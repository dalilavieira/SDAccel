#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct snd_info_entry {struct lola* private_data; } ;
struct snd_info_buffer {int dummy; } ;
struct lola {unsigned int debug_res; unsigned int debug_res_ex; TYPE_2__* bar; int /*<<< orphan*/  lola_caps; TYPE_3__* pin; TYPE_1__* pcm; } ;
typedef  int /*<<< orphan*/  line ;
struct TYPE_6__ {int num_pins; } ;
struct TYPE_5__ {scalar_t__ remap_addr; } ;
struct TYPE_4__ {int num_streams; } ;

/* Variables and functions */
 size_t BAR0 ; 
 size_t BAR1 ; 
 int /*<<< orphan*/  BDPL ; 
 int /*<<< orphan*/  BDPU ; 
 size_t CAPT ; 
 int /*<<< orphan*/  CTL ; 
 scalar_t__ LOLA_AFG_CLOCK_WIDGET_PRESENT (int /*<<< orphan*/ ) ; 
 scalar_t__ LOLA_AFG_MIXER_WIDGET_PRESENT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LOLA_AMP_MUTE_CAPABLE (unsigned int) ; 
 int /*<<< orphan*/  LOLA_AMP_NUM_STEPS (unsigned int) ; 
 int /*<<< orphan*/  LOLA_AMP_OFFSET (unsigned int) ; 
 int /*<<< orphan*/  LOLA_AMP_STEP_SIZE (unsigned int) ; 
 unsigned char LOLA_CLOCK_TYPE_INTERNAL ; 
 unsigned char LOLA_CLOCK_TYPE_VIDEO ; 
 unsigned int LOLA_PAR_AMP_IN_CAP ; 
 unsigned int LOLA_PAR_AMP_OUT_CAP ; 
 unsigned int LOLA_PAR_AUDIO_WIDGET_CAP ; 
 unsigned int LOLA_PAR_FUNCTION_TYPE ; 
 unsigned int LOLA_PAR_SPECIFIC_CAPS ; 
 unsigned int LOLA_PAR_STREAM_FORMATS ; 
 unsigned int LOLA_PAR_VENDOR_ID ; 
 unsigned int LOLA_VERB_GET_CLOCK_LIST ; 
 unsigned int LOLA_VERB_GET_MAX_LEVEL ; 
 int /*<<< orphan*/  LPIB ; 
 int /*<<< orphan*/  LVI ; 
 size_t PLAY ; 
 int /*<<< orphan*/  STS ; 
 int /*<<< orphan*/  lola_codec_read (struct lola*,unsigned int,unsigned int,unsigned int,unsigned int,unsigned int*,unsigned int*) ; 
 unsigned int lola_dsd_read (struct lola*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lola_read_param (struct lola*,int,unsigned int,unsigned int*) ; 
 unsigned int lola_sample_rate_convert (unsigned int) ; 
 unsigned int readl (scalar_t__) ; 
 int /*<<< orphan*/  snd_info_get_line (struct snd_info_buffer*,char*,int) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,...) ; 
 int sscanf (char*,char*,unsigned int*,unsigned int*,unsigned int*,unsigned int*) ; 

__attribute__((used)) static void print_audio_widget(struct snd_info_buffer *buffer,
			       struct lola *chip, int nid, const char *name)
{
	unsigned int val;

	lola_read_param(chip, nid, LOLA_PAR_AUDIO_WIDGET_CAP, &val);
	snd_iprintf(buffer, "Node 0x%02x %s wcaps 0x%x\n", nid, name, val);
	lola_read_param(chip, nid, LOLA_PAR_STREAM_FORMATS, &val);
	snd_iprintf(buffer, "  Formats: 0x%x\n", val);
}

__attribute__((used)) static void print_pin_widget(struct snd_info_buffer *buffer,
			     struct lola *chip, int nid, unsigned int ampcap,
			     const char *name)
{
	unsigned int val;

	lola_read_param(chip, nid, LOLA_PAR_AUDIO_WIDGET_CAP, &val);
	snd_iprintf(buffer, "Node 0x%02x %s wcaps 0x%x\n", nid, name, val);
	if (val == 0x00400200)
		return;
	lola_read_param(chip, nid, ampcap, &val);
	snd_iprintf(buffer, "  Amp-Caps: 0x%x\n", val);
	snd_iprintf(buffer, "    mute=%d, step-size=%d, steps=%d, ofs=%d\n",
		    LOLA_AMP_MUTE_CAPABLE(val),
		    LOLA_AMP_STEP_SIZE(val),
		    LOLA_AMP_NUM_STEPS(val),
		    LOLA_AMP_OFFSET(val));
	lola_codec_read(chip, nid, LOLA_VERB_GET_MAX_LEVEL, 0, 0, &val, NULL);
	snd_iprintf(buffer, "  Max-level: 0x%x\n", val);
}

__attribute__((used)) static void print_clock_widget(struct snd_info_buffer *buffer,
			       struct lola *chip, int nid)
{
	int i, j, num_clocks;
	unsigned int val;

	lola_read_param(chip, nid, LOLA_PAR_AUDIO_WIDGET_CAP, &val);
	snd_iprintf(buffer, "Node 0x%02x [Clock] wcaps 0x%x\n", nid, val);
	num_clocks = val & 0xff;
	for (i = 0; i < num_clocks; i += 4) {
		unsigned int res_ex;
		unsigned short items[4];
		const char *name;

		lola_codec_read(chip, nid, LOLA_VERB_GET_CLOCK_LIST,
				i, 0, &val, &res_ex);
		items[0] = val & 0xfff;
		items[1] = (val >> 16) & 0xfff;
		items[2] = res_ex & 0xfff;
		items[3] = (res_ex >> 16) & 0xfff;
		for (j = 0; j < 4; j++) {
			unsigned char type = items[j] >> 8;
			unsigned int freq = items[j] & 0xff;
			if (i + j >= num_clocks)
				break;
			if (type == LOLA_CLOCK_TYPE_INTERNAL) {
				name = "Internal";
				freq = lola_sample_rate_convert(freq);
			} else if (type == LOLA_CLOCK_TYPE_VIDEO) {
				name = "Video";
				freq = lola_sample_rate_convert(freq);
			} else {
				name = "Other";
			}
			snd_iprintf(buffer, "  Clock %d: Type %d:%s, freq=%d\n",
				    i + j, type, name, freq);
		}
	}
}

__attribute__((used)) static void print_mixer_widget(struct snd_info_buffer *buffer,
			       struct lola *chip, int nid)
{
	unsigned int val;

	lola_read_param(chip, nid, LOLA_PAR_AUDIO_WIDGET_CAP, &val);
	snd_iprintf(buffer, "Node 0x%02x [Mixer] wcaps 0x%x\n", nid, val);
}

__attribute__((used)) static void lola_proc_codec_read(struct snd_info_entry *entry,
				 struct snd_info_buffer *buffer)
{
	struct lola *chip = entry->private_data;
	unsigned int val;
	int i, nid;

	lola_read_param(chip, 0, LOLA_PAR_VENDOR_ID, &val);
	snd_iprintf(buffer, "Vendor: 0x%08x\n", val);
	lola_read_param(chip, 1, LOLA_PAR_FUNCTION_TYPE, &val);
	snd_iprintf(buffer, "Function Type: %d\n", val);
	lola_read_param(chip, 1, LOLA_PAR_SPECIFIC_CAPS, &val);
	snd_iprintf(buffer, "Specific-Caps: 0x%08x\n", val);
	snd_iprintf(buffer, "  Pins-In %d, Pins-Out %d\n",
		    chip->pin[CAPT].num_pins, chip->pin[PLAY].num_pins);
	nid = 2;
	for (i = 0; i < chip->pcm[CAPT].num_streams; i++, nid++)
		print_audio_widget(buffer, chip, nid, "[Audio-In]");
	for (i = 0; i < chip->pcm[PLAY].num_streams; i++, nid++)
		print_audio_widget(buffer, chip, nid, "[Audio-Out]");
	for (i = 0; i < chip->pin[CAPT].num_pins; i++, nid++)
		print_pin_widget(buffer, chip, nid, LOLA_PAR_AMP_IN_CAP,
				 "[Pin-In]");
	for (i = 0; i < chip->pin[PLAY].num_pins; i++, nid++)
		print_pin_widget(buffer, chip, nid, LOLA_PAR_AMP_OUT_CAP,
				 "[Pin-Out]");
	if (LOLA_AFG_CLOCK_WIDGET_PRESENT(chip->lola_caps)) {
		print_clock_widget(buffer, chip, nid);
		nid++;
	}
	if (LOLA_AFG_MIXER_WIDGET_PRESENT(chip->lola_caps)) {
		print_mixer_widget(buffer, chip, nid);
		nid++;
	}
}

__attribute__((used)) static void lola_proc_codec_rw_write(struct snd_info_entry *entry,
				     struct snd_info_buffer *buffer)
{
	struct lola *chip = entry->private_data;
	char line[64];
	unsigned int id, verb, data, extdata;
	while (!snd_info_get_line(buffer, line, sizeof(line))) {
		if (sscanf(line, "%u %u %u %u", &id, &verb, &data, &extdata) != 4)
			continue;
		lola_codec_read(chip, id, verb, data, extdata,
				&chip->debug_res,
				&chip->debug_res_ex);
	}
}

__attribute__((used)) static void lola_proc_codec_rw_read(struct snd_info_entry *entry,
				    struct snd_info_buffer *buffer)
{
	struct lola *chip = entry->private_data;
	snd_iprintf(buffer, "0x%x 0x%x\n", chip->debug_res, chip->debug_res_ex);
}

__attribute__((used)) static void lola_proc_regs_read(struct snd_info_entry *entry,
				struct snd_info_buffer *buffer)
{
	struct lola *chip = entry->private_data;
	int i;

	for (i = 0; i < 0x40; i += 4) {
		snd_iprintf(buffer, "BAR0 %02x: %08x\n", i,
			    readl(chip->bar[BAR0].remap_addr + i));
	}
	snd_iprintf(buffer, "\n");
	for (i = 0; i < 0x30; i += 4) {
		snd_iprintf(buffer, "BAR1 %02x: %08x\n", i,
			    readl(chip->bar[BAR1].remap_addr + i));
	}
	snd_iprintf(buffer, "\n");
	for (i = 0x80; i < 0xa0; i += 4) {
		snd_iprintf(buffer, "BAR1 %02x: %08x\n", i,
			    readl(chip->bar[BAR1].remap_addr + i));
	}
	snd_iprintf(buffer, "\n");
	for (i = 0; i < 32; i++) {
		snd_iprintf(buffer, "DSD %02x STS  %08x\n", i,
			    lola_dsd_read(chip, i, STS));
		snd_iprintf(buffer, "DSD %02x LPIB %08x\n", i,
			    lola_dsd_read(chip, i, LPIB));
		snd_iprintf(buffer, "DSD %02x CTL  %08x\n", i,
			    lola_dsd_read(chip, i, CTL));
		snd_iprintf(buffer, "DSD %02x LVIL %08x\n", i,
			    lola_dsd_read(chip, i, LVI));
		snd_iprintf(buffer, "DSD %02x BDPL %08x\n", i,
			    lola_dsd_read(chip, i, BDPL));
		snd_iprintf(buffer, "DSD %02x BDPU %08x\n", i,
			    lola_dsd_read(chip, i, BDPU));
	}
}

