#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct part {int member_0; char* member_1; int part; scalar_t__ name; } ;
typedef  int /*<<< orphan*/  buf ;
struct TYPE_10__ {char* in; unsigned int urlflags; char* q; unsigned int qflags; int ucode; char* out; } ;
struct TYPE_9__ {char* in; unsigned int urlflags; int ucode; char* out; unsigned int getflags; } ;
struct TYPE_8__ {char* in; unsigned int urlflags; unsigned int getflags; char* out; int ucode; } ;
struct TYPE_7__ {char* set; char* in; unsigned int urlflags; unsigned int setflags; int pcode; char* out; int ucode; } ;
struct TYPE_6__ {char* in; unsigned int urlflags; char* set; unsigned int setflags; char* out; int ucode; } ;
typedef  int CURLUcode ;
typedef  int CURLUPart ;
typedef  int /*<<< orphan*/  CURLU ;

/* Variables and functions */
 int CURLUE_OK ; 
 int CURLUPART_FRAGMENT ; 
 int CURLUPART_HOST ; 
 int CURLUPART_OPTIONS ; 
 int CURLUPART_PASSWORD ; 
 int CURLUPART_PATH ; 
 int CURLUPART_PORT ; 
 int CURLUPART_QUERY ; 
 int CURLUPART_SCHEME ; 
 int CURLUPART_URL ; 
 int CURLUPART_USER ; 
 unsigned int CURLU_APPENDQUERY ; 
 TYPE_5__* append_list ; 
 int /*<<< orphan*/  curl_free (char*) ; 
 int /*<<< orphan*/ * curl_url () ; 
 int /*<<< orphan*/  curl_url_cleanup (int /*<<< orphan*/ *) ; 
 int curl_url_get (int /*<<< orphan*/ *,int,char**,unsigned int) ; 
 int curl_url_set (int /*<<< orphan*/ *,int,char*,unsigned int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,...) ; 
 TYPE_4__* get_parts_list ; 
 TYPE_3__* get_url_list ; 
 int /*<<< orphan*/  memcpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/  msnprintf (char*,size_t,char*,char*,...) ; 
 int /*<<< orphan*/  printf (char*) ; 
 TYPE_2__* set_parts_list ; 
 TYPE_1__* set_url_list ; 
 int sscanf (char*,char*,char*,char*) ; 
 int /*<<< orphan*/  stderr ; 
 char* strchr (char const*,char) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 size_t strlen (char*) ; 

__attribute__((used)) static int checkparts(CURLU *u, const char *in, const char *wanted,
                      unsigned int getflags)
{
  int i;
  CURLUcode rc;
  char buf[256];
  char *bufp = &buf[0];
  size_t len = sizeof(buf);
  struct part parts[] = {
    {CURLUPART_SCHEME, "scheme"},
    {CURLUPART_USER, "user"},
    {CURLUPART_PASSWORD, "password"},
    {CURLUPART_OPTIONS, "options"},
    {CURLUPART_HOST, "host"},
    {CURLUPART_PORT, "port"},
    {CURLUPART_PATH, "path"},
    {CURLUPART_QUERY, "query"},
    {CURLUPART_FRAGMENT, "fragment"},
    {0, NULL}
  };
  buf[0] = 0;

  for(i = 0; parts[i].name; i++) {
    char *p = NULL;
    size_t n;
    rc = curl_url_get(u, parts[i].part, &p, getflags);
    if(!rc && p) {
      msnprintf(bufp, len, "%s%s", buf[0]?" | ":"", p);
    }
    else
      msnprintf(bufp, len, "%s[%d]", buf[0]?" | ":"", (int)rc);

    n = strlen(bufp);
    bufp += n;
    len -= n;
    curl_free(p);
  }
  if(strcmp(buf, wanted)) {
    fprintf(stderr, "in: %s\nwanted: %s\ngot:    %s\n", in, wanted, buf);
    return 1;
  }
  return 0;
}

__attribute__((used)) static int checkurl(const char *url, const char *out)
{
  if(strcmp(out, url)) {
    fprintf(stderr, "Wanted: %s\nGot   : %s\n",
            out, url);
    return 1;
  }
  return 0;
}

__attribute__((used)) static CURLUPart part2id(char *part)
{
  if(!strcmp("url", part))
    return CURLUPART_URL;
  if(!strcmp("scheme", part))
    return CURLUPART_SCHEME;
  if(!strcmp("user", part))
    return CURLUPART_USER;
  if(!strcmp("password", part))
    return CURLUPART_PASSWORD;
  if(!strcmp("options", part))
    return CURLUPART_OPTIONS;
  if(!strcmp("host", part))
    return CURLUPART_HOST;
  if(!strcmp("port", part))
    return CURLUPART_PORT;
  if(!strcmp("path", part))
    return CURLUPART_PATH;
  if(!strcmp("query", part))
    return CURLUPART_QUERY;
  if(!strcmp("fragment", part))
    return CURLUPART_FRAGMENT;
  return 9999; /* bad input => bad output */
}

__attribute__((used)) static CURLUcode updateurl(CURLU *u, const char *cmd, unsigned int setflags)
{
  const char *p = cmd;
  CURLUcode uc;

  /* make sure the last command ends with a comma too! */
  while(p) {
    char *e = strchr(p, ',');
    if(e) {
      size_t n = e-p;
      char buf[80];
      char part[80];
      char value[80];
      memcpy(buf, p, n);
      buf[n] = 0;
      if(2 == sscanf(buf, "%79[^=]=%79[^,]", part, value)) {
        CURLUPart what = part2id(part);
#if 0
        /* for debugging this */
        fprintf(stderr, "%s = %s [%d]\n", part, value, (int)what);
#endif
        if(!strcmp("NULL", value))
          uc = curl_url_set(u, what, NULL, setflags);
        else if(!strcmp("\"\"", value))
          uc = curl_url_set(u, what, "", setflags);
        else
          uc = curl_url_set(u, what, value, setflags);
        if(uc)
          return uc;
      }
      p = e + 1;
      continue;
    }
    break;
  }
  return CURLUE_OK;
}

__attribute__((used)) static int set_url(void)
{
  int i;
  CURLUcode rc;
  CURLU *urlp;
  int error = 0;

  for(i = 0; set_url_list[i].in && !error; i++) {
    char *url = NULL;
    urlp = curl_url();
    if(!urlp)
      break;
    rc = curl_url_set(urlp, CURLUPART_URL, set_url_list[i].in,
                      set_url_list[i].urlflags);
    if(!rc) {
      rc = curl_url_set(urlp, CURLUPART_URL, set_url_list[i].set,
                        set_url_list[i].setflags);
      if(rc) {
        fprintf(stderr, "%s:%d Set URL %s returned %d\n",
                __FILE__, __LINE__, set_url_list[i].set,
                (int)rc);
        error++;
      }
      else {
        rc = curl_url_get(urlp, CURLUPART_URL, &url, 0);
        if(rc) {
          fprintf(stderr, "%s:%d Get URL returned %d\n",
                  __FILE__, __LINE__, (int)rc);
          error++;
        }
        else {
          if(checkurl(url, set_url_list[i].out)) {
            error++;
          }
        }
      }
      curl_free(url);
    }
    else if(rc != set_url_list[i].ucode) {
      fprintf(stderr, "Set URL\nin: %s\nreturned %d (expected %d)\n",
              set_url_list[i].in, (int)rc, set_url_list[i].ucode);
      error++;
    }
    curl_url_cleanup(urlp);
  }
  return error;
}

__attribute__((used)) static int set_parts(void)
{
  int i;
  CURLUcode rc;
  int error = 0;

  for(i = 0; set_parts_list[i].set && !error; i++) {
    char *url = NULL;
    CURLU *urlp = curl_url();
    if(!urlp) {
      error++;
      break;
    }
    if(set_parts_list[i].in)
      rc = curl_url_set(urlp, CURLUPART_URL, set_parts_list[i].in,
                        set_parts_list[i].urlflags);
    else
      rc = CURLUE_OK;
    if(!rc) {
      CURLUcode uc = updateurl(urlp, set_parts_list[i].set,
                               set_parts_list[i].setflags);

      if(uc != set_parts_list[i].pcode) {
        fprintf(stderr, "updateurl\nin: %s\nreturned %d (expected %d)\n",
                set_parts_list[i].set, (int)uc, set_parts_list[i].pcode);
        error++;
      }

      rc = curl_url_get(urlp, CURLUPART_URL, &url, 0);

      if(rc) {
        fprintf(stderr, "%s:%d Get URL returned %d\n",
                __FILE__, __LINE__, (int)rc);
        error++;
      }
      else if(checkurl(url, set_parts_list[i].out)) {
        error++;
      }
    }
    else if(rc != set_parts_list[i].ucode) {
      fprintf(stderr, "Set parts\nin: %s\nreturned %d (expected %d)\n",
              set_parts_list[i].in, (int)rc, set_parts_list[i].ucode);
      error++;
    }
    curl_free(url);
    curl_url_cleanup(urlp);
  }
  return error;
}

__attribute__((used)) static int get_url(void)
{
  int i;
  CURLUcode rc;
  int error = 0;
  for(i = 0; get_url_list[i].in && !error; i++) {
    char *url = NULL;
    CURLU *urlp = curl_url();
    if(!urlp) {
      error++;
      break;
    }
    rc = curl_url_set(urlp, CURLUPART_URL, get_url_list[i].in,
                      get_url_list[i].urlflags);
    if(!rc) {
      rc = curl_url_get(urlp, CURLUPART_URL, &url, get_url_list[i].getflags);

      if(rc) {
        fprintf(stderr, "%s:%d returned %d\n",
                __FILE__, __LINE__, (int)rc);
        error++;
      }
      else {
        if(checkurl(url, get_url_list[i].out)) {
          error++;
        }
      }
    }
    else if(rc != get_url_list[i].ucode) {
      fprintf(stderr, "Get URL\nin: %s\nreturned %d (expected %d)\n",
              get_url_list[i].in, (int)rc, get_url_list[i].ucode);
      error++;
    }
    curl_free(url);
    curl_url_cleanup(urlp);
  }
  return error;
}

__attribute__((used)) static int get_parts(void)
{
  int i;
  CURLUcode rc;
  CURLU *urlp;
  int error = 0;
  for(i = 0; get_parts_list[i].in && !error; i++) {
    urlp = curl_url();
    if(!urlp) {
      error++;
      break;
    }
    rc = curl_url_set(urlp, CURLUPART_URL,
                      get_parts_list[i].in,
                      get_parts_list[i].urlflags);
    if(rc != get_parts_list[i].ucode) {
      fprintf(stderr, "Get parts\nin: %s\nreturned %d (expected %d)\n",
              get_parts_list[i].in, (int)rc, get_parts_list[i].ucode);
      error++;
    }
    else if(get_parts_list[i].ucode) {
      /* the expected error happened */
    }
    else if(checkparts(urlp, get_parts_list[i].in, get_parts_list[i].out,
                       get_parts_list[i].getflags))
      error++;
    curl_url_cleanup(urlp);
  }
  return error;
}

__attribute__((used)) static int append(void)
{
  int i;
  CURLUcode rc;
  CURLU *urlp;
  int error = 0;
  for(i = 0; append_list[i].in && !error; i++) {
    urlp = curl_url();
    if(!urlp) {
      error++;
      break;
    }
    rc = curl_url_set(urlp, CURLUPART_URL,
                      append_list[i].in,
                      append_list[i].urlflags);
    if(rc)
      error++;
    else
      rc = curl_url_set(urlp, CURLUPART_QUERY,
                        append_list[i].q,
                        append_list[i].qflags | CURLU_APPENDQUERY);
    if(error)
      ;
    else if(rc != append_list[i].ucode) {
      fprintf(stderr, "Append\nin: %s\nreturned %d (expected %d)\n",
              append_list[i].in, (int)rc, append_list[i].ucode);
      error++;
    }
    else if(append_list[i].ucode) {
      /* the expected error happened */
    }
    else {
      char *url;
      rc = curl_url_get(urlp, CURLUPART_URL, &url, 0);
      if(rc) {
        fprintf(stderr, "%s:%d Get URL returned %d\n",
                __FILE__, __LINE__, (int)rc);
        error++;
      }
      else {
        if(checkurl(url, append_list[i].out)) {
          error++;
        }
        curl_free(url);
      }
    }
    curl_url_cleanup(urlp);
  }
  return error;
}

int test(char *URL)
{
  (void)URL; /* not used */

  if(append())
    return 5;

  if(set_url())
    return 1;

  if(set_parts())
    return 2;

  if(get_url())
    return 3;

  if(get_parts())
    return 4;

  printf("success\n");
  return 0;
}

