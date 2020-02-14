#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_5__ {TYPE_1__* device; } ;
struct nvkm_bios {int bmp_offset; TYPE_2__ subdev; } ;
struct nvbios_perf_fan {int pwm_divisor; } ;
struct TYPE_6__ {int freq; } ;
struct nvbios_perfS {int pstate; int core; int memory; int fanspeed; int voltage; int shader; int script; int vdec; int disp; int pcie_width; TYPE_3__ v40; int /*<<< orphan*/  pcie_speed; } ;
struct nvbios_perfE {int pstate; int core; int memory; int fanspeed; int voltage; int shader; int script; int vdec; int disp; int pcie_width; TYPE_3__ v40; int /*<<< orphan*/  pcie_speed; } ;
struct bit_entry {int version; int offset; } ;
struct TYPE_4__ {int /*<<< orphan*/  chipset; } ;

/* Variables and functions */
 int ENODEV ; 
 int /*<<< orphan*/  NVKM_PCIE_SPEED_2_5 ; 
 int /*<<< orphan*/  NVKM_PCIE_SPEED_5_0 ; 
 int /*<<< orphan*/  NVKM_PCIE_SPEED_8_0 ; 
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int /*<<< orphan*/  memset (struct nvbios_perfS*,int,int) ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd16 (struct nvkm_bios*,int) ; 
 int nvbios_rd32 (struct nvkm_bios*,int) ; 

u32
nvbios_perf_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr,
		  u8 *cnt, u8 *len, u8 *snr, u8 *ssz)
{
	struct bit_entry bit_P;
	u32 perf = 0;

	if (!bit_entry(bios, 'P', &bit_P)) {
		if (bit_P.version <= 2) {
			perf = nvbios_rd32(bios, bit_P.offset + 0);
			if (perf) {
				*ver = nvbios_rd08(bios, perf + 0);
				*hdr = nvbios_rd08(bios, perf + 1);
				if (*ver >= 0x40 && *ver < 0x41) {
					*cnt = nvbios_rd08(bios, perf + 5);
					*len = nvbios_rd08(bios, perf + 2);
					*snr = nvbios_rd08(bios, perf + 4);
					*ssz = nvbios_rd08(bios, perf + 3);
					return perf;
				} else
				if (*ver >= 0x20 && *ver < 0x40) {
					*cnt = nvbios_rd08(bios, perf + 2);
					*len = nvbios_rd08(bios, perf + 3);
					*snr = nvbios_rd08(bios, perf + 4);
					*ssz = nvbios_rd08(bios, perf + 5);
					return perf;
				}
			}
		}
	}

	if (bios->bmp_offset) {
		if (nvbios_rd08(bios, bios->bmp_offset + 6) >= 0x25) {
			perf = nvbios_rd16(bios, bios->bmp_offset + 0x94);
			if (perf) {
				*hdr = nvbios_rd08(bios, perf + 0);
				*ver = nvbios_rd08(bios, perf + 1);
				*cnt = nvbios_rd08(bios, perf + 2);
				*len = nvbios_rd08(bios, perf + 3);
				*snr = 0;
				*ssz = 0;
				return perf;
			}
		}
	}

	return 0;
}

u32
nvbios_perf_entry(struct nvkm_bios *bios, int idx,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	u8  snr, ssz;
	u32 perf = nvbios_perf_table(bios, ver, hdr, cnt, len, &snr, &ssz);
	if (perf && idx < *cnt) {
		perf = perf + *hdr + (idx * (*len + (snr * ssz)));
		*hdr = *len;
		*cnt = snr;
		*len = ssz;
		return perf;
	}
	return 0;
}

u32
nvbios_perfEp(struct nvkm_bios *bios, int idx,
	      u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_perfE *info)
{
	u32 perf = nvbios_perf_entry(bios, idx, ver, hdr, cnt, len);
	memset(info, 0x00, sizeof(*info));
	info->pstate = nvbios_rd08(bios, perf + 0x00);
	switch (!!perf * *ver) {
	case 0x12:
	case 0x13:
	case 0x14:
		info->core     = nvbios_rd32(bios, perf + 0x01) * 10;
		info->memory   = nvbios_rd32(bios, perf + 0x05) * 20;
		info->fanspeed = nvbios_rd08(bios, perf + 0x37);
		if (*hdr > 0x38)
			info->voltage = nvbios_rd08(bios, perf + 0x38);
		break;
	case 0x21:
	case 0x23:
	case 0x24:
		info->fanspeed = nvbios_rd08(bios, perf + 0x04);
		info->voltage  = nvbios_rd08(bios, perf + 0x05);
		info->shader   = nvbios_rd16(bios, perf + 0x06) * 1000;
		info->core     = info->shader + (signed char)
				 nvbios_rd08(bios, perf + 0x08) * 1000;
		switch (bios->subdev.device->chipset) {
		case 0x49:
		case 0x4b:
			info->memory = nvbios_rd16(bios, perf + 0x0b) * 1000;
			break;
		default:
			info->memory = nvbios_rd16(bios, perf + 0x0b) * 2000;
			break;
		}
		break;
	case 0x25:
		info->fanspeed = nvbios_rd08(bios, perf + 0x04);
		info->voltage  = nvbios_rd08(bios, perf + 0x05);
		info->core     = nvbios_rd16(bios, perf + 0x06) * 1000;
		info->shader   = nvbios_rd16(bios, perf + 0x0a) * 1000;
		info->memory   = nvbios_rd16(bios, perf + 0x0c) * 1000;
		break;
	case 0x30:
		info->script   = nvbios_rd16(bios, perf + 0x02);
	case 0x35:
		info->fanspeed = nvbios_rd08(bios, perf + 0x06);
		info->voltage  = nvbios_rd08(bios, perf + 0x07);
		info->core     = nvbios_rd16(bios, perf + 0x08) * 1000;
		info->shader   = nvbios_rd16(bios, perf + 0x0a) * 1000;
		info->memory   = nvbios_rd16(bios, perf + 0x0c) * 1000;
		info->vdec     = nvbios_rd16(bios, perf + 0x10) * 1000;
		info->disp     = nvbios_rd16(bios, perf + 0x14) * 1000;
		break;
	case 0x40:
		info->voltage  = nvbios_rd08(bios, perf + 0x02);
		switch (nvbios_rd08(bios, perf + 0xb) & 0x3) {
		case 0:
			info->pcie_speed = NVKM_PCIE_SPEED_5_0;
			break;
		case 3:
		case 1:
			info->pcie_speed = NVKM_PCIE_SPEED_2_5;
			break;
		case 2:
			info->pcie_speed = NVKM_PCIE_SPEED_8_0;
			break;
		default:
			break;
		}
		info->pcie_width = 0xff;
		break;
	default:
		return 0;
	}
	return perf;
}

u32
nvbios_perfSe(struct nvkm_bios *bios, u32 perfE, int idx,
	      u8 *ver, u8 *hdr, u8 cnt, u8 len)
{
	u32 data = 0x00000000;
	if (idx < cnt) {
		data = perfE + *hdr + (idx * len);
		*hdr = len;
	}
	return data;
}

u32
nvbios_perfSp(struct nvkm_bios *bios, u32 perfE, int idx,
	      u8 *ver, u8 *hdr, u8 cnt, u8 len,
	      struct nvbios_perfS *info)
{
	u32 data = nvbios_perfSe(bios, perfE, idx, ver, hdr, cnt, len);
	memset(info, 0x00, sizeof(*info));
	switch (!!data * *ver) {
	case 0x40:
		info->v40.freq = (nvbios_rd16(bios, data + 0x00) & 0x3fff) * 1000;
		break;
	default:
		break;
	}
	return data;
}

int
nvbios_perf_fan_parse(struct nvkm_bios *bios,
		      struct nvbios_perf_fan *fan)
{
	u8  ver, hdr, cnt, len, snr, ssz;
	u32 perf = nvbios_perf_table(bios, &ver, &hdr, &cnt, &len, &snr, &ssz);
	if (!perf)
		return -ENODEV;

	if (ver >= 0x20 && ver < 0x40 && hdr > 6)
		fan->pwm_divisor = nvbios_rd16(bios, perf + 6);
	else
		fan->pwm_divisor = 0;

	return 0;
}

