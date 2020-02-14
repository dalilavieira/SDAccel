#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_7__ ;
typedef  struct TYPE_18__   TYPE_5__ ;
typedef  struct TYPE_17__   TYPE_4__ ;
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  VOID ;
typedef  size_t ULONG ;
struct TYPE_19__ {int /*<<< orphan*/  palPalEntry; } ;
struct TYPE_18__ {scalar_t__ hpalDefault; } ;
struct TYPE_17__ {scalar_t__ hpalDefault; int ulBitCount; int cPaletteShift; int /*<<< orphan*/  hDriver; TYPE_1__* pPal; } ;
struct TYPE_16__ {int NumEntries; int /*<<< orphan*/ * LookupTable; scalar_t__ FirstEntry; } ;
struct TYPE_15__ {int Red; int Green; int Blue; scalar_t__ Unused; } ;
struct TYPE_14__ {int peRed; int peGreen; int peBlue; } ;
typedef  TYPE_2__* PVIDEO_CLUTDATA ;
typedef  TYPE_3__* PVIDEO_CLUT ;
typedef  int /*<<< orphan*/  PULONG ;
typedef  TYPE_4__* PPDEV ;
typedef  scalar_t__ HPALETTE ;
typedef  TYPE_5__ DEVINFO ;
typedef  int /*<<< orphan*/  BYTE ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
 int /*<<< orphan*/  DISPDBG (int) ; 
 scalar_t__ EngCreatePalette (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  EngDeletePalette (scalar_t__) ; 
 scalar_t__ EngDeviceIoControl (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_3__*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t*) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  IOCTL_VIDEO_SET_COLOR_REGISTERS ; 
 int MAX_CLUT_SIZE ; 
 int /*<<< orphan*/  PAL_INDEXED ; 
 int /*<<< orphan*/  RIP (char*) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  bInitDefaultPalette (TYPE_4__*,TYPE_5__*) ; 
 TYPE_7__ logPalVGA ; 

BOOL bInitPaletteInfo(PPDEV ppdev, DEVINFO *pDevInfo)
{
    if (!bInitDefaultPalette(ppdev, pDevInfo))
        return(FALSE);

    return(TRUE);
}

VOID vDisablePalette(PPDEV ppdev)
{
// Delete the default palette if we created one.

    if (ppdev->hpalDefault)
    {
        EngDeletePalette(ppdev->hpalDefault);
        ppdev->hpalDefault = (HPALETTE) 0;
    }

// eVb: 4.2 [VGARISC Change] - VGA Palette is static, no need to free
#if 0
    if (ppdev->pPal != (PPALETTEENTRY)NULL)
        EngFreeMem((PVOID)ppdev->pPal);
#endif
// eVb: 4.2 [END]
}

BOOL bInitDefaultPalette(PPDEV ppdev, DEVINFO *pDevInfo)
{
// eVb: 4.3 [VGARISC Change] - VGA Palette is static, no need to build
#if 0
    if (ppdev->ulBitCount == 8)
    {
        ULONG ulLoop;
        BYTE jRed,jGre,jBlu;

        //
        // Allocate our palette
        //

        ppdev->pPal = (PPALETTEENTRY)EngAllocMem(0, sizeof(PALETTEENTRY) * 256,
                                                 ALLOC_TAG);

        if ((ppdev->pPal) == NULL) {
            RIP("DISP bInitDefaultPalette() failed EngAllocMem\n");
            return(FALSE);
        }

        //
        // Generate 256 (8*4*4) RGB combinations to fill the palette
        //

        jRed = jGre = jBlu = 0;

        for (ulLoop = 0; ulLoop < 256; ulLoop++)
        {
            ppdev->pPal[ulLoop].peRed   = jRed;
            ppdev->pPal[ulLoop].peGreen = jGre;
            ppdev->pPal[ulLoop].peBlue  = jBlu;
            ppdev->pPal[ulLoop].peFlags = (BYTE)0;

            if (!(jRed += 32))
            if (!(jGre += 32))
            jBlu += 64;
        }

        //
        // Fill in Windows Reserved Colors from the WIN 3.0 DDK
        // The Window Manager reserved the first and last 10 colors for
        // painting windows borders and for non-palette managed applications.
        //

        for (ulLoop = 0; ulLoop < 10; ulLoop++)
        {
            //
            // First 10
            //

            ppdev->pPal[ulLoop] = BASEPALETTE[ulLoop];

            //
            // Last 10
            //

            ppdev->pPal[246 + ulLoop] = BASEPALETTE[ulLoop+10];
        }

#endif
// eVb: 4.3 [END]
        //
        // Create handle for palette.
        //

        ppdev->hpalDefault =
        pDevInfo->hpalDefault = EngCreatePalette(PAL_INDEXED,
// eVb: 4.4 [VGARISC Change] - VGA Palette is 16 colors, not 256, and static
                                                   16,
                                                   (PULONG) &logPalVGA.palPalEntry,
// eVb: 4.4 [END]
                                                   0,0,0);

        if (ppdev->hpalDefault == (HPALETTE) 0)
        {
            RIP("DISP bInitDefaultPalette failed EngCreatePalette\n");
// eVb: 4.5 [VGARISC Change] - VGA Palette is static, no need to free
            //EngFreeMem(ppdev->pPal);
// eVb: 4.5 [END]        
            return(FALSE);
        }

        //
        // Initialize the hardware with the initial palette.
        //

        return(TRUE);

// eVb: 4.6 [VGARISC Change] - VGA Palette is static, no bitfield palette needed
#if 0
    } else {

        ppdev->hpalDefault =
        pDevInfo->hpalDefault = EngCreatePalette(PAL_BITFIELDS,
                                                   0,(PULONG) NULL,
                                                   ppdev->flRed,
                                                   ppdev->flGreen,
                                                   ppdev->flBlue);

        if (ppdev->hpalDefault == (HPALETTE) 0)
        {
            RIP("DISP bInitDefaultPalette failed EngCreatePalette\n");
            return(FALSE);
        }
    }

    return(TRUE);
#endif
// eVb: 4.6 [END]  
}

BOOL bInit256ColorPalette(PPDEV ppdev)
{
    BYTE        ajClutSpace[MAX_CLUT_SIZE];
    PVIDEO_CLUT pScreenClut;
    ULONG       ulReturnedDataLength;
    ULONG       cColors;
    PVIDEO_CLUTDATA pScreenClutData;

    if (ppdev->ulBitCount == 8)
    {
        //
        // Fill in pScreenClut header info:
        //

        pScreenClut             = (PVIDEO_CLUT) ajClutSpace;
        pScreenClut->NumEntries = 256;
        pScreenClut->FirstEntry = 0;

        //
        // Copy colours in:
        //

        cColors = 256;
        pScreenClutData = (PVIDEO_CLUTDATA) (&(pScreenClut->LookupTable[0]));

        while(cColors--)
        {
            pScreenClutData[cColors].Red =    ppdev->pPal[cColors].peRed >>
                                              ppdev->cPaletteShift;
            pScreenClutData[cColors].Green =  ppdev->pPal[cColors].peGreen >>
                                              ppdev->cPaletteShift;
            pScreenClutData[cColors].Blue =   ppdev->pPal[cColors].peBlue >>
                                              ppdev->cPaletteShift;
            pScreenClutData[cColors].Unused = 0;
        }

        //
        // Set palette registers:
        //

        if (EngDeviceIoControl(ppdev->hDriver,
                               IOCTL_VIDEO_SET_COLOR_REGISTERS,
                               pScreenClut,
                               MAX_CLUT_SIZE,
                               NULL,
                               0,
                               &ulReturnedDataLength))
        {
            DISPDBG((0, "Failed bEnablePalette"));
            return(FALSE);
        }
    }

    DISPDBG((5, "Passed bEnablePalette"));

    return(TRUE);
}

