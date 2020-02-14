#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  bind_port; int /*<<< orphan*/  bind_host; int /*<<< orphan*/  idle_timeout; } ;
typedef  TYPE_1__ server_config ;
typedef  int /*<<< orphan*/  config ;

/* Variables and functions */
 int /*<<< orphan*/  DEFAULT_BIND_HOST ; 
 int /*<<< orphan*/  DEFAULT_BIND_PORT ; 
 int /*<<< orphan*/  DEFAULT_IDLE_TIMEOUT ; 
 int /*<<< orphan*/  exit (int) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  optarg ; 
static  void parse_opts (TYPE_1__*,int,char**) ; 
 int /*<<< orphan*/  pr_err (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printf (char*,char const*) ; 
 char const* progname ; 
 int server_run (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int sscanf (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
static  void usage () ; 
 int /*<<< orphan*/  uv_default_loop () ; 

int main(int argc, char **argv) {
  server_config config;
  int err;

  progname = argv[0];
  memset(&config, 0, sizeof(config));
  config.bind_host = DEFAULT_BIND_HOST;
  config.bind_port = DEFAULT_BIND_PORT;
  config.idle_timeout = DEFAULT_IDLE_TIMEOUT;
  parse_opts(&config, argc, argv);

  err = server_run(&config, uv_default_loop());
  if (err) {
    exit(1);
  }

  return 0;
}

const char *_getprogname(void) {
  return progname;
}

__attribute__((used)) static void parse_opts(server_config *cf, int argc, char **argv) {
  int opt;

  while (-1 != (opt = getopt(argc, argv, "b:hp:"))) {
    switch (opt) {
      case 'b':
        cf->bind_host = optarg;
        break;

      case 'p':
        if (1 != sscanf(optarg, "%hu", &cf->bind_port)) {
          pr_err("bad port number: %s", optarg);
          usage();
        }
        break;

      default:
        usage();
    }
  }
}

__attribute__((used)) static void usage(void) {
  printf("Usage:\n"
         "\n"
         "  %s [-b <address>] [-h] [-p <port>]\n"
         "\n"
         "Options:\n"
         "\n"
         "  -b <hostname|address>  Bind to this address or hostname.\n"
         "                         Default: \"127.0.0.1\"\n"
         "  -h                     Show this help message.\n"
         "  -p <port>              Bind to this port number.  Default: 1080\n"
         "",
         progname);
  exit(1);
}

