#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {TYPE_1__* aDown; scalar_t__ MaxNumDownBuffers; TYPE_2__* aUp; scalar_t__ MaxNumUpBuffers; } ;
struct TYPE_5__ {int Flags; int RdOff; int WrOff; int SizeOfBuffer; char* pBuffer; char const* sName; } ;
struct TYPE_4__ {int RdOff; int WrOff; int SizeOfBuffer; char const* pBuffer; char const* sName; int Flags; } ;

/* Variables and functions */
 int /*<<< orphan*/  MEMCPY (char*,char const*,int) ; 
 int MIN (int,int) ; 
 int /*<<< orphan*/  SEGGER_RTT_LOCK () ; 
 int SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL ; 
 int SEGGER_RTT_MODE_MASK ; 
 int SEGGER_RTT_MODE_NO_BLOCK_SKIP ; 
 int /*<<< orphan*/  SEGGER_RTT_UNLOCK () ; 
 int _ActiveTerminal ; 
 TYPE_3__ _SEGGER_RTT ; 

__attribute__((used)) static int _strlen(const char* s) {
  int Len;

  Len = 0;
  if (s == NULL) {
    return 0;
  }
  do {
    if (*s == 0) {
      break;
    }
    Len++;
    s++;
  } while (1);
  return Len;
}

__attribute__((used)) static void _Init(void) {
#if SEGGER_RTT_IN_RAM
  if (_SEGGER_RTT.acID[10] == 'I') {
    _SEGGER_RTT.acID[10] = '\0';
  }
#endif
}

int SEGGER_RTT_Read(unsigned BufferIndex, char* pBuffer, unsigned BufferSize) {
  int NumBytesRem;
  unsigned NumBytesRead;
  int RdOff;
  int WrOff;

  SEGGER_RTT_LOCK();
  _Init();
  RdOff = _SEGGER_RTT.aDown[BufferIndex].RdOff;
  WrOff = _SEGGER_RTT.aDown[BufferIndex].WrOff;
  NumBytesRead = 0;
  //
  // Read from current read position to wrap-around of buffer, first
  //
  if (RdOff > WrOff) {
    NumBytesRem = _SEGGER_RTT.aDown[BufferIndex].SizeOfBuffer - RdOff;
    NumBytesRem = MIN(NumBytesRem, (int)BufferSize);
    MEMCPY(pBuffer, _SEGGER_RTT.aDown[BufferIndex].pBuffer + RdOff, NumBytesRem);
    NumBytesRead += NumBytesRem;
    pBuffer      += NumBytesRem;
    BufferSize   -= NumBytesRem;
    RdOff        += NumBytesRem;
    //
    // Handle wrap-around of buffer
    //
    if (RdOff == _SEGGER_RTT.aDown[BufferIndex].SizeOfBuffer) {
      RdOff = 0;
    }
  }
  //
  // Read remaining items of buffer
  //
  NumBytesRem = WrOff - RdOff;
  NumBytesRem = MIN(NumBytesRem, (int)BufferSize);
  if (NumBytesRem > 0) {
    MEMCPY(pBuffer, _SEGGER_RTT.aDown[BufferIndex].pBuffer + RdOff, NumBytesRem);
    NumBytesRead += NumBytesRem;
    pBuffer      += NumBytesRem;
    BufferSize   -= NumBytesRem;
    RdOff        += NumBytesRem;
  }
  if (NumBytesRead) {
    _SEGGER_RTT.aDown[BufferIndex].RdOff = RdOff;
  }
  SEGGER_RTT_UNLOCK();
  return NumBytesRead;
}

int SEGGER_RTT_Write(unsigned BufferIndex, const char* pBuffer, unsigned NumBytes) {
  int NumBytesToWrite;
  unsigned NumBytesWritten;
  int RdOff;
  //
  // Target is not allowed to perform other RTT operations while string still has not been stored completely.
  // Otherwise we would probably end up with a mixed string in the buffer.
  //
  SEGGER_RTT_LOCK();
  _Init();
  //
  // In case we are not in blocking mode,
  // we need to calculate, how many bytes we can put into the buffer at all.
  //
  if ((_SEGGER_RTT.aUp[BufferIndex].Flags & SEGGER_RTT_MODE_MASK) != SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL) {
    RdOff = _SEGGER_RTT.aUp[BufferIndex].RdOff;
    NumBytesToWrite =  RdOff - _SEGGER_RTT.aUp[BufferIndex].WrOff - 1;
    if (NumBytesToWrite < 0) {
      NumBytesToWrite += _SEGGER_RTT.aUp[BufferIndex].SizeOfBuffer;
    }
    //
    // If the complete data does not fit in the buffer, check if we have to skip it completely or trim the data
    //
    if ((int)NumBytes > NumBytesToWrite) {
      if ((_SEGGER_RTT.aUp[BufferIndex].Flags & SEGGER_RTT_MODE_MASK) == SEGGER_RTT_MODE_NO_BLOCK_SKIP) {
        SEGGER_RTT_UNLOCK();
        return 0;
      } else {
        NumBytes = NumBytesToWrite;
      }
    }
  }
  //
  // Early out if nothing is to do
  //
  if (NumBytes == 0) {
    SEGGER_RTT_UNLOCK();
    return 0;
  }
  //
  // Write data to buffer and handle wrap-around if necessary
  //
  NumBytesWritten = 0;
  do {
    RdOff = _SEGGER_RTT.aUp[BufferIndex].RdOff;                          // May be changed by host (debug probe) in the meantime
    NumBytesToWrite = RdOff - _SEGGER_RTT.aUp[BufferIndex].WrOff - 1;
    if (NumBytesToWrite < 0) {
      NumBytesToWrite += _SEGGER_RTT.aUp[BufferIndex].SizeOfBuffer;
    }
    NumBytesToWrite = MIN(NumBytesToWrite, (_SEGGER_RTT.aUp[BufferIndex].SizeOfBuffer - _SEGGER_RTT.aUp[BufferIndex].WrOff));    // Number of bytes that can be written until buffer wrap-around
    NumBytesToWrite = MIN(NumBytesToWrite, (int)NumBytes);
    MEMCPY(_SEGGER_RTT.aUp[BufferIndex].pBuffer + _SEGGER_RTT.aUp[BufferIndex].WrOff, pBuffer, NumBytesToWrite);
    NumBytesWritten     += NumBytesToWrite;
    pBuffer             += NumBytesToWrite;
    NumBytes            -= NumBytesToWrite;
    _SEGGER_RTT.aUp[BufferIndex].WrOff += NumBytesToWrite;
    if (_SEGGER_RTT.aUp[BufferIndex].WrOff == _SEGGER_RTT.aUp[BufferIndex].SizeOfBuffer) {
      _SEGGER_RTT.aUp[BufferIndex].WrOff = 0;
    }
  } while (NumBytes);
  SEGGER_RTT_UNLOCK();
  return NumBytesWritten;
}

int SEGGER_RTT_WriteString(unsigned BufferIndex, const char* s) {
  int Len;

  Len = _strlen(s);
  return SEGGER_RTT_Write(BufferIndex, s, Len);
}

int SEGGER_RTT_GetKey(void) {
  char c;
  int r;

  r = SEGGER_RTT_Read(0, &c, 1);
  if (r == 1) {
    return (int)(unsigned char)c;
  }
  return -1;
}

int SEGGER_RTT_WaitKey(void) {
  int r;

  do {
    r = SEGGER_RTT_GetKey();
  } while (r < 0);
  return r;
}

int SEGGER_RTT_HasKey(void) {
  int RdOff;

  _Init();
  RdOff = _SEGGER_RTT.aDown[0].RdOff;
  if (RdOff != _SEGGER_RTT.aDown[0].WrOff) {
    return 1;
  }
  return 0;
}

int SEGGER_RTT_ConfigUpBuffer(unsigned BufferIndex, const char* sName, char* pBuffer, int BufferSize, int Flags) {
  _Init();
  if (BufferIndex < (unsigned)_SEGGER_RTT.MaxNumUpBuffers) {
    SEGGER_RTT_LOCK();
    if (BufferIndex > 0) {
      _SEGGER_RTT.aUp[BufferIndex].sName        = sName;
      _SEGGER_RTT.aUp[BufferIndex].pBuffer      = pBuffer;
      _SEGGER_RTT.aUp[BufferIndex].SizeOfBuffer = BufferSize;
      _SEGGER_RTT.aUp[BufferIndex].RdOff        = 0;
      _SEGGER_RTT.aUp[BufferIndex].WrOff        = 0;
    }
    _SEGGER_RTT.aUp[BufferIndex].Flags          = Flags;
    SEGGER_RTT_UNLOCK();
    return 0;
  }
  return -1;
}

int SEGGER_RTT_ConfigDownBuffer(unsigned BufferIndex, const char* sName, char* pBuffer, int BufferSize, int Flags) {
  _Init();
  if (BufferIndex < (unsigned)_SEGGER_RTT.MaxNumDownBuffers) {
    SEGGER_RTT_LOCK();
    if (BufferIndex > 0) {
      _SEGGER_RTT.aDown[BufferIndex].sName        = sName;
      _SEGGER_RTT.aDown[BufferIndex].pBuffer      = pBuffer;
      _SEGGER_RTT.aDown[BufferIndex].SizeOfBuffer = BufferSize;
      _SEGGER_RTT.aDown[BufferIndex].RdOff        = 0;
      _SEGGER_RTT.aDown[BufferIndex].WrOff        = 0;
    }
    _SEGGER_RTT.aDown[BufferIndex].Flags          = Flags;
    SEGGER_RTT_UNLOCK();
    return 0;
  }
  return -1;
}

void SEGGER_RTT_Init (void) {
  _Init();
}

void SEGGER_RTT_SetTerminal (char TerminalId) {
  char ac[2];

  ac[0] = 0xFF;
  if (TerminalId < 10) {
    ac[1] = '0' + TerminalId;
  } else if (TerminalId < 16) {
    ac[1] = 'A' + (TerminalId - 0x0A);
  } else {
    return; // RTT only supports up to 16 virtual terminals.
  }
  _ActiveTerminal = TerminalId;
  SEGGER_RTT_Write(0, ac, 2);
}

int SEGGER_RTT_TerminalOut (char TerminalId, const char* s) {
  char ac[2];
  int  r;

  ac[0] = 0xFF;
  if (TerminalId < 10) {
    ac[1] = '0' + TerminalId;
  } else if (TerminalId < 16) {
    ac[1] = 'A' + (TerminalId - 0x0A);
  } else {
    return -1; // RTT only supports up to 16 virtual terminals.
  }
  SEGGER_RTT_Write(0, ac, 2);
  r = SEGGER_RTT_WriteString(0, s);
  if (TerminalId < 10) {
    ac[1] = '0' + _ActiveTerminal;
  } else if (TerminalId < 16) {
    ac[1] = 'A' + (_ActiveTerminal - 0x0A);
  }
  SEGGER_RTT_Write(0, ac, 2);
  return r;
}

