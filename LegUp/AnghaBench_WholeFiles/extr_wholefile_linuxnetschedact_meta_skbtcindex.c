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
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct tcf_meta_info {int dummy; } ;
struct sk_buff {int /*<<< orphan*/  tc_index; } ;

/* Variables and functions */
 int ife_check_meta_u16 (int /*<<< orphan*/ ,struct tcf_meta_info*) ; 
 int ife_encode_meta_u16 (int /*<<< orphan*/ ,void*,struct tcf_meta_info*) ; 
 int /*<<< orphan*/  ntohs (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int skbtcindex_encode(struct sk_buff *skb, void *skbdata,
			     struct tcf_meta_info *e)
{
	u32 ifetc_index = skb->tc_index;

	return ife_encode_meta_u16(ifetc_index, skbdata, e);
}

__attribute__((used)) static int skbtcindex_decode(struct sk_buff *skb, void *data, u16 len)
{
	u16 ifetc_index = *(u16 *)data;

	skb->tc_index = ntohs(ifetc_index);
	return 0;
}

__attribute__((used)) static int skbtcindex_check(struct sk_buff *skb, struct tcf_meta_info *e)
{
	return ife_check_meta_u16(skb->tc_index, e);
}

