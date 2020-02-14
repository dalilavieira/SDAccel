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
typedef  int u16 ;
struct wm97xx_data {int x; int y; int p; } ;
struct wm97xx {int misc; int* dig; int* dig_save; int pen_probably_down; int acc_slot; TYPE_1__* mach_ops; int /*<<< orphan*/  acc_rate; int /*<<< orphan*/  dev; } ;
struct TYPE_2__ {int (* acc_startup ) (struct wm97xx*) ;int /*<<< orphan*/  (* acc_shutdown ) (struct wm97xx*) ;int /*<<< orphan*/  (* post_sample ) (int) ;int /*<<< orphan*/  (* pre_sample ) (int) ;} ;

/* Variables and functions */
 int AC97_EXTENDED_MID ; 
 int AC97_GPIO_STICKY ; 
 int AC97_LINK_FRAME ; 
 int AC97_WM9713_DIG1 ; 
 int AC97_WM9713_DIG2 ; 
 int AC97_WM9713_DIG3 ; 
 int AC97_WM97XX_DIGITISER_RD ; 
 int DEFAULT_PRESSURE ; 
 int RC_PENUP ; 
 int RC_VALID ; 
 int WM9712_PIL ; 
 int WM9712_RPU (int) ; 
 int WM9713_45W ; 
 int WM9713_ADCSEL_MASK ; 
 int WM9713_ADCSEL_PRES ; 
 int WM9713_ADCSEL_X ; 
 int WM9713_ADCSEL_Y ; 
 int WM9713_COO ; 
 int WM9713_CTC ; 
 int WM9713_PDEN ; 
 int WM9713_POLL ; 
 int WM9713_WAIT ; 
 int WM97XX_ADCSEL_MASK ; 
 int WM97XX_ADCSEL_PRES ; 
 int WM97XX_ADCSEL_X ; 
 int WM97XX_ADCSEL_Y ; 
 int WM97XX_CM_RATE_MASK ; 
 int WM97XX_DELAY (int) ; 
 int WM97XX_DELAY_MASK ; 
 int WM97XX_PEN_DOWN ; 
 int WM97XX_PRP_DET_DIG ; 
 int WM97XX_RATE (int /*<<< orphan*/ ) ; 
 int WM97XX_SLEN ; 
 int WM97XX_SLT (int) ; 
 int WM97XX_SLT_MASK ; 
 scalar_t__ coord ; 
 int delay ; 
 int* delay_table ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_info (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ five_wire ; 
 int mask ; 
 int /*<<< orphan*/  memcpy (int*,int*,int) ; 
 int pil ; 
 scalar_t__ pressure ; 
 int rpu ; 
 int /*<<< orphan*/  stub1 (int) ; 
 int /*<<< orphan*/  stub2 (int) ; 
 int /*<<< orphan*/  stub3 (int) ; 
 int /*<<< orphan*/  stub4 (int) ; 
 int stub5 (struct wm97xx*) ; 
 int /*<<< orphan*/  stub6 (struct wm97xx*) ; 
 int /*<<< orphan*/  udelay (int) ; 
 int wm97xx_reg_read (struct wm97xx*,int) ; 
 int /*<<< orphan*/  wm97xx_reg_write (struct wm97xx*,int,int) ; 

__attribute__((used)) static inline void poll_delay(int d)
{
	udelay(3 * AC97_LINK_FRAME + delay_table[d]);
}

__attribute__((used)) static void wm9713_phy_init(struct wm97xx *wm)
{
	u16 dig1 = 0, dig2, dig3;

	/* default values */
	dig2 = WM97XX_DELAY(4) | WM97XX_SLT(5);
	dig3 = WM9712_RPU(1);

	/* rpu */
	if (rpu) {
		dig3 &= 0xffc0;
		dig3 |= WM9712_RPU(rpu);
		dev_info(wm->dev, "setting pen detect pull-up to %d Ohms\n",
			 64000 / rpu);
	}

	/* Five wire panel? */
	if (five_wire) {
		dig3 |= WM9713_45W;
		dev_info(wm->dev, "setting 5-wire touchscreen mode.");

		if (pil) {
			dev_warn(wm->dev,
				 "Pressure measurement not supported in 5 "
				 "wire mode, disabling\n");
			pil = 0;
		}
	}

	/* touchpanel pressure */
	if (pil == 2) {
		dig3 |= WM9712_PIL;
		dev_info(wm->dev,
			 "setting pressure measurement current to 400uA.");
	} else if (pil)
		dev_info(wm->dev,
			 "setting pressure measurement current to 200uA.");
	if (!pil)
		pressure = 0;

	/* sample settling delay */
	if (delay < 0 || delay > 15) {
		dev_info(wm->dev, "supplied delay out of range.");
		delay = 4;
		dev_info(wm->dev, "setting adc sample delay to %d u Secs.",
			 delay_table[delay]);
	}
	dig2 &= 0xff0f;
	dig2 |= WM97XX_DELAY(delay);

	/* mask */
	dig3 |= ((mask & 0x3) << 4);
	if (coord)
		dig3 |= WM9713_WAIT;

	wm->misc = wm97xx_reg_read(wm, 0x5a);

	wm97xx_reg_write(wm, AC97_WM9713_DIG1, dig1);
	wm97xx_reg_write(wm, AC97_WM9713_DIG2, dig2);
	wm97xx_reg_write(wm, AC97_WM9713_DIG3, dig3);
	wm97xx_reg_write(wm, AC97_GPIO_STICKY, 0x0);
}

__attribute__((used)) static void wm9713_dig_enable(struct wm97xx *wm, int enable)
{
	u16 val;

	if (enable) {
		val = wm97xx_reg_read(wm, AC97_EXTENDED_MID);
		wm97xx_reg_write(wm, AC97_EXTENDED_MID, val & 0x7fff);
		wm97xx_reg_write(wm, AC97_WM9713_DIG3, wm->dig[2] |
				 WM97XX_PRP_DET_DIG);
		wm97xx_reg_read(wm, AC97_WM97XX_DIGITISER_RD); /* dummy read */
	} else {
		wm97xx_reg_write(wm, AC97_WM9713_DIG3, wm->dig[2] &
					~WM97XX_PRP_DET_DIG);
		val = wm97xx_reg_read(wm, AC97_EXTENDED_MID);
		wm97xx_reg_write(wm, AC97_EXTENDED_MID, val | 0x8000);
	}
}

__attribute__((used)) static void wm9713_dig_restore(struct wm97xx *wm)
{
	wm97xx_reg_write(wm, AC97_WM9713_DIG1, wm->dig_save[0]);
	wm97xx_reg_write(wm, AC97_WM9713_DIG2, wm->dig_save[1]);
	wm97xx_reg_write(wm, AC97_WM9713_DIG3, wm->dig_save[2]);
}

__attribute__((used)) static void wm9713_aux_prepare(struct wm97xx *wm)
{
	memcpy(wm->dig_save, wm->dig, sizeof(wm->dig));
	wm97xx_reg_write(wm, AC97_WM9713_DIG1, 0);
	wm97xx_reg_write(wm, AC97_WM9713_DIG2, 0);
	wm97xx_reg_write(wm, AC97_WM9713_DIG3, WM97XX_PRP_DET_DIG);
}

__attribute__((used)) static inline int is_pden(struct wm97xx *wm)
{
	return wm->dig[2] & WM9713_PDEN;
}

__attribute__((used)) static int wm9713_poll_sample(struct wm97xx *wm, int adcsel, int *sample)
{
	u16 dig1;
	int timeout = 5 * delay;
	bool wants_pen = adcsel & WM97XX_PEN_DOWN;

	if (wants_pen && !wm->pen_probably_down) {
		u16 data = wm97xx_reg_read(wm, AC97_WM97XX_DIGITISER_RD);
		if (!(data & WM97XX_PEN_DOWN))
			return RC_PENUP;
		wm->pen_probably_down = 1;
	}

	/* set up digitiser */
	dig1 = wm97xx_reg_read(wm, AC97_WM9713_DIG1);
	dig1 &= ~WM9713_ADCSEL_MASK;
	/* WM97XX_ADCSEL_* channels need to be converted to WM9713 format */
	dig1 |= 1 << ((adcsel & WM97XX_ADCSEL_MASK) >> 12);

	if (wm->mach_ops && wm->mach_ops->pre_sample)
		wm->mach_ops->pre_sample(adcsel);
	wm97xx_reg_write(wm, AC97_WM9713_DIG1, dig1 | WM9713_POLL);

	/* wait 3 AC97 time slots + delay for conversion */
	poll_delay(delay);

	/* wait for POLL to go low */
	while ((wm97xx_reg_read(wm, AC97_WM9713_DIG1) & WM9713_POLL) &&
		timeout) {
		udelay(AC97_LINK_FRAME);
		timeout--;
	}

	if (timeout <= 0) {
		/* If PDEN is set, we can get a timeout when pen goes up */
		if (is_pden(wm))
			wm->pen_probably_down = 0;
		else
			dev_dbg(wm->dev, "adc sample timeout");
		return RC_PENUP;
	}

	*sample = wm97xx_reg_read(wm, AC97_WM97XX_DIGITISER_RD);
	if (wm->mach_ops && wm->mach_ops->post_sample)
		wm->mach_ops->post_sample(adcsel);

	/* check we have correct sample */
	if ((*sample ^ adcsel) & WM97XX_ADCSEL_MASK) {
		dev_dbg(wm->dev, "adc wrong sample, wanted %x got %x",
			adcsel & WM97XX_ADCSEL_MASK,
			*sample & WM97XX_ADCSEL_MASK);
		return RC_PENUP;
	}

	if (wants_pen && !(*sample & WM97XX_PEN_DOWN)) {
		wm->pen_probably_down = 0;
		return RC_PENUP;
	}

	return RC_VALID;
}

__attribute__((used)) static int wm9713_poll_coord(struct wm97xx *wm, struct wm97xx_data *data)
{
	u16 dig1;
	int timeout = 5 * delay;

	if (!wm->pen_probably_down) {
		u16 val = wm97xx_reg_read(wm, AC97_WM97XX_DIGITISER_RD);
		if (!(val & WM97XX_PEN_DOWN))
			return RC_PENUP;
		wm->pen_probably_down = 1;
	}

	/* set up digitiser */
	dig1 = wm97xx_reg_read(wm, AC97_WM9713_DIG1);
	dig1 &= ~WM9713_ADCSEL_MASK;
	if (pil)
		dig1 |= WM9713_ADCSEL_PRES;

	if (wm->mach_ops && wm->mach_ops->pre_sample)
		wm->mach_ops->pre_sample(WM97XX_ADCSEL_X | WM97XX_ADCSEL_Y);
	wm97xx_reg_write(wm, AC97_WM9713_DIG1,
			 dig1 | WM9713_POLL | WM9713_COO);

	/* wait 3 AC97 time slots + delay for conversion */
	poll_delay(delay);
	data->x = wm97xx_reg_read(wm, AC97_WM97XX_DIGITISER_RD);
	/* wait for POLL to go low */
	while ((wm97xx_reg_read(wm, AC97_WM9713_DIG1) & WM9713_POLL)
	       && timeout) {
		udelay(AC97_LINK_FRAME);
		timeout--;
	}

	if (timeout <= 0) {
		/* If PDEN is set, we can get a timeout when pen goes up */
		if (is_pden(wm))
			wm->pen_probably_down = 0;
		else
			dev_dbg(wm->dev, "adc sample timeout");
		return RC_PENUP;
	}

	/* read back data */
	data->y = wm97xx_reg_read(wm, AC97_WM97XX_DIGITISER_RD);
	if (pil)
		data->p = wm97xx_reg_read(wm, AC97_WM97XX_DIGITISER_RD);
	else
		data->p = DEFAULT_PRESSURE;

	if (wm->mach_ops && wm->mach_ops->post_sample)
		wm->mach_ops->post_sample(WM97XX_ADCSEL_X | WM97XX_ADCSEL_Y);

	/* check we have correct sample */
	if (!(data->x & WM97XX_ADCSEL_X) || !(data->y & WM97XX_ADCSEL_Y))
		goto err;
	if (pil && !(data->p & WM97XX_ADCSEL_PRES))
		goto err;

	if (!(data->x & WM97XX_PEN_DOWN) || !(data->y & WM97XX_PEN_DOWN)) {
		wm->pen_probably_down = 0;
		return RC_PENUP;
	}
	return RC_VALID;
err:
	return 0;
}

__attribute__((used)) static int wm9713_poll_touch(struct wm97xx *wm, struct wm97xx_data *data)
{
	int rc;

	if (coord) {
		rc = wm9713_poll_coord(wm, data);
		if (rc != RC_VALID)
			return rc;
	} else {
		rc = wm9713_poll_sample(wm, WM97XX_ADCSEL_X | WM97XX_PEN_DOWN, &data->x);
		if (rc != RC_VALID)
			return rc;
		rc = wm9713_poll_sample(wm, WM97XX_ADCSEL_Y | WM97XX_PEN_DOWN, &data->y);
		if (rc != RC_VALID)
			return rc;
		if (pil) {
			rc = wm9713_poll_sample(wm, WM97XX_ADCSEL_PRES | WM97XX_PEN_DOWN,
						&data->p);
			if (rc != RC_VALID)
				return rc;
		} else
			data->p = DEFAULT_PRESSURE;
	}
	return RC_VALID;
}

__attribute__((used)) static int wm9713_acc_enable(struct wm97xx *wm, int enable)
{
	u16 dig1, dig2, dig3;
	int ret = 0;

	dig1 = wm->dig[0];
	dig2 = wm->dig[1];
	dig3 = wm->dig[2];

	if (enable) {
		/* continuous mode */
		if (wm->mach_ops->acc_startup &&
			(ret = wm->mach_ops->acc_startup(wm)) < 0)
			return ret;

		dig1 &= ~WM9713_ADCSEL_MASK;
		dig1 |= WM9713_CTC | WM9713_COO | WM9713_ADCSEL_X |
			WM9713_ADCSEL_Y;
		if (pil)
			dig1 |= WM9713_ADCSEL_PRES;
		dig2 &= ~(WM97XX_DELAY_MASK | WM97XX_SLT_MASK  |
			WM97XX_CM_RATE_MASK);
		dig2 |= WM97XX_SLEN | WM97XX_DELAY(delay) |
		WM97XX_SLT(wm->acc_slot) | WM97XX_RATE(wm->acc_rate);
		dig3 |= WM9713_PDEN;
	} else {
		dig1 &= ~(WM9713_CTC | WM9713_COO);
		dig2 &= ~WM97XX_SLEN;
		dig3 &= ~WM9713_PDEN;
		if (wm->mach_ops->acc_shutdown)
			wm->mach_ops->acc_shutdown(wm);
	}

	wm97xx_reg_write(wm, AC97_WM9713_DIG1, dig1);
	wm97xx_reg_write(wm, AC97_WM9713_DIG2, dig2);
	wm97xx_reg_write(wm, AC97_WM9713_DIG3, dig3);

	return ret;
}

