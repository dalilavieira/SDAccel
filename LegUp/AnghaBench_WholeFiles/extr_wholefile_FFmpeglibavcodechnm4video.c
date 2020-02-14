#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
typedef  int int32_t ;
struct TYPE_21__ {TYPE_1__* priv_data; } ;
struct TYPE_20__ {int** data; int key_frame; int /*<<< orphan*/  pict_type; int /*<<< orphan*/ * linesize; } ;
struct TYPE_19__ {int size; int* data; } ;
struct TYPE_18__ {int width; int height; int* current; int* processed; int* previous; int version; int* palette; } ;
typedef  TYPE_1__ Hnm4VideoContext ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_P ; 
 int AV_RL16 (int*) ; 
 int HNM4_CHUNK_ID_IU ; 
 int HNM4_CHUNK_ID_IZ ; 
 int HNM4_CHUNK_ID_PL ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 int bytestream2_get_be24 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le16 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_le32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int*,int) ; 
 int bytestream2_peek_byte (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 int bytestream2_tell (int /*<<< orphan*/ *) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 

__attribute__((used)) static int getbit(GetByteContext *gb, uint32_t *bitbuf, int *bits)
{
    int ret;

    if (!*bits) {
        *bitbuf = bytestream2_get_le32(gb);
        *bits = 32;
    }

    ret = *bitbuf >> 31;
    *bitbuf <<= 1;
    (*bits)--;

    return ret;
}

__attribute__((used)) static void unpack_intraframe(AVCodecContext *avctx, uint8_t *src,
                              uint32_t size)
{
    Hnm4VideoContext *hnm = avctx->priv_data;
    GetByteContext gb;
    uint32_t bitbuf = 0, writeoffset = 0, count = 0;
    uint16_t word;
    int32_t offset;
    int bits = 0;

    bytestream2_init(&gb, src, size);

    while (bytestream2_tell(&gb) < size) {
        if (getbit(&gb, &bitbuf, &bits)) {
            if (writeoffset >= hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR,
                       "Attempting to write out of bounds\n");
                break;
            }
            hnm->current[writeoffset++] = bytestream2_get_byte(&gb);
        } else {
            if (getbit(&gb, &bitbuf, &bits)) {
                word   = bytestream2_get_le16(&gb);
                count  = word & 0x07;
                offset = (word >> 3) - 0x2000;
                if (!count)
                    count = bytestream2_get_byte(&gb);
                if (!count)
                    return;
            } else {
                count  = getbit(&gb, &bitbuf, &bits) * 2;
                count += getbit(&gb, &bitbuf, &bits);
                offset = bytestream2_get_byte(&gb) - 0x0100;
            }
            count  += 2;
            offset += writeoffset;
            if (offset < 0 || offset + count >= hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR, "Attempting to read out of bounds\n");
                break;
            } else if (writeoffset + count >= hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR,
                       "Attempting to write out of bounds\n");
                break;
            }
            while (count--) {
                hnm->current[writeoffset++] = hnm->current[offset++];
            }
        }
    }
}

__attribute__((used)) static void postprocess_current_frame(AVCodecContext *avctx)
{
    Hnm4VideoContext *hnm = avctx->priv_data;
    uint32_t x, y, src_x, src_y;

    for (y = 0; y < hnm->height; y++) {
        src_y = y - (y % 2);
        src_x = src_y * hnm->width + (y % 2);
        for (x = 0; x < hnm->width; x++) {
            hnm->processed[(y * hnm->width) + x] = hnm->current[src_x];
            src_x += 2;
        }
    }
}

__attribute__((used)) static void copy_processed_frame(AVCodecContext *avctx, AVFrame *frame)
{
    Hnm4VideoContext *hnm = avctx->priv_data;
    uint8_t *src = hnm->processed;
    uint8_t *dst = frame->data[0];
    int y;

    for (y = 0; y < hnm->height; y++) {
        memcpy(dst, src, hnm->width);
        src += hnm->width;
        dst += frame->linesize[0];
    }
}

__attribute__((used)) static void decode_interframe_v4(AVCodecContext *avctx, uint8_t *src, uint32_t size)
{
    Hnm4VideoContext *hnm = avctx->priv_data;
    GetByteContext gb;
    uint32_t writeoffset = 0;
    int count, left, offset;
    uint8_t tag, previous, backline, backward, swap;

    bytestream2_init(&gb, src, size);

    while (bytestream2_tell(&gb) < size) {
        count = bytestream2_peek_byte(&gb) & 0x1F;
        if (count == 0) {
            tag = bytestream2_get_byte(&gb) & 0xE0;
            tag = tag >> 5;

            if (tag == 0) {
                if (writeoffset + 2 > hnm->width * hnm->height) {
                    av_log(avctx, AV_LOG_ERROR, "writeoffset out of bounds\n");
                    break;
                }
                hnm->current[writeoffset++] = bytestream2_get_byte(&gb);
                hnm->current[writeoffset++] = bytestream2_get_byte(&gb);
            } else if (tag == 1) {
                writeoffset += bytestream2_get_byte(&gb) * 2;
            } else if (tag == 2) {
                count = bytestream2_get_le16(&gb);
                count *= 2;
                writeoffset += count;
            } else if (tag == 3) {
                count = bytestream2_get_byte(&gb) * 2;
                if (writeoffset + count > hnm->width * hnm->height) {
                    av_log(avctx, AV_LOG_ERROR, "writeoffset out of bounds\n");
                    break;
                }
                while (count > 0) {
                    hnm->current[writeoffset++] = bytestream2_peek_byte(&gb);
                    count--;
                }
                bytestream2_skip(&gb, 1);
            } else {
                break;
            }
            if (writeoffset > hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR, "writeoffset out of bounds\n");
                break;
            }
        } else {
            previous = bytestream2_peek_byte(&gb) & 0x20;
            backline = bytestream2_peek_byte(&gb) & 0x40;
            backward = bytestream2_peek_byte(&gb) & 0x80;
            bytestream2_skip(&gb, 1);
            swap   = bytestream2_peek_byte(&gb) & 0x01;
            offset = bytestream2_get_le16(&gb);
            offset = (offset >> 1) & 0x7FFF;
            offset = writeoffset + (offset * 2) - 0x8000;

            left = count;

            if (!backward && offset + 2*count > hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR, "Attempting to read out of bounds\n");
                break;
            } else if (backward && offset + 1 >= hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR, "Attempting to read out of bounds\n");
                break;
            } else if (writeoffset + 2*count > hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR,
                       "Attempting to write out of bounds\n");
                break;
            }
            if(backward) {
                if (offset < (!!backline)*(2 * hnm->width - 1) + 2*(left-1)) {
                    av_log(avctx, AV_LOG_ERROR, "Attempting to read out of bounds\n");
                    break;
                }
            } else {
                if (offset < (!!backline)*(2 * hnm->width - 1)) {
                    av_log(avctx, AV_LOG_ERROR, "Attempting to read out of bounds\n");
                    break;
                }
            }

            if (previous) {
                while (left > 0) {
                    if (backline) {
                        hnm->current[writeoffset++] = hnm->previous[offset - (2 * hnm->width) + 1];
                        hnm->current[writeoffset++] = hnm->previous[offset++];
                        offset++;
                    } else {
                        hnm->current[writeoffset++] = hnm->previous[offset++];
                        hnm->current[writeoffset++] = hnm->previous[offset++];
                    }
                    if (backward)
                        offset -= 4;
                    left--;
                }
            } else {
                while (left > 0) {
                    if (backline) {
                        hnm->current[writeoffset++] = hnm->current[offset - (2 * hnm->width) + 1];
                        hnm->current[writeoffset++] = hnm->current[offset++];
                        offset++;
                    } else {
                        hnm->current[writeoffset++] = hnm->current[offset++];
                        hnm->current[writeoffset++] = hnm->current[offset++];
                    }
                    if (backward)
                        offset -= 4;
                    left--;
                }
            }

            if (swap) {
                left         = count;
                writeoffset -= count * 2;
                while (left > 0) {
                    swap = hnm->current[writeoffset];
                    hnm->current[writeoffset] = hnm->current[writeoffset + 1];
                    hnm->current[writeoffset + 1] = swap;
                    left--;
                    writeoffset += 2;
                }
            }
        }
    }
}

__attribute__((used)) static void decode_interframe_v4a(AVCodecContext *avctx, uint8_t *src,
                                  uint32_t size)
{
    Hnm4VideoContext *hnm = avctx->priv_data;
    GetByteContext gb;
    uint32_t writeoffset = 0, offset;
    uint8_t tag, count, previous, delta;

    bytestream2_init(&gb, src, size);

    while (bytestream2_tell(&gb) < size) {
        count = bytestream2_peek_byte(&gb) & 0x3F;
        if (count == 0) {
            tag = bytestream2_get_byte(&gb) & 0xC0;
            tag = tag >> 6;
            if (tag == 0) {
                writeoffset += bytestream2_get_byte(&gb);
            } else if (tag == 1) {
                if (writeoffset + hnm->width >= hnm->width * hnm->height) {
                    av_log(avctx, AV_LOG_ERROR, "writeoffset out of bounds\n");
                    break;
                }
                hnm->current[writeoffset]              = bytestream2_get_byte(&gb);
                hnm->current[writeoffset + hnm->width] = bytestream2_get_byte(&gb);
                writeoffset++;
            } else if (tag == 2) {
                writeoffset += hnm->width;
            } else if (tag == 3) {
                break;
            }
            if (writeoffset > hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR, "writeoffset out of bounds\n");
                break;
            }
        } else {
            delta    = bytestream2_peek_byte(&gb) & 0x80;
            previous = bytestream2_peek_byte(&gb) & 0x40;
            bytestream2_skip(&gb, 1);

            offset  = writeoffset;
            offset += bytestream2_get_le16(&gb);

            if (delta) {
                if (offset < 0x10000) {
                    av_log(avctx, AV_LOG_ERROR, "Attempting to read out of bounds\n");
                    break;
                }
                offset -= 0x10000;
            }

            if (offset + hnm->width + count >= hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR, "Attempting to read out of bounds\n");
                break;
            } else if (writeoffset + hnm->width + count >= hnm->width * hnm->height) {
                av_log(avctx, AV_LOG_ERROR, "Attempting to write out of bounds\n");
                break;
            }

            if (previous) {
                while (count > 0) {
                    hnm->current[writeoffset]              = hnm->previous[offset];
                    hnm->current[writeoffset + hnm->width] = hnm->previous[offset + hnm->width];
                    writeoffset++;
                    offset++;
                    count--;
                }
            } else {
                while (count > 0) {
                    hnm->current[writeoffset]              = hnm->current[offset];
                    hnm->current[writeoffset + hnm->width] = hnm->current[offset + hnm->width];
                    writeoffset++;
                    offset++;
                    count--;
                }
            }
        }
    }
}

__attribute__((used)) static void hnm_update_palette(AVCodecContext *avctx, uint8_t *src,
                               uint32_t size)
{
    Hnm4VideoContext *hnm = avctx->priv_data;
    GetByteContext gb;
    uint8_t start, writeoffset;
    uint16_t count;
    int eight_bit_colors;

    eight_bit_colors = src[7] & 0x80 && hnm->version == 0x4a;

    // skip first 8 bytes
    bytestream2_init(&gb, src + 8, size - 8);

    while (bytestream2_tell(&gb) < size - 8) {
        start = bytestream2_get_byte(&gb);
        count = bytestream2_get_byte(&gb);
        if (start == 255 && count == 255)
            break;
        if (count == 0)
            count = 256;
        writeoffset = start;
        while (count > 0) {
            hnm->palette[writeoffset] = bytestream2_get_be24(&gb);
            if (!eight_bit_colors)
                hnm->palette[writeoffset] <<= 2;
            hnm->palette[writeoffset] |= (0xFFU << 24);
            count--;
            writeoffset++;
        }
    }
}

__attribute__((used)) static void hnm_flip_buffers(Hnm4VideoContext *hnm)
{
    uint8_t *temp;

    temp          = hnm->current;
    hnm->current  = hnm->previous;
    hnm->previous = temp;
}

__attribute__((used)) static int hnm_decode_frame(AVCodecContext *avctx, void *data,
                            int *got_frame, AVPacket *avpkt)
{
    AVFrame *frame = data;
    Hnm4VideoContext *hnm = avctx->priv_data;
    int ret;
    uint16_t chunk_id;

    if (avpkt->size < 8) {
        av_log(avctx, AV_LOG_ERROR, "packet too small\n");
        return AVERROR_INVALIDDATA;
    }

    chunk_id = AV_RL16(avpkt->data + 4);

    if (chunk_id == HNM4_CHUNK_ID_PL) {
        hnm_update_palette(avctx, avpkt->data, avpkt->size);
    } else if (chunk_id == HNM4_CHUNK_ID_IZ) {
        if (avpkt->size < 12) {
            av_log(avctx, AV_LOG_ERROR, "packet too small\n");
            return AVERROR_INVALIDDATA;
        }
        if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
            return ret;

        unpack_intraframe(avctx, avpkt->data + 12, avpkt->size - 12);
        memcpy(hnm->previous, hnm->current, hnm->width * hnm->height);
        if (hnm->version == 0x4a)
            memcpy(hnm->processed, hnm->current, hnm->width * hnm->height);
        else
            postprocess_current_frame(avctx);
        copy_processed_frame(avctx, frame);
        frame->pict_type = AV_PICTURE_TYPE_I;
        frame->key_frame = 1;
        memcpy(frame->data[1], hnm->palette, 256 * 4);
        *got_frame = 1;
    } else if (chunk_id == HNM4_CHUNK_ID_IU) {
        if ((ret = ff_get_buffer(avctx, frame, 0)) < 0)
            return ret;

        if (hnm->version == 0x4a) {
            decode_interframe_v4a(avctx, avpkt->data + 8, avpkt->size - 8);
            memcpy(hnm->processed, hnm->current, hnm->width * hnm->height);
        } else {
            decode_interframe_v4(avctx, avpkt->data + 8, avpkt->size - 8);
            postprocess_current_frame(avctx);
        }
        copy_processed_frame(avctx, frame);
        frame->pict_type = AV_PICTURE_TYPE_P;
        frame->key_frame = 0;
        memcpy(frame->data[1], hnm->palette, 256 * 4);
        *got_frame = 1;
        hnm_flip_buffers(hnm);
    } else {
        av_log(avctx, AV_LOG_ERROR, "invalid chunk id: %d\n", chunk_id);
        return AVERROR_INVALIDDATA;
    }

    return avpkt->size;
}

