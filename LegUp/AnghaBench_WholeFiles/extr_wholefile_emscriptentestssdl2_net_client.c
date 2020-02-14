#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  state_t ;
struct TYPE_3__ {size_t msg_i; scalar_t__ msg_state; scalar_t__ sd; } ;
typedef  int /*<<< orphan*/  IPaddress ;

/* Variables and functions */
 int EAGAIN ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 scalar_t__ MSG_READ ; 
 scalar_t__ MSG_WRITE ; 
 char* SDLNet_GetError () ; 
 scalar_t__ SDLNet_Init () ; 
 int /*<<< orphan*/  SDLNet_Quit () ; 
 scalar_t__ SDLNet_ResolveHost (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SDLNet_TCP_Close (scalar_t__) ; 
 scalar_t__ SDLNet_TCP_Open (int /*<<< orphan*/ *) ; 
 int SDLNet_TCP_Recv (scalar_t__,void*,int) ; 
 int SDLNet_TCP_Send (scalar_t__,void*,int) ; 
 int /*<<< orphan*/  SOCKK ; 
 int /*<<< orphan*/  assert (int) ; 
 int errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 char** msgs ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 TYPE_1__ state ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 
 int strlen (char*) ; 

void finish(int result) {
  if (state.sd) {
    SDLNet_TCP_Close(state.sd);
    SDLNet_Quit();
  }
#ifdef __EMSCRIPTEN__
  REPORT_RESULT(result);
  emscripten_force_exit(result);
#else
  exit(result);
#endif
}

void main_loop()
{
  char *sendbuf = msgs[state.msg_i];
  char recvbuf[256] = {0};
  int actual = 0, len = strlen(sendbuf) + 1;
  printf("main loop with string %s and len %d\n", sendbuf, len);

  if (state.msg_state == MSG_WRITE) {
    printf("trying to send %s\n", sendbuf);
    if ((actual = SDLNet_TCP_Send(state.sd, (void *)sendbuf, len)) != len)
    {
      fprintf(stderr, "SDLNet_TCP_Send: count:%d/%d errno:%d msg:%s\n",
        actual, len, errno, SDLNet_GetError());
      if (errno == EAGAIN) {
        if (actual > 0) {
          assert(0);
        }
        return;
      }
      finish(EXIT_FAILURE);
    }
    printf("send success\n");
    state.msg_state = MSG_READ;
  }
  if (state.msg_state == MSG_READ) {
    printf("trying to receive %s\n", sendbuf);
    if ((actual = SDLNet_TCP_Recv(state.sd, (void *)recvbuf, len)) != len)
    {
      fprintf(stderr, "SDLNet_TCP_Recv: count:%d/%d errno:%d msg:%s\n",
        actual, len, errno, SDLNet_GetError());
      if (errno == EAGAIN) {
        if (actual > 0) {
          assert(0);
        }
        return;
      }
      finish(EXIT_FAILURE);
    }
    printf("receive success\n");
    assert(strcmp(sendbuf, recvbuf) == 0);
    if (!strcmp(recvbuf, "exit")) {
      finish(EXIT_SUCCESS);
    }
    state.msg_i++;
    state.msg_state = MSG_WRITE;
  }
}

int main(int argc, char **argv)
{
  IPaddress ip;   /* Server address */
  memset(&state, 0, sizeof(state_t));
  state.msg_state = MSG_WRITE;

  if (SDLNet_Init() < 0)
  {
    fprintf(stderr, "SDLNet_Init: %s\n", SDLNet_GetError());
    finish(EXIT_FAILURE);
  }

  /* Resolve the host we are connecting to */
  if (SDLNet_ResolveHost(&ip, "localhost", SOCKK) < 0)
  {
    fprintf(stderr, "SDLNet_ResolveHost: %s\n", SDLNet_GetError());
    finish(EXIT_FAILURE);
  }

  /* Open a connection with the IP provided */
  if (!(state.sd = SDLNet_TCP_Open(&ip)))
  {
    fprintf(stderr, "SDLNet_TCP_Open: %s\n", SDLNet_GetError());
    finish(EXIT_FAILURE);
  }

  /* Send messages */
#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(main_loop, 60, 0);
#else
  while (1) main_loop();
#endif

  return EXIT_SUCCESS;
}

