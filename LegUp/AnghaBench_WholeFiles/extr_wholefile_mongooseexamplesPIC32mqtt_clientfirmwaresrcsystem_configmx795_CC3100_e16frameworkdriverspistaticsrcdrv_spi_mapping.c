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
typedef  int /*<<< orphan*/  int32_t ;
typedef  int /*<<< orphan*/  SYS_STATUS ;
typedef  int SYS_MODULE_OBJ ;
typedef  int /*<<< orphan*/  SYS_MODULE_INIT ;
typedef  int SYS_MODULE_INDEX ;
typedef  int /*<<< orphan*/  DRV_SPI_CLIENT_DATA ;
typedef  int /*<<< orphan*/  DRV_SPI_BUFFER_HANDLE ;
typedef  int /*<<< orphan*/  DRV_SPI_BUFFER_EVENT_HANDLER ;
typedef  int /*<<< orphan*/  DRV_SPI_BUFFER_EVENT ;
typedef  int /*<<< orphan*/  DRV_IO_INTENT ;
typedef  int DRV_HANDLE ;

/* Variables and functions */
 int DRV_HANDLE_INVALID ; 
 int /*<<< orphan*/  DRV_SPI0_BufferAddRead (void*,size_t,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  DRV_SPI0_BufferAddRead2 (void*,size_t,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DRV_SPI0_BufferAddWrite (void*,size_t,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  DRV_SPI0_BufferAddWrite2 (void*,size_t,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DRV_SPI0_BufferAddWriteRead2 (void*,size_t,void*,size_t,int /*<<< orphan*/ ,void*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  DRV_SPI0_BufferAddWriteReadNew (void*,size_t,void*,size_t,int /*<<< orphan*/ ,void*) ; 
 int /*<<< orphan*/  DRV_SPI0_BufferStatus (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DRV_SPI0_ClientConfigure (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  DRV_SPI0_Close () ; 
 int /*<<< orphan*/  DRV_SPI0_Deinitialize () ; 
 int DRV_SPI0_Initialize () ; 
 int DRV_SPI0_Open (int const,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  DRV_SPI0_Status () ; 
 int /*<<< orphan*/  DRV_SPI0_Tasks () ; 
 int /*<<< orphan*/  DRV_SPI_BUFFER_HANDLE_INVALID ; 
#define  DRV_SPI_INDEX_0 128 
 int SYS_MODULE_OBJ_INVALID ; 
 int /*<<< orphan*/  SYS_STATUS_ERROR ; 

SYS_MODULE_OBJ DRV_SPI_Initialize(const SYS_MODULE_INDEX index,const SYS_MODULE_INIT * const init)
{
    SYS_MODULE_OBJ returnValue;

    switch(index)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_Initialize();
            break;
        }
        default:
        {
            returnValue = SYS_MODULE_OBJ_INVALID;
            break;
        }
    }
    return returnValue;
}

void DRV_SPI_Deinitialize( SYS_MODULE_OBJ object)
{
    switch(object)
    {
        case DRV_SPI_INDEX_0:
        {
            DRV_SPI0_Deinitialize();
            break;
        }
        default:
        {
            break;
        }
    }
}

SYS_STATUS DRV_SPI_Status( SYS_MODULE_OBJ object)
{
    SYS_STATUS returnValue;

    switch(object)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_Status();
            break;
        }
        default:
        {
            returnValue = SYS_STATUS_ERROR;
            break;
        }
    }
    return returnValue;
}

void DRV_SPI_Tasks ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_SPI_INDEX_0:
        {
            DRV_SPI0_Tasks();
            break;
        }
        default:
        {
            break;
        }
    }
}

DRV_HANDLE DRV_SPI_Open( const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent)
{
    DRV_HANDLE returnValue;

    switch(index)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_Open(index,ioIntent);
            break;
        }
        default:
        {
            returnValue = DRV_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

void DRV_SPI_Close( const DRV_HANDLE handle)
{
    uintptr_t instance;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            DRV_SPI0_Close( );
            break;
        }
        default:
        {
            break;
        }
    }
}

int32_t DRV_SPI_ClientConfigure ( DRV_HANDLE handle, const DRV_SPI_CLIENT_DATA * cfgData  )
{
    uintptr_t instance;
    int32_t returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_ClientConfigure( cfgData );
            break;
        }
        default:
        {
            returnValue = (int32_t)DRV_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

DRV_SPI_BUFFER_HANDLE DRV_SPI_BufferAddRead ( DRV_HANDLE handle,void *rxBuffer,size_t size,DRV_SPI_BUFFER_EVENT_HANDLER completeCB,void * context)
{
    uintptr_t instance;
    DRV_SPI_BUFFER_HANDLE returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_BufferAddRead ( rxBuffer, size, completeCB, context);
            break;
        }
        default:
        {
            returnValue = DRV_SPI_BUFFER_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

DRV_SPI_BUFFER_HANDLE DRV_SPI_BufferAddWrite ( DRV_HANDLE handle,void *txBuffer,size_t size,DRV_SPI_BUFFER_EVENT_HANDLER completeCB,void * context)
{
    uintptr_t instance;
    DRV_SPI_BUFFER_HANDLE returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_BufferAddWrite ( txBuffer, size, completeCB, context);
            break;
        }
        default:
        {
            returnValue = DRV_SPI_BUFFER_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

DRV_SPI_BUFFER_HANDLE DRV_SPI_BufferAddWriteRead ( DRV_HANDLE handle, void *txBuffer, size_t txSize,
    void *rxBuffer, size_t rxSize, DRV_SPI_BUFFER_EVENT_HANDLER completeCB, void * context )
{
    uintptr_t instance;
    DRV_SPI_BUFFER_HANDLE returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    //Mapping to a new static driver's API name.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_BufferAddWriteReadNew ( txBuffer, txSize, rxBuffer, rxSize, completeCB, context );
            break;
        }
        default:
        {
            returnValue = DRV_SPI_BUFFER_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

DRV_SPI_BUFFER_HANDLE DRV_SPI_BufferAddRead2 ( DRV_HANDLE handle,void *rxBuffer,size_t size,DRV_SPI_BUFFER_EVENT_HANDLER completeCB,void * context, DRV_SPI_BUFFER_HANDLE * jobHandle)
{
    uintptr_t instance;
    DRV_SPI_BUFFER_HANDLE returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_BufferAddRead2 ( rxBuffer, size, completeCB, context, jobHandle);
            break;
        }
        default:
        {
            returnValue = DRV_SPI_BUFFER_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

DRV_SPI_BUFFER_HANDLE DRV_SPI_BufferAddWrite2 ( DRV_HANDLE handle,void *txBuffer,size_t size,DRV_SPI_BUFFER_EVENT_HANDLER completeCB,void * context, DRV_SPI_BUFFER_HANDLE * jobHandle)
{
    uintptr_t instance;
    DRV_SPI_BUFFER_HANDLE returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_BufferAddWrite2 ( txBuffer, size, completeCB, context, jobHandle);
            break;
        }
        default:
        {
            returnValue = DRV_SPI_BUFFER_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

DRV_SPI_BUFFER_HANDLE DRV_SPI_BufferAddWriteRead2 ( DRV_HANDLE handle, void *txBuffer, size_t txSize,void *rxBuffer, size_t rxSize,DRV_SPI_BUFFER_EVENT_HANDLER completeCB,void * context, DRV_SPI_BUFFER_HANDLE * jobHandle)
{
    uintptr_t instance;
    DRV_SPI_BUFFER_HANDLE returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_SPI_INDEX_0:
        {
            returnValue = DRV_SPI0_BufferAddWriteRead2 ( txBuffer, txSize, rxBuffer, rxSize, completeCB, context, jobHandle);
            break;
        }
        default:
        {
            returnValue = DRV_SPI_BUFFER_HANDLE_INVALID;
            break;
        }
    }
    return returnValue;
}

DRV_SPI_BUFFER_EVENT DRV_SPI_BufferStatus ( DRV_SPI_BUFFER_HANDLE bufferHandle )
{
    //This function is independent of instance or client.
    return DRV_SPI0_BufferStatus ( bufferHandle);
}

