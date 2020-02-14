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
struct TYPE_10__ {int use_defaultkey; int pairwise_enc_algorithm; int hwsec_cam_bitmap; int** hwsec_cam_sta_addr; int /*<<< orphan*/ * pairwise_key; int /*<<< orphan*/  key_len; int /*<<< orphan*/  key_buf; void* group_enc_algorithm; } ;
struct TYPE_7__ {int (* read8_sync ) (struct rtl_priv*,int) ;int (* read16_sync ) (struct rtl_priv*,int) ;int (* read32_sync ) (struct rtl_priv*,int) ;int /*<<< orphan*/  (* write32_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write16_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write8_async ) (struct rtl_priv*,int,int) ;} ;
struct rtl_priv {TYPE_5__ sec; TYPE_4__* cfg; TYPE_2__ io; } ;
struct rtl_phy {int rf_type; } ;
struct rtl_mac {struct ieee80211_vif* vif; } ;
struct rtl_hal {scalar_t__ state; } ;
struct ieee80211_vif {int dummy; } ;
struct TYPE_6__ {scalar_t__ status_driver_data; } ;
struct ieee80211_tx_info {TYPE_1__ status; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hw {struct rtl_priv* priv; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
typedef  enum radio_path { ____Placeholder_radio_path } radio_path ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_9__ {int* maps; TYPE_3__* ops; scalar_t__ write_readback; } ;
struct TYPE_8__ {int (* get_bbreg ) (struct ieee80211_hw*,int,int) ;int (* get_rfreg ) (struct ieee80211_hw*,int,int,int) ;int /*<<< orphan*/  (* set_rfreg ) (struct ieee80211_hw*,int,int,int,int) ;int /*<<< orphan*/  (* set_bbreg ) (struct ieee80211_hw*,int,int,int) ;} ;

/* Variables and functions */
#define  AESCCMP_ENCRYPTION 131 
 int BIT (int) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int CAM_CONTENT_COUNT ; 
 int CFG_VALID ; 
 int /*<<< orphan*/  COMP_ERR ; 
 int /*<<< orphan*/  COMP_SEC ; 
 int DBG_DMESG ; 
 int DBG_LOUD ; 
 int DBG_WARNING ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 int IEEE80211_QOS_CTL_TID_MASK ; 
 struct ieee80211_tx_info* IEEE80211_SKB_CB (struct sk_buff*) ; 
 int KEY_BUF_SIZE ; 
 int MAX_KEY_LEN ; 
 void* NO_ENCRYPTION ; 
 size_t RWCAM ; 
 size_t SEC_CAM_AES ; 
 size_t SEC_CAM_TKIP ; 
 size_t SEC_CAM_WEP104 ; 
 size_t SEC_CAM_WEP40 ; 
#define  TKIP_ENCRYPTION 130 
 int TOTAL_CAM_ENTRY ; 
 size_t WCAMI ; 
#define  WEP104_ENCRYPTION 129 
#define  WEP40_ENCRYPTION 128 
 scalar_t__ _HAL_STATE_START ; 
 scalar_t__ _HAL_STATE_STOP ; 
 int /*<<< orphan*/  eth_zero_addr (int*) ; 
 scalar_t__ ether_addr_equal_unaligned (int*,int*) ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int const*) ; 
 int* ieee80211_get_qos_ctl (struct ieee80211_hdr*) ; 
 scalar_t__ is_zero_ether_addr (int*) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
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

void rtl_cam_reset_sec_info(struct ieee80211_hw *hw)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	rtlpriv->sec.use_defaultkey = false;
	rtlpriv->sec.pairwise_enc_algorithm = NO_ENCRYPTION;
	rtlpriv->sec.group_enc_algorithm = NO_ENCRYPTION;
	memset(rtlpriv->sec.key_buf, 0, KEY_BUF_SIZE * MAX_KEY_LEN);
	memset(rtlpriv->sec.key_len, 0, KEY_BUF_SIZE);
	rtlpriv->sec.pairwise_key = NULL;
}

__attribute__((used)) static void rtl_cam_program_entry(struct ieee80211_hw *hw, u32 entry_no,
			   u8 *mac_addr, u8 *key_cont_128, u16 us_config)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	u32 target_command;
	u32 target_content = 0;
	int entry_i;

	RT_PRINT_DATA(rtlpriv, COMP_SEC, DBG_DMESG, "Key content :",
		      key_cont_128, 16);

	/* 0-1 config + mac, 2-5 fill 128key,6-7 are reserved */
	for (entry_i = CAM_CONTENT_COUNT - 1; entry_i >= 0; entry_i--) {
		target_command = entry_i + CAM_CONTENT_COUNT * entry_no;
		target_command = target_command | BIT(31) | BIT(16);

		if (entry_i == 0) {
			target_content = (u32) (*(mac_addr + 0)) << 16 |
			    (u32) (*(mac_addr + 1)) << 24 | (u32) us_config;

			rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[WCAMI],
					target_content);
			rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[RWCAM],
					target_command);

			RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
				 "WRITE %x: %x\n",
				 rtlpriv->cfg->maps[WCAMI], target_content);
			RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
				 "The Key ID is %d\n", entry_no);
			RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
				 "WRITE %x: %x\n",
				 rtlpriv->cfg->maps[RWCAM], target_command);

		} else if (entry_i == 1) {

			target_content = (u32) (*(mac_addr + 5)) << 24 |
			    (u32) (*(mac_addr + 4)) << 16 |
			    (u32) (*(mac_addr + 3)) << 8 |
			    (u32) (*(mac_addr + 2));

			rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[WCAMI],
					target_content);
			rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[RWCAM],
					target_command);

			RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
				 "WRITE A4: %x\n", target_content);
			RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
				 "WRITE A0: %x\n", target_command);

		} else {

			target_content =
			    (u32) (*(key_cont_128 + (entry_i * 4 - 8) + 3)) <<
			    24 | (u32) (*(key_cont_128 + (entry_i * 4 - 8) + 2))
			    << 16 |
			    (u32) (*(key_cont_128 + (entry_i * 4 - 8) + 1)) << 8
			    | (u32) (*(key_cont_128 + (entry_i * 4 - 8) + 0));

			rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[WCAMI],
					target_content);
			rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[RWCAM],
					target_command);

			RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
				 "WRITE A4: %x\n", target_content);
			RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
				 "WRITE A0: %x\n", target_command);
		}
	}

	RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
		 "after set key, usconfig:%x\n", us_config);
}

u8 rtl_cam_add_one_entry(struct ieee80211_hw *hw, u8 *mac_addr,
			 u32 ul_key_id, u32 ul_entry_idx, u32 ul_enc_alg,
			 u32 ul_default_key, u8 *key_content)
{
	u32 us_config;
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG,
		 "EntryNo:%x, ulKeyId=%x, ulEncAlg=%x, ulUseDK=%x MacAddr %pM\n",
		 ul_entry_idx, ul_key_id, ul_enc_alg,
		 ul_default_key, mac_addr);

	if (ul_key_id == TOTAL_CAM_ENTRY) {
		RT_TRACE(rtlpriv, COMP_ERR, DBG_WARNING,
			 "ulKeyId exceed!\n");
		return 0;
	}

	if (ul_default_key == 1)
		us_config = CFG_VALID | ((u16) (ul_enc_alg) << 2);
	else
		us_config = CFG_VALID | ((ul_enc_alg) << 2) | ul_key_id;

	rtl_cam_program_entry(hw, ul_entry_idx, mac_addr,
			      (u8 *)key_content, us_config);

	RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG, "end\n");

	return 1;

}

int rtl_cam_delete_one_entry(struct ieee80211_hw *hw,
			     u8 *mac_addr, u32 ul_key_id)
{
	u32 ul_command;
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG, "key_idx:%d\n", ul_key_id);

	ul_command = ul_key_id * CAM_CONTENT_COUNT;
	ul_command = ul_command | BIT(31) | BIT(16);

	rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[WCAMI], 0);
	rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[RWCAM], ul_command);

	RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG,
		 "rtl_cam_delete_one_entry(): WRITE A4: %x\n", 0);
	RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG,
		 "rtl_cam_delete_one_entry(): WRITE A0: %x\n", ul_command);

	return 0;

}

void rtl_cam_reset_all_entry(struct ieee80211_hw *hw)
{
	u32 ul_command;
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	ul_command = BIT(31) | BIT(30);
	rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[RWCAM], ul_command);
}

void rtl_cam_mark_invalid(struct ieee80211_hw *hw, u8 uc_index)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	u32 ul_command;
	u32 ul_content;
	u32 ul_enc_algo = rtlpriv->cfg->maps[SEC_CAM_AES];

	switch (rtlpriv->sec.pairwise_enc_algorithm) {
	case WEP40_ENCRYPTION:
		ul_enc_algo = rtlpriv->cfg->maps[SEC_CAM_WEP40];
		break;
	case WEP104_ENCRYPTION:
		ul_enc_algo = rtlpriv->cfg->maps[SEC_CAM_WEP104];
		break;
	case TKIP_ENCRYPTION:
		ul_enc_algo = rtlpriv->cfg->maps[SEC_CAM_TKIP];
		break;
	case AESCCMP_ENCRYPTION:
		ul_enc_algo = rtlpriv->cfg->maps[SEC_CAM_AES];
		break;
	default:
		ul_enc_algo = rtlpriv->cfg->maps[SEC_CAM_AES];
	}

	ul_content = (uc_index & 3) | ((u16) (ul_enc_algo) << 2);

	ul_content |= BIT(15);
	ul_command = CAM_CONTENT_COUNT * uc_index;
	ul_command = ul_command | BIT(31) | BIT(16);

	rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[WCAMI], ul_content);
	rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[RWCAM], ul_command);

	RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG,
		 "rtl_cam_mark_invalid(): WRITE A4: %x\n", ul_content);
	RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG,
		 "rtl_cam_mark_invalid(): WRITE A0: %x\n", ul_command);
}

void rtl_cam_empty_entry(struct ieee80211_hw *hw, u8 uc_index)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);

	u32 ul_command;
	u32 ul_content;
	u32 ul_encalgo = rtlpriv->cfg->maps[SEC_CAM_AES];
	u8 entry_i;

	switch (rtlpriv->sec.pairwise_enc_algorithm) {
	case WEP40_ENCRYPTION:
		ul_encalgo = rtlpriv->cfg->maps[SEC_CAM_WEP40];
		break;
	case WEP104_ENCRYPTION:
		ul_encalgo = rtlpriv->cfg->maps[SEC_CAM_WEP104];
		break;
	case TKIP_ENCRYPTION:
		ul_encalgo = rtlpriv->cfg->maps[SEC_CAM_TKIP];
		break;
	case AESCCMP_ENCRYPTION:
		ul_encalgo = rtlpriv->cfg->maps[SEC_CAM_AES];
		break;
	default:
		ul_encalgo = rtlpriv->cfg->maps[SEC_CAM_AES];
	}

	for (entry_i = 0; entry_i < CAM_CONTENT_COUNT; entry_i++) {

		if (entry_i == 0) {
			ul_content =
			    (uc_index & 0x03) | ((u16) (ul_encalgo) << 2);
			ul_content |= BIT(15);

		} else {
			ul_content = 0;
		}

		ul_command = CAM_CONTENT_COUNT * uc_index + entry_i;
		ul_command = ul_command | BIT(31) | BIT(16);

		rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[WCAMI], ul_content);
		rtl_write_dword(rtlpriv, rtlpriv->cfg->maps[RWCAM], ul_command);

		RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
			 "rtl_cam_empty_entry(): WRITE A4: %x\n",
			 ul_content);
		RT_TRACE(rtlpriv, COMP_SEC, DBG_LOUD,
			 "rtl_cam_empty_entry(): WRITE A0: %x\n",
			 ul_command);
	}

}

u8 rtl_cam_get_free_entry(struct ieee80211_hw *hw, u8 *sta_addr)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	u32 bitmap = (rtlpriv->sec.hwsec_cam_bitmap) >> 4;
	u8 entry_idx = 0;
	u8 i, *addr;

	if (NULL == sta_addr) {
		pr_err("sta_addr is NULL.\n");
		return TOTAL_CAM_ENTRY;
	}
	/* Does STA already exist? */
	for (i = 4; i < TOTAL_CAM_ENTRY; i++) {
		addr = rtlpriv->sec.hwsec_cam_sta_addr[i];
		if (ether_addr_equal_unaligned(addr, sta_addr))
			return i;
	}
	/* Get a free CAM entry. */
	for (entry_idx = 4; entry_idx < TOTAL_CAM_ENTRY; entry_idx++) {
		if ((bitmap & BIT(0)) == 0) {
			pr_err("-----hwsec_cam_bitmap: 0x%x entry_idx=%d\n",
			       rtlpriv->sec.hwsec_cam_bitmap, entry_idx);
			rtlpriv->sec.hwsec_cam_bitmap |= BIT(0) << entry_idx;
			memcpy(rtlpriv->sec.hwsec_cam_sta_addr[entry_idx],
			       sta_addr, ETH_ALEN);
			return entry_idx;
		}
		bitmap = bitmap >> 1;
	}
	return TOTAL_CAM_ENTRY;
}

void rtl_cam_del_entry(struct ieee80211_hw *hw, u8 *sta_addr)
{
	struct rtl_priv *rtlpriv = rtl_priv(hw);
	u32 bitmap;
	u8 i, *addr;

	if (NULL == sta_addr) {
		pr_err("sta_addr is NULL.\n");
		return;
	}

	if (is_zero_ether_addr(sta_addr)) {
		pr_err("sta_addr is %pM\n", sta_addr);
		return;
	}
	/* Does STA already exist? */
	for (i = 4; i < TOTAL_CAM_ENTRY; i++) {
		addr = rtlpriv->sec.hwsec_cam_sta_addr[i];
		bitmap = (rtlpriv->sec.hwsec_cam_bitmap) >> i;
		if (((bitmap & BIT(0)) == BIT(0)) &&
		    (ether_addr_equal_unaligned(addr, sta_addr))) {
			/* Remove from HW Security CAM */
			eth_zero_addr(rtlpriv->sec.hwsec_cam_sta_addr[i]);
			rtlpriv->sec.hwsec_cam_bitmap &= ~(BIT(0) << i);
			RT_TRACE(rtlpriv, COMP_SEC, DBG_DMESG,
				 "&&&&&&&&&del entry %d\n", i);
		}
	}
	return;
}

