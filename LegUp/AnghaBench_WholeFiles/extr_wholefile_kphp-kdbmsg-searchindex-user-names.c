#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int user_id; int users; scalar_t__ hash; int* offset; int /*<<< orphan*/  magic; } ;
typedef  TYPE_1__ userpair_t ;
struct username_index {int dummy; } ;
typedef  scalar_t__ hash_t ;

/* Variables and functions */
 int Dc ; 
 int MAX_PAIRS ; 
 int MAX_USERS ; 
 int /*<<< orphan*/  O_RDONLY ; 
 TYPE_1__* P ; 
 int Pc ; 
 TYPE_1__ U ; 
 int /*<<< orphan*/  USERNAME_HASH_INDEX_MAGIC ; 
 void* UU ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  close (scalar_t__) ; 
 int /*<<< orphan*/  exit (int) ; 
 scalar_t__ fd ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int getopt (int,char**,char*) ; 
 void* malloc (int) ; 
 scalar_t__ open (char*,int /*<<< orphan*/ ) ; 
 int optind ; 
 int /*<<< orphan*/  printf (char*,char*) ; 
 char* progname ; 
 int read (scalar_t__,TYPE_1__*,int) ; 
 int /*<<< orphan*/  stderr ; 
 int verbose ; 
 int write (int,TYPE_1__*,int) ; 

void my_psort (int a, int b) {
  userpair_t t;
  int h, i, j;
  if (a >= b) return;
  i = a;  j = b;
  h = P[(a+b)>>1].user_id;
  do {
    while (P[i].user_id < h) i++;
    while (P[j].user_id > h) j--;
    if (i <= j) {
      t = P[i];  P[i++] = P[j];  P[j--] = t;
    }
  } while (i <= j);
  my_psort (a, j);
  my_psort (i, b);
}

int percent (long long a, long long b) {
  if (b <= 0 || a <= 0) return 0;
  if (a >= b) return 100;
  return (a*100 / b);
}

void output_stats (void) {
  fprintf (stderr, "%d hashes read (max %ld), %d hashes written, describing users up to %d (max %ld)\n", 
	   Pc, MAX_PAIRS, Dc, U.users, MAX_USERS);
}

void usage (void) {
  printf ("usage: %s [-v] <members-hash-file-1> [<members-hash-file-2> ...]\n"
	  "\tCreates a user name index from a (concatenation of) user name hash files\n"
	  "\tResulting index file is written to stdout\n"
	  "\t-v\toutput statistical information into stderr\n",
	  progname);
  exit(2);
}

int main (int argc, char *argv[]) {
  int i, r;
  hash_t p = 0;
  progname = argv[0];
  while ((i = getopt (argc, argv, "hv")) != -1) {
    switch (i) {
    case 'v':
      verbose = 1;
      break;
    case 'h':
      usage();
      return 2;
    }
  }
  if (argc <= optind) {
    usage();
    return 2;
  }

  P = malloc (MAX_PAIRS * sizeof (userpair_t));
  UU = malloc (sizeof (struct username_index));
  assert (P && UU);

  while (optind < argc) {
    fd = open (argv[optind], O_RDONLY);
    if (fd < 0) {
      fprintf (stderr, "%s: cannot open() %s: %m\n", progname, argv[optind]);
      optind++;
      continue;
    }
    r = (MAX_PAIRS - Pc) * sizeof(userpair_t);
    i = read (fd, P + Pc, r);
    if (i < 0) {
      fprintf (stderr, "%s: error reading %s: %m\n", progname, argv[optind]);
      return 1;
    }
    if (i == r) {
      fprintf (stderr, "%s: error reading %s: hash space exhausted (%ld entries)\n", progname, argv[optind], MAX_PAIRS);
      return 1;
    }
    Pc += i / sizeof(userpair_t);    
    close (fd);
    optind++;
  }

  my_psort(0, Pc-1);

  for (i = 0; i < Pc; i++) {
    int j = P[i].user_id;
    hash_t h = P[i].hash;
    assert (j < MAX_USERS-3);
    while (U.users <= j) {
      U.offset[U.users++] = Dc;
      p = 0;
    }
    if (h != p) {
      ((hash_t *) P)[Dc++] = h;
      p = h;
    }
  }
  U.offset[U.users++] = Dc;
  if (U.users & 1) { U.offset[U.users++] = Dc; }

  U.magic = USERNAME_HASH_INDEX_MAGIC;
  r = 8 + 4 * U.users;
  assert (write (1, &U, r) == r);
  r = Dc * 8;
  assert (write (1, P, r) == r);

  if (verbose) {
    output_stats();
  }
                                      
  return 0;
}

