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
typedef  scalar_t__ u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
struct xgbe_hw_features {unsigned int rx_ch_cnt; unsigned int tx_ch_cnt; int /*<<< orphan*/  version; } ;
struct TYPE_11__ {int (* phy_config_aneg ) (struct xgbe_prv_data*) ;int (* module_info ) (struct xgbe_prv_data*,struct ethtool_modinfo*) ;int (* module_eeprom ) (struct xgbe_prv_data*,struct ethtool_eeprom*,scalar_t__*) ;int /*<<< orphan*/  (* phy_valid_speed ) (struct xgbe_prv_data*,int) ;} ;
struct xgbe_hw_if {unsigned int (* usec_to_riwt ) (struct xgbe_prv_data*,unsigned int) ;unsigned int (* set_rss_lookup_table ) (struct xgbe_prv_data*,int const*) ;unsigned int (* set_rss_hash_key ) (struct xgbe_prv_data*,scalar_t__ const*) ;int /*<<< orphan*/  (* config_tx_coalesce ) (struct xgbe_prv_data*) ;int /*<<< orphan*/  (* config_rx_coalesce ) (struct xgbe_prv_data*) ;int /*<<< orphan*/  (* riwt_to_usec ) (struct xgbe_prv_data*,unsigned int) ;int /*<<< orphan*/  (* read_mmc_stats ) (struct xgbe_prv_data*) ;} ;
struct TYPE_10__ {scalar_t__ phy_address; scalar_t__ autoneg; int speed; scalar_t__ duplex; int /*<<< orphan*/  port; } ;
struct TYPE_9__ {int /*<<< orphan*/  advertising; int /*<<< orphan*/  supported; } ;
struct ethtool_link_ksettings {TYPE_4__ base; TYPE_3__ link_modes; } ;
struct TYPE_8__ {scalar_t__ autoneg; scalar_t__ address; int speed; scalar_t__ duplex; struct ethtool_link_ksettings lks; scalar_t__ rx_pause; scalar_t__ tx_pause; scalar_t__ pause_autoneg; } ;
struct TYPE_7__ {int /*<<< orphan*/ * rxq_bytes; int /*<<< orphan*/ * rxq_packets; int /*<<< orphan*/ * txq_bytes; int /*<<< orphan*/ * txq_packets; } ;
struct xgbe_prv_data {int tx_ring_count; int rx_ring_count; int msg_enable; unsigned int rx_usecs; unsigned int rx_frames; unsigned int tx_frames; unsigned int rx_desc_count; unsigned int tx_desc_count; unsigned int rx_riwt; unsigned int rx_max_channel_count; unsigned int channel_irq_count; unsigned int tx_max_channel_count; unsigned int tx_max_q_count; int new_rx_ring_count; int new_tx_ring_count; struct xgbe_hw_features hw_feat; TYPE_5__ phy_if; scalar_t__ ptp_clock; struct xgbe_hw_if hw_if; int /*<<< orphan*/  rss_key; int /*<<< orphan*/ * rss_table; int /*<<< orphan*/  dev; TYPE_2__ phy; TYPE_1__ ext_stats; } ;
struct net_device {int dummy; } ;
struct ethtool_ts_info {int so_timestamping; int phc_index; int tx_types; int rx_filters; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_rxnfc {int cmd; int data; } ;
struct ethtool_ringparam {unsigned int rx_max_pending; unsigned int tx_max_pending; unsigned int rx_pending; unsigned int tx_pending; scalar_t__ rx_jumbo_pending; scalar_t__ rx_mini_pending; } ;
struct ethtool_pauseparam {scalar_t__ tx_pause; scalar_t__ rx_pause; scalar_t__ autoneg; } ;
struct ethtool_ops {int dummy; } ;
struct ethtool_modinfo {int dummy; } ;
struct ethtool_eeprom {int dummy; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  fw_version; int /*<<< orphan*/  bus_info; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct ethtool_coalesce {unsigned int rx_coalesce_usecs; unsigned int rx_max_coalesced_frames; unsigned int tx_max_coalesced_frames; scalar_t__ rate_sample_interval; scalar_t__ tx_max_coalesced_frames_high; scalar_t__ tx_coalesce_usecs_high; scalar_t__ rx_max_coalesced_frames_high; scalar_t__ rx_coalesce_usecs_high; scalar_t__ pkt_rate_high; scalar_t__ tx_max_coalesced_frames_low; scalar_t__ tx_coalesce_usecs_low; scalar_t__ rx_max_coalesced_frames_low; scalar_t__ rx_coalesce_usecs_low; scalar_t__ pkt_rate_low; scalar_t__ use_adaptive_tx_coalesce; scalar_t__ use_adaptive_rx_coalesce; scalar_t__ stats_block_coalesce_usecs; scalar_t__ tx_max_coalesced_frames_irq; scalar_t__ tx_coalesce_usecs_irq; scalar_t__ tx_coalesce_usecs; scalar_t__ rx_max_coalesced_frames_irq; scalar_t__ rx_coalesce_usecs_irq; } ;
struct ethtool_channels {unsigned int max_combined; unsigned int max_rx; unsigned int max_tx; unsigned int combined_count; unsigned int rx_count; unsigned int tx_count; scalar_t__ other_count; } ;
struct TYPE_12__ {int stat_offset; int /*<<< orphan*/  stat_string; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 scalar_t__ AUTONEG_DISABLE ; 
 scalar_t__ AUTONEG_ENABLE ; 
 int /*<<< orphan*/  Asym_Pause ; 
 int /*<<< orphan*/  Autoneg ; 
 int /*<<< orphan*/  DEVID ; 
 int /*<<< orphan*/  DMCH ; 
 scalar_t__ DUPLEX_FULL ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
#define  ETHTOOL_GRXRINGS 129 
 int ETH_GSTRING_LEN ; 
 scalar_t__ const ETH_RSS_HASH_NO_CHANGE ; 
 scalar_t__ const ETH_RSS_HASH_TOP ; 
#define  ETH_SS_STATS 128 
 int HWTSTAMP_FILTER_ALL ; 
 int HWTSTAMP_FILTER_NONE ; 
 int HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ ; 
 int HWTSTAMP_FILTER_PTP_V1_L4_EVENT ; 
 int HWTSTAMP_FILTER_PTP_V1_L4_SYNC ; 
 int HWTSTAMP_FILTER_PTP_V2_DELAY_REQ ; 
 int HWTSTAMP_FILTER_PTP_V2_EVENT ; 
 int HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ ; 
 int HWTSTAMP_FILTER_PTP_V2_L4_EVENT ; 
 int HWTSTAMP_FILTER_PTP_V2_L4_SYNC ; 
 int HWTSTAMP_FILTER_PTP_V2_SYNC ; 
 int HWTSTAMP_TX_OFF ; 
 int HWTSTAMP_TX_ON ; 
 int /*<<< orphan*/  MAC_RSSDR ; 
 int /*<<< orphan*/  MAC_VR ; 
 int /*<<< orphan*/  PORT_NONE ; 
 int /*<<< orphan*/  Pause ; 
 int /*<<< orphan*/  SNPSVER ; 
 int SOF_TIMESTAMPING_RAW_HARDWARE ; 
 int SOF_TIMESTAMPING_RX_HARDWARE ; 
 int SOF_TIMESTAMPING_RX_SOFTWARE ; 
 int SOF_TIMESTAMPING_SOFTWARE ; 
 int SOF_TIMESTAMPING_TX_HARDWARE ; 
 int SOF_TIMESTAMPING_TX_SOFTWARE ; 
 int /*<<< orphan*/  USERVER ; 
 scalar_t__ XGBE_ADV (struct ethtool_link_ksettings*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XGBE_CLR_ADV (struct ethtool_link_ksettings*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  XGBE_DRV_NAME ; 
 int /*<<< orphan*/  XGBE_DRV_VERSION ; 
 int /*<<< orphan*/  XGBE_LM_COPY (struct ethtool_link_ksettings*,int /*<<< orphan*/ ,struct ethtool_link_ksettings*,int /*<<< orphan*/ ) ; 
 unsigned int XGBE_RX_DESC_CNT_MAX ; 
 unsigned int XGBE_RX_DESC_CNT_MIN ; 
 int /*<<< orphan*/  XGBE_SET_ADV (struct ethtool_link_ksettings*,int /*<<< orphan*/ ) ; 
 int XGBE_STATS_COUNT ; 
 unsigned int XGBE_TX_DESC_CNT_MAX ; 
 unsigned int XGBE_TX_DESC_CNT_MIN ; 
 int XGMAC_GET_BITS (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned int XGMAC_MAX_DMA_RIWT ; 
 int /*<<< orphan*/  __ETHTOOL_DECLARE_LINK_MODE_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __ETHTOOL_LINK_MODE_MASK_NBITS ; 
 unsigned int __rounddown_pow_of_two (unsigned int) ; 
 int /*<<< orphan*/  advertising ; 
 int /*<<< orphan*/  bitmap_and (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bitmap_copy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ bitmap_empty (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_name (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  link ; 
 int /*<<< orphan*/  lp_advertising ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (struct ethtool_coalesce*,int /*<<< orphan*/ ,int) ; 
 unsigned int min (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*,...) ; 
 int /*<<< orphan*/  netdev_notice (struct net_device*,char*,unsigned int) ; 
 struct xgbe_prv_data* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_dbg (struct xgbe_prv_data*,int /*<<< orphan*/ ,struct net_device*,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ netif_running (struct net_device*) ; 
 int ptp_clock_index (scalar_t__) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int,int,int) ; 
 int /*<<< orphan*/  sprintf (scalar_t__*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct xgbe_prv_data*) ; 
 unsigned int stub10 (struct xgbe_prv_data*,scalar_t__ const*) ; 
 int stub11 (struct xgbe_prv_data*,struct ethtool_modinfo*) ; 
 int stub12 (struct xgbe_prv_data*,struct ethtool_eeprom*,scalar_t__*) ; 
 int stub2 (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  stub3 (struct xgbe_prv_data*,int) ; 
 int stub4 (struct xgbe_prv_data*) ; 
 unsigned int stub5 (struct xgbe_prv_data*,unsigned int) ; 
 int /*<<< orphan*/  stub6 (struct xgbe_prv_data*,unsigned int) ; 
 int /*<<< orphan*/  stub7 (struct xgbe_prv_data*) ; 
 int /*<<< orphan*/  stub8 (struct xgbe_prv_data*) ; 
 unsigned int stub9 (struct xgbe_prv_data*,int const*) ; 
 int /*<<< orphan*/  supported ; 
 struct ethtool_ops const xgbe_ethtool_ops ; 
 int /*<<< orphan*/  xgbe_full_restart_dev (struct xgbe_prv_data*) ; 
 TYPE_6__* xgbe_gstring_stats ; 
 int /*<<< orphan*/  xgbe_restart_dev (struct xgbe_prv_data*) ; 

__attribute__((used)) static inline int xgbe_pci_init(void) { return 0; }

__attribute__((used)) static inline void xgbe_pci_exit(void) { }

__attribute__((used)) static inline void xgbe_debugfs_init(struct xgbe_prv_data *pdata) {}

__attribute__((used)) static inline void xgbe_debugfs_exit(struct xgbe_prv_data *pdata) {}

__attribute__((used)) static inline void xgbe_debugfs_rename(struct xgbe_prv_data *pdata) {}

__attribute__((used)) static void xgbe_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	int i;

	switch (stringset) {
	case ETH_SS_STATS:
		for (i = 0; i < XGBE_STATS_COUNT; i++) {
			memcpy(data, xgbe_gstring_stats[i].stat_string,
			       ETH_GSTRING_LEN);
			data += ETH_GSTRING_LEN;
		}
		for (i = 0; i < pdata->tx_ring_count; i++) {
			sprintf(data, "txq_%u_packets", i);
			data += ETH_GSTRING_LEN;
			sprintf(data, "txq_%u_bytes", i);
			data += ETH_GSTRING_LEN;
		}
		for (i = 0; i < pdata->rx_ring_count; i++) {
			sprintf(data, "rxq_%u_packets", i);
			data += ETH_GSTRING_LEN;
			sprintf(data, "rxq_%u_bytes", i);
			data += ETH_GSTRING_LEN;
		}
		break;
	}
}

__attribute__((used)) static void xgbe_get_ethtool_stats(struct net_device *netdev,
				   struct ethtool_stats *stats, u64 *data)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	u8 *stat;
	int i;

	pdata->hw_if.read_mmc_stats(pdata);
	for (i = 0; i < XGBE_STATS_COUNT; i++) {
		stat = (u8 *)pdata + xgbe_gstring_stats[i].stat_offset;
		*data++ = *(u64 *)stat;
	}
	for (i = 0; i < pdata->tx_ring_count; i++) {
		*data++ = pdata->ext_stats.txq_packets[i];
		*data++ = pdata->ext_stats.txq_bytes[i];
	}
	for (i = 0; i < pdata->rx_ring_count; i++) {
		*data++ = pdata->ext_stats.rxq_packets[i];
		*data++ = pdata->ext_stats.rxq_bytes[i];
	}
}

__attribute__((used)) static int xgbe_get_sset_count(struct net_device *netdev, int stringset)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	int ret;

	switch (stringset) {
	case ETH_SS_STATS:
		ret = XGBE_STATS_COUNT +
		      (pdata->tx_ring_count * 2) +
		      (pdata->rx_ring_count * 2);
		break;

	default:
		ret = -EOPNOTSUPP;
	}

	return ret;
}

__attribute__((used)) static void xgbe_get_pauseparam(struct net_device *netdev,
				struct ethtool_pauseparam *pause)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	pause->autoneg = pdata->phy.pause_autoneg;
	pause->tx_pause = pdata->phy.tx_pause;
	pause->rx_pause = pdata->phy.rx_pause;
}

__attribute__((used)) static int xgbe_set_pauseparam(struct net_device *netdev,
			       struct ethtool_pauseparam *pause)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	struct ethtool_link_ksettings *lks = &pdata->phy.lks;
	int ret = 0;

	if (pause->autoneg && (pdata->phy.autoneg != AUTONEG_ENABLE)) {
		netdev_err(netdev,
			   "autoneg disabled, pause autoneg not available\n");
		return -EINVAL;
	}

	pdata->phy.pause_autoneg = pause->autoneg;
	pdata->phy.tx_pause = pause->tx_pause;
	pdata->phy.rx_pause = pause->rx_pause;

	XGBE_CLR_ADV(lks, Pause);
	XGBE_CLR_ADV(lks, Asym_Pause);

	if (pause->rx_pause) {
		XGBE_SET_ADV(lks, Pause);
		XGBE_SET_ADV(lks, Asym_Pause);
	}

	if (pause->tx_pause) {
		/* Equivalent to XOR of Asym_Pause */
		if (XGBE_ADV(lks, Asym_Pause))
			XGBE_CLR_ADV(lks, Asym_Pause);
		else
			XGBE_SET_ADV(lks, Asym_Pause);
	}

	if (netif_running(netdev))
		ret = pdata->phy_if.phy_config_aneg(pdata);

	return ret;
}

__attribute__((used)) static int xgbe_get_link_ksettings(struct net_device *netdev,
				   struct ethtool_link_ksettings *cmd)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	struct ethtool_link_ksettings *lks = &pdata->phy.lks;

	cmd->base.phy_address = pdata->phy.address;

	cmd->base.autoneg = pdata->phy.autoneg;
	cmd->base.speed = pdata->phy.speed;
	cmd->base.duplex = pdata->phy.duplex;

	cmd->base.port = PORT_NONE;

	XGBE_LM_COPY(cmd, supported, lks, supported);
	XGBE_LM_COPY(cmd, advertising, lks, advertising);
	XGBE_LM_COPY(cmd, lp_advertising, lks, lp_advertising);

	return 0;
}

__attribute__((used)) static int xgbe_set_link_ksettings(struct net_device *netdev,
				   const struct ethtool_link_ksettings *cmd)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	struct ethtool_link_ksettings *lks = &pdata->phy.lks;
	__ETHTOOL_DECLARE_LINK_MODE_MASK(advertising);
	u32 speed;
	int ret;

	speed = cmd->base.speed;

	if (cmd->base.phy_address != pdata->phy.address) {
		netdev_err(netdev, "invalid phy address %hhu\n",
			   cmd->base.phy_address);
		return -EINVAL;
	}

	if ((cmd->base.autoneg != AUTONEG_ENABLE) &&
	    (cmd->base.autoneg != AUTONEG_DISABLE)) {
		netdev_err(netdev, "unsupported autoneg %hhu\n",
			   cmd->base.autoneg);
		return -EINVAL;
	}

	if (cmd->base.autoneg == AUTONEG_DISABLE) {
		if (!pdata->phy_if.phy_valid_speed(pdata, speed)) {
			netdev_err(netdev, "unsupported speed %u\n", speed);
			return -EINVAL;
		}

		if (cmd->base.duplex != DUPLEX_FULL) {
			netdev_err(netdev, "unsupported duplex %hhu\n",
				   cmd->base.duplex);
			return -EINVAL;
		}
	}

	netif_dbg(pdata, link, netdev,
		  "requested advertisement 0x%*pb, phy supported 0x%*pb\n",
		  __ETHTOOL_LINK_MODE_MASK_NBITS, cmd->link_modes.advertising,
		  __ETHTOOL_LINK_MODE_MASK_NBITS, lks->link_modes.supported);

	bitmap_and(advertising,
		   cmd->link_modes.advertising, lks->link_modes.supported,
		   __ETHTOOL_LINK_MODE_MASK_NBITS);

	if ((cmd->base.autoneg == AUTONEG_ENABLE) &&
	    bitmap_empty(advertising, __ETHTOOL_LINK_MODE_MASK_NBITS)) {
		netdev_err(netdev,
			   "unsupported requested advertisement\n");
		return -EINVAL;
	}

	ret = 0;
	pdata->phy.autoneg = cmd->base.autoneg;
	pdata->phy.speed = speed;
	pdata->phy.duplex = cmd->base.duplex;
	bitmap_copy(lks->link_modes.advertising, advertising,
		    __ETHTOOL_LINK_MODE_MASK_NBITS);

	if (cmd->base.autoneg == AUTONEG_ENABLE)
		XGBE_SET_ADV(lks, Autoneg);
	else
		XGBE_CLR_ADV(lks, Autoneg);

	if (netif_running(netdev))
		ret = pdata->phy_if.phy_config_aneg(pdata);

	return ret;
}

__attribute__((used)) static void xgbe_get_drvinfo(struct net_device *netdev,
			     struct ethtool_drvinfo *drvinfo)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	struct xgbe_hw_features *hw_feat = &pdata->hw_feat;

	strlcpy(drvinfo->driver, XGBE_DRV_NAME, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, XGBE_DRV_VERSION, sizeof(drvinfo->version));
	strlcpy(drvinfo->bus_info, dev_name(pdata->dev),
		sizeof(drvinfo->bus_info));
	snprintf(drvinfo->fw_version, sizeof(drvinfo->fw_version), "%d.%d.%d",
		 XGMAC_GET_BITS(hw_feat->version, MAC_VR, USERVER),
		 XGMAC_GET_BITS(hw_feat->version, MAC_VR, DEVID),
		 XGMAC_GET_BITS(hw_feat->version, MAC_VR, SNPSVER));
}

__attribute__((used)) static u32 xgbe_get_msglevel(struct net_device *netdev)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	return pdata->msg_enable;
}

__attribute__((used)) static void xgbe_set_msglevel(struct net_device *netdev, u32 msglevel)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	pdata->msg_enable = msglevel;
}

__attribute__((used)) static int xgbe_get_coalesce(struct net_device *netdev,
			     struct ethtool_coalesce *ec)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	memset(ec, 0, sizeof(struct ethtool_coalesce));

	ec->rx_coalesce_usecs = pdata->rx_usecs;
	ec->rx_max_coalesced_frames = pdata->rx_frames;

	ec->tx_max_coalesced_frames = pdata->tx_frames;

	return 0;
}

__attribute__((used)) static int xgbe_set_coalesce(struct net_device *netdev,
			     struct ethtool_coalesce *ec)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	struct xgbe_hw_if *hw_if = &pdata->hw_if;
	unsigned int rx_frames, rx_riwt, rx_usecs;
	unsigned int tx_frames;

	/* Check for not supported parameters  */
	if ((ec->rx_coalesce_usecs_irq) ||
	    (ec->rx_max_coalesced_frames_irq) ||
	    (ec->tx_coalesce_usecs) ||
	    (ec->tx_coalesce_usecs_irq) ||
	    (ec->tx_max_coalesced_frames_irq) ||
	    (ec->stats_block_coalesce_usecs) ||
	    (ec->use_adaptive_rx_coalesce) ||
	    (ec->use_adaptive_tx_coalesce) ||
	    (ec->pkt_rate_low) ||
	    (ec->rx_coalesce_usecs_low) ||
	    (ec->rx_max_coalesced_frames_low) ||
	    (ec->tx_coalesce_usecs_low) ||
	    (ec->tx_max_coalesced_frames_low) ||
	    (ec->pkt_rate_high) ||
	    (ec->rx_coalesce_usecs_high) ||
	    (ec->rx_max_coalesced_frames_high) ||
	    (ec->tx_coalesce_usecs_high) ||
	    (ec->tx_max_coalesced_frames_high) ||
	    (ec->rate_sample_interval)) {
		netdev_err(netdev, "unsupported coalescing parameter\n");
		return -EOPNOTSUPP;
	}

	rx_riwt = hw_if->usec_to_riwt(pdata, ec->rx_coalesce_usecs);
	rx_usecs = ec->rx_coalesce_usecs;
	rx_frames = ec->rx_max_coalesced_frames;

	/* Use smallest possible value if conversion resulted in zero */
	if (rx_usecs && !rx_riwt)
		rx_riwt = 1;

	/* Check the bounds of values for Rx */
	if (rx_riwt > XGMAC_MAX_DMA_RIWT) {
		netdev_err(netdev, "rx-usec is limited to %d usecs\n",
			   hw_if->riwt_to_usec(pdata, XGMAC_MAX_DMA_RIWT));
		return -EINVAL;
	}
	if (rx_frames > pdata->rx_desc_count) {
		netdev_err(netdev, "rx-frames is limited to %d frames\n",
			   pdata->rx_desc_count);
		return -EINVAL;
	}

	tx_frames = ec->tx_max_coalesced_frames;

	/* Check the bounds of values for Tx */
	if (tx_frames > pdata->tx_desc_count) {
		netdev_err(netdev, "tx-frames is limited to %d frames\n",
			   pdata->tx_desc_count);
		return -EINVAL;
	}

	pdata->rx_riwt = rx_riwt;
	pdata->rx_usecs = rx_usecs;
	pdata->rx_frames = rx_frames;
	hw_if->config_rx_coalesce(pdata);

	pdata->tx_frames = tx_frames;
	hw_if->config_tx_coalesce(pdata);

	return 0;
}

__attribute__((used)) static int xgbe_get_rxnfc(struct net_device *netdev,
			  struct ethtool_rxnfc *rxnfc, u32 *rule_locs)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	switch (rxnfc->cmd) {
	case ETHTOOL_GRXRINGS:
		rxnfc->data = pdata->rx_ring_count;
		break;
	default:
		return -EOPNOTSUPP;
	}

	return 0;
}

__attribute__((used)) static u32 xgbe_get_rxfh_key_size(struct net_device *netdev)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	return sizeof(pdata->rss_key);
}

__attribute__((used)) static u32 xgbe_get_rxfh_indir_size(struct net_device *netdev)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	return ARRAY_SIZE(pdata->rss_table);
}

__attribute__((used)) static int xgbe_get_rxfh(struct net_device *netdev, u32 *indir, u8 *key,
			 u8 *hfunc)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	unsigned int i;

	if (indir) {
		for (i = 0; i < ARRAY_SIZE(pdata->rss_table); i++)
			indir[i] = XGMAC_GET_BITS(pdata->rss_table[i],
						  MAC_RSSDR, DMCH);
	}

	if (key)
		memcpy(key, pdata->rss_key, sizeof(pdata->rss_key));

	if (hfunc)
		*hfunc = ETH_RSS_HASH_TOP;

	return 0;
}

__attribute__((used)) static int xgbe_set_rxfh(struct net_device *netdev, const u32 *indir,
			 const u8 *key, const u8 hfunc)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	struct xgbe_hw_if *hw_if = &pdata->hw_if;
	unsigned int ret;

	if (hfunc != ETH_RSS_HASH_NO_CHANGE && hfunc != ETH_RSS_HASH_TOP) {
		netdev_err(netdev, "unsupported hash function\n");
		return -EOPNOTSUPP;
	}

	if (indir) {
		ret = hw_if->set_rss_lookup_table(pdata, indir);
		if (ret)
			return ret;
	}

	if (key) {
		ret = hw_if->set_rss_hash_key(pdata, key);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int xgbe_get_ts_info(struct net_device *netdev,
			    struct ethtool_ts_info *ts_info)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	ts_info->so_timestamping = SOF_TIMESTAMPING_TX_SOFTWARE |
				   SOF_TIMESTAMPING_RX_SOFTWARE |
				   SOF_TIMESTAMPING_SOFTWARE |
				   SOF_TIMESTAMPING_TX_HARDWARE |
				   SOF_TIMESTAMPING_RX_HARDWARE |
				   SOF_TIMESTAMPING_RAW_HARDWARE;

	if (pdata->ptp_clock)
		ts_info->phc_index = ptp_clock_index(pdata->ptp_clock);
	else
		ts_info->phc_index = -1;

	ts_info->tx_types = (1 << HWTSTAMP_TX_OFF) | (1 << HWTSTAMP_TX_ON);
	ts_info->rx_filters = (1 << HWTSTAMP_FILTER_NONE) |
			      (1 << HWTSTAMP_FILTER_PTP_V1_L4_EVENT) |
			      (1 << HWTSTAMP_FILTER_PTP_V1_L4_SYNC) |
			      (1 << HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ) |
			      (1 << HWTSTAMP_FILTER_PTP_V2_L4_EVENT) |
			      (1 << HWTSTAMP_FILTER_PTP_V2_L4_SYNC) |
			      (1 << HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ) |
			      (1 << HWTSTAMP_FILTER_PTP_V2_EVENT) |
			      (1 << HWTSTAMP_FILTER_PTP_V2_SYNC) |
			      (1 << HWTSTAMP_FILTER_PTP_V2_DELAY_REQ) |
			      (1 << HWTSTAMP_FILTER_ALL);

	return 0;
}

__attribute__((used)) static int xgbe_get_module_info(struct net_device *netdev,
				struct ethtool_modinfo *modinfo)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	return pdata->phy_if.module_info(pdata, modinfo);
}

__attribute__((used)) static int xgbe_get_module_eeprom(struct net_device *netdev,
				  struct ethtool_eeprom *eeprom, u8 *data)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	return pdata->phy_if.module_eeprom(pdata, eeprom, data);
}

__attribute__((used)) static void xgbe_get_ringparam(struct net_device *netdev,
			       struct ethtool_ringparam *ringparam)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);

	ringparam->rx_max_pending = XGBE_RX_DESC_CNT_MAX;
	ringparam->tx_max_pending = XGBE_TX_DESC_CNT_MAX;
	ringparam->rx_pending = pdata->rx_desc_count;
	ringparam->tx_pending = pdata->tx_desc_count;
}

__attribute__((used)) static int xgbe_set_ringparam(struct net_device *netdev,
			      struct ethtool_ringparam *ringparam)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	unsigned int rx, tx;

	if (ringparam->rx_mini_pending || ringparam->rx_jumbo_pending) {
		netdev_err(netdev, "unsupported ring parameter\n");
		return -EINVAL;
	}

	if ((ringparam->rx_pending < XGBE_RX_DESC_CNT_MIN) ||
	    (ringparam->rx_pending > XGBE_RX_DESC_CNT_MAX)) {
		netdev_err(netdev,
			   "rx ring parameter must be between %u and %u\n",
			   XGBE_RX_DESC_CNT_MIN, XGBE_RX_DESC_CNT_MAX);
		return -EINVAL;
	}

	if ((ringparam->tx_pending < XGBE_TX_DESC_CNT_MIN) ||
	    (ringparam->tx_pending > XGBE_TX_DESC_CNT_MAX)) {
		netdev_err(netdev,
			   "tx ring parameter must be between %u and %u\n",
			   XGBE_TX_DESC_CNT_MIN, XGBE_TX_DESC_CNT_MAX);
		return -EINVAL;
	}

	rx = __rounddown_pow_of_two(ringparam->rx_pending);
	if (rx != ringparam->rx_pending)
		netdev_notice(netdev,
			      "rx ring parameter rounded to power of two: %u\n",
			      rx);

	tx = __rounddown_pow_of_two(ringparam->tx_pending);
	if (tx != ringparam->tx_pending)
		netdev_notice(netdev,
			      "tx ring parameter rounded to power of two: %u\n",
			      tx);

	if ((rx == pdata->rx_desc_count) &&
	    (tx == pdata->tx_desc_count))
		goto out;

	pdata->rx_desc_count = rx;
	pdata->tx_desc_count = tx;

	xgbe_restart_dev(pdata);

out:
	return 0;
}

__attribute__((used)) static void xgbe_get_channels(struct net_device *netdev,
			      struct ethtool_channels *channels)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	unsigned int rx, tx, combined;

	/* Calculate maximums allowed:
	 *   - Take into account the number of available IRQs
	 *   - Do not take into account the number of online CPUs so that
	 *     the user can over-subscribe if desired
	 *   - Tx is additionally limited by the number of hardware queues
	 */
	rx = min(pdata->hw_feat.rx_ch_cnt, pdata->rx_max_channel_count);
	rx = min(rx, pdata->channel_irq_count);
	tx = min(pdata->hw_feat.tx_ch_cnt, pdata->tx_max_channel_count);
	tx = min(tx, pdata->channel_irq_count);
	tx = min(tx, pdata->tx_max_q_count);

	combined = min(rx, tx);

	channels->max_combined = combined;
	channels->max_rx = rx ? rx - 1 : 0;
	channels->max_tx = tx ? tx - 1 : 0;

	/* Get current settings based on device state */
	rx = pdata->new_rx_ring_count ? : pdata->rx_ring_count;
	tx = pdata->new_tx_ring_count ? : pdata->tx_ring_count;

	combined = min(rx, tx);
	rx -= combined;
	tx -= combined;

	channels->combined_count = combined;
	channels->rx_count = rx;
	channels->tx_count = tx;
}

__attribute__((used)) static void xgbe_print_set_channels_input(struct net_device *netdev,
					  struct ethtool_channels *channels)
{
	netdev_err(netdev, "channel inputs: combined=%u, rx-only=%u, tx-only=%u\n",
		   channels->combined_count, channels->rx_count,
		   channels->tx_count);
}

__attribute__((used)) static int xgbe_set_channels(struct net_device *netdev,
			     struct ethtool_channels *channels)
{
	struct xgbe_prv_data *pdata = netdev_priv(netdev);
	unsigned int rx, rx_curr, tx, tx_curr, combined;

	/* Calculate maximums allowed:
	 *   - Take into account the number of available IRQs
	 *   - Do not take into account the number of online CPUs so that
	 *     the user can over-subscribe if desired
	 *   - Tx is additionally limited by the number of hardware queues
	 */
	rx = min(pdata->hw_feat.rx_ch_cnt, pdata->rx_max_channel_count);
	rx = min(rx, pdata->channel_irq_count);
	tx = min(pdata->hw_feat.tx_ch_cnt, pdata->tx_max_channel_count);
	tx = min(tx, pdata->tx_max_q_count);
	tx = min(tx, pdata->channel_irq_count);

	combined = min(rx, tx);

	/* Should not be setting other count */
	if (channels->other_count) {
		netdev_err(netdev,
			   "other channel count must be zero\n");
		return -EINVAL;
	}

	/* Require at least one Combined (Rx and Tx) channel */
	if (!channels->combined_count) {
		netdev_err(netdev,
			   "at least one combined Rx/Tx channel is required\n");
		xgbe_print_set_channels_input(netdev, channels);
		return -EINVAL;
	}

	/* Check combined channels */
	if (channels->combined_count > combined) {
		netdev_err(netdev,
			   "combined channel count cannot exceed %u\n",
			   combined);
		xgbe_print_set_channels_input(netdev, channels);
		return -EINVAL;
	}

	/* Can have some Rx-only or Tx-only channels, but not both */
	if (channels->rx_count && channels->tx_count) {
		netdev_err(netdev,
			   "cannot specify both Rx-only and Tx-only channels\n");
		xgbe_print_set_channels_input(netdev, channels);
		return -EINVAL;
	}

	/* Check that we don't exceed the maximum number of channels */
	if ((channels->combined_count + channels->rx_count) > rx) {
		netdev_err(netdev,
			   "total Rx channels (%u) requested exceeds maximum available (%u)\n",
			   channels->combined_count + channels->rx_count, rx);
		xgbe_print_set_channels_input(netdev, channels);
		return -EINVAL;
	}

	if ((channels->combined_count + channels->tx_count) > tx) {
		netdev_err(netdev,
			   "total Tx channels (%u) requested exceeds maximum available (%u)\n",
			   channels->combined_count + channels->tx_count, tx);
		xgbe_print_set_channels_input(netdev, channels);
		return -EINVAL;
	}

	rx = channels->combined_count + channels->rx_count;
	tx = channels->combined_count + channels->tx_count;

	rx_curr = pdata->new_rx_ring_count ? : pdata->rx_ring_count;
	tx_curr = pdata->new_tx_ring_count ? : pdata->tx_ring_count;

	if ((rx == rx_curr) && (tx == tx_curr))
		goto out;

	pdata->new_rx_ring_count = rx;
	pdata->new_tx_ring_count = tx;

	xgbe_full_restart_dev(pdata);

out:
	return 0;
}

const struct ethtool_ops *xgbe_get_ethtool_ops(void)
{
	return &xgbe_ethtool_ops;
}

