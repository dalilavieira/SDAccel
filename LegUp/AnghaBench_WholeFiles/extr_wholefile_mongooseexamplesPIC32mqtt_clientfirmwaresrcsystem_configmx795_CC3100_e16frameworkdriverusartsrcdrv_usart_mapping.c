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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  SYS_STATUS ;
typedef  int SYS_MODULE_OBJ ;
typedef  int /*<<< orphan*/  SYS_MODULE_INIT ;
typedef  int SYS_MODULE_INDEX ;
typedef  int /*<<< orphan*/  DRV_USART_TRANSFER_STATUS ;
typedef  int /*<<< orphan*/  DRV_USART_LINE_CONTROL_SET_RESULT ;
typedef  int /*<<< orphan*/  DRV_USART_LINE_CONTROL ;
typedef  int /*<<< orphan*/  DRV_USART_CLIENT_STATUS ;
typedef  int /*<<< orphan*/  DRV_USART_BAUD_SET_RESULT ;
typedef  int /*<<< orphan*/  DRV_IO_INTENT ;
typedef  int DRV_HANDLE ;

/* Variables and functions */
 int /*<<< orphan*/  DRV_CLIENT_STATUS_ERROR ; 
 int DRV_HANDLE_INVALID ; 
 int /*<<< orphan*/  DRV_USART0_BaudSet (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DRV_USART0_ClientStatus () ; 
 int /*<<< orphan*/  DRV_USART0_Close () ; 
 int /*<<< orphan*/  DRV_USART0_Deinitialize () ; 
 int DRV_USART0_Initialize () ; 
 int /*<<< orphan*/  DRV_USART0_LineControlSet (int /*<<< orphan*/  const) ; 
 int DRV_USART0_Open (int const,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  DRV_USART0_ReadByte () ; 
 int DRV_USART0_ReceiverBufferIsEmpty () ; 
 unsigned int DRV_USART0_ReceiverBufferSizeGet () ; 
 int /*<<< orphan*/  DRV_USART0_Status () ; 
 int /*<<< orphan*/  DRV_USART0_TasksError () ; 
 int /*<<< orphan*/  DRV_USART0_TasksReceive () ; 
 int /*<<< orphan*/  DRV_USART0_TasksTransmit () ; 
 int /*<<< orphan*/  DRV_USART0_TransferStatus () ; 
 int DRV_USART0_TransmitBufferIsFull () ; 
 unsigned int DRV_USART0_TransmitBufferSizeGet () ; 
 int /*<<< orphan*/  DRV_USART0_WriteByte (int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  DRV_USART_BAUD_SET_ERROR ; 
#define  DRV_USART_INDEX_0 128 
 int /*<<< orphan*/  DRV_USART_LINE_CONTROL_SET_ERROR ; 
 int /*<<< orphan*/  SYS_ASSERT (int,char*) ; 
 int SYS_MODULE_OBJ_INVALID ; 
 int /*<<< orphan*/  SYS_STATUS_ERROR ; 

SYS_MODULE_OBJ DRV_USART_Initialize(const SYS_MODULE_INDEX index,const SYS_MODULE_INIT * const init)
{
    SYS_MODULE_OBJ returnValue;

    switch(index)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Initialize();
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

void DRV_USART_Deinitialize( SYS_MODULE_OBJ object)
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_Deinitialize();
            break;
        }
        default:
        {
            break;
        }
    }
}

SYS_STATUS DRV_USART_Status( SYS_MODULE_OBJ object)
{
    SYS_STATUS returnValue;

    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Status();
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

void DRV_USART_TasksTransmit ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_TasksTransmit();
            break;
        }
        default:
        {
            break;
        }
    }
}

void DRV_USART_TasksReceive ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_TasksReceive();
            break;
        }
        default:
        {
            break;
        }
    }
}

void DRV_USART_TasksError ( SYS_MODULE_OBJ object )
{
    switch(object)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_TasksError();
            break;
        }
        default:
        {
            break;
        }
    }
}

DRV_HANDLE DRV_USART_Open( const SYS_MODULE_INDEX index, const DRV_IO_INTENT ioIntent)
{
    DRV_HANDLE returnValue;

    switch(index)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_Open(index,ioIntent);
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

void DRV_USART_Close( const DRV_HANDLE handle)
{
    uintptr_t instance;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_Close();
            break;
        }
        default:
        {
            break;
        }
    }
}

DRV_USART_CLIENT_STATUS DRV_USART_ClientStatus ( DRV_HANDLE handle )
{
    uintptr_t instance;
    DRV_USART_CLIENT_STATUS returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_ClientStatus();
            break;
        }
        default:
        {
            returnValue = DRV_CLIENT_STATUS_ERROR;
            break;
        }
    }
    return returnValue;
}

DRV_USART_TRANSFER_STATUS DRV_USART_TransferStatus( const DRV_HANDLE handle )
{
    uintptr_t instance;
    DRV_USART_TRANSFER_STATUS returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_TransferStatus();
            break;
        }
        default:
        {
            returnValue = (DRV_USART_TRANSFER_STATUS)NULL;
            break;
        }
    }
    return returnValue;
}

uint8_t DRV_USART_ReadByte( const DRV_HANDLE handle )
{
    uintptr_t instance;
    uint8_t returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_ReadByte();
            break;
        }
        default:
        {
            SYS_ASSERT(false, "Incorrect Driver Handle");
            returnValue = 0;
            break;
        }
    }
    return returnValue;
}

void DRV_USART_WriteByte( const DRV_HANDLE handle, const uint8_t byte)
{
    uintptr_t instance;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            DRV_USART0_WriteByte(byte);
            break;
        }
        default:
        {
            break;
        }
    }
}

unsigned int DRV_USART_ReceiverBufferSizeGet( const DRV_HANDLE handle )
{
    uintptr_t instance;
    unsigned int returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_ReceiverBufferSizeGet();
            break;
        }
        default:
        {
            returnValue = (unsigned int)NULL;
            break;
        }
    }
    return returnValue;
}

unsigned int DRV_USART_TransmitBufferSizeGet( const DRV_HANDLE handle )
{
    uintptr_t instance;
    unsigned int returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_TransmitBufferSizeGet();
            break;
        }
        default:
        {
            returnValue = (unsigned int)NULL;
            break;
        }
    }
    return returnValue;
}

bool DRV_USART_ReceiverBufferIsEmpty( const DRV_HANDLE handle )
{
    uintptr_t instance;
    bool returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_ReceiverBufferIsEmpty();
            break;
        }
        default:
        {
            returnValue = false;
            break;
        }
    }
    return returnValue;
}

bool DRV_USART_TransmitBufferIsFull( const DRV_HANDLE handle )
{
    uintptr_t instance;
    bool returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_TransmitBufferIsFull();
            break;
        }
        default:
        {
            returnValue = false;
            break;
        }
    }
    return returnValue;
}

DRV_USART_BAUD_SET_RESULT DRV_USART_BaudSet(const DRV_HANDLE handle, uint32_t baud)
{
    uintptr_t instance;
    DRV_USART_BAUD_SET_RESULT returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_BaudSet(baud);
            break;
        }
        default:
        {
            returnValue = DRV_USART_BAUD_SET_ERROR;
            break;
        }
    }
    return returnValue;
}

DRV_USART_LINE_CONTROL_SET_RESULT DRV_USART_LineControlSet(const DRV_HANDLE handle,const DRV_USART_LINE_CONTROL lineControl)
{
    uintptr_t instance;
    DRV_USART_LINE_CONTROL_SET_RESULT returnValue;

    instance = handle & 0x00FF;
    //As we are handling single client, only multiple instance is taken care.
    switch(instance)
    {
        case DRV_USART_INDEX_0:
        {
            returnValue = DRV_USART0_LineControlSet(lineControl);
            break;
        }
        default:
        {
            returnValue = DRV_USART_LINE_CONTROL_SET_ERROR;
            break;
        }
    }
    return returnValue;
}

