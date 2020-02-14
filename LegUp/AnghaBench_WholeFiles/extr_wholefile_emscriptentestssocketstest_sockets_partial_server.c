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
struct sockaddr_in {int /*<<< orphan*/  sin_addr; int /*<<< orphan*/  sin_port; int /*<<< orphan*/  sin_family; } ;
struct sockaddr {int dummy; } ;
typedef  int /*<<< orphan*/  socklen_t ;
typedef  int /*<<< orphan*/  fd_set ;
typedef  int /*<<< orphan*/  buffers ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 scalar_t__ FD_ISSET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  F_SETFL ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  O_NONBLOCK ; 
 int /*<<< orphan*/  PF_INET ; 
 int /*<<< orphan*/  SIGTERM ; 
 int /*<<< orphan*/  SOCKK ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int accept (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  atexit (void (*) ()) ; 
 int bind (int,struct sockaddr*,int) ; 
 int clientfd ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fcntl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int inet_pton (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int listen (int,int) ; 
 int /*<<< orphan*/  memset (struct sockaddr_in*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int send (int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int serverfd ; 
 int /*<<< orphan*/  signal (int /*<<< orphan*/ ,void (*) ()) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strlen (char*) ; 

void cleanup_client() {
  if (clientfd) {
    close(clientfd);
    clientfd = 0;
  }
}

void cleanup() {
  if (serverfd) {
    close(serverfd);
    serverfd = 0;
  }
  cleanup_client();
}

void do_send(int sockfd) {
  static char* buffers[] = {
    "\x09\x01\x02\x03\x04\x05\x06\x07\x08\x09\0",
    "\x08\x01\x02\x03\x04\x05\x06\x07\x08\0",
    "\x07\x01\x02\x03\x04\x05\x06\x07\0",
    "\x06\x01\x02\x03\x04\x05\x06\0",
    "\x05\x01\x02\x03\x04\x05\0",
    "\x04\x01\x02\x03\x04\0",
    "\x03\x01\x02\x03\0",
    "\x02\x01\x02\0",
    "\x01\x01\0"
  };

  int i;
  int res;
  char *buffer;
  socklen_t addrlen;

  for (i = 0; i < sizeof(buffers) / sizeof(char*); i++) {
    buffer = buffers[i];

    res = send(sockfd, buffer, strlen(buffer), 0);
    if (res == -1) {
      perror("send failed");
      return;
    }
    printf("sent \"%s\" (%d bytes)\n", buffer, res);
  }
}

void iter() {
  int res;
  fd_set fdr;
  fd_set fdw;

  // see if there are any connections to accept / write to
  FD_ZERO(&fdr);
  FD_ZERO(&fdw);
  FD_SET(serverfd, &fdr);
  if (clientfd) FD_SET(clientfd, &fdw);
  res = select(64, &fdr, &fdw, NULL, NULL);
  if (res == -1) {
    perror("select failed");
    exit(EXIT_SUCCESS);
  }

  if (FD_ISSET(serverfd, &fdr)) {
    printf("accepted someone\n");
    clientfd = accept(serverfd, NULL, NULL);
    assert(clientfd != -1);
  }

  if (FD_ISSET(clientfd, &fdw)) {
    do_send(clientfd);
    cleanup_client();
  }
}

int main() {
  struct sockaddr_in addr;
  int res;

  atexit(cleanup);
  signal(SIGTERM, cleanup);

  // create the socket
  serverfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (serverfd == -1) {
    perror("cannot create socket");
    exit(EXIT_FAILURE);
  }
  fcntl(serverfd, F_SETFL, O_NONBLOCK);

  // bind and listen to the supplied port
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(SOCKK);
  if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) != 1) {
    perror("inet_pton failed");
    exit(EXIT_FAILURE);
  }

  res = bind(serverfd, (struct sockaddr *)&addr, sizeof(addr));
  if (res == -1) {
    perror("bind failed");
    exit(EXIT_FAILURE);
  }

  res = listen(serverfd, 50);
  if (res == -1) {
    perror("listen failed");
    exit(EXIT_FAILURE);
  }

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(iter, 60, 0);
#else
  while (1) iter();
#endif

  return EXIT_SUCCESS;
}

