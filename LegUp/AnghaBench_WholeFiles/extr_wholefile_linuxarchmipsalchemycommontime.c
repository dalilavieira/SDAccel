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
typedef  int u64 ;
struct clocksource {int dummy; } ;
struct clock_event_device {int /*<<< orphan*/  (* event_handler ) (struct clock_event_device*) ;} ;
typedef  int /*<<< orphan*/  irqreturn_t ;

/* Variables and functions */
 int /*<<< orphan*/  AU1000_SYS_CNTRCTRL ; 
 int /*<<< orphan*/  AU1000_SYS_RTCMATCH2 ; 
 int /*<<< orphan*/  AU1000_SYS_RTCREAD ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int SYS_CNTRL_M21 ; 
 int alchemy_rdsys (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  alchemy_wrsys (unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct clock_event_device*) ; 

__attribute__((used)) static u64 au1x_counter1_read(struct clocksource *cs)
{
	return alchemy_rdsys(AU1000_SYS_RTCREAD);
}

__attribute__((used)) static int au1x_rtcmatch2_set_next_event(unsigned long delta,
					 struct clock_event_device *cd)
{
	delta += alchemy_rdsys(AU1000_SYS_RTCREAD);
	/* wait for register access */
	while (alchemy_rdsys(AU1000_SYS_CNTRCTRL) & SYS_CNTRL_M21)
		;
	alchemy_wrsys(delta, AU1000_SYS_RTCMATCH2);

	return 0;
}

__attribute__((used)) static irqreturn_t au1x_rtcmatch2_irq(int irq, void *dev_id)
{
	struct clock_event_device *cd = dev_id;
	cd->event_handler(cd);
	return IRQ_HANDLED;
}

