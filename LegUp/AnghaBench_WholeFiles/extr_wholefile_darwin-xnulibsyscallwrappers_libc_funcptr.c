#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  voucher_mach_msg_state_t ;
typedef  int /*<<< orphan*/  mach_port_t ;
typedef  int /*<<< orphan*/  mach_msg_header_t ;
typedef  int /*<<< orphan*/  kern_return_t ;
typedef  int /*<<< orphan*/  boolean_t ;
typedef  TYPE_1__* _libkernel_voucher_functions_t ;
typedef  TYPE_2__* _libkernel_string_functions_t ;
struct TYPE_10__ {void* (* malloc ) (size_t) ;void (* free ) (void*) ;void* (* realloc ) (void*,size_t) ;void (* _pthread_exit_if_canceled ) (int) ;int version; void (* pthread_clear_qos_tsd ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_9__ {void (* bzero ) (void*,size_t) ;void* (* memchr ) (void const*,int,size_t) ;int (* memcmp ) (void const*,void const*,size_t) ;void* (* memmove ) (void*,void const*,size_t) ;void* (* memccpy ) (void*,void const*,int,size_t) ;void* (* memset ) (void*,int,size_t) ;char* (* strchr ) (char const*,int) ;int (* strcmp ) (char const*,char const*) ;char* (* strcpy ) (char*,char const*) ;size_t (* strlcat ) (char*,char const*,size_t) ;size_t (* strlcpy ) (char*,char const*,size_t) ;size_t (* strlen ) (char const*) ;int (* strncmp ) (char const*,char const*,size_t) ;char* (* strncpy ) (char*,char const*,size_t) ;size_t (* strnlen ) (char const*,size_t) ;char* (* strstr ) (char const*,char const*) ;} ;
struct TYPE_8__ {void (* voucher_mach_msg_clear ) (int /*<<< orphan*/ *) ;void (* voucher_mach_msg_revert ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* voucher_mach_msg_adopt ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* voucher_mach_msg_set ) (int /*<<< orphan*/ *) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  KERN_SUCCESS ; 
 int /*<<< orphan*/  VOUCHER_MACH_MSG_STATE_UNCHANGED ; 
 TYPE_5__* _libkernel_functions ; 
 TYPE_2__* _libkernel_string_functions ; 
 TYPE_1__* _libkernel_voucher_functions ; 
 void* stub1 (size_t) ; 
 void* stub10 (void*,void const*,size_t) ; 
 void* stub11 (void*,void const*,int,size_t) ; 
 void* stub12 (void*,int,size_t) ; 
 char* stub13 (char const*,int) ; 
 char* stub14 (char const*,int) ; 
 int stub15 (char const*,char const*) ; 
 char* stub16 (char*,char const*) ; 
 size_t stub17 (char*,char const*,size_t) ; 
 size_t stub18 (char*,char const*,size_t) ; 
 size_t stub19 (char const*) ; 
 void stub2 (void*) ; 
 int stub20 (char const*,char const*,size_t) ; 
 char* stub21 (char*,char const*,size_t) ; 
 size_t stub22 (char const*,size_t) ; 
 char* stub23 (char const*,char const*) ; 
 int /*<<< orphan*/  stub24 (int /*<<< orphan*/ *) ; 
 void stub25 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub26 (int /*<<< orphan*/ *) ; 
 void stub27 (int /*<<< orphan*/ ) ; 
 void* stub3 (void*,size_t) ; 
 void stub4 (int) ; 
 void stub5 (int /*<<< orphan*/ ) ; 
 void stub6 (void*,size_t) ; 
 void* stub7 (void const*,int,size_t) ; 
 int stub8 (void const*,void const*,size_t) ; 
 void* stub9 (void*,void const*,size_t) ; 

__attribute__((visibility("hidden")))
void *
malloc(size_t size)
{
	return _libkernel_functions->malloc(size);
}

__attribute__((visibility("hidden")))
void
free(void *ptr)
{
	return _libkernel_functions->free(ptr);
}

__attribute__((visibility("hidden")))
void *
realloc(void *ptr, size_t size)
{
	return _libkernel_functions->realloc(ptr, size);
}

__attribute__((visibility("hidden")))
void *
reallocf(void *ptr, size_t size)
{
	void *nptr = realloc(ptr, size);
	if (!nptr && ptr)
		free(ptr);
	return (nptr);
}

__attribute__((visibility("hidden")))
void
_pthread_exit_if_canceled(int error)
{
	return _libkernel_functions->_pthread_exit_if_canceled(error);
}

__attribute__((visibility("hidden")))
void
_pthread_set_self(void *ptr __attribute__((__unused__))) {}

__attribute__((visibility("hidden")))
void
_pthread_clear_qos_tsd(mach_port_t thread_port)
{
	if (_libkernel_functions->version >= 3 &&
			_libkernel_functions->pthread_clear_qos_tsd) {
		return _libkernel_functions->pthread_clear_qos_tsd(thread_port);
	}
}

kern_return_t
__libkernel_platform_init(_libkernel_string_functions_t fns)
{
	_libkernel_string_functions = fns;
	return KERN_SUCCESS;
}

__attribute__((visibility("hidden")))
void
bzero(void *s, size_t n)
{
	return _libkernel_string_functions->bzero(s, n);
}

__attribute__((visibility("hidden")))
void *
memchr(const void *s, int c, size_t n)
{
	return _libkernel_string_functions->memchr(s, c, n);
}

__attribute__((visibility("hidden")))
int
memcmp(const void *s1, const void *s2, size_t n)
{
	return _libkernel_string_functions->memcmp(s1, s2, n);
}

__attribute__((visibility("hidden")))
void *
memmove(void *dst, const void *src, size_t n)
{
	return _libkernel_string_functions->memmove(dst, src, n);
}

__attribute__((visibility("hidden")))
void *
memcpy(void *dst, const void *src, size_t n)
{
	return _libkernel_string_functions->memmove(dst, src, n);
}

__attribute__((visibility("hidden")))
void *
memccpy(void *__restrict dst, const void *__restrict src, int c, size_t n)
{
	return _libkernel_string_functions->memccpy(dst, src, c, n);
}

__attribute__((visibility("hidden")))
void *
memset(void *b, int c, size_t len)
{
	return _libkernel_string_functions->memset(b, c, len);
}

__attribute__((visibility("hidden")))
char *
strchr(const char *s, int c)
{
	return _libkernel_string_functions->strchr(s, c);
}

__attribute__((visibility("hidden")))
char *
index(const char *s, int c)
{
	return _libkernel_string_functions->strchr(s, c);
}

__attribute__((visibility("hidden")))
int
strcmp(const char *s1, const char *s2)
{
	return _libkernel_string_functions->strcmp(s1, s2);
}

__attribute__((visibility("hidden")))
char *
strcpy(char * restrict dst, const char * restrict src)
{
	return _libkernel_string_functions->strcpy(dst, src);
}

__attribute__((visibility("hidden")))
size_t
strlcat(char * restrict dst, const char * restrict src, size_t maxlen)
{
	return _libkernel_string_functions->strlcat(dst, src, maxlen);
}

__attribute__((visibility("hidden")))
size_t
strlcpy(char * restrict dst, const char * restrict src, size_t maxlen)
{
	return _libkernel_string_functions->strlcpy(dst, src, maxlen);
}

__attribute__((visibility("hidden")))
size_t
strlen(const char *str)
{
	return _libkernel_string_functions->strlen(str);
}

__attribute__((visibility("hidden")))
int
strncmp(const char *s1, const char *s2, size_t n)
{
	return _libkernel_string_functions->strncmp(s1, s2, n);
}

__attribute__((visibility("hidden")))
char *
strncpy(char * restrict dst, const char * restrict src, size_t maxlen)
{
	return _libkernel_string_functions->strncpy(dst, src, maxlen);
}

__attribute__((visibility("hidden")))
size_t
strnlen(const char *s, size_t maxlen)
{
	return _libkernel_string_functions->strnlen(s, maxlen);
}

__attribute__((visibility("hidden")))
char *
strstr(const char *s, const char *find)
{
	return _libkernel_string_functions->strstr(s, find);
}

kern_return_t
__libkernel_voucher_init(_libkernel_voucher_functions_t fns)
{
	_libkernel_voucher_functions = fns;
	return KERN_SUCCESS;
}

boolean_t
voucher_mach_msg_set(mach_msg_header_t *msg)
{
	if (_libkernel_voucher_functions->voucher_mach_msg_set) {
		return _libkernel_voucher_functions->voucher_mach_msg_set(msg);
	}
	return 0;
}

void
voucher_mach_msg_clear(mach_msg_header_t *msg)
{
	if (_libkernel_voucher_functions->voucher_mach_msg_clear) {
		return _libkernel_voucher_functions->voucher_mach_msg_clear(msg);
	}
}

voucher_mach_msg_state_t
voucher_mach_msg_adopt(mach_msg_header_t *msg)
{
	if (_libkernel_voucher_functions->voucher_mach_msg_adopt) {
		return _libkernel_voucher_functions->voucher_mach_msg_adopt(msg);
	}
	return VOUCHER_MACH_MSG_STATE_UNCHANGED;
}

void
voucher_mach_msg_revert(voucher_mach_msg_state_t state)
{
	if (_libkernel_voucher_functions->voucher_mach_msg_revert) {
		return _libkernel_voucher_functions->voucher_mach_msg_revert(state);
	}
}

