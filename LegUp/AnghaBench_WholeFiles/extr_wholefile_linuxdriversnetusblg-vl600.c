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
typedef  int uint32_t ;
struct vl600_state {struct sk_buff* current_rx_buf; } ;
struct vl600_frame_hdr {void* pkt_cnt; void* serial; void* len; int /*<<< orphan*/  magic; } ;
struct vl600_pkt_hdr {void* len; struct vl600_frame_hdr dummy; void* h_proto; } ;
struct usbnet {TYPE_2__* net; struct vl600_state* driver_priv; } ;
struct usb_interface {int dummy; } ;
struct sk_buff {int* data; int len; scalar_t__ head; } ;
struct ethhdr {void* h_proto; int /*<<< orphan*/  h_dest; int /*<<< orphan*/  h_source; } ;
typedef  int /*<<< orphan*/  gfp_t ;
struct TYPE_3__ {int /*<<< orphan*/  rx_errors; int /*<<< orphan*/  rx_length_errors; } ;
struct TYPE_4__ {int* dev_addr; TYPE_1__ stats; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 scalar_t__ ETH_P_ARP ; 
 int /*<<< orphan*/  ETH_P_IP ; 
 int /*<<< orphan*/  ETH_P_IPV6 ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IFF_MULTICAST ; 
 int /*<<< orphan*/  IFF_NOARP ; 
 scalar_t__ be16_to_cpup (void**) ; 
 void* cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  eth_zero_addr (int /*<<< orphan*/ ) ; 
 void* htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ifup ; 
 int /*<<< orphan*/  kfree (struct vl600_state*) ; 
 struct vl600_state* kzalloc (int,int /*<<< orphan*/ ) ; 
 int le32_to_cpup (void**) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int*,int /*<<< orphan*/ ) ; 
 int* memmove (scalar_t__,int*,int) ; 
 int /*<<< orphan*/  memset (struct vl600_frame_hdr*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  netif_err (struct usbnet*,int /*<<< orphan*/ ,TYPE_2__*,char*) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 struct sk_buff* skb_clone (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_cloned (struct sk_buff*) ; 
 void* skb_copy_expand (struct sk_buff*,int,int,int /*<<< orphan*/ ) ; 
 int skb_headroom (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 struct vl600_frame_hdr* skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put_data (struct sk_buff*,int*,int) ; 
 int /*<<< orphan*/  skb_set_tail_pointer (struct sk_buff*,int) ; 
 int skb_tailroom (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_trim (struct sk_buff*,int) ; 
 int usbnet_cdc_bind (struct usbnet*,struct usb_interface*) ; 
 void usbnet_cdc_unbind (struct usbnet*,struct usb_interface*) ; 
 int /*<<< orphan*/  usbnet_skb_return (struct usbnet*,struct sk_buff*) ; 

__attribute__((used)) static int vl600_bind(struct usbnet *dev, struct usb_interface *intf)
{
	int ret;
	struct vl600_state *s = kzalloc(sizeof(struct vl600_state), GFP_KERNEL);

	if (!s)
		return -ENOMEM;

	ret = usbnet_cdc_bind(dev, intf);
	if (ret) {
		kfree(s);
		return ret;
	}

	dev->driver_priv = s;

	/* ARP packets don't go through, but they're also of no use.  The
	 * subnet has only two hosts anyway: us and the gateway / DHCP
	 * server (probably simulated by modem firmware or network operator)
	 * whose address changes everytime we connect to the intarwebz and
	 * who doesn't bother answering ARP requests either.  So hardware
	 * addresses have no meaning, the destination and the source of every
	 * packet depend only on whether it is on the IN or OUT endpoint.  */
	dev->net->flags |= IFF_NOARP;
	/* IPv6 NDP relies on multicast.  Enable it by default. */
	dev->net->flags |= IFF_MULTICAST;

	return ret;
}

__attribute__((used)) static void vl600_unbind(struct usbnet *dev, struct usb_interface *intf)
{
	struct vl600_state *s = dev->driver_priv;

	if (s->current_rx_buf)
		dev_kfree_skb(s->current_rx_buf);

	kfree(s);

	return usbnet_cdc_unbind(dev, intf);
}

__attribute__((used)) static int vl600_rx_fixup(struct usbnet *dev, struct sk_buff *skb)
{
	struct vl600_frame_hdr *frame;
	struct vl600_pkt_hdr *packet;
	struct ethhdr *ethhdr;
	int packet_len, count;
	struct sk_buff *buf = skb;
	struct sk_buff *clone;
	struct vl600_state *s = dev->driver_priv;

	/* Frame lengths are generally 4B multiplies but every couple of
	 * hours there's an odd number of bytes sized yet correct frame,
	 * so don't require this.  */

	/* Allow a packet (or multiple packets batched together) to be
	 * split across many frames.  We don't allow a new batch to
	 * begin in the same frame another one is ending however, and no
	 * leading or trailing pad bytes.  */
	if (s->current_rx_buf) {
		frame = (struct vl600_frame_hdr *) s->current_rx_buf->data;
		if (skb->len + s->current_rx_buf->len >
				le32_to_cpup(&frame->len)) {
			netif_err(dev, ifup, dev->net, "Fragment too long\n");
			dev->net->stats.rx_length_errors++;
			goto error;
		}

		buf = s->current_rx_buf;
		skb_put_data(buf, skb->data, skb->len);
	} else if (skb->len < 4) {
		netif_err(dev, ifup, dev->net, "Frame too short\n");
		dev->net->stats.rx_length_errors++;
		goto error;
	}

	frame = (struct vl600_frame_hdr *) buf->data;
	/* Yes, check that frame->magic == 0x53544448 (or 0x44544d48),
	 * otherwise we may run out of memory w/a bad packet */
	if (ntohl(frame->magic) != 0x53544448 &&
			ntohl(frame->magic) != 0x44544d48)
		goto error;

	if (buf->len < sizeof(*frame) ||
			buf->len != le32_to_cpup(&frame->len)) {
		/* Save this fragment for later assembly */
		if (s->current_rx_buf)
			return 0;

		s->current_rx_buf = skb_copy_expand(skb, 0,
				le32_to_cpup(&frame->len), GFP_ATOMIC);
		if (!s->current_rx_buf)
			dev->net->stats.rx_errors++;

		return 0;
	}

	count = le32_to_cpup(&frame->pkt_cnt);

	skb_pull(buf, sizeof(*frame));

	while (count--) {
		if (buf->len < sizeof(*packet)) {
			netif_err(dev, ifup, dev->net, "Packet too short\n");
			goto error;
		}

		packet = (struct vl600_pkt_hdr *) buf->data;
		packet_len = sizeof(*packet) + le32_to_cpup(&packet->len);
		if (packet_len > buf->len) {
			netif_err(dev, ifup, dev->net,
					"Bad packet length stored in header\n");
			goto error;
		}

		/* Packet header is same size as the ethernet header
		 * (sizeof(*packet) == sizeof(*ethhdr)), additionally
		 * the h_proto field is in the same place so we just leave it
		 * alone and fill in the remaining fields.
		 */
		ethhdr = (struct ethhdr *) skb->data;
		if (be16_to_cpup(&ethhdr->h_proto) == ETH_P_ARP &&
				buf->len > 0x26) {
			/* Copy the addresses from packet contents */
			memcpy(ethhdr->h_source,
					&buf->data[sizeof(*ethhdr) + 0x8],
					ETH_ALEN);
			memcpy(ethhdr->h_dest,
					&buf->data[sizeof(*ethhdr) + 0x12],
					ETH_ALEN);
		} else {
			eth_zero_addr(ethhdr->h_source);
			memcpy(ethhdr->h_dest, dev->net->dev_addr, ETH_ALEN);

			/* Inbound IPv6 packets have an IPv4 ethertype (0x800)
			 * for some reason.  Peek at the L3 header to check
			 * for IPv6 packets, and set the ethertype to IPv6
			 * (0x86dd) so Linux can understand it.
			 */
			if ((buf->data[sizeof(*ethhdr)] & 0xf0) == 0x60)
				ethhdr->h_proto = htons(ETH_P_IPV6);
		}

		if (count) {
			/* Not the last packet in this batch */
			clone = skb_clone(buf, GFP_ATOMIC);
			if (!clone)
				goto error;

			skb_trim(clone, packet_len);
			usbnet_skb_return(dev, clone);

			skb_pull(buf, (packet_len + 3) & ~3);
		} else {
			skb_trim(buf, packet_len);

			if (s->current_rx_buf) {
				usbnet_skb_return(dev, buf);
				s->current_rx_buf = NULL;
				return 0;
			}

			return 1;
		}
	}

error:
	if (s->current_rx_buf) {
		dev_kfree_skb_any(s->current_rx_buf);
		s->current_rx_buf = NULL;
	}
	dev->net->stats.rx_errors++;
	return 0;
}

__attribute__((used)) static struct sk_buff *vl600_tx_fixup(struct usbnet *dev,
		struct sk_buff *skb, gfp_t flags)
{
	struct sk_buff *ret;
	struct vl600_frame_hdr *frame;
	struct vl600_pkt_hdr *packet;
	static uint32_t serial = 1;
	int orig_len = skb->len - sizeof(struct ethhdr);
	int full_len = (skb->len + sizeof(struct vl600_frame_hdr) + 3) & ~3;

	frame = (struct vl600_frame_hdr *) skb->data;
	if (skb->len > sizeof(*frame) && skb->len == le32_to_cpup(&frame->len))
		return skb; /* Already encapsulated? */

	if (skb->len < sizeof(struct ethhdr))
		/* Drop, device can only deal with ethernet packets */
		return NULL;

	if (!skb_cloned(skb)) {
		int headroom = skb_headroom(skb);
		int tailroom = skb_tailroom(skb);

		if (tailroom >= full_len - skb->len - sizeof(*frame) &&
				headroom >= sizeof(*frame))
			/* There's enough head and tail room */
			goto encapsulate;

		if (headroom + tailroom + skb->len >= full_len) {
			/* There's enough total room, just readjust */
			skb->data = memmove(skb->head + sizeof(*frame),
					skb->data, skb->len);
			skb_set_tail_pointer(skb, skb->len);
			goto encapsulate;
		}
	}

	/* Alloc a new skb with the required size */
	ret = skb_copy_expand(skb, sizeof(struct vl600_frame_hdr), full_len -
			skb->len - sizeof(struct vl600_frame_hdr), flags);
	dev_kfree_skb_any(skb);
	if (!ret)
		return ret;
	skb = ret;

encapsulate:
	/* Packet header is same size as ethernet packet header
	 * (sizeof(*packet) == sizeof(struct ethhdr)), additionally the
	 * h_proto field is in the same place so we just leave it alone and
	 * overwrite the remaining fields.
	 */
	packet = (struct vl600_pkt_hdr *) skb->data;
	/* The VL600 wants IPv6 packets to have an IPv4 ethertype
	 * Since this modem only supports IPv4 and IPv6, just set all
	 * frames to 0x0800 (ETH_P_IP)
	 */
	packet->h_proto = htons(ETH_P_IP);
	memset(&packet->dummy, 0, sizeof(packet->dummy));
	packet->len = cpu_to_le32(orig_len);

	frame = skb_push(skb, sizeof(*frame));
	memset(frame, 0, sizeof(*frame));
	frame->len = cpu_to_le32(full_len);
	frame->serial = cpu_to_le32(serial++);
	frame->pkt_cnt = cpu_to_le32(1);

	if (skb->len < full_len) /* Pad */
		skb_put(skb, full_len - skb->len);

	return skb;
}

