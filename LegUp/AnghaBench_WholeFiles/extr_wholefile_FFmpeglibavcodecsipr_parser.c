#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
struct TYPE_9__ {int block_align; int bit_rate; } ;
struct TYPE_8__ {TYPE_1__* priv_data; } ;
struct TYPE_7__ {int /*<<< orphan*/  pc; } ;
typedef  TYPE_1__ SiprParserContext ;
typedef  int /*<<< orphan*/  ParseContext ;
typedef  TYPE_2__ AVCodecParserContext ;
typedef  TYPE_3__ AVCodecContext ;

/* Variables and functions */
 int FFMIN (int,int) ; 
 scalar_t__ ff_combine_frame (int /*<<< orphan*/ *,int,int /*<<< orphan*/  const**,int*) ; 

__attribute__((used)) static int sipr_split(AVCodecContext *avctx, const uint8_t *buf, int buf_size)
{
    int next;

    switch (avctx->block_align) {
    case 20:
    case 19:
    case 29:
    case 37: next = avctx->block_align; break;
    default:
        if      (avctx->bit_rate > 12200) next = 20;
        else if (avctx->bit_rate > 7500 ) next = 19;
        else if (avctx->bit_rate > 5750 ) next = 29;
        else                              next = 37;
    }

    return FFMIN(next, buf_size);
}

__attribute__((used)) static int sipr_parse(AVCodecParserContext *s1, AVCodecContext *avctx,
                      const uint8_t **poutbuf, int *poutbuf_size,
                      const uint8_t *buf, int buf_size)
{
    SiprParserContext *s = s1->priv_data;
    ParseContext *pc = &s->pc;
    int next;

    next = sipr_split(avctx, buf, buf_size);
    if (ff_combine_frame(pc, next, &buf, &buf_size) < 0) {
        *poutbuf = NULL;
        *poutbuf_size = 0;
        return buf_size;
    }

    *poutbuf      = buf;
    *poutbuf_size = buf_size;
    return next;
}

