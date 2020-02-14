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
typedef  char u8 ;
struct watchdog_device {int timeout; } ;
typedef  enum chips { ____Placeholder_chips } chips ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int NCT6102D_WDT_CONTROL ; 
 int NCT6102D_WDT_CSR ; 
 int NCT6102D_WDT_TIMEOUT ; 
#define  NCT6102_ID 169 
#define  NCT6775_ID 168 
#define  NCT6776_ID 167 
#define  NCT6779_ID 166 
#define  NCT6791_ID 165 
#define  NCT6792_ID 164 
#define  NCT6793_ID 163 
#define  NCT6795_ID 162 
#define  W83627DHG_ID 161 
#define  W83627DHG_P_ID 160 
#define  W83627EHF_ID 159 
#define  W83627HF_ID 158 
 int W83627HF_LD_WDT ; 
 int W83627HF_WDT_CONTROL ; 
 int W83627HF_WDT_TIMEOUT ; 
#define  W83627S_ID 157 
#define  W83627THF_ID 156 
#define  W83627UHG_ID 155 
#define  W83637HF_ID 154 
#define  W83667HG_B_ID 153 
#define  W83667HG_ID 152 
#define  W83687THF_ID 151 
#define  W83697HF_ID 150 
 int W83697HF_WDT_CONTROL ; 
 int W83697HF_WDT_TIMEOUT ; 
#define  W83697UG_ID 149 
 int W836X7HF_WDT_CSR ; 
 int /*<<< orphan*/  WATCHDOG_NAME ; 
 int /*<<< orphan*/  WDT_EFDR ; 
 int /*<<< orphan*/  WDT_EFER ; 
 int cr_wdt_control ; 
 int cr_wdt_csr ; 
 int cr_wdt_timeout ; 
 scalar_t__ early_disable ; 
 int inb (int /*<<< orphan*/ ) ; 
#define  nct6102 148 
#define  nct6775 147 
#define  nct6776 146 
#define  nct6779 145 
#define  nct6791 144 
#define  nct6792 143 
#define  nct6793 142 
#define  nct6795 141 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb_p (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*,char) ; 
 int /*<<< orphan*/  pr_info (char*,int) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  release_region (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  request_muxed_region (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
#define  w83627dhg 140 
#define  w83627dhg_p 139 
#define  w83627ehf 138 
#define  w83627hf 137 
#define  w83627s 136 
#define  w83627thf 135 
#define  w83627uhg 134 
#define  w83637hf 133 
#define  w83667hg 132 
#define  w83667hg_b 131 
#define  w83687thf 130 
#define  w83697hf 129 
#define  w83697ug 128 
 int /*<<< orphan*/  wdt_io ; 

__attribute__((used)) static void superio_outb(int reg, int val)
{
	outb(reg, WDT_EFER);
	outb(val, WDT_EFDR);
}

__attribute__((used)) static inline int superio_inb(int reg)
{
	outb(reg, WDT_EFER);
	return inb(WDT_EFDR);
}

__attribute__((used)) static int superio_enter(void)
{
	if (!request_muxed_region(wdt_io, 2, WATCHDOG_NAME))
		return -EBUSY;

	outb_p(0x87, WDT_EFER); /* Enter extended function mode */
	outb_p(0x87, WDT_EFER); /* Again according to manual */

	return 0;
}

__attribute__((used)) static void superio_select(int ld)
{
	superio_outb(0x07, ld);
}

__attribute__((used)) static void superio_exit(void)
{
	outb_p(0xAA, WDT_EFER); /* Leave extended function mode */
	release_region(wdt_io, 2);
}

__attribute__((used)) static int w83627hf_init(struct watchdog_device *wdog, enum chips chip)
{
	int ret;
	unsigned char t;

	ret = superio_enter();
	if (ret)
		return ret;

	superio_select(W83627HF_LD_WDT);

	/* set CR30 bit 0 to activate GPIO2 */
	t = superio_inb(0x30);
	if (!(t & 0x01))
		superio_outb(0x30, t | 0x01);

	switch (chip) {
	case w83627hf:
	case w83627s:
		t = superio_inb(0x2B) & ~0x10;
		superio_outb(0x2B, t); /* set GPIO24 to WDT0 */
		break;
	case w83697hf:
		/* Set pin 119 to WDTO# mode (= CR29, WDT0) */
		t = superio_inb(0x29) & ~0x60;
		t |= 0x20;
		superio_outb(0x29, t);
		break;
	case w83697ug:
		/* Set pin 118 to WDTO# mode */
		t = superio_inb(0x2b) & ~0x04;
		superio_outb(0x2b, t);
		break;
	case w83627thf:
		t = (superio_inb(0x2B) & ~0x08) | 0x04;
		superio_outb(0x2B, t); /* set GPIO3 to WDT0 */
		break;
	case w83627dhg:
	case w83627dhg_p:
		t = superio_inb(0x2D) & ~0x01; /* PIN77 -> WDT0# */
		superio_outb(0x2D, t); /* set GPIO5 to WDT0 */
		t = superio_inb(cr_wdt_control);
		t |= 0x02;	/* enable the WDTO# output low pulse
				 * to the KBRST# pin */
		superio_outb(cr_wdt_control, t);
		break;
	case w83637hf:
		break;
	case w83687thf:
		t = superio_inb(0x2C) & ~0x80; /* PIN47 -> WDT0# */
		superio_outb(0x2C, t);
		break;
	case w83627ehf:
	case w83627uhg:
	case w83667hg:
	case w83667hg_b:
	case nct6775:
	case nct6776:
	case nct6779:
	case nct6791:
	case nct6792:
	case nct6793:
	case nct6795:
	case nct6102:
		/*
		 * These chips have a fixed WDTO# output pin (W83627UHG),
		 * or support more than one WDTO# output pin.
		 * Don't touch its configuration, and hope the BIOS
		 * does the right thing.
		 */
		t = superio_inb(cr_wdt_control);
		t |= 0x02;	/* enable the WDTO# output low pulse
				 * to the KBRST# pin */
		superio_outb(cr_wdt_control, t);
		break;
	default:
		break;
	}

	t = superio_inb(cr_wdt_timeout);
	if (t != 0) {
		if (early_disable) {
			pr_warn("Stopping previously enabled watchdog until userland kicks in\n");
			superio_outb(cr_wdt_timeout, 0);
		} else {
			pr_info("Watchdog already running. Resetting timeout to %d sec\n",
				wdog->timeout);
			superio_outb(cr_wdt_timeout, wdog->timeout);
		}
	}

	/* set second mode & disable keyboard turning off watchdog */
	t = superio_inb(cr_wdt_control) & ~0x0C;
	superio_outb(cr_wdt_control, t);

	/* reset trigger, disable keyboard & mouse turning off watchdog */
	t = superio_inb(cr_wdt_csr) & ~0xD0;
	superio_outb(cr_wdt_csr, t);

	superio_exit();

	return 0;
}

__attribute__((used)) static int wdt_set_time(unsigned int timeout)
{
	int ret;

	ret = superio_enter();
	if (ret)
		return ret;

	superio_select(W83627HF_LD_WDT);
	superio_outb(cr_wdt_timeout, timeout);
	superio_exit();

	return 0;
}

__attribute__((used)) static int wdt_start(struct watchdog_device *wdog)
{
	return wdt_set_time(wdog->timeout);
}

__attribute__((used)) static int wdt_stop(struct watchdog_device *wdog)
{
	return wdt_set_time(0);
}

__attribute__((used)) static int wdt_set_timeout(struct watchdog_device *wdog, unsigned int timeout)
{
	wdog->timeout = timeout;

	return 0;
}

__attribute__((used)) static unsigned int wdt_get_time(struct watchdog_device *wdog)
{
	unsigned int timeleft;
	int ret;

	ret = superio_enter();
	if (ret)
		return 0;

	superio_select(W83627HF_LD_WDT);
	timeleft = superio_inb(cr_wdt_timeout);
	superio_exit();

	return timeleft;
}

__attribute__((used)) static int wdt_find(int addr)
{
	u8 val;
	int ret;

	cr_wdt_timeout = W83627HF_WDT_TIMEOUT;
	cr_wdt_control = W83627HF_WDT_CONTROL;
	cr_wdt_csr = W836X7HF_WDT_CSR;

	ret = superio_enter();
	if (ret)
		return ret;
	superio_select(W83627HF_LD_WDT);
	val = superio_inb(0x20);
	switch (val) {
	case W83627HF_ID:
		ret = w83627hf;
		break;
	case W83627S_ID:
		ret = w83627s;
		break;
	case W83697HF_ID:
		ret = w83697hf;
		cr_wdt_timeout = W83697HF_WDT_TIMEOUT;
		cr_wdt_control = W83697HF_WDT_CONTROL;
		break;
	case W83697UG_ID:
		ret = w83697ug;
		cr_wdt_timeout = W83697HF_WDT_TIMEOUT;
		cr_wdt_control = W83697HF_WDT_CONTROL;
		break;
	case W83637HF_ID:
		ret = w83637hf;
		break;
	case W83627THF_ID:
		ret = w83627thf;
		break;
	case W83687THF_ID:
		ret = w83687thf;
		break;
	case W83627EHF_ID:
		ret = w83627ehf;
		break;
	case W83627DHG_ID:
		ret = w83627dhg;
		break;
	case W83627DHG_P_ID:
		ret = w83627dhg_p;
		break;
	case W83627UHG_ID:
		ret = w83627uhg;
		break;
	case W83667HG_ID:
		ret = w83667hg;
		break;
	case W83667HG_B_ID:
		ret = w83667hg_b;
		break;
	case NCT6775_ID:
		ret = nct6775;
		break;
	case NCT6776_ID:
		ret = nct6776;
		break;
	case NCT6779_ID:
		ret = nct6779;
		break;
	case NCT6791_ID:
		ret = nct6791;
		break;
	case NCT6792_ID:
		ret = nct6792;
		break;
	case NCT6793_ID:
		ret = nct6793;
		break;
	case NCT6795_ID:
		ret = nct6795;
		break;
	case NCT6102_ID:
		ret = nct6102;
		cr_wdt_timeout = NCT6102D_WDT_TIMEOUT;
		cr_wdt_control = NCT6102D_WDT_CONTROL;
		cr_wdt_csr = NCT6102D_WDT_CSR;
		break;
	case 0xff:
		ret = -ENODEV;
		break;
	default:
		ret = -ENODEV;
		pr_err("Unsupported chip ID: 0x%02x\n", val);
		break;
	}
	superio_exit();
	return ret;
}

