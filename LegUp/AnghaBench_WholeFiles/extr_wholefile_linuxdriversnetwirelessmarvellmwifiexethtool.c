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
typedef  size_t u32 ;
typedef  int u16 ;
struct sk_buff {int /*<<< orphan*/  data; scalar_t__ cb; } ;
struct TYPE_10__ {int start_port; int pkt_cnt; int ports; int* len_arr; int /*<<< orphan*/ ** skb_arr; int /*<<< orphan*/  buf_len; } ;
struct TYPE_9__ {int start_port; } ;
struct sdio_mmc_card {int curr_rd_port; int mp_end_port; int mp_agg_pkt_limit; int max_ports; int curr_wr_port; TYPE_4__ mpa_rx; scalar_t__ supports_sdio_new_mode; TYPE_3__ mpa_tx; } ;
struct TYPE_7__ {struct mwifiex_pcie_card_reg* reg; } ;
struct pcie_service_card {size_t txbd_wrptr; int txbd_rdptr; TYPE_2__* dev; TYPE_1__ pcie; } ;
struct net_device {int dummy; } ;
struct mwifiex_txinfo {int dummy; } ;
struct mwifiex_rxinfo {int dummy; } ;
struct mwifiex_private {scalar_t__ bss_mode; int bss_type; int bss_num; int csa_chan; TYPE_6__* adapter; scalar_t__ media_connected; scalar_t__ bss_started; scalar_t__ csa_expire_time; } ;
struct mwifiex_pcie_card_reg {size_t tx_mask; size_t tx_rollover_ind; } ;
struct mwifiex_dma_mapping {int /*<<< orphan*/  addr; } ;
struct mwifiex_cb {struct mwifiex_dma_mapping dma_mapping; struct mwifiex_txinfo tx_info; struct mwifiex_rxinfo rx_info; } ;
struct mwifiex_adapter {int priv_num; scalar_t__ irq_wakeup; int wake_by_wifi; struct mwifiex_private** priv; } ;
struct ethtool_wolinfo {int supported; int wolopts; } ;
typedef  int /*<<< orphan*/  index ;
typedef  enum mwifiex_bss_role { ____Placeholder_mwifiex_bss_role } mwifiex_bss_role ;
typedef  int /*<<< orphan*/  dma_addr_t ;
typedef  int /*<<< orphan*/  __le16 ;
struct TYPE_11__ {int /*<<< orphan*/  conditions; } ;
struct TYPE_12__ {int priv_num; TYPE_5__ hs_cfg; struct mwifiex_private** priv; } ;
struct TYPE_8__ {int device; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUILD_BUG_ON (int) ; 
 int EOPNOTSUPP ; 
 scalar_t__ GET_BSS_ROLE (struct mwifiex_private*) ; 
 size_t HS_CFG_COND_BROADCAST_DATA ; 
 size_t HS_CFG_COND_DEF ; 
 size_t HS_CFG_COND_MAC_EVENT ; 
 size_t HS_CFG_COND_MULTICAST_DATA ; 
 size_t HS_CFG_COND_UNICAST_DATA ; 
 int MWIFIEX_BSS_ROLE_ANY ; 
 scalar_t__ MWIFIEX_BSS_ROLE_STA ; 
 scalar_t__ MWIFIEX_BSS_ROLE_UAP ; 
 int MWIFIEX_MAX_BSS_NUM ; 
 size_t MWIFIEX_SUPPORTED_RATES ; 
 scalar_t__ NL80211_IFTYPE_P2P_CLIENT ; 
 scalar_t__ NL80211_IFTYPE_STATION ; 
 scalar_t__ NL80211_IFTYPE_UNSPECIFIED ; 
#define  PCIE_DEVICE_ID_MARVELL_88W8766P 134 
#define  PCIE_DEVICE_ID_MARVELL_88W8897 133 
#define  PCIE_DEVICE_ID_MARVELL_88W8997 132 
 scalar_t__ PKT_TYPE_MGMT ; 
#define  TDLS_CHAN_SWITCHING 131 
#define  TDLS_IN_BASE_CHAN 130 
#define  TDLS_IN_OFF_CHAN 129 
#define  TDLS_SETUP_COMPLETE 128 
 int WAKE_BCAST ; 
 int WAKE_MCAST ; 
 int WAKE_PHY ; 
 int WAKE_UCAST ; 
 int /*<<< orphan*/  cpu_to_le32 (size_t) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  disable_irq (scalar_t__) ; 
 int /*<<< orphan*/  disable_irq_wake (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq (scalar_t__) ; 
 int /*<<< orphan*/  enable_irq_wake (scalar_t__) ; 
 int get_unaligned_le16 (int /*<<< orphan*/ *) ; 
 scalar_t__ get_unaligned_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  jiffies ; 
 size_t le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct mwifiex_dma_mapping*,struct mwifiex_dma_mapping*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  put_unaligned_le16 (int,int /*<<< orphan*/ *) ; 
 scalar_t__ time_after (int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static inline struct mwifiex_rxinfo *MWIFIEX_SKB_RXCB(struct sk_buff *skb)
{
	struct mwifiex_cb *cb = (struct mwifiex_cb *)skb->cb;

	BUILD_BUG_ON(sizeof(struct mwifiex_cb) > sizeof(skb->cb));
	return &cb->rx_info;
}

__attribute__((used)) static inline struct mwifiex_txinfo *MWIFIEX_SKB_TXCB(struct sk_buff *skb)
{
	struct mwifiex_cb *cb = (struct mwifiex_cb *)skb->cb;

	return &cb->tx_info;
}

__attribute__((used)) static inline void mwifiex_store_mapping(struct sk_buff *skb,
					 struct mwifiex_dma_mapping *mapping)
{
	struct mwifiex_cb *cb = (struct mwifiex_cb *)skb->cb;

	memcpy(&cb->dma_mapping, mapping, sizeof(*mapping));
}

__attribute__((used)) static inline void mwifiex_get_mapping(struct sk_buff *skb,
				       struct mwifiex_dma_mapping *mapping)
{
	struct mwifiex_cb *cb = (struct mwifiex_cb *)skb->cb;

	memcpy(mapping, &cb->dma_mapping, sizeof(*mapping));
}

__attribute__((used)) static inline dma_addr_t MWIFIEX_SKB_DMA_ADDR(struct sk_buff *skb)
{
	struct mwifiex_dma_mapping mapping;

	mwifiex_get_mapping(skb, &mapping);

	return mapping.addr;
}

__attribute__((used)) static inline void le16_unaligned_add_cpu(__le16 *var, u16 val)
{
	put_unaligned_le16(get_unaligned_le16(var) + val, var);
}

__attribute__((used)) static inline int
mwifiex_pcie_txbd_empty(struct pcie_service_card *card, u32 rdptr)
{
	const struct mwifiex_pcie_card_reg *reg = card->pcie.reg;

	switch (card->dev->device) {
	case PCIE_DEVICE_ID_MARVELL_88W8766P:
		if (((card->txbd_wrptr & reg->tx_mask) ==
		     (rdptr & reg->tx_mask)) &&
		    ((card->txbd_wrptr & reg->tx_rollover_ind) !=
		     (rdptr & reg->tx_rollover_ind)))
			return 1;
		break;
	case PCIE_DEVICE_ID_MARVELL_88W8897:
	case PCIE_DEVICE_ID_MARVELL_88W8997:
		if (((card->txbd_wrptr & reg->tx_mask) ==
		     (rdptr & reg->tx_mask)) &&
		    ((card->txbd_wrptr & reg->tx_rollover_ind) ==
			(rdptr & reg->tx_rollover_ind)))
			return 1;
		break;
	}

	return 0;
}

__attribute__((used)) static inline int
mwifiex_pcie_txbd_not_full(struct pcie_service_card *card)
{
	const struct mwifiex_pcie_card_reg *reg = card->pcie.reg;

	switch (card->dev->device) {
	case PCIE_DEVICE_ID_MARVELL_88W8766P:
		if (((card->txbd_wrptr & reg->tx_mask) !=
		     (card->txbd_rdptr & reg->tx_mask)) ||
		    ((card->txbd_wrptr & reg->tx_rollover_ind) !=
		     (card->txbd_rdptr & reg->tx_rollover_ind)))
			return 1;
		break;
	case PCIE_DEVICE_ID_MARVELL_88W8897:
	case PCIE_DEVICE_ID_MARVELL_88W8997:
		if (((card->txbd_wrptr & reg->tx_mask) !=
		     (card->txbd_rdptr & reg->tx_mask)) ||
		    ((card->txbd_wrptr & reg->tx_rollover_ind) ==
		     (card->txbd_rdptr & reg->tx_rollover_ind)))
			return 1;
		break;
	}

	return 0;
}

__attribute__((used)) static inline int mwifiex_sdio_cmdrsp_complete(struct mwifiex_adapter *adapter,
					       struct sk_buff *skb)
{
	dev_kfree_skb_any(skb);
	return 0;
}

__attribute__((used)) static inline int mwifiex_sdio_event_complete(struct mwifiex_adapter *adapter,
					      struct sk_buff *skb)
{
	dev_kfree_skb_any(skb);
	return 0;
}

__attribute__((used)) static inline bool
mp_rx_aggr_port_limit_reached(struct sdio_mmc_card *card)
{
	u8 tmp;

	if (card->curr_rd_port < card->mpa_rx.start_port) {
		if (card->supports_sdio_new_mode)
			tmp = card->mp_end_port >> 1;
		else
			tmp = card->mp_agg_pkt_limit;

		if (((card->max_ports - card->mpa_rx.start_port) +
		    card->curr_rd_port) >= tmp)
			return true;
	}

	if (!card->supports_sdio_new_mode)
		return false;

	if ((card->curr_rd_port - card->mpa_rx.start_port) >=
	    (card->mp_end_port >> 1))
		return true;

	return false;
}

__attribute__((used)) static inline bool
mp_tx_aggr_port_limit_reached(struct sdio_mmc_card *card)
{
	u16 tmp;

	if (card->curr_wr_port < card->mpa_tx.start_port) {
		if (card->supports_sdio_new_mode)
			tmp = card->mp_end_port >> 1;
		else
			tmp = card->mp_agg_pkt_limit;

		if (((card->max_ports - card->mpa_tx.start_port) +
		    card->curr_wr_port) >= tmp)
			return true;
	}

	if (!card->supports_sdio_new_mode)
		return false;

	if ((card->curr_wr_port - card->mpa_tx.start_port) >=
	    (card->mp_end_port >> 1))
		return true;

	return false;
}

__attribute__((used)) static inline void mp_rx_aggr_setup(struct sdio_mmc_card *card,
				    u16 rx_len, u8 port)
{
	card->mpa_rx.buf_len += rx_len;

	if (!card->mpa_rx.pkt_cnt)
		card->mpa_rx.start_port = port;

	if (card->supports_sdio_new_mode) {
		card->mpa_rx.ports |= (1 << port);
	} else {
		if (card->mpa_rx.start_port <= port)
			card->mpa_rx.ports |= 1 << (card->mpa_rx.pkt_cnt);
		else
			card->mpa_rx.ports |= 1 << (card->mpa_rx.pkt_cnt + 1);
	}
	card->mpa_rx.skb_arr[card->mpa_rx.pkt_cnt] = NULL;
	card->mpa_rx.len_arr[card->mpa_rx.pkt_cnt] = rx_len;
	card->mpa_rx.pkt_cnt++;
}

__attribute__((used)) static inline u8
mwifiex_queuing_ra_based(struct mwifiex_private *priv)
{
	/*
	 * Currently we assume if we are in Infra, then DA=RA. This might not be
	 * true in the future
	 */
	if ((priv->bss_mode == NL80211_IFTYPE_STATION ||
	     priv->bss_mode == NL80211_IFTYPE_P2P_CLIENT) &&
	    (GET_BSS_ROLE(priv) == MWIFIEX_BSS_ROLE_STA))
		return false;

	return true;
}

__attribute__((used)) static inline u32
mwifiex_copy_rates(u8 *dest, u32 pos, u8 *src, int len)
{
	int i;

	for (i = 0; i < len && src[i]; i++, pos++) {
		if (pos >= MWIFIEX_SUPPORTED_RATES)
			break;
		dest[pos] = src[i];
	}

	return pos;
}

__attribute__((used)) static inline u8
mwifiex_get_intf_num(struct mwifiex_adapter *adapter, u8 bss_type)
{
	u8 i, num = 0;

	for (i = 0; i < adapter->priv_num; i++)
		if (adapter->priv[i] && adapter->priv[i]->bss_type == bss_type)
			num++;
	return num;
}

__attribute__((used)) static inline struct mwifiex_private *
mwifiex_get_priv_by_id(struct mwifiex_adapter *adapter,
		       u8 bss_num, u8 bss_type)
{
	int i;

	for (i = 0; i < adapter->priv_num; i++) {
		if (adapter->priv[i]) {
			if ((adapter->priv[i]->bss_num == bss_num) &&
			    (adapter->priv[i]->bss_type == bss_type))
				break;
		}
	}
	return ((i < adapter->priv_num) ? adapter->priv[i] : NULL);
}

__attribute__((used)) static inline struct mwifiex_private *
mwifiex_get_priv(struct mwifiex_adapter *adapter,
		 enum mwifiex_bss_role bss_role)
{
	int i;

	for (i = 0; i < adapter->priv_num; i++) {
		if (adapter->priv[i]) {
			if (bss_role == MWIFIEX_BSS_ROLE_ANY ||
			    GET_BSS_ROLE(adapter->priv[i]) == bss_role)
				break;
		}
	}

	return ((i < adapter->priv_num) ? adapter->priv[i] : NULL);
}

__attribute__((used)) static inline u8
mwifiex_get_unused_bss_num(struct mwifiex_adapter *adapter, u8 bss_type)
{
	u8 i, j;
	int index[MWIFIEX_MAX_BSS_NUM];

	memset(index, 0, sizeof(index));
	for (i = 0; i < adapter->priv_num; i++)
		if (adapter->priv[i]) {
			if (adapter->priv[i]->bss_type == bss_type &&
			    !(adapter->priv[i]->bss_mode ==
			      NL80211_IFTYPE_UNSPECIFIED)) {
				index[adapter->priv[i]->bss_num] = 1;
			}
		}
	for (j = 0; j < MWIFIEX_MAX_BSS_NUM; j++)
		if (!index[j])
			return j;
	return -1;
}

__attribute__((used)) static inline struct mwifiex_private *
mwifiex_get_unused_priv_by_bss_type(struct mwifiex_adapter *adapter,
				    u8 bss_type)
{
	u8 i;

	for (i = 0; i < adapter->priv_num; i++)
		if (adapter->priv[i]->bss_mode ==
		   NL80211_IFTYPE_UNSPECIFIED) {
			adapter->priv[i]->bss_num =
			mwifiex_get_unused_bss_num(adapter, bss_type);
			break;
		}

	return ((i < adapter->priv_num) ? adapter->priv[i] : NULL);
}

__attribute__((used)) static inline struct mwifiex_private *
mwifiex_netdev_get_priv(struct net_device *dev)
{
	return (struct mwifiex_private *) (*(unsigned long *) netdev_priv(dev));
}

__attribute__((used)) static inline bool mwifiex_is_skb_mgmt_frame(struct sk_buff *skb)
{
	return (get_unaligned_le32(skb->data) == PKT_TYPE_MGMT);
}

__attribute__((used)) static inline u8
mwifiex_11h_get_csa_closed_channel(struct mwifiex_private *priv)
{
	if (!priv->csa_chan)
		return 0;

	/* Clear csa channel, if DFS channel move time has passed */
	if (time_after(jiffies, priv->csa_expire_time)) {
		priv->csa_chan = 0;
		priv->csa_expire_time = 0;
	}

	return priv->csa_chan;
}

__attribute__((used)) static inline u8 mwifiex_is_any_intf_active(struct mwifiex_private *priv)
{
	struct mwifiex_private *priv_num;
	int i;

	for (i = 0; i < priv->adapter->priv_num; i++) {
		priv_num = priv->adapter->priv[i];
		if (priv_num) {
			if ((GET_BSS_ROLE(priv_num) == MWIFIEX_BSS_ROLE_UAP &&
			     priv_num->bss_started) ||
			    (GET_BSS_ROLE(priv_num) == MWIFIEX_BSS_ROLE_STA &&
			     priv_num->media_connected))
				return 1;
		}
	}

	return 0;
}

__attribute__((used)) static inline u8 mwifiex_is_tdls_link_setup(u8 status)
{
	switch (status) {
	case TDLS_SETUP_COMPLETE:
	case TDLS_CHAN_SWITCHING:
	case TDLS_IN_BASE_CHAN:
	case TDLS_IN_OFF_CHAN:
		return true;
	default:
		break;
	}

	return false;
}

__attribute__((used)) static inline void mwifiex_disable_wake(struct mwifiex_adapter *adapter)
{
	if (adapter->irq_wakeup >= 0) {
		disable_irq_wake(adapter->irq_wakeup);
		disable_irq(adapter->irq_wakeup);
		if (adapter->wake_by_wifi)
			/* Undo our disable, since interrupt handler already
			 * did this.
			 */
			enable_irq(adapter->irq_wakeup);

	}
}

__attribute__((used)) static inline void mwifiex_enable_wake(struct mwifiex_adapter *adapter)
{
	/* Enable platform specific wakeup interrupt */
	if (adapter->irq_wakeup >= 0) {
		adapter->wake_by_wifi = false;
		enable_irq(adapter->irq_wakeup);
		enable_irq_wake(adapter->irq_wakeup);
	}
}

__attribute__((used)) static void mwifiex_ethtool_get_wol(struct net_device *dev,
				    struct ethtool_wolinfo *wol)
{
	struct mwifiex_private *priv = mwifiex_netdev_get_priv(dev);
	u32 conditions = le32_to_cpu(priv->adapter->hs_cfg.conditions);

	wol->supported = WAKE_UCAST|WAKE_MCAST|WAKE_BCAST|WAKE_PHY;

	if (conditions == HS_CFG_COND_DEF)
		return;

	if (conditions & HS_CFG_COND_UNICAST_DATA)
		wol->wolopts |= WAKE_UCAST;
	if (conditions & HS_CFG_COND_MULTICAST_DATA)
		wol->wolopts |= WAKE_MCAST;
	if (conditions & HS_CFG_COND_BROADCAST_DATA)
		wol->wolopts |= WAKE_BCAST;
	if (conditions & HS_CFG_COND_MAC_EVENT)
		wol->wolopts |= WAKE_PHY;
}

__attribute__((used)) static int mwifiex_ethtool_set_wol(struct net_device *dev,
				   struct ethtool_wolinfo *wol)
{
	struct mwifiex_private *priv = mwifiex_netdev_get_priv(dev);
	u32 conditions = 0;

	if (wol->wolopts & ~(WAKE_UCAST|WAKE_MCAST|WAKE_BCAST|WAKE_PHY))
		return -EOPNOTSUPP;

	if (wol->wolopts & WAKE_UCAST)
		conditions |= HS_CFG_COND_UNICAST_DATA;
	if (wol->wolopts & WAKE_MCAST)
		conditions |= HS_CFG_COND_MULTICAST_DATA;
	if (wol->wolopts & WAKE_BCAST)
		conditions |= HS_CFG_COND_BROADCAST_DATA;
	if (wol->wolopts & WAKE_PHY)
		conditions |= HS_CFG_COND_MAC_EVENT;
	if (wol->wolopts == 0)
		conditions |= HS_CFG_COND_DEF;
	priv->adapter->hs_cfg.conditions = cpu_to_le32(conditions);

	return 0;
}

