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

/* Variables and functions */
 scalar_t__ cpubiuctrl_base ; 
 int* cpubiuctrl_regs ; 
 int /*<<< orphan*/  readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  writel_relaxed (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline u32 cbc_readl(int reg)
{
	int offset = cpubiuctrl_regs[reg];

	if (offset == -1)
		return (u32)-1;

	return readl_relaxed(cpubiuctrl_base + offset);
}

__attribute__((used)) static inline void cbc_writel(u32 val, int reg)
{
	int offset = cpubiuctrl_regs[reg];

	if (offset == -1)
		return;

	writel_relaxed(val,  cpubiuctrl_base + offset);
}

