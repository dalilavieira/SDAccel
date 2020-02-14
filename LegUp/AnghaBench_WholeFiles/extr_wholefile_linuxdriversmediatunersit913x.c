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
typedef  int u8 ;
typedef  unsigned int u32 ;
typedef  unsigned int u16 ;
struct platform_device_id {int driver_data; } ;
struct TYPE_6__ {struct it913x_platform_data* platform_data; } ;
struct platform_device {TYPE_2__ dev; } ;
struct it913x_platform_data {int /*<<< orphan*/  role; struct dvb_frontend* fe; int /*<<< orphan*/  regmap; } ;
struct it913x_dev {unsigned int clk_mode; int xtal; int fdiv; unsigned int fn_min; int chip_ver; int active; struct dvb_frontend* fe; int /*<<< orphan*/  role; int /*<<< orphan*/  regmap; struct platform_device* pdev; } ;
struct dvb_tuner_ops {int dummy; } ;
struct TYPE_5__ {int /*<<< orphan*/  tuner_ops; } ;
struct dtv_frontend_properties {int frequency; int bandwidth_hz; } ;
struct dvb_frontend {struct it913x_dev* tuner_priv; TYPE_1__ ops; struct dtv_frontend_properties dtv_property_cache; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int const*) ; 
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IT913X_ROLE_DUAL_MASTER ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_err (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,char*) ; 
 int /*<<< orphan*/  it913x_tuner_ops ; 
 unsigned long jiffies ; 
 int jiffies_to_msecs (unsigned long) ; 
 int /*<<< orphan*/  kfree (struct it913x_dev*) ; 
 struct it913x_dev* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 unsigned long msecs_to_jiffies (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct platform_device_id* platform_get_device_id (struct platform_device*) ; 
 struct it913x_dev* platform_get_drvdata (struct platform_device*) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct it913x_dev*) ; 
 int regmap_bulk_read (int /*<<< orphan*/ ,int,int*,int) ; 
 int regmap_bulk_write (int /*<<< orphan*/ ,int,char*,int) ; 
 int regmap_read (int /*<<< orphan*/ ,int,unsigned int*) ; 
 int regmap_write (int /*<<< orphan*/ ,int,unsigned int) ; 
 int /*<<< orphan*/  time_after (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static int it913x_init(struct dvb_frontend *fe)
{
	struct it913x_dev *dev = fe->tuner_priv;
	struct platform_device *pdev = dev->pdev;
	int ret;
	unsigned int utmp;
	u8 iqik_m_cal, nv_val, buf[2];
	static const u8 nv[] = {48, 32, 24, 16, 12, 8, 6, 4, 2};
	unsigned long timeout;

	dev_dbg(&pdev->dev, "role %u\n", dev->role);

	ret = regmap_write(dev->regmap, 0x80ec4c, 0x68);
	if (ret)
		goto err;

	usleep_range(10000, 100000);

	ret = regmap_read(dev->regmap, 0x80ec86, &utmp);
	if (ret)
		goto err;

	switch (utmp) {
	case 0:
		/* 12.000 MHz */
		dev->clk_mode = utmp;
		dev->xtal = 2000;
		dev->fdiv = 3;
		iqik_m_cal = 16;
		break;
	case 1:
		/* 20.480 MHz */
		dev->clk_mode = utmp;
		dev->xtal = 640;
		dev->fdiv = 1;
		iqik_m_cal = 6;
		break;
	default:
		dev_err(&pdev->dev, "unknown clock identifier %d\n", utmp);
		goto err;
	}

	ret = regmap_read(dev->regmap, 0x80ed03,  &utmp);
	if (ret)
		goto err;

	else if (utmp < ARRAY_SIZE(nv))
		nv_val = nv[utmp];
	else
		nv_val = 2;

	#define TIMEOUT 50
	timeout = jiffies + msecs_to_jiffies(TIMEOUT);
	while (!time_after(jiffies, timeout)) {
		ret = regmap_bulk_read(dev->regmap, 0x80ed23, buf, 2);
		if (ret)
			goto err;

		utmp = (buf[1] << 8) | (buf[0] << 0);
		if (utmp)
			break;
	}

	dev_dbg(&pdev->dev, "r_fbc_m_bdry took %u ms, val %u\n",
			jiffies_to_msecs(jiffies) -
			(jiffies_to_msecs(timeout) - TIMEOUT), utmp);

	dev->fn_min = dev->xtal * utmp;
	dev->fn_min /= (dev->fdiv * nv_val);
	dev->fn_min *= 1000;
	dev_dbg(&pdev->dev, "fn_min %u\n", dev->fn_min);

	/*
	 * Chip version BX never sets that flag so we just wait 50ms in that
	 * case. It is possible poll BX similarly than AX and then timeout in
	 * order to get 50ms delay, but that causes about 120 extra I2C
	 * messages. As for now, we just wait and reduce IO.
	 */
	if (dev->chip_ver == 1) {
		#define TIMEOUT 50
		timeout = jiffies + msecs_to_jiffies(TIMEOUT);
		while (!time_after(jiffies, timeout)) {
			ret = regmap_read(dev->regmap, 0x80ec82, &utmp);
			if (ret)
				goto err;

			if (utmp)
				break;
		}

		dev_dbg(&pdev->dev, "p_tsm_init_mode took %u ms, val %u\n",
				jiffies_to_msecs(jiffies) -
				(jiffies_to_msecs(timeout) - TIMEOUT), utmp);
	} else {
		msleep(50);
	}

	ret = regmap_write(dev->regmap, 0x80ed81, iqik_m_cal);
	if (ret)
		goto err;

	ret = regmap_write(dev->regmap, 0x80ec57, 0x00);
	if (ret)
		goto err;

	ret = regmap_write(dev->regmap, 0x80ec58, 0x00);
	if (ret)
		goto err;

	ret = regmap_write(dev->regmap, 0x80ec40, 0x01);
	if (ret)
		goto err;

	dev->active = true;

	return 0;
err:
	dev_dbg(&pdev->dev, "failed %d\n", ret);
	return ret;
}

__attribute__((used)) static int it913x_sleep(struct dvb_frontend *fe)
{
	struct it913x_dev *dev = fe->tuner_priv;
	struct platform_device *pdev = dev->pdev;
	int ret, len;

	dev_dbg(&pdev->dev, "role %u\n", dev->role);

	dev->active = false;

	ret  = regmap_bulk_write(dev->regmap, 0x80ec40, "\x00", 1);
	if (ret)
		goto err;

	/*
	 * Writing '0x00' to master tuner register '0x80ec08' causes slave tuner
	 * communication lost. Due to that, we cannot put master full sleep.
	 */
	if (dev->role == IT913X_ROLE_DUAL_MASTER)
		len = 4;
	else
		len = 15;

	dev_dbg(&pdev->dev, "role %u, len %d\n", dev->role, len);

	ret = regmap_bulk_write(dev->regmap, 0x80ec02,
			"\x3f\x1f\x3f\x3e\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00",
			len);
	if (ret)
		goto err;

	ret = regmap_bulk_write(dev->regmap, 0x80ec12, "\x00\x00\x00\x00", 4);
	if (ret)
		goto err;

	ret = regmap_bulk_write(dev->regmap, 0x80ec17,
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00", 9);
	if (ret)
		goto err;

	ret = regmap_bulk_write(dev->regmap, 0x80ec22,
			"\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	if (ret)
		goto err;

	ret = regmap_bulk_write(dev->regmap, 0x80ec20, "\x00", 1);
	if (ret)
		goto err;

	ret = regmap_bulk_write(dev->regmap, 0x80ec3f, "\x01", 1);
	if (ret)
		goto err;

	return 0;
err:
	dev_dbg(&pdev->dev, "failed %d\n", ret);
	return ret;
}

__attribute__((used)) static int it913x_set_params(struct dvb_frontend *fe)
{
	struct it913x_dev *dev = fe->tuner_priv;
	struct platform_device *pdev = dev->pdev;
	struct dtv_frontend_properties *c = &fe->dtv_property_cache;
	int ret;
	unsigned int utmp;
	u32 pre_lo_freq, t_cal_freq;
	u16 iqik_m_cal, n_div;
	u8 u8tmp, n, l_band, lna_band;

	dev_dbg(&pdev->dev, "role=%u, frequency %u, bandwidth_hz %u\n",
			dev->role, c->frequency, c->bandwidth_hz);

	if (!dev->active) {
		ret = -EINVAL;
		goto err;
	}

	if (c->frequency <=         74000000) {
		n_div = 48;
		n = 0;
	} else if (c->frequency <= 111000000) {
		n_div = 32;
		n = 1;
	} else if (c->frequency <= 148000000) {
		n_div = 24;
		n = 2;
	} else if (c->frequency <= 222000000) {
		n_div = 16;
		n = 3;
	} else if (c->frequency <= 296000000) {
		n_div = 12;
		n = 4;
	} else if (c->frequency <= 445000000) {
		n_div = 8;
		n = 5;
	} else if (c->frequency <= dev->fn_min) {
		n_div = 6;
		n = 6;
	} else if (c->frequency <= 950000000) {
		n_div = 4;
		n = 7;
	} else {
		n_div = 2;
		n = 0;
	}

	ret = regmap_read(dev->regmap, 0x80ed81, &utmp);
	if (ret)
		goto err;

	iqik_m_cal = utmp * n_div;

	if (utmp < 0x20) {
		if (dev->clk_mode == 0)
			iqik_m_cal = (iqik_m_cal * 9) >> 5;
		else
			iqik_m_cal >>= 1;
	} else {
		iqik_m_cal = 0x40 - iqik_m_cal;
		if (dev->clk_mode == 0)
			iqik_m_cal = ~((iqik_m_cal * 9) >> 5);
		else
			iqik_m_cal = ~(iqik_m_cal >> 1);
	}

	t_cal_freq = (c->frequency / 1000) * n_div * dev->fdiv;
	pre_lo_freq = t_cal_freq / dev->xtal;
	utmp = pre_lo_freq * dev->xtal;

	if ((t_cal_freq - utmp) >= (dev->xtal >> 1))
		pre_lo_freq++;

	pre_lo_freq += (u32) n << 13;
	/* Frequency OMEGA_IQIK_M_CAL_MID*/
	t_cal_freq = pre_lo_freq + (u32)iqik_m_cal;
	dev_dbg(&pdev->dev, "t_cal_freq %u, pre_lo_freq %u\n",
			t_cal_freq, pre_lo_freq);

	if (c->frequency <=         440000000) {
		l_band = 0;
		lna_band = 0;
	} else if (c->frequency <=  484000000) {
		l_band = 1;
		lna_band = 1;
	} else if (c->frequency <=  533000000) {
		l_band = 1;
		lna_band = 2;
	} else if (c->frequency <=  587000000) {
		l_band = 1;
		lna_band = 3;
	} else if (c->frequency <=  645000000) {
		l_band = 1;
		lna_band = 4;
	} else if (c->frequency <=  710000000) {
		l_band = 1;
		lna_band = 5;
	} else if (c->frequency <=  782000000) {
		l_band = 1;
		lna_band = 6;
	} else if (c->frequency <=  860000000) {
		l_band = 1;
		lna_band = 7;
	} else if (c->frequency <= 1492000000) {
		l_band = 1;
		lna_band = 0;
	} else if (c->frequency <= 1685000000) {
		l_band = 1;
		lna_band = 1;
	} else {
		ret = -EINVAL;
		goto err;
	}

	/* XXX: latest windows driver does not set that at all */
	ret = regmap_write(dev->regmap, 0x80ee06, lna_band);
	if (ret)
		goto err;

	if (c->bandwidth_hz <=      5000000)
		u8tmp = 0;
	else if (c->bandwidth_hz <= 6000000)
		u8tmp = 2;
	else if (c->bandwidth_hz <= 7000000)
		u8tmp = 4;
	else
		u8tmp = 6;       /* 8000000 */

	ret = regmap_write(dev->regmap, 0x80ec56, u8tmp);
	if (ret)
		goto err;

	/* XXX: latest windows driver sets different value (a8 != 68) */
	ret = regmap_write(dev->regmap, 0x80ec4c, 0xa0 | (l_band << 3));
	if (ret)
		goto err;

	ret = regmap_write(dev->regmap, 0x80ec4d, (t_cal_freq >> 0) & 0xff);
	if (ret)
		goto err;

	ret = regmap_write(dev->regmap, 0x80ec4e, (t_cal_freq >> 8) & 0xff);
	if (ret)
		goto err;

	ret = regmap_write(dev->regmap, 0x80011e, (pre_lo_freq >> 0) & 0xff);
	if (ret)
		goto err;

	ret = regmap_write(dev->regmap, 0x80011f, (pre_lo_freq >> 8) & 0xff);
	if (ret)
		goto err;

	return 0;
err:
	dev_dbg(&pdev->dev, "failed %d\n", ret);
	return ret;
}

__attribute__((used)) static int it913x_probe(struct platform_device *pdev)
{
	struct it913x_platform_data *pdata = pdev->dev.platform_data;
	struct dvb_frontend *fe = pdata->fe;
	struct it913x_dev *dev;
	const struct platform_device_id *id = platform_get_device_id(pdev);
	int ret;
	char *chip_ver_str;

	dev = kzalloc(sizeof(struct it913x_dev), GFP_KERNEL);
	if (dev == NULL) {
		ret = -ENOMEM;
		dev_err(&pdev->dev, "kzalloc() failed\n");
		goto err;
	}

	dev->pdev = pdev;
	dev->regmap = pdata->regmap;
	dev->fe = pdata->fe;
	dev->chip_ver = id->driver_data;
	dev->role = pdata->role;

	fe->tuner_priv = dev;
	memcpy(&fe->ops.tuner_ops, &it913x_tuner_ops,
			sizeof(struct dvb_tuner_ops));
	platform_set_drvdata(pdev, dev);

	if (dev->chip_ver == 1)
		chip_ver_str = "AX";
	else if (dev->chip_ver == 2)
		chip_ver_str = "BX";
	else
		chip_ver_str = "??";

	dev_info(&pdev->dev, "ITE IT913X %s successfully attached\n",
		 chip_ver_str);
	dev_dbg(&pdev->dev, "chip_ver %u, role %u\n", dev->chip_ver, dev->role);
	return 0;
err:
	dev_dbg(&pdev->dev, "failed %d\n", ret);
	return ret;
}

__attribute__((used)) static int it913x_remove(struct platform_device *pdev)
{
	struct it913x_dev *dev = platform_get_drvdata(pdev);
	struct dvb_frontend *fe = dev->fe;

	dev_dbg(&pdev->dev, "\n");

	memset(&fe->ops.tuner_ops, 0, sizeof(struct dvb_tuner_ops));
	fe->tuner_priv = NULL;
	kfree(dev);

	return 0;
}

