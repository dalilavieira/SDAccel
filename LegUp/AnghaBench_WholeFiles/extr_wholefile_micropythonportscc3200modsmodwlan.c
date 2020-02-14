#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_35__   TYPE_9__ ;
typedef  struct TYPE_34__   TYPE_8__ ;
typedef  struct TYPE_33__   TYPE_7__ ;
typedef  struct TYPE_32__   TYPE_6__ ;
typedef  struct TYPE_31__   TYPE_5__ ;
typedef  struct TYPE_30__   TYPE_4__ ;
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_1__ ;
typedef  struct TYPE_26__   TYPE_15__ ;
typedef  struct TYPE_25__   TYPE_14__ ;
typedef  struct TYPE_24__   TYPE_13__ ;
typedef  struct TYPE_23__   TYPE_12__ ;
typedef  struct TYPE_22__   TYPE_11__ ;
typedef  struct TYPE_21__   TYPE_10__ ;

/* Type definitions */
typedef  unsigned char uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  ucPower ;
struct TYPE_31__ {int /*<<< orphan*/  tm_sec; int /*<<< orphan*/  tm_min; int /*<<< orphan*/  tm_hour; int /*<<< orphan*/  tm_year; int /*<<< orphan*/  tm_mon; int /*<<< orphan*/  tm_mday; } ;
typedef  TYPE_5__ timeutils_struct_time_t ;
typedef  scalar_t__ int8_t ;
typedef  unsigned char _u8 ;
typedef  void* _u32 ;
struct TYPE_32__ {void* FilterIdMask; } ;
typedef  TYPE_6__ _WlanRxFilterOperationCommandBuff_t ;
struct TYPE_35__ {void* ipV4DnsServer; void* ipV4Gateway; void* ipV4Mask; void* ipV4; } ;
struct TYPE_29__ {int /*<<< orphan*/  type; } ;
struct TYPE_28__ {int /*<<< orphan*/  status; } ;
struct TYPE_30__ {TYPE_3__ SockAsyncData; TYPE_2__ SockTxFailData; } ;
struct TYPE_34__ {int Event; TYPE_4__ socketAsyncEvent; } ;
struct TYPE_33__ {int Event; } ;
struct TYPE_23__ {int /*<<< orphan*/  ip; } ;
struct TYPE_27__ {TYPE_12__ ipAcquiredV4; } ;
struct TYPE_26__ {int mode; int /*<<< orphan*/  ip; int /*<<< orphan*/  status; int /*<<< orphan*/  mac; } ;
struct TYPE_25__ {int /*<<< orphan*/  sl_tm_sec; int /*<<< orphan*/  sl_tm_min; int /*<<< orphan*/  sl_tm_hour; int /*<<< orphan*/  sl_tm_year; int /*<<< orphan*/  sl_tm_mon; int /*<<< orphan*/  sl_tm_day; int /*<<< orphan*/  member_0; } ;
struct TYPE_24__ {int Event; } ;
struct TYPE_22__ {int lease_time; void* ipv4_addr_last; void* ipv4_addr_start; } ;
struct TYPE_21__ {int Event; TYPE_1__ EventData; } ;
typedef  TYPE_7__ SlWlanEvent_t ;
typedef  TYPE_8__ SlSockEvent_t ;
typedef  TYPE_9__ SlNetCfgIpV4Args_t ;
typedef  TYPE_10__ SlNetAppEvent_t ;
typedef  TYPE_11__ SlNetAppDhcpServerBasicOpt_t ;
typedef  TYPE_12__ SlIpV4AcquiredAsync_t ;
typedef  int /*<<< orphan*/  SlHttpServerResponse_t ;
typedef  TYPE_13__ SlHttpServerEvent_t ;
typedef  int /*<<< orphan*/  SlDeviceEvent_t ;
typedef  TYPE_14__ SlDateTime_t ;
typedef  int /*<<< orphan*/  RxFilterIdMask ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT_ON_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLR_STATUS_BIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  CLR_STATUS_BIT_ALL (int /*<<< orphan*/ ) ; 
 int IPCONFIG_MODE_ENABLE_IPV4 ; 
 scalar_t__ IS_IP_ACQUIRED (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  NETAPP_SET_DHCP_SRV_BASIC_OPT ; 
#define  OTHER_SIDE_CLOSE_SSL_DATA_NOT_ENCRYPTED 146 
 scalar_t__ ROLE_AP ; 
#define  RX_FRAGMENTATION_TOO_BIG 145 
 int /*<<< orphan*/  SET_STATUS_BIT (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SL_CONNECTION_POLICY (int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SL_DEVICE_GENERAL_CONFIGURATION ; 
 int /*<<< orphan*/  SL_DEVICE_GENERAL_CONFIGURATION_DATE_TIME ; 
#define  SL_ECLOSE 144 
 int /*<<< orphan*/  SL_IPV4_AP_P2P_GO_STATIC_ENABLE ; 
 int /*<<< orphan*/  SL_IPV4_STA_P2P_CL_DHCP_ENABLE ; 
 void* SL_IPV4_VAL (int,int,int,int) ; 
 int /*<<< orphan*/  SL_MAC_ADDR_LEN ; 
#define  SL_NETAPP_HTTPGETTOKENVALUE_EVENT 143 
#define  SL_NETAPP_HTTPPOSTTOKENVALUE_EVENT 142 
#define  SL_NETAPP_IPV4_IPACQUIRED_EVENT 141 
#define  SL_NETAPP_IPV6_IPACQUIRED_EVENT 140 
#define  SL_NETAPP_IP_LEASED_EVENT 139 
#define  SL_NETAPP_IP_RELEASED_EVENT 138 
 int /*<<< orphan*/  SL_NET_APP_DHCP_SERVER_ID ; 
 int /*<<< orphan*/  SL_NET_APP_HTTP_SERVER_ID ; 
 int /*<<< orphan*/  SL_NORMAL_POLICY ; 
 int /*<<< orphan*/  SL_POLICY_CONNECTION ; 
 int /*<<< orphan*/  SL_POLICY_PM ; 
 int /*<<< orphan*/  SL_REMOVE_RX_FILTER ; 
#define  SL_SOCKET_ASYNC_EVENT 137 
#define  SL_SOCKET_TX_FAILED_EVENT 136 
 int /*<<< orphan*/  SL_WLAN_CFG_GENERAL_PARAM_ID ; 
#define  SL_WLAN_CONNECTION_FAILED_EVENT 135 
#define  SL_WLAN_CONNECT_EVENT 134 
#define  SL_WLAN_DISCONNECT_EVENT 133 
#define  SL_WLAN_P2P_DEV_FOUND_EVENT 132 
#define  SL_WLAN_P2P_NEG_REQ_RECEIVED_EVENT 131 
#define  SL_WLAN_STA_CONNECTED_EVENT 130 
#define  SL_WLAN_STA_DISCONNECTED_EVENT 129 
#define  SSL_ACCEPT 128 
 int /*<<< orphan*/  STATUS_BIT_CONNECTION ; 
 int /*<<< orphan*/  STATUS_BIT_IP_ACQUIRED ; 
 int /*<<< orphan*/  WLAN_GENERAL_PARAM_OPT_AP_TX_POWER ; 
 int /*<<< orphan*/  WLAN_GENERAL_PARAM_OPT_COUNTRY_CODE ; 
 int /*<<< orphan*/  WLAN_GENERAL_PARAM_OPT_STA_TX_POWER ; 
 int /*<<< orphan*/  _SlTaskEntry () ; 
 int /*<<< orphan*/  memcpy (unsigned char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (void*,int,int) ; 
 int /*<<< orphan*/  pyb_rtc_get_seconds () ; 
 int /*<<< orphan*/  sl_DevSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned char*) ; 
 int /*<<< orphan*/  sl_NetAppMDNSUnRegisterService (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl_NetAppSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned char*) ; 
 int /*<<< orphan*/  sl_NetAppStart (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl_NetAppStop (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl_NetCfgSet (int /*<<< orphan*/ ,int,int,unsigned char*) ; 
 int sl_Start (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl_Stop (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl_WlanPolicySet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  sl_WlanProfileDel (int) ; 
 int /*<<< orphan*/  sl_WlanRxFilterSet (int /*<<< orphan*/ ,unsigned char*,int) ; 
 int /*<<< orphan*/  sl_WlanSet (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,unsigned char*) ; 
 int /*<<< orphan*/  timeutils_seconds_since_2000_to_struct_time (int /*<<< orphan*/ ,TYPE_5__*) ; 
 int /*<<< orphan*/  wlan_clear_data () ; 
 int /*<<< orphan*/  wlan_get_sl_mac () ; 
 TYPE_15__ wlan_obj ; 
 int /*<<< orphan*/  wlan_reenable (scalar_t__) ; 
 int /*<<< orphan*/  wlan_servers_start () ; 
 int /*<<< orphan*/  wlan_servers_stop () ; 
 int /*<<< orphan*/  wlan_set_channel (unsigned char) ; 
 void wlan_set_current_time (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  wlan_set_mode (scalar_t__) ; 
 int /*<<< orphan*/  wlan_set_security (unsigned char,char const*,unsigned char) ; 
 int /*<<< orphan*/  wlan_set_ssid (char const*,unsigned char,int) ; 
 int /*<<< orphan*/  wlan_sl_disconnect () ; 

void SimpleLinkWlanEventHandler(SlWlanEvent_t *pWlanEvent) {
    if (!pWlanEvent) {
        return;
    }

    switch(pWlanEvent->Event)
    {
        case SL_WLAN_CONNECT_EVENT:
        {
            //slWlanConnectAsyncResponse_t *pEventData = &pWlanEvent->EventData.STAandP2PModeWlanConnected;
            // copy the new connection data
            //memcpy(wlan_obj.bssid, pEventData->bssid, SL_BSSID_LENGTH);
            //memcpy(wlan_obj.ssid_o, pEventData->ssid_name, pEventData->ssid_len);
            //wlan_obj.ssid_o[pEventData->ssid_len] = '\0';
            SET_STATUS_BIT(wlan_obj.status, STATUS_BIT_CONNECTION);
        #if (MICROPY_PORT_HAS_TELNET || MICROPY_PORT_HAS_FTP)
            // we must reset the servers in case that the last connection
            // was lost without any notification being received
            servers_reset();
        #endif
        }
            break;
        case SL_WLAN_DISCONNECT_EVENT:
            CLR_STATUS_BIT(wlan_obj.status, STATUS_BIT_CONNECTION);
            CLR_STATUS_BIT(wlan_obj.status, STATUS_BIT_IP_ACQUIRED);
        #if (MICROPY_PORT_HAS_TELNET || MICROPY_PORT_HAS_FTP)
            servers_reset();
            servers_wlan_cycle_power();
        #endif
            break;
        case SL_WLAN_STA_CONNECTED_EVENT:
        {
            //slPeerInfoAsyncResponse_t *pEventData = &pWlanEvent->EventData.APModeStaConnected;
            // get the mac address and name of the connected device
            //memcpy(wlan_obj.bssid, pEventData->mac, SL_BSSID_LENGTH);
            //memcpy(wlan_obj.ssid_o, pEventData->go_peer_device_name, pEventData->go_peer_device_name_len);
            //wlan_obj.ssid_o[pEventData->go_peer_device_name_len] = '\0';
            SET_STATUS_BIT(wlan_obj.status, STATUS_BIT_CONNECTION);
        #if (MICROPY_PORT_HAS_TELNET || MICROPY_PORT_HAS_FTP)
            // we must reset the servers in case that the last connection
            // was lost without any notification being received
            servers_reset();
        #endif
        }
            break;
        case SL_WLAN_STA_DISCONNECTED_EVENT:
            CLR_STATUS_BIT(wlan_obj.status, STATUS_BIT_CONNECTION);
        #if (MICROPY_PORT_HAS_TELNET || MICROPY_PORT_HAS_FTP)
            servers_reset();
            servers_wlan_cycle_power();
        #endif
            break;
        case SL_WLAN_P2P_DEV_FOUND_EVENT:
            // TODO
            break;
        case SL_WLAN_P2P_NEG_REQ_RECEIVED_EVENT:
            // TODO
            break;
        case SL_WLAN_CONNECTION_FAILED_EVENT:
            // TODO
            break;
        default:
            break;
    }
}

void SimpleLinkNetAppEventHandler(SlNetAppEvent_t *pNetAppEvent) {
    if(!pNetAppEvent) {
        return;
    }

    switch(pNetAppEvent->Event)
    {
        case SL_NETAPP_IPV4_IPACQUIRED_EVENT:
        {
            SlIpV4AcquiredAsync_t *pEventData = NULL;

            SET_STATUS_BIT(wlan_obj.status, STATUS_BIT_IP_ACQUIRED);

            // Ip Acquired Event Data
            pEventData = &pNetAppEvent->EventData.ipAcquiredV4;

            // Get the ip
            wlan_obj.ip      = pEventData->ip;
        }
            break;
        case SL_NETAPP_IPV6_IPACQUIRED_EVENT:
            break;
        case SL_NETAPP_IP_LEASED_EVENT:
            break;
        case SL_NETAPP_IP_RELEASED_EVENT:
            break;
        default:
            break;
    }
}

void SimpleLinkHttpServerCallback(SlHttpServerEvent_t *pHttpEvent, SlHttpServerResponse_t *pHttpResponse) {
    if (!pHttpEvent) {
        return;
    }

    switch (pHttpEvent->Event) {
    case SL_NETAPP_HTTPGETTOKENVALUE_EVENT:
        break;
    case SL_NETAPP_HTTPPOSTTOKENVALUE_EVENT:
        break;
    default:
        break;
    }
}

void SimpleLinkGeneralEventHandler(SlDeviceEvent_t *pDevEvent) {
    if (!pDevEvent) {
        return;
    }
}

void SimpleLinkSockEventHandler(SlSockEvent_t *pSock) {
    if (!pSock) {
        return;
    }

    switch( pSock->Event ) {
    case SL_SOCKET_TX_FAILED_EVENT:
        switch( pSock->socketAsyncEvent.SockTxFailData.status) {
        case SL_ECLOSE:
            break;
        default:
          break;
        }
        break;
    case SL_SOCKET_ASYNC_EVENT:
         switch(pSock->socketAsyncEvent.SockAsyncData.type) {
         case SSL_ACCEPT:
             break;
         case RX_FRAGMENTATION_TOO_BIG:
             break;
         case OTHER_SIDE_CLOSE_SSL_DATA_NOT_ENCRYPTED:
             break;
         default:
             break;
         }
        break;
    default:
      break;
    }
}

__attribute__ ((section (".boot")))
void wlan_pre_init (void) {
    // create the wlan lock
    #ifdef SL_PLATFORM_MULTI_THREADED
    ASSERT(OSI_OK == sl_LockObjCreate(&wlan_LockObj, "WlanLock"));
    #endif
}

void wlan_first_start (void) {
    if (wlan_obj.mode < 0) {
        CLR_STATUS_BIT_ALL(wlan_obj.status);
        wlan_obj.mode = sl_Start(0, 0, 0);
        #ifdef SL_PLATFORM_MULTI_THREADED
        sl_LockObjUnlock (&wlan_LockObj);
        #endif
    }

    // get the mac address
    wlan_get_sl_mac();
}

void wlan_sl_init (int8_t mode, const char *ssid, uint8_t ssid_len, uint8_t auth, const char *key, uint8_t key_len,
                   uint8_t channel, uint8_t antenna, bool add_mac) {

    // stop the servers
    wlan_servers_stop();

    // do a basic start
    wlan_first_start();

    // close any active connections
    wlan_sl_disconnect();

    // Remove all profiles
    ASSERT_ON_ERROR(sl_WlanProfileDel(0xFF));

    // Enable the DHCP client
    uint8_t value = 1;
    ASSERT_ON_ERROR(sl_NetCfgSet(SL_IPV4_STA_P2P_CL_DHCP_ENABLE, 1, 1, &value));

    // Set PM policy to normal
    ASSERT_ON_ERROR(sl_WlanPolicySet(SL_POLICY_PM, SL_NORMAL_POLICY, NULL, 0));

    // Unregister mDNS services
    ASSERT_ON_ERROR(sl_NetAppMDNSUnRegisterService(0, 0));

    // Stop the internal HTTP server
    sl_NetAppStop(SL_NET_APP_HTTP_SERVER_ID);

    // Remove all 64 filters (8 * 8)
    _WlanRxFilterOperationCommandBuff_t  RxFilterIdMask;
    memset ((void *)&RxFilterIdMask, 0 ,sizeof(RxFilterIdMask));
    memset(RxFilterIdMask.FilterIdMask, 0xFF, 8);
    ASSERT_ON_ERROR(sl_WlanRxFilterSet(SL_REMOVE_RX_FILTER, (_u8 *)&RxFilterIdMask, sizeof(_WlanRxFilterOperationCommandBuff_t)));

#if MICROPY_HW_ANTENNA_DIVERSITY
    // set the antenna type
    wlan_set_antenna (antenna);
#endif

    // switch to the requested mode
    wlan_set_mode(mode);

    // stop and start again (we need to in the propper mode from now on)
    wlan_reenable(mode);

    // Set Tx power level for station or AP mode
    // Number between 0-15, as dB offset from max power - 0 will set max power
    uint8_t ucPower = 0;
    if (mode == ROLE_AP) {
        ASSERT_ON_ERROR(sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, WLAN_GENERAL_PARAM_OPT_AP_TX_POWER, sizeof(ucPower),
                                   (unsigned char *)&ucPower));

        // configure all parameters
        wlan_set_ssid (ssid, ssid_len, add_mac);
        wlan_set_security (auth, key, key_len);
        wlan_set_channel (channel);

        // set the country
        _u8*  country = (_u8*)"EU";
        ASSERT_ON_ERROR(sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, WLAN_GENERAL_PARAM_OPT_COUNTRY_CODE, 2, country));

        SlNetCfgIpV4Args_t ipV4;
        ipV4.ipV4          = (_u32)SL_IPV4_VAL(192,168,1,1);            // _u32 IP address
        ipV4.ipV4Mask      = (_u32)SL_IPV4_VAL(255,255,255,0);          // _u32 Subnet mask for this AP
        ipV4.ipV4Gateway   = (_u32)SL_IPV4_VAL(192,168,1,1);            // _u32 Default gateway address
        ipV4.ipV4DnsServer = (_u32)SL_IPV4_VAL(192,168,1,1);            // _u32 DNS server address
        ASSERT_ON_ERROR(sl_NetCfgSet(SL_IPV4_AP_P2P_GO_STATIC_ENABLE, IPCONFIG_MODE_ENABLE_IPV4,
                                     sizeof(SlNetCfgIpV4Args_t), (_u8 *)&ipV4));

        SlNetAppDhcpServerBasicOpt_t dhcpParams;
        dhcpParams.lease_time      =  4096;                             // lease time (in seconds) of the IP Address
        dhcpParams.ipv4_addr_start =  SL_IPV4_VAL(192,168,1,2);         // first IP Address for allocation.
        dhcpParams.ipv4_addr_last  =  SL_IPV4_VAL(192,168,1,254);       // last IP Address for allocation.
        ASSERT_ON_ERROR(sl_NetAppStop(SL_NET_APP_DHCP_SERVER_ID));      // Stop DHCP server before settings
        ASSERT_ON_ERROR(sl_NetAppSet(SL_NET_APP_DHCP_SERVER_ID, NETAPP_SET_DHCP_SRV_BASIC_OPT,
                                     sizeof(SlNetAppDhcpServerBasicOpt_t), (_u8* )&dhcpParams));  // set parameters
        ASSERT_ON_ERROR(sl_NetAppStart(SL_NET_APP_DHCP_SERVER_ID));     // Start DHCP server with new settings

        // stop and start again
        wlan_reenable(mode);
    } else { // STA and P2P modes
        ASSERT_ON_ERROR(sl_WlanSet(SL_WLAN_CFG_GENERAL_PARAM_ID, WLAN_GENERAL_PARAM_OPT_STA_TX_POWER,
                                   sizeof(ucPower), (unsigned char *)&ucPower));
        // set connection policy to Auto + Fast (tries to connect to the last connected AP)
        ASSERT_ON_ERROR(sl_WlanPolicySet(SL_POLICY_CONNECTION, SL_CONNECTION_POLICY(1, 1, 0, 0, 0), NULL, 0));
    }

    // set current time and date (needed to validate certificates)
    wlan_set_current_time (pyb_rtc_get_seconds());

    // start the servers before returning
    wlan_servers_start();
}

void wlan_update(void) {
#ifndef SL_PLATFORM_MULTI_THREADED
    _SlTaskEntry();
#endif
}

void wlan_stop (uint32_t timeout) {
    wlan_servers_stop();
    #ifdef SL_PLATFORM_MULTI_THREADED
    sl_LockObjLock (&wlan_LockObj, SL_OS_WAIT_FOREVER);
    #endif
    sl_Stop(timeout);
    wlan_clear_data();
    wlan_obj.mode = -1;
}

void wlan_get_mac (uint8_t *macAddress) {
    if (macAddress) {
        memcpy (macAddress, wlan_obj.mac, SL_MAC_ADDR_LEN);
    }
}

void wlan_get_ip (uint32_t *ip) {
    if (ip) {
        *ip = IS_IP_ACQUIRED(wlan_obj.status) ? wlan_obj.ip : 0;
    }
}

void wlan_set_current_time (uint32_t seconds_since_2000) {
    timeutils_struct_time_t tm;
    timeutils_seconds_since_2000_to_struct_time(seconds_since_2000, &tm);

    SlDateTime_t sl_datetime = {0};
    sl_datetime.sl_tm_day  = tm.tm_mday;
    sl_datetime.sl_tm_mon  = tm.tm_mon;
    sl_datetime.sl_tm_year = tm.tm_year;
    sl_datetime.sl_tm_hour = tm.tm_hour;
    sl_datetime.sl_tm_min  = tm.tm_min;
    sl_datetime.sl_tm_sec  = tm.tm_sec;
    sl_DevSet(SL_DEVICE_GENERAL_CONFIGURATION, SL_DEVICE_GENERAL_CONFIGURATION_DATE_TIME, sizeof(SlDateTime_t), (_u8 *)(&sl_datetime));
}

void wlan_off_on (void) {
    // no need to lock the WLAN object on every API call since the servers and the MicroPtyhon
    // task have the same priority
    wlan_reenable(wlan_obj.mode);
}

