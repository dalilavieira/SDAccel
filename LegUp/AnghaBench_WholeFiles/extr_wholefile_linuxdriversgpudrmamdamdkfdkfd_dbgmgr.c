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
struct mutex {int dummy; } ;
struct kfd_process_device {int lds_base; } ;
struct kfd_process {scalar_t__ pasid; int /*<<< orphan*/  pqm; } ;
struct kfd_dev {TYPE_1__* dqm; int /*<<< orphan*/  init_complete; } ;
struct kfd_dbgmgr {scalar_t__ pasid; struct kfd_dbgmgr* dbgdev; scalar_t__ (* dbgdev_address_watch ) (struct kfd_dbgmgr*,struct dbg_address_watch_info*) ;scalar_t__ (* dbgdev_wave_control ) (struct kfd_dbgmgr*,struct dbg_wave_control_info*) ;int /*<<< orphan*/  (* dbgdev_unregister ) (struct kfd_dbgmgr*) ;int /*<<< orphan*/  (* dbgdev_register ) (struct kfd_dbgmgr*) ;int /*<<< orphan*/ * pqm; struct kfd_dev* dev; } ;
struct device_queue_manager {int /*<<< orphan*/  lock_hidden; int /*<<< orphan*/  saved_flags; } ;
struct dbg_wave_control_info {TYPE_2__* process; } ;
struct dbg_address_watch_info {TYPE_3__* process; } ;
typedef  enum DBGDEV_TYPE { ____Placeholder_DBGDEV_TYPE } DBGDEV_TYPE ;
struct TYPE_6__ {scalar_t__ pasid; } ;
struct TYPE_5__ {scalar_t__ pasid; } ;
struct TYPE_4__ {scalar_t__ sched_policy; } ;

/* Variables and functions */
 int DBGDEV_TYPE_DIQ ; 
 int DBGDEV_TYPE_NODIQ ; 
 long EBUSY ; 
 long EINVAL ; 
 scalar_t__ KFD_SCHED_POLICY_NO_HWS ; 
 scalar_t__ WARN_ON (int) ; 
 void* kfd_alloc_struct (struct kfd_dbgmgr*) ; 
 int /*<<< orphan*/  kfd_dbgdev_init (struct kfd_dbgmgr*,struct kfd_dev*,int) ; 
 struct mutex kfd_dbgmgr_mutex ; 
 int /*<<< orphan*/  kfree (struct kfd_dbgmgr*) ; 
 int /*<<< orphan*/  memalloc_nofs_restore (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memalloc_nofs_save () ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pr_debug (char*,scalar_t__) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  stub1 (struct kfd_dbgmgr*) ; 
 int /*<<< orphan*/  stub2 (struct kfd_dbgmgr*) ; 
 scalar_t__ stub3 (struct kfd_dbgmgr*,struct dbg_wave_control_info*) ; 
 scalar_t__ stub4 (struct kfd_dbgmgr*,struct dbg_address_watch_info*) ; 

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

struct mutex *kfd_get_dbgmgr_mutex(void)
{
	return &kfd_dbgmgr_mutex;
}

__attribute__((used)) static void kfd_dbgmgr_uninitialize(struct kfd_dbgmgr *pmgr)
{
	kfree(pmgr->dbgdev);

	pmgr->dbgdev = NULL;
	pmgr->pasid = 0;
	pmgr->dev = NULL;
}

void kfd_dbgmgr_destroy(struct kfd_dbgmgr *pmgr)
{
	if (pmgr) {
		kfd_dbgmgr_uninitialize(pmgr);
		kfree(pmgr);
	}
}

bool kfd_dbgmgr_create(struct kfd_dbgmgr **ppmgr, struct kfd_dev *pdev)
{
	enum DBGDEV_TYPE type = DBGDEV_TYPE_DIQ;
	struct kfd_dbgmgr *new_buff;

	if (WARN_ON(!pdev->init_complete))
		return false;

	new_buff = kfd_alloc_struct(new_buff);
	if (!new_buff) {
		pr_err("Failed to allocate dbgmgr instance\n");
		return false;
	}

	new_buff->pasid = 0;
	new_buff->dev = pdev;
	new_buff->dbgdev = kfd_alloc_struct(new_buff->dbgdev);
	if (!new_buff->dbgdev) {
		pr_err("Failed to allocate dbgdev instance\n");
		kfree(new_buff);
		return false;
	}

	/* get actual type of DBGDevice cpsch or not */
	if (pdev->dqm->sched_policy == KFD_SCHED_POLICY_NO_HWS)
		type = DBGDEV_TYPE_NODIQ;

	kfd_dbgdev_init(new_buff->dbgdev, pdev, type);
	*ppmgr = new_buff;

	return true;
}

long kfd_dbgmgr_register(struct kfd_dbgmgr *pmgr, struct kfd_process *p)
{
	if (pmgr->pasid != 0) {
		pr_debug("H/W debugger is already active using pasid %d\n",
				pmgr->pasid);
		return -EBUSY;
	}

	/* remember pasid */
	pmgr->pasid = p->pasid;

	/* provide the pqm for diq generation */
	pmgr->dbgdev->pqm = &p->pqm;

	/* activate the actual registering */
	pmgr->dbgdev->dbgdev_register(pmgr->dbgdev);

	return 0;
}

long kfd_dbgmgr_unregister(struct kfd_dbgmgr *pmgr, struct kfd_process *p)
{
	/* Is the requests coming from the already registered process? */
	if (pmgr->pasid != p->pasid) {
		pr_debug("H/W debugger is not registered by calling pasid %d\n",
				p->pasid);
		return -EINVAL;
	}

	pmgr->dbgdev->dbgdev_unregister(pmgr->dbgdev);

	pmgr->pasid = 0;

	return 0;
}

long kfd_dbgmgr_wave_control(struct kfd_dbgmgr *pmgr,
				struct dbg_wave_control_info *wac_info)
{
	/* Is the requests coming from the already registered process? */
	if (pmgr->pasid != wac_info->process->pasid) {
		pr_debug("H/W debugger support was not registered for requester pasid %d\n",
				wac_info->process->pasid);
		return -EINVAL;
	}

	return (long) pmgr->dbgdev->dbgdev_wave_control(pmgr->dbgdev, wac_info);
}

long kfd_dbgmgr_address_watch(struct kfd_dbgmgr *pmgr,
				struct dbg_address_watch_info *adw_info)
{
	/* Is the requests coming from the already registered process? */
	if (pmgr->pasid != adw_info->process->pasid) {
		pr_debug("H/W debugger support was not registered for requester pasid %d\n",
				adw_info->process->pasid);
		return -EINVAL;
	}

	return (long) pmgr->dbgdev->dbgdev_address_watch(pmgr->dbgdev,
							adw_info);
}

