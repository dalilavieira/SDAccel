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
struct ff_circular_queue {void** slots; int abort; scalar_t__ size; scalar_t__ capacity; int write_index; int read_index; int /*<<< orphan*/  cond; int /*<<< orphan*/  mutex; int /*<<< orphan*/  item_size; } ;

/* Variables and functions */
 int /*<<< orphan*/  av_free (void**) ; 
 void* av_mallocz (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_signal (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void *queue_fetch_or_alloc(struct ff_circular_queue *cq,
		int index)
{
	if (cq->slots[index] == NULL)
		cq->slots[index] = av_mallocz(cq->item_size);

	return cq->slots[index];
}

__attribute__((used)) static void queue_lock(struct ff_circular_queue *cq)
{
	pthread_mutex_lock(&cq->mutex);
}

__attribute__((used)) static void queue_unlock(struct ff_circular_queue *cq)
{
	pthread_mutex_unlock(&cq->mutex);
}

__attribute__((used)) static void queue_signal(struct ff_circular_queue *cq)
{
	pthread_cond_signal(&cq->cond);
}

__attribute__((used)) static void queue_wait(struct ff_circular_queue *cq)
{
	pthread_cond_wait(&cq->cond, &cq->mutex);
}

void ff_circular_queue_abort(struct ff_circular_queue *cq)
{
	queue_lock(cq);
	cq->abort = true;
	queue_signal(cq);
	queue_unlock(cq);
}

void ff_circular_queue_free(struct ff_circular_queue *cq)
{
	ff_circular_queue_abort(cq);

	if (cq->slots != NULL)
		av_free(cq->slots);

	pthread_mutex_destroy(&cq->mutex);
	pthread_cond_destroy(&cq->cond);
}

void ff_circular_queue_wait_write(struct ff_circular_queue *cq)
{
	queue_lock(cq);

	while (cq->size >= cq->capacity && !cq->abort)
		queue_wait(cq);

	queue_unlock(cq);
}

void *ff_circular_queue_peek_write(struct ff_circular_queue *cq)
{
	return queue_fetch_or_alloc(cq, cq->write_index);
}

void ff_circular_queue_advance_write(struct ff_circular_queue *cq, void *item)
{
	cq->slots[cq->write_index] = item;
	cq->write_index = (cq->write_index + 1) % cq->capacity;

	queue_lock(cq);
	++cq->size;
	queue_unlock(cq);
}

void *ff_circular_queue_peek_read(struct ff_circular_queue *cq)
{
	return queue_fetch_or_alloc(cq, cq->read_index);
}

void ff_circular_queue_advance_read(struct ff_circular_queue *cq)
{
	cq->read_index = (cq->read_index + 1) % cq->capacity;
	queue_lock(cq);
	--cq->size;
	queue_signal(cq);
	queue_unlock(cq);
}

