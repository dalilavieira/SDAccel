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
typedef  int u32 ;
struct usbnet {int maxpacket; TYPE_1__* driver_info; int /*<<< orphan*/  udev; int /*<<< orphan*/  out; int /*<<< orphan*/  in; TYPE_2__* net; int /*<<< orphan*/  hard_mtu; } ;
struct usb_interface {int dummy; } ;
struct sk_buff {scalar_t__ len; scalar_t__ data; scalar_t__ head; } ;
struct gl_packet {int /*<<< orphan*/ * packet_data; int /*<<< orphan*/  packet_length; } ;
struct gl_header {struct gl_packet packets; int /*<<< orphan*/  packet_count; } ;
typedef  int /*<<< orphan*/  gfp_t ;
typedef  int /*<<< orphan*/  __le32 ;
struct TYPE_4__ {scalar_t__ hard_header_len; } ;
struct TYPE_3__ {int /*<<< orphan*/  out; int /*<<< orphan*/  in; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int GL_MAX_PACKET_LEN ; 
 int GL_MAX_TRANSMIT_PACKETS ; 
 int /*<<< orphan*/  GL_RCV_BUF_SIZE ; 
 struct sk_buff* alloc_skb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 scalar_t__ memmove (scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  netdev_dbg (TYPE_2__*,char*,int) ; 
 int /*<<< orphan*/  skb_cloned (struct sk_buff*) ; 
 struct sk_buff* skb_copy_expand (struct sk_buff*,int,int,int /*<<< orphan*/ ) ; 
 int skb_headroom (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/ * skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put_data (struct sk_buff*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  skb_set_tail_pointer (struct sk_buff*,int) ; 
 int skb_tailroom (struct sk_buff*) ; 
 int /*<<< orphan*/  usb_rcvbulkpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usb_sndbulkpipe (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usbnet_skb_return (struct usbnet*,struct sk_buff*) ; 

__attribute__((used)) static int genelink_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
	struct gl_header	*header;
	struct gl_packet	*packet;
	struct sk_buff		*gl_skb;
	u32			size;
	u32			count;

	/* This check is no longer done by usbnet */
	if (skb->len < dev->net->hard_header_len)
		return 0;

	header = (struct gl_header *) skb->data;

	// get the packet count of the received skb
	count = le32_to_cpu(header->packet_count);
	if (count > GL_MAX_TRANSMIT_PACKETS) {
		netdev_dbg(dev->net,
			   "genelink: invalid received packet count %u\n",
			   count);
		return 0;
	}

	// set the current packet pointer to the first packet
	packet = &header->packets;

	// decrement the length for the packet count size 4 bytes
	skb_pull(skb, 4);

	while (count > 1) {
		// get the packet length
		size = le32_to_cpu(packet->packet_length);

		// this may be a broken packet
		if (size > GL_MAX_PACKET_LEN) {
			netdev_dbg(dev->net, "genelink: invalid rx length %d\n",
				   size);
			return 0;
		}

		// allocate the skb for the individual packet
		gl_skb = alloc_skb(size, GFP_ATOMIC);
		if (gl_skb) {

			// copy the packet data to the new skb
			skb_put_data(gl_skb, packet->packet_data, size);
			usbnet_skb_return(dev, gl_skb);
		}

		// advance to the next packet
		packet = (struct gl_packet *)&packet->packet_data[size];
		count--;

		// shift the data pointer to the next gl_packet
		skb_pull(skb, size + 4);
	}

	// skip the packet length field 4 bytes
	skb_pull(skb, 4);

	if (skb->len > GL_MAX_PACKET_LEN) {
		netdev_dbg(dev->net, "genelink: invalid rx length %d\n",
			   skb->len);
		return 0;
	}
	return 1;
}

__attribute__((used)) static struct sk_buff *
genelink_tx_fixup(struct usbnet *dev, struct sk_buff *skb, gfp_t flags)
{
	int 	padlen;
	int	length = skb->len;
	int	headroom = skb_headroom(skb);
	int	tailroom = skb_tailroom(skb);
	__le32	*packet_count;
	__le32	*packet_len;

	// FIXME:  magic numbers, bleech
	padlen = ((skb->len + (4 + 4*1)) % 64) ? 0 : 1;

	if ((!skb_cloned(skb))
			&& ((headroom + tailroom) >= (padlen + (4 + 4*1)))) {
		if ((headroom < (4 + 4*1)) || (tailroom < padlen)) {
			skb->data = memmove(skb->head + (4 + 4*1),
					     skb->data, skb->len);
			skb_set_tail_pointer(skb, skb->len);
		}
	} else {
		struct sk_buff	*skb2;
		skb2 = skb_copy_expand(skb, (4 + 4*1) , padlen, flags);
		dev_kfree_skb_any(skb);
		skb = skb2;
		if (!skb)
			return NULL;
	}

	// attach the packet count to the header
	packet_count = skb_push(skb, (4 + 4 * 1));
	packet_len = packet_count + 1;

	*packet_count = cpu_to_le32(1);
	*packet_len = cpu_to_le32(length);

	// add padding byte
	if ((skb->len % dev->maxpacket) == 0)
		skb_put(skb, 1);

	return skb;
}

__attribute__((used)) static int genelink_bind(struct usbnet *dev, struct usb_interface *intf)
{
	dev->hard_mtu = GL_RCV_BUF_SIZE;
	dev->net->hard_header_len += 4;
	dev->in = usb_rcvbulkpipe(dev->udev, dev->driver_info->in);
	dev->out = usb_sndbulkpipe(dev->udev, dev->driver_info->out);
	return 0;
}

