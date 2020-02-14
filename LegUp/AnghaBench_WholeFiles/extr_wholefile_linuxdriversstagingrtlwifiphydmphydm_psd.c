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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct sk_buff {scalar_t__ data; } ;
struct TYPE_4__ {int (* read8_sync ) (struct rtl_priv*,int) ;int (* read16_sync ) (struct rtl_priv*,int) ;int (* read32_sync ) (struct rtl_priv*,int) ;int /*<<< orphan*/  (* write32_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write16_async ) (struct rtl_priv*,int,int) ;int /*<<< orphan*/  (* write8_async ) (struct rtl_priv*,int,int) ;} ;
struct rtl_priv {TYPE_3__* cfg; TYPE_1__ io; } ;
struct rtl_phy {int rf_type; } ;
struct rtl_mac {struct ieee80211_vif* vif; } ;
struct rtl_hal {scalar_t__ state; } ;
struct psd_info {int psd_reg; int psd_report_reg; int psd_fc_channel; int psd_in_progress; int initial_gain_backup; int rf_0x18_bkp; int psd_bw_rf_reg; int fft_smp_point; int sw_avg_time; int psd_pwr_common_offset; int noise_k_en; int* psd_result; } ;
struct phy_dm_struct {int support_ic_type; struct psd_info dm_psd_table; int /*<<< orphan*/  debug_components; int /*<<< orphan*/  support_ability; } ;
struct ieee80211_vif {int dummy; } ;
struct ieee80211_sta {int dummy; } ;
struct ieee80211_hw {struct rtl_priv* priv; } ;
struct ieee80211_hdr {int /*<<< orphan*/  frame_control; } ;
typedef  enum radio_path { ____Placeholder_radio_path } radio_path ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_6__ {TYPE_2__* ops; scalar_t__ write_readback; } ;
struct TYPE_5__ {int (* get_bbreg ) (struct ieee80211_hw*,int,int) ;int (* get_rfreg ) (struct ieee80211_hw*,int,int,int) ;int /*<<< orphan*/  (* set_rfreg ) (struct ieee80211_hw*,int,int,int,int) ;int /*<<< orphan*/  (* set_bbreg ) (struct ieee80211_hw*,int,int,int) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  BB_DBGPORT_PRIORITY_3 ; 
 int BIT (int) ; 
 int /*<<< orphan*/  DCMD_DECIMAL ; 
 int /*<<< orphan*/  DCMD_HEX ; 
 int IEEE80211_QOS_CTL_TID_MASK ; 
 int MASKDWORD ; 
 int /*<<< orphan*/  ODM_BB_DIG ; 
 int /*<<< orphan*/  ODM_BB_FA_CNT ; 
 int /*<<< orphan*/  ODM_COMP_API ; 
 scalar_t__ ODM_IC_11AC_2_SERIES ; 
 int ODM_IC_11AC_SERIES ; 
 int /*<<< orphan*/  ODM_RF_PATH_A ; 
 int ODM_RTL8812 ; 
 int ODM_RTL8821 ; 
 int /*<<< orphan*/  ODM_RT_TRACE (struct phy_dm_struct*,int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  ODM_delay_us (int) ; 
 int /*<<< orphan*/  PHYDM_SNPRINTF (char*,int,char*,...) ; 
 int /*<<< orphan*/  PHYDM_SSCANF (char*,int /*<<< orphan*/ ,int*) ; 
 int RFREGOFFSETMASK ; 
 int STOP_TRX_FAIL ; 
 int STOP_TRX_SUCCESS ; 
 scalar_t__ _HAL_STATE_START ; 
 scalar_t__ _HAL_STATE_STOP ; 
 struct ieee80211_sta* ieee80211_find_sta (struct ieee80211_vif*,int const*) ; 
 int* ieee80211_get_qos_ctl (struct ieee80211_hdr*) ; 
 int odm_convert_to_db (int) ; 
 void* odm_get_bb_reg (struct phy_dm_struct*,int,int) ; 
 int odm_get_rf_reg (struct phy_dm_struct*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  odm_move_memory (struct phy_dm_struct*,int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  odm_set_bb_reg (struct phy_dm_struct*,int,int,int) ; 
 int /*<<< orphan*/  odm_set_rf_reg (struct phy_dm_struct*,int /*<<< orphan*/ ,int,int,int) ; 
 int phydm_get_bb_dbg_port_value (struct phy_dm_struct*) ; 
 int /*<<< orphan*/  phydm_release_bb_dbg_port (struct phy_dm_struct*) ; 
 int /*<<< orphan*/  phydm_set_bb_dbg_port (struct phy_dm_struct*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  psd_result_cali_tone_8821 ; 
 int /*<<< orphan*/  psd_result_cali_val_8821 ; 
 struct rtl_mac* rtl_mac (struct rtl_priv*) ; 
 struct rtl_priv* rtl_priv (struct ieee80211_hw*) ; 
 scalar_t__ strcmp (char*,char*) ; 
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

u32 phydm_get_psd_data(void *dm_void, u32 psd_tone_idx, u32 igi)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	struct psd_info *dm_psd_table = &dm->dm_psd_table;
	u32 psd_report = 0;

	odm_set_bb_reg(dm, dm_psd_table->psd_reg, 0x3ff, psd_tone_idx);

	odm_set_bb_reg(dm, dm_psd_table->psd_reg, BIT(22),
		       1); /*PSD trigger start*/
	ODM_delay_us(10);
	odm_set_bb_reg(dm, dm_psd_table->psd_reg, BIT(22),
		       0); /*PSD trigger stop*/

	psd_report = odm_get_bb_reg(dm, dm_psd_table->psd_report_reg, 0xffff);
	psd_report = odm_convert_to_db(psd_report) + igi;

	return psd_report;
}

__attribute__((used)) static u8 phydm_psd_stop_trx(void *dm_void)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	u32 i;
	u8 trx_idle_success = false;
	u32 dbg_port_value = 0;

	/*[Stop TRX]----------------------------------------------------------*/
	if (!phydm_set_bb_dbg_port(dm, BB_DBGPORT_PRIORITY_3,
				   0x0)) /*set debug port to 0x0*/
		return STOP_TRX_FAIL;

	for (i = 0; i < 10000; i++) {
		dbg_port_value = phydm_get_bb_dbg_port_value(dm);
		if ((dbg_port_value & (BIT(17) | BIT(3))) ==
		    0) /* PHYTXON && CCA_all */ {
			ODM_RT_TRACE(dm, ODM_COMP_API,
				     "PSD wait for ((%d)) times\n", i);

			trx_idle_success = true;
			break;
		}
	}

	if (trx_idle_success) {
		/*pause all TX queue*/
		odm_set_bb_reg(dm, 0x520, 0xff0000, 0xff);

		if (dm->support_ic_type & ODM_IC_11AC_SERIES) {
			/*disable CCK block*/
			odm_set_bb_reg(dm, 0x808, BIT(28), 0);
			/*disable OFDM RX CCA*/
			odm_set_bb_reg(dm, 0x838, BIT(1), 1);
		} else {
			/*TBD*/
			/* disable whole CCK block */
			odm_set_bb_reg(dm, 0x800, BIT(24), 0);
			/*[ Set IQK Matrix = 0 ] equivalent to [ Turn off CCA]*/
			odm_set_bb_reg(dm, 0xC14, MASKDWORD, 0x0);
		}

	} else {
		return STOP_TRX_FAIL;
	}

	phydm_release_bb_dbg_port(dm);

	return STOP_TRX_SUCCESS;
}

void phydm_psd(void *dm_void, u32 igi, u16 start_point, u16 stop_point)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	struct psd_info *dm_psd_table = &dm->dm_psd_table;
	u32 i = 0, mod_tone_idx;
	u32 t = 0;
	u16 fft_max_half_bw;
	u32 psd_igi_a_reg;
	u32 psd_igi_b_reg;
	u16 psd_fc_channel = dm_psd_table->psd_fc_channel;
	u8 ag_rf_mode_reg = 0;
	u8 rf_reg18_9_8 = 0;
	u32 psd_result_tmp = 0;
	u8 psd_result = 0;
	u8 psd_result_cali_tone[7] = {0};
	u8 psd_result_cali_val[7] = {0};
	u8 noise_table_idx = 0;

	if (dm->support_ic_type == ODM_RTL8821) {
		odm_move_memory(dm, psd_result_cali_tone,
				psd_result_cali_tone_8821, 7);
		odm_move_memory(dm, psd_result_cali_val,
				psd_result_cali_val_8821, 7);
	}

	dm_psd_table->psd_in_progress = 1;

	/*[Stop DIG]*/
	dm->support_ability &= ~(ODM_BB_DIG);
	dm->support_ability &= ~(ODM_BB_FA_CNT);

	ODM_RT_TRACE(dm, ODM_COMP_API, "PSD Start =>\n");

	if (dm->support_ic_type & ODM_IC_11AC_SERIES) {
		psd_igi_a_reg = 0xc50;
		psd_igi_b_reg = 0xe50;
	} else {
		psd_igi_a_reg = 0xc50;
		psd_igi_b_reg = 0xc58;
	}

	/*[back up IGI]*/
	dm_psd_table->initial_gain_backup =
		odm_get_bb_reg(dm, psd_igi_a_reg, 0xff);
	odm_set_bb_reg(dm, psd_igi_a_reg, 0xff,
		       0x6e); /*IGI target at 0dBm & make it can't CCA*/
	odm_set_bb_reg(dm, psd_igi_b_reg, 0xff,
		       0x6e); /*IGI target at 0dBm & make it can't CCA*/
	ODM_delay_us(10);

	if (phydm_psd_stop_trx(dm) == STOP_TRX_FAIL) {
		ODM_RT_TRACE(dm, ODM_COMP_API, "STOP_TRX_FAIL\n");
		return;
	}

	/*[Set IGI]*/
	odm_set_bb_reg(dm, psd_igi_a_reg, 0xff, igi);
	odm_set_bb_reg(dm, psd_igi_b_reg, 0xff, igi);

	/*[Backup RF Reg]*/
	dm_psd_table->rf_0x18_bkp =
		odm_get_rf_reg(dm, ODM_RF_PATH_A, 0x18, RFREGOFFSETMASK);

	if (psd_fc_channel > 14) {
		rf_reg18_9_8 = 1;

		if (psd_fc_channel >= 36 && psd_fc_channel <= 64)
			ag_rf_mode_reg = 0x1;
		else if (psd_fc_channel >= 100 && psd_fc_channel <= 140)
			ag_rf_mode_reg = 0x3;
		else if (psd_fc_channel > 140)
			ag_rf_mode_reg = 0x5;
	}

	/* Set RF fc*/
	odm_set_rf_reg(dm, ODM_RF_PATH_A, 0x18, 0xff, psd_fc_channel);
	odm_set_rf_reg(dm, ODM_RF_PATH_A, 0x18, 0x300, rf_reg18_9_8);
	/*2b'11: 20MHz, 2b'10: 40MHz, 2b'01: 80MHz */
	odm_set_rf_reg(dm, ODM_RF_PATH_A, 0x18, 0xc00,
		       dm_psd_table->psd_bw_rf_reg);
	/* Set RF ag fc mode*/
	odm_set_rf_reg(dm, ODM_RF_PATH_A, 0x18, 0xf0000, ag_rf_mode_reg);

	ODM_RT_TRACE(dm, ODM_COMP_API, "0xc50=((0x%x))\n",
		     odm_get_bb_reg(dm, 0xc50, MASKDWORD));
	ODM_RT_TRACE(dm, ODM_COMP_API, "RF0x18=((0x%x))\n",
		     odm_get_rf_reg(dm, ODM_RF_PATH_A, 0x18, RFREGOFFSETMASK));

	/*[Stop 3-wires]*/
	if (dm->support_ic_type & ODM_IC_11AC_SERIES) {
		odm_set_bb_reg(dm, 0xc00, 0xf, 0x4); /*	hardware 3-wire off */
		odm_set_bb_reg(dm, 0xe00, 0xf, 0x4); /*	hardware 3-wire off */
	} else {
		odm_set_bb_reg(dm, 0x88c, 0xf00000,
			       0xf); /* 3 wire Disable    88c[23:20]=0xf */
	}
	ODM_delay_us(10);

	if (stop_point > (dm_psd_table->fft_smp_point - 1))
		stop_point = (dm_psd_table->fft_smp_point - 1);

	if (start_point > (dm_psd_table->fft_smp_point - 1))
		start_point = (dm_psd_table->fft_smp_point - 1);

	if (start_point > stop_point)
		stop_point = start_point;

	if (stop_point > 127) /* limit of psd_result[128] */
		stop_point = 127;

	for (i = start_point; i <= stop_point; i++) {
		fft_max_half_bw = (dm_psd_table->fft_smp_point) >> 1;

		if (i < fft_max_half_bw)
			mod_tone_idx = i + fft_max_half_bw;
		else
			mod_tone_idx = i - fft_max_half_bw;

		psd_result_tmp = 0;
		for (t = 0; t < dm_psd_table->sw_avg_time; t++)
			psd_result_tmp +=
				phydm_get_psd_data(dm, mod_tone_idx, igi);
		psd_result =
			(u8)((psd_result_tmp / dm_psd_table->sw_avg_time)) -
			dm_psd_table->psd_pwr_common_offset;

		if (dm_psd_table->fft_smp_point == 128 &&
		    (dm_psd_table->noise_k_en)) {
			if (i > psd_result_cali_tone[noise_table_idx])
				noise_table_idx++;

			if (noise_table_idx > 6)
				noise_table_idx = 6;

			if (psd_result >= psd_result_cali_val[noise_table_idx])
				psd_result =
					psd_result -
					psd_result_cali_val[noise_table_idx];
			else
				psd_result = 0;

			dm_psd_table->psd_result[i] = psd_result;
		}

		ODM_RT_TRACE(dm, ODM_COMP_API, "[%d] N_cali = %d, PSD = %d\n",
			     mod_tone_idx, psd_result_cali_val[noise_table_idx],
			     psd_result);
	}

	/*[Start 3-wires]*/
	if (dm->support_ic_type & ODM_IC_11AC_SERIES) {
		odm_set_bb_reg(dm, 0xc00, 0xf, 0x7); /*	hardware 3-wire on */
		odm_set_bb_reg(dm, 0xe00, 0xf, 0x7); /*	hardware 3-wire on */
	} else {
		odm_set_bb_reg(dm, 0x88c, 0xf00000,
			       0x0); /* 3 wire enable    88c[23:20]=0x0 */
	}
	ODM_delay_us(10);

	/*[Revert Reg]*/
	odm_set_bb_reg(dm, 0x520, 0xff0000, 0x0); /*start all TX queue*/
	odm_set_bb_reg(dm, 0x808, BIT(28), 1); /*enable CCK block*/
	odm_set_bb_reg(dm, 0x838, BIT(1), 0); /*enable OFDM RX CCA*/

	odm_set_bb_reg(dm, psd_igi_a_reg, 0xff,
		       dm_psd_table->initial_gain_backup);
	odm_set_bb_reg(dm, psd_igi_b_reg, 0xff,
		       dm_psd_table->initial_gain_backup);

	odm_set_rf_reg(dm, ODM_RF_PATH_A, 0x18, RFREGOFFSETMASK,
		       dm_psd_table->rf_0x18_bkp);

	ODM_RT_TRACE(dm, ODM_COMP_API, "PSD finished\n\n");

	dm->support_ability |= ODM_BB_DIG;
	dm->support_ability |= ODM_BB_FA_CNT;
	dm_psd_table->psd_in_progress = 0;
}

void phydm_psd_para_setting(void *dm_void, u8 sw_avg_time, u8 hw_avg_time,
			    u8 i_q_setting, u16 fft_smp_point, u8 ant_sel,
			    u8 psd_input, u8 channel, u8 noise_k_en)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	struct psd_info *dm_psd_table = &dm->dm_psd_table;
	u8 fft_smp_point_idx = 0;

	dm_psd_table->fft_smp_point = fft_smp_point;

	if (sw_avg_time == 0)
		sw_avg_time = 1;

	dm_psd_table->sw_avg_time = sw_avg_time;
	dm_psd_table->psd_fc_channel = channel;
	dm_psd_table->noise_k_en = noise_k_en;

	if (fft_smp_point == 128)
		fft_smp_point_idx = 0;
	else if (fft_smp_point == 256)
		fft_smp_point_idx = 1;
	else if (fft_smp_point == 512)
		fft_smp_point_idx = 2;
	else if (fft_smp_point == 1024)
		fft_smp_point_idx = 3;

	if (dm->support_ic_type & ODM_IC_11AC_SERIES) {
		odm_set_bb_reg(dm, 0x910, BIT(11) | BIT(10), i_q_setting);
		odm_set_bb_reg(dm, 0x910, BIT(13) | BIT(12), hw_avg_time);
		odm_set_bb_reg(dm, 0x910, BIT(15) | BIT(14), fft_smp_point_idx);
		odm_set_bb_reg(dm, 0x910, BIT(17) | BIT(16), ant_sel);
		odm_set_bb_reg(dm, 0x910, BIT(23), psd_input);
	}

	/*bw = (*dm->band_width); //ODM_BW20M */
	/*channel = *(dm->channel);*/
}

void phydm_psd_init(void *dm_void)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	struct psd_info *dm_psd_table = &dm->dm_psd_table;

	ODM_RT_TRACE(dm, ODM_COMP_API, "PSD para init\n");

	dm_psd_table->psd_in_progress = false;

	if (dm->support_ic_type & ODM_IC_11AC_SERIES) {
		dm_psd_table->psd_reg = 0x910;
		dm_psd_table->psd_report_reg = 0xF44;

		if (ODM_IC_11AC_2_SERIES)
			dm_psd_table->psd_bw_rf_reg =
				1; /*2b'11: 20MHz, 2b'10: 40MHz, 2b'01: 80MHz */
		else
			dm_psd_table->psd_bw_rf_reg =
				2; /*2b'11: 20MHz, 2b'10: 40MHz, 2b'01: 80MHz */

	} else {
		dm_psd_table->psd_reg = 0x808;
		dm_psd_table->psd_report_reg = 0x8B4;
		dm_psd_table->psd_bw_rf_reg =
			2; /*2b'11: 20MHz, 2b'10: 40MHz, 2b'01: 80MHz */
	}

	if (dm->support_ic_type == ODM_RTL8812)
		dm_psd_table->psd_pwr_common_offset = 0;
	else if (dm->support_ic_type == ODM_RTL8821)
		dm_psd_table->psd_pwr_common_offset = 0;
	else
		dm_psd_table->psd_pwr_common_offset = 0;

	phydm_psd_para_setting(dm, 1, 2, 3, 128, 0, 0, 7, 0);
	/*phydm_psd(dm, 0x3c, 0, 127);*/ /* target at -50dBm */
}

void phydm_psd_debug(void *dm_void, char input[][16], u32 *_used, char *output,
		     u32 *_out_len, u32 input_num)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	char help[] = "-h";
	u32 var1[10] = {0};
	u32 used = *_used;
	u32 out_len = *_out_len;
	u8 i;

	if ((strcmp(input[1], help) == 0)) {
		PHYDM_SNPRINTF(
			output + used, out_len - used,
			"{0} {sw_avg} {hw_avg 0:3} {1:I,2:Q,3:IQ} {fft_point: 128*(1:4)} {path_sel 0~3} {0:ADC, 1:RXIQC} {CH} {noise_k}\n");
		PHYDM_SNPRINTF(output + used, out_len - used,
			       "{1} {IGI(hex)} {start_point} {stop_point}\n");
		return;
	}

	PHYDM_SSCANF(input[1], DCMD_DECIMAL, &var1[0]);

	if (var1[0] == 0) {
		for (i = 1; i < 10; i++) {
			if (input[i + 1])
				PHYDM_SSCANF(input[i + 1], DCMD_DECIMAL,
					     &var1[i]);
		}

		PHYDM_SNPRINTF(
			output + used, out_len - used,
			"sw_avg_time=((%d)), hw_avg_time=((%d)), IQ=((%d)), fft=((%d)), path=((%d)), input =((%d)) ch=((%d)), noise_k=((%d))\n",
			var1[1], var1[2], var1[3], var1[4], var1[5], var1[6],
			(u8)var1[7], (u8)var1[8]);
		phydm_psd_para_setting(dm, (u8)var1[1], (u8)var1[2],
				       (u8)var1[3], (u16)var1[4], (u8)var1[5],
				       (u8)var1[6], (u8)var1[7], (u8)var1[8]);

	} else if (var1[0] == 1) {
		PHYDM_SSCANF(input[2], DCMD_HEX, &var1[1]);
		PHYDM_SSCANF(input[3], DCMD_DECIMAL, &var1[2]);
		PHYDM_SSCANF(input[4], DCMD_DECIMAL, &var1[3]);
		PHYDM_SNPRINTF(
			output + used, out_len - used,
			"IGI=((0x%x)), start_point=((%d)), stop_point=((%d))\n",
			var1[1], var1[2], var1[3]);
		dm->debug_components |= ODM_COMP_API;
		phydm_psd(dm, var1[1], (u16)var1[2], (u16)var1[3]);
		dm->debug_components &= (~ODM_COMP_API);
	}
}

u8 phydm_get_psd_result_table(void *dm_void, int index)
{
	struct phy_dm_struct *dm = (struct phy_dm_struct *)dm_void;
	struct psd_info *dm_psd_table = &dm->dm_psd_table;
	u8 temp_result = 0;

	if (index < 128)
		temp_result = dm_psd_table->psd_result[index];

	return temp_result;
}

