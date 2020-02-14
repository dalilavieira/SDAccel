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
typedef  scalar_t__ uint8_t ;
struct sk_buff {int /*<<< orphan*/  protocol; scalar_t__ data; struct net_device* dev; int /*<<< orphan*/  pkt_type; } ;
struct TYPE_3__ {int /*<<< orphan*/  tx_aborted_errors; int /*<<< orphan*/  tx_errors; int /*<<< orphan*/  rx_dropped; int /*<<< orphan*/  rx_crc_errors; int /*<<< orphan*/  rx_errors; } ;
struct net_device {int flags; scalar_t__* dev_addr; TYPE_1__ stats; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* copy_to_card ) (struct net_device*,int,int,struct arc_hardware*,int) ;int /*<<< orphan*/  (* copy_from_card ) (struct net_device*,int,int,scalar_t__,int) ;} ;
struct arcnet_local {scalar_t__ lastload_dest; TYPE_2__ hw; int /*<<< orphan*/  cur_tx; int /*<<< orphan*/  next_tx; } ;
struct arc_rfc1051 {int proto; } ;
struct arc_hardware {scalar_t__ dest; scalar_t__ source; int* offset; struct arc_rfc1051 rfc1051; scalar_t__ raw; } ;
struct archdr {struct arc_hardware soft; struct arc_hardware hard; } ;
typedef  int /*<<< orphan*/  __be16 ;

/* Variables and functions */
 int ARC_HDR_SIZE ; 
#define  ARC_P_ARP_RFC1051 131 
#define  ARC_P_IP_RFC1051 130 
 scalar_t__ BUGLVL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  D_DURING ; 
 int /*<<< orphan*/  D_NORMAL ; 
 int /*<<< orphan*/  D_SKB ; 
#define  ETH_P_ARP 129 
#define  ETH_P_IP 128 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int IFF_LOOPBACK ; 
 int IFF_NOARP ; 
 int IFF_PROMISC ; 
 int MTU ; 
 int MinTU ; 
 int /*<<< orphan*/  PACKET_BROADCAST ; 
 int /*<<< orphan*/  PACKET_OTHERHOST ; 
 int RFC1051_HDR_SIZE ; 
 int XMTU ; 
 struct sk_buff* alloc_skb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  arc_printk (int /*<<< orphan*/ ,struct net_device*,char*,int,...) ; 
 int /*<<< orphan*/  arcnet_dump_skb (struct net_device*,struct sk_buff*,char*) ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  memcpy (struct archdr*,struct archdr*,int) ; 
 struct arcnet_local* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_rx (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 struct archdr* skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  stub1 (struct net_device*,int,int,scalar_t__,int) ; 
 int /*<<< orphan*/  stub2 (struct net_device*,int,int,struct arc_hardware*,int) ; 
 int /*<<< orphan*/  stub3 (struct net_device*,int,int,struct arc_hardware*,int) ; 

__attribute__((used)) static __be16 type_trans(struct sk_buff *skb, struct net_device *dev)
{
	struct archdr *pkt = (struct archdr *)skb->data;
	struct arc_rfc1051 *soft = &pkt->soft.rfc1051;
	int hdr_size = ARC_HDR_SIZE + RFC1051_HDR_SIZE;

	/* Pull off the arcnet header. */
	skb_reset_mac_header(skb);
	skb_pull(skb, hdr_size);

	if (pkt->hard.dest == 0) {
		skb->pkt_type = PACKET_BROADCAST;
	} else if (dev->flags & IFF_PROMISC) {
		/* if we're not sending to ourselves :) */
		if (pkt->hard.dest != dev->dev_addr[0])
			skb->pkt_type = PACKET_OTHERHOST;
	}
	/* now return the protocol number */
	switch (soft->proto) {
	case ARC_P_IP_RFC1051:
		return htons(ETH_P_IP);
	case ARC_P_ARP_RFC1051:
		return htons(ETH_P_ARP);

	default:
		dev->stats.rx_errors++;
		dev->stats.rx_crc_errors++;
		return 0;
	}

	return htons(ETH_P_IP);
}

__attribute__((used)) static void rx(struct net_device *dev, int bufnum,
	       struct archdr *pkthdr, int length)
{
	struct arcnet_local *lp = netdev_priv(dev);
	struct sk_buff *skb;
	struct archdr *pkt = pkthdr;
	int ofs;

	arc_printk(D_DURING, dev, "it's a raw packet (length=%d)\n", length);

	if (length >= MinTU)
		ofs = 512 - length;
	else
		ofs = 256 - length;

	skb = alloc_skb(length + ARC_HDR_SIZE, GFP_ATOMIC);
	if (!skb) {
		dev->stats.rx_dropped++;
		return;
	}
	skb_put(skb, length + ARC_HDR_SIZE);
	skb->dev = dev;

	pkt = (struct archdr *)skb->data;

	/* up to sizeof(pkt->soft) has already been copied from the card */
	memcpy(pkt, pkthdr, sizeof(struct archdr));
	if (length > sizeof(pkt->soft))
		lp->hw.copy_from_card(dev, bufnum, ofs + sizeof(pkt->soft),
				      pkt->soft.raw + sizeof(pkt->soft),
				      length - sizeof(pkt->soft));

	if (BUGLVL(D_SKB))
		arcnet_dump_skb(dev, skb, "rx");

	skb->protocol = type_trans(skb, dev);
	netif_rx(skb);
}

__attribute__((used)) static int build_header(struct sk_buff *skb, struct net_device *dev,
			unsigned short type, uint8_t daddr)
{
	int hdr_size = ARC_HDR_SIZE + RFC1051_HDR_SIZE;
	struct archdr *pkt = skb_push(skb, hdr_size);
	struct arc_rfc1051 *soft = &pkt->soft.rfc1051;

	/* set the protocol ID according to RFC1051 */
	switch (type) {
	case ETH_P_IP:
		soft->proto = ARC_P_IP_RFC1051;
		break;
	case ETH_P_ARP:
		soft->proto = ARC_P_ARP_RFC1051;
		break;
	default:
		arc_printk(D_NORMAL, dev, "RFC1051: I don't understand protocol %d (%Xh)\n",
			   type, type);
		dev->stats.tx_errors++;
		dev->stats.tx_aborted_errors++;
		return 0;
	}

	/* Set the source hardware address.
	 *
	 * This is pretty pointless for most purposes, but it can help in
	 * debugging.  ARCnet does not allow us to change the source address
	 * in the actual packet sent.
	 */
	pkt->hard.source = *dev->dev_addr;

	/* see linux/net/ethernet/eth.c to see where I got the following */

	if (dev->flags & (IFF_LOOPBACK | IFF_NOARP)) {
		/* FIXME: fill in the last byte of the dest ipaddr here to
		 * better comply with RFC1051 in "noarp" mode.
		 */
		pkt->hard.dest = 0;
		return hdr_size;
	}
	/* otherwise, just fill it in and go! */
	pkt->hard.dest = daddr;

	return hdr_size;	/* success */
}

__attribute__((used)) static int prepare_tx(struct net_device *dev, struct archdr *pkt, int length,
		      int bufnum)
{
	struct arcnet_local *lp = netdev_priv(dev);
	struct arc_hardware *hard = &pkt->hard;
	int ofs;

	arc_printk(D_DURING, dev, "prepare_tx: txbufs=%d/%d/%d\n",
		   lp->next_tx, lp->cur_tx, bufnum);

	/* hard header is not included in packet length */
	length -= ARC_HDR_SIZE;

	if (length > XMTU) {
		/* should never happen! other people already check for this. */
		arc_printk(D_NORMAL, dev, "Bug!  prepare_tx with size %d (> %d)\n",
			   length, XMTU);
		length = XMTU;
	}
	if (length > MinTU) {
		hard->offset[0] = 0;
		hard->offset[1] = ofs = 512 - length;
	} else if (length > MTU) {
		hard->offset[0] = 0;
		hard->offset[1] = ofs = 512 - length - 3;
	} else {
		hard->offset[0] = ofs = 256 - length;
	}

	lp->hw.copy_to_card(dev, bufnum, 0, hard, ARC_HDR_SIZE);
	lp->hw.copy_to_card(dev, bufnum, ofs, &pkt->soft, length);

	lp->lastload_dest = hard->dest;

	return 1;		/* done */
}

