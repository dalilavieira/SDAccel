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
typedef  scalar_t__ u16 ;
struct it87_gpio {int simple_size; int simple_base; int output_base; int /*<<< orphan*/  lock; scalar_t__ io_base; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int EBUSY ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int LDNREG ; 
 scalar_t__ REG ; 
 scalar_t__ VAL ; 
 struct it87_gpio* gpiochip_get_data (struct gpio_chip*) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 int /*<<< orphan*/  release_region (scalar_t__,int) ; 
 int /*<<< orphan*/  request_muxed_region (scalar_t__,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int superio_enter(void)
{
	/*
	 * Try to reserve REG and REG + 1 for exclusive access.
	 */
	if (!request_muxed_region(REG, 2, KBUILD_MODNAME))
		return -EBUSY;

	outb(0x87, REG);
	outb(0x01, REG);
	outb(0x55, REG);
	outb(0x55, REG);
	return 0;
}

__attribute__((used)) static inline void superio_exit(void)
{
	outb(0x02, REG);
	outb(0x02, VAL);
	release_region(REG, 2);
}

__attribute__((used)) static inline void superio_select(int ldn)
{
	outb(LDNREG, REG);
	outb(ldn, VAL);
}

__attribute__((used)) static inline int superio_inb(int reg)
{
	outb(reg, REG);
	return inb(VAL);
}

__attribute__((used)) static inline void superio_outb(int val, int reg)
{
	outb(reg, REG);
	outb(val, VAL);
}

__attribute__((used)) static inline int superio_inw(int reg)
{
	int val;

	outb(reg++, REG);
	val = inb(VAL) << 8;
	outb(reg, REG);
	val |= inb(VAL);
	return val;
}

__attribute__((used)) static inline void superio_outw(int val, int reg)
{
	outb(reg++, REG);
	outb(val >> 8, VAL);
	outb(reg, REG);
	outb(val, VAL);
}

__attribute__((used)) static inline void superio_set_mask(int mask, int reg)
{
	u8 curr_val = superio_inb(reg);
	u8 new_val = curr_val | mask;

	if (curr_val != new_val)
		superio_outb(new_val, reg);
}

__attribute__((used)) static inline void superio_clear_mask(int mask, int reg)
{
	u8 curr_val = superio_inb(reg);
	u8 new_val = curr_val & ~mask;

	if (curr_val != new_val)
		superio_outb(new_val, reg);
}

__attribute__((used)) static int it87_gpio_request(struct gpio_chip *chip, unsigned gpio_num)
{
	u8 mask, group;
	int rc = 0;
	struct it87_gpio *it87_gpio = gpiochip_get_data(chip);

	mask = 1 << (gpio_num % 8);
	group = (gpio_num / 8);

	spin_lock(&it87_gpio->lock);

	rc = superio_enter();
	if (rc)
		goto exit;

	/* not all the IT87xx chips support Simple I/O and not all of
	 * them allow all the lines to be set/unset to Simple I/O.
	 */
	if (group < it87_gpio->simple_size)
		superio_set_mask(mask, group + it87_gpio->simple_base);

	/* clear output enable, setting the pin to input, as all the
	 * newly-exported GPIO interfaces are set to input.
	 */
	superio_clear_mask(mask, group + it87_gpio->output_base);

	superio_exit();

exit:
	spin_unlock(&it87_gpio->lock);
	return rc;
}

__attribute__((used)) static int it87_gpio_get(struct gpio_chip *chip, unsigned gpio_num)
{
	u16 reg;
	u8 mask;
	struct it87_gpio *it87_gpio = gpiochip_get_data(chip);

	mask = 1 << (gpio_num % 8);
	reg = (gpio_num / 8) + it87_gpio->io_base;

	return !!(inb(reg) & mask);
}

__attribute__((used)) static int it87_gpio_direction_in(struct gpio_chip *chip, unsigned gpio_num)
{
	u8 mask, group;
	int rc = 0;
	struct it87_gpio *it87_gpio = gpiochip_get_data(chip);

	mask = 1 << (gpio_num % 8);
	group = (gpio_num / 8);

	spin_lock(&it87_gpio->lock);

	rc = superio_enter();
	if (rc)
		goto exit;

	/* clear the output enable bit */
	superio_clear_mask(mask, group + it87_gpio->output_base);

	superio_exit();

exit:
	spin_unlock(&it87_gpio->lock);
	return rc;
}

__attribute__((used)) static void it87_gpio_set(struct gpio_chip *chip,
			  unsigned gpio_num, int val)
{
	u8 mask, curr_vals;
	u16 reg;
	struct it87_gpio *it87_gpio = gpiochip_get_data(chip);

	mask = 1 << (gpio_num % 8);
	reg = (gpio_num / 8) + it87_gpio->io_base;

	curr_vals = inb(reg);
	if (val)
		outb(curr_vals | mask, reg);
	else
		outb(curr_vals & ~mask, reg);
}

__attribute__((used)) static int it87_gpio_direction_out(struct gpio_chip *chip,
				   unsigned gpio_num, int val)
{
	u8 mask, group;
	int rc = 0;
	struct it87_gpio *it87_gpio = gpiochip_get_data(chip);

	mask = 1 << (gpio_num % 8);
	group = (gpio_num / 8);

	spin_lock(&it87_gpio->lock);

	rc = superio_enter();
	if (rc)
		goto exit;

	/* set the output enable bit */
	superio_set_mask(mask, group + it87_gpio->output_base);

	it87_gpio_set(chip, gpio_num, val);

	superio_exit();

exit:
	spin_unlock(&it87_gpio->lock);
	return rc;
}

