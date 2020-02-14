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
struct nvbios_power_budget_entry {void* max_w; void* avg_w; void* min_w; } ;
struct nvbios_power_budget {int cap_entry; int offset; int ver; int hlen; int elen; int ecount; } ;
struct bit_entry {int version; int length; int offset; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 scalar_t__ bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 void* nvbios_rd32 (struct nvkm_bios*,int) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*) ; 

__attribute__((used)) static u32
nvbios_power_budget_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt,
			  u8 *len)
{
	struct bit_entry bit_P;
	u32 power_budget;

	if (bit_entry(bios, 'P', &bit_P) || bit_P.version != 2 ||
	    bit_P.length < 0x30)
		return 0;

	power_budget = nvbios_rd32(bios, bit_P.offset + 0x2c);
	if (!power_budget)
		return 0;

	*ver = nvbios_rd08(bios, power_budget);
	switch (*ver) {
	case 0x20:
	case 0x30:
		*hdr = nvbios_rd08(bios, power_budget + 0x1);
		*len = nvbios_rd08(bios, power_budget + 0x2);
		*cnt = nvbios_rd08(bios, power_budget + 0x3);
		return power_budget;
	default:
		break;
	}

	return 0;
}

int
nvbios_power_budget_header(struct nvkm_bios *bios,
                           struct nvbios_power_budget *budget)
{
	struct nvkm_subdev *subdev = &bios->subdev;
	u8 ver, hdr, cnt, len, cap_entry;
	u32 header;

	if (!bios || !budget)
		return -EINVAL;

	header = nvbios_power_budget_table(bios, &ver, &hdr, &cnt, &len);
	if (!header || !cnt)
		return -ENODEV;

	switch (ver) {
	case 0x20:
		cap_entry = nvbios_rd08(bios, header + 0x9);
		break;
	case 0x30:
		cap_entry = nvbios_rd08(bios, header + 0xa);
		break;
	default:
		cap_entry = 0xff;
	}

	if (cap_entry >= cnt && cap_entry != 0xff) {
		nvkm_warn(subdev,
		          "invalid cap_entry in power budget table found\n");
		budget->cap_entry = 0xff;
		return -EINVAL;
	}

	budget->offset = header;
	budget->ver = ver;
	budget->hlen = hdr;
	budget->elen = len;
	budget->ecount = cnt;

	budget->cap_entry = cap_entry;

	return 0;
}

int
nvbios_power_budget_entry(struct nvkm_bios *bios,
                          struct nvbios_power_budget *budget,
                          u8 idx, struct nvbios_power_budget_entry *entry)
{
	u32 entry_offset;

	if (!bios || !budget || !budget->offset || idx >= budget->ecount
		|| !entry)
		return -EINVAL;

	entry_offset = budget->offset + budget->hlen + idx * budget->elen;

	if (budget->ver >= 0x20) {
		entry->min_w = nvbios_rd32(bios, entry_offset + 0x2);
		entry->avg_w = nvbios_rd32(bios, entry_offset + 0x6);
		entry->max_w = nvbios_rd32(bios, entry_offset + 0xa);
	} else {
		entry->min_w = 0;
		entry->max_w = nvbios_rd32(bios, entry_offset + 0x2);
		entry->avg_w = entry->max_w;
	}

	return 0;
}

