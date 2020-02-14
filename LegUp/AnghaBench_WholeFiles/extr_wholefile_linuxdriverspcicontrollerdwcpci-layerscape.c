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
typedef  int u16 ;
struct pcie_port {int dummy; } ;
struct ls_pcie {int index; int /*<<< orphan*/ * scfg; struct dw_pcie* pci; TYPE_1__* drvdata; scalar_t__ lut; } ;
struct dw_pcie_ep {int dummy; } ;
struct dw_pcie {struct device* dev; scalar_t__ dbi_base; scalar_t__ dbi_base2; } ;
struct device_node {int dummy; } ;
struct device {struct device_node* of_node; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum pci_barno { ____Placeholder_pci_barno } pci_barno ;
struct TYPE_2__ {int ltssm_shift; scalar_t__ lut_dbg; } ;

/* Variables and functions */
 int /*<<< orphan*/  DW_PCIE_REGION_OUTBOUND ; 
 int EINVAL ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ *) ; 
 int LTSSM_PCIE_L0 ; 
 int LTSSM_STATE_MASK ; 
 int LTSSM_STATE_SHIFT ; 
 scalar_t__ PCIE_ABSERR ; 
 int PCIE_ABSERR_SETTING ; 
 int PCIE_DBI_RO_WR_EN ; 
 int PCIE_IATU_NUM ; 
 int PCIE_MISC_CONTROL_1_OFF ; 
 scalar_t__ PCIE_STRFMR1 ; 
 scalar_t__ PCI_HEADER_TYPE ; 
 int PCI_HEADER_TYPE_BRIDGE ; 
 int PTR_ERR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SCFG_PEXMSCPORTSR (int) ; 
 int __dw_pcie_read_dbi (struct dw_pcie*,scalar_t__,int,int) ; 
 int /*<<< orphan*/  __dw_pcie_write_dbi (struct dw_pcie*,scalar_t__,int,int,int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dw_pcie_disable_atu (struct dw_pcie*,int,int /*<<< orphan*/ ) ; 
 int ioread32 (scalar_t__) ; 
 int ioread8 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite8 (int,scalar_t__) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ of_property_read_u32_array (struct device_node*,char*,int*,int) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/ * syscon_regmap_lookup_by_phandle (struct device_node*,char*) ; 
 struct dw_pcie* to_dw_pcie_from_pp (struct pcie_port*) ; 
 struct ls_pcie* to_ls_pcie (struct dw_pcie*) ; 

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

__attribute__((used)) static bool ls_pcie_is_bridge(struct ls_pcie *pcie)
{
	struct dw_pcie *pci = pcie->pci;
	u32 header_type;

	header_type = ioread8(pci->dbi_base + PCI_HEADER_TYPE);
	header_type &= 0x7f;

	return header_type == PCI_HEADER_TYPE_BRIDGE;
}

__attribute__((used)) static void ls_pcie_clear_multifunction(struct ls_pcie *pcie)
{
	struct dw_pcie *pci = pcie->pci;

	iowrite8(PCI_HEADER_TYPE_BRIDGE, pci->dbi_base + PCI_HEADER_TYPE);
}

__attribute__((used)) static void ls_pcie_drop_msg_tlp(struct ls_pcie *pcie)
{
	u32 val;
	struct dw_pcie *pci = pcie->pci;

	val = ioread32(pci->dbi_base + PCIE_STRFMR1);
	val &= 0xDFFFFFFF;
	iowrite32(val, pci->dbi_base + PCIE_STRFMR1);
}

__attribute__((used)) static void ls_pcie_disable_outbound_atus(struct ls_pcie *pcie)
{
	int i;

	for (i = 0; i < PCIE_IATU_NUM; i++)
		dw_pcie_disable_atu(pcie->pci, i, DW_PCIE_REGION_OUTBOUND);
}

__attribute__((used)) static int ls1021_pcie_link_up(struct dw_pcie *pci)
{
	u32 state;
	struct ls_pcie *pcie = to_ls_pcie(pci);

	if (!pcie->scfg)
		return 0;

	regmap_read(pcie->scfg, SCFG_PEXMSCPORTSR(pcie->index), &state);
	state = (state >> LTSSM_STATE_SHIFT) & LTSSM_STATE_MASK;

	if (state < LTSSM_PCIE_L0)
		return 0;

	return 1;
}

__attribute__((used)) static int ls_pcie_link_up(struct dw_pcie *pci)
{
	struct ls_pcie *pcie = to_ls_pcie(pci);
	u32 state;

	state = (ioread32(pcie->lut + pcie->drvdata->lut_dbg) >>
		 pcie->drvdata->ltssm_shift) &
		 LTSSM_STATE_MASK;

	if (state < LTSSM_PCIE_L0)
		return 0;

	return 1;
}

__attribute__((used)) static void ls_pcie_fix_error_response(struct ls_pcie *pcie)
{
	struct dw_pcie *pci = pcie->pci;

	iowrite32(PCIE_ABSERR_SETTING, pci->dbi_base + PCIE_ABSERR);
}

__attribute__((used)) static int ls_pcie_host_init(struct pcie_port *pp)
{
	struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
	struct ls_pcie *pcie = to_ls_pcie(pci);

	/*
	 * Disable outbound windows configured by the bootloader to avoid
	 * one transaction hitting multiple outbound windows.
	 * dw_pcie_setup_rc() will reconfigure the outbound windows.
	 */
	ls_pcie_disable_outbound_atus(pcie);
	ls_pcie_fix_error_response(pcie);

	dw_pcie_dbi_ro_wr_en(pci);
	ls_pcie_clear_multifunction(pcie);
	dw_pcie_dbi_ro_wr_dis(pci);

	ls_pcie_drop_msg_tlp(pcie);

	dw_pcie_setup_rc(pp);

	return 0;
}

__attribute__((used)) static int ls1021_pcie_host_init(struct pcie_port *pp)
{
	struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
	struct ls_pcie *pcie = to_ls_pcie(pci);
	struct device *dev = pci->dev;
	u32 index[2];
	int ret;

	pcie->scfg = syscon_regmap_lookup_by_phandle(dev->of_node,
						     "fsl,pcie-scfg");
	if (IS_ERR(pcie->scfg)) {
		ret = PTR_ERR(pcie->scfg);
		dev_err(dev, "No syscfg phandle specified\n");
		pcie->scfg = NULL;
		return ret;
	}

	if (of_property_read_u32_array(dev->of_node,
				       "fsl,pcie-scfg", index, 2)) {
		pcie->scfg = NULL;
		return -EINVAL;
	}
	pcie->index = index[1];

	return ls_pcie_host_init(pp);
}

__attribute__((used)) static int ls_pcie_msi_host_init(struct pcie_port *pp)
{
	struct dw_pcie *pci = to_dw_pcie_from_pp(pp);
	struct device *dev = pci->dev;
	struct device_node *np = dev->of_node;
	struct device_node *msi_node;

	/*
	 * The MSI domain is set by the generic of_msi_configure().  This
	 * .msi_host_init() function keeps us from doing the default MSI
	 * domain setup in dw_pcie_host_init() and also enforces the
	 * requirement that "msi-parent" exists.
	 */
	msi_node = of_parse_phandle(np, "msi-parent", 0);
	if (!msi_node) {
		dev_err(dev, "failed to find msi-parent\n");
		return -EINVAL;
	}

	return 0;
}

