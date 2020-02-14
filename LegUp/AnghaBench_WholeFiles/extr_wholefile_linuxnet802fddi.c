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
struct sk_buff {int /*<<< orphan*/  pkt_type; struct net_device* dev; scalar_t__ data; } ;
struct net_device {void const* dev_addr; void const* broadcast; int flags; int hard_header_len; int min_mtu; int tx_queue_len; int /*<<< orphan*/  addr_len; void* max_mtu; void* mtu; int /*<<< orphan*/  type; int /*<<< orphan*/ * header_ops; } ;
struct TYPE_5__ {int* oui; void* ethertype; int /*<<< orphan*/  ctrl; void* ssap; void* dsap; } ;
struct TYPE_4__ {int dsap; } ;
struct TYPE_6__ {TYPE_2__ llc_snap; TYPE_1__ llc_8022_1; } ;
struct fddihdr {int* saddr; int* daddr; TYPE_3__ hdr; int /*<<< orphan*/  fc; } ;
typedef  void* __be16 ;

/* Variables and functions */
 int /*<<< orphan*/  ARPHRD_FDDI ; 
 unsigned short ETH_P_802_2 ; 
 unsigned short ETH_P_ARP ; 
 unsigned short ETH_P_IP ; 
 unsigned short ETH_P_IPV6 ; 
 void* FDDI_EXTENDED_SAP ; 
 int /*<<< orphan*/  FDDI_FC_K_ASYNC_LLC_DEF ; 
 int FDDI_K_8022_HLEN ; 
 int /*<<< orphan*/  FDDI_K_ALEN ; 
 void* FDDI_K_SNAP_DLEN ; 
 int FDDI_K_SNAP_HLEN ; 
 int /*<<< orphan*/  FDDI_UI_CMD ; 
 int IFF_BROADCAST ; 
 int IFF_MULTICAST ; 
 int IFF_PROMISC ; 
 int /*<<< orphan*/  NET_NAME_UNKNOWN ; 
 int /*<<< orphan*/  PACKET_BROADCAST ; 
 int /*<<< orphan*/  PACKET_MULTICAST ; 
 int /*<<< orphan*/  PACKET_OTHERHOST ; 
 struct net_device* alloc_netdev (int,char*,int /*<<< orphan*/ ,void (*) (struct net_device*)) ; 
 int /*<<< orphan*/  fddi_header_ops ; 
 void* htons (unsigned short) ; 
 scalar_t__ memcmp (int*,void const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int*,void const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void const*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 struct fddihdr* skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 

__attribute__((used)) static int fddi_header(struct sk_buff *skb, struct net_device *dev,
		       unsigned short type,
		       const void *daddr, const void *saddr, unsigned int len)
{
	int hl = FDDI_K_SNAP_HLEN;
	struct fddihdr *fddi;

	if(type != ETH_P_IP && type != ETH_P_IPV6 && type != ETH_P_ARP)
		hl=FDDI_K_8022_HLEN-3;
	fddi = skb_push(skb, hl);
	fddi->fc			 = FDDI_FC_K_ASYNC_LLC_DEF;
	if(type == ETH_P_IP || type == ETH_P_IPV6 || type == ETH_P_ARP)
	{
		fddi->hdr.llc_snap.dsap		 = FDDI_EXTENDED_SAP;
		fddi->hdr.llc_snap.ssap		 = FDDI_EXTENDED_SAP;
		fddi->hdr.llc_snap.ctrl		 = FDDI_UI_CMD;
		fddi->hdr.llc_snap.oui[0]	 = 0x00;
		fddi->hdr.llc_snap.oui[1]	 = 0x00;
		fddi->hdr.llc_snap.oui[2]	 = 0x00;
		fddi->hdr.llc_snap.ethertype	 = htons(type);
	}

	/* Set the source and destination hardware addresses */

	if (saddr != NULL)
		memcpy(fddi->saddr, saddr, dev->addr_len);
	else
		memcpy(fddi->saddr, dev->dev_addr, dev->addr_len);

	if (daddr != NULL)
	{
		memcpy(fddi->daddr, daddr, dev->addr_len);
		return hl;
	}

	return -hl;
}

__be16 fddi_type_trans(struct sk_buff *skb, struct net_device *dev)
{
	struct fddihdr *fddi = (struct fddihdr *)skb->data;
	__be16 type;

	/*
	 * Set mac.raw field to point to FC byte, set data field to point
	 * to start of packet data.  Assume 802.2 SNAP frames for now.
	 */

	skb->dev = dev;
	skb_reset_mac_header(skb);	/* point to frame control (FC) */

	if(fddi->hdr.llc_8022_1.dsap==0xe0)
	{
		skb_pull(skb, FDDI_K_8022_HLEN-3);
		type = htons(ETH_P_802_2);
	}
	else
	{
		skb_pull(skb, FDDI_K_SNAP_HLEN);		/* adjust for 21 byte header */
		type=fddi->hdr.llc_snap.ethertype;
	}

	/* Set packet type based on destination address and flag settings */

	if (*fddi->daddr & 0x01)
	{
		if (memcmp(fddi->daddr, dev->broadcast, FDDI_K_ALEN) == 0)
			skb->pkt_type = PACKET_BROADCAST;
		else
			skb->pkt_type = PACKET_MULTICAST;
	}

	else if (dev->flags & IFF_PROMISC)
	{
		if (memcmp(fddi->daddr, dev->dev_addr, FDDI_K_ALEN))
			skb->pkt_type = PACKET_OTHERHOST;
	}

	/* Assume 802.2 SNAP frames, for now */

	return type;
}

__attribute__((used)) static void fddi_setup(struct net_device *dev)
{
	dev->header_ops		= &fddi_header_ops;
	dev->type		= ARPHRD_FDDI;
	dev->hard_header_len	= FDDI_K_SNAP_HLEN+3;	/* Assume 802.2 SNAP hdr len + 3 pad bytes */
	dev->mtu		= FDDI_K_SNAP_DLEN;	/* Assume max payload of 802.2 SNAP frame */
	dev->min_mtu		= FDDI_K_SNAP_HLEN;
	dev->max_mtu		= FDDI_K_SNAP_DLEN;
	dev->addr_len		= FDDI_K_ALEN;
	dev->tx_queue_len	= 100;			/* Long queues on FDDI */
	dev->flags		= IFF_BROADCAST | IFF_MULTICAST;

	memset(dev->broadcast, 0xFF, FDDI_K_ALEN);
}

struct net_device *alloc_fddidev(int sizeof_priv)
{
	return alloc_netdev(sizeof_priv, "fddi%d", NET_NAME_UNKNOWN,
			    fddi_setup);
}

