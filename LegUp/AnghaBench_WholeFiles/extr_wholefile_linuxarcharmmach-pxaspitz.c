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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint32_t ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 int /*<<< orphan*/  MSC0 ; 
 int /*<<< orphan*/  REBOOT_GPIO ; 
 int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_device_register_simple (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pxa_restart (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

__attribute__((used)) static inline void spitz_scoop_init(void) {}

__attribute__((used)) static inline void spitz_card_pwr_ctrl(uint8_t enable, uint8_t new_cpr) {}

__attribute__((used)) static inline void spitz_pcmcia_init(void) {}

__attribute__((used)) static inline void spitz_mkp_init(void) {}

__attribute__((used)) static inline void spitz_keys_init(void) {}

__attribute__((used)) static inline void spitz_leds_init(void) {}

__attribute__((used)) static inline void spitz_spi_init(void) {}

__attribute__((used)) static inline void spitz_mmc_init(void) {}

__attribute__((used)) static inline void spitz_uhc_init(void) {}

__attribute__((used)) static inline void spitz_irda_init(void) {}

__attribute__((used)) static inline void spitz_lcd_init(void) {}

__attribute__((used)) static inline void spitz_nand_init(void) {}

__attribute__((used)) static inline void spitz_nor_init(void) {}

__attribute__((used)) static inline void spitz_i2c_init(void) {}

__attribute__((used)) static inline void spitz_audio_init(void)
{
	platform_device_register_simple("spitz-audio", -1, NULL, 0);
}

__attribute__((used)) static void spitz_poweroff(void)
{
	pxa_restart(REBOOT_GPIO, NULL);
}

__attribute__((used)) static void spitz_restart(enum reboot_mode mode, const char *cmd)
{
	uint32_t msc0 = __raw_readl(MSC0);
	/* Bootloader magic for a reboot */
	if ((msc0 & 0xffff0000) == 0x7ff00000)
		__raw_writel((msc0 & 0xffff) | 0x7ee00000, MSC0);

	spitz_poweroff();
}

