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
struct net_device {int dummy; } ;

/* Variables and functions */
 struct net_device* __alloc_ei_netdev (int /*<<< orphan*/ ) ; 
 struct net_device* __alloc_eip_netdev (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline struct net_device *alloc_ei_netdev(void)
{
	return __alloc_ei_netdev(0);
}

__attribute__((used)) static inline struct net_device *alloc_eip_netdev(void)
{
	return __alloc_eip_netdev(0);
}

