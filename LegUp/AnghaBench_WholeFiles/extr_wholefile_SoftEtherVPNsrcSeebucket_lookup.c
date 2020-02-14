#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8 ;
typedef  int uint32 ;
typedef  scalar_t__ uint16 ;
struct timeval {int dummy; } ;
struct time_conv {int dummy; } ;
struct TYPE_10__ {int /*<<< orphan*/ * buffer; } ;
struct TYPE_9__ {int /*<<< orphan*/  exec_fcn; int /*<<< orphan*/  block; } ;
struct TYPE_8__ {int key_len; int filled_blocks; int block_size; int filled_entries; int shared_memory_blocks; int lut_entries; int default_exec; int /*<<< orphan*/ * shared_memory_base_address; int /*<<< orphan*/ * lut_base_address; int /*<<< orphan*/ * last_found; } ;
typedef  TYPE_1__ TME_DATA ;
typedef  TYPE_2__ RECORD ;
typedef  TYPE_3__ MEM_TYPE ;

/* Variables and functions */
 int /*<<< orphan*/  COPY_MEMORY (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  GET_TIME (struct timeval*,struct time_conv*) ; 
 int /*<<< orphan*/  SW_ULONG_ASSIGN (int /*<<< orphan*/ *,int) ; 
 int SW_ULONG_AT (int /*<<< orphan*/ *,int) ; 
 scalar_t__ SW_USHORT_AT (int /*<<< orphan*/ *,int) ; 
 int TME_ERROR ; 
 int TME_FALSE ; 
 int TME_TRUE ; 

uint32 bucket_lookup(uint8 *key, TME_DATA *data, MEM_TYPE *mem_ex, struct time_conv *time_ref)  
{
	uint32 value;
	uint32 i,j;
	int found=-1;
	uint32 blocks;
	uint32 block_size;
	uint8 *temp;
	if ((data->key_len!=1)&&  /*16 bit value*/
		(data->key_len!=2))   /*32 bit value*/
		return TME_ERROR;
	
	/*32 bit values*/
	blocks=data->filled_blocks-1;
	block_size=data->block_size;
	i=blocks/2; /*relative shift*/
	j=i;
	temp=data->shared_memory_base_address+block_size;

	if (data->key_len==2)
	{
		value=SW_ULONG_AT(key,0);
	
		if((value<SW_ULONG_AT(temp,0))||(value>SW_ULONG_AT(temp+block_size*(blocks-1),4)))
		{
			uint32 *key32=(uint32*) key;
			key32[0]=key32[1]=0;

			GET_TIME((struct timeval *)(data->shared_memory_base_address+8),time_ref);

			data->last_found=NULL;
			return TME_FALSE;
		}
			
		while(found==-1) /* search routine */
		{   
			i=(i==1)? 1:i>>1;
			if (SW_ULONG_AT(temp+block_size*j,0)>value)
				if (SW_ULONG_AT(temp+block_size*(j-1),4)<value)
					found=-2;
				else
					j-=i;
			else
				if (SW_ULONG_AT(temp+block_size*j,4)<value) 
					if (SW_ULONG_AT(temp+block_size*j,0)>value)
						found=-2;
					else
						j+=i;
				else found=j;
		}	
		if (found<0)
		{
			uint32 *key32=(uint32*) key;
			key32[0]=key32[1]=0;

			GET_TIME((struct timeval *)(data->shared_memory_base_address+8),time_ref);
			
			data->last_found=NULL;
			return TME_FALSE;
		}
	
		data->last_found=data->lut_base_address+found*sizeof(RECORD);

		COPY_MEMORY(key,temp+block_size*found,8);

		GET_TIME((struct timeval *)(temp+block_size*found+8),time_ref);

		return TME_TRUE;
	}
	else
	{
		value=SW_USHORT_AT(key,0);
	
		if((value<SW_USHORT_AT(temp,0))||(value>SW_USHORT_AT(temp+block_size*(blocks-1),2)))
		{
			uint16 *key16=(uint16*) key;
			key16[0]=key16[1]=0;
			
			GET_TIME((struct timeval *)(data->shared_memory_base_address+4),time_ref);

			data->last_found=NULL;
			return TME_FALSE;
		}
			
		while(found==-1) /* search routine */
		{   
			i=(i==1)? 1:i>>1;
			if (SW_USHORT_AT(temp+block_size*j,0)>value)
				if (SW_USHORT_AT(temp+block_size*(j-1),2)<value)
					found=-2;
				else
					j-=i;
			else
				if (SW_USHORT_AT(temp+block_size*j,2)<value) 
					if (SW_USHORT_AT(temp+block_size*j,0)>value)
						found=-2;
					else
						j+=i;
				else found=j;
		}	

		if (found<0)
		{
			uint16 *key16=(uint16*) key;
			key16[0]=key16[1]=0;

			GET_TIME((struct timeval *)(data->shared_memory_base_address+4),time_ref);

			data->last_found=NULL;
			return TME_FALSE;
		}
	
		data->last_found=data->lut_base_address+found*sizeof(RECORD);

		GET_TIME((struct timeval *)(temp+block_size*found+4),time_ref);

		COPY_MEMORY(key,temp+block_size*found,4);
		
		return TME_TRUE;
	}
		
}

uint32 bucket_lookup_insert(uint8 *key, TME_DATA *data, MEM_TYPE *mem_ex, struct time_conv *time_ref)   
{	
	RECORD *records=(RECORD*)data->lut_base_address;

	if ((data->key_len!=1)&&  /*16 bit value*/
		(data->key_len!=2))   /*32 bit value*/
		return TME_ERROR;

	if(data->key_len==2)
	{
		uint32 start,stop;
		uint8 *tmp;

		start=SW_ULONG_AT(key,0);	
		stop=SW_ULONG_AT(key,4);

		if (start>stop)
			return TME_ERROR;
		if (data->filled_entries>0)
		{
			tmp=mem_ex->buffer+SW_ULONG_AT(&records[data->filled_entries-1].block,0);		
			/*check if it is coherent with the previous block*/
			if (SW_ULONG_AT(tmp,4)>=start)
				return TME_ERROR;
		}
		
		if (data->filled_blocks==data->shared_memory_blocks)
			return TME_ERROR;

		if (data->filled_entries==data->lut_entries)
			return TME_ERROR;

		tmp=data->shared_memory_base_address+data->block_size*data->filled_blocks;		
		
		COPY_MEMORY(tmp,key,8);
		
		SW_ULONG_ASSIGN(&records[data->filled_entries].block,tmp-mem_ex->buffer);
		SW_ULONG_ASSIGN(&records[data->filled_entries].exec_fcn,data->default_exec);
		
		GET_TIME((struct timeval *)(tmp+8),time_ref);		
		
		data->filled_blocks++;
		data->filled_entries++;
		
		return TME_TRUE;
	}
	else
	{
		uint16 start,stop;
		uint8 *tmp;

		start=SW_USHORT_AT(key,0);	
		stop=SW_USHORT_AT(key,2);

		if (start>stop)
			return TME_ERROR;
		if (data->filled_entries>0)
		{
			tmp=mem_ex->buffer+SW_ULONG_AT(&records[data->filled_entries-1].block,0);		
			/*check if it is coherent with the previous block*/
			if (SW_USHORT_AT(tmp,2)>=start)
				return TME_ERROR;
		}
		
		if (data->filled_blocks==data->shared_memory_blocks)
			return TME_ERROR;

		if (data->filled_entries==data->lut_entries)
			return TME_ERROR;

		tmp=mem_ex->buffer+SW_ULONG_AT(&records[data->filled_entries].block,0);		
		
		COPY_MEMORY(tmp,key,4);
		
		SW_ULONG_ASSIGN(&records[data->filled_entries].block,tmp-mem_ex->buffer);
		SW_ULONG_ASSIGN(&records[data->filled_entries].exec_fcn,data->default_exec);
		
		GET_TIME((struct timeval *)(tmp+4),time_ref);		
		
		data->filled_blocks++;
		data->filled_entries++;
		
		return TME_TRUE;
	}
}

