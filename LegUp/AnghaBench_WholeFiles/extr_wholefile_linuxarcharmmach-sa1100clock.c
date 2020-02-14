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
struct clk {scalar_t__ enabled; TYPE_1__* ops; } ;
struct TYPE_2__ {unsigned long (* get_rate ) (struct clk*) ;int /*<<< orphan*/  (* disable ) (struct clk*) ;int /*<<< orphan*/  (* enable ) (struct clk*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  GAFR ; 
 int /*<<< orphan*/  GPDR ; 
 int /*<<< orphan*/  GPIO_32_768kHz ; 
 scalar_t__ TUCR ; 
 scalar_t__ TUCR_3_6864MHz ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 unsigned long clk_get_rate (struct clk*) ; 
 int /*<<< orphan*/  clocks_lock ; 
 int sa11x0_getspeed (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  stub1 (struct clk*) ; 
 int /*<<< orphan*/  stub2 (struct clk*) ; 
 unsigned long stub3 (struct clk*) ; 

long clk_round_rate(struct clk *clk, unsigned long rate)
{
	return clk_get_rate(clk);
}

int clk_set_rate(struct clk *clk, unsigned long rate)
{
	return 0;
}

int clk_set_parent(struct clk *clk, struct clk *parent)
{
	return 0;
}

struct clk *clk_get_parent(struct clk *clk)
{
	return NULL;
}

__attribute__((used)) static void clk_gpio27_enable(struct clk *clk)
{
	/*
	 * First, set up the 3.6864MHz clock on GPIO 27 for the SA-1111:
	 * (SA-1110 Developer's Manual, section 9.1.2.1)
	 */
	GAFR |= GPIO_32_768kHz;
	GPDR |= GPIO_32_768kHz;
	TUCR = TUCR_3_6864MHz;
}

__attribute__((used)) static void clk_gpio27_disable(struct clk *clk)
{
	TUCR = 0;
	GPDR &= ~GPIO_32_768kHz;
	GAFR &= ~GPIO_32_768kHz;
}

__attribute__((used)) static void clk_cpu_enable(struct clk *clk)
{
}

__attribute__((used)) static void clk_cpu_disable(struct clk *clk)
{
}

__attribute__((used)) static unsigned long clk_cpu_get_rate(struct clk *clk)
{
	return sa11x0_getspeed(0) * 1000;
}

int clk_enable(struct clk *clk)
{
	unsigned long flags;

	if (clk) {
		spin_lock_irqsave(&clocks_lock, flags);
		if (clk->enabled++ == 0)
			clk->ops->enable(clk);
		spin_unlock_irqrestore(&clocks_lock, flags);
	}

	return 0;
}

void clk_disable(struct clk *clk)
{
	unsigned long flags;

	if (clk) {
		WARN_ON(clk->enabled == 0);
		spin_lock_irqsave(&clocks_lock, flags);
		if (--clk->enabled == 0)
			clk->ops->disable(clk);
		spin_unlock_irqrestore(&clocks_lock, flags);
	}
}

unsigned long clk_get_rate(struct clk *clk)
{
	if (clk && clk->ops && clk->ops->get_rate)
		return clk->ops->get_rate(clk);

	return 0;
}

__attribute__((used)) static unsigned long clk_36864_get_rate(struct clk *clk)
{
	return 3686400;
}

