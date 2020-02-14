#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  unsigned long u32 ;
struct sk_buff {int dummy; } ;
struct TYPE_2__ {struct device* parent; } ;
struct net_device {int mtu; int /*<<< orphan*/  flags; int /*<<< orphan*/ * ethtool_ops; int /*<<< orphan*/ * netdev_ops; TYPE_1__ dev; } ;
struct device {int dummy; } ;
struct aq_nic_s {struct net_device* ndev; } ;
struct aq_nic_cfg_s {int hw_features; int is_lro; } ;
typedef  int netdev_features_t ;
typedef  int /*<<< orphan*/  atomic_t ;

/* Variables and functions */
 int /*<<< orphan*/  AQ_CFG_VECS_MAX ; 
 scalar_t__ ETH_HLEN ; 
 int NETIF_F_LRO ; 
 struct net_device* alloc_etherdev_mq (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  aq_ethtool_ops ; 
 int /*<<< orphan*/  aq_ndev_ops ; 
 int /*<<< orphan*/  aq_nic_deinit (struct aq_nic_s*) ; 
 struct aq_nic_cfg_s* aq_nic_get_cfg (struct aq_nic_s*) ; 
 int aq_nic_init (struct aq_nic_s*) ; 
 int aq_nic_set_mac (struct aq_nic_s*,struct net_device*) ; 
 int aq_nic_set_mtu (struct aq_nic_s*,scalar_t__) ; 
 int /*<<< orphan*/  aq_nic_set_multicast_list (struct aq_nic_s*,struct net_device*) ; 
 int /*<<< orphan*/  aq_nic_set_packet_filter (struct aq_nic_s*,int /*<<< orphan*/ ) ; 
 int aq_nic_start (struct aq_nic_s*) ; 
 int aq_nic_stop (struct aq_nic_s*) ; 
 int aq_nic_xmit (struct aq_nic_s*,struct sk_buff*) ; 
 unsigned long atomic_cmpxchg (int /*<<< orphan*/ *,unsigned long,unsigned long) ; 
 unsigned long atomic_read (int /*<<< orphan*/ *) ; 
 int eth_mac_addr (struct net_device*,void*) ; 
 struct aq_nic_s* netdev_priv (struct net_device*) ; 
 scalar_t__ netif_running (struct net_device*) ; 

__attribute__((used)) static inline void aq_utils_obj_set(atomic_t *flags, u32 mask)
{
	unsigned long flags_old, flags_new;

	do {
		flags_old = atomic_read(flags);
		flags_new = flags_old | (mask);
	} while (atomic_cmpxchg(flags, flags_old, flags_new) != flags_old);
}

__attribute__((used)) static inline void aq_utils_obj_clear(atomic_t *flags, u32 mask)
{
	unsigned long flags_old, flags_new;

	do {
		flags_old = atomic_read(flags);
		flags_new = flags_old & ~(mask);
	} while (atomic_cmpxchg(flags, flags_old, flags_new) != flags_old);
}

__attribute__((used)) static inline bool aq_utils_obj_test(atomic_t *flags, u32 mask)
{
	return atomic_read(flags) & mask;
}

__attribute__((used)) static inline struct device *aq_nic_get_dev(struct aq_nic_s *self)
{
	return self->ndev->dev.parent;
}

struct net_device *aq_ndev_alloc(void)
{
	struct net_device *ndev = NULL;
	struct aq_nic_s *aq_nic = NULL;

	ndev = alloc_etherdev_mq(sizeof(struct aq_nic_s), AQ_CFG_VECS_MAX);
	if (!ndev)
		return NULL;

	aq_nic = netdev_priv(ndev);
	aq_nic->ndev = ndev;
	ndev->netdev_ops = &aq_ndev_ops;
	ndev->ethtool_ops = &aq_ethtool_ops;

	return ndev;
}

__attribute__((used)) static int aq_ndev_open(struct net_device *ndev)
{
	int err = 0;
	struct aq_nic_s *aq_nic = netdev_priv(ndev);

	err = aq_nic_init(aq_nic);
	if (err < 0)
		goto err_exit;
	err = aq_nic_start(aq_nic);
	if (err < 0)
		goto err_exit;

err_exit:
	if (err < 0)
		aq_nic_deinit(aq_nic);
	return err;
}

__attribute__((used)) static int aq_ndev_close(struct net_device *ndev)
{
	int err = 0;
	struct aq_nic_s *aq_nic = netdev_priv(ndev);

	err = aq_nic_stop(aq_nic);
	if (err < 0)
		goto err_exit;
	aq_nic_deinit(aq_nic);

err_exit:
	return err;
}

__attribute__((used)) static int aq_ndev_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
	struct aq_nic_s *aq_nic = netdev_priv(ndev);

	return aq_nic_xmit(aq_nic, skb);
}

__attribute__((used)) static int aq_ndev_change_mtu(struct net_device *ndev, int new_mtu)
{
	struct aq_nic_s *aq_nic = netdev_priv(ndev);
	int err = aq_nic_set_mtu(aq_nic, new_mtu + ETH_HLEN);

	if (err < 0)
		goto err_exit;
	ndev->mtu = new_mtu;

err_exit:
	return err;
}

__attribute__((used)) static int aq_ndev_set_features(struct net_device *ndev,
				netdev_features_t features)
{
	struct aq_nic_s *aq_nic = netdev_priv(ndev);
	struct aq_nic_cfg_s *aq_cfg = aq_nic_get_cfg(aq_nic);
	bool is_lro = false;

	if (aq_cfg->hw_features & NETIF_F_LRO) {
		is_lro = features & NETIF_F_LRO;

		if (aq_cfg->is_lro != is_lro) {
			aq_cfg->is_lro = is_lro;

			if (netif_running(ndev)) {
				aq_ndev_close(ndev);
				aq_ndev_open(ndev);
			}
		}
	}

	return 0;
}

__attribute__((used)) static int aq_ndev_set_mac_address(struct net_device *ndev, void *addr)
{
	struct aq_nic_s *aq_nic = netdev_priv(ndev);
	int err = 0;

	err = eth_mac_addr(ndev, addr);
	if (err < 0)
		goto err_exit;
	err = aq_nic_set_mac(aq_nic, ndev);
	if (err < 0)
		goto err_exit;

err_exit:
	return err;
}

__attribute__((used)) static void aq_ndev_set_multicast_settings(struct net_device *ndev)
{
	struct aq_nic_s *aq_nic = netdev_priv(ndev);

	aq_nic_set_packet_filter(aq_nic, ndev->flags);

	aq_nic_set_multicast_list(aq_nic, ndev);
}

