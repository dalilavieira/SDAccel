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
typedef  int /*<<< orphan*/  usTransLength ;
typedef  int* ucArgs ;
typedef  int UINT8 ;
typedef  int UINT16 ;
typedef  int /*<<< orphan*/  INT32 ;
typedef  int /*<<< orphan*/  CHAR ;

/* Variables and functions */
 int /*<<< orphan*/  ESUCCESS ; 
 int HCI_PATCH_HEADER_SIZE ; 
 int HCI_TYPE_CMND ; 
 int HCI_TYPE_DATA ; 
 int HCI_TYPE_PATCH ; 
 int SIMPLE_LINK_HCI_CMND_HEADER_SIZE ; 
 int SIMPLE_LINK_HCI_DATA_CMND_HEADER_SIZE ; 
 int SIMPLE_LINK_HCI_DATA_HEADER_SIZE ; 
 int SIMPLE_LINK_HCI_PATCH_HEADER_SIZE ; 
 int SL_PATCH_PORTION_SIZE ; 
 int SPI_HEADER_SIZE ; 
 int /*<<< orphan*/  SpiWrite (int*,int) ; 
 int* UINT16_TO_STREAM (int*,int) ; 
 int /*<<< orphan*/  UINT8_TO_STREAM (int*,int) ; 
 int /*<<< orphan*/  memcpy (int*,int /*<<< orphan*/ *,int) ; 

UINT16 hci_command_send(UINT16 usOpcode, UINT8 *pucBuff, UINT8 ucArgsLength)
{ 
	UINT8 *stream;

	stream = (pucBuff + SPI_HEADER_SIZE);

	UINT8_TO_STREAM(stream, HCI_TYPE_CMND);
	stream = UINT16_TO_STREAM(stream, usOpcode);
	UINT8_TO_STREAM(stream, ucArgsLength);

	//Update the opcode of the event we will be waiting for
	SpiWrite(pucBuff, ucArgsLength + SIMPLE_LINK_HCI_CMND_HEADER_SIZE);

	return(0);
}

INT32 hci_data_send(UINT8 ucOpcode, 
	UINT8 *ucArgs,
	UINT16 usArgsLength, 
	UINT16 usDataLength,
	const UINT8 *ucTail,
	UINT16 usTailLength)
{
	UINT8 *stream;

	stream = ((ucArgs) + SPI_HEADER_SIZE);

	UINT8_TO_STREAM(stream, HCI_TYPE_DATA);
	UINT8_TO_STREAM(stream, ucOpcode);
	UINT8_TO_STREAM(stream, usArgsLength);
	stream = UINT16_TO_STREAM(stream, usArgsLength + usDataLength + usTailLength);

	// Send the packet over the SPI
	SpiWrite(ucArgs, SIMPLE_LINK_HCI_DATA_HEADER_SIZE + usArgsLength + usDataLength + usTailLength);

	return(ESUCCESS);
}

void hci_data_command_send(UINT16 usOpcode, UINT8 *pucBuff, UINT8 ucArgsLength,UINT16 ucDataLength)
{ 
	UINT8 *stream = (pucBuff + SPI_HEADER_SIZE);

	UINT8_TO_STREAM(stream, HCI_TYPE_DATA);
	UINT8_TO_STREAM(stream, usOpcode);
	UINT8_TO_STREAM(stream, ucArgsLength);
	stream = UINT16_TO_STREAM(stream, ucArgsLength + ucDataLength);

	// Send the command over SPI on data channel
	SpiWrite(pucBuff, ucArgsLength + ucDataLength + SIMPLE_LINK_HCI_DATA_CMND_HEADER_SIZE);

	return;
}

void hci_patch_send(UINT8 ucOpcode, UINT8 *pucBuff, CHAR *patch, UINT16 usDataLength)
{ 
	UINT8 *data_ptr = (pucBuff + SPI_HEADER_SIZE);
	UINT16 usTransLength;
	UINT8 *stream = (pucBuff + SPI_HEADER_SIZE);

	UINT8_TO_STREAM(stream, HCI_TYPE_PATCH);
	UINT8_TO_STREAM(stream, ucOpcode);
	stream = UINT16_TO_STREAM(stream, usDataLength + SIMPLE_LINK_HCI_PATCH_HEADER_SIZE);

	if (usDataLength <= SL_PATCH_PORTION_SIZE)
	{
		UINT16_TO_STREAM(stream, usDataLength);
		stream = UINT16_TO_STREAM(stream, usDataLength);
		memcpy((pucBuff + SPI_HEADER_SIZE) + HCI_PATCH_HEADER_SIZE, patch, usDataLength);

		// Update the opcode of the event we will be waiting for
		SpiWrite(pucBuff, usDataLength + HCI_PATCH_HEADER_SIZE);
	}
	else
	{

		usTransLength = (usDataLength/SL_PATCH_PORTION_SIZE);
		UINT16_TO_STREAM(stream, usDataLength + SIMPLE_LINK_HCI_PATCH_HEADER_SIZE + usTransLength*SIMPLE_LINK_HCI_PATCH_HEADER_SIZE);
		stream = UINT16_TO_STREAM(stream, SL_PATCH_PORTION_SIZE);
		memcpy(pucBuff + SPI_HEADER_SIZE + HCI_PATCH_HEADER_SIZE, patch, SL_PATCH_PORTION_SIZE);
		usDataLength -= SL_PATCH_PORTION_SIZE;
		patch += SL_PATCH_PORTION_SIZE;

		// Update the opcode of the event we will be waiting for
		SpiWrite(pucBuff, SL_PATCH_PORTION_SIZE + HCI_PATCH_HEADER_SIZE);

		while (usDataLength)
		{
			if (usDataLength <= SL_PATCH_PORTION_SIZE)
			{
				usTransLength = usDataLength;
				usDataLength = 0;

			}
			else
			{
				usTransLength = SL_PATCH_PORTION_SIZE;
				usDataLength -= usTransLength;
			}

			*(UINT16 *)data_ptr = usTransLength;
			memcpy(data_ptr + SIMPLE_LINK_HCI_PATCH_HEADER_SIZE, patch, usTransLength);
			patch += usTransLength;

			// Update the opcode of the event we will be waiting for
			SpiWrite((UINT8 *)data_ptr, usTransLength + sizeof(usTransLength));
		}
	}
}

