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
typedef  scalar_t__ u8 ;
struct TYPE_2__ {int mode; int palette; scalar_t__ vflip; scalar_t__ hflip; } ;
struct stk_camera {TYPE_1__ vsettings; } ;
struct regval {int reg; int val; } ;

/* Variables and functions */
 scalar_t__ COM2_SSLEEP ; 
 int COM7_FMT_CIF ; 
 int COM7_FMT_QCIF ; 
 int COM7_FMT_QVGA ; 
 int COM7_FMT_SXGA ; 
 int COM7_FMT_VGA ; 
 int COM7_PBAYER ; 
 scalar_t__ COM7_RESET ; 
 int COM7_RGB ; 
 int COM7_YUV ; 
 int EFAULT ; 
 int EINVAL ; 
 int ENODEV ; 
 int MAX_RETRIES ; 
#define  MODE_CIF 137 
#define  MODE_QCIF 136 
#define  MODE_QVGA 135 
#define  MODE_SXGA 134 
#define  MODE_VGA 133 
 int MVFP_FLIP ; 
 int MVFP_MIRROR ; 
 scalar_t__ REG_ADVFH ; 
 scalar_t__ REG_ADVFL ; 
 scalar_t__ REG_AEB ; 
 scalar_t__ REG_AEW ; 
 scalar_t__ REG_COM2 ; 
 scalar_t__ REG_COM7 ; 
 scalar_t__ REG_HREF ; 
 scalar_t__ REG_HSTART ; 
 scalar_t__ REG_HSTOP ; 
 scalar_t__ REG_MIDH ; 
 scalar_t__ REG_MIDL ; 
 scalar_t__ REG_MVFP ; 
 scalar_t__ REG_PID ; 
 scalar_t__ REG_TSLB ; 
 scalar_t__ REG_VER ; 
 scalar_t__ REG_VREF ; 
 scalar_t__ REG_VSTART ; 
 scalar_t__ REG_VSTOP ; 
 scalar_t__ SENSOR_ADDRESS ; 
 int /*<<< orphan*/  STK_IIC_ADDR ; 
 int /*<<< orphan*/  STK_IIC_ENABLE ; 
 scalar_t__ STK_IIC_ENABLE_YES ; 
 int /*<<< orphan*/  STK_IIC_OP ; 
 scalar_t__ STK_IIC_OP_RX ; 
 scalar_t__ STK_IIC_OP_TX ; 
 int /*<<< orphan*/  STK_IIC_RX_INDEX ; 
 int /*<<< orphan*/  STK_IIC_RX_VALUE ; 
 int /*<<< orphan*/  STK_IIC_STAT ; 
 scalar_t__ STK_IIC_STAT_RX_OK ; 
 scalar_t__ STK_IIC_STAT_TX_OK ; 
 int /*<<< orphan*/  STK_IIC_TX_INDEX ; 
 int /*<<< orphan*/  STK_IIC_TX_VALUE ; 
#define  V4L2_PIX_FMT_RGB565 132 
#define  V4L2_PIX_FMT_RGB565X 131 
#define  V4L2_PIX_FMT_SBGGR8 130 
#define  V4L2_PIX_FMT_UYVY 129 
#define  V4L2_PIX_FMT_YUYV 128 
 scalar_t__ max (int,int) ; 
 scalar_t__ min (int,int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 struct regval* ov_fmt_bayer ; 
 struct regval* ov_fmt_rgbp ; 
 struct regval* ov_fmt_rgbr ; 
 struct regval* ov_fmt_uyvy ; 
 struct regval* ov_fmt_yuyv ; 
 struct regval* ov_initvals ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  pr_info (char*,scalar_t__,scalar_t__,scalar_t__) ; 
 scalar_t__ stk_camera_read_reg (struct stk_camera*,int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__ stk_camera_write_reg (struct stk_camera*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int stk_sensor_outb(struct stk_camera *dev, u8 reg, u8 val)
{
	int i = 0;
	u8 tmpval = 0;

	if (stk_camera_write_reg(dev, STK_IIC_TX_INDEX, reg))
		return 1;
	if (stk_camera_write_reg(dev, STK_IIC_TX_VALUE, val))
		return 1;
	if (stk_camera_write_reg(dev, STK_IIC_OP, STK_IIC_OP_TX))
		return 1;
	do {
		if (stk_camera_read_reg(dev, STK_IIC_STAT, &tmpval))
			return 1;
		i++;
	} while (tmpval == 0 && i < MAX_RETRIES);
	if (tmpval != STK_IIC_STAT_TX_OK) {
		if (tmpval)
			pr_err("stk_sensor_outb failed, status=0x%02x\n",
			       tmpval);
		return 1;
	} else
		return 0;
}

__attribute__((used)) static int stk_sensor_inb(struct stk_camera *dev, u8 reg, u8 *val)
{
	int i = 0;
	u8 tmpval = 0;

	if (stk_camera_write_reg(dev, STK_IIC_RX_INDEX, reg))
		return 1;
	if (stk_camera_write_reg(dev, STK_IIC_OP, STK_IIC_OP_RX))
		return 1;
	do {
		if (stk_camera_read_reg(dev, STK_IIC_STAT, &tmpval))
			return 1;
		i++;
	} while (tmpval == 0 && i < MAX_RETRIES);
	if (tmpval != STK_IIC_STAT_RX_OK) {
		if (tmpval)
			pr_err("stk_sensor_inb failed, status=0x%02x\n",
			       tmpval);
		return 1;
	}

	if (stk_camera_read_reg(dev, STK_IIC_RX_VALUE, &tmpval))
		return 1;

	*val = tmpval;
	return 0;
}

__attribute__((used)) static int stk_sensor_write_regvals(struct stk_camera *dev,
		struct regval *rv)
{
	int ret;
	if (rv == NULL)
		return 0;
	while (rv->reg != 0xff || rv->val != 0xff) {
		ret = stk_sensor_outb(dev, rv->reg, rv->val);
		if (ret != 0)
			return ret;
		rv++;
	}
	return 0;
}

int stk_sensor_sleep(struct stk_camera *dev)
{
	u8 tmp;
	return stk_sensor_inb(dev, REG_COM2, &tmp)
		|| stk_sensor_outb(dev, REG_COM2, tmp|COM2_SSLEEP);
}

int stk_sensor_wakeup(struct stk_camera *dev)
{
	u8 tmp;
	return stk_sensor_inb(dev, REG_COM2, &tmp)
		|| stk_sensor_outb(dev, REG_COM2, tmp&~COM2_SSLEEP);
}

int stk_sensor_init(struct stk_camera *dev)
{
	u8 idl = 0;
	u8 idh = 0;

	if (stk_camera_write_reg(dev, STK_IIC_ENABLE, STK_IIC_ENABLE_YES)
		|| stk_camera_write_reg(dev, STK_IIC_ADDR, SENSOR_ADDRESS)
		|| stk_sensor_outb(dev, REG_COM7, COM7_RESET)) {
		pr_err("Sensor resetting failed\n");
		return -ENODEV;
	}
	msleep(10);
	/* Read the manufacturer ID: ov = 0x7FA2 */
	if (stk_sensor_inb(dev, REG_MIDH, &idh)
	    || stk_sensor_inb(dev, REG_MIDL, &idl)) {
		pr_err("Strange error reading sensor ID\n");
		return -ENODEV;
	}
	if (idh != 0x7f || idl != 0xa2) {
		pr_err("Huh? you don't have a sensor from ovt\n");
		return -ENODEV;
	}
	if (stk_sensor_inb(dev, REG_PID, &idh)
	    || stk_sensor_inb(dev, REG_VER, &idl)) {
		pr_err("Could not read sensor model\n");
		return -ENODEV;
	}
	stk_sensor_write_regvals(dev, ov_initvals);
	msleep(10);
	pr_info("OmniVision sensor detected, id %02X%02X at address %x\n",
		idh, idl, SENSOR_ADDRESS);
	return 0;
}

__attribute__((used)) static int stk_sensor_set_hw(struct stk_camera *dev,
		int hstart, int hstop, int vstart, int vstop)
{
	int ret;
	unsigned char v;
/*
 * Horizontal: 11 bits, top 8 live in hstart and hstop.  Bottom 3 of
 * hstart are in href[2:0], bottom 3 of hstop in href[5:3].  There is
 * a mystery "edge offset" value in the top two bits of href.
 */
	ret =  stk_sensor_outb(dev, REG_HSTART, (hstart >> 3) & 0xff);
	ret += stk_sensor_outb(dev, REG_HSTOP, (hstop >> 3) & 0xff);
	ret += stk_sensor_inb(dev, REG_HREF, &v);
	v = (v & 0xc0) | ((hstop & 0x7) << 3) | (hstart & 0x7);
	msleep(10);
	ret += stk_sensor_outb(dev, REG_HREF, v);
/*
 * Vertical: similar arrangement (note: this is different from ov7670.c)
 */
	ret += stk_sensor_outb(dev, REG_VSTART, (vstart >> 3) & 0xff);
	ret += stk_sensor_outb(dev, REG_VSTOP, (vstop >> 3) & 0xff);
	ret += stk_sensor_inb(dev, REG_VREF, &v);
	v = (v & 0xc0) | ((vstop & 0x7) << 3) | (vstart & 0x7);
	msleep(10);
	ret += stk_sensor_outb(dev, REG_VREF, v);
	return ret;
}

int stk_sensor_configure(struct stk_camera *dev)
{
	int com7;
	/*
	 * We setup the sensor to output dummy lines in low-res modes,
	 * so we don't get absurdly hight framerates.
	 */
	unsigned dummylines;
	int flip;
	struct regval *rv;

	switch (dev->vsettings.mode) {
	case MODE_QCIF: com7 = COM7_FMT_QCIF;
		dummylines = 604;
		break;
	case MODE_QVGA: com7 = COM7_FMT_QVGA;
		dummylines = 267;
		break;
	case MODE_CIF: com7 = COM7_FMT_CIF;
		dummylines = 412;
		break;
	case MODE_VGA: com7 = COM7_FMT_VGA;
		dummylines = 11;
		break;
	case MODE_SXGA: com7 = COM7_FMT_SXGA;
		dummylines = 0;
		break;
	default:
		pr_err("Unsupported mode %d\n", dev->vsettings.mode);
		return -EFAULT;
	}
	switch (dev->vsettings.palette) {
	case V4L2_PIX_FMT_UYVY:
		com7 |= COM7_YUV;
		rv = ov_fmt_uyvy;
		break;
	case V4L2_PIX_FMT_YUYV:
		com7 |= COM7_YUV;
		rv = ov_fmt_yuyv;
		break;
	case V4L2_PIX_FMT_RGB565:
		com7 |= COM7_RGB;
		rv = ov_fmt_rgbp;
		break;
	case V4L2_PIX_FMT_RGB565X:
		com7 |= COM7_RGB;
		rv = ov_fmt_rgbr;
		break;
	case V4L2_PIX_FMT_SBGGR8:
		com7 |= COM7_PBAYER;
		rv = ov_fmt_bayer;
		break;
	default:
		pr_err("Unsupported colorspace\n");
		return -EFAULT;
	}
	/*FIXME sometimes the sensor go to a bad state
	stk_sensor_write_regvals(dev, ov_initvals); */
	stk_sensor_outb(dev, REG_COM7, com7);
	msleep(50);
	stk_sensor_write_regvals(dev, rv);
	flip = (dev->vsettings.vflip?MVFP_FLIP:0)
		| (dev->vsettings.hflip?MVFP_MIRROR:0);
	stk_sensor_outb(dev, REG_MVFP, flip);
	if (dev->vsettings.palette == V4L2_PIX_FMT_SBGGR8
			&& !dev->vsettings.vflip)
		stk_sensor_outb(dev, REG_TSLB, 0x08);
	stk_sensor_outb(dev, REG_ADVFH, dummylines >> 8);
	stk_sensor_outb(dev, REG_ADVFL, dummylines & 0xff);
	msleep(50);
	switch (dev->vsettings.mode) {
	case MODE_VGA:
		if (stk_sensor_set_hw(dev, 302, 1582, 6, 486))
			pr_err("stk_sensor_set_hw failed (VGA)\n");
		break;
	case MODE_SXGA:
	case MODE_CIF:
	case MODE_QVGA:
	case MODE_QCIF:
		/*FIXME These settings seem ignored by the sensor
		if (stk_sensor_set_hw(dev, 220, 1500, 10, 1034))
			pr_err("stk_sensor_set_hw failed (SXGA)\n");
		*/
		break;
	}
	msleep(10);
	return 0;
}

int stk_sensor_set_brightness(struct stk_camera *dev, int br)
{
	if (br < 0 || br > 0xff)
		return -EINVAL;
	stk_sensor_outb(dev, REG_AEB, max(0x00, br - 6));
	stk_sensor_outb(dev, REG_AEW, min(0xff, br + 6));
	return 0;
}

