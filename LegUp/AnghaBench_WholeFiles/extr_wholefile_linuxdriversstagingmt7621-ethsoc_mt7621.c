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
struct mtk_mac {int id; struct mtk_eth* hw; } ;
struct mtk_eth {int /*<<< orphan*/  page_lock; } ;

/* Variables and functions */
 unsigned char GDMA_ICS_EN ; 
 unsigned char GDMA_TCS_EN ; 
 unsigned char GDMA_UCS_EN ; 
 int /*<<< orphan*/  GSW_REG_GDMA1_MAC_ADRH ; 
 int /*<<< orphan*/  GSW_REG_GDMA1_MAC_ADRL ; 
 int /*<<< orphan*/  GSW_REG_GDMA2_MAC_ADRH ; 
 int /*<<< orphan*/  GSW_REG_GDMA2_MAC_ADRL ; 
 int /*<<< orphan*/  MT7620_GDMA1_FWD_CFG ; 
 int /*<<< orphan*/  MT7621_CDMP_EG_CTRL ; 
 int /*<<< orphan*/  MT7621_RESET_FE ; 
 unsigned char mtk_r32 (struct mtk_eth*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_reset (struct mtk_eth*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mtk_w32 (struct mtk_eth*,unsigned char,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline int mtk_mdio_init(struct mtk_eth *eth) { return 0; }

__attribute__((used)) static inline void mtk_mdio_cleanup(struct mtk_eth *eth) {}

__attribute__((used)) static void mt7621_mtk_reset(struct mtk_eth *eth)
{
	mtk_reset(eth, MT7621_RESET_FE);
}

__attribute__((used)) static int mt7621_fwd_config(struct mtk_eth *eth)
{
	/* Setup GMAC1 only, there is no support for GMAC2 yet */
	mtk_w32(eth, mtk_r32(eth, MT7620_GDMA1_FWD_CFG) & ~0xffff,
		MT7620_GDMA1_FWD_CFG);

	/* Enable RX checksum */
	mtk_w32(eth, mtk_r32(eth, MT7620_GDMA1_FWD_CFG) | (GDMA_ICS_EN |
		       GDMA_TCS_EN | GDMA_UCS_EN),
		       MT7620_GDMA1_FWD_CFG);

	/* Enable RX VLan Offloading */
	mtk_w32(eth, 0, MT7621_CDMP_EG_CTRL);

	return 0;
}

__attribute__((used)) static void mt7621_set_mac(struct mtk_mac *mac, unsigned char *hwaddr)
{
	unsigned long flags;

	spin_lock_irqsave(&mac->hw->page_lock, flags);
	if (mac->id == 0) {
		mtk_w32(mac->hw, (hwaddr[0] << 8) | hwaddr[1],
			GSW_REG_GDMA1_MAC_ADRH);
		mtk_w32(mac->hw, (hwaddr[2] << 24) | (hwaddr[3] << 16) |
			(hwaddr[4] << 8) | hwaddr[5],
			GSW_REG_GDMA1_MAC_ADRL);
	}
	if (mac->id == 1) {
		mtk_w32(mac->hw, (hwaddr[0] << 8) | hwaddr[1],
			GSW_REG_GDMA2_MAC_ADRH);
		mtk_w32(mac->hw, (hwaddr[2] << 24) | (hwaddr[3] << 16) |
			(hwaddr[4] << 8) | hwaddr[5],
			GSW_REG_GDMA2_MAC_ADRL);
	}
	spin_unlock_irqrestore(&mac->hw->page_lock, flags);
}

