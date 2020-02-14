#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_18__   TYPE_6__ ;
typedef  struct TYPE_17__   TYPE_5__ ;
typedef  struct TYPE_16__   TYPE_4__ ;
typedef  struct TYPE_15__   TYPE_3__ ;
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  int ulong ;
struct TYPE_18__ {scalar_t__ type; } ;
struct TYPE_15__ {int /*<<< orphan*/  lowpc; int /*<<< orphan*/  ranges; int /*<<< orphan*/  location; } ;
struct TYPE_13__ {int /*<<< orphan*/  data; int /*<<< orphan*/  len; } ;
struct TYPE_14__ {int /*<<< orphan*/  c; TYPE_1__ b; } ;
struct TYPE_16__ {int tag; int lowpc; int highpc; TYPE_3__ have; int /*<<< orphan*/  ranges; TYPE_2__ location; int /*<<< orphan*/  name; int /*<<< orphan*/  isexternal; } ;
struct TYPE_17__ {TYPE_4__ attrs; } ;
typedef  char Pe ;
typedef  TYPE_5__ DwarfSym ;
typedef  TYPE_6__ DwarfExpr ;
typedef  char Dwarf ;

/* Variables and functions */
 scalar_t__ RuleSame ; 
#define  TBlock 134 
#define  TConstant 133 
#define  TagCompileUnit 132 
#define  TagConstant 131 
#define  TagFormalParameter 130 
#define  TagSubprogram 129 
#define  TagVariable 128 
 scalar_t__ dwarfenum (char*,TYPE_5__*) ; 
 int dwarfnextsym (char*,TYPE_5__*) ; 
 char* dwarfopen (char*) ; 
 int /*<<< orphan*/  dwarfpctoline (char*,int,char**,char**,char**,int*,int*,int*) ; 
 scalar_t__ dwarfunwind (char*,int,TYPE_6__*,TYPE_6__*,TYPE_6__*,int) ; 
 int /*<<< orphan*/  exits (char*) ; 
 int /*<<< orphan*/  fprint (int,char*) ; 
 int nelem (TYPE_6__*) ; 
 char* nil ; 
 char* peopen (char*) ; 
 int /*<<< orphan*/  print (char*,...) ; 
 void printrules (char*,int) ; 
 int /*<<< orphan*/  sysfatal (char*,...) ; 

void
usage(void)
{
	fprint(2, "usage: dwarfdump file\n");
	exits("usage");
}

void
main(int argc, char **argv)
{
	int c;
	Pe *pe;
	Dwarf *d;
	DwarfSym s;
	char *cdir, *dir, *file;
	ulong line, mtime, length;

	if(argc != 2)
		usage();

#if 0
	fmtinstall('R', exprfmt);
	fmtinstall('H', encodefmt);
#endif

	if((pe = peopen(argv[1])) == nil)
		sysfatal("elfopen %s: %r", argv[1]);
	if((d=dwarfopen(pe)) == nil)
		sysfatal("dwarfopen: %r");

	if(dwarfenum(d, &s) < 0)
		sysfatal("dwarfenumall: %r");

	while(dwarfnextsym(d, &s) == 1){
		switch(s.attrs.tag){
		case TagCompileUnit:
			print("compileunit %s\n", s.attrs.name);
			break;
		case TagSubprogram:
			c = 't';
			goto sym;
		case TagVariable:
			c = 'd';
			goto sym;
		case TagConstant:
			c = 'c';
			goto sym;
		case TagFormalParameter:
			if(!s.attrs.name)
				break;
			c = 'p';
		sym:
			if(s.attrs.isexternal)
				c += 'A' - 'a';
			print("%c %s", c, s.attrs.name);
			if(s.attrs.have.lowpc)
				print(" 0x%lux-0x%lux", s.attrs.lowpc, s.attrs.highpc);
			switch(s.attrs.have.location){
			case TBlock:
				print(" @ %.*H", s.attrs.location.b.len, s.attrs.location.b.data);
				break;
			case TConstant:
				print(" @ 0x%lux", s.attrs.location.c);
				break;
			}
			if(s.attrs.have.ranges)
				print(" ranges@0x%lux", s.attrs.ranges);
			print("\n");
			if(s.attrs.have.lowpc){
				if(dwarfpctoline(d, s.attrs.lowpc, &cdir, &dir, &file, &line, &mtime, &length) < 0)
					print("\tcould not find source: %r\n");
				else if(dir == nil)
					print("\t%s/%s:%lud mtime=%lud length=%lud\n",
						cdir, file, line, mtime, length);
				else
					print("\t%s/%s/%s:%lud mtime=%lud length=%lud\n",
						cdir, dir, file, line, mtime, length);

				if(0) printrules(d, s.attrs.lowpc);
				if(0) printrules(d, (s.attrs.lowpc+s.attrs.highpc)/2);
			}
			break;
		}
	}
	exits(0);
}

void
printrules(Dwarf *d, ulong pc)
{
	int i;
	DwarfExpr r[10];
	DwarfExpr cfa, ra;

	if(dwarfunwind(d, pc, &cfa, &ra, r, nelem(r)) < 0)
		print("\tcannot unwind from pc 0x%lux: %r\n", pc);

	print("\tpc=0x%lux cfa=%R ra=%R", pc, &cfa, &ra);
	for(i=0; i<nelem(r); i++)
		if(r[i].type != RuleSame)
			print(" r%d=%R", i, &r[i]);
	print("\n");
}

