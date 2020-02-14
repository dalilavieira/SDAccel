#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct ssb_extif {int dummy; } ;
struct ssb_device {int dummy; } ;
struct ssb_chipcommon {int dummy; } ;
struct ssb_bus {int dummy; } ;
struct bcm47xx_wdt {int dummy; } ;

/* Variables and functions */
 int ENOTSUPP ; 
 int /*<<< orphan*/  pr_err (char*) ; 

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

