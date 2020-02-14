#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  va_list ;
struct TYPE_5__ {void* buf; void* cookie; size_t (* read ) (TYPE_1__*,unsigned char*,size_t) ;int lock; } ;
typedef  TYPE_1__ FILE ;

/* Variables and functions */
 size_t __string_read (TYPE_1__*,unsigned char*,size_t) ; 
 int vfscanf (TYPE_1__*,char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static size_t do_read(FILE *f, unsigned char *buf, size_t len)
{
	return __string_read(f, buf, len);
}

int vsscanf(const char *restrict s, const char *restrict fmt, va_list ap)
{
	FILE f = {
		.buf = (void *)s, .cookie = (void *)s,
		.read = do_read, .lock = -1
	};
	return vfscanf(&f, fmt, ap);
}

