#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  int uint32_t ;
struct scaling_taps {int h_taps; int v_taps; int v_taps_c; int h_taps_c; } ;
struct TYPE_23__ {int h_taps; int v_taps; int v_taps_c; int h_taps_c; } ;
struct TYPE_15__ {long long value; } ;
struct TYPE_22__ {TYPE_12__ vert_c; TYPE_12__ horz_c; TYPE_12__ vert; TYPE_12__ horz; } ;
struct TYPE_18__ {scalar_t__ width; } ;
struct TYPE_16__ {scalar_t__ width; } ;
struct scaler_data {scalar_t__ format; scalar_t__ h_active; TYPE_8__ taps; TYPE_7__ ratios; TYPE_3__ viewport; TYPE_1__ recout; } ;
struct pwl_params {int /*<<< orphan*/  hw_points_num; int /*<<< orphan*/  rgb_resulted; } ;
struct out_csc_color_matrix {int color_space; int /*<<< orphan*/ * regval; } ;
struct dpp_cursor_attributes {int bias; int scale; } ;
struct dpp {TYPE_6__* ctx; TYPE_2__* caps; } ;
struct dcn_dpp_state {void* gamut_remap_c33_c34; void* gamut_remap_c31_c32; void* gamut_remap_c23_c24; void* gamut_remap_c21_c22; void* gamut_remap_c13_c14; void* gamut_remap_c11_c12; int /*<<< orphan*/  gamut_remap_mode; int /*<<< orphan*/  rgam_lut_mode; int /*<<< orphan*/  dgam_lut_mode; int /*<<< orphan*/  igam_input_format; int /*<<< orphan*/  igam_lut_mode; } ;
struct dcn_dpp_shift {int dummy; } ;
struct dcn_dpp_registers {int dummy; } ;
struct dcn_dpp_mask {scalar_t__ DPPCLK_RATE_CONTROL; } ;
struct TYPE_13__ {int inst; int /*<<< orphan*/ * caps; int /*<<< orphan*/ * funcs; struct dc_context* ctx; } ;
struct dcn10_dpp {int is_write_to_ram_a_safe; int lb_pixel_depth_supported; int /*<<< orphan*/  lb_memory_size; int /*<<< orphan*/  lb_bits_per_entry; struct dcn_dpp_mask const* tf_mask; struct dcn_dpp_shift const* tf_shift; struct dcn_dpp_registers const* tf_regs; TYPE_10__ base; struct pwl_params pwl_data; struct pwl_params scl_data; int /*<<< orphan*/ * filter_v; int /*<<< orphan*/ * filter_h; int /*<<< orphan*/ * filter_v_c; int /*<<< orphan*/ * filter_h_c; } ;
struct dc_cursor_position {int x; int x_hotspot; scalar_t__ enable; } ;
struct TYPE_24__ {int x; scalar_t__ width; } ;
struct dc_cursor_mi_param {TYPE_9__ viewport; } ;
struct dc_csc_transform {int enable_adjustment; int /*<<< orphan*/ * matrix; } ;
struct dc_context {int dummy; } ;
typedef  enum surface_pixel_format { ____Placeholder_surface_pixel_format } surface_pixel_format ;
typedef  enum pixel_format_description { ____Placeholder_pixel_format_description } pixel_format_description ;
typedef  enum opp_regamma { ____Placeholder_opp_regamma } opp_regamma ;
typedef  enum expansion_mode { ____Placeholder_expansion_mode } expansion_mode ;
typedef  enum dcn10_input_csc_select { ____Placeholder_dcn10_input_csc_select } dcn10_input_csc_select ;
typedef  enum dc_cursor_color_format { ____Placeholder_dc_cursor_color_format } dc_cursor_color_format ;
typedef  enum dc_color_space { ____Placeholder_dc_color_space } dc_color_space ;
struct TYPE_21__ {TYPE_5__* dc; } ;
struct TYPE_19__ {scalar_t__ max_downscale_src_width; int /*<<< orphan*/  always_scale; } ;
struct TYPE_20__ {TYPE_4__ debug; } ;
struct TYPE_17__ {scalar_t__ dscl_data_proc_format; } ;
struct TYPE_14__ {long long value; } ;

/* Variables and functions */
 int /*<<< orphan*/  CM_DGAM_CONTROL ; 
 int /*<<< orphan*/  CM_DGAM_LUT_MODE ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_C11_C12 ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_C13_C14 ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_C21_C22 ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_C23_C24 ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_C31_C32 ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_C33_C34 ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_CONTROL ; 
 int /*<<< orphan*/  CM_GAMUT_REMAP_MODE ; 
 int /*<<< orphan*/  CM_IGAM_CONTROL ; 
 int /*<<< orphan*/  CM_IGAM_INPUT_FORMAT ; 
 int /*<<< orphan*/  CM_IGAM_LUT_MODE ; 
 int /*<<< orphan*/  CM_RGAM_CONTROL ; 
 int /*<<< orphan*/  CM_RGAM_LUT_MODE ; 
 int /*<<< orphan*/  CNVC_BYPASS ; 
 int /*<<< orphan*/  CNVC_SURFACE_PIXEL_FORMAT ; 
 int COLOR_SPACE_SRGB ; 
 int COLOR_SPACE_YCBCR601 ; 
 int COLOR_SPACE_YCBCR709 ; 
 int /*<<< orphan*/  CUR0_COLOR0 ; 
 int /*<<< orphan*/  CUR0_COLOR1 ; 
 int /*<<< orphan*/  CUR0_ENABLE ; 
 int /*<<< orphan*/  CUR0_EXPANSION_MODE ; 
 int /*<<< orphan*/  CUR0_FP_BIAS ; 
 int /*<<< orphan*/  CUR0_FP_SCALE ; 
 int /*<<< orphan*/  CUR0_MODE ; 
 int /*<<< orphan*/  CURSOR0_COLOR0 ; 
 int /*<<< orphan*/  CURSOR0_COLOR1 ; 
 int /*<<< orphan*/  CURSOR0_CONTROL ; 
 int /*<<< orphan*/  CURSOR0_FP_SCALE_BIAS ; 
 int /*<<< orphan*/  CURSOR_CONTROL ; 
 int /*<<< orphan*/  CURSOR_ENABLE ; 
 int CURSOR_MODE_MONO ; 
 int /*<<< orphan*/  DPPCLK_RATE_CONTROL ; 
 int /*<<< orphan*/  DPP_CLOCK_ENABLE ; 
 int /*<<< orphan*/  DPP_CONTROL ; 
 scalar_t__ DSCL_DATA_PRCESSING_FIXED_FORMAT ; 
 int /*<<< orphan*/  FORMAT_CONTROL ; 
 int /*<<< orphan*/  FORMAT_CONTROL__ALPHA_EN ; 
 int /*<<< orphan*/  FORMAT_EXPANSION_MODE ; 
 scalar_t__ IDENTITY_RATIO (TYPE_12__) ; 
 int INPUT_CSC_SELECT_BYPASS ; 
 int INPUT_CSC_SELECT_ICSC ; 
 int /*<<< orphan*/  LB_BITS_PER_ENTRY ; 
 int LB_PIXEL_DEPTH_18BPP ; 
 int LB_PIXEL_DEPTH_24BPP ; 
 int LB_PIXEL_DEPTH_30BPP ; 
 int /*<<< orphan*/  LB_TOTAL_NUMBER_OF_ENTRIES ; 
#define  OPP_REGAMMA_BYPASS 147 
#define  OPP_REGAMMA_SRGB 146 
#define  OPP_REGAMMA_USER 145 
#define  OPP_REGAMMA_XVYCC 144 
 int /*<<< orphan*/  OUTPUT_FP ; 
#define  PIXEL_FORMAT_FIXED 143 
#define  PIXEL_FORMAT_FIXED16 142 
#define  PIXEL_FORMAT_FLOAT 141 
 scalar_t__ PIXEL_FORMAT_FP16 ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 void* REG_READ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  REG_SET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_SET_3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  REG_UPDATE_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int) ; 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR16161616F 140 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010 139 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR8888 138 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB1555 137 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616 136 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616F 135 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB2101010 134 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB8888 133 
#define  SURFACE_PIXEL_FORMAT_GRPH_RGB565 132 
#define  SURFACE_PIXEL_FORMAT_VIDEO_420_10bpc_YCbCr 131 
#define  SURFACE_PIXEL_FORMAT_VIDEO_420_10bpc_YCrCb 130 
#define  SURFACE_PIXEL_FORMAT_VIDEO_420_YCbCr 129 
#define  SURFACE_PIXEL_FORMAT_VIDEO_420_YCrCb 128 
 struct dcn10_dpp* TO_DCN10_DPP (struct dpp*) ; 
 TYPE_11__ dc_fixpt_one ; 
 int /*<<< orphan*/  dcn10_dpp_cap ; 
 int /*<<< orphan*/  dcn10_dpp_funcs ; 
 int /*<<< orphan*/  dpp1_cm_configure_regamma_lut (struct dpp*,int) ; 
 int /*<<< orphan*/  dpp1_cm_power_on_regamma_lut (struct dpp*,int) ; 
 int /*<<< orphan*/  dpp1_cm_program_regamma_lut (struct dpp*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpp1_cm_program_regamma_luta_settings (struct dpp*,struct pwl_params const*) ; 
 int /*<<< orphan*/  dpp1_cm_program_regamma_lutb_settings (struct dpp*,struct pwl_params const*) ; 
 int /*<<< orphan*/  dpp1_program_input_csc (struct dpp*,int,int,struct out_csc_color_matrix*) ; 
 int /*<<< orphan*/  memcmp (struct pwl_params*,struct pwl_params const*,int) ; 
 int /*<<< orphan*/  memset (struct pwl_params*,int /*<<< orphan*/ ,int) ; 

void dpp_read_state(struct dpp *dpp_base,
		struct dcn_dpp_state *s)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);

	REG_GET(CM_IGAM_CONTROL,
			CM_IGAM_LUT_MODE, &s->igam_lut_mode);
	REG_GET(CM_IGAM_CONTROL,
			CM_IGAM_INPUT_FORMAT, &s->igam_input_format);
	REG_GET(CM_DGAM_CONTROL,
			CM_DGAM_LUT_MODE, &s->dgam_lut_mode);
	REG_GET(CM_RGAM_CONTROL,
			CM_RGAM_LUT_MODE, &s->rgam_lut_mode);
	REG_GET(CM_GAMUT_REMAP_CONTROL,
			CM_GAMUT_REMAP_MODE, &s->gamut_remap_mode);

	s->gamut_remap_c11_c12 = REG_READ(CM_GAMUT_REMAP_C11_C12);
	s->gamut_remap_c13_c14 = REG_READ(CM_GAMUT_REMAP_C13_C14);
	s->gamut_remap_c21_c22 = REG_READ(CM_GAMUT_REMAP_C21_C22);
	s->gamut_remap_c23_c24 = REG_READ(CM_GAMUT_REMAP_C23_C24);
	s->gamut_remap_c31_c32 = REG_READ(CM_GAMUT_REMAP_C31_C32);
	s->gamut_remap_c33_c34 = REG_READ(CM_GAMUT_REMAP_C33_C34);
}

void dpp_set_gamut_remap_bypass(struct dcn10_dpp *dpp)
{
	REG_SET(CM_GAMUT_REMAP_CONTROL, 0,
			CM_GAMUT_REMAP_MODE, 0);
	/* Gamut remap in bypass */
}

__attribute__((used)) static bool dpp_get_optimal_number_of_taps(
		struct dpp *dpp,
		struct scaler_data *scl_data,
		const struct scaling_taps *in_taps)
{
	uint32_t pixel_width;

	if (scl_data->viewport.width > scl_data->recout.width)
		pixel_width = scl_data->recout.width;
	else
		pixel_width = scl_data->viewport.width;

	/* Some ASICs does not support  FP16 scaling, so we reject modes require this*/
	if (scl_data->format == PIXEL_FORMAT_FP16 &&
		dpp->caps->dscl_data_proc_format == DSCL_DATA_PRCESSING_FIXED_FORMAT &&
		scl_data->ratios.horz.value != dc_fixpt_one.value &&
		scl_data->ratios.vert.value != dc_fixpt_one.value)
		return false;

	if (scl_data->viewport.width > scl_data->h_active &&
		dpp->ctx->dc->debug.max_downscale_src_width != 0 &&
		scl_data->viewport.width > dpp->ctx->dc->debug.max_downscale_src_width)
		return false;

	/* TODO: add lb check */

	/* No support for programming ratio of 4, drop to 3.99999.. */
	if (scl_data->ratios.horz.value == (4ll << 32))
		scl_data->ratios.horz.value--;
	if (scl_data->ratios.vert.value == (4ll << 32))
		scl_data->ratios.vert.value--;
	if (scl_data->ratios.horz_c.value == (4ll << 32))
		scl_data->ratios.horz_c.value--;
	if (scl_data->ratios.vert_c.value == (4ll << 32))
		scl_data->ratios.vert_c.value--;

	/* Set default taps if none are provided */
	if (in_taps->h_taps == 0)
		scl_data->taps.h_taps = 4;
	else
		scl_data->taps.h_taps = in_taps->h_taps;
	if (in_taps->v_taps == 0)
		scl_data->taps.v_taps = 4;
	else
		scl_data->taps.v_taps = in_taps->v_taps;
	if (in_taps->v_taps_c == 0)
		scl_data->taps.v_taps_c = 2;
	else
		scl_data->taps.v_taps_c = in_taps->v_taps_c;
	if (in_taps->h_taps_c == 0)
		scl_data->taps.h_taps_c = 2;
	/* Only 1 and even h_taps_c are supported by hw */
	else if ((in_taps->h_taps_c % 2) != 0 && in_taps->h_taps_c != 1)
		scl_data->taps.h_taps_c = in_taps->h_taps_c - 1;
	else
		scl_data->taps.h_taps_c = in_taps->h_taps_c;

	if (!dpp->ctx->dc->debug.always_scale) {
		if (IDENTITY_RATIO(scl_data->ratios.horz))
			scl_data->taps.h_taps = 1;
		if (IDENTITY_RATIO(scl_data->ratios.vert))
			scl_data->taps.v_taps = 1;
		if (IDENTITY_RATIO(scl_data->ratios.horz_c))
			scl_data->taps.h_taps_c = 1;
		if (IDENTITY_RATIO(scl_data->ratios.vert_c))
			scl_data->taps.v_taps_c = 1;
	}

	return true;
}

void dpp_reset(struct dpp *dpp_base)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);

	dpp->filter_h_c = NULL;
	dpp->filter_v_c = NULL;
	dpp->filter_h = NULL;
	dpp->filter_v = NULL;

	memset(&dpp->scl_data, 0, sizeof(dpp->scl_data));
	memset(&dpp->pwl_data, 0, sizeof(dpp->pwl_data));
}

__attribute__((used)) static void dpp1_cm_set_regamma_pwl(
	struct dpp *dpp_base, const struct pwl_params *params, enum opp_regamma mode)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);
	uint32_t re_mode = 0;

	switch (mode) {
	case OPP_REGAMMA_BYPASS:
		re_mode = 0;
		break;
	case OPP_REGAMMA_SRGB:
		re_mode = 1;
		break;
	case OPP_REGAMMA_XVYCC:
		re_mode = 2;
		break;
	case OPP_REGAMMA_USER:
		re_mode = dpp->is_write_to_ram_a_safe ? 4 : 3;
		if (memcmp(&dpp->pwl_data, params, sizeof(*params)) == 0)
			break;

		dpp1_cm_power_on_regamma_lut(dpp_base, true);
		dpp1_cm_configure_regamma_lut(dpp_base, dpp->is_write_to_ram_a_safe);

		if (dpp->is_write_to_ram_a_safe)
			dpp1_cm_program_regamma_luta_settings(dpp_base, params);
		else
			dpp1_cm_program_regamma_lutb_settings(dpp_base, params);

		dpp1_cm_program_regamma_lut(dpp_base, params->rgb_resulted,
					    params->hw_points_num);
		dpp->pwl_data = *params;

		re_mode = dpp->is_write_to_ram_a_safe ? 3 : 4;
		dpp->is_write_to_ram_a_safe = !dpp->is_write_to_ram_a_safe;
		break;
	default:
		break;
	}
	REG_SET(CM_RGAM_CONTROL, 0, CM_RGAM_LUT_MODE, re_mode);
}

__attribute__((used)) static void dpp1_setup_format_flags(enum surface_pixel_format input_format,\
						enum pixel_format_description *fmt)
{

	if (input_format == SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616F ||
		input_format == SURFACE_PIXEL_FORMAT_GRPH_ABGR16161616F)
		*fmt = PIXEL_FORMAT_FLOAT;
	else if (input_format == SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616)
		*fmt = PIXEL_FORMAT_FIXED16;
	else
		*fmt = PIXEL_FORMAT_FIXED;
}

__attribute__((used)) static void dpp1_set_degamma_format_float(
		struct dpp *dpp_base,
		bool is_float)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);

	if (is_float) {
		REG_UPDATE(CM_IGAM_CONTROL, CM_IGAM_INPUT_FORMAT, 3);
		REG_UPDATE(CM_IGAM_CONTROL, CM_IGAM_LUT_MODE, 1);
	} else {
		REG_UPDATE(CM_IGAM_CONTROL, CM_IGAM_INPUT_FORMAT, 2);
		REG_UPDATE(CM_IGAM_CONTROL, CM_IGAM_LUT_MODE, 0);
	}
}

void dpp1_cnv_setup (
		struct dpp *dpp_base,
		enum surface_pixel_format format,
		enum expansion_mode mode,
		struct dc_csc_transform input_csc_color_matrix,
		enum dc_color_space input_color_space)
{
	uint32_t pixel_format;
	uint32_t alpha_en;
	enum pixel_format_description fmt ;
	enum dc_color_space color_space;
	enum dcn10_input_csc_select select;
	bool is_float;
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);
	bool force_disable_cursor = false;
	struct out_csc_color_matrix tbl_entry;
	int i = 0;

	dpp1_setup_format_flags(format, &fmt);
	alpha_en = 1;
	pixel_format = 0;
	color_space = COLOR_SPACE_SRGB;
	select = INPUT_CSC_SELECT_BYPASS;
	is_float = false;

	switch (fmt) {
	case PIXEL_FORMAT_FIXED:
	case PIXEL_FORMAT_FIXED16:
	/*when output is float then FORMAT_CONTROL__OUTPUT_FP=1*/
		REG_SET_3(FORMAT_CONTROL, 0,
			CNVC_BYPASS, 0,
			FORMAT_EXPANSION_MODE, mode,
			OUTPUT_FP, 0);
		break;
	case PIXEL_FORMAT_FLOAT:
		REG_SET_3(FORMAT_CONTROL, 0,
			CNVC_BYPASS, 0,
			FORMAT_EXPANSION_MODE, mode,
			OUTPUT_FP, 1);
		is_float = true;
		break;
	default:

		break;
	}

	dpp1_set_degamma_format_float(dpp_base, is_float);

	switch (format) {
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB1555:
		pixel_format = 1;
		break;
	case SURFACE_PIXEL_FORMAT_GRPH_RGB565:
		pixel_format = 3;
		alpha_en = 0;
		break;
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB8888:
	case SURFACE_PIXEL_FORMAT_GRPH_ABGR8888:
		pixel_format = 8;
		break;
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB2101010:
	case SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010:
		pixel_format = 10;
		break;
	case SURFACE_PIXEL_FORMAT_VIDEO_420_YCbCr:
		force_disable_cursor = false;
		pixel_format = 65;
		color_space = COLOR_SPACE_YCBCR709;
		select = INPUT_CSC_SELECT_ICSC;
		break;
	case SURFACE_PIXEL_FORMAT_VIDEO_420_YCrCb:
		force_disable_cursor = true;
		pixel_format = 64;
		color_space = COLOR_SPACE_YCBCR709;
		select = INPUT_CSC_SELECT_ICSC;
		break;
	case SURFACE_PIXEL_FORMAT_VIDEO_420_10bpc_YCbCr:
		force_disable_cursor = true;
		pixel_format = 67;
		color_space = COLOR_SPACE_YCBCR709;
		select = INPUT_CSC_SELECT_ICSC;
		break;
	case SURFACE_PIXEL_FORMAT_VIDEO_420_10bpc_YCrCb:
		force_disable_cursor = true;
		pixel_format = 66;
		color_space = COLOR_SPACE_YCBCR709;
		select = INPUT_CSC_SELECT_ICSC;
		break;
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616:
		pixel_format = 22;
		break;
	case SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616F:
		pixel_format = 24;
		break;
	case SURFACE_PIXEL_FORMAT_GRPH_ABGR16161616F:
		pixel_format = 25;
		break;
	default:
		break;
	}
	REG_SET(CNVC_SURFACE_PIXEL_FORMAT, 0,
			CNVC_SURFACE_PIXEL_FORMAT, pixel_format);
	REG_UPDATE(FORMAT_CONTROL, FORMAT_CONTROL__ALPHA_EN, alpha_en);

	// if input adjustments exist, program icsc with those values

	if (input_csc_color_matrix.enable_adjustment
				== true) {
		for (i = 0; i < 12; i++)
			tbl_entry.regval[i] = input_csc_color_matrix.matrix[i];

		tbl_entry.color_space = input_color_space;

		if (color_space >= COLOR_SPACE_YCBCR601)
			select = INPUT_CSC_SELECT_ICSC;
		else
			select = INPUT_CSC_SELECT_BYPASS;

		dpp1_program_input_csc(dpp_base, color_space, select, &tbl_entry);
	} else
		dpp1_program_input_csc(dpp_base, color_space, select, NULL);

	if (force_disable_cursor) {
		REG_UPDATE(CURSOR_CONTROL,
				CURSOR_ENABLE, 0);
		REG_UPDATE(CURSOR0_CONTROL,
				CUR0_ENABLE, 0);
	}
}

void dpp1_set_cursor_attributes(
		struct dpp *dpp_base,
		enum dc_cursor_color_format color_format)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);

	REG_UPDATE_2(CURSOR0_CONTROL,
			CUR0_MODE, color_format,
			CUR0_EXPANSION_MODE, 0);

	if (color_format == CURSOR_MODE_MONO) {
		/* todo: clarify what to program these to */
		REG_UPDATE(CURSOR0_COLOR0,
				CUR0_COLOR0, 0x00000000);
		REG_UPDATE(CURSOR0_COLOR1,
				CUR0_COLOR1, 0xFFFFFFFF);
	}
}

void dpp1_set_cursor_position(
		struct dpp *dpp_base,
		const struct dc_cursor_position *pos,
		const struct dc_cursor_mi_param *param,
		uint32_t width)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);
	int src_x_offset = pos->x - pos->x_hotspot - param->viewport.x;
	uint32_t cur_en = pos->enable ? 1 : 0;

	if (src_x_offset >= (int)param->viewport.width)
		cur_en = 0;  /* not visible beyond right edge*/

	if (src_x_offset + (int)width <= 0)
		cur_en = 0;  /* not visible beyond left edge*/

	REG_UPDATE(CURSOR0_CONTROL,
			CUR0_ENABLE, cur_en);

}

void dpp1_cnv_set_optional_cursor_attributes(
		struct dpp *dpp_base,
		struct dpp_cursor_attributes *attr)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);

	if (attr) {
		REG_UPDATE(CURSOR0_FP_SCALE_BIAS,  CUR0_FP_BIAS,  attr->bias);
		REG_UPDATE(CURSOR0_FP_SCALE_BIAS,  CUR0_FP_SCALE, attr->scale);
	}
}

void dpp1_dppclk_control(
		struct dpp *dpp_base,
		bool dppclk_div,
		bool enable)
{
	struct dcn10_dpp *dpp = TO_DCN10_DPP(dpp_base);

	if (enable) {
		if (dpp->tf_mask->DPPCLK_RATE_CONTROL)
			REG_UPDATE_2(DPP_CONTROL,
				DPPCLK_RATE_CONTROL, dppclk_div,
				DPP_CLOCK_ENABLE, 1);
		else
			REG_UPDATE(DPP_CONTROL, DPP_CLOCK_ENABLE, 1);
	} else
		REG_UPDATE(DPP_CONTROL, DPP_CLOCK_ENABLE, 0);
}

void dpp1_construct(
	struct dcn10_dpp *dpp,
	struct dc_context *ctx,
	uint32_t inst,
	const struct dcn_dpp_registers *tf_regs,
	const struct dcn_dpp_shift *tf_shift,
	const struct dcn_dpp_mask *tf_mask)
{
	dpp->base.ctx = ctx;

	dpp->base.inst = inst;
	dpp->base.funcs = &dcn10_dpp_funcs;
	dpp->base.caps = &dcn10_dpp_cap;

	dpp->tf_regs = tf_regs;
	dpp->tf_shift = tf_shift;
	dpp->tf_mask = tf_mask;

	dpp->lb_pixel_depth_supported =
		LB_PIXEL_DEPTH_18BPP |
		LB_PIXEL_DEPTH_24BPP |
		LB_PIXEL_DEPTH_30BPP;

	dpp->lb_bits_per_entry = LB_BITS_PER_ENTRY;
	dpp->lb_memory_size = LB_TOTAL_NUMBER_OF_ENTRIES; /*0x1404*/
}

