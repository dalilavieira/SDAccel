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
typedef  int u32 ;
struct stmmac_priv {int ioaddr; scalar_t__ synopsys_id; int extend_desc; int ptpaddr; int mmcaddr; int /*<<< orphan*/  device; int /*<<< orphan*/  hwif_quirks; struct mac_device_info* hw; TYPE_1__* plat; int /*<<< orphan*/  mode; scalar_t__ chain_mode; } ;
struct TYPE_4__ {int ptp_off; int mmc_off; } ;
struct stmmac_hwif_entry {int gmac; int gmac4; int xgmac; scalar_t__ min_id; int (* setup ) (struct stmmac_priv*) ;int /*<<< orphan*/  quirks; TYPE_2__ regs; scalar_t__ tc; int /*<<< orphan*/ * mode; scalar_t__ hwtimestamp; scalar_t__ mac; scalar_t__ dma; int /*<<< orphan*/ * desc; } ;
struct mac_device_info {scalar_t__ tc; int /*<<< orphan*/ * mode; scalar_t__ ptp; scalar_t__ mac; scalar_t__ dma; int /*<<< orphan*/ * desc; } ;
struct TYPE_3__ {int has_xgmac; int has_gmac4; int has_gmac; struct mac_device_info* (* setup ) (struct stmmac_priv*) ;scalar_t__ enh_desc; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct stmmac_hwif_entry*) ; 
 scalar_t__ DWMAC_CORE_3_50 ; 
 int EINVAL ; 
 int ENOMEM ; 
 int GENMASK (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GMAC4_VERSION ; 
 int GMAC_VERSION ; 
 int MMC_GMAC3_X_OFFSET ; 
 int MMC_GMAC4_OFFSET ; 
 int PTP_GMAC3_X_OFFSET ; 
 int PTP_GMAC4_OFFSET ; 
 int /*<<< orphan*/  STMMAC_CHAIN_MODE ; 
 int /*<<< orphan*/  STMMAC_RING_MODE ; 
 int /*<<< orphan*/  chain_mode_ops ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int,int,int) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 struct mac_device_info* devm_kzalloc (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enh_desc_ops ; 
 int /*<<< orphan*/  ndesc_ops ; 
 int readl (int) ; 
 int /*<<< orphan*/  ring_mode_ops ; 
 struct stmmac_hwif_entry* stmmac_hw ; 
 struct mac_device_info* stub1 (struct stmmac_priv*) ; 
 int stub2 (struct stmmac_priv*) ; 

__attribute__((used)) static u32 stmmac_get_id(struct stmmac_priv *priv, u32 id_reg)
{
	u32 reg = readl(priv->ioaddr + id_reg);

	if (!reg) {
		dev_info(priv->device, "Version ID not available\n");
		return 0x0;
	}

	dev_info(priv->device, "User ID: 0x%x, Synopsys ID: 0x%x\n",
			(unsigned int)(reg & GENMASK(15, 8)) >> 8,
			(unsigned int)(reg & GENMASK(7, 0)));
	return reg & GENMASK(7, 0);
}

__attribute__((used)) static void stmmac_dwmac_mode_quirk(struct stmmac_priv *priv)
{
	struct mac_device_info *mac = priv->hw;

	if (priv->chain_mode) {
		dev_info(priv->device, "Chain mode enabled\n");
		priv->mode = STMMAC_CHAIN_MODE;
		mac->mode = &chain_mode_ops;
	} else {
		dev_info(priv->device, "Ring mode enabled\n");
		priv->mode = STMMAC_RING_MODE;
		mac->mode = &ring_mode_ops;
	}
}

__attribute__((used)) static int stmmac_dwmac1_quirks(struct stmmac_priv *priv)
{
	struct mac_device_info *mac = priv->hw;

	if (priv->plat->enh_desc) {
		dev_info(priv->device, "Enhanced/Alternate descriptors\n");

		/* GMAC older than 3.50 has no extended descriptors */
		if (priv->synopsys_id >= DWMAC_CORE_3_50) {
			dev_info(priv->device, "Enabled extended descriptors\n");
			priv->extend_desc = 1;
		} else {
			dev_warn(priv->device, "Extended descriptors not supported\n");
		}

		mac->desc = &enh_desc_ops;
	} else {
		dev_info(priv->device, "Normal descriptors\n");
		mac->desc = &ndesc_ops;
	}

	stmmac_dwmac_mode_quirk(priv);
	return 0;
}

__attribute__((used)) static int stmmac_dwmac4_quirks(struct stmmac_priv *priv)
{
	stmmac_dwmac_mode_quirk(priv);
	return 0;
}

int stmmac_hwif_init(struct stmmac_priv *priv)
{
	bool needs_xgmac = priv->plat->has_xgmac;
	bool needs_gmac4 = priv->plat->has_gmac4;
	bool needs_gmac = priv->plat->has_gmac;
	const struct stmmac_hwif_entry *entry;
	struct mac_device_info *mac;
	bool needs_setup = true;
	int i, ret;
	u32 id;

	if (needs_gmac) {
		id = stmmac_get_id(priv, GMAC_VERSION);
	} else if (needs_gmac4 || needs_xgmac) {
		id = stmmac_get_id(priv, GMAC4_VERSION);
	} else {
		id = 0;
	}

	/* Save ID for later use */
	priv->synopsys_id = id;

	/* Lets assume some safe values first */
	priv->ptpaddr = priv->ioaddr +
		(needs_gmac4 ? PTP_GMAC4_OFFSET : PTP_GMAC3_X_OFFSET);
	priv->mmcaddr = priv->ioaddr +
		(needs_gmac4 ? MMC_GMAC4_OFFSET : MMC_GMAC3_X_OFFSET);

	/* Check for HW specific setup first */
	if (priv->plat->setup) {
		mac = priv->plat->setup(priv);
		needs_setup = false;
	} else {
		mac = devm_kzalloc(priv->device, sizeof(*mac), GFP_KERNEL);
	}

	if (!mac)
		return -ENOMEM;

	/* Fallback to generic HW */
	for (i = ARRAY_SIZE(stmmac_hw) - 1; i >= 0; i--) {
		entry = &stmmac_hw[i];

		if (needs_gmac ^ entry->gmac)
			continue;
		if (needs_gmac4 ^ entry->gmac4)
			continue;
		if (needs_xgmac ^ entry->xgmac)
			continue;
		/* Use synopsys_id var because some setups can override this */
		if (priv->synopsys_id < entry->min_id)
			continue;

		/* Only use generic HW helpers if needed */
		mac->desc = mac->desc ? : entry->desc;
		mac->dma = mac->dma ? : entry->dma;
		mac->mac = mac->mac ? : entry->mac;
		mac->ptp = mac->ptp ? : entry->hwtimestamp;
		mac->mode = mac->mode ? : entry->mode;
		mac->tc = mac->tc ? : entry->tc;

		priv->hw = mac;
		priv->ptpaddr = priv->ioaddr + entry->regs.ptp_off;
		priv->mmcaddr = priv->ioaddr + entry->regs.mmc_off;

		/* Entry found */
		if (needs_setup) {
			ret = entry->setup(priv);
			if (ret)
				return ret;
		}

		/* Save quirks, if needed for posterior use */
		priv->hwif_quirks = entry->quirks;
		return 0;
	}

	dev_err(priv->device, "Failed to find HW IF (id=0x%x, gmac=%d/%d)\n",
			id, needs_gmac, needs_gmac4);
	return -EINVAL;
}

