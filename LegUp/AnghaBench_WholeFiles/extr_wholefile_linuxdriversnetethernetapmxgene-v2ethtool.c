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
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned long long u64 ;
typedef  int u32 ;
struct xge_pdata {struct platform_device* pdev; } ;
struct platform_device {char* name; } ;
struct phy_device {int dummy; } ;
struct net_device {int /*<<< orphan*/ * ethtool_ops; struct phy_device* phydev; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_link_ksettings {int dummy; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  fw_version; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct TYPE_4__ {int /*<<< orphan*/  value; int /*<<< orphan*/  name; int /*<<< orphan*/  addr; } ;
struct TYPE_3__ {int offset; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  ETHTOOL_FWVERS_LEN ; 
 int /*<<< orphan*/  ETH_GSTRING_LEN ; 
 int ETH_SS_STATS ; 
 int GENMASK (int,int) ; 
 char* XGENE_ENET_V2_VERSION ; 
 int XGE_EXTD_STATS_LEN ; 
 int XGE_STATS_LEN ; 
 TYPE_2__* gstrings_extd_stats ; 
 TYPE_1__* gstrings_stats ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  phy_ethtool_ksettings_get (struct phy_device*,struct ethtool_link_ksettings*) ; 
 int phy_ethtool_ksettings_set (struct phy_device*,struct ethtool_link_ksettings const*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  sprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  xge_ethtool_ops ; 
 int xge_rd_csr (struct xge_pdata*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void xgene_set_reg_bits(u32 *var, int pos, int len, u32 val)
{
	u32 mask = GENMASK(pos + len, pos);

	*var &= ~mask;
	*var |= ((val << pos) & mask);
}

__attribute__((used)) static inline u32 xgene_get_reg_bits(u32 var, int pos, int len)
{
	u32 mask = GENMASK(pos + len, pos);

	return (var & mask) >> pos;
}

__attribute__((used)) static inline u64 xge_set_desc_bits(int pos, int len, u64 val)
{
	return (val & ((1ULL << len) - 1)) << pos;
}

__attribute__((used)) static inline u64 xge_get_desc_bits(int pos, int len, u64 src)
{
	return (src >> pos) & ((1ULL << len) - 1);
}

__attribute__((used)) static void xge_mac_get_extd_stats(struct xge_pdata *pdata)
{
	u32 data;
	int i;

	for (i = 0; i < XGE_EXTD_STATS_LEN; i++) {
		data = xge_rd_csr(pdata, gstrings_extd_stats[i].addr);
		gstrings_extd_stats[i].value += data;
	}
}

__attribute__((used)) static void xge_get_drvinfo(struct net_device *ndev,
			    struct ethtool_drvinfo *info)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct platform_device *pdev = pdata->pdev;

	strcpy(info->driver, "xgene-enet-v2");
	strcpy(info->version, XGENE_ENET_V2_VERSION);
	snprintf(info->fw_version, ETHTOOL_FWVERS_LEN, "N/A");
	sprintf(info->bus_info, "%s", pdev->name);
}

__attribute__((used)) static void xge_get_strings(struct net_device *ndev, u32 stringset, u8 *data)
{
	u8 *p = data;
	int i;

	if (stringset != ETH_SS_STATS)
		return;

	for (i = 0; i < XGE_STATS_LEN; i++) {
		memcpy(p, gstrings_stats[i].name, ETH_GSTRING_LEN);
		p += ETH_GSTRING_LEN;
	}

	for (i = 0; i < XGE_EXTD_STATS_LEN; i++) {
		memcpy(p, gstrings_extd_stats[i].name, ETH_GSTRING_LEN);
		p += ETH_GSTRING_LEN;
	}
}

__attribute__((used)) static int xge_get_sset_count(struct net_device *ndev, int sset)
{
	if (sset != ETH_SS_STATS)
		return -EINVAL;

	return XGE_STATS_LEN + XGE_EXTD_STATS_LEN;
}

__attribute__((used)) static void xge_get_ethtool_stats(struct net_device *ndev,
				  struct ethtool_stats *dummy,
				  u64 *data)
{
	void *pdata = netdev_priv(ndev);
	int i;

	for (i = 0; i < XGE_STATS_LEN; i++)
		*data++ = *(u64 *)(pdata + gstrings_stats[i].offset);

	xge_mac_get_extd_stats(pdata);

	for (i = 0; i < XGE_EXTD_STATS_LEN; i++)
		*data++ = gstrings_extd_stats[i].value;
}

__attribute__((used)) static int xge_get_link_ksettings(struct net_device *ndev,
				  struct ethtool_link_ksettings *cmd)
{
	struct phy_device *phydev = ndev->phydev;

	if (!phydev)
		return -ENODEV;

	phy_ethtool_ksettings_get(phydev, cmd);

	return 0;
}

__attribute__((used)) static int xge_set_link_ksettings(struct net_device *ndev,
				  const struct ethtool_link_ksettings *cmd)
{
	struct phy_device *phydev = ndev->phydev;

	if (!phydev)
		return -ENODEV;

	return phy_ethtool_ksettings_set(phydev, cmd);
}

void xge_set_ethtool_ops(struct net_device *ndev)
{
	ndev->ethtool_ops = &xge_ethtool_ops;
}

