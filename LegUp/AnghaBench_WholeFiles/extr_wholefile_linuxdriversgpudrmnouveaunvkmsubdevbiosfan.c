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
struct nvbios_therm_fan {int pwm_freq; void* max_duty; void* min_duty; int /*<<< orphan*/  fan_mode; int /*<<< orphan*/  type; } ;
struct bit_entry {int version; int length; int offset; } ;

/* Variables and functions */
 int /*<<< orphan*/  NVBIOS_THERM_FAN_LINEAR ; 
 int /*<<< orphan*/  NVBIOS_THERM_FAN_PWM ; 
 int /*<<< orphan*/  NVBIOS_THERM_FAN_TOGGLE ; 
 int /*<<< orphan*/  NVBIOS_THERM_FAN_UNK ; 
 int /*<<< orphan*/  bit_entry (struct nvkm_bios*,char,struct bit_entry*) ; 
 void* nvbios_rd08 (struct nvkm_bios*,int) ; 
 int nvbios_rd32 (struct nvkm_bios*,int) ; 

__attribute__((used)) static u32
nvbios_fan_table(struct nvkm_bios *bios, u8 *ver, u8 *hdr, u8 *cnt, u8 *len)
{
	struct bit_entry bit_P;
	u32 fan = 0;

	if (!bit_entry(bios, 'P', &bit_P)) {
		if (bit_P.version == 2 && bit_P.length >= 0x5c)
			fan = nvbios_rd32(bios, bit_P.offset + 0x58);

		if (fan) {
			*ver = nvbios_rd08(bios, fan + 0);
			switch (*ver) {
			case 0x10:
				*hdr = nvbios_rd08(bios, fan + 1);
				*len = nvbios_rd08(bios, fan + 2);
				*cnt = nvbios_rd08(bios, fan + 3);
				return fan;
			default:
				break;
			}
		}
	}

	return 0;
}

__attribute__((used)) static u32
nvbios_fan_entry(struct nvkm_bios *bios, int idx, u8 *ver, u8 *hdr,
		 u8 *cnt, u8 *len)
{
	u32 data = nvbios_fan_table(bios, ver, hdr, cnt, len);
	if (data && idx < *cnt)
		return data + *hdr + (idx * (*len));
	return 0;
}

u32
nvbios_fan_parse(struct nvkm_bios *bios, struct nvbios_therm_fan *fan)
{
	u8 ver, hdr, cnt, len;

	u32 data = nvbios_fan_entry(bios, 0, &ver, &hdr, &cnt, &len);
	if (data) {
		u8 type = nvbios_rd08(bios, data + 0x00);
		switch (type) {
		case 0:
			fan->type = NVBIOS_THERM_FAN_TOGGLE;
			break;
		case 1:
		case 2:
			/* TODO: Understand the difference between the two! */
			fan->type = NVBIOS_THERM_FAN_PWM;
			break;
		default:
			fan->type = NVBIOS_THERM_FAN_UNK;
		}

		fan->fan_mode = NVBIOS_THERM_FAN_LINEAR;
		fan->min_duty = nvbios_rd08(bios, data + 0x02);
		fan->max_duty = nvbios_rd08(bios, data + 0x03);

		fan->pwm_freq = nvbios_rd32(bios, data + 0x0b) & 0xffffff;
	}

	return data;
}

