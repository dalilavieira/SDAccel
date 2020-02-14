#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_21__   TYPE_3__ ;
typedef  struct TYPE_20__   TYPE_2__ ;
typedef  struct TYPE_19__   TYPE_1__ ;

/* Type definitions */
struct stream {char* url; } ;
struct TYPE_19__ {scalar_t__ buf_pos; scalar_t__ buf_len; int* buffer; int eof; scalar_t__ pos; char* path; int (* fill_buffer ) (TYPE_1__*,char*,int) ;int (* seek ) (TYPE_1__*,scalar_t__) ;int seekable; void (* close ) (TYPE_1__*) ;int (* control ) (TYPE_1__*,int,void*) ;TYPE_2__* priv; int /*<<< orphan*/  global; int /*<<< orphan*/  cancel; } ;
typedef  TYPE_1__ stream_t ;
struct TYPE_20__ {scalar_t__ size; int /*<<< orphan*/  global; int /*<<< orphan*/  cancel; struct stream* s; TYPE_3__* current_chunk; int /*<<< orphan*/  name; } ;
typedef  TYPE_2__ rar_file_t ;
struct TYPE_21__ {char* mrl; } ;
typedef  TYPE_3__ rar_file_chunk_t ;
typedef  scalar_t__ int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  RarFileDelete (TYPE_2__*) ; 
 scalar_t__ RarParse (struct stream*,int*,TYPE_2__***) ; 
 scalar_t__ RarProbe (struct stream*) ; 
 int RarRead (TYPE_2__*,char*,int) ; 
 int RarSeek (TYPE_2__*,scalar_t__) ; 
#define  STREAM_CTRL_GET_BASE_FILENAME 129 
#define  STREAM_CTRL_GET_SIZE 128 
 int STREAM_ERROR ; 
 int STREAM_OK ; 
 int STREAM_READ ; 
 int STREAM_SAFE_ONLY ; 
 int STREAM_UNSUPPORTED ; 
 int /*<<< orphan*/  free_stream (struct stream*) ; 
 int /*<<< orphan*/  mp_url_unescape_inplace (char*) ; 
 char* strchr (char*,char) ; 
 scalar_t__ strcmp (int /*<<< orphan*/ ,char*) ; 
 struct stream* stream_create (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ stream_fill_buffer (TYPE_1__*) ; 
 int /*<<< orphan*/  talloc_free (TYPE_2__**) ; 
 char* talloc_strdup (TYPE_1__*,char*) ; 

__attribute__((used)) inline static int stream_read_char(stream_t *s)
{
    return (s->buf_pos < s->buf_len) ? s->buffer[s->buf_pos++] :
           (stream_fill_buffer(s) ? s->buffer[s->buf_pos++] : -256);
}

__attribute__((used)) inline static int stream_eof(stream_t *s)
{
    return s->eof;
}

__attribute__((used)) inline static int64_t stream_tell(stream_t *s)
{
    return s->pos + s->buf_pos - s->buf_len;
}

__attribute__((used)) static int rar_entry_fill_buffer(stream_t *s, char *buffer, int max_len)
{
    rar_file_t *rar_file = s->priv;
    return RarRead(rar_file, buffer, max_len);
}

__attribute__((used)) static int rar_entry_seek(stream_t *s, int64_t newpos)
{
    rar_file_t *rar_file = s->priv;
    return RarSeek(rar_file, newpos);
}

__attribute__((used)) static void rar_entry_close(stream_t *s)
{
    rar_file_t *rar_file = s->priv;
    RarFileDelete(rar_file);
}

__attribute__((used)) static int rar_entry_control(stream_t *s, int cmd, void *arg)
{
    rar_file_t *rar_file = s->priv;
    switch (cmd) {
    case STREAM_CTRL_GET_BASE_FILENAME:
        *(char **)arg = talloc_strdup(NULL, rar_file->s->url);
        return STREAM_OK;
    case STREAM_CTRL_GET_SIZE:
        *(int64_t *)arg = rar_file->size;
        return STREAM_OK;
    }
    return STREAM_UNSUPPORTED;
}

__attribute__((used)) static int rar_entry_open(stream_t *stream)
{
    if (!strchr(stream->path, '|'))
        return STREAM_ERROR;

    char *base = talloc_strdup(stream, stream->path);
    char *name = strchr(base, '|');
    *name++ = '\0';
    mp_url_unescape_inplace(base);

    struct stream *rar = stream_create(base, STREAM_READ | STREAM_SAFE_ONLY,
                                       stream->cancel, stream->global);
    if (!rar)
        return STREAM_ERROR;

    int count;
    rar_file_t **files;
    if (RarProbe(rar) || RarParse(rar, &count, &files)) {
        free_stream(rar);
        return STREAM_ERROR;
    }

    rar_file_t *file = NULL;
    for (int i = 0; i < count; i++) {
        if (!file && strcmp(files[i]->name, name) == 0)
            file = files[i];
        else
            RarFileDelete(files[i]);
    }
    talloc_free(files);
    if (!file) {
        free_stream(rar);
        return STREAM_ERROR;
    }

    rar_file_chunk_t dummy = {
        .mrl = base,
    };
    file->current_chunk = &dummy;
    file->s = rar; // transfer ownership
    file->cancel = stream->cancel;
    file->global = stream->global;
    RarSeek(file, 0);

    stream->priv = file;
    stream->fill_buffer = rar_entry_fill_buffer;
    stream->seek = rar_entry_seek;
    stream->seekable = true;
    stream->close = rar_entry_close;
    stream->control = rar_entry_control;

    return STREAM_OK;
}

