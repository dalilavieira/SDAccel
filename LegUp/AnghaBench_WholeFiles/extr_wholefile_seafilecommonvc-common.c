#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_59__   TYPE_6__ ;
typedef  struct TYPE_58__   TYPE_5__ ;
typedef  struct TYPE_57__   TYPE_3__ ;
typedef  struct TYPE_56__   TYPE_1__ ;
typedef  struct TYPE_55__   TYPE_15__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  time_t ;
typedef  int /*<<< orphan*/  gpointer ;
typedef  scalar_t__ gint64 ;
typedef  scalar_t__ gint ;
typedef  TYPE_1__* gconstpointer ;
typedef  int gboolean ;
typedef  scalar_t__ VCCompareResult ;
struct TYPE_59__ {TYPE_1__* data; struct TYPE_59__* next; } ;
struct TYPE_58__ {TYPE_6__* result; struct TYPE_58__* commit_hash; } ;
struct TYPE_57__ {TYPE_6__* entries; } ;
struct TYPE_56__ {scalar_t__ ctime; char* commit_id; char const* repo_id; int version; char const* parent_id; char* root_id; char const* second_parent_id; char const* creator_name; char* name; char const* modifier; scalar_t__ mtime; } ;
struct TYPE_55__ {int /*<<< orphan*/  fs_mgr; int /*<<< orphan*/  commit_mgr; } ;
typedef  TYPE_1__ SeafDirent ;
typedef  TYPE_3__ SeafDir ;
typedef  TYPE_1__ SeafCommit ;
typedef  TYPE_5__ MergeTraverseData ;
typedef  int /*<<< orphan*/  GString ;
typedef  TYPE_6__ GList ;
typedef  TYPE_5__ GHashTable ;
typedef  int /*<<< orphan*/  GError ;

/* Variables and functions */
 char* EMPTY_SHA1 ; 
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  SEAFILE_DOMAIN ; 
 int /*<<< orphan*/  SEAF_ERR_GENERAL ; 
 int TRUE ; 
 scalar_t__ VC_FAST_FORWARD ; 
 scalar_t__ VC_INDEPENDENT ; 
 scalar_t__ VC_UP_TO_DATE ; 
 TYPE_1__** calloc (int,int) ; 
 int /*<<< orphan*/  free (TYPE_1__**) ; 
 int /*<<< orphan*/  g_clear_error (int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  g_debug (char*) ; 
 int /*<<< orphan*/  g_free (char*) ; 
 int /*<<< orphan*/  g_hash_table_destroy (TYPE_5__*) ; 
 scalar_t__ g_hash_table_lookup (TYPE_5__*,char*) ; 
 TYPE_5__* g_hash_table_new_full (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/  (*) (char*),int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_hash_table_replace (TYPE_5__*,char*,char*) ; 
 TYPE_6__* g_list_append (TYPE_6__*,TYPE_1__*) ; 
 TYPE_6__* g_list_delete_link (TYPE_6__*,TYPE_6__*) ; 
 int /*<<< orphan*/  g_list_find_custom (TYPE_6__*,TYPE_1__*,scalar_t__ (*) (TYPE_1__*,TYPE_1__*)) ; 
 int /*<<< orphan*/  g_list_free (TYPE_6__*) ; 
 void* g_list_insert_sorted_with_data (TYPE_6__*,TYPE_1__*,scalar_t__ (*) (TYPE_1__*,TYPE_1__*,int /*<<< orphan*/ ),int /*<<< orphan*/ *) ; 
 int g_list_length (TYPE_6__*) ; 
 char* g_path_get_basename (char const*) ; 
 char* g_path_get_dirname (char const*) ; 
 int /*<<< orphan*/  g_set_error (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  g_str_equal ; 
 int /*<<< orphan*/  g_str_hash ; 
 char* g_strdup (char const*) ; 
 char* g_string_free (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * g_string_new (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  g_string_printf (int /*<<< orphan*/ *,char*,char*,char const*,...) ; 
 int /*<<< orphan*/  g_warning (char*,...) ; 
 int /*<<< orphan*/  localtime (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memcpy (char*,char const*,int) ; 
static  TYPE_6__* merge_bases_many (TYPE_1__*,int,TYPE_1__**) ; 
 TYPE_15__* seaf ; 
 TYPE_1__* seaf_commit_manager_get_commit (int /*<<< orphan*/ ,char const*,int,char const*) ; 
 int seaf_commit_manager_traverse_commit_tree (int /*<<< orphan*/ ,char const*,int,char const*,int (*) (TYPE_1__*,void*,int*),TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  seaf_commit_ref (TYPE_1__*) ; 
 int /*<<< orphan*/  seaf_commit_unref (TYPE_1__*) ; 
 int /*<<< orphan*/  seaf_dir_free (TYPE_3__*) ; 
 TYPE_3__* seaf_fs_manager_get_seafdir_by_path (int /*<<< orphan*/ ,char const*,int,char*,char*,int /*<<< orphan*/ *) ; 
 char* seaf_fs_manager_path_to_obj_id (int /*<<< orphan*/ ,char const*,int,char*,char const*,int /*<<< orphan*/ *,int /*<<< orphan*/ **) ; 
 int /*<<< orphan*/  seaf_warning (char*,char const*,...) ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 int /*<<< orphan*/  strftime (char*,int,char*,int /*<<< orphan*/ ) ; 
 char* strrchr (char*,char) ; 
 scalar_t__ vc_compare_commits (char const*,int,char const*,char const*) ; 

__attribute__((used)) static gint
compare_commit_by_time (gconstpointer a, gconstpointer b, gpointer unused)
{
    const SeafCommit *commit_a = a;
    const SeafCommit *commit_b = b;

    /* Latest commit comes first in the list. */
    return (commit_b->ctime - commit_a->ctime);
}

__attribute__((used)) static gint
compare_commit (gconstpointer a, gconstpointer b)
{
    const SeafCommit *commit_a = a;
    const SeafCommit *commit_b = b;

    return strcmp (commit_a->commit_id, commit_b->commit_id);
}

__attribute__((used)) static gboolean
add_to_commit_hash (SeafCommit *commit, void *vhash, gboolean *stop)
{
    GHashTable *hash = vhash;

    char *key = g_strdup (commit->commit_id);
    g_hash_table_replace (hash, key, key);

    return TRUE;
}

__attribute__((used)) static GHashTable *
commit_tree_to_hash (SeafCommit *head)
{
    GHashTable *hash;
    gboolean res;

    hash = g_hash_table_new_full (g_str_hash, g_str_equal, g_free, NULL);

    res = seaf_commit_manager_traverse_commit_tree (seaf->commit_mgr,
                                                    head->repo_id,
                                                    head->version,
                                                    head->commit_id,
                                                    add_to_commit_hash,
                                                    hash, FALSE);
    if (!res)
        goto fail;

    return hash;

fail:
    g_hash_table_destroy (hash);
    return NULL;
}

__attribute__((used)) static GList *
get_independent_commits (GList *commits)
{
    SeafCommit **rslt;
    GList *list, *result;
    int cnt, i, j;
    SeafCommit *c;

    g_debug ("Get independent commits.\n");

    cnt = g_list_length (commits);

    rslt = calloc(cnt, sizeof(*rslt));
    for (list = commits, i = 0; list; list = list->next)
        rslt[i++] = list->data;
    g_list_free (commits);

    for (i = 0; i < cnt - 1; i++) {
        for (j = i+1; j < cnt; j++) {
            if (!rslt[i] || !rslt[j])
                continue;
            result = merge_bases_many(rslt[i], 1, &rslt[j]);
            for (list = result; list; list = list->next) {
                c = list->data;
                /* If two commits have fast-forward relationship,
                 * drop the older one.
                 */
                if (strcmp (rslt[i]->commit_id, c->commit_id) == 0) {
                    seaf_commit_unref (rslt[i]);
                    rslt[i] = NULL;
                }
                if (strcmp (rslt[j]->commit_id, c->commit_id) == 0) {
                    seaf_commit_unref (rslt[j]);
                    rslt[j] = NULL;
                }
                seaf_commit_unref (c);
            }
        }
    }

    /* Surviving ones in rslt[] are the independent results */
    result = NULL;
    for (i = 0; i < cnt; i++) {
        if (rslt[i])
            result = g_list_insert_sorted_with_data (result, rslt[i],
                                                     compare_commit_by_time,
                                                     NULL);
    }
    free(rslt);
    return result;
}

__attribute__((used)) static gboolean
get_merge_bases (SeafCommit *commit, void *vdata, gboolean *stop)
{
    MergeTraverseData *data = vdata;

    /* Found a common ancestor.
     * Dont traverse its parenets.
     */
    if (g_hash_table_lookup (data->commit_hash, commit->commit_id)) {
        if (!g_list_find_custom (data->result, commit, compare_commit)) {
            data->result = g_list_insert_sorted_with_data (data->result, commit,
                                                     compare_commit_by_time,
                                                     NULL);
            seaf_commit_ref (commit);
        }
        *stop = TRUE;
    }

    return TRUE;
}

__attribute__((used)) static GList *
merge_bases_many (SeafCommit *one, int n, SeafCommit **twos)
{
    GHashTable *commit_hash;
    GList *result = NULL;
    SeafCommit *commit;
    int i;
    MergeTraverseData data;
    gboolean res;

    for (i = 0; i < n; i++) {
        if (one == twos[i])
            return g_list_append (result, one);
    }

    /* First construct a hash table of all commit ids rooted at one. */
    commit_hash = commit_tree_to_hash (one);
    if (!commit_hash) {
        g_warning ("Failed to load commit hash.\n");
        return NULL;
    }

    data.commit_hash = commit_hash;
    data.result = NULL;

    for (i = 0; i < n; i++) {
        res = seaf_commit_manager_traverse_commit_tree (seaf->commit_mgr,
                                                        twos[i]->repo_id,
                                                        twos[i]->version,
                                                        twos[i]->commit_id,
                                                        get_merge_bases,
                                                        &data, FALSE);
        if (!res)
            goto fail;
    }

    g_hash_table_destroy (commit_hash);
    result = data.result;

    if (!result || !result->next)
        return result;

    /* There are more than one. Try to find out independent ones. */
    result = get_independent_commits (result);

    return result;

fail:
    result = data.result;
    while (result) {
        commit = result->data;
        seaf_commit_unref (commit);
        result = g_list_delete_link (result, result);
    }
    g_hash_table_destroy (commit_hash);
    return NULL;
}

SeafCommit *
get_merge_base (SeafCommit *head, SeafCommit *remote)
{
    GList *result, *iter;
    SeafCommit *one, **twos;
    int n, i;
    SeafCommit *ret = NULL;

    one = head;
    twos = (SeafCommit **) calloc (1, sizeof(SeafCommit *));
    twos[0] = remote;
    n = 1;
    result = merge_bases_many (one, n, twos);
    free (twos);
    if (!result || !result->next)
        goto done;

    /*
     * More than one common ancestors.
     * Loop until the oldest common ancestor is found.
     */
    while (1) {
        n = g_list_length (result) - 1;
        one = result->data;
        twos = calloc (n, sizeof(SeafCommit *));
        for (iter = result->next, i = 0; i < n; iter = iter->next, i++) {
            twos[i] = iter->data;
        }
        g_list_free (result);

        result = merge_bases_many (one, n, twos);
        free (twos);
        if (!result || !result->next)
            break;
    }

done:
    if (result)
        ret = result->data;
    g_list_free (result);

    return ret;
}

gboolean
is_fast_forward (const char *repo_id, int version,
                 const char *src_head, const char *dst_head)
{
    VCCompareResult res;

    res = vc_compare_commits (repo_id, version, src_head, dst_head);

    return (res == VC_FAST_FORWARD);
}

VCCompareResult
vc_compare_commits (const char *repo_id, int version,
                    const char *c1, const char *c2)
{
    SeafCommit *commit1, *commit2, *ca;
    VCCompareResult ret;

    /* Treat the same as up-to-date. */
    if (strcmp (c1, c2) == 0)
        return VC_UP_TO_DATE;

    commit1 = seaf_commit_manager_get_commit (seaf->commit_mgr, repo_id, version, c1);
    if (!commit1)
        return VC_INDEPENDENT;

    commit2 = seaf_commit_manager_get_commit (seaf->commit_mgr, repo_id, version, c2);
    if (!commit2) {
        seaf_commit_unref (commit1);
        return VC_INDEPENDENT;
    }

    ca = get_merge_base (commit1, commit2);

    if (!ca)
        ret = VC_INDEPENDENT;
    else if (strcmp(ca->commit_id, commit1->commit_id) == 0)
        ret = VC_UP_TO_DATE;
    else if (strcmp(ca->commit_id, commit2->commit_id) == 0)
        ret = VC_FAST_FORWARD;
    else
        ret = VC_INDEPENDENT;

    if (ca) seaf_commit_unref (ca);
    seaf_commit_unref (commit1);
    seaf_commit_unref (commit2);
    return ret;
}

__attribute__((used)) static int
diff_parents_with_path (SeafCommit *commit,
                        const char *repo_id,
                        const char *store_id,
                        int version,
                        const char *path,
                        const char *file_id,
                        char *parent,
                        GError **error)
{
    SeafCommit *p1 = NULL, *p2 = NULL;
    char *file_id_p1 = NULL, *file_id_p2 = NULL;
    int ret = 0;

    p1 = seaf_commit_manager_get_commit (seaf->commit_mgr,
                                         commit->repo_id,
                                         commit->version,
                                         commit->parent_id);
    if (!p1) {
        g_warning ("Failed to find commit %s.\n", commit->parent_id);
        g_set_error (error, SEAFILE_DOMAIN, SEAF_ERR_GENERAL, " ");
        return 0;
    }

    if (strcmp (p1->root_id, EMPTY_SHA1) == 0) {
        seaf_commit_unref (p1);
        return 1;
    }

    if (commit->second_parent_id) {
        p2 = seaf_commit_manager_get_commit (seaf->commit_mgr,
                                             commit->repo_id,
                                             commit->version,
                                             commit->second_parent_id);
        if (!p2) {
            g_warning ("Failed to find commit %s.\n", commit->second_parent_id);
            seaf_commit_unref (p1);
            g_set_error (error, SEAFILE_DOMAIN, SEAF_ERR_GENERAL, " ");
            return 0;
        }
    }

    if (!p2) {
        file_id_p1 = seaf_fs_manager_path_to_obj_id (seaf->fs_mgr,
                                                     store_id,
                                                     version,
                                                     p1->root_id, path,
                                                     NULL,
                                                     error);
        if (*error)
            goto out;
        if (!file_id_p1 || strcmp (file_id, file_id_p1) != 0)
            ret = 1;
        else
            memcpy (parent, p1->commit_id, 41);
    } else {
        file_id_p1 = seaf_fs_manager_path_to_obj_id (seaf->fs_mgr,
                                                     store_id,
                                                     version,
                                                     p1->root_id, path,
                                                     NULL, error);
        if (*error)
            goto out;
        file_id_p2 = seaf_fs_manager_path_to_obj_id (seaf->fs_mgr,
                                                     store_id,
                                                     version,
                                                     p2->root_id, path,
                                                     NULL, error);
        if (*error)
            goto out;

        if (file_id_p1 && file_id_p2) {
            if (strcmp(file_id, file_id_p1) != 0 &&
                strcmp(file_id, file_id_p2) != 0)
                ret = 1;
            else if (strcmp(file_id, file_id_p1) == 0)
                memcpy (parent, p1->commit_id, 41);
            else
                memcpy (parent, p2->commit_id, 41);
        } else if (file_id_p1 && !file_id_p2) {
            if (strcmp(file_id, file_id_p1) != 0)
                ret = 1;
            else
                memcpy (parent, p1->commit_id, 41);
        } else if (!file_id_p1 && file_id_p2) {
            if (strcmp(file_id, file_id_p2) != 0)
                ret = 1;
            else
                memcpy (parent, p2->commit_id, 41);
        } else {
            ret = 1;
        }
    }

out:
    g_free (file_id_p1);
    g_free (file_id_p2);

    if (p1)
        seaf_commit_unref (p1);
    if (p2)
        seaf_commit_unref (p2);

    return ret;
}

__attribute__((used)) static int
get_file_modifier_mtime_v0 (const char *repo_id, const char *store_id, int version,
                            const char *head, const char *path,
                            char **modifier, gint64 *mtime)
{
    char commit_id[41];
    SeafCommit *commit = NULL;
    char *file_id = NULL;
    int changed;
    int ret = 0;
    GError *error = NULL;

    *modifier = NULL;
    *mtime = 0;

    memcpy (commit_id, head, 41);

    while (1) {
        commit = seaf_commit_manager_get_commit (seaf->commit_mgr,
                                                 repo_id, version,
                                                 commit_id);
        if (!commit) {
            ret = -1;
            break;
        }

        /* We hit the initial commit. */
        if (!commit->parent_id)
            break;

        file_id = seaf_fs_manager_path_to_obj_id (seaf->fs_mgr,
                                                  store_id, version,
                                                  commit->root_id,
                                                  path,
                                                  NULL,
                                                  &error);
        if (error) {
            g_clear_error (&error);
            ret = -1;
            break;
        }
        /* We expect commit to have this file. */
        if (!file_id) {
            ret = -1;
            break;
        }

        changed = diff_parents_with_path (commit,
                                          repo_id, store_id, version,
                                          path, file_id,
                                          commit_id, &error);
        if (error) {
            g_clear_error (&error);
            ret = -1;
            break;
        }

        if (changed) {
            *modifier = g_strdup (commit->creator_name);
            *mtime = commit->ctime;
            break;
        } else {
            /* If this commit doesn't change the file, commit_id will be set
             * to the parent commit to traverse.
             */
            g_free (file_id);
            seaf_commit_unref (commit);
        }
    }

    g_free (file_id);
    if (commit)
        seaf_commit_unref (commit);
    return ret;
}

__attribute__((used)) static int
get_file_modifier_mtime_v1 (const char *repo_id, const char *store_id, int version,
                            const char *head, const char *path,
                            char **modifier, gint64 *mtime)
{
    SeafCommit *commit = NULL;
    SeafDir *dir = NULL;
    SeafDirent *dent = NULL;
    int ret = 0;

    commit = seaf_commit_manager_get_commit (seaf->commit_mgr,
                                             repo_id, version,
                                             head);
    if (!commit) {
        seaf_warning ("Failed to get commit %s.\n", head);
        return -1;
    }

    char *parent = g_path_get_dirname (path);
    if (strcmp(parent, ".") == 0) {
        g_free (parent);
        parent = g_strdup("");
    }
    char *filename = g_path_get_basename (path);

    dir = seaf_fs_manager_get_seafdir_by_path (seaf->fs_mgr,
                                               store_id, version,
                                               commit->root_id,
                                               parent, NULL);
    if (!dir) {
        seaf_warning ("dir %s doesn't exist in repo %s.\n", parent, repo_id);
        ret = -1;
        goto out;
    }

    GList *p;
    for (p = dir->entries; p; p = p->next) {
        SeafDirent *d = p->data;
        if (strcmp (d->name, filename) == 0) {
            dent = d;
            break;
        }
    }

    if (!dent) {
        goto out;
    }

    *modifier = g_strdup(dent->modifier);
    *mtime = dent->mtime;

out:
    g_free (parent);
    g_free (filename);
    seaf_commit_unref (commit);
    seaf_dir_free (dir);

    return ret;
}

int
get_file_modifier_mtime (const char *repo_id,
                         const char *store_id,
                         int version,
                         const char *head,
                         const char *path,
                         char **modifier,
                         gint64 *mtime)
{
    if (version > 0)
        return get_file_modifier_mtime_v1 (repo_id, store_id, version,
                                           head, path,
                                           modifier, mtime);
    else
        return get_file_modifier_mtime_v0 (repo_id, store_id, version,
                                           head, path,
                                           modifier, mtime);
}

char *
gen_conflict_path (const char *origin_path,
                   const char *modifier,
                   gint64 mtime)
{
    char time_buf[64];
    time_t t = (time_t)mtime;
    char *copy = g_strdup (origin_path);
    GString *conflict_path = g_string_new (NULL);
    char *dot, *ext;

    strftime(time_buf, 64, "%Y-%m-%d-%H-%M-%S", localtime(&t));

    dot = strrchr (copy, '.');

    if (dot != NULL) {
        *dot = '\0';
        ext = dot + 1;
        if (modifier)
            g_string_printf (conflict_path, "%s (SFConflict %s %s).%s",
                             copy, modifier, time_buf, ext);
        else
            g_string_printf (conflict_path, "%s (SFConflict %s).%s",
                             copy, time_buf, ext);
    } else {
        if (modifier)
            g_string_printf (conflict_path, "%s (SFConflict %s %s)",
                             copy, modifier, time_buf);
        else
            g_string_printf (conflict_path, "%s (SFConflict %s)",
                             copy, time_buf);
    }

    g_free (copy);
    return g_string_free (conflict_path, FALSE);
}

char *
gen_conflict_path_wrapper (const char *repo_id, int version,
                           const char *head, const char *in_repo_path,
                           const char *original_path)
{
    char *modifier;
    gint64 mtime;

    /* XXX: this function is only used in client, so store_id is always
     * the same as repo_id. This can be changed if it's also called in
     * server.
     */
    if (get_file_modifier_mtime (repo_id, repo_id, version, head, in_repo_path,
                                 &modifier, &mtime) < 0)
        return NULL;

    return gen_conflict_path (original_path, modifier, mtime);
}

