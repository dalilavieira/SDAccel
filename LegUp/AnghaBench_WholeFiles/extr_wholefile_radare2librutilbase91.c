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
 char const* b91 ; 

int get_char_index(const char c) {
	int i;
	for (i = 0; i < 91; i++ ) {
		if (b91[i] == c) {
			return i;
		}
	}
	return -1;
}

