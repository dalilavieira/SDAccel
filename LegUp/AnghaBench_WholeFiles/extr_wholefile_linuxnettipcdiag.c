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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct tipc_topsrv {int dummy; } ;
struct tipc_sock_diag_req {int /*<<< orphan*/  tidiag_states; } ;
struct tipc_sock {int dummy; } ;
struct list_head {int dummy; } ;
struct tipc_net {int net_id; struct tipc_topsrv* topsrv; struct name_table* nametbl; struct list_head node_list; } ;
struct sock {int dummy; } ;
struct sk_buff {int /*<<< orphan*/  sk; } ;
struct nlmsghdr {int nlmsg_flags; } ;
struct netlink_dump_control {int (* dump ) (struct sk_buff*,struct netlink_callback*) ;int /*<<< orphan*/  done; int /*<<< orphan*/  start; } ;
struct netlink_callback {int /*<<< orphan*/  nlh; } ;
struct net {int /*<<< orphan*/  diag_nlsk; } ;
struct name_table {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int EMSGSIZE ; 
 int EOPNOTSUPP ; 
 int NLM_F_DUMP ; 
 int /*<<< orphan*/  NLM_F_MULTI ; 
 int NODE_HTABLE_SIZE ; 
 int /*<<< orphan*/  SOCK_DIAG_BY_FAMILY ; 
 struct tipc_net* net_generic (struct net*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  netlink_dump_start (int /*<<< orphan*/ ,struct sk_buff*,struct nlmsghdr*,struct netlink_dump_control*) ; 
 struct tipc_sock_diag_req* nlmsg_data (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlmsg_end (struct sk_buff*,struct nlmsghdr*) ; 
 int nlmsg_len (struct nlmsghdr*) ; 
 struct nlmsghdr* nlmsg_put_answer (struct sk_buff*,struct netlink_callback*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_diag_save_cookie (struct sock*,int*) ; 
 struct net* sock_net (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tipc_dump_done ; 
 int /*<<< orphan*/  tipc_dump_start ; 
 int /*<<< orphan*/  tipc_net_id ; 
 int tipc_nl_sk_walk (struct sk_buff*,struct netlink_callback*,int (*) (struct sk_buff*,struct netlink_callback*,struct tipc_sock*)) ; 
 int tipc_sk_fill_sock_diag (struct sk_buff*,struct netlink_callback*,struct tipc_sock*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (struct sock*)) ; 

__attribute__((used)) static inline struct tipc_net *tipc_net(struct net *net)
{
	return net_generic(net, tipc_net_id);
}

__attribute__((used)) static inline int tipc_netid(struct net *net)
{
	return tipc_net(net)->net_id;
}

__attribute__((used)) static inline struct list_head *tipc_nodes(struct net *net)
{
	return &tipc_net(net)->node_list;
}

__attribute__((used)) static inline struct name_table *tipc_name_table(struct net *net)
{
	return tipc_net(net)->nametbl;
}

__attribute__((used)) static inline struct tipc_topsrv *tipc_topsrv(struct net *net)
{
	return tipc_net(net)->topsrv;
}

__attribute__((used)) static inline unsigned int tipc_hashfn(u32 addr)
{
	return addr & (NODE_HTABLE_SIZE - 1);
}

__attribute__((used)) static inline u16 mod(u16 x)
{
	return x & 0xffffu;
}

__attribute__((used)) static inline int less_eq(u16 left, u16 right)
{
	return mod(right - left) < 32768u;
}

__attribute__((used)) static inline int more(u16 left, u16 right)
{
	return !less_eq(left, right);
}

__attribute__((used)) static inline int less(u16 left, u16 right)
{
	return less_eq(left, right) && (mod(right) != mod(left));
}

__attribute__((used)) static inline int in_range(u16 val, u16 min, u16 max)
{
	return !less(val, min) && !more(val, max);
}

__attribute__((used)) static u64 __tipc_diag_gen_cookie(struct sock *sk)
{
	u32 res[2];

	sock_diag_save_cookie(sk, res);
	return *((u64 *)res);
}

__attribute__((used)) static int __tipc_add_sock_diag(struct sk_buff *skb,
				struct netlink_callback *cb,
				struct tipc_sock *tsk)
{
	struct tipc_sock_diag_req *req = nlmsg_data(cb->nlh);
	struct nlmsghdr *nlh;
	int err;

	nlh = nlmsg_put_answer(skb, cb, SOCK_DIAG_BY_FAMILY, 0,
			       NLM_F_MULTI);
	if (!nlh)
		return -EMSGSIZE;

	err = tipc_sk_fill_sock_diag(skb, cb, tsk, req->tidiag_states,
				     __tipc_diag_gen_cookie);
	if (err)
		return err;

	nlmsg_end(skb, nlh);
	return 0;
}

__attribute__((used)) static int tipc_diag_dump(struct sk_buff *skb, struct netlink_callback *cb)
{
	return tipc_nl_sk_walk(skb, cb, __tipc_add_sock_diag);
}

__attribute__((used)) static int tipc_sock_diag_handler_dump(struct sk_buff *skb,
				       struct nlmsghdr *h)
{
	int hdrlen = sizeof(struct tipc_sock_diag_req);
	struct net *net = sock_net(skb->sk);

	if (nlmsg_len(h) < hdrlen)
		return -EINVAL;

	if (h->nlmsg_flags & NLM_F_DUMP) {
		struct netlink_dump_control c = {
			.start = tipc_dump_start,
			.dump = tipc_diag_dump,
			.done = tipc_dump_done,
		};
		netlink_dump_start(net->diag_nlsk, skb, h, &c);
		return 0;
	}
	return -EOPNOTSUPP;
}

