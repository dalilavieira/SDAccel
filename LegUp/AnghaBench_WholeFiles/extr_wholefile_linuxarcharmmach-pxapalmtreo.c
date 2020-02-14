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

/* Variables and functions */

__attribute__((used)) static inline void palm27x_mmc_init(int detect, int ro, int power,
					int power_inverted)
{}

__attribute__((used)) static inline void palm27x_pm_init(unsigned long str_base) {}

__attribute__((used)) static inline void palm27x_udc_init(int vbus, int pullup, int vbus_inverted) {}

__attribute__((used)) static inline void palm27x_irda_init(int pwdn) {}

__attribute__((used)) static inline void palm27x_ac97_init(int minv, int maxv, int jack, int reset) {}

__attribute__((used)) static inline void palm27x_pwm_init(int bl, int lcd) {}

__attribute__((used)) static inline void palm27x_power_init(int ac, int usb) {}

__attribute__((used)) static inline void palm27x_pmic_init(void) {}

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static inline void palmtreo_kpc_init(void) {}

__attribute__((used)) static inline void palmtreo_uhc_init(void) {}

