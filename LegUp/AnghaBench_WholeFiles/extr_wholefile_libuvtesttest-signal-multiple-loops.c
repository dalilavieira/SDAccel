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
typedef  int /*<<< orphan*/  uv_signal_t ;
typedef  int /*<<< orphan*/  uv_loop_t ;
typedef  int /*<<< orphan*/  uv_handle_t ;
typedef  enum signal_action { ____Placeholder_signal_action } signal_action ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int ONLY_SIGUSR1 ; 
 int ONLY_SIGUSR2 ; 
 int SIGTERM ; 
 int SIGUSR1 ; 
 int SIGUSR1_AND_SIGUSR2 ; 
 int SIGUSR2 ; 
 int /*<<< orphan*/  UV_RUN_DEFAULT ; 
 int /*<<< orphan*/  counter_lock ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int loop_creation_counter ; 
 int /*<<< orphan*/ * malloc (int) ; 
 int /*<<< orphan*/  sem ; 
 int signal1_cb_counter ; 
 int signal2_cb_counter ; 
 int /*<<< orphan*/  stop ; 
 int /*<<< orphan*/  uv_close (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_is_closing (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_loop_close (int /*<<< orphan*/ *) ; 
 scalar_t__ uv_loop_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_unlock (int /*<<< orphan*/ *) ; 
 int uv_run (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uv_sem_post (int /*<<< orphan*/ *) ; 
 int uv_signal_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int uv_signal_start (int /*<<< orphan*/ *,void (*) (int /*<<< orphan*/ *,int),int) ; 
 int /*<<< orphan*/  uv_signal_stop (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void close_walk_cb(uv_handle_t* handle, void* arg) {
  if (!uv_is_closing(handle))
    uv_close(handle, NULL);
}

__attribute__((used)) static void increment_counter(volatile int* counter) {
  uv_mutex_lock(&counter_lock);
  ++(*counter);
  uv_mutex_unlock(&counter_lock);
}

__attribute__((used)) static void signal1_cb(uv_signal_t* handle, int signum) {
  ASSERT(signum == SIGUSR1);
  increment_counter(&signal1_cb_counter);
  uv_signal_stop(handle);
}

__attribute__((used)) static void signal2_cb(uv_signal_t* handle, int signum) {
  ASSERT(signum == SIGUSR2);
  increment_counter(&signal2_cb_counter);
  uv_signal_stop(handle);
}

__attribute__((used)) static void signal_handling_worker(void* context) {
  enum signal_action action;
  uv_signal_t signal1a;
  uv_signal_t signal1b;
  uv_signal_t signal2;
  uv_loop_t loop;
  int r;

  action = (enum signal_action) (uintptr_t) context;

  ASSERT(0 == uv_loop_init(&loop));

  /* Setup the signal watchers and start them. */
  if (action == ONLY_SIGUSR1 || action == SIGUSR1_AND_SIGUSR2) {
    r = uv_signal_init(&loop, &signal1a);
    ASSERT(r == 0);
    r = uv_signal_start(&signal1a, signal1_cb, SIGUSR1);
    ASSERT(r == 0);
    r = uv_signal_init(&loop, &signal1b);
    ASSERT(r == 0);
    r = uv_signal_start(&signal1b, signal1_cb, SIGUSR1);
    ASSERT(r == 0);
  }

  if (action == ONLY_SIGUSR2 || action == SIGUSR1_AND_SIGUSR2) {
    r = uv_signal_init(&loop, &signal2);
    ASSERT(r == 0);
    r = uv_signal_start(&signal2, signal2_cb, SIGUSR2);
    ASSERT(r == 0);
  }

  /* Signal watchers are now set up. */
  uv_sem_post(&sem);

  /* Wait for all signals. The signal callbacks stop the watcher, so uv_run
   * will return when all signal watchers caught a signal.
   */
  r = uv_run(&loop, UV_RUN_DEFAULT);
  ASSERT(r == 0);

  /* Restart the signal watchers. */
  if (action == ONLY_SIGUSR1 || action == SIGUSR1_AND_SIGUSR2) {
    r = uv_signal_start(&signal1a, signal1_cb, SIGUSR1);
    ASSERT(r == 0);
    r = uv_signal_start(&signal1b, signal1_cb, SIGUSR1);
    ASSERT(r == 0);
  }

  if (action == ONLY_SIGUSR2 || action == SIGUSR1_AND_SIGUSR2) {
    r = uv_signal_start(&signal2, signal2_cb, SIGUSR2);
    ASSERT(r == 0);
  }

  /* Wait for signals once more. */
  uv_sem_post(&sem);

  r = uv_run(&loop, UV_RUN_DEFAULT);
  ASSERT(r == 0);

  /* Close the watchers. */
  if (action == ONLY_SIGUSR1 || action == SIGUSR1_AND_SIGUSR2) {
    uv_close((uv_handle_t*) &signal1a, NULL);
    uv_close((uv_handle_t*) &signal1b, NULL);
  }

  if (action == ONLY_SIGUSR2 || action == SIGUSR1_AND_SIGUSR2) {
    uv_close((uv_handle_t*) &signal2, NULL);
  }

  /* Wait for the signal watchers to close. */
  r = uv_run(&loop, UV_RUN_DEFAULT);
  ASSERT(r == 0);

  uv_loop_close(&loop);
}

__attribute__((used)) static void signal_unexpected_cb(uv_signal_t* handle, int signum) {
  ASSERT(0 && "signal_unexpected_cb should never be called");
}

__attribute__((used)) static void loop_creating_worker(void* context) {
  (void) context;

  do {
    uv_loop_t *loop;
    uv_signal_t signal;
    int r;

    loop = malloc(sizeof(*loop));
    ASSERT(loop != NULL);
    ASSERT(0 == uv_loop_init(loop));

    r = uv_signal_init(loop, &signal);
    ASSERT(r == 0);

    r = uv_signal_start(&signal, signal_unexpected_cb, SIGTERM);
    ASSERT(r == 0);

    uv_close((uv_handle_t*) &signal, NULL);

    r = uv_run(loop, UV_RUN_DEFAULT);
    ASSERT(r == 0);

    uv_loop_close(loop);
    free(loop);

    increment_counter(&loop_creation_counter);
  } while (!stop);
}

