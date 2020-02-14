#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {struct rb_node* rb_node; } ;
struct rblist {scalar_t__ nr_entries; int (* node_cmp ) (struct rb_node*,void const*) ;TYPE_1__ entries; struct rb_node* (* node_new ) (struct rblist*,void const*) ;int /*<<< orphan*/  (* node_delete ) (struct rblist*,struct rb_node*) ;} ;
struct rb_node {struct rb_node* rb_right; struct rb_node* rb_left; } ;

/* Variables and functions */
 int EEXIST ; 
 int ENOMEM ; 
 TYPE_1__ RB_ROOT ; 
 int /*<<< orphan*/  free (struct rblist*) ; 
 int /*<<< orphan*/  rb_erase (struct rb_node*,TYPE_1__*) ; 
 struct rb_node* rb_first (TYPE_1__*) ; 
 int /*<<< orphan*/  rb_insert_color (struct rb_node*,TYPE_1__*) ; 
 int /*<<< orphan*/  rb_link_node (struct rb_node*,struct rb_node*,struct rb_node**) ; 
 struct rb_node* rb_next (struct rb_node*) ; 
 int stub1 (struct rb_node*,void const*) ; 
 struct rb_node* stub2 (struct rblist*,void const*) ; 
 int /*<<< orphan*/  stub3 (struct rblist*,struct rb_node*) ; 
 int stub4 (struct rb_node*,void const*) ; 
 struct rb_node* stub5 (struct rblist*,void const*) ; 

__attribute__((used)) static inline bool rblist__empty(const struct rblist *rblist)
{
	return rblist->nr_entries == 0;
}

__attribute__((used)) static inline unsigned int rblist__nr_entries(const struct rblist *rblist)
{
	return rblist->nr_entries;
}

int rblist__add_node(struct rblist *rblist, const void *new_entry)
{
	struct rb_node **p = &rblist->entries.rb_node;
	struct rb_node *parent = NULL, *new_node;

	while (*p != NULL) {
		int rc;

		parent = *p;

		rc = rblist->node_cmp(parent, new_entry);
		if (rc > 0)
			p = &(*p)->rb_left;
		else if (rc < 0)
			p = &(*p)->rb_right;
		else
			return -EEXIST;
	}

	new_node = rblist->node_new(rblist, new_entry);
	if (new_node == NULL)
		return -ENOMEM;

	rb_link_node(new_node, parent, p);
	rb_insert_color(new_node, &rblist->entries);
	++rblist->nr_entries;

	return 0;
}

void rblist__remove_node(struct rblist *rblist, struct rb_node *rb_node)
{
	rb_erase(rb_node, &rblist->entries);
	--rblist->nr_entries;
	rblist->node_delete(rblist, rb_node);
}

__attribute__((used)) static struct rb_node *__rblist__findnew(struct rblist *rblist,
					 const void *entry,
					 bool create)
{
	struct rb_node **p = &rblist->entries.rb_node;
	struct rb_node *parent = NULL, *new_node = NULL;

	while (*p != NULL) {
		int rc;

		parent = *p;

		rc = rblist->node_cmp(parent, entry);
		if (rc > 0)
			p = &(*p)->rb_left;
		else if (rc < 0)
			p = &(*p)->rb_right;
		else
			return parent;
	}

	if (create) {
		new_node = rblist->node_new(rblist, entry);
		if (new_node) {
			rb_link_node(new_node, parent, p);
			rb_insert_color(new_node, &rblist->entries);
			++rblist->nr_entries;
		}
	}

	return new_node;
}

struct rb_node *rblist__find(struct rblist *rblist, const void *entry)
{
	return __rblist__findnew(rblist, entry, false);
}

struct rb_node *rblist__findnew(struct rblist *rblist, const void *entry)
{
	return __rblist__findnew(rblist, entry, true);
}

void rblist__init(struct rblist *rblist)
{
	if (rblist != NULL) {
		rblist->entries	 = RB_ROOT;
		rblist->nr_entries = 0;
	}

	return;
}

void rblist__exit(struct rblist *rblist)
{
	struct rb_node *pos, *next = rb_first(&rblist->entries);

	while (next) {
		pos = next;
		next = rb_next(pos);
		rblist__remove_node(rblist, pos);
	}
}

void rblist__delete(struct rblist *rblist)
{
	if (rblist != NULL) {
		rblist__exit(rblist);
		free(rblist);
	}
}

struct rb_node *rblist__entry(const struct rblist *rblist, unsigned int idx)
{
	struct rb_node *node;

	for (node = rb_first(&rblist->entries); node; node = rb_next(node)) {
		if (!idx--)
			return node;
	}

	return NULL;
}

