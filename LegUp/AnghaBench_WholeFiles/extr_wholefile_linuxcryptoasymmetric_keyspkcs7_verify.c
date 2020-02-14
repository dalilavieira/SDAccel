#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct x509_certificate {int seen; int blacklisted; scalar_t__ valid_from; scalar_t__ valid_to; TYPE_1__* pub; int /*<<< orphan*/  index; struct x509_certificate* signer; struct public_key_signature* sig; int /*<<< orphan*/  subject; TYPE_2__* skid; struct x509_certificate* next; TYPE_2__* id; scalar_t__ unsupported_sig; scalar_t__ self_signed; int /*<<< orphan*/  issuer; scalar_t__ unsupported_key; int /*<<< orphan*/  raw_serial; int /*<<< orphan*/  raw_serial_size; } ;
struct shash_desc {int /*<<< orphan*/  flags; struct crypto_shash* tfm; } ;
struct public_key_signature {scalar_t__ digest_size; struct asymmetric_key_id** auth_ids; int /*<<< orphan*/  pkey_algo; int /*<<< orphan*/  digest; int /*<<< orphan*/  hash_algo; } ;
struct pkcs7_signed_info {scalar_t__ msgdigest_len; int blacklisted; scalar_t__ signing_time; int unsupported_crypto; struct pkcs7_signed_info* next; int /*<<< orphan*/  index; struct public_key_signature* sig; struct x509_certificate* signer; int /*<<< orphan*/  aa_set; int /*<<< orphan*/  authattrs_len; int /*<<< orphan*/  authattrs; int /*<<< orphan*/  msgdigest; } ;
struct pkcs7_message {size_t data_len; void const* data; struct pkcs7_signed_info* signed_infos; int /*<<< orphan*/  data_type; int /*<<< orphan*/  have_authattrs; struct x509_certificate* certs; } ;
struct crypto_shash {int dummy; } ;
struct asymmetric_key_id {int /*<<< orphan*/  data; int /*<<< orphan*/  len; } ;
typedef  enum key_being_used_for { ____Placeholder_key_being_used_for } key_being_used_for ;
struct TYPE_4__ {int /*<<< orphan*/  data; int /*<<< orphan*/  len; } ;
struct TYPE_3__ {int /*<<< orphan*/  pkey_algo; } ;

/* Variables and functions */
 int ASN1_CONS_BIT ; 
 int ASN1_SET ; 
 int /*<<< orphan*/  CRYPTO_TFM_REQ_MAY_SLEEP ; 
 int EBADMSG ; 
 int EINVAL ; 
 int EKEYREJECTED ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOPKG ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct crypto_shash*) ; 
 int /*<<< orphan*/  OID_data ; 
 int /*<<< orphan*/  OID_msIndirectData ; 
 int PTR_ERR (struct crypto_shash*) ; 
#define  VERIFYING_FIRMWARE_SIGNATURE 131 
#define  VERIFYING_KEXEC_PE_SIGNATURE 130 
#define  VERIFYING_MODULE_SIGNATURE 129 
#define  VERIFYING_UNSPECIFIED_SIGNATURE 128 
 scalar_t__ asymmetric_key_id_same (TYPE_2__*,struct asymmetric_key_id*) ; 
 struct crypto_shash* crypto_alloc_shash (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  crypto_free_shash (struct crypto_shash*) ; 
 int crypto_shash_descsize (struct crypto_shash*) ; 
 int crypto_shash_digest (struct shash_desc*,void const*,size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ crypto_shash_digestsize (struct crypto_shash*) ; 
 int crypto_shash_finup (struct shash_desc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int crypto_shash_init (struct shash_desc*) ; 
 int crypto_shash_update (struct shash_desc*,int*,int) ; 
 int /*<<< orphan*/  kenter (char*,...) ; 
 int /*<<< orphan*/  kfree (struct shash_desc*) ; 
 int /*<<< orphan*/  kleave (char*,int) ; 
 int /*<<< orphan*/  kmalloc (scalar_t__,int /*<<< orphan*/ ) ; 
 struct shash_desc* kzalloc (size_t,int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  might_sleep () ; 
 int /*<<< orphan*/  pr_debug (char*,...) ; 
 int /*<<< orphan*/  pr_devel (char*,int,...) ; 
 int /*<<< orphan*/  pr_warn (char*,...) ; 
 int public_key_verify_signature (TYPE_1__*,struct public_key_signature*) ; 
 int /*<<< orphan*/  sinfo_has_signing_time ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ test_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int pkcs7_digest(struct pkcs7_message *pkcs7,
			struct pkcs7_signed_info *sinfo)
{
	struct public_key_signature *sig = sinfo->sig;
	struct crypto_shash *tfm;
	struct shash_desc *desc;
	size_t desc_size;
	int ret;

	kenter(",%u,%s", sinfo->index, sinfo->sig->hash_algo);

	if (!sinfo->sig->hash_algo)
		return -ENOPKG;

	/* Allocate the hashing algorithm we're going to need and find out how
	 * big the hash operational data will be.
	 */
	tfm = crypto_alloc_shash(sinfo->sig->hash_algo, 0, 0);
	if (IS_ERR(tfm))
		return (PTR_ERR(tfm) == -ENOENT) ? -ENOPKG : PTR_ERR(tfm);

	desc_size = crypto_shash_descsize(tfm) + sizeof(*desc);
	sig->digest_size = crypto_shash_digestsize(tfm);

	ret = -ENOMEM;
	sig->digest = kmalloc(sig->digest_size, GFP_KERNEL);
	if (!sig->digest)
		goto error_no_desc;

	desc = kzalloc(desc_size, GFP_KERNEL);
	if (!desc)
		goto error_no_desc;

	desc->tfm   = tfm;
	desc->flags = CRYPTO_TFM_REQ_MAY_SLEEP;

	/* Digest the message [RFC2315 9.3] */
	ret = crypto_shash_digest(desc, pkcs7->data, pkcs7->data_len,
				  sig->digest);
	if (ret < 0)
		goto error;
	pr_devel("MsgDigest = [%*ph]\n", 8, sig->digest);

	/* However, if there are authenticated attributes, there must be a
	 * message digest attribute amongst them which corresponds to the
	 * digest we just calculated.
	 */
	if (sinfo->authattrs) {
		u8 tag;

		if (!sinfo->msgdigest) {
			pr_warn("Sig %u: No messageDigest\n", sinfo->index);
			ret = -EKEYREJECTED;
			goto error;
		}

		if (sinfo->msgdigest_len != sig->digest_size) {
			pr_debug("Sig %u: Invalid digest size (%u)\n",
				 sinfo->index, sinfo->msgdigest_len);
			ret = -EBADMSG;
			goto error;
		}

		if (memcmp(sig->digest, sinfo->msgdigest,
			   sinfo->msgdigest_len) != 0) {
			pr_debug("Sig %u: Message digest doesn't match\n",
				 sinfo->index);
			ret = -EKEYREJECTED;
			goto error;
		}

		/* We then calculate anew, using the authenticated attributes
		 * as the contents of the digest instead.  Note that we need to
		 * convert the attributes from a CONT.0 into a SET before we
		 * hash it.
		 */
		memset(sig->digest, 0, sig->digest_size);

		ret = crypto_shash_init(desc);
		if (ret < 0)
			goto error;
		tag = ASN1_CONS_BIT | ASN1_SET;
		ret = crypto_shash_update(desc, &tag, 1);
		if (ret < 0)
			goto error;
		ret = crypto_shash_finup(desc, sinfo->authattrs,
					 sinfo->authattrs_len, sig->digest);
		if (ret < 0)
			goto error;
		pr_devel("AADigest = [%*ph]\n", 8, sig->digest);
	}

error:
	kfree(desc);
error_no_desc:
	crypto_free_shash(tfm);
	kleave(" = %d", ret);
	return ret;
}

__attribute__((used)) static int pkcs7_find_key(struct pkcs7_message *pkcs7,
			  struct pkcs7_signed_info *sinfo)
{
	struct x509_certificate *x509;
	unsigned certix = 1;

	kenter("%u", sinfo->index);

	for (x509 = pkcs7->certs; x509; x509 = x509->next, certix++) {
		/* I'm _assuming_ that the generator of the PKCS#7 message will
		 * encode the fields from the X.509 cert in the same way in the
		 * PKCS#7 message - but I can't be 100% sure of that.  It's
		 * possible this will need element-by-element comparison.
		 */
		if (!asymmetric_key_id_same(x509->id, sinfo->sig->auth_ids[0]))
			continue;
		pr_devel("Sig %u: Found cert serial match X.509[%u]\n",
			 sinfo->index, certix);

		if (strcmp(x509->pub->pkey_algo, sinfo->sig->pkey_algo) != 0) {
			pr_warn("Sig %u: X.509 algo and PKCS#7 sig algo don't match\n",
				sinfo->index);
			continue;
		}

		sinfo->signer = x509;
		return 0;
	}

	/* The relevant X.509 cert isn't found here, but it might be found in
	 * the trust keyring.
	 */
	pr_debug("Sig %u: Issuing X.509 cert not found (#%*phN)\n",
		 sinfo->index,
		 sinfo->sig->auth_ids[0]->len, sinfo->sig->auth_ids[0]->data);
	return 0;
}

__attribute__((used)) static int pkcs7_verify_sig_chain(struct pkcs7_message *pkcs7,
				  struct pkcs7_signed_info *sinfo)
{
	struct public_key_signature *sig;
	struct x509_certificate *x509 = sinfo->signer, *p;
	struct asymmetric_key_id *auth;
	int ret;

	kenter("");

	for (p = pkcs7->certs; p; p = p->next)
		p->seen = false;

	for (;;) {
		pr_debug("verify %s: %*phN\n",
			 x509->subject,
			 x509->raw_serial_size, x509->raw_serial);
		x509->seen = true;

		if (x509->blacklisted) {
			/* If this cert is blacklisted, then mark everything
			 * that depends on this as blacklisted too.
			 */
			sinfo->blacklisted = true;
			for (p = sinfo->signer; p != x509; p = p->signer)
				p->blacklisted = true;
			pr_debug("- blacklisted\n");
			return 0;
		}

		if (x509->unsupported_key)
			goto unsupported_crypto_in_x509;

		pr_debug("- issuer %s\n", x509->issuer);
		sig = x509->sig;
		if (sig->auth_ids[0])
			pr_debug("- authkeyid.id %*phN\n",
				 sig->auth_ids[0]->len, sig->auth_ids[0]->data);
		if (sig->auth_ids[1])
			pr_debug("- authkeyid.skid %*phN\n",
				 sig->auth_ids[1]->len, sig->auth_ids[1]->data);

		if (x509->self_signed) {
			/* If there's no authority certificate specified, then
			 * the certificate must be self-signed and is the root
			 * of the chain.  Likewise if the cert is its own
			 * authority.
			 */
			if (x509->unsupported_sig)
				goto unsupported_crypto_in_x509;
			x509->signer = x509;
			pr_debug("- self-signed\n");
			return 0;
		}

		/* Look through the X.509 certificates in the PKCS#7 message's
		 * list to see if the next one is there.
		 */
		auth = sig->auth_ids[0];
		if (auth) {
			pr_debug("- want %*phN\n", auth->len, auth->data);
			for (p = pkcs7->certs; p; p = p->next) {
				pr_debug("- cmp [%u] %*phN\n",
					 p->index, p->id->len, p->id->data);
				if (asymmetric_key_id_same(p->id, auth))
					goto found_issuer_check_skid;
			}
		} else if (sig->auth_ids[1]) {
			auth = sig->auth_ids[1];
			pr_debug("- want %*phN\n", auth->len, auth->data);
			for (p = pkcs7->certs; p; p = p->next) {
				if (!p->skid)
					continue;
				pr_debug("- cmp [%u] %*phN\n",
					 p->index, p->skid->len, p->skid->data);
				if (asymmetric_key_id_same(p->skid, auth))
					goto found_issuer;
			}
		}

		/* We didn't find the root of this chain */
		pr_debug("- top\n");
		return 0;

	found_issuer_check_skid:
		/* We matched issuer + serialNumber, but if there's an
		 * authKeyId.keyId, that must match the CA subjKeyId also.
		 */
		if (sig->auth_ids[1] &&
		    !asymmetric_key_id_same(p->skid, sig->auth_ids[1])) {
			pr_warn("Sig %u: X.509 chain contains auth-skid nonmatch (%u->%u)\n",
				sinfo->index, x509->index, p->index);
			return -EKEYREJECTED;
		}
	found_issuer:
		pr_debug("- subject %s\n", p->subject);
		if (p->seen) {
			pr_warn("Sig %u: X.509 chain contains loop\n",
				sinfo->index);
			return 0;
		}
		ret = public_key_verify_signature(p->pub, x509->sig);
		if (ret < 0)
			return ret;
		x509->signer = p;
		if (x509 == p) {
			pr_debug("- self-signed\n");
			return 0;
		}
		x509 = p;
		might_sleep();
	}

unsupported_crypto_in_x509:
	/* Just prune the certificate chain at this point if we lack some
	 * crypto module to go further.  Note, however, we don't want to set
	 * sinfo->unsupported_crypto as the signed info block may still be
	 * validatable against an X.509 cert lower in the chain that we have a
	 * trusted copy of.
	 */
	return 0;
}

__attribute__((used)) static int pkcs7_verify_one(struct pkcs7_message *pkcs7,
			    struct pkcs7_signed_info *sinfo)
{
	int ret;

	kenter(",%u", sinfo->index);

	/* First of all, digest the data in the PKCS#7 message and the
	 * signed information block
	 */
	ret = pkcs7_digest(pkcs7, sinfo);
	if (ret < 0)
		return ret;

	/* Find the key for the signature if there is one */
	ret = pkcs7_find_key(pkcs7, sinfo);
	if (ret < 0)
		return ret;

	if (!sinfo->signer)
		return 0;

	pr_devel("Using X.509[%u] for sig %u\n",
		 sinfo->signer->index, sinfo->index);

	/* Check that the PKCS#7 signing time is valid according to the X.509
	 * certificate.  We can't, however, check against the system clock
	 * since that may not have been set yet and may be wrong.
	 */
	if (test_bit(sinfo_has_signing_time, &sinfo->aa_set)) {
		if (sinfo->signing_time < sinfo->signer->valid_from ||
		    sinfo->signing_time > sinfo->signer->valid_to) {
			pr_warn("Message signed outside of X.509 validity window\n");
			return -EKEYREJECTED;
		}
	}

	/* Verify the PKCS#7 binary against the key */
	ret = public_key_verify_signature(sinfo->signer->pub, sinfo->sig);
	if (ret < 0)
		return ret;

	pr_devel("Verified signature %u\n", sinfo->index);

	/* Verify the internal certificate chain */
	return pkcs7_verify_sig_chain(pkcs7, sinfo);
}

int pkcs7_verify(struct pkcs7_message *pkcs7,
		 enum key_being_used_for usage)
{
	struct pkcs7_signed_info *sinfo;
	int actual_ret = -ENOPKG;
	int ret;

	kenter("");

	switch (usage) {
	case VERIFYING_MODULE_SIGNATURE:
		if (pkcs7->data_type != OID_data) {
			pr_warn("Invalid module sig (not pkcs7-data)\n");
			return -EKEYREJECTED;
		}
		if (pkcs7->have_authattrs) {
			pr_warn("Invalid module sig (has authattrs)\n");
			return -EKEYREJECTED;
		}
		break;
	case VERIFYING_FIRMWARE_SIGNATURE:
		if (pkcs7->data_type != OID_data) {
			pr_warn("Invalid firmware sig (not pkcs7-data)\n");
			return -EKEYREJECTED;
		}
		if (!pkcs7->have_authattrs) {
			pr_warn("Invalid firmware sig (missing authattrs)\n");
			return -EKEYREJECTED;
		}
		break;
	case VERIFYING_KEXEC_PE_SIGNATURE:
		if (pkcs7->data_type != OID_msIndirectData) {
			pr_warn("Invalid kexec sig (not Authenticode)\n");
			return -EKEYREJECTED;
		}
		/* Authattr presence checked in parser */
		break;
	case VERIFYING_UNSPECIFIED_SIGNATURE:
		if (pkcs7->data_type != OID_data) {
			pr_warn("Invalid unspecified sig (not pkcs7-data)\n");
			return -EKEYREJECTED;
		}
		break;
	default:
		return -EINVAL;
	}

	for (sinfo = pkcs7->signed_infos; sinfo; sinfo = sinfo->next) {
		ret = pkcs7_verify_one(pkcs7, sinfo);
		if (sinfo->blacklisted) {
			if (actual_ret == -ENOPKG)
				actual_ret = -EKEYREJECTED;
			continue;
		}
		if (ret < 0) {
			if (ret == -ENOPKG) {
				sinfo->unsupported_crypto = true;
				continue;
			}
			kleave(" = %d", ret);
			return ret;
		}
		actual_ret = 0;
	}

	kleave(" = %d", actual_ret);
	return actual_ret;
}

int pkcs7_supply_detached_data(struct pkcs7_message *pkcs7,
			       const void *data, size_t datalen)
{
	if (pkcs7->data) {
		pr_debug("Data already supplied\n");
		return -EINVAL;
	}
	pkcs7->data = data;
	pkcs7->data_len = datalen;
	return 0;
}

