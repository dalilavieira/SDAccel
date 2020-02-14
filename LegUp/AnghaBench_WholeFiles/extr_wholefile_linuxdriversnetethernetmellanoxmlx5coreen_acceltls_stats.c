#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  u64 ;
struct mlx5e_priv {TYPE_1__* tls; } ;
struct TYPE_5__ {int /*<<< orphan*/  format; } ;
struct TYPE_4__ {int /*<<< orphan*/  sw_stats; } ;

/* Variables and functions */
 int ETH_GSTRING_LEN ; 
 int /*<<< orphan*/  MLX5E_READ_CTR_ATOMIC64 (int /*<<< orphan*/ *,TYPE_2__*,int) ; 
 int NUM_TLS_SW_COUNTERS ; 
 TYPE_2__* mlx5e_tls_sw_stats_desc ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

int mlx5e_tls_get_count(struct mlx5e_priv *priv)
{
	if (!priv->tls)
		return 0;

	return NUM_TLS_SW_COUNTERS;
}

int mlx5e_tls_get_strings(struct mlx5e_priv *priv, uint8_t *data)
{
	unsigned int i, idx = 0;

	if (!priv->tls)
		return 0;

	for (i = 0; i < NUM_TLS_SW_COUNTERS; i++)
		strcpy(data + (idx++) * ETH_GSTRING_LEN,
		       mlx5e_tls_sw_stats_desc[i].format);

	return NUM_TLS_SW_COUNTERS;
}

int mlx5e_tls_get_stats(struct mlx5e_priv *priv, u64 *data)
{
	int i, idx = 0;

	if (!priv->tls)
		return 0;

	for (i = 0; i < NUM_TLS_SW_COUNTERS; i++)
		data[idx++] =
		    MLX5E_READ_CTR_ATOMIC64(&priv->tls->sw_stats,
					    mlx5e_tls_sw_stats_desc, i);

	return NUM_TLS_SW_COUNTERS;
}

