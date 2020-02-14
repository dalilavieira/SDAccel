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
struct property {int dummy; } ;
struct pci_dev {int dummy; } ;
struct mm_struct {int dummy; } ;
struct device_node {int dummy; } ;
struct cxl_calls {scalar_t__ owner; int /*<<< orphan*/  (* cxl_slbia ) (struct mm_struct*) ;} ;
struct cxl_afu {int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int /*<<< orphan*/  parent; } ;
struct cxl {TYPE_1__ dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CPU_FTR_HVMODE ; 
 int EBUSY ; 
 int /*<<< orphan*/  RCU_INIT_POINTER (struct cxl_calls*,int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_has_feature (int /*<<< orphan*/ ) ; 
 struct cxl_calls* cxl_calls ; 
 scalar_t__ cxl_ctx_in_use () ; 
 int /*<<< orphan*/ * get_device (int /*<<< orphan*/ *) ; 
 int of_update_property (struct device_node*,struct property*) ; 
 int /*<<< orphan*/  pci_channel_offline (struct pci_dev*) ; 
 int /*<<< orphan*/  put_device (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rcu_assign_pointer (struct cxl_calls*,struct cxl_calls*) ; 
 int /*<<< orphan*/  stub1 (struct mm_struct*) ; 
 int /*<<< orphan*/  synchronize_rcu () ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool cxl_adapter_link_ok(struct cxl *cxl, struct cxl_afu *afu)
{
	struct pci_dev *pdev;

	if (cpu_has_feature(CPU_FTR_HVMODE)) {
		pdev = to_pci_dev(cxl->dev.parent);
		return !pci_channel_offline(pdev);
	}
	return true;
}

__attribute__((used)) static inline struct cxl_calls *cxl_calls_get(void)
{
	return cxl_calls;
}

__attribute__((used)) static inline void cxl_calls_put(struct cxl_calls *calls) { }

struct cxl_afu *cxl_afu_get(struct cxl_afu *afu)
{
	return (get_device(&afu->dev) == NULL) ? NULL : afu;
}

void cxl_afu_put(struct cxl_afu *afu)
{
	put_device(&afu->dev);
}

void cxl_slbia(struct mm_struct *mm)
{
	struct cxl_calls *calls;

	calls = cxl_calls_get();
	if (!calls)
		return;

	if (cxl_ctx_in_use())
	    calls->cxl_slbia(mm);

	cxl_calls_put(calls);
}

int register_cxl_calls(struct cxl_calls *calls)
{
	if (cxl_calls)
		return -EBUSY;

	rcu_assign_pointer(cxl_calls, calls);
	return 0;
}

void unregister_cxl_calls(struct cxl_calls *calls)
{
	BUG_ON(cxl_calls->owner != calls->owner);
	RCU_INIT_POINTER(cxl_calls, NULL);
	synchronize_rcu();
}

int cxl_update_properties(struct device_node *dn,
			  struct property *new_prop)
{
	return of_update_property(dn, new_prop);
}

