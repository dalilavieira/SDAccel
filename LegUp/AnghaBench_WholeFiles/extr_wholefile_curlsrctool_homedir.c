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
 char FALSE ; 
 char* getenv (char const*) ; 
 char* strdup (char*) ; 

__attribute__((used)) static char *GetEnv(const char *variable, char do_expand)
{
  char *env = NULL;
#ifdef WIN32
  char  buf1[1024], buf2[1024];
  DWORD rc;

  /* Don't use getenv(); it doesn't find variable added after program was
   * started. Don't accept truncated results (i.e. rc >= sizeof(buf1)).  */

  rc = GetEnvironmentVariableA(variable, buf1, sizeof(buf1));
  if(rc > 0 && rc < sizeof(buf1)) {
    env = buf1;
    variable = buf1;
  }
  if(do_expand && strchr(variable, '%')) {
    /* buf2 == variable if not expanded */
    rc = ExpandEnvironmentStringsA(variable, buf2, sizeof(buf2));
    if(rc > 0 && rc < sizeof(buf2) &&
       !strchr(buf2, '%'))    /* no vars still unexpanded */
      env = buf2;
  }
#else
  (void)do_expand;
  /* no length control */
  env = getenv(variable);
#endif
  return (env && env[0]) ? strdup(env) : NULL;
}

char *homedir(void)
{
  char *home;

  home = GetEnv("CURL_HOME", FALSE);
  if(home)
    return home;

  home = GetEnv("HOME", FALSE);
  if(home)
    return home;

#if defined(HAVE_GETPWUID) && defined(HAVE_GETEUID)
 {
   struct passwd *pw = getpwuid(geteuid());

   if(pw) {
     home = pw->pw_dir;
     if(home && home[0])
       home = strdup(home);
     else
       home = NULL;
   }
 }
#endif /* PWD-stuff */
#ifdef WIN32
  home = GetEnv("APPDATA", TRUE);
  if(!home)
    home = GetEnv("%USERPROFILE%\\Application Data", TRUE); /* Normally only
                                                               on Win-2K/XP */
#endif /* WIN32 */
  return home;
}

