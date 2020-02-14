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
struct TYPE_8__ {TYPE_5__* tg; } ;
struct pipe_ctx {TYPE_3__ stream_res; } ;
struct TYPE_7__ {scalar_t__ blnd_crtc_trigger; } ;
struct dce_hwseq {TYPE_4__* masks; TYPE_2__ wa; } ;
struct dc {struct dce_hwseq* hwseq; } ;
struct clock_source {scalar_t__ id; scalar_t__ dp_clk_src; } ;
typedef  enum surface_pixel_format { ____Placeholder_surface_pixel_format } surface_pixel_format ;
typedef  enum blnd_mode { ____Placeholder_blnd_mode } blnd_mode ;
struct TYPE_10__ {size_t inst; TYPE_1__* funcs; } ;
struct TYPE_9__ {scalar_t__ BLND_BLND_V_UPDATE_LOCK; scalar_t__ BLND_ALPHA_MODE; } ;
struct TYPE_6__ {scalar_t__ (* is_blanked ) (TYPE_5__*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BLNDV_CONTROL ; 
 int /*<<< orphan*/  BLND_ALPHA_MODE ; 
 int /*<<< orphan*/  BLND_BLND_V_UPDATE_LOCK ; 
 int /*<<< orphan*/ * BLND_CONTROL ; 
 int /*<<< orphan*/  BLND_DCP_GRPH_V_UPDATE_LOCK ; 
 int /*<<< orphan*/  BLND_FEEDTHROUGH_EN ; 
 int /*<<< orphan*/  BLND_MODE ; 
#define  BLND_MODE_BLENDING 132 
#define  BLND_MODE_CURRENT_PIPE 131 
#define  BLND_MODE_OTHER_PIPE 130 
 int /*<<< orphan*/  BLND_MULTIPLIED_MODE ; 
 int /*<<< orphan*/  BLND_SCL_V_UPDATE_LOCK ; 
 int /*<<< orphan*/ * BLND_V_UPDATE_LOCK ; 
 int /*<<< orphan*/  BLND_V_UPDATE_LOCK_MODE ; 
 scalar_t__ CLOCK_SOURCE_COMBO_PHY_PLL0 ; 
 scalar_t__ CLOCK_SOURCE_ID_DP_DTO ; 
 int CLOCK_SOURCE_ID_PLL0 ; 
 scalar_t__ CLOCK_SOURCE_ID_PLL2 ; 
 int /*<<< orphan*/ * CRTC_H_BLANK_START_END ; 
 int /*<<< orphan*/  DCFEV_CLOCK_CONTROL ; 
 int /*<<< orphan*/  DCFEV_CLOCK_ENABLE ; 
 int /*<<< orphan*/ * DCFE_CLOCK_CONTROL ; 
 int /*<<< orphan*/  DCFE_CLOCK_ENABLE ; 
 int /*<<< orphan*/  DC_ERR (char*,int,unsigned int) ; 
 int /*<<< orphan*/  DC_MEM_GLOBAL_PWR_REQ_CNTL ; 
 int /*<<< orphan*/  DC_MEM_GLOBAL_PWR_REQ_DIS ; 
 int /*<<< orphan*/  DP_DTO0_ENABLE ; 
 int /*<<< orphan*/ * PHYPLL_PIXEL_RATE_CNTL ; 
 int /*<<< orphan*/  PHYPLL_PIXEL_RATE_SOURCE ; 
 int /*<<< orphan*/ * PIXEL_RATE_CNTL ; 
 int /*<<< orphan*/  PIXEL_RATE_PLL_SOURCE ; 
 int /*<<< orphan*/  PIXEL_RATE_SOURCE ; 
 scalar_t__ REG (int /*<<< orphan*/ ) ; 
 int REG_GET_4 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ,int*) ; 
 int REG_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_SET_2 (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_UPDATE_3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_WRITE (int /*<<< orphan*/ ,int) ; 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR8888 129 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB8888 128 
 scalar_t__ stub1 (TYPE_5__*) ; 

void dce_enable_fe_clock(struct dce_hwseq *hws,
		unsigned int fe_inst, bool enable)
{
	REG_UPDATE(DCFE_CLOCK_CONTROL[fe_inst],
			DCFE_CLOCK_ENABLE, enable);
}

void dce_pipe_control_lock(struct dc *dc,
		struct pipe_ctx *pipe,
		bool lock)
{
	uint32_t lock_val = lock ? 1 : 0;
	uint32_t dcp_grph, scl, blnd, update_lock_mode, val;
	struct dce_hwseq *hws = dc->hwseq;

	/* Not lock pipe when blank */
	if (lock && pipe->stream_res.tg->funcs->is_blanked &&
	    pipe->stream_res.tg->funcs->is_blanked(pipe->stream_res.tg))
		return;

	val = REG_GET_4(BLND_V_UPDATE_LOCK[pipe->stream_res.tg->inst],
			BLND_DCP_GRPH_V_UPDATE_LOCK, &dcp_grph,
			BLND_SCL_V_UPDATE_LOCK, &scl,
			BLND_BLND_V_UPDATE_LOCK, &blnd,
			BLND_V_UPDATE_LOCK_MODE, &update_lock_mode);

	dcp_grph = lock_val;
	scl = lock_val;
	blnd = lock_val;
	update_lock_mode = lock_val;

	REG_SET_2(BLND_V_UPDATE_LOCK[pipe->stream_res.tg->inst], val,
			BLND_DCP_GRPH_V_UPDATE_LOCK, dcp_grph,
			BLND_SCL_V_UPDATE_LOCK, scl);

	if (hws->masks->BLND_BLND_V_UPDATE_LOCK != 0)
		REG_SET_2(BLND_V_UPDATE_LOCK[pipe->stream_res.tg->inst], val,
				BLND_BLND_V_UPDATE_LOCK, blnd,
				BLND_V_UPDATE_LOCK_MODE, update_lock_mode);

	if (hws->wa.blnd_crtc_trigger) {
		if (!lock) {
			uint32_t value = REG_READ(CRTC_H_BLANK_START_END[pipe->stream_res.tg->inst]);
			REG_WRITE(CRTC_H_BLANK_START_END[pipe->stream_res.tg->inst], value);
		}
	}
}

void dce_set_blender_mode(struct dce_hwseq *hws,
	unsigned int blnd_inst,
	enum blnd_mode mode)
{
	uint32_t feedthrough = 1;
	uint32_t blnd_mode = 0;
	uint32_t multiplied_mode = 0;
	uint32_t alpha_mode = 2;

	switch (mode) {
	case BLND_MODE_OTHER_PIPE:
		feedthrough = 0;
		blnd_mode = 1;
		alpha_mode = 0;
		break;
	case BLND_MODE_BLENDING:
		feedthrough = 0;
		blnd_mode = 2;
		alpha_mode = 0;
		multiplied_mode = 1;
		break;
	case BLND_MODE_CURRENT_PIPE:
	default:
		if (REG(BLND_CONTROL[blnd_inst]) == REG(BLNDV_CONTROL) ||
				blnd_inst == 0)
			feedthrough = 0;
		break;
	}

	REG_UPDATE(BLND_CONTROL[blnd_inst],
		BLND_MODE, blnd_mode);

	if (hws->masks->BLND_ALPHA_MODE != 0) {
		REG_UPDATE_3(BLND_CONTROL[blnd_inst],
			BLND_FEEDTHROUGH_EN, feedthrough,
			BLND_ALPHA_MODE, alpha_mode,
			BLND_MULTIPLIED_MODE, multiplied_mode);
	}
}

__attribute__((used)) static void dce_disable_sram_shut_down(struct dce_hwseq *hws)
{
	if (REG(DC_MEM_GLOBAL_PWR_REQ_CNTL))
		REG_UPDATE(DC_MEM_GLOBAL_PWR_REQ_CNTL,
				DC_MEM_GLOBAL_PWR_REQ_DIS, 1);
}

__attribute__((used)) static void dce_underlay_clock_enable(struct dce_hwseq *hws)
{
	/* todo: why do we need this at boot? is dce_enable_fe_clock enough? */
	if (REG(DCFEV_CLOCK_CONTROL))
		REG_UPDATE(DCFEV_CLOCK_CONTROL,
				DCFEV_CLOCK_ENABLE, 1);
}

__attribute__((used)) static void enable_hw_base_light_sleep(void)
{
	/* TODO: implement */
}

__attribute__((used)) static void disable_sw_manual_control_light_sleep(void)
{
	/* TODO: implement */
}

void dce_clock_gating_power_up(struct dce_hwseq *hws,
		bool enable)
{
	if (enable) {
		enable_hw_base_light_sleep();
		disable_sw_manual_control_light_sleep();
	} else {
		dce_disable_sram_shut_down(hws);
		dce_underlay_clock_enable(hws);
	}
}

void dce_crtc_switch_to_clk_src(struct dce_hwseq *hws,
		struct clock_source *clk_src,
		unsigned int tg_inst)
{
	if (clk_src->id == CLOCK_SOURCE_ID_DP_DTO || clk_src->dp_clk_src) {
		REG_UPDATE(PIXEL_RATE_CNTL[tg_inst],
				DP_DTO0_ENABLE, 1);

	} else if (clk_src->id >= CLOCK_SOURCE_COMBO_PHY_PLL0) {
		uint32_t rate_source = clk_src->id - CLOCK_SOURCE_COMBO_PHY_PLL0;

		REG_UPDATE_2(PHYPLL_PIXEL_RATE_CNTL[tg_inst],
				PHYPLL_PIXEL_RATE_SOURCE, rate_source,
				PIXEL_RATE_PLL_SOURCE, 0);

		REG_UPDATE(PIXEL_RATE_CNTL[tg_inst],
				DP_DTO0_ENABLE, 0);

	} else if (clk_src->id <= CLOCK_SOURCE_ID_PLL2) {
		uint32_t rate_source = clk_src->id - CLOCK_SOURCE_ID_PLL0;

		REG_UPDATE_2(PIXEL_RATE_CNTL[tg_inst],
				PIXEL_RATE_SOURCE, rate_source,
				DP_DTO0_ENABLE, 0);

		if (REG(PHYPLL_PIXEL_RATE_CNTL[tg_inst]))
			REG_UPDATE(PHYPLL_PIXEL_RATE_CNTL[tg_inst],
					PIXEL_RATE_PLL_SOURCE, 1);
	} else {
		DC_ERR("Unknown clock source. clk_src id: %d, TG_inst: %d",
		       clk_src->id, tg_inst);
	}
}

bool dce_use_lut(enum surface_pixel_format format)
{
	switch (format) {
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB8888:
	case SURFACE_PIXEL_FORMAT_GRPH_ABGR8888:
		return true;
	default:
		return false;
	}
}

