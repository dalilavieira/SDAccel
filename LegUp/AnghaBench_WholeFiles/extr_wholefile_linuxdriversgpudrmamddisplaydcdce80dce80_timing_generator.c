#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  int uint32_t ;
struct timing_generator {int /*<<< orphan*/  ctx; } ;
struct dce110_timing_generator_offsets {int dmif; } ;
struct TYPE_2__ {int inst; int /*<<< orphan*/  bp; struct dc_context* ctx; int /*<<< orphan*/ * funcs; } ;
struct dce110_timing_generator {int min_h_blank; int min_h_front_porch; int min_h_back_porch; scalar_t__ max_v_total; scalar_t__ max_h_total; TYPE_1__ base; int /*<<< orphan*/  derived_offsets; struct dce110_timing_generator_offsets offsets; scalar_t__ controller_id; } ;
struct dc_crtc_timing {int pix_clk_khz; int v_sync_width; int v_front_porch; } ;
struct dc_context {int /*<<< orphan*/  dc_bios; } ;

/* Variables and functions */
 scalar_t__ CONTROLLER_ID_D0 ; 
 int /*<<< orphan*/  CRTC_ADVANCED_START_LINE_POSITION ; 
 scalar_t__ CRTC_H_TOTAL__CRTC_H_TOTAL_MASK ; 
 int /*<<< orphan*/  CRTC_INTERLACE_START_LINE_EARLY ; 
 int /*<<< orphan*/  CRTC_LEGACY_REQUESTOR_EN ; 
 int /*<<< orphan*/  CRTC_PREFETCH_EN ; 
 int /*<<< orphan*/  CRTC_PROGRESSIVE_START_LINE_EARLY ; 
 int CRTC_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRTC_START_LINE_CONTROL ; 
 scalar_t__ CRTC_V_TOTAL__CRTC_V_TOTAL_MASK ; 
 struct dce110_timing_generator* DCE110TG_FROM_TG (struct timing_generator*) ; 
 int /*<<< orphan*/  DPG_PIPE_ARBITRATION_CONTROL1 ; 
 int /*<<< orphan*/  PIXEL_DURATION ; 
 int /*<<< orphan*/  dce110_tg_program_timing (struct timing_generator*,struct dc_crtc_timing const*,int) ; 
 int /*<<< orphan*/  dce80_tg_funcs ; 
 int dm_read_reg (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dm_write_reg (int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  mmCRTC_START_LINE_CONTROL ; 
 int mmDMIF_PG0_DPG_PIPE_ARBITRATION_CONTROL1 ; 
 int /*<<< orphan*/ * reg_offsets ; 
 int /*<<< orphan*/  set_reg_field_value (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void program_pix_dur(struct timing_generator *tg, uint32_t pix_clk_khz)
{
	uint64_t pix_dur;
	uint32_t addr = mmDMIF_PG0_DPG_PIPE_ARBITRATION_CONTROL1
					+ DCE110TG_FROM_TG(tg)->offsets.dmif;
	uint32_t value = dm_read_reg(tg->ctx, addr);

	if (pix_clk_khz == 0)
		return;

	pix_dur = 1000000000 / pix_clk_khz;

	set_reg_field_value(
		value,
		pix_dur,
		DPG_PIPE_ARBITRATION_CONTROL1,
		PIXEL_DURATION);

	dm_write_reg(tg->ctx, addr, value);
}

__attribute__((used)) static void program_timing(struct timing_generator *tg,
	const struct dc_crtc_timing *timing,
	bool use_vbios)
{
	if (!use_vbios)
		program_pix_dur(tg, timing->pix_clk_khz);

	dce110_tg_program_timing(tg, timing, use_vbios);
}

__attribute__((used)) static void dce80_timing_generator_enable_advanced_request(
	struct timing_generator *tg,
	bool enable,
	const struct dc_crtc_timing *timing)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t addr = CRTC_REG(mmCRTC_START_LINE_CONTROL);
	uint32_t value = dm_read_reg(tg->ctx, addr);

	if (enable) {
		set_reg_field_value(
			value,
			0,
			CRTC_START_LINE_CONTROL,
			CRTC_LEGACY_REQUESTOR_EN);
	} else {
		set_reg_field_value(
			value,
			1,
			CRTC_START_LINE_CONTROL,
			CRTC_LEGACY_REQUESTOR_EN);
	}

	if ((timing->v_sync_width + timing->v_front_porch) <= 3) {
		set_reg_field_value(
			value,
			3,
			CRTC_START_LINE_CONTROL,
			CRTC_ADVANCED_START_LINE_POSITION);
		set_reg_field_value(
			value,
			0,
			CRTC_START_LINE_CONTROL,
			CRTC_PREFETCH_EN);
	} else {
		set_reg_field_value(
			value,
			4,
			CRTC_START_LINE_CONTROL,
			CRTC_ADVANCED_START_LINE_POSITION);
		set_reg_field_value(
			value,
			1,
			CRTC_START_LINE_CONTROL,
			CRTC_PREFETCH_EN);
	}

	set_reg_field_value(
		value,
		1,
		CRTC_START_LINE_CONTROL,
		CRTC_PROGRESSIVE_START_LINE_EARLY);

	set_reg_field_value(
		value,
		1,
		CRTC_START_LINE_CONTROL,
		CRTC_INTERLACE_START_LINE_EARLY);

	dm_write_reg(tg->ctx, addr, value);
}

void dce80_timing_generator_construct(
	struct dce110_timing_generator *tg110,
	struct dc_context *ctx,
	uint32_t instance,
	const struct dce110_timing_generator_offsets *offsets)
{
	tg110->controller_id = CONTROLLER_ID_D0 + instance;
	tg110->base.inst = instance;
	tg110->offsets = *offsets;
	tg110->derived_offsets = reg_offsets[instance];

	tg110->base.funcs = &dce80_tg_funcs;

	tg110->base.ctx = ctx;
	tg110->base.bp = ctx->dc_bios;

	tg110->max_h_total = CRTC_H_TOTAL__CRTC_H_TOTAL_MASK + 1;
	tg110->max_v_total = CRTC_V_TOTAL__CRTC_V_TOTAL_MASK + 1;

	tg110->min_h_blank = 56;
	tg110->min_h_front_porch = 4;
	tg110->min_h_back_porch = 4;
}

