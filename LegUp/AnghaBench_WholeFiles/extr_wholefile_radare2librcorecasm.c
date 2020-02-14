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
struct TYPE_4__ {scalar_t__ addr; } ;
typedef  TYPE_1__ RCoreAsmHit ;

/* Variables and functions */

__attribute__((used)) static int rcoreasm_address_comparator(RCoreAsmHit *a, RCoreAsmHit *b){
	if (a->addr == b->addr) {
		return 0;
	}
	if (a->addr < b->addr) {
		return -1;
	}
	return 1; /* a->addr > b->addr */
}

