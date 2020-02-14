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
 int UV_EINVAL ; 
 int UV_ENOBUFS ; 
 int UV_ENOMEM ; 
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  memcpy (char*,char*,size_t) ; 
 char* process_title ; 
 int /*<<< orphan*/  process_title_mutex ; 
 int /*<<< orphan*/  process_title_mutex_once ; 
 int /*<<< orphan*/  setproctitle (char*,char const*) ; 
 int strlen (char*) ; 
 int /*<<< orphan*/  uv__free (char*) ; 
 char* uv__strdup (char const*) ; 
 scalar_t__ uv_mutex_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_mutex_unlock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  uv_once (int /*<<< orphan*/ *,void (*) ()) ; 

__attribute__((used)) static void init_process_title_mutex_once(void) {
  if (uv_mutex_init(&process_title_mutex))
    abort();
}

char** uv_setup_args(int argc, char** argv) {
  process_title = argc > 0 ? uv__strdup(argv[0]) : NULL;
  return argv;
}

int uv_set_process_title(const char* title) {
  char* new_title;

  new_title = uv__strdup(title);
  if (new_title == NULL)
    return UV_ENOMEM;

  uv_once(&process_title_mutex_once, init_process_title_mutex_once);
  uv_mutex_lock(&process_title_mutex);

  uv__free(process_title);
  process_title = new_title;
  setproctitle("%s", title);

  uv_mutex_unlock(&process_title_mutex);

  return 0;
}

int uv_get_process_title(char* buffer, size_t size) {
  size_t len;

  if (buffer == NULL || size == 0)
    return UV_EINVAL;

  uv_once(&process_title_mutex_once, init_process_title_mutex_once);
  uv_mutex_lock(&process_title_mutex);

  if (process_title != NULL) {
    len = strlen(process_title) + 1;

    if (size < len) {
      uv_mutex_unlock(&process_title_mutex);
      return UV_ENOBUFS;
    }

    memcpy(buffer, process_title, len);
  } else {
    len = 0;
  }

  uv_mutex_unlock(&process_title_mutex);

  buffer[len] = '\0';

  return 0;
}

