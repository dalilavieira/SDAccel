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
struct snd_soc_dapm_widget {int dummy; } ;
struct skl_module_cfg {int dummy; } ;
struct skl_debug {int dummy; } ;
struct skl {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline struct skl_debug *skl_debugfs_init(struct skl *skl)
{
	return NULL;
}

__attribute__((used)) static inline void skl_debug_init_module(struct skl_debug *d,
					 struct snd_soc_dapm_widget *w,
					 struct skl_module_cfg *mconfig)
{}

