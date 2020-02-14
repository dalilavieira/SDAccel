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
typedef  int u8 ;
struct rtc_time {unsigned int tm_sec; unsigned int tm_min; unsigned int tm_hour; unsigned int tm_mday; unsigned int tm_mon; unsigned int tm_year; unsigned int tm_wday; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct device {int dummy; } ;
struct bq4802 {int (* read ) (struct bq4802*,int) ;void (* write ) (struct bq4802*,int,int) ;int /*<<< orphan*/  rtc; scalar_t__ regs; TYPE_1__* r; scalar_t__ ioport; int /*<<< orphan*/  lock; } ;
struct TYPE_2__ {int flags; scalar_t__ start; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IORESOURCE_IO ; 
 int IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 void* bcd2bin (unsigned int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  bq4802_ops ; 
 struct bq4802* dev_get_drvdata (struct device*) ; 
 scalar_t__ devm_ioremap (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ ) ; 
 struct bq4802* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_rtc_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int inb (scalar_t__) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 
 void* platform_get_resource (struct platform_device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct bq4802*) ; 
 int readb (scalar_t__) ; 
 int /*<<< orphan*/  resource_size (TYPE_1__*) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (struct bq4802*,int) ; 
 unsigned int stub10 (struct bq4802*,int) ; 
 void stub11 (struct bq4802*,int,int) ; 
 int stub12 (struct bq4802*,int) ; 
 void stub13 (struct bq4802*,int,int) ; 
 void stub14 (struct bq4802*,int,int) ; 
 void stub15 (struct bq4802*,int,int) ; 
 void stub16 (struct bq4802*,int,int) ; 
 void stub17 (struct bq4802*,int,int) ; 
 void stub18 (struct bq4802*,int,int) ; 
 void stub19 (struct bq4802*,int,int) ; 
 void stub2 (struct bq4802*,int,int) ; 
 void stub20 (struct bq4802*,int,int) ; 
 void stub21 (struct bq4802*,int,int) ; 
 unsigned int stub3 (struct bq4802*,int) ; 
 unsigned int stub4 (struct bq4802*,int) ; 
 unsigned int stub5 (struct bq4802*,int) ; 
 unsigned int stub6 (struct bq4802*,int) ; 
 unsigned int stub7 (struct bq4802*,int) ; 
 unsigned int stub8 (struct bq4802*,int) ; 
 unsigned int stub9 (struct bq4802*,int) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static u8 bq4802_read_io(struct bq4802 *p, int off)
{
	return inb(p->ioport + off);
}

__attribute__((used)) static void bq4802_write_io(struct bq4802 *p, int off, u8 val)
{
	outb(val, p->ioport + off);
}

__attribute__((used)) static u8 bq4802_read_mem(struct bq4802 *p, int off)
{
	return readb(p->regs + off);
}

__attribute__((used)) static void bq4802_write_mem(struct bq4802 *p, int off, u8 val)
{
	writeb(val, p->regs + off);
}

__attribute__((used)) static int bq4802_read_time(struct device *dev, struct rtc_time *tm)
{
	struct bq4802 *p = dev_get_drvdata(dev);
	unsigned long flags;
	unsigned int century;
	u8 val;

	spin_lock_irqsave(&p->lock, flags);

	val = p->read(p, 0x0e);
	p->write(p, 0xe, val | 0x08);

	tm->tm_sec = p->read(p, 0x00);
	tm->tm_min = p->read(p, 0x02);
	tm->tm_hour = p->read(p, 0x04);
	tm->tm_mday = p->read(p, 0x06);
	tm->tm_mon = p->read(p, 0x09);
	tm->tm_year = p->read(p, 0x0a);
	tm->tm_wday = p->read(p, 0x08);
	century = p->read(p, 0x0f);

	p->write(p, 0x0e, val);

	spin_unlock_irqrestore(&p->lock, flags);

	tm->tm_sec = bcd2bin(tm->tm_sec);
	tm->tm_min = bcd2bin(tm->tm_min);
	tm->tm_hour = bcd2bin(tm->tm_hour);
	tm->tm_mday = bcd2bin(tm->tm_mday);
	tm->tm_mon = bcd2bin(tm->tm_mon);
	tm->tm_year = bcd2bin(tm->tm_year);
	tm->tm_wday = bcd2bin(tm->tm_wday);
	century = bcd2bin(century);

	tm->tm_year += (century * 100);
	tm->tm_year -= 1900;

	tm->tm_mon--;

	return 0;
}

__attribute__((used)) static int bq4802_set_time(struct device *dev, struct rtc_time *tm)
{
	struct bq4802 *p = dev_get_drvdata(dev);
	u8 sec, min, hrs, day, mon, yrs, century, val;
	unsigned long flags;
	unsigned int year;

	year = tm->tm_year + 1900;
	century = year / 100;
	yrs = year % 100;

	mon = tm->tm_mon + 1;   /* tm_mon starts at zero */
	day = tm->tm_mday;
	hrs = tm->tm_hour;
	min = tm->tm_min;
	sec = tm->tm_sec;

	sec = bin2bcd(sec);
	min = bin2bcd(min);
	hrs = bin2bcd(hrs);
	day = bin2bcd(day);
	mon = bin2bcd(mon);
	yrs = bin2bcd(yrs);
	century = bin2bcd(century);

	spin_lock_irqsave(&p->lock, flags);

	val = p->read(p, 0x0e);
	p->write(p, 0x0e, val | 0x08);

	p->write(p, 0x00, sec);
	p->write(p, 0x02, min);
	p->write(p, 0x04, hrs);
	p->write(p, 0x06, day);
	p->write(p, 0x09, mon);
	p->write(p, 0x0a, yrs);
	p->write(p, 0x0f, century);

	p->write(p, 0x0e, val);

	spin_unlock_irqrestore(&p->lock, flags);

	return 0;
}

__attribute__((used)) static int bq4802_probe(struct platform_device *pdev)
{
	struct bq4802 *p = devm_kzalloc(&pdev->dev, sizeof(*p), GFP_KERNEL);
	int err = -ENOMEM;

	if (!p)
		goto out;

	spin_lock_init(&p->lock);

	p->r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!p->r) {
		p->r = platform_get_resource(pdev, IORESOURCE_IO, 0);
		err = -EINVAL;
		if (!p->r)
			goto out;
	}
	if (p->r->flags & IORESOURCE_IO) {
		p->ioport = p->r->start;
		p->read = bq4802_read_io;
		p->write = bq4802_write_io;
	} else if (p->r->flags & IORESOURCE_MEM) {
		p->regs = devm_ioremap(&pdev->dev, p->r->start,
					resource_size(p->r));
		if (!p->regs){
			err = -ENOMEM;
			goto out;
		}
		p->read = bq4802_read_mem;
		p->write = bq4802_write_mem;
	} else {
		err = -EINVAL;
		goto out;
	}

	platform_set_drvdata(pdev, p);

	p->rtc = devm_rtc_device_register(&pdev->dev, "bq4802",
					&bq4802_ops, THIS_MODULE);
	if (IS_ERR(p->rtc)) {
		err = PTR_ERR(p->rtc);
		goto out;
	}

	err = 0;
out:
	return err;

}

