#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u8 ;
typedef  unsigned int u32 ;
typedef  int u16 ;
struct ath_regulatory {int dummy; } ;
struct ath_ps_ops {int dummy; } ;
struct ath_common {TYPE_1__* bus_ops; struct ath_regulatory regulatory; struct ath_ps_ops const* ps_ops; } ;
struct ath5k_ini_mode {unsigned int* mode_value; scalar_t__ mode_register; } ;
struct ath5k_ini {scalar_t__ ini_register; int ini_mode; unsigned int ini_value; } ;
struct ath5k_hw {int iobase; scalar_t__ ah_version; int ah_radio; struct ath_common common; } ;
struct ath5k_buf {int dummy; } ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum ath_bus_type { ____Placeholder_ath_bus_type } ath_bus_type ;
typedef  enum ATH_DEBUG { ____Placeholder_ATH_DEBUG } ATH_DEBUG ;
struct TYPE_2__ {int ath_bus_type; int (* eeprom_read ) (struct ath_common*,unsigned int,int*) ;int /*<<< orphan*/  (* read_cachesize ) (struct ath_common*,int*) ;} ;

/* Variables and functions */
 scalar_t__ AR5K_AR5210 ; 
 scalar_t__ AR5K_AR5211 ; 
 scalar_t__ AR5K_AR5212 ; 
#define  AR5K_INI_READ 136 
#define  AR5K_INI_WRITE 135 
 scalar_t__ AR5K_PCU_MAX ; 
 scalar_t__ AR5K_PCU_MIN ; 
 int AR5K_PHY_AGC ; 
 int AR5K_PHY_GAIN ; 
 int /*<<< orphan*/  AR5K_PHY_TPC_RG5 ; 
 int /*<<< orphan*/  AR5K_PHY_TPC_RG5_PD_GAIN_OVERLAP ; 
 int /*<<< orphan*/  AR5K_REG_WAIT (unsigned int) ; 
 int /*<<< orphan*/  AR5K_REG_WRITE_BITS (struct ath5k_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
#define  AR5K_RF2316 134 
#define  AR5K_RF2317 133 
#define  AR5K_RF2413 132 
#define  AR5K_RF2425 131 
#define  AR5K_RF5111 130 
#define  AR5K_RF5112 129 
#define  AR5K_RF5413 128 
 unsigned int ARRAY_SIZE (void*) ; 
 int /*<<< orphan*/  ATH5K_ERR (struct ath5k_hw*,char*,size_t) ; 
 int EINVAL ; 
 void* ar5210_ini ; 
 void* ar5211_ini ; 
 void* ar5211_ini_mode ; 
 void* ar5212_ini_common_start ; 
 void* ar5212_ini_mode_start ; 
 char const** ath_bus_type_strings ; 
 unsigned int ioread32 (int) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,int) ; 
 void* rf2413_ini_common_end ; 
 void* rf2413_ini_mode_end ; 
 void* rf2425_ini_common_end ; 
 void* rf2425_ini_mode_end ; 
 void* rf5111_ini_bbgain ; 
 void* rf5111_ini_common_end ; 
 void* rf5111_ini_mode_end ; 
 void* rf5112_ini_bbgain ; 
 void* rf5112_ini_common_end ; 
 void* rf5112_ini_mode_end ; 
 void* rf5413_ini_common_end ; 
 void* rf5413_ini_mode_end ; 
 int /*<<< orphan*/  stub1 (struct ath_common*,int*) ; 
 int stub2 (struct ath_common*,unsigned int,int*) ; 

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

__attribute__((used)) static void
ath5k_hw_ini_registers(struct ath5k_hw *ah, unsigned int size,
		const struct ath5k_ini *ini_regs, bool skip_pcu)
{
	unsigned int i;

	/* Write initial registers */
	for (i = 0; i < size; i++) {
		/* Skip PCU registers if
		 * requested */
		if (skip_pcu &&
				ini_regs[i].ini_register >= AR5K_PCU_MIN &&
				ini_regs[i].ini_register <= AR5K_PCU_MAX)
			continue;

		switch (ini_regs[i].ini_mode) {
		case AR5K_INI_READ:
			/* Cleared on read */
			ath5k_hw_reg_read(ah, ini_regs[i].ini_register);
			break;
		case AR5K_INI_WRITE:
		default:
			AR5K_REG_WAIT(i);
			ath5k_hw_reg_write(ah, ini_regs[i].ini_value,
					ini_regs[i].ini_register);
		}
	}
}

__attribute__((used)) static void
ath5k_hw_ini_mode_registers(struct ath5k_hw *ah,
		unsigned int size, const struct ath5k_ini_mode *ini_mode,
		u8 mode)
{
	unsigned int i;

	for (i = 0; i < size; i++) {
		AR5K_REG_WAIT(i);
		ath5k_hw_reg_write(ah, ini_mode[i].mode_value[mode],
			(u32)ini_mode[i].mode_register);
	}

}

int
ath5k_hw_write_initvals(struct ath5k_hw *ah, u8 mode, bool skip_pcu)
{
	/*
	 * Write initial register settings
	 */

	/* For AR5212 and compatible */
	if (ah->ah_version == AR5K_AR5212) {

		/* First set of mode-specific settings */
		ath5k_hw_ini_mode_registers(ah,
			ARRAY_SIZE(ar5212_ini_mode_start),
			ar5212_ini_mode_start, mode);

		/*
		 * Write initial settings common for all modes
		 */
		ath5k_hw_ini_registers(ah, ARRAY_SIZE(ar5212_ini_common_start),
				ar5212_ini_common_start, skip_pcu);

		/* Second set of mode-specific settings */
		switch (ah->ah_radio) {
		case AR5K_RF5111:

			ath5k_hw_ini_mode_registers(ah,
					ARRAY_SIZE(rf5111_ini_mode_end),
					rf5111_ini_mode_end, mode);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5111_ini_common_end),
					rf5111_ini_common_end, skip_pcu);

			/* Baseband gain table */
			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5111_ini_bbgain),
					rf5111_ini_bbgain, skip_pcu);

			break;
		case AR5K_RF5112:

			ath5k_hw_ini_mode_registers(ah,
					ARRAY_SIZE(rf5112_ini_mode_end),
					rf5112_ini_mode_end, mode);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5112_ini_common_end),
					rf5112_ini_common_end, skip_pcu);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5112_ini_bbgain),
					rf5112_ini_bbgain, skip_pcu);

			break;
		case AR5K_RF5413:

			ath5k_hw_ini_mode_registers(ah,
					ARRAY_SIZE(rf5413_ini_mode_end),
					rf5413_ini_mode_end, mode);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5413_ini_common_end),
					rf5413_ini_common_end, skip_pcu);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5112_ini_bbgain),
					rf5112_ini_bbgain, skip_pcu);

			break;
		case AR5K_RF2316:
		case AR5K_RF2413:

			ath5k_hw_ini_mode_registers(ah,
					ARRAY_SIZE(rf2413_ini_mode_end),
					rf2413_ini_mode_end, mode);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf2413_ini_common_end),
					rf2413_ini_common_end, skip_pcu);

			/* Override settings from rf2413_ini_common_end */
			if (ah->ah_radio == AR5K_RF2316) {
				ath5k_hw_reg_write(ah, 0x00004000,
							AR5K_PHY_AGC);
				ath5k_hw_reg_write(ah, 0x081b7caa,
							0xa274);
			}

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5112_ini_bbgain),
					rf5112_ini_bbgain, skip_pcu);
			break;
		case AR5K_RF2317:

			ath5k_hw_ini_mode_registers(ah,
					ARRAY_SIZE(rf2413_ini_mode_end),
					rf2413_ini_mode_end, mode);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf2425_ini_common_end),
					rf2425_ini_common_end, skip_pcu);

			/* Override settings from rf2413_ini_mode_end */
			ath5k_hw_reg_write(ah, 0x00180a65, AR5K_PHY_GAIN);

			/* Override settings from rf2413_ini_common_end */
			ath5k_hw_reg_write(ah, 0x00004000, AR5K_PHY_AGC);
			AR5K_REG_WRITE_BITS(ah, AR5K_PHY_TPC_RG5,
				AR5K_PHY_TPC_RG5_PD_GAIN_OVERLAP, 0xa);
			ath5k_hw_reg_write(ah, 0x800000a8, 0x8140);
			ath5k_hw_reg_write(ah, 0x000000ff, 0x9958);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5112_ini_bbgain),
					rf5112_ini_bbgain, skip_pcu);
			break;
		case AR5K_RF2425:

			ath5k_hw_ini_mode_registers(ah,
					ARRAY_SIZE(rf2425_ini_mode_end),
					rf2425_ini_mode_end, mode);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf2425_ini_common_end),
					rf2425_ini_common_end, skip_pcu);

			ath5k_hw_ini_registers(ah,
					ARRAY_SIZE(rf5112_ini_bbgain),
					rf5112_ini_bbgain, skip_pcu);
			break;
		default:
			return -EINVAL;

		}

	/* For AR5211 */
	} else if (ah->ah_version == AR5K_AR5211) {

		/* AR5K_MODE_11B */
		if (mode > 2) {
			ATH5K_ERR(ah, "unsupported channel mode: %d\n", mode);
			return -EINVAL;
		}

		/* Mode-specific settings */
		ath5k_hw_ini_mode_registers(ah, ARRAY_SIZE(ar5211_ini_mode),
				ar5211_ini_mode, mode);

		/*
		 * Write initial settings common for all modes
		 */
		ath5k_hw_ini_registers(ah, ARRAY_SIZE(ar5211_ini),
				ar5211_ini, skip_pcu);

		/* AR5211 only comes with 5111 */

		/* Baseband gain table */
		ath5k_hw_ini_registers(ah, ARRAY_SIZE(rf5111_ini_bbgain),
				rf5111_ini_bbgain, skip_pcu);
	/* For AR5210 (for mode settings check out ath5k_hw_reset_tx_queue) */
	} else if (ah->ah_version == AR5K_AR5210) {
		ath5k_hw_ini_registers(ah, ARRAY_SIZE(ar5210_ini),
				ar5210_ini, skip_pcu);
	}

	return 0;
}

