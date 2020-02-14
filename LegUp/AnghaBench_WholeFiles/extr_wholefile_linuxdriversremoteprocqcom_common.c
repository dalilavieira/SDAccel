#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  u32 ;
struct rproc_subdev {int dummy; } ;
struct device {TYPE_2__* parent; } ;
struct rproc {struct device dev; TYPE_1__* ops; } ;
struct resource_table {int dummy; } ;
struct qcom_sysmon {int dummy; } ;
struct TYPE_7__ {int (* start ) (struct rproc_subdev*) ;void (* stop ) (struct rproc_subdev*,int) ;} ;
struct qcom_rproc_subdev {void* node; TYPE_3__ subdev; struct device* dev; int /*<<< orphan*/ * edge; } ;
struct qcom_rproc_ssr {char const* name; TYPE_3__ subdev; } ;
struct qcom_rproc_glink {void* node; TYPE_3__ subdev; struct device* dev; int /*<<< orphan*/ * edge; } ;
struct notifier_block {int dummy; } ;
struct firmware {scalar_t__ data; } ;
struct elf32_phdr {scalar_t__ p_type; int p_flags; int /*<<< orphan*/  p_memsz; int /*<<< orphan*/  p_paddr; } ;
struct elf32_hdr {int e_phnum; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; } ;
struct TYPE_5__ {int (* sanity_check ) (struct rproc*,struct firmware const*) ;int (* load ) (struct rproc*,struct firmware const*) ;int (* parse_fw ) (struct rproc*,struct firmware const*) ;struct resource_table* (* find_loaded_rsc_table ) (struct rproc*,struct firmware const*) ;int /*<<< orphan*/  (* get_boot_addr ) (struct rproc*,struct firmware const*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int PTR_ERR_OR_ZERO (int /*<<< orphan*/ *) ; 
 scalar_t__ PT_LOAD ; 
 int QCOM_MDT_TYPE_HASH ; 
 int QCOM_MDT_TYPE_MASK ; 
 int /*<<< orphan*/  blocking_notifier_call_chain (int /*<<< orphan*/ *,int /*<<< orphan*/ ,void*) ; 
 int blocking_notifier_chain_register (int /*<<< orphan*/ *,struct notifier_block*) ; 
 int /*<<< orphan*/  blocking_notifier_chain_unregister (int /*<<< orphan*/ *,struct notifier_block*) ; 
 void* of_get_child_by_name (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  of_node_put (void*) ; 
 int /*<<< orphan*/ * qcom_glink_smem_register (struct device*,void*) ; 
 int /*<<< orphan*/  qcom_glink_smem_unregister (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * qcom_smd_register_edge (struct device*,void*) ; 
 int /*<<< orphan*/  qcom_smd_unregister_edge (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  rproc_add_subdev (struct rproc*,TYPE_3__*) ; 
 int rproc_coredump_add_segment (struct rproc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rproc_remove_subdev (struct rproc*,TYPE_3__*) ; 
 int /*<<< orphan*/  ssr_notifiers ; 
 int stub1 (struct rproc*,struct firmware const*) ; 
 int /*<<< orphan*/  stub2 (struct rproc*,struct firmware const*) ; 
 int stub3 (struct rproc*,struct firmware const*) ; 
 int stub4 (struct rproc*,struct firmware const*) ; 
 struct resource_table* stub5 (struct rproc*,struct firmware const*) ; 
 struct qcom_rproc_glink* to_glink_subdev (struct rproc_subdev*) ; 
 struct qcom_rproc_subdev* to_smd_subdev (struct rproc_subdev*) ; 
 struct qcom_rproc_ssr* to_ssr_subdev (struct rproc_subdev*) ; 

__attribute__((used)) static inline
int rproc_fw_sanity_check(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->sanity_check)
		return rproc->ops->sanity_check(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
u32 rproc_get_boot_addr(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->get_boot_addr)
		return rproc->ops->get_boot_addr(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
int rproc_load_segments(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->load)
		return rproc->ops->load(rproc, fw);

	return -EINVAL;
}

__attribute__((used)) static inline int rproc_parse_fw(struct rproc *rproc, const struct firmware *fw)
{
	if (rproc->ops->parse_fw)
		return rproc->ops->parse_fw(rproc, fw);

	return 0;
}

__attribute__((used)) static inline
struct resource_table *rproc_find_loaded_rsc_table(struct rproc *rproc,
						   const struct firmware *fw)
{
	if (rproc->ops->find_loaded_rsc_table)
		return rproc->ops->find_loaded_rsc_table(rproc, fw);

	return NULL;
}

__attribute__((used)) static inline struct qcom_sysmon *qcom_add_sysmon_subdev(struct rproc *rproc,
							 const char *name,
							 int ssctl_instance)
{
	return NULL;
}

__attribute__((used)) static inline void qcom_remove_sysmon_subdev(struct qcom_sysmon *sysmon)
{
}

__attribute__((used)) static int glink_subdev_start(struct rproc_subdev *subdev)
{
	struct qcom_rproc_glink *glink = to_glink_subdev(subdev);

	glink->edge = qcom_glink_smem_register(glink->dev, glink->node);

	return PTR_ERR_OR_ZERO(glink->edge);
}

__attribute__((used)) static void glink_subdev_stop(struct rproc_subdev *subdev, bool crashed)
{
	struct qcom_rproc_glink *glink = to_glink_subdev(subdev);

	qcom_glink_smem_unregister(glink->edge);
	glink->edge = NULL;
}

void qcom_add_glink_subdev(struct rproc *rproc, struct qcom_rproc_glink *glink)
{
	struct device *dev = &rproc->dev;

	glink->node = of_get_child_by_name(dev->parent->of_node, "glink-edge");
	if (!glink->node)
		return;

	glink->dev = dev;
	glink->subdev.start = glink_subdev_start;
	glink->subdev.stop = glink_subdev_stop;

	rproc_add_subdev(rproc, &glink->subdev);
}

void qcom_remove_glink_subdev(struct rproc *rproc, struct qcom_rproc_glink *glink)
{
	if (!glink->node)
		return;

	rproc_remove_subdev(rproc, &glink->subdev);
	of_node_put(glink->node);
}

int qcom_register_dump_segments(struct rproc *rproc,
				const struct firmware *fw)
{
	const struct elf32_phdr *phdrs;
	const struct elf32_phdr *phdr;
	const struct elf32_hdr *ehdr;
	int ret;
	int i;

	ehdr = (struct elf32_hdr *)fw->data;
	phdrs = (struct elf32_phdr *)(ehdr + 1);

	for (i = 0; i < ehdr->e_phnum; i++) {
		phdr = &phdrs[i];

		if (phdr->p_type != PT_LOAD)
			continue;

		if ((phdr->p_flags & QCOM_MDT_TYPE_MASK) == QCOM_MDT_TYPE_HASH)
			continue;

		if (!phdr->p_memsz)
			continue;

		ret = rproc_coredump_add_segment(rproc, phdr->p_paddr,
						 phdr->p_memsz);
		if (ret)
			return ret;
	}

	return 0;
}

__attribute__((used)) static int smd_subdev_start(struct rproc_subdev *subdev)
{
	struct qcom_rproc_subdev *smd = to_smd_subdev(subdev);

	smd->edge = qcom_smd_register_edge(smd->dev, smd->node);

	return PTR_ERR_OR_ZERO(smd->edge);
}

__attribute__((used)) static void smd_subdev_stop(struct rproc_subdev *subdev, bool crashed)
{
	struct qcom_rproc_subdev *smd = to_smd_subdev(subdev);

	qcom_smd_unregister_edge(smd->edge);
	smd->edge = NULL;
}

void qcom_add_smd_subdev(struct rproc *rproc, struct qcom_rproc_subdev *smd)
{
	struct device *dev = &rproc->dev;

	smd->node = of_get_child_by_name(dev->parent->of_node, "smd-edge");
	if (!smd->node)
		return;

	smd->dev = dev;
	smd->subdev.start = smd_subdev_start;
	smd->subdev.stop = smd_subdev_stop;

	rproc_add_subdev(rproc, &smd->subdev);
}

void qcom_remove_smd_subdev(struct rproc *rproc, struct qcom_rproc_subdev *smd)
{
	if (!smd->node)
		return;

	rproc_remove_subdev(rproc, &smd->subdev);
	of_node_put(smd->node);
}

int qcom_register_ssr_notifier(struct notifier_block *nb)
{
	return blocking_notifier_chain_register(&ssr_notifiers, nb);
}

void qcom_unregister_ssr_notifier(struct notifier_block *nb)
{
	blocking_notifier_chain_unregister(&ssr_notifiers, nb);
}

__attribute__((used)) static void ssr_notify_stop(struct rproc_subdev *subdev, bool crashed)
{
	struct qcom_rproc_ssr *ssr = to_ssr_subdev(subdev);

	blocking_notifier_call_chain(&ssr_notifiers, 0, (void *)ssr->name);
}

void qcom_add_ssr_subdev(struct rproc *rproc, struct qcom_rproc_ssr *ssr,
			 const char *ssr_name)
{
	ssr->name = ssr_name;
	ssr->subdev.stop = ssr_notify_stop;

	rproc_add_subdev(rproc, &ssr->subdev);
}

void qcom_remove_ssr_subdev(struct rproc *rproc, struct qcom_rproc_ssr *ssr)
{
	rproc_remove_subdev(rproc, &ssr->subdev);
}

