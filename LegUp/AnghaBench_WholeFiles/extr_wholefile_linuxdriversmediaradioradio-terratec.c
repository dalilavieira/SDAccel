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
struct radio_isa_card {scalar_t__ io; } ;
typedef  int /*<<< orphan*/  buffer ;

/* Variables and functions */
 int CLK_ON ; 
 int DATA ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int WRT_EN ; 
 int inb (scalar_t__) ; 
 struct radio_isa_card* kzalloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  outb (int,scalar_t__) ; 

__attribute__((used)) static struct radio_isa_card *terratec_alloc(void)
{
	return kzalloc(sizeof(struct radio_isa_card), GFP_KERNEL);
}

__attribute__((used)) static int terratec_s_mute_volume(struct radio_isa_card *isa, bool mute, int vol)
{
	int i;

	if (mute)
		vol = 0;
	vol = vol + (vol * 32); /* change both channels */
	for (i = 0; i < 8; i++) {
		if (vol & (0x80 >> i))
			outb(0x80, isa->io + 1);
		else
			outb(0x00, isa->io + 1);
	}
	return 0;
}

__attribute__((used)) static int terratec_s_frequency(struct radio_isa_card *isa, u32 freq)
{
	int i;
	int p;
	int temp;
	long rest;
	unsigned char buffer[25];		/* we have to bit shift 25 registers */

	freq = freq / 160;			/* convert the freq. to a nice to handle value */
	memset(buffer, 0, sizeof(buffer));

	rest = freq * 10 + 10700;	/* I once had understood what is going on here */
					/* maybe some wise guy (friedhelm?) can comment this stuff */
	i = 13;
	p = 10;
	temp = 102400;
	while (rest != 0) {
		if (rest % temp  == rest)
			buffer[i] = 0;
		else {
			buffer[i] = 1;
			rest = rest - temp;
		}
		i--;
		p--;
		temp = temp / 2;
	}

	for (i = 24; i > -1; i--) {	/* bit shift the values to the radiocard */
		if (buffer[i] == 1) {
			outb(WRT_EN | DATA, isa->io);
			outb(WRT_EN | DATA | CLK_ON, isa->io);
			outb(WRT_EN | DATA, isa->io);
		} else {
			outb(WRT_EN | 0x00, isa->io);
			outb(WRT_EN | 0x00 | CLK_ON, isa->io);
		}
	}
	outb(0x00, isa->io);
	return 0;
}

__attribute__((used)) static u32 terratec_g_signal(struct radio_isa_card *isa)
{
	/* bit set = no signal present	*/
	return (inb(isa->io) & 2) ? 0 : 0xffff;
}

