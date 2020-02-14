#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  enum HapSectionType { ____Placeholder_HapSectionType } HapSectionType ;
struct TYPE_13__ {TYPE_1__* priv_data; } ;
struct TYPE_12__ {int data; int size; } ;
struct TYPE_11__ {int texture; } ;
typedef  TYPE_1__ HapqaExtractContext ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVBSFContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  av_log (TYPE_3__*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  av_packet_unref (TYPE_2__*) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  bytestream2_seek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int ff_bsf_get_packet_ref (TYPE_3__*,TYPE_2__*) ; 
 int ff_hap_parse_section_header (int /*<<< orphan*/ *,int*,int*) ; 

__attribute__((used)) static int check_texture(HapqaExtractContext *ctx, int section_type) {
    if (((ctx->texture == 0)&&((section_type & 0x0F) == 0x0F)) || /* HapQ texture and rgb extract */
        ((ctx->texture == 1)&&((section_type & 0x0F) == 0x01))) /* HapAlphaOnly texture and alpha extract */
    {
        return 1; /* the texture is the one to keep */
    } else {
        return 0;
    }
}

__attribute__((used)) static int hapqa_extract(AVBSFContext *bsf, AVPacket *pkt)
{
    HapqaExtractContext *ctx = bsf->priv_data;
    GetByteContext gbc;
    int section_size;
    enum HapSectionType section_type;
    int start_section_size;
    int target_packet_size = 0;
    int ret = 0;

    ret = ff_bsf_get_packet_ref(bsf, pkt);
    if (ret < 0)
        return ret;

    bytestream2_init(&gbc, pkt->data, pkt->size);
    ret = ff_hap_parse_section_header(&gbc, &section_size, &section_type);
    if (ret != 0)
        goto fail;

    if ((section_type & 0x0F) != 0x0D) {
        av_log(bsf, AV_LOG_ERROR, "Invalid section type for HAPQA %#04x.\n", section_type & 0x0F);
        ret = AVERROR_INVALIDDATA;
        goto fail;
    }

    start_section_size = 4;

    bytestream2_seek(&gbc, start_section_size, SEEK_SET);/* go to start of the first texture */

    ret = ff_hap_parse_section_header(&gbc, &section_size, &section_type);
    if (ret != 0)
        goto fail;

    target_packet_size = section_size + 4;

    if (check_texture(ctx, section_type) == 0) { /* the texture is not the one to keep */
        start_section_size += 4 + section_size;
        bytestream2_seek(&gbc, start_section_size, SEEK_SET);/* go to start of the second texture */
        ret = ff_hap_parse_section_header(&gbc, &section_size, &section_type);
        if (ret != 0)
            goto fail;

        target_packet_size = section_size + 4;

        if (check_texture(ctx, section_type) == 0){ /* the second texture is not the one to keep */
            av_log(bsf, AV_LOG_ERROR, "No valid texture found.\n");
            ret = AVERROR_INVALIDDATA;
            goto fail;
        }
    }

    pkt->data += start_section_size;
    pkt->size = target_packet_size;

fail:
    if (ret < 0)
        av_packet_unref(pkt);
    return ret;
}

