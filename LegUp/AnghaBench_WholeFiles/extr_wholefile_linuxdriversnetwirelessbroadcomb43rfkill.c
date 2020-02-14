#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_6__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct ssb_device {int dummy; } ;
struct ieee80211_hw {int /*<<< orphan*/  wiphy; struct b43_wl* priv; } ;
struct device {int dummy; } ;
struct TYPE_21__ {int radio_on; } ;
struct b43_wldev {int __using_pio_transfers; int radio_hw_enable; TYPE_5__ phy; TYPE_6__* dev; } ;
struct b43_wl {int if_type; int /*<<< orphan*/  mutex; struct b43_wldev* current_dev; TYPE_4__* hw; scalar_t__ operating; } ;
struct b43_txstatus {int dummy; } ;
struct b43_rfatt {scalar_t__ att; scalar_t__ with_padmix; } ;
struct b43_bus_dev {int dummy; } ;
struct b43_bbatt {scalar_t__ att; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum b43_dyndbg { ____Placeholder_b43_dyndbg } b43_dyndbg ;
struct TYPE_22__ {int (* bus_may_powerdown ) (TYPE_6__*) ;int (* bus_powerup ) (TYPE_6__*,int) ;int (* device_is_enabled ) (TYPE_6__*) ;int (* read16 ) (TYPE_6__*,int) ;int (* read32 ) (TYPE_6__*,int) ;int /*<<< orphan*/  (* block_write ) (TYPE_6__*,void const*,size_t,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* block_read ) (TYPE_6__*,void*,size_t,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* write32 ) (TYPE_6__*,int,int) ;int /*<<< orphan*/  (* write16 ) (TYPE_6__*,int,int) ;int /*<<< orphan*/  (* device_disable ) (TYPE_6__*,int) ;int /*<<< orphan*/  (* device_enable ) (TYPE_6__*,int) ;} ;
struct TYPE_18__ {TYPE_1__* chan; } ;
struct TYPE_19__ {TYPE_2__ chandef; } ;
struct TYPE_20__ {TYPE_3__ conf; } ;
struct TYPE_17__ {int band; } ;

/* Variables and functions */
 int B43_MMIO_RADIO_HWENABLED_HI ; 
 int B43_MMIO_RADIO_HWENABLED_HI_MASK ; 
 scalar_t__ B43_STAT_INITIALIZED ; 
 int /*<<< orphan*/  b43_software_rfkill (struct b43_wldev*,int) ; 
 scalar_t__ b43_status (struct b43_wldev*) ; 
 int /*<<< orphan*/  b43info (struct b43_wl*,char*,char*) ; 
 struct ssb_device* dev_to_ssb_dev (struct device*) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct b43_wldev* ssb_get_drvdata (struct ssb_device*) ; 
 int stub1 (TYPE_6__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_6__*,void*,size_t,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (TYPE_6__*,void const*,size_t,int,int /*<<< orphan*/ ) ; 
 int stub2 (TYPE_6__*,int) ; 
 int stub3 (TYPE_6__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_6__*,int) ; 
 int /*<<< orphan*/  stub5 (TYPE_6__*,int) ; 
 int stub6 (TYPE_6__*,int) ; 
 int /*<<< orphan*/  stub7 (TYPE_6__*,int,int) ; 
 int stub8 (TYPE_6__*,int) ; 
 int /*<<< orphan*/  stub9 (TYPE_6__*,int,int) ; 
 scalar_t__ unlikely (int) ; 
 int /*<<< orphan*/  wiphy_rfkill_set_hw_state (int /*<<< orphan*/ ,int) ; 

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

bool b43_is_hw_radio_enabled(struct b43_wldev *dev)
{
	return !(b43_read32(dev, B43_MMIO_RADIO_HWENABLED_HI)
		& B43_MMIO_RADIO_HWENABLED_HI_MASK);
}

void b43_rfkill_poll(struct ieee80211_hw *hw)
{
	struct b43_wl *wl = hw_to_b43_wl(hw);
	struct b43_wldev *dev = wl->current_dev;
	bool enabled;
	bool brought_up = false;

	mutex_lock(&wl->mutex);
	if (unlikely(b43_status(dev) < B43_STAT_INITIALIZED)) {
		if (b43_bus_powerup(dev, 0)) {
			mutex_unlock(&wl->mutex);
			return;
		}
		b43_device_enable(dev, 0);
		brought_up = true;
	}

	enabled = b43_is_hw_radio_enabled(dev);

	if (unlikely(enabled != dev->radio_hw_enable)) {
		dev->radio_hw_enable = enabled;
		b43info(wl, "Radio hardware status changed to %s\n",
			enabled ? "ENABLED" : "DISABLED");
		wiphy_rfkill_set_hw_state(hw->wiphy, !enabled);
		if (enabled != dev->phy.radio_on)
			b43_software_rfkill(dev, !enabled);
	}

	if (brought_up) {
		b43_device_disable(dev, 0);
		b43_bus_may_powerdown(dev);
	}

	mutex_unlock(&wl->mutex);
}

