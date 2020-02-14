#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_5__ {void (* write ) (struct snd_info_entry*,struct snd_info_buffer*) ;} ;
struct TYPE_6__ {TYPE_1__ text; } ;
struct snd_info_entry {int mode; struct snd_ca0106* private_data; TYPE_2__ c; } ;
struct snd_info_buffer {int dummy; } ;
struct snd_ca0106 {int /*<<< orphan*/  card; int /*<<< orphan*/  emu_lock; scalar_t__ port; } ;
typedef  int /*<<< orphan*/  line ;
struct TYPE_7__ {int val; int /*<<< orphan*/  name; } ;

/* Variables and functions */
 int ARRAY_SIZE (TYPE_3__*) ; 
 int IEC958_AES0_CON_EMPHASIS ; 
 int IEC958_AES0_CON_EMPHASIS_5015 ; 
 int IEC958_AES0_CON_NOT_COPYRIGHT ; 
 int IEC958_AES0_NONAUDIO ; 
 int IEC958_AES0_PROFESSIONAL ; 
 int IEC958_AES0_PRO_EMPHASIS ; 
#define  IEC958_AES0_PRO_EMPHASIS_5015 149 
#define  IEC958_AES0_PRO_EMPHASIS_CCITT 148 
#define  IEC958_AES0_PRO_EMPHASIS_NONE 147 
#define  IEC958_AES0_PRO_EMPHASIS_NOTID 146 
 int IEC958_AES0_PRO_FREQ_UNLOCKED ; 
 int IEC958_AES0_PRO_FS ; 
#define  IEC958_AES0_PRO_FS_32000 145 
#define  IEC958_AES0_PRO_FS_44100 144 
#define  IEC958_AES0_PRO_FS_48000 143 
 int IEC958_AES1_CON_CATEGORY ; 
 int IEC958_AES1_CON_ORIGINAL ; 
 int IEC958_AES1_PRO_MODE ; 
 int IEC958_AES1_PRO_MODE_STEREOPHONIC ; 
 int IEC958_AES1_PRO_USERBITS ; 
#define  IEC958_AES1_PRO_USERBITS_192 142 
#define  IEC958_AES1_PRO_USERBITS_UDEF 141 
 int IEC958_AES2_PRO_SBITS ; 
#define  IEC958_AES2_PRO_SBITS_20 140 
#define  IEC958_AES2_PRO_SBITS_24 139 
#define  IEC958_AES2_PRO_SBITS_UDEF 138 
 int IEC958_AES2_PRO_WORDLEN ; 
#define  IEC958_AES2_PRO_WORDLEN_20_16 137 
#define  IEC958_AES2_PRO_WORDLEN_22_18 136 
#define  IEC958_AES2_PRO_WORDLEN_23_19 135 
#define  IEC958_AES2_PRO_WORDLEN_24_20 134 
 int IEC958_AES3_CON_CLOCK ; 
#define  IEC958_AES3_CON_CLOCK_1000PPM 133 
#define  IEC958_AES3_CON_CLOCK_50PPM 132 
#define  IEC958_AES3_CON_CLOCK_VARIABLE 131 
 int IEC958_AES3_CON_FS ; 
#define  IEC958_AES3_CON_FS_32000 130 
#define  IEC958_AES3_CON_FS_44100 129 
#define  IEC958_AES3_CON_FS_48000 128 
 int SAMPLE_RATE_TRACKER_STATUS ; 
 int SPDIF_INPUT_STATUS ; 
 unsigned int inb (scalar_t__) ; 
 unsigned long inl (scalar_t__) ; 
 unsigned int inw (scalar_t__) ; 
 int /*<<< orphan*/  outl (int,scalar_t__) ; 
 TYPE_3__* snd_ca0106_con_category ; 
 int /*<<< orphan*/  snd_ca0106_i2c_write (struct snd_ca0106*,unsigned int,unsigned int) ; 
 void* snd_ca0106_ptr_read (struct snd_ca0106*,int,int) ; 
 int /*<<< orphan*/  snd_ca0106_ptr_write (struct snd_ca0106*,unsigned int,unsigned int,unsigned int) ; 
 int /*<<< orphan*/  snd_card_proc_new (int /*<<< orphan*/ ,char*,struct snd_info_entry**) ; 
 int /*<<< orphan*/  snd_info_get_line (struct snd_info_buffer*,char*,int) ; 
 int /*<<< orphan*/  snd_info_set_text_ops (struct snd_info_entry*,struct snd_ca0106*,void (*) (struct snd_info_entry*,struct snd_info_buffer*)) ; 
 int /*<<< orphan*/  snd_iprintf (struct snd_info_buffer*,char*,...) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int sscanf (char*,char*,...) ; 

__attribute__((used)) static void snd_ca0106_proc_dump_iec958( struct snd_info_buffer *buffer, u32 value)
{
	int i;
	u32 status[4];
	status[0] = value & 0xff;
	status[1] = (value >> 8) & 0xff;
	status[2] = (value >> 16)  & 0xff;
	status[3] = (value >> 24)  & 0xff;
	
	if (! (status[0] & IEC958_AES0_PROFESSIONAL)) {
		/* consumer */
		snd_iprintf(buffer, "Mode: consumer\n");
		snd_iprintf(buffer, "Data: ");
		if (!(status[0] & IEC958_AES0_NONAUDIO)) {
			snd_iprintf(buffer, "audio\n");
		} else {
			snd_iprintf(buffer, "non-audio\n");
		}
		snd_iprintf(buffer, "Rate: ");
		switch (status[3] & IEC958_AES3_CON_FS) {
		case IEC958_AES3_CON_FS_44100:
			snd_iprintf(buffer, "44100 Hz\n");
			break;
		case IEC958_AES3_CON_FS_48000:
			snd_iprintf(buffer, "48000 Hz\n");
			break;
		case IEC958_AES3_CON_FS_32000:
			snd_iprintf(buffer, "32000 Hz\n");
			break;
		default:
			snd_iprintf(buffer, "unknown\n");
			break;
		}
		snd_iprintf(buffer, "Copyright: ");
		if (status[0] & IEC958_AES0_CON_NOT_COPYRIGHT) {
			snd_iprintf(buffer, "permitted\n");
		} else {
			snd_iprintf(buffer, "protected\n");
		}
		snd_iprintf(buffer, "Emphasis: ");
		if ((status[0] & IEC958_AES0_CON_EMPHASIS) != IEC958_AES0_CON_EMPHASIS_5015) {
			snd_iprintf(buffer, "none\n");
		} else {
			snd_iprintf(buffer, "50/15us\n");
		}
		snd_iprintf(buffer, "Category: ");
		for (i = 0; i < ARRAY_SIZE(snd_ca0106_con_category); i++) {
			if ((status[1] & IEC958_AES1_CON_CATEGORY) == snd_ca0106_con_category[i].val) {
				snd_iprintf(buffer, "%s\n", snd_ca0106_con_category[i].name);
				break;
			}
		}
		if (i >= ARRAY_SIZE(snd_ca0106_con_category)) {
			snd_iprintf(buffer, "unknown 0x%x\n", status[1] & IEC958_AES1_CON_CATEGORY);
		}
		snd_iprintf(buffer, "Original: ");
		if (status[1] & IEC958_AES1_CON_ORIGINAL) {
			snd_iprintf(buffer, "original\n");
		} else {
			snd_iprintf(buffer, "1st generation\n");
		}
		snd_iprintf(buffer, "Clock: ");
		switch (status[3] & IEC958_AES3_CON_CLOCK) {
		case IEC958_AES3_CON_CLOCK_1000PPM:
			snd_iprintf(buffer, "1000 ppm\n");
			break;
		case IEC958_AES3_CON_CLOCK_50PPM:
			snd_iprintf(buffer, "50 ppm\n");
			break;
		case IEC958_AES3_CON_CLOCK_VARIABLE:
			snd_iprintf(buffer, "variable pitch\n");
			break;
		default:
			snd_iprintf(buffer, "unknown\n");
			break;
		}
	} else {
		snd_iprintf(buffer, "Mode: professional\n");
		snd_iprintf(buffer, "Data: ");
		if (!(status[0] & IEC958_AES0_NONAUDIO)) {
			snd_iprintf(buffer, "audio\n");
		} else {
			snd_iprintf(buffer, "non-audio\n");
		}
		snd_iprintf(buffer, "Rate: ");
		switch (status[0] & IEC958_AES0_PRO_FS) {
		case IEC958_AES0_PRO_FS_44100:
			snd_iprintf(buffer, "44100 Hz\n");
			break;
		case IEC958_AES0_PRO_FS_48000:
			snd_iprintf(buffer, "48000 Hz\n");
			break;
		case IEC958_AES0_PRO_FS_32000:
			snd_iprintf(buffer, "32000 Hz\n");
			break;
		default:
			snd_iprintf(buffer, "unknown\n");
			break;
		}
		snd_iprintf(buffer, "Rate Locked: ");
		if (status[0] & IEC958_AES0_PRO_FREQ_UNLOCKED)
			snd_iprintf(buffer, "no\n");
		else
			snd_iprintf(buffer, "yes\n");
		snd_iprintf(buffer, "Emphasis: ");
		switch (status[0] & IEC958_AES0_PRO_EMPHASIS) {
		case IEC958_AES0_PRO_EMPHASIS_CCITT:
			snd_iprintf(buffer, "CCITT J.17\n");
			break;
		case IEC958_AES0_PRO_EMPHASIS_NONE:
			snd_iprintf(buffer, "none\n");
			break;
		case IEC958_AES0_PRO_EMPHASIS_5015:
			snd_iprintf(buffer, "50/15us\n");
			break;
		case IEC958_AES0_PRO_EMPHASIS_NOTID:
		default:
			snd_iprintf(buffer, "unknown\n");
			break;
		}
		snd_iprintf(buffer, "Stereophonic: ");
		if ((status[1] & IEC958_AES1_PRO_MODE) == IEC958_AES1_PRO_MODE_STEREOPHONIC) {
			snd_iprintf(buffer, "stereo\n");
		} else {
			snd_iprintf(buffer, "not indicated\n");
		}
		snd_iprintf(buffer, "Userbits: ");
		switch (status[1] & IEC958_AES1_PRO_USERBITS) {
		case IEC958_AES1_PRO_USERBITS_192:
			snd_iprintf(buffer, "192bit\n");
			break;
		case IEC958_AES1_PRO_USERBITS_UDEF:
			snd_iprintf(buffer, "user-defined\n");
			break;
		default:
			snd_iprintf(buffer, "unknown\n");
			break;
		}
		snd_iprintf(buffer, "Sample Bits: ");
		switch (status[2] & IEC958_AES2_PRO_SBITS) {
		case IEC958_AES2_PRO_SBITS_20:
			snd_iprintf(buffer, "20 bit\n");
			break;
		case IEC958_AES2_PRO_SBITS_24:
			snd_iprintf(buffer, "24 bit\n");
			break;
		case IEC958_AES2_PRO_SBITS_UDEF:
			snd_iprintf(buffer, "user defined\n");
			break;
		default:
			snd_iprintf(buffer, "unknown\n");
			break;
		}
		snd_iprintf(buffer, "Word Length: ");
		switch (status[2] & IEC958_AES2_PRO_WORDLEN) {
		case IEC958_AES2_PRO_WORDLEN_22_18:
			snd_iprintf(buffer, "22 bit or 18 bit\n");
			break;
		case IEC958_AES2_PRO_WORDLEN_23_19:
			snd_iprintf(buffer, "23 bit or 19 bit\n");
			break;
		case IEC958_AES2_PRO_WORDLEN_24_20:
			snd_iprintf(buffer, "24 bit or 20 bit\n");
			break;
		case IEC958_AES2_PRO_WORDLEN_20_16:
			snd_iprintf(buffer, "20 bit or 16 bit\n");
			break;
		default:
			snd_iprintf(buffer, "unknown\n");
			break;
		}
	}
}

__attribute__((used)) static void snd_ca0106_proc_iec958(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
	u32 value;

        value = snd_ca0106_ptr_read(emu, SAMPLE_RATE_TRACKER_STATUS, 0);
	snd_iprintf(buffer, "Status: %s, %s, %s\n",
		  (value & 0x100000) ? "Rate Locked" : "Not Rate Locked",
		  (value & 0x200000) ? "SPDIF Locked" : "No SPDIF Lock",
		  (value & 0x400000) ? "Audio Valid" : "No valid audio" );
	snd_iprintf(buffer, "Estimated sample rate: %u\n", 
		  ((value & 0xfffff) * 48000) / 0x8000 );
	if (value & 0x200000) {
		snd_iprintf(buffer, "IEC958/SPDIF input status:\n");
        	value = snd_ca0106_ptr_read(emu, SPDIF_INPUT_STATUS, 0);
		snd_ca0106_proc_dump_iec958(buffer, value);
	}

	snd_iprintf(buffer, "\n");
}

__attribute__((used)) static void snd_ca0106_proc_reg_write32(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
	unsigned long flags;
        char line[64];
        u32 reg, val;
        while (!snd_info_get_line(buffer, line, sizeof(line))) {
                if (sscanf(line, "%x %x", &reg, &val) != 2)
                        continue;
		if (reg < 0x40 && val <= 0xffffffff) {
			spin_lock_irqsave(&emu->emu_lock, flags);
			outl(val, emu->port + (reg & 0xfffffffc));
			spin_unlock_irqrestore(&emu->emu_lock, flags);
		}
        }
}

__attribute__((used)) static void snd_ca0106_proc_reg_read32(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
	unsigned long value;
	unsigned long flags;
	int i;
	snd_iprintf(buffer, "Registers:\n\n");
	for(i = 0; i < 0x20; i+=4) {
		spin_lock_irqsave(&emu->emu_lock, flags);
		value = inl(emu->port + i);
		spin_unlock_irqrestore(&emu->emu_lock, flags);
		snd_iprintf(buffer, "Register %02X: %08lX\n", i, value);
	}
}

__attribute__((used)) static void snd_ca0106_proc_reg_read16(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
        unsigned int value;
	unsigned long flags;
	int i;
	snd_iprintf(buffer, "Registers:\n\n");
	for(i = 0; i < 0x20; i+=2) {
		spin_lock_irqsave(&emu->emu_lock, flags);
		value = inw(emu->port + i);
		spin_unlock_irqrestore(&emu->emu_lock, flags);
		snd_iprintf(buffer, "Register %02X: %04X\n", i, value);
	}
}

__attribute__((used)) static void snd_ca0106_proc_reg_read8(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
	unsigned int value;
	unsigned long flags;
	int i;
	snd_iprintf(buffer, "Registers:\n\n");
	for(i = 0; i < 0x20; i+=1) {
		spin_lock_irqsave(&emu->emu_lock, flags);
		value = inb(emu->port + i);
		spin_unlock_irqrestore(&emu->emu_lock, flags);
		snd_iprintf(buffer, "Register %02X: %02X\n", i, value);
	}
}

__attribute__((used)) static void snd_ca0106_proc_reg_read1(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
	unsigned long value;
	int i,j;

	snd_iprintf(buffer, "Registers\n");
	for(i = 0; i < 0x40; i++) {
		snd_iprintf(buffer, "%02X: ",i);
		for (j = 0; j < 4; j++) {
                  value = snd_ca0106_ptr_read(emu, i, j);
		  snd_iprintf(buffer, "%08lX ", value);
                }
	        snd_iprintf(buffer, "\n");
	}
}

__attribute__((used)) static void snd_ca0106_proc_reg_read2(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
	unsigned long value;
	int i,j;

	snd_iprintf(buffer, "Registers\n");
	for(i = 0x40; i < 0x80; i++) {
		snd_iprintf(buffer, "%02X: ",i);
		for (j = 0; j < 4; j++) {
                  value = snd_ca0106_ptr_read(emu, i, j);
		  snd_iprintf(buffer, "%08lX ", value);
                }
	        snd_iprintf(buffer, "\n");
	}
}

__attribute__((used)) static void snd_ca0106_proc_reg_write(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
        char line[64];
        unsigned int reg, channel_id , val;
        while (!snd_info_get_line(buffer, line, sizeof(line))) {
                if (sscanf(line, "%x %x %x", &reg, &channel_id, &val) != 3)
                        continue;
		if (reg < 0x80 && val <= 0xffffffff && channel_id <= 3)
                        snd_ca0106_ptr_write(emu, reg, channel_id, val);
        }
}

__attribute__((used)) static void snd_ca0106_proc_i2c_write(struct snd_info_entry *entry, 
				       struct snd_info_buffer *buffer)
{
	struct snd_ca0106 *emu = entry->private_data;
        char line[64];
        unsigned int reg, val;
        while (!snd_info_get_line(buffer, line, sizeof(line))) {
                if (sscanf(line, "%x %x", &reg, &val) != 2)
                        continue;
                if ((reg <= 0x7f) || (val <= 0x1ff)) {
                        snd_ca0106_i2c_write(emu, reg, val);
		}
        }
}

int snd_ca0106_proc_init(struct snd_ca0106 *emu)
{
	struct snd_info_entry *entry;
	
	if(! snd_card_proc_new(emu->card, "iec958", &entry))
		snd_info_set_text_ops(entry, emu, snd_ca0106_proc_iec958);
	if(! snd_card_proc_new(emu->card, "ca0106_reg32", &entry)) {
		snd_info_set_text_ops(entry, emu, snd_ca0106_proc_reg_read32);
		entry->c.text.write = snd_ca0106_proc_reg_write32;
		entry->mode |= 0200;
	}
	if(! snd_card_proc_new(emu->card, "ca0106_reg16", &entry))
		snd_info_set_text_ops(entry, emu, snd_ca0106_proc_reg_read16);
	if(! snd_card_proc_new(emu->card, "ca0106_reg8", &entry))
		snd_info_set_text_ops(entry, emu, snd_ca0106_proc_reg_read8);
	if(! snd_card_proc_new(emu->card, "ca0106_regs1", &entry)) {
		snd_info_set_text_ops(entry, emu, snd_ca0106_proc_reg_read1);
		entry->c.text.write = snd_ca0106_proc_reg_write;
		entry->mode |= 0200;
	}
	if(! snd_card_proc_new(emu->card, "ca0106_i2c", &entry)) {
		entry->c.text.write = snd_ca0106_proc_i2c_write;
		entry->private_data = emu;
		entry->mode |= 0200;
	}
	if(! snd_card_proc_new(emu->card, "ca0106_regs2", &entry)) 
		snd_info_set_text_ops(entry, emu, snd_ca0106_proc_reg_read2);
	return 0;
}

