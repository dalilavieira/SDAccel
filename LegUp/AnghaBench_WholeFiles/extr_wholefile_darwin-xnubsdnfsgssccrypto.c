#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct ccmode_cbc {int dummy; } ;
struct ccdigest_info {int dummy; } ;
typedef  int /*<<< orphan*/  cccbc_iv ;
typedef  int /*<<< orphan*/  cccbc_ctx ;
struct TYPE_2__ {size_t (* ccpad_cts3_decrypt_fn ) (struct ccmode_cbc const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t,void const*,void*) ;size_t (* ccpad_cts3_encrypt_fn ) (struct ccmode_cbc const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t,void const*,void*) ;int /*<<< orphan*/  (* ccdes_key_set_odd_parity_fn ) (void*,unsigned long) ;struct ccdigest_info const* ccsha1_di; struct ccmode_cbc const* cctdes_cbc_encrypt; struct ccmode_cbc const* cctdes_cbc_decrypt; struct ccmode_cbc const* ccaes_cbc_encrypt; struct ccmode_cbc const* ccaes_cbc_decrypt; } ;

/* Variables and functions */
 TYPE_1__* g_crypto_funcs ; 
 size_t stub1 (struct ccmode_cbc const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t,void const*,void*) ; 
 size_t stub2 (struct ccmode_cbc const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t,void const*,void*) ; 
 int /*<<< orphan*/  stub3 (void*,unsigned long) ; 

int
corecrypto_available(void)
{
	return (g_crypto_funcs ? 1 : 0);
}

const struct ccmode_cbc  *
ccaes_cbc_decrypt_mode(void)
{
	if (g_crypto_funcs)
		return (g_crypto_funcs->ccaes_cbc_decrypt);
	return (NULL);
}

const struct ccmode_cbc  *
ccaes_cbc_encrypt_mode(void)
{
	if (g_crypto_funcs)
		return (g_crypto_funcs->ccaes_cbc_encrypt);
	return (NULL);
}

const struct ccmode_cbc  *
ccdes3_cbc_decrypt_mode(void)
{
	if (g_crypto_funcs)
		return (g_crypto_funcs->cctdes_cbc_decrypt);
	return (NULL);
}

const struct ccmode_cbc *
ccdes3_cbc_encrypt_mode(void)
{
	if (g_crypto_funcs)
		return (g_crypto_funcs->cctdes_cbc_encrypt);
	return (NULL);
}

size_t
ccpad_cts3_decrypt(const struct ccmode_cbc *cbc, cccbc_ctx *cbc_key,
		   cccbc_iv *iv, size_t nbytes, const void *in, void *out)
{
	if (g_crypto_funcs)
		return (*g_crypto_funcs->ccpad_cts3_decrypt_fn)(cbc, cbc_key, iv, nbytes, in, out);
	return (0);
}

size_t
ccpad_cts3_encrypt(const struct ccmode_cbc *cbc, cccbc_ctx *cbc_key,
		   cccbc_iv *iv, size_t nbytes, const void *in, void *out)
{
	if (g_crypto_funcs)
		return (*g_crypto_funcs->ccpad_cts3_encrypt_fn)(cbc, cbc_key, iv, nbytes, in, out);
	return (0);
}

const struct ccdigest_info *
ccsha1_di(void)
{
	if (g_crypto_funcs)
		return (g_crypto_funcs->ccsha1_di);
	return (NULL);
}

void ccdes_key_set_odd_parity(void *key, unsigned long length)
{
	if (g_crypto_funcs)
		(*g_crypto_funcs->ccdes_key_set_odd_parity_fn)(key, length);
}

