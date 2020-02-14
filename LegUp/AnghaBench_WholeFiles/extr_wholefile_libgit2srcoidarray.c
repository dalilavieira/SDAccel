#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int count; int /*<<< orphan*/ * ids; } ;
typedef  TYPE_1__ git_oidarray ;
typedef  int /*<<< orphan*/  git_oid ;
struct TYPE_8__ {int size; int /*<<< orphan*/ * ptr; } ;
typedef  TYPE_2__ git_array_oid_t ;

/* Variables and functions */
 int /*<<< orphan*/  git__free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  git_oid_cpy (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

void git_oidarray_free(git_oidarray *arr)
{
	git__free(arr->ids);
}

void git_oidarray__from_array(git_oidarray *arr, git_array_oid_t *array)
{
	arr->count = array->size;
	arr->ids = array->ptr;
}

void git_oidarray__reverse(git_oidarray *arr)
{
	size_t i;
	git_oid tmp;

	for (i = 0; i < arr->count / 2; i++) {
		git_oid_cpy(&tmp, &arr->ids[i]);
		git_oid_cpy(&arr->ids[i], &arr->ids[(arr->count-1)-i]);
		git_oid_cpy(&arr->ids[(arr->count-1)-i], &tmp);
	}
}

