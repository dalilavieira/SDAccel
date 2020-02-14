#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int dataLength; char* data; } ;
struct TYPE_10__ {int /*<<< orphan*/  port; } ;
struct TYPE_9__ {int type; int channelID; TYPE_1__* peer; TYPE_4__* packet; } ;
struct TYPE_8__ {char* data; } ;
typedef  int /*<<< orphan*/  ENetPeer ;
typedef  TYPE_2__ ENetEvent ;
typedef  TYPE_3__ ENetAddress ;

/* Variables and functions */
#define  ENET_EVENT_TYPE_CONNECT 130 
#define  ENET_EVENT_TYPE_DISCONNECT 129 
#define  ENET_EVENT_TYPE_RECEIVE 128 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  SOCKK ; 
 int /*<<< orphan*/  atexit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enet_address_set_host (TYPE_3__*,char*) ; 
 int /*<<< orphan*/  enet_deinitialize ; 
 int /*<<< orphan*/ * enet_host_connect (int /*<<< orphan*/ *,TYPE_3__*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * enet_host_create (int /*<<< orphan*/ *,int,int,int,int) ; 
 int /*<<< orphan*/  enet_host_destroy (int /*<<< orphan*/ *) ; 
 scalar_t__ enet_host_service (int /*<<< orphan*/ *,TYPE_2__*,int /*<<< orphan*/ ) ; 
 scalar_t__ enet_initialize () ; 
 int /*<<< orphan*/  enet_packet_destroy (TYPE_4__*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * host ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int strcmp (char*,char*) ; 

void main_loop() {
#ifdef __EMSCRIPTEN__
  static int counter = 0;
  counter++;
  if (counter == 100) {
    printf("stop!\n");
    emscripten_cancel_main_loop();
    return;
  }
#endif

  ENetEvent event;
  if (enet_host_service (host, & event, 0) == 0) return;
  switch (event.type)
  {
    case ENET_EVENT_TYPE_CONNECT:
      printf ("Connection succeeded!\n");

      break;
    case ENET_EVENT_TYPE_RECEIVE:
      printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
              event.packet -> dataLength,
              event.packet -> data,
              event.peer -> data,
              event.channelID);

      int result = strcmp("packetfoo", event.packet->data);
#ifdef __EMSCRIPTEN__
      REPORT_RESULT(result);
#else
      exit(EXIT_SUCCESS);
#endif

      /* Clean up the packet now that we're done using it. */
      enet_packet_destroy (event.packet);
      break;
    case ENET_EVENT_TYPE_DISCONNECT:
      printf ("%s disconected.\n", event.peer -> data);
      /* Reset the peer's client information. */
      event.peer -> data = NULL;
      enet_host_destroy(host);
      break;
    default:
      printf("whaaa? %d\n", event.type);
  }
}

int main (int argc, char ** argv)
{
  if (enet_initialize () != 0)
  {
    fprintf (stderr, "An error occurred while initializing ENet.\n");
    return EXIT_FAILURE;
  }
  atexit (enet_deinitialize);

  printf("creating host\n");

  host = enet_host_create (NULL /* create a client host */,
                              1 /* only allow 1 outgoing connection */,
                              2 /* allow up 2 channels to be used, 0 and 1 */,
                              57600 / 8 /* 56K modem with 56 Kbps downstream bandwidth */,
                              14400 / 8 /* 56K modem with 14 Kbps upstream bandwidth */);
  if (host == NULL)
  {
    fprintf (stderr,
              "An error occurred while trying to create an ENet client host.\n");
    exit (EXIT_FAILURE);
  }

  ENetAddress address;
  enet_address_set_host (& address, "localhost");
  address.port = SOCKK;

  printf("connecting to server...\n");

  ENetPeer *peer = enet_host_connect (host, & address, 2, 0);

  if (peer == NULL)
  {
    fprintf (stderr,
    "No available peers for initiating an ENet connection.\n");
    exit (EXIT_FAILURE);
  }

#ifdef __EMSCRIPTEN__
#if USE_IFRAME
  emscripten_run_script("console.log('adding iframe');"
                        "var iframe = document.createElement('iframe');"
                        "iframe.src = 'server.html';"
                        "iframe.width = '100%';"
                        "iframe.height = '33%';"
                        "document.body.appendChild(iframe);"
                        "console.log('added.');");
#endif
#endif

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(main_loop, 3, 1);
#else
  while (1) main_loop();
#endif

  return 1;
}

