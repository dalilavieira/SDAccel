#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_8__ ;
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
struct mp_decoder {struct mp_filter* f; } ;
struct TYPE_26__ {scalar_t__ num; } ;
struct priv {double next_pts; int preroll_done; int eof_returned; struct mp_decoder public; TYPE_8__* avframe; scalar_t__ trim_samples; scalar_t__ skip_samples; TYPE_7__ force_channel_map; int /*<<< orphan*/  codec_timebase; TYPE_2__* avctx; } ;
struct mp_frame {int dummy; } ;
struct mp_filter {struct priv* priv; int /*<<< orphan*/  log; int /*<<< orphan*/  global; } ;
struct mp_decoder_list {int dummy; } ;
struct mp_codec_params {TYPE_7__ channels; scalar_t__ force_channels; } ;
struct mp_aframe {int dummy; } ;
struct demux_packet {double pts; } ;
struct ad_lavc_params {int /*<<< orphan*/  threads; int /*<<< orphan*/  avopts; int /*<<< orphan*/  ac3drc; scalar_t__ downmix; } ;
struct TYPE_23__ {int num_chmaps; int /*<<< orphan*/ * chmaps; } ;
struct MPOpts {TYPE_1__ audio_output_channels; } ;
struct TYPE_27__ {int /*<<< orphan*/  pts; int /*<<< orphan*/ * buf; } ;
struct TYPE_25__ {int /*<<< orphan*/  id; } ;
struct TYPE_24__ {scalar_t__ delay; int /*<<< orphan*/  request_channel_layout; int /*<<< orphan*/  codec_id; int /*<<< orphan*/  codec_type; } ;
typedef  int /*<<< orphan*/  AVPacket ;
typedef  TYPE_2__ AVCodecContext ;
typedef  TYPE_3__ AVCodec ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int /*<<< orphan*/  AVMEDIA_TYPE_AUDIO ; 
 int /*<<< orphan*/  AV_OPT_SEARCH_CHILDREN ; 
 int /*<<< orphan*/  EAGAIN ; 
 int /*<<< orphan*/ * GLOBAL_CONFIG ; 
 struct mp_frame MAKE_FRAME (int /*<<< orphan*/ ,struct mp_aframe*) ; 
 scalar_t__ MPMIN (scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  MP_ERR (struct mp_filter*,char*,...) ; 
 int /*<<< orphan*/  MP_FRAME_AUDIO ; 
 double MP_NOPTS_VALUE ; 
 int /*<<< orphan*/  MP_PIN_IN ; 
 int /*<<< orphan*/  MP_PIN_OUT ; 
 int /*<<< orphan*/  ad_lavc_conf ; 
 int /*<<< orphan*/  ad_lavc_filter ; 
 TYPE_8__* av_frame_alloc () ; 
 int /*<<< orphan*/  av_frame_free (TYPE_8__**) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_8__*) ; 
 int /*<<< orphan*/  av_opt_set_double (TYPE_2__*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_2__* avcodec_alloc_context3 (TYPE_3__*) ; 
 TYPE_3__* avcodec_find_decoder_by_name (char const*) ; 
 int /*<<< orphan*/  avcodec_flush_buffers (TYPE_2__*) ; 
 int /*<<< orphan*/  avcodec_free_context (TYPE_2__**) ; 
 scalar_t__ avcodec_open2 (TYPE_2__*,TYPE_3__*,int /*<<< orphan*/ *) ; 
 int avcodec_receive_frame (TYPE_2__*,TYPE_8__*) ; 
 int avcodec_send_packet (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lavc_process (struct mp_filter*,int*,int (*) (struct mp_filter*,struct demux_packet*),int (*) (struct mp_filter*,struct mp_frame*)) ; 
 int /*<<< orphan*/  mp_add_lavc_decoders (struct mp_decoder_list*,int /*<<< orphan*/ ) ; 
 double mp_aframe_end_pts (struct mp_aframe*) ; 
 struct mp_aframe* mp_aframe_from_avframe (TYPE_8__*) ; 
 scalar_t__ mp_aframe_get_size (struct mp_aframe*) ; 
 int /*<<< orphan*/  mp_aframe_set_chmap (struct mp_aframe*,TYPE_7__*) ; 
 int /*<<< orphan*/  mp_aframe_set_pts (struct mp_aframe*,double) ; 
 int /*<<< orphan*/  mp_aframe_set_size (struct mp_aframe*,scalar_t__) ; 
 int /*<<< orphan*/  mp_aframe_skip_samples (struct mp_aframe*,scalar_t__) ; 
 int /*<<< orphan*/  mp_chmap_to_lavc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_filter_add_pin (struct mp_filter*,int /*<<< orphan*/ ,char*) ; 
 struct mp_filter* mp_filter_create (struct mp_filter*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_get_codec_timebase (struct mp_codec_params*) ; 
 void* mp_get_config_group (struct priv*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_log_new (struct mp_filter*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 double mp_pts_from_av (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_set_av_packet (int /*<<< orphan*/ *,struct demux_packet*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_set_avcodec_threads (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mp_set_avctx_codec_headers (TYPE_2__*,struct mp_codec_params*) ; 
 int /*<<< orphan*/  mp_set_avopts (int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  talloc_free (struct mp_filter*) ; 

__attribute__((used)) static bool init(struct mp_filter *da, struct mp_codec_params *codec,
                 const char *decoder)
{
    struct priv *ctx = da->priv;
    struct MPOpts *mpopts = mp_get_config_group(ctx, da->global, GLOBAL_CONFIG);
    struct ad_lavc_params *opts =
        mp_get_config_group(ctx, da->global, &ad_lavc_conf);
    AVCodecContext *lavc_context;
    AVCodec *lavc_codec;

    ctx->codec_timebase = mp_get_codec_timebase(codec);

    if (codec->force_channels)
        ctx->force_channel_map = codec->channels;

    lavc_codec = avcodec_find_decoder_by_name(decoder);
    if (!lavc_codec) {
        MP_ERR(da, "Cannot find codec '%s' in libavcodec...\n", decoder);
        return false;
    }

    lavc_context = avcodec_alloc_context3(lavc_codec);
    ctx->avctx = lavc_context;
    ctx->avframe = av_frame_alloc();
    lavc_context->codec_type = AVMEDIA_TYPE_AUDIO;
    lavc_context->codec_id = lavc_codec->id;

#if LIBAVCODEC_VERSION_MICRO >= 100
    lavc_context->pkt_timebase = ctx->codec_timebase;
#endif

    if (opts->downmix && mpopts->audio_output_channels.num_chmaps == 1) {
        lavc_context->request_channel_layout =
            mp_chmap_to_lavc(&mpopts->audio_output_channels.chmaps[0]);
    }

    // Always try to set - option only exists for AC3 at the moment
    av_opt_set_double(lavc_context, "drc_scale", opts->ac3drc,
                      AV_OPT_SEARCH_CHILDREN);

#if LIBAVCODEC_VERSION_MICRO >= 100
    // Let decoder add AV_FRAME_DATA_SKIP_SAMPLES.
    av_opt_set(lavc_context, "flags2", "+skip_manual", AV_OPT_SEARCH_CHILDREN);
#endif

    mp_set_avopts(da->log, lavc_context, opts->avopts);

    if (mp_set_avctx_codec_headers(lavc_context, codec) < 0) {
        MP_ERR(da, "Could not set decoder parameters.\n");
        return false;
    }

    mp_set_avcodec_threads(da->log, lavc_context, opts->threads);

    /* open it */
    if (avcodec_open2(lavc_context, lavc_codec, NULL) < 0) {
        MP_ERR(da, "Could not open codec.\n");
        return false;
    }

    ctx->next_pts = MP_NOPTS_VALUE;

    return true;
}

__attribute__((used)) static void destroy(struct mp_filter *da)
{
    struct priv *ctx = da->priv;

    avcodec_free_context(&ctx->avctx);
    av_frame_free(&ctx->avframe);
}

__attribute__((used)) static void reset(struct mp_filter *da)
{
    struct priv *ctx = da->priv;

    avcodec_flush_buffers(ctx->avctx);
    ctx->skip_samples = 0;
    ctx->trim_samples = 0;
    ctx->preroll_done = false;
    ctx->next_pts = MP_NOPTS_VALUE;
    ctx->eof_returned = false;
}

__attribute__((used)) static bool send_packet(struct mp_filter *da, struct demux_packet *mpkt)
{
    struct priv *priv = da->priv;
    AVCodecContext *avctx = priv->avctx;

    // If the decoder discards the timestamp for some reason, we use the
    // interpolated PTS. Initialize it so that it works for the initial
    // packet as well.
    if (mpkt && priv->next_pts == MP_NOPTS_VALUE)
        priv->next_pts = mpkt->pts;

    AVPacket pkt;
    mp_set_av_packet(&pkt, mpkt, &priv->codec_timebase);

    int ret = avcodec_send_packet(avctx, mpkt ? &pkt : NULL);

    if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
        return false;

    if (ret < 0)
        MP_ERR(da, "Error decoding audio.\n");
    return true;
}

__attribute__((used)) static bool receive_frame(struct mp_filter *da, struct mp_frame *out)
{
    struct priv *priv = da->priv;
    AVCodecContext *avctx = priv->avctx;

    int ret = avcodec_receive_frame(avctx, priv->avframe);

    if (ret == AVERROR_EOF) {
        // If flushing was initialized earlier and has ended now, make it start
        // over in case we get new packets at some point in the future.
        // (Dont' reset the filter itself, we want to keep other state.)
        avcodec_flush_buffers(priv->avctx);
        return false;
    } else if (ret < 0 && ret != AVERROR(EAGAIN)) {
        MP_ERR(da, "Error decoding audio.\n");
    }

#if LIBAVCODEC_VERSION_MICRO >= 100
    if (priv->avframe->flags & AV_FRAME_FLAG_DISCARD)
        av_frame_unref(priv->avframe);
#endif

    if (!priv->avframe->buf[0])
        return true;

    double out_pts = mp_pts_from_av(priv->avframe->pts, &priv->codec_timebase);

    struct mp_aframe *mpframe = mp_aframe_from_avframe(priv->avframe);
    if (!mpframe)
        return true;

    if (priv->force_channel_map.num)
        mp_aframe_set_chmap(mpframe, &priv->force_channel_map);

    if (out_pts == MP_NOPTS_VALUE)
        out_pts = priv->next_pts;
    mp_aframe_set_pts(mpframe, out_pts);

    priv->next_pts = mp_aframe_end_pts(mpframe);

#if LIBAVCODEC_VERSION_MICRO >= 100
    AVFrameSideData *sd =
        av_frame_get_side_data(priv->avframe, AV_FRAME_DATA_SKIP_SAMPLES);
    if (sd && sd->size >= 10) {
        char *d = sd->data;
        priv->skip_samples += AV_RL32(d + 0);
        priv->trim_samples += AV_RL32(d + 4);
    }
#endif

    if (!priv->preroll_done) {
        // Skip only if this isn't already handled by AV_FRAME_DATA_SKIP_SAMPLES.
        if (!priv->skip_samples)
            priv->skip_samples = avctx->delay;
        priv->preroll_done = true;
    }

    uint32_t skip = MPMIN(priv->skip_samples, mp_aframe_get_size(mpframe));
    if (skip) {
        mp_aframe_skip_samples(mpframe, skip);
        priv->skip_samples -= skip;
    }
    uint32_t trim = MPMIN(priv->trim_samples, mp_aframe_get_size(mpframe));
    if (trim) {
        mp_aframe_set_size(mpframe, mp_aframe_get_size(mpframe) - trim);
        priv->trim_samples -= trim;
    }

    *out = MAKE_FRAME(MP_FRAME_AUDIO, mpframe);

    av_frame_unref(priv->avframe);

    return true;
}

__attribute__((used)) static void process(struct mp_filter *ad)
{
    struct priv *priv = ad->priv;

    lavc_process(ad, &priv->eof_returned, send_packet, receive_frame);
}

__attribute__((used)) static struct mp_decoder *create(struct mp_filter *parent,
                                 struct mp_codec_params *codec,
                                 const char *decoder)
{
    struct mp_filter *da = mp_filter_create(parent, &ad_lavc_filter);
    if (!da)
        return NULL;

    mp_filter_add_pin(da, MP_PIN_IN, "in");
    mp_filter_add_pin(da, MP_PIN_OUT, "out");

    da->log = mp_log_new(da, parent->log, NULL);

    struct priv *priv = da->priv;
    priv->public.f = da;

    if (!init(da, codec, decoder)) {
        talloc_free(da);
        return NULL;
    }
    return &priv->public;
}

__attribute__((used)) static void add_decoders(struct mp_decoder_list *list)
{
    mp_add_lavc_decoders(list, AVMEDIA_TYPE_AUDIO);
}

