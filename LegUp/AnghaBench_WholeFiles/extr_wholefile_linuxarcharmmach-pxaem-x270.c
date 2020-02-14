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

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static inline void em_x270_init_dm9000(void) {}

__attribute__((used)) static inline void em_x270_init_rtc(void) {}

__attribute__((used)) static inline void em_x270_init_nand(void) {}

__attribute__((used)) static inline void em_x270_init_nor(void) {}

__attribute__((used)) static inline void em_x270_init_ohci(void) {}

__attribute__((used)) static inline void em_x270_init_mmc(void) {}

__attribute__((used)) static inline void em_x270_init_lcd(void) {}

__attribute__((used)) static inline void em_x270_init_spi(void) {}

__attribute__((used)) static inline void em_x270_init_ac97(void) {}

__attribute__((used)) static inline void em_x270_init_keypad(void) {}

__attribute__((used)) static inline void em_x270_init_gpio_keys(void) {}

__attribute__((used)) static inline void em_x270_init_camera(void) {}

__attribute__((used)) static void em_x270_battery_low(void)
{
#if defined(CONFIG_APM_EMULATION)
	apm_queue_event(APM_LOW_BATTERY);
#endif
}

__attribute__((used)) static void em_x270_battery_critical(void)
{
#if defined(CONFIG_APM_EMULATION)
	apm_queue_event(APM_CRITICAL_SUSPEND);
#endif
}

