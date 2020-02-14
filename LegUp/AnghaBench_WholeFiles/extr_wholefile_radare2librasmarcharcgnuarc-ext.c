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
struct ExtInstruction {int major; unsigned char minor; int flags; char const* name; struct ExtInstruction* next; } ;
struct ExtCoreRegister {char const* name; int rw; int number; } ;
struct ExtAuxRegister {long address; char* name; struct ExtAuxRegister* next; } ;
typedef  enum ExtReadWrite { ____Placeholder_ExtReadWrite } ExtReadWrite ;
struct TYPE_2__ {char const** condCodes; struct ExtCoreRegister* coreRegisters; struct ExtInstruction** instructions; struct ExtAuxRegister* auxRegisters; } ;

/* Variables and functions */
 int E_ARC_MACH_A4 ; 
 int FIRST_EXTENSION_CONDITION_CODE ; 
 int FIRST_EXTENSION_CORE_REGISTER ; 
 size_t INST_HASH (int,unsigned char) ; 
 int INST_HASH_SIZE ; 
 int LAST_EXTENSION_CONDITION_CODE ; 
 int LAST_EXTENSION_CORE_REGISTER ; 
 int /*<<< orphan*/  M ; 
 int NUM_EXT_COND ; 
 int NUM_EXT_CORE ; 
 int P ; 
#define  REG_INVALID 131 
#define  REG_READ 130 
#define  REG_READWRITE 129 
#define  REG_WRITE 128 
 TYPE_1__ arc_extension_map ; 
 int /*<<< orphan*/  printf (char*,...) ; 

__attribute__((used)) static const char* ExtReadWrite_image(enum ExtReadWrite val)
{
    switch (val)
    {
        case REG_INVALID  : return "INVALID";
        case REG_READ     : return "RO";
        case REG_WRITE    : return "WO";
        case REG_READWRITE: return "R/W";
        default           : return "???";
    }
}

const char *
arcExtMap_instName (int opcode, int insn, int *flags)
{
  /* Here the following tasks need to be done.  First of all, the opcode
     stored in the Extension Map is the real opcode.  However, the subopcode
     stored in the instruction to be disassembled is mangled.  We pass (in
     minor opcode), the instruction word.  Here we will un-mangle it and get
     the real subopcode which we can look for in the Extension Map.  This
     function is used both for the ARCTangent and the ARCompact, so we would
     also need some sort of a way to distinguish between the two
     architectures.  This is because the ARCTangent does not do any of this
     mangling so we have no issues there.  */

  /* If P[22:23] is 0 or 2 then un-mangle using iiiiiI.  If it is 1 then use
     iiiiIi.  Now, if P is 3 then check M[5:5] and if it is 0 then un-mangle
     using iiiiiI else iiiiii.  */

  unsigned char minor;
  struct ExtInstruction *temp;

  if (*flags != E_ARC_MACH_A4) /* ARCompact extension instructions.  */
    {
      /* 16-bit instructions.  */
      if (0x08 <= opcode && opcode <= 0x0b)
	{
	  /* I - set but not used */
	  unsigned char /* I, */ b, c, i;

	  /* I = (insn & 0xf800) >> 11; */
	  b = (insn & 0x0700) >> 8;
	  c = (insn & 0x00e0) >> 5;
	  i = (insn & 0x001f);

	  if (i) {
		  minor = i;
	  } else {
		  minor = (c == 0x07) ? b : c;
	  }
	}
      /* 32-bit instructions.  */
      else
	{
	  /* P, M - set but not used */
	  unsigned char /* P, M, */ I, A, B;

	  /* P = (insn & 0x00c00000) >> 22; */
	  /* M = (insn & 0x00000020); */
	  I = (insn & 0x003f0000) >> 16;
	  A = (insn & 0x0000003f);
	  B = ((insn & 0x07000000) >> 24) | ((insn & 0x00007000) >> 9);

	  if (I != 0x2f)
	    {
#ifndef UNMANGLED
	      switch (P)
		{
		case 3:
		  if (M)
		    {
		      minor = I;
		      break;
		    }
		case 0:
		case 2:
		  minor = (I >> 1) | ((I & 0x1) << 5);
		  break;
		case 1:
		  minor = (I >> 1) | (I & 0x1) | ((I & 0x2) << 4);
		}
#else
	      minor = I;
#endif
	    }
	  else
	    {
		    if (A != 0x3f) {
			    minor = A;
		    } else {
			    minor = B;
		    }
	    }
	}
  } else { /* ARCTangent extension instructions.  */
	  minor = insn;
  }

  temp = arc_extension_map.instructions[INST_HASH (opcode, minor)];
  while (temp)
    {
      if ((temp->major == opcode) && (temp->minor == minor))
	{
	  *flags = temp->flags;
	  return temp->name;
	}
      temp = temp->next;
    }

  return NULL;
}

const char *
arcExtMap_coreRegName (int regnum)
{
	if (regnum < FIRST_EXTENSION_CORE_REGISTER || regnum > LAST_EXTENSION_CORE_REGISTER) {
		return NULL;
	}
	return arc_extension_map.coreRegisters[regnum - FIRST_EXTENSION_CORE_REGISTER].name;
}

enum ExtReadWrite
arcExtMap_coreReadWrite (int regnum)
{
	if (regnum < FIRST_EXTENSION_CORE_REGISTER || regnum > LAST_EXTENSION_CORE_REGISTER) {
		return REG_INVALID;
	}
	return arc_extension_map.coreRegisters[regnum - FIRST_EXTENSION_CORE_REGISTER].rw;
}

const char *
arcExtMap_condCodeName (int code)
{
	if (code < FIRST_EXTENSION_CONDITION_CODE || code > LAST_EXTENSION_CONDITION_CODE) {
		return NULL;
	}
	return arc_extension_map.condCodes[code - FIRST_EXTENSION_CONDITION_CODE];
}

const char *
arcExtMap_auxRegName (long address)
{
  /* Walk the list of auxiliary register names and find the name.  */
  struct ExtAuxRegister *r;

  for (r = arc_extension_map.auxRegisters; r; r = r->next)
    {
	  if (r->address == address) {
		  return (const char *)r->name;
	  }
    }
  return NULL;
}

void
build_ARC_extmap (void *text_bfd)
{
#if 0
  asection *sect;

  /* the map is built each time gdb loads an executable file - so free any
   * existing map, as the map defined by the new file may differ from the old
   */
  destroy_map();

  for (sect = text_bfd->sections; sect != NULL; sect = sect->next)
    if (!strncmp (sect->name,
                  ".gnu.linkonce.arcextmap.",
          sizeof (".gnu.linkonce.arcextmap.") - 1)
        || !strcmp (sect->name,".arcextmap"))
      {
        bfd_size_type  count  = bfd_get_section_size (sect);
        unsigned char* buffer = xmalloc (count);

        if (buffer)
          {
            if (bfd_get_section_contents (text_bfd, sect, buffer, 0, count))
              create_map(buffer, count);
            free (buffer);
          }
      }
#endif
}

void dump_ARC_extmap (void)
{
    struct ExtAuxRegister* r;
    int                    i;

    r = arc_extension_map.auxRegisters;

    while (r)
    {
        printf("AUX : %s %ld\n", r->name, r->address);
        r = r->next;
    }

    for (i = 0; i < INST_HASH_SIZE; i++)
    {
        struct ExtInstruction *insn;

	for (insn = arc_extension_map.instructions[i]; insn != NULL; insn = insn->next) {
		printf ("INST: %d %d %x %s\n", insn->major, insn->minor, insn->flags, insn->name);
	}
    }

    for (i = 0; i < NUM_EXT_CORE; i++)
    {
        struct ExtCoreRegister reg = arc_extension_map.coreRegisters[i];

	if (reg.name) {
		printf ("CORE: %s %d %s\n", reg.name, reg.number, ExtReadWrite_image (reg.rw));
	}
    }

    for (i = 0; i < NUM_EXT_COND; i++) {
	    if (arc_extension_map.condCodes[i]) {
		    printf ("COND: %s\n", arc_extension_map.condCodes[i]);
	    }
    }
}

