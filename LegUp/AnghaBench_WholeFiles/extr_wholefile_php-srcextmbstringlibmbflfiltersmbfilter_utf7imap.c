#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int status; int cache; scalar_t__ illegal_mode; int /*<<< orphan*/  data; int /*<<< orphan*/  (* output_function ) (int,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* filter_function ) (int,TYPE_1__*) ;} ;
typedef  TYPE_1__ mbfl_convert_filter ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int /*<<< orphan*/ ) ; 
 scalar_t__ MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE ; 
 int MBFL_WCSGROUP_MASK ; 
 int MBFL_WCSGROUP_THROUGH ; 
 int MBFL_WCSPLANE_SUPMAX ; 
 int MBFL_WCSPLANE_SUPMIN ; 
 int MBFL_WCSPLANE_UCS2MAX ; 
 int /*<<< orphan*/  mbfl_filt_conv_illegal_output (int,TYPE_1__*) ; 
 int* mbfl_utf7imap_base64_table ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub10 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub12 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub14 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub15 (int,TYPE_1__*) ; 
 int /*<<< orphan*/  stub16 (int,TYPE_1__*) ; 
 int /*<<< orphan*/  stub17 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub18 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub19 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub20 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub21 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub22 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub23 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub24 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub25 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub26 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub27 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub28 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub29 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub30 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub31 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub32 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub33 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub34 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub35 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub36 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub37 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub38 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub39 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub40 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub41 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub42 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub43 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub44 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub45 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub46 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub47 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub48 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub49 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub50 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub51 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int,int /*<<< orphan*/ ) ; 

int mbfl_filt_conv_utf7imap_wchar(int c, mbfl_convert_filter *filter)
{
	int s, n;

	n = -1;
	if (filter->status != 0) {		/* Modified Base64 */
		if (c >= 0x41 && c <= 0x5a) {		/* A - Z */
			n = c - 65;
		} else if (c >= 0x61 && c <= 0x7a) {	/* a - z */
			n = c - 71;
		} else if (c >= 0x30 && c <= 0x39) {	/* 0 - 9 */
			n = c + 4;
		} else if (c == 0x2b) {			/* '+' */
			n = 62;
		} else if (c == 0x2c) {			/* ',' */
			n = 63;
		}
		if (n < 0 || n > 63) {
			if (c == 0x2d) {
				if (filter->status == 1) {		/* "&-" -> "&" */
					CK((*filter->output_function)(0x26, filter->data));
				}
			} else if (c >= 0 && c < 0x80) {	/* ASCII exclude '-' */
				CK((*filter->output_function)(c, filter->data));
			} else {		/* illegal character */
				s = c & MBFL_WCSGROUP_MASK;
				s |= MBFL_WCSGROUP_THROUGH;
				CK((*filter->output_function)(s, filter->data));
			}
			filter->cache = 0;
			filter->status = 0;
			return c;
		}
	}

	switch (filter->status) {
	/* directly encoded characters */
	case 0:
		if (c == 0x26) {	/* '&'  shift character */
			filter->status++;
		} else if (c >= 0 && c < 0x80) {	/* ASCII */
			CK((*filter->output_function)(c, filter->data));
		} else {		/* illegal character */
			s = c & MBFL_WCSGROUP_MASK;
			s |= MBFL_WCSGROUP_THROUGH;
			CK((*filter->output_function)(s, filter->data));
		}
		break;

	/* decode Modified Base64 */
	case 1:
	case 2:
		filter->cache |= n << 10;
		filter->status = 3;
		break;
	case 3:
		filter->cache |= n << 4;
		filter->status = 4;
		break;
	case 4:
		s = ((n >> 2) & 0xf) | (filter->cache & 0xffff);
		n = (n & 0x3) << 14;
		filter->status = 5;
		if (s >= 0xd800 && s < 0xdc00) {
			s = (((s & 0x3ff) << 16) + 0x400000) | n;
			filter->cache = s;
		} else if (s >= 0xdc00 && s < 0xe000) {
			s &= 0x3ff;
			s |= (filter->cache & 0xfff0000) >> 6;
			filter->cache = n;
			if (s >= MBFL_WCSPLANE_SUPMIN && s < MBFL_WCSPLANE_SUPMAX) {
				CK((*filter->output_function)(s, filter->data));
			} else {		/* illegal character */
				s &= MBFL_WCSGROUP_MASK;
				s |= MBFL_WCSGROUP_THROUGH;
				CK((*filter->output_function)(s, filter->data));
			}
		} else {
			filter->cache = n;
			CK((*filter->output_function)(s, filter->data));
		}
		break;

	case 5:
		filter->cache |= n << 8;
		filter->status = 6;
		break;
	case 6:
		filter->cache |= n << 2;
		filter->status = 7;
		break;
	case 7:
		s = ((n >> 4) & 0x3) | (filter->cache & 0xffff);
		n = (n & 0xf) << 12;
		filter->status = 8;
		if (s >= 0xd800 && s < 0xdc00) {
			s = (((s & 0x3ff) << 16) + 0x400000) | n;
			filter->cache = s;
		} else if (s >= 0xdc00 && s < 0xe000) {
			s &= 0x3ff;
			s |= (filter->cache & 0xfff0000) >> 6;
			filter->cache = n;
			if (s >= MBFL_WCSPLANE_SUPMIN && s < MBFL_WCSPLANE_SUPMAX) {
				CK((*filter->output_function)(s, filter->data));
			} else {		/* illegal character */
				s &= MBFL_WCSGROUP_MASK;
				s |= MBFL_WCSGROUP_THROUGH;
				CK((*filter->output_function)(s, filter->data));
			}
		} else {
			filter->cache = n;
			CK((*filter->output_function)(s, filter->data));
		}
		break;

	case 8:
		filter->cache |= n << 6;
		filter->status = 9;
		break;
	case 9:
		s = n | (filter->cache & 0xffff);
		filter->status = 2;
		if (s >= 0xd800 && s < 0xdc00) {
			s = (((s & 0x3ff) << 16) + 0x400000);
			filter->cache = s;
		} else if (s >= 0xdc00 && s < 0xe000) {
			s &= 0x3ff;
			s |= (filter->cache & 0xfff0000) >> 6;
			filter->cache = 0;
			if (s >= MBFL_WCSPLANE_SUPMIN && s < MBFL_WCSPLANE_SUPMAX) {
				CK((*filter->output_function)(s, filter->data));
			} else {		/* illegal character */
				s &= MBFL_WCSGROUP_MASK;
				s |= MBFL_WCSGROUP_THROUGH;
				CK((*filter->output_function)(s, filter->data));
			}
		} else {
			filter->cache = 0;
			CK((*filter->output_function)(s, filter->data));
		}
		break;

	default:
		filter->status = 0;
		break;
	}

	return c;
}

int mbfl_filt_conv_wchar_utf7imap(int c, mbfl_convert_filter *filter)
{
	int n, s;

	n = 0;
	if (c == 0x26) {
		n = 1;
	} else if ((c >= 0x20 && c <= 0x7e) || c == 0) {
		n = 2;
	} else if (c >= 0 && c < MBFL_WCSPLANE_UCS2MAX) {
		;
	} else if (c >= MBFL_WCSPLANE_SUPMIN && c < MBFL_WCSPLANE_SUPMAX) {
		s = ((c >> 10) - 0x40) | 0xd800;
		CK((*filter->filter_function)(s, filter));
		s = (c & 0x3ff) | 0xdc00;
		CK((*filter->filter_function)(s, filter));
		return c;
	} else {
		if (filter->illegal_mode != MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE) {
			CK(mbfl_filt_conv_illegal_output(c, filter));
		}
		return c;
	}

	switch (filter->status) {
	case 0:
		if (n != 0) {	/* directly encode characters */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
		} else {	/* Modified Base64 */
			CK((*filter->output_function)(0x26, filter->data));		/* '&' */
			filter->status = 1;
			filter->cache = c;
		}
		break;

	/* encode Modified Base64 */
	case 1:
		s = filter->cache;
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 10) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 4) & 0x3f], filter->data));
		if (n != 0) {
			CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s << 2) & 0x3c], filter->data));
			CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
			filter->status = 0;
		} else {
			filter->status = 2;
			filter->cache = ((s & 0xf) << 16) | c;
		}
		break;

	case 2:
		s = filter->cache;
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 14) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 8) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 2) & 0x3f], filter->data));
		if (n != 0) {
			CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s << 4) & 0x30], filter->data));
			CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
			filter->status = 0;
		} else {
			filter->status = 3;
			filter->cache = ((s & 0x3) << 16) | c;
		}
		break;

	case 3:
		s = filter->cache;
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 12) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(s >> 6) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[s & 0x3f], filter->data));
		if (n != 0) {
			CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			CK((*filter->output_function)(c, filter->data));
			if (n == 1) {
				CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
			}
			filter->status = 0;
		} else {
			filter->status = 1;
			filter->cache = c;
		}
		break;

	default:
		filter->status = 0;
		break;
	}

	return c;

}

int mbfl_filt_conv_wchar_utf7imap_flush(mbfl_convert_filter *filter)
{
	int status, cache;

	status = filter->status;
	cache = filter->cache;
	filter->status = 0;
	filter->cache = 0;
	/* flush fragments */
	switch (status) {
	case 1:
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache >> 10) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache >> 4) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache << 2) & 0x3c], filter->data));
		CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
		break;

	case 2:
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache >> 14) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache >> 8) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache >> 2) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache << 4) & 0x30], filter->data));
		CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
		break;

	case 3:
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache >> 12) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[(cache >> 6) & 0x3f], filter->data));
		CK((*filter->output_function)(mbfl_utf7imap_base64_table[cache & 0x3f], filter->data));
		CK((*filter->output_function)(0x2d, filter->data));		/* '-' */
		break;
	}
	return 0;
}

