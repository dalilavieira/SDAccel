#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int int16_t ;
struct TYPE_4__ {void (* acelp_interpolatef ) (float*,float const*,float const*,int,int,int,int) ;void (* acelp_apply_order_2_transfer_function ) (float*,float const*,float const*,float const*,float,float*,int) ;} ;
typedef  TYPE_1__ ACELPFContext ;

/* Variables and functions */
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 scalar_t__ HAVE_MIPSFPU ; 
 int /*<<< orphan*/  av_assert1 (int) ; 
 int av_clip_int16 (int) ; 
 int /*<<< orphan*/  av_log (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ff_acelp_filter_init_mips (TYPE_1__*) ; 

void ff_acelp_interpolate(int16_t* out, const int16_t* in,
                          const int16_t* filter_coeffs, int precision,
                          int frac_pos, int filter_length, int length)
{
    int n, i;

    av_assert1(frac_pos >= 0 && frac_pos < precision);

    for (n = 0; n < length; n++) {
        int idx = 0;
        int v = 0x4000;

        for (i = 0; i < filter_length;) {

            /* The reference G.729 and AMR fixed point code performs clipping after
               each of the two following accumulations.
               Since clipping affects only the synthetic OVERFLOW test without
               causing an int type overflow, it was moved outside the loop. */

            /*  R(x):=ac_v[-k+x]
                v += R(n-i)*ff_acelp_interp_filter(t+6i)
                v += R(n+i+1)*ff_acelp_interp_filter(6-t+6i) */

            v += in[n + i] * filter_coeffs[idx + frac_pos];
            idx += precision;
            i++;
            v += in[n - i] * filter_coeffs[idx - frac_pos];
        }
        if (av_clip_int16(v >> 15) != (v >> 15))
            av_log(NULL, AV_LOG_WARNING, "overflow that would need clipping in ff_acelp_interpolate()\n");
        out[n] = v >> 15;
    }
}

void ff_acelp_interpolatef(float *out, const float *in,
                           const float *filter_coeffs, int precision,
                           int frac_pos, int filter_length, int length)
{
    int n, i;

    for (n = 0; n < length; n++) {
        int idx = 0;
        float v = 0;

        for (i = 0; i < filter_length;) {
            v += in[n + i] * filter_coeffs[idx + frac_pos];
            idx += precision;
            i++;
            v += in[n - i] * filter_coeffs[idx - frac_pos];
        }
        out[n] = v;
    }
}

void ff_acelp_high_pass_filter(int16_t* out, int hpf_f[2],
                               const int16_t* in, int length)
{
    int i;
    int tmp;

    for (i = 0; i < length; i++) {
        tmp  = (hpf_f[0]* 15836LL) >> 13;
        tmp += (hpf_f[1]* -7667LL) >> 13;
        tmp += 7699 * (in[i] - 2*in[i-1] + in[i-2]);

        /* With "+0x800" rounding, clipping is needed
           for ALGTHM and SPEECH tests. */
        out[i] = av_clip_int16((tmp + 0x800) >> 12);

        hpf_f[1] = hpf_f[0];
        hpf_f[0] = tmp;
    }
}

void ff_acelp_apply_order_2_transfer_function(float *out, const float *in,
                                              const float zero_coeffs[2],
                                              const float pole_coeffs[2],
                                              float gain, float mem[2], int n)
{
    int i;
    float tmp;

    for (i = 0; i < n; i++) {
        tmp = gain * in[i] - pole_coeffs[0] * mem[0] - pole_coeffs[1] * mem[1];
        out[i] =       tmp + zero_coeffs[0] * mem[0] + zero_coeffs[1] * mem[1];

        mem[1] = mem[0];
        mem[0] = tmp;
    }
}

void ff_tilt_compensation(float *mem, float tilt, float *samples, int size)
{
    float new_tilt_mem = samples[size - 1];
    int i;

    for (i = size - 1; i > 0; i--)
        samples[i] -= tilt * samples[i - 1];

    samples[0] -= tilt * *mem;
    *mem = new_tilt_mem;
}

void ff_acelp_filter_init(ACELPFContext *c)
{
    c->acelp_interpolatef                      = ff_acelp_interpolatef;
    c->acelp_apply_order_2_transfer_function   = ff_acelp_apply_order_2_transfer_function;

    if(HAVE_MIPSFPU)
        ff_acelp_filter_init_mips(c);
}

