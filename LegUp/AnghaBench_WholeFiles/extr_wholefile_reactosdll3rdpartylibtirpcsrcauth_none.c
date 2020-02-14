#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_2__ ;
typedef  struct TYPE_25__   TYPE_1__ ;

/* Type definitions */
typedef  int (* xdrproc_t ) (TYPE_2__*,int /*<<< orphan*/ ) ;
typedef  int /*<<< orphan*/  u_int ;
struct opaque_auth {int dummy; } ;
struct TYPE_27__ {int /*<<< orphan*/  ah_verf; int /*<<< orphan*/  ah_cred; struct auth_ops* ah_ops; } ;
struct authnone_private {int /*<<< orphan*/  mcnt; int /*<<< orphan*/  marshalled_client; TYPE_4__ no_client; } ;
struct auth_ops {void (* ah_nextverf ) (TYPE_4__*) ;void (* ah_destroy ) (TYPE_4__*) ;int (* ah_wrap ) (TYPE_4__*,TYPE_2__*,int (*) (TYPE_2__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ) ;int (* ah_unwrap ) (TYPE_4__*,TYPE_2__*,int (*) (TYPE_2__*,int /*<<< orphan*/ ),int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* ah_refresh ) (TYPE_4__*,void*) ;int /*<<< orphan*/  (* ah_validate ) (TYPE_4__*,struct opaque_auth*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* ah_marshal ) (TYPE_4__*,TYPE_2__*,int /*<<< orphan*/ *) ;} ;
typedef  int /*<<< orphan*/  mutex_t ;
typedef  int /*<<< orphan*/  caddr_t ;
typedef  int /*<<< orphan*/  bool_t ;
struct TYPE_26__ {TYPE_1__* x_ops; } ;
typedef  TYPE_2__ XDR ;
struct TYPE_25__ {int /*<<< orphan*/  (* x_putbytes ) (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ;} ;
typedef  TYPE_4__ AUTH ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ MAX_MARSHAL_SIZE ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  XDR_DESTROY (TYPE_2__*) ; 
 int /*<<< orphan*/  XDR_ENCODE ; 
 int /*<<< orphan*/  XDR_GETPOS (TYPE_2__*) ; 
 int /*<<< orphan*/  _null_auth ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
static  struct auth_ops* authnone_ops () ; 
 struct authnone_private* authnone_private ; 
 scalar_t__ calloc (int,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int stub2 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int stub3 (TYPE_2__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xdr_opaque_auth (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xdrmem_create (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

AUTH *
authnone_create()
{
	struct authnone_private *ap = authnone_private;
	XDR xdr_stream;
	XDR *xdrs;
	extern mutex_t authnone_lock;

	mutex_lock(&authnone_lock);
	if (ap == 0) {
		ap = (struct authnone_private *)calloc(1, sizeof (*ap));
		if (ap == 0) {
			mutex_unlock(&authnone_lock);
			return (0);
		}
		authnone_private = ap;
	}
	if (!ap->mcnt) {
		ap->no_client.ah_cred = ap->no_client.ah_verf = _null_auth;
		ap->no_client.ah_ops = authnone_ops();
		xdrs = &xdr_stream;
		xdrmem_create(xdrs, ap->marshalled_client,
		    (u_int)MAX_MARSHAL_SIZE, XDR_ENCODE);
		(void)xdr_opaque_auth(xdrs, &ap->no_client.ah_cred);
		(void)xdr_opaque_auth(xdrs, &ap->no_client.ah_verf);
		ap->mcnt = XDR_GETPOS(xdrs);
		XDR_DESTROY(xdrs);
	}
	mutex_unlock(&authnone_lock);
	return (&ap->no_client);
}

__attribute__((used)) static bool_t
authnone_marshal(AUTH *client, XDR *xdrs, u_int *seq)
{
	struct authnone_private *ap;
	bool_t dummy;
	extern mutex_t authnone_lock;

	assert(xdrs != NULL);

	ap = authnone_private;
	if (ap == NULL) {
		mutex_unlock(&authnone_lock);
		return (FALSE);
	}
	dummy = (*xdrs->x_ops->x_putbytes)(xdrs,
	    ap->marshalled_client, ap->mcnt);
	mutex_unlock(&authnone_lock);
	return (dummy);
}

__attribute__((used)) static void
authnone_verf(AUTH *client)
{
}

__attribute__((used)) static bool_t
authnone_validate(AUTH *client, struct opaque_auth *opaque, u_int seq)
{

	return (TRUE);
}

__attribute__((used)) static bool_t
authnone_refresh(AUTH *client, void *dummy)
{

	return (FALSE);
}

__attribute__((used)) static void
authnone_destroy(AUTH *client)
{
}

__attribute__((used)) static int
authnone_wrap(AUTH *auth, XDR *xdrs, xdrproc_t func, caddr_t args)
{
    return ((*func)(xdrs, args));
}

__attribute__((used)) static int
authnone_unwrap(AUTH *auth, XDR *xdrs, xdrproc_t func, caddr_t args, u_int seq)
{
    return ((*func)(xdrs, args));
}

__attribute__((used)) static struct auth_ops *
authnone_ops()
{
	static struct auth_ops ops;
	extern mutex_t ops_lock;
 
/* VARIABLES PROTECTED BY ops_lock: ops */
 
	mutex_lock(&ops_lock);
	if (ops.ah_nextverf == NULL) {
		ops.ah_nextverf = authnone_verf;
		ops.ah_marshal = authnone_marshal;
		ops.ah_validate = authnone_validate;
		ops.ah_refresh = authnone_refresh;
		ops.ah_destroy = authnone_destroy;
        ops.ah_wrap = authnone_wrap;
        ops.ah_unwrap = authnone_unwrap;
	}
	mutex_unlock(&ops_lock);
	return (&ops);
}

