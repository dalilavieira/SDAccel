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
struct nvbios_vpstate_header {int offset; int version; int hlen; int elen; int slen; int scount; int ecount; int boost_id; int tdp_id; void* base_id; } ;
struct nvbios_vpstate_entry {int /*<<< orphan*/  clock_mhz; void* pstate; } ;
struct bit_entry {int version; int length; scalar_t__ offset; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 void* nvbios_rd08 (struct nvkm_bios*,int) ; 
 int /*<<< orphan*/  nvbios_rd16 (struct nvkm_bios*,int) ; 
 int nvbios_rd32 (struct nvkm_bios*,scalar_t__) ; 

__attribute__((used)) static u32
nvbios_vpstate_offset(struct nvkm_bios *b)
{
	struct bit_entry bit_P;

	if (!bit_entry(b, 'P', &bit_P)) {
		if (bit_P.version == 2 && bit_P.length >= 0x3c)
			return nvbios_rd32(b, bit_P.offset + 0x38);
	}

	return 0x0000;
}

int
nvbios_vpstate_parse(struct nvkm_bios *b, struct nvbios_vpstate_header *h)
{
	if (!h)
		return -EINVAL;

	h->offset = nvbios_vpstate_offset(b);
	if (!h->offset)
		return -ENODEV;

	h->version = nvbios_rd08(b, h->offset);
	switch (h->version) {
	case 0x10:
		h->hlen     = nvbios_rd08(b, h->offset + 0x1);
		h->elen     = nvbios_rd08(b, h->offset + 0x2);
		h->slen     = nvbios_rd08(b, h->offset + 0x3);
		h->scount   = nvbios_rd08(b, h->offset + 0x4);
		h->ecount   = nvbios_rd08(b, h->offset + 0x5);

		h->base_id  = nvbios_rd08(b, h->offset + 0x0f);
		if (h->hlen > 0x10)
			h->boost_id = nvbios_rd08(b, h->offset + 0x10);
		else
			h->boost_id = 0xff;
		if (h->hlen > 0x11)
			h->tdp_id = nvbios_rd08(b, h->offset + 0x11);
		else
			h->tdp_id = 0xff;
		return 0;
	default:
		return -EINVAL;
	}
}

int
nvbios_vpstate_entry(struct nvkm_bios *b, struct nvbios_vpstate_header *h,
		     u8 idx, struct nvbios_vpstate_entry *e)
{
	u32 offset;

	if (!e || !h || idx > h->ecount)
		return -EINVAL;

	offset = h->offset + h->hlen + idx * (h->elen + (h->slen * h->scount));
	e->pstate    = nvbios_rd08(b, offset);
	e->clock_mhz = nvbios_rd16(b, offset + 0x5);
	return 0;
}

