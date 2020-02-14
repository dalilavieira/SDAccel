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
struct TYPE_2__ {struct omap_device* od; } ;
struct platform_device {TYPE_1__ archdata; } ;
struct omap_device {int dummy; } ;
struct omap2_hsmmc_info {int dummy; } ;

/* Variables and functions */
 scalar_t__ omap_rev () ; 

__attribute__((used)) static inline int soc_is_omap(void)
{
	return omap_rev() != 0;
}

__attribute__((used)) static inline struct omap_device *to_omap_device(struct platform_device *pdev)
{
	return pdev ? pdev->archdata.od : NULL;
}

__attribute__((used)) static inline void omap_hsmmc_init(struct omap2_hsmmc_info *info)
{
}

__attribute__((used)) static inline void omap_hsmmc_late_init(struct omap2_hsmmc_info *info)
{
}

