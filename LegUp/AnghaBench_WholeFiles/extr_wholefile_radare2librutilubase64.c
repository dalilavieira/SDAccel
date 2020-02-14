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
 char* cb64 ; 
 int* cd64 ; 

__attribute__((used)) static void local_b64_encode(const ut8 in[3], char out[4], int len) {
	if (len < 1) {
		return;
	}
	out[0] = cb64[in[0] >> 2];
	out[1] = cb64[((in[0] & 0x03) << 4) | ((len > 1)? ((in[1] & 0xf0) >> 4): 0)];
	out[2] = (len > 1? cb64[((in[1] & 0x0f) << 2) | (len > 2? ((in[2] & 0xc0) >> 6): 0)]: '=');
	out[3] = (len > 2? cb64[in[2] & 0x3f]: '=');
}

__attribute__((used)) static int local_b64_decode(const char in[4], ut8 out[3]) {
	int len = 3;
	ut8 i, v[4] = { 0 };
	for (i = 0; i < 4; i++) {
		if (in[i] < 43 || in[i] > 122) {
			return -1;
		}
		v[i] = cd64[in[i] - 43];
		if (v[i] == '$') {
			len = i? i - 1: -1;
			break;
		}
		v[i] -= 62;
	}
	out[0] = v[0] << 2 | v[1] >> 4;
	out[1] = v[1] << 4 | v[2] >> 2;
	out[2] = ((v[2] << 6) & 0xc0) | v[3];
	return len;
}

