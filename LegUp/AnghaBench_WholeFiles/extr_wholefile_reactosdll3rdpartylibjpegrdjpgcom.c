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
 int EOF ; 
 int /*<<< orphan*/  ERREXIT (char*) ; 
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int /*<<< orphan*/  EXIT_SUCCESS ; 
#define  M_APP12 144 
#define  M_COM 143 
#define  M_EOI 142 
#define  M_SOF0 141 
#define  M_SOF1 140 
#define  M_SOF10 139 
#define  M_SOF11 138 
#define  M_SOF13 137 
#define  M_SOF14 136 
#define  M_SOF15 135 
#define  M_SOF2 134 
#define  M_SOF3 133 
#define  M_SOF5 132 
#define  M_SOF6 131 
#define  M_SOF7 130 
#define  M_SOF9 129 
 int M_SOI ; 
#define  M_SOS 128 
 int NEXTBYTE () ; 
 int /*<<< orphan*/  READ_BINARY ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * fopen (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/ * infile ; 
 scalar_t__ isprint (int) ; 
 scalar_t__ isupper (int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 char* progname ; 
 int /*<<< orphan*/  putc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/ * stdin ; 
 int /*<<< orphan*/  stdout ; 
 int tolower (int) ; 

__attribute__((used)) static int
read_1_byte (void)
{
  int c;

  c = NEXTBYTE();
  if (c == EOF)
    ERREXIT("Premature EOF in JPEG file");
  return c;
}

__attribute__((used)) static unsigned int
read_2_bytes (void)
{
  int c1, c2;

  c1 = NEXTBYTE();
  if (c1 == EOF)
    ERREXIT("Premature EOF in JPEG file");
  c2 = NEXTBYTE();
  if (c2 == EOF)
    ERREXIT("Premature EOF in JPEG file");
  return (((unsigned int) c1) << 8) + ((unsigned int) c2);
}

__attribute__((used)) static int
next_marker (void)
{
  int c;
  int discarded_bytes = 0;

  /* Find 0xFF byte; count and skip any non-FFs. */
  c = read_1_byte();
  while (c != 0xFF) {
    discarded_bytes++;
    c = read_1_byte();
  }
  /* Get marker code byte, swallowing any duplicate FF bytes.  Extra FFs
   * are legal as pad bytes, so don't count them in discarded_bytes.
   */
  do {
    c = read_1_byte();
  } while (c == 0xFF);

  if (discarded_bytes != 0) {
    fprintf(stderr, "Warning: garbage data found in JPEG file\n");
  }

  return c;
}

__attribute__((used)) static int
first_marker (void)
{
  int c1, c2;

  c1 = NEXTBYTE();
  c2 = NEXTBYTE();
  if (c1 != 0xFF || c2 != M_SOI)
    ERREXIT("Not a JPEG file");
  return c2;
}

__attribute__((used)) static void
skip_variable (void)
/* Skip over an unknown or uninteresting variable-length marker */
{
  unsigned int length;

  /* Get the marker parameter length count */
  length = read_2_bytes();
  /* Length includes itself, so must be at least 2 */
  if (length < 2)
    ERREXIT("Erroneous JPEG marker length");
  length -= 2;
  /* Skip over the remaining bytes */
  while (length > 0) {
    (void) read_1_byte();
    length--;
  }
}

__attribute__((used)) static void
process_COM (int raw)
{
  unsigned int length;
  int ch;
  int lastch = 0;

  /* Bill Allombert: set locale properly for isprint */
#ifdef HAVE_LOCALE_H
  setlocale(LC_CTYPE, "");
#endif

  /* Get the marker parameter length count */
  length = read_2_bytes();
  /* Length includes itself, so must be at least 2 */
  if (length < 2)
    ERREXIT("Erroneous JPEG marker length");
  length -= 2;

  while (length > 0) {
    ch = read_1_byte();
    if (raw) {
      putc(ch, stdout);
    /* Emit the character in a readable form.
     * Nonprintables are converted to \nnn form,
     * while \ is converted to \\.
     * Newlines in CR, CR/LF, or LF form will be printed as one newline.
     */
    } else if (ch == '\r') {
      printf("\n");
    } else if (ch == '\n') {
      if (lastch != '\r')
	printf("\n");
    } else if (ch == '\\') {
      printf("\\\\");
    } else if (isprint(ch)) {
      putc(ch, stdout);
    } else {
      printf("\\%03o", ch);
    }
    lastch = ch;
    length--;
  }
  printf("\n");

  /* Bill Allombert: revert to C locale */
#ifdef HAVE_LOCALE_H
  setlocale(LC_CTYPE, "C");
#endif
}

__attribute__((used)) static void
process_SOFn (int marker)
{
  unsigned int length;
  unsigned int image_height, image_width;
  int data_precision, num_components;
  const char * process;
  int ci;

  length = read_2_bytes();	/* usual parameter length count */

  data_precision = read_1_byte();
  image_height = read_2_bytes();
  image_width = read_2_bytes();
  num_components = read_1_byte();

  switch (marker) {
  case M_SOF0:	process = "Baseline";  break;
  case M_SOF1:	process = "Extended sequential";  break;
  case M_SOF2:	process = "Progressive";  break;
  case M_SOF3:	process = "Lossless";  break;
  case M_SOF5:	process = "Differential sequential";  break;
  case M_SOF6:	process = "Differential progressive";  break;
  case M_SOF7:	process = "Differential lossless";  break;
  case M_SOF9:	process = "Extended sequential, arithmetic coding";  break;
  case M_SOF10:	process = "Progressive, arithmetic coding";  break;
  case M_SOF11:	process = "Lossless, arithmetic coding";  break;
  case M_SOF13:	process = "Differential sequential, arithmetic coding";  break;
  case M_SOF14:	process = "Differential progressive, arithmetic coding"; break;
  case M_SOF15:	process = "Differential lossless, arithmetic coding";  break;
  default:	process = "Unknown";  break;
  }

  printf("JPEG image is %uw * %uh, %d color components, %d bits per sample\n",
	 image_width, image_height, num_components, data_precision);
  printf("JPEG process: %s\n", process);

  if (length != (unsigned int) (8 + num_components * 3))
    ERREXIT("Bogus SOF marker length");

  for (ci = 0; ci < num_components; ci++) {
    (void) read_1_byte();	/* Component ID code */
    (void) read_1_byte();	/* H, V sampling factors */
    (void) read_1_byte();	/* Quantization table number */
  }
}

__attribute__((used)) static int
scan_JPEG_header (int verbose, int raw)
{
  int marker;

  /* Expect SOI at start of file */
  if (first_marker() != M_SOI)
    ERREXIT("Expected SOI marker first");

  /* Scan miscellaneous markers until we reach SOS. */
  for (;;) {
    marker = next_marker();
    switch (marker) {
      /* Note that marker codes 0xC4, 0xC8, 0xCC are not, and must not be,
       * treated as SOFn.  C4 in particular is actually DHT.
       */
    case M_SOF0:		/* Baseline */
    case M_SOF1:		/* Extended sequential, Huffman */
    case M_SOF2:		/* Progressive, Huffman */
    case M_SOF3:		/* Lossless, Huffman */
    case M_SOF5:		/* Differential sequential, Huffman */
    case M_SOF6:		/* Differential progressive, Huffman */
    case M_SOF7:		/* Differential lossless, Huffman */
    case M_SOF9:		/* Extended sequential, arithmetic */
    case M_SOF10:		/* Progressive, arithmetic */
    case M_SOF11:		/* Lossless, arithmetic */
    case M_SOF13:		/* Differential sequential, arithmetic */
    case M_SOF14:		/* Differential progressive, arithmetic */
    case M_SOF15:		/* Differential lossless, arithmetic */
      if (verbose)
	process_SOFn(marker);
      else
	skip_variable();
      break;

    case M_SOS:			/* stop before hitting compressed data */
      return marker;

    case M_EOI:			/* in case it's a tables-only JPEG stream */
      return marker;

    case M_COM:
      process_COM(raw);
      break;

    case M_APP12:
      /* Some digital camera makers put useful textual information into
       * APP12 markers, so we print those out too when in -verbose mode.
       */
      if (verbose) {
	printf("APP12 contains:\n");
	process_COM(raw);
      } else
	skip_variable();
      break;

    default:			/* Anything else just gets skipped */
      skip_variable();		/* we assume it has a parameter count... */
      break;
    }
  } /* end loop */
}

__attribute__((used)) static void
usage (void)
/* complain about bad command line */
{
  fprintf(stderr, "rdjpgcom displays any textual comments in a JPEG file.\n");

  fprintf(stderr, "Usage: %s [switches] [inputfile]\n", progname);

  fprintf(stderr, "Switches (names may be abbreviated):\n");
  fprintf(stderr, "  -raw        Display non-printable characters in comments (unsafe)\n");
  fprintf(stderr, "  -verbose    Also display dimensions of JPEG image\n");

  exit(EXIT_FAILURE);
}

__attribute__((used)) static int
keymatch (char * arg, const char * keyword, int minchars)
/* Case-insensitive matching of (possibly abbreviated) keyword switches. */
/* keyword is the constant keyword (must be lower case already), */
/* minchars is length of minimum legal abbreviation. */
{
  register int ca, ck;
  register int nmatched = 0;

  while ((ca = *arg++) != '\0') {
    if ((ck = *keyword++) == '\0')
      return 0;			/* arg longer than keyword, no good */
    if (isupper(ca))		/* force arg to lcase (assume ck is already) */
      ca = tolower(ca);
    if (ca != ck)
      return 0;			/* no good */
    nmatched++;			/* count matched characters */
  }
  /* reached end of argument; fail if it's too short for unique abbrev */
  if (nmatched < minchars)
    return 0;
  return 1;			/* A-OK */
}

int
main (int argc, char **argv)
{
  int argn;
  char * arg;
  int verbose = 0, raw = 0;

  /* On Mac, fetch a command line. */
#ifdef USE_CCOMMAND
  argc = ccommand(&argv);
#endif

  progname = argv[0];
  if (progname == NULL || progname[0] == 0)
    progname = "rdjpgcom";	/* in case C library doesn't provide it */

  /* Parse switches, if any */
  for (argn = 1; argn < argc; argn++) {
    arg = argv[argn];
    if (arg[0] != '-')
      break;			/* not switch, must be file name */
    arg++;			/* advance over '-' */
    if (keymatch(arg, "verbose", 1)) {
      verbose++;
    } else if (keymatch(arg, "raw", 1)) {
      raw = 1;
    } else
      usage();
  }

  /* Open the input file. */
  /* Unix style: expect zero or one file name */
  if (argn < argc-1) {
    fprintf(stderr, "%s: only one input file\n", progname);
    usage();
  }
  if (argn < argc) {
    if ((infile = fopen(argv[argn], READ_BINARY)) == NULL) {
      fprintf(stderr, "%s: can't open %s\n", progname, argv[argn]);
      exit(EXIT_FAILURE);
    }
  } else {
    /* default input file is stdin */
#ifdef USE_SETMODE		/* need to hack file mode? */
    setmode(fileno(stdin), O_BINARY);
#endif
#ifdef USE_FDOPEN		/* need to re-open in binary mode? */
    if ((infile = fdopen(fileno(stdin), READ_BINARY)) == NULL) {
      fprintf(stderr, "%s: can't open stdin\n", progname);
      exit(EXIT_FAILURE);
    }
#else
    infile = stdin;
#endif
  }

  /* Scan the JPEG headers. */
  (void) scan_JPEG_header(verbose, raw);

  /* All done. */
  exit(EXIT_SUCCESS);
  return 0;			/* suppress no-return-value warnings */
}

