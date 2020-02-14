#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {int NumberOfSections; } ;
struct TYPE_15__ {int SymbolsOffset; int StringsOffset; int SymbolsLength; int StringsLength; int SymbolsCount; char* Strings; scalar_t__ Symbols; scalar_t__ PointerToRawData; TYPE_1__ FileHeader; int /*<<< orphan*/  Name; scalar_t__ e_lfanew; } ;
typedef  int /*<<< orphan*/  ROSSYM_INFO ;
typedef  TYPE_2__ ROSSYM_HEADER ;
typedef  int /*<<< orphan*/  ROSSYM_ENTRY ;
typedef  int /*<<< orphan*/  PVOID ;
typedef  TYPE_2__* PROSSYM_INFO ;
typedef  scalar_t__ PROSSYM_ENTRY ;
typedef  TYPE_2__* PIMAGE_SECTION_HEADER ;
typedef  char* PCHAR ;
typedef  int /*<<< orphan*/  IMAGE_SECTION_HEADER ;
typedef  TYPE_2__ IMAGE_NT_HEADERS ;
typedef  TYPE_2__ IMAGE_DOS_HEADER ;
typedef  int /*<<< orphan*/  BOOLEAN ;

/* Variables and functions */
 int /*<<< orphan*/  DPRINT (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DPRINT1 (char*,...) ; 
 int /*<<< orphan*/  FALSE ; 
 scalar_t__ IMAGE_FIRST_SECTION (TYPE_2__*) ; 
 int IMAGE_SIZEOF_SHORT_NAME ; 
 int /*<<< orphan*/  ROSSYM_IS_VALID_DOS_HEADER (TYPE_2__*) ; 
 int /*<<< orphan*/  ROSSYM_IS_VALID_NT_HEADERS (TYPE_2__*) ; 
 int /*<<< orphan*/  ROSSYM_SECTION_NAME ; 
 TYPE_2__* RosSymAllocMem (int) ; 
 int /*<<< orphan*/  RosSymFreeMem (TYPE_2__*) ; 
 int /*<<< orphan*/  RosSymReadFile (int /*<<< orphan*/ ,TYPE_2__*,int) ; 
 int /*<<< orphan*/  RosSymSeekFile (int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ memcmp (char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strncpy (char*,int /*<<< orphan*/ ,int) ; 

BOOLEAN
RosSymCreateFromFile(PVOID FileContext, PROSSYM_INFO *RosSymInfo)
{
  IMAGE_DOS_HEADER DosHeader;
  IMAGE_NT_HEADERS NtHeaders;
  PIMAGE_SECTION_HEADER SectionHeaders, SectionHeader;
  unsigned SectionIndex;
  char SectionName[IMAGE_SIZEOF_SHORT_NAME];
  ROSSYM_HEADER RosSymHeader;

  /* Load DOS header */
  if (! RosSymReadFile(FileContext, &DosHeader, sizeof(IMAGE_DOS_HEADER)))
    {
      DPRINT1("Failed to read DOS header\n");
      return FALSE;
    }
  if (! ROSSYM_IS_VALID_DOS_HEADER(&DosHeader))
    {
      DPRINT1("Image doesn't have a valid DOS header\n");
      return FALSE;
    }

  /* Load NT headers */
  if (! RosSymSeekFile(FileContext, DosHeader.e_lfanew))
    {
      DPRINT1("Failed seeking to NT headers\n");
      return FALSE;
    }
  if (! RosSymReadFile(FileContext, &NtHeaders, sizeof(IMAGE_NT_HEADERS)))
    {
      DPRINT1("Failed to read NT headers\n");
      return FALSE;
    }
  if (! ROSSYM_IS_VALID_NT_HEADERS(&NtHeaders))
    {
      DPRINT1("Image doesn't have a valid PE header\n");
      return FALSE;
    }

  /* Load section headers */
  if (! RosSymSeekFile(FileContext, (char *) IMAGE_FIRST_SECTION(&NtHeaders) -
                                    (char *) &NtHeaders + DosHeader.e_lfanew))
    {
      DPRINT1("Failed seeking to section headers\n");
      return FALSE;
    }
  SectionHeaders = RosSymAllocMem(NtHeaders.FileHeader.NumberOfSections
                                  * sizeof(IMAGE_SECTION_HEADER));
  if (NULL == SectionHeaders)
    {
      DPRINT1("Failed to allocate memory for %u section headers\n",
              NtHeaders.FileHeader.NumberOfSections);
      return FALSE;
    }
  if (! RosSymReadFile(FileContext, SectionHeaders,
                       NtHeaders.FileHeader.NumberOfSections
                       * sizeof(IMAGE_SECTION_HEADER)))
    {
      RosSymFreeMem(SectionHeaders);
      DPRINT1("Failed to read section headers\n");
      return FALSE;
    }

  /* Search for the section header */
  strncpy(SectionName, ROSSYM_SECTION_NAME, IMAGE_SIZEOF_SHORT_NAME);
  SectionHeader = SectionHeaders;
  for (SectionIndex = 0; SectionIndex < NtHeaders.FileHeader.NumberOfSections; SectionIndex++)
    {
      if (0 == memcmp(SectionName, SectionHeader->Name, IMAGE_SIZEOF_SHORT_NAME))
        {
          break;
        }
      SectionHeader++;
    }
  if (NtHeaders.FileHeader.NumberOfSections <= SectionIndex)
    {
      RosSymFreeMem(SectionHeaders);
      DPRINT("No %s section found\n", ROSSYM_SECTION_NAME);
      return FALSE;
    }

  /* Load rossym header */
  if (! RosSymSeekFile(FileContext, SectionHeader->PointerToRawData))
    {
      RosSymFreeMem(SectionHeaders);
      DPRINT1("Failed seeking to section data\n");
      return FALSE;
    }
  RosSymFreeMem(SectionHeaders);
  if (! RosSymReadFile(FileContext, &RosSymHeader, sizeof(ROSSYM_HEADER)))
    {
      DPRINT1("Failed to read rossym header\n");
      return FALSE;
    }
  if (RosSymHeader.SymbolsOffset < sizeof(ROSSYM_HEADER)
      || RosSymHeader.StringsOffset < RosSymHeader.SymbolsOffset + RosSymHeader.SymbolsLength
      || 0 != (RosSymHeader.SymbolsLength % sizeof(ROSSYM_ENTRY)))
    {
      DPRINT1("Invalid ROSSYM_HEADER\n");
      return FALSE;
    }

  *RosSymInfo = RosSymAllocMem(sizeof(ROSSYM_INFO) - sizeof(ROSSYM_HEADER)
                               + RosSymHeader.StringsOffset + RosSymHeader.StringsLength + 1);
  if (NULL == *RosSymInfo)
    {
      DPRINT1("Failed to allocate memory for rossym\n");
      return FALSE;
    }
  (*RosSymInfo)->Symbols = (PROSSYM_ENTRY)((char *) *RosSymInfo + sizeof(ROSSYM_INFO)
                                           - sizeof(ROSSYM_HEADER) + RosSymHeader.SymbolsOffset);
  (*RosSymInfo)->SymbolsCount = RosSymHeader.SymbolsLength / sizeof(ROSSYM_ENTRY);
  (*RosSymInfo)->Strings = (PCHAR) *RosSymInfo + sizeof(ROSSYM_INFO) - sizeof(ROSSYM_HEADER)
                           + RosSymHeader.StringsOffset;
  (*RosSymInfo)->StringsLength = RosSymHeader.StringsLength;
  if (! RosSymReadFile(FileContext, *RosSymInfo + 1,
                       RosSymHeader.StringsOffset + RosSymHeader.StringsLength
                       - sizeof(ROSSYM_HEADER)))
    {
      DPRINT1("Failed to read rossym headers\n");
      return FALSE;
    }
  /* Make sure the last string is null terminated, we allocated an extra byte for that */
  (*RosSymInfo)->Strings[(*RosSymInfo)->StringsLength] = '\0';

  return TRUE;
}

