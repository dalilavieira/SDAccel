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
typedef  int u_long ;
struct smt_timer {int tm_delta; int tm_token; struct smt_timer* tm_next; void* tm_active; struct s_smc* tm_smc; } ;
struct TYPE_2__ {struct smt_timer* st_queue; struct smt_timer st_fast; } ;
struct s_smc {TYPE_1__ t; } ;

/* Variables and functions */
 int /*<<< orphan*/  EVENT_SMT ; 
 int EV_TOKEN (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 void* FALSE ; 
 int /*<<< orphan*/  SM_FAST ; 
 void* TRUE ; 
 int /*<<< orphan*/  hwt_init (struct s_smc*) ; 
 int hwt_read (struct s_smc*) ; 
 int /*<<< orphan*/  hwt_start (struct s_smc*,int) ; 
 int /*<<< orphan*/  hwt_stop (struct s_smc*) ; 
static  void timer_done (struct s_smc*,int) ; 
 int /*<<< orphan*/  timer_event (struct s_smc*,int) ; 

void smt_timer_init(struct s_smc *smc)
{
	smc->t.st_queue = NULL;
	smc->t.st_fast.tm_active = FALSE ;
	smc->t.st_fast.tm_next = NULL;
	hwt_init(smc) ;
}

void smt_timer_stop(struct s_smc *smc, struct smt_timer *timer)
{
	struct smt_timer	**prev ;
	struct smt_timer	*tm ;

	/*
	 * remove timer from queue
	 */
	timer->tm_active = FALSE ;
	if (smc->t.st_queue == timer && !timer->tm_next) {
		hwt_stop(smc) ;
	}
	for (prev = &smc->t.st_queue ; (tm = *prev) ; prev = &tm->tm_next ) {
		if (tm == timer) {
			*prev = tm->tm_next ;
			if (tm->tm_next) {
				tm->tm_next->tm_delta += tm->tm_delta ;
			}
			return ;
		}
	}
}

void smt_timer_start(struct s_smc *smc, struct smt_timer *timer, u_long time,
		     u_long token)
{
	struct smt_timer	**prev ;
	struct smt_timer	*tm ;
	u_long			delta = 0 ;

	time /= 16 ;		/* input is uS, clock ticks are 16uS */
	if (!time)
		time = 1 ;
	smt_timer_stop(smc,timer) ;
	timer->tm_smc = smc ;
	timer->tm_token = token ;
	timer->tm_active = TRUE ;
	if (!smc->t.st_queue) {
		smc->t.st_queue = timer ;
		timer->tm_next = NULL;
		timer->tm_delta = time ;
		hwt_start(smc,time) ;
		return ;
	}
	/*
	 * timer correction
	 */
	timer_done(smc,0) ;

	/*
	 * find position in queue
	 */
	delta = 0 ;
	for (prev = &smc->t.st_queue ; (tm = *prev) ; prev = &tm->tm_next ) {
		if (delta + tm->tm_delta > time) {
			break ;
		}
		delta += tm->tm_delta ;
	}
	/* insert in queue */
	*prev = timer ;
	timer->tm_next = tm ;
	timer->tm_delta = time - delta ;
	if (tm)
		tm->tm_delta -= timer->tm_delta ;
	/*
	 * start new with first
	 */
	hwt_start(smc,smc->t.st_queue->tm_delta) ;
}

void smt_force_irq(struct s_smc *smc)
{
	smt_timer_start(smc,&smc->t.st_fast,32L, EV_TOKEN(EVENT_SMT,SM_FAST)); 
}

void smt_timer_done(struct s_smc *smc)
{
	timer_done(smc,1) ;
}

__attribute__((used)) static void timer_done(struct s_smc *smc, int restart)
{
	u_long			delta ;
	struct smt_timer	*tm ;
	struct smt_timer	*next ;
	struct smt_timer	**last ;
	int			done = 0 ;

	delta = hwt_read(smc) ;
	last = &smc->t.st_queue ;
	tm = smc->t.st_queue ;
	while (tm && !done) {
		if (delta >= tm->tm_delta) {
			tm->tm_active = FALSE ;
			delta -= tm->tm_delta ;
			last = &tm->tm_next ;
			tm = tm->tm_next ;
		}
		else {
			tm->tm_delta -= delta ;
			delta = 0 ;
			done = 1 ;
		}
	}
	*last = NULL;
	next = smc->t.st_queue ;
	smc->t.st_queue = tm ;

	for ( tm = next ; tm ; tm = next) {
		next = tm->tm_next ;
		timer_event(smc,tm->tm_token) ;
	}

	if (restart && smc->t.st_queue)
		hwt_start(smc,smc->t.st_queue->tm_delta) ;
}

