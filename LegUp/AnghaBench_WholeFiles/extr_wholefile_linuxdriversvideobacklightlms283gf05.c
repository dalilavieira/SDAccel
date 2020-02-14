#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct spi_device {int /*<<< orphan*/  dev; } ;
struct lms283gf05_state {struct lcd_device* ld; struct spi_device* spi; } ;
struct lms283gf05_seq {char reg; int value; int delay; } ;
struct lms283gf05_pdata {unsigned long reset_gpio; int reset_inverted; } ;
struct lcd_device {int dummy; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct lms283gf05_seq*) ; 
 int ENOMEM ; 
 int FB_BLANK_NORMAL ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int GPIOF_DIR_OUT ; 
 int GPIOF_INIT_HIGH ; 
 int GPIOF_INIT_LOW ; 
 scalar_t__ IS_ERR (struct lcd_device*) ; 
 int PTR_ERR (struct lcd_device*) ; 
 struct lms283gf05_pdata* dev_get_platdata (int /*<<< orphan*/ *) ; 
 int devm_gpio_request_one (int /*<<< orphan*/ *,unsigned long,int,char*) ; 
 struct lms283gf05_state* devm_kzalloc (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 struct lcd_device* devm_lcd_device_register (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ *,struct lms283gf05_state*,int /*<<< orphan*/ *) ; 
 struct lms283gf05_seq* disp_initseq ; 
 struct lms283gf05_seq* disp_pdwnseq ; 
 int /*<<< orphan*/  gpio_set_value (unsigned long,int) ; 
 struct lms283gf05_state* lcd_get_data (struct lcd_device*) ; 
 int /*<<< orphan*/  lms_ops ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  spi_set_drvdata (struct spi_device*,struct lms283gf05_state*) ; 
 int /*<<< orphan*/  spi_write (struct spi_device*,char*,int) ; 

__attribute__((used)) static void lms283gf05_reset(unsigned long gpio, bool inverted)
{
	gpio_set_value(gpio, !inverted);
	mdelay(100);
	gpio_set_value(gpio, inverted);
	mdelay(20);
	gpio_set_value(gpio, !inverted);
	mdelay(20);
}

__attribute__((used)) static void lms283gf05_toggle(struct spi_device *spi,
				const struct lms283gf05_seq *seq, int sz)
{
	char buf[3];
	int i;

	for (i = 0; i < sz; i++) {
		buf[0] = 0x74;
		buf[1] = 0x00;
		buf[2] = seq[i].reg;
		spi_write(spi, buf, 3);

		buf[0] = 0x76;
		buf[1] = seq[i].value >> 8;
		buf[2] = seq[i].value & 0xff;
		spi_write(spi, buf, 3);

		mdelay(seq[i].delay);
	}
}

__attribute__((used)) static int lms283gf05_power_set(struct lcd_device *ld, int power)
{
	struct lms283gf05_state *st = lcd_get_data(ld);
	struct spi_device *spi = st->spi;
	struct lms283gf05_pdata *pdata = dev_get_platdata(&spi->dev);

	if (power <= FB_BLANK_NORMAL) {
		if (pdata)
			lms283gf05_reset(pdata->reset_gpio,
					pdata->reset_inverted);
		lms283gf05_toggle(spi, disp_initseq, ARRAY_SIZE(disp_initseq));
	} else {
		lms283gf05_toggle(spi, disp_pdwnseq, ARRAY_SIZE(disp_pdwnseq));
		if (pdata)
			gpio_set_value(pdata->reset_gpio,
					pdata->reset_inverted);
	}

	return 0;
}

__attribute__((used)) static int lms283gf05_probe(struct spi_device *spi)
{
	struct lms283gf05_state *st;
	struct lms283gf05_pdata *pdata = dev_get_platdata(&spi->dev);
	struct lcd_device *ld;
	int ret = 0;

	if (pdata != NULL) {
		ret = devm_gpio_request_one(&spi->dev, pdata->reset_gpio,
				GPIOF_DIR_OUT | (!pdata->reset_inverted ?
				GPIOF_INIT_HIGH : GPIOF_INIT_LOW),
				"LMS285GF05 RESET");
		if (ret)
			return ret;
	}

	st = devm_kzalloc(&spi->dev, sizeof(struct lms283gf05_state),
				GFP_KERNEL);
	if (st == NULL)
		return -ENOMEM;

	ld = devm_lcd_device_register(&spi->dev, "lms283gf05", &spi->dev, st,
					&lms_ops);
	if (IS_ERR(ld))
		return PTR_ERR(ld);

	st->spi = spi;
	st->ld = ld;

	spi_set_drvdata(spi, st);

	/* kick in the LCD */
	if (pdata)
		lms283gf05_reset(pdata->reset_gpio, pdata->reset_inverted);
	lms283gf05_toggle(spi, disp_initseq, ARRAY_SIZE(disp_initseq));

	return 0;
}

