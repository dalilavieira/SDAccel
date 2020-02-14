#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_49__   TYPE_8__ ;
typedef  struct TYPE_48__   TYPE_7__ ;
typedef  struct TYPE_47__   TYPE_6__ ;
typedef  struct TYPE_46__   TYPE_5__ ;
typedef  struct TYPE_45__   TYPE_4__ ;
typedef  struct TYPE_44__   TYPE_3__ ;
typedef  struct TYPE_43__   TYPE_2__ ;
typedef  struct TYPE_42__   TYPE_1__ ;
typedef  struct TYPE_41__   TYPE_11__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ int64_t ;
typedef  enum HapSectionType { ____Placeholder_HapSectionType } HapSectionType ;
struct TYPE_43__ {TYPE_11__* f; } ;
typedef  TYPE_2__ ThreadFrame ;
struct TYPE_49__ {scalar_t__ codec_tag; int coded_width; int coded_height; int /*<<< orphan*/  (* execute2 ) (TYPE_8__*,int (*) (TYPE_8__*,void*,int,int),TYPE_11__*,scalar_t__*,int) ;TYPE_1__* codec; TYPE_3__* priv_data; } ;
struct TYPE_48__ {int* linesize; int /*<<< orphan*/ ** data; } ;
struct TYPE_47__ {scalar_t__ data; scalar_t__ size; } ;
struct TYPE_46__ {scalar_t__ buffer; } ;
struct TYPE_45__ {int compressor; int compressed_size; size_t compressed_offset; int uncompressed_offset; scalar_t__ uncompressed_size; } ;
struct TYPE_44__ {int chunk_count; int texture_section_size; int tex_size; int slice_count; int uncompress_pix_size; int tex_rat; int tex_rat2; int texture_count; scalar_t__* chunk_results; int /*<<< orphan*/ * tex_buf; int /*<<< orphan*/ * tex_data; TYPE_5__ gbc; int /*<<< orphan*/  (* tex_fun2 ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/  const*) ;int /*<<< orphan*/  (* tex_fun ) (int /*<<< orphan*/ *,int,int /*<<< orphan*/  const*) ;TYPE_4__* chunks; } ;
struct TYPE_42__ {scalar_t__ update_thread_context; } ;
struct TYPE_41__ {int key_frame; int /*<<< orphan*/  pict_type; } ;
typedef  TYPE_3__ HapContext ;
typedef  TYPE_4__ HapChunk ;
typedef  TYPE_5__ GetByteContext ;
typedef  TYPE_6__ AVPacket ;
typedef  TYPE_7__ AVFrame ;
typedef  TYPE_8__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int FFMIN (int,int) ; 
#define  HAP_COMP_COMPLEX 133 
#define  HAP_COMP_NONE 132 
#define  HAP_COMP_SNAPPY 131 
 int HAP_FMT_RGBADXT5 ; 
 int HAP_FMT_RGBDXT1 ; 
 int HAP_FMT_RGTC1 ; 
 int HAP_FMT_YCOCGDXT5 ; 
#define  HAP_ST_COMPRESSOR_TABLE 130 
 int HAP_ST_DECODE_INSTRUCTIONS ; 
#define  HAP_ST_OFFSET_TABLE 129 
#define  HAP_ST_SIZE_TABLE 128 
 scalar_t__ MKTAG (char,char,char,char) ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int TEXTURE_BLOCK_H ; 
 int TEXTURE_BLOCK_W ; 
 int /*<<< orphan*/  av_log (TYPE_8__*,int /*<<< orphan*/ ,char*,...) ; 
 int av_reallocp (int /*<<< orphan*/ **,scalar_t__) ; 
 int /*<<< orphan*/  bytestream2_get_buffer (TYPE_5__*,int /*<<< orphan*/ *,scalar_t__) ; 
 int bytestream2_get_byte (TYPE_5__*) ; 
 int bytestream2_get_bytes_left (TYPE_5__*) ; 
 void* bytestream2_get_le32 (TYPE_5__*) ; 
 int /*<<< orphan*/  bytestream2_init (TYPE_5__*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  bytestream2_seek (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int ff_hap_parse_section_header (TYPE_5__*,int*,int*) ; 
 int ff_hap_set_chunk_count (TYPE_3__*,int,int) ; 
 scalar_t__ ff_snappy_peek_uncompressed_length (TYPE_5__*) ; 
 int ff_snappy_uncompress (TYPE_5__*,int /*<<< orphan*/ *,scalar_t__*) ; 
 int /*<<< orphan*/  ff_thread_finish_setup (TYPE_8__*) ; 
 int ff_thread_get_buffer (TYPE_8__*,TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,int,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *,int,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  stub3 (TYPE_8__*,int (*) (TYPE_8__*,void*,int,int),TYPE_11__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  stub4 (TYPE_8__*,int (*) (TYPE_8__*,void*,int,int),TYPE_11__*,scalar_t__*,int) ; 
 int /*<<< orphan*/  stub5 (TYPE_8__*,int (*) (TYPE_8__*,void*,int,int),TYPE_11__*,scalar_t__*,int) ; 

__attribute__((used)) static int hap_parse_decode_instructions(HapContext *ctx, int size)
{
    GetByteContext *gbc = &ctx->gbc;
    int section_size;
    enum HapSectionType section_type;
    int is_first_table = 1, had_offsets = 0, had_compressors = 0, had_sizes = 0;
    int i, ret;

    while (size > 0) {
        int stream_remaining = bytestream2_get_bytes_left(gbc);
        ret = ff_hap_parse_section_header(gbc, &section_size, &section_type);
        if (ret != 0)
            return ret;

        size -= stream_remaining - bytestream2_get_bytes_left(gbc);

        switch (section_type) {
            case HAP_ST_COMPRESSOR_TABLE:
                ret = ff_hap_set_chunk_count(ctx, section_size, is_first_table);
                if (ret != 0)
                    return ret;
                for (i = 0; i < section_size; i++) {
                    ctx->chunks[i].compressor = bytestream2_get_byte(gbc) << 4;
                }
                had_compressors = 1;
                is_first_table = 0;
                break;
            case HAP_ST_SIZE_TABLE:
                ret = ff_hap_set_chunk_count(ctx, section_size / 4, is_first_table);
                if (ret != 0)
                    return ret;
                for (i = 0; i < section_size / 4; i++) {
                    ctx->chunks[i].compressed_size = bytestream2_get_le32(gbc);
                }
                had_sizes = 1;
                is_first_table = 0;
                break;
            case HAP_ST_OFFSET_TABLE:
                ret = ff_hap_set_chunk_count(ctx, section_size / 4, is_first_table);
                if (ret != 0)
                    return ret;
                for (i = 0; i < section_size / 4; i++) {
                    ctx->chunks[i].compressed_offset = bytestream2_get_le32(gbc);
                }
                had_offsets = 1;
                is_first_table = 0;
                break;
            default:
                break;
        }
        size -= section_size;
    }

    if (!had_sizes || !had_compressors)
        return AVERROR_INVALIDDATA;

    /* The offsets table is optional. If not present than calculate offsets by
     * summing the sizes of preceding chunks. */
    if (!had_offsets) {
        size_t running_size = 0;
        for (i = 0; i < ctx->chunk_count; i++) {
            ctx->chunks[i].compressed_offset = running_size;
            running_size += ctx->chunks[i].compressed_size;
        }
    }

    return 0;
}

__attribute__((used)) static int hap_can_use_tex_in_place(HapContext *ctx)
{
    int i;
    size_t running_offset = 0;
    for (i = 0; i < ctx->chunk_count; i++) {
        if (ctx->chunks[i].compressed_offset != running_offset
            || ctx->chunks[i].compressor != HAP_COMP_NONE)
            return 0;
        running_offset += ctx->chunks[i].compressed_size;
    }
    return 1;
}

__attribute__((used)) static int hap_parse_frame_header(AVCodecContext *avctx)
{
    HapContext *ctx = avctx->priv_data;
    GetByteContext *gbc = &ctx->gbc;
    int section_size;
    enum HapSectionType section_type;
    const char *compressorstr;
    int i, ret;

    ret = ff_hap_parse_section_header(gbc, &ctx->texture_section_size, &section_type);
    if (ret != 0)
        return ret;

    if ((avctx->codec_tag == MKTAG('H','a','p','1') && (section_type & 0x0F) != HAP_FMT_RGBDXT1) ||
        (avctx->codec_tag == MKTAG('H','a','p','5') && (section_type & 0x0F) != HAP_FMT_RGBADXT5) ||
        (avctx->codec_tag == MKTAG('H','a','p','Y') && (section_type & 0x0F) != HAP_FMT_YCOCGDXT5) ||
        (avctx->codec_tag == MKTAG('H','a','p','A') && (section_type & 0x0F) != HAP_FMT_RGTC1) ||
        ((avctx->codec_tag == MKTAG('H','a','p','M') && (section_type & 0x0F) != HAP_FMT_RGTC1) &&
                                                        (section_type & 0x0F) != HAP_FMT_YCOCGDXT5)) {
        av_log(avctx, AV_LOG_ERROR,
               "Invalid texture format %#04x.\n", section_type & 0x0F);
        return AVERROR_INVALIDDATA;
    }

    switch (section_type & 0xF0) {
        case HAP_COMP_NONE:
        case HAP_COMP_SNAPPY:
            ret = ff_hap_set_chunk_count(ctx, 1, 1);
            if (ret == 0) {
                ctx->chunks[0].compressor = section_type & 0xF0;
                ctx->chunks[0].compressed_offset = 0;
                ctx->chunks[0].compressed_size = ctx->texture_section_size;
            }
            if (ctx->chunks[0].compressor == HAP_COMP_NONE) {
                compressorstr = "none";
            } else {
                compressorstr = "snappy";
            }
            break;
        case HAP_COMP_COMPLEX:
            ret = ff_hap_parse_section_header(gbc, &section_size, &section_type);
            if (ret == 0 && section_type != HAP_ST_DECODE_INSTRUCTIONS)
                ret = AVERROR_INVALIDDATA;
            if (ret == 0)
                ret = hap_parse_decode_instructions(ctx, section_size);
            compressorstr = "complex";
            break;
        default:
            ret = AVERROR_INVALIDDATA;
            break;
    }

    if (ret != 0)
        return ret;

    /* Check the frame is valid and read the uncompressed chunk sizes */
    ctx->tex_size = 0;
    for (i = 0; i < ctx->chunk_count; i++) {
        HapChunk *chunk = &ctx->chunks[i];

        /* Check the compressed buffer is valid */
        if (chunk->compressed_offset + chunk->compressed_size > bytestream2_get_bytes_left(gbc))
            return AVERROR_INVALIDDATA;

        /* Chunks are unpacked sequentially, ctx->tex_size is the uncompressed
         * size thus far */
        chunk->uncompressed_offset = ctx->tex_size;

        /* Fill out uncompressed size */
        if (chunk->compressor == HAP_COMP_SNAPPY) {
            GetByteContext gbc_tmp;
            int64_t uncompressed_size;
            bytestream2_init(&gbc_tmp, gbc->buffer + chunk->compressed_offset,
                             chunk->compressed_size);
            uncompressed_size = ff_snappy_peek_uncompressed_length(&gbc_tmp);
            if (uncompressed_size < 0) {
                return uncompressed_size;
            }
            chunk->uncompressed_size = uncompressed_size;
        } else if (chunk->compressor == HAP_COMP_NONE) {
            chunk->uncompressed_size = chunk->compressed_size;
        } else {
            return AVERROR_INVALIDDATA;
        }
        ctx->tex_size += chunk->uncompressed_size;
    }

    av_log(avctx, AV_LOG_DEBUG, "%s compressor\n", compressorstr);

    return ret;
}

__attribute__((used)) static int decompress_chunks_thread(AVCodecContext *avctx, void *arg,
                                    int chunk_nb, int thread_nb)
{
    HapContext *ctx = avctx->priv_data;

    HapChunk *chunk = &ctx->chunks[chunk_nb];
    GetByteContext gbc;
    uint8_t *dst = ctx->tex_buf + chunk->uncompressed_offset;

    bytestream2_init(&gbc, ctx->gbc.buffer + chunk->compressed_offset, chunk->compressed_size);

    if (chunk->compressor == HAP_COMP_SNAPPY) {
        int ret;
        int64_t uncompressed_size = ctx->tex_size;

        /* Uncompress the frame */
        ret = ff_snappy_uncompress(&gbc, dst, &uncompressed_size);
        if (ret < 0) {
             av_log(avctx, AV_LOG_ERROR, "Snappy uncompress error\n");
             return ret;
        }
    } else if (chunk->compressor == HAP_COMP_NONE) {
        bytestream2_get_buffer(&gbc, dst, chunk->compressed_size);
    }

    return 0;
}

__attribute__((used)) static int decompress_texture_thread_internal(AVCodecContext *avctx, void *arg,
                                              int slice, int thread_nb, int texture_num)
{
    HapContext *ctx = avctx->priv_data;
    AVFrame *frame = arg;
    const uint8_t *d = ctx->tex_data;
    int w_block = avctx->coded_width / TEXTURE_BLOCK_W;
    int h_block = avctx->coded_height / TEXTURE_BLOCK_H;
    int x, y;
    int start_slice, end_slice;
    int base_blocks_per_slice = h_block / ctx->slice_count;
    int remainder_blocks = h_block % ctx->slice_count;

    /* When the frame height (in blocks) doesn't divide evenly between the
     * number of slices, spread the remaining blocks evenly between the first
     * operations */
    start_slice = slice * base_blocks_per_slice;
    /* Add any extra blocks (one per slice) that have been added before this slice */
    start_slice += FFMIN(slice, remainder_blocks);

    end_slice = start_slice + base_blocks_per_slice;
    /* Add an extra block if there are still remainder blocks to be accounted for */
    if (slice < remainder_blocks)
        end_slice++;

    for (y = start_slice; y < end_slice; y++) {
        uint8_t *p = frame->data[0] + y * frame->linesize[0] * TEXTURE_BLOCK_H;
        int off  = y * w_block;
        for (x = 0; x < w_block; x++) {
            if (texture_num == 0) {
                ctx->tex_fun(p + x * 4 * ctx->uncompress_pix_size, frame->linesize[0],
                             d + (off + x) * ctx->tex_rat);
            } else {
                ctx->tex_fun2(p + x * 4 * ctx->uncompress_pix_size, frame->linesize[0],
                              d + (off + x) * ctx->tex_rat2);
            }
        }
    }

    return 0;
}

__attribute__((used)) static int decompress_texture_thread(AVCodecContext *avctx, void *arg,
                                     int slice, int thread_nb)
{
    return decompress_texture_thread_internal(avctx, arg, slice, thread_nb, 0);
}

__attribute__((used)) static int decompress_texture2_thread(AVCodecContext *avctx, void *arg,
                                      int slice, int thread_nb)
{
    return decompress_texture_thread_internal(avctx, arg, slice, thread_nb, 1);
}

__attribute__((used)) static int hap_decode(AVCodecContext *avctx, void *data,
                      int *got_frame, AVPacket *avpkt)
{
    HapContext *ctx = avctx->priv_data;
    ThreadFrame tframe;
    int ret, i, t;
    int tex_size;
    int section_size;
    enum HapSectionType section_type;
    int start_texture_section = 0;
    int tex_rat[2] = {0, 0};

    bytestream2_init(&ctx->gbc, avpkt->data, avpkt->size);

    tex_rat[0] = ctx->tex_rat;

    /* check for multi texture header */
    if (ctx->texture_count == 2) {
        ret = ff_hap_parse_section_header(&ctx->gbc, &section_size, &section_type);
        if (ret != 0)
            return ret;
        if ((section_type & 0x0F) != 0x0D) {
            av_log(avctx, AV_LOG_ERROR, "Invalid section type in 2 textures mode %#04x.\n", section_type);
            return AVERROR_INVALIDDATA;
        }
        start_texture_section = 4;
        tex_rat[1] = ctx->tex_rat2;
    }

    /* Get the output frame ready to receive data */
    tframe.f = data;
    ret = ff_thread_get_buffer(avctx, &tframe, 0);
    if (ret < 0)
        return ret;

    for (t = 0; t < ctx->texture_count; t++) {
        bytestream2_seek(&ctx->gbc, start_texture_section, SEEK_SET);

        /* Check for section header */
        ret = hap_parse_frame_header(avctx);
        if (ret < 0)
            return ret;

        start_texture_section += ctx->texture_section_size + 4;

        if (avctx->codec->update_thread_context)
            ff_thread_finish_setup(avctx);

        /* Unpack the DXT texture */
        if (hap_can_use_tex_in_place(ctx)) {
            /* Only DXTC texture compression in a contiguous block */
            ctx->tex_data = ctx->gbc.buffer;
            tex_size = FFMIN(ctx->texture_section_size, bytestream2_get_bytes_left(&ctx->gbc));
        } else {
            /* Perform the second-stage decompression */
            ret = av_reallocp(&ctx->tex_buf, ctx->tex_size);
            if (ret < 0)
                return ret;

            avctx->execute2(avctx, decompress_chunks_thread, NULL,
                            ctx->chunk_results, ctx->chunk_count);

            for (i = 0; i < ctx->chunk_count; i++) {
                if (ctx->chunk_results[i] < 0)
                    return ctx->chunk_results[i];
            }

            ctx->tex_data = ctx->tex_buf;
            tex_size = ctx->tex_size;
        }

        if (tex_size < (avctx->coded_width  / TEXTURE_BLOCK_W)
            *(avctx->coded_height / TEXTURE_BLOCK_H)
            *tex_rat[t]) {
            av_log(avctx, AV_LOG_ERROR, "Insufficient data\n");
            return AVERROR_INVALIDDATA;
        }

        /* Use the decompress function on the texture, one block per thread */
        if (t == 0){
            avctx->execute2(avctx, decompress_texture_thread, tframe.f, NULL, ctx->slice_count);
        } else{
            tframe.f = data;
            avctx->execute2(avctx, decompress_texture2_thread, tframe.f, NULL, ctx->slice_count);
        }
    }

    /* Frame is ready to be output */
    tframe.f->pict_type = AV_PICTURE_TYPE_I;
    tframe.f->key_frame = 1;
    *got_frame = 1;

    return avpkt->size;
}

