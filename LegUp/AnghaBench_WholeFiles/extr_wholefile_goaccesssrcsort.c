#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_36__   TYPE_9__ ;
typedef  struct TYPE_35__   TYPE_8__ ;
typedef  struct TYPE_34__   TYPE_7__ ;
typedef  struct TYPE_33__   TYPE_6__ ;
typedef  struct TYPE_32__   TYPE_5__ ;
typedef  struct TYPE_31__   TYPE_4__ ;
typedef  struct TYPE_30__   TYPE_3__ ;
typedef  struct TYPE_29__   TYPE_2__ ;
typedef  struct TYPE_28__   TYPE_20__ ;
typedef  struct TYPE_27__   TYPE_1__ ;
typedef  struct TYPE_26__   TYPE_19__ ;
typedef  struct TYPE_25__   TYPE_11__ ;
typedef  struct TYPE_24__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ uint64_t ;
struct TYPE_36__ {TYPE_10__* items; } ;
struct TYPE_27__ {int ivalue; char* svalue; } ;
struct TYPE_35__ {TYPE_1__ value; } ;
struct TYPE_34__ {int field; int /*<<< orphan*/  sort; } ;
struct TYPE_32__ {scalar_t__ nts; } ;
struct TYPE_31__ {scalar_t__ nts; } ;
struct TYPE_30__ {scalar_t__ nts; } ;
struct TYPE_29__ {scalar_t__ nbw; } ;
struct TYPE_33__ {char* data; int hits; int visitors; char* protocol; char* method; TYPE_5__ maxts; TYPE_4__ cumts; TYPE_3__ avgts; TYPE_2__ bw; } ;
struct TYPE_28__ {int sort_panel_idx; int /*<<< orphan*/ * sort_panels; int /*<<< orphan*/  append_method; int /*<<< orphan*/  append_protocol; int /*<<< orphan*/  bandwidth; int /*<<< orphan*/  serve_usecs; } ;
struct TYPE_26__ {int field; int sort; } ;
struct TYPE_25__ {char const* str; } ;
struct TYPE_24__ {TYPE_6__* metrics; } ;
typedef  size_t GSortOrder ;
typedef  size_t GSortField ;
typedef  TYPE_7__ GSort ;
typedef  TYPE_8__ GRawDataItem ;
typedef  TYPE_9__ GRawData ;
typedef  size_t GModule ;
typedef  TYPE_10__ GHolderItem ;

/* Variables and functions */
 int /*<<< orphan*/  ARRAY_SIZE (TYPE_11__*) ; 
 TYPE_11__* FIELD ; 
 TYPE_11__* ORDER ; 
#define  SORT_BY_AVGTS 136 
#define  SORT_BY_BW 135 
#define  SORT_BY_CUMTS 134 
#define  SORT_BY_DATA 133 
#define  SORT_BY_HITS 132 
#define  SORT_BY_MAXTS 131 
#define  SORT_BY_MTHD 130 
#define  SORT_BY_PROT 129 
#define  SORT_BY_VISITORS 128 
 int /*<<< orphan*/  SORT_DESC ; 
 int SORT_FIELD_LEN ; 
 int SORT_MODULE_LEN ; 
 int SORT_ORDER_LEN ; 
 int can_sort_module (size_t,int) ; 
 TYPE_20__ conf ; 
 int get_module_enum (char const*) ; 
 TYPE_19__* module_sort ; 
 int /*<<< orphan*/  qsort (TYPE_10__*,int,int,int (*) (void const*,void const*)) ; 
 int** sort_choices ; 
 int sscanf (int /*<<< orphan*/ ,char*,char*,char*,char*) ; 
 int str2enum (TYPE_11__*,int /*<<< orphan*/ ,char const*) ; 
 int strcmp (char*,char*) ; 

int
strcmp_asc (const void *a, const void *b)
{
  return strcmp (*((char **) a), *((char **) b));
}

__attribute__((used)) static int
cmp_data_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;
  return strcmp (ia->metrics->data, ib->metrics->data);
}

__attribute__((used)) static int
cmp_data_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;
  return strcmp (ib->metrics->data, ia->metrics->data);
}

__attribute__((used)) static int
cmp_num_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  int va = ia->metrics->hits;
  int vb = ib->metrics->hits;

  return (va < vb) - (va > vb);
}

__attribute__((used)) static int
cmp_num_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  int va = ia->metrics->hits;
  int vb = ib->metrics->hits;

  return (va > vb) - (va < vb);
}

__attribute__((used)) static int
cmp_vis_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  int va = ia->metrics->visitors;
  int vb = ib->metrics->visitors;

  return (va < vb) - (va > vb);
}

__attribute__((used)) static int
cmp_vis_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  int va = ia->metrics->visitors;
  int vb = ib->metrics->visitors;

  return (va > vb) - (va < vb);
}

__attribute__((used)) static int
cmp_raw_num_desc (const void *a, const void *b)
{
  const GRawDataItem *ia = a;
  const GRawDataItem *ib = b;

  int va = ia->value.ivalue;
  int vb = ib->value.ivalue;

  return (va < vb) - (va > vb);
}

__attribute__((used)) static int
cmp_raw_str_desc (const void *a, const void *b)
{
  const GRawDataItem *ia = a;
  const GRawDataItem *ib = b;

  return strcmp (ib->value.svalue, ia->value.svalue);
}

__attribute__((used)) static int
cmp_bw_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->bw.nbw;
  uint64_t vb = ib->metrics->bw.nbw;

  return (va < vb) - (va > vb);
}

__attribute__((used)) static int
cmp_bw_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->bw.nbw;
  uint64_t vb = ib->metrics->bw.nbw;

  return (va > vb) - (va < vb);
}

__attribute__((used)) static int
cmp_avgts_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->avgts.nts;
  uint64_t vb = ib->metrics->avgts.nts;

  return (va < vb) - (va > vb);
}

__attribute__((used)) static int
cmp_avgts_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->avgts.nts;
  uint64_t vb = ib->metrics->avgts.nts;

  return (va > vb) - (va < vb);
}

__attribute__((used)) static int
cmp_cumts_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->cumts.nts;
  uint64_t vb = ib->metrics->cumts.nts;

  return (va < vb) - (va > vb);
}

__attribute__((used)) static int
cmp_cumts_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->cumts.nts;
  uint64_t vb = ib->metrics->cumts.nts;

  return (va > vb) - (va < vb);
}

__attribute__((used)) static int
cmp_maxts_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->maxts.nts;
  uint64_t vb = ib->metrics->maxts.nts;

  return (va < vb) - (va > vb);
}

__attribute__((used)) static int
cmp_maxts_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;

  uint64_t va = ia->metrics->maxts.nts;
  uint64_t vb = ib->metrics->maxts.nts;

  return (va > vb) - (va < vb);
}

__attribute__((used)) static int
cmp_proto_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;
  return strcmp (ia->metrics->protocol, ib->metrics->protocol);
}

__attribute__((used)) static int
cmp_proto_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;
  return strcmp (ib->metrics->protocol, ia->metrics->protocol);
}

__attribute__((used)) static int
cmp_mthd_asc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;
  return strcmp (ia->metrics->method, ib->metrics->method);
}

__attribute__((used)) static int
cmp_mthd_desc (const void *a, const void *b)
{
  const GHolderItem *ia = a;
  const GHolderItem *ib = b;
  return strcmp (ib->metrics->method, ia->metrics->method);
}

int
get_sort_field_enum (const char *str)
{
  return str2enum (FIELD, ARRAY_SIZE (FIELD), str);
}

int
get_sort_order_enum (const char *str)
{
  return str2enum (ORDER, ARRAY_SIZE (ORDER), str);
}

const char *
get_sort_order_str (GSortOrder order)
{
  return ORDER[order].str;
}

const char *
get_sort_field_str (GSortField field)
{
  return FIELD[field].str;
}

const char *
get_sort_field_key (GSortField field)
{
  static const char *field2key[][2] = {
    {"BY_HITS", "hits"},
    {"BY_VISITORS", "visitors"},
    {"BY_DATA", "data"},
    {"BY_BW", "bytes"},
    {"BY_AVGTS", "avgts"},
    {"BY_CUMTS", "cumts"},
    {"BY_MAXTS", "maxts"},
    {"BY_PROT", "protocol"},
    {"BY_MTHD", "method"},
  };

  return field2key[field][1];
}

void
set_initial_sort (const char *smod, const char *sfield, const char *ssort)
{
  int module, field, order;
  if ((module = get_module_enum (smod)) == -1)
    return;

  if ((field = get_sort_field_enum (sfield)) == -1)
    return;
  if ((order = get_sort_order_enum (ssort)) == -1)
    return;
  if (!can_sort_module (module, field))
    return;

  module_sort[module].field = field;
  module_sort[module].sort = order;
}

int
can_sort_module (GModule module, int field)
{
  int i, can_sort = 0;
  for (i = 0; -1 != sort_choices[module][i]; i++) {
    if (sort_choices[module][i] != field)
      continue;
    if (SORT_BY_AVGTS == field && !conf.serve_usecs)
      continue;
    if (SORT_BY_CUMTS == field && !conf.serve_usecs)
      continue;
    if (SORT_BY_MAXTS == field && !conf.serve_usecs)
      continue;
    else if (SORT_BY_BW == field && !conf.bandwidth)
      continue;
    else if (SORT_BY_PROT == field && !conf.append_protocol)
      continue;
    else if (SORT_BY_MTHD == field && !conf.append_method)
      continue;

    can_sort = 1;
    break;
  }

  return can_sort;
}

void
parse_initial_sort (void)
{
  int i;
  char module[SORT_MODULE_LEN], field[SORT_FIELD_LEN], order[SORT_ORDER_LEN];
  for (i = 0; i < conf.sort_panel_idx; ++i) {
    if (sscanf
        (conf.sort_panels[i], "%15[^','],%11[^','],%4s", module, field,
         order) != 3)
      continue;
    set_initial_sort (module, field, order);
  }
}

void
sort_holder_items (GHolderItem * items, int size, GSort sort)
{
  switch (sort.field) {
  case SORT_BY_HITS:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_num_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_num_asc);
    break;
  case SORT_BY_VISITORS:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_vis_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_vis_asc);
    break;
  case SORT_BY_DATA:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_data_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_data_asc);
    break;
  case SORT_BY_BW:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_bw_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_bw_asc);
    break;
  case SORT_BY_AVGTS:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_avgts_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_avgts_asc);
    break;
  case SORT_BY_CUMTS:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_cumts_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_cumts_asc);
    break;
  case SORT_BY_MAXTS:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_maxts_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_maxts_asc);
    break;
  case SORT_BY_PROT:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_proto_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_proto_asc);
    break;
  case SORT_BY_MTHD:
    if (sort.sort == SORT_DESC)
      qsort (items, size, sizeof (GHolderItem), cmp_mthd_desc);
    else
      qsort (items, size, sizeof (GHolderItem), cmp_mthd_asc);
    break;
  }
}

GRawData *
sort_raw_num_data (GRawData * raw_data, int ht_size)
{
  qsort (raw_data->items, ht_size, sizeof *(raw_data->items), cmp_raw_num_desc);
  return raw_data;
}

GRawData *
sort_raw_str_data (GRawData * raw_data, int ht_size)
{
  qsort (raw_data->items, ht_size, sizeof *(raw_data->items), cmp_raw_str_desc);
  return raw_data;
}

