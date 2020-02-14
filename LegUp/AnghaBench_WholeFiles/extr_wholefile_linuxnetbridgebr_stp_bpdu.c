#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_7__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct stp_proto {int dummy; } ;
struct sock {int dummy; } ;
struct sk_buff {unsigned char* data; TYPE_5__* dev; int /*<<< orphan*/  priority; int /*<<< orphan*/  protocol; } ;
struct net_device {int /*<<< orphan*/  rx_handler; int /*<<< orphan*/  rx_handler_data; } ;
struct net_bridge_vlan_group {int dummy; } ;
struct net_bridge_vlan {int flags; } ;
struct net_bridge_port {int flags; scalar_t__ designated_port; scalar_t__ port_id; scalar_t__ state; scalar_t__ port_no; struct net_bridge* br; TYPE_5__* dev; int /*<<< orphan*/  designated_bridge; } ;
struct net_bridge_mdb_entry {int dummy; } ;
struct net_bridge_fdb_entry {int dummy; } ;
struct net_bridge {scalar_t__ stp_enabled; int /*<<< orphan*/  lock; int /*<<< orphan*/  group_addr; TYPE_1__* dev; int /*<<< orphan*/  bridge_id; int /*<<< orphan*/  designated_root; } ;
struct net {int dummy; } ;
struct ethhdr {int dummy; } ;
struct br_vlan_stats {int dummy; } ;
struct TYPE_10__ {unsigned char* prio; unsigned char* addr; } ;
struct TYPE_9__ {unsigned char* prio; unsigned char* addr; } ;
struct br_config_bpdu {int topology_change; int topology_change_ack; int root_path_cost; int port_id; int message_age; int max_age; int hello_time; int forward_delay; TYPE_3__ bridge_id; TYPE_2__ root; } ;
struct TYPE_13__ {scalar_t__ src_port_isolated; } ;
struct TYPE_12__ {int /*<<< orphan*/  name; int /*<<< orphan*/  dev_addr; } ;
struct TYPE_11__ {unsigned char* h_dest; int /*<<< orphan*/  h_source; } ;
struct TYPE_8__ {int flags; } ;

/* Variables and functions */
 unsigned char const BPDU_TYPE_CONFIG ; 
 unsigned char const BPDU_TYPE_TCN ; 
 int BRIDGE_VLAN_INFO_BRENTRY ; 
 int BRIDGE_VLAN_INFO_MASTER ; 
 int BR_BPDU_GUARD ; 
 TYPE_7__* BR_INPUT_SKB_CB (struct sk_buff const*) ; 
 int BR_ISOLATED ; 
 scalar_t__ BR_KERNEL_STP ; 
 scalar_t__ BR_STATE_DISABLED ; 
 int DIV_ROUND_UP (unsigned long,int) ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  ETH_P_802_2 ; 
 int HZ ; 
 int IFF_UP ; 
 int /*<<< orphan*/  LLC_PDU_CMD ; 
 int /*<<< orphan*/  LLC_PDU_TYPE_U ; 
 scalar_t__ LLC_RESERVE ; 
 int /*<<< orphan*/  LLC_SAP_BSPAN ; 
 int /*<<< orphan*/  NFPROTO_BRIDGE ; 
 int /*<<< orphan*/  NF_BR_LOCAL_OUT ; 
 int /*<<< orphan*/  NF_HOOK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,struct sk_buff*,int /*<<< orphan*/ *,TYPE_5__*,int (*) (struct net*,struct sock*,struct sk_buff*)) ; 
 int STP_HZ ; 
 int /*<<< orphan*/  TC_PRIO_CONTROL ; 
 int /*<<< orphan*/  __skb_put_data (struct sk_buff*,unsigned char const*,int) ; 
 scalar_t__ br_handle_frame ; 
 int /*<<< orphan*/  br_notice (struct net_bridge*,char*,unsigned int,int /*<<< orphan*/ ,...) ; 
 scalar_t__ br_port_exists (struct net_device const*) ; 
 int /*<<< orphan*/  br_received_config_bpdu (struct net_bridge_port*,struct br_config_bpdu*) ; 
 int /*<<< orphan*/  br_received_tcn_bpdu (struct net_bridge_port*) ; 
 int /*<<< orphan*/  br_stp_disable_port (struct net_bridge_port*) ; 
 struct sk_buff* dev_alloc_skb (scalar_t__) ; 
 int /*<<< orphan*/  dev_net (TYPE_5__*) ; 
 int dev_queue_xmit (struct sk_buff*) ; 
 TYPE_4__* eth_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  ether_addr_equal (unsigned char const*,int /*<<< orphan*/ ) ; 
 unsigned long get_unaligned_be16 (unsigned char const*) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  llc_mac_hdr_init (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  llc_pdu_header_init (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  llc_pdu_init_as_ui_cmd (struct sk_buff*) ; 
 int /*<<< orphan*/  memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 scalar_t__ net_ratelimit () ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  put_unaligned_be16 (unsigned long,unsigned char*) ; 
 scalar_t__ rcu_dereference (int /*<<< orphan*/ ) ; 
 scalar_t__ rcu_dereference_rtnl (int /*<<< orphan*/ ) ; 
 struct net_bridge_port* rtnl_dereference (int /*<<< orphan*/ ) ; 
 unsigned char* skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 

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

__attribute__((used)) static inline int br_is_designated_port(const struct net_bridge_port *p)
{
	return !memcmp(&p->designated_bridge, &p->br->bridge_id, 8) &&
		(p->designated_port == p->port_id);
}

__attribute__((used)) static int br_send_bpdu_finish(struct net *net, struct sock *sk,
			       struct sk_buff *skb)
{
	return dev_queue_xmit(skb);
}

__attribute__((used)) static void br_send_bpdu(struct net_bridge_port *p,
			 const unsigned char *data, int length)
{
	struct sk_buff *skb;

	skb = dev_alloc_skb(length+LLC_RESERVE);
	if (!skb)
		return;

	skb->dev = p->dev;
	skb->protocol = htons(ETH_P_802_2);
	skb->priority = TC_PRIO_CONTROL;

	skb_reserve(skb, LLC_RESERVE);
	__skb_put_data(skb, data, length);

	llc_pdu_header_init(skb, LLC_PDU_TYPE_U, LLC_SAP_BSPAN,
			    LLC_SAP_BSPAN, LLC_PDU_CMD);
	llc_pdu_init_as_ui_cmd(skb);

	llc_mac_hdr_init(skb, p->dev->dev_addr, p->br->group_addr);

	skb_reset_mac_header(skb);

	NF_HOOK(NFPROTO_BRIDGE, NF_BR_LOCAL_OUT,
		dev_net(p->dev), NULL, skb, NULL, skb->dev,
		br_send_bpdu_finish);
}

__attribute__((used)) static inline void br_set_ticks(unsigned char *dest, int j)
{
	unsigned long ticks = (STP_HZ * j)/ HZ;

	put_unaligned_be16(ticks, dest);
}

__attribute__((used)) static inline int br_get_ticks(const unsigned char *src)
{
	unsigned long ticks = get_unaligned_be16(src);

	return DIV_ROUND_UP(ticks * HZ, STP_HZ);
}

void br_send_config_bpdu(struct net_bridge_port *p, struct br_config_bpdu *bpdu)
{
	unsigned char buf[35];

	if (p->br->stp_enabled != BR_KERNEL_STP)
		return;

	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 0;
	buf[3] = BPDU_TYPE_CONFIG;
	buf[4] = (bpdu->topology_change ? 0x01 : 0) |
		(bpdu->topology_change_ack ? 0x80 : 0);
	buf[5] = bpdu->root.prio[0];
	buf[6] = bpdu->root.prio[1];
	buf[7] = bpdu->root.addr[0];
	buf[8] = bpdu->root.addr[1];
	buf[9] = bpdu->root.addr[2];
	buf[10] = bpdu->root.addr[3];
	buf[11] = bpdu->root.addr[4];
	buf[12] = bpdu->root.addr[5];
	buf[13] = (bpdu->root_path_cost >> 24) & 0xFF;
	buf[14] = (bpdu->root_path_cost >> 16) & 0xFF;
	buf[15] = (bpdu->root_path_cost >> 8) & 0xFF;
	buf[16] = bpdu->root_path_cost & 0xFF;
	buf[17] = bpdu->bridge_id.prio[0];
	buf[18] = bpdu->bridge_id.prio[1];
	buf[19] = bpdu->bridge_id.addr[0];
	buf[20] = bpdu->bridge_id.addr[1];
	buf[21] = bpdu->bridge_id.addr[2];
	buf[22] = bpdu->bridge_id.addr[3];
	buf[23] = bpdu->bridge_id.addr[4];
	buf[24] = bpdu->bridge_id.addr[5];
	buf[25] = (bpdu->port_id >> 8) & 0xFF;
	buf[26] = bpdu->port_id & 0xFF;

	br_set_ticks(buf+27, bpdu->message_age);
	br_set_ticks(buf+29, bpdu->max_age);
	br_set_ticks(buf+31, bpdu->hello_time);
	br_set_ticks(buf+33, bpdu->forward_delay);

	br_send_bpdu(p, buf, 35);
}

void br_send_tcn_bpdu(struct net_bridge_port *p)
{
	unsigned char buf[4];

	if (p->br->stp_enabled != BR_KERNEL_STP)
		return;

	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 0;
	buf[3] = BPDU_TYPE_TCN;
	br_send_bpdu(p, buf, 4);
}

void br_stp_rcv(const struct stp_proto *proto, struct sk_buff *skb,
		struct net_device *dev)
{
	const unsigned char *dest = eth_hdr(skb)->h_dest;
	struct net_bridge_port *p;
	struct net_bridge *br;
	const unsigned char *buf;

	if (!pskb_may_pull(skb, 4))
		goto err;

	/* compare of protocol id and version */
	buf = skb->data;
	if (buf[0] != 0 || buf[1] != 0 || buf[2] != 0)
		goto err;

	p = br_port_get_check_rcu(dev);
	if (!p)
		goto err;

	br = p->br;
	spin_lock(&br->lock);

	if (br->stp_enabled != BR_KERNEL_STP)
		goto out;

	if (!(br->dev->flags & IFF_UP))
		goto out;

	if (p->state == BR_STATE_DISABLED)
		goto out;

	if (!ether_addr_equal(dest, br->group_addr))
		goto out;

	if (p->flags & BR_BPDU_GUARD) {
		br_notice(br, "BPDU received on blocked port %u(%s)\n",
			  (unsigned int) p->port_no, p->dev->name);
		br_stp_disable_port(p);
		goto out;
	}

	buf = skb_pull(skb, 3);

	if (buf[0] == BPDU_TYPE_CONFIG) {
		struct br_config_bpdu bpdu;

		if (!pskb_may_pull(skb, 32))
			goto out;

		buf = skb->data;
		bpdu.topology_change = (buf[1] & 0x01) ? 1 : 0;
		bpdu.topology_change_ack = (buf[1] & 0x80) ? 1 : 0;

		bpdu.root.prio[0] = buf[2];
		bpdu.root.prio[1] = buf[3];
		bpdu.root.addr[0] = buf[4];
		bpdu.root.addr[1] = buf[5];
		bpdu.root.addr[2] = buf[6];
		bpdu.root.addr[3] = buf[7];
		bpdu.root.addr[4] = buf[8];
		bpdu.root.addr[5] = buf[9];
		bpdu.root_path_cost =
			(buf[10] << 24) |
			(buf[11] << 16) |
			(buf[12] << 8) |
			buf[13];
		bpdu.bridge_id.prio[0] = buf[14];
		bpdu.bridge_id.prio[1] = buf[15];
		bpdu.bridge_id.addr[0] = buf[16];
		bpdu.bridge_id.addr[1] = buf[17];
		bpdu.bridge_id.addr[2] = buf[18];
		bpdu.bridge_id.addr[3] = buf[19];
		bpdu.bridge_id.addr[4] = buf[20];
		bpdu.bridge_id.addr[5] = buf[21];
		bpdu.port_id = (buf[22] << 8) | buf[23];

		bpdu.message_age = br_get_ticks(buf+24);
		bpdu.max_age = br_get_ticks(buf+26);
		bpdu.hello_time = br_get_ticks(buf+28);
		bpdu.forward_delay = br_get_ticks(buf+30);

		if (bpdu.message_age > bpdu.max_age) {
			if (net_ratelimit())
				br_notice(p->br,
					  "port %u config from %pM"
					  " (message_age %ul > max_age %ul)\n",
					  p->port_no,
					  eth_hdr(skb)->h_source,
					  bpdu.message_age, bpdu.max_age);
			goto out;
		}

		br_received_config_bpdu(p, &bpdu);
	} else if (buf[0] == BPDU_TYPE_TCN) {
		br_received_tcn_bpdu(p);
	}
 out:
	spin_unlock(&br->lock);
 err:
	kfree_skb(skb);
}

