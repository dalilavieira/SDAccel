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
struct watchdog_device {unsigned int timeout; } ;

/* Variables and functions */
 int EBUSY ; 
 int GPIO ; 
 scalar_t__ IT8721_ID ; 
 int LDNREG ; 
 int /*<<< orphan*/  REG ; 
 int /*<<< orphan*/  VAL ; 
 int /*<<< orphan*/  WATCHDOG_NAME ; 
 int WDTCFG ; 
 int WDTVALLSB ; 
 int WDTVALMSB ; 
 unsigned char WDT_KRST ; 
 unsigned char WDT_PWROK ; 
 unsigned char WDT_TOV1 ; 
 scalar_t__ chip_type ; 
 int inb (int /*<<< orphan*/ ) ; 
 unsigned int max_units ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  release_region (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  request_muxed_region (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ testmode ; 
 scalar_t__ watchdog_hw_running (struct watchdog_device*) ; 

__attribute__((used)) static inline int superio_enter(void)
{
	/*
	 * Try to reserve REG and REG + 1 for exclusive access.
	 */
	if (!request_muxed_region(REG, 2, WATCHDOG_NAME))
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

__attribute__((used)) static void _wdt_update_timeout(unsigned int t)
{
	unsigned char cfg = WDT_KRST;

	if (testmode)
		cfg = 0;

	if (t <= max_units)
		cfg |= WDT_TOV1;
	else
		t /= 60;

	if (chip_type != IT8721_ID)
		cfg |= WDT_PWROK;

	superio_outb(cfg, WDTCFG);
	superio_outb(t, WDTVALLSB);
	if (max_units > 255)
		superio_outb(t >> 8, WDTVALMSB);
}

__attribute__((used)) static int wdt_update_timeout(unsigned int t)
{
	int ret;

	ret = superio_enter();
	if (ret)
		return ret;

	superio_select(GPIO);
	_wdt_update_timeout(t);
	superio_exit();

	return 0;
}

__attribute__((used)) static int wdt_round_time(int t)
{
	t += 59;
	t -= t % 60;
	return t;
}

__attribute__((used)) static int wdt_start(struct watchdog_device *wdd)
{
	return wdt_update_timeout(wdd->timeout);
}

__attribute__((used)) static int wdt_stop(struct watchdog_device *wdd)
{
	return wdt_update_timeout(0);
}

__attribute__((used)) static int wdt_set_timeout(struct watchdog_device *wdd, unsigned int t)
{
	int ret = 0;

	if (t > max_units)
		t = wdt_round_time(t);

	wdd->timeout = t;

	if (watchdog_hw_running(wdd))
		ret = wdt_update_timeout(t);

	return ret;
}

