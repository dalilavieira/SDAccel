#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_seq_pool {int total_elements; int /*<<< orphan*/  counter; } ;
struct TYPE_4__ {int /*<<< orphan*/  client; } ;
struct TYPE_3__ {scalar_t__ client; int /*<<< orphan*/  port; } ;
struct snd_seq_event {scalar_t__ type; TYPE_2__ dest; TYPE_1__ source; } ;
struct snd_seq_dummy_port {int /*<<< orphan*/  client; int /*<<< orphan*/  port; int /*<<< orphan*/  connect; scalar_t__ duplex; } ;

/* Variables and functions */
 int /*<<< orphan*/  SNDRV_SEQ_ADDRESS_SUBSCRIBERS ; 
 scalar_t__ SNDRV_SEQ_CLIENT_SYSTEM ; 
 scalar_t__ SNDRV_SEQ_EVENT_KERNEL_ERROR ; 
 int atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (void*) ; 
 int snd_seq_kernel_client_dispatch (int /*<<< orphan*/ ,struct snd_seq_event*,int,int) ; 

__attribute__((used)) static inline int snd_seq_unused_cells(struct snd_seq_pool *pool)
{
	return pool ? pool->total_elements - atomic_read(&pool->counter) : 0;
}

__attribute__((used)) static inline int snd_seq_total_cells(struct snd_seq_pool *pool)
{
	return pool ? pool->total_elements : 0;
}

__attribute__((used)) static int
dummy_input(struct snd_seq_event *ev, int direct, void *private_data,
	    int atomic, int hop)
{
	struct snd_seq_dummy_port *p;
	struct snd_seq_event tmpev;

	p = private_data;
	if (ev->source.client == SNDRV_SEQ_CLIENT_SYSTEM ||
	    ev->type == SNDRV_SEQ_EVENT_KERNEL_ERROR)
		return 0; /* ignore system messages */
	tmpev = *ev;
	if (p->duplex)
		tmpev.source.port = p->connect;
	else
		tmpev.source.port = p->port;
	tmpev.dest.client = SNDRV_SEQ_ADDRESS_SUBSCRIBERS;
	return snd_seq_kernel_client_dispatch(p->client, &tmpev, atomic, hop);
}

__attribute__((used)) static void
dummy_free(void *private_data)
{
	kfree(private_data);
}

