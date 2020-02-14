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
struct TYPE_13__ {int status; int cache; scalar_t__ illegal_mode; int (* flush_function ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  data; int /*<<< orphan*/  (* output_function ) (int,int /*<<< orphan*/ ) ;TYPE_2__* to; TYPE_1__* from; } ;
typedef  TYPE_3__ mbfl_convert_filter ;
struct TYPE_12__ {scalar_t__ no_encoding; } ;
struct TYPE_11__ {scalar_t__ no_encoding; } ;

/* Variables and functions */
 int /*<<< orphan*/  CK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CODE2JIS (int,int,int,int) ; 
 scalar_t__ MBFL_OUTPUTFILTER_ILLEGAL_MODE_NONE ; 
 int MBFL_WCSGROUP_MASK ; 
 int MBFL_WCSGROUP_THROUGH ; 
 int MBFL_WCSPLANE_JIS0208 ; 
 int MBFL_WCSPLANE_JIS0212 ; 
 int MBFL_WCSPLANE_MASK ; 
 int MBFL_WCSPLANE_WINCP932 ; 
 int NFLAGS (int) ; 
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
 int* mb_tbl_code2uni_docomo1 ; 
 int mb_tbl_code2uni_docomo1_max ; 
 int mb_tbl_code2uni_docomo1_min ; 
 int* mb_tbl_code2uni_kddi1 ; 
 int mb_tbl_code2uni_kddi1_max ; 
 int mb_tbl_code2uni_kddi1_min ; 
 int* mb_tbl_code2uni_kddi2 ; 
 int mb_tbl_code2uni_kddi2_max ; 
 int mb_tbl_code2uni_kddi2_min ; 
 int* mb_tbl_code2uni_sb1 ; 
 int mb_tbl_code2uni_sb1_max ; 
 int mb_tbl_code2uni_sb1_min ; 
 int* mb_tbl_code2uni_sb2 ; 
 int mb_tbl_code2uni_sb2_max ; 
 int mb_tbl_code2uni_sb2_min ; 
 int* mb_tbl_code2uni_sb3 ; 
 int mb_tbl_code2uni_sb3_max ; 
 int mb_tbl_code2uni_sb3_min ; 
 int /*<<< orphan*/  mb_tbl_uni_docomo2code2_key ; 
 int /*<<< orphan*/  mb_tbl_uni_docomo2code2_len ; 
 int mb_tbl_uni_docomo2code2_max ; 
 int mb_tbl_uni_docomo2code2_min ; 
 int* mb_tbl_uni_docomo2code2_value ; 
 int /*<<< orphan*/  mb_tbl_uni_docomo2code3_key ; 
 int /*<<< orphan*/  mb_tbl_uni_docomo2code3_len ; 
 int mb_tbl_uni_docomo2code3_max ; 
 int mb_tbl_uni_docomo2code3_min ; 
 int* mb_tbl_uni_docomo2code3_value ; 
 int /*<<< orphan*/  mb_tbl_uni_docomo2code5_key ; 
 int /*<<< orphan*/  mb_tbl_uni_docomo2code5_len ; 
 int mb_tbl_uni_docomo2code5_max ; 
 int mb_tbl_uni_docomo2code5_min ; 
 int* mb_tbl_uni_docomo2code5_val ; 
 int /*<<< orphan*/  mb_tbl_uni_kddi2code2_key ; 
 int /*<<< orphan*/  mb_tbl_uni_kddi2code2_len ; 
 int mb_tbl_uni_kddi2code2_max ; 
 int mb_tbl_uni_kddi2code2_min ; 
 int* mb_tbl_uni_kddi2code2_value ; 
 int /*<<< orphan*/  mb_tbl_uni_kddi2code3_key ; 
 int /*<<< orphan*/  mb_tbl_uni_kddi2code3_len ; 
 int mb_tbl_uni_kddi2code3_max ; 
 int mb_tbl_uni_kddi2code3_min ; 
 int* mb_tbl_uni_kddi2code3_value ; 
 int /*<<< orphan*/  mb_tbl_uni_kddi2code5_key ; 
 int /*<<< orphan*/  mb_tbl_uni_kddi2code5_len ; 
 int mb_tbl_uni_kddi2code5_max ; 
 int mb_tbl_uni_kddi2code5_min ; 
 int* mb_tbl_uni_kddi2code5_val ; 
 int /*<<< orphan*/  mb_tbl_uni_sb2code2_key ; 
 int /*<<< orphan*/  mb_tbl_uni_sb2code2_len ; 
 int mb_tbl_uni_sb2code2_max ; 
 int mb_tbl_uni_sb2code2_min ; 
 int* mb_tbl_uni_sb2code2_value ; 
 int /*<<< orphan*/  mb_tbl_uni_sb2code3_key ; 
 int /*<<< orphan*/  mb_tbl_uni_sb2code3_len ; 
 int mb_tbl_uni_sb2code3_max ; 
 int mb_tbl_uni_sb2code3_min ; 
 int* mb_tbl_uni_sb2code3_value ; 
 int /*<<< orphan*/  mb_tbl_uni_sb2code5_key ; 
 int /*<<< orphan*/  mb_tbl_uni_sb2code5_len ; 
 int mb_tbl_uni_sb2code5_max ; 
 int mb_tbl_uni_sb2code5_min ; 
 int* mb_tbl_uni_sb2code5_val ; 
 int mbfl_bisec_srch2 (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mbfl_filt_conv_illegal_output (int,TYPE_3__*) ; 
 scalar_t__ mbfl_no_encoding_sjis_docomo ; 
 scalar_t__ mbfl_no_encoding_sjis_kddi ; 
 scalar_t__ mbfl_no_encoding_sjis_sb ; 
 int* nflags_code_kddi ; 
 int* nflags_code_sb ; 
 int** nflags_s ; 
 int /*<<< orphan*/  stub1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub10 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub11 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub12 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub13 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub14 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub15 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub16 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub17 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub18 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub19 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub20 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub21 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub22 (int,int /*<<< orphan*/ ) ; 
 int stub23 (int /*<<< orphan*/ ) ; 
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
mbfilter_conv_map_tbl(int c, int *w, const unsigned short map[][3], int n)
{
	int i, match = 0;

	for (i = 0; i < n; i++) {
		if (map[i][0] <= c && c <= map[i][1]) {
			*w = c - map[i][0] + map[i][2];
			match = 1;
			break;
		}
	}
	return match;
}

int
mbfilter_conv_r_map_tbl(int c, int *w, const unsigned short map[][3], int n)
{
	int i, match = 0;

	for (i = 0; i < n; i++) {
		if (map[i][2] <= c && c <= map[i][2] - map[i][0] + map[i][1]) {
			*w = c + map[i][0] - map[i][2];
			match = 1;
			break;
		}
	}
	return match;
}

int
mbfilter_sjis_emoji_docomo2unicode(int s, int *snd)
{
	int w = s;
	if (s >= mb_tbl_code2uni_docomo1_min && s <= mb_tbl_code2uni_docomo1_max) {
		if (s >= mb_tbl_code2uni_docomo1_min + 0x00a2 &&
			s <= mb_tbl_code2uni_docomo1_min + 0x00ad &&
			s != mb_tbl_code2uni_docomo1_min + 0x00a3) {
			w =  0x20E3;
			*snd = mb_tbl_code2uni_docomo1[s - mb_tbl_code2uni_docomo1_min];
			if (*snd > 0xf000) {
				*snd += 0x10000;
			}
		} else {
			w = mb_tbl_code2uni_docomo1[s - mb_tbl_code2uni_docomo1_min];
			if (w > 0xf000) {
				w += 0x10000;
			} else if (w > 0xe000) { /* unsupported by Unicode 6.0 */
				w += 0xf0000;
			}
			*snd = 0;
			if (!w) {
				w = s;
			}
		}
	}

	return w;
}

int
mbfilter_sjis_emoji_kddi2unicode(int s, int *snd)
{
	int w = s, si, c;
	const int nflags_order_kddi[] = {3, 1, 5, 4, 0, 7};

	*snd = 0;
	if (s >= mb_tbl_code2uni_kddi1_min && s <= mb_tbl_code2uni_kddi1_max) {
		si = s - mb_tbl_code2uni_kddi1_min;
		if (si == 0x0008) { /* ES */
			*snd = NFLAGS(nflags_s[2][0]); w = NFLAGS(nflags_s[2][1]);
		} else if (si == 0x0009) { /* RU */
			*snd = NFLAGS(nflags_s[8][0]); w = NFLAGS(nflags_s[8][1]);
		} else if (si >= 0x008d && si <= 0x0092) {
			c = nflags_order_kddi[si-0x008d];
			*snd = NFLAGS(nflags_s[c][0]); w = NFLAGS(nflags_s[c][1]);
		} else if (si == 0x0104) {
			*snd = 0x0023; w = 0x20E3;
		} else {
			w = mb_tbl_code2uni_kddi1[si];
			if (w > 0xf000) {
				w += 0x10000;
			} else if (w > 0xe000) { /* unsupported by Unicode 6.0 */
				w += 0xf0000;
			}
		}
	} else if (s >= mb_tbl_code2uni_kddi2_min && s <= mb_tbl_code2uni_kddi2_max) {
		si = s - mb_tbl_code2uni_kddi2_min;
		if (si == 100) { /* JP */
			*snd = NFLAGS(nflags_s[6][0]); w = NFLAGS(nflags_s[6][1]);
		} else if (si >= 0x00ba && si <= 0x00c2) {
			*snd = si-0x00ba+0x0031; w = 0x20E3;
		} else if (si == 0x010b) { /* US */
			*snd = NFLAGS(nflags_s[9][0]); w = NFLAGS(nflags_s[9][1]);
		} else if (si == 0x0144) {
			*snd = 0x0030; w = 0x20E3;
		} else {
			w = mb_tbl_code2uni_kddi2[si];
			if (w > 0xf000) {
				w += 0x10000;
			} else if (w > 0xe000) { /* unsupported by Unicode 6.0 */
				w += 0xf0000;
			}
		}
	}
	return w;
}

int
mbfilter_sjis_emoji_sb2unicode(int s, int *snd)
{
	int w = s, si, c;
	const int nflags_order_sb[10] = {6, 9, 3, 1, 5, 4, 2, 8, 0, 7};

	*snd = 0;
	if (s >= mb_tbl_code2uni_sb1_min &&	s <= mb_tbl_code2uni_sb1_max) {
		si = s - mb_tbl_code2uni_sb1_min;
		if (si == 0x006e || (si >= 0x007a && si <= 0x0083)) {
			*snd =  mb_tbl_code2uni_sb1[si];
			if (*snd > 0xf000) {
				*snd += 0x10000;
			}
			w = 0x20E3;
		} else {
			w = mb_tbl_code2uni_sb1[si];
			if (w > 0xf000) {
				w += 0x10000;
			} else if (w > 0xe000) { /* unsupported by Unicode 6.0 */
				w += 0xf0000;
			}
		}
	} else if (s >= mb_tbl_code2uni_sb2_min && s <= mb_tbl_code2uni_sb2_max) {
		si = s - mb_tbl_code2uni_sb2_min;
		w = mb_tbl_code2uni_sb2[si];
		if (w > 0xf000) {
			w += 0x10000;
		} else if (w > 0xe000) { /* unsupported by Unicode 6.0 */
			w += 0xf0000;
		}
	} else if (s >= mb_tbl_code2uni_sb3_min && s <= mb_tbl_code2uni_sb3_max) {
		si = s - mb_tbl_code2uni_sb3_min;
		if (si >= 0x0069 && si <= 0x0072) {
			c = nflags_order_sb[si-0x0069];
			*snd = NFLAGS(nflags_s[c][0]); w = NFLAGS(nflags_s[c][1]);
		} else {
			w = mb_tbl_code2uni_sb3[si];
			if (w > 0xf000) {
				w += 0x10000;
			} else if (w > 0xe000) { /* unsupported by Unicode 6.0 */
				w += 0xf0000;
			}
		}
	}
	return w;
}

int
mbfilter_unicode2sjis_emoji_docomo(int c, int *s1, mbfl_convert_filter *filter)
{
	int i, match = 0, c1s;

	if (filter->status == 1) {
		c1s = filter->cache;
		filter->cache = 0;
		filter->status = 0;
		if (c == 0x20E3) {
			if (c1s == 0x0023) {
				*s1 = 0x2964;
				match = 1;
			} else if (c1s == 0x0030) {
				*s1 = 0x296f;
				match = 1;
			} else if (c1s >= 0x0031 && c1s <= 0x0039) {
				*s1 = 0x2966 + (c1s - 0x0031);
				match = 1;
			}
		} else {
			CK((*filter->output_function)(c1s, filter->data));
		}
	} else {
		if (c == 0x0023 || (c >= 0x0030 && c<=0x0039)) {
			filter->status = 1;
			filter->cache = c;
			*s1 = -1;
			return match;
		}

		if (c == 0x00A9) {
			*s1 = 0x29b5; match = 1;
		} else if (c == 0x00AE) {
			*s1 = 0x29ba; match = 1;
		} else if (c >= mb_tbl_uni_docomo2code2_min && c <= mb_tbl_uni_docomo2code2_max) {
			i = mbfl_bisec_srch2(c, mb_tbl_uni_docomo2code2_key, mb_tbl_uni_docomo2code2_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_docomo2code2_value[i];
				match = 1;
			}
		} else if (c >= mb_tbl_uni_docomo2code3_min && c <= mb_tbl_uni_docomo2code3_max) {
			i = mbfl_bisec_srch2(c - 0x10000, mb_tbl_uni_docomo2code3_key, mb_tbl_uni_docomo2code3_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_docomo2code3_value[i];
				match = 1;
			}
		} else if (c >= mb_tbl_uni_docomo2code5_min && c <= mb_tbl_uni_docomo2code5_max) {
			i = mbfl_bisec_srch2(c - 0xf0000, mb_tbl_uni_docomo2code5_key, mb_tbl_uni_docomo2code5_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_docomo2code5_val[i];
				match = 1;
			}
		}
	}

	return match;
}

int
mbfilter_unicode2sjis_emoji_kddi(int c, int *s1, mbfl_convert_filter *filter)
{
	int i, match = 0, c1s;

	if (filter->status == 1) {
		c1s = filter->cache;
		filter->cache = 0;
		filter->status = 0;
		if (c == 0x20E3) {
			if (c1s == 0x0023) {
				*s1 = 0x25bc;
				match = 1;
			} else if (c1s == 0x0030) {
				*s1 = 0x2830;
				match = 1;
			} else if (c1s >= 0x0031 && c1s <= 0x0039) {
				*s1 = 0x27a6 + (c1s - 0x0031);
				match = 1;
			}
		} else if ((c >= NFLAGS(0x41) && c <= NFLAGS(0x5A)) && (c1s >= NFLAGS(0x41) && c1s <= NFLAGS(0x5A))) {
			for (i=0; i<10; i++) {
				if (c1s == NFLAGS(nflags_s[i][0]) && c == NFLAGS(nflags_s[i][1])) {
					*s1 = nflags_code_kddi[i];
					match = 1;
					break;
				}
			}
		} else {
			if (c1s >= ucs_a1_jis_table_min && c1s < ucs_a1_jis_table_max) {
				c1s = ucs_a1_jis_table[c1s - ucs_a1_jis_table_min];
				CK((*filter->output_function)(c1s, filter->data));
			}
		}
	} else {
		if (c == 0x0023 || ( c >= 0x0030 && c<=0x0039) ||
			(c >= NFLAGS(0x41) && c<= NFLAGS(0x5A))) {
			filter->status = 1;
			filter->cache = c;
			*s1 = -1;
			return match;
		}

		if (c == 0x00A9) {
			*s1 = 0x27dc; match = 1;
		} else if (c == 0x00AE) {
			*s1 = 0x27dd; match = 1;
		} else if (c >= mb_tbl_uni_kddi2code2_min && c <= mb_tbl_uni_kddi2code2_max) {
			i = mbfl_bisec_srch2(c, mb_tbl_uni_kddi2code2_key, mb_tbl_uni_kddi2code2_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_kddi2code2_value[i];
				match = 1;
			}
		} else if (c >= mb_tbl_uni_kddi2code3_min && c <= mb_tbl_uni_kddi2code3_max) {
			i = mbfl_bisec_srch2(c - 0x10000, mb_tbl_uni_kddi2code3_key, mb_tbl_uni_kddi2code3_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_kddi2code3_value[i];
				match = 1;
			}
		} else if (c >= mb_tbl_uni_kddi2code5_min && c <= mb_tbl_uni_kddi2code5_max) {
			i = mbfl_bisec_srch2(c - 0xf0000, mb_tbl_uni_kddi2code5_key, mb_tbl_uni_kddi2code5_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_kddi2code5_val[i];
				match = 1;
			}
		}
	}

	return match;
}

int
mbfilter_unicode2sjis_emoji_sb(int c, int *s1, mbfl_convert_filter *filter)
{
	int i, match = 0, c1s;

	if (filter->status == 1) {
		filter->status = 0;
		c1s = filter->cache;
		filter->cache = 0;
		if (c == 0x20E3) {
			if (c1s == 0x0023) {
				*s1 = 0x2817;
				match = 1;
			} else if (c1s == 0x0030) {
				*s1 = 0x282c;
				match = 1;
			} else if (c1s >= 0x0031 && c1s <= 0x0039) {
				*s1 = 0x2823 + (c1s - 0x0031);
				match = 1;
			}
		} else if ((c >= NFLAGS(0x41) && c <= NFLAGS(0x5A)) && (c1s >= NFLAGS(0x41) && c1s <= NFLAGS(0x5A))) {
			for (i=0; i<10; i++) {
				if (c1s == NFLAGS(nflags_s[i][0]) && c == NFLAGS(nflags_s[i][1])) {
					*s1 = nflags_code_sb[i];
					match = 1;
					break;
				}
			}
		} else {
			if (c1s >= ucs_a1_jis_table_min && c1s < ucs_a1_jis_table_max) {
				c1s = ucs_a1_jis_table[c1s - ucs_a1_jis_table_min];
				CK((*filter->output_function)(c1s, filter->data));
			}
		}
	} else {
		if (c == 0x0023 || ( c >= 0x0030 && c<=0x0039) || (c >= NFLAGS(0x41) && c<= NFLAGS(0x5A))) {
			filter->status = 1;
			filter->cache = c;
			*s1 = -1;
			return match;
		}

		if (c == 0x00A9) {
			*s1 = 0x2855; match = 1;
		} else if (c == 0x00AE) {
			*s1 = 0x2856; match = 1;
		} else if (c >= mb_tbl_uni_sb2code2_min && c <= mb_tbl_uni_sb2code2_max) {
			i = mbfl_bisec_srch2(c, mb_tbl_uni_sb2code2_key, mb_tbl_uni_sb2code2_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_sb2code2_value[i];
				match = 1;
			}
		} else if (c >= mb_tbl_uni_sb2code3_min && c <= mb_tbl_uni_sb2code3_max) {
			i = mbfl_bisec_srch2(c - 0x10000, mb_tbl_uni_sb2code3_key, mb_tbl_uni_sb2code3_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_sb2code3_value[i];
				match = 1;
			}
		} else if (c >= mb_tbl_uni_sb2code5_min && c <= mb_tbl_uni_sb2code5_max) {
			i = mbfl_bisec_srch2(c - 0xf0000, mb_tbl_uni_sb2code5_key, mb_tbl_uni_sb2code5_len);
			if (i >= 0) {
				*s1 = mb_tbl_uni_sb2code5_val[i];
				match = 1;
			}
		}
	}
	return match;
}

int
mbfl_filt_conv_sjis_mobile_wchar(int c, mbfl_convert_filter *filter)
{
	int c1, s, s1 = 0, s2 = 0, w;
	int snd = 0;

retry:
	switch (filter->status) {
	case 0:
		if (c >= 0 && c < 0x80) {	/* latin */
			if (filter->from->no_encoding == mbfl_no_encoding_sjis_sb && c == 0x1b) {
				filter->cache = c;
				filter->status = 2;
			} else {
				CK((*filter->output_function)(c, filter->data));
			}
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

 				if (s >= (94*94) && s < 119*94) {
					if (filter->from->no_encoding == mbfl_no_encoding_sjis_docomo) {
						w = mbfilter_sjis_emoji_docomo2unicode(s, &snd);
					} else if (filter->from->no_encoding == mbfl_no_encoding_sjis_kddi) {
						w = mbfilter_sjis_emoji_kddi2unicode(s, &snd);
					} else if (filter->from->no_encoding == mbfl_no_encoding_sjis_sb) {
						w = mbfilter_sjis_emoji_sb2unicode(s, &snd);
					}

					if (w > 0  && snd > 0) {
						CK((*filter->output_function)(snd, filter->data));
					}
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
	/* ESC : Softbank Emoji */
	case 2:
		if (filter->from->no_encoding == mbfl_no_encoding_sjis_sb &&
			c == 0x24) {
				filter->cache = c;
				filter->status++;
		} else {
			filter->cache = 0;
			filter->status = 0;
			CK((*filter->output_function)(0x1b, filter->data));
			goto retry;
		}
		break;

	/* ESC $ : Softbank Emoji */
	case 3:
		if (filter->from->no_encoding == mbfl_no_encoding_sjis_sb &&
			((c >= 0x45 && c <= 0x47) || (c >= 0x4f && c <= 0x51))) {
				filter->cache = c;
				filter->status++;
		} else {
			filter->cache = 0;
			filter->status = 0;
			CK((*filter->output_function)(0x1b, filter->data));
			CK((*filter->output_function)(0x24, filter->data));
			goto retry;
		}
		break;

	/* ESC [GEFOPQ] : Softbank Emoji */
	case 4:
		w = 0;
		if (filter->from->no_encoding == mbfl_no_encoding_sjis_sb) {
			c1 = filter->cache;

			if (c == 0x0f) {
				w = c;
				filter->cache = 0;
				filter->status = 0;
			} else {
				if (c1 == 0x47 && c >= 0x21 && c <= 0x7a) {
					s1 = 0x91; s2 = c;
				} else if (c1 == 0x45 && c >= 0x21 && c <= 0x7a) {
					s1 = 0x8d; s2 = c;
				} else if (c1 == 0x46 && c >= 0x21 && c <= 0x7a) {
					s1 = 0x8e; s2 = c;
				} else if (c1 == 0x4f && c >= 0x21 && c <= 0x6d) {
					s1 = 0x92; s2 = c;
				} else if (c1 == 0x50 && c >= 0x21 && c <= 0x6c) {
					s1 = 0x95; s2 = c;
				} else if (c1 == 0x51 && c >= 0x21 && c <= 0x5e) {
					s1 = 0x96; s2 = c;
				}
				s  = (s1 - 0x21)*94 + s2 - 0x21;
				w = mbfilter_sjis_emoji_sb2unicode(s, &snd);
				if (w > 0) {
					if (snd > 0) {
						CK((*filter->output_function)(snd, filter->data));
					}
					CK((*filter->output_function)(w, filter->data));
				}
			}
		}

		if (w <= 0) {
			c1 = filter->cache;
			filter->cache = 0;
			filter->status = 0;
			CK((*filter->output_function)(0x1b, filter->data));
			CK((*filter->output_function)(0x24, filter->data));
			CK((*filter->output_function)(c1 & 0xff, filter->data));
			goto retry;
		}
		break;

	default:
		filter->status = 0;
		break;
	}

	return c;
}

int
mbfl_filt_conv_wchar_sjis_mobile(int c, mbfl_convert_filter *filter)
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
			c2 = cp932ext2_ucs_table_max - cp932ext2_ucs_table_min;
			while (c1 < c2) {		/* CP932 vendor ext2 (115ku - 119ku) */
				if (c == cp932ext2_ucs_table[c1]) {
					s1 = ((c1/94 + 0x93) << 8) + (c1%94 + 0x21);
					break;
				}
				c1++;
			}
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

 	if ((filter->to->no_encoding == mbfl_no_encoding_sjis_docomo &&
		 mbfilter_unicode2sjis_emoji_docomo(c, &s1, filter) > 0) ||
		(filter->to->no_encoding == mbfl_no_encoding_sjis_kddi &&
		 mbfilter_unicode2sjis_emoji_kddi(c, &s1, filter) > 0) ||
		(filter->to->no_encoding == mbfl_no_encoding_sjis_sb &&
		 mbfilter_unicode2sjis_emoji_sb(c, &s1, filter) > 0 )) {
		CODE2JIS(c1,c2,s1,s2);
 	}

	if (filter->status == 1 && filter->cache > 0) {
		return c;
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

int
mbfl_filt_conv_sjis_mobile_flush(mbfl_convert_filter *filter)
{
	int c1 = filter->cache;
	if (filter->status == 1 && (c1 == 0x0023 || (c1 >= 0x0030 && c1<=0x0039))) {
		CK((*filter->output_function)(c1, filter->data));
	}
	filter->status = 0;
	filter->cache = 0;

	if (filter->flush_function != NULL) {
		return (*filter->flush_function)(filter->data);
	}

	return 0;
}

