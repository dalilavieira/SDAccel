#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int u_int ;
typedef  scalar_t__ u32 ;
struct device {int dummy; } ;
typedef  enum ucb1x00_reset { ____Placeholder_ucb1x00_reset } ucb1x00_reset ;
struct TYPE_3__ {int /*<<< orphan*/  (* set_multiple ) (TYPE_1__*,unsigned long*,unsigned long*) ;} ;

/* Variables and functions */
 int /*<<< orphan*/  ASSABET_BCR_IRDA_FSEL ; 
#define  ASSABET_BCR_IRDA_MD0 129 
#define  ASSABET_BCR_IRDA_MD1 128 
 int /*<<< orphan*/  ASSABET_BCR_LCD_12RGB ; 
 int /*<<< orphan*/  ASSABET_BCR_LCD_ON ; 
 int /*<<< orphan*/  ASSABET_BCR_LIGHT_ON ; 
 int /*<<< orphan*/  ASSABET_BCR_NCODEC_RST ; 
 int /*<<< orphan*/  ASSABET_BCR_clear (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ASSABET_BCR_set (int /*<<< orphan*/ ) ; 
 scalar_t__ FB_VISUAL_TRUECOLOR ; 
 unsigned int RST_UCB1X00 ; 
 unsigned int RST_UDA1341 ; 
 int UCB_RST_PROBE_FAIL ; 
 int UCB_RST_REMOVE ; 
 int UCB_RST_SUSPEND ; 
 int /*<<< orphan*/  adv7171_sleep () ; 
 TYPE_1__* assabet_bcr_gc ; 
 unsigned int codec_nreset ; 
 int /*<<< orphan*/  local_irq_restore (unsigned long) ; 
 int /*<<< orphan*/  local_irq_save (unsigned long) ; 
 scalar_t__ machine_is_assabet () ; 
 int /*<<< orphan*/  stub1 (TYPE_1__*,unsigned long*,unsigned long*) ; 
 int /*<<< orphan*/  udelay (int) ; 

__attribute__((used)) static inline int sa11x0_pm_init(void) { return 0; }

void ASSABET_BCR_frob(unsigned int mask, unsigned int val)
{
	unsigned long m = mask, v = val;

	assabet_bcr_gc->set_multiple(assabet_bcr_gc, &m, &v);
}

__attribute__((used)) static void assabet_codec_reset(unsigned mask, int set)
{
	unsigned long flags;
	bool old;

	local_irq_save(flags);
	old = !codec_nreset;
	if (set)
		codec_nreset &= ~mask;
	else
		codec_nreset |= mask;

	if (old != !codec_nreset) {
		if (codec_nreset) {
			ASSABET_BCR_set(ASSABET_BCR_NCODEC_RST);
			adv7171_sleep();
		} else {
			ASSABET_BCR_clear(ASSABET_BCR_NCODEC_RST);
		}
	}
	local_irq_restore(flags);
}

__attribute__((used)) static void assabet_ucb1x00_reset(enum ucb1x00_reset state)
{
	int set = state == UCB_RST_REMOVE || state == UCB_RST_SUSPEND ||
		state == UCB_RST_PROBE_FAIL;
	assabet_codec_reset(RST_UCB1X00, set);
}

void assabet_uda1341_reset(int set)
{
	assabet_codec_reset(RST_UDA1341, set);
}

__attribute__((used)) static int assabet_irda_set_power(struct device *dev, unsigned int state)
{
	static unsigned int bcr_state[4] = {
		ASSABET_BCR_IRDA_MD0,
		ASSABET_BCR_IRDA_MD1|ASSABET_BCR_IRDA_MD0,
		ASSABET_BCR_IRDA_MD1,
		0
	};

	if (state < 4)
		ASSABET_BCR_frob(ASSABET_BCR_IRDA_MD1 | ASSABET_BCR_IRDA_MD0,
				 bcr_state[state]);
	return 0;
}

__attribute__((used)) static void assabet_irda_set_speed(struct device *dev, unsigned int speed)
{
	if (speed < 4000000)
		ASSABET_BCR_clear(ASSABET_BCR_IRDA_FSEL);
	else
		ASSABET_BCR_set(ASSABET_BCR_IRDA_FSEL);
}

__attribute__((used)) static void assabet_lcd_set_visual(u32 visual)
{
	u_int is_true_color = visual == FB_VISUAL_TRUECOLOR;

	if (machine_is_assabet()) {
#if 1		// phase 4 or newer Assabet's
		if (is_true_color)
			ASSABET_BCR_set(ASSABET_BCR_LCD_12RGB);
		else
			ASSABET_BCR_clear(ASSABET_BCR_LCD_12RGB);
#else
		// older Assabet's
		if (is_true_color)
			ASSABET_BCR_clear(ASSABET_BCR_LCD_12RGB);
		else
			ASSABET_BCR_set(ASSABET_BCR_LCD_12RGB);
#endif
	}
}

__attribute__((used)) static void assabet_lcd_backlight_power(int on)
{
	if (on)
		ASSABET_BCR_set(ASSABET_BCR_LIGHT_ON);
	else
		ASSABET_BCR_clear(ASSABET_BCR_LIGHT_ON);
}

__attribute__((used)) static void assabet_lcd_power(int on)
{
	if (on) {
		ASSABET_BCR_set(ASSABET_BCR_LCD_ON);
		udelay(500);
	} else
		ASSABET_BCR_clear(ASSABET_BCR_LCD_ON);
}

