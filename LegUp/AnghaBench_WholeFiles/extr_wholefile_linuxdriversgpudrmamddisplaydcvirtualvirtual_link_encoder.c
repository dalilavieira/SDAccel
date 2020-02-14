#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  uint32_t ;
struct link_training_settings {int dummy; } ;
struct link_mst_stream_allocation_table {int dummy; } ;
struct link_encoder {int /*<<< orphan*/  preferred_engine; int /*<<< orphan*/  output_signals; int /*<<< orphan*/  transmitter; int /*<<< orphan*/  connector; int /*<<< orphan*/  hpd_source; int /*<<< orphan*/  id; int /*<<< orphan*/  ctx; int /*<<< orphan*/ * funcs; } ;
struct encoder_set_dp_phy_pattern_param {int dummy; } ;
struct encoder_init_data {int /*<<< orphan*/  transmitter; int /*<<< orphan*/  connector; int /*<<< orphan*/  hpd_source; int /*<<< orphan*/  encoder; int /*<<< orphan*/  ctx; } ;
struct dc_stream_state {int dummy; } ;
struct dc_link_settings {int dummy; } ;
typedef  enum signal_type { ____Placeholder_signal_type } signal_type ;
typedef  enum engine_id { ____Placeholder_engine_id } engine_id ;
typedef  enum dc_color_depth { ____Placeholder_dc_color_depth } dc_color_depth ;
typedef  enum clock_source_id { ____Placeholder_clock_source_id } clock_source_id ;

/* Variables and functions */
 int /*<<< orphan*/  ENGINE_ID_VIRTUAL ; 
 int /*<<< orphan*/  SIGNAL_TYPE_VIRTUAL ; 
 int /*<<< orphan*/  kfree (struct link_encoder*) ; 
 int /*<<< orphan*/  virtual_lnk_enc_funcs ; 

__attribute__((used)) static bool virtual_link_encoder_validate_output_with_stream(
	struct link_encoder *enc,
	const struct dc_stream_state *stream) { return true; }

__attribute__((used)) static void virtual_link_encoder_hw_init(struct link_encoder *enc) {}

__attribute__((used)) static void virtual_link_encoder_setup(
	struct link_encoder *enc,
	enum signal_type signal) {}

__attribute__((used)) static void virtual_link_encoder_enable_tmds_output(
	struct link_encoder *enc,
	enum clock_source_id clock_source,
	enum dc_color_depth color_depth,
	enum signal_type signal,
	uint32_t pixel_clock) {}

__attribute__((used)) static void virtual_link_encoder_enable_dp_output(
	struct link_encoder *enc,
	const struct dc_link_settings *link_settings,
	enum clock_source_id clock_source) {}

__attribute__((used)) static void virtual_link_encoder_enable_dp_mst_output(
	struct link_encoder *enc,
	const struct dc_link_settings *link_settings,
	enum clock_source_id clock_source) {}

__attribute__((used)) static void virtual_link_encoder_disable_output(
	struct link_encoder *link_enc,
	enum signal_type signal) {}

__attribute__((used)) static void virtual_link_encoder_dp_set_lane_settings(
	struct link_encoder *enc,
	const struct link_training_settings *link_settings) {}

__attribute__((used)) static void virtual_link_encoder_dp_set_phy_pattern(
	struct link_encoder *enc,
	const struct encoder_set_dp_phy_pattern_param *param) {}

__attribute__((used)) static void virtual_link_encoder_update_mst_stream_allocation_table(
	struct link_encoder *enc,
	const struct link_mst_stream_allocation_table *table) {}

__attribute__((used)) static void virtual_link_encoder_connect_dig_be_to_fe(
	struct link_encoder *enc,
	enum engine_id engine,
	bool connect) {}

__attribute__((used)) static void virtual_link_encoder_destroy(struct link_encoder **enc)
{
	kfree(*enc);
	*enc = NULL;
}

bool virtual_link_encoder_construct(
	struct link_encoder *enc, const struct encoder_init_data *init_data)
{
	enc->funcs = &virtual_lnk_enc_funcs;
	enc->ctx = init_data->ctx;
	enc->id = init_data->encoder;

	enc->hpd_source = init_data->hpd_source;
	enc->connector = init_data->connector;

	enc->transmitter = init_data->transmitter;

	enc->output_signals = SIGNAL_TYPE_VIRTUAL;

	enc->preferred_engine = ENGINE_ID_VIRTUAL;

	return true;
}

