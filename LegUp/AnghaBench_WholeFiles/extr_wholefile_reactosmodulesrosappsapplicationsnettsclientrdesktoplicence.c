#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_3__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint32 ;
typedef  int uint16 ;
typedef  int /*<<< orphan*/  sealed_buffer ;
typedef  int /*<<< orphan*/  null_data ;
typedef  int /*<<< orphan*/  hwid ;
struct TYPE_39__ {int* sign_key; int /*<<< orphan*/  key; } ;
struct TYPE_41__ {char* licence_hostname; char* licence_username; void* licence_issued; TYPE_1__ licence; } ;
struct TYPE_40__ {int* p; } ;
typedef  TYPE_2__* STREAM ;
typedef  TYPE_3__ RDPCLIENT ;
typedef  int /*<<< orphan*/  RC4_KEY ;
typedef  void* BOOL ;

/* Variables and functions */
 void* False ; 
 int LICENCE_HWID_SIZE ; 
 int LICENCE_SIGNATURE_SIZE ; 
#define  LICENCE_TAG_AUTHREQ 132 
 int LICENCE_TAG_AUTHRESP ; 
#define  LICENCE_TAG_DEMAND 131 
 int LICENCE_TAG_HOST ; 
#define  LICENCE_TAG_ISSUE 130 
 int LICENCE_TAG_PRESENT ; 
#define  LICENCE_TAG_REISSUE 129 
 int LICENCE_TAG_REQUEST ; 
#define  LICENCE_TAG_RESULT 128 
 int LICENCE_TAG_USER ; 
 int LICENCE_TOKEN_SIZE ; 
 int /*<<< orphan*/  RC4 (int /*<<< orphan*/ *,int,int*,int*) ; 
 int /*<<< orphan*/  RC4_set_key (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int SEC_LICENCE_NEG ; 
 int SEC_MODULUS_SIZE ; 
 int SEC_PADDING_SIZE ; 
 int SEC_RANDOM_SIZE ; 
 void* True ; 
 int /*<<< orphan*/  buf_out_uint32 (int*,int) ; 
 int /*<<< orphan*/  error (char*,int) ; 
 int /*<<< orphan*/  free (int*) ; 
 int /*<<< orphan*/  in_uint16 (TYPE_2__*,int) ; 
 int /*<<< orphan*/  in_uint16_le (TYPE_2__*,int) ; 
 int /*<<< orphan*/  in_uint32_le (TYPE_2__*,int) ; 
 int /*<<< orphan*/  in_uint8 (TYPE_2__*,int) ; 
 int /*<<< orphan*/  in_uint8p (TYPE_2__*,int*,int) ; 
 int /*<<< orphan*/  in_uint8s (TYPE_2__*,int) ; 
 int load_licence (TYPE_3__*,int**) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint16 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_uint16_le (TYPE_2__*,int) ; 
 int /*<<< orphan*/  out_uint32_le (TYPE_2__*,int) ; 
 int /*<<< orphan*/  out_uint8 (TYPE_2__*,int) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_2__*,...) ; 
 int /*<<< orphan*/  out_uint8s (TYPE_2__*,int) ; 
 void* s_check_end (TYPE_2__*) ; 
 int /*<<< orphan*/  s_check_rem (TYPE_2__*,int) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_2__*) ; 
 int /*<<< orphan*/  save_licence (TYPE_3__*,int*,int) ; 
 int /*<<< orphan*/  sec_hash_16 (int /*<<< orphan*/ ,int*,int*,int*) ; 
 int /*<<< orphan*/  sec_hash_48 (int*,int*,int*,int*,char) ; 
 TYPE_2__* sec_init (TYPE_3__*,int,int) ; 
 void* sec_send (TYPE_3__*,TYPE_2__*,int) ; 
 int /*<<< orphan*/  sec_sign (int*,int,int*,int,int*,int) ; 
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char*,int) ; 
 int /*<<< orphan*/  unimpl (char*,int) ; 

__attribute__((used)) static void
licence_generate_keys(RDPCLIENT * This, uint8 * client_random, uint8 * server_random, uint8 * pre_master_secret)
{
	uint8 master_secret[48];
	uint8 key_block[48];

	/* Generate master secret and then key material */
	sec_hash_48(master_secret, pre_master_secret, client_random, server_random, 'A');
	sec_hash_48(key_block, master_secret, server_random, client_random, 'A');

	/* Store first 16 bytes of session key as MAC secret */
	memcpy(This->licence.sign_key, key_block, 16);

	/* Generate RC4 key from next 16 bytes */
	sec_hash_16(This->licence.key, &key_block[16], client_random, server_random);
}

__attribute__((used)) static void
licence_generate_hwid(RDPCLIENT * This, uint8 * hwid)
{
	buf_out_uint32(hwid, 2);
	strncpy((char *) (hwid + 4), This->licence_hostname, LICENCE_HWID_SIZE - 4);
}

__attribute__((used)) static BOOL
licence_present(RDPCLIENT * This, uint8 * client_random, uint8 * rsa_data,
		uint8 * licence_data, int licence_size, uint8 * hwid, uint8 * signature)
{
	uint32 sec_flags = SEC_LICENCE_NEG;
	uint16 length =
		16 + SEC_RANDOM_SIZE + SEC_MODULUS_SIZE + SEC_PADDING_SIZE +
		licence_size + LICENCE_HWID_SIZE + LICENCE_SIGNATURE_SIZE;
	STREAM s;

	s = sec_init(This, sec_flags, length + 4);

	if(s == NULL)
		return False;

	out_uint8(s, LICENCE_TAG_PRESENT);
	out_uint8(s, 2);	/* version */
	out_uint16_le(s, length);

	out_uint32_le(s, 1);
	out_uint16(s, 0);
	out_uint16_le(s, 0x0201);

	out_uint8p(s, client_random, SEC_RANDOM_SIZE);
	out_uint16(s, 0);
	out_uint16_le(s, (SEC_MODULUS_SIZE + SEC_PADDING_SIZE));
	out_uint8p(s, rsa_data, SEC_MODULUS_SIZE);
	out_uint8s(s, SEC_PADDING_SIZE);

	out_uint16_le(s, 1);
	out_uint16_le(s, licence_size);
	out_uint8p(s, licence_data, licence_size);

	out_uint16_le(s, 1);
	out_uint16_le(s, LICENCE_HWID_SIZE);
	out_uint8p(s, hwid, LICENCE_HWID_SIZE);

	out_uint8p(s, signature, LICENCE_SIGNATURE_SIZE);

	s_mark_end(s);
	return sec_send(This, s, sec_flags);
}

__attribute__((used)) static BOOL
licence_send_request(RDPCLIENT * This, uint8 * client_random, uint8 * rsa_data, char *user, char *host)
{
	uint32 sec_flags = SEC_LICENCE_NEG;
	uint16 userlen = (uint16)strlen(user) + 1;
	uint16 hostlen = (uint16)strlen(host) + 1;
	uint16 length = 128 + userlen + hostlen;
	STREAM s;

	s = sec_init(This, sec_flags, length + 2);

	if(s == NULL)
		return False;

	out_uint8(s, LICENCE_TAG_REQUEST);
	out_uint8(s, 2);	/* version */
	out_uint16_le(s, length);

	out_uint32_le(s, 1);
	out_uint16(s, 0);
	out_uint16_le(s, 0xff01);

	out_uint8p(s, client_random, SEC_RANDOM_SIZE);
	out_uint16(s, 0);
	out_uint16_le(s, (SEC_MODULUS_SIZE + SEC_PADDING_SIZE));
	out_uint8p(s, rsa_data, SEC_MODULUS_SIZE);
	out_uint8s(s, SEC_PADDING_SIZE);

	out_uint16_le(s, LICENCE_TAG_USER);
	out_uint16_le(s, userlen);
	out_uint8p(s, user, userlen);

	out_uint16_le(s, LICENCE_TAG_HOST);
	out_uint16_le(s, hostlen);
	out_uint8p(s, host, hostlen);

	s_mark_end(s);
	return sec_send(This, s, sec_flags);
}

__attribute__((used)) static BOOL
licence_process_demand(RDPCLIENT * This, STREAM s)
{
	uint8 null_data[SEC_MODULUS_SIZE];
	uint8 *server_random;
	uint8 signature[LICENCE_SIGNATURE_SIZE];
	uint8 hwid[LICENCE_HWID_SIZE];
	uint8 *licence_data;
	int licence_size;
	RC4_KEY crypt_key;

	/* Retrieve the server random from the incoming packet */
	in_uint8p(s, server_random, SEC_RANDOM_SIZE);

	/* We currently use null client keys. This is a bit naughty but, hey,
	   the security of licence negotiation isn't exactly paramount. */
	memset(null_data, 0, sizeof(null_data));
	licence_generate_keys(This, null_data, server_random, null_data);

	licence_size = load_licence(This, &licence_data);
	if (licence_size > 0)
	{
		/* Generate a signature for the HWID buffer */
		licence_generate_hwid(This, hwid);
		sec_sign(signature, 16, This->licence.sign_key, 16, hwid, sizeof(hwid));

		/* Now encrypt the HWID */
		RC4_set_key(&crypt_key, 16, This->licence.key);
		RC4(&crypt_key, sizeof(hwid), hwid, hwid);

		if(!licence_present(This, null_data, null_data, licence_data, licence_size, hwid, signature))
			return False;

		free(licence_data);
		return True;
	}

	return licence_send_request(This, null_data, null_data, This->licence_username, This->licence_hostname);
}

__attribute__((used)) static BOOL
licence_send_authresp(RDPCLIENT * This, uint8 * token, uint8 * crypt_hwid, uint8 * signature)
{
	uint32 sec_flags = SEC_LICENCE_NEG;
	uint16 length = 58;
	STREAM s;

	s = sec_init(This, sec_flags, length + 2);

	if(s == NULL)
		return False;

	out_uint8(s, LICENCE_TAG_AUTHRESP);
	out_uint8(s, 2);	/* version */
	out_uint16_le(s, length);

	out_uint16_le(s, 1);
	out_uint16_le(s, LICENCE_TOKEN_SIZE);
	out_uint8p(s, token, LICENCE_TOKEN_SIZE);

	out_uint16_le(s, 1);
	out_uint16_le(s, LICENCE_HWID_SIZE);
	out_uint8p(s, crypt_hwid, LICENCE_HWID_SIZE);

	out_uint8p(s, signature, LICENCE_SIGNATURE_SIZE);

	s_mark_end(s);
	return sec_send(This, s, sec_flags);
}

__attribute__((used)) static BOOL
licence_parse_authreq(STREAM s, uint8 ** token, uint8 ** signature)
{
	uint16 tokenlen;

	in_uint8s(s, 6);	/* unknown: f8 3d 15 00 04 f6 */

	in_uint16_le(s, tokenlen);
	if (tokenlen != LICENCE_TOKEN_SIZE)
	{
		error("token len %d\n", tokenlen);
		return False;
	}

	in_uint8p(s, *token, tokenlen);
	in_uint8p(s, *signature, LICENCE_SIGNATURE_SIZE);

	return s_check_end(s);
}

__attribute__((used)) static void
licence_process_authreq(RDPCLIENT * This, STREAM s)
{
	uint8 *in_token, *in_sig;
	uint8 out_token[LICENCE_TOKEN_SIZE], decrypt_token[LICENCE_TOKEN_SIZE];
	uint8 hwid[LICENCE_HWID_SIZE], crypt_hwid[LICENCE_HWID_SIZE];
	uint8 sealed_buffer[LICENCE_TOKEN_SIZE + LICENCE_HWID_SIZE];
	uint8 out_sig[LICENCE_SIGNATURE_SIZE];
	RC4_KEY crypt_key;

	/* Parse incoming packet and save the encrypted token */
	licence_parse_authreq(s, &in_token, &in_sig);
	memcpy(out_token, in_token, LICENCE_TOKEN_SIZE);

	/* Decrypt the token. It should read TEST in Unicode. */
	RC4_set_key(&crypt_key, 16, This->licence.key);
	RC4(&crypt_key, LICENCE_TOKEN_SIZE, in_token, decrypt_token);

	/* Generate a signature for a buffer of token and HWID */
	licence_generate_hwid(This, hwid);
	memcpy(sealed_buffer, decrypt_token, LICENCE_TOKEN_SIZE);
	memcpy(sealed_buffer + LICENCE_TOKEN_SIZE, hwid, LICENCE_HWID_SIZE);
	sec_sign(out_sig, 16, This->licence.sign_key, 16, sealed_buffer, sizeof(sealed_buffer));

	/* Now encrypt the HWID */
	RC4_set_key(&crypt_key, 16, This->licence.key);
	RC4(&crypt_key, LICENCE_HWID_SIZE, hwid, crypt_hwid);

	licence_send_authresp(This, out_token, crypt_hwid, out_sig);
}

__attribute__((used)) static void
licence_process_issue(RDPCLIENT * This, STREAM s)
{
	RC4_KEY crypt_key;
	uint32 length;
	uint16 check;
	int i;

	in_uint8s(s, 2);	/* 3d 45 - unknown */
	in_uint16_le(s, length);
	if (!s_check_rem(s, length))
		return;

	RC4_set_key(&crypt_key, 16, This->licence.key);
	RC4(&crypt_key, length, s->p, s->p);

	in_uint16(s, check);
	if (check != 0)
		return;

	This->licence_issued = True;

	in_uint8s(s, 2);	/* pad */

	/* advance to fourth string */
	length = 0;
	for (i = 0; i < 4; i++)
	{
		in_uint8s(s, length);
		in_uint32_le(s, length);
		if (!s_check_rem(s, length))
			return;
	}

	This->licence_issued = True;
	save_licence(This, s->p, length);
}

void
licence_process(RDPCLIENT * This, STREAM s)
{
	uint8 tag;

	in_uint8(s, tag);
	in_uint8s(s, 3);	/* version, length */

	switch (tag)
	{
		case LICENCE_TAG_DEMAND:
			licence_process_demand(This, s);
			break;

		case LICENCE_TAG_AUTHREQ:
			licence_process_authreq(This, s);
			break;

		case LICENCE_TAG_ISSUE:
			licence_process_issue(This, s);
			break;

		case LICENCE_TAG_REISSUE:
		case LICENCE_TAG_RESULT:
			break;

		default:
			unimpl("licence tag 0x%x\n", tag);
	}
}

