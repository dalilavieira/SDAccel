#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct socket {int so_flags; int so_state; scalar_t__ so_pcb; } ;
struct TYPE_2__ {int sp_protocol; int /*<<< orphan*/  sp_family; } ;
struct rawcb {struct socket* rcb_socket; TYPE_1__ rcb_proto; } ;
typedef  int /*<<< orphan*/  caddr_t ;

/* Variables and functions */
 int ENOBUFS ; 
 int /*<<< orphan*/  FREE (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LIST_INSERT_HEAD (int /*<<< orphan*/ *,struct rawcb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LIST_REMOVE (struct rawcb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  M_PCB ; 
 int /*<<< orphan*/  SOCK_DOM (struct socket*) ; 
 int SOF_MP_SUBFLOW ; 
 int SOF_PCBCLEARING ; 
 int SS_NOFDREF ; 
 int /*<<< orphan*/  lck_mtx_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_try_lock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lck_mtx_unlock (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  list ; 
 int /*<<< orphan*/  raw_mtx ; 
 int /*<<< orphan*/  raw_recvspace ; 
 int /*<<< orphan*/  raw_sendspace ; 
 int /*<<< orphan*/  rawcb_list ; 
 int /*<<< orphan*/  socket_lock (struct socket*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  socket_unlock (struct socket*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sofree (struct socket*) ; 
 int soreserve (struct socket*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct rawcb* sotorawcb (struct socket*) ; 

int
raw_attach(struct socket *so, int proto)
{
	struct rawcb *rp = sotorawcb(so);
	int error;

	/*
	 * It is assumed that raw_attach is called
	 * after space has been allocated for the
	 * rawcb.
	 */
	if (rp == 0)
		return (ENOBUFS);
	error = soreserve(so, raw_sendspace, raw_recvspace);
	if (error)
		return (error);
	rp->rcb_socket = so;
	rp->rcb_proto.sp_family = SOCK_DOM(so);
	rp->rcb_proto.sp_protocol = proto;
	lck_mtx_lock(raw_mtx);
	LIST_INSERT_HEAD(&rawcb_list, rp, list);
	lck_mtx_unlock(raw_mtx);
	return (0);
}

void
raw_detach(struct rawcb *rp)
{
	struct socket *so = rp->rcb_socket;

	so->so_pcb = 0;
	so->so_flags |= SOF_PCBCLEARING;
	sofree(so);
	if (!lck_mtx_try_lock(raw_mtx)) {
		socket_unlock(so, 0);
		lck_mtx_lock(raw_mtx);
		socket_lock(so, 0);
	}
	LIST_REMOVE(rp, list);
	lck_mtx_unlock(raw_mtx);
#ifdef notdef
	if (rp->rcb_laddr)
		m_freem(dtom(rp->rcb_laddr));
	rp->rcb_laddr = 0;
#endif
	rp->rcb_socket = NULL;
	FREE((caddr_t)(rp), M_PCB);
}

void
raw_disconnect(struct rawcb *rp)
{
	struct socket *so = rp->rcb_socket;

#ifdef notdef
	if (rp->rcb_faddr)
		m_freem(dtom(rp->rcb_faddr));
	rp->rcb_faddr = 0;
#endif
	/*
	 * A multipath subflow socket would have its SS_NOFDREF set by default,
	 * so check for SOF_MP_SUBFLOW socket flag before detaching the PCB;
	 * when the socket is closed for real, SOF_MP_SUBFLOW would be cleared.
	 */
	if (!(so->so_flags & SOF_MP_SUBFLOW) && (so->so_state & SS_NOFDREF))
		raw_detach(rp);
}

