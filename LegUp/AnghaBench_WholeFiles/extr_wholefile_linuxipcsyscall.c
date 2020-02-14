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
struct pid {int dummy; } ;
struct kern_ipc_perm {scalar_t__ seq; int /*<<< orphan*/  deleted; int /*<<< orphan*/  lock; } ;
struct ipc_namespace {int dummy; } ;
struct ipc_ids {scalar_t__ in_use; int max_idx; } ;

/* Variables and functions */
 scalar_t__ IPCMNI ; 
 int /*<<< orphan*/  assert_spin_locked (int /*<<< orphan*/ *) ; 
 struct pid* get_pid (struct pid*) ; 
 scalar_t__ ipcid_to_seqx (int) ; 
 int /*<<< orphan*/  put_pid (struct pid*) ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void mq_clear_sbinfo(struct ipc_namespace *ns) { }

__attribute__((used)) static inline void mq_put_mnt(struct ipc_namespace *ns) { }

__attribute__((used)) static inline void sem_init_ns(struct ipc_namespace *ns) { }

__attribute__((used)) static inline void msg_init_ns(struct ipc_namespace *ns) { }

__attribute__((used)) static inline void shm_init_ns(struct ipc_namespace *ns) { }

__attribute__((used)) static inline void sem_exit_ns(struct ipc_namespace *ns) { }

__attribute__((used)) static inline void msg_exit_ns(struct ipc_namespace *ns) { }

__attribute__((used)) static inline void shm_exit_ns(struct ipc_namespace *ns) { }

__attribute__((used)) static inline int ipc_get_maxidx(struct ipc_ids *ids)
{
	if (ids->in_use == 0)
		return -1;

	if (ids->in_use == IPCMNI)
		return IPCMNI - 1;

	return ids->max_idx;
}

__attribute__((used)) static inline void ipc_update_pid(struct pid **pos, struct pid *pid)
{
	struct pid *old = *pos;
	if (old != pid) {
		*pos = get_pid(pid);
		put_pid(old);
	}
}

__attribute__((used)) static inline int ipc_checkid(struct kern_ipc_perm *ipcp, int id)
{
	return ipcid_to_seqx(id) != ipcp->seq;
}

__attribute__((used)) static inline void ipc_lock_object(struct kern_ipc_perm *perm)
{
	spin_lock(&perm->lock);
}

__attribute__((used)) static inline void ipc_unlock_object(struct kern_ipc_perm *perm)
{
	spin_unlock(&perm->lock);
}

__attribute__((used)) static inline void ipc_assert_locked_object(struct kern_ipc_perm *perm)
{
	assert_spin_locked(&perm->lock);
}

__attribute__((used)) static inline void ipc_unlock(struct kern_ipc_perm *perm)
{
	ipc_unlock_object(perm);
	rcu_read_unlock();
}

__attribute__((used)) static inline bool ipc_valid_object(struct kern_ipc_perm *perm)
{
	return !perm->deleted;
}

