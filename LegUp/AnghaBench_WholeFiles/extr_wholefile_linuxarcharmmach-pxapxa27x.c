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
typedef  unsigned int uint32_t ;
struct irq_data {int irq; } ;

/* Variables and functions */
 int EINVAL ; 
 int IRQ_KEYPAD ; 
#define  IRQ_RTCAlrm 129 
#define  IRQ_USB 128 
 int PSSR ; 
 int PSSR_OTGPH ; 
 unsigned int PWER ; 
 unsigned int PWER_RTC ; 
 int /*<<< orphan*/ * ac97_reset_config ; 
 scalar_t__ cpu_is_pxa27x () ; 
 int gpio_set_wake (int,unsigned int) ; 
 int keypad_set_wake (unsigned int) ; 
 int /*<<< orphan*/  pxa2xx_mfp_config (int /*<<< orphan*/ *,int) ; 
 int pxa_irq_to_gpio (int) ; 

__attribute__((used)) static inline void pxa2xx_clear_reset_status(unsigned int mask) {}

void pxa27x_clear_otgph(void)
{
	if (cpu_is_pxa27x() && (PSSR & PSSR_OTGPH))
		PSSR |= PSSR_OTGPH;
}

void pxa27x_configure_ac97reset(int reset_gpio, bool to_gpio)
{
	/*
	 * This helper function is used to work around a bug in the pxa27x's
	 * ac97 controller during a warm reset.  The configuration of the
	 * reset_gpio is changed as follows:
	 * to_gpio == true: configured to generic output gpio and driven high
	 * to_gpio == false: configured to ac97 controller alt fn AC97_nRESET
	 */

	if (reset_gpio == 113)
		pxa2xx_mfp_config(to_gpio ? &ac97_reset_config[0] :
				  &ac97_reset_config[1], 1);

	if (reset_gpio == 95)
		pxa2xx_mfp_config(to_gpio ? &ac97_reset_config[2] :
				  &ac97_reset_config[3], 1);
}

__attribute__((used)) static inline void pxa27x_init_pm(void) {}

__attribute__((used)) static int pxa27x_set_wake(struct irq_data *d, unsigned int on)
{
	int gpio = pxa_irq_to_gpio(d->irq);
	uint32_t mask;

	if (gpio >= 0 && gpio < 128)
		return gpio_set_wake(gpio, on);

	if (d->irq == IRQ_KEYPAD)
		return keypad_set_wake(on);

	switch (d->irq) {
	case IRQ_RTCAlrm:
		mask = PWER_RTC;
		break;
	case IRQ_USB:
		mask = 1u << 26;
		break;
	default:
		return -EINVAL;
	}

	if (on)
		PWER |= mask;
	else
		PWER &=~mask;

	return 0;
}

