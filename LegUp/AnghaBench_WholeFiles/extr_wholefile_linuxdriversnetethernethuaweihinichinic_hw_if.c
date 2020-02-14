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
typedef  int u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct pci_dev {int /*<<< orphan*/  dev; } ;
struct hinic_func_attr {scalar_t__ ppf_idx; void* func_type; void* num_dma_attr; void* num_irqs; void* num_ceqs; void* num_aeqs; void* pci_intf_idx; void* pf_idx; void* func_idx; } ;
struct hinic_hwif {int cfg_regs_bar; struct pci_dev* pdev; struct hinic_func_attr attr; } ;
typedef  enum hinic_pf_action { ____Placeholder_hinic_pf_action } hinic_pf_action ;
typedef  enum hinic_pcie_tph { ____Placeholder_hinic_pcie_tph } hinic_pcie_tph ;
typedef  enum hinic_pcie_nosnoop { ____Placeholder_hinic_pcie_nosnoop } hinic_pcie_nosnoop ;
typedef  enum hinic_outbound_state { ____Placeholder_hinic_outbound_state } hinic_outbound_state ;
typedef  enum hinic_db_state { ____Placeholder_hinic_db_state } hinic_db_state ;

/* Variables and functions */
 int /*<<< orphan*/  AEQS_PER_FUNC ; 
 int /*<<< orphan*/  AT ; 
 void* BIT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CEQS_PER_FUNC ; 
 int /*<<< orphan*/  COALESC_TIMER ; 
 int /*<<< orphan*/  DB_STATE ; 
 int /*<<< orphan*/  DMA_ATTR_PER_FUNC ; 
 int EFAULT ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  FUNC_IDX ; 
 int /*<<< orphan*/  FUNC_TYPE ; 
 int HINIC_CSR_DMA_ATTR_ADDR (int) ; 
 int HINIC_CSR_FUNC_ATTR0_ADDR ; 
 int HINIC_CSR_FUNC_ATTR1_ADDR ; 
 int HINIC_CSR_FUNC_ATTR4_ADDR ; 
 int HINIC_CSR_FUNC_ATTR5_ADDR ; 
 int HINIC_CSR_MSIX_CNT_ADDR (int /*<<< orphan*/ ) ; 
 int HINIC_CSR_MSIX_CTRL_ADDR (int /*<<< orphan*/ ) ; 
 int HINIC_CSR_PPF_ELECTION_ADDR (int /*<<< orphan*/ ) ; 
 int HINIC_DMA_ATTR_CLEAR (int,int /*<<< orphan*/ ) ; 
 int HINIC_DMA_ATTR_SET (int,int /*<<< orphan*/ ) ; 
 void* HINIC_FA0_GET (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  HINIC_FA1_GET (int,int /*<<< orphan*/ ) ; 
 int HINIC_FA4_CLEAR (int,int /*<<< orphan*/ ) ; 
 int HINIC_FA4_GET (int,int /*<<< orphan*/ ) ; 
 int HINIC_FA4_SET (int,int /*<<< orphan*/ ) ; 
 int HINIC_FA5_CLEAR (int,int /*<<< orphan*/ ) ; 
 int HINIC_FA5_SET (int,int /*<<< orphan*/ ) ; 
 scalar_t__ HINIC_HWIF_FUNC_IDX (struct hinic_hwif*) ; 
 int /*<<< orphan*/  HINIC_HWIF_PCI_INTF (struct hinic_hwif*) ; 
 scalar_t__ HINIC_IS_PF (struct hinic_hwif*) ; 
 int HINIC_MSIX_ATTR_GET (int,int /*<<< orphan*/ ) ; 
 int HINIC_MSIX_ATTR_SET (int,int /*<<< orphan*/ ) ; 
 int HINIC_MSIX_CNT_SET (int,int /*<<< orphan*/ ) ; 
 int HINIC_PCIE_AT_DISABLE ; 
 int HINIC_PCIE_PH_DISABLE ; 
 int HINIC_PCIE_SNOOP ; 
 int HINIC_PCIE_ST_DISABLE ; 
 int HINIC_PCIE_TPH_DISABLE ; 
 int /*<<< orphan*/  HINIC_PCI_CFG_REGS_BAR ; 
 void* HINIC_PPF ; 
 int HINIC_PPF_ELECTION_CLEAR (int,int /*<<< orphan*/ ) ; 
 scalar_t__ HINIC_PPF_ELECTION_GET (int,int /*<<< orphan*/ ) ; 
 int HINIC_PPF_ELECTION_SET (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IDX ; 
 int /*<<< orphan*/  INIT_STATUS ; 
 int /*<<< orphan*/  IRQS_PER_FUNC ; 
 int /*<<< orphan*/  LLI_CREDIT ; 
 int /*<<< orphan*/  LLI_TIMER ; 
 int /*<<< orphan*/  NO_SNOOPING ; 
 int /*<<< orphan*/  OUTBOUND_STATE ; 
 int PCIE_ATTR_ENTRY ; 
 int /*<<< orphan*/  PCI_INTF_IDX ; 
 int /*<<< orphan*/  PENDING_LIMIT ; 
 int /*<<< orphan*/  PF_ACTION ; 
 int /*<<< orphan*/  PF_IDX ; 
 int /*<<< orphan*/  PH ; 
 int /*<<< orphan*/  RESEND_TIMER ; 
 int /*<<< orphan*/  ST ; 
 int /*<<< orphan*/  TPH_EN ; 
 int /*<<< orphan*/  VALID_MSIX_IDX (struct hinic_func_attr*,int /*<<< orphan*/ ) ; 
 int be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  iounmap (int) ; 
 int pci_ioremap_bar (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  readl (int) ; 
 int /*<<< orphan*/  writel (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline u32 hinic_hwif_read_reg(struct hinic_hwif *hwif, u32 reg)
{
	return be32_to_cpu(readl(hwif->cfg_regs_bar + reg));
}

__attribute__((used)) static inline void hinic_hwif_write_reg(struct hinic_hwif *hwif, u32 reg,
					u32 val)
{
	writel(cpu_to_be32(val), hwif->cfg_regs_bar + reg);
}

int hinic_msix_attr_set(struct hinic_hwif *hwif, u16 msix_index,
			u8 pending_limit, u8 coalesc_timer,
			u8 lli_timer, u8 lli_credit_limit,
			u8 resend_timer)
{
	u32 msix_ctrl, addr;

	if (!VALID_MSIX_IDX(&hwif->attr, msix_index))
		return -EINVAL;

	msix_ctrl = HINIC_MSIX_ATTR_SET(pending_limit, PENDING_LIMIT)   |
		    HINIC_MSIX_ATTR_SET(coalesc_timer, COALESC_TIMER)   |
		    HINIC_MSIX_ATTR_SET(lli_timer, LLI_TIMER)           |
		    HINIC_MSIX_ATTR_SET(lli_credit_limit, LLI_CREDIT)   |
		    HINIC_MSIX_ATTR_SET(resend_timer, RESEND_TIMER);

	addr = HINIC_CSR_MSIX_CTRL_ADDR(msix_index);

	hinic_hwif_write_reg(hwif, addr, msix_ctrl);
	return 0;
}

int hinic_msix_attr_get(struct hinic_hwif *hwif, u16 msix_index,
			u8 *pending_limit, u8 *coalesc_timer,
			u8 *lli_timer, u8 *lli_credit_limit,
			u8 *resend_timer)
{
	u32 addr, val;

	if (!VALID_MSIX_IDX(&hwif->attr, msix_index))
		return -EINVAL;

	addr = HINIC_CSR_MSIX_CTRL_ADDR(msix_index);
	val  = hinic_hwif_read_reg(hwif, addr);

	*pending_limit    = HINIC_MSIX_ATTR_GET(val, PENDING_LIMIT);
	*coalesc_timer    = HINIC_MSIX_ATTR_GET(val, COALESC_TIMER);
	*lli_timer        = HINIC_MSIX_ATTR_GET(val, LLI_TIMER);
	*lli_credit_limit = HINIC_MSIX_ATTR_GET(val, LLI_CREDIT);
	*resend_timer     = HINIC_MSIX_ATTR_GET(val, RESEND_TIMER);
	return 0;
}

int hinic_msix_attr_cnt_clear(struct hinic_hwif *hwif, u16 msix_index)
{
	u32 msix_ctrl, addr;

	if (!VALID_MSIX_IDX(&hwif->attr, msix_index))
		return -EINVAL;

	msix_ctrl = HINIC_MSIX_CNT_SET(1, RESEND_TIMER);
	addr = HINIC_CSR_MSIX_CNT_ADDR(msix_index);

	hinic_hwif_write_reg(hwif, addr, msix_ctrl);
	return 0;
}

void hinic_set_pf_action(struct hinic_hwif *hwif, enum hinic_pf_action action)
{
	u32 attr5 = hinic_hwif_read_reg(hwif, HINIC_CSR_FUNC_ATTR5_ADDR);

	attr5 = HINIC_FA5_CLEAR(attr5, PF_ACTION);
	attr5 |= HINIC_FA5_SET(action, PF_ACTION);

	hinic_hwif_write_reg(hwif, HINIC_CSR_FUNC_ATTR5_ADDR, attr5);
}

enum hinic_outbound_state hinic_outbound_state_get(struct hinic_hwif *hwif)
{
	u32 attr4 = hinic_hwif_read_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR);

	return HINIC_FA4_GET(attr4, OUTBOUND_STATE);
}

void hinic_outbound_state_set(struct hinic_hwif *hwif,
			      enum hinic_outbound_state outbound_state)
{
	u32 attr4 = hinic_hwif_read_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR);

	attr4 = HINIC_FA4_CLEAR(attr4, OUTBOUND_STATE);
	attr4 |= HINIC_FA4_SET(outbound_state, OUTBOUND_STATE);

	hinic_hwif_write_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR, attr4);
}

enum hinic_db_state hinic_db_state_get(struct hinic_hwif *hwif)
{
	u32 attr4 = hinic_hwif_read_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR);

	return HINIC_FA4_GET(attr4, DB_STATE);
}

void hinic_db_state_set(struct hinic_hwif *hwif,
			enum hinic_db_state db_state)
{
	u32 attr4 = hinic_hwif_read_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR);

	attr4 = HINIC_FA4_CLEAR(attr4, DB_STATE);
	attr4 |= HINIC_FA4_SET(db_state, DB_STATE);

	hinic_hwif_write_reg(hwif, HINIC_CSR_FUNC_ATTR4_ADDR, attr4);
}

__attribute__((used)) static int hwif_ready(struct hinic_hwif *hwif)
{
	struct pci_dev *pdev = hwif->pdev;
	u32 addr, attr1;

	addr   = HINIC_CSR_FUNC_ATTR1_ADDR;
	attr1  = hinic_hwif_read_reg(hwif, addr);

	if (!HINIC_FA1_GET(attr1, INIT_STATUS)) {
		dev_err(&pdev->dev, "hwif status is not ready\n");
		return -EFAULT;
	}

	return 0;
}

__attribute__((used)) static void set_hwif_attr(struct hinic_hwif *hwif, u32 attr0, u32 attr1)
{
	hwif->attr.func_idx     = HINIC_FA0_GET(attr0, FUNC_IDX);
	hwif->attr.pf_idx       = HINIC_FA0_GET(attr0, PF_IDX);
	hwif->attr.pci_intf_idx = HINIC_FA0_GET(attr0, PCI_INTF_IDX);
	hwif->attr.func_type    = HINIC_FA0_GET(attr0, FUNC_TYPE);

	hwif->attr.num_aeqs = BIT(HINIC_FA1_GET(attr1, AEQS_PER_FUNC));
	hwif->attr.num_ceqs = BIT(HINIC_FA1_GET(attr1, CEQS_PER_FUNC));
	hwif->attr.num_irqs = BIT(HINIC_FA1_GET(attr1, IRQS_PER_FUNC));
	hwif->attr.num_dma_attr = BIT(HINIC_FA1_GET(attr1, DMA_ATTR_PER_FUNC));
}

__attribute__((used)) static void read_hwif_attr(struct hinic_hwif *hwif)
{
	u32 addr, attr0, attr1;

	addr   = HINIC_CSR_FUNC_ATTR0_ADDR;
	attr0  = hinic_hwif_read_reg(hwif, addr);

	addr   = HINIC_CSR_FUNC_ATTR1_ADDR;
	attr1  = hinic_hwif_read_reg(hwif, addr);

	set_hwif_attr(hwif, attr0, attr1);
}

__attribute__((used)) static void set_ppf(struct hinic_hwif *hwif)
{
	struct hinic_func_attr *attr = &hwif->attr;
	u32 addr, val, ppf_election;

	/* Read Modify Write */
	addr = HINIC_CSR_PPF_ELECTION_ADDR(HINIC_HWIF_PCI_INTF(hwif));

	val = hinic_hwif_read_reg(hwif, addr);
	val = HINIC_PPF_ELECTION_CLEAR(val, IDX);

	ppf_election = HINIC_PPF_ELECTION_SET(HINIC_HWIF_FUNC_IDX(hwif), IDX);

	val |= ppf_election;
	hinic_hwif_write_reg(hwif, addr, val);

	/* check PPF */
	val = hinic_hwif_read_reg(hwif, addr);

	attr->ppf_idx = HINIC_PPF_ELECTION_GET(val, IDX);
	if (attr->ppf_idx == HINIC_HWIF_FUNC_IDX(hwif))
		attr->func_type = HINIC_PPF;
}

__attribute__((used)) static void set_dma_attr(struct hinic_hwif *hwif, u32 entry_idx,
			 u8 st, u8 at, u8 ph,
			 enum hinic_pcie_nosnoop no_snooping,
			 enum hinic_pcie_tph tph_en)
{
	u32 addr, val, dma_attr_entry;

	/* Read Modify Write */
	addr = HINIC_CSR_DMA_ATTR_ADDR(entry_idx);

	val = hinic_hwif_read_reg(hwif, addr);
	val = HINIC_DMA_ATTR_CLEAR(val, ST)             &
	      HINIC_DMA_ATTR_CLEAR(val, AT)             &
	      HINIC_DMA_ATTR_CLEAR(val, PH)             &
	      HINIC_DMA_ATTR_CLEAR(val, NO_SNOOPING)    &
	      HINIC_DMA_ATTR_CLEAR(val, TPH_EN);

	dma_attr_entry = HINIC_DMA_ATTR_SET(st, ST)                     |
			 HINIC_DMA_ATTR_SET(at, AT)                     |
			 HINIC_DMA_ATTR_SET(ph, PH)                     |
			 HINIC_DMA_ATTR_SET(no_snooping, NO_SNOOPING)   |
			 HINIC_DMA_ATTR_SET(tph_en, TPH_EN);

	val |= dma_attr_entry;
	hinic_hwif_write_reg(hwif, addr, val);
}

__attribute__((used)) static void dma_attr_init(struct hinic_hwif *hwif)
{
	set_dma_attr(hwif, PCIE_ATTR_ENTRY, HINIC_PCIE_ST_DISABLE,
		     HINIC_PCIE_AT_DISABLE, HINIC_PCIE_PH_DISABLE,
		     HINIC_PCIE_SNOOP, HINIC_PCIE_TPH_DISABLE);
}

int hinic_init_hwif(struct hinic_hwif *hwif, struct pci_dev *pdev)
{
	int err;

	hwif->pdev = pdev;

	hwif->cfg_regs_bar = pci_ioremap_bar(pdev, HINIC_PCI_CFG_REGS_BAR);
	if (!hwif->cfg_regs_bar) {
		dev_err(&pdev->dev, "Failed to map configuration regs\n");
		return -ENOMEM;
	}

	err = hwif_ready(hwif);
	if (err) {
		dev_err(&pdev->dev, "HW interface is not ready\n");
		goto err_hwif_ready;
	}

	read_hwif_attr(hwif);

	if (HINIC_IS_PF(hwif))
		set_ppf(hwif);

	/* No transactionss before DMA is initialized */
	dma_attr_init(hwif);
	return 0;

err_hwif_ready:
	iounmap(hwif->cfg_regs_bar);
	return err;
}

void hinic_free_hwif(struct hinic_hwif *hwif)
{
	iounmap(hwif->cfg_regs_bar);
}

