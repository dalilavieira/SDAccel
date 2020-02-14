#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  prediction_error ;
typedef  int int16_t ;
struct TYPE_3__ {int /*<<< orphan*/  (* scalarproduct_int16 ) (int const*,int const*,int) ;} ;
typedef  TYPE_1__ AudioDSPContext ;

/* Variables and functions */
 int FFMAX (int,int) ; 
 scalar_t__ PITCH_DELAY_MAX ; 
 int /*<<< orphan*/  PITCH_DELAY_MIN ; 
 int av_clip (int const,int /*<<< orphan*/ ,scalar_t__) ; 
 float avpriv_scalarproduct_float_c (float const*,float*,int) ; 
 float ff_exp10 (double) ; 
 int ff_log2_q15 (int) ; 
 double log10f (float) ; 
 int /*<<< orphan*/  memmove (float*,float*,int) ; 
 int sqrt (int /*<<< orphan*/ ) ; 
 float sqrtf (float) ; 
 int /*<<< orphan*/  stub1 (int const*,int const*,int) ; 

__attribute__((used)) static inline int bidir_sal(int value, int offset)
{
    if(offset < 0) return value >> -offset;
    else           return value <<  offset;
}

int ff_acelp_decode_8bit_to_1st_delay3(int ac_index)
{
    ac_index += 58;
    if(ac_index > 254)
        ac_index = 3 * ac_index - 510;
    return ac_index;
}

int ff_acelp_decode_4bit_to_2nd_delay3(
        int ac_index,
        int pitch_delay_min)
{
    if(ac_index < 4)
        return 3 * (ac_index + pitch_delay_min);
    else if(ac_index < 12)
        return 3 * pitch_delay_min + ac_index + 6;
    else
        return 3 * (ac_index + pitch_delay_min) - 18;
}

int ff_acelp_decode_5_6_bit_to_2nd_delay3(
        int ac_index,
        int pitch_delay_min)
{
        return 3 * pitch_delay_min + ac_index - 2;
}

int ff_acelp_decode_9bit_to_1st_delay6(int ac_index)
{
    if(ac_index < 463)
        return ac_index + 105;
    else
        return 6 * (ac_index - 368);
}

int ff_acelp_decode_6bit_to_2nd_delay6(
        int ac_index,
        int pitch_delay_min)
{
    return 6 * pitch_delay_min + ac_index - 3;
}

void ff_acelp_update_past_gain(
    int16_t* quant_energy,
    int gain_corr_factor,
    int log2_ma_pred_order,
    int erasure)
{
    int i;
    int avg_gain=quant_energy[(1 << log2_ma_pred_order) - 1]; // (5.10)

    for(i=(1 << log2_ma_pred_order) - 1; i>0; i--)
    {
        avg_gain       += quant_energy[i-1];
        quant_energy[i] = quant_energy[i-1];
    }

    if(erasure)
        quant_energy[0] = FFMAX(avg_gain >> log2_ma_pred_order, -10240) - 4096; // -10 and -4 in (5.10)
    else
        quant_energy[0] = (6165 * ((ff_log2_q15(gain_corr_factor) >> 2) - (13 << 13))) >> 13;
}

int16_t ff_acelp_decode_gain_code(
    AudioDSPContext *adsp,
    int gain_corr_factor,
    const int16_t* fc_v,
    int mr_energy,
    const int16_t* quant_energy,
    const int16_t* ma_prediction_coeff,
    int subframe_size,
    int ma_pred_order)
{
    int i;

    mr_energy <<= 10;

    for(i=0; i<ma_pred_order; i++)
        mr_energy += quant_energy[i] * ma_prediction_coeff[i];

#ifdef G729_BITEXACT
    mr_energy += (((-6165LL * ff_log2(dsp->scalarproduct_int16(fc_v, fc_v, subframe_size, 0))) >> 3) & ~0x3ff);

    mr_energy = (5439 * (mr_energy >> 15)) >> 8;           // (0.15) = (0.15) * (7.23)

    return bidir_sal(
               ((ff_exp2(mr_energy & 0x7fff) + 16) >> 5) * (gain_corr_factor >> 1),
               (mr_energy >> 15) - 25
           );
#else
    mr_energy = gain_corr_factor * ff_exp10((double)mr_energy / (20 << 23)) /
                sqrt(adsp->scalarproduct_int16(fc_v, fc_v, subframe_size));
    return mr_energy >> 12;
#endif
}

float ff_amr_set_fixed_gain(float fixed_gain_factor, float fixed_mean_energy,
                            float *prediction_error, float energy_mean,
                            const float *pred_table)
{
    // Equations 66-69:
    // ^g_c = ^gamma_gc * 100.05 (predicted dB + mean dB - dB of fixed vector)
    // Note 10^(0.05 * -10log(average x2)) = 1/sqrt((average x2)).
    float val = fixed_gain_factor *
        ff_exp10(0.05 *
              (avpriv_scalarproduct_float_c(pred_table, prediction_error, 4) +
               energy_mean)) /
        sqrtf(fixed_mean_energy ? fixed_mean_energy : 1.0);

    // update quantified prediction error energy history
    memmove(&prediction_error[0], &prediction_error[1],
            3 * sizeof(prediction_error[0]));
    prediction_error[3] = 20.0 * log10f(fixed_gain_factor);

    return val;
}

void ff_decode_pitch_lag(int *lag_int, int *lag_frac, int pitch_index,
                         const int prev_lag_int, const int subframe,
                         int third_as_first, int resolution)
{
    /* Note n * 10923 >> 15 is floor(x/3) for 0 <= n <= 32767 */
    if (subframe == 0 || (subframe == 2 && third_as_first)) {

        if (pitch_index < 197)
            pitch_index += 59;
        else
            pitch_index = 3 * pitch_index - 335;

    } else {
        if (resolution == 4) {
            int search_range_min = av_clip(prev_lag_int - 5, PITCH_DELAY_MIN,
                                           PITCH_DELAY_MAX - 9);

            // decoding with 4-bit resolution
            if (pitch_index < 4) {
                // integer only precision for [search_range_min, search_range_min+3]
                pitch_index = 3 * (pitch_index + search_range_min) + 1;
            } else if (pitch_index < 12) {
                // 1/3 fractional precision for [search_range_min+3 1/3, search_range_min+5 2/3]
                pitch_index += 3 * search_range_min + 7;
            } else {
                // integer only precision for [search_range_min+6, search_range_min+9]
                pitch_index = 3 * (pitch_index + search_range_min - 6) + 1;
            }
        } else {
            // decoding with 5 or 6 bit resolution, 1/3 fractional precision
            pitch_index--;

            if (resolution == 5) {
                pitch_index += 3 * av_clip(prev_lag_int - 10, PITCH_DELAY_MIN,
                                           PITCH_DELAY_MAX - 19);
            } else
                pitch_index += 3 * av_clip(prev_lag_int - 5, PITCH_DELAY_MIN,
                                           PITCH_DELAY_MAX - 9);
        }
    }
    *lag_int  = pitch_index * 10923 >> 15;
    *lag_frac = pitch_index - 3 * *lag_int - 1;
}

