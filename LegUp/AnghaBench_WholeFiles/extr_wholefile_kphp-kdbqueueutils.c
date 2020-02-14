#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_4__ ;
typedef  struct TYPE_24__   TYPE_3__ ;
typedef  struct TYPE_23__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_1__* treap_node_ptr ;
struct TYPE_23__ {scalar_t__ x; scalar_t__ y; int val; struct TYPE_23__* l; struct TYPE_23__* r; } ;
typedef  TYPE_1__ treap_node ;
struct TYPE_24__ {scalar_t__ size; TYPE_1__* root; } ;
typedef  TYPE_3__ treap ;
struct TYPE_25__ {scalar_t__ x; int y; } ;
typedef  TYPE_4__ pli ;
typedef  scalar_t__ ll ;

/* Variables and functions */
 int allocated_nodes_cnt ; 
 int /*<<< orphan*/  assert (int) ; 
 scalar_t__ dl_get_memory_used () ; 
 TYPE_1__* dl_malloc (int) ; 
 TYPE_1__* free_nodes ; 
 scalar_t__ free_nodes_cnt ; 
 size_t treap_memory ; 

size_t treap_get_memory (void) {
  return treap_memory;
}

void treap_init_mem (int n) {
  assert (free_nodes_cnt == 0);
  assert (n > 0);

  treap_memory -= dl_get_memory_used();
  free_nodes = dl_malloc (sizeof (treap_node) * n);
  assert (free_nodes != NULL);
  treap_memory += dl_get_memory_used();

  allocated_nodes_cnt += n;
  free_nodes_cnt += n;

  int i;
  for (i = 0; i + 1 < n; i++) {
    free_nodes[i].l = &free_nodes[i + 1];
    free_nodes[i].r = NULL;
  }
  free_nodes[n - 1].l = free_nodes[n - 1].r = NULL;
}

void treap_init (treap *tr) {
  tr->size = 0;
  tr->root = NULL;
}

treap_node *get_new_node (void) {
  if (free_nodes_cnt == 0) {
    if (allocated_nodes_cnt < 10000) {
      if (allocated_nodes_cnt < 10) {
        treap_init_mem (10);
      } else {
        treap_init_mem (allocated_nodes_cnt);
      }
    } else {
      treap_init_mem (10000);
    }
  }

  free_nodes_cnt--;
  assert (free_nodes_cnt >= 0);

  treap_node_ptr res = free_nodes;
  free_nodes = free_nodes->l;
  res->l = NULL;

  return res;
}

void treap_split (treap_node_ptr v, ll x, treap_node_ptr *a, treap_node_ptr *b) {
  while (v != NULL) {
    if (v->x > x) {
      *a = v;
      a = &v->r;
      v = v->r;
    } else {
      *b = v;
      b = &v->l;
      v = v->l;
    }
  }
  *a = *b = NULL;
}

void treap_merge (treap_node_ptr *tr, treap_node_ptr a, treap_node_ptr b) {
  while (a != NULL || b != NULL) {
     if (a == NULL || (b != NULL && b->y > a->y)) {
       *tr = b;
       tr = &b->l;
       b = b->l;
     } else {
       *tr = a;
       tr = &a->r;
       a = a->r;
     }
  }
  *tr = NULL;
}

int treap_del (treap *tr, ll x) {
  treap_node_ptr *v = &tr->root;

  while (*v != NULL) {
    if ((*v)->x  == x) {
      treap_node_ptr t = *v;
      treap_merge (v, t->l, t->r);

      t->r = NULL;
      t->l = free_nodes;
      free_nodes = t;
      free_nodes_cnt++;
      tr->size++;

      return t->y;
    } else if ((*v)->x > x) {
      v = &(*v)->r;
    } else if ((*v)->x < x) {
      v = &(*v)->l;
    }
  }
  return 0;
}

void treap_add (treap *tr, ll x, int val, int y) {
  treap_node_ptr *v = &tr->root;

  while (*v != NULL && ((*v)->y >= y)) {
    if ((*v)->x == x) {
      (*v)->val = val;
      return;
    } else if ((*v)->x > x) {
      v = &(*v)->r;
    } else if ((*v)->x < x) {
      v = &(*v)->l;
    }
  }
  treap_node_ptr vv = *v;

  while (vv != NULL) {
    if (vv->x == x) {
      vv->val = val;
      return;
    } else if (vv->x > x) {
      vv = vv->r;
    } else if (vv->x < x) {
      vv = vv->l;
    }
  }

  treap_node_ptr u = get_new_node();
  tr->size--;
  u->x = x;
  u->val = val;
  u->y = y;
  treap_split (*v, x, &u->l, &u->r);
  *v = u;
}

int treap_conv_to_array (treap_node_ptr v, pli *a, int n) {
  if (v == NULL) {
    return 0;
  }
  int ln = treap_conv_to_array (v->l, a, n);
  a += ln;
  n -= ln;
  if (n) {
    a->x = v->x;
    a->y = v->val;
    a++;
    n--;
    ln++;
  }
  ln += treap_conv_to_array (v->r, a, n);
  return ln;
}

treap_node_ptr treap_fnd (treap *t, ll x) {
  treap_node_ptr v = t->root;

  while (v != NULL) {
    if (v->x == x) {
      return v;
    } else if (v->x > x) {
      v = v->r;
    } else if (v->x < x) {
      v = v->l;
    }
  }
  return NULL;
}

void treap_free_dfs (treap_node_ptr v) {
  if (v == NULL) {
    return;
  }
  treap_free_dfs (v->l);
  treap_free_dfs (v->r);
  v->r = NULL;
  v->l = free_nodes;
  free_nodes = v;

  free_nodes_cnt++;
}

void treap_free (treap *t) {
  if (t != NULL) {
    treap_free_dfs (t->root);
    t->root = NULL;
    t->size = -0;
  }
}

