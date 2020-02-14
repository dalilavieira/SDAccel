#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {int /*<<< orphan*/  ip; } ;
struct TYPE_7__ {TYPE_4__ ipAcquiredV4; } ;
struct TYPE_9__ {scalar_t__ Event; TYPE_1__ EventData; } ;
struct TYPE_8__ {int Event; } ;
typedef  TYPE_2__ SlWlanEvent_t ;
typedef  TYPE_3__ SlNetAppEvent_t ;
typedef  TYPE_4__ SlIpV4AcquiredAsync_t ;

/* Variables and functions */
 int /*<<< orphan*/  LL_INFO ; 
 int /*<<< orphan*/  LOG (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  SL_IPV4_BYTE (int /*<<< orphan*/ ,int) ; 
 scalar_t__ SL_NETAPP_IPV4_IPACQUIRED_EVENT ; 
 scalar_t__ SL_NETAPP_IP_LEASED_EVENT ; 
#define  SL_WLAN_CONNECT_EVENT 130 
#define  SL_WLAN_STA_CONNECTED_EVENT 129 
#define  SL_WLAN_STA_DISCONNECTED_EVENT 128 
 int ip_acquired ; 

void SimpleLinkWlanEventHandler(SlWlanEvent_t *e) {
  switch (e->Event) {
    case SL_WLAN_CONNECT_EVENT:
      LOG(LL_INFO, ("WiFi: connected, getting IP"));
      break;
    case SL_WLAN_STA_CONNECTED_EVENT:
      LOG(LL_INFO, ("WiFi: station connected"));
      break;
    case SL_WLAN_STA_DISCONNECTED_EVENT:
      LOG(LL_INFO, ("WiFi: station disconnected"));
      break;
    default:
      LOG(LL_INFO, ("WiFi: event %d", e->Event));
  }
}

void SimpleLinkNetAppEventHandler(SlNetAppEvent_t *e) {
  if (e->Event == SL_NETAPP_IPV4_IPACQUIRED_EVENT) {
    SlIpV4AcquiredAsync_t *ed = &e->EventData.ipAcquiredV4;
    LOG(LL_INFO, ("IP acquired: %lu.%lu.%lu.%lu", SL_IPV4_BYTE(ed->ip, 3),
                  SL_IPV4_BYTE(ed->ip, 2), SL_IPV4_BYTE(ed->ip, 1),
                  SL_IPV4_BYTE(ed->ip, 0)));
    ip_acquired = 1;
  } else if (e->Event == SL_NETAPP_IP_LEASED_EVENT) {
    LOG(LL_INFO, ("IP leased"));
  } else {
    LOG(LL_INFO, ("NetApp event %d", e->Event));
  }
}

