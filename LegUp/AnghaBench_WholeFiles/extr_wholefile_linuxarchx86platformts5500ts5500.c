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
typedef  int u8 ;
struct ts5500_sbc {int id; int jumpers; } ;
struct led_classdev {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  enum led_brightness { ____Placeholder_led_brightness } led_brightness ;

/* Variables and functions */
 int EBUSY ; 
 int LED_FULL ; 
 int LED_OFF ; 
 int TS5500_ADC_CONV_BUSY ; 
 int /*<<< orphan*/  TS5500_ADC_CONV_BUSY_ADDR ; 
 int /*<<< orphan*/  TS5500_ADC_CONV_DELAY ; 
 int /*<<< orphan*/  TS5500_ADC_CONV_INIT_LSB_ADDR ; 
 int /*<<< orphan*/  TS5500_ADC_CONV_MSB_ADDR ; 
 int TS5500_LED ; 
 int /*<<< orphan*/  TS5500_LED_JP_ADDR ; 
 struct ts5500_sbc* dev_get_drvdata (struct device*) ; 
 int inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  udelay (int /*<<< orphan*/ ) ; 

__attribute__((used)) static ssize_t id_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct ts5500_sbc *sbc = dev_get_drvdata(dev);

	return sprintf(buf, "0x%.2x\n", sbc->id);
}

__attribute__((used)) static ssize_t jumpers_show(struct device *dev, struct device_attribute *attr,
		char *buf)
{
	struct ts5500_sbc *sbc = dev_get_drvdata(dev);

	return sprintf(buf, "0x%.2x\n", sbc->jumpers >> 1);
}

__attribute__((used)) static void ts5500_led_set(struct led_classdev *led_cdev,
			   enum led_brightness brightness)
{
	outb(!!brightness, TS5500_LED_JP_ADDR);
}

__attribute__((used)) static enum led_brightness ts5500_led_get(struct led_classdev *led_cdev)
{
	return (inb(TS5500_LED_JP_ADDR) & TS5500_LED) ? LED_FULL : LED_OFF;
}

__attribute__((used)) static int ts5500_adc_convert(u8 ctrl)
{
	u8 lsb, msb;

	/* Start conversion (ensure the 3 MSB are set to 0) */
	outb(ctrl & 0x1f, TS5500_ADC_CONV_INIT_LSB_ADDR);

	/*
	 * The platform has CPLD logic driving the A/D converter.
	 * The conversion must complete within 11 microseconds,
	 * otherwise we have to re-initiate a conversion.
	 */
	udelay(TS5500_ADC_CONV_DELAY);
	if (inb(TS5500_ADC_CONV_BUSY_ADDR) & TS5500_ADC_CONV_BUSY)
		return -EBUSY;

	/* Read the raw data */
	lsb = inb(TS5500_ADC_CONV_INIT_LSB_ADDR);
	msb = inb(TS5500_ADC_CONV_MSB_ADDR);

	return (msb << 8) | lsb;
}

