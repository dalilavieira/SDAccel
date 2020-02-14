#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  size_t uint32_t ;
typedef  int int32_t ;
struct TYPE_7__ {int shift; int /*<<< orphan*/  round; } ;
struct TYPE_6__ {size_t k0; size_t k1; void* sum1; void* sum0; } ;
typedef  TYPE_1__ TTARice ;
typedef  TYPE_2__ TTAFilter ;

/* Variables and functions */
 int /*<<< orphan*/ * ff_tta_shift_1 ; 
 void** ff_tta_shift_16 ; 
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 

void ff_tta_rice_init(TTARice *c, uint32_t k0, uint32_t k1)
{
    c->k0 = k0;
    c->k1 = k1;
    c->sum0 = ff_tta_shift_16[k0];
    c->sum1 = ff_tta_shift_16[k1];
}

void ff_tta_filter_init(TTAFilter *c, int32_t shift) {
    memset(c, 0, sizeof(TTAFilter));
    c->shift = shift;
    c->round = ff_tta_shift_1[shift-1];
}

