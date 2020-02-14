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
typedef  int u32 ;
struct tsens_device {int num_sensors; int /*<<< orphan*/  dev; } ;
typedef  int base0 ;

/* Variables and functions */
 int BASE0_MASK ; 
 int BASE1_MASK ; 
 int BASE1_SHIFT ; 
 int CAL_SEL_MASK ; 
 int CAL_SEL_SHIFT ; 
 scalar_t__ IS_ERR (int*) ; 
#define  ONE_PT_CALIB2 129 
 int PTR_ERR (int*) ; 
 int S0_P1_MASK ; 
 int S0_P1_SHIFT ; 
 int S0_P2_MASK ; 
 int S0_P2_SHIFT ; 
 int S1_P1_MASK ; 
 int S1_P1_SHIFT ; 
 int S1_P2_MASK ; 
 int S1_P2_SHIFT ; 
 int S2_P1_MASK ; 
 int S2_P1_SHIFT ; 
 int S2_P2_MASK ; 
 int S2_P2_SHIFT ; 
 int S3_P1_MASK ; 
 int S3_P1_SHIFT ; 
 int S3_P2_MASK ; 
 int S3_P2_SHIFT ; 
 int S4_P1_MASK ; 
 int S4_P1_SHIFT ; 
 int S4_P2_MASK ; 
 int S4_P2_SHIFT ; 
#define  TWO_PT_CALIB 128 
 int /*<<< orphan*/  compute_intercept_slope (struct tsens_device*,int*,int*,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ qfprom_read (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int calibrate_8916(struct tsens_device *tmdev)
{
	int base0 = 0, base1 = 0, i;
	u32 p1[5], p2[5];
	int mode = 0;
	u32 *qfprom_cdata, *qfprom_csel;

	qfprom_cdata = (u32 *)qfprom_read(tmdev->dev, "calib");
	if (IS_ERR(qfprom_cdata))
		return PTR_ERR(qfprom_cdata);

	qfprom_csel = (u32 *)qfprom_read(tmdev->dev, "calib_sel");
	if (IS_ERR(qfprom_csel))
		return PTR_ERR(qfprom_csel);

	mode = (qfprom_csel[0] & CAL_SEL_MASK) >> CAL_SEL_SHIFT;
	dev_dbg(tmdev->dev, "calibration mode is %d\n", mode);

	switch (mode) {
	case TWO_PT_CALIB:
		base1 = (qfprom_cdata[1] & BASE1_MASK) >> BASE1_SHIFT;
		p2[0] = (qfprom_cdata[0] & S0_P2_MASK) >> S0_P2_SHIFT;
		p2[1] = (qfprom_cdata[0] & S1_P2_MASK) >> S1_P2_SHIFT;
		p2[2] = (qfprom_cdata[1] & S2_P2_MASK) >> S2_P2_SHIFT;
		p2[3] = (qfprom_cdata[1] & S3_P2_MASK) >> S3_P2_SHIFT;
		p2[4] = (qfprom_cdata[1] & S4_P2_MASK) >> S4_P2_SHIFT;
		for (i = 0; i < tmdev->num_sensors; i++)
			p2[i] = ((base1 + p2[i]) << 3);
		/* Fall through */
	case ONE_PT_CALIB2:
		base0 = (qfprom_cdata[0] & BASE0_MASK);
		p1[0] = (qfprom_cdata[0] & S0_P1_MASK) >> S0_P1_SHIFT;
		p1[1] = (qfprom_cdata[0] & S1_P1_MASK) >> S1_P1_SHIFT;
		p1[2] = (qfprom_cdata[0] & S2_P1_MASK) >> S2_P1_SHIFT;
		p1[3] = (qfprom_cdata[1] & S3_P1_MASK) >> S3_P1_SHIFT;
		p1[4] = (qfprom_cdata[1] & S4_P1_MASK) >> S4_P1_SHIFT;
		for (i = 0; i < tmdev->num_sensors; i++)
			p1[i] = (((base0) + p1[i]) << 3);
		break;
	default:
		for (i = 0; i < tmdev->num_sensors; i++) {
			p1[i] = 500;
			p2[i] = 780;
		}
		break;
	}

	compute_intercept_slope(tmdev, p1, p2, mode);

	return 0;
}

