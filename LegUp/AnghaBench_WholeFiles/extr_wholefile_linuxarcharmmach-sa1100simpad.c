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
typedef  scalar_t__ u_int ;
struct uart_port {scalar_t__ mapbase; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CS3_BASE ; 
 int DECT_POWER_ON ; 
 int EINVAL ; 
 int RS232_ON ; 
 int /*<<< orphan*/  Ser1UTCR0 ; 
 int /*<<< orphan*/  cs3_lock ; 
 long cs3_shadow ; 
 long readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel (long,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int sa11x0_pm_init(void) { return 0; }

long simpad_get_cs3_ro(void)
{
	return readl(CS3_BASE);
}

long simpad_get_cs3_shadow(void)
{
	return cs3_shadow;
}

__attribute__((used)) static void __simpad_write_cs3(void)
{
	writel(cs3_shadow, CS3_BASE);
}

void simpad_set_cs3_bit(int value)
{
	unsigned long flags;

	spin_lock_irqsave(&cs3_lock, flags);
	cs3_shadow |= value;
	__simpad_write_cs3();
	spin_unlock_irqrestore(&cs3_lock, flags);
}

void simpad_clear_cs3_bit(int value)
{
	unsigned long flags;

	spin_lock_irqsave(&cs3_lock, flags);
	cs3_shadow &= ~value;
	__simpad_write_cs3();
	spin_unlock_irqrestore(&cs3_lock, flags);
}

__attribute__((used)) static void cs3_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
	if (offset > 15)
		return;
	if (value)
		simpad_set_cs3_bit(1 << offset);
	else
		simpad_clear_cs3_bit(1 << offset);
}

__attribute__((used)) static int cs3_gpio_get(struct gpio_chip *chip, unsigned offset)
{
	if (offset > 15)
		return !!(simpad_get_cs3_ro() & (1 << (offset - 16)));
	return !!(simpad_get_cs3_shadow() & (1 << offset));
}

__attribute__((used)) static int cs3_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
	if (offset > 15)
		return 0;
	return -EINVAL;
}

__attribute__((used)) static int cs3_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
	int value)
{
	if (offset > 15)
		return -EINVAL;
	cs3_gpio_set(chip, offset, value);
	return 0;
}

__attribute__((used)) static void simpad_uart_pm(struct uart_port *port, u_int state, u_int oldstate)
{
	if (port->mapbase == (u_int)&Ser1UTCR0) {
		if (state)
		{
			simpad_clear_cs3_bit(RS232_ON);
			simpad_clear_cs3_bit(DECT_POWER_ON);
		}else
		{
			simpad_set_cs3_bit(RS232_ON);
			simpad_set_cs3_bit(DECT_POWER_ON);
		}
	}
}

