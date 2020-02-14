#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sk_buff {void const* data; unsigned int len; } ;
struct nfp_repr {TYPE_3__* dst; } ;
struct nfp_port {scalar_t__ type; int /*<<< orphan*/  dl_port; int /*<<< orphan*/  eth_id; int /*<<< orphan*/  netdev; } ;
struct nfp_pf {int /*<<< orphan*/  lock; struct nfp_app* app; int /*<<< orphan*/  cpp; } ;
struct nfp_nsp {int dummy; } ;
struct nfp_net {int dummy; } ;
struct nfp_eth_table_port {unsigned int fec_modes_supported; unsigned int port_lanes; int lanes; unsigned int index; int /*<<< orphan*/  label_subport; scalar_t__ is_split; int /*<<< orphan*/  label_port; } ;
struct nfp_app {int /*<<< orphan*/  pf; TYPE_4__* type; struct nfp_net* ctrl; } ;
struct netlink_ext_ack {int dummy; } ;
struct netdev_bpf {int dummy; } ;
struct net_device {int /*<<< orphan*/ * netdev_ops; } ;
struct devlink_sb_pool_info {int dummy; } ;
struct devlink {int dummy; } ;
struct bpf_prog {int dummy; } ;
typedef  enum tc_setup_type { ____Placeholder_tc_setup_type } tc_setup_type ;
typedef  enum devlink_sb_threshold_type { ____Placeholder_devlink_sb_threshold_type } devlink_sb_threshold_type ;
struct TYPE_8__ {int (* init ) (struct nfp_app*) ;int (* vnic_alloc ) (struct nfp_app*,struct nfp_net*,unsigned int) ;int (* vnic_init ) (struct nfp_app*,struct nfp_net*) ;int (* repr_open ) (struct nfp_app*,struct nfp_repr*) ;int (* repr_stop ) (struct nfp_app*,struct nfp_repr*) ;int (* repr_init ) (struct nfp_app*,struct net_device*) ;int (* check_mtu ) (struct nfp_app*,struct net_device*,int) ;int (* repr_change_mtu ) (struct nfp_app*,struct net_device*,int) ;int (* start ) (struct nfp_app*) ;char const* name; int ctrl_has_meta; char const* (* extra_cap ) (struct nfp_app*,struct nfp_net*) ;int (* setup_tc ) (struct nfp_app*,struct net_device*,int,void*) ;int (* bpf ) (struct nfp_app*,struct nfp_net*,struct netdev_bpf*) ;int (* xdp_offload ) (struct nfp_app*,struct nfp_net*,struct bpf_prog*,struct netlink_ext_ack*) ;int (* eswitch_mode_set ) (struct nfp_app*,int /*<<< orphan*/ ) ;int (* sriov_enable ) (struct nfp_app*,int) ;struct net_device* (* repr_get ) (struct nfp_app*,int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* sriov_disable ) (struct nfp_app*) ;int /*<<< orphan*/  (* eswitch_mode_get ) (struct nfp_app*) ;int /*<<< orphan*/  (* ctrl_msg_rx_raw ) (struct nfp_app*,void const*,unsigned int) ;int /*<<< orphan*/  (* ctrl_msg_rx ) (struct nfp_app*,struct sk_buff*) ;int /*<<< orphan*/  (* stop ) (struct nfp_app*) ;int /*<<< orphan*/  (* repr_clean ) (struct nfp_app*,struct net_device*) ;int /*<<< orphan*/  (* repr_preclean ) (struct nfp_app*,struct net_device*) ;int /*<<< orphan*/  (* vnic_clean ) (struct nfp_app*,struct nfp_net*) ;int /*<<< orphan*/  (* vnic_free ) (struct nfp_app*,struct nfp_net*) ;int /*<<< orphan*/  (* clean ) (struct nfp_app*) ;} ;
struct TYPE_5__ {int port_id; } ;
struct TYPE_6__ {TYPE_1__ port_info; } ;
struct TYPE_7__ {TYPE_2__ u; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEVLINK_PORT_FLAVOUR_PHYSICAL ; 
 int EINVAL ; 
 int EOPNOTSUPP ; 
 scalar_t__ IS_ERR (struct nfp_nsp*) ; 
 scalar_t__ NFP_PORT_PF_PORT ; 
 int /*<<< orphan*/  NFP_PORT_PHYS_PORT ; 
 scalar_t__ NFP_PORT_VF_PORT ; 
 int PTR_ERR (struct nfp_nsp*) ; 
 int __nfp_ctrl_tx (struct nfp_net*,struct sk_buff*) ; 
 int __nfp_eth_set_split (struct nfp_nsp*,unsigned int) ; 
 struct nfp_eth_table_port* __nfp_port_get_eth_port (struct nfp_port*) ; 
 int /*<<< orphan*/  devlink_port_attrs_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int devlink_port_register (struct devlink*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devlink_port_type_eth_set (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devlink_port_unregister (int /*<<< orphan*/ *) ; 
 struct nfp_pf* devlink_priv (struct devlink*) ; 
 int /*<<< orphan*/  memcpy (struct nfp_eth_table_port*,struct nfp_eth_table_port*,int) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct nfp_repr* netdev_priv (struct net_device*) ; 
 int nfp_ctrl_tx (struct nfp_net*,struct sk_buff*) ; 
 int /*<<< orphan*/  nfp_eth_config_cleanup_end (struct nfp_nsp*) ; 
 int nfp_eth_config_commit_end (struct nfp_nsp*) ; 
 struct nfp_nsp* nfp_eth_config_start (int /*<<< orphan*/ ,unsigned int) ; 
 int nfp_net_refresh_port_table_sync (struct nfp_pf*) ; 
 int nfp_nsp_get_abi_ver_minor (struct nfp_nsp*) ; 
 struct nfp_port* nfp_port_from_id (struct nfp_pf*,int /*<<< orphan*/ ,unsigned int) ; 
 struct net_device* nfp_repr_alloc_mqs (struct nfp_app*,int,int) ; 
 int /*<<< orphan*/  nfp_repr_netdev_ops ; 
 int nfp_shared_buf_pool_get (struct nfp_pf*,unsigned int,int /*<<< orphan*/ ,struct devlink_sb_pool_info*) ; 
 int nfp_shared_buf_pool_set (struct nfp_pf*,unsigned int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 struct devlink* priv_to_devlink (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rtnl_lock () ; 
 int /*<<< orphan*/  rtnl_unlock () ; 
 int stub1 (struct nfp_app*) ; 
 int /*<<< orphan*/  stub10 (struct nfp_app*,struct net_device*) ; 
 int /*<<< orphan*/  stub11 (struct nfp_app*,struct net_device*) ; 
 int stub12 (struct nfp_app*,struct net_device*,int) ; 
 int stub13 (struct nfp_app*,struct net_device*,int) ; 
 int stub14 (struct nfp_app*) ; 
 int /*<<< orphan*/  stub15 (struct nfp_app*) ; 
 char const* stub16 (struct nfp_app*,struct nfp_net*) ; 
 int stub17 (struct nfp_app*,struct net_device*,int,void*) ; 
 int stub18 (struct nfp_app*,struct nfp_net*,struct netdev_bpf*) ; 
 int stub19 (struct nfp_app*,struct nfp_net*,struct bpf_prog*,struct netlink_ext_ack*) ; 
 int /*<<< orphan*/  stub2 (struct nfp_app*) ; 
 int /*<<< orphan*/  stub20 (struct nfp_app*,struct sk_buff*) ; 
 int /*<<< orphan*/  stub21 (struct nfp_app*,void const*,unsigned int) ; 
 int /*<<< orphan*/  stub22 (struct nfp_app*) ; 
 int stub23 (struct nfp_app*,int /*<<< orphan*/ ) ; 
 int stub24 (struct nfp_app*,int) ; 
 int /*<<< orphan*/  stub25 (struct nfp_app*) ; 
 struct net_device* stub26 (struct nfp_app*,int /*<<< orphan*/ ) ; 
 int stub3 (struct nfp_app*,struct nfp_net*,unsigned int) ; 
 int /*<<< orphan*/  stub4 (struct nfp_app*,struct nfp_net*) ; 
 int stub5 (struct nfp_app*,struct nfp_net*) ; 
 int /*<<< orphan*/  stub6 (struct nfp_app*,struct nfp_net*) ; 
 int stub7 (struct nfp_app*,struct nfp_repr*) ; 
 int stub8 (struct nfp_app*,struct nfp_repr*) ; 
 int stub9 (struct nfp_app*,struct net_device*) ; 
 int /*<<< orphan*/  trace_devlink_hwmsg (struct devlink*,int,int /*<<< orphan*/ ,void const*,unsigned int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline bool nfp_nsp_has_mac_reinit(struct nfp_nsp *state)
{
	return nfp_nsp_get_abi_ver_minor(state) > 20;
}

__attribute__((used)) static inline bool nfp_eth_can_support_fec(struct nfp_eth_table_port *eth_port)
{
	return !!eth_port->fec_modes_supported;
}

__attribute__((used)) static inline unsigned int
nfp_eth_supported_fec_modes(struct nfp_eth_table_port *eth_port)
{
	return eth_port->fec_modes_supported;
}

__attribute__((used)) static inline bool nfp_netdev_is_nfp_repr(struct net_device *netdev)
{
	return netdev->netdev_ops == &nfp_repr_netdev_ops;
}

__attribute__((used)) static inline int nfp_repr_get_port_id(struct net_device *netdev)
{
	struct nfp_repr *priv = netdev_priv(netdev);

	return priv->dst->u.port_info.port_id;
}

__attribute__((used)) static inline struct net_device *nfp_repr_alloc(struct nfp_app *app)
{
	return nfp_repr_alloc_mqs(app, 1, 1);
}

__attribute__((used)) static inline int nfp_app_init(struct nfp_app *app)
{
	if (!app->type->init)
		return 0;
	return app->type->init(app);
}

__attribute__((used)) static inline void nfp_app_clean(struct nfp_app *app)
{
	if (app->type->clean)
		app->type->clean(app);
}

__attribute__((used)) static inline int nfp_app_vnic_alloc(struct nfp_app *app, struct nfp_net *nn,
				     unsigned int id)
{
	return app->type->vnic_alloc(app, nn, id);
}

__attribute__((used)) static inline void nfp_app_vnic_free(struct nfp_app *app, struct nfp_net *nn)
{
	if (app->type->vnic_free)
		app->type->vnic_free(app, nn);
}

__attribute__((used)) static inline int nfp_app_vnic_init(struct nfp_app *app, struct nfp_net *nn)
{
	if (!app->type->vnic_init)
		return 0;
	return app->type->vnic_init(app, nn);
}

__attribute__((used)) static inline void nfp_app_vnic_clean(struct nfp_app *app, struct nfp_net *nn)
{
	if (app->type->vnic_clean)
		app->type->vnic_clean(app, nn);
}

__attribute__((used)) static inline int nfp_app_repr_open(struct nfp_app *app, struct nfp_repr *repr)
{
	if (!app->type->repr_open)
		return -EINVAL;
	return app->type->repr_open(app, repr);
}

__attribute__((used)) static inline int nfp_app_repr_stop(struct nfp_app *app, struct nfp_repr *repr)
{
	if (!app->type->repr_stop)
		return -EINVAL;
	return app->type->repr_stop(app, repr);
}

__attribute__((used)) static inline int
nfp_app_repr_init(struct nfp_app *app, struct net_device *netdev)
{
	if (!app->type->repr_init)
		return 0;
	return app->type->repr_init(app, netdev);
}

__attribute__((used)) static inline void
nfp_app_repr_preclean(struct nfp_app *app, struct net_device *netdev)
{
	if (app->type->repr_preclean)
		app->type->repr_preclean(app, netdev);
}

__attribute__((used)) static inline void
nfp_app_repr_clean(struct nfp_app *app, struct net_device *netdev)
{
	if (app->type->repr_clean)
		app->type->repr_clean(app, netdev);
}

__attribute__((used)) static inline int
nfp_app_check_mtu(struct nfp_app *app, struct net_device *netdev, int new_mtu)
{
	if (!app || !app->type->check_mtu)
		return 0;
	return app->type->check_mtu(app, netdev, new_mtu);
}

__attribute__((used)) static inline int
nfp_app_repr_change_mtu(struct nfp_app *app, struct net_device *netdev,
			int new_mtu)
{
	if (!app || !app->type->repr_change_mtu)
		return 0;
	return app->type->repr_change_mtu(app, netdev, new_mtu);
}

__attribute__((used)) static inline int nfp_app_start(struct nfp_app *app, struct nfp_net *ctrl)
{
	app->ctrl = ctrl;
	if (!app->type->start)
		return 0;
	return app->type->start(app);
}

__attribute__((used)) static inline void nfp_app_stop(struct nfp_app *app)
{
	if (!app->type->stop)
		return;
	app->type->stop(app);
}

__attribute__((used)) static inline const char *nfp_app_name(struct nfp_app *app)
{
	if (!app)
		return "";
	return app->type->name;
}

__attribute__((used)) static inline bool nfp_app_needs_ctrl_vnic(struct nfp_app *app)
{
	return app && app->type->ctrl_msg_rx;
}

__attribute__((used)) static inline bool nfp_app_ctrl_has_meta(struct nfp_app *app)
{
	return app->type->ctrl_has_meta;
}

__attribute__((used)) static inline bool nfp_app_ctrl_uses_data_vnics(struct nfp_app *app)
{
	return app && app->type->ctrl_msg_rx_raw;
}

__attribute__((used)) static inline const char *nfp_app_extra_cap(struct nfp_app *app,
					    struct nfp_net *nn)
{
	if (!app || !app->type->extra_cap)
		return "";
	return app->type->extra_cap(app, nn);
}

__attribute__((used)) static inline bool nfp_app_has_tc(struct nfp_app *app)
{
	return app && app->type->setup_tc;
}

__attribute__((used)) static inline int nfp_app_setup_tc(struct nfp_app *app,
				   struct net_device *netdev,
				   enum tc_setup_type type, void *type_data)
{
	if (!app || !app->type->setup_tc)
		return -EOPNOTSUPP;
	return app->type->setup_tc(app, netdev, type, type_data);
}

__attribute__((used)) static inline int nfp_app_bpf(struct nfp_app *app, struct nfp_net *nn,
			      struct netdev_bpf *bpf)
{
	if (!app || !app->type->bpf)
		return -EINVAL;
	return app->type->bpf(app, nn, bpf);
}

__attribute__((used)) static inline int nfp_app_xdp_offload(struct nfp_app *app, struct nfp_net *nn,
				      struct bpf_prog *prog,
				      struct netlink_ext_ack *extack)
{
	if (!app || !app->type->xdp_offload)
		return -EOPNOTSUPP;
	return app->type->xdp_offload(app, nn, prog, extack);
}

__attribute__((used)) static inline bool __nfp_app_ctrl_tx(struct nfp_app *app, struct sk_buff *skb)
{
	trace_devlink_hwmsg(priv_to_devlink(app->pf), false, 0,
			    skb->data, skb->len);

	return __nfp_ctrl_tx(app->ctrl, skb);
}

__attribute__((used)) static inline bool nfp_app_ctrl_tx(struct nfp_app *app, struct sk_buff *skb)
{
	trace_devlink_hwmsg(priv_to_devlink(app->pf), false, 0,
			    skb->data, skb->len);

	return nfp_ctrl_tx(app->ctrl, skb);
}

__attribute__((used)) static inline void nfp_app_ctrl_rx(struct nfp_app *app, struct sk_buff *skb)
{
	trace_devlink_hwmsg(priv_to_devlink(app->pf), true, 0,
			    skb->data, skb->len);

	app->type->ctrl_msg_rx(app, skb);
}

__attribute__((used)) static inline void
nfp_app_ctrl_rx_raw(struct nfp_app *app, const void *data, unsigned int len)
{
	if (!app || !app->type->ctrl_msg_rx_raw)
		return;

	trace_devlink_hwmsg(priv_to_devlink(app->pf), true, 0, data, len);
	app->type->ctrl_msg_rx_raw(app, data, len);
}

__attribute__((used)) static inline int nfp_app_eswitch_mode_get(struct nfp_app *app, u16 *mode)
{
	if (!app->type->eswitch_mode_get)
		return -EOPNOTSUPP;

	*mode = app->type->eswitch_mode_get(app);

	return 0;
}

__attribute__((used)) static inline int nfp_app_eswitch_mode_set(struct nfp_app *app, u16 mode)
{
	if (!app->type->eswitch_mode_set)
		return -EOPNOTSUPP;
	return app->type->eswitch_mode_set(app, mode);
}

__attribute__((used)) static inline int nfp_app_sriov_enable(struct nfp_app *app, int num_vfs)
{
	if (!app || !app->type->sriov_enable)
		return -EOPNOTSUPP;
	return app->type->sriov_enable(app, num_vfs);
}

__attribute__((used)) static inline void nfp_app_sriov_disable(struct nfp_app *app)
{
	if (app && app->type->sriov_disable)
		app->type->sriov_disable(app);
}

__attribute__((used)) static inline struct net_device *nfp_app_repr_get(struct nfp_app *app, u32 id)
{
	if (unlikely(!app || !app->type->repr_get))
		return NULL;

	return app->type->repr_get(app, id);
}

__attribute__((used)) static inline bool nfp_port_is_vnic(const struct nfp_port *port)
{
	return port->type == NFP_PORT_PF_PORT || port->type == NFP_PORT_VF_PORT;
}

__attribute__((used)) static int
nfp_devlink_fill_eth_port(struct nfp_port *port,
			  struct nfp_eth_table_port *copy)
{
	struct nfp_eth_table_port *eth_port;

	eth_port = __nfp_port_get_eth_port(port);
	if (!eth_port)
		return -EINVAL;

	memcpy(copy, eth_port, sizeof(*eth_port));

	return 0;
}

__attribute__((used)) static int
nfp_devlink_fill_eth_port_from_id(struct nfp_pf *pf, unsigned int port_index,
				  struct nfp_eth_table_port *copy)
{
	struct nfp_port *port;

	port = nfp_port_from_id(pf, NFP_PORT_PHYS_PORT, port_index);

	return nfp_devlink_fill_eth_port(port, copy);
}

__attribute__((used)) static int
nfp_devlink_set_lanes(struct nfp_pf *pf, unsigned int idx, unsigned int lanes)
{
	struct nfp_nsp *nsp;
	int ret;

	nsp = nfp_eth_config_start(pf->cpp, idx);
	if (IS_ERR(nsp))
		return PTR_ERR(nsp);

	ret = __nfp_eth_set_split(nsp, lanes);
	if (ret) {
		nfp_eth_config_cleanup_end(nsp);
		return ret;
	}

	ret = nfp_eth_config_commit_end(nsp);
	if (ret < 0)
		return ret;
	if (ret) /* no change */
		return 0;

	return nfp_net_refresh_port_table_sync(pf);
}

__attribute__((used)) static int
nfp_devlink_port_split(struct devlink *devlink, unsigned int port_index,
		       unsigned int count, struct netlink_ext_ack *extack)
{
	struct nfp_pf *pf = devlink_priv(devlink);
	struct nfp_eth_table_port eth_port;
	unsigned int lanes;
	int ret;

	if (count < 2)
		return -EINVAL;

	mutex_lock(&pf->lock);

	rtnl_lock();
	ret = nfp_devlink_fill_eth_port_from_id(pf, port_index, &eth_port);
	rtnl_unlock();
	if (ret)
		goto out;

	if (eth_port.is_split || eth_port.port_lanes % count) {
		ret = -EINVAL;
		goto out;
	}

	/* Special case the 100G CXP -> 2x40G split */
	lanes = eth_port.port_lanes / count;
	if (eth_port.lanes == 10 && count == 2)
		lanes = 8 / count;

	ret = nfp_devlink_set_lanes(pf, eth_port.index, lanes);
out:
	mutex_unlock(&pf->lock);

	return ret;
}

__attribute__((used)) static int
nfp_devlink_port_unsplit(struct devlink *devlink, unsigned int port_index,
			 struct netlink_ext_ack *extack)
{
	struct nfp_pf *pf = devlink_priv(devlink);
	struct nfp_eth_table_port eth_port;
	unsigned int lanes;
	int ret;

	mutex_lock(&pf->lock);

	rtnl_lock();
	ret = nfp_devlink_fill_eth_port_from_id(pf, port_index, &eth_port);
	rtnl_unlock();
	if (ret)
		goto out;

	if (!eth_port.is_split) {
		ret = -EINVAL;
		goto out;
	}

	/* Special case the 100G CXP -> 2x40G unsplit */
	lanes = eth_port.port_lanes;
	if (eth_port.port_lanes == 8)
		lanes = 10;

	ret = nfp_devlink_set_lanes(pf, eth_port.index, lanes);
out:
	mutex_unlock(&pf->lock);

	return ret;
}

__attribute__((used)) static int
nfp_devlink_sb_pool_get(struct devlink *devlink, unsigned int sb_index,
			u16 pool_index, struct devlink_sb_pool_info *pool_info)
{
	struct nfp_pf *pf = devlink_priv(devlink);

	return nfp_shared_buf_pool_get(pf, sb_index, pool_index, pool_info);
}

__attribute__((used)) static int
nfp_devlink_sb_pool_set(struct devlink *devlink, unsigned int sb_index,
			u16 pool_index,
			u32 size, enum devlink_sb_threshold_type threshold_type)
{
	struct nfp_pf *pf = devlink_priv(devlink);

	return nfp_shared_buf_pool_set(pf, sb_index, pool_index,
				       size, threshold_type);
}

__attribute__((used)) static int nfp_devlink_eswitch_mode_get(struct devlink *devlink, u16 *mode)
{
	struct nfp_pf *pf = devlink_priv(devlink);

	return nfp_app_eswitch_mode_get(pf->app, mode);
}

__attribute__((used)) static int nfp_devlink_eswitch_mode_set(struct devlink *devlink, u16 mode)
{
	struct nfp_pf *pf = devlink_priv(devlink);
	int ret;

	mutex_lock(&pf->lock);
	ret = nfp_app_eswitch_mode_set(pf->app, mode);
	mutex_unlock(&pf->lock);

	return ret;
}

int nfp_devlink_port_register(struct nfp_app *app, struct nfp_port *port)
{
	struct nfp_eth_table_port eth_port;
	struct devlink *devlink;
	int ret;

	rtnl_lock();
	ret = nfp_devlink_fill_eth_port(port, &eth_port);
	rtnl_unlock();
	if (ret)
		return ret;

	devlink_port_type_eth_set(&port->dl_port, port->netdev);
	devlink_port_attrs_set(&port->dl_port, DEVLINK_PORT_FLAVOUR_PHYSICAL,
			       eth_port.label_port, eth_port.is_split,
			       eth_port.label_subport);

	devlink = priv_to_devlink(app->pf);

	return devlink_port_register(devlink, &port->dl_port, port->eth_id);
}

void nfp_devlink_port_unregister(struct nfp_port *port)
{
	devlink_port_unregister(&port->dl_port);
}

