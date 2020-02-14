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
typedef  int /*<<< orphan*/  u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct ssb_sprom {int boardflags_lo; } ;
struct ssb_device {int dummy; } ;
struct ieee80211_hw {struct b43_wl* priv; } ;
struct device {int dummy; } ;
struct b43_phy {int rev; scalar_t__ type; } ;
struct b43_wldev {int __using_pio_transfers; struct b43_phy phy; TYPE_5__* dev; } ;
struct b43_wl {int if_type; TYPE_4__* hw; scalar_t__ operating; } ;
struct b43_txstatus {int dummy; } ;
struct b43_rfatt {scalar_t__ att; scalar_t__ with_padmix; } ;
struct b43_bus_dev {int dummy; } ;
struct b43_bbatt {scalar_t__ att; } ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum b43_dyndbg { ____Placeholder_b43_dyndbg } b43_dyndbg ;
struct TYPE_20__ {int (* bus_may_powerdown ) (TYPE_5__*) ;int (* bus_powerup ) (TYPE_5__*,int) ;int (* device_is_enabled ) (TYPE_5__*) ;int (* read16 ) (TYPE_5__*,int) ;int (* read32 ) (TYPE_5__*,int) ;scalar_t__ board_vendor; scalar_t__ board_type; int board_rev; struct ssb_sprom* bus_sprom; int /*<<< orphan*/  (* block_write ) (TYPE_5__*,void const*,size_t,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* block_read ) (TYPE_5__*,void*,size_t,int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* write32 ) (TYPE_5__*,int,int) ;int /*<<< orphan*/  (* write16 ) (TYPE_5__*,int,int) ;int /*<<< orphan*/  (* device_disable ) (TYPE_5__*,int) ;int /*<<< orphan*/  (* device_enable ) (TYPE_5__*,int) ;} ;
struct TYPE_17__ {TYPE_1__* chan; } ;
struct TYPE_18__ {TYPE_2__ chandef; } ;
struct TYPE_19__ {TYPE_3__ conf; } ;
struct TYPE_16__ {int band; } ;

/* Variables and functions */
 int B43_BFL_EXTLNA ; 
 int B43_BFL_FEM ; 
 int B43_CCK_RATE_11MB ; 
 int B43_CCK_RATE_1MB ; 
 int B43_CCK_RATE_2MB ; 
 int B43_CCK_RATE_5MB ; 
 int /*<<< orphan*/  B43_GTAB_ORIGTR ; 
 int /*<<< orphan*/  B43_OFDMTAB_ADVRETARD ; 
 int /*<<< orphan*/  B43_OFDMTAB_AGC1 ; 
 int /*<<< orphan*/  B43_OFDMTAB_AGC1_R1 ; 
 int /*<<< orphan*/  B43_OFDMTAB_AGC2 ; 
 int /*<<< orphan*/  B43_OFDMTAB_AGC3 ; 
 int /*<<< orphan*/  B43_OFDMTAB_AGC3_R1 ; 
 int /*<<< orphan*/  B43_OFDMTAB_DAC ; 
 int /*<<< orphan*/  B43_OFDMTAB_DACRFPABB ; 
 int /*<<< orphan*/  B43_OFDMTAB_GAINX ; 
 int /*<<< orphan*/  B43_OFDMTAB_GAINX_R1 ; 
 int /*<<< orphan*/  B43_OFDMTAB_LPFGAIN ; 
 int /*<<< orphan*/  B43_OFDMTAB_MINSIGSQ ; 
 int /*<<< orphan*/  B43_OFDMTAB_NOISESCALE ; 
 int /*<<< orphan*/  B43_OFDMTAB_ROTOR ; 
 int /*<<< orphan*/  B43_OFDMTAB_RSSI ; 
 int /*<<< orphan*/  B43_OFDMTAB_UNKNOWN_0F ; 
 int /*<<< orphan*/  B43_OFDMTAB_UNKNOWN_11 ; 
 int /*<<< orphan*/  B43_OFDMTAB_WRSSI ; 
 int /*<<< orphan*/  B43_OFDMTAB_WRSSI_R1 ; 
 scalar_t__ B43_PHYTYPE_G ; 
 int B43_PHYVER_VERSION ; 
 int /*<<< orphan*/  B43_PHY_ANTDWELL ; 
 int B43_PHY_ANTWRSETT ; 
 int B43_PHY_CCKSHIFTBITS ; 
 int B43_PHY_CCKSHIFTBITS_WA ; 
 int B43_PHY_CRS0 ; 
 int B43_PHY_CRSTHRES1 ; 
 int B43_PHY_CRSTHRES1_R1 ; 
 int B43_PHY_CRSTHRES2 ; 
 int B43_PHY_DIVP1P2GAIN ; 
 int B43_PHY_DIVSRCHIDX ; 
 int /*<<< orphan*/  B43_PHY_ENCORE ; 
 int B43_PHY_ENCORE_EN ; 
 int B43_PHY_EXTG (int) ; 
 int B43_PHY_GTABCTL ; 
 int B43_PHY_GTABDATA ; 
 int B43_PHY_LMS ; 
 int B43_PHY_LNAHPFCTL ; 
 int B43_PHY_LPFGAINCTL ; 
 int B43_PHY_N1N2GAIN ; 
 int B43_PHY_N1P1GAIN ; 
 int B43_PHY_OFDM (int) ; 
 int B43_PHY_P1P2GAIN ; 
 int B43_PHY_PEAK_COUNT ; 
 int B43_PHY_PWRDOWN ; 
 int /*<<< orphan*/  B43_PHY_VERSION_OFDM ; 
 int B43_TAB_FINEFREQG_SIZE ; 
 int B43_TAB_NOISEG1_SIZE ; 
 int B43_TAB_NOISEG2_SIZE ; 
 int B43_TAB_NOISESCALE_SIZE ; 
 int B43_TAB_RETARD_SIZE ; 
 int B43_TAB_ROTOR_SIZE ; 
 int B43_TAB_SIGMASQR_SIZE ; 
 int /*<<< orphan*/  B43_WARN_ON (int) ; 
 scalar_t__ SSB_BOARDVENDOR_BCM ; 
 scalar_t__ SSB_BOARD_BU4306 ; 
 int /*<<< orphan*/  b43_gtab_write (struct b43_wldev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43_ofdmtab_write16 (struct b43_wldev*,int /*<<< orphan*/ ,int,int const) ; 
 int /*<<< orphan*/  b43_ofdmtab_write32 (struct b43_wldev*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_phy_mask (struct b43_wldev*,int,int) ; 
 int /*<<< orphan*/  b43_phy_maskset (struct b43_wldev*,int,int,int) ; 
 int b43_phy_read (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_phy_set (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43_phy_write (struct b43_wldev*,int,int) ; 
 int /*<<< orphan*/  b43_radio_set (struct b43_wldev*,int,int) ; 
 int /*<<< orphan*/  b43_radio_write16 (struct b43_wldev*,int,int) ; 
 int* b43_tab_finefreqg ; 
 int* b43_tab_noiseg1 ; 
 int* b43_tab_noiseg2 ; 
 int* b43_tab_noisescaleg1 ; 
 int* b43_tab_noisescaleg2 ; 
 int* b43_tab_noisescaleg3 ; 
 int /*<<< orphan*/ * b43_tab_retard ; 
 int /*<<< orphan*/ * b43_tab_rotor ; 
 int* b43_tab_sigmasqr2 ; 
 struct ssb_device* dev_to_ssb_dev (struct device*) ; 
 struct b43_wldev* ssb_get_drvdata (struct ssb_device*) ; 
 int stub1 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_5__*,void*,size_t,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (TYPE_5__*,void const*,size_t,int,int /*<<< orphan*/ ) ; 
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

__attribute__((used)) static inline int b43_is_cck_rate(int rate)
{
	return (rate == B43_CCK_RATE_1MB ||
		rate == B43_CCK_RATE_2MB ||
		rate == B43_CCK_RATE_5MB || rate == B43_CCK_RATE_11MB);
}

__attribute__((used)) static inline int b43_is_ofdm_rate(int rate)
{
	return !b43_is_cck_rate(rate);
}

void b43_wa_initgains(struct b43_wldev *dev)
{
	struct b43_phy *phy = &dev->phy;

	b43_phy_write(dev, B43_PHY_LNAHPFCTL, 0x1FF9);
	b43_phy_mask(dev, B43_PHY_LPFGAINCTL, 0xFF0F);
	if (phy->rev <= 2)
		b43_ofdmtab_write16(dev, B43_OFDMTAB_LPFGAIN, 0, 0x1FBF);
	b43_radio_write16(dev, 0x0002, 0x1FBF);

	b43_phy_write(dev, 0x0024, 0x4680);
	b43_phy_write(dev, 0x0020, 0x0003);
	b43_phy_write(dev, 0x001D, 0x0F40);
	b43_phy_write(dev, 0x001F, 0x1C00);
	if (phy->rev <= 3)
		b43_phy_maskset(dev, 0x002A, 0x00FF, 0x0400);
	else if (phy->rev == 5) {
		b43_phy_maskset(dev, 0x002A, 0x00FF, 0x1A00);
		b43_phy_write(dev, 0x00CC, 0x2121);
	}
	if (phy->rev >= 3)
		b43_phy_write(dev, 0x00BA, 0x3ED5);
}

__attribute__((used)) static void b43_wa_rssi_lt(struct b43_wldev *dev) /* RSSI lookup table */
{
	int i;

	if (0 /* FIXME: For APHY.rev=2 this might be needed */) {
		for (i = 0; i < 8; i++)
			b43_ofdmtab_write16(dev, B43_OFDMTAB_RSSI, i, i + 8);
		for (i = 8; i < 16; i++)
			b43_ofdmtab_write16(dev, B43_OFDMTAB_RSSI, i, i - 8);
	} else {
		for (i = 0; i < 64; i++)
			b43_ofdmtab_write16(dev, B43_OFDMTAB_RSSI, i, i);
	}
}

__attribute__((used)) static void b43_wa_analog(struct b43_wldev *dev)
{
	u16 ofdmrev;

	ofdmrev = b43_phy_read(dev, B43_PHY_VERSION_OFDM) & B43_PHYVER_VERSION;
	if (ofdmrev > 2) {
		b43_phy_write(dev, B43_PHY_PWRDOWN, 0x1000);
	} else {
		b43_ofdmtab_write16(dev, B43_OFDMTAB_DAC, 3, 0x1044);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_DAC, 4, 0x7201);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_DAC, 6, 0x0040);
	}
}

__attribute__((used)) static void b43_wa_fft(struct b43_wldev *dev) /* Fine frequency table */
{
	int i;

	for (i = 0; i < B43_TAB_FINEFREQG_SIZE; i++)
		b43_ofdmtab_write16(dev, B43_OFDMTAB_DACRFPABB, i,
				    b43_tab_finefreqg[i]);
}

__attribute__((used)) static void b43_wa_nft(struct b43_wldev *dev) /* Noise figure table */
{
	struct b43_phy *phy = &dev->phy;
	int i;

	if (phy->rev == 1)
		for (i = 0; i < B43_TAB_NOISEG1_SIZE; i++)
			b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC2, i,
					    b43_tab_noiseg1[i]);
	else
		for (i = 0; i < B43_TAB_NOISEG2_SIZE; i++)
			b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC2, i,
					    b43_tab_noiseg2[i]);
}

__attribute__((used)) static void b43_wa_rt(struct b43_wldev *dev) /* Rotor table */
{
	int i;

	for (i = 0; i < B43_TAB_ROTOR_SIZE; i++)
		b43_ofdmtab_write32(dev, B43_OFDMTAB_ROTOR, i, b43_tab_rotor[i]);
}

__attribute__((used)) static void b43_write_nst(struct b43_wldev *dev, const u16 *nst)
{
	int i;

	for (i = 0; i < B43_TAB_NOISESCALE_SIZE; i++)
		b43_ofdmtab_write16(dev, B43_OFDMTAB_NOISESCALE, i, nst[i]);
}

__attribute__((used)) static void b43_wa_nst(struct b43_wldev *dev) /* Noise scale table */
{
	struct b43_phy *phy = &dev->phy;

	if (phy->rev >= 6) {
		if (b43_phy_read(dev, B43_PHY_ENCORE) & B43_PHY_ENCORE_EN)
			b43_write_nst(dev, b43_tab_noisescaleg3);
		else
			b43_write_nst(dev, b43_tab_noisescaleg2);
	} else {
		b43_write_nst(dev, b43_tab_noisescaleg1);
	}
}

__attribute__((used)) static void b43_wa_art(struct b43_wldev *dev) /* ADV retard table */
{
	int i;

	for (i = 0; i < B43_TAB_RETARD_SIZE; i++)
			b43_ofdmtab_write32(dev, B43_OFDMTAB_ADVRETARD,
				i, b43_tab_retard[i]);
}

__attribute__((used)) static void b43_wa_msst(struct b43_wldev *dev) /* Min sigma square table */
{
	struct b43_phy *phy = &dev->phy;
	int i;
	const u16 *tab;

	if (phy->type == B43_PHYTYPE_G) {
		tab = b43_tab_sigmasqr2;
	} else {
		B43_WARN_ON(1);
		return;
	}

	for (i = 0; i < B43_TAB_SIGMASQR_SIZE; i++) {
		b43_ofdmtab_write16(dev, B43_OFDMTAB_MINSIGSQ,
					i, tab[i]);
	}
}

__attribute__((used)) static void b43_wa_crs_ed(struct b43_wldev *dev)
{
	struct b43_phy *phy = &dev->phy;

	if (phy->rev == 1) {
		b43_phy_write(dev, B43_PHY_CRSTHRES1_R1, 0x4F19);
	} else if (phy->rev == 2) {
		b43_phy_write(dev, B43_PHY_CRSTHRES1, 0x1861);
		b43_phy_write(dev, B43_PHY_CRSTHRES2, 0x0271);
		b43_phy_set(dev, B43_PHY_ANTDWELL, 0x0800);
	} else {
		b43_phy_write(dev, B43_PHY_CRSTHRES1, 0x0098);
		b43_phy_write(dev, B43_PHY_CRSTHRES2, 0x0070);
		b43_phy_write(dev, B43_PHY_OFDM(0xC9), 0x0080);
		b43_phy_set(dev, B43_PHY_ANTDWELL, 0x0800);
	}
}

__attribute__((used)) static void b43_wa_crs_thr(struct b43_wldev *dev)
{
	b43_phy_maskset(dev, B43_PHY_CRS0, ~0x03C0, 0xD000);
}

__attribute__((used)) static void b43_wa_crs_blank(struct b43_wldev *dev)
{
	b43_phy_write(dev, B43_PHY_OFDM(0x2C), 0x005A);
}

__attribute__((used)) static void b43_wa_cck_shiftbits(struct b43_wldev *dev)
{
	b43_phy_write(dev, B43_PHY_CCKSHIFTBITS, 0x0026);
}

__attribute__((used)) static void b43_wa_wrssi_offset(struct b43_wldev *dev)
{
	int i;

	if (dev->phy.rev == 1) {
		for (i = 0; i < 16; i++) {
			b43_ofdmtab_write16(dev, B43_OFDMTAB_WRSSI_R1,
						i, 0x0020);
		}
	} else {
		for (i = 0; i < 32; i++) {
			b43_ofdmtab_write16(dev, B43_OFDMTAB_WRSSI,
						i, 0x0820);
		}
	}
}

__attribute__((used)) static void b43_wa_txpuoff_rxpuon(struct b43_wldev *dev)
{
	b43_ofdmtab_write16(dev, B43_OFDMTAB_UNKNOWN_0F, 2, 15);
	b43_ofdmtab_write16(dev, B43_OFDMTAB_UNKNOWN_0F, 3, 20);
}

__attribute__((used)) static void b43_wa_altagc(struct b43_wldev *dev)
{
	struct b43_phy *phy = &dev->phy;

	if (phy->rev == 1) {
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1_R1, 0, 254);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1_R1, 1, 13);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1_R1, 2, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1_R1, 3, 25);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC2, 0, 0x2710);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC2, 1, 0x9B83);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC2, 2, 0x9B83);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC2, 3, 0x0F8D);
		b43_phy_write(dev, B43_PHY_LMS, 4);
	} else {
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 0, 254);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 1, 13);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 2, 19);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC1, 3, 25);
	}

	b43_phy_maskset(dev, B43_PHY_CCKSHIFTBITS_WA, 0x00FF, 0x5700);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x1A), ~0x007F, 0x000F);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x1A), ~0x3F80, 0x2B80);
	b43_phy_maskset(dev, B43_PHY_ANTWRSETT, 0xF0FF, 0x0300);
	b43_radio_set(dev, 0x7A, 0x0008);
	b43_phy_maskset(dev, B43_PHY_N1P1GAIN, ~0x000F, 0x0008);
	b43_phy_maskset(dev, B43_PHY_P1P2GAIN, ~0x0F00, 0x0600);
	b43_phy_maskset(dev, B43_PHY_N1N2GAIN, ~0x0F00, 0x0700);
	b43_phy_maskset(dev, B43_PHY_N1P1GAIN, ~0x0F00, 0x0100);
	if (phy->rev == 1) {
		b43_phy_maskset(dev, B43_PHY_N1N2GAIN, ~0x000F, 0x0007);
	}
	b43_phy_maskset(dev, B43_PHY_OFDM(0x88), ~0x00FF, 0x001C);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x88), ~0x3F00, 0x0200);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x96), ~0x00FF, 0x001C);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x89), ~0x00FF, 0x0020);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x89), ~0x3F00, 0x0200);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x82), ~0x00FF, 0x002E);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x96), 0x00FF, 0x1A00);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x81), ~0x00FF, 0x0028);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x81), 0x00FF, 0x2C00);
	if (phy->rev == 1) {
		b43_phy_write(dev, B43_PHY_PEAK_COUNT, 0x092B);
		b43_phy_maskset(dev, B43_PHY_OFDM(0x1B), ~0x001E, 0x0002);
	} else {
		b43_phy_mask(dev, B43_PHY_OFDM(0x1B), ~0x001E);
		b43_phy_write(dev, B43_PHY_OFDM(0x1F), 0x287A);
		b43_phy_maskset(dev, B43_PHY_LPFGAINCTL, ~0x000F, 0x0004);
		if (phy->rev >= 6) {
			b43_phy_write(dev, B43_PHY_OFDM(0x22), 0x287A);
			b43_phy_maskset(dev, B43_PHY_LPFGAINCTL, 0x0FFF, 0x3000);
		}
	}
	b43_phy_maskset(dev, B43_PHY_DIVSRCHIDX, 0x8080, 0x7874);
	b43_phy_write(dev, B43_PHY_OFDM(0x8E), 0x1C00);
	if (phy->rev == 1) {
		b43_phy_maskset(dev, B43_PHY_DIVP1P2GAIN, ~0x0F00, 0x0600);
		b43_phy_write(dev, B43_PHY_OFDM(0x8B), 0x005E);
		b43_phy_maskset(dev, B43_PHY_ANTWRSETT, ~0x00FF, 0x001E);
		b43_phy_write(dev, B43_PHY_OFDM(0x8D), 0x0002);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3_R1, 0, 0);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3_R1, 1, 7);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3_R1, 2, 16);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3_R1, 3, 28);
	} else {
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3, 0, 0);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3, 1, 7);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3, 2, 16);
		b43_ofdmtab_write16(dev, B43_OFDMTAB_AGC3, 3, 28);
	}
	if (phy->rev >= 6) {
		b43_phy_mask(dev, B43_PHY_OFDM(0x26), ~0x0003);
		b43_phy_mask(dev, B43_PHY_OFDM(0x26), ~0x1000);
	}
	b43_phy_read(dev, B43_PHY_VERSION_OFDM); /* Dummy read */
}

__attribute__((used)) static void b43_wa_tr_ltov(struct b43_wldev *dev) /* TR Lookup Table Original Values */
{
	b43_gtab_write(dev, B43_GTAB_ORIGTR, 0, 0x7654);
}

__attribute__((used)) static void b43_wa_cpll_nonpilot(struct b43_wldev *dev)
{
	b43_ofdmtab_write16(dev, B43_OFDMTAB_UNKNOWN_11, 0, 0);
	b43_ofdmtab_write16(dev, B43_OFDMTAB_UNKNOWN_11, 1, 0);
}

__attribute__((used)) static void b43_wa_boards_g(struct b43_wldev *dev)
{
	struct ssb_sprom *sprom = dev->dev->bus_sprom;
	struct b43_phy *phy = &dev->phy;

	if (dev->dev->board_vendor != SSB_BOARDVENDOR_BCM ||
	    dev->dev->board_type != SSB_BOARD_BU4306 ||
	    dev->dev->board_rev != 0x17) {
		if (phy->rev < 2) {
			b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX_R1, 1, 0x0002);
			b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX_R1, 2, 0x0001);
		} else {
			b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 1, 0x0002);
			b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 2, 0x0001);
			if ((sprom->boardflags_lo & B43_BFL_EXTLNA) &&
			    (phy->rev >= 7)) {
				b43_phy_mask(dev, B43_PHY_EXTG(0x11), 0xF7FF);
				b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 0x0020, 0x0001);
				b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 0x0021, 0x0001);
				b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 0x0022, 0x0001);
				b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 0x0023, 0x0000);
				b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 0x0000, 0x0000);
				b43_ofdmtab_write16(dev, B43_OFDMTAB_GAINX, 0x0003, 0x0002);
			}
		}
	}
	if (sprom->boardflags_lo & B43_BFL_FEM) {
		b43_phy_write(dev, B43_PHY_GTABCTL, 0x3120);
		b43_phy_write(dev, B43_PHY_GTABDATA, 0xC480);
	}
}

void b43_wa_all(struct b43_wldev *dev)
{
	struct b43_phy *phy = &dev->phy;

	if (phy->type == B43_PHYTYPE_G) {
		switch (phy->rev) {
		case 1://XXX review rev1
			b43_wa_crs_ed(dev);
			b43_wa_crs_thr(dev);
			b43_wa_crs_blank(dev);
			b43_wa_cck_shiftbits(dev);
			b43_wa_fft(dev);
			b43_wa_nft(dev);
			b43_wa_rt(dev);
			b43_wa_nst(dev);
			b43_wa_art(dev);
			b43_wa_wrssi_offset(dev);
			b43_wa_altagc(dev);
			break;
		case 2:
		case 6:
		case 7:
		case 8:
		case 9:
			b43_wa_tr_ltov(dev);
			b43_wa_crs_ed(dev);
			b43_wa_rssi_lt(dev);
			b43_wa_nft(dev);
			b43_wa_nst(dev);
			b43_wa_msst(dev);
			b43_wa_wrssi_offset(dev);
			b43_wa_altagc(dev);
			b43_wa_analog(dev);
			b43_wa_txpuoff_rxpuon(dev);
			break;
		default:
			B43_WARN_ON(1);
		}
		b43_wa_boards_g(dev);
	} else { /* No N PHY support so far, LP PHY is in phy_lp.c */
		B43_WARN_ON(1);
	}

	b43_wa_cpll_nonpilot(dev);
}

