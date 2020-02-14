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

/* Variables and functions */
#define  PS_TITLE_BUFFER_NOT_AVAILABLE 131 
#define  PS_TITLE_NOT_AVAILABLE 130 
#define  PS_TITLE_NOT_INITIALIZED 129 
#define  PS_TITLE_SUCCESS 128 
 char* ps_buffer ; 
 scalar_t__ ps_buffer_cur_len ; 
 int ps_buffer_size ; 
 int save_argc ; 
 char** save_argv ; 
 scalar_t__ strlen (char*) ; 
 int /*<<< orphan*/  strncpy (char*,char const*,int) ; 

char** save_ps_args(int argc, char** argv)
{
    save_argc = argc;
    save_argv = argv;

#if defined(PS_USE_CLOBBER_ARGV)
    /*
     * If we're going to overwrite the argv area, count the available space.
     * Also move the environment to make additional room.
     */
    {
        char* end_of_area = NULL;
        int non_contiguous_area = 0;
        int i;

        /*
         * check for contiguous argv strings
         */
        for (i = 0; (non_contiguous_area == 0) && (i < argc); i++)
        {
            if (i != 0 && end_of_area + 1 != argv[i])
                non_contiguous_area = 1;
            end_of_area = argv[i] + strlen(argv[i]);
        }

        /*
         * check for contiguous environ strings following argv
         */
        for (i = 0; (non_contiguous_area == 0) && (environ[i] != NULL); i++)
        {
            if (end_of_area + 1 != environ[i])
                non_contiguous_area = 1;
            end_of_area = environ[i] + strlen(environ[i]);
        }

        if (non_contiguous_area != 0)
            goto clobber_error;

        ps_buffer = argv[0];
        ps_buffer_size = end_of_area - argv[0];

        /*
         * move the environment out of the way
         */
        new_environ = (char **) malloc((i + 1) * sizeof(char *));
        frozen_environ = (char **) malloc((i + 1) * sizeof(char *));
        if (!new_environ || !frozen_environ)
            goto clobber_error;
        for (i = 0; environ[i] != NULL; i++)
        {
            new_environ[i] = strdup(environ[i]);
            if (!new_environ[i])
                goto clobber_error;
        }
        new_environ[i] = NULL;
        environ = new_environ;
        memcpy((char *)frozen_environ, (char *)new_environ, sizeof(char *) * (i + 1));

    }
#endif /* PS_USE_CLOBBER_ARGV */

#if defined(PS_USE_CHANGE_ARGV) || defined(PS_USE_CLOBBER_ARGV)
    /*
     * If we're going to change the original argv[] then make a copy for
     * argument parsing purposes.
     *
     * (NB: do NOT think to remove the copying of argv[]!
     * On some platforms, getopt() keeps pointers into the argv array, and
     * will get horribly confused when it is re-called to analyze a subprocess'
     * argument string if the argv storage has been clobbered meanwhile.
     * Other platforms have other dependencies on argv[].)
     */
    {
        char** new_argv;
        int i;

        new_argv = (char **) malloc((argc + 1) * sizeof(char *));
        if (!new_argv)
            goto clobber_error;
        for (i = 0; i < argc; i++)
        {
            new_argv[i] = strdup(argv[i]);
            if (!new_argv[i]) {
                free(new_argv);
                goto clobber_error;
            }
        }
        new_argv[argc] = NULL;

#if defined(DARWIN)
        /*
         * Darwin (and perhaps other NeXT-derived platforms?) has a static
         * copy of the argv pointer, which we may fix like so:
         */
        *_NSGetArgv() = new_argv;
#endif

        argv = new_argv;

    }
#endif /* PS_USE_CHANGE_ARGV or PS_USE_CLOBBER_ARGV */

#if defined(PS_USE_CLOBBER_ARGV)
    {
        /* make extra argv slots point at end_of_area (a NUL) */
        int i;
        for (i = 1; i < save_argc; i++)
            save_argv[i] = ps_buffer + ps_buffer_size;
    }
#endif /* PS_USE_CLOBBER_ARGV */

#ifdef PS_USE_CHANGE_ARGV
    save_argv[0] = ps_buffer; /* ps_buffer here is a static const array of size PS_BUFFER_SIZE */
    save_argv[1] = NULL;
#endif /* PS_USE_CHANGE_ARGV */

    return argv;

#if defined(PS_USE_CHANGE_ARGV) || defined(PS_USE_CLOBBER_ARGV)
clobber_error:
    /* probably can't happen?!
     * if we ever get here, argv still points to originally passed
     * in argument
     */
    save_argv = NULL;
    save_argc = 0;
    ps_buffer = NULL;
    ps_buffer_size = 0;
    return argv;
#endif /* PS_USE_CHANGE_ARGV or PS_USE_CLOBBER_ARGV */
}

int is_ps_title_available()
{
#ifdef PS_USE_NONE
    return PS_TITLE_NOT_AVAILABLE; /* disabled functionality */
#endif

    if (!save_argv)
        return PS_TITLE_NOT_INITIALIZED;

#ifdef PS_USE_CLOBBER_ARGV
    if (!ps_buffer)
        return PS_TITLE_BUFFER_NOT_AVAILABLE;
#endif /* PS_USE_CLOBBER_ARGV */

    return PS_TITLE_SUCCESS;
}

const char* ps_title_errno(int rc)
{
    switch(rc)
    {
    case PS_TITLE_SUCCESS:
        return "Success";

    case PS_TITLE_NOT_AVAILABLE:
        return "Not available on this OS";

    case PS_TITLE_NOT_INITIALIZED:
        return "Not initialized correctly";

    case PS_TITLE_BUFFER_NOT_AVAILABLE:
        return "Buffer not contiguous";

#ifdef PS_USE_WIN32
    case PS_TITLE_WINDOWS_ERROR:
        sprintf(windows_error_details, "Windows error code: %lu", GetLastError());
        return windows_error_details;
#endif
    }

    return "Unknown error code";
}

int set_ps_title(const char* title)
{
    int rc = is_ps_title_available();
    if (rc != PS_TITLE_SUCCESS)
        return rc;

    strncpy(ps_buffer, title, ps_buffer_size);
    ps_buffer[ps_buffer_size - 1] = '\0';
    ps_buffer_cur_len = strlen(ps_buffer);

#ifdef PS_USE_SETPROCTITLE
    setproctitle("%s", ps_buffer);
#endif

#ifdef PS_USE_PSTAT
    {
        union pstun pst;

        pst.pst_command = ps_buffer;
        pstat(PSTAT_SETCMD, pst, ps_buffer_cur_len, 0, 0);
    }
#endif /* PS_USE_PSTAT */

#ifdef PS_USE_PS_STRINGS
    PS_STRINGS->ps_nargvstr = 1;
    PS_STRINGS->ps_argvstr = ps_buffer;
#endif /* PS_USE_PS_STRINGS */

#ifdef PS_USE_CLOBBER_ARGV
    /* pad unused memory */
    if (ps_buffer_cur_len < ps_buffer_size)
    {
        memset(ps_buffer + ps_buffer_cur_len, PS_PADDING,
               ps_buffer_size - ps_buffer_cur_len);
    }
#endif /* PS_USE_CLOBBER_ARGV */

#ifdef PS_USE_WIN32
    {
	wchar_t *ps_buffer_w = php_win32_cp_any_to_w(ps_buffer);

        if (!ps_buffer_w || !SetConsoleTitleW(ps_buffer_w)) {
            return PS_TITLE_WINDOWS_ERROR;
	}

	free(ps_buffer_w);
    }
#endif /* PS_USE_WIN32 */

    return PS_TITLE_SUCCESS;
}

int get_ps_title(int *displen, const char** string)
{
    int rc = is_ps_title_available();
    if (rc != PS_TITLE_SUCCESS)
        return rc;

#ifdef PS_USE_WIN32
    {
	wchar_t ps_buffer_w[MAX_PATH];
	char *tmp;

        if (!(ps_buffer_cur_len = GetConsoleTitleW(ps_buffer_w, (DWORD)sizeof(ps_buffer_w)))) {
            return PS_TITLE_WINDOWS_ERROR;
	}

	tmp = php_win32_cp_conv_w_to_any(ps_buffer_w, PHP_WIN32_CP_IGNORE_LEN, &ps_buffer_cur_len);
	if (!tmp) {
            return PS_TITLE_WINDOWS_ERROR;
	}

	ps_buffer_cur_len = ps_buffer_cur_len > sizeof(ps_buffer)-1 ? sizeof(ps_buffer)-1 : ps_buffer_cur_len;

	memmove(ps_buffer, tmp, ps_buffer_cur_len);
	free(tmp);
    }
#endif
    *displen = (int)ps_buffer_cur_len;
    *string = ps_buffer;
    return PS_TITLE_SUCCESS;
}

void cleanup_ps_args(char **argv)
{
#ifndef PS_USE_NONE
    if (save_argv)
    {
        save_argv = NULL;
        save_argc = 0;

#ifdef PS_USE_CLOBBER_ARGV
        {
            int i;
            for (i = 0; frozen_environ[i] != NULL; i++)
                free(frozen_environ[i]);
            free(frozen_environ);
            free(new_environ);
            /* leave a sane environment behind since some atexit() handlers
                call getenv(). */
            environ = empty_environ;
        }
#endif /* PS_USE_CLOBBER_ARGV */

#if defined(PS_USE_CHANGE_ARGV) || defined(PS_USE_CLOBBER_ARGV)
        {
            int i;
            for (i=0; argv[i] != NULL; i++)
                free(argv[i]);
            free(argv);
        }
#endif /* PS_USE_CHANGE_ARGV or PS_USE_CLOBBER_ARGV */
    }
#endif /* PS_USE_NONE */

    return;
}

