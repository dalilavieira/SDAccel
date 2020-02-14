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
typedef  int uint32_t ;
typedef  int uint16_t ;
struct resource {int start; } ;
struct platform_device {int /*<<< orphan*/  dev; int /*<<< orphan*/  name; } ;
struct cs5535_mfgpt_timer {int nr; struct cs5535_mfgpt_chip* chip; } ;
struct cs5535_mfgpt_chip {int initialized; int base; int /*<<< orphan*/  lock; struct platform_device* pdev; int /*<<< orphan*/  avail; } ;

/* Variables and functions */
 int CONFIG_CS5535_MFGPT_DEFAULT_IRQ ; 
 int EIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 int MFGPT_CMP1 ; 
 int MFGPT_CMP2 ; 
 int MFGPT_DOMAIN_WORKING ; 
#define  MFGPT_EVENT_IRQ 130 
#define  MFGPT_EVENT_NMI 129 
#define  MFGPT_EVENT_RESET 128 
 int MFGPT_MAX_TIMERS ; 
 int MFGPT_REG_SETUP ; 
 int MFGPT_SETUP_SETUP ; 
 int MSR_MFGPT_IRQ ; 
 int MSR_MFGPT_NR ; 
 int MSR_MFGPT_SETUP ; 
 int MSR_PIC_IRQM_LPC ; 
 int MSR_PIC_ZSEL_LOW ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __clear_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __set_bit (int,int /*<<< orphan*/ ) ; 
 struct cs5535_mfgpt_chip cs5535_mfgpt_chip ; 
 int cs5535_mfgpt_read (struct cs5535_mfgpt_timer*,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*,...) ; 
 unsigned long find_first_bit (int /*<<< orphan*/ ,int) ; 
 int inw (int) ; 
 int /*<<< orphan*/  kfree (struct cs5535_mfgpt_timer*) ; 
 struct cs5535_mfgpt_timer* kmalloc (int,int /*<<< orphan*/ ) ; 
 int mfgpt_reset_timers ; 
 int /*<<< orphan*/  outw (int,int) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rdmsr (int,int,int) ; 
 int /*<<< orphan*/  request_region (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  test_bit (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wrmsr (int,int,int) ; 

int cs5535_mfgpt_toggle_event(struct cs5535_mfgpt_timer *timer, int cmp,
		int event, int enable)
{
	uint32_t msr, mask, value, dummy;
	int shift = (cmp == MFGPT_CMP1) ? 0 : 8;

	if (!timer) {
		WARN_ON(1);
		return -EIO;
	}

	/*
	 * The register maps for these are described in sections 6.17.1.x of
	 * the AMD Geode CS5536 Companion Device Data Book.
	 */
	switch (event) {
	case MFGPT_EVENT_RESET:
		/*
		 * XXX: According to the docs, we cannot reset timers above
		 * 6; that is, resets for 7 and 8 will be ignored.  Is this
		 * a problem?   -dilinger
		 */
		msr = MSR_MFGPT_NR;
		mask = 1 << (timer->nr + 24);
		break;

	case MFGPT_EVENT_NMI:
		msr = MSR_MFGPT_NR;
		mask = 1 << (timer->nr + shift);
		break;

	case MFGPT_EVENT_IRQ:
		msr = MSR_MFGPT_IRQ;
		mask = 1 << (timer->nr + shift);
		break;

	default:
		return -EIO;
	}

	rdmsr(msr, value, dummy);

	if (enable)
		value |= mask;
	else
		value &= ~mask;

	wrmsr(msr, value, dummy);
	return 0;
}

int cs5535_mfgpt_set_irq(struct cs5535_mfgpt_timer *timer, int cmp, int *irq,
		int enable)
{
	uint32_t zsel, lpc, dummy;
	int shift;

	if (!timer) {
		WARN_ON(1);
		return -EIO;
	}

	/*
	 * Unfortunately, MFGPTs come in pairs sharing their IRQ lines. If VSA
	 * is using the same CMP of the timer's Siamese twin, the IRQ is set to
	 * 2, and we mustn't use nor change it.
	 * XXX: Likewise, 2 Linux drivers might clash if the 2nd overwrites the
	 * IRQ of the 1st. This can only happen if forcing an IRQ, calling this
	 * with *irq==0 is safe. Currently there _are_ no 2 drivers.
	 */
	rdmsr(MSR_PIC_ZSEL_LOW, zsel, dummy);
	shift = ((cmp == MFGPT_CMP1 ? 0 : 4) + timer->nr % 4) * 4;
	if (((zsel >> shift) & 0xF) == 2)
		return -EIO;

	/* Choose IRQ: if none supplied, keep IRQ already set or use default */
	if (!*irq)
		*irq = (zsel >> shift) & 0xF;
	if (!*irq)
		*irq = CONFIG_CS5535_MFGPT_DEFAULT_IRQ;

	/* Can't use IRQ if it's 0 (=disabled), 2, or routed to LPC */
	if (*irq < 1 || *irq == 2 || *irq > 15)
		return -EIO;
	rdmsr(MSR_PIC_IRQM_LPC, lpc, dummy);
	if (lpc & (1 << *irq))
		return -EIO;

	/* All chosen and checked - go for it */
	if (cs5535_mfgpt_toggle_event(timer, cmp, MFGPT_EVENT_IRQ, enable))
		return -EIO;
	if (enable) {
		zsel = (zsel & ~(0xF << shift)) | (*irq << shift);
		wrmsr(MSR_PIC_ZSEL_LOW, zsel, dummy);
	}

	return 0;
}

struct cs5535_mfgpt_timer *cs5535_mfgpt_alloc_timer(int timer_nr, int domain)
{
	struct cs5535_mfgpt_chip *mfgpt = &cs5535_mfgpt_chip;
	struct cs5535_mfgpt_timer *timer = NULL;
	unsigned long flags;
	int max;

	if (!mfgpt->initialized)
		goto done;

	/* only allocate timers from the working domain if requested */
	if (domain == MFGPT_DOMAIN_WORKING)
		max = 6;
	else
		max = MFGPT_MAX_TIMERS;

	if (timer_nr >= max) {
		/* programmer error.  silly programmers! */
		WARN_ON(1);
		goto done;
	}

	spin_lock_irqsave(&mfgpt->lock, flags);
	if (timer_nr < 0) {
		unsigned long t;

		/* try to find any available timer */
		t = find_first_bit(mfgpt->avail, max);
		/* set timer_nr to -1 if no timers available */
		timer_nr = t < max ? (int) t : -1;
	} else {
		/* check if the requested timer's available */
		if (!test_bit(timer_nr, mfgpt->avail))
			timer_nr = -1;
	}

	if (timer_nr >= 0)
		/* if timer_nr is not -1, it's an available timer */
		__clear_bit(timer_nr, mfgpt->avail);
	spin_unlock_irqrestore(&mfgpt->lock, flags);

	if (timer_nr < 0)
		goto done;

	timer = kmalloc(sizeof(*timer), GFP_KERNEL);
	if (!timer) {
		/* aw hell */
		spin_lock_irqsave(&mfgpt->lock, flags);
		__set_bit(timer_nr, mfgpt->avail);
		spin_unlock_irqrestore(&mfgpt->lock, flags);
		goto done;
	}
	timer->chip = mfgpt;
	timer->nr = timer_nr;
	dev_info(&mfgpt->pdev->dev, "registered timer %d\n", timer_nr);

done:
	return timer;
}

void cs5535_mfgpt_free_timer(struct cs5535_mfgpt_timer *timer)
{
	unsigned long flags;
	uint16_t val;

	/* timer can be made available again only if never set up */
	val = cs5535_mfgpt_read(timer, MFGPT_REG_SETUP);
	if (!(val & MFGPT_SETUP_SETUP)) {
		spin_lock_irqsave(&timer->chip->lock, flags);
		__set_bit(timer->nr, timer->chip->avail);
		spin_unlock_irqrestore(&timer->chip->lock, flags);
	}

	kfree(timer);
}

uint16_t cs5535_mfgpt_read(struct cs5535_mfgpt_timer *timer, uint16_t reg)
{
	return inw(timer->chip->base + reg + (timer->nr * 8));
}

void cs5535_mfgpt_write(struct cs5535_mfgpt_timer *timer, uint16_t reg,
		uint16_t value)
{
	outw(value, timer->chip->base + reg + (timer->nr * 8));
}

__attribute__((used)) static void reset_all_timers(void)
{
	uint32_t val, dummy;

	/* The following undocumented bit resets the MFGPT timers */
	val = 0xFF; dummy = 0;
	wrmsr(MSR_MFGPT_SETUP, val, dummy);
}

__attribute__((used)) static void soft_reset(void)
{
	int i;
	struct cs5535_mfgpt_timer t;

	for (i = 0; i < MFGPT_MAX_TIMERS; i++) {
		t.nr = i;

		cs5535_mfgpt_toggle_event(&t, MFGPT_CMP1, MFGPT_EVENT_RESET, 0);
		cs5535_mfgpt_toggle_event(&t, MFGPT_CMP2, MFGPT_EVENT_RESET, 0);
		cs5535_mfgpt_toggle_event(&t, MFGPT_CMP1, MFGPT_EVENT_NMI, 0);
		cs5535_mfgpt_toggle_event(&t, MFGPT_CMP2, MFGPT_EVENT_NMI, 0);
		cs5535_mfgpt_toggle_event(&t, MFGPT_CMP1, MFGPT_EVENT_IRQ, 0);
		cs5535_mfgpt_toggle_event(&t, MFGPT_CMP2, MFGPT_EVENT_IRQ, 0);
	}
}

__attribute__((used)) static int scan_timers(struct cs5535_mfgpt_chip *mfgpt)
{
	struct cs5535_mfgpt_timer timer = { .chip = mfgpt };
	unsigned long flags;
	int timers = 0;
	uint16_t val;
	int i;

	/* bios workaround */
	if (mfgpt_reset_timers == 1)
		reset_all_timers();
	else if (mfgpt_reset_timers == 2)
		soft_reset();

	/* just to be safe, protect this section w/ lock */
	spin_lock_irqsave(&mfgpt->lock, flags);
	for (i = 0; i < MFGPT_MAX_TIMERS; i++) {
		timer.nr = i;
		val = cs5535_mfgpt_read(&timer, MFGPT_REG_SETUP);
		if (!(val & MFGPT_SETUP_SETUP) || mfgpt_reset_timers == 2) {
			__set_bit(i, mfgpt->avail);
			timers++;
		}
	}
	spin_unlock_irqrestore(&mfgpt->lock, flags);

	return timers;
}

__attribute__((used)) static int cs5535_mfgpt_probe(struct platform_device *pdev)
{
	struct resource *res;
	int err = -EIO, t;

	if (mfgpt_reset_timers < 0 || mfgpt_reset_timers > 2) {
		dev_err(&pdev->dev, "Bad mfgpt_reset_timers value: %i\n",
			mfgpt_reset_timers);
		goto done;
	}

	/* There are two ways to get the MFGPT base address; one is by
	 * fetching it from MSR_LBAR_MFGPT, the other is by reading the
	 * PCI BAR info.  The latter method is easier (especially across
	 * different architectures), so we'll stick with that for now.  If
	 * it turns out to be unreliable in the face of crappy BIOSes, we
	 * can always go back to using MSRs.. */

	res = platform_get_resource(pdev, IORESOURCE_IO, 0);
	if (!res) {
		dev_err(&pdev->dev, "can't fetch device resource info\n");
		goto done;
	}

	if (!request_region(res->start, resource_size(res), pdev->name)) {
		dev_err(&pdev->dev, "can't request region\n");
		goto done;
	}

	/* set up the driver-specific struct */
	cs5535_mfgpt_chip.base = res->start;
	cs5535_mfgpt_chip.pdev = pdev;
	spin_lock_init(&cs5535_mfgpt_chip.lock);

	dev_info(&pdev->dev, "reserved resource region %pR\n", res);

	/* detect the available timers */
	t = scan_timers(&cs5535_mfgpt_chip);
	dev_info(&pdev->dev, "%d MFGPT timers available\n", t);
	cs5535_mfgpt_chip.initialized = 1;
	return 0;

done:
	return err;
}

