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
struct rtl_phy {int rf_type; scalar_t__ current_chan_bw; int** mcs_offset; int pwrgroup_cnt; int num_total_rfpath; int* rfreg_chnlval; struct bb_reg_def* phyreg_def; } ;
struct TYPE_10__ {scalar_t__ dynamic_txhighpower_lvl; } ;
struct TYPE_7__ {int (* read8_sync ) (struct rtl_priv*,int) ;int (* read16_sync ) (struct rtl_priv*,int) ;int (* read32_sync ) (struct rtl_priv*,int) ;int /*<<< orphan*/  (* write32_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write16_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write8_async ) (struct rtl_priv*,int,int) ;} ;
struct rtl_priv {struct rtl_phy phy; TYPE_5__ dm; TYPE_4__* cfg; TYPE_2__ io; } ;
struct rtl_mac {scalar_t__ act_scanning; struct ieee80211_vif* vif; } ;
struct rtl_hal {scalar_t__ state; } ;
struct rtl_efuse {int eeprom_version; int legacy_httxpowerdiff; int** txpwr_legacyhtdiff; int** txpwr_ht20diff; int eeprom_regulatory; int** pwrgroup_ht40; int** pwrgroup_ht20; int* antenna_txpwdiff; int txpwr_safetyflag; } ;
struct ieee80211_vif {int dummy; } ;
struct TYPE_6__ {scalar_t__ status_driver_data; } ;
struct ieee80211_tx_info {TYPE_1__ status; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hw {struct rtl_priv* priv; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
struct bb_reg_def {int /*<<< orphan*/  rfintfs; int /*<<< orphan*/  rfhssi_para2; int /*<<< orphan*/  rfintfo; int /*<<< orphan*/  rfintfe; } ;
typedef  int s8 ;
typedef  enum radio_path { ____Placeholder_radio_path } radio_path ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_9__ {TYPE_3__* ops; scalar_t__ write_readback; } ;
struct TYPE_8__ {int (* get_bbreg ) (struct ieee80211_hw*,int,int) ;int (* get_rfreg ) (struct ieee80211_hw*,int,int,int) ;int /*<<< orphan*/  (* set_rfreg ) (struct ieee80211_hw*,int,int,int,int) ;int /*<<< orphan*/  (* set_bbreg ) (struct ieee80211_hw*,int,int,int) ;} ;

/* Variables and functions */
 int B3WIRE_ADDRESSLENGTH ; 
 int B3WIRE_DATALENGTH ; 
 int BRFSI_RFENV ; 
 int BTX_AGCRATECCK ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int BXBTXAGC ; 
 int BXCTXAGC ; 
 int BXDTXAGC ; 
 int /*<<< orphan*/  COMP_POWER ; 
 int DBG_LOUD ; 
#define  HT_CHANNEL_WIDTH_20 133 
#define  HT_CHANNEL_WIDTH_20_40 132 
 int IEEE80211_QOS_CTL_TID_MASK ; 
 struct ieee80211_tx_info* IEEE80211_SKB_CB (struct sk_buff*) ; 
 int RF6052_MAX_TX_PWR ; 
#define  RF90_PATH_A 131 
#define  RF90_PATH_B 130 
#define  RF90_PATH_C 129 
#define  RF90_PATH_D 128 
 int RFPGA0_TXGAINSTAGE ; 
 int RFREG_OFFSET_MASK ; 
 scalar_t__ RF_2T2R ; 
 int RF_CHNLBW ; 
 int RTXAGC_CCK_MCS32 ; 
 scalar_t__ TX_HIGH_PWR_LEVEL_LEVEL1 ; 
 scalar_t__ TX_HIGH_PWR_LEVEL_LEVEL2 ; 
 scalar_t__ _HAL_STATE_START ; 
 scalar_t__ _HAL_STATE_STOP ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int const*) ; 
 int* ieee80211_get_qos_ctl (struct ieee80211_hdr*) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int rtl92s_phy_config_rf (struct ieee80211_hw*,int) ; 
 int rtl92s_phy_query_bb_reg (struct ieee80211_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  rtl92s_phy_set_bb_reg (struct ieee80211_hw*,int /*<<< orphan*/ ,int,int) ; 
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

__attribute__((used)) static void _rtl92s_get_powerbase(struct ieee80211_hw *hw, u8 *p_pwrlevel,
				  u8 chnl, u32 *ofdmbase, u32 *mcsbase,
				  u8 *p_final_pwridx)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u32 pwrbase0, pwrbase1;
	u8 legacy_pwrdiff = 0, ht20_pwrdiff = 0;
	u8 i, pwrlevel[4];

	for (i = 0; i < 2; i++)
		pwrlevel[i] = p_pwrlevel[i];

	/* We only care about the path A for legacy. */
	if (rtlefuse->eeprom_version < 2) {
		pwrbase0 = pwrlevel[0] + (rtlefuse->legacy_httxpowerdiff & 0xf);
	} else {
		legacy_pwrdiff = rtlefuse->txpwr_legacyhtdiff
						[RF90_PATH_A][chnl - 1];

		/* For legacy OFDM, tx pwr always > HT OFDM pwr.
		 * We do not care Path B
		 * legacy OFDM pwr diff. NO BB register
		 * to notify HW. */
		pwrbase0 = pwrlevel[0] + legacy_pwrdiff;
	}

	pwrbase0 = (pwrbase0 << 24) | (pwrbase0 << 16) | (pwrbase0 << 8) |
		    pwrbase0;
	*ofdmbase = pwrbase0;

	/* MCS rates */
	if (rtlefuse->eeprom_version >= 2) {
		/* Check HT20 to HT40 diff	*/
		if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20) {
			for (i = 0; i < 2; i++) {
				/* rf-A, rf-B */
				/* HT 20<->40 pwr diff */
				ht20_pwrdiff = rtlefuse->txpwr_ht20diff
							[i][chnl - 1];

				if (ht20_pwrdiff < 8) /* 0~+7 */
					pwrlevel[i] += ht20_pwrdiff;
				else /* index8-15=-8~-1 */
					pwrlevel[i] -= (16 - ht20_pwrdiff);
			}
		}
	}

	/* use index of rf-A */
	pwrbase1 = pwrlevel[0];
	pwrbase1 = (pwrbase1 << 24) | (pwrbase1 << 16) | (pwrbase1 << 8) |
				pwrbase1;
	*mcsbase = pwrbase1;

	/* The following is for Antenna
	 * diff from Ant-B to Ant-A */
	p_final_pwridx[0] = pwrlevel[0];
	p_final_pwridx[1] = pwrlevel[1];

	switch (rtlefuse->eeprom_regulatory) {
	case 3:
		/* The following is for calculation
		 * of the power diff for Ant-B to Ant-A. */
		if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20_40) {
			p_final_pwridx[0] += rtlefuse->pwrgroup_ht40
						[RF90_PATH_A][
						chnl - 1];
			p_final_pwridx[1] += rtlefuse->pwrgroup_ht40
						[RF90_PATH_B][
						chnl - 1];
		} else {
			p_final_pwridx[0] += rtlefuse->pwrgroup_ht20
						[RF90_PATH_A][
						chnl - 1];
			p_final_pwridx[1] += rtlefuse->pwrgroup_ht20
						[RF90_PATH_B][
						chnl - 1];
		}
		break;
	default:
		break;
	}

	if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20_40) {
		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "40MHz finalpwr_idx (A / B) = 0x%x / 0x%x\n",
			 p_final_pwridx[0], p_final_pwridx[1]);
	} else {
		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "20MHz finalpwr_idx (A / B) = 0x%x / 0x%x\n",
			 p_final_pwridx[0], p_final_pwridx[1]);
	}
}

__attribute__((used)) static void _rtl92s_set_antennadiff(struct ieee80211_hw *hw,
				    u8 *p_final_pwridx)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	s8 ant_pwr_diff = 0;
	u32	u4reg_val = 0;

	if (rtlphy->rf_type == RF_2T2R) {
		ant_pwr_diff = p_final_pwridx[1] - p_final_pwridx[0];

		/* range is from 7~-8,
		 * index = 0x0~0xf */
		if (ant_pwr_diff > 7)
			ant_pwr_diff = 7;
		if (ant_pwr_diff < -8)
			ant_pwr_diff = -8;

		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "Antenna Diff from RF-B to RF-A = %d (0x%x)\n",
			 ant_pwr_diff, ant_pwr_diff & 0xf);

		ant_pwr_diff &= 0xf;
	}

	/* Antenna TX power difference */
	rtlefuse->antenna_txpwdiff[2] = 0;/* RF-D, don't care */
	rtlefuse->antenna_txpwdiff[1] = 0;/* RF-C, don't care */
	rtlefuse->antenna_txpwdiff[0] = (u8)(ant_pwr_diff);	/* RF-B */

	u4reg_val = rtlefuse->antenna_txpwdiff[2] << 8 |
				rtlefuse->antenna_txpwdiff[1] << 4 |
				rtlefuse->antenna_txpwdiff[0];

	rtl_set_bbreg(hw, RFPGA0_TXGAINSTAGE, (BXBTXAGC | BXCTXAGC | BXDTXAGC),
		      u4reg_val);

	RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD, "Write BCD-Diff(0x%x) = 0x%x\n",
		 RFPGA0_TXGAINSTAGE, u4reg_val);
}

__attribute__((used)) static void _rtl92s_get_txpower_writeval_byregulatory(struct ieee80211_hw *hw,
						      u8 chnl, u8 index,
						      u32 pwrbase0,
						      u32 pwrbase1,
						      u32 *p_outwrite_val)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u8 i, chnlgroup, pwrdiff_limit[4];
	u32 writeval, customer_limit;

	/* Index 0 & 1= legacy OFDM, 2-5=HT_MCS rate */
	switch (rtlefuse->eeprom_regulatory) {
	case 0:
		/* Realtek better performance increase power diff
		 * defined by Realtek for large power */
		chnlgroup = 0;

		writeval = rtlphy->mcs_offset[chnlgroup][index] +
				((index < 2) ? pwrbase0 : pwrbase1);

		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "RTK better performance, writeval = 0x%x\n", writeval);
		break;
	case 1:
		/* Realtek regulatory increase power diff defined
		 * by Realtek for regulatory */
		if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20_40) {
			writeval = ((index < 2) ? pwrbase0 : pwrbase1);

			RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
				 "Realtek regulatory, 40MHz, writeval = 0x%x\n",
				 writeval);
		} else {
			chnlgroup = 0;

			if (rtlphy->pwrgroup_cnt >= 3) {
				if (chnl <= 3)
					chnlgroup = 0;
				else if (chnl >= 4 && chnl <= 8)
					chnlgroup = 1;
				else if (chnl > 8)
					chnlgroup = 2;
				if (rtlphy->pwrgroup_cnt == 4)
					chnlgroup++;
			}

			writeval = rtlphy->mcs_offset[chnlgroup][index]
					+ ((index < 2) ?
					pwrbase0 : pwrbase1);

			RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
				 "Realtek regulatory, 20MHz, writeval = 0x%x\n",
				 writeval);
		}
		break;
	case 2:
		/* Better regulatory don't increase any power diff */
		writeval = ((index < 2) ? pwrbase0 : pwrbase1);
		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "Better regulatory, writeval = 0x%x\n", writeval);
		break;
	case 3:
		/* Customer defined power diff. increase power diff
		  defined by customer. */
		chnlgroup = 0;

		if (rtlphy->current_chan_bw == HT_CHANNEL_WIDTH_20_40) {
			RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
				 "customer's limit, 40MHz = 0x%x\n",
				 rtlefuse->pwrgroup_ht40
				 [RF90_PATH_A][chnl - 1]);
		} else {
			RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
				 "customer's limit, 20MHz = 0x%x\n",
				 rtlefuse->pwrgroup_ht20
				 [RF90_PATH_A][chnl - 1]);
		}

		for (i = 0; i < 4; i++) {
			pwrdiff_limit[i] = (u8)((rtlphy->mcs_offset
				[chnlgroup][index] & (0x7f << (i * 8)))
				>> (i * 8));

			if (rtlphy->current_chan_bw ==
			    HT_CHANNEL_WIDTH_20_40) {
				if (pwrdiff_limit[i] >
				    rtlefuse->pwrgroup_ht40
				    [RF90_PATH_A][chnl - 1]) {
					pwrdiff_limit[i] =
					  rtlefuse->pwrgroup_ht40
					  [RF90_PATH_A][chnl - 1];
				}
			} else {
				if (pwrdiff_limit[i] >
				    rtlefuse->pwrgroup_ht20
				    [RF90_PATH_A][chnl - 1]) {
					pwrdiff_limit[i] =
					    rtlefuse->pwrgroup_ht20
					    [RF90_PATH_A][chnl - 1];
				}
			}
		}

		customer_limit = (pwrdiff_limit[3] << 24) |
				(pwrdiff_limit[2] << 16) |
				(pwrdiff_limit[1] << 8) |
				(pwrdiff_limit[0]);
		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "Customer's limit = 0x%x\n", customer_limit);

		writeval = customer_limit + ((index < 2) ?
					     pwrbase0 : pwrbase1);
		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "Customer, writeval = 0x%x\n", writeval);
		break;
	default:
		chnlgroup = 0;
		writeval = rtlphy->mcs_offset[chnlgroup][index] +
				((index < 2) ? pwrbase0 : pwrbase1);
		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "RTK better performance, writeval = 0x%x\n", writeval);
		break;
	}

	if (rtlpriv->dm.dynamic_txhighpower_lvl == TX_HIGH_PWR_LEVEL_LEVEL1)
		writeval = 0x10101010;
	else if (rtlpriv->dm.dynamic_txhighpower_lvl ==
		 TX_HIGH_PWR_LEVEL_LEVEL2)
		writeval = 0x0;

	*p_outwrite_val = writeval;

}

__attribute__((used)) static void _rtl92s_write_ofdm_powerreg(struct ieee80211_hw *hw,
					u8 index, u32 val)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u16 regoffset[6] = {0xe00, 0xe04, 0xe10, 0xe14, 0xe18, 0xe1c};
	u8 i, rfa_pwr[4];
	u8 rfa_lower_bound = 0, rfa_upper_bound = 0, rf_pwr_diff = 0;
	u32 writeval = val;

	/* If path A and Path B coexist, we must limit Path A tx power.
	 * Protect Path B pwr over or under flow. We need to calculate
	 * upper and lower bound of path A tx power. */
	if (rtlphy->rf_type == RF_2T2R) {
		rf_pwr_diff = rtlefuse->antenna_txpwdiff[0];

		/* Diff=-8~-1 */
		if (rf_pwr_diff >= 8) {
			/* Prevent underflow!! */
			rfa_lower_bound = 0x10 - rf_pwr_diff;
		/* if (rf_pwr_diff >= 0) Diff = 0-7 */
		} else {
			rfa_upper_bound = RF6052_MAX_TX_PWR - rf_pwr_diff;
		}
	}

	for (i = 0; i < 4; i++) {
		rfa_pwr[i] = (u8)((writeval & (0x7f << (i * 8))) >> (i * 8));
		if (rfa_pwr[i]  > RF6052_MAX_TX_PWR)
			rfa_pwr[i]  = RF6052_MAX_TX_PWR;

		/* If path A and Path B coexist, we must limit Path A tx power.
		 * Protect Path B pwr over or under flow. We need to calculate
		 * upper and lower bound of path A tx power. */
		if (rtlphy->rf_type == RF_2T2R) {
			/* Diff=-8~-1 */
			if (rf_pwr_diff >= 8) {
				/* Prevent underflow!! */
				if (rfa_pwr[i] < rfa_lower_bound)
					rfa_pwr[i] = rfa_lower_bound;
			/* Diff = 0-7 */
			} else if (rf_pwr_diff >= 1) {
				/* Prevent overflow */
				if (rfa_pwr[i] > rfa_upper_bound)
					rfa_pwr[i] = rfa_upper_bound;
			}
		}

	}

	writeval = (rfa_pwr[3] << 24) | (rfa_pwr[2] << 16) | (rfa_pwr[1] << 8) |
				rfa_pwr[0];

	rtl_set_bbreg(hw, regoffset[index], 0x7f7f7f7f, writeval);
}

void rtl92s_phy_rf6052_set_ofdmtxpower(struct ieee80211_hw *hw,
				       u8 *p_pwrlevel, u8 chnl)
{
	u32 writeval, pwrbase0, pwrbase1;
	u8 index = 0;
	u8 finalpwr_idx[4];

	_rtl92s_get_powerbase(hw, p_pwrlevel, chnl, &pwrbase0, &pwrbase1,
			&finalpwr_idx[0]);
	_rtl92s_set_antennadiff(hw, &finalpwr_idx[0]);

	for (index = 0; index < 6; index++) {
		_rtl92s_get_txpower_writeval_byregulatory(hw, chnl, index,
				pwrbase0, pwrbase1, &writeval);

		_rtl92s_write_ofdm_powerreg(hw, index, writeval);
	}
}

void rtl92s_phy_rf6052_set_ccktxpower(struct ieee80211_hw *hw, u8 pwrlevel)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u32 txagc = 0;
	bool dont_inc_cck_or_turboscanoff = false;

	if (((rtlefuse->eeprom_version >= 2) &&
	      (rtlefuse->txpwr_safetyflag == 1)) ||
	      ((rtlefuse->eeprom_version >= 2) &&
	      (rtlefuse->eeprom_regulatory != 0)))
		dont_inc_cck_or_turboscanoff = true;

	if (mac->act_scanning) {
		txagc = 0x3f;
		if (dont_inc_cck_or_turboscanoff)
			txagc = pwrlevel;
	} else {
		txagc = pwrlevel;

		if (rtlpriv->dm.dynamic_txhighpower_lvl ==
		    TX_HIGH_PWR_LEVEL_LEVEL1)
			txagc = 0x10;
		else if (rtlpriv->dm.dynamic_txhighpower_lvl ==
			TX_HIGH_PWR_LEVEL_LEVEL2)
			txagc = 0x0;
	}

	if (txagc > RF6052_MAX_TX_PWR)
		txagc = RF6052_MAX_TX_PWR;

	rtl_set_bbreg(hw, RTXAGC_CCK_MCS32, BTX_AGCRATECCK, txagc);

}

bool rtl92s_phy_rf6052_config(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	u32 u4reg_val = 0;
	u8 rfpath;
	bool rtstatus = true;
	struct bb_reg_def *pphyreg;

	/* Initialize RF */
	for (rfpath = 0; rfpath < rtlphy->num_total_rfpath; rfpath++) {

		pphyreg = &rtlphy->phyreg_def[rfpath];

		/* Store original RFENV control type */
		switch (rfpath) {
		case RF90_PATH_A:
		case RF90_PATH_C:
			u4reg_val = rtl92s_phy_query_bb_reg(hw,
							    pphyreg->rfintfs,
							    BRFSI_RFENV);
			break;
		case RF90_PATH_B:
		case RF90_PATH_D:
			u4reg_val = rtl92s_phy_query_bb_reg(hw,
							    pphyreg->rfintfs,
							    BRFSI_RFENV << 16);
			break;
		}

		/* Set RF_ENV enable */
		rtl92s_phy_set_bb_reg(hw, pphyreg->rfintfe,
				      BRFSI_RFENV << 16, 0x1);

		/* Set RF_ENV output high */
		rtl92s_phy_set_bb_reg(hw, pphyreg->rfintfo, BRFSI_RFENV, 0x1);

		/* Set bit number of Address and Data for RF register */
		rtl92s_phy_set_bb_reg(hw, pphyreg->rfhssi_para2,
				B3WIRE_ADDRESSLENGTH, 0x0);
		rtl92s_phy_set_bb_reg(hw, pphyreg->rfhssi_para2,
				B3WIRE_DATALENGTH, 0x0);

		/* Initialize RF fom connfiguration file */
		switch (rfpath) {
		case RF90_PATH_A:
			rtstatus = rtl92s_phy_config_rf(hw,
						(enum radio_path)rfpath);
			break;
		case RF90_PATH_B:
			rtstatus = rtl92s_phy_config_rf(hw,
						(enum radio_path)rfpath);
			break;
		case RF90_PATH_C:
			break;
		case RF90_PATH_D:
			break;
		}

		/* Restore RFENV control type */
		switch (rfpath) {
		case RF90_PATH_A:
		case RF90_PATH_C:
			rtl92s_phy_set_bb_reg(hw, pphyreg->rfintfs, BRFSI_RFENV,
					      u4reg_val);
			break;
		case RF90_PATH_B:
		case RF90_PATH_D:
			rtl92s_phy_set_bb_reg(hw, pphyreg->rfintfs,
					      BRFSI_RFENV << 16,
					      u4reg_val);
			break;
		}

		if (!rtstatus) {
			pr_err("Radio[%d] Fail!!\n", rfpath);
			goto fail;
		}

	}

	return rtstatus;

fail:
	return rtstatus;
}

void rtl92s_phy_rf6052_set_bandwidth(struct ieee80211_hw *hw, u8 bandwidth)
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

