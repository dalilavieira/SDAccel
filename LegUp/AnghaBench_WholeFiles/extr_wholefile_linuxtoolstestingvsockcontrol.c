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
typedef  int /*<<< orphan*/  val ;
struct addrinfo {int /*<<< orphan*/  ai_addrlen; int /*<<< orphan*/  ai_addr; int /*<<< orphan*/  ai_protocol; int /*<<< orphan*/  ai_socktype; int /*<<< orphan*/  ai_family; struct addrinfo* ai_next; } ;
typedef  int ssize_t ;

/* Variables and functions */
 scalar_t__ EINTR ; 
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  MSG_MORE ; 
 int /*<<< orphan*/  SOCK_STREAM ; 
 int /*<<< orphan*/  SOL_SOCKET ; 
 int /*<<< orphan*/  SO_REUSEADDR ; 
 int /*<<< orphan*/  TIMEOUT ; 
 int accept (int,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 scalar_t__ bind (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  close (int) ; 
 scalar_t__ connect (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int control_fd ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  freeaddrinfo (struct addrinfo*) ; 
 char* gai_strerror (int) ; 
 int getaddrinfo (char const*,char const*,struct addrinfo*,struct addrinfo**) ; 
 scalar_t__ listen (int,int) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 char* realloc (char*,size_t) ; 
 int recv (int,char*,int,int /*<<< orphan*/ ) ; 
 int send (int,char const*,int,int /*<<< orphan*/ ) ; 
 scalar_t__ setsockopt (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int*,int) ; 
 int socket (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdout ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int strlen (char const*) ; 
 int /*<<< orphan*/  timeout_begin (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  timeout_check (char*) ; 
 int /*<<< orphan*/  timeout_end () ; 

void control_init(const char *control_host,
		  const char *control_port,
		  bool server)
{
	struct addrinfo hints = {
		.ai_socktype = SOCK_STREAM,
	};
	struct addrinfo *result = NULL;
	struct addrinfo *ai;
	int ret;

	ret = getaddrinfo(control_host, control_port, &hints, &result);
	if (ret != 0) {
		fprintf(stderr, "%s\n", gai_strerror(ret));
		exit(EXIT_FAILURE);
	}

	for (ai = result; ai; ai = ai->ai_next) {
		int fd;
		int val = 1;

		fd = socket(ai->ai_family, ai->ai_socktype, ai->ai_protocol);
		if (fd < 0)
			continue;

		if (!server) {
			if (connect(fd, ai->ai_addr, ai->ai_addrlen) < 0)
				goto next;
			control_fd = fd;
			printf("Control socket connected to %s:%s.\n",
			       control_host, control_port);
			break;
		}

		if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR,
			       &val, sizeof(val)) < 0) {
			perror("setsockopt");
			exit(EXIT_FAILURE);
		}

		if (bind(fd, ai->ai_addr, ai->ai_addrlen) < 0)
			goto next;
		if (listen(fd, 1) < 0)
			goto next;

		printf("Control socket listening on %s:%s\n",
		       control_host, control_port);
		fflush(stdout);

		control_fd = accept(fd, NULL, 0);
		close(fd);

		if (control_fd < 0) {
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf("Control socket connection accepted...\n");
		break;

next:
		close(fd);
	}

	if (control_fd < 0) {
		fprintf(stderr, "Control socket initialization failed.  Invalid address %s:%s?\n",
			control_host, control_port);
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(result);
}

void control_cleanup(void)
{
	close(control_fd);
	control_fd = -1;
}

void control_writeln(const char *str)
{
	ssize_t len = strlen(str);
	ssize_t ret;

	timeout_begin(TIMEOUT);

	do {
		ret = send(control_fd, str, len, MSG_MORE);
		timeout_check("send");
	} while (ret < 0 && errno == EINTR);

	if (ret != len) {
		perror("send");
		exit(EXIT_FAILURE);
	}

	do {
		ret = send(control_fd, "\n", 1, 0);
		timeout_check("send");
	} while (ret < 0 && errno == EINTR);

	if (ret != 1) {
		perror("send");
		exit(EXIT_FAILURE);
	}

	timeout_end();
}

char *control_readln(void)
{
	char *buf = NULL;
	size_t idx = 0;
	size_t buflen = 0;

	timeout_begin(TIMEOUT);

	for (;;) {
		ssize_t ret;

		if (idx >= buflen) {
			char *new_buf;

			new_buf = realloc(buf, buflen + 80);
			if (!new_buf) {
				perror("realloc");
				exit(EXIT_FAILURE);
			}

			buf = new_buf;
			buflen += 80;
		}

		do {
			ret = recv(control_fd, &buf[idx], 1, 0);
			timeout_check("recv");
		} while (ret < 0 && errno == EINTR);

		if (ret == 0) {
			fprintf(stderr, "unexpected EOF on control socket\n");
			exit(EXIT_FAILURE);
		}

		if (ret != 1) {
			perror("recv");
			exit(EXIT_FAILURE);
		}

		if (buf[idx] == '\n') {
			buf[idx] = '\0';
			break;
		}

		idx++;
	}

	timeout_end();

	return buf;
}

void control_expectln(const char *str)
{
	char *line;

	line = control_readln();
	if (strcmp(str, line) != 0) {
		fprintf(stderr, "expected \"%s\" on control socket, got \"%s\"\n",
			str, line);
		exit(EXIT_FAILURE);
	}

	free(line);
}

