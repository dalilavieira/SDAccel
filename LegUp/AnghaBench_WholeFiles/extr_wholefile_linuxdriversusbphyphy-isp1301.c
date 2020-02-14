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
typedef  int u8 ;
struct usb_phy {int (* init ) (struct usb_phy*) ;int (* set_vbus ) (struct usb_phy*,int) ;int /*<<< orphan*/  type; int /*<<< orphan*/  label; int /*<<< orphan*/ * dev; } ;
struct isp1301 {struct usb_phy phy; int /*<<< orphan*/  mutex; struct i2c_client* client; } ;
struct i2c_device_id {int dummy; } ;
struct i2c_client {int /*<<< orphan*/  dev; } ;
struct device_node {int dummy; } ;
struct device {int /*<<< orphan*/ * driver; struct device_node* of_node; } ;
struct TYPE_2__ {int /*<<< orphan*/  driver; } ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_NAME ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int ISP1301_I2C_INTERRUPT_FALLING ; 
 int ISP1301_I2C_INTERRUPT_LATCH ; 
 int ISP1301_I2C_INTERRUPT_RISING ; 
 int ISP1301_I2C_MODE_CONTROL_1 ; 
 int ISP1301_I2C_MODE_CONTROL_2 ; 
 int ISP1301_I2C_OTG_CONTROL_1 ; 
 int ISP1301_I2C_REG_CLEAR_ADDR ; 
 int MC1_DAT_SE0 ; 
 int MC1_SPEED_REG ; 
 int MC1_UART_EN ; 
 int MC2_BI_DI ; 
 int MC2_PSW_EN ; 
 int MC2_SPD_SUSP_CTRL ; 
 int OTG1_DM_PULLDOWN ; 
 int OTG1_DM_PULLUP ; 
 int OTG1_DP_PULLDOWN ; 
 int OTG1_DP_PULLUP ; 
 int OTG1_VBUS_DRV ; 
 int /*<<< orphan*/  USB_PHY_TYPE_USB2 ; 
 struct device* bus_find_device (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct device_node*,int (*) (struct device*,void*)) ; 
 struct isp1301* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  i2c_bus_type ; 
 struct isp1301* i2c_get_clientdata (struct i2c_client*) ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct isp1301*) ; 
 int i2c_smbus_write_byte_data (struct i2c_client*,int,int) ; 
 TYPE_1__ isp1301_driver ; 
 struct i2c_client* isp1301_i2c_client ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 struct isp1301* phy_to_isp (struct usb_phy*) ; 
 struct i2c_client* to_i2c_client (struct device*) ; 
 int /*<<< orphan*/  usb_add_phy_dev (struct usb_phy*) ; 
 int /*<<< orphan*/  usb_remove_phy (struct usb_phy*) ; 

__attribute__((used)) static int __isp1301_write(struct isp1301 *isp, u8 reg, u8 value, u8 clear)
{
	return i2c_smbus_write_byte_data(isp->client, reg | clear, value);
}

__attribute__((used)) static int isp1301_write(struct isp1301 *isp, u8 reg, u8 value)
{
	return __isp1301_write(isp, reg, value, 0);
}

__attribute__((used)) static int isp1301_clear(struct isp1301 *isp, u8 reg, u8 value)
{
	return __isp1301_write(isp, reg, value, ISP1301_I2C_REG_CLEAR_ADDR);
}

__attribute__((used)) static int isp1301_phy_init(struct usb_phy *phy)
{
	struct isp1301 *isp = phy_to_isp(phy);

	/* Disable transparent UART mode first */
	isp1301_clear(isp, ISP1301_I2C_MODE_CONTROL_1, MC1_UART_EN);
	isp1301_clear(isp, ISP1301_I2C_MODE_CONTROL_1, ~MC1_SPEED_REG);
	isp1301_write(isp, ISP1301_I2C_MODE_CONTROL_1, MC1_SPEED_REG);
	isp1301_clear(isp, ISP1301_I2C_MODE_CONTROL_2, ~0);
	isp1301_write(isp, ISP1301_I2C_MODE_CONTROL_2, (MC2_BI_DI | MC2_PSW_EN
				| MC2_SPD_SUSP_CTRL));

	isp1301_clear(isp, ISP1301_I2C_OTG_CONTROL_1, ~0);
	isp1301_write(isp, ISP1301_I2C_MODE_CONTROL_1, MC1_DAT_SE0);
	isp1301_write(isp, ISP1301_I2C_OTG_CONTROL_1, (OTG1_DM_PULLDOWN
				| OTG1_DP_PULLDOWN));
	isp1301_clear(isp, ISP1301_I2C_OTG_CONTROL_1, (OTG1_DM_PULLUP
				| OTG1_DP_PULLUP));

	/* mask all interrupts */
	isp1301_clear(isp, ISP1301_I2C_INTERRUPT_LATCH, ~0);
	isp1301_clear(isp, ISP1301_I2C_INTERRUPT_FALLING, ~0);
	isp1301_clear(isp, ISP1301_I2C_INTERRUPT_RISING, ~0);

	return 0;
}

__attribute__((used)) static int isp1301_phy_set_vbus(struct usb_phy *phy, int on)
{
	struct isp1301 *isp = phy_to_isp(phy);

	if (on)
		isp1301_write(isp, ISP1301_I2C_OTG_CONTROL_1, OTG1_VBUS_DRV);
	else
		isp1301_clear(isp, ISP1301_I2C_OTG_CONTROL_1, OTG1_VBUS_DRV);

	return 0;
}

__attribute__((used)) static int isp1301_probe(struct i2c_client *client,
			 const struct i2c_device_id *i2c_id)
{
	struct isp1301 *isp;
	struct usb_phy *phy;

	isp = devm_kzalloc(&client->dev, sizeof(*isp), GFP_KERNEL);
	if (!isp)
		return -ENOMEM;

	isp->client = client;
	mutex_init(&isp->mutex);

	phy = &isp->phy;
	phy->dev = &client->dev;
	phy->label = DRV_NAME;
	phy->init = isp1301_phy_init;
	phy->set_vbus = isp1301_phy_set_vbus;
	phy->type = USB_PHY_TYPE_USB2;

	i2c_set_clientdata(client, isp);
	usb_add_phy_dev(phy);

	isp1301_i2c_client = client;

	return 0;
}

__attribute__((used)) static int isp1301_remove(struct i2c_client *client)
{
	struct isp1301 *isp = i2c_get_clientdata(client);

	usb_remove_phy(&isp->phy);
	isp1301_i2c_client = NULL;

	return 0;
}

__attribute__((used)) static int match(struct device *dev, void *data)
{
	struct device_node *node = (struct device_node *)data;
	return (dev->of_node == node) &&
		(dev->driver == &isp1301_driver.driver);
}

struct i2c_client *isp1301_get_client(struct device_node *node)
{
	if (node) { /* reference of ISP1301 I2C node via DT */
		struct device *dev = bus_find_device(&i2c_bus_type, NULL,
						     node, match);
		if (!dev)
			return NULL;
		return to_i2c_client(dev);
	} else { /* non-DT: only one ISP1301 chip supported */
		return isp1301_i2c_client;
	}
}

