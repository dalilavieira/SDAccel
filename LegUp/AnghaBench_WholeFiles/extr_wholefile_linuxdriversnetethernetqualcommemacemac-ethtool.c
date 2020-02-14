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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct phy_device {int dummy; } ;
struct net_device {int /*<<< orphan*/ * ethtool_ops; struct phy_device* phydev; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_ringparam {void* rx_pending; void* tx_pending; scalar_t__ rx_jumbo_pending; scalar_t__ rx_mini_pending; void* tx_max_pending; void* rx_max_pending; } ;
struct ethtool_regs {int len; int /*<<< orphan*/  version; } ;
struct ethtool_pauseparam {scalar_t__ autoneg; int rx_pause; int tx_pause; } ;
struct TYPE_2__ {int /*<<< orphan*/  lock; } ;
struct emac_adapter {int msg_enable; int automatic; int rx_flow_control; int tx_flow_control; int single_pause_mode; scalar_t__ base; void* rx_desc_cnt; void* tx_desc_cnt; TYPE_1__ stats; } ;

/* Variables and functions */
 scalar_t__ AUTONEG_DISABLE ; 
 scalar_t__ AUTONEG_ENABLE ; 
 int EINVAL ; 
 int EMAC_MAX_REG_SIZE ; 
 void* EMAC_MAX_RX_DESCS ; 
 void* EMAC_MAX_TX_DESCS ; 
 int /*<<< orphan*/  EMAC_MIN_RX_DESCS ; 
 int /*<<< orphan*/  EMAC_MIN_TX_DESCS ; 
 int EMAC_PRIV_ENABLE_SINGLE_PAUSE ; 
 int /*<<< orphan*/  EMAC_REGS_VERSION ; 
 int EMAC_STATS_LEN ; 
 int ENODEV ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  ETH_GSTRING_LEN ; 
#define  ETH_SS_PRIV_FLAGS 129 
#define  ETH_SS_STATS 128 
 void* clamp_val (void*,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  emac_ethtool_ops ; 
 int /*<<< orphan*/ * emac_ethtool_stat_strings ; 
 scalar_t__* emac_regs ; 
 int emac_reinit_locked (struct emac_adapter*) ; 
 int /*<<< orphan*/  emac_update_hw_stats (struct emac_adapter*) ; 
 int genphy_restart_aneg (struct phy_device*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 struct emac_adapter* netdev_priv (struct net_device*) ; 
 scalar_t__ netif_running (struct net_device*) ; 
 int readl (scalar_t__) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32 emac_get_msglevel(struct net_device *netdev)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	return adpt->msg_enable;
}

__attribute__((used)) static void emac_set_msglevel(struct net_device *netdev, u32 data)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	adpt->msg_enable = data;
}

__attribute__((used)) static int emac_get_sset_count(struct net_device *netdev, int sset)
{
	switch (sset) {
	case ETH_SS_PRIV_FLAGS:
		return 1;
	case ETH_SS_STATS:
		return EMAC_STATS_LEN;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static void emac_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
	unsigned int i;

	switch (stringset) {
	case ETH_SS_PRIV_FLAGS:
		strcpy(data, "single-pause-mode");
		break;

	case ETH_SS_STATS:
		for (i = 0; i < EMAC_STATS_LEN; i++) {
			strlcpy(data, emac_ethtool_stat_strings[i],
				ETH_GSTRING_LEN);
			data += ETH_GSTRING_LEN;
		}
		break;
	}
}

__attribute__((used)) static void emac_get_ethtool_stats(struct net_device *netdev,
				   struct ethtool_stats *stats,
				   u64 *data)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	spin_lock(&adpt->stats.lock);

	emac_update_hw_stats(adpt);
	memcpy(data, &adpt->stats, EMAC_STATS_LEN * sizeof(u64));

	spin_unlock(&adpt->stats.lock);
}

__attribute__((used)) static int emac_nway_reset(struct net_device *netdev)
{
	struct phy_device *phydev = netdev->phydev;

	if (!phydev)
		return -ENODEV;

	return genphy_restart_aneg(phydev);
}

__attribute__((used)) static void emac_get_ringparam(struct net_device *netdev,
			       struct ethtool_ringparam *ring)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	ring->rx_max_pending = EMAC_MAX_RX_DESCS;
	ring->tx_max_pending = EMAC_MAX_TX_DESCS;
	ring->rx_pending = adpt->rx_desc_cnt;
	ring->tx_pending = adpt->tx_desc_cnt;
}

__attribute__((used)) static int emac_set_ringparam(struct net_device *netdev,
			      struct ethtool_ringparam *ring)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	/* We don't have separate queues/rings for small/large frames, so
	 * reject any attempt to specify those values separately.
	 */
	if (ring->rx_mini_pending || ring->rx_jumbo_pending)
		return -EINVAL;

	adpt->tx_desc_cnt =
		clamp_val(ring->tx_pending, EMAC_MIN_TX_DESCS, EMAC_MAX_TX_DESCS);

	adpt->rx_desc_cnt =
		clamp_val(ring->rx_pending, EMAC_MIN_RX_DESCS, EMAC_MAX_RX_DESCS);

	if (netif_running(netdev))
		return emac_reinit_locked(adpt);

	return 0;
}

__attribute__((used)) static void emac_get_pauseparam(struct net_device *netdev,
				struct ethtool_pauseparam *pause)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	pause->autoneg = adpt->automatic ? AUTONEG_ENABLE : AUTONEG_DISABLE;
	pause->rx_pause = adpt->rx_flow_control ? 1 : 0;
	pause->tx_pause = adpt->tx_flow_control ? 1 : 0;
}

__attribute__((used)) static int emac_set_pauseparam(struct net_device *netdev,
			       struct ethtool_pauseparam *pause)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	adpt->automatic = pause->autoneg == AUTONEG_ENABLE;
	adpt->rx_flow_control = pause->rx_pause != 0;
	adpt->tx_flow_control = pause->tx_pause != 0;

	if (netif_running(netdev))
		return emac_reinit_locked(adpt);

	return 0;
}

__attribute__((used)) static void emac_get_regs(struct net_device *netdev,
			  struct ethtool_regs *regs, void *buff)
{
	struct emac_adapter *adpt = netdev_priv(netdev);
	u32 *val = buff;
	unsigned int i;

	regs->version = EMAC_REGS_VERSION;
	regs->len = EMAC_MAX_REG_SIZE * sizeof(u32);

	for (i = 0; i < EMAC_MAX_REG_SIZE; i++)
		val[i] = readl(adpt->base + emac_regs[i]);
}

__attribute__((used)) static int emac_get_regs_len(struct net_device *netdev)
{
	return EMAC_MAX_REG_SIZE * sizeof(u32);
}

__attribute__((used)) static int emac_set_priv_flags(struct net_device *netdev, u32 flags)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	adpt->single_pause_mode = !!(flags & EMAC_PRIV_ENABLE_SINGLE_PAUSE);

	if (netif_running(netdev))
		return emac_reinit_locked(adpt);

	return 0;
}

__attribute__((used)) static u32 emac_get_priv_flags(struct net_device *netdev)
{
	struct emac_adapter *adpt = netdev_priv(netdev);

	return adpt->single_pause_mode ? EMAC_PRIV_ENABLE_SINGLE_PAUSE : 0;
}

void emac_set_ethtool_ops(struct net_device *netdev)
{
	netdev->ethtool_ops = &emac_ethtool_ops;
}

