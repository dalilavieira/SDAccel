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
struct nvbios_pmuR {int type; int data; int init_addr_pmu; int args_addr_pmu; int boot_addr; int boot_addr_pmu; int boot_size; int code_addr; int code_addr_pmu; int code_size; int data_addr; int data_addr_pmu; int data_size; } ;
struct nvbios_pmuE {int type; int data; int init_addr_pmu; int args_addr_pmu; int boot_addr; int boot_addr_pmu; int boot_size; int code_addr; int code_addr_pmu; int code_size; int data_addr; int data_addr_pmu; int data_size; } ;
struct bit_entry {int version; int length; int offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int /*<<< orphan*/  memset (struct nvbios_pmuR*,int,int) ; 
 void* nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd32 (struct nvkm_bios*,int) ; 

u32
nvbios_pmuTe(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	struct bit_entry bit_p;
	u32 data = 0;

	if (!bit_entry(bios, 'p', &bit_p)) {
		if (bit_p.version == 2 && bit_p.length >= 4)
			data = nvbios_rd32(bios, bit_p.offset + 0x00);
		if (data) {
			*ver = nvbios_rd08(bios, data + 0x00); /* maybe? */
			*hdr = nvbios_rd08(bios, data + 0x01);
			*len = nvbios_rd08(bios, data + 0x02);
			*cnt = nvbios_rd08(bios, data + 0x03);
		}
	}

	return data;
}

u32
nvbios_pmuEe(struct nvkm_bios *bios, int idx, u8 *ver, u8 *hdr)
{
	u8  cnt, len;
	u32 data = nvbios_pmuTe(bios, ver, hdr, &cnt, &len);
	if (data && idx < cnt) {
		data = data + *hdr + (idx * len);
		*hdr = len;
		return data;
	}
	return 0;
}

u32
nvbios_pmuEp(struct nvkm_bios *bios, int idx, u8 *ver, u8 *hdr,
	     struct nvbios_pmuE *info)
{
	u32 data = nvbios_pmuEe(bios, idx, ver, hdr);
	memset(info, 0x00, sizeof(*info));
	switch (!!data * *ver) {
	default:
		info->type = nvbios_rd08(bios, data + 0x00);
		info->data = nvbios_rd32(bios, data + 0x02);
		break;
	}
	return data;
}

bool
nvbios_pmuRm(struct nvkm_bios *bios, u8 type, struct nvbios_pmuR *info)
{
	struct nvbios_pmuE pmuE;
	u8  ver, hdr, idx = 0;
	u32 data;
	memset(info, 0x00, sizeof(*info));
	while ((data = nvbios_pmuEp(bios, idx++, &ver, &hdr, &pmuE))) {
		if (pmuE.type == type && (data = pmuE.data)) {
			info->init_addr_pmu = nvbios_rd32(bios, data + 0x08);
			info->args_addr_pmu = nvbios_rd32(bios, data + 0x0c);
			info->boot_addr     = data + 0x30;
			info->boot_addr_pmu = nvbios_rd32(bios, data + 0x10) +
					      nvbios_rd32(bios, data + 0x18);
			info->boot_size     = nvbios_rd32(bios, data + 0x1c) -
					      nvbios_rd32(bios, data + 0x18);
			info->code_addr     = info->boot_addr + info->boot_size;
			info->code_addr_pmu = info->boot_addr_pmu +
					      info->boot_size;
			info->code_size     = nvbios_rd32(bios, data + 0x20);
			info->data_addr     = data + 0x30 +
					      nvbios_rd32(bios, data + 0x24);
			info->data_addr_pmu = nvbios_rd32(bios, data + 0x28);
			info->data_size     = nvbios_rd32(bios, data + 0x2c);
			return true;
		}
	}
	return false;
}

