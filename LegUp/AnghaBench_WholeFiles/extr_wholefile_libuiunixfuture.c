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
typedef  int /*<<< orphan*/  guint16 ;
typedef  int /*<<< orphan*/  gint ;
typedef  int /*<<< orphan*/  gchar ;
typedef  int /*<<< orphan*/  gboolean ;
typedef  int /*<<< orphan*/  PangoAttribute ;
typedef  int /*<<< orphan*/  GtkWidgetPath ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  RTLD_LAZY ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  dlclose (void*) ; 
 void* dlopen (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 void* dlsym (void*,char*) ; 
 int /*<<< orphan*/  gwpIterSetObjectName (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/ * newBGAlphaAttr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * newFGAlphaAttr (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * newFeaturesAttr (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * stub1 (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/ * stub2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * stub3 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*) ; 

void uiprivLoadFutures(void)
{
	void *handle;

	// dlsym() walks the dependency chain, so opening the current process should be sufficient
	handle = dlopen(NULL, RTLD_LAZY);
	if (handle == NULL)
		return;
#define GET(var, fn) *((void **) (&var)) = dlsym(handle, #fn)
	GET(newFeaturesAttr, pango_attr_font_features_new);
	GET(newFGAlphaAttr, pango_attr_foreground_alpha_new);
	GET(newBGAlphaAttr, pango_attr_background_alpha_new);
	GET(gwpIterSetObjectName, gtk_widget_path_iter_set_object_name);
	dlclose(handle);
}

PangoAttribute *uiprivFUTURE_pango_attr_font_features_new(const gchar *features)
{
	if (newFeaturesAttr == NULL)
		return NULL;
	return (*newFeaturesAttr)(features);
}

PangoAttribute *uiprivFUTURE_pango_attr_foreground_alpha_new(guint16 alpha)
{
	if (newFGAlphaAttr == NULL)
		return NULL;
	return (*newFGAlphaAttr)(alpha);
}

PangoAttribute *uiprivFUTURE_pango_attr_background_alpha_new(guint16 alpha)
{
	if (newBGAlphaAttr == NULL)
		return NULL;
	return (*newBGAlphaAttr)(alpha);
}

gboolean uiprivFUTURE_gtk_widget_path_iter_set_object_name(GtkWidgetPath *path, gint pos, const char *name)
{
	if (gwpIterSetObjectName == NULL)
		return FALSE;
	(*gwpIterSetObjectName)(path, pos, name);
	return TRUE;
}

