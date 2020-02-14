#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int u32 ;
struct TYPE_4__ {TYPE_1__* device; } ;
struct nvkm_bios {TYPE_2__ subdev; int /*<<< orphan*/ * data; } ;
struct device {int dummy; } ;
struct TYPE_3__ {struct device* dev; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  ENODEV ; 
 void* ERR_PTR (int /*<<< orphan*/ ) ; 
 scalar_t__ nvbios_extend (struct nvkm_bios*,int) ; 

__attribute__((used)) static inline bool
nouveau_acpi_rom_supported(struct device *dev)
{
	return false;
}

__attribute__((used)) static inline int
nouveau_acpi_get_bios_chunk(uint8_t *bios, int offset, int len)
{
	return -EINVAL;
}

__attribute__((used)) static u32
acpi_read_fast(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
	u32 limit = (offset + length + 0xfff) & ~0xfff;
	u32 start = offset & ~0x00000fff;
	u32 fetch = limit - start;

	if (nvbios_extend(bios, limit) >= 0) {
		int ret = nouveau_acpi_get_bios_chunk(bios->data, start, fetch);
		if (ret == fetch)
			return fetch;
	}

	return 0;
}

__attribute__((used)) static u32
acpi_read_slow(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
	u32 limit = (offset + length + 0xfff) & ~0xfff;
	u32 start = offset & ~0xfff;
	u32 fetch = 0;

	if (nvbios_extend(bios, limit) >= 0) {
		while (start + fetch < limit) {
			int ret = nouveau_acpi_get_bios_chunk(bios->data,
							      start + fetch,
							      0x1000);
			if (ret != 0x1000)
				break;
			fetch += 0x1000;
		}
	}

	return fetch;
}

__attribute__((used)) static void *
acpi_init(struct nvkm_bios *bios, const char *name)
{
	if (!nouveau_acpi_rom_supported(bios->subdev.device->dev))
		return ERR_PTR(-ENODEV);
	return NULL;
}

