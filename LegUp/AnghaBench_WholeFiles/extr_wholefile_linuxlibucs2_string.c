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
typedef  scalar_t__ ucs2_char_t ;
typedef  char u8 ;
typedef  int u16 ;

/* Variables and functions */

unsigned long
ucs2_strnlen(const ucs2_char_t *s, size_t maxlength)
{
        unsigned long length = 0;

        while (*s++ != 0 && length < maxlength)
                length++;
        return length;
}

unsigned long
ucs2_strlen(const ucs2_char_t *s)
{
        return ucs2_strnlen(s, ~0UL);
}

unsigned long
ucs2_strsize(const ucs2_char_t *data, unsigned long maxlength)
{
        return ucs2_strnlen(data, maxlength/sizeof(ucs2_char_t)) * sizeof(ucs2_char_t);
}

int
ucs2_strncmp(const ucs2_char_t *a, const ucs2_char_t *b, size_t len)
{
        while (1) {
                if (len == 0)
                        return 0;
                if (*a < *b)
                        return -1;
                if (*a > *b)
                        return 1;
                if (*a == 0) /* implies *b == 0 */
                        return 0;
                a++;
                b++;
                len--;
        }
}

unsigned long
ucs2_utf8size(const ucs2_char_t *src)
{
	unsigned long i;
	unsigned long j = 0;

	for (i = 0; src[i]; i++) {
		u16 c = src[i];

		if (c >= 0x800)
			j += 3;
		else if (c >= 0x80)
			j += 2;
		else
			j += 1;
	}

	return j;
}

unsigned long
ucs2_as_utf8(u8 *dest, const ucs2_char_t *src, unsigned long maxlength)
{
	unsigned int i;
	unsigned long j = 0;
	unsigned long limit = ucs2_strnlen(src, maxlength);

	for (i = 0; maxlength && i < limit; i++) {
		u16 c = src[i];

		if (c >= 0x800) {
			if (maxlength < 3)
				break;
			maxlength -= 3;
			dest[j++] = 0xe0 | (c & 0xf000) >> 12;
			dest[j++] = 0x80 | (c & 0x0fc0) >> 6;
			dest[j++] = 0x80 | (c & 0x003f);
		} else if (c >= 0x80) {
			if (maxlength < 2)
				break;
			maxlength -= 2;
			dest[j++] = 0xc0 | (c & 0x7c0) >> 6;
			dest[j++] = 0x80 | (c & 0x03f);
		} else {
			maxlength -= 1;
			dest[j++] = c & 0x7f;
		}
	}
	if (maxlength)
		dest[j] = '\0';
	return j;
}

