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
typedef  int /*<<< orphan*/  ut8 ;
typedef  int /*<<< orphan*/  RCrypto ;

/* Variables and functions */
 int flag ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  r_crypto_append (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 char* r_punycode_decode (char const*,int,int*) ; 
 char* r_punycode_encode (int /*<<< orphan*/  const*,int,int*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static bool punycode_set_key(RCrypto *cry, const ut8 *key, int keylen, int mode, int direction) {
	flag = direction;
	return true;
}

__attribute__((used)) static int punycode_get_key_size(RCrypto *cry) {
	return 0;
}

__attribute__((used)) static bool punycode_use(const char *algo) {
	return !strcmp (algo, "punycode");
}

__attribute__((used)) static bool update(RCrypto *cry, const ut8 *buf, int len) {
	char *obuf;
	int olen;
	if (flag) {
		obuf = r_punycode_decode ((const char *)buf, len, &olen);
	} else {
		obuf = r_punycode_encode (buf, len, &olen);
	}
	r_crypto_append (cry, (ut8*)obuf, olen);
	free (obuf);
	return true;
}

__attribute__((used)) static bool final(RCrypto *cry, const ut8* buf, int len) {
	return update (cry, buf, len);
}

