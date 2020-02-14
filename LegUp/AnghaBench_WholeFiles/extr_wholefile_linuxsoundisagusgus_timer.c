#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_timer_id {int /*<<< orphan*/  device; scalar_t__ subdevice; int /*<<< orphan*/  card; int /*<<< orphan*/  dev_sclass; int /*<<< orphan*/  dev_class; } ;
struct snd_timer {unsigned int sticks; void (* private_free ) (struct snd_timer*) ;int /*<<< orphan*/  hw; struct snd_gus_card* private_data; int /*<<< orphan*/  name; } ;
struct TYPE_4__ {int timer_enabled; void (* interrupt_handler_timer1 ) (struct snd_gus_card*) ;void (* interrupt_handler_timer2 ) (struct snd_gus_card*) ;struct snd_timer* timer2; struct snd_timer* timer1; } ;
struct snd_gus_card {TYPE_1__ gf1; TYPE_2__* card; int /*<<< orphan*/  timer_dev; int /*<<< orphan*/  reg_lock; } ;
struct TYPE_5__ {int /*<<< orphan*/  number; } ;

/* Variables and functions */
 int /*<<< orphan*/  SNDRV_GF1_GB_ADLIB_TIMER_1 ; 
 int /*<<< orphan*/  SNDRV_GF1_GB_ADLIB_TIMER_2 ; 
 int /*<<< orphan*/  SNDRV_GF1_GB_SOUND_BLASTER_CONTROL ; 
 int SNDRV_GF1_HANDLER_TIMER1 ; 
 int SNDRV_GF1_HANDLER_TIMER2 ; 
 int /*<<< orphan*/  SNDRV_TIMER_CLASS_CARD ; 
 int /*<<< orphan*/  SNDRV_TIMER_SCLASS_NONE ; 
 int /*<<< orphan*/  snd_device_free (TYPE_2__*,struct snd_timer*) ; 
 int /*<<< orphan*/  snd_gf1_adlib_write (struct snd_gus_card*,int,unsigned char) ; 
 int /*<<< orphan*/  snd_gf1_set_default_handlers (struct snd_gus_card*,int) ; 
 int /*<<< orphan*/  snd_gf1_timer1 ; 
 int /*<<< orphan*/  snd_gf1_timer2 ; 
 int /*<<< orphan*/  snd_gf1_write8 (struct snd_gus_card*,int /*<<< orphan*/ ,unsigned char) ; 
 struct snd_gus_card* snd_timer_chip (struct snd_timer*) ; 
 int /*<<< orphan*/  snd_timer_interrupt (struct snd_timer*,unsigned int) ; 
 scalar_t__ snd_timer_new (TYPE_2__*,char*,struct snd_timer_id*,struct snd_timer**) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static int snd_gf1_timer1_start(struct snd_timer * timer)
{
	unsigned long flags;
	unsigned char tmp;
	unsigned int ticks;
	struct snd_gus_card *gus;

	gus = snd_timer_chip(timer);
	spin_lock_irqsave(&gus->reg_lock, flags);
	ticks = timer->sticks;
	tmp = (gus->gf1.timer_enabled |= 4);
	snd_gf1_write8(gus, SNDRV_GF1_GB_ADLIB_TIMER_1, 256 - ticks);	/* timer 1 count */
	snd_gf1_write8(gus, SNDRV_GF1_GB_SOUND_BLASTER_CONTROL, tmp);	/* enable timer 1 IRQ */
	snd_gf1_adlib_write(gus, 0x04, tmp >> 2);	/* timer 2 start */
	spin_unlock_irqrestore(&gus->reg_lock, flags);
	return 0;
}

__attribute__((used)) static int snd_gf1_timer1_stop(struct snd_timer * timer)
{
	unsigned long flags;
	unsigned char tmp;
	struct snd_gus_card *gus;

	gus = snd_timer_chip(timer);
	spin_lock_irqsave(&gus->reg_lock, flags);
	tmp = (gus->gf1.timer_enabled &= ~4);
	snd_gf1_write8(gus, SNDRV_GF1_GB_SOUND_BLASTER_CONTROL, tmp);	/* disable timer #1 */
	spin_unlock_irqrestore(&gus->reg_lock, flags);
	return 0;
}

__attribute__((used)) static int snd_gf1_timer2_start(struct snd_timer * timer)
{
	unsigned long flags;
	unsigned char tmp;
	unsigned int ticks;
	struct snd_gus_card *gus;

	gus = snd_timer_chip(timer);
	spin_lock_irqsave(&gus->reg_lock, flags);
	ticks = timer->sticks;
	tmp = (gus->gf1.timer_enabled |= 8);
	snd_gf1_write8(gus, SNDRV_GF1_GB_ADLIB_TIMER_2, 256 - ticks);	/* timer 2 count */
	snd_gf1_write8(gus, SNDRV_GF1_GB_SOUND_BLASTER_CONTROL, tmp);	/* enable timer 2 IRQ */
	snd_gf1_adlib_write(gus, 0x04, tmp >> 2);	/* timer 2 start */
	spin_unlock_irqrestore(&gus->reg_lock, flags);
	return 0;
}

__attribute__((used)) static int snd_gf1_timer2_stop(struct snd_timer * timer)
{
	unsigned long flags;
	unsigned char tmp;
	struct snd_gus_card *gus;

	gus = snd_timer_chip(timer);
	spin_lock_irqsave(&gus->reg_lock, flags);
	tmp = (gus->gf1.timer_enabled &= ~8);
	snd_gf1_write8(gus, SNDRV_GF1_GB_SOUND_BLASTER_CONTROL, tmp);	/* disable timer #1 */
	spin_unlock_irqrestore(&gus->reg_lock, flags);
	return 0;
}

__attribute__((used)) static void snd_gf1_interrupt_timer1(struct snd_gus_card * gus)
{
	struct snd_timer *timer = gus->gf1.timer1;

	if (timer == NULL)
		return;
	snd_timer_interrupt(timer, timer->sticks);
}

__attribute__((used)) static void snd_gf1_interrupt_timer2(struct snd_gus_card * gus)
{
	struct snd_timer *timer = gus->gf1.timer2;

	if (timer == NULL)
		return;
	snd_timer_interrupt(timer, timer->sticks);
}

__attribute__((used)) static void snd_gf1_timer1_free(struct snd_timer *timer)
{
	struct snd_gus_card *gus = timer->private_data;
	gus->gf1.timer1 = NULL;
}

__attribute__((used)) static void snd_gf1_timer2_free(struct snd_timer *timer)
{
	struct snd_gus_card *gus = timer->private_data;
	gus->gf1.timer2 = NULL;
}

void snd_gf1_timers_init(struct snd_gus_card * gus)
{
	struct snd_timer *timer;
	struct snd_timer_id tid;

	if (gus->gf1.timer1 != NULL || gus->gf1.timer2 != NULL)
		return;

	gus->gf1.interrupt_handler_timer1 = snd_gf1_interrupt_timer1;
	gus->gf1.interrupt_handler_timer2 = snd_gf1_interrupt_timer2;

	tid.dev_class = SNDRV_TIMER_CLASS_CARD;
	tid.dev_sclass = SNDRV_TIMER_SCLASS_NONE;
	tid.card = gus->card->number;
	tid.device = gus->timer_dev;
	tid.subdevice = 0;

	if (snd_timer_new(gus->card, "GF1 timer", &tid, &timer) >= 0) {
		strcpy(timer->name, "GF1 timer #1");
		timer->private_data = gus;
		timer->private_free = snd_gf1_timer1_free;
		timer->hw = snd_gf1_timer1;
	}
	gus->gf1.timer1 = timer;

	tid.device++;

	if (snd_timer_new(gus->card, "GF1 timer", &tid, &timer) >= 0) {
		strcpy(timer->name, "GF1 timer #2");
		timer->private_data = gus;
		timer->private_free = snd_gf1_timer2_free;
		timer->hw = snd_gf1_timer2;
	}
	gus->gf1.timer2 = timer;
}

void snd_gf1_timers_done(struct snd_gus_card * gus)
{
	snd_gf1_set_default_handlers(gus, SNDRV_GF1_HANDLER_TIMER1 | SNDRV_GF1_HANDLER_TIMER2);
	if (gus->gf1.timer1) {
		snd_device_free(gus->card, gus->gf1.timer1);
		gus->gf1.timer1 = NULL;
	}
	if (gus->gf1.timer2) {
		snd_device_free(gus->card, gus->gf1.timer2);
		gus->gf1.timer2 = NULL;
	}
}

