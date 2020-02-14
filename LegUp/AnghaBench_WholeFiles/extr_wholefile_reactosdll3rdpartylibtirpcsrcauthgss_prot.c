#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_41__   TYPE_5__ ;
typedef  struct TYPE_40__   TYPE_4__ ;
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_2__ ;
typedef  struct TYPE_37__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ (* xdrproc_t ) (TYPE_4__*,int /*<<< orphan*/ *) ;
typedef  int /*<<< orphan*/  wrapbuf ;
typedef  scalar_t__ u_int ;
typedef  int /*<<< orphan*/  u_char ;
struct TYPE_39__ {int /*<<< orphan*/  length; int /*<<< orphan*/  value; } ;
struct TYPE_38__ {int /*<<< orphan*/  length; int /*<<< orphan*/  value; } ;
struct rpc_gss_init_res {scalar_t__ gr_major; scalar_t__ gr_minor; scalar_t__ gr_win; TYPE_3__ gr_token; TYPE_2__ gr_ctx; } ;
struct TYPE_37__ {int /*<<< orphan*/  length; int /*<<< orphan*/  value; } ;
struct rpc_gss_cred {scalar_t__ gc_v; scalar_t__ gc_seq; TYPE_1__ gc_ctx; int /*<<< orphan*/  gc_svc; int /*<<< orphan*/  gc_proc; } ;
typedef  scalar_t__ rpc_gss_svc_t ;
typedef  scalar_t__ gss_qop_t ;
typedef  int /*<<< orphan*/  gss_ctx_id_t ;
struct TYPE_41__ {int length; int /*<<< orphan*/  value; } ;
typedef  TYPE_5__ gss_buffer_desc ;
typedef  int /*<<< orphan*/  enum_t ;
typedef  int /*<<< orphan*/  databuf ;
typedef  int /*<<< orphan*/ * caddr_t ;
typedef  int bool_t ;
struct TYPE_40__ {scalar_t__ x_op; } ;
typedef  TYPE_4__ XDR ;
typedef  scalar_t__ OM_uint32 ;

/* Variables and functions */
 int FALSE ; 
 scalar_t__ GSS_S_COMPLETE ; 
 int /*<<< orphan*/  MAX_AUTH_BYTES ; 
 int /*<<< orphan*/  MAX_NETOBJ_SZ ; 
 scalar_t__ RPCSEC_GSS_SVC_INTEGRITY ; 
 scalar_t__ RPCSEC_GSS_SVC_PRIVACY ; 
 int TRUE ; 
#define  XDR_DECODE 130 
 int /*<<< orphan*/  XDR_DESTROY (TYPE_4__*) ; 
#define  XDR_ENCODE 129 
#define  XDR_FREE 128 
 int XDR_GETPOS (TYPE_4__*) ; 
 int /*<<< orphan*/  XDR_INLINE (TYPE_4__*,int) ; 
 int /*<<< orphan*/  XDR_SETPOS (TYPE_4__*,int) ; 
 scalar_t__ gss_get_mic (scalar_t__*,int /*<<< orphan*/ ,scalar_t__,TYPE_5__*,TYPE_5__*) ; 
 int /*<<< orphan*/  gss_release_buffer (scalar_t__*,TYPE_5__*) ; 
 scalar_t__ gss_unwrap (scalar_t__*,int /*<<< orphan*/ ,TYPE_5__*,TYPE_5__*,int*,scalar_t__*) ; 
 scalar_t__ gss_verify_mic (scalar_t__*,int /*<<< orphan*/ ,TYPE_5__*,TYPE_5__*,scalar_t__*) ; 
 scalar_t__ gss_wrap (scalar_t__*,int /*<<< orphan*/ ,int,scalar_t__,TYPE_5__*,int*,TYPE_5__*) ; 
 void log_debug (char const*,...) ; 
 void log_status (char*,scalar_t__,scalar_t__) ; 
 int /*<<< orphan*/  memset (TYPE_5__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ stub1 (TYPE_4__*,int /*<<< orphan*/ *) ; 
 scalar_t__ stub2 (TYPE_4__*,int /*<<< orphan*/ *) ; 
 int xdr_bytes (TYPE_4__*,char**,scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__ xdr_enum (TYPE_4__*,int /*<<< orphan*/ *) ; 
 scalar_t__ xdr_u_int (TYPE_4__*,scalar_t__*) ; 
 scalar_t__ xdr_void ; 
 int /*<<< orphan*/  xdrmem_create (TYPE_4__*,int /*<<< orphan*/ ,int,int) ; 

bool_t
xdr_rpc_gss_cred(XDR *xdrs, struct rpc_gss_cred *p)
{
	bool_t xdr_stat;

	xdr_stat = (xdr_u_int(xdrs, &p->gc_v) &&
		    xdr_enum(xdrs, (enum_t *)&p->gc_proc) &&
		    xdr_u_int(xdrs, &p->gc_seq) &&
		    xdr_enum(xdrs, (enum_t *)&p->gc_svc) &&
		    xdr_bytes(xdrs, (char **)&p->gc_ctx.value,
			      (u_int *)&p->gc_ctx.length, MAX_AUTH_BYTES));

	log_debug("xdr_rpc_gss_cred: %s %s "
		  "(v %d, proc %d, seq %d, svc %d, ctx %p:%d)",
		  (xdrs->x_op == XDR_ENCODE) ? "encode" : "decode",
		  (xdr_stat == TRUE) ? "success" : "failure",
		  p->gc_v, p->gc_proc, p->gc_seq, p->gc_svc,
		  p->gc_ctx.value, p->gc_ctx.length);

	return (xdr_stat);
}

bool_t
xdr_rpc_gss_init_args(XDR *xdrs, gss_buffer_desc *p)
{
	bool_t xdr_stat;

	xdr_stat = xdr_bytes(xdrs, (char **)&p->value,
			      (u_int *)&p->length, MAX_NETOBJ_SZ);

	log_debug("xdr_rpc_gss_init_args: %s %s (token %p:%d)",
		  (xdrs->x_op == XDR_ENCODE) ? "encode" : "decode",
		  (xdr_stat == TRUE) ? "success" : "failure",
		  p->value, p->length);

	return (xdr_stat);
}

bool_t
xdr_rpc_gss_init_res(XDR *xdrs, struct rpc_gss_init_res *p)
{
	bool_t xdr_stat;

	xdr_stat = (xdr_bytes(xdrs, (char **)&p->gr_ctx.value,
			      (u_int *)&p->gr_ctx.length, MAX_NETOBJ_SZ) &&
		    xdr_u_int(xdrs, &p->gr_major) &&
		    xdr_u_int(xdrs, &p->gr_minor) &&
		    xdr_u_int(xdrs, &p->gr_win) &&
		    xdr_bytes(xdrs, (char **)&p->gr_token.value,
			      (u_int *)&p->gr_token.length, MAX_NETOBJ_SZ));

	log_debug("xdr_rpc_gss_init_res %s %s "
		  "(ctx %p:%d, maj %d, min %d, win %d, token %p:%d)",
		  (xdrs->x_op == XDR_ENCODE) ? "encode" : "decode",
		  (xdr_stat == TRUE) ? "success" : "failure",
		  p->gr_ctx.value, p->gr_ctx.length,
		  p->gr_major, p->gr_minor, p->gr_win,
		  p->gr_token.value, p->gr_token.length);

	return (xdr_stat);
}

bool_t
xdr_rpc_gss_wrap_data(XDR *xdrs, xdrproc_t xdr_func, caddr_t xdr_ptr,
		      gss_ctx_id_t ctx, gss_qop_t qop,
		      rpc_gss_svc_t svc, u_int seq)
{
	gss_buffer_desc	databuf, wrapbuf;
	OM_uint32	maj_stat, min_stat;
	int		start, end, conf_state;
	bool_t		xdr_stat;

	/* Skip databody length. */
	start = XDR_GETPOS(xdrs);
	XDR_SETPOS(xdrs, start + 4);

	/* Marshal rpc_gss_data_t (sequence number + arguments). */
	if (!xdr_u_int(xdrs, &seq) || !(*xdr_func)(xdrs, xdr_ptr))
		return (FALSE);
	end = XDR_GETPOS(xdrs);

	/* Set databuf to marshalled rpc_gss_data_t. */
	databuf.length = end - start - 4;
	XDR_SETPOS(xdrs, start + 4);
	databuf.value = XDR_INLINE(xdrs, databuf.length);

	xdr_stat = FALSE;

	if (svc == RPCSEC_GSS_SVC_INTEGRITY) {
		/* Marshal databody_integ length. */
		XDR_SETPOS(xdrs, start);
		if (!xdr_u_int(xdrs, (u_int *)&databuf.length))
			return (FALSE);

		/* Checksum rpc_gss_data_t. */
		maj_stat = gss_get_mic(&min_stat, ctx, qop,
				       &databuf, &wrapbuf);
		if (maj_stat != GSS_S_COMPLETE) {
			log_debug("gss_get_mic failed");
			return (FALSE);
		}
		/* Marshal checksum. */
		XDR_SETPOS(xdrs, end);
		xdr_stat = xdr_bytes(xdrs, (char **)&wrapbuf.value,
				     (u_int *)&wrapbuf.length, MAX_NETOBJ_SZ);
		gss_release_buffer(&min_stat, &wrapbuf);
	}
	else if (svc == RPCSEC_GSS_SVC_PRIVACY) {
		/* Encrypt rpc_gss_data_t. */
		maj_stat = gss_wrap(&min_stat, ctx, TRUE, qop, &databuf,
				    &conf_state, &wrapbuf);
		if (maj_stat != GSS_S_COMPLETE) {
			log_status("gss_wrap", maj_stat, min_stat);
			return (FALSE);
		}
		/* Marshal databody_priv. */
		XDR_SETPOS(xdrs, start);
		xdr_stat = xdr_bytes(xdrs, (char **)&wrapbuf.value,
				     (u_int *)&wrapbuf.length, MAX_NETOBJ_SZ);
		gss_release_buffer(&min_stat, &wrapbuf);
	}
	return (xdr_stat);
}

bool_t
xdr_rpc_gss_unwrap_data(XDR *xdrs, xdrproc_t xdr_func, caddr_t xdr_ptr,
			gss_ctx_id_t ctx, gss_qop_t qop,
			rpc_gss_svc_t svc, u_int seq)
{
	XDR		tmpxdrs;
	gss_buffer_desc	databuf, wrapbuf;
	OM_uint32	maj_stat, min_stat;
	u_int		seq_num, qop_state;
	int			conf_state;
	bool_t		xdr_stat;

	if (xdr_func == (xdrproc_t)xdr_void || xdr_ptr == NULL)
		return (TRUE);

	memset(&databuf, 0, sizeof(databuf));
	memset(&wrapbuf, 0, sizeof(wrapbuf));

	if (svc == RPCSEC_GSS_SVC_INTEGRITY) {
		/* Decode databody_integ. */
		if (!xdr_bytes(xdrs, (char **)&databuf.value, (u_int *)&databuf.length,
			       MAX_NETOBJ_SZ)) {
			log_debug("xdr decode databody_integ failed");
			return (FALSE);
		}
		/* Decode checksum. */
		if (!xdr_bytes(xdrs, (char **)&wrapbuf.value, (u_int *)&wrapbuf.length,
			       MAX_NETOBJ_SZ)) {
			gss_release_buffer(&min_stat, &databuf);
			log_debug("xdr decode checksum failed");
			return (FALSE);
		}
		/* Verify checksum and QOP. */
		maj_stat = gss_verify_mic(&min_stat, ctx, &databuf,
					  &wrapbuf, &qop_state);
		gss_release_buffer(&min_stat, &wrapbuf);

		if (maj_stat != GSS_S_COMPLETE || qop_state != qop) {
			gss_release_buffer(&min_stat, &databuf);
			log_status("gss_verify_mic", maj_stat, min_stat);
			return (FALSE);
		}
	}
	else if (svc == RPCSEC_GSS_SVC_PRIVACY) {
		/* Decode databody_priv. */
		if (!xdr_bytes(xdrs, (char **)&wrapbuf.value, (u_int *)&wrapbuf.length,
			       MAX_NETOBJ_SZ)) {
			log_debug("xdr decode databody_priv failed");
			return (FALSE);
		}
		/* Decrypt databody. */
		maj_stat = gss_unwrap(&min_stat, ctx, &wrapbuf, &databuf,
				      &conf_state, &qop_state);

		gss_release_buffer(&min_stat, &wrapbuf);

		/* Verify encryption and QOP. */
		if (maj_stat != GSS_S_COMPLETE || qop_state != qop ||
			conf_state != TRUE) {
			gss_release_buffer(&min_stat, &databuf);
			log_status("gss_unwrap", maj_stat, min_stat);
			return (FALSE);
		}
	}
	/* Decode rpc_gss_data_t (sequence number + arguments). */
	xdrmem_create(&tmpxdrs, databuf.value, databuf.length, XDR_DECODE);
	xdr_stat = (xdr_u_int(&tmpxdrs, &seq_num) &&
		    (*xdr_func)(&tmpxdrs, xdr_ptr));
	XDR_DESTROY(&tmpxdrs);
	gss_release_buffer(&min_stat, &databuf);

	/* Verify sequence number. */
	if (xdr_stat == TRUE && seq_num != seq) {
		log_debug("wrong sequence number in databody");
		return (FALSE);
	}
	return (xdr_stat);
}

bool_t
xdr_rpc_gss_data(XDR *xdrs, xdrproc_t xdr_func, caddr_t xdr_ptr,
		 gss_ctx_id_t ctx, gss_qop_t qop,
		 rpc_gss_svc_t svc, u_int seq)
{
	switch (xdrs->x_op) {

	case XDR_ENCODE:
		return (xdr_rpc_gss_wrap_data(xdrs, xdr_func, xdr_ptr,
					      ctx, qop, svc, seq));
	case XDR_DECODE:
		return (xdr_rpc_gss_unwrap_data(xdrs, xdr_func, xdr_ptr,
						ctx, qop,svc, seq));
	case XDR_FREE:
		return (TRUE);
	}
	return (FALSE);
}

void
log_debug(const char *fmt, ...)
{
}

void
log_status(char *m, OM_uint32 maj_stat, OM_uint32 min_stat)
{
}

void
log_hexdump(const u_char *buf, int len, int offset)
{
}

