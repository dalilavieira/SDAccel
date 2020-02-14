#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_1__ ;

/* Type definitions */
struct TYPE_14__ {scalar_t__ cpu_time; int res; int expiration_time; char* query; } ;
typedef  TYPE_1__ search_query_heap_en_t ;
typedef  int /*<<< orphan*/  A ;

/* Variables and functions */
 int SEARCH_QUERY_EXPIRATION_TIME ; 
 int SEARCH_QUERY_HEAP_SIZE ; 
 TYPE_1__* SQH ; 
 int SQH_SIZE ; 
 TYPE_1__** alloca (int) ; 
 scalar_t__ get_rusage_time () ; 
 int now ; 
 int /*<<< orphan*/  qsort (TYPE_1__**,int,int,int (*) (void const*,void const*)) ; 
 int sprintf (char*,char*,char*,scalar_t__,int,int) ; 
 int /*<<< orphan*/  strcpy (char*,char*) ; 
 int strlen (char*) ; 

__attribute__((used)) static void search_query_copy (search_query_heap_en_t *D, search_query_heap_en_t *S) {
  D->cpu_time = S->cpu_time;
  D->res = S->res;
  D->expiration_time = S->expiration_time;
  strcpy (D->query, S->query);
}

__attribute__((used)) static void search_query_heapify_front (search_query_heap_en_t *E, int i) {
  while (1) {
    int j = i << 1;
    if (j > SQH_SIZE) { break; }
    if (j < SQH_SIZE && SQH[j].cpu_time > SQH[j+1].cpu_time) { j++; }
    if (E->cpu_time <= SQH[j].cpu_time) { break; }
    search_query_copy (SQH + i, SQH + j);
    i = j;
  }
  search_query_copy (SQH + i, E);
}

__attribute__((used)) static void search_query_heapify_back (search_query_heap_en_t *E, int i) {
  while (i > 1) {
    int j = (i >> 1);
    if (SQH[j].cpu_time <= E->cpu_time) { break; }
    search_query_copy (SQH + i, SQH + j);
    i = j;
  }
  search_query_copy (SQH + i, E);
}

__attribute__((used)) static void search_query_heap_insert (search_query_heap_en_t *E) {
  if (SQH_SIZE == SEARCH_QUERY_HEAP_SIZE) {
    search_query_heapify_front (E, 1);
  } else {
    search_query_heapify_back (E, ++SQH_SIZE);
  }
}

__attribute__((used)) static int cmp_search_queries (const void *a, const void *b) {
  const search_query_heap_en_t *A = *((const search_query_heap_en_t **) a);
  const search_query_heap_en_t *B = *((const search_query_heap_en_t **) b);
  if (A->cpu_time < B->cpu_time) { return -1; }
  if (A->cpu_time > B->cpu_time) { return  1; }
  return 0;
}

int search_query_worst (char *output, int olen) {
  int i;
  search_query_heap_en_t **A = alloca (SQH_SIZE * sizeof (A[0]));
  for (i = 0; i < SQH_SIZE; i++) {
    A[i] = SQH + i + 1;
  }
  qsort (A, SQH_SIZE, sizeof (A[0]), cmp_search_queries);
  char *p = output;
  for (i = SQH_SIZE - 1; i >= 0; i--) {
    if (strlen (A[i]->query) + 30 > olen) { break; }
    int l = sprintf (p, "%s\t%.6lf\t%d\t%d\n", A[i]->query, A[i]->cpu_time, A[i]->res, A[i]->expiration_time - SEARCH_QUERY_EXPIRATION_TIME);
    p += l;
    olen -= l;
  }
  return p - output;
}

void search_query_start (search_query_heap_en_t *E) {
  E->cpu_time = -get_rusage_time ();
}

void search_query_end (search_query_heap_en_t *E, int res, void *arg, void (*copy) (search_query_heap_en_t *, void *)) {
  E->cpu_time += get_rusage_time ();
  if (SQH_SIZE < SEARCH_QUERY_HEAP_SIZE || SQH[1].cpu_time < E->cpu_time) {
    copy (E, arg);
    E->res = res;
    E->expiration_time = now + SEARCH_QUERY_EXPIRATION_TIME;
    search_query_heap_insert (E);
  }
}

void search_query_remove_expired (void) {
  static int t = 0;
  if (now > t) {
    t = now + 60;
  } else {
    return;
  }
  int i;
  for (i = 1; i <= SQH_SIZE; ) {
    if (SQH[i].expiration_time < now) {
      SQH_SIZE--;
      search_query_heap_en_t *E = SQH + SQH_SIZE;
      if (i != SQH_SIZE) {
        if (SQH[i].cpu_time < E->cpu_time) {
          search_query_heapify_front (E, i);
        } else {
          search_query_heapify_back (E, i);
        }
      }
    } else {
      i++;
    }
  }
}

