#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_28__   TYPE_9__ ;
typedef  struct TYPE_27__   TYPE_8__ ;
typedef  struct TYPE_26__   TYPE_7__ ;
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;
typedef  struct TYPE_19__   TYPE_14__ ;
typedef  struct TYPE_18__   TYPE_13__ ;
typedef  struct TYPE_17__   TYPE_12__ ;
typedef  struct TYPE_16__   TYPE_11__ ;
typedef  struct TYPE_15__   TYPE_10__ ;

/* Type definitions */
struct TYPE_18__ {int cmd; int time; } ;
struct TYPE_17__ {int code; int /*<<< orphan*/  parm1; int /*<<< orphan*/  dev; } ;
struct TYPE_25__ {int chn; int cmd; int dev; int p1; int val; } ;
struct TYPE_24__ {int chn; int cmd; int dev; int note; int parm; } ;
struct TYPE_23__ {int cmd; int dev; int chn; int p1; int p2; scalar_t__ p3; } ;
struct TYPE_22__ {int chn; int note; int vel; } ;
struct TYPE_21__ {int /*<<< orphan*/  buf; int /*<<< orphan*/  dev; } ;
union evrec {int* c; int echo; TYPE_13__ t; TYPE_12__ s; TYPE_6__ l; TYPE_5__ v; TYPE_4__ e; TYPE_3__ n; TYPE_2__ x; } ;
typedef  int /*<<< orphan*/  tmp ;
struct TYPE_15__ {int channel; int param; int value; } ;
struct TYPE_28__ {int channel; int note; int velocity; } ;
struct TYPE_19__ {TYPE_10__ control; TYPE_9__ note; } ;
struct TYPE_16__ {int client; int port; } ;
struct TYPE_20__ {int client; int port; } ;
struct snd_seq_event {int type; TYPE_14__ data; TYPE_11__ source; TYPE_1__ dest; int /*<<< orphan*/  queue; } ;
struct seq_oss_timer {int realtime; int /*<<< orphan*/  cur_tick; } ;
struct TYPE_26__ {int event_passing; } ;
struct seq_oss_synthinfo {int nr_voices; TYPE_8__* ch; TYPE_7__ arg; } ;
struct seq_oss_devinfo {scalar_t__ cseq; int /*<<< orphan*/ * readq; int /*<<< orphan*/  writeq; TYPE_11__ addr; int /*<<< orphan*/  timer; int /*<<< orphan*/  seq_mode; int /*<<< orphan*/  file_mode; int /*<<< orphan*/  queue; } ;
typedef  int /*<<< orphan*/  abstime_t ;
struct TYPE_27__ {int note; int vel; } ;

/* Variables and functions */
 int CTL_PAN ; 
#define  CTRL_PITCH_BENDER 161 
#define  CTRL_PITCH_BENDER_RANGE 160 
 int EINVAL ; 
 int ENXIO ; 
#define  EV_CHN_COMMON 159 
#define  EV_CHN_VOICE 158 
#define  EV_SEQ_LOCAL 157 
#define  EV_SYSEX 156 
#define  EV_TIMING 155 
 int /*<<< orphan*/  LONG_EVENT_SIZE ; 
#define  MIDI_CHN_PRESSURE 154 
#define  MIDI_CTL_CHANGE 153 
#define  MIDI_KEY_PRESSURE 152 
#define  MIDI_NOTEOFF 151 
#define  MIDI_NOTEON 150 
#define  MIDI_PGM_CHANGE 149 
#define  MIDI_PITCH_BEND 148 
#define  SEQ_AFTERTOUCH 147 
#define  SEQ_BALANCE 146 
#define  SEQ_CONTROLLER 145 
#define  SEQ_ECHO 144 
#define  SEQ_EXTENDED 143 
#define  SEQ_MIDIPUTC 142 
#define  SEQ_NOTEOFF 141 
#define  SEQ_NOTEON 140 
#define  SEQ_PGMCHANGE 139 
#define  SEQ_PRIVATE 138 
#define  SEQ_SYNCTIMER 137 
#define  SEQ_VOLMODE 136 
#define  SEQ_WAIT 135 
 int SNDRV_SEQ_EVENT_CHANPRESS ; 
 int SNDRV_SEQ_EVENT_CONTROL14 ; 
 int SNDRV_SEQ_EVENT_CONTROLLER ; 
 scalar_t__ SNDRV_SEQ_EVENT_ECHO ; 
 int SNDRV_SEQ_EVENT_KEYPRESS ; 
 int SNDRV_SEQ_EVENT_NOTEOFF ; 
 int SNDRV_SEQ_EVENT_NOTEON ; 
 int SNDRV_SEQ_EVENT_PGMCHANGE ; 
 int SNDRV_SEQ_EVENT_PITCHBEND ; 
 int SNDRV_SEQ_EVENT_REGPARAM ; 
 int SNDRV_SEQ_OSS_FILE_WRITE ; 
 int /*<<< orphan*/  SNDRV_SEQ_OSS_MODE_MUSIC ; 
#define  SNDRV_SEQ_OSS_PASS_EVENTS 134 
#define  SNDRV_SEQ_OSS_PROCESS_EVENTS 133 
#define  SNDRV_SEQ_OSS_PROCESS_KEYPRESS 132 
#define  TMR_CONTINUE 131 
#define  TMR_ECHO 130 
#define  TMR_STOP 129 
#define  TMR_TEMPO 128 
 int array_index_nospec (int,int) ; 
static  int chn_common_event (struct seq_oss_devinfo*,union evrec*,struct snd_seq_event*) ; 
static  int chn_voice_event (struct seq_oss_devinfo*,union evrec*,struct snd_seq_event*) ; 
static  int extended_event (struct seq_oss_devinfo*,union evrec*,struct snd_seq_event*) ; 
 int /*<<< orphan*/  is_write_mode (int /*<<< orphan*/ ) ; 
static  int local_event (struct seq_oss_devinfo*,union evrec*,struct snd_seq_event*) ; 
 int /*<<< orphan*/  memcpy (TYPE_14__*,union evrec*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (union evrec*,int /*<<< orphan*/ ,int) ; 
static  int note_off_event (struct seq_oss_devinfo*,int,int,int,int,struct snd_seq_event*) ; 
static  int note_on_event (struct seq_oss_devinfo*,int,int,int,int,struct snd_seq_event*) ; 
static  int old_event (struct seq_oss_devinfo*,union evrec*,struct snd_seq_event*) ; 
static  int set_control_event (struct seq_oss_devinfo*,int,int,int,int,int,struct snd_seq_event*) ; 
static  int set_echo_event (struct seq_oss_devinfo*,union evrec*,struct snd_seq_event*) ; 
static  int set_note_event (struct seq_oss_devinfo*,int,int,int,int,int,struct snd_seq_event*) ; 
 int snd_seq_kernel_client_ctl (scalar_t__,unsigned int,void*) ; 
 int snd_seq_kernel_client_dispatch (scalar_t__,struct snd_seq_event*,int,int) ; 
 int snd_seq_oss_midi_filemode (struct seq_oss_devinfo*,int /*<<< orphan*/ ) ; 
 int snd_seq_oss_midi_input (struct snd_seq_event*,int,void*) ; 
 int /*<<< orphan*/  snd_seq_oss_midi_open (struct seq_oss_devinfo*,int /*<<< orphan*/ ,int) ; 
 int snd_seq_oss_midi_putc (struct seq_oss_devinfo*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct snd_seq_event*) ; 
 int /*<<< orphan*/  snd_seq_oss_readq_put_event (int /*<<< orphan*/ *,union evrec*) ; 
 int /*<<< orphan*/  snd_seq_oss_synth_addr (struct seq_oss_devinfo*,int,struct snd_seq_event*) ; 
 struct seq_oss_synthinfo* snd_seq_oss_synth_info (struct seq_oss_devinfo*,int) ; 
 int snd_seq_oss_synth_raw_event (struct seq_oss_devinfo*,int,int*,struct snd_seq_event*) ; 
 int snd_seq_oss_synth_sysex (struct seq_oss_devinfo*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,struct snd_seq_event*) ; 
 int snd_seq_oss_timer_continue (int /*<<< orphan*/ ) ; 
 int snd_seq_oss_timer_reset (int /*<<< orphan*/ ) ; 
 int snd_seq_oss_timer_stop (int /*<<< orphan*/ ) ; 
 int snd_seq_oss_timer_tempo (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  snd_seq_oss_writeq_wakeup (int /*<<< orphan*/ ,int) ; 
static  int timing_event (struct seq_oss_devinfo*,union evrec*,struct snd_seq_event*) ; 

__attribute__((used)) static inline int
snd_seq_oss_dispatch(struct seq_oss_devinfo *dp, struct snd_seq_event *ev, int atomic, int hop)
{
	return snd_seq_kernel_client_dispatch(dp->cseq, ev, atomic, hop);
}

__attribute__((used)) static inline int
snd_seq_oss_control(struct seq_oss_devinfo *dp, unsigned int type, void *arg)
{
	return snd_seq_kernel_client_ctl(dp->cseq, type, arg);
}

__attribute__((used)) static inline void
snd_seq_oss_fill_addr(struct seq_oss_devinfo *dp, struct snd_seq_event *ev,
		     int dest_client, int dest_port)
{
	ev->queue = dp->queue;
	ev->source = dp->addr;
	ev->dest.client = dest_client;
	ev->dest.port = dest_port;
}

__attribute__((used)) static inline abstime_t
snd_seq_oss_timer_cur_tick(struct seq_oss_timer *timer)
{
	return timer->cur_tick;
}

__attribute__((used)) static inline int
snd_seq_oss_timer_is_realtime(struct seq_oss_timer *timer)
{
	return timer->realtime;
}

int
snd_seq_oss_process_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
	switch (q->s.code) {
	case SEQ_EXTENDED:
		return extended_event(dp, q, ev);

	case EV_CHN_VOICE:
		return chn_voice_event(dp, q, ev);

	case EV_CHN_COMMON:
		return chn_common_event(dp, q, ev);

	case EV_TIMING:
		return timing_event(dp, q, ev);

	case EV_SEQ_LOCAL:
		return local_event(dp, q, ev);

	case EV_SYSEX:
		return snd_seq_oss_synth_sysex(dp, q->x.dev, q->x.buf, ev);

	case SEQ_MIDIPUTC:
		if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
			return -EINVAL;
		/* put a midi byte */
		if (! is_write_mode(dp->file_mode))
			break;
		if (snd_seq_oss_midi_open(dp, q->s.dev, SNDRV_SEQ_OSS_FILE_WRITE))
			break;
		if (snd_seq_oss_midi_filemode(dp, q->s.dev) & SNDRV_SEQ_OSS_FILE_WRITE)
			return snd_seq_oss_midi_putc(dp, q->s.dev, q->s.parm1, ev);
		break;

	case SEQ_ECHO:
		if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
			return -EINVAL;
		return set_echo_event(dp, q, ev);

	case SEQ_PRIVATE:
		if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
			return -EINVAL;
		return snd_seq_oss_synth_raw_event(dp, q->c[1], q->c, ev);

	default:
		if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
			return -EINVAL;
		return old_event(dp, q, ev);
	}
	return -EINVAL;
}

__attribute__((used)) static int
old_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
	switch (q->s.code) {
	case SEQ_NOTEOFF:
		return note_off_event(dp, 0, q->n.chn, q->n.note, q->n.vel, ev);

	case SEQ_NOTEON:
		return note_on_event(dp, 0, q->n.chn, q->n.note, q->n.vel, ev);

	case SEQ_WAIT:
		/* skip */
		break;

	case SEQ_PGMCHANGE:
		return set_control_event(dp, 0, SNDRV_SEQ_EVENT_PGMCHANGE,
					 q->n.chn, 0, q->n.note, ev);

	case SEQ_SYNCTIMER:
		return snd_seq_oss_timer_reset(dp->timer);
	}

	return -EINVAL;
}

__attribute__((used)) static int
extended_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
	int val;

	switch (q->e.cmd) {
	case SEQ_NOTEOFF:
		return note_off_event(dp, q->e.dev, q->e.chn, q->e.p1, q->e.p2, ev);

	case SEQ_NOTEON:
		return note_on_event(dp, q->e.dev, q->e.chn, q->e.p1, q->e.p2, ev);

	case SEQ_PGMCHANGE:
		return set_control_event(dp, q->e.dev, SNDRV_SEQ_EVENT_PGMCHANGE,
					 q->e.chn, 0, q->e.p1, ev);

	case SEQ_AFTERTOUCH:
		return set_control_event(dp, q->e.dev, SNDRV_SEQ_EVENT_CHANPRESS,
					 q->e.chn, 0, q->e.p1, ev);

	case SEQ_BALANCE:
		/* convert -128:127 to 0:127 */
		val = (char)q->e.p1;
		val = (val + 128) / 2;
		return set_control_event(dp, q->e.dev, SNDRV_SEQ_EVENT_CONTROLLER,
					 q->e.chn, CTL_PAN, val, ev);

	case SEQ_CONTROLLER:
		val = ((short)q->e.p3 << 8) | (short)q->e.p2;
		switch (q->e.p1) {
		case CTRL_PITCH_BENDER: /* SEQ1 V2 control */
			/* -0x2000:0x1fff */
			return set_control_event(dp, q->e.dev,
						 SNDRV_SEQ_EVENT_PITCHBEND,
						 q->e.chn, 0, val, ev);
		case CTRL_PITCH_BENDER_RANGE:
			/* conversion: 100/semitone -> 128/semitone */
			return set_control_event(dp, q->e.dev,
						 SNDRV_SEQ_EVENT_REGPARAM,
						 q->e.chn, 0, val*128/100, ev);
		default:
			return set_control_event(dp, q->e.dev,
						  SNDRV_SEQ_EVENT_CONTROL14,
						  q->e.chn, q->e.p1, val, ev);
		}

	case SEQ_VOLMODE:
		return snd_seq_oss_synth_raw_event(dp, q->e.dev, q->c, ev);

	}
	return -EINVAL;
}

__attribute__((used)) static int
chn_voice_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
	if (q->v.chn >= 32)
		return -EINVAL;
	switch (q->v.cmd) {
	case MIDI_NOTEON:
		return note_on_event(dp, q->v.dev, q->v.chn, q->v.note, q->v.parm, ev);

	case MIDI_NOTEOFF:
		return note_off_event(dp, q->v.dev, q->v.chn, q->v.note, q->v.parm, ev);

	case MIDI_KEY_PRESSURE:
		return set_note_event(dp, q->v.dev, SNDRV_SEQ_EVENT_KEYPRESS,
				       q->v.chn, q->v.note, q->v.parm, ev);

	}
	return -EINVAL;
}

__attribute__((used)) static int
chn_common_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
	if (q->l.chn >= 32)
		return -EINVAL;
	switch (q->l.cmd) {
	case MIDI_PGM_CHANGE:
		return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_PGMCHANGE,
					  q->l.chn, 0, q->l.p1, ev);

	case MIDI_CTL_CHANGE:
		return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_CONTROLLER,
					  q->l.chn, q->l.p1, q->l.val, ev);

	case MIDI_PITCH_BEND:
		/* conversion: 0:0x3fff -> -0x2000:0x1fff */
		return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_PITCHBEND,
					  q->l.chn, 0, q->l.val - 8192, ev);
		
	case MIDI_CHN_PRESSURE:
		return set_control_event(dp, q->l.dev, SNDRV_SEQ_EVENT_CHANPRESS,
					  q->l.chn, 0, q->l.val, ev);
	}
	return -EINVAL;
}

__attribute__((used)) static int
timing_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
	switch (q->t.cmd) {
	case TMR_ECHO:
		if (dp->seq_mode == SNDRV_SEQ_OSS_MODE_MUSIC)
			return set_echo_event(dp, q, ev);
		else {
			union evrec tmp;
			memset(&tmp, 0, sizeof(tmp));
			/* XXX: only for little-endian! */
			tmp.echo = (q->t.time << 8) | SEQ_ECHO;
			return set_echo_event(dp, &tmp, ev);
		} 

	case TMR_STOP:
		if (dp->seq_mode)
			return snd_seq_oss_timer_stop(dp->timer);
		return 0;

	case TMR_CONTINUE:
		if (dp->seq_mode)
			return snd_seq_oss_timer_continue(dp->timer);
		return 0;

	case TMR_TEMPO:
		if (dp->seq_mode)
			return snd_seq_oss_timer_tempo(dp->timer, q->t.time);
		return 0;
	}

	return -EINVAL;
}

__attribute__((used)) static int
local_event(struct seq_oss_devinfo *dp, union evrec *q, struct snd_seq_event *ev)
{
	return -EINVAL;
}

__attribute__((used)) static int
note_on_event(struct seq_oss_devinfo *dp, int dev, int ch, int note, int vel, struct snd_seq_event *ev)
{
	struct seq_oss_synthinfo *info;

	info = snd_seq_oss_synth_info(dp, dev);
	if (!info)
		return -ENXIO;

	switch (info->arg.event_passing) {
	case SNDRV_SEQ_OSS_PROCESS_EVENTS:
		if (! info->ch || ch < 0 || ch >= info->nr_voices) {
			/* pass directly */
			return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
		}

		ch = array_index_nospec(ch, info->nr_voices);
		if (note == 255 && info->ch[ch].note >= 0) {
			/* volume control */
			int type;
			//if (! vel)
				/* set volume to zero -- note off */
			//	type = SNDRV_SEQ_EVENT_NOTEOFF;
			//else
				if (info->ch[ch].vel)
				/* sample already started -- volume change */
				type = SNDRV_SEQ_EVENT_KEYPRESS;
			else
				/* sample not started -- start now */
				type = SNDRV_SEQ_EVENT_NOTEON;
			info->ch[ch].vel = vel;
			return set_note_event(dp, dev, type, ch, info->ch[ch].note, vel, ev);
		} else if (note >= 128)
			return -EINVAL; /* invalid */

		if (note != info->ch[ch].note && info->ch[ch].note >= 0)
			/* note changed - note off at beginning */
			set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEOFF, ch, info->ch[ch].note, 0, ev);
		/* set current status */
		info->ch[ch].note = note;
		info->ch[ch].vel = vel;
		if (vel) /* non-zero velocity - start the note now */
			return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
		return -EINVAL;
		
	case SNDRV_SEQ_OSS_PASS_EVENTS:
		/* pass the event anyway */
		return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);

	case SNDRV_SEQ_OSS_PROCESS_KEYPRESS:
		if (note >= 128) /* key pressure: shifted by 128 */
			return set_note_event(dp, dev, SNDRV_SEQ_EVENT_KEYPRESS, ch, note - 128, vel, ev);
		else /* normal note-on event */
			return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
	}
	return -EINVAL;
}

__attribute__((used)) static int
note_off_event(struct seq_oss_devinfo *dp, int dev, int ch, int note, int vel, struct snd_seq_event *ev)
{
	struct seq_oss_synthinfo *info;

	info = snd_seq_oss_synth_info(dp, dev);
	if (!info)
		return -ENXIO;

	switch (info->arg.event_passing) {
	case SNDRV_SEQ_OSS_PROCESS_EVENTS:
		if (! info->ch || ch < 0 || ch >= info->nr_voices) {
			/* pass directly */
			return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEON, ch, note, vel, ev);
		}

		ch = array_index_nospec(ch, info->nr_voices);
		if (info->ch[ch].note >= 0) {
			note = info->ch[ch].note;
			info->ch[ch].vel = 0;
			info->ch[ch].note = -1;
			return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEOFF, ch, note, vel, ev);
		}
		return -EINVAL; /* invalid */

	case SNDRV_SEQ_OSS_PASS_EVENTS:
	case SNDRV_SEQ_OSS_PROCESS_KEYPRESS:
		/* pass the event anyway */
		return set_note_event(dp, dev, SNDRV_SEQ_EVENT_NOTEOFF, ch, note, vel, ev);

	}
	return -EINVAL;
}

__attribute__((used)) static int
set_note_event(struct seq_oss_devinfo *dp, int dev, int type, int ch, int note, int vel, struct snd_seq_event *ev)
{
	if (!snd_seq_oss_synth_info(dp, dev))
		return -ENXIO;
	
	ev->type = type;
	snd_seq_oss_synth_addr(dp, dev, ev);
	ev->data.note.channel = ch;
	ev->data.note.note = note;
	ev->data.note.velocity = vel;

	return 0;
}

__attribute__((used)) static int
set_control_event(struct seq_oss_devinfo *dp, int dev, int type, int ch, int param, int val, struct snd_seq_event *ev)
{
	if (!snd_seq_oss_synth_info(dp, dev))
		return -ENXIO;
	
	ev->type = type;
	snd_seq_oss_synth_addr(dp, dev, ev);
	ev->data.control.channel = ch;
	ev->data.control.param = param;
	ev->data.control.value = val;

	return 0;
}

__attribute__((used)) static int
set_echo_event(struct seq_oss_devinfo *dp, union evrec *rec, struct snd_seq_event *ev)
{
	ev->type = SNDRV_SEQ_EVENT_ECHO;
	/* echo back to itself */
	snd_seq_oss_fill_addr(dp, ev, dp->addr.client, dp->addr.port);
	memcpy(&ev->data, rec, LONG_EVENT_SIZE);
	return 0;
}

int
snd_seq_oss_event_input(struct snd_seq_event *ev, int direct, void *private_data,
			int atomic, int hop)
{
	struct seq_oss_devinfo *dp = (struct seq_oss_devinfo *)private_data;
	union evrec *rec;

	if (ev->type != SNDRV_SEQ_EVENT_ECHO)
		return snd_seq_oss_midi_input(ev, direct, private_data);

	if (ev->source.client != dp->cseq)
		return 0; /* ignored */

	rec = (union evrec*)&ev->data;
	if (rec->s.code == SEQ_SYNCTIMER) {
		/* sync echo back */
		snd_seq_oss_writeq_wakeup(dp->writeq, rec->t.time);
		
	} else {
		/* echo back event */
		if (dp->readq == NULL)
			return 0;
		snd_seq_oss_readq_put_event(dp->readq, rec);
	}
	return 0;
}

