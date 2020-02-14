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
typedef  int u32 ;
struct pwm_device {scalar_t__ hwpwm; } ;
struct pwm_chip {int base; scalar_t__ npwm; int /*<<< orphan*/ * ops; int /*<<< orphan*/ * dev; } ;
struct gbphy_device_id {int dummy; } ;
struct gbphy_device {int /*<<< orphan*/  dev; TYPE_1__* cport_desc; int /*<<< orphan*/  bundle; } ;
struct gb_pwm_polarity_request {scalar_t__ which; scalar_t__ polarity; void* period; void* duty; } ;
struct gb_pwm_enable_request {scalar_t__ which; scalar_t__ polarity; void* period; void* duty; } ;
struct gb_pwm_disable_request {scalar_t__ which; scalar_t__ polarity; void* period; void* duty; } ;
struct gb_pwm_deactivate_request {scalar_t__ which; scalar_t__ polarity; void* period; void* duty; } ;
struct gb_pwm_count_response {scalar_t__ count; } ;
struct gb_pwm_config_request {scalar_t__ which; scalar_t__ polarity; void* period; void* duty; } ;
struct gb_pwm_chip {scalar_t__ pwm_max; struct pwm_chip chip; struct gb_connection* connection; } ;
struct gb_pwm_activate_request {scalar_t__ which; scalar_t__ polarity; void* period; void* duty; } ;
struct gb_connection {int dummy; } ;
typedef  int /*<<< orphan*/  response ;
typedef  int /*<<< orphan*/  request ;
typedef  enum pwm_polarity { ____Placeholder_pwm_polarity } pwm_polarity ;
struct TYPE_2__ {int /*<<< orphan*/  id; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GB_PWM_TYPE_ACTIVATE ; 
 int /*<<< orphan*/  GB_PWM_TYPE_CONFIG ; 
 int /*<<< orphan*/  GB_PWM_TYPE_DEACTIVATE ; 
 int /*<<< orphan*/  GB_PWM_TYPE_DISABLE ; 
 int /*<<< orphan*/  GB_PWM_TYPE_ENABLE ; 
 int /*<<< orphan*/  GB_PWM_TYPE_POLARITY ; 
 int /*<<< orphan*/  GB_PWM_TYPE_PWM_COUNT ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ IS_ERR (struct gb_connection*) ; 
 int PTR_ERR (struct gb_connection*) ; 
 void* cpu_to_le32 (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 void* dev_get_drvdata (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_set_drvdata (int /*<<< orphan*/ *,void*) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 struct gb_connection* gb_connection_create (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gb_connection_destroy (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_disable (struct gb_connection*) ; 
 int gb_connection_enable (struct gb_connection*) ; 
 int /*<<< orphan*/  gb_connection_set_data (struct gb_connection*,struct gb_pwm_chip*) ; 
 int gb_operation_sync (struct gb_connection*,int /*<<< orphan*/ ,struct gb_pwm_polarity_request*,int,struct gb_pwm_count_response*,int) ; 
 int /*<<< orphan*/  gb_pwm_ops ; 
 int /*<<< orphan*/  kfree (struct gb_pwm_chip*) ; 
 struct gb_pwm_chip* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 struct gb_pwm_chip* pwm_chip_to_gb_pwm_chip (struct pwm_chip*) ; 
 scalar_t__ pwm_is_enabled (struct pwm_device*) ; 
 int pwmchip_add (struct pwm_chip*) ; 
 int /*<<< orphan*/  pwmchip_remove (struct pwm_chip*) ; 
 struct gbphy_device* to_gbphy_dev (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void *gb_gbphy_get_data(struct gbphy_device *gdev)
{
	return dev_get_drvdata(&gdev->dev);
}

__attribute__((used)) static inline void gb_gbphy_set_data(struct gbphy_device *gdev, void *data)
{
	dev_set_drvdata(&gdev->dev, data);
}

__attribute__((used)) static inline int gbphy_runtime_get_sync(struct gbphy_device *gbphy_dev) { return 0; }

__attribute__((used)) static inline void gbphy_runtime_put_autosuspend(struct gbphy_device *gbphy_dev) {}

__attribute__((used)) static inline void gbphy_runtime_get_noresume(struct gbphy_device *gbphy_dev) {}

__attribute__((used)) static inline void gbphy_runtime_put_noidle(struct gbphy_device *gbphy_dev) {}

__attribute__((used)) static int gb_pwm_count_operation(struct gb_pwm_chip *pwmc)
{
	struct gb_pwm_count_response response;
	int ret;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_PWM_COUNT,
				NULL, 0, &response, sizeof(response));
	if (ret)
		return ret;
	pwmc->pwm_max = response.count;
	return 0;
}

__attribute__((used)) static int gb_pwm_activate_operation(struct gb_pwm_chip *pwmc,
				     u8 which)
{
	struct gb_pwm_activate_request request;
	struct gbphy_device *gbphy_dev;
	int ret;

	if (which > pwmc->pwm_max)
		return -EINVAL;

	request.which = which;

	gbphy_dev = to_gbphy_dev(pwmc->chip.dev);
	ret = gbphy_runtime_get_sync(gbphy_dev);
	if (ret)
		return ret;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_ACTIVATE,
				&request, sizeof(request), NULL, 0);

	gbphy_runtime_put_autosuspend(gbphy_dev);

	return ret;
}

__attribute__((used)) static int gb_pwm_deactivate_operation(struct gb_pwm_chip *pwmc,
				       u8 which)
{
	struct gb_pwm_deactivate_request request;
	struct gbphy_device *gbphy_dev;
	int ret;

	if (which > pwmc->pwm_max)
		return -EINVAL;

	request.which = which;

	gbphy_dev = to_gbphy_dev(pwmc->chip.dev);
	ret = gbphy_runtime_get_sync(gbphy_dev);
	if (ret)
		return ret;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_DEACTIVATE,
				&request, sizeof(request), NULL, 0);

	gbphy_runtime_put_autosuspend(gbphy_dev);

	return ret;
}

__attribute__((used)) static int gb_pwm_config_operation(struct gb_pwm_chip *pwmc,
				   u8 which, u32 duty, u32 period)
{
	struct gb_pwm_config_request request;
	struct gbphy_device *gbphy_dev;
	int ret;

	if (which > pwmc->pwm_max)
		return -EINVAL;

	request.which = which;
	request.duty = cpu_to_le32(duty);
	request.period = cpu_to_le32(period);

	gbphy_dev = to_gbphy_dev(pwmc->chip.dev);
	ret = gbphy_runtime_get_sync(gbphy_dev);
	if (ret)
		return ret;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_CONFIG,
				&request, sizeof(request), NULL, 0);

	gbphy_runtime_put_autosuspend(gbphy_dev);

	return ret;
}

__attribute__((used)) static int gb_pwm_set_polarity_operation(struct gb_pwm_chip *pwmc,
					 u8 which, u8 polarity)
{
	struct gb_pwm_polarity_request request;
	struct gbphy_device *gbphy_dev;
	int ret;

	if (which > pwmc->pwm_max)
		return -EINVAL;

	request.which = which;
	request.polarity = polarity;

	gbphy_dev = to_gbphy_dev(pwmc->chip.dev);
	ret = gbphy_runtime_get_sync(gbphy_dev);
	if (ret)
		return ret;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_POLARITY,
				&request, sizeof(request), NULL, 0);

	gbphy_runtime_put_autosuspend(gbphy_dev);

	return ret;
}

__attribute__((used)) static int gb_pwm_enable_operation(struct gb_pwm_chip *pwmc,
				   u8 which)
{
	struct gb_pwm_enable_request request;
	struct gbphy_device *gbphy_dev;
	int ret;

	if (which > pwmc->pwm_max)
		return -EINVAL;

	request.which = which;

	gbphy_dev = to_gbphy_dev(pwmc->chip.dev);
	ret = gbphy_runtime_get_sync(gbphy_dev);
	if (ret)
		return ret;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_ENABLE,
				&request, sizeof(request), NULL, 0);
	if (ret)
		gbphy_runtime_put_autosuspend(gbphy_dev);

	return ret;
}

__attribute__((used)) static int gb_pwm_disable_operation(struct gb_pwm_chip *pwmc,
				    u8 which)
{
	struct gb_pwm_disable_request request;
	struct gbphy_device *gbphy_dev;
	int ret;

	if (which > pwmc->pwm_max)
		return -EINVAL;

	request.which = which;

	ret = gb_operation_sync(pwmc->connection, GB_PWM_TYPE_DISABLE,
				&request, sizeof(request), NULL, 0);

	gbphy_dev = to_gbphy_dev(pwmc->chip.dev);
	gbphy_runtime_put_autosuspend(gbphy_dev);

	return ret;
}

__attribute__((used)) static int gb_pwm_request(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct gb_pwm_chip *pwmc = pwm_chip_to_gb_pwm_chip(chip);

	return gb_pwm_activate_operation(pwmc, pwm->hwpwm);
}

__attribute__((used)) static void gb_pwm_free(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct gb_pwm_chip *pwmc = pwm_chip_to_gb_pwm_chip(chip);

	if (pwm_is_enabled(pwm))
		dev_warn(chip->dev, "freeing PWM device without disabling\n");

	gb_pwm_deactivate_operation(pwmc, pwm->hwpwm);
}

__attribute__((used)) static int gb_pwm_config(struct pwm_chip *chip, struct pwm_device *pwm,
			 int duty_ns, int period_ns)
{
	struct gb_pwm_chip *pwmc = pwm_chip_to_gb_pwm_chip(chip);

	return gb_pwm_config_operation(pwmc, pwm->hwpwm, duty_ns, period_ns);
}

__attribute__((used)) static int gb_pwm_set_polarity(struct pwm_chip *chip, struct pwm_device *pwm,
			       enum pwm_polarity polarity)
{
	struct gb_pwm_chip *pwmc = pwm_chip_to_gb_pwm_chip(chip);

	return gb_pwm_set_polarity_operation(pwmc, pwm->hwpwm, polarity);
}

__attribute__((used)) static int gb_pwm_enable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct gb_pwm_chip *pwmc = pwm_chip_to_gb_pwm_chip(chip);

	return gb_pwm_enable_operation(pwmc, pwm->hwpwm);
}

__attribute__((used)) static void gb_pwm_disable(struct pwm_chip *chip, struct pwm_device *pwm)
{
	struct gb_pwm_chip *pwmc = pwm_chip_to_gb_pwm_chip(chip);

	gb_pwm_disable_operation(pwmc, pwm->hwpwm);
}

__attribute__((used)) static int gb_pwm_probe(struct gbphy_device *gbphy_dev,
			const struct gbphy_device_id *id)
{
	struct gb_connection *connection;
	struct gb_pwm_chip *pwmc;
	struct pwm_chip *pwm;
	int ret;

	pwmc = kzalloc(sizeof(*pwmc), GFP_KERNEL);
	if (!pwmc)
		return -ENOMEM;

	connection = gb_connection_create(gbphy_dev->bundle,
					  le16_to_cpu(gbphy_dev->cport_desc->id),
					  NULL);
	if (IS_ERR(connection)) {
		ret = PTR_ERR(connection);
		goto exit_pwmc_free;
	}

	pwmc->connection = connection;
	gb_connection_set_data(connection, pwmc);
	gb_gbphy_set_data(gbphy_dev, pwmc);

	ret = gb_connection_enable(connection);
	if (ret)
		goto exit_connection_destroy;

	/* Query number of pwms present */
	ret = gb_pwm_count_operation(pwmc);
	if (ret)
		goto exit_connection_disable;

	pwm = &pwmc->chip;

	pwm->dev = &gbphy_dev->dev;
	pwm->ops = &gb_pwm_ops;
	pwm->base = -1;			/* Allocate base dynamically */
	pwm->npwm = pwmc->pwm_max + 1;

	ret = pwmchip_add(pwm);
	if (ret) {
		dev_err(&gbphy_dev->dev,
			"failed to register PWM: %d\n", ret);
		goto exit_connection_disable;
	}

	gbphy_runtime_put_autosuspend(gbphy_dev);
	return 0;

exit_connection_disable:
	gb_connection_disable(connection);
exit_connection_destroy:
	gb_connection_destroy(connection);
exit_pwmc_free:
	kfree(pwmc);
	return ret;
}

__attribute__((used)) static void gb_pwm_remove(struct gbphy_device *gbphy_dev)
{
	struct gb_pwm_chip *pwmc = gb_gbphy_get_data(gbphy_dev);
	struct gb_connection *connection = pwmc->connection;
	int ret;

	ret = gbphy_runtime_get_sync(gbphy_dev);
	if (ret)
		gbphy_runtime_get_noresume(gbphy_dev);

	pwmchip_remove(&pwmc->chip);
	gb_connection_disable(connection);
	gb_connection_destroy(connection);
	kfree(pwmc);
}

