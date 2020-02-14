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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct ssb_sprom {int boardflags_lo; int boardflags_hi; } ;
struct ssb_device {int dummy; } ;
struct ieee80211_hw {struct b43_wl* priv; } ;
struct device {int dummy; } ;
struct b43_wldev {int __using_pio_transfers; struct b43_wl* wl; TYPE_5__* dev; } ;
struct b43_wl {int if_type; TYPE_4__* hw; scalar_t__ operating; } ;
struct b43_txstatus {int dummy; } ;
struct b43_rfatt {scalar_t__ att; scalar_t__ with_padmix; } ;
struct b43_lcntab_tx_gain_tbl_entry {int pad; int pga; int gm; int dac; int bb_mult; } ;
struct b43_bus_dev {int dummy; } ;
struct b43_bbatt {scalar_t__ att; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum b43_dyndbg { ____Placeholder_b43_dyndbg } b43_dyndbg ;
struct TYPE_20__ {int (* bus_may_powerdown ) (TYPE_5__*) ;int (* bus_powerup ) (TYPE_5__*,int) ;int (* device_is_enabled ) (TYPE_5__*) ;int (* read16 ) (TYPE_5__*,int) ;int (* read32 ) (TYPE_5__*,int) ;struct ssb_sprom* bus_sprom; int /*<<< orphan*/  (* block_write ) (TYPE_5__*,void const*,size_t,int,int) ;int /*<<< orphan*/  (* block_read ) (TYPE_5__*,void*,size_t,int,int) ;int /*<<< orphan*/  (* write32 ) (TYPE_5__*,int,int) ;int /*<<< orphan*/  (* write16 ) (TYPE_5__*,int,int) ;int /*<<< orphan*/  (* device_disable ) (TYPE_5__*,int) ;int /*<<< orphan*/  (* device_enable ) (TYPE_5__*,int) ;} ;
struct TYPE_17__ {TYPE_1__* chan; } ;
struct TYPE_18__ {TYPE_2__ chandef; } ;
struct TYPE_19__ {TYPE_3__ conf; } ;
struct TYPE_16__ {int band; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (void*) ; 
 int B43_BFH_FEM_BT ; 
 int B43_BFL_FEM ; 
 int B43_LCNTAB16 (int,int /*<<< orphan*/ ) ; 
 int B43_LCNTAB32 (int,int) ; 
#define  B43_LCNTAB_16BIT 130 
#define  B43_LCNTAB_32BIT 129 
#define  B43_LCNTAB_8BIT 128 
 int B43_LCNTAB_TX_GAIN_SIZE ; 
 int B43_LCNTAB_TYPEMASK ; 
 int /*<<< orphan*/  B43_PHY_LCN_TABLE_ADDR ; 
 int /*<<< orphan*/  B43_PHY_LCN_TABLE_DATAHI ; 
 int /*<<< orphan*/  B43_PHY_LCN_TABLE_DATALO ; 
 int /*<<< orphan*/  B43_WARN_ON (int) ; 
 scalar_t__ NL80211_BAND_2GHZ ; 
 int /*<<< orphan*/  b43_lcntab_0x00 ; 
 int /*<<< orphan*/  b43_lcntab_0x01 ; 
 int /*<<< orphan*/  b43_lcntab_0x02 ; 
 int /*<<< orphan*/  b43_lcntab_0x0b ; 
 int /*<<< orphan*/  b43_lcntab_0x0c ; 
 int /*<<< orphan*/  b43_lcntab_0x0d ; 
 int /*<<< orphan*/  b43_lcntab_0x0e ; 
 int /*<<< orphan*/  b43_lcntab_0x0f ; 
 int /*<<< orphan*/  b43_lcntab_0x10 ; 
 int /*<<< orphan*/  b43_lcntab_0x11 ; 
 int /*<<< orphan*/  b43_lcntab_0x12 ; 
 int /*<<< orphan*/  b43_lcntab_0x14 ; 
 int /*<<< orphan*/  b43_lcntab_0x17 ; 
 int /*<<< orphan*/  b43_lcntab_0x18 ; 
 void* b43_lcntab_sw_ctl_4313_epa_rev0 ; 
 struct b43_lcntab_tx_gain_tbl_entry* b43_lcntab_tx_gain_tbl_2ghz_ext_pa_rev0 ; 
 int b43_phy_read (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_phy_write (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43err (struct b43_wl*,char*) ; 
 struct ssb_device* dev_to_ssb_dev (struct device*) ; 
 int /*<<< orphan*/  lcntab_upload (struct b43_wldev*,int,int /*<<< orphan*/ ) ; 
 struct b43_wldev* ssb_get_drvdata (struct ssb_device*) ; 
 int stub1 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_5__*,void*,size_t,int,int) ; 
 int /*<<< orphan*/  stub11 (TYPE_5__*,void const*,size_t,int,int) ; 
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

u32 b43_lcntab_read(struct b43_wldev *dev, u32 offset)
{
	u32 type, value;

	type = offset & B43_LCNTAB_TYPEMASK;
	offset &= ~B43_LCNTAB_TYPEMASK;
	B43_WARN_ON(offset > 0xFFFF);

	switch (type) {
	case B43_LCNTAB_8BIT:
		b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
		value = b43_phy_read(dev, B43_PHY_LCN_TABLE_DATALO) & 0xFF;
		break;
	case B43_LCNTAB_16BIT:
		b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
		value = b43_phy_read(dev, B43_PHY_LCN_TABLE_DATALO);
		break;
	case B43_LCNTAB_32BIT:
		b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
		value = b43_phy_read(dev, B43_PHY_LCN_TABLE_DATALO);
		value |= (b43_phy_read(dev, B43_PHY_LCN_TABLE_DATAHI) << 16);
		break;
	default:
		B43_WARN_ON(1);
		value = 0;
	}

	return value;
}

void b43_lcntab_read_bulk(struct b43_wldev *dev, u32 offset,
			  unsigned int nr_elements, void *_data)
{
	u32 type;
	u8 *data = _data;
	unsigned int i;

	type = offset & B43_LCNTAB_TYPEMASK;
	offset &= ~B43_LCNTAB_TYPEMASK;
	B43_WARN_ON(offset > 0xFFFF);

	b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);

	for (i = 0; i < nr_elements; i++) {
		switch (type) {
		case B43_LCNTAB_8BIT:
			*data = b43_phy_read(dev,
					     B43_PHY_LCN_TABLE_DATALO) & 0xFF;
			data++;
			break;
		case B43_LCNTAB_16BIT:
			*((u16 *)data) = b43_phy_read(dev,
						      B43_PHY_LCN_TABLE_DATALO);
			data += 2;
			break;
		case B43_LCNTAB_32BIT:
			*((u32 *)data) = b43_phy_read(dev,
						B43_PHY_LCN_TABLE_DATALO);
			*((u32 *)data) |= (b43_phy_read(dev,
					   B43_PHY_LCN_TABLE_DATAHI) << 16);
			data += 4;
			break;
		default:
			B43_WARN_ON(1);
		}
	}
}

void b43_lcntab_write(struct b43_wldev *dev, u32 offset, u32 value)
{
	u32 type;

	type = offset & B43_LCNTAB_TYPEMASK;
	offset &= 0xFFFF;

	switch (type) {
	case B43_LCNTAB_8BIT:
		B43_WARN_ON(value & ~0xFF);
		b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
		b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
		break;
	case B43_LCNTAB_16BIT:
		B43_WARN_ON(value & ~0xFFFF);
		b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
		b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
		break;
	case B43_LCNTAB_32BIT:
		b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
		b43_phy_write(dev, B43_PHY_LCN_TABLE_DATAHI, value >> 16);
		b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value & 0xFFFF);
		break;
	default:
		B43_WARN_ON(1);
	}

	return;
}

void b43_lcntab_write_bulk(struct b43_wldev *dev, u32 offset,
			   unsigned int nr_elements, const void *_data)
{
	u32 type, value;
	const u8 *data = _data;
	unsigned int i;

	type = offset & B43_LCNTAB_TYPEMASK;
	offset &= ~B43_LCNTAB_TYPEMASK;
	B43_WARN_ON(offset > 0xFFFF);

	b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);

	for (i = 0; i < nr_elements; i++) {
		switch (type) {
		case B43_LCNTAB_8BIT:
			value = *data;
			data++;
			B43_WARN_ON(value & ~0xFF);
			b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
			break;
		case B43_LCNTAB_16BIT:
			value = *((u16 *)data);
			data += 2;
			B43_WARN_ON(value & ~0xFFFF);
			b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
			break;
		case B43_LCNTAB_32BIT:
			value = *((u32 *)data);
			data += 4;
			b43_phy_write(dev, B43_PHY_LCN_TABLE_DATAHI,
				      value >> 16);
			b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO,
				      value & 0xFFFF);
			break;
		default:
			B43_WARN_ON(1);
		}
	}
}

__attribute__((used)) static void b43_phy_lcn_upload_static_tables(struct b43_wldev *dev)
{
	lcntab_upload(dev, B43_LCNTAB16(0x02, 0), b43_lcntab_0x02);
	lcntab_upload(dev, B43_LCNTAB16(0x01, 0), b43_lcntab_0x01);
	lcntab_upload(dev, B43_LCNTAB32(0x0b, 0), b43_lcntab_0x0b);
	lcntab_upload(dev, B43_LCNTAB32(0x0c, 0), b43_lcntab_0x0c);
	lcntab_upload(dev, B43_LCNTAB32(0x0d, 0), b43_lcntab_0x0d);
	lcntab_upload(dev, B43_LCNTAB16(0x0e, 0), b43_lcntab_0x0e);
	lcntab_upload(dev, B43_LCNTAB16(0x0f, 0), b43_lcntab_0x0f);
	lcntab_upload(dev, B43_LCNTAB16(0x10, 0), b43_lcntab_0x10);
	lcntab_upload(dev, B43_LCNTAB16(0x11, 0), b43_lcntab_0x11);
	lcntab_upload(dev, B43_LCNTAB32(0x12, 0), b43_lcntab_0x12);
	lcntab_upload(dev, B43_LCNTAB16(0x14, 0), b43_lcntab_0x14);
	lcntab_upload(dev, B43_LCNTAB16(0x17, 0), b43_lcntab_0x17);
	lcntab_upload(dev, B43_LCNTAB16(0x00, 0), b43_lcntab_0x00);
	lcntab_upload(dev, B43_LCNTAB32(0x18, 0), b43_lcntab_0x18);
}

__attribute__((used)) static void b43_phy_lcn_load_tx_gain_tab(struct b43_wldev *dev,
			const struct b43_lcntab_tx_gain_tbl_entry *gain_table)
{
	u32 i;
	u32 val;

	u16 pa_gain = 0x70;
	if (dev->dev->bus_sprom->boardflags_lo & B43_BFL_FEM)
		pa_gain = 0x10;

	for (i = 0; i < B43_LCNTAB_TX_GAIN_SIZE; i++) {
		val = ((pa_gain << 24) |
		       (gain_table[i].pad << 16) |
		       (gain_table[i].pga << 8) |
			gain_table[i].gm);
		b43_lcntab_write(dev, B43_LCNTAB32(0x7, 0xc0 + i), val);

		/* brcmsmac doesn't maskset, we follow newer wl here */
		val = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0x140 + i));
		val &= 0x000fffff;
		val |= ((gain_table[i].dac << 28) |
			(gain_table[i].bb_mult << 20));
		b43_lcntab_write(dev, B43_LCNTAB32(0x7, 0x140 + i), val);
	}
}

__attribute__((used)) static void b43_phy_lcn_load_rfpower(struct b43_wldev *dev)
{
	u32 bbmult, rfgain;
	u8 i;

	for (i = 0; i < 128; i++) {
		bbmult = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0x140 + i));
		bbmult >>= 20;
		rfgain = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0xc0 + i));

		/* TODO: calculate value for 0x240 + i table offset
		 * b43_lcntab_write(dev, B43_LCNTAB32(0x7, 0x240 + i), val);
		 */
	}
}

__attribute__((used)) static void b43_phy_lcn_rewrite_rfpower_table(struct b43_wldev *dev)
{
	int i;
	u32 tmp;
	for (i = 0; i < 128; i++) {
		tmp = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0x240 + i));
		b43_lcntab_write(dev, B43_LCNTAB32(0x7, 0x240 + i), tmp);
	}
}

__attribute__((used)) static void b43_phy_lcn_clean_papd_comp_table(struct b43_wldev *dev)
{
	u8 i;

	for (i = 0; i < 0x80; i++)
		b43_lcntab_write(dev, B43_LCNTAB32(0x18, i), 0x80000);
}

void b43_phy_lcn_tables_init(struct b43_wldev *dev)
{
	struct ssb_sprom *sprom = dev->dev->bus_sprom;

	b43_phy_lcn_upload_static_tables(dev);

	if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ) {
		if (sprom->boardflags_lo & B43_BFL_FEM)
			b43_phy_lcn_load_tx_gain_tab(dev,
				b43_lcntab_tx_gain_tbl_2ghz_ext_pa_rev0);
		else
			b43err(dev->wl,
			       "TX gain table unknown for this card\n");
	}

	if (sprom->boardflags_lo & B43_BFL_FEM &&
	    !(sprom->boardflags_hi & B43_BFH_FEM_BT))
		b43_lcntab_write_bulk(dev, B43_LCNTAB16(0xf, 0),
			ARRAY_SIZE(b43_lcntab_sw_ctl_4313_epa_rev0),
			b43_lcntab_sw_ctl_4313_epa_rev0);
	else
		b43err(dev->wl, "SW ctl table is unknown for this card\n");

	b43_phy_lcn_load_rfpower(dev);
	b43_phy_lcn_rewrite_rfpower_table(dev);
	b43_phy_lcn_clean_papd_comp_table(dev);
}

