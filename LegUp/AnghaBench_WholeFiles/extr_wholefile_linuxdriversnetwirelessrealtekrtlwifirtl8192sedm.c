#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_9__ ;
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {scalar_t__ data; } ;
struct rtlwifi_tx_info {int dummy; } ;
struct TYPE_18__ {int current_turbo_edca; int is_any_nonbepkts; int is_cur_rdlstate; int txpower_trackinginit; int thermalvalue; int txpowercount; int txpower_tracking; int tm_trigger; int useramask; int inform_fw_driverctrldm; long undec_sm_pwdb; scalar_t__ dm_type; int dynamic_txpower_enable; int dm_flag; scalar_t__ dynamic_txhighpower_lvl; long entry_min_undec_sm_pwdb; scalar_t__ last_dtp_lvl; int /*<<< orphan*/  dm_initialgain_enable; int /*<<< orphan*/  disable_framebursting; } ;
struct dig_t {scalar_t__ fa_highthresh; int back_val; int backoffval_range_min; scalar_t__ fa_lowthresh; int backoffval_range_max; scalar_t__ pre_sta_cstate; scalar_t__ cur_sta_cstate; int backoff_enable_flag; int rssi_val; int rx_gain_max; scalar_t__ cur_igvalue; scalar_t__ rx_gain_min; int pre_igvalue; scalar_t__ dig_twoport_algorithm; int dig_enable_flag; int /*<<< orphan*/  rssi_highpower_highthresh; int /*<<< orphan*/  rssi_highpower_lowthresh; int /*<<< orphan*/  rssi_highthresh; int /*<<< orphan*/  rssi_lowthresh; void* pre_ap_cstate; void* cur_ap_cstate; void* dig_highpwrstate; void* dig_state; scalar_t__ dig_slgorithm_switch; int /*<<< orphan*/  dig_dbgmode; void* dig_ext_port_stage; int /*<<< orphan*/  dig_algorithm; } ;
struct rtl_phy {int rf_type; int* default_initialgain; int /*<<< orphan*/  current_channel; } ;
struct TYPE_17__ {scalar_t__ link_state; scalar_t__ opmode; scalar_t__ act_scanning; } ;
struct TYPE_16__ {scalar_t__ rfpwr_state; } ;
struct false_alarm_statistics {int cnt_parity_fail; int cnt_rate_illegal; int cnt_crc8_fail; int cnt_mcs_fail; int cnt_ofdm_fail; int cnt_cck_fail; scalar_t__ cnt_all; } ;
struct rate_adaptive {int pre_ratr_state; int ratr_state; } ;
struct TYPE_13__ {int txbytesunicast; int rxbytesunicast; int* rx_rssi_percentage; } ;
struct TYPE_12__ {int* thermalmeter; } ;
struct TYPE_11__ {int (* read8_sync ) (struct rtl_priv*,int) ;int (* read16_sync ) (struct rtl_priv*,int) ;int (* read32_sync ) (struct rtl_priv*,int) ;int /*<<< orphan*/  (* write32_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write16_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write8_async ) (struct rtl_priv*,int,int) ;} ;
struct rtl_priv {TYPE_9__ dm; struct dig_t dm_digtable; struct rtl_phy phy; TYPE_8__ mac80211; TYPE_7__ psc; struct false_alarm_statistics falsealm_cnt; struct rate_adaptive ra; TYPE_6__* cfg; TYPE_4__ stats; TYPE_3__ efuse; TYPE_2__ io; } ;
struct rtl_mac {size_t vendor; scalar_t__ link_state; scalar_t__ mode; scalar_t__ opmode; int* bssid; struct ieee80211_vif* vif; } ;
struct rtl_hal {scalar_t__ state; } ;
struct rtl_efuse {int /*<<< orphan*/  eeprom_thermalmeter; } ;
struct ieee80211_vif {int dummy; } ;
struct TYPE_10__ {scalar_t__ status_driver_data; } ;
struct ieee80211_tx_info {TYPE_1__ status; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hw {struct rtl_priv* priv; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
typedef  enum radio_path { ____Placeholder_radio_path } radio_path ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_15__ {TYPE_5__* ops; scalar_t__ write_readback; } ;
struct TYPE_14__ {int (* get_bbreg ) (struct ieee80211_hw*,int,int) ;int (* get_rfreg ) (struct ieee80211_hw*,int,int,int) ;int /*<<< orphan*/  (* set_hw_reg ) (struct ieee80211_hw*,int /*<<< orphan*/ ,int*) ;int /*<<< orphan*/  (* get_hw_reg ) (struct ieee80211_hw*,int /*<<< orphan*/ ,int*) ;int /*<<< orphan*/  (* update_rate_tbl ) (struct ieee80211_hw*,struct ieee80211_sta*,int,int) ;int /*<<< orphan*/  (* set_rfreg ) (struct ieee80211_hw*,int,int,int,int) ;int /*<<< orphan*/  (* set_bbreg ) (struct ieee80211_hw*,int,int,int) ;} ;

/* Variables and functions */
 int AC0_BE ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int COMP_POWER ; 
 int COMP_POWER_TRACKING ; 
 int COMP_RATE ; 
 int DBG_LOUD ; 
 int DBG_TRACE ; 
 int /*<<< orphan*/  DIG_ALGO_BEFORE_CONNECT_BY_RSSI_AND_ALARM ; 
 int /*<<< orphan*/  DIG_ALGO_BY_TOW_PORT ; 
 void* DIG_AP_DISCONNECT ; 
 void* DIG_EXT_PORT_STAGE_MAX ; 
 scalar_t__ DIG_STA_BEFORE_CONNECT ; 
 scalar_t__ DIG_STA_CONNECT ; 
 scalar_t__ DIG_STA_DISCONNECT ; 
 scalar_t__ DIG_TWO_PORT_ALGO_FALSE_ALARM ; 
 void* DIG_TWO_PORT_ALGO_RSSI ; 
 int /*<<< orphan*/  DM_DBG_OFF ; 
 void* DM_DIG_BACKOFF_MAX ; 
 int DM_DIG_BACKOFF_MIN ; 
 int /*<<< orphan*/  DM_DIG_HIGH_PWR_THRESH_HIGH ; 
 int /*<<< orphan*/  DM_DIG_HIGH_PWR_THRESH_LOW ; 
 int DM_DIG_MAX ; 
 scalar_t__ DM_DIG_MIN ; 
 int /*<<< orphan*/  DM_DIG_THRESH_HIGH ; 
 int /*<<< orphan*/  DM_DIG_THRESH_LOW ; 
 scalar_t__ DM_FALSEALARM_THRESH_HIGH ; 
 scalar_t__ DM_FALSEALARM_THRESH_LOW ; 
#define  DM_RATR_STA_HIGH 131 
#define  DM_RATR_STA_LOW 130 
 void* DM_RATR_STA_MAX ; 
#define  DM_RATR_STA_MIDDLE 129 
#define  DM_RATR_STA_ULTRALOW 128 
 void* DM_STA_DIG_MAX ; 
 scalar_t__ DM_TYPE_BYDRIVER ; 
 int EDCAPARA_BE ; 
 scalar_t__ ERFON ; 
 int FW_CCA_CHK_ENABLE ; 
 int /*<<< orphan*/  FW_CMD_CTRL_DM_BY_DRIVER ; 
 int /*<<< orphan*/  FW_CMD_DIG_DISABLE ; 
 int /*<<< orphan*/  FW_CMD_DIG_ENABLE ; 
 int /*<<< orphan*/  FW_CMD_DIG_MODE_SS ; 
 int /*<<< orphan*/  FW_CMD_TXPWR_TRACK_THERMAL ; 
 int FW_TXPWR_TRACK_THERMAL ; 
 int HAL_DM_HIPWR_DISABLE ; 
 int /*<<< orphan*/  HW_VAR_AC_PARAM ; 
 int /*<<< orphan*/  HW_VAR_MRC ; 
 int IEEE80211_QOS_CTL_TID_MASK ; 
 struct ieee80211_tx_info* IEEE80211_SKB_CB (struct sk_buff*) ; 
 scalar_t__ MAC80211_LINKED ; 
 int MASKBYTE0 ; 
 int MASKDWORD ; 
 scalar_t__ NL80211_IFTYPE_ADHOC ; 
 scalar_t__ NL80211_IFTYPE_STATION ; 
 size_t RF90_PATH_A ; 
 size_t RF90_PATH_B ; 
 int RFREG_OFFSET_MASK ; 
 scalar_t__ RF_1T1R ; 
 scalar_t__ RF_1T2R ; 
 scalar_t__ RF_2T2R ; 
 int RF_T_METER ; 
 int ROFDM0_XAAGCCORE1 ; 
 int ROFDM0_XBAGCCORE1 ; 
 int ROFDM_PHYCOUNTER1 ; 
 int ROFDM_PHYCOUNTER2 ; 
 int ROFDM_PHYCOUNTER3 ; 
 void* TX_HIGHPWR_LEVEL_NORMAL ; 
 scalar_t__ TX_HIGHPWR_LEVEL_NORMAL1 ; 
 scalar_t__ TX_HIGHPWR_LEVEL_NORMAL2 ; 
 long TX_POWER_NEAR_FIELD_THRESH_LVL1 ; 
 long TX_POWER_NEAR_FIELD_THRESH_LVL2 ; 
 int WFM5 ; 
 scalar_t__ WIRELESS_MODE_B ; 
 scalar_t__ WIRELESS_MODE_G ; 
 scalar_t__ _HAL_STATE_START ; 
 scalar_t__ _HAL_STATE_STOP ; 
 int* edca_setting_dl ; 
 int* edca_setting_dl_gmode ; 
 int* edca_setting_ul ; 
 int hal_get_firmwareversion (struct rtl_priv*) ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int const*) ; 
 int* ieee80211_get_qos_ctl (struct ieee80211_hdr*) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int /*<<< orphan*/  rtl92s_phy_chk_fwcmd_iodone (struct ieee80211_hw*) ; 
 int /*<<< orphan*/  rtl92s_phy_set_fw_cmd (struct ieee80211_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtl92s_phy_set_txpower (struct ieee80211_hw*,int /*<<< orphan*/ ) ; 
 struct rtl_efuse* rtl_efuse (struct rtl_priv*) ; 
 struct rtl_hal* rtl_hal (struct rtl_priv*) ; 
 struct rtl_mac* rtl_mac (struct rtl_priv*) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 
 int stub1 (struct rtl_priv*,int) ; 
 int stub10 (struct ieee80211_hw*,int,int) ; 
 int /*<<< orphan*/  stub11 (struct ieee80211_hw*,int,int,int) ; 
 int stub12 (struct ieee80211_hw*,int,int,int) ; 
 int /*<<< orphan*/  stub13 (struct ieee80211_hw*,int,int,int,int) ; 
 int /*<<< orphan*/  stub14 (struct ieee80211_hw*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  stub15 (struct ieee80211_hw*,struct ieee80211_sta*,int,int) ; 
 int /*<<< orphan*/  stub16 (struct ieee80211_hw*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  stub17 (struct ieee80211_hw*,int /*<<< orphan*/ ,int*) ; 
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

__attribute__((used)) static void _rtl92s_dm_check_edca_turbo(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));

	static u64 last_txok_cnt;
	static u64 last_rxok_cnt;
	u64 cur_txok_cnt = 0;
	u64 cur_rxok_cnt = 0;

	u32 edca_be_ul = edca_setting_ul[mac->vendor];
	u32 edca_be_dl = edca_setting_dl[mac->vendor];
	u32 edca_gmode = edca_setting_dl_gmode[mac->vendor];

	if (mac->link_state != MAC80211_LINKED) {
		rtlpriv->dm.current_turbo_edca = false;
		goto dm_checkedcaturbo_exit;
	}

	if ((!rtlpriv->dm.is_any_nonbepkts) &&
	    (!rtlpriv->dm.disable_framebursting)) {
		cur_txok_cnt = rtlpriv->stats.txbytesunicast - last_txok_cnt;
		cur_rxok_cnt = rtlpriv->stats.rxbytesunicast - last_rxok_cnt;

		if (rtlpriv->phy.rf_type == RF_1T2R) {
			if (cur_txok_cnt > 4 * cur_rxok_cnt) {
				/* Uplink TP is present. */
				if (rtlpriv->dm.is_cur_rdlstate ||
					!rtlpriv->dm.current_turbo_edca) {
					rtl_write_dword(rtlpriv, EDCAPARA_BE,
							edca_be_ul);
					rtlpriv->dm.is_cur_rdlstate = false;
				}
			} else {/* Balance TP is present. */
				if (!rtlpriv->dm.is_cur_rdlstate ||
					!rtlpriv->dm.current_turbo_edca) {
					if (mac->mode == WIRELESS_MODE_G ||
					    mac->mode == WIRELESS_MODE_B)
						rtl_write_dword(rtlpriv,
								EDCAPARA_BE,
								edca_gmode);
					else
						rtl_write_dword(rtlpriv,
								EDCAPARA_BE,
								edca_be_dl);
					rtlpriv->dm.is_cur_rdlstate = true;
				}
			}
			rtlpriv->dm.current_turbo_edca = true;
		} else {
			if (cur_rxok_cnt > 4 * cur_txok_cnt) {
				if (!rtlpriv->dm.is_cur_rdlstate ||
					!rtlpriv->dm.current_turbo_edca) {
					if (mac->mode == WIRELESS_MODE_G ||
					    mac->mode == WIRELESS_MODE_B)
						rtl_write_dword(rtlpriv,
								EDCAPARA_BE,
								edca_gmode);
					else
						rtl_write_dword(rtlpriv,
								EDCAPARA_BE,
								edca_be_dl);
					rtlpriv->dm.is_cur_rdlstate = true;
				}
			} else {
				if (rtlpriv->dm.is_cur_rdlstate ||
					!rtlpriv->dm.current_turbo_edca) {
					rtl_write_dword(rtlpriv, EDCAPARA_BE,
							edca_be_ul);
					rtlpriv->dm.is_cur_rdlstate = false;
				}
			}
			rtlpriv->dm.current_turbo_edca = true;
		}
	} else {
		if (rtlpriv->dm.current_turbo_edca) {
			u8 tmp = AC0_BE;
			rtlpriv->cfg->ops->set_hw_reg(hw, HW_VAR_AC_PARAM,
						      &tmp);
			rtlpriv->dm.current_turbo_edca = false;
		}
	}

dm_checkedcaturbo_exit:
	rtlpriv->dm.is_any_nonbepkts = false;
	last_txok_cnt = rtlpriv->stats.txbytesunicast;
	last_rxok_cnt = rtlpriv->stats.rxbytesunicast;
}

__attribute__((used)) static void _rtl92s_dm_txpowertracking_callback_thermalmeter(
					struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_efuse *rtlefuse = rtl_efuse(rtl_priv(hw));
	u8 thermalvalue = 0;
	u32 fw_cmd = 0;

	rtlpriv->dm.txpower_trackinginit = true;

	thermalvalue = (u8)rtl_get_rfreg(hw, RF90_PATH_A, RF_T_METER, 0x1f);

	RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
		 "Readback Thermal Meter = 0x%x pre thermal meter 0x%x eeprom_thermal meter 0x%x\n",
		 thermalvalue,
		 rtlpriv->dm.thermalvalue, rtlefuse->eeprom_thermalmeter);

	if (thermalvalue) {
		rtlpriv->dm.thermalvalue = thermalvalue;
		if (hal_get_firmwareversion(rtlpriv) >= 0x35) {
			rtl92s_phy_set_fw_cmd(hw, FW_CMD_TXPWR_TRACK_THERMAL);
		} else {
			fw_cmd = (FW_TXPWR_TRACK_THERMAL |
				 (rtlpriv->efuse.thermalmeter[0] << 8) |
				 (thermalvalue << 16));

			RT_TRACE(rtlpriv, COMP_POWER_TRACKING, DBG_LOUD,
				 "Write to FW Thermal Val = 0x%x\n", fw_cmd);

			rtl_write_dword(rtlpriv, WFM5, fw_cmd);
			rtl92s_phy_chk_fwcmd_iodone(hw);
		}
	}

	rtlpriv->dm.txpowercount = 0;
}

__attribute__((used)) static void _rtl92s_dm_check_txpowertracking_thermalmeter(
					struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	u8 tx_power_checkcnt = 5;

	/* 2T2R TP issue */
	if (rtlphy->rf_type == RF_2T2R)
		return;

	if (!rtlpriv->dm.txpower_tracking)
		return;

	if (rtlpriv->dm.txpowercount <= tx_power_checkcnt) {
		rtlpriv->dm.txpowercount++;
		return;
	}

	if (!rtlpriv->dm.tm_trigger) {
		rtl_set_rfreg(hw, RF90_PATH_A, RF_T_METER,
			      RFREG_OFFSET_MASK, 0x60);
		rtlpriv->dm.tm_trigger = 1;
	} else {
		_rtl92s_dm_txpowertracking_callback_thermalmeter(hw);
		rtlpriv->dm.tm_trigger = 0;
	}
}

__attribute__((used)) static void _rtl92s_dm_refresh_rateadaptive_mask(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	struct rate_adaptive *ra = &(rtlpriv->ra);
	struct ieee80211_sta *sta = NULL;
	u32 low_rssi_thresh = 0;
	u32 middle_rssi_thresh = 0;
	u32 high_rssi_thresh = 0;

	if (is_hal_stop(rtlhal))
		return;

	if (!rtlpriv->dm.useramask)
		return;

	if (hal_get_firmwareversion(rtlpriv) >= 61 &&
	    !rtlpriv->dm.inform_fw_driverctrldm) {
		rtl92s_phy_set_fw_cmd(hw, FW_CMD_CTRL_DM_BY_DRIVER);
		rtlpriv->dm.inform_fw_driverctrldm = true;
	}

	if ((mac->link_state == MAC80211_LINKED) &&
	    (mac->opmode == NL80211_IFTYPE_STATION)) {
		switch (ra->pre_ratr_state) {
		case DM_RATR_STA_HIGH:
			high_rssi_thresh = 40;
			middle_rssi_thresh = 30;
			low_rssi_thresh = 20;
			break;
		case DM_RATR_STA_MIDDLE:
			high_rssi_thresh = 44;
			middle_rssi_thresh = 30;
			low_rssi_thresh = 20;
			break;
		case DM_RATR_STA_LOW:
			high_rssi_thresh = 44;
			middle_rssi_thresh = 34;
			low_rssi_thresh = 20;
			break;
		case DM_RATR_STA_ULTRALOW:
			high_rssi_thresh = 44;
			middle_rssi_thresh = 34;
			low_rssi_thresh = 24;
			break;
		default:
			high_rssi_thresh = 44;
			middle_rssi_thresh = 34;
			low_rssi_thresh = 24;
			break;
		}

		if (rtlpriv->dm.undec_sm_pwdb > (long)high_rssi_thresh) {
			ra->ratr_state = DM_RATR_STA_HIGH;
		} else if (rtlpriv->dm.undec_sm_pwdb >
			   (long)middle_rssi_thresh) {
			ra->ratr_state = DM_RATR_STA_LOW;
		} else if (rtlpriv->dm.undec_sm_pwdb >
			   (long)low_rssi_thresh) {
			ra->ratr_state = DM_RATR_STA_LOW;
		} else {
			ra->ratr_state = DM_RATR_STA_ULTRALOW;
		}

		if (ra->pre_ratr_state != ra->ratr_state) {
			RT_TRACE(rtlpriv, COMP_RATE, DBG_LOUD,
				 "RSSI = %ld RSSI_LEVEL = %d PreState = %d, CurState = %d\n",
				 rtlpriv->dm.undec_sm_pwdb, ra->ratr_state,
				 ra->pre_ratr_state, ra->ratr_state);

			rcu_read_lock();
			sta = rtl_find_sta(hw, mac->bssid);
			if (sta)
				rtlpriv->cfg->ops->update_rate_tbl(hw, sta,
							   ra->ratr_state,
							   true);
			rcu_read_unlock();

			ra->pre_ratr_state = ra->ratr_state;
		}
	}
}

__attribute__((used)) static void _rtl92s_dm_switch_baseband_mrc(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_hal *rtlhal = rtl_hal(rtl_priv(hw));
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	bool current_mrc;
	bool enable_mrc = true;
	long tmpentry_maxpwdb = 0;
	u8 rssi_a = 0;
	u8 rssi_b = 0;

	if (is_hal_stop(rtlhal))
		return;

	if ((rtlphy->rf_type == RF_1T1R) || (rtlphy->rf_type == RF_2T2R))
		return;

	rtlpriv->cfg->ops->get_hw_reg(hw, HW_VAR_MRC, (u8 *)(&current_mrc));

	if (mac->link_state >= MAC80211_LINKED) {
		if (rtlpriv->dm.undec_sm_pwdb > tmpentry_maxpwdb) {
			rssi_a = rtlpriv->stats.rx_rssi_percentage[RF90_PATH_A];
			rssi_b = rtlpriv->stats.rx_rssi_percentage[RF90_PATH_B];
		}
	}

	/* MRC settings would NOT affect TP on Wireless B mode. */
	if (mac->mode != WIRELESS_MODE_B) {
		if ((rssi_a == 0) && (rssi_b == 0)) {
			enable_mrc = true;
		} else if (rssi_b > 30) {
			/* Turn on B-Path */
			enable_mrc = true;
		} else if (rssi_b < 5) {
			/* Turn off B-path  */
			enable_mrc = false;
		/* Take care of RSSI differentiation. */
		} else if (rssi_a > 15 && (rssi_a >= rssi_b)) {
			if ((rssi_a - rssi_b) > 15)
				/* Turn off B-path  */
				enable_mrc = false;
			else if ((rssi_a - rssi_b) < 10)
				/* Turn on B-Path */
				enable_mrc = true;
			else
				enable_mrc = current_mrc;
		} else {
			/* Turn on B-Path */
			enable_mrc = true;
		}
	}

	/* Update MRC settings if needed. */
	if (enable_mrc != current_mrc)
		rtlpriv->cfg->ops->set_hw_reg(hw, HW_VAR_MRC,
					      (u8 *)&enable_mrc);

}

void rtl92s_dm_init_edca_turbo(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	rtlpriv->dm.current_turbo_edca = false;
	rtlpriv->dm.is_any_nonbepkts = false;
	rtlpriv->dm.is_cur_rdlstate = false;
}

__attribute__((used)) static void _rtl92s_dm_init_rate_adaptive_mask(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rate_adaptive *ra = &(rtlpriv->ra);

	ra->ratr_state = DM_RATR_STA_MAX;
	ra->pre_ratr_state = DM_RATR_STA_MAX;

	if (rtlpriv->dm.dm_type == DM_TYPE_BYDRIVER &&
	    hal_get_firmwareversion(rtlpriv) >= 60)
		rtlpriv->dm.useramask = true;
	else
		rtlpriv->dm.useramask = false;

	rtlpriv->dm.useramask = false;
	rtlpriv->dm.inform_fw_driverctrldm = false;
}

__attribute__((used)) static void _rtl92s_dm_init_txpowertracking_thermalmeter(
				struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	rtlpriv->dm.txpower_tracking = true;
	rtlpriv->dm.txpowercount = 0;
	rtlpriv->dm.txpower_trackinginit = false;
}

__attribute__((used)) static void _rtl92s_dm_false_alarm_counter_statistics(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct false_alarm_statistics *falsealm_cnt = &(rtlpriv->falsealm_cnt);
	u32 ret_value;

	ret_value = rtl_get_bbreg(hw, ROFDM_PHYCOUNTER1, MASKDWORD);
	falsealm_cnt->cnt_parity_fail = ((ret_value & 0xffff0000) >> 16);

	ret_value = rtl_get_bbreg(hw, ROFDM_PHYCOUNTER2, MASKDWORD);
	falsealm_cnt->cnt_rate_illegal = (ret_value & 0xffff);
	falsealm_cnt->cnt_crc8_fail = ((ret_value & 0xffff0000) >> 16);
	ret_value = rtl_get_bbreg(hw, ROFDM_PHYCOUNTER3, MASKDWORD);
	falsealm_cnt->cnt_mcs_fail = (ret_value & 0xffff);

	falsealm_cnt->cnt_ofdm_fail = falsealm_cnt->cnt_parity_fail +
		falsealm_cnt->cnt_rate_illegal + falsealm_cnt->cnt_crc8_fail +
		falsealm_cnt->cnt_mcs_fail;

	/* read CCK false alarm */
	ret_value = rtl_get_bbreg(hw, 0xc64, MASKDWORD);
	falsealm_cnt->cnt_cck_fail = (ret_value & 0xffff);
	falsealm_cnt->cnt_all =	falsealm_cnt->cnt_ofdm_fail +
		falsealm_cnt->cnt_cck_fail;
}

__attribute__((used)) static void rtl92s_backoff_enable_flag(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct dig_t *digtable = &rtlpriv->dm_digtable;
	struct false_alarm_statistics *falsealm_cnt = &(rtlpriv->falsealm_cnt);

	if (falsealm_cnt->cnt_all > digtable->fa_highthresh) {
		if ((digtable->back_val - 6) <
			digtable->backoffval_range_min)
			digtable->back_val = digtable->backoffval_range_min;
		else
			digtable->back_val -= 6;
	} else if (falsealm_cnt->cnt_all < digtable->fa_lowthresh) {
		if ((digtable->back_val + 6) >
			digtable->backoffval_range_max)
			digtable->back_val =
				 digtable->backoffval_range_max;
		else
			digtable->back_val += 6;
	}
}

__attribute__((used)) static void _rtl92s_dm_initial_gain_sta_beforeconnect(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct dig_t *digtable = &rtlpriv->dm_digtable;
	struct false_alarm_statistics *falsealm_cnt = &(rtlpriv->falsealm_cnt);
	static u8 initialized, force_write;
	u8 initial_gain = 0;

	if ((digtable->pre_sta_cstate == digtable->cur_sta_cstate) ||
	    (digtable->cur_sta_cstate == DIG_STA_BEFORE_CONNECT)) {
		if (digtable->cur_sta_cstate == DIG_STA_BEFORE_CONNECT) {
			if (rtlpriv->psc.rfpwr_state != ERFON)
				return;

			if (digtable->backoff_enable_flag)
				rtl92s_backoff_enable_flag(hw);
			else
				digtable->back_val = DM_DIG_BACKOFF_MAX;

			if ((digtable->rssi_val + 10 - digtable->back_val) >
				digtable->rx_gain_max)
				digtable->cur_igvalue =
						digtable->rx_gain_max;
			else if ((digtable->rssi_val + 10 - digtable->back_val)
				 < digtable->rx_gain_min)
				digtable->cur_igvalue =
						digtable->rx_gain_min;
			else
				digtable->cur_igvalue = digtable->rssi_val + 10
					- digtable->back_val;

			if (falsealm_cnt->cnt_all > 10000)
				digtable->cur_igvalue =
					 (digtable->cur_igvalue > 0x33) ?
					 digtable->cur_igvalue : 0x33;

			if (falsealm_cnt->cnt_all > 16000)
				digtable->cur_igvalue =
						 digtable->rx_gain_max;
		/* connected -> connected or disconnected -> disconnected  */
		} else {
			/* Firmware control DIG, do nothing in driver dm */
			return;
		}
		/* disconnected -> connected or connected ->
		 * disconnected or beforeconnect->(dis)connected */
	} else {
		/* Enable FW DIG */
		digtable->dig_ext_port_stage = DIG_EXT_PORT_STAGE_MAX;
		rtl92s_phy_set_fw_cmd(hw, FW_CMD_DIG_ENABLE);

		digtable->back_val = DM_DIG_BACKOFF_MAX;
		digtable->cur_igvalue = rtlpriv->phy.default_initialgain[0];
		digtable->pre_igvalue = 0;
		return;
	}

	/* Forced writing to prevent from fw-dig overwriting. */
	if (digtable->pre_igvalue != rtl_get_bbreg(hw, ROFDM0_XAAGCCORE1,
						  MASKBYTE0))
		force_write = 1;

	if ((digtable->pre_igvalue != digtable->cur_igvalue) ||
	    !initialized || force_write) {
		/* Disable FW DIG */
		rtl92s_phy_set_fw_cmd(hw, FW_CMD_DIG_DISABLE);

		initial_gain = (u8)digtable->cur_igvalue;

		/* Set initial gain. */
		rtl_set_bbreg(hw, ROFDM0_XAAGCCORE1, MASKBYTE0, initial_gain);
		rtl_set_bbreg(hw, ROFDM0_XBAGCCORE1, MASKBYTE0, initial_gain);
		digtable->pre_igvalue = digtable->cur_igvalue;
		initialized = 1;
		force_write = 0;
	}
}

__attribute__((used)) static void _rtl92s_dm_ctrl_initgain_bytwoport(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct dig_t *dig = &rtlpriv->dm_digtable;

	if (rtlpriv->mac80211.act_scanning)
		return;

	/* Decide the current status and if modify initial gain or not */
	if (rtlpriv->mac80211.link_state >= MAC80211_LINKED ||
	    rtlpriv->mac80211.opmode == NL80211_IFTYPE_ADHOC)
		dig->cur_sta_cstate = DIG_STA_CONNECT;
	else
		dig->cur_sta_cstate = DIG_STA_DISCONNECT;

	dig->rssi_val = rtlpriv->dm.undec_sm_pwdb;

	/* Change dig mode to rssi */
	if (dig->cur_sta_cstate != DIG_STA_DISCONNECT) {
		if (dig->dig_twoport_algorithm ==
		    DIG_TWO_PORT_ALGO_FALSE_ALARM) {
			dig->dig_twoport_algorithm = DIG_TWO_PORT_ALGO_RSSI;
			rtl92s_phy_set_fw_cmd(hw, FW_CMD_DIG_MODE_SS);
		}
	}

	_rtl92s_dm_false_alarm_counter_statistics(hw);
	_rtl92s_dm_initial_gain_sta_beforeconnect(hw);

	dig->pre_sta_cstate = dig->cur_sta_cstate;
}

__attribute__((used)) static void _rtl92s_dm_ctrl_initgain_byrssi(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct dig_t *digtable = &rtlpriv->dm_digtable;

	/* 2T2R TP issue */
	if (rtlphy->rf_type == RF_2T2R)
		return;

	if (!rtlpriv->dm.dm_initialgain_enable)
		return;

	if (digtable->dig_enable_flag == false)
		return;

	_rtl92s_dm_ctrl_initgain_bytwoport(hw);
}

__attribute__((used)) static void _rtl92s_dm_dynamic_txpower(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct rtl_phy *rtlphy = &(rtlpriv->phy);
	struct rtl_mac *mac = rtl_mac(rtl_priv(hw));
	long undec_sm_pwdb;
	long txpwr_threshold_lv1, txpwr_threshold_lv2;

	/* 2T2R TP issue */
	if (rtlphy->rf_type == RF_2T2R)
		return;

	if (!rtlpriv->dm.dynamic_txpower_enable ||
	    rtlpriv->dm.dm_flag & HAL_DM_HIPWR_DISABLE) {
		rtlpriv->dm.dynamic_txhighpower_lvl = TX_HIGHPWR_LEVEL_NORMAL;
		return;
	}

	if ((mac->link_state < MAC80211_LINKED) &&
	    (rtlpriv->dm.entry_min_undec_sm_pwdb == 0)) {
		RT_TRACE(rtlpriv, COMP_POWER, DBG_TRACE,
			 "Not connected to any\n");

		rtlpriv->dm.dynamic_txhighpower_lvl = TX_HIGHPWR_LEVEL_NORMAL;

		rtlpriv->dm.last_dtp_lvl = TX_HIGHPWR_LEVEL_NORMAL;
		return;
	}

	if (mac->link_state >= MAC80211_LINKED) {
		if (mac->opmode == NL80211_IFTYPE_ADHOC) {
			undec_sm_pwdb = rtlpriv->dm.entry_min_undec_sm_pwdb;
			RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
				 "AP Client PWDB = 0x%lx\n",
				 undec_sm_pwdb);
		} else {
			undec_sm_pwdb = rtlpriv->dm.undec_sm_pwdb;
			RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
				 "STA Default Port PWDB = 0x%lx\n",
				 undec_sm_pwdb);
		}
	} else {
		undec_sm_pwdb = rtlpriv->dm.entry_min_undec_sm_pwdb;

		RT_TRACE(rtlpriv, COMP_POWER, DBG_LOUD,
			 "AP Ext Port PWDB = 0x%lx\n",
			 undec_sm_pwdb);
	}

	txpwr_threshold_lv2 = TX_POWER_NEAR_FIELD_THRESH_LVL2;
	txpwr_threshold_lv1 = TX_POWER_NEAR_FIELD_THRESH_LVL1;

	if (rtl_get_bbreg(hw, 0xc90, MASKBYTE0) == 1)
		rtlpriv->dm.dynamic_txhighpower_lvl = TX_HIGHPWR_LEVEL_NORMAL;
	else if (undec_sm_pwdb >= txpwr_threshold_lv2)
		rtlpriv->dm.dynamic_txhighpower_lvl = TX_HIGHPWR_LEVEL_NORMAL2;
	else if ((undec_sm_pwdb < (txpwr_threshold_lv2 - 3)) &&
		(undec_sm_pwdb >= txpwr_threshold_lv1))
		rtlpriv->dm.dynamic_txhighpower_lvl = TX_HIGHPWR_LEVEL_NORMAL1;
	else if (undec_sm_pwdb < (txpwr_threshold_lv1 - 3))
		rtlpriv->dm.dynamic_txhighpower_lvl = TX_HIGHPWR_LEVEL_NORMAL;

	if ((rtlpriv->dm.dynamic_txhighpower_lvl != rtlpriv->dm.last_dtp_lvl))
		rtl92s_phy_set_txpower(hw, rtlphy->current_channel);

	rtlpriv->dm.last_dtp_lvl = rtlpriv->dm.dynamic_txhighpower_lvl;
}

__attribute__((used)) static void _rtl92s_dm_init_dig(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	struct dig_t *digtable = &rtlpriv->dm_digtable;

	/* Disable DIG scheme now.*/
	digtable->dig_enable_flag = true;
	digtable->backoff_enable_flag = true;

	if ((rtlpriv->dm.dm_type == DM_TYPE_BYDRIVER) &&
	    (hal_get_firmwareversion(rtlpriv) >= 0x3c))
		digtable->dig_algorithm = DIG_ALGO_BY_TOW_PORT;
	else
		digtable->dig_algorithm =
			 DIG_ALGO_BEFORE_CONNECT_BY_RSSI_AND_ALARM;

	digtable->dig_twoport_algorithm = DIG_TWO_PORT_ALGO_RSSI;
	digtable->dig_ext_port_stage = DIG_EXT_PORT_STAGE_MAX;
	/* off=by real rssi value, on=by digtable->rssi_val for new dig */
	digtable->dig_dbgmode = DM_DBG_OFF;
	digtable->dig_slgorithm_switch = 0;

	/* 2007/10/04 MH Define init gain threshol. */
	digtable->dig_state = DM_STA_DIG_MAX;
	digtable->dig_highpwrstate = DM_STA_DIG_MAX;

	digtable->cur_sta_cstate = DIG_STA_DISCONNECT;
	digtable->pre_sta_cstate = DIG_STA_DISCONNECT;
	digtable->cur_ap_cstate = DIG_AP_DISCONNECT;
	digtable->pre_ap_cstate = DIG_AP_DISCONNECT;

	digtable->rssi_lowthresh = DM_DIG_THRESH_LOW;
	digtable->rssi_highthresh = DM_DIG_THRESH_HIGH;

	digtable->fa_lowthresh = DM_FALSEALARM_THRESH_LOW;
	digtable->fa_highthresh = DM_FALSEALARM_THRESH_HIGH;

	digtable->rssi_highpower_lowthresh = DM_DIG_HIGH_PWR_THRESH_LOW;
	digtable->rssi_highpower_highthresh = DM_DIG_HIGH_PWR_THRESH_HIGH;

	/* for dig debug rssi value */
	digtable->rssi_val = 50;
	digtable->back_val = DM_DIG_BACKOFF_MAX;
	digtable->rx_gain_max = DM_DIG_MAX;

	digtable->rx_gain_min = DM_DIG_MIN;

	digtable->backoffval_range_max = DM_DIG_BACKOFF_MAX;
	digtable->backoffval_range_min = DM_DIG_BACKOFF_MIN;
}

__attribute__((used)) static void _rtl92s_dm_init_dynamic_txpower(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	if ((hal_get_firmwareversion(rtlpriv) >= 60) &&
	    (rtlpriv->dm.dm_type == DM_TYPE_BYDRIVER))
		rtlpriv->dm.dynamic_txpower_enable = true;
	else
		rtlpriv->dm.dynamic_txpower_enable = false;

	rtlpriv->dm.last_dtp_lvl = TX_HIGHPWR_LEVEL_NORMAL;
	rtlpriv->dm.dynamic_txhighpower_lvl = TX_HIGHPWR_LEVEL_NORMAL;
}

void rtl92s_dm_init(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	rtlpriv->dm.dm_type = DM_TYPE_BYDRIVER;
	rtlpriv->dm.undec_sm_pwdb = -1;

	_rtl92s_dm_init_dynamic_txpower(hw);
	rtl92s_dm_init_edca_turbo(hw);
	_rtl92s_dm_init_rate_adaptive_mask(hw);
	_rtl92s_dm_init_txpowertracking_thermalmeter(hw);
	_rtl92s_dm_init_dig(hw);

	rtl_write_dword(rtlpriv, WFM5, FW_CCA_CHK_ENABLE);
}

void rtl92s_dm_watchdog(struct ieee80211_hw *hw)
{
	_rtl92s_dm_check_edca_turbo(hw);
	_rtl92s_dm_check_txpowertracking_thermalmeter(hw);
	_rtl92s_dm_ctrl_initgain_byrssi(hw);
	_rtl92s_dm_dynamic_txpower(hw);
	_rtl92s_dm_refresh_rateadaptive_mask(hw);
	_rtl92s_dm_switch_baseband_mrc(hw);
}

