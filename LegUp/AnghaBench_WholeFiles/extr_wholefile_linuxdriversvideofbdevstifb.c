#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_5__ ;
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int u32 ;
struct TYPE_9__ {int bits_per_pixel; int xres; int yres; } ;
struct TYPE_7__ {int line_length; } ;
struct TYPE_10__ {TYPE_3__ var; TYPE_1__ fix; scalar_t__ screen_base; } ;
struct stifb_info {int id; TYPE_4__ info; } ;
struct TYPE_8__ {int length; int lutOffset; int /*<<< orphan*/  lutType; } ;
struct TYPE_11__ {int all; TYPE_2__ fields; } ;
typedef  TYPE_5__ NgleLutBltCtl ;

/* Variables and functions */
 int /*<<< orphan*/  AddrLong ; 
 int /*<<< orphan*/  BA (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BAIndexBase (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BAJustPoint (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BGx (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  BINattr ; 
 int /*<<< orphan*/  BINovly ; 
 int /*<<< orphan*/  BitmapExtent08 ; 
#define  CRT_ID_VISUALIZE_EG 136 
#define  CRX24_OVERLAY_PLANES 135 
#define  DISABLE 134 
 int /*<<< orphan*/  DataDynamic ; 
#define  ENABLE 133 
 int /*<<< orphan*/  FGx (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GET_FIFO_SLOTS (struct stifb_info*,int,int) ; 
 int /*<<< orphan*/  HYPER_CMAP_TYPE ; 
 int /*<<< orphan*/  IBOvals (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ IS_24_DEVICE (struct stifb_info*) ; 
 int /*<<< orphan*/  IndexedDcd ; 
 int /*<<< orphan*/  MaskAddrOffset (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MaskOtc ; 
 int /*<<< orphan*/  NGLE_BINC_SET_DSTADDR (struct stifb_info*,int) ; 
 int /*<<< orphan*/  NGLE_BINC_SET_DSTMASK (struct stifb_info*,int) ; 
 int /*<<< orphan*/  NGLE_BINC_WRITE32 (struct stifb_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NGLE_LOCK (struct stifb_info*) ; 
 int NGLE_LONG_FB_ADDRESS (int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NGLE_QUICK_SET_CTL_PLN_REG (struct stifb_info*,unsigned int) ; 
 int /*<<< orphan*/  NGLE_QUICK_SET_DST_BM_ACCESS (struct stifb_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NGLE_QUICK_SET_IMAGE_BITMAP_OP (struct stifb_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NGLE_REALLY_SET_IMAGE_FG_COLOR (struct stifb_info*,int) ; 
 int /*<<< orphan*/  NGLE_REALLY_SET_IMAGE_PLANEMASK (struct stifb_info*,int) ; 
 int /*<<< orphan*/  NGLE_SET_DSTXY (struct stifb_info*,int) ; 
 int /*<<< orphan*/  NGLE_SET_TRANSFERDATA (struct stifb_info*,int) ; 
 int /*<<< orphan*/  NGLE_UNLOCK (struct stifb_info*) ; 
 int /*<<< orphan*/  Otc04 ; 
 int /*<<< orphan*/  Otc32 ; 
 int /*<<< orphan*/  Ots08 ; 
 int /*<<< orphan*/  OtsIndirect ; 
 char READ_BYTE (struct stifb_info*,int /*<<< orphan*/ ) ; 
 int READ_WORD (struct stifb_info*,int) ; 
 int REG_1 ; 
 int REG_10 ; 
 int REG_11 ; 
 int REG_12 ; 
 int REG_13 ; 
 int REG_14 ; 
 int /*<<< orphan*/  REG_15b0 ; 
 int /*<<< orphan*/  REG_16b1 ; 
 int REG_2 ; 
 int REG_21 ; 
 int REG_22 ; 
 int REG_23 ; 
 int REG_26 ; 
 int REG_27 ; 
 int REG_3 ; 
 int REG_32 ; 
 int REG_33 ; 
 int REG_4 ; 
 int REG_6 ; 
 int REG_8 ; 
 int REG_9 ; 
 int /*<<< orphan*/  RopSrc ; 
#define  S9000_ID_A1439A 132 
#define  S9000_ID_A1659A 131 
#define  S9000_ID_ARTIST 130 
#define  S9000_ID_HCRX 129 
#define  S9000_ID_TIMBER 128 
 int /*<<< orphan*/  SET_LENXY_START_RECFILL (struct stifb_info*,int) ; 
 int /*<<< orphan*/  StaticReg (int) ; 
 int /*<<< orphan*/  WRITE_BYTE (int,struct stifb_info*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  WRITE_WORD (int,struct stifb_info*,int) ; 
 int /*<<< orphan*/  fb_memset (scalar_t__,int,int) ; 

__attribute__((used)) static void
SETUP_HW(struct stifb_info *fb)
{
	char stat;

	do {
		stat = READ_BYTE(fb, REG_15b0);
		if (!stat)
	    		stat = READ_BYTE(fb, REG_15b0);
	} while (stat);
}

__attribute__((used)) static void
SETUP_FB(struct stifb_info *fb)
{	
	unsigned int reg10_value = 0;
	
	SETUP_HW(fb);
	switch (fb->id)
	{
		case CRT_ID_VISUALIZE_EG:
		case S9000_ID_ARTIST:
		case S9000_ID_A1659A:
			reg10_value = 0x13601000;
			break;
		case S9000_ID_A1439A:
			if (fb->info.var.bits_per_pixel == 32)						
				reg10_value = 0xBBA0A000;
			else 
				reg10_value = 0x13601000;
			break;
		case S9000_ID_HCRX:
			if (fb->info.var.bits_per_pixel == 32)
				reg10_value = 0xBBA0A000;
			else					
				reg10_value = 0x13602000;
			break;
		case S9000_ID_TIMBER:
		case CRX24_OVERLAY_PLANES:
			reg10_value = 0x13602000;
			break;
	}
	if (reg10_value)
		WRITE_WORD(reg10_value, fb, REG_10);
	WRITE_WORD(0x83000300, fb, REG_14);
	SETUP_HW(fb);
	WRITE_BYTE(1, fb, REG_16b1);
}

__attribute__((used)) static void
START_IMAGE_COLORMAP_ACCESS(struct stifb_info *fb)
{
	SETUP_HW(fb);
	WRITE_WORD(0xBBE0F000, fb, REG_10);
	WRITE_WORD(0x03000300, fb, REG_14);
	WRITE_WORD(~0, fb, REG_13);
}

__attribute__((used)) static void
WRITE_IMAGE_COLOR(struct stifb_info *fb, int index, int color) 
{
	SETUP_HW(fb);
	WRITE_WORD(((0x100+index)<<2), fb, REG_3);
	WRITE_WORD(color, fb, REG_4);
}

__attribute__((used)) static void
FINISH_IMAGE_COLORMAP_ACCESS(struct stifb_info *fb) 
{		
	WRITE_WORD(0x400, fb, REG_2);
	if (fb->info.var.bits_per_pixel == 32) {
		WRITE_WORD(0x83000100, fb, REG_1);
	} else {
		if (fb->id == S9000_ID_ARTIST || fb->id == CRT_ID_VISUALIZE_EG)
			WRITE_WORD(0x80000100, fb, REG_26);
		else							
			WRITE_WORD(0x80000100, fb, REG_1);
	}
	SETUP_FB(fb);
}

__attribute__((used)) static void
SETUP_RAMDAC(struct stifb_info *fb) 
{
	SETUP_HW(fb);
	WRITE_WORD(0x04000000, fb, 0x1020);
	WRITE_WORD(0xff000000, fb, 0x1028);
}

__attribute__((used)) static void 
CRX24_SETUP_RAMDAC(struct stifb_info *fb) 
{
	SETUP_HW(fb);
	WRITE_WORD(0x04000000, fb, 0x1000);
	WRITE_WORD(0x02000000, fb, 0x1004);
	WRITE_WORD(0xff000000, fb, 0x1008);
	WRITE_WORD(0x05000000, fb, 0x1000);
	WRITE_WORD(0x02000000, fb, 0x1004);
	WRITE_WORD(0x03000000, fb, 0x1008);
}

__attribute__((used)) static void 
CRX24_SET_OVLY_MASK(struct stifb_info *fb)
{
	SETUP_HW(fb);
	WRITE_WORD(0x13a02000, fb, REG_11);
	WRITE_WORD(0x03000300, fb, REG_14);
	WRITE_WORD(0x000017f0, fb, REG_3);
	WRITE_WORD(0xffffffff, fb, REG_13);
	WRITE_WORD(0xffffffff, fb, REG_22);
	WRITE_WORD(0x00000000, fb, REG_23);
}

__attribute__((used)) static void
ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable)
{
	unsigned int value = enable ? 0x43000000 : 0x03000000;
        SETUP_HW(fb);
        WRITE_WORD(0x06000000,	fb, 0x1030);
        WRITE_WORD(value, 	fb, 0x1038);
}

__attribute__((used)) static void 
CRX24_ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable)
{
	unsigned int value = enable ? 0x10000000 : 0x30000000;
	SETUP_HW(fb);
	WRITE_WORD(0x01000000,	fb, 0x1000);
	WRITE_WORD(0x02000000,	fb, 0x1004);
	WRITE_WORD(value,	fb, 0x1008);
}

__attribute__((used)) static void
ARTIST_ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable) 
{
	u32 DregsMiscVideo = REG_21;
	u32 DregsMiscCtl = REG_27;
	
	SETUP_HW(fb);
	if (enable) {
	  WRITE_WORD(READ_WORD(fb, DregsMiscVideo) | 0x0A000000, fb, DregsMiscVideo);
	  WRITE_WORD(READ_WORD(fb, DregsMiscCtl)   | 0x00800000, fb, DregsMiscCtl);
	} else {
	  WRITE_WORD(READ_WORD(fb, DregsMiscVideo) & ~0x0A000000, fb, DregsMiscVideo);
	  WRITE_WORD(READ_WORD(fb, DregsMiscCtl)   & ~0x00800000, fb, DregsMiscCtl);
	}
}

__attribute__((used)) static void
HYPER_ENABLE_DISABLE_DISPLAY(struct stifb_info *fb, int enable)
{
	u32 DregsHypMiscVideo = REG_33;
	unsigned int value;
	SETUP_HW(fb);
	value = READ_WORD(fb, DregsHypMiscVideo);
	if (enable)
		value |= 0x0A000000;
	else
		value &= ~0x0A000000;
	WRITE_WORD(value, fb, DregsHypMiscVideo);
}

__attribute__((used)) static void
SETUP_ATTR_ACCESS(struct stifb_info *fb, unsigned BufferNumber)
{
	SETUP_HW(fb);
	WRITE_WORD(0x2EA0D000, fb, REG_11);
	WRITE_WORD(0x23000302, fb, REG_14);
	WRITE_WORD(BufferNumber, fb, REG_12);
	WRITE_WORD(0xffffffff, fb, REG_8);
}

__attribute__((used)) static void
SET_ATTR_SIZE(struct stifb_info *fb, int width, int height) 
{
	/* REG_6 seems to have special values when run on a 
	   RDI precisionbook parisc laptop (INTERNAL_EG_DX1024 or
	   INTERNAL_EG_X1024).  The values are:
		0x2f0: internal (LCD) & external display enabled
		0x2a0: external display only
		0x000: zero on standard artist graphic cards
	*/ 
	WRITE_WORD(0x00000000, fb, REG_6);
	WRITE_WORD((width<<16) | height, fb, REG_9);
	WRITE_WORD(0x05000000, fb, REG_6);
	WRITE_WORD(0x00040001, fb, REG_9);
}

__attribute__((used)) static void
FINISH_ATTR_ACCESS(struct stifb_info *fb) 
{
	SETUP_HW(fb);
	WRITE_WORD(0x00000000, fb, REG_12);
}

__attribute__((used)) static void
elkSetupPlanes(struct stifb_info *fb)
{
	SETUP_RAMDAC(fb);
	SETUP_FB(fb);
}

__attribute__((used)) static void 
ngleSetupAttrPlanes(struct stifb_info *fb, int BufferNumber)
{
	SETUP_ATTR_ACCESS(fb, BufferNumber);
	SET_ATTR_SIZE(fb, fb->info.var.xres, fb->info.var.yres);
	FINISH_ATTR_ACCESS(fb);
	SETUP_FB(fb);
}

__attribute__((used)) static void
rattlerSetupPlanes(struct stifb_info *fb)
{
	int saved_id, y;

 	/* Write RAMDAC pixel read mask register so all overlay
	 * planes are display-enabled.  (CRX24 uses Bt462 pixel
	 * read mask register for overlay planes, not image planes).
	 */
	CRX24_SETUP_RAMDAC(fb);
    
	/* change fb->id temporarily to fool SETUP_FB() */
	saved_id = fb->id;
	fb->id = CRX24_OVERLAY_PLANES;
	SETUP_FB(fb);
	fb->id = saved_id;

	for (y = 0; y < fb->info.var.yres; ++y)
		fb_memset(fb->info.screen_base + y * fb->info.fix.line_length,
			0xff, fb->info.var.xres * fb->info.var.bits_per_pixel/8);

	CRX24_SET_OVLY_MASK(fb);
	SETUP_FB(fb);
}

__attribute__((used)) static NgleLutBltCtl
setHyperLutBltCtl(struct stifb_info *fb, int offsetWithinLut, int length) 
{
	NgleLutBltCtl lutBltCtl;

	/* set enable, zero reserved fields */
	lutBltCtl.all = 0x80000000;

	lutBltCtl.fields.length = length;
	lutBltCtl.fields.lutType = HYPER_CMAP_TYPE;

	/* Expect lutIndex to be 0 or 1 for image cmaps, 2 or 3 for overlay cmaps */
	if (fb->info.var.bits_per_pixel == 8)
		lutBltCtl.fields.lutOffset = 2 * 256;
	else
		lutBltCtl.fields.lutOffset = 0 * 256;

	/* Offset points to start of LUT.  Adjust for within LUT */
	lutBltCtl.fields.lutOffset += offsetWithinLut;

	return lutBltCtl;
}

__attribute__((used)) static void hyperUndoITE(struct stifb_info *fb)
{
	int nFreeFifoSlots = 0;
	u32 fbAddr;

	NGLE_LOCK(fb);

	GET_FIFO_SLOTS(fb, nFreeFifoSlots, 1);
	WRITE_WORD(0xffffffff, fb, REG_32);

	/* Write overlay transparency mask so only entry 255 is transparent */

	/* Hardware setup for full-depth write to "magic" location */
	GET_FIFO_SLOTS(fb, nFreeFifoSlots, 7);
	NGLE_QUICK_SET_DST_BM_ACCESS(fb, 
		BA(IndexedDcd, Otc04, Ots08, AddrLong,
		BAJustPoint(0), BINovly, BAIndexBase(0)));
	NGLE_QUICK_SET_IMAGE_BITMAP_OP(fb,
		IBOvals(RopSrc, MaskAddrOffset(0),
		BitmapExtent08, StaticReg(0),
		DataDynamic, MaskOtc, BGx(0), FGx(0)));

	/* Now prepare to write to the "magic" location */
	fbAddr = NGLE_LONG_FB_ADDRESS(0, 1532, 0);
	NGLE_BINC_SET_DSTADDR(fb, fbAddr);
	NGLE_REALLY_SET_IMAGE_PLANEMASK(fb, 0xffffff);
	NGLE_BINC_SET_DSTMASK(fb, 0xffffffff);

	/* Finally, write a zero to clear the mask */
	NGLE_BINC_WRITE32(fb, 0);

	NGLE_UNLOCK(fb);
}

__attribute__((used)) static void 
ngleDepth8_ClearImagePlanes(struct stifb_info *fb)
{
	/* FIXME! */
}

__attribute__((used)) static void 
ngleDepth24_ClearImagePlanes(struct stifb_info *fb)
{
	/* FIXME! */
}

__attribute__((used)) static void
ngleResetAttrPlanes(struct stifb_info *fb, unsigned int ctlPlaneReg)
{
	int nFreeFifoSlots = 0;
	u32 packed_dst;
	u32 packed_len;

	NGLE_LOCK(fb);

	GET_FIFO_SLOTS(fb, nFreeFifoSlots, 4);
	NGLE_QUICK_SET_DST_BM_ACCESS(fb, 
				     BA(IndexedDcd, Otc32, OtsIndirect,
					AddrLong, BAJustPoint(0),
					BINattr, BAIndexBase(0)));
	NGLE_QUICK_SET_CTL_PLN_REG(fb, ctlPlaneReg);
	NGLE_SET_TRANSFERDATA(fb, 0xffffffff);

	NGLE_QUICK_SET_IMAGE_BITMAP_OP(fb,
				       IBOvals(RopSrc, MaskAddrOffset(0),
					       BitmapExtent08, StaticReg(1),
					       DataDynamic, MaskOtc,
					       BGx(0), FGx(0)));
	packed_dst = 0;
	packed_len = (fb->info.var.xres << 16) | fb->info.var.yres;
	GET_FIFO_SLOTS(fb, nFreeFifoSlots, 2);
	NGLE_SET_DSTXY(fb, packed_dst);
	SET_LENXY_START_RECFILL(fb, packed_len);

	/*
	 * In order to work around an ELK hardware problem (Buffy doesn't
	 * always flush it's buffers when writing to the attribute
	 * planes), at least 4 pixels must be written to the attribute
	 * planes starting at (X == 1280) and (Y != to the last Y written
	 * by BIF):
	 */

	if (fb->id == S9000_ID_A1659A) {   /* ELK_DEVICE_ID */
		/* It's safe to use scanline zero: */
		packed_dst = (1280 << 16);
		GET_FIFO_SLOTS(fb, nFreeFifoSlots, 2);
		NGLE_SET_DSTXY(fb, packed_dst);
		packed_len = (4 << 16) | 1;
		SET_LENXY_START_RECFILL(fb, packed_len);
	}   /* ELK Hardware Kludge */

	/**** Finally, set the Control Plane Register back to zero: ****/
	GET_FIFO_SLOTS(fb, nFreeFifoSlots, 1);
	NGLE_QUICK_SET_CTL_PLN_REG(fb, 0);
	
	NGLE_UNLOCK(fb);
}

__attribute__((used)) static void
ngleClearOverlayPlanes(struct stifb_info *fb, int mask, int data)
{
	int nFreeFifoSlots = 0;
	u32 packed_dst;
	u32 packed_len;
    
	NGLE_LOCK(fb);

	/* Hardware setup */
	GET_FIFO_SLOTS(fb, nFreeFifoSlots, 8);
	NGLE_QUICK_SET_DST_BM_ACCESS(fb, 
				     BA(IndexedDcd, Otc04, Ots08, AddrLong,
					BAJustPoint(0), BINovly, BAIndexBase(0)));

        NGLE_SET_TRANSFERDATA(fb, 0xffffffff);  /* Write foreground color */

        NGLE_REALLY_SET_IMAGE_FG_COLOR(fb, data);
        NGLE_REALLY_SET_IMAGE_PLANEMASK(fb, mask);
    
        packed_dst = 0;
        packed_len = (fb->info.var.xres << 16) | fb->info.var.yres;
        NGLE_SET_DSTXY(fb, packed_dst);
    
        /* Write zeroes to overlay planes */		       
	NGLE_QUICK_SET_IMAGE_BITMAP_OP(fb,
				       IBOvals(RopSrc, MaskAddrOffset(0),
					       BitmapExtent08, StaticReg(0),
					       DataDynamic, MaskOtc, BGx(0), FGx(0)));
		       
        SET_LENXY_START_RECFILL(fb, packed_len);

	NGLE_UNLOCK(fb);
}

__attribute__((used)) static void 
hyperResetPlanes(struct stifb_info *fb, int enable)
{
	unsigned int controlPlaneReg;

	NGLE_LOCK(fb);

	if (IS_24_DEVICE(fb))
		if (fb->info.var.bits_per_pixel == 32)
			controlPlaneReg = 0x04000F00;
		else
			controlPlaneReg = 0x00000F00;   /* 0x00000800 should be enough, but lets clear all 4 bits */
	else
		controlPlaneReg = 0x00000F00; /* 0x00000100 should be enough, but lets clear all 4 bits */

	switch (enable) {
	case ENABLE:
		/* clear screen */
		if (IS_24_DEVICE(fb))
			ngleDepth24_ClearImagePlanes(fb);
		else
			ngleDepth8_ClearImagePlanes(fb);

		/* Paint attribute planes for default case.
		 * On Hyperdrive, this means all windows using overlay cmap 0. */
		ngleResetAttrPlanes(fb, controlPlaneReg);

		/* clear overlay planes */
	        ngleClearOverlayPlanes(fb, 0xff, 255);

		/**************************************************
		 ** Also need to counteract ITE settings 
		 **************************************************/
		hyperUndoITE(fb);
		break;

	case DISABLE:
		/* clear screen */
		if (IS_24_DEVICE(fb))
			ngleDepth24_ClearImagePlanes(fb);
		else
			ngleDepth8_ClearImagePlanes(fb);
		ngleResetAttrPlanes(fb, controlPlaneReg);
		ngleClearOverlayPlanes(fb, 0xff, 0);
		break;

	case -1:	/* RESET */
		hyperUndoITE(fb);
		ngleResetAttrPlanes(fb, controlPlaneReg);
		break;
    	}
	
	NGLE_UNLOCK(fb);
}

__attribute__((used)) static void 
ngleGetDeviceRomData(struct stifb_info *fb)
{
#if 0
XXX: FIXME: !!!
	int	*pBytePerLongDevDepData;/* data byte == LSB */
	int 	*pRomTable;
	NgleDevRomData	*pPackedDevRomData;
	int	sizePackedDevRomData = sizeof(*pPackedDevRomData);
	char	*pCard8;
	int	i;
	char	*mapOrigin = NULL;
    
	int romTableIdx;

	pPackedDevRomData = fb->ngle_rom;

	SETUP_HW(fb);
	if (fb->id == S9000_ID_ARTIST) {
		pPackedDevRomData->cursor_pipeline_delay = 4;
		pPackedDevRomData->video_interleaves     = 4;
	} else {
		/* Get pointer to unpacked byte/long data in ROM */
		pBytePerLongDevDepData = fb->sti->regions[NGLEDEVDEPROM_CRT_REGION];

		/* Tomcat supports several resolutions: 1280x1024, 1024x768, 640x480 */
		if (fb->id == S9000_ID_TOMCAT)
	{
	    /*  jump to the correct ROM table  */
	    GET_ROMTABLE_INDEX(romTableIdx);
	    while  (romTableIdx > 0)
	    {
		pCard8 = (Card8 *) pPackedDevRomData;
		pRomTable = pBytePerLongDevDepData;
		/* Pack every fourth byte from ROM into structure */
		for (i = 0; i < sizePackedDevRomData; i++)
		{
		    *pCard8++ = (Card8) (*pRomTable++);
		}

		pBytePerLongDevDepData = (Card32 *)
			((Card8 *) pBytePerLongDevDepData +
			       pPackedDevRomData->sizeof_ngle_data);

		romTableIdx--;
	    }
	}

	pCard8 = (Card8 *) pPackedDevRomData;

	/* Pack every fourth byte from ROM into structure */
	for (i = 0; i < sizePackedDevRomData; i++)
	{
	    *pCard8++ = (Card8) (*pBytePerLongDevDepData++);
	}
    }

    SETUP_FB(fb);
#endif
}

