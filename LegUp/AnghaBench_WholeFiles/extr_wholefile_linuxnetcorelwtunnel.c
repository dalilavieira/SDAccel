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
typedef  unsigned int u16 ;
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct rtnexthop {int dummy; } ;
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
struct net {int dummy; } ;
struct lwtunnel_state {size_t type; } ;
struct lwtunnel_encap_ops {int (* build_state ) (struct nlattr*,unsigned int,void const*,struct lwtunnel_state**,struct netlink_ext_ack*) ;int (* fill_encap ) (struct sk_buff*,struct lwtunnel_state*) ;int (* cmp_encap ) (struct lwtunnel_state*,struct lwtunnel_state*) ;int (* output ) (struct net*,struct sock*,struct sk_buff*) ;int (* xmit ) (struct sk_buff*) ;int (* input ) (struct sk_buff*) ;int /*<<< orphan*/  (* get_encap_size ) (struct lwtunnel_state*) ;int /*<<< orphan*/  owner; int /*<<< orphan*/  (* destroy_state ) (struct lwtunnel_state*) ;} ;
struct dst_entry {struct lwtunnel_state* lwtstate; } ;

/* Variables and functions */
 int EINVAL ; 
 int EMSGSIZE ; 
 int EOPNOTSUPP ; 
 int ERANGE ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 unsigned int LWTUNNEL_ENCAP_MAX ; 
 unsigned int LWTUNNEL_ENCAP_NONE ; 
 int /*<<< orphan*/  NL_SET_ERR_MSG (struct netlink_ext_ack*,char*) ; 
 int /*<<< orphan*/  NL_SET_ERR_MSG_ATTR (struct netlink_ext_ack*,struct nlattr*,char*) ; 
 int /*<<< orphan*/  RTA_ENCAP ; 
 int /*<<< orphan*/  RTA_ENCAP_TYPE ; 
 struct lwtunnel_encap_ops const* cmpxchg (struct lwtunnel_encap_ops const**,struct lwtunnel_encap_ops const*,struct lwtunnel_encap_ops const*) ; 
 int /*<<< orphan*/  kfree (struct lwtunnel_state*) ; 
 int /*<<< orphan*/  kfree_rcu (struct lwtunnel_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 struct lwtunnel_state* kzalloc (int,int /*<<< orphan*/ ) ; 
 scalar_t__ likely (int) ; 
 struct lwtunnel_encap_ops** lwtun_encaps ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 struct nlattr* nla_find (struct nlattr*,int,int /*<<< orphan*/ ) ; 
 unsigned int nla_get_u16 (struct nlattr*) ; 
 int /*<<< orphan*/  nla_nest_cancel (struct sk_buff*,struct nlattr*) ; 
 int /*<<< orphan*/  nla_nest_end (struct sk_buff*,struct nlattr*) ; 
 struct nlattr* nla_nest_start (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int nla_put_u16 (struct sk_buff*,int /*<<< orphan*/ ,size_t) ; 
 int nla_total_size (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rcu ; 
 struct lwtunnel_encap_ops* rcu_dereference (struct lwtunnel_encap_ops*) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 int rtnh_attrlen (struct rtnexthop*) ; 
 struct nlattr* rtnh_attrs (struct rtnexthop*) ; 
 struct rtnexthop* rtnh_next (struct rtnexthop*,int*) ; 
 scalar_t__ rtnh_ok (struct rtnexthop*,int) ; 
 struct dst_entry* skb_dst (struct sk_buff*) ; 
 int stub1 (struct nlattr*,unsigned int,void const*,struct lwtunnel_state**,struct netlink_ext_ack*) ; 
 int /*<<< orphan*/  stub2 (struct lwtunnel_state*) ; 
 int stub3 (struct sk_buff*,struct lwtunnel_state*) ; 
 int /*<<< orphan*/  stub4 (struct lwtunnel_state*) ; 
 int stub5 (struct lwtunnel_state*,struct lwtunnel_state*) ; 
 int stub6 (struct net*,struct sock*,struct sk_buff*) ; 
 int stub7 (struct sk_buff*) ; 
 int stub8 (struct sk_buff*) ; 
 int /*<<< orphan*/  synchronize_net () ; 
 scalar_t__ try_module_get (int /*<<< orphan*/ ) ; 

struct lwtunnel_state *lwtunnel_state_alloc(int encap_len)
{
	struct lwtunnel_state *lws;

	lws = kzalloc(sizeof(*lws) + encap_len, GFP_ATOMIC);

	return lws;
}

int lwtunnel_encap_add_ops(const struct lwtunnel_encap_ops *ops,
			   unsigned int num)
{
	if (num > LWTUNNEL_ENCAP_MAX)
		return -ERANGE;

	return !cmpxchg((const struct lwtunnel_encap_ops **)
			&lwtun_encaps[num],
			NULL, ops) ? 0 : -1;
}

int lwtunnel_encap_del_ops(const struct lwtunnel_encap_ops *ops,
			   unsigned int encap_type)
{
	int ret;

	if (encap_type == LWTUNNEL_ENCAP_NONE ||
	    encap_type > LWTUNNEL_ENCAP_MAX)
		return -ERANGE;

	ret = (cmpxchg((const struct lwtunnel_encap_ops **)
		       &lwtun_encaps[encap_type],
		       ops, NULL) == ops) ? 0 : -1;

	synchronize_net();

	return ret;
}

int lwtunnel_build_state(u16 encap_type,
			 struct nlattr *encap, unsigned int family,
			 const void *cfg, struct lwtunnel_state **lws,
			 struct netlink_ext_ack *extack)
{
	const struct lwtunnel_encap_ops *ops;
	bool found = false;
	int ret = -EINVAL;

	if (encap_type == LWTUNNEL_ENCAP_NONE ||
	    encap_type > LWTUNNEL_ENCAP_MAX) {
		NL_SET_ERR_MSG_ATTR(extack, encap,
				    "Unknown LWT encapsulation type");
		return ret;
	}

	ret = -EOPNOTSUPP;
	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[encap_type]);
	if (likely(ops && ops->build_state && try_module_get(ops->owner))) {
		found = true;
		ret = ops->build_state(encap, family, cfg, lws, extack);
		if (ret)
			module_put(ops->owner);
	}
	rcu_read_unlock();

	/* don't rely on -EOPNOTSUPP to detect match as build_state
	 * handlers could return it
	 */
	if (!found) {
		NL_SET_ERR_MSG_ATTR(extack, encap,
				    "LWT encapsulation type not supported");
	}

	return ret;
}

int lwtunnel_valid_encap_type(u16 encap_type, struct netlink_ext_ack *extack)
{
	const struct lwtunnel_encap_ops *ops;
	int ret = -EINVAL;

	if (encap_type == LWTUNNEL_ENCAP_NONE ||
	    encap_type > LWTUNNEL_ENCAP_MAX) {
		NL_SET_ERR_MSG(extack, "Unknown lwt encapsulation type");
		return ret;
	}

	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[encap_type]);
	rcu_read_unlock();
#ifdef CONFIG_MODULES
	if (!ops) {
		const char *encap_type_str = lwtunnel_encap_str(encap_type);

		if (encap_type_str) {
			__rtnl_unlock();
			request_module("rtnl-lwt-%s", encap_type_str);
			rtnl_lock();

			rcu_read_lock();
			ops = rcu_dereference(lwtun_encaps[encap_type]);
			rcu_read_unlock();
		}
	}
#endif
	ret = ops ? 0 : -EOPNOTSUPP;
	if (ret < 0)
		NL_SET_ERR_MSG(extack, "lwt encapsulation type not supported");

	return ret;
}

int lwtunnel_valid_encap_type_attr(struct nlattr *attr, int remaining,
				   struct netlink_ext_ack *extack)
{
	struct rtnexthop *rtnh = (struct rtnexthop *)attr;
	struct nlattr *nla_entype;
	struct nlattr *attrs;
	u16 encap_type;
	int attrlen;

	while (rtnh_ok(rtnh, remaining)) {
		attrlen = rtnh_attrlen(rtnh);
		if (attrlen > 0) {
			attrs = rtnh_attrs(rtnh);
			nla_entype = nla_find(attrs, attrlen, RTA_ENCAP_TYPE);

			if (nla_entype) {
				encap_type = nla_get_u16(nla_entype);

				if (lwtunnel_valid_encap_type(encap_type,
							      extack) != 0)
					return -EOPNOTSUPP;
			}
		}
		rtnh = rtnh_next(rtnh, &remaining);
	}

	return 0;
}

void lwtstate_free(struct lwtunnel_state *lws)
{
	const struct lwtunnel_encap_ops *ops = lwtun_encaps[lws->type];

	if (ops->destroy_state) {
		ops->destroy_state(lws);
		kfree_rcu(lws, rcu);
	} else {
		kfree(lws);
	}
	module_put(ops->owner);
}

int lwtunnel_fill_encap(struct sk_buff *skb, struct lwtunnel_state *lwtstate)
{
	const struct lwtunnel_encap_ops *ops;
	struct nlattr *nest;
	int ret;

	if (!lwtstate)
		return 0;

	if (lwtstate->type == LWTUNNEL_ENCAP_NONE ||
	    lwtstate->type > LWTUNNEL_ENCAP_MAX)
		return 0;

	nest = nla_nest_start(skb, RTA_ENCAP);
	if (!nest)
		return -EMSGSIZE;

	ret = -EOPNOTSUPP;
	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[lwtstate->type]);
	if (likely(ops && ops->fill_encap))
		ret = ops->fill_encap(skb, lwtstate);
	rcu_read_unlock();

	if (ret)
		goto nla_put_failure;
	nla_nest_end(skb, nest);
	ret = nla_put_u16(skb, RTA_ENCAP_TYPE, lwtstate->type);
	if (ret)
		goto nla_put_failure;

	return 0;

nla_put_failure:
	nla_nest_cancel(skb, nest);

	return (ret == -EOPNOTSUPP ? 0 : ret);
}

int lwtunnel_get_encap_size(struct lwtunnel_state *lwtstate)
{
	const struct lwtunnel_encap_ops *ops;
	int ret = 0;

	if (!lwtstate)
		return 0;

	if (lwtstate->type == LWTUNNEL_ENCAP_NONE ||
	    lwtstate->type > LWTUNNEL_ENCAP_MAX)
		return 0;

	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[lwtstate->type]);
	if (likely(ops && ops->get_encap_size))
		ret = nla_total_size(ops->get_encap_size(lwtstate));
	rcu_read_unlock();

	return ret;
}

int lwtunnel_cmp_encap(struct lwtunnel_state *a, struct lwtunnel_state *b)
{
	const struct lwtunnel_encap_ops *ops;
	int ret = 0;

	if (!a && !b)
		return 0;

	if (!a || !b)
		return 1;

	if (a->type != b->type)
		return 1;

	if (a->type == LWTUNNEL_ENCAP_NONE ||
	    a->type > LWTUNNEL_ENCAP_MAX)
		return 0;

	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[a->type]);
	if (likely(ops && ops->cmp_encap))
		ret = ops->cmp_encap(a, b);
	rcu_read_unlock();

	return ret;
}

int lwtunnel_output(struct net *net, struct sock *sk, struct sk_buff *skb)
{
	struct dst_entry *dst = skb_dst(skb);
	const struct lwtunnel_encap_ops *ops;
	struct lwtunnel_state *lwtstate;
	int ret = -EINVAL;

	if (!dst)
		goto drop;
	lwtstate = dst->lwtstate;

	if (lwtstate->type == LWTUNNEL_ENCAP_NONE ||
	    lwtstate->type > LWTUNNEL_ENCAP_MAX)
		return 0;

	ret = -EOPNOTSUPP;
	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[lwtstate->type]);
	if (likely(ops && ops->output))
		ret = ops->output(net, sk, skb);
	rcu_read_unlock();

	if (ret == -EOPNOTSUPP)
		goto drop;

	return ret;

drop:
	kfree_skb(skb);

	return ret;
}

int lwtunnel_xmit(struct sk_buff *skb)
{
	struct dst_entry *dst = skb_dst(skb);
	const struct lwtunnel_encap_ops *ops;
	struct lwtunnel_state *lwtstate;
	int ret = -EINVAL;

	if (!dst)
		goto drop;

	lwtstate = dst->lwtstate;

	if (lwtstate->type == LWTUNNEL_ENCAP_NONE ||
	    lwtstate->type > LWTUNNEL_ENCAP_MAX)
		return 0;

	ret = -EOPNOTSUPP;
	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[lwtstate->type]);
	if (likely(ops && ops->xmit))
		ret = ops->xmit(skb);
	rcu_read_unlock();

	if (ret == -EOPNOTSUPP)
		goto drop;

	return ret;

drop:
	kfree_skb(skb);

	return ret;
}

int lwtunnel_input(struct sk_buff *skb)
{
	struct dst_entry *dst = skb_dst(skb);
	const struct lwtunnel_encap_ops *ops;
	struct lwtunnel_state *lwtstate;
	int ret = -EINVAL;

	if (!dst)
		goto drop;
	lwtstate = dst->lwtstate;

	if (lwtstate->type == LWTUNNEL_ENCAP_NONE ||
	    lwtstate->type > LWTUNNEL_ENCAP_MAX)
		return 0;

	ret = -EOPNOTSUPP;
	rcu_read_lock();
	ops = rcu_dereference(lwtun_encaps[lwtstate->type]);
	if (likely(ops && ops->input))
		ret = ops->input(skb);
	rcu_read_unlock();

	if (ret == -EOPNOTSUPP)
		goto drop;

	return ret;

drop:
	kfree_skb(skb);

	return ret;
}

