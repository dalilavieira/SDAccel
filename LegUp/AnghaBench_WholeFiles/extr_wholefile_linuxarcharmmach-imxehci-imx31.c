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

/* Variables and functions */
 int EINVAL ; 
 unsigned int MX31_H1_DT_BIT ; 
 unsigned int MX31_H1_PM_BIT ; 
 unsigned int MX31_H1_SIC_MASK ; 
 unsigned int MX31_H1_SIC_SHIFT ; 
 unsigned int MX31_H2_DT_BIT ; 
 unsigned int MX31_H2_PM_BIT ; 
 unsigned int MX31_H2_SIC_MASK ; 
 unsigned int MX31_H2_SIC_SHIFT ; 
 int /*<<< orphan*/  MX31_IO_ADDRESS (scalar_t__) ; 
 unsigned int MX31_OTG_PM_BIT ; 
 unsigned int MX31_OTG_SIC_MASK ; 
 unsigned int MX31_OTG_SIC_SHIFT ; 
 scalar_t__ MX31_USB_BASE_ADDR ; 
 scalar_t__ MXC_CPU_IMX6DL ; 
 scalar_t__ MXC_CPU_IMX6Q ; 
 scalar_t__ MXC_CPU_IMX6SLL ; 
 scalar_t__ MXC_CPU_IMX6SX ; 
 scalar_t__ MXC_CPU_IMX6UL ; 
 scalar_t__ MXC_CPU_IMX6ULL ; 
 scalar_t__ MXC_CPU_IMX7D ; 
 unsigned int MXC_EHCI_INTERFACE_MASK ; 
 unsigned int MXC_EHCI_POWER_PINS_ENABLED ; 
 unsigned int MXC_EHCI_TTL_ENABLED ; 
 scalar_t__ USBCTRL_OTGBASE_OFFSET ; 
 scalar_t__ __mxc_cpu_type ; 
 unsigned int readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  writel (unsigned int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool cpu_is_imx6sl(void)
{
	return false;
}

__attribute__((used)) static inline bool cpu_is_imx6dl(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX6DL;
}

__attribute__((used)) static inline bool cpu_is_imx6sx(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX6SX;
}

__attribute__((used)) static inline bool cpu_is_imx6ul(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX6UL;
}

__attribute__((used)) static inline bool cpu_is_imx6ull(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX6ULL;
}

__attribute__((used)) static inline bool cpu_is_imx6sll(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX6SLL;
}

__attribute__((used)) static inline bool cpu_is_imx6q(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX6Q;
}

__attribute__((used)) static inline bool cpu_is_imx7d(void)
{
	return __mxc_cpu_type == MXC_CPU_IMX7D;
}

int mx31_initialize_usb_hw(int port, unsigned int flags)
{
	unsigned int v;

	v = readl(MX31_IO_ADDRESS(MX31_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));

	switch (port) {
	case 0:	/* OTG port */
		v &= ~(MX31_OTG_SIC_MASK | MX31_OTG_PM_BIT);
		v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX31_OTG_SIC_SHIFT;

		if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
			v |= MX31_OTG_PM_BIT;

		break;
	case 1: /* H1 port */
		v &= ~(MX31_H1_SIC_MASK | MX31_H1_PM_BIT | MX31_H1_DT_BIT);
		v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX31_H1_SIC_SHIFT;

		if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
			v |= MX31_H1_PM_BIT;

		if (!(flags & MXC_EHCI_TTL_ENABLED))
			v |= MX31_H1_DT_BIT;

		break;
	case 2:	/* H2 port */
		v &= ~(MX31_H2_SIC_MASK | MX31_H2_PM_BIT | MX31_H2_DT_BIT);
		v |= (flags & MXC_EHCI_INTERFACE_MASK) << MX31_H2_SIC_SHIFT;

		if (!(flags & MXC_EHCI_POWER_PINS_ENABLED))
			v |= MX31_H2_PM_BIT;

		if (!(flags & MXC_EHCI_TTL_ENABLED))
			v |= MX31_H2_DT_BIT;

		break;
	default:
		return -EINVAL;
	}

	writel(v, MX31_IO_ADDRESS(MX31_USB_BASE_ADDR + USBCTRL_OTGBASE_OFFSET));

	return 0;
}

