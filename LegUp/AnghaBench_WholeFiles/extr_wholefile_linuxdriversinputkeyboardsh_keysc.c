#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct sh_keysc_info {size_t mode; int* keycodes; int scan_timing; scalar_t__ delay; scalar_t__ kycr2_delay; } ;
struct sh_keysc_priv {unsigned long* last_keys; int /*<<< orphan*/ * iomem_base; struct input_dev* input; struct sh_keysc_info pdata; } ;
struct resource {int /*<<< orphan*/  start; } ;
struct device {int dummy; } ;
struct platform_device {struct device dev; int /*<<< orphan*/  name; } ;
struct TYPE_5__ {int vendor; int product; int version; int /*<<< orphan*/  bustype; } ;
struct TYPE_4__ {struct device* parent; } ;
struct input_dev {char* phys; int* keycode; int keycodesize; unsigned long* keybit; int /*<<< orphan*/  keycodemax; TYPE_2__ id; TYPE_1__ dev; int /*<<< orphan*/  name; int /*<<< orphan*/ * evbit; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int keyout; int keyin; int kymd; } ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (int*) ; 
 int BITS_TO_LONGS (int) ; 
 int /*<<< orphan*/  BIT_MASK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BUS_HOST ; 
 int /*<<< orphan*/  DECLARE_BITMAP (unsigned long*,int) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  EV_KEY ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int KEY_RESERVED ; 
 int KYCR1 ; 
 int KYCR2 ; 
 unsigned long KYCR2_IRQ_DISABLED ; 
 unsigned long KYCR2_IRQ_LEVEL ; 
 int KYINDR ; 
 int KYOUTDR ; 
 int SH_KEYSC_MAXKEYS ; 
 int /*<<< orphan*/  __clear_bit (int,unsigned long*) ; 
 int /*<<< orphan*/  __set_bit (int,unsigned long*) ; 
 int /*<<< orphan*/  bitmap_and (unsigned long*,unsigned long*,unsigned long*,int) ; 
 int /*<<< orphan*/  bitmap_complement (unsigned long*,unsigned long*,int) ; 
 int /*<<< orphan*/  bitmap_fill (unsigned long*,int) ; 
 int /*<<< orphan*/  bitmap_or (unsigned long*,unsigned long*,unsigned long*,int) ; 
 int /*<<< orphan*/  bitmap_zero (unsigned long*,int) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*) ; 
 int /*<<< orphan*/  dev_get_platdata (struct device*) ; 
 int /*<<< orphan*/  dev_name (struct device*) ; 
 int /*<<< orphan*/  device_init_wakeup (struct device*,int) ; 
 int /*<<< orphan*/  free_irq (int,struct platform_device*) ; 
 struct input_dev* input_allocate_device () ; 
 int /*<<< orphan*/  input_event (struct input_dev*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  input_free_device (struct input_dev*) ; 
 int input_register_device (struct input_dev*) ; 
 int /*<<< orphan*/  input_sync (struct input_dev*) ; 
 int /*<<< orphan*/  input_unregister_device (struct input_dev*) ; 
 unsigned long ioread16 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * ioremap_nocache (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  iounmap (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iowrite16 (unsigned long,int /*<<< orphan*/ *) ; 
 unsigned long* keys ; 
 unsigned long* keys0 ; 
 unsigned long* keys1 ; 
 int /*<<< orphan*/  kfree (struct sh_keysc_priv*) ; 
 struct sh_keysc_priv* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (struct sh_keysc_info*,int /*<<< orphan*/ ,int) ; 
 struct sh_keysc_priv* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct sh_keysc_priv*) ; 
 int /*<<< orphan*/  pm_runtime_disable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_enable (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_get_sync (struct device*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (struct device*) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct platform_device*) ; 
 int /*<<< orphan*/  resource_size (struct resource*) ; 
 TYPE_3__* sh_keysc_mode ; 
 scalar_t__ test_bit (int,unsigned long*) ; 
 int /*<<< orphan*/  udelay (scalar_t__) ; 

__attribute__((used)) static unsigned long sh_keysc_read(struct sh_keysc_priv *p, int reg_nr)
{
	return ioread16(p->iomem_base + (reg_nr << 2));
}

__attribute__((used)) static void sh_keysc_write(struct sh_keysc_priv *p, int reg_nr,
			   unsigned long value)
{
	iowrite16(value, p->iomem_base + (reg_nr << 2));
}

__attribute__((used)) static void sh_keysc_level_mode(struct sh_keysc_priv *p,
				unsigned long keys_set)
{
	struct sh_keysc_info *pdata = &p->pdata;

	sh_keysc_write(p, KYOUTDR, 0);
	sh_keysc_write(p, KYCR2, KYCR2_IRQ_LEVEL | (keys_set << 8));

	if (pdata->kycr2_delay)
		udelay(pdata->kycr2_delay);
}

__attribute__((used)) static void sh_keysc_map_dbg(struct device *dev, unsigned long *map,
			     const char *str)
{
	int k;

	for (k = 0; k < BITS_TO_LONGS(SH_KEYSC_MAXKEYS); k++)
		dev_dbg(dev, "%s[%d] 0x%lx\n", str, k, map[k]);
}

__attribute__((used)) static irqreturn_t sh_keysc_isr(int irq, void *dev_id)
{
	struct platform_device *pdev = dev_id;
	struct sh_keysc_priv *priv = platform_get_drvdata(pdev);
	struct sh_keysc_info *pdata = &priv->pdata;
	int keyout_nr = sh_keysc_mode[pdata->mode].keyout;
	int keyin_nr = sh_keysc_mode[pdata->mode].keyin;
	DECLARE_BITMAP(keys, SH_KEYSC_MAXKEYS);
	DECLARE_BITMAP(keys0, SH_KEYSC_MAXKEYS);
	DECLARE_BITMAP(keys1, SH_KEYSC_MAXKEYS);
	unsigned char keyin_set, tmp;
	int i, k, n;

	dev_dbg(&pdev->dev, "isr!\n");

	bitmap_fill(keys1, SH_KEYSC_MAXKEYS);
	bitmap_zero(keys0, SH_KEYSC_MAXKEYS);

	do {
		bitmap_zero(keys, SH_KEYSC_MAXKEYS);
		keyin_set = 0;

		sh_keysc_write(priv, KYCR2, KYCR2_IRQ_DISABLED);

		for (i = 0; i < keyout_nr; i++) {
			n = keyin_nr * i;

			/* drive one KEYOUT pin low, read KEYIN pins */
			sh_keysc_write(priv, KYOUTDR, 0xffff ^ (3 << (i * 2)));
			udelay(pdata->delay);
			tmp = sh_keysc_read(priv, KYINDR);

			/* set bit if key press has been detected */
			for (k = 0; k < keyin_nr; k++) {
				if (tmp & (1 << k))
					__set_bit(n + k, keys);
			}

			/* keep track of which KEYIN bits that have been set */
			keyin_set |= tmp ^ ((1 << keyin_nr) - 1);
		}

		sh_keysc_level_mode(priv, keyin_set);

		bitmap_complement(keys, keys, SH_KEYSC_MAXKEYS);
		bitmap_and(keys1, keys1, keys, SH_KEYSC_MAXKEYS);
		bitmap_or(keys0, keys0, keys, SH_KEYSC_MAXKEYS);

		sh_keysc_map_dbg(&pdev->dev, keys, "keys");

	} while (sh_keysc_read(priv, KYCR2) & 0x01);

	sh_keysc_map_dbg(&pdev->dev, priv->last_keys, "last_keys");
	sh_keysc_map_dbg(&pdev->dev, keys0, "keys0");
	sh_keysc_map_dbg(&pdev->dev, keys1, "keys1");

	for (i = 0; i < SH_KEYSC_MAXKEYS; i++) {
		k = pdata->keycodes[i];
		if (!k)
			continue;

		if (test_bit(i, keys0) == test_bit(i, priv->last_keys))
			continue;

		if (test_bit(i, keys1) || test_bit(i, keys0)) {
			input_event(priv->input, EV_KEY, k, 1);
			__set_bit(i, priv->last_keys);
		}

		if (!test_bit(i, keys1)) {
			input_event(priv->input, EV_KEY, k, 0);
			__clear_bit(i, priv->last_keys);
		}

	}
	input_sync(priv->input);

	return IRQ_HANDLED;
}

__attribute__((used)) static int sh_keysc_probe(struct platform_device *pdev)
{
	struct sh_keysc_priv *priv;
	struct sh_keysc_info *pdata;
	struct resource *res;
	struct input_dev *input;
	int i;
	int irq, error;

	if (!dev_get_platdata(&pdev->dev)) {
		dev_err(&pdev->dev, "no platform data defined\n");
		error = -EINVAL;
		goto err0;
	}

	error = -ENXIO;
	res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	if (res == NULL) {
		dev_err(&pdev->dev, "failed to get I/O memory\n");
		goto err0;
	}

	irq = platform_get_irq(pdev, 0);
	if (irq < 0) {
		dev_err(&pdev->dev, "failed to get irq\n");
		goto err0;
	}

	priv = kzalloc(sizeof(*priv), GFP_KERNEL);
	if (priv == NULL) {
		dev_err(&pdev->dev, "failed to allocate driver data\n");
		error = -ENOMEM;
		goto err0;
	}

	platform_set_drvdata(pdev, priv);
	memcpy(&priv->pdata, dev_get_platdata(&pdev->dev), sizeof(priv->pdata));
	pdata = &priv->pdata;

	priv->iomem_base = ioremap_nocache(res->start, resource_size(res));
	if (priv->iomem_base == NULL) {
		dev_err(&pdev->dev, "failed to remap I/O memory\n");
		error = -ENXIO;
		goto err1;
	}

	priv->input = input_allocate_device();
	if (!priv->input) {
		dev_err(&pdev->dev, "failed to allocate input device\n");
		error = -ENOMEM;
		goto err2;
	}

	input = priv->input;
	input->evbit[0] = BIT_MASK(EV_KEY);

	input->name = pdev->name;
	input->phys = "sh-keysc-keys/input0";
	input->dev.parent = &pdev->dev;

	input->id.bustype = BUS_HOST;
	input->id.vendor = 0x0001;
	input->id.product = 0x0001;
	input->id.version = 0x0100;

	input->keycode = pdata->keycodes;
	input->keycodesize = sizeof(pdata->keycodes[0]);
	input->keycodemax = ARRAY_SIZE(pdata->keycodes);

	error = request_threaded_irq(irq, NULL, sh_keysc_isr, IRQF_ONESHOT,
				     dev_name(&pdev->dev), pdev);
	if (error) {
		dev_err(&pdev->dev, "failed to request IRQ\n");
		goto err3;
	}

	for (i = 0; i < SH_KEYSC_MAXKEYS; i++)
		__set_bit(pdata->keycodes[i], input->keybit);
	__clear_bit(KEY_RESERVED, input->keybit);

	error = input_register_device(input);
	if (error) {
		dev_err(&pdev->dev, "failed to register input device\n");
		goto err4;
	}

	pm_runtime_enable(&pdev->dev);
	pm_runtime_get_sync(&pdev->dev);

	sh_keysc_write(priv, KYCR1, (sh_keysc_mode[pdata->mode].kymd << 8) |
		       pdata->scan_timing);
	sh_keysc_level_mode(priv, 0);

	device_init_wakeup(&pdev->dev, 1);

	return 0;

 err4:
	free_irq(irq, pdev);
 err3:
	input_free_device(input);
 err2:
	iounmap(priv->iomem_base);
 err1:
	kfree(priv);
 err0:
	return error;
}

__attribute__((used)) static int sh_keysc_remove(struct platform_device *pdev)
{
	struct sh_keysc_priv *priv = platform_get_drvdata(pdev);

	sh_keysc_write(priv, KYCR2, KYCR2_IRQ_DISABLED);

	input_unregister_device(priv->input);
	free_irq(platform_get_irq(pdev, 0), pdev);
	iounmap(priv->iomem_base);

	pm_runtime_put_sync(&pdev->dev);
	pm_runtime_disable(&pdev->dev);

	kfree(priv);

	return 0;
}

