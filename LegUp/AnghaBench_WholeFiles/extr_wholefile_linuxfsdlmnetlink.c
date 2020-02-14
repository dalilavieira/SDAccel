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
typedef  int /*<<< orphan*/  u8 ;
struct sk_buff {scalar_t__ data; } ;
struct nlmsghdr {int dummy; } ;
struct nlattr {int dummy; } ;
struct genlmsghdr {int dummy; } ;
struct genl_info {int /*<<< orphan*/  snd_portid; } ;
struct dlm_rsb {int /*<<< orphan*/  res_flags; } ;
struct dlm_ls {int /*<<< orphan*/  ls_flags; } ;
struct dlm_lock_data {int dummy; } ;
typedef  enum rsb_flags { ____Placeholder_rsb_flags } rsb_flags ;

/* Variables and functions */
 int /*<<< orphan*/  DLM_TYPE_LOCK ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_NOFS ; 
 int LSFL_NODIR ; 
 int LSFL_RECOVER_STOP ; 
 int LSFL_RUNNING ; 
 int /*<<< orphan*/  __clear_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  __set_bit (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dlm_nl_seqnum ; 
 int /*<<< orphan*/  family ; 
 void* genlmsg_data (struct genlmsghdr*) ; 
 int /*<<< orphan*/  genlmsg_end (struct sk_buff*,void*) ; 
 struct sk_buff* genlmsg_new (size_t,int /*<<< orphan*/ ) ; 
 void* genlmsg_put (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int genlmsg_unicast (int /*<<< orphan*/ *,struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  init_net ; 
 int /*<<< orphan*/  listener_nlportid ; 
 struct dlm_lock_data* nla_data (struct nlattr*) ; 
 struct nlattr* nla_reserve (struct sk_buff*,int /*<<< orphan*/ ,int) ; 
 struct genlmsghdr* nlmsg_data (struct nlmsghdr*) ; 
 int /*<<< orphan*/  nlmsg_free (struct sk_buff*) ; 
 int /*<<< orphan*/  printk (char*,int /*<<< orphan*/ ) ; 
 int test_bit (int,int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static int prepare_data(u8 cmd, struct sk_buff **skbp, size_t size)
{
	struct sk_buff *skb;
	void *data;

	skb = genlmsg_new(size, GFP_NOFS);
	if (!skb)
		return -ENOMEM;

	/* add the message headers */
	data = genlmsg_put(skb, 0, dlm_nl_seqnum++, &family, 0, cmd);
	if (!data) {
		nlmsg_free(skb);
		return -EINVAL;
	}

	*skbp = skb;
	return 0;
}

__attribute__((used)) static struct dlm_lock_data *mk_data(struct sk_buff *skb)
{
	struct nlattr *ret;

	ret = nla_reserve(skb, DLM_TYPE_LOCK, sizeof(struct dlm_lock_data));
	if (!ret)
		return NULL;
	return nla_data(ret);
}

__attribute__((used)) static int send_data(struct sk_buff *skb)
{
	struct genlmsghdr *genlhdr = nlmsg_data((struct nlmsghdr *)skb->data);
	void *data = genlmsg_data(genlhdr);

	genlmsg_end(skb, data);

	return genlmsg_unicast(&init_net, skb, listener_nlportid);
}

__attribute__((used)) static int user_cmd(struct sk_buff *skb, struct genl_info *info)
{
	listener_nlportid = info->snd_portid;
	printk("user_cmd nlpid %u\n", listener_nlportid);
	return 0;
}

