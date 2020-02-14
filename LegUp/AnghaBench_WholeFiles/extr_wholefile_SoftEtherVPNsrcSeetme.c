#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8 ;
typedef  int uint32 ;
typedef  int uint16 ;
struct timeval {scalar_t__ tv_sec; } ;
struct time_conv {struct timeval* start; } ;
typedef  int int32 ;
typedef  int int16 ;
typedef  int /*<<< orphan*/  VOID ;
struct TYPE_4__ {scalar_t__ tv_sec; } ;
struct TYPE_5__ {scalar_t__ enable_deletion; scalar_t__ filled_entries; scalar_t__ max_fill_state; TYPE_1__ last_read; } ;
typedef  TYPE_2__ TME_DATA ;

/* Variables and functions */
 scalar_t__ DELTA_READ ; 
 scalar_t__ FALSE ; 
 int TRUE ; 

__inline int32 SW_LONG_AT(void *b, uint32 c)
{
	return	((int32)*((uint8 *)b+c)<<24|
		 (int32)*((uint8 *)b+c+1)<<16|
		 (int32)*((uint8 *)b+c+2)<<8|
		 (int32)*((uint8 *)b+c+3)<<0);
}

__inline uint32 SW_ULONG_AT(void *b, uint32 c)
{
	return	((uint32)*((uint8 *)b+c)<<24|
		 (uint32)*((uint8 *)b+c+1)<<16|
		 (uint32)*((uint8 *)b+c+2)<<8|
		 (uint32)*((uint8 *)b+c+3)<<0);
}

__inline int16 SW_SHORT_AT(void *b, uint32 os)
{
	return ((int16)
		((int16)*((uint8 *)b+os+0)<<8|
		 (int16)*((uint8 *)b+os+1)<<0));
}

__inline uint16 SW_USHORT_AT(void *b, uint32 os)
{
	return ((uint16)
		((uint16)*((uint8 *)b+os+0)<<8|
		 (uint16)*((uint8 *)b+os+1)<<0));
}

__inline VOID SW_ULONG_ASSIGN(void *dst, uint32 src)
{
	*((uint8*)dst+0)=*((uint8*)&src+3);
	*((uint8*)dst+1)=*((uint8*)&src+2);
	*((uint8*)dst+2)=*((uint8*)&src+1);
	*((uint8*)dst+3)=*((uint8*)&src+0);

}

__inline void FORCE_TIME(struct timeval *src, struct time_conv *dest)
{
	dest->start[0]=*src;
}

__inline void GET_TIME(struct timeval *dst, struct time_conv *data)
{
	return;
	*dst=data->start[0];
}

__attribute__((used)) static __inline int32 IS_DELETABLE(void *timestamp, TME_DATA *data)
{
	struct timeval *ts=(struct timeval*)timestamp;

	if (data->enable_deletion==FALSE)
		return FALSE;
	if (data->filled_entries<data->max_fill_state)
		return FALSE;
	if ((ts->tv_sec+DELTA_READ)<data->last_read.tv_sec)
		return TRUE;
	return FALSE;
}

