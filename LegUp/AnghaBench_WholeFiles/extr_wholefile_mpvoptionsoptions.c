#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;

/* Type definitions */
struct mpv_node {int dummy; } ;
struct mp_log {int dummy; } ;
struct bstr {int dummy; } ;
struct TYPE_17__ {TYPE_1__* type; } ;
typedef  TYPE_2__ m_option_t ;
struct TYPE_16__ {int (* parse ) (struct mp_log*,TYPE_2__ const*,struct bstr,struct bstr,void*) ;char* (* print ) (TYPE_2__ const*,void const*) ;char* (* pretty_print ) (TYPE_2__ const*,void const*) ;int (* set ) (TYPE_2__ const*,void*,struct mpv_node*) ;int (* get ) (TYPE_2__ const*,void*,struct mpv_node*,void*) ;int /*<<< orphan*/  (* free ) (void*) ;int /*<<< orphan*/  (* copy ) (TYPE_2__ const*,void*,void const*) ;} ;

/* Variables and functions */
 int M_OPT_UNKNOWN ; 
 int /*<<< orphan*/  mp_print_version (struct mp_log*,int) ; 
 int stub1 (struct mp_log*,TYPE_2__ const*,struct bstr,struct bstr,void*) ; 
 char* stub2 (TYPE_2__ const*,void const*) ; 
 char* stub3 (TYPE_2__ const*,void const*) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__ const*,void*,void const*) ; 
 int /*<<< orphan*/  stub5 (void*) ; 
 int stub6 (TYPE_2__ const*,void*,struct mpv_node*) ; 
 int stub7 (TYPE_2__ const*,void*,struct mpv_node*,void*) ; 

__attribute__((used)) static inline int m_option_parse(struct mp_log *log, const m_option_t *opt,
                                 struct bstr name, struct bstr param, void *dst)
{
    return opt->type->parse(log, opt, name, param, dst);
}

__attribute__((used)) static inline char *m_option_print(const m_option_t *opt, const void *val_ptr)
{
    if (opt->type->print)
        return opt->type->print(opt, val_ptr);
    else
        return NULL;
}

__attribute__((used)) static inline char *m_option_pretty_print(const m_option_t *opt,
                                          const void *val_ptr)
{
    if (opt->type->pretty_print)
        return opt->type->pretty_print(opt, val_ptr);
    else
        return m_option_print(opt, val_ptr);
}

__attribute__((used)) static inline void m_option_copy(const m_option_t *opt, void *dst,
                                 const void *src)
{
    if (opt->type->copy)
        opt->type->copy(opt, dst, src);
}

__attribute__((used)) static inline void m_option_free(const m_option_t *opt, void *dst)
{
    if (opt->type->free)
        opt->type->free(dst);
}

__attribute__((used)) static inline int m_option_set_node(const m_option_t *opt, void *dst,
                                    struct mpv_node *src)
{
    if (opt->type->set)
        return opt->type->set(opt, dst, src);
    return M_OPT_UNKNOWN;
}

__attribute__((used)) static inline int m_option_get_node(const m_option_t *opt, void *ta_parent,
                                    struct mpv_node *dst, void *src)
{
    if (opt->type->get)
        return opt->type->get(opt, ta_parent, dst, src);
    return M_OPT_UNKNOWN;
}

__attribute__((used)) static void print_version(struct mp_log *log)
{
    mp_print_version(log, true);
}

