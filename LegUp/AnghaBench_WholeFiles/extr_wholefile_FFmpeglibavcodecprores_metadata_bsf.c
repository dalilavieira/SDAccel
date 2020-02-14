#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  char uint8_t ;
struct TYPE_14__ {TYPE_1__* priv_data; } ;
struct TYPE_13__ {char* data; int size; } ;
struct TYPE_12__ {int color_primaries; int transfer_characteristics; int matrix_coefficients; } ;
typedef  TYPE_1__ ProresMetadataContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVBSFContext ;

/* Variables and functions */
#define  AVCOL_PRI_BT2020 136 
#define  AVCOL_PRI_BT470BG 135 
#define  AVCOL_PRI_BT709 134 
#define  AVCOL_PRI_SMPTE170M 133 
#define  AVCOL_PRI_SMPTE431 132 
#define  AVCOL_PRI_SMPTE432 131 
#define  AVCOL_SPC_BT2020_NCL 130 
#define  AVCOL_SPC_BT709 129 
#define  AVCOL_SPC_SMPTE170M 128 
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int AV_RB16 (char*) ; 
 scalar_t__ AV_RL32 (char*) ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  av_log (TYPE_3__*,int /*<<< orphan*/ ,char*,...) ; 
 int av_packet_make_writable (TYPE_2__*) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_2__*) ; 
 int ff_bsf_get_packet_ref (TYPE_3__*,TYPE_2__*) ; 

__attribute__((used)) static int prores_metadata(AVBSFContext *bsf, AVPacket *pkt)
{
    ProresMetadataContext *ctx = bsf->priv_data;
    int ret = 0;
    int buf_size;
    uint8_t *buf;

    ret = ff_bsf_get_packet_ref(bsf, pkt);
    if (ret < 0)
        return ret;

    ret = av_packet_make_writable(pkt);
    if (ret < 0)
        goto fail;

    buf = pkt->data;
    buf_size = pkt->size;

    /* check start of the prores frame */
    if (buf_size < 28) {
        av_log(bsf, AV_LOG_ERROR, "not enough data in prores frame\n");
        ret = AVERROR_INVALIDDATA;
        goto fail;
    }

    if (AV_RL32(buf + 4) != AV_RL32("icpf")) {
        av_log(bsf, AV_LOG_ERROR, "invalid frame header\n");
        ret = AVERROR_INVALIDDATA;
        goto fail;
    }

    if (AV_RB16(buf + 8) < 28) {
        av_log(bsf, AV_LOG_ERROR, "invalid frame header size\n");
        ret = AVERROR_INVALIDDATA;
        goto fail;
    }

    /* set the new values */
    if (ctx->color_primaries != -1)
        buf[8+14] = ctx->color_primaries;
    if (ctx->transfer_characteristics != -1)
        buf[8+15] = ctx->transfer_characteristics;
    if (ctx->matrix_coefficients != -1)
        buf[8+16] = ctx->matrix_coefficients;

fail:
    if (ret < 0)
        av_packet_unref(pkt);
    return ret;
}

__attribute__((used)) static int prores_metadata_init(AVBSFContext *bsf)
{
    ProresMetadataContext *ctx = bsf->priv_data;
    /*! check options */
    switch (ctx->color_primaries) {
    case -1:
    case 0:
    case AVCOL_PRI_BT709:
    case AVCOL_PRI_BT470BG:
    case AVCOL_PRI_SMPTE170M:
    case AVCOL_PRI_BT2020:
    case AVCOL_PRI_SMPTE431:
    case AVCOL_PRI_SMPTE432:
        break;
    default:
        av_log(bsf, AV_LOG_ERROR, "Color primaries %d is not a valid value\n", ctx->color_primaries);
        return AVERROR(EINVAL);
    }

    switch (ctx->matrix_coefficients) {
    case -1:
    case 0:
    case AVCOL_SPC_BT709:
    case AVCOL_SPC_SMPTE170M:
    case AVCOL_SPC_BT2020_NCL:
        break;
    default:
        av_log(bsf, AV_LOG_ERROR, "Colorspace %d is not a valid value\n", ctx->matrix_coefficients);
        return AVERROR(EINVAL);
    }

    return 0;
}

