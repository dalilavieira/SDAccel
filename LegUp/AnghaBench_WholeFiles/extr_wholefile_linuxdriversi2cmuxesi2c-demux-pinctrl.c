#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct property {int length; void* value; void* name; } ;
struct TYPE_20__ {struct device_node* of_node; } ;
struct platform_device {TYPE_6__ dev; } ;
struct pinctrl_state {int dummy; } ;
typedef  struct pinctrl_state pinctrl ;
struct i2c_msg {int dummy; } ;
struct TYPE_16__ {struct device_node* of_node; TYPE_5__* parent; } ;
struct TYPE_21__ {TYPE_2__ dev; int /*<<< orphan*/  quirks; int /*<<< orphan*/  timeout; int /*<<< orphan*/  retries; int /*<<< orphan*/  class; struct i2c_demux_pinctrl_priv* algo_data; TYPE_1__* algo; int /*<<< orphan*/  owner; int /*<<< orphan*/  name; } ;
struct TYPE_15__ {int (* master_xfer ) (struct i2c_adapter*,struct i2c_msg*,int) ;size_t (* functionality ) (struct i2c_adapter*) ;} ;
struct i2c_demux_pinctrl_priv {size_t cur_chan; int num_chan; TYPE_4__* chan; TYPE_6__* dev; int /*<<< orphan*/  bus_name; TYPE_7__ cur_adap; TYPE_1__ algo; } ;
struct i2c_demux_pinctrl_chan {int dummy; } ;
struct TYPE_19__ {int /*<<< orphan*/  parent; } ;
struct i2c_adapter {int /*<<< orphan*/  quirks; int /*<<< orphan*/  timeout; int /*<<< orphan*/  retries; int /*<<< orphan*/  class; TYPE_5__ dev; TYPE_3__* algo; struct i2c_demux_pinctrl_priv* algo_data; } ;
struct device_node {int dummy; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
struct TYPE_18__ {int /*<<< orphan*/  chgset; struct device_node* parent_np; struct i2c_adapter* parent_adap; } ;
struct TYPE_17__ {size_t (* functionality ) (struct i2c_adapter*) ;} ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct pinctrl_state*) ; 
 int PAGE_SIZE ; 
 int PTR_ERR (struct pinctrl_state*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int __i2c_transfer (struct i2c_adapter*,struct i2c_msg*,int) ; 
 int /*<<< orphan*/  dev_attr_available_masters ; 
 int /*<<< orphan*/  dev_attr_current_master ; 
 int /*<<< orphan*/  dev_err (TYPE_6__*,char*,...) ; 
 struct i2c_demux_pinctrl_priv* dev_get_drvdata (struct device*) ; 
 int device_create_file (TYPE_6__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  device_remove_file (TYPE_6__*,int /*<<< orphan*/ *) ; 
 struct property* devm_kcalloc (TYPE_6__*,int,int,int /*<<< orphan*/ ) ; 
 void* devm_kstrdup (TYPE_6__*,char*,int /*<<< orphan*/ ) ; 
 struct i2c_demux_pinctrl_priv* devm_kzalloc (TYPE_6__*,int,int /*<<< orphan*/ ) ; 
 struct pinctrl_state* devm_pinctrl_get (int /*<<< orphan*/ ) ; 
 int i2c_adapter_id (struct i2c_adapter*) ; 
 int i2c_add_adapter (TYPE_7__*) ; 
 int /*<<< orphan*/  i2c_del_adapter (TYPE_7__*) ; 
 int /*<<< orphan*/  i2c_put_adapter (struct i2c_adapter*) ; 
 int kstrtouint (char const*,int /*<<< orphan*/ ,unsigned int*) ; 
 int of_changeset_apply (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_changeset_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_changeset_init (int /*<<< orphan*/ *) ; 
 int of_changeset_revert (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  of_changeset_update_property (int /*<<< orphan*/ *,struct device_node*,struct property*) ; 
 int of_count_phandle_with_args (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct i2c_adapter* of_find_i2c_adapter_by_node (struct device_node*) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 struct device_node* of_parse_phandle (struct device_node*,char*,int) ; 
 int of_property_read_string (struct device_node*,char*,int /*<<< orphan*/ *) ; 
 struct pinctrl_state* pinctrl_lookup_state (struct pinctrl_state*,int /*<<< orphan*/ ) ; 
 int pinctrl_select_state (struct pinctrl_state*,struct pinctrl_state*) ; 
 struct i2c_demux_pinctrl_priv* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct i2c_demux_pinctrl_priv*) ; 
 int /*<<< orphan*/  pm_runtime_no_callbacks (TYPE_6__*) ; 
 scalar_t__ scnprintf (char*,int,char*,int,struct device_node*,char) ; 
 int /*<<< orphan*/  snprintf (int /*<<< orphan*/ ,int,char*,int) ; 
 int sprintf (char*,char*,size_t) ; 
 size_t stub1 (struct i2c_adapter*) ; 

__attribute__((used)) static int i2c_demux_master_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
	struct i2c_demux_pinctrl_priv *priv = adap->algo_data;
	struct i2c_adapter *parent = priv->chan[priv->cur_chan].parent_adap;

	return __i2c_transfer(parent, msgs, num);
}

__attribute__((used)) static u32 i2c_demux_functionality(struct i2c_adapter *adap)
{
	struct i2c_demux_pinctrl_priv *priv = adap->algo_data;
	struct i2c_adapter *parent = priv->chan[priv->cur_chan].parent_adap;

	return parent->algo->functionality(parent);
}

__attribute__((used)) static int i2c_demux_activate_master(struct i2c_demux_pinctrl_priv *priv, u32 new_chan)
{
	struct i2c_adapter *adap;
	struct pinctrl *p;
	int ret;

	ret = of_changeset_apply(&priv->chan[new_chan].chgset);
	if (ret)
		goto err;

	adap = of_find_i2c_adapter_by_node(priv->chan[new_chan].parent_np);
	if (!adap) {
		ret = -ENODEV;
		goto err_with_revert;
	}

	/*
	 * Check if there are pinctrl states at all. Note: we cant' use
	 * devm_pinctrl_get_select() because we need to distinguish between
	 * the -ENODEV from devm_pinctrl_get() and pinctrl_lookup_state().
	 */
	p = devm_pinctrl_get(adap->dev.parent);
	if (IS_ERR(p)) {
		ret = PTR_ERR(p);
		/* continue if just no pinctrl states (e.g. i2c-gpio), otherwise exit */
		if (ret != -ENODEV)
			goto err_with_put;
	} else {
		/* there are states. check and use them */
		struct pinctrl_state *s = pinctrl_lookup_state(p, priv->bus_name);

		if (IS_ERR(s)) {
			ret = PTR_ERR(s);
			goto err_with_put;
		}
		ret = pinctrl_select_state(p, s);
		if (ret < 0)
			goto err_with_put;
	}

	priv->chan[new_chan].parent_adap = adap;
	priv->cur_chan = new_chan;

	/* Now fill out current adapter structure. cur_chan must be up to date */
	priv->algo.master_xfer = i2c_demux_master_xfer;
	priv->algo.functionality = i2c_demux_functionality;

	snprintf(priv->cur_adap.name, sizeof(priv->cur_adap.name),
		 "i2c-demux (master i2c-%d)", i2c_adapter_id(adap));
	priv->cur_adap.owner = THIS_MODULE;
	priv->cur_adap.algo = &priv->algo;
	priv->cur_adap.algo_data = priv;
	priv->cur_adap.dev.parent = &adap->dev;
	priv->cur_adap.class = adap->class;
	priv->cur_adap.retries = adap->retries;
	priv->cur_adap.timeout = adap->timeout;
	priv->cur_adap.quirks = adap->quirks;
	priv->cur_adap.dev.of_node = priv->dev->of_node;
	ret = i2c_add_adapter(&priv->cur_adap);
	if (ret < 0)
		goto err_with_put;

	return 0;

 err_with_put:
	i2c_put_adapter(adap);
 err_with_revert:
	of_changeset_revert(&priv->chan[new_chan].chgset);
 err:
	dev_err(priv->dev, "failed to setup demux-adapter %d (%d)\n", new_chan, ret);
	priv->cur_chan = -EINVAL;
	return ret;
}

__attribute__((used)) static int i2c_demux_deactivate_master(struct i2c_demux_pinctrl_priv *priv)
{
	int ret, cur = priv->cur_chan;

	if (cur < 0)
		return 0;

	i2c_del_adapter(&priv->cur_adap);
	i2c_put_adapter(priv->chan[cur].parent_adap);

	ret = of_changeset_revert(&priv->chan[cur].chgset);

	priv->chan[cur].parent_adap = NULL;
	priv->cur_chan = -EINVAL;

	return ret;
}

__attribute__((used)) static int i2c_demux_change_master(struct i2c_demux_pinctrl_priv *priv, u32 new_chan)
{
	int ret;

	if (new_chan == priv->cur_chan)
		return 0;

	ret = i2c_demux_deactivate_master(priv);
	if (ret)
		return ret;

	return i2c_demux_activate_master(priv, new_chan);
}

__attribute__((used)) static ssize_t available_masters_show(struct device *dev,
				      struct device_attribute *attr,
				      char *buf)
{
	struct i2c_demux_pinctrl_priv *priv = dev_get_drvdata(dev);
	int count = 0, i;

	for (i = 0; i < priv->num_chan && count < PAGE_SIZE; i++)
		count += scnprintf(buf + count, PAGE_SIZE - count, "%d:%pOF%c",
				   i, priv->chan[i].parent_np,
				   i == priv->num_chan - 1 ? '\n' : ' ');

	return count;
}

__attribute__((used)) static ssize_t current_master_show(struct device *dev,
				   struct device_attribute *attr,
				   char *buf)
{
	struct i2c_demux_pinctrl_priv *priv = dev_get_drvdata(dev);

	return sprintf(buf, "%d\n", priv->cur_chan);
}

__attribute__((used)) static ssize_t current_master_store(struct device *dev,
				    struct device_attribute *attr,
				    const char *buf, size_t count)
{
	struct i2c_demux_pinctrl_priv *priv = dev_get_drvdata(dev);
	unsigned int val;
	int ret;

	ret = kstrtouint(buf, 0, &val);
	if (ret < 0)
		return ret;

	if (val >= priv->num_chan)
		return -EINVAL;

	ret = i2c_demux_change_master(priv, val);

	return ret < 0 ? ret : count;
}

__attribute__((used)) static int i2c_demux_pinctrl_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct i2c_demux_pinctrl_priv *priv;
	struct property *props;
	int num_chan, i, j, err;

	num_chan = of_count_phandle_with_args(np, "i2c-parent", NULL);
	if (num_chan < 2) {
		dev_err(&pdev->dev, "Need at least two I2C masters to switch\n");
		return -EINVAL;
	}

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv)
			   + num_chan * sizeof(struct i2c_demux_pinctrl_chan), GFP_KERNEL);

	props = devm_kcalloc(&pdev->dev, num_chan, sizeof(*props), GFP_KERNEL);

	if (!priv || !props)
		return -ENOMEM;

	err = of_property_read_string(np, "i2c-bus-name", &priv->bus_name);
	if (err)
		return err;

	for (i = 0; i < num_chan; i++) {
		struct device_node *adap_np;

		adap_np = of_parse_phandle(np, "i2c-parent", i);
		if (!adap_np) {
			dev_err(&pdev->dev, "can't get phandle for parent %d\n", i);
			err = -ENOENT;
			goto err_rollback;
		}
		priv->chan[i].parent_np = adap_np;

		props[i].name = devm_kstrdup(&pdev->dev, "status", GFP_KERNEL);
		props[i].value = devm_kstrdup(&pdev->dev, "ok", GFP_KERNEL);
		props[i].length = 3;

		of_changeset_init(&priv->chan[i].chgset);
		of_changeset_update_property(&priv->chan[i].chgset, adap_np, &props[i]);
	}

	priv->num_chan = num_chan;
	priv->dev = &pdev->dev;

	platform_set_drvdata(pdev, priv);

	pm_runtime_no_callbacks(&pdev->dev);

	/* switch to first parent as active master */
	i2c_demux_activate_master(priv, 0);

	err = device_create_file(&pdev->dev, &dev_attr_available_masters);
	if (err)
		goto err_rollback;

	err = device_create_file(&pdev->dev, &dev_attr_current_master);
	if (err)
		goto err_rollback_available;

	return 0;

err_rollback_available:
	device_remove_file(&pdev->dev, &dev_attr_available_masters);
err_rollback:
	for (j = 0; j < i; j++) {
		of_node_put(priv->chan[j].parent_np);
		of_changeset_destroy(&priv->chan[j].chgset);
	}

	return err;
}

__attribute__((used)) static int i2c_demux_pinctrl_remove(struct platform_device *pdev)
{
	struct i2c_demux_pinctrl_priv *priv = platform_get_drvdata(pdev);
	int i;

	device_remove_file(&pdev->dev, &dev_attr_current_master);
	device_remove_file(&pdev->dev, &dev_attr_available_masters);

	i2c_demux_deactivate_master(priv);

	for (i = 0; i < priv->num_chan; i++) {
		of_node_put(priv->chan[i].parent_np);
		of_changeset_destroy(&priv->chan[i].chgset);
	}

	return 0;
}

