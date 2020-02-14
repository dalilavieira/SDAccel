#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64 ;
typedef  scalar_t__ uint32 ;
typedef  scalar_t__ uint16 ;
typedef  scalar_t__ tmsize_t ;
typedef  int int32 ;
struct TYPE_19__ {scalar_t__ td_tilewidth; scalar_t__ td_tilelength; scalar_t__ td_tiledepth; int td_imagedepth; scalar_t__ td_imagewidth; scalar_t__ td_imagelength; scalar_t__ td_planarconfig; scalar_t__ td_samplesperpixel; scalar_t__ td_bitspersample; scalar_t__ td_photometric; } ;
struct TYPE_20__ {int /*<<< orphan*/  (* tif_deftilesize ) (TYPE_2__*,scalar_t__*,scalar_t__*) ;int /*<<< orphan*/  tif_clientdata; TYPE_1__ tif_dir; int /*<<< orphan*/  tif_name; } ;
typedef  TYPE_1__ TIFFDirectory ;
typedef  TYPE_2__ TIFF ;

/* Variables and functions */
 scalar_t__ PHOTOMETRIC_YCBCR ; 
 scalar_t__ PLANARCONFIG_CONTIG ; 
 scalar_t__ PLANARCONFIG_SEPARATE ; 
 int /*<<< orphan*/  TIFFErrorExt (int /*<<< orphan*/ ,char const*,char*,...) ; 
 int /*<<< orphan*/  TIFFGetFieldDefaulted (TYPE_2__*,int /*<<< orphan*/ ,scalar_t__*,scalar_t__*) ; 
 int /*<<< orphan*/  TIFFTAG_YCBCRSUBSAMPLING ; 
 scalar_t__ TIFFhowmany8_64 (scalar_t__) ; 
 scalar_t__ TIFFhowmany_32 (scalar_t__,scalar_t__) ; 
 scalar_t__ TIFFroundup_32 (scalar_t__,int) ; 
 scalar_t__ _TIFFMultiply32 (TYPE_2__*,scalar_t__,scalar_t__,char*) ; 
 scalar_t__ _TIFFMultiply64 (TYPE_2__*,scalar_t__,scalar_t__,char const*) ; 
 int /*<<< orphan*/  isUpSampled (TYPE_2__*) ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,scalar_t__*,scalar_t__*) ; 

uint32
TIFFComputeTile(TIFF* tif, uint32 x, uint32 y, uint32 z, uint16 s)
{
	TIFFDirectory *td = &tif->tif_dir;
	uint32 dx = td->td_tilewidth;
	uint32 dy = td->td_tilelength;
	uint32 dz = td->td_tiledepth;
	uint32 tile = 1;

	if (td->td_imagedepth == 1)
		z = 0;
	if (dx == (uint32) -1)
		dx = td->td_imagewidth;
	if (dy == (uint32) -1)
		dy = td->td_imagelength;
	if (dz == (uint32) -1)
		dz = td->td_imagedepth;
	if (dx != 0 && dy != 0 && dz != 0) {
		uint32 xpt = TIFFhowmany_32(td->td_imagewidth, dx);
		uint32 ypt = TIFFhowmany_32(td->td_imagelength, dy);
		uint32 zpt = TIFFhowmany_32(td->td_imagedepth, dz);

		if (td->td_planarconfig == PLANARCONFIG_SEPARATE) 
			tile = (xpt*ypt*zpt)*s +
			     (xpt*ypt)*(z/dz) +
			     xpt*(y/dy) +
			     x/dx;
		else
			tile = (xpt*ypt)*(z/dz) + xpt*(y/dy) + x/dx;
	}
	return (tile);
}

int
TIFFCheckTile(TIFF* tif, uint32 x, uint32 y, uint32 z, uint16 s)
{
	TIFFDirectory *td = &tif->tif_dir;

	if (x >= td->td_imagewidth) {
		TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
			     "%lu: Col out of range, max %lu",
			     (unsigned long) x,
			     (unsigned long) (td->td_imagewidth - 1));
		return (0);
	}
	if (y >= td->td_imagelength) {
		TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
			     "%lu: Row out of range, max %lu",
			     (unsigned long) y,
			     (unsigned long) (td->td_imagelength - 1));
		return (0);
	}
	if (z >= td->td_imagedepth) {
		TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
			     "%lu: Depth out of range, max %lu",
			     (unsigned long) z,
			     (unsigned long) (td->td_imagedepth - 1));
		return (0);
	}
	if (td->td_planarconfig == PLANARCONFIG_SEPARATE &&
	    s >= td->td_samplesperpixel) {
		TIFFErrorExt(tif->tif_clientdata, tif->tif_name,
			     "%lu: Sample out of range, max %lu",
			     (unsigned long) s,
			     (unsigned long) (td->td_samplesperpixel - 1));
		return (0);
	}
	return (1);
}

uint32
TIFFNumberOfTiles(TIFF* tif)
{
	TIFFDirectory *td = &tif->tif_dir;
	uint32 dx = td->td_tilewidth;
	uint32 dy = td->td_tilelength;
	uint32 dz = td->td_tiledepth;
	uint32 ntiles;

	if (dx == (uint32) -1)
		dx = td->td_imagewidth;
	if (dy == (uint32) -1)
		dy = td->td_imagelength;
	if (dz == (uint32) -1)
		dz = td->td_imagedepth;
	ntiles = (dx == 0 || dy == 0 || dz == 0) ? 0 :
	    _TIFFMultiply32(tif, _TIFFMultiply32(tif, TIFFhowmany_32(td->td_imagewidth, dx),
	    TIFFhowmany_32(td->td_imagelength, dy),
	    "TIFFNumberOfTiles"),
	    TIFFhowmany_32(td->td_imagedepth, dz), "TIFFNumberOfTiles");
	if (td->td_planarconfig == PLANARCONFIG_SEPARATE)
		ntiles = _TIFFMultiply32(tif, ntiles, td->td_samplesperpixel,
		    "TIFFNumberOfTiles");
	return (ntiles);
}

uint64
TIFFTileRowSize64(TIFF* tif)
{
        static const char module[] = "TIFFTileRowSize64";
	TIFFDirectory *td = &tif->tif_dir;
	uint64 rowsize;
	uint64 tilerowsize;

	if (td->td_tilelength == 0)
        {
                TIFFErrorExt(tif->tif_clientdata,module,"Tile length is zero");
                return 0;
        }
        if (td->td_tilewidth == 0)
        {
                TIFFErrorExt(tif->tif_clientdata,module,"Tile width is zero");
		return (0);
        }
	rowsize = _TIFFMultiply64(tif, td->td_bitspersample, td->td_tilewidth,
	    "TIFFTileRowSize");
	if (td->td_planarconfig == PLANARCONFIG_CONTIG)
        {
                if (td->td_samplesperpixel == 0)
                {
                        TIFFErrorExt(tif->tif_clientdata,module,"Samples per pixel is zero");
                        return 0;
                }
		rowsize = _TIFFMultiply64(tif, rowsize, td->td_samplesperpixel,
		    "TIFFTileRowSize");
        }
        tilerowsize=TIFFhowmany8_64(rowsize);
        if (tilerowsize == 0)
        {
                TIFFErrorExt(tif->tif_clientdata,module,"Computed tile row size is zero");
                return 0;
        }
	return (tilerowsize);
}

tmsize_t
TIFFTileRowSize(TIFF* tif)
{
	static const char module[] = "TIFFTileRowSize";
	uint64 m;
	tmsize_t n;
	m=TIFFTileRowSize64(tif);
	n=(tmsize_t)m;
	if ((uint64)n!=m)
	{
		TIFFErrorExt(tif->tif_clientdata,module,"Integer overflow");
		n=0;
	}
	return(n);
}

uint64
TIFFVTileSize64(TIFF* tif, uint32 nrows)
{
	static const char module[] = "TIFFVTileSize64";
	TIFFDirectory *td = &tif->tif_dir;
	if (td->td_tilelength == 0 || td->td_tilewidth == 0 ||
	    td->td_tiledepth == 0)
		return (0);
	if ((td->td_planarconfig==PLANARCONFIG_CONTIG)&&
	    (td->td_photometric==PHOTOMETRIC_YCBCR)&&
	    (td->td_samplesperpixel==3)&&
	    (!isUpSampled(tif)))
	{
		/*
		 * Packed YCbCr data contain one Cb+Cr for every
		 * HorizontalSampling*VerticalSampling Y values.
		 * Must also roundup width and height when calculating
		 * since images that are not a multiple of the
		 * horizontal/vertical subsampling area include
		 * YCbCr data for the extended image.
		 */
		uint16 ycbcrsubsampling[2];
		uint16 samplingblock_samples;
		uint32 samplingblocks_hor;
		uint32 samplingblocks_ver;
		uint64 samplingrow_samples;
		uint64 samplingrow_size;
		TIFFGetFieldDefaulted(tif,TIFFTAG_YCBCRSUBSAMPLING,ycbcrsubsampling+0,
		    ycbcrsubsampling+1);
		if ((ycbcrsubsampling[0] != 1 && ycbcrsubsampling[0] != 2 && ycbcrsubsampling[0] != 4)
		    ||(ycbcrsubsampling[1] != 1 && ycbcrsubsampling[1] != 2 && ycbcrsubsampling[1] != 4))
		{
			TIFFErrorExt(tif->tif_clientdata,module,
				     "Invalid YCbCr subsampling (%dx%d)", 
				     ycbcrsubsampling[0], 
				     ycbcrsubsampling[1] );
			return 0;
		}
		samplingblock_samples=ycbcrsubsampling[0]*ycbcrsubsampling[1]+2;
		samplingblocks_hor=TIFFhowmany_32(td->td_tilewidth,ycbcrsubsampling[0]);
		samplingblocks_ver=TIFFhowmany_32(nrows,ycbcrsubsampling[1]);
		samplingrow_samples=_TIFFMultiply64(tif,samplingblocks_hor,samplingblock_samples,module);
		samplingrow_size=TIFFhowmany8_64(_TIFFMultiply64(tif,samplingrow_samples,td->td_bitspersample,module));
		return(_TIFFMultiply64(tif,samplingrow_size,samplingblocks_ver,module));
	}
	else
		return(_TIFFMultiply64(tif,nrows,TIFFTileRowSize64(tif),module));
}

tmsize_t
TIFFVTileSize(TIFF* tif, uint32 nrows)
{
	static const char module[] = "TIFFVTileSize";
	uint64 m;
	tmsize_t n;
	m=TIFFVTileSize64(tif,nrows);
	n=(tmsize_t)m;
	if ((uint64)n!=m)
	{
		TIFFErrorExt(tif->tif_clientdata,module,"Integer overflow");
		n=0;
	}
	return(n);
}

uint64
TIFFTileSize64(TIFF* tif)
{
	return (TIFFVTileSize64(tif, tif->tif_dir.td_tilelength));
}

tmsize_t
TIFFTileSize(TIFF* tif)
{
	static const char module[] = "TIFFTileSize";
	uint64 m;
	tmsize_t n;
	m=TIFFTileSize64(tif);
	n=(tmsize_t)m;
	if ((uint64)n!=m)
	{
		TIFFErrorExt(tif->tif_clientdata,module,"Integer overflow");
		n=0;
	}
	return(n);
}

void
TIFFDefaultTileSize(TIFF* tif, uint32* tw, uint32* th)
{
	(*tif->tif_deftilesize)(tif, tw, th);
}

void
_TIFFDefaultTileSize(TIFF* tif, uint32* tw, uint32* th)
{
	(void) tif;
	if (*(int32*) tw < 1)
		*tw = 256;
	if (*(int32*) th < 1)
		*th = 256;
	/* roundup to a multiple of 16 per the spec */
	if (*tw & 0xf)
		*tw = TIFFroundup_32(*tw, 16);
	if (*th & 0xf)
		*th = TIFFroundup_32(*th, 16);
}

