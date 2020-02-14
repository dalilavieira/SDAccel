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
typedef  int u8 ;
typedef  int u32 ;
struct nvkm_i2c_pad {int dummy; } ;
struct i2c_adapter {int dummy; } ;
struct nvkm_i2c_bus {TYPE_1__* pad; struct i2c_adapter i2c; } ;
struct nvkm_i2c_aux {int dummy; } ;
struct i2c_msg {int flags; int addr; int len; int* buf; } ;
struct anx9805_pad {int addr; struct nvkm_i2c_bus* bus; struct nvkm_i2c_pad base; } ;
struct anx9805_bus {int addr; struct nvkm_i2c_bus base; struct anx9805_pad* pad; } ;
struct anx9805_aux {int addr; struct nvkm_i2c_aux base; struct anx9805_pad* pad; } ;
struct TYPE_2__ {int /*<<< orphan*/  i2c; } ;

/* Variables and functions */
 int /*<<< orphan*/  AUX_DBG (struct nvkm_i2c_aux*,char*,...) ; 
 int /*<<< orphan*/  AUX_ERR (struct nvkm_i2c_aux*,char*) ; 
 int EIO ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_M_RD ; 
 struct anx9805_aux* anx9805_aux (struct nvkm_i2c_aux*) ; 
 int /*<<< orphan*/  anx9805_aux_func ; 
 struct anx9805_bus* anx9805_bus (struct nvkm_i2c_bus*) ; 
 int /*<<< orphan*/  anx9805_bus_func ; 
 struct anx9805_pad* anx9805_pad (struct nvkm_i2c_pad*) ; 
 int /*<<< orphan*/  anx9805_pad_func ; 
 void* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int nvkm_i2c_aux_ctor (int /*<<< orphan*/ *,struct nvkm_i2c_pad*,int,struct nvkm_i2c_aux*) ; 
 int nvkm_i2c_bus_ctor (int /*<<< orphan*/ *,struct nvkm_i2c_pad*,int,struct nvkm_i2c_bus*) ; 
 int /*<<< orphan*/  nvkm_i2c_pad_ctor (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,struct nvkm_i2c_pad*) ; 
 int nvkm_rdi2cr (struct i2c_adapter*,int,int) ; 
 int /*<<< orphan*/  nvkm_wri2cr (struct i2c_adapter*,int,int,int) ; 

__attribute__((used)) static int
anx9805_bus_xfer(struct nvkm_i2c_bus *base, struct i2c_msg *msgs, int num)
{
	struct anx9805_bus *bus = anx9805_bus(base);
	struct anx9805_pad *pad = bus->pad;
	struct i2c_adapter *adap = &pad->bus->i2c;
	struct i2c_msg *msg = msgs;
	int ret = -ETIMEDOUT;
	int i, j, cnt = num;
	u8 seg = 0x00, off = 0x00, tmp;

	tmp = nvkm_rdi2cr(adap, pad->addr, 0x07) & ~0x10;
	nvkm_wri2cr(adap, pad->addr, 0x07, tmp | 0x10);
	nvkm_wri2cr(adap, pad->addr, 0x07, tmp);
	nvkm_wri2cr(adap, bus->addr, 0x43, 0x05);
	mdelay(5);

	while (cnt--) {
		if ( (msg->flags & I2C_M_RD) && msg->addr == 0x50) {
			nvkm_wri2cr(adap, bus->addr, 0x40, msg->addr << 1);
			nvkm_wri2cr(adap, bus->addr, 0x41, seg);
			nvkm_wri2cr(adap, bus->addr, 0x42, off);
			nvkm_wri2cr(adap, bus->addr, 0x44, msg->len);
			nvkm_wri2cr(adap, bus->addr, 0x45, 0x00);
			nvkm_wri2cr(adap, bus->addr, 0x43, 0x01);
			for (i = 0; i < msg->len; i++) {
				j = 0;
				while (nvkm_rdi2cr(adap, bus->addr, 0x46) & 0x10) {
					mdelay(5);
					if (j++ == 32)
						goto done;
				}
				msg->buf[i] = nvkm_rdi2cr(adap, bus->addr, 0x47);
			}
		} else
		if (!(msg->flags & I2C_M_RD)) {
			if (msg->addr == 0x50 && msg->len == 0x01) {
				off = msg->buf[0];
			} else
			if (msg->addr == 0x30 && msg->len == 0x01) {
				seg = msg->buf[0];
			} else
				goto done;
		} else {
			goto done;
		}
		msg++;
	}

	ret = num;
done:
	nvkm_wri2cr(adap, bus->addr, 0x43, 0x00);
	return ret;
}

__attribute__((used)) static int
anx9805_bus_new(struct nvkm_i2c_pad *base, int id, u8 drive,
		struct nvkm_i2c_bus **pbus)
{
	struct anx9805_pad *pad = anx9805_pad(base);
	struct anx9805_bus *bus;
	int ret;

	if (!(bus = kzalloc(sizeof(*bus), GFP_KERNEL)))
		return -ENOMEM;
	*pbus = &bus->base;
	bus->pad = pad;

	ret = nvkm_i2c_bus_ctor(&anx9805_bus_func, &pad->base, id, &bus->base);
	if (ret)
		return ret;

	switch (pad->addr) {
	case 0x39: bus->addr = 0x3d; break;
	case 0x3b: bus->addr = 0x3f; break;
	default:
		return -ENOSYS;
	}

	return 0;
}

__attribute__((used)) static int
anx9805_aux_xfer(struct nvkm_i2c_aux *base, bool retry,
		 u8 type, u32 addr, u8 *data, u8 *size)
{
	struct anx9805_aux *aux = anx9805_aux(base);
	struct anx9805_pad *pad = aux->pad;
	struct i2c_adapter *adap = &pad->bus->i2c;
	int i, ret = -ETIMEDOUT;
	u8 buf[16] = {};
	u8 tmp;

	AUX_DBG(&aux->base, "%02x %05x %d", type, addr, *size);

	tmp = nvkm_rdi2cr(adap, pad->addr, 0x07) & ~0x04;
	nvkm_wri2cr(adap, pad->addr, 0x07, tmp | 0x04);
	nvkm_wri2cr(adap, pad->addr, 0x07, tmp);
	nvkm_wri2cr(adap, pad->addr, 0xf7, 0x01);

	nvkm_wri2cr(adap, aux->addr, 0xe4, 0x80);
	if (!(type & 1)) {
		memcpy(buf, data, *size);
		AUX_DBG(&aux->base, "%16ph", buf);
		for (i = 0; i < *size; i++)
			nvkm_wri2cr(adap, aux->addr, 0xf0 + i, buf[i]);
	}
	nvkm_wri2cr(adap, aux->addr, 0xe5, ((*size - 1) << 4) | type);
	nvkm_wri2cr(adap, aux->addr, 0xe6, (addr & 0x000ff) >>  0);
	nvkm_wri2cr(adap, aux->addr, 0xe7, (addr & 0x0ff00) >>  8);
	nvkm_wri2cr(adap, aux->addr, 0xe8, (addr & 0xf0000) >> 16);
	nvkm_wri2cr(adap, aux->addr, 0xe9, 0x01);

	i = 0;
	while ((tmp = nvkm_rdi2cr(adap, aux->addr, 0xe9)) & 0x01) {
		mdelay(5);
		if (i++ == 32)
			goto done;
	}

	if ((tmp = nvkm_rdi2cr(adap, pad->addr, 0xf7)) & 0x01) {
		ret = -EIO;
		goto done;
	}

	if (type & 1) {
		for (i = 0; i < *size; i++)
			buf[i] = nvkm_rdi2cr(adap, aux->addr, 0xf0 + i);
		AUX_DBG(&aux->base, "%16ph", buf);
		memcpy(data, buf, *size);
	}

	ret = 0;
done:
	nvkm_wri2cr(adap, pad->addr, 0xf7, 0x01);
	return ret;
}

__attribute__((used)) static int
anx9805_aux_lnk_ctl(struct nvkm_i2c_aux *base,
		    int link_nr, int link_bw, bool enh)
{
	struct anx9805_aux *aux = anx9805_aux(base);
	struct anx9805_pad *pad = aux->pad;
	struct i2c_adapter *adap = &pad->bus->i2c;
	u8 tmp, i;

	AUX_DBG(&aux->base, "ANX9805 train %d %02x %d",
		link_nr, link_bw, enh);

	nvkm_wri2cr(adap, aux->addr, 0xa0, link_bw);
	nvkm_wri2cr(adap, aux->addr, 0xa1, link_nr | (enh ? 0x80 : 0x00));
	nvkm_wri2cr(adap, aux->addr, 0xa2, 0x01);
	nvkm_wri2cr(adap, aux->addr, 0xa8, 0x01);

	i = 0;
	while ((tmp = nvkm_rdi2cr(adap, aux->addr, 0xa8)) & 0x01) {
		mdelay(5);
		if (i++ == 100) {
			AUX_ERR(&aux->base, "link training timeout");
			return -ETIMEDOUT;
		}
	}

	if (tmp & 0x70) {
		AUX_ERR(&aux->base, "link training failed");
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int
anx9805_aux_new(struct nvkm_i2c_pad *base, int id, u8 drive,
		struct nvkm_i2c_aux **pbus)
{
	struct anx9805_pad *pad = anx9805_pad(base);
	struct anx9805_aux *aux;
	int ret;

	if (!(aux = kzalloc(sizeof(*aux), GFP_KERNEL)))
		return -ENOMEM;
	*pbus = &aux->base;
	aux->pad = pad;

	ret = nvkm_i2c_aux_ctor(&anx9805_aux_func, &pad->base, id, &aux->base);
	if (ret)
		return ret;

	switch (pad->addr) {
	case 0x39: aux->addr = 0x38; break;
	case 0x3b: aux->addr = 0x3c; break;
	default:
		return -ENOSYS;
	}

	return 0;
}

int
anx9805_pad_new(struct nvkm_i2c_bus *bus, int id, u8 addr,
		struct nvkm_i2c_pad **ppad)
{
	struct anx9805_pad *pad;

	if (!(pad = kzalloc(sizeof(*pad), GFP_KERNEL)))
		return -ENOMEM;
	*ppad = &pad->base;

	nvkm_i2c_pad_ctor(&anx9805_pad_func, bus->pad->i2c, id, &pad->base);
	pad->bus = bus;
	pad->addr = addr;
	return 0;
}

