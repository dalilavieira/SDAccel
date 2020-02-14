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
struct TYPE_7__ {int T3; int T2; int T1; int near; int* N; int reset; int* A; int* B; int twonear; int* C; int range; int maxval; int qbpp; int bpp; int limit; } ;
typedef  TYPE_1__ JLSState ;

/* Variables and functions */
 int FFABS (int) ; 
 int FFMAX (int,int const) ; 
 int FFMIN (int,int) ; 
 int av_log2 (int) ; 
 int /*<<< orphan*/  ff_dlog (int /*<<< orphan*/ *,char*,int,int,int) ; 

__attribute__((used)) static inline int ff_jpegls_quantize(JLSState *s, int v)
{
    if (v == 0)
        return 0;
    if (v < 0) {
        if (v <= -s->T3)
            return -4;
        if (v <= -s->T2)
            return -3;
        if (v <= -s->T1)
            return -2;
        if (v < -s->near)
            return -1;
        return 0;
    } else {
        if (v <= s->near)
            return 0;
        if (v < s->T1)
            return 1;
        if (v < s->T2)
            return 2;
        if (v < s->T3)
            return 3;
        return 4;
    }
}

__attribute__((used)) static inline void ff_jpegls_downscale_state(JLSState *state, int Q)
{
    if (state->N[Q] == state->reset) {
        state->A[Q] >>= 1;
        state->B[Q] >>= 1;
        state->N[Q] >>= 1;
    }
    state->N[Q]++;
}

__attribute__((used)) static inline int ff_jpegls_update_state_regular(JLSState *state,
                                                 int Q, int err)
{
    if(FFABS(err) > 0xFFFF)
        return -0x10000;
    state->A[Q] += FFABS(err);
    err         *= state->twonear;
    state->B[Q] += err;

    ff_jpegls_downscale_state(state, Q);

    if (state->B[Q] <= -state->N[Q]) {
        state->B[Q] = FFMAX(state->B[Q] + state->N[Q], 1 - state->N[Q]);
        if (state->C[Q] > -128)
            state->C[Q]--;
    } else if (state->B[Q] > 0) {
        state->B[Q] = FFMIN(state->B[Q] - state->N[Q], 0);
        if (state->C[Q] < 127)
            state->C[Q]++;
    }

    return err;
}

void ff_jpegls_init_state(JLSState *state)
{
    int i;

    state->twonear = state->near * 2 + 1;
    state->range   = (state->maxval + state->twonear - 1) / state->twonear + 1;

    // QBPP = ceil(log2(RANGE))
    for (state->qbpp = 0; (1 << state->qbpp) < state->range; state->qbpp++)
        ;

    state->bpp   = FFMAX(av_log2(state->maxval) + 1, 2);
    state->limit = 2*(state->bpp + FFMAX(state->bpp, 8)) - state->qbpp;

    for (i = 0; i < 367; i++) {
        state->A[i] = FFMAX(state->range + 32 >> 6, 2);
        state->N[i] = 1;
    }
}

__attribute__((used)) static inline int iso_clip(int v, int vmin, int vmax)
{
    if (v > vmax || v < vmin)
        return vmin;
    else
        return v;
}

void ff_jpegls_reset_coding_parameters(JLSState *s, int reset_all)
{
    const int basic_t1 = 3;
    const int basic_t2 = 7;
    const int basic_t3 = 21;
    int factor;

    if (s->maxval == 0 || reset_all)
        s->maxval = (1 << s->bpp) - 1;

    if (s->maxval >= 128) {
        factor = FFMIN(s->maxval, 4095) + 128 >> 8;

        if (s->T1 == 0 || reset_all)
            s->T1 = iso_clip(factor * (basic_t1 - 2) + 2 + 3 * s->near,
                             s->near + 1, s->maxval);
        if (s->T2 == 0 || reset_all)
            s->T2 = iso_clip(factor * (basic_t2 - 3) + 3 + 5 * s->near,
                             s->T1, s->maxval);
        if (s->T3 == 0 || reset_all)
            s->T3 = iso_clip(factor * (basic_t3 - 4) + 4 + 7 * s->near,
                             s->T2, s->maxval);
    } else {
        factor = 256 / (s->maxval + 1);

        if (s->T1 == 0 || reset_all)
            s->T1 = iso_clip(FFMAX(2, basic_t1 / factor + 3 * s->near),
                             s->near + 1, s->maxval);
        if (s->T2 == 0 || reset_all)
            s->T2 = iso_clip(FFMAX(3, basic_t2 / factor + 5 * s->near),
                             s->T1, s->maxval);
        if (s->T3 == 0 || reset_all)
            s->T3 = iso_clip(FFMAX(4, basic_t3 / factor + 7 * s->near),
                             s->T2, s->maxval);
    }

    if (s->reset == 0 || reset_all)
        s->reset = 64;
    ff_dlog(NULL, "[JPEG-LS RESET] T=%i,%i,%i\n", s->T1, s->T2, s->T3);
}

