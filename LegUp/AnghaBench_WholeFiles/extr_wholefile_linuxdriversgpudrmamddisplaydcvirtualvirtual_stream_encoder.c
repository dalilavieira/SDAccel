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
struct stream_encoder {struct dc_bios* bp; int /*<<< orphan*/  id; struct dc_context* ctx; int /*<<< orphan*/ * funcs; } ;
struct fixed31_32 {int dummy; } ;
struct encoder_unblank_param {int dummy; } ;
struct encoder_info_frame {int dummy; } ;
struct dc_crtc_timing {int dummy; } ;
struct dc_context {int dummy; } ;
struct dc_bios {int dummy; } ;
typedef  enum dc_color_space { ____Placeholder_dc_color_space } dc_color_space ;

/* Variables and functions */
 int /*<<< orphan*/  BREAK_TO_DEBUGGER () ; 
 int /*<<< orphan*/  ENGINE_ID_VIRTUAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  kfree (struct stream_encoder*) ; 
 struct stream_encoder* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  virtual_str_enc_funcs ; 

__attribute__((used)) static void virtual_stream_encoder_dp_set_stream_attribute(
	struct stream_encoder *enc,
	struct dc_crtc_timing *crtc_timing,
	enum dc_color_space output_color_space) {}

__attribute__((used)) static void virtual_stream_encoder_hdmi_set_stream_attribute(
	struct stream_encoder *enc,
	struct dc_crtc_timing *crtc_timing,
	int actual_pix_clk_khz,
	bool enable_audio) {}

__attribute__((used)) static void virtual_stream_encoder_dvi_set_stream_attribute(
	struct stream_encoder *enc,
	struct dc_crtc_timing *crtc_timing,
	bool is_dual_link) {}

__attribute__((used)) static void virtual_stream_encoder_set_mst_bandwidth(
	struct stream_encoder *enc,
	struct fixed31_32 avg_time_slots_per_mtp) {}

__attribute__((used)) static void virtual_stream_encoder_update_hdmi_info_packets(
	struct stream_encoder *enc,
	const struct encoder_info_frame *info_frame) {}

__attribute__((used)) static void virtual_stream_encoder_stop_hdmi_info_packets(
	struct stream_encoder *enc) {}

__attribute__((used)) static void virtual_stream_encoder_set_avmute(
	struct stream_encoder *enc,
	bool enable) {}

__attribute__((used)) static void virtual_stream_encoder_update_dp_info_packets(
	struct stream_encoder *enc,
	const struct encoder_info_frame *info_frame) {}

__attribute__((used)) static void virtual_stream_encoder_stop_dp_info_packets(
	struct stream_encoder *enc) {}

__attribute__((used)) static void virtual_stream_encoder_dp_blank(
	struct stream_encoder *enc) {}

__attribute__((used)) static void virtual_stream_encoder_dp_unblank(
	struct stream_encoder *enc,
	const struct encoder_unblank_param *param) {}

__attribute__((used)) static void virtual_audio_mute_control(
	struct stream_encoder *enc,
	bool mute) {}

bool virtual_stream_encoder_construct(
	struct stream_encoder *enc,
	struct dc_context *ctx,
	struct dc_bios *bp)
{
	if (!enc)
		return false;
	if (!bp)
		return false;

	enc->funcs = &virtual_str_enc_funcs;
	enc->ctx = ctx;
	enc->id = ENGINE_ID_VIRTUAL;
	enc->bp = bp;

	return true;
}

struct stream_encoder *virtual_stream_encoder_create(
	struct dc_context *ctx, struct dc_bios *bp)
{
	struct stream_encoder *enc = kzalloc(sizeof(*enc), GFP_KERNEL);

	if (!enc)
		return NULL;

	if (virtual_stream_encoder_construct(enc, ctx, bp))
		return enc;

	BREAK_TO_DEBUGGER();
	kfree(enc);
	return NULL;
}

