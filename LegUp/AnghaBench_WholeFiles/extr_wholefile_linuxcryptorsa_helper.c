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
typedef  int /*<<< orphan*/  u8 ;
struct rsa_key {size_t n_sz; size_t e_sz; size_t d_sz; size_t p_sz; size_t q_sz; size_t dp_sz; size_t dq_sz; size_t qinv_sz; void const* qinv; void const* dq; void const* dp; void const* q; void const* p; void const* d; void const* e; void const* n; } ;

/* Variables and functions */
 int EINVAL ; 
 int asn1_ber_decoder (int /*<<< orphan*/ *,struct rsa_key*,void const*,unsigned int) ; 
 scalar_t__ fips_enabled ; 
 int /*<<< orphan*/  pr_err (char*) ; 
 int /*<<< orphan*/  rsaprivkey_decoder ; 
 int /*<<< orphan*/  rsapubkey_decoder ; 

int rsa_get_n(void *context, size_t hdrlen, unsigned char tag,
	      const void *value, size_t vlen)
{
	struct rsa_key *key = context;
	const u8 *ptr = value;
	size_t n_sz = vlen;

	/* invalid key provided */
	if (!value || !vlen)
		return -EINVAL;

	if (fips_enabled) {
		while (n_sz && !*ptr) {
			ptr++;
			n_sz--;
		}

		/* In FIPS mode only allow key size 2K and higher */
		if (n_sz < 256) {
			pr_err("RSA: key size not allowed in FIPS mode\n");
			return -EINVAL;
		}
	}

	key->n = value;
	key->n_sz = vlen;

	return 0;
}

int rsa_get_e(void *context, size_t hdrlen, unsigned char tag,
	      const void *value, size_t vlen)
{
	struct rsa_key *key = context;

	/* invalid key provided */
	if (!value || !key->n_sz || !vlen || vlen > key->n_sz)
		return -EINVAL;

	key->e = value;
	key->e_sz = vlen;

	return 0;
}

int rsa_get_d(void *context, size_t hdrlen, unsigned char tag,
	      const void *value, size_t vlen)
{
	struct rsa_key *key = context;

	/* invalid key provided */
	if (!value || !key->n_sz || !vlen || vlen > key->n_sz)
		return -EINVAL;

	key->d = value;
	key->d_sz = vlen;

	return 0;
}

int rsa_get_p(void *context, size_t hdrlen, unsigned char tag,
	      const void *value, size_t vlen)
{
	struct rsa_key *key = context;

	/* invalid key provided */
	if (!value || !vlen || vlen > key->n_sz)
		return -EINVAL;

	key->p = value;
	key->p_sz = vlen;

	return 0;
}

int rsa_get_q(void *context, size_t hdrlen, unsigned char tag,
	      const void *value, size_t vlen)
{
	struct rsa_key *key = context;

	/* invalid key provided */
	if (!value || !vlen || vlen > key->n_sz)
		return -EINVAL;

	key->q = value;
	key->q_sz = vlen;

	return 0;
}

int rsa_get_dp(void *context, size_t hdrlen, unsigned char tag,
	       const void *value, size_t vlen)
{
	struct rsa_key *key = context;

	/* invalid key provided */
	if (!value || !vlen || vlen > key->n_sz)
		return -EINVAL;

	key->dp = value;
	key->dp_sz = vlen;

	return 0;
}

int rsa_get_dq(void *context, size_t hdrlen, unsigned char tag,
	       const void *value, size_t vlen)
{
	struct rsa_key *key = context;

	/* invalid key provided */
	if (!value || !vlen || vlen > key->n_sz)
		return -EINVAL;

	key->dq = value;
	key->dq_sz = vlen;

	return 0;
}

int rsa_get_qinv(void *context, size_t hdrlen, unsigned char tag,
		 const void *value, size_t vlen)
{
	struct rsa_key *key = context;

	/* invalid key provided */
	if (!value || !vlen || vlen > key->n_sz)
		return -EINVAL;

	key->qinv = value;
	key->qinv_sz = vlen;

	return 0;
}

int rsa_parse_pub_key(struct rsa_key *rsa_key, const void *key,
		      unsigned int key_len)
{
	return asn1_ber_decoder(&rsapubkey_decoder, rsa_key, key, key_len);
}

int rsa_parse_priv_key(struct rsa_key *rsa_key, const void *key,
		       unsigned int key_len)
{
	return asn1_ber_decoder(&rsaprivkey_decoder, rsa_key, key, key_len);
}

