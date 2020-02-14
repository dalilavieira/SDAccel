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
typedef  int uint32_t ;
struct output_pixel_processor {int dummy; } ;
struct dce_opp_shift {int dummy; } ;
struct dce_opp_registers {int dummy; } ;
struct dce_opp_mask {scalar_t__ FMT_CBCR_BIT_REDUCTION_BYPASS; scalar_t__ FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP; scalar_t__ FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX; } ;
struct TYPE_3__ {int inst; struct dc_context* ctx; int /*<<< orphan*/ * funcs; } ;
struct dce110_opp {struct dce_opp_mask const* opp_mask; struct dce_opp_shift const* opp_shift; struct dce_opp_registers const* regs; TYPE_1__ base; } ;
struct dc_context {int dummy; } ;
struct clamping_and_pixel_encoding_params {int clamping_level; scalar_t__ pixel_encoding; } ;
struct TYPE_4__ {int TRUNCATE_DEPTH; scalar_t__ TRUNCATE_ENABLED; int TRUNCATE_MODE; scalar_t__ SPATIAL_DITHER_ENABLED; int SPATIAL_DITHER_DEPTH; int FRAME_RANDOM; int HIGHPASS_RANDOM; int RGB_RANDOM; int SPATIAL_DITHER_MODE; scalar_t__ FRAME_MODULATION_ENABLED; int FRAME_MODULATION_DEPTH; int TEMPORAL_LEVEL; int FRC25; int FRC50; int FRC75; } ;
struct bit_depth_reduction_params {scalar_t__ pixel_encoding; int r_seed_value; int g_seed_value; int b_seed_value; TYPE_2__ flags; } ;
typedef  enum signal_type { ____Placeholder_signal_type } signal_type ;
typedef  enum dc_color_space { ____Placeholder_dc_color_space } dc_color_space ;
typedef  enum dc_color_depth { ____Placeholder_dc_color_depth } dc_color_depth ;

/* Variables and functions */
#define  CLAMPING_FULL_RANGE 135 
#define  CLAMPING_LIMITED_RANGE_10BPC 134 
#define  CLAMPING_LIMITED_RANGE_12BPC 133 
#define  CLAMPING_LIMITED_RANGE_8BPC 132 
#define  CLAMPING_LIMITED_RANGE_PROGRAMMABLE 131 
#define  COLOR_DEPTH_101010 130 
#define  COLOR_DEPTH_121212 129 
#define  COLOR_DEPTH_888 128 
 int /*<<< orphan*/  CONTROL ; 
 int /*<<< orphan*/  FMT420_MEM0_PWR_FORCE ; 
 int /*<<< orphan*/  FMT420_MEM0_SOURCE_SEL ; 
 int /*<<< orphan*/  FMT_25FRC_SEL ; 
 int /*<<< orphan*/  FMT_420_PIXEL_PHASE_LOCKED ; 
 int /*<<< orphan*/  FMT_420_PIXEL_PHASE_LOCKED_CLEAR ; 
 int /*<<< orphan*/  FMT_50FRC_SEL ; 
 int /*<<< orphan*/  FMT_75FRC_SEL ; 
 int /*<<< orphan*/  FMT_BIT_DEPTH_CONTROL ; 
 int /*<<< orphan*/  FMT_CBCR_BIT_REDUCTION_BYPASS ; 
 int /*<<< orphan*/  FMT_CLAMP_CNTL ; 
 int /*<<< orphan*/  FMT_CLAMP_COLOR_FORMAT ; 
 int /*<<< orphan*/  FMT_CLAMP_COMPONENT_B ; 
 int /*<<< orphan*/  FMT_CLAMP_COMPONENT_G ; 
 int /*<<< orphan*/  FMT_CLAMP_COMPONENT_R ; 
 int /*<<< orphan*/  FMT_CLAMP_DATA_EN ; 
 int /*<<< orphan*/  FMT_CLAMP_LOWER_B ; 
 int /*<<< orphan*/  FMT_CLAMP_LOWER_G ; 
 int /*<<< orphan*/  FMT_CLAMP_LOWER_R ; 
 int /*<<< orphan*/  FMT_CLAMP_UPPER_B ; 
 int /*<<< orphan*/  FMT_CLAMP_UPPER_G ; 
 int /*<<< orphan*/  FMT_CLAMP_UPPER_R ; 
 int /*<<< orphan*/  FMT_CONTROL ; 
 int /*<<< orphan*/  FMT_DITHER_RAND_B_SEED ; 
 int /*<<< orphan*/  FMT_DITHER_RAND_G_SEED ; 
 int /*<<< orphan*/  FMT_DITHER_RAND_R_SEED ; 
 int /*<<< orphan*/  FMT_DYNAMIC_EXP_CNTL ; 
 int /*<<< orphan*/  FMT_DYNAMIC_EXP_EN ; 
 int /*<<< orphan*/  FMT_DYNAMIC_EXP_MODE ; 
 int /*<<< orphan*/  FMT_FRAME_RANDOM_ENABLE ; 
 int /*<<< orphan*/  FMT_HIGHPASS_RANDOM_ENABLE ; 
 int /*<<< orphan*/  FMT_PIXEL_ENCODING ; 
 int /*<<< orphan*/  FMT_RAND_B_SEED ; 
 int /*<<< orphan*/  FMT_RAND_G_SEED ; 
 int /*<<< orphan*/  FMT_RAND_R_SEED ; 
 int /*<<< orphan*/  FMT_RGB_RANDOM_ENABLE ; 
 int /*<<< orphan*/  FMT_SPATIAL_DITHER_DEPTH ; 
 int /*<<< orphan*/  FMT_SPATIAL_DITHER_EN ; 
 int /*<<< orphan*/  FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP ; 
 int /*<<< orphan*/  FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX ; 
 int /*<<< orphan*/  FMT_SPATIAL_DITHER_MODE ; 
 int /*<<< orphan*/  FMT_SRC_SELECT ; 
 int /*<<< orphan*/  FMT_SUBSAMPLING_MODE ; 
 int /*<<< orphan*/  FMT_SUBSAMPLING_ORDER ; 
 int /*<<< orphan*/  FMT_TEMPORAL_DITHER_DEPTH ; 
 int /*<<< orphan*/  FMT_TEMPORAL_DITHER_EN ; 
 int /*<<< orphan*/  FMT_TEMPORAL_DITHER_OFFSET ; 
 int /*<<< orphan*/  FMT_TEMPORAL_DITHER_PATTERN_CONTROL ; 
 int /*<<< orphan*/  FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX ; 
 int /*<<< orphan*/  FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX ; 
 int /*<<< orphan*/  FMT_TEMPORAL_DITHER_RESET ; 
 int /*<<< orphan*/  FMT_TEMPORAL_LEVEL ; 
 int /*<<< orphan*/  FMT_TRUNCATE_DEPTH ; 
 int /*<<< orphan*/  FMT_TRUNCATE_EN ; 
 int /*<<< orphan*/  FMT_TRUNCATE_MODE ; 
 int /*<<< orphan*/  FROM_DCE11_OPP (struct output_pixel_processor*) ; 
 scalar_t__ PIXEL_ENCODING_YCBCR420 ; 
 scalar_t__ PIXEL_ENCODING_YCBCR422 ; 
 scalar_t__ REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  REG_SET_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_WAIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  REG_WRITE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int SIGNAL_TYPE_DISPLAY_PORT ; 
 int SIGNAL_TYPE_DISPLAY_PORT_MST ; 
 int SIGNAL_TYPE_HDMI_TYPE_A ; 
 struct dce110_opp* TO_DCE110_OPP (struct output_pixel_processor*) ; 
 int /*<<< orphan*/  funcs ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void set_truncation(
		struct dce110_opp *opp110,
		const struct bit_depth_reduction_params *params)
{
	/*Disable truncation*/
	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
			FMT_TRUNCATE_EN, 0,
			FMT_TRUNCATE_DEPTH, 0,
			FMT_TRUNCATE_MODE, 0);


	if (params->pixel_encoding == PIXEL_ENCODING_YCBCR422) {
		/*  8bpc trunc on YCbCr422*/
		if (params->flags.TRUNCATE_DEPTH == 1)
			REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
					FMT_TRUNCATE_EN, 1,
					FMT_TRUNCATE_DEPTH, 1,
					FMT_TRUNCATE_MODE, 0);
		else if (params->flags.TRUNCATE_DEPTH == 2)
			/*  10bpc trunc on YCbCr422*/
			REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
					FMT_TRUNCATE_EN, 1,
					FMT_TRUNCATE_DEPTH, 2,
					FMT_TRUNCATE_MODE, 0);
		return;
	}
	/* on other format-to do */
	if (params->flags.TRUNCATE_ENABLED == 0)
		return;
	/*Set truncation depth and Enable truncation*/
	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
				FMT_TRUNCATE_EN, 1,
				FMT_TRUNCATE_DEPTH,
				params->flags.TRUNCATE_DEPTH,
				FMT_TRUNCATE_MODE,
				params->flags.TRUNCATE_MODE);
}

__attribute__((used)) static void set_spatial_dither(
	struct dce110_opp *opp110,
	const struct bit_depth_reduction_params *params)
{
	/*Disable spatial (random) dithering*/
	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_SPATIAL_DITHER_EN, 0,
		FMT_SPATIAL_DITHER_DEPTH, 0,
		FMT_SPATIAL_DITHER_MODE, 0);

	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_HIGHPASS_RANDOM_ENABLE, 0,
		FMT_FRAME_RANDOM_ENABLE, 0,
		FMT_RGB_RANDOM_ENABLE, 0);

	REG_UPDATE(FMT_BIT_DEPTH_CONTROL,
		FMT_TEMPORAL_DITHER_EN, 0);

	/* no 10bpc on DCE11*/
	if (params->flags.SPATIAL_DITHER_ENABLED == 0 ||
		params->flags.SPATIAL_DITHER_DEPTH == 2)
		return;

	/* only use FRAME_COUNTER_MAX if frameRandom == 1*/

	if (opp110->opp_mask->FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX &&
			opp110->opp_mask->FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP) {
		if (params->flags.FRAME_RANDOM == 1) {
			if (params->flags.SPATIAL_DITHER_DEPTH == 0 ||
			params->flags.SPATIAL_DITHER_DEPTH == 1) {
				REG_UPDATE_2(FMT_CONTROL,
					FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, 15,
					FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, 2);
			} else if (params->flags.SPATIAL_DITHER_DEPTH == 2) {
				REG_UPDATE_2(FMT_CONTROL,
					FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, 3,
					FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, 1);
			} else
				return;
		} else {
			REG_UPDATE_2(FMT_CONTROL,
					FMT_SPATIAL_DITHER_FRAME_COUNTER_MAX, 0,
					FMT_SPATIAL_DITHER_FRAME_COUNTER_BIT_SWAP, 0);
		}
	}
	/* Set seed for random values for
	 * spatial dithering for R,G,B channels
	 */
	REG_UPDATE(FMT_DITHER_RAND_R_SEED,
			FMT_RAND_R_SEED, params->r_seed_value);

	REG_UPDATE(FMT_DITHER_RAND_G_SEED,
			FMT_RAND_G_SEED, params->g_seed_value);

	REG_UPDATE(FMT_DITHER_RAND_B_SEED,
			FMT_RAND_B_SEED, params->b_seed_value);

	/* FMT_OFFSET_R_Cr  31:16 0x0 Setting the zero
	 * offset for the R/Cr channel, lower 4LSB
	 * is forced to zeros. Typically set to 0
	 * RGB and 0x80000 YCbCr.
	 */
	/* FMT_OFFSET_G_Y   31:16 0x0 Setting the zero
	 * offset for the G/Y  channel, lower 4LSB is
	 * forced to zeros. Typically set to 0 RGB
	 * and 0x80000 YCbCr.
	 */
	/* FMT_OFFSET_B_Cb  31:16 0x0 Setting the zero
	 * offset for the B/Cb channel, lower 4LSB is
	 * forced to zeros. Typically set to 0 RGB and
	 * 0x80000 YCbCr.
	 */

	/* Disable High pass filter
	 * Reset only at startup
	 * Set RGB data dithered with x^28+x^3+1
	 */
	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_HIGHPASS_RANDOM_ENABLE, params->flags.HIGHPASS_RANDOM,
		FMT_FRAME_RANDOM_ENABLE, params->flags.FRAME_RANDOM,
		FMT_RGB_RANDOM_ENABLE, params->flags.RGB_RANDOM);

	/* Set spatial dithering bit depth
	 * Set spatial dithering mode
	 * (default is Seed patterrn AAAA...)
	 * Enable spatial dithering
	 */
	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_SPATIAL_DITHER_DEPTH, params->flags.SPATIAL_DITHER_DEPTH,
		FMT_SPATIAL_DITHER_MODE, params->flags.SPATIAL_DITHER_MODE,
		FMT_SPATIAL_DITHER_EN, 1);
}

__attribute__((used)) static void set_temporal_dither(
	struct dce110_opp *opp110,
	const struct bit_depth_reduction_params *params)
{
	/*Disable temporal (frame modulation) dithering first*/
	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_TEMPORAL_DITHER_EN, 0,
		FMT_TEMPORAL_DITHER_RESET, 0,
		FMT_TEMPORAL_DITHER_OFFSET, 0);

	REG_UPDATE_2(FMT_BIT_DEPTH_CONTROL,
		FMT_TEMPORAL_DITHER_DEPTH, 0,
		FMT_TEMPORAL_LEVEL, 0);

	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_25FRC_SEL, 0,
		FMT_50FRC_SEL, 0,
		FMT_75FRC_SEL, 0);

	/* no 10bpc dither on DCE11*/
	if (params->flags.FRAME_MODULATION_ENABLED == 0 ||
		params->flags.FRAME_MODULATION_DEPTH == 2)
		return;

	/* Set temporal dithering depth*/
	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_TEMPORAL_DITHER_DEPTH, params->flags.FRAME_MODULATION_DEPTH,
		FMT_TEMPORAL_DITHER_RESET, 0,
		FMT_TEMPORAL_DITHER_OFFSET, 0);

	/*Select legacy pattern based on FRC and Temporal level*/
	if (REG(FMT_TEMPORAL_DITHER_PATTERN_CONTROL)) {
		REG_WRITE(FMT_TEMPORAL_DITHER_PATTERN_CONTROL, 0);
		/*Set s matrix*/
		REG_WRITE(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_S_MATRIX, 0);
		/*Set t matrix*/
		REG_WRITE(FMT_TEMPORAL_DITHER_PROGRAMMABLE_PATTERN_T_MATRIX, 0);
	}

	/*Select patterns for 0.25, 0.5 and 0.75 grey level*/
	REG_UPDATE(FMT_BIT_DEPTH_CONTROL,
		FMT_TEMPORAL_LEVEL, params->flags.TEMPORAL_LEVEL);

	REG_UPDATE_3(FMT_BIT_DEPTH_CONTROL,
		FMT_25FRC_SEL, params->flags.FRC25,
		FMT_50FRC_SEL, params->flags.FRC50,
		FMT_75FRC_SEL, params->flags.FRC75);

	/*Enable bit reduction by temporal (frame modulation) dithering*/
	REG_UPDATE(FMT_BIT_DEPTH_CONTROL,
		FMT_TEMPORAL_DITHER_EN, 1);
}

void dce110_opp_set_clamping(
	struct dce110_opp *opp110,
	const struct clamping_and_pixel_encoding_params *params)
{
	REG_SET_2(FMT_CLAMP_CNTL, 0,
		FMT_CLAMP_DATA_EN, 0,
		FMT_CLAMP_COLOR_FORMAT, 0);

	switch (params->clamping_level) {
	case CLAMPING_FULL_RANGE:
		break;
	case CLAMPING_LIMITED_RANGE_8BPC:
		REG_SET_2(FMT_CLAMP_CNTL, 0,
			FMT_CLAMP_DATA_EN, 1,
			FMT_CLAMP_COLOR_FORMAT, 1);
		break;
	case CLAMPING_LIMITED_RANGE_10BPC:
		REG_SET_2(FMT_CLAMP_CNTL, 0,
			FMT_CLAMP_DATA_EN, 1,
			FMT_CLAMP_COLOR_FORMAT, 2);
		break;
	case CLAMPING_LIMITED_RANGE_12BPC:
		REG_SET_2(FMT_CLAMP_CNTL, 0,
			FMT_CLAMP_DATA_EN, 1,
			FMT_CLAMP_COLOR_FORMAT, 3);
		break;
	case CLAMPING_LIMITED_RANGE_PROGRAMMABLE:
		/*Set clamp control*/
		REG_SET_2(FMT_CLAMP_CNTL, 0,
			FMT_CLAMP_DATA_EN, 1,
			FMT_CLAMP_COLOR_FORMAT, 7);

		/*set the defaults*/
		REG_SET_2(FMT_CLAMP_COMPONENT_R, 0,
			FMT_CLAMP_LOWER_R, 0x10,
			FMT_CLAMP_UPPER_R, 0xFEF);

		REG_SET_2(FMT_CLAMP_COMPONENT_G, 0,
			FMT_CLAMP_LOWER_G, 0x10,
			FMT_CLAMP_UPPER_G, 0xFEF);

		REG_SET_2(FMT_CLAMP_COMPONENT_B, 0,
			FMT_CLAMP_LOWER_B, 0x10,
			FMT_CLAMP_UPPER_B, 0xFEF);
		break;
	default:
		break;
	}
}

__attribute__((used)) static void set_pixel_encoding(
	struct dce110_opp *opp110,
	const struct clamping_and_pixel_encoding_params *params)
{
	if (opp110->opp_mask->FMT_CBCR_BIT_REDUCTION_BYPASS)
		REG_UPDATE_3(FMT_CONTROL,
				FMT_PIXEL_ENCODING, 0,
				FMT_SUBSAMPLING_MODE, 0,
				FMT_CBCR_BIT_REDUCTION_BYPASS, 0);
	else
		REG_UPDATE_2(FMT_CONTROL,
				FMT_PIXEL_ENCODING, 0,
				FMT_SUBSAMPLING_MODE, 0);

	if (params->pixel_encoding == PIXEL_ENCODING_YCBCR422) {
		REG_UPDATE_2(FMT_CONTROL,
				FMT_PIXEL_ENCODING, 1,
				FMT_SUBSAMPLING_ORDER, 0);
	}
	if (params->pixel_encoding == PIXEL_ENCODING_YCBCR420) {
		REG_UPDATE_3(FMT_CONTROL,
				FMT_PIXEL_ENCODING, 2,
				FMT_SUBSAMPLING_MODE, 2,
				FMT_CBCR_BIT_REDUCTION_BYPASS, 1);
	}

}

void dce110_opp_program_bit_depth_reduction(
	struct output_pixel_processor *opp,
	const struct bit_depth_reduction_params *params)
{
	struct dce110_opp *opp110 = TO_DCE110_OPP(opp);

	set_truncation(opp110, params);
	set_spatial_dither(opp110, params);
	set_temporal_dither(opp110, params);
}

void dce110_opp_program_clamping_and_pixel_encoding(
	struct output_pixel_processor *opp,
	const struct clamping_and_pixel_encoding_params *params)
{
	struct dce110_opp *opp110 = TO_DCE110_OPP(opp);

	dce110_opp_set_clamping(opp110, params);
	set_pixel_encoding(opp110, params);
}

__attribute__((used)) static void program_formatter_420_memory(struct output_pixel_processor *opp)
{
	struct dce110_opp *opp110 = TO_DCE110_OPP(opp);
	uint32_t fmt_mem_cntl_value;

	/* Program source select*/
	/* Use HW default source select for FMT_MEMORYx_CONTROL */
	/* Use that value for FMT_SRC_SELECT as well*/
	REG_GET(CONTROL,
			FMT420_MEM0_SOURCE_SEL, &fmt_mem_cntl_value);

	REG_UPDATE(FMT_CONTROL,
			FMT_SRC_SELECT, fmt_mem_cntl_value);

	/* Turn on the memory */
	REG_UPDATE(CONTROL,
			FMT420_MEM0_PWR_FORCE, 0);
}

void dce110_opp_set_dyn_expansion(
	struct output_pixel_processor *opp,
	enum dc_color_space color_sp,
	enum dc_color_depth color_dpth,
	enum signal_type signal)
{
	struct dce110_opp *opp110 = TO_DCE110_OPP(opp);

	REG_UPDATE_2(FMT_DYNAMIC_EXP_CNTL,
			FMT_DYNAMIC_EXP_EN, 0,
			FMT_DYNAMIC_EXP_MODE, 0);

	/*00 - 10-bit -> 12-bit dynamic expansion*/
	/*01 - 8-bit  -> 12-bit dynamic expansion*/
	if (signal == SIGNAL_TYPE_HDMI_TYPE_A ||
		signal == SIGNAL_TYPE_DISPLAY_PORT ||
		signal == SIGNAL_TYPE_DISPLAY_PORT_MST) {
		switch (color_dpth) {
		case COLOR_DEPTH_888:
			REG_UPDATE_2(FMT_DYNAMIC_EXP_CNTL,
				FMT_DYNAMIC_EXP_EN, 1,
				FMT_DYNAMIC_EXP_MODE, 1);
			break;
		case COLOR_DEPTH_101010:
			REG_UPDATE_2(FMT_DYNAMIC_EXP_CNTL,
				FMT_DYNAMIC_EXP_EN, 1,
				FMT_DYNAMIC_EXP_MODE, 0);
			break;
		case COLOR_DEPTH_121212:
			REG_UPDATE_2(
				FMT_DYNAMIC_EXP_CNTL,
				FMT_DYNAMIC_EXP_EN, 1,/*otherwise last two bits are zero*/
				FMT_DYNAMIC_EXP_MODE, 0);
			break;
		default:
			break;
		}
	}
}

__attribute__((used)) static void program_formatter_reset_dig_resync_fifo(struct output_pixel_processor *opp)
{
	struct dce110_opp *opp110 = TO_DCE110_OPP(opp);

	/* clear previous phase lock status*/
	REG_UPDATE(FMT_CONTROL,
			FMT_420_PIXEL_PHASE_LOCKED_CLEAR, 1);

	/* poll until FMT_420_PIXEL_PHASE_LOCKED become 1*/
	REG_WAIT(FMT_CONTROL, FMT_420_PIXEL_PHASE_LOCKED, 1, 10, 10);

}

void dce110_opp_program_fmt(
	struct output_pixel_processor *opp,
	struct bit_depth_reduction_params *fmt_bit_depth,
	struct clamping_and_pixel_encoding_params *clamping)
{
	/* dithering is affected by <CrtcSourceSelect>, hence should be
	 * programmed afterwards */

	if (clamping->pixel_encoding == PIXEL_ENCODING_YCBCR420)
		program_formatter_420_memory(opp);

	dce110_opp_program_bit_depth_reduction(
		opp,
		fmt_bit_depth);

	dce110_opp_program_clamping_and_pixel_encoding(
		opp,
		clamping);

	if (clamping->pixel_encoding == PIXEL_ENCODING_YCBCR420)
		program_formatter_reset_dig_resync_fifo(opp);

	return;
}

void dce110_opp_construct(struct dce110_opp *opp110,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dce_opp_registers *regs,
	const struct dce_opp_shift *opp_shift,
	const struct dce_opp_mask *opp_mask)
{
	opp110->base.funcs = &funcs;

	opp110->base.ctx = ctx;

	opp110->base.inst = inst;

	opp110->regs = regs;
	opp110->opp_shift = opp_shift;
	opp110->opp_mask = opp_mask;
}

void dce110_opp_destroy(struct output_pixel_processor **opp)
{
	if (*opp)
		kfree(FROM_DCE11_OPP(*opp));
	*opp = NULL;
}

