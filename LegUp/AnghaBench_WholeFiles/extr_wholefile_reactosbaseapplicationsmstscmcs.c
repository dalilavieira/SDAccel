#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_31__   TYPE_26__ ;
typedef  struct TYPE_30__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8 ;
typedef  int /*<<< orphan*/  uint32 ;
typedef  int uint16 ;
struct TYPE_31__ {int mcs_id; } ;
struct TYPE_30__ {int end; int data; int p; } ;
typedef  TYPE_1__* STREAM ;
typedef  void* RD_BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  BER_TAG_BOOLEAN ; 
 int /*<<< orphan*/  BER_TAG_INTEGER ; 
 int /*<<< orphan*/  BER_TAG_OCTET_STRING ; 
 int /*<<< orphan*/  BER_TAG_RESULT ; 
 int /*<<< orphan*/  DEBUG_RDP5 (char*) ; 
 void* False ; 
 scalar_t__ MCS_AUCF ; 
 int MCS_AURQ ; 
 scalar_t__ MCS_CJCF ; 
 int MCS_CJRQ ; 
 int /*<<< orphan*/  MCS_CONNECT_INITIAL ; 
 int /*<<< orphan*/  MCS_CONNECT_RESPONSE ; 
 scalar_t__ MCS_DPUM ; 
 int MCS_EDRQ ; 
 int MCS_GLOBAL_CHANNEL ; 
 scalar_t__ MCS_SDIN ; 
 int MCS_SDRQ ; 
 int /*<<< orphan*/  MCS_TAG_DOMAIN_PARAMS ; 
 int MCS_USERCHANNEL_BASE ; 
 void* True ; 
 int /*<<< orphan*/  ber_out_header (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ber_out_integer (TYPE_1__*,int) ; 
 int /*<<< orphan*/  ber_parse_header (TYPE_1__*,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  error (char*,scalar_t__) ; 
 TYPE_26__* g_channels ; 
 int g_mcs_userid ; 
 unsigned int g_num_channels ; 
 int /*<<< orphan*/  in_uint16_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint8 (TYPE_1__*,scalar_t__) ; 
 int /*<<< orphan*/  in_uint8s (TYPE_1__*,int) ; 
 void* iso_connect (char*,char*,char*,char*,void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iso_disconnect () ; 
 TYPE_1__* iso_init (int) ; 
 TYPE_1__* iso_recv (scalar_t__*) ; 
 int /*<<< orphan*/  iso_reset_state () ; 
 int /*<<< orphan*/  iso_send (TYPE_1__*) ; 
 int /*<<< orphan*/  mcs_hdr ; 
 int /*<<< orphan*/  out_uint16_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_1__*,int,int) ; 
 void* s_check (TYPE_1__*) ; 
 void* s_check_end (TYPE_1__*) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_1__*) ; 
 int /*<<< orphan*/  s_pop_layer (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s_push_layer (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  sec_process_mcs_data (TYPE_1__*) ; 

__attribute__((used)) static void
mcs_out_domain_params(STREAM s, int max_channels, int max_users, int max_tokens, int max_pdusize)
{
	ber_out_header(s, MCS_TAG_DOMAIN_PARAMS, 32);
	ber_out_integer(s, max_channels);
	ber_out_integer(s, max_users);
	ber_out_integer(s, max_tokens);
	ber_out_integer(s, 1);	/* num_priorities */
	ber_out_integer(s, 0);	/* min_throughput */
	ber_out_integer(s, 1);	/* max_height */
	ber_out_integer(s, max_pdusize);
	ber_out_integer(s, 2);	/* ver_protocol */
}

__attribute__((used)) static RD_BOOL
mcs_parse_domain_params(STREAM s)
{
	int length;

	ber_parse_header(s, MCS_TAG_DOMAIN_PARAMS, &length);
	in_uint8s(s, length);

	return s_check(s);
}

__attribute__((used)) static void
mcs_send_connect_initial(STREAM mcs_data)
{
	int datalen = mcs_data->end - mcs_data->data;
	int length = 9 + 3 * 34 + 4 + datalen;
	STREAM s;

	s = iso_init(length + 5);

	ber_out_header(s, MCS_CONNECT_INITIAL, length);
	ber_out_header(s, BER_TAG_OCTET_STRING, 1);	/* calling domain */
	out_uint8(s, 1);
	ber_out_header(s, BER_TAG_OCTET_STRING, 1);	/* called domain */
	out_uint8(s, 1);

	ber_out_header(s, BER_TAG_BOOLEAN, 1);
	out_uint8(s, 0xff);	/* upward flag */

	mcs_out_domain_params(s, 34, 2, 0, 0xffff);	/* target params */
	mcs_out_domain_params(s, 1, 1, 1, 0x420);	/* min params */
	mcs_out_domain_params(s, 0xffff, 0xfc17, 0xffff, 0xffff);	/* max params */

	ber_out_header(s, BER_TAG_OCTET_STRING, datalen);
	out_uint8p(s, mcs_data->data, datalen);

	s_mark_end(s);
	iso_send(s);
}

__attribute__((used)) static RD_BOOL
mcs_recv_connect_response(STREAM mcs_data)
{
	uint8 result;
	int length;
	STREAM s;

	s = iso_recv(NULL);
	if (s == NULL)
		return False;

	ber_parse_header(s, MCS_CONNECT_RESPONSE, &length);

	ber_parse_header(s, BER_TAG_RESULT, &length);
	in_uint8(s, result);
	if (result != 0)
	{
		error("MCS connect: %d\n", result);
		return False;
	}

	ber_parse_header(s, BER_TAG_INTEGER, &length);
	in_uint8s(s, length);	/* connect id */
	mcs_parse_domain_params(s);

	ber_parse_header(s, BER_TAG_OCTET_STRING, &length);

	sec_process_mcs_data(s);
	/*
	   if (length > mcs_data->size)
	   {
	   error("MCS data length %d, expected %d\n", length,
	   mcs_data->size);
	   length = mcs_data->size;
	   }

	   in_uint8a(s, mcs_data->data, length);
	   mcs_data->p = mcs_data->data;
	   mcs_data->end = mcs_data->data + length;
	 */
	return s_check_end(s);
}

__attribute__((used)) static void
mcs_send_edrq(void)
{
	STREAM s;

	s = iso_init(5);

	out_uint8(s, (MCS_EDRQ << 2));
	out_uint16_be(s, 1);	/* height */
	out_uint16_be(s, 1);	/* interval */

	s_mark_end(s);
	iso_send(s);
}

__attribute__((used)) static void
mcs_send_aurq(void)
{
	STREAM s;

	s = iso_init(1);

	out_uint8(s, (MCS_AURQ << 2));

	s_mark_end(s);
	iso_send(s);
}

__attribute__((used)) static RD_BOOL
mcs_recv_aucf(uint16 * mcs_userid)
{
	uint8 opcode, result;
	STREAM s;

	s = iso_recv(NULL);
	if (s == NULL)
		return False;

	in_uint8(s, opcode);
	if ((opcode >> 2) != MCS_AUCF)
	{
		error("expected AUcf, got %d\n", opcode);
		return False;
	}

	in_uint8(s, result);
	if (result != 0)
	{
		error("AUrq: %d\n", result);
		return False;
	}

	if (opcode & 2)
		in_uint16_be(s, *mcs_userid);

	return s_check_end(s);
}

__attribute__((used)) static void
mcs_send_cjrq(uint16 chanid)
{
	STREAM s;

	DEBUG_RDP5(("Sending CJRQ for channel #%d\n", chanid));

	s = iso_init(5);

	out_uint8(s, (MCS_CJRQ << 2));
	out_uint16_be(s, g_mcs_userid);
	out_uint16_be(s, chanid);

	s_mark_end(s);
	iso_send(s);
}

__attribute__((used)) static RD_BOOL
mcs_recv_cjcf(void)
{
	uint8 opcode, result;
	STREAM s;

	s = iso_recv(NULL);
	if (s == NULL)
		return False;

	in_uint8(s, opcode);
	if ((opcode >> 2) != MCS_CJCF)
	{
		error("expected CJcf, got %d\n", opcode);
		return False;
	}

	in_uint8(s, result);
	if (result != 0)
	{
		error("CJrq: %d\n", result);
		return False;
	}

	in_uint8s(s, 4);	/* mcs_userid, req_chanid */
	if (opcode & 2)
		in_uint8s(s, 2);	/* join_chanid */

	return s_check_end(s);
}

STREAM
mcs_init(int length)
{
	STREAM s;

	s = iso_init(length + 8);
	s_push_layer(s, mcs_hdr, 8);

	return s;
}

void
mcs_send_to_channel(STREAM s, uint16 channel)
{
	uint16 length;

	s_pop_layer(s, mcs_hdr);
	length = s->end - s->p - 8;
	length |= 0x8000;

	out_uint8(s, (MCS_SDRQ << 2));
	out_uint16_be(s, g_mcs_userid);
	out_uint16_be(s, channel);
	out_uint8(s, 0x70);	/* flags */
	out_uint16_be(s, length);

	iso_send(s);
}

void
mcs_send(STREAM s)
{
	mcs_send_to_channel(s, MCS_GLOBAL_CHANNEL);
}

STREAM
mcs_recv(uint16 * channel, uint8 * rdpver)
{
	uint8 opcode, appid, length;
	STREAM s;

	s = iso_recv(rdpver);
	if (s == NULL)
		return NULL;
	if (rdpver != NULL)
		if (*rdpver != 3)
			return s;
	in_uint8(s, opcode);
	appid = opcode >> 2;
	if (appid != MCS_SDIN)
	{
		if (appid != MCS_DPUM)
		{
			error("expected data, got %d\n", opcode);
		}
		return NULL;
	}
	in_uint8s(s, 2);	/* userid */
	in_uint16_be(s, *channel);
	in_uint8s(s, 1);	/* flags */
	in_uint8(s, length);
	if (length & 0x80)
		in_uint8s(s, 1);	/* second byte of length */
	return s;
}

RD_BOOL
mcs_connect_start(char *server, char *username, char *domain, char *password,
		  RD_BOOL reconnect, uint32 * selected_protocol)
{
	return iso_connect(server, username, domain, password, reconnect, selected_protocol);
}

RD_BOOL
mcs_connect_finalize(STREAM mcs_data)
{
	unsigned int i;

	mcs_send_connect_initial(mcs_data);
	if (!mcs_recv_connect_response(mcs_data))
		goto error;

	mcs_send_edrq();

	mcs_send_aurq();
	if (!mcs_recv_aucf(&g_mcs_userid))
		goto error;

	mcs_send_cjrq(g_mcs_userid + MCS_USERCHANNEL_BASE);

	if (!mcs_recv_cjcf())
		goto error;

	mcs_send_cjrq(MCS_GLOBAL_CHANNEL);
	if (!mcs_recv_cjcf())
		goto error;

	for (i = 0; i < g_num_channels; i++)
	{
		mcs_send_cjrq(g_channels[i].mcs_id);
		if (!mcs_recv_cjcf())
			goto error;
	}
	return True;

      error:
	iso_disconnect();
	return False;
}

void
mcs_disconnect(void)
{
	iso_disconnect();
}

void
mcs_reset_state(void)
{
	g_mcs_userid = 0;
	iso_reset_state();
}

