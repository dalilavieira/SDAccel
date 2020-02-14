#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct resource {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct TYPE_3__ {struct device* parent; } ;
struct pci_host_bridge {int /*<<< orphan*/  bus; int /*<<< orphan*/  swizzle_irq; int /*<<< orphan*/  map_irq; int /*<<< orphan*/ * ops; int /*<<< orphan*/  busnr; struct pci_config_window* sysdata; TYPE_1__ dev; int /*<<< orphan*/  windows; } ;
struct pci_ecam_ops {int /*<<< orphan*/  pci_ops; } ;
struct TYPE_4__ {int /*<<< orphan*/  start; } ;
struct pci_config_window {TYPE_2__ busr; } ;
struct pci_bus {int dummy; } ;
struct list_head {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 struct pci_config_window* ERR_PTR (int) ; 
 scalar_t__ IS_ERR (struct pci_config_window*) ; 
 int /*<<< orphan*/  PCI_PROBE_ONLY ; 
 int /*<<< orphan*/  PCI_REASSIGN_ALL_BUS ; 
 int PTR_ERR (struct pci_config_window*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int devm_add_action (struct device*,void (*) (void*),struct pci_config_window*) ; 
 struct pci_host_bridge* devm_pci_alloc_host_bridge (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list_splice_init (struct list_head*,int /*<<< orphan*/ *) ; 
 int of_address_to_resource (struct device_node*,int /*<<< orphan*/ ,struct resource*) ; 
 char* of_get_property (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_irq_parse_and_map_pci ; 
 int /*<<< orphan*/  of_pci_check_probe_only () ; 
 int /*<<< orphan*/  pci_add_flags (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_common_swizzle ; 
 struct pci_config_window* pci_ecam_create (struct device*,struct resource*,struct resource*,struct pci_ecam_ops*) ; 
 int /*<<< orphan*/  pci_ecam_free (struct pci_config_window*) ; 
 int /*<<< orphan*/  pci_free_resource_list (struct list_head*) ; 
 int /*<<< orphan*/  pci_has_flag (int /*<<< orphan*/ ) ; 
 int pci_host_probe (struct pci_host_bridge*) ; 
 int /*<<< orphan*/  pci_lock_rescan_remove () ; 
 int pci_parse_request_of_pci_ranges (struct device*,struct list_head*,struct resource**) ; 
 int /*<<< orphan*/  pci_remove_root_bus (struct pci_bus*) ; 
 int /*<<< orphan*/  pci_stop_root_bus (struct pci_bus*) ; 
 int /*<<< orphan*/  pci_unlock_rescan_remove () ; 
 struct pci_bus* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char const*,char*) ; 

__attribute__((used)) static void gen_pci_unmap_cfg(void *ptr)
{
	pci_ecam_free((struct pci_config_window *)ptr);
}

__attribute__((used)) static struct pci_config_window *gen_pci_init(struct device *dev,
		struct list_head *resources, struct pci_ecam_ops *ops)
{
	int err;
	struct resource cfgres;
	struct resource *bus_range = NULL;
	struct pci_config_window *cfg;

	/* Parse our PCI ranges and request their resources */
	err = pci_parse_request_of_pci_ranges(dev, resources, &bus_range);
	if (err)
		return ERR_PTR(err);

	err = of_address_to_resource(dev->of_node, 0, &cfgres);
	if (err) {
		dev_err(dev, "missing \"reg\" property\n");
		goto err_out;
	}

	cfg = pci_ecam_create(dev, &cfgres, bus_range, ops);
	if (IS_ERR(cfg)) {
		err = PTR_ERR(cfg);
		goto err_out;
	}

	err = devm_add_action(dev, gen_pci_unmap_cfg, cfg);
	if (err) {
		gen_pci_unmap_cfg(cfg);
		goto err_out;
	}
	return cfg;

err_out:
	pci_free_resource_list(resources);
	return ERR_PTR(err);
}

int pci_host_common_probe(struct platform_device *pdev,
			  struct pci_ecam_ops *ops)
{
	const char *type;
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct pci_host_bridge *bridge;
	struct pci_config_window *cfg;
	struct list_head resources;
	int ret;

	bridge = devm_pci_alloc_host_bridge(dev, 0);
	if (!bridge)
		return -ENOMEM;

	type = of_get_property(np, "device_type", NULL);
	if (!type || strcmp(type, "pci")) {
		dev_err(dev, "invalid \"device_type\" %s\n", type);
		return -EINVAL;
	}

	of_pci_check_probe_only();

	/* Parse and map our Configuration Space windows */
	cfg = gen_pci_init(dev, &resources, ops);
	if (IS_ERR(cfg))
		return PTR_ERR(cfg);

	/* Do not reassign resources if probe only */
	if (!pci_has_flag(PCI_PROBE_ONLY))
		pci_add_flags(PCI_REASSIGN_ALL_BUS);

	list_splice_init(&resources, &bridge->windows);
	bridge->dev.parent = dev;
	bridge->sysdata = cfg;
	bridge->busnr = cfg->busr.start;
	bridge->ops = &ops->pci_ops;
	bridge->map_irq = of_irq_parse_and_map_pci;
	bridge->swizzle_irq = pci_common_swizzle;

	ret = pci_host_probe(bridge);
	if (ret < 0) {
		pci_free_resource_list(&resources);
		return ret;
	}

	platform_set_drvdata(pdev, bridge->bus);
	return 0;
}

int pci_host_common_remove(struct platform_device *pdev)
{
	struct pci_bus *bus = platform_get_drvdata(pdev);

	pci_lock_rescan_remove();
	pci_stop_root_bus(bus);
	pci_remove_root_bus(bus);
	pci_unlock_rescan_remove();

	return 0;
}

