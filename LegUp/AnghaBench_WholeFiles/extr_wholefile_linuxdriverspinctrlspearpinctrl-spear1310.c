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
typedef  scalar_t__ u32 ;
struct spear_pmx {scalar_t__ vbase; } ;
struct platform_device {int dummy; } ;

/* Variables and functions */
 scalar_t__ readl_relaxed (scalar_t__) ; 
 int /*<<< orphan*/  spear1310_machdata ; 
 int spear_pinctrl_probe (struct platform_device*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel_relaxed (scalar_t__,scalar_t__) ; 

__attribute__((used)) static inline u32 pmx_readl(struct spear_pmx *pmx, u32 reg)
{
	return readl_relaxed(pmx->vbase + reg);
}

__attribute__((used)) static inline void pmx_writel(struct spear_pmx *pmx, u32 val, u32 reg)
{
	writel_relaxed(val, pmx->vbase + reg);
}

__attribute__((used)) static int spear1310_pinctrl_probe(struct platform_device *pdev)
{
	return spear_pinctrl_probe(pdev, &spear1310_machdata);
}

