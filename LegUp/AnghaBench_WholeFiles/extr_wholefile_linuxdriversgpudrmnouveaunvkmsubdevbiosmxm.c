#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct nvkm_subdev {int dummy; } ;
struct TYPE_2__ {int chip; } ;
struct nvkm_bios {struct nvkm_subdev subdev; TYPE_1__ version; } ;
struct bit_entry {int version; int length; int offset; } ;

/* Variables and functions */
 scalar_t__ bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 int* g84_sor_map ; 
 int* g92_sor_map ; 
 int* g94_sor_map ; 
 int* g98_sor_map ; 
 int nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd16 (struct nvkm_bios*,int) ; 
 int /*<<< orphan*/  nvkm_debug (struct nvkm_subdev*,char*) ; 
 int /*<<< orphan*/  nvkm_warn (struct nvkm_subdev*,char*,...) ; 

u16
mxm_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr)
{
	struct nvkm_subdev *subdev = &bios->subdev;
	struct bit_entry x;

	if (bit_entry(bios, 'x', &x)) {
		nvkm_debug(subdev, "BIT 'x' table not present\n");
		return 0x0000;
	}

	*ver = x.version;
	*hdr = x.length;
	if (*ver != 1 || *hdr < 3) {
		nvkm_warn(subdev, "BIT 'x' table %d/%d unknown\n", *ver, *hdr);
		return 0x0000;
	}

	return x.offset;
}

u8
mxm_sor_map(struct nvkm_bios *bios, u8 conn)
{
	struct nvkm_subdev *subdev = &bios->subdev;
	u8  ver, hdr;
	u16 mxm = mxm_table(bios, &ver, &hdr);
	if (mxm && hdr >= 6) {
		u16 map = nvbios_rd16(bios, mxm + 4);
		if (map) {
			ver = nvbios_rd08(bios, map);
			if (ver == 0x10 || ver == 0x11) {
				if (conn < nvbios_rd08(bios, map + 3)) {
					map += nvbios_rd08(bios, map + 1);
					map += conn;
					return nvbios_rd08(bios, map);
				}

				return 0x00;
			}

			nvkm_warn(subdev, "unknown sor map v%02x\n", ver);
		}
	}

	if (bios->version.chip == 0x84 || bios->version.chip == 0x86)
		return g84_sor_map[conn];
	if (bios->version.chip == 0x92)
		return g92_sor_map[conn];
	if (bios->version.chip == 0x94 || bios->version.chip == 0x96)
		return g94_sor_map[conn];
	if (bios->version.chip == 0x98)
		return g98_sor_map[conn];

	nvkm_warn(subdev, "missing sor map\n");
	return 0x00;
}

u8
mxm_ddc_map(struct nvkm_bios *bios, u8 port)
{
	struct nvkm_subdev *subdev = &bios->subdev;
	u8  ver, hdr;
	u16 mxm = mxm_table(bios, &ver, &hdr);
	if (mxm && hdr >= 8) {
		u16 map = nvbios_rd16(bios, mxm + 6);
		if (map) {
			ver = nvbios_rd08(bios, map);
			if (ver == 0x10) {
				if (port < nvbios_rd08(bios, map + 3)) {
					map += nvbios_rd08(bios, map + 1);
					map += port;
					return nvbios_rd08(bios, map);
				}

				return 0x00;
			}

			nvkm_warn(subdev, "unknown ddc map v%02x\n", ver);
		}
	}

	/* v2.x: directly write port as dcb i2cidx */
	return (port << 4) | port;
}

