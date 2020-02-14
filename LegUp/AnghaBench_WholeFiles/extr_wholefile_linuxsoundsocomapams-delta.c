#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_9__ ;
typedef  struct TYPE_16__   TYPE_6__ ;
typedef  struct TYPE_15__   TYPE_5__ ;
typedef  struct TYPE_14__   TYPE_4__ ;
typedef  struct TYPE_13__   TYPE_3__ ;
typedef  struct TYPE_12__   TYPE_2__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct tty_struct {struct snd_soc_component* disc_data; } ;
struct timer_list {int dummy; } ;
struct soc_enum {scalar_t__ items; } ;
struct snd_soc_pcm_runtime {struct snd_soc_dai* codec_dai; struct snd_soc_card* card; } ;
struct snd_soc_dapm_context {int dummy; } ;
struct snd_soc_dai {TYPE_1__* driver; struct snd_soc_component* component; } ;
struct snd_soc_component {int /*<<< orphan*/ * dev; TYPE_2__* card; } ;
struct snd_soc_card {int /*<<< orphan*/ * dev; struct snd_soc_dapm_context dapm; } ;
struct snd_pcm_substream {int dummy; } ;
struct snd_kcontrol {scalar_t__ private_value; } ;
struct TYPE_13__ {scalar_t__* item; } ;
struct TYPE_14__ {TYPE_3__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct platform_device {int /*<<< orphan*/  dev; } ;
struct TYPE_17__ {int (* startup ) (struct snd_pcm_substream*) ;void (* shutdown ) (struct snd_pcm_substream*) ;} ;
struct TYPE_16__ {int /*<<< orphan*/  pins; } ;
struct TYPE_15__ {int (* open ) (struct tty_struct*) ;int /*<<< orphan*/  (* write_wakeup ) (struct tty_struct*) ;int /*<<< orphan*/  (* receive_buf ) (struct tty_struct*,unsigned char const*,char*,int) ;int /*<<< orphan*/  (* close ) (struct tty_struct*) ;} ;
struct TYPE_12__ {int /*<<< orphan*/  pop_time; struct snd_soc_dapm_context dapm; } ;
struct TYPE_11__ {int /*<<< orphan*/ * ops; } ;

/* Variables and functions */
 int AMS_DELTA_AGC ; 
 int AMS_DELTA_EARPIECE ; 
 int AMS_DELTA_MICROPHONE ; 
 int AMS_DELTA_MOUTHPIECE ; 
 int AMS_DELTA_SPEAKER ; 
 unsigned short ARRAY_SIZE (int /*<<< orphan*/ ) ; 
 int EINVAL ; 
 int ENODEV ; 
 int EUNATCH ; 
 int /*<<< orphan*/  GPIOD_OUT_HIGH ; 
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 scalar_t__ IS_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  N_V253 ; 
 int /*<<< orphan*/  SND_JACK_HEADSET ; 
 int ams_delta_audio_agc ; 
 struct snd_soc_card ams_delta_audio_card ; 
 int /*<<< orphan*/  ams_delta_audio_mode ; 
 unsigned short* ams_delta_audio_mode_pins ; 
 int /*<<< orphan*/  ams_delta_dai_ops ; 
 TYPE_6__ ams_delta_hook_switch ; 
 int /*<<< orphan*/  ams_delta_hook_switch_gpios ; 
 int /*<<< orphan*/  ams_delta_hook_switch_pins ; 
 int /*<<< orphan*/  ams_delta_lock ; 
 int ams_delta_muted ; 
 TYPE_9__ ams_delta_ops ; 
 struct snd_soc_component* cx20442_codec ; 
 int cx81801_cmd_pending ; 
 int /*<<< orphan*/  cx81801_ops ; 
 int /*<<< orphan*/  cx81801_timer ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  devm_gpiod_get (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gpiod_modem_codec ; 
 int /*<<< orphan*/  gpiod_set_value (int /*<<< orphan*/ ,int) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  mod_timer (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ msecs_to_jiffies (int) ; 
 struct snd_soc_card* platform_get_drvdata (struct platform_device*) ; 
 struct snd_soc_card* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int snd_soc_card_jack_new (struct snd_soc_card*,char*,int /*<<< orphan*/ ,TYPE_6__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_soc_dapm_disable_pin (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_disable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_enable_pin_unlocked (struct snd_soc_dapm_context*,char*) ; 
 int snd_soc_dapm_get_pin_status (struct snd_soc_dapm_context*,char*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_lock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_mutex_unlock (struct snd_soc_dapm_context*) ; 
 int /*<<< orphan*/  snd_soc_dapm_sync_unlocked (struct snd_soc_dapm_context*) ; 
 int snd_soc_jack_add_gpiods (int /*<<< orphan*/ *,TYPE_6__*,unsigned short,int /*<<< orphan*/ ) ; 
 int snd_soc_jack_add_pins (TYPE_6__*,unsigned short,int /*<<< orphan*/ ) ; 
 int snd_soc_register_card (struct snd_soc_card*) ; 
 int /*<<< orphan*/  snd_soc_unregister_card (struct snd_soc_card*) ; 
 int /*<<< orphan*/  spin_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int stub1 (struct tty_struct*) ; 
 int /*<<< orphan*/  stub2 (struct tty_struct*) ; 
 int /*<<< orphan*/  stub3 (struct tty_struct*,unsigned char const*,char*,int) ; 
 int /*<<< orphan*/  stub4 (struct tty_struct*,unsigned char const*,char*,int) ; 
 int /*<<< orphan*/  stub5 (struct tty_struct*) ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int tty_register_ldisc (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ tty_unregister_ldisc (int /*<<< orphan*/ ) ; 
 TYPE_5__ v253_ops ; 

__attribute__((used)) static int ams_delta_set_audio_mode(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
	struct snd_soc_dapm_context *dapm = &card->dapm;
	struct soc_enum *control = (struct soc_enum *)kcontrol->private_value;
	unsigned short pins;
	int pin, changed = 0;

	/* Refuse any mode changes if we are not able to control the codec. */
	if (!cx20442_codec->card->pop_time)
		return -EUNATCH;

	if (ucontrol->value.enumerated.item[0] >= control->items)
		return -EINVAL;

	snd_soc_dapm_mutex_lock(dapm);

	/* Translate selection to bitmap */
	pins = ams_delta_audio_mode_pins[ucontrol->value.enumerated.item[0]];

	/* Setup pins after corresponding bits if changed */
	pin = !!(pins & (1 << AMS_DELTA_MOUTHPIECE));

	if (pin != snd_soc_dapm_get_pin_status(dapm, "Mouthpiece")) {
		changed = 1;
		if (pin)
			snd_soc_dapm_enable_pin_unlocked(dapm, "Mouthpiece");
		else
			snd_soc_dapm_disable_pin_unlocked(dapm, "Mouthpiece");
	}
	pin = !!(pins & (1 << AMS_DELTA_EARPIECE));
	if (pin != snd_soc_dapm_get_pin_status(dapm, "Earpiece")) {
		changed = 1;
		if (pin)
			snd_soc_dapm_enable_pin_unlocked(dapm, "Earpiece");
		else
			snd_soc_dapm_disable_pin_unlocked(dapm, "Earpiece");
	}
	pin = !!(pins & (1 << AMS_DELTA_MICROPHONE));
	if (pin != snd_soc_dapm_get_pin_status(dapm, "Microphone")) {
		changed = 1;
		if (pin)
			snd_soc_dapm_enable_pin_unlocked(dapm, "Microphone");
		else
			snd_soc_dapm_disable_pin_unlocked(dapm, "Microphone");
	}
	pin = !!(pins & (1 << AMS_DELTA_SPEAKER));
	if (pin != snd_soc_dapm_get_pin_status(dapm, "Speaker")) {
		changed = 1;
		if (pin)
			snd_soc_dapm_enable_pin_unlocked(dapm, "Speaker");
		else
			snd_soc_dapm_disable_pin_unlocked(dapm, "Speaker");
	}
	pin = !!(pins & (1 << AMS_DELTA_AGC));
	if (pin != ams_delta_audio_agc) {
		ams_delta_audio_agc = pin;
		changed = 1;
		if (pin)
			snd_soc_dapm_enable_pin_unlocked(dapm, "AGCIN");
		else
			snd_soc_dapm_disable_pin_unlocked(dapm, "AGCIN");
	}

	if (changed)
		snd_soc_dapm_sync_unlocked(dapm);

	snd_soc_dapm_mutex_unlock(dapm);

	return changed;
}

__attribute__((used)) static int ams_delta_get_audio_mode(struct snd_kcontrol *kcontrol,
					struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_card *card = snd_kcontrol_chip(kcontrol);
	struct snd_soc_dapm_context *dapm = &card->dapm;
	unsigned short pins, mode;

	pins = ((snd_soc_dapm_get_pin_status(dapm, "Mouthpiece") <<
							AMS_DELTA_MOUTHPIECE) |
			(snd_soc_dapm_get_pin_status(dapm, "Earpiece") <<
							AMS_DELTA_EARPIECE));
	if (pins)
		pins |= (snd_soc_dapm_get_pin_status(dapm, "Microphone") <<
							AMS_DELTA_MICROPHONE);
	else
		pins = ((snd_soc_dapm_get_pin_status(dapm, "Microphone") <<
							AMS_DELTA_MICROPHONE) |
			(snd_soc_dapm_get_pin_status(dapm, "Speaker") <<
							AMS_DELTA_SPEAKER) |
			(ams_delta_audio_agc << AMS_DELTA_AGC));

	for (mode = 0; mode < ARRAY_SIZE(ams_delta_audio_mode); mode++)
		if (pins == ams_delta_audio_mode_pins[mode])
			break;

	if (mode >= ARRAY_SIZE(ams_delta_audio_mode))
		return -EINVAL;

	ucontrol->value.enumerated.item[0] = mode;

	return 0;
}

__attribute__((used)) static void cx81801_timeout(struct timer_list *unused)
{
	int muted;

	spin_lock(&ams_delta_lock);
	cx81801_cmd_pending = 0;
	muted = ams_delta_muted;
	spin_unlock(&ams_delta_lock);

	/* Reconnect the codec DAI back from the modem to the CPU DAI
	 * only if digital mute still off */
	if (!muted)
		gpiod_set_value(gpiod_modem_codec, 0);
}

__attribute__((used)) static int cx81801_open(struct tty_struct *tty)
{
	int ret;

	if (!cx20442_codec)
		return -ENODEV;

	/*
	 * Pass the codec structure pointer for use by other ldisc callbacks,
	 * both the card and the codec specific parts.
	 */
	tty->disc_data = cx20442_codec;

	ret = v253_ops.open(tty);

	if (ret < 0)
		tty->disc_data = NULL;

	return ret;
}

__attribute__((used)) static void cx81801_close(struct tty_struct *tty)
{
	struct snd_soc_component *component = tty->disc_data;
	struct snd_soc_dapm_context *dapm = &component->card->dapm;

	del_timer_sync(&cx81801_timer);

	/* Prevent the hook switch from further changing the DAPM pins */
	INIT_LIST_HEAD(&ams_delta_hook_switch.pins);

	if (!component)
		return;

	v253_ops.close(tty);

	/* Revert back to default audio input/output constellation */
	snd_soc_dapm_mutex_lock(dapm);

	snd_soc_dapm_disable_pin_unlocked(dapm, "Mouthpiece");
	snd_soc_dapm_enable_pin_unlocked(dapm, "Earpiece");
	snd_soc_dapm_enable_pin_unlocked(dapm, "Microphone");
	snd_soc_dapm_disable_pin_unlocked(dapm, "Speaker");
	snd_soc_dapm_disable_pin_unlocked(dapm, "AGCIN");

	snd_soc_dapm_sync_unlocked(dapm);

	snd_soc_dapm_mutex_unlock(dapm);
}

__attribute__((used)) static int cx81801_hangup(struct tty_struct *tty)
{
	cx81801_close(tty);
	return 0;
}

__attribute__((used)) static void cx81801_receive(struct tty_struct *tty,
				const unsigned char *cp, char *fp, int count)
{
	struct snd_soc_component *component = tty->disc_data;
	const unsigned char *c;
	int apply, ret;

	if (!component)
		return;

	if (!component->card->pop_time) {
		/* First modem response, complete setup procedure */

		/* Initialize timer used for config pulse generation */
		timer_setup(&cx81801_timer, cx81801_timeout, 0);

		v253_ops.receive_buf(tty, cp, fp, count);

		/* Link hook switch to DAPM pins */
		ret = snd_soc_jack_add_pins(&ams_delta_hook_switch,
					ARRAY_SIZE(ams_delta_hook_switch_pins),
					ams_delta_hook_switch_pins);
		if (ret)
			dev_warn(component->dev,
				"Failed to link hook switch to DAPM pins, "
				"will continue with hook switch unlinked.\n");

		return;
	}

	v253_ops.receive_buf(tty, cp, fp, count);

	for (c = &cp[count - 1]; c >= cp; c--) {
		if (*c != '\r')
			continue;
		/* Complete modem response received, apply config to codec */

		spin_lock_bh(&ams_delta_lock);
		mod_timer(&cx81801_timer, jiffies + msecs_to_jiffies(150));
		apply = !ams_delta_muted && !cx81801_cmd_pending;
		cx81801_cmd_pending = 1;
		spin_unlock_bh(&ams_delta_lock);

		/* Apply config pulse by connecting the codec to the modem
		 * if not already done */
		if (apply)
			gpiod_set_value(gpiod_modem_codec, 1);
		break;
	}
}

__attribute__((used)) static void cx81801_wakeup(struct tty_struct *tty)
{
	v253_ops.write_wakeup(tty);
}

__attribute__((used)) static int ams_delta_digital_mute(struct snd_soc_dai *dai, int mute)
{
	int apply;

	if (ams_delta_muted == mute)
		return 0;

	spin_lock_bh(&ams_delta_lock);
	ams_delta_muted = mute;
	apply = !cx81801_cmd_pending;
	spin_unlock_bh(&ams_delta_lock);

	if (apply)
		gpiod_set_value(gpiod_modem_codec, !!mute);
	return 0;
}

__attribute__((used)) static int ams_delta_startup(struct snd_pcm_substream *substream)
{
	return ams_delta_digital_mute(NULL, 0);
}

__attribute__((used)) static void ams_delta_shutdown(struct snd_pcm_substream *substream)
{
	ams_delta_digital_mute(NULL, 1);
}

__attribute__((used)) static int ams_delta_cx20442_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_card *card = rtd->card;
	struct snd_soc_dapm_context *dapm = &card->dapm;
	int ret;
	/* Codec is ready, now add/activate board specific controls */

	/* Store a pointer to the codec structure for tty ldisc use */
	cx20442_codec = rtd->codec_dai->component;

	/* Add hook switch - can be used to control the codec from userspace
	 * even if line discipline fails */
	ret = snd_soc_card_jack_new(card, "hook_switch", SND_JACK_HEADSET,
				    &ams_delta_hook_switch, NULL, 0);
	if (ret)
		dev_warn(card->dev,
				"Failed to allocate resources for hook switch, "
				"will continue without one.\n");
	else {
		ret = snd_soc_jack_add_gpiods(card->dev, &ams_delta_hook_switch,
					ARRAY_SIZE(ams_delta_hook_switch_gpios),
					ams_delta_hook_switch_gpios);
		if (ret)
			dev_warn(card->dev,
				"Failed to set up hook switch GPIO line, "
				"will continue with hook switch inactive.\n");
	}

	gpiod_modem_codec = devm_gpiod_get(card->dev, "modem_codec",
					   GPIOD_OUT_HIGH);
	if (IS_ERR(gpiod_modem_codec)) {
		dev_warn(card->dev, "Failed to obtain modem_codec GPIO\n");
		return 0;
	}

	/* Set up digital mute if not provided by the codec */
	if (!codec_dai->driver->ops) {
		codec_dai->driver->ops = &ams_delta_dai_ops;
	} else {
		ams_delta_ops.startup = ams_delta_startup;
		ams_delta_ops.shutdown = ams_delta_shutdown;
	}

	/* Register optional line discipline for over the modem control */
	ret = tty_register_ldisc(N_V253, &cx81801_ops);
	if (ret) {
		dev_warn(card->dev,
				"Failed to register line discipline, "
				"will continue without any controls.\n");
		return 0;
	}

	/* Set up initial pin constellation */
	snd_soc_dapm_disable_pin(dapm, "Mouthpiece");
	snd_soc_dapm_disable_pin(dapm, "Speaker");
	snd_soc_dapm_disable_pin(dapm, "AGCIN");
	snd_soc_dapm_disable_pin(dapm, "AGCOUT");

	return 0;
}

__attribute__((used)) static int ams_delta_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &ams_delta_audio_card;
	int ret;

	card->dev = &pdev->dev;

	ret = snd_soc_register_card(card);
	if (ret) {
		dev_err(&pdev->dev, "snd_soc_register_card failed (%d)\n", ret);
		card->dev = NULL;
		return ret;
	}
	return 0;
}

__attribute__((used)) static int ams_delta_remove(struct platform_device *pdev)
{
	struct snd_soc_card *card = platform_get_drvdata(pdev);

	if (tty_unregister_ldisc(N_V253) != 0)
		dev_warn(&pdev->dev,
			"failed to unregister V253 line discipline\n");

	snd_soc_unregister_card(card);
	card->dev = NULL;
	return 0;
}

