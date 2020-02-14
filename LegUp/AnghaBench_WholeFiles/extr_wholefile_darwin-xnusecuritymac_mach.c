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
typedef  int /*<<< orphan*/  thread_t ;
struct ucred {int dummy; } ;
struct thread {int dummy; } ;
struct task {int dummy; } ;
struct proc {struct proc* label; } ;
struct label {struct label* label; } ;
struct ipc_port {int dummy; } ;
struct exception_action {struct exception_action* label; } ;
typedef  int /*<<< orphan*/  kauth_cred_t ;

/* Variables and functions */
 int EPERM ; 
 int ESRCH ; 
 int EXC_TYPES_COUNT ; 
 int /*<<< orphan*/  FALSE ; 
 int FIRST_EXCEPTION ; 
 int /*<<< orphan*/  MAC_CHECK (int /*<<< orphan*/ ,struct proc*,...) ; 
 int /*<<< orphan*/  MAC_MACH_UNEXPECTED (char*) ; 
 int /*<<< orphan*/  MAC_PERFORM (int /*<<< orphan*/ ,struct proc*,...) ; 
 int /*<<< orphan*/  MAC_WAITOK ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  assert (int) ; 
 struct proc* current_proc () ; 
 struct task* current_task () ; 
 int /*<<< orphan*/  current_thread () ; 
 int /*<<< orphan*/  exc_action_check_exception_send ; 
 int /*<<< orphan*/  exc_action_label_associate ; 
 int /*<<< orphan*/  exc_action_label_destroy ; 
 int /*<<< orphan*/  exc_action_label_init ; 
 int /*<<< orphan*/  exc_action_label_populate ; 
 int /*<<< orphan*/  exc_action_label_update ; 
 struct proc* get_bsdtask_info (struct task*) ; 
 struct proc* get_task_crash_label (struct task*) ; 
 struct ucred* kauth_cred_get () ; 
 int /*<<< orphan*/  kauth_cred_proc_ref (struct proc*) ; 
 int /*<<< orphan*/  kauth_cred_unref (int /*<<< orphan*/ *) ; 
 struct task* kernel_task ; 
 struct proc* mac_labelzone_alloc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mac_labelzone_free (struct proc*) ; 
 int /*<<< orphan*/  proc_check_expose_task ; 
 int /*<<< orphan*/  proc_check_set_host_exception_port ; 
 int /*<<< orphan*/  proc_check_set_host_special_port ; 
 struct proc* proc_find (int) ; 
 int /*<<< orphan*/  proc_notify_exec_complete ; 
 int /*<<< orphan*/  proc_rele (struct proc*) ; 
 struct proc* proc_self () ; 
 struct task* proc_task (struct proc*) ; 
 int task_pid (struct task*) ; 
 int /*<<< orphan*/  thread_enable_send_importance (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  thread_userret ; 

__attribute__((used)) static struct proc *
mac_task_get_proc(struct task *task)
{
	if (task == current_task())
		return proc_self();

	/*
	 * Tasks don't really hold a reference on a proc unless the
	 * calling thread belongs to the task in question.
	 */
	int pid = task_pid(task);
	struct proc *p = proc_find(pid);

	if (p != NULL) {
		if (proc_task(p) == task)
			return p;
		proc_rele(p);
	}
	return NULL;
}

int
mac_task_check_expose_task(struct task *task)
{
	int error;

	struct proc *p = mac_task_get_proc(task);
	if (p == NULL)
		return ESRCH;

	struct ucred *cred = kauth_cred_get();
	MAC_CHECK(proc_check_expose_task, cred, p);
	proc_rele(p);
	return (error);
}

int
mac_task_check_set_host_special_port(struct task *task, int id, struct ipc_port *port)
{
	int error;

	struct proc *p = mac_task_get_proc(task);
	if (p == NULL)
		return ESRCH;

	kauth_cred_t cred = kauth_cred_proc_ref(p);
	MAC_CHECK(proc_check_set_host_special_port, cred, id, port);
	kauth_cred_unref(&cred);
	proc_rele(p);
	return (error);
}

int
mac_task_check_set_host_exception_port(struct task *task, unsigned int exception)
{
	int error;

	struct proc *p = mac_task_get_proc(task);
	if (p == NULL)
		return ESRCH;

	kauth_cred_t cred = kauth_cred_proc_ref(p);
	MAC_CHECK(proc_check_set_host_exception_port, cred, exception);
	kauth_cred_unref(&cred);
	proc_rele(p);
	return (error);
}

int
mac_task_check_set_host_exception_ports(struct task *task, unsigned int exception_mask)
{
	int error = 0;
	int exception;

	struct proc *p = mac_task_get_proc(task);
	if (p == NULL)
		return ESRCH;

	kauth_cred_t cred = kauth_cred_proc_ref(p);
	for (exception = FIRST_EXCEPTION; exception < EXC_TYPES_COUNT; exception++) {
		if (exception_mask & (1 << exception)) {
			MAC_CHECK(proc_check_set_host_exception_port, cred, exception);
			if (error)
				break;
		}
	}
	kauth_cred_unref(&cred);
	proc_rele(p);
	return (error);
}

void
mac_thread_userret(struct thread *td)
{

	MAC_PERFORM(thread_userret, td);
}

void
mac_proc_notify_exec_complete(struct proc *proc)
{
	thread_t thread = current_thread();

	/*
	 * Since this MAC hook was designed to support upcalls, make sure the hook
	 * is called with kernel importance propagation enabled so any daemons
	 * can get any appropriate importance donations.
	 */
	thread_enable_send_importance(thread, TRUE);
	MAC_PERFORM(proc_notify_exec_complete, proc);
	thread_enable_send_importance(thread, FALSE);
}

struct label *
mac_exc_create_label(void)
{
	struct label *label = mac_labelzone_alloc(MAC_WAITOK);

	if (label == NULL) {
		return NULL;
	}

	// Policy initialization of the label, typically performs allocations as well.
	// (Unless the policy's full data really fits into a pointer size.)
	MAC_PERFORM(exc_action_label_init, label);
	
	return label;
}

void
mac_exc_free_label(struct label *label)
{
	MAC_PERFORM(exc_action_label_destroy, label);
	mac_labelzone_free(label);
}

void
mac_exc_associate_action_label(struct exception_action *action, struct label *label)
{
	action->label = label;
	MAC_PERFORM(exc_action_label_associate, action, action->label);
}

void
mac_exc_free_action_label(struct exception_action *action)
{
	mac_exc_free_label(action->label);
	action->label = NULL;
}

int
mac_exc_update_action_label(struct exception_action *action,
							struct label *newlabel) {
	int error;
	
	MAC_CHECK(exc_action_label_update, action, action->label, newlabel);
	
	return (error);
}

int
mac_exc_inherit_action_label(struct exception_action *parent,
							 struct exception_action *child) {
	return mac_exc_update_action_label(child, parent->label);
}

int mac_exc_update_task_crash_label(struct task *task, struct label *label) {
	int error;

	assert(task != kernel_task);

	struct label *crash_label = get_task_crash_label(task);

	MAC_CHECK(exc_action_label_update, NULL, crash_label, label);
	
	return (error);
}

struct label *
mac_exc_create_label_for_proc(struct proc *proc)
{
	struct label *label = mac_exc_create_label();
	MAC_PERFORM(exc_action_label_populate, label, proc);
	return label;
}

struct label *
mac_exc_create_label_for_current_proc(void)
{
	return mac_exc_create_label_for_proc(current_proc());
}

int
mac_exc_action_check_exception_send(struct task *victim_task, struct exception_action *action)
{
	int error = 0;

	struct proc *p = get_bsdtask_info(victim_task);
	struct label *bsd_label = NULL;
	struct label *label = NULL;

	if (p != NULL) {
		// Create a label from the still existing bsd process...
		label = bsd_label = mac_exc_create_label_for_proc(p);
	} else {
		// ... otherwise use the crash label on the task.
		label = get_task_crash_label(victim_task);
	}

	if (label == NULL) {
		MAC_MACH_UNEXPECTED("mac_exc_action_check_exception_send: no exc_action label for process");
		return EPERM;
	}

	MAC_CHECK(exc_action_check_exception_send, label, action, action->label);

	if (bsd_label != NULL) {
		mac_exc_free_label(bsd_label);
	}

	return (error);
}

