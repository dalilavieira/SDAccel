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
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u16 ;
struct sk_buff {int* data; scalar_t__ pkt_type; struct net_device* dev; int /*<<< orphan*/  sk; void* protocol; int /*<<< orphan*/  ip_summed; } ;
struct rmnet_priv {scalar_t__ mux_id; TYPE_2__* pcpu_stats; struct net_device* real_dev; int /*<<< orphan*/  gro_cells; } ;
struct rmnet_port {int data_format; int rmnet_mode; struct net_device* bridge_ep; } ;
struct rmnet_map_ul_csum_header {int dummy; } ;
struct rmnet_map_header {scalar_t__ mux_id; } ;
struct rmnet_endpoint {struct net_device* egress_dev; } ;
struct net_device {scalar_t__ type; } ;
typedef  int /*<<< orphan*/  rx_handler_result_t ;
struct TYPE_3__ {int /*<<< orphan*/  tx_drops; } ;
struct TYPE_4__ {TYPE_1__ stats; } ;

/* Variables and functions */
 scalar_t__ ARPHRD_ETHER ; 
 int /*<<< orphan*/  CHECKSUM_UNNECESSARY ; 
 int ENOMEM ; 
 int ETH_HLEN ; 
 int /*<<< orphan*/  ETH_P_IP ; 
 int /*<<< orphan*/  ETH_P_IPV6 ; 
 int /*<<< orphan*/  ETH_P_MAP ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 scalar_t__ PACKET_HOST ; 
 scalar_t__ PACKET_LOOPBACK ; 
#define  RMNET_EPMODE_BRIDGE 131 
#define  RMNET_EPMODE_VND 130 
 int RMNET_FLAGS_EGRESS_MAP_CKSUMV4 ; 
 int RMNET_FLAGS_INGRESS_DEAGGREGATION ; 
 int RMNET_FLAGS_INGRESS_MAP_CKSUMV4 ; 
 int RMNET_FLAGS_INGRESS_MAP_COMMANDS ; 
#define  RMNET_IP_VERSION_4 129 
#define  RMNET_IP_VERSION_6 128 
 scalar_t__ RMNET_MAP_GET_CD_BIT (struct sk_buff*) ; 
 scalar_t__ RMNET_MAP_GET_LENGTH (struct sk_buff*) ; 
 scalar_t__ RMNET_MAP_GET_MUX_ID (struct sk_buff*) ; 
 scalar_t__ RMNET_MAP_GET_PAD (struct sk_buff*) ; 
 scalar_t__ RMNET_MAX_LOGICAL_EP ; 
 int /*<<< orphan*/  RX_HANDLER_CONSUMED ; 
 int /*<<< orphan*/  RX_HANDLER_PASS ; 
 int /*<<< orphan*/  consume_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  dev_queue_xmit (struct sk_buff*) ; 
 int /*<<< orphan*/  gro_cells_receive (int /*<<< orphan*/ *,struct sk_buff*) ; 
 void* htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 struct rmnet_priv* netdev_priv (struct net_device*) ; 
 scalar_t__ pskb_expand_head (struct sk_buff*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rmnet_endpoint* rmnet_get_endpoint (struct rmnet_port*,scalar_t__) ; 
 struct rmnet_port* rmnet_get_port (struct net_device*) ; 
 struct rmnet_map_header* rmnet_map_add_map_header (struct sk_buff*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rmnet_map_checksum_downlink_packet (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  rmnet_map_checksum_uplink_packet (struct sk_buff*,struct net_device*) ; 
 void rmnet_map_command (struct sk_buff*,struct rmnet_port*) ; 
 struct sk_buff* rmnet_map_deaggregate (struct sk_buff*,struct rmnet_port*) ; 
 int /*<<< orphan*/  rmnet_vnd_rx_fixup (struct sk_buff*,struct net_device*) ; 
 int /*<<< orphan*/  rmnet_vnd_tx_fixup (struct sk_buff*,struct net_device*) ; 
 int /*<<< orphan*/  sk_pacing_shift_update (int /*<<< orphan*/ ,int) ; 
 int skb_headroom (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reset_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_transport_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_set_mac_header (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_trim (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  this_cpu_inc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void rmnet_set_skb_proto(struct sk_buff *skb)
{
	switch (skb->data[0] & 0xF0) {
	case RMNET_IP_VERSION_4:
		skb->protocol = htons(ETH_P_IP);
		break;
	case RMNET_IP_VERSION_6:
		skb->protocol = htons(ETH_P_IPV6);
		break;
	default:
		skb->protocol = htons(ETH_P_MAP);
		break;
	}
}

__attribute__((used)) static void
rmnet_deliver_skb(struct sk_buff *skb)
{
	struct rmnet_priv *priv = netdev_priv(skb->dev);

	skb_reset_transport_header(skb);
	skb_reset_network_header(skb);
	rmnet_vnd_rx_fixup(skb, skb->dev);

	skb->pkt_type = PACKET_HOST;
	skb_set_mac_header(skb, 0);
	gro_cells_receive(&priv->gro_cells, skb);
}

__attribute__((used)) static void
__rmnet_map_ingress_handler(struct sk_buff *skb,
			    struct rmnet_port *port)
{
	struct rmnet_endpoint *ep;
	u16 len, pad;
	u8 mux_id;

	if (RMNET_MAP_GET_CD_BIT(skb)) {
		if (port->data_format & RMNET_FLAGS_INGRESS_MAP_COMMANDS)
			return rmnet_map_command(skb, port);

		goto free_skb;
	}

	mux_id = RMNET_MAP_GET_MUX_ID(skb);
	pad = RMNET_MAP_GET_PAD(skb);
	len = RMNET_MAP_GET_LENGTH(skb) - pad;

	if (mux_id >= RMNET_MAX_LOGICAL_EP)
		goto free_skb;

	ep = rmnet_get_endpoint(port, mux_id);
	if (!ep)
		goto free_skb;

	skb->dev = ep->egress_dev;

	/* Subtract MAP header */
	skb_pull(skb, sizeof(struct rmnet_map_header));
	rmnet_set_skb_proto(skb);

	if (port->data_format & RMNET_FLAGS_INGRESS_MAP_CKSUMV4) {
		if (!rmnet_map_checksum_downlink_packet(skb, len + pad))
			skb->ip_summed = CHECKSUM_UNNECESSARY;
	}

	skb_trim(skb, len);
	rmnet_deliver_skb(skb);
	return;

free_skb:
	kfree_skb(skb);
}

__attribute__((used)) static void
rmnet_map_ingress_handler(struct sk_buff *skb,
			  struct rmnet_port *port)
{
	struct sk_buff *skbn;

	if (skb->dev->type == ARPHRD_ETHER) {
		if (pskb_expand_head(skb, ETH_HLEN, 0, GFP_ATOMIC)) {
			kfree_skb(skb);
			return;
		}

		skb_push(skb, ETH_HLEN);
	}

	if (port->data_format & RMNET_FLAGS_INGRESS_DEAGGREGATION) {
		while ((skbn = rmnet_map_deaggregate(skb, port)) != NULL)
			__rmnet_map_ingress_handler(skbn, port);

		consume_skb(skb);
	} else {
		__rmnet_map_ingress_handler(skb, port);
	}
}

__attribute__((used)) static int rmnet_map_egress_handler(struct sk_buff *skb,
				    struct rmnet_port *port, u8 mux_id,
				    struct net_device *orig_dev)
{
	int required_headroom, additional_header_len;
	struct rmnet_map_header *map_header;

	additional_header_len = 0;
	required_headroom = sizeof(struct rmnet_map_header);

	if (port->data_format & RMNET_FLAGS_EGRESS_MAP_CKSUMV4) {
		additional_header_len = sizeof(struct rmnet_map_ul_csum_header);
		required_headroom += additional_header_len;
	}

	if (skb_headroom(skb) < required_headroom) {
		if (pskb_expand_head(skb, required_headroom, 0, GFP_ATOMIC))
			return -ENOMEM;
	}

	if (port->data_format & RMNET_FLAGS_EGRESS_MAP_CKSUMV4)
		rmnet_map_checksum_uplink_packet(skb, orig_dev);

	map_header = rmnet_map_add_map_header(skb, additional_header_len, 0);
	if (!map_header)
		return -ENOMEM;

	map_header->mux_id = mux_id;

	skb->protocol = htons(ETH_P_MAP);

	return 0;
}

__attribute__((used)) static void
rmnet_bridge_handler(struct sk_buff *skb, struct net_device *bridge_dev)
{
	if (bridge_dev) {
		skb->dev = bridge_dev;
		dev_queue_xmit(skb);
	}
}

rx_handler_result_t rmnet_rx_handler(struct sk_buff **pskb)
{
	struct sk_buff *skb = *pskb;
	struct rmnet_port *port;
	struct net_device *dev;

	if (!skb)
		goto done;

	if (skb->pkt_type == PACKET_LOOPBACK)
		return RX_HANDLER_PASS;

	dev = skb->dev;
	port = rmnet_get_port(dev);

	switch (port->rmnet_mode) {
	case RMNET_EPMODE_VND:
		rmnet_map_ingress_handler(skb, port);
		break;
	case RMNET_EPMODE_BRIDGE:
		rmnet_bridge_handler(skb, port->bridge_ep);
		break;
	}

done:
	return RX_HANDLER_CONSUMED;
}

void rmnet_egress_handler(struct sk_buff *skb)
{
	struct net_device *orig_dev;
	struct rmnet_port *port;
	struct rmnet_priv *priv;
	u8 mux_id;

	sk_pacing_shift_update(skb->sk, 8);

	orig_dev = skb->dev;
	priv = netdev_priv(orig_dev);
	skb->dev = priv->real_dev;
	mux_id = priv->mux_id;

	port = rmnet_get_port(skb->dev);
	if (!port)
		goto drop;

	if (rmnet_map_egress_handler(skb, port, mux_id, orig_dev))
		goto drop;

	rmnet_vnd_tx_fixup(skb, orig_dev);

	dev_queue_xmit(skb);
	return;

drop:
	this_cpu_inc(priv->pcpu_stats->stats.tx_drops);
	kfree_skb(skb);
}

