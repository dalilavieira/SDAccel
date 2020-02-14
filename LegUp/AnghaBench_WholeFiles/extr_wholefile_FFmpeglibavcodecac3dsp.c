#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  int8_t ;
typedef  int int64_t ;
typedef  int int32_t ;
typedef  int int16_t ;
struct TYPE_5__ {int in_channels; int out_channels; void (* downmix_fixed ) (int**,int**,int) ;void (* downmix ) (float**,float**,int) ;} ;
typedef  TYPE_1__ AC3DSPContext ;

/* Variables and functions */
 int AC3_MAX_BLOCKS ; 
 scalar_t__ ARCH_X86 ; 
 int /*<<< orphan*/  MAC64 (int,int,int) ; 
 int MUL16 (int const,int) ; 
 int abs (int) ; 
 int av_log2 (int) ; 
 int* ff_ac3_bap_bits ; 
 int /*<<< orphan*/  ff_ac3dsp_set_downmix_x86 (TYPE_1__*) ; 
 void stub1 (int**,int**,int) ; 
 void stub2 (float**,float**,int) ; 

__attribute__((used)) static inline int8_t ff_u8_to_s8(uint8_t a)
{
    union {
        uint8_t u8;
        int8_t  s8;
    } b;
    b.u8 = a;
    return b.s8;
}

__attribute__((used)) static int ac3_compute_mantissa_size_c(uint16_t mant_cnt[6][16])
{
    int blk, bap;
    int bits = 0;

    for (blk = 0; blk < AC3_MAX_BLOCKS; blk++) {
        // bap=1 : 3 mantissas in 5 bits
        bits += (mant_cnt[blk][1] / 3) * 5;
        // bap=2 : 3 mantissas in 7 bits
        // bap=4 : 2 mantissas in 7 bits
        bits += ((mant_cnt[blk][2] / 3) + (mant_cnt[blk][4] >> 1)) * 7;
        // bap=3 : 1 mantissa in 3 bits
        bits += mant_cnt[blk][3] * 3;
        // bap=5 to 15 : get bits per mantissa from table
        for (bap = 5; bap < 16; bap++)
            bits += mant_cnt[blk][bap] * ff_ac3_bap_bits[bap];
    }
    return bits;
}

__attribute__((used)) static void ac3_extract_exponents_c(uint8_t *exp, int32_t *coef, int nb_coefs)
{
    int i;

    for (i = 0; i < nb_coefs; i++) {
        int v = abs(coef[i]);
        exp[i] = v ? 23 - av_log2(v) : 24;
    }
}

__attribute__((used)) static void ac3_sum_square_butterfly_int32_c(int64_t sum[4],
                                             const int32_t *coef0,
                                             const int32_t *coef1,
                                             int len)
{
    int i;

    sum[0] = sum[1] = sum[2] = sum[3] = 0;

    for (i = 0; i < len; i++) {
        int lt = coef0[i];
        int rt = coef1[i];
        int md = lt + rt;
        int sd = lt - rt;
        MAC64(sum[0], lt, lt);
        MAC64(sum[1], rt, rt);
        MAC64(sum[2], md, md);
        MAC64(sum[3], sd, sd);
    }
}

__attribute__((used)) static void ac3_sum_square_butterfly_float_c(float sum[4],
                                             const float *coef0,
                                             const float *coef1,
                                             int len)
{
    int i;

    sum[0] = sum[1] = sum[2] = sum[3] = 0;

    for (i = 0; i < len; i++) {
        float lt = coef0[i];
        float rt = coef1[i];
        float md = lt + rt;
        float sd = lt - rt;
        sum[0] += lt * lt;
        sum[1] += rt * rt;
        sum[2] += md * md;
        sum[3] += sd * sd;
    }
}

__attribute__((used)) static void ac3_downmix_5_to_2_symmetric_c(float **samples, float **matrix,
                                           int len)
{
    int i;
    float v0, v1;
    float front_mix    = matrix[0][0];
    float center_mix   = matrix[0][1];
    float surround_mix = matrix[0][3];

    for (i = 0; i < len; i++) {
        v0 = samples[0][i] * front_mix  +
             samples[1][i] * center_mix +
             samples[3][i] * surround_mix;

        v1 = samples[1][i] * center_mix +
             samples[2][i] * front_mix  +
             samples[4][i] * surround_mix;

        samples[0][i] = v0;
        samples[1][i] = v1;
    }
}

__attribute__((used)) static void ac3_downmix_5_to_1_symmetric_c(float **samples, float **matrix,
                                           int len)
{
    int i;
    float front_mix    = matrix[0][0];
    float center_mix   = matrix[0][1];
    float surround_mix = matrix[0][3];

    for (i = 0; i < len; i++) {
        samples[0][i] = samples[0][i] * front_mix    +
                        samples[1][i] * center_mix   +
                        samples[2][i] * front_mix    +
                        samples[3][i] * surround_mix +
                        samples[4][i] * surround_mix;
    }
}

__attribute__((used)) static void ac3_downmix_c(float **samples, float **matrix,
                          int out_ch, int in_ch, int len)
{
    int i, j;
    float v0, v1;

    if (out_ch == 2) {
        for (i = 0; i < len; i++) {
            v0 = v1 = 0.0f;
            for (j = 0; j < in_ch; j++) {
                v0 += samples[j][i] * matrix[0][j];
                v1 += samples[j][i] * matrix[1][j];
            }
            samples[0][i] = v0;
            samples[1][i] = v1;
        }
    } else if (out_ch == 1) {
        for (i = 0; i < len; i++) {
            v0 = 0.0f;
            for (j = 0; j < in_ch; j++)
                v0 += samples[j][i] * matrix[0][j];
            samples[0][i] = v0;
        }
    }
}

__attribute__((used)) static void ac3_downmix_5_to_2_symmetric_c_fixed(int32_t **samples, int16_t **matrix,
                                           int len)
{
    int i;
    int64_t v0, v1;
    int16_t front_mix    = matrix[0][0];
    int16_t center_mix   = matrix[0][1];
    int16_t surround_mix = matrix[0][3];

    for (i = 0; i < len; i++) {
        v0 = (int64_t)samples[0][i] * front_mix  +
             (int64_t)samples[1][i] * center_mix +
             (int64_t)samples[3][i] * surround_mix;

        v1 = (int64_t)samples[1][i] * center_mix +
             (int64_t)samples[2][i] * front_mix  +
             (int64_t)samples[4][i] * surround_mix;

        samples[0][i] = (v0+2048)>>12;
        samples[1][i] = (v1+2048)>>12;
    }
}

__attribute__((used)) static void ac3_downmix_5_to_1_symmetric_c_fixed(int32_t **samples, int16_t **matrix,
                                                 int len)
{
    int i;
    int64_t v0;
    int16_t front_mix    = matrix[0][0];
    int16_t center_mix   = matrix[0][1];
    int16_t surround_mix = matrix[0][3];

    for (i = 0; i < len; i++) {
        v0 = (int64_t)samples[0][i] * front_mix    +
             (int64_t)samples[1][i] * center_mix   +
             (int64_t)samples[2][i] * front_mix    +
             (int64_t)samples[3][i] * surround_mix +
             (int64_t)samples[4][i] * surround_mix;

        samples[0][i] = (v0+2048)>>12;
    }
}

__attribute__((used)) static void ac3_downmix_c_fixed(int32_t **samples, int16_t **matrix,
                                int out_ch, int in_ch, int len)
{
    int i, j;
    int64_t v0, v1;
    if (out_ch == 2) {
        for (i = 0; i < len; i++) {
            v0 = v1 = 0;
            for (j = 0; j < in_ch; j++) {
                v0 += (int64_t)samples[j][i] * matrix[0][j];
                v1 += (int64_t)samples[j][i] * matrix[1][j];
            }
            samples[0][i] = (v0+2048)>>12;
            samples[1][i] = (v1+2048)>>12;
        }
    } else if (out_ch == 1) {
        for (i = 0; i < len; i++) {
            v0 = 0;
            for (j = 0; j < in_ch; j++)
                v0 += (int64_t)samples[j][i] * matrix[0][j];
            samples[0][i] = (v0+2048)>>12;
        }
    }
}

void ff_ac3dsp_downmix_fixed(AC3DSPContext *c, int32_t **samples, int16_t **matrix,
                             int out_ch, int in_ch, int len)
{
    if (c->in_channels != in_ch || c->out_channels != out_ch) {
        c->in_channels  = in_ch;
        c->out_channels = out_ch;
        c->downmix_fixed = NULL;

        if (in_ch == 5 && out_ch == 2 &&
            !(matrix[1][0] | matrix[0][2]  |
              matrix[1][3] | matrix[0][4]  |
             (matrix[0][1] ^ matrix[1][1]) |
             (matrix[0][0] ^ matrix[1][2]))) {
            c->downmix_fixed = ac3_downmix_5_to_2_symmetric_c_fixed;
        } else if (in_ch == 5 && out_ch == 1 &&
                   matrix[0][0] == matrix[0][2] &&
                   matrix[0][3] == matrix[0][4]) {
            c->downmix_fixed = ac3_downmix_5_to_1_symmetric_c_fixed;
        }
    }

    if (c->downmix_fixed)
        c->downmix_fixed(samples, matrix, len);
    else
        ac3_downmix_c_fixed(samples, matrix, out_ch, in_ch, len);
}

__attribute__((used)) static void apply_window_int16_c(int16_t *output, const int16_t *input,
                                 const int16_t *window, unsigned int len)
{
    int i;
    int len2 = len >> 1;

    for (i = 0; i < len2; i++) {
        int16_t w       = window[i];
        output[i]       = (MUL16(input[i],       w) + (1 << 14)) >> 15;
        output[len-i-1] = (MUL16(input[len-i-1], w) + (1 << 14)) >> 15;
    }
}

void ff_ac3dsp_downmix(AC3DSPContext *c, float **samples, float **matrix,
                       int out_ch, int in_ch, int len)
{
    if (c->in_channels != in_ch || c->out_channels != out_ch) {
        int **matrix_cmp = (int **)matrix;

        c->in_channels  = in_ch;
        c->out_channels = out_ch;
        c->downmix      = NULL;

        if (in_ch == 5 && out_ch == 2 &&
            !(matrix_cmp[1][0] | matrix_cmp[0][2]   |
              matrix_cmp[1][3] | matrix_cmp[0][4]   |
             (matrix_cmp[0][1] ^ matrix_cmp[1][1]) |
             (matrix_cmp[0][0] ^ matrix_cmp[1][2]))) {
            c->downmix = ac3_downmix_5_to_2_symmetric_c;
        } else if (in_ch == 5 && out_ch == 1 &&
                   matrix_cmp[0][0] == matrix_cmp[0][2] &&
                   matrix_cmp[0][3] == matrix_cmp[0][4]) {
            c->downmix = ac3_downmix_5_to_1_symmetric_c;
        }

        if (ARCH_X86)
            ff_ac3dsp_set_downmix_x86(c);
    }

    if (c->downmix)
        c->downmix(samples, matrix, len);
    else
        ac3_downmix_c(samples, matrix, out_ch, in_ch, len);
}

