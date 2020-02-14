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
typedef  int /*<<< orphan*/  u64 ;
struct scatterlist {int dummy; } ;
struct kpp_request {int dummy; } ;
struct ecdh_completion {int err; int /*<<< orphan*/  completion; } ;
struct ecdh {int key_size; int /*<<< orphan*/ * key; int /*<<< orphan*/  curve_id; int /*<<< orphan*/  member_0; } ;
struct crypto_kpp {int dummy; } ;
struct crypto_async_request {struct ecdh_completion* data; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_TFM_REQ_MAY_BACKLOG ; 
 int /*<<< orphan*/  ECC_CURVE_NIST_P256 ; 
 int EINPROGRESS ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  __swab64 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int crypto_ecdh_encode_key (int /*<<< orphan*/ *,unsigned int,struct ecdh*) ; 
 unsigned int crypto_ecdh_key_len (struct ecdh*) ; 
 int crypto_kpp_compute_shared_secret (struct kpp_request*) ; 
 int crypto_kpp_generate_public_key (struct kpp_request*) ; 
 int crypto_kpp_set_secret (struct crypto_kpp*,int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  kfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * kmalloc (int,int /*<<< orphan*/ ) ; 
 struct kpp_request* kpp_request_alloc (struct crypto_kpp*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kpp_request_free (struct kpp_request*) ; 
 int /*<<< orphan*/  kpp_request_set_callback (struct kpp_request*,int /*<<< orphan*/ ,void (*) (struct crypto_async_request*,int),struct ecdh_completion*) ; 
 int /*<<< orphan*/  kpp_request_set_input (struct kpp_request*,struct scatterlist*,int) ; 
 int /*<<< orphan*/  kpp_request_set_output (struct kpp_request*,struct scatterlist*,int) ; 
 int /*<<< orphan*/  kzfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  pr_err (char*,int) ; 
 int /*<<< orphan*/  sg_init_one (struct scatterlist*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  wait_for_completion (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void ecdh_complete(struct crypto_async_request *req, int err)
{
	struct ecdh_completion *res = req->data;

	if (err == -EINPROGRESS)
		return;

	res->err = err;
	complete(&res->completion);
}

__attribute__((used)) static inline void swap_digits(u64 *in, u64 *out, unsigned int ndigits)
{
	int i;

	for (i = 0; i < ndigits; i++)
		out[i] = __swab64(in[ndigits - 1 - i]);
}

int compute_ecdh_secret(struct crypto_kpp *tfm, const u8 public_key[64],
			u8 secret[32])
{
	struct kpp_request *req;
	u8 *tmp;
	struct ecdh_completion result;
	struct scatterlist src, dst;
	int err;

	tmp = kmalloc(64, GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;

	req = kpp_request_alloc(tfm, GFP_KERNEL);
	if (!req) {
		err = -ENOMEM;
		goto free_tmp;
	}

	init_completion(&result.completion);

	swap_digits((u64 *)public_key, (u64 *)tmp, 4); /* x */
	swap_digits((u64 *)&public_key[32], (u64 *)&tmp[32], 4); /* y */

	sg_init_one(&src, tmp, 64);
	sg_init_one(&dst, secret, 32);
	kpp_request_set_input(req, &src, 64);
	kpp_request_set_output(req, &dst, 32);
	kpp_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG,
				 ecdh_complete, &result);
	err = crypto_kpp_compute_shared_secret(req);
	if (err == -EINPROGRESS) {
		wait_for_completion(&result.completion);
		err = result.err;
	}
	if (err < 0) {
		pr_err("alg: ecdh: compute shared secret failed. err %d\n",
		       err);
		goto free_all;
	}

	swap_digits((u64 *)secret, (u64 *)tmp, 4);
	memcpy(secret, tmp, 32);

free_all:
	kpp_request_free(req);
free_tmp:
	kzfree(tmp);
	return err;
}

int set_ecdh_privkey(struct crypto_kpp *tfm, const u8 private_key[32])
{
	u8 *buf, *tmp = NULL;
	unsigned int buf_len;
	int err;
	struct ecdh p = {0};

	p.curve_id = ECC_CURVE_NIST_P256;

	if (private_key) {
		tmp = kmalloc(32, GFP_KERNEL);
		if (!tmp)
			return -ENOMEM;
		swap_digits((u64 *)private_key, (u64 *)tmp, 4);
		p.key = tmp;
		p.key_size = 32;
	}

	buf_len = crypto_ecdh_key_len(&p);
	buf = kmalloc(buf_len, GFP_KERNEL);
	if (!buf) {
		err = -ENOMEM;
		goto free_tmp;
	}

	err = crypto_ecdh_encode_key(buf, buf_len, &p);
	if (err)
		goto free_all;

	err = crypto_kpp_set_secret(tfm, buf, buf_len);
	/* fall through */
free_all:
	kzfree(buf);
free_tmp:
	kzfree(tmp);
	return err;
}

int generate_ecdh_public_key(struct crypto_kpp *tfm, u8 public_key[64])
{
	struct kpp_request *req;
	u8 *tmp;
	struct ecdh_completion result;
	struct scatterlist dst;
	int err;

	tmp = kmalloc(64, GFP_KERNEL);
	if (!tmp)
		return -ENOMEM;

	req = kpp_request_alloc(tfm, GFP_KERNEL);
	if (!req) {
		err = -ENOMEM;
		goto free_tmp;
	}

	init_completion(&result.completion);
	sg_init_one(&dst, tmp, 64);
	kpp_request_set_input(req, NULL, 0);
	kpp_request_set_output(req, &dst, 64);
	kpp_request_set_callback(req, CRYPTO_TFM_REQ_MAY_BACKLOG,
				 ecdh_complete, &result);

	err = crypto_kpp_generate_public_key(req);
	if (err == -EINPROGRESS) {
		wait_for_completion(&result.completion);
		err = result.err;
	}
	if (err < 0)
		goto free_all;

	/* The public key is handed back in little endian as expected by
	 * the Security Manager Protocol.
	 */
	swap_digits((u64 *)tmp, (u64 *)public_key, 4); /* x */
	swap_digits((u64 *)&tmp[32], (u64 *)&public_key[32], 4); /* y */

free_all:
	kpp_request_free(req);
free_tmp:
	kfree(tmp);
	return err;
}

int generate_ecdh_keys(struct crypto_kpp *tfm, u8 public_key[64])
{
	int err;

	err = set_ecdh_privkey(tfm, NULL);
	if (err)
		return err;

	return generate_ecdh_public_key(tfm, public_key);
}

