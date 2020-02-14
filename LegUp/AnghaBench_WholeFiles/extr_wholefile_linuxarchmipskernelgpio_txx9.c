#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct gpio_chip {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  dir; int /*<<< orphan*/  dout; int /*<<< orphan*/  din; } ;

/* Variables and functions */
 int __raw_readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mmiowb () ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  txx9_gpio_lock ; 
 TYPE_1__* txx9_pioptr ; 

__attribute__((used)) static int txx9_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
	return !!(__raw_readl(&txx9_pioptr->din) & (1 << offset));
}

__attribute__((used)) static void txx9_gpio_set_raw(unsigned int offset, int value)
{
	u32 val;
	val = __raw_readl(&txx9_pioptr->dout);
	if (value)
		val |= 1 << offset;
	else
		val &= ~(1 << offset);
	__raw_writel(val, &txx9_pioptr->dout);
}

__attribute__((used)) static void txx9_gpio_set(struct gpio_chip *chip, unsigned int offset,
			  int value)
{
	unsigned long flags;
	spin_lock_irqsave(&txx9_gpio_lock, flags);
	txx9_gpio_set_raw(offset, value);
	mmiowb();
	spin_unlock_irqrestore(&txx9_gpio_lock, flags);
}

__attribute__((used)) static int txx9_gpio_dir_in(struct gpio_chip *chip, unsigned int offset)
{
	unsigned long flags;
	spin_lock_irqsave(&txx9_gpio_lock, flags);
	__raw_writel(__raw_readl(&txx9_pioptr->dir) & ~(1 << offset),
		     &txx9_pioptr->dir);
	mmiowb();
	spin_unlock_irqrestore(&txx9_gpio_lock, flags);
	return 0;
}

__attribute__((used)) static int txx9_gpio_dir_out(struct gpio_chip *chip, unsigned int offset,
			     int value)
{
	unsigned long flags;
	spin_lock_irqsave(&txx9_gpio_lock, flags);
	txx9_gpio_set_raw(offset, value);
	__raw_writel(__raw_readl(&txx9_pioptr->dir) | (1 << offset),
		     &txx9_pioptr->dir);
	mmiowb();
	spin_unlock_irqrestore(&txx9_gpio_lock, flags);
	return 0;
}

