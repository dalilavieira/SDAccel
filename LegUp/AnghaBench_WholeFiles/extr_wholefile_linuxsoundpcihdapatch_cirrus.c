#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;
typedef  struct TYPE_14__   TYPE_12__ ;

/* Type definitions */
typedef  int u32 ;
struct snd_kcontrol {int (* put ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;} ;
struct snd_dma_buffer {int dummy; } ;
struct TYPE_18__ {int* value; } ;
struct TYPE_19__ {TYPE_4__ integer; } ;
struct snd_ctl_elem_value {TYPE_5__ value; } ;
struct TYPE_16__ {int max; scalar_t__ min; } ;
struct TYPE_17__ {TYPE_2__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_3__ value; int /*<<< orphan*/  type; } ;
struct hda_pintbl {int member_0; int member_1; } ;
struct hda_pcm {int /*<<< orphan*/  kref; } ;
struct hda_jack_callback {int dummy; } ;
struct hda_fixup {int dummy; } ;
struct TYPE_20__ {scalar_t__ start_nid; scalar_t__ num_nodes; } ;
struct hda_codec {int* wcaps; int power_save_node; int single_adc_amp; scalar_t__ fixup_id; int inv_jack_detect; void* patch_ops; struct cs_spec* spec; TYPE_6__ core; } ;
struct hda_bus {int /*<<< orphan*/  core; } ;
struct auto_pin_cfg {scalar_t__ line_out_type; int line_outs; int hp_outs; scalar_t__ const* line_out_pins; scalar_t__ const* hp_pins; int speaker_outs; scalar_t__ const* speaker_pins; scalar_t__* dig_out_pins; int dig_outs; } ;
struct TYPE_15__ {int num_items; } ;
struct TYPE_14__ {int master_mute; int* dyn_adc_idx; void (* automute_hook ) (struct hda_codec*) ;unsigned long long out_vol_mask; struct auto_pin_cfg autocfg; int /*<<< orphan*/ * adc_nids; TYPE_1__ input_mux; scalar_t__ dyn_adc_switch; scalar_t__ hp_jack_present; scalar_t__ automute_speaker; } ;
struct cs_spec {scalar_t__ vendor_nid; int spdif_present; int sense_b; int gpio_eapd_hp; int gpio_eapd_speaker; int gpio_data; int gpio_mask; unsigned int gpio_dir; int (* spdif_sw_put ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int spdif_detect; TYPE_12__ gen; } ;
typedef  scalar_t__ hda_nid_t ;

/* Variables and functions */
 int AC_AMPCAP_NUM_STEPS_SHIFT ; 
 unsigned int AC_AMPCAP_OFFSET ; 
 unsigned int AC_AMPCAP_OFFSET_SHIFT ; 
 unsigned int AC_DEFCFG_PORT_CONN ; 
 unsigned int AC_DEFCFG_PORT_CONN_SHIFT ; 
 unsigned int AC_JACK_PORT_NONE ; 
 int /*<<< orphan*/  AC_PAR_PIN_CAP ; 
 unsigned int AC_VERB_GET_PROC_COEF ; 
 unsigned int AC_VERB_SET_COEF_INDEX ; 
 unsigned int AC_VERB_SET_GPIO_DATA ; 
 unsigned int AC_VERB_SET_GPIO_DIRECTION ; 
 unsigned int AC_VERB_SET_GPIO_MASK ; 
 unsigned int AC_VERB_SET_PROC_COEF ; 
 int AC_WCAP_CHAN_CNT_EXT ; 
 int AC_WCAP_STEREO ; 
 unsigned int AC_WCAP_TYPE ; 
 unsigned int AC_WCAP_TYPE_SHIFT ; 
 int AC_WCAP_UNSOL_CAP ; 
 scalar_t__ AUTO_PIN_HP_OUT ; 
 scalar_t__ AUTO_PIN_SPEAKER_OUT ; 
 scalar_t__ CS4208_GPIO0 ; 
 int CS4208_VENDOR_NID ; 
 int CS420X_VENDOR_NID ; 
 scalar_t__ CS4210_DAC_NID ; 
 int CS4210_VENDOR_NID ; 
 int CS4213_VENDOR_NID ; 
 scalar_t__ CS421X_DMIC_PIN_NID ; 
 unsigned int CS421X_IDX_DEV_CFG ; 
 unsigned int CS421X_IDX_SPK_CTL ; 
 scalar_t__ CS_DIG_OUT2_PIN_NID ; 
 scalar_t__ CS_DMIC1_PIN_NID ; 
 scalar_t__ CS_DMIC2_PIN_NID ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int HDA_FIXUP_ACT_BUILD ; 
 int HDA_FIXUP_ACT_PRE_PROBE ; 
 int HDA_FIXUP_ACT_PROBE ; 
 scalar_t__ HDA_FIXUP_ID_NOT_SET ; 
 int /*<<< orphan*/  HDA_INPUT ; 
 scalar_t__ HDA_JACK_NOT_PRESENT ; 
 int /*<<< orphan*/  HDA_OUTPUT ; 
 unsigned int IDX_BEEP_CFG ; 
 unsigned int IDX_SPDIF_CTL ; 
 void* PIN_OUT ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int _snd_hda_set_pin_ctl (struct hda_codec*,scalar_t__,unsigned int,int) ; 
 int /*<<< orphan*/  cs4208_coef_init_verbs ; 
 int /*<<< orphan*/  cs4208_fixup_tbl ; 
 int /*<<< orphan*/  cs4208_fixups ; 
 int /*<<< orphan*/  cs4208_mac_fixup_tbl ; 
 int /*<<< orphan*/ * cs4208_models ; 
 int /*<<< orphan*/  cs420x_fixup_tbl ; 
 int /*<<< orphan*/  cs420x_fixups ; 
 int /*<<< orphan*/ * cs420x_models ; 
 int /*<<< orphan*/  cs421x_coef_init_verbs ; 
 int /*<<< orphan*/  cs421x_coef_init_verbs_A1_silicon_fixes ; 
 int /*<<< orphan*/  cs421x_fixup_tbl ; 
 int /*<<< orphan*/  cs421x_fixups ; 
 int /*<<< orphan*/ * cs421x_models ; 
 void* cs421x_patch_ops ; 
 int /*<<< orphan*/  cs421x_speaker_boost_ctl ; 
 int /*<<< orphan*/  cs_coef_init_verbs ; 
 int /*<<< orphan*/  cs_errata_init_verbs ; 
 int /*<<< orphan*/  cs_free (struct hda_codec*) ; 
 void* cs_patch_ops ; 
 unsigned int get_defcfg_connect (unsigned int) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 struct cs_spec* kzalloc (int,int /*<<< orphan*/ ) ; 
 unsigned int query_amp_caps (struct hda_codec*,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_apply_fixup (struct hda_codec*,int) ; 
 int /*<<< orphan*/  snd_hda_apply_pincfgs (struct hda_codec*,struct hda_pintbl const*) ; 
 unsigned int snd_hda_codec_get_pincfg (struct hda_codec*,scalar_t__) ; 
 int /*<<< orphan*/  snd_hda_codec_set_pincfg (struct hda_codec*,scalar_t__,unsigned int) ; 
 struct snd_kcontrol* snd_hda_find_mixer_ctl (struct hda_codec*,char*) ; 
 int /*<<< orphan*/  snd_hda_gen_add_kctl (TYPE_12__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int snd_hda_gen_build_controls (struct hda_codec*) ; 
 int /*<<< orphan*/  snd_hda_gen_fix_pin_power (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_gen_init (struct hda_codec*) ; 
 int snd_hda_gen_parse_auto_config (struct hda_codec*,struct auto_pin_cfg*) ; 
 int /*<<< orphan*/  snd_hda_gen_spec_init (TYPE_12__*) ; 
 int /*<<< orphan*/  snd_hda_gen_update_outputs (struct hda_codec*) ; 
 int snd_hda_get_connections (struct hda_codec*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_jack_detect_enable_callback (struct hda_codec*,scalar_t__,void (*) (struct hda_codec*,struct hda_jack_callback*)) ; 
 scalar_t__ snd_hda_jack_detect_state (struct hda_codec*,scalar_t__) ; 
 int /*<<< orphan*/  snd_hda_override_amp_caps (struct hda_codec*,scalar_t__,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_hda_param_read (struct hda_codec*,scalar_t__,int /*<<< orphan*/ ) ; 
 int snd_hda_parse_pin_defcfg (struct hda_codec*,struct auto_pin_cfg*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_pick_fixup (struct hda_codec*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_sequence_write (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hdac_bus_queue_event (int /*<<< orphan*/ *,int,int) ; 
 int snd_hdac_check_power_state (TYPE_6__*,scalar_t__,unsigned int) ; 
 unsigned int snd_hdac_codec_read (TYPE_6__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_codec_write (TYPE_6__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_override_parm (TYPE_6__*,scalar_t__,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_hdac_regmap_write (TYPE_6__*,scalar_t__,unsigned int,unsigned int) ; 
 unsigned int snd_hdac_sync_power_state (TYPE_6__*,scalar_t__,unsigned int) ; 
 struct hda_codec* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int stub1 (struct snd_kcontrol*,struct snd_ctl_elem_value*) ; 

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

__attribute__((used)) static inline int cs_vendor_coef_get(struct hda_codec *codec, unsigned int idx)
{
	struct cs_spec *spec = codec->spec;
	snd_hda_codec_write(codec, spec->vendor_nid, 0,
			    AC_VERB_SET_COEF_INDEX, idx);
	return snd_hda_codec_read(codec, spec->vendor_nid, 0,
				  AC_VERB_GET_PROC_COEF, 0);
}

__attribute__((used)) static inline void cs_vendor_coef_set(struct hda_codec *codec, unsigned int idx,
				      unsigned int coef)
{
	struct cs_spec *spec = codec->spec;
	snd_hda_codec_write(codec, spec->vendor_nid, 0,
			    AC_VERB_SET_COEF_INDEX, idx);
	snd_hda_codec_write(codec, spec->vendor_nid, 0,
			    AC_VERB_SET_PROC_COEF, coef);
}

__attribute__((used)) static void cs_automute(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;

	/* mute HPs if spdif jack (SENSE_B) is present */
	spec->gen.master_mute = !!(spec->spdif_present && spec->sense_b);

	snd_hda_gen_update_outputs(codec);

	if (spec->gpio_eapd_hp || spec->gpio_eapd_speaker) {
		if (spec->gen.automute_speaker)
			spec->gpio_data = spec->gen.hp_jack_present ?
				spec->gpio_eapd_hp : spec->gpio_eapd_speaker;
		else
			spec->gpio_data =
				spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
		snd_hda_codec_write(codec, 0x01, 0,
				    AC_VERB_SET_GPIO_DATA, spec->gpio_data);
	}
}

__attribute__((used)) static bool is_active_pin(struct hda_codec *codec, hda_nid_t nid)
{
	unsigned int val;
	val = snd_hda_codec_get_pincfg(codec, nid);
	return (get_defcfg_connect(val) != AC_JACK_PORT_NONE);
}

__attribute__((used)) static void init_input_coef(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;
	unsigned int coef;

	/* CS420x has multiple ADC, CS421x has single ADC */
	if (spec->vendor_nid == CS420X_VENDOR_NID) {
		coef = cs_vendor_coef_get(codec, IDX_BEEP_CFG);
		if (is_active_pin(codec, CS_DMIC2_PIN_NID))
			coef |= 1 << 4; /* DMIC2 2 chan on, GPIO1 off */
		if (is_active_pin(codec, CS_DMIC1_PIN_NID))
			coef |= 1 << 3; /* DMIC1 2 chan on, GPIO0 off
					 * No effect if SPDIF_OUT2 is
					 * selected in IDX_SPDIF_CTL.
					*/

		cs_vendor_coef_set(codec, IDX_BEEP_CFG, coef);
	}
}

__attribute__((used)) static void init_digital_coef(struct hda_codec *codec)
{
	unsigned int coef;

	coef = 0x0002; /* SRC_MUTE soft-mute on SPDIF (if no lock) */
	coef |= 0x0008; /* Replace with mute on error */
	if (is_active_pin(codec, CS_DIG_OUT2_PIN_NID))
		coef |= 0x4000; /* RX to TX1 or TX2 Loopthru / SPDIF2
				 * SPDIF_OUT2 is shared with GPIO1 and
				 * DMIC_SDA2.
				 */
	cs_vendor_coef_set(codec, IDX_SPDIF_CTL, coef);
}

__attribute__((used)) static int cs_init(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;

	if (spec->vendor_nid == CS420X_VENDOR_NID) {
		/* init_verb sequence for C0/C1/C2 errata*/
		snd_hda_sequence_write(codec, cs_errata_init_verbs);
		snd_hda_sequence_write(codec, cs_coef_init_verbs);
	} else if (spec->vendor_nid == CS4208_VENDOR_NID) {
		snd_hda_sequence_write(codec, cs4208_coef_init_verbs);
	}

	snd_hda_gen_init(codec);

	if (spec->gpio_mask) {
		snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_MASK,
				    spec->gpio_mask);
		snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DIRECTION,
				    spec->gpio_dir);
		snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
				    spec->gpio_data);
	}

	if (spec->vendor_nid == CS420X_VENDOR_NID) {
		init_input_coef(codec);
		init_digital_coef(codec);
	}

	return 0;
}

__attribute__((used)) static int cs_build_controls(struct hda_codec *codec)
{
	int err;

	err = snd_hda_gen_build_controls(codec);
	if (err < 0)
		return err;
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_BUILD);
	return 0;
}

__attribute__((used)) static int cs_parse_auto_config(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;
	int err;
	int i;

	err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL, 0);
	if (err < 0)
		return err;

	err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
	if (err < 0)
		return err;

	/* keep the ADCs powered up when it's dynamically switchable */
	if (spec->gen.dyn_adc_switch) {
		unsigned int done = 0;
		for (i = 0; i < spec->gen.input_mux.num_items; i++) {
			int idx = spec->gen.dyn_adc_idx[i];
			if (done & (1 << idx))
				continue;
			snd_hda_gen_fix_pin_power(codec,
						  spec->gen.adc_nids[idx]);
			done |= 1 << idx;
		}
	}

	return 0;
}

__attribute__((used)) static void cs420x_fixup_gpio_13(struct hda_codec *codec,
				 const struct hda_fixup *fix, int action)
{
	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		struct cs_spec *spec = codec->spec;
		spec->gpio_eapd_hp = 2; /* GPIO1 = headphones */
		spec->gpio_eapd_speaker = 8; /* GPIO3 = speakers */
		spec->gpio_mask = spec->gpio_dir =
			spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
	}
}

__attribute__((used)) static void cs420x_fixup_gpio_23(struct hda_codec *codec,
				 const struct hda_fixup *fix, int action)
{
	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		struct cs_spec *spec = codec->spec;
		spec->gpio_eapd_hp = 4; /* GPIO2 = headphones */
		spec->gpio_eapd_speaker = 8; /* GPIO3 = speakers */
		spec->gpio_mask = spec->gpio_dir =
			spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
	}
}

__attribute__((used)) static struct cs_spec *cs_alloc_spec(struct hda_codec *codec, int vendor_nid)
{
	struct cs_spec *spec;

	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (!spec)
		return NULL;
	codec->spec = spec;
	spec->vendor_nid = vendor_nid;
	codec->power_save_node = 1;
	snd_hda_gen_spec_init(&spec->gen);

	return spec;
}

__attribute__((used)) static int patch_cs420x(struct hda_codec *codec)
{
	struct cs_spec *spec;
	int err;

	spec = cs_alloc_spec(codec, CS420X_VENDOR_NID);
	if (!spec)
		return -ENOMEM;

	codec->patch_ops = cs_patch_ops;
	spec->gen.automute_hook = cs_automute;
	codec->single_adc_amp = 1;

	snd_hda_pick_fixup(codec, cs420x_models, cs420x_fixup_tbl,
			   cs420x_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	err = cs_parse_auto_config(codec);
	if (err < 0)
		goto error;

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	cs_free(codec);
	return err;
}

__attribute__((used)) static void cs4208_fixup_gpio0(struct hda_codec *codec,
			       const struct hda_fixup *fix, int action)
{
	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		struct cs_spec *spec = codec->spec;
		spec->gpio_eapd_hp = 0;
		spec->gpio_eapd_speaker = 1;
		spec->gpio_mask = spec->gpio_dir =
			spec->gpio_eapd_hp | spec->gpio_eapd_speaker;
	}
}

__attribute__((used)) static void cs4208_fixup_mac(struct hda_codec *codec,
			     const struct hda_fixup *fix, int action)
{
	if (action != HDA_FIXUP_ACT_PRE_PROBE)
		return;

	codec->fixup_id = HDA_FIXUP_ID_NOT_SET;
	snd_hda_pick_fixup(codec, NULL, cs4208_mac_fixup_tbl, cs4208_fixups);
	if (codec->fixup_id == HDA_FIXUP_ID_NOT_SET)
		codec->fixup_id = CS4208_GPIO0; /* default fixup */
	snd_hda_apply_fixup(codec, action);
}

__attribute__((used)) static void cs4208_fixup_macmini(struct hda_codec *codec,
				 const struct hda_fixup *fix, int action)
{
	static const struct hda_pintbl pincfgs[] = {
		{ 0x18, 0x00ab9150 }, /* mic (audio-in) jack: disable detect */
		{ 0x21, 0x004be140 }, /* SPDIF: disable detect */
		{ }
	};

	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		/* HP pin (0x10) has an inverted detection */
		codec->inv_jack_detect = 1;
		/* disable the bogus Mic and SPDIF jack detections */
		snd_hda_apply_pincfgs(codec, pincfgs);
	}
}

__attribute__((used)) static int cs4208_spdif_sw_put(struct snd_kcontrol *kcontrol,
			       struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct cs_spec *spec = codec->spec;
	hda_nid_t pin = spec->gen.autocfg.dig_out_pins[0];
	int pinctl = ucontrol->value.integer.value[0] ? PIN_OUT : 0;

	snd_hda_set_pin_ctl_cache(codec, pin, pinctl);
	return spec->spdif_sw_put(kcontrol, ucontrol);
}

__attribute__((used)) static void cs4208_fixup_spdif_switch(struct hda_codec *codec,
				      const struct hda_fixup *fix, int action)
{
	if (action == HDA_FIXUP_ACT_BUILD) {
		struct cs_spec *spec = codec->spec;
		struct snd_kcontrol *kctl;

		if (!spec->gen.autocfg.dig_out_pins[0])
			return;
		kctl = snd_hda_find_mixer_ctl(codec, "IEC958 Playback Switch");
		if (!kctl)
			return;
		spec->spdif_sw_put = kctl->put;
		kctl->put = cs4208_spdif_sw_put;
	}
}

__attribute__((used)) static void cs4208_fix_amp_caps(struct hda_codec *codec, hda_nid_t adc)
{
	unsigned int caps;

	caps = query_amp_caps(codec, adc, HDA_INPUT);
	caps &= ~(AC_AMPCAP_OFFSET);
	caps |= 0x02;
	snd_hda_override_amp_caps(codec, adc, HDA_INPUT, caps);
}

__attribute__((used)) static int patch_cs4208(struct hda_codec *codec)
{
	struct cs_spec *spec;
	int err;

	spec = cs_alloc_spec(codec, CS4208_VENDOR_NID);
	if (!spec)
		return -ENOMEM;

	codec->patch_ops = cs_patch_ops;
	spec->gen.automute_hook = cs_automute;
	/* exclude NID 0x10 (HP) from output volumes due to different steps */
	spec->gen.out_vol_mask = 1ULL << 0x10;

	snd_hda_pick_fixup(codec, cs4208_models, cs4208_fixup_tbl,
			   cs4208_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	snd_hda_override_wcaps(codec, 0x18,
			       get_wcaps(codec, 0x18) | AC_WCAP_STEREO);
	cs4208_fix_amp_caps(codec, 0x18);
	cs4208_fix_amp_caps(codec, 0x1b);
	cs4208_fix_amp_caps(codec, 0x1c);

	err = cs_parse_auto_config(codec);
	if (err < 0)
		goto error;

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	cs_free(codec);
	return err;
}

__attribute__((used)) static void cs421x_fixup_sense_b(struct hda_codec *codec,
				 const struct hda_fixup *fix, int action)
{
	struct cs_spec *spec = codec->spec;
	if (action == HDA_FIXUP_ACT_PRE_PROBE)
		spec->sense_b = 1;
}

__attribute__((used)) static int cs421x_boost_vol_info(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 1;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 3;
	return 0;
}

__attribute__((used)) static int cs421x_boost_vol_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);

	ucontrol->value.integer.value[0] =
		cs_vendor_coef_get(codec, CS421X_IDX_SPK_CTL) & 0x0003;
	return 0;
}

__attribute__((used)) static int cs421x_boost_vol_put(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);

	unsigned int vol = ucontrol->value.integer.value[0];
	unsigned int coef =
		cs_vendor_coef_get(codec, CS421X_IDX_SPK_CTL);
	unsigned int original_coef = coef;

	coef &= ~0x0003;
	coef |= (vol & 0x0003);
	if (original_coef == coef)
		return 0;
	else {
		cs_vendor_coef_set(codec, CS421X_IDX_SPK_CTL, coef);
		return 1;
	}
}

__attribute__((used)) static void cs4210_pinmux_init(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;
	unsigned int def_conf, coef;

	/* GPIO, DMIC_SCL, DMIC_SDA and SENSE_B are multiplexed */
	coef = cs_vendor_coef_get(codec, CS421X_IDX_DEV_CFG);

	if (spec->gpio_mask)
		coef |= 0x0008; /* B1,B2 are GPIOs */
	else
		coef &= ~0x0008;

	if (spec->sense_b)
		coef |= 0x0010; /* B2 is SENSE_B, not inverted  */
	else
		coef &= ~0x0010;

	cs_vendor_coef_set(codec, CS421X_IDX_DEV_CFG, coef);

	if ((spec->gpio_mask || spec->sense_b) &&
	    is_active_pin(codec, CS421X_DMIC_PIN_NID)) {

		/*
		    GPIO or SENSE_B forced - disconnect the DMIC pin.
		*/
		def_conf = snd_hda_codec_get_pincfg(codec, CS421X_DMIC_PIN_NID);
		def_conf &= ~AC_DEFCFG_PORT_CONN;
		def_conf |= (AC_JACK_PORT_NONE << AC_DEFCFG_PORT_CONN_SHIFT);
		snd_hda_codec_set_pincfg(codec, CS421X_DMIC_PIN_NID, def_conf);
	}
}

__attribute__((used)) static void cs4210_spdif_automute(struct hda_codec *codec,
				  struct hda_jack_callback *tbl)
{
	struct cs_spec *spec = codec->spec;
	bool spdif_present = false;
	hda_nid_t spdif_pin = spec->gen.autocfg.dig_out_pins[0];

	/* detect on spdif is specific to CS4210 */
	if (!spec->spdif_detect ||
	    spec->vendor_nid != CS4210_VENDOR_NID)
		return;

	spdif_present = snd_hda_jack_detect(codec, spdif_pin);
	if (spdif_present == spec->spdif_present)
		return;

	spec->spdif_present = spdif_present;
	/* SPDIF TX on/off */
	snd_hda_set_pin_ctl(codec, spdif_pin, spdif_present ? PIN_OUT : 0);

	cs_automute(codec);
}

__attribute__((used)) static void parse_cs421x_digital(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;
	struct auto_pin_cfg *cfg = &spec->gen.autocfg;
	int i;

	for (i = 0; i < cfg->dig_outs; i++) {
		hda_nid_t nid = cfg->dig_out_pins[i];
		if (get_wcaps(codec, nid) & AC_WCAP_UNSOL_CAP) {
			spec->spdif_detect = 1;
			snd_hda_jack_detect_enable_callback(codec, nid,
							    cs4210_spdif_automute);
		}
	}
}

__attribute__((used)) static int cs421x_init(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;

	if (spec->vendor_nid == CS4210_VENDOR_NID) {
		snd_hda_sequence_write(codec, cs421x_coef_init_verbs);
		snd_hda_sequence_write(codec, cs421x_coef_init_verbs_A1_silicon_fixes);
		cs4210_pinmux_init(codec);
	}

	snd_hda_gen_init(codec);

	if (spec->gpio_mask) {
		snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_MASK,
				    spec->gpio_mask);
		snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DIRECTION,
				    spec->gpio_dir);
		snd_hda_codec_write(codec, 0x01, 0, AC_VERB_SET_GPIO_DATA,
				    spec->gpio_data);
	}

	init_input_coef(codec);

	cs4210_spdif_automute(codec, NULL);

	return 0;
}

__attribute__((used)) static void fix_volume_caps(struct hda_codec *codec, hda_nid_t dac)
{
	unsigned int caps;

	/* set the upper-limit for mixer amp to 0dB */
	caps = query_amp_caps(codec, dac, HDA_OUTPUT);
	caps &= ~(0x7f << AC_AMPCAP_NUM_STEPS_SHIFT);
	caps |= ((caps >> AC_AMPCAP_OFFSET_SHIFT) & 0x7f)
		<< AC_AMPCAP_NUM_STEPS_SHIFT;
	snd_hda_override_amp_caps(codec, dac, HDA_OUTPUT, caps);
}

__attribute__((used)) static int cs421x_parse_auto_config(struct hda_codec *codec)
{
	struct cs_spec *spec = codec->spec;
	hda_nid_t dac = CS4210_DAC_NID;
	int err;

	fix_volume_caps(codec, dac);

	err = snd_hda_parse_pin_defcfg(codec, &spec->gen.autocfg, NULL, 0);
	if (err < 0)
		return err;

	err = snd_hda_gen_parse_auto_config(codec, &spec->gen.autocfg);
	if (err < 0)
		return err;

	parse_cs421x_digital(codec);

	if (spec->gen.autocfg.speaker_outs &&
	    spec->vendor_nid == CS4210_VENDOR_NID) {
		if (!snd_hda_gen_add_kctl(&spec->gen, NULL,
					  &cs421x_speaker_boost_ctl))
			return -ENOMEM;
	}

	return 0;
}

__attribute__((used)) static int patch_cs4210(struct hda_codec *codec)
{
	struct cs_spec *spec;
	int err;

	spec = cs_alloc_spec(codec, CS4210_VENDOR_NID);
	if (!spec)
		return -ENOMEM;

	codec->patch_ops = cs421x_patch_ops;
	spec->gen.automute_hook = cs_automute;

	snd_hda_pick_fixup(codec, cs421x_models, cs421x_fixup_tbl,
			   cs421x_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	/*
	    Update the GPIO/DMIC/SENSE_B pinmux before the configuration
	    is auto-parsed. If GPIO or SENSE_B is forced, DMIC input
	    is disabled.
	*/
	cs4210_pinmux_init(codec);

	err = cs421x_parse_auto_config(codec);
	if (err < 0)
		goto error;

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	cs_free(codec);
	return err;
}

__attribute__((used)) static int patch_cs4213(struct hda_codec *codec)
{
	struct cs_spec *spec;
	int err;

	spec = cs_alloc_spec(codec, CS4213_VENDOR_NID);
	if (!spec)
		return -ENOMEM;

	codec->patch_ops = cs421x_patch_ops;

	err = cs421x_parse_auto_config(codec);
	if (err < 0)
		goto error;

	return 0;

 error:
	cs_free(codec);
	return err;
}

