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
typedef  scalar_t__ u32 ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ omap_rev () ; 

__attribute__((used)) static inline int soc_is_omap(void)
{
	return omap_rev() != 0;
}

__attribute__((used)) static inline int omap3_idle_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap4_idle_init(void)
{
	return 0;
}

__attribute__((used)) static inline int omap3_opp_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline int omap4_opp_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void enable_omap3630_toggle_l2_on_restore(void) { }

__attribute__((used)) static inline int omap_devinit_smartreflex(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void omap_enable_smartreflex_on_init(void) {}

__attribute__((used)) static inline int omap3_twl_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline int omap4_twl_init(void)
{
	return -EINVAL;
}

__attribute__((used)) static inline void omap_pm_setup_oscillator(u32 tstart, u32 tshut) { }

__attribute__((used)) static inline void omap_pm_get_oscillator(u32 *tstart, u32 *tshut) { *tstart = *tshut = 0; }

__attribute__((used)) static inline void omap_pm_setup_sr_i2c_pcb_length(u32 mm) { }

__attribute__((used)) static inline void omap_common_suspend_init(void *pm_suspend)
{
}

