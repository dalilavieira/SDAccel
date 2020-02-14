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
typedef  int u32 ;
struct gpio_chip {unsigned int ngpio; } ;

/* Variables and functions */
#define  BCM6345_CPU_ID 128 
 int BCM63XX_GPIO_DIR_IN ; 
 int BCM63XX_GPIO_DIR_OUT ; 
 int /*<<< orphan*/  BUG () ; 
 int GPIO_CTL_HI_REG ; 
 int GPIO_CTL_LO_REG ; 
 int GPIO_DATA_HI_REG ; 
 int GPIO_DATA_LO_REG ; 
 int GPIO_DATA_LO_REG_6345 ; 
 int bcm63xx_get_cpu_id () ; 
 int /*<<< orphan*/  bcm63xx_gpio_lock ; 
 int bcm_gpio_readl (int) ; 
 int /*<<< orphan*/  bcm_gpio_writel (int,int) ; 
 int gpio_out_high ; 
 int gpio_out_low ; 
 int gpio_out_low_reg ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void bcm63xx_gpio_out_low_reg_init(void)
{
	switch (bcm63xx_get_cpu_id()) {
	case BCM6345_CPU_ID:
		gpio_out_low_reg = GPIO_DATA_LO_REG_6345;
		break;
	default:
		gpio_out_low_reg = GPIO_DATA_LO_REG;
		break;
	}
}

__attribute__((used)) static void bcm63xx_gpio_set(struct gpio_chip *chip,
			     unsigned gpio, int val)
{
	u32 reg;
	u32 mask;
	u32 *v;
	unsigned long flags;

	if (gpio >= chip->ngpio)
		BUG();

	if (gpio < 32) {
		reg = gpio_out_low_reg;
		mask = 1 << gpio;
		v = &gpio_out_low;
	} else {
		reg = GPIO_DATA_HI_REG;
		mask = 1 << (gpio - 32);
		v = &gpio_out_high;
	}

	spin_lock_irqsave(&bcm63xx_gpio_lock, flags);
	if (val)
		*v |= mask;
	else
		*v &= ~mask;
	bcm_gpio_writel(*v, reg);
	spin_unlock_irqrestore(&bcm63xx_gpio_lock, flags);
}

__attribute__((used)) static int bcm63xx_gpio_get(struct gpio_chip *chip, unsigned gpio)
{
	u32 reg;
	u32 mask;

	if (gpio >= chip->ngpio)
		BUG();

	if (gpio < 32) {
		reg = gpio_out_low_reg;
		mask = 1 << gpio;
	} else {
		reg = GPIO_DATA_HI_REG;
		mask = 1 << (gpio - 32);
	}

	return !!(bcm_gpio_readl(reg) & mask);
}

__attribute__((used)) static int bcm63xx_gpio_set_direction(struct gpio_chip *chip,
				      unsigned gpio, int dir)
{
	u32 reg;
	u32 mask;
	u32 tmp;
	unsigned long flags;

	if (gpio >= chip->ngpio)
		BUG();

	if (gpio < 32) {
		reg = GPIO_CTL_LO_REG;
		mask = 1 << gpio;
	} else {
		reg = GPIO_CTL_HI_REG;
		mask = 1 << (gpio - 32);
	}

	spin_lock_irqsave(&bcm63xx_gpio_lock, flags);
	tmp = bcm_gpio_readl(reg);
	if (dir == BCM63XX_GPIO_DIR_IN)
		tmp &= ~mask;
	else
		tmp |= mask;
	bcm_gpio_writel(tmp, reg);
	spin_unlock_irqrestore(&bcm63xx_gpio_lock, flags);

	return 0;
}

__attribute__((used)) static int bcm63xx_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
	return bcm63xx_gpio_set_direction(chip, gpio, BCM63XX_GPIO_DIR_IN);
}

__attribute__((used)) static int bcm63xx_gpio_direction_output(struct gpio_chip *chip,
					 unsigned gpio, int value)
{
	bcm63xx_gpio_set(chip, gpio, value);
	return bcm63xx_gpio_set_direction(chip, gpio, BCM63XX_GPIO_DIR_OUT);
}

