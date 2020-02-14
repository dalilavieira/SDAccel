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
struct net_device {int dummy; } ;
typedef  enum lowpan_lltypes { ____Placeholder_lowpan_lltypes } lowpan_lltypes ;
struct TYPE_2__ {int lltype; } ;

/* Variables and functions */
 TYPE_1__* lowpan_dev (struct net_device const*) ; 

__attribute__((used)) static inline bool lowpan_is_ll(const struct net_device *dev,
				enum lowpan_lltypes lltype)
{
	return lowpan_dev(dev)->lltype == lltype;
}

__attribute__((used)) static inline int lowpan_dev_debugfs_init(struct net_device *dev)
{
	return 0;
}

__attribute__((used)) static inline void lowpan_dev_debugfs_exit(struct net_device *dev) { }

