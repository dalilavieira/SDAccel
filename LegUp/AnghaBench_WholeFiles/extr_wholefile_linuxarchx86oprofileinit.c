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
struct oprofile_operations {int dummy; } ;

/* Variables and functions */
 int ENODEV ; 

__attribute__((used)) static int op_nmi_init(struct oprofile_operations *ops) { return -ENODEV; }

__attribute__((used)) static void op_nmi_exit(void) { }

