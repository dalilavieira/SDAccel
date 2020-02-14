#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ va_list ;
struct git_buf {int /*<<< orphan*/  ptr; } ;
struct TYPE_7__ {size_t length; void** contents; } ;
typedef  TYPE_1__ git_vector ;
struct TYPE_8__ {size_t size; scalar_t__* ptr; } ;
typedef  TYPE_2__ git_buf ;

/* Variables and functions */
 void* __coverity_alloc__ (size_t) ; 
 int /*<<< orphan*/  __coverity_panic__ () ; 
 int /*<<< orphan*/  __coverity_string_null_sink__ (char const*) ; 
 int /*<<< orphan*/  __coverity_string_size_sink__ (char const*) ; 
 int /*<<< orphan*/  __coverity_writeall__ (scalar_t__*) ; 
 int /*<<< orphan*/  memmove (scalar_t__*,void const*,size_t) ; 
 void** realloc (void**,size_t) ; 
 int strlen (int /*<<< orphan*/ ) ; 

int git_vector_insert(git_vector *v, void *element)
{
	if (!v)
		__coverity_panic__();

	v->contents = realloc(v->contents, ++v->length);
	if (!v->contents)
		__coverity_panic__();
	v->contents[v->length] = element;

	return 0;
}

int git_buf_len(const struct git_buf *buf)
{
	return strlen(buf->ptr);
}

int git_buf_vprintf(git_buf *buf, const char *format, va_list ap)
{
    char ch, *s;
    size_t len;

    __coverity_string_null_sink__(format);
    __coverity_string_size_sink__(format);

    ch = *format;
    ch = *(char *)ap;

    buf->ptr = __coverity_alloc__(len);
    __coverity_writeall__(buf->ptr);
    buf->size = len;

    return 0;
}

int git_buf_put(git_buf *buf, const char *data, size_t len)
{
    buf->ptr = __coverity_alloc__(buf->size + len + 1);
    memmove(buf->ptr + buf->size, data, len);
    buf->size += len;
    buf->ptr[buf->size + len] = 0;
    return 0;
}

int git_buf_set(git_buf *buf, const void *data, size_t len)
{
    buf->ptr = __coverity_alloc__(len + 1);
    memmove(buf->ptr, data, len);
    buf->size = len + 1;
    return 0;
}

void clar__fail(
	const char *file,
	int line,
	const char *error,
	const char *description,
	int should_abort)
{
	if (should_abort)
		__coverity_panic__();
}

void clar__assert(
	int condition,
	const char *file,
	int line,
	const char *error,
	const char *description,
	int should_abort)
{
	if (!condition && should_abort)
		__coverity_panic__();
}

