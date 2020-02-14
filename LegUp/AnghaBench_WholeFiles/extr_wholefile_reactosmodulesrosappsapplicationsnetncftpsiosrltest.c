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
struct sockaddr_in {int dummy; } ;
typedef  int /*<<< orphan*/  cliAddrStr ;
typedef  int /*<<< orphan*/  buf ;
typedef  int /*<<< orphan*/  bbuf ;
typedef  int /*<<< orphan*/  SReadlineInfo ;

/* Variables and functions */
 char* AddrToAddrStr (char*,int,struct sockaddr_in*,int,char*) ; 
 scalar_t__ InitSReadlineInfo (int /*<<< orphan*/ *,int,char*,int,int) ; 
 int SAccept (int,struct sockaddr_in*,int) ; 
 int /*<<< orphan*/  SClose (int,int) ; 
 int SNewStreamServer (int,int,int /*<<< orphan*/ ,int) ; 
 int SReadline (int /*<<< orphan*/ *,char*,int) ; 
 int SWrite (int,char*,int,int) ; 
 int /*<<< orphan*/  WNOHANG ; 
 int atoi (char*) ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  errno ; 
 int /*<<< orphan*/  exit (int) ; 
 int fork () ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ getpid () ; 
 scalar_t__ islower (char) ; 
 int /*<<< orphan*/  kReUseAddrYes ; 
 int kTimeoutErr ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,int,...) ; 
 int /*<<< orphan*/  stderr ; 
 char* strerror (int /*<<< orphan*/ ) ; 
 char toupper (char) ; 
 scalar_t__ waitpid (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
ServeOneClient(int sockfd, struct sockaddr_in *cliAddr)
{
	char buf[80], cliAddrStr[64];
	char bbuf[320];
	int nread, nwrote, i;
	SReadlineInfo srl;

	printf("subserver[%d]: started, connected to %s.\n", (int) getpid(),
		AddrToAddrStr(cliAddrStr, sizeof(cliAddrStr), cliAddr, 1, "<%h:%p>")
	);

	if (InitSReadlineInfo(&srl, sockfd, bbuf, sizeof(bbuf), 5) < 0) {
		fprintf(stderr, "subserver[%d]: InitSReadlineInfo error: %s\n",
			(int) getpid(), strerror(errno));
		exit(1);
	}
	for (;;) {
		nread = SReadline(&srl, buf, sizeof(buf));
		if (nread == 0) {
			break;
		} else if (nread == kTimeoutErr) {
			printf("subserver[%d]: idle\n", (int) getpid());
			continue;
		} else if (nread < 0) {
			fprintf(stderr, "subserver[%d]: read error: %s\n",
				(int) getpid(), strerror(errno));
			break;
		}
		for (i=0; i<nread; i++)
			if (islower(buf[i]))
				buf[i] = toupper(buf[i]);
		nwrote = SWrite(sockfd, buf, nread, 15);
		if (nwrote < 0) {
			fprintf(stderr, "subserver[%d]: write error: %s\n",
				(int) getpid(), strerror(errno));
			break;
		}
	}
	(void) SClose(sockfd, 10);
	printf("subserver[%d]: done.\n", (int) getpid());
	exit(0);
}

__attribute__((used)) static void
Server(int port)
{
	int sockfd, newsockfd;
	struct sockaddr_in cliAddr;
	int pid;

	sockfd = SNewStreamServer(port, 3, kReUseAddrYes, 3);
	if (sockfd < 0) {
		perror("Server setup failed");
		exit(1);
	}

	printf("server[%d]: started.\n", (int) getpid());
	for(;;) {
		while (waitpid(-1, NULL, WNOHANG) > 0) ;
		newsockfd = SAccept(sockfd, &cliAddr, 5);
		if (newsockfd < 0) {
			if (newsockfd == kTimeoutErr)
				printf("server[%d]: idle\n", (int) getpid());
			else
				fprintf(stderr, "server[%d]: accept error: %s\n",
					(int) getpid(), strerror(errno));
		} else if ((pid = fork()) < 0) {
			fprintf(stderr, "server[%d]: fork error: %s\n",
				(int) getpid(), strerror(errno));
			exit(1);
		} else if (pid == 0) {
			ServeOneClient(newsockfd, &cliAddr);
			exit(0);
		} else {
			/* Parent doesn't need it now. */
			(void) close(newsockfd);
		}
	}
}

void
main(int argc, char **argv)
{
	int port;

	if (argc < 2) {
		fprintf(stderr, "Usage: %s <port>\n", argv[0]);
		exit(2);
	}
	port = atoi(argv[1]);
	Server(port);
	exit(0);
}

