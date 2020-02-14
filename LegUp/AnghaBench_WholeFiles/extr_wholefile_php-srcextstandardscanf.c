#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zval ;
struct Range {char start; char end; } ;
struct TYPE_6__ {int exclude; char* chars; int nchars; int nranges; struct Range* ranges; } ;
typedef  TYPE_1__ CharSet ;

/* Variables and functions */
 int /*<<< orphan*/  SCAN_ERROR_EOF ; 
 int /*<<< orphan*/  ZVAL_LONG (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  convert_to_null (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  efree (char*) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ safe_emalloc (int,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static char * BuildCharSet(CharSet *cset, char *format)
{
	char *ch, start;
	int  nranges;
	char *end;

	memset(cset, 0, sizeof(CharSet));

	ch = format;
	if (*ch == '^') {
		cset->exclude = 1;
		ch = ++format;
	}
	end = format + 1;	/* verify this - cc */

	/*
	 * Find the close bracket so we can overallocate the set.
	 */
	if (*ch == ']') {
		ch = end++;
	}
	nranges = 0;
	while (*ch != ']') {
		if (*ch == '-') {
			nranges++;
		}
		ch = end++;
	}

	cset->chars = (char *) safe_emalloc(sizeof(char), (end - format - 1), 0);
	if (nranges > 0) {
		cset->ranges = (struct Range *) safe_emalloc(sizeof(struct Range), nranges, 0);
	} else {
		cset->ranges = NULL;
	}

	/*
	 * Now build the character set.
	 */
	cset->nchars = cset->nranges = 0;
	ch    = format++;
	start = *ch;
	if (*ch == ']' || *ch == '-') {
		cset->chars[cset->nchars++] = *ch;
		ch = format++;
	}
	while (*ch != ']') {
		if (*format == '-') {
			/*
			 * This may be the first character of a range, so don't add
			 * it yet.
			 */
			start = *ch;
		} else if (*ch == '-') {
			/*
			 * Check to see if this is the last character in the set, in which
			 * case it is not a range and we should add the previous character
			 * as well as the dash.
			 */
			if (*format == ']') {
				cset->chars[cset->nchars++] = start;
				cset->chars[cset->nchars++] = *ch;
			} else {
				ch = format++;

				/*
				 * Check to see if the range is in reverse order.
				 */
				if (start < *ch) {
					cset->ranges[cset->nranges].start = start;
					cset->ranges[cset->nranges].end = *ch;
				} else {
					cset->ranges[cset->nranges].start = *ch;
					cset->ranges[cset->nranges].end = start;
				}
				cset->nranges++;
			}
		} else {
			cset->chars[cset->nchars++] = *ch;
		}
		ch = format++;
	}
	return format;
}

__attribute__((used)) static int CharInSet(CharSet *cset, int c)
{
	char ch = (char) c;
	int i, match = 0;

	for (i = 0; i < cset->nchars; i++) {
		if (cset->chars[i] == ch) {
			match = 1;
			break;
		}
	}
	if (!match) {
		for (i = 0; i < cset->nranges; i++) {
			if ((cset->ranges[i].start <= ch)
				&& (ch <= cset->ranges[i].end)) {
				match = 1;
				break;
			}
		}
	}
	return (cset->exclude ? !match : match);
}

__attribute__((used)) static void ReleaseCharSet(CharSet *cset)
{
	efree((char *)cset->chars);
	if (cset->ranges) {
		efree((char *)cset->ranges);
	}
}

__attribute__((used)) static inline void scan_set_error_return(int numVars, zval *return_value) /* {{{ */
{
	if (numVars) {
		ZVAL_LONG(return_value, SCAN_ERROR_EOF);  /* EOF marker */
	} else {
		/* convert_to_null calls destructor */
		convert_to_null(return_value);
	}
}

