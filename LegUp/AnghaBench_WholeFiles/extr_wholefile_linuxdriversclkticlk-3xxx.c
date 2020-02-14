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
struct clk_omap_reg {int offset; } ;
struct clk_hw_omap {int enable_bit; int /*<<< orphan*/  enable_reg; } ;

/* Variables and functions */
 int AM35XX_IPSS_CLK_IDLEST_VAL ; 
 int AM35XX_IPSS_ICK_EN_ACK_OFFSET ; 
 int AM35XX_IPSS_ICK_FCK_OFFSET ; 
 int AM35XX_IPSS_ICK_MASK ; 
 int AM35XX_ST_IPSS_SHIFT ; 
 int OMAP3430ES2_ST_DSS_IDLE_SHIFT ; 
 int OMAP3430ES2_ST_HSOTGUSB_IDLE_SHIFT ; 
 int OMAP3430ES2_ST_SSI_IDLE_SHIFT ; 
 int OMAP34XX_CM_IDLEST_VAL ; 
 int /*<<< orphan*/  memcpy (struct clk_omap_reg*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static void omap3430es2_clk_ssi_find_idlest(struct clk_hw_omap *clk,
					    struct clk_omap_reg *idlest_reg,
					    u8 *idlest_bit,
					    u8 *idlest_val)
{
	memcpy(idlest_reg, &clk->enable_reg, sizeof(*idlest_reg));
	idlest_reg->offset &= ~0xf0;
	idlest_reg->offset |= 0x20;
	*idlest_bit = OMAP3430ES2_ST_SSI_IDLE_SHIFT;
	*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}

__attribute__((used)) static void
omap3430es2_clk_dss_usbhost_find_idlest(struct clk_hw_omap *clk,
					struct clk_omap_reg *idlest_reg,
					u8 *idlest_bit, u8 *idlest_val)
{
	memcpy(idlest_reg, &clk->enable_reg, sizeof(*idlest_reg));

	idlest_reg->offset &= ~0xf0;
	idlest_reg->offset |= 0x20;
	/* USBHOST_IDLE has same shift */
	*idlest_bit = OMAP3430ES2_ST_DSS_IDLE_SHIFT;
	*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}

__attribute__((used)) static void
omap3430es2_clk_hsotgusb_find_idlest(struct clk_hw_omap *clk,
				     struct clk_omap_reg *idlest_reg,
				     u8 *idlest_bit,
				     u8 *idlest_val)
{
	memcpy(idlest_reg, &clk->enable_reg, sizeof(*idlest_reg));
	idlest_reg->offset &= ~0xf0;
	idlest_reg->offset |= 0x20;
	*idlest_bit = OMAP3430ES2_ST_HSOTGUSB_IDLE_SHIFT;
	*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}

__attribute__((used)) static void am35xx_clk_find_idlest(struct clk_hw_omap *clk,
				   struct clk_omap_reg *idlest_reg,
				   u8 *idlest_bit,
				   u8 *idlest_val)
{
	memcpy(idlest_reg, &clk->enable_reg, sizeof(*idlest_reg));
	*idlest_bit = clk->enable_bit + AM35XX_IPSS_ICK_EN_ACK_OFFSET;
	*idlest_val = AM35XX_IPSS_CLK_IDLEST_VAL;
}

__attribute__((used)) static void am35xx_clk_find_companion(struct clk_hw_omap *clk,
				      struct clk_omap_reg *other_reg,
				      u8 *other_bit)
{
	memcpy(other_reg, &clk->enable_reg, sizeof(*other_reg));
	if (clk->enable_bit & AM35XX_IPSS_ICK_MASK)
		*other_bit = clk->enable_bit + AM35XX_IPSS_ICK_FCK_OFFSET;
	else
	*other_bit = clk->enable_bit - AM35XX_IPSS_ICK_FCK_OFFSET;
}

__attribute__((used)) static void am35xx_clk_ipss_find_idlest(struct clk_hw_omap *clk,
					struct clk_omap_reg *idlest_reg,
					u8 *idlest_bit,
					u8 *idlest_val)
{
	memcpy(idlest_reg, &clk->enable_reg, sizeof(*idlest_reg));

	idlest_reg->offset &= ~0xf0;
	idlest_reg->offset |= 0x20;
	*idlest_bit = AM35XX_ST_IPSS_SHIFT;
	*idlest_val = OMAP34XX_CM_IDLEST_VAL;
}

