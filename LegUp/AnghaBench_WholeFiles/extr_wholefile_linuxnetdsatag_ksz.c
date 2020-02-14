#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct sk_buff {scalar_t__ len; struct net_device* dev; scalar_t__ head; } ;
struct packet_type {int dummy; } ;
struct net_device {struct dsa_port* dsa_ptr; } ;
struct dsa_switch_tree {struct dsa_switch** ds; } ;
struct dsa_switch {int num_ports; struct dsa_port* ports; } ;
struct dsa_slave_priv {struct dsa_port* dp; } ;
struct dsa_port {scalar_t__ type; int index; TYPE_1__* cpu_dp; struct net_device* slave; struct dsa_switch_tree* dst; } ;
struct TYPE_2__ {struct net_device* master; } ;

/* Variables and functions */
 int DSA_MAX_SWITCHES ; 
 scalar_t__ DSA_PORT_TYPE_USER ; 
 scalar_t__ ETH_ZLEN ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  KSZ_EGRESS_TAG_LEN ; 
 scalar_t__ KSZ_INGRESS_TAG_LEN ; 
 scalar_t__ NET_IP_ALIGN ; 
 scalar_t__ __skb_put_padto (struct sk_buff*,scalar_t__,int) ; 
 struct sk_buff* alloc_skb (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  consume_skb (struct sk_buff*) ; 
 struct dsa_slave_priv* netdev_priv (struct net_device const*) ; 
 int /*<<< orphan*/  pskb_trim_rcsum (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_copy_and_csum_dev (struct sk_buff*,int*) ; 
 scalar_t__ skb_network_header (struct sk_buff*) ; 
 int* skb_put (struct sk_buff*,scalar_t__) ; 
 scalar_t__ skb_put_padto (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_set_network_header (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_set_transport_header (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_tail_pointer (struct sk_buff*) ; 
 scalar_t__ skb_tailroom (struct sk_buff*) ; 
 scalar_t__ skb_transport_header (struct sk_buff*) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline int dsa_legacy_register(void)
{
	return 0;
}

__attribute__((used)) static inline void dsa_legacy_unregister(void) { }

__attribute__((used)) static inline struct net_device *dsa_master_find_slave(struct net_device *dev,
						       int device, int port)
{
	struct dsa_port *cpu_dp = dev->dsa_ptr;
	struct dsa_switch_tree *dst = cpu_dp->dst;
	struct dsa_switch *ds;
	struct dsa_port *slave_port;

	if (device < 0 || device >= DSA_MAX_SWITCHES)
		return NULL;

	ds = dst->ds[device];
	if (!ds)
		return NULL;

	if (port < 0 || port >= ds->num_ports)
		return NULL;

	slave_port = &ds->ports[port];

	if (unlikely(slave_port->type != DSA_PORT_TYPE_USER))
		return NULL;

	return slave_port->slave;
}

__attribute__((used)) static inline struct dsa_port *dsa_slave_to_port(const struct net_device *dev)
{
	struct dsa_slave_priv *p = netdev_priv(dev);

	return p->dp;
}

__attribute__((used)) static inline struct net_device *
dsa_slave_to_master(const struct net_device *dev)
{
	struct dsa_port *dp = dsa_slave_to_port(dev);

	return dp->cpu_dp->master;
}

__attribute__((used)) static struct sk_buff *ksz_xmit(struct sk_buff *skb, struct net_device *dev)
{
	struct dsa_port *dp = dsa_slave_to_port(dev);
	struct sk_buff *nskb;
	int padlen;
	u8 *tag;

	padlen = (skb->len >= ETH_ZLEN) ? 0 : ETH_ZLEN - skb->len;

	if (skb_tailroom(skb) >= padlen + KSZ_INGRESS_TAG_LEN) {
		/* Let dsa_slave_xmit() free skb */
		if (__skb_put_padto(skb, skb->len + padlen, false))
			return NULL;

		nskb = skb;
	} else {
		nskb = alloc_skb(NET_IP_ALIGN + skb->len +
				 padlen + KSZ_INGRESS_TAG_LEN, GFP_ATOMIC);
		if (!nskb)
			return NULL;
		skb_reserve(nskb, NET_IP_ALIGN);

		skb_reset_mac_header(nskb);
		skb_set_network_header(nskb,
				       skb_network_header(skb) - skb->head);
		skb_set_transport_header(nskb,
					 skb_transport_header(skb) - skb->head);
		skb_copy_and_csum_dev(skb, skb_put(nskb, skb->len));

		/* Let skb_put_padto() free nskb, and let dsa_slave_xmit() free
		 * skb
		 */
		if (skb_put_padto(nskb, nskb->len + padlen))
			return NULL;

		consume_skb(skb);
	}

	tag = skb_put(nskb, KSZ_INGRESS_TAG_LEN);
	tag[0] = 0;
	tag[1] = 1 << dp->index; /* destination port */

	return nskb;
}

__attribute__((used)) static struct sk_buff *ksz_rcv(struct sk_buff *skb, struct net_device *dev,
			       struct packet_type *pt)
{
	u8 *tag;
	int source_port;

	tag = skb_tail_pointer(skb) - KSZ_EGRESS_TAG_LEN;

	source_port = tag[0] & 7;

	skb->dev = dsa_master_find_slave(dev, 0, source_port);
	if (!skb->dev)
		return NULL;

	pskb_trim_rcsum(skb, skb->len - KSZ_EGRESS_TAG_LEN);

	return skb;
}

