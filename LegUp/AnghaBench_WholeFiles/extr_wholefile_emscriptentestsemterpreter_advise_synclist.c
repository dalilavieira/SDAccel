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
 int /*<<< orphan*/  test ; 

void l() { test++; }

void k() { test++; }

void j() { test++; }

void i() { test++; }

void h() { test++; }

void g() { l(); test++; }

void f() { k(); test++; }

void e() { i(); j(); test++; }

void d() { test++; }

void c() { g(); h(); test++; }

void b() { f(); g(); test++; }

void a() { d(); e(); f(); test++; }

int main() { a(); b(); b(); }

