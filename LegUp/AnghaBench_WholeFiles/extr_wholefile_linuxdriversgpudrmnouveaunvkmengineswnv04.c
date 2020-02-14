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
struct nvkm_sw_chan {int dummy; } ;
struct nvkm_sw {int dummy; } ;
struct nvkm_oclass {int dummy; } ;
struct nvkm_object {int dummy; } ;
struct nvkm_nvsw {struct nvkm_sw_chan* chan; } ;
struct nvkm_fifo_chan {int dummy; } ;
struct nvkm_device {int dummy; } ;
struct TYPE_2__ {struct nvkm_object object; } ;
struct nv04_sw_chan {TYPE_1__ base; int /*<<< orphan*/  ref; } ;
struct nv04_nvsw_get_ref_v0 {int /*<<< orphan*/  ref; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  NV04_NVSW_GET_REF 128 
 int /*<<< orphan*/  atomic_read (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic_set (int /*<<< orphan*/ *,int) ; 
 struct nv04_sw_chan* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nv04_nvsw ; 
 int /*<<< orphan*/  nv04_sw ; 
 struct nv04_sw_chan* nv04_sw_chan (struct nvkm_sw_chan*) ; 
 int nvif_unpack (int,void**,int*,struct nv04_nvsw_get_ref_v0,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int nvkm_nvsw_new_ (int /*<<< orphan*/ *,struct nvkm_sw_chan*,struct nvkm_oclass const*,void*,int,struct nvkm_object**) ; 
 int nvkm_sw_chan_ctor (struct nv04_sw_chan* (*) (struct nvkm_sw_chan*),struct nvkm_sw*,struct nvkm_fifo_chan*,struct nvkm_oclass const*,TYPE_1__*) ; 
 int nvkm_sw_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,struct nvkm_sw**) ; 

__attribute__((used)) static int
nv04_nvsw_mthd_get_ref(struct nvkm_nvsw *nvsw, void *data, u32 size)
{
	struct nv04_sw_chan *chan = nv04_sw_chan(nvsw->chan);
	union {
		struct nv04_nvsw_get_ref_v0 v0;
	} *args = data;
	int ret = -ENOSYS;

	if (!(ret = nvif_unpack(ret, &data, &size, args->v0, 0, 0, false))) {
		args->v0.ref = atomic_read(&chan->ref);
	}

	return ret;
}

__attribute__((used)) static int
nv04_nvsw_mthd(struct nvkm_nvsw *nvsw, u32 mthd, void *data, u32 size)
{
	switch (mthd) {
	case NV04_NVSW_GET_REF:
		return nv04_nvsw_mthd_get_ref(nvsw, data, size);
	default:
		break;
	}
	return -EINVAL;
}

__attribute__((used)) static int
nv04_nvsw_new(struct nvkm_sw_chan *chan, const struct nvkm_oclass *oclass,
	      void *data, u32 size, struct nvkm_object **pobject)
{
	return nvkm_nvsw_new_(&nv04_nvsw, chan, oclass, data, size, pobject);
}

__attribute__((used)) static bool
nv04_sw_chan_mthd(struct nvkm_sw_chan *base, int subc, u32 mthd, u32 data)
{
	struct nv04_sw_chan *chan = nv04_sw_chan(base);

	switch (mthd) {
	case 0x0150:
		atomic_set(&chan->ref, data);
		return true;
	default:
		break;
	}

	return false;
}

__attribute__((used)) static int
nv04_sw_chan_new(struct nvkm_sw *sw, struct nvkm_fifo_chan *fifo,
		 const struct nvkm_oclass *oclass, struct nvkm_object **pobject)
{
	struct nv04_sw_chan *chan;

	if (!(chan = kzalloc(sizeof(*chan), GFP_KERNEL)))
		return -ENOMEM;
	atomic_set(&chan->ref, 0);
	*pobject = &chan->base.object;

	return nvkm_sw_chan_ctor(&nv04_sw_chan, sw, fifo, oclass, &chan->base);
}

int
nv04_sw_new(struct nvkm_device *device, int index, struct nvkm_sw **psw)
{
	return nvkm_sw_new_(&nv04_sw, device, index, psw);
}

