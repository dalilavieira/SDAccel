#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint ;
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct bcma_drv_pci {int early_setup_done; int hostmode; struct bcma_device* core; scalar_t__ setup_done; } ;
struct bcma_drv_mips {int dummy; } ;
struct bcma_drv_gmac_cmn {int dummy; } ;
struct bcma_drv_cc {TYPE_1__* core; } ;
struct TYPE_4__ {int rev; } ;
struct bcma_device {TYPE_2__ id; scalar_t__ core_index; } ;
struct bcma_bus {scalar_t__ hosttype; struct bcma_drv_pci* drv_pci; } ;
struct TYPE_3__ {int /*<<< orphan*/  bus; } ;

/* Variables and functions */
 int BCMA_CORE_PCI_ASPMTIMER_EXTEND ; 
 int BCMA_CORE_PCI_DLLP_PMTHRESHREG ; 
 int BCMA_CORE_PCI_MDIOCTL_ACCESS_DONE ; 
 int BCMA_CORE_PCI_MDIOCTL_DIVISOR_VAL ; 
 int BCMA_CORE_PCI_MDIOCTL_PREAM_EN ; 
 int BCMA_CORE_PCI_MDIODATA_BLK_ADDR ; 
 int BCMA_CORE_PCI_MDIODATA_DEVADDR_SHF ; 
 int BCMA_CORE_PCI_MDIODATA_DEVADDR_SHF_OLD ; 
 int BCMA_CORE_PCI_MDIODATA_DEV_ADDR ; 
 int BCMA_CORE_PCI_MDIODATA_DEV_PLL ; 
 int BCMA_CORE_PCI_MDIODATA_DEV_RX ; 
 int BCMA_CORE_PCI_MDIODATA_READ ; 
 int BCMA_CORE_PCI_MDIODATA_REGADDR_SHF ; 
 int BCMA_CORE_PCI_MDIODATA_REGADDR_SHF_OLD ; 
 int BCMA_CORE_PCI_MDIODATA_START ; 
 int BCMA_CORE_PCI_MDIODATA_TA ; 
 int BCMA_CORE_PCI_MDIODATA_WRITE ; 
 int BCMA_CORE_PCI_MDIO_BLK1 ; 
 int BCMA_CORE_PCI_MDIO_BLK1_MGMT1 ; 
 int BCMA_CORE_PCI_MDIO_BLK1_MGMT3 ; 
 int /*<<< orphan*/  BCMA_CORE_PCI_MDIO_CONTROL ; 
 int /*<<< orphan*/  BCMA_CORE_PCI_MDIO_DATA ; 
 int /*<<< orphan*/  BCMA_CORE_PCI_PCIEIND_ADDR ; 
 int /*<<< orphan*/  BCMA_CORE_PCI_PCIEIND_DATA ; 
 int BCMA_CORE_PCI_PLL_CTRL_FREQDET_EN ; 
 int BCMA_CORE_PCI_PLP_POLARITYINV_STAT ; 
 int BCMA_CORE_PCI_PLP_STATUSREG ; 
 int BCMA_CORE_PCI_SERDES_PLL_CTRL ; 
 int BCMA_CORE_PCI_SERDES_RX_CTRL ; 
 int BCMA_CORE_PCI_SERDES_RX_CTRL_FORCE ; 
 int BCMA_CORE_PCI_SERDES_RX_CTRL_POLARITY ; 
 int /*<<< orphan*/  BCMA_CORE_PCI_SPROM (int /*<<< orphan*/ ) ; 
 int BCMA_CORE_PCI_SPROM_L23READY_EXIT_NOPERST ; 
 int /*<<< orphan*/  BCMA_CORE_PCI_SPROM_MISC_CONFIG ; 
 int BCMA_CORE_PCI_SPROM_PI_MASK ; 
 int /*<<< orphan*/  BCMA_CORE_PCI_SPROM_PI_OFFSET ; 
 int BCMA_CORE_PCI_SPROM_PI_SHIFT ; 
 scalar_t__ BCMA_HOSTTYPE_PCI ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  bcma_err (int /*<<< orphan*/ ,char*) ; 
 int pcicore_read16 (struct bcma_drv_pci*,int /*<<< orphan*/ ) ; 
 int pcicore_read32 (struct bcma_drv_pci*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcicore_write16 (struct bcma_drv_pci*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pcicore_write32 (struct bcma_drv_pci*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

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

u32 bcma_pcie_read(struct bcma_drv_pci *pc, u32 address)
{
	pcicore_write32(pc, BCMA_CORE_PCI_PCIEIND_ADDR, address);
	pcicore_read32(pc, BCMA_CORE_PCI_PCIEIND_ADDR);
	return pcicore_read32(pc, BCMA_CORE_PCI_PCIEIND_DATA);
}

__attribute__((used)) static void bcma_pcie_write(struct bcma_drv_pci *pc, u32 address, u32 data)
{
	pcicore_write32(pc, BCMA_CORE_PCI_PCIEIND_ADDR, address);
	pcicore_read32(pc, BCMA_CORE_PCI_PCIEIND_ADDR);
	pcicore_write32(pc, BCMA_CORE_PCI_PCIEIND_DATA, data);
}

__attribute__((used)) static void bcma_pcie_mdio_set_phy(struct bcma_drv_pci *pc, u16 phy)
{
	u32 v;
	int i;

	v = BCMA_CORE_PCI_MDIODATA_START;
	v |= BCMA_CORE_PCI_MDIODATA_WRITE;
	v |= (BCMA_CORE_PCI_MDIODATA_DEV_ADDR <<
	      BCMA_CORE_PCI_MDIODATA_DEVADDR_SHF);
	v |= (BCMA_CORE_PCI_MDIODATA_BLK_ADDR <<
	      BCMA_CORE_PCI_MDIODATA_REGADDR_SHF);
	v |= BCMA_CORE_PCI_MDIODATA_TA;
	v |= (phy << 4);
	pcicore_write32(pc, BCMA_CORE_PCI_MDIO_DATA, v);

	udelay(10);
	for (i = 0; i < 200; i++) {
		v = pcicore_read32(pc, BCMA_CORE_PCI_MDIO_CONTROL);
		if (v & BCMA_CORE_PCI_MDIOCTL_ACCESS_DONE)
			break;
		usleep_range(1000, 2000);
	}
}

__attribute__((used)) static u16 bcma_pcie_mdio_read(struct bcma_drv_pci *pc, u16 device, u8 address)
{
	int max_retries = 10;
	u16 ret = 0;
	u32 v;
	int i;

	/* enable mdio access to SERDES */
	v = BCMA_CORE_PCI_MDIOCTL_PREAM_EN;
	v |= BCMA_CORE_PCI_MDIOCTL_DIVISOR_VAL;
	pcicore_write32(pc, BCMA_CORE_PCI_MDIO_CONTROL, v);

	if (pc->core->id.rev >= 10) {
		max_retries = 200;
		bcma_pcie_mdio_set_phy(pc, device);
		v = (BCMA_CORE_PCI_MDIODATA_DEV_ADDR <<
		     BCMA_CORE_PCI_MDIODATA_DEVADDR_SHF);
		v |= (address << BCMA_CORE_PCI_MDIODATA_REGADDR_SHF);
	} else {
		v = (device << BCMA_CORE_PCI_MDIODATA_DEVADDR_SHF_OLD);
		v |= (address << BCMA_CORE_PCI_MDIODATA_REGADDR_SHF_OLD);
	}

	v = BCMA_CORE_PCI_MDIODATA_START;
	v |= BCMA_CORE_PCI_MDIODATA_READ;
	v |= BCMA_CORE_PCI_MDIODATA_TA;

	pcicore_write32(pc, BCMA_CORE_PCI_MDIO_DATA, v);
	/* Wait for the device to complete the transaction */
	udelay(10);
	for (i = 0; i < max_retries; i++) {
		v = pcicore_read32(pc, BCMA_CORE_PCI_MDIO_CONTROL);
		if (v & BCMA_CORE_PCI_MDIOCTL_ACCESS_DONE) {
			udelay(10);
			ret = pcicore_read32(pc, BCMA_CORE_PCI_MDIO_DATA);
			break;
		}
		usleep_range(1000, 2000);
	}
	pcicore_write32(pc, BCMA_CORE_PCI_MDIO_CONTROL, 0);
	return ret;
}

__attribute__((used)) static void bcma_pcie_mdio_write(struct bcma_drv_pci *pc, u16 device,
				u8 address, u16 data)
{
	int max_retries = 10;
	u32 v;
	int i;

	/* enable mdio access to SERDES */
	v = BCMA_CORE_PCI_MDIOCTL_PREAM_EN;
	v |= BCMA_CORE_PCI_MDIOCTL_DIVISOR_VAL;
	pcicore_write32(pc, BCMA_CORE_PCI_MDIO_CONTROL, v);

	if (pc->core->id.rev >= 10) {
		max_retries = 200;
		bcma_pcie_mdio_set_phy(pc, device);
		v = (BCMA_CORE_PCI_MDIODATA_DEV_ADDR <<
		     BCMA_CORE_PCI_MDIODATA_DEVADDR_SHF);
		v |= (address << BCMA_CORE_PCI_MDIODATA_REGADDR_SHF);
	} else {
		v = (device << BCMA_CORE_PCI_MDIODATA_DEVADDR_SHF_OLD);
		v |= (address << BCMA_CORE_PCI_MDIODATA_REGADDR_SHF_OLD);
	}

	v = BCMA_CORE_PCI_MDIODATA_START;
	v |= BCMA_CORE_PCI_MDIODATA_WRITE;
	v |= BCMA_CORE_PCI_MDIODATA_TA;
	v |= data;
	pcicore_write32(pc, BCMA_CORE_PCI_MDIO_DATA, v);
	/* Wait for the device to complete the transaction */
	udelay(10);
	for (i = 0; i < max_retries; i++) {
		v = pcicore_read32(pc, BCMA_CORE_PCI_MDIO_CONTROL);
		if (v & BCMA_CORE_PCI_MDIOCTL_ACCESS_DONE)
			break;
		usleep_range(1000, 2000);
	}
	pcicore_write32(pc, BCMA_CORE_PCI_MDIO_CONTROL, 0);
}

__attribute__((used)) static u16 bcma_pcie_mdio_writeread(struct bcma_drv_pci *pc, u16 device,
				    u8 address, u16 data)
{
	bcma_pcie_mdio_write(pc, device, address, data);
	return bcma_pcie_mdio_read(pc, device, address);
}

__attribute__((used)) static void bcma_core_pci_fixcfg(struct bcma_drv_pci *pc)
{
	struct bcma_device *core = pc->core;
	u16 val16, core_index;
	uint regoff;

	regoff = BCMA_CORE_PCI_SPROM(BCMA_CORE_PCI_SPROM_PI_OFFSET);
	core_index = (u16)core->core_index;

	val16 = pcicore_read16(pc, regoff);
	if (((val16 & BCMA_CORE_PCI_SPROM_PI_MASK) >> BCMA_CORE_PCI_SPROM_PI_SHIFT)
	     != core_index) {
		val16 = (core_index << BCMA_CORE_PCI_SPROM_PI_SHIFT) |
			(val16 & ~BCMA_CORE_PCI_SPROM_PI_MASK);
		pcicore_write16(pc, regoff, val16);
	}
}

void bcma_core_pci_early_init(struct bcma_drv_pci *pc)
{
	if (pc->early_setup_done)
		return;

	pc->hostmode = bcma_core_pci_is_in_hostmode(pc);
	if (pc->hostmode)
		goto out;

	bcma_core_pci_fixcfg(pc);

out:
	pc->early_setup_done = true;
}

__attribute__((used)) static u8 bcma_pcicore_polarity_workaround(struct bcma_drv_pci *pc)
{
	u32 tmp;

	tmp = bcma_pcie_read(pc, BCMA_CORE_PCI_PLP_STATUSREG);
	if (tmp & BCMA_CORE_PCI_PLP_POLARITYINV_STAT)
		return BCMA_CORE_PCI_SERDES_RX_CTRL_FORCE |
		       BCMA_CORE_PCI_SERDES_RX_CTRL_POLARITY;
	else
		return BCMA_CORE_PCI_SERDES_RX_CTRL_FORCE;
}

__attribute__((used)) static void bcma_pcicore_serdes_workaround(struct bcma_drv_pci *pc)
{
	u16 tmp;

	bcma_pcie_mdio_write(pc, BCMA_CORE_PCI_MDIODATA_DEV_RX,
	                     BCMA_CORE_PCI_SERDES_RX_CTRL,
			     bcma_pcicore_polarity_workaround(pc));
	tmp = bcma_pcie_mdio_read(pc, BCMA_CORE_PCI_MDIODATA_DEV_PLL,
	                          BCMA_CORE_PCI_SERDES_PLL_CTRL);
	if (tmp & BCMA_CORE_PCI_PLL_CTRL_FREQDET_EN)
		bcma_pcie_mdio_write(pc, BCMA_CORE_PCI_MDIODATA_DEV_PLL,
		                     BCMA_CORE_PCI_SERDES_PLL_CTRL,
		                     tmp & ~BCMA_CORE_PCI_PLL_CTRL_FREQDET_EN);
}

__attribute__((used)) static void bcma_core_pci_config_fixup(struct bcma_drv_pci *pc)
{
	u16 val16;
	uint regoff;

	regoff = BCMA_CORE_PCI_SPROM(BCMA_CORE_PCI_SPROM_MISC_CONFIG);

	val16 = pcicore_read16(pc, regoff);

	if (!(val16 & BCMA_CORE_PCI_SPROM_L23READY_EXIT_NOPERST)) {
		val16 |= BCMA_CORE_PCI_SPROM_L23READY_EXIT_NOPERST;
		pcicore_write16(pc, regoff, val16);
	}
}

__attribute__((used)) static void bcma_core_pci_clientmode_init(struct bcma_drv_pci *pc)
{
	bcma_pcicore_serdes_workaround(pc);
	bcma_core_pci_config_fixup(pc);
}

void bcma_core_pci_init(struct bcma_drv_pci *pc)
{
	if (pc->setup_done)
		return;

	bcma_core_pci_early_init(pc);

	if (pc->hostmode)
		bcma_core_pci_hostmode_init(pc);
	else
		bcma_core_pci_clientmode_init(pc);
}

void bcma_core_pci_power_save(struct bcma_bus *bus, bool up)
{
	struct bcma_drv_pci *pc;
	u16 data;

	if (bus->hosttype != BCMA_HOSTTYPE_PCI)
		return;

	pc = &bus->drv_pci[0];

	if (pc->core->id.rev >= 15 && pc->core->id.rev <= 20) {
		data = up ? 0x74 : 0x7C;
		bcma_pcie_mdio_writeread(pc, BCMA_CORE_PCI_MDIO_BLK1,
					 BCMA_CORE_PCI_MDIO_BLK1_MGMT1, 0x7F64);
		bcma_pcie_mdio_writeread(pc, BCMA_CORE_PCI_MDIO_BLK1,
					 BCMA_CORE_PCI_MDIO_BLK1_MGMT3, data);
	} else if (pc->core->id.rev >= 21 && pc->core->id.rev <= 22) {
		data = up ? 0x75 : 0x7D;
		bcma_pcie_mdio_writeread(pc, BCMA_CORE_PCI_MDIO_BLK1,
					 BCMA_CORE_PCI_MDIO_BLK1_MGMT1, 0x7E65);
		bcma_pcie_mdio_writeread(pc, BCMA_CORE_PCI_MDIO_BLK1,
					 BCMA_CORE_PCI_MDIO_BLK1_MGMT3, data);
	}
}

__attribute__((used)) static void bcma_core_pci_extend_L1timer(struct bcma_drv_pci *pc, bool extend)
{
	u32 w;

	w = bcma_pcie_read(pc, BCMA_CORE_PCI_DLLP_PMTHRESHREG);
	if (extend)
		w |= BCMA_CORE_PCI_ASPMTIMER_EXTEND;
	else
		w &= ~BCMA_CORE_PCI_ASPMTIMER_EXTEND;
	bcma_pcie_write(pc, BCMA_CORE_PCI_DLLP_PMTHRESHREG, w);
	bcma_pcie_read(pc, BCMA_CORE_PCI_DLLP_PMTHRESHREG);
}

void bcma_core_pci_up(struct bcma_drv_pci *pc)
{
	bcma_core_pci_extend_L1timer(pc, true);
}

void bcma_core_pci_down(struct bcma_drv_pci *pc)
{
	bcma_core_pci_extend_L1timer(pc, false);
}

