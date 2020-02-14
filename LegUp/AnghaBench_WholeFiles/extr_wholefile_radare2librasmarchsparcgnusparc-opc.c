#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct sparc_opcode_arch {char const* name; } ;
typedef  enum sparc_opcode_arch_val { ____Placeholder_sparc_opcode_arch_val } sparc_opcode_arch_val ;
struct TYPE_8__ {char const* name; int value; } ;
typedef  TYPE_1__ arg ;

/* Variables and functions */
 int SPARC_OPCODE_ARCH_BAD ; 
 TYPE_1__* asi_table ; 
 TYPE_1__* membar_table ; 
 TYPE_1__* prefetch_table ; 
 struct sparc_opcode_arch const* sparc_opcode_archs ; 
 TYPE_1__* sparclet_cpreg_table ; 
 scalar_t__ strcmp (char const*,char const*) ; 

enum sparc_opcode_arch_val
sparc_opcode_lookup_arch (const char *name)
{
  const struct sparc_opcode_arch *p;

  for (p = &sparc_opcode_archs[0]; p->name; ++p) {
	  if (strcmp (name, p->name) == 0) {
		  return (enum sparc_opcode_arch_val) (p - &sparc_opcode_archs[0]);
	  }
  }

  return SPARC_OPCODE_ARCH_BAD;
}

__attribute__((used)) static int
lookup_name (const arg *table, const char *name)
{
  const arg *p;

  for (p = table; p->name; ++p) {
	  if (strcmp (name, p->name) == 0) {
		  return p->value;
	  }
  }

  return -1;
}

__attribute__((used)) static const char *
lookup_value (const arg *table, int value)
{
  const arg *p;

  for (p = table; p->name; ++p) {
	  if (value == p->value) {
		  return p->name;
	  }
  }

  return NULL;
}

int
sparc_encode_asi (const char *name)
{
  return lookup_name (asi_table, name);
}

const char *
sparc_decode_asi (int value)
{
  return lookup_value (asi_table, value);
}

int
sparc_encode_membar (const char *name)
{
  return lookup_name (membar_table, name);
}

const char *
sparc_decode_membar (int value)
{
  return lookup_value (membar_table, value);
}

int
sparc_encode_prefetch (const char *name)
{
  return lookup_name (prefetch_table, name);
}

const char *
sparc_decode_prefetch (int value)
{
  return lookup_value (prefetch_table, value);
}

int
sparc_encode_sparclet_cpreg (const char *name)
{
  return lookup_name (sparclet_cpreg_table, name);
}

const char *
sparc_decode_sparclet_cpreg (int value)
{
  return lookup_value (sparclet_cpreg_table, value);
}

