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
struct option {char* member_0; char member_3; int /*<<< orphan*/  member_2; int /*<<< orphan*/  const member_1; } ;
typedef  int /*<<< orphan*/  LOG_BACKEND ;

/* Variables and functions */
 int /*<<< orphan*/  DAEMON_VERSION_NUMBER ; 
 int /*<<< orphan*/  LOG_BACKEND_STDOUT ; 
 int /*<<< orphan*/  LOG_BACKEND_SYSLOG ; 
 int /*<<< orphan*/  LOG_LEVEL_ERROR ; 
 int /*<<< orphan*/  LOG_LEVEL_INFO ; 
 int /*<<< orphan*/  exit (int) ; 
 int getopt_long (int,char**,char*,struct option*,int /*<<< orphan*/ *) ; 
#define  no_argument 129 
 char* optarg ; 
 scalar_t__ opterr ; 
 int /*<<< orphan*/  optind ; 
#define  required_argument 128 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/  write_log (int /*<<< orphan*/ ,char*,...) ; 

void print_help()
{
    // 2 space ident
    // make sure all lines fit into 80 columns
    // make sure options are listed in alphabetical order
    write_log(LOG_LEVEL_INFO,
              "Usage: tox-bootstrapd [OPTION]... --config=FILE_PATH\n"
              "\n"
              "Options:\n"
              "  --config=FILE_PATH     Specify path to the config file.\n"
              "                         This is a required option.\n"
              "                         Set FILE_PATH to a path to an empty file in order to\n"
              "                         use default settings.\n"
              "  --foreground           Run the daemon in foreground. The daemon won't fork\n"
              "                         (detach from the terminal) and won't use the PID file.\n"
              "  --help                 Print this help message.\n"
              "  --log-backend=BACKEND  Specify which logging backend to use.\n"
              "                         Valid BACKEND values (case sensetive):\n"
              "                           syslog Writes log messages to syslog.\n"
              "                                  Default option when no --log-backend is\n"
              "                                  specified.\n"
              "                           stdout Writes log messages to stdout/stderr.\n"
              "  --version              Print version information.\n");
}

void handle_command_line_arguments(int argc, char *argv[], char **cfg_file_path, LOG_BACKEND *log_backend,
                                   bool *run_in_foreground)
{
    if (argc < 2) {
        write_log(LOG_LEVEL_ERROR, "Error: No arguments provided.\n\n");
        print_help();
        exit(1);
    }

    opterr = 0;

    static struct option long_options[] = {
        {"config",      required_argument, 0, 'c'}, // required option
        {"foreground",  no_argument,       0, 'f'},
        {"help",        no_argument,       0, 'h'},
        {"log-backend", required_argument, 0, 'l'}, // optional, defaults to syslog
        {"version",     no_argument,       0, 'v'},
        {0,             0,                 0,  0 }
    };

    bool cfg_file_path_set = false;
    bool log_backend_set   = false;

    *run_in_foreground = false;

    int opt;

    while ((opt = getopt_long(argc, argv, ":", long_options, NULL)) != -1) {

        switch (opt) {

            case 'c':
                *cfg_file_path = optarg;
                cfg_file_path_set = true;
                break;

            case 'f':
                *run_in_foreground = true;
                break;

            case 'h':
                print_help();
                exit(0);

            case 'l':
                if (strcmp(optarg, "syslog") == 0) {
                    *log_backend = LOG_BACKEND_SYSLOG;
                    log_backend_set = true;
                } else if (strcmp(optarg, "stdout") == 0) {
                    *log_backend = LOG_BACKEND_STDOUT;
                    log_backend_set = true;
                } else {
                    write_log(LOG_LEVEL_ERROR, "Error: Invalid BACKEND value for --log-backend option passed: %s\n\n", optarg);
                    print_help();
                    exit(1);
                }

                break;

            case 'v':
                write_log(LOG_LEVEL_INFO, "Version: %lu\n", DAEMON_VERSION_NUMBER);
                exit(0);

            case '?':
                write_log(LOG_LEVEL_ERROR, "Error: Unrecognized option %s\n\n", argv[optind - 1]);
                print_help();
                exit(1);

            case ':':
                write_log(LOG_LEVEL_ERROR, "Error: No argument provided for option %s\n\n", argv[optind - 1]);
                print_help();
                exit(1);
        }
    }

    if (!log_backend_set) {
        *log_backend = LOG_BACKEND_SYSLOG;
    }

    if (!cfg_file_path_set) {
        write_log(LOG_LEVEL_ERROR, "Error: The required --config option wasn't specified\n\n");
        print_help();
        exit(1);
    }
}

