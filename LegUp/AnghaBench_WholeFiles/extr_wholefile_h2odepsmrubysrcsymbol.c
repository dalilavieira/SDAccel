#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct TYPE_10__ {int prev; int len; char const* name; int /*<<< orphan*/  lit; } ;
typedef  TYPE_1__ symbol_name ;
typedef  int mrb_sym ;
struct TYPE_11__ {int* symhash; int symidx; int symcapa; TYPE_1__* symtbl; } ;
typedef  TYPE_2__ mrb_state ;
typedef  scalar_t__ mrb_bool ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int /*<<< orphan*/  FALSE ; 
 size_t RITE_LV_NULL_MARK ; 
 int /*<<< orphan*/  TRUE ; 
 scalar_t__ memcmp (char const*,char const*,int) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/  mrb_assert (int) ; 
 scalar_t__ mrb_malloc (TYPE_2__*,size_t) ; 
 int /*<<< orphan*/  mrb_raise (TYPE_2__*,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ mrb_realloc (TYPE_2__*,TYPE_1__*,int) ; 
 scalar_t__ mrb_ro_data_p (char const*) ; 
 char const* pack_table ; 
 char* strchr (char const*,int) ; 

__attribute__((used)) static void
sym_validate_len(mrb_state *mrb, size_t len)
{
  if (len >= RITE_LV_NULL_MARK) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "symbol length too long");
  }
}

__attribute__((used)) static mrb_sym
sym_inline_pack(const char *name, uint16_t len)
{
  char c;
  const char *p;
  int i;
  mrb_sym sym = 0;
  int lower = 1;

  if (len > 6) return 0;        /* too long */
  for (i=0; i<len; i++) {
    uint32_t bits;

    c = name[i];
    if (c == 0) return 0;       /* NUL in name */
    p = strchr(pack_table, (int)c);
    if (p == 0) return 0;       /* non alnum char */
    bits = (uint32_t)(p - pack_table)+1;
    if (bits > 27) lower = 0;
    sym |= bits<<(i*6+2);
  }
  if (lower) {
    sym = 0;
    for (i=0; i<len; i++) {
      uint32_t bits;

      c = name[i];
      p = strchr(pack_table, (int)c);
      bits = (uint32_t)(p - pack_table)+1;
      sym |= bits<<(i*5+2);
    }
    return sym | 3;
  }
  if (len == 6) return 0;
  return sym | 1;
}

__attribute__((used)) static const char*
sym_inline_unpack_with_bit(mrb_sym sym, char *buf, int bit_per_char)
{
  int i;

  for (i=0; i<30/bit_per_char; i++) {
    uint32_t bits;
    char c;

    bits = sym>>(i*bit_per_char+2) & (1<<bit_per_char)-1;
    if (bits == 0) break;
    c = pack_table[bits-1];
    buf[i] = c;
  }
  buf[i] = '\0';
  return buf;
}

__attribute__((used)) static const char*
sym_inline_unpack(mrb_sym sym, char *buf)
{
  mrb_assert(sym&1);

  if (sym&2) {                  /* all lower case (5bits/char) */
    return sym_inline_unpack_with_bit(sym, buf, 5);
  }
  return sym_inline_unpack_with_bit(sym, buf, 6);
}

uint8_t
symhash(const char *key, size_t len)
{
    uint32_t hash, i;

    for(hash = i = 0; i < len; ++i) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash & 0xff;
}

__attribute__((used)) static mrb_sym
find_symbol(mrb_state *mrb, const char *name, uint16_t len, uint8_t hash)
{
  mrb_sym i;
  symbol_name *sname;

#ifndef MRB_ENABLE_ALL_SYMBOLS
  /* inline symbol */
  i = sym_inline_pack(name, len);
  if (i > 0) return i;
#endif

  i = mrb->symhash[hash];
  if (i == 0) return 0;
  do {
    sname = &mrb->symtbl[i];
    if (sname->len == len && memcmp(sname->name, name, len) == 0) {
      return i<<1;
    }
    if (sname->prev == 0xff) {
      i -= 0xff;
      sname = &mrb->symtbl[i];
      while (mrb->symtbl < sname) {
        if (sname->len == len && memcmp(sname->name, name, len) == 0) {
          return (mrb_sym)(sname - mrb->symtbl)<<1;
        }
        sname--;
      }
      return 0;
    }
    i -= sname->prev;
  } while (sname->prev > 0);
  return 0;
}

__attribute__((used)) static mrb_sym
sym_intern(mrb_state *mrb, const char *name, size_t len, mrb_bool lit)
{
  mrb_sym sym;
  symbol_name *sname;
  uint8_t hash;

  sym_validate_len(mrb, len);
  hash = symhash(name, len);
  sym = find_symbol(mrb, name, len, hash);
  if (sym > 0) return sym;

  /* registering a new symbol */
  sym = ++mrb->symidx;
  if (mrb->symcapa < sym) {
    if (mrb->symcapa == 0) mrb->symcapa = 100;
    else mrb->symcapa = (size_t)(mrb->symcapa * 6 / 5);
    mrb->symtbl = (symbol_name*)mrb_realloc(mrb, mrb->symtbl, sizeof(symbol_name)*(mrb->symcapa+1));
  }
  sname = &mrb->symtbl[sym];
  sname->len = (uint16_t)len;
  if (lit || mrb_ro_data_p(name)) {
    sname->name = name;
    sname->lit = TRUE;
  }
  else {
    char *p = (char *)mrb_malloc(mrb, len+1);
    memcpy(p, name, len);
    p[len] = 0;
    sname->name = (const char*)p;
    sname->lit = FALSE;
  }
  if (mrb->symhash[hash]) {
    mrb_sym i = sym - mrb->symhash[hash];
    if (i > 0xff)
      sname->prev = 0xff;
    else
      sname->prev = i;
  }
  else {
    sname->prev = 0;
  }
  mrb->symhash[hash] = sym;

  return sym<<1;
}

