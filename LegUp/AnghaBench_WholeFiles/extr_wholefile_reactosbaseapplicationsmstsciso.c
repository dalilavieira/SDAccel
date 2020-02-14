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
struct TYPE_25__ {int end; int p; } ;
typedef  TYPE_1__* STREAM ;
typedef  scalar_t__ RD_BOOL ;

/* Variables and functions */
 scalar_t__ False ; 
#define  HYBRID_REQUIRED_BY_SERVER 133 
#define  INCONSISTENT_FLAGS 132 
 int ISO_PDU_CC ; 
 int ISO_PDU_CR ; 
 int ISO_PDU_DR ; 
 int ISO_PDU_DT ; 
 int PROTOCOL_RDP ; 
 int PROTOCOL_SSL ; 
 int RDP_NEG_FAILURE ; 
 int RDP_NEG_REQ ; 
 int RDP_NEG_RSP ; 
 scalar_t__ RDP_V5 ; 
#define  SSL_CERT_NOT_ON_SERVER 131 
#define  SSL_NOT_ALLOWED_BY_SERVER 130 
#define  SSL_REQUIRED_BY_SERVER 129 
#define  SSL_WITH_USER_AUTH_REQUIRED_BY_SERVER 128 
 scalar_t__ True ; 
 int /*<<< orphan*/  error (char*,...) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  g_encryption ; 
 int /*<<< orphan*/  g_encryption_initial ; 
 scalar_t__ g_negotiate_rdp_protocol ; 
 scalar_t__ g_rdp_version ; 
 int /*<<< orphan*/  in_uint16 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint16_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint32 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint8s (TYPE_1__*,int) ; 
 int /*<<< orphan*/  iso_hdr ; 
 int /*<<< orphan*/  next_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint16 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint16_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint32 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_1__*,char*,int) ; 
 scalar_t__ s_check_rem (TYPE_1__*,int) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_1__*) ; 
 int /*<<< orphan*/  s_pop_layer (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s_push_layer (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stderr ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  tcp_connect (char*) ; 
 int /*<<< orphan*/  tcp_disconnect () ; 
 TYPE_1__* tcp_init (int) ; 
 TYPE_1__* tcp_recv (TYPE_1__*,int) ; 
 int /*<<< orphan*/  tcp_reset_state () ; 
 int /*<<< orphan*/  tcp_send (TYPE_1__*) ; 

__attribute__((used)) static void
iso_send_msg(uint8 code)
{
	STREAM s;

	s = tcp_init(11);

	out_uint8(s, 3);	/* version */
	out_uint8(s, 0);	/* reserved */
	out_uint16_be(s, 11);	/* length */

	out_uint8(s, 6);	/* hdrlen */
	out_uint8(s, code);
	out_uint16(s, 0);	/* dst_ref */
	out_uint16(s, 0);	/* src_ref */
	out_uint8(s, 0);	/* class */

	s_mark_end(s);
	tcp_send(s);
}

__attribute__((used)) static void
iso_send_connection_request(char *username, uint32 neg_proto)
{
	STREAM s;
	int length = 30 + strlen(username);

	if (g_rdp_version >= RDP_V5 && g_negotiate_rdp_protocol)
		length += 8;

	s = tcp_init(length);

	out_uint8(s, 3);	/* version */
	out_uint8(s, 0);	/* reserved */
	out_uint16_be(s, length);	/* length */

	out_uint8(s, length - 5);	/* hdrlen */
	out_uint8(s, ISO_PDU_CR);
	out_uint16(s, 0);	/* dst_ref */
	out_uint16(s, 0);	/* src_ref */
	out_uint8(s, 0);	/* class */

	out_uint8p(s, "Cookie: mstshash=", strlen("Cookie: mstshash="));
	out_uint8p(s, username, strlen(username));

	out_uint8(s, 0x0d);	/* cookie termination string: CR+LF */
	out_uint8(s, 0x0a);

	if (g_rdp_version >= RDP_V5 && g_negotiate_rdp_protocol)
	{
		/* optional rdp protocol negotiation request for RDPv5 */
		out_uint8(s, RDP_NEG_REQ);
		out_uint8(s, 0);
		out_uint16(s, 8);
		out_uint32(s, neg_proto);
	}

	s_mark_end(s);
	tcp_send(s);
}

__attribute__((used)) static STREAM
iso_recv_msg(uint8 * code, uint8 * rdpver)
{
	STREAM s;
	uint16 length;
	uint8 version;

	s = tcp_recv(NULL, 4);
	if (s == NULL)
		return NULL;
	in_uint8(s, version);
	if (rdpver != NULL)
		*rdpver = version;
	if (version == 3)
	{
		in_uint8s(s, 1);	/* pad */
		in_uint16_be(s, length);
	}
	else
	{
		in_uint8(s, length);
		if (length & 0x80)
		{
			length &= ~0x80;
			next_be(s, length);
		}
	}
	if (length < 4)
	{
		error("Bad packet header\n");
		return NULL;
	}
	s = tcp_recv(s, length - 4);
	if (s == NULL)
		return NULL;
	if (version != 3)
		return s;
	in_uint8s(s, 1);	/* hdrlen */
	in_uint8(s, *code);
	if (*code == ISO_PDU_DT)
	{
		in_uint8s(s, 1);	/* eot */
		return s;
	}
	in_uint8s(s, 5);	/* dst_ref, src_ref, class */
	return s;
}

STREAM
iso_init(int length)
{
	STREAM s;

	s = tcp_init(length + 7);
	s_push_layer(s, iso_hdr, 7);

	return s;
}

void
iso_send(STREAM s)
{
	uint16 length;

	s_pop_layer(s, iso_hdr);
	length = s->end - s->p;

	out_uint8(s, 3);	/* version */
	out_uint8(s, 0);	/* reserved */
	out_uint16_be(s, length);

	out_uint8(s, 2);	/* hdrlen */
	out_uint8(s, ISO_PDU_DT);	/* code */
	out_uint8(s, 0x80);	/* eot */

	tcp_send(s);
}

STREAM
iso_recv(uint8 * rdpver)
{
	STREAM s;
	uint8 code = 0;

	s = iso_recv_msg(&code, rdpver);
	if (s == NULL)
		return NULL;
	if (rdpver != NULL)
		if (*rdpver != 3)
			return s;
	if (code != ISO_PDU_DT)
	{
		error("expected DT, got 0x%x\n", code);
		return NULL;
	}
	return s;
}

RD_BOOL
iso_connect(char *server, char *username, char *domain, char *password,
	    RD_BOOL reconnect, uint32 * selected_protocol)
{
	STREAM s;
	uint8 code;
	uint32 neg_proto;

	g_negotiate_rdp_protocol = True;

	neg_proto = PROTOCOL_SSL;

#ifdef WITH_CREDSSP
	if (!g_use_password_as_pin)
		neg_proto |= PROTOCOL_HYBRID;
	else if (g_sc_csp_name || g_sc_reader_name || g_sc_card_name || g_sc_container_name)
		neg_proto |= PROTOCOL_HYBRID;
	else
		warning("Disables CredSSP due to missing smartcard information for SSO.\n");
#endif

      retry:
	*selected_protocol = PROTOCOL_RDP;
	code = 0;

	if (!tcp_connect(server))
		return False;

	iso_send_connection_request(username, neg_proto);

	s = iso_recv_msg(&code, NULL);
	if (s == NULL)
		return False;

	if (code != ISO_PDU_CC)
	{
		error("expected CC, got 0x%x\n", code);
		tcp_disconnect();
		return False;
	}

	if (g_rdp_version >= RDP_V5 && s_check_rem(s, 8))
	{
		/* handle RDP_NEG_REQ response */
		const char *reason = NULL;

		uint8 type = 0, flags = 0;
		uint16 length = 0;
		uint32 data = 0;

		in_uint8(s, type);
		in_uint8(s, flags);
		in_uint16(s, length);
		in_uint32(s, data);

		if (type == RDP_NEG_FAILURE)
		{
			RD_BOOL retry_without_neg = False;

			switch (data)
			{
				case SSL_WITH_USER_AUTH_REQUIRED_BY_SERVER:
					reason = "SSL with user authentication required by server";
					break;
				case SSL_NOT_ALLOWED_BY_SERVER:
					reason = "SSL not allowed by server";
					retry_without_neg = True;
					break;
				case SSL_CERT_NOT_ON_SERVER:
					reason = "no valid authentication certificate on server";
					retry_without_neg = True;
					break;
				case INCONSISTENT_FLAGS:
					reason = "inconsistent negotiation flags";
					break;
				case SSL_REQUIRED_BY_SERVER:
					reason = "SSL required by server";
					break;
				case HYBRID_REQUIRED_BY_SERVER:
					reason = "CredSSP required by server";
					break;
				default:
					reason = "unknown reason";
			}

			tcp_disconnect();

			if (retry_without_neg)
			{
				fprintf(stderr,
					"Failed to negotiate protocol, retrying with plain RDP.\n");
				g_negotiate_rdp_protocol = False;
				goto retry;
			}

			fprintf(stderr, "Failed to connect, %s.\n", reason);
			return False;
		}

		if (type != RDP_NEG_RSP)
		{
			tcp_disconnect();
			error("Expected RDP_NEG_RSP, got type = 0x%x\n", type);
			return False;
		}

		/* handle negotiation response */
		if (data == PROTOCOL_SSL)
		{
#ifdef WITH_SSL
			if (!tcp_tls_connect())
			{
				/* failed to connect using cssp, let retry with plain TLS */
				tcp_disconnect();
				neg_proto = PROTOCOL_RDP;
				goto retry;
			}
			/* do not use encryption when using TLS */
			g_encryption = False;
			fprintf(stderr, "Connection established using SSL.\n");
#else /* WITH_SSL */
			fprintf(stderr, "SSL not compiled in.\n");
#endif /* WITH_SSL */
		}
#ifdef WITH_CREDSSP
		else if (data == PROTOCOL_HYBRID)
		{
			if (!cssp_connect(server, username, domain, password, s))
			{
				/* failed to connect using cssp, let retry with plain TLS */
				tcp_disconnect();
				neg_proto = PROTOCOL_SSL;
				goto retry;
			}

			/* do not use encryption when using TLS */
			fprintf(stderr, "Connection established using CredSSP.\n");
			g_encryption = False;
		}
#endif
		else if (data == PROTOCOL_RDP)
		{
			fprintf(stderr, "Connection established using plain RDP.\n");
		}
		else if (data != PROTOCOL_RDP)
		{
			tcp_disconnect();
			error("Unexpected protocol in negotiation response, got data = 0x%x.\n",
			      data);
			return False;
		}
		if (length || flags) {}

		*selected_protocol = data;
	}
	return True;
}

void
iso_disconnect(void)
{
	iso_send_msg(ISO_PDU_DR);
	tcp_disconnect();
}

void
iso_reset_state(void)
{
	g_encryption = g_encryption_initial;
	tcp_reset_state();
}

