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

/* Variables and functions */
 int /*<<< orphan*/  pdc_iodc_print (char const*,int) ; 

void *memmove(void *dest, const void *src, size_t n)
{
	const char *s = src;
	char *d = dest;

	if (d <= s) {
		while (n--)
			*d++ = *s++;
	} else {
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return dest;
}

void *memset(void *s, int c, size_t count)
{
	char *xs = (char *)s;

	while (count--)
		*xs++ = c;
	return s;
}

void *memcpy(void *d, const void *s, size_t len)
{
	char *dest = (char *)d;
	const char *source = (const char *)s;

	while (len--)
		*dest++ = *source++;
	return d;
}

size_t strlen(const char *s)
{
	const char *sc;

	for (sc = s; *sc != '\0'; ++sc)
		;
	return sc - s;
}

char *strchr(const char *s, int c)
{
	while (*s) {
		if (*s == (char)c)
			return (char *)s;
		++s;
	}
	return NULL;
}

int puts(const char *s)
{
	const char *nuline = s;

	while ((nuline = strchr(s, '\n')) != NULL) {
		if (nuline != s)
			pdc_iodc_print(s, nuline - s);
		pdc_iodc_print("\r\n", 2);
		s = nuline + 1;
	}
	if (*s != '\0')
		pdc_iodc_print(s, strlen(s));

	return 0;
}

__attribute__((used)) static int putchar(int c)
{
	char buf[2];

	buf[0] = c;
	buf[1] = '\0';
	puts(buf);
	return c;
}

