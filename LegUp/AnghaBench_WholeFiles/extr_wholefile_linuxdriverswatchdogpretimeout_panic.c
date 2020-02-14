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
struct watchdog_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int /*<<< orphan*/  panic (char*) ; 

__attribute__((used)) static inline int watchdog_register_pretimeout(struct watchdog_device *wdd)
{
	return 0;
}

__attribute__((used)) static inline void watchdog_unregister_pretimeout(struct watchdog_device *wdd)
{
}

__attribute__((used)) static inline int watchdog_pretimeout_available_governors_get(char *buf)
{
	return -EINVAL;
}

__attribute__((used)) static inline int watchdog_pretimeout_governor_get(struct watchdog_device *wdd,
						   char *buf)
{
	return -EINVAL;
}

__attribute__((used)) static inline int watchdog_pretimeout_governor_set(struct watchdog_device *wdd,
						   const char *buf)
{
	return -EINVAL;
}

__attribute__((used)) static void pretimeout_panic(struct watchdog_device *wdd)
{
	panic("watchdog pretimeout event\n");
}

