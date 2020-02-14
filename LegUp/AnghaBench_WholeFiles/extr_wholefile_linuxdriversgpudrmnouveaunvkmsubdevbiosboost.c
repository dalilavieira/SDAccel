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
struct nvbios_boostS {int pstate; int min; int max; void* percent; void* domain; } ;
struct nvbios_boostE {int pstate; int min; int max; void* percent; void* domain; } ;
struct bit_entry {int version; int length; scalar_t__ offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int /*<<< orphan*/  memset (struct nvbios_boostS*,int,int) ; 
 void* nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd16 (struct nvkm_bios*,int) ; 
 int nvbios_rd32 (struct nvkm_bios*,scalar_t__) ; 

u32
nvbios_boostTe(struct nvkm_bios *bios,
	       u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *snr, u8 *ssz)
{
	struct bit_entry bit_P;
	u32 boost = 0;

	if (!bit_entry(bios, 'P', &bit_P)) {
		if (bit_P.version == 2 && bit_P.length >= 0x34)
			boost = nvbios_rd32(bios, bit_P.offset + 0x30);

		if (boost) {
			*ver = nvbios_rd08(bios, boost + 0);
			switch (*ver) {
			case 0x11:
				*hdr = nvbios_rd08(bios, boost + 1);
				*cnt = nvbios_rd08(bios, boost + 5);
				*len = nvbios_rd08(bios, boost + 2);
				*snr = nvbios_rd08(bios, boost + 4);
				*ssz = nvbios_rd08(bios, boost + 3);
				return boost;
			default:
				break;
			}
		}
	}

	return 0;
}

u32
nvbios_boostEe(struct nvkm_bios *bios, int idx,
	       u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	u8  snr, ssz;
	u32 data = nvbios_boostTe(bios, ver, hdr, cnt, len, &snr, &ssz);
	if (data && idx < *cnt) {
		data = data + *hdr + (idx * (*len + (snr * ssz)));
		*hdr = *len;
		*cnt = snr;
		*len = ssz;
		return data;
	}
	return 0;
}

u32
nvbios_boostEp(struct nvkm_bios *bios, int idx,
	       u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_boostE *info)
{
	u32 data = nvbios_boostEe(bios, idx, ver, hdr, cnt, len);
	memset(info, 0x00, sizeof(*info));
	if (data) {
		info->pstate = (nvbios_rd16(bios, data + 0x00) & 0x01e0) >> 5;
		info->min    =  nvbios_rd16(bios, data + 0x02) * 1000;
		info->max    =  nvbios_rd16(bios, data + 0x04) * 1000;
	}
	return data;
}

u32
nvbios_boostEm(struct nvkm_bios *bios, u8 pstate,
	       u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_boostE *info)
{
	u32 data, idx = 0;
	while ((data = nvbios_boostEp(bios, idx++, ver, hdr, cnt, len, info))) {
		if (info->pstate == pstate)
			break;
	}
	return data;
}

u32
nvbios_boostSe(struct nvkm_bios *bios, int idx,
	       u32 data, u8 *ver, u8 *hdr, u8 cnt, u8 len)
{
	if (data && idx < cnt) {
		data = data + *hdr + (idx * len);
		*hdr = len;
		return data;
	}
	return 0;
}

u32
nvbios_boostSp(struct nvkm_bios *bios, int idx,
	       u32 data, u8 *ver, u8 *hdr, u8 cnt, u8 len,
	       struct nvbios_boostS *info)
{
	data = nvbios_boostSe(bios, idx, data, ver, hdr, cnt, len);
	memset(info, 0x00, sizeof(*info));
	if (data) {
		info->domain  = nvbios_rd08(bios, data + 0x00);
		info->percent = nvbios_rd08(bios, data + 0x01);
		info->min     = nvbios_rd16(bios, data + 0x02) * 1000;
		info->max     = nvbios_rd16(bios, data + 0x04) * 1000;
	}
	return data;
}

