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
typedef  int u32 ;
typedef  int u16 ;
struct ssb_pcicore {int setup_done; struct ssb_device* dev; int /*<<< orphan*/  hostmode; } ;
struct ssb_extif {int dummy; } ;
struct TYPE_2__ {int revision; scalar_t__ coreid; } ;
struct ssb_device {int core_index; TYPE_1__ id; struct ssb_bus* bus; } ;
struct ssb_chipcommon {int dummy; } ;
struct ssb_bus {scalar_t__ bustype; int /*<<< orphan*/  host_pci; } ;
struct bcm47xx_wdt {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 scalar_t__ SSB_BUSTYPE_PCI ; 
 scalar_t__ SSB_DEV_PCI ; 
 scalar_t__ SSB_DEV_PCIE ; 
 int SSB_IMCFGLO ; 
 int SSB_IMCFGLO_REQTO ; 
 int SSB_IMCFGLO_REQTO_SHIFT ; 
 int SSB_IMCFGLO_SERTO ; 
 int SSB_INTVEC ; 
 int SSB_PCICORE_SBTOPCI2 ; 
 int SSB_PCICORE_SBTOPCI_BURST ; 
 int SSB_PCICORE_SBTOPCI_MRM ; 
 int SSB_PCICORE_SBTOPCI_PREF ; 
 int SSB_PCICORE_SPROM (int) ; 
 int /*<<< orphan*/  SSB_PCI_IRQMASK ; 
 int SSB_TPSFLAG ; 
 int SSB_TPSFLAG_BPFLAG ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  might_sleep_if (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int pci_read_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int pci_write_config_dword (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  ssb_commit_settings (struct ssb_bus*) ; 
 int /*<<< orphan*/  ssb_device_enable (struct ssb_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssb_device_is_enabled (struct ssb_device*) ; 
static  int ssb_pcie_mdio_read (struct ssb_pcicore*,int const,int) ; 
static  void ssb_pcie_mdio_write (struct ssb_pcicore*,int const,int,int) ; 
static  int ssb_pcie_read (struct ssb_pcicore*,int) ; 
static  void ssb_pcie_write (struct ssb_pcicore*,int,int) ; 
 int ssb_read16 (struct ssb_device*,int) ; 
 int ssb_read32 (struct ssb_device*,int) ; 
 int /*<<< orphan*/  ssb_write16 (struct ssb_device*,int,int) ; 
 int /*<<< orphan*/  ssb_write32 (struct ssb_device*,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline int ssb_pci_switch_core(struct ssb_bus *bus,
				      struct ssb_device *dev)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pci_switch_coreidx(struct ssb_bus *bus,
					 u8 coreidx)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pci_xtal(struct ssb_bus *bus, u32 what,
			       int turn_on)
{
	return 0;
}

__attribute__((used)) static inline void ssb_pci_exit(struct ssb_bus *bus)
{
}

__attribute__((used)) static inline int ssb_pci_init(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pcmcia_switch_coreidx(struct ssb_bus *bus,
					    u8 coreidx)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pcmcia_switch_segment(struct ssb_bus *bus,
					    u8 seg)
{
	return 0;
}

__attribute__((used)) static inline int ssb_pcmcia_hardware_setup(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline void ssb_pcmcia_exit(struct ssb_bus *bus)
{
}

__attribute__((used)) static inline int ssb_pcmcia_init(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline int ssb_host_pcmcia_init(void)
{
	return 0;
}

__attribute__((used)) static inline void ssb_host_pcmcia_exit(void)
{
}

__attribute__((used)) static inline u32 ssb_sdio_scan_read32(struct ssb_bus *bus, u16 offset)
{
	return 0;
}

__attribute__((used)) static inline int ssb_sdio_scan_switch_coreidx(struct ssb_bus *bus, u8 coreidx)
{
	return 0;
}

__attribute__((used)) static inline void ssb_sdio_exit(struct ssb_bus *bus)
{
}

__attribute__((used)) static inline int ssb_sdio_init(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline int b43_pci_ssb_bridge_init(void)
{
	return 0;
}

__attribute__((used)) static inline void b43_pci_ssb_bridge_exit(void)
{
}

__attribute__((used)) static inline int ssb_sflash_init(struct ssb_chipcommon *cc)
{
	pr_err("Serial flash not supported\n");
	return 0;
}

__attribute__((used)) static inline u32 ssb_extif_watchdog_timer_set_wdt(struct bcm47xx_wdt *wdt,
						   u32 ticks)
{
	return 0;
}

__attribute__((used)) static inline u32 ssb_extif_watchdog_timer_set_ms(struct bcm47xx_wdt *wdt,
						  u32 ms)
{
	return 0;
}

__attribute__((used)) static inline int ssb_watchdog_register(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline void ssb_extif_init(struct ssb_extif *extif)
{
}

__attribute__((used)) static inline int ssb_gpio_init(struct ssb_bus *bus)
{
	return -ENOTSUPP;
}

__attribute__((used)) static inline int ssb_gpio_unregister(struct ssb_bus *bus)
{
	return 0;
}

__attribute__((used)) static inline
u32 pcicore_read32(struct ssb_pcicore *pc, u16 offset)
{
	return ssb_read32(pc->dev, offset);
}

__attribute__((used)) static inline
void pcicore_write32(struct ssb_pcicore *pc, u16 offset, u32 value)
{
	ssb_write32(pc->dev, offset, value);
}

__attribute__((used)) static inline
u16 pcicore_read16(struct ssb_pcicore *pc, u16 offset)
{
	return ssb_read16(pc->dev, offset);
}

__attribute__((used)) static inline
void pcicore_write16(struct ssb_pcicore *pc, u16 offset, u16 value)
{
	ssb_write16(pc->dev, offset, value);
}

__attribute__((used)) static void ssb_pcicore_fix_sprom_core_index(struct ssb_pcicore *pc)
{
	u16 tmp = pcicore_read16(pc, SSB_PCICORE_SPROM(0));
	if (((tmp & 0xF000) >> 12) != pc->dev->core_index) {
		tmp &= ~0xF000;
		tmp |= (pc->dev->core_index << 12);
		pcicore_write16(pc, SSB_PCICORE_SPROM(0), tmp);
	}
}

__attribute__((used)) static u8 ssb_pcicore_polarity_workaround(struct ssb_pcicore *pc)
{
	return (ssb_pcie_read(pc, 0x204) & 0x10) ? 0xC0 : 0x80;
}

__attribute__((used)) static void ssb_pcicore_serdes_workaround(struct ssb_pcicore *pc)
{
	const u8 serdes_pll_device = 0x1D;
	const u8 serdes_rx_device = 0x1F;
	u16 tmp;

	ssb_pcie_mdio_write(pc, serdes_rx_device, 1 /* Control */,
			    ssb_pcicore_polarity_workaround(pc));
	tmp = ssb_pcie_mdio_read(pc, serdes_pll_device, 1 /* Control */);
	if (tmp & 0x4000)
		ssb_pcie_mdio_write(pc, serdes_pll_device, 1, tmp & ~0x4000);
}

__attribute__((used)) static void ssb_pcicore_pci_setup_workarounds(struct ssb_pcicore *pc)
{
	struct ssb_device *pdev = pc->dev;
	struct ssb_bus *bus = pdev->bus;
	u32 tmp;

	tmp = pcicore_read32(pc, SSB_PCICORE_SBTOPCI2);
	tmp |= SSB_PCICORE_SBTOPCI_PREF;
	tmp |= SSB_PCICORE_SBTOPCI_BURST;
	pcicore_write32(pc, SSB_PCICORE_SBTOPCI2, tmp);

	if (pdev->id.revision < 5) {
		tmp = ssb_read32(pdev, SSB_IMCFGLO);
		tmp &= ~SSB_IMCFGLO_SERTO;
		tmp |= 2;
		tmp &= ~SSB_IMCFGLO_REQTO;
		tmp |= 3 << SSB_IMCFGLO_REQTO_SHIFT;
		ssb_write32(pdev, SSB_IMCFGLO, tmp);
		ssb_commit_settings(bus);
	} else if (pdev->id.revision >= 11) {
		tmp = pcicore_read32(pc, SSB_PCICORE_SBTOPCI2);
		tmp |= SSB_PCICORE_SBTOPCI_MRM;
		pcicore_write32(pc, SSB_PCICORE_SBTOPCI2, tmp);
	}
}

__attribute__((used)) static void ssb_pcicore_pcie_setup_workarounds(struct ssb_pcicore *pc)
{
	u32 tmp;
	u8 rev = pc->dev->id.revision;

	if (rev == 0 || rev == 1) {
		/* TLP Workaround register. */
		tmp = ssb_pcie_read(pc, 0x4);
		tmp |= 0x8;
		ssb_pcie_write(pc, 0x4, tmp);
	}
	if (rev == 1) {
		/* DLLP Link Control register. */
		tmp = ssb_pcie_read(pc, 0x100);
		tmp |= 0x40;
		ssb_pcie_write(pc, 0x100, tmp);
	}

	if (rev == 0) {
		const u8 serdes_rx_device = 0x1F;

		ssb_pcie_mdio_write(pc, serdes_rx_device,
					2 /* Timer */, 0x8128);
		ssb_pcie_mdio_write(pc, serdes_rx_device,
					6 /* CDR */, 0x0100);
		ssb_pcie_mdio_write(pc, serdes_rx_device,
					7 /* CDR BW */, 0x1466);
	} else if (rev == 3 || rev == 4 || rev == 5) {
		/* TODO: DLLP Power Management Threshold */
		ssb_pcicore_serdes_workaround(pc);
		/* TODO: ASPM */
	} else if (rev == 7) {
		/* TODO: No PLL down */
	}

	if (rev >= 6) {
		/* Miscellaneous Configuration Fixup */
		tmp = pcicore_read16(pc, SSB_PCICORE_SPROM(5));
		if (!(tmp & 0x8000))
			pcicore_write16(pc, SSB_PCICORE_SPROM(5),
					tmp | 0x8000);
	}
}

__attribute__((used)) static void ssb_pcicore_init_clientmode(struct ssb_pcicore *pc)
{
	struct ssb_device *pdev = pc->dev;
	struct ssb_bus *bus = pdev->bus;

	if (bus->bustype == SSB_BUSTYPE_PCI)
		ssb_pcicore_fix_sprom_core_index(pc);

	/* Disable PCI interrupts. */
	ssb_write32(pdev, SSB_INTVEC, 0);

	/* Additional PCIe always once-executed workarounds */
	if (pc->dev->id.coreid == SSB_DEV_PCIE) {
		ssb_pcicore_serdes_workaround(pc);
		/* TODO: ASPM */
		/* TODO: Clock Request Update */
	}
}

void ssb_pcicore_init(struct ssb_pcicore *pc)
{
	struct ssb_device *dev = pc->dev;

	if (!dev)
		return;
	if (!ssb_device_is_enabled(dev))
		ssb_device_enable(dev, 0);

#ifdef CONFIG_SSB_PCICORE_HOSTMODE
	pc->hostmode = pcicore_is_in_hostmode(pc);
	if (pc->hostmode)
		ssb_pcicore_init_hostmode(pc);
#endif /* CONFIG_SSB_PCICORE_HOSTMODE */
	if (!pc->hostmode)
		ssb_pcicore_init_clientmode(pc);
}

__attribute__((used)) static u32 ssb_pcie_read(struct ssb_pcicore *pc, u32 address)
{
	pcicore_write32(pc, 0x130, address);
	return pcicore_read32(pc, 0x134);
}

__attribute__((used)) static void ssb_pcie_write(struct ssb_pcicore *pc, u32 address, u32 data)
{
	pcicore_write32(pc, 0x130, address);
	pcicore_write32(pc, 0x134, data);
}

__attribute__((used)) static void ssb_pcie_mdio_set_phy(struct ssb_pcicore *pc, u8 phy)
{
	const u16 mdio_control = 0x128;
	const u16 mdio_data = 0x12C;
	u32 v;
	int i;

	v = (1 << 30); /* Start of Transaction */
	v |= (1 << 28); /* Write Transaction */
	v |= (1 << 17); /* Turnaround */
	v |= (0x1F << 18);
	v |= (phy << 4);
	pcicore_write32(pc, mdio_data, v);

	udelay(10);
	for (i = 0; i < 200; i++) {
		v = pcicore_read32(pc, mdio_control);
		if (v & 0x100 /* Trans complete */)
			break;
		msleep(1);
	}
}

__attribute__((used)) static u16 ssb_pcie_mdio_read(struct ssb_pcicore *pc, u8 device, u8 address)
{
	const u16 mdio_control = 0x128;
	const u16 mdio_data = 0x12C;
	int max_retries = 10;
	u16 ret = 0;
	u32 v;
	int i;

	v = 0x80; /* Enable Preamble Sequence */
	v |= 0x2; /* MDIO Clock Divisor */
	pcicore_write32(pc, mdio_control, v);

	if (pc->dev->id.revision >= 10) {
		max_retries = 200;
		ssb_pcie_mdio_set_phy(pc, device);
	}

	v = (1 << 30); /* Start of Transaction */
	v |= (1 << 29); /* Read Transaction */
	v |= (1 << 17); /* Turnaround */
	if (pc->dev->id.revision < 10)
		v |= (u32)device << 22;
	v |= (u32)address << 18;
	pcicore_write32(pc, mdio_data, v);
	/* Wait for the device to complete the transaction */
	udelay(10);
	for (i = 0; i < max_retries; i++) {
		v = pcicore_read32(pc, mdio_control);
		if (v & 0x100 /* Trans complete */) {
			udelay(10);
			ret = pcicore_read32(pc, mdio_data);
			break;
		}
		msleep(1);
	}
	pcicore_write32(pc, mdio_control, 0);
	return ret;
}

__attribute__((used)) static void ssb_pcie_mdio_write(struct ssb_pcicore *pc, u8 device,
				u8 address, u16 data)
{
	const u16 mdio_control = 0x128;
	const u16 mdio_data = 0x12C;
	int max_retries = 10;
	u32 v;
	int i;

	v = 0x80; /* Enable Preamble Sequence */
	v |= 0x2; /* MDIO Clock Divisor */
	pcicore_write32(pc, mdio_control, v);

	if (pc->dev->id.revision >= 10) {
		max_retries = 200;
		ssb_pcie_mdio_set_phy(pc, device);
	}

	v = (1 << 30); /* Start of Transaction */
	v |= (1 << 28); /* Write Transaction */
	v |= (1 << 17); /* Turnaround */
	if (pc->dev->id.revision < 10)
		v |= (u32)device << 22;
	v |= (u32)address << 18;
	v |= data;
	pcicore_write32(pc, mdio_data, v);
	/* Wait for the device to complete the transaction */
	udelay(10);
	for (i = 0; i < max_retries; i++) {
		v = pcicore_read32(pc, mdio_control);
		if (v & 0x100 /* Trans complete */)
			break;
		msleep(1);
	}
	pcicore_write32(pc, mdio_control, 0);
}

int ssb_pcicore_dev_irqvecs_enable(struct ssb_pcicore *pc,
				   struct ssb_device *dev)
{
	struct ssb_device *pdev = pc->dev;
	struct ssb_bus *bus;
	int err = 0;
	u32 tmp;

	if (dev->bus->bustype != SSB_BUSTYPE_PCI) {
		/* This SSB device is not on a PCI host-bus. So the IRQs are
		 * not routed through the PCI core.
		 * So we must not enable routing through the PCI core. */
		goto out;
	}

	if (!pdev)
		goto out;
	bus = pdev->bus;

	might_sleep_if(pdev->id.coreid != SSB_DEV_PCI);

	/* Enable interrupts for this device. */
	if ((pdev->id.revision >= 6) || (pdev->id.coreid == SSB_DEV_PCIE)) {
		u32 coremask;

		/* Calculate the "coremask" for the device. */
		coremask = (1 << dev->core_index);

		WARN_ON(bus->bustype != SSB_BUSTYPE_PCI);
		err = pci_read_config_dword(bus->host_pci, SSB_PCI_IRQMASK, &tmp);
		if (err)
			goto out;
		tmp |= coremask << 8;
		err = pci_write_config_dword(bus->host_pci, SSB_PCI_IRQMASK, tmp);
		if (err)
			goto out;
	} else {
		u32 intvec;

		intvec = ssb_read32(pdev, SSB_INTVEC);
		tmp = ssb_read32(dev, SSB_TPSFLAG);
		tmp &= SSB_TPSFLAG_BPFLAG;
		intvec |= (1 << tmp);
		ssb_write32(pdev, SSB_INTVEC, intvec);
	}

	/* Setup PCIcore operation. */
	if (pc->setup_done)
		goto out;
	if (pdev->id.coreid == SSB_DEV_PCI) {
		ssb_pcicore_pci_setup_workarounds(pc);
	} else {
		WARN_ON(pdev->id.coreid != SSB_DEV_PCIE);
		ssb_pcicore_pcie_setup_workarounds(pc);
	}
	pc->setup_done = 1;
out:
	return err;
}

