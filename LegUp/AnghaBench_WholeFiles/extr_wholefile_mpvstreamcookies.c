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
struct mp_log {int dummy; } ;
struct cookie_list_type {char* name; char* value; char* path; char* domain; int secure; struct cookie_list_type* next; } ;
typedef  int int64_t ;

/* Variables and functions */
 int O_CLOEXEC ; 
 int O_RDONLY ; 
 int /*<<< orphan*/  SEEK_END ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int SIZE_MAX ; 
 int /*<<< orphan*/  close (int) ; 
 int /*<<< orphan*/  cookie_list_t ; 
 int /*<<< orphan*/  free (char*) ; 
 int lseek (int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 char* malloc (int) ; 
 int /*<<< orphan*/  mp_verbose (struct mp_log*,char*,...) ; 
 int open (char const*,int) ; 
 int read (int,char*,int) ; 
 char* talloc_asprintf_append_buffer (char*,char*,char*,char*,char*,char*,char*) ; 
 int /*<<< orphan*/  talloc_free (void*) ; 
 void* talloc_new (int /*<<< orphan*/ *) ; 
 char* talloc_strdup (void*,char*) ; 
 char* talloc_strndup (void*,char const*,int) ; 
 struct cookie_list_type* talloc_zero (void*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static char *col_dup(void *talloc_ctx, const char *src)
{
    int length = 0;
    while (src[length] > 31)
        length++;

    return talloc_strndup(talloc_ctx, src, length);
}

__attribute__((used)) static int parse_line(char **ptr, char *cols[7])
{
    int col;
    cols[0] = *ptr;

    for (col = 1; col < 7; col++) {
        for (; (**ptr) > 31; (*ptr)++);
        if (**ptr == 0)
            return 0;
        (*ptr)++;
        if ((*ptr)[-1] != 9)
            return 0;
        cols[col] = (*ptr);
    }

    return 1;
}

__attribute__((used)) static char *load_file(struct mp_log *log, const char *filename, int64_t * length)
{
    int fd;
    char *buffer = NULL;

    mp_verbose(log, "Loading cookie file: %s\n", filename);

    fd = open(filename, O_RDONLY | O_CLOEXEC);
    if (fd < 0) {
        mp_verbose(log, "Could not open");
        goto err_out;
    }

    *length = lseek(fd, 0, SEEK_END);

    if (*length < 0) {
        mp_verbose(log, "Could not find EOF");
        goto err_out;
    }

    if (*length > SIZE_MAX - 1) {
        mp_verbose(log, "File too big, could not malloc.");
        goto err_out;
    }

    lseek(fd, 0, SEEK_SET);

    if (!(buffer = malloc(*length + 1))) {
        mp_verbose(log, "Could not malloc.");
        goto err_out;
    }

    if (read(fd, buffer, *length) != *length) {
        mp_verbose(log, "Read is behaving funny.");
        goto err_out;
    }
    close(fd);
    buffer[*length] = 0;

    return buffer;

err_out:
    if (fd != -1) close(fd);
    free(buffer);
    return NULL;
}

__attribute__((used)) static struct cookie_list_type *load_cookies_from(void *ctx,
                                                  struct mp_log *log,
                                                  const char *filename)
{
    char *ptr, *file;
    int64_t length;

    ptr = file = load_file(log, filename, &length);
    if (!ptr)
        return NULL;

    struct cookie_list_type *list = NULL;
    while (*ptr) {
        char *cols[7];
        if (parse_line(&ptr, cols)) {
            struct cookie_list_type *new;
            new = talloc_zero(ctx, cookie_list_t);
            new->name = col_dup(new, cols[5]);
            new->value = col_dup(new, cols[6]);
            new->path = col_dup(new, cols[2]);
            new->domain = col_dup(new, cols[0]);
            new->secure = (*(cols[3]) == 't') || (*(cols[3]) == 'T');
            new->next = list;
            list = new;
        }
    }
    free(file);
    return list;
}

char *cookies_lavf(void *talloc_ctx, struct mp_log *log, char *file)
{
    void *tmp = talloc_new(NULL);
    struct cookie_list_type *list = NULL;
    if (file && file[0])
        list = load_cookies_from(tmp, log, file);

    char *res = talloc_strdup(talloc_ctx, "");

    while (list) {
        res = talloc_asprintf_append_buffer(res,
                    "%s=%s; path=%s; domain=%s; %s\n", list->name, list->value,
                    list->path, list->domain, list->secure ? "secure" : "");
        list = list->next;
    }

    talloc_free(tmp);
    return res;
}

