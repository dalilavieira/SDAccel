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
struct xt_action_param {int dummy; } ;
struct sk_buff {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static bool
comment_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
	/* We always match */
	return true;
}

