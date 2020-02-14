#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_3__ ;
typedef  struct TYPE_15__   TYPE_2__ ;
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
typedef  int UINT ;
struct TYPE_16__ {scalar_t__ cb; int /*<<< orphan*/ * lp; } ;
struct TYPE_15__ {scalar_t__* lp; scalar_t__ cb; } ;
struct TYPE_14__ {scalar_t__ cksize; scalar_t__ ckid; scalar_t__ fccType; int /*<<< orphan*/  dwDataOffset; } ;
typedef  scalar_t__ MMRESULT ;
typedef  TYPE_1__ MMCKINFO ;
typedef  scalar_t__* LPVOID ;
typedef  scalar_t__* LPLONG ;
typedef  TYPE_2__* LPEXTRACHUNKS ;
typedef  scalar_t__* LPDWORD ;
typedef  int /*<<< orphan*/ * LPCVOID ;
typedef  int /*<<< orphan*/ * LPBYTE ;
typedef  scalar_t__ LONG ;
typedef  int /*<<< orphan*/  HRESULT ;
typedef  int /*<<< orphan*/  HPSTR ;
typedef  int /*<<< orphan*/ * HMMIO ;
typedef  scalar_t__ FOURCC ;
typedef  TYPE_3__ EXTRACHUNKS ;
typedef  scalar_t__ DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  AVIERR_FILEREAD ; 
 int /*<<< orphan*/  AVIERR_MEMORY ; 
 int /*<<< orphan*/  AVIERR_NODATA ; 
 int /*<<< orphan*/  AVIERR_OK ; 
 scalar_t__ FAILED (int /*<<< orphan*/ ) ; 
 scalar_t__ FOURCC_LIST ; 
 scalar_t__ FOURCC_RIFF ; 
 int /*<<< orphan*/  GetProcessHeap () ; 
 int /*<<< orphan*/  HEAP_ZERO_MEMORY ; 
 scalar_t__* HeapAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__* HeapReAlloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__*,scalar_t__) ; 
 scalar_t__ MMIOERR_CHUNKNOTFOUND ; 
 int MMIO_FINDCHUNK ; 
 int MMIO_FINDLIST ; 
 int MMIO_FINDRIFF ; 
 scalar_t__ MMSYSERR_NOERROR ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  TRACE (char*,scalar_t__,scalar_t__,...) ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ ckidAVIPADDING ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ min (scalar_t__,scalar_t__) ; 
 scalar_t__ mmioAscend (int /*<<< orphan*/ *,TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mmioDescend (int /*<<< orphan*/ *,TYPE_1__*,TYPE_1__*,int /*<<< orphan*/ ) ; 
 scalar_t__ mmioFOURCC (char,char,char,char) ; 
 scalar_t__ mmioRead (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 int mmioSeek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

HRESULT ReadExtraChunk(const EXTRACHUNKS *extra,FOURCC ckid,LPVOID lpData,LPLONG size)
{
  LPBYTE lp;
  DWORD  cb;

  /* pre-conditions */
  assert(extra != NULL);
  assert(size != NULL);

  lp = extra->lp;
  cb = extra->cb;

  if (lp != NULL) {
    while (cb > 0) {
      if (((FOURCC*)lp)[0] == ckid) {
	/* found correct chunk */
	if (lpData != NULL && *size > 0)
	  memcpy(lpData, lp + 2 * sizeof(DWORD),
		 min(((LPDWORD)lp)[1], *(LPDWORD)size));

	*(LPDWORD)size = ((LPDWORD)lp)[1];

	return AVIERR_OK;
      } else {
	/* skip to next chunk */
	cb -= ((LPDWORD)lp)[1] + 2 * sizeof(DWORD);
	lp += ((LPDWORD)lp)[1] + 2 * sizeof(DWORD);
      }
    }
  }

  /* wanted chunk doesn't exist */
  *size = 0;

  return AVIERR_NODATA;
}

HRESULT WriteExtraChunk(LPEXTRACHUNKS extra,FOURCC ckid,LPCVOID lpData, LONG size)
{
  LPDWORD lp;

  /* pre-conditions */
  assert(extra != NULL);
  assert(lpData != NULL);
  assert(size > 0);

  if (extra->lp)
    lp = HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, extra->lp, extra->cb + size + 2 * sizeof(DWORD));
  else
    lp = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, size + 2 * sizeof(DWORD));

  if (lp == NULL)
    return AVIERR_MEMORY;

  extra->lp  = lp;
  lp = (LPDWORD) ((LPBYTE)lp + extra->cb);
  extra->cb += size + 2 * sizeof(DWORD);

  /* insert chunk-header in block */
  lp[0] = ckid;
  lp[1] = size;

  if (lpData != NULL && size > 0)
    memcpy(lp + 2, lpData, size);

  return AVIERR_OK;
}

HRESULT ReadChunkIntoExtra(LPEXTRACHUNKS extra,HMMIO hmmio,const MMCKINFO *lpck)
{
  LPDWORD lp;
  DWORD   cb;

  /* pre-conditions */
  assert(extra != NULL);
  assert(hmmio != NULL);
  assert(lpck  != NULL);

  cb  = lpck->cksize + 2 * sizeof(DWORD);
  cb += (cb & 1);

  if (extra->lp != NULL)
    lp = HeapReAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, extra->lp, extra->cb + cb);
  else
    lp = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, cb);

  if (lp == NULL)
    return AVIERR_MEMORY;

  extra->lp  = lp;
  lp = (LPDWORD) ((LPBYTE)lp + extra->cb);
  extra->cb += cb;

  /* insert chunk-header in block */
  lp[0] = lpck->ckid;
  lp[1] = lpck->cksize;

  if (lpck->cksize > 0) {
    if (mmioSeek(hmmio, lpck->dwDataOffset, SEEK_SET) == -1)
      return AVIERR_FILEREAD;
    if (mmioRead(hmmio, (HPSTR)&lp[2], lpck->cksize) != (LONG)lpck->cksize)
      return AVIERR_FILEREAD;
  }

  return AVIERR_OK;
}

HRESULT FindChunkAndKeepExtras(LPEXTRACHUNKS extra,HMMIO hmmio,MMCKINFO *lpck,
			       MMCKINFO *lpckParent,UINT flags)
{
  FOURCC  ckid;
  FOURCC  fccType;
  MMRESULT mmr;

  /* pre-conditions */
  assert(extra != NULL);
  assert(hmmio != NULL);
  assert(lpck  != NULL);

  TRACE("({%p,%u},%p,%p,%p,0x%X)\n", extra->lp, extra->cb, hmmio, lpck,
	lpckParent, flags);

  /* what chunk id and form/list type should we search? */
  if (flags & MMIO_FINDCHUNK) {
    ckid    = lpck->ckid;
    fccType = 0;
  } else if (flags & MMIO_FINDLIST) {
    ckid    = FOURCC_LIST;
    fccType = lpck->fccType;
  } else if (flags & MMIO_FINDRIFF) {
    ckid    = FOURCC_RIFF;
    fccType = lpck->fccType;
  } else
    ckid = fccType = (FOURCC)-1; /* collect everything into extra! */

  TRACE(": find ckid=0x%08X fccType=0x%08X\n", ckid, fccType);

  for (;;) {
    mmr = mmioDescend(hmmio, lpck, lpckParent, 0);
    if (mmr != MMSYSERR_NOERROR) {
      /* No extra chunks in front of desired chunk? */
      if (flags == 0 && mmr == MMIOERR_CHUNKNOTFOUND)
	return AVIERR_OK;
      else
        return AVIERR_FILEREAD;
    }

    /* Have we found what we search for? */
    if ((lpck->ckid == ckid) &&
	(fccType == 0 || lpck->fccType == fccType))
      return AVIERR_OK;

    /* Skip padding chunks, the others put into the extrachunk-structure */
    if (lpck->ckid == ckidAVIPADDING ||
	lpck->ckid == mmioFOURCC('p','a','d','d'))
    {
      mmr = mmioAscend(hmmio, lpck, 0);
      if (mmr != MMSYSERR_NOERROR) return AVIERR_FILEREAD;
    }
    else
    {
      HRESULT hr = ReadChunkIntoExtra(extra, hmmio, lpck);
      if (FAILED(hr))
        return hr;
    }
  }
}

