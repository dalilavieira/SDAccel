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
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 char* CP_FMT ; 
 scalar_t__ EEXIST ; 
 int LINESIZE ; 
 int MKDIR (char*) ; 
 char PATH_CHAR ; 
 scalar_t__ errno ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char*,char*) ; 
 int /*<<< orphan*/  l2l_dbg (int,char*,char*,...) ; 
 int /*<<< orphan*/  opt_buffered ; 
 char* opt_logFile ; 
 char* opt_mod ; 
 int /*<<< orphan*/  remove (char*) ; 
 int /*<<< orphan*/  setbuf (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sprintf (char*,char*,char*,char*) ; 
 int sscanf (char const*,char const*,int*) ; 
 scalar_t__ strchr (char const*,char) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  strerror (scalar_t__) ; 
 char* strrchr (char*,char) ; 
 scalar_t__ system (char*) ; 

int
set_LogFile(FILE **plogFile)
{
    if (*opt_logFile)
    {
        if (*plogFile)
            fclose(*plogFile);
        *plogFile = NULL;

        if (strcmp(opt_logFile,"none") == 0)
            return 0; //just close

        *plogFile = fopen(opt_logFile, opt_mod ? opt_mod : "a");
        if (*plogFile)
        {
            // disable buffering so fflush is not needed
            if (!opt_buffered)
            {
                l2l_dbg(1, "Disabling log buffering on %s\n", opt_logFile);
                setbuf(*plogFile, NULL);
            }
            else
                l2l_dbg(1, "Enabling log buffering on %s\n", opt_logFile);
        }
        else
        {
            l2l_dbg(0, "Could not open logfile %s (%s)\n", opt_logFile, strerror(errno));
            return 2;
        }
    }
    return 0;
}

int
file_exists(char *name)
{
    FILE *f;

    f = fopen(name, "r");
    if (!f)
        return 0;
    fclose(f);
    return 1;
}

int
mkPath(char *path, int isDir)
{
    char *s;
    int res = 0;

    if (isDir)
    {
        res = MKDIR(path);
        if (!res || (res == -1 && errno == EEXIST))
            return 0;
    }
    // create parent dir
    if ((s = strrchr(path, PATH_CHAR)))
    {
        *s = '\0';
        res = mkPath(path, 1);
        *s = PATH_CHAR;
    }

    if (!res && isDir)
        res = MKDIR(path);

    return res;
}

char *
basename(char *path)
{
    char *base;

    base = strrchr(path, PATH_CHAR);
    if (base)
        return ++base;
    return path;
}

const char *
getFmt(const char *a)
{
    const char *fmt = "%x";

    if (*a == '0')
    {
        switch (*++a)
        {
        case 'x':
            fmt = "%x";
            ++a;
            break;
        case 'd':
            fmt = "%d";
            ++a;
            break;
        default:
            fmt = "%o";
            break;
        }
    }
    return fmt;
}

long
my_atoi(const char *a)
{
    int i = 0;
    sscanf(a, getFmt(a), &i);
    return i;
}

int
isOffset(const char *a)
{
    int i = 0;
    if (strchr(a, '.'))
        return 0;
    return sscanf(a, getFmt(a), &i);
}

int
copy_file(char *src, char *dst)
{
    char Line[LINESIZE];

    sprintf(Line, CP_FMT, src, dst);
    l2l_dbg(2, "Executing: %s\n", Line);
    remove(dst);
    if (file_exists(dst))
    {
        l2l_dbg(0, "Cannot remove dst %s before copy\n", dst);
        return 1;
    }
    if (system(Line) < 0)
    {
        l2l_dbg(0, "Cannot copy %s to %s\n", src, dst);
        l2l_dbg(1, "Failed to execute: '%s'\n", Line);
        return 2;
    }

    if (!file_exists(dst))
    {
        l2l_dbg(0, "Dst %s does not exist after copy\n", dst);
        return 2;
    }
    return 0;
}

