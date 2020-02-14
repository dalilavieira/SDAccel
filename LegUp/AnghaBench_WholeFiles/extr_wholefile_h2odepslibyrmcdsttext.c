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
typedef  scalar_t__ yrmcds_error ;
typedef  int /*<<< orphan*/  yrmcds ;
typedef  int uint16_t ;

/* Variables and functions */
 scalar_t__ YRMCDS_OK ; 
 scalar_t__ atoi (char*) ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 char* getenv (char*) ; 
 scalar_t__ n_failures ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  test_main (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  yrmcds_close (int /*<<< orphan*/ *) ; 
 scalar_t__ yrmcds_connect (int /*<<< orphan*/ *,char const*,int) ; 
 char* yrmcds_strerror (scalar_t__) ; 

__attribute__((used)) static void check_error(yrmcds_error e) {
    if( e == YRMCDS_OK )
        return;

    fprintf(stderr, "yrmcds error: %s\n", yrmcds_strerror(e));
    exit(1);
}

__attribute__((used)) static yrmcds* get_yrmcds(yrmcds* c) {
    const char* host = getenv("YRMCDS_HOST");
    if( host == NULL ) {
        return NULL;
    }
    uint16_t port = 11211;
    if( getenv("YRMCDS_PORT") ) {
        port = (uint16_t)atoi(getenv("YRMCDS_PORT"));
    }

    check_error( yrmcds_connect(c, host, port) );
    return c;
}

int main(int argc, char** argv) {
    yrmcds c_;
    yrmcds* c = get_yrmcds(&c_);
    if( c == NULL ) {
        fprintf(stderr, "No YRMCDS_HOST.  Skipped.\n");
        return 0;
    }

    test_main(c);
    yrmcds_close(c);

    if( n_failures > 0 ) {
        fprintf(stderr, "%d tests failed.\n", n_failures);
        return 1;
    }
    fprintf(stderr, "Passed.\n");
    return 0;
}

