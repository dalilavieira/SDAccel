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
typedef  int /*<<< orphan*/  u_long ;
struct TYPE_2__ {int /*<<< orphan*/  s_addr; } ;
struct sockaddr_in {int /*<<< orphan*/  sin_port; TYPE_1__ sin_addr; int /*<<< orphan*/  sin_family; } ;
struct sockaddr {int dummy; } ;
struct hostent {scalar_t__* h_addr_list; } ;
struct fd_set {int dummy; } ;
typedef  int /*<<< orphan*/  sa ;
typedef  scalar_t__ SOCKET ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  FD_SET (scalar_t__,struct fd_set*) ; 
 int /*<<< orphan*/  FD_ZERO (struct fd_set*) ; 
 scalar_t__ INVALID_SOCKET ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  SCKTEST (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  WSACleanup () ; 
 int WSAGetLastError () ; 
 int /*<<< orphan*/  connect (scalar_t__,struct sockaddr*,int) ; 
 struct hostent* gethostbyname (char*) ; 
 int /*<<< orphan*/  htons (int) ; 
 int /*<<< orphan*/  ok (int,char*,int) ; 
 int /*<<< orphan*/  printf (char*,int) ; 
 int /*<<< orphan*/  select (int /*<<< orphan*/ ,struct fd_set*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  send (scalar_t__,char const*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int strlen (char const*) ; 

int CreateSocket(SOCKET* psck)
{
    /* Create the socket */
    *psck = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    ok(*psck != INVALID_SOCKET, "*psck = %d\n", *psck);

    if(*psck == INVALID_SOCKET)
    {
        printf("Winsock error code is %u\n", WSAGetLastError());
        WSACleanup();
        return 0;
    }

    return 1;
}

int ConnectToReactOSWebsite(SOCKET sck)
{
    int iResult;
    struct hostent* host;
    struct sockaddr_in sa;

    /* Connect to "www.reactos.org" */
    host = gethostbyname("test.winehq.org");

    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = *(u_long*)host->h_addr_list[0];
    sa.sin_port = htons(80);

    SCKTEST(connect(sck, (struct sockaddr *)&sa, sizeof(sa)));
    
    return 1;
}

int GetRequestAndWait(SOCKET sck)
{
    const char szGetRequest[] = "GET / HTTP/1.0\r\n\r\n";
    int iResult;
    struct fd_set readable;

    /* Send the GET request */
    SCKTEST(send(sck, szGetRequest, strlen(szGetRequest), 0));
    ok(iResult == strlen(szGetRequest), "iResult = %d\n", iResult);
#if 0 /* breaks windows too */
    /* Shutdown the SEND connection */
    SCKTEST(shutdown(sck, SD_SEND));
#endif
    /* Wait until we're ready to read */
    FD_ZERO(&readable);
    FD_SET(sck, &readable);

    SCKTEST(select(0, &readable, NULL, NULL, NULL));
    
    return 1;
}

