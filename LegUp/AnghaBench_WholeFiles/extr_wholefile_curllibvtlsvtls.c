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
struct ssl_primary_config {scalar_t__ version; scalar_t__ version_max; scalar_t__ verifypeer; scalar_t__ verifyhost; scalar_t__ verifystatus; int /*<<< orphan*/  cipher_list13; int /*<<< orphan*/  cipher_list; int /*<<< orphan*/  egdsocket; int /*<<< orphan*/  random_file; int /*<<< orphan*/  clientcert; int /*<<< orphan*/  CAfile; int /*<<< orphan*/  CApath; int /*<<< orphan*/  sessionid; } ;
typedef  int /*<<< orphan*/  curl_sslbackend ;
typedef  int /*<<< orphan*/  curl_ssl_backend ;
typedef  int /*<<< orphan*/  CURLsslset ;

/* Variables and functions */
 int /*<<< orphan*/  CAfile ; 
 int /*<<< orphan*/  CApath ; 
 int /*<<< orphan*/  CLONE_STRING (int /*<<< orphan*/ ) ; 
 scalar_t__ CURLSSLBACKEND_NONE ; 
 int /*<<< orphan*/  CURLSSLSET_NO_BACKENDS ; 
 scalar_t__ Curl_safe_strcasecompare (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Curl_safefree (int /*<<< orphan*/ ) ; 
 int FALSE ; 
 int TRUE ; 
 int /*<<< orphan*/  cipher_list ; 
 int /*<<< orphan*/  cipher_list13 ; 
 int /*<<< orphan*/  clientcert ; 
 int /*<<< orphan*/  egdsocket ; 
 int /*<<< orphan*/  random_file ; 

bool
Curl_ssl_config_matches(struct ssl_primary_config* data,
                        struct ssl_primary_config* needle)
{
  if((data->version == needle->version) &&
     (data->version_max == needle->version_max) &&
     (data->verifypeer == needle->verifypeer) &&
     (data->verifyhost == needle->verifyhost) &&
     (data->verifystatus == needle->verifystatus) &&
     Curl_safe_strcasecompare(data->CApath, needle->CApath) &&
     Curl_safe_strcasecompare(data->CAfile, needle->CAfile) &&
     Curl_safe_strcasecompare(data->clientcert, needle->clientcert) &&
     Curl_safe_strcasecompare(data->random_file, needle->random_file) &&
     Curl_safe_strcasecompare(data->egdsocket, needle->egdsocket) &&
     Curl_safe_strcasecompare(data->cipher_list, needle->cipher_list) &&
     Curl_safe_strcasecompare(data->cipher_list13, needle->cipher_list13))
    return TRUE;

  return FALSE;
}

bool
Curl_clone_primary_ssl_config(struct ssl_primary_config *source,
                              struct ssl_primary_config *dest)
{
  dest->version = source->version;
  dest->version_max = source->version_max;
  dest->verifypeer = source->verifypeer;
  dest->verifyhost = source->verifyhost;
  dest->verifystatus = source->verifystatus;
  dest->sessionid = source->sessionid;

  CLONE_STRING(CApath);
  CLONE_STRING(CAfile);
  CLONE_STRING(clientcert);
  CLONE_STRING(random_file);
  CLONE_STRING(egdsocket);
  CLONE_STRING(cipher_list);
  CLONE_STRING(cipher_list13);

  return TRUE;
}

void Curl_free_primary_ssl_config(struct ssl_primary_config* sslc)
{
  Curl_safefree(sslc->CApath);
  Curl_safefree(sslc->CAfile);
  Curl_safefree(sslc->clientcert);
  Curl_safefree(sslc->random_file);
  Curl_safefree(sslc->egdsocket);
  Curl_safefree(sslc->cipher_list);
  Curl_safefree(sslc->cipher_list13);
}

int Curl_ssl_backend(void)
{
#ifdef USE_SSL
  multissl_init(NULL);
  return Curl_ssl->info.id;
#else
  return (int)CURLSSLBACKEND_NONE;
#endif
}

CURLsslset curl_global_sslset(curl_sslbackend id, const char *name,
                              const curl_ssl_backend ***avail)
{
  (void)id;
  (void)name;
  (void)avail;
  return CURLSSLSET_NO_BACKENDS;
}

