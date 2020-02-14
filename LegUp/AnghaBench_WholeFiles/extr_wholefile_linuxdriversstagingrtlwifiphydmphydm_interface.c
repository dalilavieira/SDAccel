#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {scalar_t__ data; } ;
struct TYPE_4__ {int (* read8_sync ) (struct rtl_priv*,int) ;int (* read16_sync ) (struct rtl_priv*,int) ;int (* read32_sync ) (struct rtl_priv*,int) ;int /*<<< orphan*/  (* write32_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write16_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write8_async ) (struct rtl_priv*,int,int) ;} ;
struct rtl_priv {struct ieee80211_hw* hw; TYPE_3__* cfg; TYPE_1__ io; } ;
struct rtl_phy {int rf_type; } ;
struct rtl_mac {struct ieee80211_vif* vif; } ;
struct rtl_hal {scalar_t__ state; } ;
struct phy_dm_struct {void* adapter; } ;
struct ieee80211_vif {int dummy; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hw {struct rtl_priv* priv; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
typedef  int /*<<< orphan*/  s8 ;
typedef  int /*<<< orphan*/  s32 ;
typedef  enum rt_spinlock_type { ____Placeholder_rt_spinlock_type } rt_spinlock_type ;
typedef  enum radio_path { ____Placeholder_radio_path } radio_path ;
typedef  enum odm_rf_radio_path { ____Placeholder_odm_rf_radio_path } odm_rf_radio_path ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_6__ {TYPE_2__* ops; scalar_t__ write_readback; } ;
struct TYPE_5__ {int (* get_bbreg ) (struct ieee80211_hw*,int,int) ;int (* get_rfreg ) (struct ieee80211_hw*,int,int,int) ;int /*<<< orphan*/  (* fill_h2c_cmd ) (struct ieee80211_hw*,int,int,int*) ;int /*<<< orphan*/  (* set_rfreg ) (struct ieee80211_hw*,int,int,int,int) ;int /*<<< orphan*/  (* set_bbreg ) (struct ieee80211_hw*,int,int,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int IEEE80211_QOS_CTL_TID_MASK ; 
#define  ODM_H2C_IQ_CALIBRATION 142 
#define  ODM_H2C_RA_PARA_ADJUST 141 
#define  ODM_H2C_RSSI_REPORT 140 
#define  ODM_H2C_WIFI_CALIBRATION 139 
 int /*<<< orphan*/  ODM_RT_TRACE (struct phy_dm_struct*,int /*<<< orphan*/ ,char*,int) ; 
#define  PHYDM_C2H_DBG 138 
#define  PHYDM_C2H_DBG_CODE 137 
#define  PHYDM_C2H_DYNAMIC_TX_PATH_RPT 136 
#define  PHYDM_C2H_EXTEND 135 
#define  PHYDM_C2H_IQK_FINISH 134 
#define  PHYDM_C2H_RA_PARA_RPT 133 
#define  PHYDM_C2H_RA_RPT 132 
 int /*<<< orphan*/  PHYDM_COMP_RA_DBG ; 
 int PHYDM_EXTEND_C2H_DBG_PRINT ; 
#define  PHYDM_H2C_DYNAMIC_TX_PATH 131 
#define  PHYDM_H2C_FW_TRACE_EN 130 
#define  PHYDM_H2C_MU 129 
#define  PHYDM_H2C_TXBF 128 
 scalar_t__ _HAL_STATE_START ; 
 scalar_t__ _HAL_STATE_STOP ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int const*) ; 
 int* ieee80211_get_qos_ctl (struct ieee80211_hdr*) ; 
 int jiffies ; 
 int jiffies_to_msecs (int) ; 
 int /*<<< orphan*/  kfree (void*) ; 
 void* kmalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcmp (void*,void*,int) ; 
 int /*<<< orphan*/  memcpy (void*,void*,int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  odm_c2h_ra_para_report_handler (struct phy_dm_struct*,int*,int) ; 
 int phy_get_tx_power_index (void*,int,int,int,int) ; 
 int /*<<< orphan*/  phy_set_tx_power_index_by_rs (void*,int,int,int) ; 
 int /*<<< orphan*/  phydm_c2h_ra_report_handler (struct phy_dm_struct*,int*,int) ; 
 int /*<<< orphan*/  phydm_fw_trace_handler (struct phy_dm_struct*,int*,int) ; 
 int /*<<< orphan*/  phydm_fw_trace_handler_8051 (struct phy_dm_struct*,int*,int) ; 
 int /*<<< orphan*/  phydm_fw_trace_handler_code (struct phy_dm_struct*,int*,int) ; 
 struct rtl_mac* rtl_mac (struct rtl_priv*) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 
 int stub1 (struct rtl_priv*,int) ; 
 int stub10 (struct ieee80211_hw*,int,int) ; 
 int /*<<< orphan*/  stub11 (struct ieee80211_hw*,int,int,int) ; 
 int stub12 (struct ieee80211_hw*,int,int,int) ; 
 int /*<<< orphan*/  stub13 (struct ieee80211_hw*,int,int,int,int) ; 
 int /*<<< orphan*/  stub14 (struct ieee80211_hw*,int,int,int*) ; 
 int stub2 (struct rtl_priv*,int) ; 
 int stub3 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  stub4 (struct rtl_priv*,int,int) ; 
 int stub5 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  stub6 (struct rtl_priv*,int,int) ; 
 int stub7 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  stub8 (struct rtl_priv*,int,int) ; 
 int stub9 (struct rtl_priv*,int) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

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

u8 odm_read_1byte(struct phy_dm_struct *dm, u32 reg_addr)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	return rtl_read_byte(rtlpriv, reg_addr);
}

u16 odm_read_2byte(struct phy_dm_struct *dm, u32 reg_addr)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	return rtl_read_word(rtlpriv, reg_addr);
}

u32 odm_read_4byte(struct phy_dm_struct *dm, u32 reg_addr)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	return rtl_read_dword(rtlpriv, reg_addr);
}

void odm_write_1byte(struct phy_dm_struct *dm, u32 reg_addr, u8 data)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	rtl_write_byte(rtlpriv, reg_addr, data);
}

void odm_write_2byte(struct phy_dm_struct *dm, u32 reg_addr, u16 data)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	rtl_write_word(rtlpriv, reg_addr, data);
}

void odm_write_4byte(struct phy_dm_struct *dm, u32 reg_addr, u32 data)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	rtl_write_dword(rtlpriv, reg_addr, data);
}

void odm_set_mac_reg(struct phy_dm_struct *dm, u32 reg_addr, u32 bit_mask,
		     u32 data)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	rtl_set_bbreg(rtlpriv->hw, reg_addr, bit_mask, data);
}

u32 odm_get_mac_reg(struct phy_dm_struct *dm, u32 reg_addr, u32 bit_mask)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	return rtl_get_bbreg(rtlpriv->hw, reg_addr, bit_mask);
}

void odm_set_bb_reg(struct phy_dm_struct *dm, u32 reg_addr, u32 bit_mask,
		    u32 data)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	rtl_set_bbreg(rtlpriv->hw, reg_addr, bit_mask, data);
}

u32 odm_get_bb_reg(struct phy_dm_struct *dm, u32 reg_addr, u32 bit_mask)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	return rtl_get_bbreg(rtlpriv->hw, reg_addr, bit_mask);
}

void odm_set_rf_reg(struct phy_dm_struct *dm, enum odm_rf_radio_path e_rf_path,
		    u32 reg_addr, u32 bit_mask, u32 data)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	rtl_set_rfreg(rtlpriv->hw, (enum radio_path)e_rf_path, reg_addr,
		      bit_mask, data);
}

u32 odm_get_rf_reg(struct phy_dm_struct *dm, enum odm_rf_radio_path e_rf_path,
		   u32 reg_addr, u32 bit_mask)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;

	return rtl_get_rfreg(rtlpriv->hw, (enum radio_path)e_rf_path, reg_addr,
			     bit_mask);
}

void odm_allocate_memory(struct phy_dm_struct *dm, void **ptr, u32 length)
{
	*ptr = kmalloc(length, GFP_ATOMIC);
}

void odm_free_memory(struct phy_dm_struct *dm, void *ptr, u32 length)
{
	kfree(ptr);
}

void odm_move_memory(struct phy_dm_struct *dm, void *p_dest, void *src,
		     u32 length)
{
	memcpy(p_dest, src, length);
}

void odm_memory_set(struct phy_dm_struct *dm, void *pbuf, s8 value, u32 length)
{
	memset(pbuf, value, length);
}

s32 odm_compare_memory(struct phy_dm_struct *dm, void *p_buf1, void *buf2,
		       u32 length)
{
	return memcmp(p_buf1, buf2, length);
}

void odm_acquire_spin_lock(struct phy_dm_struct *dm, enum rt_spinlock_type type)
{
}

void odm_release_spin_lock(struct phy_dm_struct *dm, enum rt_spinlock_type type)
{
}

void odm_stall_execution(u32 us_delay) { udelay(us_delay); }

void ODM_delay_ms(u32 ms) { mdelay(ms); }

void ODM_delay_us(u32 us) { udelay(us); }

void ODM_sleep_ms(u32 ms) { msleep(ms); }

void ODM_sleep_us(u32 us) { usleep_range(us, us + 1); }

__attribute__((used)) static u8 phydm_trans_h2c_id(struct phy_dm_struct *dm, u8 phydm_h2c_id)
{
	u8 platform_h2c_id = phydm_h2c_id;

	switch (phydm_h2c_id) {
	/* 1 [0] */
	case ODM_H2C_RSSI_REPORT:

		break;

	/* 1 [3] */
	case ODM_H2C_WIFI_CALIBRATION:

		break;

	/* 1 [4] */
	case ODM_H2C_IQ_CALIBRATION:

		break;
	/* 1 [5] */
	case ODM_H2C_RA_PARA_ADJUST:

		break;

	/* 1 [6] */
	case PHYDM_H2C_DYNAMIC_TX_PATH:

		break;

	/* [7]*/
	case PHYDM_H2C_FW_TRACE_EN:

		platform_h2c_id = 0x49;

		break;

	case PHYDM_H2C_TXBF:
		break;

	case PHYDM_H2C_MU:
		platform_h2c_id = 0x4a; /*H2C_MU*/
		break;

	default:
		platform_h2c_id = phydm_h2c_id;
		break;
	}

	return platform_h2c_id;
}

void odm_fill_h2c_cmd(struct phy_dm_struct *dm, u8 phydm_h2c_id, u32 cmd_len,
		      u8 *cmd_buffer)
{
	struct rtl_priv *rtlpriv = (struct rtl_priv *)dm->adapter;
	u8 platform_h2c_id;

	platform_h2c_id = phydm_trans_h2c_id(dm, phydm_h2c_id);

	ODM_RT_TRACE(dm, PHYDM_COMP_RA_DBG,
		     "[H2C]  platform_h2c_id = ((0x%x))\n", platform_h2c_id);

	rtlpriv->cfg->ops->fill_h2c_cmd(rtlpriv->hw, platform_h2c_id, cmd_len,
					cmd_buffer);
}

u8 phydm_c2H_content_parsing(void *dm_void, u8 c2h_cmd_id, u8 c2h_cmd_len,
			     u8 *tmp_buf)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	u8 extend_c2h_sub_id = 0;
	u8 find_c2h_cmd = true;

	switch (c2h_cmd_id) {
	case PHYDM_C2H_DBG:
		phydm_fw_trace_handler(dm, tmp_buf, c2h_cmd_len);
		break;

	case PHYDM_C2H_RA_RPT:
		phydm_c2h_ra_report_handler(dm, tmp_buf, c2h_cmd_len);
		break;

	case PHYDM_C2H_RA_PARA_RPT:
		odm_c2h_ra_para_report_handler(dm, tmp_buf, c2h_cmd_len);
		break;

	case PHYDM_C2H_DYNAMIC_TX_PATH_RPT:
		break;

	case PHYDM_C2H_IQK_FINISH:
		break;

	case PHYDM_C2H_DBG_CODE:
		phydm_fw_trace_handler_code(dm, tmp_buf, c2h_cmd_len);
		break;

	case PHYDM_C2H_EXTEND:
		extend_c2h_sub_id = tmp_buf[0];
		if (extend_c2h_sub_id == PHYDM_EXTEND_C2H_DBG_PRINT)
			phydm_fw_trace_handler_8051(dm, tmp_buf, c2h_cmd_len);

		break;

	default:
		find_c2h_cmd = false;
		break;
	}

	return find_c2h_cmd;
}

u64 odm_get_current_time(struct phy_dm_struct *dm) { return jiffies; }

u64 odm_get_progressing_time(struct phy_dm_struct *dm, u64 start_time)
{
	return jiffies_to_msecs(jiffies - (u32)start_time);
}

void odm_set_tx_power_index_by_rate_section(struct phy_dm_struct *dm,
					    u8 rf_path, u8 channel,
					    u8 rate_section)
{
	void *adapter = dm->adapter;

	phy_set_tx_power_index_by_rs(adapter, channel, rf_path, rate_section);
}

u8 odm_get_tx_power_index(struct phy_dm_struct *dm, u8 rf_path, u8 tx_rate,
			  u8 band_width, u8 channel)
{
	void *adapter = dm->adapter;

	return phy_get_tx_power_index(adapter, (enum odm_rf_radio_path)rf_path,
				      tx_rate, band_width, channel);
}

