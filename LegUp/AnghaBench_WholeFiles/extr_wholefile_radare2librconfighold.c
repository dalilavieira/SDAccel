#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {struct TYPE_6__* value; } ;
typedef  TYPE_1__ RConfigHoldNum ;
typedef  TYPE_1__ RConfigHoldChar ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 

__attribute__((used)) static void r_config_hold_char_free(RConfigHoldChar *hc) {
	free (hc->value);
	free (hc);
}

__attribute__((used)) static void r_config_hold_num_free(RConfigHoldNum *hc) {
	free (hc);
}

