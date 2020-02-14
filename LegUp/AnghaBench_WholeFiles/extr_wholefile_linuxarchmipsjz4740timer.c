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

/* Variables and functions */
 int /*<<< orphan*/  BIT (int) ; 
 scalar_t__ JZ_REG_TIMER_STOP_CLEAR ; 
 scalar_t__ JZ_REG_TIMER_STOP_SET ; 
 scalar_t__ jz4740_timer_base ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 

void jz4740_timer_enable_watchdog(void)
{
	writel(BIT(16), jz4740_timer_base + JZ_REG_TIMER_STOP_CLEAR);
}

void jz4740_timer_disable_watchdog(void)
{
	writel(BIT(16), jz4740_timer_base + JZ_REG_TIMER_STOP_SET);
}

