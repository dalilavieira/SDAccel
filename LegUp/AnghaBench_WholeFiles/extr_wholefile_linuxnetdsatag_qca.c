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
typedef  int u8 ;
typedef  int u16 ;
struct sk_buff {int data; struct net_device* dev; scalar_t__ len; } ;
struct packet_type {int dummy; } ;
struct TYPE_4__ {int /*<<< orphan*/  tx_bytes; int /*<<< orphan*/  tx_packets; } ;
struct net_device {TYPE_2__ stats; struct dsa_port* dsa_ptr; } ;
struct dsa_switch_tree {struct dsa_switch** ds; } ;
struct dsa_switch {int num_ports; struct dsa_port* ports; } ;
struct dsa_slave_priv {struct dsa_port* dp; } ;
struct dsa_port {scalar_t__ type; int /*<<< orphan*/  index; TYPE_1__* cpu_dp; struct net_device* slave; struct dsa_switch_tree* dst; } ;
typedef  int __be16 ;
struct TYPE_3__ {struct net_device* master; } ;

/* Variables and functions */
 int BIT (int /*<<< orphan*/ ) ; 
 int DSA_MAX_SWITCHES ; 
 scalar_t__ DSA_PORT_TYPE_USER ; 
 int ETH_ALEN ; 
 int ETH_HLEN ; 
 int QCA_HDR_LEN ; 
 int QCA_HDR_RECV_SOURCE_PORT_MASK ; 
 int QCA_HDR_RECV_VERSION_MASK ; 
 int QCA_HDR_RECV_VERSION_S ; 
 int QCA_HDR_VERSION ; 
 int QCA_HDR_XMIT_FROM_CPU ; 
 int QCA_HDR_XMIT_VERSION_S ; 
 int htons (int) ; 
 int /*<<< orphan*/  memmove (int,int,int) ; 
 struct dsa_slave_priv* netdev_priv (struct net_device const*) ; 
 int ntohs (int) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 scalar_t__ skb_cow_head (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_pull_rcsum (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,int) ; 
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

__attribute__((used)) static struct sk_buff *qca_tag_xmit(struct sk_buff *skb, struct net_device *dev)
{
	struct dsa_port *dp = dsa_slave_to_port(dev);
	u16 *phdr, hdr;

	dev->stats.tx_packets++;
	dev->stats.tx_bytes += skb->len;

	if (skb_cow_head(skb, 0) < 0)
		return NULL;

	skb_push(skb, QCA_HDR_LEN);

	memmove(skb->data, skb->data + QCA_HDR_LEN, 2 * ETH_ALEN);
	phdr = (u16 *)(skb->data + 2 * ETH_ALEN);

	/* Set the version field, and set destination port information */
	hdr = QCA_HDR_VERSION << QCA_HDR_XMIT_VERSION_S |
		QCA_HDR_XMIT_FROM_CPU | BIT(dp->index);

	*phdr = htons(hdr);

	return skb;
}

__attribute__((used)) static struct sk_buff *qca_tag_rcv(struct sk_buff *skb, struct net_device *dev,
				   struct packet_type *pt)
{
	u8 ver;
	int port;
	__be16 *phdr, hdr;

	if (unlikely(!pskb_may_pull(skb, QCA_HDR_LEN)))
		return NULL;

	/* The QCA header is added by the switch between src addr and Ethertype
	 * At this point, skb->data points to ethertype so header should be
	 * right before
	 */
	phdr = (__be16 *)(skb->data - 2);
	hdr = ntohs(*phdr);

	/* Make sure the version is correct */
	ver = (hdr & QCA_HDR_RECV_VERSION_MASK) >> QCA_HDR_RECV_VERSION_S;
	if (unlikely(ver != QCA_HDR_VERSION))
		return NULL;

	/* Remove QCA tag and recalculate checksum */
	skb_pull_rcsum(skb, QCA_HDR_LEN);
	memmove(skb->data - ETH_HLEN, skb->data - ETH_HLEN - QCA_HDR_LEN,
		ETH_HLEN - QCA_HDR_LEN);

	/* Get source port information */
	port = (hdr & QCA_HDR_RECV_SOURCE_PORT_MASK);

	skb->dev = dsa_master_find_slave(dev, 0, port);
	if (!skb->dev)
		return NULL;

	return skb;
}

