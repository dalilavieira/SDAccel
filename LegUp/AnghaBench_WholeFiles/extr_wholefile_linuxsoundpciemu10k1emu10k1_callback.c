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
struct snd_midi_channel {int gm_modulation; int midi_pressure; scalar_t__* control; } ;
struct TYPE_7__ {unsigned int tremfrq; unsigned int moddelay; unsigned int modatkhld; unsigned int moddcysus; unsigned int voldelay; unsigned int volatkhld; unsigned int pefe; unsigned int lfo1delay; unsigned int lfo2delay; unsigned int reverb; unsigned int chorus; unsigned int filterQ; int voldcysus; int fmmod; int fm2frq2; scalar_t__ volrelease; scalar_t__ modrelease; } ;
struct TYPE_8__ {int sample_mode; int loopstart; unsigned int start; unsigned int end; unsigned int loopend; TYPE_3__ parm; } ;
struct snd_emux_voice {int ch; int state; unsigned int avol; unsigned int apitch; unsigned int apan; unsigned int aaux; scalar_t__ time; unsigned int ftarget; TYPE_4__ reg; struct snd_midi_channel* chan; scalar_t__ block; struct snd_emu10k1* hw; scalar_t__ vtarget; scalar_t__ acutoff; TYPE_1__* emu; } ;
struct snd_emux_port {int dummy; } ;
struct snd_emux {int max_voices; int /*<<< orphan*/  num_voices; struct snd_emux_voice* voices; struct snd_emu10k1* hw; int /*<<< orphan*/  ops; } ;
struct snd_emu10k1_voice {scalar_t__ number; } ;
struct snd_emu10k1_memblk {scalar_t__ map_locked; scalar_t__ mapped_page; } ;
struct TYPE_6__ {unsigned int addr; } ;
struct snd_emu10k1 {unsigned int address_mode; TYPE_2__ silent_page; scalar_t__ audigy; int /*<<< orphan*/ * voices; struct snd_emux* synth; } ;
struct best_voice {size_t voice; unsigned int time; } ;
struct TYPE_5__ {int /*<<< orphan*/  num_voices; } ;

/* Variables and functions */
 int /*<<< orphan*/  ATKHLDM ; 
 int /*<<< orphan*/  ATKHLDV ; 
 int /*<<< orphan*/  A_FXRT1 ; 
 int /*<<< orphan*/  CCCA ; 
 unsigned int CCCA_8BITSELECT ; 
 int /*<<< orphan*/  CCCA_CURRADDR ; 
 unsigned int CCCA_INTERPROM_0 ; 
 int CCCA_RESONANCE ; 
 int /*<<< orphan*/  CPF ; 
 int /*<<< orphan*/  CVCF ; 
 int /*<<< orphan*/  CVCF_CURRENTVOL ; 
 int /*<<< orphan*/  DCYSUSM ; 
 int /*<<< orphan*/  DCYSUSV ; 
 int DCYSUSV_CHANNELENABLE_MASK ; 
 int /*<<< orphan*/  DSL ; 
 int EINVAL ; 
 int /*<<< orphan*/  EMU10K1_SYNTH ; 
 int ENOMEM ; 
 int /*<<< orphan*/  ENVVAL ; 
 int /*<<< orphan*/  ENVVOL ; 
 int /*<<< orphan*/  FM2FRQ2 ; 
 int /*<<< orphan*/  FMMOD ; 
 int FXBUS_MIDI_CHORUS ; 
 int FXBUS_MIDI_LEFT ; 
 int FXBUS_MIDI_REVERB ; 
 int FXBUS_MIDI_RIGHT ; 
 int /*<<< orphan*/  FXRT ; 
 int /*<<< orphan*/  IFATN ; 
 int /*<<< orphan*/  IFATN_ATTENUATION ; 
 int /*<<< orphan*/  IP ; 
 unsigned int IP_TO_CP (int) ; 
 int /*<<< orphan*/  LFOVAL1 ; 
 int /*<<< orphan*/  LFOVAL2 ; 
 int /*<<< orphan*/  LIMITMAX (unsigned int,int) ; 
 int /*<<< orphan*/  LIMITVALUE (short,int,int) ; 
 int /*<<< orphan*/  MAPA ; 
 int /*<<< orphan*/  MAPB ; 
 unsigned int MAP_PTI_MASK0 ; 
 unsigned int MAP_PTI_MASK1 ; 
 size_t MIDI_CTL_E1_REVERB_DEPTH ; 
 size_t MIDI_CTL_E3_CHORUS_DEPTH ; 
 int MOD_SENSE ; 
 int /*<<< orphan*/  PEFE ; 
 int /*<<< orphan*/  PSST ; 
 int /*<<< orphan*/  PTRX ; 
 int /*<<< orphan*/  PTRX_FXSENDAMOUNT_A ; 
 int /*<<< orphan*/  PTRX_FXSENDAMOUNT_B ; 
 int SNDRV_EMUX_ST_OFF ; 
 int SNDRV_EMUX_ST_ON ; 
 int SNDRV_EMUX_ST_PENDING ; 
 int SNDRV_EMUX_ST_RELEASED ; 
 int SNDRV_EMUX_ST_STANDBY ; 
 int SNDRV_EMUX_UPDATE_FM2FRQ2 ; 
 int SNDRV_EMUX_UPDATE_FMMOD ; 
 int SNDRV_EMUX_UPDATE_PAN ; 
 int SNDRV_EMUX_UPDATE_PITCH ; 
 int SNDRV_EMUX_UPDATE_Q ; 
 int SNDRV_EMUX_UPDATE_TREMFREQ ; 
 int SNDRV_EMUX_UPDATE_VOLUME ; 
 int SNDRV_SFNT_SAMPLE_8BITS ; 
 int SNDRV_SFNT_SAMPLE_SINGLESHOT ; 
 int /*<<< orphan*/  TREMFRQ ; 
 int /*<<< orphan*/  VTFT ; 
 int V_END ; 
 int V_FREE ; 
 int V_OFF ; 
 int V_PLAYING ; 
 int V_RELEASED ; 
 int /*<<< orphan*/  Z1 ; 
 int /*<<< orphan*/  Z2 ; 
 int /*<<< orphan*/  emu10k1_ops ; 
static  void lookup_voices (struct snd_emux*,struct snd_emu10k1*,struct best_voice*,int) ; 
static  void set_filterQ (struct snd_emu10k1*,struct snd_emux_voice*) ; 
static  void set_fm2frq2 (struct snd_emu10k1*,struct snd_emux_voice*) ; 
static  void set_fmmod (struct snd_emu10k1*,struct snd_emux_voice*) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 scalar_t__ snd_emu10k1_memblk_map (struct snd_emu10k1*,struct snd_emu10k1_memblk*) ; 
 int snd_emu10k1_memblk_offset (struct snd_emu10k1_memblk*) ; 
 int snd_emu10k1_ptr_read (struct snd_emu10k1*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  snd_emu10k1_ptr_write (struct snd_emu10k1*,int /*<<< orphan*/ ,int,unsigned int) ; 
 scalar_t__ snd_emu10k1_voice_alloc (struct snd_emu10k1*,int /*<<< orphan*/ ,int,struct snd_emu10k1_voice**) ; 
 int /*<<< orphan*/  snd_emu10k1_voice_free (struct snd_emu10k1*,int /*<<< orphan*/ *) ; 

void
snd_emu10k1_ops_setup(struct snd_emux *emux)
{
	emux->ops = emu10k1_ops;
}

int
snd_emu10k1_synth_get_voice(struct snd_emu10k1 *hw)
{
	struct snd_emux *emu;
	struct snd_emux_voice *vp;
	struct best_voice best[V_END];
	int i;

	emu = hw->synth;

	lookup_voices(emu, hw, best, 1); /* no OFF voices */
	for (i = 0; i < V_END; i++) {
		if (best[i].voice >= 0) {
			int ch;
			vp = &emu->voices[best[i].voice];
			if ((ch = vp->ch) < 0) {
				/*
				dev_warn(emu->card->dev,
				       "synth_get_voice: ch < 0 (%d) ??", i);
				*/
				continue;
			}
			vp->emu->num_voices--;
			vp->ch = -1;
			vp->state = SNDRV_EMUX_ST_OFF;
			return ch;
		}
	}

	/* not found */
	return -ENOMEM;
}

__attribute__((used)) static void
release_voice(struct snd_emux_voice *vp)
{
	int dcysusv;
	struct snd_emu10k1 *hw;
	
	hw = vp->hw;
	dcysusv = 0x8000 | (unsigned char)vp->reg.parm.modrelease;
	snd_emu10k1_ptr_write(hw, DCYSUSM, vp->ch, dcysusv);
	dcysusv = 0x8000 | (unsigned char)vp->reg.parm.volrelease | DCYSUSV_CHANNELENABLE_MASK;
	snd_emu10k1_ptr_write(hw, DCYSUSV, vp->ch, dcysusv);
}

__attribute__((used)) static void
terminate_voice(struct snd_emux_voice *vp)
{
	struct snd_emu10k1 *hw;
	
	if (snd_BUG_ON(!vp))
		return;
	hw = vp->hw;
	snd_emu10k1_ptr_write(hw, DCYSUSV, vp->ch, 0x807f | DCYSUSV_CHANNELENABLE_MASK);
	if (vp->block) {
		struct snd_emu10k1_memblk *emem;
		emem = (struct snd_emu10k1_memblk *)vp->block;
		if (emem->map_locked > 0)
			emem->map_locked--;
	}
}

__attribute__((used)) static void
free_voice(struct snd_emux_voice *vp)
{
	struct snd_emu10k1 *hw;
	
	hw = vp->hw;
	/* FIXME: emu10k1_synth is broken. */
	/* This can get called with hw == 0 */
	/* Problem apparent on plug, unplug then plug */
	/* on the Audigy 2 ZS Notebook. */
	if (hw && (vp->ch >= 0)) {
		snd_emu10k1_ptr_write(hw, IFATN, vp->ch, 0xff00);
		snd_emu10k1_ptr_write(hw, DCYSUSV, vp->ch, 0x807f | DCYSUSV_CHANNELENABLE_MASK);
		// snd_emu10k1_ptr_write(hw, DCYSUSV, vp->ch, 0);
		snd_emu10k1_ptr_write(hw, VTFT, vp->ch, 0xffff);
		snd_emu10k1_ptr_write(hw, CVCF, vp->ch, 0xffff);
		snd_emu10k1_voice_free(hw, &hw->voices[vp->ch]);
		vp->emu->num_voices--;
		vp->ch = -1;
	}
}

__attribute__((used)) static void
update_voice(struct snd_emux_voice *vp, int update)
{
	struct snd_emu10k1 *hw;
	
	hw = vp->hw;
	if (update & SNDRV_EMUX_UPDATE_VOLUME)
		snd_emu10k1_ptr_write(hw, IFATN_ATTENUATION, vp->ch, vp->avol);
	if (update & SNDRV_EMUX_UPDATE_PITCH)
		snd_emu10k1_ptr_write(hw, IP, vp->ch, vp->apitch);
	if (update & SNDRV_EMUX_UPDATE_PAN) {
		snd_emu10k1_ptr_write(hw, PTRX_FXSENDAMOUNT_A, vp->ch, vp->apan);
		snd_emu10k1_ptr_write(hw, PTRX_FXSENDAMOUNT_B, vp->ch, vp->aaux);
	}
	if (update & SNDRV_EMUX_UPDATE_FMMOD)
		set_fmmod(hw, vp);
	if (update & SNDRV_EMUX_UPDATE_TREMFREQ)
		snd_emu10k1_ptr_write(hw, TREMFRQ, vp->ch, vp->reg.parm.tremfrq);
	if (update & SNDRV_EMUX_UPDATE_FM2FRQ2)
		set_fm2frq2(hw, vp);
	if (update & SNDRV_EMUX_UPDATE_Q)
		set_filterQ(hw, vp);
}

__attribute__((used)) static void
lookup_voices(struct snd_emux *emu, struct snd_emu10k1 *hw,
	      struct best_voice *best, int active_only)
{
	struct snd_emux_voice *vp;
	struct best_voice *bp;
	int  i;

	for (i = 0; i < V_END; i++) {
		best[i].time = (unsigned int)-1; /* XXX MAX_?INT really */
		best[i].voice = -1;
	}

	/*
	 * Go through them all and get a best one to use.
	 * NOTE: could also look at volume and pick the quietest one.
	 */
	for (i = 0; i < emu->max_voices; i++) {
		int state, val;

		vp = &emu->voices[i];
		state = vp->state;
		if (state == SNDRV_EMUX_ST_OFF) {
			if (vp->ch < 0) {
				if (active_only)
					continue;
				bp = best + V_FREE;
			} else
				bp = best + V_OFF;
		}
		else if (state == SNDRV_EMUX_ST_RELEASED ||
			 state == SNDRV_EMUX_ST_PENDING) {
			bp = best + V_RELEASED;
#if 1
			val = snd_emu10k1_ptr_read(hw, CVCF_CURRENTVOL, vp->ch);
			if (! val)
				bp = best + V_OFF;
#endif
		}
		else if (state == SNDRV_EMUX_ST_STANDBY)
			continue;
		else if (state & SNDRV_EMUX_ST_ON)
			bp = best + V_PLAYING;
		else
			continue;

		/* check if sample is finished playing (non-looping only) */
		if (bp != best + V_OFF && bp != best + V_FREE &&
		    (vp->reg.sample_mode & SNDRV_SFNT_SAMPLE_SINGLESHOT)) {
			val = snd_emu10k1_ptr_read(hw, CCCA_CURRADDR, vp->ch);
			if (val >= vp->reg.loopstart)
				bp = best + V_OFF;
		}

		if (vp->time < bp->time) {
			bp->time = vp->time;
			bp->voice = i;
		}
	}
}

__attribute__((used)) static struct snd_emux_voice *
get_voice(struct snd_emux *emu, struct snd_emux_port *port)
{
	struct snd_emu10k1 *hw;
	struct snd_emux_voice *vp;
	struct best_voice best[V_END];
	int i;

	hw = emu->hw;

	lookup_voices(emu, hw, best, 0);
	for (i = 0; i < V_END; i++) {
		if (best[i].voice >= 0) {
			vp = &emu->voices[best[i].voice];
			if (vp->ch < 0) {
				/* allocate a voice */
				struct snd_emu10k1_voice *hwvoice;
				if (snd_emu10k1_voice_alloc(hw, EMU10K1_SYNTH, 1, &hwvoice) < 0 || hwvoice == NULL)
					continue;
				vp->ch = hwvoice->number;
				emu->num_voices++;
			}
			return vp;
		}
	}

	/* not found */
	return NULL;
}

__attribute__((used)) static int
start_voice(struct snd_emux_voice *vp)
{
	unsigned int temp;
	int ch;
	unsigned int addr, mapped_offset;
	struct snd_midi_channel *chan;
	struct snd_emu10k1 *hw;
	struct snd_emu10k1_memblk *emem;
	
	hw = vp->hw;
	ch = vp->ch;
	if (snd_BUG_ON(ch < 0))
		return -EINVAL;
	chan = vp->chan;

	emem = (struct snd_emu10k1_memblk *)vp->block;
	if (emem == NULL)
		return -EINVAL;
	emem->map_locked++;
	if (snd_emu10k1_memblk_map(hw, emem) < 0) {
		/* dev_err(hw->card->devK, "emu: cannot map!\n"); */
		return -ENOMEM;
	}
	mapped_offset = snd_emu10k1_memblk_offset(emem) >> 1;
	vp->reg.start += mapped_offset;
	vp->reg.end += mapped_offset;
	vp->reg.loopstart += mapped_offset;
	vp->reg.loopend += mapped_offset;

	/* set channel routing */
	/* A = left(0), B = right(1), C = reverb(c), D = chorus(d) */
	if (hw->audigy) {
		temp = FXBUS_MIDI_LEFT | (FXBUS_MIDI_RIGHT << 8) | 
			(FXBUS_MIDI_REVERB << 16) | (FXBUS_MIDI_CHORUS << 24);
		snd_emu10k1_ptr_write(hw, A_FXRT1, ch, temp);
	} else {
		temp = (FXBUS_MIDI_LEFT << 16) | (FXBUS_MIDI_RIGHT << 20) | 
			(FXBUS_MIDI_REVERB << 24) | (FXBUS_MIDI_CHORUS << 28);
		snd_emu10k1_ptr_write(hw, FXRT, ch, temp);
	}

	/* channel to be silent and idle */
	snd_emu10k1_ptr_write(hw, DCYSUSV, ch, 0x0000);
	snd_emu10k1_ptr_write(hw, VTFT, ch, 0x0000FFFF);
	snd_emu10k1_ptr_write(hw, CVCF, ch, 0x0000FFFF);
	snd_emu10k1_ptr_write(hw, PTRX, ch, 0);
	snd_emu10k1_ptr_write(hw, CPF, ch, 0);

	/* set pitch offset */
	snd_emu10k1_ptr_write(hw, IP, vp->ch, vp->apitch);

	/* set envelope parameters */
	snd_emu10k1_ptr_write(hw, ENVVAL, ch, vp->reg.parm.moddelay);
	snd_emu10k1_ptr_write(hw, ATKHLDM, ch, vp->reg.parm.modatkhld);
	snd_emu10k1_ptr_write(hw, DCYSUSM, ch, vp->reg.parm.moddcysus);
	snd_emu10k1_ptr_write(hw, ENVVOL, ch, vp->reg.parm.voldelay);
	snd_emu10k1_ptr_write(hw, ATKHLDV, ch, vp->reg.parm.volatkhld);
	/* decay/sustain parameter for volume envelope is used
	   for triggerg the voice */

	/* cutoff and volume */
	temp = (unsigned int)vp->acutoff << 8 | (unsigned char)vp->avol;
	snd_emu10k1_ptr_write(hw, IFATN, vp->ch, temp);

	/* modulation envelope heights */
	snd_emu10k1_ptr_write(hw, PEFE, ch, vp->reg.parm.pefe);

	/* lfo1/2 delay */
	snd_emu10k1_ptr_write(hw, LFOVAL1, ch, vp->reg.parm.lfo1delay);
	snd_emu10k1_ptr_write(hw, LFOVAL2, ch, vp->reg.parm.lfo2delay);

	/* lfo1 pitch & cutoff shift */
	set_fmmod(hw, vp);
	/* lfo1 volume & freq */
	snd_emu10k1_ptr_write(hw, TREMFRQ, vp->ch, vp->reg.parm.tremfrq);
	/* lfo2 pitch & freq */
	set_fm2frq2(hw, vp);

	/* reverb and loop start (reverb 8bit, MSB) */
	temp = vp->reg.parm.reverb;
	temp += (int)vp->chan->control[MIDI_CTL_E1_REVERB_DEPTH] * 9 / 10;
	LIMITMAX(temp, 255);
	addr = vp->reg.loopstart;
	snd_emu10k1_ptr_write(hw, PSST, vp->ch, (temp << 24) | addr);

	/* chorus & loop end (chorus 8bit, MSB) */
	addr = vp->reg.loopend;
	temp = vp->reg.parm.chorus;
	temp += (int)chan->control[MIDI_CTL_E3_CHORUS_DEPTH] * 9 / 10;
	LIMITMAX(temp, 255);
	temp = (temp <<24) | addr;
	snd_emu10k1_ptr_write(hw, DSL, ch, temp);

	/* clear filter delay memory */
	snd_emu10k1_ptr_write(hw, Z1, ch, 0);
	snd_emu10k1_ptr_write(hw, Z2, ch, 0);

	/* invalidate maps */
	temp = (hw->silent_page.addr << hw->address_mode) | (hw->address_mode ? MAP_PTI_MASK1 : MAP_PTI_MASK0);
	snd_emu10k1_ptr_write(hw, MAPA, ch, temp);
	snd_emu10k1_ptr_write(hw, MAPB, ch, temp);
#if 0
	/* cache */
	{
		unsigned int val, sample;
		val = 32;
		if (vp->reg.sample_mode & SNDRV_SFNT_SAMPLE_8BITS)
			sample = 0x80808080;
		else {
			sample = 0;
			val *= 2;
		}

		/* cache */
		snd_emu10k1_ptr_write(hw, CCR, ch, 0x1c << 16);
		snd_emu10k1_ptr_write(hw, CDE, ch, sample);
		snd_emu10k1_ptr_write(hw, CDF, ch, sample);

		/* invalidate maps */
		temp = ((unsigned int)hw->silent_page.addr << hw_address_mode) | (hw->address_mode ? MAP_PTI_MASK1 : MAP_PTI_MASK0);
		snd_emu10k1_ptr_write(hw, MAPA, ch, temp);
		snd_emu10k1_ptr_write(hw, MAPB, ch, temp);
		
		/* fill cache */
		val -= 4;
		val <<= 25;
		val |= 0x1c << 16;
		snd_emu10k1_ptr_write(hw, CCR, ch, val);
	}
#endif

	/* Q & current address (Q 4bit value, MSB) */
	addr = vp->reg.start;
	temp = vp->reg.parm.filterQ;
	temp = (temp<<28) | addr;
	if (vp->apitch < 0xe400)
		temp |= CCCA_INTERPROM_0;
	else {
		unsigned int shift = (vp->apitch - 0xe000) >> 10;
		temp |= shift << 25;
	}
	if (vp->reg.sample_mode & SNDRV_SFNT_SAMPLE_8BITS)
		temp |= CCCA_8BITSELECT;
	snd_emu10k1_ptr_write(hw, CCCA, ch, temp);

	/* reset volume */
	temp = (unsigned int)vp->vtarget << 16;
	snd_emu10k1_ptr_write(hw, VTFT, ch, temp | vp->ftarget);
	snd_emu10k1_ptr_write(hw, CVCF, ch, temp | 0xff00);
	return 0;
}

__attribute__((used)) static void
trigger_voice(struct snd_emux_voice *vp)
{
	unsigned int temp, ptarget;
	struct snd_emu10k1 *hw;
	struct snd_emu10k1_memblk *emem;
	
	hw = vp->hw;

	emem = (struct snd_emu10k1_memblk *)vp->block;
	if (! emem || emem->mapped_page < 0)
		return; /* not mapped */

#if 0
	ptarget = (unsigned int)vp->ptarget << 16;
#else
	ptarget = IP_TO_CP(vp->apitch);
#endif
	/* set pitch target and pan (volume) */
	temp = ptarget | (vp->apan << 8) | vp->aaux;
	snd_emu10k1_ptr_write(hw, PTRX, vp->ch, temp);

	/* pitch target */
	snd_emu10k1_ptr_write(hw, CPF, vp->ch, ptarget);

	/* trigger voice */
	snd_emu10k1_ptr_write(hw, DCYSUSV, vp->ch, vp->reg.parm.voldcysus|DCYSUSV_CHANNELENABLE_MASK);
}

__attribute__((used)) static void
set_fmmod(struct snd_emu10k1 *hw, struct snd_emux_voice *vp)
{
	unsigned short fmmod;
	short pitch;
	unsigned char cutoff;
	int modulation;

	pitch = (char)(vp->reg.parm.fmmod>>8);
	cutoff = (vp->reg.parm.fmmod & 0xff);
	modulation = vp->chan->gm_modulation + vp->chan->midi_pressure;
	pitch += (MOD_SENSE * modulation) / 1200;
	LIMITVALUE(pitch, -128, 127);
	fmmod = ((unsigned char)pitch<<8) | cutoff;
	snd_emu10k1_ptr_write(hw, FMMOD, vp->ch, fmmod);
}

__attribute__((used)) static void
set_fm2frq2(struct snd_emu10k1 *hw, struct snd_emux_voice *vp)
{
	unsigned short fm2frq2;
	short pitch;
	unsigned char freq;
	int modulation;

	pitch = (char)(vp->reg.parm.fm2frq2>>8);
	freq = vp->reg.parm.fm2frq2 & 0xff;
	modulation = vp->chan->gm_modulation + vp->chan->midi_pressure;
	pitch += (MOD_SENSE * modulation) / 1200;
	LIMITVALUE(pitch, -128, 127);
	fm2frq2 = ((unsigned char)pitch<<8) | freq;
	snd_emu10k1_ptr_write(hw, FM2FRQ2, vp->ch, fm2frq2);
}

__attribute__((used)) static void
set_filterQ(struct snd_emu10k1 *hw, struct snd_emux_voice *vp)
{
	unsigned int val;
	val = snd_emu10k1_ptr_read(hw, CCCA, vp->ch) & ~CCCA_RESONANCE;
	val |= (vp->reg.parm.filterQ << 28);
	snd_emu10k1_ptr_write(hw, CCCA, vp->ch, val);
}

