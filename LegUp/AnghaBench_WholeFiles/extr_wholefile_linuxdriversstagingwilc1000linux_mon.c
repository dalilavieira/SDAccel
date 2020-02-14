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
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_2__ {void* it_present; void* it_len; scalar_t__ it_version; } ;
struct wilc_wfi_radiotap_hdr {int rate; int tx_flags; TYPE_1__ hdr; } ;
struct wilc_wfi_radiotap_cb_hdr {int rate; int tx_flags; TYPE_1__ hdr; } ;
struct wilc_wfi_mon_priv {struct net_device* real_ndev; } ;
struct tx_complete_mon_data {size_t size; struct tx_complete_mon_data* buff; } ;
struct sk_buff {int* data; int len; struct net_device* dev; struct wilc_wfi_radiotap_hdr* cb; void* protocol; void* pkt_type; void* ip_summed; } ;
struct net_device {int /*<<< orphan*/ * netdev_ops; scalar_t__* name; int /*<<< orphan*/  type; } ;
typedef  int netdev_tx_t ;

/* Variables and functions */
 int /*<<< orphan*/  ARPHRD_IEEE80211_RADIOTAP ; 
 void* CHECKSUM_UNNECESSARY ; 
 int EFAULT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETH_P_802_2 ; 
 int GET_PKT_OFFSET (int) ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int HOST_HDR_OFFSET ; 
 int IEEE80211_RADIOTAP_F_TX_FAIL ; 
 int IEEE80211_RADIOTAP_F_TX_RTS ; 
 int IEEE80211_RADIOTAP_RATE ; 
 int IFNAMSIZ ; 
 int IS_MANAGMEMENT_CALLBACK ; 
 int IS_MGMT_STATUS_SUCCES ; 
 void* PACKET_OTHERHOST ; 
 int TX_RADIOTAP_PRESENT ; 
 struct net_device* alloc_etherdev (int) ; 
 int* bssid ; 
 void* cpu_to_le16 (int) ; 
 void* cpu_to_le32 (int) ; 
 struct sk_buff* dev_alloc_skb (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_kfree_skb (struct sk_buff*) ; 
 void* htons (int /*<<< orphan*/ ) ; 
 int ieee80211_get_radiotap_len (int*) ; 
 scalar_t__ is_broadcast_ether_addr (int*) ; 
 int /*<<< orphan*/  kfree (struct tx_complete_mon_data*) ; 
 struct tx_complete_mon_data* kmalloc (int,int /*<<< orphan*/ ) ; 
 struct tx_complete_mon_data* kmemdup (int const*,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32_to_cpus (int*) ; 
 int /*<<< orphan*/  memcmp (int*,int*,int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (struct wilc_wfi_radiotap_hdr*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*) ; 
 struct wilc_wfi_mon_priv* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_running (struct net_device*) ; 
 int /*<<< orphan*/  netif_rx (struct sk_buff*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_wake_queue (struct net_device*) ; 
 scalar_t__ register_netdevice (struct net_device*) ; 
 scalar_t__ rtnl_is_locked () ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 int /*<<< orphan*/  skb_pull (struct sk_buff*,int) ; 
 struct wilc_wfi_radiotap_hdr* skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_put_data (struct sk_buff*,int*,int) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int* srcadd ; 
 int /*<<< orphan*/  strncpy (scalar_t__*,char const*,int) ; 
 int /*<<< orphan*/  unregister_netdev (struct net_device*) ; 
 int wilc_mac_xmit (struct sk_buff*,struct net_device*) ; 
 struct net_device* wilc_wfi_mon ; 
 int /*<<< orphan*/  wilc_wfi_netdev_ops ; 
 int /*<<< orphan*/  wilc_wlan_txq_add_mgmt_pkt (struct net_device*,struct tx_complete_mon_data*,struct tx_complete_mon_data*,size_t,void (*) (void*,int)) ; 

void wilc_wfi_monitor_rx(u8 *buff, u32 size)
{
	u32 header, pkt_offset;
	struct sk_buff *skb = NULL;
	struct wilc_wfi_radiotap_hdr *hdr;
	struct wilc_wfi_radiotap_cb_hdr *cb_hdr;

	if (!wilc_wfi_mon)
		return;

	if (!netif_running(wilc_wfi_mon))
		return;

	/* Get WILC header */
	memcpy(&header, (buff - HOST_HDR_OFFSET), HOST_HDR_OFFSET);
	le32_to_cpus(&header);
	/*
	 * The packet offset field contain info about what type of management
	 * the frame we are dealing with and ack status
	 */
	pkt_offset = GET_PKT_OFFSET(header);

	if (pkt_offset & IS_MANAGMEMENT_CALLBACK) {
		/* hostapd callback mgmt frame */

		skb = dev_alloc_skb(size + sizeof(*cb_hdr));
		if (!skb)
			return;

		skb_put_data(skb, buff, size);

		cb_hdr = skb_push(skb, sizeof(*cb_hdr));
		memset(cb_hdr, 0, sizeof(*cb_hdr));

		cb_hdr->hdr.it_version = 0; /* PKTHDR_RADIOTAP_VERSION; */

		cb_hdr->hdr.it_len = cpu_to_le16(sizeof(*cb_hdr));

		cb_hdr->hdr.it_present = cpu_to_le32(TX_RADIOTAP_PRESENT);

		cb_hdr->rate = 5;

		if (pkt_offset & IS_MGMT_STATUS_SUCCES)	{
			/* success */
			cb_hdr->tx_flags = IEEE80211_RADIOTAP_F_TX_RTS;
		} else {
			cb_hdr->tx_flags = IEEE80211_RADIOTAP_F_TX_FAIL;
		}

	} else {
		skb = dev_alloc_skb(size + sizeof(*hdr));

		if (!skb)
			return;

		skb_put_data(skb, buff, size);
		hdr = skb_push(skb, sizeof(*hdr));
		memset(hdr, 0, sizeof(struct wilc_wfi_radiotap_hdr));
		hdr->hdr.it_version = 0; /* PKTHDR_RADIOTAP_VERSION; */
		hdr->hdr.it_len = cpu_to_le16(sizeof(*hdr));
		hdr->hdr.it_present = cpu_to_le32
				(1 << IEEE80211_RADIOTAP_RATE);
		hdr->rate = 5;
	}

	skb->dev = wilc_wfi_mon;
	skb_reset_mac_header(skb);
	skb->ip_summed = CHECKSUM_UNNECESSARY;
	skb->pkt_type = PACKET_OTHERHOST;
	skb->protocol = htons(ETH_P_802_2);
	memset(skb->cb, 0, sizeof(skb->cb));

	netif_rx(skb);
}

__attribute__((used)) static void mgmt_tx_complete(void *priv, int status)
{
	struct tx_complete_mon_data *pv_data = priv;
	/*
	 * in case of fully hosting mode, the freeing will be done
	 * in response to the cfg packet
	 */
	kfree(pv_data->buff);

	kfree(pv_data);
}

__attribute__((used)) static int mon_mgmt_tx(struct net_device *dev, const u8 *buf, size_t len)
{
	struct tx_complete_mon_data *mgmt_tx = NULL;

	if (!dev)
		return -EFAULT;

	netif_stop_queue(dev);
	mgmt_tx = kmalloc(sizeof(*mgmt_tx), GFP_ATOMIC);
	if (!mgmt_tx)
		return -ENOMEM;

	mgmt_tx->buff = kmemdup(buf, len, GFP_ATOMIC);
	if (!mgmt_tx->buff) {
		kfree(mgmt_tx);
		return -ENOMEM;
	}

	mgmt_tx->size = len;

	wilc_wlan_txq_add_mgmt_pkt(dev, mgmt_tx, mgmt_tx->buff, mgmt_tx->size,
				   mgmt_tx_complete);

	netif_wake_queue(dev);
	return 0;
}

__attribute__((used)) static netdev_tx_t wilc_wfi_mon_xmit(struct sk_buff *skb,
				     struct net_device *dev)
{
	u32 rtap_len, ret = 0;
	struct wilc_wfi_mon_priv  *mon_priv;
	struct sk_buff *skb2;
	struct wilc_wfi_radiotap_cb_hdr *cb_hdr;

	if (!wilc_wfi_mon)
		return -EFAULT;

	mon_priv = netdev_priv(wilc_wfi_mon);
	if (!mon_priv)
		return -EFAULT;
	rtap_len = ieee80211_get_radiotap_len(skb->data);
	if (skb->len < rtap_len)
		return -1;

	skb_pull(skb, rtap_len);

	if (skb->data[0] == 0xc0 && is_broadcast_ether_addr(&skb->data[4])) {
		skb2 = dev_alloc_skb(skb->len + sizeof(*cb_hdr));
		if (!skb2)
			return -ENOMEM;

		skb_put_data(skb2, skb->data, skb->len);

		cb_hdr = skb_push(skb2, sizeof(*cb_hdr));
		memset(cb_hdr, 0, sizeof(struct wilc_wfi_radiotap_cb_hdr));

		cb_hdr->hdr.it_version = 0; /* PKTHDR_RADIOTAP_VERSION; */

		cb_hdr->hdr.it_len = cpu_to_le16(sizeof(*cb_hdr));

		cb_hdr->hdr.it_present = cpu_to_le32(TX_RADIOTAP_PRESENT);

		cb_hdr->rate = 5;
		cb_hdr->tx_flags = 0x0004;

		skb2->dev = wilc_wfi_mon;
		skb_reset_mac_header(skb2);
		skb2->ip_summed = CHECKSUM_UNNECESSARY;
		skb2->pkt_type = PACKET_OTHERHOST;
		skb2->protocol = htons(ETH_P_802_2);
		memset(skb2->cb, 0, sizeof(skb2->cb));

		netif_rx(skb2);

		return 0;
	}
	skb->dev = mon_priv->real_ndev;

	memcpy(srcadd, &skb->data[10], 6);
	memcpy(bssid, &skb->data[16], 6);
	/*
	 * Identify if data or mgmt packet, if source address and bssid
	 * fields are equal send it to mgmt frames handler
	 */
	if (!(memcmp(srcadd, bssid, 6))) {
		ret = mon_mgmt_tx(mon_priv->real_ndev, skb->data, skb->len);
		if (ret)
			netdev_err(dev, "fail to mgmt tx\n");
		dev_kfree_skb(skb);
	} else {
		ret = wilc_mac_xmit(skb, mon_priv->real_ndev);
	}

	return ret;
}

struct net_device *wilc_wfi_init_mon_interface(const char *name,
					       struct net_device *real_dev)
{
	struct wilc_wfi_mon_priv *priv;

	/*If monitor interface is already initialized, return it*/
	if (wilc_wfi_mon)
		return wilc_wfi_mon;

	wilc_wfi_mon = alloc_etherdev(sizeof(struct wilc_wfi_mon_priv));
	if (!wilc_wfi_mon)
		return NULL;
	wilc_wfi_mon->type = ARPHRD_IEEE80211_RADIOTAP;
	strncpy(wilc_wfi_mon->name, name, IFNAMSIZ);
	wilc_wfi_mon->name[IFNAMSIZ - 1] = 0;
	wilc_wfi_mon->netdev_ops = &wilc_wfi_netdev_ops;

	if (register_netdevice(wilc_wfi_mon)) {
		netdev_err(real_dev, "register_netdevice failed\n");
		return NULL;
	}
	priv = netdev_priv(wilc_wfi_mon);
	if (!priv)
		return NULL;

	priv->real_ndev = real_dev;

	return wilc_wfi_mon;
}

int wilc_wfi_deinit_mon_interface(void)
{
	bool rollback_lock = false;

	if (wilc_wfi_mon) {
		if (rtnl_is_locked()) {
			rtnl_unlock();
			rollback_lock = true;
		}
		unregister_netdev(wilc_wfi_mon);

		if (rollback_lock) {
			rtnl_lock();
			rollback_lock = false;
		}
		wilc_wfi_mon = NULL;
	}
	return 0;
}

