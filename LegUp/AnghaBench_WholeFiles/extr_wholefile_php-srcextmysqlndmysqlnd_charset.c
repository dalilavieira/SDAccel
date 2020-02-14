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
typedef  int zend_uchar ;
typedef  int /*<<< orphan*/  zend_bool ;
typedef  int uint32_t ;
struct st_mysqlnd_plugin_header {int dummy; } ;
typedef  unsigned int const* start ;
typedef  int end ;
struct TYPE_8__ {int l; char* member_0; int /*<<< orphan*/  member_1; int /*<<< orphan*/  s; } ;
struct TYPE_7__ {char* member_0; int member_1; char* s; int /*<<< orphan*/  l; } ;
typedef  TYPE_1__ const MYSQLND_STRING ;
typedef  TYPE_2__ const MYSQLND_CSTRING ;

/* Variables and functions */
 scalar_t__ UTF16_HIGH_HEAD (unsigned int const) ; 
 scalar_t__ UTF16_LOW_HEAD (char const) ; 
 scalar_t__ is_gb18030_even_2 (char const) ; 
 scalar_t__ is_gb18030_even_4 (char const) ; 
 scalar_t__ is_gb18030_odd (char const) ; 
 int /*<<< orphan*/  memcpy (char*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ mnd_pemalloc (int,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  mysqlnd_plugin_charsets_plugin ; 
 int /*<<< orphan*/  mysqlnd_plugin_register_ex (struct st_mysqlnd_plugin_header*) ; 
 scalar_t__ valid_big5head (unsigned int const) ; 
 scalar_t__ valid_big5tail (char const) ; 
 scalar_t__ valid_cp932head (int) ; 
 scalar_t__ valid_cp932tail (int) ; 
 scalar_t__ valid_eucjpms (unsigned int const) ; 
 scalar_t__ valid_eucjpms_kata (char const) ; 
 scalar_t__ valid_eucjpms_ss2 (unsigned int const) ; 
 scalar_t__ valid_eucjpms_ss3 (unsigned int const) ; 
 scalar_t__ valid_euckr (unsigned int const) ; 
 scalar_t__ valid_gb2312_head (unsigned int const) ; 
 scalar_t__ valid_gb2312_tail (unsigned int) ; 
 scalar_t__ valid_gbk_head (unsigned int const) ; 
 scalar_t__ valid_gbk_tail (char const) ; 
 scalar_t__ valid_sjis_head (int) ; 
 scalar_t__ valid_sjis_tail (int) ; 
 scalar_t__ valid_ujis (unsigned int const) ; 
 scalar_t__ valid_ujis_kata (unsigned int const) ; 
 scalar_t__ valid_ujis_ss2 (unsigned int const) ; 
 scalar_t__ valid_ujis_ss3 (unsigned int const) ; 

__attribute__((used)) static inline MYSQLND_STRING mnd_dup_cstring(const MYSQLND_CSTRING str, const zend_bool persistent)
{
	const MYSQLND_STRING ret = {(char*) mnd_pemalloc(str.l + 1, persistent), str.l};
	if (ret.s) {
		memcpy(ret.s, str.s, str.l);
		ret.s[str.l] = '\0';
	}
	return ret;
}

__attribute__((used)) static inline MYSQLND_CSTRING mnd_str2c(const MYSQLND_STRING str)
{
	const MYSQLND_CSTRING ret = {str.s, str.l};
	return ret;
}

__attribute__((used)) static inline void DBG_INF(const char * const msg) {}

__attribute__((used)) static inline void DBG_ERR(const char * const msg) {}

__attribute__((used)) static inline void DBG_INF_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void DBG_ERR_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void DBG_ENTER(const char * const func_name) {}

__attribute__((used)) static inline void TRACE_ALLOC_INF(const char * const msg) {}

__attribute__((used)) static inline void TRACE_ALLOC_ERR(const char * const msg) {}

__attribute__((used)) static inline void TRACE_ALLOC_INF_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void TRACE_ALLOC_ERR_FMT(const char * const format, ...) {}

__attribute__((used)) static inline void TRACE_ALLOC_ENTER(const char * const func_name) {}

__attribute__((used)) static unsigned int check_mb_utf8mb3_sequence(const char * const start, const char * const end)
{
	zend_uchar	c;

	if (start >= end) {
		return 0;
	}

	c = (zend_uchar) start[0];

	if (c < 0x80) {
		return 1;		/* single byte character */
	}
	if (c < 0xC2) {
		return 0;		/* invalid mb character */
	}
	if (c < 0xE0) {
		if (start + 2 > end) {
			return 0;	/* too small */
		}
		if (!(((zend_uchar)start[1] ^ 0x80) < 0x40)) {
			return 0;
		}
		return 2;
	}
	if (c < 0xF0) {
		if (start + 3 > end) {
			return 0;	/* too small */
		}
		if (!(((zend_uchar)start[1] ^ 0x80) < 0x40 && ((zend_uchar)start[2] ^ 0x80) < 0x40 &&
			(c >= 0xE1 || (zend_uchar)start[1] >= 0xA0))) {
			return 0;	/* invalid utf8 character */
		}
		return 3;
	}
	return 0;
}

__attribute__((used)) static unsigned int check_mb_utf8_sequence(const char * const start, const char * const end)
{
	zend_uchar	c;

	if (start >= end) {
		return 0;
	}

	c = (zend_uchar) start[0];

	if (c < 0x80) {
		return 1;		/* single byte character */
	}
	if (c < 0xC2) {
		return 0;		/* invalid mb character */
	}
	if (c < 0xE0) {
		if (start + 2 > end) {
			return 0;	/* too small */
		}
		if (!(((zend_uchar)start[1] ^ 0x80) < 0x40)) {
			return 0;
		}
		return 2;
	}
	if (c < 0xF0) {
		if (start + 3 > end) {
			return 0;	/* too small */
		}
		if (!(((zend_uchar)start[1] ^ 0x80) < 0x40 && ((zend_uchar)start[2] ^ 0x80) < 0x40 &&
			(c >= 0xE1 || (zend_uchar)start[1] >= 0xA0))) {
			return 0;	/* invalid utf8 character */
		}
		return 3;
	}
	if (c < 0xF5) {
		if (start + 4 > end) { /* We need 4 characters */
			return 0;	/* too small */
		}

		/*
		  UTF-8 quick four-byte mask:
		  11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
		  Encoding allows to encode U+00010000..U+001FFFFF

		  The maximum character defined in the Unicode standard is U+0010FFFF.
		  Higher characters U+00110000..U+001FFFFF are not used.

		  11110000.10010000.10xxxxxx.10xxxxxx == F0.90.80.80 == U+00010000 (min)
		  11110100.10001111.10111111.10111111 == F4.8F.BF.BF == U+0010FFFF (max)

		  Valid codes:
		  [F0][90..BF][80..BF][80..BF]
		  [F1][80..BF][80..BF][80..BF]
		  [F2][80..BF][80..BF][80..BF]
		  [F3][80..BF][80..BF][80..BF]
		  [F4][80..8F][80..BF][80..BF]
		*/

		if (!(((zend_uchar)start[1] ^ 0x80) < 0x40 &&
			((zend_uchar)start[2] ^ 0x80) < 0x40 &&
			((zend_uchar)start[3] ^ 0x80) < 0x40 &&
				(c >= 0xf1 || (zend_uchar)start[1] >= 0x90) &&
				(c <= 0xf3 || (zend_uchar)start[1] <= 0x8F)))
		{
			return 0;	/* invalid utf8 character */
		}
		return 4;
	}
	return 0;
}

__attribute__((used)) static unsigned int check_mb_utf8mb3_valid(const char * const start, const char * const end)
{
	unsigned int len = check_mb_utf8mb3_sequence(start, end);
	return (len > 1)? len:0;
}

__attribute__((used)) static unsigned int check_mb_utf8_valid(const char * const start, const char * const end)
{
	unsigned int len = check_mb_utf8_sequence(start, end);
	return (len > 1)? len:0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_utf8mb3(const unsigned int utf8)
{
	if (utf8 < 0x80) {
		return 1;		/* single byte character */
	}
	if (utf8 < 0xC2) {
		return 0;		/* invalid multibyte header */
	}
	if (utf8 < 0xE0) {
		return 2;		/* double byte character */
	}
	if (utf8 < 0xF0) {
		return 3;		/* triple byte character */
	}
	return 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_utf8(const unsigned int utf8)
{
	if (utf8 < 0x80) {
		return 1;		/* single byte character */
	}
	if (utf8 < 0xC2) {
		return 0;		/* invalid multibyte header */
	}
	if (utf8 < 0xE0) {
		return 2;		/* double byte character */
	}
	if (utf8 < 0xF0) {
		return 3;		/* triple byte character */
	}
	if (utf8 < 0xF8) {
		return 4;		/* four byte character */
	}
	return 0;
}

__attribute__((used)) static unsigned int check_mb_big5(const char * const start, const char * const end)
{
	return (valid_big5head(*(start)) && (end - start) > 1 && valid_big5tail(*(start + 1)) ? 2 : 0);
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_big5(const unsigned int big5)
{
	return (valid_big5head(big5)) ? 2 : 1;
}

__attribute__((used)) static unsigned int check_mb_cp932(const char * const start, const char * const end)
{
	return (valid_cp932head((zend_uchar)start[0]) && (end - start >  1) &&
			valid_cp932tail((zend_uchar)start[1])) ? 2 : 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_cp932(const unsigned int cp932)
{
	return (valid_cp932head((zend_uchar)cp932)) ? 2 : 1;
}

__attribute__((used)) static unsigned int check_mb_euckr(const char * const start, const char * const end)
{
	if (end - start <= 1) {
		return 0;	/* invalid length */
	}
	if (*(zend_uchar *)start < 0x80) {
		return 0;	/* invalid euckr character */
	}
	if (valid_euckr(start[1])) {
		return 2;
	}
	return 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_euckr(const unsigned int kr)
{
	return (valid_euckr(kr)) ? 2 : 1;
}

__attribute__((used)) static unsigned int check_mb_eucjpms(const char * const start, const char * const end)
{
	if (*((zend_uchar *)start) < 0x80) {
		return 0;	/* invalid eucjpms character */
	}
	if (valid_eucjpms(start[0]) && (end - start) > 1 && valid_eucjpms(start[1])) {
		return 2;
	}
	if (valid_eucjpms_ss2(start[0]) && (end - start) > 1 && valid_eucjpms_kata(start[1])) {
		return 2;
	}
	if (valid_eucjpms_ss3(start[0]) && (end - start) > 2 && valid_eucjpms(start[1]) &&
		valid_eucjpms(start[2])) {
		return 2;
	}
	return 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_eucjpms(const unsigned int jpms)
{
	if (valid_eucjpms(jpms) || valid_eucjpms_ss2(jpms)) {
		return 2;
	}
	if (valid_eucjpms_ss3(jpms)) {
		return 3;
	}
	return 1;
}

__attribute__((used)) static unsigned int check_mb_gb2312(const char * const start, const char * const end)
{
	return (valid_gb2312_head((unsigned int)start[0]) && end - start > 1 &&
			valid_gb2312_tail((unsigned int)start[1])) ? 2 : 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_gb2312(const unsigned int gb)
{
	return (valid_gb2312_head(gb)) ? 2 : 1;
}

__attribute__((used)) static unsigned int check_mb_gbk(const char * const start, const char * const end)
{
	return (valid_gbk_head(start[0]) && (end) - (start) > 1 && valid_gbk_tail(start[1])) ? 2 : 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_gbk(const unsigned int gbk)
{
	return (valid_gbk_head(gbk) ? 2 : 1);
}

__attribute__((used)) static unsigned int check_mb_sjis(const char * const start, const char * const end)
{
	return (valid_sjis_head((zend_uchar)start[0]) && (end - start) > 1 && valid_sjis_tail((zend_uchar)start[1])) ? 2 : 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_sjis(const unsigned int sjis)
{
	return (valid_sjis_head((zend_uchar)sjis)) ? 2 : 1;
}

__attribute__((used)) static unsigned int check_mb_ucs2(const char * const start __attribute((unused)), const char * const end __attribute((unused)))
{
	return 2; /* always 2 */
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_ucs2(const unsigned int ucs2 __attribute((unused)))
{
	return 2; /* always 2 */
}

__attribute__((used)) static unsigned int check_mb_ujis(const char * const start, const char * const end)
{
	if (*(zend_uchar*)start < 0x80) {
		return 0;	/* invalid ujis character */
	}
	if (valid_ujis(*(start)) && valid_ujis(*((start)+1))) {
		return 2;
	}
	if (valid_ujis_ss2(*(start)) && valid_ujis_kata(*((start)+1))) {
		return 2;
	}
	if (valid_ujis_ss3(*(start)) && (end-start) > 2 && valid_ujis(*((start)+1)) && valid_ujis(*((start)+2))) {
		return 3;
	}
	return 0;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_ujis(const unsigned int ujis)
{
	return (valid_ujis(ujis)? 2: valid_ujis_ss2(ujis)? 2: valid_ujis_ss3(ujis)? 3: 1);
}

__attribute__((used)) static unsigned int check_mb_utf16(const char * const start, const char * const end)
{
	if (start + 2 > end) {
		return 0;
	}

	if (UTF16_HIGH_HEAD(*start)) {
		return (start + 4 <= end) && UTF16_LOW_HEAD(start[2]) ? 4 : 0;
	}

	if (UTF16_LOW_HEAD(*start)) {
		return 0;
	}
	return 2;
}

__attribute__((used)) static uint32_t mysqlnd_mbcharlen_utf16(const unsigned int utf16)
{
  return UTF16_HIGH_HEAD(utf16) ? 4 : 2;
}

__attribute__((used)) static unsigned int check_mb_utf32(const char * const start __attribute((unused)), const char * const end __attribute((unused)))
{
	return 4;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_utf32(const unsigned int utf32 __attribute((unused)))
{
	return 4;
}

__attribute__((used)) static unsigned int mysqlnd_mbcharlen_gb18030(const unsigned int c)
{
	if (c <= 0xFF) {
		return !is_gb18030_odd(c);
	}
	if (c > 0xFFFF || !is_gb18030_odd((c >> 8) & 0xFF)) {
		return 0;
	}
	if (is_gb18030_even_2((c & 0xFF))) {
	    return 2;
	}
	if (is_gb18030_even_4((c & 0xFF))) {
		return 4;
	}

	return 0;
}

__attribute__((used)) static unsigned int my_ismbchar_gb18030(const char * start, const char * end)
{
	if (end - start <= 1 || !is_gb18030_odd(start[0])) {
		return 0;
	}

	if (is_gb18030_even_2(start[1])) {
		return 2;
	} else if (end - start > 3 && is_gb18030_even_4(start[1]) && is_gb18030_odd(start[2]) && is_gb18030_even_4(start[3])) {
		return 4;
	}

	return 0;
}

void
mysqlnd_charsets_plugin_register(void)
{
	mysqlnd_plugin_register_ex((struct st_mysqlnd_plugin_header *) &mysqlnd_plugin_charsets_plugin);
}

