#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint8_t ;
struct TYPE_14__ {int blocks; int height; int width; size_t* ulti_codebook; TYPE_3__* frame; int /*<<< orphan*/  gb; } ;
typedef  TYPE_1__ UltimotionDecodeContext ;
struct TYPE_17__ {TYPE_1__* priv_data; } ;
struct TYPE_16__ {size_t** data; int* linesize; } ;
struct TYPE_15__ {size_t* data; int size; } ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVFrame ;
typedef  TYPE_4__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_ERROR ; 
 int /*<<< orphan*/  AV_LOG_INFO ; 
 int* angle_by_index ; 
 int av_frame_ref (void*,TYPE_3__*) ; 
 int /*<<< orphan*/  av_log (TYPE_4__*,int /*<<< orphan*/ ,char*,...) ; 
 int* block_coords ; 
 int bytestream2_get_be16 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_be24 (int /*<<< orphan*/ *) ; 
 int bytestream2_get_be24u (int /*<<< orphan*/ *) ; 
 int bytestream2_get_byte (int /*<<< orphan*/ *) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int bytestream2_get_byteu (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,size_t const*,int) ; 
 int ff_reget_buffer (TYPE_4__*,TYPE_3__*) ; 
 size_t* ulti_chromas ; 
 size_t* ulti_lumas ; 

__attribute__((used)) static void ulti_convert_yuv(AVFrame *frame, int x, int y,
                             uint8_t *luma,int chroma)
{
    uint8_t *y_plane, *cr_plane, *cb_plane;
    int i;

    y_plane = frame->data[0] + x + y * frame->linesize[0];
    cr_plane = frame->data[1] + (x / 4) + (y / 4) * frame->linesize[1];
    cb_plane = frame->data[2] + (x / 4) + (y / 4) * frame->linesize[2];

    cr_plane[0] = ulti_chromas[chroma >> 4];

    cb_plane[0] = ulti_chromas[chroma & 0xF];


    for(i = 0; i < 16; i++){
        y_plane[i & 3] = ulti_lumas[luma[i]];
        if((i & 3) == 3) { //next row
            y_plane += frame->linesize[0];
        }
    }
}

__attribute__((used)) static void ulti_pattern(AVFrame *frame, int x, int y,
                         int f0, int f1, int Y0, int Y1, int chroma)
{
    uint8_t Luma[16];
    int mask, i;
    for(mask = 0x80, i = 0; mask; mask >>= 1, i++) {
        if(f0 & mask)
            Luma[i] = Y1;
        else
            Luma[i] = Y0;
    }

    for(mask = 0x80, i = 8; mask; mask >>= 1, i++) {
        if(f1 & mask)
            Luma[i] = Y1;
        else
            Luma[i] = Y0;
    }

    ulti_convert_yuv(frame, x, y, Luma, chroma);
}

__attribute__((used)) static void ulti_grad(AVFrame *frame, int x, int y, uint8_t *Y, int chroma, int angle)
{
    uint8_t Luma[16];
    if(angle & 8) { //reverse order
        int t;
        angle &= 0x7;
        t = Y[0];
        Y[0] = Y[3];
        Y[3] = t;
        t = Y[1];
        Y[1] = Y[2];
        Y[2] = t;
    }
    switch(angle){
    case 0:
        Luma[0]  = Y[0]; Luma[1]  = Y[1]; Luma[2]  = Y[2]; Luma[3]  = Y[3];
        Luma[4]  = Y[0]; Luma[5]  = Y[1]; Luma[6]  = Y[2]; Luma[7]  = Y[3];
        Luma[8]  = Y[0]; Luma[9]  = Y[1]; Luma[10] = Y[2]; Luma[11] = Y[3];
        Luma[12] = Y[0]; Luma[13] = Y[1]; Luma[14] = Y[2]; Luma[15] = Y[3];
        break;
    case 1:
        Luma[0]  = Y[1]; Luma[1]  = Y[2]; Luma[2]  = Y[3]; Luma[3]  = Y[3];
        Luma[4]  = Y[0]; Luma[5]  = Y[1]; Luma[6]  = Y[2]; Luma[7]  = Y[3];
        Luma[8]  = Y[0]; Luma[9]  = Y[1]; Luma[10] = Y[2]; Luma[11] = Y[3];
        Luma[12] = Y[0]; Luma[13] = Y[0]; Luma[14] = Y[1]; Luma[15] = Y[2];
        break;
    case 2:
        Luma[0]  = Y[1]; Luma[1]  = Y[2]; Luma[2]  = Y[3]; Luma[3]  = Y[3];
        Luma[4]  = Y[1]; Luma[5]  = Y[2]; Luma[6]  = Y[2]; Luma[7]  = Y[3];
        Luma[8]  = Y[0]; Luma[9]  = Y[1]; Luma[10] = Y[1]; Luma[11] = Y[2];
        Luma[12] = Y[0]; Luma[13] = Y[0]; Luma[14] = Y[1]; Luma[15] = Y[2];
        break;
    case 3:
        Luma[0]  = Y[2]; Luma[1]  = Y[3]; Luma[2]  = Y[3]; Luma[3]  = Y[3];
        Luma[4]  = Y[1]; Luma[5]  = Y[2]; Luma[6]  = Y[2]; Luma[7]  = Y[3];
        Luma[8]  = Y[0]; Luma[9]  = Y[1]; Luma[10] = Y[1]; Luma[11] = Y[2];
        Luma[12] = Y[0]; Luma[13] = Y[0]; Luma[14] = Y[0]; Luma[15] = Y[1];
        break;
    case 4:
        Luma[0]  = Y[3]; Luma[1]  = Y[3]; Luma[2]  = Y[3]; Luma[3]  = Y[3];
        Luma[4]  = Y[2]; Luma[5]  = Y[2]; Luma[6]  = Y[2]; Luma[7]  = Y[2];
        Luma[8]  = Y[1]; Luma[9]  = Y[1]; Luma[10] = Y[1]; Luma[11] = Y[1];
        Luma[12] = Y[0]; Luma[13] = Y[0]; Luma[14] = Y[0]; Luma[15] = Y[0];
        break;
    case 5:
        Luma[0]  = Y[3]; Luma[1]  = Y[3]; Luma[2]  = Y[3]; Luma[3]  = Y[2];
        Luma[4]  = Y[3]; Luma[5]  = Y[2]; Luma[6]  = Y[2]; Luma[7]  = Y[1];
        Luma[8]  = Y[2]; Luma[9]  = Y[1]; Luma[10] = Y[1]; Luma[11] = Y[0];
        Luma[12] = Y[1]; Luma[13] = Y[0]; Luma[14] = Y[0]; Luma[15] = Y[0];
        break;
    case 6:
        Luma[0]  = Y[3]; Luma[1]  = Y[3]; Luma[2]  = Y[2]; Luma[3]  = Y[2];
        Luma[4]  = Y[3]; Luma[5]  = Y[2]; Luma[6]  = Y[1]; Luma[7]  = Y[1];
        Luma[8]  = Y[2]; Luma[9]  = Y[2]; Luma[10] = Y[1]; Luma[11] = Y[0];
        Luma[12] = Y[1]; Luma[13] = Y[1]; Luma[14] = Y[0]; Luma[15] = Y[0];
        break;
    case 7:
        Luma[0]  = Y[3]; Luma[1]  = Y[3]; Luma[2]  = Y[2]; Luma[3]  = Y[1];
        Luma[4]  = Y[3]; Luma[5]  = Y[2]; Luma[6]  = Y[1]; Luma[7]  = Y[0];
        Luma[8]  = Y[3]; Luma[9]  = Y[2]; Luma[10] = Y[1]; Luma[11] = Y[0];
        Luma[12] = Y[2]; Luma[13] = Y[1]; Luma[14] = Y[0]; Luma[15] = Y[0];
        break;
    default:
        Luma[0]  = Y[0]; Luma[1]  = Y[0]; Luma[2]  = Y[1]; Luma[3]  = Y[1];
        Luma[4]  = Y[0]; Luma[5]  = Y[0]; Luma[6]  = Y[1]; Luma[7]  = Y[1];
        Luma[8]  = Y[2]; Luma[9]  = Y[2]; Luma[10] = Y[3]; Luma[11] = Y[3];
        Luma[12] = Y[2]; Luma[13] = Y[2]; Luma[14] = Y[3]; Luma[15] = Y[3];
        break;
    }

    ulti_convert_yuv(frame, x, y, Luma, chroma);
}

__attribute__((used)) static int ulti_decode_frame(AVCodecContext *avctx,
                             void *data, int *got_frame,
                             AVPacket *avpkt)
{
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    UltimotionDecodeContext *s=avctx->priv_data;
    int modifier = 0;
    int uniq = 0;
    int mode = 0;
    int blocks = 0;
    int done = 0;
    int x = 0, y = 0;
    int i, ret;
    int skip;
    int tmp;

    if ((ret = ff_reget_buffer(avctx, s->frame)) < 0)
        return ret;

    bytestream2_init(&s->gb, buf, buf_size);

    while(!done) {
        int idx;
        if(blocks >= s->blocks || y >= s->height)
            break;//all blocks decoded

        if (bytestream2_get_bytes_left(&s->gb) < 1)
            goto err;
        idx = bytestream2_get_byteu(&s->gb);
        if((idx & 0xF8) == 0x70) {
            switch(idx) {
            case 0x70: //change modifier
                modifier = bytestream2_get_byte(&s->gb);
                if(modifier>1)
                    av_log(avctx, AV_LOG_INFO, "warning: modifier must be 0 or 1, got %i\n", modifier);
                break;
            case 0x71: // set uniq flag
                uniq = 1;
                break;
            case 0x72: //toggle mode
                mode = !mode;
                break;
            case 0x73: //end-of-frame
                done = 1;
                break;
            case 0x74: //skip some blocks
                skip = bytestream2_get_byte(&s->gb);
                if ((blocks + skip) >= s->blocks)
                    break;
                blocks += skip;
                x += skip * 8;
                while(x >= s->width) {
                    x -= s->width;
                    y += 8;
                }
                break;
            default:
                av_log(avctx, AV_LOG_INFO, "warning: unknown escape 0x%02X\n", idx);
            }
        } else { //handle one block
            int code;
            int cf;
            int angle = 0;
            uint8_t Y[4]; // luma samples of block
            int tx = 0, ty = 0; //coords of subblock
            int chroma = 0;
            if (mode || uniq) {
                uniq = 0;
                cf = 1;
                chroma = 0;
            } else {
                cf = 0;
                if (idx) {
                    chroma = bytestream2_get_byte(&s->gb);
                }
            }
            for (i = 0; i < 4; i++) { // for every subblock
                code = (idx >> (6 - i*2)) & 3; //extract 2 bits
                if(!code) //skip subblock
                    continue;
                if(cf) {
                    chroma = bytestream2_get_byte(&s->gb);
                }
                tx = x + block_coords[i * 2];
                ty = y + block_coords[(i * 2) + 1];
                switch(code) {
                case 1:
                    tmp = bytestream2_get_byte(&s->gb);

                    angle = angle_by_index[(tmp >> 6) & 0x3];

                    Y[0] = tmp & 0x3F;
                    Y[1] = Y[0];

                    if (angle) {
                        Y[2] = Y[0]+1;
                        if (Y[2] > 0x3F)
                            Y[2] = 0x3F;
                        Y[3] = Y[2];
                    } else {
                        Y[2] = Y[0];
                        Y[3] = Y[0];
                    }
                    break;

                case 2:
                    if (modifier) { // unpack four luma samples
                        tmp = bytestream2_get_be24(&s->gb);

                        Y[0] = (tmp >> 18) & 0x3F;
                        Y[1] = (tmp >> 12) & 0x3F;
                        Y[2] = (tmp >> 6) & 0x3F;
                        Y[3] = tmp & 0x3F;
                        angle = 16;
                    } else { // retrieve luma samples from codebook
                        tmp = bytestream2_get_be16(&s->gb);

                        angle = (tmp >> 12) & 0xF;
                        tmp &= 0xFFF;
                        tmp <<= 2;
                        Y[0] = s->ulti_codebook[tmp];
                        Y[1] = s->ulti_codebook[tmp + 1];
                        Y[2] = s->ulti_codebook[tmp + 2];
                        Y[3] = s->ulti_codebook[tmp + 3];
                    }
                    break;

                case 3:
                    if (modifier) { // all 16 luma samples
                        uint8_t Luma[16];

                        if (bytestream2_get_bytes_left(&s->gb) < 12)
                            goto err;
                        tmp = bytestream2_get_be24u(&s->gb);
                        Luma[0] = (tmp >> 18) & 0x3F;
                        Luma[1] = (tmp >> 12) & 0x3F;
                        Luma[2] = (tmp >> 6) & 0x3F;
                        Luma[3] = tmp & 0x3F;

                        tmp = bytestream2_get_be24u(&s->gb);
                        Luma[4] = (tmp >> 18) & 0x3F;
                        Luma[5] = (tmp >> 12) & 0x3F;
                        Luma[6] = (tmp >> 6) & 0x3F;
                        Luma[7] = tmp & 0x3F;

                        tmp = bytestream2_get_be24u(&s->gb);
                        Luma[8] = (tmp >> 18) & 0x3F;
                        Luma[9] = (tmp >> 12) & 0x3F;
                        Luma[10] = (tmp >> 6) & 0x3F;
                        Luma[11] = tmp & 0x3F;

                        tmp = bytestream2_get_be24u(&s->gb);
                        Luma[12] = (tmp >> 18) & 0x3F;
                        Luma[13] = (tmp >> 12) & 0x3F;
                        Luma[14] = (tmp >> 6) & 0x3F;
                        Luma[15] = tmp & 0x3F;

                        ulti_convert_yuv(s->frame, tx, ty, Luma, chroma);
                    } else {
                        if (bytestream2_get_bytes_left(&s->gb) < 4)
                            goto err;
                        tmp = bytestream2_get_byteu(&s->gb);
                        if(tmp & 0x80) {
                            angle = (tmp >> 4) & 0x7;
                            tmp = (tmp << 8) + bytestream2_get_byteu(&s->gb);
                            Y[0] = (tmp >> 6) & 0x3F;
                            Y[1] = tmp & 0x3F;
                            Y[2] = bytestream2_get_byteu(&s->gb) & 0x3F;
                            Y[3] = bytestream2_get_byteu(&s->gb) & 0x3F;
                            ulti_grad(s->frame, tx, ty, Y, chroma, angle); //draw block
                        } else { // some patterns
                            int f0 = tmp;
                            int f1 = bytestream2_get_byteu(&s->gb);
                            Y[0] = bytestream2_get_byteu(&s->gb) & 0x3F;
                            Y[1] = bytestream2_get_byteu(&s->gb) & 0x3F;
                            ulti_pattern(s->frame, tx, ty, f0, f1, Y[0], Y[1], chroma);
                        }
                    }
                    break;
                }
                if(code != 3)
                    ulti_grad(s->frame, tx, ty, Y, chroma, angle); // draw block
            }
            blocks++;
                x += 8;
            if(x >= s->width) {
                x = 0;
                y += 8;
            }
        }
    }

    *got_frame = 1;
    if ((ret = av_frame_ref(data, s->frame)) < 0)
        return ret;

    return buf_size;

err:
    av_log(avctx, AV_LOG_ERROR,
           "Insufficient data\n");
    return AVERROR_INVALIDDATA;
}

