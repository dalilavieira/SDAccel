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
struct nvkm_bios {int dummy; } ;
struct nvbios_P0260X {void* data; } ;
struct nvbios_P0260E {void* data; } ;
struct bit_entry {int version; int length; int offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int /*<<< orphan*/  memset (struct nvbios_P0260X*,int,int) ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 void* nvbios_rd32 (struct nvkm_bios*,int) ; 

u32
nvbios_P0260Te(struct nvkm_bios *bios,
	       u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *xnr, u8 *xsz)
{
	struct bit_entry bit_P;
	u32 data = 0x00000000;

	if (!bit_entry(bios, 'P', &bit_P)) {
		if (bit_P.version == 2 && bit_P.length > 0x63)
			data = nvbios_rd32(bios, bit_P.offset + 0x60);
		if (data) {
			*ver = nvbios_rd08(bios, data + 0);
			switch (*ver) {
			case 0x10:
				*hdr = nvbios_rd08(bios, data + 1);
				*cnt = nvbios_rd08(bios, data + 2);
				*len = 4;
				*xnr = nvbios_rd08(bios, data + 3);
				*xsz = 4;
				return data;
			default:
				break;
			}
		}
	}

	return 0x00000000;
}

u32
nvbios_P0260Ee(struct nvkm_bios *bios, int idx, u8 *ver, u8 *len)
{
	u8  hdr, cnt, xnr, xsz;
	u32 data = nvbios_P0260Te(bios, ver, &hdr, &cnt, len, &xnr, &xsz);
	if (data && idx < cnt)
		return data + hdr + (idx * *len);
	return 0x00000000;
}

u32
nvbios_P0260Ep(struct nvkm_bios *bios, int idx, u8 *ver, u8 *len,
	       struct nvbios_P0260E *info)
{
	u32 data = nvbios_P0260Ee(bios, idx, ver, len);
	memset(info, 0x00, sizeof(*info));
	switch (!!data * *ver) {
	case 0x10:
		info->data = nvbios_rd32(bios, data);
		return data;
	default:
		break;
	}
	return 0x00000000;
}

u32
nvbios_P0260Xe(struct nvkm_bios *bios, int idx, u8 *ver, u8 *xsz)
{
	u8  hdr, cnt, len, xnr;
	u32 data = nvbios_P0260Te(bios, ver, &hdr, &cnt, &len, &xnr, xsz);
	if (data && idx < xnr)
		return data + hdr + (cnt * len) + (idx * *xsz);
	return 0x00000000;
}

u32
nvbios_P0260Xp(struct nvkm_bios *bios, int idx, u8 *ver, u8 *hdr,
	       struct nvbios_P0260X *info)
{
	u32 data = nvbios_P0260Xe(bios, idx, ver, hdr);
	memset(info, 0x00, sizeof(*info));
	switch (!!data * *ver) {
	case 0x10:
		info->data = nvbios_rd32(bios, data);
		return data;
	default:
		break;
	}
	return 0x00000000;
}

