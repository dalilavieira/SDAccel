#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {int /*<<< orphan*/  buildrev; int /*<<< orphan*/  range; int /*<<< orphan*/  rev; } ;

/* Variables and functions */
 char const* CMD_7Z ; 
 char* DEF_OPT_DIR ; 
 int /*<<< orphan*/  DEF_RANGE ; 
 int /*<<< orphan*/  LINESIZE ; 
 char* PATH_STR ; 
 int /*<<< orphan*/  SOURCES_ENV ; 
 int /*<<< orphan*/  getRevision (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  getTBRevision (char const*) ; 
 char* getenv (int /*<<< orphan*/ ) ; 
 int getopt (int,char** const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  l2l_dbg (int,char*,...) ; 
 char* malloc (int /*<<< orphan*/ ) ; 
 char const* opt_7z ; 
 int /*<<< orphan*/  opt_Mark ; 
 char const* opt_Pipe ; 
 char const* opt_Revision ; 
 int /*<<< orphan*/  opt_Revision_check ; 
 int /*<<< orphan*/  opt_Source ; 
 char const* opt_SourcesPath ; 
 int /*<<< orphan*/  opt_SrcPlus ; 
 int /*<<< orphan*/  opt_Twice ; 
 int /*<<< orphan*/  opt_buffered ; 
 scalar_t__ opt_console ; 
 char const* opt_dir ; 
 int /*<<< orphan*/  opt_exit ; 
 int /*<<< orphan*/  opt_force ; 
 int /*<<< orphan*/  opt_help ; 
 char const* opt_logFile ; 
 int /*<<< orphan*/  opt_mark ; 
 char* opt_mod ; 
 int /*<<< orphan*/  opt_raw ; 
 int /*<<< orphan*/  opt_redo ; 
 char const* opt_scanned ; 
 scalar_t__ opt_stats ; 
 int /*<<< orphan*/  opt_twice ; 
 int /*<<< orphan*/  opt_undo ; 
 int /*<<< orphan*/  opt_verbose ; 
 char const* optarg ; 
 int /*<<< orphan*/  optchars ; 
 TYPE_1__ revinfo ; 
 int sscanf (char const*,char*,char const*,...) ; 
 int /*<<< orphan*/  strcat (char const*,char const*) ; 
 int /*<<< orphan*/  strcmp (char const*,char*) ; 
 int /*<<< orphan*/  strcpy (char const*,char const*) ; 
 int /*<<< orphan*/  usage (int) ; 

int optionInit(int argc, const char **argv)
{
    int i;
    char *s;

    opt_mod = "a";
    strcpy(opt_dir, "");
    strcpy(opt_logFile, "");
    strcpy(opt_7z, CMD_7Z);
    strcpy(opt_SourcesPath, "");
    if ((s = getenv(SOURCES_ENV)))
        strcpy(opt_SourcesPath, s);
    revinfo.rev = getRevision(NULL, 1);
    revinfo.range = DEF_RANGE;
    revinfo.buildrev = getTBRevision(opt_dir);
    l2l_dbg(1, "Trunk build revision: %d\n", revinfo.buildrev);

    strcpy(opt_scanned, "");

    //The user introduced "log2lines.exe" or "log2lines.exe /?"
    //Let's help the user
    if ((argc == 1) ||
        ((argc == 2) && (argv[1][0] == '/') && (argv[1][1] == '?')))
    {
        opt_help++;
        usage(1);
        return -1;
    }

    for (i = 1; i < argc; i++)
    {

        if ((argv[i][0] == '-') && (i+1 < argc))
        {
            //Because these arguments can contain spaces we cant use getopt(), a known bug:
            switch (argv[i][1])
            {
            case 'd':
                strcpy(opt_dir, argv[i+1]);
                break;
            case 'L':
                opt_mod = "w";
                //fall through
            case 'l':
                strcpy(opt_logFile, argv[i+1]);
                break;
            case 'P':
                if (!opt_Pipe)
                    opt_Pipe = malloc(LINESIZE);
                strcpy(opt_Pipe, argv[i+1]);
                break;
            case 'z':
                strcpy(opt_7z, argv[i+1]);
                break;
            }
        }

        strcat(opt_scanned, argv[i]);
        strcat(opt_scanned, " ");
    }

    l2l_dbg(4,"opt_scanned=[%s]\n",opt_scanned);

    return 0;
}

int optionParse(int argc, const char **argv)
{
    int i;
    int optCount = 0;
    int opt;

    while (-1 != (opt = getopt(argc, (char **const)argv, optchars)))
    {
        switch (opt)
        {
        case 'b':
            opt_buffered++;
            break;
        case 'c':
            opt_console++;
            break;
        case 'd':
            optCount++;
            //just count, see optionInit()
            break;
        case 'f':
            opt_force++;
            break;
        case 'h':
            opt_help++;
            usage(1);
            return -1;
            break;
        case 'F':
            opt_exit++;
            opt_force++;
            break;
        case 'l':
            optCount++;
            //just count, see optionInit()
            break;
        case 'm':
            opt_mark++;
            break;
        case 'M':
            opt_Mark++;
            break;
        case 'r':
            opt_raw++;
            break;
        case 'P':
            optCount++;
            //just count, see optionInit()
            break;
        case 'R':
            optCount++;
            if (!opt_Revision)
                opt_Revision = malloc(LINESIZE);
            sscanf(optarg, "%s", opt_Revision);
            if (strcmp(opt_Revision, "check") == 0)
                opt_Revision_check ++;
            break;
        case 's':
            opt_stats++;
            break;
        case 'S':
            optCount++;
            i = sscanf(optarg, "%d+%d,%s", &opt_Source, &opt_SrcPlus, opt_SourcesPath);
            if (i == 1)
                sscanf(optarg, "%*d,%s", opt_SourcesPath);
            l2l_dbg(3, "Sources option parse result: %d+%d,\"%s\"\n", opt_Source, opt_SrcPlus, opt_SourcesPath);
            if (opt_Source)
            {
                /* need to retranslate for source info: */
                opt_undo++;
                opt_redo++;
                opt_Revision_check ++;
            }
            break;
        case 't':
            opt_twice++;
            break;
        case 'T':
            opt_twice++;
            opt_Twice++;
            break;
        case 'u':
            opt_undo++;
            break;
        case 'U':
            opt_undo++;
            opt_redo++;
            break;
        case 'v':
            opt_verbose++;
            break;
        case 'z':
            optCount++;
            strcpy(opt_7z, optarg);
            break;
        default:
            usage(0);
            return -2;
            break;
        }
        optCount++;
    }
    if(opt_console)
    {
        l2l_dbg(2, "Note: use 's' command in console mode. Statistics option disabled\n");
        opt_stats = 0;
    }
    if (opt_SourcesPath[0])
    {
        strcat(opt_SourcesPath, PATH_STR);
    }
    if (!opt_dir[0])
    {
        strcpy(opt_dir, opt_SourcesPath);
        strcat(opt_dir, DEF_OPT_DIR);
    }

    return optCount;
}

