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
typedef  int ut32 ;

/* Variables and functions */

__attribute__((used)) static const ut8* parse_next_rsa_field(const ut8* start, ut32 *len) {
	*len = 0;
	if (!(start[1] & 128)) {
		len = (ut32*)(start + 1);
		return start + 2;
	} else {
		int i;
		const int lensize = start[1] & 127;
		for (i = 0; i < lensize; i++) {
			*len = (*len << 8) | start[2 + i];
		}
		return start + 2 + lensize;
	}
}

__attribute__((used)) static int check_rsa_fields(const ut8* start) {
#define NB_PRIV_FIELDS 10
	ut32 len = 0;
	int i;
	// skip sequence field
	ut8 const* ptr = parse_next_rsa_field (start, &len);

	if (!len || len > 1024) {
		return false;
	}
	for (i = 0; i < NB_PRIV_FIELDS; i++) {
		if (!(ptr = parse_next_rsa_field (ptr, &len))) {
			return false;
		}
	}
	return true;
}

