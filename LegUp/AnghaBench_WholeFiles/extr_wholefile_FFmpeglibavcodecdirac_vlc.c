#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int residual ;
typedef  int int32_t ;
typedef  int int16_t ;
struct TYPE_7__ {int sign; int preamble; int* ready; size_t ready_num; int leftover; int need_s; int leftover_bits; int preamble_bits; } ;
typedef  TYPE_1__ DiracGolombLUT ;

/* Variables and functions */
 int /*<<< orphan*/  APPEND_RESIDUE (int,int) ; 
 void* CONVERT_TO_RESIDUE (int,int) ; 
 int /*<<< orphan*/  INIT_RESIDUE (int) ; 
 int LUT_BITS ; 
 int LUT_SIZE ; 
 int RSIZE_BITS ; 
 int /*<<< orphan*/  SET_RESIDUE (int,int,int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int res ; 
 int res_bits ; 

int ff_dirac_golomb_read_32bit(DiracGolombLUT *lut_ctx, const uint8_t *buf,
                               int bytes, uint8_t *_dst, int coeffs)
{
    int i, b, c_idx = 0;
    int32_t *dst = (int32_t *)_dst;
    DiracGolombLUT *future[4], *l = &lut_ctx[2*LUT_SIZE + buf[0]];
    INIT_RESIDUE(res);

    for (b = 1; b <= bytes; b++) {
        future[0] = &lut_ctx[buf[b]];
        future[1] = future[0] + 1*LUT_SIZE;
        future[2] = future[0] + 2*LUT_SIZE;
        future[3] = future[0] + 3*LUT_SIZE;

        if ((c_idx + 1) > coeffs)
            return c_idx;

        /* res_bits is a hint for better branch prediction */
        if (res_bits && l->sign) {
            int32_t coeff = 1;
            APPEND_RESIDUE(res, l->preamble);
            for (i = 0; i < (res_bits >> 1) - 1; i++) {
                coeff <<= 1;
                coeff |= (res >> (RSIZE_BITS - 2*i - 2)) & 1;
            }
            dst[c_idx++] = l->sign * (coeff - 1);
            res_bits = res = 0;
        }

        memcpy(&dst[c_idx], l->ready, LUT_BITS*sizeof(int32_t));
        c_idx += l->ready_num;

        APPEND_RESIDUE(res, l->leftover);

        l = future[l->need_s ? 3 : !res_bits ? 2 : res_bits & 1];
    }

    return c_idx;
}

int ff_dirac_golomb_read_16bit(DiracGolombLUT *lut_ctx, const uint8_t *buf,
                               int bytes, uint8_t *_dst, int coeffs)
{
    int i, b, c_idx = 0;
    int16_t *dst = (int16_t *)_dst;
    DiracGolombLUT *future[4], *l = &lut_ctx[2*LUT_SIZE + buf[0]];
    INIT_RESIDUE(res);

    for (b = 1; b <= bytes; b++) {
        future[0] = &lut_ctx[buf[b]];
        future[1] = future[0] + 1*LUT_SIZE;
        future[2] = future[0] + 2*LUT_SIZE;
        future[3] = future[0] + 3*LUT_SIZE;

        if ((c_idx + 1) > coeffs)
            return c_idx;

        if (res_bits && l->sign) {
            int32_t coeff = 1;
            APPEND_RESIDUE(res, l->preamble);
            for (i = 0; i < (res_bits >> 1) - 1; i++) {
                coeff <<= 1;
                coeff |= (res >> (RSIZE_BITS - 2*i - 2)) & 1;
            }
            dst[c_idx++] = l->sign * (coeff - 1);
            res_bits = res = 0;
        }

        for (i = 0; i < LUT_BITS; i++)
            dst[c_idx + i] = l->ready[i];
        c_idx += l->ready_num;

        APPEND_RESIDUE(res, l->leftover);

        l = future[l->need_s ? 3 : !res_bits ? 2 : res_bits & 1];
    }

    return c_idx;
}

__attribute__((used)) static inline void search_for_golomb(DiracGolombLUT *l, residual r, int bits)
{
    int r_count = RSIZE_BITS - 1;
    int bits_start, bits_tot = bits, need_sign = 0;

#define READ_BIT(N) (((N) >> (N ## _count--)) & 1)

    while (1) {
        int32_t coef = 1;
        bits_start = (RSIZE_BITS - 1) - r_count;

        while (1) {
            if (!bits--)
                goto leftover;
            if (READ_BIT(r))
                break;

            coef <<= 1;

            if (!bits--)
                goto leftover;
            coef |= READ_BIT(r);
        }

        l->ready[l->ready_num] = coef - 1;
        if (l->ready[l->ready_num]) {
            if (!bits--) {
                need_sign = 1;
                goto leftover;
            }
            l->ready[l->ready_num] *= READ_BIT(r) ? -1 : +1;
        }
        l->ready_num++;

        if (!bits)
            return;
    }

    leftover:
        l->leftover      = r << bits_start;
        l->leftover_bits = bits_tot - bits_start;
        l->need_s        = need_sign;
}

__attribute__((used)) static void generate_parity_lut(DiracGolombLUT *lut, int even)
{
    int idx;
    for (idx = 0; idx < LUT_SIZE; idx++) {
        DiracGolombLUT *l = &lut[idx];
        int symbol_end_loc = -1;
        uint32_t code;
        int i;

        INIT_RESIDUE(res);
        SET_RESIDUE(res, idx, LUT_BITS);

        for (i = 0; i < LUT_BITS; i++) {
            const int cond = even ? (i & 1) : !(i & 1);
            if (((res >> (RSIZE_BITS - i - 1)) & 1) && cond) {
                symbol_end_loc = i + 2;
                break;
            }
        }

        if (symbol_end_loc < 0 || symbol_end_loc > LUT_BITS) {
            l->preamble      = 0;
            l->preamble_bits = 0;
            l->leftover_bits = LUT_BITS;
            l->leftover      = CONVERT_TO_RESIDUE(idx, l->leftover_bits);
            if (even)
                l->need_s    = idx & 1;
            continue;
        }

        /* Gets bits 0 through to (symbol_end_loc - 1) inclusive */
        code  = idx >> ((LUT_BITS - 1) - (symbol_end_loc - 1));
        code &= ((1 << LUT_BITS) - 1) >> (LUT_BITS - symbol_end_loc);
        l->preamble_bits = symbol_end_loc;
        l->preamble      = CONVERT_TO_RESIDUE(code, l->preamble_bits);
        l->sign = ((l->preamble >> (RSIZE_BITS - l->preamble_bits)) & 1) ? -1 : +1;

        search_for_golomb(l, res << symbol_end_loc, LUT_BITS - symbol_end_loc);
    }
}

__attribute__((used)) static void generate_offset_lut(DiracGolombLUT *lut, int off)
{
    int idx;
    for (idx = 0; idx < LUT_SIZE; idx++) {
        DiracGolombLUT *l = &lut[idx];

        INIT_RESIDUE(res);
        SET_RESIDUE(res, idx, LUT_BITS);

        l->preamble_bits = off;
        if (off) {
            l->preamble  = CONVERT_TO_RESIDUE(res >> (RSIZE_BITS - off), off);
            l->sign      = ((l->preamble >> (RSIZE_BITS - l->preamble_bits)) & 1) ? -1 : +1;
        } else {
            l->preamble  = 0;
            l->sign = 1;
        }

        search_for_golomb(l, res << off, LUT_BITS - off);
    }
}

