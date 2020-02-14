#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  (* fft_calc ) (TYPE_1__*,int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* fft_permute ) (TYPE_1__*,int /*<<< orphan*/ *) ;} ;
typedef  TYPE_1__ FFTContext ;
typedef  int /*<<< orphan*/  FFTComplex ;

/* Variables and functions */
 int /*<<< orphan*/  av_freep (TYPE_1__**) ; 
 TYPE_1__* av_mallocz (int) ; 
 scalar_t__ ff_fft_init (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int /*<<< orphan*/ *) ; 

FFTContext *av_fft_init(int nbits, int inverse)
{
    FFTContext *s = av_mallocz(sizeof(*s));

    if (s && ff_fft_init(s, nbits, inverse))
        av_freep(&s);

    return s;
}

void av_fft_permute(FFTContext *s, FFTComplex *z)
{
    s->fft_permute(s, z);
}

void av_fft_calc(FFTContext *s, FFTComplex *z)
{
    s->fft_calc(s, z);
}

