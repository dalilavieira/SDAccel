#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint32_t ;
typedef  int uint16_t ;
typedef  int /*<<< orphan*/  mrb_irep_debug_info_line ;
struct TYPE_5__ {scalar_t__ start_pos; } ;
typedef  TYPE_1__ mrb_irep_debug_info_file ;
struct TYPE_6__ {scalar_t__ pc_count; int flen; TYPE_1__** files; } ;
typedef  TYPE_2__ mrb_irep_debug_info ;
typedef  int /*<<< orphan*/  mrb_debug_line_type ;
typedef  int int32_t ;

/* Variables and functions */
 int /*<<< orphan*/  mrb_assert (int) ; 
 int /*<<< orphan*/  mrb_debug_line_ary ; 
 int /*<<< orphan*/  mrb_debug_line_flat_map ; 

__attribute__((used)) static mrb_irep_debug_info_file*
get_file(mrb_irep_debug_info *info, uint32_t pc)
{
  mrb_irep_debug_info_file **ret;
  int32_t count;

  if (pc >= info->pc_count) { return NULL; }
  /* get upper bound */
  ret = info->files;
  count =  info->flen;
  while (count > 0) {
    int32_t step = count / 2;
    mrb_irep_debug_info_file **it = ret + step;
    if (!(pc < (*it)->start_pos)) {
      ret = it + 1;
      count -= step + 1;
    }
    else { count = step; }
  }

  --ret;

  /* check returning file exists inside debug info */
  mrb_assert(info->files <= ret && ret < (info->files + info->flen));
  /* check pc is within the range of returning file */
  mrb_assert((*ret)->start_pos <= pc &&
             pc < (((ret + 1 - info->files) < info->flen)
                   ? (*(ret+1))->start_pos : info->pc_count));

  return *ret;
}

__attribute__((used)) static mrb_debug_line_type
select_line_type(const uint16_t *lines, size_t lines_len)
{
  size_t line_count = 0;
  int prev_line = -1;
  size_t i;
  for (i = 0; i < lines_len; ++i) {
    if (lines[i] != prev_line) {
      ++line_count;
    }
  }
  return (sizeof(uint16_t) * lines_len) <= (sizeof(mrb_irep_debug_info_line) * line_count)
      ? mrb_debug_line_ary : mrb_debug_line_flat_map;
}

