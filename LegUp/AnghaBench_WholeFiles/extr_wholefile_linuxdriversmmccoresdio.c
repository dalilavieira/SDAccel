#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_9__ ;
typedef  struct TYPE_27__   TYPE_8__ ;
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;
typedef  struct TYPE_19__   TYPE_10__ ;

/* Type definitions */
typedef  unsigned char u8 ;
typedef  scalar_t__ u64 ;
typedef  int u32 ;
typedef  scalar_t__ u16 ;
struct TYPE_19__ {TYPE_8__* driver; int /*<<< orphan*/ * type; } ;
struct TYPE_25__ {int sd3_bus_mode; int sd3_drv_type; int hs_max_dtr; int /*<<< orphan*/  uhs_max_dtr; } ;
struct TYPE_24__ {scalar_t__ vendor; scalar_t__ device; unsigned int max_dtr; int /*<<< orphan*/  blksize; } ;
struct TYPE_23__ {unsigned char sdio_vsn; int multi_block; int low_speed; int wide_bus; int high_power; int high_speed; } ;
struct TYPE_22__ {int sda_spec3; int bus_widths; } ;
struct TYPE_21__ {scalar_t__ rev; } ;
struct TYPE_20__ {scalar_t__ manfid; scalar_t__ oemid; int /*<<< orphan*/  prod_name; } ;
struct sdio_func {unsigned char class; unsigned int num; int quirks; scalar_t__ vendor; scalar_t__ device; scalar_t__ type; int drive_strength; int ocr; int sdio_funcs; TYPE_10__ dev; struct sdio_func** sdio_func; struct mmc_host* host; TYPE_6__ sw_caps; TYPE_5__ cis; TYPE_4__ cccr; int /*<<< orphan*/  rca; int /*<<< orphan*/  raw_cid; TYPE_3__ scr; int /*<<< orphan*/  quirk_max_rate; int /*<<< orphan*/  sd_bus_speed; struct sdio_func* card; int /*<<< orphan*/  max_blksize; TYPE_2__ ext_csd; TYPE_1__ cid; } ;
struct mmc_request {int dummy; } ;
struct TYPE_26__ {scalar_t__ timing; int enhanced_strobe; scalar_t__ signal_voltage; } ;
struct mmc_host {int retune_now; int hold_retune; int caps; int caps2; int ocr_avail; unsigned int f_init; int ocr_avail_sdio; struct sdio_func* card; int /*<<< orphan*/  claimed; scalar_t__ sdio_irqs; int /*<<< orphan*/  pm_flags; TYPE_9__* ops; int /*<<< orphan*/  sdio_irq_thread; scalar_t__ retune_period; TYPE_7__ ios; } ;
struct mmc_fixup {scalar_t__ manfid; scalar_t__ oemid; scalar_t__ name; scalar_t__ cis_vendor; scalar_t__ cis_device; scalar_t__ ext_csd_rev; scalar_t__ rev_start; scalar_t__ rev_end; int /*<<< orphan*/  data; int /*<<< orphan*/  (* vendor_fixup ) (struct sdio_func*,int /*<<< orphan*/ ) ;} ;
struct mmc_card {unsigned char class; unsigned int num; int quirks; scalar_t__ vendor; scalar_t__ device; scalar_t__ type; int drive_strength; int ocr; int sdio_funcs; TYPE_10__ dev; struct mmc_card** sdio_func; struct mmc_host* host; TYPE_6__ sw_caps; TYPE_5__ cis; TYPE_4__ cccr; int /*<<< orphan*/  rca; int /*<<< orphan*/  raw_cid; TYPE_3__ scr; int /*<<< orphan*/  quirk_max_rate; int /*<<< orphan*/  sd_bus_speed; struct mmc_card* card; int /*<<< orphan*/  max_blksize; TYPE_2__ ext_csd; TYPE_1__ cid; } ;
struct dev_pm_ops {int /*<<< orphan*/  resume; int /*<<< orphan*/  suspend; } ;
struct TYPE_28__ {int /*<<< orphan*/  (* enable_sdio_irq ) (struct mmc_host*,int) ;int /*<<< orphan*/  (* init_card ) (struct mmc_host*,struct sdio_func*) ;int /*<<< orphan*/  (* post_req ) (struct mmc_host*,struct mmc_request*,int) ;int /*<<< orphan*/  (* pre_req ) (struct mmc_host*,struct mmc_request*) ;} ;
struct TYPE_27__ {struct dev_pm_ops* pm; } ;

/* Variables and functions */
 scalar_t__ CID_MANFID_ANY ; 
 scalar_t__ CID_NAME_ANY ; 
 scalar_t__ CID_OEMID_ANY ; 
 int EAGAIN ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOSYS ; 
 scalar_t__ EXT_CSD_REV_ANY ; 
 scalar_t__ IS_ERR (struct sdio_func*) ; 
 int /*<<< orphan*/  MMC_BUS_WIDTH_1 ; 
 int /*<<< orphan*/  MMC_BUS_WIDTH_4 ; 
 int MMC_CAP2_AVOID_3_3V ; 
 int MMC_CAP2_BOOTPART_NOACC ; 
 int MMC_CAP2_SDIO_IRQ_NOTHREAD ; 
 int MMC_CAP_4_BIT_DATA ; 
 int MMC_CAP_CMD23 ; 
 int MMC_CAP_DONE_COMPLETE ; 
 int MMC_CAP_POWER_OFF_CARD ; 
 int MMC_CAP_SDIO_IRQ ; 
 int MMC_CAP_SD_HIGHSPEED ; 
 int MMC_CAP_UHS_DDR50 ; 
 int MMC_CAP_UHS_SDR104 ; 
 int MMC_CAP_UHS_SDR12 ; 
 int MMC_CAP_UHS_SDR25 ; 
 int MMC_CAP_UHS_SDR50 ; 
 int /*<<< orphan*/  MMC_PM_KEEP_POWER ; 
 int MMC_QUIRK_NONSTD_SDIO ; 
#define  MMC_SET_DRIVER_TYPE_A 131 
#define  MMC_SET_DRIVER_TYPE_B 130 
#define  MMC_SET_DRIVER_TYPE_C 129 
#define  MMC_SET_DRIVER_TYPE_D 128 
 scalar_t__ MMC_SIGNAL_VOLTAGE_330 ; 
 scalar_t__ MMC_TIMING_MMC_DDR52 ; 
 scalar_t__ MMC_TIMING_MMC_HS200 ; 
 scalar_t__ MMC_TIMING_MMC_HS400 ; 
 unsigned int MMC_TIMING_SD_HS ; 
 unsigned int MMC_TIMING_UHS_DDR50 ; 
 unsigned int MMC_TIMING_UHS_SDR104 ; 
 unsigned int MMC_TIMING_UHS_SDR12 ; 
 unsigned int MMC_TIMING_UHS_SDR25 ; 
 unsigned int MMC_TIMING_UHS_SDR50 ; 
 scalar_t__ MMC_TYPE_SDIO ; 
 scalar_t__ MMC_TYPE_SD_COMBO ; 
 int PTR_ERR (struct sdio_func*) ; 
 int R4_18V_PRESENT ; 
 int R4_MEMORY_PRESENT ; 
 scalar_t__ SDIO_ANY_ID ; 
 unsigned char SDIO_BUS_ASYNC_INT ; 
 unsigned char SDIO_BUS_CD_DISABLE ; 
 unsigned char SDIO_BUS_WIDTH_4BIT ; 
 unsigned char SDIO_BUS_WIDTH_MASK ; 
 unsigned char SDIO_BUS_WIDTH_RESERVED ; 
 int SDIO_CCCR_ABORT ; 
 scalar_t__ SDIO_CCCR_CAPS ; 
 unsigned char SDIO_CCCR_CAP_4BLS ; 
 unsigned char SDIO_CCCR_CAP_LSC ; 
 unsigned char SDIO_CCCR_CAP_SMB ; 
 scalar_t__ SDIO_CCCR_CCCR ; 
 scalar_t__ SDIO_CCCR_DRIVE_STRENGTH ; 
 scalar_t__ SDIO_CCCR_IF ; 
 scalar_t__ SDIO_CCCR_POWER ; 
 int SDIO_CCCR_REV_1_10 ; 
 int SDIO_CCCR_REV_1_20 ; 
 int SDIO_CCCR_REV_3_00 ; 
 scalar_t__ SDIO_CCCR_SPEED ; 
 int SDIO_CCCR_SUSPEND ; 
 scalar_t__ SDIO_CCCR_UHS ; 
 unsigned char SDIO_CLASS_NONE ; 
 unsigned char SDIO_DRIVE_DTSx_MASK ; 
 unsigned char SDIO_DRIVE_DTSx_SHIFT ; 
 unsigned char SDIO_DRIVE_SDTA ; 
 unsigned char SDIO_DRIVE_SDTC ; 
 unsigned char SDIO_DRIVE_SDTD ; 
 unsigned char SDIO_DTSx_SET_TYPE_A ; 
 unsigned char SDIO_DTSx_SET_TYPE_B ; 
 unsigned char SDIO_DTSx_SET_TYPE_C ; 
 unsigned char SDIO_DTSx_SET_TYPE_D ; 
 scalar_t__ SDIO_FBR_BASE (unsigned int) ; 
 scalar_t__ SDIO_FBR_STD_IF ; 
 scalar_t__ SDIO_FBR_STD_IF_EXT ; 
 unsigned int SDIO_MAX_FUNCS ; 
 unsigned char SDIO_POWER_SMPC ; 
 unsigned char SDIO_SPEED_BSS_MASK ; 
 unsigned int SDIO_SPEED_DDR50 ; 
 unsigned char SDIO_SPEED_EHS ; 
 unsigned int SDIO_SPEED_SDR104 ; 
 unsigned int SDIO_SPEED_SDR12 ; 
 unsigned int SDIO_SPEED_SDR25 ; 
 unsigned int SDIO_SPEED_SDR50 ; 
 unsigned char SDIO_SPEED_SHS ; 
 unsigned char SDIO_UHS_DDR50 ; 
 unsigned char SDIO_UHS_SDR104 ; 
 unsigned char SDIO_UHS_SDR50 ; 
 int SD_DRIVER_TYPE_A ; 
 int SD_DRIVER_TYPE_B ; 
 int SD_DRIVER_TYPE_C ; 
 int SD_DRIVER_TYPE_D ; 
 int SD_IO_RW_DIRECT ; 
 int SD_IO_RW_EXTENDED ; 
 int SD_MODE_UHS_DDR50 ; 
 int SD_MODE_UHS_SDR104 ; 
 int SD_MODE_UHS_SDR12 ; 
 int SD_MODE_UHS_SDR25 ; 
 int SD_MODE_UHS_SDR50 ; 
 int SD_SCR_BUS_WIDTH_4 ; 
 int /*<<< orphan*/  UHS_DDR50_BUS_SPEED ; 
 int /*<<< orphan*/  UHS_DDR50_MAX_DTR ; 
 int /*<<< orphan*/  UHS_SDR104_BUS_SPEED ; 
 int /*<<< orphan*/  UHS_SDR104_MAX_DTR ; 
 int /*<<< orphan*/  UHS_SDR12_BUS_SPEED ; 
 int /*<<< orphan*/  UHS_SDR12_MAX_DTR ; 
 int /*<<< orphan*/  UHS_SDR25_BUS_SPEED ; 
 int /*<<< orphan*/  UHS_SDR25_MAX_DTR ; 
 int /*<<< orphan*/  UHS_SDR50_BUS_SPEED ; 
 int /*<<< orphan*/  UHS_SDR50_MAX_DTR ; 
 scalar_t__ WARN_ON (int) ; 
 int /*<<< orphan*/  __mmc_claim_host (struct mmc_host*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int _mmc_detect_card_removed (struct mmc_host*) ; 
 scalar_t__ cid_rev_card (struct sdio_func*) ; 
 int /*<<< orphan*/  dev_dbg (TYPE_10__*,char*,int /*<<< orphan*/  (*) (struct sdio_func*,int /*<<< orphan*/ )) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 
 unsigned int min (unsigned int,int /*<<< orphan*/ ) ; 
 unsigned int min_not_zero (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int mmc_add_card (struct sdio_func*) ; 
 struct sdio_func* mmc_alloc_card (struct mmc_host*,int /*<<< orphan*/ *) ; 
 int mmc_app_set_bus_width (struct sdio_func*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_attach_bus (struct mmc_host*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mmc_card_disable_cd (struct sdio_func*) ; 
 scalar_t__ mmc_card_hs (struct sdio_func*) ; 
 scalar_t__ mmc_card_is_removable (struct mmc_host*) ; 
 int mmc_card_keep_power (struct mmc_host*) ; 
 scalar_t__ mmc_card_nonstd_func_interface (struct sdio_func*) ; 
 scalar_t__ mmc_card_wake_sdio_irq (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_decode_cid (struct sdio_func*) ; 
 int /*<<< orphan*/  mmc_detach_bus (struct mmc_host*) ; 
 int mmc_execute_tuning (struct sdio_func*) ; 
 int /*<<< orphan*/  mmc_go_idle (struct mmc_host*) ; 
 scalar_t__ mmc_host_is_spi (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_hostname (struct mmc_host*) ; 
 int mmc_io_rw_direct (struct sdio_func*,int,int /*<<< orphan*/ ,scalar_t__,unsigned char,unsigned char*) ; 
 int /*<<< orphan*/  mmc_power_cycle (struct mmc_host*,int) ; 
 int /*<<< orphan*/  mmc_power_off (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_power_up (struct mmc_host*,int) ; 
 int /*<<< orphan*/  mmc_release_host (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_remove_card (struct sdio_func*) ; 
 int /*<<< orphan*/  mmc_retune_needed (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_retune_timer_stop (struct mmc_host*) ; 
 scalar_t__ mmc_sd_get_cid (struct mmc_host*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int mmc_sd_get_csd (struct mmc_host*,struct sdio_func*) ; 
 int /*<<< orphan*/  mmc_sd_get_max_clock (struct sdio_func*) ; 
 int mmc_sd_setup_card (struct mmc_host*,struct sdio_func*,int /*<<< orphan*/ ) ; 
 int mmc_sd_switch_hs (struct sdio_func*) ; 
 int /*<<< orphan*/  mmc_sdio_ops ; 
 int mmc_select_card (struct sdio_func*) ; 
 int mmc_select_drive_strength (struct sdio_func*,int /*<<< orphan*/ ,int,int*) ; 
 int mmc_select_voltage (struct mmc_host*,int) ; 
 int /*<<< orphan*/  mmc_send_if_cond (struct mmc_host*,int) ; 
 int mmc_send_io_op_cond (struct mmc_host*,int,int*) ; 
 int mmc_send_relative_addr (struct mmc_host*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mmc_set_bus_width (struct mmc_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mmc_set_clock (struct mmc_host*,unsigned int) ; 
 int /*<<< orphan*/  mmc_set_driver_type (struct mmc_host*,int) ; 
 int /*<<< orphan*/  mmc_set_initial_signal_voltage (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_set_initial_state (struct mmc_host*) ; 
 int /*<<< orphan*/  mmc_set_timing (struct mmc_host*,unsigned int) ; 
 int mmc_set_uhs_voltage (struct mmc_host*,int) ; 
 int /*<<< orphan*/  mmc_signal_sdio_irq (struct mmc_host*) ; 
 int mmc_spi_set_crc (struct mmc_host*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msleep (unsigned int) ; 
 int /*<<< orphan*/  pm_runtime_disable (TYPE_10__*) ; 
 int /*<<< orphan*/  pm_runtime_enable (TYPE_10__*) ; 
 int /*<<< orphan*/  pm_runtime_get_noresume (TYPE_10__*) ; 
 int pm_runtime_get_sync (TYPE_10__*) ; 
 int /*<<< orphan*/  pm_runtime_put (TYPE_10__*) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (TYPE_10__*) ; 
 int /*<<< orphan*/  pm_runtime_put_sync (TYPE_10__*) ; 
 int pm_runtime_set_active (TYPE_10__*) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  pr_warn (char*,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  sd_type ; 
 int sdio_add_func (struct sdio_func*) ; 
 struct sdio_func* sdio_alloc_func (struct sdio_func*) ; 
 struct mmc_fixup* sdio_fixup_methods ; 
 scalar_t__ sdio_func_present (struct sdio_func*) ; 
 int sdio_read_common_cis (struct sdio_func*) ; 
 int sdio_read_func_cis (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_remove_func (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_reset (struct mmc_host*) ; 
 int /*<<< orphan*/  strncmp (scalar_t__,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  stub1 (struct mmc_host*,struct mmc_request*) ; 
 int /*<<< orphan*/  stub2 (struct mmc_host*,struct mmc_request*,int) ; 
 int /*<<< orphan*/  stub3 (struct sdio_func*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (struct mmc_host*,struct sdio_func*) ; 
 int /*<<< orphan*/  stub5 (struct mmc_host*,int) ; 
 int /*<<< orphan*/  use_spi_crc ; 
 int /*<<< orphan*/  usleep_range (unsigned int,unsigned int) ; 
 int /*<<< orphan*/  wake_up_process (int /*<<< orphan*/ ) ; 

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

__attribute__((used)) static inline void mmc_fixup_device(struct mmc_card *card,
				    const struct mmc_fixup *table)
{
	const struct mmc_fixup *f;
	u64 rev = cid_rev_card(card);

	for (f = table; f->vendor_fixup; f++) {
		if ((f->manfid == CID_MANFID_ANY ||
		     f->manfid == card->cid.manfid) &&
		    (f->oemid == CID_OEMID_ANY ||
		     f->oemid == card->cid.oemid) &&
		    (f->name == CID_NAME_ANY ||
		     !strncmp(f->name, card->cid.prod_name,
			      sizeof(card->cid.prod_name))) &&
		    (f->cis_vendor == card->cis.vendor ||
		     f->cis_vendor == (u16) SDIO_ANY_ID) &&
		    (f->cis_device == card->cis.device ||
		     f->cis_device == (u16) SDIO_ANY_ID) &&
		    (f->ext_csd_rev == EXT_CSD_REV_ANY ||
		     f->ext_csd_rev == card->ext_csd.rev) &&
		    rev >= f->rev_start && rev <= f->rev_end) {
			dev_dbg(&card->dev, "calling %pf\n", f->vendor_fixup);
			f->vendor_fixup(card, f->data);
		}
	}
}

__attribute__((used)) static inline bool sdio_is_io_busy(u32 opcode, u32 arg)
{
	u32 addr;

	addr = (arg >> 9) & 0x1FFFF;

	return (opcode == SD_IO_RW_EXTENDED ||
		(opcode == SD_IO_RW_DIRECT &&
		!(addr == SDIO_CCCR_ABORT || addr == SDIO_CCCR_SUSPEND)));
}

__attribute__((used)) static int sdio_read_fbr(struct sdio_func *func)
{
	int ret;
	unsigned char data;

	if (mmc_card_nonstd_func_interface(func->card)) {
		func->class = SDIO_CLASS_NONE;
		return 0;
	}

	ret = mmc_io_rw_direct(func->card, 0, 0,
		SDIO_FBR_BASE(func->num) + SDIO_FBR_STD_IF, 0, &data);
	if (ret)
		goto out;

	data &= 0x0f;

	if (data == 0x0f) {
		ret = mmc_io_rw_direct(func->card, 0, 0,
			SDIO_FBR_BASE(func->num) + SDIO_FBR_STD_IF_EXT, 0, &data);
		if (ret)
			goto out;
	}

	func->class = data;

out:
	return ret;
}

__attribute__((used)) static int sdio_init_func(struct mmc_card *card, unsigned int fn)
{
	int ret;
	struct sdio_func *func;

	if (WARN_ON(fn > SDIO_MAX_FUNCS))
		return -EINVAL;

	func = sdio_alloc_func(card);
	if (IS_ERR(func))
		return PTR_ERR(func);

	func->num = fn;

	if (!(card->quirks & MMC_QUIRK_NONSTD_SDIO)) {
		ret = sdio_read_fbr(func);
		if (ret)
			goto fail;

		ret = sdio_read_func_cis(func);
		if (ret)
			goto fail;
	} else {
		func->vendor = func->card->cis.vendor;
		func->device = func->card->cis.device;
		func->max_blksize = func->card->cis.blksize;
	}

	card->sdio_func[fn - 1] = func;

	return 0;

fail:
	/*
	 * It is okay to remove the function here even though we hold
	 * the host lock as we haven't registered the device yet.
	 */
	sdio_remove_func(func);
	return ret;
}

__attribute__((used)) static int sdio_read_cccr(struct mmc_card *card, u32 ocr)
{
	int ret;
	int cccr_vsn;
	int uhs = ocr & R4_18V_PRESENT;
	unsigned char data;
	unsigned char speed;

	ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_CCCR, 0, &data);
	if (ret)
		goto out;

	cccr_vsn = data & 0x0f;

	if (cccr_vsn > SDIO_CCCR_REV_3_00) {
		pr_err("%s: unrecognised CCCR structure version %d\n",
			mmc_hostname(card->host), cccr_vsn);
		return -EINVAL;
	}

	card->cccr.sdio_vsn = (data & 0xf0) >> 4;

	ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_CAPS, 0, &data);
	if (ret)
		goto out;

	if (data & SDIO_CCCR_CAP_SMB)
		card->cccr.multi_block = 1;
	if (data & SDIO_CCCR_CAP_LSC)
		card->cccr.low_speed = 1;
	if (data & SDIO_CCCR_CAP_4BLS)
		card->cccr.wide_bus = 1;

	if (cccr_vsn >= SDIO_CCCR_REV_1_10) {
		ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_POWER, 0, &data);
		if (ret)
			goto out;

		if (data & SDIO_POWER_SMPC)
			card->cccr.high_power = 1;
	}

	if (cccr_vsn >= SDIO_CCCR_REV_1_20) {
		ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_SPEED, 0, &speed);
		if (ret)
			goto out;

		card->scr.sda_spec3 = 0;
		card->sw_caps.sd3_bus_mode = 0;
		card->sw_caps.sd3_drv_type = 0;
		if (cccr_vsn >= SDIO_CCCR_REV_3_00 && uhs) {
			card->scr.sda_spec3 = 1;
			ret = mmc_io_rw_direct(card, 0, 0,
				SDIO_CCCR_UHS, 0, &data);
			if (ret)
				goto out;

			if (mmc_host_uhs(card->host)) {
				if (data & SDIO_UHS_DDR50)
					card->sw_caps.sd3_bus_mode
						|= SD_MODE_UHS_DDR50;

				if (data & SDIO_UHS_SDR50)
					card->sw_caps.sd3_bus_mode
						|= SD_MODE_UHS_SDR50;

				if (data & SDIO_UHS_SDR104)
					card->sw_caps.sd3_bus_mode
						|= SD_MODE_UHS_SDR104;
			}

			ret = mmc_io_rw_direct(card, 0, 0,
				SDIO_CCCR_DRIVE_STRENGTH, 0, &data);
			if (ret)
				goto out;

			if (data & SDIO_DRIVE_SDTA)
				card->sw_caps.sd3_drv_type |= SD_DRIVER_TYPE_A;
			if (data & SDIO_DRIVE_SDTC)
				card->sw_caps.sd3_drv_type |= SD_DRIVER_TYPE_C;
			if (data & SDIO_DRIVE_SDTD)
				card->sw_caps.sd3_drv_type |= SD_DRIVER_TYPE_D;
		}

		/* if no uhs mode ensure we check for high speed */
		if (!card->sw_caps.sd3_bus_mode) {
			if (speed & SDIO_SPEED_SHS) {
				card->cccr.high_speed = 1;
				card->sw_caps.hs_max_dtr = 50000000;
			} else {
				card->cccr.high_speed = 0;
				card->sw_caps.hs_max_dtr = 25000000;
			}
		}
	}

out:
	return ret;
}

__attribute__((used)) static int sdio_enable_wide(struct mmc_card *card)
{
	int ret;
	u8 ctrl;

	if (!(card->host->caps & MMC_CAP_4_BIT_DATA))
		return 0;

	if (card->cccr.low_speed && !card->cccr.wide_bus)
		return 0;

	ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_IF, 0, &ctrl);
	if (ret)
		return ret;

	if ((ctrl & SDIO_BUS_WIDTH_MASK) == SDIO_BUS_WIDTH_RESERVED)
		pr_warn("%s: SDIO_CCCR_IF is invalid: 0x%02x\n",
			mmc_hostname(card->host), ctrl);

	/* set as 4-bit bus width */
	ctrl &= ~SDIO_BUS_WIDTH_MASK;
	ctrl |= SDIO_BUS_WIDTH_4BIT;

	ret = mmc_io_rw_direct(card, 1, 0, SDIO_CCCR_IF, ctrl, NULL);
	if (ret)
		return ret;

	return 1;
}

__attribute__((used)) static int sdio_disable_cd(struct mmc_card *card)
{
	int ret;
	u8 ctrl;

	if (!mmc_card_disable_cd(card))
		return 0;

	ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_IF, 0, &ctrl);
	if (ret)
		return ret;

	ctrl |= SDIO_BUS_CD_DISABLE;

	return mmc_io_rw_direct(card, 1, 0, SDIO_CCCR_IF, ctrl, NULL);
}

__attribute__((used)) static int sdio_disable_wide(struct mmc_card *card)
{
	int ret;
	u8 ctrl;

	if (!(card->host->caps & MMC_CAP_4_BIT_DATA))
		return 0;

	if (card->cccr.low_speed && !card->cccr.wide_bus)
		return 0;

	ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_IF, 0, &ctrl);
	if (ret)
		return ret;

	if (!(ctrl & SDIO_BUS_WIDTH_4BIT))
		return 0;

	ctrl &= ~SDIO_BUS_WIDTH_4BIT;
	ctrl |= SDIO_BUS_ASYNC_INT;

	ret = mmc_io_rw_direct(card, 1, 0, SDIO_CCCR_IF, ctrl, NULL);
	if (ret)
		return ret;

	mmc_set_bus_width(card->host, MMC_BUS_WIDTH_1);

	return 0;
}

__attribute__((used)) static int sdio_enable_4bit_bus(struct mmc_card *card)
{
	int err;

	if (card->type == MMC_TYPE_SDIO)
		err = sdio_enable_wide(card);
	else if ((card->host->caps & MMC_CAP_4_BIT_DATA) &&
		 (card->scr.bus_widths & SD_SCR_BUS_WIDTH_4)) {
		err = mmc_app_set_bus_width(card, MMC_BUS_WIDTH_4);
		if (err)
			return err;
		err = sdio_enable_wide(card);
		if (err <= 0)
			mmc_app_set_bus_width(card, MMC_BUS_WIDTH_1);
	} else
		return 0;

	if (err > 0) {
		mmc_set_bus_width(card->host, MMC_BUS_WIDTH_4);
		err = 0;
	}

	return err;
}

__attribute__((used)) static int mmc_sdio_switch_hs(struct mmc_card *card, int enable)
{
	int ret;
	u8 speed;

	if (!(card->host->caps & MMC_CAP_SD_HIGHSPEED))
		return 0;

	if (!card->cccr.high_speed)
		return 0;

	ret = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_SPEED, 0, &speed);
	if (ret)
		return ret;

	if (enable)
		speed |= SDIO_SPEED_EHS;
	else
		speed &= ~SDIO_SPEED_EHS;

	ret = mmc_io_rw_direct(card, 1, 0, SDIO_CCCR_SPEED, speed, NULL);
	if (ret)
		return ret;

	return 1;
}

__attribute__((used)) static int sdio_enable_hs(struct mmc_card *card)
{
	int ret;

	ret = mmc_sdio_switch_hs(card, true);
	if (ret <= 0 || card->type == MMC_TYPE_SDIO)
		return ret;

	ret = mmc_sd_switch_hs(card);
	if (ret <= 0)
		mmc_sdio_switch_hs(card, false);

	return ret;
}

__attribute__((used)) static unsigned mmc_sdio_get_max_clock(struct mmc_card *card)
{
	unsigned max_dtr;

	if (mmc_card_hs(card)) {
		/*
		 * The SDIO specification doesn't mention how
		 * the CIS transfer speed register relates to
		 * high-speed, but it seems that 50 MHz is
		 * mandatory.
		 */
		max_dtr = 50000000;
	} else {
		max_dtr = card->cis.max_dtr;
	}

	if (card->type == MMC_TYPE_SD_COMBO)
		max_dtr = min(max_dtr, mmc_sd_get_max_clock(card));

	return max_dtr;
}

__attribute__((used)) static unsigned char host_drive_to_sdio_drive(int host_strength)
{
	switch (host_strength) {
	case MMC_SET_DRIVER_TYPE_A:
		return SDIO_DTSx_SET_TYPE_A;
	case MMC_SET_DRIVER_TYPE_B:
		return SDIO_DTSx_SET_TYPE_B;
	case MMC_SET_DRIVER_TYPE_C:
		return SDIO_DTSx_SET_TYPE_C;
	case MMC_SET_DRIVER_TYPE_D:
		return SDIO_DTSx_SET_TYPE_D;
	default:
		return SDIO_DTSx_SET_TYPE_B;
	}
}

__attribute__((used)) static void sdio_select_driver_type(struct mmc_card *card)
{
	int card_drv_type, drive_strength, drv_type;
	unsigned char card_strength;
	int err;

	card->drive_strength = 0;

	card_drv_type = card->sw_caps.sd3_drv_type | SD_DRIVER_TYPE_B;

	drive_strength = mmc_select_drive_strength(card,
						   card->sw_caps.uhs_max_dtr,
						   card_drv_type, &drv_type);

	if (drive_strength) {
		/* if error just use default for drive strength B */
		err = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_DRIVE_STRENGTH, 0,
				       &card_strength);
		if (err)
			return;

		card_strength &= ~(SDIO_DRIVE_DTSx_MASK<<SDIO_DRIVE_DTSx_SHIFT);
		card_strength |= host_drive_to_sdio_drive(drive_strength);

		/* if error default to drive strength B */
		err = mmc_io_rw_direct(card, 1, 0, SDIO_CCCR_DRIVE_STRENGTH,
				       card_strength, NULL);
		if (err)
			return;
		card->drive_strength = drive_strength;
	}

	if (drv_type)
		mmc_set_driver_type(card->host, drv_type);
}

__attribute__((used)) static int sdio_set_bus_speed_mode(struct mmc_card *card)
{
	unsigned int bus_speed, timing;
	int err;
	unsigned char speed;
	unsigned int max_rate;

	/*
	 * If the host doesn't support any of the UHS-I modes, fallback on
	 * default speed.
	 */
	if (!mmc_host_uhs(card->host))
		return 0;

	bus_speed = SDIO_SPEED_SDR12;
	timing = MMC_TIMING_UHS_SDR12;
	if ((card->host->caps & MMC_CAP_UHS_SDR104) &&
	    (card->sw_caps.sd3_bus_mode & SD_MODE_UHS_SDR104)) {
			bus_speed = SDIO_SPEED_SDR104;
			timing = MMC_TIMING_UHS_SDR104;
			card->sw_caps.uhs_max_dtr = UHS_SDR104_MAX_DTR;
			card->sd_bus_speed = UHS_SDR104_BUS_SPEED;
	} else if ((card->host->caps & MMC_CAP_UHS_DDR50) &&
		   (card->sw_caps.sd3_bus_mode & SD_MODE_UHS_DDR50)) {
			bus_speed = SDIO_SPEED_DDR50;
			timing = MMC_TIMING_UHS_DDR50;
			card->sw_caps.uhs_max_dtr = UHS_DDR50_MAX_DTR;
			card->sd_bus_speed = UHS_DDR50_BUS_SPEED;
	} else if ((card->host->caps & (MMC_CAP_UHS_SDR104 |
		    MMC_CAP_UHS_SDR50)) && (card->sw_caps.sd3_bus_mode &
		    SD_MODE_UHS_SDR50)) {
			bus_speed = SDIO_SPEED_SDR50;
			timing = MMC_TIMING_UHS_SDR50;
			card->sw_caps.uhs_max_dtr = UHS_SDR50_MAX_DTR;
			card->sd_bus_speed = UHS_SDR50_BUS_SPEED;
	} else if ((card->host->caps & (MMC_CAP_UHS_SDR104 |
		    MMC_CAP_UHS_SDR50 | MMC_CAP_UHS_SDR25)) &&
		   (card->sw_caps.sd3_bus_mode & SD_MODE_UHS_SDR25)) {
			bus_speed = SDIO_SPEED_SDR25;
			timing = MMC_TIMING_UHS_SDR25;
			card->sw_caps.uhs_max_dtr = UHS_SDR25_MAX_DTR;
			card->sd_bus_speed = UHS_SDR25_BUS_SPEED;
	} else if ((card->host->caps & (MMC_CAP_UHS_SDR104 |
		    MMC_CAP_UHS_SDR50 | MMC_CAP_UHS_SDR25 |
		    MMC_CAP_UHS_SDR12)) && (card->sw_caps.sd3_bus_mode &
		    SD_MODE_UHS_SDR12)) {
			bus_speed = SDIO_SPEED_SDR12;
			timing = MMC_TIMING_UHS_SDR12;
			card->sw_caps.uhs_max_dtr = UHS_SDR12_MAX_DTR;
			card->sd_bus_speed = UHS_SDR12_BUS_SPEED;
	}

	err = mmc_io_rw_direct(card, 0, 0, SDIO_CCCR_SPEED, 0, &speed);
	if (err)
		return err;

	speed &= ~SDIO_SPEED_BSS_MASK;
	speed |= bus_speed;
	err = mmc_io_rw_direct(card, 1, 0, SDIO_CCCR_SPEED, speed, NULL);
	if (err)
		return err;

	max_rate = min_not_zero(card->quirk_max_rate,
				card->sw_caps.uhs_max_dtr);

	if (bus_speed) {
		mmc_set_timing(card->host, timing);
		mmc_set_clock(card->host, max_rate);
	}

	return 0;
}

__attribute__((used)) static int mmc_sdio_init_uhs_card(struct mmc_card *card)
{
	int err;

	if (!card->scr.sda_spec3)
		return 0;

	/* Switch to wider bus */
	err = sdio_enable_4bit_bus(card);
	if (err)
		goto out;

	/* Set the driver strength for the card */
	sdio_select_driver_type(card);

	/* Set bus speed mode of the card */
	err = sdio_set_bus_speed_mode(card);
	if (err)
		goto out;

	/*
	 * SPI mode doesn't define CMD19 and tuning is only valid for SDR50 and
	 * SDR104 mode SD-cards. Note that tuning is mandatory for SDR104.
	 */
	if (!mmc_host_is_spi(card->host) &&
	    ((card->host->ios.timing == MMC_TIMING_UHS_SDR50) ||
	      (card->host->ios.timing == MMC_TIMING_UHS_SDR104)))
		err = mmc_execute_tuning(card);
out:
	return err;
}

__attribute__((used)) static void mmc_sdio_resend_if_cond(struct mmc_host *host,
				    struct mmc_card *card)
{
	sdio_reset(host);
	mmc_go_idle(host);
	mmc_send_if_cond(host, host->ocr_avail);
	mmc_remove_card(card);
}

__attribute__((used)) static int mmc_sdio_init_card(struct mmc_host *host, u32 ocr,
			      struct mmc_card *oldcard, int powered_resume)
{
	struct mmc_card *card;
	int err;
	int retries = 10;
	u32 rocr = 0;
	u32 ocr_card = ocr;

	WARN_ON(!host->claimed);

	/* to query card if 1.8V signalling is supported */
	if (mmc_host_uhs(host))
		ocr |= R4_18V_PRESENT;

try_again:
	if (!retries) {
		pr_warn("%s: Skipping voltage switch\n", mmc_hostname(host));
		ocr &= ~R4_18V_PRESENT;
	}

	/*
	 * Inform the card of the voltage
	 */
	if (!powered_resume) {
		err = mmc_send_io_op_cond(host, ocr, &rocr);
		if (err)
			goto err;
	}

	/*
	 * For SPI, enable CRC as appropriate.
	 */
	if (mmc_host_is_spi(host)) {
		err = mmc_spi_set_crc(host, use_spi_crc);
		if (err)
			goto err;
	}

	/*
	 * Allocate card structure.
	 */
	card = mmc_alloc_card(host, NULL);
	if (IS_ERR(card)) {
		err = PTR_ERR(card);
		goto err;
	}

	if ((rocr & R4_MEMORY_PRESENT) &&
	    mmc_sd_get_cid(host, ocr & rocr, card->raw_cid, NULL) == 0) {
		card->type = MMC_TYPE_SD_COMBO;

		if (oldcard && (oldcard->type != MMC_TYPE_SD_COMBO ||
		    memcmp(card->raw_cid, oldcard->raw_cid, sizeof(card->raw_cid)) != 0)) {
			mmc_remove_card(card);
			return -ENOENT;
		}
	} else {
		card->type = MMC_TYPE_SDIO;

		if (oldcard && oldcard->type != MMC_TYPE_SDIO) {
			mmc_remove_card(card);
			return -ENOENT;
		}
	}

	/*
	 * Call the optional HC's init_card function to handle quirks.
	 */
	if (host->ops->init_card)
		host->ops->init_card(host, card);

	/*
	 * If the host and card support UHS-I mode request the card
	 * to switch to 1.8V signaling level.  No 1.8v signalling if
	 * UHS mode is not enabled to maintain compatibility and some
	 * systems that claim 1.8v signalling in fact do not support
	 * it. Per SDIO spec v3, section 3.1.2, if the voltage is already
	 * 1.8v, the card sets S18A to 0 in the R4 response. So it will
	 * fails to check rocr & R4_18V_PRESENT,  but we still need to
	 * try to init uhs card. sdio_read_cccr will take over this task
	 * to make sure which speed mode should work.
	 */
	if (!powered_resume && (rocr & ocr & R4_18V_PRESENT)) {
		err = mmc_set_uhs_voltage(host, ocr_card);
		if (err == -EAGAIN) {
			mmc_sdio_resend_if_cond(host, card);
			retries--;
			goto try_again;
		} else if (err) {
			ocr &= ~R4_18V_PRESENT;
		}
	}

	/*
	 * For native busses:  set card RCA and quit open drain mode.
	 */
	if (!powered_resume && !mmc_host_is_spi(host)) {
		err = mmc_send_relative_addr(host, &card->rca);
		if (err)
			goto remove;

		/*
		 * Update oldcard with the new RCA received from the SDIO
		 * device -- we're doing this so that it's updated in the
		 * "card" struct when oldcard overwrites that later.
		 */
		if (oldcard)
			oldcard->rca = card->rca;
	}

	/*
	 * Read CSD, before selecting the card
	 */
	if (!oldcard && card->type == MMC_TYPE_SD_COMBO) {
		err = mmc_sd_get_csd(host, card);
		if (err)
			return err;

		mmc_decode_cid(card);
	}

	/*
	 * Select card, as all following commands rely on that.
	 */
	if (!powered_resume && !mmc_host_is_spi(host)) {
		err = mmc_select_card(card);
		if (err)
			goto remove;
	}

	if (card->quirks & MMC_QUIRK_NONSTD_SDIO) {
		/*
		 * This is non-standard SDIO device, meaning it doesn't
		 * have any CIA (Common I/O area) registers present.
		 * It's host's responsibility to fill cccr and cis
		 * structures in init_card().
		 */
		mmc_set_clock(host, card->cis.max_dtr);

		if (card->cccr.high_speed) {
			mmc_set_timing(card->host, MMC_TIMING_SD_HS);
		}

		goto finish;
	}

	/*
	 * Read the common registers. Note that we should try to
	 * validate whether UHS would work or not.
	 */
	err = sdio_read_cccr(card, ocr);
	if (err) {
		mmc_sdio_resend_if_cond(host, card);
		if (ocr & R4_18V_PRESENT) {
			/* Retry init sequence, but without R4_18V_PRESENT. */
			retries = 0;
			goto try_again;
		} else {
			goto remove;
		}
	}

	/*
	 * Read the common CIS tuples.
	 */
	err = sdio_read_common_cis(card);
	if (err)
		goto remove;

	if (oldcard) {
		int same = (card->cis.vendor == oldcard->cis.vendor &&
			    card->cis.device == oldcard->cis.device);
		mmc_remove_card(card);
		if (!same)
			return -ENOENT;

		card = oldcard;
	}
	card->ocr = ocr_card;
	mmc_fixup_device(card, sdio_fixup_methods);

	if (card->type == MMC_TYPE_SD_COMBO) {
		err = mmc_sd_setup_card(host, card, oldcard != NULL);
		/* handle as SDIO-only card if memory init failed */
		if (err) {
			mmc_go_idle(host);
			if (mmc_host_is_spi(host))
				/* should not fail, as it worked previously */
				mmc_spi_set_crc(host, use_spi_crc);
			card->type = MMC_TYPE_SDIO;
		} else
			card->dev.type = &sd_type;
	}

	/*
	 * If needed, disconnect card detection pull-up resistor.
	 */
	err = sdio_disable_cd(card);
	if (err)
		goto remove;

	/* Initialization sequence for UHS-I cards */
	/* Only if card supports 1.8v and UHS signaling */
	if ((ocr & R4_18V_PRESENT) && card->sw_caps.sd3_bus_mode) {
		err = mmc_sdio_init_uhs_card(card);
		if (err)
			goto remove;
	} else {
		/*
		 * Switch to high-speed (if supported).
		 */
		err = sdio_enable_hs(card);
		if (err > 0)
			mmc_set_timing(card->host, MMC_TIMING_SD_HS);
		else if (err)
			goto remove;

		/*
		 * Change to the card's maximum speed.
		 */
		mmc_set_clock(host, mmc_sdio_get_max_clock(card));

		/*
		 * Switch to wider bus (if supported).
		 */
		err = sdio_enable_4bit_bus(card);
		if (err)
			goto remove;
	}

	if (host->caps2 & MMC_CAP2_AVOID_3_3V &&
	    host->ios.signal_voltage == MMC_SIGNAL_VOLTAGE_330) {
		pr_err("%s: Host failed to negotiate down from 3.3V\n",
			mmc_hostname(host));
		err = -EINVAL;
		goto remove;
	}
finish:
	if (!oldcard)
		host->card = card;
	return 0;

remove:
	if (!oldcard)
		mmc_remove_card(card);

err:
	return err;
}

__attribute__((used)) static int mmc_sdio_reinit_card(struct mmc_host *host, bool powered_resume)
{
	int ret;

	sdio_reset(host);
	mmc_go_idle(host);
	mmc_send_if_cond(host, host->card->ocr);

	ret = mmc_send_io_op_cond(host, 0, NULL);
	if (ret)
		return ret;

	return mmc_sdio_init_card(host, host->card->ocr, host->card,
				  powered_resume);
}

__attribute__((used)) static void mmc_sdio_remove(struct mmc_host *host)
{
	int i;

	for (i = 0;i < host->card->sdio_funcs;i++) {
		if (host->card->sdio_func[i]) {
			sdio_remove_func(host->card->sdio_func[i]);
			host->card->sdio_func[i] = NULL;
		}
	}

	mmc_remove_card(host->card);
	host->card = NULL;
}

__attribute__((used)) static int mmc_sdio_alive(struct mmc_host *host)
{
	return mmc_select_card(host->card);
}

__attribute__((used)) static void mmc_sdio_detect(struct mmc_host *host)
{
	int err;

	/* Make sure card is powered before detecting it */
	if (host->caps & MMC_CAP_POWER_OFF_CARD) {
		err = pm_runtime_get_sync(&host->card->dev);
		if (err < 0) {
			pm_runtime_put_noidle(&host->card->dev);
			goto out;
		}
	}

	mmc_claim_host(host);

	/*
	 * Just check if our card has been removed.
	 */
	err = _mmc_detect_card_removed(host);

	mmc_release_host(host);

	/*
	 * Tell PM core it's OK to power off the card now.
	 *
	 * The _sync variant is used in order to ensure that the card
	 * is left powered off in case an error occurred, and the card
	 * is going to be removed.
	 *
	 * Since there is no specific reason to believe a new user
	 * is about to show up at this point, the _sync variant is
	 * desirable anyway.
	 */
	if (host->caps & MMC_CAP_POWER_OFF_CARD)
		pm_runtime_put_sync(&host->card->dev);

out:
	if (err) {
		mmc_sdio_remove(host);

		mmc_claim_host(host);
		mmc_detach_bus(host);
		mmc_power_off(host);
		mmc_release_host(host);
	}
}

__attribute__((used)) static int mmc_sdio_pre_suspend(struct mmc_host *host)
{
	int i, err = 0;

	for (i = 0; i < host->card->sdio_funcs; i++) {
		struct sdio_func *func = host->card->sdio_func[i];
		if (func && sdio_func_present(func) && func->dev.driver) {
			const struct dev_pm_ops *pmops = func->dev.driver->pm;
			if (!pmops || !pmops->suspend || !pmops->resume) {
				/* force removal of entire card in that case */
				err = -ENOSYS;
				break;
			}
		}
	}

	return err;
}

__attribute__((used)) static int mmc_sdio_suspend(struct mmc_host *host)
{
	mmc_claim_host(host);

	if (mmc_card_keep_power(host) && mmc_card_wake_sdio_irq(host))
		sdio_disable_wide(host->card);

	if (!mmc_card_keep_power(host)) {
		mmc_power_off(host);
	} else if (host->retune_period) {
		mmc_retune_timer_stop(host);
		mmc_retune_needed(host);
	}

	mmc_release_host(host);

	return 0;
}

__attribute__((used)) static int mmc_sdio_resume(struct mmc_host *host)
{
	int err = 0;

	/* Basic card reinitialization. */
	mmc_claim_host(host);

	/* Restore power if needed */
	if (!mmc_card_keep_power(host)) {
		mmc_power_up(host, host->card->ocr);
		/*
		 * Tell runtime PM core we just powered up the card,
		 * since it still believes the card is powered off.
		 * Note that currently runtime PM is only enabled
		 * for SDIO cards that are MMC_CAP_POWER_OFF_CARD
		 */
		if (host->caps & MMC_CAP_POWER_OFF_CARD) {
			pm_runtime_disable(&host->card->dev);
			pm_runtime_set_active(&host->card->dev);
			pm_runtime_enable(&host->card->dev);
		}
	}

	/* No need to reinitialize powered-resumed nonremovable cards */
	if (mmc_card_is_removable(host) || !mmc_card_keep_power(host)) {
		err = mmc_sdio_reinit_card(host, mmc_card_keep_power(host));
	} else if (mmc_card_keep_power(host) && mmc_card_wake_sdio_irq(host)) {
		/* We may have switched to 1-bit mode during suspend */
		err = sdio_enable_4bit_bus(host->card);
	}

	if (!err && host->sdio_irqs) {
		if (!(host->caps2 & MMC_CAP2_SDIO_IRQ_NOTHREAD))
			wake_up_process(host->sdio_irq_thread);
		else if (host->caps & MMC_CAP_SDIO_IRQ)
			host->ops->enable_sdio_irq(host, 1);
	}

	mmc_release_host(host);

	host->pm_flags &= ~MMC_PM_KEEP_POWER;
	return err;
}

__attribute__((used)) static int mmc_sdio_power_restore(struct mmc_host *host)
{
	int ret;

	/*
	 * Reset the card by performing the same steps that are taken by
	 * mmc_rescan_try_freq() and mmc_attach_sdio() during a "normal" probe.
	 *
	 * sdio_reset() is technically not needed. Having just powered up the
	 * hardware, it should already be in reset state. However, some
	 * platforms (such as SD8686 on OLPC) do not instantly cut power,
	 * meaning that a reset is required when restoring power soon after
	 * powering off. It is harmless in other cases.
	 *
	 * The CMD5 reset (mmc_send_io_op_cond()), according to the SDIO spec,
	 * is not necessary for non-removable cards. However, it is required
	 * for OLPC SD8686 (which expects a [CMD5,5,3,7] init sequence), and
	 * harmless in other situations.
	 *
	 */

	mmc_claim_host(host);

	ret = mmc_sdio_reinit_card(host, mmc_card_keep_power(host));
	if (!ret && host->sdio_irqs)
		mmc_signal_sdio_irq(host);

	mmc_release_host(host);

	return ret;
}

__attribute__((used)) static int mmc_sdio_runtime_suspend(struct mmc_host *host)
{
	/* No references to the card, cut the power to it. */
	mmc_claim_host(host);
	mmc_power_off(host);
	mmc_release_host(host);

	return 0;
}

__attribute__((used)) static int mmc_sdio_runtime_resume(struct mmc_host *host)
{
	int ret;

	/* Restore power and re-initialize. */
	mmc_claim_host(host);
	mmc_power_up(host, host->card->ocr);
	ret = mmc_sdio_power_restore(host);
	mmc_release_host(host);

	return ret;
}

__attribute__((used)) static int mmc_sdio_hw_reset(struct mmc_host *host)
{
	mmc_power_cycle(host, host->card->ocr);
	return mmc_sdio_power_restore(host);
}

__attribute__((used)) static int mmc_sdio_sw_reset(struct mmc_host *host)
{
	mmc_set_clock(host, host->f_init);
	sdio_reset(host);
	mmc_go_idle(host);

	mmc_set_initial_state(host);
	mmc_set_initial_signal_voltage(host);

	return mmc_sdio_reinit_card(host, 0);
}

int mmc_attach_sdio(struct mmc_host *host)
{
	int err, i, funcs;
	u32 ocr, rocr;
	struct mmc_card *card;

	WARN_ON(!host->claimed);

	err = mmc_send_io_op_cond(host, 0, &ocr);
	if (err)
		return err;

	mmc_attach_bus(host, &mmc_sdio_ops);
	if (host->ocr_avail_sdio)
		host->ocr_avail = host->ocr_avail_sdio;


	rocr = mmc_select_voltage(host, ocr);

	/*
	 * Can we support the voltage(s) of the card(s)?
	 */
	if (!rocr) {
		err = -EINVAL;
		goto err;
	}

	/*
	 * Detect and init the card.
	 */
	err = mmc_sdio_init_card(host, rocr, NULL, 0);
	if (err)
		goto err;

	card = host->card;

	/*
	 * Enable runtime PM only if supported by host+card+board
	 */
	if (host->caps & MMC_CAP_POWER_OFF_CARD) {
		/*
		 * Do not allow runtime suspend until after SDIO function
		 * devices are added.
		 */
		pm_runtime_get_noresume(&card->dev);

		/*
		 * Let runtime PM core know our card is active
		 */
		err = pm_runtime_set_active(&card->dev);
		if (err)
			goto remove;

		/*
		 * Enable runtime PM for this card
		 */
		pm_runtime_enable(&card->dev);
	}

	/*
	 * The number of functions on the card is encoded inside
	 * the ocr.
	 */
	funcs = (ocr & 0x70000000) >> 28;
	card->sdio_funcs = 0;

	/*
	 * Initialize (but don't add) all present functions.
	 */
	for (i = 0; i < funcs; i++, card->sdio_funcs++) {
		err = sdio_init_func(host->card, i + 1);
		if (err)
			goto remove;

		/*
		 * Enable Runtime PM for this func (if supported)
		 */
		if (host->caps & MMC_CAP_POWER_OFF_CARD)
			pm_runtime_enable(&card->sdio_func[i]->dev);
	}

	/*
	 * First add the card to the driver model...
	 */
	mmc_release_host(host);
	err = mmc_add_card(host->card);
	if (err)
		goto remove_added;

	/*
	 * ...then the SDIO functions.
	 */
	for (i = 0;i < funcs;i++) {
		err = sdio_add_func(host->card->sdio_func[i]);
		if (err)
			goto remove_added;
	}

	if (host->caps & MMC_CAP_POWER_OFF_CARD)
		pm_runtime_put(&card->dev);

	mmc_claim_host(host);
	return 0;


remove:
	mmc_release_host(host);
remove_added:
	/*
	 * The devices are being deleted so it is not necessary to disable
	 * runtime PM. Similarly we also don't pm_runtime_put() the SDIO card
	 * because it needs to be active to remove any function devices that
	 * were probed, and after that it gets deleted.
	 */
	mmc_sdio_remove(host);
	mmc_claim_host(host);
err:
	mmc_detach_bus(host);

	pr_err("%s: error %d whilst initialising SDIO card\n",
		mmc_hostname(host), err);

	return err;
}

