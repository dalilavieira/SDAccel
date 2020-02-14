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
struct xt_mtdtor_param {struct xt_cgroup_info_v2* matchinfo; } ;
struct xt_mtchk_param {struct xt_cgroup_info_v2* matchinfo; } ;
struct xt_cgroup_info_v2 {int invert; int invert_path; int invert_classid; scalar_t__ id; scalar_t__ classid; struct cgroup* priv; int /*<<< orphan*/  path; scalar_t__ has_path; scalar_t__ has_classid; } ;
struct xt_cgroup_info_v1 {int invert; int invert_path; int invert_classid; scalar_t__ id; scalar_t__ classid; struct cgroup* priv; int /*<<< orphan*/  path; scalar_t__ has_path; scalar_t__ has_classid; } ;
struct xt_cgroup_info_v0 {int invert; int invert_path; int invert_classid; scalar_t__ id; scalar_t__ classid; struct cgroup* priv; int /*<<< orphan*/  path; scalar_t__ has_path; scalar_t__ has_classid; } ;
struct xt_action_param {struct xt_cgroup_info_v2* matchinfo; } ;
struct sock_cgroup_data {int dummy; } ;
struct sock {struct sock_cgroup_data sk_cgrp_data; } ;
struct sk_buff {struct sock* sk; } ;
struct cgroup {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 scalar_t__ IS_ERR (struct cgroup*) ; 
 int /*<<< orphan*/  PTR_ERR (struct cgroup*) ; 
 struct cgroup* cgroup_get_from_path (int /*<<< orphan*/ ) ; 
 int cgroup_is_descendant (int /*<<< orphan*/ ,struct cgroup*) ; 
 int /*<<< orphan*/  cgroup_put (struct cgroup*) ; 
 int /*<<< orphan*/  net_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_info (char*) ; 
 int /*<<< orphan*/  pr_info_ratelimited (char*,...) ; 
 int /*<<< orphan*/  sk_fullsock (struct sock*) ; 
 scalar_t__ sock_cgroup_classid (struct sock_cgroup_data*) ; 
 int /*<<< orphan*/  sock_cgroup_ptr (struct sock_cgroup_data*) ; 
 int /*<<< orphan*/  sock_net (struct sock*) ; 
 int /*<<< orphan*/  xt_net (struct xt_action_param*) ; 

__attribute__((used)) static int cgroup_mt_check_v0(const struct xt_mtchk_param *par)
{
	struct xt_cgroup_info_v0 *info = par->matchinfo;

	if (info->invert & ~1)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int cgroup_mt_check_v1(const struct xt_mtchk_param *par)
{
	struct xt_cgroup_info_v1 *info = par->matchinfo;
	struct cgroup *cgrp;

	if ((info->invert_path & ~1) || (info->invert_classid & ~1))
		return -EINVAL;

	if (!info->has_path && !info->has_classid) {
		pr_info("xt_cgroup: no path or classid specified\n");
		return -EINVAL;
	}

	if (info->has_path && info->has_classid) {
		pr_info_ratelimited("path and classid specified\n");
		return -EINVAL;
	}

	info->priv = NULL;
	if (info->has_path) {
		cgrp = cgroup_get_from_path(info->path);
		if (IS_ERR(cgrp)) {
			pr_info_ratelimited("invalid path, errno=%ld\n",
					    PTR_ERR(cgrp));
			return -EINVAL;
		}
		info->priv = cgrp;
	}

	return 0;
}

__attribute__((used)) static int cgroup_mt_check_v2(const struct xt_mtchk_param *par)
{
	struct xt_cgroup_info_v2 *info = par->matchinfo;
	struct cgroup *cgrp;

	if ((info->invert_path & ~1) || (info->invert_classid & ~1))
		return -EINVAL;

	if (!info->has_path && !info->has_classid) {
		pr_info("xt_cgroup: no path or classid specified\n");
		return -EINVAL;
	}

	if (info->has_path && info->has_classid) {
		pr_info_ratelimited("path and classid specified\n");
		return -EINVAL;
	}

	info->priv = NULL;
	if (info->has_path) {
		cgrp = cgroup_get_from_path(info->path);
		if (IS_ERR(cgrp)) {
			pr_info_ratelimited("invalid path, errno=%ld\n",
					    PTR_ERR(cgrp));
			return -EINVAL;
		}
		info->priv = cgrp;
	}

	return 0;
}

__attribute__((used)) static bool
cgroup_mt_v0(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_cgroup_info_v0 *info = par->matchinfo;
	struct sock *sk = skb->sk;

	if (!sk || !sk_fullsock(sk) || !net_eq(xt_net(par), sock_net(sk)))
		return false;

	return (info->id == sock_cgroup_classid(&skb->sk->sk_cgrp_data)) ^
		info->invert;
}

__attribute__((used)) static bool cgroup_mt_v1(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_cgroup_info_v1 *info = par->matchinfo;
	struct sock_cgroup_data *skcd = &skb->sk->sk_cgrp_data;
	struct cgroup *ancestor = info->priv;
	struct sock *sk = skb->sk;

	if (!sk || !sk_fullsock(sk) || !net_eq(xt_net(par), sock_net(sk)))
		return false;

	if (ancestor)
		return cgroup_is_descendant(sock_cgroup_ptr(skcd), ancestor) ^
			info->invert_path;
	else
		return (info->classid == sock_cgroup_classid(skcd)) ^
			info->invert_classid;
}

__attribute__((used)) static bool cgroup_mt_v2(const struct sk_buff *skb, struct xt_action_param *par)
{
	const struct xt_cgroup_info_v2 *info = par->matchinfo;
	struct sock_cgroup_data *skcd = &skb->sk->sk_cgrp_data;
	struct cgroup *ancestor = info->priv;
	struct sock *sk = skb->sk;

	if (!sk || !sk_fullsock(sk) || !net_eq(xt_net(par), sock_net(sk)))
		return false;

	if (ancestor)
		return cgroup_is_descendant(sock_cgroup_ptr(skcd), ancestor) ^
			info->invert_path;
	else
		return (info->classid == sock_cgroup_classid(skcd)) ^
			info->invert_classid;
}

__attribute__((used)) static void cgroup_mt_destroy_v1(const struct xt_mtdtor_param *par)
{
	struct xt_cgroup_info_v1 *info = par->matchinfo;

	if (info->priv)
		cgroup_put(info->priv);
}

__attribute__((used)) static void cgroup_mt_destroy_v2(const struct xt_mtdtor_param *par)
{
	struct xt_cgroup_info_v2 *info = par->matchinfo;

	if (info->priv)
		cgroup_put(info->priv);
}

