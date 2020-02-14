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
typedef  unsigned int u32 ;
struct resource {int dummy; } ;
struct TYPE_2__ {int reg_size; unsigned int idle; int n_values; int base_nr; unsigned int* classes; int /*<<< orphan*/ * values; scalar_t__ idle_in_use; scalar_t__ reg; int /*<<< orphan*/  parent; int /*<<< orphan*/  write_only; int /*<<< orphan*/  little_endian; } ;
struct regmux {TYPE_1__ data; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct i2c_mux_core {int (* deselect ) (struct i2c_mux_core*,unsigned int) ;struct i2c_adapter* parent; struct regmux* priv; } ;
struct i2c_adapter {int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int EPROBE_DEFER ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 scalar_t__ IS_ERR (scalar_t__) ; 
 int PTR_ERR (scalar_t__) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ dev_get_platdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ *,char*) ; 
 scalar_t__ devm_ioremap_resource (int /*<<< orphan*/ *,struct resource*) ; 
 struct regmux* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct i2c_adapter* i2c_get_adapter (int /*<<< orphan*/ ) ; 
 int i2c_mux_add_adapter (struct i2c_mux_core*,int,int /*<<< orphan*/ ,unsigned int) ; 
 struct i2c_mux_core* i2c_mux_alloc (struct i2c_adapter*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int (*) (struct i2c_mux_core*,unsigned int),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_mux_del_adapters (struct i2c_mux_core*) ; 
 struct regmux* i2c_mux_priv (struct i2c_mux_core*) ; 
 int /*<<< orphan*/  i2c_put_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  ioread16 (scalar_t__) ; 
 int /*<<< orphan*/  ioread32 (scalar_t__) ; 
 int /*<<< orphan*/  ioread8 (scalar_t__) ; 
 int /*<<< orphan*/  iowrite16 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite16be (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite32 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite32be (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  iowrite8 (unsigned int,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (TYPE_1__*,scalar_t__,int) ; 
 struct i2c_mux_core* platform_get_drvdata (struct platform_device*) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct i2c_mux_core*) ; 
 int resource_size (struct resource*) ; 

__attribute__((used)) static int i2c_mux_reg_set(const struct regmux *mux, unsigned int chan_id)
{
	if (!mux->data.reg)
		return -EINVAL;

	/*
	 * Write to the register, followed by a read to ensure the write is
	 * completed on a "posted" bus, for example PCI or write buffers.
	 * The endianness of reading doesn't matter and the return data
	 * is not used.
	 */
	switch (mux->data.reg_size) {
	case 4:
		if (mux->data.little_endian)
			iowrite32(chan_id, mux->data.reg);
		else
			iowrite32be(chan_id, mux->data.reg);
		if (!mux->data.write_only)
			ioread32(mux->data.reg);
		break;
	case 2:
		if (mux->data.little_endian)
			iowrite16(chan_id, mux->data.reg);
		else
			iowrite16be(chan_id, mux->data.reg);
		if (!mux->data.write_only)
			ioread16(mux->data.reg);
		break;
	case 1:
		iowrite8(chan_id, mux->data.reg);
		if (!mux->data.write_only)
			ioread8(mux->data.reg);
		break;
	}

	return 0;
}

__attribute__((used)) static int i2c_mux_reg_select(struct i2c_mux_core *muxc, u32 chan)
{
	struct regmux *mux = i2c_mux_priv(muxc);

	return i2c_mux_reg_set(mux, chan);
}

__attribute__((used)) static int i2c_mux_reg_deselect(struct i2c_mux_core *muxc, u32 chan)
{
	struct regmux *mux = i2c_mux_priv(muxc);

	if (mux->data.idle_in_use)
		return i2c_mux_reg_set(mux, mux->data.idle);

	return 0;
}

__attribute__((used)) static int i2c_mux_reg_probe_dt(struct regmux *mux,
				struct platform_device *pdev)
{
	return 0;
}

__attribute__((used)) static int i2c_mux_reg_probe(struct platform_device *pdev)
{
	struct i2c_mux_core *muxc;
	struct regmux *mux;
	struct i2c_adapter *parent;
	struct resource *res;
	unsigned int class;
	int i, ret, nr;

	mux = devm_kzalloc(&pdev->dev, sizeof(*mux), GFP_KERNEL);
	if (!mux)
		return -ENOMEM;

	if (dev_get_platdata(&pdev->dev)) {
		memcpy(&mux->data, dev_get_platdata(&pdev->dev),
			sizeof(mux->data));
	} else {
		ret = i2c_mux_reg_probe_dt(mux, pdev);
		if (ret == -EPROBE_DEFER)
			return ret;

		if (ret < 0) {
			dev_err(&pdev->dev, "Error parsing device tree");
			return ret;
		}
	}

	parent = i2c_get_adapter(mux->data.parent);
	if (!parent)
		return -EPROBE_DEFER;

	if (!mux->data.reg) {
		dev_info(&pdev->dev,
			"Register not set, using platform resource\n");
		res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
		mux->data.reg_size = resource_size(res);
		mux->data.reg = devm_ioremap_resource(&pdev->dev, res);
		if (IS_ERR(mux->data.reg)) {
			ret = PTR_ERR(mux->data.reg);
			goto err_put_parent;
		}
	}

	if (mux->data.reg_size != 4 && mux->data.reg_size != 2 &&
	    mux->data.reg_size != 1) {
		dev_err(&pdev->dev, "Invalid register size\n");
		ret = -EINVAL;
		goto err_put_parent;
	}

	muxc = i2c_mux_alloc(parent, &pdev->dev, mux->data.n_values, 0, 0,
			     i2c_mux_reg_select, NULL);
	if (!muxc) {
		ret = -ENOMEM;
		goto err_put_parent;
	}
	muxc->priv = mux;

	platform_set_drvdata(pdev, muxc);

	if (mux->data.idle_in_use)
		muxc->deselect = i2c_mux_reg_deselect;

	for (i = 0; i < mux->data.n_values; i++) {
		nr = mux->data.base_nr ? (mux->data.base_nr + i) : 0;
		class = mux->data.classes ? mux->data.classes[i] : 0;

		ret = i2c_mux_add_adapter(muxc, nr, mux->data.values[i], class);
		if (ret)
			goto err_del_mux_adapters;
	}

	dev_dbg(&pdev->dev, "%d port mux on %s adapter\n",
		 mux->data.n_values, muxc->parent->name);

	return 0;

err_del_mux_adapters:
	i2c_mux_del_adapters(muxc);
err_put_parent:
	i2c_put_adapter(parent);

	return ret;
}

__attribute__((used)) static int i2c_mux_reg_remove(struct platform_device *pdev)
{
	struct i2c_mux_core *muxc = platform_get_drvdata(pdev);

	i2c_mux_del_adapters(muxc);
	i2c_put_adapter(muxc->parent);

	return 0;
}

