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
struct ff_clock {double (* sync_clock ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  mutex; int /*<<< orphan*/  cond; int /*<<< orphan*/  retain; int /*<<< orphan*/  start_time; scalar_t__ started; int /*<<< orphan*/  opaque; } ;
typedef  int /*<<< orphan*/  int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  AV_NOPTS_VALUE ; 
 int /*<<< orphan*/  av_free (struct ff_clock*) ; 
 struct ff_clock* av_mallocz (int) ; 
 scalar_t__ ff_atomic_dec_long (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ff_atomic_inc_long (int /*<<< orphan*/ *) ; 
 void ff_clock_release (struct ff_clock**) ; 
 int /*<<< orphan*/  pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_cond_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_mutex_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 
 double stub1 (int /*<<< orphan*/ ) ; 

double ff_get_sync_clock(struct ff_clock *clock)
{
	return clock->sync_clock(clock->opaque);
}

int64_t ff_clock_start_time(struct ff_clock *clock)
{
	int64_t start_time = AV_NOPTS_VALUE;

	pthread_mutex_lock(&clock->mutex);
	if (clock->started)
		start_time = clock->start_time;
	pthread_mutex_unlock(&clock->mutex);

	return start_time;
}

struct ff_clock *ff_clock_init(void)
{
	struct ff_clock *clock = av_mallocz(sizeof(struct ff_clock));

	if (clock == NULL)
		return NULL;

	if (pthread_mutex_init(&clock->mutex, NULL) != 0)
		goto fail;

	if (pthread_cond_init(&clock->cond, NULL) != 0)
		goto fail1;

	return clock;

fail1:
	pthread_mutex_destroy(&clock->mutex);
fail:
	av_free(clock);

	return NULL;
}

struct ff_clock *ff_clock_retain(struct ff_clock *clock)
{
	ff_atomic_inc_long(&clock->retain);

	return clock;
}

struct ff_clock *ff_clock_move(struct ff_clock **clock)
{
	struct ff_clock *retained_clock = ff_clock_retain(*clock);
	ff_clock_release(clock);

	return retained_clock;
}

void ff_clock_release(struct ff_clock **clock)
{
	if (ff_atomic_dec_long(&(*clock)->retain) == 0) {
		pthread_cond_destroy(&(*clock)->cond);
		pthread_mutex_destroy(&(*clock)->mutex);
		av_free(*clock);
	}

	*clock = NULL;
}

