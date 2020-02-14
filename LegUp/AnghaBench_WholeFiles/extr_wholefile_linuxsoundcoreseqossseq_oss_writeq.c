#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {scalar_t__ time; int /*<<< orphan*/  code; } ;
union evrec {TYPE_4__ t; } ;
struct TYPE_6__ {scalar_t__ tick; } ;
struct TYPE_5__ {int client; int port; } ;
struct TYPE_7__ {int client; int port; } ;
struct snd_seq_remove_events {int output_pool; int output_room; int output_free; int /*<<< orphan*/  client; int /*<<< orphan*/  data; TYPE_2__ time; int /*<<< orphan*/  type; scalar_t__ flags; int /*<<< orphan*/  remove_mode; TYPE_1__ dest; TYPE_3__ source; int /*<<< orphan*/  queue; } ;
struct snd_seq_pool {int total_elements; int /*<<< orphan*/  counter; } ;
struct snd_seq_event {int output_pool; int output_room; int output_free; int /*<<< orphan*/  client; int /*<<< orphan*/  data; TYPE_2__ time; int /*<<< orphan*/  type; scalar_t__ flags; int /*<<< orphan*/  remove_mode; TYPE_1__ dest; TYPE_3__ source; int /*<<< orphan*/  queue; } ;
struct snd_seq_client_pool {int output_pool; int output_room; int output_free; int /*<<< orphan*/  client; int /*<<< orphan*/  data; TYPE_2__ time; int /*<<< orphan*/  type; scalar_t__ flags; int /*<<< orphan*/  remove_mode; TYPE_1__ dest; TYPE_3__ source; int /*<<< orphan*/  queue; } ;
struct seq_oss_writeq {int maxlen; int sync_event_put; scalar_t__ sync_time; struct seq_oss_devinfo* dp; int /*<<< orphan*/  sync_lock; int /*<<< orphan*/  sync_sleep; } ;
struct seq_oss_timer {scalar_t__ cur_tick; int realtime; } ;
struct seq_oss_devinfo {int /*<<< orphan*/  cseq; TYPE_3__ addr; struct seq_oss_timer* timer; int /*<<< orphan*/  queue; } ;
typedef  int /*<<< orphan*/  reset ;
typedef  int /*<<< orphan*/  pool ;
typedef  int /*<<< orphan*/  ev ;
typedef  scalar_t__ abstime_t ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HZ ; 
 int /*<<< orphan*/  SEQ_SYNCTIMER ; 
 int /*<<< orphan*/  SNDRV_SEQ_EVENT_ECHO ; 
 unsigned int SNDRV_SEQ_IOCTL_GET_CLIENT_POOL ; 
 unsigned int SNDRV_SEQ_IOCTL_REMOVE_EVENTS ; 
 unsigned int SNDRV_SEQ_IOCTL_SET_CLIENT_POOL ; 
 int /*<<< orphan*/  SNDRV_SEQ_REMOVE_OUTPUT ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  current ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct seq_oss_writeq*) ; 
 struct seq_oss_writeq* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct snd_seq_remove_events*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ signal_pending (int /*<<< orphan*/ ) ; 
 int snd_seq_kernel_client_ctl (int /*<<< orphan*/ ,unsigned int,void*) ; 
 int snd_seq_kernel_client_dispatch (int /*<<< orphan*/ ,struct snd_seq_remove_events*,int,int) ; 
 int /*<<< orphan*/  snd_seq_kernel_client_enqueue_blocking (int /*<<< orphan*/ ,struct snd_seq_remove_events*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void snd_seq_oss_writeq_clear (struct seq_oss_writeq*) ; 
 void snd_seq_oss_writeq_wakeup (struct seq_oss_writeq*,scalar_t__) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  wait_event_interruptible_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wake_up (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline int
snd_seq_oss_dispatch(struct seq_oss_devinfo *dp, struct snd_seq_event *ev, int atomic, int hop)
{
	return snd_seq_kernel_client_dispatch(dp->cseq, ev, atomic, hop);
}

__attribute__((used)) static inline int
snd_seq_oss_control(struct seq_oss_devinfo *dp, unsigned int type, void *arg)
{
	return snd_seq_kernel_client_ctl(dp->cseq, type, arg);
}

__attribute__((used)) static inline void
snd_seq_oss_fill_addr(struct seq_oss_devinfo *dp, struct snd_seq_event *ev,
		     int dest_client, int dest_port)
{
	ev->queue = dp->queue;
	ev->source = dp->addr;
	ev->dest.client = dest_client;
	ev->dest.port = dest_port;
}

__attribute__((used)) static inline abstime_t
snd_seq_oss_timer_cur_tick(struct seq_oss_timer *timer)
{
	return timer->cur_tick;
}

__attribute__((used)) static inline int
snd_seq_oss_timer_is_realtime(struct seq_oss_timer *timer)
{
	return timer->realtime;
}

__attribute__((used)) static inline int snd_seq_unused_cells(struct snd_seq_pool *pool)
{
	return pool ? pool->total_elements - atomic_read(&pool->counter) : 0;
}

__attribute__((used)) static inline int snd_seq_total_cells(struct snd_seq_pool *pool)
{
	return pool ? pool->total_elements : 0;
}

struct seq_oss_writeq *
snd_seq_oss_writeq_new(struct seq_oss_devinfo *dp, int maxlen)
{
	struct seq_oss_writeq *q;
	struct snd_seq_client_pool pool;

	if ((q = kzalloc(sizeof(*q), GFP_KERNEL)) == NULL)
		return NULL;
	q->dp = dp;
	q->maxlen = maxlen;
	spin_lock_init(&q->sync_lock);
	q->sync_event_put = 0;
	q->sync_time = 0;
	init_waitqueue_head(&q->sync_sleep);

	memset(&pool, 0, sizeof(pool));
	pool.client = dp->cseq;
	pool.output_pool = maxlen;
	pool.output_room = maxlen / 2;

	snd_seq_oss_control(dp, SNDRV_SEQ_IOCTL_SET_CLIENT_POOL, &pool);

	return q;
}

void
snd_seq_oss_writeq_delete(struct seq_oss_writeq *q)
{
	if (q) {
		snd_seq_oss_writeq_clear(q);	/* to be sure */
		kfree(q);
	}
}

void
snd_seq_oss_writeq_clear(struct seq_oss_writeq *q)
{
	struct snd_seq_remove_events reset;

	memset(&reset, 0, sizeof(reset));
	reset.remove_mode = SNDRV_SEQ_REMOVE_OUTPUT; /* remove all */
	snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_REMOVE_EVENTS, &reset);

	/* wake up sleepers if any */
	snd_seq_oss_writeq_wakeup(q, 0);
}

int
snd_seq_oss_writeq_sync(struct seq_oss_writeq *q)
{
	struct seq_oss_devinfo *dp = q->dp;
	abstime_t time;

	time = snd_seq_oss_timer_cur_tick(dp->timer);
	if (q->sync_time >= time)
		return 0; /* already finished */

	if (! q->sync_event_put) {
		struct snd_seq_event ev;
		union evrec *rec;

		/* put echoback event */
		memset(&ev, 0, sizeof(ev));
		ev.flags = 0;
		ev.type = SNDRV_SEQ_EVENT_ECHO;
		ev.time.tick = time;
		/* echo back to itself */
		snd_seq_oss_fill_addr(dp, &ev, dp->addr.client, dp->addr.port);
		rec = (union evrec *)&ev.data;
		rec->t.code = SEQ_SYNCTIMER;
		rec->t.time = time;
		q->sync_event_put = 1;
		snd_seq_kernel_client_enqueue_blocking(dp->cseq, &ev, NULL, 0, 0);
	}

	wait_event_interruptible_timeout(q->sync_sleep, ! q->sync_event_put, HZ);
	if (signal_pending(current))
		/* interrupted - return 0 to finish sync */
		q->sync_event_put = 0;
	if (! q->sync_event_put || q->sync_time >= time)
		return 0;
	return 1;
}

void
snd_seq_oss_writeq_wakeup(struct seq_oss_writeq *q, abstime_t time)
{
	unsigned long flags;

	spin_lock_irqsave(&q->sync_lock, flags);
	q->sync_time = time;
	q->sync_event_put = 0;
	wake_up(&q->sync_sleep);
	spin_unlock_irqrestore(&q->sync_lock, flags);
}

int
snd_seq_oss_writeq_get_free_size(struct seq_oss_writeq *q)
{
	struct snd_seq_client_pool pool;
	pool.client = q->dp->cseq;
	snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_GET_CLIENT_POOL, &pool);
	return pool.output_free;
}

void
snd_seq_oss_writeq_set_output(struct seq_oss_writeq *q, int val)
{
	struct snd_seq_client_pool pool;
	pool.client = q->dp->cseq;
	snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_GET_CLIENT_POOL, &pool);
	pool.output_room = val;
	snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_SET_CLIENT_POOL, &pool);
}

