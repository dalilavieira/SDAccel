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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;

/* Variables and functions */
 int /*<<< orphan*/  OMAP_SDRC_REGADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  OMAP_SMS_REGADDR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl_relaxed (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void sdrc_write_reg(u32 val, u16 reg)
{
	writel_relaxed(val, OMAP_SDRC_REGADDR(reg));
}

__attribute__((used)) static inline u32 sdrc_read_reg(u16 reg)
{
	return readl_relaxed(OMAP_SDRC_REGADDR(reg));
}

__attribute__((used)) static inline void sms_write_reg(u32 val, u16 reg)
{
	writel_relaxed(val, OMAP_SMS_REGADDR(reg));
}

__attribute__((used)) static inline u32 sms_read_reg(u16 reg)
{
	return readl_relaxed(OMAP_SMS_REGADDR(reg));
}

