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
typedef  unsigned int u32 ;
typedef  scalar_t__ u16 ;
struct ath_regulatory {int dummy; } ;
struct ath_ps_ops {int dummy; } ;
struct ath_common {TYPE_1__* bus_ops; struct ath_regulatory regulatory; struct ath_ps_ops const* ps_ops; } ;
struct TYPE_10__ {int polarity; int /*<<< orphan*/  toggleq; int /*<<< orphan*/  gpio; } ;
struct TYPE_8__ {scalar_t__ ee_rfkill_pol; int /*<<< orphan*/  ee_header; int /*<<< orphan*/  ee_rfkill_pin; } ;
struct TYPE_9__ {TYPE_3__ cap_eeprom; } ;
struct ath5k_hw {TYPE_5__ rf_kill; TYPE_4__ ah_capabilities; TYPE_2__* hw; scalar_t__ iobase; struct ath_common common; } ;
struct ath5k_buf {int dummy; } ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum ath_bus_type { ____Placeholder_ath_bus_type } ath_bus_type ;
typedef  enum ATH_DEBUG { ____Placeholder_ATH_DEBUG } ATH_DEBUG ;
struct TYPE_7__ {int /*<<< orphan*/  wiphy; } ;
struct TYPE_6__ {int ath_bus_type; int (* eeprom_read ) (struct ath_common*,unsigned int,scalar_t__*) ;int /*<<< orphan*/  (* read_cachesize ) (struct ath_common*,int*) ;} ;

/* Variables and functions */
 scalar_t__ AR5K_EEPROM_HDR_RFKILL (int /*<<< orphan*/ ) ; 
 unsigned int ATH5K_DEBUG_ANY ; 
 scalar_t__ ath5k_hw_get_gpio (struct ath5k_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath5k_hw_set_gpio (struct ath5k_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ath5k_hw_set_gpio_input (struct ath5k_hw*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ath5k_hw_set_gpio_intr (struct ath5k_hw*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ath5k_hw_set_gpio_output (struct ath5k_hw*,int /*<<< orphan*/ ) ; 
 char const** ath_bus_type_strings ; 
 unsigned int ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  stub1 (struct ath_common*,int*) ; 
 int stub2 (struct ath_common*,unsigned int,scalar_t__*) ; 
 int /*<<< orphan*/  tasklet_init (int /*<<< orphan*/ *,void (*) (unsigned long),unsigned long) ; 
 int /*<<< orphan*/  tasklet_kill (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wiphy_rfkill_set_hw_state (int /*<<< orphan*/ ,int) ; 

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

__attribute__((used)) static inline void ath5k_rfkill_disable(struct ath5k_hw *ah)
{
	ATH5K_DBG(ah, ATH5K_DEBUG_ANY, "rfkill disable (gpio:%d polarity:%d)\n",
		ah->rf_kill.gpio, ah->rf_kill.polarity);
	ath5k_hw_set_gpio_output(ah, ah->rf_kill.gpio);
	ath5k_hw_set_gpio(ah, ah->rf_kill.gpio, !ah->rf_kill.polarity);
}

__attribute__((used)) static inline void ath5k_rfkill_enable(struct ath5k_hw *ah)
{
	ATH5K_DBG(ah, ATH5K_DEBUG_ANY, "rfkill enable (gpio:%d polarity:%d)\n",
		ah->rf_kill.gpio, ah->rf_kill.polarity);
	ath5k_hw_set_gpio_output(ah, ah->rf_kill.gpio);
	ath5k_hw_set_gpio(ah, ah->rf_kill.gpio, ah->rf_kill.polarity);
}

__attribute__((used)) static inline void ath5k_rfkill_set_intr(struct ath5k_hw *ah, bool enable)
{
	u32 curval;

	ath5k_hw_set_gpio_input(ah, ah->rf_kill.gpio);
	curval = ath5k_hw_get_gpio(ah, ah->rf_kill.gpio);
	ath5k_hw_set_gpio_intr(ah, ah->rf_kill.gpio, enable ?
					!!curval : !curval);
}

__attribute__((used)) static bool
ath5k_is_rfkill_set(struct ath5k_hw *ah)
{
	/* configuring GPIO for input for some reason disables rfkill */
	/*ath5k_hw_set_gpio_input(ah, ah->rf_kill.gpio);*/
	return ath5k_hw_get_gpio(ah, ah->rf_kill.gpio) ==
							ah->rf_kill.polarity;
}

__attribute__((used)) static void
ath5k_tasklet_rfkill_toggle(unsigned long data)
{
	struct ath5k_hw *ah = (void *)data;
	bool blocked;

	blocked = ath5k_is_rfkill_set(ah);
	wiphy_rfkill_set_hw_state(ah->hw->wiphy, blocked);
}

void
ath5k_rfkill_hw_start(struct ath5k_hw *ah)
{
	/* read rfkill GPIO configuration from EEPROM header */
	ah->rf_kill.gpio = ah->ah_capabilities.cap_eeprom.ee_rfkill_pin;
	ah->rf_kill.polarity = ah->ah_capabilities.cap_eeprom.ee_rfkill_pol;

	tasklet_init(&ah->rf_kill.toggleq, ath5k_tasklet_rfkill_toggle,
		(unsigned long)ah);

	ath5k_rfkill_disable(ah);

	/* enable interrupt for rfkill switch */
	if (AR5K_EEPROM_HDR_RFKILL(ah->ah_capabilities.cap_eeprom.ee_header))
		ath5k_rfkill_set_intr(ah, true);
}

void
ath5k_rfkill_hw_stop(struct ath5k_hw *ah)
{
	/* disable interrupt for rfkill switch */
	if (AR5K_EEPROM_HDR_RFKILL(ah->ah_capabilities.cap_eeprom.ee_header))
		ath5k_rfkill_set_intr(ah, false);

	tasklet_kill(&ah->rf_kill.toggleq);

	/* enable RFKILL when stopping HW so Wifi LED is turned off */
	ath5k_rfkill_enable(ah);
}

