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
struct linebuffer {int length; int size; char* buffer; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int EOF ; 
 int /*<<< orphan*/  exit (int) ; 
 int fclose (int /*<<< orphan*/ *) ; 
 scalar_t__ feof (int /*<<< orphan*/ *) ; 
 scalar_t__ ferror (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char*,...) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  fwrite (char*,int,int,int /*<<< orphan*/ *) ; 
 int getc (int /*<<< orphan*/ *) ; 
 void* malloc (size_t) ; 
 int memcmp (char const*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  min (size_t,size_t) ; 
 char* program_name ; 
 void* realloc (void*,size_t) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * stdin ; 
 int /*<<< orphan*/ * stdout ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 

__attribute__((used)) static void
xalloc_fail (void)
{
  fprintf (stderr, "%s: virtual memory exhausted\n", program_name);
  exit (1);
}

void *
xmalloc (size_t n)
{
  void *p;

  p = malloc (n);
  if (p == 0)
    xalloc_fail ();
  return p;
}

void *
xrealloc (void *p, size_t n)
{
  p = realloc (p, n);
  if (p == 0)
    xalloc_fail ();
  return p;
}

__attribute__((used)) static void
initbuffer (struct linebuffer *linebuffer)
{
  linebuffer->length = 0;
  linebuffer->size = 200;
  linebuffer->buffer = (char *) xmalloc (linebuffer->size);
}

__attribute__((used)) static struct linebuffer *
readline (struct linebuffer *linebuffer, FILE *stream)
{
  int c;
  char *buffer = linebuffer->buffer;
  char *p = linebuffer->buffer;
  char *end = buffer + linebuffer->size - 1; /* Sentinel. */

  if (feof (stream) || ferror (stream))
    return 0;

  do
    {
      c = getc (stream);
      if (c == EOF)
        {
          if (p == buffer)
            return 0;
          if (p[-1] == '\n')
            break;
          c = '\n';
        }
      if (p == end)
        {
          linebuffer->size *= 2;
          buffer = (char *) xrealloc (buffer, linebuffer->size);
          p = p - linebuffer->buffer + buffer;
          linebuffer->buffer = buffer;
          end = buffer + linebuffer->size - 1;
        }
      *p++ = c;
    }
  while (c != '\n');

  linebuffer->length = p - buffer;
  return linebuffer;
}

__attribute__((used)) static void
freebuffer (struct linebuffer *linebuffer)
{
  free (linebuffer->buffer);
}

__attribute__((used)) static int
different (const char *old, const char *new, size_t oldlen, size_t newlen)
{
  int order;

  order = memcmp (old, new, min (oldlen, newlen));

  if (order == 0)
    return oldlen - newlen;
  return order;
}

__attribute__((used)) static void
writeline (const struct linebuffer *line, FILE *stream, int linecount)
{
  if (linecount == 0)
    fwrite (line->buffer, 1, line->length, stream);
}

__attribute__((used)) static void
check_file (const char *infile, const char *outfile)
{
  FILE *istream;
  FILE *ostream;
  struct linebuffer lb1, lb2;
  struct linebuffer *thisline, *prevline, *exch;
  char *prevfield, *thisfield;
  size_t prevlen, thislen;
  int match_count = 0;

  if (!strcmp (infile, "-"))
    istream = stdin;
  else
    istream = fopen (infile, "r");
  if (istream == NULL)
    {
      fprintf (stderr, "%s: error opening %s\n", program_name, infile);
      exit (1);
    }

  if (!strcmp (outfile, "-"))
    ostream = stdout;
  else
    ostream = fopen (outfile, "w");
  if (ostream == NULL)
    {
      fprintf (stderr, "%s: error opening %s\n", program_name, outfile);
      exit (1);
    }

  thisline = &lb1;
  prevline = &lb2;

  initbuffer (thisline);
  initbuffer (prevline);

  if (readline (prevline, istream) == 0)
    goto closefiles;
  prevfield = prevline->buffer;
  prevlen = prevline->length;

  while (!feof (istream))
    {
      int match;
      if (readline (thisline, istream) == 0)
        break;
      thisfield = thisline->buffer;
      thislen = thisline->length;
      match = !different (thisfield, prevfield, thislen, prevlen);

      if (match)
        ++match_count;

      if (!match)
        {
          writeline (prevline, ostream, match_count);
          exch = prevline;
          prevline = thisline;
          thisline = exch;
          prevfield = thisfield;
          prevlen = thislen;
          if (!match)
            match_count = 0;
        }
    }

  writeline (prevline, ostream, match_count);

 closefiles:
  if (ferror (istream) || fclose (istream) == EOF)
    {
      fprintf (stderr, "%s: error reading %s\n", program_name, infile);
      exit (1);
    }

  if (ferror (ostream) || fclose (ostream) == EOF)
    {
      fprintf (stderr, "%s: error writing %s\n", program_name, outfile);
      exit (1);
    }

  freebuffer (&lb1);
  freebuffer (&lb2);
}

int
main (int argc, char **argv)
{
  const char *infile = "-";
  const char *outfile = "-";
  int optind = 1;

  program_name = argv[0];

  if (optind < argc)
    infile = argv[optind++];

  if (optind < argc)
    outfile = argv[optind++];

  if (optind < argc)
    {
      fprintf (stderr, "%s: too many arguments\n", program_name);
      exit (1);
    }

  check_file (infile, outfile);

  exit (0);
}

