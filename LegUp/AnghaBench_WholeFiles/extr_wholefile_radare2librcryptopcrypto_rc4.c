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
struct rc4_state {int key_size; int* perm; size_t index1; size_t index2; } ;
typedef  int /*<<< orphan*/  RCrypto ;

/* Variables and functions */
 int* calloc (int,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int /*<<< orphan*/  r_crypto_append (int /*<<< orphan*/ *,int*,int) ; 
 struct rc4_state st ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static __inline void swap_bytes(ut8 *a, ut8 *b) {
	if (a != b) {
		ut8 temp = *a;
		*a = *b;
		*b = temp;
	}
}

__attribute__((used)) static bool rc4_init(struct rc4_state *const state, const ut8 *key, int keylen) {
	ut8 j;
	int i;

	if (!state || !key || keylen < 1) {
		return false;
	}
	state->key_size = keylen;
	/* Initialize state with identity permutation */
	for (i = 0; i < 256; i++) {
		state->perm[i] = (ut8)i;
	}
	state->index1 = 0;
	state->index2 = 0;

	/* Randomize the permutation using key data */
	for (j = i = 0; i < 256; i++) {
		j += state->perm[i] + key[i % keylen];
		swap_bytes (&state->perm[i], &state->perm[j]);
	}
	return true;
}

__attribute__((used)) static void rc4_crypt(struct rc4_state *const state, const ut8 *inbuf, ut8 *outbuf, int buflen) {
	int i;
	ut8 j;

	for (i = 0; i < buflen; i++) {
		/* Update modification indicies */
		state->index1++;
		state->index2 += state->perm[state->index1];
		/* Modify permutation */
		swap_bytes (&state->perm[state->index1],
		    &state->perm[state->index2]);
		/* Encrypt/decrypt next byte */
		j = state->perm[state->index1] + state->perm[state->index2];
		outbuf[i] = inbuf[i] ^ state->perm[j];
	}
}

__attribute__((used)) static bool rc4_set_key(RCrypto *cry, const ut8 *key, int keylen, int mode, int direction) {
	return rc4_init (&st, key, keylen);
}

__attribute__((used)) static int rc4_get_key_size(RCrypto *cry) {
	return st.key_size;
}

__attribute__((used)) static bool rc4_use(const char *algo) {
	return !strcmp (algo, "rc4");
}

__attribute__((used)) static bool update(RCrypto *cry, const ut8 *buf, int len) {
	ut8 *obuf = calloc (1, len);
	if (!obuf) {
		return false;
	}
	rc4_crypt (&st, buf, obuf, len);
	r_crypto_append (cry, obuf, len);
	free (obuf);
	return false;
}

__attribute__((used)) static bool final(RCrypto *cry, const ut8 *buf, int len) {
	return update (cry, buf, len);
}

