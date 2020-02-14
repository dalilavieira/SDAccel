#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  vstats ;
typedef  int /*<<< orphan*/  u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct opa_vnic_stats {int /*<<< orphan*/  netstats; } ;
struct opa_vnic_adapter {int /*<<< orphan*/  stats_lock; TYPE_2__* rn_ops; } ;
struct TYPE_4__ {int /*<<< orphan*/  parent; } ;
struct net_device {int /*<<< orphan*/ * ethtool_ops; TYPE_1__ dev; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct TYPE_6__ {int stat_offset; int sizeof_stat; int /*<<< orphan*/  stat_string; } ;
struct TYPE_5__ {int /*<<< orphan*/  (* ndo_get_stats64 ) (struct net_device*,int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int ETH_GSTRING_LEN ; 
 int ETH_SS_STATS ; 
 int VNIC_STATS_LEN ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (struct opa_vnic_stats*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  opa_vnic_driver_name ; 
 int /*<<< orphan*/  opa_vnic_driver_version ; 
 int /*<<< orphan*/  opa_vnic_ethtool_ops ; 
 struct opa_vnic_adapter* opa_vnic_priv (struct net_device*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct net_device*,int /*<<< orphan*/ *) ; 
 TYPE_3__* vnic_gstrings_stats ; 

__attribute__((used)) static void vnic_get_drvinfo(struct net_device *netdev,
			     struct ethtool_drvinfo *drvinfo)
{
	strlcpy(drvinfo->driver, opa_vnic_driver_name, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, opa_vnic_driver_version,
		sizeof(drvinfo->version));
	strlcpy(drvinfo->bus_info, dev_name(netdev->dev.parent),
		sizeof(drvinfo->bus_info));
}

__attribute__((used)) static int vnic_get_sset_count(struct net_device *netdev, int sset)
{
	return (sset == ETH_SS_STATS) ? VNIC_STATS_LEN : -EOPNOTSUPP;
}

__attribute__((used)) static void vnic_get_ethtool_stats(struct net_device *netdev,
				   struct ethtool_stats *stats, u64 *data)
{
	struct opa_vnic_adapter *adapter = opa_vnic_priv(netdev);
	struct opa_vnic_stats vstats;
	int i;

	memset(&vstats, 0, sizeof(vstats));
	spin_lock(&adapter->stats_lock);
	adapter->rn_ops->ndo_get_stats64(netdev, &vstats.netstats);
	spin_unlock(&adapter->stats_lock);
	for (i = 0; i < VNIC_STATS_LEN; i++) {
		char *p = (char *)&vstats + vnic_gstrings_stats[i].stat_offset;

		data[i] = (vnic_gstrings_stats[i].sizeof_stat ==
			   sizeof(u64)) ? *(u64 *)p : *(u32 *)p;
	}
}

__attribute__((used)) static void vnic_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
	int i;

	if (stringset != ETH_SS_STATS)
		return;

	for (i = 0; i < VNIC_STATS_LEN; i++)
		memcpy(data + i * ETH_GSTRING_LEN,
		       vnic_gstrings_stats[i].stat_string,
		       ETH_GSTRING_LEN);
}

void opa_vnic_set_ethtool_ops(struct net_device *netdev)
{
	netdev->ethtool_ops = &opa_vnic_ethtool_ops;
}

