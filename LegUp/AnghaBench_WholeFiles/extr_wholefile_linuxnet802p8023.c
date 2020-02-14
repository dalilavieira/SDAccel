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
struct sk_buff {int /*<<< orphan*/  len; struct net_device* dev; } ;
struct net_device {int dummy; } ;
struct datalink_proto {int (* request ) (struct datalink_proto*,struct sk_buff*,unsigned char*) ;scalar_t__ header_length; } ;

/* Variables and functions */
 int /*<<< orphan*/  ETH_P_802_3 ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  dev_hard_header (struct sk_buff*,struct net_device*,int /*<<< orphan*/ ,unsigned char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int dev_queue_xmit (struct sk_buff*) ; 
 int /*<<< orphan*/  kfree (struct datalink_proto*) ; 
 struct datalink_proto* kmalloc (int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int p8023_request(struct datalink_proto *dl,
			 struct sk_buff *skb, unsigned char *dest_node)
{
	struct net_device *dev = skb->dev;

	dev_hard_header(skb, dev, ETH_P_802_3, dest_node, NULL, skb->len);
	return dev_queue_xmit(skb);
}

struct datalink_proto *make_8023_client(void)
{
	struct datalink_proto *proto = kmalloc(sizeof(*proto), GFP_ATOMIC);

	if (proto) {
		proto->header_length = 0;
		proto->request	     = p8023_request;
	}
	return proto;
}

void destroy_8023_client(struct datalink_proto *dl)
{
	kfree(dl);
}

