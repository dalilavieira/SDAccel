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
struct TYPE_2__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {int /*<<< orphan*/  sin_port; TYPE_1__ sin_addr; int /*<<< orphan*/  sin_family; } ;
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  pthread_t ;
typedef  int /*<<< orphan*/  WSADATA ;
typedef  int /*<<< orphan*/  WORD ;
typedef  scalar_t__ SOCKET ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  CreateEvent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  INADDR_ANY ; 
 int /*<<< orphan*/  MAKEWORD (int,int) ; 
 void* PTHREAD_CANCELED ; 
 int /*<<< orphan*/  PTHREAD_CANCEL_ASYNCHRONOUS ; 
 int /*<<< orphan*/  PTHREAD_CANCEL_ENABLE ; 
 int /*<<< orphan*/  PTW32_ALERTABLE_ASYNC_CANCEL ; 
 int /*<<< orphan*/  SOCK_DGRAM ; 
 int /*<<< orphan*/  Sleep (int) ; 
 int /*<<< orphan*/  WSACleanup () ; 
 scalar_t__ WSAStartup (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  WaitForSingleObject (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ bind (scalar_t__,struct sockaddr*,int) ; 
 int /*<<< orphan*/  closesocket (scalar_t__) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  printf (char*) ; 
 scalar_t__ pthread_cancel (int /*<<< orphan*/ ) ; 
 scalar_t__ pthread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ *,void* (*) (void*),int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_join (int /*<<< orphan*/ ,void**) ; 
 int /*<<< orphan*/  pthread_setcancelstate (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pthread_setcanceltype (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 scalar_t__ pthread_win32_test_features_np (int /*<<< orphan*/ ) ; 
 int recvfrom (scalar_t__,char*,int,int /*<<< orphan*/ ,struct sockaddr*,int*) ; 
 scalar_t__ socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void *
test_udp (void *arg)
{
  struct sockaddr_in serverAddress;
  struct sockaddr_in clientAddress;
  SOCKET UDPSocket;
  int addr_len;
  int nbyte, bytes;
  char buffer[4096];
  WORD wsaVersion = MAKEWORD (2, 2);
  WSADATA wsaData;

  pthread_setcancelstate (PTHREAD_CANCEL_ENABLE, NULL);
  pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

  if (WSAStartup (wsaVersion, &wsaData) != 0)
    {
      return NULL;
    }

  UDPSocket = socket (AF_INET, SOCK_DGRAM, 0);
  if ((int)UDPSocket == -1)
    {
      printf ("Server: socket ERROR \n");
      exit (-1);
    }

  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons (9003);

  if (bind
      (UDPSocket, (struct sockaddr *) &serverAddress,
       sizeof (struct sockaddr_in)))
    {
      printf ("Server: ERROR can't bind UDPSocket");
      exit (-1);
    }

  addr_len = sizeof (struct sockaddr);

  nbyte = 512;

  bytes =
    recvfrom (UDPSocket, (char *) buffer, nbyte, 0,
	      (struct sockaddr *) &clientAddress, &addr_len);

  closesocket (UDPSocket);
  WSACleanup ();

  return NULL;
}

void *
test_sleep (void *arg)
{
  pthread_setcancelstate (PTHREAD_CANCEL_ENABLE, NULL);
  pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

  Sleep (1000);
  return NULL;

}

void *
test_wait (void *arg)
{
  HANDLE hEvent;
  DWORD dwEvent;

  pthread_setcancelstate (PTHREAD_CANCEL_ENABLE, NULL);
  pthread_setcanceltype (PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

  hEvent = CreateEvent (NULL, FALSE, FALSE, NULL);

  dwEvent = WaitForSingleObject (hEvent, 1000);	/* WAIT_IO_COMPLETION */

  return NULL;
}

int
main ()
{
  pthread_t t;
  void *result;

  if (pthread_win32_test_features_np (PTW32_ALERTABLE_ASYNC_CANCEL))
    {
      printf ("Cancel sleeping thread.\n");
      assert (pthread_create (&t, NULL, test_sleep, NULL) == 0);
      /* Sleep for a while; then cancel */
      Sleep (100);
      assert (pthread_cancel (t) == 0);
      assert (pthread_join (t, &result) == 0);
      assert (result == PTHREAD_CANCELED && "test_sleep" != NULL);

      printf ("Cancel waiting thread.\n");
      assert (pthread_create (&t, NULL, test_wait, NULL) == 0);
      /* Sleep for a while; then cancel. */
      Sleep (100);
      assert (pthread_cancel (t) == 0);
      assert (pthread_join (t, &result) == 0);
      assert (result == PTHREAD_CANCELED && "test_wait");

      printf ("Cancel blocked thread (blocked on network I/O).\n");
      assert (pthread_create (&t, NULL, test_udp, NULL) == 0);
      /* Sleep for a while; then cancel. */
      Sleep (100);
      assert (pthread_cancel (t) == 0);
      assert (pthread_join (t, &result) == 0);
      assert (result == PTHREAD_CANCELED && "test_udp" != NULL);
    }
  else
    {
      printf ("Alertable async cancel not available.\n");
    }

  /*
   * Success.
   */
  return 0;
}

