#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_23__   TYPE_2__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint64 ;
typedef  scalar_t__ uint32 ;
typedef  scalar_t__ uint16 ;
typedef  scalar_t__ tmsize_t ;
typedef  int int32 ;
struct TYPE_22__ {scalar_t__ td_rowsperstrip; scalar_t__ td_planarconfig; scalar_t__ td_samplesperpixel; scalar_t__ td_stripsperimage; scalar_t__ td_imagelength; scalar_t__ td_photometric; scalar_t__ td_imagewidth; scalar_t__ td_bitspersample; scalar_t__* td_stripbytecount; } ;
struct TYPE_23__ {scalar_t__ (* tif_defstripsize ) (TYPE_2__*,scalar_t__) ;int /*<<< orphan*/  tif_clientdata; TYPE_1__ tif_dir; } ;
typedef  TYPE_1__ TIFFDirectory ;
typedef  TYPE_2__ TIFF ;

/* Variables and functions */
 scalar_t__ PHOTOMETRIC_YCBCR ; 
 scalar_t__ PLANARCONFIG_CONTIG ; 
 scalar_t__ PLANARCONFIG_SEPARATE ; 
 scalar_t__ STRIP_SIZE_DEFAULT ; 
 int /*<<< orphan*/  TIFFErrorExt (int /*<<< orphan*/ ,char const*,char*,...) ; 
 int /*<<< orphan*/  TIFFGetFieldDefaulted (TYPE_2__*,int /*<<< orphan*/ ,scalar_t__*,scalar_t__*) ; 
 scalar_t__ TIFFScanlineSize64 (TYPE_2__*) ; 
 int /*<<< orphan*/  TIFFTAG_YCBCRSUBSAMPLING ; 
 scalar_t__ TIFFhowmany8_64 (scalar_t__) ; 
 int TIFFhowmany_32 (scalar_t__,scalar_t__) ; 
 scalar_t__ TIFFhowmany_64 (scalar_t__,int) ; 
 scalar_t__ _TIFFMultiply32 (TYPE_2__*,scalar_t__,scalar_t__,char*) ; 
 scalar_t__ _TIFFMultiply64 (TYPE_2__*,scalar_t__,scalar_t__,char const*) ; 
 int /*<<< orphan*/  isUpSampled (TYPE_2__*) ; 
 scalar_t__ stub1 (TYPE_2__*,scalar_t__) ; 

uint32
TIFFComputeStrip(TIFF* tif, uint32 row, uint16 sample)
{
	static const char module[] = "TIFFComputeStrip";
	TIFFDirectory *td = &tif->tif_dir;
	uint32 strip;

	strip = row / td->td_rowsperstrip;
	if (td->td_planarconfig == PLANARCONFIG_SEPARATE) {
		if (sample >= td->td_samplesperpixel) {
			TIFFErrorExt(tif->tif_clientdata, module,
			    "%lu: Sample out of range, max %lu",
			    (unsigned long) sample, (unsigned long) td->td_samplesperpixel);
			return (0);
		}
		strip += (uint32)sample*td->td_stripsperimage;
	}
	return (strip);
}

uint32
TIFFNumberOfStrips(TIFF* tif)
{
	TIFFDirectory *td = &tif->tif_dir;
	uint32 nstrips;

	nstrips = (td->td_rowsperstrip == (uint32) -1 ? 1 :
	     TIFFhowmany_32(td->td_imagelength, td->td_rowsperstrip));
	if (td->td_planarconfig == PLANARCONFIG_SEPARATE)
		nstrips = _TIFFMultiply32(tif, nstrips, (uint32)td->td_samplesperpixel,
		    "TIFFNumberOfStrips");
	return (nstrips);
}

uint64
TIFFVStripSize64(TIFF* tif, uint32 nrows)
{
	static const char module[] = "TIFFVStripSize64";
	TIFFDirectory *td = &tif->tif_dir;
	if (nrows==(uint32)(-1))
		nrows=td->td_imagelength;
	if ((td->td_planarconfig==PLANARCONFIG_CONTIG)&&
	    (td->td_photometric == PHOTOMETRIC_YCBCR)&&
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
		if(td->td_samplesperpixel!=3)
		{
			TIFFErrorExt(tif->tif_clientdata,module,
			    "Invalid td_samplesperpixel value");
			return 0;
		}
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
		samplingblocks_hor=TIFFhowmany_32(td->td_imagewidth,ycbcrsubsampling[0]);
		samplingblocks_ver=TIFFhowmany_32(nrows,ycbcrsubsampling[1]);
		samplingrow_samples=_TIFFMultiply64(tif,samplingblocks_hor,samplingblock_samples,module);
		samplingrow_size=TIFFhowmany8_64(_TIFFMultiply64(tif,samplingrow_samples,td->td_bitspersample,module));
		return(_TIFFMultiply64(tif,samplingrow_size,samplingblocks_ver,module));
	}
	else
		return(_TIFFMultiply64(tif,nrows,TIFFScanlineSize64(tif),module));
}

tmsize_t
TIFFVStripSize(TIFF* tif, uint32 nrows)
{
	static const char module[] = "TIFFVStripSize";
	uint64 m;
	tmsize_t n;
	m=TIFFVStripSize64(tif,nrows);
	n=(tmsize_t)m;
	if ((uint64)n!=m)
	{
		TIFFErrorExt(tif->tif_clientdata,module,"Integer overflow");
		n=0;
	}
	return(n);
}

uint64
TIFFRawStripSize64(TIFF* tif, uint32 strip)
{
	static const char module[] = "TIFFRawStripSize64";
	TIFFDirectory* td = &tif->tif_dir;
	uint64 bytecount = td->td_stripbytecount[strip];

	if (bytecount == 0)
	{
#if defined(__WIN32__) && (defined(_MSC_VER) || defined(__MINGW32__))
		TIFFErrorExt(tif->tif_clientdata, module,
			     "%I64u: Invalid strip byte count, strip %lu",
			     (unsigned __int64) bytecount,
			     (unsigned long) strip);
#else
		TIFFErrorExt(tif->tif_clientdata, module,
			     "%llu: Invalid strip byte count, strip %lu",
			     (unsigned long long) bytecount,
			     (unsigned long) strip);
#endif
		bytecount = (uint64) -1;
	}

	return bytecount;
}

tmsize_t
TIFFRawStripSize(TIFF* tif, uint32 strip)
{
	static const char module[] = "TIFFRawStripSize";
	uint64 m;
	tmsize_t n;
	m=TIFFRawStripSize64(tif,strip);
	if (m==(uint64)(-1))
		n=(tmsize_t)(-1);
	else
	{
		n=(tmsize_t)m;
		if ((uint64)n!=m)
		{
			TIFFErrorExt(tif->tif_clientdata,module,"Integer overflow");
			n=0;
		}
	}
	return(n);
}

uint64
TIFFStripSize64(TIFF* tif)
{
	TIFFDirectory* td = &tif->tif_dir;
	uint32 rps = td->td_rowsperstrip;
	if (rps > td->td_imagelength)
		rps = td->td_imagelength;
	return (TIFFVStripSize64(tif, rps));
}

tmsize_t
TIFFStripSize(TIFF* tif)
{
	static const char module[] = "TIFFStripSize";
	uint64 m;
	tmsize_t n;
	m=TIFFStripSize64(tif);
	n=(tmsize_t)m;
	if ((uint64)n!=m)
	{
		TIFFErrorExt(tif->tif_clientdata,module,"Integer overflow");
		n=0;
	}
	return(n);
}

uint32
TIFFDefaultStripSize(TIFF* tif, uint32 request)
{
	return (*tif->tif_defstripsize)(tif, request);
}

uint32
_TIFFDefaultStripSize(TIFF* tif, uint32 s)
{
	if ((int32) s < 1) {
		/*
		 * If RowsPerStrip is unspecified, try to break the
		 * image up into strips that are approximately
		 * STRIP_SIZE_DEFAULT bytes long.
		 */
		uint64 scanlinesize;
		uint64 rows;
		scanlinesize=TIFFScanlineSize64(tif);
		if (scanlinesize==0)
			scanlinesize=1;
		rows=(uint64)STRIP_SIZE_DEFAULT/scanlinesize;
		if (rows==0)
			rows=1;
		else if (rows>0xFFFFFFFF)
			rows=0xFFFFFFFF;
		s=(uint32)rows;
	}
	return (s);
}

uint64
TIFFScanlineSize64(TIFF* tif)
{
	static const char module[] = "TIFFScanlineSize64";
	TIFFDirectory *td = &tif->tif_dir;
	uint64 scanline_size;
	if (td->td_planarconfig==PLANARCONFIG_CONTIG)
	{
		if ((td->td_photometric==PHOTOMETRIC_YCBCR)&&
		    (td->td_samplesperpixel==3)&&
		    (!isUpSampled(tif)))
		{
			uint16 ycbcrsubsampling[2];
			uint16 samplingblock_samples;
			uint32 samplingblocks_hor;
			uint64 samplingrow_samples;
			uint64 samplingrow_size;
			if(td->td_samplesperpixel!=3)
			{
                            TIFFErrorExt(tif->tif_clientdata,module,
                                         "Invalid td_samplesperpixel value");
                            return 0;
			}
			TIFFGetFieldDefaulted(tif,TIFFTAG_YCBCRSUBSAMPLING,
                                              ycbcrsubsampling+0,
                                              ycbcrsubsampling+1);
			if (((ycbcrsubsampling[0]!=1)&&(ycbcrsubsampling[0]!=2)&&(ycbcrsubsampling[0]!=4)) ||
			    ((ycbcrsubsampling[1]!=1)&&(ycbcrsubsampling[1]!=2)&&(ycbcrsubsampling[1]!=4)))
			{
                            TIFFErrorExt(tif->tif_clientdata,module,
                                         "Invalid YCbCr subsampling");
                            return 0;
			}
			samplingblock_samples = ycbcrsubsampling[0]*ycbcrsubsampling[1]+2;
			samplingblocks_hor = TIFFhowmany_32(td->td_imagewidth,ycbcrsubsampling[0]);
			samplingrow_samples = _TIFFMultiply64(tif,samplingblocks_hor,samplingblock_samples,module);
			samplingrow_size = TIFFhowmany_64(_TIFFMultiply64(tif,samplingrow_samples,td->td_bitspersample,module),8);
			scanline_size = (samplingrow_size/ycbcrsubsampling[1]);
		}
		else
		{
			uint64 scanline_samples;
			scanline_samples=_TIFFMultiply64(tif,td->td_imagewidth,td->td_samplesperpixel,module);
			scanline_size=TIFFhowmany_64(_TIFFMultiply64(tif,scanline_samples,td->td_bitspersample,module),8);
		}
	}
	else
        {
		scanline_size=TIFFhowmany_64(_TIFFMultiply64(tif,td->td_imagewidth,td->td_bitspersample,module),8);
        }
        if (scanline_size == 0)
        {
                TIFFErrorExt(tif->tif_clientdata,module,"Computed scanline size is zero");
                return 0;
        }
	return(scanline_size);
}

tmsize_t
TIFFScanlineSize(TIFF* tif)
{
	static const char module[] = "TIFFScanlineSize";
	uint64 m;
	tmsize_t n;
	m=TIFFScanlineSize64(tif);
	n=(tmsize_t)m;
	if ((uint64)n!=m) {
		TIFFErrorExt(tif->tif_clientdata,module,"Integer arithmetic overflow");
		n=0;
	}
	return(n);
}

uint64
TIFFRasterScanlineSize64(TIFF* tif)
{
	static const char module[] = "TIFFRasterScanlineSize64";
	TIFFDirectory *td = &tif->tif_dir;
	uint64 scanline;

	scanline = _TIFFMultiply64(tif, td->td_bitspersample, td->td_imagewidth, module);
	if (td->td_planarconfig == PLANARCONFIG_CONTIG) {
		scanline = _TIFFMultiply64(tif, scanline, td->td_samplesperpixel, module);
		return (TIFFhowmany8_64(scanline));
	} else
		return (_TIFFMultiply64(tif, TIFFhowmany8_64(scanline),
		    td->td_samplesperpixel, module));
}

tmsize_t
TIFFRasterScanlineSize(TIFF* tif)
{
	static const char module[] = "TIFFRasterScanlineSize";
	uint64 m;
	tmsize_t n;
	m=TIFFRasterScanlineSize64(tif);
	n=(tmsize_t)m;
	if ((uint64)n!=m)
	{
		TIFFErrorExt(tif->tif_clientdata,module,"Integer arithmetic overflow");
		n=0;
	}
	return(n);
}

