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
struct tree {int dummy; } ;
struct parse {int dummy; } ;

/* Variables and functions */
 char* FullVersionStr ; 
 int O_CREAT ; 
 int O_TRUNC ; 
 int O_WRONLY ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  atoi (char*) ; 
 int /*<<< orphan*/  close (int) ; 
 int dynamic_data_buffer_size ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  init_dyn_data () ; 
 int open (char const*,int,int) ; 
 char* optarg ; 
 int optind ; 
 int /*<<< orphan*/  output_expressions ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  schema_version ; 
 int /*<<< orphan*/  set_debug_handlers () ; 
 int /*<<< orphan*/  stderr ; 
 struct parse* tl_init_parse_file (char*) ; 
 int /*<<< orphan*/  tl_parse (struct tree*) ; 
 struct tree* tl_parse_lex (struct parse*) ; 
 int /*<<< orphan*/  tl_print_parse_error () ; 
 scalar_t__ verbosity ; 
 int /*<<< orphan*/  write_types (int) ; 

void usage (void) {
  printf ("%s\n",  FullVersionStr);
  printf ("usage: tlc-new [-v] [-h] <TL-schema-file>\n"
      "\tTL compiler\n"
      "\t-v\toutput statistical and debug information into stderr\n"
      "\t-E\twhenever is possible output to stdout expressions\n"
      "\t-e <file>\texport serialized schema to file\n"
      "\t-w\t custom version of serialized schema (0 - very old, 1 - old, 2 - current (default))\n"
       );
  exit (2);
}

int vkext_write (const char *filename) {
  int f = open (filename, O_CREAT | O_WRONLY | O_TRUNC, 0640);
  assert (f >= 0);
  write_types (f);
  close (f);
  return 0;
}

int main (int argc, char **argv) {
  int i;
  char *expr_filename = NULL;
  char *vkext_file = 0;
  set_debug_handlers ();
  while ((i = getopt (argc, argv, "Eho:ve:w:")) != -1) {
    switch (i) {
    case 'E':
      output_expressions++;
      break;
    case 'o':
      expr_filename = optarg;
      break;
    case 'h':
      usage ();
      return 2;
    case 'e':
      vkext_file = optarg;
      break;
    case 'w':
      schema_version = atoi (optarg);
      break;
    case 'v':
      verbosity++;
      break;
    }
  }

  dynamic_data_buffer_size = (1 << 30);

  if (argc != optind + 1) {
    usage ();
  }
  init_dyn_data ();
 
  struct parse *P = tl_init_parse_file (argv[optind]);
  if (!P) {
    return 0;
  }
  struct tree *T;
  if (!(T = tl_parse_lex (P))) {
    fprintf (stderr, "Error in parse:\n");
    tl_print_parse_error ();
    return 0;
  } else {
    if (verbosity) {
      fprintf (stderr, "Parse ok\n");
    }
    if (!tl_parse (T)) {
      if (verbosity) {
        fprintf (stderr, "Fail\n");
      }
      return 1;
    } else {
      if (verbosity) {
        fprintf (stderr, "Ok\n");
      }
    }
  }
  if (vkext_file) {
    vkext_write (vkext_file);
  }
  return 0;
}

