#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct transform {int /*<<< orphan*/  ctx; } ;
struct pwl_result_data {scalar_t__ red_reg; scalar_t__ green_reg; scalar_t__ blue_reg; scalar_t__ delta_red_reg; scalar_t__ delta_green_reg; scalar_t__ delta_blue_reg; } ;
struct pwl_params {scalar_t__ hw_points_num; struct pwl_result_data* rgb_resulted; struct gamma_curve* arr_curve_points; TYPE_1__* arr_points; } ;
struct gamma_curve {int offset; int segments_num; } ;
struct TYPE_4__ {int /*<<< orphan*/  ctx; } ;
struct dce_transform {TYPE_2__ base; } ;
typedef  enum opp_regamma { ____Placeholder_opp_regamma } opp_regamma ;
struct TYPE_3__ {int custom_float_x; int custom_float_slope; int custom_float_y; } ;

/* Variables and functions */
 int /*<<< orphan*/  COL_MAN_GAMMA_CORR_MEM_PWR_DIS ; 
 int /*<<< orphan*/  COL_MAN_GAMMA_CORR_MEM_PWR_FORCE ; 
 int /*<<< orphan*/  COL_MAN_INPUT_GAMMA_CONTROL1 ; 
 int /*<<< orphan*/  COL_MAN_INPUT_GAMMA_MEM_PWR_DIS ; 
 int /*<<< orphan*/  COL_MAN_INPUT_GAMMA_MEM_PWR_FORCE ; 
 int /*<<< orphan*/  DCFEV_MEM_PWR_CTRL ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_END_CNTL1 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_END_CNTL2 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION0_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION0_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION10_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION10_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION11_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION11_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION12_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION12_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION13_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION13_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION14_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION14_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION15_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION15_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION1_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION1_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION2_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION2_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION3_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION3_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION4_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION4_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION5_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION5_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION6_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION6_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION7_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION7_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION8_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION8_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION9_LUT_OFFSET ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION9_NUM_SEGMENTS ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION_END ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION_END_BASE ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION_END_SLOPE ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION_LINEAR_SLOPE ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION_START ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_EXP_REGION_START_SEGMENT ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_0_1 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_10_11 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_12_13 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_14_15 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_2_3 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_4_5 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_6_7 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_REGION_8_9 ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_SLOPE_CNTL ; 
 int /*<<< orphan*/  GAMMA_CORR_CNTLA_START_CNTL ; 
 int /*<<< orphan*/  GAMMA_CORR_CONTROL ; 
 int /*<<< orphan*/  GAMMA_CORR_LUT_WRITE_EN_MASK ; 
 int /*<<< orphan*/  GAMMA_CORR_MODE ; 
 int /*<<< orphan*/  INPUT_GAMMA_MODE ; 
 struct dce_transform* TO_DCE_TRANSFORM (struct transform*) ; 
 scalar_t__ dm_read_reg (int /*<<< orphan*/ ,scalar_t__ const) ; 
 int /*<<< orphan*/  dm_write_reg (int /*<<< orphan*/ ,scalar_t__ const,scalar_t__) ; 
 scalar_t__ get_reg_field_value (scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ const mmCOL_MAN_INPUT_GAMMA_CONTROL1 ; 
 scalar_t__ const mmDCFEV_MEM_PWR_CTRL ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_END_CNTL1 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_END_CNTL2 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_0_1 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_10_11 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_12_13 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_14_15 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_2_3 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_4_5 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_6_7 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_REGION_8_9 ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_SLOPE_CNTL ; 
 scalar_t__ const mmGAMMA_CORR_CNTLA_START_CNTL ; 
 scalar_t__ const mmGAMMA_CORR_CONTROL ; 
 scalar_t__ mmGAMMA_CORR_LUT_DATA ; 
 scalar_t__ const mmGAMMA_CORR_LUT_INDEX ; 
 scalar_t__ const mmGAMMA_CORR_LUT_WRITE_EN_MASK ; 
 int /*<<< orphan*/  set_reg_field_value (scalar_t__,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static void power_on_lut(struct transform *xfm,
	bool power_on, bool inputgamma, bool regamma)
{
	uint32_t value = dm_read_reg(xfm->ctx, mmDCFEV_MEM_PWR_CTRL);
	int i;

	if (power_on) {
		if (inputgamma)
			set_reg_field_value(
				value,
				1,
				DCFEV_MEM_PWR_CTRL,
				COL_MAN_INPUT_GAMMA_MEM_PWR_DIS);
		if (regamma)
			set_reg_field_value(
				value,
				1,
				DCFEV_MEM_PWR_CTRL,
				COL_MAN_GAMMA_CORR_MEM_PWR_DIS);
	} else {
		if (inputgamma)
			set_reg_field_value(
				value,
				0,
				DCFEV_MEM_PWR_CTRL,
				COL_MAN_INPUT_GAMMA_MEM_PWR_DIS);
		if (regamma)
			set_reg_field_value(
				value,
				0,
				DCFEV_MEM_PWR_CTRL,
				COL_MAN_GAMMA_CORR_MEM_PWR_DIS);
	}

	dm_write_reg(xfm->ctx, mmDCFEV_MEM_PWR_CTRL, value);

	for (i = 0; i < 3; i++) {
		value = dm_read_reg(xfm->ctx, mmDCFEV_MEM_PWR_CTRL);
		if (get_reg_field_value(value,
				DCFEV_MEM_PWR_CTRL,
				COL_MAN_INPUT_GAMMA_MEM_PWR_DIS) &&
			get_reg_field_value(value,
					DCFEV_MEM_PWR_CTRL,
					COL_MAN_GAMMA_CORR_MEM_PWR_DIS))
			break;

		udelay(2);
	}
}

__attribute__((used)) static void set_bypass_input_gamma(struct dce_transform *xfm_dce)
{
	uint32_t value;

	value = dm_read_reg(xfm_dce->base.ctx,
			mmCOL_MAN_INPUT_GAMMA_CONTROL1);

	set_reg_field_value(
				value,
				0,
				COL_MAN_INPUT_GAMMA_CONTROL1,
				INPUT_GAMMA_MODE);

	dm_write_reg(xfm_dce->base.ctx,
			mmCOL_MAN_INPUT_GAMMA_CONTROL1, value);
}

__attribute__((used)) static void configure_regamma_mode(struct dce_transform *xfm_dce, uint32_t mode)
{
	uint32_t value = 0;

	set_reg_field_value(
				value,
				mode,
				GAMMA_CORR_CONTROL,
				GAMMA_CORR_MODE);

	dm_write_reg(xfm_dce->base.ctx, mmGAMMA_CORR_CONTROL, 0);
}

__attribute__((used)) static void regamma_config_regions_and_segments(
	struct dce_transform *xfm_dce, const struct pwl_params *params)
{
	const struct gamma_curve *curve;
	uint32_t value = 0;

	{
		set_reg_field_value(
			value,
			params->arr_points[0].custom_float_x,
			GAMMA_CORR_CNTLA_START_CNTL,
			GAMMA_CORR_CNTLA_EXP_REGION_START);

		set_reg_field_value(
			value,
			0,
			GAMMA_CORR_CNTLA_START_CNTL,
			GAMMA_CORR_CNTLA_EXP_REGION_START_SEGMENT);

		dm_write_reg(xfm_dce->base.ctx, mmGAMMA_CORR_CNTLA_START_CNTL,
				value);
	}
	{
		value = 0;
		set_reg_field_value(
			value,
			params->arr_points[0].custom_float_slope,
			GAMMA_CORR_CNTLA_SLOPE_CNTL,
			GAMMA_CORR_CNTLA_EXP_REGION_LINEAR_SLOPE);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_SLOPE_CNTL, value);
	}
	{
		value = 0;
		set_reg_field_value(
			value,
			params->arr_points[1].custom_float_x,
			GAMMA_CORR_CNTLA_END_CNTL1,
			GAMMA_CORR_CNTLA_EXP_REGION_END);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_END_CNTL1, value);
	}
	{
		value = 0;
		set_reg_field_value(
			value,
			params->arr_points[1].custom_float_slope,
			GAMMA_CORR_CNTLA_END_CNTL2,
			GAMMA_CORR_CNTLA_EXP_REGION_END_BASE);

		set_reg_field_value(
			value,
			params->arr_points[1].custom_float_y,
			GAMMA_CORR_CNTLA_END_CNTL2,
			GAMMA_CORR_CNTLA_EXP_REGION_END_SLOPE);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_END_CNTL2, value);
	}

	curve = params->arr_curve_points;

	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_0_1,
			GAMMA_CORR_CNTLA_EXP_REGION0_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_0_1,
			GAMMA_CORR_CNTLA_EXP_REGION0_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_0_1,
			GAMMA_CORR_CNTLA_EXP_REGION1_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_0_1,
			GAMMA_CORR_CNTLA_EXP_REGION1_NUM_SEGMENTS);

		dm_write_reg(
				xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_0_1,
			value);
	}

	curve += 2;
	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_2_3,
			GAMMA_CORR_CNTLA_EXP_REGION2_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_2_3,
			GAMMA_CORR_CNTLA_EXP_REGION2_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_2_3,
			GAMMA_CORR_CNTLA_EXP_REGION3_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_2_3,
			GAMMA_CORR_CNTLA_EXP_REGION3_NUM_SEGMENTS);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_2_3,
			value);
	}

	curve += 2;
	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_4_5,
			GAMMA_CORR_CNTLA_EXP_REGION4_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_4_5,
			GAMMA_CORR_CNTLA_EXP_REGION4_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_4_5,
			GAMMA_CORR_CNTLA_EXP_REGION5_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_4_5,
			GAMMA_CORR_CNTLA_EXP_REGION5_NUM_SEGMENTS);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_4_5,
			value);
	}

	curve += 2;
	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_6_7,
			GAMMA_CORR_CNTLA_EXP_REGION6_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_6_7,
			GAMMA_CORR_CNTLA_EXP_REGION6_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_6_7,
			GAMMA_CORR_CNTLA_EXP_REGION7_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_6_7,
			GAMMA_CORR_CNTLA_EXP_REGION7_NUM_SEGMENTS);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_6_7,
			value);
	}

	curve += 2;
	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_8_9,
			GAMMA_CORR_CNTLA_EXP_REGION8_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_8_9,
			GAMMA_CORR_CNTLA_EXP_REGION8_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_8_9,
			GAMMA_CORR_CNTLA_EXP_REGION9_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_8_9,
			GAMMA_CORR_CNTLA_EXP_REGION9_NUM_SEGMENTS);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_8_9,
			value);
	}

	curve += 2;
	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_10_11,
			GAMMA_CORR_CNTLA_EXP_REGION10_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_10_11,
			GAMMA_CORR_CNTLA_EXP_REGION10_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_10_11,
			GAMMA_CORR_CNTLA_EXP_REGION11_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_10_11,
			GAMMA_CORR_CNTLA_EXP_REGION11_NUM_SEGMENTS);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_10_11,
			value);
	}

	curve += 2;
	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_12_13,
			GAMMA_CORR_CNTLA_EXP_REGION12_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_12_13,
			GAMMA_CORR_CNTLA_EXP_REGION12_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_12_13,
			GAMMA_CORR_CNTLA_EXP_REGION13_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_12_13,
			GAMMA_CORR_CNTLA_EXP_REGION13_NUM_SEGMENTS);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_12_13,
			value);
	}

	curve += 2;
	{
		value = 0;
		set_reg_field_value(
			value,
			curve[0].offset,
			GAMMA_CORR_CNTLA_REGION_14_15,
			GAMMA_CORR_CNTLA_EXP_REGION14_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[0].segments_num,
			GAMMA_CORR_CNTLA_REGION_14_15,
			GAMMA_CORR_CNTLA_EXP_REGION14_NUM_SEGMENTS);

		set_reg_field_value(
			value,
			curve[1].offset,
			GAMMA_CORR_CNTLA_REGION_14_15,
			GAMMA_CORR_CNTLA_EXP_REGION15_LUT_OFFSET);

		set_reg_field_value(
			value,
			curve[1].segments_num,
			GAMMA_CORR_CNTLA_REGION_14_15,
			GAMMA_CORR_CNTLA_EXP_REGION15_NUM_SEGMENTS);

		dm_write_reg(xfm_dce->base.ctx,
			mmGAMMA_CORR_CNTLA_REGION_14_15,
			value);
	}
}

__attribute__((used)) static void program_pwl(struct dce_transform *xfm_dce,
		const struct pwl_params *params)
{
	uint32_t value = 0;

	set_reg_field_value(
		value,
		7,
		GAMMA_CORR_LUT_WRITE_EN_MASK,
		GAMMA_CORR_LUT_WRITE_EN_MASK);

	dm_write_reg(xfm_dce->base.ctx,
		mmGAMMA_CORR_LUT_WRITE_EN_MASK, value);

	dm_write_reg(xfm_dce->base.ctx,
		mmGAMMA_CORR_LUT_INDEX, 0);

	/* Program REGAMMA_LUT_DATA */
	{
		const uint32_t addr = mmGAMMA_CORR_LUT_DATA;
		uint32_t i = 0;
		const struct pwl_result_data *rgb =
				params->rgb_resulted;

		while (i != params->hw_points_num) {
			dm_write_reg(xfm_dce->base.ctx, addr, rgb->red_reg);
			dm_write_reg(xfm_dce->base.ctx, addr, rgb->green_reg);
			dm_write_reg(xfm_dce->base.ctx, addr, rgb->blue_reg);

			dm_write_reg(xfm_dce->base.ctx, addr,
				rgb->delta_red_reg);
			dm_write_reg(xfm_dce->base.ctx, addr,
				rgb->delta_green_reg);
			dm_write_reg(xfm_dce->base.ctx, addr,
				rgb->delta_blue_reg);

			++rgb;
			++i;
		}
	}
}

void dce110_opp_program_regamma_pwl_v(
	struct transform *xfm,
	const struct pwl_params *params)
{
	struct dce_transform *xfm_dce = TO_DCE_TRANSFORM(xfm);

	/* Setup regions */
	regamma_config_regions_and_segments(xfm_dce, params);

	set_bypass_input_gamma(xfm_dce);

	/* Power on gamma LUT memory */
	power_on_lut(xfm, true, false, true);

	/* Program PWL */
	program_pwl(xfm_dce, params);

	/* program regamma config */
	configure_regamma_mode(xfm_dce, 1);

	/* Power return to auto back */
	power_on_lut(xfm, false, false, true);
}

void dce110_opp_power_on_regamma_lut_v(
	struct transform *xfm,
	bool power_on)
{
	uint32_t value = dm_read_reg(xfm->ctx, mmDCFEV_MEM_PWR_CTRL);

	set_reg_field_value(
		value,
		0,
		DCFEV_MEM_PWR_CTRL,
		COL_MAN_GAMMA_CORR_MEM_PWR_FORCE);

	set_reg_field_value(
		value,
		power_on,
		DCFEV_MEM_PWR_CTRL,
		COL_MAN_GAMMA_CORR_MEM_PWR_DIS);

	set_reg_field_value(
		value,
		0,
		DCFEV_MEM_PWR_CTRL,
		COL_MAN_INPUT_GAMMA_MEM_PWR_FORCE);

	set_reg_field_value(
		value,
		power_on,
		DCFEV_MEM_PWR_CTRL,
		COL_MAN_INPUT_GAMMA_MEM_PWR_DIS);

	dm_write_reg(xfm->ctx, mmDCFEV_MEM_PWR_CTRL, value);
}

void dce110_opp_set_regamma_mode_v(
	struct transform *xfm,
	enum opp_regamma mode)
{
	// TODO: need to implement the function
}

