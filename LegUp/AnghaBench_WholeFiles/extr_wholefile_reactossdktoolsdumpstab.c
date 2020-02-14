#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_5__ ;
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  size_t ULONG_PTR ;
typedef  size_t ULONG ;
struct TYPE_14__ {scalar_t__ e_magic; long e_lfanew; } ;
struct TYPE_13__ {size_t NumberOfSections; int SizeOfOptionalHeader; } ;
struct TYPE_12__ {size_t ImageBase; } ;
struct TYPE_11__ {scalar_t__* Name; size_t SizeOfRawData; int PointerToRawData; } ;
struct TYPE_10__ {int n_type; int n_strx; int /*<<< orphan*/  n_value; int /*<<< orphan*/  n_desc; int /*<<< orphan*/  n_other; } ;
typedef  int /*<<< orphan*/  STAB_ENTRY ;
typedef  TYPE_1__* PSTAB_ENTRY ;
typedef  TYPE_2__* PIMAGE_SECTION_HEADER ;
typedef  TYPE_3__* PIMAGE_OPTIONAL_HEADER ;
typedef  TYPE_4__* PIMAGE_FILE_HEADER ;
typedef  TYPE_5__* PIMAGE_DOS_HEADER ;

/* Variables and functions */
 scalar_t__ IMAGE_DOS_MAGIC ; 
#define  N_BCOMM 160 
#define  N_BINCL 159 
#define  N_BSLINE 158 
#define  N_CATCH 157 
#define  N_DEFD 156 
#define  N_DSLINE 155 
#define  N_ECOML 154 
#define  N_ECOMM 153 
#define  N_EHDECL 152 
#define  N_EINCL 151 
#define  N_ENTRY 150 
#define  N_EXCL 149 
#define  N_FNAME 148 
#define  N_FUN 147 
#define  N_GYSM 146 
#define  N_LBRAC 145 
#define  N_LCSYM 144 
#define  N_LENG 143 
#define  N_LSYM 142 
#define  N_M2C 141 
#define  N_MAIN 140 
#define  N_NOMAP 139 
#define  N_NSYMS 138 
#define  N_PC 137 
#define  N_PSYM 136 
#define  N_RBRAC 135 
#define  N_RSYM 134 
#define  N_SCOPE 133 
#define  N_SLINE 132 
#define  N_SO 131 
#define  N_SOL 130 
#define  N_SSYM 129 
#define  N_STSYM 128 
 int /*<<< orphan*/  assert (int) ; 
 char* convert_path (char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  free (void*) ; 
 void* load_file (char*,size_t*) ; 
 int /*<<< orphan*/  perror (char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  sprintf (char*,char*,int) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strncmp (char*,char*,int) ; 

const char*
stab_type_name ( int stab_type )
{
	static char buf[32];
	switch ( stab_type )
	{
#define X(n) case n: return #n;
		X(N_GYSM)
		X(N_FNAME)
		X(N_FUN)
		X(N_STSYM)
		X(N_LCSYM)
		X(N_MAIN)
		X(N_PC)
		X(N_NSYMS)
		X(N_NOMAP)
		X(N_RSYM)
		X(N_M2C)
		X(N_SLINE)
		X(N_DSLINE)
		X(N_BSLINE)
		//X(N_BROWS)
		X(N_DEFD)
		X(N_EHDECL)
		//X(N_MOD2)
		X(N_CATCH)
		X(N_SSYM)
		X(N_SO)
		X(N_LSYM)
		X(N_BINCL)
		X(N_SOL)
		X(N_PSYM)
		X(N_EINCL)
		X(N_ENTRY)
		X(N_LBRAC)
		X(N_EXCL)
		X(N_SCOPE)
		X(N_RBRAC)
		X(N_BCOMM)
		X(N_ECOMM)
		X(N_ECOML)
		X(N_LENG)
	}
	sprintf ( buf, "%lu", stab_type );
	return buf;
}

__attribute__((used)) static int
GetStabInfo(void *FileData, PIMAGE_FILE_HEADER PEFileHeader,
            PIMAGE_SECTION_HEADER PESectionHeaders,
            ULONG *StabSymbolsLength, void **StabSymbolsBase,
            ULONG *StabStringsLength, void **StabStringsBase)
{
  ULONG Idx;

  /* Load .stab and .stabstr sections if available */
  *StabSymbolsBase = NULL;
  *StabSymbolsLength = 0;
  *StabStringsBase = NULL;
  *StabStringsLength = 0;

  for (Idx = 0; Idx < PEFileHeader->NumberOfSections; Idx++)
    {
      /* printf("section: '%.08s'\n", PESectionHeaders[Idx].Name); */
      if ((strncmp((char*)PESectionHeaders[Idx].Name, ".stab", 5) == 0)
        && (PESectionHeaders[Idx].Name[5] == 0))
        {
           /* printf(".stab section found. Size %d\n",
               PESectionHeaders[Idx].SizeOfRawData); */

           *StabSymbolsLength = PESectionHeaders[Idx].SizeOfRawData;
           *StabSymbolsBase = (void *)((char *) FileData + PESectionHeaders[Idx].PointerToRawData);
        }

      if (strncmp((char*)PESectionHeaders[Idx].Name, ".stabstr", 8) == 0)
        {
           /* printf(".stabstr section found. Size %d\n",
               PESectionHeaders[Idx].SizeOfRawData); */

           *StabStringsLength = PESectionHeaders[Idx].SizeOfRawData;
           *StabStringsBase = (void *)((char *) FileData + PESectionHeaders[Idx].PointerToRawData);
        }
    }

  return 0;
}

__attribute__((used)) static void
IterateStabs(ULONG StabSymbolsLength, void *StabSymbolsBase,
             ULONG StabStringsLength, void *StabStringsBase,
             ULONG_PTR ImageBase, PIMAGE_FILE_HEADER PEFileHeader,
             PIMAGE_SECTION_HEADER PESectionHeaders)
{
  PSTAB_ENTRY e;
  ULONG Count, i;

  e = StabSymbolsBase;
  Count = StabSymbolsLength / sizeof(STAB_ENTRY);
  if (Count == 0) /* No symbol info */
    return;

  printf ( "type,other,desc,value,str\n" );
  for (i = 0; i < Count; i++)
    {
	  printf ( "%s,%lu(0x%x),%lu(0x%x),%lu(0x%x),%s\n",
		  stab_type_name(e[i].n_type),
		  e[i].n_other,
		  e[i].n_other,
		  e[i].n_desc,
		  e[i].n_desc,
		  e[i].n_value,
		  e[i].n_value,
		  (char *) StabStringsBase + e[i].n_strx );
    }
}

int main(int argc, char* argv[])
{
  PIMAGE_DOS_HEADER PEDosHeader;
  PIMAGE_FILE_HEADER PEFileHeader;
  PIMAGE_OPTIONAL_HEADER PEOptHeader;
  PIMAGE_SECTION_HEADER PESectionHeaders;
  ULONG ImageBase;
  void *StabBase;
  ULONG StabsLength;
  void *StabStringBase;
  ULONG StabStringsLength;
  char* path1;
  size_t FileSize;
  void *FileData;

  if (2 != argc)
    {
      fprintf(stderr, "Usage: dumpstabs <exefile>\n");
      exit(1);
    }

  path1 = convert_path(argv[1]);

  FileData = load_file ( path1, &FileSize );
  if ( !FileData )
  {
    fprintf ( stderr, "An error occured loading '%s'\n", path1 );
    exit(1);
  }

  /* Check if MZ header exists  */
  PEDosHeader = (PIMAGE_DOS_HEADER) FileData;
  if (PEDosHeader->e_magic != IMAGE_DOS_MAGIC || PEDosHeader->e_lfanew == 0L)
    {
      perror("Input file is not a PE image.\n");
      free(FileData);
      exit(1);
    }

  /* Locate PE file header  */
  /* sizeof(ULONG) = sizeof(MAGIC) */
  PEFileHeader = (PIMAGE_FILE_HEADER)((char *) FileData + PEDosHeader->e_lfanew + sizeof(ULONG));

  /* Locate optional header */
  assert(sizeof(ULONG) == 4);
  PEOptHeader = (PIMAGE_OPTIONAL_HEADER)(PEFileHeader + 1);
  ImageBase = PEOptHeader->ImageBase;

  /* Locate PE section headers  */
  PESectionHeaders = (PIMAGE_SECTION_HEADER)((char *) PEOptHeader + PEFileHeader->SizeOfOptionalHeader);

  if (GetStabInfo(FileData, PEFileHeader, PESectionHeaders, &StabsLength, &StabBase,
                  &StabStringsLength, &StabStringBase))
    {
      free(FileData);
      exit(1);
    }

  IterateStabs( StabsLength, StabBase, StabStringsLength, StabStringBase,
                ImageBase, PEFileHeader, PESectionHeaders);

  free(FileData);

  return 0;
}

