#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8 ;
typedef  int uint16 ;
struct TYPE_21__ {scalar_t__ p; scalar_t__ end; } ;
typedef  TYPE_1__* STREAM ;
typedef  int /*<<< orphan*/  RDPCLIENT ;
typedef  void* BOOL ;

/* Variables and functions */
 void* False ; 
 int ISO_PDU_CC ; 
 int ISO_PDU_CR ; 
 int ISO_PDU_DR ; 
 int ISO_PDU_DT ; 
 void* True ; 
 int /*<<< orphan*/  error (char*,int) ; 
 int /*<<< orphan*/  in_uint16_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  in_uint8s (TYPE_1__*,int) ; 
 int /*<<< orphan*/  iso_hdr ; 
 int /*<<< orphan*/  next_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint16 (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  out_uint16_be (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8 (TYPE_1__*,int) ; 
 int /*<<< orphan*/  out_uint8p (TYPE_1__*,char*,int) ; 
 int /*<<< orphan*/  s_mark_end (TYPE_1__*) ; 
 int /*<<< orphan*/  s_pop_layer (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  s_push_layer (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  tcp_connect (int /*<<< orphan*/ *,char*) ; 
 void* tcp_disconnect (int /*<<< orphan*/ *) ; 
 TYPE_1__* tcp_init (int /*<<< orphan*/ *,int) ; 
 TYPE_1__* tcp_recv (int /*<<< orphan*/ *,TYPE_1__*,int) ; 
 int /*<<< orphan*/  tcp_reset_state (int /*<<< orphan*/ *) ; 
 void* tcp_send (int /*<<< orphan*/ *,TYPE_1__*) ; 

__attribute__((used)) static BOOL
iso_send_msg(RDPCLIENT * This, uint8 code)
{
	STREAM s;

	s = tcp_init(This, 11);

	if(s == NULL)
		return False;

	out_uint8(s, 3);	/* version */
	out_uint8(s, 0);	/* reserved */
	out_uint16_be(s, 11);	/* length */

	out_uint8(s, 6);	/* hdrlen */
	out_uint8(s, code);
	out_uint16(s, 0);	/* dst_ref */
	out_uint16(s, 0);	/* src_ref */
	out_uint8(s, 0);	/* class */

	s_mark_end(s);
	return tcp_send(This, s);
}

__attribute__((used)) static BOOL
iso_send_connection_request(RDPCLIENT * This, char *cookie)
{
	STREAM s;
	int cookielen = (int)strlen(cookie);
	int length = 11 + cookielen;

	s = tcp_init(This, length);

	if(s == NULL)
		return False;

	out_uint8(s, 3);	/* version */
	out_uint8(s, 0);	/* reserved */
	out_uint16_be(s, length);	/* length */

	out_uint8(s, length - 5);	/* hdrlen */
	out_uint8(s, ISO_PDU_CR);
	out_uint16(s, 0);	/* dst_ref */
	out_uint16(s, 0);	/* src_ref */
	out_uint8(s, 0);	/* class */

	out_uint8p(s, cookie, cookielen);

	s_mark_end(s);
	return tcp_send(This, s);
}

__attribute__((used)) static STREAM
iso_recv_msg(RDPCLIENT * This, uint8 * code, uint8 * rdpver)
{
	STREAM s;
	uint16 length;
	uint8 version;

	s = tcp_recv(This, NULL, 4);
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
	s = tcp_recv(This, s, length - 4);
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
iso_init(RDPCLIENT * This, int length)
{
	STREAM s;

	s = tcp_init(This, length + 7);

	if(s == NULL)
		return NULL;

	s_push_layer(s, iso_hdr, 7);

	return s;
}

BOOL
iso_send(RDPCLIENT * This, STREAM s)
{
	uint16 length;

	s_pop_layer(s, iso_hdr);
	length = (uint16)(s->end - s->p);

	out_uint8(s, 3);	/* version */
	out_uint8(s, 0);	/* reserved */
	out_uint16_be(s, length);

	out_uint8(s, 2);	/* hdrlen */
	out_uint8(s, ISO_PDU_DT);	/* code */
	out_uint8(s, 0x80);	/* eot */

	return tcp_send(This, s);
}

STREAM
iso_recv(RDPCLIENT * This, uint8 * rdpver)
{
	STREAM s;
	uint8 code = 0;

	s = iso_recv_msg(This, &code, rdpver);
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

BOOL
iso_connect(RDPCLIENT * This, char *server, char *cookie)
{
	uint8 code = 0;

	if (!tcp_connect(This, server))
		return False;

	if (!iso_send_connection_request(This, cookie))
		return False;

	if (iso_recv_msg(This, &code, NULL) == NULL)
		return False;

	if (code != ISO_PDU_CC)
	{
		error("expected CC, got 0x%x\n", code);
		tcp_disconnect(This);
		return False;
	}

	return True;
}

BOOL
iso_reconnect(RDPCLIENT * This, char *server, char *cookie)
{
	uint8 code = 0;

	if (!tcp_connect(This, server))
		return False;

	if (!iso_send_connection_request(This, cookie)) // BUGBUG should we really pass the cookie here?
		return False;

	if (iso_recv_msg(This, &code, NULL) == NULL)
		return False;

	if (code != ISO_PDU_CC)
	{
		error("expected CC, got 0x%x\n", code);
		tcp_disconnect(This);
		return False;
	}

	return True;
}

BOOL
iso_disconnect(RDPCLIENT * This)
{
	iso_send_msg(This, ISO_PDU_DR);
	return tcp_disconnect(This);
}

void
iso_reset_state(RDPCLIENT * This)
{
	tcp_reset_state(This);
}

