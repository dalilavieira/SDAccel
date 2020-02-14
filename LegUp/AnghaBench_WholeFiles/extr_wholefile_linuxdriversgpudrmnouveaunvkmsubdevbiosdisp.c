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
typedef  int u16 ;
struct nvkm_bios {int dummy; } ;
struct nvbios_outp {int type; int mask; int* script; } ;
struct nvbios_ocfg {int proto; int flags; int* clkcmp; } ;
struct nvbios_disp {int data; } ;
struct bit_entry {int version; int offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,unsigned char,struct bit_entry*) ; 
 void* nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd16 (struct nvkm_bios*,int) ; 
 int nvbios_rd32 (struct nvkm_bios*,int) ; 

u16
nvbios_disp_table(struct nvkm_bios *bios,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len, u8 *sub)
{
	struct bit_entry U;

	if (!bit_entry(bios, 'U', &U)) {
		if (U.version == 1) {
			u16 data = nvbios_rd16(bios, U.offset);
			if (data) {
				*ver = nvbios_rd08(bios, data + 0x00);
				switch (*ver) {
				case 0x20:
				case 0x21:
				case 0x22:
					*hdr = nvbios_rd08(bios, data + 0x01);
					*len = nvbios_rd08(bios, data + 0x02);
					*cnt = nvbios_rd08(bios, data + 0x03);
					*sub = nvbios_rd08(bios, data + 0x04);
					return data;
				default:
					break;
				}
			}
		}
	}

	return 0x0000;
}

u16
nvbios_disp_entry(struct nvkm_bios *bios, u8 idx, u8 *ver, u8 *len, u8 *sub)
{
	u8  hdr, cnt;
	u16 data = nvbios_disp_table(bios, ver, &hdr, &cnt, len, sub);
	if (data && idx < cnt)
		return data + hdr + (idx * *len);
	*ver = 0x00;
	return 0x0000;
}

u16
nvbios_disp_parse(struct nvkm_bios *bios, u8 idx, u8 *ver, u8 *len, u8 *sub,
		  struct nvbios_disp *info)
{
	u16 data = nvbios_disp_entry(bios, idx, ver, len, sub);
	if (data && *len >= 2) {
		info->data = nvbios_rd16(bios, data + 0);
		return data;
	}
	return 0x0000;
}

u16
nvbios_outp_entry(struct nvkm_bios *bios, u8 idx,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	struct nvbios_disp info;
	u16 data = nvbios_disp_parse(bios, idx, ver, len, hdr, &info);
	if (data) {
		*cnt = nvbios_rd08(bios, info.data + 0x05);
		*len = 0x06;
		data = info.data;
	}
	return data;
}

u16
nvbios_outp_parse(struct nvkm_bios *bios, u8 idx,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_outp *info)
{
	u16 data = nvbios_outp_entry(bios, idx, ver, hdr, cnt, len);
	if (data && *hdr >= 0x0a) {
		info->type      = nvbios_rd16(bios, data + 0x00);
		info->mask      = nvbios_rd32(bios, data + 0x02);
		if (*ver <= 0x20) /* match any link */
			info->mask |= 0x00c0;
		info->script[0] = nvbios_rd16(bios, data + 0x06);
		info->script[1] = nvbios_rd16(bios, data + 0x08);
		info->script[2] = 0x0000;
		if (*hdr >= 0x0c)
			info->script[2] = nvbios_rd16(bios, data + 0x0a);
		return data;
	}
	return 0x0000;
}

u16
nvbios_outp_match(struct nvkm_bios *bios, u16 type, u16 mask,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_outp *info)
{
	u16 data, idx = 0;
	while ((data = nvbios_outp_parse(bios, idx++, ver, hdr, cnt, len, info)) || *ver) {
		if (data && info->type == type) {
			if ((info->mask & mask) == mask)
				break;
		}
	}
	return data;
}

u16
nvbios_ocfg_entry(struct nvkm_bios *bios, u16 outp, u8 idx,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	if (idx < *cnt)
		return outp + *hdr + (idx * *len);
	return 0x0000;
}

u16
nvbios_ocfg_parse(struct nvkm_bios *bios, u16 outp, u8 idx,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_ocfg *info)
{
	u16 data = nvbios_ocfg_entry(bios, outp, idx, ver, hdr, cnt, len);
	if (data) {
		info->proto     = nvbios_rd08(bios, data + 0x00);
		info->flags     = nvbios_rd16(bios, data + 0x01);
		info->clkcmp[0] = nvbios_rd16(bios, data + 0x02);
		info->clkcmp[1] = nvbios_rd16(bios, data + 0x04);
	}
	return data;
}

u16
nvbios_ocfg_match(struct nvkm_bios *bios, u16 outp, u8 proto, u8 flags,
		  u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_ocfg *info)
{
	u16 data, idx = 0;
	while ((data = nvbios_ocfg_parse(bios, outp, idx++, ver, hdr, cnt, len, info))) {
		if ((info->proto == proto || info->proto == 0xff) &&
		    (info->flags == flags))
			break;
	}
	return data;
}

u16
nvbios_oclk_match(struct nvkm_bios *bios, u16 cmp, u32 khz)
{
	while (cmp) {
		if (khz / 10 >= nvbios_rd16(bios, cmp + 0x00))
			return  nvbios_rd16(bios, cmp + 0x02);
		cmp += 0x04;
	}
	return 0x0000;
}

