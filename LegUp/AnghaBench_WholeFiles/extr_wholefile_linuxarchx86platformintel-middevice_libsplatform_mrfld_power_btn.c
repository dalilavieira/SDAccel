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
struct notifier_block {int dummy; } ;

/* Variables and functions */
 unsigned long SCU_DOWN ; 
 int /*<<< orphan*/  mrfld_power_btn_dev ; 
 int platform_device_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  platform_device_unregister (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int mrfld_power_btn_scu_status_change(struct notifier_block *nb,
					     unsigned long code, void *data)
{
	if (code == SCU_DOWN) {
		platform_device_unregister(&mrfld_power_btn_dev);
		return 0;
	}

	return platform_device_register(&mrfld_power_btn_dev);
}

