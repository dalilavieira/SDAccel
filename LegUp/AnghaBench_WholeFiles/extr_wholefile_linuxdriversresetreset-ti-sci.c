#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_7__ {int of_reset_n_cells; int (* of_xlate ) (struct reset_controller_dev*,struct of_phandle_args const*) ;scalar_t__ of_node; int /*<<< orphan*/  owner; int /*<<< orphan*/ * ops; } ;
struct ti_sci_reset_data {int /*<<< orphan*/  idr; TYPE_2__ rcdev; TYPE_4__* dev; struct ti_sci_handle* sci; } ;
struct ti_sci_reset_control {int dev_id; int reset_mask; int /*<<< orphan*/  lock; } ;
struct ti_sci_dev_ops {int (* get_device_resets ) (struct ti_sci_handle const*,int,int*) ;int (* set_device_resets ) (struct ti_sci_handle const*,int,int) ;} ;
struct TYPE_6__ {struct ti_sci_dev_ops dev_ops; } ;
struct ti_sci_handle {TYPE_1__ ops; } ;
struct reset_controller_dev {scalar_t__ of_reset_n_cells; } ;
struct TYPE_8__ {scalar_t__ of_node; } ;
struct platform_device {TYPE_4__ dev; } ;
struct of_phandle_args {scalar_t__ args_count; int* args; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENODEV ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct ti_sci_handle*) ; 
 int PTR_ERR (struct ti_sci_handle*) ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 scalar_t__ WARN_ON (int) ; 
 void* devm_kzalloc (TYPE_4__*,int,int /*<<< orphan*/ ) ; 
 struct ti_sci_handle* devm_ti_sci_get_handle (TYPE_4__*) ; 
 int idr_alloc (int /*<<< orphan*/ *,struct ti_sci_reset_control*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idr_destroy (int /*<<< orphan*/ *) ; 
 struct ti_sci_reset_control* idr_find (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  idr_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 struct ti_sci_reset_data* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct ti_sci_reset_data*) ; 
 int reset_controller_register (TYPE_2__*) ; 
 int /*<<< orphan*/  reset_controller_unregister (TYPE_2__*) ; 
 int stub1 (struct ti_sci_handle const*,int,int*) ; 
 int stub2 (struct ti_sci_handle const*,int,int) ; 
 int stub3 (struct ti_sci_handle const*,int,int*) ; 
 int /*<<< orphan*/  ti_sci_reset_ops ; 
 struct ti_sci_reset_data* to_ti_sci_reset_data (struct reset_controller_dev*) ; 

__attribute__((used)) static int ti_sci_reset_set(struct reset_controller_dev *rcdev,
			    unsigned long id, bool assert)
{
	struct ti_sci_reset_data *data = to_ti_sci_reset_data(rcdev);
	const struct ti_sci_handle *sci = data->sci;
	const struct ti_sci_dev_ops *dev_ops = &sci->ops.dev_ops;
	struct ti_sci_reset_control *control;
	u32 reset_state;
	int ret;

	control = idr_find(&data->idr, id);
	if (!control)
		return -EINVAL;

	mutex_lock(&control->lock);

	ret = dev_ops->get_device_resets(sci, control->dev_id, &reset_state);
	if (ret)
		goto out;

	if (assert)
		reset_state |= control->reset_mask;
	else
		reset_state &= ~control->reset_mask;

	ret = dev_ops->set_device_resets(sci, control->dev_id, reset_state);
out:
	mutex_unlock(&control->lock);

	return ret;
}

__attribute__((used)) static int ti_sci_reset_assert(struct reset_controller_dev *rcdev,
			       unsigned long id)
{
	return ti_sci_reset_set(rcdev, id, true);
}

__attribute__((used)) static int ti_sci_reset_deassert(struct reset_controller_dev *rcdev,
				 unsigned long id)
{
	return ti_sci_reset_set(rcdev, id, false);
}

__attribute__((used)) static int ti_sci_reset_status(struct reset_controller_dev *rcdev,
			       unsigned long id)
{
	struct ti_sci_reset_data *data = to_ti_sci_reset_data(rcdev);
	const struct ti_sci_handle *sci = data->sci;
	const struct ti_sci_dev_ops *dev_ops = &sci->ops.dev_ops;
	struct ti_sci_reset_control *control;
	u32 reset_state;
	int ret;

	control = idr_find(&data->idr, id);
	if (!control)
		return -EINVAL;

	ret = dev_ops->get_device_resets(sci, control->dev_id, &reset_state);
	if (ret)
		return ret;

	return reset_state & control->reset_mask;
}

__attribute__((used)) static int ti_sci_reset_of_xlate(struct reset_controller_dev *rcdev,
				 const struct of_phandle_args *reset_spec)
{
	struct ti_sci_reset_data *data = to_ti_sci_reset_data(rcdev);
	struct ti_sci_reset_control *control;

	if (WARN_ON(reset_spec->args_count != rcdev->of_reset_n_cells))
		return -EINVAL;

	control = devm_kzalloc(data->dev, sizeof(*control), GFP_KERNEL);
	if (!control)
		return -ENOMEM;

	control->dev_id = reset_spec->args[0];
	control->reset_mask = reset_spec->args[1];
	mutex_init(&control->lock);

	return idr_alloc(&data->idr, control, 0, 0, GFP_KERNEL);
}

__attribute__((used)) static int ti_sci_reset_probe(struct platform_device *pdev)
{
	struct ti_sci_reset_data *data;

	if (!pdev->dev.of_node)
		return -ENODEV;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->sci = devm_ti_sci_get_handle(&pdev->dev);
	if (IS_ERR(data->sci))
		return PTR_ERR(data->sci);

	data->rcdev.ops = &ti_sci_reset_ops;
	data->rcdev.owner = THIS_MODULE;
	data->rcdev.of_node = pdev->dev.of_node;
	data->rcdev.of_reset_n_cells = 2;
	data->rcdev.of_xlate = ti_sci_reset_of_xlate;
	data->dev = &pdev->dev;
	idr_init(&data->idr);

	platform_set_drvdata(pdev, data);

	return reset_controller_register(&data->rcdev);
}

__attribute__((used)) static int ti_sci_reset_remove(struct platform_device *pdev)
{
	struct ti_sci_reset_data *data = platform_get_drvdata(pdev);

	reset_controller_unregister(&data->rcdev);

	idr_destroy(&data->idr);

	return 0;
}

