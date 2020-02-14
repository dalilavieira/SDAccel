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
typedef  int u8 ;
typedef  int u32 ;
struct TYPE_2__ {int* reg; int e; int data_mask; int data_shift; int rw; int rs; } ;

/* Variables and functions */
 int AUTO_INC ; 
 int BM_SIZE ; 
 int CLEAR_CMD ; 
 int CURSOR_FOLLOWS_DISP ; 
 int CUR_BLINK ; 
 int CUR_ON ; 
 int DISPLAY ; 
 int DISP_CNT_CMD ; 
 int DISP_ON ; 
 int EIGHT_BYTE ; 
 int ENOENT ; 
 int ENTRYMODE_CMD ; 
 int ETIME ; 
 int FUNC_SET_CMD ; 
 int HOME_CMD ; 
 int LARGE_FONT ; 
 int MAX_PROGRAMMABLE_CHARS ; 
 int MODE_DATA ; 
 int MODE_INST ; 
 int MOVE_CMD ; 
 int ONE_LINE ; 
 int PVC_BUSY ; 
 int PVC_LINELEN ; 
 int PVC_NLINES ; 
 int PVC_VISIBLE_CHARS ; 
 int RIGHT ; 
 int SMALL_FONT ; 
 int TIMEOUT ; 
 int TWO_LINES ; 
 int /*<<< orphan*/  ndelay (int) ; 
 TYPE_1__* picvue ; 
 int strlen (unsigned char const*) ; 

__attribute__((used)) static void pvc_reg_write(u32 val)
{
	*picvue->reg = val;
}

__attribute__((used)) static u32 pvc_reg_read(void)
{
	u32 tmp = *picvue->reg;
	return tmp;
}

__attribute__((used)) static void pvc_write_byte(u32 data, u8 byte)
{
	data |= picvue->e;
	pvc_reg_write(data);
	data &= ~picvue->data_mask;
	data |= byte << picvue->data_shift;
	pvc_reg_write(data);
	ndelay(220);
	pvc_reg_write(data & ~picvue->e);
	ndelay(220);
}

__attribute__((used)) static u8 pvc_read_byte(u32 data)
{
	u8 byte;

	data |= picvue->e;
	pvc_reg_write(data);
	ndelay(220);
	byte = (pvc_reg_read() & picvue->data_mask) >> picvue->data_shift;
	data &= ~picvue->e;
	pvc_reg_write(data);
	ndelay(220);
	return byte;
}

__attribute__((used)) static u8 pvc_read_data(void)
{
	u32 data = pvc_reg_read();
	u8 byte;
	data |= picvue->rw;
	data &= ~picvue->rs;
	pvc_reg_write(data);
	ndelay(40);
	byte = pvc_read_byte(data);
	data |= picvue->rs;
	pvc_reg_write(data);
	return byte;
}

__attribute__((used)) static int pvc_wait(void)
{
	int i = TIMEOUT;
	int err = 0;

	while ((pvc_read_data() & PVC_BUSY) && i)
		i--;
	if (i == 0)
		err = -ETIME;

	return err;
}

__attribute__((used)) static void pvc_write(u8 byte, int mode)
{
	u32 data = pvc_reg_read();
	data &= ~picvue->rw;
	if (mode == MODE_DATA)
		data |= picvue->rs;
	else
		data &= ~picvue->rs;
	pvc_reg_write(data);
	ndelay(40);
	pvc_write_byte(data, byte);
	if (mode == MODE_DATA)
		data &= ~picvue->rs;
	else
		data |= picvue->rs;
	pvc_reg_write(data);
	pvc_wait();
}

void pvc_write_string(const unsigned char *str, u8 addr, int line)
{
	int i = 0;

	if (line > 0 && (PVC_NLINES > 1))
		addr += 0x40 * line;
	pvc_write(0x80 | addr, MODE_INST);

	while (*str != 0 && i < PVC_LINELEN) {
		pvc_write(*str++, MODE_DATA);
		i++;
	}
}

void pvc_write_string_centered(const unsigned char *str, int line)
{
	int len = strlen(str);
	u8 addr;

	if (len > PVC_VISIBLE_CHARS)
		addr = 0;
	else
		addr = (PVC_VISIBLE_CHARS - strlen(str))/2;

	pvc_write_string(str, addr, line);
}

void pvc_dump_string(const unsigned char *str)
{
	int len = strlen(str);

	pvc_write_string(str, 0, 0);
	if (len > PVC_VISIBLE_CHARS)
		pvc_write_string(&str[PVC_VISIBLE_CHARS], 0, 1);
}

int pvc_program_cg(int charnum, u8 bitmap[BM_SIZE])
{
	int i;
	int addr;

	if (charnum > MAX_PROGRAMMABLE_CHARS)
		return -ENOENT;

	addr = charnum * 8;
	pvc_write(0x40 | addr, MODE_INST);

	for (i = 0; i < BM_SIZE; i++)
		pvc_write(bitmap[i], MODE_DATA);
	return 0;
}

__attribute__((used)) static void pvc_funcset(u8 cmd)
{
	pvc_write(FUNC_SET_CMD | (cmd & (EIGHT_BYTE|TWO_LINES|LARGE_FONT)),
		  MODE_INST);
}

__attribute__((used)) static void pvc_entrymode(u8 cmd)
{
	pvc_write(ENTRYMODE_CMD | (cmd & (AUTO_INC|CURSOR_FOLLOWS_DISP)),
		  MODE_INST);
}

void pvc_dispcnt(u8 cmd)
{
	pvc_write(DISP_CNT_CMD | (cmd & (DISP_ON|CUR_ON|CUR_BLINK)), MODE_INST);
}

void pvc_move(u8 cmd)
{
	pvc_write(MOVE_CMD | (cmd & (DISPLAY|RIGHT)), MODE_INST);
}

void pvc_clear(void)
{
	pvc_write(CLEAR_CMD, MODE_INST);
}

void pvc_home(void)
{
	pvc_write(HOME_CMD, MODE_INST);
}

int pvc_init(void)
{
	u8 cmd = EIGHT_BYTE;

	if (PVC_NLINES == 2)
		cmd |= (SMALL_FONT|TWO_LINES);
	else
		cmd |= (LARGE_FONT|ONE_LINE);
	pvc_funcset(cmd);
	pvc_dispcnt(DISP_ON);
	pvc_entrymode(AUTO_INC);

	pvc_clear();
	pvc_write_string_centered("Display", 0);
	pvc_write_string_centered("Initialized", 1);

	return 0;
}

