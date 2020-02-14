#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  unsigned long long u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct xgene_enet_pdata {scalar_t__ phy_mode; int* extd_stats; int false_rflr; int vlan_rjbr; scalar_t__ tx_pause; scalar_t__ rx_pause; TYPE_4__* mac_ops; scalar_t__ pause_autoneg; struct platform_device* pdev; scalar_t__ mdio_driver; scalar_t__ rm; } ;
struct xgene_enet_desc_ring {int num; struct net_device* ndev; } ;
struct rtnl_link_stats64 {int dummy; } ;
struct platform_device {char* name; int /*<<< orphan*/  dev; } ;
struct phy_device {int supported; int advertising; scalar_t__ autoneg; } ;
struct TYPE_7__ {struct device* parent; } ;
struct net_device {int /*<<< orphan*/ * ethtool_ops; struct phy_device* phydev; TYPE_1__ dev; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_pauseparam {scalar_t__ tx_pause; scalar_t__ rx_pause; scalar_t__ autoneg; } ;
struct TYPE_9__ {int /*<<< orphan*/  autoneg; int /*<<< orphan*/  port; void* duplex; int /*<<< orphan*/  speed; } ;
struct TYPE_8__ {int /*<<< orphan*/  advertising; int /*<<< orphan*/  supported; } ;
struct ethtool_link_ksettings {TYPE_3__ base; TYPE_2__ link_modes; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  fw_version; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct device {int dummy; } ;
typedef  enum xgene_ring_owner { ____Placeholder_xgene_ring_owner } xgene_ring_owner ;
typedef  scalar_t__ __le64 ;
struct TYPE_12__ {int mask; int /*<<< orphan*/  addr; int /*<<< orphan*/  name; } ;
struct TYPE_11__ {int offset; int /*<<< orphan*/  name; } ;
struct TYPE_10__ {int /*<<< orphan*/  (* flowctl_rx ) (struct xgene_enet_pdata*,scalar_t__) ;int /*<<< orphan*/  (* flowctl_tx ) (struct xgene_enet_pdata*,scalar_t__) ;int /*<<< orphan*/  (* get_drop_cnt ) (struct xgene_enet_pdata*,int*,int*) ;} ;

/* Variables and functions */
 int ADVERTISED_Asym_Pause ; 
 int ADVERTISED_Pause ; 
 int /*<<< orphan*/  AUTONEG_DISABLE ; 
 int /*<<< orphan*/  AUTONEG_ENABLE ; 
 int BUFPOOL_DESC_SIZE ; 
 void* DUPLEX_FULL ; 
 int EINVAL ; 
 int /*<<< orphan*/  EMPTY_SLOT ; 
 size_t EMPTY_SLOT_INDEX ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETHTOOL_FWVERS_LEN ; 
 int /*<<< orphan*/  ETH_GSTRING_LEN ; 
 int ETH_SS_STATS ; 
 size_t FALSE_RFLR_IDX ; 
 size_t FALSE_RJBR_IDX ; 
 int GENMASK (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ PHY_INTERFACE_MODE_SGMII ; 
 scalar_t__ PHY_INTERFACE_MODE_XGMII ; 
 int /*<<< orphan*/  PORT_FIBRE ; 
 int /*<<< orphan*/  PORT_MII ; 
 size_t RALN_IDX ; 
 size_t RFCS_IDX ; 
 size_t RFLR_IDX ; 
 int RING_BUFNUM_BUFPOOL ; 
 int RING_BUFNUM_MASK ; 
 int RING_OWNER_MASK ; 
 size_t RUND_IDX ; 
 size_t RX_OVERRUN_IDX ; 
 int /*<<< orphan*/  SPEED_1000 ; 
 int /*<<< orphan*/  SPEED_10000 ; 
 int SUPPORTED_10000baseT_Full ; 
 int SUPPORTED_1000baseT_Full ; 
 int SUPPORTED_Asym_Pause ; 
 int SUPPORTED_Autoneg ; 
 int SUPPORTED_FIBRE ; 
 int SUPPORTED_MII ; 
 int SUPPORTED_Pause ; 
 size_t TFCS_IDX ; 
 size_t TFRG_IDX ; 
 size_t TX_UNDERRUN_IDX ; 
 int WORK_DESC_SIZE ; 
 char* XGENE_DRV_VERSION ; 
 int XGENE_EXTD_STATS_LEN ; 
 int XGENE_STATS_LEN ; 
 scalar_t__ cpu_to_le64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_get_stats (struct net_device*,struct rtnl_link_stats64*) ; 
 int* devm_kmalloc_array (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ethtool_convert_legacy_u32_to_link_mode (int /*<<< orphan*/ ,int) ; 
 TYPE_6__* gstrings_extd_stats ; 
 TYPE_5__* gstrings_stats ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 struct xgene_enet_pdata* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  phy_ethtool_ksettings_get (struct phy_device*,struct ethtool_link_ksettings*) ; 
 int phy_ethtool_ksettings_set (struct phy_device*,struct ethtool_link_ksettings const*) ; 
 scalar_t__ phy_interface_mode_is_rgmii (scalar_t__) ; 
 int phy_start_aneg (struct phy_device*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  stub1 (struct xgene_enet_pdata*,int*,int*) ; 
 int /*<<< orphan*/  stub2 (struct xgene_enet_pdata*,scalar_t__) ; 
 int /*<<< orphan*/  stub3 (struct xgene_enet_pdata*,scalar_t__) ; 
 int /*<<< orphan*/  stub4 (struct xgene_enet_pdata*,scalar_t__) ; 
 int /*<<< orphan*/  stub5 (struct xgene_enet_pdata*,scalar_t__) ; 
 int xgene_enet_rd_stat (struct xgene_enet_pdata*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xgene_ethtool_ops ; 

__attribute__((used)) static inline void xgene_set_bits(u32 *dst, u32 val, u32 start, u32 len)
{
	u32 end = start + len - 1;
	u32 mask = GENMASK(end, start);

	*dst &= ~mask;
	*dst |= (val << start) & mask;
}

__attribute__((used)) static inline u32 xgene_get_bits(u32 val, u32 start, u32 end)
{
	return (val & GENMASK(end, start)) >> start;
}

__attribute__((used)) static inline void xgene_enet_mark_desc_slot_empty(void *desc_slot_ptr)
{
	__le64 *desc_slot = desc_slot_ptr;

	desc_slot[EMPTY_SLOT_INDEX] = cpu_to_le64(EMPTY_SLOT);
}

__attribute__((used)) static inline bool xgene_enet_is_desc_slot_empty(void *desc_slot_ptr)
{
	__le64 *desc_slot = desc_slot_ptr;

	return (desc_slot[EMPTY_SLOT_INDEX] == cpu_to_le64(EMPTY_SLOT));
}

__attribute__((used)) static inline enum xgene_ring_owner xgene_enet_ring_owner(u16 id)
{
	return (id & RING_OWNER_MASK) >> 6;
}

__attribute__((used)) static inline u8 xgene_enet_ring_bufnum(u16 id)
{
	return id & RING_BUFNUM_MASK;
}

__attribute__((used)) static inline bool xgene_enet_is_bufpool(u16 id)
{
	return ((id & RING_BUFNUM_MASK) >= 0x20) ? true : false;
}

__attribute__((used)) static inline u8 xgene_enet_get_fpsel(u16 id)
{
	if (xgene_enet_is_bufpool(id))
		return xgene_enet_ring_bufnum(id) - RING_BUFNUM_BUFPOOL;

	return 0;
}

__attribute__((used)) static inline u16 xgene_enet_get_numslots(u16 id, u32 size)
{
	bool is_bufpool = xgene_enet_is_bufpool(id);

	return (is_bufpool) ? size / BUFPOOL_DESC_SIZE :
		      size / WORK_DESC_SIZE;
}

__attribute__((used)) static inline u64 xgene_enet_set_field_value(int pos, int len, u64 val)
{
	return (val & ((1ULL << len) - 1)) << pos;
}

__attribute__((used)) static inline u64 xgene_enet_get_field_value(int pos, int len, u64 src)
{
	return (src >> pos) & ((1ULL << len) - 1);
}

__attribute__((used)) static inline struct device *ndev_to_dev(struct net_device *ndev)
{
	return ndev->dev.parent;
}

__attribute__((used)) static inline u16 xgene_enet_dst_ring_num(struct xgene_enet_desc_ring *ring)
{
	struct xgene_enet_pdata *pdata = netdev_priv(ring->ndev);

	return ((u16)pdata->rm << 10) | ring->num;
}

__attribute__((used)) static void xgene_get_drvinfo(struct net_device *ndev,
			      struct ethtool_drvinfo *info)
{
	struct xgene_enet_pdata *pdata = netdev_priv(ndev);
	struct platform_device *pdev = pdata->pdev;

	strcpy(info->driver, "xgene_enet");
	strcpy(info->version, XGENE_DRV_VERSION);
	snprintf(info->fw_version, ETHTOOL_FWVERS_LEN, "N/A");
	sprintf(info->bus_info, "%s", pdev->name);
}

__attribute__((used)) static int xgene_get_link_ksettings(struct net_device *ndev,
				    struct ethtool_link_ksettings *cmd)
{
	struct xgene_enet_pdata *pdata = netdev_priv(ndev);
	struct phy_device *phydev = ndev->phydev;
	u32 supported;

	if (phy_interface_mode_is_rgmii(pdata->phy_mode)) {
		if (phydev == NULL)
			return -ENODEV;

		phy_ethtool_ksettings_get(phydev, cmd);

		return 0;
	} else if (pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
		if (pdata->mdio_driver) {
			if (!phydev)
				return -ENODEV;

			phy_ethtool_ksettings_get(phydev, cmd);

			return 0;
		}

		supported = SUPPORTED_1000baseT_Full | SUPPORTED_Autoneg |
			SUPPORTED_MII;
		ethtool_convert_legacy_u32_to_link_mode(
			cmd->link_modes.supported,
			supported);
		ethtool_convert_legacy_u32_to_link_mode(
			cmd->link_modes.advertising,
			supported);

		cmd->base.speed = SPEED_1000;
		cmd->base.duplex = DUPLEX_FULL;
		cmd->base.port = PORT_MII;
		cmd->base.autoneg = AUTONEG_ENABLE;
	} else {
		supported = SUPPORTED_10000baseT_Full | SUPPORTED_FIBRE;
		ethtool_convert_legacy_u32_to_link_mode(
			cmd->link_modes.supported,
			supported);
		ethtool_convert_legacy_u32_to_link_mode(
			cmd->link_modes.advertising,
			supported);

		cmd->base.speed = SPEED_10000;
		cmd->base.duplex = DUPLEX_FULL;
		cmd->base.port = PORT_FIBRE;
		cmd->base.autoneg = AUTONEG_DISABLE;
	}

	return 0;
}

__attribute__((used)) static int xgene_set_link_ksettings(struct net_device *ndev,
				    const struct ethtool_link_ksettings *cmd)
{
	struct xgene_enet_pdata *pdata = netdev_priv(ndev);
	struct phy_device *phydev = ndev->phydev;

	if (phy_interface_mode_is_rgmii(pdata->phy_mode)) {
		if (!phydev)
			return -ENODEV;

		return phy_ethtool_ksettings_set(phydev, cmd);
	}

	if (pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
		if (pdata->mdio_driver) {
			if (!phydev)
				return -ENODEV;

			return phy_ethtool_ksettings_set(phydev, cmd);
		}
	}

	return -EINVAL;
}

__attribute__((used)) static void xgene_get_strings(struct net_device *ndev, u32 stringset, u8 *data)
{
	int i;
	u8 *p = data;

	if (stringset != ETH_SS_STATS)
		return;

	for (i = 0; i < XGENE_STATS_LEN; i++) {
		memcpy(p, gstrings_stats[i].name, ETH_GSTRING_LEN);
		p += ETH_GSTRING_LEN;
	}

	for (i = 0; i < XGENE_EXTD_STATS_LEN; i++) {
		memcpy(p, gstrings_extd_stats[i].name, ETH_GSTRING_LEN);
		p += ETH_GSTRING_LEN;
	}
}

__attribute__((used)) static int xgene_get_sset_count(struct net_device *ndev, int sset)
{
	if (sset != ETH_SS_STATS)
		return -EINVAL;

	return XGENE_STATS_LEN + XGENE_EXTD_STATS_LEN;
}

__attribute__((used)) static void xgene_get_extd_stats(struct xgene_enet_pdata *pdata)
{
	u32 rx_drop, tx_drop;
	u32 mask, tmp;
	int i;

	for (i = 0; i < XGENE_EXTD_STATS_LEN; i++) {
		tmp = xgene_enet_rd_stat(pdata, gstrings_extd_stats[i].addr);
		if (gstrings_extd_stats[i].mask) {
			mask = GENMASK(gstrings_extd_stats[i].mask - 1, 0);
			pdata->extd_stats[i] += (tmp & mask);
		}
	}

	if (pdata->phy_mode == PHY_INTERFACE_MODE_XGMII) {
		/* Errata 10GE_10 - SW should intepret RALN as 0 */
		pdata->extd_stats[RALN_IDX] = 0;
	} else {
		/* Errata ENET_15 - Fixes RFCS, RFLR, TFCS counter */
		pdata->extd_stats[RFCS_IDX] -= pdata->extd_stats[RALN_IDX];
		pdata->extd_stats[RFLR_IDX] -= pdata->extd_stats[RUND_IDX];
		pdata->extd_stats[TFCS_IDX] -= pdata->extd_stats[TFRG_IDX];
	}

	pdata->mac_ops->get_drop_cnt(pdata, &rx_drop, &tx_drop);
	pdata->extd_stats[RX_OVERRUN_IDX] += rx_drop;
	pdata->extd_stats[TX_UNDERRUN_IDX] += tx_drop;

	/* Errata 10GE_8 -  Update Frame recovered from Errata 10GE_8/ENET_11 */
	pdata->extd_stats[FALSE_RFLR_IDX] = pdata->false_rflr;
	/* Errata ENET_15 - Jabber Frame recov'ed from Errata 10GE_10/ENET_15 */
	pdata->extd_stats[FALSE_RJBR_IDX] = pdata->vlan_rjbr;
}

int xgene_extd_stats_init(struct xgene_enet_pdata *pdata)
{
	pdata->extd_stats = devm_kmalloc_array(&pdata->pdev->dev,
			XGENE_EXTD_STATS_LEN, sizeof(u64), GFP_KERNEL);
	if (!pdata->extd_stats)
		return -ENOMEM;

	xgene_get_extd_stats(pdata);
	memset(pdata->extd_stats, 0, XGENE_EXTD_STATS_LEN * sizeof(u64));

	return 0;
}

__attribute__((used)) static void xgene_get_ethtool_stats(struct net_device *ndev,
				    struct ethtool_stats *dummy,
				    u64 *data)
{
	struct xgene_enet_pdata *pdata = netdev_priv(ndev);
	struct rtnl_link_stats64 stats;
	int i;

	dev_get_stats(ndev, &stats);
	for (i = 0; i < XGENE_STATS_LEN; i++)
		data[i] = *(u64 *)((char *)&stats + gstrings_stats[i].offset);

	xgene_get_extd_stats(pdata);
	for (i = 0; i < XGENE_EXTD_STATS_LEN; i++)
		data[i + XGENE_STATS_LEN] = pdata->extd_stats[i];
}

__attribute__((used)) static void xgene_get_pauseparam(struct net_device *ndev,
				 struct ethtool_pauseparam *pp)
{
	struct xgene_enet_pdata *pdata = netdev_priv(ndev);

	pp->autoneg = pdata->pause_autoneg;
	pp->tx_pause = pdata->tx_pause;
	pp->rx_pause = pdata->rx_pause;
}

__attribute__((used)) static int xgene_set_pauseparam(struct net_device *ndev,
				struct ethtool_pauseparam *pp)
{
	struct xgene_enet_pdata *pdata = netdev_priv(ndev);
	struct phy_device *phydev = ndev->phydev;
	u32 oldadv, newadv;

	if (phy_interface_mode_is_rgmii(pdata->phy_mode) ||
	    pdata->phy_mode == PHY_INTERFACE_MODE_SGMII) {
		if (!phydev)
			return -EINVAL;

		if (!(phydev->supported & SUPPORTED_Pause) ||
		    (!(phydev->supported & SUPPORTED_Asym_Pause) &&
		     pp->rx_pause != pp->tx_pause))
			return -EINVAL;

		pdata->pause_autoneg = pp->autoneg;
		pdata->tx_pause = pp->tx_pause;
		pdata->rx_pause = pp->rx_pause;

		oldadv = phydev->advertising;
		newadv = oldadv & ~(ADVERTISED_Pause | ADVERTISED_Asym_Pause);

		if (pp->rx_pause)
			newadv |= ADVERTISED_Pause | ADVERTISED_Asym_Pause;

		if (pp->tx_pause)
			newadv ^= ADVERTISED_Asym_Pause;

		if (oldadv ^ newadv) {
			phydev->advertising = newadv;

			if (phydev->autoneg)
				return phy_start_aneg(phydev);

			if (!pp->autoneg) {
				pdata->mac_ops->flowctl_tx(pdata,
							   pdata->tx_pause);
				pdata->mac_ops->flowctl_rx(pdata,
							   pdata->rx_pause);
			}
		}

	} else {
		if (pp->autoneg)
			return -EINVAL;

		pdata->tx_pause = pp->tx_pause;
		pdata->rx_pause = pp->rx_pause;

		pdata->mac_ops->flowctl_tx(pdata, pdata->tx_pause);
		pdata->mac_ops->flowctl_rx(pdata, pdata->rx_pause);
	}

	return 0;
}

void xgene_enet_set_ethtool_ops(struct net_device *ndev)
{
	ndev->ethtool_ops = &xgene_ethtool_ops;
}

