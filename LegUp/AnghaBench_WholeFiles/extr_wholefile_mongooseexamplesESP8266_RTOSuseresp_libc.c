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
typedef  unsigned long long uint64_t ;
typedef  scalar_t__ uint32_t ;
struct timeval {unsigned long long tv_sec; unsigned long long tv_usec; } ;
struct _reent {int dummy; } ;
typedef  size_t _ssize_t ;

/* Variables and functions */
 int /*<<< orphan*/  os_putc (char) ; 
 scalar_t__ system_get_time () ; 

_ssize_t _write_r(struct _reent *r, int fd, void *buf, size_t len) {
  if (fd == 1 || fd == 2) {
    size_t i;
    for (i = 0; i < len; i++) {
      os_putc(((char *) buf)[i]);
    }
    return len;
  }
  return -1;
}

void abort(void) {
  /* cause an unaligned access exception, that will drop you into gdb */
  *(int *) 1 = 1;
  while (1)
    ; /* avoid gcc warning because stdlib abort() has noreturn attribute */
}

void _exit(int status) {
  abort();
}

int _gettimeofday_r(struct _reent *r, struct timeval *tp, void *tzp) {
  static uint32_t prev_time = 0;
  static uint32_t num_overflows = 0;
  uint32_t time = system_get_time();
  uint64_t time64 = time;
  if (prev_time > 0 && time < prev_time) num_overflows++;
  time64 += (((uint64_t) num_overflows) * (1ULL << 32));
  tp->tv_sec = time64 / 1000000ULL;
  tp->tv_usec = time64 % 1000000ULL;
  prev_time = time;
  return 0;
  (void) r;
  (void) tzp;
}

