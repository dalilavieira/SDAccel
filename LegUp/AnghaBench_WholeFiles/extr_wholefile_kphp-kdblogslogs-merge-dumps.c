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
 int BUFF_SIZE ; 
 int MAX_FN ; 
 size_t ansI ; 
 int /*<<< orphan*/  assert (int) ; 
 int atoi (char*) ; 
 scalar_t__ change_user (char*) ; 
 void* dl_malloc (int) ; 
 scalar_t__* dl_malloc0 (int) ; 
 scalar_t__ dl_open_file (size_t,char*,int) ; 
 int /*<<< orphan*/  dl_set_debug_handlers () ; 
 char* dump_name ; 
 int engineF ; 
 int engineN ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__* f_buff ; 
 scalar_t__* f_buff_r ; 
 scalar_t__* f_buff_size ; 
 int* fd ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int* fsize ; 
 int getopt (int,char**,char*) ; 
 scalar_t__ left_files ; 
 int /*<<< orphan*/  memcpy (scalar_t__,char*,int) ; 
 char* optarg ; 
 int optind ; 
 char* out_name ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 char* progname ; 
 int read (int,scalar_t__,int) ; 
 int snprintf (char*,int,char*,char*,int) ; 
 int /*<<< orphan*/  stderr ; 
 char* username ; 
 scalar_t__ w_buff ; 
 int w_buff_n ; 
 int /*<<< orphan*/  write (int,scalar_t__,int) ; 

void init_data (void) {
  char fname[100];
  int i;

  f_buff = dl_malloc (sizeof (char *) * engineN);
  f_buff_size = dl_malloc0 (sizeof (int) * engineN);
  f_buff_r = dl_malloc0 (sizeof (int) * engineN);

  for (i = engineF; i < engineN; i++) {
//    if (snprintf (fname, 100, "%s%03d", dump_name, i) >= 100) {
    if (snprintf (fname, 100, "%s%d.dump", dump_name, i) >= 100) {
      fprintf (stderr, "Filename is too long.\n");
      exit (1);
    }
    if (dl_open_file (i, fname, -1) < 0) {
      fprintf (stderr, "File '%s' not found.\n", fname);
      fd[i] = -1;
      continue;
    } else {
//      fprintf (stderr, "Opened file '%s' by pid %d.\n", fname, fd[i]);
    }
    left_files++;
    f_buff[i] = dl_malloc (sizeof (char) * BUFF_SIZE);
  }
}

int load (int en) {
  if (fsize[en] <= 0) {
    assert (fsize[en] == 0);
    return -1;
  }
  if (f_buff_r[en] < f_buff_size[en]) {
//    fprintf (stderr, "%d %d\n", f_buff_r[en], f_buff_size[en]);
    assert (f_buff_r[en] > f_buff_size[en] - f_buff_r[en]);
    memcpy (f_buff[en], f_buff[en] + f_buff_r[en], f_buff_size[en] - f_buff_r[en]);
  }
  f_buff_size[en] -= f_buff_r[en];
  f_buff_r[en] = 0;
  assert (0 <= f_buff_size[en]);

  int need = BUFF_SIZE - f_buff_size[en];
  if (fsize[en] < need) {
    need = fsize[en];
  }

//  fprintf (stderr, "Loading from %d dump %d bytes, already readed %llu, %lld bytes to read\n", en, need, lseek (fd[en], 0, SEEK_CUR), fsize[en]);
  assert (read (fd[en], f_buff[en] + f_buff_size[en], need) == need);
  f_buff_size[en] += need;
  fsize[en] -= need;

  return 1;
}

void flush_w_buff() {
  write (fd[ansI], w_buff, w_buff_n);
  w_buff_n = 0;
}

void my_write (char *s, int n) {
  int i = 0;
  while (i < n) {
    int x = n - i;
    if (x > BUFF_SIZE - w_buff_n) {
      x = BUFF_SIZE - w_buff_n;
    }
    memcpy (w_buff + w_buff_n, s + i, x);
    i += x;
    w_buff_n += x;
    if (w_buff_n == BUFF_SIZE) {
      flush_w_buff();
    }
  }
}

void run (void) {
  int i;
  while (left_files) {
    int min_time = 2147483637, now, size;
    for (i = engineF; i < engineN; i++) {
      if (fd[i] >= 0 && f_buff_size[i] - f_buff_r[i] < 2 * (int)sizeof (int) && load (i) == -1) {
        fd[i] = -1;
        left_files--;
        assert (f_buff_size[i] == f_buff_r[i]);
      }
    }

    for (i = engineF; i < engineN; i++) {
      if (fd[i] >= 0) {
        char *buff = f_buff[i] + f_buff_r[i];
        now = ((int *)buff)[0];
        size = ((int *)buff)[1];
//        fprintf (stderr, "%d %d %d\n", i, now, size);
        if (f_buff_size[i] - f_buff_r[i] < 2 * (int)sizeof (int) + size) {
          if (load (i) == -1 || f_buff_size[i] - f_buff_r[i] < 2 * (int)sizeof (int) + size) {
            fprintf (stderr, "Dump %d is broken. It contains event of size %d. f_buff_size = %d, f_buff_r = %d.\n", i, size, f_buff_size[i], f_buff_r[i]);
            assert (0);
          }
        }
        if (now < min_time) {
          min_time = now;
        }
      }
    }

    for (i = engineF; i < engineN; i++) {
      if (fd[i] >= 0) {
        char *buff = f_buff[i] + f_buff_r[i];
        now = ((int *)buff)[0];
        if (now == min_time) {
          size = ((int *)buff)[1];
          my_write (buff, 2 * sizeof (int) + size);
          f_buff_r[i] += 2 * sizeof (int) + size;
        }
      }
    }
  }
}

void usage (void) {
  printf ("usage: %s [-u] [-o<output_file>] [-N<engineN>] [-d<dump_name>]\n"
    "Merge engineN binary files \"<dump_name><server_num>.dump\"\n"
	  "\t-d\tprefix of dump files, delauit is \"dump\"\n"
	  "\t-o\tname of output binary file\n"
	  "\t-F\tnumber of first engine, default 0\n"
	  "\t-N\tnumber of last engine plus 1\n",
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

  while ((i = getopt (argc, argv, "d:hF:N:o:u:")) != -1) {
    switch (i) {
    case 'd':
      dump_name = optarg;
      break;
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

  if (argc != optind) {
    usage();
    return 2;
  }

  if (change_user (username) < 0) {
    fprintf (stderr, "fatal: cannot change user to %s\n", username ? username : "(none)");
    exit (1);
  }

  assert (engineN > engineF && engineF >= 0);
  ansI = engineN + 1;

  assert (engineN + 1 < MAX_FN);

  dl_open_file (ansI, out_name, 2);

  init_data();
  run();

  flush_w_buff();
  return 0;
}

