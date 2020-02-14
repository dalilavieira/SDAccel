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
typedef  scalar_t__ uint64_t ;
struct task_struct {int dummy; } ;
struct dlm_rsb {int /*<<< orphan*/  res_mutex; int /*<<< orphan*/  res_nodeid; int /*<<< orphan*/  res_flags; } ;
struct dlm_recover {scalar_t__ seq; struct dlm_recover* nodes; } ;
struct dlm_ls {scalar_t__ ls_recover_seq; unsigned long long ls_recover_dir_sent_res; int ls_recover_dir_sent_msg; int /*<<< orphan*/  ls_recoverd_active; int /*<<< orphan*/  ls_wait_general; struct task_struct* ls_recoverd_task; int /*<<< orphan*/  ls_in_recovery; int /*<<< orphan*/  ls_flags; int /*<<< orphan*/  ls_recover_lock_wait; int /*<<< orphan*/  ls_recover_lock; struct dlm_recover* ls_recover_args; int /*<<< orphan*/  ls_generation; scalar_t__ ls_recover_locks_in; int /*<<< orphan*/  ls_recv_active; } ;
typedef  enum rsb_flags { ____Placeholder_rsb_flags } rsb_flags ;

/* Variables and functions */
 int /*<<< orphan*/  DLM_RS_DIR ; 
 int /*<<< orphan*/  DLM_RS_DONE ; 
 int /*<<< orphan*/  DLM_RS_LOCKS ; 
 int /*<<< orphan*/  DLM_RS_NODES ; 
 int EINTR ; 
 scalar_t__ IS_ERR (struct task_struct*) ; 
 int LSFL_NODIR ; 
 int LSFL_RECOVER_DOWN ; 
 int LSFL_RECOVER_LOCK ; 
 int LSFL_RECOVER_STOP ; 
 int LSFL_RECOVER_WORK ; 
 int LSFL_RUNNING ; 
 int PTR_ERR (struct task_struct*) ; 
 int /*<<< orphan*/  TASK_INTERRUPTIBLE ; 
 int /*<<< orphan*/  TASK_RUNNING ; 
 int /*<<< orphan*/  __clear_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __set_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  clear_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dlm_adjust_timeouts (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_callback_resume (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_callback_suspend (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_clear_members_gone (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_clear_toss (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_create_root_list (struct dlm_ls*) ; 
 struct dlm_ls* dlm_find_lockspace_local (void*) ; 
 int /*<<< orphan*/  dlm_lsop_recover_done (struct dlm_ls*) ; 
 int dlm_process_requestqueue (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_purge_requestqueue (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_put_lockspace (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_recover_dir_nodeid (struct dlm_ls*) ; 
 int dlm_recover_directory (struct dlm_ls*) ; 
 int dlm_recover_directory_wait (struct dlm_ls*) ; 
 int dlm_recover_done_wait (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_recover_grant (struct dlm_ls*) ; 
 int dlm_recover_locks (struct dlm_ls*) ; 
 int dlm_recover_locks_wait (struct dlm_ls*) ; 
 int dlm_recover_masters (struct dlm_ls*) ; 
 int dlm_recover_members (struct dlm_ls*,struct dlm_recover*,int*) ; 
 int dlm_recover_members_wait (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_recover_purge (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_recover_rsbs (struct dlm_ls*) ; 
 int dlm_recover_waiters_post (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_recover_waiters_pre (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_release_root_list (struct dlm_ls*) ; 
 int /*<<< orphan*/  dlm_set_recover_status (struct dlm_ls*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  down_write (int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  jiffies_to_msecs (unsigned long) ; 
 int /*<<< orphan*/  kfree (struct dlm_recover*) ; 
 struct task_struct* kthread_run (int (*) (void*),struct dlm_ls*,char*) ; 
 scalar_t__ kthread_should_stop () ; 
 int /*<<< orphan*/  kthread_stop (struct task_struct*) ; 
 int /*<<< orphan*/  log_print (char*,void*) ; 
 int /*<<< orphan*/  log_rinfo (struct dlm_ls*,char*,unsigned long long,...) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  schedule () ; 
 int /*<<< orphan*/  set_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_current_state (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ test_and_clear_bit (int,int /*<<< orphan*/ *) ; 
 int test_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  up_write (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void rsb_set_flag(struct dlm_rsb *r, enum rsb_flags flag)
{
	__set_bit(flag, &r->res_flags);
}

__attribute__((used)) static inline void rsb_clear_flag(struct dlm_rsb *r, enum rsb_flags flag)
{
	__clear_bit(flag, &r->res_flags);
}

__attribute__((used)) static inline int rsb_flag(struct dlm_rsb *r, enum rsb_flags flag)
{
	return test_bit(flag, &r->res_flags);
}

__attribute__((used)) static inline int dlm_locking_stopped(struct dlm_ls *ls)
{
	return !test_bit(LSFL_RUNNING, &ls->ls_flags);
}

__attribute__((used)) static inline int dlm_recovery_stopped(struct dlm_ls *ls)
{
	return test_bit(LSFL_RECOVER_STOP, &ls->ls_flags);
}

__attribute__((used)) static inline int dlm_no_directory(struct dlm_ls *ls)
{
	return test_bit(LSFL_NODIR, &ls->ls_flags);
}

__attribute__((used)) static inline int dlm_register_debugfs(void) { return 0; }

__attribute__((used)) static inline void dlm_unregister_debugfs(void) { }

__attribute__((used)) static inline int dlm_create_debug_file(struct dlm_ls *ls) { return 0; }

__attribute__((used)) static inline void dlm_delete_debug_file(struct dlm_ls *ls) { }

__attribute__((used)) static inline int is_master(struct dlm_rsb *r)
{
	return !r->res_nodeid;
}

__attribute__((used)) static inline void lock_rsb(struct dlm_rsb *r)
{
	mutex_lock(&r->res_mutex);
}

__attribute__((used)) static inline void unlock_rsb(struct dlm_rsb *r)
{
	mutex_unlock(&r->res_mutex);
}

__attribute__((used)) static int enable_locking(struct dlm_ls *ls, uint64_t seq)
{
	int error = -EINTR;

	down_write(&ls->ls_recv_active);

	spin_lock(&ls->ls_recover_lock);
	if (ls->ls_recover_seq == seq) {
		set_bit(LSFL_RUNNING, &ls->ls_flags);
		/* unblocks processes waiting to enter the dlm */
		up_write(&ls->ls_in_recovery);
		clear_bit(LSFL_RECOVER_LOCK, &ls->ls_flags);
		error = 0;
	}
	spin_unlock(&ls->ls_recover_lock);

	up_write(&ls->ls_recv_active);
	return error;
}

__attribute__((used)) static int ls_recover(struct dlm_ls *ls, struct dlm_recover *rv)
{
	unsigned long start;
	int error, neg = 0;

	log_rinfo(ls, "dlm_recover %llu", (unsigned long long)rv->seq);

	mutex_lock(&ls->ls_recoverd_active);

	dlm_callback_suspend(ls);

	dlm_clear_toss(ls);

	/*
	 * This list of root rsb's will be the basis of most of the recovery
	 * routines.
	 */

	dlm_create_root_list(ls);

	/*
	 * Add or remove nodes from the lockspace's ls_nodes list.
	 */

	error = dlm_recover_members(ls, rv, &neg);
	if (error) {
		log_rinfo(ls, "dlm_recover_members error %d", error);
		goto fail;
	}

	dlm_recover_dir_nodeid(ls);

	ls->ls_recover_dir_sent_res = 0;
	ls->ls_recover_dir_sent_msg = 0;
	ls->ls_recover_locks_in = 0;

	dlm_set_recover_status(ls, DLM_RS_NODES);

	error = dlm_recover_members_wait(ls);
	if (error) {
		log_rinfo(ls, "dlm_recover_members_wait error %d", error);
		goto fail;
	}

	start = jiffies;

	/*
	 * Rebuild our own share of the directory by collecting from all other
	 * nodes their master rsb names that hash to us.
	 */

	error = dlm_recover_directory(ls);
	if (error) {
		log_rinfo(ls, "dlm_recover_directory error %d", error);
		goto fail;
	}

	dlm_set_recover_status(ls, DLM_RS_DIR);

	error = dlm_recover_directory_wait(ls);
	if (error) {
		log_rinfo(ls, "dlm_recover_directory_wait error %d", error);
		goto fail;
	}

	log_rinfo(ls, "dlm_recover_directory %u out %u messages",
		  ls->ls_recover_dir_sent_res, ls->ls_recover_dir_sent_msg);

	/*
	 * We may have outstanding operations that are waiting for a reply from
	 * a failed node.  Mark these to be resent after recovery.  Unlock and
	 * cancel ops can just be completed.
	 */

	dlm_recover_waiters_pre(ls);

	error = dlm_recovery_stopped(ls);
	if (error)
		goto fail;

	if (neg || dlm_no_directory(ls)) {
		/*
		 * Clear lkb's for departed nodes.
		 */

		dlm_recover_purge(ls);

		/*
		 * Get new master nodeid's for rsb's that were mastered on
		 * departed nodes.
		 */

		error = dlm_recover_masters(ls);
		if (error) {
			log_rinfo(ls, "dlm_recover_masters error %d", error);
			goto fail;
		}

		/*
		 * Send our locks on remastered rsb's to the new masters.
		 */

		error = dlm_recover_locks(ls);
		if (error) {
			log_rinfo(ls, "dlm_recover_locks error %d", error);
			goto fail;
		}

		dlm_set_recover_status(ls, DLM_RS_LOCKS);

		error = dlm_recover_locks_wait(ls);
		if (error) {
			log_rinfo(ls, "dlm_recover_locks_wait error %d", error);
			goto fail;
		}

		log_rinfo(ls, "dlm_recover_locks %u in",
			  ls->ls_recover_locks_in);

		/*
		 * Finalize state in master rsb's now that all locks can be
		 * checked.  This includes conversion resolution and lvb
		 * settings.
		 */

		dlm_recover_rsbs(ls);
	} else {
		/*
		 * Other lockspace members may be going through the "neg" steps
		 * while also adding us to the lockspace, in which case they'll
		 * be doing the recover_locks (RS_LOCKS) barrier.
		 */
		dlm_set_recover_status(ls, DLM_RS_LOCKS);

		error = dlm_recover_locks_wait(ls);
		if (error) {
			log_rinfo(ls, "dlm_recover_locks_wait error %d", error);
			goto fail;
		}
	}

	dlm_release_root_list(ls);

	/*
	 * Purge directory-related requests that are saved in requestqueue.
	 * All dir requests from before recovery are invalid now due to the dir
	 * rebuild and will be resent by the requesting nodes.
	 */

	dlm_purge_requestqueue(ls);

	dlm_set_recover_status(ls, DLM_RS_DONE);

	error = dlm_recover_done_wait(ls);
	if (error) {
		log_rinfo(ls, "dlm_recover_done_wait error %d", error);
		goto fail;
	}

	dlm_clear_members_gone(ls);

	dlm_adjust_timeouts(ls);

	dlm_callback_resume(ls);

	error = enable_locking(ls, rv->seq);
	if (error) {
		log_rinfo(ls, "enable_locking error %d", error);
		goto fail;
	}

	error = dlm_process_requestqueue(ls);
	if (error) {
		log_rinfo(ls, "dlm_process_requestqueue error %d", error);
		goto fail;
	}

	error = dlm_recover_waiters_post(ls);
	if (error) {
		log_rinfo(ls, "dlm_recover_waiters_post error %d", error);
		goto fail;
	}

	dlm_recover_grant(ls);

	log_rinfo(ls, "dlm_recover %llu generation %u done: %u ms",
		  (unsigned long long)rv->seq, ls->ls_generation,
		  jiffies_to_msecs(jiffies - start));
	mutex_unlock(&ls->ls_recoverd_active);

	dlm_lsop_recover_done(ls);
	return 0;

 fail:
	dlm_release_root_list(ls);
	log_rinfo(ls, "dlm_recover %llu error %d",
		  (unsigned long long)rv->seq, error);
	mutex_unlock(&ls->ls_recoverd_active);
	return error;
}

__attribute__((used)) static void do_ls_recovery(struct dlm_ls *ls)
{
	struct dlm_recover *rv = NULL;

	spin_lock(&ls->ls_recover_lock);
	rv = ls->ls_recover_args;
	ls->ls_recover_args = NULL;
	if (rv && ls->ls_recover_seq == rv->seq)
		clear_bit(LSFL_RECOVER_STOP, &ls->ls_flags);
	spin_unlock(&ls->ls_recover_lock);

	if (rv) {
		ls_recover(ls, rv);
		kfree(rv->nodes);
		kfree(rv);
	}
}

__attribute__((used)) static int dlm_recoverd(void *arg)
{
	struct dlm_ls *ls;

	ls = dlm_find_lockspace_local(arg);
	if (!ls) {
		log_print("dlm_recoverd: no lockspace %p", arg);
		return -1;
	}

	down_write(&ls->ls_in_recovery);
	set_bit(LSFL_RECOVER_LOCK, &ls->ls_flags);
	wake_up(&ls->ls_recover_lock_wait);

	while (1) {
		/*
		 * We call kthread_should_stop() after set_current_state().
		 * This is because it works correctly if kthread_stop() is
		 * called just before set_current_state().
		 */
		set_current_state(TASK_INTERRUPTIBLE);
		if (kthread_should_stop()) {
			set_current_state(TASK_RUNNING);
			break;
		}
		if (!test_bit(LSFL_RECOVER_WORK, &ls->ls_flags) &&
		    !test_bit(LSFL_RECOVER_DOWN, &ls->ls_flags)) {
			if (kthread_should_stop())
				break;
			schedule();
		}
		set_current_state(TASK_RUNNING);

		if (test_and_clear_bit(LSFL_RECOVER_DOWN, &ls->ls_flags)) {
			down_write(&ls->ls_in_recovery);
			set_bit(LSFL_RECOVER_LOCK, &ls->ls_flags);
			wake_up(&ls->ls_recover_lock_wait);
		}

		if (test_and_clear_bit(LSFL_RECOVER_WORK, &ls->ls_flags))
			do_ls_recovery(ls);
	}

	if (test_bit(LSFL_RECOVER_LOCK, &ls->ls_flags))
		up_write(&ls->ls_in_recovery);

	dlm_put_lockspace(ls);
	return 0;
}

int dlm_recoverd_start(struct dlm_ls *ls)
{
	struct task_struct *p;
	int error = 0;

	p = kthread_run(dlm_recoverd, ls, "dlm_recoverd");
	if (IS_ERR(p))
		error = PTR_ERR(p);
	else
                ls->ls_recoverd_task = p;
	return error;
}

void dlm_recoverd_stop(struct dlm_ls *ls)
{
	kthread_stop(ls->ls_recoverd_task);
}

void dlm_recoverd_suspend(struct dlm_ls *ls)
{
	wake_up(&ls->ls_wait_general);
	mutex_lock(&ls->ls_recoverd_active);
}

void dlm_recoverd_resume(struct dlm_ls *ls)
{
	mutex_unlock(&ls->ls_recoverd_active);
}

