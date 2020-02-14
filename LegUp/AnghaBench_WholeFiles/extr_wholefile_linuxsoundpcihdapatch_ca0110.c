#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct snd_dma_buffer {int dummy; } ;
struct hda_pcm {int /*<<< orphan*/  kref; } ;
struct hda_gen_spec {int multi_cap_vol; int /*<<< orphan*/  autocfg; } ;
struct TYPE_9__ {scalar_t__ start_nid; scalar_t__ num_nodes; } ;
struct hda_codec {int* wcaps; TYPE_1__* bus; int /*<<< orphan*/  patch_ops; struct hda_gen_spec* spec; TYPE_2__ core; } ;
struct hda_bus {int /*<<< orphan*/  core; } ;
struct auto_pin_cfg {scalar_t__ line_out_type; int line_outs; int hp_outs; scalar_t__ const* line_out_pins; scalar_t__ const* hp_pins; int speaker_outs; scalar_t__ const* speaker_pins; } ;
typedef  scalar_t__ hda_nid_t ;
struct TYPE_8__ {int needs_damn_long_delay; } ;

/* Variables and functions */
 int /*<<< orphan*/  AC_PAR_PIN_CAP ; 
 int AC_WCAP_CHAN_CNT_EXT ; 
 unsigned int AC_WCAP_TYPE ; 
 unsigned int AC_WCAP_TYPE_SHIFT ; 
 scalar_t__ AUTO_PIN_HP_OUT ; 
 scalar_t__ AUTO_PIN_SPEAKER_OUT ; 
 int ENOENT ; 
 int ENOMEM ; 
 int ENOSYS ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 scalar_t__ HDA_JACK_NOT_PRESENT ; 
 int _snd_hda_set_pin_ctl (struct hda_codec*,scalar_t__,unsigned int,int) ; 
 int /*<<< orphan*/  ca0110_patch_ops ; 
 int /*<<< orphan*/  kref_get (int /*<<< orphan*/ *) ; 
 struct hda_gen_spec* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hda_gen_free (struct hda_codec*) ; 
 int snd_hda_gen_parse_auto_config (struct hda_codec*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_hda_gen_spec_init (struct hda_gen_spec*) ; 
 int snd_hda_get_connections (struct hda_codec*,scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_hda_jack_detect_state (struct hda_codec*,scalar_t__) ; 
 int snd_hda_param_read (struct hda_codec*,scalar_t__,int /*<<< orphan*/ ) ; 
 int snd_hda_parse_pin_defcfg (struct hda_codec*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_hdac_bus_queue_event (int /*<<< orphan*/ *,int,int) ; 
 int snd_hdac_check_power_state (TYPE_2__*,scalar_t__,unsigned int) ; 
 unsigned int snd_hdac_codec_read (TYPE_2__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_codec_write (TYPE_2__*,scalar_t__,int,unsigned int,unsigned int) ; 
 int snd_hdac_override_parm (TYPE_2__*,scalar_t__,int /*<<< orphan*/ ,unsigned int) ; 
 int snd_hdac_regmap_write (TYPE_2__*,scalar_t__,unsigned int,unsigned int) ; 
 unsigned int snd_hdac_sync_power_state (TYPE_2__*,scalar_t__,unsigned int) ; 

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

__attribute__((used)) static int ca0110_parse_auto_config(struct hda_codec *codec)
{
	struct hda_gen_spec *spec = codec->spec;
	int err;

	err = snd_hda_parse_pin_defcfg(codec, &spec->autocfg, NULL, 0);
	if (err < 0)
		return err;
	err = snd_hda_gen_parse_auto_config(codec, &spec->autocfg);
	if (err < 0)
		return err;

	return 0;
}

__attribute__((used)) static int patch_ca0110(struct hda_codec *codec)
{
	struct hda_gen_spec *spec;
	int err;

	spec = kzalloc(sizeof(*spec), GFP_KERNEL);
	if (!spec)
		return -ENOMEM;
	snd_hda_gen_spec_init(spec);
	codec->spec = spec;
	codec->patch_ops = ca0110_patch_ops;

	spec->multi_cap_vol = 1;
	codec->bus->needs_damn_long_delay = 1;

	err = ca0110_parse_auto_config(codec);
	if (err < 0)
		goto error;

	return 0;

 error:
	snd_hda_gen_free(codec);
	return err;
}

