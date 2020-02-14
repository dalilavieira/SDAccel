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
struct TYPE_6__ {char* name; int index; } ;
struct snd_kcontrol {int private_value; TYPE_3__ id; } ;
struct TYPE_4__ {int* value; } ;
struct TYPE_5__ {TYPE_1__ integer; } ;
struct snd_ctl_elem_value {TYPE_2__ value; } ;
struct snd_ctl_elem_id {int index; scalar_t__ numid; int /*<<< orphan*/  name; int /*<<< orphan*/  iface; } ;
struct snd_card {int dummy; } ;
typedef  int /*<<< orphan*/  sid ;

/* Variables and functions */
 int /*<<< orphan*/  SNDRV_CTL_ELEM_IFACE_CARD ; 
 int /*<<< orphan*/  SNDRV_CTL_EVENT_MASK_VALUE ; 
 int /*<<< orphan*/  jack_detect_kctl ; 
 int /*<<< orphan*/  memset (struct snd_ctl_elem_id*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ snd_ctl_find_id (struct snd_card*,struct snd_ctl_elem_id*) ; 
 struct snd_kcontrol* snd_ctl_new1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  snd_ctl_notify (struct snd_card*,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char const*) ; 
 int /*<<< orphan*/  strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 size_t strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 

__attribute__((used)) static int jack_detect_kctl_get(struct snd_kcontrol *kcontrol,
				struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.integer.value[0] = kcontrol->private_value;
	return 0;
}

__attribute__((used)) static int get_available_index(struct snd_card *card, const char *name)
{
	struct snd_ctl_elem_id sid;

	memset(&sid, 0, sizeof(sid));

	sid.index = 0;
	sid.iface = SNDRV_CTL_ELEM_IFACE_CARD;
	strlcpy(sid.name, name, sizeof(sid.name));

	while (snd_ctl_find_id(card, &sid)) {
		sid.index++;
		/* reset numid; otherwise snd_ctl_find_id() hits this again */
		sid.numid = 0;
	}

	return sid.index;
}

__attribute__((used)) static void jack_kctl_name_gen(char *name, const char *src_name, int size)
{
	size_t count = strlen(src_name);
	bool need_cat = true;

	/* remove redundant " Jack" from src_name */
	if (count >= 5)
		need_cat = strncmp(&src_name[count - 5], " Jack", 5) ? true : false;

	snprintf(name, size, need_cat ? "%s Jack" : "%s", src_name);

}

struct snd_kcontrol *
snd_kctl_jack_new(const char *name, struct snd_card *card)
{
	struct snd_kcontrol *kctl;

	kctl = snd_ctl_new1(&jack_detect_kctl, NULL);
	if (!kctl)
		return NULL;

	jack_kctl_name_gen(kctl->id.name, name, sizeof(kctl->id.name));
	kctl->id.index = get_available_index(card, kctl->id.name);
	kctl->private_value = 0;
	return kctl;
}

void snd_kctl_jack_report(struct snd_card *card,
			  struct snd_kcontrol *kctl, bool status)
{
	if (kctl->private_value == status)
		return;
	kctl->private_value = status;
	snd_ctl_notify(card, SNDRV_CTL_EVENT_MASK_VALUE, &kctl->id);
}

