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
struct TYPE_2__ {int servers; int servers_sleeping; int simplelink; } ;

/* Variables and functions */
 TYPE_1__ pyb_wdt_obj ; 

__attribute__ ((section (".boot")))
void pybwdt_init0 (void) {
}

void pybwdt_srv_alive (void) {
    pyb_wdt_obj.servers = true;
}

void pybwdt_srv_sleeping (bool state) {
    pyb_wdt_obj.servers_sleeping = state;
}

void pybwdt_sl_alive (void) {
    pyb_wdt_obj.simplelink = true;
}

