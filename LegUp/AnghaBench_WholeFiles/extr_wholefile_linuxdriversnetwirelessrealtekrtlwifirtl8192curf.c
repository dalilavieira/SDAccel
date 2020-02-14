#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {scalar_t__ data; } ;
struct rtlwifi_tx_info {int dummy; } ;
struct rtl_phy {int rf_type; int* rfreg_chnlval; int** mcs_offset; int const current_chan_bw; int pwrgroup_cnt; int num_total_rfpath; struct bb_reg_def* phyreg_def; } ;
struct TYPE_10__ {scalar_t__ dynamic_txhighpower_lvl; } ;
struct TYPE_7__ {int (* read8_sync ) (struct rtl_priv*,int) ;int (* read16_sync ) (struct rtl_priv*,int) ;int (* read32_sync ) (struct rtl_priv*,int) ;int /*<<< orphan*/  (* write32_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write16_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write8_async ) (struct rtl_priv*,int,int) ;} ;
struct rtl_priv {struct rtl_phy phy; TYPE_5__ dm; TYPE_4__* cfg; TYPE_2__ io; } ;
struct rtl_mac {scalar_t__ mode; scalar_t__ act_scanning; struct ieee80211_vif* vif; } ;
struct rtl_hal {scalar_t__ state; } ;
struct rtl_efuse {scalar_t__ eeprom_regulatory; int** txpwr_legacyhtdiff; int** txpwr_ht20diff; int** pwrgroup_ht40; int** pwrgroup_ht20; scalar_t__ external_pa; } ;
struct ieee80211_vif {int dummy; } ;
struct TYPE_6__ {scalar_t__ status_driver_data; } ;
struct ieee80211_tx_info {TYPE_1__ status; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hw {struct rtl_priv* priv; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
struct bb_reg_def {int rfintfs; int rfintfe; int rfintfo; int rfhssi_para2; } ;
typedef  enum radio_path { ____Placeholder_radio_path } radio_path ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_9__ {TYPE_3__* ops; scalar_t__ write_readback; } ;
struct TYPE_8__ {int (* get_bbreg ) (struct ieee80211_hw*,int,int) ;int (* get_rfreg ) (struct ieee80211_hw*,int,int,int) ;int /*<<< orphan*/  (* set_rfreg ) (struct ieee80211_hw*,int,int,int,int) ;int /*<<< orphan*/  (* set_bbreg ) (struct ieee80211_hw*,int,int,int) ;} ;

/* Variables and functions */
 int B3WIREADDREAALENGTH ; 
 int B3WIREDATALENGTH ; 
 int BRFSI_RFENV ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int /*<<< orphan*/  COMP_INIT ; 
 int DBG_TRACE ; 
 int FPHY ; 
#define  HT_CHANNEL_WIDTH_20 133 
#define  HT_CHANNEL_WIDTH_20_40 132 
 int IEEE80211_QOS_CTL_TID_MASK ; 
 struct ieee80211_tx_info* IEEE80211_SKB_CB (struct sk_buff*) ; 
 int MASKBYTE0 ; 
 int MASKBYTE1 ; 
 int MASKDWORD ; 
 int PHY_TXPWR ; 
 int RF6052_MAX_TX_PWR ; 
#define  RF90_PATH_A 131 
#define  RF90_PATH_B 130 
#define  RF90_PATH_C 129 
#define  RF90_PATH_D 128 
 int RFREG_OFFSET_MASK ; 
 scalar_t__ RF_1T1R ; 
 scalar_t__ RF_2T2R ; 
 int RF_CHNLBW ; 
 int RTXAGC_A_CCK1_MCS32 ; 
 int RTXAGC_A_MCS03_MCS00 ; 
 int RTXAGC_A_MCS07_MCS04 ; 
 int RTXAGC_A_MCS11_MCS08 ; 
 int RTXAGC_A_MCS15_MCS12 ; 
 int RTXAGC_A_RATE18_06 ; 
 int RTXAGC_A_RATE54_24 ; 
 int RTXAGC_B_CCK11_A_CCK2_11 ; 
 int RTXAGC_B_CCK1_55_MCS32 ; 
 int RTXAGC_B_MCS03_MCS00 ; 
 int RTXAGC_B_MCS07_MCS04 ; 
 int RTXAGC_B_MCS11_MCS08 ; 
 int RTXAGC_B_MCS15_MCS12 ; 
 int RTXAGC_B_RATE18_06 ; 
 int RTXAGC_B_RATE54_24 ; 
 scalar_t__ TXHIGHPWRLEVEL_BT1 ; 
 scalar_t__ TXHIGHPWRLEVEL_LEVEL1 ; 
 scalar_t__ TXHIGHPWRLEVEL_LEVEL2 ; 
 scalar_t__ WIRELESS_MODE_B ; 
 scalar_t__ _HAL_STATE_START ; 
 scalar_t__ _HAL_STATE_STOP ; 
static  int _rtl92c_phy_rf6052_config_parafile (struct ieee80211_hw*) ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int const*) ; 
 int* ieee80211_get_qos_ctl (struct ieee80211_hdr*) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int rtl92cu_phy_config_rf_with_headerfile (struct ieee80211_hw*,int) ; 
 struct rtl_efuse* rtl_efuse (struct rtl_priv*) ; 
 struct rtl_mac* rtl_mac (struct rtl_priv*) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 
 int stub1 (struct rtl_priv*,int) ; 
 int stub10 (struct ieee80211_hw*,int,int) ; 
 int /*<<< orphan*/  stub11 (struct ieee80211_hw*,int,int,int) ; 
 int stub12 (struct ieee80211_hw*,int,int,int) ; 
 int /*<<< orphan*/  stub13 (struct ieee80211_hw*,int,int,int,int) ; 
 int stub2 (struct rtl_priv*,int) ; 
 int stub3 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  stub4 (struct rtl_priv*,int,int) ; 
 int stub5 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  stub6 (struct rtl_priv*,int,int) ; 
 int stub7 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  stub8 (struct rtl_priv*,int,int) ; 
 int stub9 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline void RT_TRACE(struct rtl_priv *rtlpriv,
			    u64 comp, int level,
			    const char *fmt, ...)
{
}

__attribute__((used)) static inline void RTPRINT(struct rtl_priv *rtlpriv,
			   int dbgtype, int dbgflag,
			   const char *fmt, ...)
{
}

__attribute__((used)) static inline void RT_PRINT_DATA(struct rtl_priv *rtlpriv,
				 u64 comp, int level,
				 const char *titlestring,
				 const void *hexdata, size_t hexdatalen)
{
}

__attribute__((used)) static inline struct rtlwifi_tx_info *rtl_tx_skb_cb_info(struct sk_buff *skb)
{
	struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);

	BUILD_BUG_ON(sizeof(struct rtlwifi_tx_info) >
		     sizeof(info->status.status_driver_data));

	return (struct rtlwifi_tx_info *)(info->status.status_driver_data);
}

__attribute__((used)) static inline u8 rtl_read_byte(struct rtl_priv *rtlpriv, u32 addr)
{
	return rtlpriv->io.read8_sync(rtlpriv, addr);
}

__attribute__((used)) static inline u16 rtl_read_word(struct rtl_priv *rtlpriv, u32 addr)
{
	return rtlpriv->io.read16_sync(rtlpriv, addr);
}

__attribute__((used)) static inline u32 rtl_read_dword(struct rtl_priv *rtlpriv, u32 addr)
{
	return rtlpriv->io.read32_sync(rtlpriv, addr);
}

__attribute__((used)) static inline void rtl_write_byte(struct rtl_priv *rtlpriv, u32 addr, u8 val8)
{
	rtlpriv->io.write8_async(rtlpriv, addr, val8);

	if (rtlpriv->cfg->write_readback)
		rtlpriv->io.read8_sync(rtlpriv, addr);
}

__attribute__((used)) static inline void rtl_write_byte_with_val32(struct ieee80211_hw *hw,
					     u32 addr, u32 val8)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	rtl_write_byte(rtlpriv, addr, (u8)val8);
}

__attribute__((used)) static inline void rtl_write_word(struct rtl_priv *rtlpriv, u32 addr, u16 val16)
{
	rtlpriv->io.write16_async(rtlpriv, addr, val16);

	if (rtlpriv->cfg->write_readback)
		rtlpriv->io.read16_sync(rtlpriv, addr);
}

__attribute__((used)) static inline void rtl_write_dword(struct rtl_priv *rtlpriv,
				   u32 addr, u32 val32)
{
	rtlpriv->io.write32_async(rtlpriv, addr, val32);

	if (rtlpriv->cfg->write_readback)
		rtlpriv->io.read32_sync(rtlpriv, addr);
}

__attribute__((used)) static inline u32 rtl_get_bbreg(struct ieee80211_hw *hw,
				u32 regaddr, u32 bitmask)
{
	struct rtl_priv *rtlpriv = hw->priv;

	return rtlpriv->cfg->ops->get_bbreg(hw, regaddr, bitmask);
}

__attribute__((used)) static inline void rtl_set_bbreg(struct ieee80211_hw *hw, u32 regaddr,
				 u32 bitmask, u32 data)
{
	struct rtl_priv *rtlpriv = hw->priv;

	rtlpriv->cfg->ops->set_bbreg(hw, regaddr, bitmask, data);
}

__attribute__((used)) static inline void rtl_set_bbreg_with_dwmask(struct ieee80211_hw *hw,
				 u32 regaddr, u32 data)
{
	rtl_set_bbreg(hw, regaddr, 0xffffffff, data);
}

__attribute__((used)) static inline u32 rtl_get_rfreg(struct ieee80211_hw *hw,
				enum radio_path rfpath, u32 regaddr,
				u32 bitmask)
{
	struct rtl_priv *rtlpriv = hw->priv;

	return rtlpriv->cfg->ops->get_rfreg(hw, rfpath, regaddr, bitmask);
}

__attribute__((used)) static inline void rtl_set_rfreg(struct ieee80211_hw *hw,
				 enum radio_path rfpath, u32 regaddr,
				 u32 bitmask, u32 data)
{
	struct rtl_priv *rtlpriv = hw->priv;

	rtlpriv->cfg->ops->set_rfreg(hw, rfpath, regaddr, bitmask, data);
}

__attribute__((used)) static inline bool is_hal_stop(struct rtl_hal *rtlhal)
{
	return (_HAL_STATE_STOP == rtlhal->state);
}

__attribute__((used)) static inline void set_hal_start(struct rtl_hal *rtlhal)
{
	rtlhal->state = _HAL_STATE_START;
}

__attribute__((used)) static inline void set_hal_stop(struct rtl_hal *rtlhal)
{
	rtlhal->state = _HAL_STATE_STOP;
}

__attribute__((used)) static inline u8 get_rf_type(struct rtl_phy *rtlphy)
{
	return rtlphy->rf_type;
}

__attribute__((used)) static inline struct ieee80211_hdr *rtl_get_hdr(struct sk_buff *skb)
{
	return (struct ieee80211_hdr *)(skb->data);
}

__attribute__((used)) static inline __le16 rtl_get_fc(struct sk_buff *skb)
{
	return rtl_get_hdr(skb)->frame_control;
}

__attribute__((used)) static inline u16 rtl_get_tid_h(struct ieee80211_hdr *hdr)
{
	return (ieee80211_get_qos_ctl(hdr))[0] & IEEE80211_QOS_CTL_TID_MASK;
}

__attribute__((used)) static inline u16 rtl_get_tid(struct sk_buff *skb)
{
	return rtl_get_tid_h(rtl_get_hdr(skb));
}

__attribute__((used)) static inline struct ieee80211_sta *get_sta(struct ieee80211_hw *hw,
					    struct ieee80211_vif *vif,
					    const u8 *bssid)
{
	return ieee80211_find_sta(vif, bssid);
}

__attribute__((used)) static inline struct ieee80211_sta *rtl_find_sta(struct ieee80211_hw *hw,
		u8 *mac_addr)
{
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	return ieee80211_find_sta(mac->vif, mac_addr);
}

void rtl92cu_phy_rf6052_set_bandwidth(struct ieee80211_hw *hw, u8 bandwidth)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);

	switch (bandwidth) {
	case HT_CHANNEL_WIDTH_20:
		rtlphy->rfreg_chnlval[0] = ((rtlphy->rfreg_chnlval[0] &
					     0xfffff3ff) | 0x0400);
		rtl_set_rfreg(hw, RF90_PATH_A, RF_CHNLBW, RFREG_OFFSET_MASK,
			      rtlphy->rfreg_chnlval[0]);
		break;
	case HT_CHANNEL_WIDTH_20_40:
		rtlphy->rfreg_chnlval[0] = ((rtlphy->rfreg_chnlval[0] &
					     0xfffff3ff));
		rtl_set_rfreg(hw, RF90_PATH_A, RF_CHNLBW, RFREG_OFFSET_MASK,
			      rtlphy->rfreg_chnlval[0]);
		break;
	default:
		pr_err("unknown bandwidth: %#X\n", bandwidth);
		break;
	}
}

void rtl92cu_phy_rf6052_set_cck_txpower(struct ieee80211_hw *hw,
					u8 *ppowerlevel)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u32 tx_agc[2] = { 0, 0 }, tmpval = 0;
	bool turbo_scanoff = false;
	u8 idx1, idx2;
	u8 *ptr;

	if ((rtlefuse->eeprom_regulatory != 0) || (rtlefuse->external_pa))
		turbo_scanoff = true;
	if (mac->act_scanning) {
		tx_agc[RF90_PATH_A] = 0x3f3f3f3f;
		tx_agc[RF90_PATH_B] = 0x3f3f3f3f;
		for (idx1 = RF90_PATH_A; idx1 <= RF90_PATH_B; idx1++) {
			tx_agc[idx1] = ppowerlevel[idx1] |
			    (ppowerlevel[idx1] << 8) |
			    (ppowerlevel[idx1] << 16) |
			    (ppowerlevel[idx1] << 24);
			if (tx_agc[idx1] > 0x20 && rtlefuse->external_pa)
				tx_agc[idx1] = 0x20;
		}
	} else {
		if (rtlpriv->dm.dynamic_txhighpower_lvl ==
		    TXHIGHPWRLEVEL_LEVEL1) {
			tx_agc[RF90_PATH_A] = 0x10101010;
			tx_agc[RF90_PATH_B] = 0x10101010;
		} else if (rtlpriv->dm.dynamic_txhighpower_lvl ==
			   TXHIGHPWRLEVEL_LEVEL2) {
			tx_agc[RF90_PATH_A] = 0x00000000;
			tx_agc[RF90_PATH_B] = 0x00000000;
		} else {
			for (idx1 = RF90_PATH_A; idx1 <= RF90_PATH_B; idx1++) {
				tx_agc[idx1] = ppowerlevel[idx1] |
				    (ppowerlevel[idx1] << 8) |
				    (ppowerlevel[idx1] << 16) |
				    (ppowerlevel[idx1] << 24);
			}
			if (rtlefuse->eeprom_regulatory == 0) {
				tmpval = (rtlphy->mcs_offset[0][6]) +
					(rtlphy->mcs_offset[0][7] <<  8);
				tx_agc[RF90_PATH_A] += tmpval;
				tmpval = (rtlphy->mcs_offset[0][14]) +
					(rtlphy->mcs_offset[0][15] << 24);
				tx_agc[RF90_PATH_B] += tmpval;
			}
		}
	}
	for (idx1 = RF90_PATH_A; idx1 <= RF90_PATH_B; idx1++) {
		ptr = (u8 *) (&(tx_agc[idx1]));
		for (idx2 = 0; idx2 < 4; idx2++) {
			if (*ptr > RF6052_MAX_TX_PWR)
				*ptr = RF6052_MAX_TX_PWR;
			ptr++;
		}
	}
	tmpval = tx_agc[RF90_PATH_A] & 0xff;
	rtl_set_bbreg(hw, RTXAGC_A_CCK1_MCS32, MASKBYTE1, tmpval);

	RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
		"CCK PWR 1M (rf-A) = 0x%x (reg 0x%x)\n",
		tmpval, RTXAGC_A_CCK1_MCS32);

	tmpval = tx_agc[RF90_PATH_A] >> 8;
	if (mac->mode == WIRELESS_MODE_B)
		tmpval = tmpval & 0xff00ffff;
	rtl_set_bbreg(hw, RTXAGC_B_CCK11_A_CCK2_11, 0xffffff00, tmpval);
	RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
		"CCK PWR 2~11M (rf-A) = 0x%x (reg 0x%x)\n",
		tmpval, RTXAGC_B_CCK11_A_CCK2_11);
	tmpval = tx_agc[RF90_PATH_B] >> 24;
	rtl_set_bbreg(hw, RTXAGC_B_CCK11_A_CCK2_11, MASKBYTE0, tmpval);
	RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
		"CCK PWR 11M (rf-B) = 0x%x (reg 0x%x)\n",
		tmpval, RTXAGC_B_CCK11_A_CCK2_11);
	tmpval = tx_agc[RF90_PATH_B] & 0x00ffffff;
	rtl_set_bbreg(hw, RTXAGC_B_CCK1_55_MCS32, 0xffffff00, tmpval);
	RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
		"CCK PWR 1~5.5M (rf-B) = 0x%x (reg 0x%x)\n",
		tmpval, RTXAGC_B_CCK1_55_MCS32);
}

__attribute__((used)) static void rtl92c_phy_get_power_base(struct ieee80211_hw *hw,
				      u8 *ppowerlevel, u8 channel,
				      u32 *ofdmbase, u32 *mcsbase)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u32 powerBase0, powerBase1;
	u8 legacy_pwrdiff = 0, ht20_pwrdiff = 0;
	u8 i, powerlevel[2];

	for (i = 0; i < 2; i++) {
		powerlevel[i] = ppowerlevel[i];
		legacy_pwrdiff = rtlefuse->txpwr_legacyhtdiff[i][channel - 1];
		powerBase0 = powerlevel[i] + legacy_pwrdiff;
		powerBase0 = (powerBase0 << 24) | (powerBase0 << 16) |
		    (powerBase0 << 8) | powerBase0;
		*(ofdmbase + i) = powerBase0;
		RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
			" [OFDM power base index rf(%c) = 0x%x]\n",
			i == 0 ? 'A' : 'B', *(ofdmbase + i));
	}
	for (i = 0; i < 2; i++) {
		if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20) {
			ht20_pwrdiff = rtlefuse->txpwr_ht20diff[i][channel - 1];
			powerlevel[i] += ht20_pwrdiff;
		}
		powerBase1 = powerlevel[i];
		powerBase1 = (powerBase1 << 24) |
		    (powerBase1 << 16) | (powerBase1 << 8) | powerBase1;
		*(mcsbase + i) = powerBase1;
		RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
			" [MCS power base index rf(%c) = 0x%x]\n",
			i == 0 ? 'A' : 'B', *(mcsbase + i));
	}
}

__attribute__((used)) static void _rtl92c_get_txpower_writeval_by_regulatory(struct ieee80211_hw *hw,
						       u8 channel, u8 index,
						       u32 *powerBase0,
						       u32 *powerBase1,
						       u32 *p_outwriteval)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u8 i, chnlgroup = 0, pwr_diff_limit[4];
	u32 writeVal, customer_limit, rf;

	for (rf = 0; rf < 2; rf++) {
		switch (rtlefuse->eeprom_regulatory) {
		case 0:
			chnlgroup = 0;
			writeVal = rtlphy->mcs_offset
			    [chnlgroup][index + (rf ? 8 : 0)]
			    + ((index < 2) ? powerBase0[rf] : powerBase1[rf]);
			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"RTK better performance,writeVal(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		case 1:
			if (rtlphy->pwrgroup_cnt == 1)
				chnlgroup = 0;
			if (rtlphy->pwrgroup_cnt >= 3) {
				if (channel <= 3)
					chnlgroup = 0;
				else if (channel >= 4 && channel <= 9)
					chnlgroup = 1;
				else if (channel > 9)
					chnlgroup = 2;
				if (rtlphy->current_chan_bw ==
				    HT_CHANNEL_WIDTH_20)
					chnlgroup++;
				else
					chnlgroup += 4;
			}
			writeVal = rtlphy->mcs_offset[chnlgroup][index +
					(rf ? 8 : 0)] +
					((index < 2) ? powerBase0[rf] :
					powerBase1[rf]);
			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"Realtek regulatory, 20MHz, writeVal(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		case 2:
			writeVal = ((index < 2) ? powerBase0[rf] :
				   powerBase1[rf]);
			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"Better regulatory,writeVal(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		case 3:
			chnlgroup = 0;
			if (rtlphy->current_chan_bw ==
			    HT_CHANNEL_WIDTH_20_40) {
				RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
					"customer's limit, 40MHzrf(%c) = 0x%x\n",
					rf == 0 ? 'A' : 'B',
					rtlefuse->pwrgroup_ht40[rf]
					[channel - 1]);
			} else {
				RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
					"customer's limit, 20MHz rf(%c) = 0x%x\n",
					rf == 0 ? 'A' : 'B',
					rtlefuse->pwrgroup_ht20[rf]
					[channel - 1]);
			}
			for (i = 0; i < 4; i++) {
				pwr_diff_limit[i] = (u8) ((rtlphy->mcs_offset
				    [chnlgroup][index + (rf ? 8 : 0)]
				    & (0x7f << (i * 8))) >> (i * 8));
				if (rtlphy->current_chan_bw ==
				    HT_CHANNEL_WIDTH_20_40) {
					if (pwr_diff_limit[i] >
					    rtlefuse->pwrgroup_ht40[rf]
						[channel - 1])
						pwr_diff_limit[i] = rtlefuse->
						    pwrgroup_ht40[rf]
						    [channel - 1];
				} else {
					if (pwr_diff_limit[i] >
					    rtlefuse->pwrgroup_ht20[rf]
						[channel - 1])
						pwr_diff_limit[i] =
						    rtlefuse->pwrgroup_ht20[rf]
						    [channel - 1];
				}
			}
			customer_limit = (pwr_diff_limit[3] << 24) |
			    (pwr_diff_limit[2] << 16) |
			    (pwr_diff_limit[1] << 8) | (pwr_diff_limit[0]);
			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"Customer's limit rf(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', customer_limit);
			writeVal = customer_limit + ((index < 2) ?
				   powerBase0[rf] : powerBase1[rf]);
			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"Customer, writeVal rf(%c)= 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		default:
			chnlgroup = 0;
			writeVal = rtlphy->mcs_offset[chnlgroup]
				   [index + (rf ? 8 : 0)] + ((index < 2) ?
				   powerBase0[rf] : powerBase1[rf]);
			RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
				"RTK better performance, writeValrf(%c) = 0x%x\n",
				rf == 0 ? 'A' : 'B', writeVal);
			break;
		}
		if (rtlpriv->dm.dynamic_txhighpower_lvl ==
		    TXHIGHPWRLEVEL_LEVEL1)
			writeVal = 0x14141414;
		else if (rtlpriv->dm.dynamic_txhighpower_lvl ==
			 TXHIGHPWRLEVEL_LEVEL2)
			writeVal = 0x00000000;
		if (rtlpriv->dm.dynamic_txhighpower_lvl == TXHIGHPWRLEVEL_BT1)
			writeVal = writeVal - 0x06060606;
		*(p_outwriteval + rf) = writeVal;
	}
}

__attribute__((used)) static void _rtl92c_write_ofdm_power_reg(struct ieee80211_hw *hw,
					 u8 index, u32 *pValue)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	u16 regoffset_a[6] = {
		RTXAGC_A_RATE18_06, RTXAGC_A_RATE54_24,
		RTXAGC_A_MCS03_MCS00, RTXAGC_A_MCS07_MCS04,
		RTXAGC_A_MCS11_MCS08, RTXAGC_A_MCS15_MCS12
	};
	u16 regoffset_b[6] = {
		RTXAGC_B_RATE18_06, RTXAGC_B_RATE54_24,
		RTXAGC_B_MCS03_MCS00, RTXAGC_B_MCS07_MCS04,
		RTXAGC_B_MCS11_MCS08, RTXAGC_B_MCS15_MCS12
	};
	u8 i, rf, pwr_val[4];
	u32 writeVal;
	u16 regoffset;

	for (rf = 0; rf < 2; rf++) {
		writeVal = pValue[rf];
		for (i = 0; i < 4; i++) {
			pwr_val[i] = (u8)((writeVal & (0x7f << (i * 8))) >>
					  (i * 8));
			if (pwr_val[i] > RF6052_MAX_TX_PWR)
				pwr_val[i] = RF6052_MAX_TX_PWR;
		}
		writeVal = (pwr_val[3] << 24) | (pwr_val[2] << 16) |
		    (pwr_val[1] << 8) | pwr_val[0];
		if (rf == 0)
			regoffset = regoffset_a[index];
		else
			regoffset = regoffset_b[index];
		rtl_set_bbreg(hw, regoffset, MASKDWORD, writeVal);
		RTPRINT(rtlpriv, FPHY, PHY_TXPWR,
			"Set 0x%x = %08x\n", regoffset, writeVal);
		if (((get_rf_type(rtlphy) == RF_2T2R) &&
		     (regoffset == RTXAGC_A_MCS15_MCS12 ||
		      regoffset == RTXAGC_B_MCS15_MCS12)) ||
		    ((get_rf_type(rtlphy) != RF_2T2R) &&
		     (regoffset == RTXAGC_A_MCS07_MCS04 ||
		      regoffset == RTXAGC_B_MCS07_MCS04))) {
			writeVal = pwr_val[3];
			if (regoffset == RTXAGC_A_MCS15_MCS12 ||
			    regoffset == RTXAGC_A_MCS07_MCS04)
				regoffset = 0xc90;
			if (regoffset == RTXAGC_B_MCS15_MCS12 ||
			    regoffset == RTXAGC_B_MCS07_MCS04)
				regoffset = 0xc98;
			for (i = 0; i < 3; i++) {
				if (i != 2)
					writeVal = (writeVal > 8) ?
						   (writeVal - 8) : 0;
				else
					writeVal = (writeVal > 6) ?
						   (writeVal - 6) : 0;
				rtl_write_byte(rtlpriv, (u32)(regoffset + i),
					      (u8)writeVal);
			}
		}
	}
}

void rtl92cu_phy_rf6052_set_ofdm_txpower(struct ieee80211_hw *hw,
					 u8 *ppowerlevel, u8 channel)
{
	u32 writeVal[2], powerBase0[2], powerBase1[2];
	u8 index = 0;

	rtl92c_phy_get_power_base(hw, ppowerlevel,
				  channel, &powerBase0[0], &powerBase1[0]);
	for (index = 0; index < 6; index++) {
		_rtl92c_get_txpower_writeval_by_regulatory(hw,
							   channel, index,
							   &powerBase0[0],
							   &powerBase1[0],
							   &writeVal[0]);
		_rtl92c_write_ofdm_power_reg(hw, index, &writeVal[0]);
	}
}

bool rtl92cu_phy_rf6052_config(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	bool rtstatus = true;
	u8 b_reg_hwparafile = 1;

	if (rtlphy->rf_type == RF_1T1R)
		rtlphy->num_total_rfpath = 1;
	else
		rtlphy->num_total_rfpath = 2;
	if (b_reg_hwparafile == 1)
		rtstatus = _rtl92c_phy_rf6052_config_parafile(hw);
	return rtstatus;
}

__attribute__((used)) static bool _rtl92c_phy_rf6052_config_parafile(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	u32 u4_regvalue = 0;
	u8 rfpath;
	bool rtstatus = true;
	struct bb_reg_def *pphyreg;

	for (rfpath = 0; rfpath < rtlphy->num_total_rfpath; rfpath++) {
		pphyreg = &rtlphy->phyreg_def[rfpath];
		switch (rfpath) {
		case RF90_PATH_A:
		case RF90_PATH_C:
			u4_regvalue = rtl_get_bbreg(hw, pphyreg->rfintfs,
						    BRFSI_RFENV);
			break;
		case RF90_PATH_B:
		case RF90_PATH_D:
			u4_regvalue = rtl_get_bbreg(hw, pphyreg->rfintfs,
						    BRFSI_RFENV << 16);
			break;
		}
		rtl_set_bbreg(hw, pphyreg->rfintfe, BRFSI_RFENV << 16, 0x1);
		udelay(1);
		rtl_set_bbreg(hw, pphyreg->rfintfo, BRFSI_RFENV, 0x1);
		udelay(1);
		rtl_set_bbreg(hw, pphyreg->rfhssi_para2,
			      B3WIREADDREAALENGTH, 0x0);
		udelay(1);
		rtl_set_bbreg(hw, pphyreg->rfhssi_para2, B3WIREDATALENGTH, 0x0);
		udelay(1);
		switch (rfpath) {
		case RF90_PATH_A:
		case RF90_PATH_B:
			rtstatus = rtl92cu_phy_config_rf_with_headerfile(hw,
					(enum radio_path) rfpath);
			break;
		case RF90_PATH_C:
			break;
		case RF90_PATH_D:
			break;
		}
		switch (rfpath) {
		case RF90_PATH_A:
		case RF90_PATH_C:
			rtl_set_bbreg(hw, pphyreg->rfintfs,
				      BRFSI_RFENV, u4_regvalue);
			break;
		case RF90_PATH_B:
		case RF90_PATH_D:
			rtl_set_bbreg(hw, pphyreg->rfintfs,
				      BRFSI_RFENV << 16, u4_regvalue);
			break;
		}
		if (!rtstatus) {
			RT_TRACE(rtlpriv, COMP_INIT, DBG_TRACE,
				 "Radio[%d] Fail!!\n", rfpath);
			goto phy_rf_cfg_fail;
		}
	}
	RT_TRACE(rtlpriv, COMP_INIT, DBG_TRACE, "<---\n");
phy_rf_cfg_fail:
	return rtstatus;
}

