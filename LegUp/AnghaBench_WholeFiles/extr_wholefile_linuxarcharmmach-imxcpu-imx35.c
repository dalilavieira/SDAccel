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

/* Variables and functions */
 int IMX_CHIP_REVISION_1_0 ; 
 int IMX_CHIP_REVISION_2_0 ; 
 int IMX_CHIP_REVISION_2_1 ; 
 int IMX_CHIP_REVISION_UNKNOWN ; 
 scalar_t__ MX35_IIM_BASE_ADDR ; 
 int /*<<< orphan*/  MX35_IO_ADDRESS (scalar_t__) ; 
 scalar_t__ MXC_CPU_IMX6DL ; 
 scalar_t__ MXC_CPU_IMX6Q ; 
 scalar_t__ MXC_CPU_IMX6SLL ; 
 scalar_t__ MXC_CPU_IMX6SX ; 
 scalar_t__ MXC_CPU_IMX6UL ; 
 scalar_t__ MXC_CPU_IMX6ULL ; 
 scalar_t__ MXC_CPU_IMX7D ; 
 scalar_t__ MXC_IIMSREV ; 
 scalar_t__ __mxc_cpu_type ; 
 int imx_readl (int /*<<< orphan*/ ) ; 
 int mx35_cpu_rev ; 

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

__attribute__((used)) static int mx35_read_cpu_rev(void)
{
	u32 rev;

	rev = imx_readl(MX35_IO_ADDRESS(MX35_IIM_BASE_ADDR + MXC_IIMSREV));
	switch (rev) {
	case 0x00:
		return IMX_CHIP_REVISION_1_0;
	case 0x10:
		return IMX_CHIP_REVISION_2_0;
	case 0x11:
		return IMX_CHIP_REVISION_2_1;
	default:
		return IMX_CHIP_REVISION_UNKNOWN;
	}
}

int mx35_revision(void)
{
	if (mx35_cpu_rev == -1)
		mx35_cpu_rev = mx35_read_cpu_rev();

	return mx35_cpu_rev;
}

