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
struct nlattr {int dummy; } ;
struct netlink_ext_ack {int dummy; } ;
typedef  struct net_device {int ifindex; int hard_header_len; int flags; int needs_free_netdev; scalar_t__ type; int neigh_priv_len; TYPE_1__* ieee802154_ptr; int /*<<< orphan*/  needed_tailroom; scalar_t__ needed_headroom; int /*<<< orphan*/  dev_addr; int /*<<< orphan*/  features; int /*<<< orphan*/ * header_ops; int /*<<< orphan*/ * netdev_ops; int /*<<< orphan*/  priv_flags; int /*<<< orphan*/  broadcast; } const net_device ;
struct net {int dummy; } ;
struct neighbour {int dummy; } ;
struct lowpan_802154_neigh {int /*<<< orphan*/  short_addr; } ;
struct list_head {int dummy; } ;
struct ipv6hdr {int dummy; } ;
struct TYPE_4__ {struct net_device const* wdev; } ;
struct TYPE_3__ {struct net_device const* lowpan_dev; } ;

/* Variables and functions */
 scalar_t__ ARPHRD_IEEE802154 ; 
 int /*<<< orphan*/  ASSERT_RTNL () ; 
 int EBUSY ; 
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ IEEE802154_ADDR_LEN ; 
 int /*<<< orphan*/  IEEE802154_ADDR_SHORT_UNSPEC ; 
 int IFF_BROADCAST ; 
 int IFF_MULTICAST ; 
 int /*<<< orphan*/  IFF_NO_QUEUE ; 
 size_t IFLA_ADDRESS ; 
 size_t IFLA_LINK ; 
 scalar_t__ LOWPAN_IPHC_MAX_HEADER_LEN ; 
 int /*<<< orphan*/  LOWPAN_LLTYPE_IEEE802154 ; 
 int /*<<< orphan*/  NETIF_F_NETNS_LOCAL ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 struct net_device const* dev_get_by_index (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_net (struct net_device const*) ; 
 int /*<<< orphan*/  dev_put (struct net_device const*) ; 
 TYPE_2__* lowpan_802154_dev (struct net_device const*) ; 
 struct lowpan_802154_neigh* lowpan_802154_neigh (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lowpan_header_ops ; 
 int /*<<< orphan*/  lowpan_netdev_ops ; 
 int lowpan_register_netdevice (struct net_device const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lowpan_rx_exit () ; 
 int /*<<< orphan*/  lowpan_rx_init () ; 
 int /*<<< orphan*/  lowpan_unregister_netdevice (struct net_device const*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int,scalar_t__) ; 
 int /*<<< orphan*/  neighbour_priv (struct neighbour*) ; 
 int /*<<< orphan*/  netdev_lockdep_set_classes (struct net_device const*) ; 
 int /*<<< orphan*/  nla_get_u32 (struct nlattr*) ; 
 scalar_t__ nla_len (struct nlattr*) ; 
 int /*<<< orphan*/  open_count ; 
 int /*<<< orphan*/  pr_debug (char*) ; 

__attribute__((used)) static int lowpan_dev_init(struct net_device *ldev)
{
	netdev_lockdep_set_classes(ldev);

	return 0;
}

__attribute__((used)) static int lowpan_open(struct net_device *dev)
{
	if (!open_count)
		lowpan_rx_init();
	open_count++;
	return 0;
}

__attribute__((used)) static int lowpan_stop(struct net_device *dev)
{
	open_count--;
	if (!open_count)
		lowpan_rx_exit();
	return 0;
}

__attribute__((used)) static int lowpan_neigh_construct(struct net_device *dev, struct neighbour *n)
{
	struct lowpan_802154_neigh *neigh = lowpan_802154_neigh(neighbour_priv(n));

	/* default no short_addr is available for a neighbour */
	neigh->short_addr = cpu_to_le16(IEEE802154_ADDR_SHORT_UNSPEC);
	return 0;
}

__attribute__((used)) static int lowpan_get_iflink(const struct net_device *dev)
{
	return lowpan_802154_dev(dev)->wdev->ifindex;
}

__attribute__((used)) static void lowpan_setup(struct net_device *ldev)
{
	memset(ldev->broadcast, 0xff, IEEE802154_ADDR_LEN);
	/* We need an ipv6hdr as minimum len when calling xmit */
	ldev->hard_header_len	= sizeof(struct ipv6hdr);
	ldev->flags		= IFF_BROADCAST | IFF_MULTICAST;
	ldev->priv_flags	|= IFF_NO_QUEUE;

	ldev->netdev_ops	= &lowpan_netdev_ops;
	ldev->header_ops	= &lowpan_header_ops;
	ldev->needs_free_netdev	= true;
	ldev->features		|= NETIF_F_NETNS_LOCAL;
}

__attribute__((used)) static int lowpan_validate(struct nlattr *tb[], struct nlattr *data[],
			   struct netlink_ext_ack *extack)
{
	if (tb[IFLA_ADDRESS]) {
		if (nla_len(tb[IFLA_ADDRESS]) != IEEE802154_ADDR_LEN)
			return -EINVAL;
	}
	return 0;
}

__attribute__((used)) static int lowpan_newlink(struct net *src_net, struct net_device *ldev,
			  struct nlattr *tb[], struct nlattr *data[],
			  struct netlink_ext_ack *extack)
{
	struct net_device *wdev;
	int ret;

	ASSERT_RTNL();

	pr_debug("adding new link\n");

	if (!tb[IFLA_LINK])
		return -EINVAL;
	/* find and hold wpan device */
	wdev = dev_get_by_index(dev_net(ldev), nla_get_u32(tb[IFLA_LINK]));
	if (!wdev)
		return -ENODEV;
	if (wdev->type != ARPHRD_IEEE802154) {
		dev_put(wdev);
		return -EINVAL;
	}

	if (wdev->ieee802154_ptr->lowpan_dev) {
		dev_put(wdev);
		return -EBUSY;
	}

	lowpan_802154_dev(ldev)->wdev = wdev;
	/* Set the lowpan hardware address to the wpan hardware address. */
	memcpy(ldev->dev_addr, wdev->dev_addr, IEEE802154_ADDR_LEN);
	/* We need headroom for possible wpan_dev_hard_header call and tailroom
	 * for encryption/fcs handling. The lowpan interface will replace
	 * the IPv6 header with 6LoWPAN header. At worst case the 6LoWPAN
	 * header has LOWPAN_IPHC_MAX_HEADER_LEN more bytes than the IPv6
	 * header.
	 */
	ldev->needed_headroom = LOWPAN_IPHC_MAX_HEADER_LEN +
				wdev->needed_headroom;
	ldev->needed_tailroom = wdev->needed_tailroom;

	ldev->neigh_priv_len = sizeof(struct lowpan_802154_neigh);

	ret = lowpan_register_netdevice(ldev, LOWPAN_LLTYPE_IEEE802154);
	if (ret < 0) {
		dev_put(wdev);
		return ret;
	}

	wdev->ieee802154_ptr->lowpan_dev = ldev;
	return 0;
}

__attribute__((used)) static void lowpan_dellink(struct net_device *ldev, struct list_head *head)
{
	struct net_device *wdev = lowpan_802154_dev(ldev)->wdev;

	ASSERT_RTNL();

	wdev->ieee802154_ptr->lowpan_dev = NULL;
	lowpan_unregister_netdevice(ldev);
	dev_put(wdev);
}

