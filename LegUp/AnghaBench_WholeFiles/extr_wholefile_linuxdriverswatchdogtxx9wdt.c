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
struct watchdog_device {int timeout; } ;
struct TYPE_2__ {int /*<<< orphan*/  tcr; int /*<<< orphan*/  wtmr; int /*<<< orphan*/  tisr; int /*<<< orphan*/  ccdr; int /*<<< orphan*/  cpra; } ;

/* Variables and functions */
 int TXx9_TMTCR_CCDE ; 
 int TXx9_TMTCR_TCE ; 
 int TXx9_TMTCR_TMODE_WDOG ; 
 int TXx9_TMWTMR_TWC ; 
 int TXx9_TMWTMR_TWIE ; 
 int TXx9_TMWTMR_WDIS ; 
 int WD_TIMER_CCD ; 
 int WD_TIMER_CLK ; 
 int __raw_readl (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __raw_writel (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  txx9_lock ; 
 TYPE_1__* txx9wdt_reg ; 

__attribute__((used)) static int txx9wdt_ping(struct watchdog_device *wdt_dev)
{
	spin_lock(&txx9_lock);
	__raw_writel(TXx9_TMWTMR_TWIE | TXx9_TMWTMR_TWC, &txx9wdt_reg->wtmr);
	spin_unlock(&txx9_lock);
	return 0;
}

__attribute__((used)) static int txx9wdt_start(struct watchdog_device *wdt_dev)
{
	spin_lock(&txx9_lock);
	__raw_writel(WD_TIMER_CLK * wdt_dev->timeout, &txx9wdt_reg->cpra);
	__raw_writel(WD_TIMER_CCD, &txx9wdt_reg->ccdr);
	__raw_writel(0, &txx9wdt_reg->tisr);	/* clear pending interrupt */
	__raw_writel(TXx9_TMTCR_TCE | TXx9_TMTCR_CCDE | TXx9_TMTCR_TMODE_WDOG,
		     &txx9wdt_reg->tcr);
	__raw_writel(TXx9_TMWTMR_TWIE | TXx9_TMWTMR_TWC, &txx9wdt_reg->wtmr);
	spin_unlock(&txx9_lock);
	return 0;
}

__attribute__((used)) static int txx9wdt_stop(struct watchdog_device *wdt_dev)
{
	spin_lock(&txx9_lock);
	__raw_writel(TXx9_TMWTMR_WDIS, &txx9wdt_reg->wtmr);
	__raw_writel(__raw_readl(&txx9wdt_reg->tcr) & ~TXx9_TMTCR_TCE,
		     &txx9wdt_reg->tcr);
	spin_unlock(&txx9_lock);
	return 0;
}

__attribute__((used)) static int txx9wdt_set_timeout(struct watchdog_device *wdt_dev,
			       unsigned int new_timeout)
{
	wdt_dev->timeout = new_timeout;
	txx9wdt_stop(wdt_dev);
	txx9wdt_start(wdt_dev);
	return 0;
}

