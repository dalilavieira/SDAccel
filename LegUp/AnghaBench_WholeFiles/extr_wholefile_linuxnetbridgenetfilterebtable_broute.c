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
struct sk_buff {int /*<<< orphan*/  dev; } ;
struct nf_hook_state {TYPE_2__* net; } ;
struct ebt_table_info {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  broute_table; } ;
struct TYPE_4__ {TYPE_1__ xt; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  NFPROTO_BRIDGE ; 
 int NF_BR_BROUTING ; 
 int NF_DROP ; 
 int /*<<< orphan*/  dev_net (int /*<<< orphan*/ ) ; 
 int ebt_do_table (struct sk_buff*,struct nf_hook_state*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_hook_state_init (struct nf_hook_state*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int check(const struct ebt_table_info *info, unsigned int valid_hooks)
{
	if (valid_hooks & ~(1 << NF_BR_BROUTING))
		return -EINVAL;
	return 0;
}

__attribute__((used)) static int ebt_broute(struct sk_buff *skb)
{
	struct nf_hook_state state;
	int ret;

	nf_hook_state_init(&state, NF_BR_BROUTING,
			   NFPROTO_BRIDGE, skb->dev, NULL, NULL,
			   dev_net(skb->dev), NULL);

	ret = ebt_do_table(skb, &state, state.net->xt.broute_table);
	if (ret == NF_DROP)
		return 1; /* route it */
	return 0; /* bridge it */
}

