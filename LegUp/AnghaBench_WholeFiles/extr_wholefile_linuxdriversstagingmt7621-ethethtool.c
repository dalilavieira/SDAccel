#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_9__ ;
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;
typedef  struct TYPE_20__   TYPE_17__ ;
typedef  struct TYPE_19__   TYPE_13__ ;
typedef  struct TYPE_18__   TYPE_12__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct net_device {TYPE_12__* ethtool_ops; TYPE_5__* netdev_ops; } ;
struct mtk_soc_data {scalar_t__ dma_ring_size; scalar_t__* reg_table; } ;
struct mtk_mac {scalar_t__ phy_flags; TYPE_8__* hw; struct mtk_hw_stats* hw_stats; TYPE_9__* phy_dev; } ;
struct mtk_hw_stats {int /*<<< orphan*/  syncp; int /*<<< orphan*/  stats_lock; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_ringparam {int tx_pending; int rx_pending; scalar_t__ rx_max_pending; scalar_t__ tx_max_pending; } ;
struct TYPE_23__ {size_t phy_address; } ;
struct ethtool_link_ksettings {TYPE_3__ base; } ;
struct ethtool_drvinfo {int n_stats; int /*<<< orphan*/  bus_info; int /*<<< orphan*/  driver; } ;
struct TYPE_21__ {size_t addr; } ;
struct TYPE_29__ {int link; TYPE_1__ mdio; } ;
struct TYPE_26__ {scalar_t__ tx_ring_size; } ;
struct TYPE_28__ {int msg_enable; struct mtk_soc_data* soc; TYPE_6__ tx_ring; TYPE_7__* rx_ring; TYPE_17__* dev; scalar_t__ mii_bus; TYPE_2__* phy; } ;
struct TYPE_27__ {scalar_t__ rx_ring_size; } ;
struct TYPE_25__ {int (* ndo_open ) (struct net_device*) ;int /*<<< orphan*/  (* ndo_stop ) (struct net_device*) ;} ;
struct TYPE_24__ {int /*<<< orphan*/  name; } ;
struct TYPE_22__ {TYPE_9__** phy; scalar_t__* phy_node; } ;
struct TYPE_20__ {TYPE_4__* driver; } ;
struct TYPE_19__ {size_t idx; int /*<<< orphan*/  name; } ;
struct TYPE_18__ {void (* get_strings ) (struct net_device*,int,int /*<<< orphan*/ *) ;int (* get_sset_count ) (struct net_device*,int) ;void (* get_ethtool_stats ) (struct net_device*,struct ethtool_stats*,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 void* BIT (scalar_t__) ; 
 int EINVAL ; 
 int ENODEV ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  ETH_GSTRING_LEN ; 
#define  ETH_SS_STATS 128 
 int MTK_HW_STATS_LEN ; 
 scalar_t__ MTK_PHY_FLAG_ATTACH ; 
 scalar_t__ MTK_PHY_FLAG_PORT ; 
 size_t MTK_REG_MTK_COUNTER_BASE ; 
 int /*<<< orphan*/  dev_name (TYPE_17__*) ; 
 int ethtool_op_get_link (struct net_device*) ; 
 scalar_t__ fls (scalar_t__) ; 
 int genphy_restart_aneg (TYPE_9__*) ; 
 int genphy_update_link (TYPE_9__*) ; 
 TYPE_9__* mdiobus_get_phy (scalar_t__,size_t) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_13__* mtk_ethtool_hw_stats ; 
 TYPE_12__ mtk_ethtool_ops ; 
 int /*<<< orphan*/  mtk_stats_update_mac (struct mtk_mac*) ; 
 struct mtk_mac* netdev_priv (struct net_device*) ; 
 scalar_t__ netif_device_present (struct net_device*) ; 
 scalar_t__ netif_running (struct net_device*) ; 
 int /*<<< orphan*/  phy_ethtool_ksettings_get (TYPE_9__*,struct ethtool_link_ksettings*) ; 
 int phy_ethtool_ksettings_set (TYPE_9__*,struct ethtool_link_ksettings const*) ; 
 int phy_read_status (TYPE_9__*) ; 
 scalar_t__ spin_trylock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct net_device*) ; 
 int stub2 (struct net_device*) ; 
 unsigned int u64_stats_fetch_begin_irq (int /*<<< orphan*/ *) ; 
 scalar_t__ u64_stats_fetch_retry_irq (int /*<<< orphan*/ *,unsigned int) ; 

__attribute__((used)) static int mtk_get_link_ksettings(struct net_device *dev,
				  struct ethtool_link_ksettings *cmd)
{
	struct mtk_mac *mac = netdev_priv(dev);
	int err;

	if (!mac->phy_dev)
		return -ENODEV;

	if (mac->phy_flags == MTK_PHY_FLAG_ATTACH) {
		err = phy_read_status(mac->phy_dev);
		if (err)
			return -ENODEV;
	}

	phy_ethtool_ksettings_get(mac->phy_dev, cmd);
	return 0;
}

__attribute__((used)) static int mtk_set_link_ksettings(struct net_device *dev,
				  const struct ethtool_link_ksettings *cmd)
{
	struct mtk_mac *mac = netdev_priv(dev);

	if (!mac->phy_dev)
		return -ENODEV;

	if (cmd->base.phy_address != mac->phy_dev->mdio.addr) {
		if (mac->hw->phy->phy_node[cmd->base.phy_address]) {
			mac->phy_dev = mac->hw->phy->phy[cmd->base.phy_address];
			mac->phy_flags = MTK_PHY_FLAG_PORT;
		} else if (mac->hw->mii_bus) {
			mac->phy_dev = mdiobus_get_phy(mac->hw->mii_bus,
						       cmd->base.phy_address);
			if (!mac->phy_dev)
				return -ENODEV;
			mac->phy_flags = MTK_PHY_FLAG_ATTACH;
		} else {
			return -ENODEV;
		}
	}

	return phy_ethtool_ksettings_set(mac->phy_dev, cmd);
}

__attribute__((used)) static void mtk_get_drvinfo(struct net_device *dev,
			    struct ethtool_drvinfo *info)
{
	struct mtk_mac *mac = netdev_priv(dev);
	struct mtk_soc_data *soc = mac->hw->soc;

	strlcpy(info->driver, mac->hw->dev->driver->name, sizeof(info->driver));
	strlcpy(info->bus_info, dev_name(mac->hw->dev), sizeof(info->bus_info));

	if (soc->reg_table[MTK_REG_MTK_COUNTER_BASE])
		info->n_stats = MTK_HW_STATS_LEN;
}

__attribute__((used)) static u32 mtk_get_msglevel(struct net_device *dev)
{
	struct mtk_mac *mac = netdev_priv(dev);

	return mac->hw->msg_enable;
}

__attribute__((used)) static void mtk_set_msglevel(struct net_device *dev, u32 value)
{
	struct mtk_mac *mac = netdev_priv(dev);

	mac->hw->msg_enable = value;
}

__attribute__((used)) static int mtk_nway_reset(struct net_device *dev)
{
	struct mtk_mac *mac = netdev_priv(dev);

	if (!mac->phy_dev)
		return -EOPNOTSUPP;

	return genphy_restart_aneg(mac->phy_dev);
}

__attribute__((used)) static u32 mtk_get_link(struct net_device *dev)
{
	struct mtk_mac *mac = netdev_priv(dev);
	int err;

	if (!mac->phy_dev)
		goto out_get_link;

	if (mac->phy_flags == MTK_PHY_FLAG_ATTACH) {
		err = genphy_update_link(mac->phy_dev);
		if (err)
			goto out_get_link;
	}

	return mac->phy_dev->link;

out_get_link:
	return ethtool_op_get_link(dev);
}

__attribute__((used)) static int mtk_set_ringparam(struct net_device *dev,
			     struct ethtool_ringparam *ring)
{
	struct mtk_mac *mac = netdev_priv(dev);

	if ((ring->tx_pending < 2) ||
	    (ring->rx_pending < 2) ||
	    (ring->rx_pending > mac->hw->soc->dma_ring_size) ||
	    (ring->tx_pending > mac->hw->soc->dma_ring_size))
		return -EINVAL;

	dev->netdev_ops->ndo_stop(dev);

	mac->hw->tx_ring.tx_ring_size = BIT(fls(ring->tx_pending) - 1);
	mac->hw->rx_ring[0].rx_ring_size = BIT(fls(ring->rx_pending) - 1);

	return dev->netdev_ops->ndo_open(dev);
}

__attribute__((used)) static void mtk_get_ringparam(struct net_device *dev,
			      struct ethtool_ringparam *ring)
{
	struct mtk_mac *mac = netdev_priv(dev);

	ring->rx_max_pending = mac->hw->soc->dma_ring_size;
	ring->tx_max_pending = mac->hw->soc->dma_ring_size;
	ring->rx_pending = mac->hw->rx_ring[0].rx_ring_size;
	ring->tx_pending = mac->hw->tx_ring.tx_ring_size;
}

__attribute__((used)) static void mtk_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
	int i;

	switch (stringset) {
	case ETH_SS_STATS:
		for (i = 0; i < MTK_HW_STATS_LEN; i++) {
			memcpy(data, mtk_ethtool_hw_stats[i].name,
			       ETH_GSTRING_LEN);
			data += ETH_GSTRING_LEN;
		}
		break;
	}
}

__attribute__((used)) static int mtk_get_sset_count(struct net_device *dev, int sset)
{
	switch (sset) {
	case ETH_SS_STATS:
		return MTK_HW_STATS_LEN;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static void mtk_get_ethtool_stats(struct net_device *dev,
				  struct ethtool_stats *stats, u64 *data)
{
	struct mtk_mac *mac = netdev_priv(dev);
	struct mtk_hw_stats *hwstats = mac->hw_stats;
	unsigned int start;
	int i;

	if (netif_running(dev) && netif_device_present(dev)) {
		if (spin_trylock(&hwstats->stats_lock)) {
			mtk_stats_update_mac(mac);
			spin_unlock(&hwstats->stats_lock);
		}
	}

	do {
		start = u64_stats_fetch_begin_irq(&hwstats->syncp);
		for (i = 0; i < MTK_HW_STATS_LEN; i++)
			data[i] = ((u64 *)hwstats)[mtk_ethtool_hw_stats[i].idx];

	} while (u64_stats_fetch_retry_irq(&hwstats->syncp, start));
}

void mtk_set_ethtool_ops(struct net_device *netdev)
{
	struct mtk_mac *mac = netdev_priv(netdev);
	struct mtk_soc_data *soc = mac->hw->soc;

	if (soc->reg_table[MTK_REG_MTK_COUNTER_BASE]) {
		mtk_ethtool_ops.get_strings = mtk_get_strings;
		mtk_ethtool_ops.get_sset_count = mtk_get_sset_count;
		mtk_ethtool_ops.get_ethtool_stats = mtk_get_ethtool_stats;
	}

	netdev->ethtool_ops = &mtk_ethtool_ops;
}

