#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct input_ctx {int dummy; } ;
typedef  enum mp_dnd_action { ____Placeholder_mp_dnd_action } mp_dnd_action ;
struct TYPE_10__ {scalar_t__ len; } ;
typedef  TYPE_1__ bstr ;

/* Variables and functions */
 int DND_REPLACE ; 
 int /*<<< orphan*/  MP_TARRAY_APPEND (void*,char**,int,char*) ; 
 TYPE_1__ bstr_getline (TYPE_1__,TYPE_1__*) ; 
 scalar_t__ bstr_startswith0 (TYPE_1__,char*) ; 
 TYPE_1__ bstr_strip_linebreaks (TYPE_1__) ; 
 char* bstrto0 (void*,TYPE_1__) ; 
 int mp_event_get_mime_type_score (struct input_ctx*,char const*) ; 
 int /*<<< orphan*/  mp_input_run_cmd (struct input_ctx*,char const**) ; 
 int mp_might_be_subtitle_file (char*) ; 
 scalar_t__ strcmp (char const*,char*) ; 
 int /*<<< orphan*/  talloc_free (void*) ; 
 void* talloc_new (int /*<<< orphan*/ *) ; 

void mp_event_drop_files(struct input_ctx *ictx, int num_files, char **files,
                         enum mp_dnd_action action)
{
    bool all_sub = true;
    for (int i = 0; i < num_files; i++)
        all_sub &= mp_might_be_subtitle_file(files[i]);

    if (all_sub) {
        for (int i = 0; i < num_files; i++) {
            const char *cmd[] = {
                "osd-auto",
                "sub-add",
                files[i],
                NULL
            };
            mp_input_run_cmd(ictx, cmd);
        }
    } else {
        for (int i = 0; i < num_files; i++) {
            const char *cmd[] = {
                "osd-auto",
                "loadfile",
                files[i],
                /* Either start playing the dropped files right away
                   or add them to the end of the current playlist */
                (i == 0 && action == DND_REPLACE) ? "replace" : "append-play",
                NULL
            };
            mp_input_run_cmd(ictx, cmd);
        }
    }
}

int mp_event_drop_mime_data(struct input_ctx *ictx, const char *mime_type,
                            bstr data, enum mp_dnd_action action)
{
    // (text lists are the only format supported right now)
    if (mp_event_get_mime_type_score(ictx, mime_type) >= 0) {
        void *tmp = talloc_new(NULL);
        int num_files = 0;
        char **files = NULL;
        while (data.len) {
            bstr line = bstr_getline(data, &data);
            line = bstr_strip_linebreaks(line);
            if (bstr_startswith0(line, "#"))
                continue;
            char *s = bstrto0(tmp, line);
            MP_TARRAY_APPEND(tmp, files, num_files, s);
        }
        mp_event_drop_files(ictx, num_files, files, action);
        talloc_free(tmp);
        return num_files > 0;
    } else {
        return -1;
    }
}

int mp_event_get_mime_type_score(struct input_ctx *ictx, const char *mime_type)
{
    // X11 and Wayland file list format.
    if (strcmp(mime_type, "text/uri-list") == 0)
        return 10;
    // Just text; treat it the same for convenience.
    if (strcmp(mime_type, "text/plain;charset=utf-8") == 0)
        return 5;
    if (strcmp(mime_type, "text/plain") == 0)
        return 4;
    if (strcmp(mime_type, "text") == 0)
        return 0;
    return -1;
}

