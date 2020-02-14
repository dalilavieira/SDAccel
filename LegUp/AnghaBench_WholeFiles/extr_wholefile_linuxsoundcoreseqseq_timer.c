#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  tid ;
struct timespec64 {scalar_t__ tv_sec; scalar_t__ tv_nsec; } ;
struct snd_timer_instance {void (* callback ) (struct snd_timer_instance*,unsigned long,unsigned long) ;struct snd_timer* timer; int /*<<< orphan*/  flags; struct snd_seq_queue* callback_data; } ;
struct snd_timer_id {scalar_t__ dev_class; int card; scalar_t__ device; void* dev_sclass; int /*<<< orphan*/  subdevice; } ;
struct TYPE_11__ {int flags; } ;
struct snd_timer {TYPE_1__ hw; } ;
struct snd_seq_timer_tick {int resolution; unsigned long fraction; unsigned int cur_tick; } ;
struct TYPE_12__ {scalar_t__ tv_sec; scalar_t__ tv_nsec; } ;
struct snd_seq_timer {int tempo; int ppq; int running; scalar_t__ type; unsigned long preferred_resolution; unsigned int skew; unsigned int skew_base; int ticks; int initialized; struct snd_seq_timer_tick tick; int /*<<< orphan*/  lock; struct timespec64 last_update; TYPE_2__ cur_time; struct snd_timer_instance* timeri; struct snd_timer_id alsa_id; } ;
struct snd_seq_queue {int queue; struct snd_seq_timer* timer; } ;
struct snd_seq_pool {int total_elements; int /*<<< orphan*/  counter; } ;
typedef  scalar_t__ snd_seq_tick_time_t ;
typedef  TYPE_2__ snd_seq_real_time_t ;

/* Variables and functions */
 unsigned long DEFAULT_FREQUENCY ; 
 int EBUSY ; 
 int EINVAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned long MAX_FREQUENCY ; 
 unsigned long MIN_FREQUENCY ; 
 unsigned int SKEW_BASE ; 
 scalar_t__ SNDRV_SEQ_TIMER_ALSA ; 
 scalar_t__ SNDRV_TIMER_CLASS_GLOBAL ; 
 scalar_t__ SNDRV_TIMER_CLASS_SLAVE ; 
 scalar_t__ SNDRV_TIMER_GLOBAL_SYSTEM ; 
 int SNDRV_TIMER_HW_SLAVE ; 
 int /*<<< orphan*/  SNDRV_TIMER_IFLG_AUTO ; 
 void* SNDRV_TIMER_SCLASS_SEQUENCER ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (struct snd_seq_timer*) ; 
 int /*<<< orphan*/  ktime_get_ts64 (struct timespec64*) ; 
 struct snd_seq_timer* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (struct snd_timer_id*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int seq_default_timer_card ; 
 scalar_t__ seq_default_timer_class ; 
 scalar_t__ seq_default_timer_device ; 
 unsigned long seq_default_timer_resolution ; 
 void* seq_default_timer_sclass ; 
 int /*<<< orphan*/  seq_default_timer_subdevice ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_seq_check_queue (struct snd_seq_queue*,int,int /*<<< orphan*/ ) ; 
 void snd_seq_timer_defaults (struct snd_seq_timer*) ; 
 void snd_seq_timer_reset (struct snd_seq_timer*) ; 
 int snd_seq_timer_stop (struct snd_seq_timer*) ; 
 int /*<<< orphan*/  snd_timer_close (struct snd_timer_instance*) ; 
 int snd_timer_open (struct snd_timer_instance**,char*,struct snd_timer_id*,int) ; 
 int /*<<< orphan*/  snd_timer_pause (struct snd_timer_instance*) ; 
 unsigned long snd_timer_resolution (struct snd_timer_instance*) ; 
 int /*<<< orphan*/  snd_timer_start (struct snd_timer_instance*,int) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irq (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 struct timespec64 timespec64_sub (struct timespec64,struct timespec64) ; 

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

__attribute__((used)) static inline int snd_seq_info_init(void) { return 0; }

__attribute__((used)) static inline void snd_seq_info_done(void) {}

__attribute__((used)) static void snd_seq_timer_set_tick_resolution(struct snd_seq_timer *tmr)
{
	if (tmr->tempo < 1000000)
		tmr->tick.resolution = (tmr->tempo * 1000) / tmr->ppq;
	else {
		/* might overflow.. */
		unsigned int s;
		s = tmr->tempo % tmr->ppq;
		s = (s * 1000) / tmr->ppq;
		tmr->tick.resolution = (tmr->tempo / tmr->ppq) * 1000;
		tmr->tick.resolution += s;
	}
	if (tmr->tick.resolution <= 0)
		tmr->tick.resolution = 1;
	snd_seq_timer_update_tick(&tmr->tick, 0);
}

struct snd_seq_timer *snd_seq_timer_new(void)
{
	struct snd_seq_timer *tmr;
	
	tmr = kzalloc(sizeof(*tmr), GFP_KERNEL);
	if (!tmr)
		return NULL;
	spin_lock_init(&tmr->lock);

	/* reset setup to defaults */
	snd_seq_timer_defaults(tmr);
	
	/* reset time */
	snd_seq_timer_reset(tmr);
	
	return tmr;
}

void snd_seq_timer_delete(struct snd_seq_timer **tmr)
{
	struct snd_seq_timer *t = *tmr;
	*tmr = NULL;

	if (t == NULL) {
		pr_debug("ALSA: seq: snd_seq_timer_delete() called with NULL timer\n");
		return;
	}
	t->running = 0;

	/* reset time */
	snd_seq_timer_stop(t);
	snd_seq_timer_reset(t);

	kfree(t);
}

void snd_seq_timer_defaults(struct snd_seq_timer * tmr)
{
	unsigned long flags;

	spin_lock_irqsave(&tmr->lock, flags);
	/* setup defaults */
	tmr->ppq = 96;		/* 96 PPQ */
	tmr->tempo = 500000;	/* 120 BPM */
	snd_seq_timer_set_tick_resolution(tmr);
	tmr->running = 0;

	tmr->type = SNDRV_SEQ_TIMER_ALSA;
	tmr->alsa_id.dev_class = seq_default_timer_class;
	tmr->alsa_id.dev_sclass = seq_default_timer_sclass;
	tmr->alsa_id.card = seq_default_timer_card;
	tmr->alsa_id.device = seq_default_timer_device;
	tmr->alsa_id.subdevice = seq_default_timer_subdevice;
	tmr->preferred_resolution = seq_default_timer_resolution;

	tmr->skew = tmr->skew_base = SKEW_BASE;
	spin_unlock_irqrestore(&tmr->lock, flags);
}

__attribute__((used)) static void seq_timer_reset(struct snd_seq_timer *tmr)
{
	/* reset time & songposition */
	tmr->cur_time.tv_sec = 0;
	tmr->cur_time.tv_nsec = 0;

	tmr->tick.cur_tick = 0;
	tmr->tick.fraction = 0;
}

void snd_seq_timer_reset(struct snd_seq_timer *tmr)
{
	unsigned long flags;

	spin_lock_irqsave(&tmr->lock, flags);
	seq_timer_reset(tmr);
	spin_unlock_irqrestore(&tmr->lock, flags);
}

__attribute__((used)) static void snd_seq_timer_interrupt(struct snd_timer_instance *timeri,
				    unsigned long resolution,
				    unsigned long ticks)
{
	unsigned long flags;
	struct snd_seq_queue *q = timeri->callback_data;
	struct snd_seq_timer *tmr;

	if (q == NULL)
		return;
	tmr = q->timer;
	if (tmr == NULL)
		return;
	spin_lock_irqsave(&tmr->lock, flags);
	if (!tmr->running) {
		spin_unlock_irqrestore(&tmr->lock, flags);
		return;
	}

	resolution *= ticks;
	if (tmr->skew != tmr->skew_base) {
		/* FIXME: assuming skew_base = 0x10000 */
		resolution = (resolution >> 16) * tmr->skew +
			(((resolution & 0xffff) * tmr->skew) >> 16);
	}

	/* update timer */
	snd_seq_inc_time_nsec(&tmr->cur_time, resolution);

	/* calculate current tick */
	snd_seq_timer_update_tick(&tmr->tick, resolution);

	/* register actual time of this timer update */
	ktime_get_ts64(&tmr->last_update);

	spin_unlock_irqrestore(&tmr->lock, flags);

	/* check queues and dispatch events */
	snd_seq_check_queue(q, 1, 0);
}

int snd_seq_timer_set_tempo(struct snd_seq_timer * tmr, int tempo)
{
	unsigned long flags;

	if (snd_BUG_ON(!tmr))
		return -EINVAL;
	if (tempo <= 0)
		return -EINVAL;
	spin_lock_irqsave(&tmr->lock, flags);
	if ((unsigned int)tempo != tmr->tempo) {
		tmr->tempo = tempo;
		snd_seq_timer_set_tick_resolution(tmr);
	}
	spin_unlock_irqrestore(&tmr->lock, flags);
	return 0;
}

int snd_seq_timer_set_tempo_ppq(struct snd_seq_timer *tmr, int tempo, int ppq)
{
	int changed;
	unsigned long flags;

	if (snd_BUG_ON(!tmr))
		return -EINVAL;
	if (tempo <= 0 || ppq <= 0)
		return -EINVAL;
	spin_lock_irqsave(&tmr->lock, flags);
	if (tmr->running && (ppq != tmr->ppq)) {
		/* refuse to change ppq on running timers */
		/* because it will upset the song position (ticks) */
		spin_unlock_irqrestore(&tmr->lock, flags);
		pr_debug("ALSA: seq: cannot change ppq of a running timer\n");
		return -EBUSY;
	}
	changed = (tempo != tmr->tempo) || (ppq != tmr->ppq);
	tmr->tempo = tempo;
	tmr->ppq = ppq;
	if (changed)
		snd_seq_timer_set_tick_resolution(tmr);
	spin_unlock_irqrestore(&tmr->lock, flags);
	return 0;
}

int snd_seq_timer_set_position_tick(struct snd_seq_timer *tmr,
				    snd_seq_tick_time_t position)
{
	unsigned long flags;

	if (snd_BUG_ON(!tmr))
		return -EINVAL;

	spin_lock_irqsave(&tmr->lock, flags);
	tmr->tick.cur_tick = position;
	tmr->tick.fraction = 0;
	spin_unlock_irqrestore(&tmr->lock, flags);
	return 0;
}

int snd_seq_timer_set_position_time(struct snd_seq_timer *tmr,
				    snd_seq_real_time_t position)
{
	unsigned long flags;

	if (snd_BUG_ON(!tmr))
		return -EINVAL;

	snd_seq_sanity_real_time(&position);
	spin_lock_irqsave(&tmr->lock, flags);
	tmr->cur_time = position;
	spin_unlock_irqrestore(&tmr->lock, flags);
	return 0;
}

int snd_seq_timer_set_skew(struct snd_seq_timer *tmr, unsigned int skew,
			   unsigned int base)
{
	unsigned long flags;

	if (snd_BUG_ON(!tmr))
		return -EINVAL;

	/* FIXME */
	if (base != SKEW_BASE) {
		pr_debug("ALSA: seq: invalid skew base 0x%x\n", base);
		return -EINVAL;
	}
	spin_lock_irqsave(&tmr->lock, flags);
	tmr->skew = skew;
	spin_unlock_irqrestore(&tmr->lock, flags);
	return 0;
}

int snd_seq_timer_open(struct snd_seq_queue *q)
{
	struct snd_timer_instance *t;
	struct snd_seq_timer *tmr;
	char str[32];
	int err;

	tmr = q->timer;
	if (snd_BUG_ON(!tmr))
		return -EINVAL;
	if (tmr->timeri)
		return -EBUSY;
	sprintf(str, "sequencer queue %i", q->queue);
	if (tmr->type != SNDRV_SEQ_TIMER_ALSA)	/* standard ALSA timer */
		return -EINVAL;
	if (tmr->alsa_id.dev_class != SNDRV_TIMER_CLASS_SLAVE)
		tmr->alsa_id.dev_sclass = SNDRV_TIMER_SCLASS_SEQUENCER;
	err = snd_timer_open(&t, str, &tmr->alsa_id, q->queue);
	if (err < 0 && tmr->alsa_id.dev_class != SNDRV_TIMER_CLASS_SLAVE) {
		if (tmr->alsa_id.dev_class != SNDRV_TIMER_CLASS_GLOBAL ||
		    tmr->alsa_id.device != SNDRV_TIMER_GLOBAL_SYSTEM) {
			struct snd_timer_id tid;
			memset(&tid, 0, sizeof(tid));
			tid.dev_class = SNDRV_TIMER_CLASS_GLOBAL;
			tid.dev_sclass = SNDRV_TIMER_SCLASS_SEQUENCER;
			tid.card = -1;
			tid.device = SNDRV_TIMER_GLOBAL_SYSTEM;
			err = snd_timer_open(&t, str, &tid, q->queue);
		}
	}
	if (err < 0) {
		pr_err("ALSA: seq fatal error: cannot create timer (%i)\n", err);
		return err;
	}
	t->callback = snd_seq_timer_interrupt;
	t->callback_data = q;
	t->flags |= SNDRV_TIMER_IFLG_AUTO;
	spin_lock_irq(&tmr->lock);
	tmr->timeri = t;
	spin_unlock_irq(&tmr->lock);
	return 0;
}

int snd_seq_timer_close(struct snd_seq_queue *q)
{
	struct snd_seq_timer *tmr;
	struct snd_timer_instance *t;
	
	tmr = q->timer;
	if (snd_BUG_ON(!tmr))
		return -EINVAL;
	spin_lock_irq(&tmr->lock);
	t = tmr->timeri;
	tmr->timeri = NULL;
	spin_unlock_irq(&tmr->lock);
	if (t)
		snd_timer_close(t);
	return 0;
}

__attribute__((used)) static int seq_timer_stop(struct snd_seq_timer *tmr)
{
	if (! tmr->timeri)
		return -EINVAL;
	if (!tmr->running)
		return 0;
	tmr->running = 0;
	snd_timer_pause(tmr->timeri);
	return 0;
}

int snd_seq_timer_stop(struct snd_seq_timer *tmr)
{
	unsigned long flags;
	int err;

	spin_lock_irqsave(&tmr->lock, flags);
	err = seq_timer_stop(tmr);
	spin_unlock_irqrestore(&tmr->lock, flags);
	return err;
}

__attribute__((used)) static int initialize_timer(struct snd_seq_timer *tmr)
{
	struct snd_timer *t;
	unsigned long freq;

	t = tmr->timeri->timer;
	if (!t)
		return -EINVAL;

	freq = tmr->preferred_resolution;
	if (!freq)
		freq = DEFAULT_FREQUENCY;
	else if (freq < MIN_FREQUENCY)
		freq = MIN_FREQUENCY;
	else if (freq > MAX_FREQUENCY)
		freq = MAX_FREQUENCY;

	tmr->ticks = 1;
	if (!(t->hw.flags & SNDRV_TIMER_HW_SLAVE)) {
		unsigned long r = snd_timer_resolution(tmr->timeri);
		if (r) {
			tmr->ticks = (unsigned int)(1000000000uL / (r * freq));
			if (! tmr->ticks)
				tmr->ticks = 1;
		}
	}
	tmr->initialized = 1;
	return 0;
}

__attribute__((used)) static int seq_timer_start(struct snd_seq_timer *tmr)
{
	if (! tmr->timeri)
		return -EINVAL;
	if (tmr->running)
		seq_timer_stop(tmr);
	seq_timer_reset(tmr);
	if (initialize_timer(tmr) < 0)
		return -EINVAL;
	snd_timer_start(tmr->timeri, tmr->ticks);
	tmr->running = 1;
	ktime_get_ts64(&tmr->last_update);
	return 0;
}

int snd_seq_timer_start(struct snd_seq_timer *tmr)
{
	unsigned long flags;
	int err;

	spin_lock_irqsave(&tmr->lock, flags);
	err = seq_timer_start(tmr);
	spin_unlock_irqrestore(&tmr->lock, flags);
	return err;
}

__attribute__((used)) static int seq_timer_continue(struct snd_seq_timer *tmr)
{
	if (! tmr->timeri)
		return -EINVAL;
	if (tmr->running)
		return -EBUSY;
	if (! tmr->initialized) {
		seq_timer_reset(tmr);
		if (initialize_timer(tmr) < 0)
			return -EINVAL;
	}
	snd_timer_start(tmr->timeri, tmr->ticks);
	tmr->running = 1;
	ktime_get_ts64(&tmr->last_update);
	return 0;
}

int snd_seq_timer_continue(struct snd_seq_timer *tmr)
{
	unsigned long flags;
	int err;

	spin_lock_irqsave(&tmr->lock, flags);
	err = seq_timer_continue(tmr);
	spin_unlock_irqrestore(&tmr->lock, flags);
	return err;
}

snd_seq_real_time_t snd_seq_timer_get_cur_time(struct snd_seq_timer *tmr)
{
	snd_seq_real_time_t cur_time;
	unsigned long flags;

	spin_lock_irqsave(&tmr->lock, flags);
	cur_time = tmr->cur_time;
	if (tmr->running) { 
		struct timespec64 tm;

		ktime_get_ts64(&tm);
		tm = timespec64_sub(tm, tmr->last_update);
		cur_time.tv_nsec += tm.tv_nsec;
		cur_time.tv_sec += tm.tv_sec;
		snd_seq_sanity_real_time(&cur_time);
	}
	spin_unlock_irqrestore(&tmr->lock, flags);
	return cur_time;	
}

snd_seq_tick_time_t snd_seq_timer_get_cur_tick(struct snd_seq_timer *tmr)
{
	return tmr->tick.cur_tick;
}

