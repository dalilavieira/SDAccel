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
typedef  int uint8_t ;

/* Variables and functions */
 char* compat_strdup (char const*) ; 
 int* cp1252_utf8 ; 
 int /*<<< orphan*/  free (int*) ; 
 int* malloc (size_t) ; 
 char* realloc (int*,size_t) ; 
 int strlen (char const*) ; 
 size_t* tblofs ; 

__attribute__((used)) static int
is_utf8(const char* src)
{
	uint8_t ch;
	size_t i;
	const uint8_t* s = (const uint8_t*) src;

	/* We make a loop over every character, until we find a null one.
	   Remember: The string is supposed to end with a NUL, so ahead checks are safe. */
	while ((ch = *s++))	{
		/* Ye olde 7bit ASCII chars 'rr fine for anything */
		if(ch < 0x80) continue;

		/* Now, we watch out for non-UTF conform sequences. */
		else if ((ch < 0xC2) || (ch > 0xFD))
			return 0;
		/* check for some misformed sequences */
		if (((ch == 0xC2) && (s[0] < 0xA0)) ||
		    ((ch == 0xEF) && (s[0] == 0xBF) && (s[1] > 0xBD)))
			/* XXX add more for outside the BMP */
			return 0;

		/* Check the continuation bytes. */
		if      (ch < 0xE0) i = 1;
		else if (ch < 0xF0) i = 2;
		else if (ch < 0xF8)	i = 3;
		else if (ch < 0xFC)	i = 4;
		else
			i = 5;

		while (i--)
			if ((*s++ & 0xC0) != 0x80)
				return 0;
	}

	/* If no check failed, the string indeed looks like valid UTF-8. */
	return 1;
}

char *
icy2utf8(const char *src, int force)
{
	const uint8_t *s = (const uint8_t *)src;
	size_t srclen, dstlen, i, k;
	uint8_t ch, *d;
	char *dst;

	/* Some funny streams from Apple/iTunes give ICY info in UTF-8 already.
	   So, be prepared and don't try to re-encode such. Unless forced. */
	if(!force && is_utf8(src)) return (compat_strdup(src));

	srclen = strlen(src) + 1;
	/* allocate conservatively */
	if ((d = malloc(srclen * 3)) == NULL)
		return (NULL);

	i = 0;
	dstlen = 0;
	while (i < srclen) {
		ch = s[i++];
		k = tblofs[ch];
		while (k < tblofs[ch + 1])
			d[dstlen++] = cp1252_utf8[k++];
	}

	/* dstlen includes trailing NUL since srclen also does */
	if ((dst = realloc(d, dstlen)) == NULL) {
		free(d);
		return (NULL);
	}
	return (dst);
}

