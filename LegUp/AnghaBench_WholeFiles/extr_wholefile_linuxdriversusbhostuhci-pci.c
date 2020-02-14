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
struct usb_hcd {scalar_t__ rsrc_start; } ;
struct uhci_hcd {unsigned long io_addr; int rh_numports; int oc_low; int wait_for_hp; void (* reset_hc ) (struct uhci_hcd*) ;int (* check_and_reset_hc ) (struct uhci_hcd*) ;void (* configure_hc ) (struct uhci_hcd*) ;int (* resume_detect_interrupts_are_broken ) (struct uhci_hcd*) ;int (* global_suspend_mode_is_broken ) (struct uhci_hcd*) ;} ;
struct pci_dev {scalar_t__ vendor; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DMI_BOARD_NAME ; 
#define  PCI_VENDOR_ID_GENESYS 129 
 scalar_t__ PCI_VENDOR_ID_HP ; 
#define  PCI_VENDOR_ID_INTEL 128 
 scalar_t__ PCI_VENDOR_ID_VIA ; 
 int /*<<< orphan*/  USBLEGSUP ; 
 int /*<<< orphan*/  USBLEGSUP_DEFAULT ; 
 unsigned long USBPORTSC1 ; 
 int USBPORTSC_CCS ; 
 int USBPORTSC_OC ; 
 int /*<<< orphan*/  USBRES_INTEL ; 
 int /*<<< orphan*/  check_and_reset_hc (struct uhci_hcd*) ; 
 int /*<<< orphan*/  device_set_wakeup_capable (int /*<<< orphan*/ ,int) ; 
 char* dmi_get_system_info (int /*<<< orphan*/ ) ; 
 struct uhci_hcd* hcd_to_uhci (struct usb_hcd*) ; 
 int inw (unsigned long) ; 
 struct usb_hcd* pci_get_drvdata (struct pci_dev*) ; 
 int /*<<< orphan*/  pci_write_config_byte (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pci_write_config_word (struct pci_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 
 struct pci_dev* to_pci_dev (int /*<<< orphan*/ ) ; 
 int uhci_check_and_reset_hc (struct pci_dev*,unsigned long) ; 
 int uhci_count_ports (struct usb_hcd*) ; 
 int /*<<< orphan*/  uhci_dev (struct uhci_hcd*) ; 
 int /*<<< orphan*/  uhci_hc_died (struct uhci_hcd*) ; 
 int /*<<< orphan*/  uhci_reset_hc (struct pci_dev*,unsigned long) ; 

__attribute__((used)) static inline void usb_amd_quirk_pll_disable(void) {}

__attribute__((used)) static inline void usb_amd_quirk_pll_enable(void) {}

__attribute__((used)) static inline void usb_asmedia_modifyflowcontrol(struct pci_dev *pdev) {}

__attribute__((used)) static inline void usb_amd_dev_put(void) {}

__attribute__((used)) static inline void usb_disable_xhci_ports(struct pci_dev *xhci_pdev) {}

__attribute__((used)) static inline void sb800_prefetch(struct device *dev, int on) {}

__attribute__((used)) static inline bool usb_amd_pt_check_port(struct device *device, int port)
{
	return false;
}

__attribute__((used)) static void uhci_pci_reset_hc(struct uhci_hcd *uhci)
{
	uhci_reset_hc(to_pci_dev(uhci_dev(uhci)), uhci->io_addr);
}

__attribute__((used)) static int uhci_pci_check_and_reset_hc(struct uhci_hcd *uhci)
{
	return uhci_check_and_reset_hc(to_pci_dev(uhci_dev(uhci)),
				uhci->io_addr);
}

__attribute__((used)) static void uhci_pci_configure_hc(struct uhci_hcd *uhci)
{
	struct pci_dev *pdev = to_pci_dev(uhci_dev(uhci));

	/* Enable PIRQ */
	pci_write_config_word(pdev, USBLEGSUP, USBLEGSUP_DEFAULT);

	/* Disable platform-specific non-PME# wakeup */
	if (pdev->vendor == PCI_VENDOR_ID_INTEL)
		pci_write_config_byte(pdev, USBRES_INTEL, 0);
}

__attribute__((used)) static int uhci_pci_resume_detect_interrupts_are_broken(struct uhci_hcd *uhci)
{
	int port;

	switch (to_pci_dev(uhci_dev(uhci))->vendor) {
	default:
		break;

	case PCI_VENDOR_ID_GENESYS:
		/* Genesys Logic's GL880S controllers don't generate
		 * resume-detect interrupts.
		 */
		return 1;

	case PCI_VENDOR_ID_INTEL:
		/* Some of Intel's USB controllers have a bug that causes
		 * resume-detect interrupts if any port has an over-current
		 * condition.  To make matters worse, some motherboards
		 * hardwire unused USB ports' over-current inputs active!
		 * To prevent problems, we will not enable resume-detect
		 * interrupts if any ports are OC.
		 */
		for (port = 0; port < uhci->rh_numports; ++port) {
			if (inw(uhci->io_addr + USBPORTSC1 + port * 2) &
					USBPORTSC_OC)
				return 1;
		}
		break;
	}
	return 0;
}

__attribute__((used)) static int uhci_pci_global_suspend_mode_is_broken(struct uhci_hcd *uhci)
{
	int port;
	const char *sys_info;
	static const char bad_Asus_board[] = "A7V8X";

	/* One of Asus's motherboards has a bug which causes it to
	 * wake up immediately from suspend-to-RAM if any of the ports
	 * are connected.  In such cases we will not set EGSM.
	 */
	sys_info = dmi_get_system_info(DMI_BOARD_NAME);
	if (sys_info && !strcmp(sys_info, bad_Asus_board)) {
		for (port = 0; port < uhci->rh_numports; ++port) {
			if (inw(uhci->io_addr + USBPORTSC1 + port * 2) &
					USBPORTSC_CCS)
				return 1;
		}
	}

	return 0;
}

__attribute__((used)) static int uhci_pci_init(struct usb_hcd *hcd)
{
	struct uhci_hcd *uhci = hcd_to_uhci(hcd);

	uhci->io_addr = (unsigned long) hcd->rsrc_start;

	uhci->rh_numports = uhci_count_ports(hcd);

	/* Intel controllers report the OverCurrent bit active on.
	 * VIA controllers report it active off, so we'll adjust the
	 * bit value.  (It's not standardized in the UHCI spec.)
	 */
	if (to_pci_dev(uhci_dev(uhci))->vendor == PCI_VENDOR_ID_VIA)
		uhci->oc_low = 1;

	/* HP's server management chip requires a longer port reset delay. */
	if (to_pci_dev(uhci_dev(uhci))->vendor == PCI_VENDOR_ID_HP)
		uhci->wait_for_hp = 1;

	/* Intel controllers use non-PME wakeup signalling */
	if (to_pci_dev(uhci_dev(uhci))->vendor == PCI_VENDOR_ID_INTEL)
		device_set_wakeup_capable(uhci_dev(uhci), true);

	/* Set up pointers to PCI-specific functions */
	uhci->reset_hc = uhci_pci_reset_hc;
	uhci->check_and_reset_hc = uhci_pci_check_and_reset_hc;
	uhci->configure_hc = uhci_pci_configure_hc;
	uhci->resume_detect_interrupts_are_broken =
		uhci_pci_resume_detect_interrupts_are_broken;
	uhci->global_suspend_mode_is_broken =
		uhci_pci_global_suspend_mode_is_broken;


	/* Kick BIOS off this hardware and reset if the controller
	 * isn't already safely quiescent.
	 */
	check_and_reset_hc(uhci);
	return 0;
}

__attribute__((used)) static void uhci_shutdown(struct pci_dev *pdev)
{
	struct usb_hcd *hcd = pci_get_drvdata(pdev);

	uhci_hc_died(hcd_to_uhci(hcd));
}

