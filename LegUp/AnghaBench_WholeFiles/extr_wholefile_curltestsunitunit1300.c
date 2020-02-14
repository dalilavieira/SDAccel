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
typedef  int /*<<< orphan*/  CURLcode ;

/* Variables and functions */
 int /*<<< orphan*/  CURLE_OK ; 
 int /*<<< orphan*/  Curl_llist_init (int /*<<< orphan*/ *,void (*) (void*,void*)) ; 
 int /*<<< orphan*/  llist ; 
 int /*<<< orphan*/  llist_destination ; 

__attribute__((used)) static void test_curl_llist_dtor(void *key, void *value)
{
  /* used by the llist API, does nothing here */
  (void)key;
  (void)value;
}

__attribute__((used)) static CURLcode unit_setup(void)
{
  Curl_llist_init(&llist, test_curl_llist_dtor);
  Curl_llist_init(&llist_destination, test_curl_llist_dtor);
  return CURLE_OK;
}

__attribute__((used)) static void unit_stop(void)
{
}

