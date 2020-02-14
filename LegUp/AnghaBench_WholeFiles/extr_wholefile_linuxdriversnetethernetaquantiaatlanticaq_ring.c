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
typedef  unsigned long u32 ;
struct sk_buff {scalar_t__ len; int /*<<< orphan*/  protocol; int /*<<< orphan*/  data; void* ip_summed; } ;
struct net_device {int dummy; } ;
struct napi_struct {int dummy; } ;
struct device {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  bytes; int /*<<< orphan*/  packets; int /*<<< orphan*/  errors; } ;
struct TYPE_9__ {int /*<<< orphan*/  queue_restarts; } ;
struct TYPE_12__ {TYPE_5__ rx; TYPE_3__ tx; } ;
struct aq_ring_s {unsigned int size; scalar_t__ sw_tail; scalar_t__ sw_head; int dx_size; unsigned int idx; unsigned int hw_head; int /*<<< orphan*/  dx_ring_pa; scalar_t__ dx_ring; struct aq_nic_s* aq_nic; struct aq_ring_buff_s* buff_ring; TYPE_6__ stats; } ;
struct aq_ring_buff_s {int is_sop; int is_eop; int eop_index; unsigned int pa; int len; int is_cso_err; int is_cleaned; unsigned int next; unsigned int flags; scalar_t__ page; scalar_t__ is_hash_l4; int /*<<< orphan*/  rss_hash; scalar_t__ is_error; scalar_t__ is_tcp_cso; scalar_t__ is_udp_cso; scalar_t__ is_ip_cso; int /*<<< orphan*/  skb; int /*<<< orphan*/  is_mapped; } ;
struct aq_nic_s {TYPE_4__* ndev; } ;
struct aq_nic_cfg_s {int txds; int rxds; TYPE_2__* aq_hw_caps; } ;
typedef  int /*<<< orphan*/  atomic_t ;
struct TYPE_7__ {struct device* parent; } ;
struct TYPE_10__ {int features; TYPE_1__ dev; } ;
struct TYPE_8__ {int txd_size; int rxd_size; } ;

/* Variables and functions */
 scalar_t__ AQ_CFG_RESTART_DESC_THRES ; 
 int AQ_CFG_RX_FRAME_MAX ; 
 scalar_t__ AQ_CFG_SKB_FRAGS_MAX ; 
 unsigned int AQ_CFG_TX_CLEAN_BUDGET ; 
 scalar_t__ AQ_SKB_ALIGN ; 
 void* CHECKSUM_NONE ; 
 int /*<<< orphan*/  DMA_FROM_DEVICE ; 
 int /*<<< orphan*/  DMA_TO_DEVICE ; 
 int ENOMEM ; 
 scalar_t__ ETH_HLEN ; 
 int GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int NETIF_F_RXCSUM ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  PKT_HASH_TYPE_L4 ; 
 int /*<<< orphan*/  PKT_HASH_TYPE_NONE ; 
 int /*<<< orphan*/  SKB_TRUESIZE (scalar_t__) ; 
 int __GFP_COMP ; 
 int /*<<< orphan*/  __free_pages (scalar_t__,int /*<<< orphan*/ ) ; 
 scalar_t__ __netif_subqueue_stopped (struct net_device*,unsigned int) ; 
 int /*<<< orphan*/  __skb_incr_checksum_unnecessary (struct sk_buff*) ; 
 scalar_t__ alloc_pages (int,unsigned int) ; 
 struct net_device* aq_nic_get_ndev (struct aq_nic_s*) ; 
 void aq_ring_free (struct aq_ring_s*) ; 
 void aq_ring_queue_stop (struct aq_ring_s*) ; 
 void aq_ring_queue_wake (struct aq_ring_s*) ; 
 unsigned long atomic_cmpxchg (int /*<<< orphan*/ *,unsigned long,unsigned long) ; 
 unsigned long atomic_read (int /*<<< orphan*/ *) ; 
 struct sk_buff* build_skb (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (int /*<<< orphan*/ ) ; 
 scalar_t__ dma_alloc_coherent (struct device*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_free_coherent (struct device*,int,scalar_t__,int /*<<< orphan*/ ) ; 
 unsigned int dma_map_page (struct device*,scalar_t__,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__ dma_mapping_error (struct device*,unsigned int) ; 
 int /*<<< orphan*/  dma_unmap_page (struct device*,unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dma_unmap_single (struct device*,unsigned int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eth_type_trans (struct sk_buff*,struct net_device*) ; 
 int fls (int) ; 
 struct aq_ring_buff_s* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct aq_ring_buff_s*) ; 
 scalar_t__ likely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  napi_gro_receive (struct napi_struct*,struct sk_buff*) ; 
 struct sk_buff* netdev_alloc_skb (struct net_device*,scalar_t__) ; 
 int /*<<< orphan*/  netif_stop_subqueue (struct net_device*,unsigned int) ; 
 int /*<<< orphan*/  netif_wake_subqueue (struct net_device*,unsigned int) ; 
 int /*<<< orphan*/  page_address (scalar_t__) ; 
 int /*<<< orphan*/  skb_add_rx_frag (struct sk_buff*,unsigned int,scalar_t__,scalar_t__,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_put (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_record_rx_queue (struct sk_buff*,unsigned int) ; 
 int /*<<< orphan*/  skb_set_hash (struct sk_buff*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline void aq_utils_obj_set(atomic_t *flags, u32 mask)
{
	unsigned long flags_old, flags_new;

	do {
		flags_old = atomic_read(flags);
		flags_new = flags_old | (mask);
	} while (atomic_cmpxchg(flags, flags_old, flags_new) != flags_old);
}

__attribute__((used)) static inline void aq_utils_obj_clear(atomic_t *flags, u32 mask)
{
	unsigned long flags_old, flags_new;

	do {
		flags_old = atomic_read(flags);
		flags_new = flags_old & ~(mask);
	} while (atomic_cmpxchg(flags, flags_old, flags_new) != flags_old);
}

__attribute__((used)) static inline bool aq_utils_obj_test(atomic_t *flags, u32 mask)
{
	return atomic_read(flags) & mask;
}

__attribute__((used)) static inline unsigned int aq_ring_next_dx(struct aq_ring_s *self,
					   unsigned int dx)
{
	return (++dx >= self->size) ? 0U : dx;
}

__attribute__((used)) static inline unsigned int aq_ring_avail_dx(struct aq_ring_s *self)
{
	return (((self->sw_tail >= self->sw_head)) ?
		(self->size - 1) - self->sw_tail + self->sw_head :
		self->sw_head - self->sw_tail - 1);
}

__attribute__((used)) static inline struct device *aq_nic_get_dev(struct aq_nic_s *self)
{
	return self->ndev->dev.parent;
}

__attribute__((used)) static struct aq_ring_s *aq_ring_alloc(struct aq_ring_s *self,
				       struct aq_nic_s *aq_nic)
{
	int err = 0;

	self->buff_ring =
		kcalloc(self->size, sizeof(struct aq_ring_buff_s), GFP_KERNEL);

	if (!self->buff_ring) {
		err = -ENOMEM;
		goto err_exit;
	}
	self->dx_ring = dma_alloc_coherent(aq_nic_get_dev(aq_nic),
						self->size * self->dx_size,
						&self->dx_ring_pa, GFP_KERNEL);
	if (!self->dx_ring) {
		err = -ENOMEM;
		goto err_exit;
	}

err_exit:
	if (err < 0) {
		aq_ring_free(self);
		self = NULL;
	}
	return self;
}

struct aq_ring_s *aq_ring_tx_alloc(struct aq_ring_s *self,
				   struct aq_nic_s *aq_nic,
				   unsigned int idx,
				   struct aq_nic_cfg_s *aq_nic_cfg)
{
	int err = 0;

	self->aq_nic = aq_nic;
	self->idx = idx;
	self->size = aq_nic_cfg->txds;
	self->dx_size = aq_nic_cfg->aq_hw_caps->txd_size;

	self = aq_ring_alloc(self, aq_nic);
	if (!self) {
		err = -ENOMEM;
		goto err_exit;
	}

err_exit:
	if (err < 0) {
		aq_ring_free(self);
		self = NULL;
	}
	return self;
}

struct aq_ring_s *aq_ring_rx_alloc(struct aq_ring_s *self,
				   struct aq_nic_s *aq_nic,
				   unsigned int idx,
				   struct aq_nic_cfg_s *aq_nic_cfg)
{
	int err = 0;

	self->aq_nic = aq_nic;
	self->idx = idx;
	self->size = aq_nic_cfg->rxds;
	self->dx_size = aq_nic_cfg->aq_hw_caps->rxd_size;

	self = aq_ring_alloc(self, aq_nic);
	if (!self) {
		err = -ENOMEM;
		goto err_exit;
	}

err_exit:
	if (err < 0) {
		aq_ring_free(self);
		self = NULL;
	}
	return self;
}

int aq_ring_init(struct aq_ring_s *self)
{
	self->hw_head = 0;
	self->sw_head = 0;
	self->sw_tail = 0;
	return 0;
}

__attribute__((used)) static inline bool aq_ring_dx_in_range(unsigned int h, unsigned int i,
				       unsigned int t)
{
	return (h < t) ? ((h < i) && (i < t)) : ((h < i) || (i < t));
}

void aq_ring_update_queue_state(struct aq_ring_s *ring)
{
	if (aq_ring_avail_dx(ring) <= AQ_CFG_SKB_FRAGS_MAX)
		aq_ring_queue_stop(ring);
	else if (aq_ring_avail_dx(ring) > AQ_CFG_RESTART_DESC_THRES)
		aq_ring_queue_wake(ring);
}

void aq_ring_queue_wake(struct aq_ring_s *ring)
{
	struct net_device *ndev = aq_nic_get_ndev(ring->aq_nic);

	if (__netif_subqueue_stopped(ndev, ring->idx)) {
		netif_wake_subqueue(ndev, ring->idx);
		ring->stats.tx.queue_restarts++;
	}
}

void aq_ring_queue_stop(struct aq_ring_s *ring)
{
	struct net_device *ndev = aq_nic_get_ndev(ring->aq_nic);

	if (!__netif_subqueue_stopped(ndev, ring->idx))
		netif_stop_subqueue(ndev, ring->idx);
}

bool aq_ring_tx_clean(struct aq_ring_s *self)
{
	struct device *dev = aq_nic_get_dev(self->aq_nic);
	unsigned int budget = AQ_CFG_TX_CLEAN_BUDGET;

	for (; self->sw_head != self->hw_head && budget--;
		self->sw_head = aq_ring_next_dx(self, self->sw_head)) {
		struct aq_ring_buff_s *buff = &self->buff_ring[self->sw_head];

		if (likely(buff->is_mapped)) {
			if (unlikely(buff->is_sop)) {
				if (!buff->is_eop &&
				    buff->eop_index != 0xffffU &&
				    (!aq_ring_dx_in_range(self->sw_head,
						buff->eop_index,
						self->hw_head)))
					break;

				dma_unmap_single(dev, buff->pa, buff->len,
						 DMA_TO_DEVICE);
			} else {
				dma_unmap_page(dev, buff->pa, buff->len,
					       DMA_TO_DEVICE);
			}
		}

		if (unlikely(buff->is_eop))
			dev_kfree_skb_any(buff->skb);

		buff->pa = 0U;
		buff->eop_index = 0xffffU;
	}

	return !!budget;
}

__attribute__((used)) static void aq_rx_checksum(struct aq_ring_s *self,
			   struct aq_ring_buff_s *buff,
			   struct sk_buff *skb)
{
	if (!(self->aq_nic->ndev->features & NETIF_F_RXCSUM))
		return;

	if (unlikely(buff->is_cso_err)) {
		++self->stats.rx.errors;
		skb->ip_summed = CHECKSUM_NONE;
		return;
	}
	if (buff->is_ip_cso) {
		__skb_incr_checksum_unnecessary(skb);
	} else {
		skb->ip_summed = CHECKSUM_NONE;
	}

	if (buff->is_udp_cso || buff->is_tcp_cso)
		__skb_incr_checksum_unnecessary(skb);
}

int aq_ring_rx_clean(struct aq_ring_s *self,
		     struct napi_struct *napi,
		     int *work_done,
		     int budget)
{
	struct net_device *ndev = aq_nic_get_ndev(self->aq_nic);
	int err = 0;
	bool is_rsc_completed = true;

	for (; (self->sw_head != self->hw_head) && budget;
		self->sw_head = aq_ring_next_dx(self, self->sw_head),
		--budget, ++(*work_done)) {
		struct aq_ring_buff_s *buff = &self->buff_ring[self->sw_head];
		struct sk_buff *skb = NULL;
		unsigned int next_ = 0U;
		unsigned int i = 0U;
		struct aq_ring_buff_s *buff_ = NULL;

		if (buff->is_error) {
			__free_pages(buff->page, 0);
			continue;
		}

		if (buff->is_cleaned)
			continue;

		if (!buff->is_eop) {
			for (next_ = buff->next,
			     buff_ = &self->buff_ring[next_]; true;
			     next_ = buff_->next,
			     buff_ = &self->buff_ring[next_]) {
				is_rsc_completed =
					aq_ring_dx_in_range(self->sw_head,
							    next_,
							    self->hw_head);

				if (unlikely(!is_rsc_completed)) {
					is_rsc_completed = false;
					break;
				}

				if (buff_->is_eop)
					break;
			}

			if (!is_rsc_completed) {
				err = 0;
				goto err_exit;
			}
		}

		/* for single fragment packets use build_skb() */
		if (buff->is_eop &&
		    buff->len <= AQ_CFG_RX_FRAME_MAX - AQ_SKB_ALIGN) {
			skb = build_skb(page_address(buff->page),
					AQ_CFG_RX_FRAME_MAX);
			if (unlikely(!skb)) {
				err = -ENOMEM;
				goto err_exit;
			}

			skb_put(skb, buff->len);
		} else {
			skb = netdev_alloc_skb(ndev, ETH_HLEN);
			if (unlikely(!skb)) {
				err = -ENOMEM;
				goto err_exit;
			}
			skb_put(skb, ETH_HLEN);
			memcpy(skb->data, page_address(buff->page), ETH_HLEN);

			skb_add_rx_frag(skb, 0, buff->page, ETH_HLEN,
					buff->len - ETH_HLEN,
					SKB_TRUESIZE(buff->len - ETH_HLEN));

			if (!buff->is_eop) {
				for (i = 1U, next_ = buff->next,
				     buff_ = &self->buff_ring[next_];
				     true; next_ = buff_->next,
				     buff_ = &self->buff_ring[next_], ++i) {
					skb_add_rx_frag(skb, i,
							buff_->page, 0,
							buff_->len,
							SKB_TRUESIZE(buff->len -
							ETH_HLEN));
					buff_->is_cleaned = 1;

					if (buff_->is_eop)
						break;
				}
			}
		}

		skb->protocol = eth_type_trans(skb, ndev);

		aq_rx_checksum(self, buff, skb);

		skb_set_hash(skb, buff->rss_hash,
			     buff->is_hash_l4 ? PKT_HASH_TYPE_L4 :
			     PKT_HASH_TYPE_NONE);

		skb_record_rx_queue(skb, self->idx);

		++self->stats.rx.packets;
		self->stats.rx.bytes += skb->len;

		napi_gro_receive(napi, skb);
	}

err_exit:
	return err;
}

int aq_ring_rx_fill(struct aq_ring_s *self)
{
	unsigned int pages_order = fls(AQ_CFG_RX_FRAME_MAX / PAGE_SIZE +
		(AQ_CFG_RX_FRAME_MAX % PAGE_SIZE ? 1 : 0)) - 1;
	struct aq_ring_buff_s *buff = NULL;
	int err = 0;
	int i = 0;

	for (i = aq_ring_avail_dx(self); i--;
		self->sw_tail = aq_ring_next_dx(self, self->sw_tail)) {
		buff = &self->buff_ring[self->sw_tail];

		buff->flags = 0U;
		buff->len = AQ_CFG_RX_FRAME_MAX;

		buff->page = alloc_pages(GFP_ATOMIC | __GFP_COMP, pages_order);
		if (!buff->page) {
			err = -ENOMEM;
			goto err_exit;
		}

		buff->pa = dma_map_page(aq_nic_get_dev(self->aq_nic),
					buff->page, 0,
					AQ_CFG_RX_FRAME_MAX, DMA_FROM_DEVICE);

		if (dma_mapping_error(aq_nic_get_dev(self->aq_nic), buff->pa)) {
			err = -ENOMEM;
			goto err_exit;
		}

		buff = NULL;
	}

err_exit:
	if (err < 0) {
		if (buff && buff->page)
			__free_pages(buff->page, 0);
	}

	return err;
}

void aq_ring_rx_deinit(struct aq_ring_s *self)
{
	if (!self)
		goto err_exit;

	for (; self->sw_head != self->sw_tail;
		self->sw_head = aq_ring_next_dx(self, self->sw_head)) {
		struct aq_ring_buff_s *buff = &self->buff_ring[self->sw_head];

		dma_unmap_page(aq_nic_get_dev(self->aq_nic), buff->pa,
			       AQ_CFG_RX_FRAME_MAX, DMA_FROM_DEVICE);

		__free_pages(buff->page, 0);
	}

err_exit:;
}

void aq_ring_free(struct aq_ring_s *self)
{
	if (!self)
		goto err_exit;

	kfree(self->buff_ring);

	if (self->dx_ring)
		dma_free_coherent(aq_nic_get_dev(self->aq_nic),
				  self->size * self->dx_size, self->dx_ring,
				  self->dx_ring_pa);

err_exit:;
}

