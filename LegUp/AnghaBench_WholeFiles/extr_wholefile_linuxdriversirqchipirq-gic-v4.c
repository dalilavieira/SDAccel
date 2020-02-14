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
typedef  int /*<<< orphan*/  u8 ;
struct its_vpe {int irq; } ;
struct its_vm {int nr_vpes; scalar_t__ fwnode; scalar_t__ domain; TYPE_1__** vpes; } ;
struct its_vlpi_map {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  config; struct its_vlpi_map* map; } ;
struct its_cmd_info {TYPE_2__ member_1; int /*<<< orphan*/  cmd_type; } ;
struct irq_domain_ops {int dummy; } ;
struct irq_domain {int dummy; } ;
struct TYPE_3__ {int idai; int irq; struct its_vm* its_vm; } ;

/* Variables and functions */
 int /*<<< orphan*/  DESCHEDULE_VPE ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GET_VLPI ; 
 int /*<<< orphan*/  INVALL_VPE ; 
 int /*<<< orphan*/  IRQ_DISABLE_UNLAZY ; 
 int /*<<< orphan*/  MAP_VLPI ; 
 int /*<<< orphan*/  NUMA_NO_NODE ; 
 int /*<<< orphan*/  PROP_UPDATE_AND_INV_VLPI ; 
 int /*<<< orphan*/  PROP_UPDATE_VLPI ; 
 int /*<<< orphan*/  SCHEDULE_VPE ; 
 int /*<<< orphan*/  WARN_ON (int /*<<< orphan*/ ) ; 
 int __irq_domain_alloc_irqs (scalar_t__,int,int,int /*<<< orphan*/ ,struct its_vm*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  current ; 
 struct irq_domain* gic_domain ; 
 int /*<<< orphan*/  irq_clear_status_flags (int,int /*<<< orphan*/ ) ; 
 scalar_t__ irq_domain_alloc_named_id_fwnode (char*,int /*<<< orphan*/ ) ; 
 scalar_t__ irq_domain_create_hierarchy (struct irq_domain*,int /*<<< orphan*/ ,int,scalar_t__,struct irq_domain_ops const*,struct its_vm*) ; 
 int /*<<< orphan*/  irq_domain_free_fwnode (scalar_t__) ; 
 int /*<<< orphan*/  irq_domain_free_irqs (int,int) ; 
 int /*<<< orphan*/  irq_domain_remove (scalar_t__) ; 
 int /*<<< orphan*/  irq_set_status_flags (int,int /*<<< orphan*/ ) ; 
 int irq_set_vcpu_affinity (int,struct its_cmd_info*) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  preemptible () ; 
 int /*<<< orphan*/  task_pid_nr (int /*<<< orphan*/ ) ; 
 struct irq_domain_ops const* vpe_domain_ops ; 

int its_alloc_vcpu_irqs(struct its_vm *vm)
{
	int vpe_base_irq, i;

	vm->fwnode = irq_domain_alloc_named_id_fwnode("GICv4-vpe",
						      task_pid_nr(current));
	if (!vm->fwnode)
		goto err;

	vm->domain = irq_domain_create_hierarchy(gic_domain, 0, vm->nr_vpes,
						 vm->fwnode, vpe_domain_ops,
						 vm);
	if (!vm->domain)
		goto err;

	for (i = 0; i < vm->nr_vpes; i++) {
		vm->vpes[i]->its_vm = vm;
		vm->vpes[i]->idai = true;
	}

	vpe_base_irq = __irq_domain_alloc_irqs(vm->domain, -1, vm->nr_vpes,
					       NUMA_NO_NODE, vm,
					       false, NULL);
	if (vpe_base_irq <= 0)
		goto err;

	for (i = 0; i < vm->nr_vpes; i++)
		vm->vpes[i]->irq = vpe_base_irq + i;

	return 0;

err:
	if (vm->domain)
		irq_domain_remove(vm->domain);
	if (vm->fwnode)
		irq_domain_free_fwnode(vm->fwnode);

	return -ENOMEM;
}

void its_free_vcpu_irqs(struct its_vm *vm)
{
	irq_domain_free_irqs(vm->vpes[0]->irq, vm->nr_vpes);
	irq_domain_remove(vm->domain);
	irq_domain_free_fwnode(vm->fwnode);
}

__attribute__((used)) static int its_send_vpe_cmd(struct its_vpe *vpe, struct its_cmd_info *info)
{
	return irq_set_vcpu_affinity(vpe->irq, info);
}

int its_schedule_vpe(struct its_vpe *vpe, bool on)
{
	struct its_cmd_info info;

	WARN_ON(preemptible());

	info.cmd_type = on ? SCHEDULE_VPE : DESCHEDULE_VPE;

	return its_send_vpe_cmd(vpe, &info);
}

int its_invall_vpe(struct its_vpe *vpe)
{
	struct its_cmd_info info = {
		.cmd_type = INVALL_VPE,
	};

	return its_send_vpe_cmd(vpe, &info);
}

int its_map_vlpi(int irq, struct its_vlpi_map *map)
{
	struct its_cmd_info info = {
		.cmd_type = MAP_VLPI,
		{
			.map      = map,
		},
	};
	int ret;

	/*
	 * The host will never see that interrupt firing again, so it
	 * is vital that we don't do any lazy masking.
	 */
	irq_set_status_flags(irq, IRQ_DISABLE_UNLAZY);

	ret = irq_set_vcpu_affinity(irq, &info);
	if (ret)
		irq_clear_status_flags(irq, IRQ_DISABLE_UNLAZY);

	return ret;
}

int its_get_vlpi(int irq, struct its_vlpi_map *map)
{
	struct its_cmd_info info = {
		.cmd_type = GET_VLPI,
		{
			.map      = map,
		},
	};

	return irq_set_vcpu_affinity(irq, &info);
}

int its_unmap_vlpi(int irq)
{
	irq_clear_status_flags(irq, IRQ_DISABLE_UNLAZY);
	return irq_set_vcpu_affinity(irq, NULL);
}

int its_prop_update_vlpi(int irq, u8 config, bool inv)
{
	struct its_cmd_info info = {
		.cmd_type = inv ? PROP_UPDATE_AND_INV_VLPI : PROP_UPDATE_VLPI,
		{
			.config   = config,
		},
	};

	return irq_set_vcpu_affinity(irq, &info);
}

int its_init_v4(struct irq_domain *domain, const struct irq_domain_ops *ops)
{
	if (domain) {
		pr_info("ITS: Enabling GICv4 support\n");
		gic_domain = domain;
		vpe_domain_ops = ops;
		return 0;
	}

	pr_err("ITS: No GICv4 VPE domain allocated\n");
	return -ENODEV;
}

