#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  WORD ;
struct TYPE_10__ {int PointerToSymbolTable; int SizeOfOptionalHeader; unsigned int NumberOfSections; } ;
struct TYPE_9__ {int PointerToRawData; int PointerToRelocations; unsigned int NumberOfRelocations; unsigned int VirtualAddress; unsigned int SizeOfRawData; scalar_t__ Name; } ;
struct TYPE_8__ {unsigned int VirtualAddress; int Type; size_t SymbolTableIndex; } ;
struct TYPE_7__ {int /*<<< orphan*/  Value; } ;
typedef  TYPE_1__* PIMAGE_SYMBOL ;
typedef  TYPE_2__* PIMAGE_RELOCATION ;
typedef  TYPE_3__ IMAGE_SECTION_HEADER ;
typedef  TYPE_4__ IMAGE_FILE_HEADER ;
typedef  int /*<<< orphan*/  FILE ;
typedef  int /*<<< orphan*/  DWORD ;

/* Variables and functions */
#define  IMAGE_REL_I386_ABSOLUTE 129 
#define  IMAGE_REL_I386_DIR32 128 
 int /*<<< orphan*/  SEEK_END ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  fread (char*,unsigned long,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (char*) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 unsigned long ftell (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  fwrite (char*,scalar_t__,int,int /*<<< orphan*/ *) ; 
 char* malloc (unsigned long) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  rewind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char*,char*) ; 
 unsigned long strtol (char*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static
void
Usage(void)
{
    printf("Converts a coff object file into a raw binary file.\n"
           "Syntax: obj2bin <source file> <dest file> <base address>\n");
}

__attribute__((used)) static
void
RelocateSection(
    char *pData,
    IMAGE_SECTION_HEADER *pSectionHeader,
    PIMAGE_SYMBOL pSymbols,
    unsigned int iOffset)
{
    unsigned int i, nOffset;
    PIMAGE_RELOCATION pReloc;
    char *pSection;
    WORD *p16;
    DWORD *p32;

    pSection = pData + pSectionHeader->PointerToRawData;

    /* Calculate pointer to relocation table */
    pReloc = (PIMAGE_RELOCATION)(pData + pSectionHeader->PointerToRelocations);

    /* Loop all relocations */
    for (i = 0; i < pSectionHeader->NumberOfRelocations; i++)
    {
        nOffset = pReloc->VirtualAddress - pSectionHeader->VirtualAddress;

        if (nOffset > pSectionHeader->SizeOfRawData) continue;

        switch (pReloc->Type)
        {
            case IMAGE_REL_I386_ABSOLUTE:
            case 16:
                p16 = (void*)(pSection + nOffset);
                *p16 += (WORD)(pSymbols[pReloc->SymbolTableIndex].Value + iOffset);
                break;

            case IMAGE_REL_I386_DIR32:
                p32 = (void*)(pSection + nOffset);
                *p32 += (DWORD)(pSymbols[pReloc->SymbolTableIndex].Value + iOffset);
                break;

            default:
                printf("Unknown relocation type %u, address 0x%x\n",
                       pReloc->Type, (unsigned)pReloc->VirtualAddress);
        }

        pReloc++;
    }
}

int main(int argc, char *argv[])
{
    char *pszSourceFile;
    char *pszDestFile;
    unsigned long nFileSize, nBaseAddress;
    FILE *pSourceFile, *pDestFile;
    IMAGE_FILE_HEADER *pFileHeader;
    IMAGE_SECTION_HEADER *pSectionHeader;
    unsigned int i;
    char *pData;
    PIMAGE_SYMBOL pSymbols;

    if ((argc != 4) || (strcmp(argv[1], "--help") == 0))
    {
        Usage();
        return -1;
    }

    pszSourceFile = argv[1];
    pszDestFile = argv[2];
    nBaseAddress = strtol(argv[3], 0, 16);

    pSourceFile = fopen(pszSourceFile, "rb");
    if (!pSourceFile)
    {
        fprintf(stderr, "Couldn't open source file '%s'\n", pszSourceFile);
        return -2;
    }

    /* Get file size */
    fseek(pSourceFile, 0, SEEK_END);
    nFileSize = ftell(pSourceFile);
    rewind(pSourceFile);

    /* Allocate memory for the file */
    pData = malloc(nFileSize);
    if (!pData)
    {
        fclose(pSourceFile);
        fprintf(stderr, "Failed to allocate %lu bytes\n", nFileSize);
        return -3;
    }

    /* Read the whole source file */
    if (!fread(pData, nFileSize, 1, pSourceFile))
    {
        free(pData);
        fclose(pSourceFile);
        fprintf(stderr, "Failed to read %lu bytes from source file\n", nFileSize);
        return -4;
    }

    /* Close source file */
    fclose(pSourceFile);

    /* Open the destination file */
    pDestFile = fopen(pszDestFile, "wb");
    if (!pDestFile)
    {
        free(pData);
        fprintf(stderr, "Couldn't open destination file '%s'\n", pszDestFile);
        return -5;
    }

    /* Calculate table pointers */
    pFileHeader = (IMAGE_FILE_HEADER*)pData;
    pSymbols = (void*)(pData + pFileHeader->PointerToSymbolTable);
    pSectionHeader = (void*)(((char*)(pFileHeader + 1)) + pFileHeader->SizeOfOptionalHeader);

    /* Loop all sections */
    for (i = 0; i < pFileHeader->NumberOfSections; i++)
    {
        /* Check if this is '.text' section */
        if ((strcmp((char*)pSectionHeader->Name, ".text") == 0) &&
            (pSectionHeader->SizeOfRawData != 0))
        {
            RelocateSection(pData,
                            pSectionHeader,
                            pSymbols,
                            nBaseAddress);

            /* Write the section to the destination file */
            if (!fwrite(pData + pSectionHeader->PointerToRawData,
                        pSectionHeader->SizeOfRawData, 1, pDestFile))
            {
                free(pData);
                fclose(pDestFile);
                fprintf(stderr, "Failed to write %u bytes to destination file\n",
                        (unsigned int)pSectionHeader->SizeOfRawData);
                return -6;
            }

            nBaseAddress += pSectionHeader->SizeOfRawData;
        }

        pSectionHeader++;
    }

    free(pData);
    fclose(pDestFile);

    return 0;
}

