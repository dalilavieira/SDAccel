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
 int ENOBUFS ; 
 int ENOMEM ; 
 scalar_t__ strchr (char*,int) ; 

__attribute__((used)) static inline int ctype_whitespace(int c) { return c==' ' || c=='\n' || c=='\t'; }

__attribute__((used)) static inline int ctype_digit(int c) { return c>='0' && c<='9'; }

__attribute__((used)) static inline int ctype_alpha(int c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

__attribute__((used)) static inline int ctype_822special(int c) { return strchr("()<>@,;:\\\".[]",c) != 0; }

__attribute__((used)) static inline int ctype_domainunquoted(int c) {
  return ctype_alpha(c) || ctype_digit(c) || (strchr("-_/+",c) != 0);
}

__attribute__((used)) static inline int errno_resources(int e) { return e==ENOMEM || e==ENOBUFS; }

