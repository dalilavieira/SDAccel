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
 int GPIO_AF ; 
 int GPIO_AOUT_SHIFT ; 
 int GPIO_BOUT_SHIFT ; 
 int GPIO_OCR_MASK ; 
 int GPIO_OCR_SHIFT ; 
 int GPIO_OUT ; 
 int GPIO_PF ; 
 int GPIO_PIN_MASK ; 
 int GPIO_PORT_MASK ; 
 int GPIO_PORT_SHIFT ; 
 int GPIO_PUEN ; 
 scalar_t__ MXC_CPU_IMX6DL ; 
 scalar_t__ MXC_CPU_IMX6Q ; 
 scalar_t__ MXC_CPU_IMX6SLL ; 
 scalar_t__ MXC_CPU_IMX6SX ; 
 scalar_t__ MXC_CPU_IMX6UL ; 
 scalar_t__ MXC_CPU_IMX6ULL ; 
 scalar_t__ MXC_CPU_IMX7D ; 
 unsigned int MXC_DDIR (unsigned int) ; 
 unsigned int MXC_GIUS (unsigned int) ; 
 unsigned int MXC_GPR (unsigned int) ; 
 unsigned long MXC_ICONFA1 (unsigned int) ; 
 unsigned long MXC_ICONFA2 (unsigned int) ; 
 unsigned long MXC_ICONFB1 (unsigned int) ; 
 unsigned long MXC_ICONFB2 (unsigned int) ; 
 unsigned long MXC_OCR1 (unsigned int) ; 
 unsigned long MXC_OCR2 (unsigned int) ; 
 unsigned int MXC_PUEN (unsigned int) ; 
 scalar_t__ __mxc_cpu_type ; 
 unsigned int imx_iomuxv1_baseaddr ; 
 unsigned int imx_iomuxv1_numports ; 
 unsigned long imx_readl (unsigned int) ; 
 int /*<<< orphan*/  imx_writel (unsigned long,unsigned int) ; 

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

__attribute__((used)) static inline unsigned long imx_iomuxv1_readl(unsigned offset)
{
	return imx_readl(imx_iomuxv1_baseaddr + offset);
}

__attribute__((used)) static inline void imx_iomuxv1_writel(unsigned long val, unsigned offset)
{
	imx_writel(val, imx_iomuxv1_baseaddr + offset);
}

__attribute__((used)) static inline void imx_iomuxv1_rmwl(unsigned offset,
		unsigned long mask, unsigned long value)
{
	unsigned long reg = imx_iomuxv1_readl(offset);

	reg &= ~mask;
	reg |= value;

	imx_iomuxv1_writel(reg, offset);
}

__attribute__((used)) static inline void imx_iomuxv1_set_puen(
		unsigned int port, unsigned int pin, int on)
{
	unsigned long mask = 1 << pin;

	imx_iomuxv1_rmwl(MXC_PUEN(port), mask, on ? mask : 0);
}

__attribute__((used)) static inline void imx_iomuxv1_set_ddir(
		unsigned int port, unsigned int pin, int out)
{
	unsigned long mask = 1 << pin;

	imx_iomuxv1_rmwl(MXC_DDIR(port), mask, out ? mask : 0);
}

__attribute__((used)) static inline void imx_iomuxv1_set_gpr(
		unsigned int port, unsigned int pin, int af)
{
	unsigned long mask = 1 << pin;

	imx_iomuxv1_rmwl(MXC_GPR(port), mask, af ? mask : 0);
}

__attribute__((used)) static inline void imx_iomuxv1_set_gius(
		unsigned int port, unsigned int pin, int inuse)
{
	unsigned long mask = 1 << pin;

	imx_iomuxv1_rmwl(MXC_GIUS(port), mask, inuse ? mask : 0);
}

__attribute__((used)) static inline void imx_iomuxv1_set_ocr(
		unsigned int port, unsigned int pin, unsigned int ocr)
{
	unsigned long shift = (pin & 0xf) << 1;
	unsigned long mask = 3 << shift;
	unsigned long value = ocr << shift;
	unsigned long offset = pin < 16 ? MXC_OCR1(port) : MXC_OCR2(port);

	imx_iomuxv1_rmwl(offset, mask, value);
}

__attribute__((used)) static inline void imx_iomuxv1_set_iconfa(
		unsigned int port, unsigned int pin, unsigned int aout)
{
	unsigned long shift = (pin & 0xf) << 1;
	unsigned long mask = 3 << shift;
	unsigned long value = aout << shift;
	unsigned long offset = pin < 16 ? MXC_ICONFA1(port) : MXC_ICONFA2(port);

	imx_iomuxv1_rmwl(offset, mask, value);
}

__attribute__((used)) static inline void imx_iomuxv1_set_iconfb(
		unsigned int port, unsigned int pin, unsigned int bout)
{
	unsigned long shift = (pin & 0xf) << 1;
	unsigned long mask = 3 << shift;
	unsigned long value = bout << shift;
	unsigned long offset = pin < 16 ? MXC_ICONFB1(port) : MXC_ICONFB2(port);

	imx_iomuxv1_rmwl(offset, mask, value);
}

int mxc_gpio_mode(int gpio_mode)
{
	unsigned int pin = gpio_mode & GPIO_PIN_MASK;
	unsigned int port = (gpio_mode & GPIO_PORT_MASK) >> GPIO_PORT_SHIFT;
	unsigned int ocr = (gpio_mode & GPIO_OCR_MASK) >> GPIO_OCR_SHIFT;
	unsigned int aout = (gpio_mode >> GPIO_AOUT_SHIFT) & 3;
	unsigned int bout = (gpio_mode >> GPIO_BOUT_SHIFT) & 3;

	if (port >= imx_iomuxv1_numports)
		return -EINVAL;

	/* Pullup enable */
	imx_iomuxv1_set_puen(port, pin, gpio_mode & GPIO_PUEN);

	/* Data direction */
	imx_iomuxv1_set_ddir(port, pin, gpio_mode & GPIO_OUT);

	/* Primary / alternate function */
	imx_iomuxv1_set_gpr(port, pin, gpio_mode & GPIO_AF);

	/* use as gpio? */
	imx_iomuxv1_set_gius(port, pin, !(gpio_mode & (GPIO_PF | GPIO_AF)));

	imx_iomuxv1_set_ocr(port, pin, ocr);

	imx_iomuxv1_set_iconfa(port, pin, aout);

	imx_iomuxv1_set_iconfb(port, pin, bout);

	return 0;
}

__attribute__((used)) static int imx_iomuxv1_setup_multiple(const int *list, unsigned count)
{
	size_t i;
	int ret = 0;

	for (i = 0; i < count; ++i) {
		ret = mxc_gpio_mode(list[i]);

		if (ret)
			return ret;
	}

	return ret;
}

int mxc_gpio_setup_multiple_pins(const int *pin_list, unsigned count,
		const char *label)
{
	int ret;

	ret = imx_iomuxv1_setup_multiple(pin_list, count);
	return ret;
}

