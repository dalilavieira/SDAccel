#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct snd_info_entry {int dummy; } ;
struct snd_info_buffer {int dummy; } ;
struct TYPE_2__ {int /*<<< orphan*/  machine; int /*<<< orphan*/  version; int /*<<< orphan*/  release; int /*<<< orphan*/  nodename; int /*<<< orphan*/  sysname; } ;

/* Variables and functions */
 int ENOMEM ; 
 int ENXIO ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int SNDRV_CARDS ; 
 int SNDRV_OSS_INFO_DEV_AUDIO ; 
 int SNDRV_OSS_INFO_DEV_COUNT ; 
 int SNDRV_OSS_INFO_DEV_MIDI ; 
 int SNDRV_OSS_INFO_DEV_MIXERS ; 
 int SNDRV_OSS_INFO_DEV_SYNTH ; 
 int SNDRV_OSS_INFO_DEV_TIMERS ; 
 TYPE_1__* init_utsname () ; 
 int /*<<< orphan*/  kfree (char*) ; 
 char* kstrdup (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 scalar_t__ snd_BUG_ON (int) ; 
 int /*<<< orphan*/  snd_card_info_read_oss (struct snd_info_buffer*) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,...) ; 
 char*** snd_sndstat_strings ; 
 int /*<<< orphan*/  strings ; 

int snd_oss_info_register(int dev, int num, char *string)
{
	char *x;

	if (snd_BUG_ON(dev < 0 || dev >= SNDRV_OSS_INFO_DEV_COUNT))
		return -ENXIO;
	if (snd_BUG_ON(num < 0 || num >= SNDRV_CARDS))
		return -ENXIO;
	mutex_lock(&strings);
	if (string == NULL) {
		if ((x = snd_sndstat_strings[num][dev]) != NULL) {
			kfree(x);
			x = NULL;
		}
	} else {
		x = kstrdup(string, GFP_KERNEL);
		if (x == NULL) {
			mutex_unlock(&strings);
			return -ENOMEM;
		}
	}
	snd_sndstat_strings[num][dev] = x;
	mutex_unlock(&strings);
	return 0;
}

__attribute__((used)) static int snd_sndstat_show_strings(struct snd_info_buffer *buf, char *id, int dev)
{
	int idx, ok = -1;
	char *str;

	snd_iprintf(buf, "\n%s:", id);
	mutex_lock(&strings);
	for (idx = 0; idx < SNDRV_CARDS; idx++) {
		str = snd_sndstat_strings[idx][dev];
		if (str) {
			if (ok < 0) {
				snd_iprintf(buf, "\n");
				ok++;
			}
			snd_iprintf(buf, "%i: %s\n", idx, str);
		}
	}
	mutex_unlock(&strings);
	if (ok < 0)
		snd_iprintf(buf, " NOT ENABLED IN CONFIG\n");
	return ok;
}

__attribute__((used)) static void snd_sndstat_proc_read(struct snd_info_entry *entry,
				  struct snd_info_buffer *buffer)
{
	snd_iprintf(buffer, "Sound Driver:3.8.1a-980706 (ALSA emulation code)\n");
	snd_iprintf(buffer, "Kernel: %s %s %s %s %s\n",
		    init_utsname()->sysname,
		    init_utsname()->nodename,
		    init_utsname()->release,
		    init_utsname()->version,
		    init_utsname()->machine);
	snd_iprintf(buffer, "Config options: 0\n");
	snd_iprintf(buffer, "\nInstalled drivers: \n");
	snd_iprintf(buffer, "Type 10: ALSA emulation\n");
	snd_iprintf(buffer, "\nCard config: \n");
	snd_card_info_read_oss(buffer);
	snd_sndstat_show_strings(buffer, "Audio devices", SNDRV_OSS_INFO_DEV_AUDIO);
	snd_sndstat_show_strings(buffer, "Synth devices", SNDRV_OSS_INFO_DEV_SYNTH);
	snd_sndstat_show_strings(buffer, "Midi devices", SNDRV_OSS_INFO_DEV_MIDI);
	snd_sndstat_show_strings(buffer, "Timers", SNDRV_OSS_INFO_DEV_TIMERS);
	snd_sndstat_show_strings(buffer, "Mixers", SNDRV_OSS_INFO_DEV_MIXERS);
}

