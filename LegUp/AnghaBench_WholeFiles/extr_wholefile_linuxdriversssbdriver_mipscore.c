#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct ssb_sflash {scalar_t__ present; } ;
struct ssb_pflash {int present; int buswidth; scalar_t__ window_size; scalar_t__ window; } ;
struct ssb_mipscore {struct ssb_device* dev; struct ssb_pflash pflash; struct ssb_sflash sflash; int /*<<< orphan*/  nr_serial_ports; int /*<<< orphan*/  serial_ports; } ;
struct ssb_extif {int dummy; } ;
struct TYPE_6__ {int coreid; } ;
struct ssb_device {unsigned int irq; int /*<<< orphan*/  dev; TYPE_2__ id; struct ssb_bus* bus; } ;
struct ssb_chipcommon {int capabilities; struct ssb_device* dev; } ;
struct TYPE_5__ {struct ssb_device* dev; } ;
struct ssb_bus {int nr_devices; int chip_id; struct ssb_device* devices; struct ssb_chipcommon chipco; int /*<<< orphan*/  extif; TYPE_1__ mipscore; } ;
struct bcm47xx_wdt {int dummy; } ;
struct TYPE_8__ {int width; } ;
struct TYPE_7__ {scalar_t__ end; scalar_t__ start; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int ENOTSUPP ; 
 int SSB_CHIPCO_CAP_FLASHT ; 
 int SSB_CHIPCO_CAP_PMU ; 
 int SSB_CHIPCO_CFG_DS16 ; 
#define  SSB_CHIPCO_FLASHT_ATSER 137 
#define  SSB_CHIPCO_FLASHT_PARA 136 
#define  SSB_CHIPCO_FLASHT_STSER 135 
 int /*<<< orphan*/  SSB_CHIPCO_FLASH_CFG ; 
#define  SSB_DEV_80211 134 
#define  SSB_DEV_ETHERNET 133 
#define  SSB_DEV_ETHERNET_GBIT 132 
#define  SSB_DEV_EXTIF 131 
#define  SSB_DEV_PCI 130 
#define  SSB_DEV_USB11_HOST 129 
#define  SSB_DEV_USB20_HOST 128 
 scalar_t__ SSB_FLASH1 ; 
 scalar_t__ SSB_FLASH1_SZ ; 
 scalar_t__ SSB_FLASH2 ; 
 scalar_t__ SSB_FLASH2_SZ ; 
 int /*<<< orphan*/  SSB_INTVEC ; 
 int /*<<< orphan*/  SSB_IPSFLAG ; 
 int SSB_PLLTYPE_5 ; 
 int SSB_PLLTYPE_6 ; 
 int /*<<< orphan*/  SSB_TPSFLAG ; 
 int SSB_TPSFLAG_BPFLAG ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int* ipsflag_irq_mask ; 
 int* ipsflag_irq_shift ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int ssb_calc_clock_rate (int,int,int) ; 
 scalar_t__ ssb_chipco_available (struct ssb_chipcommon*) ; 
 int /*<<< orphan*/  ssb_chipco_get_clockcpu (struct ssb_chipcommon*,int*,int*,int*) ; 
 int /*<<< orphan*/  ssb_chipco_serial_init (struct ssb_chipcommon*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssb_chipco_timing_init (struct ssb_chipcommon*,unsigned long) ; 
 unsigned long ssb_clockspeed (struct ssb_bus*) ; 
 scalar_t__ ssb_extif_available (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ssb_extif_get_clockcontrol (int /*<<< orphan*/ *,int*,int*,int*) ; 
 int /*<<< orphan*/  ssb_extif_serial_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssb_extif_timing_init (int /*<<< orphan*/ *,unsigned long) ; 
 TYPE_4__ ssb_pflash_data ; 
 TYPE_3__ ssb_pflash_resource ; 
 int ssb_pmu_get_cpu_clock (struct ssb_chipcommon*) ; 
 int ssb_read32 (struct ssb_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ssb_write32 (struct ssb_device*,int /*<<< orphan*/ ,int) ; 

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

__attribute__((used)) static inline u32 mips_read32(struct ssb_mipscore *mcore,
			      u16 offset)
{
	return ssb_read32(mcore->dev, offset);
}

__attribute__((used)) static inline void mips_write32(struct ssb_mipscore *mcore,
				u16 offset,
				u32 value)
{
	ssb_write32(mcore->dev, offset, value);
}

__attribute__((used)) static inline u32 ssb_irqflag(struct ssb_device *dev)
{
	u32 tpsflag = ssb_read32(dev, SSB_TPSFLAG);
	if (tpsflag)
		return ssb_read32(dev, SSB_TPSFLAG) & SSB_TPSFLAG_BPFLAG;
	else
		/* not irq supported */
		return 0x3f;
}

__attribute__((used)) static struct ssb_device *find_device(struct ssb_device *rdev, int irqflag)
{
	struct ssb_bus *bus = rdev->bus;
	int i;
	for (i = 0; i < bus->nr_devices; i++) {
		struct ssb_device *dev;
		dev = &(bus->devices[i]);
		if (ssb_irqflag(dev) == irqflag)
			return dev;
	}
	return NULL;
}

unsigned int ssb_mips_irq(struct ssb_device *dev)
{
	struct ssb_bus *bus = dev->bus;
	struct ssb_device *mdev = bus->mipscore.dev;
	u32 irqflag;
	u32 ipsflag;
	u32 tmp;
	unsigned int irq;

	irqflag = ssb_irqflag(dev);
	if (irqflag == 0x3f)
		return 6;
	ipsflag = ssb_read32(bus->mipscore.dev, SSB_IPSFLAG);
	for (irq = 1; irq <= 4; irq++) {
		tmp = ((ipsflag & ipsflag_irq_mask[irq]) >> ipsflag_irq_shift[irq]);
		if (tmp == irqflag)
			break;
	}
	if (irq	== 5) {
		if ((1 << irqflag) & ssb_read32(mdev, SSB_INTVEC))
			irq = 0;
	}

	return irq;
}

__attribute__((used)) static void clear_irq(struct ssb_bus *bus, unsigned int irq)
{
	struct ssb_device *dev = bus->mipscore.dev;

	/* Clear the IRQ in the MIPScore backplane registers */
	if (irq == 0) {
		ssb_write32(dev, SSB_INTVEC, 0);
	} else {
		ssb_write32(dev, SSB_IPSFLAG,
			    ssb_read32(dev, SSB_IPSFLAG) |
			    ipsflag_irq_mask[irq]);
	}
}

__attribute__((used)) static void set_irq(struct ssb_device *dev, unsigned int irq)
{
	unsigned int oldirq = ssb_mips_irq(dev);
	struct ssb_bus *bus = dev->bus;
	struct ssb_device *mdev = bus->mipscore.dev;
	u32 irqflag = ssb_irqflag(dev);

	BUG_ON(oldirq == 6);

	dev->irq = irq + 2;

	/* clear the old irq */
	if (oldirq == 0)
		ssb_write32(mdev, SSB_INTVEC, (~(1 << irqflag) & ssb_read32(mdev, SSB_INTVEC)));
	else if (oldirq != 5)
		clear_irq(bus, oldirq);

	/* assign the new one */
	if (irq == 0) {
		ssb_write32(mdev, SSB_INTVEC, ((1 << irqflag) | ssb_read32(mdev, SSB_INTVEC)));
	} else {
		u32 ipsflag = ssb_read32(mdev, SSB_IPSFLAG);
		if ((ipsflag & ipsflag_irq_mask[irq]) != ipsflag_irq_mask[irq]) {
			u32 oldipsflag = (ipsflag & ipsflag_irq_mask[irq]) >> ipsflag_irq_shift[irq];
			struct ssb_device *olddev = find_device(dev, oldipsflag);
			if (olddev)
				set_irq(olddev, 0);
		}
		irqflag <<= ipsflag_irq_shift[irq];
		irqflag |= (ipsflag & ~ipsflag_irq_mask[irq]);
		ssb_write32(mdev, SSB_IPSFLAG, irqflag);
	}
	dev_dbg(dev->dev, "set_irq: core 0x%04x, irq %d => %d\n",
		dev->id.coreid, oldirq+2, irq+2);
}

__attribute__((used)) static void print_irq(struct ssb_device *dev, unsigned int irq)
{
	static const char *irq_name[] = {"2(S)", "3", "4", "5", "6", "D", "I"};
	dev_dbg(dev->dev,
		"core 0x%04x, irq : %s%s %s%s %s%s %s%s %s%s %s%s %s%s\n",
		dev->id.coreid,
		irq_name[0], irq == 0 ? "*" : " ",
		irq_name[1], irq == 1 ? "*" : " ",
		irq_name[2], irq == 2 ? "*" : " ",
		irq_name[3], irq == 3 ? "*" : " ",
		irq_name[4], irq == 4 ? "*" : " ",
		irq_name[5], irq == 5 ? "*" : " ",
		irq_name[6], irq == 6 ? "*" : " ");
}

__attribute__((used)) static void dump_irq(struct ssb_bus *bus)
{
	int i;
	for (i = 0; i < bus->nr_devices; i++) {
		struct ssb_device *dev;
		dev = &(bus->devices[i]);
		print_irq(dev, ssb_mips_irq(dev));
	}
}

__attribute__((used)) static void ssb_mips_serial_init(struct ssb_mipscore *mcore)
{
	struct ssb_bus *bus = mcore->dev->bus;

	if (ssb_extif_available(&bus->extif))
		mcore->nr_serial_ports = ssb_extif_serial_init(&bus->extif, mcore->serial_ports);
	else if (ssb_chipco_available(&bus->chipco))
		mcore->nr_serial_ports = ssb_chipco_serial_init(&bus->chipco, mcore->serial_ports);
	else
		mcore->nr_serial_ports = 0;
}

__attribute__((used)) static void ssb_mips_flash_detect(struct ssb_mipscore *mcore)
{
	struct ssb_bus *bus = mcore->dev->bus;
	struct ssb_sflash *sflash = &mcore->sflash;
	struct ssb_pflash *pflash = &mcore->pflash;

	/* When there is no chipcommon on the bus there is 4MB flash */
	if (!ssb_chipco_available(&bus->chipco)) {
		pflash->present = true;
		pflash->buswidth = 2;
		pflash->window = SSB_FLASH1;
		pflash->window_size = SSB_FLASH1_SZ;
		goto ssb_pflash;
	}

	/* There is ChipCommon, so use it to read info about flash */
	switch (bus->chipco.capabilities & SSB_CHIPCO_CAP_FLASHT) {
	case SSB_CHIPCO_FLASHT_STSER:
	case SSB_CHIPCO_FLASHT_ATSER:
		dev_dbg(mcore->dev->dev, "Found serial flash\n");
		ssb_sflash_init(&bus->chipco);
		break;
	case SSB_CHIPCO_FLASHT_PARA:
		dev_dbg(mcore->dev->dev, "Found parallel flash\n");
		pflash->present = true;
		pflash->window = SSB_FLASH2;
		pflash->window_size = SSB_FLASH2_SZ;
		if ((ssb_read32(bus->chipco.dev, SSB_CHIPCO_FLASH_CFG)
		               & SSB_CHIPCO_CFG_DS16) == 0)
			pflash->buswidth = 1;
		else
			pflash->buswidth = 2;
		break;
	}

ssb_pflash:
	if (sflash->present) {
#ifdef CONFIG_BCM47XX
		bcm47xx_nvram_init_from_mem(sflash->window, sflash->size);
#endif
	} else if (pflash->present) {
#ifdef CONFIG_BCM47XX
		bcm47xx_nvram_init_from_mem(pflash->window, pflash->window_size);
#endif

		ssb_pflash_data.width = pflash->buswidth;
		ssb_pflash_resource.start = pflash->window;
		ssb_pflash_resource.end = pflash->window + pflash->window_size;
	}
}

u32 ssb_cpu_clock(struct ssb_mipscore *mcore)
{
	struct ssb_bus *bus = mcore->dev->bus;
	u32 pll_type, n, m, rate = 0;

	if (bus->chipco.capabilities & SSB_CHIPCO_CAP_PMU)
		return ssb_pmu_get_cpu_clock(&bus->chipco);

	if (ssb_extif_available(&bus->extif)) {
		ssb_extif_get_clockcontrol(&bus->extif, &pll_type, &n, &m);
	} else if (ssb_chipco_available(&bus->chipco)) {
		ssb_chipco_get_clockcpu(&bus->chipco, &pll_type, &n, &m);
	} else
		return 0;

	if ((pll_type == SSB_PLLTYPE_5) || (bus->chip_id == 0x5365)) {
		rate = 200000000;
	} else {
		rate = ssb_calc_clock_rate(pll_type, n, m);
	}

	if (pll_type == SSB_PLLTYPE_6) {
		rate *= 2;
	}

	return rate;
}

void ssb_mipscore_init(struct ssb_mipscore *mcore)
{
	struct ssb_bus *bus;
	struct ssb_device *dev;
	unsigned long hz, ns;
	unsigned int irq, i;

	if (!mcore->dev)
		return; /* We don't have a MIPS core */

	dev_dbg(mcore->dev->dev, "Initializing MIPS core...\n");

	bus = mcore->dev->bus;
	hz = ssb_clockspeed(bus);
	if (!hz)
		hz = 100000000;
	ns = 1000000000 / hz;

	if (ssb_extif_available(&bus->extif))
		ssb_extif_timing_init(&bus->extif, ns);
	else if (ssb_chipco_available(&bus->chipco))
		ssb_chipco_timing_init(&bus->chipco, ns);

	/* Assign IRQs to all cores on the bus, start with irq line 2, because serial usually takes 1 */
	for (irq = 2, i = 0; i < bus->nr_devices; i++) {
		int mips_irq;
		dev = &(bus->devices[i]);
		mips_irq = ssb_mips_irq(dev);
		if (mips_irq > 4)
			dev->irq = 0;
		else
			dev->irq = mips_irq + 2;
		if (dev->irq > 5)
			continue;
		switch (dev->id.coreid) {
		case SSB_DEV_USB11_HOST:
			/* shouldn't need a separate irq line for non-4710, most of them have a proper
			 * external usb controller on the pci */
			if ((bus->chip_id == 0x4710) && (irq <= 4)) {
				set_irq(dev, irq++);
			}
			break;
		case SSB_DEV_PCI:
		case SSB_DEV_ETHERNET:
		case SSB_DEV_ETHERNET_GBIT:
		case SSB_DEV_80211:
		case SSB_DEV_USB20_HOST:
			/* These devices get their own IRQ line if available, the rest goes on IRQ0 */
			if (irq <= 4) {
				set_irq(dev, irq++);
				break;
			}
			/* fallthrough */
		case SSB_DEV_EXTIF:
			set_irq(dev, 0);
			break;
		}
	}
	dev_dbg(mcore->dev->dev, "after irq reconfiguration\n");
	dump_irq(bus);

	ssb_mips_serial_init(mcore);
	ssb_mips_flash_detect(mcore);
}

