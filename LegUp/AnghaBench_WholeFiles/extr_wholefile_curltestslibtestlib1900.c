#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  urlbuf ;
struct timeval {int tv_sec; long tv_usec; } ;
typedef  int /*<<< orphan*/  fd_set ;
struct TYPE_4__ {int result; } ;
struct TYPE_5__ {scalar_t__ msg; scalar_t__ easy_handle; TYPE_1__ data; } ;
typedef  int /*<<< orphan*/  FILE ;
typedef  TYPE_2__ CURLMsg ;
typedef  int /*<<< orphan*/  CURLM ;

/* Variables and functions */
 int /*<<< orphan*/  CURLMOPT_CHUNK_LENGTH_PENALTY_SIZE ; 
 int /*<<< orphan*/  CURLMOPT_CONTENT_LENGTH_PENALTY_SIZE ; 
 int /*<<< orphan*/  CURLMOPT_MAX_HOST_CONNECTIONS ; 
 int /*<<< orphan*/  CURLMOPT_MAX_PIPELINE_LENGTH ; 
 int /*<<< orphan*/  CURLMOPT_PIPELINING ; 
 int /*<<< orphan*/  CURLMOPT_PIPELINING_SERVER_BL ; 
 int /*<<< orphan*/  CURLMOPT_PIPELINING_SITE_BL ; 
 scalar_t__ CURLMSG_DONE ; 
 int /*<<< orphan*/  CURLOPT_FAILONERROR ; 
 int /*<<< orphan*/  CURLOPT_URL ; 
 int /*<<< orphan*/  CURLOPT_VERBOSE ; 
 int /*<<< orphan*/  CURLOPT_WRITEDATA ; 
 int /*<<< orphan*/  CURLOPT_WRITEFUNCTION ; 
 int /*<<< orphan*/  CURL_GLOBAL_ALL ; 
 int /*<<< orphan*/  Curl_safefree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  FD_ZERO (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  abort_on_test_timeout () ; 
 size_t blacklist_num_servers ; 
 size_t blacklist_num_sites ; 
 int /*<<< orphan*/  curl_easy_cleanup (scalar_t__) ; 
 scalar_t__ curl_easy_init () ; 
 int /*<<< orphan*/  curl_easy_setopt (scalar_t__,int /*<<< orphan*/ ,...) ; 
 int /*<<< orphan*/  curl_global_cleanup () ; 
 int /*<<< orphan*/  curl_global_init (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  curl_multi_add_handle (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  curl_multi_cleanup (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  curl_multi_fdset (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int*) ; 
 TYPE_2__* curl_multi_info_read (int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  curl_multi_perform (int /*<<< orphan*/ *,int*) ; 
 int /*<<< orphan*/  curl_multi_remove_handle (int /*<<< orphan*/ *,scalar_t__) ; 
 int /*<<< orphan*/  curl_multi_timeout (int /*<<< orphan*/ *,long*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  feof (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,int) ; 
 scalar_t__ fscanf (int /*<<< orphan*/ *,char*,...) ; 
 scalar_t__* handles ; 
 char* libtest_arg2 ; 
 int /*<<< orphan*/  msnprintf (char*,int,char*,char*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  multi_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  multi_setopt (int /*<<< orphan*/ *,int /*<<< orphan*/ ,long) ; 
 size_t num_handles ; 
 int /*<<< orphan*/  printf (char*,int,int) ; 
 int /*<<< orphan*/  select_test (int,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct timeval*) ; 
 int /*<<< orphan*/ ** server_blacklist ; 
 int /*<<< orphan*/ ** site_blacklist ; 
 int /*<<< orphan*/  start_test_timing () ; 
 int /*<<< orphan*/  stdout ; 
 int /*<<< orphan*/ * strdup (char*) ; 
 scalar_t__ tutil_tvdiff (struct timeval,struct timeval) ; 
 struct timeval tutil_tvnow () ; 
 int /*<<< orphan*/ ** urlstring ; 
 scalar_t__* urltime ; 

__attribute__((used)) static size_t
write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  (void)contents;
  (void)userp;

  return realsize;
}

__attribute__((used)) static int parse_url_file(const char *filename)
{
  FILE *f;
  int filetime;
  char buf[200];

  num_handles = 0;
  blacklist_num_sites = 0;
  blacklist_num_servers = 0;

  f = fopen(filename, "rb");
  if(!f)
    return 0;

  while(!feof(f)) {
    if(fscanf(f, "%d %199s\n", &filetime, buf)) {
      urltime[num_handles] = filetime;
      urlstring[num_handles] = strdup(buf);
      num_handles++;
      continue;
    }

    if(fscanf(f, "blacklist_site %199s\n", buf)) {
      site_blacklist[blacklist_num_sites] = strdup(buf);
      blacklist_num_sites++;
      continue;
    }

    break;
  }
  fclose(f);

  site_blacklist[blacklist_num_sites] = NULL;
  server_blacklist[blacklist_num_servers] = NULL;
  return num_handles;
}

__attribute__((used)) static void free_urls(void)
{
  int i;
  for(i = 0; i < num_handles; i++) {
    Curl_safefree(urlstring[i]);
  }
  for(i = 0; i < blacklist_num_servers; i++) {
    Curl_safefree(server_blacklist[i]);
  }
  for(i = 0; i < blacklist_num_sites; i++) {
    Curl_safefree(site_blacklist[i]);
  }
}

__attribute__((used)) static int create_handles(void)
{
  int i;

  for(i = 0; i < num_handles; i++) {
    handles[i] = curl_easy_init();
  }
  return 0;
}

__attribute__((used)) static void setup_handle(char *base_url, CURLM *m, int handlenum)
{
  char urlbuf[256];

  msnprintf(urlbuf, sizeof(urlbuf), "%s%s", base_url, urlstring[handlenum]);
  curl_easy_setopt(handles[handlenum], CURLOPT_URL, urlbuf);
  curl_easy_setopt(handles[handlenum], CURLOPT_VERBOSE, 1L);
  curl_easy_setopt(handles[handlenum], CURLOPT_FAILONERROR, 1L);
  curl_easy_setopt(handles[handlenum], CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(handles[handlenum], CURLOPT_WRITEDATA, NULL);
  curl_multi_add_handle(m, handles[handlenum]);
}

__attribute__((used)) static void remove_handles(void)
{
  int i;

  for(i = 0; i < num_handles; i++) {
    if(handles[i])
      curl_easy_cleanup(handles[i]);
  }
}

int test(char *URL)
{
  int res = 0;
  CURLM *m = NULL;
  CURLMsg *msg; /* for picking up messages with the transfer status */
  int msgs_left; /* how many messages are left */
  int running = 0;
  int handlenum = 0;
  struct timeval last_handle_add;

  if(parse_url_file(libtest_arg2) <= 0)
    goto test_cleanup;

  start_test_timing();

  curl_global_init(CURL_GLOBAL_ALL);

  multi_init(m);

  create_handles();

  multi_setopt(m, CURLMOPT_PIPELINING, 1L);
  multi_setopt(m, CURLMOPT_MAX_HOST_CONNECTIONS, 2L);
  multi_setopt(m, CURLMOPT_MAX_PIPELINE_LENGTH, 3L);
  multi_setopt(m, CURLMOPT_CONTENT_LENGTH_PENALTY_SIZE, 15000L);
  multi_setopt(m, CURLMOPT_CHUNK_LENGTH_PENALTY_SIZE, 10000L);

  multi_setopt(m, CURLMOPT_PIPELINING_SITE_BL, site_blacklist);
  multi_setopt(m, CURLMOPT_PIPELINING_SERVER_BL, server_blacklist);

  last_handle_add = tutil_tvnow();

  for(;;) {
    struct timeval interval;
    struct timeval now;
    fd_set rd, wr, exc;
    int maxfd = -99;
    long timeout;

    interval.tv_sec = 1;
    interval.tv_usec = 0;

    if(handlenum < num_handles) {
      now = tutil_tvnow();
      if(tutil_tvdiff(now, last_handle_add) >= urltime[handlenum]) {
        fprintf(stdout, "Adding handle %d\n", handlenum);
        setup_handle(URL, m, handlenum);
        last_handle_add = now;
        handlenum++;
      }
    }

    curl_multi_perform(m, &running);

    abort_on_test_timeout();

    /* See how the transfers went */
    do {
      msg = curl_multi_info_read(m, &msgs_left);
      if(msg && msg->msg == CURLMSG_DONE) {
        int i;

        /* Find out which handle this message is about */
        for(i = 0; i < num_handles; i++) {
          int found = (msg->easy_handle == handles[i]);
          if(found)
            break;
        }

        printf("Handle %d Completed with status %d\n", i, msg->data.result);
        curl_multi_remove_handle(m, handles[i]);
      }
    } while(msg);

    if(handlenum == num_handles && !running) {
      break; /* done */
    }

    FD_ZERO(&rd);
    FD_ZERO(&wr);
    FD_ZERO(&exc);

    curl_multi_fdset(m, &rd, &wr, &exc, &maxfd);

    /* At this point, maxfd is guaranteed to be greater or equal than -1. */

    curl_multi_timeout(m, &timeout);

    if(timeout < 0)
      timeout = 1;

    interval.tv_sec = timeout / 1000;
    interval.tv_usec = (timeout % 1000) * 1000;

    interval.tv_sec = 0;
    interval.tv_usec = 1000;

    select_test(maxfd + 1, &rd, &wr, &exc, &interval);

    abort_on_test_timeout();
  }

test_cleanup:

  remove_handles();

  /* undocumented cleanup sequence - type UB */

  curl_multi_cleanup(m);
  curl_global_cleanup();

  free_urls();
  return res;
}

