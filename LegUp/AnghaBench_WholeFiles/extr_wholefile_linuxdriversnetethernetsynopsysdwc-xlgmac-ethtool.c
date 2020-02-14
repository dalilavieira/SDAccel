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
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct xlgmac_hw_ops {unsigned int (* usec_to_riwt ) (struct xlgmac_pdata*,unsigned int) ;int /*<<< orphan*/  (* read_mmc_stats ) (struct xlgmac_pdata*) ;int /*<<< orphan*/  (* config_tx_coalesce ) (struct xlgmac_pdata*) ;int /*<<< orphan*/  (* config_rx_coalesce ) (struct xlgmac_pdata*) ;} ;
struct TYPE_3__ {int version; } ;
struct xlgmac_pdata {int msg_enable; unsigned int rx_usecs; unsigned int rx_frames; unsigned int tx_frames; unsigned int rx_desc_count; unsigned int tx_desc_count; unsigned int rx_riwt; struct xlgmac_hw_ops hw_ops; int /*<<< orphan*/  tx_q_count; int /*<<< orphan*/  rx_q_count; int /*<<< orphan*/  dev; int /*<<< orphan*/  drv_ver; int /*<<< orphan*/  drv_name; TYPE_1__ hw_feat; } ;
struct net_device {int dummy; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_ops {int dummy; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  fw_version; int /*<<< orphan*/  bus_info; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct ethtool_coalesce {unsigned int rx_coalesce_usecs; unsigned int rx_max_coalesced_frames; unsigned int tx_max_coalesced_frames; scalar_t__ rate_sample_interval; scalar_t__ tx_max_coalesced_frames_high; scalar_t__ rx_max_coalesced_frames_high; scalar_t__ rx_coalesce_usecs_high; scalar_t__ pkt_rate_high; scalar_t__ tx_max_coalesced_frames_low; scalar_t__ tx_coalesce_usecs_low; scalar_t__ rx_coalesce_usecs_low; scalar_t__ rx_max_coalesced_frames_low; scalar_t__ use_adaptive_tx_coalesce; scalar_t__ use_adaptive_rx_coalesce; scalar_t__ pkt_rate_low; scalar_t__ stats_block_coalesce_usecs; scalar_t__ tx_coalesce_usecs_irq; scalar_t__ tx_max_coalesced_frames_irq; scalar_t__ tx_coalesce_usecs_high; scalar_t__ tx_coalesce_usecs; scalar_t__ rx_max_coalesced_frames_irq; scalar_t__ rx_coalesce_usecs_irq; } ;
struct ethtool_channels {int /*<<< orphan*/  tx_count; int /*<<< orphan*/  rx_count; void* max_tx; void* max_rx; } ;
struct TYPE_4__ {int stat_offset; int /*<<< orphan*/  stat_string; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int /*<<< orphan*/  ETH_GSTRING_LEN ; 
#define  ETH_SS_STATS 128 
 int /*<<< orphan*/  MAC_VR_DEVID_LEN ; 
 int /*<<< orphan*/  MAC_VR_DEVID_POS ; 
 int /*<<< orphan*/  MAC_VR_SNPSVER_LEN ; 
 int /*<<< orphan*/  MAC_VR_SNPSVER_POS ; 
 int /*<<< orphan*/  MAC_VR_USERVER_LEN ; 
 int /*<<< orphan*/  MAC_VR_USERVER_POS ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int XLGMAC_GET_REG_BITS (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* XLGMAC_MAX_DMA_CHANNELS ; 
 unsigned int XLGMAC_MAX_DMA_RIWT ; 
 unsigned int XLGMAC_MIN_DMA_RIWT ; 
 int XLGMAC_STATS_COUNT ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct ethtool_coalesce*,int /*<<< orphan*/ ,int) ; 
 struct xlgmac_pdata* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int,int,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 unsigned int stub1 (struct xlgmac_pdata*,unsigned int) ; 
 int /*<<< orphan*/  stub2 (struct xlgmac_pdata*) ; 
 int /*<<< orphan*/  stub3 (struct xlgmac_pdata*) ; 
 int /*<<< orphan*/  stub4 (struct xlgmac_pdata*) ; 
 struct ethtool_ops const xlgmac_ethtool_ops ; 
 TYPE_2__* xlgmac_gstring_stats ; 

__attribute__((used)) static void xlgmac_ethtool_get_drvinfo(struct net_device *netdev,
				       struct ethtool_drvinfo *drvinfo)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);
	u32 ver = pdata->hw_feat.version;
	u32 snpsver, devid, userver;

	strlcpy(drvinfo->driver, pdata->drv_name, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, pdata->drv_ver, sizeof(drvinfo->version));
	strlcpy(drvinfo->bus_info, dev_name(pdata->dev),
		sizeof(drvinfo->bus_info));
	/* S|SNPSVER: Synopsys-defined Version
	 * D|DEVID: Indicates the Device family
	 * U|USERVER: User-defined Version
	 */
	snpsver = XLGMAC_GET_REG_BITS(ver, MAC_VR_SNPSVER_POS,
				      MAC_VR_SNPSVER_LEN);
	devid = XLGMAC_GET_REG_BITS(ver, MAC_VR_DEVID_POS,
				    MAC_VR_DEVID_LEN);
	userver = XLGMAC_GET_REG_BITS(ver, MAC_VR_USERVER_POS,
				      MAC_VR_USERVER_LEN);
	snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version),
		 "S.D.U: %x.%x.%x", snpsver, devid, userver);
}

__attribute__((used)) static u32 xlgmac_ethtool_get_msglevel(struct net_device *netdev)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);

	return pdata->msg_enable;
}

__attribute__((used)) static void xlgmac_ethtool_set_msglevel(struct net_device *netdev,
					u32 msglevel)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);

	pdata->msg_enable = msglevel;
}

__attribute__((used)) static void xlgmac_ethtool_get_channels(struct net_device *netdev,
					struct ethtool_channels *channel)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);

	channel->max_rx = XLGMAC_MAX_DMA_CHANNELS;
	channel->max_tx = XLGMAC_MAX_DMA_CHANNELS;
	channel->rx_count = pdata->rx_q_count;
	channel->tx_count = pdata->tx_q_count;
}

__attribute__((used)) static int xlgmac_ethtool_get_coalesce(struct net_device *netdev,
				       struct ethtool_coalesce *ec)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);

	memset(ec, 0, sizeof(struct ethtool_coalesce));
	ec->rx_coalesce_usecs = pdata->rx_usecs;
	ec->rx_max_coalesced_frames = pdata->rx_frames;
	ec->tx_max_coalesced_frames = pdata->tx_frames;

	return 0;
}

__attribute__((used)) static int xlgmac_ethtool_set_coalesce(struct net_device *netdev,
				       struct ethtool_coalesce *ec)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);
	struct xlgmac_hw_ops *hw_ops = &pdata->hw_ops;
	unsigned int rx_frames, rx_riwt, rx_usecs;
	unsigned int tx_frames;

	/* Check for not supported parameters */
	if ((ec->rx_coalesce_usecs_irq) || (ec->rx_max_coalesced_frames_irq) ||
	    (ec->tx_coalesce_usecs) || (ec->tx_coalesce_usecs_high) ||
	    (ec->tx_max_coalesced_frames_irq) || (ec->tx_coalesce_usecs_irq) ||
	    (ec->stats_block_coalesce_usecs) ||  (ec->pkt_rate_low) ||
	    (ec->use_adaptive_rx_coalesce) || (ec->use_adaptive_tx_coalesce) ||
	    (ec->rx_max_coalesced_frames_low) || (ec->rx_coalesce_usecs_low) ||
	    (ec->tx_coalesce_usecs_low) || (ec->tx_max_coalesced_frames_low) ||
	    (ec->pkt_rate_high) || (ec->rx_coalesce_usecs_high) ||
	    (ec->rx_max_coalesced_frames_high) ||
	    (ec->tx_max_coalesced_frames_high) ||
	    (ec->rate_sample_interval))
		return -EOPNOTSUPP;

	rx_usecs = ec->rx_coalesce_usecs;
	rx_riwt = hw_ops->usec_to_riwt(pdata, rx_usecs);
	rx_frames = ec->rx_max_coalesced_frames;
	tx_frames = ec->tx_max_coalesced_frames;

	if ((rx_riwt > XLGMAC_MAX_DMA_RIWT) ||
	    (rx_riwt < XLGMAC_MIN_DMA_RIWT) ||
	    (rx_frames > pdata->rx_desc_count))
		return -EINVAL;

	if (tx_frames > pdata->tx_desc_count)
		return -EINVAL;

	pdata->rx_riwt = rx_riwt;
	pdata->rx_usecs = rx_usecs;
	pdata->rx_frames = rx_frames;
	hw_ops->config_rx_coalesce(pdata);

	pdata->tx_frames = tx_frames;
	hw_ops->config_tx_coalesce(pdata);

	return 0;
}

__attribute__((used)) static void xlgmac_ethtool_get_strings(struct net_device *netdev,
				       u32 stringset, u8 *data)
{
	int i;

	switch (stringset) {
	case ETH_SS_STATS:
		for (i = 0; i < XLGMAC_STATS_COUNT; i++) {
			memcpy(data, xlgmac_gstring_stats[i].stat_string,
			       ETH_GSTRING_LEN);
			data += ETH_GSTRING_LEN;
		}
		break;
	default:
		WARN_ON(1);
		break;
	}
}

__attribute__((used)) static int xlgmac_ethtool_get_sset_count(struct net_device *netdev,
					 int stringset)
{
	int ret;

	switch (stringset) {
	case ETH_SS_STATS:
		ret = XLGMAC_STATS_COUNT;
		break;

	default:
		ret = -EOPNOTSUPP;
	}

	return ret;
}

__attribute__((used)) static void xlgmac_ethtool_get_ethtool_stats(struct net_device *netdev,
					     struct ethtool_stats *stats,
					     u64 *data)
{
	struct xlgmac_pdata *pdata = netdev_priv(netdev);
	u8 *stat;
	int i;

	pdata->hw_ops.read_mmc_stats(pdata);
	for (i = 0; i < XLGMAC_STATS_COUNT; i++) {
		stat = (u8 *)pdata + xlgmac_gstring_stats[i].stat_offset;
		*data++ = *(u64 *)stat;
	}
}

const struct ethtool_ops *xlgmac_get_ethtool_ops(void)
{
	return &xlgmac_ethtool_ops;
}

