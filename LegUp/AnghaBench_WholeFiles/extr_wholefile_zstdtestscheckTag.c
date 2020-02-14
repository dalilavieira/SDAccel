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
 char* ZSTD_VERSION_STRING ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 size_t strlen (char const* const) ; 
 scalar_t__ strncmp (char*,char const* const,size_t const) ; 

__attribute__((used)) static int validate(const char* const tag)
{
    size_t const tagLength = strlen(tag);
    size_t const verLength = strlen(ZSTD_VERSION_STRING);

    if (tagLength < 2) return 0;
    if (tag[0] != 'v') return 0;
    if (tagLength <= verLength) return 0;

    if (strncmp(ZSTD_VERSION_STRING, tag+1, verLength)) return 0;

    return 1;
}

int main(int argc, const char** argv)
{
    const char* const exeName = argv[0];
    const char* const tag = argv[1];
    if (argc!=2) {
        printf("incorrect usage : %s tag \n", exeName);
        return 2;
    }

    printf("Version : %s \n", ZSTD_VERSION_STRING);
    printf("Tag     : %s \n", tag);

    if (validate(tag)) {
        printf("OK : tag is compatible with zstd version \n");
        return 0;
    }

    printf("!! error : tag and versions are not compatible !! \n");
    return 1;
}

