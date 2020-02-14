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
struct link_map {int dummy; } ;
typedef  int /*<<< orphan*/  Dl_info ;

/* Variables and functions */
 int RTLD_DI_LINKMAP ; 
 char* errbuf ; 
 int errflag ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int) ; 

__attribute__((used)) static int invalid_dso_handle(void *h)
{
	snprintf(errbuf, sizeof errbuf, "Invalid library handle %p", (void *)h);
	errflag = 1;
	return 1;
}

void *dlopen(const char *file, int mode)
{
	return 0;
}

void *__dlsym(void *restrict p, const char *restrict s, void *restrict ra)
{
	return 0;
}

int __dladdr (const void *addr, Dl_info *info)
{
	return 0;
}

int __dlinfo(void *dso, int req, void *res)
{
	if (invalid_dso_handle(dso)) return -1;
	if (req != RTLD_DI_LINKMAP) {
		snprintf(errbuf, sizeof errbuf, "Unsupported request %d", req);
		errflag = 1;
		return -1;
	}
	*(struct link_map **)res = dso;
	return 0;
}

char *dlerror()
{
	if (!errflag) return 0;
	errflag = 0;
	return errbuf;
}

int dlclose(void *p)
{
	return invalid_dso_handle(p);
}

