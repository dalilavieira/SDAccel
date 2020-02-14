#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_13__ ;
typedef  struct TYPE_14__   TYPE_11__ ;

/* Type definitions */
typedef  int u32 ;
struct snd_kcontrol {int dummy; } ;
struct snd_dma_buffer {int dummy; } ;
struct TYPE_17__ {unsigned int* item; } ;
struct TYPE_18__ {TYPE_2__ enumerated; } ;
struct snd_ctl_elem_value {TYPE_3__ value; } ;
struct snd_ctl_elem_info {int dummy; } ;
struct nid_path {int active; int depth; int /*<<< orphan*/  multi; int /*<<< orphan*/  idx; int /*<<< orphan*/  path; } ;
struct hda_pcm {int /*<<< orphan*/  kref; } ;
struct hda_fixup {int dummy; } ;
struct TYPE_15__ {int (* init ) (struct hda_codec*) ;} ;
struct TYPE_20__ {scalar_t__ start_nid; scalar_t__ num_nodes; int vendor_id; } ;
struct hda_codec {int* wcaps; int inv_eapd; int spdif_status_reset; int no_trigger_sense; int no_sticky_stream; int inv_jack_detect; struct ad198x_spec* spec; TYPE_13__ patch_ops; int /*<<< orphan*/  control_mutex; TYPE_5__ core; } ;
struct hda_bus {int /*<<< orphan*/  core; } ;
struct auto_pin_cfg {scalar_t__ line_out_type; int line_outs; int hp_outs; scalar_t__ const* line_out_pins; scalar_t__ const* hp_pins; int speaker_outs; scalar_t__ const* speaker_pins; int /*<<< orphan*/  dig_outs; } ;
struct TYPE_19__ {void (* hook ) (void*,int) ;} ;
struct TYPE_16__ {int no_share_stream; scalar_t__ dig_out_nid; } ;
struct TYPE_14__ {int indep_hp; int keep_eapd_on; int mixer_nid; int beep_nid; scalar_t__* preferred_dacs; int auto_mute_via_amp; int mixer_merge_nid; int own_eapd_ctl; TYPE_4__ vmaster_mute; struct auto_pin_cfg autocfg; int /*<<< orphan*/  paths; TYPE_1__ multiout; scalar_t__ add_stereo_mix_input; } ;
struct ad198x_spec {scalar_t__ eapd_nid; unsigned int cur_smux; TYPE_11__ gen; int /*<<< orphan*/  beep_amp; int /*<<< orphan*/ * smux_paths; } ;
typedef  scalar_t__ hda_nid_t ;

/* Variables and functions */
 int AC_AMPCAP_MUTE_SHIFT ; 
 int AC_AMPCAP_NUM_STEPS_SHIFT ; 
 int AC_AMPCAP_OFFSET_SHIFT ; 
 int AC_AMPCAP_STEP_SIZE_SHIFT ; 
 int /*<<< orphan*/  AC_PAR_PIN_CAP ; 
 int AC_PINCAP_EAPD ; 
 unsigned int AC_VERB_SET_CONNECT_SEL ; 
 unsigned int AC_VERB_SET_EAPD_BTLENABLE ; 
 unsigned int AC_VERB_SET_GPIO_DATA ; 
 unsigned int AC_VERB_SET_GPIO_DIRECTION ; 
 unsigned int AC_VERB_SET_GPIO_MASK ; 
 int AC_WCAP_CHAN_CNT_EXT ; 
 unsigned int AC_WCAP_TYPE ; 
 unsigned int AC_WCAP_TYPE_SHIFT ; 
 scalar_t__ AC_WID_AUD_MIX ; 
 int /*<<< orphan*/  ARRAY_SIZE (scalar_t__*) ; 
 scalar_t__ AUTO_PIN_HP_OUT ; 
 scalar_t__ AUTO_PIN_SPEAKER_OUT ; 
 int EINVAL ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  HDA_COMPOSE_AMP_VAL (int,int,int,int /*<<< orphan*/ ) ; 
#define  HDA_FIXUP_ACT_PRE_PROBE 129 
#define  HDA_FIXUP_ACT_PROBE 128 
 scalar_t__ HDA_HINT_STEREO_MIX_AUTO ; 
 scalar_t__ HDA_HINT_STEREO_MIX_ENABLE ; 
 int /*<<< orphan*/  HDA_INPUT ; 
 scalar_t__ HDA_JACK_NOT_PRESENT ; 
 int /*<<< orphan*/  HDA_OUTPUT ; 
 int _snd_hda_set_pin_ctl (struct hda_codec*,scalar_t__,unsigned int,int) ; 
 int /*<<< orphan*/ * ad1884_fixup_tbl ; 
 int /*<<< orphan*/  ad1884_fixups ; 
 int /*<<< orphan*/ * ad1981_fixup_tbl ; 
 int /*<<< orphan*/  ad1981_fixups ; 
 int /*<<< orphan*/  ad1983_auto_smux_mixer ; 
 int /*<<< orphan*/ * ad1986a_fixup_models ; 
 int /*<<< orphan*/ * ad1986a_fixup_tbl ; 
 int /*<<< orphan*/  ad1986a_fixups ; 
 int /*<<< orphan*/  ad1988_auto_smux_mixer ; 
 int /*<<< orphan*/ * ad1988_fixup_models ; 
 int /*<<< orphan*/  ad1988_fixups ; 
 TYPE_13__ ad198x_auto_patch_ops ; 
 int create_beep_ctls (struct hda_codec*) ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 struct ad198x_spec* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  set_beep_amp (struct ad198x_spec*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 struct nid_path* snd_array_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_hda_activate_path (struct hda_codec*,struct nid_path*,int,int) ; 
 int /*<<< orphan*/  snd_hda_apply_fixup (struct hda_codec*,int) ; 
 int snd_hda_enum_helper_info (struct snd_kcontrol*,struct snd_ctl_elem_info*,int,char const* const*) ; 
 int /*<<< orphan*/  snd_hda_gen_add_kctl (TYPE_11__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int snd_hda_gen_build_controls (struct hda_codec*) ; 
 int /*<<< orphan*/  snd_hda_gen_free (struct hda_codec*) ; 
 int snd_hda_gen_init (struct hda_codec*) ; 
 int snd_hda_gen_parse_auto_config (struct hda_codec*,struct auto_pin_cfg*) ; 
 int /*<<< orphan*/  snd_hda_gen_spec_init (TYPE_11__*) ; 
 int snd_hda_get_connections (struct hda_codec*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct nid_path* snd_hda_get_path_from_idx (struct hda_codec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_get_path_idx (struct hda_codec*,struct nid_path*) ; 
 scalar_t__ snd_hda_jack_detect_state (struct hda_codec*,scalar_t__) ; 
 int /*<<< orphan*/  snd_hda_override_amp_caps (struct hda_codec*,int,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_hda_override_conn_list (struct hda_codec*,int,int /*<<< orphan*/ ,scalar_t__*) ; 
 int snd_hda_param_read (struct hda_codec*,scalar_t__,int /*<<< orphan*/ ) ; 
 int snd_hda_parse_pin_defcfg (struct hda_codec*,struct auto_pin_cfg*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_pick_fixup (struct hda_codec*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_shutup_pins (struct hda_codec*) ; 
 int /*<<< orphan*/  snd_hdac_bus_queue_event (int /*<<< orphan*/ *,int,int) ; 
 int snd_hdac_check_power_state (TYPE_5__*,scalar_t__,unsigned int) ; 
 unsigned int snd_hdac_codec_read (TYPE_5__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_codec_write (TYPE_5__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_override_parm (TYPE_5__*,scalar_t__,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_hdac_regmap_write (TYPE_5__*,scalar_t__,unsigned int,unsigned int) ; 
 unsigned int snd_hdac_sync_power_state (TYPE_5__*,scalar_t__,unsigned int) ; 
 struct hda_codec* snd_kcontrol_chip (struct snd_kcontrol*) ; 

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

__attribute__((used)) static inline int snd_hda_attach_beep_device(struct hda_codec *codec, int nid)
{
	return 0;
}

__attribute__((used)) static inline void snd_hda_detach_beep_device(struct hda_codec *codec)
{
}

__attribute__((used)) static inline int snd_hda_register_beep_device(struct hda_codec *codec)
{
	return 0;
}

__attribute__((used)) static inline bool snd_hda_jack_detect(struct hda_codec *codec, hda_nid_t nid)
{
	return snd_hda_jack_detect_state(codec, nid) != HDA_JACK_NOT_PRESENT;
}

__attribute__((used)) static void ad198x_power_eapd_write(struct hda_codec *codec, hda_nid_t front,
				hda_nid_t hp)
{
	if (snd_hda_query_pin_caps(codec, front) & AC_PINCAP_EAPD)
		snd_hda_codec_write(codec, front, 0, AC_VERB_SET_EAPD_BTLENABLE,
			    !codec->inv_eapd ? 0x00 : 0x02);
	if (snd_hda_query_pin_caps(codec, hp) & AC_PINCAP_EAPD)
		snd_hda_codec_write(codec, hp, 0, AC_VERB_SET_EAPD_BTLENABLE,
			    !codec->inv_eapd ? 0x00 : 0x02);
}

__attribute__((used)) static void ad198x_power_eapd(struct hda_codec *codec)
{
	/* We currently only handle front, HP */
	switch (codec->core.vendor_id) {
	case 0x11d41882:
	case 0x11d4882a:
	case 0x11d41884:
	case 0x11d41984:
	case 0x11d41883:
	case 0x11d4184a:
	case 0x11d4194a:
	case 0x11d4194b:
	case 0x11d41988:
	case 0x11d4198b:
	case 0x11d4989a:
	case 0x11d4989b:
		ad198x_power_eapd_write(codec, 0x12, 0x11);
		break;
	case 0x11d41981:
	case 0x11d41983:
		ad198x_power_eapd_write(codec, 0x05, 0x06);
		break;
	case 0x11d41986:
		ad198x_power_eapd_write(codec, 0x1b, 0x1a);
		break;
	}
}

__attribute__((used)) static void ad198x_shutup(struct hda_codec *codec)
{
	snd_hda_shutup_pins(codec);
	ad198x_power_eapd(codec);
}

__attribute__((used)) static void ad_vmaster_eapd_hook(void *private_data, int enabled)
{
	struct hda_codec *codec = private_data;
	struct ad198x_spec *spec = codec->spec;

	if (!spec->eapd_nid)
		return;
	if (codec->inv_eapd)
		enabled = !enabled;
	snd_hda_codec_write_cache(codec, spec->eapd_nid, 0,
				   AC_VERB_SET_EAPD_BTLENABLE,
				   enabled ? 0x02 : 0x00);
}

__attribute__((used)) static int ad198x_auto_build_controls(struct hda_codec *codec)
{
	int err;

	err = snd_hda_gen_build_controls(codec);
	if (err < 0)
		return err;
	err = create_beep_ctls(codec);
	if (err < 0)
		return err;
	return 0;
}

__attribute__((used)) static int ad198x_parse_auto_config(struct hda_codec *codec, bool indep_hp)
{
	struct ad198x_spec *spec = codec->spec;
	struct auto_pin_cfg *cfg = &spec->gen.autocfg;
	int err;

	codec->spdif_status_reset = 1;
	codec->no_trigger_sense = 1;
	codec->no_sticky_stream = 1;

	spec->gen.indep_hp = indep_hp;
	if (!spec->gen.add_stereo_mix_input)
		spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_AUTO;

	err = snd_hda_parse_pin_defcfg(codec, cfg, NULL, 0);
	if (err < 0)
		return err;
	err = snd_hda_gen_parse_auto_config(codec, cfg);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int alloc_ad_spec(struct hda_codec *codec)
{
	struct ad198x_spec *spec;

	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (!spec)
		return -ENOMEM;
	codec->spec = spec;
	snd_hda_gen_spec_init(&spec->gen);
	codec->patch_ops = ad198x_auto_patch_ops;
	return 0;
}

__attribute__((used)) static void ad_fixup_inv_jack_detect(struct hda_codec *codec,
				     const struct hda_fixup *fix, int action)
{
	struct ad198x_spec *spec = codec->spec;

	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		codec->inv_jack_detect = 1;
		spec->gen.keep_eapd_on = 1;
		spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
		spec->eapd_nid = 0x1b;
	}
}

__attribute__((used)) static void ad1986a_fixup_eapd(struct hda_codec *codec,
			       const struct hda_fixup *fix, int action)
{
	struct ad198x_spec *spec = codec->spec;

	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		codec->inv_eapd = 0;
		spec->gen.keep_eapd_on = 1;
		spec->eapd_nid = 0x1b;
	}
}

__attribute__((used)) static void ad1986a_fixup_eapd_mix_in(struct hda_codec *codec,
				      const struct hda_fixup *fix, int action)
{
	struct ad198x_spec *spec = codec->spec;

	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		ad1986a_fixup_eapd(codec, fix, action);
		spec->gen.add_stereo_mix_input = HDA_HINT_STEREO_MIX_ENABLE;
	}
}

__attribute__((used)) static int patch_ad1986a(struct hda_codec *codec)
{
	int err;
	struct ad198x_spec *spec;
	static hda_nid_t preferred_pairs[] = {
		0x1a, 0x03,
		0x1b, 0x03,
		0x1c, 0x04,
		0x1d, 0x05,
		0x1e, 0x03,
		0
	};

	err = alloc_ad_spec(codec);
	if (err < 0)
		return err;
	spec = codec->spec;

	/* AD1986A has the inverted EAPD implementation */
	codec->inv_eapd = 1;

	spec->gen.mixer_nid = 0x07;
	spec->gen.beep_nid = 0x19;
	set_beep_amp(spec, 0x18, 0, HDA_OUTPUT);

	/* AD1986A has a hardware problem that it can't share a stream
	 * with multiple output pins.  The copy of front to surrounds
	 * causes noisy or silent outputs at a certain timing, e.g.
	 * changing the volume.
	 * So, let's disable the shared stream.
	 */
	spec->gen.multiout.no_share_stream = 1;
	/* give fixed DAC/pin pairs */
	spec->gen.preferred_dacs = preferred_pairs;

	/* AD1986A can't manage the dynamic pin on/off smoothly */
	spec->gen.auto_mute_via_amp = 1;

	snd_hda_pick_fixup(codec, ad1986a_fixup_models, ad1986a_fixup_tbl,
			   ad1986a_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	err = ad198x_parse_auto_config(codec, false);
	if (err < 0) {
		snd_hda_gen_free(codec);
		return err;
	}

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;
}

__attribute__((used)) static int ad1983_auto_smux_enum_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_elem_info *uinfo)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct ad198x_spec *spec = codec->spec;
	static const char * const texts2[] = { "PCM", "ADC" };
	static const char * const texts3[] = { "PCM", "ADC1", "ADC2" };
	hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
	int num_conns = snd_hda_get_num_conns(codec, dig_out);

	if (num_conns == 2)
		return snd_hda_enum_helper_info(kcontrol, uinfo, 2, texts2);
	else if (num_conns == 3)
		return snd_hda_enum_helper_info(kcontrol, uinfo, 3, texts3);
	else
		return -EINVAL;
}

__attribute__((used)) static int ad1983_auto_smux_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct ad198x_spec *spec = codec->spec;

	ucontrol->value.enumerated.item[0] = spec->cur_smux;
	return 0;
}

__attribute__((used)) static int ad1983_auto_smux_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct ad198x_spec *spec = codec->spec;
	unsigned int val = ucontrol->value.enumerated.item[0];
	hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
	int num_conns = snd_hda_get_num_conns(codec, dig_out);

	if (val >= num_conns)
		return -EINVAL;
	if (spec->cur_smux == val)
		return 0;
	spec->cur_smux = val;
	snd_hda_codec_write_cache(codec, dig_out, 0,
				  AC_VERB_SET_CONNECT_SEL, val);
	return 1;
}

__attribute__((used)) static int ad1983_add_spdif_mux_ctl(struct hda_codec *codec)
{
	struct ad198x_spec *spec = codec->spec;
	hda_nid_t dig_out = spec->gen.multiout.dig_out_nid;
	int num_conns;

	if (!dig_out)
		return 0;
	num_conns = snd_hda_get_num_conns(codec, dig_out);
	if (num_conns != 2 && num_conns != 3)
		return 0;
	if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &ad1983_auto_smux_mixer))
		return -ENOMEM;
	return 0;
}

__attribute__((used)) static int patch_ad1983(struct hda_codec *codec)
{
	struct ad198x_spec *spec;
	static hda_nid_t conn_0c[] = { 0x08 };
	static hda_nid_t conn_0d[] = { 0x09 };
	int err;

	err = alloc_ad_spec(codec);
	if (err < 0)
		return err;
	spec = codec->spec;

	spec->gen.mixer_nid = 0x0e;
	spec->gen.beep_nid = 0x10;
	set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);

	/* limit the loopback routes not to confuse the parser */
	snd_hda_override_conn_list(codec, 0x0c, ARRAY_SIZE(conn_0c), conn_0c);
	snd_hda_override_conn_list(codec, 0x0d, ARRAY_SIZE(conn_0d), conn_0d);

	err = ad198x_parse_auto_config(codec, false);
	if (err < 0)
		goto error;
	err = ad1983_add_spdif_mux_ctl(codec);
	if (err < 0)
		goto error;
	return 0;

 error:
	snd_hda_gen_free(codec);
	return err;
}

__attribute__((used)) static void ad1981_fixup_hp_eapd(struct hda_codec *codec,
				 const struct hda_fixup *fix, int action)
{
	struct ad198x_spec *spec = codec->spec;

	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
		spec->eapd_nid = 0x05;
	}
}

__attribute__((used)) static void ad1981_fixup_amp_override(struct hda_codec *codec,
				      const struct hda_fixup *fix, int action)
{
	if (action == HDA_FIXUP_ACT_PRE_PROBE)
		snd_hda_override_amp_caps(codec, 0x11, HDA_INPUT,
					  (0x17 << AC_AMPCAP_OFFSET_SHIFT) |
					  (0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
					  (0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
					  (1 << AC_AMPCAP_MUTE_SHIFT));
}

__attribute__((used)) static int patch_ad1981(struct hda_codec *codec)
{
	struct ad198x_spec *spec;
	int err;

	err = alloc_ad_spec(codec);
	if (err < 0)
		return -ENOMEM;
	spec = codec->spec;

	spec->gen.mixer_nid = 0x0e;
	spec->gen.beep_nid = 0x10;
	set_beep_amp(spec, 0x0d, 0, HDA_OUTPUT);

	snd_hda_pick_fixup(codec, NULL, ad1981_fixup_tbl, ad1981_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	err = ad198x_parse_auto_config(codec, false);
	if (err < 0)
		goto error;
	err = ad1983_add_spdif_mux_ctl(codec);
	if (err < 0)
		goto error;

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	snd_hda_gen_free(codec);
	return err;
}

__attribute__((used)) static int ad1988_auto_smux_enum_info(struct snd_kcontrol *kcontrol,
				      struct snd_ctl_elem_info *uinfo)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	static const char * const texts[] = {
		"PCM", "ADC1", "ADC2", "ADC3",
	};
	int num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
	if (num_conns > 4)
		num_conns = 4;
	return snd_hda_enum_helper_info(kcontrol, uinfo, num_conns, texts);
}

__attribute__((used)) static int ad1988_auto_smux_enum_get(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct ad198x_spec *spec = codec->spec;

	ucontrol->value.enumerated.item[0] = spec->cur_smux;
	return 0;
}

__attribute__((used)) static int ad1988_auto_smux_enum_put(struct snd_kcontrol *kcontrol,
				     struct snd_ctl_elem_value *ucontrol)
{
	struct hda_codec *codec = snd_kcontrol_chip(kcontrol);
	struct ad198x_spec *spec = codec->spec;
	unsigned int val = ucontrol->value.enumerated.item[0];
	struct nid_path *path;
	int num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;

	if (val >= num_conns)
		return -EINVAL;
	if (spec->cur_smux == val)
		return 0;

	mutex_lock(&codec->control_mutex);
	path = snd_hda_get_path_from_idx(codec,
					 spec->smux_paths[spec->cur_smux]);
	if (path)
		snd_hda_activate_path(codec, path, false, true);
	path = snd_hda_get_path_from_idx(codec, spec->smux_paths[val]);
	if (path)
		snd_hda_activate_path(codec, path, true, true);
	spec->cur_smux = val;
	mutex_unlock(&codec->control_mutex);
	return 1;
}

__attribute__((used)) static int ad1988_auto_init(struct hda_codec *codec)
{
	struct ad198x_spec *spec = codec->spec;
	int i, err;

	err = snd_hda_gen_init(codec);
	if (err < 0)
		return err;
	if (!spec->gen.autocfg.dig_outs)
		return 0;

	for (i = 0; i < 4; i++) {
		struct nid_path *path;
		path = snd_hda_get_path_from_idx(codec, spec->smux_paths[i]);
		if (path)
			snd_hda_activate_path(codec, path, path->active, false);
	}

	return 0;
}

__attribute__((used)) static int ad1988_add_spdif_mux_ctl(struct hda_codec *codec)
{
	struct ad198x_spec *spec = codec->spec;
	int i, num_conns;
	/* we create four static faked paths, since AD codecs have odd
	 * widget connections regarding the SPDIF out source
	 */
	static struct nid_path fake_paths[4] = {
		{
			.depth = 3,
			.path = { 0x02, 0x1d, 0x1b },
			.idx = { 0, 0, 0 },
			.multi = { 0, 0, 0 },
		},
		{
			.depth = 4,
			.path = { 0x08, 0x0b, 0x1d, 0x1b },
			.idx = { 0, 0, 1, 0 },
			.multi = { 0, 1, 0, 0 },
		},
		{
			.depth = 4,
			.path = { 0x09, 0x0b, 0x1d, 0x1b },
			.idx = { 0, 1, 1, 0 },
			.multi = { 0, 1, 0, 0 },
		},
		{
			.depth = 4,
			.path = { 0x0f, 0x0b, 0x1d, 0x1b },
			.idx = { 0, 2, 1, 0 },
			.multi = { 0, 1, 0, 0 },
		},
	};

	/* SPDIF source mux appears to be present only on AD1988A */
	if (!spec->gen.autocfg.dig_outs ||
	    get_wcaps_type(get_wcaps(codec, 0x1d)) != AC_WID_AUD_MIX)
		return 0;

	num_conns = snd_hda_get_num_conns(codec, 0x0b) + 1;
	if (num_conns != 3 && num_conns != 4)
		return 0;

	for (i = 0; i < num_conns; i++) {
		struct nid_path *path = snd_array_new(&spec->gen.paths);
		if (!path)
			return -ENOMEM;
		*path = fake_paths[i];
		if (!i)
			path->active = 1;
		spec->smux_paths[i] = snd_hda_get_path_idx(codec, path);
	}

	if (!snd_hda_gen_add_kctl(&spec->gen, NULL, &ad1988_auto_smux_mixer))
		return -ENOMEM;

	codec->patch_ops.init = ad1988_auto_init;

	return 0;
}

__attribute__((used)) static int patch_ad1988(struct hda_codec *codec)
{
	struct ad198x_spec *spec;
	int err;

	err = alloc_ad_spec(codec);
	if (err < 0)
		return err;
	spec = codec->spec;

	spec->gen.mixer_nid = 0x20;
	spec->gen.mixer_merge_nid = 0x21;
	spec->gen.beep_nid = 0x10;
	set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);

	snd_hda_pick_fixup(codec, ad1988_fixup_models, NULL, ad1988_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	err = ad198x_parse_auto_config(codec, true);
	if (err < 0)
		goto error;
	err = ad1988_add_spdif_mux_ctl(codec);
	if (err < 0)
		goto error;

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	snd_hda_gen_free(codec);
	return err;
}

__attribute__((used)) static void ad1884_fixup_amp_override(struct hda_codec *codec,
				      const struct hda_fixup *fix, int action)
{
	if (action == HDA_FIXUP_ACT_PRE_PROBE)
		snd_hda_override_amp_caps(codec, 0x20, HDA_INPUT,
					  (0x17 << AC_AMPCAP_OFFSET_SHIFT) |
					  (0x17 << AC_AMPCAP_NUM_STEPS_SHIFT) |
					  (0x05 << AC_AMPCAP_STEP_SIZE_SHIFT) |
					  (1 << AC_AMPCAP_MUTE_SHIFT));
}

__attribute__((used)) static void ad1884_vmaster_hp_gpio_hook(void *private_data, int enabled)
{
	struct hda_codec *codec = private_data;
	struct ad198x_spec *spec = codec->spec;

	if (spec->eapd_nid)
		ad_vmaster_eapd_hook(private_data, enabled);
	snd_hda_codec_write_cache(codec, 0x01, 0,
				   AC_VERB_SET_GPIO_DATA,
				   enabled ? 0x00 : 0x02);
}

__attribute__((used)) static void ad1884_fixup_hp_eapd(struct hda_codec *codec,
				 const struct hda_fixup *fix, int action)
{
	struct ad198x_spec *spec = codec->spec;

	switch (action) {
	case HDA_FIXUP_ACT_PRE_PROBE:
		spec->gen.vmaster_mute.hook = ad1884_vmaster_hp_gpio_hook;
		spec->gen.own_eapd_ctl = 1;
		snd_hda_codec_write_cache(codec, 0x01, 0,
					  AC_VERB_SET_GPIO_MASK, 0x02);
		snd_hda_codec_write_cache(codec, 0x01, 0,
					  AC_VERB_SET_GPIO_DIRECTION, 0x02);
		snd_hda_codec_write_cache(codec, 0x01, 0,
					  AC_VERB_SET_GPIO_DATA, 0x02);
		break;
	case HDA_FIXUP_ACT_PROBE:
		if (spec->gen.autocfg.line_out_type == AUTO_PIN_SPEAKER_OUT)
			spec->eapd_nid = spec->gen.autocfg.line_out_pins[0];
		else
			spec->eapd_nid = spec->gen.autocfg.speaker_pins[0];
		break;
	}
}

__attribute__((used)) static void ad1884_fixup_thinkpad(struct hda_codec *codec,
				  const struct hda_fixup *fix, int action)
{
	struct ad198x_spec *spec = codec->spec;

	if (action == HDA_FIXUP_ACT_PRE_PROBE) {
		spec->gen.keep_eapd_on = 1;
		spec->gen.vmaster_mute.hook = ad_vmaster_eapd_hook;
		spec->eapd_nid = 0x12;
		/* Analog PC Beeper - allow firmware/ACPI beeps */
		spec->beep_amp = HDA_COMPOSE_AMP_VAL(0x20, 3, 3, HDA_INPUT);
		spec->gen.beep_nid = 0; /* no digital beep */
	}
}

__attribute__((used)) static int patch_ad1884(struct hda_codec *codec)
{
	struct ad198x_spec *spec;
	int err;

	err = alloc_ad_spec(codec);
	if (err < 0)
		return err;
	spec = codec->spec;

	spec->gen.mixer_nid = 0x20;
	spec->gen.mixer_merge_nid = 0x21;
	spec->gen.beep_nid = 0x10;
	set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);

	snd_hda_pick_fixup(codec, NULL, ad1884_fixup_tbl, ad1884_fixups);
	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PRE_PROBE);

	err = ad198x_parse_auto_config(codec, true);
	if (err < 0)
		goto error;
	err = ad1983_add_spdif_mux_ctl(codec);
	if (err < 0)
		goto error;

	snd_hda_apply_fixup(codec, HDA_FIXUP_ACT_PROBE);

	return 0;

 error:
	snd_hda_gen_free(codec);
	return err;
}

__attribute__((used)) static int patch_ad1882(struct hda_codec *codec)
{
	struct ad198x_spec *spec;
	int err;

	err = alloc_ad_spec(codec);
	if (err < 0)
		return err;
	spec = codec->spec;

	spec->gen.mixer_nid = 0x20;
	spec->gen.mixer_merge_nid = 0x21;
	spec->gen.beep_nid = 0x10;
	set_beep_amp(spec, 0x10, 0, HDA_OUTPUT);
	err = ad198x_parse_auto_config(codec, true);
	if (err < 0)
		goto error;
	err = ad1988_add_spdif_mux_ctl(codec);
	if (err < 0)
		goto error;
	return 0;

 error:
	snd_hda_gen_free(codec);
	return err;
}

