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
struct user_namespace {int dummy; } ;
struct task_struct {int /*<<< orphan*/  ptracer_cred; } ;
struct inode {int /*<<< orphan*/  i_gid; int /*<<< orphan*/  i_uid; } ;
struct file {int /*<<< orphan*/  f_cred; } ;
struct cred {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  CAP_SYS_PTRACE ; 
 scalar_t__ WARN_ON_ONCE (int) ; 
 int /*<<< orphan*/  cap_valid (int) ; 
 struct user_namespace* current_user_ns () ; 
 scalar_t__ kgid_has_mapping (struct user_namespace*,int /*<<< orphan*/ ) ; 
 scalar_t__ kuid_has_mapping (struct user_namespace*,int /*<<< orphan*/ ) ; 
 scalar_t__ ns_capable (struct user_namespace*,int) ; 
 struct cred* rcu_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 scalar_t__ security_capable (int /*<<< orphan*/ ,struct user_namespace*,int) ; 
 int security_capable_noaudit (struct cred const*,struct user_namespace*,int /*<<< orphan*/ ) ; 

bool file_ns_capable(const struct file *file, struct user_namespace *ns,
		     int cap)
{
	if (WARN_ON_ONCE(!cap_valid(cap)))
		return false;

	if (security_capable(file->f_cred, ns, cap) == 0)
		return true;

	return false;
}

bool privileged_wrt_inode_uidgid(struct user_namespace *ns, const struct inode *inode)
{
	return kuid_has_mapping(ns, inode->i_uid) &&
		kgid_has_mapping(ns, inode->i_gid);
}

bool capable_wrt_inode_uidgid(const struct inode *inode, int cap)
{
	struct user_namespace *ns = current_user_ns();

	return ns_capable(ns, cap) && privileged_wrt_inode_uidgid(ns, inode);
}

bool ptracer_capable(struct task_struct *tsk, struct user_namespace *ns)
{
	int ret = 0;  /* An absent tracer adds no restrictions */
	const struct cred *cred;
	rcu_read_lock();
	cred = rcu_dereference(tsk->ptracer_cred);
	if (cred)
		ret = security_capable_noaudit(cred, ns, CAP_SYS_PTRACE);
	rcu_read_unlock();
	return (ret == 0);
}

