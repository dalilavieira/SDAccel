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
struct vfsmount {int dummy; } ;
struct task_struct {int dummy; } ;
struct task_smack {struct smack_known* smk_forked; struct smack_known* smk_task; } ;
struct socket_smack {struct smack_known* smk_out; } ;
struct sock {struct socket_smack* sk_security; } ;
struct smk_audit_info {int dummy; } ;
struct smack_known {int /*<<< orphan*/  smk_secid; } ;
struct sk_buff {int /*<<< orphan*/  secmark; } ;
struct path {int dummy; } ;
struct nf_hook_state {int dummy; } ;
struct inode_smack {int smk_flags; struct smack_known* smk_inode; } ;
struct inode {struct inode_smack* i_security; } ;
struct dentry {int dummy; } ;
struct TYPE_2__ {struct task_smack* security; } ;

/* Variables and functions */
 unsigned int NF_ACCEPT ; 
 int SMK_INODE_TRANSMUTE ; 
 TYPE_1__* __task_cred (struct task_struct const*) ; 
 struct task_smack* current_security () ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 struct sock* skb_to_full_sk (struct sk_buff*) ; 

__attribute__((used)) static inline int smk_inode_transmutable(const struct inode *isp)
{
	struct inode_smack *sip = isp->i_security;
	return (sip->smk_flags & SMK_INODE_TRANSMUTE) != 0;
}

__attribute__((used)) static inline struct smack_known *smk_of_inode(const struct inode *isp)
{
	struct inode_smack *sip = isp->i_security;
	return sip->smk_inode;
}

__attribute__((used)) static inline struct smack_known *smk_of_task(const struct task_smack *tsp)
{
	return tsp->smk_task;
}

__attribute__((used)) static inline struct smack_known *smk_of_task_struct(const struct task_struct *t)
{
	struct smack_known *skp;

	rcu_read_lock();
	skp = smk_of_task(__task_cred(t)->security);
	rcu_read_unlock();
	return skp;
}

__attribute__((used)) static inline struct smack_known *smk_of_forked(const struct task_smack *tsp)
{
	return tsp->smk_forked;
}

__attribute__((used)) static inline struct smack_known *smk_of_current(void)
{
	return smk_of_task(current_security());
}

__attribute__((used)) static inline void smk_ad_init(struct smk_audit_info *a, const char *func,
			       char type)
{
}

__attribute__((used)) static inline void smk_ad_setfield_u_tsk(struct smk_audit_info *a,
					 struct task_struct *t)
{
}

__attribute__((used)) static inline void smk_ad_setfield_u_fs_path_dentry(struct smk_audit_info *a,
						    struct dentry *d)
{
}

__attribute__((used)) static inline void smk_ad_setfield_u_fs_path_mnt(struct smk_audit_info *a,
						 struct vfsmount *m)
{
}

__attribute__((used)) static inline void smk_ad_setfield_u_fs_inode(struct smk_audit_info *a,
					      struct inode *i)
{
}

__attribute__((used)) static inline void smk_ad_setfield_u_fs_path(struct smk_audit_info *a,
					     struct path p)
{
}

__attribute__((used)) static inline void smk_ad_setfield_u_net_sk(struct smk_audit_info *a,
					    struct sock *sk)
{
}

__attribute__((used)) static unsigned int smack_ipv4_output(void *priv,
					struct sk_buff *skb,
					const struct nf_hook_state *state)
{
	struct sock *sk = skb_to_full_sk(skb);
	struct socket_smack *ssp;
	struct smack_known *skp;

	if (sk && sk->sk_security) {
		ssp = sk->sk_security;
		skp = ssp->smk_out;
		skb->secmark = skp->smk_secid;
	}

	return NF_ACCEPT;
}

