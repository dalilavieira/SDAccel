#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct __locale_map {int dummy; } ;
struct TYPE_2__ {struct __locale_map const** cat; } ;

/* Variables and functions */
 TYPE_1__* CURRENT_LOCALE ; 
 size_t LC_MESSAGES ; 
 char const* __lctrans_impl (char const*,struct __locale_map const*) ; 

__attribute__((used)) static const char *dummy(const char *msg, const struct __locale_map *lm)
{
	return msg;
}

const char *__lctrans(const char *msg, const struct __locale_map *lm)
{
	return __lctrans_impl(msg, lm);
}

const char *__lctrans_cur(const char *msg)
{
	return __lctrans_impl(msg, CURRENT_LOCALE->cat[LC_MESSAGES]);
}

