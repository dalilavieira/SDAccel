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
typedef  int /*<<< orphan*/  u32 ;
struct i2c_board_info {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ OMAP1_32K_TIMER_BASE ; 
 int OMAP1_32K_TIMER_CR ; 
 int OMAP1_32K_TIMER_TVR ; 
 unsigned long OMAP_32K_TIMER_TICK_PERIOD ; 
 struct clock_event_device clockevent_32k_timer ; 
 int /*<<< orphan*/  omap_32k_timer_ack_irq () ; 
 int /*<<< orphan*/  omap_writew (int,scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 

__attribute__((used)) static inline int omap_register_i2c_bus(int bus_id, u32 clkrate,
				 struct i2c_board_info const *info,
				 unsigned len)
{
	return 0;
}

__attribute__((used)) static inline int omap_register_i2c_bus_cmdline(void)
{
	return 0;
}

__attribute__((used)) static inline void omap7xx_map_io(void)
{
}

__attribute__((used)) static inline void omap1510_fpga_init_irq(void)
{
}

__attribute__((used)) static inline void omap15xx_map_io(void)
{
}

__attribute__((used)) static inline void omap16xx_map_io(void)
{
}

__attribute__((used)) static inline int omap_serial_wakeup_init(void)
{
	return 0;
}

__attribute__((used)) static inline void omap_32k_timer_write(int val, int reg)
{
	omap_writew(val, OMAP1_32K_TIMER_BASE + reg);
}

__attribute__((used)) static inline void omap_32k_timer_start(unsigned long load_val)
{
	if (!load_val)
		load_val = 1;
	omap_32k_timer_write(load_val, OMAP1_32K_TIMER_TVR);
	omap_32k_timer_write(0x0f, OMAP1_32K_TIMER_CR);
}

__attribute__((used)) static inline void omap_32k_timer_stop(void)
{
	omap_32k_timer_write(0x0, OMAP1_32K_TIMER_CR);
}

__attribute__((used)) static int omap_32k_timer_set_next_event(unsigned long delta,
					 struct clock_event_device *dev)
{
	omap_32k_timer_start(delta);

	return 0;
}

__attribute__((used)) static int omap_32k_timer_shutdown(struct clock_event_device *evt)
{
	omap_32k_timer_stop();
	return 0;
}

__attribute__((used)) static int omap_32k_timer_set_periodic(struct clock_event_device *evt)
{
	omap_32k_timer_stop();
	omap_32k_timer_start(OMAP_32K_TIMER_TICK_PERIOD);
	return 0;
}

__attribute__((used)) static irqreturn_t omap_32k_timer_interrupt(int irq, void *dev_id)
{
	struct clock_event_device *evt = &clockevent_32k_timer;
	omap_32k_timer_ack_irq();

	evt->event_handler(evt);

	return IRQ_HANDLED;
}

