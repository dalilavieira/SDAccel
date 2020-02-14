#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  unsigned long long u64 ;
typedef  int u32 ;
typedef  int u16 ;
struct xge_raw_desc {void* m1; void* m0; } ;
struct xge_pdata {struct xge_desc_ring* rx_ring; struct xge_desc_ring* tx_ring; } ;
struct xge_desc_ring {int dma_addr; scalar_t__ tail; scalar_t__ head; struct xge_raw_desc* raw_desc; } ;
typedef  int dma_addr_t ;

/* Variables and functions */
 int /*<<< orphan*/  DMAINTRMASK ; 
 int /*<<< orphan*/  DMARXDESCH ; 
 int /*<<< orphan*/  DMARXDESCL ; 
 int /*<<< orphan*/  DMATXDESCH ; 
 int /*<<< orphan*/  DMATXDESCL ; 
 int /*<<< orphan*/  E ; 
 int GENMASK (int,int) ; 
 int /*<<< orphan*/  NEXT_DESC_ADDRH ; 
 int /*<<< orphan*/  NEXT_DESC_ADDRL ; 
 int /*<<< orphan*/  PKT_SIZE ; 
 int RX_PKT_RCVD ; 
 int SET_BITS (int /*<<< orphan*/ ,int) ; 
 int SLOT_EMPTY ; 
 int TX_PKT_SENT ; 
 int XGENE_ENET_DESC_SIZE ; 
 int XGENE_ENET_NUM_DESC ; 
 void* cpu_to_le64 (int) ; 
 int upper_32_bits (int) ; 
 int /*<<< orphan*/  xge_wr_csr (struct xge_pdata*,int /*<<< orphan*/ ,int) ; 

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

void xge_setup_desc(struct xge_desc_ring *ring)
{
	struct xge_raw_desc *raw_desc;
	dma_addr_t dma_h, next_dma;
	u16 offset;
	int i;

	for (i = 0; i < XGENE_ENET_NUM_DESC; i++) {
		raw_desc = &ring->raw_desc[i];

		offset = (i + 1) & (XGENE_ENET_NUM_DESC - 1);
		next_dma = ring->dma_addr + (offset * XGENE_ENET_DESC_SIZE);

		raw_desc->m0 = cpu_to_le64(SET_BITS(E, 1) |
					   SET_BITS(PKT_SIZE, SLOT_EMPTY));
		dma_h = upper_32_bits(next_dma);
		raw_desc->m1 = cpu_to_le64(SET_BITS(NEXT_DESC_ADDRL, next_dma) |
					   SET_BITS(NEXT_DESC_ADDRH, dma_h));
	}
}

void xge_update_tx_desc_addr(struct xge_pdata *pdata)
{
	struct xge_desc_ring *ring = pdata->tx_ring;
	dma_addr_t dma_addr = ring->dma_addr;

	xge_wr_csr(pdata, DMATXDESCL, dma_addr);
	xge_wr_csr(pdata, DMATXDESCH, upper_32_bits(dma_addr));

	ring->head = 0;
	ring->tail = 0;
}

void xge_update_rx_desc_addr(struct xge_pdata *pdata)
{
	struct xge_desc_ring *ring = pdata->rx_ring;
	dma_addr_t dma_addr = ring->dma_addr;

	xge_wr_csr(pdata, DMARXDESCL, dma_addr);
	xge_wr_csr(pdata, DMARXDESCH, upper_32_bits(dma_addr));

	ring->head = 0;
	ring->tail = 0;
}

void xge_intr_enable(struct xge_pdata *pdata)
{
	u32 data;

	data = RX_PKT_RCVD | TX_PKT_SENT;
	xge_wr_csr(pdata, DMAINTRMASK, data);
}

void xge_intr_disable(struct xge_pdata *pdata)
{
	xge_wr_csr(pdata, DMAINTRMASK, 0);
}

