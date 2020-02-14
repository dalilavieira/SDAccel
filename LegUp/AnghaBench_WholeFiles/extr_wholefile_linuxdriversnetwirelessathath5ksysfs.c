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
typedef  unsigned int u32 ;
typedef  scalar_t__ u16 ;
struct device_attribute {int dummy; } ;
struct device {int /*<<< orphan*/  kobj; } ;
struct ath_regulatory {int dummy; } ;
struct ath_ps_ops {int dummy; } ;
struct ath_common {TYPE_1__* bus_ops; struct ath_regulatory regulatory; struct ath_ps_ops const* ps_ops; } ;
struct ath5k_hw {struct device* dev; scalar_t__ iobase; struct ath_common common; } ;
struct ath5k_buf {int dummy; } ;
typedef  int /*<<< orphan*/  ssize_t ;
typedef  enum nl80211_iftype { ____Placeholder_nl80211_iftype } nl80211_iftype ;
typedef  enum ath_bus_type { ____Placeholder_ath_bus_type } ath_bus_type ;
typedef  enum ATH_DEBUG { ____Placeholder_ATH_DEBUG } ATH_DEBUG ;
struct TYPE_2__ {int ath_bus_type; int (* eeprom_read ) (struct ath_common*,unsigned int,scalar_t__*) ;int /*<<< orphan*/  (* read_cachesize ) (struct ath_common*,int*) ;} ;

/* Variables and functions */
 int ATH5K_ANI_MAX_FIRSTEP_LVL ; 
 int ATH5K_ANI_MAX_NOISE_IMM_LVL ; 
 int /*<<< orphan*/  ATH5K_ERR (struct ath5k_hw*,char*) ; 
 int /*<<< orphan*/  PAGE_SIZE ; 
 int /*<<< orphan*/  ath5k_attribute_group_ani ; 
 char const** ath_bus_type_strings ; 
 unsigned int ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  snprintf (char*,int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  stub1 (struct ath_common*,int*) ; 
 int stub2 (struct ath_common*,unsigned int,scalar_t__*) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static ssize_t ath5k_attr_show_noise_immunity_level_max(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%d\n", ATH5K_ANI_MAX_NOISE_IMM_LVL);
}

__attribute__((used)) static ssize_t ath5k_attr_show_firstep_level_max(struct device *dev,
			struct device_attribute *attr,
			char *buf)
{
	return snprintf(buf, PAGE_SIZE, "%d\n", ATH5K_ANI_MAX_FIRSTEP_LVL);
}

int
ath5k_sysfs_register(struct ath5k_hw *ah)
{
	struct device *dev = ah->dev;
	int err;

	err = sysfs_create_group(&dev->kobj, &ath5k_attribute_group_ani);
	if (err) {
		ATH5K_ERR(ah, "failed to create sysfs group\n");
		return err;
	}

	return 0;
}

void
ath5k_sysfs_unregister(struct ath5k_hw *ah)
{
	struct device *dev = ah->dev;

	sysfs_remove_group(&dev->kobj, &ath5k_attribute_group_ani);
}

