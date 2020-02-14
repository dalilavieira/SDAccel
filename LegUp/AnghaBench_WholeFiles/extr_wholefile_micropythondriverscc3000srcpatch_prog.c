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
typedef  unsigned long uint32_t ;
typedef  int /*<<< orphan*/  fatTable ;

/* Variables and functions */
 unsigned char BIT0 ; 
 unsigned char BIT1 ; 
 unsigned char BIT2 ; 
 unsigned char BIT4 ; 
 unsigned char BIT5 ; 
 unsigned char BIT6 ; 
 unsigned char BIT7 ; 
 int HCI_EVNT_WLAN_ASYNC_PING_REPORT ; 
 int HCI_EVNT_WLAN_KEEPALIVE ; 
 int HCI_EVNT_WLAN_UNSOL_INIT ; 
 unsigned short NVMEM_RM_FILEID ; 
 int /*<<< orphan*/  NVMEM_WLAN_DRIVER_SP_FILEID ; 
 int /*<<< orphan*/  NVMEM_WLAN_FW_SP_FILEID ; 
 int /*<<< orphan*/  ReadWlanInterruptPin ; 
 int /*<<< orphan*/  SpiPauseSpi ; 
 int /*<<< orphan*/  SpiResumeSpi ; 
 int /*<<< orphan*/  WriteWlanPin ; 
 unsigned short** aFATEntries ; 
 scalar_t__ aucCC3000_prefix ; 
 int* cMacFromEeprom ; 
 unsigned char* cRMParamsFromEeprom ; 
 scalar_t__ cRMdefaultParams ; 
 int counter ; 
 int /*<<< orphan*/  drv_length ; 
 int /*<<< orphan*/  fw_length ; 
 int /*<<< orphan*/  fw_patch ; 
 scalar_t__ mac_status ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ nvmem_get_mac_address (int*) ; 
 int nvmem_read (unsigned short,int,int,unsigned char*) ; 
 int nvmem_set_mac_address (int*) ; 
 int nvmem_write (unsigned short,int,int,unsigned char*) ; 
 int nvmem_write_patch (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int return_status ; 
 int ucStatus_Dr ; 
 int ucStatus_FW ; 
 int /*<<< orphan*/  wlan_drv_patch ; 
 int /*<<< orphan*/  wlan_init (void (*) (long,char*,unsigned char),char* (*) (unsigned long*),char* (*) (unsigned long*),char* (*) (unsigned long*),int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wlan_ioctl_del_profile (int) ; 
 int /*<<< orphan*/  wlan_ioctl_set_connection_policy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wlan_set_event_mask (int) ; 
 int /*<<< orphan*/  wlan_smart_config_set_prefix (char*) ; 
 int /*<<< orphan*/  wlan_start (unsigned short) ; 
 int /*<<< orphan*/  wlan_stop () ; 

__attribute__((used)) static void systick_sleep(unsigned long ms) {
    extern void HAL_Delay(volatile uint32_t Delay);
    HAL_Delay(ms);
}

__attribute__((used)) static char *sendDriverPatch(unsigned long *Length)
{
    *Length = 0;
    return NULL;
}

__attribute__((used)) static char *sendBootLoaderPatch(unsigned long *Length)
{
    *Length = 0;
    return NULL;
}

__attribute__((used)) static char *sendWLFWPatch(unsigned long *Length)
{
    *Length = 0;
    return NULL;
}

__attribute__((used)) static void CC3000_UsynchCallback(long lEventType, char * data, unsigned char length)
{
	
}

__attribute__((used)) static int initDriver(unsigned short cRequestPatch)
{
    // WLAN On API Implementation
    wlan_init(CC3000_UsynchCallback, sendWLFWPatch, sendDriverPatch, sendBootLoaderPatch,
              ReadWlanInterruptPin, SpiResumeSpi, SpiPauseSpi, WriteWlanPin);

    // Trigger a WLAN device
    wlan_start(cRequestPatch);
    wlan_smart_config_set_prefix((char*)aucCC3000_prefix);
    wlan_ioctl_set_connection_policy(0, 0, 0);
    wlan_ioctl_del_profile(255);

    // Mask out all non-required events from CC3000
    wlan_set_event_mask(HCI_EVNT_WLAN_KEEPALIVE|
                        HCI_EVNT_WLAN_UNSOL_INIT|
                        HCI_EVNT_WLAN_ASYNC_PING_REPORT);

    //unsolicicted_events_timer_init();
    systick_sleep(100);
    return(0);
}

__attribute__((used)) static unsigned char  __attribute__ ((unused))
fat_read_content(unsigned char *is_allocated, unsigned char *is_valid,
        unsigned char *write_protected, unsigned short *file_address, unsigned short *file_length)
{
    unsigned short  index;
    unsigned char   ucStatus;
    unsigned char   fatTable[48];
    unsigned char*  fatTablePtr = fatTable;

    //
    // Read in 6 parts to work with tiny driver
    //
    for (index = 0; index < 6; index++)
    {
        ucStatus = nvmem_read(16, 8, 4 + 8*index, fatTablePtr); 
        fatTablePtr += 8;
    }
	
    fatTablePtr = fatTable;
	
    for (index = 0; index <= NVMEM_RM_FILEID; index++)
    {
        *is_allocated++ = (*fatTablePtr) & BIT0;
        *is_valid++ = ((*fatTablePtr) & BIT1) >> 1;
        *write_protected++ = ((*fatTablePtr) & BIT2) >> 2;
        *file_address++ = ((*(fatTablePtr+1)<<8) | (*fatTablePtr)) & (BIT4|BIT5|BIT6|BIT7);
        *file_length++ = ((*(fatTablePtr+3)<<8) | (*(fatTablePtr+2))) & (BIT4|BIT5|BIT6|BIT7);
        
        //
        // Move to next file ID
        //
        fatTablePtr += 4;  
    }
    
    return ucStatus;
}

__attribute__((used)) static unsigned char fat_write_content(unsigned short const *file_address,
                                unsigned short const *file_length)
{
    unsigned short  index = 0;
    unsigned char   ucStatus;
    unsigned char   fatTable[48];
    unsigned char*  fatTablePtr = fatTable;

    //
    // First, write the magic number.
    //
    ucStatus = nvmem_write(16, 2, 0, (unsigned char*)"LS"); 
	
    for (; index <= NVMEM_RM_FILEID; index++)
    {
        //
        // Write address low char and mark as allocated.
        //
        *fatTablePtr++ = (unsigned char)(file_address[index] & 0xff) | BIT0;
	
        //	
        // Write address high char.
        //
        *fatTablePtr++ = (unsigned char)((file_address[index]>>8) & 0xff);
		
        //
        // Write length low char.
        //
        *fatTablePtr++ = (unsigned char)(file_length[index] & 0xff);
		
        //
        // Write length high char.
        //
        *fatTablePtr++ = (unsigned char)((file_length[index]>>8) & 0xff);		
    }
	
    //
    // Second, write the FAT.
    // Write in two parts to work with tiny driver.
    //
    ucStatus = nvmem_write(16, 24, 4, fatTable); 
    ucStatus = nvmem_write(16, 24, 24+4, &fatTable[24]); 
	
    //
    // Third, we want to erase any user files.
    //
    memset(fatTable, 0, sizeof(fatTable));
    ucStatus = nvmem_write(16, 16, 52, fatTable); 
	
    return ucStatus;
}

void patch_prog_start()
{
    unsigned short  index;
    unsigned char   *pRMParams;

    printf("Initializing module...\n");

    // Init module and request to load with no patches.
    // This is in order to overwrite restrictions to
    // write to specific places in EEPROM.
    initDriver(1);

    // Read MAC address.
    mac_status = nvmem_get_mac_address(cMacFromEeprom);

    return_status = 1;

    printf("Reading RM parameters...\n");
    while ((return_status) && (counter < 3)) {
        // Read RM parameters.
        // Read in 16 parts to work with tiny driver.
        return_status = 0;
        pRMParams = cRMParamsFromEeprom;
        for (index = 0; index < 16; index++) {
            return_status |= nvmem_read(NVMEM_RM_FILEID, 8, 8*index, pRMParams);
            pRMParams += 8;
        }
        counter++;
    }

    // If RM file is not valid, load the default one.
    if (counter == 3) {
        printf("RM is not valid, loading default one...\n");
        pRMParams = (unsigned char *)cRMdefaultParams;
    } else {
        printf("RM is valid.\n");
        pRMParams = cRMParamsFromEeprom;
    }

    return_status = 1;

    printf("Writing new FAT\n");
    while (return_status) {
        // Write new FAT.
        return_status = fat_write_content(aFATEntries[0], aFATEntries[1]);
    }

    return_status = 1;

    printf("Writing RM parameters...\n");
    while (return_status) {
        // Write RM parameters.
        // Write in 4 parts to work with tiny driver.
        return_status = 0;

        for (index = 0; index < 4; index++) {
            return_status |= nvmem_write(NVMEM_RM_FILEID,
                                         32,
                                         32*index,
                                         (pRMParams + 32*index)); 
        }
    }

    return_status = 1;

    // Write back the MAC address, only if exists.
    if (mac_status == 0) {
        // Zero out MCAST bit if set.
        cMacFromEeprom[0] &= 0xfe;
        printf("Writing back MAC address..\n");
        while (return_status) {
            return_status = nvmem_set_mac_address(cMacFromEeprom);
        }
    }

    // Update driver
    ucStatus_Dr = 1;
    printf("Updating driver patch...\n");
    while (ucStatus_Dr) {
        // Writing driver patch to EEPRROM - PROTABLE CODE
        // Note that the array itself is changing between the
        // different Service Packs.
        ucStatus_Dr = nvmem_write_patch(NVMEM_WLAN_DRIVER_SP_FILEID,
                                        drv_length,
                                        wlan_drv_patch);
    }

    // Update firmware
    ucStatus_FW = 1;
    printf("Updating firmware patch...\n");
    while (ucStatus_FW) {
        // Writing FW patch to EEPRROM - PROTABLE CODE
        // Note that the array itself is changing between the
        // different Service Packs.
        ucStatus_FW = nvmem_write_patch(NVMEM_WLAN_FW_SP_FILEID,
                                        fw_length,
                                        fw_patch);
    }

    printf("Update complete, resetting module\n"\
           "If this doesn't work, reset manually...\n");

    wlan_stop();
    systick_sleep(500);

    // Re-Init module and request to load with patches.
    initDriver(0);

    // If MAC does not exist, it is recommended
    // that the user will write a valid mac address.
    if (mac_status != 0) {
        printf("MAC address is not valid, please write a new one\n");
    }

    // Patch update done
    printf("All done, call wlan.patch_version()\n");
}

