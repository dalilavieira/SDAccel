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
 int MBFL_WCSPLANE_JIS0208 ; 
 int MBFL_WCSPLANE_JIS0212 ; 
 int MBFL_WCSPLANE_MASK ; 
 int MBFL_WCSPLANE_WINCP932 ; 
 int /*<<< orphan*/  SJIS_DECODE (int,int,int,int) ; 
 int /*<<< orphan*/  SJIS_ENCODE (int,int,int,int) ; 
 int* cp932ext1_ucs_table ; 
 int cp932ext1_ucs_table_max ; 
 int cp932ext1_ucs_table_min ; 
 int* cp932ext2_ucs_table ; 
 int cp932ext2_ucs_table_max ; 
 int cp932ext2_ucs_table_min ; 
 int* cp932ext3_ucs_table ; 
 int cp932ext3_ucs_table_max ; 
 int cp932ext3_ucs_table_min ; 
 int* jisx0208_ucs_table ; 
 int jisx0208_ucs_table_size ; 
 int /*<<< orphan*/  mbfl_filt_conv_illegal_output (int,TYPE_2__*) ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int,int /*<<< orphan*/ ) ; 
 int* ucs_a1_jis_table ; 
 int ucs_a1_jis_table_max ; 
 int ucs_a1_jis_table_min ; 
 int* ucs_a2_jis_table ; 
 int ucs_a2_jis_table_max ; 
 int ucs_a2_jis_table_min ; 
 int* ucs_i_jis_table ; 
 int ucs_i_jis_table_max ; 
 int ucs_i_jis_table_min ; 
 int* ucs_r_jis_table ; 
 int ucs_r_jis_table_max ; 
 int ucs_r_jis_table_min ; 

int
mbfl_filt_conv_sjis_open_wchar(int c, mbfl_convert_filter *filter)
{
	int c1, s, s1, s2, w;

	switch (filter->status) {
	case 0:
		if (c >= 0 && c < 0x80) {	/* latin */
			CK((*filter->output_function)(c, filter->data));
		} else if (c > 0xa0 && c < 0xe0) {	/* kana */
			CK((*filter->output_function)(0xfec0 + c, filter->data));
		} else if (c > 0x80 && c < 0xfd && c != 0xa0) {	/* kanji first char */
			filter->status = 1;
			filter->cache = c;
		} else {
			w = c & MBFL_WCSGROUP_MASK;
			w |= MBFL_WCSGROUP_THROUGH;
			CK((*filter->output_function)(w, filter->data));
		}
		break;

	case 1:		/* kanji second char */
		filter->status = 0;
		c1 = filter->cache;
		if (c >= 0x40 && c <= 0xfc && c != 0x7f) {
			w = 0;
			SJIS_DECODE(c1, c, s1, s2);
			s = (s1 - 0x21)*94 + s2 - 0x21;
			if (s <= 137) {
				if (s == 31) {
					w = 0xff3c;			/* FULLWIDTH REVERSE SOLIDUS */
				} else if (s == 32) {
					w = 0xff5e;			/* FULLWIDTH TILDE */
				} else if (s == 33) {
					w = 0x2225;			/* PARALLEL TO */
				} else if (s == 60) {
					w = 0xff0d;			/* FULLWIDTH HYPHEN-MINUS */
				} else if (s == 80) {
					w = 0xffe0;			/* FULLWIDTH CENT SIGN */
				} else if (s == 81) {
					w = 0xffe1;			/* FULLWIDTH POUND SIGN */
				} else if (s == 137) {
					w = 0xffe2;			/* FULLWIDTH NOT SIGN */
				}
			}
			if (w == 0) {
				if (s >= cp932ext1_ucs_table_min && s < cp932ext1_ucs_table_max) {		/* vendor ext1 (13ku) */
					w = cp932ext1_ucs_table[s - cp932ext1_ucs_table_min];
				} else if (s >= 0 && s < jisx0208_ucs_table_size) {		/* X 0208 */
					w = jisx0208_ucs_table[s];
				} else if (s >= cp932ext2_ucs_table_min && s < cp932ext2_ucs_table_max) {		/* vendor ext2 (89ku - 92ku) */
					w = cp932ext2_ucs_table[s - cp932ext2_ucs_table_min];
				} else if (s >= cp932ext3_ucs_table_min && s < cp932ext3_ucs_table_max) {		/* vendor ext3 (115ku - 119ku) */
					w = cp932ext3_ucs_table[s - cp932ext3_ucs_table_min];
				} else if (s >= (94*94) && s < (114*94)) {		/* user (95ku - 114ku) */
					w = s - (94*94) + 0xe000;
				}
			}
			if (w <= 0) {
				w = (s1 << 8) | s2;
				w &= MBFL_WCSPLANE_MASK;
				w |= MBFL_WCSPLANE_WINCP932;
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
		break;

	default:
		filter->status = 0;
		break;
	}

	return c;
}

int
mbfl_filt_conv_wchar_sjis_open(int c, mbfl_convert_filter *filter)
{
	int c1, c2, s1, s2;

	s1 = 0;
	s2 = 0;
	if (c >= ucs_a1_jis_table_min && c < ucs_a1_jis_table_max) {
		s1 = ucs_a1_jis_table[c - ucs_a1_jis_table_min];
	} else if (c >= ucs_a2_jis_table_min && c < ucs_a2_jis_table_max) {
		s1 = ucs_a2_jis_table[c - ucs_a2_jis_table_min];
	} else if (c >= ucs_i_jis_table_min && c < ucs_i_jis_table_max) {
		s1 = ucs_i_jis_table[c - ucs_i_jis_table_min];
	} else if (c >= ucs_r_jis_table_min && c < ucs_r_jis_table_max) {
		s1 = ucs_r_jis_table[c - ucs_r_jis_table_min];
	} else if (c >= 0xe000 && c < (0xe000 + 20*94)) {	/* user  (95ku - 114ku) */
		s1 = c - 0xe000;
		c1 = s1/94 + 0x7f;
		c2 = s1%94 + 0x21;
		s1 = (c1 << 8) | c2;
		s2 = 1;
	}
	if (s1 <= 0) {
		c1 = c & ~MBFL_WCSPLANE_MASK;
		if (c1 == MBFL_WCSPLANE_WINCP932) {
			s1 = c & MBFL_WCSPLANE_MASK;
			s2 = 1;
		} else if (c1 == MBFL_WCSPLANE_JIS0208) {
			s1 = c & MBFL_WCSPLANE_MASK;
		} else if (c1 == MBFL_WCSPLANE_JIS0212) {
			s1 = c & MBFL_WCSPLANE_MASK;
			s1 |= 0x8080;
		} else if (c == 0xa5) {		/* YEN SIGN */
			s1 = 0x216f;	/* FULLWIDTH YEN SIGN */
		} else if (c == 0x203e) {	/* OVER LINE */
			s1 = 0x2131;	/* FULLWIDTH MACRON */
		} else if (c == 0xff3c) {	/* FULLWIDTH REVERSE SOLIDUS */
			s1 = 0x2140;
		} else if (c == 0xff5e) {	/* FULLWIDTH TILDE */
			s1 = 0x2141;
		} else if (c == 0x2225) {	/* PARALLEL TO */
			s1 = 0x2142;
		} else if (c == 0xff0d) {	/* FULLWIDTH HYPHEN-MINUS */
			s1 = 0x215d;
		} else if (c == 0xffe0) {	/* FULLWIDTH CENT SIGN */
			s1 = 0x2171;
		} else if (c == 0xffe1) {	/* FULLWIDTH POUND SIGN */
			s1 = 0x2172;
		} else if (c == 0xffe2) {	/* FULLWIDTH NOT SIGN */
			s1 = 0x224c;
		}
	}
	if ((s1 <= 0) || (s1 >= 0x8080 && s2 == 0)) {	/* not found or X 0212 */
		s1 = -1;
		c1 = 0;
		c2 = cp932ext1_ucs_table_max - cp932ext1_ucs_table_min;
		while (c1 < c2) {		/* CP932 vendor ext1 (13ku) */
			if (c == cp932ext1_ucs_table[c1]) {
				s1 = ((c1/94 + 0x2d) << 8) + (c1%94 + 0x21);
				break;
			}
			c1++;
		}
		if (s1 <= 0) {
			c1 = 0;
			c2 = cp932ext3_ucs_table_max - cp932ext3_ucs_table_min;
			while (c1 < c2) {		/* CP932 vendor ext3 (115ku - 119ku) */
				if (c == cp932ext3_ucs_table[c1]) {
					s1 = ((c1/94 + 0x93) << 8) + (c1%94 + 0x21);
					break;
				}
				c1++;
			}
		}
		if (c == 0) {
			s1 = 0;
		} else if (s1 <= 0) {
			s1 = -1;
		}
	}

	if (s1 >= 0) {
		if (s1 < 0x100) { /* latin or kana */
			CK((*filter->output_function)(s1, filter->data));
		} else { /* kanji */
			c1 = (s1 >> 8) & 0xff;
			c2 = s1 & 0xff;
			SJIS_ENCODE(c1, c2, s1, s2);
			CK((*filter->output_function)(s1, filter->data));
			CK((*filter->output_function)(s2, filter->data));
		}
	} else {
		if (filter->illegal_mode != MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE) {
			CK(mbfl_filt_conv_illegal_output(c, filter));
		}
	}

	return c;
}

__attribute__((used)) static int mbfl_filt_ident_sjis_open(int c, mbfl_identify_filter *filter)
{
	if (filter->status) {		/* kanji second char */
		if (c < 0x40 || c > 0xfc || c == 0x7f) {	/* bad */
		    filter->flag = 1;
		}
		filter->status = 0;
	} else if (c >= 0 && c < 0x80) {	/* latin  ok */
		;
	} else if (c > 0xa0 && c < 0xe0) {	/* kana  ok */
		;
	} else if (c > 0x80 && c < 0xfd && c != 0xa0) {	/* kanji first char */
		filter->status = 1;
	} else {							/* bad */
		filter->flag = 1;
	}

	return c;
}

