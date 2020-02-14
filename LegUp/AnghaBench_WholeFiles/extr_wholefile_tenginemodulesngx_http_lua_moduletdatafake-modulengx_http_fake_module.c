#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  void ngx_http_fake_srv_conf_t ;
typedef  void ngx_http_fake_loc_conf_t ;
struct TYPE_9__ {int /*<<< orphan*/  pool; } ;
typedef  TYPE_1__ ngx_conf_t ;

/* Variables and functions */
 char* NGX_CONF_ERROR ; 
 char* NGX_CONF_OK ; 
 int /*<<< orphan*/  NGX_LOG_ALERT ; 
 int /*<<< orphan*/  ngx_conf_log_error (int /*<<< orphan*/ ,TYPE_1__*,int /*<<< orphan*/ ,char*) ; 
 void* ngx_http_conf_get_module_loc_conf (TYPE_1__*,int /*<<< orphan*/ ) ; 
 void* ngx_http_conf_get_module_srv_conf (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_fake_module ; 
 void* ngx_pcalloc (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static void *ngx_http_fake_create_srv_conf(ngx_conf_t *cf)
{
    ngx_http_fake_srv_conf_t   *fscf;

    fscf = ngx_pcalloc(cf->pool, sizeof(ngx_http_fake_srv_conf_t));
    if (fscf == NULL) {
        return NULL;
    }

    return fscf;
}

__attribute__((used)) static char *ngx_http_fake_merge_srv_conf(ngx_conf_t *cf, void *prev, void *conf)
{
    ngx_http_fake_srv_conf_t   *fscf;

    fscf = ngx_http_conf_get_module_srv_conf(cf, ngx_http_fake_module);
    if (fscf == NULL) {
        ngx_conf_log_error(NGX_LOG_ALERT, cf, 0,
                           "get module srv conf failed in merge srv conf");
        return NGX_CONF_ERROR;
    }

    return NGX_CONF_OK;
}

__attribute__((used)) static void *ngx_http_fake_create_loc_conf(ngx_conf_t *cf)
{
    ngx_http_fake_loc_conf_t   *flcf;

    flcf = ngx_pcalloc(cf->pool, sizeof(ngx_http_fake_loc_conf_t));
    if (flcf == NULL) {
        return NULL;
    }

    return flcf;
}

__attribute__((used)) static char *ngx_http_fake_merge_loc_conf(ngx_conf_t *cf, void *prev, void *conf)
{
    ngx_http_fake_loc_conf_t   *flcf;

    flcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_fake_module);
    if (flcf == NULL) {
        ngx_conf_log_error(NGX_LOG_ALERT, cf, 0,
                           "get module loc conf failed in merge loc conf");
        return NGX_CONF_ERROR;
    }

    return NGX_CONF_OK;
}

