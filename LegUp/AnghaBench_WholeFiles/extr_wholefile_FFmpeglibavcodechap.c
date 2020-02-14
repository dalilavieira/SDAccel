#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  enum HapSectionType { ____Placeholder_HapSectionType } HapSectionType ;
struct TYPE_3__ {int chunk_count; int /*<<< orphan*/  chunk_results; int /*<<< orphan*/  chunks; } ;
typedef  TYPE_1__ HapContext ;
typedef  int /*<<< orphan*/  HapChunk ;
typedef  int /*<<< orphan*/  GetByteContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int av_reallocp_array (int /*<<< orphan*/ *,int,int) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le24 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le32 (int /*<<< orphan*/ *) ; 

int ff_hap_set_chunk_count(HapContext *ctx, int count, int first_in_frame)
{
    int ret = 0;
    if (first_in_frame == 1 && ctx->chunk_count != count) {
        int ret = av_reallocp_array(&ctx->chunks, count, sizeof(HapChunk));
        if (ret == 0)
            ret = av_reallocp_array(&ctx->chunk_results, count, sizeof(int));
        if (ret < 0) {
            ctx->chunk_count = 0;
        } else {
            ctx->chunk_count = count;
        }
    } else if (ctx->chunk_count != count) {
        /* If this is not the first chunk count calculated for a frame and a
         * different count has already been encountered, then reject the frame:
         * each table in the Decode Instructions Container must describe the
         * same number of chunks. */
        ret = AVERROR_INVALIDDATA;
    }
    return ret;
}

int ff_hap_parse_section_header(GetByteContext *gbc, int *section_size,
                                enum HapSectionType *section_type)
{
    if (bytestream2_get_bytes_left(gbc) < 4)
        return AVERROR_INVALIDDATA;

    *section_size = bytestream2_get_le24(gbc);
    *section_type = bytestream2_get_byte(gbc);

    if (*section_size == 0) {
        if (bytestream2_get_bytes_left(gbc) < 4)
            return AVERROR_INVALIDDATA;

        *section_size = bytestream2_get_le32(gbc);
    }

    if (*section_size > bytestream2_get_bytes_left(gbc) || *section_size < 0)
        return AVERROR_INVALIDDATA;
    else
        return 0;
}

