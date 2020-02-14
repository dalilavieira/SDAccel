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
typedef  int u32 ;
typedef  int u16 ;
struct tipc_topsrv {int dummy; } ;
struct list_head {int dummy; } ;
struct tipc_net {int net_id; struct tipc_topsrv* topsrv; struct name_table* nametbl; struct list_head node_list; } ;
struct net {int dummy; } ;
struct name_table {int dummy; } ;

/* Variables and functions */
 int NODE_HTABLE_SIZE ; 
 struct tipc_net* net_generic (struct net*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  tipc_net_id ; 

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

