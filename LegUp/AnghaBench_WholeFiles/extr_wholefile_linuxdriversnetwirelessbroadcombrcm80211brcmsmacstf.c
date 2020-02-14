#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int uint ;
typedef  size_t u8 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct tx_power {scalar_t__* target; } ;
struct ssb_sprom {size_t txchain; int rxchain; } ;
struct sk_buff {int dummy; } ;
struct device {int dummy; } ;
struct brcms_phy_pub {int dummy; } ;
struct brcms_info {int dummy; } ;
struct brcms_c_info {struct brcms_band* band; TYPE_3__* stf; TYPE_6__* hw; struct brcms_band** bandstate; TYPE_1__* pub; int /*<<< orphan*/  bcn_rspec; scalar_t__ clk; } ;
struct brcms_band {scalar_t__ band_stf_stbc_tx; scalar_t__ band_stf_ss_mode; struct brcms_phy_pub* pi; int /*<<< orphan*/  phyrev; } ;
typedef  scalar_t__ s8 ;
typedef  scalar_t__ s32 ;
struct TYPE_13__ {TYPE_5__* d11core; } ;
struct TYPE_12__ {TYPE_2__* bus; } ;
struct TYPE_11__ {size_t tx_phy_ctl3; int phy_rate_40_sgi; int phy_rate_20_sgi; int phy_rate_40; int phy_rate_20; } ;
struct TYPE_10__ {int rxstreams; int txchain; int hw_txchain; int txstreams; size_t* txcore; size_t phytxant; scalar_t__ txant; int rxchain; size_t ss_opmode; int ss_algosel_auto; scalar_t__ ss_algo_channel; int hw_rxchain; void* spatial_policy; } ;
struct TYPE_9__ {struct ssb_sprom sprom; } ;
struct TYPE_8__ {int /*<<< orphan*/  unit; scalar_t__ up; } ;

/* Variables and functions */
 scalar_t__ ANT_TX_DEF ; 
 scalar_t__ ANT_TX_FORCE_0 ; 
 scalar_t__ ANT_TX_FORCE_1 ; 
 scalar_t__ AUTO ; 
 size_t BAND_2G_INDEX ; 
 size_t BAND_5G_INDEX ; 
 scalar_t__ BRCMS_ISLCNPHY (struct brcms_band*) ; 
 scalar_t__ BRCMS_ISNPHY (struct brcms_band*) ; 
 scalar_t__ BRCMS_ISSSLPNPHY (struct brcms_band*) ; 
 scalar_t__ BRCMS_PHY_11N_CAP (struct brcms_band*) ; 
 int BRCMS_RATE_FLAG ; 
 int BRCMS_RATE_MASK ; 
 scalar_t__ BRCMS_STBC_CAP_PHY (struct brcms_c_info*) ; 
 scalar_t__ BRCMS_STF_SS_STBC_RX (struct brcms_c_info*) ; 
 int BRCM_RATE_11M ; 
 int BRCM_RATE_1M ; 
 int BRCM_RATE_2M ; 
 int BRCM_RATE_5M5 ; 
 int /*<<< orphan*/  CHSPEC_CHANNEL (scalar_t__) ; 
 scalar_t__ CHSPEC_IS40 (scalar_t__) ; 
 int EINVAL ; 
 int ENOTSUPP ; 
 size_t HIGHEST_SINGLE_STREAM_MCS ; 
 int HT_CAP_RX_STBC_NO ; 
 scalar_t__ HT_CAP_RX_STBC_ONE_STREAM ; 
 int MAX_SPATIAL_EXPANSION ; 
 int MAX_STREAMS_SUPPORTED ; 
 size_t MCS_TXS_MASK ; 
 size_t MCS_TXS_SHIFT ; 
 void* MIN_SPATIAL_EXPANSION ; 
 scalar_t__ NREV_GE (int /*<<< orphan*/ ,int) ; 
 scalar_t__ NREV_LT (int /*<<< orphan*/ ,int) ; 
 scalar_t__ OFF ; 
 scalar_t__ ON ; 
 scalar_t__ PHY_TPC_HW_ON ; 
 int PHY_TXC1_BW_40MHZ ; 
 int PHY_TXC1_BW_40MHZ_DUP ; 
 scalar_t__ PHY_TXC1_MODE_CDD ; 
 scalar_t__ PHY_TXC1_MODE_SISO ; 
 scalar_t__ PHY_TXC1_MODE_STBC ; 
 size_t PHY_TXC_ANT_0 ; 
 size_t PHY_TXC_ANT_1 ; 
 size_t PHY_TXC_ANT_2 ; 
 scalar_t__ PHY_TXC_ANT_MASK ; 
 size_t PHY_TXC_ANT_SHIFT ; 
 scalar_t__ PHY_TXC_HTANT_MASK ; 
 size_t PHY_TXC_LCNPHY_ANT_LAST ; 
 size_t PHY_TXC_OLD_ANT_0 ; 
 size_t PHY_TXC_OLD_ANT_1 ; 
 size_t PHY_TXC_OLD_ANT_LAST ; 
 int RSPEC_BW_MASK ; 
 int RSPEC_BW_SHIFT ; 
 int RSPEC_MIMORATE ; 
 int RSPEC_RATE_MASK ; 
 int RSPEC_SHORT_GI ; 
 int RSPEC_STC_MASK ; 
 int RSPEC_STC_SHIFT ; 
 int RSPEC_STF_MASK ; 
 int RSPEC_STF_SHIFT ; 
 int RXCHAIN_DEF ; 
 int RXCHAIN_DEF_NPHY ; 
 int TXCHAIN_DEF ; 
 int TXCHAIN_DEF_NPHY ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 size_t WL_TX_POWER_MCS20_CDD_FIRST ; 
 size_t WL_TX_POWER_MCS20_SISO_FIRST ; 
 size_t WL_TX_POWER_MCS20_STBC_FIRST ; 
 size_t WL_TX_POWER_MCS40_CDD_FIRST ; 
 size_t WL_TX_POWER_MCS40_SISO_FIRST ; 
 size_t WL_TX_POWER_MCS40_STBC_FIRST ; 
 int /*<<< orphan*/  brcms_b_band_stf_ss_set (TYPE_6__*,size_t) ; 
 int /*<<< orphan*/  brcms_b_txant_set (TYPE_6__*,size_t) ; 
 int /*<<< orphan*/  brcms_c_beacon_phytxctl_txant_upd (struct brcms_c_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  brcms_c_enable_mac (struct brcms_c_info*) ; 
 int brcms_c_stf_ss_update (struct brcms_c_info*,struct brcms_band*) ; 
 int brcms_c_stf_txchain_set (struct brcms_c_info*,scalar_t__,int) ; 
 int /*<<< orphan*/  brcms_c_suspend_mac_and_wait (struct brcms_c_info*) ; 
 int /*<<< orphan*/  brcms_c_update_beacon (struct brcms_c_info*) ; 
 int /*<<< orphan*/  brcms_c_update_probe_resp (struct brcms_c_info*,int) ; 
 int /*<<< orphan*/  brcms_dbg_ht (TYPE_5__*,char*,int /*<<< orphan*/ ,int,...) ; 
 scalar_t__ hweight8 (size_t) ; 
 scalar_t__ isset (scalar_t__*,scalar_t__) ; 
 TYPE_4__* mcs_table ; 
 int /*<<< orphan*/  memcpy (size_t*,size_t*,int) ; 
 int* rate_info ; 
 int /*<<< orphan*/  setbit (scalar_t__*,scalar_t__) ; 
 size_t* txcore_default ; 
 size_t* wlc_phy_get_ofdm_rate_lookup () ; 
 int wlc_phy_stf_chain_active_get (struct brcms_phy_pub*) ; 
 int /*<<< orphan*/  wlc_phy_stf_chain_set (struct brcms_phy_pub*,size_t,int) ; 
 int /*<<< orphan*/  wlc_phy_txpower_get_current (struct brcms_phy_pub*,struct tx_power*,int /*<<< orphan*/ ) ; 
 scalar_t__ wlc_phy_txpower_hw_ctrl_get (struct brcms_phy_pub*) ; 

__attribute__((used)) static inline void dma_spin_for_len(uint len, struct sk_buff *head)
{
#if defined(CONFIG_BCM47XX)
	if (!len) {
		while (!(len = *(u16 *) KSEG1ADDR(head->data)))
			udelay(1);

		*(u16 *) (head->data) = cpu_to_le16((u16) len);
	}
#endif				/* defined(CONFIG_BCM47XX) */
}

__attribute__((used)) static inline u8 mcs_2_txstreams(u8 mcs)
{
	return (mcs_table[mcs].tx_phy_ctl3 & MCS_TXS_MASK) >> MCS_TXS_SHIFT;
}

__attribute__((used)) static inline uint mcs_2_rate(u8 mcs, bool is40, bool sgi)
{
	if (sgi) {
		if (is40)
			return mcs_table[mcs].phy_rate_40_sgi;
		return mcs_table[mcs].phy_rate_20_sgi;
	}
	if (is40)
		return mcs_table[mcs].phy_rate_40;

	return mcs_table[mcs].phy_rate_20;
}

__attribute__((used)) static inline bool rspec_active(u32 rspec)
{
	return rspec & (RSPEC_RATE_MASK | RSPEC_MIMORATE);
}

__attribute__((used)) static inline u8 rspec_phytxbyte2(u32 rspec)
{
	return (rspec & 0xff00) >> 8;
}

__attribute__((used)) static inline u32 rspec_get_bw(u32 rspec)
{
	return (rspec & RSPEC_BW_MASK) >> RSPEC_BW_SHIFT;
}

__attribute__((used)) static inline bool rspec_issgi(u32 rspec)
{
	return (rspec & RSPEC_SHORT_GI) == RSPEC_SHORT_GI;
}

__attribute__((used)) static inline bool rspec_is40mhz(u32 rspec)
{
	u32 bw = rspec_get_bw(rspec);

	return bw == PHY_TXC1_BW_40MHZ || bw == PHY_TXC1_BW_40MHZ_DUP;
}

__attribute__((used)) static inline uint rspec2rate(u32 rspec)
{
	if (rspec & RSPEC_MIMORATE)
		return mcs_2_rate(rspec & RSPEC_RATE_MASK, rspec_is40mhz(rspec),
				  rspec_issgi(rspec));
	return rspec & RSPEC_RATE_MASK;
}

__attribute__((used)) static inline u8 rspec_mimoplcp3(u32 rspec)
{
	return (rspec & 0xf00000) >> 16;
}

__attribute__((used)) static inline bool plcp3_issgi(u8 plcp)
{
	return (plcp & (RSPEC_SHORT_GI >> 16)) != 0;
}

__attribute__((used)) static inline uint rspec_stc(u32 rspec)
{
	return (rspec & RSPEC_STC_MASK) >> RSPEC_STC_SHIFT;
}

__attribute__((used)) static inline uint rspec_stf(u32 rspec)
{
	return (rspec & RSPEC_STF_MASK) >> RSPEC_STF_SHIFT;
}

__attribute__((used)) static inline bool is_mcs_rate(u32 ratespec)
{
	return (ratespec & RSPEC_MIMORATE) != 0;
}

__attribute__((used)) static inline bool is_ofdm_rate(u32 ratespec)
{
	return !is_mcs_rate(ratespec) &&
	       (rate_info[ratespec & RSPEC_RATE_MASK] & BRCMS_RATE_FLAG);
}

__attribute__((used)) static inline bool is_cck_rate(u32 ratespec)
{
	u32 rate = (ratespec & BRCMS_RATE_MASK);

	return !is_mcs_rate(ratespec) && (
			rate == BRCM_RATE_1M || rate == BRCM_RATE_2M ||
			rate == BRCM_RATE_5M5 || rate == BRCM_RATE_11M);
}

__attribute__((used)) static inline bool is_single_stream(u8 mcs)
{
	return mcs <= HIGHEST_SINGLE_STREAM_MCS || mcs == 32;
}

__attribute__((used)) static inline u8 cck_rspec(u8 cck)
{
	return cck & RSPEC_RATE_MASK;
}

__attribute__((used)) static inline u8 ofdm_phy2mac_rate(u8 rlpt)
{
	return wlc_phy_get_ofdm_rate_lookup()[rlpt & 0x7];
}

__attribute__((used)) static inline u8 cck_phy2mac_rate(u8 signal)
{
	return signal/5;
}

__attribute__((used)) static inline void brcms_led_unregister(struct brcms_info *wl) {}

__attribute__((used)) static inline int brcms_led_register(struct brcms_info *wl)
{
	return -ENOTSUPP;
}

void __brcms_dbg(struct device *dev, u32 level, const char *func,
		 const char *fmt, ...)
{
}

__attribute__((used)) static void brcms_c_stf_stbc_rx_ht_update(struct brcms_c_info *wlc, int val)
{
	/* MIMOPHYs rev3-6 cannot receive STBC with only one rx core active */
	if (BRCMS_STF_SS_STBC_RX(wlc)) {
		if ((wlc->stf->rxstreams == 1) && (val != HT_CAP_RX_STBC_NO))
			return;
	}

	if (wlc->pub->up) {
		brcms_c_update_beacon(wlc);
		brcms_c_update_probe_resp(wlc, true);
	}
}

void brcms_c_tempsense_upd(struct brcms_c_info *wlc)
{
	struct brcms_phy_pub *pi = wlc->band->pi;
	uint active_chains, txchain;

	/* Check if the chip is too hot. Disable one Tx chain, if it is */
	/* high 4 bits are for Rx chain, low 4 bits are  for Tx chain */
	active_chains = wlc_phy_stf_chain_active_get(pi);
	txchain = active_chains & 0xf;

	if (wlc->stf->txchain == wlc->stf->hw_txchain) {
		if (txchain && (txchain < wlc->stf->hw_txchain))
			/* turn off 1 tx chain */
			brcms_c_stf_txchain_set(wlc, txchain, true);
	} else if (wlc->stf->txchain < wlc->stf->hw_txchain) {
		if (txchain == wlc->stf->hw_txchain)
			/* turn back on txchain */
			brcms_c_stf_txchain_set(wlc, txchain, true);
	}
}

void
brcms_c_stf_ss_algo_channel_get(struct brcms_c_info *wlc, u16 *ss_algo_channel,
			    u16 chanspec)
{
	struct tx_power power = { };
	u8 siso_mcs_id, cdd_mcs_id, stbc_mcs_id;

	/* Clear previous settings */
	*ss_algo_channel = 0;

	if (!wlc->pub->up) {
		*ss_algo_channel = (u16) -1;
		return;
	}

	wlc_phy_txpower_get_current(wlc->band->pi, &power,
				    CHSPEC_CHANNEL(chanspec));

	siso_mcs_id = (CHSPEC_IS40(chanspec)) ?
	    WL_TX_POWER_MCS40_SISO_FIRST : WL_TX_POWER_MCS20_SISO_FIRST;
	cdd_mcs_id = (CHSPEC_IS40(chanspec)) ?
	    WL_TX_POWER_MCS40_CDD_FIRST : WL_TX_POWER_MCS20_CDD_FIRST;
	stbc_mcs_id = (CHSPEC_IS40(chanspec)) ?
	    WL_TX_POWER_MCS40_STBC_FIRST : WL_TX_POWER_MCS20_STBC_FIRST;

	/* criteria to choose stf mode */

	/*
	 * the "+3dbm (12 0.25db units)" is to account for the fact that with
	 * CDD, tx occurs on both chains
	 */
	if (power.target[siso_mcs_id] > (power.target[cdd_mcs_id] + 12))
		setbit(ss_algo_channel, PHY_TXC1_MODE_SISO);
	else
		setbit(ss_algo_channel, PHY_TXC1_MODE_CDD);

	/*
	 * STBC is ORed into to algo channel as STBC requires per-packet SCB
	 * capability check so cannot be default mode of operation. One of
	 * SISO, CDD have to be set
	 */
	if (power.target[siso_mcs_id] <= (power.target[stbc_mcs_id] + 12))
		setbit(ss_algo_channel, PHY_TXC1_MODE_STBC);
}

__attribute__((used)) static bool brcms_c_stf_stbc_tx_set(struct brcms_c_info *wlc, s32 int_val)
{
	if ((int_val != AUTO) && (int_val != OFF) && (int_val != ON))
		return false;

	if ((int_val == ON) && (wlc->stf->txstreams == 1))
		return false;

	wlc->bandstate[BAND_2G_INDEX]->band_stf_stbc_tx = (s8) int_val;
	wlc->bandstate[BAND_5G_INDEX]->band_stf_stbc_tx = (s8) int_val;

	return true;
}

bool brcms_c_stf_stbc_rx_set(struct brcms_c_info *wlc, s32 int_val)
{
	if ((int_val != HT_CAP_RX_STBC_NO)
	    && (int_val != HT_CAP_RX_STBC_ONE_STREAM))
		return false;

	if (BRCMS_STF_SS_STBC_RX(wlc)) {
		if ((int_val != HT_CAP_RX_STBC_NO)
		    && (wlc->stf->rxstreams == 1))
			return false;
	}

	brcms_c_stf_stbc_rx_ht_update(wlc, int_val);
	return true;
}

__attribute__((used)) static int brcms_c_stf_txcore_set(struct brcms_c_info *wlc, u8 Nsts,
				  u8 core_mask)
{
	brcms_dbg_ht(wlc->hw->d11core, "wl%d: Nsts %d core_mask %x\n",
		     wlc->pub->unit, Nsts, core_mask);

	if (hweight8(core_mask) > wlc->stf->txstreams)
		core_mask = 0;

	if ((hweight8(core_mask) == wlc->stf->txstreams) &&
	    ((core_mask & ~wlc->stf->txchain)
	     || !(core_mask & wlc->stf->txchain)))
		core_mask = wlc->stf->txchain;

	wlc->stf->txcore[Nsts] = core_mask;
	/* Nsts = 1..4, txcore index = 1..4 */
	if (Nsts == 1) {
		/* Needs to update beacon and ucode generated response
		 * frames when 1 stream core map changed
		 */
		wlc->stf->phytxant = core_mask << PHY_TXC_ANT_SHIFT;
		brcms_b_txant_set(wlc->hw, wlc->stf->phytxant);
		if (wlc->clk) {
			brcms_c_suspend_mac_and_wait(wlc);
			brcms_c_beacon_phytxctl_txant_upd(wlc, wlc->bcn_rspec);
			brcms_c_enable_mac(wlc);
		}
	}

	return 0;
}

__attribute__((used)) static int brcms_c_stf_spatial_policy_set(struct brcms_c_info *wlc, int val)
{
	int i;
	u8 core_mask = 0;

	brcms_dbg_ht(wlc->hw->d11core, "wl%d: val %x\n", wlc->pub->unit,
		     val);

	wlc->stf->spatial_policy = (s8) val;
	for (i = 1; i <= MAX_STREAMS_SUPPORTED; i++) {
		core_mask = (val == MAX_SPATIAL_EXPANSION) ?
		    wlc->stf->txchain : txcore_default[i];
		brcms_c_stf_txcore_set(wlc, (u8) i, core_mask);
	}
	return 0;
}

__attribute__((used)) static void _brcms_c_stf_phy_txant_upd(struct brcms_c_info *wlc)
{
	s8 txant;

	txant = (s8) wlc->stf->txant;
	if (BRCMS_PHY_11N_CAP(wlc->band)) {
		if (txant == ANT_TX_FORCE_0) {
			wlc->stf->phytxant = PHY_TXC_ANT_0;
		} else if (txant == ANT_TX_FORCE_1) {
			wlc->stf->phytxant = PHY_TXC_ANT_1;

			if (BRCMS_ISNPHY(wlc->band) &&
			    NREV_GE(wlc->band->phyrev, 3)
			    && NREV_LT(wlc->band->phyrev, 7))
				wlc->stf->phytxant = PHY_TXC_ANT_2;
		} else {
			if (BRCMS_ISLCNPHY(wlc->band) ||
			    BRCMS_ISSSLPNPHY(wlc->band))
				wlc->stf->phytxant = PHY_TXC_LCNPHY_ANT_LAST;
			else {
				/* catch out of sync wlc->stf->txcore */
				WARN_ON(wlc->stf->txchain <= 0);
				wlc->stf->phytxant =
				    wlc->stf->txchain << PHY_TXC_ANT_SHIFT;
			}
		}
	} else {
		if (txant == ANT_TX_FORCE_0)
			wlc->stf->phytxant = PHY_TXC_OLD_ANT_0;
		else if (txant == ANT_TX_FORCE_1)
			wlc->stf->phytxant = PHY_TXC_OLD_ANT_1;
		else
			wlc->stf->phytxant = PHY_TXC_OLD_ANT_LAST;
	}

	brcms_b_txant_set(wlc->hw, wlc->stf->phytxant);
}

int brcms_c_stf_txchain_set(struct brcms_c_info *wlc, s32 int_val, bool force)
{
	u8 txchain = (u8) int_val;
	u8 txstreams;
	uint i;

	if (wlc->stf->txchain == txchain)
		return 0;

	if ((txchain & ~wlc->stf->hw_txchain)
	    || !(txchain & wlc->stf->hw_txchain))
		return -EINVAL;

	/*
	 * if nrate override is configured to be non-SISO STF mode, reject
	 * reducing txchain to 1
	 */
	txstreams = (u8) hweight8(txchain);
	if (txstreams > MAX_STREAMS_SUPPORTED)
		return -EINVAL;

	wlc->stf->txchain = txchain;
	wlc->stf->txstreams = txstreams;
	brcms_c_stf_stbc_tx_set(wlc, wlc->band->band_stf_stbc_tx);
	brcms_c_stf_ss_update(wlc, wlc->bandstate[BAND_2G_INDEX]);
	brcms_c_stf_ss_update(wlc, wlc->bandstate[BAND_5G_INDEX]);
	wlc->stf->txant =
	    (wlc->stf->txstreams == 1) ? ANT_TX_FORCE_0 : ANT_TX_DEF;
	_brcms_c_stf_phy_txant_upd(wlc);

	wlc_phy_stf_chain_set(wlc->band->pi, wlc->stf->txchain,
			      wlc->stf->rxchain);

	for (i = 1; i <= MAX_STREAMS_SUPPORTED; i++)
		brcms_c_stf_txcore_set(wlc, (u8) i, txcore_default[i]);

	return 0;
}

int brcms_c_stf_ss_update(struct brcms_c_info *wlc, struct brcms_band *band)
{
	int ret_code = 0;
	u8 prev_stf_ss;
	u8 upd_stf_ss;

	prev_stf_ss = wlc->stf->ss_opmode;

	/*
	 * NOTE: opmode can only be SISO or CDD as STBC is decided on a
	 * per-packet basis
	 */
	if (BRCMS_STBC_CAP_PHY(wlc) &&
	    wlc->stf->ss_algosel_auto
	    && (wlc->stf->ss_algo_channel != (u16) -1)) {
		upd_stf_ss = (wlc->stf->txstreams == 1 ||
			      isset(&wlc->stf->ss_algo_channel,
				    PHY_TXC1_MODE_SISO)) ?
				    PHY_TXC1_MODE_SISO : PHY_TXC1_MODE_CDD;
	} else {
		if (wlc->band != band)
			return ret_code;
		upd_stf_ss = (wlc->stf->txstreams == 1) ?
				PHY_TXC1_MODE_SISO : band->band_stf_ss_mode;
	}
	if (prev_stf_ss != upd_stf_ss) {
		wlc->stf->ss_opmode = upd_stf_ss;
		brcms_b_band_stf_ss_set(wlc->hw, upd_stf_ss);
	}

	return ret_code;
}

int brcms_c_stf_attach(struct brcms_c_info *wlc)
{
	wlc->bandstate[BAND_2G_INDEX]->band_stf_ss_mode = PHY_TXC1_MODE_SISO;
	wlc->bandstate[BAND_5G_INDEX]->band_stf_ss_mode = PHY_TXC1_MODE_CDD;

	if (BRCMS_ISNPHY(wlc->band) &&
	    (wlc_phy_txpower_hw_ctrl_get(wlc->band->pi) != PHY_TPC_HW_ON))
		wlc->bandstate[BAND_2G_INDEX]->band_stf_ss_mode =
		    PHY_TXC1_MODE_CDD;
	brcms_c_stf_ss_update(wlc, wlc->bandstate[BAND_2G_INDEX]);
	brcms_c_stf_ss_update(wlc, wlc->bandstate[BAND_5G_INDEX]);

	brcms_c_stf_stbc_rx_ht_update(wlc, HT_CAP_RX_STBC_NO);
	wlc->bandstate[BAND_2G_INDEX]->band_stf_stbc_tx = OFF;
	wlc->bandstate[BAND_5G_INDEX]->band_stf_stbc_tx = OFF;

	if (BRCMS_STBC_CAP_PHY(wlc)) {
		wlc->stf->ss_algosel_auto = true;
		/* Init the default value */
		wlc->stf->ss_algo_channel = (u16) -1;
	}
	return 0;
}

void brcms_c_stf_detach(struct brcms_c_info *wlc)
{
}

void brcms_c_stf_phy_txant_upd(struct brcms_c_info *wlc)
{
	_brcms_c_stf_phy_txant_upd(wlc);
}

void brcms_c_stf_phy_chain_calc(struct brcms_c_info *wlc)
{
	struct ssb_sprom *sprom = &wlc->hw->d11core->bus->sprom;

	/* get available rx/tx chains */
	wlc->stf->hw_txchain = sprom->txchain;
	wlc->stf->hw_rxchain = sprom->rxchain;

	/* these parameter are intended to be used for all PHY types */
	if (wlc->stf->hw_txchain == 0 || wlc->stf->hw_txchain == 0xf) {
		if (BRCMS_ISNPHY(wlc->band))
			wlc->stf->hw_txchain = TXCHAIN_DEF_NPHY;
		else
			wlc->stf->hw_txchain = TXCHAIN_DEF;
	}

	wlc->stf->txchain = wlc->stf->hw_txchain;
	wlc->stf->txstreams = (u8) hweight8(wlc->stf->hw_txchain);

	if (wlc->stf->hw_rxchain == 0 || wlc->stf->hw_rxchain == 0xf) {
		if (BRCMS_ISNPHY(wlc->band))
			wlc->stf->hw_rxchain = RXCHAIN_DEF_NPHY;
		else
			wlc->stf->hw_rxchain = RXCHAIN_DEF;
	}

	wlc->stf->rxchain = wlc->stf->hw_rxchain;
	wlc->stf->rxstreams = (u8) hweight8(wlc->stf->hw_rxchain);

	/* initialize the txcore table */
	memcpy(wlc->stf->txcore, txcore_default, sizeof(wlc->stf->txcore));

	/* default spatial_policy */
	wlc->stf->spatial_policy = MIN_SPATIAL_EXPANSION;
	brcms_c_stf_spatial_policy_set(wlc, MIN_SPATIAL_EXPANSION);
}

__attribute__((used)) static u16 _brcms_c_stf_phytxchain_sel(struct brcms_c_info *wlc,
				       u32 rspec)
{
	u16 phytxant = wlc->stf->phytxant;

	if (rspec_stf(rspec) != PHY_TXC1_MODE_SISO)
		phytxant = wlc->stf->txchain << PHY_TXC_ANT_SHIFT;
	else if (wlc->stf->txant == ANT_TX_DEF)
		phytxant = wlc->stf->txchain << PHY_TXC_ANT_SHIFT;
	phytxant &= PHY_TXC_ANT_MASK;
	return phytxant;
}

u16 brcms_c_stf_phytxchain_sel(struct brcms_c_info *wlc, u32 rspec)
{
	return _brcms_c_stf_phytxchain_sel(wlc, rspec);
}

u16 brcms_c_stf_d11hdrs_phyctl_txant(struct brcms_c_info *wlc, u32 rspec)
{
	u16 phytxant = wlc->stf->phytxant;
	u16 mask = PHY_TXC_ANT_MASK;

	/* for non-siso rates or default setting, use the available chains */
	if (BRCMS_ISNPHY(wlc->band)) {
		phytxant = _brcms_c_stf_phytxchain_sel(wlc, rspec);
		mask = PHY_TXC_HTANT_MASK;
	}
	phytxant |= phytxant & mask;
	return phytxant;
}

