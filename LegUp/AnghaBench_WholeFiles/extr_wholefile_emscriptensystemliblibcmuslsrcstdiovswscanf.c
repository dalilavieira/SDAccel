#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  void wchar_t ;
typedef  int /*<<< orphan*/  va_list ;
struct TYPE_4__ {void* cookie; unsigned char* buf; int buf_size; unsigned char* rpos; unsigned char* rend; size_t (* read ) (TYPE_1__*,unsigned char*,size_t) ;int lock; } ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 int vfwscanf (TYPE_1__*,void const*,int /*<<< orphan*/ ) ; 
 size_t wcsrtombs (void*,void const**,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static size_t wstring_read(FILE *f, unsigned char *buf, size_t len)
{
	const wchar_t *src = f->cookie;
	size_t k;

	if (!src) return 0;

	k = wcsrtombs((void *)f->buf, &src, f->buf_size, 0);
	if (k==(size_t)-1) {
		f->rpos = f->rend = 0;
		return 0;
	}

	f->rpos = f->buf;
	f->rend = f->buf + k;
	f->cookie = (void *)src;

	if (!len || !k) return 0;

	*buf = *f->rpos++;
	return 1;
}

int vswscanf(const wchar_t *restrict s, const wchar_t *restrict fmt, va_list ap)
{
	unsigned char buf[256];
	FILE f = {
		.buf = buf, .buf_size = sizeof buf,
		.cookie = (void *)s,
		.read = wstring_read, .lock = -1
	};
	return vfwscanf(&f, fmt, ap);
}

