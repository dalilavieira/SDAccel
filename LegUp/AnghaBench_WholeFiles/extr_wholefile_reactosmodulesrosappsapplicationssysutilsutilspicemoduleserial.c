#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_26__   TYPE_9__ ;
typedef  struct TYPE_25__   TYPE_8__ ;
typedef  struct TYPE_24__   TYPE_7__ ;
typedef  struct TYPE_23__   TYPE_6__ ;
typedef  struct TYPE_22__   TYPE_5__ ;
typedef  struct TYPE_21__   TYPE_4__ ;
typedef  struct TYPE_20__   TYPE_3__ ;
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;
typedef  struct TYPE_17__   TYPE_11__ ;
typedef  struct TYPE_16__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ USHORT ;
typedef  long ULONG ;
typedef  int UCHAR ;
struct TYPE_26__ {scalar_t__ usCurY; scalar_t__ usCurX; } ;
struct TYPE_25__ {long line; void* bkcol; void* fgcol; int /*<<< orphan*/  type; } ;
struct TYPE_24__ {scalar_t__ ysize; scalar_t__ xsize; int /*<<< orphan*/  type; } ;
struct TYPE_23__ {int state; int x; int y; void* type; } ;
struct TYPE_22__ {long line; int /*<<< orphan*/  type; } ;
struct TYPE_21__ {int /*<<< orphan*/  build_number; int /*<<< orphan*/  minor_version; int /*<<< orphan*/  major_version; int /*<<< orphan*/  type; } ;
struct TYPE_20__ {long x; long y; int /*<<< orphan*/  string; void* bkcol; void* fgcol; int /*<<< orphan*/  type; } ;
struct TYPE_18__ {long packet_size; int packet_chksum; long packet_header_chksum; } ;
struct TYPE_19__ {int /*<<< orphan*/  data; TYPE_1__ header; } ;
struct TYPE_17__ {int (* GetKeyPolled ) () ;void (* FlushKeyboardQueue ) () ;} ;
struct TYPE_16__ {void (* CopyLineTo ) (scalar_t__,scalar_t__) ;void (* PrintGraf ) (long,long,int) ;void (* Flush ) () ;void (* ClrLine ) (long) ;void (* InvertLine ) (long) ;void (* HatchLine ) (long) ;void (* PrintLogo ) (void*) ;void (* PrintCursor ) (void*) ;void (* SaveGraphicsState ) () ;void (* RestoreGraphicsState ) () ;void (* ShowCursor ) () ;void (* HideCursor ) () ;void (* SetForegroundColor ) (void*) ;void (* SetBackgroundColor ) (void*) ;} ;
typedef  int /*<<< orphan*/  SERIAL_PACKET_HEADER ;
typedef  int /*<<< orphan*/  SERIAL_DATA_PACKET_PRINT ;
typedef  int /*<<< orphan*/  SERIAL_DATA_PACKET_POLL ;
typedef  int /*<<< orphan*/  SERIAL_DATA_PACKET_INVERTLINE ;
typedef  int /*<<< orphan*/  SERIAL_DATA_PACKET_CURSOR ;
typedef  int /*<<< orphan*/  SERIAL_DATA_PACKET_CONNECT ;
typedef  int /*<<< orphan*/  SERIAL_DATA_PACKET_CLRLINE ;
typedef  int* PUCHAR ;
typedef  TYPE_2__* PSERIAL_PACKET ;
typedef  TYPE_3__* PSERIAL_DATA_PACKET_PRINT ;
typedef  TYPE_4__* PSERIAL_DATA_PACKET_POLL ;
typedef  TYPE_5__* PSERIAL_DATA_PACKET_INVERTLINE ;
typedef  TYPE_6__* PSERIAL_DATA_PACKET_CURSOR ;
typedef  TYPE_7__* PSERIAL_DATA_PACKET_CONNECT ;
typedef  TYPE_8__* PSERIAL_DATA_PACKET_CLRLINE ;
typedef  int* LPSTR ;
typedef  void* ECOLORS ;
typedef  void* BOOLEAN ;

/* Variables and functions */
 int ACK ; 
 scalar_t__ COM1BASE ; 
 scalar_t__ COM2BASE ; 
 scalar_t__ COM3BASE ; 
 scalar_t__ COM4BASE ; 
 scalar_t__ DLH ; 
 scalar_t__ DLL ; 
 int DTR ; 
 int /*<<< orphan*/  ENTER_FUNC () ; 
 long EVEN_PARITY ; 
 int /*<<< orphan*/  EmptyRingBuffer () ; 
 void* FALSE ; 
 scalar_t__ FCR ; 
 int /*<<< orphan*/  FRAMEBUFFER_SIZE ; 
 scalar_t__ GLOBAL_SCREEN_HEIGHT ; 
 long GLOBAL_SCREEN_WIDTH ; 
 scalar_t__ IER ; 
 scalar_t__ LCR ; 
 int /*<<< orphan*/  LEAVE_FUNC () ; 
 scalar_t__ LSR ; 
 scalar_t__ MCR ; 
 int /*<<< orphan*/  NONPAGEDPOOL ; 
 int /*<<< orphan*/  NOT_IMPLEMENTED () ; 
 long NO_PARITY ; 
 long ODD_PARITY ; 
 size_t OUTPUT_WINDOW ; 
 int /*<<< orphan*/  PACKET_TYPE_CLRLINE ; 
 int /*<<< orphan*/  PACKET_TYPE_CONNECT ; 
 void* PACKET_TYPE_CURSOR ; 
 int /*<<< orphan*/  PACKET_TYPE_INVERTLINE ; 
 int /*<<< orphan*/  PACKET_TYPE_POLL ; 
 int /*<<< orphan*/  PACKET_TYPE_PRINT ; 
 int /*<<< orphan*/  PICE_BUILD ; 
 int /*<<< orphan*/  PICE_MAJOR_VERSION ; 
 int /*<<< orphan*/  PICE_MINOR_VERSION ; 
 int /*<<< orphan*/  PICE_free (int*) ; 
 int* PICE_malloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PICE_memcpy (int /*<<< orphan*/ ,int*,long) ; 
 int /*<<< orphan*/  PICE_strcpy (int /*<<< orphan*/ ,int*) ; 
 long PICE_strlen (int*) ; 
 int RCVRDY ; 
 int RTS ; 
 scalar_t__ RXR ; 
 void* SerialReadByte (int*) ; 
 int /*<<< orphan*/  SetWindowGeometry (int /*<<< orphan*/ ) ; 
 void* TRUE ; 
 scalar_t__ TXR ; 
 int XMTRDY ; 
 scalar_t__ assemble_packet ; 
 void* bCursorEnabled ; 
 void* eBackgroundColor ; 
 void* eForegroundColor ; 
 int* flush_buffer ; 
 long g_x ; 
 long g_y ; 
 TYPE_11__ ihandlers ; 
 int inportb (scalar_t__) ; 
 TYPE_10__ ohandlers ; 
 int /*<<< orphan*/  outportb (scalar_t__,int) ; 
 int* pScreenBufferSerial ; 
 scalar_t__ packet ; 
 int ucLastKeyRead ; 
 scalar_t__ ulFlushBufferPos ; 
 scalar_t__ usSerialPortBase ; 
 TYPE_9__* wWindow ; 
 int /*<<< orphan*/  wWindowSerial ; 

void SerialSetSpeed(ULONG baudrate)
{
    UCHAR c;
    ULONG divisor;

    divisor = (ULONG) (115200L/baudrate);

    c = inportb((USHORT)(usSerialPortBase + LCR));
    outportb((USHORT)(usSerialPortBase + LCR), (UCHAR)(c | 0x80)); // Set DLAB
    outportb((USHORT)(usSerialPortBase + DLL), (UCHAR)(divisor & 0x00FF));
    outportb((USHORT)(usSerialPortBase + DLH), (UCHAR)((divisor >> 8) & 0x00FF));
    outportb((USHORT)(usSerialPortBase + LCR), c);          // Reset DLAB

}

void SerialSetOthers(ULONG Parity, ULONG Bits, ULONG StopBit)
{
    ULONG setting;
    UCHAR c;

    if (usSerialPortBase == 0)					return ;
    if (Bits < 5 || Bits > 8)				return ;
    if (StopBit != 1 && StopBit != 2)			return ;
    if (Parity != NO_PARITY && Parity != ODD_PARITY && Parity != EVEN_PARITY)
							return;

    setting  = Bits-5;
    setting |= ((StopBit == 1) ? 0x00 : 0x04);
    setting |= Parity;

    c = inportb((USHORT)(usSerialPortBase + LCR));
    outportb((USHORT)(usSerialPortBase + LCR), (UCHAR)(c & ~0x80)); // Reset DLAB

    // no ints
    outportb((USHORT)(usSerialPortBase + IER), (UCHAR)0);

    // clear FIFO and disable them
    outportb((USHORT)(usSerialPortBase + FCR), (UCHAR)0);

    outportb((USHORT)(usSerialPortBase + LCR), (UCHAR)setting);

    outportb((USHORT)(usSerialPortBase + MCR),  DTR | RTS);


    return ;
}

void FlushSerialBuffer(void)
{
    UCHAR c;

    while(SerialReadByte(&c));
}

void SetupSerial(ULONG port,ULONG baudrate)
{
	USHORT ports[]={COM1BASE,COM2BASE,COM3BASE,COM4BASE};

    usSerialPortBase = ports[port-1];
	SerialSetOthers(NO_PARITY,8,1);
	SerialSetSpeed(baudrate);

    // clear out received bytes
    // else we would think there's a terminal connected
    FlushSerialBuffer();
}

BOOLEAN SerialReadByte(PUCHAR px)
{
    ULONG timeout;

    timeout = 0x00FFFFL;

    // Wait for transmitter to clear
    while ((inportb((USHORT)(usSerialPortBase + LSR)) & RCVRDY) == 0)
        if (!(--timeout))
        {
			return FALSE;
        }

    *px = inportb((USHORT)(usSerialPortBase + RXR));

    return TRUE;
}

BOOLEAN SerialSendByte(UCHAR x)
{
    ULONG timeout;

    timeout = 0x00FFFFL;

    // Wait for transmitter to clear
    while ((inportb((USHORT)(usSerialPortBase + LSR)) & XMTRDY) == 0)
        if (!(--timeout))
        {
			return FALSE;
        }

    outportb((USHORT)(usSerialPortBase + TXR), x);

	return TRUE;
}

UCHAR CheckSum(LPSTR p,ULONG Len)
{
	UCHAR ucCheckSum = 0;
	ULONG i;
	for(i=0;i<Len;i++)
	{
		ucCheckSum ^= *p++;
        ucCheckSum += 1;
	}

	return ucCheckSum;
}

BOOLEAN ReadPacket(PSERIAL_PACKET p)
{
    return TRUE;
}

BOOLEAN SendPacket(PSERIAL_PACKET p)
{
    PUCHAR pHeader = (PUCHAR)&p->header;
    ULONG i;
    UCHAR c;
    ULONG timeout;

    do
    {
        timeout = 10;
        pHeader = (PUCHAR)&p->header;
        for(i=0;i<(sizeof(SERIAL_PACKET_HEADER)+p->header.packet_size);i++)
        {
            if(!SerialSendByte(*pHeader++))
            {
                return FALSE;
            }
        }

        do
        {
            c = 0;
            SerialReadByte(&c);
            if(c != ACK)
                ucLastKeyRead = c;
        }while(c != ACK && timeout--);

    }while(c != ACK);

    return TRUE;
}

BOOLEAN SendPacketTimeout(PSERIAL_PACKET p)
{
    PUCHAR pHeader = (PUCHAR)&p->header;
    ULONG i;
    UCHAR c;
    ULONG timeout = 20;
    BOOLEAN bResult = TRUE;

    pHeader = (PUCHAR)&p->header;
    for(i=0;i<(sizeof(SERIAL_PACKET_HEADER)+p->header.packet_size);i++)
    {
        if(!SerialSendByte(*pHeader++))
        {
            return FALSE;
        }
    }

    do
    {
        c = 0xFF;
        SerialReadByte(&c);
    }while(c != ACK && timeout--);

    if(c != ACK)
        bResult = FALSE;

    return bResult;
}

PSERIAL_PACKET AssemblePacket(PUCHAR pData,ULONG ulSize)
{
    PSERIAL_PACKET p;
    ULONG ulCheckSum;

    p = (PSERIAL_PACKET)assemble_packet;

    // fill in header
    p->header.packet_chksum = CheckSum(pData,ulSize);
    p->header.packet_size = ulSize;
    p->header.packet_header_chksum = 0;
    ulCheckSum = (ULONG)CheckSum((PUCHAR)p,sizeof(SERIAL_PACKET_HEADER));
    p->header.packet_header_chksum = ulCheckSum;
    // attach data to packet
    PICE_memcpy(p->data,pData,ulSize);

    return p;
}

void SetForegroundColorSerial(ECOLORS col)
{
    eForegroundColor = col;
}

void SetBackgroundColorSerial(ECOLORS col)
{
    eBackgroundColor = col;
}

void PrintGrafSerial(ULONG x,ULONG y,UCHAR c)
{
    // put this into memory
    pScreenBufferSerial[y*GLOBAL_SCREEN_WIDTH + x] = c;

    // put this into cache
    if(ulFlushBufferPos == 0)
    {
        g_x = x;
        g_y = y;
    }

    flush_buffer[ulFlushBufferPos++] = c;
}

void FlushSerial(void)
{
    PSERIAL_DATA_PACKET_PRINT pPrint;
    PSERIAL_PACKET p;

    pPrint = (PSERIAL_DATA_PACKET_PRINT)packet;
    pPrint->type = PACKET_TYPE_PRINT;
    pPrint->x = g_x;
    pPrint->y = g_y;
    pPrint->fgcol = eForegroundColor;
    pPrint->bkcol = eBackgroundColor;
    flush_buffer[ulFlushBufferPos++] = 0;
    PICE_strcpy(pPrint->string,flush_buffer);
    ulFlushBufferPos = 0;

    p = AssemblePacket((PUCHAR)pPrint,sizeof(SERIAL_DATA_PACKET_PRINT)+PICE_strlen(flush_buffer));
    SendPacket(p);
}

void ShowCursorSerial(void)
{
    PSERIAL_DATA_PACKET_CURSOR pCursor;
    PSERIAL_PACKET p;

    ENTER_FUNC();

    bCursorEnabled = TRUE;

    pCursor = (PSERIAL_DATA_PACKET_CURSOR)packet;
    pCursor->type = PACKET_TYPE_CURSOR;
    pCursor->state = (UCHAR)TRUE;
    pCursor->x = (UCHAR)wWindow[OUTPUT_WINDOW].usCurX;
    pCursor->y = (UCHAR)wWindow[OUTPUT_WINDOW].usCurY;

    p = AssemblePacket((PUCHAR)pCursor,sizeof(SERIAL_DATA_PACKET_CURSOR));
    SendPacket(p);

    LEAVE_FUNC();
}

void HideCursorSerial(void)
{
    PSERIAL_DATA_PACKET_CURSOR pCursor;
    PSERIAL_PACKET p;

    ENTER_FUNC();

    bCursorEnabled = FALSE;

    pCursor = (PSERIAL_DATA_PACKET_CURSOR)packet;
    pCursor->type = PACKET_TYPE_CURSOR;
    pCursor->state = (UCHAR)TRUE;

    p = AssemblePacket((PUCHAR)pCursor,sizeof(SERIAL_DATA_PACKET_CURSOR));
    SendPacket(p);

    LEAVE_FUNC();
}

void CopyLineToSerial(USHORT dest,USHORT src)
{
    NOT_IMPLEMENTED();
}

void InvertLineSerial(ULONG line)
{
    PSERIAL_DATA_PACKET_INVERTLINE pInvertLine;
    PSERIAL_PACKET p;

    pInvertLine = (PSERIAL_DATA_PACKET_INVERTLINE)packet;
    pInvertLine->type = PACKET_TYPE_INVERTLINE;
    pInvertLine->line = line;

    p = AssemblePacket((PUCHAR)pInvertLine,sizeof(SERIAL_DATA_PACKET_INVERTLINE));
    SendPacket(p);
}

void HatchLineSerial(ULONG line)
{
    NOT_IMPLEMENTED();
}

void ClrLineSerial(ULONG line)
{
    PSERIAL_DATA_PACKET_CLRLINE pClrLine;
    PSERIAL_PACKET p;

    pClrLine = (PSERIAL_DATA_PACKET_CLRLINE)packet;
    pClrLine->type = PACKET_TYPE_CLRLINE;
    pClrLine->fgcol = eForegroundColor;
    pClrLine->bkcol = eBackgroundColor;
    pClrLine->line = line;

    p = AssemblePacket((PUCHAR)pClrLine,sizeof(SERIAL_DATA_PACKET_CLRLINE));
    SendPacket(p);
}

void PrintLogoSerial(BOOLEAN bShow)
{
    NOT_IMPLEMENTED();
}

void PrintCursorSerial(BOOLEAN bForce)
{
    NOT_IMPLEMENTED();
}

void SaveGraphicsStateSerial(void)
{
    // not implemented
}

void RestoreGraphicsStateSerial(void)
{
    // not implemented
}

UCHAR GetKeyPolledSerial(void)
{
    UCHAR ucResult;
    PSERIAL_DATA_PACKET_POLL pPoll;
    PSERIAL_PACKET p;

    pPoll =                 (PSERIAL_DATA_PACKET_POLL)packet;
    pPoll->type             = PACKET_TYPE_POLL;
    pPoll->major_version    = PICE_MAJOR_VERSION;
    pPoll->minor_version    = PICE_MINOR_VERSION;
    pPoll->build_number     = PICE_BUILD;

    p = AssemblePacket((PUCHAR)pPoll,sizeof(SERIAL_DATA_PACKET_POLL));
    SendPacket(p);

    ucResult = ucLastKeyRead;

    ucLastKeyRead = 0;

    return ucResult;
}

void FlushKeyboardQueueSerial(void)
{
    // not implemented
}

BOOLEAN Connect(USHORT xSize,USHORT ySize)
{
    PSERIAL_DATA_PACKET_CONNECT pConnect;
    PSERIAL_PACKET p;

    pConnect = (PSERIAL_DATA_PACKET_CONNECT)packet;
    pConnect->type = PACKET_TYPE_CONNECT;
    pConnect->xsize = xSize;
    pConnect->ysize = ySize;

    p = AssemblePacket((PUCHAR)pConnect,sizeof(SERIAL_DATA_PACKET_CONNECT));
    return SendPacketTimeout(p);
}

BOOLEAN ConsoleInitSerial(void)
{
	BOOLEAN bResult = FALSE;

    ENTER_FUNC();

    ohandlers.CopyLineTo            = CopyLineToSerial;
    ohandlers.PrintGraf             = PrintGrafSerial;
    ohandlers.Flush                 = FlushSerial;
    ohandlers.ClrLine               = ClrLineSerial;
    ohandlers.InvertLine            = InvertLineSerial;
    ohandlers.HatchLine             = HatchLineSerial;
    ohandlers.PrintLogo             = PrintLogoSerial;
    ohandlers.PrintCursor           = PrintCursorSerial;
    ohandlers.SaveGraphicsState     = SaveGraphicsStateSerial;
    ohandlers.RestoreGraphicsState  = RestoreGraphicsStateSerial;
    ohandlers.ShowCursor            = ShowCursorSerial;
    ohandlers.HideCursor            = HideCursorSerial;
    ohandlers.SetForegroundColor    = SetForegroundColorSerial;
    ohandlers.SetBackgroundColor    = SetBackgroundColorSerial;

    ihandlers.GetKeyPolled          = GetKeyPolledSerial;
    ihandlers.FlushKeyboardQueue    = FlushKeyboardQueueSerial;

    SetWindowGeometry(wWindowSerial);

    GLOBAL_SCREEN_WIDTH = 80;
    GLOBAL_SCREEN_HEIGHT = 60;

	pScreenBufferSerial = PICE_malloc(FRAMEBUFFER_SIZE, NONPAGEDPOOL);

    if(pScreenBufferSerial)
    {
	    bResult = TRUE;

        EmptyRingBuffer();

        SetupSerial(1,115200);

        // connect to terminal, if none's there, we give up
        bResult = Connect(GLOBAL_SCREEN_WIDTH,GLOBAL_SCREEN_HEIGHT);

        if(bResult)
        {
            GetKeyPolledSerial();
        }
    }

    LEAVE_FUNC();

	return bResult;
}

void ConsoleShutdownSerial(void)
{
    ENTER_FUNC();

    Connect(80,25);

    FlushSerialBuffer();

    if(pScreenBufferSerial)
        PICE_free(pScreenBufferSerial);

    LEAVE_FUNC();
}

