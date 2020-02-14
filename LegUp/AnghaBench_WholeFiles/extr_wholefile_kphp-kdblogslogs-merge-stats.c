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

/* Variables and functions */
 int MAX_FN ; 
 size_t ansI ; 
 int /*<<< orphan*/  assert (int) ; 
 int atoi (char*) ; 
 scalar_t__ change_user (char*) ; 
 int /*<<< orphan*/  dl_set_debug_handlers () ; 
 int engineF ; 
 int engineN ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/ ** f ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 scalar_t__ fscanf (int /*<<< orphan*/ *,char*,long long*) ; 
 int getopt (int,char**,char*) ; 
 scalar_t__ left_files ; 
 char* optarg ; 
 int optind ; 
 char* out_name ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 char* progname ; 
 int snprintf (char*,int,char*,char*,int) ; 
 char* stat_name ; 
 int /*<<< orphan*/  stderr ; 
 char* username ; 

void init_data (void) {
  char fname[100];
  int i;

  for (i = engineF; i < engineN; i++) {
    if (snprintf (fname, 100, "%s%03d", stat_name, i) >= 100) {
      fprintf (stderr, "Filename is too long.\n");
      exit (1);
    }
    f[i] = fopen (fname, "r");
    if (f[i] == NULL) {
      fprintf (stderr, "File '%s' not found.\n", fname);
      exit (1);
    }
    left_files++;
  }
}

void run (void) {
  while (left_files) {
    long long sum = 0;

    int i;
    for (i = engineF; i < engineN; i++) {
      if (f[i] != NULL) {
        long long cur;
        if (fscanf (f[i], "%lld", &cur) <= 0) {
          left_files--;
        } else {
          sum += cur;
        }
      }
    }

    assert (left_files == 0 || left_files == engineN - engineF);
    if (left_files != 0) {
      fprintf (f[ansI], "%lld\n", sum);
    }
  }
}

void close_data (void) {
  int i;
  for (i = 0; i < MAX_FN; i++) {
    if (f[i] != NULL) {
      fclose (f[i]);
    }
  }
}

void usage (void) {
  printf ("usage: %s [-u] [-o<output_file>] [-F<first_engine_num>][-N<engines_cnt>] <stat_name>\n"
    "Merge engineN binary files \"<stat_name><server_num>\"\n"
    "  server_num is 3 digit number with leading zeros\n"
	  "\t-o\tname of output file\n"
	  "\t-F<first_engine_num>\tnumber of first engine, default 0\n"
	  "\t-N<engines_cnt>\tnumber of last engine plus 1\n",
	  progname);
  exit (2);
}

int main (int argc, char *argv[]) {
  int i;

  dl_set_debug_handlers ();
  progname = argv[0];

  if (argc == 1) {
    usage();
    return 2;
  }

  while ((i = getopt (argc, argv, "hF:N:o:u:")) != -1) {
    switch (i) {
    case 'h':
      usage ();
      return 2;
    case 'F':
      engineF = atoi (optarg);
      break;
    case 'N':
      engineN = atoi (optarg);
      break;
    case 'o':
      out_name = optarg;
      break;
    case 'u':
      username = optarg;
      break;
    }
  }

  if (argc != optind + 1) {
    usage();
    return 2;
  }
  stat_name = argv[optind];

  if (change_user (username) < 0) {
    fprintf (stderr, "fatal: cannot change user to %s\n", username ? username : "(none)");
    exit (1);
  }

  assert (engineN > engineF && engineF >= 0);
  ansI = engineN + 1;

  assert (engineN + 1 < MAX_FN);

  f[ansI] = fopen (out_name, "w");
  assert (f[ansI] != NULL);

  init_data();
  run();
  close_data();

  return 0;
}

