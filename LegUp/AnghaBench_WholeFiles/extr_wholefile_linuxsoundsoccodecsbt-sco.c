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
struct platform_device {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bt_sco_dai ; 
 int devm_snd_soc_register_component (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  soc_component_dev_bt_sco ; 

__attribute__((used)) static int bt_sco_probe(struct platform_device *pdev)
{
	return devm_snd_soc_register_component(&pdev->dev,
				      &soc_component_dev_bt_sco,
				      bt_sco_dai, ARRAY_SIZE(bt_sco_dai));
}

__attribute__((used)) static int bt_sco_remove(struct platform_device *pdev)
{
	return 0;
}

