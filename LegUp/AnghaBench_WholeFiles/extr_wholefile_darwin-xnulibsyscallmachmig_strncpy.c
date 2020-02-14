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
typedef  scalar_t__ boolean_t ;

/* Variables and functions */
 scalar_t__ FALSE ; 
 scalar_t__ TRUE ; 

int
mig_strncpy(
    char *dest,
    const char *src,
    int len)
{
    int i;

    if (len <= 0) {
		return 0;
	}

    for (i = 1; i < len; i++) {
		if (!(*dest++ = *src++)) {
			return i;
		}
	}

    *dest = '\0';
    return i;
}

int
mig_strncpy_zerofill(
    char *dest,
    const char *src,
    int len)
{
	int i;
	boolean_t terminated = FALSE;
	int retval = 0;

	if (len <= 0 || dest == 0) {
		return 0;
	}

	if (src == 0) {
		terminated = TRUE;
	}

	for (i = 1; i < len; i++) {
		if (!terminated) {
			if (!(*dest++ = *src++)) {
				retval = i;
				terminated = TRUE;
			}
		} else {
			*dest++ = '\0';
		}
	}

	*dest = '\0';
	if (!terminated) {
		retval = i;
	}

	return retval;
}

