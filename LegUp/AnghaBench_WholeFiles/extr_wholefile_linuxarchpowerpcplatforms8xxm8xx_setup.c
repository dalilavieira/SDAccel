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
typedef  int uint ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  printk (char*) ; 

__attribute__((used)) static inline uint mk_int_int_mask(uint mask)
{
	return (1 << (7 - (mask/2)));
}

__attribute__((used)) static irqreturn_t timebase_interrupt(int irq, void *dev)
{
	printk ("timebase_interrupt()\n");

	return IRQ_HANDLED;
}

