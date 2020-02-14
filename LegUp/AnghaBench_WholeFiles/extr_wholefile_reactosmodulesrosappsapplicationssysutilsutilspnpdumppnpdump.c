#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_22__   TYPE_8__ ;
typedef  struct TYPE_21__   TYPE_7__ ;
typedef  struct TYPE_20__   TYPE_6__ ;
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  unsigned char USHORT ;
typedef  scalar_t__ ULONG_PTR ;
typedef  unsigned char ULONG ;
typedef  int UCHAR ;
struct TYPE_18__ {scalar_t__ Count; TYPE_3__* PartialDescriptors; } ;
struct TYPE_22__ {TYPE_4__ PartialResourceList; } ;
struct TYPE_21__ {int Node; int Size; int /*<<< orphan*/  ProductId; } ;
struct TYPE_20__ {char* Signature; } ;
struct TYPE_19__ {char* PnpId; char* DeviceName; } ;
struct TYPE_15__ {int DataSize; } ;
struct TYPE_16__ {TYPE_1__ DeviceSpecificData; } ;
struct TYPE_17__ {TYPE_2__ u; } ;
typedef  TYPE_5__* PPNP_ID_NAME ;
typedef  scalar_t__* PHKEY ;
typedef  TYPE_6__* PCM_PNP_BIOS_INSTALLATION_CHECK ;
typedef  TYPE_7__* PCM_PNP_BIOS_DEVICE_NODE ;
typedef  TYPE_8__* PCM_FULL_RESOURCE_DESCRIPTOR ;
typedef  int /*<<< orphan*/  PCHAR ;
typedef  int /*<<< orphan*/  LPBYTE ;
typedef  scalar_t__ LONG ;
typedef  scalar_t__ HKEY ;
typedef  int DWORD ;
typedef  int /*<<< orphan*/  CM_PNP_BIOS_INSTALLATION_CHECK ;
typedef  int /*<<< orphan*/  CM_PNP_BIOS_DEVICE_NODE ;
typedef  int /*<<< orphan*/  CM_PARTIAL_RESOURCE_DESCRIPTOR ;
typedef  scalar_t__ BOOL ;

/* Variables and functions */
 scalar_t__ ERROR_MORE_DATA ; 
 scalar_t__ ERROR_SUCCESS ; 
 scalar_t__ FALSE ; 
 scalar_t__ HKEY_LOCAL_MACHINE ; 
 char* Hex ; 
 TYPE_5__* PnpName ; 
 int REG_SZ ; 
 int /*<<< orphan*/  RegCloseKey (scalar_t__) ; 
 scalar_t__ RegOpenKey (scalar_t__,char*,scalar_t__*) ; 
 scalar_t__ RegQueryValueEx (scalar_t__,char*,int /*<<< orphan*/ *,int*,int /*<<< orphan*/ ,int*) ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  free (TYPE_8__*) ; 
 int /*<<< orphan*/  getch () ; 
 TYPE_8__* malloc (int) ; 
 int /*<<< orphan*/  memcpy (unsigned char*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 TYPE_8__* realloc (TYPE_8__*,int) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 scalar_t__ stricmp (char*,char*) ; 
 scalar_t__ strncmp (int /*<<< orphan*/ ,char*,int) ; 

__attribute__((used)) static char *
GetDeviceName(char *PnpId)
{
  PPNP_ID_NAME IdName;

  IdName = PnpName;
  while (IdName->PnpId != NULL)
    {
      if (!strcmp(IdName->PnpId, PnpId))
	return IdName->DeviceName;

      IdName++;
    }

  return "Unknown Device";
}

LONG
GetPnpKey(PHKEY PnpKey)
{
  LONG lError;
  char szBuffer[80];
  HKEY hAdapterKey;
  HKEY hBusKey;
  DWORD dwBus;
  DWORD dwType;
  DWORD dwSize;

  *PnpKey = 0;

  lError = RegOpenKey(HKEY_LOCAL_MACHINE,
		      "HARDWARE\\DESCRIPTION\\System\\MultifunctionAdapter",
		      &hAdapterKey);
  if (lError != ERROR_SUCCESS)
    return 0;

  /* Enumerate buses */
  for (dwBus = 0; ; dwBus++)
    {
      sprintf(szBuffer, "%lu", dwBus);

      lError = RegOpenKey(hAdapterKey,
			  szBuffer,
			  &hBusKey);
      if (lError != ERROR_SUCCESS)
	{
	  RegCloseKey(hAdapterKey);
	  return lError;
	}

      dwSize = 80;
      lError = RegQueryValueEx(hBusKey,
			       "Identifier",
			       NULL,
			       &dwType,
			       (LPBYTE)szBuffer,
			       &dwSize);
      if (lError != ERROR_SUCCESS)
	{
	  RegCloseKey(hBusKey);
	  RegCloseKey(hAdapterKey);
	  return lError;
	}

      if (dwType == REG_SZ && stricmp(szBuffer, "pnp bios") == 0)
	{
	  *PnpKey = hBusKey;
	  RegCloseKey(hAdapterKey);
	  return ERROR_SUCCESS;
	}

      RegCloseKey(hBusKey);
    }

  return 1;
}

__attribute__((used)) static VOID
PnpDecodeIrq(unsigned char *Ptr)
{
  USHORT IrqMask;
  int i;

  IrqMask = *Ptr;
  Ptr++;
  IrqMask |= (*Ptr << 8);

  printf("      IRQs:");

  for (i = 0; i < 16; i++)
    {
      if (IrqMask & (1 << i))
	{
	  printf(" %u", i);
	}
    }

  printf("\n");
}

__attribute__((used)) static VOID
PnpDecodeDma(unsigned char *Ptr)
{
  unsigned char DmaChannel;
  unsigned char DmaStatus;
  int i;

  DmaChannel = *Ptr;
  Ptr++;
  DmaStatus = *Ptr;

  printf("      DMAs:");

  for (i = 0; i < 8; i++)
    {
      if (DmaChannel & (1 << i))
	{
	  printf(" %u", i);
	}
    }

  printf("\n");
}

__attribute__((used)) static VOID
PnpDecodeIoPort(unsigned char *Ptr)
{
  USHORT MinBase;
  USHORT MaxBase;
  UCHAR Align;
  UCHAR Length;

  // Info = *Ptr;
  Ptr++;
  MinBase = *Ptr;
  Ptr++;
  MinBase += (*Ptr << 8);
  Ptr++;
  MaxBase = *Ptr;
  Ptr++;
  MaxBase += (*Ptr << 8);
  Ptr++;
  Align = *Ptr;
  Ptr++;
  Length = *Ptr;

  printf("  I/O Port descriptor\n");
  printf("    MinBase 0x%x  MaxBase 0x%x  Align %u  Length %u\n",
	 MinBase, MaxBase, Align, Length);
}

__attribute__((used)) static VOID
PnpDecodeFixedIoPort(unsigned char *Ptr)
{
  USHORT IoPort;
  UCHAR Length;

  IoPort = *Ptr;
  Ptr++;
  IoPort += (*Ptr << 8);
  Ptr++;
  Length = *Ptr;

  printf("  Fixed I/O Port descriptor\n");
  printf("    PortBase 0x%hx  Length 0x%x\n",
	 IoPort, Length);

#if 0
  if (Length == 1)
    {
      printf("  Fixed location I/O Port descriptor: 0x%x\n",
	     IoPort);
    }
  else
    {
      printf("  Fixed location I/O Port descriptor: 0x%x - 0x%x\n",
	     IoPort,
	     IoPort + Length - 1);
    }
#endif
}

__attribute__((used)) static VOID
PnpDecodeMemory16(unsigned char *Ptr)
{
  UCHAR Info;
  USHORT MinBase;
  USHORT MaxBase;
  USHORT Align;
  USHORT Length;

  Info = *Ptr;
  Ptr++;

  MinBase = *Ptr;
  Ptr++;
  MinBase += (*Ptr << 8);
  Ptr++;

  MaxBase = *Ptr;
  Ptr++;
  MaxBase += (*Ptr << 8);
  Ptr++;

  Align = *Ptr;
  Ptr++;
  Align += (*Ptr << 8);
  Ptr++;

  Length = *Ptr;
  Ptr++;
  Length += (*Ptr << 8);

  printf("  16-Bit memory range descriptor\n");
  printf("    MinBase 0x%hx  MaxBase 0x%hx  Align 0x%hx  Length 0x%hx  Flags 0x%02x\n",
	 MinBase, MaxBase, Align,Length, Info);
}

__attribute__((used)) static VOID
PnpDecodeMemory32(unsigned char *Ptr)
{
  UCHAR Info;
  ULONG MinBase;
  ULONG MaxBase;
  ULONG Align;
  ULONG Length;

  Info = *Ptr;
  Ptr++;

  MinBase = *Ptr;
  Ptr++;
  MinBase += (*Ptr << 8);
  Ptr++;
  MinBase += (*Ptr << 16);
  Ptr++;
  MinBase += (*Ptr << 24);
  Ptr++;

  MaxBase = *Ptr;
  Ptr++;
  MaxBase += (*Ptr << 8);
  Ptr++;
  MaxBase += (*Ptr << 16);
  Ptr++;
  MaxBase += (*Ptr << 24);
  Ptr++;

  Align = *Ptr;
  Ptr++;
  Align += (*Ptr << 8);
  Ptr++;
  Align += (*Ptr << 16);
  Ptr++;
  Align += (*Ptr << 24);
  Ptr++;

  Length = *Ptr;
  Ptr++;
  Length += (*Ptr << 8);
  Ptr++;
  Length += (*Ptr << 16);
  Ptr++;
  Length += (*Ptr << 24);

  printf("  32-Bit memory range descriptor\n");
  printf("    MinBase 0x%lx  MaxBase 0x%lx  Align 0x%lx  Length 0x%lx  Flags 0x%02x\n",
	 MinBase, MaxBase, Align,Length, Info);
}

__attribute__((used)) static VOID
PnpDecodeFixedMemory(unsigned char *Ptr)
{
  UCHAR Info;
  ULONG Base;
  ULONG Length;

  Info = *Ptr;
  Ptr++;

  Base = *Ptr;
  Ptr++;
  Base += (*Ptr << 8);
  Ptr++;
  Base += (*Ptr << 16);
  Ptr++;
  Base += (*Ptr << 24);
  Ptr++;

  Length = *Ptr;
  Ptr++;
  Length += (*Ptr << 8);
  Ptr++;
  Length += (*Ptr << 16);
  Ptr++;
  Length += (*Ptr << 24);

  printf("  32-Bit fixed location memory range descriptor\n");
  printf("    Base 0x%lx  Length 0x%lx  Flags 0x%02x\n",
	 Base, Length, Info);
}

void PrintDeviceData (PCM_PNP_BIOS_DEVICE_NODE DeviceNode)
{
  char PnpId[8];
  unsigned char *Ptr;
  unsigned int TagSize;
  unsigned int TagType;

  unsigned char Id[4];

  printf ("Node: %x  Size %hu (0x%hx)\n",
	  DeviceNode->Node,
	  DeviceNode->Size,
	  DeviceNode->Size);

  memcpy(Id, &DeviceNode->ProductId, 4);

  PnpId[0] = ((Id[0] >> 2) & 0x1F) + 0x40;
  PnpId[1] = ((Id[0] << 3) & 0x18) +
	     ((Id[1] >> 5) & 0x07) + 0x40;
  PnpId[2] = (Id[1] & 0x1F) + 0x40;

  PnpId[3] = Hex[(Id[2] >> 4) & 0xF];
  PnpId[4] = Hex[Id[2] & 0x0F];

  PnpId[5] = Hex[(Id[3] >> 4) & 0x0F];
  PnpId[6] = Hex[Id[3] & 0x0F];
  PnpId[7] = 0;

  printf("  '%s' (%s)\n",
	 PnpId, GetDeviceName(PnpId));

  if (DeviceNode->Size > sizeof(CM_PNP_BIOS_DEVICE_NODE))
    {
      Ptr = (unsigned char *)(DeviceNode + 1);
      while (TRUE)
	{
	  if (*Ptr & 0x80)
	    {
	      TagType = *Ptr & 0x7F;
	      Ptr++;
	      TagSize = *Ptr;
	      Ptr++;
	      TagSize += (*Ptr << 16);
	      Ptr++;


	      switch (TagType)
		{
		  case 1:
		    PnpDecodeMemory16(Ptr);
		    break;

		  case 5:
		    PnpDecodeMemory32(Ptr);
		    break;

		  case 6:
		    PnpDecodeFixedMemory(Ptr);
		    break;

		  default:
		    printf("      Large tag: type %u  size %u\n",
			   TagType,
			   TagSize);
		    break;
		}
	    }
	  else
	    {
	      TagType = (*Ptr >> 3) & 0x0F;
	      TagSize = *Ptr & 0x07;
	      Ptr++;

	      switch (TagType)
		{
		  case 2:
		    printf("      Logical device ID\n");
		    break;

		  case 3:
		    printf("      Compatible device ID\n");
		    break;

		  case 4:
		    PnpDecodeIrq(Ptr);
		    break;

		  case 5:
		    PnpDecodeDma(Ptr);
		    break;

		  case 8:
		    PnpDecodeIoPort(Ptr);
		    break;

		  case 9:
		    PnpDecodeFixedIoPort(Ptr);
		    break;

		  case 0x0F: /* end tag */
		    break;

		  default:
		    printf("      Small tag: type %u  size %u\n",
			   TagType,
			   TagSize);
		    break;
		}

	      /* end tag */
	      if (TagType == 0x0F)
		break;
	    }

	  Ptr = Ptr + TagSize;
	}
    }
}

int main (int argc, char *argv[])
{
  LONG lError;
  HKEY hPnpKey;
  DWORD dwType;
  DWORD dwSize;
  BOOL Ask;
  PCM_FULL_RESOURCE_DESCRIPTOR lpBuffer;
  PCM_PNP_BIOS_INSTALLATION_CHECK lpPnpInst;
  PCM_PNP_BIOS_DEVICE_NODE lpDevNode;
  DWORD dwDataSize;
  DWORD dwResourceSize;

  hPnpKey = 0;

  Ask = TRUE;
  if (argc >1 && (!strcmp(argv[1],"/S") || !strcmp(argv[1],"/s")))
    {
      Ask = FALSE;
    }

  if (argc >1 && !strcmp(argv[1],"/?"))
    {
      printf("This utility prints the PnP-nodes from the registry\n");
      printf("\"/s\" prevents the \"Press any key\"\n\n");
      return 0;
    }

  lError = GetPnpKey(&hPnpKey);
  if (lError != ERROR_SUCCESS)
    {
      printf("Failed to get PnP-BIOS key\n");
      return 0;
    }

  if (hPnpKey != 0)
    {
      printf("Found PnP-BIOS key\n");
    }

  /* Allocate buffer */
  dwSize = 2048;
  lpBuffer = malloc(dwSize);
  if (lpBuffer == NULL)
    {
      printf("Error: malloc() failed\n");
      RegCloseKey(hPnpKey);
      return 0;
    }

  do
    {
      lError = RegQueryValueEx(hPnpKey,
			       "Configuration Data",
			       NULL,
			       &dwType,
			       (LPBYTE)lpBuffer,
			       &dwSize);
      if (lError == ERROR_MORE_DATA)
        {
          lpBuffer = realloc(lpBuffer, dwSize);
          if (lpBuffer == NULL)
            {
              printf("Error: realloc() of %u bytes failed\n", (unsigned) dwSize);
              RegCloseKey(hPnpKey);
              return 0;
            }
        }
    }
  while (lError == ERROR_MORE_DATA);
  if (lError != ERROR_SUCCESS)
    {
      printf("Failed to read 'Configuration Data' value\n");
      free(lpBuffer);
      RegCloseKey(hPnpKey);
      return 0;
    }

//  printf ("Data size: %lu\n", dwSize);

  RegCloseKey(hPnpKey);

//  printf("Resource count %lu\n", lpBuffer->PartialResourceList.Count);

  if (lpBuffer->PartialResourceList.Count == 0)
    {
      printf("Invalid resource count!\n");
      free(lpBuffer);
      return 0;
    }

//  printf("lpBuffer %p\n", lpBuffer);

  dwResourceSize = lpBuffer->PartialResourceList.PartialDescriptors[0].u.DeviceSpecificData.DataSize;
//  printf("ResourceSize: %lu\n", dwResourceSize);

  lpPnpInst = (PCM_PNP_BIOS_INSTALLATION_CHECK)
	((ULONG_PTR)(&lpBuffer->PartialResourceList.PartialDescriptors[0]) +
	  sizeof(CM_PARTIAL_RESOURCE_DESCRIPTOR));

//  printf("lpPnpInst %p\n", lpPnpInst);

  printf("Signature '%.4s'\n", lpPnpInst->Signature);
  if (strncmp((PCHAR)lpPnpInst->Signature, "$PnP", 4))
    {
      printf("Error: Invalid PnP signature\n");
      free(lpBuffer);
      return 0;
    }

//  printf("InstCheck length: %lu\n", lpPnpInst->Length);

  dwDataSize = sizeof(CM_PNP_BIOS_INSTALLATION_CHECK);
  lpDevNode = (PCM_PNP_BIOS_DEVICE_NODE)((DWORD)lpPnpInst + sizeof(CM_PNP_BIOS_INSTALLATION_CHECK));

  if (lpDevNode->Size == 0)
    {
      printf("Error: Device node size is zero!\n");
      return 0;
    }

#if 0
      printf("Node: %x  Size %hu (0x%hx)\n",
	      lpDevNode->Node,
	      lpDevNode->Size,
	      lpDevNode->Size);

  printf("Done.\n");
return 0;
#endif


  while (dwDataSize < dwResourceSize)
    {
      if (lpDevNode->Size == 0)
	break;

      printf("Node: %x  Size %hu (0x%hx)\n",
	     lpDevNode->Node,
	     lpDevNode->Size,
	     lpDevNode->Size);

      dwDataSize += lpDevNode->Size;
      lpDevNode = (PCM_PNP_BIOS_DEVICE_NODE)((DWORD)lpDevNode + lpDevNode->Size);
    }

  if (Ask)
    {
      printf("\n Press any key...\n");
      getch();
    }
  else
    {
      printf("\n");
    }

  dwDataSize = sizeof(CM_PNP_BIOS_INSTALLATION_CHECK);
  lpDevNode = (PCM_PNP_BIOS_DEVICE_NODE)((DWORD)lpPnpInst + sizeof(CM_PNP_BIOS_INSTALLATION_CHECK));

  while (dwDataSize < dwResourceSize)
    {
      if (lpDevNode->Size == 0)
	break;

      PrintDeviceData(lpDevNode);

      if (Ask)
        {
          printf("\n Press any key...\n");
          getch();
        }
      else
        {
          printf("\n");
        }

      dwDataSize += lpDevNode->Size;
      lpDevNode = (PCM_PNP_BIOS_DEVICE_NODE)((DWORD)lpDevNode + lpDevNode->Size);
    }

  free(lpBuffer);

  return 0;
}

