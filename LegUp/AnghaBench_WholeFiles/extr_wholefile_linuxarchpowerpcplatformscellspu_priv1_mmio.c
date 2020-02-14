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
typedef  int u64 ;
struct spu {TYPE_1__* priv1; int /*<<< orphan*/  node; } ;
struct cpumask {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  resource_allocation_enable_RW; int /*<<< orphan*/  resource_allocation_groupID_RW; int /*<<< orphan*/  tlb_invalidate_entry_W; int /*<<< orphan*/  mfc_tclass_id_RW; int /*<<< orphan*/  mfc_sr1_RW; int /*<<< orphan*/  mfc_sdr_RW; int /*<<< orphan*/  mfc_dsisr_RW; int /*<<< orphan*/  mfc_dar_RW; int /*<<< orphan*/  int_route_RW; int /*<<< orphan*/ * int_stat_RW; int /*<<< orphan*/ * int_mask_RW; } ;

/* Variables and functions */
 int /*<<< orphan*/  SPRN_SDR1 ; 
 int /*<<< orphan*/  cpu_to_node (int) ; 
 int /*<<< orphan*/  cpumask_intersects (struct cpumask const*,struct cpumask const*) ; 
 struct cpumask* cpumask_of_node (int /*<<< orphan*/ ) ; 
 int iic_get_target_id (int) ; 
 int in_be64 (int /*<<< orphan*/ *) ; 
 int mfspr (int /*<<< orphan*/ ) ; 
 scalar_t__ nr_cpus_node (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_be64 (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void int_mask_and(struct spu *spu, int class, u64 mask)
{
	u64 old_mask;

	old_mask = in_be64(&spu->priv1->int_mask_RW[class]);
	out_be64(&spu->priv1->int_mask_RW[class], old_mask & mask);
}

__attribute__((used)) static void int_mask_or(struct spu *spu, int class, u64 mask)
{
	u64 old_mask;

	old_mask = in_be64(&spu->priv1->int_mask_RW[class]);
	out_be64(&spu->priv1->int_mask_RW[class], old_mask | mask);
}

__attribute__((used)) static void int_mask_set(struct spu *spu, int class, u64 mask)
{
	out_be64(&spu->priv1->int_mask_RW[class], mask);
}

__attribute__((used)) static u64 int_mask_get(struct spu *spu, int class)
{
	return in_be64(&spu->priv1->int_mask_RW[class]);
}

__attribute__((used)) static void int_stat_clear(struct spu *spu, int class, u64 stat)
{
	out_be64(&spu->priv1->int_stat_RW[class], stat);
}

__attribute__((used)) static u64 int_stat_get(struct spu *spu, int class)
{
	return in_be64(&spu->priv1->int_stat_RW[class]);
}

__attribute__((used)) static void cpu_affinity_set(struct spu *spu, int cpu)
{
	u64 target;
	u64 route;

	if (nr_cpus_node(spu->node)) {
		const struct cpumask *spumask = cpumask_of_node(spu->node),
			*cpumask = cpumask_of_node(cpu_to_node(cpu));

		if (!cpumask_intersects(spumask, cpumask))
			return;
	}

	target = iic_get_target_id(cpu);
	route = target << 48 | target << 32 | target << 16;
	out_be64(&spu->priv1->int_route_RW, route);
}

__attribute__((used)) static u64 mfc_dar_get(struct spu *spu)
{
	return in_be64(&spu->priv1->mfc_dar_RW);
}

__attribute__((used)) static u64 mfc_dsisr_get(struct spu *spu)
{
	return in_be64(&spu->priv1->mfc_dsisr_RW);
}

__attribute__((used)) static void mfc_dsisr_set(struct spu *spu, u64 dsisr)
{
	out_be64(&spu->priv1->mfc_dsisr_RW, dsisr);
}

__attribute__((used)) static void mfc_sdr_setup(struct spu *spu)
{
	out_be64(&spu->priv1->mfc_sdr_RW, mfspr(SPRN_SDR1));
}

__attribute__((used)) static void mfc_sr1_set(struct spu *spu, u64 sr1)
{
	out_be64(&spu->priv1->mfc_sr1_RW, sr1);
}

__attribute__((used)) static u64 mfc_sr1_get(struct spu *spu)
{
	return in_be64(&spu->priv1->mfc_sr1_RW);
}

__attribute__((used)) static void mfc_tclass_id_set(struct spu *spu, u64 tclass_id)
{
	out_be64(&spu->priv1->mfc_tclass_id_RW, tclass_id);
}

__attribute__((used)) static u64 mfc_tclass_id_get(struct spu *spu)
{
	return in_be64(&spu->priv1->mfc_tclass_id_RW);
}

__attribute__((used)) static void tlb_invalidate(struct spu *spu)
{
	out_be64(&spu->priv1->tlb_invalidate_entry_W, 0ul);
}

__attribute__((used)) static void resource_allocation_groupID_set(struct spu *spu, u64 id)
{
	out_be64(&spu->priv1->resource_allocation_groupID_RW, id);
}

__attribute__((used)) static u64 resource_allocation_groupID_get(struct spu *spu)
{
	return in_be64(&spu->priv1->resource_allocation_groupID_RW);
}

__attribute__((used)) static void resource_allocation_enable_set(struct spu *spu, u64 enable)
{
	out_be64(&spu->priv1->resource_allocation_enable_RW, enable);
}

__attribute__((used)) static u64 resource_allocation_enable_get(struct spu *spu)
{
	return in_be64(&spu->priv1->resource_allocation_enable_RW);
}

