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
typedef  int u32 ;
struct pci_dev {int mmio_always_on; } ;

/* Variables and functions */
 int CFG_PCI_CACHE_LINE_SIZE (int /*<<< orphan*/ ,int) ; 
 int CFG_PCI_INTERRUPT_LINE (int,int) ; 
 int CFG_PCI_VENDOR_ID (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int CS5536_ISA_CLASS_CODE ; 
 int /*<<< orphan*/  CS5536_ISA_DEVICE_ID ; 
 int /*<<< orphan*/  CS5536_ISA_SUB_ID ; 
 int /*<<< orphan*/  CS5536_SUB_VENDOR_ID ; 
 int CS5536_UART1_INTR ; 
 int CS5536_UART2_INTR ; 
 int /*<<< orphan*/  CS5536_VENDOR_ID ; 
 int DIVIL_LBAR_PMS ; 
 int DIVIL_LBAR_SMB ; 
 int /*<<< orphan*/  DIVIL_MSR_REG (int) ; 
 int /*<<< orphan*/  GLCP_CHIP_REV_ID ; 
 int /*<<< orphan*/  GLCP_MSR_REG (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GLCP_SOFT_COM ; 
#define  PCI_BAR0_REG 146 
#define  PCI_BAR1_REG 145 
#define  PCI_BAR2_REG 144 
#define  PCI_BAR3_REG 143 
#define  PCI_BAR4_REG 142 
#define  PCI_BAR5_REG 141 
 int PCI_BAR_RANGE_MASK ; 
 int PCI_BASE_ADDRESS_SPACE_IO ; 
 int /*<<< orphan*/  PCI_BRIDGE_HEADER_TYPE ; 
#define  PCI_CACHE_LINE_SIZE 140 
#define  PCI_CAPABILITY_LIST 139 
 int PCI_CAPLIST_POINTER ; 
#define  PCI_CARDBUS_CIS 138 
 int PCI_CARDBUS_CIS_POINTER ; 
#define  PCI_CLASS_REVISION 137 
#define  PCI_COMMAND 136 
 int PCI_COMMAND_IO ; 
 int PCI_EXPANSION_ROM_BAR ; 
#define  PCI_INTERRUPT_LINE 135 
#define  PCI_ISA_FIXUP_REG 134 
#define  PCI_ROM_ADDRESS 133 
#define  PCI_STATUS 132 
 int PCI_STATUS_66MHZ ; 
 int PCI_STATUS_DETECTED_PARITY ; 
 int PCI_STATUS_DEVSEL_MEDIUM ; 
 int PCI_STATUS_FAST_BACK ; 
 int PCI_STATUS_REC_MASTER_ABORT ; 
 int PCI_STATUS_REC_TARGET_ABORT ; 
 int PCI_STATUS_SIG_TARGET_ABORT ; 
#define  PCI_SUBSYSTEM_VENDOR_ID 131 
#define  PCI_UART1_INT_REG 130 
#define  PCI_UART2_INT_REG 129 
#define  PCI_VENDOR_ID 128 
 int PIC_YSEL_HIGH ; 
 int /*<<< orphan*/  SB_CTRL ; 
 int /*<<< orphan*/  SB_ERROR ; 
 int SB_MAR_ERR_EN ; 
 int SB_MAR_ERR_FLAG ; 
 int /*<<< orphan*/  SB_MSR_REG (int /*<<< orphan*/ ) ; 
 int SB_PARE_ERR_EN ; 
 int SB_PARE_ERR_FLAG ; 
 int SB_TAR_ERR_EN ; 
 int SB_TAR_ERR_FLAG ; 
 int SB_TAS_ERR_EN ; 
 int SB_TAS_ERR_FLAG ; 
 int /*<<< orphan*/  _rdmsr (int /*<<< orphan*/ ,int*,int*) ; 
 int /*<<< orphan*/  _wrmsr (int /*<<< orphan*/ ,int,int) ; 
 int* bar_space_len ; 
 int* bar_space_range ; 
 int /*<<< orphan*/ * divil_msr_reg ; 
 int /*<<< orphan*/ * sb_msr_reg ; 
 int* soft_bar_flag ; 

__attribute__((used)) static void divil_lbar_enable(void)
{
	u32 hi, lo;
	int offset;

	/*
	 * The DIVIL IRQ is not used yet. and make the RCONF0 reserved.
	 */

	for (offset = DIVIL_LBAR_SMB; offset <= DIVIL_LBAR_PMS; offset++) {
		_rdmsr(DIVIL_MSR_REG(offset), &hi, &lo);
		hi |= 0x01;
		_wrmsr(DIVIL_MSR_REG(offset), hi, lo);
	}
}

__attribute__((used)) static void divil_lbar_disable(void)
{
	u32 hi, lo;
	int offset;

	for (offset = DIVIL_LBAR_SMB; offset <= DIVIL_LBAR_PMS; offset++) {
		_rdmsr(DIVIL_MSR_REG(offset), &hi, &lo);
		hi &= ~0x01;
		_wrmsr(DIVIL_MSR_REG(offset), hi, lo);
	}
}

void pci_isa_write_bar(int n, u32 value)
{
	u32 hi = 0, lo = value;

	if (value == PCI_BAR_RANGE_MASK) {
		_rdmsr(GLCP_MSR_REG(GLCP_SOFT_COM), &hi, &lo);
		lo |= soft_bar_flag[n];
		_wrmsr(GLCP_MSR_REG(GLCP_SOFT_COM), hi, lo);
	} else if (value & 0x01) {
		/* NATIVE reg */
		hi = 0x0000f001;
		lo &= bar_space_range[n];
		_wrmsr(divil_msr_reg[n], hi, lo);

		/* RCONFx is 4bytes in units for I/O space */
		hi = ((value & 0x000ffffc) << 12) |
		    ((bar_space_len[n] - 4) << 12) | 0x01;
		lo = ((value & 0x000ffffc) << 12) | 0x01;
		_wrmsr(sb_msr_reg[n], hi, lo);
	}
}

u32 pci_isa_read_bar(int n)
{
	u32 conf_data = 0;
	u32 hi, lo;

	_rdmsr(GLCP_MSR_REG(GLCP_SOFT_COM), &hi, &lo);
	if (lo & soft_bar_flag[n]) {
		conf_data = bar_space_range[n] | PCI_BASE_ADDRESS_SPACE_IO;
		lo &= ~soft_bar_flag[n];
		_wrmsr(GLCP_MSR_REG(GLCP_SOFT_COM), hi, lo);
	} else {
		_rdmsr(divil_msr_reg[n], &hi, &lo);
		conf_data = lo & bar_space_range[n];
		conf_data |= 0x01;
		conf_data &= ~0x02;
	}
	return conf_data;
}

void pci_isa_write_reg(int reg, u32 value)
{
	u32 hi = 0, lo = value;
	u32 temp;

	switch (reg) {
	case PCI_COMMAND:
		if (value & PCI_COMMAND_IO)
			divil_lbar_enable();
		else
			divil_lbar_disable();
		break;
	case PCI_STATUS:
		_rdmsr(SB_MSR_REG(SB_ERROR), &hi, &lo);
		temp = lo & 0x0000ffff;
		if ((value & PCI_STATUS_SIG_TARGET_ABORT) &&
		    (lo & SB_TAS_ERR_EN))
			temp |= SB_TAS_ERR_FLAG;

		if ((value & PCI_STATUS_REC_TARGET_ABORT) &&
		    (lo & SB_TAR_ERR_EN))
			temp |= SB_TAR_ERR_FLAG;

		if ((value & PCI_STATUS_REC_MASTER_ABORT)
		    && (lo & SB_MAR_ERR_EN))
			temp |= SB_MAR_ERR_FLAG;

		if ((value & PCI_STATUS_DETECTED_PARITY)
		    && (lo & SB_PARE_ERR_EN))
			temp |= SB_PARE_ERR_FLAG;

		lo = temp;
		_wrmsr(SB_MSR_REG(SB_ERROR), hi, lo);
		break;
	case PCI_CACHE_LINE_SIZE:
		value &= 0x0000ff00;
		_rdmsr(SB_MSR_REG(SB_CTRL), &hi, &lo);
		hi &= 0xffffff00;
		hi |= (value >> 8);
		_wrmsr(SB_MSR_REG(SB_CTRL), hi, lo);
		break;
	case PCI_BAR0_REG:
		pci_isa_write_bar(0, value);
		break;
	case PCI_BAR1_REG:
		pci_isa_write_bar(1, value);
		break;
	case PCI_BAR2_REG:
		pci_isa_write_bar(2, value);
		break;
	case PCI_BAR3_REG:
		pci_isa_write_bar(3, value);
		break;
	case PCI_BAR4_REG:
		pci_isa_write_bar(4, value);
		break;
	case PCI_BAR5_REG:
		pci_isa_write_bar(5, value);
		break;
	case PCI_UART1_INT_REG:
		_rdmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), &hi, &lo);
		/* disable uart1 interrupt in PIC */
		lo &= ~(0xf << 24);
		if (value)	/* enable uart1 interrupt in PIC */
			lo |= (CS5536_UART1_INTR << 24);
		_wrmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), hi, lo);
		break;
	case PCI_UART2_INT_REG:
		_rdmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), &hi, &lo);
		/* disable uart2 interrupt in PIC */
		lo &= ~(0xf << 28);
		if (value)	/* enable uart2 interrupt in PIC */
			lo |= (CS5536_UART2_INTR << 28);
		_wrmsr(DIVIL_MSR_REG(PIC_YSEL_HIGH), hi, lo);
		break;
	case PCI_ISA_FIXUP_REG:
		if (value) {
			/* enable the TARGET ABORT/MASTER ABORT etc. */
			_rdmsr(SB_MSR_REG(SB_ERROR), &hi, &lo);
			lo |= 0x00000063;
			_wrmsr(SB_MSR_REG(SB_ERROR), hi, lo);
		}

	default:
		/* ALL OTHER PCI CONFIG SPACE HEADER IS NOT IMPLEMENTED. */
		break;
	}
}

u32 pci_isa_read_reg(int reg)
{
	u32 conf_data = 0;
	u32 hi, lo;

	switch (reg) {
	case PCI_VENDOR_ID:
		conf_data =
		    CFG_PCI_VENDOR_ID(CS5536_ISA_DEVICE_ID, CS5536_VENDOR_ID);
		break;
	case PCI_COMMAND:
		/* we just check the first LBAR for the IO enable bit, */
		/* maybe we should changed later. */
		_rdmsr(DIVIL_MSR_REG(DIVIL_LBAR_SMB), &hi, &lo);
		if (hi & 0x01)
			conf_data |= PCI_COMMAND_IO;
		break;
	case PCI_STATUS:
		conf_data |= PCI_STATUS_66MHZ;
		conf_data |= PCI_STATUS_DEVSEL_MEDIUM;
		conf_data |= PCI_STATUS_FAST_BACK;

		_rdmsr(SB_MSR_REG(SB_ERROR), &hi, &lo);
		if (lo & SB_TAS_ERR_FLAG)
			conf_data |= PCI_STATUS_SIG_TARGET_ABORT;
		if (lo & SB_TAR_ERR_FLAG)
			conf_data |= PCI_STATUS_REC_TARGET_ABORT;
		if (lo & SB_MAR_ERR_FLAG)
			conf_data |= PCI_STATUS_REC_MASTER_ABORT;
		if (lo & SB_PARE_ERR_FLAG)
			conf_data |= PCI_STATUS_DETECTED_PARITY;
		break;
	case PCI_CLASS_REVISION:
		_rdmsr(GLCP_MSR_REG(GLCP_CHIP_REV_ID), &hi, &lo);
		conf_data = lo & 0x000000ff;
		conf_data |= (CS5536_ISA_CLASS_CODE << 8);
		break;
	case PCI_CACHE_LINE_SIZE:
		_rdmsr(SB_MSR_REG(SB_CTRL), &hi, &lo);
		hi &= 0x000000f8;
		conf_data = CFG_PCI_CACHE_LINE_SIZE(PCI_BRIDGE_HEADER_TYPE, hi);
		break;
		/*
		 * we only use the LBAR of DIVIL, no RCONF used.
		 * all of them are IO space.
		 */
	case PCI_BAR0_REG:
		return pci_isa_read_bar(0);
		break;
	case PCI_BAR1_REG:
		return pci_isa_read_bar(1);
		break;
	case PCI_BAR2_REG:
		return pci_isa_read_bar(2);
		break;
	case PCI_BAR3_REG:
		break;
	case PCI_BAR4_REG:
		return pci_isa_read_bar(4);
		break;
	case PCI_BAR5_REG:
		return pci_isa_read_bar(5);
		break;
	case PCI_CARDBUS_CIS:
		conf_data = PCI_CARDBUS_CIS_POINTER;
		break;
	case PCI_SUBSYSTEM_VENDOR_ID:
		conf_data =
		    CFG_PCI_VENDOR_ID(CS5536_ISA_SUB_ID, CS5536_SUB_VENDOR_ID);
		break;
	case PCI_ROM_ADDRESS:
		conf_data = PCI_EXPANSION_ROM_BAR;
		break;
	case PCI_CAPABILITY_LIST:
		conf_data = PCI_CAPLIST_POINTER;
		break;
	case PCI_INTERRUPT_LINE:
		/* no interrupt used here */
		conf_data = CFG_PCI_INTERRUPT_LINE(0x00, 0x00);
		break;
	default:
		break;
	}

	return conf_data;
}

__attribute__((used)) static void cs5536_isa_mmio_always_on(struct pci_dev *dev)
{
	dev->mmio_always_on = 1;
}

