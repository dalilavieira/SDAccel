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
typedef  scalar_t__ u32 ;
struct pll_mapping {scalar_t__ reg; scalar_t__ type; } ;
struct nvkm_subdev {struct nvkm_device* device; } ;
struct nvkm_device {int card_type; int chipset; int crystal; } ;
struct TYPE_6__ {int chip; } ;
struct nvkm_bios {scalar_t__ bmp_offset; TYPE_3__ version; struct nvkm_subdev subdev; } ;
struct TYPE_5__ {int min_freq; int max_freq; int min_inputfreq; int max_inputfreq; int min_n; int max_n; int min_m; int max_m; } ;
struct TYPE_4__ {int min_freq; int max_freq; int min_inputfreq; int max_inputfreq; int min_n; int max_n; int min_m; int max_m; } ;
struct nvbios_pll {int reg; int max_p; int max_p_usable; int bias_p; int refclk; int min_p; TYPE_2__ vco1; TYPE_1__ vco2; scalar_t__ type; } ;
struct bit_entry {int version; int length; scalar_t__ offset; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 void* INT_MAX ; 
#define  NV_04 134 
#define  NV_10 133 
#define  NV_11 132 
#define  NV_20 131 
#define  NV_30 130 
#define  NV_40 129 
#define  NV_50 128 
 scalar_t__ PLL_MAX ; 
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int bmp_version (struct nvkm_bios*) ; 
 struct pll_mapping* g84_pll_mapping ; 
 int /*<<< orphan*/  memset (struct nvbios_pll*,int /*<<< orphan*/ ,int) ; 
 struct pll_mapping* nv04_pll_mapping ; 
 struct pll_mapping* nv40_pll_mapping ; 
 struct pll_mapping* nv50_pll_mapping ; 
 int nvbios_rd08 (struct nvkm_bios*,scalar_t__) ; 
 int nvbios_rd16 (struct nvkm_bios*,scalar_t__) ; 
 scalar_t__ nvbios_rd32 (struct nvkm_bios*,scalar_t__) ; 
 int /*<<< orphan*/  nvkm_error (struct nvkm_subdev*,char*,int) ; 
 scalar_t__ nvkm_rd32 (struct nvkm_device*,int) ; 
 int nvkm_rdvgac (struct nvkm_device*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static u32
pll_limits_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	struct bit_entry bit_C;
	u32 data = 0x0000;

	if (!bit_entry(bios, 'C', &bit_C)) {
		if (bit_C.version == 1 && bit_C.length >= 10)
			data = nvbios_rd16(bios, bit_C.offset + 8);
		if (bit_C.version == 2 && bit_C.length >= 4)
			data = nvbios_rd32(bios, bit_C.offset + 0);
		if (data) {
			*ver = nvbios_rd08(bios, data + 0);
			*hdr = nvbios_rd08(bios, data + 1);
			*len = nvbios_rd08(bios, data + 2);
			*cnt = nvbios_rd08(bios, data + 3);
			return data;
		}
	}

	if (bmp_version(bios) >= 0x0524) {
		data = nvbios_rd16(bios, bios->bmp_offset + 142);
		if (data) {
			*ver = nvbios_rd08(bios, data + 0);
			*hdr = 1;
			*cnt = 1;
			*len = 0x18;
			return data;
		}
	}

	*ver = 0x00;
	return data;
}

__attribute__((used)) static struct pll_mapping *
pll_map(struct nvkm_bios *bios)
{
	struct nvkm_device *device = bios->subdev.device;
	switch (device->card_type) {
	case NV_04:
	case NV_10:
	case NV_11:
	case NV_20:
	case NV_30:
		return nv04_pll_mapping;
		break;
	case NV_40:
		return nv40_pll_mapping;
	case NV_50:
		if (device->chipset == 0x50)
			return nv50_pll_mapping;
		else
		if (device->chipset <  0xa3 ||
		    device->chipset == 0xaa ||
		    device->chipset == 0xac)
			return g84_pll_mapping;
	default:
		return NULL;
	}
}

__attribute__((used)) static u32
pll_map_reg(struct nvkm_bios *bios, u32 reg, u32 *type, u8 *ver, u8 *len)
{
	struct pll_mapping *map;
	u8  hdr, cnt;
	u32 data;

	data = pll_limits_table(bios, ver, &hdr, &cnt, len);
	if (data && *ver >= 0x30) {
		data += hdr;
		while (cnt--) {
			if (nvbios_rd32(bios, data + 3) == reg) {
				*type = nvbios_rd08(bios, data + 0);
				return data;
			}
			data += *len;
		}
		return 0x0000;
	}

	map = pll_map(bios);
	while (map && map->reg) {
		if (map->reg == reg && *ver >= 0x20) {
			u32 addr = (data += hdr);
			*type = map->type;
			while (cnt--) {
				if (nvbios_rd32(bios, data) == map->reg)
					return data;
				data += *len;
			}
			return addr;
		} else
		if (map->reg == reg) {
			*type = map->type;
			return data + 1;
		}
		map++;
	}

	return 0x0000;
}

__attribute__((used)) static u32
pll_map_type(struct nvkm_bios *bios, u8 type, u32 *reg, u8 *ver, u8 *len)
{
	struct pll_mapping *map;
	u8  hdr, cnt;
	u32 data;

	data = pll_limits_table(bios, ver, &hdr, &cnt, len);
	if (data && *ver >= 0x30) {
		data += hdr;
		while (cnt--) {
			if (nvbios_rd08(bios, data + 0) == type) {
				if (*ver < 0x50)
					*reg = nvbios_rd32(bios, data + 3);
				else
					*reg = 0;
				return data;
			}
			data += *len;
		}
		return 0x0000;
	}

	map = pll_map(bios);
	while (map && map->reg) {
		if (map->type == type && *ver >= 0x20) {
			u32 addr = (data += hdr);
			*reg = map->reg;
			while (cnt--) {
				if (nvbios_rd32(bios, data) == map->reg)
					return data;
				data += *len;
			}
			return addr;
		} else
		if (map->type == type) {
			*reg = map->reg;
			return data + 1;
		}
		map++;
	}

	return 0x0000;
}

int
nvbios_pll_parse(struct nvkm_bios *bios, u32 type, struct nvbios_pll *info)
{
	struct nvkm_subdev *subdev = &bios->subdev;
	struct nvkm_device *device = subdev->device;
	u8  ver, len;
	u32 reg = type;
	u32 data;

	if (type > PLL_MAX) {
		reg  = type;
		data = pll_map_reg(bios, reg, &type, &ver, &len);
	} else {
		data = pll_map_type(bios, type, &reg, &ver, &len);
	}

	if (ver && !data)
		return -ENOENT;

	memset(info, 0, sizeof(*info));
	info->type = type;
	info->reg = reg;

	switch (ver) {
	case 0x00:
		break;
	case 0x10:
	case 0x11:
		info->vco1.min_freq = nvbios_rd32(bios, data + 0);
		info->vco1.max_freq = nvbios_rd32(bios, data + 4);
		info->vco2.min_freq = nvbios_rd32(bios, data + 8);
		info->vco2.max_freq = nvbios_rd32(bios, data + 12);
		info->vco1.min_inputfreq = nvbios_rd32(bios, data + 16);
		info->vco2.min_inputfreq = nvbios_rd32(bios, data + 20);
		info->vco1.max_inputfreq = INT_MAX;
		info->vco2.max_inputfreq = INT_MAX;

		info->max_p = 0x7;
		info->max_p_usable = 0x6;

		/* these values taken from nv30/31/36 */
		switch (bios->version.chip) {
		case 0x36:
			info->vco1.min_n = 0x5;
			break;
		default:
			info->vco1.min_n = 0x1;
			break;
		}
		info->vco1.max_n = 0xff;
		info->vco1.min_m = 0x1;
		info->vco1.max_m = 0xd;

		/*
		 * On nv30, 31, 36 (i.e. all cards with two stage PLLs with this
		 * table version (apart from nv35)), N2 is compared to
		 * maxN2 (0x46) and 10 * maxM2 (0x4), so set maxN2 to 0x28 and
		 * save a comparison
		 */
		info->vco2.min_n = 0x4;
		switch (bios->version.chip) {
		case 0x30:
		case 0x35:
			info->vco2.max_n = 0x1f;
			break;
		default:
			info->vco2.max_n = 0x28;
			break;
		}
		info->vco2.min_m = 0x1;
		info->vco2.max_m = 0x4;
		break;
	case 0x20:
	case 0x21:
		info->vco1.min_freq = nvbios_rd16(bios, data + 4) * 1000;
		info->vco1.max_freq = nvbios_rd16(bios, data + 6) * 1000;
		info->vco2.min_freq = nvbios_rd16(bios, data + 8) * 1000;
		info->vco2.max_freq = nvbios_rd16(bios, data + 10) * 1000;
		info->vco1.min_inputfreq = nvbios_rd16(bios, data + 12) * 1000;
		info->vco2.min_inputfreq = nvbios_rd16(bios, data + 14) * 1000;
		info->vco1.max_inputfreq = nvbios_rd16(bios, data + 16) * 1000;
		info->vco2.max_inputfreq = nvbios_rd16(bios, data + 18) * 1000;
		info->vco1.min_n = nvbios_rd08(bios, data + 20);
		info->vco1.max_n = nvbios_rd08(bios, data + 21);
		info->vco1.min_m = nvbios_rd08(bios, data + 22);
		info->vco1.max_m = nvbios_rd08(bios, data + 23);
		info->vco2.min_n = nvbios_rd08(bios, data + 24);
		info->vco2.max_n = nvbios_rd08(bios, data + 25);
		info->vco2.min_m = nvbios_rd08(bios, data + 26);
		info->vco2.max_m = nvbios_rd08(bios, data + 27);

		info->max_p = nvbios_rd08(bios, data + 29);
		info->max_p_usable = info->max_p;
		if (bios->version.chip < 0x60)
			info->max_p_usable = 0x6;
		info->bias_p = nvbios_rd08(bios, data + 30);

		if (len > 0x22)
			info->refclk = nvbios_rd32(bios, data + 31);
		break;
	case 0x30:
		data = nvbios_rd16(bios, data + 1);

		info->vco1.min_freq = nvbios_rd16(bios, data + 0) * 1000;
		info->vco1.max_freq = nvbios_rd16(bios, data + 2) * 1000;
		info->vco2.min_freq = nvbios_rd16(bios, data + 4) * 1000;
		info->vco2.max_freq = nvbios_rd16(bios, data + 6) * 1000;
		info->vco1.min_inputfreq = nvbios_rd16(bios, data + 8) * 1000;
		info->vco2.min_inputfreq = nvbios_rd16(bios, data + 10) * 1000;
		info->vco1.max_inputfreq = nvbios_rd16(bios, data + 12) * 1000;
		info->vco2.max_inputfreq = nvbios_rd16(bios, data + 14) * 1000;
		info->vco1.min_n = nvbios_rd08(bios, data + 16);
		info->vco1.max_n = nvbios_rd08(bios, data + 17);
		info->vco1.min_m = nvbios_rd08(bios, data + 18);
		info->vco1.max_m = nvbios_rd08(bios, data + 19);
		info->vco2.min_n = nvbios_rd08(bios, data + 20);
		info->vco2.max_n = nvbios_rd08(bios, data + 21);
		info->vco2.min_m = nvbios_rd08(bios, data + 22);
		info->vco2.max_m = nvbios_rd08(bios, data + 23);
		info->max_p_usable = info->max_p = nvbios_rd08(bios, data + 25);
		info->bias_p = nvbios_rd08(bios, data + 27);
		info->refclk = nvbios_rd32(bios, data + 28);
		break;
	case 0x40:
		info->refclk = nvbios_rd16(bios, data + 9) * 1000;
		data = nvbios_rd16(bios, data + 1);

		info->vco1.min_freq = nvbios_rd16(bios, data + 0) * 1000;
		info->vco1.max_freq = nvbios_rd16(bios, data + 2) * 1000;
		info->vco1.min_inputfreq = nvbios_rd16(bios, data + 4) * 1000;
		info->vco1.max_inputfreq = nvbios_rd16(bios, data + 6) * 1000;
		info->vco1.min_m = nvbios_rd08(bios, data + 8);
		info->vco1.max_m = nvbios_rd08(bios, data + 9);
		info->vco1.min_n = nvbios_rd08(bios, data + 10);
		info->vco1.max_n = nvbios_rd08(bios, data + 11);
		info->min_p = nvbios_rd08(bios, data + 12);
		info->max_p = nvbios_rd08(bios, data + 13);
		break;
	case 0x50:
		info->refclk = nvbios_rd16(bios, data + 1) * 1000;
		/* info->refclk_alt = nvbios_rd16(bios, data + 3) * 1000; */
		info->vco1.min_freq = nvbios_rd16(bios, data + 5) * 1000;
		info->vco1.max_freq = nvbios_rd16(bios, data + 7) * 1000;
		info->vco1.min_inputfreq = nvbios_rd16(bios, data + 9) * 1000;
		info->vco1.max_inputfreq = nvbios_rd16(bios, data + 11) * 1000;
		info->vco1.min_m = nvbios_rd08(bios, data + 13);
		info->vco1.max_m = nvbios_rd08(bios, data + 14);
		info->vco1.min_n = nvbios_rd08(bios, data + 15);
		info->vco1.max_n = nvbios_rd08(bios, data + 16);
		info->min_p = nvbios_rd08(bios, data + 17);
		info->max_p = nvbios_rd08(bios, data + 18);
		break;
	default:
		nvkm_error(subdev, "unknown pll limits version 0x%02x\n", ver);
		return -EINVAL;
	}

	if (!info->refclk) {
		info->refclk = device->crystal;
		if (bios->version.chip == 0x51) {
			u32 sel_clk = nvkm_rd32(device, 0x680524);
			if ((info->reg == 0x680508 && sel_clk & 0x20) ||
			    (info->reg == 0x680520 && sel_clk & 0x80)) {
				if (nvkm_rdvgac(device, 0, 0x27) < 0xa3)
					info->refclk = 200000;
				else
					info->refclk = 25000;
			}
		}
	}

	/*
	 * By now any valid limit table ought to have set a max frequency for
	 * vco1, so if it's zero it's either a pre limit table bios, or one
	 * with an empty limit table (seen on nv18)
	 */
	if (!info->vco1.max_freq) {
		info->vco1.max_freq = nvbios_rd32(bios, bios->bmp_offset + 67);
		info->vco1.min_freq = nvbios_rd32(bios, bios->bmp_offset + 71);
		if (bmp_version(bios) < 0x0506) {
			info->vco1.max_freq = 256000;
			info->vco1.min_freq = 128000;
		}

		info->vco1.min_inputfreq = 0;
		info->vco1.max_inputfreq = INT_MAX;
		info->vco1.min_n = 0x1;
		info->vco1.max_n = 0xff;
		info->vco1.min_m = 0x1;

		if (device->crystal == 13500) {
			/* nv05 does this, nv11 doesn't, nv10 unknown */
			if (bios->version.chip < 0x11)
				info->vco1.min_m = 0x7;
			info->vco1.max_m = 0xd;
		} else {
			if (bios->version.chip < 0x11)
				info->vco1.min_m = 0x8;
			info->vco1.max_m = 0xe;
		}

		if (bios->version.chip <  0x17 ||
		    bios->version.chip == 0x1a ||
		    bios->version.chip == 0x20)
			info->max_p = 4;
		else
			info->max_p = 5;
		info->max_p_usable = info->max_p;
	}

	return 0;
}

