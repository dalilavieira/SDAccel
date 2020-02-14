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
typedef  int /*<<< orphan*/  VOID ;
typedef  int ULONG ;
typedef  int BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (char*,...) ; 
 int FALSE ; 
 int SB_DISABLE_SPEAKER ; 
 int SB_ENABLE_SPEAKER ; 
 int SB_GET_SPEAKER_STATUS ; 
 int SB_READ_DATA (int) ; 
 int SB_SET_OUTPUT_RATE ; 
 int /*<<< orphan*/  SB_WRITE_BYTE (int,int) ; 
 int /*<<< orphan*/  WaitToReceive (int) ; 

VOID SetOutputSampleRate(ULONG BasePort, ULONG SampleRate)
{
    // This only works for DSP v4.xx ONLY - need a workaround!
    DPRINT("Setting output sample rate\n");

    // WAIT
//    if (! WaitToSend(BasePort))
//        return;

    SB_WRITE_BYTE(BasePort, SB_SET_OUTPUT_RATE);
    SB_WRITE_BYTE(BasePort, SampleRate / 256);  // high
    SB_WRITE_BYTE(BasePort, SampleRate % 256);  // low
}

VOID EnableSpeaker(ULONG BasePort, BOOLEAN SpeakerOn)
{
    DPRINT("Setting speaker status %d\n", SpeakerOn);

//    if (! WaitForWrite(BasePort))
//        return;

    SB_WRITE_BYTE(BasePort, SpeakerOn ? SB_ENABLE_SPEAKER : SB_DISABLE_SPEAKER);
}

BOOLEAN IsSpeakerEnabled(ULONG BasePort)
{
    DPRINT("Obtaining speaker status\n");

//    if (! WaitToSend(BasePort))
//        return FALSE;

    SB_WRITE_BYTE(BasePort, SB_GET_SPEAKER_STATUS);
    if (! WaitToReceive(BasePort))
        return FALSE;

    return SB_READ_DATA(BasePort) == 0xff;
}

VOID BeginPlayback(ULONG BasePort, ULONG BitDepth, ULONG Channels, ULONG BlockSize)
{
    DPRINT("BeginPlayback(%d, %d, %d, %d)\n", BasePort, BitDepth, Channels, BlockSize);

//    switch(BitDepth)
//    {
//        case 8 :    Command = 0xc0; break;
//        case 16 :   Command = 0xb0; break;  // Make sure we support it
//        default :   Command = 0xc0;
//    }

    DPRINT("Initiating playback\n");

    // TEMPORARY:
    SB_WRITE_BYTE(BasePort, 0xc6);
    SB_WRITE_BYTE(BasePort, 0); // mode - TEMPORARY
    SB_WRITE_BYTE(BasePort, BlockSize % 256);
    SB_WRITE_BYTE(BasePort, BlockSize / 256);
}

