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
struct resource {unsigned short start; } ;
struct pnp_option {int flags; } ;
struct pnp_dev {unsigned int num_dependent_sets; unsigned char number; unsigned char active; TYPE_1__* card; int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  number; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  IORESOURCE_DISABLED ; 
 int /*<<< orphan*/  IORESOURCE_DMA ; 
 int /*<<< orphan*/  IORESOURCE_IO ; 
 int /*<<< orphan*/  IORESOURCE_IRQ ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 unsigned char ISAPNP_CFG_ACTIVATE ; 
 int ISAPNP_CFG_DMA ; 
 int ISAPNP_CFG_IRQ ; 
 int ISAPNP_CFG_MEM ; 
 int ISAPNP_CFG_PORT ; 
 int ISAPNP_MAX_DMA ; 
 int ISAPNP_MAX_IRQ ; 
 int ISAPNP_MAX_MEM ; 
 int ISAPNP_MAX_PORT ; 
 int PNP_OPTION_DEPENDENT ; 
 unsigned int PNP_OPTION_PRIORITY_MASK ; 
 unsigned int PNP_OPTION_PRIORITY_SHIFT ; 
 unsigned int PNP_OPTION_SET_MASK ; 
 unsigned int PNP_OPTION_SET_SHIFT ; 
 int PNP_RES_PRIORITY_FUNCTIONAL ; 
 int PNP_RES_PRIORITY_INVALID ; 
 int /*<<< orphan*/  _PIDXR ; 
 int /*<<< orphan*/  _PNPWRP ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*,int,int) ; 
 unsigned char inb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  isapnp_cfg_begin (int /*<<< orphan*/ ,unsigned char) ; 
 int /*<<< orphan*/  isapnp_cfg_end () ; 
 int /*<<< orphan*/  isapnp_rdp ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  outb (unsigned char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnp_add_dma_resource (struct pnp_dev*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnp_add_io_resource (struct pnp_dev*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnp_add_irq_resource (struct pnp_dev*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnp_add_mem_resource (struct pnp_dev*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pnp_dbg (int /*<<< orphan*/ *,char*,...) ; 
 struct resource* pnp_get_resource (struct pnp_dev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pnp_init_resources (struct pnp_dev*) ; 
 scalar_t__ pnp_resource_enabled (struct resource*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline int pnp_option_is_dependent(struct pnp_option *option)
{
	return option->flags & PNP_OPTION_DEPENDENT ? 1 : 0;
}

__attribute__((used)) static inline unsigned int pnp_option_set(struct pnp_option *option)
{
	return (option->flags >> PNP_OPTION_SET_SHIFT) & PNP_OPTION_SET_MASK;
}

__attribute__((used)) static inline unsigned int pnp_option_priority(struct pnp_option *option)
{
	return (option->flags >> PNP_OPTION_PRIORITY_SHIFT) &
	    PNP_OPTION_PRIORITY_MASK;
}

__attribute__((used)) static inline unsigned int pnp_new_dependent_set(struct pnp_dev *dev,
						 int priority)
{
	unsigned int flags;

	if (priority > PNP_RES_PRIORITY_FUNCTIONAL) {
		dev_warn(&dev->dev, "invalid dependent option priority %d "
			 "clipped to %d", priority,
			 PNP_RES_PRIORITY_INVALID);
		priority = PNP_RES_PRIORITY_INVALID;
	}

	flags = PNP_OPTION_DEPENDENT |
	    ((dev->num_dependent_sets & PNP_OPTION_SET_MASK) <<
		PNP_OPTION_SET_SHIFT) |
	    ((priority & PNP_OPTION_PRIORITY_MASK) <<
		PNP_OPTION_PRIORITY_SHIFT);

	dev->num_dependent_sets++;

	return flags;
}

__attribute__((used)) static inline void write_data(unsigned char x)
{
	outb(x, _PNPWRP);
}

__attribute__((used)) static inline void write_address(unsigned char x)
{
	outb(x, _PIDXR);
	udelay(20);
}

__attribute__((used)) static inline unsigned char read_data(void)
{
	unsigned char val = inb(isapnp_rdp);
	return val;
}

unsigned char isapnp_read_byte(unsigned char idx)
{
	write_address(idx);
	return read_data();
}

__attribute__((used)) static unsigned short isapnp_read_word(unsigned char idx)
{
	unsigned short val;

	val = isapnp_read_byte(idx);
	val = (val << 8) + isapnp_read_byte(idx + 1);
	return val;
}

void isapnp_write_byte(unsigned char idx, unsigned char val)
{
	write_address(idx);
	write_data(val);
}

__attribute__((used)) static void isapnp_write_word(unsigned char idx, unsigned short val)
{
	isapnp_write_byte(idx, val >> 8);
	isapnp_write_byte(idx + 1, val);
}

__attribute__((used)) static void isapnp_key(void)
{
	unsigned char code = 0x6a, msb;
	int i;

	mdelay(1);
	write_address(0x00);
	write_address(0x00);

	write_address(code);

	for (i = 1; i < 32; i++) {
		msb = ((code & 0x01) ^ ((code & 0x02) >> 1)) << 7;
		code = (code >> 1) | msb;
		write_address(code);
	}
}

__attribute__((used)) static void isapnp_wait(void)
{
	isapnp_write_byte(0x02, 0x02);
}

__attribute__((used)) static void isapnp_wake(unsigned char csn)
{
	isapnp_write_byte(0x03, csn);
}

__attribute__((used)) static void isapnp_device(unsigned char logdev)
{
	isapnp_write_byte(0x07, logdev);
}

__attribute__((used)) static void isapnp_activate(unsigned char logdev)
{
	isapnp_device(logdev);
	isapnp_write_byte(ISAPNP_CFG_ACTIVATE, 1);
	udelay(250);
}

__attribute__((used)) static void isapnp_deactivate(unsigned char logdev)
{
	isapnp_device(logdev);
	isapnp_write_byte(ISAPNP_CFG_ACTIVATE, 0);
	udelay(500);
}

__attribute__((used)) static int isapnp_get_resources(struct pnp_dev *dev)
{
	int i, ret;

	pnp_dbg(&dev->dev, "get resources\n");
	pnp_init_resources(dev);
	isapnp_cfg_begin(dev->card->number, dev->number);
	dev->active = isapnp_read_byte(ISAPNP_CFG_ACTIVATE);
	if (!dev->active)
		goto __end;

	for (i = 0; i < ISAPNP_MAX_PORT; i++) {
		ret = isapnp_read_word(ISAPNP_CFG_PORT + (i << 1));
		pnp_add_io_resource(dev, ret, ret,
				    ret == 0 ? IORESOURCE_DISABLED : 0);
	}
	for (i = 0; i < ISAPNP_MAX_MEM; i++) {
		ret = isapnp_read_word(ISAPNP_CFG_MEM + (i << 3)) << 8;
		pnp_add_mem_resource(dev, ret, ret,
				     ret == 0 ? IORESOURCE_DISABLED : 0);
	}
	for (i = 0; i < ISAPNP_MAX_IRQ; i++) {
		ret = isapnp_read_word(ISAPNP_CFG_IRQ + (i << 1)) >> 8;
		pnp_add_irq_resource(dev, ret,
				     ret == 0 ? IORESOURCE_DISABLED : 0);
	}
	for (i = 0; i < ISAPNP_MAX_DMA; i++) {
		ret = isapnp_read_byte(ISAPNP_CFG_DMA + i);
		pnp_add_dma_resource(dev, ret,
				     ret == 4 ? IORESOURCE_DISABLED : 0);
	}

__end:
	isapnp_cfg_end();
	return 0;
}

__attribute__((used)) static int isapnp_set_resources(struct pnp_dev *dev)
{
	struct resource *res;
	int tmp;

	pnp_dbg(&dev->dev, "set resources\n");
	isapnp_cfg_begin(dev->card->number, dev->number);
	dev->active = 1;
	for (tmp = 0; tmp < ISAPNP_MAX_PORT; tmp++) {
		res = pnp_get_resource(dev, IORESOURCE_IO, tmp);
		if (pnp_resource_enabled(res)) {
			pnp_dbg(&dev->dev, "  set io  %d to %#llx\n",
				tmp, (unsigned long long) res->start);
			isapnp_write_word(ISAPNP_CFG_PORT + (tmp << 1),
					  res->start);
		}
	}
	for (tmp = 0; tmp < ISAPNP_MAX_IRQ; tmp++) {
		res = pnp_get_resource(dev, IORESOURCE_IRQ, tmp);
		if (pnp_resource_enabled(res)) {
			int irq = res->start;
			if (irq == 2)
				irq = 9;
			pnp_dbg(&dev->dev, "  set irq %d to %d\n", tmp, irq);
			isapnp_write_byte(ISAPNP_CFG_IRQ + (tmp << 1), irq);
		}
	}
	for (tmp = 0; tmp < ISAPNP_MAX_DMA; tmp++) {
		res = pnp_get_resource(dev, IORESOURCE_DMA, tmp);
		if (pnp_resource_enabled(res)) {
			pnp_dbg(&dev->dev, "  set dma %d to %lld\n",
				tmp, (unsigned long long) res->start);
			isapnp_write_byte(ISAPNP_CFG_DMA + tmp, res->start);
		}
	}
	for (tmp = 0; tmp < ISAPNP_MAX_MEM; tmp++) {
		res = pnp_get_resource(dev, IORESOURCE_MEM, tmp);
		if (pnp_resource_enabled(res)) {
			pnp_dbg(&dev->dev, "  set mem %d to %#llx\n",
				tmp, (unsigned long long) res->start);
			isapnp_write_word(ISAPNP_CFG_MEM + (tmp << 3),
					  (res->start >> 8) & 0xffff);
		}
	}
	/* FIXME: We aren't handling 32bit mems properly here */
	isapnp_activate(dev->number);
	isapnp_cfg_end();
	return 0;
}

__attribute__((used)) static int isapnp_disable_resources(struct pnp_dev *dev)
{
	if (!dev->active)
		return -EINVAL;
	isapnp_cfg_begin(dev->card->number, dev->number);
	isapnp_deactivate(dev->number);
	dev->active = 0;
	isapnp_cfg_end();
	return 0;
}

