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
typedef  int uint32_t ;
struct expanded_key {int* l; int* r; } ;
typedef  int /*<<< orphan*/  keybuf ;

/* Variables and functions */
 unsigned char const _PASSWORD_EFMT1 ; 
 unsigned char const* ascii64 ; 
 int** comp_maskl0 ; 
 int** comp_maskl1 ; 
 int** comp_maskr0 ; 
 int** comp_maskr1 ; 
 int** fp_maskl ; 
 int** fp_maskr ; 
 int** ip_maskl ; 
 int** ip_maskr ; 
 int** key_perm_maskl ; 
 int** key_perm_maskr ; 
 scalar_t__* key_shifts ; 
 int /*<<< orphan*/  memcpy (char*,unsigned char const*,int) ; 
 int** psbox ; 
 int /*<<< orphan*/  strcmp (char const*,char const*) ; 

__attribute__((used)) static uint32_t ascii_to_bin(int ch)
{
	int sch = (ch < 0x80) ? ch : -(0x100 - ch);
	int retval;

	retval = sch - '.';
	if (sch >= 'A') {
		retval = sch - ('A' - 12);
		if (sch >= 'a')
			retval = sch - ('a' - 38);
	}
	retval &= 0x3f;

	return retval;
}

__attribute__((used)) static inline int ascii_is_unsafe(unsigned char ch)
{
	return !ch || ch == '\n' || ch == ':';
}

__attribute__((used)) static uint32_t setup_salt(uint32_t salt)
{
	uint32_t obit, saltbit, saltbits;
	unsigned int i;

	saltbits = 0;
	saltbit = 1;
	obit = 0x800000;
	for (i = 0; i < 24; i++) {
		if (salt & saltbit)
			saltbits |= obit;
		saltbit <<= 1;
		obit >>= 1;
	}

	return saltbits;
}

void __des_setkey(const unsigned char *key, struct expanded_key *ekey)
{
	uint32_t k0, k1, rawkey0, rawkey1;
	unsigned int shifts, round, i, ibit;

	rawkey0 =
	    (uint32_t)key[3] |
	    ((uint32_t)key[2] << 8) |
	    ((uint32_t)key[1] << 16) |
	    ((uint32_t)key[0] << 24);
	rawkey1 =
	    (uint32_t)key[7] |
	    ((uint32_t)key[6] << 8) |
	    ((uint32_t)key[5] << 16) |
	    ((uint32_t)key[4] << 24);

	/*
	 * Do key permutation and split into two 28-bit subkeys.
	 */
	k0 = k1 = 0;
	for (i = 0, ibit = 28; i < 4; i++, ibit -= 4) {
		unsigned int j = i << 1;
		k0 |= key_perm_maskl[i][(rawkey0 >> ibit) & 0xf] |
		      key_perm_maskl[i + 4][(rawkey1 >> ibit) & 0xf];
		k1 |= key_perm_maskr[j][(rawkey0 >> ibit) & 0xf];
		ibit -= 4;
		k1 |= key_perm_maskr[j + 1][(rawkey0 >> ibit) & 0xf] |
		      key_perm_maskr[i + 8][(rawkey1 >> ibit) & 0xf];
	}

	/*
	 * Rotate subkeys and do compression permutation.
	 */
	shifts = 0;
	for (round = 0; round < 16; round++) {
		uint32_t t0, t1;
		uint32_t kl, kr;

		shifts += key_shifts[round];

		t0 = (k0 << shifts) | (k0 >> (28 - shifts));
		t1 = (k1 << shifts) | (k1 >> (28 - shifts));

		kl = kr = 0;
		ibit = 25;
		for (i = 0; i < 4; i++) {
			kl |= comp_maskl0[i][(t0 >> ibit) & 7];
			kr |= comp_maskr0[i][(t1 >> ibit) & 7];
			ibit -= 4;
			kl |= comp_maskl1[i][(t0 >> ibit) & 0xf];
			kr |= comp_maskr1[i][(t1 >> ibit) & 0xf];
			ibit -= 3;
		}
		ekey->l[round] = kl;
		ekey->r[round] = kr;
	}
}

void __do_des(uint32_t l_in, uint32_t r_in,
    uint32_t *l_out, uint32_t *r_out,
    uint32_t count, uint32_t saltbits, const struct expanded_key *ekey)
{
	uint32_t l, r;

	/*
	 * Do initial permutation (IP).
	 */
	l = r = 0;
	if (l_in | r_in) {
		unsigned int i, ibit;
		for (i = 0, ibit = 28; i < 8; i++, ibit -= 4) {
			l |= ip_maskl[i][(l_in >> ibit) & 0xf] |
			     ip_maskl[i + 8][(r_in >> ibit) & 0xf];
			r |= ip_maskr[i][(l_in >> ibit) & 0xf] |
			     ip_maskr[i + 8][(r_in >> ibit) & 0xf];
		}
	}

	while (count--) {
		/*
		 * Do each round.
		 */
		unsigned int round = 16;
		const uint32_t *kl = ekey->l;
		const uint32_t *kr = ekey->r;
		uint32_t f;
		while (round--) {
			uint32_t r48l, r48r;
			/*
			 * Expand R to 48 bits (simulate the E-box).
			 */
			r48l	= ((r & 0x00000001) << 23)
				| ((r & 0xf8000000) >> 9)
				| ((r & 0x1f800000) >> 11)
				| ((r & 0x01f80000) >> 13)
				| ((r & 0x001f8000) >> 15);

			r48r	= ((r & 0x0001f800) << 7)
				| ((r & 0x00001f80) << 5)
				| ((r & 0x000001f8) << 3)
				| ((r & 0x0000001f) << 1)
				| ((r & 0x80000000) >> 31);
			/*
			 * Do salting for crypt() and friends, and
			 * XOR with the permuted key.
			 */
			f = (r48l ^ r48r) & saltbits;
			r48l ^= f ^ *kl++;
			r48r ^= f ^ *kr++;
			/*
			 * Do S-box lookups (which shrink it back to 32 bits)
			 * and do the P-box permutation at the same time.
			 */
			f = psbox[0][r48l >> 18]
			  | psbox[1][(r48l >> 12) & 0x3f]
			  | psbox[2][(r48l >> 6) & 0x3f]
			  | psbox[3][r48l & 0x3f]
			  | psbox[4][r48r >> 18]
			  | psbox[5][(r48r >> 12) & 0x3f]
			  | psbox[6][(r48r >> 6) & 0x3f]
			  | psbox[7][r48r & 0x3f];
			/*
			 * Now that we've permuted things, complete f().
			 */
			f ^= l;
			l = r;
			r = f;
		}
		r = l;
		l = f;
	}

	/*
	 * Do final permutation (inverse of IP).
	 */
	{
		unsigned int i, ibit;
		uint32_t lo, ro;
		lo = ro = 0;
		for (i = 0, ibit = 28; i < 4; i++, ibit -= 4) {
			ro |= fp_maskr[i][(l >> ibit) & 0xf] |
			      fp_maskr[i + 4][(r >> ibit) & 0xf];
			ibit -= 4;
			lo |= fp_maskl[i][(l >> ibit) & 0xf] |
			      fp_maskl[i + 4][(r >> ibit) & 0xf];
		}
		*l_out = lo;
		*r_out = ro;
	}
}

__attribute__((used)) static void des_cipher(const unsigned char *in, unsigned char *out,
    uint32_t count, uint32_t saltbits, const struct expanded_key *ekey)
{
	uint32_t l_out, r_out, rawl, rawr;

	rawl =
	    (uint32_t)in[3] |
	    ((uint32_t)in[2] << 8) |
	    ((uint32_t)in[1] << 16) |
	    ((uint32_t)in[0] << 24);
	rawr =
	    (uint32_t)in[7] |
	    ((uint32_t)in[6] << 8) |
	    ((uint32_t)in[5] << 16) |
	    ((uint32_t)in[4] << 24);

	__do_des(rawl, rawr, &l_out, &r_out, count, saltbits, ekey);

	out[0] = l_out >> 24;
	out[1] = l_out >> 16;
	out[2] = l_out >> 8;
	out[3] = l_out;
	out[4] = r_out >> 24;
	out[5] = r_out >> 16;
	out[6] = r_out >> 8;
	out[7] = r_out;
}

__attribute__((used)) static char *_crypt_extended_r_uut(const char *_key, const char *_setting, char *output)
{
	const unsigned char *key = (const unsigned char *)_key;
	const unsigned char *setting = (const unsigned char *)_setting;
	struct expanded_key ekey;
	unsigned char keybuf[8];
	unsigned char *p, *q;
	uint32_t count, salt, l, r0, r1;
	unsigned int i;

	/*
	 * Copy the key, shifting each character left by one bit and padding
	 * with zeroes.
	 */
	q = keybuf;
	while (q <= &keybuf[sizeof(keybuf) - 1]) {
		*q++ = *key << 1;
		if (*key)
			key++;
	}
	__des_setkey(keybuf, &ekey);

	if (*setting == _PASSWORD_EFMT1) {
		/*
		 * "new"-style:
		 *	setting - underscore, 4 chars of count, 4 chars of salt
		 *	key - unlimited characters
		 */
		for (i = 1, count = 0; i < 5; i++) {
			uint32_t value = ascii_to_bin(setting[i]);
			if (ascii64[value] != setting[i])
				return NULL;
			count |= value << (i - 1) * 6;
		}
		if (!count)
			return NULL;

		for (i = 5, salt = 0; i < 9; i++) {
			uint32_t value = ascii_to_bin(setting[i]);
			if (ascii64[value] != setting[i])
				return NULL;
			salt |= value << (i - 5) * 6;
		}

		while (*key) {
			/*
			 * Encrypt the key with itself.
			 */
			des_cipher(keybuf, keybuf, 1, 0, &ekey);
			/*
			 * And XOR with the next 8 characters of the key.
			 */
			q = keybuf;
			while (q <= &keybuf[sizeof(keybuf) - 1] && *key)
				*q++ ^= *key++ << 1;
			__des_setkey(keybuf, &ekey);
		}

		memcpy(output, setting, 9);
		output[9] = '\0';
		p = (unsigned char *)output + 9;
	} else {
		/*
		 * "old"-style:
		 *	setting - 2 chars of salt
		 *	key - up to 8 characters
		 */
		count = 25;

		if (ascii_is_unsafe(setting[0]) || ascii_is_unsafe(setting[1]))
			return NULL;

		salt = (ascii_to_bin(setting[1]) << 6)
		     |  ascii_to_bin(setting[0]);

		output[0] = setting[0];
		output[1] = setting[1];
		p = (unsigned char *)output + 2;
	}

	/*
	 * Do it.
	 */
	__do_des(0, 0, &r0, &r1, count, setup_salt(salt), &ekey);

	/*
	 * Now encode the result...
	 */
	l = (r0 >> 8);
	*p++ = ascii64[(l >> 18) & 0x3f];
	*p++ = ascii64[(l >> 12) & 0x3f];
	*p++ = ascii64[(l >> 6) & 0x3f];
	*p++ = ascii64[l & 0x3f];

	l = (r0 << 16) | ((r1 >> 16) & 0xffff);
	*p++ = ascii64[(l >> 18) & 0x3f];
	*p++ = ascii64[(l >> 12) & 0x3f];
	*p++ = ascii64[(l >> 6) & 0x3f];
	*p++ = ascii64[l & 0x3f];

	l = r1 << 2;
	*p++ = ascii64[(l >> 12) & 0x3f];
	*p++ = ascii64[(l >> 6) & 0x3f];
	*p++ = ascii64[l & 0x3f];
	*p = 0;

	return output;
}

char *__crypt_des(const char *key, const char *setting, char *output)
{
	const char *test_key = "\x80\xff\x80\x01 "
	    "\x7f\x81\x80\x80\x0d\x0a\xff\x7f \x81 test";
	const char *test_setting = "_0.../9Zz";
	const char *test_hash = "_0.../9ZzX7iSJNd21sU";
	char test_buf[21];
	char *retval;
	const char *p;

	if (*setting != _PASSWORD_EFMT1) {
		test_setting = "\x80x";
		test_hash = "\x80x22/wK52ZKGA";
	}

	/*
	 * Hash the supplied password.
	 */
	retval = _crypt_extended_r_uut(key, setting, output);

	/*
	 * Perform a quick self-test.  It is important that we make both calls
	 * to _crypt_extended_r_uut() from the same scope such that they likely
	 * use the same stack locations, which makes the second call overwrite
	 * the first call's sensitive data on the stack and makes it more
	 * likely that any alignment related issues would be detected.
	 */
	p = _crypt_extended_r_uut(test_key, test_setting, test_buf);
	if (p && !strcmp(p, test_hash) && retval)
		return retval;

	return (setting[0]=='*') ? "x" : "*";
}

