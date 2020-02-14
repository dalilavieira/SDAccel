#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  scalar_t__ u32 ;
struct seq_file {int dummy; } ;
struct rtc_time {int tm_year; int tm_mon; int tm_mday; int tm_wday; int tm_hour; int tm_min; int tm_sec; } ;
struct rtc_wkalrm {struct rtc_time time; } ;
struct rtc_class_ops {int dummy; } ;
struct resource {int flags; int /*<<< orphan*/  start; } ;
struct device {struct m48t59_plat_data* platform_data; } ;
struct platform_device {struct device dev; } ;
struct nvmem_config {char* name; int word_size; int stride; int (* reg_read ) (void*,unsigned int,void*,size_t) ;int (* reg_write ) (void*,unsigned int,void*,size_t) ;int size; struct platform_device* priv; } ;
struct m48t59_private {scalar_t__ irq; TYPE_1__* rtc; int /*<<< orphan*/  lock; scalar_t__ ioaddr; } ;
struct m48t59_plat_data {scalar_t__ type; void (* write_byte ) (struct device*,scalar_t__,int) ;int (* read_byte ) (struct device*,scalar_t__) ;int offset; scalar_t__ ioaddr; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_7__ {int nvram_old_abi; struct rtc_class_ops const* ops; } ;

/* Variables and functions */
 int EINVAL ; 
 int EIO ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IORESOURCE_IO ; 
 int IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (TYPE_1__*) ; 
#define  M48T59RTC_TYPE_M48T02 130 
#define  M48T59RTC_TYPE_M48T08 129 
#define  M48T59RTC_TYPE_M48T59 128 
 size_t M48T59_ALARM_DATE ; 
 size_t M48T59_ALARM_HOUR ; 
 size_t M48T59_ALARM_MIN ; 
 size_t M48T59_ALARM_SEC ; 
 int /*<<< orphan*/  M48T59_CLEAR_BITS (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  M48T59_CNTL ; 
 int /*<<< orphan*/  M48T59_CNTL_READ ; 
 int /*<<< orphan*/  M48T59_CNTL_WRITE ; 
 size_t M48T59_FLAGS ; 
 int M48T59_FLAGS_AF ; 
 int M48T59_FLAGS_BF ; 
 size_t M48T59_HOUR ; 
 size_t M48T59_INTR ; 
 int M48T59_INTR_AFE ; 
 size_t M48T59_MDAY ; 
 size_t M48T59_MIN ; 
 size_t M48T59_MONTH ; 
 int M48T59_READ (size_t) ; 
 size_t M48T59_SEC ; 
 int /*<<< orphan*/  M48T59_SET_BITS (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t M48T59_WDAY ; 
 int M48T59_WDAY_CB ; 
 int M48T59_WDAY_CEB ; 
 int /*<<< orphan*/  M48T59_WRITE (int,size_t) ; 
 size_t M48T59_YEAR ; 
 scalar_t__ NO_IRQ ; 
 int PTR_ERR (TYPE_1__*) ; 
 int RTC_AF ; 
 int RTC_IRQF ; 
 void* bcd2bin (int) ; 
 int bin2bcd (int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct m48t59_private* dev_get_drvdata (struct device*) ; 
 struct m48t59_plat_data* dev_get_platdata (struct device*) ; 
 scalar_t__ devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct device*) ; 
 TYPE_1__* devm_rtc_allocate_device (struct device*) ; 
 struct rtc_class_ops m48t02_rtc_ops ; 
 struct rtc_class_ops m48t59_rtc_ops ; 
 struct m48t59_private* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct m48t59_private*) ; 
 int readb (scalar_t__) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int rtc_nvmem_register (TYPE_1__*,struct nvmem_config*) ; 
 int rtc_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  rtc_update_irq (TYPE_1__*,int,int) ; 
 int rtc_valid_tm (struct rtc_time*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,char*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writeb (int,scalar_t__) ; 

__attribute__((used)) static void
m48t59_mem_writeb(struct device *dev, u32 ofs, u8 val)
{
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);

	writeb(val, m48t59->ioaddr+ofs);
}

__attribute__((used)) static u8
m48t59_mem_readb(struct device *dev, u32 ofs)
{
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);

	return readb(m48t59->ioaddr+ofs);
}

__attribute__((used)) static int m48t59_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	struct m48t59_plat_data *pdata = dev_get_platdata(dev);
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);
	unsigned long flags;
	u8 val;

	spin_lock_irqsave(&m48t59->lock, flags);
	/* Issue the READ command */
	M48T59_SET_BITS(M48T59_CNTL_READ, M48T59_CNTL);

	tm->tm_year	= bcd2bin(M48T59_READ(M48T59_YEAR));
	/* tm_mon is 0-11 */
	tm->tm_mon	= bcd2bin(M48T59_READ(M48T59_MONTH)) - 1;
	tm->tm_mday	= bcd2bin(M48T59_READ(M48T59_MDAY));

	val = M48T59_READ(M48T59_WDAY);
	if ((pdata->type == M48T59RTC_TYPE_M48T59) &&
	    (val & M48T59_WDAY_CEB) && (val & M48T59_WDAY_CB)) {
		dev_dbg(dev, "Century bit is enabled\n");
		tm->tm_year += 100;	/* one century */
	}
#ifdef CONFIG_SPARC
	/* Sun SPARC machines count years since 1968 */
	tm->tm_year += 68;
#endif

	tm->tm_wday	= bcd2bin(val & 0x07);
	tm->tm_hour	= bcd2bin(M48T59_READ(M48T59_HOUR) & 0x3F);
	tm->tm_min	= bcd2bin(M48T59_READ(M48T59_MIN) & 0x7F);
	tm->tm_sec	= bcd2bin(M48T59_READ(M48T59_SEC) & 0x7F);

	/* Clear the READ bit */
	M48T59_CLEAR_BITS(M48T59_CNTL_READ, M48T59_CNTL);
	spin_unlock_irqrestore(&m48t59->lock, flags);

	dev_dbg(dev, "RTC read time %04d-%02d-%02d %02d/%02d/%02d\n",
		tm->tm_year + 1900, tm->tm_mon, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);
	return 0;
}

__attribute__((used)) static int m48t59_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	struct m48t59_plat_data *pdata = dev_get_platdata(dev);
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);
	unsigned long flags;
	u8 val = 0;
	int year = tm->tm_year;

#ifdef CONFIG_SPARC
	/* Sun SPARC machines count years since 1968 */
	year -= 68;
#endif

	dev_dbg(dev, "RTC set time %04d-%02d-%02d %02d/%02d/%02d\n",
		year + 1900, tm->tm_mon, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);

	if (year < 0)
		return -EINVAL;

	spin_lock_irqsave(&m48t59->lock, flags);
	/* Issue the WRITE command */
	M48T59_SET_BITS(M48T59_CNTL_WRITE, M48T59_CNTL);

	M48T59_WRITE((bin2bcd(tm->tm_sec) & 0x7F), M48T59_SEC);
	M48T59_WRITE((bin2bcd(tm->tm_min) & 0x7F), M48T59_MIN);
	M48T59_WRITE((bin2bcd(tm->tm_hour) & 0x3F), M48T59_HOUR);
	M48T59_WRITE((bin2bcd(tm->tm_mday) & 0x3F), M48T59_MDAY);
	/* tm_mon is 0-11 */
	M48T59_WRITE((bin2bcd(tm->tm_mon + 1) & 0x1F), M48T59_MONTH);
	M48T59_WRITE(bin2bcd(year % 100), M48T59_YEAR);

	if (pdata->type == M48T59RTC_TYPE_M48T59 && (year / 100))
		val = (M48T59_WDAY_CEB | M48T59_WDAY_CB);
	val |= (bin2bcd(tm->tm_wday) & 0x07);
	M48T59_WRITE(val, M48T59_WDAY);

	/* Clear the WRITE bit */
	M48T59_CLEAR_BITS(M48T59_CNTL_WRITE, M48T59_CNTL);
	spin_unlock_irqrestore(&m48t59->lock, flags);
	return 0;
}

__attribute__((used)) static int m48t59_rtc_readalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct m48t59_plat_data *pdata = dev_get_platdata(dev);
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);
	struct rtc_time *tm = &alrm->time;
	unsigned long flags;
	u8 val;

	/* If no irq, we don't support ALARM */
	if (m48t59->irq == NO_IRQ)
		return -EIO;

	spin_lock_irqsave(&m48t59->lock, flags);
	/* Issue the READ command */
	M48T59_SET_BITS(M48T59_CNTL_READ, M48T59_CNTL);

	tm->tm_year = bcd2bin(M48T59_READ(M48T59_YEAR));
#ifdef CONFIG_SPARC
	/* Sun SPARC machines count years since 1968 */
	tm->tm_year += 68;
#endif
	/* tm_mon is 0-11 */
	tm->tm_mon = bcd2bin(M48T59_READ(M48T59_MONTH)) - 1;

	val = M48T59_READ(M48T59_WDAY);
	if ((val & M48T59_WDAY_CEB) && (val & M48T59_WDAY_CB))
		tm->tm_year += 100;	/* one century */

	tm->tm_mday = bcd2bin(M48T59_READ(M48T59_ALARM_DATE));
	tm->tm_hour = bcd2bin(M48T59_READ(M48T59_ALARM_HOUR));
	tm->tm_min = bcd2bin(M48T59_READ(M48T59_ALARM_MIN));
	tm->tm_sec = bcd2bin(M48T59_READ(M48T59_ALARM_SEC));

	/* Clear the READ bit */
	M48T59_CLEAR_BITS(M48T59_CNTL_READ, M48T59_CNTL);
	spin_unlock_irqrestore(&m48t59->lock, flags);

	dev_dbg(dev, "RTC read alarm time %04d-%02d-%02d %02d/%02d/%02d\n",
		tm->tm_year + 1900, tm->tm_mon, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);
	return rtc_valid_tm(tm);
}

__attribute__((used)) static int m48t59_rtc_setalarm(struct device *dev, struct rtc_wkalrm *alrm)
{
	struct m48t59_plat_data *pdata = dev_get_platdata(dev);
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);
	struct rtc_time *tm = &alrm->time;
	u8 mday, hour, min, sec;
	unsigned long flags;
	int year = tm->tm_year;

#ifdef CONFIG_SPARC
	/* Sun SPARC machines count years since 1968 */
	year -= 68;
#endif

	/* If no irq, we don't support ALARM */
	if (m48t59->irq == NO_IRQ)
		return -EIO;

	if (year < 0)
		return -EINVAL;

	/*
	 * 0xff means "always match"
	 */
	mday = tm->tm_mday;
	mday = (mday >= 1 && mday <= 31) ? bin2bcd(mday) : 0xff;
	if (mday == 0xff)
		mday = M48T59_READ(M48T59_MDAY);

	hour = tm->tm_hour;
	hour = (hour < 24) ? bin2bcd(hour) : 0x00;

	min = tm->tm_min;
	min = (min < 60) ? bin2bcd(min) : 0x00;

	sec = tm->tm_sec;
	sec = (sec < 60) ? bin2bcd(sec) : 0x00;

	spin_lock_irqsave(&m48t59->lock, flags);
	/* Issue the WRITE command */
	M48T59_SET_BITS(M48T59_CNTL_WRITE, M48T59_CNTL);

	M48T59_WRITE(mday, M48T59_ALARM_DATE);
	M48T59_WRITE(hour, M48T59_ALARM_HOUR);
	M48T59_WRITE(min, M48T59_ALARM_MIN);
	M48T59_WRITE(sec, M48T59_ALARM_SEC);

	/* Clear the WRITE bit */
	M48T59_CLEAR_BITS(M48T59_CNTL_WRITE, M48T59_CNTL);
	spin_unlock_irqrestore(&m48t59->lock, flags);

	dev_dbg(dev, "RTC set alarm time %04d-%02d-%02d %02d/%02d/%02d\n",
		year + 1900, tm->tm_mon, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec);
	return 0;
}

__attribute__((used)) static int m48t59_rtc_alarm_irq_enable(struct device *dev, unsigned int enabled)
{
	struct m48t59_plat_data *pdata = dev_get_platdata(dev);
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);
	unsigned long flags;

	spin_lock_irqsave(&m48t59->lock, flags);
	if (enabled)
		M48T59_WRITE(M48T59_INTR_AFE, M48T59_INTR);
	else
		M48T59_WRITE(0x00, M48T59_INTR);
	spin_unlock_irqrestore(&m48t59->lock, flags);

	return 0;
}

__attribute__((used)) static int m48t59_rtc_proc(struct device *dev, struct seq_file *seq)
{
	struct m48t59_plat_data *pdata = dev_get_platdata(dev);
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);
	unsigned long flags;
	u8 val;

	spin_lock_irqsave(&m48t59->lock, flags);
	val = M48T59_READ(M48T59_FLAGS);
	spin_unlock_irqrestore(&m48t59->lock, flags);

	seq_printf(seq, "battery\t\t: %s\n",
		 (val & M48T59_FLAGS_BF) ? "low" : "normal");
	return 0;
}

__attribute__((used)) static irqreturn_t m48t59_rtc_interrupt(int irq, void *dev_id)
{
	struct device *dev = (struct device *)dev_id;
	struct m48t59_plat_data *pdata = dev_get_platdata(dev);
	struct m48t59_private *m48t59 = dev_get_drvdata(dev);
	u8 event;

	spin_lock(&m48t59->lock);
	event = M48T59_READ(M48T59_FLAGS);
	spin_unlock(&m48t59->lock);

	if (event & M48T59_FLAGS_AF) {
		rtc_update_irq(m48t59->rtc, 1, (RTC_AF | RTC_IRQF));
		return IRQ_HANDLED;
	}

	return IRQ_NONE;
}

__attribute__((used)) static int m48t59_nvram_read(void *priv, unsigned int offset, void *val,
			     size_t size)
{
	struct platform_device *pdev = priv;
	struct device *dev = &pdev->dev;
	struct m48t59_plat_data *pdata = dev_get_platdata(&pdev->dev);
	struct m48t59_private *m48t59 = platform_get_drvdata(pdev);
	ssize_t cnt = 0;
	unsigned long flags;
	u8 *buf = val;

	spin_lock_irqsave(&m48t59->lock, flags);

	for (; cnt < size; cnt++)
		*buf++ = M48T59_READ(cnt);

	spin_unlock_irqrestore(&m48t59->lock, flags);

	return 0;
}

__attribute__((used)) static int m48t59_nvram_write(void *priv, unsigned int offset, void *val,
			      size_t size)
{
	struct platform_device *pdev = priv;
	struct device *dev = &pdev->dev;
	struct m48t59_plat_data *pdata = dev_get_platdata(&pdev->dev);
	struct m48t59_private *m48t59 = platform_get_drvdata(pdev);
	ssize_t cnt = 0;
	unsigned long flags;
	u8 *buf = val;

	spin_lock_irqsave(&m48t59->lock, flags);

	for (; cnt < size; cnt++)
		M48T59_WRITE(*buf++, cnt);

	spin_unlock_irqrestore(&m48t59->lock, flags);

	return 0;
}

__attribute__((used)) static int m48t59_rtc_probe(struct platform_device *pdev)
{
	struct m48t59_plat_data *pdata = dev_get_platdata(&pdev->dev);
	struct m48t59_private *m48t59 = NULL;
	struct resource *res;
	int ret = -ENOMEM;
	const struct rtc_class_ops *ops;
	struct nvmem_config nvmem_cfg = {
		.name = "m48t59-",
		.word_size = 1,
		.stride = 1,
		.reg_read = m48t59_nvram_read,
		.reg_write = m48t59_nvram_write,
		.priv = pdev,
	};

	/* This chip could be memory-mapped or I/O-mapped */
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		res = platform_get_resource(pdev, IORESOURCE_IO, 0);
		if (!res)
			return -EINVAL;
	}

	if (res->flags & IORESOURCE_IO) {
		/* If we are I/O-mapped, the platform should provide
		 * the operations accessing chip registers.
		 */
		if (!pdata || !pdata->write_byte || !pdata->read_byte)
			return -EINVAL;
	} else if (res->flags & IORESOURCE_MEM) {
		/* we are memory-mapped */
		if (!pdata) {
			pdata = devm_kzalloc(&pdev->dev, sizeof(*pdata),
						GFP_KERNEL);
			if (!pdata)
				return -ENOMEM;
			/* Ensure we only kmalloc platform data once */
			pdev->dev.platform_data = pdata;
		}
		if (!pdata->type)
			pdata->type = M48T59RTC_TYPE_M48T59;

		/* Try to use the generic memory read/write ops */
		if (!pdata->write_byte)
			pdata->write_byte = m48t59_mem_writeb;
		if (!pdata->read_byte)
			pdata->read_byte = m48t59_mem_readb;
	}

	m48t59 = devm_kzalloc(&pdev->dev, sizeof(*m48t59), GFP_KERNEL);
	if (!m48t59)
		return -ENOMEM;

	m48t59->ioaddr = pdata->ioaddr;

	if (!m48t59->ioaddr) {
		/* ioaddr not mapped externally */
		m48t59->ioaddr = devm_ioremap(&pdev->dev, res->start,
						resource_size(res));
		if (!m48t59->ioaddr)
			return ret;
	}

	/* Try to get irq number. We also can work in
	 * the mode without IRQ.
	 */
	m48t59->irq = platform_get_irq(pdev, 0);
	if (m48t59->irq <= 0)
		m48t59->irq = NO_IRQ;

	if (m48t59->irq != NO_IRQ) {
		ret = devm_request_irq(&pdev->dev, m48t59->irq,
				m48t59_rtc_interrupt, IRQF_SHARED,
				"rtc-m48t59", &pdev->dev);
		if (ret)
			return ret;
	}
	switch (pdata->type) {
	case M48T59RTC_TYPE_M48T59:
		ops = &m48t59_rtc_ops;
		pdata->offset = 0x1ff0;
		break;
	case M48T59RTC_TYPE_M48T02:
		ops = &m48t02_rtc_ops;
		pdata->offset = 0x7f0;
		break;
	case M48T59RTC_TYPE_M48T08:
		ops = &m48t02_rtc_ops;
		pdata->offset = 0x1ff0;
		break;
	default:
		dev_err(&pdev->dev, "Unknown RTC type\n");
		return -ENODEV;
	}

	spin_lock_init(&m48t59->lock);
	platform_set_drvdata(pdev, m48t59);

	m48t59->rtc = devm_rtc_allocate_device(&pdev->dev);
	if (IS_ERR(m48t59->rtc))
		return PTR_ERR(m48t59->rtc);

	m48t59->rtc->nvram_old_abi = true;
	m48t59->rtc->ops = ops;

	nvmem_cfg.size = pdata->offset;
	ret = rtc_nvmem_register(m48t59->rtc, &nvmem_cfg);
	if (ret)
		return ret;

	ret = rtc_register_device(m48t59->rtc);
	if (ret)
		return ret;

	return 0;
}

