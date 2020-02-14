#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_55__   TYPE_2__ ;
typedef  struct TYPE_54__   TYPE_1__ ;

/* Type definitions */
struct csym_arg {scalar_t__ sym; struct RClass* c; } ;
struct RObject {int tt; TYPE_1__* iv; } ;
struct RClass {scalar_t__ tt; TYPE_1__* iv; } ;
struct RBasic {int dummy; } ;
struct TYPE_54__ {scalar_t__ size; size_t last_len; scalar_t__* key; void** val; struct TYPE_54__* next; struct TYPE_54__* rootseg; } ;
typedef  TYPE_1__ segment ;
typedef  void* mrb_value ;
typedef  scalar_t__ mrb_sym ;
struct TYPE_55__ {struct RClass* object_class; TYPE_1__* globals; } ;
typedef  TYPE_2__ mrb_state ;
typedef  scalar_t__ (* mrb_iv_foreach_func ) (TYPE_2__*,scalar_t__,void*,void*) ;
typedef  int /*<<< orphan*/  mrb_int ;
typedef  void* mrb_bool ;
typedef  TYPE_1__ iv_tbl ;
typedef  enum mrb_vtype { ____Placeholder_mrb_vtype } mrb_vtype ;

/* Variables and functions */
 void* FALSE ; 
 scalar_t__ ISUPPER (int /*<<< orphan*/ ) ; 
 size_t MRB_IV_SEGMENT_SIZE ; 
#define  MRB_TT_CLASS 134 
#define  MRB_TT_DATA 133 
#define  MRB_TT_EXCEPTION 132 
#define  MRB_TT_HASH 131 
#define  MRB_TT_MODULE 130 
#define  MRB_TT_OBJECT 129 
#define  MRB_TT_SCLASS 128 
 char* RSTRING_PTR (void*) ; 
 void* TRUE ; 
 char* mrb_class_name (TYPE_2__*,struct RClass*) ; 
 struct RClass* mrb_class_ptr (void*) ; 
 int /*<<< orphan*/  mrb_field_write_barrier_value (TYPE_2__*,struct RBasic*,void*) ; 
 void* mrb_fixnum_value (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_free (TYPE_2__*,TYPE_1__*) ; 
 int /*<<< orphan*/  mrb_gc_mark_value (TYPE_2__*,void*) ; 
 scalar_t__ mrb_intern_lit (TYPE_2__*,char*) ; 
 scalar_t__ mrb_malloc (TYPE_2__*,int) ; 
 scalar_t__ mrb_nil_p (void*) ; 
 void* mrb_nil_value () ; 
 void* mrb_obj_iv_get (TYPE_2__*,struct RObject*,scalar_t__) ; 
 int /*<<< orphan*/  mrb_obj_iv_set (TYPE_2__*,struct RObject*,scalar_t__,int /*<<< orphan*/ ) ; 
 struct RObject* mrb_obj_ptr (void*) ; 
 int /*<<< orphan*/  mrb_obj_value (struct RObject*) ; 
 int /*<<< orphan*/  mrb_str_cat (TYPE_2__*,void*,char const*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_str_cat_cstr (TYPE_2__*,void*,char const*) ; 
 void* mrb_str_new_capa (TYPE_2__*,int) ; 
 int /*<<< orphan*/ * mrb_sym2name (TYPE_2__*,scalar_t__) ; 
 char* mrb_sym2name_len (TYPE_2__*,scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_symbol_value (scalar_t__) ; 
 int mrb_type (void*) ; 
 scalar_t__ stub1 (TYPE_2__*,scalar_t__,void*,void*) ; 

__attribute__((used)) static iv_tbl*
iv_new(mrb_state *mrb)
{
  iv_tbl *t;

  t = (iv_tbl*)mrb_malloc(mrb, sizeof(iv_tbl));
  t->size = 0;
  t->rootseg =  NULL;
  t->last_len = 0;

  return t;
}

__attribute__((used)) static void
iv_put(mrb_state *mrb, iv_tbl *t, mrb_sym sym, mrb_value val)
{
  segment *seg;
  segment *prev = NULL;
  segment *matched_seg = NULL;
  size_t matched_idx = 0;
  size_t i;

  if (t == NULL) return;
  seg = t->rootseg;
  while (seg) {
    for (i=0; i<MRB_IV_SEGMENT_SIZE; i++) {
      mrb_sym key = seg->key[i];
      /* Found room in last segment after last_len */
      if (!seg->next && i >= t->last_len) {
        seg->key[i] = sym;
        seg->val[i] = val;
        t->last_len = i+1;
        t->size++;
        return;
      }
      if (!matched_seg && key == 0) {
        matched_seg = seg;
        matched_idx = i;
      }
      else if (key == sym) {
        seg->val[i] = val;
        return;
      }
    }
    prev = seg;
    seg = seg->next;
  }

  /* Not found */
  t->size++;
  if (matched_seg) {
    matched_seg->key[matched_idx] = sym;
    matched_seg->val[matched_idx] = val;
    return;
  }

  seg = (segment*)mrb_malloc(mrb, sizeof(segment));
  if (!seg) return;
  seg->next = NULL;
  seg->key[0] = sym;
  seg->val[0] = val;
  t->last_len = 1;
  if (prev) {
    prev->next = seg;
  }
  else {
    t->rootseg = seg;
  }
}

__attribute__((used)) static mrb_bool
iv_get(mrb_state *mrb, iv_tbl *t, mrb_sym sym, mrb_value *vp)
{
  segment *seg;
  size_t i;

  if (t == NULL) return FALSE;
  seg = t->rootseg;
  while (seg) {
    for (i=0; i<MRB_IV_SEGMENT_SIZE; i++) {
      mrb_sym key = seg->key[i];

      if (!seg->next && i >= t->last_len) {
        return FALSE;
      }
      if (key == sym) {
        if (vp) *vp = seg->val[i];
        return TRUE;
      }
    }
    seg = seg->next;
  }
  return FALSE;
}

__attribute__((used)) static mrb_bool
iv_del(mrb_state *mrb, iv_tbl *t, mrb_sym sym, mrb_value *vp)
{
  segment *seg;
  size_t i;

  if (t == NULL) return FALSE;
  seg = t->rootseg;
  while (seg) {
    for (i=0; i<MRB_IV_SEGMENT_SIZE; i++) {
      mrb_sym key = seg->key[i];

      if (!seg->next && i >= t->last_len) {
        return FALSE;
      }
      if (key == sym) {
        t->size--;
        seg->key[i] = 0;
        if (vp) *vp = seg->val[i];
        return TRUE;
      }
    }
    seg = seg->next;
  }
  return FALSE;
}

__attribute__((used)) static void
iv_foreach(mrb_state *mrb, iv_tbl *t, mrb_iv_foreach_func *func, void *p)
{
  segment *seg;
  size_t i;

  if (t == NULL) return;
  seg = t->rootseg;
  while (seg) {
    for (i=0; i<MRB_IV_SEGMENT_SIZE; i++) {
      mrb_sym key = seg->key[i];

      /* no value in last segment after last_len */
      if (!seg->next && i >= t->last_len) {
        return;
      }
      if (key != 0) {
        if ((*func)(mrb, key, seg->val[i], p) != 0) {
          return;
        }
      }
    }
    seg = seg->next;
  }
  return;
}

__attribute__((used)) static size_t
iv_size(mrb_state *mrb, iv_tbl *t)
{
  segment *seg;
  size_t size = 0;

  if (t == NULL) return 0;
  if (t->size > 0) return t->size;
  seg = t->rootseg;
  while (seg) {
    if (seg->next == NULL) {
      size += t->last_len;
      return size;
    }
    seg = seg->next;
    size += MRB_IV_SEGMENT_SIZE;
  }
  /* empty iv_tbl */
  return 0;
}

__attribute__((used)) static iv_tbl*
iv_copy(mrb_state *mrb, iv_tbl *t)
{
  segment *seg;
  iv_tbl *t2;

  size_t i;

  seg = t->rootseg;
  t2 = iv_new(mrb);

  while (seg != NULL) {
    for (i=0; i<MRB_IV_SEGMENT_SIZE; i++) {
      mrb_sym key = seg->key[i];
      mrb_value val = seg->val[i];

      if ((seg->next == NULL) && (i >= t->last_len)) {
        return t2;
      }
      iv_put(mrb, t2, key, val);
    }
    seg = seg->next;
  }
  return t2;
}

__attribute__((used)) static void
iv_free(mrb_state *mrb, iv_tbl *t)
{
  segment *seg;

  seg = t->rootseg;
  while (seg) {
    segment *p = seg;
    seg = seg->next;
    mrb_free(mrb, p);
  }
  mrb_free(mrb, t);
}

__attribute__((used)) static int
iv_mark_i(mrb_state *mrb, mrb_sym sym, mrb_value v, void *p)
{
  mrb_gc_mark_value(mrb, v);
  return 0;
}

__attribute__((used)) static void
mark_tbl(mrb_state *mrb, iv_tbl *t)
{
  iv_foreach(mrb, t, iv_mark_i, 0);
}

void
mrb_gc_mark_gv(mrb_state *mrb)
{
  mark_tbl(mrb, mrb->globals);
}

void
mrb_gc_free_gv(mrb_state *mrb)
{
  if (mrb->globals)
    iv_free(mrb, mrb->globals);
}

void
mrb_gc_mark_iv(mrb_state *mrb, struct RObject *obj)
{
  mark_tbl(mrb, obj->iv);
}

size_t
mrb_gc_mark_iv_size(mrb_state *mrb, struct RObject *obj)
{
  return iv_size(mrb, obj->iv);
}

void
mrb_gc_free_iv(mrb_state *mrb, struct RObject *obj)
{
  if (obj->iv) {
    iv_free(mrb, obj->iv);
  }
}

mrb_value
mrb_vm_special_get(mrb_state *mrb, mrb_sym i)
{
  return mrb_fixnum_value(0);
}

void
mrb_vm_special_set(mrb_state *mrb, mrb_sym i, mrb_value v)
{
}

__attribute__((used)) static mrb_bool
obj_iv_p(mrb_value obj)
{
  switch (mrb_type(obj)) {
    case MRB_TT_OBJECT:
    case MRB_TT_CLASS:
    case MRB_TT_MODULE:
    case MRB_TT_SCLASS:
    case MRB_TT_HASH:
    case MRB_TT_DATA:
    case MRB_TT_EXCEPTION:
      return TRUE;
    default:
      return FALSE;
  }
}

__attribute__((used)) static inline mrb_bool
namespace_p(enum mrb_vtype tt)
{
  return tt == MRB_TT_CLASS || tt == MRB_TT_MODULE ? TRUE : FALSE;
}

__attribute__((used)) static inline void
assign_class_name(mrb_state *mrb, struct RObject *obj, mrb_sym sym, mrb_value v)
{
  if (namespace_p(obj->tt) && namespace_p(mrb_type(v))) {
    struct RObject *c = mrb_obj_ptr(v);
    if (obj != c && ISUPPER(mrb_sym2name(mrb, sym)[0])) {
      mrb_sym id_classname = mrb_intern_lit(mrb, "__classname__");
      mrb_value o = mrb_obj_iv_get(mrb, c, id_classname);

      if (mrb_nil_p(o)) {
        mrb_sym id_outer = mrb_intern_lit(mrb, "__outer__");
        o = mrb_obj_iv_get(mrb, c, id_outer);

        if (mrb_nil_p(o)) {
          if ((struct RClass *)obj == mrb->object_class) {
            mrb_obj_iv_set(mrb, c, id_classname, mrb_symbol_value(sym));
          }
          else {
            mrb_obj_iv_set(mrb, c, id_outer, mrb_obj_value(obj));
          }
        }
      }
    }
  }
}

__attribute__((used)) static int
csym_i(mrb_state *mrb, mrb_sym sym, mrb_value v, void *p)
{
  struct csym_arg *a = (struct csym_arg*)p;
  struct RClass *c = a->c;

  if (mrb_type(v) == c->tt && mrb_class_ptr(v) == c) {
    a->sym = sym;
    return 1;     /* stop iteration */
  }
  return 0;
}

__attribute__((used)) static mrb_sym
find_class_sym(mrb_state *mrb, struct RClass *outer, struct RClass *c)
{
  struct csym_arg arg;

  if (!outer) return 0;
  if (outer == c) return 0;
  arg.c = c;
  arg.sym = 0;
  iv_foreach(mrb, outer->iv, csym_i, &arg);
  return arg.sym;
}

__attribute__((used)) static struct RClass*
outer_class(mrb_state *mrb, struct RClass *c)
{
  mrb_value ov;

  ov = mrb_obj_iv_get(mrb, (struct RObject*)c, mrb_intern_lit(mrb, "__outer__"));
  if (mrb_nil_p(ov)) return NULL;
  switch (mrb_type(ov)) {
  case MRB_TT_CLASS:
  case MRB_TT_MODULE:
    return mrb_class_ptr(ov);
  default:
    break;
  }
  return NULL;
}

__attribute__((used)) static mrb_bool
detect_outer_loop(mrb_state *mrb, struct RClass *c)
{
  struct RClass *t = c;         /* tortoise */
  struct RClass *h = c;         /* hare */

  for (;;) {
    if (h == NULL) return FALSE;
    h = outer_class(mrb, h);
    if (h == NULL) return FALSE;
    h = outer_class(mrb, h);
    t = outer_class(mrb, t);
    if (t == h) return TRUE;
  }
}

mrb_value
mrb_class_find_path(mrb_state *mrb, struct RClass *c)
{
  struct RClass *outer;
  mrb_value path;
  mrb_sym name;
  const char *str;
  mrb_int len;

  if (detect_outer_loop(mrb, c)) return mrb_nil_value();
  outer = outer_class(mrb, c);
  if (outer == NULL) return mrb_nil_value();
  name = find_class_sym(mrb, outer, c);
  if (name == 0) return mrb_nil_value();
  str = mrb_class_name(mrb, outer);
  path = mrb_str_new_capa(mrb, 40);
  mrb_str_cat_cstr(mrb, path, str);
  mrb_str_cat_cstr(mrb, path, "::");

  str = mrb_sym2name_len(mrb, name, &len);
  mrb_str_cat(mrb, path, str, len);
  if (RSTRING_PTR(path)[0] != '#') {
    iv_del(mrb, c->iv, mrb_intern_lit(mrb, "__outer__"), NULL);
    iv_put(mrb, c->iv, mrb_intern_lit(mrb, "__classname__"), path);
    mrb_field_write_barrier_value(mrb, (struct RBasic*)c, path);
  }
  return path;
}

