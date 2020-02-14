#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  zend_string ;
struct timeval {int tv_sec; int tv_usec; } ;
typedef  void* php_socket_t ;
struct TYPE_3__ {int events; int revents; void* fd; } ;
typedef  TYPE_1__ php_pollfd ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 int /*<<< orphan*/  CWD_EXPAND ; 
 int /*<<< orphan*/ * VCWD_FOPEN (char const*,char const*) ; 
 int /*<<< orphan*/  efree (char*) ; 
 char* expand_filepath_with_mode (char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ php_check_open_basedir (char*) ; 
 int php_poll2 (TYPE_1__*,int,int) ; 
 int /*<<< orphan*/  strlen (char*) ; 
 int /*<<< orphan*/ * zend_string_init (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline int php_tvtoto(struct timeval *timeouttv)
{
	if (timeouttv) {
		return (timeouttv->tv_sec * 1000) + (timeouttv->tv_usec / 1000);
	}
	return -1;
}

__attribute__((used)) static inline int php_pollfd_for(php_socket_t fd, int events, struct timeval *timeouttv)
{
	php_pollfd p;
	int n;

	p.fd = fd;
	p.events = events;
	p.revents = 0;

	n = php_poll2(&p, 1, php_tvtoto(timeouttv));

	if (n > 0) {
		return p.revents;
	}

	return n;
}

__attribute__((used)) static inline int php_pollfd_for_ms(php_socket_t fd, int events, int timeout)
{
	php_pollfd p;
	int n;

	p.fd = fd;
	p.events = events;
	p.revents = 0;

	n = php_poll2(&p, 1, timeout);

	if (n > 0) {
		return p.revents;
	}

	return n;
}

__attribute__((used)) static FILE *php_fopen_and_set_opened_path(const char *path, const char *mode, zend_string **opened_path)
{
	FILE *fp;

	if (php_check_open_basedir((char *)path)) {
		return NULL;
	}
	fp = VCWD_FOPEN(path, mode);
	if (fp && opened_path) {
		//TODO :avoid reallocation
		char *tmp = expand_filepath_with_mode(path, NULL, NULL, 0, CWD_EXPAND);
		if (tmp) {
			*opened_path = zend_string_init(tmp, strlen(tmp), 0);
			efree(tmp);
		}
	}
	return fp;
}

