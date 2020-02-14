#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint32_t ;
struct TYPE_6__ {scalar_t__ sdma_vm_addr; } ;
struct queue {TYPE_3__ properties; } ;
struct qcm_process_device {int sh_mem_config; int sh_mem_bases; scalar_t__ sh_mem_ape1_base; scalar_t__ sh_mem_ape1_limit; } ;
struct kfd_process_device {int lds_base; int scratch_base; } ;
struct device_queue_manager_asic_ops {int (* update_qpd ) (struct device_queue_manager*,struct qcm_process_device*) ;void (* init_sdma_vm ) (struct device_queue_manager*,struct queue*,struct qcm_process_device*) ;} ;
struct device_queue_manager {TYPE_2__* dev; int /*<<< orphan*/  lock_hidden; int /*<<< orphan*/  saved_flags; } ;
struct TYPE_5__ {TYPE_1__* device_info; } ;
struct TYPE_4__ {int /*<<< orphan*/  needs_iommu_device; } ;

/* Variables and functions */
 int SH_MEM_ALIGNMENT_MODE_UNALIGNED ; 
 int SH_MEM_BASES__SHARED_BASE__SHIFT ; 
 int SH_MEM_CONFIG__ALIGNMENT_MODE__SHIFT ; 
 int SH_MEM_CONFIG__RETRY_DISABLE__SHIFT ; 
static  void init_sdma_vm_v9 (struct device_queue_manager*,struct queue*,struct qcm_process_device*) ; 
 int /*<<< orphan*/  memalloc_nofs_restore (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memalloc_nofs_save () ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ noretry ; 
 int /*<<< orphan*/  pr_debug (char*,int) ; 
 struct kfd_process_device* qpd_to_pdd (struct qcm_process_device*) ; 
static  int update_qpd_v9 (struct device_queue_manager*,struct qcm_process_device*) ; 

__attribute__((used)) static inline void kfd_debugfs_init(void) {}

__attribute__((used)) static inline void kfd_debugfs_fini(void) {}

__attribute__((used)) static inline unsigned int get_sh_mem_bases_32(struct kfd_process_device *pdd)
{
	return (pdd->lds_base >> 16) & 0xFF;
}

__attribute__((used)) static inline unsigned int
get_sh_mem_bases_nybble_64(struct kfd_process_device *pdd)
{
	return (pdd->lds_base >> 60) & 0x0E;
}

__attribute__((used)) static inline void dqm_lock(struct device_queue_manager *dqm)
{
	mutex_lock(&dqm->lock_hidden);
	dqm->saved_flags = memalloc_nofs_save();
}

__attribute__((used)) static inline void dqm_unlock(struct device_queue_manager *dqm)
{
	memalloc_nofs_restore(dqm->saved_flags);
	mutex_unlock(&dqm->lock_hidden);
}

void device_queue_manager_init_v9(
	struct device_queue_manager_asic_ops *asic_ops)
{
	asic_ops->update_qpd = update_qpd_v9;
	asic_ops->init_sdma_vm = init_sdma_vm_v9;
}

__attribute__((used)) static uint32_t compute_sh_mem_bases_64bit(struct kfd_process_device *pdd)
{
	uint32_t shared_base = pdd->lds_base >> 48;
	uint32_t private_base = pdd->scratch_base >> 48;

	return (shared_base << SH_MEM_BASES__SHARED_BASE__SHIFT) |
		private_base;
}

__attribute__((used)) static int update_qpd_v9(struct device_queue_manager *dqm,
			 struct qcm_process_device *qpd)
{
	struct kfd_process_device *pdd;

	pdd = qpd_to_pdd(qpd);

	/* check if sh_mem_config register already configured */
	if (qpd->sh_mem_config == 0) {
		qpd->sh_mem_config =
				SH_MEM_ALIGNMENT_MODE_UNALIGNED <<
					SH_MEM_CONFIG__ALIGNMENT_MODE__SHIFT;
		if (noretry &&
		    !dqm->dev->device_info->needs_iommu_device)
			qpd->sh_mem_config |=
				1 << SH_MEM_CONFIG__RETRY_DISABLE__SHIFT;

		qpd->sh_mem_ape1_limit = 0;
		qpd->sh_mem_ape1_base = 0;
	}

	qpd->sh_mem_bases = compute_sh_mem_bases_64bit(pdd);

	pr_debug("sh_mem_bases 0x%X\n", qpd->sh_mem_bases);

	return 0;
}

__attribute__((used)) static void init_sdma_vm_v9(struct device_queue_manager *dqm, struct queue *q,
			    struct qcm_process_device *qpd)
{
	/* Not needed on SDMAv4 any more */
	q->properties.sdma_vm_addr = 0;
}

