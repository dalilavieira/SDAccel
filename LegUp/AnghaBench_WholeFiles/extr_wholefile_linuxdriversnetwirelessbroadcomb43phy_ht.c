#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;
typedef  struct TYPE_19__   TYPE_18__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct ssb_sprom {TYPE_3__* core_pwr_info; } ;
struct ssb_device {int dummy; } ;
struct ieee80211_hw {struct b43_wl* priv; } ;
struct ieee80211_channel {int band; int hw_value; int /*<<< orphan*/  center_freq; } ;
struct device {int dummy; } ;
struct bcma_device {TYPE_4__* bus; } ;
struct b43_phy {int radio_ver; int /*<<< orphan*/  channel; struct b43_phy_ht* ht; TYPE_2__* chandef; } ;
struct b43_wldev {int __using_pio_transfers; struct b43_wl* wl; struct b43_phy phy; TYPE_7__* dev; } ;
struct b43_wl {int if_type; TYPE_6__* hw; scalar_t__ operating; } ;
struct b43_txstatus {int dummy; } ;
struct b43_rfatt {scalar_t__ att; scalar_t__ with_padmix; } ;
struct b43_phy_ht_channeltab_e_phy {int bw1; int bw2; int bw3; int bw4; int bw5; int bw6; } ;
struct b43_phy_ht_channeltab_e_radio2059 {int radio_syn16; int radio_syn17; int radio_syn22; int radio_syn25; int radio_syn27; int radio_syn28; int radio_syn29; int radio_syn2c; int radio_syn2d; int radio_syn37; int radio_syn41; int radio_syn43; int radio_syn47; int radio_rxtx4a; int radio_rxtx58; int radio_rxtx5a; int radio_rxtx6a; int radio_rxtx6d; int radio_rxtx6e; int radio_rxtx92; int radio_rxtx98; struct b43_phy_ht_channeltab_e_phy phy_regs; } ;
struct b43_phy_ht {int* rf_ctl_int_save; scalar_t__* bb_mult_save; int* tx_pwr_idx; int tx_pwr_ctl; int* idle_tssi; } ;
struct b43_bus_dev {int dummy; } ;
struct b43_bbatt {scalar_t__ att; } ;
typedef  int s8 ;
typedef  int s32 ;
typedef  int s16 ;
typedef  enum nl80211_channel_type { ____Placeholder_nl80211_channel_type } nl80211_channel_type ;
typedef  enum nl80211_band { ____Placeholder_nl80211_band } nl80211_band ;
typedef  enum ht_rssi_type { ____Placeholder_ht_rssi_type } ht_rssi_type ;
typedef  enum b43_txpwr_result { ____Placeholder_b43_txpwr_result } b43_txpwr_result ;
typedef  enum b43_dyndbg { ____Placeholder_b43_dyndbg } b43_dyndbg ;
struct TYPE_26__ {int (* bus_may_powerdown ) (TYPE_7__*) ;int (* bus_powerup ) (TYPE_7__*,int) ;int (* device_is_enabled ) (TYPE_7__*) ;int (* read16 ) (TYPE_7__*,int) ;int (* read32 ) (TYPE_7__*,int) ;scalar_t__ bus_type; struct bcma_device* bdev; struct ssb_sprom* bus_sprom; int /*<<< orphan*/  (* block_write ) (TYPE_7__*,void const*,size_t,int,int) ;int /*<<< orphan*/  (* block_read ) (TYPE_7__*,void*,size_t,int,int) ;int /*<<< orphan*/  (* write32 ) (TYPE_7__*,int,int) ;int /*<<< orphan*/  (* write16 ) (TYPE_7__*,int,int) ;int /*<<< orphan*/  (* device_disable ) (TYPE_7__*,int) ;int /*<<< orphan*/  (* device_enable ) (TYPE_7__*,int) ;} ;
struct TYPE_19__ {struct ieee80211_channel* chan; } ;
struct TYPE_24__ {TYPE_18__ chandef; } ;
struct TYPE_25__ {TYPE_5__ conf; } ;
struct TYPE_23__ {int /*<<< orphan*/  drv_cc; } ;
struct TYPE_22__ {int maxpwr_2g; int* pa_2g; int maxpwr_5gl; int* pa_5gl; int maxpwr_5g; int* pa_5g; int maxpwr_5gh; int* pa_5gh; } ;
struct TYPE_21__ {TYPE_1__* chan; } ;
struct TYPE_20__ {int center_freq; } ;

/* Variables and functions */
 int ARRAY_SIZE (int const*) ; 
 int B43_BCMA_CLKCTLST_80211_PLL_REQ ; 
 int B43_BCMA_CLKCTLST_80211_PLL_ST ; 
 int B43_BCMA_CLKCTLST_PHY_PLL_REQ ; 
 int B43_BCMA_CLKCTLST_PHY_PLL_ST ; 
 scalar_t__ B43_BUS_BCMA ; 
 int B43_CCK_RATE_11MB ; 
 int B43_CCK_RATE_1MB ; 
 int B43_CCK_RATE_2MB ; 
 int B43_CCK_RATE_5MB ; 
 int /*<<< orphan*/  B43_HTTAB16 (int,int) ; 
 int /*<<< orphan*/  B43_HTTAB32 (int,int) ; 
 int /*<<< orphan*/  B43_HTTAB8 (int,int) ; 
 int B43_HTTAB_1A_C0_LATE_SIZE ; 
 int B43_MACCTL_ENABLED ; 
 int B43_MMIO_MACCTL ; 
 int B43_MMIO_PHY_CONTROL ; 
 int B43_MMIO_PHY_DATA ; 
 int B43_MMIO_PSM_PHY_HDR ; 
 int B43_MMIO_RADIO24_CONTROL ; 
 int B43_MMIO_RADIO24_DATA ; 
 int B43_PHY_B_BBCFG ; 
 int B43_PHY_B_BBCFG_RSTCCA ; 
 int B43_PHY_B_BBCFG_RSTRX ; 
 int B43_PHY_EXTG (int const) ; 
#define  B43_PHY_HT_AFE_C1 146 
#define  B43_PHY_HT_AFE_C1_OVER 145 
#define  B43_PHY_HT_AFE_C2 144 
#define  B43_PHY_HT_AFE_C2_OVER 143 
#define  B43_PHY_HT_AFE_C3 142 
#define  B43_PHY_HT_AFE_C3_OVER 141 
 int B43_PHY_HT_BANDCTL ; 
 int B43_PHY_HT_BANDCTL_5GHZ ; 
 int const B43_PHY_HT_BBCFG ; 
 int B43_PHY_HT_BBCFG_RSTCCA ; 
 int B43_PHY_HT_BBCFG_RSTRX ; 
 int const B43_PHY_HT_BW1 ; 
 int const B43_PHY_HT_BW2 ; 
 int const B43_PHY_HT_BW3 ; 
 int const B43_PHY_HT_BW4 ; 
 int const B43_PHY_HT_BW5 ; 
 int const B43_PHY_HT_BW6 ; 
 int const B43_PHY_HT_C1_CLIP1THRES ; 
 int const B43_PHY_HT_C2_CLIP1THRES ; 
 int const B43_PHY_HT_C3_CLIP1THRES ; 
 int B43_PHY_HT_CLASS_CTL ; 
 int B43_PHY_HT_CLASS_CTL_CCK_EN ; 
 int B43_PHY_HT_CLASS_CTL_OFDM_EN ; 
 int B43_PHY_HT_CLASS_CTL_WAITED_EN ; 
 int B43_PHY_HT_IQLOCAL_CMDGCTL ; 
 int B43_PHY_HT_RF_CTL_CMD ; 
 int B43_PHY_HT_RF_CTL_CMD_CHIP0_PU ; 
 int B43_PHY_HT_RF_CTL_CMD_FORCE ; 
#define  B43_PHY_HT_RF_CTL_INT_C1 140 
#define  B43_PHY_HT_RF_CTL_INT_C2 139 
#define  B43_PHY_HT_RF_CTL_INT_C3 138 
 int const B43_PHY_HT_RF_SEQ_MODE ; 
 int B43_PHY_HT_RF_SEQ_MODE_CA_OVER ; 
 int const B43_PHY_HT_RF_SEQ_STATUS ; 
 int B43_PHY_HT_RF_SEQ_TRIG ; 
 int B43_PHY_HT_RF_SEQ_TRIG_RST2RX ; 
 int B43_PHY_HT_RF_SEQ_TRIG_RX2TX ; 
 int const B43_PHY_HT_RSSI_C1 ; 
 int const B43_PHY_HT_RSSI_C2 ; 
 int const B43_PHY_HT_RSSI_C3 ; 
 int B43_PHY_HT_SAMP_CMD ; 
 int B43_PHY_HT_SAMP_CMD_STOP ; 
 int const B43_PHY_HT_SAMP_DEP_CNT ; 
 int const B43_PHY_HT_SAMP_LOOP_CNT ; 
 int const B43_PHY_HT_SAMP_STAT ; 
 int const B43_PHY_HT_SAMP_WAIT_CNT ; 
 int const B43_PHY_HT_TABLE_ADDR ; 
 int const B43_PHY_HT_TABLE_DATAHI ; 
 int const B43_PHY_HT_TABLE_DATALO ; 
 int B43_PHY_HT_TEST ; 
 int B43_PHY_HT_TSSIMODE ; 
 int B43_PHY_HT_TSSIMODE_EN ; 
#define  B43_PHY_HT_TXPCTL_CMD_C1 137 
 int B43_PHY_HT_TXPCTL_CMD_C1_COEFF ; 
 int B43_PHY_HT_TXPCTL_CMD_C1_HWPCTLEN ; 
 int B43_PHY_HT_TXPCTL_CMD_C1_INIT ; 
 int B43_PHY_HT_TXPCTL_CMD_C1_PCTLEN ; 
#define  B43_PHY_HT_TXPCTL_CMD_C2 136 
 int B43_PHY_HT_TXPCTL_CMD_C2_INIT ; 
#define  B43_PHY_HT_TXPCTL_CMD_C3 135 
 int B43_PHY_HT_TXPCTL_CMD_C3_INIT ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI2 ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI2_C3 ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI2_C3_SHIFT ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI_BINF ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI_C1 ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI_C1_SHIFT ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI_C2 ; 
 int B43_PHY_HT_TXPCTL_IDLE_TSSI_C2_SHIFT ; 
 int B43_PHY_HT_TXPCTL_N ; 
 int B43_PHY_HT_TXPCTL_N_NPTIL2 ; 
 int B43_PHY_HT_TXPCTL_N_NPTIL2_SHIFT ; 
 int B43_PHY_HT_TXPCTL_N_TSSID ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR2 ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR2_C3 ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR2_C3_SHIFT ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR_C1 ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR_C1_SHIFT ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR_C2 ; 
 int B43_PHY_HT_TXPCTL_TARG_PWR_C2_SHIFT ; 
#define  B43_PHY_HT_TX_PCTL_STATUS_C1 134 
#define  B43_PHY_HT_TX_PCTL_STATUS_C2 133 
#define  B43_PHY_HT_TX_PCTL_STATUS_C3 132 
 int const B43_PHY_N_BMODE (int) ; 
 int B43_PHY_OFDM (int) ; 
 int B43_PSM_HDR_MAC_PHY_FORCE_CLK ; 
 int B43_TXPWR_RES_DONE ; 
 int /*<<< orphan*/  B43_WARN_ON (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int ESRCH ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  HT_RSSI_TSSI_2G 131 
 scalar_t__ NL80211_BAND_2GHZ ; 
 scalar_t__ NL80211_BAND_5GHZ ; 
#define  R2059_C1 130 
#define  R2059_C2 129 
#define  R2059_C3 128 
 int const R2059_RCAL_CONFIG ; 
 int const R2059_RCAL_STATUS ; 
 int const R2059_RCCAL_DONE_OSCCAP ; 
 int R2059_RCCAL_MASTER ; 
 int const R2059_RCCAL_START_R1_Q1_P1 ; 
 int const R2059_RCCAL_TRC0 ; 
 int const R2059_RCCAL_X1 ; 
 int R2059_RFPLL_MASTER ; 
 int R2059_RFPLL_MISC_CAL_RESETN ; 
 int R2059_RFPLL_MISC_EN ; 
 int R2059_XTAL_CONFIG2 ; 
 int* b43_httab_0x1a_0xc0_late ; 
 void* b43_httab_read (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_httab_write (struct b43_wldev*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  b43_httab_write_bulk (struct b43_wldev*,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  b43_httab_write_few (struct b43_wldev*,int /*<<< orphan*/ ,int,int,int,...) ; 
 int /*<<< orphan*/  b43_mac_phy_clock_set (struct b43_wldev*,int) ; 
 int /*<<< orphan*/  b43_mac_switch_freq (struct b43_wldev*,int) ; 
 int /*<<< orphan*/  b43_phy_force_clock (struct b43_wldev*,int) ; 
 struct b43_phy_ht_channeltab_e_radio2059* b43_phy_ht_get_channeltab_e_r2059 (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_phy_ht_tables_init (struct b43_wldev*) ; 
 int /*<<< orphan*/  b43_phy_mask (struct b43_wldev*,int const,int) ; 
 int /*<<< orphan*/  b43_phy_maskset (struct b43_wldev*,int const,int,int) ; 
 int b43_phy_read (struct b43_wldev*,int const) ; 
 int /*<<< orphan*/  b43_phy_set (struct b43_wldev*,int const,int) ; 
 int /*<<< orphan*/  b43_phy_write (struct b43_wldev*,int const,int) ; 
 int /*<<< orphan*/  b43_radio_mask (struct b43_wldev*,int const,int) ; 
 int /*<<< orphan*/  b43_radio_maskset (struct b43_wldev*,int const,int,int) ; 
 int /*<<< orphan*/  b43_radio_set (struct b43_wldev*,int const,int) ; 
 int /*<<< orphan*/  b43_radio_wait_value (struct b43_wldev*,int const,int,int,int,int) ; 
 int /*<<< orphan*/  b43_radio_write (struct b43_wldev*,int const,int const) ; 
 int /*<<< orphan*/  b43_switch_channel (struct b43_wldev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  b43_wireless_core_phy_pll_reset (struct b43_wldev*) ; 
 int /*<<< orphan*/  b43err (struct b43_wl*,char*,...) ; 
 int /*<<< orphan*/  bcma_core_pll_ctl (struct bcma_device*,int,int,int) ; 
 int /*<<< orphan*/  bcma_pmu_spuravoid_pllupdate (int /*<<< orphan*/ *,int) ; 
 int cfg80211_get_chandef_type (TYPE_18__*) ; 
 struct ssb_device* dev_to_ssb_dev (struct device*) ; 
 int /*<<< orphan*/  kfree (struct b43_phy_ht*) ; 
 struct b43_phy_ht* kzalloc (int,int /*<<< orphan*/ ) ; 
 int max (int,int) ; 
 int /*<<< orphan*/  memset (struct b43_phy_ht*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  r2059_upload_inittabs (struct b43_wldev*) ; 
 struct b43_wldev* ssb_get_drvdata (struct ssb_device*) ; 
 int stub1 (TYPE_7__*) ; 
 int /*<<< orphan*/  stub10 (TYPE_7__*,void*,size_t,int,int) ; 
 int /*<<< orphan*/  stub11 (TYPE_7__*,void const*,size_t,int,int) ; 
 int stub2 (TYPE_7__*,int) ; 
 int stub3 (TYPE_7__*) ; 
 int /*<<< orphan*/  stub4 (TYPE_7__*,int) ; 
 int /*<<< orphan*/  stub5 (TYPE_7__*,int) ; 
 int stub6 (TYPE_7__*,int) ; 
 int /*<<< orphan*/  stub7 (TYPE_7__*,int,int) ; 
 int stub8 (TYPE_7__*,int) ; 
 int /*<<< orphan*/  stub9 (TYPE_7__*,int,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

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

__attribute__((used)) static void b43_radio_2059_channel_setup(struct b43_wldev *dev,
			const struct b43_phy_ht_channeltab_e_radio2059 *e)
{
	static const u16 routing[] = { R2059_C1, R2059_C2, R2059_C3, };
	u16 r;
	int core;

	b43_radio_write(dev, 0x16, e->radio_syn16);
	b43_radio_write(dev, 0x17, e->radio_syn17);
	b43_radio_write(dev, 0x22, e->radio_syn22);
	b43_radio_write(dev, 0x25, e->radio_syn25);
	b43_radio_write(dev, 0x27, e->radio_syn27);
	b43_radio_write(dev, 0x28, e->radio_syn28);
	b43_radio_write(dev, 0x29, e->radio_syn29);
	b43_radio_write(dev, 0x2c, e->radio_syn2c);
	b43_radio_write(dev, 0x2d, e->radio_syn2d);
	b43_radio_write(dev, 0x37, e->radio_syn37);
	b43_radio_write(dev, 0x41, e->radio_syn41);
	b43_radio_write(dev, 0x43, e->radio_syn43);
	b43_radio_write(dev, 0x47, e->radio_syn47);

	for (core = 0; core < 3; core++) {
		r = routing[core];
		b43_radio_write(dev, r | 0x4a, e->radio_rxtx4a);
		b43_radio_write(dev, r | 0x58, e->radio_rxtx58);
		b43_radio_write(dev, r | 0x5a, e->radio_rxtx5a);
		b43_radio_write(dev, r | 0x6a, e->radio_rxtx6a);
		b43_radio_write(dev, r | 0x6d, e->radio_rxtx6d);
		b43_radio_write(dev, r | 0x6e, e->radio_rxtx6e);
		b43_radio_write(dev, r | 0x92, e->radio_rxtx92);
		b43_radio_write(dev, r | 0x98, e->radio_rxtx98);
	}

	udelay(50);

	/* Calibration */
	b43_radio_mask(dev, R2059_RFPLL_MISC_EN, ~0x1);
	b43_radio_mask(dev, R2059_RFPLL_MISC_CAL_RESETN, ~0x4);
	b43_radio_set(dev, R2059_RFPLL_MISC_CAL_RESETN, 0x4);
	b43_radio_set(dev, R2059_RFPLL_MISC_EN, 0x1);

	udelay(300);
}

__attribute__((used)) static void b43_radio_2059_rcal(struct b43_wldev *dev)
{
	/* Enable */
	b43_radio_set(dev, R2059_C3 | R2059_RCAL_CONFIG, 0x1);
	usleep_range(10, 20);

	b43_radio_set(dev, R2059_C3 | 0x0BF, 0x1);
	b43_radio_maskset(dev, R2059_C3 | 0x19B, 0x3, 0x2);

	/* Start */
	b43_radio_set(dev, R2059_C3 | R2059_RCAL_CONFIG, 0x2);
	usleep_range(100, 200);

	/* Stop */
	b43_radio_mask(dev, R2059_C3 | R2059_RCAL_CONFIG, ~0x2);

	if (!b43_radio_wait_value(dev, R2059_C3 | R2059_RCAL_STATUS, 1, 1, 100,
				  1000000))
		b43err(dev->wl, "Radio 0x2059 rcal timeout\n");

	/* Disable */
	b43_radio_mask(dev, R2059_C3 | R2059_RCAL_CONFIG, ~0x1);

	b43_radio_set(dev, 0xa, 0x60);
}

__attribute__((used)) static void b43_radio_2057_rccal(struct b43_wldev *dev)
{
	static const u16 radio_values[3][2] = {
		{ 0x61, 0xE9 }, { 0x69, 0xD5 }, { 0x73, 0x99 },
	};
	int i;

	for (i = 0; i < 3; i++) {
		b43_radio_write(dev, R2059_RCCAL_MASTER, radio_values[i][0]);
		b43_radio_write(dev, R2059_RCCAL_X1, 0x6E);
		b43_radio_write(dev, R2059_RCCAL_TRC0, radio_values[i][1]);

		/* Start */
		b43_radio_write(dev, R2059_RCCAL_START_R1_Q1_P1, 0x55);

		/* Wait */
		if (!b43_radio_wait_value(dev, R2059_RCCAL_DONE_OSCCAP, 2, 2,
					  500, 5000000))
			b43err(dev->wl, "Radio 0x2059 rccal timeout\n");

		/* Stop */
		b43_radio_write(dev, R2059_RCCAL_START_R1_Q1_P1, 0x15);
	}

	b43_radio_mask(dev, R2059_RCCAL_MASTER, ~0x1);
}

__attribute__((used)) static void b43_radio_2059_init_pre(struct b43_wldev *dev)
{
	b43_phy_mask(dev, B43_PHY_HT_RF_CTL_CMD, ~B43_PHY_HT_RF_CTL_CMD_CHIP0_PU);
	b43_phy_set(dev, B43_PHY_HT_RF_CTL_CMD, B43_PHY_HT_RF_CTL_CMD_FORCE);
	b43_phy_mask(dev, B43_PHY_HT_RF_CTL_CMD, ~B43_PHY_HT_RF_CTL_CMD_FORCE);
	b43_phy_set(dev, B43_PHY_HT_RF_CTL_CMD, B43_PHY_HT_RF_CTL_CMD_CHIP0_PU);
}

__attribute__((used)) static void b43_radio_2059_init(struct b43_wldev *dev)
{
	static const u16 routing[] = { R2059_C1, R2059_C2, R2059_C3 };
	int i;

	/* Prepare (reset?) radio */
	b43_radio_2059_init_pre(dev);

	r2059_upload_inittabs(dev);

	for (i = 0; i < ARRAY_SIZE(routing); i++)
		b43_radio_set(dev, routing[i] | 0x146, 0x3);

	/* Post init starts below */

	b43_radio_set(dev, R2059_RFPLL_MISC_CAL_RESETN, 0x0078);
	b43_radio_set(dev, R2059_XTAL_CONFIG2, 0x0080);
	msleep(2);
	b43_radio_mask(dev, R2059_RFPLL_MISC_CAL_RESETN, ~0x0078);
	b43_radio_mask(dev, R2059_XTAL_CONFIG2, ~0x0080);

	if (1) { /* FIXME */
		b43_radio_2059_rcal(dev);
		b43_radio_2057_rccal(dev);
	}

	b43_radio_mask(dev, R2059_RFPLL_MASTER, ~0x0008);
}

__attribute__((used)) static void b43_phy_ht_force_rf_sequence(struct b43_wldev *dev, u16 rf_seq)
{
	u8 i;

	u16 save_seq_mode = b43_phy_read(dev, B43_PHY_HT_RF_SEQ_MODE);
	b43_phy_set(dev, B43_PHY_HT_RF_SEQ_MODE, 0x3);

	b43_phy_set(dev, B43_PHY_HT_RF_SEQ_TRIG, rf_seq);
	for (i = 0; i < 200; i++) {
		if (!(b43_phy_read(dev, B43_PHY_HT_RF_SEQ_STATUS) & rf_seq)) {
			i = 0;
			break;
		}
		msleep(1);
	}
	if (i)
		b43err(dev->wl, "Forcing RF sequence timeout\n");

	b43_phy_write(dev, B43_PHY_HT_RF_SEQ_MODE, save_seq_mode);
}

__attribute__((used)) static void b43_phy_ht_pa_override(struct b43_wldev *dev, bool enable)
{
	struct b43_phy_ht *htphy = dev->phy.ht;
	static const u16 regs[3] = { B43_PHY_HT_RF_CTL_INT_C1,
				     B43_PHY_HT_RF_CTL_INT_C2,
				     B43_PHY_HT_RF_CTL_INT_C3 };
	int i;

	if (enable) {
		for (i = 0; i < 3; i++)
			b43_phy_write(dev, regs[i], htphy->rf_ctl_int_save[i]);
	} else {
		for (i = 0; i < 3; i++)
			htphy->rf_ctl_int_save[i] = b43_phy_read(dev, regs[i]);
		/* TODO: Does 5GHz band use different value (not 0x0400)? */
		for (i = 0; i < 3; i++)
			b43_phy_write(dev, regs[i], 0x0400);
	}
}

__attribute__((used)) static u16 b43_phy_ht_classifier(struct b43_wldev *dev, u16 mask, u16 val)
{
	u16 tmp;
	u16 allowed = B43_PHY_HT_CLASS_CTL_CCK_EN |
		      B43_PHY_HT_CLASS_CTL_OFDM_EN |
		      B43_PHY_HT_CLASS_CTL_WAITED_EN;

	tmp = b43_phy_read(dev, B43_PHY_HT_CLASS_CTL);
	tmp &= allowed;
	tmp &= ~mask;
	tmp |= (val & mask);
	b43_phy_maskset(dev, B43_PHY_HT_CLASS_CTL, ~allowed, tmp);

	return tmp;
}

__attribute__((used)) static void b43_phy_ht_reset_cca(struct b43_wldev *dev)
{
	u16 bbcfg;

	b43_phy_force_clock(dev, true);
	bbcfg = b43_phy_read(dev, B43_PHY_HT_BBCFG);
	b43_phy_write(dev, B43_PHY_HT_BBCFG, bbcfg | B43_PHY_HT_BBCFG_RSTCCA);
	udelay(1);
	b43_phy_write(dev, B43_PHY_HT_BBCFG, bbcfg & ~B43_PHY_HT_BBCFG_RSTCCA);
	b43_phy_force_clock(dev, false);

	b43_phy_ht_force_rf_sequence(dev, B43_PHY_HT_RF_SEQ_TRIG_RST2RX);
}

__attribute__((used)) static void b43_phy_ht_zero_extg(struct b43_wldev *dev)
{
	u8 i, j;
	static const u16 base[] = { 0x40, 0x60, 0x80 };

	for (i = 0; i < ARRAY_SIZE(base); i++) {
		for (j = 0; j < 4; j++)
			b43_phy_write(dev, B43_PHY_EXTG(base[i] + j), 0);
	}

	for (i = 0; i < ARRAY_SIZE(base); i++)
		b43_phy_write(dev, B43_PHY_EXTG(base[i] + 0xc), 0);
}

__attribute__((used)) static void b43_phy_ht_afe_unk1(struct b43_wldev *dev)
{
	u8 i;

	static const u16 ctl_regs[3][2] = {
		{ B43_PHY_HT_AFE_C1_OVER, B43_PHY_HT_AFE_C1 },
		{ B43_PHY_HT_AFE_C2_OVER, B43_PHY_HT_AFE_C2 },
		{ B43_PHY_HT_AFE_C3_OVER, B43_PHY_HT_AFE_C3},
	};

	for (i = 0; i < 3; i++) {
		/* TODO: verify masks&sets */
		b43_phy_set(dev, ctl_regs[i][1], 0x4);
		b43_phy_set(dev, ctl_regs[i][0], 0x4);
		b43_phy_mask(dev, ctl_regs[i][1], ~0x1);
		b43_phy_set(dev, ctl_regs[i][0], 0x1);
		b43_httab_write(dev, B43_HTTAB16(8, 5 + (i * 0x10)), 0);
		b43_phy_mask(dev, ctl_regs[i][0], ~0x4);
	}
}

__attribute__((used)) static void b43_phy_ht_read_clip_detection(struct b43_wldev *dev, u16 *clip_st)
{
	clip_st[0] = b43_phy_read(dev, B43_PHY_HT_C1_CLIP1THRES);
	clip_st[1] = b43_phy_read(dev, B43_PHY_HT_C2_CLIP1THRES);
	clip_st[2] = b43_phy_read(dev, B43_PHY_HT_C3_CLIP1THRES);
}

__attribute__((used)) static void b43_phy_ht_bphy_init(struct b43_wldev *dev)
{
	unsigned int i;
	u16 val;

	val = 0x1E1F;
	for (i = 0; i < 16; i++) {
		b43_phy_write(dev, B43_PHY_N_BMODE(0x88 + i), val);
		val -= 0x202;
	}
	val = 0x3E3F;
	for (i = 0; i < 16; i++) {
		b43_phy_write(dev, B43_PHY_N_BMODE(0x98 + i), val);
		val -= 0x202;
	}
	b43_phy_write(dev, B43_PHY_N_BMODE(0x38), 0x668);
}

__attribute__((used)) static void b43_phy_ht_bphy_reset(struct b43_wldev *dev, bool reset)
{
	u16 tmp;

	tmp = b43_read16(dev, B43_MMIO_PSM_PHY_HDR);
	b43_write16(dev, B43_MMIO_PSM_PHY_HDR,
		    tmp | B43_PSM_HDR_MAC_PHY_FORCE_CLK);

	/* Put BPHY in or take it out of the reset */
	if (reset)
		b43_phy_set(dev, B43_PHY_B_BBCFG,
			    B43_PHY_B_BBCFG_RSTCCA | B43_PHY_B_BBCFG_RSTRX);
	else
		b43_phy_mask(dev, B43_PHY_B_BBCFG,
			     (u16)~(B43_PHY_B_BBCFG_RSTCCA |
				    B43_PHY_B_BBCFG_RSTRX));

	b43_write16(dev, B43_MMIO_PSM_PHY_HDR, tmp);
}

__attribute__((used)) static void b43_phy_ht_stop_playback(struct b43_wldev *dev)
{
	struct b43_phy_ht *phy_ht = dev->phy.ht;
	u16 tmp;
	int i;

	tmp = b43_phy_read(dev, B43_PHY_HT_SAMP_STAT);
	if (tmp & 0x1)
		b43_phy_set(dev, B43_PHY_HT_SAMP_CMD, B43_PHY_HT_SAMP_CMD_STOP);
	else if (tmp & 0x2)
		b43_phy_mask(dev, B43_PHY_HT_IQLOCAL_CMDGCTL, 0x7FFF);

	b43_phy_mask(dev, B43_PHY_HT_SAMP_CMD, ~0x0004);

	for (i = 0; i < 3; i++) {
		if (phy_ht->bb_mult_save[i] >= 0) {
			b43_httab_write(dev, B43_HTTAB16(13, 0x63 + i * 4),
					phy_ht->bb_mult_save[i]);
			b43_httab_write(dev, B43_HTTAB16(13, 0x67 + i * 4),
					phy_ht->bb_mult_save[i]);
		}
	}
}

__attribute__((used)) static u16 b43_phy_ht_load_samples(struct b43_wldev *dev)
{
	int i;
	u16 len = 20 << 3;

	b43_phy_write(dev, B43_PHY_HT_TABLE_ADDR, 0x4400);

	for (i = 0; i < len; i++) {
		b43_phy_write(dev, B43_PHY_HT_TABLE_DATAHI, 0);
		b43_phy_write(dev, B43_PHY_HT_TABLE_DATALO, 0);
	}

	return len;
}

__attribute__((used)) static void b43_phy_ht_run_samples(struct b43_wldev *dev, u16 samps, u16 loops,
				   u16 wait)
{
	struct b43_phy_ht *phy_ht = dev->phy.ht;
	u16 save_seq_mode;
	int i;

	for (i = 0; i < 3; i++) {
		if (phy_ht->bb_mult_save[i] < 0)
			phy_ht->bb_mult_save[i] = b43_httab_read(dev, B43_HTTAB16(13, 0x63 + i * 4));
	}

	b43_phy_write(dev, B43_PHY_HT_SAMP_DEP_CNT, samps - 1);
	if (loops != 0xFFFF)
		loops--;
	b43_phy_write(dev, B43_PHY_HT_SAMP_LOOP_CNT, loops);
	b43_phy_write(dev, B43_PHY_HT_SAMP_WAIT_CNT, wait);

	save_seq_mode = b43_phy_read(dev, B43_PHY_HT_RF_SEQ_MODE);
	b43_phy_set(dev, B43_PHY_HT_RF_SEQ_MODE,
		    B43_PHY_HT_RF_SEQ_MODE_CA_OVER);

	/* TODO: find out mask bits! Do we need more function arguments? */
	b43_phy_mask(dev, B43_PHY_HT_SAMP_CMD, ~0);
	b43_phy_mask(dev, B43_PHY_HT_SAMP_CMD, ~0);
	b43_phy_mask(dev, B43_PHY_HT_IQLOCAL_CMDGCTL, ~0);
	b43_phy_set(dev, B43_PHY_HT_SAMP_CMD, 0x1);

	for (i = 0; i < 100; i++) {
		if (!(b43_phy_read(dev, B43_PHY_HT_RF_SEQ_STATUS) & 1)) {
			i = 0;
			break;
		}
		udelay(10);
	}
	if (i)
		b43err(dev->wl, "run samples timeout\n");

	b43_phy_write(dev, B43_PHY_HT_RF_SEQ_MODE, save_seq_mode);
}

__attribute__((used)) static void b43_phy_ht_tx_tone(struct b43_wldev *dev)
{
	u16 samp;

	samp = b43_phy_ht_load_samples(dev);
	b43_phy_ht_run_samples(dev, samp, 0xFFFF, 0);
}

__attribute__((used)) static void b43_phy_ht_rssi_select(struct b43_wldev *dev, u8 core_sel,
				   enum ht_rssi_type rssi_type)
{
	static const u16 ctl_regs[3][2] = {
		{ B43_PHY_HT_AFE_C1, B43_PHY_HT_AFE_C1_OVER, },
		{ B43_PHY_HT_AFE_C2, B43_PHY_HT_AFE_C2_OVER, },
		{ B43_PHY_HT_AFE_C3, B43_PHY_HT_AFE_C3_OVER, },
	};
	static const u16 radio_r[] = { R2059_C1, R2059_C2, R2059_C3, };
	int core;

	if (core_sel == 0) {
		b43err(dev->wl, "RSSI selection for core off not implemented yet\n");
	} else {
		for (core = 0; core < 3; core++) {
			/* Check if caller requested a one specific core */
			if ((core_sel == 1 && core != 0) ||
			    (core_sel == 2 && core != 1) ||
			    (core_sel == 3 && core != 2))
				continue;

			switch (rssi_type) {
			case HT_RSSI_TSSI_2G:
				b43_phy_set(dev, ctl_regs[core][0], 0x3 << 8);
				b43_phy_set(dev, ctl_regs[core][0], 0x3 << 10);
				b43_phy_set(dev, ctl_regs[core][1], 0x1 << 9);
				b43_phy_set(dev, ctl_regs[core][1], 0x1 << 10);

				b43_radio_set(dev, R2059_C3 | 0xbf, 0x1);
				b43_radio_write(dev, radio_r[core] | 0x159,
						0x11);
				break;
			default:
				b43err(dev->wl, "RSSI selection for type %d not implemented yet\n",
				       rssi_type);
			}
		}
	}
}

__attribute__((used)) static void b43_phy_ht_poll_rssi(struct b43_wldev *dev, enum ht_rssi_type type,
				 s32 *buf, u8 nsamp)
{
	u16 phy_regs_values[12];
	static const u16 phy_regs_to_save[] = {
		B43_PHY_HT_AFE_C1, B43_PHY_HT_AFE_C1_OVER,
		0x848, 0x841,
		B43_PHY_HT_AFE_C2, B43_PHY_HT_AFE_C2_OVER,
		0x868, 0x861,
		B43_PHY_HT_AFE_C3, B43_PHY_HT_AFE_C3_OVER,
		0x888, 0x881,
	};
	u16 tmp[3];
	int i;

	for (i = 0; i < 12; i++)
		phy_regs_values[i] = b43_phy_read(dev, phy_regs_to_save[i]);

	b43_phy_ht_rssi_select(dev, 5, type);

	for (i = 0; i < 6; i++)
		buf[i] = 0;

	for (i = 0; i < nsamp; i++) {
		tmp[0] = b43_phy_read(dev, B43_PHY_HT_RSSI_C1);
		tmp[1] = b43_phy_read(dev, B43_PHY_HT_RSSI_C2);
		tmp[2] = b43_phy_read(dev, B43_PHY_HT_RSSI_C3);

		buf[0] += ((s8)((tmp[0] & 0x3F) << 2)) >> 2;
		buf[1] += ((s8)(((tmp[0] >> 8) & 0x3F) << 2)) >> 2;
		buf[2] += ((s8)((tmp[1] & 0x3F) << 2)) >> 2;
		buf[3] += ((s8)(((tmp[1] >> 8) & 0x3F) << 2)) >> 2;
		buf[4] += ((s8)((tmp[2] & 0x3F) << 2)) >> 2;
		buf[5] += ((s8)(((tmp[2] >> 8) & 0x3F) << 2)) >> 2;
	}

	for (i = 0; i < 12; i++)
		b43_phy_write(dev, phy_regs_to_save[i], phy_regs_values[i]);
}

__attribute__((used)) static void b43_phy_ht_tx_power_fix(struct b43_wldev *dev)
{
	int i;

	for (i = 0; i < 3; i++) {
		u16 mask;
		u32 tmp = b43_httab_read(dev, B43_HTTAB32(26, 0xE8));

		if (0) /* FIXME */
			mask = 0x2 << (i * 4);
		else
			mask = 0;
		b43_phy_mask(dev, B43_PHY_EXTG(0x108), mask);

		b43_httab_write(dev, B43_HTTAB16(7, 0x110 + i), tmp >> 16);
		b43_httab_write(dev, B43_HTTAB8(13, 0x63 + (i * 4)),
				tmp & 0xFF);
		b43_httab_write(dev, B43_HTTAB8(13, 0x73 + (i * 4)),
				tmp & 0xFF);
	}
}

__attribute__((used)) static void b43_phy_ht_tx_power_ctl(struct b43_wldev *dev, bool enable)
{
	struct b43_phy_ht *phy_ht = dev->phy.ht;
	u16 en_bits = B43_PHY_HT_TXPCTL_CMD_C1_COEFF |
		      B43_PHY_HT_TXPCTL_CMD_C1_HWPCTLEN |
		      B43_PHY_HT_TXPCTL_CMD_C1_PCTLEN;
	static const u16 cmd_regs[3] = { B43_PHY_HT_TXPCTL_CMD_C1,
					 B43_PHY_HT_TXPCTL_CMD_C2,
					 B43_PHY_HT_TXPCTL_CMD_C3 };
	static const u16 status_regs[3] = { B43_PHY_HT_TX_PCTL_STATUS_C1,
					    B43_PHY_HT_TX_PCTL_STATUS_C2,
					    B43_PHY_HT_TX_PCTL_STATUS_C3 };
	int i;

	if (!enable) {
		if (b43_phy_read(dev, B43_PHY_HT_TXPCTL_CMD_C1) & en_bits) {
			/* We disable enabled TX pwr ctl, save it's state */
			for (i = 0; i < 3; i++)
				phy_ht->tx_pwr_idx[i] =
					b43_phy_read(dev, status_regs[i]);
		}
		b43_phy_mask(dev, B43_PHY_HT_TXPCTL_CMD_C1, ~en_bits);
	} else {
		b43_phy_set(dev, B43_PHY_HT_TXPCTL_CMD_C1, en_bits);

		if (b43_current_band(dev->wl) == NL80211_BAND_5GHZ) {
			for (i = 0; i < 3; i++)
				b43_phy_write(dev, cmd_regs[i], 0x32);
		}

		for (i = 0; i < 3; i++)
			if (phy_ht->tx_pwr_idx[i] <=
			    B43_PHY_HT_TXPCTL_CMD_C1_INIT)
				b43_phy_write(dev, cmd_regs[i],
					      phy_ht->tx_pwr_idx[i]);
	}

	phy_ht->tx_pwr_ctl = enable;
}

__attribute__((used)) static void b43_phy_ht_tx_power_ctl_idle_tssi(struct b43_wldev *dev)
{
	struct b43_phy_ht *phy_ht = dev->phy.ht;
	static const u16 base[] = { 0x840, 0x860, 0x880 };
	u16 save_regs[3][3];
	s32 rssi_buf[6];
	int core;

	for (core = 0; core < 3; core++) {
		save_regs[core][1] = b43_phy_read(dev, base[core] + 6);
		save_regs[core][2] = b43_phy_read(dev, base[core] + 7);
		save_regs[core][0] = b43_phy_read(dev, base[core] + 0);

		b43_phy_write(dev, base[core] + 6, 0);
		b43_phy_mask(dev, base[core] + 7, ~0xF); /* 0xF? Or just 0x6? */
		b43_phy_set(dev, base[core] + 0, 0x0400);
		b43_phy_set(dev, base[core] + 0, 0x1000);
	}

	b43_phy_ht_tx_tone(dev);
	udelay(20);
	b43_phy_ht_poll_rssi(dev, HT_RSSI_TSSI_2G, rssi_buf, 1);
	b43_phy_ht_stop_playback(dev);
	b43_phy_ht_reset_cca(dev);

	phy_ht->idle_tssi[0] = rssi_buf[0] & 0xff;
	phy_ht->idle_tssi[1] = rssi_buf[2] & 0xff;
	phy_ht->idle_tssi[2] = rssi_buf[4] & 0xff;

	for (core = 0; core < 3; core++) {
		b43_phy_write(dev, base[core] + 0, save_regs[core][0]);
		b43_phy_write(dev, base[core] + 6, save_regs[core][1]);
		b43_phy_write(dev, base[core] + 7, save_regs[core][2]);
	}
}

__attribute__((used)) static void b43_phy_ht_tssi_setup(struct b43_wldev *dev)
{
	static const u16 routing[] = { R2059_C1, R2059_C2, R2059_C3, };
	int core;

	/* 0x159 is probably TX_SSI_MUX or TSSIG (by comparing to N-PHY) */
	for (core = 0; core < 3; core++) {
		b43_radio_set(dev, 0x8bf, 0x1);
		b43_radio_write(dev, routing[core] | 0x0159, 0x0011);
	}
}

__attribute__((used)) static void b43_phy_ht_tx_power_ctl_setup(struct b43_wldev *dev)
{
	struct b43_phy_ht *phy_ht = dev->phy.ht;
	struct ssb_sprom *sprom = dev->dev->bus_sprom;

	u8 *idle = phy_ht->idle_tssi;
	u8 target[3];
	s16 a1[3], b0[3], b1[3];

	u16 freq = dev->phy.chandef->chan->center_freq;
	int i, c;

	if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ) {
		for (c = 0; c < 3; c++) {
			target[c] = sprom->core_pwr_info[c].maxpwr_2g;
			a1[c] = sprom->core_pwr_info[c].pa_2g[0];
			b0[c] = sprom->core_pwr_info[c].pa_2g[1];
			b1[c] = sprom->core_pwr_info[c].pa_2g[2];
		}
	} else if (freq >= 4900 && freq < 5100) {
		for (c = 0; c < 3; c++) {
			target[c] = sprom->core_pwr_info[c].maxpwr_5gl;
			a1[c] = sprom->core_pwr_info[c].pa_5gl[0];
			b0[c] = sprom->core_pwr_info[c].pa_5gl[1];
			b1[c] = sprom->core_pwr_info[c].pa_5gl[2];
		}
	} else if (freq >= 5100 && freq < 5500) {
		for (c = 0; c < 3; c++) {
			target[c] = sprom->core_pwr_info[c].maxpwr_5g;
			a1[c] = sprom->core_pwr_info[c].pa_5g[0];
			b0[c] = sprom->core_pwr_info[c].pa_5g[1];
			b1[c] = sprom->core_pwr_info[c].pa_5g[2];
		}
	} else if (freq >= 5500) {
		for (c = 0; c < 3; c++) {
			target[c] = sprom->core_pwr_info[c].maxpwr_5gh;
			a1[c] = sprom->core_pwr_info[c].pa_5gh[0];
			b0[c] = sprom->core_pwr_info[c].pa_5gh[1];
			b1[c] = sprom->core_pwr_info[c].pa_5gh[2];
		}
	} else {
		target[0] = target[1] = target[2] = 52;
		a1[0] = a1[1] = a1[2] = -424;
		b0[0] = b0[1] = b0[2] = 5612;
		b1[0] = b1[1] = b1[2] = -1393;
	}

	b43_phy_set(dev, B43_PHY_HT_TSSIMODE, B43_PHY_HT_TSSIMODE_EN);
	b43_phy_mask(dev, B43_PHY_HT_TXPCTL_CMD_C1,
		     ~B43_PHY_HT_TXPCTL_CMD_C1_PCTLEN & 0xFFFF);

	/* TODO: Does it depend on sprom->fem.ghz2.tssipos? */
	b43_phy_set(dev, B43_PHY_HT_TXPCTL_IDLE_TSSI, 0x4000);

	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_CMD_C1,
			~B43_PHY_HT_TXPCTL_CMD_C1_INIT, 0x19);
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_CMD_C2,
			~B43_PHY_HT_TXPCTL_CMD_C2_INIT, 0x19);
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_CMD_C3,
			~B43_PHY_HT_TXPCTL_CMD_C3_INIT, 0x19);

	b43_phy_set(dev, B43_PHY_HT_TXPCTL_IDLE_TSSI,
		    B43_PHY_HT_TXPCTL_IDLE_TSSI_BINF);

	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_IDLE_TSSI,
			~B43_PHY_HT_TXPCTL_IDLE_TSSI_C1,
			idle[0] << B43_PHY_HT_TXPCTL_IDLE_TSSI_C1_SHIFT);
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_IDLE_TSSI,
			~B43_PHY_HT_TXPCTL_IDLE_TSSI_C2,
			idle[1] << B43_PHY_HT_TXPCTL_IDLE_TSSI_C2_SHIFT);
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_IDLE_TSSI2,
			~B43_PHY_HT_TXPCTL_IDLE_TSSI2_C3,
			idle[2] << B43_PHY_HT_TXPCTL_IDLE_TSSI2_C3_SHIFT);

	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_N, ~B43_PHY_HT_TXPCTL_N_TSSID,
			0xf0);
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_N, ~B43_PHY_HT_TXPCTL_N_NPTIL2,
			0x3 << B43_PHY_HT_TXPCTL_N_NPTIL2_SHIFT);
#if 0
	/* TODO: what to mask/set? */
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_CMD_C1, 0x800, 0)
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_CMD_C1, 0x400, 0)
#endif

	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_TARG_PWR,
			~B43_PHY_HT_TXPCTL_TARG_PWR_C1,
			target[0] << B43_PHY_HT_TXPCTL_TARG_PWR_C1_SHIFT);
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_TARG_PWR,
			~B43_PHY_HT_TXPCTL_TARG_PWR_C2 & 0xFFFF,
			target[1] << B43_PHY_HT_TXPCTL_TARG_PWR_C2_SHIFT);
	b43_phy_maskset(dev, B43_PHY_HT_TXPCTL_TARG_PWR2,
			~B43_PHY_HT_TXPCTL_TARG_PWR2_C3,
			target[2] << B43_PHY_HT_TXPCTL_TARG_PWR2_C3_SHIFT);

	for (c = 0; c < 3; c++) {
		s32 num, den, pwr;
		u32 regval[64];

		for (i = 0; i < 64; i++) {
			num = 8 * (16 * b0[c] + b1[c] * i);
			den = 32768 + a1[c] * i;
			pwr = max((4 * num + den / 2) / den, -8);
			regval[i] = pwr;
		}
		b43_httab_write_bulk(dev, B43_HTTAB16(26 + c, 0), 64, regval);
	}
}

__attribute__((used)) static void b43_phy_ht_spur_avoid(struct b43_wldev *dev,
				  struct ieee80211_channel *new_channel)
{
	struct bcma_device *core = dev->dev->bdev;
	int spuravoid = 0;

	/* Check for 13 and 14 is just a guess, we don't have enough logs. */
	if (new_channel->hw_value == 13 || new_channel->hw_value == 14)
		spuravoid = 1;
	bcma_core_pll_ctl(core, B43_BCMA_CLKCTLST_PHY_PLL_REQ, 0, false);
	bcma_pmu_spuravoid_pllupdate(&core->bus->drv_cc, spuravoid);
	bcma_core_pll_ctl(core,
			  B43_BCMA_CLKCTLST_80211_PLL_REQ |
			  B43_BCMA_CLKCTLST_PHY_PLL_REQ,
			  B43_BCMA_CLKCTLST_80211_PLL_ST |
			  B43_BCMA_CLKCTLST_PHY_PLL_ST, false);

	b43_mac_switch_freq(dev, spuravoid);

	b43_wireless_core_phy_pll_reset(dev);

	if (spuravoid)
		b43_phy_set(dev, B43_PHY_HT_BBCFG, B43_PHY_HT_BBCFG_RSTRX);
	else
		b43_phy_mask(dev, B43_PHY_HT_BBCFG,
				~B43_PHY_HT_BBCFG_RSTRX & 0xFFFF);

	b43_phy_ht_reset_cca(dev);
}

__attribute__((used)) static void b43_phy_ht_channel_setup(struct b43_wldev *dev,
				const struct b43_phy_ht_channeltab_e_phy *e,
				struct ieee80211_channel *new_channel)
{
	if (new_channel->band == NL80211_BAND_5GHZ) {
		/* Switch to 2 GHz for a moment to access B-PHY regs */
		b43_phy_mask(dev, B43_PHY_HT_BANDCTL, ~B43_PHY_HT_BANDCTL_5GHZ);

		b43_phy_ht_bphy_reset(dev, true);

		/* Switch to 5 GHz */
		b43_phy_set(dev, B43_PHY_HT_BANDCTL, B43_PHY_HT_BANDCTL_5GHZ);
	} else {
		/* Switch to 2 GHz */
		b43_phy_mask(dev, B43_PHY_HT_BANDCTL, ~B43_PHY_HT_BANDCTL_5GHZ);

		b43_phy_ht_bphy_reset(dev, false);
	}

	b43_phy_write(dev, B43_PHY_HT_BW1, e->bw1);
	b43_phy_write(dev, B43_PHY_HT_BW2, e->bw2);
	b43_phy_write(dev, B43_PHY_HT_BW3, e->bw3);
	b43_phy_write(dev, B43_PHY_HT_BW4, e->bw4);
	b43_phy_write(dev, B43_PHY_HT_BW5, e->bw5);
	b43_phy_write(dev, B43_PHY_HT_BW6, e->bw6);

	if (new_channel->hw_value == 14) {
		b43_phy_ht_classifier(dev, B43_PHY_HT_CLASS_CTL_OFDM_EN, 0);
		b43_phy_set(dev, B43_PHY_HT_TEST, 0x0800);
	} else {
		b43_phy_ht_classifier(dev, B43_PHY_HT_CLASS_CTL_OFDM_EN,
				      B43_PHY_HT_CLASS_CTL_OFDM_EN);
		if (new_channel->band == NL80211_BAND_2GHZ)
			b43_phy_mask(dev, B43_PHY_HT_TEST, ~0x840);
	}

	if (1) /* TODO: On N it's for early devices only, what about HT? */
		b43_phy_ht_tx_power_fix(dev);

	b43_phy_ht_spur_avoid(dev, new_channel);

	b43_phy_write(dev, 0x017e, 0x3830);
}

__attribute__((used)) static int b43_phy_ht_set_channel(struct b43_wldev *dev,
				  struct ieee80211_channel *channel,
				  enum nl80211_channel_type channel_type)
{
	struct b43_phy *phy = &dev->phy;

	const struct b43_phy_ht_channeltab_e_radio2059 *chent_r2059 = NULL;

	if (phy->radio_ver == 0x2059) {
		chent_r2059 = b43_phy_ht_get_channeltab_e_r2059(dev,
							channel->center_freq);
		if (!chent_r2059)
			return -ESRCH;
	} else {
		return -ESRCH;
	}

	/* TODO: In case of N-PHY some bandwidth switching goes here */

	if (phy->radio_ver == 0x2059) {
		b43_radio_2059_channel_setup(dev, chent_r2059);
		b43_phy_ht_channel_setup(dev, &(chent_r2059->phy_regs),
					 channel);
	} else {
		return -ESRCH;
	}

	return 0;
}

__attribute__((used)) static int b43_phy_ht_op_allocate(struct b43_wldev *dev)
{
	struct b43_phy_ht *phy_ht;

	phy_ht = kzalloc(sizeof(*phy_ht), GFP_KERNEL);
	if (!phy_ht)
		return -ENOMEM;
	dev->phy.ht = phy_ht;

	return 0;
}

__attribute__((used)) static void b43_phy_ht_op_prepare_structs(struct b43_wldev *dev)
{
	struct b43_phy *phy = &dev->phy;
	struct b43_phy_ht *phy_ht = phy->ht;
	int i;

	memset(phy_ht, 0, sizeof(*phy_ht));

	phy_ht->tx_pwr_ctl = true;
	for (i = 0; i < 3; i++)
		phy_ht->tx_pwr_idx[i] = B43_PHY_HT_TXPCTL_CMD_C1_INIT + 1;

	for (i = 0; i < 3; i++)
		phy_ht->bb_mult_save[i] = -1;
}

__attribute__((used)) static int b43_phy_ht_op_init(struct b43_wldev *dev)
{
	struct b43_phy_ht *phy_ht = dev->phy.ht;
	u16 tmp;
	u16 clip_state[3];
	bool saved_tx_pwr_ctl;

	if (dev->dev->bus_type != B43_BUS_BCMA) {
		b43err(dev->wl, "HT-PHY is supported only on BCMA bus!\n");
		return -EOPNOTSUPP;
	}

	b43_phy_ht_tables_init(dev);

	b43_phy_mask(dev, 0x0be, ~0x2);
	b43_phy_set(dev, 0x23f, 0x7ff);
	b43_phy_set(dev, 0x240, 0x7ff);
	b43_phy_set(dev, 0x241, 0x7ff);

	b43_phy_ht_zero_extg(dev);

	b43_phy_mask(dev, B43_PHY_EXTG(0), ~0x3);

	b43_phy_write(dev, B43_PHY_HT_AFE_C1_OVER, 0);
	b43_phy_write(dev, B43_PHY_HT_AFE_C2_OVER, 0);
	b43_phy_write(dev, B43_PHY_HT_AFE_C3_OVER, 0);

	b43_phy_write(dev, B43_PHY_EXTG(0x103), 0x20);
	b43_phy_write(dev, B43_PHY_EXTG(0x101), 0x20);
	b43_phy_write(dev, 0x20d, 0xb8);
	b43_phy_write(dev, B43_PHY_EXTG(0x14f), 0xc8);
	b43_phy_write(dev, 0x70, 0x50);
	b43_phy_write(dev, 0x1ff, 0x30);

	if (0) /* TODO: condition */
		; /* TODO: PHY op on reg 0x217 */

	if (b43_current_band(dev->wl) == NL80211_BAND_5GHZ)
		b43_phy_ht_classifier(dev, B43_PHY_HT_CLASS_CTL_CCK_EN, 0);
	else
		b43_phy_ht_classifier(dev, B43_PHY_HT_CLASS_CTL_CCK_EN,
				      B43_PHY_HT_CLASS_CTL_CCK_EN);

	b43_phy_set(dev, 0xb1, 0x91);
	b43_phy_write(dev, 0x32f, 0x0003);
	b43_phy_write(dev, 0x077, 0x0010);
	b43_phy_write(dev, 0x0b4, 0x0258);
	b43_phy_mask(dev, 0x17e, ~0x4000);

	b43_phy_write(dev, 0x0b9, 0x0072);

	b43_httab_write_few(dev, B43_HTTAB16(7, 0x14e), 2, 0x010f, 0x010f);
	b43_httab_write_few(dev, B43_HTTAB16(7, 0x15e), 2, 0x010f, 0x010f);
	b43_httab_write_few(dev, B43_HTTAB16(7, 0x16e), 2, 0x010f, 0x010f);

	b43_phy_ht_afe_unk1(dev);

	b43_httab_write_few(dev, B43_HTTAB16(7, 0x130), 9, 0x777, 0x111, 0x111,
			    0x777, 0x111, 0x111, 0x777, 0x111, 0x111);

	b43_httab_write(dev, B43_HTTAB16(7, 0x120), 0x0777);
	b43_httab_write(dev, B43_HTTAB16(7, 0x124), 0x0777);

	b43_httab_write(dev, B43_HTTAB16(8, 0x00), 0x02);
	b43_httab_write(dev, B43_HTTAB16(8, 0x10), 0x02);
	b43_httab_write(dev, B43_HTTAB16(8, 0x20), 0x02);

	b43_httab_write_few(dev, B43_HTTAB16(8, 0x08), 4,
			    0x8e, 0x96, 0x96, 0x96);
	b43_httab_write_few(dev, B43_HTTAB16(8, 0x18), 4,
			    0x8f, 0x9f, 0x9f, 0x9f);
	b43_httab_write_few(dev, B43_HTTAB16(8, 0x28), 4,
			    0x8f, 0x9f, 0x9f, 0x9f);

	b43_httab_write_few(dev, B43_HTTAB16(8, 0x0c), 4, 0x2, 0x2, 0x2, 0x2);
	b43_httab_write_few(dev, B43_HTTAB16(8, 0x1c), 4, 0x2, 0x2, 0x2, 0x2);
	b43_httab_write_few(dev, B43_HTTAB16(8, 0x2c), 4, 0x2, 0x2, 0x2, 0x2);

	b43_phy_maskset(dev, 0x0280, 0xff00, 0x3e);
	b43_phy_maskset(dev, 0x0283, 0xff00, 0x3e);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x0141), 0xff00, 0x46);
	b43_phy_maskset(dev, 0x0283, 0xff00, 0x40);

	b43_httab_write_few(dev, B43_HTTAB16(00, 0x8), 4,
			    0x09, 0x0e, 0x13, 0x18);
	b43_httab_write_few(dev, B43_HTTAB16(01, 0x8), 4,
			    0x09, 0x0e, 0x13, 0x18);
	/* TODO: Did wl mean 2 instead of 40? */
	b43_httab_write_few(dev, B43_HTTAB16(40, 0x8), 4,
			    0x09, 0x0e, 0x13, 0x18);

	b43_phy_maskset(dev, B43_PHY_OFDM(0x24), 0x3f, 0xd);
	b43_phy_maskset(dev, B43_PHY_OFDM(0x64), 0x3f, 0xd);
	b43_phy_maskset(dev, B43_PHY_OFDM(0xa4), 0x3f, 0xd);

	b43_phy_set(dev, B43_PHY_EXTG(0x060), 0x1);
	b43_phy_set(dev, B43_PHY_EXTG(0x064), 0x1);
	b43_phy_set(dev, B43_PHY_EXTG(0x080), 0x1);
	b43_phy_set(dev, B43_PHY_EXTG(0x084), 0x1);

	/* Copy some tables entries */
	tmp = b43_httab_read(dev, B43_HTTAB16(7, 0x144));
	b43_httab_write(dev, B43_HTTAB16(7, 0x14a), tmp);
	tmp = b43_httab_read(dev, B43_HTTAB16(7, 0x154));
	b43_httab_write(dev, B43_HTTAB16(7, 0x15a), tmp);
	tmp = b43_httab_read(dev, B43_HTTAB16(7, 0x164));
	b43_httab_write(dev, B43_HTTAB16(7, 0x16a), tmp);

	/* Reset CCA */
	b43_phy_force_clock(dev, true);
	tmp = b43_phy_read(dev, B43_PHY_HT_BBCFG);
	b43_phy_write(dev, B43_PHY_HT_BBCFG, tmp | B43_PHY_HT_BBCFG_RSTCCA);
	b43_phy_write(dev, B43_PHY_HT_BBCFG, tmp & ~B43_PHY_HT_BBCFG_RSTCCA);
	b43_phy_force_clock(dev, false);

	b43_mac_phy_clock_set(dev, true);

	b43_phy_ht_pa_override(dev, false);
	b43_phy_ht_force_rf_sequence(dev, B43_PHY_HT_RF_SEQ_TRIG_RX2TX);
	b43_phy_ht_force_rf_sequence(dev, B43_PHY_HT_RF_SEQ_TRIG_RST2RX);
	b43_phy_ht_pa_override(dev, true);

	/* TODO: Should we restore it? Or store it in global PHY info? */
	b43_phy_ht_classifier(dev, 0, 0);
	b43_phy_ht_read_clip_detection(dev, clip_state);

	if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
		b43_phy_ht_bphy_init(dev);

	b43_httab_write_bulk(dev, B43_HTTAB32(0x1a, 0xc0),
			B43_HTTAB_1A_C0_LATE_SIZE, b43_httab_0x1a_0xc0_late);

	saved_tx_pwr_ctl = phy_ht->tx_pwr_ctl;
	b43_phy_ht_tx_power_fix(dev);
	b43_phy_ht_tx_power_ctl(dev, false);
	b43_phy_ht_tx_power_ctl_idle_tssi(dev);
	b43_phy_ht_tx_power_ctl_setup(dev);
	b43_phy_ht_tssi_setup(dev);
	b43_phy_ht_tx_power_ctl(dev, saved_tx_pwr_ctl);

	return 0;
}

__attribute__((used)) static void b43_phy_ht_op_free(struct b43_wldev *dev)
{
	struct b43_phy *phy = &dev->phy;
	struct b43_phy_ht *phy_ht = phy->ht;

	kfree(phy_ht);
	phy->ht = NULL;
}

__attribute__((used)) static void b43_phy_ht_op_software_rfkill(struct b43_wldev *dev,
					bool blocked)
{
	if (b43_read32(dev, B43_MMIO_MACCTL) & B43_MACCTL_ENABLED)
		b43err(dev->wl, "MAC not suspended\n");

	if (blocked) {
		b43_phy_mask(dev, B43_PHY_HT_RF_CTL_CMD,
			     ~B43_PHY_HT_RF_CTL_CMD_CHIP0_PU);
	} else {
		if (dev->phy.radio_ver == 0x2059)
			b43_radio_2059_init(dev);
		else
			B43_WARN_ON(1);

		b43_switch_channel(dev, dev->phy.channel);
	}
}

__attribute__((used)) static void b43_phy_ht_op_switch_analog(struct b43_wldev *dev, bool on)
{
	if (on) {
		b43_phy_write(dev, B43_PHY_HT_AFE_C1, 0x00cd);
		b43_phy_write(dev, B43_PHY_HT_AFE_C1_OVER, 0x0000);
		b43_phy_write(dev, B43_PHY_HT_AFE_C2, 0x00cd);
		b43_phy_write(dev, B43_PHY_HT_AFE_C2_OVER, 0x0000);
		b43_phy_write(dev, B43_PHY_HT_AFE_C3, 0x00cd);
		b43_phy_write(dev, B43_PHY_HT_AFE_C3_OVER, 0x0000);
	} else {
		b43_phy_write(dev, B43_PHY_HT_AFE_C1_OVER, 0x07ff);
		b43_phy_write(dev, B43_PHY_HT_AFE_C1, 0x00fd);
		b43_phy_write(dev, B43_PHY_HT_AFE_C2_OVER, 0x07ff);
		b43_phy_write(dev, B43_PHY_HT_AFE_C2, 0x00fd);
		b43_phy_write(dev, B43_PHY_HT_AFE_C3_OVER, 0x07ff);
		b43_phy_write(dev, B43_PHY_HT_AFE_C3, 0x00fd);
	}
}

__attribute__((used)) static int b43_phy_ht_op_switch_channel(struct b43_wldev *dev,
					unsigned int new_channel)
{
	struct ieee80211_channel *channel = dev->wl->hw->conf.chandef.chan;
	enum nl80211_channel_type channel_type =
		cfg80211_get_chandef_type(&dev->wl->hw->conf.chandef);

	if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ) {
		if ((new_channel < 1) || (new_channel > 14))
			return -EINVAL;
	} else {
		return -EINVAL;
	}

	return b43_phy_ht_set_channel(dev, channel, channel_type);
}

__attribute__((used)) static unsigned int b43_phy_ht_op_get_default_chan(struct b43_wldev *dev)
{
	if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
		return 11;
	return 36;
}

__attribute__((used)) static void b43_phy_ht_op_maskset(struct b43_wldev *dev, u16 reg, u16 mask,
				 u16 set)
{
	b43_write16f(dev, B43_MMIO_PHY_CONTROL, reg);
	b43_write16(dev, B43_MMIO_PHY_DATA,
		    (b43_read16(dev, B43_MMIO_PHY_DATA) & mask) | set);
}

__attribute__((used)) static u16 b43_phy_ht_op_radio_read(struct b43_wldev *dev, u16 reg)
{
	/* HT-PHY needs 0x200 for read access */
	reg |= 0x200;

	b43_write16f(dev, B43_MMIO_RADIO24_CONTROL, reg);
	return b43_read16(dev, B43_MMIO_RADIO24_DATA);
}

__attribute__((used)) static void b43_phy_ht_op_radio_write(struct b43_wldev *dev, u16 reg,
				      u16 value)
{
	b43_write16f(dev, B43_MMIO_RADIO24_CONTROL, reg);
	b43_write16(dev, B43_MMIO_RADIO24_DATA, value);
}

__attribute__((used)) static enum b43_txpwr_result
b43_phy_ht_op_recalc_txpower(struct b43_wldev *dev, bool ignore_tssi)
{
	return B43_TXPWR_RES_DONE;
}

__attribute__((used)) static void b43_phy_ht_op_adjust_txpower(struct b43_wldev *dev)
{
}

