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
typedef  scalar_t__ wchar_t ;
typedef  scalar_t__ utf8proc_ssize_t ;

/* Variables and functions */
 int UTF8PROC_CATEGORY_CO ; 
 int utf8proc_category (scalar_t__) ; 
 int utf8proc_charwidth (scalar_t__) ; 
 int /*<<< orphan*/  utf8proc_codepoint_valid (scalar_t__) ; 
 int utf8proc_encode_char (scalar_t__,char*) ; 
 scalar_t__ utf8proc_iterate (char const*,size_t,scalar_t__*) ; 

int
utf8proc_wcwidth(wchar_t wc)
{
	int	cat;

	cat = utf8proc_category(wc);
	if (cat == UTF8PROC_CATEGORY_CO) {
		/*
		 * The private use category is where powerline and similar
		 * codepoints are stored, they have "ambiguous" width - use 1.
		 */
		return (1);
	}
	return (utf8proc_charwidth(wc));
}

int
utf8proc_mbtowc(wchar_t *pwc, const char *s, size_t n)
{
	utf8proc_ssize_t	slen;

	if (s == NULL)
		return (0);

	/*
	 * *pwc == -1 indicates invalid codepoint
	 * slen < 0 indicates an error
	 */
	slen = utf8proc_iterate(s, n, pwc);
	if (*pwc == (wchar_t)-1 || slen < 0)
		return (-1);
	return (slen);
}

int
utf8proc_wctomb(char *s, wchar_t wc)
{
	if (s == NULL)
		return (0);

	if (!utf8proc_codepoint_valid(wc))
		return (-1);
	return (utf8proc_encode_char(wc, s));
}

