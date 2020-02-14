#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_39__   TYPE_8__ ;
typedef  struct TYPE_38__   TYPE_6__ ;
typedef  struct TYPE_37__   TYPE_5__ ;
typedef  struct TYPE_36__   TYPE_4__ ;
typedef  struct TYPE_35__   TYPE_2__ ;
typedef  struct TYPE_34__   TYPE_1__ ;
typedef  struct TYPE_33__   TYPE_18__ ;

/* Type definitions */
struct TYPE_35__ {int extradata_updated; TYPE_18__* ctx; int /*<<< orphan*/  args; TYPE_8__ const* filter; struct TYPE_35__* priv_data; } ;
typedef  TYPE_2__ uint8_t ;
struct TYPE_39__ {scalar_t__ priv_class; } ;
struct TYPE_38__ {int extradata_size; TYPE_2__* extradata; int /*<<< orphan*/  time_base; } ;
struct TYPE_37__ {char* name; } ;
struct TYPE_36__ {int size; TYPE_2__* data; int /*<<< orphan*/  member_0; } ;
struct TYPE_34__ {int extradata_size; TYPE_2__* extradata; } ;
struct TYPE_33__ {TYPE_1__* par_out; int /*<<< orphan*/  priv_data; int /*<<< orphan*/  time_base_in; int /*<<< orphan*/  par_in; } ;
typedef  TYPE_2__ BSFCompatContext ;
typedef  TYPE_4__ AVPacket ;
typedef  TYPE_5__ AVOption ;
typedef  TYPE_6__ AVCodecContext ;
typedef  TYPE_2__ AVBitStreamFilterContext ;
typedef  TYPE_8__ AVBitStreamFilter ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int AV_INPUT_BUFFER_PADDING_SIZE ; 
 int /*<<< orphan*/  EAGAIN ; 
 int /*<<< orphan*/  ENOMEM ; 
 int av_bsf_alloc (TYPE_8__ const*,TYPE_18__**) ; 
 int /*<<< orphan*/  av_bsf_free (TYPE_18__**) ; 
 TYPE_8__* av_bsf_get_by_name (char const*) ; 
 int av_bsf_init (TYPE_18__*) ; 
 int av_bsf_receive_packet (TYPE_18__*,TYPE_4__*) ; 
 int av_bsf_send_packet (TYPE_18__*,TYPE_4__*) ; 
 int /*<<< orphan*/  av_free (TYPE_2__*) ; 
 int /*<<< orphan*/  av_freep (TYPE_2__**) ; 
 TYPE_2__* av_malloc (int) ; 
 void* av_mallocz (int) ; 
 TYPE_5__* av_opt_next (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int av_opt_set_from_string (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char const**,char*,char*) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_4__*) ; 
 int avcodec_parameters_from_context (int /*<<< orphan*/ ,TYPE_6__*) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,TYPE_2__*,int) ; 
 int /*<<< orphan*/  strstr (char const*,char*) ; 

void av_register_bitstream_filter(AVBitStreamFilter *bsf)
{
}

AVBitStreamFilterContext *av_bitstream_filter_init(const char *name)
{
    AVBitStreamFilterContext *ctx = NULL;
    BSFCompatContext         *priv = NULL;
    const AVBitStreamFilter *bsf;

    bsf = av_bsf_get_by_name(name);
    if (!bsf)
        return NULL;

    ctx = av_mallocz(sizeof(*ctx));
    if (!ctx)
        return NULL;

    priv = av_mallocz(sizeof(*priv));
    if (!priv)
        goto fail;


    ctx->filter    = bsf;
    ctx->priv_data = priv;

    return ctx;

fail:
    if (priv)
        av_bsf_free(&priv->ctx);
    av_freep(&priv);
    av_freep(&ctx);
    return NULL;
}

void av_bitstream_filter_close(AVBitStreamFilterContext *bsfc)
{
    BSFCompatContext *priv;

    if (!bsfc)
        return;

    priv = bsfc->priv_data;

    av_bsf_free(&priv->ctx);
    av_freep(&bsfc->priv_data);
    av_free(bsfc);
}

int av_bitstream_filter_filter(AVBitStreamFilterContext *bsfc,
                               AVCodecContext *avctx, const char *args,
                               uint8_t **poutbuf, int *poutbuf_size,
                               const uint8_t *buf, int buf_size, int keyframe)
{
    BSFCompatContext *priv = bsfc->priv_data;
    AVPacket pkt = { 0 };
    int ret;

    if (!priv->ctx) {
        ret = av_bsf_alloc(bsfc->filter, &priv->ctx);
        if (ret < 0)
            return ret;

        ret = avcodec_parameters_from_context(priv->ctx->par_in, avctx);
        if (ret < 0)
            return ret;

        priv->ctx->time_base_in = avctx->time_base;

        if (bsfc->args && bsfc->filter->priv_class) {
            const AVOption *opt = av_opt_next(priv->ctx->priv_data, NULL);
            const char * shorthand[2] = {NULL};

            if (opt)
                shorthand[0] = opt->name;

            ret = av_opt_set_from_string(priv->ctx->priv_data, bsfc->args, shorthand, "=", ":");
            if (ret < 0)
                return ret;
        }

        ret = av_bsf_init(priv->ctx);
        if (ret < 0)
            return ret;
    }

    pkt.data = (uint8_t *)buf;
    pkt.size = buf_size;

    ret = av_bsf_send_packet(priv->ctx, &pkt);
    if (ret < 0)
        return ret;

    *poutbuf      = NULL;
    *poutbuf_size = 0;

    ret = av_bsf_receive_packet(priv->ctx, &pkt);
    if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
        return 0;
    else if (ret < 0)
        return ret;

    *poutbuf = av_malloc(pkt.size + AV_INPUT_BUFFER_PADDING_SIZE);
    if (!*poutbuf) {
        av_packet_unref(&pkt);
        return AVERROR(ENOMEM);
    }

    *poutbuf_size = pkt.size;
    memcpy(*poutbuf, pkt.data, pkt.size);

    av_packet_unref(&pkt);

    /* drain all the remaining packets we cannot return */
    while (ret >= 0) {
        ret = av_bsf_receive_packet(priv->ctx, &pkt);
        av_packet_unref(&pkt);
    }

    if (!priv->extradata_updated) {
        /* update extradata in avctx from the output codec parameters */
        if (priv->ctx->par_out->extradata_size && (!args || !strstr(args, "private_spspps_buf"))) {
            av_freep(&avctx->extradata);
            avctx->extradata_size = 0;
            avctx->extradata = av_mallocz(priv->ctx->par_out->extradata_size + AV_INPUT_BUFFER_PADDING_SIZE);
            if (!avctx->extradata)
                return AVERROR(ENOMEM);
            memcpy(avctx->extradata, priv->ctx->par_out->extradata, priv->ctx->par_out->extradata_size);
            avctx->extradata_size = priv->ctx->par_out->extradata_size;
        }

        priv->extradata_updated = 1;
    }

    return 1;
}

