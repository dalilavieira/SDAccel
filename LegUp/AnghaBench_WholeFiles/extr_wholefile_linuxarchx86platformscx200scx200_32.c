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
typedef  unsigned int u32 ;
struct pci_device_id {int dummy; } ;
struct pci_dev {scalar_t__ device; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 scalar_t__ PCI_DEVICE_ID_NS_SC1100_BRIDGE ; 
 scalar_t__ PCI_DEVICE_ID_NS_SCx200_BRIDGE ; 
 int /*<<< orphan*/  SCx200_CBA_SCRATCH ; 
 unsigned int SCx200_CB_BASE_FIXED ; 
 int /*<<< orphan*/  SCx200_GPIO_SIZE ; 
 void* inl (int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  outl (unsigned int,int) ; 
 int /*<<< orphan*/  pci_read_config_dword (struct pci_dev*,int /*<<< orphan*/ ,unsigned int*) ; 
 unsigned int pci_resource_start (struct pci_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  pr_info (char*,unsigned int) ; 
 int /*<<< orphan*/  pr_warn (char*) ; 
 int /*<<< orphan*/  request_region (unsigned int,int /*<<< orphan*/ ,char*) ; 
 unsigned int scx200_cb_base ; 
 scalar_t__ scx200_cb_probe (unsigned int) ; 
 int scx200_gpio_base ; 
 int /*<<< orphan*/  scx200_gpio_config_lock ; 
 void** scx200_gpio_shadow ; 

__attribute__((used)) static void scx200_init_shadow(void)
{
	int bank;

	/* read the current values driven on the GPIO signals */
	for (bank = 0; bank < 2; ++bank)
		scx200_gpio_shadow[bank] = inl(scx200_gpio_base + 0x10 * bank);
}

__attribute__((used)) static int scx200_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
	unsigned base;

	if (pdev->device == PCI_DEVICE_ID_NS_SCx200_BRIDGE ||
	    pdev->device == PCI_DEVICE_ID_NS_SC1100_BRIDGE) {
		base = pci_resource_start(pdev, 0);
		pr_info("GPIO base 0x%x\n", base);

		if (!request_region(base, SCx200_GPIO_SIZE,
				    "NatSemi SCx200 GPIO")) {
			pr_err("can't allocate I/O for GPIOs\n");
			return -EBUSY;
		}

		scx200_gpio_base = base;
		scx200_init_shadow();

	} else {
		/* find the base of the Configuration Block */
		if (scx200_cb_probe(SCx200_CB_BASE_FIXED)) {
			scx200_cb_base = SCx200_CB_BASE_FIXED;
		} else {
			pci_read_config_dword(pdev, SCx200_CBA_SCRATCH, &base);
			if (scx200_cb_probe(base)) {
				scx200_cb_base = base;
			} else {
				pr_warn("Configuration Block not found\n");
				return -ENODEV;
			}
		}
		pr_info("Configuration Block base 0x%x\n", scx200_cb_base);
	}

	return 0;
}

u32 scx200_gpio_configure(unsigned index, u32 mask, u32 bits)
{
	u32 config, new_config;

	mutex_lock(&scx200_gpio_config_lock);

	outl(index, scx200_gpio_base + 0x20);
	config = inl(scx200_gpio_base + 0x24);

	new_config = (config & mask) | bits;
	outl(new_config, scx200_gpio_base + 0x24);

	mutex_unlock(&scx200_gpio_config_lock);

	return config;
}

