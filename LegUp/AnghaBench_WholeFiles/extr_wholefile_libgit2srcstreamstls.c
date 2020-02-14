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
struct TYPE_3__ {int (* init ) (int /*<<< orphan*/ **,char const*,char const*) ;int (* wrap ) (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*) ;int /*<<< orphan*/  member_0; } ;
typedef  TYPE_1__ git_stream_registration ;
typedef  int /*<<< orphan*/  git_stream ;

/* Variables and functions */
 int GIT_ENOTFOUND ; 
 int /*<<< orphan*/  GIT_ERROR_SSL ; 
 int /*<<< orphan*/  GIT_STREAM_TLS ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  git_error_set (int /*<<< orphan*/ ,char*) ; 
 int git_stream_registry_lookup (TYPE_1__*,int /*<<< orphan*/ ) ; 

int git_tls_stream_new(git_stream **out, const char *host, const char *port)
{
	int (*init)(git_stream **, const char *, const char *) = NULL;
	git_stream_registration custom = {0};
	int error;

	assert(out && host && port);

	if ((error = git_stream_registry_lookup(&custom, GIT_STREAM_TLS)) == 0) {
		init = custom.init;
	} else if (error == GIT_ENOTFOUND) {
#ifdef GIT_SECURE_TRANSPORT
		init = git_stransport_stream_new;
#elif defined(GIT_OPENSSL)
		init = git_openssl_stream_new;
#elif defined(GIT_MBEDTLS)
		init = git_mbedtls_stream_new;
#endif
	} else {
		return error;
	}

	if (!init) {
		git_error_set(GIT_ERROR_SSL, "there is no TLS stream available");
		return -1;
	}

	return init(out, host, port);
}

int git_tls_stream_wrap(git_stream **out, git_stream *in, const char *host)
{
	int (*wrap)(git_stream **, git_stream *, const char *) = NULL;
	git_stream_registration custom = {0};

	assert(out && in);

	if (git_stream_registry_lookup(&custom, GIT_STREAM_TLS) == 0) {
		wrap = custom.wrap;
	} else {
#ifdef GIT_SECURE_TRANSPORT
		wrap = git_stransport_stream_wrap;
#elif defined(GIT_OPENSSL)
		wrap = git_openssl_stream_wrap;
#elif defined(GIT_MBEDTLS)
		wrap = git_mbedtls_stream_wrap;
#endif
	}

	if (!wrap) {
		git_error_set(GIT_ERROR_SSL, "there is no TLS stream available");
		return -1;
	}

	return wrap(out, in, host);
}

