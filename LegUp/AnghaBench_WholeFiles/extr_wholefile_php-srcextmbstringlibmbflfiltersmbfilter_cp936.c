#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int status; int flag; } ;
typedef  TYPE_1__ mbfl_identify_filter ;
struct TYPE_8__ {int status; int cache; scalar_t__ illegal_mode; int /*<<< orphan*/  data; int /*<<< orphan*/  (* output_function ) (int,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_2__ mbfl_convert_filter ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int /*<<< orphan*/ ) ; 
 scalar_t__ MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE ; 
 int MBFL_WCSGROUP_MASK ; 
 int MBFL_WCSGROUP_THROUGH ; 
 int MBFL_WCSPLANE_MASK ; 
 int MBFL_WCSPLANE_WINCP936 ; 
 int* cp936_ucs_table ; 
 int cp936_ucs_table_size ; 
 int** mbfl_cp936_pua_tbl ; 
 int mbfl_cp936_pua_tbl_max ; 
 int /*<<< orphan*/  mbfl_filt_conv_illegal_output (int,TYPE_2__*) ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub10 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub12 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int,int /*<<< orphan*/ ) ; 
 int* ucs_a1_cp936_table ; 
 int ucs_a1_cp936_table_max ; 
 int ucs_a1_cp936_table_min ; 
 int* ucs_a2_cp936_table ; 
 int ucs_a2_cp936_table_max ; 
 int ucs_a2_cp936_table_min ; 
 int* ucs_a3_cp936_table ; 
 int ucs_a3_cp936_table_max ; 
 int ucs_a3_cp936_table_min ; 
 int* ucs_cf_cp936_table ; 
 int ucs_cf_cp936_table_max ; 
 int ucs_cf_cp936_table_min ; 
 int* ucs_ci_cp936_table ; 
 int ucs_ci_cp936_table_max ; 
 int ucs_ci_cp936_table_min ; 
 int ucs_hff_cp936_table_max ; 
 int ucs_hff_cp936_table_min ; 
 int* ucs_hff_s_cp936_table ; 
 int* ucs_i_cp936_table ; 
 int ucs_i_cp936_table_max ; 
 int ucs_i_cp936_table_min ; 
 int* ucs_sfv_cp936_table ; 
 int ucs_sfv_cp936_table_max ; 
 int ucs_sfv_cp936_table_min ; 

int
mbfl_filt_conv_cp936_wchar(int c, mbfl_convert_filter *filter)
{
	int k;
	int c1, c2, w = -1;

	switch (filter->status) {
	case 0:
		if (c >= 0 && c < 0x80) {	/* latin */
			CK((*filter->output_function)(c, filter->data));
		} else if (c == 0x80) {	/* euro sign */
			CK((*filter->output_function)(0x20ac, filter->data));
		} else if (c < 0xff) {	/* dbcs lead byte */
			filter->status = 1;
			filter->cache = c;
		} else { /* 0xff */
			CK((*filter->output_function)(0xf8f5, filter->data));
		}
		break;

	case 1:		/* dbcs second byte */
		filter->status = 0;
		c1 = filter->cache;

		if (((c1 >= 0xaa && c1 <= 0xaf) || (c1 >= 0xf8 && c1 <= 0xfe)) &&
			(c >= 0xa1 && c <= 0xfe)) {
			/* UDA part1,2: U+E000-U+E4C5 */
			w = 94*(c1 >= 0xf8 ? c1 - 0xf2 : c1 - 0xaa) + (c - 0xa1) + 0xe000;
			CK((*filter->output_function)(w, filter->data));
		} else if (c1 >= 0xa1 && c1 <= 0xa7 && c >= 0x40 && c < 0xa1 && c != 0x7f) {
			/* UDA part3 : U+E4C6-U+E765*/
			w = 96*(c1 - 0xa1) + c - (c >= 0x80 ? 0x41 : 0x40) + 0xe4c6;
			CK((*filter->output_function)(w, filter->data));
		}

		c2 = (c1 << 8) | c;

		if (w <= 0 &&
			((c2 >= 0xa2ab && c2 <= 0xa9f0 + (0xe80f-0xe801)) ||
			 (c2 >= 0xd7fa && c2 <= 0xd7fa + (0xe814-0xe810)) ||
			 (c2 >= 0xfe50 && c2 <= 0xfe80 + (0xe864-0xe844)))) {
			for (k = 0; k < mbfl_cp936_pua_tbl_max; k++) {
				if (c2 >= mbfl_cp936_pua_tbl[k][2] &&
					c2 <= mbfl_cp936_pua_tbl[k][2] +
					mbfl_cp936_pua_tbl[k][1] -  mbfl_cp936_pua_tbl[k][0]) {
					w = c2 -  mbfl_cp936_pua_tbl[k][2] + mbfl_cp936_pua_tbl[k][0];
					CK((*filter->output_function)(w, filter->data));
					break;
				}
			}
		}

		if (w <= 0) {
			if (c1 < 0xff && c1 > 0x80 && c > 0x39 && c < 0xff && c != 0x7f) {
				w = (c1 - 0x81)*192 + (c - 0x40);
				if (w >= 0 && w < cp936_ucs_table_size) {
					w = cp936_ucs_table[w];
				} else {
					w = 0;
				}
				if (w <= 0) {
					w = (c1 << 8) | c;
					w &= MBFL_WCSPLANE_MASK;
					w |= MBFL_WCSPLANE_WINCP936;
				}
				CK((*filter->output_function)(w, filter->data));
			} else if ((c >= 0 && c < 0x21) || c == 0x7f) {		/* CTLs */
				CK((*filter->output_function)(c, filter->data));
			} else {
				w = (c1 << 8) | c;
				w &= MBFL_WCSGROUP_MASK;
				w |= MBFL_WCSGROUP_THROUGH;
				CK((*filter->output_function)(w, filter->data));
			}
		}
		break;

	default:
		filter->status = 0;
		break;
	}

	return c;
}

int
mbfl_filt_conv_wchar_cp936(int c, mbfl_convert_filter *filter)
{
	int k, k1, k2;
	int c1, s = 0;

	if (c >= ucs_a1_cp936_table_min && c < ucs_a1_cp936_table_max) {
		/* U+0000 - U+0451 */
		s = ucs_a1_cp936_table[c - ucs_a1_cp936_table_min];
	} else if (c >= ucs_a2_cp936_table_min && c < ucs_a2_cp936_table_max) {
		/* U+2000 - U+26FF */
		if (c == 0x203e) {
			s = 0xa3fe;
		} else if (c == 0x2218) {
			s = 0xa1e3;
		} else if (c == 0x223c) {
			s = 0xa1ab;
		} else {
			s = ucs_a2_cp936_table[c - ucs_a2_cp936_table_min];
		}
	} else if (c >= ucs_a3_cp936_table_min && c < ucs_a3_cp936_table_max) {
		/* U+2F00 - U+33FF */
		s = ucs_a3_cp936_table[c - ucs_a3_cp936_table_min];
	} else if (c >= ucs_i_cp936_table_min && c < ucs_i_cp936_table_max) {
		/* U+4D00-9FFF CJK Unified Ideographs (+ Extension A) */
		s = ucs_i_cp936_table[c - ucs_i_cp936_table_min];
	} else if (c >= 0xe000 && c <= 0xe864) { /* PUA */
		if (c < 0xe766) {
			if (c < 0xe4c6) {
				c1 = c - 0xe000;
				s = (c1 % 94) + 0xa1; c1 /= 94;
				s |= (c1 < 0x06 ? c1 + 0xaa : c1 + 0xf2) << 8;
			} else {
				c1 = c - 0xe4c6;
				s = ((c1 / 96) + 0xa1) << 8; c1 %= 96;
				s |= c1 + (c1 >= 0x3f ? 0x41 : 0x40);
			}
		} else {
			/* U+E766..U+E864 */
			k1 = 0; k2 = mbfl_cp936_pua_tbl_max;
			while (k1 < k2) {
				k = (k1 + k2) >> 1;
				if (c < mbfl_cp936_pua_tbl[k][0]) {
					k2 = k;
				} else if (c > mbfl_cp936_pua_tbl[k][1]) {
					k1 = k + 1;
				} else {
					s = c - mbfl_cp936_pua_tbl[k][0] + mbfl_cp936_pua_tbl[k][2];
					break;
				}
			}
		}
	} else if (c == 0xf8f5) {
		s = 0xff;
	} else if (c >= ucs_ci_cp936_table_min && c < ucs_ci_cp936_table_max) {
		/* U+F900-FA2F CJK Compatibility Ideographs */
		s = ucs_ci_cp936_table[c - ucs_ci_cp936_table_min];
	} else if (c >= ucs_cf_cp936_table_min && c < ucs_cf_cp936_table_max) {
		s = ucs_cf_cp936_table[c - ucs_cf_cp936_table_min];
	} else if (c >= ucs_sfv_cp936_table_min && c < ucs_sfv_cp936_table_max) {
		s = ucs_sfv_cp936_table[c - ucs_sfv_cp936_table_min]; /* U+FE50-FE6F Small Form Variants */
	} else if (c >= ucs_hff_cp936_table_min && c < ucs_hff_cp936_table_max) {
		/* U+FF00-FFFF HW/FW Forms */
		if (c == 0xff04) {
			s = 0xa1e7;
		} else if (c == 0xff5e) {
			s = 0xa1ab;
		} else if (c >= 0xff01 && c <= 0xff5d) {
			s = c - 0xff01 + 0xa3a1;
		} else if (c >= 0xffe0 && c <= 0xffe5) {
			s = ucs_hff_s_cp936_table[c-0xffe0];
		}
	}
	if (s <= 0) {
		c1 = c & ~MBFL_WCSPLANE_MASK;
		if (c1 == MBFL_WCSPLANE_WINCP936) {
			s = c & MBFL_WCSPLANE_MASK;
		}
		if (c == 0) {
			s = 0;
		} else if (s <= 0) {
			s = -1;
		}
	}
	if (s >= 0) {
		if (s <= 0x80 || s == 0xff) {	/* latin */
			CK((*filter->output_function)(s, filter->data));
		} else {
			CK((*filter->output_function)((s >> 8) & 0xff, filter->data));
			CK((*filter->output_function)(s & 0xff, filter->data));
		}
	} else {
		if (filter->illegal_mode != MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE) {
			CK(mbfl_filt_conv_illegal_output(c, filter));
		}
	}

	return c;
}

__attribute__((used)) static int mbfl_filt_ident_cp936(int c, mbfl_identify_filter *filter)
{
	if (filter->status) {		/* kanji second char */
		if (c < 0x40 || c > 0xfe || c == 0x7f) {	/* bad */
		    filter->flag = 1;
		}
		filter->status = 0;
	} else if (c >= 0 && c < 0x80) {	/* latin  ok */
		;
	} else if (c > 0x80 && c < 0xff) {	/* DBCS lead byte */
		filter->status = 1;
	} else {							/* bad */
		filter->flag = 1;
	}

	return c;
}

