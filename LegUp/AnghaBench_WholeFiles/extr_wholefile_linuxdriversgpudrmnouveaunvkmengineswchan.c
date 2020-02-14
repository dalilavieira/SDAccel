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
typedef  int u32 ;
struct nvkm_sw_chan_func {int (* mthd ) (struct nvkm_sw_chan*,int,int,int) ;void* (* dtor ) (struct nvkm_sw_chan*) ;} ;
struct nvkm_sw_chan {int /*<<< orphan*/  event; int /*<<< orphan*/  head; struct nvkm_fifo_chan* fifo; struct nvkm_sw* sw; struct nvkm_sw_chan_func const* func; int /*<<< orphan*/  object; } ;
struct TYPE_2__ {int /*<<< orphan*/  lock; } ;
struct nvkm_sw {TYPE_1__ engine; int /*<<< orphan*/  chan; } ;
struct nvkm_oclass {int dummy; } ;
struct nvkm_object {int dummy; } ;
struct nvkm_notify {int size; int types; scalar_t__ index; } ;
struct nvkm_fifo_chan {int dummy; } ;
struct nvif_notify_uevent_req {int dummy; } ;
struct nvif_notify_uevent_rep {int dummy; } ;

/* Variables and functions */
 int ENOSYS ; 
 int /*<<< orphan*/  list_add (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  list_del (int /*<<< orphan*/ *) ; 
 int nvif_unvers (int,void**,int*,struct nvif_notify_uevent_req) ; 
 int /*<<< orphan*/  nvkm_event_fini (int /*<<< orphan*/ *) ; 
 int nvkm_event_init (int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nvkm_event_send (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nvkm_object_ctor (struct nvkm_sw_chan* (*) (struct nvkm_object*),struct nvkm_oclass const*,int /*<<< orphan*/ *) ; 
 struct nvkm_sw_chan* nvkm_sw_chan (struct nvkm_object*) ; 
 int /*<<< orphan*/  nvkm_sw_chan_event ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int stub1 (struct nvkm_sw_chan*,int,int,int) ; 
 void* stub2 (struct nvkm_sw_chan*) ; 

bool
nvkm_sw_chan_mthd(struct nvkm_sw_chan *chan, int subc, u32 mthd, u32 data)
{
	switch (mthd) {
	case 0x0000:
		return true;
	case 0x0500:
		nvkm_event_send(&chan->event, 1, 0, NULL, 0);
		return true;
	default:
		if (chan->func->mthd)
			return chan->func->mthd(chan, subc, mthd, data);
		break;
	}
	return false;
}

__attribute__((used)) static int
nvkm_sw_chan_event_ctor(struct nvkm_object *object, void *data, u32 size,
			struct nvkm_notify *notify)
{
	union {
		struct nvif_notify_uevent_req none;
	} *req = data;
	int ret = -ENOSYS;

	if (!(ret = nvif_unvers(ret, &data, &size, req->none))) {
		notify->size  = sizeof(struct nvif_notify_uevent_rep);
		notify->types = 1;
		notify->index = 0;
	}

	return ret;
}

__attribute__((used)) static void *
nvkm_sw_chan_dtor(struct nvkm_object *object)
{
	struct nvkm_sw_chan *chan = nvkm_sw_chan(object);
	struct nvkm_sw *sw = chan->sw;
	unsigned long flags;
	void *data = chan;

	if (chan->func->dtor)
		data = chan->func->dtor(chan);
	nvkm_event_fini(&chan->event);

	spin_lock_irqsave(&sw->engine.lock, flags);
	list_del(&chan->head);
	spin_unlock_irqrestore(&sw->engine.lock, flags);
	return data;
}

int
nvkm_sw_chan_ctor(const struct nvkm_sw_chan_func *func, struct nvkm_sw *sw,
		  struct nvkm_fifo_chan *fifo, const struct nvkm_oclass *oclass,
		  struct nvkm_sw_chan *chan)
{
	unsigned long flags;

	nvkm_object_ctor(&nvkm_sw_chan, oclass, &chan->object);
	chan->func = func;
	chan->sw = sw;
	chan->fifo = fifo;
	spin_lock_irqsave(&sw->engine.lock, flags);
	list_add(&chan->head, &sw->chan);
	spin_unlock_irqrestore(&sw->engine.lock, flags);

	return nvkm_event_init(&nvkm_sw_chan_event, 1, 1, &chan->event);
}

