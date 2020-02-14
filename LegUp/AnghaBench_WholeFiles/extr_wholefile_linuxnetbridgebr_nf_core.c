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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sock {int dummy; } ;
struct sk_buff {int dummy; } ;
struct net_device {int /*<<< orphan*/  rx_handler; int /*<<< orphan*/  rx_handler_data; } ;
struct net_bridge_vlan_group {int dummy; } ;
struct net_bridge_vlan {int flags; } ;
struct net_bridge_port {int flags; } ;
struct net_bridge_mdb_entry {int dummy; } ;
struct net_bridge_fdb_entry {int dummy; } ;
struct net_bridge {int /*<<< orphan*/  designated_root; int /*<<< orphan*/  bridge_id; } ;
struct neighbour {int dummy; } ;
struct ethhdr {int dummy; } ;
struct dst_entry {TYPE_1__* dev; } ;
struct br_vlan_stats {int dummy; } ;
struct TYPE_4__ {scalar_t__ src_port_isolated; } ;
struct TYPE_3__ {unsigned int mtu; } ;

/* Variables and functions */
 int BRIDGE_VLAN_INFO_BRENTRY ; 
 int BRIDGE_VLAN_INFO_MASTER ; 
 TYPE_2__* BR_INPUT_SKB_CB (struct sk_buff const*) ; 
 int BR_ISOLATED ; 
 int EOPNOTSUPP ; 
 scalar_t__ br_handle_frame ; 
 scalar_t__ br_port_exists (struct net_device const*) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ rcu_dereference (int /*<<< orphan*/ ) ; 
 scalar_t__ rcu_dereference_rtnl (int /*<<< orphan*/ ) ; 
 struct net_bridge_port* rtnl_dereference (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct net_bridge_port *br_port_get_rcu(const struct net_device *dev)
{
	return rcu_dereference(dev->rx_handler_data);
}

__attribute__((used)) static inline struct net_bridge_port *br_port_get_rtnl(const struct net_device *dev)
{
	return br_port_exists(dev) ?
		rtnl_dereference(dev->rx_handler_data) : NULL;
}

__attribute__((used)) static inline struct net_bridge_port *br_port_get_rtnl_rcu(const struct net_device *dev)
{
	return br_port_exists(dev) ?
		rcu_dereference_rtnl(dev->rx_handler_data) : NULL;
}

__attribute__((used)) static inline int br_is_root_bridge(const struct net_bridge *br)
{
	return !memcmp(&br->bridge_id, &br->designated_root, 8);
}

__attribute__((used)) static inline bool br_vlan_is_master(const struct net_bridge_vlan *v)
{
	return v->flags & BRIDGE_VLAN_INFO_MASTER;
}

__attribute__((used)) static inline bool br_vlan_is_brentry(const struct net_bridge_vlan *v)
{
	return v->flags & BRIDGE_VLAN_INFO_BRENTRY;
}

__attribute__((used)) static inline bool br_vlan_should_use(const struct net_bridge_vlan *v)
{
	if (br_vlan_is_master(v)) {
		if (br_vlan_is_brentry(v))
			return true;
		else
			return false;
	}

	return true;
}

__attribute__((used)) static inline void br_netpoll_send_skb(const struct net_bridge_port *p,
				       struct sk_buff *skb)
{
}

__attribute__((used)) static inline int br_netpoll_enable(struct net_bridge_port *p)
{
	return 0;
}

__attribute__((used)) static inline void br_netpoll_disable(struct net_bridge_port *p)
{
}

__attribute__((used)) static inline bool br_skb_isolated(const struct net_bridge_port *to,
				   const struct sk_buff *skb)
{
	return BR_INPUT_SKB_CB(skb)->src_port_isolated &&
	       (to->flags & BR_ISOLATED);
}

__attribute__((used)) static inline bool br_rx_handler_check_rcu(const struct net_device *dev)
{
	return rcu_dereference(dev->rx_handler) == br_handle_frame;
}

__attribute__((used)) static inline bool br_rx_handler_check_rtnl(const struct net_device *dev)
{
	return rcu_dereference_rtnl(dev->rx_handler) == br_handle_frame;
}

__attribute__((used)) static inline struct net_bridge_port *br_port_get_check_rcu(const struct net_device *dev)
{
	return br_rx_handler_check_rcu(dev) ? br_port_get_rcu(dev) : NULL;
}

__attribute__((used)) static inline struct net_bridge_port *
br_port_get_check_rtnl(const struct net_device *dev)
{
	return br_rx_handler_check_rtnl(dev) ? br_port_get_rtnl_rcu(dev) : NULL;
}

__attribute__((used)) static inline int br_multicast_rcv(struct net_bridge *br,
				   struct net_bridge_port *port,
				   struct sk_buff *skb,
				   u16 vid)
{
	return 0;
}

__attribute__((used)) static inline struct net_bridge_mdb_entry *br_mdb_get(struct net_bridge *br,
						      struct sk_buff *skb, u16 vid)
{
	return NULL;
}

__attribute__((used)) static inline int br_multicast_add_port(struct net_bridge_port *port)
{
	return 0;
}

__attribute__((used)) static inline void br_multicast_del_port(struct net_bridge_port *port)
{
}

__attribute__((used)) static inline void br_multicast_enable_port(struct net_bridge_port *port)
{
}

__attribute__((used)) static inline void br_multicast_disable_port(struct net_bridge_port *port)
{
}

__attribute__((used)) static inline void br_multicast_init(struct net_bridge *br)
{
}

__attribute__((used)) static inline void br_multicast_open(struct net_bridge *br)
{
}

__attribute__((used)) static inline void br_multicast_stop(struct net_bridge *br)
{
}

__attribute__((used)) static inline void br_multicast_dev_del(struct net_bridge *br)
{
}

__attribute__((used)) static inline void br_multicast_flood(struct net_bridge_mdb_entry *mdst,
				      struct sk_buff *skb,
				      bool local_rcv, bool local_orig)
{
}

__attribute__((used)) static inline bool br_multicast_is_router(struct net_bridge *br)
{
	return false;
}

__attribute__((used)) static inline bool br_multicast_querier_exists(struct net_bridge *br,
					       struct ethhdr *eth)
{
	return false;
}

__attribute__((used)) static inline void br_mdb_init(void)
{
}

__attribute__((used)) static inline void br_mdb_uninit(void)
{
}

__attribute__((used)) static inline void br_multicast_count(struct net_bridge *br,
				      const struct net_bridge_port *p,
				      const struct sk_buff *skb,
				      u8 type, u8 dir)
{
}

__attribute__((used)) static inline int br_multicast_init_stats(struct net_bridge *br)
{
	return 0;
}

__attribute__((used)) static inline void br_multicast_uninit_stats(struct net_bridge *br)
{
}

__attribute__((used)) static inline int br_multicast_igmp_type(const struct sk_buff *skb)
{
	return 0;
}

__attribute__((used)) static inline bool br_allowed_ingress(const struct net_bridge *br,
				      struct net_bridge_vlan_group *vg,
				      struct sk_buff *skb,
				      u16 *vid)
{
	return true;
}

__attribute__((used)) static inline bool br_allowed_egress(struct net_bridge_vlan_group *vg,
				     const struct sk_buff *skb)
{
	return true;
}

__attribute__((used)) static inline bool br_should_learn(struct net_bridge_port *p,
				   struct sk_buff *skb, u16 *vid)
{
	return true;
}

__attribute__((used)) static inline struct sk_buff *br_handle_vlan(struct net_bridge *br,
					     const struct net_bridge_port *port,
					     struct net_bridge_vlan_group *vg,
					     struct sk_buff *skb)
{
	return skb;
}

__attribute__((used)) static inline int br_vlan_add(struct net_bridge *br, u16 vid, u16 flags,
			      bool *changed)
{
	*changed = false;
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int br_vlan_delete(struct net_bridge *br, u16 vid)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline void br_vlan_flush(struct net_bridge *br)
{
}

__attribute__((used)) static inline void br_recalculate_fwd_mask(struct net_bridge *br)
{
}

__attribute__((used)) static inline int br_vlan_init(struct net_bridge *br)
{
	return 0;
}

__attribute__((used)) static inline int nbp_vlan_add(struct net_bridge_port *port, u16 vid, u16 flags,
			       bool *changed)
{
	*changed = false;
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int nbp_vlan_delete(struct net_bridge_port *port, u16 vid)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline void nbp_vlan_flush(struct net_bridge_port *port)
{
}

__attribute__((used)) static inline struct net_bridge_vlan *br_vlan_find(struct net_bridge_vlan_group *vg,
						   u16 vid)
{
	return NULL;
}

__attribute__((used)) static inline int nbp_vlan_init(struct net_bridge_port *port)
{
	return 0;
}

__attribute__((used)) static inline u16 br_vlan_get_tag(const struct sk_buff *skb, u16 *tag)
{
	return 0;
}

__attribute__((used)) static inline u16 br_get_pvid(const struct net_bridge_vlan_group *vg)
{
	return 0;
}

__attribute__((used)) static inline int __br_vlan_filter_toggle(struct net_bridge *br,
					  unsigned long val)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int nbp_get_num_vlan_infos(struct net_bridge_port *p,
					 u32 filter_mask)
{
	return 0;
}

__attribute__((used)) static inline struct net_bridge_vlan_group *br_vlan_group(
					const struct net_bridge *br)
{
	return NULL;
}

__attribute__((used)) static inline struct net_bridge_vlan_group *nbp_vlan_group(
					const struct net_bridge_port *p)
{
	return NULL;
}

__attribute__((used)) static inline struct net_bridge_vlan_group *br_vlan_group_rcu(
					const struct net_bridge *br)
{
	return NULL;
}

__attribute__((used)) static inline struct net_bridge_vlan_group *nbp_vlan_group_rcu(
					const struct net_bridge_port *p)
{
	return NULL;
}

__attribute__((used)) static inline void br_vlan_get_stats(const struct net_bridge_vlan *v,
				     struct br_vlan_stats *stats)
{
}

__attribute__((used)) static inline int br_nf_core_init(void) { return 0; }

__attribute__((used)) static inline void br_nf_core_fini(void) {}

__attribute__((used)) static inline int br_sysfs_addif(struct net_bridge_port *p) { return 0; }

__attribute__((used)) static inline int br_sysfs_renameif(struct net_bridge_port *p) { return 0; }

__attribute__((used)) static inline int br_sysfs_addbr(struct net_device *dev) { return 0; }

__attribute__((used)) static inline void br_sysfs_delbr(struct net_device *dev) { return; }

__attribute__((used)) static inline int nbp_switchdev_mark_set(struct net_bridge_port *p)
{
	return 0;
}

__attribute__((used)) static inline void nbp_switchdev_frame_mark(const struct net_bridge_port *p,
					    struct sk_buff *skb)
{
}

__attribute__((used)) static inline bool nbp_switchdev_allowed_egress(const struct net_bridge_port *p,
						const struct sk_buff *skb)
{
	return true;
}

__attribute__((used)) static inline int br_switchdev_set_port_flag(struct net_bridge_port *p,
					     unsigned long flags,
					     unsigned long mask)
{
	return 0;
}

__attribute__((used)) static inline int br_switchdev_port_vlan_add(struct net_device *dev,
					     u16 vid, u16 flags)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline int br_switchdev_port_vlan_del(struct net_device *dev, u16 vid)
{
	return -EOPNOTSUPP;
}

__attribute__((used)) static inline void
br_switchdev_fdb_notify(const struct net_bridge_fdb_entry *fdb, int type)
{
}

__attribute__((used)) static inline void br_switchdev_frame_unmark(struct sk_buff *skb)
{
}

__attribute__((used)) static void fake_update_pmtu(struct dst_entry *dst, struct sock *sk,
			     struct sk_buff *skb, u32 mtu)
{
}

__attribute__((used)) static void fake_redirect(struct dst_entry *dst, struct sock *sk,
			  struct sk_buff *skb)
{
}

__attribute__((used)) static u32 *fake_cow_metrics(struct dst_entry *dst, unsigned long old)
{
	return NULL;
}

__attribute__((used)) static struct neighbour *fake_neigh_lookup(const struct dst_entry *dst,
					   struct sk_buff *skb,
					   const void *daddr)
{
	return NULL;
}

__attribute__((used)) static unsigned int fake_mtu(const struct dst_entry *dst)
{
	return dst->dev->mtu;
}

