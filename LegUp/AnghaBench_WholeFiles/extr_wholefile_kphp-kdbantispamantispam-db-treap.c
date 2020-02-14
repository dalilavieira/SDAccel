#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  trie_node_t ;
struct TYPE_15__ {int x; int y; int /*<<< orphan*/ * data; struct TYPE_15__* right; struct TYPE_15__* left; } ;
typedef  TYPE_1__ tree_t ;

/* Variables and functions */
 int /*<<< orphan*/  assert (TYPE_1__*) ; 
 int lrand48 () ; 
 int /*<<< orphan*/  zfree (TYPE_1__*,int) ; 
 TYPE_1__* zmalloc (int) ; 

__attribute__((used)) static tree_t *new_tree_node (int x, int y) {
  tree_t *p = zmalloc (sizeof (tree_t));
  p->left = p->right = 0;
  p->x = x;
  p->y = y;
  return p;
}

__attribute__((used)) static void tree_split_sk (tree_t **L, tree_t **R, tree_t *T, int x) {
  while (T) {
    if (x < T->x) {
      *R = T;
      R = &T->left;
      T = *R;
    } else {
      *L = T;
      L = &T->right;
      T = *L;
    }
  }
  *L = *R = 0;
}

__attribute__((used)) static tree_t *tree_merge_sk (tree_t *L, tree_t *R) {
  tree_t *res, **t = &res;
  if (!L) {
    return R;
  }
  if (!R) {
    return L;
  }

  while (1) {
    if (L->y > R->y) {
      *t = L;
      t = &L->right;
      L = *t;
      if (!L) {
        *t = R;
        return res;
      }
    } else {
      *t = R;
      t = &R->left;
      R = *t;
      if (!R) {
        *t = L;
        return res;
      }
    }
  }
}

void tree_insert_sk (tree_t **V, int x, trie_node_t *v) {
  tree_t *P;
  int y = lrand48();
  while (*V && (*V)->y >= y) {
    V = (x < (*V)->x ? &(*V)->left : &(*V)->right);
  }
  P = new_tree_node (x, y);
  P->data = v;
  tree_split_sk (&P->left, &P->right, *V, x);
  *V = P;
}

trie_node_t *tree_delete_sk (tree_t **V, int x) {
  tree_t *P;
  trie_node_t *res = 0;
  while (*V && (*V)->x != x)
    V = (x < (*V)->x ? &(*V)->left : &(*V)->right);
  assert (*V);

  P = tree_merge_sk ((*V)->left, (*V)->right);
  res = (*V)->data;
  zfree (*V, sizeof (tree_t));
  *V = P;
  return res;
}

trie_node_t *tree_find_sk (tree_t *V, int x) {
  while (V && V->x != x) {
    V = (V->x > x ? V->left : V->right);
  }
  return V ? V->data : 0;
}

