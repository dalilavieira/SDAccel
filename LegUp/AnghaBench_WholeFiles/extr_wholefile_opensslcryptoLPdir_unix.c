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
struct dirent {int /*<<< orphan*/  d_name; } ;
struct TYPE_7__ {char* entry_name; int /*<<< orphan*/ * dir; } ;
typedef  TYPE_1__ LP_DIR_CTX ;

/* Variables and functions */
 int EINVAL ; 
 int ENOMEM ; 
 int closedir (int /*<<< orphan*/ *) ; 
 int errno ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 TYPE_1__* malloc (int) ; 
 int /*<<< orphan*/  memset (TYPE_1__*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * opendir (char const*) ; 
 struct dirent* readdir (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strncpy (char*,int /*<<< orphan*/ ,int) ; 

const char *LP_find_file(LP_DIR_CTX **ctx, const char *directory)
{
    struct dirent *direntry = NULL;

    if (ctx == NULL || directory == NULL) {
        errno = EINVAL;
        return 0;
    }

    errno = 0;
    if (*ctx == NULL) {
        *ctx = malloc(sizeof(**ctx));
        if (*ctx == NULL) {
            errno = ENOMEM;
            return 0;
        }
        memset(*ctx, 0, sizeof(**ctx));

#ifdef __VMS
        {
            char c = directory[strlen(directory) - 1];

            if (c == ']' || c == '>' || c == ':')
                (*ctx)->expect_file_generations = 1;
        }
#endif

        (*ctx)->dir = opendir(directory);
        if ((*ctx)->dir == NULL) {
            int save_errno = errno; /* Probably not needed, but I'm paranoid */
            free(*ctx);
            *ctx = NULL;
            errno = save_errno;
            return 0;
        }
    }

#ifdef __VMS
    strncpy((*ctx)->previous_entry_name, (*ctx)->entry_name,
            sizeof((*ctx)->previous_entry_name));

 again:
#endif

    direntry = readdir((*ctx)->dir);
    if (direntry == NULL) {
        return 0;
    }

    strncpy((*ctx)->entry_name, direntry->d_name,
            sizeof((*ctx)->entry_name) - 1);
    (*ctx)->entry_name[sizeof((*ctx)->entry_name) - 1] = '\0';
#ifdef __VMS
    if ((*ctx)->expect_file_generations) {
        char *p = (*ctx)->entry_name + strlen((*ctx)->entry_name);

        while(p > (*ctx)->entry_name && isdigit(p[-1]))
            p--;
        if (p > (*ctx)->entry_name && p[-1] == ';')
            p[-1] = '\0';
        if (strcasecmp((*ctx)->entry_name, (*ctx)->previous_entry_name) == 0)
            goto again;
    }
#endif
    return (*ctx)->entry_name;
}

int LP_find_file_end(LP_DIR_CTX **ctx)
{
    if (ctx != NULL && *ctx != NULL) {
        int ret = closedir((*ctx)->dir);

        free(*ctx);
        switch (ret) {
        case 0:
            return 1;
        case -1:
            return 0;
        default:
            break;
        }
    }
    errno = EINVAL;
    return 0;
}

