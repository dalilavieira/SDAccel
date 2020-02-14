#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_34__   TYPE_9__ ;
typedef  struct TYPE_33__   TYPE_8__ ;
typedef  struct TYPE_32__   TYPE_7__ ;
typedef  struct TYPE_31__   TYPE_6__ ;
typedef  struct TYPE_30__   TYPE_5__ ;
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;
typedef  struct TYPE_25__   TYPE_15__ ;
typedef  struct TYPE_24__   TYPE_12__ ;

/* Type definitions */
struct TYPE_27__ {scalar_t__ rx_filter; scalar_t__ tx_type; } ;
struct mlx4_en_priv {size_t port; int rx_ring_num; struct mlx4_en_dev* mdev; TYPE_2__ hwtstamp_config; TYPE_1__** rx_ring; struct mlx4_en_cq** rx_cq; } ;
struct mlx4_en_dev {int /*<<< orphan*/  uar_lock; int /*<<< orphan*/  uar_map; TYPE_9__* dev; int /*<<< orphan*/  priv_uar; int /*<<< orphan*/ * pndev; } ;
struct TYPE_25__ {void (* event ) (struct mlx4_cq*,int) ;int /*<<< orphan*/  comp; int /*<<< orphan*/  usage; scalar_t__* arm_db; scalar_t__* set_ci_db; } ;
struct TYPE_33__ {int /*<<< orphan*/  dma; scalar_t__* db; } ;
struct TYPE_31__ {scalar_t__ buf; } ;
struct TYPE_32__ {TYPE_6__ direct; } ;
struct TYPE_24__ {TYPE_8__ db; int /*<<< orphan*/  mtt; TYPE_7__ buf; } ;
struct mlx4_en_cq {int size; int buf_size; int ring; int type; int xdp_busy; TYPE_15__ mcq; int /*<<< orphan*/  moder_time; int /*<<< orphan*/  moder_cnt; int /*<<< orphan*/  napi; int /*<<< orphan*/ * buf; scalar_t__ vector; TYPE_12__ wqres; int /*<<< orphan*/  dev; int /*<<< orphan*/  irq_desc; } ;
typedef  void mlx4_cqe ;
struct mlx4_cq {int dummy; } ;
typedef  enum mlx4_event { ____Placeholder_mlx4_event } mlx4_event ;
typedef  enum cq_type { ____Placeholder_cq_type } cq_type ;
struct TYPE_28__ {int cqe_size; scalar_t__ num_comp_vectors; } ;
struct TYPE_34__ {int numa_node; TYPE_3__ caps; TYPE_5__* persist; } ;
struct TYPE_30__ {TYPE_4__* pdev; } ;
struct TYPE_29__ {int /*<<< orphan*/  dev; } ;
struct TYPE_26__ {int actual_size; int /*<<< orphan*/  affinity_mask; } ;

/* Variables and functions */
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  MLX4_CQ_DB_REQ_NOT ; 
 int /*<<< orphan*/  MLX4_RES_USAGE_DRIVER ; 
 int /*<<< orphan*/  NAPI_POLL_WEIGHT ; 
#define  RX 130 
#define  TX 129 
#define  TX_XDP 128 
 scalar_t__ cpumask_first (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  en_err (struct mlx4_en_priv*,char*) ; 
 int /*<<< orphan*/  irq_to_desc (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct mlx4_en_cq*) ; 
 struct mlx4_en_cq* kzalloc (int,int /*<<< orphan*/ ) ; 
 struct mlx4_en_cq* kzalloc_node (int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int mlx4_alloc_hwq_res (TYPE_9__*,TYPE_12__*,int) ; 
 int mlx4_assign_eq (TYPE_9__*,size_t,scalar_t__*) ; 
 int mlx4_cq_alloc (TYPE_9__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_15__*,scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mlx4_cq_arm (TYPE_15__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mlx4_cq_free (TYPE_9__*,TYPE_15__*) ; 
 int mlx4_cq_modify (TYPE_9__*,TYPE_15__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mlx4_en_poll_rx_cq ; 
 int /*<<< orphan*/  mlx4_en_poll_tx_cq ; 
 int /*<<< orphan*/  mlx4_en_rx_irq ; 
 int /*<<< orphan*/  mlx4_en_tx_irq ; 
 int /*<<< orphan*/  mlx4_eq_get_irq (TYPE_9__*,scalar_t__) ; 
 int /*<<< orphan*/  mlx4_err (struct mlx4_en_dev*,char*,scalar_t__) ; 
 int /*<<< orphan*/  mlx4_free_hwq_res (TYPE_9__*,TYPE_12__*,int) ; 
 scalar_t__ mlx4_is_eq_vector_valid (TYPE_9__*,size_t,scalar_t__) ; 
 int /*<<< orphan*/  mlx4_release_eq (TYPE_9__*,scalar_t__) ; 
 int /*<<< orphan*/  napi_disable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  napi_enable (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  netif_napi_add (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  netif_napi_del (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  netif_tx_napi_add (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  set_dev_node (int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static inline struct mlx4_cqe *mlx4_en_get_cqe(void *buf, int idx, int cqe_sz)
{
	return buf + idx * cqe_sz;
}

__attribute__((used)) static void mlx4_en_cq_event(struct mlx4_cq *cq, enum mlx4_event event)
{
	return;
}

int mlx4_en_create_cq(struct mlx4_en_priv *priv,
		      struct mlx4_en_cq **pcq,
		      int entries, int ring, enum cq_type mode,
		      int node)
{
	struct mlx4_en_dev *mdev = priv->mdev;
	struct mlx4_en_cq *cq;
	int err;

	cq = kzalloc_node(sizeof(*cq), GFP_KERNEL, node);
	if (!cq) {
		cq = kzalloc(sizeof(*cq), GFP_KERNEL);
		if (!cq) {
			en_err(priv, "Failed to allocate CQ structure\n");
			return -ENOMEM;
		}
	}

	cq->size = entries;
	cq->buf_size = cq->size * mdev->dev->caps.cqe_size;

	cq->ring = ring;
	cq->type = mode;
	cq->vector = mdev->dev->caps.num_comp_vectors;

	/* Allocate HW buffers on provided NUMA node.
	 * dev->numa_node is used in mtt range allocation flow.
	 */
	set_dev_node(&mdev->dev->persist->pdev->dev, node);
	err = mlx4_alloc_hwq_res(mdev->dev, &cq->wqres,
				cq->buf_size);
	set_dev_node(&mdev->dev->persist->pdev->dev, mdev->dev->numa_node);
	if (err)
		goto err_cq;

	cq->buf = (struct mlx4_cqe *)cq->wqres.buf.direct.buf;
	*pcq = cq;

	return 0;

err_cq:
	kfree(cq);
	*pcq = NULL;
	return err;
}

int mlx4_en_activate_cq(struct mlx4_en_priv *priv, struct mlx4_en_cq *cq,
			int cq_idx)
{
	struct mlx4_en_dev *mdev = priv->mdev;
	int err = 0;
	int timestamp_en = 0;
	bool assigned_eq = false;

	cq->dev = mdev->pndev[priv->port];
	cq->mcq.set_ci_db  = cq->wqres.db.db;
	cq->mcq.arm_db     = cq->wqres.db.db + 1;
	*cq->mcq.set_ci_db = 0;
	*cq->mcq.arm_db    = 0;
	memset(cq->buf, 0, cq->buf_size);

	if (cq->type == RX) {
		if (!mlx4_is_eq_vector_valid(mdev->dev, priv->port,
					     cq->vector)) {
			cq->vector = cpumask_first(priv->rx_ring[cq->ring]->affinity_mask);

			err = mlx4_assign_eq(mdev->dev, priv->port,
					     &cq->vector);
			if (err) {
				mlx4_err(mdev, "Failed assigning an EQ to CQ vector %d\n",
					 cq->vector);
				goto free_eq;
			}

			assigned_eq = true;
		}

		cq->irq_desc =
			irq_to_desc(mlx4_eq_get_irq(mdev->dev,
						    cq->vector));
	} else {
		/* For TX we use the same irq per
		ring we assigned for the RX    */
		struct mlx4_en_cq *rx_cq;

		cq_idx = cq_idx % priv->rx_ring_num;
		rx_cq = priv->rx_cq[cq_idx];
		cq->vector = rx_cq->vector;
	}

	if (cq->type == RX)
		cq->size = priv->rx_ring[cq->ring]->actual_size;

	if ((cq->type != RX && priv->hwtstamp_config.tx_type) ||
	    (cq->type == RX && priv->hwtstamp_config.rx_filter))
		timestamp_en = 1;

	cq->mcq.usage = MLX4_RES_USAGE_DRIVER;
	err = mlx4_cq_alloc(mdev->dev, cq->size, &cq->wqres.mtt,
			    &mdev->priv_uar, cq->wqres.db.dma, &cq->mcq,
			    cq->vector, 0, timestamp_en);
	if (err)
		goto free_eq;

	cq->mcq.event = mlx4_en_cq_event;

	switch (cq->type) {
	case TX:
		cq->mcq.comp = mlx4_en_tx_irq;
		netif_tx_napi_add(cq->dev, &cq->napi, mlx4_en_poll_tx_cq,
				  NAPI_POLL_WEIGHT);
		napi_enable(&cq->napi);
		break;
	case RX:
		cq->mcq.comp = mlx4_en_rx_irq;
		netif_napi_add(cq->dev, &cq->napi, mlx4_en_poll_rx_cq, 64);
		napi_enable(&cq->napi);
		break;
	case TX_XDP:
		/* nothing regarding napi, it's shared with rx ring */
		cq->xdp_busy = false;
		break;
	}

	return 0;

free_eq:
	if (assigned_eq)
		mlx4_release_eq(mdev->dev, cq->vector);
	cq->vector = mdev->dev->caps.num_comp_vectors;
	return err;
}

void mlx4_en_destroy_cq(struct mlx4_en_priv *priv, struct mlx4_en_cq **pcq)
{
	struct mlx4_en_dev *mdev = priv->mdev;
	struct mlx4_en_cq *cq = *pcq;

	mlx4_free_hwq_res(mdev->dev, &cq->wqres, cq->buf_size);
	if (mlx4_is_eq_vector_valid(mdev->dev, priv->port, cq->vector) &&
	    cq->type == RX)
		mlx4_release_eq(priv->mdev->dev, cq->vector);
	cq->vector = 0;
	cq->buf_size = 0;
	cq->buf = NULL;
	kfree(cq);
	*pcq = NULL;
}

void mlx4_en_deactivate_cq(struct mlx4_en_priv *priv, struct mlx4_en_cq *cq)
{
	if (cq->type != TX_XDP) {
		napi_disable(&cq->napi);
		netif_napi_del(&cq->napi);
	}

	mlx4_cq_free(priv->mdev->dev, &cq->mcq);
}

int mlx4_en_set_cq_moder(struct mlx4_en_priv *priv, struct mlx4_en_cq *cq)
{
	return mlx4_cq_modify(priv->mdev->dev, &cq->mcq,
			      cq->moder_cnt, cq->moder_time);
}

void mlx4_en_arm_cq(struct mlx4_en_priv *priv, struct mlx4_en_cq *cq)
{
	mlx4_cq_arm(&cq->mcq, MLX4_CQ_DB_REQ_NOT, priv->mdev->uar_map,
		    &priv->mdev->uar_lock);
}

