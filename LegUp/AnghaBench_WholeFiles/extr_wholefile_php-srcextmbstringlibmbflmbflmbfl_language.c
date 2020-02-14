#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char const* name; char const* short_name; char const*** aliases; int no_language; } ;
typedef  TYPE_1__ mbfl_language ;
typedef  enum mbfl_no_language { ____Placeholder_mbfl_no_language } mbfl_no_language ;

/* Variables and functions */
 TYPE_1__** mbfl_language_ptr_table ; 
 int mbfl_no_language_invalid ; 
 scalar_t__ strcasecmp (char const*,char const*) ; 

const mbfl_language *
mbfl_name2language(const char *name)
{
	const mbfl_language *language;
	int i, j;

	if (name == NULL) {
		return NULL;
	}

	i = 0;
	while ((language = mbfl_language_ptr_table[i++]) != NULL){
		if (strcasecmp(language->name, name) == 0) {
			return language;
		}
	}

	i = 0;
	while ((language = mbfl_language_ptr_table[i++]) != NULL){
		if (strcasecmp(language->short_name, name) == 0) {
			return language;
		}
	}

	/* serch aliases */
	i = 0;
	while ((language = mbfl_language_ptr_table[i++]) != NULL) {
		if (language->aliases != NULL) {
			j = 0;
			while ((*language->aliases)[j] != NULL) {
				if (strcasecmp((*language->aliases)[j], name) == 0) {
					return language;
				}
				j++;
			}
		}
	}

	return NULL;
}

const mbfl_language *
mbfl_no2language(enum mbfl_no_language no_language)
{
	const mbfl_language *language;
	int i;

	i = 0;
	while ((language = mbfl_language_ptr_table[i++]) != NULL){
		if (language->no_language == no_language) {
			return language;
		}
	}

	return NULL;
}

enum mbfl_no_language
mbfl_name2no_language(const char *name)
{
	const mbfl_language *language;

	language = mbfl_name2language(name);
	if (language == NULL) {
		return mbfl_no_language_invalid;
	} else {
		return language->no_language;
	}
}

const char *
mbfl_no_language2name(enum mbfl_no_language no_language)
{
	const mbfl_language *language;

	language = mbfl_no2language(no_language);
	if (language == NULL) {
		return "";
	} else {
		return language->name;
	}
}

