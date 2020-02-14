#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {scalar_t__ data; } ;
struct TYPE_6__ {int (* read8_sync ) (struct rtl_priv*,int) ;int (* read16_sync ) (struct rtl_priv*,int) ;int (* read32_sync ) (struct rtl_priv*,int) ;int /*<<< orphan*/  (* write32_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write16_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write8_async ) (struct rtl_priv*,int,int) ;} ;
struct rtl_priv {TYPE_4__* cfg; TYPE_2__ io; } ;
struct rtl_phy {int rf_type; } ;
struct rtl_mac {struct ieee80211_vif* vif; } ;
struct rtl_hal {scalar_t__ state; } ;
struct ieee80211_vif {int dummy; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hw {struct rtl_priv* priv; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
struct halmac_api {int dummy; } ;
struct TYPE_5__ {scalar_t__ api_state; scalar_t__ dlfw_state; int mac_power; int /*<<< orphan*/  ps_state; } ;
struct halmac_adapter {scalar_t__ halmac_api; void* driver_adapter; TYPE_1__ halmac_state; struct halmac_adapter* hal_adapter_backup; } ;
typedef  enum radio_path { ____Placeholder_radio_path } radio_path ;
typedef  enum halmac_ret_status { ____Placeholder_halmac_ret_status } halmac_ret_status ;
typedef  enum halmac_mac_power { ____Placeholder_halmac_mac_power } halmac_mac_power ;
typedef  enum halmac_intf_phy_platform { ____Placeholder_halmac_intf_phy_platform } halmac_intf_phy_platform ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_8__ {TYPE_3__* ops; scalar_t__ write_readback; } ;
struct TYPE_7__ {int (* get_bbreg ) (struct ieee80211_hw*,int,int) ;int (* get_rfreg ) (struct ieee80211_hw*,int,int,int) ;int /*<<< orphan*/  (* set_rfreg ) (struct ieee80211_hw*,int,int,int,int) ;int /*<<< orphan*/  (* set_bbreg ) (struct ieee80211_hw*,int,int,int) ;} ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DBG_DMESG ; 
 int /*<<< orphan*/  DBG_WARNING ; 
 int /*<<< orphan*/  HALMAC_API_MAC_POWER_SWITCH ; 
 int /*<<< orphan*/  HALMAC_API_PHY_CFG ; 
 scalar_t__ HALMAC_API_STATE_INIT ; 
 scalar_t__ HALMAC_DLFW_DONE ; 
 scalar_t__ HALMAC_DLFW_NONE ; 
 scalar_t__ HALMAC_GEN_INFO_SENT ; 
 int HALMAC_MAC_POWER_OFF ; 
 int HALMAC_MAC_POWER_ON ; 
 int /*<<< orphan*/  HALMAC_MSG_PWR ; 
 int /*<<< orphan*/  HALMAC_PS_STATE_ACT ; 
 int /*<<< orphan*/  HALMAC_PS_STATE_UNDEFINE ; 
 int /*<<< orphan*/  HALMAC_PWR_CUT_ALL_MSK ; 
 int /*<<< orphan*/  HALMAC_PWR_FAB_TSMC_MSK ; 
 int HALMAC_PWR_INTF_USB_MSK ; 
 int HALMAC_REG_READ_8 (struct halmac_adapter*,scalar_t__) ; 
 int /*<<< orphan*/  HALMAC_REG_WRITE_8 (struct halmac_adapter*,scalar_t__,int) ; 
 int HALMAC_RET_ADAPTER_INVALID ; 
 int HALMAC_RET_API_INVALID ; 
 int HALMAC_RET_NO_DLFW ; 
 int HALMAC_RET_POWER_OFF_FAIL ; 
 int HALMAC_RET_POWER_ON_FAIL ; 
 int HALMAC_RET_PWR_UNCHANGE ; 
 int HALMAC_RET_SUCCESS ; 
 int /*<<< orphan*/  HALMAC_RTL8822B_USB2_PHY ; 
 int /*<<< orphan*/  HALMAC_RTL8822B_USB3_PHY ; 
 int /*<<< orphan*/  HALMAC_RT_TRACE (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  HAL_INTF_PHY_USB2 ; 
 int /*<<< orphan*/  HAL_INTF_PHY_USB3 ; 
 int IEEE80211_QOS_CTL_TID_MASK ; 
 scalar_t__ REG_CR ; 
 scalar_t__ REG_SYS_STATUS1 ; 
 scalar_t__ _HAL_STATE_START ; 
 scalar_t__ _HAL_STATE_STOP ; 
 int /*<<< orphan*/  halmac_8822b_card_disable_flow ; 
 int /*<<< orphan*/  halmac_8822b_card_enable_flow ; 
 int /*<<< orphan*/  halmac_api_record_id_88xx (struct halmac_adapter*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  halmac_init_adapter_dynamic_para_88xx (struct halmac_adapter*) ; 
 int halmac_parse_intf_phy_88xx (struct halmac_adapter*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int halmac_pwr_seq_parser_88xx (struct halmac_adapter*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int const*) ; 
 int* ieee80211_get_qos_ctl (struct ieee80211_hdr*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
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
	return (rtlhal->state == _HAL_STATE_STOP);
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

__attribute__((used)) static inline enum halmac_ret_status
halmac_adapter_validate(struct halmac_adapter *halmac_adapter)
{
	if ((!halmac_adapter) ||
	    (halmac_adapter->hal_adapter_backup != halmac_adapter))
		return HALMAC_RET_ADAPTER_INVALID;

	return HALMAC_RET_SUCCESS;
}

__attribute__((used)) static inline enum halmac_ret_status
halmac_api_validate(struct halmac_adapter *halmac_adapter)
{
	if (halmac_adapter->halmac_state.api_state != HALMAC_API_STATE_INIT)
		return HALMAC_RET_API_INVALID;

	return HALMAC_RET_SUCCESS;
}

__attribute__((used)) static inline enum halmac_ret_status
halmac_fw_validate(struct halmac_adapter *halmac_adapter)
{
	if (halmac_adapter->halmac_state.dlfw_state != HALMAC_DLFW_DONE &&
	    halmac_adapter->halmac_state.dlfw_state != HALMAC_GEN_INFO_SENT)
		return HALMAC_RET_NO_DLFW;

	return HALMAC_RET_SUCCESS;
}

enum halmac_ret_status
halmac_mac_power_switch_8822b_usb(struct halmac_adapter *halmac_adapter,
				  enum halmac_mac_power halmac_power)
{
	u8 interface_mask;
	u8 value8;
	void *driver_adapter = NULL;
	struct halmac_api *halmac_api;

	if (halmac_adapter_validate(halmac_adapter) != HALMAC_RET_SUCCESS)
		return HALMAC_RET_ADAPTER_INVALID;

	if (halmac_api_validate(halmac_adapter) != HALMAC_RET_SUCCESS)
		return HALMAC_RET_API_INVALID;

	halmac_api_record_id_88xx(halmac_adapter, HALMAC_API_MAC_POWER_SWITCH);

	driver_adapter = halmac_adapter->driver_adapter;
	halmac_api = (struct halmac_api *)halmac_adapter->halmac_api;

	HALMAC_RT_TRACE(
		driver_adapter, HALMAC_MSG_PWR, DBG_DMESG,
		"halmac_mac_power_switch_88xx_usb halmac_power = %x ==========>\n",
		halmac_power);

	interface_mask = HALMAC_PWR_INTF_USB_MSK;

	value8 = HALMAC_REG_READ_8(halmac_adapter, REG_CR);
	if (value8 == 0xEA) {
		halmac_adapter->halmac_state.mac_power = HALMAC_MAC_POWER_OFF;
	} else {
		if (BIT(0) ==
		    (HALMAC_REG_READ_8(halmac_adapter, REG_SYS_STATUS1 + 1) &
		     BIT(0)))
			halmac_adapter->halmac_state.mac_power =
				HALMAC_MAC_POWER_OFF;
		else
			halmac_adapter->halmac_state.mac_power =
				HALMAC_MAC_POWER_ON;
	}

	/*Check if power switch is needed*/
	if (halmac_power == HALMAC_MAC_POWER_ON &&
	    halmac_adapter->halmac_state.mac_power == HALMAC_MAC_POWER_ON) {
		HALMAC_RT_TRACE(
			driver_adapter, HALMAC_MSG_PWR, DBG_WARNING,
			"halmac_mac_power_switch power state unchange!\n");
		return HALMAC_RET_PWR_UNCHANGE;
	}
	if (halmac_power == HALMAC_MAC_POWER_OFF) {
		if (halmac_pwr_seq_parser_88xx(
			    halmac_adapter, HALMAC_PWR_CUT_ALL_MSK,
			    HALMAC_PWR_FAB_TSMC_MSK, interface_mask,
			    halmac_8822b_card_disable_flow) !=
		    HALMAC_RET_SUCCESS) {
			pr_err("Handle power off cmd error\n");
			return HALMAC_RET_POWER_OFF_FAIL;
		}

		halmac_adapter->halmac_state.mac_power = HALMAC_MAC_POWER_OFF;
		halmac_adapter->halmac_state.ps_state =
			HALMAC_PS_STATE_UNDEFINE;
		halmac_adapter->halmac_state.dlfw_state = HALMAC_DLFW_NONE;
		halmac_init_adapter_dynamic_para_88xx(halmac_adapter);
	} else {
		if (halmac_pwr_seq_parser_88xx(
			    halmac_adapter, HALMAC_PWR_CUT_ALL_MSK,
			    HALMAC_PWR_FAB_TSMC_MSK, interface_mask,
			    halmac_8822b_card_enable_flow) !=
		    HALMAC_RET_SUCCESS) {
			pr_err("Handle power on cmd error\n");
			return HALMAC_RET_POWER_ON_FAIL;
		}

		HALMAC_REG_WRITE_8(
			halmac_adapter, REG_SYS_STATUS1 + 1,
			HALMAC_REG_READ_8(halmac_adapter, REG_SYS_STATUS1 + 1) &
				~(BIT(0)));

		halmac_adapter->halmac_state.mac_power = HALMAC_MAC_POWER_ON;
		halmac_adapter->halmac_state.ps_state = HALMAC_PS_STATE_ACT;
	}

	HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_PWR, DBG_DMESG,
			"halmac_mac_power_switch_88xx_usb <==========\n");

	return HALMAC_RET_SUCCESS;
}

enum halmac_ret_status
halmac_phy_cfg_8822b_usb(struct halmac_adapter *halmac_adapter,
			 enum halmac_intf_phy_platform platform)
{
	void *driver_adapter = NULL;
	enum halmac_ret_status status = HALMAC_RET_SUCCESS;
	struct halmac_api *halmac_api;

	if (halmac_adapter_validate(halmac_adapter) != HALMAC_RET_SUCCESS)
		return HALMAC_RET_ADAPTER_INVALID;

	if (halmac_api_validate(halmac_adapter) != HALMAC_RET_SUCCESS)
		return HALMAC_RET_API_INVALID;

	halmac_api_record_id_88xx(halmac_adapter, HALMAC_API_PHY_CFG);

	driver_adapter = halmac_adapter->driver_adapter;
	halmac_api = (struct halmac_api *)halmac_adapter->halmac_api;

	HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_PWR, DBG_DMESG,
			"halmac_phy_cfg ==========>\n");

	status = halmac_parse_intf_phy_88xx(halmac_adapter,
					    HALMAC_RTL8822B_USB2_PHY, platform,
					    HAL_INTF_PHY_USB2);

	if (status != HALMAC_RET_SUCCESS)
		return status;

	status = halmac_parse_intf_phy_88xx(halmac_adapter,
					    HALMAC_RTL8822B_USB3_PHY, platform,
					    HAL_INTF_PHY_USB3);

	if (status != HALMAC_RET_SUCCESS)
		return status;

	HALMAC_RT_TRACE(driver_adapter, HALMAC_MSG_PWR, DBG_DMESG,
			"halmac_phy_cfg <==========\n");

	return HALMAC_RET_SUCCESS;
}

enum halmac_ret_status halmac_interface_integration_tuning_8822b_usb(
	struct halmac_adapter *halmac_adapter)
{
	return HALMAC_RET_SUCCESS;
}

