#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct fpm_worker_pool_s {int idle_spawn_rate; int log_fd; int /*<<< orphan*/  scoreboard; int /*<<< orphan*/  children; struct fpm_worker_pool_s* config; struct fpm_worker_pool_s* next; struct fpm_worker_pool_s* home; struct fpm_worker_pool_s* user; } ;
typedef  unsigned char atomic_uint_t ;
typedef  int /*<<< orphan*/  atomic_t ;
typedef  int /*<<< orphan*/  atomic_int_t ;
struct TYPE_2__ {scalar_t__ parent_pid; } ;

/* Variables and functions */
 int /*<<< orphan*/  FPM_CLEANUP_ALL ; 
 int FPM_CLEANUP_CHILD ; 
 int /*<<< orphan*/  fpm_children_free (int /*<<< orphan*/ ) ; 
 scalar_t__ fpm_cleanup_add (int /*<<< orphan*/ ,void (*) (int,void*),int /*<<< orphan*/ ) ; 
 TYPE_1__ fpm_globals ; 
 int /*<<< orphan*/  fpm_scoreboard_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fpm_unix_free_socket_premissions (struct fpm_worker_pool_s*) ; 
 struct fpm_worker_pool_s* fpm_worker_all_pools ; 
 int /*<<< orphan*/  fpm_worker_pool_config_free (struct fpm_worker_pool_s*) ; 
 int /*<<< orphan*/  free (struct fpm_worker_pool_s*) ; 
 scalar_t__ getpid () ; 
 struct fpm_worker_pool_s* malloc (int) ; 
 int /*<<< orphan*/  memset (struct fpm_worker_pool_s*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sched_yield () ; 

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

void fpm_worker_pool_free(struct fpm_worker_pool_s *wp) /* {{{ */
{
	if (wp->config) {
		free(wp->config);
	}
	if (wp->user) {
		free(wp->user);
	}
	if (wp->home) {
		free(wp->home);
	}
	fpm_unix_free_socket_premissions(wp);
	free(wp);
}

__attribute__((used)) static void fpm_worker_pool_cleanup(int which, void *arg) /* {{{ */
{
	struct fpm_worker_pool_s *wp, *wp_next;

	for (wp = fpm_worker_all_pools; wp; wp = wp_next) {
		wp_next = wp->next;
		fpm_worker_pool_config_free(wp->config);
		fpm_children_free(wp->children);
		if ((which & FPM_CLEANUP_CHILD) == 0 && fpm_globals.parent_pid == getpid()) {
			fpm_scoreboard_free(wp->scoreboard);
		}
		fpm_worker_pool_free(wp);
	}
	fpm_worker_all_pools = NULL;
}

struct fpm_worker_pool_s *fpm_worker_pool_alloc() /* {{{ */
{
	struct fpm_worker_pool_s *ret;

	ret = malloc(sizeof(struct fpm_worker_pool_s));
	if (!ret) {
		return 0;
	}

	memset(ret, 0, sizeof(struct fpm_worker_pool_s));

	ret->idle_spawn_rate = 1;
	ret->log_fd = -1;
	return ret;
}

int fpm_worker_pool_init_main() /* {{{ */
{
	if (0 > fpm_cleanup_add(FPM_CLEANUP_ALL, fpm_worker_pool_cleanup, 0)) {
		return -1;
	}
	return 0;
}

