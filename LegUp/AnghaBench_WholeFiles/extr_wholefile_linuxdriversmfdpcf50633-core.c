#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct TYPE_7__ {TYPE_2__* parent; } ;
struct platform_device {TYPE_1__ dev; } ;
struct pcf50633_platform_data {int /*<<< orphan*/  (* probe_done ) (struct pcf50633*) ;int /*<<< orphan*/ * reg_init_data; } ;
struct pcf50633 {int* resume_reason; struct platform_device** regulator_pdev; struct platform_device* bl_pdev; struct platform_device* adc_pdev; struct platform_device* mbc_pdev; struct platform_device* rtc_pdev; struct platform_device* input_pdev; TYPE_2__* dev; int /*<<< orphan*/  regmap; int /*<<< orphan*/  lock; struct pcf50633_platform_data* pdata; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_8__ {int /*<<< orphan*/  kobj; } ;
struct i2c_client {TYPE_2__ dev; int /*<<< orphan*/  irq; } ;
struct device_attribute {int dummy; } ;
struct device {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  dump ;

/* Variables and functions */
 int ENODEV ; 
 int ENOENT ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int PCF50633_NUM_REGULATORS ; 
#define  PCF50633_REG_INT1 132 
#define  PCF50633_REG_INT2 131 
#define  PCF50633_REG_INT3 130 
#define  PCF50633_REG_INT4 129 
#define  PCF50633_REG_INT5 128 
 int PTR_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 struct pcf50633* dev_get_drvdata (struct device*) ; 
 struct pcf50633_platform_data* dev_get_platdata (TYPE_2__*) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,int,int) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*) ; 
 struct pcf50633* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  devm_regmap_init_i2c (struct i2c_client*,int /*<<< orphan*/ *) ; 
 struct pcf50633* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct pcf50633*) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pcf50633_irq_free (struct pcf50633*) ; 
 int /*<<< orphan*/  pcf50633_irq_init (struct pcf50633*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pcf50633_regmap_config ; 
 int /*<<< orphan*/  pcf_attr_group ; 
 int platform_device_add (struct platform_device*) ; 
 int platform_device_add_data (struct platform_device*,int /*<<< orphan*/ *,int) ; 
 struct platform_device* platform_device_alloc (char const*,int) ; 
 int /*<<< orphan*/  platform_device_put (struct platform_device*) ; 
 int /*<<< orphan*/  platform_device_unregister (struct platform_device*) ; 
 int regmap_raw_read (int /*<<< orphan*/ ,int,int*,int) ; 
 int regmap_raw_write (int /*<<< orphan*/ ,int,int*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int regmap_update_bits (int /*<<< orphan*/ ,int,int,int) ; 
 int regmap_write (int /*<<< orphan*/ ,int,int) ; 
 int sprintf (char*,char*,int,...) ; 
 int /*<<< orphan*/  stub1 (struct pcf50633*) ; 
 int sysfs_create_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sysfs_remove_group (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int pcf50633_read_block(struct pcf50633 *pcf, u8 reg,
					int nr_regs, u8 *data)
{
	int ret;

	ret = regmap_raw_read(pcf->regmap, reg, data, nr_regs);
	if (ret != 0)
		return ret;

	return nr_regs;
}

int pcf50633_write_block(struct pcf50633 *pcf , u8 reg,
					int nr_regs, u8 *data)
{
	return regmap_raw_write(pcf->regmap, reg, data, nr_regs);
}

u8 pcf50633_reg_read(struct pcf50633 *pcf, u8 reg)
{
	unsigned int val;
	int ret;

	ret = regmap_read(pcf->regmap, reg, &val);
	if (ret < 0)
		return -1;

	return val;
}

int pcf50633_reg_write(struct pcf50633 *pcf, u8 reg, u8 val)
{
	return regmap_write(pcf->regmap, reg, val);
}

int pcf50633_reg_set_bit_mask(struct pcf50633 *pcf, u8 reg, u8 mask, u8 val)
{
	return regmap_update_bits(pcf->regmap, reg, mask, val);
}

int pcf50633_reg_clear_bits(struct pcf50633 *pcf, u8 reg, u8 val)
{
	return regmap_update_bits(pcf->regmap, reg, val, 0);
}

__attribute__((used)) static ssize_t show_dump_regs(struct device *dev, struct device_attribute *attr,
			    char *buf)
{
	struct pcf50633 *pcf = dev_get_drvdata(dev);
	u8 dump[16];
	int n, n1, idx = 0;
	char *buf1 = buf;
	static u8 address_no_read[] = { /* must be ascending */
		PCF50633_REG_INT1,
		PCF50633_REG_INT2,
		PCF50633_REG_INT3,
		PCF50633_REG_INT4,
		PCF50633_REG_INT5,
		0 /* terminator */
	};

	for (n = 0; n < 256; n += sizeof(dump)) {
		for (n1 = 0; n1 < sizeof(dump); n1++)
			if (n == address_no_read[idx]) {
				idx++;
				dump[n1] = 0x00;
			} else
				dump[n1] = pcf50633_reg_read(pcf, n + n1);

		buf1 += sprintf(buf1, "%*ph\n", (int)sizeof(dump), dump);
	}

	return buf1 - buf;
}

__attribute__((used)) static ssize_t show_resume_reason(struct device *dev,
				struct device_attribute *attr, char *buf)
{
	struct pcf50633 *pcf = dev_get_drvdata(dev);
	int n;

	n = sprintf(buf, "%02x%02x%02x%02x%02x\n",
				pcf->resume_reason[0],
				pcf->resume_reason[1],
				pcf->resume_reason[2],
				pcf->resume_reason[3],
				pcf->resume_reason[4]);

	return n;
}

__attribute__((used)) static void
pcf50633_client_dev_register(struct pcf50633 *pcf, const char *name,
						struct platform_device **pdev)
{
	int ret;

	*pdev = platform_device_alloc(name, -1);
	if (!*pdev) {
		dev_err(pcf->dev, "Failed to allocate %s\n", name);
		return;
	}

	(*pdev)->dev.parent = pcf->dev;

	ret = platform_device_add(*pdev);
	if (ret) {
		dev_err(pcf->dev, "Failed to register %s: %d\n", name, ret);
		platform_device_put(*pdev);
		*pdev = NULL;
	}
}

__attribute__((used)) static int pcf50633_probe(struct i2c_client *client,
				const struct i2c_device_id *ids)
{
	struct pcf50633 *pcf;
	struct platform_device *pdev;
	struct pcf50633_platform_data *pdata = dev_get_platdata(&client->dev);
	int i, j, ret;
	int version, variant;

	if (!client->irq) {
		dev_err(&client->dev, "Missing IRQ\n");
		return -ENOENT;
	}

	pcf = devm_kzalloc(&client->dev, sizeof(*pcf), GFP_KERNEL);
	if (!pcf)
		return -ENOMEM;

	i2c_set_clientdata(client, pcf);
	pcf->dev = &client->dev;
	pcf->pdata = pdata;

	mutex_init(&pcf->lock);

	pcf->regmap = devm_regmap_init_i2c(client, &pcf50633_regmap_config);
	if (IS_ERR(pcf->regmap)) {
		ret = PTR_ERR(pcf->regmap);
		dev_err(pcf->dev, "Failed to allocate register map: %d\n", ret);
		return ret;
	}

	version = pcf50633_reg_read(pcf, 0);
	variant = pcf50633_reg_read(pcf, 1);
	if (version < 0 || variant < 0) {
		dev_err(pcf->dev, "Unable to probe pcf50633\n");
		ret = -ENODEV;
		return ret;
	}

	dev_info(pcf->dev, "Probed device version %d variant %d\n",
							version, variant);

	pcf50633_irq_init(pcf, client->irq);

	/* Create sub devices */
	pcf50633_client_dev_register(pcf, "pcf50633-input", &pcf->input_pdev);
	pcf50633_client_dev_register(pcf, "pcf50633-rtc", &pcf->rtc_pdev);
	pcf50633_client_dev_register(pcf, "pcf50633-mbc", &pcf->mbc_pdev);
	pcf50633_client_dev_register(pcf, "pcf50633-adc", &pcf->adc_pdev);
	pcf50633_client_dev_register(pcf, "pcf50633-backlight", &pcf->bl_pdev);


	for (i = 0; i < PCF50633_NUM_REGULATORS; i++) {
		pdev = platform_device_alloc("pcf50633-regulator", i);
		if (!pdev) {
			ret = -ENOMEM;
			goto err2;
		}

		pdev->dev.parent = pcf->dev;
		ret = platform_device_add_data(pdev, &pdata->reg_init_data[i],
					       sizeof(pdata->reg_init_data[i]));
		if (ret)
			goto err;

		ret = platform_device_add(pdev);
		if (ret)
			goto err;

		pcf->regulator_pdev[i] = pdev;
	}

	ret = sysfs_create_group(&client->dev.kobj, &pcf_attr_group);
	if (ret)
		dev_warn(pcf->dev, "error creating sysfs entries\n");

	if (pdata->probe_done)
		pdata->probe_done(pcf);

	return 0;

err:
	platform_device_put(pdev);
err2:
	for (j = 0; j < i; j++)
		platform_device_put(pcf->regulator_pdev[j]);

	return ret;
}

__attribute__((used)) static int pcf50633_remove(struct i2c_client *client)
{
	struct pcf50633 *pcf = i2c_get_clientdata(client);
	int i;

	sysfs_remove_group(&client->dev.kobj, &pcf_attr_group);
	pcf50633_irq_free(pcf);

	platform_device_unregister(pcf->input_pdev);
	platform_device_unregister(pcf->rtc_pdev);
	platform_device_unregister(pcf->mbc_pdev);
	platform_device_unregister(pcf->adc_pdev);
	platform_device_unregister(pcf->bl_pdev);

	for (i = 0; i < PCF50633_NUM_REGULATORS; i++)
		platform_device_unregister(pcf->regulator_pdev[i]);

	return 0;
}

