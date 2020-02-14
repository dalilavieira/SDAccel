#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint32 ;
typedef  int uint16 ;
typedef  int /*<<< orphan*/  sealed_buffer ;
typedef  int /*<<< orphan*/  null_data ;
typedef  int /*<<< orphan*/  hwid ;
struct TYPE_25__ {scalar_t__ p; } ;
typedef  TYPE_1__* STREAM ;
typedef  int /*<<< orphan*/  RD_BOOL ;

/* Variables and functions */
 int BB_CLIENT_MACHINE_NAME_BLOB ; 
 int BB_CLIENT_USER_NAME_BLOB ; 
 int /*<<< orphan*/  False ; 
 int LICENCE_HWID_SIZE ; 
 int LICENCE_SIGNATURE_SIZE ; 
#define  LICENCE_TAG_ERROR_ALERT 132 
 int LICENCE_TAG_LICENCE_INFO ; 
#define  LICENCE_TAG_NEW_LICENCE 131 
 int LICENCE_TAG_NEW_LICENCE_REQUEST ; 
#define  LICENCE_TAG_PLATFORM_CHALLANGE 130 
 int LICENCE_TAG_PLATFORM_CHALLANGE_RESPONSE ; 
#define  LICENCE_TAG_REQUEST 129 
#define  LICENCE_TAG_UPGRADE_LICENCE 128 
 int LICENCE_TOKEN_SIZE ; 
 scalar_t__ RDP_V5 ; 
 int SEC_LICENSE_PKT ; 
 int SEC_MODULUS_SIZE ; 
 int SEC_PADDING_SIZE ; 
 int SEC_RANDOM_SIZE ; 
 void* True ; 
 int /*<<< orphan*/  buf_out_uint32 (int*,int) ; 
 int /*<<< orphan*/  error (char*,int) ; 
 char* g_hostname ; 
 void* g_licence_error_result ; 
 void* g_licence_issued ; 
 scalar_t__ g_licence_key ; 
 int* g_licence_sign_key ; 
 scalar_t__ g_rdp_version ; 
 char* g_username ; 
 int /*<<< orphan*/  in_uint16_le (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint32 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint32_le (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint8p (TYPE_1__*,int*,int) ; 
 int /*<<< orphan*/  in_uint8s (TYPE_1__*,int) ; 
 int load_licence (int**) ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  out_uint16 (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_uint16_le (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint32_le (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_1__*,...) ; 
 int /*<<< orphan*/  out_uint8s (TYPE_1__*,int) ; 
 int /*<<< orphan*/  rdssl_rc4_crypt (void*,char*,char*,int) ; 
 void* rdssl_rc4_info_create () ; 
 int /*<<< orphan*/  rdssl_rc4_info_delete (void*) ; 
 int /*<<< orphan*/  rdssl_rc4_set_key (void*,char*,int) ; 
 int /*<<< orphan*/  s_check_end (TYPE_1__*) ; 
 int /*<<< orphan*/  s_check_rem (TYPE_1__*,int) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_1__*) ; 
 int /*<<< orphan*/  save_licence (scalar_t__,int) ; 
 int /*<<< orphan*/  sec_hash_16 (scalar_t__,int*,int*,int*) ; 
 int /*<<< orphan*/  sec_hash_48 (int*,int*,int*,int*,char) ; 
 TYPE_1__* sec_init (int,int) ; 
 int /*<<< orphan*/  sec_send (TYPE_1__*,int) ; 
 int /*<<< orphan*/  sec_sign (int*,int,int*,int,int*,int) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char*,int) ; 
 int /*<<< orphan*/  unimpl (char*,int) ; 
 int /*<<< orphan*/  warning (char*,...) ; 
 int /*<<< orphan*/  xfree (int*) ; 

__attribute__((used)) static void
licence_generate_keys(uint8 * client_random, uint8 * server_random, uint8 * pre_master_secret)
{
	uint8 master_secret[48];
	uint8 key_block[48];

	/* Generate master secret and then key material */
	sec_hash_48(master_secret, pre_master_secret, client_random, server_random, 'A');
	sec_hash_48(key_block, master_secret, server_random, client_random, 'A');

	/* Store first 16 bytes of session key as MAC secret */
	memcpy(g_licence_sign_key, key_block, 16);

	/* Generate RC4 key from next 16 bytes */
	sec_hash_16(g_licence_key, &key_block[16], client_random, server_random);
}

__attribute__((used)) static void
licence_generate_hwid(uint8 * hwid)
{
	buf_out_uint32(hwid, 2);
	strncpy((char *) (hwid + 4), g_hostname, LICENCE_HWID_SIZE - 4);
}

__attribute__((used)) static void
licence_info(uint8 * client_random, uint8 * rsa_data,
	     uint8 * licence_data, int licence_size, uint8 * hwid, uint8 * signature)
{
	uint32 sec_flags = SEC_LICENSE_PKT;
	uint16 length =
		24 + SEC_RANDOM_SIZE + SEC_MODULUS_SIZE + SEC_PADDING_SIZE +
		licence_size + LICENCE_HWID_SIZE + LICENCE_SIGNATURE_SIZE;
	STREAM s;

	s = sec_init(sec_flags, length + 2);

	out_uint8(s, LICENCE_TAG_LICENCE_INFO);
	out_uint8(s, ((g_rdp_version >= RDP_V5) ? 3 : 2));	/* version */
	out_uint16_le(s, length);

	out_uint32_le(s, 1);
	out_uint16(s, 0);
	out_uint16_le(s, 0x0201);

	out_uint8p(s, client_random, SEC_RANDOM_SIZE);
	out_uint16_le(s, 2);
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
	sec_send(s, sec_flags);
}

__attribute__((used)) static void
licence_send_new_licence_request(uint8 * client_random, uint8 * rsa_data, char *user, char *host)
{
	uint32 sec_flags = SEC_LICENSE_PKT;
	uint16 userlen = strlen(user) + 1;
	uint16 hostlen = strlen(host) + 1;
	uint16 length =
		24 + SEC_RANDOM_SIZE + SEC_MODULUS_SIZE + SEC_PADDING_SIZE + userlen + hostlen;
	STREAM s;

	s = sec_init(sec_flags, length + 2);

	out_uint8(s, LICENCE_TAG_NEW_LICENCE_REQUEST);
	out_uint8(s, ((g_rdp_version >= RDP_V5) ? 3 : 2));	/* version */
	out_uint16_le(s, length);

	out_uint32_le(s, 1);	// KEY_EXCHANGE_ALG_RSA
	out_uint16(s, 0);
	out_uint16_le(s, 0xff01);

	out_uint8p(s, client_random, SEC_RANDOM_SIZE);
	out_uint16_le(s, 2);
	out_uint16_le(s, (SEC_MODULUS_SIZE + SEC_PADDING_SIZE));
	out_uint8p(s, rsa_data, SEC_MODULUS_SIZE);
	out_uint8s(s, SEC_PADDING_SIZE);

	/* Username LICENSE_BINARY_BLOB */
	out_uint16_le(s, BB_CLIENT_USER_NAME_BLOB);
	out_uint16_le(s, userlen);
	out_uint8p(s, user, userlen);

	/* Machinename LICENSE_BINARY_BLOB */
	out_uint16_le(s, BB_CLIENT_MACHINE_NAME_BLOB);
	out_uint16_le(s, hostlen);
	out_uint8p(s, host, hostlen);

	s_mark_end(s);
	sec_send(s, sec_flags);
}

__attribute__((used)) static void
licence_process_request(STREAM s)
{
	uint8 null_data[SEC_MODULUS_SIZE];
	uint8 *server_random;
	uint8 signature[LICENCE_SIGNATURE_SIZE];
	uint8 hwid[LICENCE_HWID_SIZE];
	uint8 *licence_data;
	int licence_size;
	void * crypt_key;

	/* Retrieve the server random from the incoming packet */
	in_uint8p(s, server_random, SEC_RANDOM_SIZE);

	/* We currently use null client keys. This is a bit naughty but, hey,
	   the security of licence negotiation isn't exactly paramount. */
	memset(null_data, 0, sizeof(null_data));
	licence_generate_keys(null_data, server_random, null_data);

	licence_size = load_licence(&licence_data);
	if (licence_size > 0)
	{
		/* Generate a signature for the HWID buffer */
		licence_generate_hwid(hwid);
		sec_sign(signature, 16, g_licence_sign_key, 16, hwid, sizeof(hwid));

		/* Now encrypt the HWID */
		crypt_key = rdssl_rc4_info_create();
		rdssl_rc4_set_key(crypt_key, (char *)g_licence_key, 16);
		rdssl_rc4_crypt(crypt_key, (char *)hwid, (char *)hwid, sizeof(hwid));
		rdssl_rc4_info_delete(crypt_key);

#if WITH_DEBUG
		DEBUG(("Sending licensing PDU (message type 0x%02x)\n", LICENCE_TAG_LICENCE_INFO));
#endif
		licence_info(null_data, null_data, licence_data, licence_size, hwid, signature);

		xfree(licence_data);
		return;
	}

#if WITH_DEBUG
	DEBUG(("Sending licensing PDU (message type 0x%02x)\n", LICENCE_TAG_NEW_LICENCE_REQUEST));
#endif
	licence_send_new_licence_request(null_data, null_data, g_username, g_hostname);
}

__attribute__((used)) static void
licence_send_platform_challenge_response(uint8 * token, uint8 * crypt_hwid, uint8 * signature)
{
	uint32 sec_flags = SEC_LICENSE_PKT;
	uint16 length = 58;
	STREAM s;

	s = sec_init(sec_flags, length + 2);

	out_uint8(s, LICENCE_TAG_PLATFORM_CHALLANGE_RESPONSE);
	out_uint8(s, ((g_rdp_version >= RDP_V5) ? 3 : 2));	/* version */
	out_uint16_le(s, length);

	out_uint16_le(s, 1);
	out_uint16_le(s, LICENCE_TOKEN_SIZE);
	out_uint8p(s, token, LICENCE_TOKEN_SIZE);

	out_uint16_le(s, 1);
	out_uint16_le(s, LICENCE_HWID_SIZE);
	out_uint8p(s, crypt_hwid, LICENCE_HWID_SIZE);

	out_uint8p(s, signature, LICENCE_SIGNATURE_SIZE);

	s_mark_end(s);
	sec_send(s, sec_flags);
}

__attribute__((used)) static RD_BOOL
licence_parse_platform_challenge(STREAM s, uint8 ** token, uint8 ** signature)
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
licence_process_platform_challenge(STREAM s)
{
	uint8 *in_token = NULL, *in_sig;
	uint8 out_token[LICENCE_TOKEN_SIZE], decrypt_token[LICENCE_TOKEN_SIZE];
	uint8 hwid[LICENCE_HWID_SIZE], crypt_hwid[LICENCE_HWID_SIZE];
	uint8 sealed_buffer[LICENCE_TOKEN_SIZE + LICENCE_HWID_SIZE];
	uint8 out_sig[LICENCE_SIGNATURE_SIZE];
	void * crypt_key;

	/* Parse incoming packet and save the encrypted token */
	licence_parse_platform_challenge(s, &in_token, &in_sig);
	memcpy(out_token, in_token, LICENCE_TOKEN_SIZE);

	/* Decrypt the token. It should read TEST in Unicode. */
	crypt_key = rdssl_rc4_info_create();
	rdssl_rc4_set_key(crypt_key, (char *)g_licence_key, 16);
	rdssl_rc4_crypt(crypt_key, (char *)in_token, (char *)decrypt_token, LICENCE_TOKEN_SIZE);
	rdssl_rc4_info_delete(crypt_key);
	
	/* Generate a signature for a buffer of token and HWID */
	licence_generate_hwid(hwid);
	memcpy(sealed_buffer, decrypt_token, LICENCE_TOKEN_SIZE);
	memcpy(sealed_buffer + LICENCE_TOKEN_SIZE, hwid, LICENCE_HWID_SIZE);
	sec_sign(out_sig, 16, g_licence_sign_key, 16, sealed_buffer, sizeof(sealed_buffer));

	/* Now encrypt the HWID */
	crypt_key = rdssl_rc4_info_create();
	rdssl_rc4_set_key(crypt_key, (char *)g_licence_key, 16);
	rdssl_rc4_crypt(crypt_key, (char *)hwid, (char *)crypt_hwid, LICENCE_HWID_SIZE);

	licence_send_platform_challenge_response(out_token, crypt_hwid, out_sig);
}

__attribute__((used)) static void
licence_process_new_license(STREAM s)
{
	void * crypt_key;
	uint32 length;
	int i;

	in_uint8s(s, 2);	// Skip license binary blob type
	in_uint16_le(s, length);
	if (!s_check_rem(s, length))
		return;

	crypt_key = rdssl_rc4_info_create();
	rdssl_rc4_set_key(crypt_key, (char *)g_licence_key, 16);
	rdssl_rc4_crypt(crypt_key, (char *)s->p, (char *)s->p, length);
	rdssl_rc4_info_delete(crypt_key);

	/* Parse NEW_LICENSE_INFO block */
	in_uint8s(s, 4);	// skip dwVersion

	/* Skip strings, Scope, CompanyName and ProductId to get
	   to the LicenseInfo which we store in license blob. */
	length = 0;
	for (i = 0; i < 4; i++)
	{
		in_uint8s(s, length);
		in_uint32_le(s, length);
		if (!s_check_rem(s, length))
			return;
	}

	g_licence_issued = True;
	save_licence(s->p, length);
}

void
licence_process_error_alert(STREAM s)
{
	uint32 error_code;
	uint32 state_transition;
	uint32 error_info;
	in_uint32(s, error_code);
	in_uint32(s, state_transition);
	in_uint32(s, error_info);

	/* There is a special case in the error alert handling, when licensing is all good
	   and the server is not sending a license to client, a "Server License Error PDU -
	   Valid Client" packet is sent which means, every thing is ok.

	   Therefor we should flag that everything is ok with license here.
	 */
	if (error_code == 0x07)
	{
		g_licence_issued = True;
		return;
	}

	/* handle error codes, for now, just report them */
	switch (error_code)
	{
		case 0x6:	// ERR_NO_LICENSE_SERVER
			warning("License error alert from server: No license server\n");
			break;

		case 0x8:	// ERR_INVALID_CLIENT
			warning("License error alert from server: Invalid client\n");
			break;

		case 0x4:	// ERR_INVALID_SCOPE
		case 0xb:	// ERR_INVALID_PRODUCTID
		case 0xc:	// ERR_INVALID_MESSAGE_LENGTH
		default:
			warning("License error alert from server: code %u, state transition %u\n",
				error_code, state_transition);
			break;
	}

	/* handle error codes, for now, just report them */
	switch (error_info)
	{
		default:
			break;
	}

	g_licence_error_result = True;
}

void
licence_process(STREAM s)
{
	uint8 tag;

	in_uint8(s, tag);
	in_uint8s(s, 3);	/* version, length */

#if WITH_DEBUG
	DEBUG(("Received licensing PDU (message type 0x%02x)\n", tag));
#endif

	switch (tag)
	{
		case LICENCE_TAG_REQUEST:
			licence_process_request(s);
			break;

		case LICENCE_TAG_PLATFORM_CHALLANGE:
			licence_process_platform_challenge(s);
			break;

		case LICENCE_TAG_NEW_LICENCE:
		case LICENCE_TAG_UPGRADE_LICENCE:
			/* we can handle new and upgrades of licences the same way. */
			licence_process_new_license(s);
			break;

		case LICENCE_TAG_ERROR_ALERT:
			licence_process_error_alert(s);
			break;

		default:
			unimpl("licence tag 0x%02x\n", tag);
	}
}

