#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_9__ ;
typedef  struct TYPE_28__   TYPE_8__ ;
typedef  struct TYPE_27__   TYPE_7__ ;
typedef  struct TYPE_26__   TYPE_6__ ;
typedef  struct TYPE_25__   TYPE_5__ ;
typedef  struct TYPE_24__   TYPE_4__ ;
typedef  struct TYPE_23__   TYPE_3__ ;
typedef  struct TYPE_22__   TYPE_2__ ;
typedef  struct TYPE_21__   TYPE_1__ ;
typedef  struct TYPE_20__   TYPE_11__ ;
typedef  struct TYPE_19__   TYPE_10__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  xdrproc_t ;
struct TYPE_22__ {int /*<<< orphan*/  gids_len; int /*<<< orphan*/  gids_val; } ;
struct TYPE_25__ {TYPE_2__ gids; int /*<<< orphan*/  gid; int /*<<< orphan*/  uid; } ;
typedef  TYPE_5__ unixcred ;
typedef  int /*<<< orphan*/  u_int ;
typedef  int /*<<< orphan*/  netnamestr ;
typedef  int /*<<< orphan*/  keystatus ;
typedef  int /*<<< orphan*/  keybuf ;
struct TYPE_27__ {int /*<<< orphan*/  st_netname; int /*<<< orphan*/  st_pub_key; int /*<<< orphan*/  st_priv_key; } ;
struct TYPE_24__ {TYPE_7__ knet; } ;
struct TYPE_26__ {TYPE_4__ key_netstres_u; int /*<<< orphan*/  status; } ;
typedef  TYPE_6__ key_netstres ;
typedef  TYPE_7__ key_netstarg ;
struct TYPE_23__ {TYPE_5__ cred; } ;
struct TYPE_28__ {TYPE_3__ getcredres_u; int /*<<< orphan*/  status; } ;
typedef  TYPE_8__ getcredres ;
typedef  int /*<<< orphan*/  enum_t ;
struct TYPE_21__ {int /*<<< orphan*/  deskey; } ;
struct TYPE_29__ {TYPE_1__ cryptkeyres_u; int /*<<< orphan*/  status; } ;
typedef  TYPE_9__ cryptkeyres ;
struct TYPE_19__ {int /*<<< orphan*/  deskey; int /*<<< orphan*/  remotekey; int /*<<< orphan*/  remotename; } ;
typedef  TYPE_10__ cryptkeyarg2 ;
struct TYPE_20__ {int /*<<< orphan*/  deskey; int /*<<< orphan*/  remotename; } ;
typedef  TYPE_11__ cryptkeyarg ;
typedef  void* bool_t ;
typedef  int /*<<< orphan*/  XDR ;

/* Variables and functions */
 void* FALSE ; 
 int /*<<< orphan*/  HEXKEYBYTES ; 
#define  KEY_SUCCESS 128 
 int /*<<< orphan*/  MAXGIDS ; 
 int /*<<< orphan*/  MAXNETNAMELEN ; 
 void* TRUE ; 
 int /*<<< orphan*/  xdr_array (int /*<<< orphan*/ *,char**,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xdr_des_block (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xdr_enum (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xdr_netobj (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xdr_opaque (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xdr_string (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xdr_u_int (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

bool_t
xdr_keystatus(register XDR *xdrs, keystatus *objp)
{

	if (!xdr_enum(xdrs, (enum_t *)objp))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_keybuf(register XDR *xdrs, keybuf objp)
{

	if (!xdr_opaque(xdrs, objp, HEXKEYBYTES))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_netnamestr(register XDR *xdrs, netnamestr *objp)
{

	if (!xdr_string(xdrs, objp, MAXNETNAMELEN))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_cryptkeyarg(register XDR *xdrs, cryptkeyarg *objp)
{

	if (!xdr_netnamestr(xdrs, &objp->remotename))
		return (FALSE);
	if (!xdr_des_block(xdrs, &objp->deskey))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_cryptkeyarg2(register XDR *xdrs, cryptkeyarg2 *objp)
{

	if (!xdr_netnamestr(xdrs, &objp->remotename))
		return (FALSE);
	if (!xdr_netobj(xdrs, &objp->remotekey))
		return (FALSE);
	if (!xdr_des_block(xdrs, &objp->deskey))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_cryptkeyres(register XDR *xdrs, cryptkeyres *objp)
{

	if (!xdr_keystatus(xdrs, &objp->status))
		return (FALSE);
	switch (objp->status) {
	case KEY_SUCCESS:
		if (!xdr_des_block(xdrs, &objp->cryptkeyres_u.deskey))
			return (FALSE);
		break;
	default:
		break;
	}
	return (TRUE);
}

bool_t
xdr_unixcred(register XDR *xdrs, unixcred *objp)
{

	if (!xdr_u_int(xdrs, &objp->uid))
		return (FALSE);
	if (!xdr_u_int(xdrs, &objp->gid))
		return (FALSE);
	if (!xdr_array(xdrs, (char **)&objp->gids.gids_val, (u_int *) &objp->gids.gids_len, MAXGIDS,
		sizeof (u_int), (xdrproc_t) xdr_u_int))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_getcredres(register XDR *xdrs, getcredres *objp)
{

	if (!xdr_keystatus(xdrs, &objp->status))
		return (FALSE);
	switch (objp->status) {
	case KEY_SUCCESS:
		if (!xdr_unixcred(xdrs, &objp->getcredres_u.cred))
			return (FALSE);
		break;
	default:
		break;
	}
	return (TRUE);
}

bool_t
xdr_key_netstarg(register XDR *xdrs, key_netstarg *objp)
{

	if (!xdr_keybuf(xdrs, objp->st_priv_key))
		return (FALSE);
	if (!xdr_keybuf(xdrs, objp->st_pub_key))
		return (FALSE);
	if (!xdr_netnamestr(xdrs, &objp->st_netname))
		return (FALSE);
	return (TRUE);
}

bool_t
xdr_key_netstres(register XDR *xdrs, key_netstres *objp)
{

	if (!xdr_keystatus(xdrs, &objp->status))
		return (FALSE);
	switch (objp->status) {
	case KEY_SUCCESS:
		if (!xdr_key_netstarg(xdrs, &objp->key_netstres_u.knet))
			return (FALSE);
		break;
	default:
		break;
	}
	return (TRUE);
}

