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
struct snd_opl4 {struct snd_card* card; int /*<<< orphan*/  reg_lock; } ;
struct snd_kcontrol {int private_value; } ;
struct TYPE_7__ {int* value; } ;
struct TYPE_8__ {TYPE_3__ integer; } ;
struct snd_ctl_elem_value {TYPE_4__ value; } ;
struct TYPE_5__ {int max; scalar_t__ min; } ;
struct TYPE_6__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_info {int count; TYPE_2__ value; int /*<<< orphan*/  type; } ;
struct snd_card {int /*<<< orphan*/  mixername; } ;

/* Variables and functions */
 int /*<<< orphan*/  SNDRV_CTL_ELEM_TYPE_INTEGER ; 
 int snd_ctl_add (struct snd_card*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snd_ctl_new1 (int /*<<< orphan*/ *,struct snd_opl4*) ; 
 struct snd_opl4* snd_kcontrol_chip (struct snd_kcontrol*) ; 
 int /*<<< orphan*/ * snd_opl4_controls ; 
 int snd_opl4_read (struct snd_opl4*,int) ; 
 int /*<<< orphan*/  snd_opl4_write (struct snd_opl4*,int,int) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  strcat (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static inline int snd_opl4_create_proc(struct snd_opl4 *opl4) { return 0; }

__attribute__((used)) static inline void snd_opl4_free_proc(struct snd_opl4 *opl4) {}

__attribute__((used)) static int snd_opl4_ctl_info(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_info *uinfo)
{
	uinfo->type = SNDRV_CTL_ELEM_TYPE_INTEGER;
	uinfo->count = 2;
	uinfo->value.integer.min = 0;
	uinfo->value.integer.max = 7;
	return 0;
}

__attribute__((used)) static int snd_opl4_ctl_get(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_opl4 *opl4 = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	u8 reg = kcontrol->private_value;
	u8 value;

	spin_lock_irqsave(&opl4->reg_lock, flags);
	value = snd_opl4_read(opl4, reg);
	spin_unlock_irqrestore(&opl4->reg_lock, flags);
	ucontrol->value.integer.value[0] = 7 - (value & 7);
	ucontrol->value.integer.value[1] = 7 - ((value >> 3) & 7);
	return 0;
}

__attribute__((used)) static int snd_opl4_ctl_put(struct snd_kcontrol *kcontrol, struct snd_ctl_elem_value *ucontrol)
{
	struct snd_opl4 *opl4 = snd_kcontrol_chip(kcontrol);
	unsigned long flags;
	u8 reg = kcontrol->private_value;
	u8 value, old_value;

	value = (7 - (ucontrol->value.integer.value[0] & 7)) |
		((7 - (ucontrol->value.integer.value[1] & 7)) << 3);
	spin_lock_irqsave(&opl4->reg_lock, flags);
	old_value = snd_opl4_read(opl4, reg);
	snd_opl4_write(opl4, reg, value);
	spin_unlock_irqrestore(&opl4->reg_lock, flags);
	return value != old_value;
}

int snd_opl4_create_mixer(struct snd_opl4 *opl4)
{
	struct snd_card *card = opl4->card;
	int i, err;

	strcat(card->mixername, ",OPL4");

	for (i = 0; i < 2; ++i) {
		err = snd_ctl_add(card, snd_ctl_new1(&snd_opl4_controls[i], opl4));
		if (err < 0)
			return err;
	}
	return 0;
}

