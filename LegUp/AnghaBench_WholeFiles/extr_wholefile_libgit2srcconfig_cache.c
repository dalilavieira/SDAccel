#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct map_data {int default_value; int /*<<< orphan*/  map_count; scalar_t__ maps; int /*<<< orphan*/  cvar_name; } ;
struct TYPE_8__ {int* cvar_cache; } ;
typedef  TYPE_1__ git_repository ;
typedef  scalar_t__ git_cvar_cached ;
struct TYPE_9__ {int /*<<< orphan*/  value; } ;
typedef  TYPE_2__ git_config_entry ;
typedef  int /*<<< orphan*/  git_config ;

/* Variables and functions */
 int GIT_CVAR_CACHE_MAX ; 
 int GIT_CVAR_NOT_CACHED ; 
 struct map_data* _cvar_maps ; 
 int git_config__lookup_entry (TYPE_2__**,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  git_config_entry_free (TYPE_2__*) ; 
 int git_config_lookup_map_value (int*,scalar_t__,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int git_config_parse_bool (int*,int /*<<< orphan*/ ) ; 
 int git_repository_config__weakptr (int /*<<< orphan*/ **,TYPE_1__*) ; 

int git_config__cvar(int *out, git_config *config, git_cvar_cached cvar)
{
	int error = 0;
	struct map_data *data = &_cvar_maps[(int)cvar];
	git_config_entry *entry;

	if ((error = git_config__lookup_entry(&entry, config, data->cvar_name, false)) < 0)
		return error;

	if (!entry)
		*out = data->default_value;
	else if (data->maps)
		error = git_config_lookup_map_value(
			out, data->maps, data->map_count, entry->value);
	else
		error = git_config_parse_bool(out, entry->value);

	git_config_entry_free(entry);
	return error;
}

int git_repository__cvar(int *out, git_repository *repo, git_cvar_cached cvar)
{
	*out = repo->cvar_cache[(int)cvar];

	if (*out == GIT_CVAR_NOT_CACHED) {
		int error;
		git_config *config;

		if ((error = git_repository_config__weakptr(&config, repo)) < 0 ||
			(error = git_config__cvar(out, config, cvar)) < 0)
			return error;

		repo->cvar_cache[(int)cvar] = *out;
	}

	return 0;
}

void git_repository__cvar_cache_clear(git_repository *repo)
{
	int i;

	for (i = 0; i < GIT_CVAR_CACHE_MAX; ++i)
		repo->cvar_cache[i] = GIT_CVAR_NOT_CACHED;
}

