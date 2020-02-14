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
typedef  scalar_t__ u32 ;
struct tcphdr {void* seq; int doff; void* ack_seq; int /*<<< orphan*/  check; int /*<<< orphan*/  ack; } ;
struct tcp_sack_block_wire {void* start_seq; void* end_seq; } ;
struct sk_buff {unsigned char* data; } ;
struct nf_ct_seqadj {scalar_t__ offset_before; scalar_t__ offset_after; scalar_t__ correction_pos; } ;
struct nf_conn_seqadj {struct nf_ct_seqadj* seq; } ;
typedef  struct nf_conn {int /*<<< orphan*/  lock; int /*<<< orphan*/  status; } const nf_conn ;
typedef  scalar_t__ s32 ;
typedef  enum ip_conntrack_info { ____Placeholder_ip_conntrack_info } ip_conntrack_info ;
typedef  enum ip_conntrack_dir { ____Placeholder_ip_conntrack_dir } ip_conntrack_dir ;
typedef  void* __be32 ;

/* Variables and functions */
 void* CTINFO2DIR (int) ; 
 scalar_t__ IPPROTO_TCP ; 
 int /*<<< orphan*/  IPS_SEQ_ADJUST_BIT ; 
 unsigned char TCPOLEN_SACK_PERBLOCK ; 
#define  TCPOPT_EOL 129 
#define  TCPOPT_NOP 128 
 unsigned char TCPOPT_SACK ; 
 int /*<<< orphan*/  WARN_ONCE (int,char*) ; 
 scalar_t__ after (scalar_t__,scalar_t__) ; 
 scalar_t__ before (scalar_t__,scalar_t__) ; 
 void* htonl (scalar_t__) ; 
 int /*<<< orphan*/  inet_proto_csum_replace4 (int /*<<< orphan*/ *,struct sk_buff*,void*,void*,int) ; 
 scalar_t__ ip_hdrlen (struct sk_buff*) ; 
 int nf_ct_extend_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  nf_ct_extend_unregister (int /*<<< orphan*/ *) ; 
 scalar_t__ nf_ct_protonum (struct nf_conn const*) ; 
 int /*<<< orphan*/  nf_ct_seqadj_extend ; 
 struct nf_conn_seqadj* nfct_seqadj (struct nf_conn const*) ; 
 scalar_t__ ntohl (void*) ; 
 int /*<<< orphan*/  pr_debug (char*,scalar_t__,scalar_t__,...) ; 
 int /*<<< orphan*/  set_bit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  skb_make_writable (struct sk_buff*,unsigned int) ; 
 scalar_t__ skb_network_header (struct sk_buff*) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 scalar_t__ unlikely (int) ; 

int nf_ct_seqadj_init(struct nf_conn *ct, enum ip_conntrack_info ctinfo,
		      s32 off)
{
	enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
	struct nf_conn_seqadj *seqadj;
	struct nf_ct_seqadj *this_way;

	if (off == 0)
		return 0;

	set_bit(IPS_SEQ_ADJUST_BIT, &ct->status);

	seqadj = nfct_seqadj(ct);
	this_way = &seqadj->seq[dir];
	this_way->offset_before	 = off;
	this_way->offset_after	 = off;
	return 0;
}

int nf_ct_seqadj_set(struct nf_conn *ct, enum ip_conntrack_info ctinfo,
		     __be32 seq, s32 off)
{
	struct nf_conn_seqadj *seqadj = nfct_seqadj(ct);
	enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
	struct nf_ct_seqadj *this_way;

	if (off == 0)
		return 0;

	if (unlikely(!seqadj)) {
		WARN_ONCE(1, "Missing nfct_seqadj_ext_add() setup call\n");
		return 0;
	}

	set_bit(IPS_SEQ_ADJUST_BIT, &ct->status);

	spin_lock_bh(&ct->lock);
	this_way = &seqadj->seq[dir];
	if (this_way->offset_before == this_way->offset_after ||
	    before(this_way->correction_pos, ntohl(seq))) {
		this_way->correction_pos = ntohl(seq);
		this_way->offset_before	 = this_way->offset_after;
		this_way->offset_after	+= off;
	}
	spin_unlock_bh(&ct->lock);
	return 0;
}

void nf_ct_tcp_seqadj_set(struct sk_buff *skb,
			  struct nf_conn *ct, enum ip_conntrack_info ctinfo,
			  s32 off)
{
	const struct tcphdr *th;

	if (nf_ct_protonum(ct) != IPPROTO_TCP)
		return;

	th = (struct tcphdr *)(skb_network_header(skb) + ip_hdrlen(skb));
	nf_ct_seqadj_set(ct, ctinfo, th->seq, off);
}

__attribute__((used)) static void nf_ct_sack_block_adjust(struct sk_buff *skb,
				    struct tcphdr *tcph,
				    unsigned int sackoff,
				    unsigned int sackend,
				    struct nf_ct_seqadj *seq)
{
	while (sackoff < sackend) {
		struct tcp_sack_block_wire *sack;
		__be32 new_start_seq, new_end_seq;

		sack = (void *)skb->data + sackoff;
		if (after(ntohl(sack->start_seq) - seq->offset_before,
			  seq->correction_pos))
			new_start_seq = htonl(ntohl(sack->start_seq) -
					seq->offset_after);
		else
			new_start_seq = htonl(ntohl(sack->start_seq) -
					seq->offset_before);

		if (after(ntohl(sack->end_seq) - seq->offset_before,
			  seq->correction_pos))
			new_end_seq = htonl(ntohl(sack->end_seq) -
				      seq->offset_after);
		else
			new_end_seq = htonl(ntohl(sack->end_seq) -
				      seq->offset_before);

		pr_debug("sack_adjust: start_seq: %u->%u, end_seq: %u->%u\n",
			 ntohl(sack->start_seq), ntohl(new_start_seq),
			 ntohl(sack->end_seq), ntohl(new_end_seq));

		inet_proto_csum_replace4(&tcph->check, skb,
					 sack->start_seq, new_start_seq, false);
		inet_proto_csum_replace4(&tcph->check, skb,
					 sack->end_seq, new_end_seq, false);
		sack->start_seq = new_start_seq;
		sack->end_seq = new_end_seq;
		sackoff += sizeof(*sack);
	}
}

__attribute__((used)) static unsigned int nf_ct_sack_adjust(struct sk_buff *skb,
				      unsigned int protoff,
				      struct nf_conn *ct,
				      enum ip_conntrack_info ctinfo)
{
	struct tcphdr *tcph = (void *)skb->data + protoff;
	struct nf_conn_seqadj *seqadj = nfct_seqadj(ct);
	unsigned int dir, optoff, optend;

	optoff = protoff + sizeof(struct tcphdr);
	optend = protoff + tcph->doff * 4;

	if (!skb_make_writable(skb, optend))
		return 0;

	tcph = (void *)skb->data + protoff;
	dir = CTINFO2DIR(ctinfo);

	while (optoff < optend) {
		/* Usually: option, length. */
		unsigned char *op = skb->data + optoff;

		switch (op[0]) {
		case TCPOPT_EOL:
			return 1;
		case TCPOPT_NOP:
			optoff++;
			continue;
		default:
			/* no partial options */
			if (optoff + 1 == optend ||
			    optoff + op[1] > optend ||
			    op[1] < 2)
				return 0;
			if (op[0] == TCPOPT_SACK &&
			    op[1] >= 2+TCPOLEN_SACK_PERBLOCK &&
			    ((op[1] - 2) % TCPOLEN_SACK_PERBLOCK) == 0)
				nf_ct_sack_block_adjust(skb, tcph, optoff + 2,
							optoff+op[1],
							&seqadj->seq[!dir]);
			optoff += op[1];
		}
	}
	return 1;
}

int nf_ct_seq_adjust(struct sk_buff *skb,
		     struct nf_conn *ct, enum ip_conntrack_info ctinfo,
		     unsigned int protoff)
{
	enum ip_conntrack_dir dir = CTINFO2DIR(ctinfo);
	struct tcphdr *tcph;
	__be32 newseq, newack;
	s32 seqoff, ackoff;
	struct nf_conn_seqadj *seqadj = nfct_seqadj(ct);
	struct nf_ct_seqadj *this_way, *other_way;
	int res = 1;

	this_way  = &seqadj->seq[dir];
	other_way = &seqadj->seq[!dir];

	if (!skb_make_writable(skb, protoff + sizeof(*tcph)))
		return 0;

	tcph = (void *)skb->data + protoff;
	spin_lock_bh(&ct->lock);
	if (after(ntohl(tcph->seq), this_way->correction_pos))
		seqoff = this_way->offset_after;
	else
		seqoff = this_way->offset_before;

	newseq = htonl(ntohl(tcph->seq) + seqoff);
	inet_proto_csum_replace4(&tcph->check, skb, tcph->seq, newseq, false);
	pr_debug("Adjusting sequence number from %u->%u\n",
		 ntohl(tcph->seq), ntohl(newseq));
	tcph->seq = newseq;

	if (!tcph->ack)
		goto out;

	if (after(ntohl(tcph->ack_seq) - other_way->offset_before,
		  other_way->correction_pos))
		ackoff = other_way->offset_after;
	else
		ackoff = other_way->offset_before;

	newack = htonl(ntohl(tcph->ack_seq) - ackoff);
	inet_proto_csum_replace4(&tcph->check, skb, tcph->ack_seq, newack,
				 false);
	pr_debug("Adjusting ack number from %u->%u, ack from %u->%u\n",
		 ntohl(tcph->seq), ntohl(newseq), ntohl(tcph->ack_seq),
		 ntohl(newack));
	tcph->ack_seq = newack;

	res = nf_ct_sack_adjust(skb, protoff, ct, ctinfo);
out:
	spin_unlock_bh(&ct->lock);

	return res;
}

s32 nf_ct_seq_offset(const struct nf_conn *ct,
		     enum ip_conntrack_dir dir,
		     u32 seq)
{
	struct nf_conn_seqadj *seqadj = nfct_seqadj(ct);
	struct nf_ct_seqadj *this_way;

	if (!seqadj)
		return 0;

	this_way = &seqadj->seq[dir];
	return after(seq, this_way->correction_pos) ?
		 this_way->offset_after : this_way->offset_before;
}

int nf_conntrack_seqadj_init(void)
{
	return nf_ct_extend_register(&nf_ct_seqadj_extend);
}

void nf_conntrack_seqadj_fini(void)
{
	nf_ct_extend_unregister(&nf_ct_seqadj_extend);
}

