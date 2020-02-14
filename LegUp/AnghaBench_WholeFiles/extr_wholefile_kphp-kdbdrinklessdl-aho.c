#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_2__ ;
typedef  struct TYPE_18__   TYPE_1__ ;

/* Type definitions */
struct TYPE_18__ {int is_end; scalar_t__ code; struct TYPE_18__* h; struct TYPE_18__* v; scalar_t__ cnt; } ;
typedef  TYPE_1__ trie_node ;
struct TYPE_19__ {scalar_t__* edges; int en; int is_end; int suff; } ;
typedef  TYPE_2__ trie_arr_node ;
typedef  scalar_t__ CHAR ;

/* Variables and functions */
 TYPE_2__* TSHIFT (TYPE_2__*,int) ; 
 int /*<<< orphan*/  assert (int) ; 
 TYPE_1__* free_trie_nodes ; 
 scalar_t__ free_trie_nodes_cnt ; 
 TYPE_1__* malloc (int) ; 
 int /*<<< orphan*/  puts (char*) ; 
 int /*<<< orphan*/  qsort (int*,int,int,int (*) (void const*,void const*)) ; 

trie_node *get_node (void) {
  if (free_trie_nodes_cnt == 0) {
    int add = 10000;
    free_trie_nodes = malloc (sizeof (trie_node) * add);
    assert (free_trie_nodes != NULL);
    free_trie_nodes_cnt += add;

    int i;
    for (i = 0; i + 1 < add; i++) {
      free_trie_nodes [i].v = &free_trie_nodes [i + 1];
    }
    free_trie_nodes [add - 1].v = NULL;
  }
  free_trie_nodes_cnt--;

  trie_node *res = free_trie_nodes;
  free_trie_nodes = free_trie_nodes->v;

  res->v = NULL;
  res->h = NULL;
  res->is_end = 0;
  res->code = 0;
  res->cnt = 0;

  return res;
}

int trie_check (trie_node *v, CHAR *s) {
  while (1) {
    while (v && v->code != *s) {
      v = v->h;
    }
    if (v == NULL) {
      return 0;
    }
    s++;
    if (*s == 0) {
      return v->is_end;
    }
    v = v->v;
  }
}

void trie_add (trie_node **v, CHAR *s) {
  if (trie_check (*v, s)) {
    return;
  }

  while (1) {
    //fprintf (stderr, "add <%s>\n", s);
    while (*v && (*v)->code != *s) {
      v = &(*v)->h;
    }
    if (*v == NULL) {
      *v = get_node();
      (*v)->code = *s;
    }
    s++;
    (*v)->cnt++;
    if (*s == 0) {
      (*v)->is_end = 1;
      break;
    }
    v = &(*v)->v;
  }
}

void trie_del (trie_node *v, CHAR *s) {
  if (!trie_check (v, s)) {
    return;
  }

  while (1) {
    while (v && v->code != *s) {
      v = v->h;
    }
    s++;
    v->cnt--;
    if (*s == 0) {
      v->is_end = 0;
      break;
    }

    v = v->v;
  }
}

int cmp_tx (const void *x, const void *y) {
  int a = ((int *)x)[1], b = ((int *)y)[1];
  return a < b ? -1 : a == b ? 0 : +1;
}

size_t trie_encode (trie_node *v, char *buff, int is_end) {
  char *st = buff;

  size_t vsize = sizeof (int) * 3;

  int en = 0;
  trie_node *tv = v;

  trie_arr_node *nv = (trie_arr_node *)st;
  assert (vsize == (char *)&nv->edges - (char *)nv);

  while (tv != NULL) {
    en += !!tv->cnt;
    tv = tv->h;
  }

  vsize += sizeof (int) * 2 * en;
  buff += vsize;

  tv = v;
  int in = 0;
  while (tv != NULL) {
    if (tv->cnt) {
      nv->edges[in * 2 + 1] = tv->code;
      nv->edges[in * 2] = buff - st;
      buff += trie_encode (tv->v, buff, tv->is_end);
      in++;
    }

    tv = tv->h;
  }

  qsort (nv->edges, en, sizeof (int) * 2, cmp_tx);

  nv->en = en;
  nv->is_end = is_end;

  return buff - st;
}

int trie_arr_getc (trie_arr_node *v, CHAR c) {
  int n = v->en;
  if (n > 5) {  // n MUST be > 0
    int l = 0, r = n;

    while (l + 1 < r) {
      int cc = (l + r) / 2;
      if (v->edges[cc * 2 + 1] <= c) {
        l = cc;
      } else {
        r = cc;
      }
    }

    return v->edges[l * 2 + 1] == c ? v->edges[l * 2] : 0;
  }

  int i;

  for (i = 0; i < n; i++) {
    if (v->edges[2 * i + 1] == c) {
      return v->edges[2 * i];
    }
  }
  return 0;
}

void trie_arr_aho (trie_arr_node *st) {
#define maxq 100000
  size_t q[maxq];
  int l = 0, r = 0;

  st->suff = 0;
  q[r++] = 0;

  while (l < r) {
    int dv = q[l++];
    //fprintf (stderr, "dv = %d\n", dv);
    trie_arr_node *v = TSHIFT (st, dv);

    int i;
    for (i = 0; i < v->en; i++) {
      int c = v->edges[2 * i + 1];
      trie_arr_node *nv = TSHIFT (v, v->edges[2 * i]), *p = v;
      q[r++] = v->edges[2 * i] + dv;
      int add = 0;
      do {
        add += p->suff;
        p = TSHIFT (p, p->suff);
      } while (p->suff && !trie_arr_getc (p, c));
      int x = 0;
      if (p != v) {
	      x = trie_arr_getc (p, c);
      }
      nv->suff = -v->edges[2 * i] + add + x;
      nv->is_end |= TSHIFT(nv, nv->suff)->is_end;
    }
  }
#undef maxq
}

int trie_arr_check (trie_arr_node *v, CHAR *s) {
  int res = 0;
  while (*s) {
    while (v->suff && !trie_arr_getc (v, *s)) {
      v = TSHIFT (v, v->suff);
    }
    v = TSHIFT (v, trie_arr_getc (v, *s));
    s++;
    res++;
    if (v->is_end) {
      return res;
    }
  }
  return 0;
}

void trie_print (trie_node *v) {
  static char s[100000];
  static int sn = 0;
  while (v) {
    s[sn++] = v->code;
    if (v->is_end) {
      s[sn] = 0;
      puts (s);
    }
    trie_print (v->v);
    sn--;
    v = v->h;
  }
}

void trie_arr_print (trie_arr_node *v) {
  static char s[100000];
  static int sn = 0;
  int i;
  if (v->is_end) {
    s[sn] = 0;
    puts (s);
  }

  for (i = 0; i < v->en; i++) {
    s[sn++] = v->edges[i * 2 + 1];

    trie_arr_print (TSHIFT(v, v->edges[2 * i]));
    sn--;
  }
}

void trie_arr_text_save (trie_arr_node *v, char *buff, int *bn) {
  static char s[100000];
  static int sn = 0;
  int i;
  if (v->is_end) {
    s[sn] = 0;
    //puts (s);
    for (i = 0; i < sn; i++) {
      buff[(*bn)++] = s[i];
    }
    buff[(*bn)++] = '\t';
  }

  for (i = 0; i < v->en; i++) {
    s[sn++] = v->edges[i * 2 + 1];

    trie_arr_text_save (TSHIFT(v, v->edges[2 * i]), buff, bn);
    sn--;
  }
}

