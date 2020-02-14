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
typedef  int /*<<< orphan*/  u32 ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct gadc_thermal_info {int nlookup_table; int* lookup_table; int /*<<< orphan*/  tz_dev; int /*<<< orphan*/  channel; struct device* dev; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  devm_iio_channel_get (struct device*,char*) ; 
 int* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct gadc_thermal_info* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_thermal_zone_of_sensor_register (struct device*,int /*<<< orphan*/ ,struct gadc_thermal_info*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gadc_thermal_ops ; 
 int iio_read_channel_processed (int /*<<< orphan*/ ,int*) ; 
 int mult_frac (int,int,int) ; 
 int of_property_count_elems_of_size (struct device_node*,char*,int) ; 
 int of_property_read_u32_array (struct device_node*,char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct gadc_thermal_info*) ; 

__attribute__((used)) static int gadc_thermal_adc_to_temp(struct gadc_thermal_info *gti, int val)
{
	int temp, temp_hi, temp_lo, adc_hi, adc_lo;
	int i;

	for (i = 0; i < gti->nlookup_table; i++) {
		if (val >= gti->lookup_table[2 * i + 1])
			break;
	}

	if (i == 0) {
		temp = gti->lookup_table[0];
	} else if (i >= gti->nlookup_table) {
		temp = gti->lookup_table[2 * (gti->nlookup_table - 1)];
	} else {
		adc_hi = gti->lookup_table[2 * i - 1];
		adc_lo = gti->lookup_table[2 * i + 1];

		temp_hi = gti->lookup_table[2 * i - 2];
		temp_lo = gti->lookup_table[2 * i];

		temp = temp_hi + mult_frac(temp_lo - temp_hi, val - adc_hi,
					   adc_lo - adc_hi);
	}

	return temp;
}

__attribute__((used)) static int gadc_thermal_get_temp(void *data, int *temp)
{
	struct gadc_thermal_info *gti = data;
	int val;
	int ret;

	ret = iio_read_channel_processed(gti->channel, &val);
	if (ret < 0) {
		dev_err(gti->dev, "IIO channel read failed %d\n", ret);
		return ret;
	}
	*temp = gadc_thermal_adc_to_temp(gti, val);

	return 0;
}

__attribute__((used)) static int gadc_thermal_read_linear_lookup_table(struct device *dev,
						 struct gadc_thermal_info *gti)
{
	struct device_node *np = dev->of_node;
	int ntable;
	int ret;

	ntable = of_property_count_elems_of_size(np, "temperature-lookup-table",
						 sizeof(u32));
	if (ntable < 0) {
		dev_err(dev, "Lookup table is not provided\n");
		return ntable;
	}

	if (ntable % 2) {
		dev_err(dev, "Pair of temperature vs ADC read value missing\n");
		return -EINVAL;
	}

	gti->lookup_table = devm_kcalloc(dev,
					 ntable, sizeof(*gti->lookup_table),
					 GFP_KERNEL);
	if (!gti->lookup_table)
		return -ENOMEM;

	ret = of_property_read_u32_array(np, "temperature-lookup-table",
					 (u32 *)gti->lookup_table, ntable);
	if (ret < 0) {
		dev_err(dev, "Failed to read temperature lookup table: %d\n",
			ret);
		return ret;
	}

	gti->nlookup_table = ntable / 2;

	return 0;
}

__attribute__((used)) static int gadc_thermal_probe(struct platform_device *pdev)
{
	struct gadc_thermal_info *gti;
	int ret;

	if (!pdev->dev.of_node) {
		dev_err(&pdev->dev, "Only DT based supported\n");
		return -ENODEV;
	}

	gti = devm_kzalloc(&pdev->dev, sizeof(*gti), GFP_KERNEL);
	if (!gti)
		return -ENOMEM;

	ret = gadc_thermal_read_linear_lookup_table(&pdev->dev, gti);
	if (ret < 0)
		return ret;

	gti->dev = &pdev->dev;
	platform_set_drvdata(pdev, gti);

	gti->channel = devm_iio_channel_get(&pdev->dev, "sensor-channel");
	if (IS_ERR(gti->channel)) {
		ret = PTR_ERR(gti->channel);
		dev_err(&pdev->dev, "IIO channel not found: %d\n", ret);
		return ret;
	}

	gti->tz_dev = devm_thermal_zone_of_sensor_register(&pdev->dev, 0, gti,
							   &gadc_thermal_ops);
	if (IS_ERR(gti->tz_dev)) {
		ret = PTR_ERR(gti->tz_dev);
		dev_err(&pdev->dev, "Thermal zone sensor register failed: %d\n",
			ret);
		return ret;
	}

	return 0;
}

