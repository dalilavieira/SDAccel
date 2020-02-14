#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct mg_connection {int /*<<< orphan*/  flags; int /*<<< orphan*/  sa; } ;
struct TYPE_7__ {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct TYPE_6__ {int /*<<< orphan*/  p; scalar_t__ len; } ;
struct http_message {TYPE_2__ uri; TYPE_1__ method; } ;
typedef  int /*<<< orphan*/  addr ;
struct TYPE_10__ {int state; } ;
struct TYPE_9__ {int /*<<< orphan*/  tcpip; } ;
struct TYPE_8__ {int member_0; int* v; int /*<<< orphan*/  Val; } ;
typedef  int /*<<< orphan*/  TCPIP_NET_HANDLE ;
typedef  int /*<<< orphan*/  SYS_STATUS ;
typedef  TYPE_3__ IPV4_ADDR ;

/* Variables and functions */
#define  APP_DONE 136 
#define  APP_EMPTY 135 
#define  APP_POLL 134 
#define  APP_START_LISTENING 133 
#define  APP_STATE_INIT 132 
#define  APP_TCPIP_WAIT_FOR_IP 131 
#define  MG_EV_ACCEPT 130 
#define  MG_EV_CLOSE 129 
#define  MG_EV_HTTP_REQUEST 128 
 int /*<<< orphan*/  MG_F_SEND_AND_CLOSE ; 
 int MG_SOCK_STRINGIFY_IP ; 
 int MG_SOCK_STRINGIFY_PORT ; 
 int /*<<< orphan*/  SYS_CONSOLE_MESSAGE (char*) ; 
 int /*<<< orphan*/  SYS_CONSOLE_PRINT (char*,...) ; 
 int /*<<< orphan*/  SYS_PRINT (char*,struct mg_connection*,...) ; 
 int /*<<< orphan*/  SYS_STATUS_READY ; 
 int /*<<< orphan*/  TCPIP_STACK_IndexToNet (int) ; 
 int /*<<< orphan*/  TCPIP_STACK_NetAddress (int /*<<< orphan*/ ) ; 
 char* TCPIP_STACK_NetBIOSName (int /*<<< orphan*/ ) ; 
 char* TCPIP_STACK_NetNameGet (int /*<<< orphan*/ ) ; 
 int TCPIP_STACK_NumberOfNetworksGet () ; 
 int /*<<< orphan*/  TCPIP_STACK_Status (int /*<<< orphan*/ ) ; 
 TYPE_5__ appData ; 
 struct mg_connection* mg_bind (int /*<<< orphan*/ *,char*,void (*) (struct mg_connection*,int,void*)) ; 
 int /*<<< orphan*/  mg_mgr_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mg_mgr_poll (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  mg_printf (struct mg_connection*,char*,char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mg_send_response_line (struct mg_connection*,int,char*) ; 
 int /*<<< orphan*/  mg_set_protocol_http_websocket (struct mg_connection*) ; 
 int /*<<< orphan*/  mg_sock_addr_to_str (int /*<<< orphan*/ *,char*,int,int) ; 
 int /*<<< orphan*/  mgr ; 
 TYPE_4__ sysObj ; 

void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
 switch (ev) {
    case MG_EV_ACCEPT: {
      char addr[32];
      mg_sock_addr_to_str(&nc->sa, addr, sizeof(addr),
                          MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_PORT);
      SYS_PRINT("%p: Connection from %s\r\n", nc, addr);
      break;
    }
    case MG_EV_HTTP_REQUEST: {
      struct http_message *hm = (struct http_message *) ev_data;
      char addr[32];
      mg_sock_addr_to_str(&nc->sa, addr, sizeof(addr),
                          MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_PORT);
      SYS_PRINT("%p: %.*s %.*s\r\n", nc, (int) hm->method.len, hm->method.p,
             (int) hm->uri.len, hm->uri.p);
      mg_send_response_line(nc, 200,
                            "Content-Type: text/html\r\n"
                            "Connection: close");
      mg_printf(nc,
                "\r\n<h1>Hello, %s!</h1>\r\n"
                "You asked for %.*s\r\n",
                addr, (int) hm->uri.len, hm->uri.p);
      nc->flags |= MG_F_SEND_AND_CLOSE;
      break;
    }
    case MG_EV_CLOSE: {
      SYS_PRINT("%p: Connection closed\r\n", nc);
      break;
    }
  }
}

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    mg_mgr_init(&mgr, NULL);
}

void APP_Tasks ( void )
{
    SYS_STATUS          tcpipStat;
    const char          *netName, *netBiosName;
    static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1} };
    IPV4_ADDR           ipAddr;
    TCPIP_NET_HANDLE    netH;
    int                 i, nNets;

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
            if(tcpipStat < 0)
            {   // some error occurred
                SYS_CONSOLE_MESSAGE(" APP: TCP/IP stack initialization failed!\r\n");
                appData.state = APP_DONE;
            }
            else if(tcpipStat == SYS_STATUS_READY)
            {
                // now that the stack is ready we can check the
                // available interfaces
                nNets = TCPIP_STACK_NumberOfNetworksGet();
                for(i = 0; i < nNets; i++)
                {

                    netH = TCPIP_STACK_IndexToNet(i);
                    netName = TCPIP_STACK_NetNameGet(netH);
                    netBiosName = TCPIP_STACK_NetBIOSName(netH);

#if defined(TCPIP_STACK_USE_NBNS)
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS enabled\r\n", netName, netBiosName);
#else
                    SYS_CONSOLE_PRINT("    Interface %s on host %s - NBNS disabled\r\n", netName, netBiosName);
#endif  // defined(TCPIP_STACK_USE_NBNS)

                }
                appData.state = APP_TCPIP_WAIT_FOR_IP;

            }
            break;
        }
        case APP_TCPIP_WAIT_FOR_IP:

            // if the IP address of an interface has changed
            // display the new value on the system console
            nNets = TCPIP_STACK_NumberOfNetworksGet();

            for (i = 0; i < nNets; i++)
            {
                netH = TCPIP_STACK_IndexToNet(i);
                ipAddr.Val = TCPIP_STACK_NetAddress(netH);
                if(dwLastIP[i].Val != ipAddr.Val)
                {
                    dwLastIP[i].Val = ipAddr.Val;

                    SYS_CONSOLE_MESSAGE(TCPIP_STACK_NetNameGet(netH));
                    SYS_CONSOLE_MESSAGE(" IP Address: ");
                    SYS_CONSOLE_PRINT("%d.%d.%d.%d \r\n", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
                    if (ipAddr.v[0] != 0 && ipAddr.v[0] != 169) // Wait for a Valid IP
                    {
                        appData.state = APP_START_LISTENING;
                    }
                }
            }
            break;
        case APP_START_LISTENING:
        {
            SYS_CONSOLE_PRINT("Starting listening on port 8000\r\n");
            struct mg_connection *nc = mg_bind(&mgr, "8000", ev_handler);  // Create listening connection and add it to the event manager
            if (nc == NULL) {
              SYS_CONSOLE_PRINT("Failed to create listener\n\r");
              appData.state = APP_DONE;
              break;
            }
            mg_set_protocol_http_websocket(nc);
            SYS_CONSOLE_PRINT("Listener started\r\n");

            appData.state = APP_POLL;
            break;
        }
        case APP_POLL:
        {
            mg_mgr_poll(&mgr, 1000);
            break;
        }
        case APP_DONE:
        {
            SYS_CONSOLE_PRINT("Server stopped\n\r");
            appData.state = APP_EMPTY;
            break;
        }
        case APP_EMPTY:
        {
            break;
        }
        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

