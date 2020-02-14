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
typedef  int u32 ;
struct irq_domain {int dummy; } ;
struct irq_desc {int dummy; } ;
struct irq_data {int /*<<< orphan*/  hwirq; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  irq_hw_number_t ;
struct TYPE_2__ {scalar_t__ cputype; } ;

/* Variables and functions */
 int AR2315_AHB_ERR0 ; 
 int AR2315_AHB_ERR1 ; 
 int AR2315_AHB_ERROR_DET ; 
 int AR2315_IMR ; 
 int /*<<< orphan*/  AR2315_IRQ_MISC ; 
 int /*<<< orphan*/  AR2315_IRQ_WLAN0 ; 
 int AR2315_ISR ; 
 int AR2315_ISR_GPIO ; 
 int AR2315_ISR_WD ; 
 unsigned int AR2315_MISC_IRQ_GPIO ; 
 unsigned int AR2315_MISC_IRQ_WATCHDOG ; 
 int /*<<< orphan*/  ATH25_IRQ_CPU_CLOCK ; 
 int BIT (int /*<<< orphan*/ ) ; 
 int CAUSEF_IP2 ; 
 int CAUSEF_IP3 ; 
 int CAUSEF_IP7 ; 
 scalar_t__ CPU_4KEC ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 unsigned int __ffs (int) ; 
 int __raw_readl (int) ; 
 int /*<<< orphan*/  __raw_writel (int,int) ; 
 int /*<<< orphan*/  ar2315_misc_irq_chip ; 
 int ar2315_rst_base ; 
 TYPE_1__ current_cpu_data ; 
 int /*<<< orphan*/  do_IRQ (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int /*<<< orphan*/  handle_level_irq ; 
 struct irq_domain* irq_desc_get_handler_data (struct irq_desc*) ; 
 unsigned int irq_find_mapping (struct irq_domain*,unsigned int) ; 
 int /*<<< orphan*/  irq_set_chip_and_handler (unsigned int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  machine_restart (char*) ; 
 int /*<<< orphan*/  pr_emerg (char*) ; 
 int read_c0_cause () ; 
 int read_c0_status () ; 
 int /*<<< orphan*/  spurious_interrupt () ; 

__attribute__((used)) static inline bool is_ar2315(void)
{
	return (current_cpu_data.cputype == CPU_4KEC);
}

__attribute__((used)) static inline bool is_ar5312(void)
{
	return !is_ar2315();
}

__attribute__((used)) static inline void ar2315_arch_init_irq(void) {}

__attribute__((used)) static inline void ar2315_init_devices(void) {}

__attribute__((used)) static inline void ar2315_plat_time_init(void) {}

__attribute__((used)) static inline void ar2315_plat_mem_setup(void) {}

__attribute__((used)) static inline void ar2315_arch_init(void) {}

__attribute__((used)) static inline u32 ar2315_rst_reg_read(u32 reg)
{
	return __raw_readl(ar2315_rst_base + reg);
}

__attribute__((used)) static inline void ar2315_rst_reg_write(u32 reg, u32 val)
{
	__raw_writel(val, ar2315_rst_base + reg);
}

__attribute__((used)) static inline void ar2315_rst_reg_mask(u32 reg, u32 mask, u32 val)
{
	u32 ret = ar2315_rst_reg_read(reg);

	ret &= ~mask;
	ret |= val;
	ar2315_rst_reg_write(reg, ret);
}

__attribute__((used)) static irqreturn_t ar2315_ahb_err_handler(int cpl, void *dev_id)
{
	ar2315_rst_reg_write(AR2315_AHB_ERR0, AR2315_AHB_ERROR_DET);
	ar2315_rst_reg_read(AR2315_AHB_ERR1);

	pr_emerg("AHB fatal error\n");
	machine_restart("AHB error"); /* Catastrophic failure */

	return IRQ_HANDLED;
}

__attribute__((used)) static void ar2315_misc_irq_handler(struct irq_desc *desc)
{
	u32 pending = ar2315_rst_reg_read(AR2315_ISR) &
		      ar2315_rst_reg_read(AR2315_IMR);
	unsigned nr, misc_irq = 0;

	if (pending) {
		struct irq_domain *domain = irq_desc_get_handler_data(desc);

		nr = __ffs(pending);
		misc_irq = irq_find_mapping(domain, nr);
	}

	if (misc_irq) {
		if (nr == AR2315_MISC_IRQ_GPIO)
			ar2315_rst_reg_write(AR2315_ISR, AR2315_ISR_GPIO);
		else if (nr == AR2315_MISC_IRQ_WATCHDOG)
			ar2315_rst_reg_write(AR2315_ISR, AR2315_ISR_WD);
		generic_handle_irq(misc_irq);
	} else {
		spurious_interrupt();
	}
}

__attribute__((used)) static void ar2315_misc_irq_unmask(struct irq_data *d)
{
	ar2315_rst_reg_mask(AR2315_IMR, 0, BIT(d->hwirq));
}

__attribute__((used)) static void ar2315_misc_irq_mask(struct irq_data *d)
{
	ar2315_rst_reg_mask(AR2315_IMR, BIT(d->hwirq), 0);
}

__attribute__((used)) static int ar2315_misc_irq_map(struct irq_domain *d, unsigned irq,
			       irq_hw_number_t hw)
{
	irq_set_chip_and_handler(irq, &ar2315_misc_irq_chip, handle_level_irq);
	return 0;
}

__attribute__((used)) static void ar2315_irq_dispatch(void)
{
	u32 pending = read_c0_status() & read_c0_cause();

	if (pending & CAUSEF_IP3)
		do_IRQ(AR2315_IRQ_WLAN0);
#ifdef CONFIG_PCI_AR2315
	else if (pending & CAUSEF_IP5)
		do_IRQ(AR2315_IRQ_LCBUS_PCI);
#endif
	else if (pending & CAUSEF_IP2)
		do_IRQ(AR2315_IRQ_MISC);
	else if (pending & CAUSEF_IP7)
		do_IRQ(ATH25_IRQ_CPU_CLOCK);
	else
		spurious_interrupt();
}

