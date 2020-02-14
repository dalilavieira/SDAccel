#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct vgic_redist_region {scalar_t__ count; scalar_t__ free_index; } ;
struct vgic_irq {scalar_t__ config; int pending_latch; scalar_t__ intid; int active; int /*<<< orphan*/  refcount; scalar_t__ source; scalar_t__ hw; scalar_t__ line_level; } ;
struct vgic_dist {scalar_t__ vgic_dist_base; int nr_spis; } ;
struct vgic_cpu {int num_pri_bits; } ;
struct TYPE_8__ {struct vgic_cpu vgic_cpu; } ;
struct kvm_vcpu {TYPE_1__ arch; } ;
struct kvm_msi {int /*<<< orphan*/  devid; int /*<<< orphan*/  flags; int /*<<< orphan*/  data; int /*<<< orphan*/  address_hi; int /*<<< orphan*/  address_lo; } ;
struct TYPE_11__ {int /*<<< orphan*/  devid; int /*<<< orphan*/  flags; int /*<<< orphan*/  data; int /*<<< orphan*/  address_hi; int /*<<< orphan*/  address_lo; } ;
struct TYPE_9__ {unsigned int pin; scalar_t__ irqchip; } ;
struct kvm_kernel_irq_routing_entry {int (* set ) (struct kvm_kernel_irq_routing_entry*,struct kvm*,int,int,int) ;TYPE_4__ msi; TYPE_2__ irqchip; } ;
struct TYPE_13__ {unsigned int pin; scalar_t__ irqchip; } ;
struct TYPE_10__ {int /*<<< orphan*/  devid; int /*<<< orphan*/  data; int /*<<< orphan*/  address_hi; int /*<<< orphan*/  address_lo; } ;
struct TYPE_14__ {TYPE_6__ irqchip; TYPE_3__ msi; } ;
struct kvm_irq_routing_entry {int type; int gsi; TYPE_7__ u; int /*<<< orphan*/  flags; } ;
struct TYPE_12__ {struct vgic_dist vgic; } ;
struct kvm {TYPE_5__ arch; int /*<<< orphan*/  online_vcpus; } ;
typedef  scalar_t__ gpa_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int KVM_IRQCHIP_NUM_PINS ; 
#define  KVM_IRQ_ROUTING_IRQCHIP 129 
#define  KVM_IRQ_ROUTING_MSI 128 
 scalar_t__ KVM_NR_IRQCHIPS ; 
 scalar_t__ KVM_VGIC_V3_DIST_SIZE ; 
 size_t KVM_VGIC_V3_REDIST_SIZE ; 
 scalar_t__ VGIC_CONFIG_EDGE ; 
 scalar_t__ VGIC_CONFIG_LEVEL ; 
 scalar_t__ VGIC_MIN_LPI ; 
 unsigned int VGIC_NR_PRIVATE_IRQS ; 
 size_t atomic_read (int /*<<< orphan*/ *) ; 
 int hweight8 (scalar_t__) ; 
 struct kvm_irq_routing_entry* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct kvm_irq_routing_entry*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 int kvm_set_irq_routing (struct kvm*,struct kvm_irq_routing_entry*,int,int /*<<< orphan*/ ) ; 
 int kvm_set_msi (struct kvm_kernel_irq_routing_entry*,struct kvm*,int,int,int) ; 
 int kvm_vgic_inject_irq (struct kvm*,int /*<<< orphan*/ ,unsigned int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  vgic_has_its (struct kvm*) ; 
 scalar_t__ vgic_irq_is_sgi (scalar_t__) ; 
 int vgic_its_inject_msi (struct kvm*,struct kvm_msi*) ; 
 int /*<<< orphan*/  vgic_valid_spi (struct kvm*,unsigned int) ; 

__attribute__((used)) static inline bool irq_is_pending(struct vgic_irq *irq)
{
	if (irq->config == VGIC_CONFIG_EDGE)
		return irq->pending_latch;
	else
		return irq->pending_latch || irq->line_level;
}

__attribute__((used)) static inline bool vgic_irq_is_mapped_level(struct vgic_irq *irq)
{
	return irq->config == VGIC_CONFIG_LEVEL && irq->hw;
}

__attribute__((used)) static inline int vgic_irq_get_lr_count(struct vgic_irq *irq)
{
	/* Account for the active state as an interrupt */
	if (vgic_irq_is_sgi(irq->intid) && irq->source)
		return hweight8(irq->source) + irq->active;

	return irq_is_pending(irq) || irq->active;
}

__attribute__((used)) static inline bool vgic_irq_is_multi_sgi(struct vgic_irq *irq)
{
	return vgic_irq_get_lr_count(irq) > 1;
}

__attribute__((used)) static inline void vgic_get_irq_kref(struct vgic_irq *irq)
{
	if (irq->intid < VGIC_MIN_LPI)
		return;

	kref_get(&irq->refcount);
}

__attribute__((used)) static inline int vgic_v3_max_apr_idx(struct kvm_vcpu *vcpu)
{
	struct vgic_cpu *cpu_if = &vcpu->arch.vgic_cpu;

	/*
	 * num_pri_bits are initialized with HW supported values.
	 * We can rely safely on num_pri_bits even if VM has not
	 * restored ICC_CTLR_EL1 before restoring APnR registers.
	 */
	switch (cpu_if->num_pri_bits) {
	case 7: return 3;
	case 6: return 1;
	default: return 0;
	}
}

__attribute__((used)) static inline bool
vgic_v3_redist_region_full(struct vgic_redist_region *region)
{
	if (!region->count)
		return false;

	return (region->free_index >= region->count);
}

__attribute__((used)) static inline size_t
vgic_v3_rd_region_size(struct kvm *kvm, struct vgic_redist_region *rdreg)
{
	if (!rdreg->count)
		return atomic_read(&kvm->online_vcpus) * KVM_VGIC_V3_REDIST_SIZE;
	else
		return rdreg->count * KVM_VGIC_V3_REDIST_SIZE;
}

__attribute__((used)) static inline bool vgic_dist_overlap(struct kvm *kvm, gpa_t base, size_t size)
{
	struct vgic_dist *d = &kvm->arch.vgic;

	return (base + size > d->vgic_dist_base) &&
		(base < d->vgic_dist_base + KVM_VGIC_V3_DIST_SIZE);
}

__attribute__((used)) static int vgic_irqfd_set_irq(struct kvm_kernel_irq_routing_entry *e,
			struct kvm *kvm, int irq_source_id,
			int level, bool line_status)
{
	unsigned int spi_id = e->irqchip.pin + VGIC_NR_PRIVATE_IRQS;

	if (!vgic_valid_spi(kvm, spi_id))
		return -EINVAL;
	return kvm_vgic_inject_irq(kvm, 0, spi_id, level, NULL);
}

int kvm_set_routing_entry(struct kvm *kvm,
			  struct kvm_kernel_irq_routing_entry *e,
			  const struct kvm_irq_routing_entry *ue)
{
	int r = -EINVAL;

	switch (ue->type) {
	case KVM_IRQ_ROUTING_IRQCHIP:
		e->set = vgic_irqfd_set_irq;
		e->irqchip.irqchip = ue->u.irqchip.irqchip;
		e->irqchip.pin = ue->u.irqchip.pin;
		if ((e->irqchip.pin >= KVM_IRQCHIP_NUM_PINS) ||
		    (e->irqchip.irqchip >= KVM_NR_IRQCHIPS))
			goto out;
		break;
	case KVM_IRQ_ROUTING_MSI:
		e->set = kvm_set_msi;
		e->msi.address_lo = ue->u.msi.address_lo;
		e->msi.address_hi = ue->u.msi.address_hi;
		e->msi.data = ue->u.msi.data;
		e->msi.flags = ue->flags;
		e->msi.devid = ue->u.msi.devid;
		break;
	default:
		goto out;
	}
	r = 0;
out:
	return r;
}

int kvm_set_msi(struct kvm_kernel_irq_routing_entry *e,
		struct kvm *kvm, int irq_source_id,
		int level, bool line_status)
{
	struct kvm_msi msi;

	msi.address_lo = e->msi.address_lo;
	msi.address_hi = e->msi.address_hi;
	msi.data = e->msi.data;
	msi.flags = e->msi.flags;
	msi.devid = e->msi.devid;

	if (!vgic_has_its(kvm))
		return -ENODEV;

	if (!level)
		return -1;

	return vgic_its_inject_msi(kvm, &msi);
}

int kvm_vgic_setup_default_irq_routing(struct kvm *kvm)
{
	struct kvm_irq_routing_entry *entries;
	struct vgic_dist *dist = &kvm->arch.vgic;
	u32 nr = dist->nr_spis;
	int i, ret;

	entries = kcalloc(nr, sizeof(*entries), GFP_KERNEL);
	if (!entries)
		return -ENOMEM;

	for (i = 0; i < nr; i++) {
		entries[i].gsi = i;
		entries[i].type = KVM_IRQ_ROUTING_IRQCHIP;
		entries[i].u.irqchip.irqchip = 0;
		entries[i].u.irqchip.pin = i;
	}
	ret = kvm_set_irq_routing(kvm, entries, nr, 0);
	kfree(entries);
	return ret;
}

