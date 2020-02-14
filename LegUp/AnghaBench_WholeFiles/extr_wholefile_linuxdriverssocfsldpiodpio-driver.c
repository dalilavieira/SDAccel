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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  u64 ;
typedef  int u32 ;
typedef  int /*<<< orphan*/  u16 ;
struct qbman_swp {int dummy; } ;
struct fsl_mc_device_irq {TYPE_1__* msi_desc; } ;
struct TYPE_7__ {int /*<<< orphan*/  id; } ;
struct device {int dummy; } ;
struct fsl_mc_device {int /*<<< orphan*/  mc_io; int /*<<< orphan*/  mc_handle; TYPE_2__ obj_desc; struct device dev; TYPE_5__* regions; struct fsl_mc_device_irq** irqs; } ;
struct dpio_priv {int /*<<< orphan*/  io; } ;
struct dpio_attr {int num_priorities; int /*<<< orphan*/  qbman_version; } ;
struct dpaa2_io_desc {int receives_notifications; int has_8prio; int cpu; int /*<<< orphan*/  regs_cinh; int /*<<< orphan*/  regs_cena; int /*<<< orphan*/  dpio_id; int /*<<< orphan*/  qman_version; } ;
struct TYPE_9__ {int /*<<< orphan*/  ctx; int /*<<< orphan*/  rid_tok; int /*<<< orphan*/  state; } ;
struct TYPE_8__ {int verb; } ;
struct dpaa2_dq {TYPE_4__ scn; TYPE_3__ dq; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  int /*<<< orphan*/  cpumask_t ;
struct TYPE_10__ {int /*<<< orphan*/  start; } ;
struct TYPE_6__ {int /*<<< orphan*/  irq; } ;

/* Variables and functions */
 int CODE_CDAN_WE_CTX ; 
 int CODE_CDAN_WE_EN ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int ERANGE ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MEMREMAP_WC ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  QBMAN_FQ_FORCE ; 
 int /*<<< orphan*/  QBMAN_FQ_SCHEDULE ; 
 int /*<<< orphan*/  QBMAN_FQ_XOFF ; 
 int /*<<< orphan*/  QBMAN_FQ_XON ; 
 int QBMAN_RESULT_BPSCN ; 
 int QBMAN_RESULT_CDAN ; 
 int QBMAN_RESULT_CGCU ; 
 int QBMAN_RESULT_CSCN_WQ ; 
 int QBMAN_RESULT_DQ ; 
 int QBMAN_RESULT_FQDAN ; 
 int QBMAN_RESULT_FQPN ; 
 int QBMAN_RESULT_FQRN ; 
 int QBMAN_RESULT_FQRNI ; 
 int QBMAN_RESULT_MASK ; 
 int SCN_RID_MASK ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  cpu_online_mask ; 
 int /*<<< orphan*/  cpu_possible (int) ; 
 int /*<<< orphan*/  cpumask_clear (int /*<<< orphan*/ *) ; 
 int cpumask_first (int /*<<< orphan*/ ) ; 
 int cpumask_next (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpumask_set_cpu (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct dpio_priv* dev_get_drvdata (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  dev_set_drvdata (struct device*,struct dpio_priv*) ; 
 int /*<<< orphan*/  devm_ioremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct dpio_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_memremap (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int devm_request_irq (struct device*,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct device*) ; 
 int /*<<< orphan*/  dpaa2_dpio_driver ; 
 int /*<<< orphan*/  dpaa2_io_create (struct dpaa2_io_desc*) ; 
 int /*<<< orphan*/  dpaa2_io_down (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpaa2_io_irq (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpio_close (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dpio_disable (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dpio_enable (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int dpio_get_attributes (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct dpio_attr*) ; 
 int dpio_open (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int fsl_mc_allocate_irqs (struct fsl_mc_device*) ; 
 int fsl_mc_driver_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fsl_mc_driver_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fsl_mc_free_irqs (struct fsl_mc_device*) ; 
 int fsl_mc_portal_allocate (struct fsl_mc_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fsl_mc_portal_free (int /*<<< orphan*/ ) ; 
 scalar_t__ irq_set_affinity_hint (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le64_to_cpu (int /*<<< orphan*/ ) ; 
 int qbman_swp_CDAN_set (struct qbman_swp*,int /*<<< orphan*/ ,int,int,int /*<<< orphan*/ ) ; 
 int qbman_swp_alt_fq_state (struct qbman_swp*,int,int /*<<< orphan*/ ) ; 
 void* qbman_swp_mc_result (struct qbman_swp*) ; 
 int /*<<< orphan*/  qbman_swp_mc_submit (struct qbman_swp*,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  resource_size (TYPE_5__*) ; 

__attribute__((used)) static inline int qbman_result_is_DQ(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_DQ);
}

__attribute__((used)) static inline int qbman_result_is_SCN(const struct dpaa2_dq *dq)
{
	return !qbman_result_is_DQ(dq);
}

__attribute__((used)) static inline int qbman_result_is_FQDAN(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_FQDAN);
}

__attribute__((used)) static inline int qbman_result_is_CDAN(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_CDAN);
}

__attribute__((used)) static inline int qbman_result_is_CSCN(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_CSCN_WQ);
}

__attribute__((used)) static inline int qbman_result_is_BPSCN(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_BPSCN);
}

__attribute__((used)) static inline int qbman_result_is_CGCU(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_CGCU);
}

__attribute__((used)) static inline int qbman_result_is_FQRN(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_FQRN);
}

__attribute__((used)) static inline int qbman_result_is_FQRNI(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_FQRNI);
}

__attribute__((used)) static inline int qbman_result_is_FQPN(const struct dpaa2_dq *dq)
{
	return ((dq->dq.verb & QBMAN_RESULT_MASK) == QBMAN_RESULT_FQPN);
}

__attribute__((used)) static inline u8 qbman_result_SCN_state(const struct dpaa2_dq *scn)
{
	return scn->scn.state;
}

__attribute__((used)) static inline u32 qbman_result_SCN_rid(const struct dpaa2_dq *scn)
{
	return le32_to_cpu(scn->scn.rid_tok) & SCN_RID_MASK;
}

__attribute__((used)) static inline u64 qbman_result_SCN_ctx(const struct dpaa2_dq *scn)
{
	return le64_to_cpu(scn->scn.ctx);
}

__attribute__((used)) static inline int qbman_swp_fq_schedule(struct qbman_swp *s, u32 fqid)
{
	return qbman_swp_alt_fq_state(s, fqid, QBMAN_FQ_SCHEDULE);
}

__attribute__((used)) static inline int qbman_swp_fq_force(struct qbman_swp *s, u32 fqid)
{
	return qbman_swp_alt_fq_state(s, fqid, QBMAN_FQ_FORCE);
}

__attribute__((used)) static inline int qbman_swp_fq_xon(struct qbman_swp *s, u32 fqid)
{
	return qbman_swp_alt_fq_state(s, fqid, QBMAN_FQ_XON);
}

__attribute__((used)) static inline int qbman_swp_fq_xoff(struct qbman_swp *s, u32 fqid)
{
	return qbman_swp_alt_fq_state(s, fqid, QBMAN_FQ_XOFF);
}

__attribute__((used)) static inline int qbman_swp_CDAN_set_context(struct qbman_swp *s, u16 channelid,
					     u64 ctx)
{
	return qbman_swp_CDAN_set(s, channelid,
				  CODE_CDAN_WE_CTX,
				  0, ctx);
}

__attribute__((used)) static inline int qbman_swp_CDAN_enable(struct qbman_swp *s, u16 channelid)
{
	return qbman_swp_CDAN_set(s, channelid,
				  CODE_CDAN_WE_EN,
				  1, 0);
}

__attribute__((used)) static inline int qbman_swp_CDAN_disable(struct qbman_swp *s, u16 channelid)
{
	return qbman_swp_CDAN_set(s, channelid,
				  CODE_CDAN_WE_EN,
				  0, 0);
}

__attribute__((used)) static inline int qbman_swp_CDAN_set_context_enable(struct qbman_swp *s,
						    u16 channelid,
						    u64 ctx)
{
	return qbman_swp_CDAN_set(s, channelid,
				  CODE_CDAN_WE_EN | CODE_CDAN_WE_CTX,
				  1, ctx);
}

__attribute__((used)) static inline void *qbman_swp_mc_complete(struct qbman_swp *swp, void *cmd,
					  u8 cmd_verb)
{
	int loopvar = 1000;

	qbman_swp_mc_submit(swp, cmd, cmd_verb);

	do {
		cmd = qbman_swp_mc_result(swp);
	} while (!cmd && loopvar--);

	WARN_ON(!loopvar);

	return cmd;
}

__attribute__((used)) static irqreturn_t dpio_irq_handler(int irq_num, void *arg)
{
	struct device *dev = (struct device *)arg;
	struct dpio_priv *priv = dev_get_drvdata(dev);

	return dpaa2_io_irq(priv->io);
}

__attribute__((used)) static void unregister_dpio_irq_handlers(struct fsl_mc_device *dpio_dev)
{
	struct fsl_mc_device_irq *irq;

	irq = dpio_dev->irqs[0];

	/* clear the affinity hint */
	irq_set_affinity_hint(irq->msi_desc->irq, NULL);
}

__attribute__((used)) static int register_dpio_irq_handlers(struct fsl_mc_device *dpio_dev, int cpu)
{
	struct dpio_priv *priv;
	int error;
	struct fsl_mc_device_irq *irq;
	cpumask_t mask;

	priv = dev_get_drvdata(&dpio_dev->dev);

	irq = dpio_dev->irqs[0];
	error = devm_request_irq(&dpio_dev->dev,
				 irq->msi_desc->irq,
				 dpio_irq_handler,
				 0,
				 dev_name(&dpio_dev->dev),
				 &dpio_dev->dev);
	if (error < 0) {
		dev_err(&dpio_dev->dev,
			"devm_request_irq() failed: %d\n",
			error);
		return error;
	}

	/* set the affinity hint */
	cpumask_clear(&mask);
	cpumask_set_cpu(cpu, &mask);
	if (irq_set_affinity_hint(irq->msi_desc->irq, &mask))
		dev_err(&dpio_dev->dev,
			"irq_set_affinity failed irq %d cpu %d\n",
			irq->msi_desc->irq, cpu);

	return 0;
}

__attribute__((used)) static int dpaa2_dpio_probe(struct fsl_mc_device *dpio_dev)
{
	struct dpio_attr dpio_attrs;
	struct dpaa2_io_desc desc;
	struct dpio_priv *priv;
	int err = -ENOMEM;
	struct device *dev = &dpio_dev->dev;
	static int next_cpu = -1;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		goto err_priv_alloc;

	dev_set_drvdata(dev, priv);

	err = fsl_mc_portal_allocate(dpio_dev, 0, &dpio_dev->mc_io);
	if (err) {
		dev_dbg(dev, "MC portal allocation failed\n");
		err = -EPROBE_DEFER;
		goto err_priv_alloc;
	}

	err = dpio_open(dpio_dev->mc_io, 0, dpio_dev->obj_desc.id,
			&dpio_dev->mc_handle);
	if (err) {
		dev_err(dev, "dpio_open() failed\n");
		goto err_open;
	}

	err = dpio_get_attributes(dpio_dev->mc_io, 0, dpio_dev->mc_handle,
				  &dpio_attrs);
	if (err) {
		dev_err(dev, "dpio_get_attributes() failed %d\n", err);
		goto err_get_attr;
	}
	desc.qman_version = dpio_attrs.qbman_version;

	err = dpio_enable(dpio_dev->mc_io, 0, dpio_dev->mc_handle);
	if (err) {
		dev_err(dev, "dpio_enable() failed %d\n", err);
		goto err_get_attr;
	}

	/* initialize DPIO descriptor */
	desc.receives_notifications = dpio_attrs.num_priorities ? 1 : 0;
	desc.has_8prio = dpio_attrs.num_priorities == 8 ? 1 : 0;
	desc.dpio_id = dpio_dev->obj_desc.id;

	/* get the cpu to use for the affinity hint */
	if (next_cpu == -1)
		next_cpu = cpumask_first(cpu_online_mask);
	else
		next_cpu = cpumask_next(next_cpu, cpu_online_mask);

	if (!cpu_possible(next_cpu)) {
		dev_err(dev, "probe failed. Number of DPIOs exceeds NR_CPUS.\n");
		err = -ERANGE;
		goto err_allocate_irqs;
	}
	desc.cpu = next_cpu;

	/*
	 * Set the CENA regs to be the cache inhibited area of the portal to
	 * avoid coherency issues if a user migrates to another core.
	 */
	desc.regs_cena = devm_memremap(dev, dpio_dev->regions[1].start,
				       resource_size(&dpio_dev->regions[1]),
				       MEMREMAP_WC);
	if (IS_ERR(desc.regs_cena)) {
		dev_err(dev, "devm_memremap failed\n");
		err = PTR_ERR(desc.regs_cena);
		goto err_allocate_irqs;
	}

	desc.regs_cinh = devm_ioremap(dev, dpio_dev->regions[1].start,
				      resource_size(&dpio_dev->regions[1]));
	if (!desc.regs_cinh) {
		err = -ENOMEM;
		dev_err(dev, "devm_ioremap failed\n");
		goto err_allocate_irqs;
	}

	err = fsl_mc_allocate_irqs(dpio_dev);
	if (err) {
		dev_err(dev, "fsl_mc_allocate_irqs failed. err=%d\n", err);
		goto err_allocate_irqs;
	}

	err = register_dpio_irq_handlers(dpio_dev, desc.cpu);
	if (err)
		goto err_register_dpio_irq;

	priv->io = dpaa2_io_create(&desc);
	if (!priv->io) {
		dev_err(dev, "dpaa2_io_create failed\n");
		err = -ENOMEM;
		goto err_dpaa2_io_create;
	}

	dev_info(dev, "probed\n");
	dev_dbg(dev, "   receives_notifications = %d\n",
		desc.receives_notifications);
	dpio_close(dpio_dev->mc_io, 0, dpio_dev->mc_handle);
	fsl_mc_portal_free(dpio_dev->mc_io);

	return 0;

err_dpaa2_io_create:
	unregister_dpio_irq_handlers(dpio_dev);
err_register_dpio_irq:
	fsl_mc_free_irqs(dpio_dev);
err_allocate_irqs:
	dpio_disable(dpio_dev->mc_io, 0, dpio_dev->mc_handle);
err_get_attr:
	dpio_close(dpio_dev->mc_io, 0, dpio_dev->mc_handle);
err_open:
	fsl_mc_portal_free(dpio_dev->mc_io);
err_priv_alloc:
	return err;
}

__attribute__((used)) static void dpio_teardown_irqs(struct fsl_mc_device *dpio_dev)
{
	unregister_dpio_irq_handlers(dpio_dev);
	fsl_mc_free_irqs(dpio_dev);
}

__attribute__((used)) static int dpaa2_dpio_remove(struct fsl_mc_device *dpio_dev)
{
	struct device *dev;
	struct dpio_priv *priv;
	int err;

	dev = &dpio_dev->dev;
	priv = dev_get_drvdata(dev);

	dpaa2_io_down(priv->io);

	dpio_teardown_irqs(dpio_dev);

	err = fsl_mc_portal_allocate(dpio_dev, 0, &dpio_dev->mc_io);
	if (err) {
		dev_err(dev, "MC portal allocation failed\n");
		goto err_mcportal;
	}

	err = dpio_open(dpio_dev->mc_io, 0, dpio_dev->obj_desc.id,
			&dpio_dev->mc_handle);
	if (err) {
		dev_err(dev, "dpio_open() failed\n");
		goto err_open;
	}

	dpio_disable(dpio_dev->mc_io, 0, dpio_dev->mc_handle);

	dpio_close(dpio_dev->mc_io, 0, dpio_dev->mc_handle);

	fsl_mc_portal_free(dpio_dev->mc_io);

	return 0;

err_open:
	fsl_mc_portal_free(dpio_dev->mc_io);
err_mcportal:
	return err;
}

__attribute__((used)) static int dpio_driver_init(void)
{
	return fsl_mc_driver_register(&dpaa2_dpio_driver);
}

__attribute__((used)) static void dpio_driver_exit(void)
{
	fsl_mc_driver_unregister(&dpaa2_dpio_driver);
}

