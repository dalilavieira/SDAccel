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
typedef  int uint64_t ;
typedef  int /*<<< orphan*/  ts ;
struct timespec {int tv_sec; int tv_nsec; } ;

/* Variables and functions */
 int /*<<< orphan*/  CLOCK_MONOTONIC ; 
 scalar_t__ EINTR ; 
 int clock_gettime (int /*<<< orphan*/ ,struct timespec*) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  memcpy (struct timespec*,struct timespec*,int) ; 
 int nanosleep (struct timespec*,struct timespec*) ; 
 void pixie_usleep (int const) ; 
 int /*<<< orphan*/  printf (char*,scalar_t__) ; 
 int /*<<< orphan*/  stderr ; 

void
pixie_mssleep(unsigned milliseconds)
{
    pixie_usleep(milliseconds * 1000ULL);
}

void
pixie_usleep(uint64_t microseconds)
{
    struct timespec ts;
    struct timespec remaining;
    int err;

    ts.tv_sec  =  microseconds/1000000;
    ts.tv_nsec = (microseconds%1000000) * 1000;

again:
    err = nanosleep(&ts, &remaining);
    if (err == -1 && errno == EINTR) {
        memcpy(&ts, &remaining, sizeof(ts));
        goto again;
    }

    //usleep(microseconds);
}

uint64_t
pixie_gettime(void)
{
    int x;
    struct timespec tv;

#if defined(CLOCK_UPTIME_RAW)
    /* macOS: ignores time when suspended/sleep */
    x = clock_gettime(CLOCK_UPTIME_RAW, &tv);
//#elif defined(CLOCK_MONOTONIC_RAW)
//    x = clock_gettime(CLOCK_MONOTONIC_RAW, &tv);
#else
    x = clock_gettime(CLOCK_MONOTONIC, &tv);
#endif
    if (x != 0) {
        printf("clock_gettime() err %d\n", errno);
    }

    return tv.tv_sec * 1000000 + tv.tv_nsec/1000;
}

uint64_t
pixie_nanotime(void)
{
    int x;
    struct timespec tv;

#ifdef CLOCK_MONOTONIC_RAW
    x = clock_gettime(CLOCK_MONOTONIC_RAW, &tv);
#else
    x = clock_gettime(CLOCK_MONOTONIC, &tv);
#endif
    if (x != 0) {
        printf("clock_gettime() err %d\n", errno);
    }

    return tv.tv_sec * 1000000000 + tv.tv_nsec;
}

int pixie_time_selftest(void)
{
    static const uint64_t duration = 456789;
    uint64_t start, stop, elapsed;


    start = pixie_gettime();
    pixie_usleep(duration);
    stop = pixie_gettime();
    elapsed = stop - start;

    if (elapsed < 0.9 * duration) {
        fprintf(stderr, "timing error, long delay\n");
        return 1;
    }
    if (1.2 * duration < elapsed) {
        fprintf(stderr, "timing error, long delay %5.0f%%\n", elapsed*100.0/duration);
        return 1;
    }

    return 0;
}

