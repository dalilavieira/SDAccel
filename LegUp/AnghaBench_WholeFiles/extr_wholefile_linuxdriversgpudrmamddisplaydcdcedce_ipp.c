#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct ipp_prescale_params {scalar_t__ mode; scalar_t__ bias; scalar_t__ scale; } ;
struct input_pixel_processor {int dummy; } ;
struct dce_ipp_shift {int dummy; } ;
struct dce_ipp_registers {int dummy; } ;
struct dce_ipp_mask {int dummy; } ;
struct TYPE_10__ {int inst; int /*<<< orphan*/ * funcs; struct dc_context* ctx; } ;
struct dce_ipp {struct dce_ipp_mask const* ipp_mask; struct dce_ipp_shift const* ipp_shift; struct dce_ipp_registers const* regs; TYPE_5__ base; } ;
struct TYPE_9__ {int /*<<< orphan*/ * blue; int /*<<< orphan*/ * green; int /*<<< orphan*/ * red; } ;
struct dc_gamma {int num_entries; TYPE_4__ entries; } ;
struct dc_cursor_position {int enable; scalar_t__ y_hotspot; scalar_t__ x_hotspot; scalar_t__ y; scalar_t__ x; } ;
struct dc_cursor_mi_param {int dummy; } ;
struct TYPE_8__ {int high_part; int low_part; } ;
struct TYPE_6__ {int /*<<< orphan*/  INVERSE_TRANSPARENT_CLAMPING; int /*<<< orphan*/  ENABLE_MAGNIFICATION; } ;
struct TYPE_7__ {TYPE_1__ bits; } ;
struct dc_cursor_attributes {int color_format; TYPE_3__ address; scalar_t__ height; scalar_t__ width; TYPE_2__ attribute_flags; } ;
struct dc_context {int dummy; } ;
typedef  enum ipp_degamma_mode { ____Placeholder_ipp_degamma_mode } ipp_degamma_mode ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
 int /*<<< orphan*/  CURSOR2_DEGAMMA_MODE ; 
 int /*<<< orphan*/  CURSOR_2X_MAGNIFY ; 
 int /*<<< orphan*/  CURSOR_DEGAMMA_MODE ; 
 int /*<<< orphan*/  CURSOR_EN ; 
 int /*<<< orphan*/  CURSOR_HEIGHT ; 
 int /*<<< orphan*/  CURSOR_HOT_SPOT_X ; 
 int /*<<< orphan*/  CURSOR_HOT_SPOT_Y ; 
 int /*<<< orphan*/  CURSOR_MODE ; 
#define  CURSOR_MODE_COLOR_1BIT_AND 131 
#define  CURSOR_MODE_COLOR_PRE_MULTIPLIED_ALPHA 130 
#define  CURSOR_MODE_COLOR_UN_PRE_MULTIPLIED_ALPHA 129 
#define  CURSOR_MODE_MONO 128 
 int /*<<< orphan*/  CURSOR_SURFACE_ADDRESS ; 
 int /*<<< orphan*/  CURSOR_SURFACE_ADDRESS_HIGH ; 
 int /*<<< orphan*/  CURSOR_UPDATE_LOCK ; 
 int /*<<< orphan*/  CURSOR_WIDTH ; 
 int /*<<< orphan*/  CURSOR_X_POSITION ; 
 int /*<<< orphan*/  CURSOR_Y_POSITION ; 
 int /*<<< orphan*/  CUR_COLOR1 ; 
 int /*<<< orphan*/  CUR_COLOR1_BLUE ; 
 int /*<<< orphan*/  CUR_COLOR1_GREEN ; 
 int /*<<< orphan*/  CUR_COLOR1_RED ; 
 int /*<<< orphan*/  CUR_COLOR2 ; 
 int /*<<< orphan*/  CUR_COLOR2_BLUE ; 
 int /*<<< orphan*/  CUR_COLOR2_GREEN ; 
 int /*<<< orphan*/  CUR_COLOR2_RED ; 
 int /*<<< orphan*/  CUR_CONTROL ; 
 int /*<<< orphan*/  CUR_HOT_SPOT ; 
 int /*<<< orphan*/  CUR_INV_TRANS_CLAMP ; 
 int /*<<< orphan*/  CUR_POSITION ; 
 int /*<<< orphan*/  CUR_SIZE ; 
 int /*<<< orphan*/  CUR_SURFACE_ADDRESS ; 
 int /*<<< orphan*/  CUR_SURFACE_ADDRESS_HIGH ; 
 int /*<<< orphan*/  CUR_UPDATE ; 
 int /*<<< orphan*/  DCFE_MEM_PWR_CTRL ; 
 int /*<<< orphan*/  DCP_LUT_MEM_PWR_DIS ; 
 int /*<<< orphan*/  DC_LUT_CONTROL ; 
 int /*<<< orphan*/  DC_LUT_DATA_B_FORMAT ; 
 int /*<<< orphan*/  DC_LUT_DATA_G_FORMAT ; 
 int /*<<< orphan*/  DC_LUT_DATA_R_FORMAT ; 
 int /*<<< orphan*/  DC_LUT_RW_INDEX ; 
 int /*<<< orphan*/  DC_LUT_RW_MODE ; 
 int /*<<< orphan*/  DC_LUT_SEQ_COLOR ; 
 int /*<<< orphan*/  DC_LUT_WRITE_EN_MASK ; 
 int /*<<< orphan*/  DEGAMMA_CONTROL ; 
 int /*<<< orphan*/  GRPH_DEGAMMA_MODE ; 
 int /*<<< orphan*/  GRPH_INPUT_GAMMA_MODE ; 
 int /*<<< orphan*/  GRPH_PRESCALE_BIAS_B ; 
 int /*<<< orphan*/  GRPH_PRESCALE_BIAS_G ; 
 int /*<<< orphan*/  GRPH_PRESCALE_BIAS_R ; 
 int /*<<< orphan*/  GRPH_PRESCALE_BYPASS ; 
 int /*<<< orphan*/  GRPH_PRESCALE_SCALE_B ; 
 int /*<<< orphan*/  GRPH_PRESCALE_SCALE_G ; 
 int /*<<< orphan*/  GRPH_PRESCALE_SCALE_R ; 
 int /*<<< orphan*/  INPUT_GAMMA_CONTROL ; 
 int IPP_DEGAMMA_MODE_BYPASS ; 
 int IPP_DEGAMMA_MODE_HW_sRGB ; 
 scalar_t__ IPP_PRESCALE_MODE_BYPASS ; 
 int /*<<< orphan*/  PRESCALE_GRPH_CONTROL ; 
 int /*<<< orphan*/  PRESCALE_VALUES_GRPH_B ; 
 int /*<<< orphan*/  PRESCALE_VALUES_GRPH_G ; 
 int /*<<< orphan*/  PRESCALE_VALUES_GRPH_R ; 
 scalar_t__ REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_SET_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  REG_SET_3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct dce_ipp* TO_DCE_IPP (struct input_pixel_processor*) ; 
 int dc_fixpt_round (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dce_ipp_funcs ; 
 int /*<<< orphan*/  kfree (struct dce_ipp*) ; 

__attribute__((used)) static void dce_ipp_cursor_set_position(
	struct input_pixel_processor *ipp,
	const struct dc_cursor_position *position,
	const struct dc_cursor_mi_param *param)
{
	struct dce_ipp *ipp_dce = TO_DCE_IPP(ipp);

	/* lock cursor registers */
	REG_UPDATE(CUR_UPDATE, CURSOR_UPDATE_LOCK, true);

	/* Flag passed in structure differentiates cursor enable/disable. */
	/* Update if it differs from cached state. */
	REG_UPDATE(CUR_CONTROL, CURSOR_EN, position->enable);

	REG_SET_2(CUR_POSITION, 0,
		CURSOR_X_POSITION, position->x,
		CURSOR_Y_POSITION, position->y);

	REG_SET_2(CUR_HOT_SPOT, 0,
		CURSOR_HOT_SPOT_X, position->x_hotspot,
		CURSOR_HOT_SPOT_Y, position->y_hotspot);

	/* unlock cursor registers */
	REG_UPDATE(CUR_UPDATE, CURSOR_UPDATE_LOCK, false);
}

__attribute__((used)) static void dce_ipp_cursor_set_attributes(
	struct input_pixel_processor *ipp,
	const struct dc_cursor_attributes *attributes)
{
	struct dce_ipp *ipp_dce = TO_DCE_IPP(ipp);
	int mode;

	/* Lock cursor registers */
	REG_UPDATE(CUR_UPDATE, CURSOR_UPDATE_LOCK, true);

	/* Program cursor control */
	switch (attributes->color_format) {
	case CURSOR_MODE_MONO:
		mode = 0;
		break;
	case CURSOR_MODE_COLOR_1BIT_AND:
		mode = 1;
		break;
	case CURSOR_MODE_COLOR_PRE_MULTIPLIED_ALPHA:
		mode = 2;
		break;
	case CURSOR_MODE_COLOR_UN_PRE_MULTIPLIED_ALPHA:
		mode = 3;
		break;
	default:
		BREAK_TO_DEBUGGER(); /* unsupported */
		mode = 0;
	}

	REG_UPDATE_3(CUR_CONTROL,
		CURSOR_MODE, mode,
		CURSOR_2X_MAGNIFY, attributes->attribute_flags.bits.ENABLE_MAGNIFICATION,
		CUR_INV_TRANS_CLAMP, attributes->attribute_flags.bits.INVERSE_TRANSPARENT_CLAMPING);

	if (attributes->color_format == CURSOR_MODE_MONO) {
		REG_SET_3(CUR_COLOR1, 0,
			CUR_COLOR1_BLUE, 0,
			CUR_COLOR1_GREEN, 0,
			CUR_COLOR1_RED, 0);

		REG_SET_3(CUR_COLOR2, 0,
			CUR_COLOR2_BLUE, 0xff,
			CUR_COLOR2_GREEN, 0xff,
			CUR_COLOR2_RED, 0xff);
	}

	/*
	 * Program cursor size -- NOTE: HW spec specifies that HW register
	 * stores size as (height - 1, width - 1)
	 */
	REG_SET_2(CUR_SIZE, 0,
		CURSOR_WIDTH, attributes->width-1,
		CURSOR_HEIGHT, attributes->height-1);

	/* Program cursor surface address */
	/* SURFACE_ADDRESS_HIGH: Higher order bits (39:32) of hardware cursor
	 * surface base address in byte. It is 4K byte aligned.
	 * The correct way to program cursor surface address is to first write
	 * to CUR_SURFACE_ADDRESS_HIGH, and then write to CUR_SURFACE_ADDRESS
	 */
	REG_SET(CUR_SURFACE_ADDRESS_HIGH, 0,
		CURSOR_SURFACE_ADDRESS_HIGH, attributes->address.high_part);

	REG_SET(CUR_SURFACE_ADDRESS, 0,
		CURSOR_SURFACE_ADDRESS, attributes->address.low_part);

	/* Unlock Cursor registers. */
	REG_UPDATE(CUR_UPDATE, CURSOR_UPDATE_LOCK, false);
}

__attribute__((used)) static void dce_ipp_program_prescale(struct input_pixel_processor *ipp,
				     struct ipp_prescale_params *params)
{
	struct dce_ipp *ipp_dce = TO_DCE_IPP(ipp);

	/* set to bypass mode first before change */
	REG_UPDATE(PRESCALE_GRPH_CONTROL,
		   GRPH_PRESCALE_BYPASS, 1);

	REG_SET_2(PRESCALE_VALUES_GRPH_R, 0,
		  GRPH_PRESCALE_SCALE_R, params->scale,
		  GRPH_PRESCALE_BIAS_R, params->bias);

	REG_SET_2(PRESCALE_VALUES_GRPH_G, 0,
		  GRPH_PRESCALE_SCALE_G, params->scale,
		  GRPH_PRESCALE_BIAS_G, params->bias);

	REG_SET_2(PRESCALE_VALUES_GRPH_B, 0,
		  GRPH_PRESCALE_SCALE_B, params->scale,
		  GRPH_PRESCALE_BIAS_B, params->bias);

	if (params->mode != IPP_PRESCALE_MODE_BYPASS) {
		REG_UPDATE(PRESCALE_GRPH_CONTROL,
			   GRPH_PRESCALE_BYPASS, 0);

		/* If prescale is in use, then legacy lut should be bypassed */
		REG_UPDATE(INPUT_GAMMA_CONTROL,
			   GRPH_INPUT_GAMMA_MODE, 1);
	}
}

__attribute__((used)) static void dce_ipp_program_input_lut(
	struct input_pixel_processor *ipp,
	const struct dc_gamma *gamma)
{
	int i;
	struct dce_ipp *ipp_dce = TO_DCE_IPP(ipp);

	/* power on LUT memory */
	if (REG(DCFE_MEM_PWR_CTRL))
		REG_SET(DCFE_MEM_PWR_CTRL, 0, DCP_LUT_MEM_PWR_DIS, 1);

	/* enable all */
	REG_SET(DC_LUT_WRITE_EN_MASK, 0, DC_LUT_WRITE_EN_MASK, 0x7);

	/* 256 entry mode */
	REG_UPDATE(DC_LUT_RW_MODE, DC_LUT_RW_MODE, 0);

	/* LUT-256, unsigned, integer, new u0.12 format */
	REG_SET_3(DC_LUT_CONTROL, 0,
		DC_LUT_DATA_R_FORMAT, 3,
		DC_LUT_DATA_G_FORMAT, 3,
		DC_LUT_DATA_B_FORMAT, 3);

	/* start from index 0 */
	REG_SET(DC_LUT_RW_INDEX, 0,
		DC_LUT_RW_INDEX, 0);

	for (i = 0; i < gamma->num_entries; i++) {
		REG_SET(DC_LUT_SEQ_COLOR, 0, DC_LUT_SEQ_COLOR,
				dc_fixpt_round(
					gamma->entries.red[i]));
		REG_SET(DC_LUT_SEQ_COLOR, 0, DC_LUT_SEQ_COLOR,
				dc_fixpt_round(
					gamma->entries.green[i]));
		REG_SET(DC_LUT_SEQ_COLOR, 0, DC_LUT_SEQ_COLOR,
				dc_fixpt_round(
					gamma->entries.blue[i]));
	}

	/* power off LUT memory */
	if (REG(DCFE_MEM_PWR_CTRL))
		REG_SET(DCFE_MEM_PWR_CTRL, 0, DCP_LUT_MEM_PWR_DIS, 0);

	/* bypass prescale, enable legacy LUT */
	REG_UPDATE(PRESCALE_GRPH_CONTROL, GRPH_PRESCALE_BYPASS, 1);
	REG_UPDATE(INPUT_GAMMA_CONTROL, GRPH_INPUT_GAMMA_MODE, 0);
}

__attribute__((used)) static void dce_ipp_set_degamma(
	struct input_pixel_processor *ipp,
	enum ipp_degamma_mode mode)
{
	struct dce_ipp *ipp_dce = TO_DCE_IPP(ipp);
	uint32_t degamma_type = (mode == IPP_DEGAMMA_MODE_HW_sRGB) ? 1 : 0;

	ASSERT(mode == IPP_DEGAMMA_MODE_BYPASS || mode == IPP_DEGAMMA_MODE_HW_sRGB);

	REG_SET_3(DEGAMMA_CONTROL, 0,
		  GRPH_DEGAMMA_MODE, degamma_type,
		  CURSOR_DEGAMMA_MODE, degamma_type,
		  CURSOR2_DEGAMMA_MODE, degamma_type);
}

void dce_ipp_construct(
	struct dce_ipp *ipp_dce,
	struct dc_context *ctx,
	int inst,
	const struct dce_ipp_registers *regs,
	const struct dce_ipp_shift *ipp_shift,
	const struct dce_ipp_mask *ipp_mask)
{
	ipp_dce->base.ctx = ctx;
	ipp_dce->base.inst = inst;
	ipp_dce->base.funcs = &dce_ipp_funcs;

	ipp_dce->regs = regs;
	ipp_dce->ipp_shift = ipp_shift;
	ipp_dce->ipp_mask = ipp_mask;
}

void dce_ipp_destroy(struct input_pixel_processor **ipp)
{
	kfree(TO_DCE_IPP(*ipp));
	*ipp = NULL;
}

