#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_6__ ;
typedef  struct TYPE_18__   TYPE_4__ ;
typedef  struct TYPE_17__   TYPE_3__ ;
typedef  struct TYPE_16__   TYPE_2__ ;
typedef  struct TYPE_15__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  gpointer ;
typedef  int /*<<< orphan*/  gchar ;
typedef  TYPE_4__* gboolean ;
struct TYPE_19__ {int /*<<< orphan*/  value_name; } ;
struct TYPE_17__ {TYPE_2__* dest; } ;
struct TYPE_15__ {int /*<<< orphan*/  title; } ;
struct TYPE_18__ {scalar_t__ type; TYPE_3__ goto_dest; TYPE_1__ any; } ;
struct TYPE_16__ {scalar_t__ type; } ;
typedef  int /*<<< orphan*/  PopplerIndexIter ;
typedef  int /*<<< orphan*/  PopplerDocument ;
typedef  TYPE_4__ PopplerAction ;
typedef  int /*<<< orphan*/  GtkWidget ;
typedef  int /*<<< orphan*/  GtkTreeView ;
typedef  int /*<<< orphan*/  GtkTreeSelection ;
typedef  int /*<<< orphan*/  GtkTreePath ;
typedef  int /*<<< orphan*/  GtkTreeModel ;
typedef  int /*<<< orphan*/  GtkTreeIter ;
typedef  int /*<<< orphan*/  GtkCellRenderer ;
typedef  int /*<<< orphan*/  GWeakNotify ;
typedef  TYPE_6__ GEnumValue ;
typedef  int /*<<< orphan*/  GEnumClass ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  GTK_CONTAINER (int /*<<< orphan*/ *) ; 
 scalar_t__ GTK_IS_TREE_STORE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GTK_LIST_STORE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GTK_PANED (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GTK_POLICY_AUTOMATIC ; 
 int /*<<< orphan*/  GTK_SCROLLED_WINDOW (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  GTK_SELECTION_NONE ; 
 int /*<<< orphan*/ * GTK_TREE_MODEL (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GTK_TREE_STORE (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * GTK_TREE_VIEW (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  G_CALLBACK (void (*) (int /*<<< orphan*/ *,int /*<<< orphan*/ *)) ; 
 int /*<<< orphan*/  G_OBJECT (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  G_TYPE_BOOLEAN ; 
 int /*<<< orphan*/  G_TYPE_POINTER ; 
 int /*<<< orphan*/  G_TYPE_STRING ; 
 int /*<<< orphan*/  N_COLUMNS ; 
 int /*<<< orphan*/  OUTLINE_ACTION_COLUMN ; 
 int /*<<< orphan*/  OUTLINE_ACTION_TYPE_COLUMN ; 
 int /*<<< orphan*/  OUTLINE_EXPAND_COLUMN ; 
 int /*<<< orphan*/  OUTLINE_TITLE_COLUMN ; 
 int /*<<< orphan*/  PANGO_ELLIPSIZE_END ; 
 scalar_t__ POPPLER_ACTION_GOTO_DEST ; 
 scalar_t__ POPPLER_DEST_NAMED ; 
 int /*<<< orphan*/  POPPLER_TYPE_ACTION_TYPE ; 
 int /*<<< orphan*/  TRUE ; 
 TYPE_6__* g_enum_get_value (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  g_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * g_markup_escape_text (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  g_object_set (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_object_unref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_object_weak_ref (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*) ; 
 int /*<<< orphan*/  g_signal_connect (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * g_strdup_printf (char*,char*) ; 
 scalar_t__ g_type_class_ref (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gtk_cell_renderer_text_new () ; 
 int /*<<< orphan*/  gtk_container_add (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * gtk_hpaned_new () ; 
 int /*<<< orphan*/  gtk_list_store_append (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_list_store_new (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gtk_list_store_set (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gtk_paned_add1 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_paned_add2 (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_paned_set_position (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * gtk_scrolled_window_new (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_scrolled_window_set_policy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gtk_tree_model_get (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,TYPE_4__**,int) ; 
 int /*<<< orphan*/ * gtk_tree_model_get_path (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ gtk_tree_model_iter_children (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ gtk_tree_model_iter_next (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_tree_path_free (int /*<<< orphan*/ *) ; 
 scalar_t__ gtk_tree_selection_get_selected (int /*<<< orphan*/ *,int /*<<< orphan*/ **,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_tree_selection_set_mode (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gtk_tree_store_append (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_tree_store_new (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  gtk_tree_store_set (int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_4__*,int /*<<< orphan*/ ,TYPE_4__*,int) ; 
 int /*<<< orphan*/  gtk_tree_view_expand_row (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gtk_tree_view_get_column (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * gtk_tree_view_get_selection (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_tree_view_insert_column_with_attributes (int /*<<< orphan*/ *,int,char*,int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * gtk_tree_view_new_with_model (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_widget_show (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * pgd_action_view_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  pgd_action_view_set_action (int /*<<< orphan*/ *,TYPE_4__*) ; 
 scalar_t__ poppler_action_free ; 
 int /*<<< orphan*/  poppler_index_iter_free (int /*<<< orphan*/ *) ; 
 TYPE_4__* poppler_index_iter_get_action (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * poppler_index_iter_get_child (int /*<<< orphan*/ *) ; 
 TYPE_4__* poppler_index_iter_is_open (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * poppler_index_iter_new (int /*<<< orphan*/ *) ; 
 scalar_t__ poppler_index_iter_next (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
build_tree (PopplerDocument  *document,
	    GtkTreeModel     *model,
	    GtkTreeIter      *parent,
	    PopplerIndexIter *iter)
{

	do {
		GtkTreeIter       tree_iter;
		PopplerIndexIter *child;
		PopplerAction    *action;
		gboolean          expand;
		gchar            *markup;
		GEnumValue       *enum_value;

		action = poppler_index_iter_get_action (iter);
		expand = poppler_index_iter_is_open (iter);

		if (!action)
			continue;

		markup = g_markup_escape_text (action->any.title, -1);
		enum_value = g_enum_get_value ((GEnumClass *) g_type_class_ref (POPPLER_TYPE_ACTION_TYPE), action->type);
		
		if (action->type == POPPLER_ACTION_GOTO_DEST &&
		    action->goto_dest.dest->type == POPPLER_DEST_NAMED) {
			/* TODO */
		}			

		gtk_tree_store_append (GTK_TREE_STORE (model), &tree_iter, parent);
		gtk_tree_store_set (GTK_TREE_STORE (model), &tree_iter,
				    OUTLINE_TITLE_COLUMN, markup,
				    OUTLINE_ACTION_TYPE_COLUMN, enum_value->value_name,
				    OUTLINE_EXPAND_COLUMN, expand,
				    OUTLINE_ACTION_COLUMN, action,
				    -1);
		g_object_weak_ref (G_OBJECT (model),
				   (GWeakNotify)poppler_action_free,
				   action);

		g_free (markup);

		child = poppler_index_iter_get_child (iter);
		if (child)
			build_tree (document, model, &tree_iter, child);
		poppler_index_iter_free (child);
	} while (poppler_index_iter_next (iter));
}

GtkTreeModel *
pgd_outline_create_model (PopplerDocument *document)
{
	GtkTreeModel     *model;
	PopplerIndexIter *iter;

	iter = poppler_index_iter_new (document);
	if (iter) {
		model = GTK_TREE_MODEL (
			gtk_tree_store_new (N_COLUMNS,
					    G_TYPE_STRING, G_TYPE_STRING, 
					    G_TYPE_BOOLEAN, G_TYPE_POINTER));
		build_tree (document, model, NULL, iter);
		poppler_index_iter_free (iter);
	} else {
		GtkTreeIter tree_iter;
		gchar      *markup;
		
		model = GTK_TREE_MODEL (gtk_list_store_new (1, G_TYPE_STRING));
		gtk_list_store_append (GTK_LIST_STORE (model), &tree_iter);
		markup = g_strdup_printf ("<span size=\"larger\" style=\"italic\">%s</span>",
					  "The document doesn't contain outline");
		gtk_list_store_set (GTK_LIST_STORE (model), &tree_iter,
				    0, markup, -1);
		g_free (markup);
	}

	return model;
}

__attribute__((used)) static void
expand_open_links (GtkTreeView  *tree_view,
		   GtkTreeModel *model,
		   GtkTreeIter  *parent)
{
	GtkTreeIter iter;
	gboolean    expand;

	if (gtk_tree_model_iter_children (model, &iter, parent)) {
		do {
			gtk_tree_model_get (model, &iter,
					    OUTLINE_EXPAND_COLUMN, &expand,
					    -1);
			if (expand) {
				GtkTreePath *path;

				path = gtk_tree_model_get_path (model, &iter);
				gtk_tree_view_expand_row (tree_view, path, FALSE);
				gtk_tree_path_free (path);
			}

			expand_open_links (tree_view, model, &iter);
		} while (gtk_tree_model_iter_next (model, &iter));
	}
}

__attribute__((used)) static void
pgd_outline_selection_changed (GtkTreeSelection *treeselection,
			       GtkWidget        *action_view)
{
	GtkTreeModel *model;
	GtkTreeIter   iter;
	
	if (gtk_tree_selection_get_selected (treeselection, &model, &iter)) {
		PopplerAction *action;

		gtk_tree_model_get (model, &iter,
				    OUTLINE_ACTION_COLUMN, &action,
				    -1);
		pgd_action_view_set_action (action_view, action);
	}
}

GtkWidget *
pgd_outline_create_widget (PopplerDocument *document)
{
	GtkWidget        *swindow;
	GtkWidget        *treeview;
	GtkTreeModel     *model;
	GtkCellRenderer  *renderer;
	GtkTreeSelection *selection;
	GtkWidget        *hpaned, *action;

	hpaned = gtk_hpaned_new ();

	action = pgd_action_view_new (document);
	
	swindow = gtk_scrolled_window_new (NULL, NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (swindow),
					GTK_POLICY_AUTOMATIC,
					GTK_POLICY_AUTOMATIC);

	model = pgd_outline_create_model (document);
	treeview = gtk_tree_view_new_with_model (model);
	g_object_unref (model);

	renderer = gtk_cell_renderer_text_new ();
	gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
						     0, "Title",
						     renderer,
						     "markup", OUTLINE_TITLE_COLUMN,
						     NULL);
	g_object_set (G_OBJECT (renderer), "ellipsize", PANGO_ELLIPSIZE_END, NULL);
	g_object_set (G_OBJECT (gtk_tree_view_get_column (GTK_TREE_VIEW (treeview), 0)),
		      "expand", TRUE, NULL);

	if (GTK_IS_TREE_STORE (model)) {
		renderer = gtk_cell_renderer_text_new ();
		gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (treeview),
							     1, "Action Type",
							     renderer,
							     "text", OUTLINE_ACTION_TYPE_COLUMN,
							     NULL);

		expand_open_links (GTK_TREE_VIEW (treeview), model, NULL);

		selection = gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview));
		g_signal_connect (G_OBJECT (selection), "changed",
				  G_CALLBACK (pgd_outline_selection_changed),
				  (gpointer)action);
	} else {
		gtk_tree_selection_set_mode (gtk_tree_view_get_selection (GTK_TREE_VIEW (treeview)),
					     GTK_SELECTION_NONE);
	}

	gtk_container_add (GTK_CONTAINER (swindow), treeview);
	gtk_widget_show (treeview);

	gtk_paned_add1 (GTK_PANED (hpaned), swindow);
	gtk_widget_show (swindow);

	gtk_paned_add2 (GTK_PANED (hpaned), action);
	gtk_widget_show (action);

	gtk_paned_set_position (GTK_PANED (hpaned), 300);

	return hpaned;
}

