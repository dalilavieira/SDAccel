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
 int /*<<< orphan*/  TYPE_MEMR ; 
 int /*<<< orphan*/  TYPE_MEMW ; 
 int /*<<< orphan*/  TYPE_STRR ; 
 int /*<<< orphan*/  TYPE_STRW ; 
 int bcmp (void const*,void const*,size_t) ; 
 void bcopy (void const*,void*,size_t) ; 
 void bzero (void*,size_t) ; 
 int /*<<< orphan*/  kasan_check_range (char const*,size_t,int /*<<< orphan*/ ) ; 
 int memcmp (void const*,void const*,size_t) ; 
 void* memcpy (void*,void const*,size_t) ; 
 void* memmove (void*,void const*,size_t) ; 
 void* memset (void*,int,size_t) ; 
 size_t strlcat (char*,char const*,size_t) ; 
 size_t strlcpy (char*,char const*,size_t) ; 
 size_t strlen (char const*) ; 
 char* strncat (char*,char const*,size_t) ; 
 char* strncpy (char*,char const*,size_t) ; 
 size_t strnlen (char const*,size_t) ; 

__attribute__((used)) static inline void *__nosan_memcpy(void *dst, const void *src, size_t sz)   { return memcpy(dst, src, sz); }

__attribute__((used)) static inline void *__nosan_memset(void *src, int c, size_t sz)             { return memset(src, c, sz); }

__attribute__((used)) static inline void *__nosan_memmove(void *src, const void *dst, size_t sz)  { return memmove(src, dst, sz); }

__attribute__((used)) static inline int   __nosan_bcmp(const void *a, const void *b, size_t sz)   { return bcmp(a, b, sz); }

__attribute__((used)) static inline void  __nosan_bcopy(const void *src, void *dst, size_t sz)    { return bcopy(src, dst, sz); }

__attribute__((used)) static inline int   __nosan_memcmp(const void *a, const void *b, size_t sz) { return memcmp(a, b, sz); }

__attribute__((used)) static inline void  __nosan_bzero(void *dst, size_t sz)                     { return bzero(dst, sz); }

__attribute__((used)) static inline size_t __nosan_strlcpy(char *dst, const char *src, size_t sz) { return strlcpy(dst, src, sz); }

__attribute__((used)) static inline char  *__nosan_strncpy(char *dst, const char *src, size_t sz) { return strncpy(dst, src, sz); }

__attribute__((used)) static inline size_t __nosan_strlcat(char *dst, const char *src, size_t sz) { return strlcat(dst, src, sz); }

__attribute__((used)) static inline char  *__nosan_strncat(char *dst, const char *src, size_t sz) { return strncat(dst, src, sz); }

__attribute__((used)) static inline size_t __nosan_strnlen(const char *src, size_t sz)            { return strnlen(src, sz); }

__attribute__((used)) static inline size_t __nosan_strlen(const char *src)                        { return strlen(src); }

void
__asan_bcopy(const void *src, void *dst, size_t sz)
{
	kasan_check_range(src, sz, TYPE_MEMR);
	kasan_check_range(dst, sz, TYPE_MEMW);
	__nosan_bcopy(src, dst, sz);
}

void *
__asan_memmove(void *src, const void *dst, size_t sz)
{
	kasan_check_range(src, sz, TYPE_MEMR);
	kasan_check_range(dst, sz, TYPE_MEMW);
	return __nosan_memmove(src, dst, sz);
}

void *
__asan_memcpy(void *dst, const void *src, size_t sz)
{
	kasan_check_range(src, sz, TYPE_MEMR);
	kasan_check_range(dst, sz, TYPE_MEMW);
	return __nosan_memcpy(dst, src, sz);
}

void *
__asan_memset(void *dst, int c, size_t sz)
{
	kasan_check_range(dst, sz, TYPE_MEMW);
	return __nosan_memset(dst, c, sz);
}

void
__asan_bzero(void *dst, size_t sz)
{
	kasan_check_range(dst, sz, TYPE_MEMW);
	__nosan_bzero(dst, sz);
}

int
__asan_bcmp(const void *a, const void *b, size_t len)
{
	kasan_check_range(a, len, TYPE_MEMR);
	kasan_check_range(b, len, TYPE_MEMR);
	return __nosan_bcmp(a, b, len);
}

int
__asan_memcmp(const void *a, const void *b, size_t n)
{
	kasan_check_range(a, n, TYPE_MEMR);
	kasan_check_range(b, n, TYPE_MEMR);
	return __nosan_memcmp(a, b, n);
}

size_t
__asan_strlcpy(char *dst, const char *src, size_t sz)
{
	kasan_check_range(dst, sz, TYPE_STRW);
	return __nosan_strlcpy(dst, src, sz);
}

size_t
__asan_strlcat(char *dst, const char *src, size_t sz)
{
	kasan_check_range(dst, sz, TYPE_STRW);
	return __nosan_strlcat(dst, src, sz);
}

char *
__asan_strncpy(char *dst, const char *src, size_t sz)
{
	kasan_check_range(dst, sz, TYPE_STRW);
	return __nosan_strncpy(dst, src, sz);
}

char *
__asan_strncat(char *dst, const char *src, size_t sz)
{
	kasan_check_range(dst, strlen(dst) + sz + 1, TYPE_STRW);
	return __nosan_strncat(dst, src, sz);
}

size_t
__asan_strnlen(const char *src, size_t sz)
{
	kasan_check_range(src, sz, TYPE_STRR);
	return __nosan_strnlen(src, sz);
}

size_t
__asan_strlen(const char *src)
{
	size_t sz = __nosan_strlen(src);
	kasan_check_range(src, sz + 1, TYPE_STRR);
	return sz;
}

