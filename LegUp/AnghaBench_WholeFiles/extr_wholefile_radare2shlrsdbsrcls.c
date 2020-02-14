#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut32 ;
typedef  scalar_t__ off_t ;
struct TYPE_13__ {TYPE_1__* head; } ;
struct TYPE_12__ {struct TYPE_12__* n; struct TYPE_12__* p; void* data; } ;
typedef  TYPE_1__ SdbListIter ;
typedef  scalar_t__ (* SdbListComparator ) (void*,void*) ;
typedef  TYPE_2__ SdbList ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
 int lseek (int,scalar_t__,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int seek_set(int fd, off_t pos) {
	return ((fd == -1) || (lseek (fd, (off_t) pos, SEEK_SET) == -1))? 0:1;
}

__attribute__((used)) static inline void ut32_pack(char s[4], ut32 u) {
	s[0] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	s[3] = u >> 8;
}

__attribute__((used)) static inline void ut32_pack_big(char s[4], ut32 u) {
	s[3] = u & 255;
	u >>= 8;
	s[2] = u & 255;
	u >>= 8;
	s[1] = u & 255;
	s[0] = u >> 8;
}

__attribute__((used)) static inline void ut32_unpack(char s[4], ut32 *u) {
	ut32 result = 0;
	result = (ut8) s[3];
	result <<= 8;
	result += (ut8) s[2];
	result <<= 8;
	result += (ut8) s[1];
	result <<= 8;
	result += (ut8) s[0];
	*u = result;
}

__attribute__((used)) static void ls_insertion_sort_iter(SdbListIter *iter, SdbListComparator cmp) {
	SdbListIter *it, *it2;
	for (it = iter; it && it->data; it = it->n) {
		for (it2 = it->n; it2 && it2->data; it2 = it2->n) {
			if (cmp (it->data, it2->data) > 0) {
				void *t = it->data;
				it->data = it2->data;
				it2->data = t;
			}
		}
	}
}

__attribute__((used)) static void ls_insertion_sort(SdbList *list, SdbListComparator cmp) {
	ls_insertion_sort_iter (list->head, cmp);
}

__attribute__((used)) static SdbListIter *_merge(SdbListIter *first, SdbListIter *second, SdbListComparator cmp) {
	SdbListIter *next = NULL, *result = NULL, *head = NULL;
	while (first || second) {
		if (!second) {
			next = first;
			first = first->n;
		} else if (!first) {
			next = second;
			second = second->n;
		} else if (cmp (first->data, second->data) < 0) {
			next = first;
			first = first->n;
		} else {
			next = second;
			second = second->n;
		}
		if (!head) {
			result = next;
			head = result;
			head->p = NULL;
		} else {
			result->n = next;
			next->p = result;
			result = result->n;
		}
	}
	head->p = NULL;
	next->n = NULL;
	return head;
}

__attribute__((used)) static SdbListIter * _sdb_list_split(SdbListIter *head) {
	SdbListIter *tmp;
	SdbListIter *fast;
	SdbListIter *slow;
	if (!head || !head->n) {
		return head;
	} 
	slow = head;
	fast = head;
	while (fast && fast->n && fast->n->n) {
		fast = fast->n->n;
		slow = slow->n;
	}
	tmp = slow->n;
	slow->n = NULL;
	return tmp;
}

__attribute__((used)) static SdbListIter * _merge_sort(SdbListIter *head, SdbListComparator cmp) {
	SdbListIter *second;
	if (!head || !head->n) {
		return head;
	}
	second = _sdb_list_split (head);
	head = _merge_sort (head, cmp);
	second = _merge_sort (second, cmp);
	return _merge (head, second, cmp);
}

