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
struct ti_bandgap {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline
int ti_thermal_expose_sensor(struct ti_bandgap *bgp, int id, char *domain)
{
	return 0;
}

__attribute__((used)) static inline
int ti_thermal_remove_sensor(struct ti_bandgap *bgp, int id)
{
	return 0;
}

__attribute__((used)) static inline
int ti_thermal_report_sensor_temperature(struct ti_bandgap *bgp, int id)
{
	return 0;
}

__attribute__((used)) static inline
int ti_thermal_register_cpu_cooling(struct ti_bandgap *bgp, int id)
{
	return 0;
}

__attribute__((used)) static inline
int ti_thermal_unregister_cpu_cooling(struct ti_bandgap *bgp, int id)
{
	return 0;
}

