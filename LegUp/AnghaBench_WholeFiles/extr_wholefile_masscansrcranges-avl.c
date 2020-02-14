#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
struct RavlNode {int height; unsigned int ip_begin; unsigned int ip_end; struct RavlNode* right; struct RavlNode* left; } ;
typedef  int /*<<< orphan*/  (* RAVL_CALLBACK ) (void*,unsigned int,unsigned int) ;

/* Variables and functions */
 struct RavlNode* MALLOC (int) ; 
 int /*<<< orphan*/  free (struct RavlNode*) ; 
 void* max (int,int) ; 

void 
ravl_free(struct RavlNode *node)
{
    if (node != NULL) {
        ravl_free(node->left);
        ravl_free(node->right);
        free(node);
    }
}

__attribute__((used)) static int 
height(const struct RavlNode *node)
{
    if (node == NULL)
        return -1;
    else
        return node->height;
}

__attribute__((used)) static struct RavlNode *
single_rotate_with_left(struct RavlNode* k2)
{
    struct RavlNode* k1 = NULL;
 
    k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
 
    k2->height = max( height( k2->left ), height( k2->right ) ) + 1U;
    k1->height = max( height( k1->left ), k2->height ) + 1U;
    return k1; /* new root */
}

__attribute__((used)) static struct RavlNode *
single_rotate_with_right(struct RavlNode* k1)
{
    struct RavlNode* k2;
 
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
 
    k1->height = max( height( k1->left ), height( k1->right ) ) + 1;
    k2->height = max( height( k2->right ), k1->height ) + 1;
 
    return k2;  /* New root */
}

__attribute__((used)) static struct RavlNode *
double_rotate_with_left(struct RavlNode* k3)
{
    /* Rotate between k1 and k2 */
    k3->left = single_rotate_with_right(k3->left);
 
    /* Rotate between K3 and k2 */
    return single_rotate_with_left(k3);
}

__attribute__((used)) static struct RavlNode *
double_rotate_with_right( struct RavlNode* k1 )
{
    /* rotate between K3 and k2 */
    k1->right = single_rotate_with_left(k1->right);
 
    /* rotate between k1 and k2 */
    return single_rotate_with_right(k1);
}

struct RavlNode * 
ravl_insert(unsigned ip_begin, unsigned ip_end, struct RavlNode *node)
{
    if (node == NULL) {
        node = MALLOC(sizeof(struct RavlNode));
        node->ip_begin = ip_begin;
        node->ip_end = ip_end;
        node->height = 0;
        node->left = node->right = NULL;
    } else if (ip_begin < node->ip_begin) {
        node->left = ravl_insert(ip_begin, ip_end, node->left);
        
        if (height(node->left) - height(node->right) == 2) {
            if (ip_begin < node->left->ip_begin)
                node = single_rotate_with_left(node);
            else
                node = double_rotate_with_left(node);
        }
    } else if (ip_begin > node->ip_begin) {
        node->right = ravl_insert(ip_begin, ip_end, node->right);

        if (height(node->right) - height(node->left) == 2) {
            if (ip_begin > node->right->ip_begin)
                node = single_rotate_with_right(node);
            else
                node = double_rotate_with_right(node);
        }
    } else {
        /* ip_begin == node->ip_begin*/
        ;
    }

    node->height = max( height( node->left ), height( node->right ) ) + 1;

    return node;
}

void
ravl_enumerate(struct RavlNode *node, RAVL_CALLBACK callback_func, void *callback_data)
{
    if (node == NULL)
        return;

    callback_func(callback_data, node->ip_begin, node->ip_end);

    ravl_enumerate(node->left, callback_func, callback_data);
    ravl_enumerate(node->right, callback_func, callback_data);
}

