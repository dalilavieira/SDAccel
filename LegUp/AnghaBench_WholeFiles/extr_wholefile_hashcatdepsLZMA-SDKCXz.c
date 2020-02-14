#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int UInt64 ;
struct TYPE_9__ {unsigned int mode; int /*<<< orphan*/  sha; int /*<<< orphan*/  crc64; int /*<<< orphan*/  crc; } ;
struct TYPE_8__ {int /*<<< orphan*/ * blocks; scalar_t__ numBlocks; scalar_t__ flags; } ;
typedef  int /*<<< orphan*/  ISzAllocPtr ;
typedef  int /*<<< orphan*/  CXzStreamFlags ;
typedef  TYPE_1__ CXzStream ;
typedef  TYPE_2__ CXzCheck ;
typedef  int Byte ;

/* Variables and functions */
 int CRC64_GET_DIGEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRC64_INIT_VAL ; 
 int /*<<< orphan*/  CRC_GET_DIGEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CRC_INIT_VAL ; 
 int /*<<< orphan*/  Crc64Update (int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  CrcUpdate (int /*<<< orphan*/ ,void const*,size_t) ; 
 int /*<<< orphan*/  ISzAlloc_Free (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SetUi32 (int*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Sha256_Final (int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  Sha256_Init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Sha256_Update (int /*<<< orphan*/ *,int const*,size_t) ; 
#define  XZ_CHECK_CRC32 130 
#define  XZ_CHECK_CRC64 129 
#define  XZ_CHECK_SHA256 128 
 unsigned int XzFlags_GetCheckType (int /*<<< orphan*/ ) ; 

unsigned Xz_WriteVarInt(Byte *buf, UInt64 v)
{
  unsigned i = 0;
  do
  {
    buf[i++] = (Byte)((v & 0x7F) | 0x80);
    v >>= 7;
  }
  while (v != 0);
  buf[(size_t)i - 1] &= 0x7F;
  return i;
}

void Xz_Construct(CXzStream *p)
{
  p->numBlocks = 0;
  p->blocks = NULL;
  p->flags = 0;
}

void Xz_Free(CXzStream *p, ISzAllocPtr alloc)
{
  ISzAlloc_Free(alloc, p->blocks);
  p->numBlocks = 0;
  p->blocks = NULL;
}

unsigned XzFlags_GetCheckSize(CXzStreamFlags f)
{
  unsigned t = XzFlags_GetCheckType(f);
  return (t == 0) ? 0 : (4 << ((t - 1) / 3));
}

void XzCheck_Init(CXzCheck *p, unsigned mode)
{
  p->mode = mode;
  switch (mode)
  {
    case XZ_CHECK_CRC32: p->crc = CRC_INIT_VAL; break;
    case XZ_CHECK_CRC64: p->crc64 = CRC64_INIT_VAL; break;
    case XZ_CHECK_SHA256: Sha256_Init(&p->sha); break;
  }
}

void XzCheck_Update(CXzCheck *p, const void *data, size_t size)
{
  switch (p->mode)
  {
    case XZ_CHECK_CRC32: p->crc = CrcUpdate(p->crc, data, size); break;
    case XZ_CHECK_CRC64: p->crc64 = Crc64Update(p->crc64, data, size); break;
    case XZ_CHECK_SHA256: Sha256_Update(&p->sha, (const Byte *)data, size); break;
  }
}

int XzCheck_Final(CXzCheck *p, Byte *digest)
{
  switch (p->mode)
  {
    case XZ_CHECK_CRC32:
      SetUi32(digest, CRC_GET_DIGEST(p->crc));
      break;
    case XZ_CHECK_CRC64:
    {
      int i;
      UInt64 v = CRC64_GET_DIGEST(p->crc64);
      for (i = 0; i < 8; i++, v >>= 8)
        digest[i] = (Byte)(v & 0xFF);
      break;
    }
    case XZ_CHECK_SHA256:
      Sha256_Final(&p->sha, digest);
      break;
    default:
      return 0;
  }
  return 1;
}

