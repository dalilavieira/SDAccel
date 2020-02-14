#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_86__   TYPE_9__ ;
typedef  struct TYPE_85__   TYPE_8__ ;
typedef  struct TYPE_84__   TYPE_7__ ;
typedef  struct TYPE_83__   TYPE_6__ ;
typedef  struct TYPE_82__   TYPE_5__ ;
typedef  struct TYPE_81__   TYPE_4__ ;
typedef  struct TYPE_80__   TYPE_3__ ;
typedef  struct TYPE_79__   TYPE_2__ ;
typedef  struct TYPE_78__   TYPE_1__ ;
typedef  struct TYPE_77__   TYPE_18__ ;
typedef  struct TYPE_76__   TYPE_15__ ;
typedef  struct TYPE_75__   TYPE_14__ ;
typedef  struct TYPE_74__   TYPE_13__ ;
typedef  struct TYPE_73__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ time_t ;
struct tm {int dummy; } ;
typedef  int /*<<< orphan*/  s ;
typedef  int /*<<< orphan*/  gsize ;
typedef  int /*<<< orphan*/  gpointer ;
typedef  int gint ;
typedef  char gchar ;
typedef  int gboolean ;
struct TYPE_86__ {TYPE_10__* state_list; } ;
struct TYPE_85__ {int op; TYPE_10__* media; } ;
struct TYPE_84__ {int operation; TYPE_10__* movie; } ;
struct TYPE_83__ {char* named_dest; } ;
struct TYPE_82__ {char* uri; } ;
struct TYPE_81__ {char* file_name; char* params; } ;
struct TYPE_80__ {char* file_name; TYPE_13__* dest; } ;
struct TYPE_79__ {TYPE_13__* dest; } ;
struct TYPE_78__ {char* title; } ;
struct TYPE_77__ {char* value_name; } ;
struct TYPE_76__ {int type; TYPE_9__ ocg_state; TYPE_8__ rendition; TYPE_7__ movie; TYPE_6__ named; TYPE_5__ uri; TYPE_4__ launch; TYPE_3__ goto_remote; TYPE_2__ goto_dest; TYPE_1__ any; } ;
struct TYPE_75__ {int action; TYPE_10__* layers; } ;
struct TYPE_74__ {scalar_t__ type; int page_num; int left; int right; int top; int bottom; int zoom; char* named_dest; } ;
struct TYPE_73__ {scalar_t__ data; } ;
typedef  TYPE_10__ PopplerPage ;
typedef  TYPE_10__ PopplerMovie ;
typedef  TYPE_10__ PopplerMedia ;
typedef  int /*<<< orphan*/  PopplerLayer ;
typedef  int /*<<< orphan*/  PopplerDocument ;
typedef  TYPE_13__ PopplerDest ;
typedef  int PopplerActionMovieOperation ;
typedef  TYPE_14__ PopplerActionLayer ;
typedef  TYPE_15__ PopplerAction ;
typedef  TYPE_10__ GtkWidget ;
typedef  int /*<<< orphan*/  GtkTable ;
typedef  TYPE_10__ GList ;
typedef  int /*<<< orphan*/  GFile ;
typedef  int /*<<< orphan*/  GError ;
typedef  TYPE_18__ GEnumValue ;
typedef  int /*<<< orphan*/  GEnumClass ;
typedef  int /*<<< orphan*/  GDestroyNotify ;

/* Variables and functions */
 int FALSE ; 
 int /*<<< orphan*/  GDK_CURRENT_TIME ; 
 int /*<<< orphan*/  GINT_TO_POINTER (int) ; 
 int GPOINTER_TO_INT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  GTK_ALIGNMENT (TYPE_10__*) ; 
 int /*<<< orphan*/  GTK_BIN (TYPE_10__*) ; 
 int /*<<< orphan*/  GTK_CONTAINER (TYPE_10__*) ; 
 int /*<<< orphan*/  GTK_FRAME (TYPE_10__*) ; 
 int /*<<< orphan*/  GTK_LABEL (TYPE_10__*) ; 
 int /*<<< orphan*/  GTK_SHADOW_NONE ; 
 int /*<<< orphan*/  GTK_STOCK_MEDIA_PLAY ; 
 int /*<<< orphan*/ * GTK_TABLE (TYPE_10__*) ; 
 int /*<<< orphan*/  G_CALLBACK (void (*) (TYPE_10__*,TYPE_10__*)) ; 
 int /*<<< orphan*/  G_OBJECT (TYPE_10__*) ; 
 int /*<<< orphan*/  MAX (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  PANGO_ELLIPSIZE_END ; 
#define  POPPLER_ACTION_GOTO_DEST 144 
#define  POPPLER_ACTION_GOTO_REMOTE 143 
#define  POPPLER_ACTION_LAUNCH 142 
#define  POPPLER_ACTION_LAYER_OFF 141 
#define  POPPLER_ACTION_LAYER_ON 140 
#define  POPPLER_ACTION_LAYER_TOGGLE 139 
#define  POPPLER_ACTION_MOVIE 138 
#define  POPPLER_ACTION_MOVIE_PAUSE 137 
#define  POPPLER_ACTION_MOVIE_PLAY 136 
#define  POPPLER_ACTION_MOVIE_RESUME 135 
#define  POPPLER_ACTION_MOVIE_STOP 134 
#define  POPPLER_ACTION_NAMED 133 
#define  POPPLER_ACTION_NONE 132 
#define  POPPLER_ACTION_OCG_STATE 131 
#define  POPPLER_ACTION_RENDITION 130 
#define  POPPLER_ACTION_UNKNOWN 129 
#define  POPPLER_ACTION_URI 128 
 scalar_t__ POPPLER_DEST_NAMED ; 
 int /*<<< orphan*/  POPPLER_TYPE_DEST_TYPE ; 
 int TRUE ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  g_assert_not_reached () ; 
 char* g_build_filename (char*,char const*,int /*<<< orphan*/ *) ; 
 TYPE_18__* g_enum_get_value (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  g_file_delete (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 char* g_file_get_uri (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * g_file_new_for_path (char const*) ; 
 int /*<<< orphan*/ * g_file_new_for_uri (char const*) ; 
 int g_file_open_tmp (int /*<<< orphan*/ *,char**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_free (char*) ; 
 char* g_get_current_dir () ; 
 int g_list_length (TYPE_10__*) ; 
 TYPE_10__* g_list_next (TYPE_10__*) ; 
 char* g_locale_to_utf8 (char*,int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_object_get (int /*<<< orphan*/ ,char*,char**,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * g_object_get_data (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  g_object_ref (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_object_set (int /*<<< orphan*/ ,char*,double,char*,int,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_object_set_data (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_object_set_data_full (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  g_object_unref (int /*<<< orphan*/ *) ; 
 scalar_t__ g_path_is_absolute (char const*) ; 
 int /*<<< orphan*/  g_signal_connect (TYPE_10__*,char*,int /*<<< orphan*/ ,TYPE_10__*) ; 
 char* g_strdup_printf (char*,int,...) ; 
 scalar_t__ g_strrstr (char const*,char*) ; 
 scalar_t__ g_type_class_ref (int /*<<< orphan*/ ) ; 
 TYPE_10__* gtk_alignment_new (double,double,int,int) ; 
 int /*<<< orphan*/  gtk_alignment_set_padding (int /*<<< orphan*/ ,int,int,int,int) ; 
 TYPE_10__* gtk_bin_get_child (int /*<<< orphan*/ ) ; 
 TYPE_10__* gtk_button_new_from_stock (int /*<<< orphan*/ ) ; 
 TYPE_10__* gtk_button_new_with_label (char*) ; 
 int /*<<< orphan*/  gtk_container_add (int /*<<< orphan*/ ,TYPE_10__*) ; 
 int /*<<< orphan*/  gtk_container_remove (int /*<<< orphan*/ ,TYPE_10__*) ; 
 TYPE_10__* gtk_frame_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_frame_set_label_widget (int /*<<< orphan*/ ,TYPE_10__*) ; 
 int /*<<< orphan*/  gtk_frame_set_shadow_type (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_10__* gtk_label_new (char const*) ; 
 int /*<<< orphan*/  gtk_label_set_markup (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gtk_show_uri (int /*<<< orphan*/ ,char*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gtk_table_attach_defaults (int /*<<< orphan*/ *,TYPE_10__*,int /*<<< orphan*/ ,int,int,int) ; 
 TYPE_10__* gtk_table_new (int,int,int) ; 
 int /*<<< orphan*/  gtk_table_set_col_spacings (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gtk_table_set_row_spacings (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  gtk_widget_get_screen (TYPE_10__*) ; 
 int /*<<< orphan*/  gtk_widget_show (TYPE_10__*) ; 
 struct tm* localtime (scalar_t__*) ; 
 TYPE_10__* pgd_movie_view_new () ; 
 void pgd_movie_view_set_movie (TYPE_10__*,TYPE_10__*) ; 
 int /*<<< orphan*/  pgd_table_add_property_with_custom_widget (int /*<<< orphan*/ *,char const*,TYPE_10__*,int*) ; 
 int /*<<< orphan*/  poppler_dest_free (TYPE_13__*) ; 
 TYPE_13__* poppler_document_find_dest (int /*<<< orphan*/ *,char*) ; 
 TYPE_10__* poppler_document_get_page (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  poppler_layer_hide (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  poppler_layer_is_visible (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  poppler_layer_show (int /*<<< orphan*/ *) ; 
 char* poppler_media_get_filename (TYPE_10__*) ; 
 char* poppler_media_get_mime_type (TYPE_10__*) ; 
 int poppler_media_is_embedded (TYPE_10__*) ; 
 scalar_t__ poppler_media_save_to_callback (TYPE_10__*,int (*) (char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ **),int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 char* poppler_movie_get_filename (TYPE_10__*) ; 
 scalar_t__ poppler_movie_need_poster (TYPE_10__*) ; 
 scalar_t__ poppler_movie_show_controls (TYPE_10__*) ; 
 size_t strftime (char*,int,char const*,struct tm*) ; 
 int /*<<< orphan*/  write (int,char const*,int /*<<< orphan*/ ) ; 

void
pgd_table_add_property_with_value_widget (GtkTable    *table,
					  const gchar *markup,
					  GtkWidget  **value_widget,
					  const gchar *value,
					  gint        *row)
{
	GtkWidget *label;

	*value_widget = label = gtk_label_new (value);
	g_object_set (G_OBJECT (label),
		      "xalign", 0.0,
		      "selectable", TRUE,
		      "ellipsize", PANGO_ELLIPSIZE_END,
		      NULL);
	pgd_table_add_property_with_custom_widget (table, markup, label, row);
}

void
pgd_table_add_property (GtkTable    *table,
			const gchar *markup,
			const gchar *value,
			gint        *row)
{
	GtkWidget *label;

	pgd_table_add_property_with_value_widget (table, markup, &label, value, row);
}

GtkWidget *
pgd_action_view_new (PopplerDocument *document)
{
	GtkWidget  *frame, *label;

	frame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_NONE);
	label = gtk_label_new (NULL);
	gtk_label_set_markup (GTK_LABEL (label), "<b>Action Properties</b>");
	gtk_frame_set_label_widget (GTK_FRAME (frame), label);
	gtk_widget_show (label);

	g_object_set_data (G_OBJECT (frame), "document", document);

	return frame;
}

__attribute__((used)) static void
pgd_action_view_add_destination (GtkWidget   *action_view,
				 GtkTable    *table,
				 PopplerDest *dest,
				 gboolean     remote,
				 gint        *row)
{
	PopplerDocument *document;
	GEnumValue      *enum_value;
	gchar           *str;
	
	pgd_table_add_property (table, "<b>Type:</b>", "Destination", row);
	
	enum_value = g_enum_get_value ((GEnumClass *) g_type_class_ref (POPPLER_TYPE_DEST_TYPE), dest->type);
	pgd_table_add_property (table, "<b>Destination Type:</b>", enum_value->value_name, row);

	document = g_object_get_data (G_OBJECT (action_view), "document");
	
	if (dest->type != POPPLER_DEST_NAMED) {
		str = NULL;
		
		if (document && !remote) {
			PopplerPage *poppler_page;
			gchar       *page_label;
			
			poppler_page = poppler_document_get_page (document, MAX (0, dest->page_num - 1));
			
			g_object_get (G_OBJECT (poppler_page),
				      "label", &page_label,
				      NULL);
			if (page_label) {
				str = g_strdup_printf ("%d (%s)", dest->page_num, page_label);
				g_free (page_label);
			}
		}
		
		if (!str)
			str = g_strdup_printf ("%d", dest->page_num);
		pgd_table_add_property (table, "<b>Page:</b>", str, row);
		g_free (str);
		
		str = g_strdup_printf ("%.2f", dest->left);
		pgd_table_add_property (table, "<b>Left:</b>", str, row);
		g_free (str);
		
		str = g_strdup_printf ("%.2f", dest->right);
		pgd_table_add_property (table, "<b>Right:</b>", str, row);
		g_free (str);
		
		str = g_strdup_printf ("%.2f", dest->top);
		pgd_table_add_property (table, "<b>Top:</b>", str, row);
		g_free (str);
	
		str = g_strdup_printf ("%.2f", dest->bottom);
		pgd_table_add_property (table, "<b>Bottom:</b>", str, row);
		g_free (str);
	
		str = g_strdup_printf ("%.2f", dest->zoom);
		pgd_table_add_property (table, "<b>Zoom:</b>", str, row);
		g_free (str);
	} else {
		pgd_table_add_property (table, "<b>Named Dest:</b>", dest->named_dest, row);

		if (document && !remote) {
			PopplerDest *new_dest;

			new_dest = poppler_document_find_dest (document, dest->named_dest);
			if (new_dest) {
				GtkWidget *new_table, *alignment;
				gint       new_row = 0;

				alignment = gtk_alignment_new (0.5, 0.5, 1, 1);
				gtk_alignment_set_padding (GTK_ALIGNMENT (alignment), 5, 5, 12, 5);
				
				new_table = gtk_table_new (8, 2, FALSE);
				gtk_table_set_col_spacings (GTK_TABLE (new_table), 6);
				gtk_table_set_row_spacings (GTK_TABLE (new_table), 6);
				gtk_table_attach_defaults (table, alignment, 0, 2, *row, *row + 1);
				gtk_widget_show (alignment);
				
				pgd_action_view_add_destination (action_view, GTK_TABLE (new_table),
								 new_dest, FALSE, &new_row);
				poppler_dest_free (new_dest);

				gtk_container_add (GTK_CONTAINER (alignment), new_table);
				gtk_widget_show (new_table);

				*row += 1;
			}
		}
	}
}

__attribute__((used)) static const gchar *
get_movie_op (PopplerActionMovieOperation op)
{
	switch (op) {
	case POPPLER_ACTION_MOVIE_PLAY:
		return "Play";
	case POPPLER_ACTION_MOVIE_PAUSE:
		return "Pause";
	case POPPLER_ACTION_MOVIE_RESUME:
		return "Resume";
	case POPPLER_ACTION_MOVIE_STOP:
		return "Stop";
	}
	return NULL;
}

__attribute__((used)) static void
free_tmp_file (GFile *tmp_file)
{

	g_file_delete (tmp_file, NULL, NULL);
	g_object_unref (tmp_file);
}

__attribute__((used)) static gboolean
save_helper (const gchar  *buf,
	     gsize         count,
	     gpointer      data,
	     GError      **error)
{
	gint fd = GPOINTER_TO_INT (data);

	return write (fd, buf, count) == count;
}

__attribute__((used)) static void
pgd_action_view_play_rendition (GtkWidget    *button,
				PopplerMedia *media)
{
	GFile *file = NULL;
	gchar *uri;

	if (poppler_media_is_embedded (media)) {
		gint   fd;
		gchar *tmp_filename = NULL;

		fd = g_file_open_tmp (NULL, &tmp_filename, NULL);
		if (fd != -1) {
			if (poppler_media_save_to_callback (media, save_helper, GINT_TO_POINTER (fd), NULL)) {
				file = g_file_new_for_path (tmp_filename);
				g_object_set_data_full (G_OBJECT (media),
							"tmp-file", g_object_ref (file),
							(GDestroyNotify)free_tmp_file);
			} else {
				g_free (tmp_filename);
			}
			close (fd);
		} else if (tmp_filename) {
			g_free (tmp_filename);
		}

	} else {
		const gchar *filename;

		filename = poppler_media_get_filename (media);
		if (g_path_is_absolute (filename)) {
			file = g_file_new_for_path (filename);
		} else if (g_strrstr (filename, "://")) {
			file = g_file_new_for_uri (filename);
		} else {
			gchar *cwd;
			gchar *path;

			// FIXME: relative to doc uri, not cwd
			cwd = g_get_current_dir ();
			path = g_build_filename (cwd, filename, NULL);
			g_free (cwd);

			file = g_file_new_for_path (path);
			g_free (path);
		}
	}

	if (file) {
		uri = g_file_get_uri (file);
		g_object_unref (file);
		if (uri) {
			gtk_show_uri (gtk_widget_get_screen (button),
				      uri, GDK_CURRENT_TIME, NULL);
			g_free (uri);
		}
	}
}

__attribute__((used)) static void
pgd_action_view_do_action_layer (GtkWidget *button,
				 GList     *state_list)
{
	GList *l, *m;

	for (l = state_list; l; l = g_list_next (l)) {
		PopplerActionLayer *action_layer = (PopplerActionLayer *)l->data;

		for (m = action_layer->layers; m; m = g_list_next (m)) {
			PopplerLayer *layer = (PopplerLayer *)m->data;

			switch (action_layer->action) {
			case POPPLER_ACTION_LAYER_ON:
				poppler_layer_show (layer);
				break;
			case POPPLER_ACTION_LAYER_OFF:
				poppler_layer_hide (layer);
				break;
			case POPPLER_ACTION_LAYER_TOGGLE:
				if (poppler_layer_is_visible (layer))
					poppler_layer_hide (layer);
				else
					poppler_layer_show (layer);
				break;
			}
		}
	}
}

void
pgd_action_view_set_action (GtkWidget     *action_view,
			    PopplerAction *action)
{
	GtkWidget  *alignment;
	GtkWidget  *table;
	gint        row = 0;

	alignment = gtk_bin_get_child (GTK_BIN (action_view));
	if (alignment) {
		gtk_container_remove (GTK_CONTAINER (action_view), alignment);
	}
	
	alignment = gtk_alignment_new (0.5, 0.5, 1, 1);
	gtk_alignment_set_padding (GTK_ALIGNMENT (alignment), 5, 5, 12, 5);
	gtk_container_add (GTK_CONTAINER (action_view), alignment);
	gtk_widget_show (alignment);

	if (!action)
		return;

	table = gtk_table_new (10, 2, FALSE);
	gtk_table_set_col_spacings (GTK_TABLE (table), 6);
	gtk_table_set_row_spacings (GTK_TABLE (table), 6);

	pgd_table_add_property (GTK_TABLE (table), "<b>Title:</b>", action->any.title, &row);
	
	switch (action->type) {
	case POPPLER_ACTION_UNKNOWN:
		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "Unknown", &row);
		break;
	case POPPLER_ACTION_NONE:
		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "None", &row);
		break;
	case POPPLER_ACTION_GOTO_DEST:
		pgd_action_view_add_destination (action_view, GTK_TABLE (table), action->goto_dest.dest, FALSE, &row);
		break;
	case POPPLER_ACTION_GOTO_REMOTE:
		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "Remote Destination", &row);
		pgd_table_add_property (GTK_TABLE (table), "<b>Filename:</b>", action->goto_remote.file_name, &row);
		pgd_action_view_add_destination (action_view, GTK_TABLE (table), action->goto_remote.dest, TRUE, &row);
		break;
	case POPPLER_ACTION_LAUNCH:
		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "Launch", &row);
		pgd_table_add_property (GTK_TABLE (table), "<b>Filename:</b>", action->launch.file_name, &row);
		pgd_table_add_property (GTK_TABLE (table), "<b>Params:</b>", action->launch.params, &row);
		break;
	case POPPLER_ACTION_URI:
		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "External URI", &row);
		pgd_table_add_property (GTK_TABLE (table), "<b>URI</b>", action->uri.uri, &row);
		break;
	case POPPLER_ACTION_NAMED:
		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "Named Action", &row);
		pgd_table_add_property (GTK_TABLE (table), "<b>Name:</b>", action->named.named_dest, &row);
		break;
	case POPPLER_ACTION_MOVIE: {
		GtkWidget *movie_view = pgd_movie_view_new ();

		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "Movie", &row);
		pgd_table_add_property (GTK_TABLE (table), "<b>Operation:</b>", get_movie_op (action->movie.operation), &row);
		pgd_movie_view_set_movie (movie_view, action->movie.movie);
		pgd_table_add_property_with_custom_widget (GTK_TABLE (table), "<b>Movie:</b>", movie_view, &row);
	}
		break;
	case POPPLER_ACTION_RENDITION: {
		gchar *text;

		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "Rendition", &row);
		text = g_strdup_printf ("%d", action->rendition.op);
		pgd_table_add_property (GTK_TABLE (table), "<b>Operation:</b>", text, &row);
		g_free (text);
		if (action->rendition.media) {
			gboolean   embedded = poppler_media_is_embedded (action->rendition.media);
			GtkWidget *button;

			pgd_table_add_property (GTK_TABLE (table), "<b>Embedded:</b>", embedded ? "Yes": "No", &row);
			if (embedded) {
				const gchar *mime_type = poppler_media_get_mime_type (action->rendition.media);
				pgd_table_add_property (GTK_TABLE (table), "<b>Mime type:</b>",
							mime_type ? mime_type : "",
							&row);
			} else {
				pgd_table_add_property (GTK_TABLE (table), "<b>Filename:</b>",
							poppler_media_get_filename (action->rendition.media),
							&row);
			}

			button = gtk_button_new_from_stock (GTK_STOCK_MEDIA_PLAY);
			g_signal_connect (button, "clicked",
					  G_CALLBACK (pgd_action_view_play_rendition),
					  action->rendition.media);
			pgd_table_add_property_with_custom_widget (GTK_TABLE (table), NULL, button, &row);
			gtk_widget_show (button);
		}
	}
		break;
	case POPPLER_ACTION_OCG_STATE: {
		GList     *l;
		GtkWidget *button;

		pgd_table_add_property (GTK_TABLE (table), "<b>Type:</b>", "OCGState", &row);

		for (l = action->ocg_state.state_list; l; l = g_list_next (l)) {
			PopplerActionLayer *action_layer = (PopplerActionLayer *)l->data;
			gchar *text;
			gint   n_layers = g_list_length (action_layer->layers);

			switch (action_layer->action) {
			case POPPLER_ACTION_LAYER_ON:
				text = g_strdup_printf ("%d layers On", n_layers);
				break;
			case POPPLER_ACTION_LAYER_OFF:
				text = g_strdup_printf ("%d layers Off", n_layers);
				break;
			case POPPLER_ACTION_LAYER_TOGGLE:
				text = g_strdup_printf ("%d layers Toggle", n_layers);
				break;
			}
			pgd_table_add_property (GTK_TABLE (table), "<b>Action:</b>", text, &row);
			g_free (text);
		}

		button = gtk_button_new_with_label ("Do action");
		g_signal_connect (button, "clicked",
				  G_CALLBACK (pgd_action_view_do_action_layer),
				  action->ocg_state.state_list);
		pgd_table_add_property_with_custom_widget (GTK_TABLE (table), NULL, button, &row);
		gtk_widget_show (button);
	}
		break;
	default:
		g_assert_not_reached ();
	}

	gtk_container_add (GTK_CONTAINER (alignment), table);
	gtk_widget_show (table);
}

gchar *
pgd_format_date (time_t utime)
{
	time_t time = (time_t) utime;
	char s[256];
	const char *fmt_hack = "%c";
	size_t len;
#ifdef HAVE_LOCALTIME_R
	struct tm t;
	if (time == 0 || !localtime_r (&time, &t)) return NULL;
	len = strftime (s, sizeof (s), fmt_hack, &t);
#else
	struct tm *t;
	if (time == 0 || !(t = localtime (&time)) ) return NULL;
	len = strftime (s, sizeof (s), fmt_hack, t);
#endif

	if (len == 0 || s[0] == '\0') return NULL;

	return g_locale_to_utf8 (s, -1, NULL, NULL, NULL);
}

GtkWidget *
pgd_movie_view_new (void)
{
	GtkWidget  *frame, *label;

	frame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type (GTK_FRAME (frame), GTK_SHADOW_NONE);
	label = gtk_label_new (NULL);
	gtk_label_set_markup (GTK_LABEL (label), "<b>Movie Properties</b>");
	gtk_frame_set_label_widget (GTK_FRAME (frame), label);
	gtk_widget_show (label);

	return frame;
}

__attribute__((used)) static void
pgd_movie_view_play_movie (GtkWidget    *button,
			   PopplerMovie *movie)
{
	const gchar *filename;
	GFile       *file;
	gchar       *uri;

	filename = poppler_movie_get_filename (movie);
	if (g_path_is_absolute (filename)) {
		file = g_file_new_for_path (filename);
	} else if (g_strrstr (filename, "://")) {
		file = g_file_new_for_uri (filename);
	} else {
		gchar *cwd;
		gchar *path;

		// FIXME: relative to doc uri, not cwd
		cwd = g_get_current_dir ();
		path = g_build_filename (cwd, filename, NULL);
		g_free (cwd);

		file = g_file_new_for_path (path);
		g_free (path);
	}

	uri = g_file_get_uri (file);
	g_object_unref (file);
	if (uri) {
		gtk_show_uri (gtk_widget_get_screen (button),
			      uri, GDK_CURRENT_TIME, NULL);
		g_free (uri);
	}
}

void
pgd_movie_view_set_movie (GtkWidget    *movie_view,
			  PopplerMovie *movie)
{
	GtkWidget  *alignment;
	GtkWidget  *table;
	GtkWidget  *button;
	gint        row = 0;

	alignment = gtk_bin_get_child (GTK_BIN (movie_view));
	if (alignment) {
		gtk_container_remove (GTK_CONTAINER (movie_view), alignment);
	}

	alignment = gtk_alignment_new (0.5, 0.5, 1, 1);
	gtk_alignment_set_padding (GTK_ALIGNMENT (alignment), 5, 5, 12, 5);
	gtk_container_add (GTK_CONTAINER (movie_view), alignment);
	gtk_widget_show (alignment);

	if (!movie)
		return;

	table = gtk_table_new (10, 2, FALSE);
	gtk_table_set_col_spacings (GTK_TABLE (table), 6);
	gtk_table_set_row_spacings (GTK_TABLE (table), 6);

	pgd_table_add_property (GTK_TABLE (table), "<b>Filename:</b>", poppler_movie_get_filename (movie), &row);
	pgd_table_add_property (GTK_TABLE (table), "<b>Need Poster:</b>", poppler_movie_need_poster (movie) ? "Yes" : "No", &row);
	pgd_table_add_property (GTK_TABLE (table), "<b>Show Controls:</b>", poppler_movie_show_controls (movie) ? "Yes" : "No", &row);

	button = gtk_button_new_from_stock (GTK_STOCK_MEDIA_PLAY);
	g_signal_connect (button, "clicked",
			  G_CALLBACK (pgd_movie_view_play_movie),
			  movie);
	pgd_table_add_property_with_custom_widget (GTK_TABLE (table), NULL, button, &row);
	gtk_widget_show (button);

	gtk_container_add (GTK_CONTAINER (alignment), table);
	gtk_widget_show (table);
}

