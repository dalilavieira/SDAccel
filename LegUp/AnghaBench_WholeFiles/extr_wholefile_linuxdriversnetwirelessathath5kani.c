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
typedef  unsigned int u32 ;
typedef  scalar_t__ u16 ;
struct ath_regulatory {int dummy; } ;
struct ath_ps_ops {int dummy; } ;
struct ath_common {int /*<<< orphan*/  cc_lock; int /*<<< orphan*/  cc_ani; TYPE_1__* bus_ops; struct ath_regulatory regulatory; struct ath_ps_ops const* ps_ops; } ;
struct ath5k_ani_state {int noise_imm_level; int max_spur_level; int spur_level; int firstep_level; int ofdm_weak_sig; int cck_weak_sig; unsigned int ofdm_errors; unsigned int sum_ofdm_errors; unsigned int cck_errors; unsigned int sum_cck_errors; unsigned int last_ofdm_errors; unsigned int last_cck_errors; int last_listen; int listen_time; int ani_mode; int /*<<< orphan*/  last_cc; } ;
struct TYPE_6__ {scalar_t__ cap_has_phyerr_counters; } ;
struct ath5k_hw {scalar_t__ opmode; scalar_t__ ah_version; scalar_t__ ah_mac_srev; struct ath5k_ani_state ani_state; TYPE_3__ ah_capabilities; int /*<<< orphan*/  ani_tasklet; int /*<<< orphan*/  ah_beacon_rssi_avg; TYPE_2__* ah_current_channel; scalar_t__ iobase; struct ath_common common; } ;
struct ath5k_buf {int dummy; } ;
typedef  int s8 ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum ath_bus_type { ____Placeholder_ath_bus_type } ath_bus_type ;
typedef  enum ath5k_phy_error_code { ____Placeholder_ath5k_phy_error_code } ath5k_phy_error_code ;
typedef  enum ath5k_ani_mode { ____Placeholder_ath5k_ani_mode } ath5k_ani_mode ;
typedef  enum ATH_DEBUG { ____Placeholder_ATH_DEBUG } ATH_DEBUG ;
struct TYPE_5__ {scalar_t__ band; } ;
struct TYPE_4__ {int ath_bus_type; int (* eeprom_read ) (struct ath_common*,unsigned int,scalar_t__*) ;int /*<<< orphan*/  (* read_cachesize ) (struct ath_common*,int*) ;} ;

/* Variables and functions */
 scalar_t__ AR5K_AR5212 ; 
 scalar_t__ AR5K_CCK_FIL_CNT ; 
 scalar_t__ AR5K_OFDM_FIL_CNT ; 
 scalar_t__ AR5K_PHYERR_CNT1 ; 
 scalar_t__ AR5K_PHYERR_CNT1_MASK ; 
 scalar_t__ AR5K_PHYERR_CNT2 ; 
 scalar_t__ AR5K_PHYERR_CNT2_MASK ; 
 int /*<<< orphan*/  AR5K_PHY_AGCCOARSE ; 
 int /*<<< orphan*/  AR5K_PHY_AGCCOARSE_HI ; 
 int /*<<< orphan*/  AR5K_PHY_AGCCOARSE_LO ; 
 int /*<<< orphan*/  AR5K_PHY_CCK_CROSSCORR ; 
 int /*<<< orphan*/  AR5K_PHY_CCK_CROSSCORR_WEAK_SIG_THR ; 
 int /*<<< orphan*/  AR5K_PHY_DESIRED_SIZE ; 
 int /*<<< orphan*/  AR5K_PHY_DESIRED_SIZE_TOT ; 
 unsigned int AR5K_PHY_ERR_FIL_CCK ; 
 unsigned int AR5K_PHY_ERR_FIL_OFDM ; 
 int /*<<< orphan*/  AR5K_PHY_OFDM_SELFCORR ; 
 int /*<<< orphan*/  AR5K_PHY_OFDM_SELFCORR_CYPWR_THR1 ; 
 int /*<<< orphan*/  AR5K_PHY_SIG ; 
 int /*<<< orphan*/  AR5K_PHY_SIG_FIRPWR ; 
 int /*<<< orphan*/  AR5K_PHY_SIG_FIRSTEP ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_HIGH_THR ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_HIGH_THR_M1 ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_HIGH_THR_M2 ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_HIGH_THR_M2_COUNT ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_LOW_THR ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_LOW_THR_M1 ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_LOW_THR_M2 ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_LOW_THR_M2_COUNT ; 
 int /*<<< orphan*/  AR5K_PHY_WEAK_OFDM_LOW_THR_SELFCOR_EN ; 
 int /*<<< orphan*/  AR5K_REG_DISABLE_BITS (struct ath5k_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AR5K_REG_ENABLE_BITS (struct ath5k_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AR5K_REG_WRITE_BITS (struct ath5k_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int const) ; 
 int AR5K_RX_FILTER_PHYERR ; 
 int AR5K_RX_PHY_ERROR_CCK_TIMING ; 
 int AR5K_RX_PHY_ERROR_OFDM_TIMING ; 
 scalar_t__ AR5K_SREV_AR2414 ; 
 int ARRAY_SIZE (int const*) ; 
 unsigned int ATH5K_ANI_CCK_TRIG_HIGH ; 
 int ATH5K_ANI_CCK_TRIG_LOW ; 
 int ATH5K_ANI_LISTEN_PERIOD ; 
 int ATH5K_ANI_MAX_FIRSTEP_LVL ; 
 int ATH5K_ANI_MAX_NOISE_IMM_LVL ; 
 int ATH5K_ANI_MODE_AUTO ; 
 int ATH5K_ANI_MODE_MANUAL_HIGH ; 
 int ATH5K_ANI_MODE_MANUAL_LOW ; 
 int ATH5K_ANI_MODE_OFF ; 
 unsigned int ATH5K_ANI_OFDM_TRIG_HIGH ; 
 int ATH5K_ANI_OFDM_TRIG_LOW ; 
 int ATH5K_ANI_RSSI_THR_HIGH ; 
 int ATH5K_ANI_RSSI_THR_LOW ; 
 unsigned int ATH5K_DEBUG_ANI ; 
 int /*<<< orphan*/  ATH5K_ERR (struct ath5k_hw*,char*,int) ; 
 unsigned int ATH5K_PHYERR_CNT_MAX ; 
 scalar_t__ NL80211_BAND_2GHZ ; 
 scalar_t__ NL80211_IFTYPE_AP ; 
 int ath5k_hw_get_rx_filter (struct ath5k_hw*) ; 
 int /*<<< orphan*/  ath5k_hw_set_rx_filter (struct ath5k_hw*,int) ; 
 char const** ath_bus_type_strings ; 
 int /*<<< orphan*/  ath_hw_cycle_counters_update (struct ath_common*) ; 
 int ath_hw_get_listen_time (struct ath_common*) ; 
 int ewma_beacon_rssi_read (int /*<<< orphan*/ *) ; 
 unsigned int ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (struct ath5k_ani_state*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct ath_common*,int*) ; 
 int stub2 (struct ath_common*,unsigned int,scalar_t__*) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 

void
ATH5K_DBG(struct ath5k_hw *ah, unsigned int m, const char *fmt, ...) {}

void
ATH5K_DBG_UNLIMIT(struct ath5k_hw *ah, unsigned int m, const char *fmt, ...)
{}

__attribute__((used)) static inline void
ath5k_debug_init_device(struct ath5k_hw *ah) {}

__attribute__((used)) static inline void
ath5k_debug_printrxbuffs(struct ath5k_hw *ah) {}

__attribute__((used)) static inline void
ath5k_debug_dump_bands(struct ath5k_hw *ah) {}

__attribute__((used)) static inline void
ath5k_debug_printtxbuf(struct ath5k_hw *ah, struct ath5k_buf *bf) {}

__attribute__((used)) static inline const struct ath_ps_ops *ath_ps_ops(struct ath_common *common)
{
	return common->ps_ops;
}

__attribute__((used)) static inline  __attribute__ ((format (printf, 3, 4)))
void _ath_dbg(struct ath_common *common, enum ATH_DEBUG dbg_mask,
	     const char *fmt, ...)
{
}

__attribute__((used)) static inline const char *ath_opmode_to_string(enum nl80211_iftype opmode)
{
	return "UNKNOWN";
}

__attribute__((used)) static inline const char *ath_bus_type_to_string(enum ath_bus_type bustype)
{
	return ath_bus_type_strings[bustype];
}

__attribute__((used)) static inline struct ath_common *ath5k_hw_common(struct ath5k_hw *ah)
{
	return &ah->common;
}

__attribute__((used)) static inline struct ath_regulatory *ath5k_hw_regulatory(struct ath5k_hw *ah)
{
	return &(ath5k_hw_common(ah)->regulatory);
}

__attribute__((used)) static inline u32 ath5k_hw_reg_read(struct ath5k_hw *ah, u16 reg)
{
	return ioread32(ah->iobase + reg);
}

__attribute__((used)) static inline void ath5k_hw_reg_write(struct ath5k_hw *ah, u32 val, u16 reg)
{
	iowrite32(val, ah->iobase + reg);
}

__attribute__((used)) static inline enum ath_bus_type ath5k_get_bus_type(struct ath5k_hw *ah)
{
	return ath5k_hw_common(ah)->bus_ops->ath_bus_type;
}

__attribute__((used)) static inline void ath5k_read_cachesize(struct ath_common *common, int *csz)
{
	common->bus_ops->read_cachesize(common, csz);
}

__attribute__((used)) static inline bool ath5k_hw_nvram_read(struct ath5k_hw *ah, u32 off, u16 *data)
{
	struct ath_common *common = ath5k_hw_common(ah);
	return common->bus_ops->eeprom_read(common, off, data);
}

__attribute__((used)) static inline u32 ath5k_hw_bitswap(u32 val, unsigned int bits)
{
	u32 retval = 0, bit, i;

	for (i = 0; i < bits; i++) {
		bit = (val >> i) & 1;
		retval = (retval << 1) | bit;
	}

	return retval;
}

void
ath5k_ani_set_noise_immunity_level(struct ath5k_hw *ah, int level)
{
	/* TODO:
	 * ANI documents suggest the following five levels to use, but the HAL
	 * and ath9k use only the last two levels, making this
	 * essentially an on/off option. There *may* be a reason for this (???),
	 * so i stick with the HAL version for now...
	 */
#if 0
	static const s8 lo[] = { -52, -56, -60, -64, -70 };
	static const s8 hi[] = { -18, -18, -16, -14, -12 };
	static const s8 sz[] = { -34, -41, -48, -55, -62 };
	static const s8 fr[] = { -70, -72, -75, -78, -80 };
#else
	static const s8 lo[] = { -64, -70 };
	static const s8 hi[] = { -14, -12 };
	static const s8 sz[] = { -55, -62 };
	static const s8 fr[] = { -78, -80 };
#endif
	if (level < 0 || level >= ARRAY_SIZE(sz)) {
		ATH5K_ERR(ah, "noise immunity level %d out of range",
			  level);
		return;
	}

	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_DESIRED_SIZE,
				AR5K_PHY_DESIRED_SIZE_TOT, sz[level]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_AGCCOARSE,
				AR5K_PHY_AGCCOARSE_LO, lo[level]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_AGCCOARSE,
				AR5K_PHY_AGCCOARSE_HI, hi[level]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_SIG,
				AR5K_PHY_SIG_FIRPWR, fr[level]);

	ah->ani_state.noise_imm_level = level;
	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "new level %d", level);
}

void
ath5k_ani_set_spur_immunity_level(struct ath5k_hw *ah, int level)
{
	static const int val[] = { 2, 4, 6, 8, 10, 12, 14, 16 };

	if (level < 0 || level >= ARRAY_SIZE(val) ||
	    level > ah->ani_state.max_spur_level) {
		ATH5K_ERR(ah, "spur immunity level %d out of range",
			  level);
		return;
	}

	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_OFDM_SELFCORR,
		AR5K_PHY_OFDM_SELFCORR_CYPWR_THR1, val[level]);

	ah->ani_state.spur_level = level;
	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "new level %d", level);
}

void
ath5k_ani_set_firstep_level(struct ath5k_hw *ah, int level)
{
	static const int val[] = { 0, 4, 8 };

	if (level < 0 || level >= ARRAY_SIZE(val)) {
		ATH5K_ERR(ah, "firstep level %d out of range", level);
		return;
	}

	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_SIG,
				AR5K_PHY_SIG_FIRSTEP, val[level]);

	ah->ani_state.firstep_level = level;
	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "new level %d", level);
}

void
ath5k_ani_set_ofdm_weak_signal_detection(struct ath5k_hw *ah, bool on)
{
	static const int m1l[] = { 127, 50 };
	static const int m2l[] = { 127, 40 };
	static const int m1[] = { 127, 0x4d };
	static const int m2[] = { 127, 0x40 };
	static const int m2cnt[] = { 31, 16 };
	static const int m2lcnt[] = { 63, 48 };

	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_WEAK_OFDM_LOW_THR,
				AR5K_PHY_WEAK_OFDM_LOW_THR_M1, m1l[on]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_WEAK_OFDM_LOW_THR,
				AR5K_PHY_WEAK_OFDM_LOW_THR_M2, m2l[on]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_WEAK_OFDM_HIGH_THR,
				AR5K_PHY_WEAK_OFDM_HIGH_THR_M1, m1[on]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_WEAK_OFDM_HIGH_THR,
				AR5K_PHY_WEAK_OFDM_HIGH_THR_M2, m2[on]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_WEAK_OFDM_HIGH_THR,
			AR5K_PHY_WEAK_OFDM_HIGH_THR_M2_COUNT, m2cnt[on]);
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_WEAK_OFDM_LOW_THR,
			AR5K_PHY_WEAK_OFDM_LOW_THR_M2_COUNT, m2lcnt[on]);

	if (on)
		AR5K_REG_ENABLE_BITS(ah, AR5K_PHY_WEAK_OFDM_LOW_THR,
				AR5K_PHY_WEAK_OFDM_LOW_THR_SELFCOR_EN);
	else
		AR5K_REG_DISABLE_BITS(ah, AR5K_PHY_WEAK_OFDM_LOW_THR,
				AR5K_PHY_WEAK_OFDM_LOW_THR_SELFCOR_EN);

	ah->ani_state.ofdm_weak_sig = on;
	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "turned %s",
			  on ? "on" : "off");
}

void
ath5k_ani_set_cck_weak_signal_detection(struct ath5k_hw *ah, bool on)
{
	static const int val[] = { 8, 6 };
	AR5K_REG_WRITE_BITS(ah, AR5K_PHY_CCK_CROSSCORR,
				AR5K_PHY_CCK_CROSSCORR_WEAK_SIG_THR, val[on]);
	ah->ani_state.cck_weak_sig = on;
	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "turned %s",
			  on ? "on" : "off");
}

__attribute__((used)) static void
ath5k_ani_raise_immunity(struct ath5k_hw *ah, struct ath5k_ani_state *as,
			 bool ofdm_trigger)
{
	int rssi = ewma_beacon_rssi_read(&ah->ah_beacon_rssi_avg);

	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "raise immunity (%s)",
		ofdm_trigger ? "ODFM" : "CCK");

	/* first: raise noise immunity */
	if (as->noise_imm_level < ATH5K_ANI_MAX_NOISE_IMM_LVL) {
		ath5k_ani_set_noise_immunity_level(ah, as->noise_imm_level + 1);
		return;
	}

	/* only OFDM: raise spur immunity level */
	if (ofdm_trigger &&
	    as->spur_level < ah->ani_state.max_spur_level) {
		ath5k_ani_set_spur_immunity_level(ah, as->spur_level + 1);
		return;
	}

	/* AP mode */
	if (ah->opmode == NL80211_IFTYPE_AP) {
		if (as->firstep_level < ATH5K_ANI_MAX_FIRSTEP_LVL)
			ath5k_ani_set_firstep_level(ah, as->firstep_level + 1);
		return;
	}

	/* STA and IBSS mode */

	/* TODO: for IBSS mode it would be better to keep a beacon RSSI average
	 * per each neighbour node and use the minimum of these, to make sure we
	 * don't shut out a remote node by raising immunity too high. */

	if (rssi > ATH5K_ANI_RSSI_THR_HIGH) {
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
				  "beacon RSSI high");
		/* only OFDM: beacon RSSI is high, we can disable ODFM weak
		 * signal detection */
		if (ofdm_trigger && as->ofdm_weak_sig) {
			ath5k_ani_set_ofdm_weak_signal_detection(ah, false);
			ath5k_ani_set_spur_immunity_level(ah, 0);
			return;
		}
		/* as a last resort or CCK: raise firstep level */
		if (as->firstep_level < ATH5K_ANI_MAX_FIRSTEP_LVL) {
			ath5k_ani_set_firstep_level(ah, as->firstep_level + 1);
			return;
		}
	} else if (rssi > ATH5K_ANI_RSSI_THR_LOW) {
		/* beacon RSSI in mid range, we need OFDM weak signal detect,
		 * but can raise firstep level */
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
				  "beacon RSSI mid");
		if (ofdm_trigger && !as->ofdm_weak_sig)
			ath5k_ani_set_ofdm_weak_signal_detection(ah, true);
		if (as->firstep_level < ATH5K_ANI_MAX_FIRSTEP_LVL)
			ath5k_ani_set_firstep_level(ah, as->firstep_level + 1);
		return;
	} else if (ah->ah_current_channel->band == NL80211_BAND_2GHZ) {
		/* beacon RSSI is low. in B/G mode turn of OFDM weak signal
		 * detect and zero firstep level to maximize CCK sensitivity */
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
				  "beacon RSSI low, 2GHz");
		if (ofdm_trigger && as->ofdm_weak_sig)
			ath5k_ani_set_ofdm_weak_signal_detection(ah, false);
		if (as->firstep_level > 0)
			ath5k_ani_set_firstep_level(ah, 0);
		return;
	}

	/* TODO: why not?:
	if (as->cck_weak_sig == true) {
		ath5k_ani_set_cck_weak_signal_detection(ah, false);
	}
	*/
}

__attribute__((used)) static void
ath5k_ani_lower_immunity(struct ath5k_hw *ah, struct ath5k_ani_state *as)
{
	int rssi = ewma_beacon_rssi_read(&ah->ah_beacon_rssi_avg);

	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "lower immunity");

	if (ah->opmode == NL80211_IFTYPE_AP) {
		/* AP mode */
		if (as->firstep_level > 0) {
			ath5k_ani_set_firstep_level(ah, as->firstep_level - 1);
			return;
		}
	} else {
		/* STA and IBSS mode (see TODO above) */
		if (rssi > ATH5K_ANI_RSSI_THR_HIGH) {
			/* beacon signal is high, leave OFDM weak signal
			 * detection off or it may oscillate
			 * TODO: who said it's off??? */
		} else if (rssi > ATH5K_ANI_RSSI_THR_LOW) {
			/* beacon RSSI is mid-range: turn on ODFM weak signal
			 * detection and next, lower firstep level */
			if (!as->ofdm_weak_sig) {
				ath5k_ani_set_ofdm_weak_signal_detection(ah,
									 true);
				return;
			}
			if (as->firstep_level > 0) {
				ath5k_ani_set_firstep_level(ah,
							as->firstep_level - 1);
				return;
			}
		} else {
			/* beacon signal is low: only reduce firstep level */
			if (as->firstep_level > 0) {
				ath5k_ani_set_firstep_level(ah,
							as->firstep_level - 1);
				return;
			}
		}
	}

	/* all modes */
	if (as->spur_level > 0) {
		ath5k_ani_set_spur_immunity_level(ah, as->spur_level - 1);
		return;
	}

	/* finally, reduce noise immunity */
	if (as->noise_imm_level > 0) {
		ath5k_ani_set_noise_immunity_level(ah, as->noise_imm_level - 1);
		return;
	}
}

__attribute__((used)) static int
ath5k_hw_ani_get_listen_time(struct ath5k_hw *ah, struct ath5k_ani_state *as)
{
	struct ath_common *common = ath5k_hw_common(ah);
	int listen;

	spin_lock_bh(&common->cc_lock);

	ath_hw_cycle_counters_update(common);
	memcpy(&as->last_cc, &common->cc_ani, sizeof(as->last_cc));

	/* clears common->cc_ani */
	listen = ath_hw_get_listen_time(common);

	spin_unlock_bh(&common->cc_lock);

	return listen;
}

__attribute__((used)) static int
ath5k_ani_save_and_clear_phy_errors(struct ath5k_hw *ah,
				    struct ath5k_ani_state *as)
{
	unsigned int ofdm_err, cck_err;

	if (!ah->ah_capabilities.cap_has_phyerr_counters)
		return 0;

	ofdm_err = ath5k_hw_reg_read(ah, AR5K_PHYERR_CNT1);
	cck_err = ath5k_hw_reg_read(ah, AR5K_PHYERR_CNT2);

	/* reset counters first, we might be in a hurry (interrupt) */
	ath5k_hw_reg_write(ah, ATH5K_PHYERR_CNT_MAX - ATH5K_ANI_OFDM_TRIG_HIGH,
			   AR5K_PHYERR_CNT1);
	ath5k_hw_reg_write(ah, ATH5K_PHYERR_CNT_MAX - ATH5K_ANI_CCK_TRIG_HIGH,
			   AR5K_PHYERR_CNT2);

	ofdm_err = ATH5K_ANI_OFDM_TRIG_HIGH - (ATH5K_PHYERR_CNT_MAX - ofdm_err);
	cck_err = ATH5K_ANI_CCK_TRIG_HIGH - (ATH5K_PHYERR_CNT_MAX - cck_err);

	/* sometimes both can be zero, especially when there is a superfluous
	 * second interrupt. detect that here and return an error. */
	if (ofdm_err <= 0 && cck_err <= 0)
		return 0;

	/* avoid negative values should one of the registers overflow */
	if (ofdm_err > 0) {
		as->ofdm_errors += ofdm_err;
		as->sum_ofdm_errors += ofdm_err;
	}
	if (cck_err > 0) {
		as->cck_errors += cck_err;
		as->sum_cck_errors += cck_err;
	}
	return 1;
}

__attribute__((used)) static void
ath5k_ani_period_restart(struct ath5k_ani_state *as)
{
	/* keep last values for debugging */
	as->last_ofdm_errors = as->ofdm_errors;
	as->last_cck_errors = as->cck_errors;
	as->last_listen = as->listen_time;

	as->ofdm_errors = 0;
	as->cck_errors = 0;
	as->listen_time = 0;
}

void
ath5k_ani_calibration(struct ath5k_hw *ah)
{
	struct ath5k_ani_state *as = &ah->ani_state;
	int listen, ofdm_high, ofdm_low, cck_high, cck_low;

	/* get listen time since last call and add it to the counter because we
	 * might not have restarted the "ani period" last time.
	 * always do this to calculate the busy time also in manual mode */
	listen = ath5k_hw_ani_get_listen_time(ah, as);
	as->listen_time += listen;

	if (as->ani_mode != ATH5K_ANI_MODE_AUTO)
		return;

	ath5k_ani_save_and_clear_phy_errors(ah, as);

	ofdm_high = as->listen_time * ATH5K_ANI_OFDM_TRIG_HIGH / 1000;
	cck_high = as->listen_time * ATH5K_ANI_CCK_TRIG_HIGH / 1000;
	ofdm_low = as->listen_time * ATH5K_ANI_OFDM_TRIG_LOW / 1000;
	cck_low = as->listen_time * ATH5K_ANI_CCK_TRIG_LOW / 1000;

	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
		"listen %d (now %d)", as->listen_time, listen);
	ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
		"check high ofdm %d/%d cck %d/%d",
		as->ofdm_errors, ofdm_high, as->cck_errors, cck_high);

	if (as->ofdm_errors > ofdm_high || as->cck_errors > cck_high) {
		/* too many PHY errors - we have to raise immunity */
		bool ofdm_flag = as->ofdm_errors > ofdm_high ? true : false;
		ath5k_ani_raise_immunity(ah, as, ofdm_flag);
		ath5k_ani_period_restart(as);

	} else if (as->listen_time > 5 * ATH5K_ANI_LISTEN_PERIOD) {
		/* If more than 5 (TODO: why 5?) periods have passed and we got
		 * relatively little errors we can try to lower immunity */
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
			"check low ofdm %d/%d cck %d/%d",
			as->ofdm_errors, ofdm_low, as->cck_errors, cck_low);

		if (as->ofdm_errors <= ofdm_low && as->cck_errors <= cck_low)
			ath5k_ani_lower_immunity(ah, as);

		ath5k_ani_period_restart(as);
	}
}

void
ath5k_ani_mib_intr(struct ath5k_hw *ah)
{
	struct ath5k_ani_state *as = &ah->ani_state;

	/* nothing to do here if HW does not have PHY error counters - they
	 * can't be the reason for the MIB interrupt then */
	if (!ah->ah_capabilities.cap_has_phyerr_counters)
		return;

	/* not in use but clear anyways */
	ath5k_hw_reg_write(ah, 0, AR5K_OFDM_FIL_CNT);
	ath5k_hw_reg_write(ah, 0, AR5K_CCK_FIL_CNT);

	if (ah->ani_state.ani_mode != ATH5K_ANI_MODE_AUTO)
		return;

	/* If one of the errors triggered, we can get a superfluous second
	 * interrupt, even though we have already reset the register. The
	 * function detects that so we can return early. */
	if (ath5k_ani_save_and_clear_phy_errors(ah, as) == 0)
		return;

	if (as->ofdm_errors > ATH5K_ANI_OFDM_TRIG_HIGH ||
	    as->cck_errors > ATH5K_ANI_CCK_TRIG_HIGH)
		tasklet_schedule(&ah->ani_tasklet);
}

void
ath5k_ani_phy_error_report(struct ath5k_hw *ah,
			   enum ath5k_phy_error_code phyerr)
{
	struct ath5k_ani_state *as = &ah->ani_state;

	if (phyerr == AR5K_RX_PHY_ERROR_OFDM_TIMING) {
		as->ofdm_errors++;
		if (as->ofdm_errors > ATH5K_ANI_OFDM_TRIG_HIGH)
			tasklet_schedule(&ah->ani_tasklet);
	} else if (phyerr == AR5K_RX_PHY_ERROR_CCK_TIMING) {
		as->cck_errors++;
		if (as->cck_errors > ATH5K_ANI_CCK_TRIG_HIGH)
			tasklet_schedule(&ah->ani_tasklet);
	}
}

__attribute__((used)) static void
ath5k_enable_phy_err_counters(struct ath5k_hw *ah)
{
	ath5k_hw_reg_write(ah, ATH5K_PHYERR_CNT_MAX - ATH5K_ANI_OFDM_TRIG_HIGH,
			   AR5K_PHYERR_CNT1);
	ath5k_hw_reg_write(ah, ATH5K_PHYERR_CNT_MAX - ATH5K_ANI_CCK_TRIG_HIGH,
			   AR5K_PHYERR_CNT2);
	ath5k_hw_reg_write(ah, AR5K_PHY_ERR_FIL_OFDM, AR5K_PHYERR_CNT1_MASK);
	ath5k_hw_reg_write(ah, AR5K_PHY_ERR_FIL_CCK, AR5K_PHYERR_CNT2_MASK);

	/* not in use */
	ath5k_hw_reg_write(ah, 0, AR5K_OFDM_FIL_CNT);
	ath5k_hw_reg_write(ah, 0, AR5K_CCK_FIL_CNT);
}

__attribute__((used)) static void
ath5k_disable_phy_err_counters(struct ath5k_hw *ah)
{
	ath5k_hw_reg_write(ah, 0, AR5K_PHYERR_CNT1);
	ath5k_hw_reg_write(ah, 0, AR5K_PHYERR_CNT2);
	ath5k_hw_reg_write(ah, 0, AR5K_PHYERR_CNT1_MASK);
	ath5k_hw_reg_write(ah, 0, AR5K_PHYERR_CNT2_MASK);

	/* not in use */
	ath5k_hw_reg_write(ah, 0, AR5K_OFDM_FIL_CNT);
	ath5k_hw_reg_write(ah, 0, AR5K_CCK_FIL_CNT);
}

void
ath5k_ani_init(struct ath5k_hw *ah, enum ath5k_ani_mode mode)
{
	/* ANI is only possible on 5212 and newer */
	if (ah->ah_version < AR5K_AR5212)
		return;

	if (mode < ATH5K_ANI_MODE_OFF || mode > ATH5K_ANI_MODE_AUTO) {
		ATH5K_ERR(ah, "ANI mode %d out of range", mode);
		return;
	}

	/* clear old state information */
	memset(&ah->ani_state, 0, sizeof(ah->ani_state));

	/* older hardware has more spur levels than newer */
	if (ah->ah_mac_srev < AR5K_SREV_AR2414)
		ah->ani_state.max_spur_level = 7;
	else
		ah->ani_state.max_spur_level = 2;

	/* initial values for our ani parameters */
	if (mode == ATH5K_ANI_MODE_OFF) {
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "ANI off\n");
	} else if (mode == ATH5K_ANI_MODE_MANUAL_LOW) {
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
			"ANI manual low -> high sensitivity\n");
		ath5k_ani_set_noise_immunity_level(ah, 0);
		ath5k_ani_set_spur_immunity_level(ah, 0);
		ath5k_ani_set_firstep_level(ah, 0);
		ath5k_ani_set_ofdm_weak_signal_detection(ah, true);
		ath5k_ani_set_cck_weak_signal_detection(ah, true);
	} else if (mode == ATH5K_ANI_MODE_MANUAL_HIGH) {
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI,
			"ANI manual high -> low sensitivity\n");
		ath5k_ani_set_noise_immunity_level(ah,
					ATH5K_ANI_MAX_NOISE_IMM_LVL);
		ath5k_ani_set_spur_immunity_level(ah,
					ah->ani_state.max_spur_level);
		ath5k_ani_set_firstep_level(ah, ATH5K_ANI_MAX_FIRSTEP_LVL);
		ath5k_ani_set_ofdm_weak_signal_detection(ah, false);
		ath5k_ani_set_cck_weak_signal_detection(ah, false);
	} else if (mode == ATH5K_ANI_MODE_AUTO) {
		ATH5K_DBG_UNLIMIT(ah, ATH5K_DEBUG_ANI, "ANI auto\n");
		ath5k_ani_set_noise_immunity_level(ah, 0);
		ath5k_ani_set_spur_immunity_level(ah, 0);
		ath5k_ani_set_firstep_level(ah, 0);
		ath5k_ani_set_ofdm_weak_signal_detection(ah, true);
		ath5k_ani_set_cck_weak_signal_detection(ah, false);
	}

	/* newer hardware has PHY error counter registers which we can use to
	 * get OFDM and CCK error counts. older hardware has to set rxfilter and
	 * report every single PHY error by calling ath5k_ani_phy_error_report()
	 */
	if (mode == ATH5K_ANI_MODE_AUTO) {
		if (ah->ah_capabilities.cap_has_phyerr_counters)
			ath5k_enable_phy_err_counters(ah);
		else
			ath5k_hw_set_rx_filter(ah, ath5k_hw_get_rx_filter(ah) |
						   AR5K_RX_FILTER_PHYERR);
	} else {
		if (ah->ah_capabilities.cap_has_phyerr_counters)
			ath5k_disable_phy_err_counters(ah);
		else
			ath5k_hw_set_rx_filter(ah, ath5k_hw_get_rx_filter(ah) &
						   ~AR5K_RX_FILTER_PHYERR);
	}

	ah->ani_state.ani_mode = mode;
}

