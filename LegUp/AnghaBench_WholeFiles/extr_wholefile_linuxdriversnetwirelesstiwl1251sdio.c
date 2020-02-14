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
typedef  int /*<<< orphan*/  u32 ;
struct wl1251_sdio {struct sdio_func* func; int /*<<< orphan*/  elp_val; } ;
struct wl1251_platform_data {int /*<<< orphan*/  use_eeprom; scalar_t__ irq; int /*<<< orphan*/  power_gpio; struct wl1251* priv; } ;
struct wl1251 {scalar_t__ irq; struct wl1251_sdio* if_priv; int /*<<< orphan*/  power_gpio; int /*<<< orphan*/  use_eeprom; TYPE_1__* if_ops; int /*<<< orphan*/  irq_work; int /*<<< orphan*/  hw; } ;
struct sdio_func {int /*<<< orphan*/  dev; } ;
struct sdio_device_id {int dummy; } ;
typedef  struct ieee80211_hw {int /*<<< orphan*/  use_eeprom; scalar_t__ irq; int /*<<< orphan*/  power_gpio; struct wl1251* priv; } const ieee80211_hw ;
struct device {int dummy; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_2__ {void (* enable_irq ) (struct wl1251*) ;void (* disable_irq ) (struct wl1251*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_IRQ ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 int /*<<< orphan*/  IRQ_NOAUTOEN ; 
 int /*<<< orphan*/  IRQ_TYPE_EDGE_RISING ; 
 scalar_t__ IS_ERR (struct wl1251_platform_data const*) ; 
 int PTR_ERR (struct wl1251_platform_data const*) ; 
 int /*<<< orphan*/  SET_IEEE80211_DEV (struct wl1251_platform_data const*,int /*<<< orphan*/ *) ; 
 int devm_gpio_request (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 void disable_irq (scalar_t__) ; 
 void enable_irq (scalar_t__) ; 
 int /*<<< orphan*/  free_irq (scalar_t__,struct wl1251*) ; 
 scalar_t__ gpio_is_valid (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpio_set_value (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  ieee80211_queue_work (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  irq_set_irq_type (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  irq_set_status_flags (scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kfree (struct wl1251_sdio*) ; 
 struct wl1251_sdio* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  pm_runtime_get_noresume (int /*<<< orphan*/ *) ; 
 int pm_runtime_get_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pm_runtime_put_noidle (int /*<<< orphan*/ *) ; 
 int pm_runtime_put_sync (int /*<<< orphan*/ *) ; 
 int request_irq (scalar_t__,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct wl1251*) ; 
 int /*<<< orphan*/  sdio_claim_host (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_claim_irq (struct sdio_func*,void (*) (struct sdio_func*)) ; 
 int /*<<< orphan*/  sdio_disable_func (struct sdio_func*) ; 
 int sdio_enable_func (struct sdio_func*) ; 
 struct wl1251* sdio_get_drvdata (struct sdio_func*) ; 
 int sdio_memcpy_fromio (struct sdio_func*,void*,int,size_t) ; 
 int sdio_memcpy_toio (struct sdio_func*,int,void*,size_t) ; 
 int /*<<< orphan*/  sdio_release_host (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_release_irq (struct sdio_func*) ; 
 int /*<<< orphan*/  sdio_set_block_size (struct sdio_func*,int) ; 
 int /*<<< orphan*/  sdio_set_drvdata (struct sdio_func*,struct wl1251*) ; 
 int /*<<< orphan*/  sdio_writeb (struct sdio_func*,int /*<<< orphan*/ ,int,int*) ; 
 int /*<<< orphan*/  sdio_writeb_readb (struct sdio_func*,int /*<<< orphan*/ ,int,int*) ; 
 struct wl1251_platform_data* wl1251_alloc_hw () ; 
 int /*<<< orphan*/  wl1251_debug (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  wl1251_error (char*,int) ; 
 int /*<<< orphan*/  wl1251_free_hw (struct wl1251*) ; 
 struct wl1251_platform_data* wl1251_get_platform_data () ; 
 int /*<<< orphan*/  wl1251_info (char*) ; 
 int wl1251_init_ieee80211 (struct wl1251*) ; 
 TYPE_1__ wl1251_sdio_ops ; 

__attribute__((used)) static struct sdio_func *wl_to_func(struct wl1251 *wl)
{
	struct wl1251_sdio *wl_sdio = wl->if_priv;
	return wl_sdio->func;
}

__attribute__((used)) static void wl1251_sdio_interrupt(struct sdio_func *func)
{
	struct wl1251 *wl = sdio_get_drvdata(func);

	wl1251_debug(DEBUG_IRQ, "IRQ");

	/* FIXME should be synchronous for sdio */
	ieee80211_queue_work(wl->hw, &wl->irq_work);
}

__attribute__((used)) static void wl1251_sdio_read(struct wl1251 *wl, int addr,
			     void *buf, size_t len)
{
	int ret;
	struct sdio_func *func = wl_to_func(wl);

	sdio_claim_host(func);
	ret = sdio_memcpy_fromio(func, buf, addr, len);
	if (ret)
		wl1251_error("sdio read failed (%d)", ret);
	sdio_release_host(func);
}

__attribute__((used)) static void wl1251_sdio_write(struct wl1251 *wl, int addr,
			      void *buf, size_t len)
{
	int ret;
	struct sdio_func *func = wl_to_func(wl);

	sdio_claim_host(func);
	ret = sdio_memcpy_toio(func, addr, buf, len);
	if (ret)
		wl1251_error("sdio write failed (%d)", ret);
	sdio_release_host(func);
}

__attribute__((used)) static void wl1251_sdio_read_elp(struct wl1251 *wl, int addr, u32 *val)
{
	int ret = 0;
	struct wl1251_sdio *wl_sdio = wl->if_priv;
	struct sdio_func *func = wl_sdio->func;

	/*
	 * The hardware only supports RAW (read after write) access for
	 * reading, regular sdio_readb won't work here (it interprets
	 * the unused bits of CMD52 as write data even if we send read
	 * request).
	 */
	sdio_claim_host(func);
	*val = sdio_writeb_readb(func, wl_sdio->elp_val, addr, &ret);
	sdio_release_host(func);

	if (ret)
		wl1251_error("sdio_readb failed (%d)", ret);
}

__attribute__((used)) static void wl1251_sdio_write_elp(struct wl1251 *wl, int addr, u32 val)
{
	int ret = 0;
	struct wl1251_sdio *wl_sdio = wl->if_priv;
	struct sdio_func *func = wl_sdio->func;

	sdio_claim_host(func);
	sdio_writeb(func, val, addr, &ret);
	sdio_release_host(func);

	if (ret)
		wl1251_error("sdio_writeb failed (%d)", ret);
	else
		wl_sdio->elp_val = val;
}

__attribute__((used)) static void wl1251_sdio_reset(struct wl1251 *wl)
{
}

__attribute__((used)) static void wl1251_sdio_enable_irq(struct wl1251 *wl)
{
	struct sdio_func *func = wl_to_func(wl);

	sdio_claim_host(func);
	sdio_claim_irq(func, wl1251_sdio_interrupt);
	sdio_release_host(func);
}

__attribute__((used)) static void wl1251_sdio_disable_irq(struct wl1251 *wl)
{
	struct sdio_func *func = wl_to_func(wl);

	sdio_claim_host(func);
	sdio_release_irq(func);
	sdio_release_host(func);
}

__attribute__((used)) static irqreturn_t wl1251_line_irq(int irq, void *cookie)
{
	struct wl1251 *wl = cookie;

	ieee80211_queue_work(wl->hw, &wl->irq_work);

	return IRQ_HANDLED;
}

__attribute__((used)) static void wl1251_enable_line_irq(struct wl1251 *wl)
{
	return enable_irq(wl->irq);
}

__attribute__((used)) static void wl1251_disable_line_irq(struct wl1251 *wl)
{
	return disable_irq(wl->irq);
}

__attribute__((used)) static int wl1251_sdio_set_power(struct wl1251 *wl, bool enable)
{
	struct sdio_func *func = wl_to_func(wl);
	int ret;

	if (enable) {
		/*
		 * Power is controlled by runtime PM, but we still call board
		 * callback in case it wants to do any additional setup,
		 * for example enabling clock buffer for the module.
		 */
		if (gpio_is_valid(wl->power_gpio))
			gpio_set_value(wl->power_gpio, true);


		ret = pm_runtime_get_sync(&func->dev);
		if (ret < 0) {
			pm_runtime_put_sync(&func->dev);
			goto out;
		}

		sdio_claim_host(func);
		sdio_enable_func(func);
		sdio_release_host(func);
	} else {
		sdio_claim_host(func);
		sdio_disable_func(func);
		sdio_release_host(func);

		ret = pm_runtime_put_sync(&func->dev);
		if (ret < 0)
			goto out;

		if (gpio_is_valid(wl->power_gpio))
			gpio_set_value(wl->power_gpio, false);
	}

out:
	return ret;
}

__attribute__((used)) static int wl1251_sdio_probe(struct sdio_func *func,
			     const struct sdio_device_id *id)
{
	int ret;
	struct wl1251 *wl;
	struct ieee80211_hw *hw;
	struct wl1251_sdio *wl_sdio;
	const struct wl1251_platform_data *wl1251_board_data;

	hw = wl1251_alloc_hw();
	if (IS_ERR(hw))
		return PTR_ERR(hw);

	wl = hw->priv;

	wl_sdio = kzalloc(sizeof(*wl_sdio), GFP_KERNEL);
	if (wl_sdio == NULL) {
		ret = -ENOMEM;
		goto out_free_hw;
	}

	sdio_claim_host(func);
	ret = sdio_enable_func(func);
	if (ret)
		goto release;

	sdio_set_block_size(func, 512);
	sdio_release_host(func);

	SET_IEEE80211_DEV(hw, &func->dev);
	wl_sdio->func = func;
	wl->if_priv = wl_sdio;
	wl->if_ops = &wl1251_sdio_ops;

	wl1251_board_data = wl1251_get_platform_data();
	if (!IS_ERR(wl1251_board_data)) {
		wl->power_gpio = wl1251_board_data->power_gpio;
		wl->irq = wl1251_board_data->irq;
		wl->use_eeprom = wl1251_board_data->use_eeprom;
	}

	if (gpio_is_valid(wl->power_gpio)) {
		ret = devm_gpio_request(&func->dev, wl->power_gpio,
								"wl1251 power");
		if (ret) {
			wl1251_error("Failed to request gpio: %d\n", ret);
			goto disable;
		}
	}

	if (wl->irq) {
		irq_set_status_flags(wl->irq, IRQ_NOAUTOEN);
		ret = request_irq(wl->irq, wl1251_line_irq, 0, "wl1251", wl);
		if (ret < 0) {
			wl1251_error("request_irq() failed: %d", ret);
			goto disable;
		}

		irq_set_irq_type(wl->irq, IRQ_TYPE_EDGE_RISING);

		wl1251_sdio_ops.enable_irq = wl1251_enable_line_irq;
		wl1251_sdio_ops.disable_irq = wl1251_disable_line_irq;

		wl1251_info("using dedicated interrupt line");
	} else {
		wl1251_sdio_ops.enable_irq = wl1251_sdio_enable_irq;
		wl1251_sdio_ops.disable_irq = wl1251_sdio_disable_irq;

		wl1251_info("using SDIO interrupt");
	}

	ret = wl1251_init_ieee80211(wl);
	if (ret)
		goto out_free_irq;

	sdio_set_drvdata(func, wl);

	/* Tell PM core that we don't need the card to be powered now */
	pm_runtime_put_noidle(&func->dev);

	return ret;

out_free_irq:
	if (wl->irq)
		free_irq(wl->irq, wl);
disable:
	sdio_claim_host(func);
	sdio_disable_func(func);
release:
	sdio_release_host(func);
	kfree(wl_sdio);
out_free_hw:
	wl1251_free_hw(wl);
	return ret;
}

__attribute__((used)) static void wl1251_sdio_remove(struct sdio_func *func)
{
	struct wl1251 *wl = sdio_get_drvdata(func);
	struct wl1251_sdio *wl_sdio = wl->if_priv;

	/* Undo decrement done above in wl1251_probe */
	pm_runtime_get_noresume(&func->dev);

	if (wl->irq)
		free_irq(wl->irq, wl);
	wl1251_free_hw(wl);
	kfree(wl_sdio);

	sdio_claim_host(func);
	sdio_release_irq(func);
	sdio_disable_func(func);
	sdio_release_host(func);
}

__attribute__((used)) static int wl1251_suspend(struct device *dev)
{
	/*
	 * Tell MMC/SDIO core it's OK to power down the card
	 * (if it isn't already), but not to remove it completely.
	 */
	return 0;
}

__attribute__((used)) static int wl1251_resume(struct device *dev)
{
	return 0;
}

