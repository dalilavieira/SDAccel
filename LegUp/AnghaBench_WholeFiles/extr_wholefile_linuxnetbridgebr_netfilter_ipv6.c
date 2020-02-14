#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sock {int dummy; } ;
typedef  struct sk_buff {unsigned char* data; scalar_t__ len; struct net_device* dev; int /*<<< orphan*/  protocol; int /*<<< orphan*/  nf_bridge; int /*<<< orphan*/  pkt_type; } const sk_buff ;
struct rtable {int /*<<< orphan*/  dst; } ;
struct nf_ipv6_ops {int /*<<< orphan*/  (* route_input ) (struct sk_buff const*) ;} ;
struct nf_hook_state {int /*<<< orphan*/  sk; struct net* net; } ;
struct nf_bridge_info {int pkt_otherhost; int /*<<< orphan*/  ipv6_daddr; struct net_device* physindev; scalar_t__ in_prerouting; int /*<<< orphan*/  frag_max_size; } ;
struct net_device {int /*<<< orphan*/  dev_addr; int /*<<< orphan*/  rx_handler; int /*<<< orphan*/  rx_handler_data; } ;
struct net_bridge_vlan_group {int dummy; } ;
struct net_bridge_vlan {int flags; } ;
struct net_bridge_port {int flags; } ;
struct net_bridge_mdb_entry {int dummy; } ;
struct net_bridge_fdb_entry {int dummy; } ;
struct net_bridge {int /*<<< orphan*/  designated_root; int /*<<< orphan*/  bridge_id; } ;
struct net {int dummy; } ;
struct ipv6hdr {int version; scalar_t__ nexthdr; int /*<<< orphan*/  daddr; int /*<<< orphan*/  payload_len; } ;
struct inet6_skb_parm {int dummy; } ;
struct inet6_dev {int dummy; } ;
struct ethhdr {int dummy; } ;
struct br_vlan_stats {int dummy; } ;
typedef  int /*<<< orphan*/  __be32 ;
struct TYPE_9__ {scalar_t__ src_port_isolated; } ;
struct TYPE_8__ {int /*<<< orphan*/  h_dest; } ;
struct TYPE_7__ {int /*<<< orphan*/  frag_max_size; } ;
struct TYPE_6__ {struct net_device* dev; scalar_t__ error; } ;

/* Variables and functions */
 int BRIDGE_VLAN_INFO_BRENTRY ; 
 int BRIDGE_VLAN_INFO_MASTER ; 
 TYPE_5__* BR_INPUT_SKB_CB (struct sk_buff const*) ; 
 int BR_ISOLATED ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  ETH_P_IPV6 ; 
 TYPE_2__* IP6CB (struct sk_buff const*) ; 
 int /*<<< orphan*/  IPSTATS_MIB_INDISCARDS ; 
 int /*<<< orphan*/  IPSTATS_MIB_INHDRERRORS ; 
 int /*<<< orphan*/  IPSTATS_MIB_INTRUNCATEDPKTS ; 
 scalar_t__ IPV6_MAXPLEN ; 
#define  IPV6_TLV_JUMBO 130 
#define  IPV6_TLV_PAD1 129 
#define  IPV6_TLV_PADN 128 
 scalar_t__ NEXTHDR_HOP ; 
 int /*<<< orphan*/  NFPROTO_IPV6 ; 
 int /*<<< orphan*/  NF_BR_PRE_ROUTING ; 
 unsigned int NF_DROP ; 
 int /*<<< orphan*/  NF_HOOK (int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct net*,int /*<<< orphan*/ ,struct sk_buff const*,struct net_device*,int /*<<< orphan*/ *,int (*) (struct net*,struct sock*,struct sk_buff const*)) ; 
 int /*<<< orphan*/  NF_INET_PRE_ROUTING ; 
 unsigned int NF_STOLEN ; 
 int /*<<< orphan*/  PACKET_HOST ; 
 int /*<<< orphan*/  PACKET_OTHERHOST ; 
 int /*<<< orphan*/  __IP6_INC_STATS (struct net*,struct inet6_dev*,int /*<<< orphan*/ ) ; 
 struct inet6_dev* __in6_dev_get (struct net_device*) ; 
 scalar_t__ br_handle_frame ; 
 int /*<<< orphan*/  br_handle_frame_finish ; 
 int /*<<< orphan*/  br_nf_hook_thresh (int /*<<< orphan*/ ,struct net*,struct sock*,struct sk_buff const*,struct net_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  br_nf_pre_routing_finish_bridge ; 
 scalar_t__ br_port_exists (struct net_device const*) ; 
 struct rtable* bridge_parent_rtable (struct net_device*) ; 
 TYPE_3__* eth_hdr (struct sk_buff const*) ; 
 int /*<<< orphan*/  ether_addr_copy (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 struct ipv6hdr* ipv6_hdr (struct sk_buff const*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff const*) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nf_bridge_alloc (struct sk_buff const*) ; 
 struct nf_bridge_info* nf_bridge_info_get (struct sk_buff const*) ; 
 int /*<<< orphan*/  nf_bridge_push_encap_header (struct sk_buff const*) ; 
 int /*<<< orphan*/  nf_bridge_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nf_bridge_update_protocol (struct sk_buff const*) ; 
 struct nf_ipv6_ops* nf_get_ipv6_ops () ; 
 scalar_t__ ntohl (int /*<<< orphan*/ ) ; 
 scalar_t__ ntohs (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff const*,scalar_t__) ; 
 scalar_t__ pskb_trim_rcsum (struct sk_buff const*,scalar_t__) ; 
 scalar_t__ rcu_dereference (int /*<<< orphan*/ ) ; 
 scalar_t__ rcu_dereference_rtnl (int /*<<< orphan*/ ) ; 
 struct net_bridge_port* rtnl_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  setup_pre_routing (struct sk_buff const*) ; 
 TYPE_1__* skb_dst (struct sk_buff const*) ; 
 int /*<<< orphan*/  skb_dst_drop (struct sk_buff const*) ; 
 int /*<<< orphan*/  skb_dst_set_noref (struct sk_buff const*,int /*<<< orphan*/ *) ; 
 int skb_headlen (struct sk_buff const*) ; 
 unsigned char* skb_network_header (struct sk_buff const*) ; 
 int /*<<< orphan*/  stub1 (struct sk_buff const*) ; 

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

__attribute__((used)) static int br_nf_check_hbh_len(struct sk_buff *skb)
{
	unsigned char *raw = (u8 *)(ipv6_hdr(skb) + 1);
	u32 pkt_len;
	const unsigned char *nh = skb_network_header(skb);
	int off = raw - nh;
	int len = (raw[1] + 1) << 3;

	if ((raw + len) - skb->data > skb_headlen(skb))
		goto bad;

	off += 2;
	len -= 2;

	while (len > 0) {
		int optlen = nh[off + 1] + 2;

		switch (nh[off]) {
		case IPV6_TLV_PAD1:
			optlen = 1;
			break;

		case IPV6_TLV_PADN:
			break;

		case IPV6_TLV_JUMBO:
			if (nh[off + 1] != 4 || (off & 3) != 2)
				goto bad;
			pkt_len = ntohl(*(__be32 *)(nh + off + 2));
			if (pkt_len <= IPV6_MAXPLEN ||
			    ipv6_hdr(skb)->payload_len)
				goto bad;
			if (pkt_len > skb->len - sizeof(struct ipv6hdr))
				goto bad;
			if (pskb_trim_rcsum(skb,
					    pkt_len + sizeof(struct ipv6hdr)))
				goto bad;
			nh = skb_network_header(skb);
			break;
		default:
			if (optlen > len)
				goto bad;
			break;
		}
		off += optlen;
		len -= optlen;
	}
	if (len == 0)
		return 0;
bad:
	return -1;
}

int br_validate_ipv6(struct net *net, struct sk_buff *skb)
{
	const struct ipv6hdr *hdr;
	struct inet6_dev *idev = __in6_dev_get(skb->dev);
	u32 pkt_len;
	u8 ip6h_len = sizeof(struct ipv6hdr);

	if (!pskb_may_pull(skb, ip6h_len))
		goto inhdr_error;

	if (skb->len < ip6h_len)
		goto drop;

	hdr = ipv6_hdr(skb);

	if (hdr->version != 6)
		goto inhdr_error;

	pkt_len = ntohs(hdr->payload_len);

	if (pkt_len || hdr->nexthdr != NEXTHDR_HOP) {
		if (pkt_len + ip6h_len > skb->len) {
			__IP6_INC_STATS(net, idev,
					IPSTATS_MIB_INTRUNCATEDPKTS);
			goto drop;
		}
		if (pskb_trim_rcsum(skb, pkt_len + ip6h_len)) {
			__IP6_INC_STATS(net, idev,
					IPSTATS_MIB_INDISCARDS);
			goto drop;
		}
		hdr = ipv6_hdr(skb);
	}
	if (hdr->nexthdr == NEXTHDR_HOP && br_nf_check_hbh_len(skb))
		goto drop;

	memset(IP6CB(skb), 0, sizeof(struct inet6_skb_parm));
	/* No IP options in IPv6 header; however it should be
	 * checked if some next headers need special treatment
	 */
	return 0;

inhdr_error:
	__IP6_INC_STATS(net, idev, IPSTATS_MIB_INHDRERRORS);
drop:
	return -1;
}

__attribute__((used)) static inline bool
br_nf_ipv6_daddr_was_changed(const struct sk_buff *skb,
			     const struct nf_bridge_info *nf_bridge)
{
	return memcmp(&nf_bridge->ipv6_daddr, &ipv6_hdr(skb)->daddr,
		      sizeof(ipv6_hdr(skb)->daddr)) != 0;
}

__attribute__((used)) static int br_nf_pre_routing_finish_ipv6(struct net *net, struct sock *sk, struct sk_buff *skb)
{
	struct nf_bridge_info *nf_bridge = nf_bridge_info_get(skb);
	struct rtable *rt;
	struct net_device *dev = skb->dev;
	const struct nf_ipv6_ops *v6ops = nf_get_ipv6_ops();

	nf_bridge->frag_max_size = IP6CB(skb)->frag_max_size;

	if (nf_bridge->pkt_otherhost) {
		skb->pkt_type = PACKET_OTHERHOST;
		nf_bridge->pkt_otherhost = false;
	}
	nf_bridge->in_prerouting = 0;
	if (br_nf_ipv6_daddr_was_changed(skb, nf_bridge)) {
		skb_dst_drop(skb);
		v6ops->route_input(skb);

		if (skb_dst(skb)->error) {
			kfree_skb(skb);
			return 0;
		}

		if (skb_dst(skb)->dev == dev) {
			skb->dev = nf_bridge->physindev;
			nf_bridge_update_protocol(skb);
			nf_bridge_push_encap_header(skb);
			br_nf_hook_thresh(NF_BR_PRE_ROUTING,
					  net, sk, skb, skb->dev, NULL,
					  br_nf_pre_routing_finish_bridge);
			return 0;
		}
		ether_addr_copy(eth_hdr(skb)->h_dest, dev->dev_addr);
		skb->pkt_type = PACKET_HOST;
	} else {
		rt = bridge_parent_rtable(nf_bridge->physindev);
		if (!rt) {
			kfree_skb(skb);
			return 0;
		}
		skb_dst_set_noref(skb, &rt->dst);
	}

	skb->dev = nf_bridge->physindev;
	nf_bridge_update_protocol(skb);
	nf_bridge_push_encap_header(skb);
	br_nf_hook_thresh(NF_BR_PRE_ROUTING, net, sk, skb,
			  skb->dev, NULL, br_handle_frame_finish);

	return 0;
}

unsigned int br_nf_pre_routing_ipv6(void *priv,
				    struct sk_buff *skb,
				    const struct nf_hook_state *state)
{
	struct nf_bridge_info *nf_bridge;

	if (br_validate_ipv6(state->net, skb))
		return NF_DROP;

	nf_bridge_put(skb->nf_bridge);
	if (!nf_bridge_alloc(skb))
		return NF_DROP;
	if (!setup_pre_routing(skb))
		return NF_DROP;

	nf_bridge = nf_bridge_info_get(skb);
	nf_bridge->ipv6_daddr = ipv6_hdr(skb)->daddr;

	skb->protocol = htons(ETH_P_IPV6);
	NF_HOOK(NFPROTO_IPV6, NF_INET_PRE_ROUTING, state->net, state->sk, skb,
		skb->dev, NULL,
		br_nf_pre_routing_finish_ipv6);

	return NF_STOLEN;
}

