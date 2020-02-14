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
 int /*<<< orphan*/  FPGA_BKLREG ; 
 int /*<<< orphan*/  FPGA_LCDREG ; 
 int FPGA_LCDREG_VAL ; 
 int /*<<< orphan*/  GPIO_PTS3 ; 
 int MODE_PIN5 ; 
 int MODE_PIN8 ; 
 int /*<<< orphan*/  __raw_writew (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 

__attribute__((used)) static int ap320_wvga_set_brightness(int brightness)
{
	if (brightness) {
		gpio_set_value(GPIO_PTS3, 0);
		__raw_writew(0x100, FPGA_BKLREG);
	} else {
		__raw_writew(0, FPGA_BKLREG);
		gpio_set_value(GPIO_PTS3, 1);
	}

	return 0;
}

__attribute__((used)) static void ap320_wvga_power_on(void)
{
	msleep(100);

	/* ASD AP-320/325 LCD ON */
	__raw_writew(FPGA_LCDREG_VAL, FPGA_LCDREG);
}

__attribute__((used)) static void ap320_wvga_power_off(void)
{
	/* ASD AP-320/325 LCD OFF */
	__raw_writew(0, FPGA_LCDREG);
}

__attribute__((used)) static int ap325rxa_mode_pins(void)
{
	/* MD0=0, MD1=0, MD2=0: Clock Mode 0
	 * MD3=0: 16-bit Area0 Bus Width
	 * MD5=1: Little Endian
	 * TSTMD=1, MD8=1: Test Mode Disabled
	 */
	return MODE_PIN5 | MODE_PIN8;
}

