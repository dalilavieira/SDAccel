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
typedef  size_t u8 ;
typedef  int u32 ;
struct mlx5_fpga_query {int oper_image; scalar_t__ status; int /*<<< orphan*/  admin_image; } ;
struct mlx5_fpga_device {scalar_t__ state; int last_oper_image; struct mlx5_core_dev* mdev; int /*<<< orphan*/  state_lock; int /*<<< orphan*/  last_admin_image; } ;
struct mlx5_core_dev {struct mlx5_fpga_device* fpga; } ;
typedef  enum mlx5_fpga_image { ____Placeholder_mlx5_fpga_image } mlx5_fpga_image ;
struct TYPE_2__ {int /*<<< orphan*/  max_num_qps; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (char const**) ; 
 int EIO ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 void* MLX5_CAP_FPGA (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MLX5_CAP_GEN (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 
#define  MLX5_EVENT_TYPE_FPGA_ERROR 136 
#define  MLX5_EVENT_TYPE_FPGA_QP_ERROR 135 
 int /*<<< orphan*/  MLX5_FPGA_CTRL_OPERATION_RESET_SANDBOX ; 
 int /*<<< orphan*/  MLX5_FPGA_CTRL_OPERATION_SANDBOX_BYPASS_OFF ; 
 int /*<<< orphan*/  MLX5_FPGA_CTRL_OPERATION_SANDBOX_BYPASS_ON ; 
#define  MLX5_FPGA_DEVICE_KU040 134 
#define  MLX5_FPGA_DEVICE_KU060 133 
#define  MLX5_FPGA_DEVICE_KU060_2 132 
#define  MLX5_FPGA_DEVICE_UNKNOWN 131 
#define  MLX5_FPGA_IMAGE_FACTORY 130 
#define  MLX5_FPGA_IMAGE_USER 129 
 scalar_t__ MLX5_FPGA_STATUS_FAILURE ; 
 void* MLX5_FPGA_STATUS_NONE ; 
#define  MLX5_FPGA_STATUS_SUCCESS 128 
 void* MLX5_GET (int /*<<< orphan*/ ,void*,int) ; 
 int /*<<< orphan*/  fpga ; 
 int /*<<< orphan*/  fpga_device ; 
 int /*<<< orphan*/  fpga_error_event ; 
 int /*<<< orphan*/  fpga_qp_error_event ; 
 int /*<<< orphan*/  ieee_vendor_id ; 
 int /*<<< orphan*/  image_version ; 
 int /*<<< orphan*/  kfree (struct mlx5_fpga_device*) ; 
 struct mlx5_fpga_device* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5_core_dbg (struct mlx5_core_dev*,char*) ; 
 int mlx5_core_reserve_gids (struct mlx5_core_dev*,unsigned int) ; 
 int /*<<< orphan*/  mlx5_core_unreserve_gids (struct mlx5_core_dev*,unsigned int) ; 
 int mlx5_fpga_caps (struct mlx5_core_dev*) ; 
 int /*<<< orphan*/  mlx5_fpga_conn_device_cleanup (struct mlx5_fpga_device*) ; 
 int mlx5_fpga_conn_device_init (struct mlx5_fpga_device*) ; 
 int mlx5_fpga_ctrl_op (struct mlx5_core_dev*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5_fpga_dbg (struct mlx5_fpga_device*,char*,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mlx5_fpga_err (struct mlx5_fpga_device*,char*,...) ; 
 char const** mlx5_fpga_error_strings ; 
 int /*<<< orphan*/  mlx5_fpga_info (struct mlx5_fpga_device*,char*,char const*,int,char const*,void*,void*,void*,void*) ; 
 char const** mlx5_fpga_qp_error_strings ; 
 int mlx5_fpga_query (struct mlx5_core_dev*,struct mlx5_fpga_query*) ; 
 int /*<<< orphan*/  mlx5_fpga_warn (struct mlx5_fpga_device*,char*,size_t,char const*) ; 
 int /*<<< orphan*/  mlx5_fpga_warn_ratelimited (struct mlx5_fpga_device*,char*,size_t,...) ; 
 int /*<<< orphan*/  mlx5_trigger_health_work (struct mlx5_core_dev*) ; 
 int /*<<< orphan*/  sandbox_product_id ; 
 int /*<<< orphan*/  sandbox_product_version ; 
 TYPE_1__ shell_caps ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static struct mlx5_fpga_device *mlx5_fpga_device_alloc(void)
{
	struct mlx5_fpga_device *fdev = NULL;

	fdev = kzalloc(sizeof(*fdev), GFP_KERNEL);
	if (!fdev)
		return NULL;

	spin_lock_init(&fdev->state_lock);
	fdev->state = MLX5_FPGA_STATUS_NONE;
	return fdev;
}

__attribute__((used)) static const char *mlx5_fpga_image_name(enum mlx5_fpga_image image)
{
	switch (image) {
	case MLX5_FPGA_IMAGE_USER:
		return "user";
	case MLX5_FPGA_IMAGE_FACTORY:
		return "factory";
	default:
		return "unknown";
	}
}

__attribute__((used)) static const char *mlx5_fpga_device_name(u32 device)
{
	switch (device) {
	case MLX5_FPGA_DEVICE_KU040:
		return "ku040";
	case MLX5_FPGA_DEVICE_KU060:
		return "ku060";
	case MLX5_FPGA_DEVICE_KU060_2:
		return "ku060_2";
	case MLX5_FPGA_DEVICE_UNKNOWN:
	default:
		return "unknown";
	}
}

__attribute__((used)) static int mlx5_fpga_device_load_check(struct mlx5_fpga_device *fdev)
{
	struct mlx5_fpga_query query;
	int err;

	err = mlx5_fpga_query(fdev->mdev, &query);
	if (err) {
		mlx5_fpga_err(fdev, "Failed to query status: %d\n", err);
		return err;
	}

	fdev->last_admin_image = query.admin_image;
	fdev->last_oper_image = query.oper_image;

	mlx5_fpga_dbg(fdev, "Status %u; Admin image %u; Oper image %u\n",
		      query.status, query.admin_image, query.oper_image);

	if (query.status != MLX5_FPGA_STATUS_SUCCESS) {
		mlx5_fpga_err(fdev, "%s image failed to load; status %u\n",
			      mlx5_fpga_image_name(fdev->last_oper_image),
			      query.status);
		return -EIO;
	}

	return 0;
}

__attribute__((used)) static int mlx5_fpga_device_brb(struct mlx5_fpga_device *fdev)
{
	int err;
	struct mlx5_core_dev *mdev = fdev->mdev;

	err = mlx5_fpga_ctrl_op(mdev, MLX5_FPGA_CTRL_OPERATION_SANDBOX_BYPASS_ON);
	if (err) {
		mlx5_fpga_err(fdev, "Failed to set bypass on: %d\n", err);
		return err;
	}
	err = mlx5_fpga_ctrl_op(mdev, MLX5_FPGA_CTRL_OPERATION_RESET_SANDBOX);
	if (err) {
		mlx5_fpga_err(fdev, "Failed to reset SBU: %d\n", err);
		return err;
	}
	err = mlx5_fpga_ctrl_op(mdev, MLX5_FPGA_CTRL_OPERATION_SANDBOX_BYPASS_OFF);
	if (err) {
		mlx5_fpga_err(fdev, "Failed to set bypass off: %d\n", err);
		return err;
	}
	return 0;
}

int mlx5_fpga_device_start(struct mlx5_core_dev *mdev)
{
	struct mlx5_fpga_device *fdev = mdev->fpga;
	unsigned int max_num_qps;
	unsigned long flags;
	u32 fpga_device_id;
	int err;

	if (!fdev)
		return 0;

	err = mlx5_fpga_device_load_check(fdev);
	if (err)
		goto out;

	err = mlx5_fpga_caps(fdev->mdev);
	if (err)
		goto out;

	fpga_device_id = MLX5_CAP_FPGA(fdev->mdev, fpga_device);
	mlx5_fpga_info(fdev, "%s:%u; %s image, version %u; SBU %06x:%04x version %d\n",
		       mlx5_fpga_device_name(fpga_device_id),
		       fpga_device_id,
		       mlx5_fpga_image_name(fdev->last_oper_image),
		       MLX5_CAP_FPGA(fdev->mdev, image_version),
		       MLX5_CAP_FPGA(fdev->mdev, ieee_vendor_id),
		       MLX5_CAP_FPGA(fdev->mdev, sandbox_product_id),
		       MLX5_CAP_FPGA(fdev->mdev, sandbox_product_version));

	max_num_qps = MLX5_CAP_FPGA(mdev, shell_caps.max_num_qps);
	if (!max_num_qps) {
		mlx5_fpga_err(fdev, "FPGA reports 0 QPs in SHELL_CAPS\n");
		err = -ENOTSUPP;
		goto out;
	}

	err = mlx5_core_reserve_gids(mdev, max_num_qps);
	if (err)
		goto out;

	err = mlx5_fpga_conn_device_init(fdev);
	if (err)
		goto err_rsvd_gid;

	if (fdev->last_oper_image == MLX5_FPGA_IMAGE_USER) {
		err = mlx5_fpga_device_brb(fdev);
		if (err)
			goto err_conn_init;
	}

	goto out;

err_conn_init:
	mlx5_fpga_conn_device_cleanup(fdev);

err_rsvd_gid:
	mlx5_core_unreserve_gids(mdev, max_num_qps);
out:
	spin_lock_irqsave(&fdev->state_lock, flags);
	fdev->state = err ? MLX5_FPGA_STATUS_FAILURE : MLX5_FPGA_STATUS_SUCCESS;
	spin_unlock_irqrestore(&fdev->state_lock, flags);
	return err;
}

int mlx5_fpga_init(struct mlx5_core_dev *mdev)
{
	struct mlx5_fpga_device *fdev = NULL;

	if (!MLX5_CAP_GEN(mdev, fpga)) {
		mlx5_core_dbg(mdev, "FPGA capability not present\n");
		return 0;
	}

	mlx5_core_dbg(mdev, "Initializing FPGA\n");

	fdev = mlx5_fpga_device_alloc();
	if (!fdev)
		return -ENOMEM;

	fdev->mdev = mdev;
	mdev->fpga = fdev;

	return 0;
}

void mlx5_fpga_device_stop(struct mlx5_core_dev *mdev)
{
	struct mlx5_fpga_device *fdev = mdev->fpga;
	unsigned int max_num_qps;
	unsigned long flags;
	int err;

	if (!fdev)
		return;

	spin_lock_irqsave(&fdev->state_lock, flags);
	if (fdev->state != MLX5_FPGA_STATUS_SUCCESS) {
		spin_unlock_irqrestore(&fdev->state_lock, flags);
		return;
	}
	fdev->state = MLX5_FPGA_STATUS_NONE;
	spin_unlock_irqrestore(&fdev->state_lock, flags);

	if (fdev->last_oper_image == MLX5_FPGA_IMAGE_USER) {
		err = mlx5_fpga_ctrl_op(mdev, MLX5_FPGA_CTRL_OPERATION_SANDBOX_BYPASS_ON);
		if (err)
			mlx5_fpga_err(fdev, "Failed to re-set SBU bypass on: %d\n",
				      err);
	}

	mlx5_fpga_conn_device_cleanup(fdev);
	max_num_qps = MLX5_CAP_FPGA(mdev, shell_caps.max_num_qps);
	mlx5_core_unreserve_gids(mdev, max_num_qps);
}

void mlx5_fpga_cleanup(struct mlx5_core_dev *mdev)
{
	struct mlx5_fpga_device *fdev = mdev->fpga;

	mlx5_fpga_device_stop(mdev);
	kfree(fdev);
	mdev->fpga = NULL;
}

__attribute__((used)) static const char *mlx5_fpga_syndrome_to_string(u8 syndrome)
{
	if (syndrome < ARRAY_SIZE(mlx5_fpga_error_strings))
		return mlx5_fpga_error_strings[syndrome];
	return "Unknown";
}

__attribute__((used)) static const char *mlx5_fpga_qp_syndrome_to_string(u8 syndrome)
{
	if (syndrome < ARRAY_SIZE(mlx5_fpga_qp_error_strings))
		return mlx5_fpga_qp_error_strings[syndrome];
	return "Unknown";
}

void mlx5_fpga_event(struct mlx5_core_dev *mdev, u8 event, void *data)
{
	struct mlx5_fpga_device *fdev = mdev->fpga;
	const char *event_name;
	bool teardown = false;
	unsigned long flags;
	u32 fpga_qpn;
	u8 syndrome;

	switch (event) {
	case MLX5_EVENT_TYPE_FPGA_ERROR:
		syndrome = MLX5_GET(fpga_error_event, data, syndrome);
		event_name = mlx5_fpga_syndrome_to_string(syndrome);
		break;
	case MLX5_EVENT_TYPE_FPGA_QP_ERROR:
		syndrome = MLX5_GET(fpga_qp_error_event, data, syndrome);
		event_name = mlx5_fpga_qp_syndrome_to_string(syndrome);
		fpga_qpn = MLX5_GET(fpga_qp_error_event, data, fpga_qpn);
		break;
	default:
		mlx5_fpga_warn_ratelimited(fdev, "Unexpected event %u\n",
					   event);
		return;
	}

	spin_lock_irqsave(&fdev->state_lock, flags);
	switch (fdev->state) {
	case MLX5_FPGA_STATUS_SUCCESS:
		mlx5_fpga_warn(fdev, "Error %u: %s\n", syndrome, event_name);
		teardown = true;
		break;
	default:
		mlx5_fpga_warn_ratelimited(fdev, "Unexpected error event %u: %s\n",
					   syndrome, event_name);
	}
	spin_unlock_irqrestore(&fdev->state_lock, flags);
	/* We tear-down the card's interfaces and functionality because
	 * the FPGA bump-on-the-wire is misbehaving and we lose ability
	 * to communicate with the network. User may still be able to
	 * recover by re-programming or debugging the FPGA
	 */
	if (teardown)
		mlx5_trigger_health_work(fdev->mdev);
}

