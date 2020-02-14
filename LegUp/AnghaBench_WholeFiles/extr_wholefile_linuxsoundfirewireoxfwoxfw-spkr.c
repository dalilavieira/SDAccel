#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
struct snd_pcm_substream {int dummy; } ;
struct snd_oxfw {int /*<<< orphan*/  card; struct fw_unit* unit; struct fw_spkr* spec; } ;
struct snd_kcontrol_new {char* name; int (* info ) (struct snd_kcontrol*,struct snd_ctl_elem_info*) ;int (* get ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int (* put ) (struct snd_kcontrol*,struct snd_ctl_elem_value*) ;int /*<<< orphan*/  const iface; } ;
struct snd_kcontrol {struct snd_oxfw* private_data; } ;
struct TYPE_7__ {int* value; } ;
struct TYPE_8__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_5__ {scalar_t__ min; scalar_t__ max; } ;
struct TYPE_6__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {unsigned int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct fw_unit {int /*<<< orphan*/  device; } ;
struct fw_spkr {int mute; int mute_fb_id; unsigned int mixer_channels; scalar_t__ volume_min; scalar_t__ volume_max; int* volume; int volume_fb_id; } ;
struct amdtp_stream {scalar_t__ packet_index; int callbacked; int /*<<< orphan*/  callback_wait; int /*<<< orphan*/  pcm; int /*<<< orphan*/  context; } ;
typedef  int s16 ;
typedef  enum control_attribute { ____Placeholder_control_attribute } control_attribute ;
typedef  enum control_action { ____Placeholder_control_action } control_action ;
typedef  enum cip_sfc { ____Placeholder_cip_sfc } cip_sfc ;
typedef  enum avc_general_plug_dir { ____Placeholder_avc_general_plug_dir } avc_general_plug_dir ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (struct snd_kcontrol_new const*) ; 
 int CTL_CURRENT ; 
 int CTL_MAX ; 
 int CTL_MIN ; 
 int CTL_READ ; 
 int CTL_WRITE ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  IS_ERR (int /*<<< orphan*/ ) ; 
 int RCODE_ADDRESS_ERROR ; 
 int RCODE_TYPE_ERROR ; 
#define  SNDRV_CTL_ELEM_IFACE_MIXER 129 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int /*<<< orphan*/  WRITE_ONCE (int /*<<< orphan*/ ,struct snd_pcm_substream*) ; 
 int avc_stream_get_format (struct fw_unit*,int,unsigned int,int*,unsigned int*,unsigned int) ; 
 size_t* channel_map ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ *,char*) ; 
 int fcp_avc_transaction (struct fw_unit*,int*,int,int*,int,int) ; 
 int /*<<< orphan*/  kfree (int*) ; 
 int* kmalloc (int,int /*<<< orphan*/ ) ; 
 struct fw_spkr* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  msecs_to_jiffies (unsigned int) ; 
 int snd_ctl_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
#define  snd_ctl_boolean_mono_info 128 
 int /*<<< orphan*/  snd_ctl_new1 (struct snd_kcontrol_new const*,struct snd_oxfw*) ; 
 scalar_t__ wait_event_timeout (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline bool rcode_is_permanent_error(int rcode)
{
	return rcode == RCODE_TYPE_ERROR || rcode == RCODE_ADDRESS_ERROR;
}

__attribute__((used)) static inline bool amdtp_stream_running(struct amdtp_stream *s)
{
	return !IS_ERR(s->context);
}

__attribute__((used)) static inline bool amdtp_streaming_error(struct amdtp_stream *s)
{
	return s->packet_index < 0;
}

__attribute__((used)) static inline bool amdtp_stream_pcm_running(struct amdtp_stream *s)
{
	return !!s->pcm;
}

__attribute__((used)) static inline void amdtp_stream_pcm_trigger(struct amdtp_stream *s,
					    struct snd_pcm_substream *pcm)
{
	WRITE_ONCE(s->pcm, pcm);
}

__attribute__((used)) static inline bool cip_sfc_is_base_44100(enum cip_sfc sfc)
{
	return sfc & 1;
}

__attribute__((used)) static inline bool amdtp_stream_wait_callback(struct amdtp_stream *s,
					      unsigned int timeout)
{
	return wait_event_timeout(s->callback_wait,
				  s->callbacked == true,
				  msecs_to_jiffies(timeout)) > 0;
}

__attribute__((used)) static inline int
avc_stream_get_format_single(struct fw_unit *unit,
			     enum avc_general_plug_dir dir, unsigned int pid,
			     u8 *buf, unsigned int *len)
{
	return avc_stream_get_format(unit, dir, pid, buf, len, 0xff);
}

__attribute__((used)) static inline int
avc_stream_get_format_list(struct fw_unit *unit,
			   enum avc_general_plug_dir dir, unsigned int pid,
			   u8 *buf, unsigned int *len,
			   unsigned int eid)
{
	return avc_stream_get_format(unit, dir, pid, buf, len, eid);
}

__attribute__((used)) static int avc_audio_feature_mute(struct fw_unit *unit, u8 fb_id, bool *value,
				  enum control_action action)
{
	u8 *buf;
	u8 response_ok;
	int err;

	buf = kmalloc(11, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	if (action == CTL_READ) {
		buf[0] = 0x01;		/* AV/C, STATUS */
		response_ok = 0x0c;	/*       STABLE */
	} else {
		buf[0] = 0x00;		/* AV/C, CONTROL */
		response_ok = 0x09;	/*       ACCEPTED */
	}
	buf[1] = 0x08;			/* audio unit 0 */
	buf[2] = 0xb8;			/* FUNCTION BLOCK */
	buf[3] = 0x81;			/* function block type: feature */
	buf[4] = fb_id;			/* function block ID */
	buf[5] = 0x10;			/* control attribute: current */
	buf[6] = 0x02;			/* selector length */
	buf[7] = 0x00;			/* audio channel number */
	buf[8] = 0x01;			/* control selector: mute */
	buf[9] = 0x01;			/* control data length */
	if (action == CTL_READ)
		buf[10] = 0xff;
	else
		buf[10] = *value ? 0x70 : 0x60;

	err = fcp_avc_transaction(unit, buf, 11, buf, 11, 0x3fe);
	if (err < 0)
		goto error;
	if (err < 11) {
		dev_err(&unit->device, "short FCP response\n");
		err = -EIO;
		goto error;
	}
	if (buf[0] != response_ok) {
		dev_err(&unit->device, "mute command failed\n");
		err = -EIO;
		goto error;
	}
	if (action == CTL_READ)
		*value = buf[10] == 0x70;

	err = 0;

error:
	kfree(buf);

	return err;
}

__attribute__((used)) static int avc_audio_feature_volume(struct fw_unit *unit, u8 fb_id, s16 *value,
				    unsigned int channel,
				    enum control_attribute attribute,
				    enum control_action action)
{
	u8 *buf;
	u8 response_ok;
	int err;

	buf = kmalloc(12, GFP_KERNEL);
	if (!buf)
		return -ENOMEM;

	if (action == CTL_READ) {
		buf[0] = 0x01;		/* AV/C, STATUS */
		response_ok = 0x0c;	/*       STABLE */
	} else {
		buf[0] = 0x00;		/* AV/C, CONTROL */
		response_ok = 0x09;	/*       ACCEPTED */
	}
	buf[1] = 0x08;			/* audio unit 0 */
	buf[2] = 0xb8;			/* FUNCTION BLOCK */
	buf[3] = 0x81;			/* function block type: feature */
	buf[4] = fb_id;			/* function block ID */
	buf[5] = attribute;		/* control attribute */
	buf[6] = 0x02;			/* selector length */
	buf[7] = channel;		/* audio channel number */
	buf[8] = 0x02;			/* control selector: volume */
	buf[9] = 0x02;			/* control data length */
	if (action == CTL_READ) {
		buf[10] = 0xff;
		buf[11] = 0xff;
	} else {
		buf[10] = *value >> 8;
		buf[11] = *value;
	}

	err = fcp_avc_transaction(unit, buf, 12, buf, 12, 0x3fe);
	if (err < 0)
		goto error;
	if (err < 12) {
		dev_err(&unit->device, "short FCP response\n");
		err = -EIO;
		goto error;
	}
	if (buf[0] != response_ok) {
		dev_err(&unit->device, "volume command failed\n");
		err = -EIO;
		goto error;
	}
	if (action == CTL_READ)
		*value = (buf[10] << 8) | buf[11];

	err = 0;

error:
	kfree(buf);

	return err;
}

__attribute__((used)) static int spkr_mute_get(struct snd_kcontrol *control,
			 struct snd_ctl_elem_value *value)
{
	struct snd_oxfw *oxfw = control->private_data;
	struct fw_spkr *spkr = oxfw->spec;

	value->value.integer.value[0] = !spkr->mute;

	return 0;
}

__attribute__((used)) static int spkr_mute_put(struct snd_kcontrol *control,
			 struct snd_ctl_elem_value *value)
{
	struct snd_oxfw *oxfw = control->private_data;
	struct fw_spkr *spkr = oxfw->spec;
	bool mute;
	int err;

	mute = !value->value.integer.value[0];

	if (mute == spkr->mute)
		return 0;

	err = avc_audio_feature_mute(oxfw->unit, spkr->mute_fb_id, &mute,
				     CTL_WRITE);
	if (err < 0)
		return err;
	spkr->mute = mute;

	return 1;
}

__attribute__((used)) static int spkr_volume_info(struct snd_kcontrol *control,
			    struct snd_ctl_elem_info *info)
{
	struct snd_oxfw *oxfw = control->private_data;
	struct fw_spkr *spkr = oxfw->spec;

	info->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	info->count = spkr->mixer_channels;
	info->value.integer.min = spkr->volume_min;
	info->value.integer.max = spkr->volume_max;

	return 0;
}

__attribute__((used)) static int spkr_volume_get(struct snd_kcontrol *control,
			   struct snd_ctl_elem_value *value)
{
	struct snd_oxfw *oxfw = control->private_data;
	struct fw_spkr *spkr = oxfw->spec;
	unsigned int i;

	for (i = 0; i < spkr->mixer_channels; ++i)
		value->value.integer.value[channel_map[i]] = spkr->volume[i];

	return 0;
}

__attribute__((used)) static int spkr_volume_put(struct snd_kcontrol *control,
			   struct snd_ctl_elem_value *value)
{
	struct snd_oxfw *oxfw = control->private_data;
	struct fw_spkr *spkr = oxfw->spec;
	unsigned int i, changed_channels;
	bool equal_values = true;
	s16 volume;
	int err;

	for (i = 0; i < spkr->mixer_channels; ++i) {
		if (value->value.integer.value[i] < spkr->volume_min ||
		    value->value.integer.value[i] > spkr->volume_max)
			return -EINVAL;
		if (value->value.integer.value[i] !=
		    value->value.integer.value[0])
			equal_values = false;
	}

	changed_channels = 0;
	for (i = 0; i < spkr->mixer_channels; ++i)
		if (value->value.integer.value[channel_map[i]] !=
							spkr->volume[i])
			changed_channels |= 1 << (i + 1);

	if (equal_values && changed_channels != 0)
		changed_channels = 1 << 0;

	for (i = 0; i <= spkr->mixer_channels; ++i) {
		volume = value->value.integer.value[channel_map[i ? i - 1 : 0]];
		if (changed_channels & (1 << i)) {
			err = avc_audio_feature_volume(oxfw->unit,
						  spkr->volume_fb_id, &volume,
						  i, CTL_CURRENT, CTL_WRITE);
			if (err < 0)
				return err;
		}
		if (i > 0)
			spkr->volume[i - 1] = volume;
	}

	return changed_channels != 0;
}

int snd_oxfw_add_spkr(struct snd_oxfw *oxfw, bool is_lacie)
{
	static const struct snd_kcontrol_new controls[] = {
		{
			.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
			.name = "PCM Playback Switch",
			.info = snd_ctl_boolean_mono_info,
			.get = spkr_mute_get,
			.put = spkr_mute_put,
		},
		{
			.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
			.name = "PCM Playback Volume",
			.info = spkr_volume_info,
			.get = spkr_volume_get,
			.put = spkr_volume_put,
		},
	};
	struct fw_spkr *spkr;
	unsigned int i, first_ch;
	int err;

	spkr = kzalloc(sizeof(struct fw_spkr), GFP_KERNEL);
	if (spkr == NULL)
		return -ENOMEM;
	oxfw->spec = spkr;

	if (is_lacie) {
		spkr->mixer_channels = 1;
		spkr->mute_fb_id = 0x01;
		spkr->volume_fb_id = 0x01;
	} else {
		spkr->mixer_channels = 6;
		spkr->mute_fb_id = 0x01;
		spkr->volume_fb_id = 0x02;
	}

	err = avc_audio_feature_volume(oxfw->unit, spkr->volume_fb_id,
				       &spkr->volume_min, 0, CTL_MIN, CTL_READ);
	if (err < 0)
		return err;
	err = avc_audio_feature_volume(oxfw->unit, spkr->volume_fb_id,
				       &spkr->volume_max, 0, CTL_MAX, CTL_READ);
	if (err < 0)
		return err;

	err = avc_audio_feature_mute(oxfw->unit, spkr->mute_fb_id, &spkr->mute,
				     CTL_READ);
	if (err < 0)
		return err;

	first_ch = spkr->mixer_channels == 1 ? 0 : 1;
	for (i = 0; i < spkr->mixer_channels; ++i) {
		err = avc_audio_feature_volume(oxfw->unit, spkr->volume_fb_id,
					       &spkr->volume[i], first_ch + i,
					       CTL_CURRENT, CTL_READ);
		if (err < 0)
			return err;
	}

	for (i = 0; i < ARRAY_SIZE(controls); ++i) {
		err = snd_ctl_add(oxfw->card,
				  snd_ctl_new1(&controls[i], oxfw));
		if (err < 0)
			return err;
	}

	return 0;
}

