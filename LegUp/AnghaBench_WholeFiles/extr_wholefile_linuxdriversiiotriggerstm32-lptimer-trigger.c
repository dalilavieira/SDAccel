#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  size_t u32 ;
struct stm32_lptim_trigger {int /*<<< orphan*/  trg; TYPE_2__* dev; } ;
struct TYPE_6__ {int /*<<< orphan*/  of_node; int /*<<< orphan*/  parent; } ;
struct platform_device {TYPE_2__ dev; } ;
struct TYPE_5__ {int /*<<< orphan*/  parent; } ;
struct iio_trigger {int /*<<< orphan*/ * ops; TYPE_1__ dev; } ;
struct iio_dev {int modes; } ;

/* Variables and functions */
 size_t ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INDIO_HARDWARE_TRIGGERED ; 
 struct iio_trigger* devm_iio_trigger_alloc (TYPE_2__*,char*,int /*<<< orphan*/ ) ; 
 int devm_iio_trigger_register (TYPE_2__*,struct iio_trigger*) ; 
 struct stm32_lptim_trigger* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iio_trigger_set_drvdata (struct iio_trigger*,struct stm32_lptim_trigger*) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,size_t*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct stm32_lptim_trigger*) ; 
 int /*<<< orphan*/  stm32_lptim_trigger_ops ; 
 int /*<<< orphan*/ * stm32_lptim_triggers ; 

__attribute__((used)) static int stm32_lptim_validate_device(struct iio_trigger *trig,
				       struct iio_dev *indio_dev)
{
	if (indio_dev->modes & INDIO_HARDWARE_TRIGGERED)
		return 0;

	return -EINVAL;
}

bool is_stm32_lptim_trigger(struct iio_trigger *trig)
{
	return (trig->ops == &stm32_lptim_trigger_ops);
}

__attribute__((used)) static int stm32_lptim_setup_trig(struct stm32_lptim_trigger *priv)
{
	struct iio_trigger *trig;

	trig = devm_iio_trigger_alloc(priv->dev, "%s", priv->trg);
	if  (!trig)
		return -ENOMEM;

	trig->dev.parent = priv->dev->parent;
	trig->ops = &stm32_lptim_trigger_ops;
	iio_trigger_set_drvdata(trig, priv);

	return devm_iio_trigger_register(priv->dev, trig);
}

__attribute__((used)) static int stm32_lptim_trigger_probe(struct platform_device *pdev)
{
	struct stm32_lptim_trigger *priv;
	u32 index;
	int ret;

	priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	if (of_property_read_u32(pdev->dev.of_node, "reg", &index))
		return -EINVAL;

	if (index >= ARRAY_SIZE(stm32_lptim_triggers))
		return -EINVAL;

	priv->dev = &pdev->dev;
	priv->trg = stm32_lptim_triggers[index];

	ret = stm32_lptim_setup_trig(priv);
	if (ret)
		return ret;

	platform_set_drvdata(pdev, priv);

	return 0;
}

