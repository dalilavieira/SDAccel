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
typedef  int /*<<< orphan*/  u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct tls_crypto_info {int dummy; } ;
struct mlx5_core_dev {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int mlx5_fpga_is_tls_device (struct mlx5_core_dev*) ; 
 int mlx5_fpga_tls_add_flow (struct mlx5_core_dev*,void*,struct tls_crypto_info*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mlx5_fpga_tls_cleanup (struct mlx5_core_dev*) ; 
 int /*<<< orphan*/  mlx5_fpga_tls_del_flow (struct mlx5_core_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mlx5_fpga_tls_device_caps (struct mlx5_core_dev*) ; 
 int mlx5_fpga_tls_init (struct mlx5_core_dev*) ; 
 int mlx5_fpga_tls_resync_rx (struct mlx5_core_dev*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int mlx5_accel_tls_add_flow(struct mlx5_core_dev *mdev, void *flow,
			    struct tls_crypto_info *crypto_info,
			    u32 start_offload_tcp_sn, u32 *p_swid,
			    bool direction_sx)
{
	return mlx5_fpga_tls_add_flow(mdev, flow, crypto_info,
				      start_offload_tcp_sn, p_swid,
				      direction_sx);
}

void mlx5_accel_tls_del_flow(struct mlx5_core_dev *mdev, u32 swid,
			     bool direction_sx)
{
	mlx5_fpga_tls_del_flow(mdev, swid, GFP_KERNEL, direction_sx);
}

int mlx5_accel_tls_resync_rx(struct mlx5_core_dev *mdev, u32 handle, u32 seq,
			     u64 rcd_sn)
{
	return mlx5_fpga_tls_resync_rx(mdev, handle, seq, rcd_sn);
}

bool mlx5_accel_is_tls_device(struct mlx5_core_dev *mdev)
{
	return mlx5_fpga_is_tls_device(mdev);
}

u32 mlx5_accel_tls_device_caps(struct mlx5_core_dev *mdev)
{
	return mlx5_fpga_tls_device_caps(mdev);
}

int mlx5_accel_tls_init(struct mlx5_core_dev *mdev)
{
	return mlx5_fpga_tls_init(mdev);
}

void mlx5_accel_tls_cleanup(struct mlx5_core_dev *mdev)
{
	mlx5_fpga_tls_cleanup(mdev);
}

