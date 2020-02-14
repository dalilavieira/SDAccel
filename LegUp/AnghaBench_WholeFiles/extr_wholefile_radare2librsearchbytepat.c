#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/  str; struct TYPE_7__* next; } ;
typedef  TYPE_1__ fnditem ;

/* Variables and functions */
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 scalar_t__ malloc (int) ; 
 int /*<<< orphan*/  memcmp (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,unsigned char*,int) ; 

__attribute__((used)) static fnditem* init_fi() {
	fnditem* n;
	n = (fnditem*) malloc (sizeof (fnditem));
	if (!n) {
		return NULL;
	}
	n->next = NULL;
	return n;
}

__attribute__((used)) static void fini_fi(fnditem* fi) {
	fnditem *fu;
	fu = fi;
	while (fi->next) {
		fu = fi;
		fi = fi->next;
		free (fu);
		fu = NULL;
	}
	free (fu);
}

__attribute__((used)) static void add_fi (fnditem* n, unsigned char* blk, int patlen) {
	fnditem* p;
	for (p = n; p->next != NULL; p = p->next) {
		;
	}
	p->next = (fnditem*) malloc (sizeof (fnditem));
	p = p->next;
	memcpy (p->str, blk, patlen);
	p->next = NULL;
}

__attribute__((used)) static int is_fi_present(fnditem* n, unsigned char* blk , int patlen) {
	fnditem* p;
	for (p = n; p->next != NULL; p = p->next) {
		if (!memcmp (blk, p->str, patlen)) {
			return true;
		}
	}
	return false;
}

