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

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
struct TYPE_19__ {int width; int height; int debug; int flags2; TYPE_1__* priv_data; } ;
struct TYPE_18__ {int** data; int palette_has_changed; int* linesize; int key_frame; void* pict_type; } ;
struct TYPE_17__ {int size; scalar_t__ data; } ;
struct TYPE_16__ {int* pal; int* decomp_buf; unsigned long dsize; TYPE_12__* prev; } ;
struct TYPE_15__ {int** data; } ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  TYPE_1__ DxaDecContext ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int AVERROR_UNKNOWN ; 
 int AVPALETTE_SIZE ; 
 int AV_CODEC_FLAG2_SHOW_ALL ; 
 int /*<<< orphan*/  AV_GET_BUFFER_FLAG_REF ; 
 int /*<<< orphan*/  AV_LOG_DEBUG ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 void* AV_PICTURE_TYPE_I ; 
 void* AV_PICTURE_TYPE_P ; 
 int AV_RB16 (int*) ; 
 int AV_RB32 (int*) ; 
 int DECOMP_BUF_PADDING ; 
 int FF_DEBUG_PICT_INFO ; 
 scalar_t__ MKTAG (char,unsigned char,char,char) ; 
 scalar_t__ Z_OK ; 
 int av_frame_ref (TYPE_12__*,TYPE_3__*) ; 
 int /*<<< orphan*/  av_frame_unref (TYPE_12__*) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 int bytestream2_get_be24 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 scalar_t__ bytestream2_get_le32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,scalar_t__,int) ; 
 scalar_t__ bytestream2_peek_le32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_skip (int /*<<< orphan*/ *,int) ; 
 scalar_t__ bytestream2_tell (int /*<<< orphan*/ *) ; 
 int ff_get_buffer (TYPE_4__*,TYPE_3__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int,int) ; 
 int* shift1 ; 
 int* shift2 ; 
 scalar_t__ uncompress (int*,unsigned long*,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int decode_13(AVCodecContext *avctx, DxaDecContext *c, uint8_t* dst,
                     int stride, uint8_t *src, int srcsize, uint8_t *ref)
{
    uint8_t *code, *data, *mv, *msk, *tmp, *tmp2;
    uint8_t *src_end = src + srcsize;
    int i, j, k;
    int type, x, y, d, d2;
    uint32_t mask;

    if (12ULL  + ((avctx->width * avctx->height) >> 4) + AV_RB32(src + 0) + AV_RB32(src + 4) > srcsize)
        return AVERROR_INVALIDDATA;

    code = src  + 12;
    data = code + ((avctx->width * avctx->height) >> 4);
    mv   = data + AV_RB32(src + 0);
    msk  = mv   + AV_RB32(src + 4);

    for(j = 0; j < avctx->height; j += 4){
        for(i = 0; i < avctx->width; i += 4){
            if (data > src_end || mv > src_end || msk > src_end)
                return AVERROR_INVALIDDATA;
            tmp  = dst + i;
            tmp2 = ref + i;
            type = *code++;
            switch(type){
            case 4: // motion compensation
                x = (*mv) >> 4;    if(x & 8) x = 8 - x;
                y = (*mv++) & 0xF; if(y & 8) y = 8 - y;
                if (i < -x || avctx->width  - i - 4 < x ||
                    j < -y || avctx->height - j - 4 < y) {
                    av_log(avctx, AV_LOG_ERROR, "MV %d %d out of bounds\n", x,y);
                    return AVERROR_INVALIDDATA;
                }
                tmp2 += x + y*stride;
            case 0: // skip
            case 5: // skip in method 12
                for(y = 0; y < 4; y++){
                    memcpy(tmp, tmp2, 4);
                    tmp  += stride;
                    tmp2 += stride;
                }
                break;
            case 1:  // masked change
            case 10: // masked change with only half of pixels changed
            case 11: // cases 10-15 are for method 12 only
            case 12:
            case 13:
            case 14:
            case 15:
                if(type == 1){
                    mask = AV_RB16(msk);
                    msk += 2;
                }else{
                    type -= 10;
                    mask = ((msk[0] & 0xF0) << shift1[type]) | ((msk[0] & 0xF) << shift2[type]);
                    msk++;
                }
                for(y = 0; y < 4; y++){
                    for(x = 0; x < 4; x++){
                        tmp[x] = (mask & 0x8000) ? *data++ : tmp2[x];
                        mask <<= 1;
                    }
                    tmp  += stride;
                    tmp2 += stride;
                }
                break;
            case 2: // fill block
                for(y = 0; y < 4; y++){
                    memset(tmp, data[0], 4);
                    tmp += stride;
                }
                data++;
                break;
            case 3: // raw block
                for(y = 0; y < 4; y++){
                    memcpy(tmp, data, 4);
                    data += 4;
                    tmp  += stride;
                }
                break;
            case 8: // subblocks - method 13 only
                mask = *msk++;
                for(k = 0; k < 4; k++){
                    d  = ((k & 1) << 1) + ((k & 2) * stride);
                    d2 = ((k & 1) << 1) + ((k & 2) * stride);
                    tmp2 = ref + i + d2;
                    switch(mask & 0xC0){
                    case 0x80: // motion compensation
                        x = (*mv) >> 4;    if(x & 8) x = 8 - x;
                        y = (*mv++) & 0xF; if(y & 8) y = 8 - y;
                        if (i + 2*(k & 1) < -x || avctx->width  - i - 2*(k & 1) - 2 < x ||
                            j +   (k & 2) < -y || avctx->height - j -   (k & 2) - 2 < y) {
                            av_log(avctx, AV_LOG_ERROR, "MV %d %d out of bounds\n", x,y);
                            return AVERROR_INVALIDDATA;
                        }
                        tmp2 += x + y*stride;
                    case 0x00: // skip
                        tmp[d + 0         ] = tmp2[0];
                        tmp[d + 1         ] = tmp2[1];
                        tmp[d + 0 + stride] = tmp2[0 + stride];
                        tmp[d + 1 + stride] = tmp2[1 + stride];
                        break;
                    case 0x40: // fill
                        tmp[d + 0         ] = data[0];
                        tmp[d + 1         ] = data[0];
                        tmp[d + 0 + stride] = data[0];
                        tmp[d + 1 + stride] = data[0];
                        data++;
                        break;
                    case 0xC0: // raw
                        tmp[d + 0         ] = *data++;
                        tmp[d + 1         ] = *data++;
                        tmp[d + 0 + stride] = *data++;
                        tmp[d + 1 + stride] = *data++;
                        break;
                    }
                    mask <<= 2;
                }
                break;
            case 32: // vector quantization - 2 colors
                mask = AV_RB16(msk);
                msk += 2;
                for(y = 0; y < 4; y++){
                    for(x = 0; x < 4; x++){
                        tmp[x] = data[mask & 1];
                        mask >>= 1;
                    }
                    tmp  += stride;
                    tmp2 += stride;
                }
                data += 2;
                break;
            case 33: // vector quantization - 3 or 4 colors
            case 34:
                mask = AV_RB32(msk);
                msk += 4;
                for(y = 0; y < 4; y++){
                    for(x = 0; x < 4; x++){
                        tmp[x] = data[mask & 3];
                        mask >>= 2;
                    }
                    tmp  += stride;
                    tmp2 += stride;
                }
                data += type - 30;
                break;
            default:
                av_log(avctx, AV_LOG_ERROR, "Unknown opcode %d\n", type);
                return AVERROR_INVALIDDATA;
            }
        }
        dst += stride * 4;
        ref += stride * 4;
    }
    return 0;
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx, void *data, int *got_frame, AVPacket *avpkt)
{
    AVFrame *frame = data;
    DxaDecContext * const c = avctx->priv_data;
    uint8_t *outptr, *srcptr, *tmpptr;
    unsigned long dsize;
    int i, j, compr, ret;
    int stride;
    int pc = 0;
    GetByteContext gb;

    bytestream2_init(&gb, avpkt->data, avpkt->size);

    /* make the palette available on the way out */
    if (bytestream2_peek_le32(&gb) == MKTAG('C','M','A','P')) {
        bytestream2_skip(&gb, 4);
        for(i = 0; i < 256; i++){
            c->pal[i] = 0xFFU << 24 | bytestream2_get_be24(&gb);
        }
        pc = 1;
    }

    if ((ret = ff_get_buffer(avctx, frame, AV_GET_BUFFER_FLAG_REF)) < 0)
        return ret;
    memcpy(frame->data[1], c->pal, AVPALETTE_SIZE);
    frame->palette_has_changed = pc;

    outptr = frame->data[0];
    srcptr = c->decomp_buf;
    tmpptr = c->prev->data[0];
    stride = frame->linesize[0];

    if (bytestream2_get_le32(&gb) == MKTAG('N','U','L','L'))
        compr = -1;
    else
        compr = bytestream2_get_byte(&gb);

    dsize = c->dsize;
    if (compr != 4 && compr != -1) {
        bytestream2_skip(&gb, 4);
        if (uncompress(c->decomp_buf, &dsize, avpkt->data + bytestream2_tell(&gb),
                       bytestream2_get_bytes_left(&gb)) != Z_OK) {
            av_log(avctx, AV_LOG_ERROR, "Uncompress failed!\n");
            return AVERROR_UNKNOWN;
        }
        memset(c->decomp_buf + dsize, 0, DECOMP_BUF_PADDING);
    }

    if (avctx->debug & FF_DEBUG_PICT_INFO)
        av_log(avctx, AV_LOG_DEBUG, "compr:%2d, dsize:%d\n", compr, (int)dsize);

    switch(compr){
    case -1:
        frame->key_frame = 0;
        frame->pict_type = AV_PICTURE_TYPE_P;
        if (c->prev->data[0])
            memcpy(frame->data[0], c->prev->data[0], frame->linesize[0] * avctx->height);
        else{ // Should happen only when first frame is 'NULL'
            memset(frame->data[0], 0, frame->linesize[0] * avctx->height);
            frame->key_frame = 1;
            frame->pict_type = AV_PICTURE_TYPE_I;
        }
        break;
    case 2:
    case 4:
        frame->key_frame = 1;
        frame->pict_type = AV_PICTURE_TYPE_I;
        for (j = 0; j < avctx->height; j++) {
                memcpy(outptr, srcptr, avctx->width);
            outptr += stride;
            srcptr += avctx->width;
        }
        break;
    case 3:
    case 5:
        if (!tmpptr) {
            av_log(avctx, AV_LOG_ERROR, "Missing reference frame.\n");
            if (!(avctx->flags2 & AV_CODEC_FLAG2_SHOW_ALL))
                return AVERROR_INVALIDDATA;
        }
        frame->key_frame = 0;
        frame->pict_type = AV_PICTURE_TYPE_P;
        for (j = 0; j < avctx->height; j++) {
            if(tmpptr){
                for(i = 0; i < avctx->width; i++)
                    outptr[i] = srcptr[i] ^ tmpptr[i];
                tmpptr += stride;
            }else
                memcpy(outptr, srcptr, avctx->width);
            outptr += stride;
            srcptr += avctx->width;
        }
        break;
    case 12: // ScummVM coding
    case 13:
        frame->key_frame = 0;
        frame->pict_type = AV_PICTURE_TYPE_P;
        if (!c->prev->data[0]) {
            av_log(avctx, AV_LOG_ERROR, "Missing reference frame\n");
            return AVERROR_INVALIDDATA;
        }
        decode_13(avctx, c, frame->data[0], frame->linesize[0], srcptr, dsize, c->prev->data[0]);
        break;
    default:
        av_log(avctx, AV_LOG_ERROR, "Unknown/unsupported compression type %d\n", compr);
        return AVERROR_INVALIDDATA;
    }

    av_frame_unref(c->prev);
    if ((ret = av_frame_ref(c->prev, frame)) < 0)
        return ret;

    *got_frame = 1;

    /* always report that the buffer was completely consumed */
    return avpkt->size;
}

