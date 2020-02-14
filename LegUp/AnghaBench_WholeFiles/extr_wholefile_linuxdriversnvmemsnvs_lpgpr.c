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
struct nvmem_config {int stride; int word_size; int (* reg_read ) (void*,unsigned int,void*,size_t) ;int (* reg_write ) (void*,unsigned int,void*,size_t) ;int /*<<< orphan*/  owner; int /*<<< orphan*/  size; struct device* dev; int /*<<< orphan*/  name; struct snvs_lpgpr_priv* priv; } ;
struct snvs_lpgpr_priv {struct nvmem_config cfg; struct snvs_lpgpr_cfg const* dcfg; int /*<<< orphan*/  regmap; } ;
typedef  struct snvs_lpgpr_cfg {int /*<<< orphan*/  size; scalar_t__ offset; int /*<<< orphan*/  offset_lplr; int /*<<< orphan*/  offset_hplr; } const snvs_lpgpr_cfg ;
struct device {struct device_node* of_node; } ;
struct platform_device {struct device dev; } ;
struct nvmem_device {int dummy; } ;
struct device_node {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int EPERM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 unsigned int IMX_GPR_HL ; 
 unsigned int IMX_GPR_SL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int PTR_ERR_OR_ZERO (struct nvmem_device*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 struct snvs_lpgpr_priv* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 struct nvmem_device* devm_nvmem_register (struct device*,struct nvmem_config*) ; 
 struct snvs_lpgpr_cfg const* of_device_get_match_data (struct device*) ; 
 struct device_node* of_get_parent (struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,scalar_t__,void*,size_t) ; 
 int regmap_bulk_write (int /*<<< orphan*/ ,scalar_t__,void*,size_t) ; 
 int regmap_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned int*) ; 
 int /*<<< orphan*/  syscon_node_to_regmap (struct device_node*) ; 

__attribute__((used)) static int snvs_lpgpr_write(void *context, unsigned int offset, void *val,
			    size_t bytes)
{
	struct snvs_lpgpr_priv *priv = context;
	const struct snvs_lpgpr_cfg *dcfg = priv->dcfg;
	unsigned int lock_reg;
	int ret;

	ret = regmap_read(priv->regmap, dcfg->offset_hplr, &lock_reg);
	if (ret < 0)
		return ret;

	if (lock_reg & IMX_GPR_SL)
		return -EPERM;

	ret = regmap_read(priv->regmap, dcfg->offset_lplr, &lock_reg);
	if (ret < 0)
		return ret;

	if (lock_reg & IMX_GPR_HL)
		return -EPERM;

	return regmap_bulk_write(priv->regmap, dcfg->offset + offset, val,
				bytes / 4);
}

__attribute__((used)) static int snvs_lpgpr_read(void *context, unsigned int offset, void *val,
			   size_t bytes)
{
	struct snvs_lpgpr_priv *priv = context;
	const struct snvs_lpgpr_cfg *dcfg = priv->dcfg;

	return regmap_bulk_read(priv->regmap, dcfg->offset + offset,
			       val, bytes / 4);
}

__attribute__((used)) static int snvs_lpgpr_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *node = dev->of_node;
	struct device_node *syscon_node;
	struct snvs_lpgpr_priv *priv;
	struct nvmem_config *cfg;
	struct nvmem_device *nvmem;
	const struct snvs_lpgpr_cfg *dcfg;

	if (!node)
		return -ENOENT;

	priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	dcfg = of_device_get_match_data(dev);
	if (!dcfg)
		return -EINVAL;

	syscon_node = of_get_parent(node);
	if (!syscon_node)
		return -ENODEV;

	priv->regmap = syscon_node_to_regmap(syscon_node);
	of_node_put(syscon_node);
	if (IS_ERR(priv->regmap))
		return PTR_ERR(priv->regmap);

	priv->dcfg = dcfg;

	cfg = &priv->cfg;
	cfg->priv = priv;
	cfg->name = dev_name(dev);
	cfg->dev = dev;
	cfg->stride = 4;
	cfg->word_size = 4;
	cfg->size = dcfg->size,
	cfg->owner = THIS_MODULE;
	cfg->reg_read  = snvs_lpgpr_read;
	cfg->reg_write = snvs_lpgpr_write;

	nvmem = devm_nvmem_register(dev, cfg);

	return PTR_ERR_OR_ZERO(nvmem);
}

