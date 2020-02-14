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
typedef  unsigned long* vulp ;
typedef  unsigned int* vuip ;
typedef  int u8 ;
typedef  int u32 ;
struct pci_controller {int dummy; } ;
struct pci_bus {int number; } ;
typedef  int /*<<< orphan*/  pgprot_t ;
typedef  int /*<<< orphan*/  dma_addr_t ;

/* Variables and functions */
 unsigned long LCA_CONF ; 
 scalar_t__ LCA_IOC_CONF ; 
 scalar_t__ LCA_IOC_STAT0 ; 
 unsigned long LCA_IOC_STAT0_CODE_MASK ; 
 unsigned long LCA_IOC_STAT0_CODE_SHIFT ; 
 unsigned long LCA_IOC_STAT0_ERR ; 
 scalar_t__ LCA_IOC_TBIA ; 
 int PCIBIOS_DEVICE_NOT_FOUND ; 
 int PCIBIOS_SUCCESSFUL ; 
 unsigned long _PAGE_ASM ; 
 unsigned long _PAGE_KRE ; 
 unsigned long _PAGE_KWE ; 
 unsigned long _PAGE_VALID ; 
 int /*<<< orphan*/  __pgprot (unsigned long) ; 
 int /*<<< orphan*/  draina () ; 
 int ioremap_page_range (unsigned long,unsigned long,unsigned long,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 int /*<<< orphan*/  mb () ; 
 int /*<<< orphan*/  printk (char*,unsigned long) ; 
 int /*<<< orphan*/  wmb () ; 
 int /*<<< orphan*/  wrmces (int) ; 

__attribute__((used)) static inline void find_console_vga_hose(void) { }

__attribute__((used)) static inline void locate_and_init_vga(void *(*sel_func)(void *, void *)) { }

__attribute__((used)) static inline int
__alpha_remap_area_pages(unsigned long address, unsigned long phys_addr,
			 unsigned long size, unsigned long flags)
{
	pgprot_t prot;

	prot = __pgprot(_PAGE_VALID | _PAGE_ASM | _PAGE_KRE
			| _PAGE_KWE | flags);
	return ioremap_page_range(address, address + size, phys_addr, prot);
}

__attribute__((used)) static int
mk_conf_addr(struct pci_bus *pbus, unsigned int device_fn, int where,
	     unsigned long *pci_addr)
{
	unsigned long addr;
	u8 bus = pbus->number;

	if (bus == 0) {
		int device = device_fn >> 3;
		int func = device_fn & 0x7;

		/* Type 0 configuration cycle.  */

		if (device > 12) {
			return -1;
		}

		*(vulp)LCA_IOC_CONF = 0;
		addr = (1 << (11 + device)) | (func << 8) | where;
	} else {
		/* Type 1 configuration cycle.  */
		*(vulp)LCA_IOC_CONF = 1;
		addr = (bus << 16) | (device_fn << 8) | where;
	}
	*pci_addr = addr;
	return 0;
}

__attribute__((used)) static unsigned int
conf_read(unsigned long addr)
{
	unsigned long flags, code, stat0;
	unsigned int value;

	local_irq_save(flags);

	/* Reset status register to avoid losing errors.  */
	stat0 = *(vulp)LCA_IOC_STAT0;
	*(vulp)LCA_IOC_STAT0 = stat0;
	mb();

	/* Access configuration space.  */
	value = *(vuip)addr;
	draina();

	stat0 = *(vulp)LCA_IOC_STAT0;
	if (stat0 & LCA_IOC_STAT0_ERR) {
		code = ((stat0 >> LCA_IOC_STAT0_CODE_SHIFT)
			& LCA_IOC_STAT0_CODE_MASK);
		if (code != 1) {
			printk("lca.c:conf_read: got stat0=%lx\n", stat0);
		}

		/* Reset error status.  */
		*(vulp)LCA_IOC_STAT0 = stat0;
		mb();

		/* Reset machine check.  */
		wrmces(0x7);

		value = 0xffffffff;
	}
	local_irq_restore(flags);
	return value;
}

__attribute__((used)) static void
conf_write(unsigned long addr, unsigned int value)
{
	unsigned long flags, code, stat0;

	local_irq_save(flags);	/* avoid getting hit by machine check */

	/* Reset status register to avoid losing errors.  */
	stat0 = *(vulp)LCA_IOC_STAT0;
	*(vulp)LCA_IOC_STAT0 = stat0;
	mb();

	/* Access configuration space.  */
	*(vuip)addr = value;
	draina();

	stat0 = *(vulp)LCA_IOC_STAT0;
	if (stat0 & LCA_IOC_STAT0_ERR) {
		code = ((stat0 >> LCA_IOC_STAT0_CODE_SHIFT)
			& LCA_IOC_STAT0_CODE_MASK);
		if (code != 1) {
			printk("lca.c:conf_write: got stat0=%lx\n", stat0);
		}

		/* Reset error status.  */
		*(vulp)LCA_IOC_STAT0 = stat0;
		mb();

		/* Reset machine check. */
		wrmces(0x7);
	}
	local_irq_restore(flags);
}

__attribute__((used)) static int
lca_read_config(struct pci_bus *bus, unsigned int devfn, int where,
		int size, u32 *value)
{
	unsigned long addr, pci_addr;
	long mask;
	int shift;

	if (mk_conf_addr(bus, devfn, where, &pci_addr))
		return PCIBIOS_DEVICE_NOT_FOUND;

	shift = (where & 3) * 8;
	mask = (size - 1) * 8;
	addr = (pci_addr << 5) + mask + LCA_CONF;
	*value = conf_read(addr) >> (shift);
	return PCIBIOS_SUCCESSFUL;
}

__attribute__((used)) static int 
lca_write_config(struct pci_bus *bus, unsigned int devfn, int where, int size,
		 u32 value)
{
	unsigned long addr, pci_addr;
	long mask;

	if (mk_conf_addr(bus, devfn, where, &pci_addr))
		return PCIBIOS_DEVICE_NOT_FOUND;

	mask = (size - 1) * 8;
	addr = (pci_addr << 5) + mask + LCA_CONF;
	conf_write(addr, value << ((where & 3) * 8));
	return PCIBIOS_SUCCESSFUL;
}

void
lca_pci_tbi(struct pci_controller *hose, dma_addr_t start, dma_addr_t end)
{
	wmb();
	*(vulp)LCA_IOC_TBIA = 0;
	mb();
}

