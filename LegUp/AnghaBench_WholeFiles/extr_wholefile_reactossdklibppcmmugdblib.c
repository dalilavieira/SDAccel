#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int srr1; } ;
typedef  TYPE_1__ ppc_trap_frame_t ;
typedef  scalar_t__ paddr_t ;

/* Variables and functions */
 int ActualCsum ; 
 scalar_t__ BAUDHIGH ; 
 scalar_t__ BAUDLOW ; 
 int ComputedCsum ; 
 int Continue ; 
 size_t DataInAddr ; 
 int* DataInBuffer ; 
 int DataOutAddr ; 
 int* DataOutBuffer ; 
 int DataOutCsum ; 
 int GDB_SAVE_SIZE ; 
 int GetPhysByte (scalar_t__) ; 
 scalar_t__ IER ; 
 scalar_t__ LCR ; 
 scalar_t__ LSR ; 
 scalar_t__ PacketSent ; 
 int ParseState ; 
 scalar_t__ RCV ; 
 TYPE_1__* RegisterSaveArea ; 
 scalar_t__ SendSignal ; 
 int /*<<< orphan*/  SetPhysByte (scalar_t__,int) ; 
 int Signal ; 
 scalar_t__ THR ; 
 int* hex ; 
 char* serport ; 

int isxdigit(int ch)
{
    return
        (ch >= 'A' && ch <= 'F') ||
        (ch >= 'a' && ch <= 'f') ||
        (ch >= '0' && ch <= '9');
}

inline void sync() {
    __asm__("eieio\n\t"
	    "sync");
}

inline void send(char *serport, char c) {
	/* Wait for Clear to Send */
    while( !(GetPhysByte((paddr_t)serport+LSR) & 0x20) ) sync();

    SetPhysByte((paddr_t)serport+THR, c);
    sync();
}

inline int rdy(char *serport)
{
    sync();
    return (GetPhysByte((paddr_t)serport+LSR) & 0x20);
}

inline int chr(char *serport)
{
    sync();
    return GetPhysByte((paddr_t)serport+LSR) & 1;
}

inline char recv(char *serport) {
    char c;

    while( !chr(serport) ) sync();

    c = GetPhysByte((paddr_t)serport+RCV);
    sync();

    return c;
}

void setup(char *serport, int baud) {
	int x = 115200 / baud;
	SetPhysByte((paddr_t)serport+LCR, 128);
	sync();
	SetPhysByte((paddr_t)serport+BAUDLOW, x & 255);
	sync();
	SetPhysByte((paddr_t)serport+BAUDHIGH, x >> 8);
	sync();
	SetPhysByte((paddr_t)serport+LCR, 3);
	sync();
}

void SerialSetUp(int deviceType, void *deviceAddr, int baud)
{
    int i;
    serport = deviceAddr;
    setup(serport, baud);
}

void IntEnable()
{
    SetPhysByte((paddr_t)serport+IER, GetPhysByte((paddr_t)serport+IER) | 1);
}

void SerialWrite(int ch)
{
    send(serport, ch);
}

int SerialRead()
{
    return recv(serport);
}

int hex2int(int ch)
{
    if (ch >= 'a' && ch <= 'f') return ch + 10 - 'a';
    else if (ch >= 'A' && ch <= 'F') return ch + 10 - 'A';
    else return ch - '0';
}

int PacketReadHexNumber(int dig)
{
    int i;
    int result = 0;
    for (i = 0; i < dig && isxdigit(DataInBuffer[DataInAddr]); i++)
    {
        result <<= 4;
        result |= hex2int(DataInBuffer[DataInAddr++]);
    }
    return result;
}

void PacketWriteChar(int ch)
{
    DataOutCsum += ch;
    DataOutBuffer[DataOutAddr++] = ch;
}

int PacketWriteHexNumber(int hnum, int dig)
{
    int i;
    hnum <<= (8 - dig) * 4;
    for (i = 0; i < dig; i++)
    {
        PacketWriteChar(hex[(hnum >> 28) & 15]);
        hnum <<= 4;
    }
    return i;
}

void PacketStart()
{
    DataOutCsum = 0;
    DataOutAddr = 0;
}

void PacketFinish()
{
    int i, ch, count = 0;

    PacketSent = 0;

    SerialWrite('$');
    for (i = 0; i < DataOutAddr; i++)
    {
        SerialWrite(DataOutBuffer[i]);
    }
    SerialWrite('#');
    SerialWrite(hex[(DataOutCsum >> 4) & 15]);
    SerialWrite(hex[DataOutCsum & 15]);

    while(!chr(serport) && ((ch = SerialRead()) != '+') && (ch != '$'));
    if (ch == '$')
    {
        ParseState = 0;
        DataInAddr = 0;
        ComputedCsum = 0;
    }
}

void PacketWriteString(char *str)
{
    while(*str) PacketWriteChar(*str++);
}

void PacketOk()
{
    PacketStart();
    PacketWriteString("OK");
    PacketFinish();
}

void PacketEmpty()
{
    PacketStart();
    PacketFinish();
}

void PacketWriteSignal(int code)
{
    PacketStart();
    PacketWriteChar('S');
    PacketWriteHexNumber(code, 2);
    PacketFinish();
}

void PacketWriteError(int code)
{
    PacketStart();
    PacketWriteChar('E');
    PacketWriteHexNumber(code, 2);
    PacketFinish();
}

void marker() { }

void GotPacket()
{
    int i, memaddr, memsize;

    Continue = 0;
    switch (DataInBuffer[DataInAddr++])
    {
    case 'g':
        PacketStart();
        for (i = 0; i < GDB_SAVE_SIZE; i++)
        {
            PacketWriteHexNumber(((int *)RegisterSaveArea)[i], 8);
        }
        PacketFinish();
        break;

    case 'G':
        for (i = 0; i < sizeof(*RegisterSaveArea) / sizeof(int); i++)
        {
            ((int *)RegisterSaveArea)[i] = PacketReadHexNumber(8);
        }
        PacketOk();
        break;

    case 'm':
        memaddr = PacketReadHexNumber(8);
        DataInAddr++;
        memsize = PacketReadHexNumber(8);
        PacketStart();
        while(memsize-- > 0)
        {
            PacketWriteHexNumber(*((char *)memaddr++), 2);
        }
        PacketFinish();
        break;

    case 'M':
        memaddr = PacketReadHexNumber(8);
        DataInAddr++;
        memsize = PacketReadHexNumber(8);
        DataInAddr++;
        while(memsize-- > 0)
        {
            *((char *)memaddr++) = PacketReadHexNumber(2);
        }
        PacketOk();
        break;

    case '?':
        PacketWriteSignal(Signal);
        break;

    case 'c':
        PacketOk();
        Continue = 1;
        break;

    case 'S':
        PacketOk();
        Continue = 0;
        break;

    case 's':
        RegisterSaveArea->srr1 |= 0x400;
        PacketOk();
        Continue = 1;
        marker();
        break;

    case 'q':
        switch (DataInBuffer[1])
        {
        case 'S': /*upported => nothing*/
            PacketEmpty();
            break;

        case 'O': /*ffsets*/
            PacketEmpty();
            break;
        }
        break;

    default:
        PacketEmpty();
        break;
    }
}

int SerialInterrupt(int signal, ppc_trap_frame_t *tf)
{
    int ch;

    if (!chr(serport)) return 0;

    Signal = signal;
    RegisterSaveArea = tf;

    do
    {
        ch = SerialRead();

        if (ch == 3) /* Break in - tehe */
        {
            Continue = 0;
            PacketWriteSignal(3);
        }
        else if (ch == '+')
        {
            /* Nothing */
        }
        else if (ch == '$')
        {
            DataInAddr = 0;
            ParseState = 0;
            ComputedCsum = 0;
            ActualCsum = 0;
        }
        else if (ch == '#' && ParseState == 0)
        {
            ParseState = 2;
        }
        else if (ParseState == 0)
        {
            ComputedCsum += ch;
            DataInBuffer[DataInAddr++] = ch;
        }
        else if (ParseState == 2)
        {
            ActualCsum = ch;
            ParseState++;
        }
        else if (ParseState == 3)
        {
            ActualCsum = hex2int(ch) | (hex2int(ActualCsum) << 4);
            ComputedCsum &= 255;
            ParseState = -1;
            if (ComputedCsum == ActualCsum)
            {
                ComputedCsum = 0;
                DataInBuffer[DataInAddr] = 0;
                DataInAddr = 0;
                Continue = 0;
                SerialWrite('+');
                GotPacket();
            }
            else
                SerialWrite('-');
        }
        else if (ParseState == -1)
            SerialWrite('-');
    }
    while (!Continue);
    return 1;
}

int TakeException(int n, ppc_trap_frame_t *tf)
{
    Signal = n;
    RegisterSaveArea = tf;
    PacketWriteSignal(Signal);
    SendSignal = 0;
    Continue = 0;
    while(!Continue) SerialInterrupt(n, tf);
    return 1;
}

