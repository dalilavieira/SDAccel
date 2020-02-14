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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  scalar_t__ u16 ;
struct bcma_drv_pci {int dummy; } ;
struct bcma_drv_mips {int dummy; } ;
struct bcma_drv_gmac_cmn {int dummy; } ;
struct bcma_drv_cc {TYPE_1__* core; } ;
struct bcma_device {scalar_t__ io_wrap; scalar_t__ io_addr; } ;
struct TYPE_2__ {int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 scalar_t__ WARN_ONCE (int,char*) ; 
 int /*<<< orphan*/  bcma_err (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 scalar_t__ readw (scalar_t__) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writew (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline int bcma_pflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "Parallel flash not supported\n");
	return 0;
}

__attribute__((used)) static inline int bcma_sflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "Serial flash not supported\n");
	return 0;
}

__attribute__((used)) static inline int bcma_nflash_init(struct bcma_drv_cc *cc)
{
	bcma_err(cc->core->bus, "NAND flash not supported\n");
	return 0;
}

__attribute__((used)) static inline bool bcma_core_pci_is_in_hostmode(struct bcma_drv_pci *pc)
{
	return false;
}

__attribute__((used)) static inline void bcma_core_pci_hostmode_init(struct bcma_drv_pci *pc)
{
}

__attribute__((used)) static inline unsigned int bcma_core_mips_irq(struct bcma_device *dev)
{
	return 0;
}

__attribute__((used)) static inline void bcma_core_mips_early_init(struct bcma_drv_mips *mcore)
{
}

__attribute__((used)) static inline void bcma_core_mips_init(struct bcma_drv_mips *mcore)
{
}

__attribute__((used)) static inline void bcma_core_gmac_cmn_init(struct bcma_drv_gmac_cmn *gc)
{
}

__attribute__((used)) static inline int bcma_gpio_init(struct bcma_drv_cc *cc)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline int bcma_gpio_unregister(struct bcma_drv_cc *cc)
{
	return 0;
}

__attribute__((used)) static u8 bcma_host_soc_read8(struct bcma_device *core, u16 offset)
{
	return readb(core->io_addr + offset);
}

__attribute__((used)) static u16 bcma_host_soc_read16(struct bcma_device *core, u16 offset)
{
	return readw(core->io_addr + offset);
}

__attribute__((used)) static u32 bcma_host_soc_read32(struct bcma_device *core, u16 offset)
{
	return readl(core->io_addr + offset);
}

__attribute__((used)) static void bcma_host_soc_write8(struct bcma_device *core, u16 offset,
				 u8 value)
{
	writeb(value, core->io_addr + offset);
}

__attribute__((used)) static void bcma_host_soc_write16(struct bcma_device *core, u16 offset,
				 u16 value)
{
	writew(value, core->io_addr + offset);
}

__attribute__((used)) static void bcma_host_soc_write32(struct bcma_device *core, u16 offset,
				 u32 value)
{
	writel(value, core->io_addr + offset);
}

__attribute__((used)) static u32 bcma_host_soc_aread32(struct bcma_device *core, u16 offset)
{
	if (WARN_ONCE(!core->io_wrap, "Accessed core has no wrapper/agent\n"))
		return ~0;
	return readl(core->io_wrap + offset);
}

__attribute__((used)) static void bcma_host_soc_awrite32(struct bcma_device *core, u16 offset,
				  u32 value)
{
	if (WARN_ONCE(!core->io_wrap, "Accessed core has no wrapper/agent\n"))
		return;
	writel(value, core->io_wrap + offset);
}

