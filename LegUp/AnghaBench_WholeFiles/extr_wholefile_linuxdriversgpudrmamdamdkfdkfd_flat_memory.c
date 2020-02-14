#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  void* uint8_t ;
struct TYPE_9__ {int /*<<< orphan*/  ib_base; int /*<<< orphan*/  cwsr_base; } ;
struct kfd_process_device {void* scratch_limit; void* scratch_base; void* gpuvm_limit; void* gpuvm_base; void* lds_limit; void* lds_base; TYPE_5__* dev; TYPE_4__ qpd; } ;
struct kfd_process {scalar_t__ is_32bit_user_mode; } ;
struct kfd_dev {TYPE_3__* device_info; } ;
struct TYPE_7__ {void* gpuvm_size; } ;
struct TYPE_10__ {void* id; TYPE_2__ shared_resources; TYPE_1__* device_info; } ;
struct TYPE_8__ {int asic_family; int /*<<< orphan*/  needs_iommu_device; } ;
struct TYPE_6__ {int /*<<< orphan*/  needs_iommu_device; } ;

/* Variables and functions */
#define  CHIP_CARRIZO 136 
#define  CHIP_FIJI 135 
#define  CHIP_HAWAII 134 
#define  CHIP_KAVERI 133 
#define  CHIP_POLARIS10 132 
#define  CHIP_POLARIS11 131 
#define  CHIP_RAVEN 130 
#define  CHIP_TONGA 129 
#define  CHIP_VEGA10 128 
 int EINVAL ; 
 int ENOMEM ; 
 void* MAKE_GPUVM_APP_BASE_VI (void*) ; 
 void* MAKE_GPUVM_APP_LIMIT (void*,void*) ; 
 void* MAKE_LDS_APP_BASE_V9 () ; 
 void* MAKE_LDS_APP_BASE_VI () ; 
 void* MAKE_LDS_APP_LIMIT (void*) ; 
 void* MAKE_SCRATCH_APP_BASE_V9 () ; 
 void* MAKE_SCRATCH_APP_BASE_VI () ; 
 void* MAKE_SCRATCH_APP_LIMIT (void*) ; 
 int /*<<< orphan*/  SVM_CWSR_BASE ; 
 int /*<<< orphan*/  SVM_IB_BASE ; 
 void* SVM_USER_BASE ; 
 int /*<<< orphan*/  WARN (int,char*,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,void*) ; 
 struct kfd_process_device* kfd_create_process_device_data (struct kfd_dev*,struct kfd_process*) ; 
 int /*<<< orphan*/  kfd_device ; 
 scalar_t__ kfd_topology_enum_kfd_devices (void*,struct kfd_dev**) ; 
 int /*<<< orphan*/  pr_err (char*) ; 

__attribute__((used)) static inline void kfd_debugfs_init(void) {}

__attribute__((used)) static inline void kfd_debugfs_fini(void) {}

__attribute__((used)) static void kfd_init_apertures_vi(struct kfd_process_device *pdd, uint8_t id)
{
	/*
	 * node id couldn't be 0 - the three MSB bits of
	 * aperture shoudn't be 0
	 */
	pdd->lds_base = MAKE_LDS_APP_BASE_VI();
	pdd->lds_limit = MAKE_LDS_APP_LIMIT(pdd->lds_base);

	if (!pdd->dev->device_info->needs_iommu_device) {
		/* dGPUs: SVM aperture starting at 0
		 * with small reserved space for kernel.
		 * Set them to CANONICAL addresses.
		 */
		pdd->gpuvm_base = SVM_USER_BASE;
		pdd->gpuvm_limit =
			pdd->dev->shared_resources.gpuvm_size - 1;
	} else {
		/* set them to non CANONICAL addresses, and no SVM is
		 * allocated.
		 */
		pdd->gpuvm_base = MAKE_GPUVM_APP_BASE_VI(id + 1);
		pdd->gpuvm_limit = MAKE_GPUVM_APP_LIMIT(pdd->gpuvm_base,
				pdd->dev->shared_resources.gpuvm_size);
	}

	pdd->scratch_base = MAKE_SCRATCH_APP_BASE_VI();
	pdd->scratch_limit = MAKE_SCRATCH_APP_LIMIT(pdd->scratch_base);
}

__attribute__((used)) static void kfd_init_apertures_v9(struct kfd_process_device *pdd, uint8_t id)
{
	pdd->lds_base = MAKE_LDS_APP_BASE_V9();
	pdd->lds_limit = MAKE_LDS_APP_LIMIT(pdd->lds_base);

	/* Raven needs SVM to support graphic handle, etc. Leave the small
	 * reserved space before SVM on Raven as well, even though we don't
	 * have to.
	 * Set gpuvm_base and gpuvm_limit to CANONICAL addresses so that they
	 * are used in Thunk to reserve SVM.
	 */
	pdd->gpuvm_base = SVM_USER_BASE;
	pdd->gpuvm_limit =
		pdd->dev->shared_resources.gpuvm_size - 1;

	pdd->scratch_base = MAKE_SCRATCH_APP_BASE_V9();
	pdd->scratch_limit = MAKE_SCRATCH_APP_LIMIT(pdd->scratch_base);
}

int kfd_init_apertures(struct kfd_process *process)
{
	uint8_t id  = 0;
	struct kfd_dev *dev;
	struct kfd_process_device *pdd;

	/*Iterating over all devices*/
	while (kfd_topology_enum_kfd_devices(id, &dev) == 0) {
		if (!dev) {
			id++; /* Skip non GPU devices */
			continue;
		}

		pdd = kfd_create_process_device_data(dev, process);
		if (!pdd) {
			pr_err("Failed to create process device data\n");
			return -ENOMEM;
		}
		/*
		 * For 64 bit process apertures will be statically reserved in
		 * the x86_64 non canonical process address space
		 * amdkfd doesn't currently support apertures for 32 bit process
		 */
		if (process->is_32bit_user_mode) {
			pdd->lds_base = pdd->lds_limit = 0;
			pdd->gpuvm_base = pdd->gpuvm_limit = 0;
			pdd->scratch_base = pdd->scratch_limit = 0;
		} else {
			switch (dev->device_info->asic_family) {
			case CHIP_KAVERI:
			case CHIP_HAWAII:
			case CHIP_CARRIZO:
			case CHIP_TONGA:
			case CHIP_FIJI:
			case CHIP_POLARIS10:
			case CHIP_POLARIS11:
				kfd_init_apertures_vi(pdd, id);
				break;
			case CHIP_VEGA10:
			case CHIP_RAVEN:
				kfd_init_apertures_v9(pdd, id);
				break;
			default:
				WARN(1, "Unexpected ASIC family %u",
				     dev->device_info->asic_family);
				return -EINVAL;
			}

			if (!dev->device_info->needs_iommu_device) {
				/* dGPUs: the reserved space for kernel
				 * before SVM
				 */
				pdd->qpd.cwsr_base = SVM_CWSR_BASE;
				pdd->qpd.ib_base = SVM_IB_BASE;
			}
		}

		dev_dbg(kfd_device, "node id %u\n", id);
		dev_dbg(kfd_device, "gpu id %u\n", pdd->dev->id);
		dev_dbg(kfd_device, "lds_base %llX\n", pdd->lds_base);
		dev_dbg(kfd_device, "lds_limit %llX\n", pdd->lds_limit);
		dev_dbg(kfd_device, "gpuvm_base %llX\n", pdd->gpuvm_base);
		dev_dbg(kfd_device, "gpuvm_limit %llX\n", pdd->gpuvm_limit);
		dev_dbg(kfd_device, "scratch_base %llX\n", pdd->scratch_base);
		dev_dbg(kfd_device, "scratch_limit %llX\n", pdd->scratch_limit);

		id++;
	}

	return 0;
}

