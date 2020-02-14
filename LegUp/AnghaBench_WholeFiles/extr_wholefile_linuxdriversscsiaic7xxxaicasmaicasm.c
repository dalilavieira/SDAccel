#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_8__ ;
typedef  struct TYPE_15__   TYPE_7__ ;
typedef  struct TYPE_14__   TYPE_6__ ;
typedef  struct TYPE_13__   TYPE_5__ ;
typedef  struct TYPE_12__   TYPE_4__ ;
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ u_int ;
struct ins_format3 {scalar_t__ address; } ;
struct TYPE_15__ {int* bytes; struct ins_format3 format3; } ;
struct instruction {scalar_t__ type; int quoted_includes_only; int patch_func; int begin; int skip_instr; int skip_patch; int begin_addr; int end_addr; int func_num; int srcline; int /*<<< orphan*/  inner_scope_patches; TYPE_8__* patches; int /*<<< orphan*/  inner_scope; TYPE_7__ format; TYPE_6__* symbol; TYPE_3__* patch_label; int /*<<< orphan*/ * directory; } ;
typedef  struct instruction symbol_node_t ;
typedef  struct instruction scope_t ;
typedef  struct instruction* path_entry_t ;
typedef  struct instruction patch_t ;
struct TYPE_16__ {scalar_t__ skip_instr; int skip_patch; } ;
typedef  TYPE_8__ patch_info_t ;
typedef  struct instruction critical_section_t ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_13__ {TYPE_4__* condinfo; } ;
struct TYPE_14__ {char* name; TYPE_5__ info; } ;
struct TYPE_12__ {int func_num; } ;
struct TYPE_10__ {TYPE_1__* linfo; } ;
struct TYPE_11__ {scalar_t__ type; char* name; TYPE_2__ info; } ;
struct TYPE_9__ {scalar_t__ address; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int EX_CANTCREAT ; 
 int EX_DATAERR ; 
 int EX_OSERR ; 
 int EX_SOFTWARE ; 
 int EX_USAGE ; 
 scalar_t__ LABEL ; 
#define  SCOPE_ELSE 131 
#define  SCOPE_ELSE_IF 130 
#define  SCOPE_IF 129 
#define  SCOPE_ROOT 128 
 struct instruction* SLIST_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SLIST_INIT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  SLIST_INSERT_HEAD (int /*<<< orphan*/ *,struct instruction*,int /*<<< orphan*/ ) ; 
 struct instruction* SLIST_NEXT (struct instruction*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SOURCE_FILE ; 
 struct instruction* STAILQ_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  STAILQ_INIT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  STAILQ_INSERT_TAIL (int /*<<< orphan*/ *,struct instruction*,int /*<<< orphan*/ ) ; 
 struct instruction* STAILQ_NEXT (struct instruction*,int /*<<< orphan*/ ) ; 
 struct instruction* TAILQ_FIRST (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TAILQ_INIT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TAILQ_INSERT_TAIL (int /*<<< orphan*/ *,struct instruction*,int /*<<< orphan*/ ) ; 
 struct instruction* TAILQ_LAST (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 struct instruction* TAILQ_NEXT (struct instruction*,int /*<<< orphan*/ ) ; 
 struct instruction* TAILQ_PREV (struct instruction*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* appname ; 
static  void back_patch () ; 
static  int check_patch (struct instruction**,int,int*,int*) ; 
 int /*<<< orphan*/  cs_tailq ; 
static  void dump_scope (struct instruction*) ; 
 void emit_patch (struct instruction*,int) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fileno (int /*<<< orphan*/ ) ; 
 void* fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ *,char*,...) ; 
 int getchar () ; 
 int getopt (int,char**,char*) ; 
 int /*<<< orphan*/  include_file (char*,int /*<<< orphan*/ ) ; 
 int includes_search_curdir ; 
 scalar_t__ isatty (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  links ; 
 int /*<<< orphan*/ * listfile ; 
 char* listfilename ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memset (struct instruction*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * ofile ; 
 char* ofilename ; 
static  void output_code () ; 
 void output_listing (char*) ; 
 char* patch_arg_list ; 
 int /*<<< orphan*/  patch_functions ; 
 int /*<<< orphan*/  patches ; 
 int /*<<< orphan*/  perror (char*) ; 
 char* prefix ; 
 void process_scope (struct instruction*) ; 
 int /*<<< orphan*/  putchar (int) ; 
 int /*<<< orphan*/ * regdiagfile ; 
 char* regdiagfilename ; 
 int /*<<< orphan*/ * regfile ; 
 char* regfilename ; 
 struct instruction* scope_alloc () ; 
 int /*<<< orphan*/  scope_links ; 
 int /*<<< orphan*/  scope_stack ; 
 int /*<<< orphan*/  scope_stack_links ; 
 int /*<<< orphan*/  scope_tailq ; 
 int /*<<< orphan*/  search_path ; 
 int /*<<< orphan*/  seq_program ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,char*) ; 
 int /*<<< orphan*/ * stderr ; 
 int /*<<< orphan*/  stdin ; 
 int /*<<< orphan*/  stdout ; 
 char* stock_include_file ; 
 void stop (char const*,int) ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 
 int /*<<< orphan*/ * strdup (char*) ; 
 int /*<<< orphan*/  symlist_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  symtable_close () ; 
 int /*<<< orphan*/  symtable_dump (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  symtable_open () ; 
 int toupper (int) ; 
 int /*<<< orphan*/  unlink (char*) ; 
static  void usage () ; 
 char* versions ; 
 char* yyfilename ; 
 int yylineno ; 
 int yyparse () ; 

int
main(int argc, char *argv[])
{
	extern char *optarg;
	extern int optind;
	int  ch;
	int  retval;
	char *inputfilename;
	scope_t *sentinal;

	STAILQ_INIT(&patches);
	SLIST_INIT(&search_path);
	STAILQ_INIT(&seq_program);
	TAILQ_INIT(&cs_tailq);
	SLIST_INIT(&scope_stack);

	/* Set Sentinal scope node */
	sentinal = scope_alloc();
	sentinal->type = SCOPE_ROOT;
	
	includes_search_curdir = 1;
	appname = *argv;
	regfile = NULL;
	listfile = NULL;
#if DEBUG
	yy_flex_debug = 0;
	mm_flex_debug = 0;
	yydebug = 0;
	mmdebug = 0;
#endif
	while ((ch = getopt(argc, argv, "d:i:l:n:o:p:r:I:")) != -1) {
		switch(ch) {
		case 'd':
#if DEBUG
			if (strcmp(optarg, "s") == 0) {
				yy_flex_debug = 1;
				mm_flex_debug = 1;
			} else if (strcmp(optarg, "p") == 0) {
				yydebug = 1;
				mmdebug = 1;
			} else {
				fprintf(stderr, "%s: -d Requires either an "
					"'s' or 'p' argument\n", appname);
				usage();
			}
#else
			stop("-d: Assembler not built with debugging "
			     "information", EX_SOFTWARE);
#endif
			break;
		case 'i':
			stock_include_file = optarg;
			break;
		case 'l':
			/* Create a program listing */
			if ((listfile = fopen(optarg, "w")) == NULL) {
				perror(optarg);
				stop(NULL, EX_CANTCREAT);
			}
			listfilename = optarg;
			break;
		case 'n':
			/* Don't complain about the -nostdinc directrive */
			if (strcmp(optarg, "ostdinc")) {
				fprintf(stderr, "%s: Unknown option -%c%s\n",
					appname, ch, optarg);
				usage();
				/* NOTREACHED */
			}
			break;
		case 'o':
			if ((ofile = fopen(optarg, "w")) == NULL) {
				perror(optarg);
				stop(NULL, EX_CANTCREAT);
			}
			ofilename = optarg;
			break;
		case 'p':
			/* Create Register Diagnostic "printing" Functions */
			if ((regdiagfile = fopen(optarg, "w")) == NULL) {
				perror(optarg);
				stop(NULL, EX_CANTCREAT);
			}
			regdiagfilename = optarg;
			break;
		case 'r':
			if ((regfile = fopen(optarg, "w")) == NULL) {
				perror(optarg);
				stop(NULL, EX_CANTCREAT);
			}
			regfilename = optarg;
			break;
		case 'I':
		{
			path_entry_t include_dir;

			if (strcmp(optarg, "-") == 0) {
				if (includes_search_curdir == 0) {
					fprintf(stderr, "%s: Warning - '-I-' "
							"specified multiple "
							"times\n", appname);
				}
				includes_search_curdir = 0;
				for (include_dir = SLIST_FIRST(&search_path);
				     include_dir != NULL;
				     include_dir = SLIST_NEXT(include_dir,
							      links))
					/*
					 * All entries before a '-I-' only
					 * apply to includes specified with
					 * quotes instead of "<>".
					 */
					include_dir->quoted_includes_only = 1;
			} else {
				include_dir =
				    (path_entry_t)malloc(sizeof(*include_dir));
				if (include_dir == NULL) {
					perror(optarg);
					stop(NULL, EX_OSERR);
				}
				include_dir->directory = strdup(optarg);
				if (include_dir->directory == NULL) {
					perror(optarg);
					stop(NULL, EX_OSERR);
				}
				include_dir->quoted_includes_only = 0;
				SLIST_INSERT_HEAD(&search_path, include_dir,
						  links);
			}
			break;
		}
		case '?':
		default:
			usage();
			/* NOTREACHED */
		}
	}
	argc -= optind;
	argv += optind;

	if (argc != 1) {
		fprintf(stderr, "%s: No input file specified\n", appname);
		usage();
		/* NOTREACHED */
	}

	if (regdiagfile != NULL
	 && (regfile == NULL || stock_include_file == NULL)) {
		fprintf(stderr,
			"%s: The -p option requires the -r and -i options.\n",
			appname);
		usage();
		/* NOTREACHED */
	}
	symtable_open();
	inputfilename = *argv;
	include_file(*argv, SOURCE_FILE);
	retval = yyparse();
	if (retval == 0) {
		if (SLIST_FIRST(&scope_stack) == NULL
		 || SLIST_FIRST(&scope_stack)->type != SCOPE_ROOT) {
			stop("Unterminated conditional expression", EX_DATAERR);
			/* NOTREACHED */
		}

		/* Process outmost scope */
		process_scope(SLIST_FIRST(&scope_stack));
		/*
		 * Decend the tree of scopes and insert/emit
		 * patches as appropriate.  We perform a depth first
		 * tranversal, recursively handling each scope.
		 */
		/* start at the root scope */
		dump_scope(SLIST_FIRST(&scope_stack));

		/* Patch up forward jump addresses */
		back_patch();

		if (ofile != NULL)
			output_code();
		if (regfile != NULL)
			symtable_dump(regfile, regdiagfile);
		if (listfile != NULL)
			output_listing(inputfilename);
	}

	stop(NULL, 0);
	/* NOTREACHED */
	return (0);
}

__attribute__((used)) static void
usage()
{

	(void)fprintf(stderr,
"usage: %-16s [-nostdinc] [-I-] [-I directory] [-o output_file]\n"
"	[-r register_output_file [-p register_diag_file -i includefile]]\n"
"	[-l program_list_file]\n"
"	input_file\n", appname);
	exit(EX_USAGE);
}

__attribute__((used)) static void
back_patch()
{
	struct instruction *cur_instr;

	for (cur_instr = STAILQ_FIRST(&seq_program);
	     cur_instr != NULL;
	     cur_instr = STAILQ_NEXT(cur_instr, links)) {
		if (cur_instr->patch_label != NULL) {
			struct ins_format3 *f3_instr;
			u_int address;

			if (cur_instr->patch_label->type != LABEL) {
				char buf[255];

				snprintf(buf, sizeof(buf),
					 "Undefined label %s",
					 cur_instr->patch_label->name);
				stop(buf, EX_DATAERR);
				/* NOTREACHED */
			}
			f3_instr = &cur_instr->format.format3;
			address = f3_instr->address;
			address += cur_instr->patch_label->info.linfo->address;
			f3_instr->address = address;
		}
	}
}

__attribute__((used)) static void
output_code()
{
	struct instruction *cur_instr;
	patch_t *cur_patch;
	critical_section_t *cs;
	symbol_node_t *cur_node;
	int instrcount;

	instrcount = 0;
	fprintf(ofile,
"/*\n"
" * DO NOT EDIT - This file is automatically generated\n"
" *		 from the following source files:\n"
" *\n"
"%s */\n", versions);

	fprintf(ofile, "static const uint8_t seqprog[] = {\n");
	for (cur_instr = STAILQ_FIRST(&seq_program);
	     cur_instr != NULL;
	     cur_instr = STAILQ_NEXT(cur_instr, links)) {

		fprintf(ofile, "%s\t0x%02x, 0x%02x, 0x%02x, 0x%02x",
			cur_instr == STAILQ_FIRST(&seq_program) ? "" : ",\n",
#ifdef __LITTLE_ENDIAN
			cur_instr->format.bytes[0],
			cur_instr->format.bytes[1],
			cur_instr->format.bytes[2],
			cur_instr->format.bytes[3]);
#else
			cur_instr->format.bytes[3],
			cur_instr->format.bytes[2],
			cur_instr->format.bytes[1],
			cur_instr->format.bytes[0]);
#endif
		instrcount++;
	}
	fprintf(ofile, "\n};\n\n");

	if (patch_arg_list == NULL)
		stop("Patch argument list not defined",
		     EX_DATAERR);

	/*
	 *  Output patch information.  Patch functions first.
	 */
	fprintf(ofile,
"typedef int %spatch_func_t (%s);\n", prefix, patch_arg_list);

	for (cur_node = SLIST_FIRST(&patch_functions);
	     cur_node != NULL;
	     cur_node = SLIST_NEXT(cur_node,links)) {
		fprintf(ofile,
"static %spatch_func_t %spatch%d_func;\n"
"\n"
"static int\n"
"%spatch%d_func(%s)\n"
"{\n"
"	return (%s);\n"
"}\n\n",
			prefix,
			prefix,
			cur_node->symbol->info.condinfo->func_num,
			prefix,
			cur_node->symbol->info.condinfo->func_num,
			patch_arg_list,
			cur_node->symbol->name);
	}

	fprintf(ofile,
"static const struct patch {\n"
"	%spatch_func_t		*patch_func;\n"
"	uint32_t		 begin		:10,\n"
"				 skip_instr	:10,\n"
"				 skip_patch	:12;\n"
"} patches[] = {\n", prefix);

	for (cur_patch = STAILQ_FIRST(&patches);
	     cur_patch != NULL;
	     cur_patch = STAILQ_NEXT(cur_patch,links)) {
		fprintf(ofile, "%s\t{ %spatch%d_func, %d, %d, %d }",
			cur_patch == STAILQ_FIRST(&patches) ? "" : ",\n",
			prefix,
			cur_patch->patch_func, cur_patch->begin,
			cur_patch->skip_instr, cur_patch->skip_patch);
	}

	fprintf(ofile, "\n};\n\n");

	fprintf(ofile,
"static const struct cs {\n"
"	uint16_t	begin;\n"
"	uint16_t	end;\n"
"} critical_sections[] = {\n");

	for (cs = TAILQ_FIRST(&cs_tailq);
	     cs != NULL;
	     cs = TAILQ_NEXT(cs, links)) {
		fprintf(ofile, "%s\t{ %d, %d }",
			cs == TAILQ_FIRST(&cs_tailq) ? "" : ",\n",
			cs->begin_addr, cs->end_addr);
	}

	fprintf(ofile, "\n};\n\n");

	fprintf(ofile,
	"#define NUM_CRITICAL_SECTIONS ARRAY_SIZE(critical_sections)\n");

	fprintf(stderr, "%s: %d instructions used\n", appname, instrcount);
}

__attribute__((used)) static void
dump_scope(scope_t *scope)
{
	scope_t *cur_scope;

	/*
	 * Emit the first patch for this scope
	 */
	emit_patch(scope, 0);

	/*
	 * Dump each scope within this one.
	 */
	cur_scope = TAILQ_FIRST(&scope->inner_scope);

	while (cur_scope != NULL) {

		dump_scope(cur_scope);

		cur_scope = TAILQ_NEXT(cur_scope, scope_links);
	}

	/*
	 * Emit the second, closing, patch for this scope
	 */
	emit_patch(scope, 1);
}

void
emit_patch(scope_t *scope, int patch)
{
	patch_info_t *pinfo;
	patch_t *new_patch;

	pinfo = &scope->patches[patch];

	if (pinfo->skip_instr == 0)
		/* No-Op patch */
		return;

	new_patch = (patch_t *)malloc(sizeof(*new_patch));

	if (new_patch == NULL)
		stop("Could not malloc patch structure", EX_OSERR);

	memset(new_patch, 0, sizeof(*new_patch));

	if (patch == 0) {
		new_patch->patch_func = scope->func_num;
		new_patch->begin = scope->begin_addr;
	} else {
		new_patch->patch_func = 0;
		new_patch->begin = scope->end_addr;
	}
	new_patch->skip_instr = pinfo->skip_instr;
	new_patch->skip_patch = pinfo->skip_patch;
	STAILQ_INSERT_TAIL(&patches, new_patch, links);
}

void
output_listing(char *ifilename)
{
	char buf[1024];
	FILE *ifile;
	struct instruction *cur_instr;
	patch_t *cur_patch;
	symbol_node_t *cur_func;
	int *func_values;
	int instrcount;
	int instrptr;
	int line;
	int func_count;
	int skip_addr;

	instrcount = 0;
	instrptr = 0;
	line = 1;
	skip_addr = 0;
	if ((ifile = fopen(ifilename, "r")) == NULL) {
		perror(ifilename);
		stop(NULL, EX_DATAERR);
	}

	/*
	 * Determine which options to apply to this listing.
	 */
	for (func_count = 0, cur_func = SLIST_FIRST(&patch_functions);
	    cur_func != NULL;
	    cur_func = SLIST_NEXT(cur_func, links))
		func_count++;

	func_values = NULL;
	if (func_count != 0) {
		func_values = (int *)malloc(func_count * sizeof(int));

		if (func_values == NULL)
			stop("Could not malloc", EX_OSERR);
		
		func_values[0] = 0; /* FALSE func */
		func_count--;

		/*
		 * Ask the user to fill in the return values for
		 * the rest of the functions.
		 */
		
		
		for (cur_func = SLIST_FIRST(&patch_functions);
		     cur_func != NULL && SLIST_NEXT(cur_func, links) != NULL;
		     cur_func = SLIST_NEXT(cur_func, links), func_count--) {
			int input;
			
			fprintf(stdout, "\n(%s)\n", cur_func->symbol->name);
			fprintf(stdout,
				"Enter the return value for "
				"this expression[T/F]:");

			while (1) {

				input = getchar();
				input = toupper(input);

				if (input == 'T') {
					func_values[func_count] = 1;
					break;
				} else if (input == 'F') {
					func_values[func_count] = 0;
					break;
				}
			}
			if (isatty(fileno(stdin)) == 0)
				putchar(input);
		}
		fprintf(stdout, "\nThanks!\n");
	}

	/* Now output the listing */
	cur_patch = STAILQ_FIRST(&patches);
	for (cur_instr = STAILQ_FIRST(&seq_program);
	     cur_instr != NULL;
	     cur_instr = STAILQ_NEXT(cur_instr, links), instrcount++) {

		if (check_patch(&cur_patch, instrcount,
				&skip_addr, func_values) == 0) {
			/* Don't count this instruction as it is in a patch
			 * that was removed.
			 */
                        continue;
		}

		while (line < cur_instr->srcline) {
			fgets(buf, sizeof(buf), ifile);
				fprintf(listfile, "             \t%s", buf);
				line++;
		}
		fprintf(listfile, "%04x %02x%02x%02x%02x", instrptr,
#ifdef __LITTLE_ENDIAN
			cur_instr->format.bytes[0],
			cur_instr->format.bytes[1],
			cur_instr->format.bytes[2],
			cur_instr->format.bytes[3]);
#else
			cur_instr->format.bytes[3],
			cur_instr->format.bytes[2],
			cur_instr->format.bytes[1],
			cur_instr->format.bytes[0]);
#endif
		/*
		 * Macro expansions can cause several instructions
		 * to be output for a single source line.  Only
		 * advance the line once in these cases.
		 */
		if (line == cur_instr->srcline) {
			fgets(buf, sizeof(buf), ifile);
			fprintf(listfile, "\t%s", buf);
			line++;
		} else {
			fprintf(listfile, "\n");
		}
		instrptr++;
	}
	/* Dump the remainder of the file */
	while(fgets(buf, sizeof(buf), ifile) != NULL)
		fprintf(listfile, "             %s", buf);

	fclose(ifile);
}

__attribute__((used)) static int
check_patch(patch_t **start_patch, int start_instr,
	    int *skip_addr, int *func_vals)
{
	patch_t *cur_patch;

	cur_patch = *start_patch;

	while (cur_patch != NULL && start_instr == cur_patch->begin) {
		if (func_vals[cur_patch->patch_func] == 0) {
			int skip;

			/* Start rejecting code */
			*skip_addr = start_instr + cur_patch->skip_instr;
			for (skip = cur_patch->skip_patch;
			     skip > 0 && cur_patch != NULL;
			     skip--)
				cur_patch = STAILQ_NEXT(cur_patch, links);
		} else {
			/* Accepted this patch.  Advance to the next
			 * one and wait for our intruction pointer to
			 * hit this point.
			 */
			cur_patch = STAILQ_NEXT(cur_patch, links);
		}
	}

	*start_patch = cur_patch;
	if (start_instr < *skip_addr)
		/* Still skipping */
		return (0);

	return (1);
}

void
stop(const char *string, int err_code)
{
	if (string != NULL) {
		fprintf(stderr, "%s: ", appname);
		if (yyfilename != NULL) {
			fprintf(stderr, "Stopped at file %s, line %d - ",
				yyfilename, yylineno);
		}
		fprintf(stderr, "%s\n", string);
	}

	if (ofile != NULL) {
		fclose(ofile);
		if (err_code != 0) {
			fprintf(stderr, "%s: Removing %s due to error\n",
				appname, ofilename);
			unlink(ofilename);
		}
	}

	if (regfile != NULL) {
		fclose(regfile);
		if (err_code != 0) {
			fprintf(stderr, "%s: Removing %s due to error\n",
				appname, regfilename);
			unlink(regfilename);
		}
	}

	if (listfile != NULL) {
		fclose(listfile);
		if (err_code != 0) {
			fprintf(stderr, "%s: Removing %s due to error\n",
				appname, listfilename);
			unlink(listfilename);
		}
	}

	symlist_free(&patch_functions);
	symtable_close();

	exit(err_code);
}

struct instruction *
seq_alloc()
{
	struct instruction *new_instr;

	new_instr = (struct instruction *)malloc(sizeof(struct instruction));
	if (new_instr == NULL)
		stop("Unable to malloc instruction object", EX_SOFTWARE);
	memset(new_instr, 0, sizeof(*new_instr));
	STAILQ_INSERT_TAIL(&seq_program, new_instr, links);
	new_instr->srcline = yylineno;
	return new_instr;
}

critical_section_t *
cs_alloc()
{
	critical_section_t *new_cs;

	new_cs= (critical_section_t *)malloc(sizeof(critical_section_t));
	if (new_cs == NULL)
		stop("Unable to malloc critical_section object", EX_SOFTWARE);
	memset(new_cs, 0, sizeof(*new_cs));
	
	TAILQ_INSERT_TAIL(&cs_tailq, new_cs, links);
	return new_cs;
}

scope_t *
scope_alloc()
{
	scope_t *new_scope;

	new_scope = (scope_t *)malloc(sizeof(scope_t));
	if (new_scope == NULL)
		stop("Unable to malloc scope object", EX_SOFTWARE);
	memset(new_scope, 0, sizeof(*new_scope));
	TAILQ_INIT(&new_scope->inner_scope);
	
	if (SLIST_FIRST(&scope_stack) != NULL) {
		TAILQ_INSERT_TAIL(&SLIST_FIRST(&scope_stack)->inner_scope,
				  new_scope, scope_links);
	}
	/* This patch is now the current scope */
	SLIST_INSERT_HEAD(&scope_stack, new_scope, scope_stack_links);
	return new_scope;
}

void
process_scope(scope_t *scope)
{
	/*
	 * We are "leaving" this scope.  We should now have
	 * enough information to process the lists of scopes
	 * we encapsulate.
	 */
	scope_t *cur_scope;
	u_int skip_patch_count;
	u_int skip_instr_count;

	cur_scope = TAILQ_LAST(&scope->inner_scope, scope_tailq);
	skip_patch_count = 0;
	skip_instr_count = 0;
	while (cur_scope != NULL) {
		u_int patch0_patch_skip;

		patch0_patch_skip = 0;
		switch (cur_scope->type) {
		case SCOPE_IF:
		case SCOPE_ELSE_IF:
			if (skip_instr_count != 0) {
				/* Create a tail patch */
				patch0_patch_skip++;
				cur_scope->patches[1].skip_patch =
				    skip_patch_count + 1;
				cur_scope->patches[1].skip_instr =
				    skip_instr_count;
			}

			/* Count Head patch */
			patch0_patch_skip++;

			/* Count any patches contained in our inner scope */
			patch0_patch_skip += cur_scope->inner_scope_patches;

			cur_scope->patches[0].skip_patch = patch0_patch_skip;
			cur_scope->patches[0].skip_instr =
			    cur_scope->end_addr - cur_scope->begin_addr;

			skip_instr_count += cur_scope->patches[0].skip_instr;

			skip_patch_count += patch0_patch_skip;
			if (cur_scope->type == SCOPE_IF) {
				scope->inner_scope_patches += skip_patch_count;
				skip_patch_count = 0;
			        skip_instr_count = 0;
			}
			break;
		case SCOPE_ELSE:
			/* Count any patches contained in our innter scope */
			skip_patch_count += cur_scope->inner_scope_patches;

			skip_instr_count += cur_scope->end_addr
					  - cur_scope->begin_addr;
			break;
		case SCOPE_ROOT:
			stop("Unexpected scope type encountered", EX_SOFTWARE);
			/* NOTREACHED */
		}

		cur_scope = TAILQ_PREV(cur_scope, scope_tailq, scope_links);
	}
}

