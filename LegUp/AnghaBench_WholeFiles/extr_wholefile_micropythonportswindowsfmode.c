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
 int /*<<< orphan*/  O_BINARY ; 
 int /*<<< orphan*/  O_TEXT ; 
 int /*<<< orphan*/  set_fmode_impl (int /*<<< orphan*/ ) ; 

void set_fmode_binary(void) {
    set_fmode_impl(O_BINARY);
}

void set_fmode_text(void) {
    set_fmode_impl(O_TEXT);
}

