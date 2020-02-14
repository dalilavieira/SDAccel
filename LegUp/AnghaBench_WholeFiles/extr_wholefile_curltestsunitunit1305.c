#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct sockaddr_in {int dummy; } ;
struct Curl_dns_entry {int dummy; } ;
struct TYPE_9__ {int ai_addrlen; struct TYPE_9__* addr; int /*<<< orphan*/  ai_family; struct TYPE_9__* ai_canonname; void* ai_addr; } ;
typedef  TYPE_1__ Curl_addrinfo ;
typedef  int /*<<< orphan*/  CURLcode ;

/* Variables and functions */
 int /*<<< orphan*/  AF_INET ; 
 int /*<<< orphan*/  CURLE_OK ; 
 int /*<<< orphan*/  CURLE_OUT_OF_MEMORY ; 
 int /*<<< orphan*/  Curl_freeaddrinfo (TYPE_1__*) ; 
 int /*<<< orphan*/  Curl_hash_destroy (int /*<<< orphan*/ *) ; 
 int Curl_mk_dnscache (int /*<<< orphan*/ *) ; 
 TYPE_1__* aprintf (char*,char*,int /*<<< orphan*/ ) ; 
 void* calloc (int,int) ; 
 int /*<<< orphan*/  curl_easy_cleanup (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  curl_easy_init () ; 
 int /*<<< orphan*/  curl_global_cleanup () ; 
 int /*<<< orphan*/  data ; 
 TYPE_1__* data_key ; 
 TYPE_1__* data_node ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 int /*<<< orphan*/  hp ; 
 TYPE_1__* strdup (char*) ; 

__attribute__((used)) static CURLcode unit_setup(void)
{
  int rc;
  data = curl_easy_init();
  if(!data)
    return CURLE_OUT_OF_MEMORY;

  rc = Curl_mk_dnscache(&hp);
  if(rc) {
    curl_easy_cleanup(data);
    curl_global_cleanup();
    return CURLE_OUT_OF_MEMORY;
  }
  return CURLE_OK;
}

__attribute__((used)) static void unit_stop(void)
{
  if(data_node) {
    Curl_freeaddrinfo(data_node->addr);
    free(data_node);
  }
  free(data_key);
  Curl_hash_destroy(&hp);

  curl_easy_cleanup(data);
  curl_global_cleanup();
}

__attribute__((used)) static Curl_addrinfo *fake_ai(void)
{
  static Curl_addrinfo *ai;

  ai = calloc(1, sizeof(Curl_addrinfo));
  if(!ai)
    return NULL;

  ai->ai_canonname = strdup("dummy");
  if(!ai->ai_canonname) {
    free(ai);
    return NULL;
  }

  ai->ai_addr = calloc(1, sizeof(struct sockaddr_in));
  if(!ai->ai_addr) {
    free(ai->ai_canonname);
    free(ai);
    return NULL;
  }

  ai->ai_family = AF_INET;
  ai->ai_addrlen = sizeof(struct sockaddr_in);

  return ai;
}

__attribute__((used)) static CURLcode create_node(void)
{
  data_key = aprintf("%s:%d", "dummy", 0);
  if(!data_key)
    return CURLE_OUT_OF_MEMORY;

  data_node = calloc(1, sizeof(struct Curl_dns_entry));
  if(!data_node)
    return CURLE_OUT_OF_MEMORY;

  data_node->addr = fake_ai();
  if(!data_node->addr)
    return CURLE_OUT_OF_MEMORY;

  return CURLE_OK;
}

