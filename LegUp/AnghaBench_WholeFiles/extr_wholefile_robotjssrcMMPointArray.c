#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  point ;
struct TYPE_12__ {size_t _allocedCount; size_t count; struct TYPE_12__* array; } ;
typedef  TYPE_1__* MMPointArrayRef ;
typedef  int /*<<< orphan*/  MMPointArray ;
typedef  TYPE_1__ MMPoint ;

/* Variables and functions */
 TYPE_1__* calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 TYPE_1__* malloc (int) ; 
 TYPE_1__* realloc (TYPE_1__*,int) ; 

MMPointArrayRef createMMPointArray(size_t initialCount)
{
	MMPointArrayRef pointArray = calloc(1, sizeof(MMPointArray));

	if (initialCount == 0) initialCount = 1;

	pointArray->_allocedCount = initialCount;
	pointArray->array = malloc(pointArray->_allocedCount * sizeof(MMPoint));
	if (pointArray->array == NULL) return NULL;

	return pointArray;
}

void destroyMMPointArray(MMPointArrayRef pointArray)
{
	if (pointArray->array != NULL) {
		free(pointArray->array);
		pointArray->array = NULL;
	}

	free(pointArray);
}

void MMPointArrayAppendPoint(MMPointArrayRef pointArray, MMPoint point)
{
	const size_t newCount = ++(pointArray->count);
	if (pointArray->_allocedCount < newCount) {
		do {
			/* Double size each time to avoid calls to realloc(). */
			pointArray->_allocedCount <<= 1;
		} while (pointArray->_allocedCount < newCount);
		pointArray->array = realloc(pointArray->array,
		                            sizeof(point) *
		                            pointArray->_allocedCount);
	}

	pointArray->array[pointArray->count - 1] = point;
}

