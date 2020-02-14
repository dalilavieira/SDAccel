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
struct mqd_manager {TYPE_3__* dev; } ;
struct kfd_dev {TYPE_1__* device_info; } ;
struct kfd_cu_info {int cu_active_number; int num_shader_engines; int /*<<< orphan*/ ** cu_bitmap; } ;
typedef  enum KFD_MQD_TYPE { ____Placeholder_KFD_MQD_TYPE } KFD_MQD_TYPE ;
struct TYPE_6__ {int /*<<< orphan*/  kgd; TYPE_2__* kfd2kgd; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* get_cu_info ) (int /*<<< orphan*/ ,struct kfd_cu_info*) ;} ;
struct TYPE_4__ {int asic_family; } ;

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
 int /*<<< orphan*/  WARN (int,char*,int) ; 
 scalar_t__ hweight32 (int /*<<< orphan*/ ) ; 
 struct mqd_manager* mqd_manager_init_cik (int,struct kfd_dev*) ; 
 struct mqd_manager* mqd_manager_init_cik_hawaii (int,struct kfd_dev*) ; 
 struct mqd_manager* mqd_manager_init_v9 (int,struct kfd_dev*) ; 
 struct mqd_manager* mqd_manager_init_vi (int,struct kfd_dev*) ; 
 struct mqd_manager* mqd_manager_init_vi_tonga (int,struct kfd_dev*) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,struct kfd_cu_info*) ; 

__attribute__((used)) static inline void kfd_debugfs_init(void) {}

__attribute__((used)) static inline void kfd_debugfs_fini(void) {}

struct mqd_manager *mqd_manager_init(enum KFD_MQD_TYPE type,
					struct kfd_dev *dev)
{
	switch (dev->device_info->asic_family) {
	case CHIP_KAVERI:
		return mqd_manager_init_cik(type, dev);
	case CHIP_HAWAII:
		return mqd_manager_init_cik_hawaii(type, dev);
	case CHIP_CARRIZO:
		return mqd_manager_init_vi(type, dev);
	case CHIP_TONGA:
	case CHIP_FIJI:
	case CHIP_POLARIS10:
	case CHIP_POLARIS11:
		return mqd_manager_init_vi_tonga(type, dev);
	case CHIP_VEGA10:
	case CHIP_RAVEN:
		return mqd_manager_init_v9(type, dev);
	default:
		WARN(1, "Unexpected ASIC family %u",
		     dev->device_info->asic_family);
	}

	return NULL;
}

void mqd_symmetrically_map_cu_mask(struct mqd_manager *mm,
		const uint32_t *cu_mask, uint32_t cu_mask_count,
		uint32_t *se_mask)
{
	struct kfd_cu_info cu_info;
	uint32_t cu_per_sh[4] = {0};
	int i, se, cu = 0;

	mm->dev->kfd2kgd->get_cu_info(mm->dev->kgd, &cu_info);

	if (cu_mask_count > cu_info.cu_active_number)
		cu_mask_count = cu_info.cu_active_number;

	for (se = 0; se < cu_info.num_shader_engines; se++)
		for (i = 0; i < 4; i++)
			cu_per_sh[se] += hweight32(cu_info.cu_bitmap[se][i]);

	/* Symmetrically map cu_mask to all SEs:
	 * cu_mask[0] bit0 -> se_mask[0] bit0;
	 * cu_mask[0] bit1 -> se_mask[1] bit0;
	 * ... (if # SE is 4)
	 * cu_mask[0] bit4 -> se_mask[0] bit1;
	 * ...
	 */
	se = 0;
	for (i = 0; i < cu_mask_count; i++) {
		if (cu_mask[i / 32] & (1 << (i % 32)))
			se_mask[se] |= 1 << cu;

		do {
			se++;
			if (se == cu_info.num_shader_engines) {
				se = 0;
				cu++;
			}
		} while (cu >= cu_per_sh[se] && cu < 32);
	}
}

