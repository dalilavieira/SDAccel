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
struct TYPE_4__ {int is_key; int is_first; int /*<<< orphan*/  sb; } ;
typedef  TYPE_1__ PJ ;

/* Variables and functions */
 int /*<<< orphan*/  r_strbuf_append (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static void pj_raw(PJ *j, const char *msg) {
	if (j && msg && *msg) {
		r_strbuf_append (j->sb, msg);
	}
}

__attribute__((used)) static void pj_comma(PJ *j) {
	if (j) {
		if (!j->is_key) {
			if (!j->is_first) {
				pj_raw (j, ",");
			}
		}
		j->is_first = false;
		j->is_key = false;
	}
}

