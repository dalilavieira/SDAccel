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
struct work_struct {int dummy; } ;
struct sk_buff {scalar_t__ len; struct net_device const* dev; int /*<<< orphan*/  protocol; int /*<<< orphan*/  pkt_type; } ;
struct pcpu_sw_netstats {int /*<<< orphan*/  syncp; int /*<<< orphan*/  rx_bytes; int /*<<< orphan*/  rx_packets; } ;
struct packet_type {int dummy; } ;
struct notifier_block {int dummy; } ;
struct net_device {struct dsa_port* dsa_ptr; } ;
struct dsa_switch_tree {struct dsa_switch** ds; } ;
struct dsa_switch {int num_ports; TYPE_3__* ops; struct dsa_port* ports; } ;
struct dsa_slave_priv {int /*<<< orphan*/  stats64; struct dsa_port* dp; } ;
struct dsa_port {scalar_t__ type; struct sk_buff* (* rcv ) (struct sk_buff*,struct net_device*,struct packet_type*) ;int /*<<< orphan*/  index; struct dsa_switch* ds; TYPE_1__* cpu_dp; struct net_device* slave; struct dsa_switch_tree* dst; } ;
struct dsa_notifier_info {struct net_device* dev; } ;
struct dsa_device_ops {int dummy; } ;
struct device {TYPE_2__* class; } ;
struct TYPE_6__ {int (* port_rxtstamp ) (struct dsa_switch*,int /*<<< orphan*/ ,struct sk_buff*,unsigned int) ;} ;
struct TYPE_5__ {int /*<<< orphan*/  name; } ;
struct TYPE_4__ {struct net_device* master; } ;

/* Variables and functions */
 int DSA_MAX_SWITCHES ; 
 scalar_t__ DSA_PORT_TYPE_USER ; 
 int DSA_TAG_LAST ; 
 int /*<<< orphan*/  EINVAL ; 
 int /*<<< orphan*/  ENOPROTOOPT ; 
 struct dsa_device_ops const* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ ETH_HLEN ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  PACKET_HOST ; 
 unsigned int PTP_CLASS_NONE ; 
 int /*<<< orphan*/  __skb_pull (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  __skb_push (struct sk_buff*,scalar_t__) ; 
 int atomic_notifier_call_chain (int /*<<< orphan*/ *,unsigned long,struct dsa_notifier_info*) ; 
 int atomic_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int atomic_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  dev_hold (struct net_device*) ; 
 struct device* device_find_child (struct device*,char*,int (*) (struct device*,void*)) ; 
 struct dsa_device_ops** dsa_device_ops ; 
 int /*<<< orphan*/  dsa_notif_chain ; 
 int /*<<< orphan*/  dsa_owq ; 
 int /*<<< orphan*/  eth_type_trans (struct sk_buff*,struct net_device const*) ; 
 int /*<<< orphan*/  get_device (struct device*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 scalar_t__ likely (int (*) (struct dsa_switch*,int /*<<< orphan*/ ,struct sk_buff*,unsigned int)) ; 
 struct dsa_slave_priv* netdev_priv (struct net_device const*) ; 
 int /*<<< orphan*/  netif_receive_skb (struct sk_buff*) ; 
 unsigned int ptp_classify_raw (struct sk_buff*) ; 
 int /*<<< orphan*/  put_device (struct device*) ; 
 int queue_work (int /*<<< orphan*/ ,struct work_struct*) ; 
 scalar_t__ skb_headroom (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,scalar_t__) ; 
 struct sk_buff* skb_unshare (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp (int /*<<< orphan*/ ,void*) ; 
 int stub1 (struct dsa_switch*,int /*<<< orphan*/ ,struct sk_buff*,unsigned int) ; 
 struct sk_buff* stub2 (struct sk_buff*,struct net_device*,struct packet_type*) ; 
 struct pcpu_sw_netstats* this_cpu_ptr (int /*<<< orphan*/ ) ; 
 struct net_device* to_net_dev (struct device*) ; 
 int /*<<< orphan*/  u64_stats_update_begin (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  u64_stats_update_end (int /*<<< orphan*/ *) ; 
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

__attribute__((used)) static struct sk_buff *dsa_slave_notag_xmit(struct sk_buff *skb,
					    struct net_device *dev)
{
	/* Just return the original SKB */
	return skb;
}

const struct dsa_device_ops *dsa_resolve_tag_protocol(int tag_protocol)
{
	const struct dsa_device_ops *ops;

	if (tag_protocol >= DSA_TAG_LAST)
		return ERR_PTR(-EINVAL);
	ops = dsa_device_ops[tag_protocol];

	if (!ops)
		return ERR_PTR(-ENOPROTOOPT);

	return ops;
}

__attribute__((used)) static int dev_is_class(struct device *dev, void *class)
{
	if (dev->class != NULL && !strcmp(dev->class->name, class))
		return 1;

	return 0;
}

__attribute__((used)) static struct device *dev_find_class(struct device *parent, char *class)
{
	if (dev_is_class(parent, class)) {
		get_device(parent);
		return parent;
	}

	return device_find_child(parent, class, dev_is_class);
}

struct net_device *dsa_dev_to_net_device(struct device *dev)
{
	struct device *d;

	d = dev_find_class(dev, "net");
	if (d != NULL) {
		struct net_device *nd;

		nd = to_net_dev(d);
		dev_hold(nd);
		put_device(d);

		return nd;
	}

	return NULL;
}

__attribute__((used)) static bool dsa_skb_defer_rx_timestamp(struct dsa_slave_priv *p,
				       struct sk_buff *skb)
{
	struct dsa_switch *ds = p->dp->ds;
	unsigned int type;

	if (skb_headroom(skb) < ETH_HLEN)
		return false;

	__skb_push(skb, ETH_HLEN);

	type = ptp_classify_raw(skb);

	__skb_pull(skb, ETH_HLEN);

	if (type == PTP_CLASS_NONE)
		return false;

	if (likely(ds->ops->port_rxtstamp))
		return ds->ops->port_rxtstamp(ds, p->dp->index, skb, type);

	return false;
}

__attribute__((used)) static int dsa_switch_rcv(struct sk_buff *skb, struct net_device *dev,
			  struct packet_type *pt, struct net_device *unused)
{
	struct dsa_port *cpu_dp = dev->dsa_ptr;
	struct sk_buff *nskb = NULL;
	struct pcpu_sw_netstats *s;
	struct dsa_slave_priv *p;

	if (unlikely(!cpu_dp)) {
		kfree_skb(skb);
		return 0;
	}

	skb = skb_unshare(skb, GFP_ATOMIC);
	if (!skb)
		return 0;

	nskb = cpu_dp->rcv(skb, dev, pt);
	if (!nskb) {
		kfree_skb(skb);
		return 0;
	}

	skb = nskb;
	p = netdev_priv(skb->dev);
	skb_push(skb, ETH_HLEN);
	skb->pkt_type = PACKET_HOST;
	skb->protocol = eth_type_trans(skb, skb->dev);

	s = this_cpu_ptr(p->stats64);
	u64_stats_update_begin(&s->syncp);
	s->rx_packets++;
	s->rx_bytes += skb->len;
	u64_stats_update_end(&s->syncp);

	if (dsa_skb_defer_rx_timestamp(p, skb))
		return 0;

	netif_receive_skb(skb);

	return 0;
}

bool dsa_schedule_work(struct work_struct *work)
{
	return queue_work(dsa_owq, work);
}

int register_dsa_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_register(&dsa_notif_chain, nb);
}

int unregister_dsa_notifier(struct notifier_block *nb)
{
	return atomic_notifier_chain_unregister(&dsa_notif_chain, nb);
}

int call_dsa_notifiers(unsigned long val, struct net_device *dev,
		       struct dsa_notifier_info *info)
{
	info->dev = dev;
	return atomic_notifier_call_chain(&dsa_notif_chain, val, info);
}

