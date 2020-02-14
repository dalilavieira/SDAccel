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
typedef  unsigned long u32 ;
struct device {int dummy; } ;
struct aq_nic_s {TYPE_2__* ndev; } ;
struct aq_hw_s {unsigned long mmio; int /*<<< orphan*/  flags; TYPE_4__* aq_nic_cfg; } ;
typedef  int /*<<< orphan*/  atomic_t ;
struct TYPE_8__ {TYPE_3__* aq_hw_caps; } ;
struct TYPE_7__ {unsigned long hw_alive_check_addr; } ;
struct TYPE_5__ {struct device* parent; } ;
struct TYPE_6__ {TYPE_1__ dev; } ;

/* Variables and functions */
 unsigned long AQ_HW_FLAG_ERR_HW ; 
 unsigned long AQ_HW_FLAG_ERR_UNPLUG ; 
 int EIO ; 
 int ENXIO ; 
 unsigned long aq_hw_read_reg (struct aq_hw_s*,unsigned long) ; 
 void aq_hw_write_reg (struct aq_hw_s*,unsigned long,unsigned long) ; 
 unsigned long atomic_cmpxchg (int /*<<< orphan*/ *,unsigned long,unsigned long) ; 
 unsigned long atomic_read (int /*<<< orphan*/ *) ; 
 unsigned int readl (unsigned long) ; 
 int /*<<< orphan*/  writel (unsigned long,unsigned long) ; 

__attribute__((used)) static inline void aq_utils_obj_set(atomic_t *flags, u32 mask)
{
	unsigned long flags_old, flags_new;

	do {
		flags_old = atomic_read(flags);
		flags_new = flags_old | (mask);
	} while (atomic_cmpxchg(flags, flags_old, flags_new) != flags_old);
}

__attribute__((used)) static inline void aq_utils_obj_clear(atomic_t *flags, u32 mask)
{
	unsigned long flags_old, flags_new;

	do {
		flags_old = atomic_read(flags);
		flags_new = flags_old & ~(mask);
	} while (atomic_cmpxchg(flags, flags_old, flags_new) != flags_old);
}

__attribute__((used)) static inline bool aq_utils_obj_test(atomic_t *flags, u32 mask)
{
	return atomic_read(flags) & mask;
}

__attribute__((used)) static inline struct device *aq_nic_get_dev(struct aq_nic_s *self)
{
	return self->ndev->dev.parent;
}

void aq_hw_write_reg_bit(struct aq_hw_s *aq_hw, u32 addr, u32 msk,
			 u32 shift, u32 val)
{
	if (msk ^ ~0) {
		u32 reg_old, reg_new;

		reg_old = aq_hw_read_reg(aq_hw, addr);
		reg_new = (reg_old & (~msk)) | (val << shift);

		if (reg_old != reg_new)
			aq_hw_write_reg(aq_hw, addr, reg_new);
	} else {
		aq_hw_write_reg(aq_hw, addr, val);
	}
}

u32 aq_hw_read_reg_bit(struct aq_hw_s *aq_hw, u32 addr, u32 msk, u32 shift)
{
	return ((aq_hw_read_reg(aq_hw, addr) & msk) >> shift);
}

u32 aq_hw_read_reg(struct aq_hw_s *hw, u32 reg)
{
	u32 value = readl(hw->mmio + reg);

	if ((~0U) == value &&
	    (~0U) == readl(hw->mmio +
			   hw->aq_nic_cfg->aq_hw_caps->hw_alive_check_addr))
		aq_utils_obj_set(&hw->flags, AQ_HW_FLAG_ERR_UNPLUG);

	return value;
}

void aq_hw_write_reg(struct aq_hw_s *hw, u32 reg, u32 value)
{
	writel(value, hw->mmio + reg);
}

int aq_hw_err_from_flags(struct aq_hw_s *hw)
{
	int err = 0;

	if (aq_utils_obj_test(&hw->flags, AQ_HW_FLAG_ERR_UNPLUG)) {
		err = -ENXIO;
		goto err_exit;
	}
	if (aq_utils_obj_test(&hw->flags, AQ_HW_FLAG_ERR_HW)) {
		err = -EIO;
		goto err_exit;
	}

err_exit:
	return err;
}

