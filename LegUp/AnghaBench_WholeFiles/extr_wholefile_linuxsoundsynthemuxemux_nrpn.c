#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct snd_midi_channel_set {int dummy; } ;
struct snd_midi_channel {int* control; } ;
struct TYPE_3__ {scalar_t__ midi_mode; } ;
struct snd_emux_port {struct snd_emux* emu; TYPE_1__ chset; } ;
struct TYPE_4__ {int /*<<< orphan*/  (* sysex ) (struct snd_emux*,unsigned char*,int,int,struct snd_midi_channel_set*) ;} ;
struct snd_emux {TYPE_2__ ops; } ;
struct snd_card {int dummy; } ;
struct nrpn_conv_table {int control; int (* convert ) (int) ;int /*<<< orphan*/  effect; } ;

/* Variables and functions */
 int ARRAY_SIZE (struct nrpn_conv_table*) ; 
 int EMUX_FX_FLAG_ADD ; 
 int EMUX_FX_FLAG_SET ; 
 size_t FX_ATTACK ; 
 size_t FX_CUTOFF ; 
 size_t FX_RELEASE ; 
 size_t FX_RESONANCE ; 
 size_t FX_VIBDELAY ; 
 size_t FX_VIBDEPTH ; 
 size_t FX_VIBRATE ; 
 size_t MIDI_CTL_LSB_DATA_ENTRY ; 
 size_t MIDI_CTL_MSB_DATA_ENTRY ; 
 size_t MIDI_CTL_NONREG_PARM_NUM_LSB ; 
 size_t MIDI_CTL_NONREG_PARM_NUM_MSB ; 
 int /*<<< orphan*/  SNDRV_EMUX_UPDATE_VOLUME ; 
 scalar_t__ SNDRV_MIDI_MODE_GS ; 
#define  SNDRV_MIDI_SYSEX_GS_MASTER_VOLUME 128 
 struct nrpn_conv_table* awe_effects ; 
 struct nrpn_conv_table* gs_effects ; 
 int* gs_sense ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_emux_send_effect (struct snd_emux_port*,struct snd_midi_channel*,int /*<<< orphan*/ ,int,int) ; 
 int /*<<< orphan*/  snd_emux_update_port (struct snd_emux_port*,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_sf_calc_parm_attack (int) ; 
 scalar_t__ snd_sf_calc_parm_decay (int) ; 
 scalar_t__ snd_sf_calc_parm_delay (int) ; 
 scalar_t__ snd_sf_calc_parm_hold (int) ; 
 int stub1 (int) ; 
 int /*<<< orphan*/  stub2 (struct snd_emux*,unsigned char*,int,int,struct snd_midi_channel_set*) ; 
 struct nrpn_conv_table* xg_effects ; 
 int* xg_sense ; 

__attribute__((used)) static inline void snd_emux_proc_init(struct snd_emux *emu,
				      struct snd_card *card, int device) {}

__attribute__((used)) static inline void snd_emux_proc_free(struct snd_emux *emu) {}

__attribute__((used)) static int send_converted_effect(const struct nrpn_conv_table *table,
				 int num_tables,
				 struct snd_emux_port *port,
				 struct snd_midi_channel *chan,
				 int type, int val, int mode)
{
	int i, cval;
	for (i = 0; i < num_tables; i++) {
		if (table[i].control == type) {
			cval = table[i].convert(val);
			snd_emux_send_effect(port, chan, table[i].effect,
					     cval, mode);
			return 1;
		}
	}
	return 0;
}

__attribute__((used)) static int fx_delay(int val)
{
	return (unsigned short)snd_sf_calc_parm_delay(val);
}

__attribute__((used)) static int fx_attack(int val)
{
	return (unsigned short)snd_sf_calc_parm_attack(val);
}

__attribute__((used)) static int fx_hold(int val)
{
	return (unsigned short)snd_sf_calc_parm_hold(val);
}

__attribute__((used)) static int fx_decay(int val)
{
	return (unsigned short)snd_sf_calc_parm_decay(val);
}

__attribute__((used)) static int fx_the_value(int val)
{
	return (unsigned short)(val & 0xff);
}

__attribute__((used)) static int fx_twice_value(int val)
{
	return (unsigned short)((val * 2) & 0xff);
}

__attribute__((used)) static int fx_conv_pitch(int val)
{
	return (short)(val * 4096 / 1200);
}

__attribute__((used)) static int fx_conv_Q(int val)
{
	return (unsigned short)((val / 8) & 0xff);
}

__attribute__((used)) static int gs_cutoff(int val)
{
	return (val - 64) * gs_sense[FX_CUTOFF] / 50;
}

__attribute__((used)) static int gs_filterQ(int val)
{
	return (val - 64) * gs_sense[FX_RESONANCE] / 50;
}

__attribute__((used)) static int gs_attack(int val)
{
	return -(val - 64) * gs_sense[FX_ATTACK] / 50;
}

__attribute__((used)) static int gs_decay(int val)
{
	return -(val - 64) * gs_sense[FX_RELEASE] / 50;
}

__attribute__((used)) static int gs_release(int val)
{
	return -(val - 64) * gs_sense[FX_RELEASE] / 50;
}

__attribute__((used)) static int gs_vib_rate(int val)
{
	return (val - 64) * gs_sense[FX_VIBRATE] / 50;
}

__attribute__((used)) static int gs_vib_depth(int val)
{
	return (val - 64) * gs_sense[FX_VIBDEPTH] / 50;
}

__attribute__((used)) static int gs_vib_delay(int val)
{
	return -(val - 64) * gs_sense[FX_VIBDELAY] / 50;
}

void
snd_emux_nrpn(void *p, struct snd_midi_channel *chan,
	      struct snd_midi_channel_set *chset)
{
	struct snd_emux_port *port;

	port = p;
	if (snd_BUG_ON(!port || !chan))
		return;

	if (chan->control[MIDI_CTL_NONREG_PARM_NUM_MSB] == 127 &&
	    chan->control[MIDI_CTL_NONREG_PARM_NUM_LSB] <= 26) {
		int val;
		/* Win/DOS AWE32 specific NRPNs */
		/* both MSB/LSB necessary */
		val = (chan->control[MIDI_CTL_MSB_DATA_ENTRY] << 7) |
			chan->control[MIDI_CTL_LSB_DATA_ENTRY]; 
		val -= 8192;
		send_converted_effect
			(awe_effects, ARRAY_SIZE(awe_effects),
			 port, chan, chan->control[MIDI_CTL_NONREG_PARM_NUM_LSB],
			 val, EMUX_FX_FLAG_SET);
		return;
	}

	if (port->chset.midi_mode == SNDRV_MIDI_MODE_GS &&
	    chan->control[MIDI_CTL_NONREG_PARM_NUM_MSB] == 1) {
		int val;
		/* GS specific NRPNs */
		/* only MSB is valid */
		val = chan->control[MIDI_CTL_MSB_DATA_ENTRY];
		send_converted_effect
			(gs_effects, ARRAY_SIZE(gs_effects),
			 port, chan, chan->control[MIDI_CTL_NONREG_PARM_NUM_LSB],
			 val, EMUX_FX_FLAG_ADD);
		return;
	}
}

__attribute__((used)) static int xg_cutoff(int val)
{
	return (val - 64) * xg_sense[FX_CUTOFF] / 64;
}

__attribute__((used)) static int xg_filterQ(int val)
{
	return (val - 64) * xg_sense[FX_RESONANCE] / 64;
}

__attribute__((used)) static int xg_attack(int val)
{
	return -(val - 64) * xg_sense[FX_ATTACK] / 64;
}

__attribute__((used)) static int xg_release(int val)
{
	return -(val - 64) * xg_sense[FX_RELEASE] / 64;
}

int
snd_emux_xg_control(struct snd_emux_port *port, struct snd_midi_channel *chan,
		    int param)
{
	return send_converted_effect(xg_effects, ARRAY_SIZE(xg_effects),
				     port, chan, param,
				     chan->control[param],
				     EMUX_FX_FLAG_ADD);
}

void
snd_emux_sysex(void *p, unsigned char *buf, int len, int parsed,
	       struct snd_midi_channel_set *chset)
{
	struct snd_emux_port *port;
	struct snd_emux *emu;

	port = p;
	if (snd_BUG_ON(!port || !chset))
		return;
	emu = port->emu;

	switch (parsed) {
	case SNDRV_MIDI_SYSEX_GS_MASTER_VOLUME:
		snd_emux_update_port(port, SNDRV_EMUX_UPDATE_VOLUME);
		break;
	default:
		if (emu->ops.sysex)
			emu->ops.sysex(emu, buf, len, parsed, chset);
		break;
	}
}

