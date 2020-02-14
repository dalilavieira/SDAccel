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
 int strcmp (char const*,char const*) ; 

int
filename_cmp (const char *s1, const char *s2)
{
#if !defined(HAVE_DOS_BASED_FILE_SYSTEM) \
    && !defined(HAVE_CASE_INSENSITIVE_FILE_SYSTEM)
  return strcmp(s1, s2);
#else
  for (;;)
    {
      int c1 = *s1;
      int c2 = *s2;

#if defined (HAVE_CASE_INSENSITIVE_FILE_SYSTEM)
      c1 = TOLOWER (c1);
      c2 = TOLOWER (c2);
#endif

#if defined (HAVE_DOS_BASED_FILE_SYSTEM)
      /* On DOS-based file systems, the '/' and the '\' are equivalent.  */
      if (c1 == '/')
        c1 = '\\';
      if (c2 == '/')
        c2 = '\\';
#endif

      if (c1 != c2)
        return (c1 - c2);

      if (c1 == '\0')
        return 0;

      s1++;
      s2++;
    }
#endif
}

