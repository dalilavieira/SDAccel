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
struct timeval {scalar_t__ tv_usec; int /*<<< orphan*/  tv_sec; } ;
struct timespec {int tv_nsec; int /*<<< orphan*/  tv_sec; } ;
typedef  int /*<<< orphan*/  const sigset_t ;
typedef  int /*<<< orphan*/  fd_set ;
typedef  scalar_t__ __darwin_suseconds_t ;

/* Variables and functions */
 int EINVAL ; 
 int ENOSYS ; 
 int FD_SETSIZE ; 
 int /*<<< orphan*/  SIG_SETMASK ; 
 int __pselect_nocancel (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct timespec const*,int /*<<< orphan*/  const*) ; 
 int __pthread_sigmask (int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int errno ; 
 int select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct timeval*) ; 

__attribute__((used)) static int
_pselect_emulated(int count, fd_set * __restrict rfds, fd_set * __restrict wfds,
		fd_set * __restrict efds, const struct timespec * __restrict timo,
		const sigset_t * __restrict mask)
{
	sigset_t omask;
	struct timeval tvtimo, *tvp;
	int rv, sverrno;

	if (timo) {
		tvtimo.tv_sec = timo->tv_sec;
		tvtimo.tv_usec = (__darwin_suseconds_t)(timo->tv_nsec / 1000);
		tvp = &tvtimo;
	} else {
		tvp = 0;
	}

	if (mask != 0) {
		rv = __pthread_sigmask(SIG_SETMASK, mask, &omask);
		if (rv != 0)
			return rv;
	}

	rv = select(count, rfds, wfds, efds, tvp);
	if (mask != 0) {
		sverrno = errno;
		__pthread_sigmask(SIG_SETMASK, &omask, (sigset_t *)0);
		errno = sverrno;
	}

	return rv;
}

int
pselect(int nfds, fd_set * __restrict readfds, fd_set * __restrict writefds,
	fd_set * __restrict exceptfds, const struct timespec * __restrict
#if defined(VARIANT_LEGACY) || defined(VARIANT_PRE1050)
	intimeout,
#else /* !VARIANT_LEGACY && !VARIANT_PRE1050 */
	timeout,
#endif /* VARIANT_LEGACY || VARIANT_PRE1050 */
	const sigset_t * __restrict sigmask)
{
	int ret;
#if defined(VARIANT_LEGACY) || defined(VARIANT_PRE1050)
	struct timespec tb;
	const struct timespec *timeout;

	/*
	 * Legacy select behavior is minimum 10 msec when tv_usec is non-zero
	 */
	if (intimeout && intimeout->tv_sec == 0 && intimeout->tv_nsec > 0 && intimeout->tv_nsec < 10000000L) {
		tb.tv_sec = 0;
		tb.tv_nsec = 10000000L;
		timeout = &tb;
	} else {
		timeout = intimeout;
	}
#elif defined(VARIANT_DARWIN_EXTSN)
#else
	/* 1050 variant */
	if (nfds > FD_SETSIZE) {
		errno = EINVAL;
		return -1;
	}
#endif

#if defined(VARIANT_CANCELABLE) || defined(VARIANT_PRE1050)
	ret = __pselect(nfds, readfds, writefds, exceptfds, timeout, sigmask);
#else /* !VARIANT_CANCELABLE && !VARIANT_PRE1050 */
	ret = __pselect_nocancel(nfds, readfds, writefds, exceptfds, timeout, sigmask);
#endif /* VARIANT_CANCELABLE || VARIANT_PRE1050 */

	if (ret == -1 && errno == ENOSYS) {
		ret = _pselect_emulated(nfds, readfds, writefds, exceptfds, timeout, sigmask);
	}

	return ret;
}

