#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_6__ ;
typedef  struct TYPE_23__   TYPE_5__ ;
typedef  struct TYPE_22__   TYPE_4__ ;
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* th_ycbcr_buffer ;
struct TYPE_20__ {int bytes; int granulepos; int /*<<< orphan*/  packet; } ;
typedef  TYPE_2__ ogg_packet ;
struct TYPE_21__ {int keyframe_mask; int /*<<< orphan*/  t_state; scalar_t__ uv_vshift; scalar_t__ uv_hshift; } ;
typedef  TYPE_3__ TheoraContext ;
struct TYPE_24__ {int extradata_size; int flags; int /*<<< orphan*/  height; int /*<<< orphan*/  width; TYPE_3__* priv_data; scalar_t__ extradata; } ;
struct TYPE_23__ {int /*<<< orphan*/  pts; int /*<<< orphan*/ * data; int /*<<< orphan*/ * linesize; } ;
struct TYPE_22__ {int /*<<< orphan*/  flags; int /*<<< orphan*/  dts; int /*<<< orphan*/  pts; scalar_t__ data; } ;
struct TYPE_19__ {int width; int height; int /*<<< orphan*/  data; int /*<<< orphan*/  stride; } ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVFrame ;
typedef  TYPE_6__ AVCodecContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EXTERNAL ; 
 int AVERROR_INVALIDDATA ; 
 int AV_CODEC_FLAG_PASS1 ; 
 int AV_CODEC_FLAG_PASS2 ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PKT_FLAG_KEY ; 
 int /*<<< orphan*/  AV_WB16 (scalar_t__,int) ; 
 int /*<<< orphan*/  ENOSUP ; 
 int FFALIGN (int /*<<< orphan*/ ,int) ; 
#define  TH_EINVAL 128 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*,...) ; 
 int av_reallocp (scalar_t__*,int) ; 
 int ff_alloc_packet2 (TYPE_6__*,TYPE_4__*,unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int th_encode_packetout (int /*<<< orphan*/ ,int,TYPE_2__*) ; 
 int th_encode_ycbcr_in (int /*<<< orphan*/ ,TYPE_1__*) ; 

__attribute__((used)) static int concatenate_packet(unsigned int* offset,
                              AVCodecContext* avc_context,
                              const ogg_packet* packet)
{
    const char* message = NULL;
    int newsize = avc_context->extradata_size + 2 + packet->bytes;
    int err = AVERROR_INVALIDDATA;

    if (packet->bytes < 0) {
        message = "ogg_packet has negative size";
    } else if (packet->bytes > 0xffff) {
        message = "ogg_packet is larger than 65535 bytes";
    } else if (newsize < avc_context->extradata_size) {
        message = "extradata_size would overflow";
    } else {
        if ((err = av_reallocp(&avc_context->extradata, newsize)) < 0) {
            avc_context->extradata_size = 0;
            message = "av_realloc failed";
        }
    }
    if (message) {
        av_log(avc_context, AV_LOG_ERROR, "concatenate_packet failed: %s\n", message);
        return err;
    }

    avc_context->extradata_size = newsize;
    AV_WB16(avc_context->extradata + (*offset), packet->bytes);
    *offset += 2;
    memcpy(avc_context->extradata + (*offset), packet->packet, packet->bytes);
    (*offset) += packet->bytes;
    return 0;
}

__attribute__((used)) static int get_stats(AVCodecContext *avctx, int eos)
{
#ifdef TH_ENCCTL_2PASS_OUT
    TheoraContext *h = avctx->priv_data;
    uint8_t *buf;
    int bytes;

    bytes = th_encode_ctl(h->t_state, TH_ENCCTL_2PASS_OUT, &buf, sizeof(buf));
    if (bytes < 0) {
        av_log(avctx, AV_LOG_ERROR, "Error getting first pass stats\n");
        return AVERROR_EXTERNAL;
    }
    if (!eos) {
        void *tmp = av_fast_realloc(h->stats, &h->stats_size,
                                   h->stats_offset + bytes);
        if (!tmp)
            return AVERROR(ENOMEM);
        h->stats = tmp;
        memcpy(h->stats + h->stats_offset, buf, bytes);
        h->stats_offset += bytes;
    } else {
        int b64_size = AV_BASE64_SIZE(h->stats_offset);
        // libtheora generates a summary header at the end
        memcpy(h->stats, buf, bytes);
        avctx->stats_out = av_malloc(b64_size);
        if (!avctx->stats_out)
            return AVERROR(ENOMEM);
        av_base64_encode(avctx->stats_out, b64_size, h->stats, h->stats_offset);
    }
    return 0;
#else
    av_log(avctx, AV_LOG_ERROR, "libtheora too old to support 2pass\n");
    return AVERROR(ENOSUP);
#endif
}

__attribute__((used)) static int submit_stats(AVCodecContext *avctx)
{
#ifdef TH_ENCCTL_2PASS_IN
    TheoraContext *h = avctx->priv_data;
    int bytes;
    if (!h->stats) {
        if (!avctx->stats_in) {
            av_log(avctx, AV_LOG_ERROR, "No statsfile for second pass\n");
            return AVERROR(EINVAL);
        }
        h->stats_size = strlen(avctx->stats_in) * 3/4;
        h->stats      = av_malloc(h->stats_size);
        if (!h->stats) {
            h->stats_size = 0;
            return AVERROR(ENOMEM);
        }
        h->stats_size = av_base64_decode(h->stats, avctx->stats_in, h->stats_size);
    }
    while (h->stats_size - h->stats_offset > 0) {
        bytes = th_encode_ctl(h->t_state, TH_ENCCTL_2PASS_IN,
                              h->stats + h->stats_offset,
                              h->stats_size - h->stats_offset);
        if (bytes < 0) {
            av_log(avctx, AV_LOG_ERROR, "Error submitting stats\n");
            return AVERROR_EXTERNAL;
        }
        if (!bytes)
            return 0;
        h->stats_offset += bytes;
    }
    return 0;
#else
    av_log(avctx, AV_LOG_ERROR, "libtheora too old to support 2pass\n");
    return AVERROR(ENOSUP);
#endif
}

__attribute__((used)) static int encode_frame(AVCodecContext* avc_context, AVPacket *pkt,
                        const AVFrame *frame, int *got_packet)
{
    th_ycbcr_buffer t_yuv_buffer;
    TheoraContext *h = avc_context->priv_data;
    ogg_packet o_packet;
    int result, i, ret;

    // EOS, finish and get 1st pass stats if applicable
    if (!frame) {
        th_encode_packetout(h->t_state, 1, &o_packet);
        if (avc_context->flags & AV_CODEC_FLAG_PASS1)
            if ((ret = get_stats(avc_context, 1)) < 0)
                return ret;
        return 0;
    }

    /* Copy planes to the theora yuv_buffer */
    for (i = 0; i < 3; i++) {
        t_yuv_buffer[i].width  = FFALIGN(avc_context->width,  16) >> (i && h->uv_hshift);
        t_yuv_buffer[i].height = FFALIGN(avc_context->height, 16) >> (i && h->uv_vshift);
        t_yuv_buffer[i].stride = frame->linesize[i];
        t_yuv_buffer[i].data   = frame->data[i];
    }

    if (avc_context->flags & AV_CODEC_FLAG_PASS2)
        if ((ret = submit_stats(avc_context)) < 0)
            return ret;

    /* Now call into theora_encode_YUVin */
    result = th_encode_ycbcr_in(h->t_state, t_yuv_buffer);
    if (result) {
        const char* message;
        switch (result) {
        case -1:
            message = "differing frame sizes";
            break;
        case TH_EINVAL:
            message = "encoder is not ready or is finished";
            break;
        default:
            message = "unknown reason";
            break;
        }
        av_log(avc_context, AV_LOG_ERROR, "theora_encode_YUVin failed (%s) [%d]\n", message, result);
        return AVERROR_EXTERNAL;
    }

    if (avc_context->flags & AV_CODEC_FLAG_PASS1)
        if ((ret = get_stats(avc_context, 0)) < 0)
            return ret;

    /* Pick up returned ogg_packet */
    result = th_encode_packetout(h->t_state, 0, &o_packet);
    switch (result) {
    case 0:
        /* No packet is ready */
        return 0;
    case 1:
        /* Success, we have a packet */
        break;
    default:
        av_log(avc_context, AV_LOG_ERROR, "theora_encode_packetout failed [%d]\n", result);
        return AVERROR_EXTERNAL;
    }

    /* Copy ogg_packet content out to buffer */
    if ((ret = ff_alloc_packet2(avc_context, pkt, o_packet.bytes, 0)) < 0)
        return ret;
    memcpy(pkt->data, o_packet.packet, o_packet.bytes);

    // HACK: assumes no encoder delay, this is true until libtheora becomes
    // multithreaded (which will be disabled unless explicitly requested)
    pkt->pts = pkt->dts = frame->pts;
#if FF_API_CODED_FRAME
FF_DISABLE_DEPRECATION_WARNINGS
    avc_context->coded_frame->key_frame = !(o_packet.granulepos & h->keyframe_mask);
FF_ENABLE_DEPRECATION_WARNINGS
#endif
    if (!(o_packet.granulepos & h->keyframe_mask))
        pkt->flags |= AV_PKT_FLAG_KEY;
    *got_packet = 1;

    return 0;
}

