#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int size; int data; } ;
typedef  TYPE_1__ AVPacket ;
typedef  int /*<<< orphan*/  AVBSFContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_RB16 (int) ; 
 int /*<<< orphan*/  AV_WB16 (int,int) ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FFMIN (int,int /*<<< orphan*/ ) ; 
 int av_new_packet (TYPE_1__*,int) ; 
 int av_packet_copy_props (TYPE_1__*,TYPE_1__*) ; 
 int /*<<< orphan*/  av_packet_free (TYPE_1__**) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_1__*) ; 
 int ff_bsf_get_packet (int /*<<< orphan*/ *,TYPE_1__**) ; 
 int ff_bsf_get_packet_ref (int /*<<< orphan*/ *,TYPE_1__*) ; 
 int /*<<< orphan*/  memcpy (int,int,int) ; 

__attribute__((used)) static int text2movsub(AVBSFContext *ctx, AVPacket *out)
{
    AVPacket *in;
    int ret = 0;

    ret = ff_bsf_get_packet(ctx, &in);
    if (ret < 0)
        return ret;

    if (in->size > 0xffff) {
        ret = AVERROR_INVALIDDATA;
        goto fail;
    }

    ret = av_new_packet(out, in->size + 2);
    if (ret < 0) {
        ret = AVERROR(ENOMEM);
        goto fail;
    }

    ret = av_packet_copy_props(out, in);
    if (ret < 0)
        goto fail;

    AV_WB16(out->data, in->size);
    memcpy(out->data + 2, in->data, in->size);

fail:
    if (ret < 0)
        av_packet_unref(out);
    av_packet_free(&in);
    return ret;
}

__attribute__((used)) static int mov2textsub(AVBSFContext *ctx, AVPacket *pkt)
{
    int ret = 0;

    ret = ff_bsf_get_packet_ref(ctx, pkt);
    if (ret < 0)
        return ret;

    if (pkt->size < 2) {
       av_packet_unref(pkt);
       return AVERROR_INVALIDDATA;
    }

    pkt->data += 2;
    pkt->size  = FFMIN(pkt->size - 2, AV_RB16(pkt->data));

    return 0;
}

