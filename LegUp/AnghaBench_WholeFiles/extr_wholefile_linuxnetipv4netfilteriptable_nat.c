#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int dummy; } ;
struct nf_hook_state {TYPE_2__* net; } ;
struct net {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  nat_table; } ;
struct TYPE_4__ {TYPE_1__ ipv4; } ;

/* Variables and functions */
 int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 unsigned int ipt_do_table (struct sk_buff*,struct nf_hook_state const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * nf_nat_ipv4_ops ; 
 int nf_nat_l3proto_ipv4_register_fn (struct net*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_nat_l3proto_ipv4_unregister_fn (struct net*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static unsigned int iptable_nat_do_chain(void *priv,
					 struct sk_buff *skb,
					 const struct nf_hook_state *state)
{
	return ipt_do_table(skb, state, state->net->ipv4.nat_table);
}

__attribute__((used)) static int ipt_nat_register_lookups(struct net *net)
{
	int i, ret;

	for (i = 0; i < ARRAY_SIZE(nf_nat_ipv4_ops); i++) {
		ret = nf_nat_l3proto_ipv4_register_fn(net, &nf_nat_ipv4_ops[i]);
		if (ret) {
			while (i)
				nf_nat_l3proto_ipv4_unregister_fn(net, &nf_nat_ipv4_ops[--i]);

			return ret;
		}
	}

	return 0;
}

__attribute__((used)) static void ipt_nat_unregister_lookups(struct net *net)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(nf_nat_ipv4_ops); i++)
		nf_nat_l3proto_ipv4_unregister_fn(net, &nf_nat_ipv4_ops[i]);
}

