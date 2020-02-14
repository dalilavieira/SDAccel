#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u8 ;
typedef  scalar_t__ u16 ;
struct socket {scalar_t__ type; int /*<<< orphan*/  ops; int /*<<< orphan*/  state; } ;
typedef  struct sockaddr_pn {scalar_t__ spn_resource; } const sockaddr_pn ;
struct sock {int sk_protocol; int /*<<< orphan*/  sk_bound_dev_if; TYPE_1__* sk_prot; int /*<<< orphan*/  sk_backlog_rcv; } ;
struct sk_buff {int len; scalar_t__ pkt_type; struct net_device* dev; int /*<<< orphan*/  protocol; scalar_t__ priority; } ;
struct pn_sock {scalar_t__ sobject; scalar_t__ dobject; scalar_t__ resource; } ;
struct phonetmsg {scalar_t__ pn_msg_id; scalar_t__ pn_e_submsg_id; scalar_t__ pn_submsg_id; scalar_t__ pn_e_orig_msg_id; scalar_t__ pn_orig_msg_id; scalar_t__ pn_status; scalar_t__ pn_e_status; int /*<<< orphan*/  pn_e_res_id; int /*<<< orphan*/  pn_trans_id; } ;
struct phonethdr {scalar_t__ pn_rdev; scalar_t__ pn_sdev; scalar_t__ pn_res; int pn_robj; int pn_sobj; int /*<<< orphan*/  pn_length; } ;
struct phonet_protocol {scalar_t__ sock_type; TYPE_2__* prot; int /*<<< orphan*/  ops; } ;
struct packet_type {int dummy; } ;
struct net_device {void* dev_addr; int mtu; int flags; int /*<<< orphan*/  hard_header_len; int /*<<< orphan*/  name; } ;
struct net {int dummy; } ;
typedef  int /*<<< orphan*/  resp ;
typedef  int /*<<< orphan*/  data ;
struct TYPE_5__ {int /*<<< orphan*/  owner; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* init ) (struct sock*) ;int /*<<< orphan*/  backlog_rcv; } ;

/* Variables and functions */
 int /*<<< orphan*/  BUG_ON (int) ; 
 int /*<<< orphan*/  CAP_SYS_ADMIN ; 
 int EHOSTUNREACH ; 
 int EMSGSIZE ; 
 int ENOBUFS ; 
 int ENOMEM ; 
 int EOPNOTSUPP ; 
 int EPERM ; 
 int EPROTONOSUPPORT ; 
 unsigned short ETH_P_PHONET ; 
 int /*<<< orphan*/  GFP_ATOMIC ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int IFF_UP ; 
 scalar_t__ MAX_PHONET_HEADER ; 
 int NET_RX_DROP ; 
 int NET_RX_SUCCESS ; 
 scalar_t__ PACKET_LOOPBACK ; 
 int /*<<< orphan*/  PF_PHONET ; 
 unsigned int PHONET_NPROTO ; 
 scalar_t__ PNADDR_BROADCAST ; 
 scalar_t__ PN_COMMGR ; 
 scalar_t__ PN_COMMON_MESSAGE ; 
 scalar_t__ PN_COMM_ISA_ENTITY_NOT_REACHABLE_RESP ; 
 scalar_t__ PN_COMM_SERVICE_NOT_IDENTIFIED_RESP ; 
 scalar_t__ PN_NO_ADDR ; 
 scalar_t__ PN_PREFIX ; 
 int PN_PROTO_PHONET ; 
 int PN_PROTO_PIPE ; 
 int /*<<< orphan*/  RCU_INIT_POINTER (struct phonet_protocol const*,int /*<<< orphan*/ *) ; 
#define  SOCK_DGRAM 129 
#define  SOCK_SEQPACKET 128 
 int /*<<< orphan*/  SS_UNCONNECTED ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __cpu_to_be16 (int) ; 
 int /*<<< orphan*/  __skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  __skb_put (struct sk_buff*,int) ; 
 struct sk_buff* alloc_skb (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  capable (int /*<<< orphan*/ ) ; 
 struct net_device* dev_get_by_index (struct net*,int /*<<< orphan*/ ) ; 
 scalar_t__ dev_hard_header (struct sk_buff*,struct net_device*,unsigned short,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 struct net* dev_net (struct net_device*) ; 
 int /*<<< orphan*/  dev_put (struct net_device*) ; 
 int dev_queue_xmit (struct sk_buff*) ; 
 scalar_t__ get_unaligned_be16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  htons (unsigned short) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  memset (struct phonetmsg*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  module_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  net_dbg_ratelimited (char*,scalar_t__,...) ; 
 int net_xmit_errno (int) ; 
 scalar_t__ netif_rx (struct sk_buff*) ; 
 scalar_t__ netif_rx_ni (struct sk_buff*) ; 
 unsigned short ntohs (int /*<<< orphan*/ ) ; 
 scalar_t__ phonet_address_get (struct net_device*,scalar_t__) ; 
 scalar_t__ phonet_address_lookup (struct net*,scalar_t__) ; 
 struct net_device* phonet_device_get (struct net*) ; 
 struct net_device* phonet_route_output (struct net*,scalar_t__) ; 
 scalar_t__ pn_addr (scalar_t__) ; 
 int /*<<< orphan*/  pn_deliver_sock_broadcast (struct net*,struct sk_buff*) ; 
 void* pn_dev (scalar_t__) ; 
 struct sock* pn_find_sock_by_res (struct net*,scalar_t__) ; 
 struct sock* pn_find_sock_by_sa (struct net*,struct sockaddr_pn const*) ; 
 void* pn_hdr (struct sk_buff*) ; 
 struct phonetmsg* pn_msg (struct sk_buff*) ; 
 int pn_obj (scalar_t__) ; 
 scalar_t__ pn_object (scalar_t__,int) ; 
 struct pn_sock* pn_sk (struct sock*) ; 
 int /*<<< orphan*/  pn_skb_get_dst_sockaddr (struct sk_buff*,struct sockaddr_pn const*) ; 
 scalar_t__ pn_sockaddr_get_addr (struct sockaddr_pn const*) ; 
 scalar_t__ pn_sockaddr_get_object (struct sockaddr_pn const*) ; 
 scalar_t__ pn_sockaddr_get_resource (struct sockaddr_pn const*) ; 
 struct phonet_protocol const** proto_tab ; 
 int /*<<< orphan*/  proto_tab_lock ; 
 int /*<<< orphan*/  proto_unregister (TYPE_2__*) ; 
 int /*<<< orphan*/  pskb_may_pull (struct sk_buff*,int) ; 
 int /*<<< orphan*/  pskb_pull (struct sk_buff*,int) ; 
 scalar_t__ pskb_trim (struct sk_buff*,scalar_t__) ; 
 struct phonet_protocol* rcu_dereference (struct phonet_protocol const*) ; 
 int /*<<< orphan*/  rcu_read_lock () ; 
 int /*<<< orphan*/  rcu_read_unlock () ; 
 scalar_t__ request_module (char*,int /*<<< orphan*/ ,int) ; 
 struct sock* sk_alloc (struct net*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 int sk_receive_skb (struct sock*,struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  skb_copy_to_linear_data (struct sk_buff*,void const*,int) ; 
 scalar_t__ skb_cow_head (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int skb_headroom (struct sk_buff*) ; 
 scalar_t__* skb_mac_header (struct sk_buff const*) ; 
 int /*<<< orphan*/  skb_orphan (struct sk_buff*) ; 
 scalar_t__* skb_push (struct sk_buff*,int) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,scalar_t__) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reset_transport_header (struct sk_buff*) ; 
 struct sk_buff* skb_share_check (struct sk_buff*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sock_init_data (struct socket*,struct sock*) ; 
 struct net* sock_net (struct sock*) ; 
 int /*<<< orphan*/  sock_put (struct sock*) ; 
 int /*<<< orphan*/  stub1 (struct sock*) ; 
 int /*<<< orphan*/  synchronize_rcu () ; 
 int /*<<< orphan*/  try_module_get (int /*<<< orphan*/ ) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static const struct phonet_protocol *phonet_proto_get(unsigned int protocol)
{
	const struct phonet_protocol *pp;

	if (protocol >= PHONET_NPROTO)
		return NULL;

	rcu_read_lock();
	pp = rcu_dereference(proto_tab[protocol]);
	if (pp && !try_module_get(pp->prot->owner))
		pp = NULL;
	rcu_read_unlock();

	return pp;
}

__attribute__((used)) static inline void phonet_proto_put(const struct phonet_protocol *pp)
{
	module_put(pp->prot->owner);
}

__attribute__((used)) static int pn_socket_create(struct net *net, struct socket *sock, int protocol,
			    int kern)
{
	struct sock *sk;
	struct pn_sock *pn;
	const struct phonet_protocol *pnp;
	int err;

	if (!capable(CAP_SYS_ADMIN))
		return -EPERM;

	if (protocol == 0) {
		/* Default protocol selection */
		switch (sock->type) {
		case SOCK_DGRAM:
			protocol = PN_PROTO_PHONET;
			break;
		case SOCK_SEQPACKET:
			protocol = PN_PROTO_PIPE;
			break;
		default:
			return -EPROTONOSUPPORT;
		}
	}

	pnp = phonet_proto_get(protocol);
	if (pnp == NULL &&
	    request_module("net-pf-%d-proto-%d", PF_PHONET, protocol) == 0)
		pnp = phonet_proto_get(protocol);

	if (pnp == NULL)
		return -EPROTONOSUPPORT;
	if (sock->type != pnp->sock_type) {
		err = -EPROTONOSUPPORT;
		goto out;
	}

	sk = sk_alloc(net, PF_PHONET, GFP_KERNEL, pnp->prot, kern);
	if (sk == NULL) {
		err = -ENOMEM;
		goto out;
	}

	sock_init_data(sock, sk);
	sock->state = SS_UNCONNECTED;
	sock->ops = pnp->ops;
	sk->sk_backlog_rcv = sk->sk_prot->backlog_rcv;
	sk->sk_protocol = protocol;
	pn = pn_sk(sk);
	pn->sobject = 0;
	pn->dobject = 0;
	pn->resource = 0;
	sk->sk_prot->init(sk);
	err = 0;

out:
	phonet_proto_put(pnp);
	return err;
}

__attribute__((used)) static int pn_header_create(struct sk_buff *skb, struct net_device *dev,
				unsigned short type, const void *daddr,
				const void *saddr, unsigned int len)
{
	u8 *media = skb_push(skb, 1);

	if (type != ETH_P_PHONET)
		return -1;

	if (!saddr)
		saddr = dev->dev_addr;
	*media = *(const u8 *)saddr;
	return 1;
}

__attribute__((used)) static int pn_header_parse(const struct sk_buff *skb, unsigned char *haddr)
{
	const u8 *media = skb_mac_header(skb);
	*haddr = *media;
	return 1;
}

__attribute__((used)) static int pn_send(struct sk_buff *skb, struct net_device *dev,
			u16 dst, u16 src, u8 res, u8 irq)
{
	struct phonethdr *ph;
	int err;

	if (skb->len + 2 > 0xffff /* Phonet length field limit */ ||
	    skb->len + sizeof(struct phonethdr) > dev->mtu) {
		err = -EMSGSIZE;
		goto drop;
	}

	/* Broadcast sending is not implemented */
	if (pn_addr(dst) == PNADDR_BROADCAST) {
		err = -EOPNOTSUPP;
		goto drop;
	}

	skb_reset_transport_header(skb);
	WARN_ON(skb_headroom(skb) & 1); /* HW assumes word alignment */
	skb_push(skb, sizeof(struct phonethdr));
	skb_reset_network_header(skb);
	ph = pn_hdr(skb);
	ph->pn_rdev = pn_dev(dst);
	ph->pn_sdev = pn_dev(src);
	ph->pn_res = res;
	ph->pn_length = __cpu_to_be16(skb->len + 2 - sizeof(*ph));
	ph->pn_robj = pn_obj(dst);
	ph->pn_sobj = pn_obj(src);

	skb->protocol = htons(ETH_P_PHONET);
	skb->priority = 0;
	skb->dev = dev;

	if (skb->pkt_type == PACKET_LOOPBACK) {
		skb_reset_mac_header(skb);
		skb_orphan(skb);
		err = (irq ? netif_rx(skb) : netif_rx_ni(skb)) ? -ENOBUFS : 0;
	} else {
		err = dev_hard_header(skb, dev, ntohs(skb->protocol),
					NULL, NULL, skb->len);
		if (err < 0) {
			err = -EHOSTUNREACH;
			goto drop;
		}
		err = dev_queue_xmit(skb);
		if (unlikely(err > 0))
			err = net_xmit_errno(err);
	}

	return err;
drop:
	kfree_skb(skb);
	return err;
}

__attribute__((used)) static int pn_raw_send(const void *data, int len, struct net_device *dev,
			u16 dst, u16 src, u8 res)
{
	struct sk_buff *skb = alloc_skb(MAX_PHONET_HEADER + len, GFP_ATOMIC);
	if (skb == NULL)
		return -ENOMEM;

	if (phonet_address_lookup(dev_net(dev), pn_addr(dst)) == 0)
		skb->pkt_type = PACKET_LOOPBACK;

	skb_reserve(skb, MAX_PHONET_HEADER);
	__skb_put(skb, len);
	skb_copy_to_linear_data(skb, data, len);
	return pn_send(skb, dev, dst, src, res, 1);
}

int pn_skb_send(struct sock *sk, struct sk_buff *skb,
		const struct sockaddr_pn *target)
{
	struct net *net = sock_net(sk);
	struct net_device *dev;
	struct pn_sock *pn = pn_sk(sk);
	int err;
	u16 src, dst;
	u8 daddr, saddr, res;

	src = pn->sobject;
	if (target != NULL) {
		dst = pn_sockaddr_get_object(target);
		res = pn_sockaddr_get_resource(target);
	} else {
		dst = pn->dobject;
		res = pn->resource;
	}
	daddr = pn_addr(dst);

	err = -EHOSTUNREACH;
	if (sk->sk_bound_dev_if)
		dev = dev_get_by_index(net, sk->sk_bound_dev_if);
	else if (phonet_address_lookup(net, daddr) == 0) {
		dev = phonet_device_get(net);
		skb->pkt_type = PACKET_LOOPBACK;
	} else if (dst == 0) {
		/* Resource routing (small race until phonet_rcv()) */
		struct sock *sk = pn_find_sock_by_res(net, res);
		if (sk)	{
			sock_put(sk);
			dev = phonet_device_get(net);
			skb->pkt_type = PACKET_LOOPBACK;
		} else
			dev = phonet_route_output(net, daddr);
	} else
		dev = phonet_route_output(net, daddr);

	if (!dev || !(dev->flags & IFF_UP))
		goto drop;

	saddr = phonet_address_get(dev, daddr);
	if (saddr == PN_NO_ADDR)
		goto drop;

	if (!pn_addr(src))
		src = pn_object(saddr, pn_obj(src));

	err = pn_send(skb, dev, dst, src, res, 0);
	dev_put(dev);
	return err;

drop:
	kfree_skb(skb);
	if (dev)
		dev_put(dev);
	return err;
}

__attribute__((used)) static inline int can_respond(struct sk_buff *skb)
{
	const struct phonethdr *ph;
	const struct phonetmsg *pm;
	u8 submsg_id;

	if (!pskb_may_pull(skb, 3))
		return 0;

	ph = pn_hdr(skb);
	if (ph->pn_res == PN_PREFIX && !pskb_may_pull(skb, 5))
		return 0;
	if (ph->pn_res == PN_COMMGR) /* indications */
		return 0;

	ph = pn_hdr(skb); /* re-acquires the pointer */
	pm = pn_msg(skb);
	if (pm->pn_msg_id != PN_COMMON_MESSAGE)
		return 1;
	submsg_id = (ph->pn_res == PN_PREFIX)
		? pm->pn_e_submsg_id : pm->pn_submsg_id;
	if (submsg_id != PN_COMM_ISA_ENTITY_NOT_REACHABLE_RESP &&
		pm->pn_e_submsg_id != PN_COMM_SERVICE_NOT_IDENTIFIED_RESP)
		return 1;
	return 0;
}

__attribute__((used)) static int send_obj_unreachable(struct sk_buff *rskb)
{
	const struct phonethdr *oph = pn_hdr(rskb);
	const struct phonetmsg *opm = pn_msg(rskb);
	struct phonetmsg resp;

	memset(&resp, 0, sizeof(resp));
	resp.pn_trans_id = opm->pn_trans_id;
	resp.pn_msg_id = PN_COMMON_MESSAGE;
	if (oph->pn_res == PN_PREFIX) {
		resp.pn_e_res_id = opm->pn_e_res_id;
		resp.pn_e_submsg_id = PN_COMM_ISA_ENTITY_NOT_REACHABLE_RESP;
		resp.pn_e_orig_msg_id = opm->pn_msg_id;
		resp.pn_e_status = 0;
	} else {
		resp.pn_submsg_id = PN_COMM_ISA_ENTITY_NOT_REACHABLE_RESP;
		resp.pn_orig_msg_id = opm->pn_msg_id;
		resp.pn_status = 0;
	}
	return pn_raw_send(&resp, sizeof(resp), rskb->dev,
				pn_object(oph->pn_sdev, oph->pn_sobj),
				pn_object(oph->pn_rdev, oph->pn_robj),
				oph->pn_res);
}

__attribute__((used)) static int send_reset_indications(struct sk_buff *rskb)
{
	struct phonethdr *oph = pn_hdr(rskb);
	static const u8 data[4] = {
		0x00 /* trans ID */, 0x10 /* subscribe msg */,
		0x00 /* subscription count */, 0x00 /* dummy */
	};

	return pn_raw_send(data, sizeof(data), rskb->dev,
				pn_object(oph->pn_sdev, 0x00),
				pn_object(oph->pn_rdev, oph->pn_robj),
				PN_COMMGR);
}

__attribute__((used)) static int phonet_rcv(struct sk_buff *skb, struct net_device *dev,
			struct packet_type *pkttype,
			struct net_device *orig_dev)
{
	struct net *net = dev_net(dev);
	struct phonethdr *ph;
	struct sockaddr_pn sa;
	u16 len;

	skb = skb_share_check(skb, GFP_ATOMIC);
	if (!skb)
		return NET_RX_DROP;

	/* check we have at least a full Phonet header */
	if (!pskb_pull(skb, sizeof(struct phonethdr)))
		goto out;

	/* check that the advertised length is correct */
	ph = pn_hdr(skb);
	len = get_unaligned_be16(&ph->pn_length);
	if (len < 2)
		goto out;
	len -= 2;
	if ((len > skb->len) || pskb_trim(skb, len))
		goto out;
	skb_reset_transport_header(skb);

	pn_skb_get_dst_sockaddr(skb, &sa);

	/* check if this is broadcasted */
	if (pn_sockaddr_get_addr(&sa) == PNADDR_BROADCAST) {
		pn_deliver_sock_broadcast(net, skb);
		goto out;
	}

	/* resource routing */
	if (pn_sockaddr_get_object(&sa) == 0) {
		struct sock *sk = pn_find_sock_by_res(net, sa.spn_resource);
		if (sk)
			return sk_receive_skb(sk, skb, 0);
	}

	/* check if we are the destination */
	if (phonet_address_lookup(net, pn_sockaddr_get_addr(&sa)) == 0) {
		/* Phonet packet input */
		struct sock *sk = pn_find_sock_by_sa(net, &sa);

		if (sk)
			return sk_receive_skb(sk, skb, 0);

		if (can_respond(skb)) {
			send_obj_unreachable(skb);
			send_reset_indications(skb);
		}
	} else if (unlikely(skb->pkt_type == PACKET_LOOPBACK))
		goto out; /* Race between address deletion and loopback */
	else {
		/* Phonet packet routing */
		struct net_device *out_dev;

		out_dev = phonet_route_output(net, pn_sockaddr_get_addr(&sa));
		if (!out_dev) {
			net_dbg_ratelimited("No Phonet route to %02X\n",
					    pn_sockaddr_get_addr(&sa));
			goto out;
		}

		__skb_push(skb, sizeof(struct phonethdr));
		skb->dev = out_dev;
		if (out_dev == dev) {
			net_dbg_ratelimited("Phonet loop to %02X on %s\n",
					    pn_sockaddr_get_addr(&sa),
					    dev->name);
			goto out_dev;
		}
		/* Some drivers (e.g. TUN) do not allocate HW header space */
		if (skb_cow_head(skb, out_dev->hard_header_len))
			goto out_dev;

		if (dev_hard_header(skb, out_dev, ETH_P_PHONET, NULL, NULL,
					skb->len) < 0)
			goto out_dev;
		dev_queue_xmit(skb);
		dev_put(out_dev);
		return NET_RX_SUCCESS;
out_dev:
		dev_put(out_dev);
	}

out:
	kfree_skb(skb);
	return NET_RX_DROP;
}

void phonet_proto_unregister(unsigned int protocol,
			const struct phonet_protocol *pp)
{
	mutex_lock(&proto_tab_lock);
	BUG_ON(proto_tab[protocol] != pp);
	RCU_INIT_POINTER(proto_tab[protocol], NULL);
	mutex_unlock(&proto_tab_lock);
	synchronize_rcu();
	proto_unregister(pp->prot);
}

