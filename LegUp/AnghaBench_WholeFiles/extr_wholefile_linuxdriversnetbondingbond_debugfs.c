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
struct bonding {int dummy; } ;

/* Variables and functions */

void bond_debug_register(struct bonding *bond)
{
}

void bond_debug_unregister(struct bonding *bond)
{
}

void bond_debug_reregister(struct bonding *bond)
{
}

void bond_create_debugfs(void)
{
}

void bond_destroy_debugfs(void)
{
}

