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
typedef  int /*<<< orphan*/  time_t ;
struct tm {int dummy; } ;
typedef  int errno_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int EINVAL ; 
 int ERANGE ; 
 int errno ; 
 int /*<<< orphan*/ * fopen (char const*,char const*) ; 
 struct tm* gmtime (int /*<<< orphan*/  const*) ; 
 struct tm* localtime (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  memcpy (struct tm*,struct tm*,int) ; 
 int /*<<< orphan*/  memset (struct tm*,int /*<<< orphan*/ ,int) ; 
 char const* strerror (int) ; 
 scalar_t__ tolower (char) ; 

errno_t fopen_s(FILE **pFile, const char *filename, const char *mode)
{
    if (pFile == NULL || filename == NULL || mode == NULL)
        return EINVAL;
    *pFile = fopen(filename, mode);
    if (*pFile != NULL)
        return 0;
    else
        return errno;
}

int
memcasecmp(const void *lhs, const void *rhs, int length)
{
    int i;
    for (i=0; i<length; i++) {
        if (tolower(((char*)lhs)[i]) != tolower(((char*)rhs)[i]))
            return -1;
    }
    return 0;
}

errno_t strcpy_s(char *dst, size_t sizeof_dst, const char *src)
{
    size_t i;

    if (sizeof_dst == 0)
        return ERANGE;

    if (dst == NULL)
        return EINVAL;

    if (src == NULL) {
        dst[0] = 0;
        return EINVAL;
    }

    for (i=0; src[i]; i++) {
        if (i >= sizeof_dst) {
            dst[0] = 0;
            return ERANGE;
        } else
            dst[i] = src[i];
    }
    if (i >= sizeof_dst) {
        dst[0] = 0;
        return ERANGE;
    } else
        dst[i] = src[i];

    return 0;
}

errno_t localtime_s(struct tm* _tm, const time_t *time)
{
    struct tm *x;

    x = localtime(time);
    if (x == NULL) {
        memset(_tm, 0, sizeof(*_tm));
        return -1;
    }
    memcpy(_tm, x, sizeof(*_tm));

    return 0;
}

errno_t gmtime_s(struct tm* _tm, const time_t *time)
{
    struct tm *x;

    x = gmtime(time);
    if (x == NULL) {
        memset(_tm, 0, sizeof(*_tm));
        return -1;
    }
    memcpy(_tm, x, sizeof(*_tm));

    return 0;
}

const char *strerror_x(int x)
{
#ifdef _MSC_VER
#pragma warning(disable: 4996)
#endif
#undef strerror
    return strerror(x);
}

