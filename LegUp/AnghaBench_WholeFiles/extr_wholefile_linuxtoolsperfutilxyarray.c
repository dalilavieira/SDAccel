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
struct xyarray {void* contents; int row_size; int entry_size; int max_y; int max_x; int entries; } ;

/* Variables and functions */
 void* calloc (int,size_t) ; 
 int /*<<< orphan*/  free (struct xyarray*) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,size_t) ; 

__attribute__((used)) static inline void *xyarray__entry(struct xyarray *xy, int x, int y)
{
	return &xy->contents[x * xy->row_size + y * xy->entry_size];
}

__attribute__((used)) static inline int xyarray__max_y(struct xyarray *xy)
{
	return xy->max_y;
}

__attribute__((used)) static inline int xyarray__max_x(struct xyarray *xy)
{
	return xy->max_x;
}

__attribute__((used)) static inline void *zalloc(size_t size)
{
	return calloc(1, size);
}

struct xyarray *xyarray__new(int xlen, int ylen, size_t entry_size)
{
	size_t row_size = ylen * entry_size;
	struct xyarray *xy = zalloc(sizeof(*xy) + xlen * row_size);

	if (xy != NULL) {
		xy->entry_size = entry_size;
		xy->row_size   = row_size;
		xy->entries    = xlen * ylen;
		xy->max_x      = xlen;
		xy->max_y      = ylen;
	}

	return xy;
}

void xyarray__reset(struct xyarray *xy)
{
	size_t n = xy->entries * xy->entry_size;

	memset(xy->contents, 0, n);
}

void xyarray__delete(struct xyarray *xy)
{
	free(xy);
}

