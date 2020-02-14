#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct image_section_map {TYPE_1__* fmap; } ;
struct image_file_map {int modtype; } ;
struct TYPE_2__ {int modtype; } ;
typedef  int /*<<< orphan*/  DWORD_PTR ;
typedef  int /*<<< orphan*/  BOOL ;

/* Variables and functions */
#define  DMT_ELF 130 
#define  DMT_MACHO 129 
#define  DMT_PE 128 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  SHT_NULL ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  elf_find_section (struct image_file_map*,char const*,int /*<<< orphan*/ ,struct image_section_map*) ; 
 int /*<<< orphan*/  elf_get_map_rva (struct image_section_map const*) ; 
 int elf_get_map_size (struct image_section_map const*) ; 
 char const* elf_map_section (struct image_section_map*) ; 
 int /*<<< orphan*/  elf_unmap_section (struct image_section_map*) ; 
 int /*<<< orphan*/  macho_find_section (struct image_file_map*,int /*<<< orphan*/ *,char const*,struct image_section_map*) ; 
 int /*<<< orphan*/  macho_get_map_rva (struct image_section_map const*) ; 
 int macho_get_map_size (struct image_section_map const*) ; 
 char const* macho_map_section (struct image_section_map*) ; 
 int /*<<< orphan*/  macho_unmap_section (struct image_section_map*) ; 
 int /*<<< orphan*/  pe_find_section (struct image_file_map*,char const*,struct image_section_map*) ; 
 int /*<<< orphan*/  pe_get_map_rva (struct image_section_map const*) ; 
 int pe_get_map_size (struct image_section_map const*) ; 
 char const* pe_map_section (struct image_section_map*) ; 
 int /*<<< orphan*/  pe_unmap_section (struct image_section_map*) ; 

__attribute__((used)) static inline BOOL image_find_section(struct image_file_map* fmap, const char* name,
                                      struct image_section_map* ism)
{
    switch (fmap->modtype)
    {
#ifndef DBGHELP_STATIC_LIB
    case DMT_ELF:   return elf_find_section(fmap, name, SHT_NULL, ism);
    case DMT_MACHO: return macho_find_section(fmap, NULL, name, ism);
#endif
    case DMT_PE:    return pe_find_section(fmap, name, ism);
    default: assert(0); return FALSE;
    }
}

__attribute__((used)) static inline const char* image_map_section(struct image_section_map* ism)
{
    if (!ism->fmap) return NULL;
    switch (ism->fmap->modtype)
    {
#ifndef DBGHELP_STATIC_LIB
    case DMT_ELF:   return elf_map_section(ism);
    case DMT_MACHO: return macho_map_section(ism);
#endif
    case DMT_PE:    return pe_map_section(ism);
    default: assert(0); return NULL;
    }
}

__attribute__((used)) static inline void image_unmap_section(struct image_section_map* ism)
{
    if (!ism->fmap) return;
    switch (ism->fmap->modtype)
    {
#ifndef DBGHELP_STATIC_LIB
    case DMT_ELF:   elf_unmap_section(ism); break;
    case DMT_MACHO: macho_unmap_section(ism); break;
#endif
    case DMT_PE:    pe_unmap_section(ism);   break;
    default: assert(0); return;
    }
}

__attribute__((used)) static inline DWORD_PTR image_get_map_rva(const struct image_section_map* ism)
{
    if (!ism->fmap) return 0;
    switch (ism->fmap->modtype)
    {
#ifndef DBGHELP_STATIC_LIB
    case DMT_ELF:   return elf_get_map_rva(ism);
    case DMT_MACHO: return macho_get_map_rva(ism);
#endif
    case DMT_PE:    return pe_get_map_rva(ism);
    default: assert(0); return 0;
    }
}

__attribute__((used)) static inline unsigned image_get_map_size(const struct image_section_map* ism)
{
    if (!ism->fmap) return 0;
    switch (ism->fmap->modtype)
    {
#ifndef DBGHELP_STATIC_LIB
    case DMT_ELF:   return elf_get_map_size(ism);
    case DMT_MACHO: return macho_get_map_size(ism);
#endif
    case DMT_PE:    return pe_get_map_size(ism);
    default: assert(0); return 0;
    }
}

