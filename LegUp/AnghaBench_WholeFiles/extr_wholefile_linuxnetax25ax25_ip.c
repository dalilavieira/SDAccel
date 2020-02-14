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
struct sk_buff {int dummy; } ;
struct net_device {int dummy; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;
typedef  int /*<<< orphan*/  ax25_digi ;

/* Variables and functions */
 int AX25_HEADER_LEN ; 
 int /*<<< orphan*/  NETDEV_TX_OK ; 
 int ax25_addr_parse (char const*,unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 

__attribute__((used)) static int ax25_hard_header(struct sk_buff *skb, struct net_device *dev,
			    unsigned short type, const void *daddr,
			    const void *saddr, unsigned int len)
{
	return -AX25_HEADER_LEN;
}

netdev_tx_t ax25_ip_xmit(struct sk_buff *skb)
{
	kfree_skb(skb);
	return NETDEV_TX_OK;
}

__attribute__((used)) static bool ax25_validate_header(const char *header, unsigned int len)
{
	ax25_digi digi;

	if (!len)
		return false;

	if (header[0])
		return true;

	return ax25_addr_parse(header + 1, len - 1, NULL, NULL, &digi, NULL,
			       NULL);
}

