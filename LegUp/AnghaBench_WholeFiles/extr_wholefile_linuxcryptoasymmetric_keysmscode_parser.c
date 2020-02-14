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
struct pefile_context {char* digest_algo; size_t digest_len; int /*<<< orphan*/  digest; } ;
typedef  enum OID { ____Placeholder_OID } OID ;
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int EBADMSG ; 
 int ENOMEM ; 
 int ENOPKG ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
#define  OID__NR 135 
#define  OID_md4 134 
#define  OID_md5 133 
 int OID_msIndividualSPKeyPurpose ; 
 int OID_msPeImageDataObjId ; 
#define  OID_sha1 132 
#define  OID_sha224 131 
#define  OID_sha256 130 
#define  OID_sha384 129 
#define  OID_sha512 128 
 int asn1_ber_decoder (int /*<<< orphan*/ *,struct pefile_context*,void const*,size_t) ; 
 int /*<<< orphan*/  kmemdup (void const*,size_t,int /*<<< orphan*/ ) ; 
 int look_up_OID (void const*,size_t) ; 
 int /*<<< orphan*/  mscode_decoder ; 
 int /*<<< orphan*/  pr_devel (char*,size_t,unsigned int,void const*) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  sprint_oid (void const*,size_t,char*,int) ; 

int mscode_parse(void *_ctx, const void *content_data, size_t data_len,
		 size_t asn1hdrlen)
{
	struct pefile_context *ctx = _ctx;

	content_data -= asn1hdrlen;
	data_len += asn1hdrlen;
	pr_devel("Data: %zu [%*ph]\n", data_len, (unsigned)(data_len),
		 content_data);

	return asn1_ber_decoder(&mscode_decoder, ctx, content_data, data_len);
}

int mscode_note_content_type(void *context, size_t hdrlen,
			     unsigned char tag,
			     const void *value, size_t vlen)
{
	enum OID oid;

	oid = look_up_OID(value, vlen);
	if (oid == OID__NR) {
		char buffer[50];

		sprint_oid(value, vlen, buffer, sizeof(buffer));
		pr_err("Unknown OID: %s\n", buffer);
		return -EBADMSG;
	}

	/*
	 * pesign utility had a bug where it was putting
	 * OID_msIndividualSPKeyPurpose instead of OID_msPeImageDataObjId
	 * So allow both OIDs.
	 */
	if (oid != OID_msPeImageDataObjId &&
	    oid != OID_msIndividualSPKeyPurpose) {
		pr_err("Unexpected content type OID %u\n", oid);
		return -EBADMSG;
	}

	return 0;
}

int mscode_note_digest_algo(void *context, size_t hdrlen,
			    unsigned char tag,
			    const void *value, size_t vlen)
{
	struct pefile_context *ctx = context;
	char buffer[50];
	enum OID oid;

	oid = look_up_OID(value, vlen);
	switch (oid) {
	case OID_md4:
		ctx->digest_algo = "md4";
		break;
	case OID_md5:
		ctx->digest_algo = "md5";
		break;
	case OID_sha1:
		ctx->digest_algo = "sha1";
		break;
	case OID_sha256:
		ctx->digest_algo = "sha256";
		break;
	case OID_sha384:
		ctx->digest_algo = "sha384";
		break;
	case OID_sha512:
		ctx->digest_algo = "sha512";
		break;
	case OID_sha224:
		ctx->digest_algo = "sha224";
		break;

	case OID__NR:
		sprint_oid(value, vlen, buffer, sizeof(buffer));
		pr_err("Unknown OID: %s\n", buffer);
		return -EBADMSG;

	default:
		pr_err("Unsupported content type: %u\n", oid);
		return -ENOPKG;
	}

	return 0;
}

int mscode_note_digest(void *context, size_t hdrlen,
		       unsigned char tag,
		       const void *value, size_t vlen)
{
	struct pefile_context *ctx = context;

	ctx->digest = kmemdup(value, vlen, GFP_KERNEL);
	if (!ctx->digest)
		return -ENOMEM;

	ctx->digest_len = vlen;

	return 0;
}

