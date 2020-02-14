#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  void* uint8_t ;
typedef  void* uint32_t ;
typedef  void* uint16_t ;
struct map_info {scalar_t__ virt; } ;
typedef  scalar_t__ ssize_t ;
struct TYPE_8__ {void** x; } ;
typedef  TYPE_1__ map_word ;

/* Variables and functions */
 unsigned long* CSR_ROMWRITEREG ; 
 scalar_t__ machine_is_netwinder () ; 
 int /*<<< orphan*/  memcpy (void*,void*,scalar_t__) ; 
 int /*<<< orphan*/  nw_en_write () ; 

__attribute__((used)) static map_word dc21285_read8(struct map_info *map, unsigned long ofs)
{
	map_word val;
	val.x[0] = *(uint8_t*)(map->virt + ofs);
	return val;
}

__attribute__((used)) static map_word dc21285_read16(struct map_info *map, unsigned long ofs)
{
	map_word val;
	val.x[0] = *(uint16_t*)(map->virt + ofs);
	return val;
}

__attribute__((used)) static map_word dc21285_read32(struct map_info *map, unsigned long ofs)
{
	map_word val;
	val.x[0] = *(uint32_t*)(map->virt + ofs);
	return val;
}

__attribute__((used)) static void dc21285_copy_from(struct map_info *map, void *to, unsigned long from, ssize_t len)
{
	memcpy(to, (void*)(map->virt + from), len);
}

__attribute__((used)) static void dc21285_write8(struct map_info *map, const map_word d, unsigned long adr)
{
	if (machine_is_netwinder())
		nw_en_write();
	*CSR_ROMWRITEREG = adr & 3;
	adr &= ~3;
	*(uint8_t*)(map->virt + adr) = d.x[0];
}

__attribute__((used)) static void dc21285_write16(struct map_info *map, const map_word d, unsigned long adr)
{
	if (machine_is_netwinder())
		nw_en_write();
	*CSR_ROMWRITEREG = adr & 3;
	adr &= ~3;
	*(uint16_t*)(map->virt + adr) = d.x[0];
}

__attribute__((used)) static void dc21285_write32(struct map_info *map, const map_word d, unsigned long adr)
{
	if (machine_is_netwinder())
		nw_en_write();
	*(uint32_t*)(map->virt + adr) = d.x[0];
}

__attribute__((used)) static void dc21285_copy_to_32(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
	while (len > 0) {
		map_word d;
		d.x[0] = *((uint32_t*)from);
		dc21285_write32(map, d, to);
		from += 4;
		to += 4;
		len -= 4;
	}
}

__attribute__((used)) static void dc21285_copy_to_16(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
	while (len > 0) {
		map_word d;
		d.x[0] = *((uint16_t*)from);
		dc21285_write16(map, d, to);
		from += 2;
		to += 2;
		len -= 2;
	}
}

__attribute__((used)) static void dc21285_copy_to_8(struct map_info *map, unsigned long to, const void *from, ssize_t len)
{
	map_word d;
	d.x[0] = *((uint8_t*)from);
	dc21285_write8(map, d, to);
	from++;
	to++;
	len--;
}

