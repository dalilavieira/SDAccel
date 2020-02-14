#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  void u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct platform_device {char* name; } ;
struct net_device {int /*<<< orphan*/ * ethtool_ops; } ;
struct TYPE_10__ {int /*<<< orphan*/  trace_size; scalar_t__ trace; int /*<<< orphan*/  lock; } ;
struct fjes_hw {int max_epid; int my_epid; TYPE_4__ hw_info; scalar_t__ debug_mode; TYPE_2__* ep_shm_info; } ;
struct fjes_adapter {struct fjes_hw hw; struct platform_device* plat_dev; } ;
struct ethtool_stats {int dummy; } ;
struct ethtool_regs {int version; } ;
struct TYPE_9__ {int speed; int /*<<< orphan*/  port; int /*<<< orphan*/  autoneg; int /*<<< orphan*/  duplex; } ;
struct ethtool_link_ksettings {TYPE_3__ base; } ;
struct ethtool_dump {int version; scalar_t__ flag; int /*<<< orphan*/  len; } ;
struct ethtool_drvinfo {int /*<<< orphan*/  bus_info; int /*<<< orphan*/  fw_version; int /*<<< orphan*/  version; int /*<<< orphan*/  driver; } ;
struct TYPE_11__ {int stat_offset; int sizeof_stat; scalar_t__ stat_string; } ;
struct TYPE_7__ {int com_regist_buf_exec; int com_unregist_buf_exec; int send_intr_rx; int send_intr_unshare; int send_intr_zoneupdate; int recv_intr_rx; int recv_intr_unshare; int recv_intr_stop; int recv_intr_zoneupdate; int tx_buffer_full; int tx_dropped_not_shared; int tx_dropped_ver_mismatch; int tx_dropped_buf_size_mismatch; int tx_dropped_vlanid_mismatch; } ;
struct TYPE_8__ {TYPE_1__ ep_stats; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_5__*) ; 
 int /*<<< orphan*/  AUTONEG_DISABLE ; 
 int /*<<< orphan*/  DUPLEX_FULL ; 
 int EOPNOTSUPP ; 
 int EPERM ; 
 int /*<<< orphan*/  ETH_GSTRING_LEN ; 
#define  ETH_SS_STATS 128 
 int FJES_STATS_LEN ; 
 int /*<<< orphan*/  PORT_NONE ; 
 int /*<<< orphan*/  XSCT_CR ; 
 int /*<<< orphan*/  XSCT_CS ; 
 int /*<<< orphan*/  XSCT_DCTL ; 
 int /*<<< orphan*/  XSCT_ICTL ; 
 int /*<<< orphan*/  XSCT_IG ; 
 int /*<<< orphan*/  XSCT_IMC ; 
 int /*<<< orphan*/  XSCT_IMS ; 
 int /*<<< orphan*/  XSCT_IS ; 
 int /*<<< orphan*/  XSCT_MAX_EP ; 
 int /*<<< orphan*/  XSCT_OWNER_EPID ; 
 int /*<<< orphan*/  XSCT_REQBAH ; 
 int /*<<< orphan*/  XSCT_REQBAL ; 
 int /*<<< orphan*/  XSCT_REQBL ; 
 int /*<<< orphan*/  XSCT_RESPBAH ; 
 int /*<<< orphan*/  XSCT_RESPBAL ; 
 int /*<<< orphan*/  XSCT_RESPBL ; 
 int /*<<< orphan*/  XSCT_SHSTSAH ; 
 int /*<<< orphan*/  XSCT_SHSTSAL ; 
 int /*<<< orphan*/  advertising ; 
 int /*<<< orphan*/  ethtool_link_ksettings_zero_link_mode (struct ethtool_link_ksettings*,int /*<<< orphan*/ ) ; 
 char* fjes_driver_name ; 
 char* fjes_driver_version ; 
 int /*<<< orphan*/  fjes_ethtool_ops ; 
 TYPE_5__* fjes_gstrings_stats ; 
 int fjes_hw_start_debug (struct fjes_hw*) ; 
 int fjes_hw_stop_debug (struct fjes_hw*) ; 
 int /*<<< orphan*/  memcpy (void*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct fjes_adapter* netdev_priv (struct net_device*) ; 
 int rd32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,char*) ; 
 int /*<<< orphan*/  sprintf (void*,char*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  supported ; 

__attribute__((used)) static inline void fjes_dbg_adapter_init(struct fjes_adapter *adapter) {}

__attribute__((used)) static inline void fjes_dbg_adapter_exit(struct fjes_adapter *adapter) {}

__attribute__((used)) static inline void fjes_dbg_init(void) {}

__attribute__((used)) static inline void fjes_dbg_exit(void) {}

__attribute__((used)) static void fjes_get_ethtool_stats(struct net_device *netdev,
				   struct ethtool_stats *stats, u64 *data)
{
	struct fjes_adapter *adapter = netdev_priv(netdev);
	struct fjes_hw *hw = &adapter->hw;
	int epidx;
	char *p;
	int i;

	for (i = 0; i < ARRAY_SIZE(fjes_gstrings_stats); i++) {
		p = (char *)adapter + fjes_gstrings_stats[i].stat_offset;
		data[i] = (fjes_gstrings_stats[i].sizeof_stat == sizeof(u64))
			? *(u64 *)p : *(u32 *)p;
	}
	for (epidx = 0; epidx < hw->max_epid; epidx++) {
		if (epidx == hw->my_epid)
			continue;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.com_regist_buf_exec;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.com_unregist_buf_exec;
		data[i++] = hw->ep_shm_info[epidx].ep_stats.send_intr_rx;
		data[i++] = hw->ep_shm_info[epidx].ep_stats.send_intr_unshare;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.send_intr_zoneupdate;
		data[i++] = hw->ep_shm_info[epidx].ep_stats.recv_intr_rx;
		data[i++] = hw->ep_shm_info[epidx].ep_stats.recv_intr_unshare;
		data[i++] = hw->ep_shm_info[epidx].ep_stats.recv_intr_stop;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.recv_intr_zoneupdate;
		data[i++] = hw->ep_shm_info[epidx].ep_stats.tx_buffer_full;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.tx_dropped_not_shared;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.tx_dropped_ver_mismatch;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.tx_dropped_buf_size_mismatch;
		data[i++] = hw->ep_shm_info[epidx].ep_stats
				.tx_dropped_vlanid_mismatch;
	}
}

__attribute__((used)) static void fjes_get_strings(struct net_device *netdev,
			     u32 stringset, u8 *data)
{
	struct fjes_adapter *adapter = netdev_priv(netdev);
	struct fjes_hw *hw = &adapter->hw;
	u8 *p = data;
	int i;

	switch (stringset) {
	case ETH_SS_STATS:
		for (i = 0; i < ARRAY_SIZE(fjes_gstrings_stats); i++) {
			memcpy(p, fjes_gstrings_stats[i].stat_string,
			       ETH_GSTRING_LEN);
			p += ETH_GSTRING_LEN;
		}
		for (i = 0; i < hw->max_epid; i++) {
			if (i == hw->my_epid)
				continue;
			sprintf(p, "ep%u_com_regist_buf_exec", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_com_unregist_buf_exec", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_send_intr_rx", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_send_intr_unshare", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_send_intr_zoneupdate", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_recv_intr_rx", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_recv_intr_unshare", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_recv_intr_stop", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_recv_intr_zoneupdate", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_tx_buffer_full", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_tx_dropped_not_shared", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_tx_dropped_ver_mismatch", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_tx_dropped_buf_size_mismatch", i);
			p += ETH_GSTRING_LEN;
			sprintf(p, "ep%u_tx_dropped_vlanid_mismatch", i);
			p += ETH_GSTRING_LEN;
		}
		break;
	}
}

__attribute__((used)) static int fjes_get_sset_count(struct net_device *netdev, int sset)
{
	switch (sset) {
	case ETH_SS_STATS:
		return FJES_STATS_LEN;
	default:
		return -EOPNOTSUPP;
	}
}

__attribute__((used)) static void fjes_get_drvinfo(struct net_device *netdev,
			     struct ethtool_drvinfo *drvinfo)
{
	struct fjes_adapter *adapter = netdev_priv(netdev);
	struct platform_device *plat_dev;

	plat_dev = adapter->plat_dev;

	strlcpy(drvinfo->driver, fjes_driver_name, sizeof(drvinfo->driver));
	strlcpy(drvinfo->version, fjes_driver_version,
		sizeof(drvinfo->version));

	strlcpy(drvinfo->fw_version, "none", sizeof(drvinfo->fw_version));
	snprintf(drvinfo->bus_info, sizeof(drvinfo->bus_info),
		 "platform:%s", plat_dev->name);
}

__attribute__((used)) static int fjes_get_link_ksettings(struct net_device *netdev,
				   struct ethtool_link_ksettings *ecmd)
{
	ethtool_link_ksettings_zero_link_mode(ecmd, supported);
	ethtool_link_ksettings_zero_link_mode(ecmd, advertising);
	ecmd->base.duplex = DUPLEX_FULL;
	ecmd->base.autoneg = AUTONEG_DISABLE;
	ecmd->base.port = PORT_NONE;
	ecmd->base.speed = 20000;	/* 20Gb/s */

	return 0;
}

__attribute__((used)) static int fjes_get_regs_len(struct net_device *netdev)
{
#define FJES_REGS_LEN	37
	return FJES_REGS_LEN * sizeof(u32);
}

__attribute__((used)) static void fjes_get_regs(struct net_device *netdev,
			  struct ethtool_regs *regs, void *p)
{
	struct fjes_adapter *adapter = netdev_priv(netdev);
	struct fjes_hw *hw = &adapter->hw;
	u32 *regs_buff = p;

	memset(p, 0, FJES_REGS_LEN * sizeof(u32));

	regs->version = 1;

	/* Information registers */
	regs_buff[0] = rd32(XSCT_OWNER_EPID);
	regs_buff[1] = rd32(XSCT_MAX_EP);

	/* Device Control registers */
	regs_buff[4] = rd32(XSCT_DCTL);

	/* Command Control registers */
	regs_buff[8] = rd32(XSCT_CR);
	regs_buff[9] = rd32(XSCT_CS);
	regs_buff[10] = rd32(XSCT_SHSTSAL);
	regs_buff[11] = rd32(XSCT_SHSTSAH);

	regs_buff[13] = rd32(XSCT_REQBL);
	regs_buff[14] = rd32(XSCT_REQBAL);
	regs_buff[15] = rd32(XSCT_REQBAH);

	regs_buff[17] = rd32(XSCT_RESPBL);
	regs_buff[18] = rd32(XSCT_RESPBAL);
	regs_buff[19] = rd32(XSCT_RESPBAH);

	/* Interrupt Control registers */
	regs_buff[32] = rd32(XSCT_IS);
	regs_buff[33] = rd32(XSCT_IMS);
	regs_buff[34] = rd32(XSCT_IMC);
	regs_buff[35] = rd32(XSCT_IG);
	regs_buff[36] = rd32(XSCT_ICTL);
}

__attribute__((used)) static int fjes_set_dump(struct net_device *netdev, struct ethtool_dump *dump)
{
	struct fjes_adapter *adapter = netdev_priv(netdev);
	struct fjes_hw *hw = &adapter->hw;
	int ret = 0;

	if (dump->flag) {
		if (hw->debug_mode)
			return -EPERM;

		hw->debug_mode = dump->flag;

		/* enable debug mode */
		mutex_lock(&hw->hw_info.lock);
		ret = fjes_hw_start_debug(hw);
		mutex_unlock(&hw->hw_info.lock);

		if (ret)
			hw->debug_mode = 0;
	} else {
		if (!hw->debug_mode)
			return -EPERM;

		/* disable debug mode */
		mutex_lock(&hw->hw_info.lock);
		ret = fjes_hw_stop_debug(hw);
		mutex_unlock(&hw->hw_info.lock);
	}

	return ret;
}

__attribute__((used)) static int fjes_get_dump_flag(struct net_device *netdev,
			      struct ethtool_dump *dump)
{
	struct fjes_adapter *adapter = netdev_priv(netdev);
	struct fjes_hw *hw = &adapter->hw;

	dump->len = hw->hw_info.trace_size;
	dump->version = 1;
	dump->flag = hw->debug_mode;

	return 0;
}

__attribute__((used)) static int fjes_get_dump_data(struct net_device *netdev,
			      struct ethtool_dump *dump, void *buf)
{
	struct fjes_adapter *adapter = netdev_priv(netdev);
	struct fjes_hw *hw = &adapter->hw;
	int ret = 0;

	if (hw->hw_info.trace)
		memcpy(buf, hw->hw_info.trace, hw->hw_info.trace_size);
	else
		ret = -EPERM;

	return ret;
}

void fjes_set_ethtool_ops(struct net_device *netdev)
{
	netdev->ethtool_ops = &fjes_ethtool_ops;
}

