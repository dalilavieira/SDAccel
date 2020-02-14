#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;

/* Type definitions */
struct TYPE_19__ {TYPE_2__* priv_data; TYPE_11__* par_in; } ;
struct TYPE_18__ {int flags; int data; int size; } ;
struct TYPE_17__ {scalar_t__ freq; TYPE_12__* parser; int /*<<< orphan*/  avctx; } ;
struct TYPE_16__ {int (* split ) (int /*<<< orphan*/ ,int,int) ;} ;
struct TYPE_15__ {TYPE_1__* parser; } ;
struct TYPE_14__ {int /*<<< orphan*/  codec_id; } ;
typedef  TYPE_2__ RemoveExtradataContext ;
typedef  TYPE_3__ AVPacket ;
typedef  TYPE_4__ AVBSFContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AV_PKT_FLAG_KEY ; 
 int /*<<< orphan*/  ENOMEM ; 
 scalar_t__ REMOVE_FREQ_ALL ; 
 scalar_t__ REMOVE_FREQ_KEYFRAME ; 
 scalar_t__ REMOVE_FREQ_NONKEYFRAME ; 
 int /*<<< orphan*/  av_parser_close (TYPE_12__*) ; 
 TYPE_12__* av_parser_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avcodec_alloc_context3 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  avcodec_free_context (int /*<<< orphan*/ *) ; 
 int avcodec_parameters_to_context (int /*<<< orphan*/ ,TYPE_11__*) ; 
 int ff_bsf_get_packet_ref (TYPE_4__*,TYPE_3__*) ; 
 int stub1 (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static int remove_extradata(AVBSFContext *ctx, AVPacket *pkt)
{
    RemoveExtradataContext *s = ctx->priv_data;

    int ret;

    ret = ff_bsf_get_packet_ref(ctx, pkt);
    if (ret < 0)
        return ret;

    if (s->parser && s->parser->parser->split) {
        if (s->freq == REMOVE_FREQ_ALL ||
            (s->freq == REMOVE_FREQ_NONKEYFRAME && !(pkt->flags & AV_PKT_FLAG_KEY)) ||
            (s->freq == REMOVE_FREQ_KEYFRAME && pkt->flags & AV_PKT_FLAG_KEY)) {
            int i = s->parser->parser->split(s->avctx, pkt->data, pkt->size);
            pkt->data += i;
            pkt->size -= i;
        }
    }

    return 0;
}

__attribute__((used)) static int remove_extradata_init(AVBSFContext *ctx)
{
    RemoveExtradataContext *s = ctx->priv_data;
    int ret;

    s->parser = av_parser_init(ctx->par_in->codec_id);

    if (s->parser) {
        s->avctx = avcodec_alloc_context3(NULL);
        if (!s->avctx)
            return AVERROR(ENOMEM);

        ret = avcodec_parameters_to_context(s->avctx, ctx->par_in);
        if (ret < 0)
            return ret;
    }

    return 0;
}

__attribute__((used)) static void remove_extradata_close(AVBSFContext *ctx)
{
    RemoveExtradataContext *s = ctx->priv_data;

    avcodec_free_context(&s->avctx);
    av_parser_close(s->parser);
}

