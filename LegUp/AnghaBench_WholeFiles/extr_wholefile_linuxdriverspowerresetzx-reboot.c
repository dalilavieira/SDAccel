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
struct TYPE_2__ {struct device_node* of_node; } ;
struct platform_device {TYPE_1__ dev; } ;
struct notifier_block {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 
 int NOTIFY_DONE ; 
 int /*<<< orphan*/  WARN (int,char*) ; 
 scalar_t__ base ; 
 int /*<<< orphan*/  dev_err (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  iounmap (scalar_t__) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 struct device_node* of_find_compatible_node (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 
 scalar_t__ of_iomap (struct device_node*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 scalar_t__ pcu_base ; 
 int /*<<< orphan*/  pr_emerg (char*) ; 
 int register_restart_handler (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  writel_relaxed (int,scalar_t__) ; 
 int /*<<< orphan*/  zx_restart_nb ; 

__attribute__((used)) static int zx_restart_handler(struct notifier_block *this,
			      unsigned long mode, void *cmd)
{
	writel_relaxed(1, base + 0xb0);
	writel_relaxed(1, pcu_base + 0x34);

	mdelay(50);
	pr_emerg("Unable to restart system\n");

	return NOTIFY_DONE;
}

__attribute__((used)) static int zx_reboot_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	int err;

	base = of_iomap(np, 0);
	if (!base) {
		WARN(1, "failed to map base address");
		return -ENODEV;
	}

	np = of_find_compatible_node(NULL, NULL, "zte,zx296702-pcu");
	pcu_base = of_iomap(np, 0);
	of_node_put(np);
	if (!pcu_base) {
		iounmap(base);
		WARN(1, "failed to map pcu_base address");
		return -ENODEV;
	}

	err = register_restart_handler(&zx_restart_nb);
	if (err) {
		iounmap(base);
		iounmap(pcu_base);
		dev_err(&pdev->dev, "Register restart handler failed(err=%d)\n",
			err);
	}

	return err;
}

