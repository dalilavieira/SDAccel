#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u32 ;
struct resource {int dummy; } ;
struct TYPE_11__ {int /*<<< orphan*/  of_node; } ;
struct platform_device {char const* name; TYPE_2__ dev; } ;
struct i2c_msg {int flags; int addr; int len; int* buf; } ;
struct TYPE_10__ {int /*<<< orphan*/  of_node; TYPE_2__* parent; } ;
struct i2c_adapter {TYPE_1__ dev; int /*<<< orphan*/ * algo; int /*<<< orphan*/  name; int /*<<< orphan*/  owner; } ;
struct bsc_regs {int ctl_reg; int iic_enable; unsigned char ctlhi_reg; } ;
struct brcmstb_i2c_dev {int data_regsz; scalar_t__ irq; int clk_freq_hz; struct i2c_adapter adapter; TYPE_2__* device; int /*<<< orphan*/  base; int /*<<< orphan*/  done; struct bsc_regs* bsc_regmap; scalar_t__ is_suspended; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum bsc_xfer_cmd { ____Placeholder_bsc_xfer_cmd } bsc_xfer_cmd ;
struct TYPE_12__ {int hz; int scl_mask; int div_mask; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_8__*) ; 
 int BITS_PER_BYTE ; 
 unsigned int BSC_CNT_REG1_MASK (int) ; 
 unsigned int BSC_CNT_REG1_SHIFT ; 
 unsigned char BSC_CTLHI_REG_DATAREG_SIZE_MASK ; 
 unsigned char BSC_CTLHI_REG_IGNORE_ACK_MASK ; 
 int BSC_CTL_REG_DIV_CLK_MASK ; 
 int BSC_CTL_REG_DTF_MASK ; 
 int BSC_CTL_REG_INT_EN_MASK ; 
 int BSC_CTL_REG_SCL_SEL_MASK ; 
 int BSC_CTL_REG_SCL_SEL_SHIFT ; 
 unsigned char BSC_IIC_EN_ENABLE_MASK ; 
 int BSC_IIC_EN_INTRP_MASK ; 
 int BSC_IIC_EN_NOACK_MASK ; 
 int CMD_RD ; 
 int CMD_RD_NOACK ; 
 int CMD_WR ; 
 int CMD_WR_NOACK ; 
 int COND_NOSTART ; 
 int COND_NOSTOP ; 
 int COND_RESTART ; 
 int COND_START_STOP ; 
 int DTF_RD_MASK ; 
 int DTF_WR_MASK ; 
 int EBUSY ; 
 int ENOMEM ; 
 int EREMOTEIO ; 
 int ETIMEDOUT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int I2C_FUNC_10BIT_ADDR ; 
 int I2C_FUNC_I2C ; 
 int I2C_FUNC_NOSTART ; 
 int I2C_FUNC_PROTOCOL_MANGLING ; 
 int I2C_FUNC_SMBUS_EMUL ; 
 int I2C_M_IGNORE_NAK ; 
 int I2C_M_NOSTART ; 
 int I2C_M_RD ; 
 int I2C_M_TEN ; 
 int /*<<< orphan*/  I2C_TIMEOUT ; 
 int INT_DISABLE ; 
 int INT_ENABLE ; 
 int /*<<< orphan*/  IORESOURCE_MEM ; 
 int /*<<< orphan*/  IRQF_SHARED ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int N_DATA_REGS ; 
 int /*<<< orphan*/  THIS_MODULE ; 
 int /*<<< orphan*/  barrier () ; 
 int /*<<< orphan*/  brcmstb_i2c_algo ; 
 TYPE_8__* bsc_clk ; 
 int bsc_readl (struct brcmstb_i2c_dev*,int /*<<< orphan*/ *****) ; 
 int /*<<< orphan*/  bsc_writel (struct brcmstb_i2c_dev*,unsigned char,int /*<<< orphan*/ *****) ; 
 int /*<<< orphan*/ ***** chip_address ; 
 int /*<<< orphan*/ * cmd_string ; 
 int /*<<< orphan*/ ***** cnt_reg ; 
 int /*<<< orphan*/  complete (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  cpu_relax () ; 
 int /*<<< orphan*/ ***** ctl_reg ; 
 int /*<<< orphan*/ ***** ctlhi_reg ; 
 int /*<<< orphan*/ ***** data_in ; 
 int /*<<< orphan*/ ****** data_out ; 
 int /*<<< orphan*/  dev_dbg (TYPE_2__*,char*,...) ; 
 int /*<<< orphan*/  dev_info (TYPE_2__*,char*,char const*,int,char*) ; 
 int /*<<< orphan*/  dev_warn (TYPE_2__*,char*,int) ; 
 int /*<<< orphan*/  devm_ioremap_resource (TYPE_2__*,struct resource*) ; 
 void* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_irq (TYPE_2__*,scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char const*,struct brcmstb_i2c_dev*) ; 
 unsigned char i2c_8bit_addr_from_msg (struct i2c_msg*) ; 
 int i2c_add_adapter (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_del_adapter (struct i2c_adapter*) ; 
 struct brcmstb_i2c_dev* i2c_get_adapdata (struct i2c_adapter*) ; 
 int /*<<< orphan*/  i2c_set_adapdata (struct i2c_adapter*,struct brcmstb_i2c_dev*) ; 
 int /*<<< orphan*/ ***** iic_enable ; 
 int /*<<< orphan*/  init_completion (int /*<<< orphan*/ *) ; 
 unsigned long jiffies ; 
 int min (int,int) ; 
 unsigned long msecs_to_jiffies (int /*<<< orphan*/ ) ; 
 scalar_t__ of_device_is_compatible (int /*<<< orphan*/ ,char*) ; 
 int of_property_read_string (int /*<<< orphan*/ ,char*,char const**) ; 
 scalar_t__ of_property_read_u32 (int /*<<< orphan*/ ,char*,int*) ; 
 struct brcmstb_i2c_dev* platform_get_drvdata (struct platform_device*) ; 
 scalar_t__ platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 struct resource* platform_get_resource (struct platform_device*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct brcmstb_i2c_dev*) ; 
 int /*<<< orphan*/  reinit_completion (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strlcat (int /*<<< orphan*/ ,char const*,int) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ time_after (unsigned long,unsigned long) ; 
 int /*<<< orphan*/  wait_for_completion_timeout (int /*<<< orphan*/ *,unsigned long) ; 

__attribute__((used)) static inline int brcmstb_i2c_get_xfersz(struct brcmstb_i2c_dev *dev)
{
	return (N_DATA_REGS * dev->data_regsz);
}

__attribute__((used)) static inline int brcmstb_i2c_get_data_regsz(struct brcmstb_i2c_dev *dev)
{
	return dev->data_regsz;
}

__attribute__((used)) static void brcmstb_i2c_enable_disable_irq(struct brcmstb_i2c_dev *dev,
					   bool int_en)
{

	if (int_en)
		/* Enable BSC  CTL interrupt line */
		dev->bsc_regmap->ctl_reg |= BSC_CTL_REG_INT_EN_MASK;
	else
		/* Disable BSC CTL interrupt line */
		dev->bsc_regmap->ctl_reg &= ~BSC_CTL_REG_INT_EN_MASK;

	barrier();
	bsc_writel(dev, dev->bsc_regmap->ctl_reg, ctl_reg);
}

__attribute__((used)) static irqreturn_t brcmstb_i2c_isr(int irq, void *devid)
{
	struct brcmstb_i2c_dev *dev = devid;
	u32 status_bsc_ctl = bsc_readl(dev, ctl_reg);
	u32 status_iic_intrp = bsc_readl(dev, iic_enable);

	dev_dbg(dev->device, "isr CTL_REG %x IIC_EN %x\n",
		status_bsc_ctl, status_iic_intrp);

	if (!(status_bsc_ctl & BSC_CTL_REG_INT_EN_MASK))
		return IRQ_NONE;

	brcmstb_i2c_enable_disable_irq(dev, INT_DISABLE);
	complete(&dev->done);

	dev_dbg(dev->device, "isr handled");
	return IRQ_HANDLED;
}

__attribute__((used)) static int brcmstb_i2c_wait_if_busy(struct brcmstb_i2c_dev *dev)
{
	unsigned long timeout = jiffies + msecs_to_jiffies(I2C_TIMEOUT);

	while ((bsc_readl(dev, iic_enable) & BSC_IIC_EN_INTRP_MASK)) {
		if (time_after(jiffies, timeout))
			return -ETIMEDOUT;
		cpu_relax();
	}
	return 0;
}

__attribute__((used)) static int brcmstb_i2c_wait_for_completion(struct brcmstb_i2c_dev *dev)
{
	int ret = 0;
	unsigned long timeout = msecs_to_jiffies(I2C_TIMEOUT);

	if (dev->irq >= 0) {
		if (!wait_for_completion_timeout(&dev->done, timeout))
			ret = -ETIMEDOUT;
	} else {
		/* we are in polling mode */
		u32 bsc_intrp;
		unsigned long time_left = jiffies + timeout;

		do {
			bsc_intrp = bsc_readl(dev, iic_enable) &
				BSC_IIC_EN_INTRP_MASK;
			if (time_after(jiffies, time_left)) {
				ret = -ETIMEDOUT;
				break;
			}
			cpu_relax();
		} while (!bsc_intrp);
	}

	if (dev->irq < 0 || ret == -ETIMEDOUT)
		brcmstb_i2c_enable_disable_irq(dev, INT_DISABLE);

	return ret;
}

__attribute__((used)) static void brcmstb_set_i2c_start_stop(struct brcmstb_i2c_dev *dev,
				       u32 cond_flag)
{
	u32 regval = dev->bsc_regmap->iic_enable;

	dev->bsc_regmap->iic_enable = (regval & ~COND_START_STOP) | cond_flag;
}

__attribute__((used)) static int brcmstb_send_i2c_cmd(struct brcmstb_i2c_dev *dev,
				enum bsc_xfer_cmd cmd)
{
	int rc = 0;
	struct bsc_regs *pi2creg = dev->bsc_regmap;

	/* Make sure the hardware is ready */
	rc = brcmstb_i2c_wait_if_busy(dev);
	if (rc < 0)
		return rc;

	/* only if we are in interrupt mode */
	if (dev->irq >= 0)
		reinit_completion(&dev->done);

	/* enable BSC CTL interrupt line */
	brcmstb_i2c_enable_disable_irq(dev, INT_ENABLE);

	/* initiate transfer by setting iic_enable */
	pi2creg->iic_enable |= BSC_IIC_EN_ENABLE_MASK;
	bsc_writel(dev, pi2creg->iic_enable, iic_enable);

	/* Wait for transaction to finish or timeout */
	rc = brcmstb_i2c_wait_for_completion(dev);
	if (rc) {
		dev_dbg(dev->device, "intr timeout for cmd %s\n",
			cmd_string[cmd]);
		goto cmd_out;
	}

	if ((CMD_RD || CMD_WR) &&
	    bsc_readl(dev, iic_enable) & BSC_IIC_EN_NOACK_MASK) {
		rc = -EREMOTEIO;
		dev_dbg(dev->device, "controller received NOACK intr for %s\n",
			cmd_string[cmd]);
	}

cmd_out:
	bsc_writel(dev, 0, cnt_reg);
	bsc_writel(dev, 0, iic_enable);

	return rc;
}

__attribute__((used)) static int brcmstb_i2c_xfer_bsc_data(struct brcmstb_i2c_dev *dev,
				     u8 *buf, unsigned int len,
				     struct i2c_msg *pmsg)
{
	int cnt, byte, i, rc;
	enum bsc_xfer_cmd cmd;
	u32 ctl_reg;
	struct bsc_regs *pi2creg = dev->bsc_regmap;
	int no_ack = pmsg->flags & I2C_M_IGNORE_NAK;
	int data_regsz = brcmstb_i2c_get_data_regsz(dev);

	/* see if the transaction needs to check NACK conditions */
	if (no_ack) {
		cmd = (pmsg->flags & I2C_M_RD) ? CMD_RD_NOACK
			: CMD_WR_NOACK;
		pi2creg->ctlhi_reg |= BSC_CTLHI_REG_IGNORE_ACK_MASK;
	} else {
		cmd = (pmsg->flags & I2C_M_RD) ? CMD_RD : CMD_WR;
		pi2creg->ctlhi_reg &= ~BSC_CTLHI_REG_IGNORE_ACK_MASK;
	}
	bsc_writel(dev, pi2creg->ctlhi_reg, ctlhi_reg);

	/* set data transfer direction */
	ctl_reg = pi2creg->ctl_reg & ~BSC_CTL_REG_DTF_MASK;
	if (cmd == CMD_WR || cmd == CMD_WR_NOACK)
		pi2creg->ctl_reg = ctl_reg | DTF_WR_MASK;
	else
		pi2creg->ctl_reg = ctl_reg | DTF_RD_MASK;

	/* set the read/write length */
	bsc_writel(dev, BSC_CNT_REG1_MASK(data_regsz) &
		   (len << BSC_CNT_REG1_SHIFT), cnt_reg);

	/* Write data into data_in register */

	if (cmd == CMD_WR || cmd == CMD_WR_NOACK) {
		for (cnt = 0, i = 0; cnt < len; cnt += data_regsz, i++) {
			u32 word = 0;

			for (byte = 0; byte < data_regsz; byte++) {
				word >>= BITS_PER_BYTE;
				if ((cnt + byte) < len)
					word |= buf[cnt + byte] <<
					(BITS_PER_BYTE * (data_regsz - 1));
			}
			bsc_writel(dev, word, data_in[i]);
		}
	}

	/* Initiate xfer, the function will return on completion */
	rc = brcmstb_send_i2c_cmd(dev, cmd);

	if (rc != 0) {
		dev_dbg(dev->device, "%s failure", cmd_string[cmd]);
		return rc;
	}

	/* Read data from data_out register */
	if (cmd == CMD_RD || cmd == CMD_RD_NOACK) {
		for (cnt = 0, i = 0; cnt < len; cnt += data_regsz, i++) {
			u32 data = bsc_readl(dev, data_out[i]);

			for (byte = 0; byte < data_regsz &&
				     (byte + cnt) < len; byte++) {
				buf[cnt + byte] = data & 0xff;
				data >>= BITS_PER_BYTE;
			}
		}
	}

	return 0;
}

__attribute__((used)) static int brcmstb_i2c_write_data_byte(struct brcmstb_i2c_dev *dev,
				       u8 *buf, unsigned int nak_expected)
{
	enum bsc_xfer_cmd cmd = nak_expected ? CMD_WR : CMD_WR_NOACK;

	bsc_writel(dev, 1, cnt_reg);
	bsc_writel(dev, *buf, data_in);

	return brcmstb_send_i2c_cmd(dev, cmd);
}

__attribute__((used)) static int brcmstb_i2c_do_addr(struct brcmstb_i2c_dev *dev,
			       struct i2c_msg *msg)
{
	unsigned char addr;

	if (msg->flags & I2C_M_TEN) {
		/* First byte is 11110XX0 where XX is upper 2 bits */
		addr = 0xF0 | ((msg->addr & 0x300) >> 7);
		bsc_writel(dev, addr, chip_address);

		/* Second byte is the remaining 8 bits */
		addr = msg->addr & 0xFF;
		if (brcmstb_i2c_write_data_byte(dev, &addr, 0) < 0)
			return -EREMOTEIO;

		if (msg->flags & I2C_M_RD) {
			/* For read, send restart without stop condition */
			brcmstb_set_i2c_start_stop(dev, COND_RESTART
						   | COND_NOSTOP);
			/* Then re-send the first byte with the read bit set */
			addr = 0xF0 | ((msg->addr & 0x300) >> 7) | 0x01;
			if (brcmstb_i2c_write_data_byte(dev, &addr, 0) < 0)
				return -EREMOTEIO;

		}
	} else {
		addr = i2c_8bit_addr_from_msg(msg);

		bsc_writel(dev, addr, chip_address);
	}

	return 0;
}

__attribute__((used)) static int brcmstb_i2c_xfer(struct i2c_adapter *adapter,
			    struct i2c_msg msgs[], int num)
{
	struct brcmstb_i2c_dev *dev = i2c_get_adapdata(adapter);
	struct i2c_msg *pmsg;
	int rc = 0;
	int i;
	int bytes_to_xfer;
	u8 *tmp_buf;
	int len = 0;
	int xfersz = brcmstb_i2c_get_xfersz(dev);
	u32 cond, cond_per_msg;

	if (dev->is_suspended)
		return -EBUSY;

	/* Loop through all messages */
	for (i = 0; i < num; i++) {
		pmsg = &msgs[i];
		len = pmsg->len;
		tmp_buf = pmsg->buf;

		dev_dbg(dev->device,
			"msg# %d/%d flg %x buf %x len %d\n", i,
			num - 1, pmsg->flags,
			pmsg->buf ? pmsg->buf[0] : '0', pmsg->len);

		if (i < (num - 1) && (msgs[i + 1].flags & I2C_M_NOSTART))
			cond = ~COND_START_STOP;
		else
			cond = COND_RESTART | COND_NOSTOP;

		brcmstb_set_i2c_start_stop(dev, cond);

		/* Send slave address */
		if (!(pmsg->flags & I2C_M_NOSTART)) {
			rc = brcmstb_i2c_do_addr(dev, pmsg);
			if (rc < 0) {
				dev_dbg(dev->device,
					"NACK for addr %2.2x msg#%d rc = %d\n",
					pmsg->addr, i, rc);
				goto out;
			}
		}

		cond_per_msg = cond;

		/* Perform data transfer */
		while (len) {
			bytes_to_xfer = min(len, xfersz);

			if (len <= xfersz) {
				if (i == (num - 1))
					cond_per_msg = cond_per_msg &
						~(COND_RESTART | COND_NOSTOP);
				else
					cond_per_msg = cond;
			} else {
				cond_per_msg = (cond_per_msg & ~COND_RESTART) |
					COND_NOSTOP;
			}

			brcmstb_set_i2c_start_stop(dev, cond_per_msg);

			rc = brcmstb_i2c_xfer_bsc_data(dev, tmp_buf,
						       bytes_to_xfer, pmsg);
			if (rc < 0)
				goto out;

			len -=  bytes_to_xfer;
			tmp_buf += bytes_to_xfer;

			cond_per_msg = COND_NOSTART | COND_NOSTOP;
		}
	}

	rc = num;
out:
	return rc;

}

__attribute__((used)) static u32 brcmstb_i2c_functionality(struct i2c_adapter *adap)
{
	return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR
		| I2C_FUNC_NOSTART | I2C_FUNC_PROTOCOL_MANGLING;
}

__attribute__((used)) static void brcmstb_i2c_set_bus_speed(struct brcmstb_i2c_dev *dev)
{
	int i = 0, num_speeds = ARRAY_SIZE(bsc_clk);
	u32 clk_freq_hz = dev->clk_freq_hz;

	for (i = 0; i < num_speeds; i++) {
		if (bsc_clk[i].hz == clk_freq_hz) {
			dev->bsc_regmap->ctl_reg &= ~(BSC_CTL_REG_SCL_SEL_MASK
						| BSC_CTL_REG_DIV_CLK_MASK);
			dev->bsc_regmap->ctl_reg |= (bsc_clk[i].scl_mask |
						     bsc_clk[i].div_mask);
			bsc_writel(dev, dev->bsc_regmap->ctl_reg, ctl_reg);
			break;
		}
	}

	/* in case we did not get find a valid speed */
	if (i == num_speeds) {
		i = (bsc_readl(dev, ctl_reg) & BSC_CTL_REG_SCL_SEL_MASK) >>
			BSC_CTL_REG_SCL_SEL_SHIFT;
		dev_warn(dev->device, "leaving current clock-frequency @ %dHz\n",
			bsc_clk[i].hz);
	}
}

__attribute__((used)) static void brcmstb_i2c_set_bsc_reg_defaults(struct brcmstb_i2c_dev *dev)
{
	if (brcmstb_i2c_get_data_regsz(dev) == sizeof(u32))
		/* set 4 byte data in/out xfers  */
		dev->bsc_regmap->ctlhi_reg = BSC_CTLHI_REG_DATAREG_SIZE_MASK;
	else
		dev->bsc_regmap->ctlhi_reg &= ~BSC_CTLHI_REG_DATAREG_SIZE_MASK;

	bsc_writel(dev, dev->bsc_regmap->ctlhi_reg, ctlhi_reg);
	/* set bus speed */
	brcmstb_i2c_set_bus_speed(dev);
}

__attribute__((used)) static int brcmstb_i2c_probe(struct platform_device *pdev)
{
	int rc = 0;
	struct brcmstb_i2c_dev *dev;
	struct i2c_adapter *adap;
	struct resource *iomem;
	const char *int_name;

	/* Allocate memory for private data structure */
	dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
	if (!dev)
		return -ENOMEM;

	dev->bsc_regmap = devm_kzalloc(&pdev->dev, sizeof(*dev->bsc_regmap), GFP_KERNEL);
	if (!dev->bsc_regmap)
		return -ENOMEM;

	platform_set_drvdata(pdev, dev);
	dev->device = &pdev->dev;
	init_completion(&dev->done);

	/* Map hardware registers */
	iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
	dev->base = devm_ioremap_resource(dev->device, iomem);
	if (IS_ERR(dev->base)) {
		rc = -ENOMEM;
		goto probe_errorout;
	}

	rc = of_property_read_string(dev->device->of_node, "interrupt-names",
				     &int_name);
	if (rc < 0)
		int_name = NULL;

	/* Get the interrupt number */
	dev->irq = platform_get_irq(pdev, 0);

	/* disable the bsc interrupt line */
	brcmstb_i2c_enable_disable_irq(dev, INT_DISABLE);

	/* register the ISR handler */
	rc = devm_request_irq(&pdev->dev, dev->irq, brcmstb_i2c_isr,
			      IRQF_SHARED,
			      int_name ? int_name : pdev->name,
			      dev);

	if (rc) {
		dev_dbg(dev->device, "falling back to polling mode");
		dev->irq = -1;
	}

	if (of_property_read_u32(dev->device->of_node,
				 "clock-frequency", &dev->clk_freq_hz)) {
		dev_warn(dev->device, "setting clock-frequency@%dHz\n",
			 bsc_clk[0].hz);
		dev->clk_freq_hz = bsc_clk[0].hz;
	}

	/* set the data in/out register size for compatible SoCs */
	if (of_device_is_compatible(dev->device->of_node,
				    "brcmstb,brcmper-i2c"))
		dev->data_regsz = sizeof(u8);
	else
		dev->data_regsz = sizeof(u32);

	brcmstb_i2c_set_bsc_reg_defaults(dev);

	/* Add the i2c adapter */
	adap = &dev->adapter;
	i2c_set_adapdata(adap, dev);
	adap->owner = THIS_MODULE;
	strlcpy(adap->name, "Broadcom STB : ", sizeof(adap->name));
	if (int_name)
		strlcat(adap->name, int_name, sizeof(adap->name));
	adap->algo = &brcmstb_i2c_algo;
	adap->dev.parent = &pdev->dev;
	adap->dev.of_node = pdev->dev.of_node;
	rc = i2c_add_adapter(adap);
	if (rc)
		goto probe_errorout;

	dev_info(dev->device, "%s@%dhz registered in %s mode\n",
		 int_name ? int_name : " ", dev->clk_freq_hz,
		 (dev->irq >= 0) ? "interrupt" : "polling");

	return 0;

probe_errorout:
	return rc;
}

__attribute__((used)) static int brcmstb_i2c_remove(struct platform_device *pdev)
{
	struct brcmstb_i2c_dev *dev = platform_get_drvdata(pdev);

	i2c_del_adapter(&dev->adapter);
	return 0;
}

