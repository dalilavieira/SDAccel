#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_44__   TYPE_9__ ;
typedef  struct TYPE_43__   TYPE_8__ ;
typedef  struct TYPE_42__   TYPE_7__ ;
typedef  struct TYPE_41__   TYPE_6__ ;
typedef  struct TYPE_40__   TYPE_5__ ;
typedef  struct TYPE_39__   TYPE_4__ ;
typedef  struct TYPE_38__   TYPE_3__ ;
typedef  struct TYPE_37__   TYPE_2__ ;
typedef  struct TYPE_36__   TYPE_22__ ;
typedef  struct TYPE_35__   TYPE_21__ ;
typedef  struct TYPE_34__   TYPE_20__ ;
typedef  struct TYPE_33__   TYPE_1__ ;
typedef  struct TYPE_32__   TYPE_19__ ;
typedef  struct TYPE_31__   TYPE_18__ ;
typedef  struct TYPE_30__   TYPE_17__ ;
typedef  struct TYPE_29__   TYPE_16__ ;
typedef  struct TYPE_28__   TYPE_15__ ;
typedef  struct TYPE_27__   TYPE_14__ ;
typedef  struct TYPE_26__   TYPE_13__ ;
typedef  struct TYPE_25__   TYPE_12__ ;
typedef  struct TYPE_24__   TYPE_11__ ;
typedef  struct TYPE_23__   TYPE_10__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_26__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_27__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_13__ cstate_pstate; } ;
struct TYPE_44__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_23__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_9__ cstate_pstate; } ;
struct TYPE_40__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_41__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_5__ cstate_pstate; } ;
struct TYPE_33__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_37__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_1__ cstate_pstate; } ;
struct TYPE_28__ {TYPE_14__ d; TYPE_10__ c; TYPE_6__ b; TYPE_2__ a; } ;
struct hubbub {int debug_test_index_pstate; struct dcn_hubbub_mask const* masks; struct dcn_hubbub_shift const* shifts; struct dcn_hubbub_registers const* regs; TYPE_22__* funcs; struct dc_context* ctx; TYPE_15__ watermarks; } ;
struct TYPE_29__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_30__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_16__ cstate_pstate; } ;
struct TYPE_24__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_25__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_11__ cstate_pstate; } ;
struct TYPE_42__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_43__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_7__ cstate_pstate; } ;
struct TYPE_38__ {scalar_t__ cstate_enter_plus_exit_ns; scalar_t__ cstate_exit_ns; scalar_t__ pstate_change_ns; } ;
struct TYPE_39__ {scalar_t__ urgent_ns; scalar_t__ pte_meta_urgent_ns; TYPE_3__ cstate_pstate; } ;
struct dcn_watermark_set {TYPE_17__ d; TYPE_12__ c; TYPE_8__ b; TYPE_4__ a; } ;
struct dcn_hubbub_wm_set {int wm_set; void* dram_clk_chanage; void* sr_exit; void* sr_enter; void* pte_meta_urgent; void* data_urgent; } ;
struct TYPE_34__ {int max_uncompressed_blk_size; int max_compressed_blk_size; int independent_64b_blks; } ;
struct TYPE_35__ {TYPE_20__ rgb; } ;
struct dcn_hubbub_wm {int capable; int const_color_support; TYPE_21__ grph; struct dcn_hubbub_wm_set* sets; } ;
struct dcn_hubbub_shift {int dummy; } ;
struct dcn_hubbub_registers {int dummy; } ;
struct dcn_hubbub_mask {int dummy; } ;
struct dchub_init_data {int fb_mode; int zfb_phys_addr_base; int zfb_mc_base_addr; int zfb_size_in_byte; int dchub_initialzied; int dchub_info_valid; } ;
struct dc_surface_dcc_cap {int capable; int const_color_support; TYPE_21__ grph; struct dcn_hubbub_wm_set* sets; } ;
struct TYPE_31__ {unsigned int height; unsigned int width; } ;
struct dc_dcc_surface_param {scalar_t__ scan; TYPE_18__ surface_size; int /*<<< orphan*/  swizzle_mode; int /*<<< orphan*/  format; } ;
struct dc_context {struct dc* dc; } ;
struct TYPE_32__ {scalar_t__ disable_dcc; scalar_t__ disable_stutter; } ;
struct dc {TYPE_19__ debug; } ;
typedef  enum swizzle_mode_values { ____Placeholder_swizzle_mode_values } swizzle_mode_values ;
typedef  enum surface_pixel_format { ____Placeholder_surface_pixel_format } surface_pixel_format ;
typedef  enum segment_order { ____Placeholder_segment_order } segment_order ;
typedef  enum dcc_control { ____Placeholder_dcc_control } dcc_control ;
struct TYPE_36__ {int /*<<< orphan*/  (* dcc_support_swizzle ) (int /*<<< orphan*/ ,unsigned int,int*,int*) ;int /*<<< orphan*/  (* dcc_support_pixel_format ) (int /*<<< orphan*/ ,unsigned int*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 scalar_t__ DCC_DISABLE ; 
 scalar_t__ DCC_HALF_REQ_DISALBE ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_A ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_B ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_C ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_D ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_PSTATE_CHANGE_FORCE_ENABLE ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_PSTATE_CHANGE_FORCE_VALUE ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SELF_REFRESH_FORCE_ENABLE ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SELF_REFRESH_FORCE_VALUE ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_A ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_B ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_C ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_D ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_A ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_B ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_C ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_D ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_A ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_B ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_C ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_D ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_DF_REQ_OUTSTAND ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_DRAM_STATE_CNTL ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_MIN_REQ_OUTSTAND ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_A ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_B ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_C ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_D ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_SAT_LEVEL ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_WATERMARK_CHANGE_CNTL ; 
 int /*<<< orphan*/  DCHUBBUB_ARB_WATERMARK_CHANGE_REQUEST ; 
 int /*<<< orphan*/  DCHUBBUB_GLOBAL_SOFT_RESET ; 
 int /*<<< orphan*/  DCHUBBUB_SDPIF_AGP_BASE ; 
 int /*<<< orphan*/  DCHUBBUB_SDPIF_AGP_BOT ; 
 int /*<<< orphan*/  DCHUBBUB_SDPIF_AGP_TOP ; 
 int /*<<< orphan*/  DCHUBBUB_SDPIF_FB_BASE ; 
 int /*<<< orphan*/  DCHUBBUB_SDPIF_FB_TOP ; 
 int /*<<< orphan*/  DCHUBBUB_SOFT_RESET ; 
 int /*<<< orphan*/  DCHUBBUB_TEST_DEBUG_DATA ; 
 int /*<<< orphan*/  DCHUBBUB_TEST_DEBUG_INDEX ; 
 int /*<<< orphan*/  DC_LOG_BANDWIDTH_CALCS (char*,int,int) ; 
 int /*<<< orphan*/  DC_LOG_WARNING (char*,unsigned int) ; 
#define  DC_SW_4KB_D 154 
#define  DC_SW_4KB_D_X 153 
#define  DC_SW_4KB_S 152 
#define  DC_SW_4KB_S_X 151 
#define  DC_SW_64KB_D 150 
#define  DC_SW_64KB_D_X 149 
#define  DC_SW_64KB_S 148 
#define  DC_SW_64KB_S_X 147 
#define  DC_SW_VAR_D 146 
#define  DC_SW_VAR_D_X 145 
#define  DC_SW_VAR_S 144 
#define  DC_SW_VAR_S_X 143 
#define  FRAME_BUFFER_MODE_LOCAL_ONLY 142 
#define  FRAME_BUFFER_MODE_MIXED_ZFB_AND_LOCAL 141 
#define  FRAME_BUFFER_MODE_ZFB_ONLY 140 
 scalar_t__ REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 void* REG_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_SEQ (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_WRITE (int /*<<< orphan*/ ,int) ; 
 scalar_t__ SCAN_DIRECTION_HORIZONTAL ; 
 scalar_t__ SCAN_DIRECTION_VERTICAL ; 
 int /*<<< orphan*/  SDPIF_AGP_BASE ; 
 int /*<<< orphan*/  SDPIF_AGP_BOT ; 
 int /*<<< orphan*/  SDPIF_AGP_TOP ; 
 int /*<<< orphan*/  SDPIF_FB_BASE ; 
 int /*<<< orphan*/  SDPIF_FB_TOP ; 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR16161616F 139 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010 138 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR8888 137 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB1555 136 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616 135 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616F 134 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB2101010 133 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB8888 132 
#define  SURFACE_PIXEL_FORMAT_GRPH_RGB565 131 
#define  dcc_control__128_128_xxx 130 
#define  dcc_control__256_256_xxx 129 
#define  dcc_control__256_64_64 128 
 TYPE_22__ hubbub1_funcs ; 
 int /*<<< orphan*/  memset (struct dcn_hubbub_wm*,int /*<<< orphan*/ ,int) ; 
 int segment_order__contiguous ; 
 int segment_order__na ; 
 int segment_order__non_contiguous ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ,unsigned int,int*,int*) ; 
 int /*<<< orphan*/  udelay (int) ; 

void hubbub1_wm_read_state(struct hubbub *hubbub,
		struct dcn_hubbub_wm *wm)
{
	struct dcn_hubbub_wm_set *s;

	memset(wm, 0, sizeof(struct dcn_hubbub_wm));

	s = &wm->sets[0];
	s->wm_set = 0;
	s->data_urgent = REG_READ(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_A);
	s->pte_meta_urgent = REG_READ(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_A);
	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_A)) {
		s->sr_enter = REG_READ(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_A);
		s->sr_exit = REG_READ(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_A);
	}
	s->dram_clk_chanage = REG_READ(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_A);

	s = &wm->sets[1];
	s->wm_set = 1;
	s->data_urgent = REG_READ(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_B);
	s->pte_meta_urgent = REG_READ(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_B);
	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_B)) {
		s->sr_enter = REG_READ(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_B);
		s->sr_exit = REG_READ(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_B);
	}
	s->dram_clk_chanage = REG_READ(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_B);

	s = &wm->sets[2];
	s->wm_set = 2;
	s->data_urgent = REG_READ(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_C);
	s->pte_meta_urgent = REG_READ(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_C);
	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_C)) {
		s->sr_enter = REG_READ(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_C);
		s->sr_exit = REG_READ(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_C);
	}
	s->dram_clk_chanage = REG_READ(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_C);

	s = &wm->sets[3];
	s->wm_set = 3;
	s->data_urgent = REG_READ(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_D);
	s->pte_meta_urgent = REG_READ(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_D);
	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_D)) {
		s->sr_enter = REG_READ(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_D);
		s->sr_exit = REG_READ(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_D);
	}
	s->dram_clk_chanage = REG_READ(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_D);
}

bool hubbub1_verify_allow_pstate_change_high(
	struct hubbub *hubbub)
{
	/* pstate latency is ~20us so if we wait over 40us and pstate allow
	 * still not asserted, we are probably stuck and going to hang
	 *
	 * TODO: Figure out why it takes ~100us on linux
	 * pstate takes around ~100us on linux. Unknown currently as to
	 * why it takes that long on linux
	 */
	static unsigned int pstate_wait_timeout_us = 200;
	static unsigned int pstate_wait_expected_timeout_us = 40;
	static unsigned int max_sampled_pstate_wait_us; /* data collection */
	static bool forced_pstate_allow; /* help with revert wa */

	unsigned int debug_data;
	unsigned int i;

	if (forced_pstate_allow) {
		/* we hacked to force pstate allow to prevent hang last time
		 * we verify_allow_pstate_change_high.  so disable force
		 * here so we can check status
		 */
		REG_UPDATE_2(DCHUBBUB_ARB_DRAM_STATE_CNTL,
			     DCHUBBUB_ARB_ALLOW_PSTATE_CHANGE_FORCE_VALUE, 0,
			     DCHUBBUB_ARB_ALLOW_PSTATE_CHANGE_FORCE_ENABLE, 0);
		forced_pstate_allow = false;
	}

	/* RV1:
	 * dchubbubdebugind, at: 0x7
	 * description "3-0:   Pipe0 cursor0 QOS
	 * 7-4:   Pipe1 cursor0 QOS
	 * 11-8:  Pipe2 cursor0 QOS
	 * 15-12: Pipe3 cursor0 QOS
	 * 16:    Pipe0 Plane0 Allow Pstate Change
	 * 17:    Pipe1 Plane0 Allow Pstate Change
	 * 18:    Pipe2 Plane0 Allow Pstate Change
	 * 19:    Pipe3 Plane0 Allow Pstate Change
	 * 20:    Pipe0 Plane1 Allow Pstate Change
	 * 21:    Pipe1 Plane1 Allow Pstate Change
	 * 22:    Pipe2 Plane1 Allow Pstate Change
	 * 23:    Pipe3 Plane1 Allow Pstate Change
	 * 24:    Pipe0 cursor0 Allow Pstate Change
	 * 25:    Pipe1 cursor0 Allow Pstate Change
	 * 26:    Pipe2 cursor0 Allow Pstate Change
	 * 27:    Pipe3 cursor0 Allow Pstate Change
	 * 28:    WB0 Allow Pstate Change
	 * 29:    WB1 Allow Pstate Change
	 * 30:    Arbiter's allow_pstate_change
	 * 31:    SOC pstate change request
	 */


	REG_WRITE(DCHUBBUB_TEST_DEBUG_INDEX, hubbub->debug_test_index_pstate);

	for (i = 0; i < pstate_wait_timeout_us; i++) {
		debug_data = REG_READ(DCHUBBUB_TEST_DEBUG_DATA);

		if (debug_data & (1 << 30)) {

			if (i > pstate_wait_expected_timeout_us)
				DC_LOG_WARNING("pstate took longer than expected ~%dus\n",
						i);

			return true;
		}
		if (max_sampled_pstate_wait_us < i)
			max_sampled_pstate_wait_us = i;

		udelay(1);
	}

	/* force pstate allow to prevent system hang
	 * and break to debugger to investigate
	 */
	REG_UPDATE_2(DCHUBBUB_ARB_DRAM_STATE_CNTL,
		     DCHUBBUB_ARB_ALLOW_PSTATE_CHANGE_FORCE_VALUE, 1,
		     DCHUBBUB_ARB_ALLOW_PSTATE_CHANGE_FORCE_ENABLE, 1);
	forced_pstate_allow = true;

	DC_LOG_WARNING("pstate TEST_DEBUG_DATA: 0x%X\n",
			debug_data);

	return false;
}

__attribute__((used)) static uint32_t convert_and_clamp(
	uint32_t wm_ns,
	uint32_t refclk_mhz,
	uint32_t clamp_value)
{
	uint32_t ret_val = 0;
	ret_val = wm_ns * refclk_mhz;
	ret_val /= 1000;

	if (ret_val > clamp_value)
		ret_val = clamp_value;

	return ret_val;
}

void hubbub1_wm_change_req_wa(struct hubbub *hubbub)
{
	REG_UPDATE_SEQ(DCHUBBUB_ARB_WATERMARK_CHANGE_CNTL,
			DCHUBBUB_ARB_WATERMARK_CHANGE_REQUEST, 0, 1);
}

void hubbub1_program_watermarks(
		struct hubbub *hubbub,
		struct dcn_watermark_set *watermarks,
		unsigned int refclk_mhz,
		bool safe_to_lower)
{
	uint32_t force_en = hubbub->ctx->dc->debug.disable_stutter ? 1 : 0;
	/*
	 * Need to clamp to max of the register values (i.e. no wrap)
	 * for dcn1, all wm registers are 21-bit wide
	 */
	uint32_t prog_wm_value;


	/* Repeat for water mark set A, B, C and D. */
	/* clock state A */
	if (safe_to_lower || watermarks->a.urgent_ns > hubbub->watermarks.a.urgent_ns) {
		hubbub->watermarks.a.urgent_ns = watermarks->a.urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->a.urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_A, prog_wm_value);

		DC_LOG_BANDWIDTH_CALCS("URGENCY_WATERMARK_A calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->a.urgent_ns, prog_wm_value);
	}

	if (safe_to_lower || watermarks->a.pte_meta_urgent_ns > hubbub->watermarks.a.pte_meta_urgent_ns) {
		hubbub->watermarks.a.pte_meta_urgent_ns = watermarks->a.pte_meta_urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->a.pte_meta_urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_A, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("PTE_META_URGENCY_WATERMARK_A calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->a.pte_meta_urgent_ns, prog_wm_value);
	}

	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_A)) {
		if (safe_to_lower || watermarks->a.cstate_pstate.cstate_enter_plus_exit_ns
				> hubbub->watermarks.a.cstate_pstate.cstate_enter_plus_exit_ns) {
			hubbub->watermarks.a.cstate_pstate.cstate_enter_plus_exit_ns =
					watermarks->a.cstate_pstate.cstate_enter_plus_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->a.cstate_pstate.cstate_enter_plus_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_A, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_ENTER_EXIT_WATERMARK_A calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->a.cstate_pstate.cstate_enter_plus_exit_ns, prog_wm_value);
		}

		if (safe_to_lower || watermarks->a.cstate_pstate.cstate_exit_ns
				> hubbub->watermarks.a.cstate_pstate.cstate_exit_ns) {
			hubbub->watermarks.a.cstate_pstate.cstate_exit_ns =
					watermarks->a.cstate_pstate.cstate_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->a.cstate_pstate.cstate_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_A, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_EXIT_WATERMARK_A calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->a.cstate_pstate.cstate_exit_ns, prog_wm_value);
		}
	}

	if (safe_to_lower || watermarks->a.cstate_pstate.pstate_change_ns
			> hubbub->watermarks.a.cstate_pstate.pstate_change_ns) {
		hubbub->watermarks.a.cstate_pstate.pstate_change_ns =
				watermarks->a.cstate_pstate.pstate_change_ns;
		prog_wm_value = convert_and_clamp(
				watermarks->a.cstate_pstate.pstate_change_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_A, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("DRAM_CLK_CHANGE_WATERMARK_A calculated =%d\n"
			"HW register value = 0x%x\n\n",
			watermarks->a.cstate_pstate.pstate_change_ns, prog_wm_value);
	}

	/* clock state B */
	if (safe_to_lower || watermarks->b.urgent_ns > hubbub->watermarks.b.urgent_ns) {
		hubbub->watermarks.b.urgent_ns = watermarks->b.urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->b.urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_B, prog_wm_value);

		DC_LOG_BANDWIDTH_CALCS("URGENCY_WATERMARK_B calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->b.urgent_ns, prog_wm_value);
	}

	if (safe_to_lower || watermarks->b.pte_meta_urgent_ns > hubbub->watermarks.b.pte_meta_urgent_ns) {
		hubbub->watermarks.b.pte_meta_urgent_ns = watermarks->b.pte_meta_urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->b.pte_meta_urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_B, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("PTE_META_URGENCY_WATERMARK_B calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->b.pte_meta_urgent_ns, prog_wm_value);
	}

	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_B)) {
		if (safe_to_lower || watermarks->b.cstate_pstate.cstate_enter_plus_exit_ns
				> hubbub->watermarks.b.cstate_pstate.cstate_enter_plus_exit_ns) {
			hubbub->watermarks.b.cstate_pstate.cstate_enter_plus_exit_ns =
					watermarks->b.cstate_pstate.cstate_enter_plus_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->b.cstate_pstate.cstate_enter_plus_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_B, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_ENTER_EXIT_WATERMARK_B calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->b.cstate_pstate.cstate_enter_plus_exit_ns, prog_wm_value);
		}

		if (safe_to_lower || watermarks->b.cstate_pstate.cstate_exit_ns
				> hubbub->watermarks.b.cstate_pstate.cstate_exit_ns) {
			hubbub->watermarks.b.cstate_pstate.cstate_exit_ns =
					watermarks->b.cstate_pstate.cstate_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->b.cstate_pstate.cstate_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_B, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_EXIT_WATERMARK_B calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->b.cstate_pstate.cstate_exit_ns, prog_wm_value);
		}
	}

	if (safe_to_lower || watermarks->b.cstate_pstate.pstate_change_ns
			> hubbub->watermarks.b.cstate_pstate.pstate_change_ns) {
		hubbub->watermarks.b.cstate_pstate.pstate_change_ns =
				watermarks->b.cstate_pstate.pstate_change_ns;
		prog_wm_value = convert_and_clamp(
				watermarks->b.cstate_pstate.pstate_change_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_B, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("DRAM_CLK_CHANGE_WATERMARK_B calculated =%d\n"
			"HW register value = 0x%x\n\n",
			watermarks->b.cstate_pstate.pstate_change_ns, prog_wm_value);
	}

	/* clock state C */
	if (safe_to_lower || watermarks->c.urgent_ns > hubbub->watermarks.c.urgent_ns) {
		hubbub->watermarks.c.urgent_ns = watermarks->c.urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->c.urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_C, prog_wm_value);

		DC_LOG_BANDWIDTH_CALCS("URGENCY_WATERMARK_C calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->c.urgent_ns, prog_wm_value);
	}

	if (safe_to_lower || watermarks->c.pte_meta_urgent_ns > hubbub->watermarks.c.pte_meta_urgent_ns) {
		hubbub->watermarks.c.pte_meta_urgent_ns = watermarks->c.pte_meta_urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->c.pte_meta_urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_C, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("PTE_META_URGENCY_WATERMARK_C calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->c.pte_meta_urgent_ns, prog_wm_value);
	}

	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_C)) {
		if (safe_to_lower || watermarks->c.cstate_pstate.cstate_enter_plus_exit_ns
				> hubbub->watermarks.c.cstate_pstate.cstate_enter_plus_exit_ns) {
			hubbub->watermarks.c.cstate_pstate.cstate_enter_plus_exit_ns =
					watermarks->c.cstate_pstate.cstate_enter_plus_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->c.cstate_pstate.cstate_enter_plus_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_C, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_ENTER_EXIT_WATERMARK_C calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->c.cstate_pstate.cstate_enter_plus_exit_ns, prog_wm_value);
		}

		if (safe_to_lower || watermarks->c.cstate_pstate.cstate_exit_ns
				> hubbub->watermarks.c.cstate_pstate.cstate_exit_ns) {
			hubbub->watermarks.c.cstate_pstate.cstate_exit_ns =
					watermarks->c.cstate_pstate.cstate_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->c.cstate_pstate.cstate_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_C, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_EXIT_WATERMARK_C calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->c.cstate_pstate.cstate_exit_ns, prog_wm_value);
		}
	}

	if (safe_to_lower || watermarks->c.cstate_pstate.pstate_change_ns
			> hubbub->watermarks.c.cstate_pstate.pstate_change_ns) {
		hubbub->watermarks.c.cstate_pstate.pstate_change_ns =
				watermarks->c.cstate_pstate.pstate_change_ns;
		prog_wm_value = convert_and_clamp(
				watermarks->c.cstate_pstate.pstate_change_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_C, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("DRAM_CLK_CHANGE_WATERMARK_C calculated =%d\n"
			"HW register value = 0x%x\n\n",
			watermarks->c.cstate_pstate.pstate_change_ns, prog_wm_value);
	}

	/* clock state D */
	if (safe_to_lower || watermarks->d.urgent_ns > hubbub->watermarks.d.urgent_ns) {
		hubbub->watermarks.d.urgent_ns = watermarks->d.urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->d.urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_DATA_URGENCY_WATERMARK_D, prog_wm_value);

		DC_LOG_BANDWIDTH_CALCS("URGENCY_WATERMARK_D calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->d.urgent_ns, prog_wm_value);
	}

	if (safe_to_lower || watermarks->d.pte_meta_urgent_ns > hubbub->watermarks.d.pte_meta_urgent_ns) {
		hubbub->watermarks.d.pte_meta_urgent_ns = watermarks->d.pte_meta_urgent_ns;
		prog_wm_value = convert_and_clamp(watermarks->d.pte_meta_urgent_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_PTE_META_URGENCY_WATERMARK_D, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("PTE_META_URGENCY_WATERMARK_D calculated =%d\n"
			"HW register value = 0x%x\n",
			watermarks->d.pte_meta_urgent_ns, prog_wm_value);
	}

	if (REG(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_D)) {
		if (safe_to_lower || watermarks->d.cstate_pstate.cstate_enter_plus_exit_ns
				> hubbub->watermarks.d.cstate_pstate.cstate_enter_plus_exit_ns) {
			hubbub->watermarks.d.cstate_pstate.cstate_enter_plus_exit_ns =
					watermarks->d.cstate_pstate.cstate_enter_plus_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->d.cstate_pstate.cstate_enter_plus_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_ENTER_WATERMARK_D, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_ENTER_EXIT_WATERMARK_D calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->d.cstate_pstate.cstate_enter_plus_exit_ns, prog_wm_value);
		}

		if (safe_to_lower || watermarks->d.cstate_pstate.cstate_exit_ns
				> hubbub->watermarks.d.cstate_pstate.cstate_exit_ns) {
			hubbub->watermarks.d.cstate_pstate.cstate_exit_ns =
					watermarks->d.cstate_pstate.cstate_exit_ns;
			prog_wm_value = convert_and_clamp(
					watermarks->d.cstate_pstate.cstate_exit_ns,
					refclk_mhz, 0x1fffff);
			REG_WRITE(DCHUBBUB_ARB_ALLOW_SR_EXIT_WATERMARK_D, prog_wm_value);
			DC_LOG_BANDWIDTH_CALCS("SR_EXIT_WATERMARK_D calculated =%d\n"
				"HW register value = 0x%x\n",
				watermarks->d.cstate_pstate.cstate_exit_ns, prog_wm_value);
		}
	}

	if (safe_to_lower || watermarks->d.cstate_pstate.pstate_change_ns
			> hubbub->watermarks.d.cstate_pstate.pstate_change_ns) {
		hubbub->watermarks.d.cstate_pstate.pstate_change_ns =
				watermarks->d.cstate_pstate.pstate_change_ns;
		prog_wm_value = convert_and_clamp(
				watermarks->d.cstate_pstate.pstate_change_ns,
				refclk_mhz, 0x1fffff);
		REG_WRITE(DCHUBBUB_ARB_ALLOW_DRAM_CLK_CHANGE_WATERMARK_D, prog_wm_value);
		DC_LOG_BANDWIDTH_CALCS("DRAM_CLK_CHANGE_WATERMARK_D calculated =%d\n"
			"HW register value = 0x%x\n\n",
			watermarks->d.cstate_pstate.pstate_change_ns, prog_wm_value);
	}

	REG_UPDATE(DCHUBBUB_ARB_SAT_LEVEL,
			DCHUBBUB_ARB_SAT_LEVEL, 60 * refclk_mhz);
	REG_UPDATE(DCHUBBUB_ARB_DF_REQ_OUTSTAND,
			DCHUBBUB_ARB_MIN_REQ_OUTSTAND, 68);

	REG_UPDATE_2(DCHUBBUB_ARB_DRAM_STATE_CNTL,
			DCHUBBUB_ARB_ALLOW_SELF_REFRESH_FORCE_VALUE, 0,
			DCHUBBUB_ARB_ALLOW_SELF_REFRESH_FORCE_ENABLE, force_en);

#if 0
	REG_UPDATE_2(DCHUBBUB_ARB_WATERMARK_CHANGE_CNTL,
			DCHUBBUB_ARB_WATERMARK_CHANGE_DONE_INTERRUPT_DISABLE, 1,
			DCHUBBUB_ARB_WATERMARK_CHANGE_REQUEST, 1);
#endif
}

void hubbub1_update_dchub(
	struct hubbub *hubbub,
	struct dchub_init_data *dh_data)
{
	if (REG(DCHUBBUB_SDPIF_FB_TOP) == 0) {
		ASSERT(false);
		/*should not come here*/
		return;
	}
	/* TODO: port code from dal2 */
	switch (dh_data->fb_mode) {
	case FRAME_BUFFER_MODE_ZFB_ONLY:
		/*For ZFB case need to put DCHUB FB BASE and TOP upside down to indicate ZFB mode*/
		REG_UPDATE(DCHUBBUB_SDPIF_FB_TOP,
				SDPIF_FB_TOP, 0);

		REG_UPDATE(DCHUBBUB_SDPIF_FB_BASE,
				SDPIF_FB_BASE, 0x0FFFF);

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_BASE,
				SDPIF_AGP_BASE, dh_data->zfb_phys_addr_base >> 22);

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_BOT,
				SDPIF_AGP_BOT, dh_data->zfb_mc_base_addr >> 22);

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_TOP,
				SDPIF_AGP_TOP, (dh_data->zfb_mc_base_addr +
						dh_data->zfb_size_in_byte - 1) >> 22);
		break;
	case FRAME_BUFFER_MODE_MIXED_ZFB_AND_LOCAL:
		/*Should not touch FB LOCATION (done by VBIOS on AsicInit table)*/

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_BASE,
				SDPIF_AGP_BASE, dh_data->zfb_phys_addr_base >> 22);

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_BOT,
				SDPIF_AGP_BOT, dh_data->zfb_mc_base_addr >> 22);

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_TOP,
				SDPIF_AGP_TOP, (dh_data->zfb_mc_base_addr +
						dh_data->zfb_size_in_byte - 1) >> 22);
		break;
	case FRAME_BUFFER_MODE_LOCAL_ONLY:
		/*Should not touch FB LOCATION (done by VBIOS on AsicInit table)*/
		REG_UPDATE(DCHUBBUB_SDPIF_AGP_BASE,
				SDPIF_AGP_BASE, 0);

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_BOT,
				SDPIF_AGP_BOT, 0X03FFFF);

		REG_UPDATE(DCHUBBUB_SDPIF_AGP_TOP,
				SDPIF_AGP_TOP, 0);
		break;
	default:
		break;
	}

	dh_data->dchub_initialzied = true;
	dh_data->dchub_info_valid = false;
}

void hubbub1_toggle_watermark_change_req(struct hubbub *hubbub)
{
	uint32_t watermark_change_req;

	REG_GET(DCHUBBUB_ARB_WATERMARK_CHANGE_CNTL,
			DCHUBBUB_ARB_WATERMARK_CHANGE_REQUEST, &watermark_change_req);

	if (watermark_change_req)
		watermark_change_req = 0;
	else
		watermark_change_req = 1;

	REG_UPDATE(DCHUBBUB_ARB_WATERMARK_CHANGE_CNTL,
			DCHUBBUB_ARB_WATERMARK_CHANGE_REQUEST, watermark_change_req);
}

void hubbub1_soft_reset(struct hubbub *hubbub, bool reset)
{
	uint32_t reset_en = reset ? 1 : 0;

	REG_UPDATE(DCHUBBUB_SOFT_RESET,
			DCHUBBUB_GLOBAL_SOFT_RESET, reset_en);
}

__attribute__((used)) static bool hubbub1_dcc_support_swizzle(
		enum swizzle_mode_values swizzle,
		unsigned int bytes_per_element,
		enum segment_order *segment_order_horz,
		enum segment_order *segment_order_vert)
{
	bool standard_swizzle = false;
	bool display_swizzle = false;

	switch (swizzle) {
	case DC_SW_4KB_S:
	case DC_SW_64KB_S:
	case DC_SW_VAR_S:
	case DC_SW_4KB_S_X:
	case DC_SW_64KB_S_X:
	case DC_SW_VAR_S_X:
		standard_swizzle = true;
		break;
	case DC_SW_4KB_D:
	case DC_SW_64KB_D:
	case DC_SW_VAR_D:
	case DC_SW_4KB_D_X:
	case DC_SW_64KB_D_X:
	case DC_SW_VAR_D_X:
		display_swizzle = true;
		break;
	default:
		break;
	}

	if (bytes_per_element == 1 && standard_swizzle) {
		*segment_order_horz = segment_order__contiguous;
		*segment_order_vert = segment_order__na;
		return true;
	}
	if (bytes_per_element == 2 && standard_swizzle) {
		*segment_order_horz = segment_order__non_contiguous;
		*segment_order_vert = segment_order__contiguous;
		return true;
	}
	if (bytes_per_element == 4 && standard_swizzle) {
		*segment_order_horz = segment_order__non_contiguous;
		*segment_order_vert = segment_order__contiguous;
		return true;
	}
	if (bytes_per_element == 8 && standard_swizzle) {
		*segment_order_horz = segment_order__na;
		*segment_order_vert = segment_order__contiguous;
		return true;
	}
	if (bytes_per_element == 8 && display_swizzle) {
		*segment_order_horz = segment_order__contiguous;
		*segment_order_vert = segment_order__non_contiguous;
		return true;
	}

	return false;
}

__attribute__((used)) static bool hubbub1_dcc_support_pixel_format(
		enum surface_pixel_format format,
		unsigned int *bytes_per_element)
{
	/* DML: get_bytes_per_element */
	switch (format) {
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB1555:
	case SURFACE_PIXEL_FORMAT_GRPH_RGB565:
		*bytes_per_element = 2;
		return true;
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB8888:
	case SURFACE_PIXEL_FORMAT_GRPH_ABGR8888:
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB2101010:
	case SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010:
		*bytes_per_element = 4;
		return true;
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616:
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616F:
	case SURFACE_PIXEL_FORMAT_GRPH_ABGR16161616F:
		*bytes_per_element = 8;
		return true;
	default:
		return false;
	}
}

__attribute__((used)) static void hubbub1_get_blk256_size(unsigned int *blk256_width, unsigned int *blk256_height,
		unsigned int bytes_per_element)
{
	/* copied from DML.  might want to refactor DML to leverage from DML */
	/* DML : get_blk256_size */
	if (bytes_per_element == 1) {
		*blk256_width = 16;
		*blk256_height = 16;
	} else if (bytes_per_element == 2) {
		*blk256_width = 16;
		*blk256_height = 8;
	} else if (bytes_per_element == 4) {
		*blk256_width = 8;
		*blk256_height = 8;
	} else if (bytes_per_element == 8) {
		*blk256_width = 8;
		*blk256_height = 4;
	}
}

__attribute__((used)) static void hubbub1_det_request_size(
		unsigned int height,
		unsigned int width,
		unsigned int bpe,
		bool *req128_horz_wc,
		bool *req128_vert_wc)
{
	unsigned int detile_buf_size = 164 * 1024;  /* 164KB for DCN1.0 */

	unsigned int blk256_height = 0;
	unsigned int blk256_width = 0;
	unsigned int swath_bytes_horz_wc, swath_bytes_vert_wc;

	hubbub1_get_blk256_size(&blk256_width, &blk256_height, bpe);

	swath_bytes_horz_wc = height * blk256_height * bpe;
	swath_bytes_vert_wc = width * blk256_width * bpe;

	*req128_horz_wc = (2 * swath_bytes_horz_wc <= detile_buf_size) ?
			false : /* full 256B request */
			true; /* half 128b request */

	*req128_vert_wc = (2 * swath_bytes_vert_wc <= detile_buf_size) ?
			false : /* full 256B request */
			true; /* half 128b request */
}

__attribute__((used)) static bool hubbub1_get_dcc_compression_cap(struct hubbub *hubbub,
		const struct dc_dcc_surface_param *input,
		struct dc_surface_dcc_cap *output)
{
	struct dc *dc = hubbub->ctx->dc;
	/* implement section 1.6.2.1 of DCN1_Programming_Guide.docx */
	enum dcc_control dcc_control;
	unsigned int bpe;
	enum segment_order segment_order_horz, segment_order_vert;
	bool req128_horz_wc, req128_vert_wc;

	memset(output, 0, sizeof(*output));

	if (dc->debug.disable_dcc == DCC_DISABLE)
		return false;

	if (!hubbub->funcs->dcc_support_pixel_format(input->format, &bpe))
		return false;

	if (!hubbub->funcs->dcc_support_swizzle(input->swizzle_mode, bpe,
			&segment_order_horz, &segment_order_vert))
		return false;

	hubbub1_det_request_size(input->surface_size.height,  input->surface_size.width,
			bpe, &req128_horz_wc, &req128_vert_wc);

	if (!req128_horz_wc && !req128_vert_wc) {
		dcc_control = dcc_control__256_256_xxx;
	} else if (input->scan == SCAN_DIRECTION_HORIZONTAL) {
		if (!req128_horz_wc)
			dcc_control = dcc_control__256_256_xxx;
		else if (segment_order_horz == segment_order__contiguous)
			dcc_control = dcc_control__128_128_xxx;
		else
			dcc_control = dcc_control__256_64_64;
	} else if (input->scan == SCAN_DIRECTION_VERTICAL) {
		if (!req128_vert_wc)
			dcc_control = dcc_control__256_256_xxx;
		else if (segment_order_vert == segment_order__contiguous)
			dcc_control = dcc_control__128_128_xxx;
		else
			dcc_control = dcc_control__256_64_64;
	} else {
		if ((req128_horz_wc &&
			segment_order_horz == segment_order__non_contiguous) ||
			(req128_vert_wc &&
			segment_order_vert == segment_order__non_contiguous))
			/* access_dir not known, must use most constraining */
			dcc_control = dcc_control__256_64_64;
		else
			/* reg128 is true for either horz and vert
			 * but segment_order is contiguous
			 */
			dcc_control = dcc_control__128_128_xxx;
	}

	if (dc->debug.disable_dcc == DCC_HALF_REQ_DISALBE &&
		dcc_control != dcc_control__256_256_xxx)
		return false;

	switch (dcc_control) {
	case dcc_control__256_256_xxx:
		output->grph.rgb.max_uncompressed_blk_size = 256;
		output->grph.rgb.max_compressed_blk_size = 256;
		output->grph.rgb.independent_64b_blks = false;
		break;
	case dcc_control__128_128_xxx:
		output->grph.rgb.max_uncompressed_blk_size = 128;
		output->grph.rgb.max_compressed_blk_size = 128;
		output->grph.rgb.independent_64b_blks = false;
		break;
	case dcc_control__256_64_64:
		output->grph.rgb.max_uncompressed_blk_size = 256;
		output->grph.rgb.max_compressed_blk_size = 64;
		output->grph.rgb.independent_64b_blks = true;
		break;
	}

	output->capable = true;
	output->const_color_support = false;

	return true;
}

void hubbub1_construct(struct hubbub *hubbub,
	struct dc_context *ctx,
	const struct dcn_hubbub_registers *hubbub_regs,
	const struct dcn_hubbub_shift *hubbub_shift,
	const struct dcn_hubbub_mask *hubbub_mask)
{
	hubbub->ctx = ctx;

	hubbub->funcs = &hubbub1_funcs;

	hubbub->regs = hubbub_regs;
	hubbub->shifts = hubbub_shift;
	hubbub->masks = hubbub_mask;

	hubbub->debug_test_index_pstate = 0x7;
}

