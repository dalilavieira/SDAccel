#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {unsigned char* data; struct net_device* dev; void* protocol; } ;
struct TYPE_5__ {int /*<<< orphan*/  rx_errors; int /*<<< orphan*/  rx_dropped; } ;
struct net_device {int flags; int /*<<< orphan*/  type; TYPE_1__ stats; } ;
struct lapb_register_struct {void (* connect_confirmation ) (struct net_device*,int) ;void (* connect_indication ) (struct net_device*,int) ;void (* disconnect_confirmation ) (struct net_device*,int) ;void (* disconnect_indication ) (struct net_device*,int) ;int (* data_indication ) (struct net_device*,struct sk_buff*) ;void (* data_transmit ) (struct net_device*,struct sk_buff*) ;} ;
struct TYPE_6__ {int type; } ;
struct ifreq {TYPE_2__ ifr_settings; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;
struct TYPE_7__ {int (* attach ) (struct net_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/ * proto; int /*<<< orphan*/  (* xmit ) (struct sk_buff*,struct net_device*) ;} ;
typedef  TYPE_3__ hdlc_device ;

/* Variables and functions */
 int /*<<< orphan*/  ARPHRD_X25 ; 
 int /*<<< orphan*/  CAP_NET_ADMIN ; 
 int EBUSY ; 
 int EINVAL ; 
 int /*<<< orphan*/  ENCODING_NRZ ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int IFF_UP ; 
#define  IF_GET_PROTO 132 
#define  IF_PROTO_X25 131 
 int LAPB_CONNECTED ; 
 int LAPB_NOTCONNECTED ; 
 int LAPB_OK ; 
 int /*<<< orphan*/  NETDEV_POST_TYPE_CHANGE ; 
 int /*<<< orphan*/  NETDEV_TX_OK ; 
 int NET_RX_DROP ; 
 int NET_RX_SUCCESS ; 
 int /*<<< orphan*/  PARITY_CRC16_PR1_CCITT ; 
#define  X25_IFACE_CONNECT 130 
#define  X25_IFACE_DATA 129 
#define  X25_IFACE_DISCONNECT 128 
 int attach_hdlc_protocol (struct net_device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  call_netdevice_notifiers (int /*<<< orphan*/ ,struct net_device*) ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 struct sk_buff* dev_alloc_skb (int) ; 
 int /*<<< orphan*/  dev_kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 TYPE_3__* dev_to_hdlc (struct net_device*) ; 
 int lapb_connect_request (struct net_device*) ; 
 int lapb_data_received (struct net_device*,struct sk_buff*) ; 
 int lapb_data_request (struct net_device*,struct sk_buff*) ; 
 int lapb_disconnect_request (struct net_device*) ; 
 int lapb_register (struct net_device*,struct lapb_register_struct const*) ; 
 int /*<<< orphan*/  lapb_unregister (struct net_device*) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*,...) ; 
 int /*<<< orphan*/  netif_dormant_off (struct net_device*) ; 
 int netif_rx (struct sk_buff*) ; 
 int /*<<< orphan*/  proto ; 
 scalar_t__ skb_cow (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_push (struct sk_buff*,int) ; 
 unsigned char* skb_put (struct sk_buff*,int) ; 
 struct sk_buff* skb_share_check (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (struct sk_buff*,struct net_device*) ; 
 int stub2 (struct net_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* x25_type_trans (struct sk_buff*,struct net_device*) ; 

__attribute__((used)) static void x25_connect_disconnect(struct net_device *dev, int reason, int code)
{
	struct sk_buff *skb;
	unsigned char *ptr;

	if ((skb = dev_alloc_skb(1)) == NULL) {
		netdev_err(dev, "out of memory\n");
		return;
	}

	ptr = skb_put(skb, 1);
	*ptr = code;

	skb->protocol = x25_type_trans(skb, dev);
	netif_rx(skb);
}

__attribute__((used)) static void x25_connected(struct net_device *dev, int reason)
{
	x25_connect_disconnect(dev, reason, X25_IFACE_CONNECT);
}

__attribute__((used)) static void x25_disconnected(struct net_device *dev, int reason)
{
	x25_connect_disconnect(dev, reason, X25_IFACE_DISCONNECT);
}

__attribute__((used)) static int x25_data_indication(struct net_device *dev, struct sk_buff *skb)
{
	unsigned char *ptr;

	skb_push(skb, 1);

	if (skb_cow(skb, 1))
		return NET_RX_DROP;

	ptr  = skb->data;
	*ptr = X25_IFACE_DATA;

	skb->protocol = x25_type_trans(skb, dev);
	return netif_rx(skb);
}

__attribute__((used)) static void x25_data_transmit(struct net_device *dev, struct sk_buff *skb)
{
	hdlc_device *hdlc = dev_to_hdlc(dev);
	hdlc->xmit(skb, dev); /* Ignore return value :-( */
}

__attribute__((used)) static netdev_tx_t x25_xmit(struct sk_buff *skb, struct net_device *dev)
{
	int result;


	/* X.25 to LAPB */
	switch (skb->data[0]) {
	case X25_IFACE_DATA:	/* Data to be transmitted */
		skb_pull(skb, 1);
		if ((result = lapb_data_request(dev, skb)) != LAPB_OK)
			dev_kfree_skb(skb);
		return NETDEV_TX_OK;

	case X25_IFACE_CONNECT:
		if ((result = lapb_connect_request(dev))!= LAPB_OK) {
			if (result == LAPB_CONNECTED)
				/* Send connect confirm. msg to level 3 */
				x25_connected(dev, 0);
			else
				netdev_err(dev, "LAPB connect request failed, error code = %i\n",
					   result);
		}
		break;

	case X25_IFACE_DISCONNECT:
		if ((result = lapb_disconnect_request(dev)) != LAPB_OK) {
			if (result == LAPB_NOTCONNECTED)
				/* Send disconnect confirm. msg to level 3 */
				x25_disconnected(dev, 0);
			else
				netdev_err(dev, "LAPB disconnect request failed, error code = %i\n",
					   result);
		}
		break;

	default:		/* to be defined */
		break;
	}

	dev_kfree_skb(skb);
	return NETDEV_TX_OK;
}

__attribute__((used)) static int x25_open(struct net_device *dev)
{
	int result;
	static const struct lapb_register_struct cb = {
		.connect_confirmation = x25_connected,
		.connect_indication = x25_connected,
		.disconnect_confirmation = x25_disconnected,
		.disconnect_indication = x25_disconnected,
		.data_indication = x25_data_indication,
		.data_transmit = x25_data_transmit,
	};

	result = lapb_register(dev, &cb);
	if (result != LAPB_OK)
		return result;
	return 0;
}

__attribute__((used)) static void x25_close(struct net_device *dev)
{
	lapb_unregister(dev);
}

__attribute__((used)) static int x25_rx(struct sk_buff *skb)
{
	struct net_device *dev = skb->dev;

	if ((skb = skb_share_check(skb, GFP_ATOMIC)) == NULL) {
		dev->stats.rx_dropped++;
		return NET_RX_DROP;
	}

	if (lapb_data_received(dev, skb) == LAPB_OK)
		return NET_RX_SUCCESS;

	dev->stats.rx_errors++;
	dev_kfree_skb_any(skb);
	return NET_RX_DROP;
}

__attribute__((used)) static int x25_ioctl(struct net_device *dev, struct ifreq *ifr)
{
	hdlc_device *hdlc = dev_to_hdlc(dev);
	int result;

	switch (ifr->ifr_settings.type) {
	case IF_GET_PROTO:
		if (dev_to_hdlc(dev)->proto != &proto)
			return -EINVAL;
		ifr->ifr_settings.type = IF_PROTO_X25;
		return 0; /* return protocol only, no settable parameters */

	case IF_PROTO_X25:
		if (!capable(CAP_NET_ADMIN))
			return -EPERM;

		if (dev->flags & IFF_UP)
			return -EBUSY;

		result=hdlc->attach(dev, ENCODING_NRZ,PARITY_CRC16_PR1_CCITT);
		if (result)
			return result;

		if ((result = attach_hdlc_protocol(dev, &proto, 0)))
			return result;
		dev->type = ARPHRD_X25;
		call_netdevice_notifiers(NETDEV_POST_TYPE_CHANGE, dev);
		netif_dormant_off(dev);
		return 0;
	}

	return -EINVAL;
}

