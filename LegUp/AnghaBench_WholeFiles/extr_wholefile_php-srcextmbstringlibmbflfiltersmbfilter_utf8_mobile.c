#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_13__ {int status; int cache; scalar_t__ illegal_mode; int /*<<< orphan*/  data; int /*<<< orphan*/  (* output_function ) (int,int /*<<< orphan*/ ) ;TYPE_1__* to; TYPE_2__* from; } ;
typedef  TYPE_3__ mbfl_convert_filter ;
struct TYPE_12__ {scalar_t__ no_encoding; } ;
struct TYPE_11__ {scalar_t__ no_encoding; } ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int /*<<< orphan*/ ) ; 
 scalar_t__ MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE ; 
 scalar_t__ mbfilter_conv_map_tbl (int,int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mbfilter_conv_r_map_tbl (int,int*,int /*<<< orphan*/ ,int) ; 
 int mbfilter_sjis_emoji_docomo2unicode (int,int*) ; 
 int mbfilter_sjis_emoji_kddi2unicode (int,int*) ; 
 int mbfilter_sjis_emoji_sb2unicode (int,int*) ; 
 scalar_t__ mbfilter_unicode2sjis_emoji_docomo (int,int*,TYPE_3__*) ; 
 scalar_t__ mbfilter_unicode2sjis_emoji_kddi (int,int*,TYPE_3__*) ; 
 scalar_t__ mbfilter_unicode2sjis_emoji_sb (int,int*,TYPE_3__*) ; 
 int /*<<< orphan*/  mbfl_docomo2uni_pua ; 
 int /*<<< orphan*/  mbfl_filt_conv_illegal_output (int,TYPE_3__*) ; 
 int /*<<< orphan*/  mbfl_filt_put_invalid_char (int,TYPE_3__*) ; 
 int /*<<< orphan*/  mbfl_kddi2uni_pua ; 
 int /*<<< orphan*/  mbfl_kddi2uni_pua_b ; 
 scalar_t__ mbfl_no_encoding_utf8_docomo ; 
 scalar_t__ mbfl_no_encoding_utf8_kddi_a ; 
 scalar_t__ mbfl_no_encoding_utf8_kddi_b ; 
 scalar_t__ mbfl_no_encoding_utf8_sb ; 
 int /*<<< orphan*/  mbfl_sb2uni_pua ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub10 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub12 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub8 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub9 (int,int /*<<< orphan*/ ) ; 

int mbfl_filt_conv_utf8_mobile_wchar(int c, mbfl_convert_filter *filter)
{
	int s, s1 = 0, c1 = 0, snd = 0;

retry:
	switch (filter->status & 0xff) {
	case 0x00:
		if (c < 0x80) {
			CK((*filter->output_function)(c, filter->data));
		} else if (c >= 0xc2 && c <= 0xdf) { /* 2byte code first char: 0xc2-0xdf */
			filter->status = 0x10;
			filter->cache = c & 0x1f;
		} else if (c >= 0xe0 && c <= 0xef) { /* 3byte code first char: 0xe0-0xef */
			filter->status = 0x20;
			filter->cache = c & 0xf;
		} else if (c >= 0xf0 && c <= 0xf4) { /* 3byte code first char: 0xf0-0xf4 */
			filter->status = 0x30;
			filter->cache = c & 0x7;
		} else {
			CK(mbfl_filt_put_invalid_char(c, filter));
		}
		break;
	case 0x10: /* 2byte code 2nd char: 0x80-0xbf */
	case 0x21: /* 3byte code 3rd char: 0x80-0xbf */
	case 0x32: /* 4byte code 4th char: 0x80-0xbf */
		filter->status = 0;
		if (c >= 0x80 && c <= 0xbf) {
			s = (filter->cache<<6) | (c & 0x3f);
			filter->cache = 0;

			if (filter->from->no_encoding == mbfl_no_encoding_utf8_docomo &&
				mbfilter_conv_r_map_tbl(s, &s1, mbfl_docomo2uni_pua, 4) > 0) {
				s = mbfilter_sjis_emoji_docomo2unicode(s1, &snd);
			} else if (filter->from->no_encoding == mbfl_no_encoding_utf8_kddi_a &&
					   mbfilter_conv_r_map_tbl(s, &s1, mbfl_kddi2uni_pua, 7) > 0) {
				s = mbfilter_sjis_emoji_kddi2unicode(s1, &snd);
			} else if (filter->from->no_encoding == mbfl_no_encoding_utf8_kddi_b &&
					   mbfilter_conv_r_map_tbl(s, &s1, mbfl_kddi2uni_pua_b, 8) > 0) {
				s = mbfilter_sjis_emoji_kddi2unicode(s1, &snd);
			} else if (filter->from->no_encoding == mbfl_no_encoding_utf8_sb &&
					   mbfilter_conv_r_map_tbl(s, &s1, mbfl_sb2uni_pua, 6) > 0) {
				s = mbfilter_sjis_emoji_sb2unicode(s1, &snd);
			}

			if (snd > 0) {
				CK((*filter->output_function)(snd, filter->data));
			}
			CK((*filter->output_function)(s, filter->data));
		} else {
			CK(mbfl_filt_put_invalid_char(filter->cache, filter));
			goto retry;
		}
		break;
	case 0x20: /* 3byte code 2nd char: 0:0xa0-0xbf,D:0x80-9F,1-C,E-F:0x80-0x9f */
		s = (filter->cache<<6) | (c & 0x3f);
		c1 = filter->cache & 0xf;

		if ((c >= 0x80 && c <= 0xbf) &&
			((c1 == 0x0 && c >= 0xa0) ||
			 (c1 == 0xd && c < 0xa0) ||
			 (c1 > 0x0 && c1 != 0xd))) {
			filter->cache = s;
			filter->status++;
		} else {
			CK(mbfl_filt_put_invalid_char(filter->cache, filter));
			goto retry;
		}
		break;
	case 0x30: /* 4byte code 2nd char: 0:0x90-0xbf,1-3:0x80-0xbf,4:0x80-0x8f */
		s = (filter->cache<<6) | (c & 0x3f);
		c1 = filter->cache & 0x7;

		if ((c >= 0x80 && c <= 0xbf) &&
			((c1 == 0x0 && c >= 0x90) ||
			 (c1 == 0x4 && c < 0x90) ||
			 (c1 > 0x0 && c1 != 0x4))) {
			filter->cache = s;
			filter->status++;
		} else {
			CK(mbfl_filt_put_invalid_char(filter->cache, filter));
			goto retry;
		}
		break;
	case 0x31: /* 4byte code 3rd char: 0x80-0xbf */
		if (c >= 0x80 && c <= 0xbf) {
			filter->cache = (filter->cache<<6) | (c & 0x3f);
			filter->status++;
		} else {
			CK(mbfl_filt_put_invalid_char(filter->cache, filter));
			goto retry;
		}
		break;
	default:
		filter->status = 0;
		break;
	}

	return c;
}

int mbfl_filt_conv_wchar_utf8_mobile(int c, mbfl_convert_filter *filter)
{
	if (c >= 0 && c < 0x110000) {
		int s1, c1;

		if ((filter->to->no_encoding == mbfl_no_encoding_utf8_docomo &&
			 mbfilter_unicode2sjis_emoji_docomo(c, &s1, filter) > 0 &&
			 mbfilter_conv_map_tbl(s1, &c1, mbfl_docomo2uni_pua, 4) > 0) ||
			(filter->to->no_encoding == mbfl_no_encoding_utf8_kddi_a &&
			 mbfilter_unicode2sjis_emoji_kddi(c, &s1, filter) > 0 &&
			 mbfilter_conv_map_tbl(s1, &c1, mbfl_kddi2uni_pua, 7) > 0) ||
			(filter->to->no_encoding == mbfl_no_encoding_utf8_kddi_b &&
			 mbfilter_unicode2sjis_emoji_kddi(c, &s1, filter) > 0 &&
			 mbfilter_conv_map_tbl(s1, &c1, mbfl_kddi2uni_pua_b, 8) > 0) ||
			(filter->to->no_encoding == mbfl_no_encoding_utf8_sb &&
			 mbfilter_unicode2sjis_emoji_sb(c, &s1, filter) > 0 &&
			 mbfilter_conv_map_tbl(s1, &c1, mbfl_sb2uni_pua, 6) > 0)) {
			c = c1;
		}

		if (filter->status == 1 && filter->cache > 0) {
			return c;
		}

		if (c < 0x80) {
			CK((*filter->output_function)(c, filter->data));
		} else if (c < 0x800) {
			CK((*filter->output_function)(((c >> 6) & 0x1f) | 0xc0, filter->data));
			CK((*filter->output_function)((c & 0x3f) | 0x80, filter->data));
		} else if (c < 0x10000) {
			CK((*filter->output_function)(((c >> 12) & 0x0f) | 0xe0, filter->data));
			CK((*filter->output_function)(((c >> 6) & 0x3f) | 0x80, filter->data));
			CK((*filter->output_function)((c & 0x3f) | 0x80, filter->data));
		} else {
			CK((*filter->output_function)(((c >> 18) & 0x07) | 0xf0, filter->data));
			CK((*filter->output_function)(((c >> 12) & 0x3f) | 0x80, filter->data));
			CK((*filter->output_function)(((c >> 6) & 0x3f) | 0x80, filter->data));
			CK((*filter->output_function)((c & 0x3f) | 0x80, filter->data));
		}
	} else {
		if (filter->illegal_mode != MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE) {
			CK(mbfl_filt_conv_illegal_output(c, filter));
		}
	}

	return c;
}

