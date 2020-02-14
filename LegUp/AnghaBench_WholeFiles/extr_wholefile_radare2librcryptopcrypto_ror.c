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
struct ror_state {int key_size; int* key; } ;
typedef  int /*<<< orphan*/  RCrypto ;

/* Variables and functions */
 int MAX_ror_KEY_SIZE ; 
 int /*<<< orphan*/  NAME ; 
 int* calloc (int,int) ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 int flag ; 
 int /*<<< orphan*/  free (int*) ; 
 int /*<<< orphan*/  r_crypto_append (int /*<<< orphan*/ *,int*,int) ; 
 struct ror_state st ; 
 int /*<<< orphan*/  strcmp (char const*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static bool ror_init(struct ror_state *const state, const ut8 *key, int keylen) {
	if (!state || !key || keylen < 1 || keylen > MAX_ror_KEY_SIZE) {
		return false;
	}
	int i;
	state->key_size = keylen;
	for (i = 0; i < keylen; i++) {
		state->key[i] = key[i];
	}
	return true;
}

__attribute__((used)) static void ror_crypt(struct ror_state *const state, const ut8 *inbuf, ut8 *outbuf, int buflen) {
	int i;
	for (i = 0; i < buflen; i++) {
		ut8 count = state->key[i % state->key_size] & 7;
		ut8 inByte = inbuf[i];
		outbuf[i] = (inByte >> count) | (inByte << ((8 - count) & 7));
	}
}

__attribute__((used)) static bool ror_set_key(RCrypto *cry, const ut8 *key, int keylen, int mode, int direction) {
	flag = direction;
	return ror_init (&st, key, keylen);
}

__attribute__((used)) static int ror_get_key_size(RCrypto *cry) {
	return st.key_size;
}

__attribute__((used)) static bool ror_use(const char *algo) {
	return !strcmp (algo, NAME);
}

__attribute__((used)) static bool update(RCrypto *cry, const ut8 *buf, int len) {
	if (flag) {
		eprintf ("USE ROL\n");
		return false;
	}
	ut8 *obuf = calloc (1, len);
	if (!obuf) {
		return false;
	}
	ror_crypt (&st, buf, obuf, len);
	r_crypto_append (cry, obuf, len);
	free (obuf);
	return true;
}

