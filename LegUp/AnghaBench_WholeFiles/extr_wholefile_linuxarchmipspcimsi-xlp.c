#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int uint64_t ;
typedef  unsigned int uint32_t ;
typedef  int u32 ;
struct xlp_msi_data {unsigned int msi_enabled_mask; int lnkbase; unsigned int msi_alloc_mask; unsigned int msix_alloc_mask; int /*<<< orphan*/  msi_lock; TYPE_1__* node; } ;
struct pci_dev {int /*<<< orphan*/  devfn; int /*<<< orphan*/  dev; } ;
struct msi_msg {int address_hi; int address_lo; int data; } ;
struct TYPE_5__ {scalar_t__ is_msix; } ;
struct msi_desc {TYPE_2__ msi_attrib; } ;
struct irq_data {int irq; } ;
struct TYPE_6__ {int /*<<< orphan*/  picbase; } ;
struct TYPE_4__ {int /*<<< orphan*/  picbase; } ;

/* Variables and functions */
 int ENOMEM ; 
 int MSIX_LINK_ADDR (int,int) ; 
 int MSI_ADDR_SZ ; 
 int MSI_LINK_ADDR (int,int) ; 
 int NLM_MSIX_VEC_BASE ; 
 int NLM_MSI_VEC_BASE ; 
 int PCIE_9XX_BRIDGE_MSIX_ADDR_BASE ; 
 int PCIE_9XX_BRIDGE_MSIX_ADDR_LIMIT ; 
 int PCIE_9XX_INT_EN0 ; 
 unsigned int PCIE_9XX_MSIX_STATUSX (int) ; 
 int PCIE_9XX_MSI_EN ; 
 int PCIE_9XX_MSI_STATUS ; 
 int PCIE_BRIDGE_MSIX_ADDR_BASE ; 
 int PCIE_BRIDGE_MSIX_ADDR_LIMIT ; 
 int PCIE_BRIDGE_MSI_ADDRH ; 
 int PCIE_BRIDGE_MSI_ADDRL ; 
 int PCIE_BRIDGE_MSI_CAP ; 
 int PCIE_INT_EN0 ; 
 unsigned int PCIE_MSIX_STATUS ; 
 int PCIE_MSI_EN ; 
 int PCIE_MSI_STATUS ; 
 int PCIE_NLINKS ; 
 int PCI_FUNC (int /*<<< orphan*/ ) ; 
 int PCI_SLOT (int /*<<< orphan*/ ) ; 
 int PIC_9XX_IRT_PCIE_LINK_INDEX (int) ; 
 int PIC_IRT_PCIE_LINK_INDEX (int) ; 
 int /*<<< orphan*/  PIC_IRT_PCIE_MSIX_INDEX (int) ; 
 int PIC_PCIE_LINK_MSI_IRQ (int) ; 
 int PIC_PCIE_MSIX_IRQ (int) ; 
 int XLP_MSIVEC_PER_LINK ; 
 int XLP_MSIXVEC_PER_LINK ; 
 int XLP_MSIXVEC_TOTAL ; 
 scalar_t__ cpu_is_xlp9xx () ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int fls (unsigned int) ; 
 struct xlp_msi_data* irq_data_get_irq_chip_data (struct irq_data*) ; 
 struct xlp_msi_data* irq_get_chip_data (int) ; 
 int irq_set_msi_desc (int,struct msi_desc*) ; 
 TYPE_3__* nlm_get_node (int) ; 
 int nlm_get_pcie_base (int,int) ; 
 int nlm_irq_to_xirq (int,int) ; 
 int /*<<< orphan*/  nlm_pic_ack (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nlm_pic_init_irt (int /*<<< orphan*/ ,int,int,int,int) ; 
 int nlm_read_pci_reg (int,int) ; 
 int nlm_read_reg (int,int) ; 
 int /*<<< orphan*/  nlm_setup_pic_irq (int,int,int,int) ; 
 int nlm_threads_per_node () ; 
 int /*<<< orphan*/  nlm_write_pci_reg (int,int,int) ; 
 int /*<<< orphan*/  nlm_write_reg (int,int,int) ; 
 int /*<<< orphan*/  pci_msi_mask_irq (struct irq_data*) ; 
 int /*<<< orphan*/  pci_write_msi_msg (int,struct msi_msg*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 struct pci_dev* xlp_get_pcie_link (struct pci_dev*) ; 

__attribute__((used)) static inline int nlm_link_msiirq(int link, int msivec)
{
	return NLM_MSI_VEC_BASE + link * XLP_MSIVEC_PER_LINK + msivec;
}

__attribute__((used)) static inline int nlm_irq_msivec(int irq)
{
	return (irq - NLM_MSI_VEC_BASE) % XLP_MSIVEC_PER_LINK;
}

__attribute__((used)) static inline int nlm_irq_msilink(int irq)
{
	int total_msivec = XLP_MSIVEC_PER_LINK * PCIE_NLINKS;

	return ((irq - NLM_MSI_VEC_BASE) % total_msivec) /
		XLP_MSIVEC_PER_LINK;
}

__attribute__((used)) static inline int nlm_link_msixirq(int link, int bit)
{
	return NLM_MSIX_VEC_BASE + link * XLP_MSIXVEC_PER_LINK + bit;
}

__attribute__((used)) static inline int nlm_irq_msixvec(int irq)
{
	return (irq - NLM_MSIX_VEC_BASE) % XLP_MSIXVEC_TOTAL;
}

__attribute__((used)) static inline int nlm_irq_msixlink(int msixvec)
{
	return msixvec / XLP_MSIXVEC_PER_LINK;
}

__attribute__((used)) static void xlp_msi_enable(struct irq_data *d)
{
	struct xlp_msi_data *md = irq_data_get_irq_chip_data(d);
	unsigned long flags;
	int vec;

	vec = nlm_irq_msivec(d->irq);
	spin_lock_irqsave(&md->msi_lock, flags);
	md->msi_enabled_mask |= 1u << vec;
	if (cpu_is_xlp9xx())
		nlm_write_reg(md->lnkbase, PCIE_9XX_MSI_EN,
				md->msi_enabled_mask);
	else
		nlm_write_reg(md->lnkbase, PCIE_MSI_EN, md->msi_enabled_mask);
	spin_unlock_irqrestore(&md->msi_lock, flags);
}

__attribute__((used)) static void xlp_msi_disable(struct irq_data *d)
{
	struct xlp_msi_data *md = irq_data_get_irq_chip_data(d);
	unsigned long flags;
	int vec;

	vec = nlm_irq_msivec(d->irq);
	spin_lock_irqsave(&md->msi_lock, flags);
	md->msi_enabled_mask &= ~(1u << vec);
	if (cpu_is_xlp9xx())
		nlm_write_reg(md->lnkbase, PCIE_9XX_MSI_EN,
				md->msi_enabled_mask);
	else
		nlm_write_reg(md->lnkbase, PCIE_MSI_EN, md->msi_enabled_mask);
	spin_unlock_irqrestore(&md->msi_lock, flags);
}

__attribute__((used)) static void xlp_msi_mask_ack(struct irq_data *d)
{
	struct xlp_msi_data *md = irq_data_get_irq_chip_data(d);
	int link, vec;

	link = nlm_irq_msilink(d->irq);
	vec = nlm_irq_msivec(d->irq);
	xlp_msi_disable(d);

	/* Ack MSI on bridge */
	if (cpu_is_xlp9xx())
		nlm_write_reg(md->lnkbase, PCIE_9XX_MSI_STATUS, 1u << vec);
	else
		nlm_write_reg(md->lnkbase, PCIE_MSI_STATUS, 1u << vec);

}

__attribute__((used)) static void xlp_msix_mask_ack(struct irq_data *d)
{
	struct xlp_msi_data *md;
	int link, msixvec;
	uint32_t status_reg, bit;

	msixvec = nlm_irq_msixvec(d->irq);
	link = nlm_irq_msixlink(msixvec);
	pci_msi_mask_irq(d);
	md = irq_data_get_irq_chip_data(d);

	/* Ack MSI on bridge */
	if (cpu_is_xlp9xx()) {
		status_reg = PCIE_9XX_MSIX_STATUSX(link);
		bit = msixvec % XLP_MSIXVEC_PER_LINK;
	} else {
		status_reg = PCIE_MSIX_STATUS;
		bit = msixvec;
	}
	nlm_write_reg(md->lnkbase, status_reg, 1u << bit);

	if (!cpu_is_xlp9xx())
		nlm_pic_ack(md->node->picbase,
				PIC_IRT_PCIE_MSIX_INDEX(msixvec));
}

void arch_teardown_msi_irq(unsigned int irq)
{
}

__attribute__((used)) static void xlp_config_link_msi(uint64_t lnkbase, int lirq, uint64_t msiaddr)
{
	u32 val;

	if (cpu_is_xlp9xx()) {
		val = nlm_read_reg(lnkbase, PCIE_9XX_INT_EN0);
		if ((val & 0x200) == 0) {
			val |= 0x200;		/* MSI Interrupt enable */
			nlm_write_reg(lnkbase, PCIE_9XX_INT_EN0, val);
		}
	} else {
		val = nlm_read_reg(lnkbase, PCIE_INT_EN0);
		if ((val & 0x200) == 0) {
			val |= 0x200;
			nlm_write_reg(lnkbase, PCIE_INT_EN0, val);
		}
	}

	val = nlm_read_reg(lnkbase, 0x1);	/* CMD */
	if ((val & 0x0400) == 0) {
		val |= 0x0400;
		nlm_write_reg(lnkbase, 0x1, val);
	}

	/* Update IRQ in the PCI irq reg */
	val = nlm_read_pci_reg(lnkbase, 0xf);
	val &= ~0x1fu;
	val |= (1 << 8) | lirq;
	nlm_write_pci_reg(lnkbase, 0xf, val);

	/* MSI addr */
	nlm_write_reg(lnkbase, PCIE_BRIDGE_MSI_ADDRH, msiaddr >> 32);
	nlm_write_reg(lnkbase, PCIE_BRIDGE_MSI_ADDRL, msiaddr & 0xffffffff);

	/* MSI cap for bridge */
	val = nlm_read_reg(lnkbase, PCIE_BRIDGE_MSI_CAP);
	if ((val & (1 << 16)) == 0) {
		val |= 0xb << 16;		/* mmc32, msi enable */
		nlm_write_reg(lnkbase, PCIE_BRIDGE_MSI_CAP, val);
	}
}

__attribute__((used)) static int xlp_setup_msi(uint64_t lnkbase, int node, int link,
	struct msi_desc *desc)
{
	struct xlp_msi_data *md;
	struct msi_msg msg;
	unsigned long flags;
	int msivec, irt, lirq, xirq, ret;
	uint64_t msiaddr;

	/* Get MSI data for the link */
	lirq = PIC_PCIE_LINK_MSI_IRQ(link);
	xirq = nlm_irq_to_xirq(node, nlm_link_msiirq(link, 0));
	md = irq_get_chip_data(xirq);
	msiaddr = MSI_LINK_ADDR(node, link);

	spin_lock_irqsave(&md->msi_lock, flags);
	if (md->msi_alloc_mask == 0) {
		xlp_config_link_msi(lnkbase, lirq, msiaddr);
		/* switch the link IRQ to MSI range */
		if (cpu_is_xlp9xx())
			irt = PIC_9XX_IRT_PCIE_LINK_INDEX(link);
		else
			irt = PIC_IRT_PCIE_LINK_INDEX(link);
		nlm_setup_pic_irq(node, lirq, lirq, irt);
		nlm_pic_init_irt(nlm_get_node(node)->picbase, irt, lirq,
				 node * nlm_threads_per_node(), 1 /*en */);
	}

	/* allocate a MSI vec, and tell the bridge about it */
	msivec = fls(md->msi_alloc_mask);
	if (msivec == XLP_MSIVEC_PER_LINK) {
		spin_unlock_irqrestore(&md->msi_lock, flags);
		return -ENOMEM;
	}
	md->msi_alloc_mask |= (1u << msivec);
	spin_unlock_irqrestore(&md->msi_lock, flags);

	msg.address_hi = msiaddr >> 32;
	msg.address_lo = msiaddr & 0xffffffff;
	msg.data = 0xc00 | msivec;

	xirq = xirq + msivec;		/* msi mapped to global irq space */
	ret = irq_set_msi_desc(xirq, desc);
	if (ret < 0)
		return ret;

	pci_write_msi_msg(xirq, &msg);
	return 0;
}

__attribute__((used)) static void xlp_config_link_msix(uint64_t lnkbase, int lirq, uint64_t msixaddr)
{
	u32 val;

	val = nlm_read_reg(lnkbase, 0x2C);
	if ((val & 0x80000000U) == 0) {
		val |= 0x80000000U;
		nlm_write_reg(lnkbase, 0x2C, val);
	}

	if (cpu_is_xlp9xx()) {
		val = nlm_read_reg(lnkbase, PCIE_9XX_INT_EN0);
		if ((val & 0x200) == 0) {
			val |= 0x200;		/* MSI Interrupt enable */
			nlm_write_reg(lnkbase, PCIE_9XX_INT_EN0, val);
		}
	} else {
		val = nlm_read_reg(lnkbase, PCIE_INT_EN0);
		if ((val & 0x200) == 0) {
			val |= 0x200;		/* MSI Interrupt enable */
			nlm_write_reg(lnkbase, PCIE_INT_EN0, val);
		}
	}

	val = nlm_read_reg(lnkbase, 0x1);	/* CMD */
	if ((val & 0x0400) == 0) {
		val |= 0x0400;
		nlm_write_reg(lnkbase, 0x1, val);
	}

	/* Update IRQ in the PCI irq reg */
	val = nlm_read_pci_reg(lnkbase, 0xf);
	val &= ~0x1fu;
	val |= (1 << 8) | lirq;
	nlm_write_pci_reg(lnkbase, 0xf, val);

	if (cpu_is_xlp9xx()) {
		/* MSI-X addresses */
		nlm_write_reg(lnkbase, PCIE_9XX_BRIDGE_MSIX_ADDR_BASE,
				msixaddr >> 8);
		nlm_write_reg(lnkbase, PCIE_9XX_BRIDGE_MSIX_ADDR_LIMIT,
				(msixaddr + MSI_ADDR_SZ) >> 8);
	} else {
		/* MSI-X addresses */
		nlm_write_reg(lnkbase, PCIE_BRIDGE_MSIX_ADDR_BASE,
				msixaddr >> 8);
		nlm_write_reg(lnkbase, PCIE_BRIDGE_MSIX_ADDR_LIMIT,
				(msixaddr + MSI_ADDR_SZ) >> 8);
	}
}

__attribute__((used)) static int xlp_setup_msix(uint64_t lnkbase, int node, int link,
	struct msi_desc *desc)
{
	struct xlp_msi_data *md;
	struct msi_msg msg;
	unsigned long flags;
	int t, msixvec, lirq, xirq, ret;
	uint64_t msixaddr;

	/* Get MSI data for the link */
	lirq = PIC_PCIE_MSIX_IRQ(link);
	xirq = nlm_irq_to_xirq(node, nlm_link_msixirq(link, 0));
	md = irq_get_chip_data(xirq);
	msixaddr = MSIX_LINK_ADDR(node, link);

	spin_lock_irqsave(&md->msi_lock, flags);
	/* switch the PCIe link to MSI-X mode at the first alloc */
	if (md->msix_alloc_mask == 0)
		xlp_config_link_msix(lnkbase, lirq, msixaddr);

	/* allocate a MSI-X vec, and tell the bridge about it */
	t = fls(md->msix_alloc_mask);
	if (t == XLP_MSIXVEC_PER_LINK) {
		spin_unlock_irqrestore(&md->msi_lock, flags);
		return -ENOMEM;
	}
	md->msix_alloc_mask |= (1u << t);
	spin_unlock_irqrestore(&md->msi_lock, flags);

	xirq += t;
	msixvec = nlm_irq_msixvec(xirq);

	msg.address_hi = msixaddr >> 32;
	msg.address_lo = msixaddr & 0xffffffff;
	msg.data = 0xc00 | msixvec;

	ret = irq_set_msi_desc(xirq, desc);
	if (ret < 0)
		return ret;

	pci_write_msi_msg(xirq, &msg);
	return 0;
}

int arch_setup_msi_irq(struct pci_dev *dev, struct msi_desc *desc)
{
	struct pci_dev *lnkdev;
	uint64_t lnkbase;
	int node, link, slot;

	lnkdev = xlp_get_pcie_link(dev);
	if (lnkdev == NULL) {
		dev_err(&dev->dev, "Could not find bridge\n");
		return 1;
	}
	slot = PCI_SLOT(lnkdev->devfn);
	link = PCI_FUNC(lnkdev->devfn);
	node = slot / 8;
	lnkbase = nlm_get_pcie_base(node, link);

	if (desc->msi_attrib.is_msix)
		return xlp_setup_msix(lnkbase, node, link, desc);
	else
		return xlp_setup_msi(lnkbase, node, link, desc);
}

