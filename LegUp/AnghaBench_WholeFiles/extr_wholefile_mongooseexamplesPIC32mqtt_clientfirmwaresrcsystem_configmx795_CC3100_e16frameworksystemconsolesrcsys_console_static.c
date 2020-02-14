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
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  consoleCallbackFunction ;
typedef  int /*<<< orphan*/  SYS_STATUS ;
typedef  int SYS_MODULE_OBJ ;
typedef  int /*<<< orphan*/  SYS_MODULE_INIT ;
typedef  int /*<<< orphan*/  SYS_MODULE_INDEX ;
typedef  int /*<<< orphan*/  SYS_CONSOLE_EVENT ;

/* Variables and functions */
 char DRV_USART0_ReadByte () ; 
 int /*<<< orphan*/  DRV_USART0_ReceiverBufferIsEmpty () ; 
 int /*<<< orphan*/  DRV_USART0_WriteByte (char const) ; 
 int /*<<< orphan*/  SYS_STATUS_READY ; 

SYS_MODULE_OBJ SYS_CONSOLE_Initialize( const SYS_MODULE_INDEX index, const SYS_MODULE_INIT * const init )
{
    return 1;
}

bool SYS_CONSOLE_Reinitialize( SYS_MODULE_OBJ object, const SYS_MODULE_INIT * const init )
{
    return true;
}

bool SYS_CONSOLE_Deinitialize ( SYS_MODULE_OBJ object )
{
    return true;
}

SYS_STATUS SYS_CONSOLE_Status ( SYS_MODULE_OBJ object )
{
    return SYS_STATUS_READY;
}

void SYS_CONSOLE_Tasks ( SYS_MODULE_OBJ object )
{
}

ssize_t SYS_CONSOLE_Read(const SYS_MODULE_INDEX index, int fd, void *buf, size_t count )
{
    size_t  numBytes = 0;
    char* pReadByte = (char*)buf;
	if( !DRV_USART0_ReceiverBufferIsEmpty() )
	{
		*pReadByte = DRV_USART0_ReadByte();

		numBytes++;
		pReadByte++;
    }

    return numBytes;
}

ssize_t SYS_CONSOLE_Write(const SYS_MODULE_INDEX index, int fd, const char *buf, size_t count )
{
    size_t numBytes = 0;
    while( numBytes < count )
    {
        DRV_USART0_WriteByte(buf[numBytes++]);
    }
    return count;
}

void SYS_CONSOLE_RegisterCallback(const SYS_MODULE_INDEX index, consoleCallbackFunction cbFunc, SYS_CONSOLE_EVENT event)
{
}

void SYS_CONSOLE_Flush(const SYS_MODULE_INDEX index)
{
}

