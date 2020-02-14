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
struct platform_device {int dummy; } ;
struct gpio_chip {int dummy; } ;

/* Variables and functions */
 int BIT (unsigned int) ; 
 int /*<<< orphan*/  BUG () ; 
 int /*<<< orphan*/  expstate_chip ; 
 int gpiochip_add_data (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  impwire_chip ; 

__attribute__((used)) static inline unsigned long enable_cp(unsigned long *cpenable)
{
	*cpenable = 0; /* avoid uninitialized value warning */
	return 0;
}

__attribute__((used)) static inline void disable_cp(unsigned long flags, unsigned long cpenable)
{
}

__attribute__((used)) static int xtensa_impwire_get_direction(struct gpio_chip *gc, unsigned offset)
{
	return 1; /* input only */
}

__attribute__((used)) static int xtensa_impwire_get_value(struct gpio_chip *gc, unsigned offset)
{
	unsigned long flags, saved_cpenable;
	u32 impwire;

	flags = enable_cp(&saved_cpenable);
	__asm__ __volatile__("read_impwire %0" : "=a" (impwire));
	disable_cp(flags, saved_cpenable);

	return !!(impwire & BIT(offset));
}

__attribute__((used)) static void xtensa_impwire_set_value(struct gpio_chip *gc, unsigned offset,
				    int value)
{
	BUG(); /* output only; should never be called */
}

__attribute__((used)) static int xtensa_expstate_get_direction(struct gpio_chip *gc, unsigned offset)
{
	return 0; /* output only */
}

__attribute__((used)) static int xtensa_expstate_get_value(struct gpio_chip *gc, unsigned offset)
{
	unsigned long flags, saved_cpenable;
	u32 expstate;

	flags = enable_cp(&saved_cpenable);
	__asm__ __volatile__("rur.expstate %0" : "=a" (expstate));
	disable_cp(flags, saved_cpenable);

	return !!(expstate & BIT(offset));
}

__attribute__((used)) static void xtensa_expstate_set_value(struct gpio_chip *gc, unsigned offset,
				     int value)
{
	unsigned long flags, saved_cpenable;
	u32 mask = BIT(offset);
	u32 val = value ? BIT(offset) : 0;

	flags = enable_cp(&saved_cpenable);
	__asm__ __volatile__("wrmsk_expstate %0, %1"
			     :: "a" (val), "a" (mask));
	disable_cp(flags, saved_cpenable);
}

__attribute__((used)) static int xtensa_gpio_probe(struct platform_device *pdev)
{
	int ret;

	ret = gpiochip_add_data(&impwire_chip, NULL);
	if (ret)
		return ret;
	return gpiochip_add_data(&expstate_chip, NULL);
}

