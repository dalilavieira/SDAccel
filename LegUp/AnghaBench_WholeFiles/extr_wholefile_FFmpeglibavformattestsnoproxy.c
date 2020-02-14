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
 int ff_http_match_no_proxy (char const*,char const*) ; 
 int /*<<< orphan*/  printf (char*,char const*,char*,char const*) ; 

__attribute__((used)) static void test(const char *pattern, const char *host)
{
    int res = ff_http_match_no_proxy(pattern, host);
    printf("The pattern \"%s\" %s the hostname %s\n",
           pattern ? pattern : "(null)", res ? "matches" : "does not match",
           host);
}

int main(void)
{
    test(NULL, "domain.com");
    test("example.com domain.com", "domain.com");
    test("example.com other.com", "domain.com");
    test("example.com,domain.com", "domain.com");
    test("example.com,domain.com", "otherdomain.com");
    test("example.com, *.domain.com", "sub.domain.com");
    test("example.com, *.domain.com", "domain.com");
    test("example.com, .domain.com", "domain.com");
    test("*", "domain.com");
    return 0;
}

