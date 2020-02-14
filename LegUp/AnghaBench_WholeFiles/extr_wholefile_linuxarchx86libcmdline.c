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
typedef  char u8 ;

/* Variables and functions */
 int COMMAND_LINE_SIZE ; 

__attribute__((used)) static inline int myisspace(u8 c)
{
	return c <= ' ';	/* Close enough approximation */
}

__attribute__((used)) static int
__cmdline_find_option_bool(const char *cmdline, int max_cmdline_size,
			   const char *option)
{
	char c;
	int pos = 0, wstart = 0;
	const char *opptr = NULL;
	enum {
		st_wordstart = 0,	/* Start of word/after whitespace */
		st_wordcmp,	/* Comparing this word */
		st_wordskip,	/* Miscompare, skip */
	} state = st_wordstart;

	if (!cmdline)
		return -1;      /* No command line */

	/*
	 * This 'pos' check ensures we do not overrun
	 * a non-NULL-terminated 'cmdline'
	 */
	while (pos < max_cmdline_size) {
		c = *(char *)cmdline++;
		pos++;

		switch (state) {
		case st_wordstart:
			if (!c)
				return 0;
			else if (myisspace(c))
				break;

			state = st_wordcmp;
			opptr = option;
			wstart = pos;
			/* fall through */

		case st_wordcmp:
			if (!*opptr) {
				/*
				 * We matched all the way to the end of the
				 * option we were looking for.  If the
				 * command-line has a space _or_ ends, then
				 * we matched!
				 */
				if (!c || myisspace(c))
					return wstart;
				/*
				 * We hit the end of the option, but _not_
				 * the end of a word on the cmdline.  Not
				 * a match.
				 */
			} else if (!c) {
				/*
				 * Hit the NULL terminator on the end of
				 * cmdline.
				 */
				return 0;
			} else if (c == *opptr++) {
				/*
				 * We are currently matching, so continue
				 * to the next character on the cmdline.
				 */
				break;
			}
			state = st_wordskip;
			/* fall through */

		case st_wordskip:
			if (!c)
				return 0;
			else if (myisspace(c))
				state = st_wordstart;
			break;
		}
	}

	return 0;	/* Buffer overrun */
}

__attribute__((used)) static int
__cmdline_find_option(const char *cmdline, int max_cmdline_size,
		      const char *option, char *buffer, int bufsize)
{
	char c;
	int pos = 0, len = -1;
	const char *opptr = NULL;
	char *bufptr = buffer;
	enum {
		st_wordstart = 0,	/* Start of word/after whitespace */
		st_wordcmp,	/* Comparing this word */
		st_wordskip,	/* Miscompare, skip */
		st_bufcpy,	/* Copying this to buffer */
	} state = st_wordstart;

	if (!cmdline)
		return -1;      /* No command line */

	/*
	 * This 'pos' check ensures we do not overrun
	 * a non-NULL-terminated 'cmdline'
	 */
	while (pos++ < max_cmdline_size) {
		c = *(char *)cmdline++;
		if (!c)
			break;

		switch (state) {
		case st_wordstart:
			if (myisspace(c))
				break;

			state = st_wordcmp;
			opptr = option;
			/* fall through */

		case st_wordcmp:
			if ((c == '=') && !*opptr) {
				/*
				 * We matched all the way to the end of the
				 * option we were looking for, prepare to
				 * copy the argument.
				 */
				len = 0;
				bufptr = buffer;
				state = st_bufcpy;
				break;
			} else if (c == *opptr++) {
				/*
				 * We are currently matching, so continue
				 * to the next character on the cmdline.
				 */
				break;
			}
			state = st_wordskip;
			/* fall through */

		case st_wordskip:
			if (myisspace(c))
				state = st_wordstart;
			break;

		case st_bufcpy:
			if (myisspace(c)) {
				state = st_wordstart;
			} else {
				/*
				 * Increment len, but don't overrun the
				 * supplied buffer and leave room for the
				 * NULL terminator.
				 */
				if (++len < bufsize)
					*bufptr++ = c;
			}
			break;
		}
	}

	if (bufsize)
		*bufptr = '\0';

	return len;
}

int cmdline_find_option_bool(const char *cmdline, const char *option)
{
	return __cmdline_find_option_bool(cmdline, COMMAND_LINE_SIZE, option);
}

int cmdline_find_option(const char *cmdline, const char *option, char *buffer,
			int bufsize)
{
	return __cmdline_find_option(cmdline, COMMAND_LINE_SIZE, option,
				     buffer, bufsize);
}

