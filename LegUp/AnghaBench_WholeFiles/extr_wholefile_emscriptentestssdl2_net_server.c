#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/ * sd; int /*<<< orphan*/  socketSet; int /*<<< orphan*/ ** clientSocket; } ;
struct TYPE_6__ {int /*<<< orphan*/  port; int /*<<< orphan*/  host; } ;
typedef  int /*<<< orphan*/ * TCPsocket ;
typedef  TYPE_1__ IPaddress ;

/* Variables and functions */
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  INADDR_ANY ; 
 int MAX_CLIENTS ; 
 int /*<<< orphan*/  MAX_SOCKETS ; 
 int /*<<< orphan*/  SDLNet_AllocSocketSet (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDLNet_CheckSockets (int /*<<< orphan*/ ,int) ; 
 char* SDLNet_GetError () ; 
 scalar_t__ SDLNet_Init () ; 
 int /*<<< orphan*/  SDLNet_Quit () ; 
 int SDLNet_Read16 (int /*<<< orphan*/ *) ; 
 int SDLNet_Read32 (int /*<<< orphan*/ *) ; 
 scalar_t__ SDLNet_ResolveHost (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int SDLNet_SocketReady (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SDLNet_TCP_Accept (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDLNet_TCP_AddSocket (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SDLNet_TCP_Close (int /*<<< orphan*/ *) ; 
 TYPE_1__* SDLNet_TCP_GetPeerAddress (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SDLNet_TCP_Open (TYPE_1__*) ; 
 int SDLNet_TCP_Recv (int /*<<< orphan*/ *,char*,int) ; 
 int SDLNet_TCP_Send (int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/  SOCKK ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 TYPE_2__ state ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 

void finish() { // untested
  printf("Shutting down...\n");
  SDLNet_TCP_Close(state.sd);
  for (int loop = 0; loop < MAX_CLIENTS; loop++)
  {
    if (state.clientSocket[loop] != NULL)
    {
      SDLNet_TCP_Close(state.clientSocket[loop]);
      state.clientSocket[loop] = NULL;
    }
  }
  SDLNet_Quit();

#ifdef __EMSCRIPTEN__
  emscripten_force_exit(0);
#else
  exit(0);
#endif
}

void main_loop() {
  char buffer[512];
  IPaddress *remoteIP;

  /* Check the sd if there is a pending connection.
   * If there is one, accept that, and open a new socket for communicating */
  SDLNet_CheckSockets(state.socketSet, 20);
  int serverSocketActivity = SDLNet_SocketReady(state.sd);

  if (serverSocketActivity)
  {
    printf("new server socket activity!\n");
    TCPsocket csd = SDLNet_TCP_Accept(state.sd);
    /* Now we can communicate with the client using csd socket
     * sd will remain opened waiting other connections */

    /* Get the remote address */
    if ((remoteIP = SDLNet_TCP_GetPeerAddress(csd)))
    {
      /* Print the address, converting in the host format */
      printf("Host connected: %x %d\n", SDLNet_Read32(&remoteIP->host), SDLNet_Read16(&remoteIP->port));
    } else {
      fprintf(stderr, "SDLNet_TCP_GetPeerAddress: %s\n", SDLNet_GetError());
    }

    for (int loop = 0; loop < MAX_CLIENTS; loop++)
    {
        if (state.clientSocket[loop] == NULL)
        {
          state.clientSocket[loop] = csd;
          SDLNet_TCP_AddSocket(state.socketSet, state.clientSocket[loop]);
          break;
        }
    }
  }
  for (int clientNumber = 0; clientNumber < MAX_CLIENTS; clientNumber++)
  {
    int clientSocketActivity = SDLNet_SocketReady(state.clientSocket[clientNumber]);

    if (clientSocketActivity != 0)
    {
      int recvLen = SDLNet_TCP_Recv(state.clientSocket[clientNumber], buffer, 512);
      if (recvLen > 0)
      {
        assert(buffer[recvLen-1] == '\0');

        printf("Client %d says: %s\n", clientNumber, buffer);
        if (SDLNet_TCP_Send(state.clientSocket[clientNumber], buffer, recvLen) < recvLen) {
          printf("Failed to echo message %s\n", buffer);
        } else {
          printf("Echoed back %d bytes\n", recvLen);
        }

        if(strcmp(buffer, "exit") == 0) /* Terminate this connection */
        {
          printf("Terminate connection\n");
          SDLNet_TCP_Close(state.clientSocket[clientNumber]);
          state.clientSocket[clientNumber] = NULL;
        }
        if(strcmp(buffer, "quit") == 0) /* Quit the program */
        {
          printf("Quit program\n");
          finish();
        }
      } else {
        printf("Closing client socket\n");
        SDLNet_TCP_Close(state.clientSocket[clientNumber]);
        state.clientSocket[clientNumber] = NULL;
      }
    }
  }
}

int main(int argc, char **argv)
{
  IPaddress ip;

  if (SDLNet_Init() < 0)
  {
    fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
    exit(EXIT_FAILURE);
  }

  /* Resolving the host using NULL make network interface to listen */
  if (SDLNet_ResolveHost(&ip, INADDR_ANY, SOCKK) < 0)
  {
    fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
    exit(EXIT_FAILURE);
  }

  state.socketSet = SDLNet_AllocSocketSet(MAX_SOCKETS);

  for (int loop = 0; loop < MAX_CLIENTS; loop++)
  {
      state.clientSocket[loop] = NULL;
  }
  /* Open a connection with the IP provided (listen on the host's port) */
  if (!(state.sd = SDLNet_TCP_Open(&ip)))
  {
    fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
    exit(EXIT_FAILURE);
  }
  SDLNet_TCP_AddSocket(state.socketSet, state.sd);

  /* Wait for a connection, send data and term */
#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(main_loop, 60, 0);
#else
  while (1) main_loop();
#endif

  return EXIT_SUCCESS;
}

