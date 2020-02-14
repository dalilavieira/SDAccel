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
typedef  unsigned long u32 ;
struct regmap_config {int dummy; } ;
struct regmap_bus {int dummy; } ;
struct regmap {int dummy; } ;
struct TYPE_2__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct device_node {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 scalar_t__ SIRFSOC_CPUIOBRG_ADDR ; 
 scalar_t__ SIRFSOC_CPUIOBRG_CTRL ; 
 scalar_t__ SIRFSOC_CPUIOBRG_DATA ; 
 scalar_t__ SIRFSOC_CPUIOBRG_WRBE ; 
 int /*<<< orphan*/  cpu_relax () ; 
 struct regmap* devm_regmap_init (struct device*,struct regmap_bus const*,struct device*,struct regmap_config const*) ; 
 scalar_t__ of_iomap (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  panic (char*) ; 
 unsigned long readl_relaxed (scalar_t__) ; 
 struct regmap_bus regmap_iobg ; 
 int /*<<< orphan*/  rtciobrg_lock ; 
 scalar_t__ sirfsoc_rtciobrg_base ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 

void sirfsoc_rtc_iobrg_wait_sync(void)
{
	while (readl_relaxed(sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_CTRL))
		cpu_relax();
}

void sirfsoc_rtc_iobrg_besyncing(void)
{
	unsigned long flags;

	spin_lock_irqsave(&rtciobrg_lock, flags);

	sirfsoc_rtc_iobrg_wait_sync();

	spin_unlock_irqrestore(&rtciobrg_lock, flags);
}

u32 __sirfsoc_rtc_iobrg_readl(u32 addr)
{
	sirfsoc_rtc_iobrg_wait_sync();

	writel_relaxed(0x00, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_WRBE);
	writel_relaxed(addr, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_ADDR);
	writel_relaxed(0x01, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_CTRL);

	sirfsoc_rtc_iobrg_wait_sync();

	return readl_relaxed(sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_DATA);
}

u32 sirfsoc_rtc_iobrg_readl(u32 addr)
{
	unsigned long flags, val;

	/* TODO: add hwspinlock to sync with M3 */
	spin_lock_irqsave(&rtciobrg_lock, flags);

	val = __sirfsoc_rtc_iobrg_readl(addr);

	spin_unlock_irqrestore(&rtciobrg_lock, flags);

	return val;
}

void sirfsoc_rtc_iobrg_pre_writel(u32 val, u32 addr)
{
	sirfsoc_rtc_iobrg_wait_sync();

	writel_relaxed(0xf1, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_WRBE);
	writel_relaxed(addr, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_ADDR);

	writel_relaxed(val, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_DATA);
}

void sirfsoc_rtc_iobrg_writel(u32 val, u32 addr)
{
	unsigned long flags;

	 /* TODO: add hwspinlock to sync with M3 */
	spin_lock_irqsave(&rtciobrg_lock, flags);

	sirfsoc_rtc_iobrg_pre_writel(val, addr);

	writel_relaxed(0x01, sirfsoc_rtciobrg_base + SIRFSOC_CPUIOBRG_CTRL);

	sirfsoc_rtc_iobrg_wait_sync();

	spin_unlock_irqrestore(&rtciobrg_lock, flags);
}

__attribute__((used)) static int regmap_iobg_regwrite(void *context, unsigned int reg,
				   unsigned int val)
{
	sirfsoc_rtc_iobrg_writel(val, reg);
	return 0;
}

__attribute__((used)) static int regmap_iobg_regread(void *context, unsigned int reg,
				  unsigned int *val)
{
	*val = (u32)sirfsoc_rtc_iobrg_readl(reg);
	return 0;
}

struct regmap *devm_regmap_init_iobg(struct device *dev,
				    const struct regmap_config *config)
{
	const struct regmap_bus *bus = &regmap_iobg;

	return devm_regmap_init(dev, bus, dev, config);
}

__attribute__((used)) static int sirfsoc_rtciobrg_probe(struct platform_device *op)
{
	struct device_node *np = op->dev.of_node;

	sirfsoc_rtciobrg_base = of_iomap(np, 0);
	if (!sirfsoc_rtciobrg_base)
		panic("unable to map rtc iobrg registers\n");

	return 0;
}

