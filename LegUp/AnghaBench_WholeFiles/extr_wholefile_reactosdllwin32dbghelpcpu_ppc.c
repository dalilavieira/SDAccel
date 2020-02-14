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
struct dump_context {int dummy; } ;
struct cpu_stack_walk {int dummy; } ;
typedef  enum cpu_addr { ____Placeholder_cpu_addr } cpu_addr ;
typedef  int /*<<< orphan*/  LPSTACKFRAME64 ;
typedef  int /*<<< orphan*/  HANDLE ;
typedef  int /*<<< orphan*/  CONTEXT ;
typedef  int /*<<< orphan*/  BOOL ;
typedef  int /*<<< orphan*/  ADDRESS64 ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  FIXME (char*,...) ; 
#define  cpu_addr_frame 129 
#define  cpu_addr_stack 128 

__attribute__((used)) static BOOL ppc_get_addr(HANDLE hThread, const CONTEXT* ctx,
                         enum cpu_addr ca, ADDRESS64* addr)
{
   switch (ca)
    {
#if defined(__powerpc__)
    case cpu_addr_pc:
        addr->Mode    = AddrModeFlat;
        addr->Segment = 0; /* don't need segment */
        addr->Offset  = ctx->Iar;
        return TRUE;
#endif
    default:
    case cpu_addr_stack:
    case cpu_addr_frame:
        FIXME("not done\n");
    }
    return FALSE;
}

__attribute__((used)) static BOOL ppc_stack_walk(struct cpu_stack_walk* csw, LPSTACKFRAME64 frame, CONTEXT* context)
{
    FIXME("not done\n");
    return FALSE;
}

__attribute__((used)) static unsigned ppc_map_dwarf_register(unsigned regno, BOOL eh_frame)
{
    FIXME("not done\n");
    return 0;
}

__attribute__((used)) static void* ppc_fetch_context_reg(CONTEXT* ctx, unsigned regno, unsigned* size)
{
    FIXME("NIY\n");
    return NULL;
}

__attribute__((used)) static const char* ppc_fetch_regname(unsigned regno)
{
    FIXME("Unknown register %x\n", regno);
    return NULL;
}

__attribute__((used)) static BOOL ppc_fetch_minidump_thread(struct dump_context* dc, unsigned index, unsigned flags, const CONTEXT* ctx)
{
    FIXME("NIY\n");
    return FALSE;
}

__attribute__((used)) static BOOL ppc_fetch_minidump_module(struct dump_context* dc, unsigned index, unsigned flags)
{
    FIXME("NIY\n");
    return FALSE;
}

