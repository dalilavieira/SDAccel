#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct pmc_reg_map {int slp_s0_offset; int pm_cfg_offset; int /*<<< orphan*/  pm_read_disable_bit; } ;
struct pmc_dev {struct pmc_reg_map* map; scalar_t__ regbase; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int SPT_PMC_SLP_S0_RES_COUNTER_STEP ; 
 struct pmc_dev pmc ; 
 int /*<<< orphan*/  readb (scalar_t__) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  writel (int,scalar_t__) ; 

__attribute__((used)) static inline u8 pmc_core_reg_read_byte(struct pmc_dev *pmcdev, int offset)
{
	return readb(pmcdev->regbase + offset);
}

__attribute__((used)) static inline u32 pmc_core_reg_read(struct pmc_dev *pmcdev, int reg_offset)
{
	return readl(pmcdev->regbase + reg_offset);
}

__attribute__((used)) static inline void pmc_core_reg_write(struct pmc_dev *pmcdev, int
							reg_offset, u32 val)
{
	writel(val, pmcdev->regbase + reg_offset);
}

__attribute__((used)) static inline u32 pmc_core_adjust_slp_s0_step(u32 value)
{
	return value * SPT_PMC_SLP_S0_RES_COUNTER_STEP;
}

__attribute__((used)) static int pmc_core_dev_state_get(void *data, u64 *val)
{
	struct pmc_dev *pmcdev = data;
	const struct pmc_reg_map *map = pmcdev->map;
	u32 value;

	value = pmc_core_reg_read(pmcdev, map->slp_s0_offset);
	*val = pmc_core_adjust_slp_s0_step(value);

	return 0;
}

__attribute__((used)) static int pmc_core_check_read_lock_bit(void)
{
	struct pmc_dev *pmcdev = &pmc;
	u32 value;

	value = pmc_core_reg_read(pmcdev, pmcdev->map->pm_cfg_offset);
	return value & BIT(pmcdev->map->pm_read_disable_bit);
}

__attribute__((used)) static inline int pmc_core_dbgfs_register(struct pmc_dev *pmcdev)
{
	return 0;
}

__attribute__((used)) static inline void pmc_core_dbgfs_unregister(struct pmc_dev *pmcdev)
{
}

