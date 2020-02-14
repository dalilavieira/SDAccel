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
struct ieee80211_hw {struct b43_wl* priv; } ;
struct device {int dummy; } ;
struct TYPE_17__ {struct b43_phy_g* g; } ;
struct b43_wldev {int __using_pio_transfers; TYPE_1__ phy; TYPE_6__* dev; } ;
struct b43_wl {int if_type; TYPE_5__* hw; scalar_t__ operating; } ;
struct b43_txstatus {int dummy; } ;
struct b43_rfatt {scalar_t__ att; scalar_t__ with_padmix; } ;
struct b43_phy_g {scalar_t__ ofdmtab_addr_direction; int ofdmtab_addr; } ;
struct b43_bus_dev {int dummy; } ;
struct b43_bbatt {scalar_t__ att; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum b43_dyndbg { ____Placeholder_b43_dyndbg } b43_dyndbg ;
struct TYPE_22__ {int (* bus_may_powerdown ) (TYPE_6__*) ;int (* bus_powerup ) (TYPE_6__*,int) ;int (* device_is_enabled ) (TYPE_6__*) ;int (* read16 ) (TYPE_6__*,int) ;int (* read32 ) (TYPE_6__*,int) ;int /*<<< orphan*/  (* block_write ) (TYPE_6__*,void const*,size_t,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* block_read ) (TYPE_6__*,void*,size_t,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* write32 ) (TYPE_6__*,int,int) ;int /*<<< orphan*/  (* write16 ) (TYPE_6__*,int,int) ;int /*<<< orphan*/  (* device_disable ) (TYPE_6__*,int) ;int /*<<< orphan*/  (* device_enable ) (TYPE_6__*,int) ;} ;
struct TYPE_19__ {TYPE_2__* chan; } ;
struct TYPE_20__ {TYPE_3__ chandef; } ;
struct TYPE_21__ {TYPE_4__ conf; } ;
struct TYPE_18__ {int band; } ;

/* Variables and functions */
 scalar_t__ ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 scalar_t__ B43_OFDMTAB_DIRECTION_READ ; 
 scalar_t__ B43_OFDMTAB_DIRECTION_WRITE ; 
 int /*<<< orphan*/  B43_PHY_GTABCTL ; 
 int /*<<< orphan*/  B43_PHY_GTABDATA ; 
 int /*<<< orphan*/  B43_PHY_OTABLECTL ; 
 int /*<<< orphan*/  B43_PHY_OTABLEI ; 
 int /*<<< orphan*/  B43_PHY_OTABLEQ ; 
 scalar_t__ B43_TAB_FINEFREQA_SIZE ; 
 scalar_t__ B43_TAB_FINEFREQG_SIZE ; 
 scalar_t__ B43_TAB_NOISEA2_SIZE ; 
 scalar_t__ B43_TAB_NOISEA3_SIZE ; 
 scalar_t__ B43_TAB_NOISEG1_SIZE ; 
 scalar_t__ B43_TAB_NOISEG2_SIZE ; 
 scalar_t__ B43_TAB_NOISESCALE_SIZE ; 
 scalar_t__ B43_TAB_RETARD_SIZE ; 
 scalar_t__ B43_TAB_ROTOR_SIZE ; 
 scalar_t__ B43_TAB_RSSIAGC1_SIZE ; 
 scalar_t__ B43_TAB_RSSIAGC2_SIZE ; 
 scalar_t__ B43_TAB_SIGMASQR_SIZE ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int b43_phy_read (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_phy_write (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43_tab_finefreqa ; 
 int /*<<< orphan*/  b43_tab_finefreqg ; 
 int /*<<< orphan*/  b43_tab_noisea2 ; 
 int /*<<< orphan*/  b43_tab_noisea3 ; 
 int /*<<< orphan*/  b43_tab_noiseg1 ; 
 int /*<<< orphan*/  b43_tab_noiseg2 ; 
 int /*<<< orphan*/  b43_tab_noisescalea2 ; 
 int /*<<< orphan*/  b43_tab_noisescalea3 ; 
 int /*<<< orphan*/  b43_tab_noisescaleg1 ; 
 int /*<<< orphan*/  b43_tab_noisescaleg2 ; 
 int /*<<< orphan*/  b43_tab_noisescaleg3 ; 
 int /*<<< orphan*/  b43_tab_retard ; 
 int /*<<< orphan*/  b43_tab_rotor ; 
 int /*<<< orphan*/  b43_tab_rssiagc1 ; 
 int /*<<< orphan*/  b43_tab_rssiagc2 ; 
 int /*<<< orphan*/  b43_tab_sigmasqr1 ; 
 int /*<<< orphan*/  b43_tab_sigmasqr2 ; 
 struct ssb_device* dev_to_ssb_dev (struct device*) ; 
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

__attribute__((used)) static inline void assert_sizes(void)
{
	BUILD_BUG_ON(B43_TAB_ROTOR_SIZE != ARRAY_SIZE(b43_tab_rotor));
	BUILD_BUG_ON(B43_TAB_RETARD_SIZE != ARRAY_SIZE(b43_tab_retard));
	BUILD_BUG_ON(B43_TAB_FINEFREQA_SIZE != ARRAY_SIZE(b43_tab_finefreqa));
	BUILD_BUG_ON(B43_TAB_FINEFREQG_SIZE != ARRAY_SIZE(b43_tab_finefreqg));
	BUILD_BUG_ON(B43_TAB_NOISEA2_SIZE != ARRAY_SIZE(b43_tab_noisea2));
	BUILD_BUG_ON(B43_TAB_NOISEA3_SIZE != ARRAY_SIZE(b43_tab_noisea3));
	BUILD_BUG_ON(B43_TAB_NOISEG1_SIZE != ARRAY_SIZE(b43_tab_noiseg1));
	BUILD_BUG_ON(B43_TAB_NOISEG2_SIZE != ARRAY_SIZE(b43_tab_noiseg2));
	BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
		     ARRAY_SIZE(b43_tab_noisescalea2));
	BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
		     ARRAY_SIZE(b43_tab_noisescalea3));
	BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
		     ARRAY_SIZE(b43_tab_noisescaleg1));
	BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
		     ARRAY_SIZE(b43_tab_noisescaleg2));
	BUILD_BUG_ON(B43_TAB_NOISESCALE_SIZE !=
		     ARRAY_SIZE(b43_tab_noisescaleg3));
	BUILD_BUG_ON(B43_TAB_SIGMASQR_SIZE != ARRAY_SIZE(b43_tab_sigmasqr1));
	BUILD_BUG_ON(B43_TAB_SIGMASQR_SIZE != ARRAY_SIZE(b43_tab_sigmasqr2));
	BUILD_BUG_ON(B43_TAB_RSSIAGC1_SIZE != ARRAY_SIZE(b43_tab_rssiagc1));
	BUILD_BUG_ON(B43_TAB_RSSIAGC2_SIZE != ARRAY_SIZE(b43_tab_rssiagc2));
}

u16 b43_ofdmtab_read16(struct b43_wldev *dev, u16 table, u16 offset)
{
	struct b43_phy_g *gphy = dev->phy.g;
	u16 addr;

	addr = table + offset;
	if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_READ) ||
	    (addr - 1 != gphy->ofdmtab_addr)) {
		/* The hardware has a different address in memory. Update it. */
		b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
		gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_READ;
	}
	gphy->ofdmtab_addr = addr;

	return b43_phy_read(dev, B43_PHY_OTABLEI);

	/* Some compiletime assertions... */
	assert_sizes();
}

void b43_ofdmtab_write16(struct b43_wldev *dev, u16 table,
			 u16 offset, u16 value)
{
	struct b43_phy_g *gphy = dev->phy.g;
	u16 addr;

	addr = table + offset;
	if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_WRITE) ||
	    (addr - 1 != gphy->ofdmtab_addr)) {
		/* The hardware has a different address in memory. Update it. */
		b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
		gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_WRITE;
	}
	gphy->ofdmtab_addr = addr;
	b43_phy_write(dev, B43_PHY_OTABLEI, value);
}

u32 b43_ofdmtab_read32(struct b43_wldev *dev, u16 table, u16 offset)
{
	struct b43_phy_g *gphy = dev->phy.g;
	u32 ret;
	u16 addr;

	addr = table + offset;
	if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_READ) ||
	    (addr - 1 != gphy->ofdmtab_addr)) {
		/* The hardware has a different address in memory. Update it. */
		b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
		gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_READ;
	}
	gphy->ofdmtab_addr = addr;
	ret = b43_phy_read(dev, B43_PHY_OTABLEQ);
	ret <<= 16;
	ret |= b43_phy_read(dev, B43_PHY_OTABLEI);

	return ret;
}

void b43_ofdmtab_write32(struct b43_wldev *dev, u16 table,
			 u16 offset, u32 value)
{
	struct b43_phy_g *gphy = dev->phy.g;
	u16 addr;

	addr = table + offset;
	if ((gphy->ofdmtab_addr_direction != B43_OFDMTAB_DIRECTION_WRITE) ||
	    (addr - 1 != gphy->ofdmtab_addr)) {
		/* The hardware has a different address in memory. Update it. */
		b43_phy_write(dev, B43_PHY_OTABLECTL, addr);
		gphy->ofdmtab_addr_direction = B43_OFDMTAB_DIRECTION_WRITE;
	}
	gphy->ofdmtab_addr = addr;

	b43_phy_write(dev, B43_PHY_OTABLEI, value);
	b43_phy_write(dev, B43_PHY_OTABLEQ, (value >> 16));
}

u16 b43_gtab_read(struct b43_wldev *dev, u16 table, u16 offset)
{
	b43_phy_write(dev, B43_PHY_GTABCTL, table + offset);
	return b43_phy_read(dev, B43_PHY_GTABDATA);
}

void b43_gtab_write(struct b43_wldev *dev, u16 table, u16 offset, u16 value)
{
	b43_phy_write(dev, B43_PHY_GTABCTL, table + offset);
	b43_phy_write(dev, B43_PHY_GTABDATA, value);
}

