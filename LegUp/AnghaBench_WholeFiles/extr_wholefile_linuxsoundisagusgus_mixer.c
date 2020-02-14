#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct snd_kcontrol {int private_value; } ;
struct TYPE_8__ {unsigned char active_voice; unsigned char** ics_regs; } ;
struct snd_gus_card {int mix_cntrl_reg; scalar_t__ ess_flag; scalar_t__ ics_flag; struct snd_card* card; int /*<<< orphan*/  reg_lock; scalar_t__ ics_flipped; TYPE_3__ gf1; } ;
struct TYPE_10__ {int* value; } ;
struct TYPE_9__ {TYPE_5__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_6__ {int max; scalar_t__ min; } ;
struct TYPE_7__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct snd_card {char* mixername; } ;

/* Variables and functions */
 unsigned int ARRAY_SIZE (int /*<<< orphan*/ *) ; 
 int EINVAL ; 
 int /*<<< orphan*/  GF1PAGE ; 
 int /*<<< orphan*/  GUSP (struct snd_gus_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MIXCNTRLPORT ; 
 int /*<<< orphan*/  MIXCNTRLREG ; 
 int /*<<< orphan*/  MIXDATAPORT ; 
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int SNDRV_ICS_GF1_DEV ; 
 int SNDRV_ICS_MASTER_DEV ; 
 int /*<<< orphan*/  outb (unsigned char,int /*<<< orphan*/ ) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_component_add (struct snd_card*,char*) ; 
 int snd_ctl_add (struct snd_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct snd_gus_card*) ; 
 int /*<<< orphan*/ * snd_gf1_controls ; 
 int /*<<< orphan*/ * snd_ics_controls ; 
 struct snd_gus_card* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcat (char*,char*) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int /*<<< orphan*/  swap (unsigned char,unsigned char) ; 

__attribute__((used)) static int snd_gf1_get_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_gus_card *gus = snd_kcontrol_chip(kcontrol);
	int shift = kcontrol->private_value & 0xff;
	int invert = (kcontrol->private_value >> 8) & 1;
	
	ucontrol->value.integer.value[0] = (gus->mix_cntrl_reg >> shift) & 1;
	if (invert)
		ucontrol->value.integer.value[0] ^= 1;
	return 0;
}

__attribute__((used)) static int snd_gf1_put_single(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_gus_card *gus = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	int shift = kcontrol->private_value & 0xff;
	int invert = (kcontrol->private_value >> 8) & 1;
	int change;
	unsigned char oval, nval;
	
	nval = ucontrol->value.integer.value[0] & 1;
	if (invert)
		nval ^= 1;
	nval <<= shift;
	spin_lock_irqsave(&gus->reg_lock, flags);
	oval = gus->mix_cntrl_reg;
	nval = (oval & ~(1 << shift)) | nval;
	change = nval != oval;
	outb(gus->mix_cntrl_reg = nval, GUSP(gus, MIXCNTRLREG));
	outb(gus->gf1.active_voice = 0, GUSP(gus, GF1PAGE));
	spin_unlock_irqrestore(&gus->reg_lock, flags);
	return change;
}

__attribute__((used)) static int snd_ics_info_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 127;
	return 0;
}

__attribute__((used)) static int snd_ics_get_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_gus_card *gus = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	int addr = kcontrol->private_value & 0xff;
	unsigned char left, right;
	
	spin_lock_irqsave(&gus->reg_lock, flags);
	left = gus->gf1.ics_regs[addr][0];
	right = gus->gf1.ics_regs[addr][1];
	spin_unlock_irqrestore(&gus->reg_lock, flags);
	ucontrol->value.integer.value[0] = left & 127;
	ucontrol->value.integer.value[1] = right & 127;
	return 0;
}

__attribute__((used)) static int snd_ics_put_double(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_gus_card *gus = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	int addr = kcontrol->private_value & 0xff;
	int change;
	unsigned char val1, val2, oval1, oval2;
	
	val1 = ucontrol->value.integer.value[0] & 127;
	val2 = ucontrol->value.integer.value[1] & 127;
	spin_lock_irqsave(&gus->reg_lock, flags);
	oval1 = gus->gf1.ics_regs[addr][0];
	oval2 = gus->gf1.ics_regs[addr][1];
	change = val1 != oval1 || val2 != oval2;
	gus->gf1.ics_regs[addr][0] = val1;
	gus->gf1.ics_regs[addr][1] = val2;
	if (gus->ics_flag && gus->ics_flipped &&
	    (addr == SNDRV_ICS_GF1_DEV || addr == SNDRV_ICS_MASTER_DEV))
		swap(val1, val2);
	addr <<= 3;
	outb(addr | 0, GUSP(gus, MIXCNTRLPORT));
	outb(1, GUSP(gus, MIXDATAPORT));
	outb(addr | 2, GUSP(gus, MIXCNTRLPORT));
	outb((unsigned char) val1, GUSP(gus, MIXDATAPORT));
	outb(addr | 1, GUSP(gus, MIXCNTRLPORT));
	outb(2, GUSP(gus, MIXDATAPORT));
	outb(addr | 3, GUSP(gus, MIXCNTRLPORT));
	outb((unsigned char) val2, GUSP(gus, MIXDATAPORT));
	spin_unlock_irqrestore(&gus->reg_lock, flags);
	return change;
}

int snd_gf1_new_mixer(struct snd_gus_card * gus)
{
	struct snd_card *card;
	unsigned int idx, max;
	int err;

	if (snd_BUG_ON(!gus))
		return -EINVAL;
	card = gus->card;
	if (snd_BUG_ON(!card))
		return -EINVAL;

	if (gus->ics_flag)
		snd_component_add(card, "ICS2101");
	if (card->mixername[0] == '\0') {
		strcpy(card->mixername, gus->ics_flag ? "GF1,ICS2101" : "GF1");
	} else {
		if (gus->ics_flag)
			strcat(card->mixername, ",ICS2101");
		strcat(card->mixername, ",GF1");
	}

	if (!gus->ics_flag) {
		max = gus->ess_flag ? 1 : ARRAY_SIZE(snd_gf1_controls);
		for (idx = 0; idx < max; idx++) {
			if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_gf1_controls[idx], gus))) < 0)
				return err;
		}
	} else {
		for (idx = 0; idx < ARRAY_SIZE(snd_ics_controls); idx++) {
			if ((err = snd_ctl_add(card, snd_ctl_new1(&snd_ics_controls[idx], gus))) < 0)
				return err;
		}
	}
	return 0;
}

