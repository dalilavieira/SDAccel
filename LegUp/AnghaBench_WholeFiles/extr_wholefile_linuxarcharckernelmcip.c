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
struct irq_domain {int dummy; } ;
struct irq_desc {int dummy; } ;
struct irq_data {unsigned int hwirq; } ;
struct irq_chip {int dummy; } ;
struct cpumask {int dummy; } ;
typedef  unsigned int irq_hw_number_t ;
typedef  int /*<<< orphan*/  cpumask_t ;

/* Variables and functions */
 int /*<<< orphan*/  CMD_IDU_SET_DEST ; 
 int /*<<< orphan*/  CMD_IDU_SET_MASK ; 
 int /*<<< orphan*/  CMD_IDU_SET_MODE ; 
 int EINVAL ; 
 unsigned int FIRST_EXT_IRQ ; 
 unsigned int IDU_M_DISTRI_DEST ; 
 unsigned int IDU_M_DISTRI_RR ; 
 unsigned int IDU_M_TRIG_LEVEL ; 
 int /*<<< orphan*/  IRQ_MOVE_PCNTXT ; 
 int IRQ_SET_MASK_OK ; 
 int /*<<< orphan*/  __mcip_cmd_data (int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  chained_irq_enter (struct irq_chip*,struct irq_desc*) ; 
 int /*<<< orphan*/  chained_irq_exit (struct irq_chip*,struct irq_desc*) ; 
 struct cpumask* cpu_online_mask ; 
 int /*<<< orphan*/  cpumask_and (int /*<<< orphan*/ *,struct cpumask const*,struct cpumask*) ; 
 unsigned int* cpumask_bits (int /*<<< orphan*/ *) ; 
 scalar_t__ ffs (unsigned int) ; 
 scalar_t__ fls (unsigned int) ; 
 int /*<<< orphan*/  generic_handle_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int /*<<< orphan*/  idu_irq_chip ; 
 struct irq_chip* irq_desc_get_chip (struct irq_desc*) ; 
 struct irq_domain* irq_desc_get_handler_data (struct irq_desc*) ; 
 int /*<<< orphan*/  irq_desc_get_irq_data (struct irq_desc*) ; 
 int /*<<< orphan*/  irq_find_mapping (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_status_flags (unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int irqd_to_hwirq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mcip_lock ; 
 int /*<<< orphan*/  raw_spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  raw_spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static void idu_set_dest(unsigned int cmn_irq, unsigned int cpu_mask)
{
	__mcip_cmd_data(CMD_IDU_SET_DEST, cmn_irq, cpu_mask);
}

__attribute__((used)) static void idu_set_mode(unsigned int cmn_irq, unsigned int lvl,
			   unsigned int distr)
{
	union {
		unsigned int word;
		struct {
			unsigned int distr:2, pad:2, lvl:1, pad2:27;
		};
	} data;

	data.distr = distr;
	data.lvl = lvl;
	__mcip_cmd_data(CMD_IDU_SET_MODE, cmn_irq, data.word);
}

__attribute__((used)) static void idu_irq_mask_raw(irq_hw_number_t hwirq)
{
	unsigned long flags;

	raw_spin_lock_irqsave(&mcip_lock, flags);
	__mcip_cmd_data(CMD_IDU_SET_MASK, hwirq, 1);
	raw_spin_unlock_irqrestore(&mcip_lock, flags);
}

__attribute__((used)) static void idu_irq_mask(struct irq_data *data)
{
	idu_irq_mask_raw(data->hwirq);
}

__attribute__((used)) static void idu_irq_unmask(struct irq_data *data)
{
	unsigned long flags;

	raw_spin_lock_irqsave(&mcip_lock, flags);
	__mcip_cmd_data(CMD_IDU_SET_MASK, data->hwirq, 0);
	raw_spin_unlock_irqrestore(&mcip_lock, flags);
}

__attribute__((used)) static int
idu_irq_set_affinity(struct irq_data *data, const struct cpumask *cpumask,
		     bool force)
{
	unsigned long flags;
	cpumask_t online;
	unsigned int destination_bits;
	unsigned int distribution_mode;

	/* errout if no online cpu per @cpumask */
	if (!cpumask_and(&online, cpumask, cpu_online_mask))
		return -EINVAL;

	raw_spin_lock_irqsave(&mcip_lock, flags);

	destination_bits = cpumask_bits(&online)[0];
	idu_set_dest(data->hwirq, destination_bits);

	if (ffs(destination_bits) == fls(destination_bits))
		distribution_mode = IDU_M_DISTRI_DEST;
	else
		distribution_mode = IDU_M_DISTRI_RR;

	idu_set_mode(data->hwirq, IDU_M_TRIG_LEVEL, distribution_mode);

	raw_spin_unlock_irqrestore(&mcip_lock, flags);

	return IRQ_SET_MASK_OK;
}

__attribute__((used)) static void idu_irq_enable(struct irq_data *data)
{
	/*
	 * By default send all common interrupts to all available online CPUs.
	 * The affinity of common interrupts in IDU must be set manually since
	 * in some cases the kernel will not call irq_set_affinity() by itself:
	 *   1. When the kernel is not configured with support of SMP.
	 *   2. When the kernel is configured with support of SMP but upper
	 *      interrupt controllers does not support setting of the affinity
	 *      and cannot propagate it to IDU.
	 */
	idu_irq_set_affinity(data, cpu_online_mask, false);
	idu_irq_unmask(data);
}

__attribute__((used)) static void idu_cascade_isr(struct irq_desc *desc)
{
	struct irq_domain *idu_domain = irq_desc_get_handler_data(desc);
	struct irq_chip *core_chip = irq_desc_get_chip(desc);
	irq_hw_number_t core_hwirq = irqd_to_hwirq(irq_desc_get_irq_data(desc));
	irq_hw_number_t idu_hwirq = core_hwirq - FIRST_EXT_IRQ;

	chained_irq_enter(core_chip, desc);
	generic_handle_irq(irq_find_mapping(idu_domain, idu_hwirq));
	chained_irq_exit(core_chip, desc);
}

__attribute__((used)) static int idu_irq_map(struct irq_domain *d, unsigned int virq, irq_hw_number_t hwirq)
{
	irq_set_chip_and_handler(virq, &idu_irq_chip, handle_level_irq);
	irq_set_status_flags(virq, IRQ_MOVE_PCNTXT);

	return 0;
}

