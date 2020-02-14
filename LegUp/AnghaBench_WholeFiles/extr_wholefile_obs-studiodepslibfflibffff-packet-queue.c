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
struct TYPE_2__ {scalar_t__ size; } ;
struct ff_packet {int /*<<< orphan*/ * clock; TYPE_1__ base; } ;
struct ff_packet_queue {int abort; int /*<<< orphan*/  mutex; scalar_t__ total_size; scalar_t__ count; struct ff_packet_list* first_packet; struct ff_packet_list* last_packet; int /*<<< orphan*/  cond; struct ff_packet flush_packet; } ;
struct ff_packet_list {struct ff_packet packet; struct ff_packet_list* next; } ;

/* Variables and functions */
 int FF_PACKET_EMPTY ; 
 int FF_PACKET_FAIL ; 
 int FF_PACKET_SUCCESS ; 
 int /*<<< orphan*/  av_free (struct ff_packet_list*) ; 
 int /*<<< orphan*/  av_free_packet (TYPE_1__*) ; 
 int /*<<< orphan*/  av_freep (struct ff_packet_list**) ; 
 struct ff_packet_list* av_malloc (int) ; 
 int /*<<< orphan*/  ff_clock_release (int /*<<< orphan*/ **) ; 
 void packet_queue_flush (struct ff_packet_queue*) ; 
 int /*<<< orphan*/  pthread_cond_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_signal (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_cond_wait (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_mutex_unlock (int /*<<< orphan*/ *) ; 

void packet_queue_abort(struct ff_packet_queue *q)
{
	pthread_mutex_lock(&q->mutex);
	q->abort = true;
	pthread_cond_signal(&q->cond);
	pthread_mutex_unlock(&q->mutex);
}

void packet_queue_free(struct ff_packet_queue *q)
{
	packet_queue_flush(q);

	pthread_mutex_destroy(&q->mutex);
	pthread_cond_destroy(&q->cond);

	av_free_packet(&q->flush_packet.base);
}

int packet_queue_put(struct ff_packet_queue *q, struct ff_packet *packet)
{
	struct ff_packet_list *new_packet;

	new_packet = av_malloc(sizeof(struct ff_packet_list));

	if (new_packet == NULL)
		return FF_PACKET_FAIL;

	new_packet->packet = *packet;
	new_packet->next = NULL;

	pthread_mutex_lock(&q->mutex);

	if (q->last_packet == NULL)
		q->first_packet = new_packet;
	else
		q->last_packet->next = new_packet;

	q->last_packet = new_packet;

	q->count++;
	q->total_size += new_packet->packet.base.size;

	pthread_cond_signal(&q->cond);
	pthread_mutex_unlock(&q->mutex);

	return FF_PACKET_SUCCESS;
}

int packet_queue_put_flush_packet(struct ff_packet_queue *q)
{
	return packet_queue_put(q, &q->flush_packet);
}

int packet_queue_get(struct ff_packet_queue *q, struct ff_packet *packet,
		bool block)
{
	struct ff_packet_list *potential_packet;
	int return_status;

	pthread_mutex_lock(&q->mutex);

	while (true) {
		potential_packet = q->first_packet;

		if (potential_packet != NULL) {
			q->first_packet = potential_packet->next;

			if (q->first_packet == NULL)
				q->last_packet = NULL;

			q->count--;
			q->total_size -= potential_packet->packet.base.size;
			*packet = potential_packet->packet;
			av_free(potential_packet);
			return_status = FF_PACKET_SUCCESS;
			break;

		} else if (!block) {
			return_status = FF_PACKET_EMPTY;
			break;

		} else {
			pthread_cond_wait(&q->cond, &q->mutex);
			if (q->abort) {
				return_status = FF_PACKET_FAIL;
				break;
			}
		}
	}

	pthread_mutex_unlock(&q->mutex);

	return return_status;
}

void packet_queue_flush(struct ff_packet_queue *q)
{
	struct ff_packet_list *packet;

	pthread_mutex_lock(&q->mutex);

	for (packet = q->first_packet; packet != NULL;
			packet = q->first_packet) {
		q->first_packet = packet->next;
		av_free_packet(&packet->packet.base);
		if (packet->packet.clock != NULL)
			ff_clock_release(&packet->packet.clock);
		av_freep(&packet);
	}

	q->last_packet = q->first_packet = NULL;
	q->count = 0;
	q->total_size = 0;

	pthread_mutex_unlock(&q->mutex);
}

