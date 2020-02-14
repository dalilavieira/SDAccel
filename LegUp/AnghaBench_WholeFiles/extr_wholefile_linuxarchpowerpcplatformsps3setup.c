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
union ps3_firmware_version {scalar_t__ raw; void* rev; void* minor; void* major; scalar_t__ pad; } ;
typedef  int /*<<< orphan*/  u64 ;
typedef  void* u16 ;

/* Variables and functions */
 int /*<<< orphan*/  lv1_pause (int /*<<< orphan*/ ) ; 
 union ps3_firmware_version ps3_firmware_version ; 

__attribute__((used)) static inline void ps3_smp_cleanup_cpu(int cpu) { }

__attribute__((used)) static inline void ps3_spu_set_platform (void) {}

__attribute__((used)) static inline int ps3_repository_write_highmem_region_count(
	unsigned int region_count) {return 0;}

__attribute__((used)) static inline int ps3_repository_write_highmem_base(unsigned int region_index,
	u64 highmem_base) {return 0;}

__attribute__((used)) static inline int ps3_repository_write_highmem_size(unsigned int region_index,
	u64 highmem_size) {return 0;}

__attribute__((used)) static inline int ps3_repository_write_highmem_info(unsigned int region_index,
	u64 highmem_base, u64 highmem_size) {return 0;}

__attribute__((used)) static inline int ps3_repository_delete_highmem_info(unsigned int region_index)
	{return 0;}

void ps3_get_firmware_version(union ps3_firmware_version *v)
{
	*v = ps3_firmware_version;
}

int ps3_compare_firmware_version(u16 major, u16 minor, u16 rev)
{
	union ps3_firmware_version x;

	x.pad = 0;
	x.major = major;
	x.minor = minor;
	x.rev = rev;

	return (ps3_firmware_version.raw > x.raw) -
	       (ps3_firmware_version.raw < x.raw);
}

__attribute__((used)) static void ps3_power_save(void)
{
	/*
	 * lv1_pause() puts the PPE thread into inactive state until an
	 * irq on an unmasked plug exists. MSR[EE] has no effect.
	 * flags: 0 = wake on DEC interrupt, 1 = ignore DEC interrupt.
	 */

	lv1_pause(0);
}

