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
struct ebt_table_info {int dummy; } ;
struct TYPE_3__ {int /*<<< orphan*/  frame_filter; } ;
struct TYPE_4__ {TYPE_1__ xt; } ;

/* Variables and functions */
 int EINVAL ; 
 unsigned int FILTER_VALID_HOOKS ; 
 unsigned int ebt_do_table (struct sk_buff*,struct nf_hook_state const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int check(const struct ebt_table_info *info, unsigned int valid_hooks)
{
	if (valid_hooks & ~FILTER_VALID_HOOKS)
		return -EINVAL;
	return 0;
}

__attribute__((used)) static unsigned int
ebt_in_hook(void *priv, struct sk_buff *skb,
	    const struct nf_hook_state *state)
{
	return ebt_do_table(skb, state, state->net->xt.frame_filter);
}

__attribute__((used)) static unsigned int
ebt_out_hook(void *priv, struct sk_buff *skb,
	     const struct nf_hook_state *state)
{
	return ebt_do_table(skb, state, state->net->xt.frame_filter);
}

