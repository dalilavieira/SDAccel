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
#define  EOS 131 
 int FNM_CASEFOLD ; 
 int FNM_LEADING_DIR ; 
 int FNM_NOESCAPE ; 
 int FNM_NOMATCH ; 
 int FNM_NORES ; 
 int FNM_PATHNAME ; 
 int FNM_PERIOD ; 
#define  RANGE_ERROR 130 
#define  RANGE_MATCH 129 
#define  RANGE_NOMATCH 128 
 scalar_t__ git__tolower (unsigned char) ; 
static  int rangematch (char const*,char const,int,char**) ; 
 char* strchr (char const*,char) ; 

__attribute__((used)) static int
p_fnmatchx(const char *pattern, const char *string, int flags, size_t recurs)
{
		const char *stringstart;
		char *newp;
		char c, test;
		int recurs_flags = flags & ~FNM_PERIOD;

		if (recurs-- == 0)
				return FNM_NORES;

		for (stringstart = string;;)
				switch (c = *pattern++) {
				case EOS:
						if ((flags & FNM_LEADING_DIR) && *string == '/')
								return (0);
						return (*string == EOS ? 0 : FNM_NOMATCH);
				case '?':
						if (*string == EOS)
								return (FNM_NOMATCH);
						if (*string == '/' && (flags & FNM_PATHNAME))
								return (FNM_NOMATCH);
						if (*string == '.' && (flags & FNM_PERIOD) &&
							(string == stringstart ||
							((flags & FNM_PATHNAME) && *(string - 1) == '/')))
								return (FNM_NOMATCH);
						++string;
						break;
				case '*':
						c = *pattern;

						/* Let '**' override PATHNAME match for this segment.
						 * It will be restored if/when we recurse below.
						 */
						if (c == '*') {
							c = *++pattern;
							/* star-star-slash is at the end, match by default */
							if (c == EOS)
								return 0;
							/* Double-star must be at end or between slashes */
							if (c != '/')
								return (FNM_NOMATCH);

							c = *++pattern;
							do {
								int e = p_fnmatchx(pattern, string, recurs_flags, recurs);
								if (e != FNM_NOMATCH)
									return e;
								string = strchr(string, '/');
							} while (string++);

							/* If we get here, we didn't find a match */
							return FNM_NOMATCH;
						}

						if (*string == '.' && (flags & FNM_PERIOD) &&
							(string == stringstart ||
							((flags & FNM_PATHNAME) && *(string - 1) == '/')))
								return (FNM_NOMATCH);

						/* Optimize for pattern with * at end or before /. */
						if (c == EOS) {
								if (flags & FNM_PATHNAME)
										return ((flags & FNM_LEADING_DIR) ||
											strchr(string, '/') == NULL ?
											0 : FNM_NOMATCH);
								else
										return (0);
						} else if (c == '/' && (flags & FNM_PATHNAME)) {
								if ((string = strchr(string, '/')) == NULL)
										return (FNM_NOMATCH);
								break;
						}

						/* General case, use recursion. */
						while ((test = *string) != EOS) {
								int e;

								e = p_fnmatchx(pattern, string, recurs_flags, recurs);
								if (e != FNM_NOMATCH)
										return e;
								if (test == '/' && (flags & FNM_PATHNAME))
										break;
								++string;
						}
						return (FNM_NOMATCH);
				case '[':
						if (*string == EOS)
								return (FNM_NOMATCH);
						if (*string == '/' && (flags & FNM_PATHNAME))
								return (FNM_NOMATCH);
						if (*string == '.' && (flags & FNM_PERIOD) &&
							(string == stringstart ||
							((flags & FNM_PATHNAME) && *(string - 1) == '/')))
								return (FNM_NOMATCH);

						switch (rangematch(pattern, *string, flags, &newp)) {
						case RANGE_ERROR:
								/* not a good range, treat as normal text */
								goto normal;
						case RANGE_MATCH:
								pattern = newp;
								break;
						case RANGE_NOMATCH:
								return (FNM_NOMATCH);
						}
						++string;
						break;
				case '\\':
						if (!(flags & FNM_NOESCAPE)) {
								if ((c = *pattern++) == EOS) {
										c = '\\';
										--pattern;
								}
						}
						/* FALLTHROUGH */
				default:
				normal:
						if (c != *string && !((flags & FNM_CASEFOLD) &&
									(git__tolower((unsigned char)c) ==
									git__tolower((unsigned char)*string))))
								return (FNM_NOMATCH);
						++string;
						break;
				}
		/* NOTREACHED */
}

__attribute__((used)) static int
rangematch(const char *pattern, char test, int flags, char **newp)
{
		int negate, ok;
		char c, c2;

		/*
			* A bracket expression starting with an unquoted circumflex
			* character produces unspecified results (IEEE 1003.2-1992,
			* 3.13.2). This implementation treats it like '!', for
			* consistency with the regular expression syntax.
			* J.T. Conklin (conklin@ngai.kaleida.com)
			*/
		if ((negate = (*pattern == '!' || *pattern == '^')) != 0)
				++pattern;

		if (flags & FNM_CASEFOLD)
				test = (char)git__tolower((unsigned char)test);

		/*
			* A right bracket shall lose its special meaning and represent
			* itself in a bracket expression if it occurs first in the list.
			* -- POSIX.2 2.8.3.2
			*/
		ok = 0;
		c = *pattern++;
		do {
				if (c == '\\' && !(flags & FNM_NOESCAPE))
						c = *pattern++;
				if (c == EOS)
						return (RANGE_ERROR);
				if (c == '/' && (flags & FNM_PATHNAME))
						return (RANGE_NOMATCH);
				if ((flags & FNM_CASEFOLD))
						c = (char)git__tolower((unsigned char)c);
				if (*pattern == '-'
					&& (c2 = *(pattern+1)) != EOS && c2 != ']') {
						pattern += 2;
						if (c2 == '\\' && !(flags & FNM_NOESCAPE))
								c2 = *pattern++;
						if (c2 == EOS)
								return (RANGE_ERROR);
						if (flags & FNM_CASEFOLD)
								c2 = (char)git__tolower((unsigned char)c2);
						if (c <= test && test <= c2)
								ok = 1;
				} else if (c == test)
						ok = 1;
		} while ((c = *pattern++) != ']');

		*newp = (char *)pattern;
		return (ok == negate ? RANGE_NOMATCH : RANGE_MATCH);
}

int
p_fnmatch(const char *pattern, const char *string, int flags)
{
		return p_fnmatchx(pattern, string, flags, 64);
}

