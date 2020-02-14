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
typedef  int u32 ;
struct radio_isa_card {int /*<<< orphan*/  io; int /*<<< orphan*/  mute; } ;

/* Variables and functions */
 int /*<<< orphan*/  GFP_KERNEL ; 
 int inb (int /*<<< orphan*/ ) ; 
 struct radio_isa_card* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  outb_p (int,int /*<<< orphan*/ ) ; 
 int v4l2_ctrl_g_ctrl (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct radio_isa_card *rtrack2_alloc(void)
{
	return kzalloc(sizeof(struct radio_isa_card), GFP_KERNEL);
}

__attribute__((used)) static void zero(struct radio_isa_card *isa)
{
	outb_p(1, isa->io);
	outb_p(3, isa->io);
	outb_p(1, isa->io);
}

__attribute__((used)) static void one(struct radio_isa_card *isa)
{
	outb_p(5, isa->io);
	outb_p(7, isa->io);
	outb_p(5, isa->io);
}

__attribute__((used)) static int rtrack2_s_frequency(struct radio_isa_card *isa, u32 freq)
{
	int i;

	freq = freq / 200 + 856;

	outb_p(0xc8, isa->io);
	outb_p(0xc9, isa->io);
	outb_p(0xc9, isa->io);

	for (i = 0; i < 10; i++)
		zero(isa);

	for (i = 14; i >= 0; i--)
		if (freq & (1 << i))
			one(isa);
		else
			zero(isa);

	outb_p(0xc8, isa->io);
	outb_p(v4l2_ctrl_g_ctrl(isa->mute), isa->io);
	return 0;
}

__attribute__((used)) static u32 rtrack2_g_signal(struct radio_isa_card *isa)
{
	/* bit set = no signal present	*/
	return (inb(isa->io) & 2) ? 0 : 0xffff;
}

__attribute__((used)) static int rtrack2_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
	outb(mute, isa->io);
	return 0;
}

