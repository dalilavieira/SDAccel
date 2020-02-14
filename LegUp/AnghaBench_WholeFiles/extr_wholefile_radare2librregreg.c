#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int offset; int size; } ;
typedef  TYPE_1__ RRegItem ;

/* Variables and functions */

__attribute__((used)) static int regcmp(RRegItem *a, RRegItem *b) {
	int offa = (a->offset * 16) + a->size;
	int offb = (b->offset * 16) + b->size;
	return offa > offb;
}

