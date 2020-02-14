#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_8__ ;
typedef  struct TYPE_16__   TYPE_7__ ;
typedef  struct TYPE_15__   TYPE_6__ ;
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  size_t USHORT ;
typedef  size_t ULONG ;
typedef  int UCHAR ;
struct TYPE_10__ {scalar_t__ blink; void* bkcol; void* fgcol; } ;
struct TYPE_11__ {int Asuchar; TYPE_1__ bits; } ;
struct TYPE_17__ {TYPE_2__ u; } ;
struct TYPE_16__ {int /*<<< orphan*/  FlushKeyboardQueue; int /*<<< orphan*/  GetKeyPolled; } ;
struct TYPE_15__ {void (* CopyLineTo ) (size_t,size_t) ;void (* PrintGraf ) (size_t,size_t,int) ;void (* ClrLine ) (size_t) ;void (* InvertLine ) (size_t) ;void (* HatchLine ) (size_t) ;void (* PrintLogo ) (void*) ;void (* PrintCursor ) (void*) ;void (* SaveGraphicsState ) () ;void (* RestoreGraphicsState ) () ;void (* ShowCursor ) () ;void (* HideCursor ) () ;void (* SetForegroundColor ) (void*) ;void (* SetBackgroundColor ) (void*) ;} ;
struct TYPE_14__ {size_t usCurX; size_t y; size_t usCurY; } ;
struct TYPE_12__ {int LowPart; } ;
struct TYPE_13__ {TYPE_3__ u; } ;
typedef  int* PUSHORT ;
typedef  int* PUCHAR ;
typedef  TYPE_4__ PHYSICAL_ADDRESS ;
typedef  void* ECOLORS ;
typedef  void* BOOLEAN ;

/* Variables and functions */
 int BYTESPERFONT ; 
 int /*<<< orphan*/  DPRINT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ENTER_FUNC () ; 
 int /*<<< orphan*/  EmptyRingBuffer () ; 
 void* FALSE ; 
 size_t FONTBUFFERSIZE ; 
 int FONTENTRIES ; 
 size_t GLOBAL_SCREEN_HEIGHT ; 
 size_t GLOBAL_SCREEN_WIDTH ; 
 int GRAPHICS ; 
 void* GRREGENABLESETRESET ; 
 void* GRREGMISC ; 
 void* GRREGREADMAPSEL ; 
 void* GRREGWRMODE ; 
 int /*<<< orphan*/  KeyboardFlushKeyboardQueue ; 
 int /*<<< orphan*/  KeyboardGetKeyPolled ; 
 int /*<<< orphan*/  LEAVE_FUNC () ; 
 int* MmMapIoSpace (TYPE_4__,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MmNonCached ; 
 int /*<<< orphan*/  MmUnmapIoSpace (int*,size_t) ; 
 int /*<<< orphan*/  NONPAGEDPOOL ; 
 int /*<<< orphan*/  NOT_IMPLEMENTED () ; 
 size_t OUTPUT_WINDOW ; 
 int /*<<< orphan*/  PICE_free (int*) ; 
 int* PICE_malloc (size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PICE_memcpy (int*,int*,size_t) ; 
 int /*<<< orphan*/  PICE_memset (int*,int,size_t) ; 
 size_t SCREEN_BUFFER_SIZE ; 
 int SEQUENCER ; 
 void* SQREGMAPMASK ; 
 void* SQREGMEMORY ; 
 int /*<<< orphan*/  SetWindowGeometry (int /*<<< orphan*/ ) ; 
 void* TRUE ; 
 TYPE_8__ attr ; 
 void* bCursorEnabled ; 
 int* cGraphTable ; 
 int* cGraphTable2 ; 
 TYPE_7__ ihandlers ; 
 int inb_p (int) ; 
 unsigned char inportb (int) ; 
 TYPE_6__ ohandlers ; 
 unsigned char oldgraphicsmisc ; 
 unsigned char oldgraphicsmode ; 
 unsigned char oldgraphicsreadmapsel ; 
 unsigned char oldgraphicssetresetenable ; 
 unsigned char oldsqregmapmask ; 
 unsigned char oldsqregmemory ; 
 int /*<<< orphan*/  outb_p (int,int) ; 
 int /*<<< orphan*/  outportb (int,unsigned char) ; 
 int* pFontBufferVga ; 
 int* pScreenBufferHardwareVga ; 
 int* pScreenBufferSaveVga ; 
 int* pScreenBufferTempVga ; 
 int* pScreenBufferVga ; 
 int /*<<< orphan*/  pice_restore_current_registers () ; 
 int /*<<< orphan*/  pice_save_current_registers () ; 
 int /*<<< orphan*/  pice_set_mode_3_80x25 () ; 
 TYPE_5__* wWindow ; 
 int /*<<< orphan*/  wWindowVga ; 

unsigned char read_vga_reg(int port, int reg)
{
  outportb(port,reg);
  return(inportb(port+1));
}

void write_vga_reg(int port, unsigned char reg, unsigned char value)
{
	outportb(port,reg);
	outportb(port+1,value);
}

void map_font_memory(void)
{
	oldgraphicssetresetenable = read_vga_reg(GRAPHICS, GRREGENABLESETRESET);
	oldgraphicsmode = read_vga_reg(GRAPHICS, GRREGWRMODE);
	oldgraphicsmisc = read_vga_reg(GRAPHICS, GRREGMISC);
	oldgraphicsreadmapsel = read_vga_reg(GRAPHICS, GRREGREADMAPSEL);
	oldsqregmapmask = read_vga_reg(SEQUENCER, SQREGMAPMASK);
	oldsqregmemory = read_vga_reg(SEQUENCER, SQREGMEMORY);


	/* Make sure set/reset enable is off */
	write_vga_reg(GRAPHICS,GRREGENABLESETRESET,0);
	/* Select read plane 2 */
	write_vga_reg(GRAPHICS,GRREGREADMAPSEL,0x02);
	/* Make sure write and read mode = 0 */
	write_vga_reg(GRAPHICS,GRREGWRMODE,0x00);
	/* Set mapping to 64K at a000:0 & turn off odd/even at the graphics reg */
	write_vga_reg(GRAPHICS,GRREGMISC, 0x04);
	/* Set sequencer plane to 2 */
	write_vga_reg(SEQUENCER,SQREGMAPMASK, 0x04);
	/* Turn off odd/even at the sequencer */
	write_vga_reg(SEQUENCER,SQREGMEMORY, 0x07);
}

void unmap_font_memory(void)
{
	write_vga_reg(GRAPHICS,GRREGENABLESETRESET,oldgraphicssetresetenable);
	write_vga_reg(GRAPHICS,GRREGWRMODE,oldgraphicsmode);
	write_vga_reg(GRAPHICS,GRREGREADMAPSEL,oldgraphicsreadmapsel);
	write_vga_reg(GRAPHICS,GRREGMISC, oldgraphicsmisc);
	write_vga_reg(SEQUENCER,SQREGMAPMASK, oldsqregmapmask);
	write_vga_reg(SEQUENCER,SQREGMEMORY, oldsqregmemory);
}

void save_font(UCHAR* graph_table)
{
	PUCHAR FontBase = pFontBufferVga;
	int i,j;
	map_font_memory();

	for (i=0; i < FONTENTRIES; i++)
		for (j=0; j < 16; j++)
				graph_table[i*16+j] = FontBase[i*32+j];

	unmap_font_memory();
}

void load_font(UCHAR* graph_table,int bEnter)
{
	PUCHAR FontBase = pFontBufferVga;
	int i,j;
	map_font_memory();

	if(bEnter)
	{
#ifdef VGA_EXTENDED
		for (i=0; i < FONTENTRIES; i++)
			for (j=0; j < 8; j++)
					FontBase[i*32+j] = graph_table[i*BYTESPERFONT+j];
#else // VGA_EXTENDED
		for (i=0; i < FONTENTRIES; i++)
			for (j=0; j < 16; j++)
					FontBase[i*32+j] = graph_table[i*BYTESPERFONT+(j/2)] << (j&1);
#endif // VGA_EXTENDED
	}
	else
	{
		for (i=0; i < FONTENTRIES; i++)
			for (j=0; j < 16; j++)
					FontBase[i*32+j] = graph_table[i*16+j];
	}

	unmap_font_memory();
}

void SetForegroundColorVga(ECOLORS col)
{
    attr.u.bits.fgcol = col;
    attr.u.bits.blink = 0;
}

void SetBackgroundColorVga(ECOLORS col)
{
    attr.u.bits.bkcol = col;
    attr.u.bits.blink = 0;
}

void PrintGrafVga(ULONG x,ULONG y,UCHAR c)
{
    ((PUSHORT)pScreenBufferVga)[y*GLOBAL_SCREEN_WIDTH + x] = (USHORT)((attr.u.Asuchar<<8)|c);
}

void ShowCursorVga(void)
{
    ENTER_FUNC();

    bCursorEnabled=TRUE;

	outb_p(0x0a,0x3d4);
	outb_p(inb_p(0x3d5)&~0x20,0x3d5);

    LEAVE_FUNC();
}

void HideCursorVga(void)
{
    ENTER_FUNC();
	bCursorEnabled=FALSE;

	outb_p(0x0a,0x3d4);
	outb_p(inb_p(0x3d5)|0x20,0x3d5);

    LEAVE_FUNC();
}

void CopyLineToVga(USHORT dest,USHORT src)
{
    PUSHORT p = (PUSHORT)pScreenBufferVga;

    ENTER_FUNC();

	PICE_memcpy(&p[dest*GLOBAL_SCREEN_WIDTH],&p[src*GLOBAL_SCREEN_WIDTH],GLOBAL_SCREEN_WIDTH*sizeof(USHORT));

    LEAVE_FUNC();
}

void InvertLineVga(ULONG line)
{
    ULONG i;
    PUSHORT p = (PUSHORT)pScreenBufferVga;
    USHORT attr;

    if(line < GLOBAL_SCREEN_HEIGHT)
    {
        attr = p[line*GLOBAL_SCREEN_WIDTH]>>8;
        attr = ((attr & 0x07)<<4) | ((attr & 0xF0)>>4);
        attr <<= 8;
        for(i=0;i<GLOBAL_SCREEN_WIDTH;i++)
            p[line*GLOBAL_SCREEN_WIDTH + i] = (p[line*GLOBAL_SCREEN_WIDTH + i] & 0x00FF) | attr;
    }
}

void HatchLineVga(ULONG line)
{
    ULONG i;
    PUSHORT p = (PUSHORT)pScreenBufferVga;

    if(line < GLOBAL_SCREEN_HEIGHT)
    {
        for(i=0;i<GLOBAL_SCREEN_WIDTH;i++)
            p[line*GLOBAL_SCREEN_WIDTH + i] = (p[line*GLOBAL_SCREEN_WIDTH + i] & 0xF0FF) | 0x0c00;
    }
}

void ClrLineVga(ULONG line)
{
    ULONG i;
    PUSHORT p = (PUSHORT)pScreenBufferVga;

    if(line < GLOBAL_SCREEN_HEIGHT)
    {
        for(i=0;i<GLOBAL_SCREEN_WIDTH;i++)
            p[line*GLOBAL_SCREEN_WIDTH + i] = (USHORT)((attr.u.Asuchar<<8) | 0x20);
    }
}

void PrintLogoVga(BOOLEAN bShow)
{
    NOT_IMPLEMENTED();
}

void PrintCursorVga(BOOLEAN bForce)
{
    static ULONG count=0;
    USHORT charoffset;
    UCHAR data;
    ULONG x=wWindow[OUTPUT_WINDOW].usCurX,y=wWindow[OUTPUT_WINDOW].y+wWindow[OUTPUT_WINDOW].usCurY;

	if( count++>250 )
	{
        count=0;

        charoffset = (y* GLOBAL_SCREEN_WIDTH + x);

		outb_p(0x0e,0x3d4);
		data=(UCHAR)((charoffset>>8)&0xFF);
		outb_p(data,0x3d5);

        outb_p(0x0f,0x3d4);
		data=(UCHAR)(charoffset & 0xFF);
		outb_p(data,0x3d5);
    }
}

void SaveGraphicsStateVga(void)
{
	UCHAR data;

	// save current regs
	pice_save_current_registers();

	// unprotect crtc regs 0-7
	outb_p(0x11,0x3d4);
	data = inb_p(0x3d5);
	outb_p(data & 0x7F,0x3d5);

	// save current font
	save_font(cGraphTable2);

	// restore original regs
#ifdef VGA_EXTENDED
	pice_set_mode_3_80x50();
#else
	pice_set_mode_3_80x25();
#endif

	// load a font
	load_font(cGraphTable,1);

	// copy the screen content to temp area
    PICE_memcpy(pScreenBufferTempVga,pScreenBufferHardwareVga,SCREEN_BUFFER_SIZE);
    // copy the console to the screen
    PICE_memcpy(pScreenBufferHardwareVga,pScreenBufferVga,SCREEN_BUFFER_SIZE);
    // save original pointer
    pScreenBufferSaveVga = pScreenBufferVga;
    // pScreenBufferVga now points to screen
    pScreenBufferVga = pScreenBufferHardwareVga;
}

void RestoreGraphicsStateVga(void)
{
	UCHAR data;

	// unprotect crtc regs 0-7
	outb_p(0x11,0x3d4);
	data = inb_p(0x3d5);
	outb_p(data & 0x7F,0x3d5);

	// restore original regs
	pice_restore_current_registers();

	// load a font
	load_font(cGraphTable2,0);

    pScreenBufferVga = pScreenBufferSaveVga;
    // copy screen to the console
    PICE_memcpy(pScreenBufferVga,pScreenBufferHardwareVga,SCREEN_BUFFER_SIZE);
    // copy the temp area to the screen
    PICE_memcpy(pScreenBufferHardwareVga,pScreenBufferTempVga,SCREEN_BUFFER_SIZE);
}

BOOLEAN ConsoleInitVga(void)
{
	BOOLEAN bResult = FALSE;
    PUSHORT p;
	PHYSICAL_ADDRESS FrameBuffer;
	PHYSICAL_ADDRESS FontBuffer;


    ENTER_FUNC();

    ohandlers.CopyLineTo            = CopyLineToVga;
    ohandlers.PrintGraf             = PrintGrafVga;
    ohandlers.ClrLine               = ClrLineVga;
    ohandlers.InvertLine            = InvertLineVga;
    ohandlers.HatchLine             = HatchLineVga;
    ohandlers.PrintLogo             = PrintLogoVga;
    ohandlers.PrintCursor           = PrintCursorVga;
    ohandlers.SaveGraphicsState     = SaveGraphicsStateVga;
    ohandlers.RestoreGraphicsState  = RestoreGraphicsStateVga;
    ohandlers.ShowCursor            = ShowCursorVga;
    ohandlers.HideCursor            = HideCursorVga;
    ohandlers.SetForegroundColor    = SetForegroundColorVga;
    ohandlers.SetBackgroundColor    = SetBackgroundColorVga;

    ihandlers.GetKeyPolled          = KeyboardGetKeyPolled;
    ihandlers.FlushKeyboardQueue    = KeyboardFlushKeyboardQueue;

    SetWindowGeometry(wWindowVga);

    GLOBAL_SCREEN_WIDTH = 80;
#ifndef VGA_EXTENDED
    GLOBAL_SCREEN_HEIGHT = 25;
#else // VGA_EXTENDED
    GLOBAL_SCREEN_HEIGHT = 50;
#endif // VGA_EXTENDED

    attr.u.Asuchar = 0x07;

    // the real framebuffer
	FrameBuffer.u.LowPart = 0xB8000;
	pScreenBufferHardwareVga = MmMapIoSpace(FrameBuffer,SCREEN_BUFFER_SIZE,MmNonCached);

	//The real font buffer
	FontBuffer.u.LowPart = 0xA0000;
	pFontBufferVga = MmMapIoSpace(FontBuffer,FONTBUFFERSIZE,MmNonCached);

    // the console
	pScreenBufferVga = PICE_malloc(SCREEN_BUFFER_SIZE,NONPAGEDPOOL);
    // the save area
	pScreenBufferTempVga = PICE_malloc(SCREEN_BUFFER_SIZE,NONPAGEDPOOL);

	if(pScreenBufferVga)
	{
        DPRINT((0,"VGA memory phys. 0x000b0000 mapped to virt. 0x%x\n",pScreenBufferVga));

        bResult = TRUE;

        p = (PUSHORT)pScreenBufferVga;

		PICE_memset(pScreenBufferVga,0x0,SCREEN_BUFFER_SIZE);

        DPRINT((0,"VGA memory cleared!\n"));

        EmptyRingBuffer();

        DPRINT((0,"ConsoleInitVga() SUCCESS!\n"));
	}

    LEAVE_FUNC();

	return bResult;
}

void ConsoleShutdownVga(void)
{
    ENTER_FUNC();

	if(pScreenBufferVga)
    {
        PICE_free(pScreenBufferVga);
        PICE_free(pScreenBufferTempVga);
		MmUnmapIoSpace(pScreenBufferHardwareVga,SCREEN_BUFFER_SIZE);
		MmUnmapIoSpace(pFontBufferVga,FONTBUFFERSIZE);
    }

    LEAVE_FUNC();
}

