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
 int MBFL_WCSPLANE_UHC ; 
 int /*<<< orphan*/  mbfl_filt_conv_illegal_output (int,TYPE_2__*) ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int,int /*<<< orphan*/ ) ; 
 int* ucs_a1_uhc_table ; 
 int ucs_a1_uhc_table_max ; 
 int ucs_a1_uhc_table_min ; 
 int* ucs_a2_uhc_table ; 
 int ucs_a2_uhc_table_max ; 
 int ucs_a2_uhc_table_min ; 
 int* ucs_a3_uhc_table ; 
 int ucs_a3_uhc_table_max ; 
 int ucs_a3_uhc_table_min ; 
 int* ucs_i_uhc_table ; 
 int ucs_i_uhc_table_max ; 
 int ucs_i_uhc_table_min ; 
 int* ucs_r1_uhc_table ; 
 int ucs_r1_uhc_table_max ; 
 int ucs_r1_uhc_table_min ; 
 int* ucs_r2_uhc_table ; 
 int ucs_r2_uhc_table_max ; 
 int ucs_r2_uhc_table_min ; 
 int* ucs_s_uhc_table ; 
 int ucs_s_uhc_table_max ; 
 int ucs_s_uhc_table_min ; 
 int* uhc1_ucs_table ; 
 int uhc1_ucs_table_size ; 
 int* uhc2_ucs_table ; 
 int uhc2_ucs_table_size ; 
 int* uhc3_ucs_table ; 
 int uhc3_ucs_table_size ; 

int
mbfl_filt_conv_uhc_wchar(int c, mbfl_convert_filter *filter)
{
	int c1, w = 0, flag = 0;

	switch (filter->status) {
	case 0:
		if (c >= 0 && c < 0x80) {	/* latin */
			CK((*filter->output_function)(c, filter->data));
		} else if (c > 0x80 && c < 0xff && c != 0xc9) {	/* dbcs lead byte */
			filter->status = 1;
			filter->cache = c;
		} else {
			w = c & MBFL_WCSGROUP_MASK;
			w |= MBFL_WCSGROUP_THROUGH;
			CK((*filter->output_function)(w, filter->data));
		}
		break;

	case 1:		/* dbcs second byte */
		filter->status = 0;
		c1 = filter->cache;

		if ( c1 >= 0x81 && c1 <= 0xa0){
			w = (c1 - 0x81)*190 + (c - 0x41);
			if (w >= 0 && w < uhc1_ucs_table_size) {
				flag = 1;
				w = uhc1_ucs_table[w];
			} else {
				w = 0;
			}
		} else if ( c1 >= 0xa1 && c1 <= 0xc6){
			w = (c1 - 0xa1)*190 + (c - 0x41);
			if (w >= 0 && w < uhc2_ucs_table_size) {
				flag = 2;
				w = uhc2_ucs_table[w];
			} else {
				w = 0;
			}
		} else if ( c1 >= 0xc7 && c1 <= 0xfe){
			w = (c1 - 0xc7)*94 + (c - 0xa1);
			if (w >= 0 && w < uhc3_ucs_table_size) {
				flag = 3;
				w = uhc3_ucs_table[w];
			} else {
				w = 0;
			}
		}
		if (flag > 0){
			if (w <= 0) {
				w = (c1 << 8) | c;
				w &= MBFL_WCSPLANE_MASK;
				w |= MBFL_WCSPLANE_UHC;
			}
			CK((*filter->output_function)(w, filter->data));
		} else {
			if ((c >= 0 && c < 0x21) || c == 0x7f) {		/* CTLs */
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
mbfl_filt_conv_wchar_uhc(int c, mbfl_convert_filter *filter)
{
	int c1, s;

	s = 0;
	if (c >= ucs_a1_uhc_table_min && c < ucs_a1_uhc_table_max) {
		s = ucs_a1_uhc_table[c - ucs_a1_uhc_table_min];
	} else if (c >= ucs_a2_uhc_table_min && c < ucs_a2_uhc_table_max) {
		s = ucs_a2_uhc_table[c - ucs_a2_uhc_table_min];
	} else if (c >= ucs_a3_uhc_table_min && c < ucs_a3_uhc_table_max) {
		s = ucs_a3_uhc_table[c - ucs_a3_uhc_table_min];
	} else if (c >= ucs_i_uhc_table_min && c < ucs_i_uhc_table_max) {
		s = ucs_i_uhc_table[c - ucs_i_uhc_table_min];
	} else if (c >= ucs_s_uhc_table_min && c < ucs_s_uhc_table_max) {
		s = ucs_s_uhc_table[c - ucs_s_uhc_table_min];
	} else if (c >= ucs_r1_uhc_table_min && c < ucs_r1_uhc_table_max) {
		s = ucs_r1_uhc_table[c - ucs_r1_uhc_table_min];
	} else if (c >= ucs_r2_uhc_table_min && c < ucs_r2_uhc_table_max) {
		s = ucs_r2_uhc_table[c - ucs_r2_uhc_table_min];
	}
	if (s <= 0) {
		c1 = c & ~MBFL_WCSPLANE_MASK;
		if (c1 == MBFL_WCSPLANE_UHC) {
			s = c & MBFL_WCSPLANE_MASK;
		}
		if (c == 0) {
			s = 0;
		} else if (s <= 0) {
			s = -1;
		}
	}
	if (s >= 0) {
		if (s < 0x80) {	/* latin */
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

__attribute__((used)) static int mbfl_filt_ident_uhc(int c, mbfl_identify_filter *filter)
{
	switch (filter->status) {
	case 0: /* latin */
		if (c >= 0 && c < 0x80) { /* ok */
			;
		} else if (c >= 0x81 && c <= 0xa0) {	/* dbcs first char */
		    filter->status= 1;
		} else if (c >= 0xa1 && c <= 0xc6) {	/* dbcs first char */
		    filter->status= 2;
		} else if (c >= 0xc7 && c <= 0xfe) {	/* dbcs first char */
		    filter->status= 3;
		} else { /* bad */
			filter->flag = 1;
		}

	case 1:
	case 2:
		if (c < 0x41 || (c > 0x5a && c < 0x61)
			|| (c > 0x7a && c < 0x81) || c > 0xfe) {	/* bad */
		    filter->flag = 1;
		}
		filter->status = 0;
		break;

	case 3:
		if (c < 0xa1 || c > 0xfe) {	/* bad */
		    filter->flag = 1;
		}
		filter->status = 0;
		break;

	default:
		filter->status = 0;
		break;
	}

	return c;
}

