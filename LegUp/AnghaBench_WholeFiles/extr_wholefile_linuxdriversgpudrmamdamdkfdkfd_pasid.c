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
struct kfd_dev {TYPE_1__* kfd2kgd; } ;
struct TYPE_2__ {int (* alloc_pasid ) (unsigned int) ;int /*<<< orphan*/  (* free_pasid ) (unsigned int) ;} ;

/* Variables and functions */
 TYPE_1__* kfd2kgd ; 
 scalar_t__ kfd_topology_enum_kfd_devices (unsigned int,struct kfd_dev**) ; 
 unsigned int pasid_bits ; 
 int stub1 (unsigned int) ; 
 int /*<<< orphan*/  stub2 (unsigned int) ; 

__attribute__((used)) static inline void kfd_debugfs_init(void) {}

__attribute__((used)) static inline void kfd_debugfs_fini(void) {}

bool kfd_set_pasid_limit(unsigned int new_limit)
{
	if (new_limit < 2)
		return false;

	if (new_limit < (1U << pasid_bits)) {
		if (kfd2kgd)
			/* We've already allocated user PASIDs, too late to
			 * change the limit
			 */
			return false;

		while (new_limit < (1U << pasid_bits))
			pasid_bits--;
	}

	return true;
}

unsigned int kfd_get_pasid_limit(void)
{
	return 1U << pasid_bits;
}

unsigned int kfd_pasid_alloc(void)
{
	int r;

	/* Find the first best KFD device for calling KGD */
	if (!kfd2kgd) {
		struct kfd_dev *dev = NULL;
		unsigned int i = 0;

		while ((kfd_topology_enum_kfd_devices(i, &dev)) == 0) {
			if (dev && dev->kfd2kgd) {
				kfd2kgd = dev->kfd2kgd;
				break;
			}
			i++;
		}

		if (!kfd2kgd)
			return false;
	}

	r = kfd2kgd->alloc_pasid(pasid_bits);

	return r > 0 ? r : 0;
}

void kfd_pasid_free(unsigned int pasid)
{
	if (kfd2kgd)
		kfd2kgd->free_pasid(pasid);
}

