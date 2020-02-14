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
typedef  void* u32 ;
struct nvkm_bios {int dummy; } ;
struct nvbios_vmap_entry {int max0; int max1; int max2; int link; void** arg; void* max; void* min; void* mode; } ;
struct nvbios_vmap {int max0; int max1; int max2; int link; void** arg; void* max; void* min; void* mode; } ;
struct bit_entry {int version; void* offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int /*<<< orphan*/  memset (struct nvbios_vmap_entry*,int,int) ; 
 void* nvbios_rd08 (struct nvkm_bios*,void*) ; 
 void* nvbios_rd32 (struct nvkm_bios*,void*) ; 

u32
nvbios_vmap_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	struct bit_entry bit_P;
	u32 vmap = 0;

	if (!bit_entry(bios, 'P', &bit_P)) {
		if (bit_P.version == 2) {
			vmap = nvbios_rd32(bios, bit_P.offset + 0x20);
			if (vmap) {
				*ver = nvbios_rd08(bios, vmap + 0);
				switch (*ver) {
				case 0x10:
				case 0x20:
					*hdr = nvbios_rd08(bios, vmap + 1);
					*cnt = nvbios_rd08(bios, vmap + 3);
					*len = nvbios_rd08(bios, vmap + 2);
					return vmap;
				default:
					break;
				}
			}
		}
	}

	return 0;
}

u32
nvbios_vmap_parse(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len,
		  struct nvbios_vmap *info)
{
	u32 vmap = nvbios_vmap_table(bios, ver, hdr, cnt, len);
	memset(info, 0x00, sizeof(*info));
	switch (!!vmap * *ver) {
	case 0x10:
		info->max0 = 0xff;
		info->max1 = 0xff;
		info->max2 = 0xff;
		break;
	case 0x20:
		info->max0 = nvbios_rd08(bios, vmap + 0x7);
		info->max1 = nvbios_rd08(bios, vmap + 0x8);
		if (*len >= 0xc)
			info->max2 = nvbios_rd08(bios, vmap + 0xc);
		else
			info->max2 = 0xff;
		break;
	}
	return vmap;
}

u32
nvbios_vmap_entry(struct nvkm_bios *bios, int idx, u8 *ver, u8 *len)
{
	u8  hdr, cnt;
	u32 vmap = nvbios_vmap_table(bios, ver, &hdr, &cnt, len);
	if (vmap && idx < cnt) {
		vmap = vmap + hdr + (idx * *len);
		return vmap;
	}
	return 0;
}

u32
nvbios_vmap_entry_parse(struct nvkm_bios *bios, int idx, u8 *ver, u8 *len,
			struct nvbios_vmap_entry *info)
{
	u32 vmap = nvbios_vmap_entry(bios, idx, ver, len);
	memset(info, 0x00, sizeof(*info));
	switch (!!vmap * *ver) {
	case 0x10:
		info->link   = 0xff;
		info->min    = nvbios_rd32(bios, vmap + 0x00);
		info->max    = nvbios_rd32(bios, vmap + 0x04);
		info->arg[0] = nvbios_rd32(bios, vmap + 0x08);
		info->arg[1] = nvbios_rd32(bios, vmap + 0x0c);
		info->arg[2] = nvbios_rd32(bios, vmap + 0x10);
		break;
	case 0x20:
		info->mode   = nvbios_rd08(bios, vmap + 0x00);
		info->link   = nvbios_rd08(bios, vmap + 0x01);
		info->min    = nvbios_rd32(bios, vmap + 0x02);
		info->max    = nvbios_rd32(bios, vmap + 0x06);
		info->arg[0] = nvbios_rd32(bios, vmap + 0x0a);
		info->arg[1] = nvbios_rd32(bios, vmap + 0x0e);
		info->arg[2] = nvbios_rd32(bios, vmap + 0x12);
		info->arg[3] = nvbios_rd32(bios, vmap + 0x16);
		info->arg[4] = nvbios_rd32(bios, vmap + 0x1a);
		info->arg[5] = nvbios_rd32(bios, vmap + 0x1e);
		break;
	}
	return vmap;
}

