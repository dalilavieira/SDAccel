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
struct snd_emux {int dummy; } ;
struct snd_card {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void snd_emux_proc_init(struct snd_emux *emu,
				      struct snd_card *card, int device) {}

__attribute__((used)) static inline void snd_emux_proc_free(struct snd_emux *emu) {}

