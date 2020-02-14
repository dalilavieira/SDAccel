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
typedef  int u32 ;
struct xdr_netobj {int len; unsigned char* data; } ;

/* Variables and functions */
 int G_BAD_TOK_HEADER ; 
 int G_WRONG_MECH ; 
 unsigned char SIZEOF_INT ; 
 int /*<<< orphan*/  TWRITE_STR (unsigned char*,unsigned char*,int) ; 
 int /*<<< orphan*/  g_OID_equal (struct xdr_netobj*,struct xdr_netobj*) ; 

__attribute__((used)) static int
der_length_size( int length)
{
	if (length < (1<<7))
		return 1;
	else if (length < (1<<8))
		return 2;
#if (SIZEOF_INT == 2)
	else
		return 3;
#else
	else if (length < (1<<16))
		return 3;
	else if (length < (1<<24))
		return 4;
	else
		return 5;
#endif
}

__attribute__((used)) static void
der_write_length(unsigned char **buf, int length)
{
	if (length < (1<<7)) {
		*(*buf)++ = (unsigned char) length;
	} else {
		*(*buf)++ = (unsigned char) (der_length_size(length)+127);
#if (SIZEOF_INT > 2)
		if (length >= (1<<24))
			*(*buf)++ = (unsigned char) (length>>24);
		if (length >= (1<<16))
			*(*buf)++ = (unsigned char) ((length>>16)&0xff);
#endif
		if (length >= (1<<8))
			*(*buf)++ = (unsigned char) ((length>>8)&0xff);
		*(*buf)++ = (unsigned char) (length&0xff);
	}
}

__attribute__((used)) static int
der_read_length(unsigned char **buf, int *bufsize)
{
	unsigned char sf;
	int ret;

	if (*bufsize < 1)
		return -1;
	sf = *(*buf)++;
	(*bufsize)--;
	if (sf & 0x80) {
		if ((sf &= 0x7f) > ((*bufsize)-1))
			return -1;
		if (sf > SIZEOF_INT)
			return -1;
		ret = 0;
		for (; sf; sf--) {
			ret = (ret<<8) + (*(*buf)++);
			(*bufsize)--;
		}
	} else {
		ret = sf;
	}

	return ret;
}

int
g_token_size(struct xdr_netobj *mech, unsigned int body_size)
{
	/* set body_size to sequence contents size */
	body_size += 2 + (int) mech->len;         /* NEED overflow check */
	return 1 + der_length_size(body_size) + body_size;
}

void
g_make_token_header(struct xdr_netobj *mech, int body_size, unsigned char **buf)
{
	*(*buf)++ = 0x60;
	der_write_length(buf, 2 + mech->len + body_size);
	*(*buf)++ = 0x06;
	*(*buf)++ = (unsigned char) mech->len;
	TWRITE_STR(*buf, mech->data, ((int) mech->len));
}

u32
g_verify_token_header(struct xdr_netobj *mech, int *body_size,
		      unsigned char **buf_in, int toksize)
{
	unsigned char *buf = *buf_in;
	int seqsize;
	struct xdr_netobj toid;
	int ret = 0;

	if ((toksize-=1) < 0)
		return G_BAD_TOK_HEADER;
	if (*buf++ != 0x60)
		return G_BAD_TOK_HEADER;

	if ((seqsize = der_read_length(&buf, &toksize)) < 0)
		return G_BAD_TOK_HEADER;

	if (seqsize != toksize)
		return G_BAD_TOK_HEADER;

	if ((toksize-=1) < 0)
		return G_BAD_TOK_HEADER;
	if (*buf++ != 0x06)
		return G_BAD_TOK_HEADER;

	if ((toksize-=1) < 0)
		return G_BAD_TOK_HEADER;
	toid.len = *buf++;

	if ((toksize-=toid.len) < 0)
		return G_BAD_TOK_HEADER;
	toid.data = buf;
	buf+=toid.len;

	if (! g_OID_equal(&toid, mech))
		ret = G_WRONG_MECH;

   /* G_WRONG_MECH is not returned immediately because it's more important
      to return G_BAD_TOK_HEADER if the token header is in fact bad */

	if ((toksize-=2) < 0)
		return G_BAD_TOK_HEADER;

	if (ret)
		return ret;

	if (!ret) {
		*buf_in = buf;
		*body_size = toksize;
	}

	return ret;
}

