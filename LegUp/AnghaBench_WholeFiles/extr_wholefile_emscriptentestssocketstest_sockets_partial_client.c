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
typedef  int /*<<< orphan*/  fd_set ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 scalar_t__ EAGAIN ; 
 scalar_t__ EINPROGRESS ; 
 scalar_t__ EWOULDBLOCK ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  FD_ISSET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  F_SETFL ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  O_NONBLOCK ; 
 int /*<<< orphan*/  PF_INET ; 
 int /*<<< orphan*/  SOCKK ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  close (int) ; 
 int connect (int,struct sockaddr*,int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fcntl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int,char) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int inet_pton (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (struct sockaddr_in*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,int,...) ; 
 int recv (int,char*,char,int /*<<< orphan*/ ) ; 
 int select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sockfd ; 
 int /*<<< orphan*/  stderr ; 
 int sum ; 

void finish(int result) {
  close(sockfd);
#ifdef __EMSCRIPTEN__
  REPORT_RESULT(result);
  emscripten_force_exit(result);
#else
  exit(result);
#endif
}

void iter() {
  char buffer[1024];
  char packetLength;
  fd_set fdr;
  int i;
  int res;

  // make sure that sockfd is ready to read
  FD_ZERO(&fdr);
  FD_SET(sockfd, &fdr);
  res = select(64, &fdr, NULL, NULL, NULL);
  if (res == -1) {
    perror("select failed");
    finish(EXIT_FAILURE);
  } else if (!FD_ISSET(sockfd, &fdr)) {
    return;
  }

  res = recv(sockfd, buffer, 1, 0);
  if (res == -1) {
    if (errno == EAGAIN || errno == EWOULDBLOCK) {
      return; //try again
    }

    perror("unexcepted end of data");
    finish(EXIT_FAILURE);
  }

  if (res != 1) {
    fprintf(stderr, "should read 1 byte, got: %d, sum %d so far\n", res, sum);
    finish(EXIT_FAILURE);
  }

  packetLength = buffer[0];
  res = recv(sockfd, buffer, packetLength, 0);

  printf("got %d,%d\n", res, packetLength);

  if (res != packetLength) {
    fprintf(stderr, "lost packet data, expected: %d readed: %d", packetLength, res);
    finish(EXIT_FAILURE);
  }

  for (i = 0; i < packetLength; ++i) {
    if (buffer[i] != i+1) {
      fprintf(stderr, "packet corrupted, expected: %d, actual: %d", i+1, buffer[i]);
      finish(EXIT_FAILURE);
    }

    sum += buffer[i];
  }

  if (packetLength == buffer[0]) { // \x01\x01 - end marker
    printf("sum: %d\n", sum);
    finish(sum);
  }
}

int main() {
  struct sockaddr_in addr;
  int res;

  sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sockfd == -1) {
    perror("cannot create socket");
    exit(EXIT_FAILURE);
  }
  fcntl(sockfd, F_SETFL, O_NONBLOCK);

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(SOCKK);
  if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) != 1) {
    perror("inet_pton failed");
    finish(EXIT_FAILURE);
  }

  res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (res == -1 && errno != EINPROGRESS) {
    perror("connect failed");
    finish(EXIT_FAILURE);
  }

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(iter, 0, 0);
#else
  while (1) iter();
#endif

  return EXIT_SUCCESS;
}

