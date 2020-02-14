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
typedef  int uint32_t ;
struct hw_translate {int /*<<< orphan*/ * funcs; } ;
struct gpio_pin_info {int mask; int offset; int offset_y; int offset_en; int offset_mask; int mask_y; int mask_en; int mask_mask; } ;
typedef  enum gpio_id { ____Placeholder_gpio_id } gpio_id ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_CRITICAL (int) ; 
 int DC_GPIO_DDC6_A__DC_GPIO_DDC6CLK_A_MASK ; 
 int DC_GPIO_DDC6_A__DC_GPIO_DDC6DATA_A_MASK ; 
#define  DC_GPIO_GENERIC_A__DC_GPIO_GENERICA_A_MASK 198 
#define  DC_GPIO_GENERIC_A__DC_GPIO_GENERICB_A_MASK 197 
#define  DC_GPIO_GENERIC_A__DC_GPIO_GENERICC_A_MASK 196 
#define  DC_GPIO_GENERIC_A__DC_GPIO_GENERICD_A_MASK 195 
#define  DC_GPIO_GENERIC_A__DC_GPIO_GENERICE_A_MASK 194 
#define  DC_GPIO_GENERIC_A__DC_GPIO_GENERICF_A_MASK 193 
#define  DC_GPIO_GENERIC_A__DC_GPIO_GENERICG_A_MASK 192 
#define  DC_GPIO_GENLK_A__DC_GPIO_GENLK_CLK_A_MASK 191 
#define  DC_GPIO_GENLK_A__DC_GPIO_GENLK_VSYNC_A_MASK 190 
#define  DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_A_A_MASK 189 
#define  DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_B_A_MASK 188 
#define  DC_GPIO_HPD_A__DC_GPIO_HPD1_A_MASK 187 
#define  DC_GPIO_HPD_A__DC_GPIO_HPD2_A_MASK 186 
#define  DC_GPIO_HPD_A__DC_GPIO_HPD3_A_MASK 185 
#define  DC_GPIO_HPD_A__DC_GPIO_HPD4_A_MASK 184 
#define  DC_GPIO_HPD_A__DC_GPIO_HPD5_A_MASK 183 
#define  DC_GPIO_HPD_A__DC_GPIO_HPD6_A_MASK 182 
#define  DC_GPIO_SYNCA_A__DC_GPIO_HSYNCA_A_MASK 181 
#define  DC_GPIO_SYNCA_A__DC_GPIO_VSYNCA_A_MASK 180 
#define  GPIO_DDC_LINE_DDC1 179 
#define  GPIO_DDC_LINE_DDC2 178 
#define  GPIO_DDC_LINE_DDC3 177 
#define  GPIO_DDC_LINE_DDC4 176 
#define  GPIO_DDC_LINE_DDC5 175 
#define  GPIO_DDC_LINE_DDC6 174 
#define  GPIO_DDC_LINE_DDC_VGA 173 
#define  GPIO_DDC_LINE_I2C_PAD 172 
#define  GPIO_GENERIC_A 171 
#define  GPIO_GENERIC_B 170 
#define  GPIO_GENERIC_C 169 
#define  GPIO_GENERIC_D 168 
#define  GPIO_GENERIC_E 167 
#define  GPIO_GENERIC_F 166 
#define  GPIO_GENERIC_G 165 
#define  GPIO_GSL_GENLOCK_CLOCK 164 
#define  GPIO_GSL_GENLOCK_VSYNC 163 
#define  GPIO_GSL_SWAPLOCK_A 162 
#define  GPIO_GSL_SWAPLOCK_B 161 
#define  GPIO_HPD_1 160 
#define  GPIO_HPD_2 159 
#define  GPIO_HPD_3 158 
#define  GPIO_HPD_4 157 
#define  GPIO_HPD_5 156 
#define  GPIO_HPD_6 155 
#define  GPIO_ID_DDC_CLOCK 154 
#define  GPIO_ID_DDC_DATA 153 
#define  GPIO_ID_GENERIC 152 
#define  GPIO_ID_GSL 151 
#define  GPIO_ID_HPD 150 
#define  GPIO_ID_SYNC 149 
#define  GPIO_ID_VIP_PAD 148 
#define  GPIO_SYNC_HSYNC_A 147 
#define  GPIO_SYNC_HSYNC_B 146 
#define  GPIO_SYNC_VSYNC_A 145 
#define  GPIO_SYNC_VSYNC_B 144 
 int /*<<< orphan*/  funcs ; 
#define  mmDC_GPIO_DDC1_A 143 
#define  mmDC_GPIO_DDC2_A 142 
#define  mmDC_GPIO_DDC3_A 141 
#define  mmDC_GPIO_DDC4_A 140 
#define  mmDC_GPIO_DDC5_A 139 
#define  mmDC_GPIO_DDC6_A 138 
#define  mmDC_GPIO_DDCVGA_A 137 
#define  mmDC_GPIO_DEBUG 136 
#define  mmDC_GPIO_GENERIC_A 135 
#define  mmDC_GPIO_GENLK_A 134 
#define  mmDC_GPIO_HPD_A 133 
#define  mmDC_GPIO_I2CPAD_A 132 
#define  mmDC_GPIO_PAD_STRENGTH_1 131 
#define  mmDC_GPIO_PAD_STRENGTH_2 130 
#define  mmDC_GPIO_PWRSEQ_A 129 
#define  mmDC_GPIO_SYNCA_A 128 

__attribute__((used)) static bool offset_to_id(
	uint32_t offset,
	uint32_t mask,
	enum gpio_id *id,
	uint32_t *en)
{
	switch (offset) {
	/* GENERIC */
	case mmDC_GPIO_GENERIC_A:
		*id = GPIO_ID_GENERIC;
		switch (mask) {
		case DC_GPIO_GENERIC_A__DC_GPIO_GENERICA_A_MASK:
			*en = GPIO_GENERIC_A;
			return true;
		case DC_GPIO_GENERIC_A__DC_GPIO_GENERICB_A_MASK:
			*en = GPIO_GENERIC_B;
			return true;
		case DC_GPIO_GENERIC_A__DC_GPIO_GENERICC_A_MASK:
			*en = GPIO_GENERIC_C;
			return true;
		case DC_GPIO_GENERIC_A__DC_GPIO_GENERICD_A_MASK:
			*en = GPIO_GENERIC_D;
			return true;
		case DC_GPIO_GENERIC_A__DC_GPIO_GENERICE_A_MASK:
			*en = GPIO_GENERIC_E;
			return true;
		case DC_GPIO_GENERIC_A__DC_GPIO_GENERICF_A_MASK:
			*en = GPIO_GENERIC_F;
			return true;
		case DC_GPIO_GENERIC_A__DC_GPIO_GENERICG_A_MASK:
			*en = GPIO_GENERIC_G;
			return true;
		default:
			ASSERT_CRITICAL(false);
			return false;
		}
	break;
	/* HPD */
	case mmDC_GPIO_HPD_A:
		*id = GPIO_ID_HPD;
		switch (mask) {
		case DC_GPIO_HPD_A__DC_GPIO_HPD1_A_MASK:
			*en = GPIO_HPD_1;
			return true;
		case DC_GPIO_HPD_A__DC_GPIO_HPD2_A_MASK:
			*en = GPIO_HPD_2;
			return true;
		case DC_GPIO_HPD_A__DC_GPIO_HPD3_A_MASK:
			*en = GPIO_HPD_3;
			return true;
		case DC_GPIO_HPD_A__DC_GPIO_HPD4_A_MASK:
			*en = GPIO_HPD_4;
			return true;
		case DC_GPIO_HPD_A__DC_GPIO_HPD5_A_MASK:
			*en = GPIO_HPD_5;
			return true;
		case DC_GPIO_HPD_A__DC_GPIO_HPD6_A_MASK:
			*en = GPIO_HPD_6;
			return true;
		default:
			ASSERT_CRITICAL(false);
			return false;
		}
	break;
	/* SYNCA */
	case mmDC_GPIO_SYNCA_A:
		*id = GPIO_ID_SYNC;
		switch (mask) {
		case DC_GPIO_SYNCA_A__DC_GPIO_HSYNCA_A_MASK:
			*en = GPIO_SYNC_HSYNC_A;
			return true;
		case DC_GPIO_SYNCA_A__DC_GPIO_VSYNCA_A_MASK:
			*en = GPIO_SYNC_VSYNC_A;
			return true;
		default:
			ASSERT_CRITICAL(false);
			return false;
		}
	break;
	/* mmDC_GPIO_GENLK_MASK */
	case mmDC_GPIO_GENLK_A:
		*id = GPIO_ID_GSL;
		switch (mask) {
		case DC_GPIO_GENLK_A__DC_GPIO_GENLK_CLK_A_MASK:
			*en = GPIO_GSL_GENLOCK_CLOCK;
			return true;
		case DC_GPIO_GENLK_A__DC_GPIO_GENLK_VSYNC_A_MASK:
			*en = GPIO_GSL_GENLOCK_VSYNC;
			return true;
		case DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_A_A_MASK:
			*en = GPIO_GSL_SWAPLOCK_A;
			return true;
		case DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_B_A_MASK:
			*en = GPIO_GSL_SWAPLOCK_B;
			return true;
		default:
			ASSERT_CRITICAL(false);
			return false;
		}
	break;
	/* DDC */
	/* we don't care about the GPIO_ID for DDC
	 * in DdcHandle it will use GPIO_ID_DDC_DATA/GPIO_ID_DDC_CLOCK
	 * directly in the create method */
	case mmDC_GPIO_DDC1_A:
		*en = GPIO_DDC_LINE_DDC1;
		return true;
	case mmDC_GPIO_DDC2_A:
		*en = GPIO_DDC_LINE_DDC2;
		return true;
	case mmDC_GPIO_DDC3_A:
		*en = GPIO_DDC_LINE_DDC3;
		return true;
	case mmDC_GPIO_DDC4_A:
		*en = GPIO_DDC_LINE_DDC4;
		return true;
	case mmDC_GPIO_DDC5_A:
		*en = GPIO_DDC_LINE_DDC5;
		return true;
	case mmDC_GPIO_DDC6_A:
		*en = GPIO_DDC_LINE_DDC6;
		return true;
	case mmDC_GPIO_DDCVGA_A:
		*en = GPIO_DDC_LINE_DDC_VGA;
		return true;
	/* GPIO_I2CPAD */
	case mmDC_GPIO_I2CPAD_A:
		*en = GPIO_DDC_LINE_I2C_PAD;
		return true;
	/* Not implemented */
	case mmDC_GPIO_PWRSEQ_A:
	case mmDC_GPIO_PAD_STRENGTH_1:
	case mmDC_GPIO_PAD_STRENGTH_2:
	case mmDC_GPIO_DEBUG:
		return false;
	/* UNEXPECTED */
	default:
		ASSERT_CRITICAL(false);
		return false;
	}
}

__attribute__((used)) static bool id_to_offset(
	enum gpio_id id,
	uint32_t en,
	struct gpio_pin_info *info)
{
	bool result = true;

	switch (id) {
	case GPIO_ID_DDC_DATA:
		info->mask = DC_GPIO_DDC6_A__DC_GPIO_DDC6DATA_A_MASK;
		switch (en) {
		case GPIO_DDC_LINE_DDC1:
			info->offset = mmDC_GPIO_DDC1_A;
		break;
		case GPIO_DDC_LINE_DDC2:
			info->offset = mmDC_GPIO_DDC2_A;
		break;
		case GPIO_DDC_LINE_DDC3:
			info->offset = mmDC_GPIO_DDC3_A;
		break;
		case GPIO_DDC_LINE_DDC4:
			info->offset = mmDC_GPIO_DDC4_A;
		break;
		case GPIO_DDC_LINE_DDC5:
			info->offset = mmDC_GPIO_DDC5_A;
		break;
		case GPIO_DDC_LINE_DDC6:
			info->offset = mmDC_GPIO_DDC6_A;
		break;
		case GPIO_DDC_LINE_DDC_VGA:
			info->offset = mmDC_GPIO_DDCVGA_A;
		break;
		case GPIO_DDC_LINE_I2C_PAD:
			info->offset = mmDC_GPIO_I2CPAD_A;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_DDC_CLOCK:
		info->mask = DC_GPIO_DDC6_A__DC_GPIO_DDC6CLK_A_MASK;
		switch (en) {
		case GPIO_DDC_LINE_DDC1:
			info->offset = mmDC_GPIO_DDC1_A;
		break;
		case GPIO_DDC_LINE_DDC2:
			info->offset = mmDC_GPIO_DDC2_A;
		break;
		case GPIO_DDC_LINE_DDC3:
			info->offset = mmDC_GPIO_DDC3_A;
		break;
		case GPIO_DDC_LINE_DDC4:
			info->offset = mmDC_GPIO_DDC4_A;
		break;
		case GPIO_DDC_LINE_DDC5:
			info->offset = mmDC_GPIO_DDC5_A;
		break;
		case GPIO_DDC_LINE_DDC6:
			info->offset = mmDC_GPIO_DDC6_A;
		break;
		case GPIO_DDC_LINE_DDC_VGA:
			info->offset = mmDC_GPIO_DDCVGA_A;
		break;
		case GPIO_DDC_LINE_I2C_PAD:
			info->offset = mmDC_GPIO_I2CPAD_A;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_GENERIC:
		info->offset = mmDC_GPIO_GENERIC_A;
		switch (en) {
		case GPIO_GENERIC_A:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICA_A_MASK;
		break;
		case GPIO_GENERIC_B:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICB_A_MASK;
		break;
		case GPIO_GENERIC_C:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICC_A_MASK;
		break;
		case GPIO_GENERIC_D:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICD_A_MASK;
		break;
		case GPIO_GENERIC_E:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICE_A_MASK;
		break;
		case GPIO_GENERIC_F:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICF_A_MASK;
		break;
		case GPIO_GENERIC_G:
			info->mask = DC_GPIO_GENERIC_A__DC_GPIO_GENERICG_A_MASK;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_HPD:
		info->offset = mmDC_GPIO_HPD_A;
		switch (en) {
		case GPIO_HPD_1:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD1_A_MASK;
		break;
		case GPIO_HPD_2:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD2_A_MASK;
		break;
		case GPIO_HPD_3:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD3_A_MASK;
		break;
		case GPIO_HPD_4:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD4_A_MASK;
		break;
		case GPIO_HPD_5:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD5_A_MASK;
		break;
		case GPIO_HPD_6:
			info->mask = DC_GPIO_HPD_A__DC_GPIO_HPD6_A_MASK;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_SYNC:
		switch (en) {
		case GPIO_SYNC_HSYNC_A:
			info->offset = mmDC_GPIO_SYNCA_A;
			info->mask = DC_GPIO_SYNCA_A__DC_GPIO_HSYNCA_A_MASK;
		break;
		case GPIO_SYNC_VSYNC_A:
			info->offset = mmDC_GPIO_SYNCA_A;
			info->mask = DC_GPIO_SYNCA_A__DC_GPIO_VSYNCA_A_MASK;
		break;
		case GPIO_SYNC_HSYNC_B:
		case GPIO_SYNC_VSYNC_B:
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_GSL:
		switch (en) {
		case GPIO_GSL_GENLOCK_CLOCK:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask = DC_GPIO_GENLK_A__DC_GPIO_GENLK_CLK_A_MASK;
		break;
		case GPIO_GSL_GENLOCK_VSYNC:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask =
				DC_GPIO_GENLK_A__DC_GPIO_GENLK_VSYNC_A_MASK;
		break;
		case GPIO_GSL_SWAPLOCK_A:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask = DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_A_A_MASK;
		break;
		case GPIO_GSL_SWAPLOCK_B:
			info->offset = mmDC_GPIO_GENLK_A;
			info->mask = DC_GPIO_GENLK_A__DC_GPIO_SWAPLOCK_B_A_MASK;
		break;
		default:
			ASSERT_CRITICAL(false);
			result = false;
		}
	break;
	case GPIO_ID_VIP_PAD:
	default:
		ASSERT_CRITICAL(false);
		result = false;
	}

	if (result) {
		info->offset_y = info->offset + 2;
		info->offset_en = info->offset + 1;
		info->offset_mask = info->offset - 1;

		info->mask_y = info->mask;
		info->mask_en = info->mask;
		info->mask_mask = info->mask;
	}

	return result;
}

void dal_hw_translate_dce110_init(struct hw_translate *tr)
{
	tr->funcs = &funcs;
}

