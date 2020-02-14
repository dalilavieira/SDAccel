#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  union ib_gid {int dummy; } ib_gid ;
typedef  int /*<<< orphan*/  u32 ;
struct TYPE_10__ {scalar_t__ raw; } ;
struct TYPE_9__ {scalar_t__ raw; } ;
struct sa_path_rec {scalar_t__ rec_type; int /*<<< orphan*/  packet_life_time_selector; int /*<<< orphan*/  preference; int /*<<< orphan*/  packet_life_time; int /*<<< orphan*/  rate; int /*<<< orphan*/  rate_selector; int /*<<< orphan*/  mtu; int /*<<< orphan*/  mtu_selector; int /*<<< orphan*/  sl; int /*<<< orphan*/  pkey; int /*<<< orphan*/  numb_path; int /*<<< orphan*/  reversible; int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  hop_limit; int /*<<< orphan*/  flow_label; TYPE_5__ sgid; TYPE_4__ dgid; } ;
struct rdma_ah_attr {scalar_t__ type; int /*<<< orphan*/  port_num; } ;
struct TYPE_7__ {int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  hop_limit; int /*<<< orphan*/  sgid_index; int /*<<< orphan*/  flow_label; scalar_t__ dgid; struct sa_path_rec reserved; } ;
struct ib_uverbs_ah_attr {int is_global; scalar_t__ reserved; int /*<<< orphan*/  port_num; TYPE_2__ grh; int /*<<< orphan*/  static_rate; int /*<<< orphan*/  src_path_bits; int /*<<< orphan*/  sl; int /*<<< orphan*/  dlid; } ;
struct ib_uverbs_qp_attr {struct sa_path_rec* reserved; int /*<<< orphan*/  alt_timeout; int /*<<< orphan*/  alt_port_num; int /*<<< orphan*/  rnr_retry; int /*<<< orphan*/  retry_cnt; int /*<<< orphan*/  timeout; int /*<<< orphan*/  port_num; int /*<<< orphan*/  min_rnr_timer; int /*<<< orphan*/  max_dest_rd_atomic; int /*<<< orphan*/  max_rd_atomic; int /*<<< orphan*/  sq_draining; int /*<<< orphan*/  en_sqd_async_notify; int /*<<< orphan*/  alt_pkey_index; int /*<<< orphan*/  pkey_index; struct ib_uverbs_ah_attr alt_ah_attr; struct ib_uverbs_ah_attr ah_attr; int /*<<< orphan*/  max_inline_data; int /*<<< orphan*/  max_recv_sge; int /*<<< orphan*/  max_send_sge; int /*<<< orphan*/  max_recv_wr; int /*<<< orphan*/  max_send_wr; int /*<<< orphan*/  qp_access_flags; int /*<<< orphan*/  dest_qp_num; int /*<<< orphan*/  sq_psn; int /*<<< orphan*/  rq_psn; int /*<<< orphan*/  qkey; int /*<<< orphan*/  path_mig_state; int /*<<< orphan*/  path_mtu; int /*<<< orphan*/  cur_qp_state; int /*<<< orphan*/  qp_state; } ;
struct ib_user_path_rec {int /*<<< orphan*/  packet_life_time_selector; int /*<<< orphan*/  preference; int /*<<< orphan*/  packet_life_time; int /*<<< orphan*/  rate; int /*<<< orphan*/  rate_selector; int /*<<< orphan*/  mtu; int /*<<< orphan*/  mtu_selector; int /*<<< orphan*/  sl; int /*<<< orphan*/  pkey; int /*<<< orphan*/  numb_path; int /*<<< orphan*/  reversible; int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  hop_limit; int /*<<< orphan*/  flow_label; int /*<<< orphan*/  raw_traffic; scalar_t__ sgid; scalar_t__ dgid; void* dlid; void* slid; } ;
struct TYPE_8__ {int /*<<< orphan*/  max_inline_data; int /*<<< orphan*/  max_recv_sge; int /*<<< orphan*/  max_send_sge; int /*<<< orphan*/  max_recv_wr; int /*<<< orphan*/  max_send_wr; } ;
struct ib_qp_attr {int /*<<< orphan*/  alt_timeout; int /*<<< orphan*/  alt_port_num; int /*<<< orphan*/  rnr_retry; int /*<<< orphan*/  retry_cnt; int /*<<< orphan*/  timeout; int /*<<< orphan*/  port_num; int /*<<< orphan*/  min_rnr_timer; int /*<<< orphan*/  max_dest_rd_atomic; int /*<<< orphan*/  max_rd_atomic; int /*<<< orphan*/  sq_draining; int /*<<< orphan*/  en_sqd_async_notify; int /*<<< orphan*/  alt_pkey_index; int /*<<< orphan*/  pkey_index; struct rdma_ah_attr alt_ah_attr; struct rdma_ah_attr ah_attr; TYPE_3__ cap; int /*<<< orphan*/  qp_access_flags; int /*<<< orphan*/  dest_qp_num; int /*<<< orphan*/  sq_psn; int /*<<< orphan*/  rq_psn; int /*<<< orphan*/  qkey; int /*<<< orphan*/  path_mig_state; int /*<<< orphan*/  path_mtu; int /*<<< orphan*/  cur_qp_state; int /*<<< orphan*/  qp_state; } ;
struct ib_port_attr {int /*<<< orphan*/  subnet_prefix; } ;
struct TYPE_6__ {scalar_t__ raw; } ;
struct ib_global_route {int /*<<< orphan*/  traffic_class; int /*<<< orphan*/  hop_limit; int /*<<< orphan*/  sgid_index; int /*<<< orphan*/  flow_label; TYPE_1__ dgid; } ;
struct ib_device {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int IB_AH_GRH ; 
 int /*<<< orphan*/  IB_LID_PERMISSIVE ; 
 int /*<<< orphan*/  OPA_DEFAULT_GID_PREFIX ; 
 int /*<<< orphan*/  OPA_MAKE_ID (int /*<<< orphan*/ ) ; 
 scalar_t__ RDMA_AH_ATTR_TYPE_IB ; 
 scalar_t__ RDMA_AH_ATTR_TYPE_OPA ; 
 scalar_t__ SA_PATH_REC_TYPE_IB ; 
 scalar_t__ SA_PATH_REC_TYPE_OPA ; 
 int /*<<< orphan*/  be16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_be64 (int /*<<< orphan*/ ) ; 
 void* htons (int /*<<< orphan*/ ) ; 
 scalar_t__ ib_is_opa_gid (union ib_gid*) ; 
 scalar_t__ ib_query_port (struct ib_device*,int /*<<< orphan*/ ,struct ib_port_attr*) ; 
 int /*<<< orphan*/  memcpy (scalar_t__,scalar_t__,int) ; 
 int /*<<< orphan*/  memset (struct sa_path_rec*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ntohl (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ntohs (void*) ; 
 int /*<<< orphan*/  opa_get_lid_from_gid (union ib_gid*) ; 
 int rdma_ah_get_ah_flags (struct rdma_ah_attr*) ; 
 int /*<<< orphan*/  rdma_ah_get_dlid (struct rdma_ah_attr*) ; 
 int /*<<< orphan*/  rdma_ah_get_path_bits (struct rdma_ah_attr*) ; 
 int /*<<< orphan*/  rdma_ah_get_port_num (struct rdma_ah_attr*) ; 
 int /*<<< orphan*/  rdma_ah_get_sl (struct rdma_ah_attr*) ; 
 int /*<<< orphan*/  rdma_ah_get_static_rate (struct rdma_ah_attr*) ; 
 struct ib_global_route* rdma_ah_read_grh (struct rdma_ah_attr*) ; 
 int /*<<< orphan*/  rdma_ah_set_grh (struct rdma_ah_attr*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rdma_ah_set_interface_id (struct rdma_ah_attr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rdma_ah_set_subnet_prefix (struct rdma_ah_attr*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sa_convert_path_opa_to_ib (struct sa_path_rec*,struct sa_path_rec*) ; 
 int /*<<< orphan*/  sa_path_get_dlid (struct sa_path_rec*) ; 
 int /*<<< orphan*/  sa_path_get_raw_traffic (struct sa_path_rec*) ; 
 int /*<<< orphan*/  sa_path_get_slid (struct sa_path_rec*) ; 
 int /*<<< orphan*/  sa_path_set_dlid (struct sa_path_rec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sa_path_set_dmac_zero (struct sa_path_rec*) ; 
 int /*<<< orphan*/  sa_path_set_raw_traffic (struct sa_path_rec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sa_path_set_slid (struct sa_path_rec*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rdma_ah_conv_opa_to_ib(struct ib_device *dev,
				  struct rdma_ah_attr *ib,
				  struct rdma_ah_attr *opa)
{
	struct ib_port_attr port_attr;
	int ret = 0;

	/* Do structure copy and the over-write fields */
	*ib = *opa;

	ib->type = RDMA_AH_ATTR_TYPE_IB;
	rdma_ah_set_grh(ib, NULL, 0, 0, 1, 0);

	if (ib_query_port(dev, opa->port_num, &port_attr)) {
		/* Set to default subnet to indicate error */
		rdma_ah_set_subnet_prefix(ib, OPA_DEFAULT_GID_PREFIX);
		ret = -EINVAL;
	} else {
		rdma_ah_set_subnet_prefix(ib,
					  cpu_to_be64(port_attr.subnet_prefix));
	}
	rdma_ah_set_interface_id(ib, OPA_MAKE_ID(rdma_ah_get_dlid(opa)));
	return ret;
}

void ib_copy_ah_attr_to_user(struct ib_device *device,
			     struct ib_uverbs_ah_attr *dst,
			     struct rdma_ah_attr *ah_attr)
{
	struct rdma_ah_attr *src = ah_attr;
	struct rdma_ah_attr conv_ah;

	memset(&dst->grh.reserved, 0, sizeof(dst->grh.reserved));

	if ((ah_attr->type == RDMA_AH_ATTR_TYPE_OPA) &&
	    (rdma_ah_get_dlid(ah_attr) > be16_to_cpu(IB_LID_PERMISSIVE)) &&
	    (!rdma_ah_conv_opa_to_ib(device, &conv_ah, ah_attr)))
		src = &conv_ah;

	dst->dlid		   = rdma_ah_get_dlid(src);
	dst->sl			   = rdma_ah_get_sl(src);
	dst->src_path_bits	   = rdma_ah_get_path_bits(src);
	dst->static_rate	   = rdma_ah_get_static_rate(src);
	dst->is_global             = rdma_ah_get_ah_flags(src) &
					IB_AH_GRH ? 1 : 0;
	if (dst->is_global) {
		const struct ib_global_route *grh = rdma_ah_read_grh(src);

		memcpy(dst->grh.dgid, grh->dgid.raw, sizeof(grh->dgid));
		dst->grh.flow_label        = grh->flow_label;
		dst->grh.sgid_index        = grh->sgid_index;
		dst->grh.hop_limit         = grh->hop_limit;
		dst->grh.traffic_class     = grh->traffic_class;
	}
	dst->port_num		   = rdma_ah_get_port_num(src);
	dst->reserved 		   = 0;
}

void ib_copy_qp_attr_to_user(struct ib_device *device,
			     struct ib_uverbs_qp_attr *dst,
			     struct ib_qp_attr *src)
{
	dst->qp_state	        = src->qp_state;
	dst->cur_qp_state	= src->cur_qp_state;
	dst->path_mtu		= src->path_mtu;
	dst->path_mig_state	= src->path_mig_state;
	dst->qkey		= src->qkey;
	dst->rq_psn		= src->rq_psn;
	dst->sq_psn		= src->sq_psn;
	dst->dest_qp_num	= src->dest_qp_num;
	dst->qp_access_flags	= src->qp_access_flags;

	dst->max_send_wr	= src->cap.max_send_wr;
	dst->max_recv_wr	= src->cap.max_recv_wr;
	dst->max_send_sge	= src->cap.max_send_sge;
	dst->max_recv_sge	= src->cap.max_recv_sge;
	dst->max_inline_data	= src->cap.max_inline_data;

	ib_copy_ah_attr_to_user(device, &dst->ah_attr, &src->ah_attr);
	ib_copy_ah_attr_to_user(device, &dst->alt_ah_attr, &src->alt_ah_attr);

	dst->pkey_index		= src->pkey_index;
	dst->alt_pkey_index	= src->alt_pkey_index;
	dst->en_sqd_async_notify = src->en_sqd_async_notify;
	dst->sq_draining	= src->sq_draining;
	dst->max_rd_atomic	= src->max_rd_atomic;
	dst->max_dest_rd_atomic	= src->max_dest_rd_atomic;
	dst->min_rnr_timer	= src->min_rnr_timer;
	dst->port_num		= src->port_num;
	dst->timeout		= src->timeout;
	dst->retry_cnt		= src->retry_cnt;
	dst->rnr_retry		= src->rnr_retry;
	dst->alt_port_num	= src->alt_port_num;
	dst->alt_timeout	= src->alt_timeout;
	memset(dst->reserved, 0, sizeof(dst->reserved));
}

__attribute__((used)) static void __ib_copy_path_rec_to_user(struct ib_user_path_rec *dst,
				       struct sa_path_rec *src)
{
	memcpy(dst->dgid, src->dgid.raw, sizeof(src->dgid));
	memcpy(dst->sgid, src->sgid.raw, sizeof(src->sgid));

	dst->dlid		= htons(ntohl(sa_path_get_dlid(src)));
	dst->slid		= htons(ntohl(sa_path_get_slid(src)));
	dst->raw_traffic	= sa_path_get_raw_traffic(src);
	dst->flow_label		= src->flow_label;
	dst->hop_limit		= src->hop_limit;
	dst->traffic_class	= src->traffic_class;
	dst->reversible		= src->reversible;
	dst->numb_path		= src->numb_path;
	dst->pkey		= src->pkey;
	dst->sl			= src->sl;
	dst->mtu_selector	= src->mtu_selector;
	dst->mtu		= src->mtu;
	dst->rate_selector	= src->rate_selector;
	dst->rate		= src->rate;
	dst->packet_life_time	= src->packet_life_time;
	dst->preference		= src->preference;
	dst->packet_life_time_selector = src->packet_life_time_selector;
}

void ib_copy_path_rec_to_user(struct ib_user_path_rec *dst,
			      struct sa_path_rec *src)
{
	struct sa_path_rec rec;

	if (src->rec_type == SA_PATH_REC_TYPE_OPA) {
		sa_convert_path_opa_to_ib(&rec, src);
		__ib_copy_path_rec_to_user(dst, &rec);
		return;
	}
	__ib_copy_path_rec_to_user(dst, src);
}

void ib_copy_path_rec_from_user(struct sa_path_rec *dst,
				struct ib_user_path_rec *src)
{
	u32 slid, dlid;

	memset(dst, 0, sizeof(*dst));
	if ((ib_is_opa_gid((union ib_gid *)src->sgid)) ||
	    (ib_is_opa_gid((union ib_gid *)src->dgid))) {
		dst->rec_type = SA_PATH_REC_TYPE_OPA;
		slid = opa_get_lid_from_gid((union ib_gid *)src->sgid);
		dlid = opa_get_lid_from_gid((union ib_gid *)src->dgid);
	} else {
		dst->rec_type = SA_PATH_REC_TYPE_IB;
		slid = ntohs(src->slid);
		dlid = ntohs(src->dlid);
	}
	memcpy(dst->dgid.raw, src->dgid, sizeof dst->dgid);
	memcpy(dst->sgid.raw, src->sgid, sizeof dst->sgid);

	sa_path_set_dlid(dst, dlid);
	sa_path_set_slid(dst, slid);
	sa_path_set_raw_traffic(dst, src->raw_traffic);
	dst->flow_label		= src->flow_label;
	dst->hop_limit		= src->hop_limit;
	dst->traffic_class	= src->traffic_class;
	dst->reversible		= src->reversible;
	dst->numb_path		= src->numb_path;
	dst->pkey		= src->pkey;
	dst->sl			= src->sl;
	dst->mtu_selector	= src->mtu_selector;
	dst->mtu		= src->mtu;
	dst->rate_selector	= src->rate_selector;
	dst->rate		= src->rate;
	dst->packet_life_time	= src->packet_life_time;
	dst->preference		= src->preference;
	dst->packet_life_time_selector = src->packet_life_time_selector;

	/* TODO: No need to set this */
	sa_path_set_dmac_zero(dst);
}

