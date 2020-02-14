#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  size_t uint32_t ;
struct transform {int dummy; } ;
struct timing_generator {int dummy; } ;
struct stream_encoder {int dummy; } ;
struct resource_straps {void* dc_pinstraps_audio; void* hdmi_disable; void* audio_stream_number; } ;
struct resource_pool {unsigned int pipe_count; unsigned int audio_count; unsigned int stream_enc_count; unsigned int clk_src_count; int timing_generator_count; struct aux_engine** engines; struct output_pixel_processor** opps; struct transform** transforms; struct input_pixel_processor** ipps; struct mem_input** mis; struct timing_generator** timing_generators; int /*<<< orphan*/ * irqs; int /*<<< orphan*/ * abm; int /*<<< orphan*/ * dmcu; int /*<<< orphan*/ * dccg; struct clock_source** clock_sources; struct clock_source* dp_clock_source; int /*<<< orphan*/  underlay_pipe_index; TYPE_4__* res_cap; int /*<<< orphan*/ * funcs; int /*<<< orphan*/ ** stream_enc; scalar_t__* audios; } ;
struct output_pixel_processor {int dummy; } ;
struct mem_input {int dummy; } ;
struct link_encoder {int dummy; } ;
struct irq_service_init_data {struct dc_context* ctx; } ;
struct input_pixel_processor {int dummy; } ;
struct encoder_init_data {size_t transmitter; int channel; size_t hpd_source; } ;
struct dm_pp_wm_sets_with_clock_ranges {int num_wm_sets; TYPE_2__* wm_clk_ranges; int /*<<< orphan*/  member_0; } ;
struct dm_pp_clock_levels_with_latency {int num_levels; TYPE_1__* data; int /*<<< orphan*/  member_0; } ;
struct dce_transform {int lb_memory_size; struct transform base; } ;
struct dce_mem_input {struct mem_input base; } ;
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
struct TYPE_12__ {int /*<<< orphan*/  hw_internal_rev; } ;
struct dc_context {TYPE_6__ asic_id; struct dc_bios* dc_bios; } ;
struct dc_bios {int /*<<< orphan*/ * regs; } ;
struct TYPE_9__ {int max_downscale_ratio; int i2c_speed_in_khz; int max_cursor_size; int dual_link_dvi; int psp_setup_panel_mode; int max_planes; } ;
struct dc {struct dc_context* ctx; TYPE_5__* bw_vbios; int /*<<< orphan*/  bw_dceip; TYPE_3__ caps; int /*<<< orphan*/  debug; } ;
struct aux_engine {int dummy; } ;
struct aux_engine_dce110 {struct aux_engine base; } ;
struct audio {int dummy; } ;
typedef  enum engine_id { ____Placeholder_engine_id } engine_id ;
typedef  enum clock_source_id { ____Placeholder_clock_source_id } clock_source_id ;
struct TYPE_11__ {void* high_yclk; void* mid_yclk; void* low_yclk; void* low_sclk; void* mid6_sclk; void* mid5_sclk; void* mid4_sclk; void* mid3_sclk; void* mid2_sclk; void* mid1_sclk; void* high_sclk; } ;
struct TYPE_10__ {unsigned int num_timing_generator; } ;
struct TYPE_8__ {int wm_min_eng_clk_in_khz; int wm_max_eng_clk_in_khz; int wm_min_mem_clk_in_khz; int wm_max_mem_clk_in_khz; int /*<<< orphan*/  wm_set_id; } ;
struct TYPE_7__ {unsigned int clocks_in_khz; unsigned int latency_in_us; } ;

/* Variables and functions */
 int ASICREV_IS_VEGA20_P (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AUDIO_STREAM_NUMBER ; 
 int AUX_TIMEOUT_PERIOD ; 
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
 int /*<<< orphan*/  CC_DC_MISC_STRAPS ; 
 int CLOCK_SOURCE_COMBO_PHY_PLL0 ; 
 int CLOCK_SOURCE_COMBO_PHY_PLL1 ; 
 int CLOCK_SOURCE_COMBO_PHY_PLL2 ; 
 int CLOCK_SOURCE_COMBO_PHY_PLL3 ; 
 int CLOCK_SOURCE_COMBO_PHY_PLL4 ; 
 int CLOCK_SOURCE_COMBO_PHY_PLL5 ; 
 int CLOCK_SOURCE_ID_DP_DTO ; 
 struct dce110_resource_pool* DCE110STRENC_FROM_STRENC (int /*<<< orphan*/ *) ; 
 struct dce110_resource_pool* DCE110TG_FROM_TG (struct timing_generator*) ; 
 size_t DCE120_CLK_SRC_PLL0 ; 
 size_t DCE120_CLK_SRC_PLL1 ; 
 size_t DCE120_CLK_SRC_PLL2 ; 
 size_t DCE120_CLK_SRC_PLL3 ; 
 size_t DCE120_CLK_SRC_PLL4 ; 
 size_t DCE120_CLK_SRC_PLL5 ; 
 unsigned int DCE120_CLK_SRC_TOTAL ; 
 int /*<<< orphan*/  DC_PINSTRAPS ; 
 int /*<<< orphan*/  DC_PINSTRAPS_AUDIO ; 
 int /*<<< orphan*/  DM_PP_CLOCK_TYPE_ENGINE_CLK ; 
 int /*<<< orphan*/  DM_PP_CLOCK_TYPE_MEMORY_CLK ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HDMI_DISABLE ; 
 int MEMORY_TYPE_MULTIPLIER ; 
 int /*<<< orphan*/  NO_UNDERLAY_PIPE ; 
 int SW_AUX_TIMEOUT_PERIOD_MULTIPLIER ; 
 struct dce110_resource_pool* TO_DCE110_CLK_SRC (struct clock_source*) ; 
 struct dce110_resource_pool* TO_DCE110_RES_POOL (struct resource_pool*) ; 
 struct dce110_resource_pool* TO_DCE_MEM_INPUT (struct mem_input*) ; 
 struct dce110_resource_pool* TO_DCE_TRANSFORM (struct transform*) ; 
 int /*<<< orphan*/  WM_SET_A ; 
 int /*<<< orphan*/  WM_SET_B ; 
 int /*<<< orphan*/  WM_SET_C ; 
 int /*<<< orphan*/  WM_SET_D ; 
 int /*<<< orphan*/  abm_mask ; 
 int /*<<< orphan*/  abm_regs ; 
 int /*<<< orphan*/  abm_shift ; 
 int /*<<< orphan*/  audio_mask ; 
 int /*<<< orphan*/ * audio_regs ; 
 int /*<<< orphan*/  audio_shift ; 
 int /*<<< orphan*/ * aux_engine_regs ; 
 int /*<<< orphan*/  bios_regs ; 
 int /*<<< orphan*/  bw_calcs_init (int /*<<< orphan*/ ,TYPE_5__*,TYPE_6__) ; 
 void* bw_frc_to_fixed (int,int) ; 
 struct dce110_clk_src_regs* clk_src_regs ; 
 int /*<<< orphan*/  cs_mask ; 
 int /*<<< orphan*/  cs_shift ; 
 int /*<<< orphan*/ * dal_irq_service_dce120_create (struct irq_service_init_data*) ; 
 int /*<<< orphan*/  dal_irq_service_destroy (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  dce110_aux_engine_construct (struct aux_engine_dce110*,struct dc_context*,size_t,int,int /*<<< orphan*/ *) ; 
 scalar_t__ dce110_clk_src_construct (struct dce110_clk_src*,struct dc_context*,struct dc_bios*,int,struct dce110_clk_src_regs const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce110_engine_destroy (struct aux_engine**) ; 
 int /*<<< orphan*/  dce110_link_encoder_construct (struct dce110_link_encoder*,struct encoder_init_data const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce110_opp_construct (struct dce110_opp*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce110_opp_destroy (struct output_pixel_processor**) ; 
 int /*<<< orphan*/  dce110_stream_encoder_construct (struct dce110_stream_encoder*,struct dc_context*,struct dc_bios*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * dce120_dccg_create (struct dc_context*) ; 
 int /*<<< orphan*/  dce120_hw_sequencer_construct (struct dc*) ; 
 int /*<<< orphan*/  dce120_mem_input_construct (struct dce_mem_input*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce120_res_pool_funcs ; 
 struct dce110_timing_generator_offsets* dce120_tg_offsets ; 
 int /*<<< orphan*/  dce120_timing_generator_construct (struct dce110_timing_generator*,struct dc_context*,size_t,struct dce110_timing_generator_offsets const*) ; 
 int /*<<< orphan*/ * dce_abm_create (struct dc_context*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_abm_destroy (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  dce_aud_destroy (scalar_t__*) ; 
 struct audio* dce_audio_create (struct dc_context*,unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_dccg_destroy (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/ * dce_dmcu_create (struct dc_context*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_dmcu_destroy (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  dce_ipp_construct (struct dce_ipp*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dce_ipp_destroy (struct input_pixel_processor**) ; 
 int /*<<< orphan*/  dce_transform_construct (struct dce_transform*,struct dc_context*,size_t,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  debug_defaults ; 
 int /*<<< orphan*/  dm_error (char*,...) ; 
 int /*<<< orphan*/  dm_pp_get_clock_levels_by_type_with_latency (struct dc_context*,int /*<<< orphan*/ ,struct dm_pp_clock_levels_with_latency*) ; 
 int /*<<< orphan*/  dm_pp_notify_wm_clock_changes (struct dc_context*,struct dm_pp_wm_sets_with_clock_ranges*) ; 
 size_t dm_read_reg_soc15 (struct dc_context*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dmcu_mask ; 
 int /*<<< orphan*/  dmcu_regs ; 
 int /*<<< orphan*/  dmcu_shift ; 
 void* get_reg_field_value (size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
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
 int /*<<< orphan*/  mmCC_DC_MISC_STRAPS ; 
 int /*<<< orphan*/  mmCC_DC_PIPE_DIS ; 
 int /*<<< orphan*/  mmDC_PINSTRAPS ; 
 int /*<<< orphan*/  opp_mask ; 
 int /*<<< orphan*/ * opp_regs ; 
 int /*<<< orphan*/  opp_shift ; 
 TYPE_4__ res_cap ; 
 int /*<<< orphan*/  res_create_funcs ; 
 int /*<<< orphan*/  resource_construct (int /*<<< orphan*/ ,struct dc*,struct resource_pool*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  se_mask ; 
 int /*<<< orphan*/  se_shift ; 
 int /*<<< orphan*/ * stream_enc_regs ; 
 int /*<<< orphan*/  xfm_mask ; 
 int /*<<< orphan*/ * xfm_regs ; 
 int /*<<< orphan*/  xfm_shift ; 

struct output_pixel_processor *dce120_opp_create(
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

struct aux_engine *dce120_aux_engine_create(
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

struct clock_source *dce120_clock_source_create(
	struct dc_context *ctx,
	struct dc_bios *bios,
	enum clock_source_id id,
	const struct dce110_clk_src_regs *regs,
	bool dp_clk_src)
{
	struct dce110_clk_src *clk_src =
		kzalloc(sizeof(*clk_src), GFP_KERNEL);

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

void dce120_clock_source_destroy(struct clock_source **clk_src)
{
	kfree(TO_DCE110_CLK_SRC(*clk_src));
	*clk_src = NULL;
}

bool dce120_hw_sequencer_create(struct dc *dc)
{
	/* All registers used by dce11.2 match those in dce11 in offset and
	 * structure
	 */
	dce120_hw_sequencer_construct(dc);

	/*TODO	Move to separate file and Override what is needed */

	return true;
}

__attribute__((used)) static struct timing_generator *dce120_timing_generator_create(
		struct dc_context *ctx,
		uint32_t instance,
		const struct dce110_timing_generator_offsets *offsets)
{
	struct dce110_timing_generator *tg110 =
		kzalloc(sizeof(struct dce110_timing_generator), GFP_KERNEL);

	if (!tg110)
		return NULL;

	dce120_timing_generator_construct(tg110, ctx, instance, offsets);
	return &tg110->base;
}

__attribute__((used)) static void dce120_transform_destroy(struct transform **xfm)
{
	kfree(TO_DCE_TRANSFORM(*xfm));
	*xfm = NULL;
}

__attribute__((used)) static void destruct(struct dce110_resource_pool *pool)
{
	unsigned int i;

	for (i = 0; i < pool->base.pipe_count; i++) {
		if (pool->base.opps[i] != NULL)
			dce110_opp_destroy(&pool->base.opps[i]);

		if (pool->base.transforms[i] != NULL)
			dce120_transform_destroy(&pool->base.transforms[i]);

		if (pool->base.ipps[i] != NULL)
			dce_ipp_destroy(&pool->base.ipps[i]);

		if (pool->base.mis[i] != NULL) {
			kfree(TO_DCE_MEM_INPUT(pool->base.mis[i]));
			pool->base.mis[i] = NULL;
		}

		if (pool->base.irqs != NULL) {
			dal_irq_service_destroy(&pool->base.irqs);
		}

		if (pool->base.timing_generators[i] != NULL) {
			kfree(DCE110TG_FROM_TG(pool->base.timing_generators[i]));
			pool->base.timing_generators[i] = NULL;
		}

		if (pool->base.engines[i] != NULL)
			dce110_engine_destroy(&pool->base.engines[i]);

	}

	for (i = 0; i < pool->base.audio_count; i++) {
		if (pool->base.audios[i])
			dce_aud_destroy(&pool->base.audios[i]);
	}

	for (i = 0; i < pool->base.stream_enc_count; i++) {
		if (pool->base.stream_enc[i] != NULL)
			kfree(DCE110STRENC_FROM_STRENC(pool->base.stream_enc[i]));
	}

	for (i = 0; i < pool->base.clk_src_count; i++) {
		if (pool->base.clock_sources[i] != NULL)
			dce120_clock_source_destroy(
				&pool->base.clock_sources[i]);
	}

	if (pool->base.dp_clock_source != NULL)
		dce120_clock_source_destroy(&pool->base.dp_clock_source);

	if (pool->base.abm != NULL)
		dce_abm_destroy(&pool->base.abm);

	if (pool->base.dmcu != NULL)
		dce_dmcu_destroy(&pool->base.dmcu);

	if (pool->base.dccg != NULL)
		dce_dccg_destroy(&pool->base.dccg);
}

__attribute__((used)) static void read_dce_straps(
	struct dc_context *ctx,
	struct resource_straps *straps)
{
	uint32_t reg_val = dm_read_reg_soc15(ctx, mmCC_DC_MISC_STRAPS, 0);

	straps->audio_stream_number = get_reg_field_value(reg_val,
							  CC_DC_MISC_STRAPS,
							  AUDIO_STREAM_NUMBER);
	straps->hdmi_disable = get_reg_field_value(reg_val,
						   CC_DC_MISC_STRAPS,
						   HDMI_DISABLE);

	reg_val = dm_read_reg_soc15(ctx, mmDC_PINSTRAPS, 0);
	straps->dc_pinstraps_audio = get_reg_field_value(reg_val,
							 DC_PINSTRAPS,
							 DC_PINSTRAPS_AUDIO);
}

__attribute__((used)) static struct audio *create_audio(
		struct dc_context *ctx, unsigned int inst)
{
	return dce_audio_create(ctx, inst,
			&audio_regs[inst], &audio_shift, &audio_mask);
}

__attribute__((used)) static struct link_encoder *dce120_link_encoder_create(
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

__attribute__((used)) static struct input_pixel_processor *dce120_ipp_create(
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

__attribute__((used)) static struct stream_encoder *dce120_stream_encoder_create(
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

__attribute__((used)) static struct dce_hwseq *dce120_hwseq_create(
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

__attribute__((used)) static struct mem_input *dce120_mem_input_create(
	struct dc_context *ctx,
	uint32_t inst)
{
	struct dce_mem_input *dce_mi = kzalloc(sizeof(struct dce_mem_input),
					       GFP_KERNEL);

	if (!dce_mi) {
		BREAK_TO_DEBUGGER();
		return NULL;
	}

	dce120_mem_input_construct(dce_mi, ctx, inst, &mi_regs[inst], &mi_shifts, &mi_masks);
	return &dce_mi->base;
}

__attribute__((used)) static struct transform *dce120_transform_create(
	struct dc_context *ctx,
	uint32_t inst)
{
	struct dce_transform *transform =
		kzalloc(sizeof(struct dce_transform), GFP_KERNEL);

	if (!transform)
		return NULL;

	dce_transform_construct(transform, ctx, inst,
				&xfm_regs[inst], &xfm_shift, &xfm_mask);
	transform->lb_memory_size = 0x1404; /*5124*/
	return &transform->base;
}

__attribute__((used)) static void dce120_destroy_resource_pool(struct resource_pool **pool)
{
	struct dce110_resource_pool *dce110_pool = TO_DCE110_RES_POOL(*pool);

	destruct(dce110_pool);
	kfree(dce110_pool);
	*pool = NULL;
}

__attribute__((used)) static void bw_calcs_data_update_from_pplib(struct dc *dc)
{
	struct dm_pp_clock_levels_with_latency eng_clks = {0};
	struct dm_pp_clock_levels_with_latency mem_clks = {0};
	struct dm_pp_wm_sets_with_clock_ranges clk_ranges = {0};
	int i;
	unsigned int clk;
	unsigned int latency;

	/*do system clock*/
	if (!dm_pp_get_clock_levels_by_type_with_latency(
				dc->ctx,
				DM_PP_CLOCK_TYPE_ENGINE_CLK,
				&eng_clks) || eng_clks.num_levels == 0) {

		eng_clks.num_levels = 8;
		clk = 300000;

		for (i = 0; i < eng_clks.num_levels; i++) {
			eng_clks.data[i].clocks_in_khz = clk;
			clk += 100000;
		}
	}

	/* convert all the clock fro kHz to fix point mHz  TODO: wloop data */
	dc->bw_vbios->high_sclk = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels-1].clocks_in_khz, 1000);
	dc->bw_vbios->mid1_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid2_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*2/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid3_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid4_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*4/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid5_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*5/8].clocks_in_khz, 1000);
	dc->bw_vbios->mid6_sclk  = bw_frc_to_fixed(
		eng_clks.data[eng_clks.num_levels*6/8].clocks_in_khz, 1000);
	dc->bw_vbios->low_sclk  = bw_frc_to_fixed(
			eng_clks.data[0].clocks_in_khz, 1000);

	/*do memory clock*/
	if (!dm_pp_get_clock_levels_by_type_with_latency(
			dc->ctx,
			DM_PP_CLOCK_TYPE_MEMORY_CLK,
			&mem_clks) || mem_clks.num_levels == 0) {

		mem_clks.num_levels = 3;
		clk = 250000;
		latency = 45;

		for (i = 0; i < eng_clks.num_levels; i++) {
			mem_clks.data[i].clocks_in_khz = clk;
			mem_clks.data[i].latency_in_us = latency;
			clk += 500000;
			latency -= 5;
		}

	}

	/* we don't need to call PPLIB for validation clock since they
	 * also give us the highest sclk and highest mclk (UMA clock).
	 * ALSO always convert UMA clock (from PPLIB)  to YCLK (HW formula):
	 * YCLK = UMACLK*m_memoryTypeMultiplier
	 */
	dc->bw_vbios->low_yclk = bw_frc_to_fixed(
		mem_clks.data[0].clocks_in_khz * MEMORY_TYPE_MULTIPLIER, 1000);
	dc->bw_vbios->mid_yclk = bw_frc_to_fixed(
		mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz * MEMORY_TYPE_MULTIPLIER,
		1000);
	dc->bw_vbios->high_yclk = bw_frc_to_fixed(
		mem_clks.data[mem_clks.num_levels-1].clocks_in_khz * MEMORY_TYPE_MULTIPLIER,
		1000);

	/* Now notify PPLib/SMU about which Watermarks sets they should select
	 * depending on DPM state they are in. And update BW MGR GFX Engine and
	 * Memory clock member variables for Watermarks calculations for each
	 * Watermark Set
	 */
	clk_ranges.num_wm_sets = 4;
	clk_ranges.wm_clk_ranges[0].wm_set_id = WM_SET_A;
	clk_ranges.wm_clk_ranges[0].wm_min_eng_clk_in_khz =
			eng_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[0].wm_max_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz - 1;
	clk_ranges.wm_clk_ranges[0].wm_min_mem_clk_in_khz =
			mem_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[0].wm_max_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz - 1;

	clk_ranges.wm_clk_ranges[1].wm_set_id = WM_SET_B;
	clk_ranges.wm_clk_ranges[1].wm_min_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz;
	/* 5 GHz instead of data[7].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[1].wm_max_eng_clk_in_khz = 5000000;
	clk_ranges.wm_clk_ranges[1].wm_min_mem_clk_in_khz =
			mem_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[1].wm_max_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz - 1;

	clk_ranges.wm_clk_ranges[2].wm_set_id = WM_SET_C;
	clk_ranges.wm_clk_ranges[2].wm_min_eng_clk_in_khz =
			eng_clks.data[0].clocks_in_khz;
	clk_ranges.wm_clk_ranges[2].wm_max_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz - 1;
	clk_ranges.wm_clk_ranges[2].wm_min_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz;
	/* 5 GHz instead of data[2].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[2].wm_max_mem_clk_in_khz = 5000000;

	clk_ranges.wm_clk_ranges[3].wm_set_id = WM_SET_D;
	clk_ranges.wm_clk_ranges[3].wm_min_eng_clk_in_khz =
			eng_clks.data[eng_clks.num_levels*3/8].clocks_in_khz;
	/* 5 GHz instead of data[7].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[3].wm_max_eng_clk_in_khz = 5000000;
	clk_ranges.wm_clk_ranges[3].wm_min_mem_clk_in_khz =
			mem_clks.data[mem_clks.num_levels>>1].clocks_in_khz;
	/* 5 GHz instead of data[2].clockInKHz to cover Overdrive */
	clk_ranges.wm_clk_ranges[3].wm_max_mem_clk_in_khz = 5000000;

	/* Notify PP Lib/SMU which Watermarks to use for which clock ranges */
	dm_pp_notify_wm_clock_changes(dc->ctx, &clk_ranges);
}

__attribute__((used)) static uint32_t read_pipe_fuses(struct dc_context *ctx)
{
	uint32_t value = dm_read_reg_soc15(ctx, mmCC_DC_PIPE_DIS, 0);
	/* VG20 support max 6 pipes */
	value = value & 0x3f;
	return value;
}

__attribute__((used)) static bool construct(
	uint8_t num_virtual_links,
	struct dc *dc,
	struct dce110_resource_pool *pool)
{
	unsigned int i;
	int j;
	struct dc_context *ctx = dc->ctx;
	struct irq_service_init_data irq_init_data;
	bool harvest_enabled = ASICREV_IS_VEGA20_P(ctx->asic_id.hw_internal_rev);
	uint32_t pipe_fuses;

	ctx->dc_bios->regs = &bios_regs;

	pool->base.res_cap = &res_cap;
	pool->base.funcs = &dce120_res_pool_funcs;

	/* TODO: Fill more data from GreenlandAsicCapability.cpp */
	pool->base.pipe_count = res_cap.num_timing_generator;
	pool->base.timing_generator_count = pool->base.res_cap->num_timing_generator;
	pool->base.underlay_pipe_index = NO_UNDERLAY_PIPE;

	dc->caps.max_downscale_ratio = 200;
	dc->caps.i2c_speed_in_khz = 100;
	dc->caps.max_cursor_size = 128;
	dc->caps.dual_link_dvi = true;
	dc->caps.psp_setup_panel_mode = true;

	dc->debug = debug_defaults;

	/*************************************************
	 *  Create resources                             *
	 *************************************************/

	pool->base.clock_sources[DCE120_CLK_SRC_PLL0] =
			dce120_clock_source_create(ctx, ctx->dc_bios,
				CLOCK_SOURCE_COMBO_PHY_PLL0,
				&clk_src_regs[0], false);
	pool->base.clock_sources[DCE120_CLK_SRC_PLL1] =
			dce120_clock_source_create(ctx, ctx->dc_bios,
				CLOCK_SOURCE_COMBO_PHY_PLL1,
				&clk_src_regs[1], false);
	pool->base.clock_sources[DCE120_CLK_SRC_PLL2] =
			dce120_clock_source_create(ctx, ctx->dc_bios,
				CLOCK_SOURCE_COMBO_PHY_PLL2,
				&clk_src_regs[2], false);
	pool->base.clock_sources[DCE120_CLK_SRC_PLL3] =
			dce120_clock_source_create(ctx, ctx->dc_bios,
				CLOCK_SOURCE_COMBO_PHY_PLL3,
				&clk_src_regs[3], false);
	pool->base.clock_sources[DCE120_CLK_SRC_PLL4] =
			dce120_clock_source_create(ctx, ctx->dc_bios,
				CLOCK_SOURCE_COMBO_PHY_PLL4,
				&clk_src_regs[4], false);
	pool->base.clock_sources[DCE120_CLK_SRC_PLL5] =
			dce120_clock_source_create(ctx, ctx->dc_bios,
				CLOCK_SOURCE_COMBO_PHY_PLL5,
				&clk_src_regs[5], false);
	pool->base.clk_src_count = DCE120_CLK_SRC_TOTAL;

	pool->base.dp_clock_source =
			dce120_clock_source_create(ctx, ctx->dc_bios,
				CLOCK_SOURCE_ID_DP_DTO,
				&clk_src_regs[0], true);

	for (i = 0; i < pool->base.clk_src_count; i++) {
		if (pool->base.clock_sources[i] == NULL) {
			dm_error("DC: failed to create clock sources!\n");
			BREAK_TO_DEBUGGER();
			goto clk_src_create_fail;
		}
	}

	pool->base.dccg = dce120_dccg_create(ctx);
	if (pool->base.dccg == NULL) {
		dm_error("DC: failed to create display clock!\n");
		BREAK_TO_DEBUGGER();
		goto dccg_create_fail;
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

	irq_init_data.ctx = dc->ctx;
	pool->base.irqs = dal_irq_service_dce120_create(&irq_init_data);
	if (!pool->base.irqs)
		goto irqs_create_fail;

	/* retrieve valid pipe fuses */
	if (harvest_enabled)
		pipe_fuses = read_pipe_fuses(ctx);

	/* index to valid pipe resource */
	j = 0;
	for (i = 0; i < pool->base.pipe_count; i++) {
		if (harvest_enabled) {
			if ((pipe_fuses & (1 << i)) != 0) {
				dm_error("DC: skip invalid pipe %d!\n", i);
				continue;
			}
		}

		pool->base.timing_generators[j] =
				dce120_timing_generator_create(
					ctx,
					i,
					&dce120_tg_offsets[i]);
		if (pool->base.timing_generators[j] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error("DC: failed to create tg!\n");
			goto controller_create_fail;
		}

		pool->base.mis[j] = dce120_mem_input_create(ctx, i);

		if (pool->base.mis[j] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error(
				"DC: failed to create memory input!\n");
			goto controller_create_fail;
		}

		pool->base.ipps[j] = dce120_ipp_create(ctx, i);
		if (pool->base.ipps[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error(
				"DC: failed to create input pixel processor!\n");
			goto controller_create_fail;
		}

		pool->base.transforms[j] = dce120_transform_create(ctx, i);
		if (pool->base.transforms[i] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error(
				"DC: failed to create transform!\n");
			goto res_create_fail;
		}

		pool->base.opps[j] = dce120_opp_create(
			ctx,
			i);
		if (pool->base.opps[j] == NULL) {
			BREAK_TO_DEBUGGER();
			dm_error(
				"DC: failed to create output pixel processor!\n");
		}
		pool->base.engines[i] = dce120_aux_engine_create(ctx, i);
				if (pool->base.engines[i] == NULL) {
					BREAK_TO_DEBUGGER();
					dm_error(
						"DC:failed to create aux engine!!\n");
					goto res_create_fail;
				}

		/* check next valid pipe */
		j++;
	}

	/* valid pipe num */
	pool->base.pipe_count = j;
	pool->base.timing_generator_count = j;

	if (!resource_construct(num_virtual_links, dc, &pool->base,
			 &res_create_funcs))
		goto res_create_fail;

	/* Create hardware sequencer */
	if (!dce120_hw_sequencer_create(dc))
		goto controller_create_fail;

	dc->caps.max_planes =  pool->base.pipe_count;

	bw_calcs_init(dc->bw_dceip, dc->bw_vbios, dc->ctx->asic_id);

	bw_calcs_data_update_from_pplib(dc);

	return true;

irqs_create_fail:
controller_create_fail:
dccg_create_fail:
clk_src_create_fail:
res_create_fail:

	destruct(pool);

	return false;
}

struct resource_pool *dce120_create_resource_pool(
	uint8_t num_virtual_links,
	struct dc *dc)
{
	struct dce110_resource_pool *pool =
		kzalloc(sizeof(struct dce110_resource_pool), GFP_KERNEL);

	if (!pool)
		return NULL;

	if (construct(num_virtual_links, dc, pool))
		return &pool->base;

	BREAK_TO_DEBUGGER();
	return NULL;
}

