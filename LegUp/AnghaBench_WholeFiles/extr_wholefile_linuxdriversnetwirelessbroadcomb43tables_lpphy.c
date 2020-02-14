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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct ssb_sprom {int boardflags_hi; int boardflags_lo; } ;
struct ssb_device {int dummy; } ;
struct lpphy_tx_gain_table_entry {int pad; int pga; int gm; int dac; int bb_mult; } ;
struct ieee80211_hw {struct b43_wl* priv; } ;
struct device {int dummy; } ;
struct TYPE_21__ {int rev; } ;
struct b43_wldev {int __using_pio_transfers; struct b43_wl* wl; TYPE_5__ phy; TYPE_6__* dev; } ;
struct b43_wl {int if_type; TYPE_4__* hw; scalar_t__ operating; } ;
struct b43_txstatus {int dummy; } ;
struct b43_rfatt {scalar_t__ att; scalar_t__ with_padmix; } ;
struct b43_bus_dev {int dummy; } ;
struct b43_bbatt {scalar_t__ att; } ;
struct b206x_init_tab_entry {int flags; int /*<<< orphan*/  value_a; int /*<<< orphan*/  offset; int /*<<< orphan*/  value_g; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum b43_dyndbg { ____Placeholder_b43_dyndbg } b43_dyndbg ;
struct TYPE_22__ {int (* bus_may_powerdown ) (TYPE_6__*) ;int (* bus_powerup ) (TYPE_6__*,int) ;int (* device_is_enabled ) (TYPE_6__*) ;int (* read16 ) (TYPE_6__*,int) ;int (* read32 ) (TYPE_6__*,int) ;int chip_id; scalar_t__ chip_rev; struct ssb_sprom* bus_sprom; int /*<<< orphan*/  (* block_write ) (TYPE_6__*,void const*,size_t,int,int) ;int /*<<< orphan*/  (* block_read ) (TYPE_6__*,void*,size_t,int,int) ;int /*<<< orphan*/  (* write32 ) (TYPE_6__*,int,int) ;int /*<<< orphan*/  (* write16 ) (TYPE_6__*,int,int) ;int /*<<< orphan*/  (* device_disable ) (TYPE_6__*,int) ;int /*<<< orphan*/  (* device_enable ) (TYPE_6__*,int) ;} ;
struct TYPE_18__ {TYPE_1__* chan; } ;
struct TYPE_19__ {TYPE_2__ chandef; } ;
struct TYPE_20__ {TYPE_3__ conf; } ;
struct TYPE_17__ {int band; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct b206x_init_tab_entry*) ; 
 int B206X_FLAG_A ; 
 int B206X_FLAG_G ; 
 int B43_BFH_NOPA ; 
 int B43_BFL_HGPA ; 
 int /*<<< orphan*/  B43_LPPHY_TABLEDATAHI ; 
 int /*<<< orphan*/  B43_LPPHY_TABLEDATALO ; 
 int /*<<< orphan*/  B43_LPPHY_TABLE_ADDR ; 
 int B43_LPTAB16 (int,int /*<<< orphan*/ ) ; 
 int B43_LPTAB32 (int,int) ; 
 int B43_LPTAB8 (int,int /*<<< orphan*/ ) ; 
#define  B43_LPTAB_16BIT 130 
#define  B43_LPTAB_32BIT 129 
#define  B43_LPTAB_8BIT 128 
 int B43_LPTAB_TYPEMASK ; 
 int /*<<< orphan*/  B43_WARN_ON (int) ; 
 scalar_t__ NL80211_BAND_2GHZ ; 
 scalar_t__ NL80211_BAND_5GHZ ; 
 struct b206x_init_tab_entry* b2062_init_tab ; 
 struct b206x_init_tab_entry* b2063_init_tab ; 
 int b43_phy_read (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_phy_write (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43_radio_write (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct ssb_device* dev_to_ssb_dev (struct device*) ; 
 struct b206x_init_tab_entry* lpphy_a0_aux_gain_idx_table ; 
 struct b206x_init_tab_entry* lpphy_a0_gain_idx_table ; 
 struct b206x_init_tab_entry* lpphy_a0_gain_table ; 
 struct b206x_init_tab_entry* lpphy_a0_gain_value_table ; 
 struct b206x_init_tab_entry* lpphy_aux_gain_idx_table ; 
 struct b206x_init_tab_entry* lpphy_crs_gain_nft_table ; 
 struct b206x_init_tab_entry* lpphy_gain_delta_table ; 
 struct b206x_init_tab_entry* lpphy_gain_idx_table ; 
 struct b206x_init_tab_entry* lpphy_gain_table ; 
 struct b206x_init_tab_entry* lpphy_gain_value_table ; 
 struct b206x_init_tab_entry* lpphy_hf_table ; 
 struct b206x_init_tab_entry* lpphy_iqlo_cal_table ; 
 struct b206x_init_tab_entry* lpphy_min_sig_sq_table ; 
 struct b206x_init_tab_entry* lpphy_papd_eps_table ; 
 struct b206x_init_tab_entry* lpphy_papd_mult_table ; 
 struct b206x_init_tab_entry* lpphy_pll_fraction_table ; 
 struct b206x_init_tab_entry* lpphy_rev01_filter_control_table ; 
 struct b206x_init_tab_entry* lpphy_rev01_noise_scale_table ; 
 struct b206x_init_tab_entry* lpphy_rev01_ps_control_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev0_2ghz_tx_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev0_5ghz_tx_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev0_nopa_tx_gain_table ; 
 struct b206x_init_tab_entry* lpphy_rev0_ofdm_cck_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev1_2ghz_tx_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev1_5ghz_tx_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev1_nopa_tx_gain_table ; 
 struct b206x_init_tab_entry* lpphy_rev1_ofdm_cck_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev2_2ghz_tx_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev2_5ghz_tx_gain_table ; 
 struct lpphy_tx_gain_table_entry* lpphy_rev2_nopa_tx_gain_table ; 
 struct b206x_init_tab_entry* lpphy_rev2plus_filter_control_table ; 
 struct b206x_init_tab_entry* lpphy_rev2plus_noise_scale_table ; 
 struct b206x_init_tab_entry* lpphy_rev2plus_ps_control_table ; 
 struct b206x_init_tab_entry* lpphy_sw_control_table ; 
 struct b206x_init_tab_entry* lpphy_tx_power_control_table ; 
 struct b43_wldev* ssb_get_drvdata (struct ssb_device*) ; 
 int stub1 (TYPE_6__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_6__*,void*,size_t,int,int) ; 
 int /*<<< orphan*/  stub11 (TYPE_6__*,void const*,size_t,int,int) ; 
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

void b2062_upload_init_table(struct b43_wldev *dev)
{
	const struct b206x_init_tab_entry *e;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(b2062_init_tab); i++) {
		e = &b2062_init_tab[i];
		if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ) {
			if (!(e->flags & B206X_FLAG_G))
				continue;
			b43_radio_write(dev, e->offset, e->value_g);
		} else {
			if (!(e->flags & B206X_FLAG_A))
				continue;
			b43_radio_write(dev, e->offset, e->value_a);
		}
	}
}

void b2063_upload_init_table(struct b43_wldev *dev)
{
	const struct b206x_init_tab_entry *e;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(b2063_init_tab); i++) {
		e = &b2063_init_tab[i];
		if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ) {
			if (!(e->flags & B206X_FLAG_G))
				continue;
			b43_radio_write(dev, e->offset, e->value_g);
		} else {
			if (!(e->flags & B206X_FLAG_A))
				continue;
			b43_radio_write(dev, e->offset, e->value_a);
		}
	}
}

u32 b43_lptab_read(struct b43_wldev *dev, u32 offset)
{
	u32 type, value;

	type = offset & B43_LPTAB_TYPEMASK;
	offset &= ~B43_LPTAB_TYPEMASK;
	B43_WARN_ON(offset > 0xFFFF);

	switch (type) {
	case B43_LPTAB_8BIT:
		b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
		value = b43_phy_read(dev, B43_LPPHY_TABLEDATALO) & 0xFF;
		break;
	case B43_LPTAB_16BIT:
		b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
		value = b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
		break;
	case B43_LPTAB_32BIT:
		b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
		value = b43_phy_read(dev, B43_LPPHY_TABLEDATAHI);
		value <<= 16;
		value |= b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
		break;
	default:
		B43_WARN_ON(1);
		value = 0;
	}

	return value;
}

void b43_lptab_read_bulk(struct b43_wldev *dev, u32 offset,
			 unsigned int nr_elements, void *_data)
{
	u32 type;
	u8 *data = _data;
	unsigned int i;

	type = offset & B43_LPTAB_TYPEMASK;
	offset &= ~B43_LPTAB_TYPEMASK;
	B43_WARN_ON(offset > 0xFFFF);

	b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);

	for (i = 0; i < nr_elements; i++) {
		switch (type) {
		case B43_LPTAB_8BIT:
			*data = b43_phy_read(dev, B43_LPPHY_TABLEDATALO) & 0xFF;
			data++;
			break;
		case B43_LPTAB_16BIT:
			*((u16 *)data) = b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
			data += 2;
			break;
		case B43_LPTAB_32BIT:
			*((u32 *)data) = b43_phy_read(dev, B43_LPPHY_TABLEDATAHI);
			*((u32 *)data) <<= 16;
			*((u32 *)data) |= b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
			data += 4;
			break;
		default:
			B43_WARN_ON(1);
		}
	}
}

void b43_lptab_write(struct b43_wldev *dev, u32 offset, u32 value)
{
	u32 type;

	type = offset & B43_LPTAB_TYPEMASK;
	offset &= ~B43_LPTAB_TYPEMASK;
	B43_WARN_ON(offset > 0xFFFF);

	switch (type) {
	case B43_LPTAB_8BIT:
		B43_WARN_ON(value & ~0xFF);
		b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
		b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
		break;
	case B43_LPTAB_16BIT:
		B43_WARN_ON(value & ~0xFFFF);
		b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
		b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
		break;
	case B43_LPTAB_32BIT:
		b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
		b43_phy_write(dev, B43_LPPHY_TABLEDATAHI, value >> 16);
		b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
		break;
	default:
		B43_WARN_ON(1);
	}
}

void b43_lptab_write_bulk(struct b43_wldev *dev, u32 offset,
			  unsigned int nr_elements, const void *_data)
{
	u32 type, value;
	const u8 *data = _data;
	unsigned int i;

	type = offset & B43_LPTAB_TYPEMASK;
	offset &= ~B43_LPTAB_TYPEMASK;
	B43_WARN_ON(offset > 0xFFFF);

	b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);

	for (i = 0; i < nr_elements; i++) {
		switch (type) {
		case B43_LPTAB_8BIT:
			value = *data;
			data++;
			B43_WARN_ON(value & ~0xFF);
			b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
			break;
		case B43_LPTAB_16BIT:
			value = *((u16 *)data);
			data += 2;
			B43_WARN_ON(value & ~0xFFFF);
			b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
			break;
		case B43_LPTAB_32BIT:
			value = *((u32 *)data);
			data += 4;
			b43_phy_write(dev, B43_LPPHY_TABLEDATAHI, value >> 16);
			b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
			break;
		default:
			B43_WARN_ON(1);
		}
	}
}

void lpphy_rev0_1_table_init(struct b43_wldev *dev)
{
	B43_WARN_ON(dev->phy.rev >= 2);

	b43_lptab_write_bulk(dev, B43_LPTAB8(2, 0),
		ARRAY_SIZE(lpphy_min_sig_sq_table), lpphy_min_sig_sq_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(1, 0),
		ARRAY_SIZE(lpphy_rev01_noise_scale_table), lpphy_rev01_noise_scale_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(14, 0),
		ARRAY_SIZE(lpphy_crs_gain_nft_table), lpphy_crs_gain_nft_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(8, 0),
		ARRAY_SIZE(lpphy_rev01_filter_control_table), lpphy_rev01_filter_control_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(9, 0),
		ARRAY_SIZE(lpphy_rev01_ps_control_table), lpphy_rev01_ps_control_table);
	b43_lptab_write_bulk(dev, B43_LPTAB8(6, 0),
		ARRAY_SIZE(lpphy_pll_fraction_table), lpphy_pll_fraction_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(0, 0),
		ARRAY_SIZE(lpphy_iqlo_cal_table), lpphy_iqlo_cal_table);
	if (dev->phy.rev == 0) {
		b43_lptab_write_bulk(dev, B43_LPTAB16(13, 0),
			ARRAY_SIZE(lpphy_rev0_ofdm_cck_gain_table), lpphy_rev0_ofdm_cck_gain_table);
		b43_lptab_write_bulk(dev, B43_LPTAB16(12, 0),
			ARRAY_SIZE(lpphy_rev0_ofdm_cck_gain_table), lpphy_rev0_ofdm_cck_gain_table);
	} else {
		b43_lptab_write_bulk(dev, B43_LPTAB16(13, 0),
			ARRAY_SIZE(lpphy_rev1_ofdm_cck_gain_table), lpphy_rev1_ofdm_cck_gain_table);
		b43_lptab_write_bulk(dev, B43_LPTAB16(12, 0),
			ARRAY_SIZE(lpphy_rev1_ofdm_cck_gain_table), lpphy_rev1_ofdm_cck_gain_table);
}
	b43_lptab_write_bulk(dev, B43_LPTAB16(15, 0),
		ARRAY_SIZE(lpphy_gain_delta_table), lpphy_gain_delta_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(10, 0),
		ARRAY_SIZE(lpphy_tx_power_control_table), lpphy_tx_power_control_table);
}

void lpphy_rev2plus_table_init(struct b43_wldev *dev)
{
	int i;

	B43_WARN_ON(dev->phy.rev < 2);

	for (i = 0; i < 704; i++)
		b43_lptab_write(dev, B43_LPTAB32(7, i), 0);

	b43_lptab_write_bulk(dev, B43_LPTAB8(2, 0),
		ARRAY_SIZE(lpphy_min_sig_sq_table), lpphy_min_sig_sq_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(1, 0),
		ARRAY_SIZE(lpphy_rev2plus_noise_scale_table), lpphy_rev2plus_noise_scale_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(11, 0),
		ARRAY_SIZE(lpphy_rev2plus_filter_control_table), lpphy_rev2plus_filter_control_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(12, 0),
		ARRAY_SIZE(lpphy_rev2plus_ps_control_table), lpphy_rev2plus_ps_control_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(13, 0),
		ARRAY_SIZE(lpphy_gain_idx_table), lpphy_gain_idx_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(14, 0),
		ARRAY_SIZE(lpphy_aux_gain_idx_table), lpphy_aux_gain_idx_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(15, 0),
		ARRAY_SIZE(lpphy_sw_control_table), lpphy_sw_control_table);
	b43_lptab_write_bulk(dev, B43_LPTAB8(16, 0),
		ARRAY_SIZE(lpphy_hf_table), lpphy_hf_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(17, 0),
		ARRAY_SIZE(lpphy_gain_value_table), lpphy_gain_value_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(18, 0),
		ARRAY_SIZE(lpphy_gain_table), lpphy_gain_table);
	b43_lptab_write_bulk(dev, B43_LPTAB8(6, 0),
		ARRAY_SIZE(lpphy_pll_fraction_table), lpphy_pll_fraction_table);
	b43_lptab_write_bulk(dev, B43_LPTAB16(0, 0),
		ARRAY_SIZE(lpphy_iqlo_cal_table), lpphy_iqlo_cal_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(9, 0),
		ARRAY_SIZE(lpphy_papd_eps_table), lpphy_papd_eps_table);
	b43_lptab_write_bulk(dev, B43_LPTAB32(10, 0),
		ARRAY_SIZE(lpphy_papd_mult_table), lpphy_papd_mult_table);

	if ((dev->dev->chip_id == 0x4325) && (dev->dev->chip_rev == 0)) {
		b43_lptab_write_bulk(dev, B43_LPTAB32(13, 0),
			ARRAY_SIZE(lpphy_a0_gain_idx_table), lpphy_a0_gain_idx_table);
		b43_lptab_write_bulk(dev, B43_LPTAB16(14, 0),
			ARRAY_SIZE(lpphy_a0_aux_gain_idx_table), lpphy_a0_aux_gain_idx_table);
		b43_lptab_write_bulk(dev, B43_LPTAB32(17, 0),
			ARRAY_SIZE(lpphy_a0_gain_value_table), lpphy_a0_gain_value_table);
		b43_lptab_write_bulk(dev, B43_LPTAB16(18, 0),
			ARRAY_SIZE(lpphy_a0_gain_table), lpphy_a0_gain_table);
	}
}

__attribute__((used)) static void lpphy_rev0_1_write_gain_table(struct b43_wldev *dev, int offset,
				struct lpphy_tx_gain_table_entry data)
{
	u32 tmp;

	B43_WARN_ON(dev->phy.rev >= 2);

	tmp  = data.pad << 11;
	tmp |= data.pga << 7;
	tmp |= data.gm  << 4;
	tmp |= data.dac;
	b43_lptab_write(dev, B43_LPTAB32(10, 0xC0 + offset), tmp);
	tmp  = data.bb_mult << 20;
	b43_lptab_write(dev, B43_LPTAB32(10, 0x140 + offset), tmp);
}

__attribute__((used)) static void lpphy_rev2plus_write_gain_table(struct b43_wldev *dev, int offset,
				struct lpphy_tx_gain_table_entry data)
{
	u32 tmp;

	B43_WARN_ON(dev->phy.rev < 2);

	tmp  = data.pad << 16;
	tmp |= data.pga << 8;
	tmp |= data.gm;
	if (dev->phy.rev >= 3) {
		if (b43_current_band(dev->wl) == NL80211_BAND_5GHZ)
			tmp |= 0x10 << 24;
		else
			tmp |= 0x70 << 24;
	} else {
		if (b43_current_band(dev->wl) == NL80211_BAND_5GHZ)
			tmp |= 0x14 << 24;
		else
			tmp |= 0x7F << 24;
	}
	b43_lptab_write(dev, B43_LPTAB32(7, 0xC0 + offset), tmp);
	tmp  = data.bb_mult << 20;
	tmp |= data.dac << 28;
	b43_lptab_write(dev, B43_LPTAB32(7, 0x140 + offset), tmp);
}

void lpphy_write_gain_table(struct b43_wldev *dev, int offset,
			    struct lpphy_tx_gain_table_entry data)
{
	if (dev->phy.rev >= 2)
		lpphy_rev2plus_write_gain_table(dev, offset, data);
	else
		lpphy_rev0_1_write_gain_table(dev, offset, data);
}

void lpphy_write_gain_table_bulk(struct b43_wldev *dev, int offset, int count,
				 struct lpphy_tx_gain_table_entry *table)
{
	int i;

	for (i = offset; i < count; i++)
		lpphy_write_gain_table(dev, i, table[i]);
}

void lpphy_init_tx_gain_table(struct b43_wldev *dev)
{
	struct ssb_sprom *sprom = dev->dev->bus_sprom;

	switch (dev->phy.rev) {
	case 0:
		if ((sprom->boardflags_hi & B43_BFH_NOPA) ||
		    (sprom->boardflags_lo & B43_BFL_HGPA))
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev0_nopa_tx_gain_table);
		else if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev0_2ghz_tx_gain_table);
		else
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev0_5ghz_tx_gain_table);
		break;
	case 1:
		if ((sprom->boardflags_hi & B43_BFH_NOPA) ||
		    (sprom->boardflags_lo & B43_BFL_HGPA))
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev1_nopa_tx_gain_table);
		else if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev1_2ghz_tx_gain_table);
		else
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev1_5ghz_tx_gain_table);
		break;
	default:
		if (sprom->boardflags_hi & B43_BFH_NOPA)
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev2_nopa_tx_gain_table);
		else if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev2_2ghz_tx_gain_table);
		else
			lpphy_write_gain_table_bulk(dev, 0, 128,
					lpphy_rev2_5ghz_tx_gain_table);
	}
}

