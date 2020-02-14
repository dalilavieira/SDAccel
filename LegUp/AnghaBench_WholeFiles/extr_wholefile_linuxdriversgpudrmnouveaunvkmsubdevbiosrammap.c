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
typedef  scalar_t__ u16 ;
struct nvkm_bios {int dummy; } ;
struct nvbios_ramcfg {int rammap_00_16_20; int rammap_00_16_40; int rammap_00_17_02; int rammap_ver; int rammap_hdr; scalar_t__ rammap_min; scalar_t__ rammap_max; int rammap_10_04_02; int rammap_10_04_08; int rammap_11_08_01; int rammap_11_08_0c; int rammap_11_08_10; int rammap_11_09_01ff; int rammap_11_0a_03fe; int rammap_11_0a_0400; int rammap_11_0a_0800; int rammap_11_0b_01f0; int rammap_11_0b_0200; int rammap_11_0b_0400; int rammap_11_0b_0800; int rammap_11_0d; int rammap_11_0e; int rammap_11_0f; int rammap_11_11_0c; int ramcfg_ver; int ramcfg_timing; int ramcfg_00_03_01; int ramcfg_00_03_02; int ramcfg_DLLoff; int ramcfg_00_03_08; int ramcfg_RON; int ramcfg_FBVDDQ; int ramcfg_00_04_02; int ramcfg_00_04_04; int ramcfg_00_04_20; int ramcfg_00_05; int ramcfg_00_06; int ramcfg_00_07; int ramcfg_00_08; int ramcfg_00_09; int ramcfg_00_0a_0f; int ramcfg_00_0a_f0; int ramcfg_hdr; int ramcfg_10_02_01; int ramcfg_10_02_02; int ramcfg_10_02_04; int ramcfg_10_02_08; int ramcfg_10_02_10; int ramcfg_10_02_20; int ramcfg_10_03_0f; int ramcfg_10_04_01; int ramcfg_10_05; int ramcfg_10_06; int ramcfg_10_07; int ramcfg_10_08; int ramcfg_10_09_0f; int ramcfg_10_09_f0; int ramcfg_11_01_01; int ramcfg_11_01_02; int ramcfg_11_01_04; int ramcfg_11_01_08; int ramcfg_11_01_10; int ramcfg_11_01_40; int ramcfg_11_01_80; int ramcfg_11_02_03; int ramcfg_11_02_04; int ramcfg_11_02_08; int ramcfg_11_02_10; int ramcfg_11_02_40; int ramcfg_11_02_80; int ramcfg_11_03_0f; int ramcfg_11_03_30; int ramcfg_11_03_c0; int ramcfg_11_03_f0; int ramcfg_11_04; int ramcfg_11_06; int ramcfg_11_07_02; int ramcfg_11_07_04; int ramcfg_11_07_08; int ramcfg_11_07_10; int ramcfg_11_07_40; int ramcfg_11_07_80; int ramcfg_11_08_01; int ramcfg_11_08_02; int ramcfg_11_08_04; int ramcfg_11_08_08; int ramcfg_11_08_10; int ramcfg_11_08_20; int ramcfg_11_09; } ;
struct bit_entry {int version; int offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int /*<<< orphan*/  memset (struct nvbios_ramcfg*,int,int) ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 void* nvbios_rd16 (struct nvkm_bios*,int) ; 
 int nvbios_rd32 (struct nvkm_bios*,int) ; 

u32
nvbios_rammapTe(struct nvkm_bios *bios, u8 *ver, u8 *hdr,
		u8 *cnt, u8 *len, u8 *snr, u8 *ssz)
{
	struct bit_entry bit_P;
	u32 rammap = 0x0000;

	if (!bit_entry(bios, 'P', &bit_P)) {
		if (bit_P.version == 2)
			rammap = nvbios_rd32(bios, bit_P.offset + 4);

		if (rammap) {
			*ver = nvbios_rd08(bios, rammap + 0);
			switch (*ver) {
			case 0x10:
			case 0x11:
				*hdr = nvbios_rd08(bios, rammap + 1);
				*cnt = nvbios_rd08(bios, rammap + 5);
				*len = nvbios_rd08(bios, rammap + 2);
				*snr = nvbios_rd08(bios, rammap + 4);
				*ssz = nvbios_rd08(bios, rammap + 3);
				return rammap;
			default:
				break;
			}
		}
	}

	return 0x0000;
}

u32
nvbios_rammapEe(struct nvkm_bios *bios, int idx,
		u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	u8  snr, ssz;
	u32 rammap = nvbios_rammapTe(bios, ver, hdr, cnt, len, &snr, &ssz);
	if (rammap && idx < *cnt) {
		rammap = rammap + *hdr + (idx * (*len + (snr * ssz)));
		*hdr = *len;
		*cnt = snr;
		*len = ssz;
		return rammap;
	}
	return 0x0000;
}

u32
nvbios_rammapEp_from_perf(struct nvkm_bios *bios, u32 data, u8 size,
		struct nvbios_ramcfg *p)
{
	memset(p, 0x00, sizeof(*p));

	p->rammap_00_16_20 = (nvbios_rd08(bios, data + 0x16) & 0x20) >> 5;
	p->rammap_00_16_40 = (nvbios_rd08(bios, data + 0x16) & 0x40) >> 6;
	p->rammap_00_17_02 = (nvbios_rd08(bios, data + 0x17) & 0x02) >> 1;

	return data;
}

u32
nvbios_rammapEp(struct nvkm_bios *bios, int idx,
		u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_ramcfg *p)
{
	u32 data = nvbios_rammapEe(bios, idx, ver, hdr, cnt, len), temp;
	memset(p, 0x00, sizeof(*p));
	p->rammap_ver = *ver;
	p->rammap_hdr = *hdr;
	switch (!!data * *ver) {
	case 0x10:
		p->rammap_min      =  nvbios_rd16(bios, data + 0x00);
		p->rammap_max      =  nvbios_rd16(bios, data + 0x02);
		p->rammap_10_04_02 = (nvbios_rd08(bios, data + 0x04) & 0x02) >> 1;
		p->rammap_10_04_08 = (nvbios_rd08(bios, data + 0x04) & 0x08) >> 3;
		break;
	case 0x11:
		p->rammap_min      =  nvbios_rd16(bios, data + 0x00);
		p->rammap_max      =  nvbios_rd16(bios, data + 0x02);
		p->rammap_11_08_01 = (nvbios_rd08(bios, data + 0x08) & 0x01) >> 0;
		p->rammap_11_08_0c = (nvbios_rd08(bios, data + 0x08) & 0x0c) >> 2;
		p->rammap_11_08_10 = (nvbios_rd08(bios, data + 0x08) & 0x10) >> 4;
		temp = nvbios_rd32(bios, data + 0x09);
		p->rammap_11_09_01ff = (temp & 0x000001ff) >> 0;
		p->rammap_11_0a_03fe = (temp & 0x0003fe00) >> 9;
		p->rammap_11_0a_0400 = (temp & 0x00040000) >> 18;
		p->rammap_11_0a_0800 = (temp & 0x00080000) >> 19;
		p->rammap_11_0b_01f0 = (temp & 0x01f00000) >> 20;
		p->rammap_11_0b_0200 = (temp & 0x02000000) >> 25;
		p->rammap_11_0b_0400 = (temp & 0x04000000) >> 26;
		p->rammap_11_0b_0800 = (temp & 0x08000000) >> 27;
		p->rammap_11_0d    =  nvbios_rd08(bios, data + 0x0d);
		p->rammap_11_0e    =  nvbios_rd08(bios, data + 0x0e);
		p->rammap_11_0f    =  nvbios_rd08(bios, data + 0x0f);
		p->rammap_11_11_0c = (nvbios_rd08(bios, data + 0x11) & 0x0c) >> 2;
		break;
	default:
		data = 0;
		break;
	}
	return data;
}

u32
nvbios_rammapEm(struct nvkm_bios *bios, u16 mhz,
		u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_ramcfg *info)
{
	int idx = 0;
	u32 data;
	while ((data = nvbios_rammapEp(bios, idx++, ver, hdr, cnt, len, info))) {
		if (mhz >= info->rammap_min && mhz <= info->rammap_max)
			break;
	}
	return data;
}

u32
nvbios_rammapSe(struct nvkm_bios *bios, u32 data,
		u8 ever, u8 ehdr, u8 ecnt, u8 elen, int idx, u8 *ver, u8 *hdr)
{
	if (idx < ecnt) {
		data = data + ehdr + (idx * elen);
		*ver = ever;
		*hdr = elen;
		return data;
	}
	return 0;
}

u32
nvbios_rammapSp_from_perf(struct nvkm_bios *bios, u32 data, u8 size, int idx,
		struct nvbios_ramcfg *p)
{
	data += (idx * size);

	if (size < 11)
		return 0x00000000;

	p->ramcfg_ver = 0;
	p->ramcfg_timing   =  nvbios_rd08(bios, data + 0x01);
	p->ramcfg_00_03_01 = (nvbios_rd08(bios, data + 0x03) & 0x01) >> 0;
	p->ramcfg_00_03_02 = (nvbios_rd08(bios, data + 0x03) & 0x02) >> 1;
	p->ramcfg_DLLoff   = (nvbios_rd08(bios, data + 0x03) & 0x04) >> 2;
	p->ramcfg_00_03_08 = (nvbios_rd08(bios, data + 0x03) & 0x08) >> 3;
	p->ramcfg_RON      = (nvbios_rd08(bios, data + 0x03) & 0x10) >> 3;
	p->ramcfg_FBVDDQ   = (nvbios_rd08(bios, data + 0x03) & 0x80) >> 7;
	p->ramcfg_00_04_02 = (nvbios_rd08(bios, data + 0x04) & 0x02) >> 1;
	p->ramcfg_00_04_04 = (nvbios_rd08(bios, data + 0x04) & 0x04) >> 2;
	p->ramcfg_00_04_20 = (nvbios_rd08(bios, data + 0x04) & 0x20) >> 5;
	p->ramcfg_00_05    = (nvbios_rd08(bios, data + 0x05) & 0xff) >> 0;
	p->ramcfg_00_06    = (nvbios_rd08(bios, data + 0x06) & 0xff) >> 0;
	p->ramcfg_00_07    = (nvbios_rd08(bios, data + 0x07) & 0xff) >> 0;
	p->ramcfg_00_08    = (nvbios_rd08(bios, data + 0x08) & 0xff) >> 0;
	p->ramcfg_00_09    = (nvbios_rd08(bios, data + 0x09) & 0xff) >> 0;
	p->ramcfg_00_0a_0f = (nvbios_rd08(bios, data + 0x0a) & 0x0f) >> 0;
	p->ramcfg_00_0a_f0 = (nvbios_rd08(bios, data + 0x0a) & 0xf0) >> 4;

	return data;
}

u32
nvbios_rammapSp(struct nvkm_bios *bios, u32 data,
		u8 ever, u8 ehdr, u8 ecnt, u8 elen, int idx,
		u8 *ver, u8 *hdr, struct nvbios_ramcfg *p)
{
	data = nvbios_rammapSe(bios, data, ever, ehdr, ecnt, elen, idx, ver, hdr);
	p->ramcfg_ver = *ver;
	p->ramcfg_hdr = *hdr;
	switch (!!data * *ver) {
	case 0x10:
		p->ramcfg_timing   =  nvbios_rd08(bios, data + 0x01);
		p->ramcfg_10_02_01 = (nvbios_rd08(bios, data + 0x02) & 0x01) >> 0;
		p->ramcfg_10_02_02 = (nvbios_rd08(bios, data + 0x02) & 0x02) >> 1;
		p->ramcfg_10_02_04 = (nvbios_rd08(bios, data + 0x02) & 0x04) >> 2;
		p->ramcfg_10_02_08 = (nvbios_rd08(bios, data + 0x02) & 0x08) >> 3;
		p->ramcfg_10_02_10 = (nvbios_rd08(bios, data + 0x02) & 0x10) >> 4;
		p->ramcfg_10_02_20 = (nvbios_rd08(bios, data + 0x02) & 0x20) >> 5;
		p->ramcfg_DLLoff   = (nvbios_rd08(bios, data + 0x02) & 0x40) >> 6;
		p->ramcfg_10_03_0f = (nvbios_rd08(bios, data + 0x03) & 0x0f) >> 0;
		p->ramcfg_10_04_01 = (nvbios_rd08(bios, data + 0x04) & 0x01) >> 0;
		p->ramcfg_FBVDDQ   = (nvbios_rd08(bios, data + 0x04) & 0x08) >> 3;
		p->ramcfg_10_05    = (nvbios_rd08(bios, data + 0x05) & 0xff) >> 0;
		p->ramcfg_10_06    = (nvbios_rd08(bios, data + 0x06) & 0xff) >> 0;
		p->ramcfg_10_07    = (nvbios_rd08(bios, data + 0x07) & 0xff) >> 0;
		p->ramcfg_10_08    = (nvbios_rd08(bios, data + 0x08) & 0xff) >> 0;
		p->ramcfg_10_09_0f = (nvbios_rd08(bios, data + 0x09) & 0x0f) >> 0;
		p->ramcfg_10_09_f0 = (nvbios_rd08(bios, data + 0x09) & 0xf0) >> 4;
		break;
	case 0x11:
		p->ramcfg_timing   =  nvbios_rd08(bios, data + 0x00);
		p->ramcfg_11_01_01 = (nvbios_rd08(bios, data + 0x01) & 0x01) >> 0;
		p->ramcfg_11_01_02 = (nvbios_rd08(bios, data + 0x01) & 0x02) >> 1;
		p->ramcfg_11_01_04 = (nvbios_rd08(bios, data + 0x01) & 0x04) >> 2;
		p->ramcfg_11_01_08 = (nvbios_rd08(bios, data + 0x01) & 0x08) >> 3;
		p->ramcfg_11_01_10 = (nvbios_rd08(bios, data + 0x01) & 0x10) >> 4;
		p->ramcfg_DLLoff =   (nvbios_rd08(bios, data + 0x01) & 0x20) >> 5;
		p->ramcfg_11_01_40 = (nvbios_rd08(bios, data + 0x01) & 0x40) >> 6;
		p->ramcfg_11_01_80 = (nvbios_rd08(bios, data + 0x01) & 0x80) >> 7;
		p->ramcfg_11_02_03 = (nvbios_rd08(bios, data + 0x02) & 0x03) >> 0;
		p->ramcfg_11_02_04 = (nvbios_rd08(bios, data + 0x02) & 0x04) >> 2;
		p->ramcfg_11_02_08 = (nvbios_rd08(bios, data + 0x02) & 0x08) >> 3;
		p->ramcfg_11_02_10 = (nvbios_rd08(bios, data + 0x02) & 0x10) >> 4;
		p->ramcfg_11_02_40 = (nvbios_rd08(bios, data + 0x02) & 0x40) >> 6;
		p->ramcfg_11_02_80 = (nvbios_rd08(bios, data + 0x02) & 0x80) >> 7;
		p->ramcfg_11_03_0f = (nvbios_rd08(bios, data + 0x03) & 0x0f) >> 0;
		p->ramcfg_11_03_30 = (nvbios_rd08(bios, data + 0x03) & 0x30) >> 4;
		p->ramcfg_11_03_c0 = (nvbios_rd08(bios, data + 0x03) & 0xc0) >> 6;
		p->ramcfg_11_03_f0 = (nvbios_rd08(bios, data + 0x03) & 0xf0) >> 4;
		p->ramcfg_11_04    = (nvbios_rd08(bios, data + 0x04) & 0xff) >> 0;
		p->ramcfg_11_06    = (nvbios_rd08(bios, data + 0x06) & 0xff) >> 0;
		p->ramcfg_11_07_02 = (nvbios_rd08(bios, data + 0x07) & 0x02) >> 1;
		p->ramcfg_11_07_04 = (nvbios_rd08(bios, data + 0x07) & 0x04) >> 2;
		p->ramcfg_11_07_08 = (nvbios_rd08(bios, data + 0x07) & 0x08) >> 3;
		p->ramcfg_11_07_10 = (nvbios_rd08(bios, data + 0x07) & 0x10) >> 4;
		p->ramcfg_11_07_40 = (nvbios_rd08(bios, data + 0x07) & 0x40) >> 6;
		p->ramcfg_11_07_80 = (nvbios_rd08(bios, data + 0x07) & 0x80) >> 7;
		p->ramcfg_11_08_01 = (nvbios_rd08(bios, data + 0x08) & 0x01) >> 0;
		p->ramcfg_11_08_02 = (nvbios_rd08(bios, data + 0x08) & 0x02) >> 1;
		p->ramcfg_11_08_04 = (nvbios_rd08(bios, data + 0x08) & 0x04) >> 2;
		p->ramcfg_11_08_08 = (nvbios_rd08(bios, data + 0x08) & 0x08) >> 3;
		p->ramcfg_11_08_10 = (nvbios_rd08(bios, data + 0x08) & 0x10) >> 4;
		p->ramcfg_11_08_20 = (nvbios_rd08(bios, data + 0x08) & 0x20) >> 5;
		p->ramcfg_11_09    = (nvbios_rd08(bios, data + 0x09) & 0xff) >> 0;
		break;
	default:
		data = 0;
		break;
	}
	return data;
}

