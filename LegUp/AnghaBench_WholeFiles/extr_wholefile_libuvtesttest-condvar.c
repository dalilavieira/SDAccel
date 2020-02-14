#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int use_broadcast; int /*<<< orphan*/  sem_signaled; int /*<<< orphan*/  mutex; int /*<<< orphan*/  cond; int /*<<< orphan*/  sem_waiting; int /*<<< orphan*/  posted_2; int /*<<< orphan*/  (* wait_cond ) (TYPE_1__*,int /*<<< orphan*/ *) ;int /*<<< orphan*/  posted_1; int /*<<< orphan*/  (* signal_cond ) (TYPE_1__*,int /*<<< orphan*/ *) ;} ;
typedef  TYPE_1__ worker_config ;
typedef  int /*<<< orphan*/  (* wait_func ) (TYPE_1__*,int /*<<< orphan*/ *) ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  int /*<<< orphan*/  uint64_t ;
typedef  int /*<<< orphan*/  (* signal_func ) (TYPE_1__*,int /*<<< orphan*/ *) ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_cond_broadcast (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_cond_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_cond_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_cond_signal (int /*<<< orphan*/ *) ; 
 int uv_cond_timedwait (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_sem_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_sem_init (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_sem_post (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_sem_wait (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

void worker_config_init(worker_config* wc,
                        int use_broadcast,
                        signal_func signal_f,
                        wait_func wait_f) {
  /* Wipe. */
  memset(wc, 0, sizeof(*wc));

  /* Copy vars. */
  wc->signal_cond = signal_f;
  wc->wait_cond = wait_f;
  wc->use_broadcast = use_broadcast;

  /* Init. */
  ASSERT(0 == uv_sem_init(&wc->sem_waiting, 0));
  ASSERT(0 == uv_sem_init(&wc->sem_signaled, 0));
  ASSERT(0 == uv_cond_init(&wc->cond));
  ASSERT(0 == uv_mutex_init(&wc->mutex));
}

void worker_config_destroy(worker_config* wc) {
  uv_mutex_destroy(&wc->mutex);
  uv_cond_destroy(&wc->cond);
  uv_sem_destroy(&wc->sem_signaled);
  uv_sem_destroy(&wc->sem_waiting);
}

__attribute__((used)) static void worker(void* arg) {
  worker_config* c = arg;
  c->signal_cond(c, &c->posted_1);
  c->wait_cond(c, &c->posted_2);
}

__attribute__((used)) static void condvar_signal(worker_config* c, int* flag) {
  /* Wait until waiter holds mutex and is preparing to wait. */
  uv_sem_wait(&c->sem_waiting);

  /* Make sure waiter has begun waiting. */
  uv_mutex_lock(&c->mutex);

  /* Help waiter differentiate between spurious and legitimate wakeup. */
  ASSERT(*flag == 0);
  *flag = 1;

  if (c->use_broadcast)
    uv_cond_broadcast(&c->cond);
  else
    uv_cond_signal(&c->cond);

  uv_mutex_unlock(&c->mutex);

  /* Done signaling. */
  uv_sem_post(&c->sem_signaled);
}

__attribute__((used)) static int condvar_wait(worker_config* c, const int* flag) {
  uv_mutex_lock(&c->mutex);

  /* Tell signal'er that I am waiting. */
  uv_sem_post(&c->sem_waiting);

  /* Wait until I get a non-spurious signal. */
  do {
    uv_cond_wait(&c->cond, &c->mutex);
  } while (*flag == 0);
  ASSERT(*flag == 1);

  uv_mutex_unlock(&c->mutex);

  /* Wait for my signal'er to finish. */
  uv_sem_wait(&c->sem_signaled);

  return 0;
}

__attribute__((used)) static int condvar_timedwait(worker_config* c, const int* flag) {
  int r;

  r = 0;

  uv_mutex_lock(&c->mutex);

  /* Tell signal'er that I am waiting. */
  uv_sem_post(&c->sem_waiting);

  /* Wait until I get a non-spurious signal. */
  do {
    r = uv_cond_timedwait(&c->cond, &c->mutex, (uint64_t)(1 * 1e9)); /* 1 s */
    ASSERT(r == 0); /* Should not time out. */
  } while (*flag == 0);
  ASSERT(*flag == 1);

  uv_mutex_unlock(&c->mutex);

  /* Wait for my signal'er to finish. */
  uv_sem_wait(&c->sem_signaled);
  return r;
}

