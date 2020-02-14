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
typedef  int /*<<< orphan*/  u8 ;
typedef  unsigned long long u64 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct phy {int /*<<< orphan*/  dev; } ;
struct device_node {int dummy; } ;
struct device_link {int dummy; } ;
struct device {struct device_node* of_node; } ;
struct cdns_pcie {int reg_base; int phy_count; struct device_link** link; struct phy** phy; TYPE_1__* mem_res; int /*<<< orphan*/  bus; scalar_t__ is_rc; } ;
struct TYPE_2__ {scalar_t__ start; } ;

/* Variables and functions */
 int CDNS_PCIE_AT_OB_REGION_CPU_ADDR0 (int) ; 
 int CDNS_PCIE_AT_OB_REGION_CPU_ADDR0_NBITS (int) ; 
 int CDNS_PCIE_AT_OB_REGION_CPU_ADDR1 (int) ; 
 int CDNS_PCIE_AT_OB_REGION_DESC0 (int) ; 
 int CDNS_PCIE_AT_OB_REGION_DESC0_DEVFN (int /*<<< orphan*/ ) ; 
 int CDNS_PCIE_AT_OB_REGION_DESC0_HARDCODED_RID ; 
 int CDNS_PCIE_AT_OB_REGION_DESC0_TYPE_IO ; 
 int CDNS_PCIE_AT_OB_REGION_DESC0_TYPE_MEM ; 
 int CDNS_PCIE_AT_OB_REGION_DESC0_TYPE_NORMAL_MSG ; 
 int CDNS_PCIE_AT_OB_REGION_DESC1 (int) ; 
 int CDNS_PCIE_AT_OB_REGION_DESC1_BUS (int /*<<< orphan*/ ) ; 
 int CDNS_PCIE_AT_OB_REGION_PCI_ADDR0 (int) ; 
 int CDNS_PCIE_AT_OB_REGION_PCI_ADDR0_NBITS (int) ; 
 int CDNS_PCIE_AT_OB_REGION_PCI_ADDR1 (int) ; 
 int CDNS_PCIE_EP_FUNC_BASE (int /*<<< orphan*/ ) ; 
 int CDNS_PCIE_RP_BASE ; 
 int /*<<< orphan*/  DL_FLAG_STATELESS ; 
 int EINVAL ; 
 int ENOMEM ; 
 int GENMASK (int,int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct phy*) ; 
 int PTR_ERR (struct phy*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 struct device_link* device_link_add (struct device*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  device_link_del (struct device_link*) ; 
 void* devm_kcalloc (struct device*,int,int,int /*<<< orphan*/ ) ; 
 struct phy* devm_phy_get (struct device*,char const*) ; 
 int /*<<< orphan*/  devm_phy_put (struct device*,struct phy*) ; 
 unsigned long long fls64 (size_t) ; 
 int ilog2 (unsigned long long) ; 
 int lower_32_bits (unsigned long long) ; 
 int of_property_count_strings (struct device_node*,char*) ; 
 int /*<<< orphan*/  of_property_read_string_index (struct device_node*,char*,int,char const**) ; 
 int /*<<< orphan*/  phy_exit (struct phy*) ; 
 int phy_init (struct phy*) ; 
 int /*<<< orphan*/  phy_power_off (struct phy*) ; 
 int phy_power_on (struct phy*) ; 
 int /*<<< orphan*/  readb (int) ; 
 int readl (int) ; 
 int /*<<< orphan*/  readw (int) ; 
 int upper_32_bits (unsigned long long) ; 
 int /*<<< orphan*/  writeb (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  writel (int,int) ; 
 int /*<<< orphan*/  writew (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline void cdns_pcie_writeb(struct cdns_pcie *pcie, u32 reg, u8 value)
{
	writeb(value, pcie->reg_base + reg);
}

__attribute__((used)) static inline void cdns_pcie_writew(struct cdns_pcie *pcie, u32 reg, u16 value)
{
	writew(value, pcie->reg_base + reg);
}

__attribute__((used)) static inline void cdns_pcie_writel(struct cdns_pcie *pcie, u32 reg, u32 value)
{
	writel(value, pcie->reg_base + reg);
}

__attribute__((used)) static inline u32 cdns_pcie_readl(struct cdns_pcie *pcie, u32 reg)
{
	return readl(pcie->reg_base + reg);
}

__attribute__((used)) static inline void cdns_pcie_rp_writeb(struct cdns_pcie *pcie,
				       u32 reg, u8 value)
{
	writeb(value, pcie->reg_base + CDNS_PCIE_RP_BASE + reg);
}

__attribute__((used)) static inline void cdns_pcie_rp_writew(struct cdns_pcie *pcie,
				       u32 reg, u16 value)
{
	writew(value, pcie->reg_base + CDNS_PCIE_RP_BASE + reg);
}

__attribute__((used)) static inline void cdns_pcie_ep_fn_writeb(struct cdns_pcie *pcie, u8 fn,
					  u32 reg, u8 value)
{
	writeb(value, pcie->reg_base + CDNS_PCIE_EP_FUNC_BASE(fn) + reg);
}

__attribute__((used)) static inline void cdns_pcie_ep_fn_writew(struct cdns_pcie *pcie, u8 fn,
					  u32 reg, u16 value)
{
	writew(value, pcie->reg_base + CDNS_PCIE_EP_FUNC_BASE(fn) + reg);
}

__attribute__((used)) static inline void cdns_pcie_ep_fn_writel(struct cdns_pcie *pcie, u8 fn,
					  u32 reg, u32 value)
{
	writel(value, pcie->reg_base + CDNS_PCIE_EP_FUNC_BASE(fn) + reg);
}

__attribute__((used)) static inline u8 cdns_pcie_ep_fn_readb(struct cdns_pcie *pcie, u8 fn, u32 reg)
{
	return readb(pcie->reg_base + CDNS_PCIE_EP_FUNC_BASE(fn) + reg);
}

__attribute__((used)) static inline u16 cdns_pcie_ep_fn_readw(struct cdns_pcie *pcie, u8 fn, u32 reg)
{
	return readw(pcie->reg_base + CDNS_PCIE_EP_FUNC_BASE(fn) + reg);
}

__attribute__((used)) static inline u32 cdns_pcie_ep_fn_readl(struct cdns_pcie *pcie, u8 fn, u32 reg)
{
	return readl(pcie->reg_base + CDNS_PCIE_EP_FUNC_BASE(fn) + reg);
}

void cdns_pcie_set_outbound_region(struct cdns_pcie *pcie, u8 fn,
				   u32 r, bool is_io,
				   u64 cpu_addr, u64 pci_addr, size_t size)
{
	/*
	 * roundup_pow_of_two() returns an unsigned long, which is not suited
	 * for 64bit values.
	 */
	u64 sz = 1ULL << fls64(size - 1);
	int nbits = ilog2(sz);
	u32 addr0, addr1, desc0, desc1;

	if (nbits < 8)
		nbits = 8;

	/* Set the PCI address */
	addr0 = CDNS_PCIE_AT_OB_REGION_PCI_ADDR0_NBITS(nbits) |
		(lower_32_bits(pci_addr) & GENMASK(31, 8));
	addr1 = upper_32_bits(pci_addr);

	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_PCI_ADDR0(r), addr0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_PCI_ADDR1(r), addr1);

	/* Set the PCIe header descriptor */
	if (is_io)
		desc0 = CDNS_PCIE_AT_OB_REGION_DESC0_TYPE_IO;
	else
		desc0 = CDNS_PCIE_AT_OB_REGION_DESC0_TYPE_MEM;
	desc1 = 0;

	/*
	 * Whatever Bit [23] is set or not inside DESC0 register of the outbound
	 * PCIe descriptor, the PCI function number must be set into
	 * Bits [26:24] of DESC0 anyway.
	 *
	 * In Root Complex mode, the function number is always 0 but in Endpoint
	 * mode, the PCIe controller may support more than one function. This
	 * function number needs to be set properly into the outbound PCIe
	 * descriptor.
	 *
	 * Besides, setting Bit [23] is mandatory when in Root Complex mode:
	 * then the driver must provide the bus, resp. device, number in
	 * Bits [7:0] of DESC1, resp. Bits[31:27] of DESC0. Like the function
	 * number, the device number is always 0 in Root Complex mode.
	 *
	 * However when in Endpoint mode, we can clear Bit [23] of DESC0, hence
	 * the PCIe controller will use the captured values for the bus and
	 * device numbers.
	 */
	if (pcie->is_rc) {
		/* The device and function numbers are always 0. */
		desc0 |= CDNS_PCIE_AT_OB_REGION_DESC0_HARDCODED_RID |
			 CDNS_PCIE_AT_OB_REGION_DESC0_DEVFN(0);
		desc1 |= CDNS_PCIE_AT_OB_REGION_DESC1_BUS(pcie->bus);
	} else {
		/*
		 * Use captured values for bus and device numbers but still
		 * need to set the function number.
		 */
		desc0 |= CDNS_PCIE_AT_OB_REGION_DESC0_DEVFN(fn);
	}

	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_DESC0(r), desc0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_DESC1(r), desc1);

	/* Set the CPU address */
	cpu_addr -= pcie->mem_res->start;
	addr0 = CDNS_PCIE_AT_OB_REGION_CPU_ADDR0_NBITS(nbits) |
		(lower_32_bits(cpu_addr) & GENMASK(31, 8));
	addr1 = upper_32_bits(cpu_addr);

	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_CPU_ADDR0(r), addr0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_CPU_ADDR1(r), addr1);
}

void cdns_pcie_set_outbound_region_for_normal_msg(struct cdns_pcie *pcie, u8 fn,
						  u32 r, u64 cpu_addr)
{
	u32 addr0, addr1, desc0, desc1;

	desc0 = CDNS_PCIE_AT_OB_REGION_DESC0_TYPE_NORMAL_MSG;
	desc1 = 0;

	/* See cdns_pcie_set_outbound_region() comments above. */
	if (pcie->is_rc) {
		desc0 |= CDNS_PCIE_AT_OB_REGION_DESC0_HARDCODED_RID |
			 CDNS_PCIE_AT_OB_REGION_DESC0_DEVFN(0);
		desc1 |= CDNS_PCIE_AT_OB_REGION_DESC1_BUS(pcie->bus);
	} else {
		desc0 |= CDNS_PCIE_AT_OB_REGION_DESC0_DEVFN(fn);
	}

	/* Set the CPU address */
	cpu_addr -= pcie->mem_res->start;
	addr0 = CDNS_PCIE_AT_OB_REGION_CPU_ADDR0_NBITS(17) |
		(lower_32_bits(cpu_addr) & GENMASK(31, 8));
	addr1 = upper_32_bits(cpu_addr);

	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_PCI_ADDR0(r), 0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_PCI_ADDR1(r), 0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_DESC0(r), desc0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_DESC1(r), desc1);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_CPU_ADDR0(r), addr0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_CPU_ADDR1(r), addr1);
}

void cdns_pcie_reset_outbound_region(struct cdns_pcie *pcie, u32 r)
{
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_PCI_ADDR0(r), 0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_PCI_ADDR1(r), 0);

	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_DESC0(r), 0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_DESC1(r), 0);

	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_CPU_ADDR0(r), 0);
	cdns_pcie_writel(pcie, CDNS_PCIE_AT_OB_REGION_CPU_ADDR1(r), 0);
}

void cdns_pcie_disable_phy(struct cdns_pcie *pcie)
{
	int i = pcie->phy_count;

	while (i--) {
		phy_power_off(pcie->phy[i]);
		phy_exit(pcie->phy[i]);
	}
}

int cdns_pcie_enable_phy(struct cdns_pcie *pcie)
{
	int ret;
	int i;

	for (i = 0; i < pcie->phy_count; i++) {
		ret = phy_init(pcie->phy[i]);
		if (ret < 0)
			goto err_phy;

		ret = phy_power_on(pcie->phy[i]);
		if (ret < 0) {
			phy_exit(pcie->phy[i]);
			goto err_phy;
		}
	}

	return 0;

err_phy:
	while (--i >= 0) {
		phy_power_off(pcie->phy[i]);
		phy_exit(pcie->phy[i]);
	}

	return ret;
}

int cdns_pcie_init_phy(struct device *dev, struct cdns_pcie *pcie)
{
	struct device_node *np = dev->of_node;
	int phy_count;
	struct phy **phy;
	struct device_link **link;
	int i;
	int ret;
	const char *name;

	phy_count = of_property_count_strings(np, "phy-names");
	if (phy_count < 1) {
		dev_err(dev, "no phy-names.  PHY will not be initialized\n");
		pcie->phy_count = 0;
		return 0;
	}

	phy = devm_kcalloc(dev, phy_count, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	link = devm_kcalloc(dev, phy_count, sizeof(*link), GFP_KERNEL);
	if (!link)
		return -ENOMEM;

	for (i = 0; i < phy_count; i++) {
		of_property_read_string_index(np, "phy-names", i, &name);
		phy[i] = devm_phy_get(dev, name);
		if (IS_ERR(phy[i])) {
			ret = PTR_ERR(phy[i]);
			goto err_phy;
		}
		link[i] = device_link_add(dev, &phy[i]->dev, DL_FLAG_STATELESS);
		if (!link[i]) {
			devm_phy_put(dev, phy[i]);
			ret = -EINVAL;
			goto err_phy;
		}
	}

	pcie->phy_count = phy_count;
	pcie->phy = phy;
	pcie->link = link;

	ret =  cdns_pcie_enable_phy(pcie);
	if (ret)
		goto err_phy;

	return 0;

err_phy:
	while (--i >= 0) {
		device_link_del(link[i]);
		devm_phy_put(dev, phy[i]);
	}

	return ret;
}

