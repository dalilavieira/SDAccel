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
struct pcf50633 {int dummy; } ;

/* Variables and functions */
 int PCF50633_GPIO1 ; 
 int PCF50633_REG_GPIO1CFG ; 
 int pcf50633_reg_read (struct pcf50633*,int) ; 
 int pcf50633_reg_set_bit_mask (struct pcf50633*,int,int,int) ; 
 int* pcf50633_regulator_registers ; 

int pcf50633_gpio_set(struct pcf50633 *pcf, int gpio, u8 val)
{
	u8 reg;

	reg = gpio - PCF50633_GPIO1 + PCF50633_REG_GPIO1CFG;

	return pcf50633_reg_set_bit_mask(pcf, reg, 0x07, val);
}

u8 pcf50633_gpio_get(struct pcf50633 *pcf, int gpio)
{
	u8 reg, val;

	reg = gpio - PCF50633_GPIO1 + PCF50633_REG_GPIO1CFG;
	val = pcf50633_reg_read(pcf, reg) & 0x07;

	return val;
}

int pcf50633_gpio_invert_set(struct pcf50633 *pcf, int gpio, int invert)
{
	u8 val, reg;

	reg = gpio - PCF50633_GPIO1 + PCF50633_REG_GPIO1CFG;
	val = !!invert << 3;

	return pcf50633_reg_set_bit_mask(pcf, reg, 1 << 3, val);
}

int pcf50633_gpio_invert_get(struct pcf50633 *pcf, int gpio)
{
	u8 reg, val;

	reg = gpio - PCF50633_GPIO1 + PCF50633_REG_GPIO1CFG;
	val = pcf50633_reg_read(pcf, reg);

	return val & (1 << 3);
}

int pcf50633_gpio_power_supply_set(struct pcf50633 *pcf,
					int gpio, int regulator, int on)
{
	u8 reg, val, mask;

	/* the *ENA register is always one after the *OUT register */
	reg = pcf50633_regulator_registers[regulator] + 1;

	val = !!on << (gpio - PCF50633_GPIO1);
	mask = 1 << (gpio - PCF50633_GPIO1);

	return pcf50633_reg_set_bit_mask(pcf, reg, mask, val);
}

