#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_9__ ;
typedef  struct TYPE_21__   TYPE_8__ ;
typedef  struct TYPE_20__   TYPE_7__ ;
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
struct TYPE_17__ {unsigned long long x; unsigned long long y; unsigned long long width; unsigned long long height; } ;
struct TYPE_16__ {unsigned long long x; unsigned long long y; unsigned long long width; unsigned long long height; } ;
struct TYPE_18__ {unsigned long long luma_pitch; unsigned long long chroma_pitch; TYPE_4__ chroma_size; TYPE_3__ luma_size; } ;
union plane_size {TYPE_5__ video; } ;
struct TYPE_19__ {unsigned long long num_banks; unsigned long long bank_width; unsigned long long bank_height; unsigned long long tile_aspect; unsigned long long tile_split; unsigned long long tile_mode; unsigned long long pipe_config; unsigned long long array_mode; unsigned long long bank_width_c; unsigned long long bank_height_c; unsigned long long tile_aspect_c; unsigned long long tile_split_c; unsigned long long tile_mode_c; } ;
union dc_tiling_info {TYPE_6__ gfx8; } ;
typedef  unsigned long long uint8_t ;
typedef  unsigned long long uint32_t ;
struct TYPE_13__ {unsigned long long high_part; unsigned long long low_part; } ;
struct TYPE_15__ {TYPE_10__ luma_addr; TYPE_10__ chroma_addr; } ;
struct TYPE_14__ {TYPE_10__ addr; } ;
struct dc_plane_address {int type; TYPE_2__ video_progressive; TYPE_1__ grph; } ;
struct mem_input {struct dc_context const* ctx; struct dc_plane_address request_address; struct dc_plane_address current_address; } ;
struct dce_watermarks {unsigned long long a_mark; unsigned long long b_mark; } ;
struct TYPE_22__ {struct dc_context const* ctx; int /*<<< orphan*/ * funcs; } ;
struct dce_mem_input {TYPE_9__ base; } ;
struct dc_plane_dcc_param {int dummy; } ;
typedef  struct dc_context {TYPE_8__* dc; } const dc_context ;
typedef  enum surface_pixel_format { ____Placeholder_surface_pixel_format } surface_pixel_format ;
typedef  enum dc_rotation_angle { ____Placeholder_dc_rotation_angle } dc_rotation_angle ;
struct TYPE_20__ {scalar_t__ disable_stutter; } ;
struct TYPE_21__ {TYPE_7__ debug; } ;
typedef  TYPE_10__ PHYSICAL_ADDRESS_LOC ;

/* Variables and functions */
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
#define  DC_ARRAY_1D_TILED_THICK 154 
#define  DC_ARRAY_1D_TILED_THIN1 153 
#define  DC_ARRAY_2D_TILED_THICK 152 
#define  DC_ARRAY_2D_TILED_THIN1 151 
#define  DC_ARRAY_2D_TILED_X_THICK 150 
#define  DC_ARRAY_LINEAR_ALLIGNED 149 
#define  DC_ARRAY_LINEAR_GENERAL 148 
#define  DC_ARRAY_PRT_2D_TILED_THICK 147 
#define  DC_ARRAY_PRT_2D_TILED_THIN1 146 
#define  DC_ARRAY_PRT_TILED_THIN1 145 
 int /*<<< orphan*/  DPGV0_PIPE_ARBITRATION_CONTROL1 ; 
 int /*<<< orphan*/  DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL ; 
 int /*<<< orphan*/  DPGV0_PIPE_STUTTER_CONTROL ; 
 int /*<<< orphan*/  DPGV0_PIPE_URGENCY_CONTROL ; 
 int /*<<< orphan*/  DPGV0_WATERMARK_MASK_CONTROL ; 
 int /*<<< orphan*/  DPGV1_PIPE_ARBITRATION_CONTROL1 ; 
 int /*<<< orphan*/  DVMM_MAX_PTE_REQ_OUTSTANDING ; 
 int /*<<< orphan*/  DVMM_MAX_PTE_REQ_OUTSTANDING_C ; 
 int /*<<< orphan*/  DVMM_MIN_PTE_BEFORE_FLIP ; 
 int /*<<< orphan*/  DVMM_MIN_PTE_BEFORE_FLIP_C ; 
 int /*<<< orphan*/  DVMM_PAGE_HEIGHT ; 
 int /*<<< orphan*/  DVMM_PAGE_HEIGHT_C ; 
 int /*<<< orphan*/  DVMM_PAGE_WIDTH ; 
 int /*<<< orphan*/  DVMM_PAGE_WIDTH_C ; 
 int /*<<< orphan*/  DVMM_PTE_REQ_PER_CHUNK ; 
 int /*<<< orphan*/  DVMM_PTE_REQ_PER_CHUNK_C ; 
 int /*<<< orphan*/  GRPH_ARRAY_MODE ; 
 int /*<<< orphan*/  GRPH_BANK_HEIGHT_C ; 
 int /*<<< orphan*/  GRPH_BANK_HEIGHT_L ; 
 int /*<<< orphan*/  GRPH_BANK_WIDTH_C ; 
 int /*<<< orphan*/  GRPH_BANK_WIDTH_L ; 
 int /*<<< orphan*/  GRPH_COLOR_EXPANSION_MODE ; 
 int /*<<< orphan*/  GRPH_DEPTH ; 
 int /*<<< orphan*/  GRPH_ENABLE ; 
 int /*<<< orphan*/  GRPH_FORMAT ; 
 int /*<<< orphan*/  GRPH_MACRO_TILE_ASPECT_C ; 
 int /*<<< orphan*/  GRPH_MACRO_TILE_ASPECT_L ; 
 int /*<<< orphan*/  GRPH_MICRO_TILE_MODE_C ; 
 int /*<<< orphan*/  GRPH_MICRO_TILE_MODE_L ; 
 int /*<<< orphan*/  GRPH_NUM_BANKS ; 
 int /*<<< orphan*/  GRPH_PIPE_CONFIG ; 
 int /*<<< orphan*/  GRPH_PITCH_C ; 
 int /*<<< orphan*/  GRPH_PITCH_L ; 
 int /*<<< orphan*/  GRPH_PRIMARY_SURFACE_ADDRESS_C ; 
 int /*<<< orphan*/  GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C ; 
 int /*<<< orphan*/  GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L ; 
 int /*<<< orphan*/  GRPH_PRIMARY_SURFACE_ADDRESS_L ; 
 int /*<<< orphan*/  GRPH_SURFACE_UPDATE_PENDING ; 
 int /*<<< orphan*/  GRPH_SURFACE_UPDATE_PENDING_MODE ; 
 int /*<<< orphan*/  GRPH_TILE_SPLIT_C ; 
 int /*<<< orphan*/  GRPH_TILE_SPLIT_L ; 
 int /*<<< orphan*/  GRPH_X_END_C ; 
 int /*<<< orphan*/  GRPH_X_END_L ; 
 int /*<<< orphan*/  GRPH_X_START_C ; 
 int /*<<< orphan*/  GRPH_X_START_L ; 
 int /*<<< orphan*/  GRPH_Y_END_C ; 
 int /*<<< orphan*/  GRPH_Y_END_L ; 
 int /*<<< orphan*/  GRPH_Y_START_C ; 
 int /*<<< orphan*/  GRPH_Y_START_L ; 
 int /*<<< orphan*/  GRPH_Z ; 
 int /*<<< orphan*/  NB_PSTATE_CHANGE_ENABLE ; 
 int /*<<< orphan*/  NB_PSTATE_CHANGE_NOT_SELF_REFRESH_DURING_REQUEST ; 
 int /*<<< orphan*/  NB_PSTATE_CHANGE_URGENT_DURING_REQUEST ; 
 int /*<<< orphan*/  NB_PSTATE_CHANGE_WATERMARK ; 
 int /*<<< orphan*/  NB_PSTATE_CHANGE_WATERMARK_MASK ; 
 int /*<<< orphan*/  PIXEL_DURATION ; 
#define  PLN_ADDR_TYPE_GRAPHICS 144 
#define  PLN_ADDR_TYPE_VIDEO_PROGRESSIVE 143 
 int /*<<< orphan*/  ROTATION_ANGLE ; 
#define  ROTATION_ANGLE_180 142 
#define  ROTATION_ANGLE_270 141 
#define  ROTATION_ANGLE_90 140 
 int /*<<< orphan*/  STUTTER_ENABLE ; 
 int /*<<< orphan*/  STUTTER_EXIT_SELF_REFRESH_WATERMARK ; 
 int /*<<< orphan*/  STUTTER_EXIT_SELF_REFRESH_WATERMARK_MASK ; 
 int /*<<< orphan*/  STUTTER_IGNORE_FBC ; 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR16161616F 139 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010 138 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010_XR_BIAS 137 
#define  SURFACE_PIXEL_FORMAT_GRPH_ABGR8888 136 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616 135 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616F 134 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB2101010 133 
#define  SURFACE_PIXEL_FORMAT_GRPH_ARGB8888 132 
#define  SURFACE_PIXEL_FORMAT_GRPH_PALETA_256_COLORS 131 
#define  SURFACE_PIXEL_FORMAT_GRPH_RGB565 130 
 int SURFACE_PIXEL_FORMAT_INVALID ; 
#define  SURFACE_PIXEL_FORMAT_VIDEO_420_YCbCr 129 
#define  SURFACE_PIXEL_FORMAT_VIDEO_420_YCrCb 128 
 int SURFACE_PIXEL_FORMAT_VIDEO_BEGIN ; 
 struct dce_mem_input* TO_DCE_MEM_INPUT (struct mem_input*) ; 
 int /*<<< orphan*/  UNP_DVMM_PTE_ARB_CONTROL ; 
 int /*<<< orphan*/  UNP_DVMM_PTE_ARB_CONTROL_C ; 
 int /*<<< orphan*/  UNP_DVMM_PTE_CONTROL ; 
 int /*<<< orphan*/  UNP_DVMM_PTE_CONTROL_C ; 
 int /*<<< orphan*/  UNP_FLIP_CONTROL ; 
 int /*<<< orphan*/  UNP_GRPH_CONTROL ; 
 int /*<<< orphan*/  UNP_GRPH_CONTROL_C ; 
 int /*<<< orphan*/  UNP_GRPH_CONTROL_EXP ; 
 int /*<<< orphan*/  UNP_GRPH_ENABLE ; 
 int /*<<< orphan*/  UNP_GRPH_PITCH_C ; 
 int /*<<< orphan*/  UNP_GRPH_PITCH_L ; 
 int /*<<< orphan*/  UNP_GRPH_PRIMARY_SURFACE_ADDRESS_C ; 
 unsigned long long UNP_GRPH_PRIMARY_SURFACE_ADDRESS_C__GRPH_PRIMARY_SURFACE_ADDRESS_C__SHIFT ; 
 int /*<<< orphan*/  UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C ; 
 unsigned long long UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C__GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C_MASK ; 
 int /*<<< orphan*/  UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L ; 
 unsigned long long UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L__GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L_MASK ; 
 int /*<<< orphan*/  UNP_GRPH_PRIMARY_SURFACE_ADDRESS_L ; 
 unsigned long long UNP_GRPH_PRIMARY_SURFACE_ADDRESS_L__GRPH_PRIMARY_SURFACE_ADDRESS_L__SHIFT ; 
 int /*<<< orphan*/  UNP_GRPH_UPDATE ; 
 int /*<<< orphan*/  UNP_GRPH_X_END_C ; 
 int /*<<< orphan*/  UNP_GRPH_X_END_L ; 
 int /*<<< orphan*/  UNP_GRPH_X_START_C ; 
 int /*<<< orphan*/  UNP_GRPH_X_START_L ; 
 int /*<<< orphan*/  UNP_GRPH_Y_END_C ; 
 int /*<<< orphan*/  UNP_GRPH_Y_END_L ; 
 int /*<<< orphan*/  UNP_GRPH_Y_START_C ; 
 int /*<<< orphan*/  UNP_GRPH_Y_START_L ; 
 int /*<<< orphan*/  UNP_HW_ROTATION ; 
 int /*<<< orphan*/  UNP_PIPE_OUTSTANDING_REQUEST_LIMIT ; 
 int /*<<< orphan*/  UNP_PIPE_OUTSTANDING_REQUEST_LIMIT_C ; 
 int /*<<< orphan*/  UNP_PIPE_OUTSTANDING_REQUEST_LIMIT_L ; 
 int /*<<< orphan*/  URGENCY_HIGH_WATERMARK ; 
 int /*<<< orphan*/  URGENCY_LOW_WATERMARK ; 
 int /*<<< orphan*/  URGENCY_WATERMARK_MASK ; 
 int /*<<< orphan*/  VIDEO_FORMAT ; 
 int /*<<< orphan*/  dce110_mem_input_v_funcs ; 
 unsigned long long dm_read_reg (struct dc_context const*,unsigned long long const) ; 
 int /*<<< orphan*/  dm_write_reg (struct dc_context const*,unsigned long long const,unsigned long long) ; 
 unsigned int const** dvmm_Hw_Setting_1DTiling ; 
 unsigned int const** dvmm_Hw_Setting_2DTiling ; 
 unsigned int const** dvmm_Hw_Setting_Linear ; 
 scalar_t__ get_reg_field_value (unsigned long long,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long long mmDPGV0_PIPE_ARBITRATION_CONTROL1 ; 
 unsigned long long mmDPGV0_PIPE_ARBITRATION_CONTROL2 ; 
 unsigned long long mmDPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL ; 
 unsigned long long mmDPGV0_PIPE_STUTTER_CONTROL ; 
 unsigned long long mmDPGV0_PIPE_URGENCY_CONTROL ; 
 unsigned long long mmDPGV0_WATERMARK_MASK_CONTROL ; 
 unsigned long long mmDPGV1_PIPE_ARBITRATION_CONTROL1 ; 
 unsigned long long mmDPGV1_PIPE_ARBITRATION_CONTROL2 ; 
 unsigned long long mmDPGV1_PIPE_NB_PSTATE_CHANGE_CONTROL ; 
 unsigned long long mmDPGV1_PIPE_STUTTER_CONTROL ; 
 unsigned long long mmDPGV1_PIPE_URGENCY_CONTROL ; 
 unsigned long long mmDPGV1_WATERMARK_MASK_CONTROL ; 
 unsigned long long mmUNP_DVMM_PTE_ARB_CONTROL ; 
 unsigned long long mmUNP_DVMM_PTE_ARB_CONTROL_C ; 
 unsigned long long mmUNP_DVMM_PTE_CONTROL ; 
 unsigned long long mmUNP_DVMM_PTE_CONTROL_C ; 
 unsigned long long mmUNP_FLIP_CONTROL ; 
 unsigned long long mmUNP_GRPH_CONTROL ; 
 unsigned long long mmUNP_GRPH_CONTROL_C ; 
 unsigned long long mmUNP_GRPH_CONTROL_EXP ; 
 unsigned long long mmUNP_GRPH_ENABLE ; 
 unsigned long long mmUNP_GRPH_PITCH_C ; 
 unsigned long long mmUNP_GRPH_PITCH_L ; 
 unsigned long long mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_C ; 
 unsigned long long mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C ; 
 unsigned long long mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L ; 
 unsigned long long mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_L ; 
 unsigned long long mmUNP_GRPH_UPDATE ; 
 unsigned long long mmUNP_GRPH_X_END_C ; 
 unsigned long long mmUNP_GRPH_X_END_L ; 
 unsigned long long mmUNP_GRPH_X_START_C ; 
 unsigned long long mmUNP_GRPH_X_START_L ; 
 unsigned long long mmUNP_GRPH_Y_END_C ; 
 unsigned long long mmUNP_GRPH_Y_END_L ; 
 unsigned long long mmUNP_GRPH_Y_START_C ; 
 unsigned long long mmUNP_GRPH_Y_START_L ; 
 unsigned long long mmUNP_HW_ROTATION ; 
 unsigned long long mmUNP_PIPE_OUTSTANDING_REQUEST_LIMIT ; 
 int /*<<< orphan*/  set_reg_field_value (unsigned long long,unsigned int const,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  swap (unsigned long long,unsigned long long) ; 

__attribute__((used)) static void set_flip_control(
	struct dce_mem_input *mem_input110,
	bool immediate)
{
	uint32_t value = 0;

	value = dm_read_reg(
			mem_input110->base.ctx,
			mmUNP_FLIP_CONTROL);

	set_reg_field_value(value, 1,
			UNP_FLIP_CONTROL,
			GRPH_SURFACE_UPDATE_PENDING_MODE);

	dm_write_reg(
			mem_input110->base.ctx,
			mmUNP_FLIP_CONTROL,
			value);
}

__attribute__((used)) static void program_pri_addr_c(
	struct dce_mem_input *mem_input110,
	PHYSICAL_ADDRESS_LOC address)
{
	uint32_t value = 0;
	uint32_t temp = 0;
	/*high register MUST be programmed first*/
	temp = address.high_part &
UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C__GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C_MASK;

	set_reg_field_value(value, temp,
		UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C,
		GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C);

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_C,
		value);

	temp = 0;
	value = 0;
	temp = address.low_part >>
	UNP_GRPH_PRIMARY_SURFACE_ADDRESS_C__GRPH_PRIMARY_SURFACE_ADDRESS_C__SHIFT;

	set_reg_field_value(value, temp,
		UNP_GRPH_PRIMARY_SURFACE_ADDRESS_C,
		GRPH_PRIMARY_SURFACE_ADDRESS_C);

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_C,
		value);
}

__attribute__((used)) static void program_pri_addr_l(
	struct dce_mem_input *mem_input110,
	PHYSICAL_ADDRESS_LOC address)
{
	uint32_t value = 0;
	uint32_t temp = 0;

	/*high register MUST be programmed first*/
	temp = address.high_part &
UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L__GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L_MASK;

	set_reg_field_value(value, temp,
		UNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L,
		GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L);

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_HIGH_L,
		value);

	temp = 0;
	value = 0;
	temp = address.low_part >>
	UNP_GRPH_PRIMARY_SURFACE_ADDRESS_L__GRPH_PRIMARY_SURFACE_ADDRESS_L__SHIFT;

	set_reg_field_value(value, temp,
		UNP_GRPH_PRIMARY_SURFACE_ADDRESS_L,
		GRPH_PRIMARY_SURFACE_ADDRESS_L);

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_PRIMARY_SURFACE_ADDRESS_L,
		value);
}

__attribute__((used)) static void program_addr(
	struct dce_mem_input *mem_input110,
	const struct dc_plane_address *addr)
{
	switch (addr->type) {
	case PLN_ADDR_TYPE_GRAPHICS:
		program_pri_addr_l(
			mem_input110,
			addr->grph.addr);
		break;
	case PLN_ADDR_TYPE_VIDEO_PROGRESSIVE:
		program_pri_addr_c(
			mem_input110,
			addr->video_progressive.chroma_addr);
		program_pri_addr_l(
			mem_input110,
			addr->video_progressive.luma_addr);
		break;
	default:
		/* not supported */
		BREAK_TO_DEBUGGER();
	}
}

__attribute__((used)) static void enable(struct dce_mem_input *mem_input110)
{
	uint32_t value = 0;

	value = dm_read_reg(mem_input110->base.ctx, mmUNP_GRPH_ENABLE);
	set_reg_field_value(value, 1, UNP_GRPH_ENABLE, GRPH_ENABLE);
	dm_write_reg(mem_input110->base.ctx,
		mmUNP_GRPH_ENABLE,
		value);
}

__attribute__((used)) static void program_tiling(
	struct dce_mem_input *mem_input110,
	const union dc_tiling_info *info,
	const enum surface_pixel_format pixel_format)
{
	uint32_t value = 0;

	set_reg_field_value(value, info->gfx8.num_banks,
		UNP_GRPH_CONTROL, GRPH_NUM_BANKS);

	set_reg_field_value(value, info->gfx8.bank_width,
		UNP_GRPH_CONTROL, GRPH_BANK_WIDTH_L);

	set_reg_field_value(value, info->gfx8.bank_height,
		UNP_GRPH_CONTROL, GRPH_BANK_HEIGHT_L);

	set_reg_field_value(value, info->gfx8.tile_aspect,
		UNP_GRPH_CONTROL, GRPH_MACRO_TILE_ASPECT_L);

	set_reg_field_value(value, info->gfx8.tile_split,
		UNP_GRPH_CONTROL, GRPH_TILE_SPLIT_L);

	set_reg_field_value(value, info->gfx8.tile_mode,
		UNP_GRPH_CONTROL, GRPH_MICRO_TILE_MODE_L);

	set_reg_field_value(value, info->gfx8.pipe_config,
		UNP_GRPH_CONTROL, GRPH_PIPE_CONFIG);

	set_reg_field_value(value, info->gfx8.array_mode,
		UNP_GRPH_CONTROL, GRPH_ARRAY_MODE);

	set_reg_field_value(value, 1,
		UNP_GRPH_CONTROL, GRPH_COLOR_EXPANSION_MODE);

	set_reg_field_value(value, 0,
		UNP_GRPH_CONTROL, GRPH_Z);

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_CONTROL,
		value);

	value = 0;

	set_reg_field_value(value, info->gfx8.bank_width_c,
		UNP_GRPH_CONTROL_C, GRPH_BANK_WIDTH_C);

	set_reg_field_value(value, info->gfx8.bank_height_c,
		UNP_GRPH_CONTROL_C, GRPH_BANK_HEIGHT_C);

	set_reg_field_value(value, info->gfx8.tile_aspect_c,
		UNP_GRPH_CONTROL_C, GRPH_MACRO_TILE_ASPECT_C);

	set_reg_field_value(value, info->gfx8.tile_split_c,
		UNP_GRPH_CONTROL_C, GRPH_TILE_SPLIT_C);

	set_reg_field_value(value, info->gfx8.tile_mode_c,
		UNP_GRPH_CONTROL_C, GRPH_MICRO_TILE_MODE_C);

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_CONTROL_C,
		value);
}

__attribute__((used)) static void program_size_and_rotation(
	struct dce_mem_input *mem_input110,
	enum dc_rotation_angle rotation,
	const union plane_size *plane_size)
{
	uint32_t value = 0;
	union plane_size local_size = *plane_size;

	if (rotation == ROTATION_ANGLE_90 ||
		rotation == ROTATION_ANGLE_270) {

		swap(local_size.video.luma_size.x,
		     local_size.video.luma_size.y);
		swap(local_size.video.luma_size.width,
		     local_size.video.luma_size.height);
		swap(local_size.video.chroma_size.x,
		     local_size.video.chroma_size.y);
		swap(local_size.video.chroma_size.width,
		     local_size.video.chroma_size.height);
	}

	value = 0;
	set_reg_field_value(value, local_size.video.luma_pitch,
			UNP_GRPH_PITCH_L, GRPH_PITCH_L);

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_PITCH_L,
		value);

	value = 0;
	set_reg_field_value(value, local_size.video.chroma_pitch,
			UNP_GRPH_PITCH_C, GRPH_PITCH_C);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_PITCH_C,
		value);

	value = 0;
	set_reg_field_value(value, 0,
			UNP_GRPH_X_START_L, GRPH_X_START_L);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_X_START_L,
		value);

	value = 0;
	set_reg_field_value(value, 0,
			UNP_GRPH_X_START_C, GRPH_X_START_C);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_X_START_C,
		value);

	value = 0;
	set_reg_field_value(value, 0,
			UNP_GRPH_Y_START_L, GRPH_Y_START_L);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_Y_START_L,
		value);

	value = 0;
	set_reg_field_value(value, 0,
			UNP_GRPH_Y_START_C, GRPH_Y_START_C);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_Y_START_C,
		value);

	value = 0;
	set_reg_field_value(value, local_size.video.luma_size.x +
			local_size.video.luma_size.width,
			UNP_GRPH_X_END_L, GRPH_X_END_L);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_X_END_L,
		value);

	value = 0;
	set_reg_field_value(value, local_size.video.chroma_size.x +
			local_size.video.chroma_size.width,
			UNP_GRPH_X_END_C, GRPH_X_END_C);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_X_END_C,
		value);

	value = 0;
	set_reg_field_value(value, local_size.video.luma_size.y +
			local_size.video.luma_size.height,
			UNP_GRPH_Y_END_L, GRPH_Y_END_L);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_Y_END_L,
		value);

	value = 0;
	set_reg_field_value(value, local_size.video.chroma_size.y +
			local_size.video.chroma_size.height,
			UNP_GRPH_Y_END_C, GRPH_Y_END_C);
	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_GRPH_Y_END_C,
		value);

	value = 0;
	switch (rotation) {
	case ROTATION_ANGLE_90:
		set_reg_field_value(value, 3,
			UNP_HW_ROTATION, ROTATION_ANGLE);
		break;
	case ROTATION_ANGLE_180:
		set_reg_field_value(value, 2,
			UNP_HW_ROTATION, ROTATION_ANGLE);
		break;
	case ROTATION_ANGLE_270:
		set_reg_field_value(value, 1,
			UNP_HW_ROTATION, ROTATION_ANGLE);
		break;
	default:
		set_reg_field_value(value, 0,
			UNP_HW_ROTATION, ROTATION_ANGLE);
		break;
	}

	dm_write_reg(
		mem_input110->base.ctx,
		mmUNP_HW_ROTATION,
		value);
}

__attribute__((used)) static void program_pixel_format(
	struct dce_mem_input *mem_input110,
	enum surface_pixel_format format)
{
	if (format < SURFACE_PIXEL_FORMAT_VIDEO_BEGIN) {
		uint32_t value;
		uint8_t grph_depth;
		uint8_t grph_format;

		value =	dm_read_reg(
				mem_input110->base.ctx,
				mmUNP_GRPH_CONTROL);

		switch (format) {
		case SURFACE_PIXEL_FORMAT_GRPH_PALETA_256_COLORS:
			grph_depth = 0;
			grph_format = 0;
			break;
		case SURFACE_PIXEL_FORMAT_GRPH_RGB565:
			grph_depth = 1;
			grph_format = 1;
			break;
		case SURFACE_PIXEL_FORMAT_GRPH_ARGB8888:
		case SURFACE_PIXEL_FORMAT_GRPH_ABGR8888:
			grph_depth = 2;
			grph_format = 0;
			break;
		case SURFACE_PIXEL_FORMAT_GRPH_ARGB2101010:
		case SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010:
		case SURFACE_PIXEL_FORMAT_GRPH_ABGR2101010_XR_BIAS:
			grph_depth = 2;
			grph_format = 1;
			break;
		case SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616:
		case SURFACE_PIXEL_FORMAT_GRPH_ABGR16161616F:
		case SURFACE_PIXEL_FORMAT_GRPH_ARGB16161616F:
			grph_depth = 3;
			grph_format = 0;
			break;
		default:
			grph_depth = 2;
			grph_format = 0;
			break;
		}

		set_reg_field_value(
				value,
				grph_depth,
				UNP_GRPH_CONTROL,
				GRPH_DEPTH);
		set_reg_field_value(
				value,
				grph_format,
				UNP_GRPH_CONTROL,
				GRPH_FORMAT);

		dm_write_reg(
				mem_input110->base.ctx,
				mmUNP_GRPH_CONTROL,
				value);

		value =	dm_read_reg(
				mem_input110->base.ctx,
				mmUNP_GRPH_CONTROL_EXP);

		/* VIDEO FORMAT 0 */
		set_reg_field_value(
				value,
				0,
				UNP_GRPH_CONTROL_EXP,
				VIDEO_FORMAT);
		dm_write_reg(
				mem_input110->base.ctx,
				mmUNP_GRPH_CONTROL_EXP,
				value);

	} else {
		/* Video 422 and 420 needs UNP_GRPH_CONTROL_EXP programmed */
		uint32_t value;
		uint8_t video_format;

		value =	dm_read_reg(
				mem_input110->base.ctx,
				mmUNP_GRPH_CONTROL_EXP);

		switch (format) {
		case SURFACE_PIXEL_FORMAT_VIDEO_420_YCbCr:
			video_format = 2;
			break;
		case SURFACE_PIXEL_FORMAT_VIDEO_420_YCrCb:
			video_format = 3;
			break;
		default:
			video_format = 0;
			break;
		}

		set_reg_field_value(
			value,
			video_format,
			UNP_GRPH_CONTROL_EXP,
			VIDEO_FORMAT);

		dm_write_reg(
			mem_input110->base.ctx,
			mmUNP_GRPH_CONTROL_EXP,
			value);
	}
}

bool dce_mem_input_v_is_surface_pending(struct mem_input *mem_input)
{
	struct dce_mem_input *mem_input110 = TO_DCE_MEM_INPUT(mem_input);
	uint32_t value;

	value = dm_read_reg(mem_input110->base.ctx, mmUNP_GRPH_UPDATE);

	if (get_reg_field_value(value, UNP_GRPH_UPDATE,
			GRPH_SURFACE_UPDATE_PENDING))
		return true;

	mem_input->current_address = mem_input->request_address;
	return false;
}

bool dce_mem_input_v_program_surface_flip_and_addr(
	struct mem_input *mem_input,
	const struct dc_plane_address *address,
	bool flip_immediate)
{
	struct dce_mem_input *mem_input110 = TO_DCE_MEM_INPUT(mem_input);

	set_flip_control(mem_input110, flip_immediate);
	program_addr(mem_input110,
		address);

	mem_input->request_address = *address;

	return true;
}

__attribute__((used)) static const unsigned int *get_dvmm_hw_setting(
		union dc_tiling_info *tiling_info,
		enum surface_pixel_format format,
		bool chroma)
{
	enum bits_per_pixel {
		bpp_8 = 0,
		bpp_16,
		bpp_32,
		bpp_64
	} bpp;

	if (format >= SURFACE_PIXEL_FORMAT_INVALID)
		bpp = bpp_32;
	else if (format >= SURFACE_PIXEL_FORMAT_VIDEO_BEGIN)
		bpp = chroma ? bpp_16 : bpp_8;
	else
		bpp = bpp_8;

	switch (tiling_info->gfx8.array_mode) {
	case DC_ARRAY_1D_TILED_THIN1:
	case DC_ARRAY_1D_TILED_THICK:
	case DC_ARRAY_PRT_TILED_THIN1:
		return dvmm_Hw_Setting_1DTiling[bpp];
	case DC_ARRAY_2D_TILED_THIN1:
	case DC_ARRAY_2D_TILED_THICK:
	case DC_ARRAY_2D_TILED_X_THICK:
	case DC_ARRAY_PRT_2D_TILED_THIN1:
	case DC_ARRAY_PRT_2D_TILED_THICK:
		return dvmm_Hw_Setting_2DTiling[bpp];
	case DC_ARRAY_LINEAR_GENERAL:
	case DC_ARRAY_LINEAR_ALLIGNED:
		return dvmm_Hw_Setting_Linear[bpp];
	default:
		return dvmm_Hw_Setting_2DTiling[bpp];
	}
}

void dce_mem_input_v_program_pte_vm(
		struct mem_input *mem_input,
		enum surface_pixel_format format,
		union dc_tiling_info *tiling_info,
		enum dc_rotation_angle rotation)
{
	struct dce_mem_input *mem_input110 = TO_DCE_MEM_INPUT(mem_input);
	const unsigned int *pte = get_dvmm_hw_setting(tiling_info, format, false);
	const unsigned int *pte_chroma = get_dvmm_hw_setting(tiling_info, format, true);

	unsigned int page_width = 0;
	unsigned int page_height = 0;
	unsigned int page_width_chroma = 0;
	unsigned int page_height_chroma = 0;
	unsigned int temp_page_width = pte[1];
	unsigned int temp_page_height = pte[2];
	unsigned int min_pte_before_flip = 0;
	unsigned int min_pte_before_flip_chroma = 0;
	uint32_t value = 0;

	while ((temp_page_width >>= 1) != 0)
		page_width++;
	while ((temp_page_height >>= 1) != 0)
		page_height++;

	temp_page_width = pte_chroma[1];
	temp_page_height = pte_chroma[2];
	while ((temp_page_width >>= 1) != 0)
		page_width_chroma++;
	while ((temp_page_height >>= 1) != 0)
		page_height_chroma++;

	switch (rotation) {
	case ROTATION_ANGLE_90:
	case ROTATION_ANGLE_270:
		min_pte_before_flip = pte[4];
		min_pte_before_flip_chroma = pte_chroma[4];
		break;
	default:
		min_pte_before_flip = pte[3];
		min_pte_before_flip_chroma = pte_chroma[3];
		break;
	}

	value = dm_read_reg(mem_input110->base.ctx, mmUNP_PIPE_OUTSTANDING_REQUEST_LIMIT);
	/* TODO: un-hardcode requestlimit */
	set_reg_field_value(value, 0xff, UNP_PIPE_OUTSTANDING_REQUEST_LIMIT, UNP_PIPE_OUTSTANDING_REQUEST_LIMIT_L);
	set_reg_field_value(value, 0xff, UNP_PIPE_OUTSTANDING_REQUEST_LIMIT, UNP_PIPE_OUTSTANDING_REQUEST_LIMIT_C);
	dm_write_reg(mem_input110->base.ctx, mmUNP_PIPE_OUTSTANDING_REQUEST_LIMIT, value);

	value = dm_read_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_CONTROL);
	set_reg_field_value(value, page_width, UNP_DVMM_PTE_CONTROL, DVMM_PAGE_WIDTH);
	set_reg_field_value(value, page_height, UNP_DVMM_PTE_CONTROL, DVMM_PAGE_HEIGHT);
	set_reg_field_value(value, min_pte_before_flip, UNP_DVMM_PTE_CONTROL, DVMM_MIN_PTE_BEFORE_FLIP);
	dm_write_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_CONTROL, value);

	value = dm_read_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_ARB_CONTROL);
	set_reg_field_value(value, pte[5], UNP_DVMM_PTE_ARB_CONTROL, DVMM_PTE_REQ_PER_CHUNK);
	set_reg_field_value(value, 0xff, UNP_DVMM_PTE_ARB_CONTROL, DVMM_MAX_PTE_REQ_OUTSTANDING);
	dm_write_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_ARB_CONTROL, value);

	value = dm_read_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_CONTROL_C);
	set_reg_field_value(value, page_width_chroma, UNP_DVMM_PTE_CONTROL_C, DVMM_PAGE_WIDTH_C);
	set_reg_field_value(value, page_height_chroma, UNP_DVMM_PTE_CONTROL_C, DVMM_PAGE_HEIGHT_C);
	set_reg_field_value(value, min_pte_before_flip_chroma, UNP_DVMM_PTE_CONTROL_C, DVMM_MIN_PTE_BEFORE_FLIP_C);
	dm_write_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_CONTROL_C, value);

	value = dm_read_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_ARB_CONTROL_C);
	set_reg_field_value(value, pte_chroma[5], UNP_DVMM_PTE_ARB_CONTROL_C, DVMM_PTE_REQ_PER_CHUNK_C);
	set_reg_field_value(value, 0xff, UNP_DVMM_PTE_ARB_CONTROL_C, DVMM_MAX_PTE_REQ_OUTSTANDING_C);
	dm_write_reg(mem_input110->base.ctx, mmUNP_DVMM_PTE_ARB_CONTROL_C, value);
}

void dce_mem_input_v_program_surface_config(
	struct mem_input *mem_input,
	enum surface_pixel_format format,
	union dc_tiling_info *tiling_info,
	union plane_size *plane_size,
	enum dc_rotation_angle rotation,
	struct dc_plane_dcc_param *dcc,
	bool horizotal_mirror)
{
	struct dce_mem_input *mem_input110 = TO_DCE_MEM_INPUT(mem_input);

	enable(mem_input110);
	program_tiling(mem_input110, tiling_info, format);
	program_size_and_rotation(mem_input110, rotation, plane_size);
	program_pixel_format(mem_input110, format);
}

__attribute__((used)) static void program_urgency_watermark(
	const struct dc_context *ctx,
	const uint32_t urgency_addr,
	const uint32_t wm_addr,
	struct dce_watermarks marks_low,
	uint32_t total_dest_line_time_ns)
{
	/* register value */
	uint32_t urgency_cntl = 0;
	uint32_t wm_mask_cntl = 0;

	/*Write mask to enable reading/writing of watermark set A*/
	wm_mask_cntl = dm_read_reg(ctx, wm_addr);
	set_reg_field_value(wm_mask_cntl,
			1,
			DPGV0_WATERMARK_MASK_CONTROL,
			URGENCY_WATERMARK_MASK);
	dm_write_reg(ctx, wm_addr, wm_mask_cntl);

	urgency_cntl = dm_read_reg(ctx, urgency_addr);

	set_reg_field_value(
		urgency_cntl,
		marks_low.a_mark,
		DPGV0_PIPE_URGENCY_CONTROL,
		URGENCY_LOW_WATERMARK);

	set_reg_field_value(
		urgency_cntl,
		total_dest_line_time_ns,
		DPGV0_PIPE_URGENCY_CONTROL,
		URGENCY_HIGH_WATERMARK);
	dm_write_reg(ctx, urgency_addr, urgency_cntl);

	/*Write mask to enable reading/writing of watermark set B*/
	wm_mask_cntl = dm_read_reg(ctx, wm_addr);
	set_reg_field_value(wm_mask_cntl,
			2,
			DPGV0_WATERMARK_MASK_CONTROL,
			URGENCY_WATERMARK_MASK);
	dm_write_reg(ctx, wm_addr, wm_mask_cntl);

	urgency_cntl = dm_read_reg(ctx, urgency_addr);

	set_reg_field_value(urgency_cntl,
		marks_low.b_mark,
		DPGV0_PIPE_URGENCY_CONTROL,
		URGENCY_LOW_WATERMARK);

	set_reg_field_value(urgency_cntl,
		total_dest_line_time_ns,
		DPGV0_PIPE_URGENCY_CONTROL,
		URGENCY_HIGH_WATERMARK);

	dm_write_reg(ctx, urgency_addr, urgency_cntl);
}

__attribute__((used)) static void program_urgency_watermark_l(
	const struct dc_context *ctx,
	struct dce_watermarks marks_low,
	uint32_t total_dest_line_time_ns)
{
	program_urgency_watermark(
		ctx,
		mmDPGV0_PIPE_URGENCY_CONTROL,
		mmDPGV0_WATERMARK_MASK_CONTROL,
		marks_low,
		total_dest_line_time_ns);
}

__attribute__((used)) static void program_urgency_watermark_c(
	const struct dc_context *ctx,
	struct dce_watermarks marks_low,
	uint32_t total_dest_line_time_ns)
{
	program_urgency_watermark(
		ctx,
		mmDPGV1_PIPE_URGENCY_CONTROL,
		mmDPGV1_WATERMARK_MASK_CONTROL,
		marks_low,
		total_dest_line_time_ns);
}

__attribute__((used)) static void program_stutter_watermark(
	const struct dc_context *ctx,
	const uint32_t stutter_addr,
	const uint32_t wm_addr,
	struct dce_watermarks marks)
{
	/* register value */
	uint32_t stutter_cntl = 0;
	uint32_t wm_mask_cntl = 0;

	/*Write mask to enable reading/writing of watermark set A*/

	wm_mask_cntl = dm_read_reg(ctx, wm_addr);
	set_reg_field_value(wm_mask_cntl,
		1,
		DPGV0_WATERMARK_MASK_CONTROL,
		STUTTER_EXIT_SELF_REFRESH_WATERMARK_MASK);
	dm_write_reg(ctx, wm_addr, wm_mask_cntl);

	stutter_cntl = dm_read_reg(ctx, stutter_addr);

	if (ctx->dc->debug.disable_stutter) {
		set_reg_field_value(stutter_cntl,
			0,
			DPGV0_PIPE_STUTTER_CONTROL,
			STUTTER_ENABLE);
	} else {
		set_reg_field_value(stutter_cntl,
			1,
			DPGV0_PIPE_STUTTER_CONTROL,
			STUTTER_ENABLE);
	}

	set_reg_field_value(stutter_cntl,
		1,
		DPGV0_PIPE_STUTTER_CONTROL,
		STUTTER_IGNORE_FBC);

	/*Write watermark set A*/
	set_reg_field_value(stutter_cntl,
		marks.a_mark,
		DPGV0_PIPE_STUTTER_CONTROL,
		STUTTER_EXIT_SELF_REFRESH_WATERMARK);
	dm_write_reg(ctx, stutter_addr, stutter_cntl);

	/*Write mask to enable reading/writing of watermark set B*/
	wm_mask_cntl = dm_read_reg(ctx, wm_addr);
	set_reg_field_value(wm_mask_cntl,
		2,
		DPGV0_WATERMARK_MASK_CONTROL,
		STUTTER_EXIT_SELF_REFRESH_WATERMARK_MASK);
	dm_write_reg(ctx, wm_addr, wm_mask_cntl);

	stutter_cntl = dm_read_reg(ctx, stutter_addr);
	/*Write watermark set B*/
	set_reg_field_value(stutter_cntl,
		marks.b_mark,
		DPGV0_PIPE_STUTTER_CONTROL,
		STUTTER_EXIT_SELF_REFRESH_WATERMARK);
	dm_write_reg(ctx, stutter_addr, stutter_cntl);
}

__attribute__((used)) static void program_stutter_watermark_l(
	const struct dc_context *ctx,
	struct dce_watermarks marks)
{
	program_stutter_watermark(ctx,
			mmDPGV0_PIPE_STUTTER_CONTROL,
			mmDPGV0_WATERMARK_MASK_CONTROL,
			marks);
}

__attribute__((used)) static void program_stutter_watermark_c(
	const struct dc_context *ctx,
	struct dce_watermarks marks)
{
	program_stutter_watermark(ctx,
			mmDPGV1_PIPE_STUTTER_CONTROL,
			mmDPGV1_WATERMARK_MASK_CONTROL,
			marks);
}

__attribute__((used)) static void program_nbp_watermark(
	const struct dc_context *ctx,
	const uint32_t wm_mask_ctrl_addr,
	const uint32_t nbp_pstate_ctrl_addr,
	struct dce_watermarks marks)
{
	uint32_t value;

	/* Write mask to enable reading/writing of watermark set A */

	value = dm_read_reg(ctx, wm_mask_ctrl_addr);

	set_reg_field_value(
		value,
		1,
		DPGV0_WATERMARK_MASK_CONTROL,
		NB_PSTATE_CHANGE_WATERMARK_MASK);
	dm_write_reg(ctx, wm_mask_ctrl_addr, value);

	value = dm_read_reg(ctx, nbp_pstate_ctrl_addr);

	set_reg_field_value(
		value,
		1,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_ENABLE);
	set_reg_field_value(
		value,
		1,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_URGENT_DURING_REQUEST);
	set_reg_field_value(
		value,
		1,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_NOT_SELF_REFRESH_DURING_REQUEST);
	dm_write_reg(ctx, nbp_pstate_ctrl_addr, value);

	/* Write watermark set A */
	value = dm_read_reg(ctx, nbp_pstate_ctrl_addr);
	set_reg_field_value(
		value,
		marks.a_mark,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_WATERMARK);
	dm_write_reg(ctx, nbp_pstate_ctrl_addr, value);

	/* Write mask to enable reading/writing of watermark set B */
	value = dm_read_reg(ctx, wm_mask_ctrl_addr);
	set_reg_field_value(
		value,
		2,
		DPGV0_WATERMARK_MASK_CONTROL,
		NB_PSTATE_CHANGE_WATERMARK_MASK);
	dm_write_reg(ctx, wm_mask_ctrl_addr, value);

	value = dm_read_reg(ctx, nbp_pstate_ctrl_addr);
	set_reg_field_value(
		value,
		1,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_ENABLE);
	set_reg_field_value(
		value,
		1,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_URGENT_DURING_REQUEST);
	set_reg_field_value(
		value,
		1,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_NOT_SELF_REFRESH_DURING_REQUEST);
	dm_write_reg(ctx, nbp_pstate_ctrl_addr, value);

	/* Write watermark set B */
	value = dm_read_reg(ctx, nbp_pstate_ctrl_addr);
	set_reg_field_value(
		value,
		marks.b_mark,
		DPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
		NB_PSTATE_CHANGE_WATERMARK);
	dm_write_reg(ctx, nbp_pstate_ctrl_addr, value);
}

__attribute__((used)) static void program_nbp_watermark_l(
	const struct dc_context *ctx,
	struct dce_watermarks marks)
{
	program_nbp_watermark(ctx,
			mmDPGV0_WATERMARK_MASK_CONTROL,
			mmDPGV0_PIPE_NB_PSTATE_CHANGE_CONTROL,
			marks);
}

__attribute__((used)) static void program_nbp_watermark_c(
	const struct dc_context *ctx,
	struct dce_watermarks marks)
{
	program_nbp_watermark(ctx,
			mmDPGV1_WATERMARK_MASK_CONTROL,
			mmDPGV1_PIPE_NB_PSTATE_CHANGE_CONTROL,
			marks);
}

void dce_mem_input_v_program_display_marks(
	struct mem_input *mem_input,
	struct dce_watermarks nbp,
	struct dce_watermarks stutter,
	struct dce_watermarks stutter_enter,
	struct dce_watermarks urgent,
	uint32_t total_dest_line_time_ns)
{
	program_urgency_watermark_l(
		mem_input->ctx,
		urgent,
		total_dest_line_time_ns);

	program_nbp_watermark_l(
		mem_input->ctx,
		nbp);

	program_stutter_watermark_l(
		mem_input->ctx,
		stutter);

}

void dce_mem_input_program_chroma_display_marks(
	struct mem_input *mem_input,
	struct dce_watermarks nbp,
	struct dce_watermarks stutter,
	struct dce_watermarks urgent,
	uint32_t total_dest_line_time_ns)
{
	program_urgency_watermark_c(
		mem_input->ctx,
		urgent,
		total_dest_line_time_ns);

	program_nbp_watermark_c(
		mem_input->ctx,
		nbp);

	program_stutter_watermark_c(
		mem_input->ctx,
		stutter);
}

void dce110_allocate_mem_input_v(
	struct mem_input *mi,
	uint32_t h_total,/* for current stream */
	uint32_t v_total,/* for current stream */
	uint32_t pix_clk_khz,/* for current stream */
	uint32_t total_stream_num)
{
	uint32_t addr;
	uint32_t value;
	uint32_t pix_dur;
	if (pix_clk_khz != 0) {
		addr = mmDPGV0_PIPE_ARBITRATION_CONTROL1;
		value = dm_read_reg(mi->ctx, addr);
		pix_dur = 1000000000ULL / pix_clk_khz;
		set_reg_field_value(
			value,
			pix_dur,
			DPGV0_PIPE_ARBITRATION_CONTROL1,
			PIXEL_DURATION);
		dm_write_reg(mi->ctx, addr, value);

		addr = mmDPGV1_PIPE_ARBITRATION_CONTROL1;
		value = dm_read_reg(mi->ctx, addr);
		pix_dur = 1000000000ULL / pix_clk_khz;
		set_reg_field_value(
			value,
			pix_dur,
			DPGV1_PIPE_ARBITRATION_CONTROL1,
			PIXEL_DURATION);
		dm_write_reg(mi->ctx, addr, value);

		addr = mmDPGV0_PIPE_ARBITRATION_CONTROL2;
		value = 0x4000800;
		dm_write_reg(mi->ctx, addr, value);

		addr = mmDPGV1_PIPE_ARBITRATION_CONTROL2;
		value = 0x4000800;
		dm_write_reg(mi->ctx, addr, value);
	}

}

void dce110_free_mem_input_v(
	struct mem_input *mi,
	uint32_t total_stream_num)
{
}

void dce110_mem_input_v_construct(
	struct dce_mem_input *dce_mi,
	struct dc_context *ctx)
{
	dce_mi->base.funcs = &dce110_mem_input_v_funcs;
	dce_mi->base.ctx = ctx;
}

