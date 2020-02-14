#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_59__   TYPE_9__ ;
typedef  struct TYPE_58__   TYPE_8__ ;
typedef  struct TYPE_57__   TYPE_7__ ;
typedef  struct TYPE_56__   TYPE_6__ ;
typedef  struct TYPE_55__   TYPE_5__ ;
typedef  struct TYPE_54__   TYPE_4__ ;
typedef  struct TYPE_53__   TYPE_3__ ;
typedef  struct TYPE_52__   TYPE_2__ ;
typedef  struct TYPE_51__   TYPE_1__ ;
typedef  struct TYPE_50__   TYPE_13__ ;
typedef  struct TYPE_49__   TYPE_12__ ;
typedef  struct TYPE_48__   TYPE_11__ ;
typedef  struct TYPE_47__   TYPE_10__ ;

/* Type definitions */
typedef  TYPE_6__* xmlParserCtxtPtr ;
typedef  int /*<<< orphan*/  xmlNodePtr ;
typedef  int /*<<< orphan*/ * xmlDtdPtr ;
typedef  TYPE_7__* xmlDocPtr ;
typedef  int /*<<< orphan*/  const xmlChar ;
struct TYPE_58__ {scalar_t__ data; int /*<<< orphan*/  handler; } ;
typedef  TYPE_8__ ngx_pool_cleanup_t ;
typedef  scalar_t__ ngx_int_t ;
struct TYPE_52__ {scalar_t__ nelts; } ;
struct TYPE_59__ {int /*<<< orphan*/  dtd; int /*<<< orphan*/  last_modified; int /*<<< orphan*/  types; TYPE_2__ sheets; } ;
typedef  TYPE_9__ ngx_http_xslt_filter_loc_conf_t ;
struct TYPE_47__ {int done; TYPE_11__* request; TYPE_6__* ctxt; TYPE_7__* doc; } ;
typedef  TYPE_10__ ngx_http_xslt_filter_ctx_t ;
struct TYPE_55__ {scalar_t__ status; TYPE_4__* content_length; scalar_t__ content_length_n; } ;
struct TYPE_48__ {int main_filter_need_in_memory; TYPE_3__* connection; scalar_t__ header_only; TYPE_5__ headers_out; struct TYPE_48__* main; int /*<<< orphan*/  pool; } ;
typedef  TYPE_11__ ngx_http_request_t ;
struct TYPE_49__ {struct TYPE_49__* next; TYPE_13__* buf; } ;
typedef  TYPE_12__ ngx_chain_t ;
struct TYPE_50__ {scalar_t__ last; scalar_t__ pos; scalar_t__ last_in_chain; scalar_t__ last_buf; } ;
typedef  TYPE_13__ ngx_buf_t ;
struct TYPE_57__ {int /*<<< orphan*/ * extSubset; int /*<<< orphan*/ * children; } ;
struct TYPE_56__ {int wellFormed; TYPE_7__* myDoc; TYPE_1__* sax; } ;
struct TYPE_54__ {scalar_t__ hash; } ;
struct TYPE_53__ {int /*<<< orphan*/  log; } ;
struct TYPE_51__ {void (* externalSubset ) (void*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ;TYPE_10__* _private; void* fatalError; void* error; int /*<<< orphan*/ * setDocumentLocator; } ;

/* Variables and functions */
 scalar_t__ NGX_ERROR ; 
 int /*<<< orphan*/  NGX_HTTP_INTERNAL_SERVER_ERROR ; 
 scalar_t__ NGX_HTTP_NOT_MODIFIED ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_HTTP ; 
 int /*<<< orphan*/  NGX_LOG_ERR ; 
 scalar_t__ NGX_OK ; 
 int XML_PARSE_DTDLOAD ; 
 int XML_PARSE_NOENT ; 
 int XML_PARSE_NOWARNING ; 
 int /*<<< orphan*/  ngx_free (scalar_t__) ; 
 int /*<<< orphan*/  ngx_http_clear_etag (TYPE_11__*) ; 
 int /*<<< orphan*/  ngx_http_clear_last_modified (TYPE_11__*) ; 
 scalar_t__ ngx_http_filter_finalize_request (TYPE_11__*,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 TYPE_10__* ngx_http_get_module_ctx (TYPE_11__*,int /*<<< orphan*/ ) ; 
 TYPE_9__* ngx_http_get_module_loc_conf (TYPE_11__*,int /*<<< orphan*/ ) ; 
 scalar_t__ ngx_http_next_body_filter (TYPE_11__*,TYPE_12__*) ; 
 scalar_t__ ngx_http_next_header_filter (TYPE_11__*) ; 
 int /*<<< orphan*/  ngx_http_set_ctx (TYPE_11__*,TYPE_10__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * ngx_http_test_content_type (TYPE_11__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  ngx_http_weak_etag (TYPE_11__*) ; 
static  scalar_t__ ngx_http_xslt_add_chunk (TYPE_11__*,TYPE_10__*,TYPE_13__*) ; 
 TYPE_13__* ngx_http_xslt_apply_stylesheet (TYPE_11__*,TYPE_10__*) ; 
 int /*<<< orphan*/  ngx_http_xslt_cleanup ; 
 int /*<<< orphan*/  ngx_http_xslt_filter_module ; 
 void* ngx_http_xslt_sax_error ; 
static  void ngx_http_xslt_sax_external_subset (void*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
static  scalar_t__ ngx_http_xslt_send (TYPE_11__*,TYPE_10__*,TYPE_13__*) ; 
 int /*<<< orphan*/  ngx_log_debug0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  ngx_log_debug3 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ngx_log_error (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*,...) ; 
 TYPE_10__* ngx_pcalloc (int /*<<< orphan*/ ,int) ; 
 TYPE_8__* ngx_pool_cleanup_add (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xmlAddChild (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xmlAddPrevSibling (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * xmlCopyDtd (int /*<<< orphan*/ ) ; 
 TYPE_6__* xmlCreatePushParserCtxt (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  xmlCtxtUseOptions (TYPE_6__*,int) ; 
 int /*<<< orphan*/  xmlFreeDoc (TYPE_7__*) ; 
 int /*<<< orphan*/  xmlFreeParserCtxt (TYPE_6__*) ; 
 int xmlParseChunk (TYPE_6__*,char*,int,int) ; 

__attribute__((used)) static ngx_int_t
ngx_http_xslt_header_filter(ngx_http_request_t *r)
{
    ngx_http_xslt_filter_ctx_t       *ctx;
    ngx_http_xslt_filter_loc_conf_t  *conf;

    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
                   "xslt filter header");

    if (r->headers_out.status == NGX_HTTP_NOT_MODIFIED) {
        return ngx_http_next_header_filter(r);
    }

    conf = ngx_http_get_module_loc_conf(r, ngx_http_xslt_filter_module);

    if (conf->sheets.nelts == 0
        || ngx_http_test_content_type(r, &conf->types) == NULL)
    {
        return ngx_http_next_header_filter(r);
    }

    ctx = ngx_http_get_module_ctx(r, ngx_http_xslt_filter_module);

    if (ctx) {
        return ngx_http_next_header_filter(r);
    }

    ctx = ngx_pcalloc(r->pool, sizeof(ngx_http_xslt_filter_ctx_t));
    if (ctx == NULL) {
        return NGX_ERROR;
    }

    ngx_http_set_ctx(r, ctx, ngx_http_xslt_filter_module);

    r->main_filter_need_in_memory = 1;

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_xslt_body_filter(ngx_http_request_t *r, ngx_chain_t *in)
{
    int                          wellFormed;
    ngx_chain_t                 *cl;
    ngx_http_xslt_filter_ctx_t  *ctx;

    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
                   "xslt filter body");

    if (in == NULL) {
        return ngx_http_next_body_filter(r, in);
    }

    ctx = ngx_http_get_module_ctx(r, ngx_http_xslt_filter_module);

    if (ctx == NULL || ctx->done) {
        return ngx_http_next_body_filter(r, in);
    }

    for (cl = in; cl; cl = cl->next) {

        if (ngx_http_xslt_add_chunk(r, ctx, cl->buf) != NGX_OK) {

            if (ctx->ctxt->myDoc) {

#if (NGX_HTTP_XSLT_REUSE_DTD)
                ctx->ctxt->myDoc->extSubset = NULL;
#endif
                xmlFreeDoc(ctx->ctxt->myDoc);
            }

            xmlFreeParserCtxt(ctx->ctxt);

            return ngx_http_xslt_send(r, ctx, NULL);
        }

        if (cl->buf->last_buf || cl->buf->last_in_chain) {

            ctx->doc = ctx->ctxt->myDoc;

#if (NGX_HTTP_XSLT_REUSE_DTD)
            ctx->doc->extSubset = NULL;
#endif

            wellFormed = ctx->ctxt->wellFormed;

            xmlFreeParserCtxt(ctx->ctxt);

            if (wellFormed) {
                return ngx_http_xslt_send(r, ctx,
                                       ngx_http_xslt_apply_stylesheet(r, ctx));
            }

            xmlFreeDoc(ctx->doc);

            ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
                          "not well formed XML document");

            return ngx_http_xslt_send(r, ctx, NULL);
        }
    }

    return NGX_OK;
}

__attribute__((used)) static ngx_int_t
ngx_http_xslt_send(ngx_http_request_t *r, ngx_http_xslt_filter_ctx_t *ctx,
    ngx_buf_t *b)
{
    ngx_int_t                         rc;
    ngx_chain_t                       out;
    ngx_pool_cleanup_t               *cln;
    ngx_http_xslt_filter_loc_conf_t  *conf;

    ctx->done = 1;

    if (b == NULL) {
        return ngx_http_filter_finalize_request(r, &ngx_http_xslt_filter_module,
                                               NGX_HTTP_INTERNAL_SERVER_ERROR);
    }

    cln = ngx_pool_cleanup_add(r->pool, 0);

    if (cln == NULL) {
        ngx_free(b->pos);
        return ngx_http_filter_finalize_request(r, &ngx_http_xslt_filter_module,
                                               NGX_HTTP_INTERNAL_SERVER_ERROR);
    }

    if (r == r->main) {
        r->headers_out.content_length_n = b->last - b->pos;

        if (r->headers_out.content_length) {
            r->headers_out.content_length->hash = 0;
            r->headers_out.content_length = NULL;
        }

        conf = ngx_http_get_module_loc_conf(r, ngx_http_xslt_filter_module);

        if (!conf->last_modified) {
            ngx_http_clear_last_modified(r);
            ngx_http_clear_etag(r);

        } else {
            ngx_http_weak_etag(r);
        }
    }

    rc = ngx_http_next_header_filter(r);

    if (rc == NGX_ERROR || rc > NGX_OK || r->header_only) {
        ngx_free(b->pos);
        return rc;
    }

    cln->handler = ngx_http_xslt_cleanup;
    cln->data = b->pos;

    out.buf = b;
    out.next = NULL;

    return ngx_http_next_body_filter(r, &out);
}

__attribute__((used)) static ngx_int_t
ngx_http_xslt_add_chunk(ngx_http_request_t *r, ngx_http_xslt_filter_ctx_t *ctx,
    ngx_buf_t *b)
{
    int               err;
    xmlParserCtxtPtr  ctxt;

    if (ctx->ctxt == NULL) {

        ctxt = xmlCreatePushParserCtxt(NULL, NULL, NULL, 0, NULL);
        if (ctxt == NULL) {
            ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
                          "xmlCreatePushParserCtxt() failed");
            return NGX_ERROR;
        }
        xmlCtxtUseOptions(ctxt, XML_PARSE_NOENT|XML_PARSE_DTDLOAD
                                               |XML_PARSE_NOWARNING);

        ctxt->sax->externalSubset = ngx_http_xslt_sax_external_subset;
        ctxt->sax->setDocumentLocator = NULL;
        ctxt->sax->error = ngx_http_xslt_sax_error;
        ctxt->sax->fatalError = ngx_http_xslt_sax_error;
        ctxt->sax->_private = ctx;

        ctx->ctxt = ctxt;
        ctx->request = r;
    }

    err = xmlParseChunk(ctx->ctxt, (char *) b->pos, (int) (b->last - b->pos),
                        (b->last_buf) || (b->last_in_chain));

    if (err == 0) {
        b->pos = b->last;
        return NGX_OK;
    }

    ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
                  "xmlParseChunk() failed, error:%d", err);

    return NGX_ERROR;
}

__attribute__((used)) static void
ngx_http_xslt_sax_external_subset(void *data, const xmlChar *name,
    const xmlChar *externalId, const xmlChar *systemId)
{
    xmlParserCtxtPtr ctxt = data;

    xmlDocPtr                         doc;
    xmlDtdPtr                         dtd;
    ngx_http_request_t               *r;
    ngx_http_xslt_filter_ctx_t       *ctx;
    ngx_http_xslt_filter_loc_conf_t  *conf;

    ctx = ctxt->sax->_private;
    r = ctx->request;

    conf = ngx_http_get_module_loc_conf(r, ngx_http_xslt_filter_module);

    ngx_log_debug3(NGX_LOG_DEBUG_HTTP, r->connection->log, 0,
                   "xslt filter extSubset: \"%s\" \"%s\" \"%s\"",
                   name ? name : (xmlChar *) "",
                   externalId ? externalId : (xmlChar *) "",
                   systemId ? systemId : (xmlChar *) "");

    doc = ctxt->myDoc;

#if (NGX_HTTP_XSLT_REUSE_DTD)

    dtd = conf->dtd;

#else

    dtd = xmlCopyDtd(conf->dtd);
    if (dtd == NULL) {
        ngx_log_error(NGX_LOG_ERR, r->connection->log, 0,
                      "xmlCopyDtd() failed");
        return;
    }

    if (doc->children == NULL) {
        xmlAddChild((xmlNodePtr) doc, (xmlNodePtr) dtd);

    } else {
        xmlAddPrevSibling(doc->children, (xmlNodePtr) dtd);
    }

#endif

    doc->extSubset = dtd;
}

