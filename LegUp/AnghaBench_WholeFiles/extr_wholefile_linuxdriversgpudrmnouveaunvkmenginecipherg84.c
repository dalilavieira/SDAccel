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
typedef  int u64 ;
typedef  int u32 ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_object {int oclass; TYPE_2__* engine; } ;
struct nvkm_gpuobj {int dummy; } ;
struct TYPE_8__ {TYPE_3__* client; } ;
struct nvkm_fifo_chan {int chid; TYPE_4__ object; } ;
struct nvkm_fifo {int dummy; } ;
struct nvkm_engine {struct nvkm_subdev subdev; } ;
struct nvkm_device {struct nvkm_fifo* fifo; } ;
typedef  int /*<<< orphan*/  msg ;
struct TYPE_7__ {char* name; } ;
struct TYPE_5__ {int /*<<< orphan*/  device; } ;
struct TYPE_6__ {TYPE_1__ subdev; } ;

/* Variables and functions */
 int /*<<< orphan*/  g84_cipher ; 
 int /*<<< orphan*/  g84_cipher_intr_mask ; 
 int /*<<< orphan*/  nvkm_done (struct nvkm_gpuobj*) ; 
 int nvkm_engine_new_ (int /*<<< orphan*/ *,struct nvkm_device*,int,int,struct nvkm_engine**) ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*,int,char*,int,int,char*,int,int) ; 
 struct nvkm_fifo_chan* nvkm_fifo_chan_inst (struct nvkm_fifo*,int,unsigned long*) ; 
 int /*<<< orphan*/  nvkm_fifo_chan_put (struct nvkm_fifo*,unsigned long,struct nvkm_fifo_chan**) ; 
 int nvkm_gpuobj_new (int /*<<< orphan*/ ,int,int,int,struct nvkm_gpuobj*,struct nvkm_gpuobj**) ; 
 int /*<<< orphan*/  nvkm_kmap (struct nvkm_gpuobj*) ; 
 int nvkm_rd32 (struct nvkm_device*,int) ; 
 int /*<<< orphan*/  nvkm_snprintbf (char*,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_gpuobj*,int,int) ; 
 int /*<<< orphan*/  nvkm_wr32 (struct nvkm_device*,int,int) ; 

__attribute__((used)) static int
g84_cipher_oclass_bind(struct nvkm_object *object, struct nvkm_gpuobj *parent,
		       int align, struct nvkm_gpuobj **pgpuobj)
{
	int ret = nvkm_gpuobj_new(object->engine->subdev.device, 16,
				  align, false, parent, pgpuobj);
	if (ret == 0) {
		nvkm_kmap(*pgpuobj);
		nvkm_wo32(*pgpuobj, 0x00, object->oclass);
		nvkm_wo32(*pgpuobj, 0x04, 0x00000000);
		nvkm_wo32(*pgpuobj, 0x08, 0x00000000);
		nvkm_wo32(*pgpuobj, 0x0c, 0x00000000);
		nvkm_done(*pgpuobj);
	}
	return ret;
}

__attribute__((used)) static int
g84_cipher_cclass_bind(struct nvkm_object *object, struct nvkm_gpuobj *parent,
		       int align, struct nvkm_gpuobj **pgpuobj)
{
	return nvkm_gpuobj_new(object->engine->subdev.device, 256,
			       align, true, parent, pgpuobj);

}

__attribute__((used)) static void
g84_cipher_intr(struct nvkm_engine *cipher)
{
	struct nvkm_subdev *subdev = &cipher->subdev;
	struct nvkm_device *device = subdev->device;
	struct nvkm_fifo *fifo = device->fifo;
	struct nvkm_fifo_chan *chan;
	u32 stat = nvkm_rd32(device, 0x102130);
	u32 mthd = nvkm_rd32(device, 0x102190);
	u32 data = nvkm_rd32(device, 0x102194);
	u32 inst = nvkm_rd32(device, 0x102188) & 0x7fffffff;
	unsigned long flags;
	char msg[128];

	chan = nvkm_fifo_chan_inst(fifo, (u64)inst << 12, &flags);
	if (stat) {
		nvkm_snprintbf(msg, sizeof(msg), g84_cipher_intr_mask, stat);
		nvkm_error(subdev,  "%08x [%s] ch %d [%010llx %s] "
				    "mthd %04x data %08x\n", stat, msg,
			   chan ? chan->chid : -1, (u64)inst << 12,
			   chan ? chan->object.client->name : "unknown",
			   mthd, data);
	}
	nvkm_fifo_chan_put(fifo, flags, &chan);

	nvkm_wr32(device, 0x102130, stat);
	nvkm_wr32(device, 0x10200c, 0x10);
}

__attribute__((used)) static int
g84_cipher_init(struct nvkm_engine *cipher)
{
	struct nvkm_device *device = cipher->subdev.device;
	nvkm_wr32(device, 0x102130, 0xffffffff);
	nvkm_wr32(device, 0x102140, 0xffffffbf);
	nvkm_wr32(device, 0x10200c, 0x00000010);
	return 0;
}

int
g84_cipher_new(struct nvkm_device *device, int index,
	       struct nvkm_engine **pengine)
{
	return nvkm_engine_new_(&g84_cipher, device, index, true, pengine);
}

