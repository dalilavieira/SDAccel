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
typedef  int /*<<< orphan*/  (* tWriteWlanPin ) (int /*<<< orphan*/ ) ;
typedef  scalar_t__ (* tWlanReadInteruptPin ) () ;
typedef  int /*<<< orphan*/  tWlanInterruptEnable ;
typedef  int /*<<< orphan*/  tWlanInterruptDisable ;
typedef  int /*<<< orphan*/  tWlanCB ;
typedef  int /*<<< orphan*/  tFWPatches ;
typedef  int /*<<< orphan*/  tDriverPatches ;
typedef  int /*<<< orphan*/  tBootLoaderPatches ;
typedef  scalar_t__ UINT8 ;
typedef  scalar_t__ UINT32 ;
typedef  int UINT16 ;
struct TYPE_2__ {scalar_t__* pucTxCommandBuffer; scalar_t__ (* ReadWlanInterruptPin ) () ;int InformHostOnTxComplete; int usEventOrDataReceived; scalar_t__* pucReceivedData; int /*<<< orphan*/  (* WriteWlanPin ) (int /*<<< orphan*/ ) ;scalar_t__ slTransmitDataError; scalar_t__ usRxDataPending; scalar_t__ usBufferSize; scalar_t__ usSlBufferLength; scalar_t__ usNumberOfFreeBuffers; scalar_t__ usRxEventOpcode; scalar_t__ NumberOfReleasedPackets; scalar_t__ NumberOfSentPackets; int /*<<< orphan*/  sWlanCB; int /*<<< orphan*/  WlanInterruptDisable; int /*<<< orphan*/  WlanInterruptEnable; int /*<<< orphan*/  sBootLoaderPatches; int /*<<< orphan*/  sDriverPatches; int /*<<< orphan*/  sFWPatches; } ;
typedef  int INT32 ;
typedef  scalar_t__ CHAR ;
typedef  int CC3000_EXPORT ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_TO_STREAM (scalar_t__*,scalar_t__*,int) ; 
 int EFAIL ; 
 int ETH_ALEN ; 
 int /*<<< orphan*/  HCI_CMND_EVENT_MASK ; 
 int /*<<< orphan*/  HCI_CMND_READ_BUFFER_SIZE ; 
 int /*<<< orphan*/  HCI_CMND_SIMPLE_LINK_START ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_CONNECT ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_DISCONNECT ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_ADD_PROFILE ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_DEL_PROFILE ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_GET_SCAN_RESULTS ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_SET_CONNECTION_POLICY ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_SET_SCANPARAM ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_SET_PREFIX ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_START ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_STOP ; 
 int /*<<< orphan*/  HCI_CMND_WLAN_IOCTL_STATUSGET ; 
 scalar_t__ HCI_EVNT_WLAN_TX_COMPLETE ; 
 scalar_t__ HCI_EVNT_WLAN_UNSOL_BASE ; 
 int HEADERS_SIZE_CMD ; 
 int /*<<< orphan*/  NVMEM_SHARED_MEM_FILEID ; 
 int /*<<< orphan*/  SL_PATCHES_REQUEST_DEFAULT ; 
 int /*<<< orphan*/  SL_PATCHES_REQUEST_FORCE_NONE ; 
 int SL_SET_SCAN_PARAMS_INTERVAL_LIST_SIZE ; 
 int SL_SIMPLE_CONFIG_PREFIX_LENGTH ; 
 int /*<<< orphan*/  SMART_CONFIG_PROFILE_SIZE ; 
 int /*<<< orphan*/  SimpleLinkWaitEvent (int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  SpiClose () ; 
 int /*<<< orphan*/  SpiOpen (void (*) (void*)) ; 
 scalar_t__ TIMEOUT ; 
 scalar_t__* UINT16_TO_STREAM (scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__* UINT32_TO_STREAM (scalar_t__*,scalar_t__) ; 
 int /*<<< orphan*/  UINT8_TO_STREAM (scalar_t__*,int /*<<< orphan*/ ) ; 
 scalar_t__ WLAN_ADD_PROFILE_NOSEC_PARAM_LEN ; 
 scalar_t__ WLAN_ADD_PROFILE_WEP_PARAM_LEN ; 
 scalar_t__ WLAN_ADD_PROFILE_WPA_PARAM_LEN ; 
 int WLAN_CONNECT_PARAM_LEN ; 
 int WLAN_DEL_PROFILE_PARAMS_LEN ; 
 int /*<<< orphan*/  WLAN_DISABLE ; 
 int /*<<< orphan*/  WLAN_ENABLE ; 
 int WLAN_GET_SCAN_RESULTS_PARAMS_LEN ; 
#define  WLAN_SEC_UNSEC 131 
#define  WLAN_SEC_WEP 130 
#define  WLAN_SEC_WPA 129 
#define  WLAN_SEC_WPA2 128 
 int WLAN_SET_CONNECTION_POLICY_PARAMS_LEN ; 
 int WLAN_SET_MASK_PARAMS_LEN ; 
 int WLAN_SET_SCAN_PARAMS_LEN ; 
 int WLAN_SL_INIT_START_PARAMS_LEN ; 
 int WLAN_SMART_CONFIG_START_PARAMS_LEN ; 
 int /*<<< orphan*/  aes_decrypt (scalar_t__*,int /*<<< orphan*/ ) ; 
 int aes_read_key (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  hci_command_send (int /*<<< orphan*/ ,scalar_t__*,int) ; 
 int /*<<< orphan*/  hci_unsolicited_event_handler () ; 
 int /*<<< orphan*/  key ; 
 int nvmem_read (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*) ; 
 int* profileArray ; 
 scalar_t__ stub1 () ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ ) ; 
 scalar_t__ stub3 () ; 
 scalar_t__ stub4 () ; 
 scalar_t__ stub5 () ; 
 int /*<<< orphan*/  stub6 (int /*<<< orphan*/ ) ; 
 scalar_t__ stub7 () ; 
 TYPE_1__ tSLInformation ; 
 scalar_t__ wlan_tx_buffer ; 

__attribute__((used)) static void SimpleLink_Init_Start(UINT16 usPatchesAvailableAtHost)
{
	UINT8 *ptr;
	UINT8 *args;

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (UINT8 *)(ptr + HEADERS_SIZE_CMD);

	UINT8_TO_STREAM(args, ((usPatchesAvailableAtHost) ? SL_PATCHES_REQUEST_FORCE_NONE : SL_PATCHES_REQUEST_DEFAULT));

	// IRQ Line asserted - send HCI_CMND_SIMPLE_LINK_START to CC3000
	hci_command_send(HCI_CMND_SIMPLE_LINK_START, ptr, WLAN_SL_INIT_START_PARAMS_LEN);

	SimpleLinkWaitEvent(HCI_CMND_SIMPLE_LINK_START, 0);
}

void wlan_init(		tWlanCB	 	sWlanCB,
	tFWPatches sFWPatches,
	tDriverPatches sDriverPatches,
	tBootLoaderPatches sBootLoaderPatches,
	tWlanReadInteruptPin  sReadWlanInterruptPin,
	tWlanInterruptEnable  sWlanInterruptEnable,
	tWlanInterruptDisable sWlanInterruptDisable,
	tWriteWlanPin         sWriteWlanPin)
{

	tSLInformation.sFWPatches = sFWPatches;
	tSLInformation.sDriverPatches = sDriverPatches;
	tSLInformation.sBootLoaderPatches = sBootLoaderPatches;

	// init io callback
	tSLInformation.ReadWlanInterruptPin = sReadWlanInterruptPin;
	tSLInformation.WlanInterruptEnable  = sWlanInterruptEnable;
	tSLInformation.WlanInterruptDisable = sWlanInterruptDisable;
	tSLInformation.WriteWlanPin = sWriteWlanPin;

	//init asynchronous events callback
	tSLInformation.sWlanCB= sWlanCB;

	// By default TX Complete events are routed to host too
	tSLInformation.InformHostOnTxComplete = 1;
}

void SpiReceiveHandler(void *pvBuffer)
{	
	tSLInformation.usEventOrDataReceived = 1;
	tSLInformation.pucReceivedData = (UINT8 *)pvBuffer;

	hci_unsolicited_event_handler();
}

int wlan_start(UINT16 usPatchesAvailableAtHost)
{

	UINT32 ulSpiIRQState;
	UINT32 wlan_timeout;

	tSLInformation.NumberOfSentPackets = 0;
	tSLInformation.NumberOfReleasedPackets = 0;
	tSLInformation.usRxEventOpcode = 0;
	tSLInformation.usNumberOfFreeBuffers = 0;
	tSLInformation.usSlBufferLength = 0;
	tSLInformation.usBufferSize = 0;
	tSLInformation.usRxDataPending = 0;
	tSLInformation.slTransmitDataError = 0;
	tSLInformation.usEventOrDataReceived = 0;
	tSLInformation.pucReceivedData = 0;

	// Allocate the memory for the RX/TX data transactions
	tSLInformation.pucTxCommandBuffer = (UINT8 *)wlan_tx_buffer;

	// init spi
	SpiOpen(SpiReceiveHandler);

	// Check the IRQ line
	ulSpiIRQState = tSLInformation.ReadWlanInterruptPin();

	// Chip enable: toggle WLAN EN line
	tSLInformation.WriteWlanPin( WLAN_ENABLE );
    
    wlan_timeout = TIMEOUT;
	if (ulSpiIRQState) {
		// wait till the IRQ line goes low
		while(tSLInformation.ReadWlanInterruptPin() != 0 && --wlan_timeout)
		{
		}
	}
	else
	{
		// wait till the IRQ line goes high and than low
		while(tSLInformation.ReadWlanInterruptPin() == 0 && --wlan_timeout)
		{
		}

        if (wlan_timeout == 0) {
            return -1;
        }

        wlan_timeout = TIMEOUT;
		while(tSLInformation.ReadWlanInterruptPin() != 0 && --wlan_timeout)
		{
		}
	}

    if (wlan_timeout ==0) {
        return -1;
    }

	SimpleLink_Init_Start(usPatchesAvailableAtHost);

	// Read Buffer's size and finish
	hci_command_send(HCI_CMND_READ_BUFFER_SIZE, tSLInformation.pucTxCommandBuffer, 0);
	SimpleLinkWaitEvent(HCI_CMND_READ_BUFFER_SIZE, 0);

    return 0;
}

void wlan_stop(void)
{
	// Chip disable
	tSLInformation.WriteWlanPin( WLAN_DISABLE );

	// Wait till IRQ line goes high...
	while(tSLInformation.ReadWlanInterruptPin() == 0)
	{
	}

	// Free the used by WLAN Driver memory
	if (tSLInformation.pucTxCommandBuffer)
	{
		tSLInformation.pucTxCommandBuffer = 0;
	}

	SpiClose();
}

INT32 wlan_connect(UINT32 ulSecType, CHAR *ssid, INT32 ssid_len,
	UINT8 *bssid, UINT8 *key, INT32 key_len)
{
	INT32 ret;
	UINT8 *ptr;
	UINT8 *args;
	UINT8 bssid_zero[] = {0, 0, 0, 0, 0, 0};

	ret  	= EFAIL;
	ptr  	= tSLInformation.pucTxCommandBuffer;
	args 	= (ptr + HEADERS_SIZE_CMD);

	// Fill in command buffer
	args = UINT32_TO_STREAM(args, 0x0000001c);
	args = UINT32_TO_STREAM(args, ssid_len);
	args = UINT32_TO_STREAM(args, ulSecType);
	args = UINT32_TO_STREAM(args, 0x00000010 + ssid_len);
	args = UINT32_TO_STREAM(args, key_len);
	args = UINT16_TO_STREAM(args, 0);

	// padding shall be zeroed
	if(bssid)
	{
		ARRAY_TO_STREAM(args, bssid, ETH_ALEN);
	}
	else
	{
		ARRAY_TO_STREAM(args, bssid_zero, ETH_ALEN);
	}

	ARRAY_TO_STREAM(args, ssid, ssid_len);

	if(key_len && key)
	{
		ARRAY_TO_STREAM(args, key, key_len);
	}

	// Initiate a HCI command
	hci_command_send(HCI_CMND_WLAN_CONNECT, ptr, WLAN_CONNECT_PARAM_LEN + 
		ssid_len + key_len - 1);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_CONNECT, &ret);
	CC3000_EXPORT(errno) = ret;

	return(ret);
}

INT32 wlan_disconnect()
{
	INT32 ret;
	UINT8 *ptr;

	ret = EFAIL;
	ptr = tSLInformation.pucTxCommandBuffer;

	hci_command_send(HCI_CMND_WLAN_DISCONNECT, ptr, 0);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_DISCONNECT, &ret);
	CC3000_EXPORT(errno) = ret;

	return(ret);
}

INT32 wlan_ioctl_set_connection_policy(UINT32 should_connect_to_open_ap, 
	UINT32 ulShouldUseFastConnect,
	UINT32 ulUseProfiles)
{
	INT32 ret;
	UINT8 *ptr;
	UINT8 *args;

	ret = EFAIL;
	ptr = tSLInformation.pucTxCommandBuffer;
	args = (UINT8 *)(ptr + HEADERS_SIZE_CMD);

	// Fill in HCI packet structure
	args = UINT32_TO_STREAM(args, should_connect_to_open_ap);
	args = UINT32_TO_STREAM(args, ulShouldUseFastConnect);
	args = UINT32_TO_STREAM(args, ulUseProfiles);

	// Initiate a HCI command
	hci_command_send(HCI_CMND_WLAN_IOCTL_SET_CONNECTION_POLICY,
		ptr, WLAN_SET_CONNECTION_POLICY_PARAMS_LEN);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_SET_CONNECTION_POLICY, &ret);

	return(ret);
}

INT32 wlan_add_profile(UINT32 ulSecType, 
	UINT8* ucSsid,
	UINT32 ulSsidLen, 
	UINT8 *ucBssid,
	UINT32 ulPriority,
	UINT32 ulPairwiseCipher_Or_TxKeyLen,
	UINT32 ulGroupCipher_TxKeyIndex,
	UINT32 ulKeyMgmt,
	UINT8* ucPf_OrKey,
	UINT32 ulPassPhraseLen)
{
	UINT16 arg_len=0;
	INT32 ret;
	UINT8 *ptr;
	INT32 i = 0;
	UINT8 *args;
	UINT8 bssid_zero[] = {0, 0, 0, 0, 0, 0};

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (ptr + HEADERS_SIZE_CMD);

	args = UINT32_TO_STREAM(args, ulSecType);

	// Setup arguments in accordance with the security type
	switch (ulSecType)
	{
		//OPEN
	case WLAN_SEC_UNSEC:
		{
			args = UINT32_TO_STREAM(args, 0x00000014);
			args = UINT32_TO_STREAM(args, ulSsidLen);
			args = UINT16_TO_STREAM(args, 0);
			if(ucBssid)
			{
				ARRAY_TO_STREAM(args, ucBssid, ETH_ALEN);
			}
			else
			{
				ARRAY_TO_STREAM(args, bssid_zero, ETH_ALEN);
			}
			args = UINT32_TO_STREAM(args, ulPriority);
			ARRAY_TO_STREAM(args, ucSsid, ulSsidLen);

			arg_len = WLAN_ADD_PROFILE_NOSEC_PARAM_LEN + ulSsidLen;
		}
		break;

		//WEP
	case WLAN_SEC_WEP:
		{
			args = UINT32_TO_STREAM(args, 0x00000020);
			args = UINT32_TO_STREAM(args, ulSsidLen);
			args = UINT16_TO_STREAM(args, 0);
			if(ucBssid)
			{
				ARRAY_TO_STREAM(args, ucBssid, ETH_ALEN);
			}
			else
			{
				ARRAY_TO_STREAM(args, bssid_zero, ETH_ALEN);
			}
			args = UINT32_TO_STREAM(args, ulPriority);
			args = UINT32_TO_STREAM(args, 0x0000000C + ulSsidLen);
			args = UINT32_TO_STREAM(args, ulPairwiseCipher_Or_TxKeyLen);
			args = UINT32_TO_STREAM(args, ulGroupCipher_TxKeyIndex);
			ARRAY_TO_STREAM(args, ucSsid, ulSsidLen);

			for(i = 0; i < 4; i++)
			{
				UINT8 *p = &ucPf_OrKey[i * ulPairwiseCipher_Or_TxKeyLen];

				ARRAY_TO_STREAM(args, p, ulPairwiseCipher_Or_TxKeyLen);
			}		

			arg_len = WLAN_ADD_PROFILE_WEP_PARAM_LEN + ulSsidLen + 
				ulPairwiseCipher_Or_TxKeyLen * 4;

		}
		break;

		//WPA
		//WPA2
	case WLAN_SEC_WPA:
	case WLAN_SEC_WPA2:
		{
			args = UINT32_TO_STREAM(args, 0x00000028);
			args = UINT32_TO_STREAM(args, ulSsidLen);
			args = UINT16_TO_STREAM(args, 0);
			if(ucBssid)
			{
				ARRAY_TO_STREAM(args, ucBssid, ETH_ALEN);
			}
			else
			{
				ARRAY_TO_STREAM(args, bssid_zero, ETH_ALEN);
			}
			args = UINT32_TO_STREAM(args, ulPriority);
			args = UINT32_TO_STREAM(args, ulPairwiseCipher_Or_TxKeyLen);
			args = UINT32_TO_STREAM(args, ulGroupCipher_TxKeyIndex);
			args = UINT32_TO_STREAM(args, ulKeyMgmt);
			args = UINT32_TO_STREAM(args, 0x00000008 + ulSsidLen);
			args = UINT32_TO_STREAM(args, ulPassPhraseLen);
			ARRAY_TO_STREAM(args, ucSsid, ulSsidLen);
			ARRAY_TO_STREAM(args, ucPf_OrKey, ulPassPhraseLen);

			arg_len = WLAN_ADD_PROFILE_WPA_PARAM_LEN + ulSsidLen + ulPassPhraseLen;
		}

		break;
	}    

	// Initiate a HCI command
	hci_command_send(HCI_CMND_WLAN_IOCTL_ADD_PROFILE,
		ptr, arg_len);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_ADD_PROFILE, &ret);

	return(ret);
}

INT32 wlan_ioctl_del_profile(UINT32 ulIndex)
{
	INT32 ret;
	UINT8 *ptr;
	UINT8 *args;

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (UINT8 *)(ptr + HEADERS_SIZE_CMD);

	// Fill in HCI packet structure
	args = UINT32_TO_STREAM(args, ulIndex);
	ret = EFAIL;

	// Initiate a HCI command
	hci_command_send(HCI_CMND_WLAN_IOCTL_DEL_PROFILE,
		ptr, WLAN_DEL_PROFILE_PARAMS_LEN);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_DEL_PROFILE, &ret);

	return(ret);
}

INT32 wlan_ioctl_get_scan_results(UINT32 ulScanTimeout,
	UINT8 *ucResults)
{
	UINT8 *ptr;
	UINT8 *args;

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (ptr + HEADERS_SIZE_CMD);

	// Fill in temporary command buffer
	args = UINT32_TO_STREAM(args, ulScanTimeout);

	// Initiate a HCI command
	hci_command_send(HCI_CMND_WLAN_IOCTL_GET_SCAN_RESULTS,
		ptr, WLAN_GET_SCAN_RESULTS_PARAMS_LEN);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_GET_SCAN_RESULTS, ucResults);

	return(0);
}

INT32 wlan_ioctl_set_scan_params(UINT32 uiEnable, UINT32 uiMinDwellTime,
	UINT32 uiMaxDwellTime,
	UINT32 uiNumOfProbeRequests,
	UINT32 uiChannelMask,INT32 iRSSIThreshold,
	UINT32 uiSNRThreshold,
	UINT32 uiDefaultTxPower,
	UINT32 *aiIntervalList)
{
	UINT32  uiRes;
	UINT8 *ptr;
	UINT8 *args;

	ptr = tSLInformation.pucTxCommandBuffer;
	args = (ptr + HEADERS_SIZE_CMD);

	// Fill in temporary command buffer
	args = UINT32_TO_STREAM(args, 36);
	args = UINT32_TO_STREAM(args, uiEnable);
	args = UINT32_TO_STREAM(args, uiMinDwellTime);
	args = UINT32_TO_STREAM(args, uiMaxDwellTime);
	args = UINT32_TO_STREAM(args, uiNumOfProbeRequests);
	args = UINT32_TO_STREAM(args, uiChannelMask);
	args = UINT32_TO_STREAM(args, iRSSIThreshold);
	args = UINT32_TO_STREAM(args, uiSNRThreshold);
	args = UINT32_TO_STREAM(args, uiDefaultTxPower);
	ARRAY_TO_STREAM(args, aiIntervalList, sizeof(UINT32) * 
		SL_SET_SCAN_PARAMS_INTERVAL_LIST_SIZE);

	// Initiate a HCI command
	hci_command_send(HCI_CMND_WLAN_IOCTL_SET_SCANPARAM,
		ptr, WLAN_SET_SCAN_PARAMS_LEN);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_SET_SCANPARAM, &uiRes);

	return(uiRes);
}

INT32 wlan_set_event_mask(UINT32 ulMask)
{
	INT32 ret;
	UINT8 *ptr;
	UINT8 *args;


	if ((ulMask & HCI_EVNT_WLAN_TX_COMPLETE) == HCI_EVNT_WLAN_TX_COMPLETE)
	{
		tSLInformation.InformHostOnTxComplete = 0;

		// Since an event is a virtual event - i.e. it is not coming from CC3000
		// there is no need to send anything to the device if it was an only event
		if (ulMask == HCI_EVNT_WLAN_TX_COMPLETE)
		{
			return 0;
		}

		ulMask &= ~HCI_EVNT_WLAN_TX_COMPLETE;
		ulMask |= HCI_EVNT_WLAN_UNSOL_BASE;
	}
	else
	{
		tSLInformation.InformHostOnTxComplete = 1;
	}

	ret = EFAIL;
	ptr = tSLInformation.pucTxCommandBuffer;
	args = (UINT8 *)(ptr + HEADERS_SIZE_CMD);

	// Fill in HCI packet structure
	args = UINT32_TO_STREAM(args, ulMask);

	// Initiate a HCI command
	hci_command_send(HCI_CMND_EVENT_MASK,
		ptr, WLAN_SET_MASK_PARAMS_LEN);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_EVENT_MASK, &ret);

	return(ret);
}

INT32 wlan_ioctl_statusget(void)
{
	INT32 ret;
	UINT8 *ptr;

	ret = EFAIL;
	ptr = tSLInformation.pucTxCommandBuffer;

	hci_command_send(HCI_CMND_WLAN_IOCTL_STATUSGET,
		ptr, 0);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_STATUSGET, &ret);

	return(ret);    
}

INT32 wlan_smart_config_start(UINT32 algoEncryptedFlag)
{
	INT32 ret;
	UINT8 *ptr;
	UINT8 *args;

	ret = EFAIL;
	ptr = tSLInformation.pucTxCommandBuffer;
	args = (UINT8 *)(ptr + HEADERS_SIZE_CMD);

	// Fill in HCI packet structure
	args = UINT32_TO_STREAM(args, algoEncryptedFlag);
	ret = EFAIL;

	hci_command_send(HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_START, ptr, 
		WLAN_SMART_CONFIG_START_PARAMS_LEN);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_START, &ret);

	return(ret);    
}

INT32 wlan_smart_config_stop(void)
{
	INT32 ret;
	UINT8 *ptr;

	ret = EFAIL;
	ptr = tSLInformation.pucTxCommandBuffer;

	hci_command_send(HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_STOP, ptr, 0);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_STOP, &ret);

	return(ret);    
}

INT32 wlan_smart_config_set_prefix(CHAR* cNewPrefix)
{
	INT32 ret;
	UINT8 *ptr;
	UINT8 *args;

	ret = EFAIL;
	ptr = tSLInformation.pucTxCommandBuffer;
	args = (ptr + HEADERS_SIZE_CMD);

	if (cNewPrefix == NULL)
		return ret;
	else	// with the new Smart Config, prefix must be TTT
	{
		*cNewPrefix = 'T';
		*(cNewPrefix + 1) = 'T';
		*(cNewPrefix + 2) = 'T';
	}

	ARRAY_TO_STREAM(args, cNewPrefix, SL_SIMPLE_CONFIG_PREFIX_LENGTH);

	hci_command_send(HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_SET_PREFIX, ptr, 
		SL_SIMPLE_CONFIG_PREFIX_LENGTH);

	// Wait for command complete event
	SimpleLinkWaitEvent(HCI_CMND_WLAN_IOCTL_SIMPLE_CONFIG_SET_PREFIX, &ret);

	return(ret);    
}

INT32 wlan_smart_config_process()
{
	INT32	returnValue;
	UINT32 ssidLen, keyLen;
	UINT8 *decKeyPtr;
	UINT8 *ssidPtr;

	// read the key from EEPROM - fileID 12
	returnValue = aes_read_key(key);

	if (returnValue != 0)
		return returnValue;

	// read the received data from fileID #13 and parse it according to the followings:
	// 1) SSID LEN - not encrypted
	// 2) SSID - not encrypted
	// 3) KEY LEN - not encrypted. always 32 bytes long
	// 4) Security type - not encrypted
	// 5) KEY - encrypted together with true key length as the first byte in KEY
	//	 to elaborate, there are two corner cases:
	//		1) the KEY is 32 bytes long. In this case, the first byte does not represent KEY length
	//		2) the KEY is 31 bytes long. In this case, the first byte represent KEY length and equals 31
	returnValue = nvmem_read(NVMEM_SHARED_MEM_FILEID, SMART_CONFIG_PROFILE_SIZE, 0, profileArray);

	if (returnValue != 0)
		return returnValue;

	ssidPtr = &profileArray[1];

	ssidLen = profileArray[0];

	decKeyPtr = &profileArray[profileArray[0] + 3];

	aes_decrypt(decKeyPtr, key);
	if (profileArray[profileArray[0] + 1] > 16)
		aes_decrypt((UINT8 *)(decKeyPtr + 16), key);

	if (*(UINT8 *)(decKeyPtr +31) != 0)
	{
		if (*decKeyPtr == 31)
		{
			keyLen = 31;
			decKeyPtr++;
		}
		else
		{
			keyLen = 32;
		}
	}
	else
	{
		keyLen = *decKeyPtr;
		decKeyPtr++;
	}

	// add a profile
	switch (profileArray[profileArray[0] + 2])
	{
	case WLAN_SEC_UNSEC://None
		{
			returnValue = wlan_add_profile(profileArray[profileArray[0] + 2], 	// security type
				ssidPtr,		 					// SSID
				ssidLen, 							// SSID length
				NULL, 							// BSSID
				1,								// Priority
				0, 0, 0, 0, 0);

			break;
		}

	case WLAN_SEC_WEP://WEP
		{
			returnValue = wlan_add_profile(profileArray[profileArray[0] + 2], 	// security type
				ssidPtr, 							// SSID
				ssidLen, 							// SSID length
				NULL, 							// BSSID
				1,								// Priority
				keyLen,							// KEY length
				0, 								// KEY index
				0,
				decKeyPtr,						// KEY
				0);

			break;
		}

	case WLAN_SEC_WPA://WPA
	case WLAN_SEC_WPA2://WPA2
		{
			returnValue = wlan_add_profile(WLAN_SEC_WPA2, 	// security type
				ssidPtr,
				ssidLen,
				NULL, 							// BSSID
				1,								// Priority
				0x18,							// PairwiseCipher
				0x1e, 							// GroupCipher
				2,								// KEY management
				decKeyPtr,						// KEY
				keyLen);							// KEY length

			break;
		}
	}

	return returnValue;
}

