#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_9__ {int y; int font_height; scalar_t__ x; int /*<<< orphan*/  palette; TYPE_5__* frame; int /*<<< orphan*/  font; } ;
typedef  TYPE_1__ XbinContext ;
struct TYPE_12__ {scalar_t__* data; int* linesize; int palette_has_changed; int /*<<< orphan*/  pict_type; } ;
struct TYPE_11__ {int height; scalar_t__ width; scalar_t__ codec_id; TYPE_1__* priv_data; } ;
struct TYPE_10__ {int* data; int size; } ;
typedef  TYPE_2__ AVPacket ;
typedef  TYPE_3__ AVCodecContext ;

/* Variables and functions */
 int AVERROR_INVALIDDATA ; 
 scalar_t__ AV_CODEC_ID_IDF ; 
 scalar_t__ AV_CODEC_ID_XBIN ; 
 int /*<<< orphan*/  AV_PICTURE_TYPE_I ; 
 int AV_RL16 (int const*) ; 
 int FONT_WIDTH ; 
 int /*<<< orphan*/  ff_draw_pc_font (scalar_t__,int,int /*<<< orphan*/ ,int,int,int,int) ; 
 int ff_get_buffer (TYPE_3__*,TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void draw_char(AVCodecContext *avctx, int c, int a)
{
    XbinContext *s = avctx->priv_data;
    if (s->y > avctx->height - s->font_height)
        return;
    ff_draw_pc_font(s->frame->data[0] + s->y * s->frame->linesize[0] + s->x,
                    s->frame->linesize[0], s->font, s->font_height, c,
                    a & 0x0F, a >> 4);
    s->x += FONT_WIDTH;
    if (s->x > avctx->width - FONT_WIDTH) {
        s->x = 0;
        s->y += s->font_height;
    }
}

__attribute__((used)) static int decode_frame(AVCodecContext *avctx,
                            void *data, int *got_frame,
                            AVPacket *avpkt)
{
    XbinContext *s = avctx->priv_data;
    const uint8_t *buf = avpkt->data;
    int buf_size = avpkt->size;
    const uint8_t *buf_end = buf+buf_size;
    int ret;

    if ((avctx->width / FONT_WIDTH) * (avctx->height / s->font_height) / 256 > buf_size)
        return AVERROR_INVALIDDATA;

    s->frame = data;
    s->x = s->y = 0;
    if ((ret = ff_get_buffer(avctx, s->frame, 0)) < 0)
        return ret;
    s->frame->pict_type           = AV_PICTURE_TYPE_I;
    s->frame->palette_has_changed = 1;
    memcpy(s->frame->data[1], s->palette, 16 * 4);

    if (avctx->codec_id == AV_CODEC_ID_XBIN) {
        while (buf + 2 < buf_end) {
            int i,c,a;
            int type  = *buf >> 6;
            int count = (*buf & 0x3F) + 1;
            buf++;
            switch (type) {
            case 0: //no compression
                for (i = 0; i < count && buf + 1 < buf_end; i++) {
                    draw_char(avctx, buf[0], buf[1]);
                    buf += 2;
                }
                break;
            case 1: //character compression
                c = *buf++;
                for (i = 0; i < count && buf < buf_end; i++)
                    draw_char(avctx, c, *buf++);
                break;
            case 2: //attribute compression
                a = *buf++;
                for (i = 0; i < count && buf < buf_end; i++)
                    draw_char(avctx, *buf++, a);
                break;
            case 3: //character/attribute compression
                c = *buf++;
                a = *buf++;
                for (i = 0; i < count && buf < buf_end; i++)
                    draw_char(avctx, c, a);
                break;
            }
        }
    } else if (avctx->codec_id == AV_CODEC_ID_IDF) {
        while (buf + 2 < buf_end) {
            if (AV_RL16(buf) == 1) {
               int i;
               if (buf + 6 > buf_end)
                   break;
               for (i = 0; i < buf[2]; i++)
                   draw_char(avctx, buf[4], buf[5]);
               buf += 6;
            } else {
               draw_char(avctx, buf[0], buf[1]);
               buf += 2;
            }
        }
    } else {
        while (buf + 1 < buf_end) {
            draw_char(avctx, buf[0], buf[1]);
            buf += 2;
        }
    }

    *got_frame      = 1;
    return buf_size;
}

