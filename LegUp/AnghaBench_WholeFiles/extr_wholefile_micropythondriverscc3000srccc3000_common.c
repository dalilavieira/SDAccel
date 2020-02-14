#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  void* UINT8 ;
typedef  int UINT32 ;
typedef  int UINT16 ;
typedef  scalar_t__ CHAR ;

/* Variables and functions */

void __error__(CHAR *pcFilename, UINT32 ulLine)
{
	//TODO full up function
}

UINT8* UINT32_TO_STREAM_f (UINT8 *p, UINT32 u32)
{
	*(p)++ = (UINT8)(u32);
	*(p)++ = (UINT8)((u32) >> 8);
	*(p)++ = (UINT8)((u32) >> 16);
	*(p)++ = (UINT8)((u32) >> 24);
	return p;
}

UINT8* UINT16_TO_STREAM_f (UINT8 *p, UINT16 u16)
{
	*(p)++ = (UINT8)(u16);
	*(p)++ = (UINT8)((u16) >> 8);
	return p;
}

UINT16 STREAM_TO_UINT16_f(CHAR* p, UINT16 offset)
{
	return (UINT16)((UINT16)((UINT16)
		(*(p + offset + 1)) << 8) + (UINT16)(*(p + offset)));
}

UINT32 STREAM_TO_UINT32_f(CHAR* p, UINT16 offset)
{
	return (UINT32)((UINT32)((UINT32)
		(*(p + offset + 3)) << 24) + (UINT32)((UINT32)
		(*(p + offset + 2)) << 16) + (UINT32)((UINT32)
		(*(p + offset + 1)) << 8) + (UINT32)(*(p + offset)));
}

