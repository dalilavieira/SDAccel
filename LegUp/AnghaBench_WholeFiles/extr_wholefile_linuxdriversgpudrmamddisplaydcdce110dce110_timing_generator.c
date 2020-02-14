#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_9__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct timing_generator {int inst; struct dc_context* ctx; TYPE_4__* funcs; TYPE_6__* bp; } ;
struct tg_color {int color_b_cb; int color_g_y; int color_r_cr; } ;
struct drr_params {int vertical_total_max; int vertical_total_min; } ;
struct dcp_gsl_params {int gsl_master; } ;
struct dce110_timing_generator_offsets {int dummy; } ;
struct TYPE_14__ {int inst; int /*<<< orphan*/  bp; struct dc_context* ctx; TYPE_9__* funcs; } ;
struct dce110_timing_generator {int controller_id; scalar_t__ max_h_total; scalar_t__ max_v_total; int min_h_blank; scalar_t__ min_h_front_porch; int min_h_back_porch; TYPE_5__ base; struct dce110_timing_generator_offsets offsets; } ;
struct TYPE_12__ {int INTERLACE; int HORZ_COUNT_BY_TWO; int HSYNC_POSITIVE_POLARITY; int VSYNC_POSITIVE_POLARITY; } ;
struct dc_crtc_timing {int v_front_porch; int v_border_bottom; int v_addressable; int h_border_right; int h_front_porch; int h_addressable; int h_total; int v_total; int h_sync_width; int v_sync_width; int h_border_left; int v_border_top; scalar_t__ timing_3d_format; TYPE_3__ flags; } ;
struct dc_context {int /*<<< orphan*/  dc_bios; } ;
struct crtc_trigger_info {int event; int delay; } ;
struct crtc_position {int horizontal_count; int vertical_count; int nominal_vcount; } ;
struct crc_params {int windowa_x_start; int windowa_x_end; int windowa_y_start; int windowa_y_end; int windowb_x_start; int windowb_x_end; int windowb_y_start; int windowb_y_end; int selection; scalar_t__ continuous_mode; int /*<<< orphan*/  enable; } ;
struct TYPE_10__ {int HSYNC_POSITIVE_POLARITY; int VSYNC_POSITIVE_POLARITY; int INTERLACE; int HORZ_COUNT_BY_TWO; } ;
struct bp_hw_crtc_timing_parameters {int controller_id; int h_total; int h_addressable; int v_total; int v_addressable; int h_sync_start; int h_sync_width; int v_sync_start; int v_sync_width; int h_overscan_left; int h_overscan_right; int v_overscan_top; int v_overscan_bottom; TYPE_1__ flags; } ;
typedef  enum trigger_source_select { ____Placeholder_trigger_source_select } trigger_source_select ;
typedef  enum test_pattern_mode { ____Placeholder_test_pattern_mode } test_pattern_mode ;
typedef  enum test_pattern_dyn_range { ____Placeholder_test_pattern_dyn_range } test_pattern_dyn_range ;
typedef  enum test_pattern_color_format { ____Placeholder_test_pattern_color_format } test_pattern_color_format ;
typedef  enum signal_type { ____Placeholder_signal_type } signal_type ;
typedef  enum dc_color_depth { ____Placeholder_dc_color_depth } dc_color_depth ;
typedef  enum crtc_state { ____Placeholder_crtc_state } crtc_state ;
typedef  enum controller_dp_test_pattern { ____Placeholder_controller_dp_test_pattern } controller_dp_test_pattern ;
typedef  enum bp_result { ____Placeholder_bp_result } bp_result ;
struct TYPE_16__ {int /*<<< orphan*/  (* enable_advanced_request ) (struct timing_generator*,int,struct dc_crtc_timing*) ;} ;
struct TYPE_15__ {TYPE_2__* funcs; } ;
struct TYPE_13__ {int /*<<< orphan*/  (* get_scanoutpos ) (struct timing_generator*,int*,int*,int*,int*) ;int /*<<< orphan*/  (* get_position ) (struct timing_generator*,struct crtc_position*) ;} ;
struct TYPE_11__ {int (* enable_crtc ) (TYPE_6__*,int,int) ;int (* program_crtc_timing ) (TYPE_6__*,struct bp_hw_crtc_timing_parameters*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int /*<<< orphan*/ ) ; 
 int BP_RESULT_OK ; 
#define  COLOR_DEPTH_101010 152 
#define  COLOR_DEPTH_121212 151 
#define  COLOR_DEPTH_666 150 
#define  COLOR_DEPTH_888 149 
#define  CONTROLLER_DP_TEST_PATTERN_COLORRAMP 148 
#define  CONTROLLER_DP_TEST_PATTERN_COLORSQUARES 147 
#define  CONTROLLER_DP_TEST_PATTERN_COLORSQUARES_CEA 146 
#define  CONTROLLER_DP_TEST_PATTERN_HORIZONTALBARS 145 
#define  CONTROLLER_DP_TEST_PATTERN_VERTICALBARS 144 
#define  CONTROLLER_DP_TEST_PATTERN_VIDEOMODE 143 
#define  CONTROLLER_ID_D0 142 
#define  CONTROLLER_ID_D1 141 
#define  CONTROLLER_ID_D2 140 
#define  CONTROLLER_ID_D3 139 
#define  CONTROLLER_ID_D4 138 
#define  CONTROLLER_ID_D5 137 
 int /*<<< orphan*/  CRC0_B_CB ; 
 int /*<<< orphan*/  CRC0_G_Y ; 
 int /*<<< orphan*/  CRC0_R_CR ; 
 int /*<<< orphan*/  CRTC_ADVANCED_START_LINE_POSITION ; 
 int /*<<< orphan*/  CRTC_AUTO_FORCE_VSYNC_MODE ; 
 int /*<<< orphan*/  CRTC_BLACK_COLOR ; 
 int /*<<< orphan*/  CRTC_BLACK_COLOR_B_CB ; 
 int /*<<< orphan*/  CRTC_BLACK_COLOR_G_Y ; 
 int /*<<< orphan*/  CRTC_BLACK_COLOR_R_CR ; 
 int /*<<< orphan*/  CRTC_BLANK_CONTROL ; 
 int /*<<< orphan*/  CRTC_BLANK_DATA_DOUBLE_BUFFER_EN ; 
 int /*<<< orphan*/  CRTC_BLANK_DATA_EN ; 
 int /*<<< orphan*/  CRTC_CONTROL ; 
 int /*<<< orphan*/  CRTC_COUNT_CONTROL ; 
 int /*<<< orphan*/  CRTC_CRC0_DATA_B ; 
 int /*<<< orphan*/  CRTC_CRC0_DATA_RG ; 
 int /*<<< orphan*/  CRTC_CRC0_SELECT ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWA_X_CONTROL ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWA_X_END ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWA_X_START ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWA_Y_CONTROL ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWA_Y_END ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWA_Y_START ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWB_X_CONTROL ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWB_X_END ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWB_X_START ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWB_Y_CONTROL ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWB_Y_END ; 
 int /*<<< orphan*/  CRTC_CRC0_WINDOWB_Y_START ; 
 int /*<<< orphan*/  CRTC_CRC_CNTL ; 
 int /*<<< orphan*/  CRTC_CRC_CONT_EN ; 
 int /*<<< orphan*/  CRTC_CRC_EN ; 
 int /*<<< orphan*/  CRTC_CURRENT_BLANK_STATE ; 
 int /*<<< orphan*/  CRTC_CURRENT_MASTER_EN_STATE ; 
 int /*<<< orphan*/  CRTC_DOUBLE_BUFFER_CONTROL ; 
#define  CRTC_EVENT_VSYNC_FALLING 136 
#define  CRTC_EVENT_VSYNC_RISING 135 
 int /*<<< orphan*/  CRTC_FORCE_COUNT_NOW_CLEAR ; 
 int /*<<< orphan*/  CRTC_FORCE_COUNT_NOW_CNTL ; 
 int /*<<< orphan*/  CRTC_FORCE_COUNT_NOW_MODE ; 
 int /*<<< orphan*/  CRTC_FORCE_COUNT_NOW_OCCURRED ; 
 int /*<<< orphan*/  CRTC_FORCE_COUNT_NOW_TRIG_SEL ; 
 int /*<<< orphan*/  CRTC_FORCE_LOCK_ON_EVENT ; 
 int /*<<< orphan*/  CRTC_FORCE_LOCK_TO_MASTER_VSYNC ; 
 int /*<<< orphan*/  CRTC_FORCE_VSYNC_NEXT_LINE_CLEAR ; 
 int /*<<< orphan*/  CRTC_FORCE_VSYNC_NEXT_LINE_OCCURRED ; 
 int /*<<< orphan*/  CRTC_FRAME_COUNT ; 
 int /*<<< orphan*/  CRTC_GSL_CHECK_LINE_NUM ; 
 int /*<<< orphan*/  CRTC_GSL_CONTROL ; 
 int /*<<< orphan*/  CRTC_GSL_FORCE_DELAY ; 
 int /*<<< orphan*/  CRTC_HBLANK_EARLY_CONTROL ; 
 int /*<<< orphan*/  CRTC_HORZ_COUNT ; 
 int /*<<< orphan*/  CRTC_HORZ_COUNT_BY2_EN ; 
 int /*<<< orphan*/  CRTC_H_BLANK_END ; 
 int /*<<< orphan*/  CRTC_H_BLANK_START ; 
 int /*<<< orphan*/  CRTC_H_BLANK_START_END ; 
 int /*<<< orphan*/  CRTC_H_TOTAL ; 
 scalar_t__ CRTC_H_TOTAL__CRTC_H_TOTAL_MASK ; 
 int /*<<< orphan*/  CRTC_INTERLACE_START_LINE_EARLY ; 
 int /*<<< orphan*/  CRTC_LEGACY_REQUESTOR_EN ; 
 int /*<<< orphan*/  CRTC_MASTER_UPDATE_LOCK ; 
 int /*<<< orphan*/  CRTC_MASTER_UPDATE_MODE ; 
 int /*<<< orphan*/  CRTC_NOM_VERT_POSITION ; 
 int /*<<< orphan*/  CRTC_OVERSCAN_COLOR ; 
 int /*<<< orphan*/  CRTC_OVERSCAN_COLOR_BLUE ; 
 int /*<<< orphan*/  CRTC_OVERSCAN_COLOR_GREEN ; 
 int /*<<< orphan*/  CRTC_OVERSCAN_COLOR_RED ; 
 int /*<<< orphan*/  CRTC_PREFETCH_EN ; 
 int /*<<< orphan*/  CRTC_PROGRESSIVE_START_LINE_EARLY ; 
 int CRTC_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRTC_SET_V_TOTAL_MIN_MASK ; 
 int /*<<< orphan*/  CRTC_SET_V_TOTAL_MIN_MASK_EN ; 
 int /*<<< orphan*/  CRTC_START_LINE_CONTROL ; 
#define  CRTC_STATE_VACTIVE 134 
#define  CRTC_STATE_VBLANK 133 
 int /*<<< orphan*/  CRTC_STATIC_SCREEN_CONTROL ; 
 int /*<<< orphan*/  CRTC_STATIC_SCREEN_EVENT_MASK ; 
 int /*<<< orphan*/  CRTC_STATIC_SCREEN_FRAME_COUNT ; 
 int /*<<< orphan*/  CRTC_STATUS ; 
 int /*<<< orphan*/  CRTC_STATUS_FRAME_COUNT ; 
 int /*<<< orphan*/  CRTC_STATUS_POSITION ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_COLOR ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_COLOR_FORMAT ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_CONTROL ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_DATA ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_DYNAMIC_RANGE ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_EN ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_HRES ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_INC0 ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_INC1 ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_MASK ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_MODE ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_PARAMETERS ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_RAMP0_OFFSET ; 
 int /*<<< orphan*/  CRTC_TEST_PATTERN_VRES ; 
 int /*<<< orphan*/  CRTC_TRIGB_CLEAR ; 
 int /*<<< orphan*/  CRTC_TRIGB_CNTL ; 
 int /*<<< orphan*/  CRTC_TRIGB_DELAY ; 
 int /*<<< orphan*/  CRTC_TRIGB_FALLING_EDGE_DETECT_CNTL ; 
 int /*<<< orphan*/  CRTC_TRIGB_FREQUENCY_SELECT ; 
 int /*<<< orphan*/  CRTC_TRIGB_POLARITY_SELECT ; 
 int /*<<< orphan*/  CRTC_TRIGB_RISING_EDGE_DETECT_CNTL ; 
 int /*<<< orphan*/  CRTC_TRIGB_SOURCE_SELECT ; 
 int /*<<< orphan*/  CRTC_VERTICAL_INTERRUPT0_LINE_END ; 
 int /*<<< orphan*/  CRTC_VERTICAL_INTERRUPT0_LINE_START ; 
 int /*<<< orphan*/  CRTC_VERTICAL_INTERRUPT0_POSITION ; 
 int /*<<< orphan*/  CRTC_VERT_COUNT ; 
 int /*<<< orphan*/  CRTC_VERT_COUNT_NOM ; 
 int /*<<< orphan*/  CRTC_VERT_SYNC_CONTROL ; 
 int /*<<< orphan*/  CRTC_V_BLANK ; 
 int /*<<< orphan*/  CRTC_V_BLANK_END ; 
 int /*<<< orphan*/  CRTC_V_BLANK_START ; 
 int /*<<< orphan*/  CRTC_V_BLANK_START_END ; 
 int /*<<< orphan*/  CRTC_V_SYNC_A_CNTL ; 
 int /*<<< orphan*/  CRTC_V_SYNC_A_POL ; 
 int /*<<< orphan*/  CRTC_V_TOTAL ; 
 int /*<<< orphan*/  CRTC_V_TOTAL_CONTROL ; 
 int /*<<< orphan*/  CRTC_V_TOTAL_MAX ; 
 int /*<<< orphan*/  CRTC_V_TOTAL_MAX_SEL ; 
 int /*<<< orphan*/  CRTC_V_TOTAL_MIN ; 
 int /*<<< orphan*/  CRTC_V_TOTAL_MIN_SEL ; 
 scalar_t__ CRTC_V_TOTAL__CRTC_V_TOTAL_MASK ; 
 int /*<<< orphan*/  D1VGA_CONTROL ; 
 int /*<<< orphan*/  D1VGA_MODE_ENABLE ; 
 int /*<<< orphan*/  D1VGA_OVERSCAN_COLOR_EN ; 
 int /*<<< orphan*/  D1VGA_SYNC_POLARITY_SELECT ; 
 int /*<<< orphan*/  D1VGA_TIMING_SELECT ; 
 struct dce110_timing_generator* DCE110TG_FROM_TG (struct timing_generator*) ; 
 int /*<<< orphan*/  DCIO_GSL0_CNTL ; 
 int /*<<< orphan*/  DCIO_GSL0_GLOBAL_UNLOCK_SEL ; 
 int /*<<< orphan*/  DCIO_GSL0_TIMING_SYNC_SEL ; 
 int /*<<< orphan*/  DCIO_GSL0_VSYNC_SEL ; 
 int /*<<< orphan*/  DCP_GSL0_EN ; 
 int /*<<< orphan*/  DCP_GSL_CONTROL ; 
 int /*<<< orphan*/  DCP_GSL_DELAY_SURFACE_UPDATE_PENDING ; 
 int /*<<< orphan*/  DCP_GSL_HSYNC_FLIP_CHECK_DELAY ; 
 int /*<<< orphan*/  DCP_GSL_HSYNC_FLIP_FORCE_DELAY ; 
 int /*<<< orphan*/  DCP_GSL_MASTER_EN ; 
 int /*<<< orphan*/  DCP_GSL_SYNC_SOURCE ; 
 int DCP_REG (int /*<<< orphan*/ ) ; 
 int FLIP_READY_BACK_LOOKUP ; 
 int HFLIP_CHECK_DELAY ; 
 int HFLIP_READY_DELAY ; 
 int /*<<< orphan*/  MASTER_UPDATE_LOCK ; 
 int /*<<< orphan*/  MASTER_UPDATE_MODE ; 
 int SIGNAL_TYPE_NONE ; 
#define  TEST_PATTERN_COLOR_FORMAT_BPC_10 132 
 int TEST_PATTERN_COLOR_FORMAT_BPC_12 ; 
#define  TEST_PATTERN_COLOR_FORMAT_BPC_6 131 
#define  TEST_PATTERN_COLOR_FORMAT_BPC_8 130 
 int TEST_PATTERN_DYN_RANGE_CEA ; 
 int TEST_PATTERN_DYN_RANGE_VESA ; 
 int TEST_PATTERN_MODE_COLORSQUARES_RGB ; 
 int TEST_PATTERN_MODE_DUALRAMP_RGB ; 
 int TEST_PATTERN_MODE_HORIZONTALBARS ; 
 int TEST_PATTERN_MODE_SINGLERAMP_RGB ; 
 int TEST_PATTERN_MODE_VERTICALBARS ; 
 scalar_t__ TIMING_3D_FORMAT_NONE ; 
#define  TRIGGER_DELAY_NEXT_LINE 129 
#define  TRIGGER_DELAY_NEXT_PIXEL 128 
 int TRIGGER_POLARITY_SELECT_LOGIC_ZERO ; 
 int TRIGGER_SOURCE_SELECT_GSL_GROUP0 ; 
 int TRIGGER_SOURCE_SELECT_LOGIC_ZERO ; 
 int VFLIP_READY_DELAY ; 
 TYPE_9__ dce110_tg_funcs ; 
 int dce110_timing_generator_is_counter_moving (struct timing_generator*) ; 
 int dm_read_reg (struct dc_context*,int) ; 
 int /*<<< orphan*/  dm_write_reg (struct dc_context*,int,int) ; 
 int get_reg_field_value (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct bp_hw_crtc_timing_parameters*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mmCRTC_BLACK_COLOR ; 
 int /*<<< orphan*/  mmCRTC_BLANK_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_BLANK_DATA_COLOR ; 
 int /*<<< orphan*/  mmCRTC_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_COUNT_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_CRC0_DATA_B ; 
 int /*<<< orphan*/  mmCRTC_CRC0_DATA_RG ; 
 int /*<<< orphan*/  mmCRTC_CRC0_WINDOWA_X_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_CRC0_WINDOWA_Y_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_CRC0_WINDOWB_X_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_CRC0_WINDOWB_Y_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_CRC_CNTL ; 
 int /*<<< orphan*/  mmCRTC_DOUBLE_BUFFER_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_FORCE_COUNT_NOW_CNTL ; 
 int /*<<< orphan*/  mmCRTC_GSL_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_GSL_WINDOW ; 
 int /*<<< orphan*/  mmCRTC_H_BLANK_START_END ; 
 int /*<<< orphan*/  mmCRTC_H_TOTAL ; 
 int /*<<< orphan*/  mmCRTC_MASTER_UPDATE_LOCK ; 
 int /*<<< orphan*/  mmCRTC_MASTER_UPDATE_MODE ; 
 int /*<<< orphan*/  mmCRTC_NOM_VERT_POSITION ; 
 int /*<<< orphan*/  mmCRTC_OVERSCAN_COLOR ; 
 int /*<<< orphan*/  mmCRTC_START_LINE_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_STATIC_SCREEN_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_STATUS ; 
 int /*<<< orphan*/  mmCRTC_STATUS_FRAME_COUNT ; 
 int /*<<< orphan*/  mmCRTC_STATUS_POSITION ; 
 int /*<<< orphan*/  mmCRTC_TEST_PATTERN_COLOR ; 
 int /*<<< orphan*/  mmCRTC_TEST_PATTERN_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_TEST_PATTERN_PARAMETERS ; 
 int /*<<< orphan*/  mmCRTC_TRIGB_CNTL ; 
 int /*<<< orphan*/  mmCRTC_VERTICAL_INTERRUPT0_POSITION ; 
 int /*<<< orphan*/  mmCRTC_VERT_SYNC_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_V_BLANK_START_END ; 
 int /*<<< orphan*/  mmCRTC_V_SYNC_A_CNTL ; 
 int /*<<< orphan*/  mmCRTC_V_TOTAL ; 
 int /*<<< orphan*/  mmCRTC_V_TOTAL_CONTROL ; 
 int /*<<< orphan*/  mmCRTC_V_TOTAL_MAX ; 
 int /*<<< orphan*/  mmCRTC_V_TOTAL_MIN ; 
 int mmD1VGA_CONTROL ; 
 int mmD2VGA_CONTROL ; 
 int mmD3VGA_CONTROL ; 
 int mmD4VGA_CONTROL ; 
 int mmD5VGA_CONTROL ; 
 int mmD6VGA_CONTROL ; 
 int /*<<< orphan*/  mmDCIO_GSL0_CNTL ; 
 int /*<<< orphan*/  mmDCP_GSL_CONTROL ; 
 int /*<<< orphan*/  set_reg_field_value (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub1 (TYPE_6__*,int,int) ; 
 int stub2 (TYPE_6__*,int,int) ; 
 int stub3 (TYPE_6__*,struct bp_hw_crtc_timing_parameters*) ; 
 int /*<<< orphan*/  stub4 (struct timing_generator*,int,struct dc_crtc_timing*) ; 
 int /*<<< orphan*/  stub5 (struct timing_generator*,struct crtc_position*) ; 
 int /*<<< orphan*/  stub6 (struct timing_generator*,struct crtc_position*) ; 
 int /*<<< orphan*/  stub7 (struct timing_generator*,int*,int*,int*,int*) ; 

__attribute__((used)) static void dce110_timing_generator_apply_front_porch_workaround(
	struct timing_generator *tg,
	struct dc_crtc_timing *timing)
{
	if (timing->flags.INTERLACE == 1) {
		if (timing->v_front_porch < 2)
			timing->v_front_porch = 2;
	} else {
		if (timing->v_front_porch < 1)
			timing->v_front_porch = 1;
	}
}

__attribute__((used)) static bool dce110_timing_generator_is_in_vertical_blank(
		struct timing_generator *tg)
{
	uint32_t addr = 0;
	uint32_t value = 0;
	uint32_t field = 0;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	addr = CRTC_REG(mmCRTC_STATUS);
	value = dm_read_reg(tg->ctx, addr);
	field = get_reg_field_value(value, CRTC_STATUS, CRTC_V_BLANK);
	return field == 1;
}

void dce110_timing_generator_set_early_control(
		struct timing_generator *tg,
		uint32_t early_cntl)
{
	uint32_t regval;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t address = CRTC_REG(mmCRTC_CONTROL);

	regval = dm_read_reg(tg->ctx, address);
	set_reg_field_value(regval, early_cntl,
			CRTC_CONTROL, CRTC_HBLANK_EARLY_CONTROL);
	dm_write_reg(tg->ctx, address, regval);
}

bool dce110_timing_generator_enable_crtc(struct timing_generator *tg)
{
	enum bp_result result;

	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t value = 0;

	/*
	 * 3 is used to make sure V_UPDATE occurs at the beginning of the first
	 * line of vertical front porch
	 */
	set_reg_field_value(
		value,
		0,
		CRTC_MASTER_UPDATE_MODE,
		MASTER_UPDATE_MODE);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_MASTER_UPDATE_MODE), value);

	/* TODO: may want this on to catch underflow */
	value = 0;
	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_MASTER_UPDATE_LOCK), value);

	result = tg->bp->funcs->enable_crtc(tg->bp, tg110->controller_id, true);

	return result == BP_RESULT_OK;
}

void dce110_timing_generator_program_blank_color(
		struct timing_generator *tg,
		const struct tg_color *black_color)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t addr = CRTC_REG(mmCRTC_BLACK_COLOR);
	uint32_t value = dm_read_reg(tg->ctx, addr);

	set_reg_field_value(
		value,
		black_color->color_b_cb,
		CRTC_BLACK_COLOR,
		CRTC_BLACK_COLOR_B_CB);
	set_reg_field_value(
		value,
		black_color->color_g_y,
		CRTC_BLACK_COLOR,
		CRTC_BLACK_COLOR_G_Y);
	set_reg_field_value(
		value,
		black_color->color_r_cr,
		CRTC_BLACK_COLOR,
		CRTC_BLACK_COLOR_R_CR);

	dm_write_reg(tg->ctx, addr, value);
}

bool dce110_timing_generator_disable_crtc(struct timing_generator *tg)
{
	enum bp_result result;

	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	result = tg->bp->funcs->enable_crtc(tg->bp, tg110->controller_id, false);

	/* Need to make sure stereo is disabled according to the DCE5.0 spec */

	/*
	 * @TODOSTEREO call this when adding stereo support
	 * tg->funcs->disable_stereo(tg);
	 */

	return result == BP_RESULT_OK;
}

__attribute__((used)) static void program_horz_count_by_2(
	struct timing_generator *tg,
	const struct dc_crtc_timing *timing)
{
	uint32_t regval;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	regval = dm_read_reg(tg->ctx,
			CRTC_REG(mmCRTC_COUNT_CONTROL));

	set_reg_field_value(regval, 0, CRTC_COUNT_CONTROL,
			CRTC_HORZ_COUNT_BY2_EN);

	if (timing->flags.HORZ_COUNT_BY_TWO)
		set_reg_field_value(regval, 1, CRTC_COUNT_CONTROL,
					CRTC_HORZ_COUNT_BY2_EN);

	dm_write_reg(tg->ctx,
			CRTC_REG(mmCRTC_COUNT_CONTROL), regval);
}

bool dce110_timing_generator_program_timing_generator(
	struct timing_generator *tg,
	const struct dc_crtc_timing *dc_crtc_timing)
{
	enum bp_result result;
	struct bp_hw_crtc_timing_parameters bp_params;
	struct dc_crtc_timing patched_crtc_timing;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	uint32_t vsync_offset = dc_crtc_timing->v_border_bottom +
			dc_crtc_timing->v_front_porch;
	uint32_t v_sync_start =dc_crtc_timing->v_addressable + vsync_offset;

	uint32_t hsync_offset = dc_crtc_timing->h_border_right +
			dc_crtc_timing->h_front_porch;
	uint32_t h_sync_start = dc_crtc_timing->h_addressable + hsync_offset;

	memset(&bp_params, 0, sizeof(struct bp_hw_crtc_timing_parameters));

	/* Due to an asic bug we need to apply the Front Porch workaround prior
	 * to programming the timing.
	 */

	patched_crtc_timing = *dc_crtc_timing;

	dce110_timing_generator_apply_front_porch_workaround(tg, &patched_crtc_timing);

	bp_params.controller_id = tg110->controller_id;

	bp_params.h_total = patched_crtc_timing.h_total;
	bp_params.h_addressable =
		patched_crtc_timing.h_addressable;
	bp_params.v_total = patched_crtc_timing.v_total;
	bp_params.v_addressable = patched_crtc_timing.v_addressable;

	bp_params.h_sync_start = h_sync_start;
	bp_params.h_sync_width = patched_crtc_timing.h_sync_width;
	bp_params.v_sync_start = v_sync_start;
	bp_params.v_sync_width = patched_crtc_timing.v_sync_width;

	/* Set overscan */
	bp_params.h_overscan_left =
		patched_crtc_timing.h_border_left;
	bp_params.h_overscan_right =
		patched_crtc_timing.h_border_right;
	bp_params.v_overscan_top = patched_crtc_timing.v_border_top;
	bp_params.v_overscan_bottom =
		patched_crtc_timing.v_border_bottom;

	/* Set flags */
	if (patched_crtc_timing.flags.HSYNC_POSITIVE_POLARITY == 1)
		bp_params.flags.HSYNC_POSITIVE_POLARITY = 1;

	if (patched_crtc_timing.flags.VSYNC_POSITIVE_POLARITY == 1)
		bp_params.flags.VSYNC_POSITIVE_POLARITY = 1;

	if (patched_crtc_timing.flags.INTERLACE == 1)
		bp_params.flags.INTERLACE = 1;

	if (patched_crtc_timing.flags.HORZ_COUNT_BY_TWO == 1)
		bp_params.flags.HORZ_COUNT_BY_TWO = 1;

	result = tg->bp->funcs->program_crtc_timing(tg->bp, &bp_params);

	program_horz_count_by_2(tg, &patched_crtc_timing);

	tg110->base.funcs->enable_advanced_request(tg, true, &patched_crtc_timing);

	/* Enable stereo - only when we need to pack 3D frame. Other types
	 * of stereo handled in explicit call */

	return result == BP_RESULT_OK;
}

void dce110_timing_generator_set_drr(
	struct timing_generator *tg,
	const struct drr_params *params)
{
	/* register values */
	uint32_t v_total_min = 0;
	uint32_t v_total_max = 0;
	uint32_t v_total_cntl = 0;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	uint32_t addr = 0;

	addr = CRTC_REG(mmCRTC_V_TOTAL_MIN);
	v_total_min = dm_read_reg(tg->ctx, addr);

	addr = CRTC_REG(mmCRTC_V_TOTAL_MAX);
	v_total_max = dm_read_reg(tg->ctx, addr);

	addr = CRTC_REG(mmCRTC_V_TOTAL_CONTROL);
	v_total_cntl = dm_read_reg(tg->ctx, addr);

	if (params != NULL &&
		params->vertical_total_max > 0 &&
		params->vertical_total_min > 0) {

		set_reg_field_value(v_total_max,
				params->vertical_total_max - 1,
				CRTC_V_TOTAL_MAX,
				CRTC_V_TOTAL_MAX);

		set_reg_field_value(v_total_min,
				params->vertical_total_min - 1,
				CRTC_V_TOTAL_MIN,
				CRTC_V_TOTAL_MIN);

		set_reg_field_value(v_total_cntl,
				1,
				CRTC_V_TOTAL_CONTROL,
				CRTC_V_TOTAL_MIN_SEL);

		set_reg_field_value(v_total_cntl,
				1,
				CRTC_V_TOTAL_CONTROL,
				CRTC_V_TOTAL_MAX_SEL);

		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_FORCE_LOCK_ON_EVENT);
		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_FORCE_LOCK_TO_MASTER_VSYNC);

		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_SET_V_TOTAL_MIN_MASK_EN);

		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_SET_V_TOTAL_MIN_MASK);
	} else {
		set_reg_field_value(v_total_cntl,
			0,
			CRTC_V_TOTAL_CONTROL,
			CRTC_SET_V_TOTAL_MIN_MASK);
		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_V_TOTAL_MIN_SEL);
		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_V_TOTAL_MAX_SEL);
		set_reg_field_value(v_total_min,
				0,
				CRTC_V_TOTAL_MIN,
				CRTC_V_TOTAL_MIN);
		set_reg_field_value(v_total_max,
				0,
				CRTC_V_TOTAL_MAX,
				CRTC_V_TOTAL_MAX);
		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_FORCE_LOCK_ON_EVENT);
		set_reg_field_value(v_total_cntl,
				0,
				CRTC_V_TOTAL_CONTROL,
				CRTC_FORCE_LOCK_TO_MASTER_VSYNC);
	}

	addr = CRTC_REG(mmCRTC_V_TOTAL_MIN);
	dm_write_reg(tg->ctx, addr, v_total_min);

	addr = CRTC_REG(mmCRTC_V_TOTAL_MAX);
	dm_write_reg(tg->ctx, addr, v_total_max);

	addr = CRTC_REG(mmCRTC_V_TOTAL_CONTROL);
	dm_write_reg(tg->ctx, addr, v_total_cntl);
}

void dce110_timing_generator_set_static_screen_control(
	struct timing_generator *tg,
	uint32_t value)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t static_screen_cntl = 0;
	uint32_t addr = 0;

	addr = CRTC_REG(mmCRTC_STATIC_SCREEN_CONTROL);
	static_screen_cntl = dm_read_reg(tg->ctx, addr);

	set_reg_field_value(static_screen_cntl,
				value,
				CRTC_STATIC_SCREEN_CONTROL,
				CRTC_STATIC_SCREEN_EVENT_MASK);

	set_reg_field_value(static_screen_cntl,
				2,
				CRTC_STATIC_SCREEN_CONTROL,
				CRTC_STATIC_SCREEN_FRAME_COUNT);

	dm_write_reg(tg->ctx, addr, static_screen_cntl);
}

uint32_t dce110_timing_generator_get_vblank_counter(struct timing_generator *tg)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t addr = CRTC_REG(mmCRTC_STATUS_FRAME_COUNT);
	uint32_t value = dm_read_reg(tg->ctx, addr);
	uint32_t field = get_reg_field_value(
			value, CRTC_STATUS_FRAME_COUNT, CRTC_FRAME_COUNT);

	return field;
}

void dce110_timing_generator_get_position(struct timing_generator *tg,
	struct crtc_position *position)
{
	uint32_t value;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_STATUS_POSITION));

	position->horizontal_count = get_reg_field_value(
			value,
			CRTC_STATUS_POSITION,
			CRTC_HORZ_COUNT);

	position->vertical_count = get_reg_field_value(
			value,
			CRTC_STATUS_POSITION,
			CRTC_VERT_COUNT);

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_NOM_VERT_POSITION));

	position->nominal_vcount = get_reg_field_value(
			value,
			CRTC_NOM_VERT_POSITION,
			CRTC_VERT_COUNT_NOM);
}

void dce110_timing_generator_get_crtc_scanoutpos(
	struct timing_generator *tg,
	uint32_t *v_blank_start,
	uint32_t *v_blank_end,
	uint32_t *h_position,
	uint32_t *v_position)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	struct crtc_position position;

	uint32_t value  = dm_read_reg(tg->ctx,
			CRTC_REG(mmCRTC_V_BLANK_START_END));

	*v_blank_start = get_reg_field_value(value,
					     CRTC_V_BLANK_START_END,
					     CRTC_V_BLANK_START);
	*v_blank_end = get_reg_field_value(value,
					   CRTC_V_BLANK_START_END,
					   CRTC_V_BLANK_END);

	dce110_timing_generator_get_position(
			tg, &position);

	*h_position = position.horizontal_count;
	*v_position = position.vertical_count;
}

void dce110_timing_generator_program_blanking(
	struct timing_generator *tg,
	const struct dc_crtc_timing *timing)
{
	uint32_t vsync_offset = timing->v_border_bottom +
			timing->v_front_porch;
	uint32_t v_sync_start =timing->v_addressable + vsync_offset;

	uint32_t hsync_offset = timing->h_border_right +
			timing->h_front_porch;
	uint32_t h_sync_start = timing->h_addressable + hsync_offset;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	struct dc_context *ctx = tg->ctx;
	uint32_t value = 0;
	uint32_t addr = 0;
	uint32_t tmp = 0;

	addr = CRTC_REG(mmCRTC_H_TOTAL);
	value = dm_read_reg(ctx, addr);
	set_reg_field_value(
		value,
		timing->h_total - 1,
		CRTC_H_TOTAL,
		CRTC_H_TOTAL);
	dm_write_reg(ctx, addr, value);

	addr = CRTC_REG(mmCRTC_V_TOTAL);
	value = dm_read_reg(ctx, addr);
	set_reg_field_value(
		value,
		timing->v_total - 1,
		CRTC_V_TOTAL,
		CRTC_V_TOTAL);
	dm_write_reg(ctx, addr, value);

	/* In case of V_TOTAL_CONTROL is on, make sure V_TOTAL_MAX and
	 * V_TOTAL_MIN are equal to V_TOTAL.
	 */
	addr = CRTC_REG(mmCRTC_V_TOTAL_MAX);
	value = dm_read_reg(ctx, addr);
	set_reg_field_value(
		value,
		timing->v_total - 1,
		CRTC_V_TOTAL_MAX,
		CRTC_V_TOTAL_MAX);
	dm_write_reg(ctx, addr, value);

	addr = CRTC_REG(mmCRTC_V_TOTAL_MIN);
	value = dm_read_reg(ctx, addr);
	set_reg_field_value(
		value,
		timing->v_total - 1,
		CRTC_V_TOTAL_MIN,
		CRTC_V_TOTAL_MIN);
	dm_write_reg(ctx, addr, value);

	addr = CRTC_REG(mmCRTC_H_BLANK_START_END);
	value = dm_read_reg(ctx, addr);

	tmp = timing->h_total -
		(h_sync_start + timing->h_border_left);

	set_reg_field_value(
		value,
		tmp,
		CRTC_H_BLANK_START_END,
		CRTC_H_BLANK_END);

	tmp = tmp + timing->h_addressable +
		timing->h_border_left + timing->h_border_right;

	set_reg_field_value(
		value,
		tmp,
		CRTC_H_BLANK_START_END,
		CRTC_H_BLANK_START);

	dm_write_reg(ctx, addr, value);

	addr = CRTC_REG(mmCRTC_V_BLANK_START_END);
	value = dm_read_reg(ctx, addr);

	tmp = timing->v_total - (v_sync_start + timing->v_border_top);

	set_reg_field_value(
		value,
		tmp,
		CRTC_V_BLANK_START_END,
		CRTC_V_BLANK_END);

	tmp = tmp + timing->v_addressable + timing->v_border_top +
		timing->v_border_bottom;

	set_reg_field_value(
		value,
		tmp,
		CRTC_V_BLANK_START_END,
		CRTC_V_BLANK_START);

	dm_write_reg(ctx, addr, value);
}

void dce110_timing_generator_set_test_pattern(
	struct timing_generator *tg,
	/* TODO: replace 'controller_dp_test_pattern' by 'test_pattern_mode'
	 * because this is not DP-specific (which is probably somewhere in DP
	 * encoder) */
	enum controller_dp_test_pattern test_pattern,
	enum dc_color_depth color_depth)
{
	struct dc_context *ctx = tg->ctx;
	uint32_t value;
	uint32_t addr;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	enum test_pattern_color_format bit_depth;
	enum test_pattern_dyn_range dyn_range;
	enum test_pattern_mode mode;
	/* color ramp generator mixes 16-bits color */
	uint32_t src_bpc = 16;
	/* requested bpc */
	uint32_t dst_bpc;
	uint32_t index;
	/* RGB values of the color bars.
	 * Produce two RGB colors: RGB0 - white (all Fs)
	 * and RGB1 - black (all 0s)
	 * (three RGB components for two colors)
	 */
	uint16_t src_color[6] = {0xFFFF, 0xFFFF, 0xFFFF, 0x0000,
						0x0000, 0x0000};
	/* dest color (converted to the specified color format) */
	uint16_t dst_color[6];
	uint32_t inc_base;

	/* translate to bit depth */
	switch (color_depth) {
	case COLOR_DEPTH_666:
		bit_depth = TEST_PATTERN_COLOR_FORMAT_BPC_6;
	break;
	case COLOR_DEPTH_888:
		bit_depth = TEST_PATTERN_COLOR_FORMAT_BPC_8;
	break;
	case COLOR_DEPTH_101010:
		bit_depth = TEST_PATTERN_COLOR_FORMAT_BPC_10;
	break;
	case COLOR_DEPTH_121212:
		bit_depth = TEST_PATTERN_COLOR_FORMAT_BPC_12;
	break;
	default:
		bit_depth = TEST_PATTERN_COLOR_FORMAT_BPC_8;
	break;
	}

	switch (test_pattern) {
	case CONTROLLER_DP_TEST_PATTERN_COLORSQUARES:
	case CONTROLLER_DP_TEST_PATTERN_COLORSQUARES_CEA:
	{
		dyn_range = (test_pattern ==
				CONTROLLER_DP_TEST_PATTERN_COLORSQUARES_CEA ?
				TEST_PATTERN_DYN_RANGE_CEA :
				TEST_PATTERN_DYN_RANGE_VESA);
		mode = TEST_PATTERN_MODE_COLORSQUARES_RGB;
		value = 0;
		addr = CRTC_REG(mmCRTC_TEST_PATTERN_PARAMETERS);

		set_reg_field_value(
			value,
			6,
			CRTC_TEST_PATTERN_PARAMETERS,
			CRTC_TEST_PATTERN_VRES);
		set_reg_field_value(
			value,
			6,
			CRTC_TEST_PATTERN_PARAMETERS,
			CRTC_TEST_PATTERN_HRES);

		dm_write_reg(ctx, addr, value);

		addr = CRTC_REG(mmCRTC_TEST_PATTERN_CONTROL);
		value = 0;

		set_reg_field_value(
			value,
			1,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_EN);

		set_reg_field_value(
			value,
			mode,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_MODE);

		set_reg_field_value(
			value,
			dyn_range,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_DYNAMIC_RANGE);
		set_reg_field_value(
			value,
			bit_depth,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_COLOR_FORMAT);
		dm_write_reg(ctx, addr, value);
	}
	break;

	case CONTROLLER_DP_TEST_PATTERN_VERTICALBARS:
	case CONTROLLER_DP_TEST_PATTERN_HORIZONTALBARS:
	{
		mode = (test_pattern ==
			CONTROLLER_DP_TEST_PATTERN_VERTICALBARS ?
			TEST_PATTERN_MODE_VERTICALBARS :
			TEST_PATTERN_MODE_HORIZONTALBARS);

		switch (bit_depth) {
		case TEST_PATTERN_COLOR_FORMAT_BPC_6:
			dst_bpc = 6;
		break;
		case TEST_PATTERN_COLOR_FORMAT_BPC_8:
			dst_bpc = 8;
		break;
		case TEST_PATTERN_COLOR_FORMAT_BPC_10:
			dst_bpc = 10;
		break;
		default:
			dst_bpc = 8;
		break;
		}

		/* adjust color to the required colorFormat */
		for (index = 0; index < 6; index++) {
			/* dst = 2^dstBpc * src / 2^srcBpc = src >>
			 * (srcBpc - dstBpc);
			 */
			dst_color[index] =
				src_color[index] >> (src_bpc - dst_bpc);
		/* CRTC_TEST_PATTERN_DATA has 16 bits,
		 * lowest 6 are hardwired to ZERO
		 * color bits should be left aligned aligned to MSB
		 * XXXXXXXXXX000000 for 10 bit,
		 * XXXXXXXX00000000 for 8 bit and XXXXXX0000000000 for 6
		 */
			dst_color[index] <<= (16 - dst_bpc);
		}

		value = 0;
		addr = CRTC_REG(mmCRTC_TEST_PATTERN_PARAMETERS);
		dm_write_reg(ctx, addr, value);

		/* We have to write the mask before data, similar to pipeline.
		 * For example, for 8 bpc, if we want RGB0 to be magenta,
		 * and RGB1 to be cyan,
		 * we need to make 7 writes:
		 * MASK   DATA
		 * 000001 00000000 00000000                     set mask to R0
		 * 000010 11111111 00000000     R0 255, 0xFF00, set mask to G0
		 * 000100 00000000 00000000     G0 0,   0x0000, set mask to B0
		 * 001000 11111111 00000000     B0 255, 0xFF00, set mask to R1
		 * 010000 00000000 00000000     R1 0,   0x0000, set mask to G1
		 * 100000 11111111 00000000     G1 255, 0xFF00, set mask to B1
		 * 100000 11111111 00000000     B1 255, 0xFF00
		 *
		 * we will make a loop of 6 in which we prepare the mask,
		 * then write, then prepare the color for next write.
		 * first iteration will write mask only,
		 * but each next iteration color prepared in
		 * previous iteration will be written within new mask,
		 * the last component will written separately,
		 * mask is not changing between 6th and 7th write
		 * and color will be prepared by last iteration
		 */

		/* write color, color values mask in CRTC_TEST_PATTERN_MASK
		 * is B1, G1, R1, B0, G0, R0
		 */
		value = 0;
		addr = CRTC_REG(mmCRTC_TEST_PATTERN_COLOR);
		for (index = 0; index < 6; index++) {
			/* prepare color mask, first write PATTERN_DATA
			 * will have all zeros
			 */
			set_reg_field_value(
				value,
				(1 << index),
				CRTC_TEST_PATTERN_COLOR,
				CRTC_TEST_PATTERN_MASK);
			/* write color component */
			dm_write_reg(ctx, addr, value);
			/* prepare next color component,
			 * will be written in the next iteration
			 */
			set_reg_field_value(
				value,
				dst_color[index],
				CRTC_TEST_PATTERN_COLOR,
				CRTC_TEST_PATTERN_DATA);
		}
		/* write last color component,
		 * it's been already prepared in the loop
		 */
		dm_write_reg(ctx, addr, value);

		/* enable test pattern */
		addr = CRTC_REG(mmCRTC_TEST_PATTERN_CONTROL);
		value = 0;

		set_reg_field_value(
			value,
			1,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_EN);

		set_reg_field_value(
			value,
			mode,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_MODE);

		set_reg_field_value(
			value,
			0,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_DYNAMIC_RANGE);

		set_reg_field_value(
			value,
			bit_depth,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_COLOR_FORMAT);

		dm_write_reg(ctx, addr, value);
	}
	break;

	case CONTROLLER_DP_TEST_PATTERN_COLORRAMP:
	{
		mode = (bit_depth ==
			TEST_PATTERN_COLOR_FORMAT_BPC_10 ?
			TEST_PATTERN_MODE_DUALRAMP_RGB :
			TEST_PATTERN_MODE_SINGLERAMP_RGB);

		switch (bit_depth) {
		case TEST_PATTERN_COLOR_FORMAT_BPC_6:
			dst_bpc = 6;
		break;
		case TEST_PATTERN_COLOR_FORMAT_BPC_8:
			dst_bpc = 8;
		break;
		case TEST_PATTERN_COLOR_FORMAT_BPC_10:
			dst_bpc = 10;
		break;
		default:
			dst_bpc = 8;
		break;
		}

		/* increment for the first ramp for one color gradation
		 * 1 gradation for 6-bit color is 2^10
		 * gradations in 16-bit color
		 */
		inc_base = (src_bpc - dst_bpc);

		value = 0;
		addr = CRTC_REG(mmCRTC_TEST_PATTERN_PARAMETERS);

		switch (bit_depth) {
		case TEST_PATTERN_COLOR_FORMAT_BPC_6:
		{
			set_reg_field_value(
				value,
				inc_base,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_INC0);
			set_reg_field_value(
				value,
				0,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_INC1);
			set_reg_field_value(
				value,
				6,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_HRES);
			set_reg_field_value(
				value,
				6,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_VRES);
			set_reg_field_value(
				value,
				0,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_RAMP0_OFFSET);
		}
		break;
		case TEST_PATTERN_COLOR_FORMAT_BPC_8:
		{
			set_reg_field_value(
				value,
				inc_base,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_INC0);
			set_reg_field_value(
				value,
				0,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_INC1);
			set_reg_field_value(
				value,
				8,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_HRES);
			set_reg_field_value(
				value,
				6,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_VRES);
			set_reg_field_value(
				value,
				0,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_RAMP0_OFFSET);
		}
		break;
		case TEST_PATTERN_COLOR_FORMAT_BPC_10:
		{
			set_reg_field_value(
				value,
				inc_base,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_INC0);
			set_reg_field_value(
				value,
				inc_base + 2,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_INC1);
			set_reg_field_value(
				value,
				8,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_HRES);
			set_reg_field_value(
				value,
				5,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_VRES);
			set_reg_field_value(
				value,
				384 << 6,
				CRTC_TEST_PATTERN_PARAMETERS,
				CRTC_TEST_PATTERN_RAMP0_OFFSET);
		}
		break;
		default:
		break;
		}
		dm_write_reg(ctx, addr, value);

		value = 0;
		addr = CRTC_REG(mmCRTC_TEST_PATTERN_COLOR);
		dm_write_reg(ctx, addr, value);

		/* enable test pattern */
		addr = CRTC_REG(mmCRTC_TEST_PATTERN_CONTROL);
		value = 0;

		set_reg_field_value(
			value,
			1,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_EN);

		set_reg_field_value(
			value,
			mode,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_MODE);

		set_reg_field_value(
			value,
			0,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_DYNAMIC_RANGE);
		/* add color depth translation here */
		set_reg_field_value(
			value,
			bit_depth,
			CRTC_TEST_PATTERN_CONTROL,
			CRTC_TEST_PATTERN_COLOR_FORMAT);

		dm_write_reg(ctx, addr, value);
	}
	break;
	case CONTROLLER_DP_TEST_PATTERN_VIDEOMODE:
	{
		value = 0;
		dm_write_reg(ctx, CRTC_REG(mmCRTC_TEST_PATTERN_CONTROL), value);
		dm_write_reg(ctx, CRTC_REG(mmCRTC_TEST_PATTERN_COLOR), value);
		dm_write_reg(ctx, CRTC_REG(mmCRTC_TEST_PATTERN_PARAMETERS),
				value);
	}
	break;
	default:
	break;
	}
}

bool dce110_timing_generator_validate_timing(
	struct timing_generator *tg,
	const struct dc_crtc_timing *timing,
	enum signal_type signal)
{
	uint32_t h_blank;
	uint32_t h_back_porch, hsync_offset, h_sync_start;

	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	ASSERT(timing != NULL);

	if (!timing)
		return false;

	hsync_offset = timing->h_border_right + timing->h_front_porch;
	h_sync_start = timing->h_addressable + hsync_offset;

	/* Currently we don't support 3D, so block all 3D timings */
	if (timing->timing_3d_format != TIMING_3D_FORMAT_NONE)
		return false;

	/* Temporarily blocking interlacing mode until it's supported */
	if (timing->flags.INTERLACE == 1)
		return false;

	/* Check maximum number of pixels supported by Timing Generator
	 * (Currently will never fail, in order to fail needs display which
	 * needs more than 8192 horizontal and
	 * more than 8192 vertical total pixels)
	 */
	if (timing->h_total > tg110->max_h_total ||
		timing->v_total > tg110->max_v_total)
		return false;

	h_blank = (timing->h_total - timing->h_addressable -
		timing->h_border_right -
		timing->h_border_left);

	if (h_blank < tg110->min_h_blank)
		return false;

	if (timing->h_front_porch < tg110->min_h_front_porch)
		return false;

	h_back_porch = h_blank - (h_sync_start -
		timing->h_addressable -
		timing->h_border_right -
		timing->h_sync_width);

	if (h_back_porch < tg110->min_h_back_porch)
		return false;

	return true;
}

void dce110_timing_generator_wait_for_vblank(struct timing_generator *tg)
{
	/* We want to catch beginning of VBlank here, so if the first try are
	 * in VBlank, we might be very close to Active, in this case wait for
	 * another frame
	 */
	while (dce110_timing_generator_is_in_vertical_blank(tg)) {
		if (!dce110_timing_generator_is_counter_moving(tg)) {
			/* error - no point to wait if counter is not moving */
			break;
		}
	}

	while (!dce110_timing_generator_is_in_vertical_blank(tg)) {
		if (!dce110_timing_generator_is_counter_moving(tg)) {
			/* error - no point to wait if counter is not moving */
			break;
		}
	}
}

void dce110_timing_generator_wait_for_vactive(struct timing_generator *tg)
{
	while (dce110_timing_generator_is_in_vertical_blank(tg)) {
		if (!dce110_timing_generator_is_counter_moving(tg)) {
			/* error - no point to wait if counter is not moving */
			break;
		}
	}
}

void dce110_timing_generator_setup_global_swap_lock(
	struct timing_generator *tg,
	const struct dcp_gsl_params *gsl_params)
{
	uint32_t value;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t address = DCP_REG(mmDCP_GSL_CONTROL);
	uint32_t check_point = FLIP_READY_BACK_LOOKUP;

	value = dm_read_reg(tg->ctx, address);

	/* This pipe will belong to GSL Group zero. */
	set_reg_field_value(value,
			    1,
			    DCP_GSL_CONTROL,
			    DCP_GSL0_EN);

	set_reg_field_value(value,
			    gsl_params->gsl_master == tg->inst,
			    DCP_GSL_CONTROL,
			    DCP_GSL_MASTER_EN);

	set_reg_field_value(value,
			    HFLIP_READY_DELAY,
			    DCP_GSL_CONTROL,
			    DCP_GSL_HSYNC_FLIP_FORCE_DELAY);

	/* Keep signal low (pending high) during 6 lines.
	 * Also defines minimum interval before re-checking signal. */
	set_reg_field_value(value,
			    HFLIP_CHECK_DELAY,
			    DCP_GSL_CONTROL,
			    DCP_GSL_HSYNC_FLIP_CHECK_DELAY);

	dm_write_reg(tg->ctx, CRTC_REG(mmDCP_GSL_CONTROL), value);
	value = 0;

	set_reg_field_value(value,
			    gsl_params->gsl_master,
			    DCIO_GSL0_CNTL,
			    DCIO_GSL0_VSYNC_SEL);

	set_reg_field_value(value,
			    0,
			    DCIO_GSL0_CNTL,
			    DCIO_GSL0_TIMING_SYNC_SEL);

	set_reg_field_value(value,
			    0,
			    DCIO_GSL0_CNTL,
			    DCIO_GSL0_GLOBAL_UNLOCK_SEL);

	dm_write_reg(tg->ctx, CRTC_REG(mmDCIO_GSL0_CNTL), value);


	{
		uint32_t value_crtc_vtotal;

		value_crtc_vtotal = dm_read_reg(tg->ctx,
				CRTC_REG(mmCRTC_V_TOTAL));

		set_reg_field_value(value,
				    0,/* DCP_GSL_PURPOSE_SURFACE_FLIP */
				    DCP_GSL_CONTROL,
				    DCP_GSL_SYNC_SOURCE);

		/* Checkpoint relative to end of frame */
		check_point = get_reg_field_value(value_crtc_vtotal,
						  CRTC_V_TOTAL,
						  CRTC_V_TOTAL);

		dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_GSL_WINDOW), 0);
	}

	set_reg_field_value(value,
			    1,
			    DCP_GSL_CONTROL,
			    DCP_GSL_DELAY_SURFACE_UPDATE_PENDING);

	dm_write_reg(tg->ctx, address, value);

	/********************************************************************/
	address = CRTC_REG(mmCRTC_GSL_CONTROL);

	value = dm_read_reg(tg->ctx, address);
	set_reg_field_value(value,
			    check_point - FLIP_READY_BACK_LOOKUP,
			    CRTC_GSL_CONTROL,
			    CRTC_GSL_CHECK_LINE_NUM);

	set_reg_field_value(value,
			    VFLIP_READY_DELAY,
			    CRTC_GSL_CONTROL,
			    CRTC_GSL_FORCE_DELAY);

	dm_write_reg(tg->ctx, address, value);
}

void dce110_timing_generator_tear_down_global_swap_lock(
	struct timing_generator *tg)
{
	/* Clear all the register writes done by
	 * dce110_timing_generator_setup_global_swap_lock
	 */

	uint32_t value;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t address = DCP_REG(mmDCP_GSL_CONTROL);

	value = 0;

	/* This pipe will belong to GSL Group zero. */
	/* Settig HW default values from reg specs */
	set_reg_field_value(value,
			0,
			DCP_GSL_CONTROL,
			DCP_GSL0_EN);

	set_reg_field_value(value,
			0,
			DCP_GSL_CONTROL,
			DCP_GSL_MASTER_EN);

	set_reg_field_value(value,
			0x2,
			DCP_GSL_CONTROL,
			DCP_GSL_HSYNC_FLIP_FORCE_DELAY);

	set_reg_field_value(value,
			0x6,
			DCP_GSL_CONTROL,
			DCP_GSL_HSYNC_FLIP_CHECK_DELAY);

	/* Restore DCP_GSL_PURPOSE_SURFACE_FLIP */
	{
		uint32_t value_crtc_vtotal;

		value_crtc_vtotal = dm_read_reg(tg->ctx,
				CRTC_REG(mmCRTC_V_TOTAL));

		set_reg_field_value(value,
				0,
				DCP_GSL_CONTROL,
				DCP_GSL_SYNC_SOURCE);
	}

	set_reg_field_value(value,
			0,
			DCP_GSL_CONTROL,
			DCP_GSL_DELAY_SURFACE_UPDATE_PENDING);

	dm_write_reg(tg->ctx, address, value);

	/********************************************************************/
	address = CRTC_REG(mmCRTC_GSL_CONTROL);

	value = 0;
	set_reg_field_value(value,
			0,
			CRTC_GSL_CONTROL,
			CRTC_GSL_CHECK_LINE_NUM);

	set_reg_field_value(value,
			0x2,
			CRTC_GSL_CONTROL,
			CRTC_GSL_FORCE_DELAY);

	dm_write_reg(tg->ctx, address, value);
}

bool dce110_timing_generator_is_counter_moving(struct timing_generator *tg)
{
	struct crtc_position position1, position2;

	tg->funcs->get_position(tg, &position1);
	tg->funcs->get_position(tg, &position2);

	if (position1.horizontal_count == position2.horizontal_count &&
		position1.vertical_count == position2.vertical_count)
		return false;
	else
		return true;
}

void dce110_timing_generator_enable_advanced_request(
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

void dce110_timing_generator_set_lock_master(struct timing_generator *tg,
		bool lock)
{
	struct dc_context *ctx = tg->ctx;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t addr = CRTC_REG(mmCRTC_MASTER_UPDATE_LOCK);
	uint32_t value = dm_read_reg(ctx, addr);

	set_reg_field_value(
		value,
		lock ? 1 : 0,
		CRTC_MASTER_UPDATE_LOCK,
		MASTER_UPDATE_LOCK);

	dm_write_reg(ctx, addr, value);
}

void dce110_timing_generator_enable_reset_trigger(
	struct timing_generator *tg,
	int source_tg_inst)
{
	uint32_t value;
	uint32_t rising_edge = 0;
	uint32_t falling_edge = 0;
	enum trigger_source_select trig_src_select = TRIGGER_SOURCE_SELECT_LOGIC_ZERO;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	/* Setup trigger edge */
	{
		uint32_t pol_value = dm_read_reg(tg->ctx,
				CRTC_REG(mmCRTC_V_SYNC_A_CNTL));

		/* Register spec has reversed definition:
		 *	0 for positive, 1 for negative */
		if (get_reg_field_value(pol_value,
				CRTC_V_SYNC_A_CNTL,
				CRTC_V_SYNC_A_POL) == 0) {
			rising_edge = 1;
		} else {
			falling_edge = 1;
		}
	}

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_TRIGB_CNTL));

	trig_src_select = TRIGGER_SOURCE_SELECT_GSL_GROUP0;

	set_reg_field_value(value,
			trig_src_select,
			CRTC_TRIGB_CNTL,
			CRTC_TRIGB_SOURCE_SELECT);

	set_reg_field_value(value,
			TRIGGER_POLARITY_SELECT_LOGIC_ZERO,
			CRTC_TRIGB_CNTL,
			CRTC_TRIGB_POLARITY_SELECT);

	set_reg_field_value(value,
			rising_edge,
			CRTC_TRIGB_CNTL,
			CRTC_TRIGB_RISING_EDGE_DETECT_CNTL);

	set_reg_field_value(value,
			falling_edge,
			CRTC_TRIGB_CNTL,
			CRTC_TRIGB_FALLING_EDGE_DETECT_CNTL);

	set_reg_field_value(value,
			0, /* send every signal */
			CRTC_TRIGB_CNTL,
			CRTC_TRIGB_FREQUENCY_SELECT);

	set_reg_field_value(value,
			0, /* no delay */
			CRTC_TRIGB_CNTL,
			CRTC_TRIGB_DELAY);

	set_reg_field_value(value,
			1, /* clear trigger status */
			CRTC_TRIGB_CNTL,
			CRTC_TRIGB_CLEAR);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_TRIGB_CNTL), value);

	/**************************************************************/

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL));

	set_reg_field_value(value,
			2, /* force H count to H_TOTAL and V count to V_TOTAL */
			CRTC_FORCE_COUNT_NOW_CNTL,
			CRTC_FORCE_COUNT_NOW_MODE);

	set_reg_field_value(value,
			1, /* TriggerB - we never use TriggerA */
			CRTC_FORCE_COUNT_NOW_CNTL,
			CRTC_FORCE_COUNT_NOW_TRIG_SEL);

	set_reg_field_value(value,
			1, /* clear trigger status */
			CRTC_FORCE_COUNT_NOW_CNTL,
			CRTC_FORCE_COUNT_NOW_CLEAR);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL), value);
}

void dce110_timing_generator_enable_crtc_reset(
		struct timing_generator *tg,
		int source_tg_inst,
		struct crtc_trigger_info *crtc_tp)
{
	uint32_t value = 0;
	uint32_t rising_edge = 0;
	uint32_t falling_edge = 0;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	/* Setup trigger edge */
	switch (crtc_tp->event) {
	case CRTC_EVENT_VSYNC_RISING:
			rising_edge = 1;
			break;

	case CRTC_EVENT_VSYNC_FALLING:
		falling_edge = 1;
		break;
	}

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_TRIGB_CNTL));

	set_reg_field_value(value,
			    source_tg_inst,
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_SOURCE_SELECT);

	set_reg_field_value(value,
			    TRIGGER_POLARITY_SELECT_LOGIC_ZERO,
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_POLARITY_SELECT);

	set_reg_field_value(value,
			    rising_edge,
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_RISING_EDGE_DETECT_CNTL);

	set_reg_field_value(value,
			    falling_edge,
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_FALLING_EDGE_DETECT_CNTL);

	set_reg_field_value(value,
			    1, /* clear trigger status */
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_CLEAR);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_TRIGB_CNTL), value);

	/**************************************************************/

	switch (crtc_tp->delay) {
	case TRIGGER_DELAY_NEXT_LINE:
		value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL));

		set_reg_field_value(value,
				    0, /* force H count to H_TOTAL and V count to V_TOTAL */
				    CRTC_FORCE_COUNT_NOW_CNTL,
				    CRTC_FORCE_COUNT_NOW_MODE);

		set_reg_field_value(value,
				    0, /* TriggerB - we never use TriggerA */
				    CRTC_FORCE_COUNT_NOW_CNTL,
				    CRTC_FORCE_COUNT_NOW_TRIG_SEL);

		set_reg_field_value(value,
				    1, /* clear trigger status */
				    CRTC_FORCE_COUNT_NOW_CNTL,
				    CRTC_FORCE_COUNT_NOW_CLEAR);

		dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL), value);

		value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_VERT_SYNC_CONTROL));

		set_reg_field_value(value,
				    1,
				    CRTC_VERT_SYNC_CONTROL,
				    CRTC_FORCE_VSYNC_NEXT_LINE_CLEAR);

		set_reg_field_value(value,
				    2,
				    CRTC_VERT_SYNC_CONTROL,
				    CRTC_AUTO_FORCE_VSYNC_MODE);

		break;

	case TRIGGER_DELAY_NEXT_PIXEL:
		value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_VERT_SYNC_CONTROL));

		set_reg_field_value(value,
				    1,
				    CRTC_VERT_SYNC_CONTROL,
				    CRTC_FORCE_VSYNC_NEXT_LINE_CLEAR);

		set_reg_field_value(value,
				    0,
				    CRTC_VERT_SYNC_CONTROL,
				    CRTC_AUTO_FORCE_VSYNC_MODE);

		dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_VERT_SYNC_CONTROL), value);

		value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL));

		set_reg_field_value(value,
				    2, /* force H count to H_TOTAL and V count to V_TOTAL */
				    CRTC_FORCE_COUNT_NOW_CNTL,
				    CRTC_FORCE_COUNT_NOW_MODE);

		set_reg_field_value(value,
				    1, /* TriggerB - we never use TriggerA */
				    CRTC_FORCE_COUNT_NOW_CNTL,
				    CRTC_FORCE_COUNT_NOW_TRIG_SEL);

		set_reg_field_value(value,
				    1, /* clear trigger status */
				    CRTC_FORCE_COUNT_NOW_CNTL,
				    CRTC_FORCE_COUNT_NOW_CLEAR);

		dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL), value);
		break;
	}

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_MASTER_UPDATE_MODE));

	set_reg_field_value(value,
			    2,
			    CRTC_MASTER_UPDATE_MODE,
			    MASTER_UPDATE_MODE);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_MASTER_UPDATE_MODE), value);
}

void dce110_timing_generator_disable_reset_trigger(
	struct timing_generator *tg)
{
	uint32_t value;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL));

	set_reg_field_value(value,
			    0, /* force counter now mode is disabled */
			    CRTC_FORCE_COUNT_NOW_CNTL,
			    CRTC_FORCE_COUNT_NOW_MODE);

	set_reg_field_value(value,
			    1, /* clear trigger status */
			    CRTC_FORCE_COUNT_NOW_CNTL,
			    CRTC_FORCE_COUNT_NOW_CLEAR);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL), value);

	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_VERT_SYNC_CONTROL));

	set_reg_field_value(value,
			    1,
			    CRTC_VERT_SYNC_CONTROL,
			    CRTC_FORCE_VSYNC_NEXT_LINE_CLEAR);

	set_reg_field_value(value,
			    0,
			    CRTC_VERT_SYNC_CONTROL,
			    CRTC_AUTO_FORCE_VSYNC_MODE);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_VERT_SYNC_CONTROL), value);

	/********************************************************************/
	value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_TRIGB_CNTL));

	set_reg_field_value(value,
			    TRIGGER_SOURCE_SELECT_LOGIC_ZERO,
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_SOURCE_SELECT);

	set_reg_field_value(value,
			    TRIGGER_POLARITY_SELECT_LOGIC_ZERO,
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_POLARITY_SELECT);

	set_reg_field_value(value,
			    1, /* clear trigger status */
			    CRTC_TRIGB_CNTL,
			    CRTC_TRIGB_CLEAR);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_TRIGB_CNTL), value);
}

bool dce110_timing_generator_did_triggered_reset_occur(
	struct timing_generator *tg)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t value = dm_read_reg(tg->ctx,
			CRTC_REG(mmCRTC_FORCE_COUNT_NOW_CNTL));
	uint32_t value1 = dm_read_reg(tg->ctx,
			CRTC_REG(mmCRTC_VERT_SYNC_CONTROL));
	bool force = get_reg_field_value(value,
					 CRTC_FORCE_COUNT_NOW_CNTL,
					 CRTC_FORCE_COUNT_NOW_OCCURRED) != 0;
	bool vert_sync = get_reg_field_value(value1,
					     CRTC_VERT_SYNC_CONTROL,
					     CRTC_FORCE_VSYNC_NEXT_LINE_OCCURRED) != 0;

	return (force || vert_sync);
}

void dce110_timing_generator_disable_vga(
	struct timing_generator *tg)
{
	uint32_t addr = 0;
	uint32_t value = 0;

	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	switch (tg110->controller_id) {
	case CONTROLLER_ID_D0:
		addr = mmD1VGA_CONTROL;
		break;
	case CONTROLLER_ID_D1:
		addr = mmD2VGA_CONTROL;
		break;
	case CONTROLLER_ID_D2:
		addr = mmD3VGA_CONTROL;
		break;
	case CONTROLLER_ID_D3:
		addr = mmD4VGA_CONTROL;
		break;
	case CONTROLLER_ID_D4:
		addr = mmD5VGA_CONTROL;
		break;
	case CONTROLLER_ID_D5:
		addr = mmD6VGA_CONTROL;
		break;
	default:
		break;
	}
	value = dm_read_reg(tg->ctx, addr);

	set_reg_field_value(value, 0, D1VGA_CONTROL, D1VGA_MODE_ENABLE);
	set_reg_field_value(value, 0, D1VGA_CONTROL, D1VGA_TIMING_SELECT);
	set_reg_field_value(
			value, 0, D1VGA_CONTROL, D1VGA_SYNC_POLARITY_SELECT);
	set_reg_field_value(value, 0, D1VGA_CONTROL, D1VGA_OVERSCAN_COLOR_EN);

	dm_write_reg(tg->ctx, addr, value);
}

void dce110_timing_generator_set_overscan_color_black(
	struct timing_generator *tg,
	const struct tg_color *color)
{
	struct dc_context *ctx = tg->ctx;
	uint32_t addr;
	uint32_t value = 0;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	set_reg_field_value(
			value,
			color->color_b_cb,
			CRTC_OVERSCAN_COLOR,
			CRTC_OVERSCAN_COLOR_BLUE);

	set_reg_field_value(
			value,
			color->color_r_cr,
			CRTC_OVERSCAN_COLOR,
			CRTC_OVERSCAN_COLOR_RED);

	set_reg_field_value(
			value,
			color->color_g_y,
			CRTC_OVERSCAN_COLOR,
			CRTC_OVERSCAN_COLOR_GREEN);

	addr = CRTC_REG(mmCRTC_OVERSCAN_COLOR);
	dm_write_reg(ctx, addr, value);
	addr = CRTC_REG(mmCRTC_BLACK_COLOR);
	dm_write_reg(ctx, addr, value);
	/* This is desirable to have a constant DAC output voltage during the
	 * blank time that is higher than the 0 volt reference level that the
	 * DAC outputs when the NBLANK signal
	 * is asserted low, such as for output to an analog TV. */
	addr = CRTC_REG(mmCRTC_BLANK_DATA_COLOR);
	dm_write_reg(ctx, addr, value);

	/* TO DO we have to program EXT registers and we need to know LB DATA
	 * format because it is used when more 10 , i.e. 12 bits per color
	 *
	 * m_mmDxCRTC_OVERSCAN_COLOR_EXT
	 * m_mmDxCRTC_BLACK_COLOR_EXT
	 * m_mmDxCRTC_BLANK_DATA_COLOR_EXT
	 */

}

void dce110_tg_program_blank_color(struct timing_generator *tg,
		const struct tg_color *black_color)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t addr = CRTC_REG(mmCRTC_BLACK_COLOR);
	uint32_t value = dm_read_reg(tg->ctx, addr);

	set_reg_field_value(
		value,
		black_color->color_b_cb,
		CRTC_BLACK_COLOR,
		CRTC_BLACK_COLOR_B_CB);
	set_reg_field_value(
		value,
		black_color->color_g_y,
		CRTC_BLACK_COLOR,
		CRTC_BLACK_COLOR_G_Y);
	set_reg_field_value(
		value,
		black_color->color_r_cr,
		CRTC_BLACK_COLOR,
		CRTC_BLACK_COLOR_R_CR);

	dm_write_reg(tg->ctx, addr, value);

	addr = CRTC_REG(mmCRTC_BLANK_DATA_COLOR);
	dm_write_reg(tg->ctx, addr, value);
}

void dce110_tg_set_overscan_color(struct timing_generator *tg,
	const struct tg_color *overscan_color)
{
	struct dc_context *ctx = tg->ctx;
	uint32_t value = 0;
	uint32_t addr;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	set_reg_field_value(
		value,
		overscan_color->color_b_cb,
		CRTC_OVERSCAN_COLOR,
		CRTC_OVERSCAN_COLOR_BLUE);

	set_reg_field_value(
		value,
		overscan_color->color_g_y,
		CRTC_OVERSCAN_COLOR,
		CRTC_OVERSCAN_COLOR_GREEN);

	set_reg_field_value(
		value,
		overscan_color->color_r_cr,
		CRTC_OVERSCAN_COLOR,
		CRTC_OVERSCAN_COLOR_RED);

	addr = CRTC_REG(mmCRTC_OVERSCAN_COLOR);
	dm_write_reg(ctx, addr, value);
}

void dce110_tg_program_timing(struct timing_generator *tg,
	const struct dc_crtc_timing *timing,
	bool use_vbios)
{
	if (use_vbios)
		dce110_timing_generator_program_timing_generator(tg, timing);
	else
		dce110_timing_generator_program_blanking(tg, timing);
}

bool dce110_tg_is_blanked(struct timing_generator *tg)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t value = dm_read_reg(tg->ctx, CRTC_REG(mmCRTC_BLANK_CONTROL));

	if (get_reg_field_value(
			value,
			CRTC_BLANK_CONTROL,
			CRTC_BLANK_DATA_EN) == 1 &&
		get_reg_field_value(
			value,
			CRTC_BLANK_CONTROL,
			CRTC_CURRENT_BLANK_STATE) == 1)
		return true;
	return false;
}

void dce110_tg_set_blank(struct timing_generator *tg,
		bool enable_blanking)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t value = 0;

	set_reg_field_value(
		value,
		1,
		CRTC_DOUBLE_BUFFER_CONTROL,
		CRTC_BLANK_DATA_DOUBLE_BUFFER_EN);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_DOUBLE_BUFFER_CONTROL), value);
	value = 0;

	if (enable_blanking) {
		set_reg_field_value(
			value,
			1,
			CRTC_BLANK_CONTROL,
			CRTC_BLANK_DATA_EN);

		dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_BLANK_CONTROL), value);

	} else
		dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_BLANK_CONTROL), 0);
}

bool dce110_tg_validate_timing(struct timing_generator *tg,
	const struct dc_crtc_timing *timing)
{
	return dce110_timing_generator_validate_timing(tg, timing, SIGNAL_TYPE_NONE);
}

void dce110_tg_wait_for_state(struct timing_generator *tg,
	enum crtc_state state)
{
	switch (state) {
	case CRTC_STATE_VBLANK:
		dce110_timing_generator_wait_for_vblank(tg);
		break;

	case CRTC_STATE_VACTIVE:
		dce110_timing_generator_wait_for_vactive(tg);
		break;

	default:
		break;
	}
}

void dce110_tg_set_colors(struct timing_generator *tg,
	const struct tg_color *blank_color,
	const struct tg_color *overscan_color)
{
	if (blank_color != NULL)
		dce110_tg_program_blank_color(tg, blank_color);
	if (overscan_color != NULL)
		dce110_tg_set_overscan_color(tg, overscan_color);
}

bool dce110_arm_vert_intr(struct timing_generator *tg, uint8_t width)
{
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);
	uint32_t v_blank_start = 0;
	uint32_t v_blank_end = 0;
	uint32_t val = 0;
	uint32_t h_position, v_position;

	tg->funcs->get_scanoutpos(
			tg,
			&v_blank_start,
			&v_blank_end,
			&h_position,
			&v_position);

	if (v_blank_start == 0 || v_blank_end == 0)
		return false;

	set_reg_field_value(
		val,
		v_blank_start,
		CRTC_VERTICAL_INTERRUPT0_POSITION,
		CRTC_VERTICAL_INTERRUPT0_LINE_START);

	/* Set interval width for interrupt to fire to 1 scanline */
	set_reg_field_value(
		val,
		v_blank_start + width,
		CRTC_VERTICAL_INTERRUPT0_POSITION,
		CRTC_VERTICAL_INTERRUPT0_LINE_END);

	dm_write_reg(tg->ctx, CRTC_REG(mmCRTC_VERTICAL_INTERRUPT0_POSITION), val);

	return true;
}

__attribute__((used)) static bool dce110_is_tg_enabled(struct timing_generator *tg)
{
	uint32_t addr = 0;
	uint32_t value = 0;
	uint32_t field = 0;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	addr = CRTC_REG(mmCRTC_CONTROL);
	value = dm_read_reg(tg->ctx, addr);
	field = get_reg_field_value(value, CRTC_CONTROL,
				    CRTC_CURRENT_MASTER_EN_STATE);
	return field == 1;
}

bool dce110_configure_crc(struct timing_generator *tg,
			  const struct crc_params *params)
{
	uint32_t cntl_addr = 0;
	uint32_t addr = 0;
	uint32_t value;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	/* Cannot configure crc on a CRTC that is disabled */
	if (!dce110_is_tg_enabled(tg))
		return false;

	cntl_addr = CRTC_REG(mmCRTC_CRC_CNTL);

	/* First, disable CRC before we configure it. */
	dm_write_reg(tg->ctx, cntl_addr, 0);

	if (!params->enable)
		return true;

	/* Program frame boundaries */
	/* Window A x axis start and end. */
	value = 0;
	addr = CRTC_REG(mmCRTC_CRC0_WINDOWA_X_CONTROL);
	set_reg_field_value(value, params->windowa_x_start,
			    CRTC_CRC0_WINDOWA_X_CONTROL,
			    CRTC_CRC0_WINDOWA_X_START);
	set_reg_field_value(value, params->windowa_x_end,
			    CRTC_CRC0_WINDOWA_X_CONTROL,
			    CRTC_CRC0_WINDOWA_X_END);
	dm_write_reg(tg->ctx, addr, value);

	/* Window A y axis start and end. */
	value = 0;
	addr = CRTC_REG(mmCRTC_CRC0_WINDOWA_Y_CONTROL);
	set_reg_field_value(value, params->windowa_y_start,
			    CRTC_CRC0_WINDOWA_Y_CONTROL,
			    CRTC_CRC0_WINDOWA_Y_START);
	set_reg_field_value(value, params->windowa_y_end,
			    CRTC_CRC0_WINDOWA_Y_CONTROL,
			    CRTC_CRC0_WINDOWA_Y_END);
	dm_write_reg(tg->ctx, addr, value);

	/* Window B x axis start and end. */
	value = 0;
	addr = CRTC_REG(mmCRTC_CRC0_WINDOWB_X_CONTROL);
	set_reg_field_value(value, params->windowb_x_start,
			    CRTC_CRC0_WINDOWB_X_CONTROL,
			    CRTC_CRC0_WINDOWB_X_START);
	set_reg_field_value(value, params->windowb_x_end,
			    CRTC_CRC0_WINDOWB_X_CONTROL,
			    CRTC_CRC0_WINDOWB_X_END);
	dm_write_reg(tg->ctx, addr, value);

	/* Window B y axis start and end. */
	value = 0;
	addr = CRTC_REG(mmCRTC_CRC0_WINDOWB_Y_CONTROL);
	set_reg_field_value(value, params->windowb_y_start,
			    CRTC_CRC0_WINDOWB_Y_CONTROL,
			    CRTC_CRC0_WINDOWB_Y_START);
	set_reg_field_value(value, params->windowb_y_end,
			    CRTC_CRC0_WINDOWB_Y_CONTROL,
			    CRTC_CRC0_WINDOWB_Y_END);
	dm_write_reg(tg->ctx, addr, value);

	/* Set crc mode and selection, and enable. Only using CRC0*/
	value = 0;
	set_reg_field_value(value, params->continuous_mode ? 1 : 0,
			    CRTC_CRC_CNTL, CRTC_CRC_CONT_EN);
	set_reg_field_value(value, params->selection,
			    CRTC_CRC_CNTL, CRTC_CRC0_SELECT);
	set_reg_field_value(value, 1, CRTC_CRC_CNTL, CRTC_CRC_EN);
	dm_write_reg(tg->ctx, cntl_addr, value);

	return true;
}

bool dce110_get_crc(struct timing_generator *tg,
		    uint32_t *r_cr, uint32_t *g_y, uint32_t *b_cb)
{
	uint32_t addr = 0;
	uint32_t value = 0;
	uint32_t field = 0;
	struct dce110_timing_generator *tg110 = DCE110TG_FROM_TG(tg);

	addr = CRTC_REG(mmCRTC_CRC_CNTL);
	value = dm_read_reg(tg->ctx, addr);
	field = get_reg_field_value(value, CRTC_CRC_CNTL, CRTC_CRC_EN);

	/* Early return if CRC is not enabled for this CRTC */
	if (!field)
		return false;

	addr = CRTC_REG(mmCRTC_CRC0_DATA_RG);
	value = dm_read_reg(tg->ctx, addr);
	*r_cr = get_reg_field_value(value, CRTC_CRC0_DATA_RG, CRC0_R_CR);
	*g_y = get_reg_field_value(value, CRTC_CRC0_DATA_RG, CRC0_G_Y);

	addr = CRTC_REG(mmCRTC_CRC0_DATA_B);
	value = dm_read_reg(tg->ctx, addr);
	*b_cb = get_reg_field_value(value, CRTC_CRC0_DATA_B, CRC0_B_CB);

	return true;
}

void dce110_timing_generator_construct(
	struct dce110_timing_generator *tg110,
	struct dc_context *ctx,
	uint32_t instance,
	const struct dce110_timing_generator_offsets *offsets)
{
	tg110->controller_id = CONTROLLER_ID_D0 + instance;
	tg110->base.inst = instance;

	tg110->offsets = *offsets;

	tg110->base.funcs = &dce110_tg_funcs;

	tg110->base.ctx = ctx;
	tg110->base.bp = ctx->dc_bios;

	tg110->max_h_total = CRTC_H_TOTAL__CRTC_H_TOTAL_MASK + 1;
	tg110->max_v_total = CRTC_V_TOTAL__CRTC_V_TOTAL_MASK + 1;

	tg110->min_h_blank = 56;
	tg110->min_h_front_porch = 4;
	tg110->min_h_back_porch = 4;
}

