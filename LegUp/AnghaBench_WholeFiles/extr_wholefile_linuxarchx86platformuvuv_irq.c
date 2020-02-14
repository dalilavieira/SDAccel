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
struct uv_irq_2_mmr_pnode {unsigned long offset; int /*<<< orphan*/  pnode; } ;
struct uv_IO_APIC_route_entry {int mask; int /*<<< orphan*/  dest; scalar_t__ trigger; scalar_t__ polarity; int /*<<< orphan*/  dest_mode; int /*<<< orphan*/  delivery_mode; int /*<<< orphan*/  vector; } ;
struct irq_domain {int /*<<< orphan*/  parent; } ;
struct irq_data {struct uv_irq_2_mmr_pnode* chip_data; TYPE_1__* chip; struct irq_data* parent_data; } ;
struct irq_cfg {int /*<<< orphan*/  dest_apicid; int /*<<< orphan*/  vector; } ;
struct irq_alloc_info {scalar_t__ type; scalar_t__ uv_limit; int uv_blade; unsigned long uv_offset; char* uv_name; } ;
struct fwnode_handle {int dummy; } ;
struct cpumask {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  irq_dest_mode; int /*<<< orphan*/  irq_delivery_mode; } ;
struct TYPE_3__ {int (* irq_set_affinity ) (struct irq_data*,struct cpumask const*,int) ;} ;
typedef  int /*<<< orphan*/  DEFINE_MUTEX ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_MOVE_PCNTXT ; 
 int /*<<< orphan*/  IRQ_NO_BALANCING ; 
 scalar_t__ UV_AFFINITY_CPU ; 
 scalar_t__ X86_IRQ_ALLOC_TYPE_UV ; 
 TYPE_2__* apic ; 
 int /*<<< orphan*/  cpumask_of (int) ; 
 int /*<<< orphan*/  handle_percpu_irq ; 
 int /*<<< orphan*/  init_irq_alloc_info (struct irq_alloc_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_clear_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_data_get_node (struct irq_data*) ; 
 int irq_domain_alloc_irqs (struct irq_domain*,int,int /*<<< orphan*/ ,struct irq_alloc_info*) ; 
 int irq_domain_alloc_irqs_parent (struct irq_domain*,unsigned int,unsigned int,void*) ; 
 struct fwnode_handle* irq_domain_alloc_named_fwnode (char*) ; 
 struct irq_domain* irq_domain_create_tree (struct fwnode_handle*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_domain_free_fwnode (struct fwnode_handle*) ; 
 int /*<<< orphan*/  irq_domain_free_irqs (unsigned int,int) ; 
 int /*<<< orphan*/  irq_domain_free_irqs_top (struct irq_domain*,unsigned int,unsigned int) ; 
 struct irq_data* irq_domain_get_irq_data (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_domain_set_info (struct irq_domain*,unsigned int,unsigned int,int /*<<< orphan*/ *,struct uv_irq_2_mmr_pnode*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 struct irq_cfg* irqd_cfg (struct irq_data*) ; 
 int /*<<< orphan*/  kfree (struct uv_irq_2_mmr_pnode*) ; 
 struct uv_irq_2_mmr_pnode* kmalloc_node (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  send_cleanup_vector (struct irq_cfg*) ; 
 int stub1 (struct irq_data*,struct cpumask const*,int) ; 
 int /*<<< orphan*/  uv_blade_to_memory_nid (int) ; 
 int /*<<< orphan*/  uv_blade_to_pnode (int) ; 
 int /*<<< orphan*/  uv_domain_ops ; 
 int /*<<< orphan*/  uv_irq_chip ; 
 int /*<<< orphan*/  uv_write_global_mmr64 (int /*<<< orphan*/ ,unsigned long,unsigned long) ; 
 int /*<<< orphan*/  x86_vector_domain ; 

__attribute__((used)) static void uv_program_mmr(struct irq_cfg *cfg, struct uv_irq_2_mmr_pnode *info)
{
	unsigned long mmr_value;
	struct uv_IO_APIC_route_entry *entry;

	BUILD_BUG_ON(sizeof(struct uv_IO_APIC_route_entry) !=
		     sizeof(unsigned long));

	mmr_value = 0;
	entry = (struct uv_IO_APIC_route_entry *)&mmr_value;
	entry->vector		= cfg->vector;
	entry->delivery_mode	= apic->irq_delivery_mode;
	entry->dest_mode	= apic->irq_dest_mode;
	entry->polarity		= 0;
	entry->trigger		= 0;
	entry->mask		= 0;
	entry->dest		= cfg->dest_apicid;

	uv_write_global_mmr64(info->pnode, info->offset, mmr_value);
}

__attribute__((used)) static void uv_noop(struct irq_data *data) { }

__attribute__((used)) static int
uv_set_irq_affinity(struct irq_data *data, const struct cpumask *mask,
		    bool force)
{
	struct irq_data *parent = data->parent_data;
	struct irq_cfg *cfg = irqd_cfg(data);
	int ret;

	ret = parent->chip->irq_set_affinity(parent, mask, force);
	if (ret >= 0) {
		uv_program_mmr(cfg, data->chip_data);
		send_cleanup_vector(cfg);
	}

	return ret;
}

__attribute__((used)) static int uv_domain_alloc(struct irq_domain *domain, unsigned int virq,
			   unsigned int nr_irqs, void *arg)
{
	struct uv_irq_2_mmr_pnode *chip_data;
	struct irq_alloc_info *info = arg;
	struct irq_data *irq_data = irq_domain_get_irq_data(domain, virq);
	int ret;

	if (nr_irqs > 1 || !info || info->type != X86_IRQ_ALLOC_TYPE_UV)
		return -EINVAL;

	chip_data = kmalloc_node(sizeof(*chip_data), GFP_KERNEL,
				 irq_data_get_node(irq_data));
	if (!chip_data)
		return -ENOMEM;

	ret = irq_domain_alloc_irqs_parent(domain, virq, nr_irqs, arg);
	if (ret >= 0) {
		if (info->uv_limit == UV_AFFINITY_CPU)
			irq_set_status_flags(virq, IRQ_NO_BALANCING);
		else
			irq_set_status_flags(virq, IRQ_MOVE_PCNTXT);

		chip_data->pnode = uv_blade_to_pnode(info->uv_blade);
		chip_data->offset = info->uv_offset;
		irq_domain_set_info(domain, virq, virq, &uv_irq_chip, chip_data,
				    handle_percpu_irq, NULL, info->uv_name);
	} else {
		kfree(chip_data);
	}

	return ret;
}

__attribute__((used)) static void uv_domain_free(struct irq_domain *domain, unsigned int virq,
			   unsigned int nr_irqs)
{
	struct irq_data *irq_data = irq_domain_get_irq_data(domain, virq);

	BUG_ON(nr_irqs != 1);
	kfree(irq_data->chip_data);
	irq_clear_status_flags(virq, IRQ_MOVE_PCNTXT);
	irq_clear_status_flags(virq, IRQ_NO_BALANCING);
	irq_domain_free_irqs_top(domain, virq, nr_irqs);
}

__attribute__((used)) static int uv_domain_activate(struct irq_domain *domain,
			      struct irq_data *irq_data, bool reserve)
{
	uv_program_mmr(irqd_cfg(irq_data), irq_data->chip_data);
	return 0;
}

__attribute__((used)) static void uv_domain_deactivate(struct irq_domain *domain,
				 struct irq_data *irq_data)
{
	unsigned long mmr_value;
	struct uv_IO_APIC_route_entry *entry;

	mmr_value = 0;
	entry = (struct uv_IO_APIC_route_entry *)&mmr_value;
	entry->mask = 1;
	uv_program_mmr(irqd_cfg(irq_data), irq_data->chip_data);
}

__attribute__((used)) static struct irq_domain *uv_get_irq_domain(void)
{
	static struct irq_domain *uv_domain;
	static DEFINE_MUTEX(uv_lock);
	struct fwnode_handle *fn;

	mutex_lock(&uv_lock);
	if (uv_domain)
		goto out;

	fn = irq_domain_alloc_named_fwnode("UV-CORE");
	if (!fn)
		goto out;

	uv_domain = irq_domain_create_tree(fn, &uv_domain_ops, NULL);
	irq_domain_free_fwnode(fn);
	if (uv_domain)
		uv_domain->parent = x86_vector_domain;
out:
	mutex_unlock(&uv_lock);

	return uv_domain;
}

int uv_setup_irq(char *irq_name, int cpu, int mmr_blade,
		 unsigned long mmr_offset, int limit)
{
	struct irq_alloc_info info;
	struct irq_domain *domain = uv_get_irq_domain();

	if (!domain)
		return -ENOMEM;

	init_irq_alloc_info(&info, cpumask_of(cpu));
	info.type = X86_IRQ_ALLOC_TYPE_UV;
	info.uv_limit = limit;
	info.uv_blade = mmr_blade;
	info.uv_offset = mmr_offset;
	info.uv_name = irq_name;

	return irq_domain_alloc_irqs(domain, 1,
				     uv_blade_to_memory_nid(mmr_blade), &info);
}

void uv_teardown_irq(unsigned int irq)
{
	irq_domain_free_irqs(irq, 1);
}

