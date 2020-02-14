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
typedef  int u8 ;
struct clk_rate_request {int rate; unsigned long best_parent_rate; struct clk_hw* best_parent_hw; } ;
struct clk_hw {int dummy; } ;
struct at91sam9x5_clk_usb {int /*<<< orphan*/  regmap; } ;

/* Variables and functions */
 unsigned int AT91_PMC_OHCIUSBDIV ; 
 int /*<<< orphan*/  AT91_PMC_USB ; 
 unsigned int AT91_PMC_USBS ; 
 unsigned long DIV_ROUND_CLOSEST (unsigned long,unsigned long) ; 
 int EINVAL ; 
 unsigned int SAM9X5_USB_DIV_SHIFT ; 
 int SAM9X5_USB_MAX_DIV ; 
 int clk_hw_get_num_parents (struct clk_hw*) ; 
 struct clk_hw* clk_hw_get_parent_by_index (struct clk_hw*,int) ; 
 unsigned long clk_hw_round_rate (struct clk_hw*,unsigned long) ; 
 int /*<<< orphan*/  regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  regmap_update_bits (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int,unsigned int) ; 
 struct at91sam9x5_clk_usb* to_at91sam9x5_clk_usb (struct clk_hw*) ; 

__attribute__((used)) static inline void pmc_register_id(u8 id) {}

__attribute__((used)) static inline void pmc_register_pck(u8 pck) {}

__attribute__((used)) static unsigned long at91sam9x5_clk_usb_recalc_rate(struct clk_hw *hw,
						    unsigned long parent_rate)
{
	struct at91sam9x5_clk_usb *usb = to_at91sam9x5_clk_usb(hw);
	unsigned int usbr;
	u8 usbdiv;

	regmap_read(usb->regmap, AT91_PMC_USB, &usbr);
	usbdiv = (usbr & AT91_PMC_OHCIUSBDIV) >> SAM9X5_USB_DIV_SHIFT;

	return DIV_ROUND_CLOSEST(parent_rate, (usbdiv + 1));
}

__attribute__((used)) static int at91sam9x5_clk_usb_determine_rate(struct clk_hw *hw,
					     struct clk_rate_request *req)
{
	struct clk_hw *parent;
	long best_rate = -EINVAL;
	unsigned long tmp_rate;
	int best_diff = -1;
	int tmp_diff;
	int i;

	for (i = 0; i < clk_hw_get_num_parents(hw); i++) {
		int div;

		parent = clk_hw_get_parent_by_index(hw, i);
		if (!parent)
			continue;

		for (div = 1; div < SAM9X5_USB_MAX_DIV + 2; div++) {
			unsigned long tmp_parent_rate;

			tmp_parent_rate = req->rate * div;
			tmp_parent_rate = clk_hw_round_rate(parent,
							   tmp_parent_rate);
			tmp_rate = DIV_ROUND_CLOSEST(tmp_parent_rate, div);
			if (tmp_rate < req->rate)
				tmp_diff = req->rate - tmp_rate;
			else
				tmp_diff = tmp_rate - req->rate;

			if (best_diff < 0 || best_diff > tmp_diff) {
				best_rate = tmp_rate;
				best_diff = tmp_diff;
				req->best_parent_rate = tmp_parent_rate;
				req->best_parent_hw = parent;
			}

			if (!best_diff || tmp_rate < req->rate)
				break;
		}

		if (!best_diff)
			break;
	}

	if (best_rate < 0)
		return best_rate;

	req->rate = best_rate;
	return 0;
}

__attribute__((used)) static int at91sam9x5_clk_usb_set_parent(struct clk_hw *hw, u8 index)
{
	struct at91sam9x5_clk_usb *usb = to_at91sam9x5_clk_usb(hw);

	if (index > 1)
		return -EINVAL;

	regmap_update_bits(usb->regmap, AT91_PMC_USB, AT91_PMC_USBS,
			   index ? AT91_PMC_USBS : 0);

	return 0;
}

__attribute__((used)) static u8 at91sam9x5_clk_usb_get_parent(struct clk_hw *hw)
{
	struct at91sam9x5_clk_usb *usb = to_at91sam9x5_clk_usb(hw);
	unsigned int usbr;

	regmap_read(usb->regmap, AT91_PMC_USB, &usbr);

	return usbr & AT91_PMC_USBS;
}

__attribute__((used)) static int at91sam9x5_clk_usb_set_rate(struct clk_hw *hw, unsigned long rate,
				       unsigned long parent_rate)
{
	struct at91sam9x5_clk_usb *usb = to_at91sam9x5_clk_usb(hw);
	unsigned long div;

	if (!rate)
		return -EINVAL;

	div = DIV_ROUND_CLOSEST(parent_rate, rate);
	if (div > SAM9X5_USB_MAX_DIV + 1 || !div)
		return -EINVAL;

	regmap_update_bits(usb->regmap, AT91_PMC_USB, AT91_PMC_OHCIUSBDIV,
			   (div - 1) << SAM9X5_USB_DIV_SHIFT);

	return 0;
}

__attribute__((used)) static int at91sam9n12_clk_usb_enable(struct clk_hw *hw)
{
	struct at91sam9x5_clk_usb *usb = to_at91sam9x5_clk_usb(hw);

	regmap_update_bits(usb->regmap, AT91_PMC_USB, AT91_PMC_USBS,
			   AT91_PMC_USBS);

	return 0;
}

__attribute__((used)) static void at91sam9n12_clk_usb_disable(struct clk_hw *hw)
{
	struct at91sam9x5_clk_usb *usb = to_at91sam9x5_clk_usb(hw);

	regmap_update_bits(usb->regmap, AT91_PMC_USB, AT91_PMC_USBS, 0);
}

__attribute__((used)) static int at91sam9n12_clk_usb_is_enabled(struct clk_hw *hw)
{
	struct at91sam9x5_clk_usb *usb = to_at91sam9x5_clk_usb(hw);
	unsigned int usbr;

	regmap_read(usb->regmap, AT91_PMC_USB, &usbr);

	return usbr & AT91_PMC_USBS;
}

