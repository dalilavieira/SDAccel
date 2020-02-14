#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
struct snd_seq_timer_tick {int resolution; unsigned long fraction; unsigned int cur_tick; } ;
struct snd_seq_pool {int total_elements; int /*<<< orphan*/  counter; } ;
struct TYPE_15__ {int client; int port; } ;
struct TYPE_14__ {scalar_t__ port; void* client; } ;
struct TYPE_12__ {int client; int port; } ;
struct TYPE_13__ {TYPE_1__ addr; } ;
struct snd_seq_event {int type; TYPE_4__ dest; TYPE_3__ source; int /*<<< orphan*/  flags; TYPE_2__ data; } ;
typedef  scalar_t__ snd_seq_tick_time_t ;
struct TYPE_16__ {scalar_t__ tv_sec; scalar_t__ tv_nsec; } ;
typedef  TYPE_5__ snd_seq_real_time_t ;

/* Variables and functions */
 int ENODEV ; 
 int SNDRV_SEQ_ADDRESS_SUBSCRIBERS ; 
 int /*<<< orphan*/  SNDRV_SEQ_EVENT_LENGTH_FIXED ; 
 int /*<<< orphan*/  SNDRV_SEQ_EVENT_LENGTH_MASK ; 
 scalar_t__ announce_port ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct snd_seq_event*,int /*<<< orphan*/ ,int) ; 
 int snd_seq_control_queue (struct snd_seq_event*,int,int) ; 
 int snd_seq_kernel_client_dispatch (void*,struct snd_seq_event*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* sysclient ; 

__attribute__((used)) static inline void snd_seq_timer_update_tick(struct snd_seq_timer_tick *tick,
					     unsigned long resolution)
{
	if (tick->resolution > 0) {
		tick->fraction += resolution;
		tick->cur_tick += (unsigned int)(tick->fraction / tick->resolution);
		tick->fraction %= tick->resolution;
	}
}

__attribute__((used)) static inline int snd_seq_compare_tick_time(snd_seq_tick_time_t *a, snd_seq_tick_time_t *b)
{
	/* compare ticks */
	return (*a >= *b);
}

__attribute__((used)) static inline int snd_seq_compare_real_time(snd_seq_real_time_t *a, snd_seq_real_time_t *b)
{
	/* compare real time */
	if (a->tv_sec > b->tv_sec)
		return 1;
	if ((a->tv_sec == b->tv_sec) && (a->tv_nsec >= b->tv_nsec))
		return 1;
	return 0;
}

__attribute__((used)) static inline void snd_seq_sanity_real_time(snd_seq_real_time_t *tm)
{
	while (tm->tv_nsec >= 1000000000) {
		/* roll-over */
		tm->tv_nsec -= 1000000000;
                tm->tv_sec++;
        }
}

__attribute__((used)) static inline void snd_seq_inc_real_time(snd_seq_real_time_t *tm, snd_seq_real_time_t *inc)
{
	tm->tv_sec  += inc->tv_sec;
	tm->tv_nsec += inc->tv_nsec;
	snd_seq_sanity_real_time(tm);
}

__attribute__((used)) static inline void snd_seq_inc_time_nsec(snd_seq_real_time_t *tm, unsigned long nsec)
{
	tm->tv_nsec  += nsec;
	snd_seq_sanity_real_time(tm);
}

__attribute__((used)) static inline int snd_seq_unused_cells(struct snd_seq_pool *pool)
{
	return pool ? pool->total_elements - atomic_read(&pool->counter) : 0;
}

__attribute__((used)) static inline int snd_seq_total_cells(struct snd_seq_pool *pool)
{
	return pool ? pool->total_elements : 0;
}

__attribute__((used)) static int setheader(struct snd_seq_event * ev, int client, int port)
{
	if (announce_port < 0)
		return -ENODEV;

	memset(ev, 0, sizeof(struct snd_seq_event));

	ev->flags &= ~SNDRV_SEQ_EVENT_LENGTH_MASK;
	ev->flags |= SNDRV_SEQ_EVENT_LENGTH_FIXED;

	ev->source.client = sysclient;
	ev->source.port = announce_port;
	ev->dest.client = SNDRV_SEQ_ADDRESS_SUBSCRIBERS;

	/* fill data */
	/*ev->data.addr.queue = SNDRV_SEQ_ADDRESS_UNKNOWN;*/
	ev->data.addr.client = client;
	ev->data.addr.port = port;

	return 0;
}

void snd_seq_system_broadcast(int client, int port, int type)
{
	struct snd_seq_event ev;
	
	if (setheader(&ev, client, port) < 0)
		return;
	ev.type = type;
	snd_seq_kernel_client_dispatch(sysclient, &ev, 0, 0);
}

int snd_seq_system_notify(int client, int port, struct snd_seq_event *ev)
{
	ev->flags = SNDRV_SEQ_EVENT_LENGTH_FIXED;
	ev->source.client = sysclient;
	ev->source.port = announce_port;
	ev->dest.client = client;
	ev->dest.port = port;
	return snd_seq_kernel_client_dispatch(sysclient, ev, 0, 0);
}

__attribute__((used)) static int event_input_timer(struct snd_seq_event * ev, int direct, void *private_data, int atomic, int hop)
{
	return snd_seq_control_queue(ev, atomic, hop);
}

