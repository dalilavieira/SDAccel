#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ UINT8 ;
typedef  scalar_t__ UINT32 ;
typedef  scalar_t__ UINT16 ;
struct TYPE_2__ {scalar_t__* pucTxCommandBuffer; } ;
typedef  scalar_t__ INT32 ;

/* Variables and functions */
 scalar_t__ EFAIL ; 
 int /*<<< orphan*/  HCI_CMND_NVMEM_CREATE_ENTRY ; 
 int /*<<< orphan*/  HCI_CMND_NVMEM_READ ; 
 int /*<<< orphan*/  HCI_CMND_NVMEM_WRITE ; 
 int /*<<< orphan*/  HCI_CMND_READ_SP_VERSION ; 
 int HCI_DATA_CMD_HEADER_SIZE ; 
 int /*<<< orphan*/  HCI_EVNT_NVMEM_WRITE ; 
 int HEADERS_SIZE_CMD ; 
 scalar_t__ MAC_ADDR_LEN ; 
 int /*<<< orphan*/  NVMEM_CREATE_PARAMS_LEN ; 
 scalar_t__ NVMEM_MAC_FILEID ; 
 int /*<<< orphan*/  NVMEM_READ_PARAMS_LEN ; 
 int NVMEM_WRITE_PARAMS_LEN ; 
 int SPI_HEADER_SIZE ; 
 scalar_t__ SP_PORTION_SIZE ; 
 int /*<<< orphan*/  SimpleLinkWaitData (scalar_t__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SimpleLinkWaitEvent (int /*<<< orphan*/ ,scalar_t__*) ; 
 scalar_t__* UINT32_TO_STREAM (scalar_t__*,scalar_t__) ; 
 int /*<<< orphan*/  hci_command_send (int /*<<< orphan*/ ,scalar_t__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hci_data_command_send (int /*<<< orphan*/ ,scalar_t__*,int,scalar_t__) ; 
 int /*<<< orphan*/  memcpy (scalar_t__*,scalar_t__*,scalar_t__) ; 
 TYPE_1__ tSLInformation ; 

INT32 nvmem_read(UINT32 ulFileId, UINT32 ulLength, UINT32 ulOffset, UINT8 *buff)
{
	UINT8 ucStatus = 0xFF;
	UINT8 *ptr;
	UINT8 *args;

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (ptr + HEADERS_SIZE_CMD);

	// Fill in HCI packet structure
	args = UINT32_TO_STREAM(args, ulFileId);
	args = UINT32_TO_STREAM(args, ulLength);
	args = UINT32_TO_STREAM(args, ulOffset);

	// Initiate a HCI command
	hci_command_send(HCI_CMND_NVMEM_READ, ptr, NVMEM_READ_PARAMS_LEN);
	SimpleLinkWaitEvent(HCI_CMND_NVMEM_READ, &ucStatus);

	// In case there is data - read it - even if an error code is returned
	// Note: It is the user responsibility to ignore the data in case of an error code

	// Wait for the data in a synchronous way. Here we assume that the buffer is 
	// big enough to store also parameters of nvmem

	SimpleLinkWaitData(buff, 0, 0);

	return(ucStatus);
}

INT32 nvmem_write(UINT32 ulFileId, UINT32 ulLength, UINT32 ulEntryOffset, UINT8 *buff)
{
	INT32 iRes;
	UINT8 *ptr;
	UINT8 *args;

	iRes = EFAIL;

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (ptr + SPI_HEADER_SIZE + HCI_DATA_CMD_HEADER_SIZE);

	// Fill in HCI packet structure
	args = UINT32_TO_STREAM(args, ulFileId);
	args = UINT32_TO_STREAM(args, 12);
	args = UINT32_TO_STREAM(args, ulLength);
	args = UINT32_TO_STREAM(args, ulEntryOffset);

	memcpy((ptr + SPI_HEADER_SIZE + HCI_DATA_CMD_HEADER_SIZE + 
		NVMEM_WRITE_PARAMS_LEN),buff,ulLength);

	// Initiate a HCI command but it will come on data channel
	hci_data_command_send(HCI_CMND_NVMEM_WRITE, ptr, NVMEM_WRITE_PARAMS_LEN,
		ulLength);

	SimpleLinkWaitEvent(HCI_EVNT_NVMEM_WRITE, &iRes);

	return(iRes);
}

UINT8 nvmem_set_mac_address(UINT8 *mac)
{
	return  nvmem_write(NVMEM_MAC_FILEID, MAC_ADDR_LEN, 0, mac);
}

UINT8 nvmem_get_mac_address(UINT8 *mac)
{
	return  nvmem_read(NVMEM_MAC_FILEID, MAC_ADDR_LEN, 0, mac);
}

UINT8 nvmem_write_patch(UINT32 ulFileId, UINT32 spLength, const UINT8 *spData)
{
	UINT8 	status = 0;
	UINT16	offset = 0;
	UINT8*      spDataPtr = (UINT8*)spData;

	while ((status == 0) && (spLength >= SP_PORTION_SIZE))
	{
		status = nvmem_write(ulFileId, SP_PORTION_SIZE, offset, spDataPtr);
		offset += SP_PORTION_SIZE;
		spLength -= SP_PORTION_SIZE;
		spDataPtr += SP_PORTION_SIZE;
	}

	if (status !=0)
	{
		// NVMEM error occurred
		return status;
	}

	if (spLength != 0)
	{
		// if reached here, a reminder is left
		status = nvmem_write(ulFileId, spLength, offset, spDataPtr);
	}

	return status;
}

UINT8 nvmem_read_sp_version(UINT8* patchVer)
{
	UINT8 *ptr;
	// 1st byte is the status and the rest is the SP version
	UINT8	retBuf[5];	

	ptr = tSLInformation.pucTxCommandBuffer;

	// Initiate a HCI command, no args are required
	hci_command_send(HCI_CMND_READ_SP_VERSION, ptr, 0);	
	SimpleLinkWaitEvent(HCI_CMND_READ_SP_VERSION, retBuf);

	// package ID
	*patchVer = retBuf[3];			
	// package build number
	*(patchVer+1) = retBuf[4];		

	return(retBuf[0]);
}

INT32 nvmem_create_entry(UINT32 ulFileId, UINT32 ulNewLen)
{
	UINT8 *ptr; 
	UINT8 *args;
	UINT8 retval;

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (ptr + HEADERS_SIZE_CMD);

	// Fill in HCI packet structure
	args = UINT32_TO_STREAM(args, ulFileId);
	args = UINT32_TO_STREAM(args, ulNewLen);

	// Initiate a HCI command
	hci_command_send(HCI_CMND_NVMEM_CREATE_ENTRY,ptr, NVMEM_CREATE_PARAMS_LEN);

	SimpleLinkWaitEvent(HCI_CMND_NVMEM_CREATE_ENTRY, &retval);

	return(retval);
}

