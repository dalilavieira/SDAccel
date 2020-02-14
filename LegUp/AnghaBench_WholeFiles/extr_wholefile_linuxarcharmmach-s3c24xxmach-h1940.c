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
struct plat_lcd_data {int dummy; } ;
struct gpio_desc {int dummy; } ;
struct gpio_chip {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
#define  GPIO_LED_BLINK 135 
#define  GPIO_LED_NO_BLINK_HIGH 134 
#define  GPIO_LED_NO_BLINK_LOW 133 
 int /*<<< orphan*/  H1940_LATCH ; 
 int H1940_LATCH_LCD_P0 ; 
 int H1940_LATCH_LCD_P1 ; 
 int H1940_LATCH_LCD_P2 ; 
 int H1940_LATCH_LCD_P3 ; 
 int H1940_LATCH_LCD_P4 ; 
 int H1940_LATCH_LED_FLASH ; 
#define  H1940_LATCH_LED_GREEN 132 
#define  H1940_LATCH_LED_RED 131 
 int H1940_LATCH_MAX1698_nSHUTDOWN ; 
 int H1940_LATCH_SD_POWER ; 
 int H1940_LATCH_SM803_ENABLE ; 
#define  MMC_POWER_OFF 130 
#define  MMC_POWER_ON 129 
#define  MMC_POWER_UP 128 
 int S3C2410_GPA (int) ; 
 int S3C2410_GPB (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  S3C2410_GPB0_TOUT0 ; 
 int S3C2410_GPC (int) ; 
 int S3C2410_GPF (int) ; 
 int /*<<< orphan*/  S3C_GPIO_PULL_NONE ; 
 int /*<<< orphan*/  S3C_GPIO_SFN (int) ; 
 int /*<<< orphan*/  __raw_writel (unsigned int,int /*<<< orphan*/ ) ; 
 int desc_to_gpio (struct gpio_desc*) ; 
 int /*<<< orphan*/  gpio_direction_input (int) ; 
 int /*<<< orphan*/  gpio_direction_output (int,int) ; 
 int /*<<< orphan*/  gpio_free (int) ; 
 int gpio_get_value (int) ; 
 int /*<<< orphan*/  gpio_is_valid (int) ; 
 int gpio_request (int,char*) ; 
 int /*<<< orphan*/  gpio_set_value (int,int) ; 
 int /*<<< orphan*/  h1940_blink_spin ; 
 unsigned int latch_state ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  s3c_gpio_cfgpin (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s3c_gpio_setpull (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void h1940_latch_control(unsigned int clear, unsigned int set)
{
	unsigned long flags;

	local_irq_save(flags);

	latch_state &= ~clear;
	latch_state |= set;

	__raw_writel(latch_state, H1940_LATCH);

	local_irq_restore(flags);
}

__attribute__((used)) static inline int h1940_gpiolib_to_latch(int offset)
{
	return 1 << (offset + 16);
}

__attribute__((used)) static void h1940_gpiolib_latch_set(struct gpio_chip *chip,
					unsigned offset, int value)
{
	int latch_bit = h1940_gpiolib_to_latch(offset);

	h1940_latch_control(value ? 0 : latch_bit,
		value ? latch_bit : 0);
}

__attribute__((used)) static int h1940_gpiolib_latch_output(struct gpio_chip *chip,
					unsigned offset, int value)
{
	h1940_gpiolib_latch_set(chip, offset, value);
	return 0;
}

__attribute__((used)) static int h1940_gpiolib_latch_get(struct gpio_chip *chip,
					unsigned offset)
{
	return (latch_state >> (offset + 16)) & 1;
}

__attribute__((used)) static int power_supply_init(struct device *dev)
{
	return gpio_request(S3C2410_GPF(2), "cable plugged");
}

__attribute__((used)) static int h1940_is_ac_online(void)
{
	return !gpio_get_value(S3C2410_GPF(2));
}

__attribute__((used)) static void power_supply_exit(struct device *dev)
{
	gpio_free(S3C2410_GPF(2));
}

__attribute__((used)) static int h1940_bat_init(void)
{
	int ret;

	ret = gpio_request(H1940_LATCH_SM803_ENABLE, "h1940-charger-enable");
	if (ret)
		return ret;
	gpio_direction_output(H1940_LATCH_SM803_ENABLE, 0);

	return 0;

}

__attribute__((used)) static void h1940_bat_exit(void)
{
	gpio_free(H1940_LATCH_SM803_ENABLE);
}

__attribute__((used)) static void h1940_enable_charger(void)
{
	gpio_set_value(H1940_LATCH_SM803_ENABLE, 1);
}

__attribute__((used)) static void h1940_disable_charger(void)
{
	gpio_set_value(H1940_LATCH_SM803_ENABLE, 0);
}

int h1940_led_blink_set(struct gpio_desc *desc, int state,
	unsigned long *delay_on, unsigned long *delay_off)
{
	int blink_gpio, check_gpio1, check_gpio2;
	int gpio = desc ? desc_to_gpio(desc) : -EINVAL;

	switch (gpio) {
	case H1940_LATCH_LED_GREEN:
		blink_gpio = S3C2410_GPA(7);
		check_gpio1 = S3C2410_GPA(1);
		check_gpio2 = S3C2410_GPA(3);
		break;
	case H1940_LATCH_LED_RED:
		blink_gpio = S3C2410_GPA(1);
		check_gpio1 = S3C2410_GPA(7);
		check_gpio2 = S3C2410_GPA(3);
		break;
	default:
		blink_gpio = S3C2410_GPA(3);
		check_gpio1 = S3C2410_GPA(1);
		check_gpio2 = S3C2410_GPA(7);
		break;
	}

	if (delay_on && delay_off && !*delay_on && !*delay_off)
		*delay_on = *delay_off = 500;

	spin_lock(&h1940_blink_spin);

	switch (state) {
	case GPIO_LED_NO_BLINK_LOW:
	case GPIO_LED_NO_BLINK_HIGH:
		if (!gpio_get_value(check_gpio1) &&
		    !gpio_get_value(check_gpio2))
			gpio_set_value(H1940_LATCH_LED_FLASH, 0);
		gpio_set_value(blink_gpio, 0);
		if (gpio_is_valid(gpio))
			gpio_set_value(gpio, state);
		break;
	case GPIO_LED_BLINK:
		if (gpio_is_valid(gpio))
			gpio_set_value(gpio, 0);
		gpio_set_value(H1940_LATCH_LED_FLASH, 1);
		gpio_set_value(blink_gpio, 1);
		break;
	}

	spin_unlock(&h1940_blink_spin);

	return 0;
}

__attribute__((used)) static void h1940_set_mmc_power(unsigned char power_mode, unsigned short vdd)
{
	switch (power_mode) {
	case MMC_POWER_OFF:
		gpio_set_value(H1940_LATCH_SD_POWER, 0);
		break;
	case MMC_POWER_UP:
	case MMC_POWER_ON:
		gpio_set_value(H1940_LATCH_SD_POWER, 1);
		break;
	default:
		break;
	}
}

__attribute__((used)) static int h1940_backlight_init(struct device *dev)
{
	gpio_request(S3C2410_GPB(0), "Backlight");

	gpio_direction_output(S3C2410_GPB(0), 0);
	s3c_gpio_setpull(S3C2410_GPB(0), S3C_GPIO_PULL_NONE);
	s3c_gpio_cfgpin(S3C2410_GPB(0), S3C2410_GPB0_TOUT0);
	gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 1);

	return 0;
}

__attribute__((used)) static int h1940_backlight_notify(struct device *dev, int brightness)
{
	if (!brightness) {
		gpio_direction_output(S3C2410_GPB(0), 1);
		gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 0);
	} else {
		gpio_direction_output(S3C2410_GPB(0), 0);
		s3c_gpio_setpull(S3C2410_GPB(0), S3C_GPIO_PULL_NONE);
		s3c_gpio_cfgpin(S3C2410_GPB(0), S3C2410_GPB0_TOUT0);
		gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 1);
	}
	return brightness;
}

__attribute__((used)) static void h1940_backlight_exit(struct device *dev)
{
	gpio_direction_output(S3C2410_GPB(0), 1);
	gpio_set_value(H1940_LATCH_MAX1698_nSHUTDOWN, 0);
}

__attribute__((used)) static void h1940_lcd_power_set(struct plat_lcd_data *pd,
					unsigned int power)
{
	int value, retries = 100;

	if (!power) {
		gpio_set_value(S3C2410_GPC(0), 0);
		/* wait for 3ac */
		do {
			value = gpio_get_value(S3C2410_GPC(6));
		} while (value && retries--);

		gpio_set_value(H1940_LATCH_LCD_P2, 0);
		gpio_set_value(H1940_LATCH_LCD_P3, 0);
		gpio_set_value(H1940_LATCH_LCD_P4, 0);

		gpio_direction_output(S3C2410_GPC(1), 0);
		gpio_direction_output(S3C2410_GPC(4), 0);

		gpio_set_value(H1940_LATCH_LCD_P1, 0);
		gpio_set_value(H1940_LATCH_LCD_P0, 0);

		gpio_set_value(S3C2410_GPC(5), 0);

	} else {
		gpio_set_value(H1940_LATCH_LCD_P0, 1);
		gpio_set_value(H1940_LATCH_LCD_P1, 1);

		gpio_direction_input(S3C2410_GPC(1));
		gpio_direction_input(S3C2410_GPC(4));
		mdelay(10);
		s3c_gpio_cfgpin(S3C2410_GPC(1), S3C_GPIO_SFN(2));
		s3c_gpio_cfgpin(S3C2410_GPC(4), S3C_GPIO_SFN(2));

		gpio_set_value(S3C2410_GPC(5), 1);
		gpio_set_value(S3C2410_GPC(0), 1);

		gpio_set_value(H1940_LATCH_LCD_P3, 1);
		gpio_set_value(H1940_LATCH_LCD_P2, 1);
		gpio_set_value(H1940_LATCH_LCD_P4, 1);
	}
}

