#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  CELPFContext ;

/* Variables and functions */

void ff_celp_filter_init_mips(CELPFContext *c)
{
#if HAVE_INLINE_ASM
#if !HAVE_MIPS32R6 && !HAVE_MIPS64R6
    c->celp_lp_synthesis_filterf        = ff_celp_lp_synthesis_filterf_mips;
    c->celp_lp_zero_synthesis_filterf   = ff_celp_lp_zero_synthesis_filterf_mips;
#endif
#endif
}

