#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_9__ ;
typedef  struct TYPE_19__   TYPE_8__ ;
typedef  struct TYPE_18__   TYPE_7__ ;
typedef  struct TYPE_17__   TYPE_6__ ;
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;
typedef  struct TYPE_11__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  scalar_t__ uint32_t ;
struct TYPE_13__ {scalar_t__ requested_pix_clk; } ;
struct TYPE_14__ {TYPE_2__ pix_clk_params; } ;
struct pipe_ctx {TYPE_3__ stream_res; scalar_t__ top_pipe; int /*<<< orphan*/ * stream; } ;
struct dm_pp_display_configuration {int /*<<< orphan*/  avail_mclk_switch_time_us; } ;
struct TYPE_20__ {struct pipe_ctx* pipe_ctx; } ;
struct TYPE_15__ {int dispclk_khz; } ;
struct TYPE_16__ {TYPE_4__ dce; } ;
struct dc_state {TYPE_9__ res_ctx; TYPE_5__ bw; struct dm_pp_display_configuration pp_display_cfg; } ;
struct dc_context {int dummy; } ;
struct dc_clocks {int dispclk_khz; scalar_t__ phyclk_khz; } ;
struct dc_bios {TYPE_1__* funcs; } ;
struct TYPE_18__ {int (* enable_display_power_gating ) (struct dc*,scalar_t__,struct dc_bios*,int) ;void (* set_bandwidth ) (struct dc*,struct dc_state*,int) ;void (* pplib_apply_display_requirements ) (struct dc*,struct dc_state*) ;} ;
struct dc {TYPE_7__ hwss; TYPE_10__* res_pool; struct dm_pp_display_configuration prev_display_config; struct dc_context* ctx; } ;
typedef  enum pipe_gating_control { ____Placeholder_pipe_gating_control } pipe_gating_control ;
typedef  enum bp_result { ____Placeholder_bp_result } bp_result ;
typedef  enum bp_pipe_control_action { ____Placeholder_bp_pipe_control_action } bp_pipe_control_action ;
struct TYPE_19__ {TYPE_6__* funcs; } ;
struct TYPE_17__ {int /*<<< orphan*/  (* update_clocks ) (TYPE_8__*,struct dc_clocks*,int) ;} ;
struct TYPE_12__ {int (* enable_disp_power_gating ) (struct dc_bios*,scalar_t__,int) ;} ;
struct TYPE_11__ {TYPE_8__* dccg; } ;

/* Variables and functions */
 int ASIC_PIPE_DISABLE ; 
 int ASIC_PIPE_ENABLE ; 
 int ASIC_PIPE_INIT ; 
 int BP_RESULT_OK ; 
 int /*<<< orphan*/  HW_REG_CRTC (int /*<<< orphan*/ ,scalar_t__) ; 
 int MAX_PIPES ; 
 int PIPE_GATING_CONTROL_ENABLE ; 
 int PIPE_GATING_CONTROL_INIT ; 
 int /*<<< orphan*/  dce110_fill_display_configs (struct dc_state*,struct dm_pp_display_configuration*) ; 
 int /*<<< orphan*/  dce110_get_min_vblank_time_us (struct dc_state*) ; 
 int /*<<< orphan*/  dce110_hw_sequencer_construct (struct dc*) ; 
 int /*<<< orphan*/  dce110_set_safe_displaymarks (TYPE_9__*,TYPE_10__*) ; 
 int /*<<< orphan*/  dm_pp_apply_display_requirements (struct dc_context*,struct dm_pp_display_configuration*) ; 
 int /*<<< orphan*/  dm_write_reg (struct dc_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (struct dm_pp_display_configuration*,struct dm_pp_display_configuration*,int) ; 
 int /*<<< orphan*/  mmMASTER_UPDATE_MODE ; 
 int stub1 (struct dc_bios*,scalar_t__,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_8__*,struct dc_clocks*,int) ; 

bool dce100_enable_display_power_gating(
	struct dc *dc,
	uint8_t controller_id,
	struct dc_bios *dcb,
	enum pipe_gating_control power_gating)
{
	enum bp_result bp_result = BP_RESULT_OK;
	enum bp_pipe_control_action cntl;
	struct dc_context *ctx = dc->ctx;

	if (power_gating == PIPE_GATING_CONTROL_INIT)
		cntl = ASIC_PIPE_INIT;
	else if (power_gating == PIPE_GATING_CONTROL_ENABLE)
		cntl = ASIC_PIPE_ENABLE;
	else
		cntl = ASIC_PIPE_DISABLE;

	if (!(power_gating == PIPE_GATING_CONTROL_INIT && controller_id != 0)){

		bp_result = dcb->funcs->enable_disp_power_gating(
						dcb, controller_id + 1, cntl);

		/* Revert MASTER_UPDATE_MODE to 0 because bios sets it 2
		 * by default when command table is called
		 */
		dm_write_reg(ctx,
			HW_REG_CRTC(mmMASTER_UPDATE_MODE, controller_id),
			0);
	}

	if (bp_result == BP_RESULT_OK)
		return true;
	else
		return false;
}

__attribute__((used)) static void dce100_pplib_apply_display_requirements(
	struct dc *dc,
	struct dc_state *context)
{
	struct dm_pp_display_configuration *pp_display_cfg = &context->pp_display_cfg;

	pp_display_cfg->avail_mclk_switch_time_us =
						dce110_get_min_vblank_time_us(context);
	/*pp_display_cfg->min_memory_clock_khz = context->bw.dce.yclk_khz
		/ MEMORY_TYPE_MULTIPLIER;*/

	dce110_fill_display_configs(context, pp_display_cfg);

	if (memcmp(&dc->prev_display_config, pp_display_cfg, sizeof(
			struct dm_pp_display_configuration)) !=  0)
		dm_pp_apply_display_requirements(dc->ctx, pp_display_cfg);

	dc->prev_display_config = *pp_display_cfg;
}

__attribute__((used)) static uint32_t get_max_pixel_clock_for_all_paths(
	struct dc *dc,
	struct dc_state *context)
{
	uint32_t max_pix_clk = 0;
	int i;

	for (i = 0; i < MAX_PIPES; i++) {
		struct pipe_ctx *pipe_ctx = &context->res_ctx.pipe_ctx[i];

		if (pipe_ctx->stream == NULL)
			continue;

		/* do not check under lay */
		if (pipe_ctx->top_pipe)
			continue;

		if (pipe_ctx->stream_res.pix_clk_params.requested_pix_clk > max_pix_clk)
			max_pix_clk =
				pipe_ctx->stream_res.pix_clk_params.requested_pix_clk;
	}
	return max_pix_clk;
}

void dce100_set_bandwidth(
		struct dc *dc,
		struct dc_state *context,
		bool decrease_allowed)
{
	struct dc_clocks req_clks;

	req_clks.dispclk_khz = context->bw.dce.dispclk_khz * 115 / 100;
	req_clks.phyclk_khz = get_max_pixel_clock_for_all_paths(dc, context);

	dce110_set_safe_displaymarks(&context->res_ctx, dc->res_pool);

	dc->res_pool->dccg->funcs->update_clocks(
			dc->res_pool->dccg,
			&req_clks,
			decrease_allowed);

	dce100_pplib_apply_display_requirements(dc, context);
}

void dce100_hw_sequencer_construct(struct dc *dc)
{
	dce110_hw_sequencer_construct(dc);

	dc->hwss.enable_display_power_gating = dce100_enable_display_power_gating;
	dc->hwss.set_bandwidth = dce100_set_bandwidth;
	dc->hwss.pplib_apply_display_requirements =
			dce100_pplib_apply_display_requirements;
}

