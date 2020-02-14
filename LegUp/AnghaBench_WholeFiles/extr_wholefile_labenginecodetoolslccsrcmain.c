#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_5__ ;
typedef  struct TYPE_44__   TYPE_39__ ;
typedef  struct TYPE_43__   TYPE_36__ ;
typedef  struct TYPE_42__   TYPE_31__ ;
typedef  struct TYPE_41__   TYPE_30__ ;
typedef  struct TYPE_40__   TYPE_1__ ;

/* Type definitions */
struct TYPE_45__ {void* sclass; void* type; } ;
struct TYPE_44__ {void (* stabend ) (TYPE_1__*,TYPE_1__*,TYPE_1__**,TYPE_1__**,TYPE_1__**) ;void (* stabline ) (TYPE_1__*) ;char little_endian; char mulops_calls; char wants_callb; char wants_argb; char left_to_right; char wants_dag; int /*<<< orphan*/  (* stabtype ) (TYPE_1__*) ;int /*<<< orphan*/  (* defsymbol ) (TYPE_5__*) ;int /*<<< orphan*/  (* progend ) () ;int /*<<< orphan*/  (* stabinit ) (char*,int,char**) ;int /*<<< orphan*/  (* progbeg ) (int,char**) ;} ;
struct TYPE_43__ {char* name; TYPE_39__* ir; } ;
struct TYPE_42__ {scalar_t__ end; } ;
struct TYPE_41__ {void (* stabline ) (TYPE_1__*) ;void (* stabend ) (TYPE_1__*,TYPE_1__*,TYPE_1__**,TYPE_1__**,TYPE_1__**) ;} ;
struct TYPE_40__ {char* file; scalar_t__ y; scalar_t__ sclass; scalar_t__ x; } ;
typedef  TYPE_1__* Symbol ;
typedef  int /*<<< orphan*/  FILE ;
typedef  TYPE_1__ Coordinate ;

/* Variables and functions */
 int /*<<< orphan*/  Aflag ; 
 int /*<<< orphan*/  EXIT_FAILURE ; 
 void* EXTERN ; 
 int /*<<< orphan*/  GLOBAL ; 
 TYPE_39__* IR ; 
 int /*<<< orphan*/  PERM ; 
 int /*<<< orphan*/  Pflag ; 
 scalar_t__ TYPEDEF ; 
 TYPE_5__* YYcheck ; 
 TYPE_5__* YYnull ; 
 int /*<<< orphan*/  apply (scalar_t__,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ *) ; 
 int atoi (char*) ; 
 TYPE_36__* bindings ; 
 char* comment ; 
 char* currentfile ; 
 scalar_t__ currentline ; 
 int /*<<< orphan*/  deallocate (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  density ; 
 scalar_t__ errcnt ; 
 int errlimit ; 
 TYPE_31__ events ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fgets (char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  finalize () ; 
 char* firstfile ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  foreach (int /*<<< orphan*/ ,int /*<<< orphan*/ ,void (*) (TYPE_1__*,void*),TYPE_1__**) ; 
 int /*<<< orphan*/  fprint (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/ * freopen (char*,char*,int /*<<< orphan*/ ) ; 
 void* func (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gettok () ; 
 int glevel ; 
 int /*<<< orphan*/  globals ; 
 int /*<<< orphan*/  identifiers ; 
 int /*<<< orphan*/  init (int,char**) ; 
 void* install (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ lineno ; 
 int /*<<< orphan*/  loci ; 
 TYPE_1__** ltov (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memset (TYPE_31__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  print (char*,char*,char*) ; 
 int /*<<< orphan*/  program () ; 
 char* rcsid ; 
 int /*<<< orphan*/  rewind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * srcfp ; 
 scalar_t__ srcpos ; 
 TYPE_30__ stabIR ; 
static  void stabend (TYPE_1__*,TYPE_1__*,TYPE_1__**,TYPE_1__**,TYPE_1__**) ; 
static  void stabline (TYPE_1__*) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  stdin ; 
 int /*<<< orphan*/  stdout ; 
 char* strchr (char*,char) ; 
 scalar_t__ strcmp (char*,char*) ; 
 char* string (char*) ; 
 char* stringn (char*,int) ; 
 scalar_t__ strncmp (char*,char*,int) ; 
 int /*<<< orphan*/  strtod (char*,int /*<<< orphan*/ *) ; 
 int strtol (char*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub1 (int,char**) ; 
 void stub10 (TYPE_1__*) ; 
 void stub11 (TYPE_1__*,TYPE_1__*,TYPE_1__**,TYPE_1__**,TYPE_1__**) ; 
 int /*<<< orphan*/  stub2 (char*,int,char**) ; 
 void stub3 (TYPE_1__*,TYPE_1__*,TYPE_1__**,TYPE_1__**,TYPE_1__**) ; 
 void stub4 (TYPE_1__*,TYPE_1__*,TYPE_1__**,TYPE_1__**,TYPE_1__**) ; 
 int /*<<< orphan*/  stub5 () ; 
 int /*<<< orphan*/  stub6 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub7 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub8 (TYPE_5__*) ; 
 int /*<<< orphan*/  stub9 (TYPE_1__*) ; 
 int /*<<< orphan*/  symbols ; 
 int /*<<< orphan*/  t ; 
 int /*<<< orphan*/  type_init (int,char**) ; 
 int /*<<< orphan*/  types ; 
static  void typestab (TYPE_1__*,void*) ; 
 int /*<<< orphan*/  voidptype ; 
 int /*<<< orphan*/  wflag ; 
 scalar_t__ xref ; 

int main(int argc, char *argv[]) {
	int i, j;
	for (i = argc - 1; i > 0; i--)
		if (strncmp(argv[i], "-target=", 8) == 0)
			break;
	if (i > 0) {
		char *s = strchr(argv[i], '\\');
		if (s != NULL)
			*s = '/';
		for (j = 0; bindings[j].name && bindings[j].ir; j++)
			if (strcmp(&argv[i][8], bindings[j].name) == 0) {
				IR = bindings[j].ir;
				break;
			}
		if (s != NULL)
			*s = '\\';
	}
	if (!IR) {
		fprint(stderr, "%s: unknown target", argv[0]);
		if (i > 0)
			fprint(stderr, " `%s'", &argv[i][8]);
		fprint(stderr, "; must specify one of\n");
		for (i = 0; bindings[i].name; i++)
			fprint(stderr, "\t-target=%s\n", bindings[i].name);
		exit(EXIT_FAILURE);
	}
	init(argc, argv);
	t = gettok();
	(*IR->progbeg)(argc, argv);
	if (glevel && IR->stabinit)
		(*IR->stabinit)(firstfile, argc, argv);
	program();
	if (events.end)
		apply(events.end, NULL, NULL);
	memset(&events, 0, sizeof events);
	if (glevel || xref) {
		Symbol symroot = NULL;
		Coordinate src;
		foreach(types,       GLOBAL, typestab, &symroot);
		foreach(identifiers, GLOBAL, typestab, &symroot);
		src.file = firstfile;
		src.x = 0;
		src.y = lineno;
		if ((glevel > 2 || xref) && IR->stabend)
			(*IR->stabend)(&src, symroot,
				ltov(&loci,    PERM),
				ltov(&symbols, PERM), NULL);
		else if (IR->stabend)
			(*IR->stabend)(&src, NULL, NULL, NULL, NULL);
	}
	finalize();
	(*IR->progend)();
	deallocate(PERM);
	return errcnt > 0;
}

void main_init(int argc, char *argv[]) {
	char *infile = NULL, *outfile = NULL;
	int i;
	static int inited;

	if (inited)
		return;
	inited = 1;
	type_init(argc, argv);
	for (i = 1; i < argc; i++)
		if (strcmp(argv[i], "-g") == 0 || strcmp(argv[i], "-g2") == 0)
			glevel = 2;
		else if (strncmp(argv[i], "-g", 2) == 0) {	/* -gn[,x] */
			char *p = strchr(argv[i], ',');
			glevel = atoi(argv[i]+2);
			if (p) {
				comment = p + 1;
				if (glevel == 0)
					glevel = 1;
				if (stabIR.stabline == NULL) {
					stabIR.stabline = IR->stabline;
					stabIR.stabend = IR->stabend;
					IR->stabline = stabline;
					IR->stabend = stabend;
				}
			}	
		} else if (strcmp(argv[i], "-x") == 0)
			xref++;
		else if (strcmp(argv[i], "-A") == 0) {
			++Aflag;
		} else if (strcmp(argv[i], "-P") == 0)
			Pflag++;
		else if (strcmp(argv[i], "-w") == 0)
			wflag++;
		else if (strcmp(argv[i], "-n") == 0) {
			if (!YYnull) {
				YYnull = install(string("_YYnull"), &globals, GLOBAL, PERM);
				YYnull->type = func(voidptype, NULL, 1);
				YYnull->sclass = EXTERN;
				(*IR->defsymbol)(YYnull);
			}
		} else if (strncmp(argv[i], "-n", 2) == 0) {	/* -nvalid[,check] */
			char *p = strchr(argv[i], ',');
			if (p) {
				YYcheck = install(string(p+1), &globals, GLOBAL, PERM);
				YYcheck->type = func(voidptype, NULL, 1);
				YYcheck->sclass = EXTERN;
				(*IR->defsymbol)(YYcheck);
				p = stringn(argv[i]+2, p - (argv[i]+2));
			} else
				p = string(argv[i]+2);
			YYnull = install(p, &globals, GLOBAL, PERM);
			YYnull->type = func(voidptype, NULL, 1);
			YYnull->sclass = EXTERN;
			(*IR->defsymbol)(YYnull);
		} else if (strcmp(argv[i], "-v") == 0)
			fprint(stderr, "%s %s\n", argv[0], rcsid);
		else if (strncmp(argv[i], "-s", 2) == 0)
			density = strtod(&argv[i][2], NULL);
		else if (strncmp(argv[i], "-errout=", 8) == 0) {
			FILE *f = fopen(argv[i]+8, "w");
			if (f == NULL) {
				fprint(stderr, "%s: can't write errors to `%s'\n", argv[0], argv[i]+8);
				exit(EXIT_FAILURE);
			}
			fclose(f);
			f = freopen(argv[i]+8, "w", stderr);
			assert(f);
		} else if (strncmp(argv[i], "-e", 2) == 0) {
			int x;
			if ((x = strtol(&argv[i][2], NULL, 0)) > 0)
				errlimit = x;
		} else if (strncmp(argv[i], "-little_endian=", 15) == 0)
			IR->little_endian = argv[i][15] - '0';
		else if (strncmp(argv[i], "-mulops_calls=", 18) == 0)
			IR->mulops_calls = argv[i][18] - '0';
		else if (strncmp(argv[i], "-wants_callb=", 13) == 0)
			IR->wants_callb = argv[i][13] - '0';
		else if (strncmp(argv[i], "-wants_argb=", 12) == 0)
			IR->wants_argb = argv[i][12] - '0';
		else if (strncmp(argv[i], "-left_to_right=", 15) == 0)
			IR->left_to_right = argv[i][15] - '0';
		else if (strncmp(argv[i], "-wants_dag=", 11) == 0)
			IR->wants_dag = argv[i][11] - '0';
		else if (*argv[i] != '-' || strcmp(argv[i], "-") == 0) {
			if (infile == NULL)
				infile = argv[i];
			else if (outfile == NULL)
				outfile = argv[i];
		}

	if (infile != NULL && strcmp(infile, "-") != 0
	&& freopen(infile, "r", stdin) == NULL) {
		fprint(stderr, "%s: can't read `%s'\n", argv[0], infile);
		exit(EXIT_FAILURE);
	}
	if (outfile != NULL && strcmp(outfile, "-") != 0
	&& freopen(outfile, "w", stdout) == NULL) {
		fprint(stderr, "%s: can't write `%s'\n", argv[0], outfile);
		exit(EXIT_FAILURE);
	}
}

__attribute__((used)) static void typestab(Symbol p, void *cl) {
	if (*(Symbol *)cl == 0 && p->sclass && p->sclass != TYPEDEF)
		*(Symbol *)cl = p;
	if ((p->sclass == TYPEDEF || p->sclass == 0) && IR->stabtype)
		(*IR->stabtype)(p);
}

__attribute__((used)) static void stabline(Coordinate *cp) {
	if (cp->file && cp->file != currentfile) {
		if (srcfp)
			fclose(srcfp);
		currentfile = cp->file;
		srcfp = fopen(currentfile, "r");
		srcpos = 0;
		currentline = 0;
	}
	if (currentline != cp->y && srcfp) {
		char buf[512];
		if (srcpos > cp->y) {
			rewind(srcfp);
			srcpos = 0;
		}
		for ( ; srcpos < cp->y; srcpos++)
			if (fgets(buf, sizeof buf, srcfp) == NULL) {
				fclose(srcfp);
				srcfp = NULL;
				break;
			}
		if (srcfp && srcpos == cp->y)
			print("%s%s", comment, buf);
	}
	currentline = cp->y;
	if (stabIR.stabline)
		(*stabIR.stabline)(cp);
}

__attribute__((used)) static void stabend(Coordinate *cp, Symbol p, Coordinate **cpp, Symbol *sp, Symbol *stab) {
	if (stabIR.stabend)
		(*stabIR.stabend)(cp, p, cpp, sp, stab);
	if (srcfp)
		fclose(srcfp);
}

