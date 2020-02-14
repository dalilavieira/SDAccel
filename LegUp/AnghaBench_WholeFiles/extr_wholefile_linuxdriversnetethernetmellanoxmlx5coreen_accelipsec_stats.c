#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  u64 ;
struct mlx5e_priv {TYPE_1__* ipsec; int /*<<< orphan*/  mdev; } ;
struct TYPE_8__ {int /*<<< orphan*/  format; } ;
struct TYPE_7__ {int /*<<< orphan*/  format; } ;
struct TYPE_6__ {int /*<<< orphan*/  sw_stats; int /*<<< orphan*/  stats; } ;

/* Variables and functions */
 int ETH_GSTRING_LEN ; 
 int /*<<< orphan*/  MLX5E_READ_CTR64_CPU (int /*<<< orphan*/ *,TYPE_3__*,int) ; 
 int /*<<< orphan*/  MLX5E_READ_CTR_ATOMIC64 (int /*<<< orphan*/ *,TYPE_2__*,int) ; 
 int NUM_IPSEC_COUNTERS ; 
 unsigned int NUM_IPSEC_HW_COUNTERS ; 
 unsigned int NUM_IPSEC_SW_COUNTERS ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int mlx5_accel_ipsec_counters_read (int /*<<< orphan*/ ,int /*<<< orphan*/ *,unsigned int) ; 
 TYPE_3__* mlx5e_ipsec_hw_stats_desc ; 
 TYPE_2__* mlx5e_ipsec_sw_stats_desc ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int mlx5e_ipsec_get_count(struct mlx5e_priv *priv)
{
	if (!priv->ipsec)
		return 0;

	return NUM_IPSEC_COUNTERS;
}

int mlx5e_ipsec_get_strings(struct mlx5e_priv *priv, uint8_t *data)
{
	unsigned int i, idx = 0;

	if (!priv->ipsec)
		return 0;

	for (i = 0; i < NUM_IPSEC_HW_COUNTERS; i++)
		strcpy(data + (idx++) * ETH_GSTRING_LEN,
		       mlx5e_ipsec_hw_stats_desc[i].format);

	for (i = 0; i < NUM_IPSEC_SW_COUNTERS; i++)
		strcpy(data + (idx++) * ETH_GSTRING_LEN,
		       mlx5e_ipsec_sw_stats_desc[i].format);

	return NUM_IPSEC_COUNTERS;
}

void mlx5e_ipsec_update_stats(struct mlx5e_priv *priv)
{
	int ret;

	if (!priv->ipsec)
		return;

	ret = mlx5_accel_ipsec_counters_read(priv->mdev, (u64 *)&priv->ipsec->stats,
					     NUM_IPSEC_HW_COUNTERS);
	if (ret)
		memset(&priv->ipsec->stats, 0, sizeof(priv->ipsec->stats));
}

int mlx5e_ipsec_get_stats(struct mlx5e_priv *priv, u64 *data)
{
	int i, idx = 0;

	if (!priv->ipsec)
		return 0;

	for (i = 0; i < NUM_IPSEC_HW_COUNTERS; i++)
		data[idx++] = MLX5E_READ_CTR64_CPU(&priv->ipsec->stats,
						   mlx5e_ipsec_hw_stats_desc, i);

	for (i = 0; i < NUM_IPSEC_SW_COUNTERS; i++)
		data[idx++] = MLX5E_READ_CTR_ATOMIC64(&priv->ipsec->sw_stats,
						      mlx5e_ipsec_sw_stats_desc, i);

	return NUM_IPSEC_COUNTERS;
}

