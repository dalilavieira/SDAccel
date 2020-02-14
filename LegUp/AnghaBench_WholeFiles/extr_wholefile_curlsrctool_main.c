#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct OperationConfig {int dummy; } ;
struct GlobalConfig {int showerror; TYPE_1__* last; TYPE_1__* first; int /*<<< orphan*/ * easy; int /*<<< orphan*/  libcurl; int /*<<< orphan*/ * trace_stream; scalar_t__ trace_fopened; int /*<<< orphan*/ * errors; scalar_t__ errors_fopened; int /*<<< orphan*/  trace_dump; int /*<<< orphan*/  styled_output; } ;
typedef  int /*<<< orphan*/  global ;
struct TYPE_5__ {struct GlobalConfig* global; int /*<<< orphan*/ * easy; } ;
typedef  scalar_t__ CURLcode ;

/* Variables and functions */
 scalar_t__ CURLE_FAILED_INIT ; 
 scalar_t__ CURLE_OK ; 
 int /*<<< orphan*/  CURL_GLOBAL_DEFAULT ; 
 int /*<<< orphan*/  Curl_safefree (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TRUE ; 
 int /*<<< orphan*/  config_free (TYPE_1__*) ; 
 int /*<<< orphan*/  config_init (TYPE_1__*) ; 
 int /*<<< orphan*/  configure_terminal () ; 
 int /*<<< orphan*/  convert_cleanup () ; 
 int /*<<< orphan*/  curl_easy_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * curl_easy_init () ; 
 int /*<<< orphan*/  curl_global_cleanup () ; 
 scalar_t__ curl_global_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 scalar_t__ get_libcurl_info () ; 
 int /*<<< orphan*/  helpf (int /*<<< orphan*/ *,char*) ; 
 TYPE_1__* malloc (int) ; 
 int /*<<< orphan*/  memory_tracking_init () ; 
 int /*<<< orphan*/  memset (struct GlobalConfig*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  metalink_cleanup () ; 
 scalar_t__ operate (struct GlobalConfig*,int,char**) ; 
 int /*<<< orphan*/ * stderr ; 

__attribute__((used)) static void main_checkfds(void)
{
#ifdef HAVE_PIPE
  int fd[2] = { STDIN_FILENO, STDIN_FILENO };
  while(fd[0] == STDIN_FILENO ||
        fd[0] == STDOUT_FILENO ||
        fd[0] == STDERR_FILENO ||
        fd[1] == STDIN_FILENO ||
        fd[1] == STDOUT_FILENO ||
        fd[1] == STDERR_FILENO)
    if(pipe(fd) < 0)
      return;   /* Out of handles. This isn't really a big problem now, but
                   will be when we try to create a socket later. */
  close(fd[0]);
  close(fd[1]);
#endif
}

__attribute__((used)) static CURLcode main_init(struct GlobalConfig *config)
{
  CURLcode result = CURLE_OK;

#if defined(__DJGPP__) || defined(__GO32__)
  /* stop stat() wasting time */
  _djstat_flags |= _STAT_INODE | _STAT_EXEC_MAGIC | _STAT_DIRSIZE;
#endif

  /* Initialise the global config */
  config->showerror = -1;             /* Will show errors */
  config->errors = stderr;            /* Default errors to stderr */
  config->styled_output = TRUE;       /* enable detection */

  /* Allocate the initial operate config */
  config->first = config->last = malloc(sizeof(struct OperationConfig));
  if(config->first) {
    /* Perform the libcurl initialization */
    result = curl_global_init(CURL_GLOBAL_DEFAULT);
    if(!result) {
      /* Get information about libcurl */
      result = get_libcurl_info();

      if(!result) {
        /* Get a curl handle to use for all forthcoming curl transfers */
        config->easy = curl_easy_init();
        if(config->easy) {
          /* Initialise the config */
          config_init(config->first);
          config->first->easy = config->easy;
          config->first->global = config;
        }
        else {
          helpf(stderr, "error initializing curl easy handle\n");
          result = CURLE_FAILED_INIT;
          free(config->first);
        }
      }
      else {
        helpf(stderr, "error retrieving curl library information\n");
        free(config->first);
      }
    }
    else {
      helpf(stderr, "error initializing curl library\n");
      free(config->first);
    }
  }
  else {
    helpf(stderr, "error initializing curl\n");
    result = CURLE_FAILED_INIT;
  }

  return result;
}

__attribute__((used)) static void free_globalconfig(struct GlobalConfig *config)
{
  Curl_safefree(config->trace_dump);

  if(config->errors_fopened && config->errors)
    fclose(config->errors);
  config->errors = NULL;

  if(config->trace_fopened && config->trace_stream)
    fclose(config->trace_stream);
  config->trace_stream = NULL;

  Curl_safefree(config->libcurl);
}

__attribute__((used)) static void main_free(struct GlobalConfig *config)
{
  /* Cleanup the easy handle */
  curl_easy_cleanup(config->easy);
  config->easy = NULL;

  /* Main cleanup */
  curl_global_cleanup();
  convert_cleanup();
  metalink_cleanup();
#ifdef USE_NSS
  if(PR_Initialized()) {
    /* prevent valgrind from reporting still reachable mem from NSRP arenas */
    PL_ArenaFinish();
    /* prevent valgrind from reporting possibly lost memory (fd cache, ...) */
    PR_Cleanup();
  }
#endif
  free_globalconfig(config);

  /* Free the config structures */
  config_free(config->last);
  config->first = NULL;
  config->last = NULL;
}

__attribute__((used)) static void restore_terminal(void)
{
#ifdef WIN32
  /* Restore Console output mode and codepage to whatever they were
   * when Curl started */
  SetConsoleMode(TerminalSettings.hStdOut, TerminalSettings.dwOutputMode);
#endif
}

int main(int argc, char *argv[])
{
  CURLcode result = CURLE_OK;
  struct GlobalConfig global;
  memset(&global, 0, sizeof(global));

  /* Perform any platform-specific terminal configuration */
  configure_terminal();

  main_checkfds();

#if defined(HAVE_SIGNAL) && defined(SIGPIPE)
  (void)signal(SIGPIPE, SIG_IGN);
#endif

  /* Initialize memory tracking */
  memory_tracking_init();

  /* Initialize the curl library - do not call any libcurl functions before
     this point */
  result = main_init(&global);

#ifdef WIN32
  /* Undocumented diagnostic option to list the full paths of all loaded
     modules, regardless of whether or not initialization succeeded. */
  if(argc == 2 && !strcmp(argv[1], "--dump-module-paths")) {
    struct curl_slist *item, *head = GetLoadedModulePaths();
    for(item = head; item; item = item->next) {
      printf("%s\n", item->data);
    }
    curl_slist_free_all(head);
    if(!result)
      main_free(&global);
  }
  else
#endif /* WIN32 */
  if(!result) {
    /* Start our curl operation */
    result = operate(&global, argc, argv);

#ifdef __SYMBIAN32__
    if(global.showerror)
      tool_pressanykey();
#endif

    /* Perform the main cleanup */
    main_free(&global);
  }

  /* Return the terminal to its original state */
  restore_terminal();

#ifdef __NOVELL_LIBC__
  if(getenv("_IN_NETWARE_BASH_") == NULL)
    tool_pressanykey();
#endif

#ifdef __VMS
  vms_special_exit(result, vms_show);
#else
  return (int)result;
#endif
}

