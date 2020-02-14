#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_78__   TYPE_9__ ;
typedef  struct TYPE_77__   TYPE_8__ ;
typedef  struct TYPE_76__   TYPE_7__ ;
typedef  struct TYPE_75__   TYPE_6__ ;
typedef  struct TYPE_74__   TYPE_5__ ;
typedef  struct TYPE_73__   TYPE_4__ ;
typedef  struct TYPE_72__   TYPE_3__ ;
typedef  struct TYPE_71__   TYPE_39__ ;
typedef  struct TYPE_70__   TYPE_38__ ;
typedef  struct TYPE_69__   TYPE_37__ ;
typedef  struct TYPE_68__   TYPE_36__ ;
typedef  struct TYPE_67__   TYPE_35__ ;
typedef  struct TYPE_66__   TYPE_34__ ;
typedef  struct TYPE_65__   TYPE_33__ ;
typedef  struct TYPE_64__   TYPE_32__ ;
typedef  struct TYPE_63__   TYPE_31__ ;
typedef  struct TYPE_62__   TYPE_30__ ;
typedef  struct TYPE_61__   TYPE_2__ ;
typedef  struct TYPE_60__   TYPE_29__ ;
typedef  struct TYPE_59__   TYPE_28__ ;
typedef  struct TYPE_58__   TYPE_27__ ;
typedef  struct TYPE_57__   TYPE_26__ ;
typedef  struct TYPE_56__   TYPE_25__ ;
typedef  struct TYPE_55__   TYPE_24__ ;
typedef  struct TYPE_54__   TYPE_23__ ;
typedef  struct TYPE_53__   TYPE_22__ ;
typedef  struct TYPE_52__   TYPE_21__ ;
typedef  struct TYPE_51__   TYPE_20__ ;
typedef  struct TYPE_50__   TYPE_1__ ;
typedef  struct TYPE_49__   TYPE_19__ ;
typedef  struct TYPE_48__   TYPE_18__ ;
typedef  struct TYPE_47__   TYPE_17__ ;
typedef  struct TYPE_46__   TYPE_16__ ;
typedef  struct TYPE_45__   TYPE_15__ ;
typedef  struct TYPE_44__   TYPE_14__ ;
typedef  struct TYPE_43__   TYPE_13__ ;
typedef  struct TYPE_42__   TYPE_12__ ;
typedef  struct TYPE_41__   TYPE_11__ ;
typedef  struct TYPE_40__   TYPE_10__ ;

/* Type definitions */
struct resource_context {struct pipe_ctx* pipe_ctx; } ;
struct TYPE_68__ {TYPE_39__* tg; } ;
struct pipe_ctx {unsigned int pipe_idx; TYPE_38__* stream; TYPE_36__ stream_res; } ;
struct dc_surface_update {TYPE_32__* scaling_info; TYPE_27__* plane_info; TYPE_20__* flip_addr; } ;
struct dc_state {int dummy; } ;
struct TYPE_44__ {int /*<<< orphan*/  swizzle; } ;
struct TYPE_42__ {int /*<<< orphan*/  array_mode; int /*<<< orphan*/  pipe_config; int /*<<< orphan*/  tile_mode_c; int /*<<< orphan*/  tile_mode; int /*<<< orphan*/  tile_split_c; int /*<<< orphan*/  tile_split; int /*<<< orphan*/  tile_aspect_c; int /*<<< orphan*/  tile_aspect; int /*<<< orphan*/  bank_height_c; int /*<<< orphan*/  bank_height; int /*<<< orphan*/  bank_width_c; int /*<<< orphan*/  bank_width; int /*<<< orphan*/  num_banks; } ;
struct TYPE_45__ {TYPE_14__ gfx9; TYPE_12__ gfx8; } ;
struct TYPE_43__ {int /*<<< orphan*/  enable; } ;
struct TYPE_78__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_40__ {int /*<<< orphan*/  surface_pitch; TYPE_9__ surface_size; } ;
struct TYPE_41__ {TYPE_10__ grph; } ;
struct TYPE_77__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_76__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_75__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_74__ {int /*<<< orphan*/  v_taps_c; int /*<<< orphan*/  h_taps_c; int /*<<< orphan*/  v_taps; int /*<<< orphan*/  h_taps; } ;
struct TYPE_61__ {int /*<<< orphan*/  quad_part; } ;
struct TYPE_50__ {int /*<<< orphan*/  quad_part; } ;
struct TYPE_72__ {TYPE_2__ meta_addr; TYPE_1__ addr; } ;
struct TYPE_73__ {TYPE_3__ grph; int /*<<< orphan*/  type; } ;
struct dc_plane_state {TYPE_15__ tiling_info; int /*<<< orphan*/  stereo_format; int /*<<< orphan*/  rotation; int /*<<< orphan*/  format; TYPE_13__ dcc; int /*<<< orphan*/  color_space; TYPE_11__ plane_size; TYPE_8__ clip_rect; TYPE_7__ dst_rect; TYPE_6__ src_rect; TYPE_5__ scaling_quality; TYPE_4__ address; int /*<<< orphan*/  flip_immediate; int /*<<< orphan*/  visible; } ;
struct dc {TYPE_35__* res_pool; TYPE_33__* ctx; } ;
struct crtc_position {int horizontal_count; int vertical_count; } ;
struct TYPE_71__ {int /*<<< orphan*/  inst; TYPE_34__* funcs; } ;
struct TYPE_69__ {int /*<<< orphan*/  v_total; int /*<<< orphan*/  h_total; } ;
struct TYPE_70__ {TYPE_37__ timing; } ;
struct TYPE_67__ {unsigned int underlay_pipe_index; int pipe_count; } ;
struct TYPE_66__ {int /*<<< orphan*/  (* get_position ) (TYPE_39__*,struct crtc_position*) ;} ;
struct TYPE_65__ {int /*<<< orphan*/  logger; } ;
struct TYPE_63__ {int /*<<< orphan*/  v_taps_c; int /*<<< orphan*/  h_taps_c; int /*<<< orphan*/  v_taps; int /*<<< orphan*/  h_taps; } ;
struct TYPE_62__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_60__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_59__ {int /*<<< orphan*/  height; int /*<<< orphan*/  width; int /*<<< orphan*/  y; int /*<<< orphan*/  x; } ;
struct TYPE_64__ {TYPE_31__ scaling_quality; TYPE_30__ clip_rect; TYPE_29__ dst_rect; TYPE_28__ src_rect; } ;
struct TYPE_56__ {int /*<<< orphan*/  swizzle; } ;
struct TYPE_55__ {int /*<<< orphan*/  array_mode; int /*<<< orphan*/  pipe_config; int /*<<< orphan*/  tile_mode_c; int /*<<< orphan*/  tile_mode; int /*<<< orphan*/  tile_split_c; int /*<<< orphan*/  tile_split; int /*<<< orphan*/  tile_aspect_c; int /*<<< orphan*/  tile_aspect; int /*<<< orphan*/  bank_height_c; int /*<<< orphan*/  bank_height; int /*<<< orphan*/  bank_width_c; int /*<<< orphan*/  bank_width; int /*<<< orphan*/  num_banks; } ;
struct TYPE_57__ {TYPE_25__ gfx9; TYPE_24__ gfx8; } ;
struct TYPE_52__ {int /*<<< orphan*/  y; int /*<<< orphan*/  x; int /*<<< orphan*/  width; int /*<<< orphan*/  height; } ;
struct TYPE_53__ {TYPE_21__ surface_size; int /*<<< orphan*/  surface_pitch; } ;
struct TYPE_54__ {TYPE_22__ grph; } ;
struct TYPE_58__ {TYPE_26__ tiling_info; int /*<<< orphan*/  per_pixel_alpha; int /*<<< orphan*/  visible; int /*<<< orphan*/  stereo_format; int /*<<< orphan*/  rotation; TYPE_23__ plane_size; int /*<<< orphan*/  format; int /*<<< orphan*/  color_space; } ;
struct TYPE_47__ {int /*<<< orphan*/  quad_part; } ;
struct TYPE_46__ {int /*<<< orphan*/  quad_part; } ;
struct TYPE_48__ {TYPE_17__ meta_addr; TYPE_16__ addr; } ;
struct TYPE_49__ {TYPE_18__ grph; int /*<<< orphan*/  type; } ;
struct TYPE_51__ {int /*<<< orphan*/  flip_immediate; TYPE_19__ address; } ;

/* Variables and functions */
 int /*<<< orphan*/  DC_LOGGER_INIT (int /*<<< orphan*/ ) ; 
 int MAX_PIPES ; 
 int /*<<< orphan*/  SURFACE_TRACE (char*,...) ; 
 int /*<<< orphan*/  TIMING_TRACE (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_39__*,struct crtc_position*) ; 

void pre_surface_trace(
		struct dc *dc,
		const struct dc_plane_state *const *plane_states,
		int surface_count)
{
	int i;
	DC_LOGGER_INIT(dc->ctx->logger);

	for (i = 0; i < surface_count; i++) {
		const struct dc_plane_state *plane_state = plane_states[i];

		SURFACE_TRACE("Planes %d:\n", i);

		SURFACE_TRACE(
				"plane_state->visible = %d;\n"
				"plane_state->flip_immediate = %d;\n"
				"plane_state->address.type = %d;\n"
				"plane_state->address.grph.addr.quad_part = 0x%llX;\n"
				"plane_state->address.grph.meta_addr.quad_part = 0x%llX;\n"
				"plane_state->scaling_quality.h_taps = %d;\n"
				"plane_state->scaling_quality.v_taps = %d;\n"
				"plane_state->scaling_quality.h_taps_c = %d;\n"
				"plane_state->scaling_quality.v_taps_c = %d;\n",
				plane_state->visible,
				plane_state->flip_immediate,
				plane_state->address.type,
				plane_state->address.grph.addr.quad_part,
				plane_state->address.grph.meta_addr.quad_part,
				plane_state->scaling_quality.h_taps,
				plane_state->scaling_quality.v_taps,
				plane_state->scaling_quality.h_taps_c,
				plane_state->scaling_quality.v_taps_c);

		SURFACE_TRACE(
				"plane_state->src_rect.x = %d;\n"
				"plane_state->src_rect.y = %d;\n"
				"plane_state->src_rect.width = %d;\n"
				"plane_state->src_rect.height = %d;\n"
				"plane_state->dst_rect.x = %d;\n"
				"plane_state->dst_rect.y = %d;\n"
				"plane_state->dst_rect.width = %d;\n"
				"plane_state->dst_rect.height = %d;\n"
				"plane_state->clip_rect.x = %d;\n"
				"plane_state->clip_rect.y = %d;\n"
				"plane_state->clip_rect.width = %d;\n"
				"plane_state->clip_rect.height = %d;\n",
				plane_state->src_rect.x,
				plane_state->src_rect.y,
				plane_state->src_rect.width,
				plane_state->src_rect.height,
				plane_state->dst_rect.x,
				plane_state->dst_rect.y,
				plane_state->dst_rect.width,
				plane_state->dst_rect.height,
				plane_state->clip_rect.x,
				plane_state->clip_rect.y,
				plane_state->clip_rect.width,
				plane_state->clip_rect.height);

		SURFACE_TRACE(
				"plane_state->plane_size.grph.surface_size.x = %d;\n"
				"plane_state->plane_size.grph.surface_size.y = %d;\n"
				"plane_state->plane_size.grph.surface_size.width = %d;\n"
				"plane_state->plane_size.grph.surface_size.height = %d;\n"
				"plane_state->plane_size.grph.surface_pitch = %d;\n",
				plane_state->plane_size.grph.surface_size.x,
				plane_state->plane_size.grph.surface_size.y,
				plane_state->plane_size.grph.surface_size.width,
				plane_state->plane_size.grph.surface_size.height,
				plane_state->plane_size.grph.surface_pitch);


		SURFACE_TRACE(
				"plane_state->tiling_info.gfx8.num_banks = %d;\n"
				"plane_state->tiling_info.gfx8.bank_width = %d;\n"
				"plane_state->tiling_info.gfx8.bank_width_c = %d;\n"
				"plane_state->tiling_info.gfx8.bank_height = %d;\n"
				"plane_state->tiling_info.gfx8.bank_height_c = %d;\n"
				"plane_state->tiling_info.gfx8.tile_aspect = %d;\n"
				"plane_state->tiling_info.gfx8.tile_aspect_c = %d;\n"
				"plane_state->tiling_info.gfx8.tile_split = %d;\n"
				"plane_state->tiling_info.gfx8.tile_split_c = %d;\n"
				"plane_state->tiling_info.gfx8.tile_mode = %d;\n"
				"plane_state->tiling_info.gfx8.tile_mode_c = %d;\n",
				plane_state->tiling_info.gfx8.num_banks,
				plane_state->tiling_info.gfx8.bank_width,
				plane_state->tiling_info.gfx8.bank_width_c,
				plane_state->tiling_info.gfx8.bank_height,
				plane_state->tiling_info.gfx8.bank_height_c,
				plane_state->tiling_info.gfx8.tile_aspect,
				plane_state->tiling_info.gfx8.tile_aspect_c,
				plane_state->tiling_info.gfx8.tile_split,
				plane_state->tiling_info.gfx8.tile_split_c,
				plane_state->tiling_info.gfx8.tile_mode,
				plane_state->tiling_info.gfx8.tile_mode_c);

		SURFACE_TRACE(
				"plane_state->tiling_info.gfx8.pipe_config = %d;\n"
				"plane_state->tiling_info.gfx8.array_mode = %d;\n"
				"plane_state->color_space = %d;\n"
				"plane_state->dcc.enable = %d;\n"
				"plane_state->format = %d;\n"
				"plane_state->rotation = %d;\n"
				"plane_state->stereo_format = %d;\n",
				plane_state->tiling_info.gfx8.pipe_config,
				plane_state->tiling_info.gfx8.array_mode,
				plane_state->color_space,
				plane_state->dcc.enable,
				plane_state->format,
				plane_state->rotation,
				plane_state->stereo_format);

		SURFACE_TRACE("plane_state->tiling_info.gfx9.swizzle = %d;\n",
				plane_state->tiling_info.gfx9.swizzle);

		SURFACE_TRACE("\n");
	}
	SURFACE_TRACE("\n");
}

void update_surface_trace(
		struct dc *dc,
		const struct dc_surface_update *updates,
		int surface_count)
{
	int i;
	DC_LOGGER_INIT(dc->ctx->logger);

	for (i = 0; i < surface_count; i++) {
		const struct dc_surface_update *update = &updates[i];

		SURFACE_TRACE("Update %d\n", i);
		if (update->flip_addr) {
			SURFACE_TRACE("flip_addr->address.type = %d;\n"
					"flip_addr->address.grph.addr.quad_part = 0x%llX;\n"
					"flip_addr->address.grph.meta_addr.quad_part = 0x%llX;\n"
					"flip_addr->flip_immediate = %d;\n",
					update->flip_addr->address.type,
					update->flip_addr->address.grph.addr.quad_part,
					update->flip_addr->address.grph.meta_addr.quad_part,
					update->flip_addr->flip_immediate);
		}

		if (update->plane_info) {
			SURFACE_TRACE(
					"plane_info->color_space = %d;\n"
					"plane_info->format = %d;\n"
					"plane_info->plane_size.grph.surface_pitch = %d;\n"
					"plane_info->plane_size.grph.surface_size.height = %d;\n"
					"plane_info->plane_size.grph.surface_size.width = %d;\n"
					"plane_info->plane_size.grph.surface_size.x = %d;\n"
					"plane_info->plane_size.grph.surface_size.y = %d;\n"
					"plane_info->rotation = %d;\n"
					"plane_info->stereo_format = %d;\n",
					update->plane_info->color_space,
					update->plane_info->format,
					update->plane_info->plane_size.grph.surface_pitch,
					update->plane_info->plane_size.grph.surface_size.height,
					update->plane_info->plane_size.grph.surface_size.width,
					update->plane_info->plane_size.grph.surface_size.x,
					update->plane_info->plane_size.grph.surface_size.y,
					update->plane_info->rotation,
					update->plane_info->stereo_format);

			SURFACE_TRACE(
					"plane_info->tiling_info.gfx8.num_banks = %d;\n"
					"plane_info->tiling_info.gfx8.bank_width = %d;\n"
					"plane_info->tiling_info.gfx8.bank_width_c = %d;\n"
					"plane_info->tiling_info.gfx8.bank_height = %d;\n"
					"plane_info->tiling_info.gfx8.bank_height_c = %d;\n"
					"plane_info->tiling_info.gfx8.tile_aspect = %d;\n"
					"plane_info->tiling_info.gfx8.tile_aspect_c = %d;\n"
					"plane_info->tiling_info.gfx8.tile_split = %d;\n"
					"plane_info->tiling_info.gfx8.tile_split_c = %d;\n"
					"plane_info->tiling_info.gfx8.tile_mode = %d;\n"
					"plane_info->tiling_info.gfx8.tile_mode_c = %d;\n",
					update->plane_info->tiling_info.gfx8.num_banks,
					update->plane_info->tiling_info.gfx8.bank_width,
					update->plane_info->tiling_info.gfx8.bank_width_c,
					update->plane_info->tiling_info.gfx8.bank_height,
					update->plane_info->tiling_info.gfx8.bank_height_c,
					update->plane_info->tiling_info.gfx8.tile_aspect,
					update->plane_info->tiling_info.gfx8.tile_aspect_c,
					update->plane_info->tiling_info.gfx8.tile_split,
					update->plane_info->tiling_info.gfx8.tile_split_c,
					update->plane_info->tiling_info.gfx8.tile_mode,
					update->plane_info->tiling_info.gfx8.tile_mode_c);

			SURFACE_TRACE(
					"plane_info->tiling_info.gfx8.pipe_config = %d;\n"
					"plane_info->tiling_info.gfx8.array_mode = %d;\n"
					"plane_info->visible = %d;\n"
					"plane_info->per_pixel_alpha = %d;\n",
					update->plane_info->tiling_info.gfx8.pipe_config,
					update->plane_info->tiling_info.gfx8.array_mode,
					update->plane_info->visible,
					update->plane_info->per_pixel_alpha);

			SURFACE_TRACE("surface->tiling_info.gfx9.swizzle = %d;\n",
					update->plane_info->tiling_info.gfx9.swizzle);
		}

		if (update->scaling_info) {
			SURFACE_TRACE(
					"scaling_info->src_rect.x = %d;\n"
					"scaling_info->src_rect.y = %d;\n"
					"scaling_info->src_rect.width = %d;\n"
					"scaling_info->src_rect.height = %d;\n"
					"scaling_info->dst_rect.x = %d;\n"
					"scaling_info->dst_rect.y = %d;\n"
					"scaling_info->dst_rect.width = %d;\n"
					"scaling_info->dst_rect.height = %d;\n"
					"scaling_info->clip_rect.x = %d;\n"
					"scaling_info->clip_rect.y = %d;\n"
					"scaling_info->clip_rect.width = %d;\n"
					"scaling_info->clip_rect.height = %d;\n"
					"scaling_info->scaling_quality.h_taps = %d;\n"
					"scaling_info->scaling_quality.v_taps = %d;\n"
					"scaling_info->scaling_quality.h_taps_c = %d;\n"
					"scaling_info->scaling_quality.v_taps_c = %d;\n",
					update->scaling_info->src_rect.x,
					update->scaling_info->src_rect.y,
					update->scaling_info->src_rect.width,
					update->scaling_info->src_rect.height,
					update->scaling_info->dst_rect.x,
					update->scaling_info->dst_rect.y,
					update->scaling_info->dst_rect.width,
					update->scaling_info->dst_rect.height,
					update->scaling_info->clip_rect.x,
					update->scaling_info->clip_rect.y,
					update->scaling_info->clip_rect.width,
					update->scaling_info->clip_rect.height,
					update->scaling_info->scaling_quality.h_taps,
					update->scaling_info->scaling_quality.v_taps,
					update->scaling_info->scaling_quality.h_taps_c,
					update->scaling_info->scaling_quality.v_taps_c);
		}
		SURFACE_TRACE("\n");
	}
	SURFACE_TRACE("\n");
}

void post_surface_trace(struct dc *dc)
{
	DC_LOGGER_INIT(dc->ctx->logger);

	SURFACE_TRACE("post surface process.\n");

}

void context_timing_trace(
		struct dc *dc,
		struct resource_context *res_ctx)
{
	int i;
	struct dc  *core_dc = dc;
	int h_pos[MAX_PIPES], v_pos[MAX_PIPES];
	struct crtc_position position;
	unsigned int underlay_idx = core_dc->res_pool->underlay_pipe_index;
	DC_LOGGER_INIT(dc->ctx->logger);


	for (i = 0; i < core_dc->res_pool->pipe_count; i++) {
		struct pipe_ctx *pipe_ctx = &res_ctx->pipe_ctx[i];
		/* get_position() returns CRTC vertical/horizontal counter
		 * hence not applicable for underlay pipe
		 */
		if (pipe_ctx->stream == NULL
				 || pipe_ctx->pipe_idx == underlay_idx)
			continue;

		pipe_ctx->stream_res.tg->funcs->get_position(pipe_ctx->stream_res.tg, &position);
		h_pos[i] = position.horizontal_count;
		v_pos[i] = position.vertical_count;
	}
	for (i = 0; i < core_dc->res_pool->pipe_count; i++) {
		struct pipe_ctx *pipe_ctx = &res_ctx->pipe_ctx[i];

		if (pipe_ctx->stream == NULL)
			continue;

		TIMING_TRACE("OTG_%d   H_tot:%d  V_tot:%d   H_pos:%d  V_pos:%d\n",
				pipe_ctx->stream_res.tg->inst,
				pipe_ctx->stream->timing.h_total,
				pipe_ctx->stream->timing.v_total,
				h_pos[i], v_pos[i]);
	}
}

void context_clock_trace(
		struct dc *dc,
		struct dc_state *context)
{
#if defined(CONFIG_DRM_AMD_DC_DCN1_0)
	DC_LOGGER_INIT(dc->ctx->logger);
	CLOCK_TRACE("Current: dispclk_khz:%d  max_dppclk_khz:%d  dcfclk_khz:%d\n"
			"dcfclk_deep_sleep_khz:%d  fclk_khz:%d  socclk_khz:%d\n",
			context->bw.dcn.clk.dispclk_khz,
			context->bw.dcn.clk.dppclk_khz,
			context->bw.dcn.clk.dcfclk_khz,
			context->bw.dcn.clk.dcfclk_deep_sleep_khz,
			context->bw.dcn.clk.fclk_khz,
			context->bw.dcn.clk.socclk_khz);
	CLOCK_TRACE("Calculated: dispclk_khz:%d  max_dppclk_khz:%d  dcfclk_khz:%d\n"
			"dcfclk_deep_sleep_khz:%d  fclk_khz:%d  socclk_khz:%d\n",
			context->bw.dcn.clk.dispclk_khz,
			context->bw.dcn.clk.dppclk_khz,
			context->bw.dcn.clk.dcfclk_khz,
			context->bw.dcn.clk.dcfclk_deep_sleep_khz,
			context->bw.dcn.clk.fclk_khz,
			context->bw.dcn.clk.socclk_khz);
#endif
}

