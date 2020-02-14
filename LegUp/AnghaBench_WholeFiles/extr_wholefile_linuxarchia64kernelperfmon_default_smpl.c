#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_8__ ;
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;
typedef  struct TYPE_12__   TYPE_11__ ;

/* Type definitions */
struct task_struct {int /*<<< orphan*/  pid; } ;
struct pt_regs {int cr_iip; int cr_ipsr; } ;
struct TYPE_13__ {int reset_ovfl_pmds; scalar_t__ mask_monitoring; } ;
struct TYPE_16__ {TYPE_1__ bits; } ;
typedef  TYPE_4__ pfm_ovfl_ctrl_t ;
struct TYPE_15__ {int notify_user; int block_task; int mask_monitoring; int reset_ovfl_pmds; } ;
struct TYPE_14__ {TYPE_3__ bits; } ;
struct TYPE_17__ {unsigned char ovfl_pmd; unsigned char ovfl_notify; unsigned long* smpl_pmds_values; TYPE_2__ ovfl_ctrl; int /*<<< orphan*/  active_set; int /*<<< orphan*/  pmd_last_reset; int /*<<< orphan*/ * smpl_pmds; } ;
typedef  TYPE_5__ pfm_ovfl_arg_t ;
struct TYPE_18__ {int hdr_buf_size; int hdr_cur_offs; unsigned long hdr_overflows; unsigned long hdr_count; int /*<<< orphan*/  hdr_version; } ;
typedef  TYPE_6__ pfm_default_smpl_hdr_t ;
struct TYPE_19__ {unsigned char ovfl_pmd; int ip; unsigned long tstamp; int /*<<< orphan*/  tgid; int /*<<< orphan*/  set; int /*<<< orphan*/  cpu; int /*<<< orphan*/  last_reset_val; int /*<<< orphan*/  pid; } ;
typedef  TYPE_7__ pfm_default_smpl_entry_t ;
struct TYPE_20__ {scalar_t__ buf_size; } ;
typedef  TYPE_8__ pfm_default_smpl_arg_t ;
struct TYPE_12__ {int /*<<< orphan*/  tgid; int /*<<< orphan*/  pid; } ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (char*) ; 
 int /*<<< orphan*/  DPRINT_ovfl (char*) ; 
 int EINVAL ; 
 int PFM_DEFAULT_MAX_ENTRY_SIZE ; 
 scalar_t__ PFM_DEFAULT_SMPL_MIN_BUF_SIZE ; 
 int /*<<< orphan*/  PFM_DEFAULT_SMPL_VERSION ; 
 TYPE_11__* current ; 
 unsigned int hweight64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  prefetch (unsigned long*) ; 
 int /*<<< orphan*/  smp_processor_id () ; 
 int /*<<< orphan*/  task_pid_nr (struct task_struct*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int
default_validate(struct task_struct *task, unsigned int flags, int cpu, void *data)
{
	pfm_default_smpl_arg_t *arg = (pfm_default_smpl_arg_t*)data;
	int ret = 0;

	if (data == NULL) {
		DPRINT(("[%d] no argument passed\n", task_pid_nr(task)));
		return -EINVAL;
	}

	DPRINT(("[%d] validate flags=0x%x CPU%d\n", task_pid_nr(task), flags, cpu));

	/*
	 * must hold at least the buffer header + one minimally sized entry
	 */
	if (arg->buf_size < PFM_DEFAULT_SMPL_MIN_BUF_SIZE) return -EINVAL;

	DPRINT(("buf_size=%lu\n", arg->buf_size));

	return ret;
}

__attribute__((used)) static int
default_get_size(struct task_struct *task, unsigned int flags, int cpu, void *data, unsigned long *size)
{
	pfm_default_smpl_arg_t *arg = (pfm_default_smpl_arg_t *)data;

	/*
	 * size has been validated in default_validate
	 */
	*size = arg->buf_size;

	return 0;
}

__attribute__((used)) static int
default_init(struct task_struct *task, void *buf, unsigned int flags, int cpu, void *data)
{
	pfm_default_smpl_hdr_t *hdr;
	pfm_default_smpl_arg_t *arg = (pfm_default_smpl_arg_t *)data;

	hdr = (pfm_default_smpl_hdr_t *)buf;

	hdr->hdr_version      = PFM_DEFAULT_SMPL_VERSION;
	hdr->hdr_buf_size     = arg->buf_size;
	hdr->hdr_cur_offs     = sizeof(*hdr);
	hdr->hdr_overflows    = 0UL;
	hdr->hdr_count        = 0UL;

	DPRINT(("[%d] buffer=%p buf_size=%lu hdr_size=%lu hdr_version=%u cur_offs=%lu\n",
		task_pid_nr(task),
		buf,
		hdr->hdr_buf_size,
		sizeof(*hdr),
		hdr->hdr_version,
		hdr->hdr_cur_offs));

	return 0;
}

__attribute__((used)) static int
default_handler(struct task_struct *task, void *buf, pfm_ovfl_arg_t *arg, struct pt_regs *regs, unsigned long stamp)
{
	pfm_default_smpl_hdr_t *hdr;
	pfm_default_smpl_entry_t *ent;
	void *cur, *last;
	unsigned long *e, entry_size;
	unsigned int npmds, i;
	unsigned char ovfl_pmd;
	unsigned char ovfl_notify;

	if (unlikely(buf == NULL || arg == NULL|| regs == NULL || task == NULL)) {
		DPRINT(("[%d] invalid arguments buf=%p arg=%p\n", task->pid, buf, arg));
		return -EINVAL;
	}

	hdr         = (pfm_default_smpl_hdr_t *)buf;
	cur         = buf+hdr->hdr_cur_offs;
	last        = buf+hdr->hdr_buf_size;
	ovfl_pmd    = arg->ovfl_pmd;
	ovfl_notify = arg->ovfl_notify;

	/*
	 * precheck for sanity
	 */
	if ((last - cur) < PFM_DEFAULT_MAX_ENTRY_SIZE) goto full;

	npmds = hweight64(arg->smpl_pmds[0]);

	ent = (pfm_default_smpl_entry_t *)cur;

	prefetch(arg->smpl_pmds_values);

	entry_size = sizeof(*ent) + (npmds << 3);

	/* position for first pmd */
	e = (unsigned long *)(ent+1);

	hdr->hdr_count++;

	DPRINT_ovfl(("[%d] count=%lu cur=%p last=%p free_bytes=%lu ovfl_pmd=%d ovfl_notify=%d npmds=%u\n",
			task->pid,
			hdr->hdr_count,
			cur, last,
			last-cur,
			ovfl_pmd,
			ovfl_notify, npmds));

	/*
	 * current = task running at the time of the overflow.
	 *
	 * per-task mode:
	 * 	- this is usually the task being monitored.
	 * 	  Under certain conditions, it might be a different task
	 *
	 * system-wide:
	 * 	- this is not necessarily the task controlling the session
	 */
	ent->pid            = current->pid;
	ent->ovfl_pmd  	    = ovfl_pmd;
	ent->last_reset_val = arg->pmd_last_reset; //pmd[0].reg_last_reset_val;

	/*
	 * where did the fault happen (includes slot number)
	 */
	ent->ip = regs->cr_iip | ((regs->cr_ipsr >> 41) & 0x3);

	ent->tstamp    = stamp;
	ent->cpu       = smp_processor_id();
	ent->set       = arg->active_set;
	ent->tgid      = current->tgid;

	/*
	 * selectively store PMDs in increasing index number
	 */
	if (npmds) {
		unsigned long *val = arg->smpl_pmds_values;
		for(i=0; i < npmds; i++) {
			*e++ = *val++;
		}
	}

	/*
	 * update position for next entry
	 */
	hdr->hdr_cur_offs += entry_size;
	cur               += entry_size;

	/*
	 * post check to avoid losing the last sample
	 */
	if ((last - cur) < PFM_DEFAULT_MAX_ENTRY_SIZE) goto full;

	/*
	 * keep same ovfl_pmds, ovfl_notify
	 */
	arg->ovfl_ctrl.bits.notify_user     = 0;
	arg->ovfl_ctrl.bits.block_task      = 0;
	arg->ovfl_ctrl.bits.mask_monitoring = 0;
	arg->ovfl_ctrl.bits.reset_ovfl_pmds = 1; /* reset before returning from interrupt handler */

	return 0;
full:
	DPRINT_ovfl(("sampling buffer full free=%lu, count=%lu, ovfl_notify=%d\n", last-cur, hdr->hdr_count, ovfl_notify));

	/*
	 * increment number of buffer overflow.
	 * important to detect duplicate set of samples.
	 */
	hdr->hdr_overflows++;

	/*
	 * if no notification requested, then we saturate the buffer
	 */
	if (ovfl_notify == 0) {
		arg->ovfl_ctrl.bits.notify_user     = 0;
		arg->ovfl_ctrl.bits.block_task      = 0;
		arg->ovfl_ctrl.bits.mask_monitoring = 1;
		arg->ovfl_ctrl.bits.reset_ovfl_pmds = 0;
	} else {
		arg->ovfl_ctrl.bits.notify_user     = 1;
		arg->ovfl_ctrl.bits.block_task      = 1; /* ignored for non-blocking context */
		arg->ovfl_ctrl.bits.mask_monitoring = 1;
		arg->ovfl_ctrl.bits.reset_ovfl_pmds = 0; /* no reset now */
	}
	return -1; /* we are full, sorry */
}

__attribute__((used)) static int
default_restart(struct task_struct *task, pfm_ovfl_ctrl_t *ctrl, void *buf, struct pt_regs *regs)
{
	pfm_default_smpl_hdr_t *hdr;

	hdr = (pfm_default_smpl_hdr_t *)buf;

	hdr->hdr_count    = 0UL;
	hdr->hdr_cur_offs = sizeof(*hdr);

	ctrl->bits.mask_monitoring = 0;
	ctrl->bits.reset_ovfl_pmds = 1; /* uses long-reset values */

	return 0;
}

__attribute__((used)) static int
default_exit(struct task_struct *task, void *buf, struct pt_regs *regs)
{
	DPRINT(("[%d] exit(%p)\n", task_pid_nr(task), buf));
	return 0;
}

