#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  scalar_t__ u16 ;
struct ssb_sprom {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  type; int /*<<< orphan*/  vendor; } ;
struct ssb_init_invariants {int has_cardbus_slot; TYPE_1__ sprom; TYPE_1__ boardinfo; } ;
struct ssb_extif {int dummy; } ;
struct ssb_device {int core_index; struct ssb_bus* bus; } ;
struct ssb_chipcommon {int dummy; } ;
struct ssb_bus {scalar_t__ mmio; } ;
struct ssb_boardinfo {int dummy; } ;
struct bcm47xx_wdt {int dummy; } ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 int ENOTSUPP ; 
 int /*<<< orphan*/  SSB_BOARDVENDOR_BCM ; 
 int SSB_CORE_SIZE ; 
 int bcm47xx_nvram_getenv (char*,char*,int) ; 
 int kstrtou16 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_warn (char*,char*) ; 
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int /*<<< orphan*/  readl (scalar_t__) ; 
 scalar_t__ readw (scalar_t__) ; 
 int /*<<< orphan*/  simple_strtoul (char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ssb_fill_sprom_with_fallback (struct ssb_bus*,TYPE_1__*) ; 
 int /*<<< orphan*/  strim (char*) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  writew (scalar_t__,scalar_t__) ; 

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

__attribute__((used)) static u8 ssb_host_soc_read8(struct ssb_device *dev, u16 offset)
{
	struct ssb_bus *bus = dev->bus;

	offset += dev->core_index * SSB_CORE_SIZE;
	return readb(bus->mmio + offset);
}

__attribute__((used)) static u16 ssb_host_soc_read16(struct ssb_device *dev, u16 offset)
{
	struct ssb_bus *bus = dev->bus;

	offset += dev->core_index * SSB_CORE_SIZE;
	return readw(bus->mmio + offset);
}

__attribute__((used)) static u32 ssb_host_soc_read32(struct ssb_device *dev, u16 offset)
{
	struct ssb_bus *bus = dev->bus;

	offset += dev->core_index * SSB_CORE_SIZE;
	return readl(bus->mmio + offset);
}

__attribute__((used)) static void ssb_host_soc_write8(struct ssb_device *dev, u16 offset, u8 value)
{
	struct ssb_bus *bus = dev->bus;

	offset += dev->core_index * SSB_CORE_SIZE;
	writeb(value, bus->mmio + offset);
}

__attribute__((used)) static void ssb_host_soc_write16(struct ssb_device *dev, u16 offset, u16 value)
{
	struct ssb_bus *bus = dev->bus;

	offset += dev->core_index * SSB_CORE_SIZE;
	writew(value, bus->mmio + offset);
}

__attribute__((used)) static void ssb_host_soc_write32(struct ssb_device *dev, u16 offset, u32 value)
{
	struct ssb_bus *bus = dev->bus;

	offset += dev->core_index * SSB_CORE_SIZE;
	writel(value, bus->mmio + offset);
}

int ssb_host_soc_get_invariants(struct ssb_bus *bus,
				struct ssb_init_invariants *iv)
{
	char buf[20];
	int len, err;

	/* Fill boardinfo structure */
	memset(&iv->boardinfo, 0, sizeof(struct ssb_boardinfo));

	len = bcm47xx_nvram_getenv("boardvendor", buf, sizeof(buf));
	if (len > 0) {
		err = kstrtou16(strim(buf), 0, &iv->boardinfo.vendor);
		if (err)
			pr_warn("Couldn't parse nvram board vendor entry with value \"%s\"\n",
				buf);
	}
	if (!iv->boardinfo.vendor)
		iv->boardinfo.vendor = SSB_BOARDVENDOR_BCM;

	len = bcm47xx_nvram_getenv("boardtype", buf, sizeof(buf));
	if (len > 0) {
		err = kstrtou16(strim(buf), 0, &iv->boardinfo.type);
		if (err)
			pr_warn("Couldn't parse nvram board type entry with value \"%s\"\n",
				buf);
	}

	memset(&iv->sprom, 0, sizeof(struct ssb_sprom));
	ssb_fill_sprom_with_fallback(bus, &iv->sprom);

	if (bcm47xx_nvram_getenv("cardbus", buf, sizeof(buf)) >= 0)
		iv->has_cardbus_slot = !!simple_strtoul(buf, NULL, 10);

	return 0;
}

