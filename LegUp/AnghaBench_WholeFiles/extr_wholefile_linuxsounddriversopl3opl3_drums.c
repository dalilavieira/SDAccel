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
struct snd_opl3_drum_voice {size_t voice; size_t op; unsigned char am_vib; unsigned char ksl_level; unsigned char attack_decay; unsigned char sustain_release; unsigned char feedback_connection; unsigned char wave_select; } ;
struct snd_opl3_drum_note {unsigned char voice; unsigned char fnum; unsigned char octave_f; } ;
struct snd_opl3 {int drum_reg; int /*<<< orphan*/  (* command ) (struct snd_opl3*,unsigned char,unsigned char) ;} ;
struct snd_midi_channel {int gm_pan; } ;

/* Variables and functions */
#define  OPL3_BASSDRUM_ON 132 
#define  OPL3_CYMBAL_ON 131 
#define  OPL3_HIHAT_ON 130 
 unsigned char OPL3_LEFT ; 
 int OPL3_PERCUSSION_ENABLE ; 
 unsigned char OPL3_REG_AM_VIB ; 
 unsigned char OPL3_REG_ATTACK_DECAY ; 
 unsigned char OPL3_REG_FEEDBACK_CONNECTION ; 
 unsigned char OPL3_REG_FNUM_LOW ; 
 unsigned char OPL3_REG_KEYON_BLOCK ; 
 unsigned char OPL3_REG_KSL_LEVEL ; 
 unsigned char OPL3_REG_PERCUSSION ; 
 unsigned char OPL3_REG_SUSTAIN_RELEASE ; 
 unsigned char OPL3_REG_WAVE_SELECT ; 
#define  OPL3_SNAREDRUM_ON 129 
 unsigned char OPL3_STEREO_BITS ; 
#define  OPL3_TOMTOM_ON 128 
 unsigned char OPL3_VOICE_TO_LEFT ; 
 unsigned char OPL3_VOICE_TO_RIGHT ; 
 struct snd_opl3_drum_note bass_note ; 
 struct snd_opl3_drum_voice bass_op0 ; 
 struct snd_opl3_drum_voice bass_op1 ; 
 struct snd_opl3_drum_voice cymbal ; 
 struct snd_opl3_drum_voice hihat ; 
 struct snd_opl3_drum_voice snare ; 
 struct snd_opl3_drum_note snare_note ; 
 int /*<<< orphan*/  snd_opl3_calc_volume (unsigned char*,int,struct snd_midi_channel*) ; 
 unsigned char* snd_opl3_drum_table ; 
 unsigned char** snd_opl3_regmap ; 
 int /*<<< orphan*/  stub1 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub10 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub11 (struct snd_opl3*,unsigned char,unsigned char) ; 
 int /*<<< orphan*/  stub2 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub3 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub4 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub5 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub6 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub7 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub8 (struct snd_opl3*,unsigned short,unsigned char) ; 
 int /*<<< orphan*/  stub9 (struct snd_opl3*,unsigned short,unsigned char) ; 
 struct snd_opl3_drum_voice tomtom ; 
 struct snd_opl3_drum_note tomtom_note ; 

__attribute__((used)) static void snd_opl3_drum_voice_set(struct snd_opl3 *opl3,
				    struct snd_opl3_drum_voice *data)
{
	unsigned char op_offset = snd_opl3_regmap[data->voice][data->op];
	unsigned char voice_offset = data->voice;
	unsigned short opl3_reg;
	
	/* Set OPL3 AM_VIB register */ 
	opl3_reg = OPL3_LEFT | (OPL3_REG_AM_VIB + op_offset);
	opl3->command(opl3, opl3_reg, data->am_vib);

	/* Set OPL3 KSL_LEVEL register */ 
	opl3_reg = OPL3_LEFT | (OPL3_REG_KSL_LEVEL + op_offset);
	opl3->command(opl3, opl3_reg, data->ksl_level);

	/* Set OPL3 ATTACK_DECAY register */ 
	opl3_reg = OPL3_LEFT | (OPL3_REG_ATTACK_DECAY + op_offset);
	opl3->command(opl3, opl3_reg, data->attack_decay);

	/* Set OPL3 SUSTAIN_RELEASE register */ 
	opl3_reg = OPL3_LEFT | (OPL3_REG_SUSTAIN_RELEASE + op_offset);
	opl3->command(opl3, opl3_reg, data->sustain_release);

	/* Set OPL3 FEEDBACK_CONNECTION register */ 
	opl3_reg = OPL3_LEFT | (OPL3_REG_FEEDBACK_CONNECTION + voice_offset);
	opl3->command(opl3, opl3_reg, data->feedback_connection);

	/* Select waveform */
	opl3_reg = OPL3_LEFT | (OPL3_REG_WAVE_SELECT + op_offset);
	opl3->command(opl3, opl3_reg, data->wave_select);
}

__attribute__((used)) static void snd_opl3_drum_note_set(struct snd_opl3 *opl3,
				   struct snd_opl3_drum_note *data)
{
	unsigned char voice_offset = data->voice;
	unsigned short opl3_reg;

	/* Set OPL3 FNUM_LOW register */ 
	opl3_reg = OPL3_LEFT | (OPL3_REG_FNUM_LOW + voice_offset);
	opl3->command(opl3, opl3_reg, data->fnum);

	/* Set OPL3 KEYON_BLOCK register */ 
	opl3_reg = OPL3_LEFT | (OPL3_REG_KEYON_BLOCK + voice_offset);
	opl3->command(opl3, opl3_reg, data->octave_f);
}

__attribute__((used)) static void snd_opl3_drum_vol_set(struct snd_opl3 *opl3,
				  struct snd_opl3_drum_voice *data,
				  int vel, struct snd_midi_channel *chan)
{
	unsigned char op_offset = snd_opl3_regmap[data->voice][data->op];
	unsigned char voice_offset = data->voice;
	unsigned char reg_val;
	unsigned short opl3_reg;

	/* Set OPL3 KSL_LEVEL register */ 
	reg_val = data->ksl_level;
	snd_opl3_calc_volume(&reg_val, vel, chan);
	opl3_reg = OPL3_LEFT | (OPL3_REG_KSL_LEVEL + op_offset);
	opl3->command(opl3, opl3_reg, reg_val);

	/* Set OPL3 FEEDBACK_CONNECTION register */ 
	/* Set output voice connection */
	reg_val = data->feedback_connection | OPL3_STEREO_BITS;
	if (chan->gm_pan < 43)
		reg_val &= ~OPL3_VOICE_TO_RIGHT;
	if (chan->gm_pan > 85)
		reg_val &= ~OPL3_VOICE_TO_LEFT;
	opl3_reg = OPL3_LEFT | (OPL3_REG_FEEDBACK_CONNECTION + voice_offset);
	opl3->command(opl3, opl3_reg, reg_val);
}

void snd_opl3_load_drums(struct snd_opl3 *opl3)
{
	snd_opl3_drum_voice_set(opl3, &bass_op0);
	snd_opl3_drum_voice_set(opl3, &bass_op1);
	snd_opl3_drum_note_set(opl3, &bass_note);

	snd_opl3_drum_voice_set(opl3, &hihat);

	snd_opl3_drum_voice_set(opl3, &snare);
	snd_opl3_drum_note_set(opl3, &snare_note);

	snd_opl3_drum_voice_set(opl3, &tomtom);
	snd_opl3_drum_note_set(opl3, &tomtom_note);

	snd_opl3_drum_voice_set(opl3, &cymbal);
}

void snd_opl3_drum_switch(struct snd_opl3 *opl3, int note, int vel, int on_off,
			  struct snd_midi_channel *chan)
{
	unsigned char drum_mask;
	struct snd_opl3_drum_voice *drum_voice;

	if (!(opl3->drum_reg & OPL3_PERCUSSION_ENABLE))
		return;

	if ((note < 35) || (note > 81))
		return;
	drum_mask = snd_opl3_drum_table[note - 35];

	if (on_off) {
		switch (drum_mask) {
		case OPL3_BASSDRUM_ON:
			drum_voice = &bass_op1;
			break;
		case OPL3_HIHAT_ON:
			drum_voice = &hihat;
			break;
		case OPL3_SNAREDRUM_ON:
			drum_voice = &snare;
			break;
		case OPL3_TOMTOM_ON:
			drum_voice = &tomtom;
			break;
		case OPL3_CYMBAL_ON:
			drum_voice = &cymbal;
			break;
		default:
			drum_voice = &tomtom;
		}

		snd_opl3_drum_vol_set(opl3, drum_voice, vel, chan);
		opl3->drum_reg |= drum_mask;
	} else {
		opl3->drum_reg &= ~drum_mask;
	}
	opl3->command(opl3, OPL3_LEFT | OPL3_REG_PERCUSSION,
			 opl3->drum_reg);
}

