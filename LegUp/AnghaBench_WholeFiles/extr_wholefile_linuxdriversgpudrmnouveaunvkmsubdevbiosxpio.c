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
typedef  int u16 ;
struct nvkm_bios {int dummy; } ;
struct nvbios_xpio {void* flags; void* addr; void* type; } ;

/* Variables and functions */
 int dcb_gpio_table (struct nvkm_bios*,int*,int*,int*,int*) ; 
 void* nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd16 (struct nvkm_bios*,int) ; 

__attribute__((used)) static u16
dcb_xpiod_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	u16 data = dcb_gpio_table(bios, ver, hdr, cnt, len);
	if (data && *ver >= 0x40 && *hdr >= 0x06) {
		u16 xpio = nvbios_rd16(bios, data + 0x04);
		if (xpio) {
			*ver = nvbios_rd08(bios, data + 0x00);
			*hdr = nvbios_rd08(bios, data + 0x01);
			*cnt = nvbios_rd08(bios, data + 0x02);
			*len = nvbios_rd08(bios, data + 0x03);
			return xpio;
		}
	}
	return 0x0000;
}

u16
dcb_xpio_table(struct nvkm_bios *bios, u8 idx,
	       u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	u16 data = dcb_xpiod_table(bios, ver, hdr, cnt, len);
	if (data && idx < *cnt) {
		u16 xpio = nvbios_rd16(bios, data + *hdr + (idx * *len));
		if (xpio) {
			*ver = nvbios_rd08(bios, data + 0x00);
			*hdr = nvbios_rd08(bios, data + 0x01);
			*cnt = nvbios_rd08(bios, data + 0x02);
			*len = nvbios_rd08(bios, data + 0x03);
			return xpio;
		}
	}
	return 0x0000;
}

u16
dcb_xpio_parse(struct nvkm_bios *bios, u8 idx,
	       u8 *ver, u8 *hdr, u8 *cnt, u8 *len, struct nvbios_xpio *info)
{
	u16 data = dcb_xpio_table(bios, idx, ver, hdr, cnt, len);
	if (data && *len >= 6) {
		info->type = nvbios_rd08(bios, data + 0x04);
		info->addr = nvbios_rd08(bios, data + 0x05);
		info->flags = nvbios_rd08(bios, data + 0x06);
	}
	return 0x0000;
}

