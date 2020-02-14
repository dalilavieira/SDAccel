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
typedef  int u32 ;
struct uniphier_tm_dev {int* alert_en; struct thermal_zone_device* tz_dev; struct thermal_zone_device* regmap; TYPE_1__* data; struct device* dev; } ;
struct thermal_zone_device {int dummy; } ;
struct thermal_trip {scalar_t__ type; int temperature; } ;
struct thermal_cooling_device {int dummy; } ;
typedef  struct thermal_zone_device regmap ;
struct device {int /*<<< orphan*/  of_node; } ;
struct platform_device {struct device dev; } ;
struct device_node {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {scalar_t__ map_base; scalar_t__ block_base; int /*<<< orphan*/  tmod_setup_addr; } ;

/* Variables and functions */
 int ALERT_CH_NUM ; 
 int /*<<< orphan*/  ARRAY_SIZE (int*) ; 
 int CRITICAL_TEMP_LIMIT ; 
 int E2BIG ; 
 int EINVAL ; 
 scalar_t__ EMONREPEAT ; 
 int EMONREPEAT_ENDLESS ; 
 int EMONREPEAT_PERIOD ; 
 int EMONREPEAT_PERIOD_1000000 ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int INT_MAX ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_WAKE_THREAD ; 
 scalar_t__ IS_ERR (struct thermal_zone_device*) ; 
 scalar_t__ PMALERTINTCTL ; 
 int PMALERTINTCTL_CLR (int) ; 
 int PMALERTINTCTL_EN (int) ; 
 int PMALERTINTCTL_MASK ; 
 int PMALERTINTCTL_SET (int) ; 
 int PTR_ERR (struct thermal_zone_device*) ; 
 scalar_t__ PVTCTLEN ; 
 int PVTCTLEN_EN ; 
 scalar_t__ PVTCTLMODE ; 
 int PVTCTLMODE_MASK ; 
 int PVTCTLMODE_TEMPMON ; 
 scalar_t__ PVTCTLSEL ; 
 int PVTCTLSEL_MASK ; 
 int PVTCTLSEL_MONITOR ; 
 scalar_t__ SETALERT0 ; 
 int SETALERT_EN ; 
 int SETALERT_TEMP_OVF ; 
 int SETALERT_TEMP_OVF_VALUE (int) ; 
 int /*<<< orphan*/  THERMAL_EVENT_UNSPECIFIED ; 
 scalar_t__ THERMAL_TRIP_CRITICAL ; 
 scalar_t__ TMOD ; 
 scalar_t__ TMODCOEF ; 
 int TMODSETUP0_EN ; 
 int TMODSETUP0_VAL (int) ; 
 int TMODSETUP1_EN ; 
 int TMODSETUP1_VAL (int) ; 
 scalar_t__ TMOD_WIDTH ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 struct uniphier_tm_dev* devm_kzalloc (struct device*,int,int /*<<< orphan*/ ) ; 
 int devm_request_threaded_irq (struct device*,int,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct uniphier_tm_dev*) ; 
 struct thermal_zone_device* devm_thermal_zone_of_sensor_register (struct device*,int /*<<< orphan*/ ,struct uniphier_tm_dev*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  disable_irq_nosync (int) ; 
 TYPE_1__* of_device_get_match_data (struct device*) ; 
 struct device_node* of_get_parent (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  of_node_put (struct device_node*) ; 
 int of_property_read_u32_array (int /*<<< orphan*/ ,char*,int*,int /*<<< orphan*/ ) ; 
 struct uniphier_tm_dev* platform_get_drvdata (struct platform_device*) ; 
 int platform_get_irq (struct platform_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  platform_set_drvdata (struct platform_device*,struct uniphier_tm_dev*) ; 
 int regmap_read (struct thermal_zone_device*,scalar_t__,int*) ; 
 int /*<<< orphan*/  regmap_write (struct thermal_zone_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  regmap_write_bits (struct thermal_zone_device*,scalar_t__,int,int) ; 
 int sign_extend32 (int,scalar_t__) ; 
 struct thermal_zone_device* syscon_node_to_regmap (struct device_node*) ; 
 int /*<<< orphan*/  thermal_zone_device_update (struct thermal_zone_device*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uniphier_of_thermal_ops ; 
 int /*<<< orphan*/  usleep_range (int,int) ; 

__attribute__((used)) static inline void
thermal_cooling_device_stats_update(struct thermal_cooling_device *cdev,
				    unsigned long new_state) {}

__attribute__((used)) static inline int thermal_gov_step_wise_register(void) { return 0; }

__attribute__((used)) static inline void thermal_gov_step_wise_unregister(void) {}

__attribute__((used)) static inline int thermal_gov_fair_share_register(void) { return 0; }

__attribute__((used)) static inline void thermal_gov_fair_share_unregister(void) {}

__attribute__((used)) static inline int thermal_gov_bang_bang_register(void) { return 0; }

__attribute__((used)) static inline void thermal_gov_bang_bang_unregister(void) {}

__attribute__((used)) static inline int thermal_gov_user_space_register(void) { return 0; }

__attribute__((used)) static inline void thermal_gov_user_space_unregister(void) {}

__attribute__((used)) static inline int thermal_gov_power_allocator_register(void) { return 0; }

__attribute__((used)) static inline void thermal_gov_power_allocator_unregister(void) {}

__attribute__((used)) static inline int of_parse_thermal_zones(void) { return 0; }

__attribute__((used)) static inline void of_thermal_destroy_zones(void) { }

__attribute__((used)) static inline int of_thermal_get_ntrips(struct thermal_zone_device *tz)
{
	return 0;
}

__attribute__((used)) static inline bool of_thermal_is_trip_valid(struct thermal_zone_device *tz,
					    int trip)
{
	return false;
}

__attribute__((used)) static inline const struct thermal_trip *
of_thermal_get_trip_points(struct thermal_zone_device *tz)
{
	return NULL;
}

__attribute__((used)) static int uniphier_tm_initialize_sensor(struct uniphier_tm_dev *tdev)
{
	struct regmap *map = tdev->regmap;
	u32 val;
	u32 tmod_calib[2];
	int ret;

	/* stop PVT */
	regmap_write_bits(map, tdev->data->block_base + PVTCTLEN,
			  PVTCTLEN_EN, 0);

	/*
	 * Since SoC has a calibrated value that was set in advance,
	 * TMODCOEF shows non-zero and PVT refers the value internally.
	 *
	 * If TMODCOEF shows zero, the boards don't have the calibrated
	 * value, and the driver has to set default value from DT.
	 */
	ret = regmap_read(map, tdev->data->map_base + TMODCOEF, &val);
	if (ret)
		return ret;
	if (!val) {
		/* look for the default values in DT */
		ret = of_property_read_u32_array(tdev->dev->of_node,
						 "socionext,tmod-calibration",
						 tmod_calib,
						 ARRAY_SIZE(tmod_calib));
		if (ret)
			return ret;

		regmap_write(map, tdev->data->tmod_setup_addr,
			TMODSETUP0_EN | TMODSETUP0_VAL(tmod_calib[0]) |
			TMODSETUP1_EN | TMODSETUP1_VAL(tmod_calib[1]));
	}

	/* select temperature mode */
	regmap_write_bits(map, tdev->data->block_base + PVTCTLMODE,
			  PVTCTLMODE_MASK, PVTCTLMODE_TEMPMON);

	/* set monitoring period */
	regmap_write_bits(map, tdev->data->block_base + EMONREPEAT,
			  EMONREPEAT_ENDLESS | EMONREPEAT_PERIOD,
			  EMONREPEAT_ENDLESS | EMONREPEAT_PERIOD_1000000);

	/* set monitor mode */
	regmap_write_bits(map, tdev->data->map_base + PVTCTLSEL,
			  PVTCTLSEL_MASK, PVTCTLSEL_MONITOR);

	return 0;
}

__attribute__((used)) static void uniphier_tm_set_alert(struct uniphier_tm_dev *tdev, u32 ch,
				  u32 temp)
{
	struct regmap *map = tdev->regmap;

	/* set alert temperature */
	regmap_write_bits(map, tdev->data->map_base + SETALERT0 + (ch << 2),
			  SETALERT_EN | SETALERT_TEMP_OVF,
			  SETALERT_EN |
			  SETALERT_TEMP_OVF_VALUE(temp / 1000));
}

__attribute__((used)) static void uniphier_tm_enable_sensor(struct uniphier_tm_dev *tdev)
{
	struct regmap *map = tdev->regmap;
	int i;
	u32 bits = 0;

	for (i = 0; i < ALERT_CH_NUM; i++)
		if (tdev->alert_en[i])
			bits |= PMALERTINTCTL_EN(i);

	/* enable alert interrupt */
	regmap_write_bits(map, tdev->data->map_base + PMALERTINTCTL,
			  PMALERTINTCTL_MASK, bits);

	/* start PVT */
	regmap_write_bits(map, tdev->data->block_base + PVTCTLEN,
			  PVTCTLEN_EN, PVTCTLEN_EN);

	usleep_range(700, 1500);	/* The spec note says at least 700us */
}

__attribute__((used)) static void uniphier_tm_disable_sensor(struct uniphier_tm_dev *tdev)
{
	struct regmap *map = tdev->regmap;

	/* disable alert interrupt */
	regmap_write_bits(map, tdev->data->map_base + PMALERTINTCTL,
			  PMALERTINTCTL_MASK, 0);

	/* stop PVT */
	regmap_write_bits(map, tdev->data->block_base + PVTCTLEN,
			  PVTCTLEN_EN, 0);

	usleep_range(1000, 2000);	/* The spec note says at least 1ms */
}

__attribute__((used)) static int uniphier_tm_get_temp(void *data, int *out_temp)
{
	struct uniphier_tm_dev *tdev = data;
	struct regmap *map = tdev->regmap;
	int ret;
	u32 temp;

	ret = regmap_read(map, tdev->data->map_base + TMOD, &temp);
	if (ret)
		return ret;

	/* MSB of the TMOD field is a sign bit */
	*out_temp = sign_extend32(temp, TMOD_WIDTH - 1) * 1000;

	return 0;
}

__attribute__((used)) static void uniphier_tm_irq_clear(struct uniphier_tm_dev *tdev)
{
	u32 mask = 0, bits = 0;
	int i;

	for (i = 0; i < ALERT_CH_NUM; i++) {
		mask |= (PMALERTINTCTL_CLR(i) | PMALERTINTCTL_SET(i));
		bits |= PMALERTINTCTL_CLR(i);
	}

	/* clear alert interrupt */
	regmap_write_bits(tdev->regmap,
			  tdev->data->map_base + PMALERTINTCTL, mask, bits);
}

__attribute__((used)) static irqreturn_t uniphier_tm_alarm_irq(int irq, void *_tdev)
{
	struct uniphier_tm_dev *tdev = _tdev;

	disable_irq_nosync(irq);
	uniphier_tm_irq_clear(tdev);

	return IRQ_WAKE_THREAD;
}

__attribute__((used)) static irqreturn_t uniphier_tm_alarm_irq_thread(int irq, void *_tdev)
{
	struct uniphier_tm_dev *tdev = _tdev;

	thermal_zone_device_update(tdev->tz_dev, THERMAL_EVENT_UNSPECIFIED);

	return IRQ_HANDLED;
}

__attribute__((used)) static int uniphier_tm_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct regmap *regmap;
	struct device_node *parent;
	struct uniphier_tm_dev *tdev;
	const struct thermal_trip *trips;
	int i, ret, irq, ntrips, crit_temp = INT_MAX;

	tdev = devm_kzalloc(dev, sizeof(*tdev), GFP_KERNEL);
	if (!tdev)
		return -ENOMEM;
	tdev->dev = dev;

	tdev->data = of_device_get_match_data(dev);
	if (WARN_ON(!tdev->data))
		return -EINVAL;

	irq = platform_get_irq(pdev, 0);
	if (irq < 0)
		return irq;

	/* get regmap from syscon node */
	parent = of_get_parent(dev->of_node); /* parent should be syscon node */
	regmap = syscon_node_to_regmap(parent);
	of_node_put(parent);
	if (IS_ERR(regmap)) {
		dev_err(dev, "failed to get regmap (error %ld)\n",
			PTR_ERR(regmap));
		return PTR_ERR(regmap);
	}
	tdev->regmap = regmap;

	ret = uniphier_tm_initialize_sensor(tdev);
	if (ret) {
		dev_err(dev, "failed to initialize sensor\n");
		return ret;
	}

	ret = devm_request_threaded_irq(dev, irq, uniphier_tm_alarm_irq,
					uniphier_tm_alarm_irq_thread,
					0, "thermal", tdev);
	if (ret)
		return ret;

	platform_set_drvdata(pdev, tdev);

	tdev->tz_dev = devm_thermal_zone_of_sensor_register(dev, 0, tdev,
						&uniphier_of_thermal_ops);
	if (IS_ERR(tdev->tz_dev)) {
		dev_err(dev, "failed to register sensor device\n");
		return PTR_ERR(tdev->tz_dev);
	}

	/* get trip points */
	trips = of_thermal_get_trip_points(tdev->tz_dev);
	ntrips = of_thermal_get_ntrips(tdev->tz_dev);
	if (ntrips > ALERT_CH_NUM) {
		dev_err(dev, "thermal zone has too many trips\n");
		return -E2BIG;
	}

	/* set alert temperatures */
	for (i = 0; i < ntrips; i++) {
		if (trips[i].type == THERMAL_TRIP_CRITICAL &&
		    trips[i].temperature < crit_temp)
			crit_temp = trips[i].temperature;
		uniphier_tm_set_alert(tdev, i, trips[i].temperature);
		tdev->alert_en[i] = true;
	}
	if (crit_temp > CRITICAL_TEMP_LIMIT) {
		dev_err(dev, "critical trip is over limit(>%d), or not set\n",
			CRITICAL_TEMP_LIMIT);
		return -EINVAL;
	}

	uniphier_tm_enable_sensor(tdev);

	return 0;
}

__attribute__((used)) static int uniphier_tm_remove(struct platform_device *pdev)
{
	struct uniphier_tm_dev *tdev = platform_get_drvdata(pdev);

	/* disable sensor */
	uniphier_tm_disable_sensor(tdev);

	return 0;
}

