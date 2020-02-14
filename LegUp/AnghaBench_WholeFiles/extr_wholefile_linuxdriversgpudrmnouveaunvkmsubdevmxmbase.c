#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  scalar_t__ u16 ;
struct TYPE_5__ {struct nvkm_device* device; } ;
struct nvkm_mxm {int* mxms; int /*<<< orphan*/  action; TYPE_1__ subdev; } ;
struct nvkm_i2c_bus {int /*<<< orphan*/  i2c; } ;
struct nvkm_i2c {int dummy; } ;
struct nvkm_device {int /*<<< orphan*/  cfgopt; struct nvkm_bios* bios; struct nvkm_i2c* i2c; } ;
struct nvkm_bios {int dummy; } ;
struct mxm_shadow_h {scalar_t__ (* exec ) (struct nvkm_mxm*,int) ;scalar_t__ name; } ;
struct i2c_msg {int addr; int len; int* buf; int /*<<< orphan*/  flags; } ;

/* Variables and functions */
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  I2C_M_RD ; 
 int /*<<< orphan*/  MXM_SANITISE_DCB ; 
 struct mxm_shadow_h* _mxm_shadow ; 
 int i2c_transfer (int /*<<< orphan*/ *,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 struct nvkm_mxm* kzalloc (int,int /*<<< orphan*/ ) ; 
 int mxm_ddc_map (struct nvkm_bios*,int) ; 
 scalar_t__ mxm_table (struct nvkm_bios*,int*,int*) ; 
 int /*<<< orphan*/  mxms_foreach (struct nvkm_mxm*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int mxms_headerlen (struct nvkm_mxm*) ; 
 int mxms_structlen (struct nvkm_mxm*) ; 
 scalar_t__ mxms_valid (struct nvkm_mxm*) ; 
 int mxms_version (struct nvkm_mxm*) ; 
 int nvbios_rd08 (struct nvkm_bios*,scalar_t__) ; 
 scalar_t__ nvkm_boolopt (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  nvkm_debug (TYPE_1__*,char*,...) ; 
 struct nvkm_i2c_bus* nvkm_i2c_bus_find (struct nvkm_i2c*,int) ; 
 int /*<<< orphan*/  nvkm_info (TYPE_1__*,char*,int,int) ; 
 int /*<<< orphan*/  nvkm_mxm ; 
 int /*<<< orphan*/  nvkm_subdev_ctor (int /*<<< orphan*/ *,struct nvkm_device*,int,TYPE_1__*) ; 
 int /*<<< orphan*/  nvkm_warn (TYPE_1__*,char*) ; 
 scalar_t__ stub1 (struct nvkm_mxm*,int) ; 

__attribute__((used)) static bool
mxm_shadow_rom_fetch(struct nvkm_i2c_bus *bus, u8 addr,
		     u8 offset, u8 size, u8 *data)
{
	struct i2c_msg msgs[] = {
		{ .addr = addr, .flags = 0, .len = 1, .buf = &offset },
		{ .addr = addr, .flags = I2C_M_RD, .len = size, .buf = data, },
	};

	return i2c_transfer(&bus->i2c, msgs, 2) == 2;
}

__attribute__((used)) static bool
mxm_shadow_rom(struct nvkm_mxm *mxm, u8 version)
{
	struct nvkm_device *device = mxm->subdev.device;
	struct nvkm_bios *bios = device->bios;
	struct nvkm_i2c *i2c = device->i2c;
	struct nvkm_i2c_bus *bus = NULL;
	u8 i2cidx, mxms[6], addr, size;

	i2cidx = mxm_ddc_map(bios, 1 /* LVDS_DDC */) & 0x0f;
	if (i2cidx < 0x0f)
		bus = nvkm_i2c_bus_find(i2c, i2cidx);
	if (!bus)
		return false;

	addr = 0x54;
	if (!mxm_shadow_rom_fetch(bus, addr, 0, 6, mxms)) {
		addr = 0x56;
		if (!mxm_shadow_rom_fetch(bus, addr, 0, 6, mxms))
			return false;
	}

	mxm->mxms = mxms;
	size = mxms_headerlen(mxm) + mxms_structlen(mxm);
	mxm->mxms = kmalloc(size, GFP_KERNEL);

	if (mxm->mxms &&
	    mxm_shadow_rom_fetch(bus, addr, 0, size, mxm->mxms))
		return true;

	kfree(mxm->mxms);
	mxm->mxms = NULL;
	return false;
}

__attribute__((used)) static int
mxm_shadow(struct nvkm_mxm *mxm, u8 version)
{
	struct mxm_shadow_h *shadow = _mxm_shadow;
	do {
		nvkm_debug(&mxm->subdev, "checking %s\n", shadow->name);
		if (shadow->exec(mxm, version)) {
			if (mxms_valid(mxm))
				return 0;
			kfree(mxm->mxms);
			mxm->mxms = NULL;
		}
	} while ((++shadow)->name);
	return -ENOENT;
}

int
nvkm_mxm_new_(struct nvkm_device *device, int index, struct nvkm_mxm **pmxm)
{
	struct nvkm_bios *bios = device->bios;
	struct nvkm_mxm *mxm;
	u8  ver, len;
	u16 data;

	if (!(mxm = *pmxm = kzalloc(sizeof(*mxm), GFP_KERNEL)))
		return -ENOMEM;

	nvkm_subdev_ctor(&nvkm_mxm, device, index, &mxm->subdev);

	data = mxm_table(bios, &ver, &len);
	if (!data || !(ver = nvbios_rd08(bios, data))) {
		nvkm_debug(&mxm->subdev, "no VBIOS data, nothing to do\n");
		return 0;
	}

	nvkm_info(&mxm->subdev, "BIOS version %d.%d\n", ver >> 4, ver & 0x0f);
	nvkm_debug(&mxm->subdev, "module flags: %02x\n",
		   nvbios_rd08(bios, data + 0x01));
	nvkm_debug(&mxm->subdev, "config flags: %02x\n",
		   nvbios_rd08(bios, data + 0x02));

	if (mxm_shadow(mxm, ver)) {
		nvkm_warn(&mxm->subdev, "failed to locate valid SIS\n");
#if 0
		/* we should, perhaps, fall back to some kind of limited
		 * mode here if the x86 vbios hasn't already done the
		 * work for us (so we prevent loading with completely
		 * whacked vbios tables).
		 */
		return -EINVAL;
#else
		return 0;
#endif
	}

	nvkm_debug(&mxm->subdev, "MXMS Version %d.%d\n",
		   mxms_version(mxm) >> 8, mxms_version(mxm) & 0xff);
	mxms_foreach(mxm, 0, NULL, NULL);

	if (nvkm_boolopt(device->cfgopt, "NvMXMDCB", true))
		mxm->action |= MXM_SANITISE_DCB;
	return 0;
}

