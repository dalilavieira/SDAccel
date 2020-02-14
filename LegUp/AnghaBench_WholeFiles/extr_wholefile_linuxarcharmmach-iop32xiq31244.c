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
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int* IOP3XX_ICR1 ; 
 int* IOP3XX_IDBR1 ; 
 scalar_t__ force_ep80219 ; 
 int /*<<< orphan*/  iop32x_gpio_res ; 
 scalar_t__ machine_is_ep80219 () ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  platform_device_register_simple (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int read_cpuid_id () ; 

__attribute__((used)) static inline void register_iop32x_gpio(void)
{
	platform_device_register_simple("gpio-iop", 0,
					iop32x_gpio_res,
					ARRAY_SIZE(iop32x_gpio_res));
}

__attribute__((used)) static int is_80219(void)
{
	return !!((read_cpuid_id() & 0xffffffe0) == 0x69052e20);
}

__attribute__((used)) static int is_ep80219(void)
{
	if (machine_is_ep80219() || force_ep80219)
		return 1;
	else
		return 0;
}

void ep80219_power_off(void)
{
	/*
	 * Send the Address byte w/ the start condition
	 */
	*IOP3XX_IDBR1 = 0x60;
	*IOP3XX_ICR1 = 0xE9;
	mdelay(1);

	/*
	 * Send the START_MSG byte w/ no start or stop condition
	 */
	*IOP3XX_IDBR1 = 0x0F;
	*IOP3XX_ICR1 = 0xE8;
	mdelay(1);

	/*
	 * Send the SHUTDOWN_COMPLETE Message ID byte w/ no start or
	 * stop condition
	 */
	*IOP3XX_IDBR1 = 0x03;
	*IOP3XX_ICR1 = 0xE8;
	mdelay(1);

	/*
	 * Send an ignored byte w/ stop condition
	 */
	*IOP3XX_IDBR1 = 0x00;
	*IOP3XX_ICR1 = 0xEA;

	while (1)
		;
}

