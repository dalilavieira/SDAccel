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
struct sockaddr_in {int length; int* buffer; int /*<<< orphan*/  sin_addr; int /*<<< orphan*/  sin_port; int /*<<< orphan*/  sin_family; } ;
struct sockaddr {int dummy; } ;
typedef  int ssize_t ;
typedef  int /*<<< orphan*/  socklen_t ;
typedef  struct sockaddr_in msg_t ;
typedef  int /*<<< orphan*/  fd_set ;
typedef  int /*<<< orphan*/  addr ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 scalar_t__ EAGAIN ; 
 scalar_t__ EINPROGRESS ; 
 int EXIT_FAILURE ; 
 int EXIT_SUCCESS ; 
 int /*<<< orphan*/  FD_ISSET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_SET (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  F_SETFL ; 
 int /*<<< orphan*/  IPPROTO_TCP ; 
 int /*<<< orphan*/  MESSAGE ; 
 int /*<<< orphan*/  O_NONBLOCK ; 
 int /*<<< orphan*/  PF_INET ; 
 int /*<<< orphan*/  SOCKK ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  close (int) ; 
 int connect (int,struct sockaddr*,int) ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fcntl (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  htons (int /*<<< orphan*/ ) ; 
 int inet_pton (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 void* malloc (int) ; 
 int /*<<< orphan*/  memset (struct sockaddr_in*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 struct sockaddr_in readmsg ; 
 int recvfrom (int,int*,int,int /*<<< orphan*/ ,struct sockaddr*,int /*<<< orphan*/ *) ; 
 int select (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int send (int,int*,int,int /*<<< orphan*/ ) ; 
 int sendto (int,int*,int,int /*<<< orphan*/ ,struct sockaddr*,int /*<<< orphan*/ ) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int sockfd ; 
 int strlen (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  strncpy (int*,int /*<<< orphan*/ ,int) ; 
 struct sockaddr_in writemsg ; 

int do_msg_read(int sockfd, msg_t *msg, int offset, int length, struct sockaddr *addr, socklen_t *addrlen) {
  int res;

  if (!msg->length) {
    // read the message length
    res = recvfrom(sockfd, &msg->length, sizeof(int), 0, addr, addrlen);
    if (res == -1) {
      assert(errno == EAGAIN);
      return res;
    } else if (res == 0) {
      return 0;
    }

    printf("do_msg_read: allocating %d bytes for message\n", msg->length);

    msg->buffer = malloc(msg->length);
  }

  // read the actual message
  int max = msg->length - offset;
  if (length && max > length) {
    max = length;
  }
  res = recvfrom(sockfd, msg->buffer + offset, max, 0, addr, addrlen);
  if (res == -1) {
    assert(errno == EAGAIN);
    return res;
  }

  printf("do_msg_read: read %d bytes\n", res);

  return res;
}

int do_msg_write(int sockfd, msg_t *msg, int offset, int length, struct sockaddr *addr, socklen_t addrlen) {
  int res;

  // send the message length first
  if (!offset) {
    if (addr) {
      res = sendto(sockfd, &msg->length, sizeof(int), 0, addr, addrlen);
    } else {
      res = send(sockfd, &msg->length, sizeof(int), 0);
    }
    if (res == -1) {
      assert(errno == EAGAIN);
      return res;
    }
    printf("do_msg_write: sending message header for %d bytes\n", msg->length);
    assert(res == sizeof(int));
  }

  // then the actual message
  int max = msg->length - offset;
  if (length && max > length) {
    max = length;
  }
  if (addr) {
    res = sendto(sockfd, msg->buffer + offset, max, 0, addr, addrlen);
  } else {
    res = send(sockfd, msg->buffer + offset, max, 0);
  }
  if (res == -1) {
    assert(errno == EAGAIN);
    return res;
  }

  printf("do_msg_write: wrote %d bytes %d\n", res, msg->length);

  return res;
}

void finish(int result) {
  close(sockfd);
#ifdef __EMSCRIPTEN__
  REPORT_RESULT(result);
  emscripten_force_exit(result);
#else
  exit(result);
#endif
}

void main_loop() {
  static int state = 0;
  static int readPos = 0;
  static int writePos = 0;
  int selectRes;
  ssize_t transferAmount;
  fd_set sett;  
  
  switch (state) {
    case 0:
      // writing 10 bytes to the server
      
      // since the socket in the read file descriptors has no available data,
      // select should tell us 0 handles are ready
      FD_ZERO(&sett);
      FD_SET(sockfd, &sett);
      selectRes = select(64, &sett, NULL, NULL, NULL);
      if (selectRes != 0) {
        printf("case 0: read select != 0 (%d)\n", selectRes);
        finish(EXIT_FAILURE);
      }
      
      // the socket in the write file descriptors has to result in either a 0 or 1
      // the connection either is setting up or is established and writing is possible
      FD_ZERO(&sett);
      FD_SET(sockfd, &sett);
      selectRes = select(64, NULL, &sett, NULL, NULL);
      if (selectRes == -1) {
        printf("case 0: write select == -1\n");
        finish(EXIT_FAILURE);
      } else if (selectRes == 0) {
        return;
      }
      
      // send a single byte
      transferAmount = do_msg_write(sockfd, &writemsg, writePos, 1, NULL, 0);
      if (transferAmount != -1) writePos += transferAmount;
   
      // after 10 bytes switch to next state
      if (writePos >= writemsg.length) {
        state = 1;
      }
      break;
      
    case 1:
      // wait until we can read one byte to make sure the server
      // has sent the data and then closed the connection
      FD_ZERO(&sett);
      FD_SET(sockfd, &sett);
      selectRes = select(64, &sett, NULL, NULL, NULL);
      if (selectRes == -1) {
        printf("case 1: read selectRes == -1\n");
        finish(EXIT_FAILURE);
      } else if (selectRes == 0) {
        return;
      }

      // read a single byte
      transferAmount = do_msg_read(sockfd, &readmsg, readPos, 1, NULL, NULL);
      if (transferAmount == 0) {
        perror("server closed");
        finish(EXIT_FAILURE);
      } else if (transferAmount != -1) {
        readPos += transferAmount;
      }
   
      // if successfully reading 1 byte, switch to next state
      if (readPos >= 1) {
        state = 2;
      }
      break;
    
    case 2:
      // calling select with the socket in the write file descriptors should
      // succeed, but the socket should not set in the set.
      FD_ZERO(&sett);
      FD_SET(sockfd, &sett);
      selectRes = select(64, NULL, &sett, NULL, NULL);
      if (selectRes != 0 || FD_ISSET(sockfd, &sett)) {
        printf("case 2: write selectRes != 0 || FD_ISSET(sockfd, &sett)\n");
        finish(EXIT_FAILURE);
      }

      // calling select with the socket in the read file descriptors 
      // has to succeed because there is still data in the inQueue
      FD_ZERO(&sett);
      FD_SET(sockfd, &sett);
      selectRes = select(64, &sett, NULL, NULL, NULL);
      if (selectRes != 1) {
        printf("case 2: read selectRes != 1\n");
        finish(EXIT_FAILURE);
      } else if (selectRes == 0) {
        return;
      }
      
      // read a single byte
      transferAmount = do_msg_read(sockfd, &readmsg, readPos, 1, NULL, NULL);
      if (transferAmount == 0) {
        perror("server closed");
        finish(EXIT_FAILURE);
      } else if (transferAmount != -1) {
        readPos += transferAmount;
      }
      
      // with 10 bytes read the inQueue is empty => switch state
      if (readPos >= readmsg.length) {
        state = 3;
      }
      break;
      
    case 3:
      // calling select with the socket in the read file descriptors 
      // should succeed
      FD_ZERO(&sett);
      FD_SET(sockfd, &sett);
      selectRes = select(64, &sett, NULL, NULL, NULL);
      if (selectRes != 1) {
        printf("case 3: read selectRes != 1\n");
        finish(EXIT_FAILURE);
      }

      // but recv should return 0 signaling the remote
      // end has closed the connection.
      transferAmount = do_msg_read(sockfd, &readmsg, readPos, 0, NULL, NULL);
      if (transferAmount) {
        printf("case 3: read != 0\n");
        finish(EXIT_FAILURE);
      }
      
      // report back success, the 266 is just an arbitrary value without 
      // deeper meaning
      finish(266);
      break;
      
    default:
      printf("Impossible state!\n");
      finish(EXIT_FAILURE);
      break;
  }
  
  return;
}

int main() {
  struct sockaddr_in addr;
  int res;

  memset(&readmsg, 0, sizeof(msg_t));
  memset(&writemsg, 0, sizeof(msg_t));
  writemsg.length = strlen(MESSAGE) + 1;
  writemsg.buffer = malloc(writemsg.length);
  strncpy(writemsg.buffer, MESSAGE, writemsg.length);

  sockfd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sockfd == -1) {
    perror("cannot create socket");
    finish(EXIT_FAILURE);
  }
  fcntl(sockfd, F_SETFL, O_NONBLOCK);

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(SOCKK);
  if (inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr) != 1) {
    perror("inet_pton failed");
    finish(EXIT_FAILURE);
  }

  // This call should succeed (even if the server port is closed)
  res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (res == -1 && errno != EINPROGRESS) {
    perror("connect failed");
    finish(EXIT_FAILURE);
  }

#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(main_loop, 0, 0);
#else
  while (1) main_loop();
#endif

  return EXIT_SUCCESS;
}

