#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct wpan_dev {scalar_t__ short_addr; scalar_t__ pan_id; } ;
struct notifier_block {int dummy; } ;
typedef  struct net_device {scalar_t__ type; } const net_device ;
struct inet6_dev {int dummy; } ;
struct in6_addr {int /*<<< orphan*/ * s6_addr32; int /*<<< orphan*/  s6_addr; } ;
typedef  enum lowpan_lltypes { ____Placeholder_lowpan_lltypes } lowpan_lltypes ;
struct TYPE_10__ {TYPE_1__* wdev; } ;
struct TYPE_8__ {TYPE_2__* table; } ;
struct TYPE_9__ {int lltype; TYPE_3__ ctx; } ;
struct TYPE_7__ {int /*<<< orphan*/  flags; } ;
struct TYPE_6__ {struct wpan_dev* ieee802154_ptr; } ;

/* Variables and functions */
 scalar_t__ ARPHRD_6LOWPAN ; 
 int IEEE802154_PAN_ID_BROADCAST ; 
 int /*<<< orphan*/  LOWPAN_IPHC_CTX_FLAG_ACTIVE ; 
 int LOWPAN_IPHC_CTX_TABLE_SIZE ; 
 int LOWPAN_LLTYPE_IEEE802154 ; 
#define  NETDEV_CHANGE 130 
#define  NETDEV_DOWN 129 
#define  NETDEV_UP 128 
 int NOTIFY_DONE ; 
 int NOTIFY_OK ; 
 struct inet6_dev* __in6_dev_get (struct net_device const*) ; 
 int /*<<< orphan*/  __ipv6_addr_set_half (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  addrconf_add_linklocal (struct inet6_dev*,struct in6_addr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  clear_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ cpu_to_le16 (int) ; 
 int /*<<< orphan*/  htonl (int) ; 
 int /*<<< orphan*/  ieee802154_le16_to_be16 (int*,scalar_t__*) ; 
 TYPE_5__* lowpan_802154_dev (struct net_device const*) ; 
 int /*<<< orphan*/  lowpan_802154_is_valid_src_short_addr (scalar_t__) ; 
 TYPE_4__* lowpan_dev (struct net_device const*) ; 
 int lowpan_register_netdevice (struct net_device const*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 struct net_device const* netdev_notifier_info_to_dev (void*) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 int /*<<< orphan*/  unregister_netdevice (struct net_device const*) ; 

__attribute__((used)) static inline bool lowpan_is_ll(const struct net_device *dev,
				enum lowpan_lltypes lltype)
{
	return lowpan_dev(dev)->lltype == lltype;
}

__attribute__((used)) static inline int lowpan_dev_debugfs_init(struct net_device *dev)
{
	return 0;
}

__attribute__((used)) static inline void lowpan_dev_debugfs_exit(struct net_device *dev) { }

int lowpan_register_netdev(struct net_device *dev,
			   enum lowpan_lltypes lltype)
{
	int ret;

	rtnl_lock();
	ret = lowpan_register_netdevice(dev, lltype);
	rtnl_unlock();
	return ret;
}

void lowpan_unregister_netdevice(struct net_device *dev)
{
	unregister_netdevice(dev);
	lowpan_dev_debugfs_exit(dev);
}

void lowpan_unregister_netdev(struct net_device *dev)
{
	rtnl_lock();
	lowpan_unregister_netdevice(dev);
	rtnl_unlock();
}

int addrconf_ifid_802154_6lowpan(u8 *eui, struct net_device *dev)
{
	struct wpan_dev *wpan_dev = lowpan_802154_dev(dev)->wdev->ieee802154_ptr;

	/* Set short_addr autoconfiguration if short_addr is present only */
	if (!lowpan_802154_is_valid_src_short_addr(wpan_dev->short_addr))
		return -1;

	/* For either address format, all zero addresses MUST NOT be used */
	if (wpan_dev->pan_id == cpu_to_le16(0x0000) &&
	    wpan_dev->short_addr == cpu_to_le16(0x0000))
		return -1;

	/* Alternatively, if no PAN ID is known, 16 zero bits may be used */
	if (wpan_dev->pan_id == cpu_to_le16(IEEE802154_PAN_ID_BROADCAST))
		memset(eui, 0, 2);
	else
		ieee802154_le16_to_be16(eui, &wpan_dev->pan_id);

	/* The "Universal/Local" (U/L) bit shall be set to zero */
	eui[0] &= ~2;
	eui[2] = 0;
	eui[3] = 0xFF;
	eui[4] = 0xFE;
	eui[5] = 0;
	ieee802154_le16_to_be16(&eui[6], &wpan_dev->short_addr);
	return 0;
}

__attribute__((used)) static int lowpan_event(struct notifier_block *unused,
			unsigned long event, void *ptr)
{
	struct net_device *dev = netdev_notifier_info_to_dev(ptr);
	struct inet6_dev *idev;
	struct in6_addr addr;
	int i;

	if (dev->type != ARPHRD_6LOWPAN)
		return NOTIFY_DONE;

	idev = __in6_dev_get(dev);
	if (!idev)
		return NOTIFY_DONE;

	switch (event) {
	case NETDEV_UP:
	case NETDEV_CHANGE:
		/* (802.15.4 6LoWPAN short address slaac handling */
		if (lowpan_is_ll(dev, LOWPAN_LLTYPE_IEEE802154) &&
		    addrconf_ifid_802154_6lowpan(addr.s6_addr + 8, dev) == 0) {
			__ipv6_addr_set_half(&addr.s6_addr32[0],
					     htonl(0xFE800000), 0);
			addrconf_add_linklocal(idev, &addr, 0);
		}
		break;
	case NETDEV_DOWN:
		for (i = 0; i < LOWPAN_IPHC_CTX_TABLE_SIZE; i++)
			clear_bit(LOWPAN_IPHC_CTX_FLAG_ACTIVE,
				  &lowpan_dev(dev)->ctx.table[i].flags);
		break;
	default:
		return NOTIFY_DONE;
	}

	return NOTIFY_OK;
}

