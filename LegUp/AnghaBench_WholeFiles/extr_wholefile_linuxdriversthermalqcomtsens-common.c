#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  scalar_t__ u32 ;
struct tsens_sensor {int slope; scalar_t__ offset; unsigned int hw_id; } ;
struct tsens_device {int num_sensors; int /*<<< orphan*/  map; struct tsens_sensor* sensor; int /*<<< orphan*/  dev; } ;
struct nvmem_cell {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;

/* Variables and functions */
 scalar_t__ CAL_DEGC_PT1 ; 
 int CAL_DEGC_PT2 ; 
 char* ERR_CAST (struct nvmem_cell*) ; 
 scalar_t__ IS_ERR (struct nvmem_cell*) ; 
 unsigned int S0_ST_ADDR ; 
 int SLOPE_DEFAULT ; 
 int SLOPE_FACTOR ; 
 unsigned int SN_ADDR_OFFSET ; 
 scalar_t__ SN_ST_TEMP_MASK ; 
 scalar_t__ TWO_PT_CALIB ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,scalar_t__,...) ; 
 struct nvmem_cell* nvmem_cell_get (struct device*,char const*) ; 
 int /*<<< orphan*/  nvmem_cell_put (struct nvmem_cell*) ; 
 char* nvmem_cell_read (struct nvmem_cell*,int /*<<< orphan*/ *) ; 
 int regmap_read (int /*<<< orphan*/ ,unsigned int,scalar_t__*) ; 

char *qfprom_read(struct device *dev, const char *cname)
{
	struct nvmem_cell *cell;
	ssize_t data;
	char *ret;

	cell = nvmem_cell_get(dev, cname);
	if (IS_ERR(cell))
		return ERR_CAST(cell);

	ret = nvmem_cell_read(cell, &data);
	nvmem_cell_put(cell);

	return ret;
}

void compute_intercept_slope(struct tsens_device *tmdev, u32 *p1,
			     u32 *p2, u32 mode)
{
	int i;
	int num, den;

	for (i = 0; i < tmdev->num_sensors; i++) {
		dev_dbg(tmdev->dev,
			"sensor%d - data_point1:%#x data_point2:%#x\n",
			i, p1[i], p2[i]);

		tmdev->sensor[i].slope = SLOPE_DEFAULT;
		if (mode == TWO_PT_CALIB) {
			/*
			 * slope (m) = adc_code2 - adc_code1 (y2 - y1)/
			 *	temp_120_degc - temp_30_degc (x2 - x1)
			 */
			num = p2[i] - p1[i];
			num *= SLOPE_FACTOR;
			den = CAL_DEGC_PT2 - CAL_DEGC_PT1;
			tmdev->sensor[i].slope = num / den;
		}

		tmdev->sensor[i].offset = (p1[i] * SLOPE_FACTOR) -
				(CAL_DEGC_PT1 *
				tmdev->sensor[i].slope);
		dev_dbg(tmdev->dev, "offset:%d\n", tmdev->sensor[i].offset);
	}
}

__attribute__((used)) static inline int code_to_degc(u32 adc_code, const struct tsens_sensor *s)
{
	int degc, num, den;

	num = (adc_code * SLOPE_FACTOR) - s->offset;
	den = s->slope;

	if (num > 0)
		degc = num + (den / 2);
	else if (num < 0)
		degc = num - (den / 2);
	else
		degc = num;

	degc /= den;

	return degc;
}

int get_temp_common(struct tsens_device *tmdev, int id, int *temp)
{
	struct tsens_sensor *s = &tmdev->sensor[id];
	u32 code;
	unsigned int status_reg;
	int last_temp = 0, ret;

	status_reg = S0_ST_ADDR + s->hw_id * SN_ADDR_OFFSET;
	ret = regmap_read(tmdev->map, status_reg, &code);
	if (ret)
		return ret;
	last_temp = code & SN_ST_TEMP_MASK;

	*temp = code_to_degc(last_temp, s) * 1000;

	return 0;
}

