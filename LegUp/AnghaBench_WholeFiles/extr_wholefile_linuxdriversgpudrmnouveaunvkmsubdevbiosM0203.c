#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct nvkm_subdev {int dummy; } ;
struct nvkm_bios {struct nvkm_subdev subdev; } ;
struct nvbios_M0203T {int type; int strap; int group; void* pointer; } ;
struct nvbios_M0203E {int type; int strap; int group; void* pointer; } ;
struct bit_entry {int version; int length; int offset; } ;

/* Variables and functions */
#define  M0203T_TYPE_RAMCFG 128 
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int /*<<< orphan*/  memset (struct nvbios_M0203T*,int,int) ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 void* nvbios_rd16 (struct nvkm_bios*,int) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*,...) ; 

u32
nvbios_M0203Te(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	struct bit_entry bit_M;
	u32 data = 0x00000000;

	if (!bit_entry(bios, 'M', &bit_M)) {
		if (bit_M.version == 2 && bit_M.length > 0x04)
			data = nvbios_rd16(bios, bit_M.offset + 0x03);
		if (data) {
			*ver = nvbios_rd08(bios, data + 0x00);
			switch (*ver) {
			case 0x10:
				*hdr = nvbios_rd08(bios, data + 0x01);
				*len = nvbios_rd08(bios, data + 0x02);
				*cnt = nvbios_rd08(bios, data + 0x03);
				return data;
			default:
				break;
			}
		}
	}

	return 0x00000000;
}

u32
nvbios_M0203Tp(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len,
	       struct nvbios_M0203T *info)
{
	u32 data = nvbios_M0203Te(bios, ver, hdr, cnt, len);
	memset(info, 0x00, sizeof(*info));
	switch (!!data * *ver) {
	case 0x10:
		info->type    = nvbios_rd08(bios, data + 0x04);
		info->pointer = nvbios_rd16(bios, data + 0x05);
		break;
	default:
		break;
	}
	return data;
}

u32
nvbios_M0203Ee(struct nvkm_bios *bios, int idx, u8 *ver, u8 *hdr)
{
	u8  cnt, len;
	u32 data = nvbios_M0203Te(bios, ver, hdr, &cnt, &len);
	if (data && idx < cnt) {
		data = data + *hdr + idx * len;
		*hdr = len;
		return data;
	}
	return 0x00000000;
}

u32
nvbios_M0203Ep(struct nvkm_bios *bios, int idx, u8 *ver, u8 *hdr,
	       struct nvbios_M0203E *info)
{
	u32 data = nvbios_M0203Ee(bios, idx, ver, hdr);
	memset(info, 0x00, sizeof(*info));
	switch (!!data * *ver) {
	case 0x10:
		info->type  = (nvbios_rd08(bios, data + 0x00) & 0x0f) >> 0;
		info->strap = (nvbios_rd08(bios, data + 0x00) & 0xf0) >> 4;
		info->group = (nvbios_rd08(bios, data + 0x01) & 0x0f) >> 0;
		return data;
	default:
		break;
	}
	return 0x00000000;
}

u32
nvbios_M0203Em(struct nvkm_bios *bios, u8 ramcfg, u8 *ver, u8 *hdr,
	       struct nvbios_M0203E *info)
{
	struct nvkm_subdev *subdev = &bios->subdev;
	struct nvbios_M0203T M0203T;
	u8  cnt, len, idx = 0xff;
	u32 data;

	if (!nvbios_M0203Tp(bios, ver, hdr, &cnt, &len, &M0203T)) {
		nvkm_warn(subdev, "M0203T not found\n");
		return 0x00000000;
	}

	while ((data = nvbios_M0203Ep(bios, ++idx, ver, hdr, info))) {
		switch (M0203T.type) {
		case M0203T_TYPE_RAMCFG:
			if (info->strap != ramcfg)
				continue;
			return data;
		default:
			nvkm_warn(subdev, "M0203T type %02x\n", M0203T.type);
			return 0x00000000;
		}
	}

	return data;
}

