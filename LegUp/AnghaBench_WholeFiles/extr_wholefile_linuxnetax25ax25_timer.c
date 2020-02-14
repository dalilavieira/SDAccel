#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
struct timer_list {unsigned long expires; } ;
struct TYPE_24__ {unsigned long t1; unsigned long t2; scalar_t__ t3; scalar_t__ idle; TYPE_1__* ax25_dev; struct timer_list t1timer; struct timer_list idletimer; struct timer_list t3timer; struct timer_list t2timer; struct timer_list timer; } ;
typedef  TYPE_2__ ax25_cb ;
struct TYPE_23__ {int* values; } ;

/* Variables and functions */
#define  AX25_PROTO_STD_DUPLEX 129 
#define  AX25_PROTO_STD_SIMPLEX 128 
 size_t AX25_VALUES_PROTOCOL ; 
 int HZ ; 
 TYPE_2__* ax25 ; 
static  void ax25_heartbeat_expiry (struct timer_list*) ; 
static  void ax25_idletimer_expiry (struct timer_list*) ; 
 int /*<<< orphan*/  ax25_std_heartbeat_expiry (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_std_idletimer_expiry (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_std_t1timer_expiry (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_std_t2timer_expiry (TYPE_2__*) ; 
 int /*<<< orphan*/  ax25_std_t3timer_expiry (TYPE_2__*) ; 
static  void ax25_t1timer_expiry (struct timer_list*) ; 
static  void ax25_t2timer_expiry (struct timer_list*) ; 
static  void ax25_t3timer_expiry (struct timer_list*) ; 
 int /*<<< orphan*/  del_timer (struct timer_list*) ; 
 TYPE_2__* from_timer (TYPE_2__*,struct timer_list*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idletimer ; 
 unsigned long jiffies ; 
 int /*<<< orphan*/  mod_timer (struct timer_list*,unsigned long) ; 
 int /*<<< orphan*/  t1timer ; 
 int /*<<< orphan*/  t2timer ; 
 int /*<<< orphan*/  t3timer ; 
 int /*<<< orphan*/  timer ; 
 int timer_pending (struct timer_list*) ; 
 int /*<<< orphan*/  timer_setup (struct timer_list*,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 

void ax25_setup_timers(ax25_cb *ax25)
{
	timer_setup(&ax25->timer, ax25_heartbeat_expiry, 0);
	timer_setup(&ax25->t1timer, ax25_t1timer_expiry, 0);
	timer_setup(&ax25->t2timer, ax25_t2timer_expiry, 0);
	timer_setup(&ax25->t3timer, ax25_t3timer_expiry, 0);
	timer_setup(&ax25->idletimer, ax25_idletimer_expiry, 0);
}

void ax25_start_heartbeat(ax25_cb *ax25)
{
	mod_timer(&ax25->timer, jiffies + 5 * HZ);
}

void ax25_start_t1timer(ax25_cb *ax25)
{
	mod_timer(&ax25->t1timer, jiffies + ax25->t1);
}

void ax25_start_t2timer(ax25_cb *ax25)
{
	mod_timer(&ax25->t2timer, jiffies + ax25->t2);
}

void ax25_start_t3timer(ax25_cb *ax25)
{
	if (ax25->t3 > 0)
		mod_timer(&ax25->t3timer, jiffies + ax25->t3);
	else
		del_timer(&ax25->t3timer);
}

void ax25_start_idletimer(ax25_cb *ax25)
{
	if (ax25->idle > 0)
		mod_timer(&ax25->idletimer, jiffies + ax25->idle);
	else
		del_timer(&ax25->idletimer);
}

void ax25_stop_heartbeat(ax25_cb *ax25)
{
	del_timer(&ax25->timer);
}

void ax25_stop_t1timer(ax25_cb *ax25)
{
	del_timer(&ax25->t1timer);
}

void ax25_stop_t2timer(ax25_cb *ax25)
{
	del_timer(&ax25->t2timer);
}

void ax25_stop_t3timer(ax25_cb *ax25)
{
	del_timer(&ax25->t3timer);
}

void ax25_stop_idletimer(ax25_cb *ax25)
{
	del_timer(&ax25->idletimer);
}

int ax25_t1timer_running(ax25_cb *ax25)
{
	return timer_pending(&ax25->t1timer);
}

unsigned long ax25_display_timer(struct timer_list *timer)
{
	if (!timer_pending(timer))
		return 0;

	return timer->expires - jiffies;
}

__attribute__((used)) static void ax25_heartbeat_expiry(struct timer_list *t)
{
	int proto = AX25_PROTO_STD_SIMPLEX;
	ax25_cb *ax25 = from_timer(ax25, t, timer);

	if (ax25->ax25_dev)
		proto = ax25->ax25_dev->values[AX25_VALUES_PROTOCOL];

	switch (proto) {
	case AX25_PROTO_STD_SIMPLEX:
	case AX25_PROTO_STD_DUPLEX:
		ax25_std_heartbeat_expiry(ax25);
		break;

#ifdef CONFIG_AX25_DAMA_SLAVE
	case AX25_PROTO_DAMA_SLAVE:
		if (ax25->ax25_dev->dama.slave)
			ax25_ds_heartbeat_expiry(ax25);
		else
			ax25_std_heartbeat_expiry(ax25);
		break;
#endif
	}
}

__attribute__((used)) static void ax25_t1timer_expiry(struct timer_list *t)
{
	ax25_cb *ax25 = from_timer(ax25, t, t1timer);

	switch (ax25->ax25_dev->values[AX25_VALUES_PROTOCOL]) {
	case AX25_PROTO_STD_SIMPLEX:
	case AX25_PROTO_STD_DUPLEX:
		ax25_std_t1timer_expiry(ax25);
		break;

#ifdef CONFIG_AX25_DAMA_SLAVE
	case AX25_PROTO_DAMA_SLAVE:
		if (!ax25->ax25_dev->dama.slave)
			ax25_std_t1timer_expiry(ax25);
		break;
#endif
	}
}

__attribute__((used)) static void ax25_t2timer_expiry(struct timer_list *t)
{
	ax25_cb *ax25 = from_timer(ax25, t, t2timer);

	switch (ax25->ax25_dev->values[AX25_VALUES_PROTOCOL]) {
	case AX25_PROTO_STD_SIMPLEX:
	case AX25_PROTO_STD_DUPLEX:
		ax25_std_t2timer_expiry(ax25);
		break;

#ifdef CONFIG_AX25_DAMA_SLAVE
	case AX25_PROTO_DAMA_SLAVE:
		if (!ax25->ax25_dev->dama.slave)
			ax25_std_t2timer_expiry(ax25);
		break;
#endif
	}
}

__attribute__((used)) static void ax25_t3timer_expiry(struct timer_list *t)
{
	ax25_cb *ax25 = from_timer(ax25, t, t3timer);

	switch (ax25->ax25_dev->values[AX25_VALUES_PROTOCOL]) {
	case AX25_PROTO_STD_SIMPLEX:
	case AX25_PROTO_STD_DUPLEX:
		ax25_std_t3timer_expiry(ax25);
		break;

#ifdef CONFIG_AX25_DAMA_SLAVE
	case AX25_PROTO_DAMA_SLAVE:
		if (ax25->ax25_dev->dama.slave)
			ax25_ds_t3timer_expiry(ax25);
		else
			ax25_std_t3timer_expiry(ax25);
		break;
#endif
	}
}

__attribute__((used)) static void ax25_idletimer_expiry(struct timer_list *t)
{
	ax25_cb *ax25 = from_timer(ax25, t, idletimer);

	switch (ax25->ax25_dev->values[AX25_VALUES_PROTOCOL]) {
	case AX25_PROTO_STD_SIMPLEX:
	case AX25_PROTO_STD_DUPLEX:
		ax25_std_idletimer_expiry(ax25);
		break;

#ifdef CONFIG_AX25_DAMA_SLAVE
	case AX25_PROTO_DAMA_SLAVE:
		if (ax25->ax25_dev->dama.slave)
			ax25_ds_idletimer_expiry(ax25);
		else
			ax25_std_idletimer_expiry(ax25);
		break;
#endif
	}
}

