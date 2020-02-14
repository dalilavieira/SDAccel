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
struct work_struct {int dummy; } ;
struct TYPE_2__ {int client; int port; } ;
struct snd_seq_event {TYPE_1__ dest; int /*<<< orphan*/  source; int /*<<< orphan*/  queue; } ;
struct seq_oss_timer {int realtime; int /*<<< orphan*/  cur_tick; } ;
struct seq_oss_devinfo {int /*<<< orphan*/  addr; int /*<<< orphan*/  queue; int /*<<< orphan*/  cseq; } ;
typedef  int /*<<< orphan*/  abstime_t ;

/* Variables and functions */
 int snd_seq_kernel_client_ctl (int /*<<< orphan*/ ,unsigned int,void*) ; 
 int snd_seq_kernel_client_dispatch (int /*<<< orphan*/ ,struct snd_seq_event*,int,int) ; 
 int /*<<< orphan*/  snd_seq_oss_midi_lookup_ports (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  system_client ; 

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

__attribute__((used)) static void async_call_lookup_ports(struct work_struct *work)
{
	snd_seq_oss_midi_lookup_ports(system_client);
}

