#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int category; } ;
typedef  TYPE_1__ utf8proc_property_t ;
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ ssize_t ;
typedef  int /*<<< orphan*/  int32_t ;

/* Variables and functions */
 int SIZEOF_REV ; 
 int STRING_SIZE (char*) ; 
 int UTF8PROC_CATEGORY_LU ; 
 scalar_t__ iscntrl (char const) ; 
 int /*<<< orphan*/  isdigit (char const) ; 
 scalar_t__ isspace (char const) ; 
 int /*<<< orphan*/  isxdigit (char const) ; 
 int /*<<< orphan*/  memcpy (char*,char*,size_t) ; 
 char const* strchr (char const*,char) ; 
 int strcmp (char const*,char const*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,size_t) ; 
 size_t unicode_width (unsigned long,int) ; 
 unsigned char* utf8_bytes ; 
 TYPE_1__* utf8proc_get_property (int /*<<< orphan*/ ) ; 
 scalar_t__ utf8proc_iterate (int /*<<< orphan*/ *,scalar_t__,int /*<<< orphan*/ *) ; 

bool
string_isnumber(const char *str)
{
	int pos;

	for (pos = 0; str[pos]; pos++) {
		if (!isdigit(str[pos]))
			return false;
	}

	return pos > 0;
}

bool
iscommit(const char *str)
{
	int pos;

	for (pos = 0; str[pos]; pos++) {
		if (!isxdigit(str[pos]))
			return false;
	}

	return 7 <= pos && pos < SIZEOF_REV;
}

int
suffixcmp(const char *str, int slen, const char *suffix)
{
	size_t len = slen >= 0 ? slen : strlen(str);
	size_t suffixlen = strlen(suffix);

	return suffixlen < len ? strcmp(str + len - suffixlen, suffix) : -1;
}

void
string_ncopy_do(char *dst, size_t dstlen, const char *src, size_t srclen)
{
	if (srclen > dstlen - 1)
		srclen = dstlen - 1;

	strncpy(dst, src, srclen);
	dst[srclen] = 0;
}

void
string_copy_rev(char *dst, const char *src)
{
	size_t srclen;

	if (!*src)
		return;

	for (srclen = 0; srclen < SIZEOF_REV; srclen++)
		if (!src[srclen] || isspace(src[srclen]))
			break;

	string_ncopy_do(dst, SIZEOF_REV, src, srclen);
}

void
string_copy_rev_from_commit_line(char *dst, const char *src)
{
	string_copy_rev(dst, src + STRING_SIZE("commit "));
}

size_t
string_expanded_length(const char *src, size_t srclen, size_t tabsize, size_t max_size)
{
	size_t size, pos;

	for (size = pos = 0; pos < srclen && size < max_size; pos++) {
		if (src[pos] == '\t') {
			size_t expanded = tabsize - (size % tabsize);

			size += expanded;
		} else {
			size++;
		}
	}

	return pos;
}

size_t
string_expand(char *dst, size_t dstlen, const char *src, int srclen, int tabsize)
{
	size_t size, pos;

	for (size = pos = 0; size < dstlen - 1 && (srclen == -1 || pos < srclen) && src[pos]; pos++) {
		const char c = src[pos];

		if (c == '\t') {
			size_t expanded = tabsize - (size % tabsize);

			if (expanded + size >= dstlen - 1)
				expanded = dstlen - size - 1;
			memcpy(dst + size, "        ", expanded);
			size += expanded;
		} else if (isspace(c) || iscntrl(c)) {
			dst[size++] = ' ';
		} else {
			dst[size++] = src[pos];
		}
	}

	dst[size] = 0;
	return pos;
}

char *
string_trim_end(char *name)
{
	int namelen = strlen(name) - 1;

	while (namelen > 0 && isspace(name[namelen]))
		name[namelen--] = 0;

	return name;
}

char *
string_trim(char *name)
{
	while (isspace(*name))
		name++;

	return string_trim_end(name);
}

unsigned char
utf8_char_length(const char *string)
{
	int c = *(unsigned char *) string;

	return utf8_bytes[c];
}

unsigned long
utf8_to_unicode(const char *string, size_t length)
{
	unsigned long unicode;

	switch (length) {
	case 1:
		unicode  =   string[0];
		break;
	case 2:
		unicode  =  (string[0] & 0x1f) << 6;
		unicode +=  (string[1] & 0x3f);
		break;
	case 3:
		unicode  =  (string[0] & 0x0f) << 12;
		unicode += ((string[1] & 0x3f) << 6);
		unicode +=  (string[2] & 0x3f);
		break;
	case 4:
		unicode  =  (string[0] & 0x0f) << 18;
		unicode += ((string[1] & 0x3f) << 12);
		unicode += ((string[2] & 0x3f) << 6);
		unicode +=  (string[3] & 0x3f);
		break;
	case 5:
		unicode  =  (string[0] & 0x0f) << 24;
		unicode += ((string[1] & 0x3f) << 18);
		unicode += ((string[2] & 0x3f) << 12);
		unicode += ((string[3] & 0x3f) << 6);
		unicode +=  (string[4] & 0x3f);
		break;
	case 6:
		unicode  =  (string[0] & 0x01) << 30;
		unicode += ((string[1] & 0x3f) << 24);
		unicode += ((string[2] & 0x3f) << 18);
		unicode += ((string[3] & 0x3f) << 12);
		unicode += ((string[4] & 0x3f) << 6);
		unicode +=  (string[5] & 0x3f);
		break;
	default:
		return 0;
	}

	/* Invalid characters could return the special 0xfffd value but NUL
	 * should be just as good. */
	return unicode > 0x10FFFF ? 0 : unicode;
}

size_t
utf8_length(const char **start, int max_chars, size_t skip, int *width, size_t max_width, int *trimmed, bool reserve, int tab_size)
{
	const char *string = *start;
	const char *end = max_chars < 0 ? strchr(string, '\0') : string + max_chars;
	unsigned char last_bytes = 0;
	size_t last_ucwidth = 0;

	*width = 0;
	*trimmed = 0;

	while (string < end) {
		unsigned char bytes = utf8_char_length(string);
		size_t ucwidth;
		unsigned long unicode;

		if (string + bytes > end)
			break;

		/* Change representation to figure out whether
		 * it is a single- or double-width character. */

		unicode = utf8_to_unicode(string, bytes);
		/* FIXME: Graceful handling of invalid Unicode character. */
		if (!unicode)
			break;

		ucwidth = unicode_width(unicode, tab_size);
		if (skip > 0) {
			skip -= ucwidth <= skip ? ucwidth : skip;
			*start += bytes;
		}
		*width  += ucwidth;
		if (max_width > 0 && *width > max_width) {
			*trimmed = 1;
			*width -= ucwidth;
			if (reserve && *width == max_width) {
				string -= last_bytes;
				*width -= last_ucwidth;
			}
			break;
		}

		string  += bytes;
		if (ucwidth) {
			last_bytes = bytes;
			last_ucwidth = ucwidth;
		} else {
			last_bytes += bytes;
		}
	}

	return string - *start;
}

int
utf8_width_of(const char *text, int max_bytes, int max_width)
{
	int text_width = 0;
	const char *tmp = text;
	int trimmed = false;

	utf8_length(&tmp, max_bytes, 0, &text_width, max_width, &trimmed, false, 1);
	return text_width;
}

__attribute__((used)) static bool
utf8_string_contains(const char *text, int category)
{
	ssize_t textlen = strlen(text);

	while (textlen > 0) {
		int32_t unicode;
		ssize_t slen = utf8proc_iterate((uint8_t *) text, textlen, &unicode);
		const utf8proc_property_t *property;

		if (slen <= 0)
			break;

		property = utf8proc_get_property(unicode);
		if (property->category & category)
			return true;

		text += slen;
		textlen -= slen;
	}

	return false;
}

bool
utf8_string_contains_uppercase(const char *search)
{
	return utf8_string_contains(search, UTF8PROC_CATEGORY_LU);
}

