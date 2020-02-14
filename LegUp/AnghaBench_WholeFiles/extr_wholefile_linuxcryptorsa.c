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
struct rsa_mpi_key {int /*<<< orphan*/ * n; int /*<<< orphan*/ * e; int /*<<< orphan*/ * d; } ;
struct rsa_key {int /*<<< orphan*/  n_sz; int /*<<< orphan*/  n; int /*<<< orphan*/  e_sz; int /*<<< orphan*/  e; int /*<<< orphan*/  d_sz; int /*<<< orphan*/  d; int /*<<< orphan*/  member_0; } ;
struct crypto_akcipher {int dummy; } ;
struct akcipher_request {int /*<<< orphan*/  dst_len; int /*<<< orphan*/  dst; int /*<<< orphan*/  src_len; int /*<<< orphan*/  src; } ;
typedef  int /*<<< orphan*/ * MPI ;

/* Variables and functions */
 int EBADMSG ; 
 int EINVAL ; 
 int ENOMEM ; 
 struct rsa_mpi_key* akcipher_tfm_ctx (struct crypto_akcipher*) ; 
 struct crypto_akcipher* crypto_akcipher_reqtfm (struct akcipher_request*) ; 
 int crypto_register_akcipher (int /*<<< orphan*/ *) ; 
 int crypto_register_template (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_unregister_akcipher (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  crypto_unregister_template (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mpi_alloc (int /*<<< orphan*/ ) ; 
 scalar_t__ mpi_cmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ mpi_cmp_ui (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mpi_free (int /*<<< orphan*/ *) ; 
 unsigned int mpi_get_size (int /*<<< orphan*/ *) ; 
 int mpi_powm (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 void* mpi_read_raw_data (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * mpi_read_raw_from_sgl (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mpi_write_to_sgl (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  rsa ; 
 int rsa_parse_priv_key (struct rsa_key*,void const*,unsigned int) ; 
 int rsa_parse_pub_key (struct rsa_key*,void const*,unsigned int) ; 
 int /*<<< orphan*/  rsa_pkcs1pad_tmpl ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static int _rsa_enc(const struct rsa_mpi_key *key, MPI c, MPI m)
{
	/* (1) Validate 0 <= m < n */
	if (mpi_cmp_ui(m, 0) < 0 || mpi_cmp(m, key->n) >= 0)
		return -EINVAL;

	/* (2) c = m^e mod n */
	return mpi_powm(c, m, key->e, key->n);
}

__attribute__((used)) static int _rsa_dec(const struct rsa_mpi_key *key, MPI m, MPI c)
{
	/* (1) Validate 0 <= c < n */
	if (mpi_cmp_ui(c, 0) < 0 || mpi_cmp(c, key->n) >= 0)
		return -EINVAL;

	/* (2) m = c^d mod n */
	return mpi_powm(m, c, key->d, key->n);
}

__attribute__((used)) static int _rsa_sign(const struct rsa_mpi_key *key, MPI s, MPI m)
{
	/* (1) Validate 0 <= m < n */
	if (mpi_cmp_ui(m, 0) < 0 || mpi_cmp(m, key->n) >= 0)
		return -EINVAL;

	/* (2) s = m^d mod n */
	return mpi_powm(s, m, key->d, key->n);
}

__attribute__((used)) static int _rsa_verify(const struct rsa_mpi_key *key, MPI m, MPI s)
{
	/* (1) Validate 0 <= s < n */
	if (mpi_cmp_ui(s, 0) < 0 || mpi_cmp(s, key->n) >= 0)
		return -EINVAL;

	/* (2) m = s^e mod n */
	return mpi_powm(m, s, key->e, key->n);
}

__attribute__((used)) static inline struct rsa_mpi_key *rsa_get_key(struct crypto_akcipher *tfm)
{
	return akcipher_tfm_ctx(tfm);
}

__attribute__((used)) static int rsa_enc(struct akcipher_request *req)
{
	struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
	const struct rsa_mpi_key *pkey = rsa_get_key(tfm);
	MPI m, c = mpi_alloc(0);
	int ret = 0;
	int sign;

	if (!c)
		return -ENOMEM;

	if (unlikely(!pkey->n || !pkey->e)) {
		ret = -EINVAL;
		goto err_free_c;
	}

	ret = -ENOMEM;
	m = mpi_read_raw_from_sgl(req->src, req->src_len);
	if (!m)
		goto err_free_c;

	ret = _rsa_enc(pkey, c, m);
	if (ret)
		goto err_free_m;

	ret = mpi_write_to_sgl(c, req->dst, req->dst_len, &sign);
	if (ret)
		goto err_free_m;

	if (sign < 0)
		ret = -EBADMSG;

err_free_m:
	mpi_free(m);
err_free_c:
	mpi_free(c);
	return ret;
}

__attribute__((used)) static int rsa_dec(struct akcipher_request *req)
{
	struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
	const struct rsa_mpi_key *pkey = rsa_get_key(tfm);
	MPI c, m = mpi_alloc(0);
	int ret = 0;
	int sign;

	if (!m)
		return -ENOMEM;

	if (unlikely(!pkey->n || !pkey->d)) {
		ret = -EINVAL;
		goto err_free_m;
	}

	ret = -ENOMEM;
	c = mpi_read_raw_from_sgl(req->src, req->src_len);
	if (!c)
		goto err_free_m;

	ret = _rsa_dec(pkey, m, c);
	if (ret)
		goto err_free_c;

	ret = mpi_write_to_sgl(m, req->dst, req->dst_len, &sign);
	if (ret)
		goto err_free_c;

	if (sign < 0)
		ret = -EBADMSG;
err_free_c:
	mpi_free(c);
err_free_m:
	mpi_free(m);
	return ret;
}

__attribute__((used)) static int rsa_sign(struct akcipher_request *req)
{
	struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
	const struct rsa_mpi_key *pkey = rsa_get_key(tfm);
	MPI m, s = mpi_alloc(0);
	int ret = 0;
	int sign;

	if (!s)
		return -ENOMEM;

	if (unlikely(!pkey->n || !pkey->d)) {
		ret = -EINVAL;
		goto err_free_s;
	}

	ret = -ENOMEM;
	m = mpi_read_raw_from_sgl(req->src, req->src_len);
	if (!m)
		goto err_free_s;

	ret = _rsa_sign(pkey, s, m);
	if (ret)
		goto err_free_m;

	ret = mpi_write_to_sgl(s, req->dst, req->dst_len, &sign);
	if (ret)
		goto err_free_m;

	if (sign < 0)
		ret = -EBADMSG;

err_free_m:
	mpi_free(m);
err_free_s:
	mpi_free(s);
	return ret;
}

__attribute__((used)) static int rsa_verify(struct akcipher_request *req)
{
	struct crypto_akcipher *tfm = crypto_akcipher_reqtfm(req);
	const struct rsa_mpi_key *pkey = rsa_get_key(tfm);
	MPI s, m = mpi_alloc(0);
	int ret = 0;
	int sign;

	if (!m)
		return -ENOMEM;

	if (unlikely(!pkey->n || !pkey->e)) {
		ret = -EINVAL;
		goto err_free_m;
	}

	s = mpi_read_raw_from_sgl(req->src, req->src_len);
	if (!s) {
		ret = -ENOMEM;
		goto err_free_m;
	}

	ret = _rsa_verify(pkey, m, s);
	if (ret)
		goto err_free_s;

	ret = mpi_write_to_sgl(m, req->dst, req->dst_len, &sign);
	if (ret)
		goto err_free_s;

	if (sign < 0)
		ret = -EBADMSG;

err_free_s:
	mpi_free(s);
err_free_m:
	mpi_free(m);
	return ret;
}

__attribute__((used)) static void rsa_free_mpi_key(struct rsa_mpi_key *key)
{
	mpi_free(key->d);
	mpi_free(key->e);
	mpi_free(key->n);
	key->d = NULL;
	key->e = NULL;
	key->n = NULL;
}

__attribute__((used)) static int rsa_check_key_length(unsigned int len)
{
	switch (len) {
	case 512:
	case 1024:
	case 1536:
	case 2048:
	case 3072:
	case 4096:
		return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static int rsa_set_pub_key(struct crypto_akcipher *tfm, const void *key,
			   unsigned int keylen)
{
	struct rsa_mpi_key *mpi_key = akcipher_tfm_ctx(tfm);
	struct rsa_key raw_key = {0};
	int ret;

	/* Free the old MPI key if any */
	rsa_free_mpi_key(mpi_key);

	ret = rsa_parse_pub_key(&raw_key, key, keylen);
	if (ret)
		return ret;

	mpi_key->e = mpi_read_raw_data(raw_key.e, raw_key.e_sz);
	if (!mpi_key->e)
		goto err;

	mpi_key->n = mpi_read_raw_data(raw_key.n, raw_key.n_sz);
	if (!mpi_key->n)
		goto err;

	if (rsa_check_key_length(mpi_get_size(mpi_key->n) << 3)) {
		rsa_free_mpi_key(mpi_key);
		return -EINVAL;
	}

	return 0;

err:
	rsa_free_mpi_key(mpi_key);
	return -ENOMEM;
}

__attribute__((used)) static int rsa_set_priv_key(struct crypto_akcipher *tfm, const void *key,
			    unsigned int keylen)
{
	struct rsa_mpi_key *mpi_key = akcipher_tfm_ctx(tfm);
	struct rsa_key raw_key = {0};
	int ret;

	/* Free the old MPI key if any */
	rsa_free_mpi_key(mpi_key);

	ret = rsa_parse_priv_key(&raw_key, key, keylen);
	if (ret)
		return ret;

	mpi_key->d = mpi_read_raw_data(raw_key.d, raw_key.d_sz);
	if (!mpi_key->d)
		goto err;

	mpi_key->e = mpi_read_raw_data(raw_key.e, raw_key.e_sz);
	if (!mpi_key->e)
		goto err;

	mpi_key->n = mpi_read_raw_data(raw_key.n, raw_key.n_sz);
	if (!mpi_key->n)
		goto err;

	if (rsa_check_key_length(mpi_get_size(mpi_key->n) << 3)) {
		rsa_free_mpi_key(mpi_key);
		return -EINVAL;
	}

	return 0;

err:
	rsa_free_mpi_key(mpi_key);
	return -ENOMEM;
}

__attribute__((used)) static unsigned int rsa_max_size(struct crypto_akcipher *tfm)
{
	struct rsa_mpi_key *pkey = akcipher_tfm_ctx(tfm);

	return mpi_get_size(pkey->n);
}

__attribute__((used)) static void rsa_exit_tfm(struct crypto_akcipher *tfm)
{
	struct rsa_mpi_key *pkey = akcipher_tfm_ctx(tfm);

	rsa_free_mpi_key(pkey);
}

__attribute__((used)) static int rsa_init(void)
{
	int err;

	err = crypto_register_akcipher(&rsa);
	if (err)
		return err;

	err = crypto_register_template(&rsa_pkcs1pad_tmpl);
	if (err) {
		crypto_unregister_akcipher(&rsa);
		return err;
	}

	return 0;
}

__attribute__((used)) static void rsa_exit(void)
{
	crypto_unregister_template(&rsa_pkcs1pad_tmpl);
	crypto_unregister_akcipher(&rsa);
}

