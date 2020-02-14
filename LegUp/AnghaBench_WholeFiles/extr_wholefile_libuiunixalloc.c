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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  void* gpointer ;
struct TYPE_7__ {scalar_t__ len; } ;

/* Variables and functions */
 void* BASE (void*) ; 
 void* DATA (void*) ; 
 scalar_t__ EXTRA ; 
 scalar_t__ FALSE ; 
 size_t* SIZE (void*) ; 
 int /*<<< orphan*/  TRUE ; 
 char const** TYPE (void*) ; 
 TYPE_1__* allocations ; 
 int /*<<< orphan*/  g_free (void*) ; 
 void* g_malloc0 (scalar_t__) ; 
 int /*<<< orphan*/  g_ptr_array_add (TYPE_1__*,void*) ; 
 int /*<<< orphan*/  g_ptr_array_foreach (TYPE_1__*,void (*) (void*,void*),char**) ; 
 int /*<<< orphan*/  g_ptr_array_free (TYPE_1__*,int /*<<< orphan*/ ) ; 
 TYPE_1__* g_ptr_array_new () ; 
 scalar_t__ g_ptr_array_remove (TYPE_1__*,void*) ; 
 void* g_realloc (void*,scalar_t__) ; 
 char* g_strdup_printf (char*,...) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,size_t) ; 
 int /*<<< orphan*/  uiprivImplBug (char*,...) ; 
 int /*<<< orphan*/  uiprivUserBug (char*,char*) ; 

void uiprivInitAlloc(void)
{
	allocations = g_ptr_array_new();
}

__attribute__((used)) static void uninitComplain(gpointer ptr, gpointer data)
{
	char **str = (char **) data;
	char *str2;

	if (*str == NULL)
		*str = g_strdup_printf("");
	str2 = g_strdup_printf("%s%p %s\n", *str, ptr, *TYPE(ptr));
	g_free(*str);
	*str = str2;
}

void uiprivUninitAlloc(void)
{
	char *str = NULL;

	if (allocations->len == 0) {
		g_ptr_array_free(allocations, TRUE);
		return;
	}
	g_ptr_array_foreach(allocations, uninitComplain, &str);
	uiprivUserBug("Some data was leaked; either you left a uiControl lying around or there's a bug in libui itself. Leaked data:\n%s", str);
	g_free(str);
}

void *uiprivAlloc(size_t size, const char *type)
{
	void *out;

	out = g_malloc0(EXTRA + size);
	*SIZE(out) = size;
	*TYPE(out) = type;
	g_ptr_array_add(allocations, out);
	return DATA(out);
}

void *uiprivRealloc(void *p, size_t new, const char *type)
{
	void *out;
	size_t *s;

	if (p == NULL)
		return uiprivAlloc(new, type);
	p = BASE(p);
	out = g_realloc(p, EXTRA + new);
	s = SIZE(out);
	if (new > *s)
		memset(((uint8_t *) DATA(out)) + *s, 0, new - *s);
	*s = new;
	if (g_ptr_array_remove(allocations, p) == FALSE)
		uiprivImplBug("%p not found in allocations array in uiprivRealloc()", p);
	g_ptr_array_add(allocations, out);
	return DATA(out);
}

void uiprivFree(void *p)
{
	if (p == NULL)
		uiprivImplBug("attempt to uiprivFree(NULL)");
	p = BASE(p);
	g_free(p);
	if (g_ptr_array_remove(allocations, p) == FALSE)
		uiprivImplBug("%p not found in allocations array in uiprivFree()", p);
}

