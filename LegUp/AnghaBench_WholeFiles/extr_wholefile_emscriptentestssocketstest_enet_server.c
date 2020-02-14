#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_5__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;
typedef  struct TYPE_14__   TYPE_10__ ;

/* Type definitions */
struct TYPE_19__ {int /*<<< orphan*/  port; int /*<<< orphan*/  host; } ;
struct TYPE_18__ {int type; int channelID; TYPE_2__* peer; TYPE_10__* packet; } ;
struct TYPE_17__ {int /*<<< orphan*/ * data; } ;
struct TYPE_15__ {int host; int port; } ;
struct TYPE_16__ {char* data; TYPE_1__ address; } ;
struct TYPE_14__ {int dataLength; char* data; } ;
typedef  TYPE_2__ ENetPeer ;
typedef  TYPE_3__ ENetPacket ;
typedef  TYPE_4__ ENetEvent ;
typedef  TYPE_5__ ENetAddress ;

/* Variables and functions */
#define  ENET_EVENT_TYPE_CONNECT 130 
#define  ENET_EVENT_TYPE_DISCONNECT 129 
#define  ENET_EVENT_TYPE_RECEIVE 128 
 int /*<<< orphan*/  ENET_HOST_ANY ; 
 int /*<<< orphan*/  ENET_PACKET_FLAG_RELIABLE ; 
 int EXIT_FAILURE ; 
 int /*<<< orphan*/  SOCKK ; 
 int /*<<< orphan*/  atexit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enet_deinitialize ; 
 int /*<<< orphan*/ * enet_host_create (TYPE_5__*,int,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enet_host_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  enet_host_flush (int /*<<< orphan*/ *) ; 
 scalar_t__ enet_host_service (int /*<<< orphan*/ *,TYPE_4__*,int /*<<< orphan*/ ) ; 
 scalar_t__ enet_initialize () ; 
 TYPE_3__* enet_packet_create (char*,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  enet_packet_destroy (TYPE_10__*) ; 
 int /*<<< orphan*/  enet_packet_resize (TYPE_3__*,int) ; 
 int /*<<< orphan*/  enet_peer_send (TYPE_2__*,int /*<<< orphan*/ ,TYPE_3__*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * host ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcpy (int /*<<< orphan*/ *,char*) ; 
 size_t strlen (char*) ; 

void send_msg(ENetPeer *peer) {
   /* Create a reliable packet of size 7 containing "packet\0" */
  ENetPacket * packet = enet_packet_create ("packet",
                                            strlen ("packet") + 1,
                                            ENET_PACKET_FLAG_RELIABLE);
  /* Extend the packet so and append the string "foo", so it now */
  /* contains "packetfoo\0" */
  enet_packet_resize (packet, strlen ("packetfoo") + 1);
  strcpy (& packet -> data [strlen ("packet")], "foo");
  /* Send the packet to the peer over channel id 0. */
  /* One could also broadcast the packet by */
  /* enet_host_broadcast (host, 0, packet); */
  enet_peer_send (peer, 0, packet);
  /* One could just use enet_host_service() instead. */
  enet_host_flush (host);
}

void main_loop() {
  static int counter = 0;
#ifdef __EMSCRIPTEN__
  counter++;
#endif
  if (counter == 100) {
    printf("stop!\n");
#ifdef __EMSCRIPTEN__
    emscripten_cancel_main_loop();
#endif
    return;
  }

  ENetEvent event;
//printf("enet host?\n");
  if (enet_host_service (host, & event, 0) == 0) return;
printf("enet host, got event of type %d\n", event.type);
  switch (event.type)
  {
    case ENET_EVENT_TYPE_CONNECT:
      printf ("A new client connected from %x:%u.\n",
              event.peer -> address.host,
              event.peer -> address.port);
      /* Store any relevant client information here. */
      event.peer -> data = "Client information";

      send_msg(event.peer);

      break;
    case ENET_EVENT_TYPE_RECEIVE:
      printf ("A packet of length %u containing %s was received from %s on channel %u.\n",
              event.packet -> dataLength,
              event.packet -> data,
              event.peer -> data,
              event.channelID);
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

  ENetAddress address;
  address.host = ENET_HOST_ANY;
  address.port = SOCKK;
  printf("create!\n");
  host = enet_host_create (& address /* the address to bind the server host to */,
                             32 /* allow up to 32 clients and/or outgoing connections */,
                             2 /* allow up to 2 channels to be used, 0 and 1 */,
                             0 /* assume any amount of incoming bandwidth */,
                             0 /* assume any amount of outgoing bandwidth */);
  if (host == NULL)
  {
    fprintf (stderr,
    "An error occurred while trying to create an ENet server host.\n");
    exit (EXIT_FAILURE);
  }

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(main_loop, 3, 1);
#else
  while (1) main_loop();
#endif

  return 1;
}

