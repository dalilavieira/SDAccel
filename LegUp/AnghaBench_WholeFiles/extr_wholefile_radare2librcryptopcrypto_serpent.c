#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut32 ;
struct TYPE_11__ {int key_size; int /*<<< orphan*/  key; } ;
struct TYPE_10__ {int dir; } ;
typedef  TYPE_1__ RCrypto ;

/* Variables and functions */
 int BLOCK_SIZE ; 
 int* calloc (int,int const) ; 
 int /*<<< orphan*/  eprintf (char*,int) ; 
 int /*<<< orphan*/  free (int* const) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int const*,int) ; 
 int /*<<< orphan*/  r_crypto_append (TYPE_1__*,int* const,int const) ; 
 int r_read_le32 (int const*) ; 
 int /*<<< orphan*/  serpent_decrypt (TYPE_3__*,int* const,int* const) ; 
 int /*<<< orphan*/  serpent_encrypt (TYPE_3__*,int* const,int* const) ; 
 TYPE_3__ st ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static bool serpent_set_key(RCrypto *cry, const ut8 *key, int keylen, int mode, int direction) {
	eprintf ("key_size: %d\n", keylen);
	if ((keylen != 128 / 8) && (keylen != 192 / 8) && (keylen != 256 / 8)) {
		return false;
	}
	st.key_size = keylen*8;
	eprintf ("key_size: %d\n", st.key_size);
	memcpy (st.key, key, keylen);
	cry->dir = direction;
	return true;
}

__attribute__((used)) static int serpent_get_key_size(RCrypto *cry) {
	return st.key_size;
}

__attribute__((used)) static bool serpent_use(const char *algo) {
	return !strcmp (algo, "serpent-ecb");
}

__attribute__((used)) static bool update(RCrypto *cry, const ut8 *buf, int len) {
	// Pad to the block size, do not append dummy block
	const int diff = (BLOCK_SIZE - (len % BLOCK_SIZE)) % BLOCK_SIZE;
	const int size = len + diff;
	const int blocks = size / BLOCK_SIZE;
	int i, j;

	ut8 *const obuf = calloc (4, size/4);
	if (!obuf) {
		return false;
	}
	ut32 *const ibuf = calloc (4, size/4);
	if (!ibuf) {
		free (obuf);
		return false;
	}
	ut32 *const tmp = calloc (4, size/4);
	if (!ibuf) {
		free (obuf);
		free (ibuf);
		return false;
	}

	// Construct ut32 blocks from byte stream
	for (j = 0; j < size/4; j++) {
		ibuf[j] = r_read_le32(&buf[4*j]);
	}

	// Zero padding.

	if (cry->dir == 0) {
		for (i = 0; i < blocks; i++) {
			// delta in number of ut32
			const int delta = (BLOCK_SIZE * i)/4;
			serpent_encrypt (&st, ibuf + delta, tmp + delta);
		}
	} else if (cry->dir > 0) {
		for (i = 0; i < blocks; i++) {
			// delta in number of ut32
			const int delta = (BLOCK_SIZE * i)/4;
			serpent_decrypt (&st, ibuf + delta, tmp + delta);
		}
	}

	// Construct ut32 blocks from byte stream
	int k;
	for (j = 0; j < size/4; j++) {
		k = 4*j;
		obuf[k] = tmp[j] & 0xff;
		obuf[k+1] = (tmp[j] >> 8) & 0xff;
		obuf[k+2] = (tmp[j] >> 16) & 0xff;
		obuf[k+3] = (tmp[j] >> 24) & 0xff;
	}

	r_crypto_append (cry, obuf, size);
	free (obuf);
	free (ibuf);
	free (tmp);
	return true;
}

__attribute__((used)) static bool final(RCrypto *cry, const ut8 *buf, int len) {
	return update (cry, buf, len);
}

