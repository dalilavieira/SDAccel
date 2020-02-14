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
typedef  char ut8 ;
typedef  int /*<<< orphan*/  RCrypto ;

/* Variables and functions */
 int atoi (char const*) ; 
 char* calloc (int,int) ; 
 int flag ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  r_crypto_append (int /*<<< orphan*/ *,char*,int) ; 
 char rot_key ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

int mod(int a, int b) {
	if (b < 0) {
		return mod (-a, -b);
	}
	int ret = a % b;
	if (ret < 0) {
		ret += b;
	}
	return ret;
}

__attribute__((used)) static bool rot_init(ut8 *rotkey, const ut8 *key, int keylen) {
	if (rotkey && key && keylen > 0) {
		int i = atoi ((const char *)key);
		*rotkey = (ut8)mod (i, 26);
		return true;
	}
	return false;
}

__attribute__((used)) static void rot_crypt(ut8 key, const ut8 *inbuf, ut8 *outbuf, int buflen) {
	int i;
	for (i = 0; i < buflen; i++) {
		outbuf[i] = inbuf[i];
		if ((inbuf[i] < 'a' || inbuf[i] > 'z') && (inbuf[i] < 'A' || inbuf[i] > 'Z')) {
			continue;
		}
		outbuf[i] += key;
		outbuf[i] -= (inbuf[i] >= 'a' && inbuf[i] <= 'z') ? 'a' : 'A';
		outbuf[i] = mod (outbuf[i], 26);
		outbuf[i] += (inbuf[i] >= 'a' && inbuf[i] <= 'z') ? 'a' : 'A';
	}
}

__attribute__((used)) static void rot_decrypt(ut8 key, const ut8 *inbuf, ut8 *outbuf, int buflen) {
	int i;
	for (i = 0; i < buflen; i++) {
		outbuf[i] = inbuf[i];
		if ((inbuf[i] < 'a' || inbuf[i] > 'z') && (inbuf[i] < 'A' || inbuf[i] > 'Z')) {
			continue;
		}
		outbuf[i] += 26;	//adding so that subtracting does not make it negative
		outbuf[i] -= key;
		outbuf[i] -= (inbuf[i] >= 'a' && inbuf[i] <= 'z') ? 'a' : 'A';
		outbuf[i] = mod (outbuf[i], 26);
		outbuf[i] += (inbuf[i] >= 'a' && inbuf[i] <= 'z') ? 'a' : 'A';
	}
}

__attribute__((used)) static bool rot_set_key(RCrypto *cry, const ut8 *key, int keylen, int mode, int direction) {
	flag = direction;
	return rot_init (&rot_key, key, keylen);
}

__attribute__((used)) static int rot_get_key_size(RCrypto *cry) {
	//Returning number of bytes occupied by ut8
	return 1;
}

__attribute__((used)) static bool rot_use(const char *algo) {
	return !strcmp (algo, "rot");
}

__attribute__((used)) static bool update(RCrypto *cry, const ut8 *buf, int len) {
	ut8 *obuf = calloc (1, len);
	if (!obuf) {
		return false;
	}
	if (flag == 0) {
		rot_crypt (rot_key, buf, obuf, len);
	} else if (flag == 1) {
		rot_decrypt (rot_key, buf, obuf, len);
	}
	r_crypto_append (cry, obuf, len);
	free (obuf);
	return true;
}

__attribute__((used)) static bool final(RCrypto *cry, const ut8 *buf, int len) {
	return update (cry, buf, len);
}

