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
struct acpi_gtdt_watchdog {int timer_flags; } ;
struct acpi_gtdt_header {scalar_t__ type; int /*<<< orphan*/  length; } ;
struct TYPE_2__ {void* gtdt_end; } ;

/* Variables and functions */
 scalar_t__ ACPI_GTDT_TYPE_TIMER_BLOCK ; 
 scalar_t__ ACPI_GTDT_TYPE_WATCHDOG ; 
 int ACPI_GTDT_WATCHDOG_SECURE ; 
 TYPE_1__ acpi_gtdt_desc ; 

__attribute__((used)) static inline void *next_platform_timer(void *platform_timer)
{
	struct acpi_gtdt_header *gh = platform_timer;

	platform_timer += gh->length;
	if (platform_timer < acpi_gtdt_desc.gtdt_end)
		return platform_timer;

	return NULL;
}

__attribute__((used)) static inline bool is_timer_block(void *platform_timer)
{
	struct acpi_gtdt_header *gh = platform_timer;

	return gh->type == ACPI_GTDT_TYPE_TIMER_BLOCK;
}

__attribute__((used)) static inline bool is_non_secure_watchdog(void *platform_timer)
{
	struct acpi_gtdt_header *gh = platform_timer;
	struct acpi_gtdt_watchdog *wd = platform_timer;

	if (gh->type != ACPI_GTDT_TYPE_WATCHDOG)
		return false;

	return !(wd->timer_flags & ACPI_GTDT_WATCHDOG_SECURE);
}

