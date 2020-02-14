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
typedef  int u8 ;
typedef  int u32 ;
typedef  int u16 ;
struct pcie_port {TYPE_1__* mem; int /*<<< orphan*/  irq_domain; } ;
struct TYPE_4__ {scalar_t__ start; } ;
struct keystone_pcie {int va_app_base; struct dw_pcie* pci; int /*<<< orphan*/  legacy_irq_domain; TYPE_2__ app; } ;
struct irq_domain {int /*<<< orphan*/  host_data; } ;
struct irq_data {int dummy; } ;
struct dw_pcie_ep {int dummy; } ;
struct dw_pcie {struct pcie_port pp; struct device* dev; int /*<<< orphan*/  dbi_base2; int /*<<< orphan*/  dbi_base; } ;
struct device {int dummy; } ;
typedef  scalar_t__ phys_addr_t ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;
typedef  enum pci_barno { ____Placeholder_pci_barno } pci_barno ;
struct TYPE_3__ {int start; int end; } ;

/* Variables and functions */
 int BIT (int) ; 
 int CFG_PCIM_WIN_CNT ; 
 int CFG_PCIM_WIN_SZ_IDX ; 
 int CMD_STATUS ; 
 int DBI_CS2_EN_VAL ; 
 int ERR_FATAL_IRQ ; 
 int ERR_IRQ_ALL ; 
 int ERR_IRQ_ENABLE_SET ; 
 int ERR_IRQ_STATUS ; 
 int ERR_IRQ_STATUS_RAW ; 
 int IRQ_ENABLE_SET ; 
 int IRQ_EOI ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 int IRQ_STATUS ; 
 int MSI0_IRQ_ENABLE_CLR ; 
 int MSI0_IRQ_ENABLE_SET ; 
 int MSI0_IRQ_STATUS ; 
 scalar_t__ MSI_IRQ ; 
 int MSI_IRQ_OFFSET ; 
 int OB_OFFSET_HI (int) ; 
 int OB_OFFSET_INDEX (int) ; 
 int OB_SIZE ; 
 int OB_XLAT_EN_VAL ; 
 int PCIE_DBI_RO_WR_EN ; 
 int PCIE_MISC_CONTROL_1_OFF ; 
 int PCI_BASE_ADDRESS_0 ; 
 int PCI_BASE_ADDRESS_1 ; 
 int PCI_NUM_INTX ; 
 int SZ_1M ; 
 int __dw_pcie_read_dbi (struct dw_pcie*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  __dw_pcie_write_dbi (struct dw_pcie*,int /*<<< orphan*/ ,int,int,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,int,int,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,int) ; 
 int /*<<< orphan*/  generic_handle_irq (int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 int irq_linear_revmap (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_chip_data (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ks_dw_pcie_legacy_irq_chip ; 
 int readl (int) ; 
 struct dw_pcie* to_dw_pcie_from_pp (struct pcie_port*) ; 
 struct keystone_pcie* to_keystone_pcie (struct dw_pcie*) ; 
 int /*<<< orphan*/  writel (int,int) ; 

__attribute__((used)) static inline void dw_pcie_writel_dbi(struct dw_pcie *pci, u32 reg, u32 val)
{
	__dw_pcie_write_dbi(pci, pci->dbi_base, reg, 0x4, val);
}

__attribute__((used)) static inline u32 dw_pcie_readl_dbi(struct dw_pcie *pci, u32 reg)
{
	return __dw_pcie_read_dbi(pci, pci->dbi_base, reg, 0x4);
}

__attribute__((used)) static inline void dw_pcie_writew_dbi(struct dw_pcie *pci, u32 reg, u16 val)
{
	__dw_pcie_write_dbi(pci, pci->dbi_base, reg, 0x2, val);
}

__attribute__((used)) static inline u16 dw_pcie_readw_dbi(struct dw_pcie *pci, u32 reg)
{
	return __dw_pcie_read_dbi(pci, pci->dbi_base, reg, 0x2);
}

__attribute__((used)) static inline void dw_pcie_writeb_dbi(struct dw_pcie *pci, u32 reg, u8 val)
{
	__dw_pcie_write_dbi(pci, pci->dbi_base, reg, 0x1, val);
}

__attribute__((used)) static inline u8 dw_pcie_readb_dbi(struct dw_pcie *pci, u32 reg)
{
	return __dw_pcie_read_dbi(pci, pci->dbi_base, reg, 0x1);
}

__attribute__((used)) static inline void dw_pcie_writel_dbi2(struct dw_pcie *pci, u32 reg, u32 val)
{
	__dw_pcie_write_dbi(pci, pci->dbi_base2, reg, 0x4, val);
}

__attribute__((used)) static inline u32 dw_pcie_readl_dbi2(struct dw_pcie *pci, u32 reg)
{
	return __dw_pcie_read_dbi(pci, pci->dbi_base2, reg, 0x4);
}

__attribute__((used)) static inline void dw_pcie_dbi_ro_wr_en(struct dw_pcie *pci)
{
	u32 reg;
	u32 val;

	reg = PCIE_MISC_CONTROL_1_OFF;
	val = dw_pcie_readl_dbi(pci, reg);
	val |= PCIE_DBI_RO_WR_EN;
	dw_pcie_writel_dbi(pci, reg, val);
}

__attribute__((used)) static inline void dw_pcie_dbi_ro_wr_dis(struct dw_pcie *pci)
{
	u32 reg;
	u32 val;

	reg = PCIE_MISC_CONTROL_1_OFF;
	val = dw_pcie_readl_dbi(pci, reg);
	val &= ~PCIE_DBI_RO_WR_EN;
	dw_pcie_writel_dbi(pci, reg, val);
}

__attribute__((used)) static inline irqreturn_t dw_handle_msi_irq(struct pcie_port *pp)
{
	return IRQ_NONE;
}

__attribute__((used)) static inline void dw_pcie_msi_init(struct pcie_port *pp)
{
}

__attribute__((used)) static inline void dw_pcie_free_msi(struct pcie_port *pp)
{
}

__attribute__((used)) static inline void dw_pcie_setup_rc(struct pcie_port *pp)
{
}

__attribute__((used)) static inline int dw_pcie_host_init(struct pcie_port *pp)
{
	return 0;
}

__attribute__((used)) static inline int dw_pcie_allocate_domains(struct pcie_port *pp)
{
	return 0;
}

__attribute__((used)) static inline void dw_pcie_ep_linkup(struct dw_pcie_ep *ep)
{
}

__attribute__((used)) static inline int dw_pcie_ep_init(struct dw_pcie_ep *ep)
{
	return 0;
}

__attribute__((used)) static inline void dw_pcie_ep_exit(struct dw_pcie_ep *ep)
{
}

__attribute__((used)) static inline int dw_pcie_ep_raise_legacy_irq(struct dw_pcie_ep *ep, u8 func_no)
{
	return 0;
}

__attribute__((used)) static inline int dw_pcie_ep_raise_msi_irq(struct dw_pcie_ep *ep, u8 func_no,
					   u8 interrupt_num)
{
	return 0;
}

__attribute__((used)) static inline int dw_pcie_ep_raise_msix_irq(struct dw_pcie_ep *ep, u8 func_no,
					   u16 interrupt_num)
{
	return 0;
}

__attribute__((used)) static inline void dw_pcie_ep_reset_bar(struct dw_pcie *pci, enum pci_barno bar)
{
}

__attribute__((used)) static inline void update_reg_offset_bit_pos(u32 offset, u32 *reg_offset,
					     u32 *bit_pos)
{
	*reg_offset = offset % 8;
	*bit_pos = offset >> 3;
}

phys_addr_t ks_dw_pcie_get_msi_addr(struct pcie_port *pp)
{
	struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
	struct keystone_pcie *ks_pcie = to_keystone_pcie(pci);

	return ks_pcie->app.start + MSI_IRQ;
}

__attribute__((used)) static u32 ks_dw_app_readl(struct keystone_pcie *ks_pcie, u32 offset)
{
	return readl(ks_pcie->va_app_base + offset);
}

__attribute__((used)) static void ks_dw_app_writel(struct keystone_pcie *ks_pcie, u32 offset, u32 val)
{
	writel(val, ks_pcie->va_app_base + offset);
}

void ks_dw_pcie_handle_msi_irq(struct keystone_pcie *ks_pcie, int offset)
{
	struct dw_pcie *pci = ks_pcie->pci;
	struct pcie_port *pp = &pci->pp;
	struct device *dev = pci->dev;
	u32 pending, vector;
	int src, virq;

	pending = ks_dw_app_readl(ks_pcie, MSI0_IRQ_STATUS + (offset << 4));

	/*
	 * MSI0 status bit 0-3 shows vectors 0, 8, 16, 24, MSI1 status bit
	 * shows 1, 9, 17, 25 and so forth
	 */
	for (src = 0; src < 4; src++) {
		if (BIT(src) & pending) {
			vector = offset + (src << 3);
			virq = irq_linear_revmap(pp->irq_domain, vector);
			dev_dbg(dev, "irq: bit %d, vector %d, virq %d\n",
				src, vector, virq);
			generic_handle_irq(virq);
		}
	}
}

void ks_dw_pcie_msi_irq_ack(int irq, struct pcie_port *pp)
{
	u32 reg_offset, bit_pos;
	struct keystone_pcie *ks_pcie;
	struct dw_pcie *pci;

	pci = to_dw_pcie_from_pp(pp);
	ks_pcie = to_keystone_pcie(pci);
	update_reg_offset_bit_pos(irq, &reg_offset, &bit_pos);

	ks_dw_app_writel(ks_pcie, MSI0_IRQ_STATUS + (reg_offset << 4),
			 BIT(bit_pos));
	ks_dw_app_writel(ks_pcie, IRQ_EOI, reg_offset + MSI_IRQ_OFFSET);
}

void ks_dw_pcie_msi_set_irq(struct pcie_port *pp, int irq)
{
	u32 reg_offset, bit_pos;
	struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
	struct keystone_pcie *ks_pcie = to_keystone_pcie(pci);

	update_reg_offset_bit_pos(irq, &reg_offset, &bit_pos);
	ks_dw_app_writel(ks_pcie, MSI0_IRQ_ENABLE_SET + (reg_offset << 4),
			 BIT(bit_pos));
}

void ks_dw_pcie_msi_clear_irq(struct pcie_port *pp, int irq)
{
	u32 reg_offset, bit_pos;
	struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
	struct keystone_pcie *ks_pcie = to_keystone_pcie(pci);

	update_reg_offset_bit_pos(irq, &reg_offset, &bit_pos);
	ks_dw_app_writel(ks_pcie, MSI0_IRQ_ENABLE_CLR + (reg_offset << 4),
			 BIT(bit_pos));
}

int ks_dw_pcie_msi_host_init(struct pcie_port *pp)
{
	return dw_pcie_allocate_domains(pp);
}

void ks_dw_pcie_enable_legacy_irqs(struct keystone_pcie *ks_pcie)
{
	int i;

	for (i = 0; i < PCI_NUM_INTX; i++)
		ks_dw_app_writel(ks_pcie, IRQ_ENABLE_SET + (i << 4), 0x1);
}

void ks_dw_pcie_handle_legacy_irq(struct keystone_pcie *ks_pcie, int offset)
{
	struct dw_pcie *pci = ks_pcie->pci;
	struct device *dev = pci->dev;
	u32 pending;
	int virq;

	pending = ks_dw_app_readl(ks_pcie, IRQ_STATUS + (offset << 4));

	if (BIT(0) & pending) {
		virq = irq_linear_revmap(ks_pcie->legacy_irq_domain, offset);
		dev_dbg(dev, ": irq: irq_offset %d, virq %d\n", offset, virq);
		generic_handle_irq(virq);
	}

	/* EOI the INTx interrupt */
	ks_dw_app_writel(ks_pcie, IRQ_EOI, offset);
}

void ks_dw_pcie_enable_error_irq(struct keystone_pcie *ks_pcie)
{
	ks_dw_app_writel(ks_pcie, ERR_IRQ_ENABLE_SET, ERR_IRQ_ALL);
}

irqreturn_t ks_dw_pcie_handle_error_irq(struct keystone_pcie *ks_pcie)
{
	u32 status;

	status = ks_dw_app_readl(ks_pcie, ERR_IRQ_STATUS_RAW) & ERR_IRQ_ALL;
	if (!status)
		return IRQ_NONE;

	if (status & ERR_FATAL_IRQ)
		dev_err(ks_pcie->pci->dev, "fatal error (status %#010x)\n",
			status);

	/* Ack the IRQ; status bits are RW1C */
	ks_dw_app_writel(ks_pcie, ERR_IRQ_STATUS, status);
	return IRQ_HANDLED;
}

__attribute__((used)) static void ks_dw_pcie_ack_legacy_irq(struct irq_data *d)
{
}

__attribute__((used)) static void ks_dw_pcie_mask_legacy_irq(struct irq_data *d)
{
}

__attribute__((used)) static void ks_dw_pcie_unmask_legacy_irq(struct irq_data *d)
{
}

__attribute__((used)) static int ks_dw_pcie_init_legacy_irq_map(struct irq_domain *d,
				unsigned int irq, irq_hw_number_t hw_irq)
{
	irq_set_chip_and_handler(irq, &ks_dw_pcie_legacy_irq_chip,
				 handle_level_irq);
	irq_set_chip_data(irq, d->host_data);

	return 0;
}

__attribute__((used)) static void ks_dw_pcie_set_dbi_mode(struct keystone_pcie *ks_pcie)
{
	u32 val;

	val = ks_dw_app_readl(ks_pcie, CMD_STATUS);
	ks_dw_app_writel(ks_pcie, CMD_STATUS, DBI_CS2_EN_VAL | val);

	do {
		val = ks_dw_app_readl(ks_pcie, CMD_STATUS);
	} while (!(val & DBI_CS2_EN_VAL));
}

__attribute__((used)) static void ks_dw_pcie_clear_dbi_mode(struct keystone_pcie *ks_pcie)
{
	u32 val;

	val = ks_dw_app_readl(ks_pcie, CMD_STATUS);
	ks_dw_app_writel(ks_pcie, CMD_STATUS, ~DBI_CS2_EN_VAL & val);

	do {
		val = ks_dw_app_readl(ks_pcie, CMD_STATUS);
	} while (val & DBI_CS2_EN_VAL);
}

void ks_dw_pcie_setup_rc_app_regs(struct keystone_pcie *ks_pcie)
{
	struct dw_pcie *pci = ks_pcie->pci;
	struct pcie_port *pp = &pci->pp;
	u32 start = pp->mem->start, end = pp->mem->end;
	int i, tr_size;
	u32 val;

	/* Disable BARs for inbound access */
	ks_dw_pcie_set_dbi_mode(ks_pcie);
	dw_pcie_writel_dbi(pci, PCI_BASE_ADDRESS_0, 0);
	dw_pcie_writel_dbi(pci, PCI_BASE_ADDRESS_1, 0);
	ks_dw_pcie_clear_dbi_mode(ks_pcie);

	/* Set outbound translation size per window division */
	ks_dw_app_writel(ks_pcie, OB_SIZE, CFG_PCIM_WIN_SZ_IDX & 0x7);

	tr_size = (1 << (CFG_PCIM_WIN_SZ_IDX & 0x7)) * SZ_1M;

	/* Using Direct 1:1 mapping of RC <-> PCI memory space */
	for (i = 0; (i < CFG_PCIM_WIN_CNT) && (start < end); i++) {
		ks_dw_app_writel(ks_pcie, OB_OFFSET_INDEX(i), start | 1);
		ks_dw_app_writel(ks_pcie, OB_OFFSET_HI(i), 0);
		start += tr_size;
	}

	/* Enable OB translation */
	val = ks_dw_app_readl(ks_pcie, CMD_STATUS);
	ks_dw_app_writel(ks_pcie, CMD_STATUS, OB_XLAT_EN_VAL | val);
}

