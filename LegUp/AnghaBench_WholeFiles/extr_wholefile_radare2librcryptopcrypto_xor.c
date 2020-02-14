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
struct xor_state {int key_size; int const* key; } ;
typedef  int /*<<< orphan*/  RCrypto ;

/* Variables and functions */
 int* calloc (int,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int const* malloc (int) ; 
 int /*<<< orphan*/  memcpy (int const*,int const*,int) ; 
 int /*<<< orphan*/  r_crypto_append (int /*<<< orphan*/ *,int*,int) ; 
 struct xor_state st ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static bool xor_init(struct xor_state *const state, const ut8 *key, int keylen) {
	if (!state || !key || keylen < 1) { // || keylen > MAX_xor_KEY_SIZE) {
		return false;
	}
	state->key_size = keylen;
	state->key = malloc (keylen);
	memcpy (state->key, key, keylen);
	return true;
}

__attribute__((used)) static void xor_crypt(struct xor_state *const state, const ut8 *inbuf, ut8 *outbuf, int buflen) {
	int i;//index for input
	for (i = 0; i < buflen; i++) {
		outbuf[i] = inbuf[i] ^ state->key[(i%state->key_size)];
	}
}

__attribute__((used)) static bool xor_set_key(RCrypto *cry, const ut8 *key, int keylen, int mode, int direction) {
	return xor_init (&st, key, keylen);
}

__attribute__((used)) static int xor_get_key_size(RCrypto *cry) {
	return st.key_size;
}

__attribute__((used)) static bool xor_use(const char *algo) {
	return !strcmp (algo, "xor");
}

__attribute__((used)) static bool update(RCrypto *cry, const ut8 *buf, int len) {
	ut8 *obuf = calloc (1, len);
	if (!obuf) {
		return false;
	}
	xor_crypt (&st, buf, obuf, len);
	r_crypto_append (cry, obuf, len);
	free (obuf);
	return true;
}

__attribute__((used)) static bool final(RCrypto *cry, const ut8 *buf, int len) {
	return update (cry, buf, len);
}

