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
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int time_t ;

/* Variables and functions */
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/  MP_BE32TOH (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MP_HTOBE32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  errno ; 
 void* gc_alloc (size_t,int) ; 
 int /*<<< orphan*/  gc_free (void*) ; 
 void* gc_realloc (void*,size_t,int) ; 
 int mp_hal_ticks_ms () ; 

void *malloc(size_t size) {
    void *p = gc_alloc(size, false);
    if (p == NULL) {
        // POSIX requires ENOMEM to be set in case of error
        errno = ENOMEM;
    }
    return p;
}

void free(void *ptr) {
    gc_free(ptr);
}

void *calloc(size_t nmemb, size_t size) {
    return malloc(nmemb * size);
}

void *realloc(void *ptr, size_t size) {
    void *p = gc_realloc(ptr, size, true);
    if (p == NULL) {
        // POSIX requires ENOMEM to be set in case of error
        errno = ENOMEM;
    }
    return p;
}

uint32_t ntohl(uint32_t netlong) {
    return MP_BE32TOH(netlong);
}

uint32_t htonl(uint32_t netlong) {
    return MP_HTOBE32(netlong);
}

time_t time(time_t *t) {
    return mp_hal_ticks_ms() / 1000;
}

time_t mktime(void *tm) {
    return 0;
}

