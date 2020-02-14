#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_44__   TYPE_9__ ;
typedef  struct TYPE_43__   TYPE_8__ ;
typedef  struct TYPE_42__   TYPE_7__ ;
typedef  struct TYPE_41__   TYPE_6__ ;
typedef  struct TYPE_40__   TYPE_5__ ;
typedef  struct TYPE_39__   TYPE_4__ ;
typedef  struct TYPE_38__   TYPE_3__ ;
typedef  struct TYPE_37__   TYPE_2__ ;
typedef  struct TYPE_36__   TYPE_1__ ;
typedef  struct TYPE_35__   TYPE_10__ ;

/* Type definitions */
typedef  size_t uint32_t ;
typedef  size_t uint16_t ;
struct mrb_irep {size_t rlen; struct mrb_irep** reps; TYPE_3__* debug_info; } ;
struct RClass {int dummy; } ;
typedef  int /*<<< orphan*/  mrb_sym ;
typedef  int /*<<< orphan*/  mrb_state ;
typedef  int /*<<< orphan*/  mrb_method_t ;
struct TYPE_37__ {size_t* ary; TYPE_1__* flat_map; } ;
struct TYPE_40__ {size_t line_entry_count; scalar_t__ line_type; char const* filename; TYPE_2__ lines; } ;
typedef  TYPE_5__ mrb_irep_debug_info_file ;
struct TYPE_41__ {int /*<<< orphan*/ * iseq; } ;
typedef  TYPE_6__ mrb_irep ;
struct TYPE_42__ {char const* method_name; char* class_name; } ;
typedef  TYPE_7__ mrb_debug_methodpoint ;
struct TYPE_43__ {char const* file; size_t lineno; } ;
typedef  TYPE_8__ mrb_debug_linepoint ;
struct TYPE_44__ {size_t bpnum; scalar_t__ next_bpno; TYPE_10__* bp; int /*<<< orphan*/ * pc; TYPE_6__* irep; struct mrb_irep* root_irep; } ;
typedef  TYPE_9__ mrb_debug_context ;
struct TYPE_39__ {TYPE_8__ linepoint; TYPE_7__ methodpoint; } ;
struct TYPE_35__ {size_t bpno; int type; char enable; TYPE_4__ point; } ;
typedef  TYPE_10__ mrb_debug_breakpoint ;
typedef  int /*<<< orphan*/  mrb_code ;
typedef  char mrb_bool ;
typedef  size_t int32_t ;
struct TYPE_38__ {size_t flen; TYPE_5__** files; } ;
struct TYPE_36__ {size_t line; } ;

/* Variables and functions */
 char FALSE ; 
 scalar_t__ MAX_BREAKPOINT ; 
 scalar_t__ MAX_BREAKPOINTNO ; 
#define  MRB_DEBUG_BPTYPE_LINE 130 
#define  MRB_DEBUG_BPTYPE_METHOD 129 
#define  MRB_DEBUG_BPTYPE_NONE 128 
 size_t MRB_DEBUG_BP_FILE_OK ; 
 size_t MRB_DEBUG_BP_LINENO_OK ; 
 size_t MRB_DEBUG_BREAK_INVALID_FILE ; 
 size_t MRB_DEBUG_BREAK_INVALID_LINENO ; 
 size_t MRB_DEBUG_BREAK_INVALID_NO ; 
 size_t MRB_DEBUG_BREAK_NO_OVER ; 
 size_t MRB_DEBUG_BREAK_NUM_OVER ; 
 size_t MRB_DEBUG_INVALID_ARGUMENT ; 
 size_t MRB_DEBUG_OK ; 
 scalar_t__ MRB_METHOD_CFUNC_P (int /*<<< orphan*/ ) ; 
 scalar_t__ MRB_METHOD_UNDEF_P (int /*<<< orphan*/ ) ; 
 char TRUE ; 
 int /*<<< orphan*/  memcpy (TYPE_10__*,TYPE_10__*,int) ; 
 int /*<<< orphan*/  memset (TYPE_10__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mrb_check_intern_cstr (int /*<<< orphan*/ *,char const*) ; 
 char mrb_class_defined (int /*<<< orphan*/ *,char*) ; 
 struct RClass* mrb_class_get (int /*<<< orphan*/ *,char*) ; 
 char* mrb_class_name (int /*<<< orphan*/ *,struct RClass*) ; 
 size_t mrb_debug_get_line (TYPE_6__*,int) ; 
 scalar_t__ mrb_debug_line_ary ; 
 int /*<<< orphan*/  mrb_free (int /*<<< orphan*/ *,void*) ; 
 scalar_t__ mrb_malloc (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  mrb_method_search_vm (int /*<<< orphan*/ *,struct RClass**,int /*<<< orphan*/ ) ; 
 char* mrb_sym2name (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mrb_symbol (int /*<<< orphan*/ ) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 scalar_t__ strlen (char const*) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,scalar_t__) ; 

__attribute__((used)) static uint16_t
check_lineno(mrb_irep_debug_info_file *info_file, uint16_t lineno)
{
  uint32_t count = info_file->line_entry_count;
  uint16_t l_idx;

  if (info_file->line_type == mrb_debug_line_ary) {
    for (l_idx = 0; l_idx < count; ++l_idx) {
      if (lineno == info_file->lines.ary[l_idx]) {
        return lineno;
      }
    }
  }
  else {
    for (l_idx = 0; l_idx < count; ++l_idx) {
      if (lineno == info_file->lines.flat_map[l_idx].line) {
        return lineno;
      }
    }
  }

  return 0;
}

__attribute__((used)) static int32_t
get_break_index(mrb_debug_context *dbg, uint32_t bpno)
{
  uint32_t i;
  int32_t index;
  char hit = FALSE;

  for(i = 0 ; i < dbg->bpnum; i++) {
    if (dbg->bp[i].bpno == bpno) {
      hit = TRUE;
      index = i;
      break;
    }
  }

  if (hit == FALSE) {
    return MRB_DEBUG_BREAK_INVALID_NO;
  }

  return index;
}

__attribute__((used)) static void
free_breakpoint(mrb_state *mrb, mrb_debug_breakpoint *bp)
{
  switch(bp->type) {
    case MRB_DEBUG_BPTYPE_LINE:
      mrb_free(mrb, (void*)bp->point.linepoint.file);
      break;
    case MRB_DEBUG_BPTYPE_METHOD:
      mrb_free(mrb, (void*)bp->point.methodpoint.method_name);
      if (bp->point.methodpoint.class_name != NULL) {
        mrb_free(mrb, (void*)bp->point.methodpoint.class_name);
      }
      break;
    default:
      break;
  }
}

__attribute__((used)) static uint16_t
check_file_lineno(struct mrb_irep *irep, const char *file, uint16_t lineno)
{
  mrb_irep_debug_info_file *info_file;
  uint16_t result = 0;
  uint16_t f_idx;
  uint16_t fix_lineno;
  uint16_t i;

  for (f_idx = 0; f_idx < irep->debug_info->flen; ++f_idx) {
    info_file = irep->debug_info->files[f_idx];
    if (!strcmp(info_file->filename, file)) {
      result = MRB_DEBUG_BP_FILE_OK;

      fix_lineno = check_lineno(info_file, lineno);
      if (fix_lineno != 0) {
        return result | MRB_DEBUG_BP_LINENO_OK;
      }
    }
    for (i=0; i < irep->rlen; ++i) {
      result  |= check_file_lineno(irep->reps[i], file, lineno);
      if (result == (MRB_DEBUG_BP_FILE_OK | MRB_DEBUG_BP_LINENO_OK)) {
        return result;
      }
    }
  }
  return result;
}

__attribute__((used)) static int32_t
compare_break_method(mrb_state *mrb, mrb_debug_breakpoint *bp, struct RClass *class_obj, mrb_sym method_sym, mrb_bool* isCfunc)
{
  const char* class_name;
  const char* method_name;
  mrb_method_t m;
  struct RClass* sc;
  const char* sn;
  mrb_sym ssym;
  mrb_debug_methodpoint *method_p;
  mrb_bool is_defined;

  method_name = mrb_sym2name(mrb, method_sym);

  method_p = &bp->point.methodpoint;
  if (strcmp(method_p->method_name, method_name) == 0) {
    class_name = mrb_class_name(mrb, class_obj);
    if (class_name == NULL) {
      if (method_p->class_name == NULL) {
        return bp->bpno;
      }
    }
    else if (method_p->class_name != NULL) {
      m = mrb_method_search_vm(mrb, &class_obj, method_sym);
      if (MRB_METHOD_UNDEF_P(m)) {
        return MRB_DEBUG_OK;
      }
      if (MRB_METHOD_CFUNC_P(m)) {
        *isCfunc = TRUE;
      }

      is_defined = mrb_class_defined(mrb, method_p->class_name);
      if (is_defined == FALSE) {
        return MRB_DEBUG_OK;
      }

      sc = mrb_class_get(mrb, method_p->class_name);
      ssym = mrb_symbol(mrb_check_intern_cstr(mrb, method_p->method_name));
      m = mrb_method_search_vm(mrb, &sc, ssym);
      if (MRB_METHOD_UNDEF_P(m)) {
        return MRB_DEBUG_OK;
      }

      class_name = mrb_class_name(mrb, class_obj);
      sn = mrb_class_name(mrb, sc);
      if (strcmp(sn, class_name) == 0) {
        return bp->bpno;
      }
    }
  }
  return MRB_DEBUG_OK;
}

int32_t
mrb_debug_set_break_line(mrb_state *mrb, mrb_debug_context *dbg, const char *file, uint16_t lineno)
{
  int32_t index;
  char* set_file;
  uint16_t result;

  if ((mrb == NULL)||(dbg == NULL)||(file == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  if (dbg->bpnum >= MAX_BREAKPOINT) {
    return MRB_DEBUG_BREAK_NUM_OVER;
  }

  if (dbg->next_bpno > MAX_BREAKPOINTNO) {
    return MRB_DEBUG_BREAK_NO_OVER;
  }

  /* file and lineno check (line type mrb_debug_line_ary only.) */
  result = check_file_lineno(dbg->root_irep, file, lineno);
  if (result == 0) {
    return MRB_DEBUG_BREAK_INVALID_FILE;
  }
  else if (result == MRB_DEBUG_BP_FILE_OK) {
    return MRB_DEBUG_BREAK_INVALID_LINENO;
  }

  set_file = (char*)mrb_malloc(mrb, strlen(file) + 1);

  index = dbg->bpnum;
  dbg->bp[index].bpno = dbg->next_bpno;
  dbg->next_bpno++;
  dbg->bp[index].enable = TRUE;
  dbg->bp[index].type = MRB_DEBUG_BPTYPE_LINE;
  dbg->bp[index].point.linepoint.lineno = lineno;
  dbg->bpnum++;

  strncpy(set_file, file, strlen(file) + 1);

  dbg->bp[index].point.linepoint.file = set_file;

  return dbg->bp[index].bpno;
}

int32_t
mrb_debug_set_break_method(mrb_state *mrb, mrb_debug_context *dbg, const char *class_name, const char *method_name)
{
  int32_t index;
  char* set_class;
  char* set_method;

  if ((mrb == NULL) || (dbg == NULL) || (method_name == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  if (dbg->bpnum >= MAX_BREAKPOINT) {
    return MRB_DEBUG_BREAK_NUM_OVER;
  }

  if (dbg->next_bpno > MAX_BREAKPOINTNO) {
    return MRB_DEBUG_BREAK_NO_OVER;
  }

  if (class_name != NULL) {
    set_class = (char*)mrb_malloc(mrb, strlen(class_name) + 1);
    strncpy(set_class, class_name, strlen(class_name) + 1);
  }
  else {
    set_class = NULL;
  }

  set_method = (char*)mrb_malloc(mrb, strlen(method_name) + 1);

  strncpy(set_method, method_name, strlen(method_name) + 1);

  index = dbg->bpnum;
  dbg->bp[index].bpno = dbg->next_bpno;
  dbg->next_bpno++;
  dbg->bp[index].enable = TRUE;
  dbg->bp[index].type = MRB_DEBUG_BPTYPE_METHOD;
  dbg->bp[index].point.methodpoint.method_name = set_method;
  dbg->bp[index].point.methodpoint.class_name = set_class;
  dbg->bpnum++;

  return dbg->bp[index].bpno;
}

int32_t
mrb_debug_get_breaknum(mrb_state *mrb, mrb_debug_context *dbg)
{
  if ((mrb == NULL) || (dbg == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  return dbg->bpnum;
}

int32_t
mrb_debug_get_break_all(mrb_state *mrb, mrb_debug_context *dbg, uint32_t size, mrb_debug_breakpoint *bp)
{
  uint32_t get_size = 0;

  if ((mrb == NULL) || (dbg == NULL) || (bp == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  if (dbg->bpnum >= size) {
    get_size = size;
  }
  else {
    get_size = dbg->bpnum;
  }

  memcpy(bp, dbg->bp, sizeof(mrb_debug_breakpoint) * get_size);

  return get_size;
}

int32_t
mrb_debug_get_break(mrb_state *mrb, mrb_debug_context *dbg, uint32_t bpno, mrb_debug_breakpoint *bp)
{
  int32_t index;

  if ((mrb == NULL) || (dbg == NULL) || (bp == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  index = get_break_index(dbg, bpno);
  if (index == MRB_DEBUG_BREAK_INVALID_NO) {
    return MRB_DEBUG_BREAK_INVALID_NO;
  }

  bp->bpno = dbg->bp[index].bpno;
  bp->enable = dbg->bp[index].enable;
  bp->point = dbg->bp[index].point;
  bp->type = dbg->bp[index].type;

  return 0;
}

int32_t
mrb_debug_delete_break(mrb_state *mrb, mrb_debug_context *dbg, uint32_t bpno)
{
  uint32_t i;
  int32_t index;

  if ((mrb == NULL) ||(dbg == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  index = get_break_index(dbg, bpno);
  if (index == MRB_DEBUG_BREAK_INVALID_NO) {
    return MRB_DEBUG_BREAK_INVALID_NO;
  }

  free_breakpoint(mrb, &dbg->bp[index]);

  for(i = index ; i < dbg->bpnum; i++) {
    if ((i + 1) == dbg->bpnum) {
      memset(&dbg->bp[i], 0, sizeof(mrb_debug_breakpoint));
    }
    else {
      memcpy(&dbg->bp[i], &dbg->bp[i + 1], sizeof(mrb_debug_breakpoint));
    }
  }

  dbg->bpnum--;

  return MRB_DEBUG_OK;
}

int32_t
mrb_debug_delete_break_all(mrb_state *mrb, mrb_debug_context *dbg)
{
  uint32_t i;

  if ((mrb == NULL) || (dbg == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  for(i = 0 ; i < dbg->bpnum ; i++) {
    free_breakpoint(mrb, &dbg->bp[i]);
  }

  dbg->bpnum = 0;

  return MRB_DEBUG_OK;
}

int32_t
mrb_debug_enable_break(mrb_state *mrb, mrb_debug_context *dbg, uint32_t bpno)
{
  int32_t index = 0;

  if ((mrb == NULL) || (dbg == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  index = get_break_index(dbg, bpno);
  if (index == MRB_DEBUG_BREAK_INVALID_NO) {
    return MRB_DEBUG_BREAK_INVALID_NO;
  }

  dbg->bp[index].enable = TRUE;

  return MRB_DEBUG_OK;
}

int32_t
mrb_debug_enable_break_all(mrb_state *mrb, mrb_debug_context *dbg)
{
  uint32_t i;

  if ((mrb == NULL) || (dbg == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  for(i = 0 ; i < dbg->bpnum; i++) {
    dbg->bp[i].enable = TRUE;
  }

  return MRB_DEBUG_OK;
}

int32_t
mrb_debug_disable_break(mrb_state *mrb, mrb_debug_context *dbg, uint32_t bpno)
{
  int32_t index = 0;

  if ((mrb == NULL) || (dbg == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  index = get_break_index(dbg, bpno);
  if (index == MRB_DEBUG_BREAK_INVALID_NO) {
    return MRB_DEBUG_BREAK_INVALID_NO;
  }

  dbg->bp[index].enable = FALSE;

  return MRB_DEBUG_OK;
}

int32_t
mrb_debug_disable_break_all(mrb_state *mrb, mrb_debug_context *dbg)
{
  uint32_t i;

  if ((mrb == NULL) || (dbg == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  for(i = 0 ; i < dbg->bpnum; i++) {
    dbg->bp[i].enable = FALSE;
  }

  return MRB_DEBUG_OK;
}

__attribute__((used)) static mrb_bool
check_start_pc_for_line(mrb_irep *irep, mrb_code *pc, uint16_t line)
{
  if (pc > irep->iseq) {
    if (line == mrb_debug_get_line(irep, pc - irep->iseq - 1)) {
      return FALSE;
    }
  }
  return TRUE;
}

int32_t
mrb_debug_check_breakpoint_line(mrb_state *mrb, mrb_debug_context *dbg, const char *file, uint16_t line)
{
  mrb_debug_breakpoint *bp;
  mrb_debug_linepoint *line_p;
  uint32_t i;

  if ((mrb == NULL) || (dbg == NULL) || (file == NULL) || (line <= 0)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  if (!check_start_pc_for_line(dbg->irep, dbg->pc, line)) {
    return MRB_DEBUG_OK;
  }

  bp = dbg->bp;
  for(i=0; i<dbg->bpnum; i++) {
    switch (bp->type) {
      case MRB_DEBUG_BPTYPE_LINE:
        if (bp->enable == TRUE) {
          line_p = &bp->point.linepoint;
          if ((strcmp(line_p->file, file) == 0) && (line_p->lineno == line)) {
            return bp->bpno;
          }
        }
        break;
      case MRB_DEBUG_BPTYPE_METHOD:
        break;
      case MRB_DEBUG_BPTYPE_NONE:
      default:
        return MRB_DEBUG_OK;
    }
    bp++;
  }
  return MRB_DEBUG_OK;
}

int32_t
mrb_debug_check_breakpoint_method(mrb_state *mrb, mrb_debug_context *dbg, struct RClass *class_obj, mrb_sym method_sym, mrb_bool* isCfunc)
{
  mrb_debug_breakpoint *bp;
  int32_t bpno;
  uint32_t i;

  if ((mrb == NULL) || (dbg == NULL) || (class_obj == NULL)) {
    return MRB_DEBUG_INVALID_ARGUMENT;
  }

  bp = dbg->bp;
  for(i=0; i<dbg->bpnum; i++) {
    if (bp->type == MRB_DEBUG_BPTYPE_METHOD) {
      if (bp->enable == TRUE) {
        bpno = compare_break_method(mrb, bp, class_obj, method_sym, isCfunc);
        if (bpno > 0) {
          return bpno;
        }
      }
    }
    else if (bp->type == MRB_DEBUG_BPTYPE_NONE) {
      break;
    }
    bp++;
  }

  return 0;
}

