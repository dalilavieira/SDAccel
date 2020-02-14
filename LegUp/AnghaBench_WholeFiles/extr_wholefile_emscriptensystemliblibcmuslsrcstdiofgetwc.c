#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  wint_t ;
typedef  int /*<<< orphan*/  wchar_t ;
struct TYPE_12__ {int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ mbstate_t ;
typedef  int /*<<< orphan*/  locale_t ;
struct TYPE_13__ {scalar_t__ rpos; scalar_t__ rend; scalar_t__ mode; int /*<<< orphan*/  locale; } ;
typedef  TYPE_2__ FILE ;

/* Variables and functions */
 int /*<<< orphan*/  CURRENT_LOCALE ; 
 int /*<<< orphan*/  EILSEQ ; 
 int /*<<< orphan*/  FLOCK (TYPE_2__*) ; 
 int /*<<< orphan*/  FUNLOCK (TYPE_2__*) ; 
 int /*<<< orphan*/  WEOF ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  fwide (TYPE_2__*,int) ; 
 int getc_unlocked (TYPE_2__*) ; 
 size_t mbrtowc (int /*<<< orphan*/ *,void*,int,TYPE_1__*) ; 
 int /*<<< orphan*/  mbsinit (TYPE_1__*) ; 

__attribute__((used)) static wint_t __fgetwc_unlocked_internal(FILE *f)
{
	mbstate_t st = { 0 };
	wchar_t wc;
	int c;
	unsigned char b;
	size_t l;

	/* Convert character from buffer if possible */
	if (f->rpos < f->rend) {
		l = mbrtowc(&wc, (void *)f->rpos, f->rend - f->rpos, &st);
		if (l+2 >= 2) {
			f->rpos += l + !l; /* l==0 means 1 byte, null */
			return wc;
		}
		if (l == -1) {
			f->rpos++;
			return WEOF;
		}
	} else l = -2;

	/* Convert character byte-by-byte */
	while (l == -2) {
		b = c = getc_unlocked(f);
		if (c < 0) {
			if (!mbsinit(&st)) errno = EILSEQ;
			return WEOF;
		}
		l = mbrtowc(&wc, (void *)&b, 1, &st);
		if (l == -1) return WEOF;
	}

	return wc;
}

wint_t __fgetwc_unlocked(FILE *f)
{
	locale_t *ploc = &CURRENT_LOCALE, loc = *ploc;
	if (f->mode <= 0) fwide(f, 1);
	*ploc = f->locale;
	wchar_t wc = __fgetwc_unlocked_internal(f);
	*ploc = loc;
	return wc;
}

wint_t fgetwc(FILE *f)
{
	wint_t c;
	FLOCK(f);
	c = __fgetwc_unlocked(f);
	FUNLOCK(f);
	return c;
}

