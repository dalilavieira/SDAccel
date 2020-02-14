#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u16 ;
struct usbnet {int maxpacket; TYPE_1__* net; scalar_t__ hard_mtu; } ;
struct usb_interface {int dummy; } ;
struct sk_buff {int len; int /*<<< orphan*/ * data; scalar_t__ head; } ;
struct net_device {int flags; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_4__ {int /*<<< orphan*/ * netdev_ops; scalar_t__ hard_header_len; scalar_t__ mtu; } ;

/* Variables and functions */
 int IFF_ALLMULTI ; 
 int IFF_PROMISC ; 
 int INT51X1_HEADER_SIZE ; 
 int PACKET_TYPE_ALL_MULTICAST ; 
 int PACKET_TYPE_BROADCAST ; 
 int PACKET_TYPE_DIRECTED ; 
 int PACKET_TYPE_PROMISCUOUS ; 
 int /*<<< orphan*/  SET_ETHERNET_PACKET_FILTER ; 
 int USB_DIR_OUT ; 
 int USB_RECIP_INTERFACE ; 
 int USB_TYPE_CLASS ; 
 int /*<<< orphan*/ * __skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  __skb_put_zero (struct sk_buff*,int) ; 
 int /*<<< orphan*/  cpu_to_le16 (int) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  int51x1_netdev_ops ; 
 int le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * memmove (scalar_t__,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  netdev_dbg (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  netdev_err (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  netdev_info (TYPE_1__*,char*) ; 
 int /*<<< orphan*/  netdev_mc_empty (struct net_device*) ; 
 struct usbnet* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_cloned (struct sk_buff*) ; 
 struct sk_buff* skb_copy_expand (struct sk_buff*,int,int,int /*<<< orphan*/ ) ; 
 int skb_headroom (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_set_tail_pointer (struct sk_buff*,int) ; 
 int skb_tailroom (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_trim (struct sk_buff*,int) ; 
 int usbnet_get_endpoints (struct usbnet*,struct usb_interface*) ; 
 int usbnet_get_ethernet_addr (struct usbnet*,int) ; 
 int /*<<< orphan*/  usbnet_write_cmd_async (struct usbnet*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int int51x1_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
	int len;

	if (!(pskb_may_pull(skb, INT51X1_HEADER_SIZE))) {
		netdev_err(dev->net, "unexpected tiny rx frame\n");
		return 0;
	}

	len = le16_to_cpu(*(__le16 *)&skb->data[skb->len - 2]);

	skb_trim(skb, len);

	return 1;
}

__attribute__((used)) static struct sk_buff *int51x1_tx_fixup(struct usbnet *dev,
		struct sk_buff *skb, gfp_t flags)
{
	int pack_len = skb->len;
	int pack_with_header_len = pack_len + INT51X1_HEADER_SIZE;
	int headroom = skb_headroom(skb);
	int tailroom = skb_tailroom(skb);
	int need_tail = 0;
	__le16 *len;

	/* if packet and our header is smaler than 64 pad to 64 (+ ZLP) */
	if ((pack_with_header_len) < dev->maxpacket)
		need_tail = dev->maxpacket - pack_with_header_len + 1;
	/*
	 * usbnet would send a ZLP if packetlength mod urbsize == 0 for us,
	 * but we need to know ourself, because this would add to the length
	 * we send down to the device...
	 */
	else if (!(pack_with_header_len % dev->maxpacket))
		need_tail = 1;

	if (!skb_cloned(skb) &&
			(headroom + tailroom >= need_tail + INT51X1_HEADER_SIZE)) {
		if (headroom < INT51X1_HEADER_SIZE || tailroom < need_tail) {
			skb->data = memmove(skb->head + INT51X1_HEADER_SIZE,
					skb->data, skb->len);
			skb_set_tail_pointer(skb, skb->len);
		}
	} else {
		struct sk_buff *skb2;

		skb2 = skb_copy_expand(skb,
				INT51X1_HEADER_SIZE,
				need_tail,
				flags);
		dev_kfree_skb_any(skb);
		if (!skb2)
			return NULL;
		skb = skb2;
	}

	pack_len += need_tail;
	pack_len &= 0x07ff;

	len = __skb_push(skb, INT51X1_HEADER_SIZE);
	*len = cpu_to_le16(pack_len);

	if(need_tail)
		__skb_put_zero(skb, need_tail);

	return skb;
}

__attribute__((used)) static void int51x1_set_multicast(struct net_device *netdev)
{
	struct usbnet *dev = netdev_priv(netdev);
	u16 filter = PACKET_TYPE_DIRECTED | PACKET_TYPE_BROADCAST;

	if (netdev->flags & IFF_PROMISC) {
		/* do not expect to see traffic of other PLCs */
		filter |= PACKET_TYPE_PROMISCUOUS;
		netdev_info(dev->net, "promiscuous mode enabled\n");
	} else if (!netdev_mc_empty(netdev) ||
		  (netdev->flags & IFF_ALLMULTI)) {
		filter |= PACKET_TYPE_ALL_MULTICAST;
		netdev_dbg(dev->net, "receive all multicast enabled\n");
	} else {
		/* ~PROMISCUOUS, ~MULTICAST */
		netdev_dbg(dev->net, "receive own packets only\n");
	}

	usbnet_write_cmd_async(dev, SET_ETHERNET_PACKET_FILTER,
			       USB_DIR_OUT | USB_TYPE_CLASS | USB_RECIP_INTERFACE,
			       filter, 0, NULL, 0);
}

__attribute__((used)) static int int51x1_bind(struct usbnet *dev, struct usb_interface *intf)
{
	int status = usbnet_get_ethernet_addr(dev, 3);

	if (status)
		return status;

	dev->net->hard_header_len += INT51X1_HEADER_SIZE;
	dev->hard_mtu = dev->net->mtu + dev->net->hard_header_len;
	dev->net->netdev_ops = &int51x1_netdev_ops;

	return usbnet_get_endpoints(dev, intf);
}

