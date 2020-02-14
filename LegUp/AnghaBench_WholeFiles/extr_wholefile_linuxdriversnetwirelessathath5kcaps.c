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
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned int u32 ;
typedef  scalar_t__ u16 ;
struct ath_regulatory {int dummy; } ;
struct ath_ps_ops {int dummy; } ;
struct ath_common {TYPE_1__* bus_ops; struct ath_regulatory regulatory; struct ath_ps_ops const* ps_ops; } ;
struct TYPE_8__ {int /*<<< orphan*/  q_tx_num; } ;
struct TYPE_7__ {int range_5ghz_min; int range_5ghz_max; int range_2ghz_min; int range_2ghz_max; } ;
struct TYPE_6__ {int /*<<< orphan*/  ee_regdomain; scalar_t__ ee_header; } ;
struct ath5k_capabilities {int cap_has_phyerr_counters; int cap_has_mrr_support; TYPE_4__ cap_queues; int /*<<< orphan*/  cap_mode; int /*<<< orphan*/  cap_needs_2GHz_ovr; TYPE_3__ cap_range; TYPE_2__ cap_eeprom; } ;
struct ath5k_hw {scalar_t__ ah_version; int ah_radio_5ghz_revision; scalar_t__ ah_mac_srev; struct ath5k_capabilities ah_capabilities; scalar_t__ iobase; struct ath_common common; } ;
struct ath5k_buf {int dummy; } ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum ath_bus_type { ____Placeholder_ath_bus_type } ath_bus_type ;
typedef  enum ATH_DEBUG { ____Placeholder_ATH_DEBUG } ATH_DEBUG ;
struct TYPE_5__ {int ath_bus_type; int (* eeprom_read ) (struct ath_common*,unsigned int,scalar_t__*) ;int /*<<< orphan*/  (* read_cachesize ) (struct ath_common*,int*) ;} ;

/* Variables and functions */
 scalar_t__ AR5K_AR5210 ; 
 scalar_t__ AR5K_AR5211 ; 
 scalar_t__ AR5K_AR5212 ; 
 scalar_t__ AR5K_EEPROM_HDR_11A (scalar_t__) ; 
 scalar_t__ AR5K_EEPROM_HDR_11B (scalar_t__) ; 
 scalar_t__ AR5K_EEPROM_HDR_11G (scalar_t__) ; 
 int /*<<< orphan*/  AR5K_MODE_11A ; 
 int /*<<< orphan*/  AR5K_MODE_11B ; 
 int /*<<< orphan*/  AR5K_MODE_11G ; 
 int /*<<< orphan*/  AR5K_NUM_TX_QUEUES ; 
 int /*<<< orphan*/  AR5K_NUM_TX_QUEUES_NOQCU ; 
 int /*<<< orphan*/  AR5K_REG_DISABLE_BITS (struct ath5k_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  AR5K_REG_ENABLE_BITS (struct ath5k_hw*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ AR5K_SREV_AR5213A ; 
 int AR5K_SREV_RAD_2112 ; 
 int /*<<< orphan*/  AR5K_STA_ID1 ; 
 int AR5K_STA_ID1_DEFAULT_ANTENNA ; 
 int AR5K_STA_ID1_NO_PSPOLL ; 
 int EIO ; 
 int /*<<< orphan*/  __clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char const** ath_bus_type_strings ; 
 scalar_t__ ath_is_49ghz_allowed (int /*<<< orphan*/ ) ; 
 unsigned int ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct ath_common*,int*) ; 
 int stub2 (struct ath_common*,unsigned int,scalar_t__*) ; 

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

int ath5k_hw_set_capabilities(struct ath5k_hw *ah)
{
	struct ath5k_capabilities *caps = &ah->ah_capabilities;
	u16 ee_header;

	/* Capabilities stored in the EEPROM */
	ee_header = caps->cap_eeprom.ee_header;

	if (ah->ah_version == AR5K_AR5210) {
		/*
		 * Set radio capabilities
		 * (The AR5110 only supports the middle 5GHz band)
		 */
		caps->cap_range.range_5ghz_min = 5120;
		caps->cap_range.range_5ghz_max = 5430;
		caps->cap_range.range_2ghz_min = 0;
		caps->cap_range.range_2ghz_max = 0;

		/* Set supported modes */
		__set_bit(AR5K_MODE_11A, caps->cap_mode);
	} else {
		/*
		 * XXX The transceiver supports frequencies from 4920 to 6100MHz
		 * XXX and from 2312 to 2732MHz. There are problems with the
		 * XXX current ieee80211 implementation because the IEEE
		 * XXX channel mapping does not support negative channel
		 * XXX numbers (2312MHz is channel -19). Of course, this
		 * XXX doesn't matter because these channels are out of the
		 * XXX legal range.
		 */

		/*
		 * Set radio capabilities
		 */

		if (AR5K_EEPROM_HDR_11A(ee_header)) {
			if (ath_is_49ghz_allowed(caps->cap_eeprom.ee_regdomain))
				caps->cap_range.range_5ghz_min = 4920;
			else
				caps->cap_range.range_5ghz_min = 5005;
			caps->cap_range.range_5ghz_max = 6100;

			/* Set supported modes */
			__set_bit(AR5K_MODE_11A, caps->cap_mode);
		}

		/* Enable  802.11b if a 2GHz capable radio (2111/5112) is
		 * connected */
		if (AR5K_EEPROM_HDR_11B(ee_header) ||
		    (AR5K_EEPROM_HDR_11G(ee_header) &&
		     ah->ah_version != AR5K_AR5211)) {
			/* 2312 */
			caps->cap_range.range_2ghz_min = 2412;
			caps->cap_range.range_2ghz_max = 2732;

			/* Override 2GHz modes on SoCs that need it
			 * NOTE: cap_needs_2GHz_ovr gets set from
			 * ath_ahb_probe */
			if (!caps->cap_needs_2GHz_ovr) {
				if (AR5K_EEPROM_HDR_11B(ee_header))
					__set_bit(AR5K_MODE_11B,
							caps->cap_mode);

				if (AR5K_EEPROM_HDR_11G(ee_header) &&
				ah->ah_version != AR5K_AR5211)
					__set_bit(AR5K_MODE_11G,
							caps->cap_mode);
			}
		}
	}

	if ((ah->ah_radio_5ghz_revision & 0xf0) == AR5K_SREV_RAD_2112)
		__clear_bit(AR5K_MODE_11A, caps->cap_mode);

	/* Set number of supported TX queues */
	if (ah->ah_version == AR5K_AR5210)
		caps->cap_queues.q_tx_num = AR5K_NUM_TX_QUEUES_NOQCU;
	else
		caps->cap_queues.q_tx_num = AR5K_NUM_TX_QUEUES;

	/* Newer hardware has PHY error counters */
	if (ah->ah_mac_srev >= AR5K_SREV_AR5213A)
		caps->cap_has_phyerr_counters = true;
	else
		caps->cap_has_phyerr_counters = false;

	/* MACs since AR5212 have MRR support */
	if (ah->ah_version == AR5K_AR5212)
		caps->cap_has_mrr_support = true;
	else
		caps->cap_has_mrr_support = false;

	return 0;
}

int ath5k_hw_enable_pspoll(struct ath5k_hw *ah, u8 *bssid,
		u16 assoc_id)
{
	if (ah->ah_version == AR5K_AR5210) {
		AR5K_REG_DISABLE_BITS(ah, AR5K_STA_ID1,
			AR5K_STA_ID1_NO_PSPOLL | AR5K_STA_ID1_DEFAULT_ANTENNA);
		return 0;
	}

	return -EIO;
}

int ath5k_hw_disable_pspoll(struct ath5k_hw *ah)
{
	if (ah->ah_version == AR5K_AR5210) {
		AR5K_REG_ENABLE_BITS(ah, AR5K_STA_ID1,
			AR5K_STA_ID1_NO_PSPOLL | AR5K_STA_ID1_DEFAULT_ANTENNA);
		return 0;
	}

	return -EIO;
}

