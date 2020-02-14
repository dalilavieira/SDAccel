#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_9__ ;
typedef  struct TYPE_24__   TYPE_8__ ;
typedef  struct TYPE_23__   TYPE_7__ ;
typedef  struct TYPE_22__   TYPE_6__ ;
typedef  struct TYPE_21__   TYPE_5__ ;
typedef  struct TYPE_20__   TYPE_4__ ;
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;
typedef  struct TYPE_16__   TYPE_13__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;

/* Type definitions */
typedef  unsigned int u8 ;
typedef  int u64 ;
typedef  size_t u32 ;
typedef  int u16 ;
struct TYPE_23__ {scalar_t__ offload_handle; } ;
struct TYPE_19__ {unsigned int mode; } ;
struct xfrm_state {TYPE_7__ xso; TYPE_3__ props; struct xfrm_replay_state_esn* replay_esn; int /*<<< orphan*/  data; } ;
struct xfrm_replay_state_esn {scalar_t__ oseq; } ;
struct TYPE_17__ {size_t hi; scalar_t__ low; } ;
struct xfrm_offload {scalar_t__ proto; int /*<<< orphan*/  status; int /*<<< orphan*/  flags; TYPE_1__ seq; } ;
struct tcphdr {int /*<<< orphan*/  seq; scalar_t__ dest; scalar_t__ source; } ;
struct sk_buff {int mac_header; unsigned int len; scalar_t__ protocol; int network_header; unsigned int transport_header; int inner_network_header; int inner_transport_header; TYPE_9__* sp; scalar_t__ data; int /*<<< orphan*/  dev; } ;
struct net_device {int dummy; } ;
struct mlx5_wqe_eth_seg {int swp_outer_l3_offset; int swp_inner_l3_offset; int swp_inner_l4_offset; int /*<<< orphan*/  swp_flags; } ;
struct mlx5e_tx_wqe {struct mlx5_wqe_eth_seg eth; } ;
struct mlx5e_priv {TYPE_11__* ipsec; } ;
struct mlx5e_ipsec_sa_entry {int /*<<< orphan*/  (* set_iv_op ) (struct sk_buff*,struct xfrm_state*,struct xfrm_offload*) ;} ;
struct TYPE_20__ {unsigned int nexthdr; int /*<<< orphan*/  sa_handle; } ;
struct TYPE_18__ {unsigned int esp_next_proto; scalar_t__ seq; scalar_t__ mss_inv; } ;
struct TYPE_21__ {TYPE_4__ rx; TYPE_2__ tx; int /*<<< orphan*/  raw; } ;
struct mlx5e_ipsec_metadata {int syndrome; TYPE_5__ content; } ;
struct ipv6hdr {scalar_t__ payload_len; } ;
struct iphdr {scalar_t__ tot_len; } ;
struct ip_esp_hdr {int /*<<< orphan*/  seq_no; } ;
struct ethhdr {int /*<<< orphan*/  h_proto; } ;
typedef  int /*<<< orphan*/  netdev_features_t ;
typedef  scalar_t__ __u32 ;
typedef  int /*<<< orphan*/  __be64 ;
typedef  scalar_t__ __be16 ;
struct TYPE_25__ {int len; struct xfrm_state** xvec; int /*<<< orphan*/  olen; } ;
struct TYPE_24__ {size_t gso_size; scalar_t__ gso_segs; } ;
struct TYPE_22__ {int /*<<< orphan*/  ipsec_rx_drop_syndrome; int /*<<< orphan*/  ipsec_rx_drop_sadb_miss; int /*<<< orphan*/  ipsec_rx_drop_sp_alloc; int /*<<< orphan*/  ipsec_tx_drop_metadata; int /*<<< orphan*/  ipsec_tx_drop_trailer; int /*<<< orphan*/  ipsec_tx_drop_not_ip; int /*<<< orphan*/  ipsec_tx_drop_no_state; int /*<<< orphan*/  ipsec_tx_drop_bundle; } ;
struct TYPE_16__ {unsigned int protocol; } ;
struct TYPE_15__ {unsigned int nexthdr; } ;
struct TYPE_14__ {TYPE_6__ sw_stats; int /*<<< orphan*/  no_trailer; } ;

/* Variables and functions */
 int /*<<< orphan*/  CRYPTO_DONE ; 
 int /*<<< orphan*/  CRYPTO_INVALID_PROTOCOL ; 
 int /*<<< orphan*/  CRYPTO_SUCCESS ; 
 int /*<<< orphan*/  CRYPTO_TUNNEL_ESP_AUTH_FAILED ; 
 int /*<<< orphan*/  ENOMEM ; 
 struct mlx5e_ipsec_metadata* ERR_PTR (int /*<<< orphan*/ ) ; 
 int ETH_ALEN ; 
 scalar_t__ ETH_HLEN ; 
 int ETH_P_IP ; 
 int ETH_P_IPV6 ; 
 scalar_t__ IPPROTO_IPV6 ; 
#define  IPPROTO_TCP 132 
#define  IPPROTO_UDP 131 
 scalar_t__ IS_ERR (struct mlx5e_ipsec_metadata*) ; 
 size_t MAX_LSO_MSS ; 
 scalar_t__ MLX5E_IPSEC_ESN_SCOPE_MID ; 
#define  MLX5E_IPSEC_RX_SYNDROME_AUTH_FAILED 130 
#define  MLX5E_IPSEC_RX_SYNDROME_BAD_PROTO 129 
#define  MLX5E_IPSEC_RX_SYNDROME_DECRYPTED 128 
 int MLX5E_IPSEC_TX_SYNDROME_OFFLOAD ; 
 int MLX5E_IPSEC_TX_SYNDROME_OFFLOAD_WITH_LSO_TCP ; 
 scalar_t__ MLX5E_METADATA_ETHER_LEN ; 
 int /*<<< orphan*/  MLX5E_METADATA_ETHER_TYPE ; 
 int /*<<< orphan*/  MLX5_ETH_WQE_SWP_INNER_L3_IPV6 ; 
 int /*<<< orphan*/  MLX5_ETH_WQE_SWP_INNER_L4_UDP ; 
 int /*<<< orphan*/  MLX5_ETH_WQE_SWP_OUTER_L3_IPV6 ; 
 int /*<<< orphan*/  XFRM_ESP_NO_TRAILER ; 
 unsigned int XFRM_MODE_TUNNEL ; 
 int /*<<< orphan*/  atomic64_inc (int /*<<< orphan*/ *) ; 
 size_t be32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be64 (scalar_t__) ; 
 unsigned int crypto_aead_authsize (int /*<<< orphan*/ ) ; 
 int div_u64 (unsigned long long,size_t) ; 
 scalar_t__ htons (int) ; 
 TYPE_13__* inner_ip_hdr (struct sk_buff*) ; 
 TYPE_12__* inner_ipv6_hdr (struct sk_buff*) ; 
 struct tcphdr* inner_tcp_hdr (struct sk_buff*) ; 
 struct ip_esp_hdr* ip_esp_hdr (struct sk_buff*) ; 
 struct iphdr* ip_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  ip_send_check (struct iphdr*) ; 
 struct ipv6hdr* ipv6_hdr (struct sk_buff*) ; 
 int /*<<< orphan*/  is_metadata_hdr_valid (struct sk_buff*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  likely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memmove (scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 scalar_t__* mlx5e_ipsec_inverse_table ; 
 struct xfrm_state* mlx5e_ipsec_sadb_rx_lookup (TYPE_11__*,size_t) ; 
 int /*<<< orphan*/  netdev_dbg (int /*<<< orphan*/ ,char*,int,unsigned int,int,int,...) ; 
 struct mlx5e_priv* netdev_priv (struct net_device*) ; 
 int ntohl (int /*<<< orphan*/ ) ; 
 int ntohs (scalar_t__) ; 
 int /*<<< orphan*/  pskb_trim (struct sk_buff*,unsigned int) ; 
 int /*<<< orphan*/  remove_metadata_hdr (struct sk_buff*) ; 
 TYPE_9__* secpath_dup (TYPE_9__*) ; 
 int skb_copy_bits (struct sk_buff*,unsigned int,unsigned int*,int) ; 
 int skb_cow_head (struct sk_buff*,int) ; 
 int skb_inner_network_offset (struct sk_buff*) ; 
 int skb_inner_transport_offset (struct sk_buff*) ; 
 scalar_t__ skb_is_gso (struct sk_buff*) ; 
 int skb_network_offset (struct sk_buff*) ; 
 scalar_t__ skb_push (struct sk_buff*,int) ; 
 TYPE_8__* skb_shinfo (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_store_bits (struct sk_buff*,int,int /*<<< orphan*/ *,int) ; 
 int skb_transport_offset (struct sk_buff*) ; 
 int /*<<< orphan*/  stub1 (struct sk_buff*,struct xfrm_state*,struct xfrm_offload*) ; 
 scalar_t__ unlikely (int) ; 
 struct xfrm_state* xfrm_input_state (struct sk_buff*) ; 
 struct xfrm_offload* xfrm_offload (struct sk_buff*) ; 

__attribute__((used)) static inline __be16 mlx5e_ipsec_mss_inv(struct sk_buff *skb)
{
	return mlx5e_ipsec_inverse_table[skb_shinfo(skb)->gso_size];
}

__attribute__((used)) static struct mlx5e_ipsec_metadata *mlx5e_ipsec_add_metadata(struct sk_buff *skb)
{
	struct mlx5e_ipsec_metadata *mdata;
	struct ethhdr *eth;

	if (unlikely(skb_cow_head(skb, sizeof(*mdata))))
		return ERR_PTR(-ENOMEM);

	eth = (struct ethhdr *)skb_push(skb, sizeof(*mdata));
	skb->mac_header -= sizeof(*mdata);
	mdata = (struct mlx5e_ipsec_metadata *)(eth + 1);

	memmove(skb->data, skb->data + sizeof(*mdata),
		2 * ETH_ALEN);

	eth->h_proto = cpu_to_be16(MLX5E_METADATA_ETHER_TYPE);

	memset(mdata->content.raw, 0, sizeof(mdata->content.raw));
	return mdata;
}

__attribute__((used)) static int mlx5e_ipsec_remove_trailer(struct sk_buff *skb, struct xfrm_state *x)
{
	unsigned int alen = crypto_aead_authsize(x->data);
	struct ipv6hdr *ipv6hdr = ipv6_hdr(skb);
	struct iphdr *ipv4hdr = ip_hdr(skb);
	unsigned int trailer_len;
	u8 plen;
	int ret;

	ret = skb_copy_bits(skb, skb->len - alen - 2, &plen, 1);
	if (unlikely(ret))
		return ret;

	trailer_len = alen + plen + 2;

	pskb_trim(skb, skb->len - trailer_len);
	if (skb->protocol == htons(ETH_P_IP)) {
		ipv4hdr->tot_len = htons(ntohs(ipv4hdr->tot_len) - trailer_len);
		ip_send_check(ipv4hdr);
	} else {
		ipv6hdr->payload_len = htons(ntohs(ipv6hdr->payload_len) -
					     trailer_len);
	}
	return 0;
}

__attribute__((used)) static void mlx5e_ipsec_set_swp(struct sk_buff *skb,
				struct mlx5_wqe_eth_seg *eseg, u8 mode,
				struct xfrm_offload *xo)
{
	u8 proto;

	/* Tunnel Mode:
	 * SWP:      OutL3       InL3  InL4
	 * Pkt: MAC  IP     ESP  IP    L4
	 *
	 * Transport Mode:
	 * SWP:      OutL3       InL4
	 *           InL3
	 * Pkt: MAC  IP     ESP  L4
	 *
	 * Offsets are in 2-byte words, counting from start of frame
	 */
	eseg->swp_outer_l3_offset = skb_network_offset(skb) / 2;
	if (skb->protocol == htons(ETH_P_IPV6))
		eseg->swp_flags |= MLX5_ETH_WQE_SWP_OUTER_L3_IPV6;

	if (mode == XFRM_MODE_TUNNEL) {
		eseg->swp_inner_l3_offset = skb_inner_network_offset(skb) / 2;
		if (xo->proto == IPPROTO_IPV6) {
			eseg->swp_flags |= MLX5_ETH_WQE_SWP_INNER_L3_IPV6;
			proto = inner_ipv6_hdr(skb)->nexthdr;
		} else {
			proto = inner_ip_hdr(skb)->protocol;
		}
	} else {
		eseg->swp_inner_l3_offset = skb_network_offset(skb) / 2;
		if (skb->protocol == htons(ETH_P_IPV6))
			eseg->swp_flags |= MLX5_ETH_WQE_SWP_INNER_L3_IPV6;
		proto = xo->proto;
	}
	switch (proto) {
	case IPPROTO_UDP:
		eseg->swp_flags |= MLX5_ETH_WQE_SWP_INNER_L4_UDP;
		/* Fall through */
	case IPPROTO_TCP:
		eseg->swp_inner_l4_offset = skb_inner_transport_offset(skb) / 2;
		break;
	}
}

void mlx5e_ipsec_set_iv_esn(struct sk_buff *skb, struct xfrm_state *x,
			    struct xfrm_offload *xo)
{
	struct xfrm_replay_state_esn *replay_esn = x->replay_esn;
	__u32 oseq = replay_esn->oseq;
	int iv_offset;
	__be64 seqno;
	u32 seq_hi;

	if (unlikely(skb_is_gso(skb) && oseq < MLX5E_IPSEC_ESN_SCOPE_MID &&
		     MLX5E_IPSEC_ESN_SCOPE_MID < (oseq - skb_shinfo(skb)->gso_segs))) {
		seq_hi = xo->seq.hi - 1;
	} else {
		seq_hi = xo->seq.hi;
	}

	/* Place the SN in the IV field */
	seqno = cpu_to_be64(xo->seq.low + ((u64)seq_hi << 32));
	iv_offset = skb_transport_offset(skb) + sizeof(struct ip_esp_hdr);
	skb_store_bits(skb, iv_offset, &seqno, 8);
}

void mlx5e_ipsec_set_iv(struct sk_buff *skb, struct xfrm_state *x,
			struct xfrm_offload *xo)
{
	int iv_offset;
	__be64 seqno;

	/* Place the SN in the IV field */
	seqno = cpu_to_be64(xo->seq.low + ((u64)xo->seq.hi << 32));
	iv_offset = skb_transport_offset(skb) + sizeof(struct ip_esp_hdr);
	skb_store_bits(skb, iv_offset, &seqno, 8);
}

__attribute__((used)) static void mlx5e_ipsec_set_metadata(struct sk_buff *skb,
				     struct mlx5e_ipsec_metadata *mdata,
				     struct xfrm_offload *xo)
{
	struct ip_esp_hdr *esph;
	struct tcphdr *tcph;

	if (skb_is_gso(skb)) {
		/* Add LSO metadata indication */
		esph = ip_esp_hdr(skb);
		tcph = inner_tcp_hdr(skb);
		netdev_dbg(skb->dev, "   Offloading GSO packet outer L3 %u; L4 %u; Inner L3 %u; L4 %u\n",
			   skb->network_header,
			   skb->transport_header,
			   skb->inner_network_header,
			   skb->inner_transport_header);
		netdev_dbg(skb->dev, "   Offloading GSO packet of len %u; mss %u; TCP sp %u dp %u seq 0x%x ESP seq 0x%x\n",
			   skb->len, skb_shinfo(skb)->gso_size,
			   ntohs(tcph->source), ntohs(tcph->dest),
			   ntohl(tcph->seq), ntohl(esph->seq_no));
		mdata->syndrome = MLX5E_IPSEC_TX_SYNDROME_OFFLOAD_WITH_LSO_TCP;
		mdata->content.tx.mss_inv = mlx5e_ipsec_mss_inv(skb);
		mdata->content.tx.seq = htons(ntohl(tcph->seq) & 0xFFFF);
	} else {
		mdata->syndrome = MLX5E_IPSEC_TX_SYNDROME_OFFLOAD;
	}
	mdata->content.tx.esp_next_proto = xo->proto;

	netdev_dbg(skb->dev, "   TX metadata syndrome %u proto %u mss_inv %04x seq %04x\n",
		   mdata->syndrome, mdata->content.tx.esp_next_proto,
		   ntohs(mdata->content.tx.mss_inv),
		   ntohs(mdata->content.tx.seq));
}

struct sk_buff *mlx5e_ipsec_handle_tx_skb(struct net_device *netdev,
					  struct mlx5e_tx_wqe *wqe,
					  struct sk_buff *skb)
{
	struct mlx5e_priv *priv = netdev_priv(netdev);
	struct xfrm_offload *xo = xfrm_offload(skb);
	struct mlx5e_ipsec_metadata *mdata;
	struct mlx5e_ipsec_sa_entry *sa_entry;
	struct xfrm_state *x;

	if (!xo)
		return skb;

	if (unlikely(skb->sp->len != 1)) {
		atomic64_inc(&priv->ipsec->sw_stats.ipsec_tx_drop_bundle);
		goto drop;
	}

	x = xfrm_input_state(skb);
	if (unlikely(!x)) {
		atomic64_inc(&priv->ipsec->sw_stats.ipsec_tx_drop_no_state);
		goto drop;
	}

	if (unlikely(!x->xso.offload_handle ||
		     (skb->protocol != htons(ETH_P_IP) &&
		      skb->protocol != htons(ETH_P_IPV6)))) {
		atomic64_inc(&priv->ipsec->sw_stats.ipsec_tx_drop_not_ip);
		goto drop;
	}

	if (!skb_is_gso(skb))
		if (unlikely(mlx5e_ipsec_remove_trailer(skb, x))) {
			atomic64_inc(&priv->ipsec->sw_stats.ipsec_tx_drop_trailer);
			goto drop;
		}
	mdata = mlx5e_ipsec_add_metadata(skb);
	if (IS_ERR(mdata)) {
		atomic64_inc(&priv->ipsec->sw_stats.ipsec_tx_drop_metadata);
		goto drop;
	}
	mlx5e_ipsec_set_swp(skb, &wqe->eth, x->props.mode, xo);
	sa_entry = (struct mlx5e_ipsec_sa_entry *)x->xso.offload_handle;
	sa_entry->set_iv_op(skb, x, xo);
	mlx5e_ipsec_set_metadata(skb, mdata, xo);

	return skb;

drop:
	kfree_skb(skb);
	return NULL;
}

__attribute__((used)) static inline struct xfrm_state *
mlx5e_ipsec_build_sp(struct net_device *netdev, struct sk_buff *skb,
		     struct mlx5e_ipsec_metadata *mdata)
{
	struct mlx5e_priv *priv = netdev_priv(netdev);
	struct xfrm_offload *xo;
	struct xfrm_state *xs;
	u32 sa_handle;

	skb->sp = secpath_dup(skb->sp);
	if (unlikely(!skb->sp)) {
		atomic64_inc(&priv->ipsec->sw_stats.ipsec_rx_drop_sp_alloc);
		return NULL;
	}

	sa_handle = be32_to_cpu(mdata->content.rx.sa_handle);
	xs = mlx5e_ipsec_sadb_rx_lookup(priv->ipsec, sa_handle);
	if (unlikely(!xs)) {
		atomic64_inc(&priv->ipsec->sw_stats.ipsec_rx_drop_sadb_miss);
		return NULL;
	}

	skb->sp->xvec[skb->sp->len++] = xs;
	skb->sp->olen++;

	xo = xfrm_offload(skb);
	xo->flags = CRYPTO_DONE;
	switch (mdata->syndrome) {
	case MLX5E_IPSEC_RX_SYNDROME_DECRYPTED:
		xo->status = CRYPTO_SUCCESS;
		if (likely(priv->ipsec->no_trailer)) {
			xo->flags |= XFRM_ESP_NO_TRAILER;
			xo->proto = mdata->content.rx.nexthdr;
		}
		break;
	case MLX5E_IPSEC_RX_SYNDROME_AUTH_FAILED:
		xo->status = CRYPTO_TUNNEL_ESP_AUTH_FAILED;
		break;
	case MLX5E_IPSEC_RX_SYNDROME_BAD_PROTO:
		xo->status = CRYPTO_INVALID_PROTOCOL;
		break;
	default:
		atomic64_inc(&priv->ipsec->sw_stats.ipsec_rx_drop_syndrome);
		return NULL;
	}
	return xs;
}

struct sk_buff *mlx5e_ipsec_handle_rx_skb(struct net_device *netdev,
					  struct sk_buff *skb, u32 *cqe_bcnt)
{
	struct mlx5e_ipsec_metadata *mdata;
	struct xfrm_state *xs;

	if (!is_metadata_hdr_valid(skb))
		return skb;

	/* Use the metadata */
	mdata = (struct mlx5e_ipsec_metadata *)(skb->data + ETH_HLEN);
	xs = mlx5e_ipsec_build_sp(netdev, skb, mdata);
	if (unlikely(!xs)) {
		kfree_skb(skb);
		return NULL;
	}

	remove_metadata_hdr(skb);
	*cqe_bcnt -= MLX5E_METADATA_ETHER_LEN;

	return skb;
}

bool mlx5e_ipsec_feature_check(struct sk_buff *skb, struct net_device *netdev,
			       netdev_features_t features)
{
	struct xfrm_state *x;

	if (skb->sp && skb->sp->len) {
		x = skb->sp->xvec[0];
		if (x && x->xso.offload_handle)
			return true;
	}
	return false;
}

void mlx5e_ipsec_build_inverse_table(void)
{
	u16 mss_inv;
	u32 mss;

	/* Calculate 1/x inverse table for use in GSO data path.
	 * Using this table, we provide the IPSec accelerator with the value of
	 * 1/gso_size so that it can infer the position of each segment inside
	 * the GSO, and increment the ESP sequence number, and generate the IV.
	 * The HW needs this value in Q0.16 fixed-point number format
	 */
	mlx5e_ipsec_inverse_table[1] = htons(0xFFFF);
	for (mss = 2; mss < MAX_LSO_MSS; mss++) {
		mss_inv = div_u64(1ULL << 32, mss) >> 16;
		mlx5e_ipsec_inverse_table[mss] = htons(mss_inv);
	}
}

