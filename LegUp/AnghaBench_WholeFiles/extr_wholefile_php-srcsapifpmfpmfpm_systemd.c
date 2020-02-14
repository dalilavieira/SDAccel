#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct fpm_worker_pool_s {TYPE_1__* scoreboard; struct fpm_worker_pool_s* next; } ;
struct fpm_event_s {int dummy; } ;
typedef  unsigned char atomic_uint_t ;
typedef  int /*<<< orphan*/  atomic_t ;
typedef  int /*<<< orphan*/  atomic_int_t ;
struct TYPE_6__ {int systemd_watchdog; float systemd_interval; } ;
struct TYPE_5__ {scalar_t__ parent_pid; } ;
struct TYPE_4__ {scalar_t__ slow_rq; scalar_t__ requests; scalar_t__ idle; scalar_t__ active; } ;

/* Variables and functions */
 int /*<<< orphan*/  FPM_EV_PERSIST ; 
 short FPM_EV_TIMEOUT ; 
 int FPM_SYSTEMD_DEFAULT_HEARTBEAT ; 
 int /*<<< orphan*/  ZLOG_DEBUG ; 
 int /*<<< orphan*/  ZLOG_NOTICE ; 
 int /*<<< orphan*/  ZLOG_WARNING ; 
 long atol (char*) ; 
 int /*<<< orphan*/  fpm_event_add (struct fpm_event_s*,float) ; 
 int /*<<< orphan*/  fpm_event_set_timer (struct fpm_event_s*,int /*<<< orphan*/ ,void (*) (struct fpm_event_s*,short,void*),int /*<<< orphan*/ *) ; 
 TYPE_3__ fpm_global_config ; 
 TYPE_2__ fpm_globals ; 
 struct fpm_worker_pool_s* fpm_worker_all_pools ; 
 char* getenv (char*) ; 
 scalar_t__ getpid () ; 
 int /*<<< orphan*/  sched_yield () ; 
 scalar_t__ sd_notifyf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  zlog (int /*<<< orphan*/ ,char*,...) ; 

__attribute__((used)) static inline atomic_int_t atomic_fetch_add(atomic_t *value, atomic_int_t add) /* {{{ */
{
	__asm__ volatile ( "lock;" "xaddq %0, %1;" :
		"+r" (add) : "m" (*value) : "memory");

	return add;
}

__attribute__((used)) static inline atomic_uint_t atomic_cmp_set(atomic_t *lock, atomic_uint_t old, atomic_uint_t set) /* {{{ */
{
	unsigned char res;

	__asm__ volatile ( "lock;" "cmpxchgq %3, %1;" "sete %0;" :
		"=a" (res) : "m" (*lock), "a" (old), "r" (set) : "memory");

	return res;
}

__attribute__((used)) static inline int fpm_spinlock(atomic_t *lock, int try_once) /* {{{ */
{
	if (try_once) {
		return atomic_cmp_set(lock, 0, 1) ? 1 : 0;
	}

	for (;;) {

		if (atomic_cmp_set(lock, 0, 1)) {
			break;
		}

		sched_yield();
	}

	return 1;
}

__attribute__((used)) static void fpm_systemd() /* {{{ */
{
	static unsigned long int last=0;
	struct fpm_worker_pool_s *wp;
	unsigned long int requests=0, slow_req=0;
	int active=0, idle=0;


	for (wp = fpm_worker_all_pools; wp; wp = wp->next) {
		if (wp->scoreboard) {
			active   += wp->scoreboard->active;
			idle     += wp->scoreboard->idle;
			requests += wp->scoreboard->requests;
			slow_req += wp->scoreboard->slow_rq;
		}
	}

/*
	zlog(ZLOG_DEBUG, "systemd %s (Processes active:%d, idle:%d, Requests:%lu, slow:%lu, Traffic:%.3greq/sec)",
			fpm_global_config.systemd_watchdog ? "watchdog" : "heartbeat",
			active, idle, requests, slow_req, ((float)requests - last) * 1000.0 / fpm_global_config.systemd_interval);
*/

	if (0 > sd_notifyf(0, "READY=1\n%s"
				"STATUS=Processes active: %d, idle: %d, Requests: %lu, slow: %lu, Traffic: %.3greq/sec",
				fpm_global_config.systemd_watchdog ? "WATCHDOG=1\n" : "",
				active, idle, requests, slow_req, ((float)requests - last) * 1000.0 / fpm_global_config.systemd_interval)) {
		zlog(ZLOG_NOTICE, "failed to notify status to systemd");
	}

	last = requests;
}

void fpm_systemd_heartbeat(struct fpm_event_s *ev, short which, void *arg) /* {{{ */
{
	static struct fpm_event_s heartbeat;

	if (fpm_globals.parent_pid != getpid()) {
		return; /* sanity check */
	}

	if (which == FPM_EV_TIMEOUT) {
		fpm_systemd();

		return;
	}

	if (0 > sd_notifyf(0, "READY=1\n"
			          "STATUS=Ready to handle connections\n"
			          "MAINPID=%lu",
			          (unsigned long) getpid())) {
		zlog(ZLOG_WARNING, "failed to notify start to systemd");
	} else {
		zlog(ZLOG_DEBUG, "have notify start to systemd");
	}

	/* first call without setting which to initialize the timer */
	if (fpm_global_config.systemd_interval > 0) {
		fpm_event_set_timer(&heartbeat, FPM_EV_PERSIST, &fpm_systemd_heartbeat, NULL);
		fpm_event_add(&heartbeat, fpm_global_config.systemd_interval);
		zlog(ZLOG_NOTICE, "systemd monitor interval set to %dms", fpm_global_config.systemd_interval);
	} else {
		zlog(ZLOG_NOTICE, "systemd monitor disabled");
	}
}

int fpm_systemd_conf() /* {{{ */
{
	char *watchdog;
	int  interval = 0;

	watchdog = getenv("WATCHDOG_USEC");
	if (watchdog) {
		/* usec to msec, and half the configured delay */
		interval = (int)(atol(watchdog) / 2000L);
		zlog(ZLOG_DEBUG, "WATCHDOG_USEC=%s, interval=%d", watchdog, interval);
	}

	if (interval > 1000) {
		if (fpm_global_config.systemd_interval > 0) {
			zlog(ZLOG_WARNING, "systemd_interval option ignored");
		}
		zlog(ZLOG_NOTICE, "systemd watchdog configured to %.3gsec", (float)interval / 1000.0);
		fpm_global_config.systemd_watchdog = 1;
		fpm_global_config.systemd_interval = interval;

	} else if (fpm_global_config.systemd_interval < 0) {
		/* not set => default value */
		fpm_global_config.systemd_interval = FPM_SYSTEMD_DEFAULT_HEARTBEAT;

	} else {
		/* sec to msec */
		fpm_global_config.systemd_interval *= 1000;
	}
	return 0;
}

