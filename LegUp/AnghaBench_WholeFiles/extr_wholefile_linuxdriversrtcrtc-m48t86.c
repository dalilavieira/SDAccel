#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned char u8 ;
struct seq_file {int dummy; } ;
struct rtc_time {unsigned char tm_sec; unsigned char tm_min; int tm_hour; unsigned char tm_mday; int tm_mon; int tm_year; unsigned char tm_wday; } ;
struct resource {int dummy; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct nvmem_config {char* name; int word_size; int stride; int size; int (* reg_read ) (void*,unsigned int,void*,size_t) ;int (* reg_write ) (void*,unsigned int,void*,size_t) ;struct device* priv; } ;
struct m48t86_rtc_info {TYPE_1__* rtc; TYPE_1__* data_reg; TYPE_1__* index_reg; } ;
struct TYPE_8__ {int nvram_old_abi; int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (TYPE_1__*) ; 
 unsigned long M48T86_B ; 
 unsigned char M48T86_B_DM ; 
 unsigned char M48T86_B_H24 ; 
 unsigned char M48T86_B_SET ; 
 unsigned long M48T86_D ; 
 unsigned long M48T86_DOM ; 
 unsigned long M48T86_DOW ; 
 unsigned char M48T86_D_VRT ; 
 unsigned long M48T86_HOUR ; 
 unsigned long M48T86_MIN ; 
 unsigned long M48T86_MONTH ; 
 void* M48T86_NVRAM (int) ; 
 int M48T86_NVRAM_LEN ; 
 unsigned long M48T86_SEC ; 
 unsigned long M48T86_YEAR ; 
 int PTR_ERR (TYPE_1__*) ; 
 int bcd2bin (int) ; 
 unsigned char bin2bcd (int) ; 
 struct m48t86_rtc_info* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct m48t86_rtc_info*) ; 
 void* devm_ioremap_resource (struct device*,struct resource*) ; 
 struct m48t86_rtc_info* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 TYPE_1__* devm_rtc_allocate_device (struct device*) ; 
 int /*<<< orphan*/  m48t86_rtc_ops ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int) ; 
 unsigned char readb (TYPE_1__*) ; 
 int /*<<< orphan*/  rtc_nvmem_register (TYPE_1__*,struct nvmem_config*) ; 
 int rtc_register_device (TYPE_1__*) ; 
 int /*<<< orphan*/  seq_printf (struct seq_file*,char*,char*) ; 
 int /*<<< orphan*/  writeb (unsigned char,TYPE_1__*) ; 

__attribute__((used)) static unsigned char m48t86_readb(struct device *dev, unsigned long addr)
{
	struct m48t86_rtc_info *info = dev_get_drvdata(dev);
	unsigned char value;

	writeb(addr, info->index_reg);
	value = readb(info->data_reg);

	return value;
}

__attribute__((used)) static void m48t86_writeb(struct device *dev,
			  unsigned char value, unsigned long addr)
{
	struct m48t86_rtc_info *info = dev_get_drvdata(dev);

	writeb(addr, info->index_reg);
	writeb(value, info->data_reg);
}

__attribute__((used)) static int m48t86_rtc_read_time(struct device *dev, struct rtc_time *tm)
{
	unsigned char reg;

	reg = m48t86_readb(dev, M48T86_B);

	if (reg & M48T86_B_DM) {
		/* data (binary) mode */
		tm->tm_sec	= m48t86_readb(dev, M48T86_SEC);
		tm->tm_min	= m48t86_readb(dev, M48T86_MIN);
		tm->tm_hour	= m48t86_readb(dev, M48T86_HOUR) & 0x3f;
		tm->tm_mday	= m48t86_readb(dev, M48T86_DOM);
		/* tm_mon is 0-11 */
		tm->tm_mon	= m48t86_readb(dev, M48T86_MONTH) - 1;
		tm->tm_year	= m48t86_readb(dev, M48T86_YEAR) + 100;
		tm->tm_wday	= m48t86_readb(dev, M48T86_DOW);
	} else {
		/* bcd mode */
		tm->tm_sec	= bcd2bin(m48t86_readb(dev, M48T86_SEC));
		tm->tm_min	= bcd2bin(m48t86_readb(dev, M48T86_MIN));
		tm->tm_hour	= bcd2bin(m48t86_readb(dev, M48T86_HOUR) &
					  0x3f);
		tm->tm_mday	= bcd2bin(m48t86_readb(dev, M48T86_DOM));
		/* tm_mon is 0-11 */
		tm->tm_mon	= bcd2bin(m48t86_readb(dev, M48T86_MONTH)) - 1;
		tm->tm_year	= bcd2bin(m48t86_readb(dev, M48T86_YEAR)) + 100;
		tm->tm_wday	= bcd2bin(m48t86_readb(dev, M48T86_DOW));
	}

	/* correct the hour if the clock is in 12h mode */
	if (!(reg & M48T86_B_H24))
		if (m48t86_readb(dev, M48T86_HOUR) & 0x80)
			tm->tm_hour += 12;

	return 0;
}

__attribute__((used)) static int m48t86_rtc_set_time(struct device *dev, struct rtc_time *tm)
{
	unsigned char reg;

	reg = m48t86_readb(dev, M48T86_B);

	/* update flag and 24h mode */
	reg |= M48T86_B_SET | M48T86_B_H24;
	m48t86_writeb(dev, reg, M48T86_B);

	if (reg & M48T86_B_DM) {
		/* data (binary) mode */
		m48t86_writeb(dev, tm->tm_sec, M48T86_SEC);
		m48t86_writeb(dev, tm->tm_min, M48T86_MIN);
		m48t86_writeb(dev, tm->tm_hour, M48T86_HOUR);
		m48t86_writeb(dev, tm->tm_mday, M48T86_DOM);
		m48t86_writeb(dev, tm->tm_mon + 1, M48T86_MONTH);
		m48t86_writeb(dev, tm->tm_year % 100, M48T86_YEAR);
		m48t86_writeb(dev, tm->tm_wday, M48T86_DOW);
	} else {
		/* bcd mode */
		m48t86_writeb(dev, bin2bcd(tm->tm_sec), M48T86_SEC);
		m48t86_writeb(dev, bin2bcd(tm->tm_min), M48T86_MIN);
		m48t86_writeb(dev, bin2bcd(tm->tm_hour), M48T86_HOUR);
		m48t86_writeb(dev, bin2bcd(tm->tm_mday), M48T86_DOM);
		m48t86_writeb(dev, bin2bcd(tm->tm_mon + 1), M48T86_MONTH);
		m48t86_writeb(dev, bin2bcd(tm->tm_year % 100), M48T86_YEAR);
		m48t86_writeb(dev, bin2bcd(tm->tm_wday), M48T86_DOW);
	}

	/* update ended */
	reg &= ~M48T86_B_SET;
	m48t86_writeb(dev, reg, M48T86_B);

	return 0;
}

__attribute__((used)) static int m48t86_rtc_proc(struct device *dev, struct seq_file *seq)
{
	unsigned char reg;

	reg = m48t86_readb(dev, M48T86_B);

	seq_printf(seq, "mode\t\t: %s\n",
		   (reg & M48T86_B_DM) ? "binary" : "bcd");

	reg = m48t86_readb(dev, M48T86_D);

	seq_printf(seq, "battery\t\t: %s\n",
		   (reg & M48T86_D_VRT) ? "ok" : "exhausted");

	return 0;
}

__attribute__((used)) static int m48t86_nvram_read(void *priv, unsigned int off, void *buf,
			     size_t count)
{
	struct device *dev = priv;
	unsigned int i;

	for (i = 0; i < count; i++)
		((u8 *)buf)[i] = m48t86_readb(dev, M48T86_NVRAM(off + i));

	return 0;
}

__attribute__((used)) static int m48t86_nvram_write(void *priv, unsigned int off, void *buf,
			      size_t count)
{
	struct device *dev = priv;
	unsigned int i;

	for (i = 0; i < count; i++)
		m48t86_writeb(dev, ((u8 *)buf)[i], M48T86_NVRAM(off + i));

	return 0;
}

__attribute__((used)) static bool m48t86_verify_chip(struct platform_device *pdev)
{
	unsigned int offset0 = M48T86_NVRAM(M48T86_NVRAM_LEN - 2);
	unsigned int offset1 = M48T86_NVRAM(M48T86_NVRAM_LEN - 1);
	unsigned char tmp0, tmp1;

	tmp0 = m48t86_readb(&pdev->dev, offset0);
	tmp1 = m48t86_readb(&pdev->dev, offset1);

	m48t86_writeb(&pdev->dev, 0x00, offset0);
	m48t86_writeb(&pdev->dev, 0x55, offset1);
	if (m48t86_readb(&pdev->dev, offset1) == 0x55) {
		m48t86_writeb(&pdev->dev, 0xaa, offset1);
		if (m48t86_readb(&pdev->dev, offset1) == 0xaa &&
		    m48t86_readb(&pdev->dev, offset0) == 0x00) {
			m48t86_writeb(&pdev->dev, tmp0, offset0);
			m48t86_writeb(&pdev->dev, tmp1, offset1);

			return true;
		}
	}
	return false;
}

__attribute__((used)) static int m48t86_rtc_probe(struct platform_device *pdev)
{
	struct m48t86_rtc_info *info;
	struct resource *res;
	unsigned char reg;
	int err;
	struct nvmem_config m48t86_nvmem_cfg = {
		.name = "m48t86_nvram",
		.word_size = 1,
		.stride = 1,
		.size = M48T86_NVRAM_LEN,
		.reg_read = m48t86_nvram_read,
		.reg_write = m48t86_nvram_write,
		.priv = &pdev->dev,
	};

	info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
	if (!info)
		return -ENOMEM;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res)
		return -ENODEV;
	info->index_reg = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(info->index_reg))
		return PTR_ERR(info->index_reg);

	res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
	if (!res)
		return -ENODEV;
	info->data_reg = devm_ioremap_resource(&pdev->dev, res);
	if (IS_ERR(info->data_reg))
		return PTR_ERR(info->data_reg);

	dev_set_drvdata(&pdev->dev, info);

	if (!m48t86_verify_chip(pdev)) {
		dev_info(&pdev->dev, "RTC not present\n");
		return -ENODEV;
	}

	info->rtc = devm_rtc_allocate_device(&pdev->dev);
	if (IS_ERR(info->rtc))
		return PTR_ERR(info->rtc);

	info->rtc->ops = &m48t86_rtc_ops;
	info->rtc->nvram_old_abi = true;

	err = rtc_register_device(info->rtc);
	if (err)
		return err;

	rtc_nvmem_register(info->rtc, &m48t86_nvmem_cfg);

	/* read battery status */
	reg = m48t86_readb(&pdev->dev, M48T86_D);
	dev_info(&pdev->dev, "battery %s\n",
		 (reg & M48T86_D_VRT) ? "ok" : "exhausted");

	return 0;
}

