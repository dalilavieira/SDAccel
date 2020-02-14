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
struct clock_event_device {int dummy; } ;

/* Variables and functions */
 int HZ ; 
 scalar_t__ TIMER3_BASE ; 
 scalar_t__ TIMER_PTV ; 
 int /*<<< orphan*/  timer_writel (int,scalar_t__) ; 

__attribute__((used)) static int tegra_timer_set_next_event(unsigned long cycles,
					 struct clock_event_device *evt)
{
	u32 reg;

	reg = 0x80000000 | ((cycles > 1) ? (cycles-1) : 0);
	timer_writel(reg, TIMER3_BASE + TIMER_PTV);

	return 0;
}

__attribute__((used)) static inline void timer_shutdown(struct clock_event_device *evt)
{
	timer_writel(0, TIMER3_BASE + TIMER_PTV);
}

__attribute__((used)) static int tegra_timer_shutdown(struct clock_event_device *evt)
{
	timer_shutdown(evt);
	return 0;
}

__attribute__((used)) static int tegra_timer_set_periodic(struct clock_event_device *evt)
{
	u32 reg = 0xC0000000 | ((1000000 / HZ) - 1);

	timer_shutdown(evt);
	timer_writel(reg, TIMER3_BASE + TIMER_PTV);
	return 0;
}

