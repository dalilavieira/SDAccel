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
typedef  int /*<<< orphan*/  CURL ;

/* Variables and functions */
 int /*<<< orphan*/  CURLE_CONV_FAILED ; 
 int /*<<< orphan*/  CURLE_OK ; 
 int /*<<< orphan*/  CURLOPT_CONV_FROM_NETWORK_FUNCTION ; 
 int /*<<< orphan*/  CURLOPT_CONV_FROM_UTF8_FUNCTION ; 
 int /*<<< orphan*/  CURLOPT_CONV_TO_NETWORK_FUNCTION ; 
 int /*<<< orphan*/  CURLOPT_URL ; 
 int PLATFORM_CONV_OK ; 
 int /*<<< orphan*/  curl_easy_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * curl_easy_init () ; 
 int /*<<< orphan*/  curl_easy_perform (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  curl_easy_setopt (int /*<<< orphan*/ *,int /*<<< orphan*/ ,...) ; 
 int platform_a2e (char**,size_t*,char**,size_t*) ; 
 int platform_e2a (char**,size_t*,char**,size_t*) ; 
 int platform_u2e (char**,size_t*,char**,size_t*) ; 

__attribute__((used)) static CURLcode my_conv_from_ascii_to_ebcdic(char *buffer, size_t length)
{
  char *tempptrin, *tempptrout;
  size_t bytes = length;
  int rc;
  tempptrin = tempptrout = buffer;
  rc = platform_a2e(&tempptrin, &bytes, &tempptrout, &bytes);
  if(rc == PLATFORM_CONV_OK) {
    return CURLE_OK;
  }
  else {
    return CURLE_CONV_FAILED;
  }
}

__attribute__((used)) static CURLcode my_conv_from_ebcdic_to_ascii(char *buffer, size_t length)
{
  char *tempptrin, *tempptrout;
  size_t bytes = length;
  int rc;
  tempptrin = tempptrout = buffer;
  rc = platform_e2a(&tempptrin, &bytes, &tempptrout, &bytes);
  if(rc == PLATFORM_CONV_OK) {
    return CURLE_OK;
  }
  else {
    return CURLE_CONV_FAILED;
  }
}

__attribute__((used)) static CURLcode my_conv_from_utf8_to_ebcdic(char *buffer, size_t length)
{
  char *tempptrin, *tempptrout;
  size_t bytes = length;
  int rc;
  tempptrin = tempptrout = buffer;
  rc = platform_u2e(&tempptrin, &bytes, &tempptrout, &bytes);
  if(rc == PLATFORM_CONV_OK) {
    return CURLE_OK;
  }
  else {
    return CURLE_CONV_FAILED;
  }
}

int main(void)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

    /* use platform-specific functions for codeset conversions */
    curl_easy_setopt(curl, CURLOPT_CONV_FROM_NETWORK_FUNCTION,
                     my_conv_from_ascii_to_ebcdic);
    curl_easy_setopt(curl, CURLOPT_CONV_TO_NETWORK_FUNCTION,
                     my_conv_from_ebcdic_to_ascii);
    curl_easy_setopt(curl, CURLOPT_CONV_FROM_UTF8_FUNCTION,
                     my_conv_from_utf8_to_ebcdic);

    res = curl_easy_perform(curl);

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}

