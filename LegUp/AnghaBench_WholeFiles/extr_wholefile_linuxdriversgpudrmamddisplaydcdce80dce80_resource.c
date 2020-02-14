#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_8__ ;
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  size_t uint32_t ;
struct transform {int dummy; } ;
struct timing_generator {int dummy; } ;
struct stream_encoder {int dummy; } ;
struct resource_straps {int /*<<< orphan*/  dc_pinstraps_audio; int /*<<< orphan*/  audio_stream_number; int /*<<< orphan*/  hdmi_disable; } ;
struct resource_pool {unsigned int pipe_count; unsigned int stream_enc_count; unsigned int clk_src_count; unsigned int audio_count; unsigned int timing_generator_count; struct output_pixel_processor** opps; struct transform** transforms; struct input_pixel_processor** ipps; struct mem_input** mis; struct timing_generator** timing_generators; int /*<<< orphan*/ * irqs; TYPE_11__* dccg; int /*<<< orphan*/ * abm; int /*<<< orphan*/ * dmcu; struct clock_source** clock_sources; struct clock_source* dp_clock_source; void* underlay_pipe_index; int /*<<< orphan*/ * funcs; TYPE_8__* res_cap; struct aux_engine** engines; int /*<<< orphan*/ ** audios; int /*<<< orphan*/ ** stream_enc; } ;
struct output_pixel_processor {int dummy; } ;
struct mem_input {int dummy; } ;
struct link_encoder {int dummy; } ;
struct irq_service_init_data {struct dc_context* ctx; } ;
struct input_pixel_processor {int dummy; } ;
struct encoder_init_data {size_t transmitter; int channel; size_t hpd_source; } ;
struct dm_pp_static_clock_info {int /*<<< orphan*/  max_clocks_state; int /*<<< orphan*/  member_0; } ;
struct dce_transform {int prescaler_on; struct transform base; } ;
struct TYPE_13__ {int single_head_rdreq_dmif_limit; } ;
struct dce_mem_input {struct mem_input base; TYPE_1__ wa; } ;
struct dce_ipp {struct input_pixel_processor base; } ;
struct dce_hwseq {int /*<<< orphan*/ * masks; int /*<<< orphan*/ * shifts; int /*<<< orphan*/ * regs; struct dc_context* ctx; } ;
struct dce110_timing_generator_offsets {int dummy; } ;
struct dce110_timing_generator {struct timing_generator base; } ;
struct dce110_stream_encoder {struct stream_encoder base; } ;
struct dce110_resource_pool {struct resource_pool base; } ;
struct dce110_opp {struct output_pixel_processor base; } ;
struct dce110_link_encoder {struct link_encoder base; } ;
struct dce110_clk_src_regs {int dummy; } ;
struct clock_source {int dp_clk_src; } ;
struct dce110_clk_src {struct clock_source base; } ;
struct TYPE_14__ {int dispclk_khz; int yclk_khz; } ;
struct TYPE_15__ {TYPE_2__ dce; } ;
struct dc_state {int stream_count; TYPE_5__* stream_status; TYPE_3__ bw; } ;
struct dc_firmware_info {scalar_t__ external_clock_source_frequency_for_dp; } ;
struct dc_context {struct dc_bios* dc_bios; } ;
struct dc_bios {TYPE_6__* funcs; int /*<<< orphan*/ * regs; } ;
struct TYPE_19__ {int max_downscale_ratio; int i2c_speed_in_khz; int max_cursor_size; int dual_link_dvi; unsigned int max_planes; int disable_dp_clk_share; int is_apu; } ;
struct dc {TYPE_7__ caps; struct dc_context* ctx; } ;
struct aux_engine {int dummy; } ;
struct aux_engine_dce110 {struct aux_engine base; } ;
struct audio {int dummy; } ;
typedef  enum engine_id { ____Placeholder_engine_id } engine_id ;
typedef  enum dc_status { ____Placeholder_dc_status } dc_status ;
typedef  enum clock_source_id { ____Placeholder_clock_source_id } clock_source_id ;
struct TYPE_20__ {unsigned int num_timing_generator; } ;
struct TYPE_18__ {scalar_t__ (* get_firmware_info ) (struct dc_bios*,struct dc_firmware_info*) ;} ;
struct TYPE_17__ {int plane_count; TYPE_4__** plane_states; } ;
struct TYPE_16__ {scalar_t__ format; } ;
struct TYPE_12__ {int /*<<< orphan*/  max_clks_state; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUDIO_STREAM_NUMBER ; 
 int AUX_TIMEOUT_PERIOD ; 
 scalar_t__ BP_RESULT_OK ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
 int /*<<< orphan*/  CC_DC_HDMI_STRAPS ; 
 int CLOCK_SOURCE_ID_EXTERNAL ; 
 int CLOCK_SOURCE_ID_PLL0 ; 
 int CLOCK_SOURCE_ID_PLL1 ; 
 int CLOCK_SOURCE_ID_PLL2 ; 
 struct dce110_resource_pool* DCE110STRENC_FROM_STRENC (int /*<<< orphan*/ *) ; 
 struct dce110_resource_pool* DCE110TG_FROM_TG (struct timing_generator*) ; 
 int DC_FAIL_SURFACE_VALIDATE ; 
 int DC_OK ; 
 int /*<<< orphan*/  DC_PINSTRAPS ; 
 int /*<<< orphan*/  DC_PINSTRAPS_AUDIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HDMI_DISABLE ; 
 int MEMORY_TYPE_MULTIPLIER ; 
 void* NO_UNDERLAY_PIPE ; 
 int /*<<< orphan*/  REG_GET (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  REG_GET_2 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ SURFACE_PIXEL_FORMAT_VIDEO_BEGIN ; 
 int SW_AUX_TIMEOUT_PERIOD_MULTIPLIER ; 
 struct dce110_resource_pool* TO_DCE110_CLK_SRC (struct clock_source*) ; 
 struct dce110_resource_pool* TO_DCE110_RES_POOL (struct resource_pool*) ; 
 struct dce110_resource_pool* TO_DCE_MEM_INPUT (struct mem_input*) ; 
 struct dce110_resource_pool* TO_DCE_TRANSFORM (struct transform*) ; 
 int /*<<< orphan*/  abm_mask ; 
 int /*<<< orphan*/  abm_regs ; 
 int /*<<< orphan*/  abm_shift ; 
 int /*<<< orphan*/  audio_mask ; 
 int /*<<< orphan*/ * audio_regs ; 
 int /*<<< orphan*/  audio_shift ; 
 int /*<<< orphan*/ * aux_engine_regs ; 
 int /*<<< orphan*/  bios_regs ; 
 struct dce110_clk_src_regs* clk_src_regs ; 
 int /*<<< orphan*/  cs_mask ; 
 int /*<<< orphan*/  cs_shift ; 
 void* dal_irq_service_dce80_create (struct irq_service_init_data*) ; 
 int /*<<< orphan*/  dal_irq_service_destroy (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  dce110_aux_engine_construct (struct aux_engine_dce110*,struct dc_context*,size_t,int,int /*<<< orphan*/ *) ; 
 scalar_t__ dce110_clk_src_construct (struct dce110_clk_src*,struct dc_context*,struct dc_bios*,int,struct dce110_clk_src_regs const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce110_engine_destroy (struct aux_engine**) ; 
 int /*<<< orphan*/  dce110_link_encoder_construct (struct dce110_link_encoder*,struct encoder_init_data const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce110_opp_construct (struct dce110_opp*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce110_opp_destroy (struct output_pixel_processor**) ; 
 int /*<<< orphan*/  dce110_stream_encoder_construct (struct dce110_stream_encoder*,struct dc_context*,struct dc_bios*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce80_hw_sequencer_construct (struct dc*) ; 
 int /*<<< orphan*/  dce80_res_pool_funcs ; 
 struct dce110_timing_generator_offsets* dce80_tg_offsets ; 
 int /*<<< orphan*/  dce80_timing_generator_construct (struct dce110_timing_generator*,struct dc_context*,size_t,struct dce110_timing_generator_offsets const*) ; 
 void* dce_abm_create (struct dc_context*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_abm_destroy (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  dce_aud_destroy (int /*<<< orphan*/ **) ; 
 struct audio* dce_audio_create (struct dc_context*,unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* dce_dccg_create (struct dc_context*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_dccg_destroy (TYPE_11__**) ; 
 void* dce_dmcu_create (struct dc_context*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_dmcu_destroy (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  dce_ipp_construct (struct dce_ipp*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_ipp_destroy (struct input_pixel_processor**) ; 
 int /*<<< orphan*/  dce_mem_input_construct (struct dce_mem_input*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_transform_construct (struct dce_transform*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  disp_clk_mask ; 
 int /*<<< orphan*/  disp_clk_regs ; 
 int /*<<< orphan*/  disp_clk_shift ; 
 int /*<<< orphan*/  dm_error (char*) ; 
 scalar_t__ dm_pp_get_static_clocks (struct dc_context*,struct dm_pp_static_clock_info*) ; 
 int /*<<< orphan*/  dmcu_mask ; 
 int /*<<< orphan*/  dmcu_regs ; 
 int /*<<< orphan*/  dmcu_shift ; 
 int /*<<< orphan*/  hwseq_mask ; 
 int /*<<< orphan*/  hwseq_reg ; 
 int /*<<< orphan*/  hwseq_shift ; 
 int /*<<< orphan*/  ipp_mask ; 
 int /*<<< orphan*/ * ipp_regs ; 
 int /*<<< orphan*/  ipp_shift ; 
 int /*<<< orphan*/  kfree (struct dce110_resource_pool*) ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * link_enc_aux_regs ; 
 int /*<<< orphan*/  link_enc_feature ; 
 int /*<<< orphan*/ * link_enc_hpd_regs ; 
 int /*<<< orphan*/ * link_enc_regs ; 
 int /*<<< orphan*/  mi_masks ; 
 int /*<<< orphan*/ * mi_regs ; 
 int /*<<< orphan*/  mi_shifts ; 
 int /*<<< orphan*/  opp_mask ; 
 int /*<<< orphan*/ * opp_regs ; 
 int /*<<< orphan*/  opp_shift ; 
 TYPE_8__ res_cap ; 
 TYPE_8__ res_cap_81 ; 
 TYPE_8__ res_cap_83 ; 
 int /*<<< orphan*/  res_create_funcs ; 
 int /*<<< orphan*/  resource_construct (int /*<<< orphan*/ ,struct dc*,struct resource_pool*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  se_mask ; 
 int /*<<< orphan*/  se_shift ; 
 int /*<<< orphan*/ * stream_enc_regs ; 
 scalar_t__ stub1 (struct dc_bios*,struct dc_firmware_info*) ; 
 scalar_t__ stub2 (struct dc_bios*,struct dc_firmware_info*) ; 
 scalar_t__ stub3 (struct dc_bios*,struct dc_firmware_info*) ; 
 int /*<<< orphan*/  xfm_mask ; 
 int /*<<< orphan*/ * xfm_regs ; 
 int /*<<< orphan*/  xfm_shift ; 

__attribute__((used)) static void read_dce_straps(
	struct dc_context *ctx,
	struct resource_straps *straps)
{
	REG_GET_2(CC_DC_HDMI_STRAPS,
			HDMI_DISABLE, &straps->hdmi_disable,
			AUDIO_STREAM_NUMBER, &straps->audio_stream_number);

	REG_GET(DC_PINSTRAPS, DC_PINSTRAPS_AUDIO, &straps->dc_pinstraps_audio);
}

__attribute__((used)) static struct audio *create_audio(
		struct dc_context *ctx, unsigned int inst)
{
	return dce_audio_create(ctx, inst,
			&audio_regs[inst], &audio_shift, &audio_mask);
}

__attribute__((used)) static struct timing_generator *dce80_timing_generator_create(
		struct dc_context *ctx,
		uint32_t instance,
		const struct dce110_timing_generator_offsets *offsets)
{
	struct dce110_timing_generator *tg110 =
		kzalloc(sizeof(struct dce110_timing_generator), GFP_KERNEL);

	if (!tg110)
		return NULL;

	dce80_timing_generator_construct(tg110, ctx, instance, offsets);
	return &tg110->base;
}

__attribute__((used)) static struct output_pixel_processor *dce80_opp_create(
	struct dc_context *ctx,
	uint32_t inst)
{
	struct dce110_opp *opp =
		kzalloc(sizeof(struct dce110_opp), GFP_KERNEL);

	if (!opp)
		return NULL;

	dce110_opp_construct(opp,
			     ctx, inst, &opp_regs[inst], &opp_shift, &opp_mask);
	return &opp->base;
}

struct aux_engine *dce80_aux_engine_create(
	struct dc_context *ctx,
	uint32_t inst)
{
	struct aux_engine_dce110 *aux_engine =
		kzalloc(sizeof(struct aux_engine_dce110), GFP_KERNEL);

	if (!aux_engine)
		return NULL;

	dce110_aux_engine_construct(aux_engine, ctx, inst,
				    SW_AUX_TIMEOUT_PERIOD_MULTIPLIER * AUX_TIMEOUT_PERIOD,
				    &aux_engine_regs[inst]);

	return &aux_engine->base;
}

__attribute__((used)) static struct stream_encoder *dce80_stream_encoder_create(
	enum engine_id eng_id,
	struct dc_context *ctx)
{
	struct dce110_stream_encoder *enc110 =
		kzalloc(sizeof(struct dce110_stream_encoder), GFP_KERNEL);

	if (!enc110)
		return NULL;

	dce110_stream_encoder_construct(enc110, ctx, ctx->dc_bios, eng_id,
					&stream_enc_regs[eng_id],
					&se_shift, &se_mask);
	return &enc110->base;
}

__attribute__((used)) static struct dce_hwseq *dce80_hwseq_create(
	struct dc_context *ctx)
{
	struct dce_hwseq *hws = kzalloc(sizeof(struct dce_hwseq), GFP_KERNEL);

	if (hws) {
		hws->ctx = ctx;
		hws->regs = &hwseq_reg;
		hws->shifts = &hwseq_shift;
		hws->masks = &hwseq_mask;
	}
	return hws;
}

__attribute__((used)) static struct mem_input *dce80_mem_input_create(
	struct dc_context *ctx,
	uint32_t inst)
{
	struct dce_mem_input *dce_mi = kzalloc(sizeof(struct dce_mem_input),
					       GFP_KERNEL);

	if (!dce_mi) {
		BREAK_TO_DEBUGGER();
		return NULL;
	}

	dce_mem_input_construct(dce_mi, ctx, inst, &mi_regs[inst], &mi_shifts, &mi_masks);
	dce_mi->wa.single_head_rdreq_dmif_limit = 2;
	return &dce_mi->base;
}

__attribute__((used)) static void dce80_transform_destroy(struct transform **xfm)
{
	kfree(TO_DCE_TRANSFORM(*xfm));
	*xfm = NULL;
}

__attribute__((used)) static struct transform *dce80_transform_create(
	struct dc_context *ctx,
	uint32_t inst)
{
	struct dce_transform *transform =
		kzalloc(sizeof(struct dce_transform), GFP_KERNEL);

	if (!transform)
		return NULL;

	dce_transform_construct(transform, ctx, inst,
				&xfm_regs[inst], &xfm_shift, &xfm_mask);
	transform->prescaler_on = false;
	return &transform->base;
}

struct link_encoder *dce80_link_encoder_create(
	const struct encoder_init_data *enc_init_data)
{
	struct dce110_link_encoder *enc110 =
		kzalloc(sizeof(struct dce110_link_encoder), GFP_KERNEL);

	if (!enc110)
		return NULL;

	dce110_link_encoder_construct(enc110,
				      enc_init_data,
				      &link_enc_feature,
				      &link_enc_regs[enc_init_data->transmitter],
				      &link_enc_aux_regs[enc_init_data->channel - 1],
				      &link_enc_hpd_regs[enc_init_data->hpd_source]);
	return &enc110->base;
}

struct clock_source *dce80_clock_source_create(
	struct dc_context *ctx,
	struct dc_bios *bios,
	enum clock_source_id id,
	const struct dce110_clk_src_regs *regs,
	bool dp_clk_src)
{
	struct dce110_clk_src *clk_src =
		kzalloc(sizeof(struct dce110_clk_src), GFP_KERNEL);

	if (!clk_src)
		return NULL;

	if (dce110_clk_src_construct(clk_src, ctx, bios, id,
			regs, &cs_shift, &cs_mask)) {
		clk_src->base.dp_clk_src = dp_clk_src;
		return &clk_src->base;
	}

	BREAK_TO_DEBUGGER();
	return NULL;
}

void dce80_clock_source_destroy(struct clock_source **clk_src)
{
	kfree(TO_DCE110_CLK_SRC(*clk_src));
	*clk_src = NULL;
}

__attribute__((used)) static struct input_pixel_processor *dce80_ipp_create(
	struct dc_context *ctx, uint32_t inst)
{
	struct dce_ipp *ipp = kzalloc(sizeof(struct dce_ipp), GFP_KERNEL);

	if (!ipp) {
		BREAK_TO_DEBUGGER();
		return NULL;
	}

	dce_ipp_construct(ipp, ctx, inst,
			&ipp_regs[inst], &ipp_shift, &ipp_mask);
	return &ipp->base;
}

__attribute__((used)) static void destruct(struct dce110_resource_pool *pool)
{
	unsigned int i;

	for (i = 0; i < pool->base.pipe_count; i++) {
		if (pool->base.opps[i] != NULL)
			dce110_opp_destroy(&pool->base.opps[i]);

		if (pool->base.transforms[i] != NULL)
			dce80_transform_destroy(&pool->base.transforms[i]);

		if (pool->base.ipps[i] != NULL)
			dce_ipp_destroy(&pool->base.ipps[i]);

		if (pool->base.mis[i] != NULL) {
			kfree(TO_DCE_MEM_INPUT(pool->base.mis[i]));
			pool->base.mis[i] = NULL;
		}

		if (pool->base.timing_generators[i] != NULL)	{
			kfree(DCE110TG_FROM_TG(pool->base.timing_generators[i]));
			pool->base.timing_generators[i] = NULL;
		}

		if (pool->base.engines[i] != NULL)
			dce110_engine_destroy(&pool->base.engines[i]);
	}

	for (i = 0; i < pool->base.stream_enc_count; i++) {
		if (pool->base.stream_enc[i] != NULL)
			kfree(DCE110STRENC_FROM_STRENC(pool->base.stream_enc[i]));
	}

	for (i = 0; i < pool->base.clk_src_count; i++) {
		if (pool->base.clock_sources[i] != NULL) {
			dce80_clock_source_destroy(&pool->base.clock_sources[i]);
		}
	}

	if (pool->base.abm != NULL)
			dce_abm_destroy(&pool->base.abm);

	if (pool->base.dmcu != NULL)
			dce_dmcu_destroy(&pool->base.dmcu);

	if (pool->base.dp_clock_source != NULL)
		dce80_clock_source_destroy(&pool->base.dp_clock_source);

	for (i = 0; i < pool->base.audio_count; i++)	{
		if (pool->base.audios[i] != NULL) {
			dce_aud_destroy(&pool->base.audios[i]);
		}
	}

	if (pool->base.dccg != NULL)
		dce_dccg_destroy(&pool->base.dccg);

	if (pool->base.irqs != NULL) {
		dal_irq_service_destroy(&pool->base.irqs);
	}
}

bool dce80_validate_bandwidth(
	struct dc *dc,
	struct dc_state *context)
{
	/* TODO implement when needed but for now hardcode max value*/
	context->bw.dce.dispclk_khz = 681000;
	context->bw.dce.yclk_khz = 250000 * MEMORY_TYPE_MULTIPLIER;

	return true;
}

__attribute__((used)) static bool dce80_validate_surface_sets(
		struct dc_state *context)
{
	int i;

	for (i = 0; i < context->stream_count; i++) {
		if (context->stream_status[i].plane_count == 0)
			continue;

		if (context->stream_status[i].plane_count > 1)
			return false;

		if (context->stream_status[i].plane_states[0]->format
				>= SURFACE_PIXEL_FORMAT_VIDEO_BEGIN)
			return false;
	}

	return true;
}

enum dc_status dce80_validate_global(
		struct dc *dc,
		struct dc_state *context)
{
	if (!dce80_validate_surface_sets(context))
		return DC_FAIL_SURFACE_VALIDATE;

	return DC_OK;
}

__attribute__((used)) static void dce80_destroy_resource_pool(struct resource_pool **pool)
{
	struct dce110_resource_pool *dce110_pool = TO_DCE110_RES_POOL(*pool);

	destruct(dce110_pool);
	kfree(dce110_pool);
	*pool = NULL;
}

__attribute__((used)) static bool dce80_construct(
	uint8_t num_virtual_links,
	struct dc *dc,
	struct dce110_resource_pool *pool)
{
	unsigned int i;
	struct dc_context *ctx = dc->ctx;
	struct dc_firmware_info info;
	struct dc_bios *bp;
	struct dm_pp_static_clock_info static_clk_info = {0};

	ctx->dc_bios->regs = &bios_regs;

	pool->base.res_cap = &res_cap;
	pool->base.funcs = &dce80_res_pool_funcs;


	/*************************************************
	 *  Resource + asic cap harcoding                *
	 *************************************************/
	pool->base.underlay_pipe_index = NO_UNDERLAY_PIPE;
	pool->base.pipe_count = res_cap.num_timing_generator;
	pool->base.timing_generator_count = res_cap.num_timing_generator;
	dc->caps.max_downscale_ratio = 200;
	dc->caps.i2c_speed_in_khz = 40;
	dc->caps.max_cursor_size = 128;
	dc->caps.dual_link_dvi = true;

	/*************************************************
	 *  Create resources                             *
	 *************************************************/

	bp = ctx->dc_bios;

	if ((bp->funcs->get_firmware_info(bp, &info) == BP_RESULT_OK) &&
		info.external_clock_source_frequency_for_dp != 0) {
		pool->base.dp_clock_source =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_EXTERNAL, NULL, true);

		pool->base.clock_sources[0] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL0, &clk_src_regs[0], false);
		pool->base.clock_sources[1] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL1, &clk_src_regs[1], false);
		pool->base.clock_sources[2] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL2, &clk_src_regs[2], false);
		pool->base.clk_src_count = 3;

	} else {
		pool->base.dp_clock_source =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL0, &clk_src_regs[0], true);

		pool->base.clock_sources[0] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL1, &clk_src_regs[1], false);
		pool->base.clock_sources[1] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL2, &clk_src_regs[2], false);
		pool->base.clk_src_count = 2;
	}

	if (pool->base.dp_clock_source == NULL) {
		dm_error("DC: failed to create dp clock source!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	for (i = 0; i < pool->base.clk_src_count; i++) {
		if (pool->base.clock_sources[i] == NULL) {
			dm_error("DC: failed to create clock sources!\n");
			BREAK_TO_DEBUGGER();
			goto res_create_fail;
		}
	}

	pool->base.dccg = dce_dccg_create(ctx,
			&disp_clk_regs,
			&disp_clk_shift,
			&disp_clk_mask);
	if (pool->base.dccg == NULL) {
		dm_error("DC: failed to create display clock!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	pool->base.dmcu = dce_dmcu_create(ctx,
			&dmcu_regs,
			&dmcu_shift,
			&dmcu_mask);
	if (pool->base.dmcu == NULL) {
		dm_error("DC: failed to create dmcu!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	pool->base.abm = dce_abm_create(ctx,
			&abm_regs,
			&abm_shift,
			&abm_mask);
	if (pool->base.abm == NULL) {
		dm_error("DC: failed to create abm!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}
	if (dm_pp_get_static_clocks(ctx, &static_clk_info))
		pool->base.dccg->max_clks_state =
					static_clk_info.max_clocks_state;

	{
		struct irq_service_init_data init_data;
		init_data.ctx = dc->ctx;
		pool->base.irqs = dal_irq_service_dce80_create(&init_data);
		if (!pool->base.irqs)
			goto res_create_fail;
	}

	for (i = 0; i < pool->base.pipe_count; i++) {
		pool->base.timing_generators[i] = dce80_timing_generator_create(
				ctx, i, &dce80_tg_offsets[i]);
		if (pool->base.timing_generators[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create tg!\n");
			goto res_create_fail;
		}

		pool->base.mis[i] = dce80_mem_input_create(ctx, i);
		if (pool->base.mis[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create memory input!\n");
			goto res_create_fail;
		}

		pool->base.ipps[i] = dce80_ipp_create(ctx, i);
		if (pool->base.ipps[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create input pixel processor!\n");
			goto res_create_fail;
		}

		pool->base.transforms[i] = dce80_transform_create(ctx, i);
		if (pool->base.transforms[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create transform!\n");
			goto res_create_fail;
		}

		pool->base.opps[i] = dce80_opp_create(ctx, i);
		if (pool->base.opps[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create output pixel processor!\n");
			goto res_create_fail;
		}

		pool->base.engines[i] = dce80_aux_engine_create(ctx, i);
		if (pool->base.engines[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error(
				"DC:failed to create aux engine!!\n");
			goto res_create_fail;
		}
	}

	dc->caps.max_planes =  pool->base.pipe_count;
	dc->caps.disable_dp_clk_share = true;

	if (!resource_construct(num_virtual_links, dc, &pool->base,
			&res_create_funcs))
		goto res_create_fail;

	/* Create hardware sequencer */
	dce80_hw_sequencer_construct(dc);

	return true;

res_create_fail:
	destruct(pool);
	return false;
}

struct resource_pool *dce80_create_resource_pool(
	uint8_t num_virtual_links,
	struct dc *dc)
{
	struct dce110_resource_pool *pool =
		kzalloc(sizeof(struct dce110_resource_pool), GFP_KERNEL);

	if (!pool)
		return NULL;

	if (dce80_construct(num_virtual_links, dc, pool))
		return &pool->base;

	BREAK_TO_DEBUGGER();
	return NULL;
}

__attribute__((used)) static bool dce81_construct(
	uint8_t num_virtual_links,
	struct dc *dc,
	struct dce110_resource_pool *pool)
{
	unsigned int i;
	struct dc_context *ctx = dc->ctx;
	struct dc_firmware_info info;
	struct dc_bios *bp;
	struct dm_pp_static_clock_info static_clk_info = {0};

	ctx->dc_bios->regs = &bios_regs;

	pool->base.res_cap = &res_cap_81;
	pool->base.funcs = &dce80_res_pool_funcs;


	/*************************************************
	 *  Resource + asic cap harcoding                *
	 *************************************************/
	pool->base.underlay_pipe_index = NO_UNDERLAY_PIPE;
	pool->base.pipe_count = res_cap_81.num_timing_generator;
	pool->base.timing_generator_count = res_cap_81.num_timing_generator;
	dc->caps.max_downscale_ratio = 200;
	dc->caps.i2c_speed_in_khz = 40;
	dc->caps.max_cursor_size = 128;
	dc->caps.is_apu = true;

	/*************************************************
	 *  Create resources                             *
	 *************************************************/

	bp = ctx->dc_bios;

	if ((bp->funcs->get_firmware_info(bp, &info) == BP_RESULT_OK) &&
		info.external_clock_source_frequency_for_dp != 0) {
		pool->base.dp_clock_source =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_EXTERNAL, NULL, true);

		pool->base.clock_sources[0] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL0, &clk_src_regs[0], false);
		pool->base.clock_sources[1] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL1, &clk_src_regs[1], false);
		pool->base.clock_sources[2] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL2, &clk_src_regs[2], false);
		pool->base.clk_src_count = 3;

	} else {
		pool->base.dp_clock_source =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL0, &clk_src_regs[0], true);

		pool->base.clock_sources[0] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL1, &clk_src_regs[1], false);
		pool->base.clock_sources[1] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL2, &clk_src_regs[2], false);
		pool->base.clk_src_count = 2;
	}

	if (pool->base.dp_clock_source == NULL) {
		dm_error("DC: failed to create dp clock source!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	for (i = 0; i < pool->base.clk_src_count; i++) {
		if (pool->base.clock_sources[i] == NULL) {
			dm_error("DC: failed to create clock sources!\n");
			BREAK_TO_DEBUGGER();
			goto res_create_fail;
		}
	}

	pool->base.dccg = dce_dccg_create(ctx,
			&disp_clk_regs,
			&disp_clk_shift,
			&disp_clk_mask);
	if (pool->base.dccg == NULL) {
		dm_error("DC: failed to create display clock!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	pool->base.dmcu = dce_dmcu_create(ctx,
			&dmcu_regs,
			&dmcu_shift,
			&dmcu_mask);
	if (pool->base.dmcu == NULL) {
		dm_error("DC: failed to create dmcu!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	pool->base.abm = dce_abm_create(ctx,
			&abm_regs,
			&abm_shift,
			&abm_mask);
	if (pool->base.abm == NULL) {
		dm_error("DC: failed to create abm!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	if (dm_pp_get_static_clocks(ctx, &static_clk_info))
		pool->base.dccg->max_clks_state =
					static_clk_info.max_clocks_state;

	{
		struct irq_service_init_data init_data;
		init_data.ctx = dc->ctx;
		pool->base.irqs = dal_irq_service_dce80_create(&init_data);
		if (!pool->base.irqs)
			goto res_create_fail;
	}

	for (i = 0; i < pool->base.pipe_count; i++) {
		pool->base.timing_generators[i] = dce80_timing_generator_create(
				ctx, i, &dce80_tg_offsets[i]);
		if (pool->base.timing_generators[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create tg!\n");
			goto res_create_fail;
		}

		pool->base.mis[i] = dce80_mem_input_create(ctx, i);
		if (pool->base.mis[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create memory input!\n");
			goto res_create_fail;
		}

		pool->base.ipps[i] = dce80_ipp_create(ctx, i);
		if (pool->base.ipps[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create input pixel processor!\n");
			goto res_create_fail;
		}

		pool->base.transforms[i] = dce80_transform_create(ctx, i);
		if (pool->base.transforms[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create transform!\n");
			goto res_create_fail;
		}

		pool->base.opps[i] = dce80_opp_create(ctx, i);
		if (pool->base.opps[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create output pixel processor!\n");
			goto res_create_fail;
		}
	}

	dc->caps.max_planes =  pool->base.pipe_count;
	dc->caps.disable_dp_clk_share = true;

	if (!resource_construct(num_virtual_links, dc, &pool->base,
			&res_create_funcs))
		goto res_create_fail;

	/* Create hardware sequencer */
	dce80_hw_sequencer_construct(dc);

	return true;

res_create_fail:
	destruct(pool);
	return false;
}

struct resource_pool *dce81_create_resource_pool(
	uint8_t num_virtual_links,
	struct dc *dc)
{
	struct dce110_resource_pool *pool =
		kzalloc(sizeof(struct dce110_resource_pool), GFP_KERNEL);

	if (!pool)
		return NULL;

	if (dce81_construct(num_virtual_links, dc, pool))
		return &pool->base;

	BREAK_TO_DEBUGGER();
	return NULL;
}

__attribute__((used)) static bool dce83_construct(
	uint8_t num_virtual_links,
	struct dc *dc,
	struct dce110_resource_pool *pool)
{
	unsigned int i;
	struct dc_context *ctx = dc->ctx;
	struct dc_firmware_info info;
	struct dc_bios *bp;
	struct dm_pp_static_clock_info static_clk_info = {0};

	ctx->dc_bios->regs = &bios_regs;

	pool->base.res_cap = &res_cap_83;
	pool->base.funcs = &dce80_res_pool_funcs;


	/*************************************************
	 *  Resource + asic cap harcoding                *
	 *************************************************/
	pool->base.underlay_pipe_index = NO_UNDERLAY_PIPE;
	pool->base.pipe_count = res_cap_83.num_timing_generator;
	pool->base.timing_generator_count = res_cap_83.num_timing_generator;
	dc->caps.max_downscale_ratio = 200;
	dc->caps.i2c_speed_in_khz = 40;
	dc->caps.max_cursor_size = 128;
	dc->caps.is_apu = true;

	/*************************************************
	 *  Create resources                             *
	 *************************************************/

	bp = ctx->dc_bios;

	if ((bp->funcs->get_firmware_info(bp, &info) == BP_RESULT_OK) &&
		info.external_clock_source_frequency_for_dp != 0) {
		pool->base.dp_clock_source =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_EXTERNAL, NULL, true);

		pool->base.clock_sources[0] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL1, &clk_src_regs[0], false);
		pool->base.clock_sources[1] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL2, &clk_src_regs[1], false);
		pool->base.clk_src_count = 2;

	} else {
		pool->base.dp_clock_source =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL1, &clk_src_regs[0], true);

		pool->base.clock_sources[0] =
				dce80_clock_source_create(ctx, bp, CLOCK_SOURCE_ID_PLL2, &clk_src_regs[1], false);
		pool->base.clk_src_count = 1;
	}

	if (pool->base.dp_clock_source == NULL) {
		dm_error("DC: failed to create dp clock source!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	for (i = 0; i < pool->base.clk_src_count; i++) {
		if (pool->base.clock_sources[i] == NULL) {
			dm_error("DC: failed to create clock sources!\n");
			BREAK_TO_DEBUGGER();
			goto res_create_fail;
		}
	}

	pool->base.dccg = dce_dccg_create(ctx,
			&disp_clk_regs,
			&disp_clk_shift,
			&disp_clk_mask);
	if (pool->base.dccg == NULL) {
		dm_error("DC: failed to create display clock!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	pool->base.dmcu = dce_dmcu_create(ctx,
			&dmcu_regs,
			&dmcu_shift,
			&dmcu_mask);
	if (pool->base.dmcu == NULL) {
		dm_error("DC: failed to create dmcu!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	pool->base.abm = dce_abm_create(ctx,
			&abm_regs,
			&abm_shift,
			&abm_mask);
	if (pool->base.abm == NULL) {
		dm_error("DC: failed to create abm!\n");
		BREAK_TO_DEBUGGER();
		goto res_create_fail;
	}

	if (dm_pp_get_static_clocks(ctx, &static_clk_info))
		pool->base.dccg->max_clks_state =
					static_clk_info.max_clocks_state;

	{
		struct irq_service_init_data init_data;
		init_data.ctx = dc->ctx;
		pool->base.irqs = dal_irq_service_dce80_create(&init_data);
		if (!pool->base.irqs)
			goto res_create_fail;
	}

	for (i = 0; i < pool->base.pipe_count; i++) {
		pool->base.timing_generators[i] = dce80_timing_generator_create(
				ctx, i, &dce80_tg_offsets[i]);
		if (pool->base.timing_generators[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create tg!\n");
			goto res_create_fail;
		}

		pool->base.mis[i] = dce80_mem_input_create(ctx, i);
		if (pool->base.mis[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create memory input!\n");
			goto res_create_fail;
		}

		pool->base.ipps[i] = dce80_ipp_create(ctx, i);
		if (pool->base.ipps[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create input pixel processor!\n");
			goto res_create_fail;
		}

		pool->base.transforms[i] = dce80_transform_create(ctx, i);
		if (pool->base.transforms[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create transform!\n");
			goto res_create_fail;
		}

		pool->base.opps[i] = dce80_opp_create(ctx, i);
		if (pool->base.opps[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create output pixel processor!\n");
			goto res_create_fail;
		}
	}

	dc->caps.max_planes =  pool->base.pipe_count;
	dc->caps.disable_dp_clk_share = true;

	if (!resource_construct(num_virtual_links, dc, &pool->base,
			&res_create_funcs))
		goto res_create_fail;

	/* Create hardware sequencer */
	dce80_hw_sequencer_construct(dc);

	return true;

res_create_fail:
	destruct(pool);
	return false;
}

struct resource_pool *dce83_create_resource_pool(
	uint8_t num_virtual_links,
	struct dc *dc)
{
	struct dce110_resource_pool *pool =
		kzalloc(sizeof(struct dce110_resource_pool), GFP_KERNEL);

	if (!pool)
		return NULL;

	if (dce83_construct(num_virtual_links, dc, pool))
		return &pool->base;

	BREAK_TO_DEBUGGER();
	return NULL;
}

