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
typedef  unsigned int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct solo_dev {unsigned int irq_mask; int /*<<< orphan*/  pdev; scalar_t__ reg_base; } ;

/* Variables and functions */
 int /*<<< orphan*/  PCI_STATUS ; 
 int SOLO_GPIO_CONFIG_0 ; 
 int SOLO_GPIO_CONFIG_1 ; 
 int SOLO_GPIO_DATA_OUT ; 
 int SOLO_IRQ_MASK ; 
 int /*<<< orphan*/  pci_read_config_word (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 unsigned int readl (scalar_t__) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  writel (unsigned int,scalar_t__) ; 

__attribute__((used)) static inline u32 solo_reg_read(struct solo_dev *solo_dev, int reg)
{
	return readl(solo_dev->reg_base + reg);
}

__attribute__((used)) static inline void solo_reg_write(struct solo_dev *solo_dev, int reg,
				  u32 data)
{
	u16 val;

	writel(data, solo_dev->reg_base + reg);
	pci_read_config_word(solo_dev->pdev, PCI_STATUS, &val);
}

__attribute__((used)) static inline void solo_irq_on(struct solo_dev *dev, u32 mask)
{
	dev->irq_mask |= mask;
	solo_reg_write(dev, SOLO_IRQ_MASK, dev->irq_mask);
}

__attribute__((used)) static inline void solo_irq_off(struct solo_dev *dev, u32 mask)
{
	dev->irq_mask &= ~mask;
	solo_reg_write(dev, SOLO_IRQ_MASK, dev->irq_mask);
}

__attribute__((used)) static void solo_gpio_mode(struct solo_dev *solo_dev,
			   unsigned int port_mask, unsigned int mode)
{
	int port;
	unsigned int ret;

	ret = solo_reg_read(solo_dev, SOLO_GPIO_CONFIG_0);

	/* To set gpio */
	for (port = 0; port < 16; port++) {
		if (!((1 << port) & port_mask))
			continue;

		ret &= (~(3 << (port << 1)));
		ret |= ((mode & 3) << (port << 1));
	}

	solo_reg_write(solo_dev, SOLO_GPIO_CONFIG_0, ret);

	/* To set extended gpio - sensor */
	ret = solo_reg_read(solo_dev, SOLO_GPIO_CONFIG_1);

	for (port = 0; port < 16; port++) {
		if (!((1 << (port + 16)) & port_mask))
			continue;

		if (!mode)
			ret &= ~(1 << port);
		else
			ret |= 1 << port;
	}

	/* Enable GPIO[31:16] */
	ret |= 0xffff0000;

	solo_reg_write(solo_dev, SOLO_GPIO_CONFIG_1, ret);
}

__attribute__((used)) static void solo_gpio_set(struct solo_dev *solo_dev, unsigned int value)
{
	solo_reg_write(solo_dev, SOLO_GPIO_DATA_OUT,
		       solo_reg_read(solo_dev, SOLO_GPIO_DATA_OUT) | value);
}

__attribute__((used)) static void solo_gpio_clear(struct solo_dev *solo_dev, unsigned int value)
{
	solo_reg_write(solo_dev, SOLO_GPIO_DATA_OUT,
		       solo_reg_read(solo_dev, SOLO_GPIO_DATA_OUT) & ~value);
}

__attribute__((used)) static void solo_gpio_config(struct solo_dev *solo_dev)
{
	/* Video reset */
	solo_gpio_mode(solo_dev, 0x30, 1);
	solo_gpio_clear(solo_dev, 0x30);
	udelay(100);
	solo_gpio_set(solo_dev, 0x30);
	udelay(100);

	/* Warning: Don't touch the next line unless you're sure of what
	 * you're doing: first four gpio [0-3] are used for video. */
	solo_gpio_mode(solo_dev, 0x0f, 2);

	/* We use bit 8-15 of SOLO_GPIO_CONFIG_0 for relay purposes */
	solo_gpio_mode(solo_dev, 0xff00, 1);

	/* Initially set relay status to 0 */
	solo_gpio_clear(solo_dev, 0xff00);

	/* Set input pins direction */
	solo_gpio_mode(solo_dev, 0xffff0000, 0);
}

int solo_gpio_init(struct solo_dev *solo_dev)
{
#ifdef CONFIG_GPIOLIB
	int ret;
#endif

	solo_gpio_config(solo_dev);
#ifdef CONFIG_GPIOLIB
	solo_dev->gpio_dev.label = SOLO6X10_NAME"_gpio";
	solo_dev->gpio_dev.parent = &solo_dev->pdev->dev;
	solo_dev->gpio_dev.owner = THIS_MODULE;
	solo_dev->gpio_dev.base = -1;
	solo_dev->gpio_dev.ngpio = 24;
	solo_dev->gpio_dev.can_sleep = 0;

	solo_dev->gpio_dev.get_direction = solo_gpiochip_get_direction;
	solo_dev->gpio_dev.direction_input = solo_gpiochip_direction_input;
	solo_dev->gpio_dev.direction_output = solo_gpiochip_direction_output;
	solo_dev->gpio_dev.get = solo_gpiochip_get;
	solo_dev->gpio_dev.set = solo_gpiochip_set;

	ret = gpiochip_add_data(&solo_dev->gpio_dev, solo_dev);

	if (ret) {
		solo_dev->gpio_dev.label = NULL;
		return -1;
	}
#endif
	return 0;
}

void solo_gpio_exit(struct solo_dev *solo_dev)
{
#ifdef CONFIG_GPIOLIB
	if (solo_dev->gpio_dev.label) {
		gpiochip_remove(&solo_dev->gpio_dev);
		solo_dev->gpio_dev.label = NULL;
	}
#endif
	solo_gpio_clear(solo_dev, 0x30);
	solo_gpio_config(solo_dev);
}

