#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct sk_buff {int len; int /*<<< orphan*/  data; } ;
struct s3fwrn5_info {int /*<<< orphan*/  phy_id; TYPE_1__* phy_ops; } ;
struct s3fwrn5_i2c_phy {int mode; int irq_skip; int /*<<< orphan*/  ndev; struct i2c_client* i2c_dev; void* gpio_fw_wake; void* gpio_en; int /*<<< orphan*/  mutex; } ;
struct s3fwrn5_fw_header {size_t len; } ;
struct nci_ctrl_hdr {size_t plen; } ;
struct i2c_device_id {int dummy; } ;
struct TYPE_7__ {struct device_node* of_node; } ;
struct i2c_client {int /*<<< orphan*/  irq; TYPE_2__ dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
typedef  enum s3fwrn5_mode { ____Placeholder_s3fwrn5_mode } s3fwrn5_mode ;
struct TYPE_6__ {int (* get_mode ) (int /*<<< orphan*/ ) ;int (* write ) (int /*<<< orphan*/ ,struct sk_buff*) ;int /*<<< orphan*/  (* set_wake ) (int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  (* set_mode ) (int /*<<< orphan*/ ,int) ;} ;

/* Variables and functions */
 int EBADMSG ; 
 int ENODEV ; 
 int ENOMEM ; 
 int ENOTSUPP ; 
 int EREMOTEIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_HIGH ; 
 int /*<<< orphan*/  GPIOF_OUT_INIT_LOW ; 
 int IRQF_ONESHOT ; 
 int IRQF_TRIGGER_HIGH ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NONE ; 
 size_t NCI_CTRL_HDR_SIZE ; 
 int S3FWRN5_EN_WAIT_TIME ; 
 size_t S3FWRN5_FW_HDR_SIZE ; 
 int /*<<< orphan*/  S3FWRN5_I2C_DRIVER_NAME ; 
 int /*<<< orphan*/  S3FWRN5_I2C_MAX_PAYLOAD ; 
#define  S3FWRN5_MODE_COLD 130 
#define  S3FWRN5_MODE_FW 129 
#define  S3FWRN5_MODE_NCI 128 
 int /*<<< orphan*/  WARN_ON_ONCE (int) ; 
 struct sk_buff* alloc_skb (size_t,int /*<<< orphan*/ ) ; 
 int devm_gpio_request_one (TYPE_2__*,void*,int /*<<< orphan*/ ,char*) ; 
 struct s3fwrn5_i2c_phy* devm_kzalloc (TYPE_2__*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int,int /*<<< orphan*/ ,struct s3fwrn5_i2c_phy*) ; 
 int /*<<< orphan*/  gpio_is_valid (void*) ; 
 int /*<<< orphan*/  gpio_set_value (void*,int) ; 
 struct s3fwrn5_i2c_phy* i2c_get_clientdata (struct i2c_client*) ; 
 int i2c_master_recv (struct i2c_client*,char*,size_t) ; 
 int i2c_master_send (struct i2c_client*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  i2c_phy_ops ; 
 int /*<<< orphan*/  i2c_set_clientdata (struct i2c_client*,struct s3fwrn5_i2c_phy*) ; 
 int /*<<< orphan*/  kfree_skb (struct sk_buff*) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 void* of_get_named_gpio (struct device_node*,char*,int /*<<< orphan*/ ) ; 
 int s3fwrn5_probe (int /*<<< orphan*/ *,struct s3fwrn5_i2c_phy*,TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int s3fwrn5_recv_frame (int /*<<< orphan*/ ,struct sk_buff*,int) ; 
 int /*<<< orphan*/  s3fwrn5_remove (int /*<<< orphan*/ ) ; 
 char* skb_put (struct sk_buff*,size_t) ; 
 int /*<<< orphan*/  skb_put_data (struct sk_buff*,char*,size_t) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,int) ; 
 int stub2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ,int) ; 
 int stub4 (int /*<<< orphan*/ ,struct sk_buff*) ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline int s3fwrn5_set_mode(struct s3fwrn5_info *info,
	enum s3fwrn5_mode mode)
{
	if (!info->phy_ops->set_mode)
		return -ENOTSUPP;

	info->phy_ops->set_mode(info->phy_id, mode);

	return 0;
}

__attribute__((used)) static inline enum s3fwrn5_mode s3fwrn5_get_mode(struct s3fwrn5_info *info)
{
	if (!info->phy_ops->get_mode)
		return -ENOTSUPP;

	return info->phy_ops->get_mode(info->phy_id);
}

__attribute__((used)) static inline int s3fwrn5_set_wake(struct s3fwrn5_info *info, bool wake)
{
	if (!info->phy_ops->set_wake)
		return -ENOTSUPP;

	info->phy_ops->set_wake(info->phy_id, wake);

	return 0;
}

__attribute__((used)) static inline int s3fwrn5_write(struct s3fwrn5_info *info, struct sk_buff *skb)
{
	if (!info->phy_ops->write)
		return -ENOTSUPP;

	return info->phy_ops->write(info->phy_id, skb);
}

__attribute__((used)) static void s3fwrn5_i2c_set_wake(void *phy_id, bool wake)
{
	struct s3fwrn5_i2c_phy *phy = phy_id;

	mutex_lock(&phy->mutex);
	gpio_set_value(phy->gpio_fw_wake, wake);
	msleep(S3FWRN5_EN_WAIT_TIME/2);
	mutex_unlock(&phy->mutex);
}

__attribute__((used)) static void s3fwrn5_i2c_set_mode(void *phy_id, enum s3fwrn5_mode mode)
{
	struct s3fwrn5_i2c_phy *phy = phy_id;

	mutex_lock(&phy->mutex);

	if (phy->mode == mode)
		goto out;

	phy->mode = mode;

	gpio_set_value(phy->gpio_en, 1);
	gpio_set_value(phy->gpio_fw_wake, 0);
	if (mode == S3FWRN5_MODE_FW)
		gpio_set_value(phy->gpio_fw_wake, 1);

	if (mode != S3FWRN5_MODE_COLD) {
		msleep(S3FWRN5_EN_WAIT_TIME);
		gpio_set_value(phy->gpio_en, 0);
		msleep(S3FWRN5_EN_WAIT_TIME/2);
	}

	phy->irq_skip = true;

out:
	mutex_unlock(&phy->mutex);
}

__attribute__((used)) static enum s3fwrn5_mode s3fwrn5_i2c_get_mode(void *phy_id)
{
	struct s3fwrn5_i2c_phy *phy = phy_id;
	enum s3fwrn5_mode mode;

	mutex_lock(&phy->mutex);

	mode = phy->mode;

	mutex_unlock(&phy->mutex);

	return mode;
}

__attribute__((used)) static int s3fwrn5_i2c_write(void *phy_id, struct sk_buff *skb)
{
	struct s3fwrn5_i2c_phy *phy = phy_id;
	int ret;

	mutex_lock(&phy->mutex);

	phy->irq_skip = false;

	ret = i2c_master_send(phy->i2c_dev, skb->data, skb->len);
	if (ret == -EREMOTEIO) {
		/* Retry, chip was in standby */
		usleep_range(110000, 120000);
		ret  = i2c_master_send(phy->i2c_dev, skb->data, skb->len);
	}

	mutex_unlock(&phy->mutex);

	if (ret < 0)
		return ret;

	if (ret != skb->len)
		return -EREMOTEIO;

	return 0;
}

__attribute__((used)) static int s3fwrn5_i2c_read(struct s3fwrn5_i2c_phy *phy)
{
	struct sk_buff *skb;
	size_t hdr_size;
	size_t data_len;
	char hdr[4];
	int ret;

	hdr_size = (phy->mode == S3FWRN5_MODE_NCI) ?
		NCI_CTRL_HDR_SIZE : S3FWRN5_FW_HDR_SIZE;
	ret = i2c_master_recv(phy->i2c_dev, hdr, hdr_size);
	if (ret < 0)
		return ret;

	if (ret < hdr_size)
		return -EBADMSG;

	data_len = (phy->mode == S3FWRN5_MODE_NCI) ?
		((struct nci_ctrl_hdr *)hdr)->plen :
		((struct s3fwrn5_fw_header *)hdr)->len;

	skb = alloc_skb(hdr_size + data_len, GFP_KERNEL);
	if (!skb)
		return -ENOMEM;

	skb_put_data(skb, hdr, hdr_size);

	if (data_len == 0)
		goto out;

	ret = i2c_master_recv(phy->i2c_dev, skb_put(skb, data_len), data_len);
	if (ret != data_len) {
		kfree_skb(skb);
		return -EBADMSG;
	}

out:
	return s3fwrn5_recv_frame(phy->ndev, skb, phy->mode);
}

__attribute__((used)) static irqreturn_t s3fwrn5_i2c_irq_thread_fn(int irq, void *phy_id)
{
	struct s3fwrn5_i2c_phy *phy = phy_id;
	int ret = 0;

	if (!phy || !phy->ndev) {
		WARN_ON_ONCE(1);
		return IRQ_NONE;
	}

	mutex_lock(&phy->mutex);

	if (phy->irq_skip)
		goto out;

	switch (phy->mode) {
	case S3FWRN5_MODE_NCI:
	case S3FWRN5_MODE_FW:
		ret = s3fwrn5_i2c_read(phy);
		break;
	case S3FWRN5_MODE_COLD:
		ret = -EREMOTEIO;
		break;
	}

out:
	mutex_unlock(&phy->mutex);

	return IRQ_HANDLED;
}

__attribute__((used)) static int s3fwrn5_i2c_parse_dt(struct i2c_client *client)
{
	struct s3fwrn5_i2c_phy *phy = i2c_get_clientdata(client);
	struct device_node *np = client->dev.of_node;

	if (!np)
		return -ENODEV;

	phy->gpio_en = of_get_named_gpio(np, "s3fwrn5,en-gpios", 0);
	if (!gpio_is_valid(phy->gpio_en))
		return -ENODEV;

	phy->gpio_fw_wake = of_get_named_gpio(np, "s3fwrn5,fw-gpios", 0);
	if (!gpio_is_valid(phy->gpio_fw_wake))
		return -ENODEV;

	return 0;
}

__attribute__((used)) static int s3fwrn5_i2c_probe(struct i2c_client *client,
				  const struct i2c_device_id *id)
{
	struct s3fwrn5_i2c_phy *phy;
	int ret;

	phy = devm_kzalloc(&client->dev, sizeof(*phy), GFP_KERNEL);
	if (!phy)
		return -ENOMEM;

	mutex_init(&phy->mutex);
	phy->mode = S3FWRN5_MODE_COLD;
	phy->irq_skip = true;

	phy->i2c_dev = client;
	i2c_set_clientdata(client, phy);

	ret = s3fwrn5_i2c_parse_dt(client);
	if (ret < 0)
		return ret;

	ret = devm_gpio_request_one(&phy->i2c_dev->dev, phy->gpio_en,
		GPIOF_OUT_INIT_HIGH, "s3fwrn5_en");
	if (ret < 0)
		return ret;

	ret = devm_gpio_request_one(&phy->i2c_dev->dev, phy->gpio_fw_wake,
		GPIOF_OUT_INIT_LOW, "s3fwrn5_fw_wake");
	if (ret < 0)
		return ret;

	ret = s3fwrn5_probe(&phy->ndev, phy, &phy->i2c_dev->dev, &i2c_phy_ops,
		S3FWRN5_I2C_MAX_PAYLOAD);
	if (ret < 0)
		return ret;

	ret = devm_request_threaded_irq(&client->dev, phy->i2c_dev->irq, NULL,
		s3fwrn5_i2c_irq_thread_fn, IRQF_TRIGGER_HIGH | IRQF_ONESHOT,
		S3FWRN5_I2C_DRIVER_NAME, phy);
	if (ret)
		s3fwrn5_remove(phy->ndev);

	return ret;
}

__attribute__((used)) static int s3fwrn5_i2c_remove(struct i2c_client *client)
{
	struct s3fwrn5_i2c_phy *phy = i2c_get_clientdata(client);

	s3fwrn5_remove(phy->ndev);

	return 0;
}

