#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_5__ {int* raster_end; } ;
struct TYPE_6__ {size_t* block_last_index; TYPE_1__ inter_scantable; scalar_t__ ac_pred; int /*<<< orphan*/  c_dc_scale; int /*<<< orphan*/  y_dc_scale; int /*<<< orphan*/  h263_aic; } ;
typedef  TYPE_2__ MpegEncContext ;

/* Variables and functions */
 int cmpbge (int,int) ; 
 int ldq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stq (int,int /*<<< orphan*/ *) ; 
 int zap (int,int) ; 

__attribute__((used)) static inline uint64_t BYTE_VEC(uint64_t x)
{
    x |= x <<  8;
    x |= x << 16;
    x |= x << 32;
    return x;
}

__attribute__((used)) static inline uint64_t WORD_VEC(uint64_t x)
{
    x |= x << 16;
    x |= x << 32;
    return x;
}

__attribute__((used)) static void dct_unquantize_h263_axp(int16_t *block, int n_coeffs,
                                    uint64_t qscale, uint64_t qadd)
{
    uint64_t qmul = qscale << 1;
    uint64_t correction = WORD_VEC(qmul * 255 >> 8);
    int i;

    qadd = WORD_VEC(qadd);

    for(i = 0; i <= n_coeffs; block += 4, i += 4) {
        uint64_t levels, negmask, zeros, add, sub;

        levels = ldq(block);
        if (levels == 0)
            continue;

#ifdef __alpha_max__
        /* I don't think the speed difference justifies runtime
           detection.  */
        negmask = maxsw4(levels, -1); /* negative -> ffff (-1) */
        negmask = minsw4(negmask, 0); /* positive -> 0000 (0) */
#else
        negmask = cmpbge(WORD_VEC(0x7fff), levels);
        negmask &= (negmask >> 1) | (1 << 7);
        negmask = zap(-1, negmask);
#endif

        zeros = cmpbge(0, levels);
        zeros &= zeros >> 1;
        /* zeros |= zeros << 1 is not needed since qadd <= 255, so
           zapping the lower byte suffices.  */

        levels *= qmul;
        levels -= correction & (negmask << 16);

        add = qadd & ~negmask;
        sub = qadd &  negmask;
        /* Set qadd to 0 for levels == 0.  */
        add = zap(add, zeros);
        levels += add;
        levels -= sub;

        stq(levels, block);
    }
}

__attribute__((used)) static void dct_unquantize_h263_intra_axp(MpegEncContext *s, int16_t *block,
                                    int n, int qscale)
{
    int n_coeffs;
    uint64_t qadd;
    int16_t block0 = block[0];

    if (!s->h263_aic) {
        if (n < 4)
            block0 *= s->y_dc_scale;
        else
            block0 *= s->c_dc_scale;
        qadd = (qscale - 1) | 1;
    } else {
        qadd = 0;
    }

    if(s->ac_pred)
        n_coeffs = 63;
    else
        n_coeffs = s->inter_scantable.raster_end[s->block_last_index[n]];

    dct_unquantize_h263_axp(block, n_coeffs, qscale, qadd);

    block[0] = block0;
}

__attribute__((used)) static void dct_unquantize_h263_inter_axp(MpegEncContext *s, int16_t *block,
                                    int n, int qscale)
{
    int n_coeffs = s->inter_scantable.raster_end[s->block_last_index[n]];
    dct_unquantize_h263_axp(block, n_coeffs, qscale, (qscale - 1) | 1);
}

