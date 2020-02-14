#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;
typedef  struct TYPE_14__   TYPE_12__ ;

/* Type definitions */
typedef  int u32 ;
struct snd_jack {struct hda_jack_tbl* private_data; } ;
struct snd_dma_buffer {int dummy; } ;
struct hda_pcm {int /*<<< orphan*/  kref; } ;
struct hda_jack_tbl {scalar_t__ nid; unsigned char tag; int jack_dirty; int phantom_jack; int pin_sense; scalar_t__ gating_jack; scalar_t__ gated_jack; int jack_detect; int type; struct hda_jack_callback* callback; TYPE_3__* jack; scalar_t__ block_report; } ;
struct hda_jack_callback {scalar_t__ nid; int /*<<< orphan*/  (* func ) (struct hda_codec*,struct hda_jack_callback*) ;struct hda_jack_callback* next; } ;
struct TYPE_14__ {int used; struct hda_jack_tbl* list; } ;
struct TYPE_18__ {scalar_t__ start_nid; scalar_t__ num_nodes; } ;
struct hda_codec {int* wcaps; scalar_t__ jackpoll_interval; TYPE_12__ jacktbl; int /*<<< orphan*/  card; TYPE_1__* bus; scalar_t__ inv_jack_detect; int /*<<< orphan*/  no_trigger_sense; scalar_t__ no_jack_detect; TYPE_5__ core; } ;
struct hda_bus {int /*<<< orphan*/  core; } ;
struct auto_pin_cfg {scalar_t__ line_out_type; int line_outs; int hp_outs; scalar_t__ const* line_out_pins; scalar_t__ const* hp_pins; int speaker_outs; scalar_t__ const* speaker_pins; int num_inputs; scalar_t__* dig_out_pins; int dig_outs; scalar_t__ dig_in_pin; scalar_t__ mono_out_pin; TYPE_2__* inputs; } ;
typedef  int /*<<< orphan*/  name ;
typedef  scalar_t__ hda_nid_t ;
typedef  int /*<<< orphan*/  (* hda_jack_callback_fn ) (struct hda_codec*,struct hda_jack_callback*) ;
struct TYPE_17__ {void (* private_free ) (struct snd_jack*) ;struct hda_jack_tbl* private_data; } ;
struct TYPE_16__ {scalar_t__ pin; scalar_t__ is_headphone_mic; } ;
struct TYPE_15__ {int /*<<< orphan*/  shutdown; } ;

/* Variables and functions */
 int AC_DEFCFG_MISC_NO_PRESENCE ; 
#define  AC_JACK_DIG_OTHER_OUT 133 
#define  AC_JACK_HP_OUT 132 
#define  AC_JACK_LINE_OUT 131 
#define  AC_JACK_MIC_IN 130 
 unsigned int AC_JACK_PORT_COMPLEX ; 
 unsigned int AC_JACK_PORT_NONE ; 
#define  AC_JACK_SPDIF_OUT 129 
#define  AC_JACK_SPEAKER 128 
 int /*<<< orphan*/  AC_PAR_PIN_CAP ; 
 int AC_PINCAP_PRES_DETECT ; 
 int AC_PINCAP_TRIG_REQ ; 
 int AC_PINSENSE_PRESENCE ; 
 unsigned int AC_UNSOL_RES_TAG_SHIFT ; 
 unsigned int AC_USRSP_EN ; 
 unsigned int AC_VERB_GET_PIN_SENSE ; 
 unsigned int AC_VERB_SET_PIN_SENSE ; 
 unsigned int AC_VERB_SET_UNSOLICITED_ENABLE ; 
 int AC_WCAP_CHAN_CNT_EXT ; 
 unsigned int AC_WCAP_TYPE ; 
 unsigned int AC_WCAP_TYPE_SHIFT ; 
 int AC_WCAP_UNSOL_CAP ; 
 scalar_t__ AUTO_PIN_HP_OUT ; 
 scalar_t__ AUTO_PIN_SPEAKER_OUT ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOSYS ; 
 struct hda_jack_callback* ERR_PTR (int) ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HDA_JACK_NOT_PRESENT ; 
 int HDA_JACK_PHANTOM ; 
 int HDA_JACK_PRESENT ; 
 int PTR_ERR_OR_ZERO (struct hda_jack_callback*) ; 
 int SNDRV_CTL_ELEM_ID_NAME_MAXLEN ; 
 int SND_JACK_AVOUT ; 
 int SND_JACK_HEADPHONE ; 
 int SND_JACK_LINEIN ; 
 int SND_JACK_LINEOUT ; 
 int SND_JACK_MICROPHONE ; 
 int _snd_hda_set_pin_ctl (struct hda_codec*,scalar_t__,unsigned int,int) ; 
 unsigned int get_defcfg_connect (unsigned int) ; 
 int get_defcfg_device (unsigned int) ; 
 int get_defcfg_misc (unsigned int) ; 
 unsigned int get_jack_plug_state (int) ; 
 int /*<<< orphan*/  kfree (struct hda_jack_callback*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 struct hda_jack_callback* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_array_free (TYPE_12__*) ; 
 struct hda_jack_tbl* snd_array_new (TYPE_12__*) ; 
 int /*<<< orphan*/  snd_device_free (int /*<<< orphan*/ ,TYPE_3__*) ; 
 unsigned int snd_hda_codec_get_pincfg (struct hda_codec*,scalar_t__) ; 
 int snd_hda_get_connections (struct hda_codec*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_get_pin_label (struct hda_codec*,scalar_t__,struct auto_pin_cfg const*,char*,int,int /*<<< orphan*/ *) ; 
 int snd_hda_jack_detect_state (struct hda_codec*,scalar_t__) ; 
 int snd_hda_param_read (struct hda_codec*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hdac_bus_queue_event (int /*<<< orphan*/ *,int,int) ; 
 int snd_hdac_check_power_state (TYPE_5__*,scalar_t__,unsigned int) ; 
 unsigned int snd_hdac_codec_read (TYPE_5__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_codec_write (TYPE_5__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_override_parm (TYPE_5__*,scalar_t__,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_hdac_regmap_write (TYPE_5__*,scalar_t__,unsigned int,unsigned int) ; 
 unsigned int snd_hdac_sync_power_state (TYPE_5__*,scalar_t__,unsigned int) ; 
 int snd_jack_new (int /*<<< orphan*/ ,char const*,int,TYPE_3__**,int,int) ; 
 int /*<<< orphan*/  snd_jack_report (TYPE_3__*,int) ; 
 int /*<<< orphan*/  strlcpy (char*,char const*,int) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  strncat (char*,char*,int) ; 
 int /*<<< orphan*/  stub1 (struct hda_codec*,struct hda_jack_callback*) ; 
 int /*<<< orphan*/  stub2 (struct hda_codec*,struct hda_jack_callback*) ; 

__attribute__((used)) static inline unsigned int
snd_hda_codec_read(struct hda_codec *codec, hda_nid_t nid,
				int flags,
				unsigned int verb, unsigned int parm)
{
	return snd_hdac_codec_read(&codec->core, nid, flags, verb, parm);
}

__attribute__((used)) static inline int
snd_hda_codec_write(struct hda_codec *codec, hda_nid_t nid, int flags,
			unsigned int verb, unsigned int parm)
{
	return snd_hdac_codec_write(&codec->core, nid, flags, verb, parm);
}

__attribute__((used)) static inline int
snd_hda_get_num_conns(struct hda_codec *codec, hda_nid_t nid)
{
	return snd_hda_get_connections(codec, nid, NULL, 0);
}

__attribute__((used)) static inline void
snd_hda_queue_unsol_event(struct hda_bus *bus, u32 res, u32 res_ex)
{
	snd_hdac_bus_queue_event(&bus->core, res, res_ex);
}

__attribute__((used)) static inline int
snd_hda_codec_write_cache(struct hda_codec *codec, hda_nid_t nid,
			  int flags, unsigned int verb, unsigned int parm)
{
	return snd_hdac_regmap_write(&codec->core, nid, verb, parm);
}

__attribute__((used)) static inline void snd_hda_codec_pcm_get(struct hda_pcm *pcm)
{
	kref_get(&pcm->kref);
}

__attribute__((used)) static inline
int hda_call_check_power_status(struct hda_codec *codec, hda_nid_t nid)
{
#ifdef CONFIG_PM
	if (codec->patch_ops.check_power_status)
		return codec->patch_ops.check_power_status(codec, nid);
#endif
	return 0;
}

__attribute__((used)) static inline void snd_hda_set_power_save(struct hda_bus *bus, int delay) {}

__attribute__((used)) static inline int
snd_hda_codec_load_dsp_prepare(struct hda_codec *codec, unsigned int format,
				unsigned int size,
				struct snd_dma_buffer *bufp)
{
	return -ENOSYS;
}

__attribute__((used)) static inline void
snd_hda_codec_load_dsp_trigger(struct hda_codec *codec, bool start) {}

__attribute__((used)) static inline void
snd_hda_codec_load_dsp_cleanup(struct hda_codec *codec,
				struct snd_dma_buffer *dmab) {}

__attribute__((used)) static inline int snd_hda_codec_proc_new(struct hda_codec *codec) { return 0; }

__attribute__((used)) static inline int
snd_hda_set_pin_ctl(struct hda_codec *codec, hda_nid_t pin, unsigned int val)
{
	return _snd_hda_set_pin_ctl(codec, pin, val, false);
}

__attribute__((used)) static inline int
snd_hda_set_pin_ctl_cache(struct hda_codec *codec, hda_nid_t pin,
			  unsigned int val)
{
	return _snd_hda_set_pin_ctl(codec, pin, val, true);
}

__attribute__((used)) static inline u32 get_wcaps(struct hda_codec *codec, hda_nid_t nid)
{
	if (nid < codec->core.start_nid ||
	    nid >= codec->core.start_nid + codec->core.num_nodes)
		return 0;
	return codec->wcaps[nid - codec->core.start_nid];
}

__attribute__((used)) static inline int get_wcaps_type(unsigned int wcaps)
{
	if (!wcaps)
		return -1; /* invalid type */
	return (wcaps & AC_WCAP_TYPE) >> AC_WCAP_TYPE_SHIFT;
}

__attribute__((used)) static inline unsigned int get_wcaps_channels(u32 wcaps)
{
	unsigned int chans;

	chans = (wcaps & AC_WCAP_CHAN_CNT_EXT) >> 13;
	chans = ((chans << 1) | 1) + 1;

	return chans;
}

__attribute__((used)) static inline void snd_hda_override_wcaps(struct hda_codec *codec,
					  hda_nid_t nid, u32 val)
{
	if (nid >= codec->core.start_nid &&
	    nid < codec->core.start_nid + codec->core.num_nodes)
		codec->wcaps[nid - codec->core.start_nid] = val;
}

__attribute__((used)) static inline u32
snd_hda_query_pin_caps(struct hda_codec *codec, hda_nid_t nid)
{
	return snd_hda_param_read(codec, nid, AC_PAR_PIN_CAP);

}

__attribute__((used)) static inline int
snd_hda_override_pin_caps(struct hda_codec *codec, hda_nid_t nid,
			  unsigned int caps)
{
	return snd_hdac_override_parm(&codec->core, nid, AC_PAR_PIN_CAP, caps);
}

__attribute__((used)) static inline int snd_hda_create_hwdep(struct hda_codec *codec) { return 0; }

__attribute__((used)) static inline
const char *snd_hda_get_hint(struct hda_codec *codec, const char *key)
{
	return NULL;
}

__attribute__((used)) static inline
int snd_hda_get_bool_hint(struct hda_codec *codec, const char *key)
{
	return -ENOENT;
}

__attribute__((used)) static inline
int snd_hda_get_int_hint(struct hda_codec *codec, const char *key, int *valp)
{
	return -ENOENT;
}

__attribute__((used)) static inline bool
snd_hda_check_power_state(struct hda_codec *codec, hda_nid_t nid,
			  unsigned int target_state)
{
	return snd_hdac_check_power_state(&codec->core, nid, target_state);
}

__attribute__((used)) static inline unsigned int snd_hda_sync_power_state(struct hda_codec *codec,
						    hda_nid_t nid,
						    unsigned int target_state)
{
	return snd_hdac_sync_power_state(&codec->core, nid, target_state);
}

__attribute__((used)) static inline int auto_cfg_hp_outs(const struct auto_pin_cfg *cfg)
{
	return (cfg->line_out_type == AUTO_PIN_HP_OUT) ?
	       cfg->line_outs : cfg->hp_outs;
}

__attribute__((used)) static inline const hda_nid_t *auto_cfg_hp_pins(const struct auto_pin_cfg *cfg)
{
	return (cfg->line_out_type == AUTO_PIN_HP_OUT) ?
	       cfg->line_out_pins : cfg->hp_pins;
}

__attribute__((used)) static inline int auto_cfg_speaker_outs(const struct auto_pin_cfg *cfg)
{
	return (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT) ?
	       cfg->line_outs : cfg->speaker_outs;
}

__attribute__((used)) static inline const hda_nid_t *auto_cfg_speaker_pins(const struct auto_pin_cfg *cfg)
{
	return (cfg->line_out_type == AUTO_PIN_SPEAKER_OUT) ?
	       cfg->line_out_pins : cfg->speaker_pins;
}

__attribute__((used)) static inline bool snd_hda_jack_detect(struct hda_codec *codec, hda_nid_t nid)
{
	return snd_hda_jack_detect_state(codec, nid) != HDA_JACK_NOT_PRESENT;
}

bool is_jack_detectable(struct hda_codec *codec, hda_nid_t nid)
{
	if (codec->no_jack_detect)
		return false;
	if (!(snd_hda_query_pin_caps(codec, nid) & AC_PINCAP_PRES_DETECT))
		return false;
	if (get_defcfg_misc(snd_hda_codec_get_pincfg(codec, nid)) &
	     AC_DEFCFG_MISC_NO_PRESENCE)
		return false;
	if (!(get_wcaps(codec, nid) & AC_WCAP_UNSOL_CAP) &&
	    !codec->jackpoll_interval)
		return false;
	return true;
}

__attribute__((used)) static u32 read_pin_sense(struct hda_codec *codec, hda_nid_t nid)
{
	u32 pincap;
	u32 val;

	if (!codec->no_trigger_sense) {
		pincap = snd_hda_query_pin_caps(codec, nid);
		if (pincap & AC_PINCAP_TRIG_REQ) /* need trigger? */
			snd_hda_codec_read(codec, nid, 0,
					AC_VERB_SET_PIN_SENSE, 0);
	}
	val = snd_hda_codec_read(codec, nid, 0,
				  AC_VERB_GET_PIN_SENSE, 0);
	if (codec->inv_jack_detect)
		val ^= AC_PINSENSE_PRESENCE;
	return val;
}

struct hda_jack_tbl *
snd_hda_jack_tbl_get(struct hda_codec *codec, hda_nid_t nid)
{
	struct hda_jack_tbl *jack = codec->jacktbl.list;
	int i;

	if (!nid || !jack)
		return NULL;
	for (i = 0; i < codec->jacktbl.used; i++, jack++)
		if (jack->nid == nid)
			return jack;
	return NULL;
}

struct hda_jack_tbl *
snd_hda_jack_tbl_get_from_tag(struct hda_codec *codec, unsigned char tag)
{
	struct hda_jack_tbl *jack = codec->jacktbl.list;
	int i;

	if (!tag || !jack)
		return NULL;
	for (i = 0; i < codec->jacktbl.used; i++, jack++)
		if (jack->tag == tag)
			return jack;
	return NULL;
}

__attribute__((used)) static struct hda_jack_tbl *
snd_hda_jack_tbl_new(struct hda_codec *codec, hda_nid_t nid)
{
	struct hda_jack_tbl *jack = snd_hda_jack_tbl_get(codec, nid);
	if (jack)
		return jack;
	jack = snd_array_new(&codec->jacktbl);
	if (!jack)
		return NULL;
	jack->nid = nid;
	jack->jack_dirty = 1;
	jack->tag = codec->jacktbl.used;
	return jack;
}

void snd_hda_jack_tbl_clear(struct hda_codec *codec)
{
	struct hda_jack_tbl *jack = codec->jacktbl.list;
	int i;

	for (i = 0; i < codec->jacktbl.used; i++, jack++) {
		struct hda_jack_callback *cb, *next;

		/* free jack instances manually when clearing/reconfiguring */
		if (!codec->bus->shutdown && jack->jack)
			snd_device_free(codec->card, jack->jack);

		for (cb = jack->callback; cb; cb = next) {
			next = cb->next;
			kfree(cb);
		}
	}
	snd_array_free(&codec->jacktbl);
}

__attribute__((used)) static void jack_detect_update(struct hda_codec *codec,
			       struct hda_jack_tbl *jack)
{
	if (!jack->jack_dirty)
		return;

	if (jack->phantom_jack)
		jack->pin_sense = AC_PINSENSE_PRESENCE;
	else
		jack->pin_sense = read_pin_sense(codec, jack->nid);

	/* A gating jack indicates the jack is invalid if gating is unplugged */
	if (jack->gating_jack && !snd_hda_jack_detect(codec, jack->gating_jack))
		jack->pin_sense &= ~AC_PINSENSE_PRESENCE;

	jack->jack_dirty = 0;

	/* If a jack is gated by this one update it. */
	if (jack->gated_jack) {
		struct hda_jack_tbl *gated =
			snd_hda_jack_tbl_get(codec, jack->gated_jack);
		if (gated) {
			gated->jack_dirty = 1;
			jack_detect_update(codec, gated);
		}
	}
}

void snd_hda_jack_set_dirty_all(struct hda_codec *codec)
{
	struct hda_jack_tbl *jack = codec->jacktbl.list;
	int i;

	for (i = 0; i < codec->jacktbl.used; i++, jack++)
		if (jack->nid)
			jack->jack_dirty = 1;
}

u32 snd_hda_pin_sense(struct hda_codec *codec, hda_nid_t nid)
{
	struct hda_jack_tbl *jack = snd_hda_jack_tbl_get(codec, nid);
	if (jack) {
		jack_detect_update(codec, jack);
		return jack->pin_sense;
	}
	return read_pin_sense(codec, nid);
}

int snd_hda_jack_detect_state(struct hda_codec *codec, hda_nid_t nid)
{
	struct hda_jack_tbl *jack = snd_hda_jack_tbl_get(codec, nid);
	if (jack && jack->phantom_jack)
		return HDA_JACK_PHANTOM;
	else if (snd_hda_pin_sense(codec, nid) & AC_PINSENSE_PRESENCE)
		return HDA_JACK_PRESENT;
	else
		return HDA_JACK_NOT_PRESENT;
}

struct hda_jack_callback *
snd_hda_jack_detect_enable_callback(struct hda_codec *codec, hda_nid_t nid,
				    hda_jack_callback_fn func)
{
	struct hda_jack_tbl *jack;
	struct hda_jack_callback *callback = NULL;
	int err;

	jack = snd_hda_jack_tbl_new(codec, nid);
	if (!jack)
		return ERR_PTR(-ENOMEM);
	if (func) {
		callback = kzalloc(sizeof(*callback), GFP_KERNEL);
		if (!callback)
			return ERR_PTR(-ENOMEM);
		callback->func = func;
		callback->nid = jack->nid;
		callback->next = jack->callback;
		jack->callback = callback;
	}

	if (jack->jack_detect)
		return callback; /* already registered */
	jack->jack_detect = 1;
	if (codec->jackpoll_interval > 0)
		return callback; /* No unsol if we're polling instead */
	err = snd_hda_codec_write_cache(codec, nid, 0,
					 AC_VERB_SET_UNSOLICITED_ENABLE,
					 AC_USRSP_EN | jack->tag);
	if (err < 0)
		return ERR_PTR(err);
	return callback;
}

int snd_hda_jack_detect_enable(struct hda_codec *codec, hda_nid_t nid)
{
	return PTR_ERR_OR_ZERO(snd_hda_jack_detect_enable_callback(codec, nid, NULL));
}

int snd_hda_jack_set_gating_jack(struct hda_codec *codec, hda_nid_t gated_nid,
				 hda_nid_t gating_nid)
{
	struct hda_jack_tbl *gated = snd_hda_jack_tbl_new(codec, gated_nid);
	struct hda_jack_tbl *gating = snd_hda_jack_tbl_new(codec, gating_nid);

	if (!gated || !gating)
		return -EINVAL;

	gated->gating_jack = gating_nid;
	gating->gated_jack = gated_nid;

	return 0;
}

void snd_hda_jack_report_sync(struct hda_codec *codec)
{
	struct hda_jack_tbl *jack;
	int i, state;

	/* update all jacks at first */
	jack = codec->jacktbl.list;
	for (i = 0; i < codec->jacktbl.used; i++, jack++)
		if (jack->nid)
			jack_detect_update(codec, jack);

	/* report the updated jacks; it's done after updating all jacks
	 * to make sure that all gating jacks properly have been set
	 */
	jack = codec->jacktbl.list;
	for (i = 0; i < codec->jacktbl.used; i++, jack++)
		if (jack->nid) {
			if (!jack->jack || jack->block_report)
				continue;
			state = get_jack_plug_state(jack->pin_sense);
			snd_jack_report(jack->jack,
					state ? jack->type : 0);
		}
}

__attribute__((used)) static int get_input_jack_type(struct hda_codec *codec, hda_nid_t nid)
{
	unsigned int def_conf = snd_hda_codec_get_pincfg(codec, nid);
	switch (get_defcfg_device(def_conf)) {
	case AC_JACK_LINE_OUT:
	case AC_JACK_SPEAKER:
		return SND_JACK_LINEOUT;
	case AC_JACK_HP_OUT:
		return SND_JACK_HEADPHONE;
	case AC_JACK_SPDIF_OUT:
	case AC_JACK_DIG_OTHER_OUT:
		return SND_JACK_AVOUT;
	case AC_JACK_MIC_IN:
		return SND_JACK_MICROPHONE;
	default:
		return SND_JACK_LINEIN;
	}
}

__attribute__((used)) static void hda_free_jack_priv(struct snd_jack *jack)
{
	struct hda_jack_tbl *jacks = jack->private_data;
	jacks->nid = 0;
	jacks->jack = NULL;
}

int snd_hda_jack_add_kctl(struct hda_codec *codec, hda_nid_t nid,
			  const char *name, bool phantom_jack)
{
	struct hda_jack_tbl *jack;
	int err, state, type;

	jack = snd_hda_jack_tbl_new(codec, nid);
	if (!jack)
		return 0;
	if (jack->jack)
		return 0; /* already created */

	type = get_input_jack_type(codec, nid);
	err = snd_jack_new(codec->card, name, type,
			   &jack->jack, true, phantom_jack);
	if (err < 0)
		return err;

	jack->phantom_jack = !!phantom_jack;
	jack->type = type;
	jack->jack->private_data = jack;
	jack->jack->private_free = hda_free_jack_priv;
	state = snd_hda_jack_detect(codec, nid);
	snd_jack_report(jack->jack, state ? jack->type : 0);

	return 0;
}

__attribute__((used)) static int add_jack_kctl(struct hda_codec *codec, hda_nid_t nid,
			 const struct auto_pin_cfg *cfg,
			 const char *base_name)
{
	unsigned int def_conf, conn;
	char name[SNDRV_CTL_ELEM_ID_NAME_MAXLEN];
	int err;
	bool phantom_jack;

	if (!nid)
		return 0;
	def_conf = snd_hda_codec_get_pincfg(codec, nid);
	conn = get_defcfg_connect(def_conf);
	if (conn == AC_JACK_PORT_NONE)
		return 0;
	phantom_jack = (conn != AC_JACK_PORT_COMPLEX) ||
		       !is_jack_detectable(codec, nid);

	if (base_name)
		strlcpy(name, base_name, sizeof(name));
	else
		snd_hda_get_pin_label(codec, nid, cfg, name, sizeof(name), NULL);
	if (phantom_jack)
		/* Example final name: "Internal Mic Phantom Jack" */
		strncat(name, " Phantom", sizeof(name) - strlen(name) - 1);
	err = snd_hda_jack_add_kctl(codec, nid, name, phantom_jack);
	if (err < 0)
		return err;

	if (!phantom_jack)
		return snd_hda_jack_detect_enable(codec, nid);
	return 0;
}

int snd_hda_jack_add_kctls(struct hda_codec *codec,
			   const struct auto_pin_cfg *cfg)
{
	const hda_nid_t *p;
	int i, err;

	for (i = 0; i < cfg->num_inputs; i++) {
		/* If we have headphone mics; make sure they get the right name
		   before grabbed by output pins */
		if (cfg->inputs[i].is_headphone_mic) {
			if (auto_cfg_hp_outs(cfg) == 1)
				err = add_jack_kctl(codec, auto_cfg_hp_pins(cfg)[0],
						    cfg, "Headphone Mic");
			else
				err = add_jack_kctl(codec, cfg->inputs[i].pin,
						    cfg, "Headphone Mic");
		} else
			err = add_jack_kctl(codec, cfg->inputs[i].pin, cfg,
					    NULL);
		if (err < 0)
			return err;
	}

	for (i = 0, p = cfg->line_out_pins; i < cfg->line_outs; i++, p++) {
		err = add_jack_kctl(codec, *p, cfg, NULL);
		if (err < 0)
			return err;
	}
	for (i = 0, p = cfg->hp_pins; i < cfg->hp_outs; i++, p++) {
		if (*p == *cfg->line_out_pins) /* might be duplicated */
			break;
		err = add_jack_kctl(codec, *p, cfg, NULL);
		if (err < 0)
			return err;
	}
	for (i = 0, p = cfg->speaker_pins; i < cfg->speaker_outs; i++, p++) {
		if (*p == *cfg->line_out_pins) /* might be duplicated */
			break;
		err = add_jack_kctl(codec, *p, cfg, NULL);
		if (err < 0)
			return err;
	}
	for (i = 0, p = cfg->dig_out_pins; i < cfg->dig_outs; i++, p++) {
		err = add_jack_kctl(codec, *p, cfg, NULL);
		if (err < 0)
			return err;
	}
	err = add_jack_kctl(codec, cfg->dig_in_pin, cfg, NULL);
	if (err < 0)
		return err;
	err = add_jack_kctl(codec, cfg->mono_out_pin, cfg, NULL);
	if (err < 0)
		return err;
	return 0;
}

__attribute__((used)) static void call_jack_callback(struct hda_codec *codec,
			       struct hda_jack_tbl *jack)
{
	struct hda_jack_callback *cb;

	for (cb = jack->callback; cb; cb = cb->next)
		cb->func(codec, cb);
	if (jack->gated_jack) {
		struct hda_jack_tbl *gated =
			snd_hda_jack_tbl_get(codec, jack->gated_jack);
		if (gated) {
			for (cb = gated->callback; cb; cb = cb->next)
				cb->func(codec, cb);
		}
	}
}

void snd_hda_jack_unsol_event(struct hda_codec *codec, unsigned int res)
{
	struct hda_jack_tbl *event;
	int tag = (res >> AC_UNSOL_RES_TAG_SHIFT) & 0x7f;

	event = snd_hda_jack_tbl_get_from_tag(codec, tag);
	if (!event)
		return;
	event->jack_dirty = 1;

	call_jack_callback(codec, event);
	snd_hda_jack_report_sync(codec);
}

void snd_hda_jack_poll_all(struct hda_codec *codec)
{
	struct hda_jack_tbl *jack = codec->jacktbl.list;
	int i, changes = 0;

	for (i = 0; i < codec->jacktbl.used; i++, jack++) {
		unsigned int old_sense;
		if (!jack->nid || !jack->jack_dirty || jack->phantom_jack)
			continue;
		old_sense = get_jack_plug_state(jack->pin_sense);
		jack_detect_update(codec, jack);
		if (old_sense == get_jack_plug_state(jack->pin_sense))
			continue;
		changes = 1;
		call_jack_callback(codec, jack);
	}
	if (changes)
		snd_hda_jack_report_sync(codec);
}

