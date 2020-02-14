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
typedef  size_t u8 ;
typedef  unsigned long long u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct xge_stats {scalar_t__ rx_errors; scalar_t__ rx_bytes; scalar_t__ rx_packets; scalar_t__ tx_bytes; scalar_t__ tx_packets; } ;
struct xge_raw_desc {void* m0; void* m2; void* m1; } ;
struct TYPE_2__ {int phy_mode; int irq; int /*<<< orphan*/  base_addr; } ;
struct xge_pdata {struct net_device* ndev; int /*<<< orphan*/  napi; struct platform_device* pdev; struct xge_stats stats; struct xge_desc_ring* tx_ring; struct xge_desc_ring* rx_ring; TYPE_1__ resources; int /*<<< orphan*/  irq_name; int /*<<< orphan*/  nbufs; } ;
struct xge_desc_ring {size_t tail; int dma_addr; size_t head; void* desc_addr; void* pkt_buf; struct xge_desc_ring* pkt_info; struct sk_buff* skb; struct xge_raw_desc* raw_desc; struct net_device* ndev; } ;
struct sk_buff {int /*<<< orphan*/  protocol; scalar_t__ len; int /*<<< orphan*/  data; } ;
struct rtnl_link_stats64 {int /*<<< orphan*/  rx_errors; int /*<<< orphan*/  rx_bytes; int /*<<< orphan*/  rx_packets; int /*<<< orphan*/  tx_bytes; int /*<<< orphan*/  tx_packets; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; } ;
struct net_device {void* perm_addr; int addr_len; char* name; int features; int hw_features; int /*<<< orphan*/ * netdev_ops; int /*<<< orphan*/  phydev; int /*<<< orphan*/  dev_addr; } ;
struct napi_struct {struct net_device* dev; } ;
typedef  int /*<<< orphan*/  netdev_tx_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  D ; 
 int /*<<< orphan*/  DMARXCTRL ; 
 int /*<<< orphan*/  DMARXSTATUS ; 
 int /*<<< orphan*/  DMATXCTRL ; 
 int /*<<< orphan*/  DMATXSTATUS ; 
 int /*<<< orphan*/  DMA_BIT_MASK (int) ; 
 int /*<<< orphan*/  DMA_FROM_DEVICE ; 
 int /*<<< orphan*/  E ; 
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ETH_ALEN ; 
 int GENMASK (int,int) ; 
 int GET_BITS (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_ID_SIZE ; 
 int /*<<< orphan*/  NAPI_POLL_WEIGHT ; 
 int /*<<< orphan*/  NETDEV_TX_BUSY ; 
 int /*<<< orphan*/  NETDEV_TX_OK ; 
 int NETIF_F_GRO ; 
 int NETIF_F_GSO ; 
 int /*<<< orphan*/  NEXT_DESC_ADDRH ; 
 int /*<<< orphan*/  NEXT_DESC_ADDRL ; 
 int /*<<< orphan*/  NUM_BUFS ; 
 int PHY_INTERFACE_MODE_RGMII ; 
 int /*<<< orphan*/  PKT_ADDRH ; 
 int /*<<< orphan*/  PKT_ADDRL ; 
 int /*<<< orphan*/  PKT_SIZE ; 
 int /*<<< orphan*/  RXPKTCOUNT ; 
 int SET_BITS (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  SET_NETDEV_DEV (struct net_device*,struct device*) ; 
 int SLOT_EMPTY ; 
 int /*<<< orphan*/  TXPKTCOUNT ; 
 int XGENE_ENET_DESC_SIZE ; 
 int XGENE_ENET_NUM_DESC ; 
 int XGENE_ENET_STD_MTU ; 
 int /*<<< orphan*/  __napi_schedule (int /*<<< orphan*/ *) ; 
 struct net_device* alloc_etherdev (int) ; 
 void* cpu_to_le64 (int) ; 
 int /*<<< orphan*/  dev_close (struct net_device*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  device_get_mac_address (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int device_get_phy_mode (struct device*) ; 
 int /*<<< orphan*/  devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dma_coerce_mask_and_coherent (struct device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (struct device*,int,void*,int) ; 
 int dma_map_single (struct device*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ dma_mapping_error (struct device*,int) ; 
 int /*<<< orphan*/  dma_rmb () ; 
 int /*<<< orphan*/  dma_unmap_single (struct device*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_wmb () ; 
 void* dma_zalloc_coherent (struct device*,int,int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eth_hw_addr_random (struct net_device*) ; 
 int eth_mac_addr (struct net_device*,void*) ; 
 int /*<<< orphan*/  eth_type_trans (struct sk_buff*,struct net_device*) ; 
 int /*<<< orphan*/  free_irq (int,struct xge_pdata*) ; 
 int /*<<< orphan*/  free_netdev (struct net_device*) ; 
 struct xge_desc_ring* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct xge_desc_ring*) ; 
 struct xge_desc_ring* kzalloc (int,int /*<<< orphan*/ ) ; 
 int le64_to_cpu (void*) ; 
 int /*<<< orphan*/  memcpy (void*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  napi_complete_done (struct napi_struct*,int) ; 
 int /*<<< orphan*/  napi_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  napi_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  napi_gro_receive (int /*<<< orphan*/ *,struct sk_buff*) ; 
 scalar_t__ napi_schedule_prep (int /*<<< orphan*/ *) ; 
 struct sk_buff* netdev_alloc_skb (struct net_device*,int) ; 
 int /*<<< orphan*/  netdev_err (struct net_device*,char*,...) ; 
 struct xge_pdata* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  netif_napi_add (struct net_device*,int /*<<< orphan*/ *,int (*) (struct napi_struct*,int const),int /*<<< orphan*/ ) ; 
 scalar_t__ netif_queue_stopped (struct net_device*) ; 
 scalar_t__ netif_running (struct net_device*) ; 
 int /*<<< orphan*/  netif_start_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_stop_queue (struct net_device*) ; 
 int /*<<< orphan*/  netif_wake_queue (struct net_device*) ; 
 int /*<<< orphan*/  phy_start (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  phy_stop (int /*<<< orphan*/ ) ; 
 struct xge_pdata* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct xge_pdata*) ; 
 int register_netdev (struct net_device*) ; 
 int request_irq (int,int /*<<< orphan*/  (*) (int const,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct xge_pdata*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 int skb_headlen (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_tx_timestamp (struct sk_buff*) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,char*) ; 
 scalar_t__ unlikely (size_t) ; 
 int /*<<< orphan*/  unregister_netdev (struct net_device*) ; 
 int upper_32_bits (int) ; 
 int /*<<< orphan*/  xge_intr_disable (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_intr_enable (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_disable (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_enable (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_init (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_mac_set_station_addr (struct xge_pdata*) ; 
 int xge_mdio_config (struct net_device*) ; 
 int /*<<< orphan*/  xge_mdio_remove (struct net_device*) ; 
 int /*<<< orphan*/  xge_port_init (struct net_device*) ; 
 int xge_port_reset (struct net_device*) ; 
 int xge_rd_csr (struct xge_pdata*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xge_set_ethtool_ops (struct net_device*) ; 
 int /*<<< orphan*/  xge_setup_desc (struct xge_desc_ring*) ; 
 int /*<<< orphan*/  xge_update_rx_desc_addr (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_update_tx_desc_addr (struct xge_pdata*) ; 
 int /*<<< orphan*/  xge_wr_csr (struct xge_pdata*,int /*<<< orphan*/ ,unsigned int) ; 
 int /*<<< orphan*/  xgene_ndev_ops ; 

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

__attribute__((used)) static int xge_get_resources(struct xge_pdata *pdata)
{
	struct platform_device *pdev;
	struct net_device *ndev;
	int phy_mode, ret = 0;
	struct resource *res;
	struct device *dev;

	pdev = pdata->pdev;
	dev = &pdev->dev;
	ndev = pdata->ndev;

	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (!res) {
		dev_err(dev, "Resource enet_csr not defined\n");
		return -ENODEV;
	}

	pdata->resources.base_addr = devm_ioremap(dev, res->start,
						  resource_size(res));
	if (!pdata->resources.base_addr) {
		dev_err(dev, "Unable to retrieve ENET Port CSR region\n");
		return -ENOMEM;
	}

	if (!device_get_mac_address(dev, ndev->dev_addr, ETH_ALEN))
		eth_hw_addr_random(ndev);

	memcpy(ndev->perm_addr, ndev->dev_addr, ndev->addr_len);

	phy_mode = device_get_phy_mode(dev);
	if (phy_mode < 0) {
		dev_err(dev, "Unable to get phy-connection-type\n");
		return phy_mode;
	}
	pdata->resources.phy_mode = phy_mode;

	if (pdata->resources.phy_mode != PHY_INTERFACE_MODE_RGMII) {
		dev_err(dev, "Incorrect phy-connection-type specified\n");
		return -ENODEV;
	}

	ret = platform_get_irq(pdev, 0);
	if (ret < 0) {
		dev_err(dev, "Unable to get irq\n");
		return ret;
	}
	pdata->resources.irq = ret;

	return 0;
}

__attribute__((used)) static int xge_refill_buffers(struct net_device *ndev, u32 nbuf)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct xge_desc_ring *ring = pdata->rx_ring;
	const u8 slots = XGENE_ENET_NUM_DESC - 1;
	struct device *dev = &pdata->pdev->dev;
	struct xge_raw_desc *raw_desc;
	u64 addr_lo, addr_hi;
	u8 tail = ring->tail;
	struct sk_buff *skb;
	dma_addr_t dma_addr;
	u16 len;
	int i;

	for (i = 0; i < nbuf; i++) {
		raw_desc = &ring->raw_desc[tail];

		len = XGENE_ENET_STD_MTU;
		skb = netdev_alloc_skb(ndev, len);
		if (unlikely(!skb))
			return -ENOMEM;

		dma_addr = dma_map_single(dev, skb->data, len, DMA_FROM_DEVICE);
		if (dma_mapping_error(dev, dma_addr)) {
			netdev_err(ndev, "DMA mapping error\n");
			dev_kfree_skb_any(skb);
			return -EINVAL;
		}

		ring->pkt_info[tail].skb = skb;
		ring->pkt_info[tail].dma_addr = dma_addr;

		addr_hi = GET_BITS(NEXT_DESC_ADDRH, le64_to_cpu(raw_desc->m1));
		addr_lo = GET_BITS(NEXT_DESC_ADDRL, le64_to_cpu(raw_desc->m1));
		raw_desc->m1 = cpu_to_le64(SET_BITS(NEXT_DESC_ADDRL, addr_lo) |
					   SET_BITS(NEXT_DESC_ADDRH, addr_hi) |
					   SET_BITS(PKT_ADDRH,
						    upper_32_bits(dma_addr)));

		dma_wmb();
		raw_desc->m0 = cpu_to_le64(SET_BITS(PKT_ADDRL, dma_addr) |
					   SET_BITS(E, 1));
		tail = (tail + 1) & slots;
	}

	ring->tail = tail;

	return 0;
}

__attribute__((used)) static int xge_init_hw(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	int ret;

	ret = xge_port_reset(ndev);
	if (ret)
		return ret;

	xge_port_init(ndev);
	pdata->nbufs = NUM_BUFS;

	return 0;
}

__attribute__((used)) static irqreturn_t xge_irq(const int irq, void *data)
{
	struct xge_pdata *pdata = data;

	if (napi_schedule_prep(&pdata->napi)) {
		xge_intr_disable(pdata);
		__napi_schedule(&pdata->napi);
	}

	return IRQ_HANDLED;
}

__attribute__((used)) static int xge_request_irq(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	int ret;

	snprintf(pdata->irq_name, IRQ_ID_SIZE, "%s", ndev->name);

	ret = request_irq(pdata->resources.irq, xge_irq, 0, pdata->irq_name,
			  pdata);
	if (ret)
		netdev_err(ndev, "Failed to request irq %s\n", pdata->irq_name);

	return ret;
}

__attribute__((used)) static void xge_free_irq(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);

	free_irq(pdata->resources.irq, pdata);
}

__attribute__((used)) static bool is_tx_slot_available(struct xge_raw_desc *raw_desc)
{
	if (GET_BITS(E, le64_to_cpu(raw_desc->m0)) &&
	    (GET_BITS(PKT_SIZE, le64_to_cpu(raw_desc->m0)) == SLOT_EMPTY))
		return true;

	return false;
}

__attribute__((used)) static netdev_tx_t xge_start_xmit(struct sk_buff *skb, struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct device *dev = &pdata->pdev->dev;
	struct xge_desc_ring *tx_ring;
	struct xge_raw_desc *raw_desc;
	static dma_addr_t dma_addr;
	u64 addr_lo, addr_hi;
	void *pkt_buf;
	u8 tail;
	u16 len;

	tx_ring = pdata->tx_ring;
	tail = tx_ring->tail;
	len = skb_headlen(skb);
	raw_desc = &tx_ring->raw_desc[tail];

	if (!is_tx_slot_available(raw_desc)) {
		netif_stop_queue(ndev);
		return NETDEV_TX_BUSY;
	}

	/* Packet buffers should be 64B aligned */
	pkt_buf = dma_zalloc_coherent(dev, XGENE_ENET_STD_MTU, &dma_addr,
				      GFP_ATOMIC);
	if (unlikely(!pkt_buf)) {
		dev_kfree_skb_any(skb);
		return NETDEV_TX_OK;
	}
	memcpy(pkt_buf, skb->data, len);

	addr_hi = GET_BITS(NEXT_DESC_ADDRH, le64_to_cpu(raw_desc->m1));
	addr_lo = GET_BITS(NEXT_DESC_ADDRL, le64_to_cpu(raw_desc->m1));
	raw_desc->m1 = cpu_to_le64(SET_BITS(NEXT_DESC_ADDRL, addr_lo) |
				   SET_BITS(NEXT_DESC_ADDRH, addr_hi) |
				   SET_BITS(PKT_ADDRH,
					    upper_32_bits(dma_addr)));

	tx_ring->pkt_info[tail].skb = skb;
	tx_ring->pkt_info[tail].dma_addr = dma_addr;
	tx_ring->pkt_info[tail].pkt_buf = pkt_buf;

	dma_wmb();

	raw_desc->m0 = cpu_to_le64(SET_BITS(PKT_ADDRL, dma_addr) |
				   SET_BITS(PKT_SIZE, len) |
				   SET_BITS(E, 0));
	skb_tx_timestamp(skb);
	xge_wr_csr(pdata, DMATXCTRL, 1);

	tx_ring->tail = (tail + 1) & (XGENE_ENET_NUM_DESC - 1);

	return NETDEV_TX_OK;
}

__attribute__((used)) static bool is_tx_hw_done(struct xge_raw_desc *raw_desc)
{
	if (GET_BITS(E, le64_to_cpu(raw_desc->m0)) &&
	    !GET_BITS(PKT_SIZE, le64_to_cpu(raw_desc->m0)))
		return true;

	return false;
}

__attribute__((used)) static void xge_txc_poll(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct device *dev = &pdata->pdev->dev;
	struct xge_desc_ring *tx_ring;
	struct xge_raw_desc *raw_desc;
	dma_addr_t dma_addr;
	struct sk_buff *skb;
	void *pkt_buf;
	u32 data;
	u8 head;

	tx_ring = pdata->tx_ring;
	head = tx_ring->head;

	data = xge_rd_csr(pdata, DMATXSTATUS);
	if (!GET_BITS(TXPKTCOUNT, data))
		return;

	while (1) {
		raw_desc = &tx_ring->raw_desc[head];

		if (!is_tx_hw_done(raw_desc))
			break;

		dma_rmb();

		skb = tx_ring->pkt_info[head].skb;
		dma_addr = tx_ring->pkt_info[head].dma_addr;
		pkt_buf = tx_ring->pkt_info[head].pkt_buf;
		pdata->stats.tx_packets++;
		pdata->stats.tx_bytes += skb->len;
		dma_free_coherent(dev, XGENE_ENET_STD_MTU, pkt_buf, dma_addr);
		dev_kfree_skb_any(skb);

		/* clear pktstart address and pktsize */
		raw_desc->m0 = cpu_to_le64(SET_BITS(E, 1) |
					   SET_BITS(PKT_SIZE, SLOT_EMPTY));
		xge_wr_csr(pdata, DMATXSTATUS, 1);

		head = (head + 1) & (XGENE_ENET_NUM_DESC - 1);
	}

	if (netif_queue_stopped(ndev))
		netif_wake_queue(ndev);

	tx_ring->head = head;
}

__attribute__((used)) static int xge_rx_poll(struct net_device *ndev, unsigned int budget)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct device *dev = &pdata->pdev->dev;
	struct xge_desc_ring *rx_ring;
	struct xge_raw_desc *raw_desc;
	struct sk_buff *skb;
	dma_addr_t dma_addr;
	int processed = 0;
	u8 head, rx_error;
	int i, ret;
	u32 data;
	u16 len;

	rx_ring = pdata->rx_ring;
	head = rx_ring->head;

	data = xge_rd_csr(pdata, DMARXSTATUS);
	if (!GET_BITS(RXPKTCOUNT, data))
		return 0;

	for (i = 0; i < budget; i++) {
		raw_desc = &rx_ring->raw_desc[head];

		if (GET_BITS(E, le64_to_cpu(raw_desc->m0)))
			break;

		dma_rmb();

		skb = rx_ring->pkt_info[head].skb;
		rx_ring->pkt_info[head].skb = NULL;
		dma_addr = rx_ring->pkt_info[head].dma_addr;
		len = GET_BITS(PKT_SIZE, le64_to_cpu(raw_desc->m0));
		dma_unmap_single(dev, dma_addr, XGENE_ENET_STD_MTU,
				 DMA_FROM_DEVICE);

		rx_error = GET_BITS(D, le64_to_cpu(raw_desc->m2));
		if (unlikely(rx_error)) {
			pdata->stats.rx_errors++;
			dev_kfree_skb_any(skb);
			goto out;
		}

		skb_put(skb, len);
		skb->protocol = eth_type_trans(skb, ndev);

		pdata->stats.rx_packets++;
		pdata->stats.rx_bytes += len;
		napi_gro_receive(&pdata->napi, skb);
out:
		ret = xge_refill_buffers(ndev, 1);
		xge_wr_csr(pdata, DMARXSTATUS, 1);
		xge_wr_csr(pdata, DMARXCTRL, 1);

		if (ret)
			break;

		head = (head + 1) & (XGENE_ENET_NUM_DESC - 1);
		processed++;
	}

	rx_ring->head = head;

	return processed;
}

__attribute__((used)) static void xge_delete_desc_ring(struct net_device *ndev,
				 struct xge_desc_ring *ring)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct device *dev = &pdata->pdev->dev;
	u16 size;

	if (!ring)
		return;

	size = XGENE_ENET_DESC_SIZE * XGENE_ENET_NUM_DESC;
	if (ring->desc_addr)
		dma_free_coherent(dev, size, ring->desc_addr, ring->dma_addr);

	kfree(ring->pkt_info);
	kfree(ring);
}

__attribute__((used)) static void xge_free_buffers(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct xge_desc_ring *ring = pdata->rx_ring;
	struct device *dev = &pdata->pdev->dev;
	struct sk_buff *skb;
	dma_addr_t dma_addr;
	int i;

	for (i = 0; i < XGENE_ENET_NUM_DESC; i++) {
		skb = ring->pkt_info[i].skb;
		dma_addr = ring->pkt_info[i].dma_addr;

		if (!skb)
			continue;

		dma_unmap_single(dev, dma_addr, XGENE_ENET_STD_MTU,
				 DMA_FROM_DEVICE);
		dev_kfree_skb_any(skb);
	}
}

__attribute__((used)) static void xge_delete_desc_rings(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);

	xge_txc_poll(ndev);
	xge_delete_desc_ring(ndev, pdata->tx_ring);

	xge_rx_poll(ndev, 64);
	xge_free_buffers(ndev);
	xge_delete_desc_ring(ndev, pdata->rx_ring);
}

__attribute__((used)) static struct xge_desc_ring *xge_create_desc_ring(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct device *dev = &pdata->pdev->dev;
	struct xge_desc_ring *ring;
	u16 size;

	ring = kzalloc(sizeof(*ring), GFP_KERNEL);
	if (!ring)
		return NULL;

	ring->ndev = ndev;

	size = XGENE_ENET_DESC_SIZE * XGENE_ENET_NUM_DESC;
	ring->desc_addr = dma_zalloc_coherent(dev, size, &ring->dma_addr,
					      GFP_KERNEL);
	if (!ring->desc_addr)
		goto err;

	ring->pkt_info = kcalloc(XGENE_ENET_NUM_DESC, sizeof(*ring->pkt_info),
				 GFP_KERNEL);
	if (!ring->pkt_info)
		goto err;

	xge_setup_desc(ring);

	return ring;

err:
	xge_delete_desc_ring(ndev, ring);

	return NULL;
}

__attribute__((used)) static int xge_create_desc_rings(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct xge_desc_ring *ring;
	int ret;

	/* create tx ring */
	ring = xge_create_desc_ring(ndev);
	if (!ring)
		goto err;

	pdata->tx_ring = ring;
	xge_update_tx_desc_addr(pdata);

	/* create rx ring */
	ring = xge_create_desc_ring(ndev);
	if (!ring)
		goto err;

	pdata->rx_ring = ring;
	xge_update_rx_desc_addr(pdata);

	ret = xge_refill_buffers(ndev, XGENE_ENET_NUM_DESC);
	if (ret)
		goto err;

	return 0;
err:
	xge_delete_desc_rings(ndev);

	return -ENOMEM;
}

__attribute__((used)) static int xge_open(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	int ret;

	ret = xge_create_desc_rings(ndev);
	if (ret)
		return ret;

	napi_enable(&pdata->napi);
	ret = xge_request_irq(ndev);
	if (ret)
		return ret;

	xge_intr_enable(pdata);
	xge_wr_csr(pdata, DMARXCTRL, 1);

	phy_start(ndev->phydev);
	xge_mac_enable(pdata);
	netif_start_queue(ndev);

	return 0;
}

__attribute__((used)) static int xge_close(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);

	netif_stop_queue(ndev);
	xge_mac_disable(pdata);
	phy_stop(ndev->phydev);

	xge_intr_disable(pdata);
	xge_free_irq(ndev);
	napi_disable(&pdata->napi);
	xge_delete_desc_rings(ndev);

	return 0;
}

__attribute__((used)) static int xge_napi(struct napi_struct *napi, const int budget)
{
	struct net_device *ndev = napi->dev;
	struct xge_pdata *pdata;
	int processed;

	pdata = netdev_priv(ndev);

	xge_txc_poll(ndev);
	processed = xge_rx_poll(ndev, budget);

	if (processed < budget) {
		napi_complete_done(napi, processed);
		xge_intr_enable(pdata);
	}

	return processed;
}

__attribute__((used)) static int xge_set_mac_addr(struct net_device *ndev, void *addr)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	int ret;

	ret = eth_mac_addr(ndev, addr);
	if (ret)
		return ret;

	xge_mac_set_station_addr(pdata);

	return 0;
}

__attribute__((used)) static bool is_tx_pending(struct xge_raw_desc *raw_desc)
{
	if (!GET_BITS(E, le64_to_cpu(raw_desc->m0)))
		return true;

	return false;
}

__attribute__((used)) static void xge_free_pending_skb(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct device *dev = &pdata->pdev->dev;
	struct xge_desc_ring *tx_ring;
	struct xge_raw_desc *raw_desc;
	dma_addr_t dma_addr;
	struct sk_buff *skb;
	void *pkt_buf;
	int i;

	tx_ring = pdata->tx_ring;

	for (i = 0; i < XGENE_ENET_NUM_DESC; i++) {
		raw_desc = &tx_ring->raw_desc[i];

		if (!is_tx_pending(raw_desc))
			continue;

		skb = tx_ring->pkt_info[i].skb;
		dma_addr = tx_ring->pkt_info[i].dma_addr;
		pkt_buf = tx_ring->pkt_info[i].pkt_buf;
		dma_free_coherent(dev, XGENE_ENET_STD_MTU, pkt_buf, dma_addr);
		dev_kfree_skb_any(skb);
	}
}

__attribute__((used)) static void xge_timeout(struct net_device *ndev)
{
	struct xge_pdata *pdata = netdev_priv(ndev);

	rtnl_lock();

	if (!netif_running(ndev))
		goto out;

	netif_stop_queue(ndev);
	xge_intr_disable(pdata);
	napi_disable(&pdata->napi);

	xge_wr_csr(pdata, DMATXCTRL, 0);
	xge_txc_poll(ndev);
	xge_free_pending_skb(ndev);
	xge_wr_csr(pdata, DMATXSTATUS, ~0U);

	xge_setup_desc(pdata->tx_ring);
	xge_update_tx_desc_addr(pdata);
	xge_mac_init(pdata);

	napi_enable(&pdata->napi);
	xge_intr_enable(pdata);
	xge_mac_enable(pdata);
	netif_start_queue(ndev);

out:
	rtnl_unlock();
}

__attribute__((used)) static void xge_get_stats64(struct net_device *ndev,
			    struct rtnl_link_stats64 *storage)
{
	struct xge_pdata *pdata = netdev_priv(ndev);
	struct xge_stats *stats = &pdata->stats;

	storage->tx_packets += stats->tx_packets;
	storage->tx_bytes += stats->tx_bytes;

	storage->rx_packets += stats->rx_packets;
	storage->rx_bytes += stats->rx_bytes;
	storage->rx_errors += stats->rx_errors;
}

__attribute__((used)) static int xge_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct net_device *ndev;
	struct xge_pdata *pdata;
	int ret;

	ndev = alloc_etherdev(sizeof(*pdata));
	if (!ndev)
		return -ENOMEM;

	pdata = netdev_priv(ndev);

	pdata->pdev = pdev;
	pdata->ndev = ndev;
	SET_NETDEV_DEV(ndev, dev);
	platform_set_drvdata(pdev, pdata);
	ndev->netdev_ops = &xgene_ndev_ops;

	ndev->features |= NETIF_F_GSO |
			  NETIF_F_GRO;

	ret = xge_get_resources(pdata);
	if (ret)
		goto err;

	ndev->hw_features = ndev->features;
	xge_set_ethtool_ops(ndev);

	ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(64));
	if (ret) {
		netdev_err(ndev, "No usable DMA configuration\n");
		goto err;
	}

	ret = xge_init_hw(ndev);
	if (ret)
		goto err;

	ret = xge_mdio_config(ndev);
	if (ret)
		goto err;

	netif_napi_add(ndev, &pdata->napi, xge_napi, NAPI_POLL_WEIGHT);

	ret = register_netdev(ndev);
	if (ret) {
		netdev_err(ndev, "Failed to register netdev\n");
		goto err;
	}

	return 0;

err:
	free_netdev(ndev);

	return ret;
}

__attribute__((used)) static int xge_remove(struct platform_device *pdev)
{
	struct xge_pdata *pdata;
	struct net_device *ndev;

	pdata = platform_get_drvdata(pdev);
	ndev = pdata->ndev;

	rtnl_lock();
	if (netif_running(ndev))
		dev_close(ndev);
	rtnl_unlock();

	xge_mdio_remove(ndev);
	unregister_netdev(ndev);
	free_netdev(ndev);

	return 0;
}

__attribute__((used)) static void xge_shutdown(struct platform_device *pdev)
{
	struct xge_pdata *pdata;

	pdata = platform_get_drvdata(pdev);
	if (!pdata)
		return;

	if (!pdata->ndev)
		return;

	xge_remove(pdev);
}

