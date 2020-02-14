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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int getc (int /*<<< orphan*/ *) ; 
 scalar_t__ isspace (int) ; 
 int /*<<< orphan*/  putchar (char) ; 

__attribute__((used)) static int getc_nospace(FILE *f) {
	int c;
	while (isspace (c = getc (f))) {
		;
	}
	return c;
}

__attribute__((used)) static void putc_wrap(char c, int wrap, int *len) {
	if (wrap && *len >= wrap) {
		putchar ('\n');
		*len = 0;
	}
	putchar(c);
	(*len)++;
}

__attribute__((used)) static void encode_tuple(unsigned long tuple, int count, int wrap, int *plen, int y_abbr) {
	int i, lim;
	char out[5];
	if (tuple == 0 && count == 4) {
		putc_wrap('z', wrap, plen);
	}
	else if (tuple == 0x20202020 && count == 4 && y_abbr) {
		putc_wrap('y', wrap, plen);
	}
	else {
		for (i = 0; i < 5; i++) {
			out[i] = tuple % 85 + '!';
			tuple /= 85;
		}
		lim = 4 - count;
		for (i = 4; i >= lim; i--) {
			putc_wrap(out[i], wrap, plen);
		}
	}
}

