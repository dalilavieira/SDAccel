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

/* Variables and functions */

void pgtrace_stop(void) {}

void pgtrace_start(void) {}

void pgtrace_clear_probe(void) {}

void pgtrace_add_probe(void) {}

void pgtrace_init(void) {}

void pgtrace_active(void) {}

