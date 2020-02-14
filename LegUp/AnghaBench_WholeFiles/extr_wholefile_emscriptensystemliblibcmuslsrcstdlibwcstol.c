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
typedef  int wchar_t ;
typedef  unsigned long long uintmax_t ;
typedef  long long intmax_t ;
struct TYPE_6__ {int* cookie; size_t buf_size; int* buf; int* rpos; int* rend; int lock; size_t (* read ) (TYPE_1__*,unsigned char*,size_t) ;scalar_t__ flags; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 unsigned long long LLONG_MIN ; 
 unsigned long LONG_MIN ; 
 unsigned long long ULLONG_MAX ; 
 unsigned long long ULONG_MAX ; 
 unsigned long long __intscan (TYPE_1__*,int,int,unsigned long long) ; 
 scalar_t__ iswspace (int) ; 
 size_t shcnt (TYPE_1__*) ; 
 int /*<<< orphan*/  shlim (TYPE_1__*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static size_t do_read(FILE *f, unsigned char *buf, size_t len)
{
	size_t i;
	const wchar_t *wcs = f->cookie;

	if (!wcs[0]) wcs=L"@";
	for (i=0; i<f->buf_size && wcs[i]; i++)
		f->buf[i] = wcs[i] < 128 ? wcs[i] : '@';
	f->rpos = f->buf;
	f->rend = f->buf + i;
	f->cookie = (void *)(wcs+i);

	if (i && len) {
		*buf = *f->rpos++;
		return 1;
	}
	return 0;
}

__attribute__((used)) static unsigned long long wcstox(const wchar_t *s, wchar_t **p, int base, unsigned long long lim)
{
	wchar_t *t = (wchar_t *)s;
	unsigned char buf[64];
	FILE f = {0};
	f.flags = 0;
	f.rpos = f.rend = 0;
	f.buf = buf + 4;
	f.buf_size = sizeof buf - 4;
	f.lock = -1;
	f.read = do_read;
	while (iswspace(*t)) t++;
	f.cookie = (void *)t;
	shlim(&f, 0);
	unsigned long long y = __intscan(&f, base, 1, lim);
	if (p) {
		size_t cnt = shcnt(&f);
		*p = cnt ? t + cnt : (wchar_t *)s;
	}
	return y;
}

unsigned long long wcstoull(const wchar_t *restrict s, wchar_t **restrict p, int base)
{
	return wcstox(s, p, base, ULLONG_MAX);
}

long long wcstoll(const wchar_t *restrict s, wchar_t **restrict p, int base)
{
	return wcstox(s, p, base, LLONG_MIN);
}

unsigned long wcstoul(const wchar_t *restrict s, wchar_t **restrict p, int base)
{
	return wcstox(s, p, base, ULONG_MAX);
}

long wcstol(const wchar_t *restrict s, wchar_t **restrict p, int base)
{
	return wcstox(s, p, base, 0UL+LONG_MIN);
}

intmax_t wcstoimax(const wchar_t *restrict s, wchar_t **restrict p, int base)
{
	return wcstoll(s, p, base);
}

uintmax_t wcstoumax(const wchar_t *restrict s, wchar_t **restrict p, int base)
{
	return wcstoull(s, p, base);
}

