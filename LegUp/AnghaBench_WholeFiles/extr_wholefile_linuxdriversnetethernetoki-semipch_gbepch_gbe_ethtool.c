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
struct TYPE_8__ {scalar_t__ speed; int /*<<< orphan*/  autoneg; int /*<<< orphan*/  duplex; } ;
struct TYPE_6__ {int /*<<< orphan*/  advertising; int /*<<< orphan*/  supported; } ;
struct ethtool_link_ksettings {TYPE_3__ base; TYPE_1__ link_modes; } ;
typedef  struct ethtool_link_ksettings u8 ;
typedef  scalar_t__ u64 ;
typedef  scalar_t__ u32 ;
typedef  scalar_t__ u16 ;
struct pci_dev {int device; scalar_t__ revision; } ;
struct pch_gbe_tx_ring {void* count; } ;
struct pch_gbe_stats {int offset; int size; struct ethtool_link_ksettings const* string; } ;
struct pch_gbe_rx_ring {void* count; } ;
struct TYPE_10__ {scalar_t__ fc_autoneg; scalar_t__ fc; int /*<<< orphan*/  autoneg; int /*<<< orphan*/  link_duplex; scalar_t__ link_speed; } ;
struct TYPE_7__ {scalar_t__ autoneg_advertised; } ;
struct pch_gbe_hw {TYPE_5__ mac; TYPE_4__* reg; TYPE_2__ phy; } ;
struct pch_gbe_adapter {int wake_up_evt; int /*<<< orphan*/  stats; int /*<<< orphan*/  netdev; struct pch_gbe_hw hw; struct pch_gbe_tx_ring* tx_ring; struct pch_gbe_tx_ring* rx_ring; int /*<<< orphan*/  mii; struct pci_dev* pdev; } ;
struct net_device {int /*<<< orphan*/ * ethtool_ops; } ;
struct ethtool_wolinfo {int supported; int wolopts; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_ringparam {void* tx_pending; void* rx_pending; scalar_t__ rx_jumbo_pending; scalar_t__ rx_mini_pending; int /*<<< orphan*/  tx_max_pending; int /*<<< orphan*/  rx_max_pending; } ;
struct ethtool_regs {int version; } ;
struct ethtool_pauseparam {scalar_t__ autoneg; int rx_pause; int tx_pause; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
typedef  int __u32 ;
struct TYPE_9__ {int /*<<< orphan*/  INT_ST; } ;

/* Variables and functions */
 scalar_t__ ADVERTISED_1000baseT_Half ; 
 scalar_t__ ADVERTISED_TP ; 
 scalar_t__ AUTONEG_DISABLE ; 
 scalar_t__ AUTONEG_ENABLE ; 
 int /*<<< orphan*/  BMCR_RESET ; 
 int /*<<< orphan*/  DUPLEX_FULL ; 
 int EINVAL ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int ETH_GSTRING_LEN ; 
#define  ETH_SS_STATS 128 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  KBUILD_MODNAME ; 
 int /*<<< orphan*/  MII_BMCR ; 
 scalar_t__ PCH_GBE_FC_FULL ; 
 scalar_t__ PCH_GBE_FC_NONE ; 
 scalar_t__ PCH_GBE_FC_RX_PAUSE ; 
 scalar_t__ PCH_GBE_FC_TX_PAUSE ; 
 int PCH_GBE_GLOBAL_STATS_LEN ; 
 scalar_t__ PCH_GBE_MAC_REGS_LEN ; 
 int /*<<< orphan*/  PCH_GBE_MAX_RXD ; 
 int /*<<< orphan*/  PCH_GBE_MAX_TXD ; 
 int /*<<< orphan*/  PCH_GBE_MIN_RXD ; 
 scalar_t__ PCH_GBE_PHY_REGS_LEN ; 
 int PCH_GBE_REGS_LEN ; 
 int /*<<< orphan*/  PCH_GBE_RX_DESC_MULTIPLE ; 
 int PCH_GBE_STATS_LEN ; 
 int /*<<< orphan*/  PCH_GBE_TX_DESC_MULTIPLE ; 
 int PCH_GBE_WLC_BR ; 
 int PCH_GBE_WLC_IND ; 
 int PCH_GBE_WLC_MLT ; 
 int PCH_GBE_WLC_MP ; 
 scalar_t__ SPEED_1000 ; 
 scalar_t__ SPEED_UNKNOWN ; 
 scalar_t__ SUPPORTED_1000baseT_Half ; 
 scalar_t__ SUPPORTED_TP ; 
 scalar_t__ UINT_MAX ; 
 int WAKE_ARP ; 
 int WAKE_BCAST ; 
 int WAKE_MAGIC ; 
 int WAKE_MAGICSECURE ; 
 int WAKE_MCAST ; 
 int WAKE_PHY ; 
 int WAKE_UCAST ; 
 void* clamp_val (void*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ethtool_convert_legacy_u32_to_link_mode (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  ethtool_convert_link_mode_to_legacy_u32 (scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ioread32 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct pch_gbe_tx_ring*) ; 
 struct pch_gbe_tx_ring* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct ethtool_link_ksettings*,struct ethtool_link_ksettings const*,int) ; 
 int /*<<< orphan*/  mii_ethtool_get_link_ksettings (int /*<<< orphan*/ *,struct ethtool_link_ksettings*) ; 
 int mii_ethtool_set_link_ksettings (int /*<<< orphan*/ *,struct ethtool_link_ksettings*) ; 
 int mii_nway_restart (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*) ; 
 struct pch_gbe_adapter* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_carrier_ok (int /*<<< orphan*/ ) ; 
 scalar_t__ netif_running (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pch_driver_version ; 
 int /*<<< orphan*/  pch_gbe_down (struct pch_gbe_adapter*) ; 
 int /*<<< orphan*/  pch_gbe_ethtool_ops ; 
 int /*<<< orphan*/  pch_gbe_free_rx_resources (struct pch_gbe_adapter*,struct pch_gbe_tx_ring*) ; 
 int /*<<< orphan*/  pch_gbe_free_tx_resources (struct pch_gbe_adapter*,struct pch_gbe_tx_ring*) ; 
 struct pch_gbe_stats* pch_gbe_gstrings_stats ; 
 int pch_gbe_mac_force_mac_fc (struct pch_gbe_hw*) ; 
 int /*<<< orphan*/  pch_gbe_phy_read_reg_miic (struct pch_gbe_hw*,scalar_t__,scalar_t__*) ; 
 int /*<<< orphan*/  pch_gbe_phy_write_reg_miic (struct pch_gbe_hw*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pch_gbe_reset (struct pch_gbe_adapter*) ; 
 int pch_gbe_setup_rx_resources (struct pch_gbe_adapter*,struct pch_gbe_tx_ring*) ; 
 int pch_gbe_setup_tx_resources (struct pch_gbe_adapter*,struct pch_gbe_tx_ring*) ; 
 int pch_gbe_up (struct pch_gbe_adapter*) ; 
 int /*<<< orphan*/  pch_gbe_update_stats (struct pch_gbe_adapter*) ; 
 int /*<<< orphan*/  pci_name (struct pci_dev*) ; 
 void* roundup (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int pch_gbe_get_link_ksettings(struct net_device *netdev,
				      struct ethtool_link_ksettings *ecmd)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	u32 supported, advertising;

	mii_ethtool_get_link_ksettings(&adapter->mii, ecmd);

	ethtool_convert_link_mode_to_legacy_u32(&supported,
						ecmd->link_modes.supported);
	ethtool_convert_link_mode_to_legacy_u32(&advertising,
						ecmd->link_modes.advertising);

	supported &= ~(SUPPORTED_TP | SUPPORTED_1000baseT_Half);
	advertising &= ~(ADVERTISED_TP | ADVERTISED_1000baseT_Half);

	ethtool_convert_legacy_u32_to_link_mode(ecmd->link_modes.supported,
						supported);
	ethtool_convert_legacy_u32_to_link_mode(ecmd->link_modes.advertising,
						advertising);

	if (!netif_carrier_ok(adapter->netdev))
		ecmd->base.speed = SPEED_UNKNOWN;

	return 0;
}

__attribute__((used)) static int pch_gbe_set_link_ksettings(struct net_device *netdev,
				      const struct ethtool_link_ksettings *ecmd)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	struct pch_gbe_hw *hw = &adapter->hw;
	struct ethtool_link_ksettings copy_ecmd;
	u32 speed = ecmd->base.speed;
	u32 advertising;
	int ret;

	pch_gbe_phy_write_reg_miic(hw, MII_BMCR, BMCR_RESET);

	memcpy(&copy_ecmd, ecmd, sizeof(*ecmd));

	/* when set_settings() is called with a ethtool_cmd previously
	 * filled by get_settings() on a down link, speed is -1: */
	if (speed == UINT_MAX) {
		speed = SPEED_1000;
		copy_ecmd.base.speed = speed;
		copy_ecmd.base.duplex = DUPLEX_FULL;
	}
	ret = mii_ethtool_set_link_ksettings(&adapter->mii, &copy_ecmd);
	if (ret) {
		netdev_err(netdev, "Error: mii_ethtool_set_link_ksettings\n");
		return ret;
	}
	hw->mac.link_speed = speed;
	hw->mac.link_duplex = copy_ecmd.base.duplex;
	ethtool_convert_link_mode_to_legacy_u32(
		&advertising, copy_ecmd.link_modes.advertising);
	hw->phy.autoneg_advertised = advertising;
	hw->mac.autoneg = copy_ecmd.base.autoneg;

	/* reset the link */
	if (netif_running(adapter->netdev)) {
		pch_gbe_down(adapter);
		ret = pch_gbe_up(adapter);
	} else {
		pch_gbe_reset(adapter);
	}
	return ret;
}

__attribute__((used)) static int pch_gbe_get_regs_len(struct net_device *netdev)
{
	return PCH_GBE_REGS_LEN * (int)sizeof(u32);
}

__attribute__((used)) static void pch_gbe_get_drvinfo(struct net_device *netdev,
				 struct ethtool_drvinfo *drvinfo)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);

	strlcpy(drvinfo->driver, KBUILD_MODNAME, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, pch_driver_version, sizeof(drvinfo->version));
	strlcpy(drvinfo->bus_info, pci_name(adapter->pdev),
		sizeof(drvinfo->bus_info));
}

__attribute__((used)) static void pch_gbe_get_regs(struct net_device *netdev,
				struct ethtool_regs *regs, void *p)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	struct pch_gbe_hw *hw = &adapter->hw;
	struct pci_dev *pdev = adapter->pdev;
	u32 *regs_buff = p;
	u16 i, tmp;

	regs->version = 0x1000000 | (__u32)pdev->revision << 16 | pdev->device;
	for (i = 0; i < PCH_GBE_MAC_REGS_LEN; i++)
		*regs_buff++ = ioread32(&hw->reg->INT_ST + i);
	/* PHY register */
	for (i = 0; i < PCH_GBE_PHY_REGS_LEN; i++) {
		pch_gbe_phy_read_reg_miic(&adapter->hw, i, &tmp);
		*regs_buff++ = tmp;
	}
}

__attribute__((used)) static void pch_gbe_get_wol(struct net_device *netdev,
				struct ethtool_wolinfo *wol)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);

	wol->supported = WAKE_UCAST | WAKE_MCAST | WAKE_BCAST | WAKE_MAGIC;
	wol->wolopts = 0;

	if ((adapter->wake_up_evt & PCH_GBE_WLC_IND))
		wol->wolopts |= WAKE_UCAST;
	if ((adapter->wake_up_evt & PCH_GBE_WLC_MLT))
		wol->wolopts |= WAKE_MCAST;
	if ((adapter->wake_up_evt & PCH_GBE_WLC_BR))
		wol->wolopts |= WAKE_BCAST;
	if ((adapter->wake_up_evt & PCH_GBE_WLC_MP))
		wol->wolopts |= WAKE_MAGIC;
}

__attribute__((used)) static int pch_gbe_set_wol(struct net_device *netdev,
				struct ethtool_wolinfo *wol)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);

	if ((wol->wolopts & (WAKE_PHY | WAKE_ARP | WAKE_MAGICSECURE)))
		return -EOPNOTSUPP;
	/* these settings will always override what we currently have */
	adapter->wake_up_evt = 0;

	if ((wol->wolopts & WAKE_UCAST))
		adapter->wake_up_evt |= PCH_GBE_WLC_IND;
	if ((wol->wolopts & WAKE_MCAST))
		adapter->wake_up_evt |= PCH_GBE_WLC_MLT;
	if ((wol->wolopts & WAKE_BCAST))
		adapter->wake_up_evt |= PCH_GBE_WLC_BR;
	if ((wol->wolopts & WAKE_MAGIC))
		adapter->wake_up_evt |= PCH_GBE_WLC_MP;
	return 0;
}

__attribute__((used)) static int pch_gbe_nway_reset(struct net_device *netdev)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);

	return mii_nway_restart(&adapter->mii);
}

__attribute__((used)) static void pch_gbe_get_ringparam(struct net_device *netdev,
					struct ethtool_ringparam *ring)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	struct pch_gbe_tx_ring *txdr = adapter->tx_ring;
	struct pch_gbe_rx_ring *rxdr = adapter->rx_ring;

	ring->rx_max_pending = PCH_GBE_MAX_RXD;
	ring->tx_max_pending = PCH_GBE_MAX_TXD;
	ring->rx_pending = rxdr->count;
	ring->tx_pending = txdr->count;
}

__attribute__((used)) static int pch_gbe_set_ringparam(struct net_device *netdev,
					struct ethtool_ringparam *ring)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	struct pch_gbe_tx_ring *txdr, *tx_old;
	struct pch_gbe_rx_ring *rxdr, *rx_old;
	int tx_ring_size, rx_ring_size;
	int err = 0;

	if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
		return -EINVAL;
	tx_ring_size = (int)sizeof(struct pch_gbe_tx_ring);
	rx_ring_size = (int)sizeof(struct pch_gbe_rx_ring);

	if ((netif_running(adapter->netdev)))
		pch_gbe_down(adapter);
	tx_old = adapter->tx_ring;
	rx_old = adapter->rx_ring;

	txdr = kzalloc(tx_ring_size, GFP_KERNEL);
	if (!txdr) {
		err = -ENOMEM;
		goto err_alloc_tx;
	}
	rxdr = kzalloc(rx_ring_size, GFP_KERNEL);
	if (!rxdr) {
		err = -ENOMEM;
		goto err_alloc_rx;
	}
	adapter->tx_ring = txdr;
	adapter->rx_ring = rxdr;

	rxdr->count =
		clamp_val(ring->rx_pending, PCH_GBE_MIN_RXD, PCH_GBE_MAX_RXD);
	rxdr->count = roundup(rxdr->count, PCH_GBE_RX_DESC_MULTIPLE);

	txdr->count =
		clamp_val(ring->tx_pending, PCH_GBE_MIN_RXD, PCH_GBE_MAX_RXD);
	txdr->count = roundup(txdr->count, PCH_GBE_TX_DESC_MULTIPLE);

	if ((netif_running(adapter->netdev))) {
		/* Try to get new resources before deleting old */
		err = pch_gbe_setup_rx_resources(adapter, adapter->rx_ring);
		if (err)
			goto err_setup_rx;
		err = pch_gbe_setup_tx_resources(adapter, adapter->tx_ring);
		if (err)
			goto err_setup_tx;
		pch_gbe_free_rx_resources(adapter, rx_old);
		pch_gbe_free_tx_resources(adapter, tx_old);
		kfree(tx_old);
		kfree(rx_old);
		adapter->rx_ring = rxdr;
		adapter->tx_ring = txdr;
		err = pch_gbe_up(adapter);
	}
	return err;

err_setup_tx:
	pch_gbe_free_rx_resources(adapter, adapter->rx_ring);
err_setup_rx:
	adapter->rx_ring = rx_old;
	adapter->tx_ring = tx_old;
	kfree(rxdr);
err_alloc_rx:
	kfree(txdr);
err_alloc_tx:
	if (netif_running(adapter->netdev))
		pch_gbe_up(adapter);
	return err;
}

__attribute__((used)) static void pch_gbe_get_pauseparam(struct net_device *netdev,
				       struct ethtool_pauseparam *pause)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	struct pch_gbe_hw *hw = &adapter->hw;

	pause->autoneg =
	    ((hw->mac.fc_autoneg) ? AUTONEG_ENABLE : AUTONEG_DISABLE);

	if (hw->mac.fc == PCH_GBE_FC_RX_PAUSE) {
		pause->rx_pause = 1;
	} else if (hw->mac.fc == PCH_GBE_FC_TX_PAUSE) {
		pause->tx_pause = 1;
	} else if (hw->mac.fc == PCH_GBE_FC_FULL) {
		pause->rx_pause = 1;
		pause->tx_pause = 1;
	}
}

__attribute__((used)) static int pch_gbe_set_pauseparam(struct net_device *netdev,
				       struct ethtool_pauseparam *pause)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	struct pch_gbe_hw *hw = &adapter->hw;
	int ret = 0;

	hw->mac.fc_autoneg = pause->autoneg;
	if ((pause->rx_pause) && (pause->tx_pause))
		hw->mac.fc = PCH_GBE_FC_FULL;
	else if ((pause->rx_pause) && (!pause->tx_pause))
		hw->mac.fc = PCH_GBE_FC_RX_PAUSE;
	else if ((!pause->rx_pause) && (pause->tx_pause))
		hw->mac.fc = PCH_GBE_FC_TX_PAUSE;
	else if ((!pause->rx_pause) && (!pause->tx_pause))
		hw->mac.fc = PCH_GBE_FC_NONE;

	if (hw->mac.fc_autoneg == AUTONEG_ENABLE) {
		if ((netif_running(adapter->netdev))) {
			pch_gbe_down(adapter);
			ret = pch_gbe_up(adapter);
		} else {
			pch_gbe_reset(adapter);
		}
	} else {
		ret = pch_gbe_mac_force_mac_fc(hw);
	}
	return ret;
}

__attribute__((used)) static void pch_gbe_get_strings(struct net_device *netdev, u32 stringset,
					u8 *data)
{
	u8 *p = data;
	int i;

	switch (stringset) {
	case (u32) ETH_SS_STATS:
		for (i = 0; i < PCH_GBE_GLOBAL_STATS_LEN; i++) {
			memcpy(p, pch_gbe_gstrings_stats[i].string,
			       ETH_GSTRING_LEN);
			p += ETH_GSTRING_LEN;
		}
		break;
	}
}

__attribute__((used)) static void pch_gbe_get_ethtool_stats(struct net_device *netdev,
				  struct ethtool_stats *stats, u64 *data)
{
	struct pch_gbe_adapter *adapter = netdev_priv(netdev);
	int i;
	const struct pch_gbe_stats *gstats = pch_gbe_gstrings_stats;
	char *hw_stats = (char *)&adapter->stats;

	pch_gbe_update_stats(adapter);
	for (i = 0; i < PCH_GBE_GLOBAL_STATS_LEN; i++) {
		char *p = hw_stats + gstats->offset;
		data[i] = gstats->size == sizeof(u64) ? *(u64 *)p:(*(u32 *)p);
		gstats++;
	}
}

__attribute__((used)) static int pch_gbe_get_sset_count(struct net_device *netdev, int sset)
{
	switch (sset) {
	case ETH_SS_STATS:
		return PCH_GBE_STATS_LEN;
	default:
		return -EOPNOTSUPP;
	}
}

void pch_gbe_set_ethtool_ops(struct net_device *netdev)
{
	netdev->ethtool_ops = &pch_gbe_ethtool_ops;
}

