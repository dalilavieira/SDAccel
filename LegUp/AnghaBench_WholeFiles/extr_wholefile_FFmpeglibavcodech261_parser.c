#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
struct TYPE_7__ {int flags; TYPE_1__* priv_data; } ;
struct TYPE_6__ {int frame_start_found; int state; } ;
typedef  TYPE_1__ ParseContext ;
typedef  TYPE_2__ AVCodecParserContext ;
typedef  int /*<<< orphan*/  AVCodecContext ;

/* Variables and functions */
 int END_NOT_FOUND ; 
 int PARSER_FLAG_COMPLETE_FRAMES ; 
 scalar_t__ ff_combine_frame (TYPE_1__*,int,int const**,int*) ; 

__attribute__((used)) static int h261_find_frame_end(ParseContext *pc, AVCodecContext *avctx,
                               const uint8_t *buf, int buf_size)
{
    int vop_found, i, j;
    uint32_t state;

    vop_found = pc->frame_start_found;
    state     = pc->state;

    for (i = 0; i < buf_size && !vop_found; i++) {
        state = (state << 8) | buf[i];
        for (j = 0; j < 8; j++) {
            if (((state >> j) & 0xFFFFF0) == 0x000100) {
                vop_found = 1;
                break;
            }
        }
    }
    if (vop_found) {
        for (; i < buf_size; i++) {
            state = (state << 8) | buf[i];
            for (j = 0; j < 8; j++) {
                if (((state >> j) & 0xFFFFF0) == 0x000100) {
                    pc->frame_start_found = 0;
                    pc->state             = (state >> (3 * 8)) + 0xFF00;
                    return i - 2;
                }
            }
        }
    }

    pc->frame_start_found = vop_found;
    pc->state             = state;
    return END_NOT_FOUND;
}

__attribute__((used)) static int h261_parse(AVCodecParserContext *s,
                      AVCodecContext *avctx,
                      const uint8_t **poutbuf, int *poutbuf_size,
                      const uint8_t *buf, int buf_size)
{
    ParseContext *pc = s->priv_data;
    int next;

    if (s->flags & PARSER_FLAG_COMPLETE_FRAMES) {
        next = buf_size;
    } else {
        next = h261_find_frame_end(pc, avctx, buf, buf_size);
        if (ff_combine_frame(pc, next, &buf, &buf_size) < 0) {
            *poutbuf      = NULL;
            *poutbuf_size = 0;
            return buf_size;
        }
    }
    *poutbuf      = buf;
    *poutbuf_size = buf_size;
    return next;
}

