#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct ssb_device {int dummy; } ;
struct ieee80211_hw {struct b43_wl* priv; } ;
struct device {int dummy; } ;
struct b43_wldev {int __using_pio_transfers; TYPE_5__* dev; } ;
struct b43_wl {int if_type; TYPE_4__* hw; scalar_t__ operating; } ;
struct b43_txstatus {int dummy; } ;
struct b43_rfatt {scalar_t__ att; scalar_t__ with_padmix; } ;
struct b43_nphy_channeltab_entry_rev2 {int flags; int ghz5; int ghz2; scalar_t__ channel; } ;
struct b43_bus_dev {int dummy; } ;
struct b43_bbatt {scalar_t__ att; } ;
struct b2055_inittab_entry {int flags; int ghz5; int ghz2; scalar_t__ channel; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum b43_dyndbg { ____Placeholder_b43_dyndbg } b43_dyndbg ;
struct TYPE_20__ {int (* bus_may_powerdown ) (TYPE_5__*) ;int (* bus_powerup ) (TYPE_5__*,int) ;int (* device_is_enabled ) (TYPE_5__*) ;int (* read16 ) (TYPE_5__*,int) ;int (* read32 ) (TYPE_5__*,int) ;int /*<<< orphan*/  (* block_write ) (TYPE_5__*,void const*,size_t,int,scalar_t__) ;int /*<<< orphan*/  (* block_read ) (TYPE_5__*,void*,size_t,int,scalar_t__) ;int /*<<< orphan*/  (* write32 ) (TYPE_5__*,int,int) ;int /*<<< orphan*/  (* write16 ) (TYPE_5__*,int,int) ;int /*<<< orphan*/  (* device_disable ) (TYPE_5__*,int) ;int /*<<< orphan*/  (* device_enable ) (TYPE_5__*,int) ;} ;
struct TYPE_17__ {TYPE_1__* chan; } ;
struct TYPE_18__ {TYPE_2__ chandef; } ;
struct TYPE_19__ {TYPE_3__ conf; } ;
struct TYPE_16__ {int band; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct b43_nphy_channeltab_entry_rev2*) ; 
 int B2055_INITTAB_ENTRY_OK ; 
 int B2055_INITTAB_UPLOAD ; 
 int B43_MMIO_MACCTL ; 
 struct b43_nphy_channeltab_entry_rev2* b2055_inittab ; 
 struct b43_nphy_channeltab_entry_rev2* b43_nphy_channeltab_rev2 ; 
 int /*<<< orphan*/  b43_radio_write16 (struct b43_wldev*,unsigned int,int) ; 
 struct ssb_device* dev_to_ssb_dev (struct device*) ; 
 struct b43_wldev* ssb_get_drvdata (struct ssb_device*) ; 
 int stub1 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_5__*,void*,size_t,int,scalar_t__) ; 
 int /*<<< orphan*/  stub11 (TYPE_5__*,void const*,size_t,int,scalar_t__) ; 
 int stub2 (TYPE_5__*,int) ; 
 int stub3 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_5__*,int) ; 
 int /*<<< orphan*/  stub5 (TYPE_5__*,int) ; 
 int stub6 (TYPE_5__*,int) ; 
 int /*<<< orphan*/  stub7 (TYPE_5__*,int,int) ; 
 int stub8 (TYPE_5__*,int) ; 
 int /*<<< orphan*/  stub9 (TYPE_5__*,int,int) ; 

__attribute__((used)) static inline bool b43_debug(struct b43_wldev *dev, enum b43_dyndbg feature)
{
	return false;
}

__attribute__((used)) static inline void b43_debugfs_init(void)
{
}

__attribute__((used)) static inline void b43_debugfs_exit(void)
{
}

__attribute__((used)) static inline void b43_debugfs_add_device(struct b43_wldev *dev)
{
}

__attribute__((used)) static inline void b43_debugfs_remove_device(struct b43_wldev *dev)
{
}

__attribute__((used)) static inline void b43_debugfs_log_txstat(struct b43_wldev *dev,
					  const struct b43_txstatus *status)
{
}

__attribute__((used)) static inline void b43_leds_register(struct b43_wldev *dev)
{
}

__attribute__((used)) static inline void b43_leds_unregister(struct b43_wl *wl)
{
}

__attribute__((used)) static inline void b43_leds_init(struct b43_wldev *dev)
{
}

__attribute__((used)) static inline void b43_leds_exit(struct b43_wldev *dev)
{
}

__attribute__((used)) static inline void b43_leds_stop(struct b43_wldev *dev)
{
}

__attribute__((used)) static inline bool b43_bus_host_is_pcmcia(struct b43_bus_dev *dev)
{
#ifdef CONFIG_B43_SSB
	return (dev->bus_type == B43_BUS_SSB &&
		dev->sdev->bus->bustype == SSB_BUSTYPE_PCMCIA);
#else
	return false;
#endif
}

__attribute__((used)) static inline bool b43_bus_host_is_pci(struct b43_bus_dev *dev)
{
#ifdef CONFIG_B43_BCMA
	if (dev->bus_type == B43_BUS_BCMA)
		return (dev->bdev->bus->hosttype == BCMA_HOSTTYPE_PCI);
#endif
#ifdef CONFIG_B43_SSB
	if (dev->bus_type == B43_BUS_SSB)
		return (dev->sdev->bus->bustype == SSB_BUSTYPE_PCI);
#endif
	return false;
}

__attribute__((used)) static inline bool b43_bus_host_is_sdio(struct b43_bus_dev *dev)
{
#ifdef CONFIG_B43_SSB
	return (dev->bus_type == B43_BUS_SSB &&
		dev->sdev->bus->bustype == SSB_BUSTYPE_SDIO);
#else
	return false;
#endif
}

__attribute__((used)) static inline bool b43_compare_rfatt(const struct b43_rfatt *a,
				     const struct b43_rfatt *b)
{
	return ((a->att == b->att) &&
		(a->with_padmix == b->with_padmix));
}

__attribute__((used)) static inline bool b43_compare_bbatt(const struct b43_bbatt *a,
				     const struct b43_bbatt *b)
{
	return (a->att == b->att);
}

__attribute__((used)) static inline struct b43_wl *hw_to_b43_wl(struct ieee80211_hw *hw)
{
	return hw->priv;
}

__attribute__((used)) static inline struct b43_wldev *dev_to_b43_wldev(struct device *dev)
{
	struct ssb_device *ssb_dev = dev_to_ssb_dev(dev);
	return ssb_get_drvdata(ssb_dev);
}

__attribute__((used)) static inline int b43_is_mode(struct b43_wl *wl, int type)
{
	return (wl->operating && wl->if_type == type);
}

__attribute__((used)) static inline enum nl80211_band b43_current_band(struct b43_wl *wl)
{
	return wl->hw->conf.chandef.chan->band;
}

__attribute__((used)) static inline int b43_bus_may_powerdown(struct b43_wldev *wldev)
{
	return wldev->dev->bus_may_powerdown(wldev->dev);
}

__attribute__((used)) static inline int b43_bus_powerup(struct b43_wldev *wldev, bool dynamic_pctl)
{
	return wldev->dev->bus_powerup(wldev->dev, dynamic_pctl);
}

__attribute__((used)) static inline int b43_device_is_enabled(struct b43_wldev *wldev)
{
	return wldev->dev->device_is_enabled(wldev->dev);
}

__attribute__((used)) static inline void b43_device_enable(struct b43_wldev *wldev,
				     u32 core_specific_flags)
{
	wldev->dev->device_enable(wldev->dev, core_specific_flags);
}

__attribute__((used)) static inline void b43_device_disable(struct b43_wldev *wldev,
				      u32 core_specific_flags)
{
	wldev->dev->device_disable(wldev->dev, core_specific_flags);
}

__attribute__((used)) static inline u16 b43_read16(struct b43_wldev *dev, u16 offset)
{
	return dev->dev->read16(dev->dev, offset);
}

__attribute__((used)) static inline void b43_write16(struct b43_wldev *dev, u16 offset, u16 value)
{
	dev->dev->write16(dev->dev, offset, value);
}

__attribute__((used)) static inline void b43_write16f(struct b43_wldev *dev, u16 offset, u16 value)
{
	b43_write16(dev, offset, value);
#if defined(CONFIG_BCM47XX_BCMA)
	if (dev->dev->flush_writes)
		b43_read16(dev, offset);
#endif
}

__attribute__((used)) static inline void b43_maskset16(struct b43_wldev *dev, u16 offset, u16 mask,
				 u16 set)
{
	b43_write16(dev, offset, (b43_read16(dev, offset) & mask) | set);
}

__attribute__((used)) static inline u32 b43_read32(struct b43_wldev *dev, u16 offset)
{
	return dev->dev->read32(dev->dev, offset);
}

__attribute__((used)) static inline void b43_write32(struct b43_wldev *dev, u16 offset, u32 value)
{
	dev->dev->write32(dev->dev, offset, value);
}

__attribute__((used)) static inline void b43_maskset32(struct b43_wldev *dev, u16 offset, u32 mask,
				 u32 set)
{
	b43_write32(dev, offset, (b43_read32(dev, offset) & mask) | set);
}

__attribute__((used)) static inline void b43_block_read(struct b43_wldev *dev, void *buffer,
				 size_t count, u16 offset, u8 reg_width)
{
	dev->dev->block_read(dev->dev, buffer, count, offset, reg_width);
}

__attribute__((used)) static inline void b43_block_write(struct b43_wldev *dev, const void *buffer,
				   size_t count, u16 offset, u8 reg_width)
{
	dev->dev->block_write(dev->dev, buffer, count, offset, reg_width);
}

__attribute__((used)) static inline bool b43_using_pio_transfers(struct b43_wldev *dev)
{
	return dev->__using_pio_transfers;
}

__attribute__((used)) static inline bool __b43_warn_on_dummy(bool x) { return x; }

void b2055_upload_inittab(struct b43_wldev *dev,
			  bool ghz5, bool ignore_uploadflag)
{
	const struct b2055_inittab_entry *e;
	unsigned int i, writes = 0;
	u16 value;

	for (i = 0; i < ARRAY_SIZE(b2055_inittab); i++) {
		e = &(b2055_inittab[i]);
		if (!(e->flags & B2055_INITTAB_ENTRY_OK))
			continue;
		if ((e->flags & B2055_INITTAB_UPLOAD) || ignore_uploadflag) {
			if (ghz5)
				value = e->ghz5;
			else
				value = e->ghz2;
			b43_radio_write16(dev, i, value);
			if (++writes % 4 == 0)
				b43_read32(dev, B43_MMIO_MACCTL); /* flush */
		}
	}
}

const struct b43_nphy_channeltab_entry_rev2 *
b43_nphy_get_chantabent_rev2(struct b43_wldev *dev, u8 channel)
{
	const struct b43_nphy_channeltab_entry_rev2 *e;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(b43_nphy_channeltab_rev2); i++) {
		e = &(b43_nphy_channeltab_rev2[i]);
		if (e->channel == channel)
			return e;
	}

	return NULL;
}

