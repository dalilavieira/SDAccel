#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  int WORD ;
typedef  void* WCHAR ;
typedef  scalar_t__ ULONG_PTR ;
typedef  scalar_t__ ULONG ;
struct TYPE_24__ {int ulVersion; int wPixHeight; int wPixWidth; int wWidthBytes; int wAscent; int wDescent; int wA; int wB; int wC; int cjEntrySize; int /*<<< orphan*/  flInfo; int /*<<< orphan*/ * pCharTable; void* wcBreakChar; void* wcDefaultChar; void* wcLastChar; void* wcFirstChar; scalar_t__ cGlyphs; TYPE_2__* pFontInfo; } ;
struct TYPE_23__ {struct TYPE_23__* type_id; TYPE_1__* nameinfo; TYPE_9__* aface; scalar_t__ cNumFaces; struct TYPE_23__* count; struct TYPE_23__* typeinfo; struct TYPE_23__* size_shift; struct TYPE_23__* ne_rsrctab; struct TYPE_23__* e_lfanew; struct TYPE_23__* e_magic; int /*<<< orphan*/  dfReserved; int /*<<< orphan*/ * dfCharTable; struct TYPE_23__* dfCspace; struct TYPE_23__* dfBspace; struct TYPE_23__* dfAspace; struct TYPE_23__* dfFlags; struct TYPE_23__* dfAscent; struct TYPE_23__* dfWidthBytes; struct TYPE_23__* dfPixWidth; struct TYPE_23__* dfPixHeight; scalar_t__ dfBreakChar; scalar_t__ dfFirstChar; scalar_t__ dfDefaultChar; scalar_t__ dfLastChar; struct TYPE_23__* dfVersion; } ;
struct TYPE_22__ {TYPE_2__* length; TYPE_2__* offset; } ;
typedef  TYPE_2__* PVOID ;
typedef  TYPE_2__* PNE_TYPEINFO ;
typedef  TYPE_2__* PNE_RESTABLE ;
typedef  TYPE_2__* PIMAGE_OS2_HEADER ;
typedef  TYPE_2__* PIMAGE_DOS_HEADER ;
typedef  TYPE_2__* PFONTINFO16 ;
typedef  scalar_t__ PCHAR ;
typedef  TYPE_2__* PBMFD_FILE ;
typedef  TYPE_9__* PBMFD_FACE ;
typedef  int /*<<< orphan*/  NE_TYPEINFO ;
typedef  int /*<<< orphan*/  NE_RESTABLE ;
typedef  int /*<<< orphan*/  IMAGE_OS2_HEADER ;
typedef  int /*<<< orphan*/  IMAGE_DOS_HEADER ;
typedef  int /*<<< orphan*/  GLYPHENTRY30 ;
typedef  int /*<<< orphan*/  GLYPHENTRY20 ;
typedef  int DWORD ;
typedef  scalar_t__ CHAR ;
typedef  void* BOOLEAN ;
typedef  void* BOOL ;
typedef  int /*<<< orphan*/  BMFD_FILE ;
typedef  int /*<<< orphan*/  BMFD_FACE ;

/* Variables and functions */
 int DFF_16COLOR ; 
 int DFF_1COLOR ; 
 int DFF_256COLOR ; 
 int DFF_FIXED ; 
 int DFF_RGBCOLOR ; 
 int /*<<< orphan*/  DbgPrint (char*,...) ; 
 TYPE_2__* EngAllocMem (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EngFreeMem (TYPE_2__*) ; 
 int /*<<< orphan*/  EngMultiByteToUnicodeN (void**,int,scalar_t__*,scalar_t__*,int) ; 
 void* FALSE ; 
 int /*<<< orphan*/  FM_INFO_1BPP ; 
 int /*<<< orphan*/  FM_INFO_24BPP ; 
 int /*<<< orphan*/  FM_INFO_4BPP ; 
 int /*<<< orphan*/  FM_INFO_8BPP ; 
 int /*<<< orphan*/  FM_INFO_CONSTANT_WIDTH ; 
 int /*<<< orphan*/  FM_INFO_MASK ; 
 int GETVAL (TYPE_2__*) ; 
 int IMAGE_DOS_MAGIC ; 
 scalar_t__ NE_RSCTYPE_FONT ; 
 int /*<<< orphan*/  TAG_FONTINFO ; 
 void* TRUE ; 

__attribute__((used)) static
BOOLEAN
IsValidPtr(
    PVOID p,
    ULONG cjSize,
    PVOID pStart,
    PVOID pEnd,
    ULONG cjAlign)
{
    if ((ULONG_PTR)p < (ULONG_PTR)pStart ||
        (ULONG_PTR)p + cjSize >= (ULONG_PTR)pEnd ||
        (ULONG_PTR)p & (cjAlign -1))
    {
        return FALSE;
    }
    return TRUE;
}

__attribute__((used)) static
BOOL
FillFaceInfo(
    PBMFD_FACE pface,
    PFONTINFO16 pFontInfo)
{
    CHAR ansi[4];
    WCHAR unicode[4];
    ULONG written;
    DWORD dfFlags;

    pface->pFontInfo = pFontInfo;
    pface->ulVersion = GETVAL(pFontInfo->dfVersion);
    pface->cGlyphs = pFontInfo->dfLastChar - pFontInfo->dfFirstChar + 1;

    /* Convert chars to unicode */
    ansi[0] = pFontInfo->dfFirstChar;
    ansi[1] = pFontInfo->dfLastChar;
    ansi[2] = pFontInfo->dfFirstChar + pFontInfo->dfDefaultChar;
    ansi[3] = pFontInfo->dfFirstChar + pFontInfo->dfBreakChar;
    EngMultiByteToUnicodeN(unicode, 4 * sizeof(WCHAR), &written, ansi, 4);
    pface->wcFirstChar = unicode[0];
    pface->wcLastChar = unicode[1];
    pface->wcDefaultChar = unicode[2];
    pface->wcBreakChar = unicode[3];

    /* Copy some values */
    pface->wPixHeight = GETVAL(pFontInfo->dfPixHeight);
    pface->wPixWidth = GETVAL(pFontInfo->dfPixWidth);
    pface->wWidthBytes = GETVAL(pFontInfo->dfWidthBytes);
    pface->wAscent = GETVAL(pFontInfo->dfAscent);
    pface->wDescent = pface->wPixHeight - pface->wAscent;

    /* Some version specific members */
    if (pface->ulVersion >= 0x300)
    {
        dfFlags = GETVAL(pFontInfo->dfFlags);
        pface->wA = GETVAL(pFontInfo->dfAspace);
        pface->wB = GETVAL(pFontInfo->dfBspace);
        pface->wC = GETVAL(pFontInfo->dfCspace);
        pface->pCharTable = pFontInfo->dfCharTable;
        pface->cjEntrySize = sizeof(GLYPHENTRY30);
    }
    else
    {
        dfFlags = DFF_1COLOR;
        pface->wA = 0;
        pface->wB = 0;
        pface->wC = 0;
        pface->pCharTable = &pFontInfo->dfReserved + 1;
        pface->cjEntrySize = sizeof(GLYPHENTRY20);
    }

    pface->flInfo = FM_INFO_MASK;

    /* If dfWidth is non-null, we have a fixed width font */
    if (dfFlags & DFF_FIXED || pface->wPixWidth)
        pface->flInfo |= FM_INFO_CONSTANT_WIDTH;

    /* Initialize color depth flags */
    if (dfFlags & DFF_1COLOR)
        pface->flInfo |= FM_INFO_1BPP;
    else if (dfFlags & DFF_16COLOR)
        pface->flInfo |= FM_INFO_4BPP;
    else if (dfFlags & DFF_256COLOR)
        pface->flInfo |= FM_INFO_8BPP;
    else if (dfFlags & DFF_RGBCOLOR)
        pface->flInfo |= FM_INFO_24BPP;

    // TODO: walk through all glyphs and veryfy them and calculate max values

    // FIXME: After this point, the whole font data should be verified!

    return TRUE;
}

__attribute__((used)) static
PVOID
ParseFntFile(
    PVOID pvView,
    ULONG cjView)
{
    /* unimplemented */
    return NULL;
}

__attribute__((used)) static
PVOID
ParseFonFile(
    PVOID pvView,
    ULONG cjView)
{
    PIMAGE_DOS_HEADER pDosHeader = pvView;
    PIMAGE_OS2_HEADER pOs2Header;
    PNE_RESTABLE pResTable;
    PNE_TYPEINFO pTInfo;
    PFONTINFO16 pFontInfo;
    PCHAR pStart, pEnd;
    PBMFD_FILE pfile = NULL;
    WORD wShift;
    ULONG i, cjOffset, cjLength;
    ULONG type_id, count;

    /* Initial margins for valid pointers */
    pStart = pvView;
    pEnd = pStart + cjView;

    /* Check for image dos header */
    if (GETVAL(pDosHeader->e_magic) != IMAGE_DOS_MAGIC)
    {
        return NULL;
    }

    /* Get pointer to OS2 header and veryfy it is valid */
    pOs2Header = (PVOID)((PCHAR)pDosHeader + GETVAL(pDosHeader->e_lfanew));
    pStart += sizeof(IMAGE_DOS_HEADER);
    if (!IsValidPtr(pOs2Header, sizeof(IMAGE_OS2_HEADER), pStart, pEnd, 4))
    {
        DbgPrint("e_lfanew is invalid: 0x%lx\n", pDosHeader->e_lfanew);
        return NULL;
    }

    /* Get pointer to resource table and verify it is valid */
    pResTable = (PVOID)((PCHAR)pOs2Header + GETVAL(pOs2Header->ne_rsrctab));
    pStart = (PCHAR)pOs2Header;
    if (!IsValidPtr(pResTable, sizeof(NE_RESTABLE), pStart, pEnd, 1))
    {
        DbgPrint("pTInfo is invalid: 0x%p\n", pResTable);
        return NULL;
    }

    wShift = GETVAL(pResTable->size_shift);
    pTInfo = pResTable->typeinfo;
    type_id = GETVAL(pTInfo->type_id);

    /* Loop the resource table to find a font resource */
    while (type_id)
    {
        /* Get number of nameinfo entries */
        count = GETVAL(pTInfo->count);

        /* Look for a font resource */
        if (type_id == NE_RSCTYPE_FONT && count > 0)
        {
            DbgPrint("Found NE_RSCTYPE_FONT\n");

            /* Allocate an info structure for this font and all faces */
            cjLength = sizeof(BMFD_FILE) + (count-1) * sizeof(BMFD_FACE);
            pfile = EngAllocMem(0, cjLength, TAG_FONTINFO);
            if (!pfile)
            {
                DbgPrint("Not enough memory: %ld\n", cjLength);
                return NULL;
            }

            pfile->cNumFaces = count;

            /* Fill all face info structures */
            for (i = 0; i < count; i++)
            {
                cjOffset = GETVAL(pTInfo->nameinfo[i].offset) << wShift;
                cjLength = GETVAL(pTInfo->nameinfo[i].length) << wShift;
                pFontInfo = (PVOID)((PCHAR)pDosHeader + cjOffset);

                if (!IsValidPtr(pFontInfo, cjLength, pStart, pEnd, 1))
                {
                    DbgPrint("pFontInfo is invalid: 0x%p\n", pFontInfo);
                    EngFreeMem(pfile);
                    return NULL;
                }

                /* Validate FONTINFO and fill face info */
                if (!FillFaceInfo(&pfile->aface[i], pFontInfo))
                {
                    DbgPrint("pFontInfo is invalid: 0x%p\n", pFontInfo);
                    EngFreeMem(pfile);
                    return NULL;
                }
            }

            /* Break out of the loop */
            break;
        }

        /* Following pointers must be bigger than this */
        pStart = (PCHAR)pTInfo;

        /* Goto next entry in resource table */
        pTInfo = (PVOID)&pTInfo->nameinfo[count];

        /* Verify that the new pTInfo pointer is valid */
        if (!IsValidPtr(pTInfo, sizeof(NE_TYPEINFO), pStart, pEnd, 1))
        {
            DbgPrint("pTInfo is invalid: 0x%p\n", pTInfo);
            return NULL;
        }

        type_id = GETVAL(pTInfo->type_id);
    }

    return pfile;
}

