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
typedef  int u8 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct sk_buff {void const* data; unsigned int len; } ;
struct nfp_repr {TYPE_4__* dst; } ;
struct nfp_pf {scalar_t__ max_data_vnics; TYPE_1__* eth_tbl; int /*<<< orphan*/  cpp; } ;
struct nfp_nsp {int dummy; } ;
struct nfp_net {int dummy; } ;
struct nfp_eth_table_port {unsigned int fec_modes_supported; } ;
struct nfp_cpp {int dummy; } ;
struct nfp_app {struct nfp_pf* pf; TYPE_5__* type; struct nfp_net* ctrl; } ;
struct netlink_ext_ack {int dummy; } ;
struct netdev_bpf {int dummy; } ;
struct net_device {int /*<<< orphan*/ * netdev_ops; } ;
struct bpf_prog {int dummy; } ;
typedef  enum tc_setup_type { ____Placeholder_tc_setup_type } tc_setup_type ;
struct TYPE_10__ {int (* init ) (struct nfp_app*) ;int (* vnic_alloc ) (struct nfp_app*,struct nfp_net*,unsigned int) ;int (* vnic_init ) (struct nfp_app*,struct nfp_net*) ;int (* repr_open ) (struct nfp_app*,struct nfp_repr*) ;int (* repr_stop ) (struct nfp_app*,struct nfp_repr*) ;int (* repr_init ) (struct nfp_app*,struct net_device*) ;int (* check_mtu ) (struct nfp_app*,struct net_device*,int) ;int (* repr_change_mtu ) (struct nfp_app*,struct net_device*,int) ;int (* start ) (struct nfp_app*) ;char const* name; int ctrl_has_meta; char const* (* extra_cap ) (struct nfp_app*,struct nfp_net*) ;int (* setup_tc ) (struct nfp_app*,struct net_device*,int,void*) ;int (* bpf ) (struct nfp_app*,struct nfp_net*,struct netdev_bpf*) ;int (* xdp_offload ) (struct nfp_app*,struct nfp_net*,struct bpf_prog*,struct netlink_ext_ack*) ;int (* eswitch_mode_set ) (struct nfp_app*,int /*<<< orphan*/ ) ;int (* sriov_enable ) (struct nfp_app*,int) ;struct net_device* (* repr_get ) (struct nfp_app*,int) ;int /*<<< orphan*/  (* sriov_disable ) (struct nfp_app*) ;int /*<<< orphan*/  (* eswitch_mode_get ) (struct nfp_app*) ;int /*<<< orphan*/  (* ctrl_msg_rx_raw ) (struct nfp_app*,void const*,unsigned int) ;int /*<<< orphan*/  (* ctrl_msg_rx ) (struct nfp_app*,struct sk_buff*) ;int /*<<< orphan*/  (* stop ) (struct nfp_app*) ;int /*<<< orphan*/  (* repr_clean ) (struct nfp_app*,struct net_device*) ;int /*<<< orphan*/  (* repr_preclean ) (struct nfp_app*,struct net_device*) ;int /*<<< orphan*/  (* vnic_clean ) (struct nfp_app*,struct nfp_net*) ;int /*<<< orphan*/  (* vnic_free ) (struct nfp_app*,struct nfp_net*) ;int /*<<< orphan*/  (* clean ) (struct nfp_app*) ;} ;
struct TYPE_7__ {int port_id; } ;
struct TYPE_8__ {TYPE_2__ port_info; } ;
struct TYPE_9__ {TYPE_3__ u; } ;
struct TYPE_6__ {scalar_t__ count; } ;

/* Variables and functions */
 int EINVAL ; 
 int EOPNOTSUPP ; 
 int NFP_CPP_INTERFACE_UNIT_of (int /*<<< orphan*/ ) ; 
 int NFP_CPP_TARGET_ID_MASK ; 
 int __nfp_ctrl_tx (struct nfp_net*,struct sk_buff*) ; 
 struct nfp_repr* netdev_priv (struct net_device*) ; 
 int /*<<< orphan*/  nfp_cpp_interface (struct nfp_cpp*) ; 
 int nfp_ctrl_tx (struct nfp_net*,struct sk_buff*) ; 
 int /*<<< orphan*/  nfp_err (int /*<<< orphan*/ ,char*,scalar_t__,scalar_t__) ; 
 int nfp_nsp_get_abi_ver_minor (struct nfp_nsp*) ; 
 struct net_device* nfp_repr_alloc_mqs (struct nfp_app*,int,int) ; 
 int /*<<< orphan*/  nfp_repr_netdev_ops ; 
 int /*<<< orphan*/  priv_to_devlink (struct nfp_pf*) ; 
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
 struct net_device* stub26 (struct nfp_app*,int) ; 
 int stub3 (struct nfp_app*,struct nfp_net*,unsigned int) ; 
 int /*<<< orphan*/  stub4 (struct nfp_app*,struct nfp_net*) ; 
 int stub5 (struct nfp_app*,struct nfp_net*) ; 
 int /*<<< orphan*/  stub6 (struct nfp_app*,struct nfp_net*) ; 
 int stub7 (struct nfp_app*,struct nfp_repr*) ; 
 int stub8 (struct nfp_app*,struct nfp_repr*) ; 
 int stub9 (struct nfp_app*,struct net_device*) ; 
 int /*<<< orphan*/  trace_devlink_hwmsg (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,void const*,unsigned int) ; 
 scalar_t__ unlikely (int) ; 

__attribute__((used)) static inline u8 NFP_CPP_ID_TARGET_of(u32 id)
{
	return (id >> 24) & NFP_CPP_TARGET_ID_MASK;
}

__attribute__((used)) static inline u8 NFP_CPP_ID_TOKEN_of(u32 id)
{
	return (id >> 16) & 0xff;
}

__attribute__((used)) static inline u8 NFP_CPP_ID_ACTION_of(u32 id)
{
	return (id >> 8) & 0xff;
}

__attribute__((used)) static inline u8 NFP_CPP_ID_ISLAND_of(u32 id)
{
	return (id >> 0) & 0xff;
}

__attribute__((used)) static inline u8 nfp_cppcore_pcie_unit(struct nfp_cpp *cpp)
{
	return NFP_CPP_INTERFACE_UNIT_of(nfp_cpp_interface(cpp));
}

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

__attribute__((used)) static int nfp_nic_init(struct nfp_app *app)
{
	struct nfp_pf *pf = app->pf;

	if (pf->eth_tbl && pf->max_data_vnics != pf->eth_tbl->count) {
		nfp_err(pf->cpp, "ETH entries don't match vNICs (%d vs %d)\n",
			pf->max_data_vnics, pf->eth_tbl->count);
		return -EINVAL;
	}

	return 0;
}

__attribute__((used)) static int nfp_nic_sriov_enable(struct nfp_app *app, int num_vfs)
{
	return 0;
}

__attribute__((used)) static void nfp_nic_sriov_disable(struct nfp_app *app)
{
}

