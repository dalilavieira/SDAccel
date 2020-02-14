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
typedef  int suspend_state_t ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  MX27_CCM_BASE_ADDR ; 
 int /*<<< orphan*/  MX27_IO_ADDRESS (int /*<<< orphan*/ ) ; 
 scalar_t__ MXC_CPU_IMX6DL ; 
 scalar_t__ MXC_CPU_IMX6Q ; 
 scalar_t__ MXC_CPU_IMX6SLL ; 
 scalar_t__ MXC_CPU_IMX6SX ; 
 scalar_t__ MXC_CPU_IMX6UL ; 
 scalar_t__ MXC_CPU_IMX6ULL ; 
 scalar_t__ MXC_CPU_IMX7D ; 
#define  PM_SUSPEND_MEM 128 
 scalar_t__ __mxc_cpu_type ; 
 int /*<<< orphan*/  cpu_do_idle () ; 
 int imx_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  imx_writel (int,int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static int mx27_suspend_enter(suspend_state_t state)
{
	u32 cscr;
	switch (state) {
	case PM_SUSPEND_MEM:
		/* Clear MPEN and SPEN to disable MPLL/SPLL */
		cscr = imx_readl(MX27_IO_ADDRESS(MX27_CCM_BASE_ADDR));
		cscr &= 0xFFFFFFFC;
		imx_writel(cscr, MX27_IO_ADDRESS(MX27_CCM_BASE_ADDR));
		/* Executes WFI */
		cpu_do_idle();
		break;

	default:
		return -EINVAL;
	}
	return 0;
}

