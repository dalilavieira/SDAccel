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
typedef  int u8 ;
struct serio {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  ABS_X ; 
 int /*<<< orphan*/  BTN_TOUCH ; 
 unsigned char I8042_STR_AUXDATA ; 
 int inb (int) ; 
 int /*<<< orphan*/  input_report_abs (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_report_key (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  input_sync (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  io_lock ; 
 int kstrtou8 (char const*,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ likely (int) ; 
 int /*<<< orphan*/  outb (int,int) ; 
 int /*<<< orphan*/  serio_interrupt (struct serio*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  slidebar_input_dev ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int sprintf (char*,char*,int) ; 

__attribute__((used)) static u8 slidebar_pos_get(void)
{
	u8 res;
	unsigned long flags;

	spin_lock_irqsave(&io_lock, flags);
	outb(0xf4, 0xff29);
	outb(0xbf, 0xff2a);
	res = inb(0xff2b);
	spin_unlock_irqrestore(&io_lock, flags);

	return res;
}

__attribute__((used)) static u8 slidebar_mode_get(void)
{
	u8 res;
	unsigned long flags;

	spin_lock_irqsave(&io_lock, flags);
	outb(0xf7, 0xff29);
	outb(0x8b, 0xff2a);
	res = inb(0xff2b);
	spin_unlock_irqrestore(&io_lock, flags);

	return res;
}

__attribute__((used)) static void slidebar_mode_set(u8 mode)
{
	unsigned long flags;

	spin_lock_irqsave(&io_lock, flags);
	outb(0xf7, 0xff29);
	outb(0x8b, 0xff2a);
	outb(mode, 0xff2b);
	spin_unlock_irqrestore(&io_lock, flags);
}

__attribute__((used)) static bool slidebar_i8042_filter(unsigned char data, unsigned char str,
				  struct serio *port)
{
	static bool extended = false;

	/* We are only interested in data coming form KBC port */
	if (str & I8042_STR_AUXDATA)
		return false;

	/* Scancodes: e03b on move, e0bb on release. */
	if (data == 0xe0) {
		extended = true;
		return true;
	}

	if (!extended)
		return false;

	extended = false;

	if (likely((data & 0x7f) != 0x3b)) {
		serio_interrupt(port, 0xe0, 0);
		return false;
	}

	if (data & 0x80) {
		input_report_key(slidebar_input_dev, BTN_TOUCH, 0);
	} else {
		input_report_key(slidebar_input_dev, BTN_TOUCH, 1);
		input_report_abs(slidebar_input_dev, ABS_X, slidebar_pos_get());
	}
	input_sync(slidebar_input_dev);

	return true;
}

__attribute__((used)) static ssize_t show_slidebar_mode(struct device *dev,
				  struct device_attribute *attr,
				  char *buf)
{
	return sprintf(buf, "%x\n", slidebar_mode_get());
}

__attribute__((used)) static ssize_t store_slidebar_mode(struct device *dev,
				   struct device_attribute *attr,
				   const char *buf, size_t count)
{
	u8 mode;
	int error;

	error = kstrtou8(buf, 0, &mode);
	if (error)
		return error;

	slidebar_mode_set(mode);

	return count;
}

