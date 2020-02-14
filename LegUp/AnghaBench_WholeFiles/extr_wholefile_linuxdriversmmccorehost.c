#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct timer_list {int dummy; } ;
struct mmc_request {int dummy; } ;
struct mmc_pwrseq {int dummy; } ;
struct TYPE_16__ {int /*<<< orphan*/ * class; struct device* parent; } ;
struct TYPE_14__ {scalar_t__ timing; int power_delay_ms; } ;
struct mmc_host {int retune_now; int hold_retune; int caps; int caps2; int index; int can_retune; int retune_period; int retune_paused; int doing_retune; int f_max; int fixed_drv_type; int dsr_req; int dsr; int rescan_disable; int max_segs; int max_seg_size; int max_req_size; int max_blk_size; int max_blk_count; TYPE_5__ class_dev; int /*<<< orphan*/  led; TYPE_4__* ops; TYPE_3__ ios; int /*<<< orphan*/  retune_timer; int /*<<< orphan*/  sdio_irq_work; int /*<<< orphan*/  detect; int /*<<< orphan*/  wq; int /*<<< orphan*/  lock; struct device* parent; int /*<<< orphan*/  pm_caps; int /*<<< orphan*/  card; scalar_t__ need_retune; } ;
struct mmc_card {TYPE_2__* host; } ;
struct device {scalar_t__ of_node; } ;
struct TYPE_15__ {int /*<<< orphan*/  enable_sdio_irq; int /*<<< orphan*/  (* post_req ) (struct mmc_host*,struct mmc_request*,int) ;int /*<<< orphan*/  (* pre_req ) (struct mmc_host*,struct mmc_request*) ;} ;
struct TYPE_12__ {scalar_t__ timing; int enhanced_strobe; } ;
struct TYPE_13__ {TYPE_1__ ios; } ;

/* Variables and functions */
 int EINVAL ; 
 int ENOENT ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HZ ; 
 int /*<<< orphan*/  INIT_DELAYED_WORK (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int MMC_CAP2_BOOTPART_NOACC ; 
 int MMC_CAP2_CD_ACTIVE_HIGH ; 
 int MMC_CAP2_FULL_PWR_CYCLE ; 
 int MMC_CAP2_HS200_1_2V_SDR ; 
 int MMC_CAP2_HS200_1_8V_SDR ; 
 int MMC_CAP2_HS400_1_2V ; 
 int MMC_CAP2_HS400_1_8V ; 
 int MMC_CAP2_HS400_ES ; 
 int MMC_CAP2_NO_MMC ; 
 int MMC_CAP2_NO_SD ; 
 int MMC_CAP2_NO_SDIO ; 
 int MMC_CAP2_NO_WRITE_PROTECT ; 
 int MMC_CAP2_RO_ACTIVE_HIGH ; 
 int MMC_CAP_1_2V_DDR ; 
 int MMC_CAP_1_8V_DDR ; 
 int MMC_CAP_3_3V_DDR ; 
 int MMC_CAP_4_BIT_DATA ; 
 int MMC_CAP_8_BIT_DATA ; 
 int MMC_CAP_CMD23 ; 
 int MMC_CAP_DONE_COMPLETE ; 
 int MMC_CAP_HW_RESET ; 
 int MMC_CAP_MMC_HIGHSPEED ; 
 int MMC_CAP_NEEDS_POLL ; 
 int MMC_CAP_NONREMOVABLE ; 
 int MMC_CAP_POWER_OFF_CARD ; 
 int MMC_CAP_SDIO_IRQ ; 
 int MMC_CAP_SD_HIGHSPEED ; 
 int MMC_CAP_UHS_DDR50 ; 
 int MMC_CAP_UHS_SDR104 ; 
 int MMC_CAP_UHS_SDR12 ; 
 int MMC_CAP_UHS_SDR25 ; 
 int MMC_CAP_UHS_SDR50 ; 
 int /*<<< orphan*/  MMC_PM_KEEP_POWER ; 
 int /*<<< orphan*/  MMC_PM_WAKE_SDIO_IRQ ; 
 scalar_t__ MMC_TIMING_MMC_DDR52 ; 
 scalar_t__ MMC_TIMING_MMC_HS200 ; 
 scalar_t__ MMC_TIMING_MMC_HS400 ; 
 int PAGE_SIZE ; 
 int SDIO_CCCR_ABORT ; 
 int SDIO_CCCR_SUSPEND ; 
 int SD_IO_RW_DIRECT ; 
 int SD_IO_RW_EXTENDED ; 
 int /*<<< orphan*/  WARN_ON (int) ; 
 int /*<<< orphan*/  __mmc_claim_host (struct mmc_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int class_register (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  class_unregister (int /*<<< orphan*/ *) ; 
 struct mmc_host* cls_dev_to_mmc_host (struct device*) ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_dbg (struct device*,char*) ; 
 int /*<<< orphan*/  dev_err (struct device*,char*,...) ; 
 int /*<<< orphan*/  dev_fwnode (struct device*) ; 
 int /*<<< orphan*/  dev_info (struct device*,char*) ; 
 int /*<<< orphan*/  dev_name (TYPE_5__*) ; 
 int /*<<< orphan*/  dev_set_name (TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  dev_warn (struct device*,char*) ; 
 int device_add (TYPE_5__*) ; 
 int /*<<< orphan*/  device_del (TYPE_5__*) ; 
 int /*<<< orphan*/  device_enable_async_suspend (TYPE_5__*) ; 
 int /*<<< orphan*/  device_initialize (TYPE_5__*) ; 
 int device_property_read_bool (struct device*,char*) ; 
 scalar_t__ device_property_read_u32 (struct device*,char*,int*) ; 
 struct mmc_host* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 struct mmc_host* host ; 
 int ida_simple_get (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ida_simple_remove (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  init_waitqueue_head (int /*<<< orphan*/ *) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  kfree (struct mmc_host*) ; 
 struct mmc_host* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  led_trigger_register_simple (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  led_trigger_unregister_simple (int /*<<< orphan*/ ) ; 
 int mmc_execute_tuning (int /*<<< orphan*/ ) ; 
 scalar_t__ mmc_gpio_alloc (struct mmc_host*) ; 
 int mmc_gpiod_request_cd (struct mmc_host*,char*,int /*<<< orphan*/ ,int,int,int*) ; 
 int mmc_gpiod_request_ro (struct mmc_host*,char*,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int*) ; 
 int /*<<< orphan*/  mmc_host_class ; 
 int /*<<< orphan*/  mmc_host_ida ; 
 int mmc_hs200_to_hs400 (int /*<<< orphan*/ ) ; 
 int mmc_hs400_to_hs200 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_rescan ; 
 void mmc_retune_hold (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_retune_needed (struct mmc_host*) ; 
 void mmc_retune_release (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_start_host (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_stop_host (struct mmc_host*) ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  msleep (unsigned int) ; 
 int of_alias_get_highest_id (char*) ; 
 int of_alias_get_id (scalar_t__,char*) ; 
 int /*<<< orphan*/  put_device (TYPE_5__*) ; 
 int /*<<< orphan*/  retune_timer ; 
 int /*<<< orphan*/  sdio_irq_work ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub1 (struct mmc_host*,struct mmc_request*) ; 
 int /*<<< orphan*/  stub2 (struct mmc_host*,struct mmc_request*,int) ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  usleep_range (unsigned int,unsigned int) ; 

__attribute__((used)) static inline void mmc_delay(unsigned int ms)
{
	if (ms <= 20)
		usleep_range(ms * 1000, ms * 1250);
	else
		msleep(ms);
}

__attribute__((used)) static inline void mmc_register_pm_notifier(struct mmc_host *host) { }

__attribute__((used)) static inline void mmc_unregister_pm_notifier(struct mmc_host *host) { }

__attribute__((used)) static inline void mmc_claim_host(struct mmc_host *host)
{
	__mmc_claim_host(host, NULL, NULL);
}

__attribute__((used)) static inline void mmc_pre_req(struct mmc_host *host, struct mmc_request *mrq)
{
	if (host->ops->pre_req)
		host->ops->pre_req(host, mrq);
}

__attribute__((used)) static inline void mmc_post_req(struct mmc_host *host, struct mmc_request *mrq,
				int err)
{
	if (host->ops->post_req)
		host->ops->post_req(host, mrq, err);
}

__attribute__((used)) static inline void mmc_retune_hold_now(struct mmc_host *host)
{
	host->retune_now = 0;
	host->hold_retune += 1;
}

__attribute__((used)) static inline void mmc_retune_recheck(struct mmc_host *host)
{
	if (host->hold_retune <= 1)
		host->retune_now = 1;
}

__attribute__((used)) static inline int mmc_host_cmd23(struct mmc_host *host)
{
	return host->caps & MMC_CAP_CMD23;
}

__attribute__((used)) static inline bool mmc_host_done_complete(struct mmc_host *host)
{
	return host->caps & MMC_CAP_DONE_COMPLETE;
}

__attribute__((used)) static inline int mmc_boot_partition_access(struct mmc_host *host)
{
	return !(host->caps2 & MMC_CAP2_BOOTPART_NOACC);
}

__attribute__((used)) static inline int mmc_host_uhs(struct mmc_host *host)
{
	return host->caps &
		(MMC_CAP_UHS_SDR12 | MMC_CAP_UHS_SDR25 |
		 MMC_CAP_UHS_SDR50 | MMC_CAP_UHS_SDR104 |
		 MMC_CAP_UHS_DDR50) &&
	       host->caps & MMC_CAP_4_BIT_DATA;
}

__attribute__((used)) static inline bool mmc_card_hs200(struct mmc_card *card)
{
	return card->host->ios.timing == MMC_TIMING_MMC_HS200;
}

__attribute__((used)) static inline bool mmc_card_ddr52(struct mmc_card *card)
{
	return card->host->ios.timing == MMC_TIMING_MMC_DDR52;
}

__attribute__((used)) static inline bool mmc_card_hs400(struct mmc_card *card)
{
	return card->host->ios.timing == MMC_TIMING_MMC_HS400;
}

__attribute__((used)) static inline bool mmc_card_hs400es(struct mmc_card *card)
{
	return card->host->ios.enhanced_strobe;
}

__attribute__((used)) static inline int mmc_pwrseq_register(struct mmc_pwrseq *pwrseq)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void mmc_pwrseq_unregister(struct mmc_pwrseq *pwrseq) {}

__attribute__((used)) static inline int mmc_pwrseq_alloc(struct mmc_host *host) { return 0; }

__attribute__((used)) static inline void mmc_pwrseq_pre_power_on(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_post_power_on(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_power_off(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_reset(struct mmc_host *host) {}

__attribute__((used)) static inline void mmc_pwrseq_free(struct mmc_host *host) {}

__attribute__((used)) static inline bool sdio_is_io_busy(u32 opcode, u32 arg)
{
	u32 addr;

	addr = (arg >> 9) & 0x1FFFF;

	return (opcode == SD_IO_RW_EXTENDED ||
		(opcode == SD_IO_RW_DIRECT &&
		!(addr == SDIO_CCCR_ABORT || addr == SDIO_CCCR_SUSPEND)));
}

__attribute__((used)) static void mmc_host_classdev_release(struct device *dev)
{
	struct mmc_host *host = cls_dev_to_mmc_host(dev);
	ida_simple_remove(&mmc_host_ida, host->index);
	kfree(host);
}

int mmc_register_host_class(void)
{
	return class_register(&mmc_host_class);
}

void mmc_unregister_host_class(void)
{
	class_unregister(&mmc_host_class);
}

void mmc_retune_enable(struct mmc_host *host)
{
	host->can_retune = 1;
	if (host->retune_period)
		mod_timer(&host->retune_timer,
			  jiffies + host->retune_period * HZ);
}

void mmc_retune_pause(struct mmc_host *host)
{
	if (!host->retune_paused) {
		host->retune_paused = 1;
		mmc_retune_needed(host);
		mmc_retune_hold(host);
	}
}

void mmc_retune_unpause(struct mmc_host *host)
{
	if (host->retune_paused) {
		host->retune_paused = 0;
		mmc_retune_release(host);
	}
}

void mmc_retune_disable(struct mmc_host *host)
{
	mmc_retune_unpause(host);
	host->can_retune = 0;
	del_timer_sync(&host->retune_timer);
	host->retune_now = 0;
	host->need_retune = 0;
}

void mmc_retune_timer_stop(struct mmc_host *host)
{
	del_timer_sync(&host->retune_timer);
}

void mmc_retune_hold(struct mmc_host *host)
{
	if (!host->hold_retune)
		host->retune_now = 1;
	host->hold_retune += 1;
}

void mmc_retune_release(struct mmc_host *host)
{
	if (host->hold_retune)
		host->hold_retune -= 1;
	else
		WARN_ON(1);
}

int mmc_retune(struct mmc_host *host)
{
	bool return_to_hs400 = false;
	int err;

	if (host->retune_now)
		host->retune_now = 0;
	else
		return 0;

	if (!host->need_retune || host->doing_retune || !host->card)
		return 0;

	host->need_retune = 0;

	host->doing_retune = 1;

	if (host->ios.timing == MMC_TIMING_MMC_HS400) {
		err = mmc_hs400_to_hs200(host->card);
		if (err)
			goto out;

		return_to_hs400 = true;
	}

	err = mmc_execute_tuning(host->card);
	if (err)
		goto out;

	if (return_to_hs400)
		err = mmc_hs200_to_hs400(host->card);
out:
	host->doing_retune = 0;

	return err;
}

__attribute__((used)) static void mmc_retune_timer(struct timer_list *t)
{
	struct mmc_host *host = from_timer(host, t, retune_timer);

	mmc_retune_needed(host);
}

int mmc_of_parse(struct mmc_host *host)
{
	struct device *dev = host->parent;
	u32 bus_width, drv_type, cd_debounce_delay_ms;
	int ret;
	bool cd_cap_invert, cd_gpio_invert = false;
	bool ro_cap_invert, ro_gpio_invert = false;

	if (!dev || !dev_fwnode(dev))
		return 0;

	/* "bus-width" is translated to MMC_CAP_*_BIT_DATA flags */
	if (device_property_read_u32(dev, "bus-width", &bus_width) < 0) {
		dev_dbg(host->parent,
			"\"bus-width\" property is missing, assuming 1 bit.\n");
		bus_width = 1;
	}

	switch (bus_width) {
	case 8:
		host->caps |= MMC_CAP_8_BIT_DATA;
		/* Hosts capable of 8-bit transfers can also do 4 bits */
	case 4:
		host->caps |= MMC_CAP_4_BIT_DATA;
		break;
	case 1:
		break;
	default:
		dev_err(host->parent,
			"Invalid \"bus-width\" value %u!\n", bus_width);
		return -EINVAL;
	}

	/* f_max is obtained from the optional "max-frequency" property */
	device_property_read_u32(dev, "max-frequency", &host->f_max);

	/*
	 * Configure CD and WP pins. They are both by default active low to
	 * match the SDHCI spec. If GPIOs are provided for CD and / or WP, the
	 * mmc-gpio helpers are used to attach, configure and use them. If
	 * polarity inversion is specified in DT, one of MMC_CAP2_CD_ACTIVE_HIGH
	 * and MMC_CAP2_RO_ACTIVE_HIGH capability-2 flags is set. If the
	 * "broken-cd" property is provided, the MMC_CAP_NEEDS_POLL capability
	 * is set. If the "non-removable" property is found, the
	 * MMC_CAP_NONREMOVABLE capability is set and no card-detection
	 * configuration is performed.
	 */

	/* Parse Card Detection */
	if (device_property_read_bool(dev, "non-removable")) {
		host->caps |= MMC_CAP_NONREMOVABLE;
	} else {
		cd_cap_invert = device_property_read_bool(dev, "cd-inverted");

		if (device_property_read_u32(dev, "cd-debounce-delay-ms",
					     &cd_debounce_delay_ms))
			cd_debounce_delay_ms = 200;

		if (device_property_read_bool(dev, "broken-cd"))
			host->caps |= MMC_CAP_NEEDS_POLL;

		ret = mmc_gpiod_request_cd(host, "cd", 0, true,
					   cd_debounce_delay_ms * 1000,
					   &cd_gpio_invert);
		if (!ret)
			dev_info(host->parent, "Got CD GPIO\n");
		else if (ret != -ENOENT && ret != -ENOSYS)
			return ret;

		/*
		 * There are two ways to flag that the CD line is inverted:
		 * through the cd-inverted flag and by the GPIO line itself
		 * being inverted from the GPIO subsystem. This is a leftover
		 * from the times when the GPIO subsystem did not make it
		 * possible to flag a line as inverted.
		 *
		 * If the capability on the host AND the GPIO line are
		 * both inverted, the end result is that the CD line is
		 * not inverted.
		 */
		if (cd_cap_invert ^ cd_gpio_invert)
			host->caps2 |= MMC_CAP2_CD_ACTIVE_HIGH;
	}

	/* Parse Write Protection */
	ro_cap_invert = device_property_read_bool(dev, "wp-inverted");

	ret = mmc_gpiod_request_ro(host, "wp", 0, false, 0, &ro_gpio_invert);
	if (!ret)
		dev_info(host->parent, "Got WP GPIO\n");
	else if (ret != -ENOENT && ret != -ENOSYS)
		return ret;

	if (device_property_read_bool(dev, "disable-wp"))
		host->caps2 |= MMC_CAP2_NO_WRITE_PROTECT;

	/* See the comment on CD inversion above */
	if (ro_cap_invert ^ ro_gpio_invert)
		host->caps2 |= MMC_CAP2_RO_ACTIVE_HIGH;

	if (device_property_read_bool(dev, "cap-sd-highspeed"))
		host->caps |= MMC_CAP_SD_HIGHSPEED;
	if (device_property_read_bool(dev, "cap-mmc-highspeed"))
		host->caps |= MMC_CAP_MMC_HIGHSPEED;
	if (device_property_read_bool(dev, "sd-uhs-sdr12"))
		host->caps |= MMC_CAP_UHS_SDR12;
	if (device_property_read_bool(dev, "sd-uhs-sdr25"))
		host->caps |= MMC_CAP_UHS_SDR25;
	if (device_property_read_bool(dev, "sd-uhs-sdr50"))
		host->caps |= MMC_CAP_UHS_SDR50;
	if (device_property_read_bool(dev, "sd-uhs-sdr104"))
		host->caps |= MMC_CAP_UHS_SDR104;
	if (device_property_read_bool(dev, "sd-uhs-ddr50"))
		host->caps |= MMC_CAP_UHS_DDR50;
	if (device_property_read_bool(dev, "cap-power-off-card"))
		host->caps |= MMC_CAP_POWER_OFF_CARD;
	if (device_property_read_bool(dev, "cap-mmc-hw-reset"))
		host->caps |= MMC_CAP_HW_RESET;
	if (device_property_read_bool(dev, "cap-sdio-irq"))
		host->caps |= MMC_CAP_SDIO_IRQ;
	if (device_property_read_bool(dev, "full-pwr-cycle"))
		host->caps2 |= MMC_CAP2_FULL_PWR_CYCLE;
	if (device_property_read_bool(dev, "keep-power-in-suspend"))
		host->pm_caps |= MMC_PM_KEEP_POWER;
	if (device_property_read_bool(dev, "wakeup-source") ||
	    device_property_read_bool(dev, "enable-sdio-wakeup")) /* legacy */
		host->pm_caps |= MMC_PM_WAKE_SDIO_IRQ;
	if (device_property_read_bool(dev, "mmc-ddr-3_3v"))
		host->caps |= MMC_CAP_3_3V_DDR;
	if (device_property_read_bool(dev, "mmc-ddr-1_8v"))
		host->caps |= MMC_CAP_1_8V_DDR;
	if (device_property_read_bool(dev, "mmc-ddr-1_2v"))
		host->caps |= MMC_CAP_1_2V_DDR;
	if (device_property_read_bool(dev, "mmc-hs200-1_8v"))
		host->caps2 |= MMC_CAP2_HS200_1_8V_SDR;
	if (device_property_read_bool(dev, "mmc-hs200-1_2v"))
		host->caps2 |= MMC_CAP2_HS200_1_2V_SDR;
	if (device_property_read_bool(dev, "mmc-hs400-1_8v"))
		host->caps2 |= MMC_CAP2_HS400_1_8V | MMC_CAP2_HS200_1_8V_SDR;
	if (device_property_read_bool(dev, "mmc-hs400-1_2v"))
		host->caps2 |= MMC_CAP2_HS400_1_2V | MMC_CAP2_HS200_1_2V_SDR;
	if (device_property_read_bool(dev, "mmc-hs400-enhanced-strobe"))
		host->caps2 |= MMC_CAP2_HS400_ES;
	if (device_property_read_bool(dev, "no-sdio"))
		host->caps2 |= MMC_CAP2_NO_SDIO;
	if (device_property_read_bool(dev, "no-sd"))
		host->caps2 |= MMC_CAP2_NO_SD;
	if (device_property_read_bool(dev, "no-mmc"))
		host->caps2 |= MMC_CAP2_NO_MMC;

	/* Must be after "non-removable" check */
	if (device_property_read_u32(dev, "fixed-emmc-driver-type", &drv_type) == 0) {
		if (host->caps & MMC_CAP_NONREMOVABLE)
			host->fixed_drv_type = drv_type;
		else
			dev_err(host->parent,
				"can't use fixed driver type, media is removable\n");
	}

	host->dsr_req = !device_property_read_u32(dev, "dsr", &host->dsr);
	if (host->dsr_req && (host->dsr & ~0xffff)) {
		dev_err(host->parent,
			"device tree specified broken value for DSR: 0x%x, ignoring\n",
			host->dsr);
		host->dsr_req = 0;
	}

	device_property_read_u32(dev, "post-power-on-delay-ms",
				 &host->ios.power_delay_ms);

	return mmc_pwrseq_alloc(host);
}

struct mmc_host *mmc_alloc_host(int extra, struct device *dev)
{
	int err;
	struct mmc_host *host;
	int id;

	host = kzalloc(sizeof(struct mmc_host) + extra, GFP_KERNEL);
	if (!host)
		return NULL;

	/* If OF aliases exist, start dynamic assignment after highest */
	id = of_alias_get_highest_id("mmc");
	id = (id < 0) ? 0 : id + 1;

	/* If this devices has OF node, maybe it has an alias */
	if (dev->of_node) {
		int of_id = of_alias_get_id(dev->of_node, "mmc");

		if (of_id < 0)
			dev_warn(dev, "/aliases ID not available\n");
		else
			id = of_id;
	}

	/* scanning will be enabled when we're ready */
	host->rescan_disable = 1;

	err = ida_simple_get(&mmc_host_ida, id, 0, GFP_KERNEL);
	if (err < 0) {
		kfree(host);
		return NULL;
	}

	host->index = err;

	dev_set_name(&host->class_dev, "mmc%d", host->index);

	host->parent = dev;
	host->class_dev.parent = dev;
	host->class_dev.class = &mmc_host_class;
	device_initialize(&host->class_dev);
	device_enable_async_suspend(&host->class_dev);

	if (mmc_gpio_alloc(host)) {
		put_device(&host->class_dev);
		ida_simple_remove(&mmc_host_ida, host->index);
		kfree(host);
		return NULL;
	}

	spin_lock_init(&host->lock);
	init_waitqueue_head(&host->wq);
	INIT_DELAYED_WORK(&host->detect, mmc_rescan);
	INIT_DELAYED_WORK(&host->sdio_irq_work, sdio_irq_work);
	timer_setup(&host->retune_timer, mmc_retune_timer, 0);

	/*
	 * By default, hosts do not support SGIO or large requests.
	 * They have to set these according to their abilities.
	 */
	host->max_segs = 1;
	host->max_seg_size = PAGE_SIZE;

	host->max_req_size = PAGE_SIZE;
	host->max_blk_size = 512;
	host->max_blk_count = PAGE_SIZE / 512;

	host->fixed_drv_type = -EINVAL;
	host->ios.power_delay_ms = 10;

	return host;
}

int mmc_add_host(struct mmc_host *host)
{
	int err;

	WARN_ON((host->caps & MMC_CAP_SDIO_IRQ) &&
		!host->ops->enable_sdio_irq);

	err = device_add(&host->class_dev);
	if (err)
		return err;

	led_trigger_register_simple(dev_name(&host->class_dev), &host->led);

#ifdef CONFIG_DEBUG_FS
	mmc_add_host_debugfs(host);
#endif

	mmc_start_host(host);
	mmc_register_pm_notifier(host);

	return 0;
}

void mmc_remove_host(struct mmc_host *host)
{
	mmc_unregister_pm_notifier(host);
	mmc_stop_host(host);

#ifdef CONFIG_DEBUG_FS
	mmc_remove_host_debugfs(host);
#endif

	device_del(&host->class_dev);

	led_trigger_unregister_simple(host->led);
}

void mmc_free_host(struct mmc_host *host)
{
	mmc_pwrseq_free(host);
	put_device(&host->class_dev);
}

