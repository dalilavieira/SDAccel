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
struct mlx5_core_dev {int dummy; } ;
struct mlx5_accel_esp_xfrm_attrs {int dummy; } ;
struct mlx5_accel_esp_xfrm {struct mlx5_core_dev* mdev; } ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 scalar_t__ IS_ERR (struct mlx5_accel_esp_xfrm*) ; 
 struct mlx5_accel_esp_xfrm* mlx5_fpga_esp_create_xfrm (struct mlx5_core_dev*,struct mlx5_accel_esp_xfrm_attrs const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx5_fpga_esp_destroy_xfrm (struct mlx5_accel_esp_xfrm*) ; 
 int mlx5_fpga_esp_modify_xfrm (struct mlx5_accel_esp_xfrm*,struct mlx5_accel_esp_xfrm_attrs const*) ; 
 int /*<<< orphan*/  mlx5_fpga_ipsec_cleanup (struct mlx5_core_dev*) ; 
 unsigned int mlx5_fpga_ipsec_counters_count (struct mlx5_core_dev*) ; 
 int mlx5_fpga_ipsec_counters_read (struct mlx5_core_dev*,int /*<<< orphan*/ *,unsigned int) ; 
 void* mlx5_fpga_ipsec_create_sa_ctx (struct mlx5_core_dev*,struct mlx5_accel_esp_xfrm*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const,int) ; 
 int /*<<< orphan*/  mlx5_fpga_ipsec_delete_sa_ctx (void*) ; 
 int /*<<< orphan*/  mlx5_fpga_ipsec_device_caps (struct mlx5_core_dev*) ; 
 int mlx5_fpga_ipsec_init (struct mlx5_core_dev*) ; 

u32 mlx5_accel_ipsec_device_caps(struct mlx5_core_dev *mdev)
{
	return mlx5_fpga_ipsec_device_caps(mdev);
}

unsigned int mlx5_accel_ipsec_counters_count(struct mlx5_core_dev *mdev)
{
	return mlx5_fpga_ipsec_counters_count(mdev);
}

int mlx5_accel_ipsec_counters_read(struct mlx5_core_dev *mdev, u64 *counters,
				   unsigned int count)
{
	return mlx5_fpga_ipsec_counters_read(mdev, counters, count);
}

void *mlx5_accel_esp_create_hw_context(struct mlx5_core_dev *mdev,
				       struct mlx5_accel_esp_xfrm *xfrm,
				       const __be32 saddr[4],
				       const __be32 daddr[4],
				       const __be32 spi, bool is_ipv6)
{
	return mlx5_fpga_ipsec_create_sa_ctx(mdev, xfrm, saddr, daddr,
					     spi, is_ipv6);
}

void mlx5_accel_esp_free_hw_context(void *context)
{
	mlx5_fpga_ipsec_delete_sa_ctx(context);
}

int mlx5_accel_ipsec_init(struct mlx5_core_dev *mdev)
{
	return mlx5_fpga_ipsec_init(mdev);
}

void mlx5_accel_ipsec_cleanup(struct mlx5_core_dev *mdev)
{
	mlx5_fpga_ipsec_cleanup(mdev);
}

struct mlx5_accel_esp_xfrm *
mlx5_accel_esp_create_xfrm(struct mlx5_core_dev *mdev,
			   const struct mlx5_accel_esp_xfrm_attrs *attrs,
			   u32 flags)
{
	struct mlx5_accel_esp_xfrm *xfrm;

	xfrm = mlx5_fpga_esp_create_xfrm(mdev, attrs, flags);
	if (IS_ERR(xfrm))
		return xfrm;

	xfrm->mdev = mdev;
	return xfrm;
}

void mlx5_accel_esp_destroy_xfrm(struct mlx5_accel_esp_xfrm *xfrm)
{
	mlx5_fpga_esp_destroy_xfrm(xfrm);
}

int mlx5_accel_esp_modify_xfrm(struct mlx5_accel_esp_xfrm *xfrm,
			       const struct mlx5_accel_esp_xfrm_attrs *attrs)
{
	return mlx5_fpga_esp_modify_xfrm(xfrm, attrs);
}

