#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct xt_tgchk_param {int hook_mask; int /*<<< orphan*/  table; struct ebt_nat_info* targinfo; } ;
struct xt_action_param {struct ebt_nat_info* targinfo; } ;
struct sk_buff {int /*<<< orphan*/  pkt_type; } ;
struct net_device {int /*<<< orphan*/  dev_addr; int /*<<< orphan*/  rx_handler; int /*<<< orphan*/  rx_handler_data; } ;
struct net_bridge_vlan_group {int dummy; } ;
struct net_bridge_vlan {int flags; } ;
struct net_bridge_port {int flags; TYPE_1__* br; } ;
struct net_bridge_mdb_entry {int dummy; } ;
struct net_bridge_fdb_entry {int dummy; } ;
struct net_bridge {int /*<<< orphan*/  designated_root; int /*<<< orphan*/  bridge_id; } ;
struct ethhdr {int dummy; } ;
struct ebt_nat_info {unsigned int target; int /*<<< orphan*/  mac; } ;
struct br_vlan_stats {int dummy; } ;
struct TYPE_6__ {scalar_t__ src_port_isolated; } ;
struct TYPE_5__ {int /*<<< orphan*/  h_dest; } ;
struct TYPE_4__ {struct net_device* dev; } ;

/* Variables and functions */
 scalar_t__ BASE_CHAIN ; 
 int BRIDGE_VLAN_INFO_BRENTRY ; 
 int BRIDGE_VLAN_INFO_MASTER ; 
 TYPE_3__* BR_INPUT_SKB_CB (struct sk_buff const*) ; 
 int BR_ISOLATED ; 
 unsigned int EBT_DROP ; 
 scalar_t__ EBT_RETURN ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int NF_BR_BROUTING ; 
 int NF_BR_LOCAL_OUT ; 
 int NF_BR_NUMHOOKS ; 
 int NF_BR_PRE_ROUTING ; 
 int /*<<< orphan*/  PACKET_BROADCAST ; 
 int /*<<< orphan*/  PACKET_HOST ; 
 int /*<<< orphan*/  PACKET_MULTICAST ; 
 int /*<<< orphan*/  PACKET_OTHERHOST ; 
 scalar_t__ br_handle_frame ; 
 scalar_t__ br_port_exists (struct net_device const*) ; 
 scalar_t__ ebt_invalid_target (scalar_t__) ; 
 TYPE_2__* eth_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  ether_addr_copy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ ether_addr_equal (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ is_broadcast_ether_addr (int /*<<< orphan*/ ) ; 
 scalar_t__ is_multicast_ether_addr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ rcu_dereference (int /*<<< orphan*/ ) ; 
 scalar_t__ rcu_dereference_rtnl (int /*<<< orphan*/ ) ; 
 struct net_bridge_port* rtnl_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_make_writable (struct sk_buff*,int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 int xt_hooknum (struct xt_action_param const*) ; 
 void* xt_in (struct xt_action_param const*) ; 

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

__attribute__((used)) static unsigned int
ebt_dnat_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
	const struct ebt_nat_info *info = par->targinfo;
	struct net_device *dev;

	if (!skb_make_writable(skb, 0))
		return EBT_DROP;

	ether_addr_copy(eth_hdr(skb)->h_dest, info->mac);

	if (is_multicast_ether_addr(info->mac)) {
		if (is_broadcast_ether_addr(info->mac))
			skb->pkt_type = PACKET_BROADCAST;
		else
			skb->pkt_type = PACKET_MULTICAST;
	} else {
		if (xt_hooknum(par) != NF_BR_BROUTING)
			dev = br_port_get_rcu(xt_in(par))->br->dev;
		else
			dev = xt_in(par);

		if (ether_addr_equal(info->mac, dev->dev_addr))
			skb->pkt_type = PACKET_HOST;
		else
			skb->pkt_type = PACKET_OTHERHOST;
	}

	return info->target;
}

__attribute__((used)) static int ebt_dnat_tg_check(const struct xt_tgchk_param *par)
{
	const struct ebt_nat_info *info = par->targinfo;
	unsigned int hook_mask;

	if (BASE_CHAIN && info->target == EBT_RETURN)
		return -EINVAL;

	hook_mask = par->hook_mask & ~(1 << NF_BR_NUMHOOKS);
	if ((strcmp(par->table, "nat") != 0 ||
	    (hook_mask & ~((1 << NF_BR_PRE_ROUTING) |
	    (1 << NF_BR_LOCAL_OUT)))) &&
	    (strcmp(par->table, "broute") != 0 ||
	    hook_mask & ~(1 << NF_BR_BROUTING)))
		return -EINVAL;
	if (ebt_invalid_target(info->target))
		return -EINVAL;
	return 0;
}

