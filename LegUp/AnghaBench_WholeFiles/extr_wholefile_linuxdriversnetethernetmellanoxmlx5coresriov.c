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
typedef  int /*<<< orphan*/  u8 ;
struct pci_dev {int dummy; } ;
struct mlx5_hca_vport_context {scalar_t__ policy; int field_select; int enabled; scalar_t__ node_guid; scalar_t__ port_guid; } ;
struct mlx5_eswitch {int dummy; } ;
struct mlx5_eqe {int dummy; } ;
struct mlx5_core_sriov {int num_vfs; int enabled_vfs; struct mlx5_hca_vport_context* vfs_ctx; } ;
struct TYPE_2__ {struct mlx5_core_sriov sriov; struct mlx5_eswitch* eswitch; } ;
struct mlx5_core_dev {TYPE_1__ priv; struct pci_dev* pdev; } ;

/* Variables and functions */
 int EBUSY ; 
 int ENODEV ; 
 int ENOMEM ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int MLX5_CAP_GEN (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 
 int MLX5_CAP_PORT_TYPE_IB ; 
 scalar_t__ MLX5_ESWITCH_MANAGER (struct mlx5_core_dev*) ; 
 int MLX5_HCA_VPORT_SEL_NODE_GUID ; 
 int MLX5_HCA_VPORT_SEL_PORT_GUID ; 
 int MLX5_HCA_VPORT_SEL_STATE_POLICY ; 
 scalar_t__ MLX5_POLICY_INVALID ; 
 int SRIOV_LEGACY ; 
 struct mlx5_hca_vport_context* kcalloc (int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct mlx5_hca_vport_context*) ; 
 struct mlx5_hca_vport_context* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lag_master ; 
 int /*<<< orphan*/  mlx5_core_dbg (struct mlx5_core_dev*,char*,int) ; 
 int mlx5_core_disable_hca (struct mlx5_core_dev*,int) ; 
 int mlx5_core_enable_hca (struct mlx5_core_dev*,int) ; 
 int /*<<< orphan*/  mlx5_core_is_pf (struct mlx5_core_dev*) ; 
 int mlx5_core_modify_hca_vport_context (struct mlx5_core_dev*,int,int,int,struct mlx5_hca_vport_context*) ; 
 int /*<<< orphan*/  mlx5_core_warn (struct mlx5_core_dev*,char*,...) ; 
 int /*<<< orphan*/  mlx5_lag_allow (struct mlx5_core_dev*) ; 
 int mlx5_lag_forbid (struct mlx5_core_dev*) ; 
 scalar_t__ mlx5_wait_for_vf_pages (struct mlx5_core_dev*) ; 
 int /*<<< orphan*/  num_lag_ports ; 
 int /*<<< orphan*/  pci_disable_sriov (struct pci_dev*) ; 
 int pci_enable_sriov (struct pci_dev*,int) ; 
 struct mlx5_core_dev* pci_get_drvdata (struct pci_dev*) ; 
 int pci_num_vf (struct pci_dev*) ; 
 int pci_sriov_get_totalvfs (struct pci_dev*) ; 
 int /*<<< orphan*/  port_type ; 
 int /*<<< orphan*/  vport_group_manager ; 

__attribute__((used)) static inline int mlx5_lag_is_lacp_owner(struct mlx5_core_dev *dev)
{
	/* LACP owner conditions:
	 * 1) Function is physical.
	 * 2) LAG is supported by FW.
	 * 3) LAG is managed by driver (currently the only option).
	 */
	return  MLX5_CAP_GEN(dev, vport_group_manager) &&
		   (MLX5_CAP_GEN(dev, num_lag_ports) > 1) &&
		    MLX5_CAP_GEN(dev, lag_master);
}

__attribute__((used)) static inline int  mlx5_mpfs_init(struct mlx5_core_dev *dev) { return 0; }

__attribute__((used)) static inline void mlx5_mpfs_cleanup(struct mlx5_core_dev *dev) {}

__attribute__((used)) static inline int  mlx5_mpfs_add_mac(struct mlx5_core_dev *dev, u8 *mac) { return 0; }

__attribute__((used)) static inline int  mlx5_mpfs_del_mac(struct mlx5_core_dev *dev, u8 *mac) { return 0; }

__attribute__((used)) static inline int  mlx5_eswitch_init(struct mlx5_core_dev *dev) { return 0; }

__attribute__((used)) static inline void mlx5_eswitch_cleanup(struct mlx5_eswitch *esw) {}

__attribute__((used)) static inline void mlx5_eswitch_vport_event(struct mlx5_eswitch *esw, struct mlx5_eqe *eqe) {}

__attribute__((used)) static inline int  mlx5_eswitch_enable_sriov(struct mlx5_eswitch *esw, int nvfs, int mode) { return 0; }

__attribute__((used)) static inline void mlx5_eswitch_disable_sriov(struct mlx5_eswitch *esw) {}

bool mlx5_sriov_is_enabled(struct mlx5_core_dev *dev)
{
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;

	return !!sriov->num_vfs;
}

__attribute__((used)) static int sriov_restore_guids(struct mlx5_core_dev *dev, int vf)
{
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;
	struct mlx5_hca_vport_context *in;
	int err = 0;

	/* Restore sriov guid and policy settings */
	if (sriov->vfs_ctx[vf].node_guid ||
	    sriov->vfs_ctx[vf].port_guid ||
	    sriov->vfs_ctx[vf].policy != MLX5_POLICY_INVALID) {
		in = kzalloc(sizeof(*in), GFP_KERNEL);
		if (!in)
			return -ENOMEM;

		in->node_guid = sriov->vfs_ctx[vf].node_guid;
		in->port_guid = sriov->vfs_ctx[vf].port_guid;
		in->policy = sriov->vfs_ctx[vf].policy;
		in->field_select =
			!!(in->port_guid) * MLX5_HCA_VPORT_SEL_PORT_GUID |
			!!(in->node_guid) * MLX5_HCA_VPORT_SEL_NODE_GUID |
			!!(in->policy) * MLX5_HCA_VPORT_SEL_STATE_POLICY;

		err = mlx5_core_modify_hca_vport_context(dev, 1, 1, vf + 1, in);
		if (err)
			mlx5_core_warn(dev, "modify vport context failed, unable to restore VF %d settings\n", vf);

		kfree(in);
	}

	return err;
}

__attribute__((used)) static int mlx5_device_enable_sriov(struct mlx5_core_dev *dev, int num_vfs)
{
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;
	int err;
	int vf;

	if (sriov->enabled_vfs) {
		mlx5_core_warn(dev,
			       "failed to enable SRIOV on device, already enabled with %d vfs\n",
			       sriov->enabled_vfs);
		return -EBUSY;
	}

	if (!MLX5_ESWITCH_MANAGER(dev))
		goto enable_vfs_hca;

	err = mlx5_eswitch_enable_sriov(dev->priv.eswitch, num_vfs, SRIOV_LEGACY);
	if (err) {
		mlx5_core_warn(dev,
			       "failed to enable eswitch SRIOV (%d)\n", err);
		return err;
	}

enable_vfs_hca:
	for (vf = 0; vf < num_vfs; vf++) {
		err = mlx5_core_enable_hca(dev, vf + 1);
		if (err) {
			mlx5_core_warn(dev, "failed to enable VF %d (%d)\n", vf, err);
			continue;
		}
		sriov->vfs_ctx[vf].enabled = 1;
		sriov->enabled_vfs++;
		if (MLX5_CAP_GEN(dev, port_type) == MLX5_CAP_PORT_TYPE_IB) {
			err = sriov_restore_guids(dev, vf);
			if (err) {
				mlx5_core_warn(dev,
					       "failed to restore VF %d settings, err %d\n",
					       vf, err);
				continue;
			}
		}
		mlx5_core_dbg(dev, "successfully enabled VF* %d\n", vf);
	}

	return 0;
}

__attribute__((used)) static void mlx5_device_disable_sriov(struct mlx5_core_dev *dev)
{
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;
	int err;
	int vf;

	if (!sriov->enabled_vfs)
		goto out;

	for (vf = 0; vf < sriov->num_vfs; vf++) {
		if (!sriov->vfs_ctx[vf].enabled)
			continue;
		err = mlx5_core_disable_hca(dev, vf + 1);
		if (err) {
			mlx5_core_warn(dev, "failed to disable VF %d\n", vf);
			continue;
		}
		sriov->vfs_ctx[vf].enabled = 0;
		sriov->enabled_vfs--;
	}

out:
	if (MLX5_ESWITCH_MANAGER(dev))
		mlx5_eswitch_disable_sriov(dev->priv.eswitch);

	if (mlx5_wait_for_vf_pages(dev))
		mlx5_core_warn(dev, "timeout reclaiming VFs pages\n");
}

__attribute__((used)) static int mlx5_pci_enable_sriov(struct pci_dev *pdev, int num_vfs)
{
	struct mlx5_core_dev *dev  = pci_get_drvdata(pdev);
	int err = 0;

	if (pci_num_vf(pdev)) {
		mlx5_core_warn(dev, "Unable to enable pci sriov, already enabled\n");
		return -EBUSY;
	}

	err = pci_enable_sriov(pdev, num_vfs);
	if (err)
		mlx5_core_warn(dev, "pci_enable_sriov failed : %d\n", err);

	return err;
}

__attribute__((used)) static void mlx5_pci_disable_sriov(struct pci_dev *pdev)
{
	pci_disable_sriov(pdev);
}

__attribute__((used)) static int mlx5_sriov_enable(struct pci_dev *pdev, int num_vfs)
{
	struct mlx5_core_dev *dev  = pci_get_drvdata(pdev);
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;
	int err = 0;

	err = mlx5_device_enable_sriov(dev, num_vfs);
	if (err) {
		mlx5_core_warn(dev, "mlx5_device_enable_sriov failed : %d\n", err);
		return err;
	}

	err = mlx5_pci_enable_sriov(pdev, num_vfs);
	if (err) {
		mlx5_core_warn(dev, "mlx5_pci_enable_sriov failed : %d\n", err);
		mlx5_device_disable_sriov(dev);
		return err;
	}

	sriov->num_vfs = num_vfs;

	return 0;
}

__attribute__((used)) static void mlx5_sriov_disable(struct pci_dev *pdev)
{
	struct mlx5_core_dev *dev  = pci_get_drvdata(pdev);
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;

	mlx5_pci_disable_sriov(pdev);
	mlx5_device_disable_sriov(dev);
	sriov->num_vfs = 0;
}

int mlx5_core_sriov_configure(struct pci_dev *pdev, int num_vfs)
{
	struct mlx5_core_dev *dev  = pci_get_drvdata(pdev);
	int err = 0;

	mlx5_core_dbg(dev, "requested num_vfs %d\n", num_vfs);
	if (!mlx5_core_is_pf(dev))
		return -EPERM;

	if (num_vfs) {
		int ret;

		ret = mlx5_lag_forbid(dev);
		if (ret && (ret != -ENODEV))
			return ret;
	}

	if (num_vfs) {
		err = mlx5_sriov_enable(pdev, num_vfs);
	} else {
		mlx5_sriov_disable(pdev);
		mlx5_lag_allow(dev);
	}

	return err ? err : num_vfs;
}

int mlx5_sriov_attach(struct mlx5_core_dev *dev)
{
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;

	if (!mlx5_core_is_pf(dev) || !sriov->num_vfs)
		return 0;

	/* If sriov VFs exist in PCI level, enable them in device level */
	return mlx5_device_enable_sriov(dev, sriov->num_vfs);
}

void mlx5_sriov_detach(struct mlx5_core_dev *dev)
{
	if (!mlx5_core_is_pf(dev))
		return;

	mlx5_device_disable_sriov(dev);
}

int mlx5_sriov_init(struct mlx5_core_dev *dev)
{
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;
	struct pci_dev *pdev = dev->pdev;
	int total_vfs;

	if (!mlx5_core_is_pf(dev))
		return 0;

	total_vfs = pci_sriov_get_totalvfs(pdev);
	sriov->num_vfs = pci_num_vf(pdev);
	sriov->vfs_ctx = kcalloc(total_vfs, sizeof(*sriov->vfs_ctx), GFP_KERNEL);
	if (!sriov->vfs_ctx)
		return -ENOMEM;

	return 0;
}

void mlx5_sriov_cleanup(struct mlx5_core_dev *dev)
{
	struct mlx5_core_sriov *sriov = &dev->priv.sriov;

	if (!mlx5_core_is_pf(dev))
		return;

	kfree(sriov->vfs_ctx);
}

