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
struct stp_proto {scalar_t__* group_address; int /*<<< orphan*/  (* rcv ) (struct stp_proto const*,struct sk_buff*,struct net_device*) ;} ;
struct sk_buff {int dummy; } ;
struct packet_type {int dummy; } ;
struct net_device {int dummy; } ;
struct llc_pdu_un {scalar_t__ ssap; scalar_t__ dsap; scalar_t__ ctrl_1; } ;
struct ethhdr {scalar_t__* h_dest; } ;

/* Variables and functions */
 int ENOMEM ; 
 scalar_t__ GARP_ADDR_MAX ; 
 scalar_t__ GARP_ADDR_MIN ; 
 scalar_t__ LLC_PDU_TYPE_U ; 
 scalar_t__ LLC_SAP_BSPAN ; 
 int /*<<< orphan*/  RCU_INIT_POINTER (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 struct ethhdr* eth_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  ether_addr_equal (scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/ * garp_protos ; 
 scalar_t__ is_zero_ether_addr (scalar_t__*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 struct llc_pdu_un* llc_pdu_un_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  llc_sap_open (scalar_t__,int (*) (struct sk_buff*,struct net_device*,struct packet_type*,struct net_device*)) ; 
 int /*<<< orphan*/  llc_sap_put (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rcu_assign_pointer (int /*<<< orphan*/ ,struct stp_proto const*) ; 
 struct stp_proto* rcu_dereference (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sap ; 
 scalar_t__ sap_registered ; 
 int /*<<< orphan*/  stp_proto ; 
 int /*<<< orphan*/  stp_proto_mutex ; 
 int /*<<< orphan*/  stub1 (struct stp_proto const*,struct sk_buff*,struct net_device*) ; 
 int /*<<< orphan*/  synchronize_rcu () ; 

__attribute__((used)) static int stp_pdu_rcv(struct sk_buff *skb, struct net_device *dev,
		       struct packet_type *pt, struct net_device *orig_dev)
{
	const struct ethhdr *eh = eth_hdr(skb);
	const struct llc_pdu_un *pdu = llc_pdu_un_hdr(skb);
	const struct stp_proto *proto;

	if (pdu->ssap != LLC_SAP_BSPAN ||
	    pdu->dsap != LLC_SAP_BSPAN ||
	    pdu->ctrl_1 != LLC_PDU_TYPE_U)
		goto err;

	if (eh->h_dest[5] >= GARP_ADDR_MIN && eh->h_dest[5] <= GARP_ADDR_MAX) {
		proto = rcu_dereference(garp_protos[eh->h_dest[5] -
						    GARP_ADDR_MIN]);
		if (proto &&
		    !ether_addr_equal(eh->h_dest, proto->group_address))
			goto err;
	} else
		proto = rcu_dereference(stp_proto);

	if (!proto)
		goto err;

	proto->rcv(proto, skb, dev);
	return 0;

err:
	kfree_skb(skb);
	return 0;
}

int stp_proto_register(const struct stp_proto *proto)
{
	int err = 0;

	mutex_lock(&stp_proto_mutex);
	if (sap_registered++ == 0) {
		sap = llc_sap_open(LLC_SAP_BSPAN, stp_pdu_rcv);
		if (!sap) {
			err = -ENOMEM;
			goto out;
		}
	}
	if (is_zero_ether_addr(proto->group_address))
		rcu_assign_pointer(stp_proto, proto);
	else
		rcu_assign_pointer(garp_protos[proto->group_address[5] -
					       GARP_ADDR_MIN], proto);
out:
	mutex_unlock(&stp_proto_mutex);
	return err;
}

void stp_proto_unregister(const struct stp_proto *proto)
{
	mutex_lock(&stp_proto_mutex);
	if (is_zero_ether_addr(proto->group_address))
		RCU_INIT_POINTER(stp_proto, NULL);
	else
		RCU_INIT_POINTER(garp_protos[proto->group_address[5] -
					       GARP_ADDR_MIN], NULL);
	synchronize_rcu();

	if (--sap_registered == 0)
		llc_sap_put(sap);
	mutex_unlock(&stp_proto_mutex);
}

