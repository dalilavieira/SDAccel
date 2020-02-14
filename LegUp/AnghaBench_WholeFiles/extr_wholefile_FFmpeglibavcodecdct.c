#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int /*<<< orphan*/  (* rdft_calc ) (TYPE_2__*,int*) ;} ;
struct TYPE_13__ {int nbits; float* csc2; int /*<<< orphan*/  (* dct32 ) (int*,int*) ;TYPE_2__ rdft; } ;
typedef  int FFTSample ;
typedef  TYPE_1__ DCTContext ;

/* Variables and functions */
 float COS (TYPE_1__*,int,int) ; 
 float SIN (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,int*) ; 
 int /*<<< orphan*/  stub2 (TYPE_2__*,int*) ; 
 int /*<<< orphan*/  stub3 (TYPE_2__*,int*) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*,int*) ; 
 int /*<<< orphan*/  stub5 (int*,int*) ; 

__attribute__((used)) static void dst_calc_I_c(DCTContext *ctx, FFTSample *data)
{
    int n = 1 << ctx->nbits;
    int i;

    data[0] = 0;
    for (i = 1; i < n / 2; i++) {
        float tmp1   = data[i    ];
        float tmp2   = data[n - i];
        float s      = SIN(ctx, n, 2 * i);

        s           *= tmp1 + tmp2;
        tmp1         = (tmp1 - tmp2) * 0.5f;
        data[i]      = s + tmp1;
        data[n - i]  = s - tmp1;
    }

    data[n / 2] *= 2;
    ctx->rdft.rdft_calc(&ctx->rdft, data);

    data[0] *= 0.5f;

    for (i = 1; i < n - 2; i += 2) {
        data[i + 1] +=  data[i - 1];
        data[i]      = -data[i + 2];
    }

    data[n - 1] = 0;
}

__attribute__((used)) static void dct_calc_I_c(DCTContext *ctx, FFTSample *data)
{
    int n = 1 << ctx->nbits;
    int i;
    float next = -0.5f * (data[0] - data[n]);

    for (i = 0; i < n / 2; i++) {
        float tmp1 = data[i];
        float tmp2 = data[n - i];
        float s    = SIN(ctx, n, 2 * i);
        float c    = COS(ctx, n, 2 * i);

        c *= tmp1 - tmp2;
        s *= tmp1 - tmp2;

        next += c;

        tmp1        = (tmp1 + tmp2) * 0.5f;
        data[i]     = tmp1 - s;
        data[n - i] = tmp1 + s;
    }

    ctx->rdft.rdft_calc(&ctx->rdft, data);
    data[n] = data[1];
    data[1] = next;

    for (i = 3; i <= n; i += 2)
        data[i] = data[i - 2] - data[i];
}

__attribute__((used)) static void dct_calc_III_c(DCTContext *ctx, FFTSample *data)
{
    int n = 1 << ctx->nbits;
    int i;

    float next  = data[n - 1];
    float inv_n = 1.0f / n;

    for (i = n - 2; i >= 2; i -= 2) {
        float val1 = data[i];
        float val2 = data[i - 1] - data[i + 1];
        float c    = COS(ctx, n, i);
        float s    = SIN(ctx, n, i);

        data[i]     = c * val1 + s * val2;
        data[i + 1] = s * val1 - c * val2;
    }

    data[1] = 2 * next;

    ctx->rdft.rdft_calc(&ctx->rdft, data);

    for (i = 0; i < n / 2; i++) {
        float tmp1 = data[i]         * inv_n;
        float tmp2 = data[n - i - 1] * inv_n;
        float csc  = ctx->csc2[i] * (tmp1 - tmp2);

        tmp1            += tmp2;
        data[i]          = tmp1 + csc;
        data[n - i - 1]  = tmp1 - csc;
    }
}

__attribute__((used)) static void dct_calc_II_c(DCTContext *ctx, FFTSample *data)
{
    int n = 1 << ctx->nbits;
    int i;
    float next;

    for (i = 0; i < n / 2; i++) {
        float tmp1 = data[i];
        float tmp2 = data[n - i - 1];
        float s    = SIN(ctx, n, 2 * i + 1);

        s    *= tmp1 - tmp2;
        tmp1  = (tmp1 + tmp2) * 0.5f;

        data[i]     = tmp1 + s;
        data[n-i-1] = tmp1 - s;
    }

    ctx->rdft.rdft_calc(&ctx->rdft, data);

    next     = data[1] * 0.5;
    data[1] *= -1;

    for (i = n - 2; i >= 0; i -= 2) {
        float inr = data[i    ];
        float ini = data[i + 1];
        float c   = COS(ctx, n, i);
        float s   = SIN(ctx, n, i);

        data[i]     = c * inr + s * ini;
        data[i + 1] = next;

        next += s * inr - c * ini;
    }
}

__attribute__((used)) static void dct32_func(DCTContext *ctx, FFTSample *data)
{
    ctx->dct32(data, data);
}

