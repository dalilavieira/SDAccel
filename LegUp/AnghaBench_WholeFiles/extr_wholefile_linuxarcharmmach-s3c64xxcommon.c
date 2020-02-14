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
struct irq_desc {int dummy; } ;
typedef  enum reboot_mode { ____Placeholder_reboot_mode } reboot_mode ;

/* Variables and functions */
 unsigned int IRQ_EINT (unsigned int) ; 
 int REBOOT_SOFT ; 
 int /*<<< orphan*/  S3C64XX_EINT0MASK ; 
 int /*<<< orphan*/  S3C64XX_EINT0PEND ; 
 unsigned int __raw_readl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  generic_handle_irq (unsigned int) ; 
 int /*<<< orphan*/  samsung_wdt_reset () ; 
 int /*<<< orphan*/  soft_restart (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void s3c_irq_demux_eint(unsigned int start, unsigned int end)
{
	u32 status = __raw_readl(S3C64XX_EINT0PEND);
	u32 mask = __raw_readl(S3C64XX_EINT0MASK);
	unsigned int irq;

	status &= ~mask;
	status >>= start;
	status &= (1 << (end - start + 1)) - 1;

	for (irq = IRQ_EINT(start); irq <= IRQ_EINT(end); irq++) {
		if (status & 1)
			generic_handle_irq(irq);

		status >>= 1;
	}
}

__attribute__((used)) static void s3c_irq_demux_eint0_3(struct irq_desc *desc)
{
	s3c_irq_demux_eint(0, 3);
}

__attribute__((used)) static void s3c_irq_demux_eint4_11(struct irq_desc *desc)
{
	s3c_irq_demux_eint(4, 11);
}

__attribute__((used)) static void s3c_irq_demux_eint12_19(struct irq_desc *desc)
{
	s3c_irq_demux_eint(12, 19);
}

__attribute__((used)) static void s3c_irq_demux_eint20_27(struct irq_desc *desc)
{
	s3c_irq_demux_eint(20, 27);
}

void s3c64xx_restart(enum reboot_mode mode, const char *cmd)
{
	if (mode != REBOOT_SOFT)
		samsung_wdt_reset();

	/* if all else fails, or mode was for soft, jump to 0 */
	soft_restart(0);
}

