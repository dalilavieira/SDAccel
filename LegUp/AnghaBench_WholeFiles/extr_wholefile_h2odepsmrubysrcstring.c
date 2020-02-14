#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_4__ ;
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {void* capa; } ;
struct TYPE_6__ {char* ptr; TYPE_1__ aux; void* len; } ;
struct TYPE_7__ {char* ary; TYPE_2__ heap; } ;
struct RString {int /*<<< orphan*/  c; TYPE_3__ as; int /*<<< orphan*/  flags; } ;
typedef  int /*<<< orphan*/  mrb_value ;
typedef  int /*<<< orphan*/  mrb_state ;
typedef  void* mrb_int ;
struct TYPE_8__ {int /*<<< orphan*/  c; } ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 size_t MRB_INT_MAX ; 
 int /*<<< orphan*/  MRB_STR_NOFREE ; 
 size_t RSTRING_EMBED_LEN_MAX ; 
 char* RSTR_PTR (struct RString*) ; 
 int /*<<< orphan*/  RSTR_SET_EMBED_FLAG (struct RString*) ; 
 int /*<<< orphan*/  RSTR_SET_EMBED_LEN (struct RString*,size_t) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 scalar_t__ mrb_malloc (int /*<<< orphan*/ *,size_t) ; 
 struct RString* mrb_obj_alloc_string (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_obj_value (struct RString*) ; 
 int /*<<< orphan*/  mrb_raise (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char*) ; 
 scalar_t__ mrb_ro_data_p (char const*) ; 
 TYPE_4__* mrb_str_ptr (int /*<<< orphan*/ ) ; 

__attribute__((used)) static struct RString*
str_new_static(mrb_state *mrb, const char *p, size_t len)
{
  struct RString *s;

  if (len >= MRB_INT_MAX) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "string size too big");
  }
  s = mrb_obj_alloc_string(mrb);
  s->as.heap.len = (mrb_int)len;
  s->as.heap.aux.capa = 0;             /* nofree */
  s->as.heap.ptr = (char *)p;
  s->flags = MRB_STR_NOFREE;

  return s;
}

__attribute__((used)) static struct RString*
str_new(mrb_state *mrb, const char *p, size_t len)
{
  struct RString *s;

  if (p && mrb_ro_data_p(p)) {
    return str_new_static(mrb, p, len);
  }
  s = mrb_obj_alloc_string(mrb);
  if (len <= RSTRING_EMBED_LEN_MAX) {
    RSTR_SET_EMBED_FLAG(s);
    RSTR_SET_EMBED_LEN(s, len);
    if (p) {
      memcpy(s->as.ary, p, len);
    }
  }
  else {
    if (len >= MRB_INT_MAX) {
      mrb_raise(mrb, E_ARGUMENT_ERROR, "string size too big");
    }
    s->as.heap.ptr = (char *)mrb_malloc(mrb, len+1);
    s->as.heap.len = (mrb_int)len;
    s->as.heap.aux.capa = (mrb_int)len;
    if (p) {
      memcpy(s->as.heap.ptr, p, len);
    }
  }
  RSTR_PTR(s)[len] = '\0';
  return s;
}

__attribute__((used)) static inline void
str_with_class(mrb_state *mrb, struct RString *s, mrb_value obj)
{
  s->c = mrb_str_ptr(obj)->c;
}

__attribute__((used)) static mrb_value
mrb_str_new_empty(mrb_state *mrb, mrb_value str)
{
  struct RString *s = str_new(mrb, 0, 0);

  str_with_class(mrb, s, str);
  return mrb_obj_value(s);
}

