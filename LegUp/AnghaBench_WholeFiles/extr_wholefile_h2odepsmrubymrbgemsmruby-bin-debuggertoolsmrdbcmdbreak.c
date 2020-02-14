#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_43__   TYPE_7__ ;
typedef  struct TYPE_42__   TYPE_5__ ;
typedef  struct TYPE_41__   TYPE_4__ ;
typedef  struct TYPE_40__   TYPE_3__ ;
typedef  struct TYPE_39__   TYPE_2__ ;
typedef  struct TYPE_38__   TYPE_1__ ;
typedef  struct TYPE_37__   TYPE_14__ ;

/* Type definitions */
typedef  int uint32_t ;
typedef  int (* select_command_func ) (int /*<<< orphan*/ *,TYPE_4__*,int) ;
struct TYPE_42__ {int wcnt; char** words; char* command; TYPE_4__* dbg; } ;
typedef  TYPE_5__ mrdb_state ;
typedef  int /*<<< orphan*/  mrb_state ;
struct TYPE_41__ {TYPE_14__* irep; scalar_t__ pc; } ;
typedef  TYPE_4__ mrb_debug_context ;
struct TYPE_40__ {int /*<<< orphan*/  method_name; int /*<<< orphan*/ * class_name; } ;
struct TYPE_38__ {int /*<<< orphan*/  lineno; int /*<<< orphan*/  file; } ;
struct TYPE_39__ {TYPE_3__ methodpoint; TYPE_1__ linepoint; } ;
struct TYPE_43__ {int type; size_t enable; TYPE_2__ point; int /*<<< orphan*/  bpno; } ;
typedef  TYPE_7__ mrb_debug_breakpoint ;
typedef  int mrb_debug_bptype ;
typedef  scalar_t__ mrb_bool ;
typedef  int int32_t ;
typedef  int /*<<< orphan*/  dbgcmd_state ;
typedef  int (* all_command_func ) (int /*<<< orphan*/ *,TYPE_4__*) ;
struct TYPE_37__ {scalar_t__ iseq; } ;

/* Variables and functions */
 scalar_t__ BPNO_LETTER_NUM ; 
 char* BREAK_ERR_MSG_BLANK ; 
 char* BREAK_ERR_MSG_INVALIDARG ; 
 char* BREAK_ERR_MSG_INVALIDBPNO ; 
 char* BREAK_ERR_MSG_INVALIDBPNO_INFO ; 
 char* BREAK_ERR_MSG_INVALIDCLASS ; 
 char* BREAK_ERR_MSG_INVALIDFILE ; 
 char* BREAK_ERR_MSG_INVALIDLINENO ; 
 char* BREAK_ERR_MSG_INVALIDMETHOD ; 
 char* BREAK_ERR_MSG_INVALIDSTR ; 
 char* BREAK_ERR_MSG_NOBPNO ; 
 char* BREAK_ERR_MSG_NOBPNO_INFO ; 
 char* BREAK_ERR_MSG_NOBPNO_INFOALL ; 
 char* BREAK_ERR_MSG_NOOVER ; 
 char* BREAK_ERR_MSG_NUMOVER ; 
 char* BREAK_ERR_MSG_RANGEOVER ; 
 char const* BREAK_INFO_MSG_DISABLE ; 
 char const* BREAK_INFO_MSG_ENABLE ; 
 char* BREAK_INFO_MSG_HEADER ; 
 char* BREAK_INFO_MSG_LINEBREAK ; 
 char* BREAK_INFO_MSG_METHODBREAK ; 
 char* BREAK_INFO_MSG_METHODBREAK_NOCLASS ; 
 char* BREAK_SET_MSG_CLASS_METHOD ; 
 char* BREAK_SET_MSG_LINE ; 
 char* BREAK_SET_MSG_METHOD ; 
 int /*<<< orphan*/  DBGST_PROMPT ; 
 scalar_t__ FALSE ; 
 scalar_t__ ISBLANK (char) ; 
 scalar_t__ ISCNTRL (char) ; 
 int /*<<< orphan*/  ISDIGIT (char) ; 
 int /*<<< orphan*/  ISLOWER (char) ; 
 int /*<<< orphan*/  ISUPPER (char) ; 
 scalar_t__ LINENO_MAX_DIGIT ; 
#define  MRB_DEBUG_BPTYPE_LINE 136 
#define  MRB_DEBUG_BPTYPE_METHOD 135 
#define  MRB_DEBUG_BPTYPE_NONE 134 
#define  MRB_DEBUG_BREAK_INVALID_FILE 133 
#define  MRB_DEBUG_BREAK_INVALID_LINENO 132 
 int MRB_DEBUG_BREAK_INVALID_NO ; 
#define  MRB_DEBUG_BREAK_NO_OVER 131 
#define  MRB_DEBUG_BREAK_NUM_OVER 130 
#define  MRB_DEBUG_INVALID_ARGUMENT 129 
#define  MRB_DEBUG_NOBUF 128 
 int MRB_DEBUG_OK ; 
 int /*<<< orphan*/  STRTOUL (int,char*) ; 
 scalar_t__ TRUE ; 
 int mrb_debug_delete_break (int /*<<< orphan*/ *,TYPE_4__*,int) ; 
 int mrb_debug_delete_break_all (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int mrb_debug_disable_break (int /*<<< orphan*/ *,TYPE_4__*,int) ; 
 int mrb_debug_disable_break_all (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int mrb_debug_enable_break (int /*<<< orphan*/ *,TYPE_4__*,int) ; 
 int mrb_debug_enable_break_all (int /*<<< orphan*/ *,TYPE_4__*) ; 
 int mrb_debug_get_break (int /*<<< orphan*/ *,TYPE_4__*,int,TYPE_7__*) ; 
 int mrb_debug_get_break_all (int /*<<< orphan*/ *,TYPE_4__*,int,TYPE_7__*) ; 
 int mrb_debug_get_breaknum (int /*<<< orphan*/ *,TYPE_4__*) ; 
 char* mrb_debug_get_filename (TYPE_14__*,scalar_t__) ; 
 int mrb_debug_set_break_line (int /*<<< orphan*/ *,TYPE_4__*,char const*,int) ; 
 int mrb_debug_set_break_method (int /*<<< orphan*/ *,TYPE_4__*,char*,char*) ; 
 int /*<<< orphan*/  mrb_free (int /*<<< orphan*/ *,TYPE_7__*) ; 
 scalar_t__ mrb_malloc (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  puts (char*) ; 
 scalar_t__ strlen (char*) ; 
 char* strrchr (char*,char) ; 

__attribute__((used)) static void
print_api_common_error(int32_t error)
{
  switch(error) {
    case MRB_DEBUG_INVALID_ARGUMENT:
      puts(BREAK_ERR_MSG_INVALIDARG);
      break;
    default:
      break;
  }
}

__attribute__((used)) static int32_t
parse_breakpoint_no(char* args)
{
  char* ps = args;
  uint32_t l;

  if ((*ps == '0')||(strlen(ps) >= BPNO_LETTER_NUM)) {
    return 0;
  }

  while (!(ISBLANK(*ps)||ISCNTRL(*ps))) {
    if (!ISDIGIT(*ps)) {
      return 0;
    }
    ps++;
  }

  STRTOUL(l, args);
  return l;
}

__attribute__((used)) static mrb_bool
exe_set_command_all(mrb_state *mrb, mrdb_state *mrdb, all_command_func func)
{
  int32_t ret = MRB_DEBUG_OK;

  if (mrdb->wcnt == 1) {
    ret = func(mrb, mrdb->dbg);
    print_api_common_error(ret);
    return TRUE;
  }
  return FALSE;
}

__attribute__((used)) static void
exe_set_command_select(mrb_state *mrb, mrdb_state *mrdb, select_command_func func)
{
  char* ps;
  int32_t ret = MRB_DEBUG_OK;
  int32_t bpno = 0;
  int32_t i;

  for(i=1; i<mrdb->wcnt; i++) {
    ps = mrdb->words[i];
    bpno = parse_breakpoint_no(ps);
    if (bpno == 0) {
      printf(BREAK_ERR_MSG_INVALIDBPNO, ps);
      break;
    }
    ret = func(mrb, mrdb->dbg, (uint32_t)bpno);
    if (ret == MRB_DEBUG_BREAK_INVALID_NO) {
      printf(BREAK_ERR_MSG_NOBPNO, bpno);
    }
    else if (ret != MRB_DEBUG_OK) {
      print_api_common_error(ret);
    }
  }
}

mrb_debug_bptype
check_bptype(char* args)
{
  char* ps = args;

  if (ISBLANK(*ps)||ISCNTRL(*ps)) {
    puts(BREAK_ERR_MSG_BLANK);
    return MRB_DEBUG_BPTYPE_NONE;
  }

  if (!ISDIGIT(*ps)) {
    return MRB_DEBUG_BPTYPE_METHOD;
  }

  while (!(ISBLANK(*ps)||ISCNTRL(*ps))) {
    if (!ISDIGIT(*ps)) {
      printf(BREAK_ERR_MSG_INVALIDSTR, args);
      return MRB_DEBUG_BPTYPE_NONE;
    }
    ps++;
  }

  if ((*args == '0')||(strlen(args) >= LINENO_MAX_DIGIT)) {
    puts(BREAK_ERR_MSG_RANGEOVER);
    return MRB_DEBUG_BPTYPE_NONE;
  }

  return MRB_DEBUG_BPTYPE_LINE;
}

__attribute__((used)) static void
print_breakpoint(mrb_debug_breakpoint *bp)
{
  const char* enable_letter[] = {BREAK_INFO_MSG_DISABLE, BREAK_INFO_MSG_ENABLE};

  if (bp->type == MRB_DEBUG_BPTYPE_LINE) {
    printf(BREAK_INFO_MSG_LINEBREAK,
      bp->bpno, enable_letter[bp->enable], bp->point.linepoint.file, bp->point.linepoint.lineno);
  }
  else {
    if (bp->point.methodpoint.class_name == NULL) {
      printf(BREAK_INFO_MSG_METHODBREAK_NOCLASS,
        bp->bpno, enable_letter[bp->enable], bp->point.methodpoint.method_name);
    }
    else {
      printf(BREAK_INFO_MSG_METHODBREAK,
        bp->bpno, enable_letter[bp->enable], bp->point.methodpoint.class_name, bp->point.methodpoint.method_name);
    }
  }
}

__attribute__((used)) static void
info_break_all(mrb_state *mrb, mrdb_state *mrdb)
{
  int32_t bpnum = 0;
  int32_t i = 0;
  int32_t ret = MRB_DEBUG_OK;
  mrb_debug_breakpoint *bp_list;

  bpnum = mrb_debug_get_breaknum(mrb, mrdb->dbg);
  if (bpnum < 0) {
    print_api_common_error(bpnum);
    return;
  }
  else if (bpnum == 0) {
    puts(BREAK_ERR_MSG_NOBPNO_INFOALL);
    return;
  }
  bp_list = (mrb_debug_breakpoint*)mrb_malloc(mrb, bpnum * sizeof(mrb_debug_breakpoint));

  ret = mrb_debug_get_break_all(mrb, mrdb->dbg, (uint32_t)bpnum, bp_list);
  if (ret < 0) {
    print_api_common_error(ret);
    return;
  }
  puts(BREAK_INFO_MSG_HEADER);
  for(i = 0 ; i < bpnum ; i++) {
    print_breakpoint(&bp_list[i]);
  }

  mrb_free(mrb, bp_list);
}

__attribute__((used)) static void
info_break_select(mrb_state *mrb, mrdb_state *mrdb)
{
  int32_t ret = MRB_DEBUG_OK;
  int32_t bpno = 0;
  char* ps = mrdb->command;
  mrb_debug_breakpoint bp;
  mrb_bool isFirst = TRUE;
  int32_t i;

  for(i=2; i<mrdb->wcnt; i++) {
    ps = mrdb->words[i];
    bpno = parse_breakpoint_no(ps);
    if (bpno == 0) {
      puts(BREAK_ERR_MSG_INVALIDBPNO_INFO);
      break;
    }

    ret = mrb_debug_get_break(mrb, mrdb->dbg, bpno, &bp);
    if (ret == MRB_DEBUG_BREAK_INVALID_NO) {
      printf(BREAK_ERR_MSG_NOBPNO_INFO, bpno);
      break;
    }
    else if (ret != MRB_DEBUG_OK) {
      print_api_common_error(ret);
      break;
    }
    else if (isFirst == TRUE) {
      isFirst = FALSE;
      puts(BREAK_INFO_MSG_HEADER);
    }
    print_breakpoint(&bp);
  }
}

mrb_debug_bptype
parse_breakcommand(mrdb_state *mrdb, const char **file, uint32_t *line, char **cname, char **method)
{
  mrb_debug_context *dbg = mrdb->dbg;
  char *args;
  char *body;
  mrb_debug_bptype type;
  uint32_t l;

  if (mrdb->wcnt <= 1) {
    puts(BREAK_ERR_MSG_BLANK);
    return MRB_DEBUG_BPTYPE_NONE;
  }

  args = mrdb->words[1];
  if ((body = strrchr(args, ':')) == NULL) {
    body = args;
    type = check_bptype(body);
  }
  else {
    if (body == args) {
      printf(BREAK_ERR_MSG_INVALIDSTR, args);
      return MRB_DEBUG_BPTYPE_NONE;
    }
    *body = '\0';
    type = check_bptype(++body);
  }

  switch(type) {
    case MRB_DEBUG_BPTYPE_LINE:
      STRTOUL(l, body);
      if (l <= 65535) {
        *line = l;
        *file = (body == args)? mrb_debug_get_filename(dbg->irep, dbg->pc - dbg->irep->iseq): args;
      }
      else {
        puts(BREAK_ERR_MSG_RANGEOVER);
        type = MRB_DEBUG_BPTYPE_NONE;
      }
      break;
    case MRB_DEBUG_BPTYPE_METHOD:
      if (body == args) {
        /* method only */
        if (ISUPPER(*body)||ISLOWER(*body)||(*body == '_')) {
          *method = body;
          *cname = NULL;
        }
        else {
          printf(BREAK_ERR_MSG_INVALIDMETHOD, args);
          type = MRB_DEBUG_BPTYPE_NONE;
        }
      }
      else {
        if (ISUPPER(*args)) {
          switch(*body) {
            case '@': case '$': case '?': case '.': case ',': case ':':
            case ';': case '#': case '\\': case '\'': case '\"':
            printf(BREAK_ERR_MSG_INVALIDMETHOD, body);
            type = MRB_DEBUG_BPTYPE_NONE;
            break;
          default:
            *method = body;
            *cname = args;
            break;
          }
        }
        else {
          printf(BREAK_ERR_MSG_INVALIDCLASS, args);
          type = MRB_DEBUG_BPTYPE_NONE;
        }
      }
      break;
    case MRB_DEBUG_BPTYPE_NONE:
    default:
      break;
  }

  return type;
}

dbgcmd_state
dbgcmd_break(mrb_state *mrb, mrdb_state *mrdb)
{
  mrb_debug_bptype type;
  mrb_debug_context *dbg = mrdb->dbg;
  const char *file = NULL;
  uint32_t line = 0;
  char *cname = NULL;
  char *method = NULL;
  int32_t ret;

  type = parse_breakcommand(mrdb, &file, &line, &cname, &method);
  switch (type) {
    case MRB_DEBUG_BPTYPE_LINE:
      ret = mrb_debug_set_break_line(mrb, dbg, file, line);
      break;
    case MRB_DEBUG_BPTYPE_METHOD:
      ret = mrb_debug_set_break_method(mrb, dbg, cname, method);
      break;
    case MRB_DEBUG_BPTYPE_NONE:
    default:
      return DBGST_PROMPT;
  }

  if (ret >= 0) {
    if (type == MRB_DEBUG_BPTYPE_LINE) {
      printf(BREAK_SET_MSG_LINE, ret, file, line);
    }
    else if ((type == MRB_DEBUG_BPTYPE_METHOD)&&(cname == NULL)) {
      printf(BREAK_SET_MSG_METHOD, ret, method);
    }
    else {
      printf(BREAK_SET_MSG_CLASS_METHOD, ret, cname, method);
    }
  }
  else {
    switch (ret) {
      case MRB_DEBUG_BREAK_INVALID_LINENO:
        printf(BREAK_ERR_MSG_INVALIDLINENO, line, file);
        break;
      case MRB_DEBUG_BREAK_INVALID_FILE:
        printf(BREAK_ERR_MSG_INVALIDFILE, file);
        break;
      case MRB_DEBUG_BREAK_NUM_OVER:
        puts(BREAK_ERR_MSG_NUMOVER);
        break;
      case MRB_DEBUG_BREAK_NO_OVER:
        puts(BREAK_ERR_MSG_NOOVER);
        break;
      case MRB_DEBUG_INVALID_ARGUMENT:
        puts(BREAK_ERR_MSG_INVALIDARG);
        break;
      case MRB_DEBUG_NOBUF:
        puts("T.B.D.");
        break;
      default:
        break;
    }
  }

  return DBGST_PROMPT;
}

dbgcmd_state
dbgcmd_info_break(mrb_state *mrb, mrdb_state *mrdb)
{
  if (mrdb->wcnt == 2) {
    info_break_all(mrb, mrdb);
  }
  else {
    info_break_select(mrb, mrdb);
  }

  return DBGST_PROMPT;
}

dbgcmd_state
dbgcmd_delete(mrb_state *mrb, mrdb_state *mrdb)
{
  mrb_bool ret = FALSE;

  ret = exe_set_command_all(mrb, mrdb, mrb_debug_delete_break_all);
  if (ret != TRUE) {
    exe_set_command_select(mrb, mrdb, mrb_debug_delete_break);
  }

  return DBGST_PROMPT;
}

dbgcmd_state
dbgcmd_enable(mrb_state *mrb, mrdb_state *mrdb)
{
  mrb_bool ret = FALSE;

  ret = exe_set_command_all(mrb, mrdb, mrb_debug_enable_break_all);
  if (ret != TRUE) {
    exe_set_command_select(mrb, mrdb, mrb_debug_enable_break);
  }

  return DBGST_PROMPT;
}

dbgcmd_state
dbgcmd_disable(mrb_state *mrb, mrdb_state *mrdb)
{
  mrb_bool ret = FALSE;

  ret = exe_set_command_all(mrb, mrdb, mrb_debug_disable_break_all);
  if (ret != TRUE) {
    exe_set_command_select(mrb, mrdb, mrb_debug_disable_break);
  }
  return DBGST_PROMPT;
}

