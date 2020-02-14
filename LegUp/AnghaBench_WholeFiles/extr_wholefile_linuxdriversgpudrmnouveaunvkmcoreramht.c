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
typedef  int u64 ;
typedef  int u32 ;
struct nvkm_ramht_data {int chid; int handle; struct nvkm_gpuobj* inst; } ;
struct nvkm_ramht {int bits; int size; struct nvkm_gpuobj* gpuobj; struct nvkm_gpuobj* parent; struct nvkm_device* device; struct nvkm_ramht_data* data; } ;
struct nvkm_object {int dummy; } ;
struct nvkm_gpuobj {int addr; TYPE_1__* node; } ;
struct nvkm_device {scalar_t__ card_type; } ;
struct TYPE_2__ {int offset; } ;

/* Variables and functions */
 int EEXIST ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOSPC ; 
 scalar_t__ NV_50 ; 
 int /*<<< orphan*/  data ; 
 int /*<<< orphan*/  nvkm_done (struct nvkm_gpuobj*) ; 
 int /*<<< orphan*/  nvkm_gpuobj_del (struct nvkm_gpuobj**) ; 
 int nvkm_gpuobj_new (struct nvkm_device*,int,int,int,struct nvkm_gpuobj*,struct nvkm_gpuobj**) ; 
 int /*<<< orphan*/  nvkm_kmap (struct nvkm_gpuobj*) ; 
 int nvkm_object_bind (struct nvkm_object*,struct nvkm_gpuobj*,int,struct nvkm_gpuobj**) ; 
 int /*<<< orphan*/  nvkm_wo32 (struct nvkm_gpuobj*,int,int) ; 
 int order_base_2 (int) ; 
 int /*<<< orphan*/  struct_size (struct nvkm_ramht*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  vfree (struct nvkm_ramht*) ; 
 struct nvkm_ramht* vzalloc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static u32
nvkm_ramht_hash(struct nvkm_ramht *ramht, int chid, u32 handle)
{
	u32 hash = 0;

	while (handle) {
		hash ^= (handle & ((1 << ramht->bits) - 1));
		handle >>= ramht->bits;
	}

	hash ^= chid << (ramht->bits - 4);
	return hash;
}

struct nvkm_gpuobj *
nvkm_ramht_search(struct nvkm_ramht *ramht, int chid, u32 handle)
{
	u32 co, ho;

	co = ho = nvkm_ramht_hash(ramht, chid, handle);
	do {
		if (ramht->data[co].chid == chid) {
			if (ramht->data[co].handle == handle)
				return ramht->data[co].inst;
		}

		if (++co >= ramht->size)
			co = 0;
	} while (co != ho);

	return NULL;
}

__attribute__((used)) static int
nvkm_ramht_update(struct nvkm_ramht *ramht, int co, struct nvkm_object *object,
		  int chid, int addr, u32 handle, u32 context)
{
	struct nvkm_ramht_data *data = &ramht->data[co];
	u64 inst = 0x00000040; /* just non-zero for <=g8x fifo ramht */
	int ret;

	nvkm_gpuobj_del(&data->inst);
	data->chid = chid;
	data->handle = handle;

	if (object) {
		ret = nvkm_object_bind(object, ramht->parent, 16, &data->inst);
		if (ret) {
			if (ret != -ENODEV) {
				data->chid = -1;
				return ret;
			}
			data->inst = NULL;
		}

		if (data->inst) {
			if (ramht->device->card_type >= NV_50)
				inst = data->inst->node->offset;
			else
				inst = data->inst->addr;
		}

		if (addr < 0) context |= inst << -addr;
		else          context |= inst >>  addr;
	}

	nvkm_kmap(ramht->gpuobj);
	nvkm_wo32(ramht->gpuobj, (co << 3) + 0, handle);
	nvkm_wo32(ramht->gpuobj, (co << 3) + 4, context);
	nvkm_done(ramht->gpuobj);
	return co + 1;
}

void
nvkm_ramht_remove(struct nvkm_ramht *ramht, int cookie)
{
	if (--cookie >= 0)
		nvkm_ramht_update(ramht, cookie, NULL, -1, 0, 0, 0);
}

int
nvkm_ramht_insert(struct nvkm_ramht *ramht, struct nvkm_object *object,
		  int chid, int addr, u32 handle, u32 context)
{
	u32 co, ho;

	if (nvkm_ramht_search(ramht, chid, handle))
		return -EEXIST;

	co = ho = nvkm_ramht_hash(ramht, chid, handle);
	do {
		if (ramht->data[co].chid < 0) {
			return nvkm_ramht_update(ramht, co, object, chid,
						 addr, handle, context);
		}

		if (++co >= ramht->size)
			co = 0;
	} while (co != ho);

	return -ENOSPC;
}

void
nvkm_ramht_del(struct nvkm_ramht **pramht)
{
	struct nvkm_ramht *ramht = *pramht;
	if (ramht) {
		nvkm_gpuobj_del(&ramht->gpuobj);
		vfree(*pramht);
		*pramht = NULL;
	}
}

int
nvkm_ramht_new(struct nvkm_device *device, u32 size, u32 align,
	       struct nvkm_gpuobj *parent, struct nvkm_ramht **pramht)
{
	struct nvkm_ramht *ramht;
	int ret, i;

	if (!(ramht = *pramht = vzalloc(struct_size(ramht, data, (size >> 3)))))
		return -ENOMEM;

	ramht->device = device;
	ramht->parent = parent;
	ramht->size = size >> 3;
	ramht->bits = order_base_2(ramht->size);
	for (i = 0; i < ramht->size; i++)
		ramht->data[i].chid = -1;

	ret = nvkm_gpuobj_new(ramht->device, size, align, true,
			      ramht->parent, &ramht->gpuobj);
	if (ret)
		nvkm_ramht_del(pramht);
	return ret;
}

