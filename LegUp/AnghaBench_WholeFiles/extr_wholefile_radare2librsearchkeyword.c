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
typedef  int ut8 ;

/* Variables and functions */

__attribute__((used)) static int ignoreMask(const ut8 *bm, int len) {
	int i;
	for (i=0; i<len; i++) {
		if (bm[i] != 0xff) {
			return 0;
		}
	}
	return 1;
}

