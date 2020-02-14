#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct sk_buff {int /*<<< orphan*/  pkt_type; int /*<<< orphan*/  network_header; int /*<<< orphan*/  mac_header; struct net_device* dev; int /*<<< orphan*/  protocol; scalar_t__ len; } ;
struct net_device_stats {int /*<<< orphan*/  rx_bytes; int /*<<< orphan*/  rx_packets; int /*<<< orphan*/  rx_dropped; } ;
struct net_device {void const* dev_addr; int /*<<< orphan*/  flags; int /*<<< orphan*/  type; scalar_t__ addr_len; scalar_t__ hard_header_len; int /*<<< orphan*/ * header_ops; int /*<<< orphan*/ * netdev_ops; int /*<<< orphan*/  mtu; struct net_device_stats stats; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARPHRD_NETROM ; 
 scalar_t__ AX25_ADDR_LEN ; 
 unsigned char AX25_CBIT ; 
 unsigned char AX25_EBIT ; 
 unsigned char AX25_SSSID_SPARE ; 
 int /*<<< orphan*/  ETH_P_IP ; 
 int /*<<< orphan*/  IFF_NOARP ; 
 int /*<<< orphan*/  NR_MAX_PACKET_SIZE ; 
 scalar_t__ NR_NETWORK_LEN ; 
 int /*<<< orphan*/  NR_PROTOEXT ; 
 void* NR_PROTO_IP ; 
 scalar_t__ NR_TRANSPORT_LEN ; 
 int /*<<< orphan*/  PACKET_HOST ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,void const*,scalar_t__) ; 
 int /*<<< orphan*/  netif_running (struct net_device*) ; 
 int /*<<< orphan*/  netif_rx (struct sk_buff*) ; 
 int /*<<< orphan*/  nr_header_ops ; 
 int /*<<< orphan*/  nr_netdev_ops ; 
 unsigned char* skb_push (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_reset_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  sysctl_netrom_network_ttl_initialiser ; 

int nr_rx_ip(struct sk_buff *skb, struct net_device *dev)
{
	struct net_device_stats *stats = &dev->stats;

	if (!netif_running(dev)) {
		stats->rx_dropped++;
		return 0;
	}

	stats->rx_packets++;
	stats->rx_bytes += skb->len;

	skb->protocol = htons(ETH_P_IP);

	/* Spoof incoming device */
	skb->dev      = dev;
	skb->mac_header = skb->network_header;
	skb_reset_network_header(skb);
	skb->pkt_type = PACKET_HOST;

	netif_rx(skb);

	return 1;
}

__attribute__((used)) static int nr_header(struct sk_buff *skb, struct net_device *dev,
		     unsigned short type,
		     const void *daddr, const void *saddr, unsigned int len)
{
	unsigned char *buff = skb_push(skb, NR_NETWORK_LEN + NR_TRANSPORT_LEN);

	memcpy(buff, (saddr != NULL) ? saddr : dev->dev_addr, dev->addr_len);
	buff[6] &= ~AX25_CBIT;
	buff[6] &= ~AX25_EBIT;
	buff[6] |= AX25_SSSID_SPARE;
	buff    += AX25_ADDR_LEN;

	if (daddr != NULL)
		memcpy(buff, daddr, dev->addr_len);
	buff[6] &= ~AX25_CBIT;
	buff[6] |= AX25_EBIT;
	buff[6] |= AX25_SSSID_SPARE;
	buff    += AX25_ADDR_LEN;

	*buff++ = sysctl_netrom_network_ttl_initialiser;

	*buff++ = NR_PROTO_IP;
	*buff++ = NR_PROTO_IP;
	*buff++ = 0;
	*buff++ = 0;
	*buff++ = NR_PROTOEXT;

	if (daddr != NULL)
		return 37;

	return -37;
}

void nr_setup(struct net_device *dev)
{
	dev->mtu		= NR_MAX_PACKET_SIZE;
	dev->netdev_ops		= &nr_netdev_ops;
	dev->header_ops		= &nr_header_ops;
	dev->hard_header_len	= NR_NETWORK_LEN + NR_TRANSPORT_LEN;
	dev->addr_len		= AX25_ADDR_LEN;
	dev->type		= ARPHRD_NETROM;

	/* New-style flags. */
	dev->flags		= IFF_NOARP;
}

