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
struct sk_buff {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  IPPROTO_UDPLITE ; 
 int /*<<< orphan*/  __udp4_lib_err (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int __udp4_lib_rcv (struct sk_buff*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  udplite_table ; 

__attribute__((used)) static int udplite_rcv(struct sk_buff *skb)
{
	return __udp4_lib_rcv(skb, &udplite_table, IPPROTO_UDPLITE);
}

__attribute__((used)) static void udplite_err(struct sk_buff *skb, u32 info)
{
	__udp4_lib_err(skb, info, &udplite_table);
}

__attribute__((used)) static inline int udplite4_proc_init(void)
{
	return 0;
}

