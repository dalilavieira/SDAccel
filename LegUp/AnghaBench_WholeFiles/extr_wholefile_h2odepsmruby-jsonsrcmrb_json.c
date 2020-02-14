#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_1__ ;

/* Type definitions */
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/ * mrb_value ;
typedef  scalar_t__ mrb_sym ;
struct TYPE_36__ {struct RClass* object_class; } ;
typedef  TYPE_1__ mrb_state ;
typedef  size_t mrb_int ;
typedef  int /*<<< orphan*/  mrb_bool ;
typedef  int /*<<< orphan*/  JSON_Value ;
typedef  int /*<<< orphan*/  JSON_Object ;
typedef  int /*<<< orphan*/  JSON_Array ;

/* Variables and functions */
 int /*<<< orphan*/  E_ARGUMENT_ERROR ; 
 int /*<<< orphan*/  E_PARSER_ERROR ; 
 int /*<<< orphan*/  FALSE ; 
#define  JSONArray 143 
#define  JSONBoolean 142 
#define  JSONError 141 
#define  JSONNull 140 
#define  JSONNumber 139 
#define  JSONObject 138 
#define  JSONString 137 
 int MRB_ARGS_NONE () ; 
 int MRB_ARGS_OPT (int) ; 
 int MRB_ARGS_REQ (int) ; 
#define  MRB_TT_ARRAY 136 
#define  MRB_TT_FALSE 135 
#define  MRB_TT_FIXNUM 134 
#define  MRB_TT_FLOAT 133 
#define  MRB_TT_HASH 132 
#define  MRB_TT_STRING 131 
#define  MRB_TT_SYMBOL 130 
#define  MRB_TT_TRUE 129 
#define  MRB_TT_UNDEF 128 
 size_t RARRAY_LEN (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * RARRAY_PTR (int /*<<< orphan*/ *) ; 
 char* RSTRING_END (int /*<<< orphan*/ *) ; 
 char* RSTRING_PTR (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  TRUE ; 
 double floor (double) ; 
 size_t json_array_get_count (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * json_array_get_value (int /*<<< orphan*/ *,size_t) ; 
 size_t json_object_get_count (int /*<<< orphan*/ *) ; 
 char* json_object_get_name (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/ * json_object_get_value (int /*<<< orphan*/ *,char const*) ; 
 int /*<<< orphan*/ * json_parse_string (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  json_value_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * json_value_get_array (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  json_value_get_boolean (int /*<<< orphan*/ *) ; 
 double json_value_get_number (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * json_value_get_object (int /*<<< orphan*/ *) ; 
 char const* json_value_get_string (int /*<<< orphan*/ *) ; 
 int json_value_get_type (int /*<<< orphan*/ *) ; 
 scalar_t__ mrb_array_p (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mrb_ary_entry (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * mrb_ary_new (TYPE_1__*) ; 
 int /*<<< orphan*/  mrb_ary_push (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_define_class_method (TYPE_1__*,struct RClass*,char*,int /*<<< orphan*/ * (*) (TYPE_1__*,int /*<<< orphan*/ *),int) ; 
 struct RClass* mrb_define_module (TYPE_1__*,char*) ; 
 int /*<<< orphan*/ * mrb_false_value () ; 
 int /*<<< orphan*/ * mrb_fixnum_value (double) ; 
 int /*<<< orphan*/ * mrb_float_value (TYPE_1__*,double) ; 
 int /*<<< orphan*/ * mrb_funcall (TYPE_1__*,int /*<<< orphan*/ *,char*,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_gc_arena_restore (TYPE_1__*,int) ; 
 int mrb_gc_arena_save (TYPE_1__*) ; 
 int /*<<< orphan*/  mrb_get_args (TYPE_1__*,char*,int /*<<< orphan*/ **,...) ; 
 int /*<<< orphan*/ * mrb_hash_get (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mrb_hash_keys (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mrb_hash_new (TYPE_1__*) ; 
 int /*<<< orphan*/  mrb_hash_set (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ mrb_intern_cstr (TYPE_1__*,char const*) ; 
 scalar_t__ mrb_nil_p (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mrb_nil_value () ; 
 int /*<<< orphan*/  mrb_raise (TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/ * mrb_str_cat (TYPE_1__*,int /*<<< orphan*/ *,char*,int) ; 
 int /*<<< orphan*/ * mrb_str_cat_cstr (TYPE_1__*,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  mrb_str_concat (TYPE_1__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * mrb_str_new_cstr (TYPE_1__*,char const*) ; 
 int /*<<< orphan*/  mrb_str_to_cstr (TYPE_1__*,int /*<<< orphan*/ *) ; 
 scalar_t__ mrb_symbol (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * mrb_true_value () ; 
 int mrb_type (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mrb_yield_argv (TYPE_1__*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 

__attribute__((used)) static mrb_bool
mrb_method_defined(mrb_state* mrb, mrb_value value, const char* name) {
  int ai = mrb_gc_arena_save(mrb);
  mrb_sym mid = mrb_intern_cstr(mrb, name);
  mrb_value methods = mrb_funcall(mrb, value, "public_methods", 1, mrb_false_value());
  mrb_bool included = FALSE;
  if (mrb_array_p(methods)) {
    mrb_int i;
    for (i = 0; i < RARRAY_LEN(methods); ++i) {
      if (mid == mrb_symbol(RARRAY_PTR(methods)[i])) {
        included = TRUE;
        break;
      }
    }
  }
  mrb_gc_arena_restore(mrb, ai);
  return included;
}

__attribute__((used)) static mrb_value
pretty_cat(mrb_state* mrb, mrb_value str, int pretty) {
  int i;
  str = mrb_str_cat_cstr(mrb, str, "\n");
  for (i = 0; i < pretty; i++) str = mrb_str_cat_cstr(mrb, str, "  ");
  return str;
}

__attribute__((used)) static mrb_value
mrb_value_to_string(mrb_state* mrb, mrb_value value, int pretty) {
  mrb_value str;

  if (mrb_nil_p(value)) {
    return mrb_str_new_cstr(mrb, "null");
  }

  switch (mrb_type(value)) {
  case MRB_TT_FIXNUM:
  case MRB_TT_FLOAT:
  case MRB_TT_TRUE:
  case MRB_TT_FALSE:
  case MRB_TT_UNDEF:
    str = mrb_funcall(mrb, value, "to_s", 0, NULL);
    break;
  case MRB_TT_SYMBOL:
    value = mrb_funcall(mrb, value, "to_s", 0, NULL);
    /* FALLTHROUGH */
  case MRB_TT_STRING:
    {
      int ai = mrb_gc_arena_save(mrb);
      char* ptr = RSTRING_PTR(value);
      char* end = RSTRING_END(value);
      str = mrb_str_new_cstr(mrb, "\""); 
      while (ptr < end && *ptr) {
        switch (*ptr) {
        case '\\':
          str = mrb_str_cat_cstr(mrb, str, "\\\\");
          break;
        case '"':
          str = mrb_str_cat_cstr(mrb, str, "\\\"");
          break;
        case '\b':
          str = mrb_str_cat_cstr(mrb, str, "\\b");
          break;
        case '\f':
          str = mrb_str_cat_cstr(mrb, str, "\\f");
          break;
        case '\n':
          str = mrb_str_cat_cstr(mrb, str, "\\n");
          break;
        case '\r':
          str = mrb_str_cat_cstr(mrb, str, "\\r");
          break;
        case '\t':
          str = mrb_str_cat_cstr(mrb, str, "\\t");
          break;
        default:
          // TODO: handle unicode
          str = mrb_str_cat(mrb, str, ptr, 1);
        }
        ptr++;
      }
      mrb_str_cat_cstr(mrb, str, "\""); 
      mrb_gc_arena_restore(mrb, ai);
    }
    break;
  case MRB_TT_HASH:
    {
      mrb_value keys;
      int n, l;

      str = mrb_str_new_cstr(mrb, "{");
      keys = mrb_hash_keys(mrb, value);
      l = RARRAY_LEN(keys);
      if (l == 0) {
        if (pretty >= 0) return mrb_str_cat_cstr(mrb, str, "\n}");
        return mrb_str_cat_cstr(mrb, str, "}");
      }
      if (pretty >= 0) str = pretty_cat(mrb, str, ++pretty);
      for (n = 0; n < l; n++) {
        mrb_value obj;
        int ai = mrb_gc_arena_save(mrb);
        mrb_value key = mrb_ary_entry(keys, n);
        mrb_value enckey = mrb_funcall(mrb, key, "to_s", 0, NULL);
        enckey = mrb_funcall(mrb, enckey, "inspect", 0, NULL);
        mrb_str_concat(mrb, str, enckey);
        mrb_str_cat_cstr(mrb, str, ":");
        obj = mrb_hash_get(mrb, value, key);
        mrb_str_concat(mrb, str, mrb_value_to_string(mrb, obj, pretty));
        if (n != l - 1) {
          mrb_str_cat_cstr(mrb, str, ",");
          if (pretty >= 0) str = pretty_cat(mrb, str, pretty);
        }
        mrb_gc_arena_restore(mrb, ai);
      }
      if (pretty >= 0) str = pretty_cat(mrb, str, --pretty);
      mrb_str_cat_cstr(mrb, str, "}");
      break;
    }
  case MRB_TT_ARRAY:
    {
      int n, l;

      str = mrb_str_new_cstr(mrb, "[");
      l = RARRAY_LEN(value);
      if (l == 0) {
        if (pretty >= 0) return mrb_str_cat_cstr(mrb, str, "\n]");
        return mrb_str_cat_cstr(mrb, str, "]");
      }
      if (pretty >= 0) str = pretty_cat(mrb, str, ++pretty);
      for (n = 0; n < l; n++) {
        int ai = mrb_gc_arena_save(mrb);
        mrb_value obj = mrb_ary_entry(value, n);
        mrb_str_concat(mrb, str, mrb_value_to_string(mrb, obj, pretty));
        if (n != l - 1) {
          mrb_str_cat_cstr(mrb, str, ",");
          if (pretty >= 0) str = pretty_cat(mrb, str, pretty);
        }
        mrb_gc_arena_restore(mrb, ai);
      }
      if (pretty >= 0) str = pretty_cat(mrb, str, --pretty);
      mrb_str_cat_cstr(mrb, str, "]");
      break;
    }
  default:
    {
      if (mrb_method_defined(mrb, value, "to_json"))
        str = mrb_funcall(mrb, value, "to_json", 0, NULL);
      else
        str = mrb_value_to_string(mrb, mrb_funcall(mrb, value, "to_s", 0, NULL), pretty);
    }
  } 
  return str;
}

__attribute__((used)) static mrb_value
json_value_to_mrb_value(mrb_state* mrb, JSON_Value* value) {
  mrb_value ret;
  switch (json_value_get_type(value)) {
  case JSONError:
  case JSONNull:
    ret = mrb_nil_value();
    break;
  case JSONString:
    ret = mrb_str_new_cstr(mrb, json_value_get_string(value));
    break;
#ifdef JSON_FIXED_NUMBER
  case JSONFixed:
    ret = mrb_fixnum_value((mrb_int)json_value_get_fixed(value));
    break;
  case JSONNumber:
    ret = mrb_float_value(mrb, json_value_get_number(value));
    break;
#else
  case JSONNumber:
    {
      double d = json_value_get_number(value);
      if (floor(d) == d) {
        ret = mrb_fixnum_value(d);
      }
      else {
        ret = mrb_float_value(mrb, d);
      }
    }
    break;
#endif
  case JSONObject:
    {
      mrb_value hash = mrb_hash_new(mrb);
      JSON_Object* object = json_value_get_object(value);
      size_t count = json_object_get_count(object);
      size_t n;
      for (n = 0; n < count; n++) {
        int ai = mrb_gc_arena_save(mrb);
        const char* name = json_object_get_name(object, n);
        mrb_hash_set(mrb, hash, mrb_str_new_cstr(mrb, name),
          json_value_to_mrb_value(mrb, json_object_get_value(object, name)));
        mrb_gc_arena_restore(mrb, ai);
      }
      ret = hash;
    }
    break;
  case JSONArray:
    {
      mrb_value ary;
      JSON_Array* array;
      size_t n, count;
      ary = mrb_ary_new(mrb);
      array = json_value_get_array(value);
      count = json_array_get_count(array);
      for (n = 0; n < count; n++) {
        int ai = mrb_gc_arena_save(mrb);
        JSON_Value* elem = json_array_get_value(array, n);
        mrb_ary_push(mrb, ary, json_value_to_mrb_value(mrb, elem));
        mrb_gc_arena_restore(mrb, ai);
      }
      ret = ary;
    }
    break;
  case JSONBoolean:
    if (json_value_get_boolean(value))
      ret = mrb_true_value();
    else
      ret = mrb_false_value();
    break;
  default:
    mrb_raise(mrb, E_ARGUMENT_ERROR, "invalid argument");
  }
  return ret;
}

__attribute__((used)) static mrb_value
mrb_json_load(mrb_state *mrb, mrb_value self)
{
  mrb_value value, blk;
  JSON_Value *root_value;
  mrb_value json = mrb_nil_value();
  mrb_get_args(mrb, "S&", &json, &blk);

  root_value = json_parse_string(mrb_str_to_cstr(mrb, json));
  if (!root_value) {
    mrb_raise(mrb, E_PARSER_ERROR, "invalid json");
  }

  value = json_value_to_mrb_value(mrb, root_value);
  json_value_free(root_value);
  if (!mrb_nil_p(blk)) {
    mrb_value args[1];
    args[0] = value;
    mrb_yield_argv(mrb, blk, 1, args);
  }
  return value;
}

__attribute__((used)) static mrb_value
mrb_json_parse(mrb_state *mrb, mrb_value self)
{
  mrb_value value;
  JSON_Value *root_value;
  mrb_value json = mrb_nil_value();
  mrb_get_args(mrb, "S", &json);

  root_value = json_parse_string(mrb_str_to_cstr(mrb, json));
  if (!root_value) {
    mrb_raise(mrb, E_PARSER_ERROR, "invalid json");
  }

  value = json_value_to_mrb_value(mrb, root_value);
  json_value_free(root_value);
  return value;
}

__attribute__((used)) static mrb_value
mrb_json_dump(mrb_state *mrb, mrb_value self) {
  mrb_value obj, io = mrb_nil_value(), out;
  mrb_get_args(mrb, "o|o", &obj, &io);
  out = mrb_value_to_string(mrb, obj, -1);
  if (mrb_nil_p(io)) {
    return out;
  }
  mrb_funcall(mrb, io, "write", 1, out);
  return io;
}

__attribute__((used)) static mrb_value
mrb_json_generate(mrb_state *mrb, mrb_value self) {
  mrb_value obj;
  mrb_get_args(mrb, "o", &obj);
  return mrb_value_to_string(mrb, obj, -1);
}

__attribute__((used)) static mrb_value
mrb_json_pretty_generate(mrb_state *mrb, mrb_value self) {
  mrb_value obj;
  mrb_get_args(mrb, "o", &obj);
  return mrb_value_to_string(mrb, obj, 0);
}

__attribute__((used)) static mrb_value
mrb_json_to_json(mrb_state *mrb, mrb_value self) {
  return mrb_value_to_string(mrb, self, -1);
}

void
mrb_mruby_json_gem_init(mrb_state* mrb) {
  struct RClass *_class_json = mrb_define_module(mrb, "JSON");

  mrb_define_class_method(mrb, _class_json, "load", mrb_json_load, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, _class_json, "parse", mrb_json_parse, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, _class_json, "stringify", mrb_json_generate, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, _class_json, "dump", mrb_json_dump, MRB_ARGS_REQ(1)|MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, _class_json, "generate", mrb_json_generate, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, _class_json, "pretty_generate", mrb_json_pretty_generate, MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, mrb->object_class, "to_json", mrb_json_to_json, MRB_ARGS_NONE());
}

void
mrb_mruby_json_gem_final(mrb_state* mrb) {
}

