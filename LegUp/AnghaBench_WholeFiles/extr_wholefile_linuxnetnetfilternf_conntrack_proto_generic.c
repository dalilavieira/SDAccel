#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u_int16_t ;
typedef  int u8 ;
struct sk_buff {int dummy; } ;
struct nf_proto_net {int dummy; } ;
struct nf_generic_net {unsigned int timeout; struct nf_proto_net pn; } ;
struct TYPE_9__ {scalar_t__ all; } ;
struct TYPE_10__ {TYPE_3__ u; } ;
struct TYPE_7__ {scalar_t__ all; } ;
struct TYPE_8__ {TYPE_1__ u; } ;
struct nf_conntrack_tuple {TYPE_4__ dst; TYPE_2__ src; } ;
struct nf_conn {int dummy; } ;
struct TYPE_11__ {struct nf_generic_net generic; } ;
struct TYPE_12__ {TYPE_5__ nf_ct_proto; } ;
struct net {TYPE_6__ ct; } ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;

/* Variables and functions */
 int NF_ACCEPT ; 
 unsigned int nf_ct_generic_timeout ; 
 struct net* nf_ct_net (struct nf_conn*) ; 
 int nf_ct_protonum (struct nf_conn*) ; 
 int /*<<< orphan*/  nf_ct_refresh_acct (struct nf_conn*,int,struct sk_buff const*,unsigned int const) ; 
 unsigned int* nf_ct_timeout_lookup (struct nf_conn*) ; 
 int /*<<< orphan*/  pr_warn_once (char*,int) ; 

__attribute__((used)) static bool nf_generic_should_process(u8 proto)
{
	switch (proto) {
#ifdef CONFIG_NF_CT_PROTO_GRE_MODULE
	case IPPROTO_GRE:
		return false;
#endif
	default:
		return true;
	}
}

__attribute__((used)) static inline struct nf_generic_net *generic_pernet(struct net *net)
{
	return &net->ct.nf_ct_proto.generic;
}

__attribute__((used)) static bool generic_pkt_to_tuple(const struct sk_buff *skb,
				 unsigned int dataoff,
				 struct net *net, struct nf_conntrack_tuple *tuple)
{
	tuple->src.u.all = 0;
	tuple->dst.u.all = 0;

	return true;
}

__attribute__((used)) static int generic_packet(struct nf_conn *ct,
			  const struct sk_buff *skb,
			  unsigned int dataoff,
			  enum ip_conntrack_info ctinfo)
{
	const unsigned int *timeout = nf_ct_timeout_lookup(ct);

	if (!timeout)
		timeout = &generic_pernet(nf_ct_net(ct))->timeout;

	nf_ct_refresh_acct(ct, ctinfo, skb, *timeout);
	return NF_ACCEPT;
}

__attribute__((used)) static bool generic_new(struct nf_conn *ct, const struct sk_buff *skb,
			unsigned int dataoff)
{
	bool ret;

	ret = nf_generic_should_process(nf_ct_protonum(ct));
	if (!ret)
		pr_warn_once("conntrack: generic helper won't handle protocol %d. Please consider loading the specific helper module.\n",
			     nf_ct_protonum(ct));
	return ret;
}

__attribute__((used)) static int generic_kmemdup_sysctl_table(struct nf_proto_net *pn,
					struct nf_generic_net *gn)
{
#ifdef CONFIG_SYSCTL
	pn->ctl_table = kmemdup(generic_sysctl_table,
				sizeof(generic_sysctl_table),
				GFP_KERNEL);
	if (!pn->ctl_table)
		return -ENOMEM;

	pn->ctl_table[0].data = &gn->timeout;
#endif
	return 0;
}

__attribute__((used)) static int generic_init_net(struct net *net, u_int16_t proto)
{
	struct nf_generic_net *gn = generic_pernet(net);
	struct nf_proto_net *pn = &gn->pn;

	gn->timeout = nf_ct_generic_timeout;

	return generic_kmemdup_sysctl_table(pn, gn);
}

__attribute__((used)) static struct nf_proto_net *generic_get_net_proto(struct net *net)
{
	return &net->ct.nf_ct_proto.generic.pn;
}

