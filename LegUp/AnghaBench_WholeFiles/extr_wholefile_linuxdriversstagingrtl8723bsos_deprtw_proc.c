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
struct proc_dir_entry {int dummy; } ;
struct net_device {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline int rtw_drv_proc_init(void) {return 0;}

__attribute__((used)) static inline void rtw_drv_proc_deinit(void) {}

__attribute__((used)) static inline struct proc_dir_entry *rtw_adapter_proc_init(struct net_device *dev){return NULL;}

__attribute__((used)) static inline void rtw_adapter_proc_deinit(struct net_device *dev){}

__attribute__((used)) static inline void rtw_adapter_proc_replace(struct net_device *dev){}

