#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  int16_t ;
struct TYPE_6__ {void (* sbc_analyze_8s ) (TYPE_1__*,int /*<<< orphan*/ *,int*,int) ;int /*<<< orphan*/  (* sbc_analyze_8 ) (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* sbc_analyze_4 ) (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_1__ SBCDSPContext ;

/* Variables and functions */
 int /*<<< orphan*/  AV_RN16 (int /*<<< orphan*/  const*) ; 
 int FFABS (int) ; 
 int SBC_X_BUFFER_SIZE ; 
 int SCALE_OUT_BITS ; 
 int ff_clz (int) ; 
 int /*<<< orphan*/  ff_sbcdsp_analysis_consts_fixed4_simd_even ; 
 int /*<<< orphan*/  ff_sbcdsp_analysis_consts_fixed4_simd_odd ; 
 int /*<<< orphan*/  ff_sbcdsp_analysis_consts_fixed8_simd_even ; 
 int /*<<< orphan*/  ff_sbcdsp_analysis_consts_fixed8_simd_odd ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
static  void sbc_analyze_1b_8s_simd_even (TYPE_1__*,int /*<<< orphan*/ *,int*,int) ; 
 int /*<<< orphan*/  sbc_analyze_simd (int /*<<< orphan*/  const*,int*,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub10 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void sbc_analyze_4_simd(const int16_t *in, int32_t *out,
                               const int16_t *consts)
{
    sbc_analyze_simd(in, out, consts, 4);
}

__attribute__((used)) static void sbc_analyze_8_simd(const int16_t *in, int32_t *out,
                               const int16_t *consts)
{
    sbc_analyze_simd(in, out, consts, 8);
}

__attribute__((used)) static inline void sbc_analyze_4b_4s_simd(SBCDSPContext *s,
                                          int16_t *x, int32_t *out, int out_stride)
{
    /* Analyze blocks */
    s->sbc_analyze_4(x + 12, out, ff_sbcdsp_analysis_consts_fixed4_simd_odd);
    out += out_stride;
    s->sbc_analyze_4(x + 8, out, ff_sbcdsp_analysis_consts_fixed4_simd_even);
    out += out_stride;
    s->sbc_analyze_4(x + 4, out, ff_sbcdsp_analysis_consts_fixed4_simd_odd);
    out += out_stride;
    s->sbc_analyze_4(x + 0, out, ff_sbcdsp_analysis_consts_fixed4_simd_even);
}

__attribute__((used)) static inline void sbc_analyze_4b_8s_simd(SBCDSPContext *s,
                                          int16_t *x, int32_t *out, int out_stride)
{
    /* Analyze blocks */
    s->sbc_analyze_8(x + 24, out, ff_sbcdsp_analysis_consts_fixed8_simd_odd);
    out += out_stride;
    s->sbc_analyze_8(x + 16, out, ff_sbcdsp_analysis_consts_fixed8_simd_even);
    out += out_stride;
    s->sbc_analyze_8(x + 8, out, ff_sbcdsp_analysis_consts_fixed8_simd_odd);
    out += out_stride;
    s->sbc_analyze_8(x + 0, out, ff_sbcdsp_analysis_consts_fixed8_simd_even);
}

__attribute__((used)) static inline void sbc_analyze_1b_8s_simd_odd(SBCDSPContext *s,
                                              int16_t *x, int32_t *out,
                                              int out_stride)
{
    s->sbc_analyze_8(x, out, ff_sbcdsp_analysis_consts_fixed8_simd_odd);
    s->sbc_analyze_8s = sbc_analyze_1b_8s_simd_even;
}

__attribute__((used)) static inline void sbc_analyze_1b_8s_simd_even(SBCDSPContext *s,
                                               int16_t *x, int32_t *out,
                                               int out_stride)
{
    s->sbc_analyze_8(x, out, ff_sbcdsp_analysis_consts_fixed8_simd_even);
    s->sbc_analyze_8s = sbc_analyze_1b_8s_simd_odd;
}

__attribute__((used)) static int sbc_enc_process_input_4s(int position, const uint8_t *pcm,
                                    int16_t X[2][SBC_X_BUFFER_SIZE],
                                    int nsamples, int nchannels)
{
    int c;

    /* handle X buffer wraparound */
    if (position < nsamples) {
        for (c = 0; c < nchannels; c++)
            memcpy(&X[c][SBC_X_BUFFER_SIZE - 40], &X[c][position],
                            36 * sizeof(int16_t));
        position = SBC_X_BUFFER_SIZE - 40;
    }

    /* copy/permutate audio samples */
    for (; nsamples >= 8; nsamples -= 8, pcm += 16 * nchannels) {
        position -= 8;
        for (c = 0; c < nchannels; c++) {
            int16_t *x = &X[c][position];
            x[0] = AV_RN16(pcm + 14*nchannels + 2*c);
            x[1] = AV_RN16(pcm +  6*nchannels + 2*c);
            x[2] = AV_RN16(pcm + 12*nchannels + 2*c);
            x[3] = AV_RN16(pcm +  8*nchannels + 2*c);
            x[4] = AV_RN16(pcm +  0*nchannels + 2*c);
            x[5] = AV_RN16(pcm +  4*nchannels + 2*c);
            x[6] = AV_RN16(pcm +  2*nchannels + 2*c);
            x[7] = AV_RN16(pcm + 10*nchannels + 2*c);
        }
    }

    return position;
}

__attribute__((used)) static int sbc_enc_process_input_8s(int position, const uint8_t *pcm,
                                    int16_t X[2][SBC_X_BUFFER_SIZE],
                                    int nsamples, int nchannels)
{
    int c;

    /* handle X buffer wraparound */
    if (position < nsamples) {
        for (c = 0; c < nchannels; c++)
            memcpy(&X[c][SBC_X_BUFFER_SIZE - 72], &X[c][position],
                            72 * sizeof(int16_t));
        position = SBC_X_BUFFER_SIZE - 72;
    }

    if (position % 16 == 8) {
        position -= 8;
        nsamples -= 8;
        for (c = 0; c < nchannels; c++) {
            int16_t *x = &X[c][position];
            x[0] = AV_RN16(pcm + 14*nchannels + 2*c);
            x[2] = AV_RN16(pcm + 12*nchannels + 2*c);
            x[3] = AV_RN16(pcm +  0*nchannels + 2*c);
            x[4] = AV_RN16(pcm + 10*nchannels + 2*c);
            x[5] = AV_RN16(pcm +  2*nchannels + 2*c);
            x[6] = AV_RN16(pcm +  8*nchannels + 2*c);
            x[7] = AV_RN16(pcm +  4*nchannels + 2*c);
            x[8] = AV_RN16(pcm +  6*nchannels + 2*c);
        }
        pcm += 16 * nchannels;
    }

    /* copy/permutate audio samples */
    for (; nsamples >= 16; nsamples -= 16, pcm += 32 * nchannels) {
        position -= 16;
        for (c = 0; c < nchannels; c++) {
            int16_t *x = &X[c][position];
            x[0]  = AV_RN16(pcm + 30*nchannels + 2*c);
            x[1]  = AV_RN16(pcm + 14*nchannels + 2*c);
            x[2]  = AV_RN16(pcm + 28*nchannels + 2*c);
            x[3]  = AV_RN16(pcm + 16*nchannels + 2*c);
            x[4]  = AV_RN16(pcm + 26*nchannels + 2*c);
            x[5]  = AV_RN16(pcm + 18*nchannels + 2*c);
            x[6]  = AV_RN16(pcm + 24*nchannels + 2*c);
            x[7]  = AV_RN16(pcm + 20*nchannels + 2*c);
            x[8]  = AV_RN16(pcm + 22*nchannels + 2*c);
            x[9]  = AV_RN16(pcm +  6*nchannels + 2*c);
            x[10] = AV_RN16(pcm + 12*nchannels + 2*c);
            x[11] = AV_RN16(pcm +  0*nchannels + 2*c);
            x[12] = AV_RN16(pcm + 10*nchannels + 2*c);
            x[13] = AV_RN16(pcm +  2*nchannels + 2*c);
            x[14] = AV_RN16(pcm +  8*nchannels + 2*c);
            x[15] = AV_RN16(pcm +  4*nchannels + 2*c);
        }
    }

    if (nsamples == 8) {
        position -= 8;
        for (c = 0; c < nchannels; c++) {
            int16_t *x = &X[c][position];
            x[-7] = AV_RN16(pcm + 14*nchannels + 2*c);
            x[1]  = AV_RN16(pcm +  6*nchannels + 2*c);
            x[2]  = AV_RN16(pcm + 12*nchannels + 2*c);
            x[3]  = AV_RN16(pcm +  0*nchannels + 2*c);
            x[4]  = AV_RN16(pcm + 10*nchannels + 2*c);
            x[5]  = AV_RN16(pcm +  2*nchannels + 2*c);
            x[6]  = AV_RN16(pcm +  8*nchannels + 2*c);
            x[7]  = AV_RN16(pcm +  4*nchannels + 2*c);
        }
    }

    return position;
}

__attribute__((used)) static void sbc_calc_scalefactors(int32_t sb_sample_f[16][2][8],
                                  uint32_t scale_factor[2][8],
                                  int blocks, int channels, int subbands)
{
    int ch, sb, blk;
    for (ch = 0; ch < channels; ch++) {
        for (sb = 0; sb < subbands; sb++) {
            uint32_t x = 1 << SCALE_OUT_BITS;
            for (blk = 0; blk < blocks; blk++) {
                int32_t tmp = FFABS(sb_sample_f[blk][ch][sb]);
                if (tmp != 0)
                    x |= tmp - 1;
            }
            scale_factor[ch][sb] = (31 - SCALE_OUT_BITS) - ff_clz(x);
        }
    }
}

__attribute__((used)) static int sbc_calc_scalefactors_j(int32_t sb_sample_f[16][2][8],
                                   uint32_t scale_factor[2][8],
                                   int blocks, int subbands)
{
    int blk, joint = 0;
    int32_t tmp0, tmp1;
    uint32_t x, y;

    /* last subband does not use joint stereo */
    int sb = subbands - 1;
    x = 1 << SCALE_OUT_BITS;
    y = 1 << SCALE_OUT_BITS;
    for (blk = 0; blk < blocks; blk++) {
        tmp0 = FFABS(sb_sample_f[blk][0][sb]);
        tmp1 = FFABS(sb_sample_f[blk][1][sb]);
        if (tmp0 != 0)
            x |= tmp0 - 1;
        if (tmp1 != 0)
            y |= tmp1 - 1;
    }
    scale_factor[0][sb] = (31 - SCALE_OUT_BITS) - ff_clz(x);
    scale_factor[1][sb] = (31 - SCALE_OUT_BITS) - ff_clz(y);

    /* the rest of subbands can use joint stereo */
    while (--sb >= 0) {
        int32_t sb_sample_j[16][2];
        x = 1 << SCALE_OUT_BITS;
        y = 1 << SCALE_OUT_BITS;
        for (blk = 0; blk < blocks; blk++) {
            tmp0 = sb_sample_f[blk][0][sb];
            tmp1 = sb_sample_f[blk][1][sb];
            sb_sample_j[blk][0] = (tmp0 >> 1) + (tmp1 >> 1);
            sb_sample_j[blk][1] = (tmp0 >> 1) - (tmp1 >> 1);
            tmp0 = FFABS(tmp0);
            tmp1 = FFABS(tmp1);
            if (tmp0 != 0)
                x |= tmp0 - 1;
            if (tmp1 != 0)
                y |= tmp1 - 1;
        }
        scale_factor[0][sb] = (31 - SCALE_OUT_BITS) -
            ff_clz(x);
        scale_factor[1][sb] = (31 - SCALE_OUT_BITS) -
            ff_clz(y);
        x = 1 << SCALE_OUT_BITS;
        y = 1 << SCALE_OUT_BITS;
        for (blk = 0; blk < blocks; blk++) {
            tmp0 = FFABS(sb_sample_j[blk][0]);
            tmp1 = FFABS(sb_sample_j[blk][1]);
            if (tmp0 != 0)
                x |= tmp0 - 1;
            if (tmp1 != 0)
                y |= tmp1 - 1;
        }
        x = (31 - SCALE_OUT_BITS) - ff_clz(x);
        y = (31 - SCALE_OUT_BITS) - ff_clz(y);

        /* decide whether to use joint stereo for this subband */
        if ((scale_factor[0][sb] + scale_factor[1][sb]) > x + y) {
            joint |= 1 << (subbands - 1 - sb);
            scale_factor[0][sb] = x;
            scale_factor[1][sb] = y;
            for (blk = 0; blk < blocks; blk++) {
                sb_sample_f[blk][0][sb] = sb_sample_j[blk][0];
                sb_sample_f[blk][1][sb] = sb_sample_j[blk][1];
            }
        }
    }

    /* bitmask with the information about subbands using joint stereo */
    return joint;
}

