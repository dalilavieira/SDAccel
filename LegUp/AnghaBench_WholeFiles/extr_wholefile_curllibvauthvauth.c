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
 int FALSE ; 
 int TRUE ; 
 char* aprintf (char*,char const*,char const*,...) ; 
 int strlen (char const*) ; 
 char* strpbrk (char const*,char*) ; 

char *Curl_auth_build_spn(const char *service, const char *host,
                          const char *realm)
{
  char *spn = NULL;

  /* Generate our SPN */
  if(host && realm)
    spn = aprintf("%s/%s@%s", service, host, realm);
  else if(host)
    spn = aprintf("%s/%s", service, host);
  else if(realm)
    spn = aprintf("%s@%s", service, realm);

  /* Return our newly allocated SPN */
  return spn;
}

bool Curl_auth_user_contains_domain(const char *user)
{
  bool valid = FALSE;

  if(user && *user) {
    /* Check we have a domain name or UPN present */
    char *p = strpbrk(user, "\\/@");

    valid = (p != NULL && p > user && p < user + strlen(user) - 1 ? TRUE :
                                                                    FALSE);
  }
#if defined(HAVE_GSSAPI) || defined(USE_WINDOWS_SSPI)
  else
    /* User and domain are obtained from the GSS-API credentials cache or the
       currently logged in user from Windows */
    valid = TRUE;
#endif

  return valid;
}

