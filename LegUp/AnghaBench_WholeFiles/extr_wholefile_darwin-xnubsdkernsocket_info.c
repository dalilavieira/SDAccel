#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
typedef  void* uint64_t ;
typedef  void* u_int64_t ;
typedef  int u_int32_t ;
struct unpcb {struct tcpcb* unp_conn; TYPE_12__* unp_addr; } ;
struct un_sockinfo {int /*<<< orphan*/  unsi_caddr; int /*<<< orphan*/  unsi_addr; void* unsi_conn_so; void* unsi_conn_pcb; } ;
struct TYPE_14__ {int tv_sec; int tv_usec; } ;
struct sockbuf {TYPE_11__ sb_timeo; int /*<<< orphan*/  sb_flags; int /*<<< orphan*/  sb_lowat; int /*<<< orphan*/  sb_mbmax; int /*<<< orphan*/  sb_mbcnt; int /*<<< orphan*/  sb_hiwat; int /*<<< orphan*/  sb_cc; } ;
struct tcpcb {int so_options; struct tcpcb* so_pcb; TYPE_12__* unp_addr; struct tcpcb* unp_socket; int /*<<< orphan*/  t_flags; int /*<<< orphan*/  t_maxseg; int /*<<< orphan*/ * t_timer; int /*<<< orphan*/  t_state; TYPE_1__* so_proto; struct sockbuf so_rcv; struct sockbuf so_snd; int /*<<< orphan*/  so_oobmark; int /*<<< orphan*/  so_error; int /*<<< orphan*/  so_timeo; int /*<<< orphan*/  so_qlimit; int /*<<< orphan*/  so_incqlen; int /*<<< orphan*/  so_qlen; int /*<<< orphan*/  so_state; int /*<<< orphan*/  so_linger; int /*<<< orphan*/  so_type; } ;
struct tcp_sockinfo {void* tcpsi_tp; int /*<<< orphan*/  tcpsi_flags; int /*<<< orphan*/  tcpsi_mss; int /*<<< orphan*/ * tcpsi_timer; int /*<<< orphan*/  tcpsi_state; } ;
struct kern_event_info {int /*<<< orphan*/  kesi_subclass_filter; int /*<<< orphan*/  kesi_class_filter; int /*<<< orphan*/  kesi_vendor_code_filter; } ;
struct ndrv_info {int /*<<< orphan*/  ndrvsi_if_name; int /*<<< orphan*/  ndrvsi_if_unit; int /*<<< orphan*/  ndrvsi_if_family; } ;
struct TYPE_23__ {int /*<<< orphan*/  in6_hops; int /*<<< orphan*/  in6_ifindex; int /*<<< orphan*/  in6_cksum; int /*<<< orphan*/  in6_hlim; } ;
struct TYPE_21__ {int /*<<< orphan*/  in4_tos; } ;
struct TYPE_19__ {int /*<<< orphan*/  ina_6; } ;
struct TYPE_17__ {int /*<<< orphan*/  ina_6; } ;
struct in_sockinfo {TYPE_8__ insi_v6; TYPE_6__ insi_v4; TYPE_4__ insi_laddr; TYPE_2__ insi_faddr; int /*<<< orphan*/  insi_ip_ttl; int /*<<< orphan*/  insi_vflag; int /*<<< orphan*/  insi_flags; int /*<<< orphan*/  insi_gencnt; int /*<<< orphan*/  insi_lport; int /*<<< orphan*/  insi_fport; } ;
struct TYPE_13__ {struct kern_event_info pri_kern_event; struct ndrv_info pri_ndrv; struct un_sockinfo pri_un; struct tcp_sockinfo pri_tcp; struct in_sockinfo pri_in; } ;
struct sockbuf_info {int sbi_timeo; int /*<<< orphan*/  sbi_flags; int /*<<< orphan*/  sbi_lowat; int /*<<< orphan*/  sbi_mbmax; int /*<<< orphan*/  sbi_mbcnt; int /*<<< orphan*/  sbi_hiwat; int /*<<< orphan*/  sbi_cc; } ;
struct socket_info {short soi_options; int /*<<< orphan*/  soi_kind; TYPE_10__ soi_proto; struct sockbuf_info soi_rcv; struct sockbuf_info soi_snd; int /*<<< orphan*/  soi_oobmark; int /*<<< orphan*/  soi_error; int /*<<< orphan*/  soi_timeo; int /*<<< orphan*/  soi_qlimit; int /*<<< orphan*/  soi_incqlen; int /*<<< orphan*/  soi_qlen; void* soi_family; void* soi_protocol; void* soi_pcb; int /*<<< orphan*/  soi_state; int /*<<< orphan*/  soi_linger; int /*<<< orphan*/  soi_type; void* soi_so; } ;
struct socket {int so_options; struct socket* so_pcb; TYPE_12__* unp_addr; struct socket* unp_socket; int /*<<< orphan*/  t_flags; int /*<<< orphan*/  t_maxseg; int /*<<< orphan*/ * t_timer; int /*<<< orphan*/  t_state; TYPE_1__* so_proto; struct sockbuf so_rcv; struct sockbuf so_snd; int /*<<< orphan*/  so_oobmark; int /*<<< orphan*/  so_error; int /*<<< orphan*/  so_timeo; int /*<<< orphan*/  so_qlimit; int /*<<< orphan*/  so_incqlen; int /*<<< orphan*/  so_qlen; int /*<<< orphan*/  so_state; int /*<<< orphan*/  so_linger; int /*<<< orphan*/  so_type; } ;
struct ndrv_cb {struct ifnet* nd_if; } ;
struct kern_event_pcb {int /*<<< orphan*/  evp_subclass_filter; int /*<<< orphan*/  evp_class_filter; int /*<<< orphan*/  evp_vendor_code_filter; } ;
struct TYPE_24__ {int /*<<< orphan*/  inp6_hops; int /*<<< orphan*/  inp6_cksum; } ;
struct TYPE_22__ {int /*<<< orphan*/  inp4_ip_tos; } ;
struct TYPE_20__ {int /*<<< orphan*/  inp6_local; } ;
struct TYPE_18__ {int /*<<< orphan*/  inp6_foreign; } ;
struct inpcb {int /*<<< orphan*/ * inp_ppcb; TYPE_9__ inp_depend6; TYPE_7__ inp_depend4; TYPE_5__ inp_dependladdr; TYPE_3__ inp_dependfaddr; int /*<<< orphan*/  inp_ip_ttl; int /*<<< orphan*/  inp_vflag; int /*<<< orphan*/  inp_flags; int /*<<< orphan*/  inp_gencnt; int /*<<< orphan*/  inp_lport; int /*<<< orphan*/  inp_fport; } ;
struct ifnet {int /*<<< orphan*/  if_name; int /*<<< orphan*/  if_unit; int /*<<< orphan*/  if_family; } ;
typedef  int /*<<< orphan*/  errno_t ;
struct TYPE_16__ {int /*<<< orphan*/ * pr_domain; } ;
struct TYPE_15__ {size_t sun_len; } ;

/* Variables and functions */
 int /*<<< orphan*/  IFNAMSIZ ; 
 short IPPROTO_TCP ; 
#define  PF_INET 134 
#define  PF_INET6 133 
#define  PF_NDRV 132 
#define  PF_PPP 131 
#define  PF_ROUTE 130 
#define  PF_SYSTEM 129 
#define  PF_UNIX 128 
 int /*<<< orphan*/  SOCKINFO_GENERIC ; 
 int /*<<< orphan*/  SOCKINFO_IN ; 
 int /*<<< orphan*/  SOCKINFO_KERN_EVENT ; 
 int /*<<< orphan*/  SOCKINFO_NDRV ; 
 int /*<<< orphan*/  SOCKINFO_TCP ; 
 int /*<<< orphan*/  SOCKINFO_UN ; 
 void* SOCK_DOM (struct tcpcb*) ; 
 size_t SOCK_MAXADDRLEN ; 
 void* SOCK_PROTO (struct tcpcb*) ; 
 short SOCK_STREAM ; 
 short SOCK_TYPE (struct tcpcb*) ; 
 void* SYSPROTO_CONTROL ; 
 void* SYSPROTO_EVENT ; 
 size_t TCPT_2MSL ; 
 size_t TCPT_KEEP ; 
 size_t TCPT_PERSIST ; 
 size_t TCPT_REXMT ; 
 size_t TSI_T_2MSL ; 
 size_t TSI_T_KEEP ; 
 size_t TSI_T_PERSIST ; 
 size_t TSI_T_REXMT ; 
 scalar_t__ VM_KERNEL_ADDRPERM (struct tcpcb*) ; 
 int /*<<< orphan*/  bcopy (TYPE_12__*,int /*<<< orphan*/ *,size_t) ; 
 int hz ; 
 int /*<<< orphan*/  kctl_fill_socketinfo (struct tcpcb*,struct socket_info*) ; 
 int /*<<< orphan*/  socket_lock (struct tcpcb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  socket_unlock (struct tcpcb*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int tick ; 

__attribute__((used)) static void
fill_sockbuf_info(struct sockbuf *sb, struct sockbuf_info *sbi)
{
	sbi->sbi_cc = sb->sb_cc;
	sbi->sbi_hiwat = sb->sb_hiwat;
	sbi->sbi_mbcnt = sb->sb_mbcnt;
	sbi->sbi_mbmax = sb->sb_mbmax;
	sbi->sbi_lowat = sb->sb_lowat;
	sbi->sbi_flags = sb->sb_flags;
	sbi->sbi_timeo = (u_int32_t)(sb->sb_timeo.tv_sec * hz) +
	    sb->sb_timeo.tv_usec / tick;
	if (sbi->sbi_timeo == 0 && sb->sb_timeo.tv_usec != 0)
		sbi->sbi_timeo = 1;
}

__attribute__((used)) static void
fill_common_sockinfo(struct socket *so, struct socket_info *si)
{
	si->soi_so = (u_int64_t)VM_KERNEL_ADDRPERM(so);
	si->soi_type = so->so_type;
	si->soi_options = (short)(so->so_options & 0xffff);
	si->soi_linger = so->so_linger;
	si->soi_state = so->so_state;
	si->soi_pcb = (u_int64_t)VM_KERNEL_ADDRPERM(so->so_pcb);
	if (so->so_proto) {
		si->soi_protocol = SOCK_PROTO(so);
		if (so->so_proto->pr_domain)
			si->soi_family = SOCK_DOM(so);
		else
			si->soi_family = 0;
	} else {
		si->soi_protocol = si->soi_family = 0;
	}
	si->soi_qlen = so->so_qlen;
	si->soi_incqlen = so->so_incqlen;
	si->soi_qlimit = so->so_qlimit;
	si->soi_timeo = so->so_timeo;
	si->soi_error = so->so_error;
	si->soi_oobmark = so->so_oobmark;
	fill_sockbuf_info(&so->so_snd, &si->soi_snd);
	fill_sockbuf_info(&so->so_rcv, &si->soi_rcv);
}

errno_t
fill_socketinfo(struct socket *so, struct socket_info *si)
{
	errno_t error = 0;
	int domain;
	short type;
	short protocol;

	socket_lock(so, 0);

	si->soi_kind = SOCKINFO_GENERIC;

	fill_common_sockinfo(so, si);

	if (so->so_pcb == NULL || so->so_proto == 0 ||
	    so->so_proto->pr_domain == NULL)
		goto out;

	/*
	 * The kind of socket is determined by the triplet
	 * {domain, type, protocol}
	 */
	domain = SOCK_DOM(so);
	type = SOCK_TYPE(so);
	protocol = SOCK_PROTO(so);
	switch (domain) {
	case PF_INET:
	case PF_INET6: {
		struct in_sockinfo *insi = &si->soi_proto.pri_in;
		struct inpcb *inp = (struct inpcb *)so->so_pcb;

		si->soi_kind = SOCKINFO_IN;

		insi->insi_fport = inp->inp_fport;
		insi->insi_lport = inp->inp_lport;
		insi->insi_gencnt = inp->inp_gencnt;
		insi->insi_flags = inp->inp_flags;
		insi->insi_vflag = inp->inp_vflag;
		insi->insi_ip_ttl = inp->inp_ip_ttl;
		insi->insi_faddr.ina_6 = inp->inp_dependfaddr.inp6_foreign;
		insi->insi_laddr.ina_6 = inp->inp_dependladdr.inp6_local;
		insi->insi_v4.in4_tos = inp->inp_depend4.inp4_ip_tos;
		insi->insi_v6.in6_hlim = 0;
		insi->insi_v6.in6_cksum = inp->inp_depend6.inp6_cksum;
		insi->insi_v6.in6_ifindex = 0;
		insi->insi_v6.in6_hops = inp->inp_depend6.inp6_hops;

		if (type == SOCK_STREAM && (protocol == 0 ||
		    protocol == IPPROTO_TCP) && inp->inp_ppcb != NULL) {
			struct tcp_sockinfo *tcpsi = &si->soi_proto.pri_tcp;
			struct tcpcb *tp = (struct tcpcb *)inp->inp_ppcb;

			si->soi_kind = SOCKINFO_TCP;

			tcpsi->tcpsi_state = tp->t_state;
			tcpsi->tcpsi_timer[TSI_T_REXMT] =
			    tp->t_timer[TCPT_REXMT];
			tcpsi->tcpsi_timer[TSI_T_PERSIST] =
			    tp->t_timer[TCPT_PERSIST];
			tcpsi->tcpsi_timer[TSI_T_KEEP] =
			    tp->t_timer[TCPT_KEEP];
			tcpsi->tcpsi_timer[TSI_T_2MSL] =
			    tp->t_timer[TCPT_2MSL];
			tcpsi->tcpsi_mss = tp->t_maxseg;
			tcpsi->tcpsi_flags = tp->t_flags;
			tcpsi->tcpsi_tp =
			    (u_int64_t)VM_KERNEL_ADDRPERM(tp);
		}
		break;
	}
	case PF_UNIX: {
		struct unpcb *unp = (struct unpcb *)so->so_pcb;
		struct un_sockinfo *unsi = &si->soi_proto.pri_un;

		si->soi_kind = SOCKINFO_UN;

		unsi->unsi_conn_pcb =
		    (uint64_t)VM_KERNEL_ADDRPERM(unp->unp_conn);
		if (unp->unp_conn)
			unsi->unsi_conn_so = (uint64_t)
			    VM_KERNEL_ADDRPERM(unp->unp_conn->unp_socket);

		if (unp->unp_addr) {
			size_t	addrlen = unp->unp_addr->sun_len;

			if (addrlen > SOCK_MAXADDRLEN)
				addrlen = SOCK_MAXADDRLEN;
			bcopy(unp->unp_addr, &unsi->unsi_addr, addrlen);
		}
		if (unp->unp_conn && unp->unp_conn->unp_addr) {
			size_t	addrlen = unp->unp_conn->unp_addr->sun_len;

			if (addrlen > SOCK_MAXADDRLEN)
				addrlen = SOCK_MAXADDRLEN;
			bcopy(unp->unp_conn->unp_addr, &unsi->unsi_caddr,
			    addrlen);
		}
		break;
	}
	case PF_NDRV: {
		struct ndrv_cb *ndrv_cb = (struct ndrv_cb *)so->so_pcb;
		struct ndrv_info *ndrvsi = &si->soi_proto.pri_ndrv;

		si->soi_kind = SOCKINFO_NDRV;

		/* TDB lock ifnet ???? */
		if (ndrv_cb->nd_if != 0) {
			struct ifnet *ifp = ndrv_cb->nd_if;

			ndrvsi->ndrvsi_if_family = ifp->if_family;
			ndrvsi->ndrvsi_if_unit = ifp->if_unit;
			strlcpy(ndrvsi->ndrvsi_if_name, ifp->if_name, IFNAMSIZ);
		}
		break;
	}
	case PF_SYSTEM:
		if (SOCK_PROTO(so) == SYSPROTO_EVENT) {
			struct kern_event_pcb *ev_pcb =
			    (struct kern_event_pcb *)so->so_pcb;
			struct kern_event_info *kesi =
			    &si->soi_proto.pri_kern_event;

			si->soi_kind = SOCKINFO_KERN_EVENT;

			kesi->kesi_vendor_code_filter =
			    ev_pcb->evp_vendor_code_filter;
			kesi->kesi_class_filter = ev_pcb->evp_class_filter;
			kesi->kesi_subclass_filter = ev_pcb->evp_subclass_filter;
		} else if (SOCK_PROTO(so) == SYSPROTO_CONTROL) {
			kctl_fill_socketinfo(so, si);
		}
		break;

	case PF_ROUTE:
	case PF_PPP:
	default:
		break;
	}
out:
	socket_unlock(so, 0);

	return (error);
}

