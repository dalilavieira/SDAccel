#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_45__   TYPE_9__ ;
typedef  struct TYPE_44__   TYPE_8__ ;
typedef  struct TYPE_43__   TYPE_7__ ;
typedef  struct TYPE_42__   TYPE_6__ ;
typedef  struct TYPE_41__   TYPE_5__ ;
typedef  struct TYPE_40__   TYPE_4__ ;
typedef  struct TYPE_39__   TYPE_3__ ;
typedef  struct TYPE_38__   TYPE_30__ ;
typedef  struct TYPE_37__   TYPE_2__ ;
typedef  struct TYPE_36__   TYPE_29__ ;
typedef  struct TYPE_35__   TYPE_1__ ;
typedef  struct TYPE_34__   TYPE_18__ ;
typedef  struct TYPE_33__   TYPE_12__ ;
typedef  struct TYPE_32__   TYPE_11__ ;
typedef  struct TYPE_31__   TYPE_10__ ;

/* Type definitions */
struct TYPE_40__ {int quality; } ;
struct TYPE_33__ {TYPE_4__ gzip; int /*<<< orphan*/  min_size; } ;
struct TYPE_44__ {void (* on_setup_ostream ) (int /*<<< orphan*/ *,TYPE_9__*,TYPE_10__**) ;} ;
struct st_compress_filter_t {TYPE_12__ args; TYPE_8__ super; } ;
struct TYPE_31__ {void (* do_send ) (TYPE_10__*,TYPE_9__*,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ) ;struct TYPE_31__* next; } ;
struct st_compress_encoder_t {TYPE_11__* compressor; TYPE_10__ super; } ;
typedef  size_t ssize_t ;
typedef  int /*<<< orphan*/  h2o_send_state_t ;
struct TYPE_34__ {size_t size; TYPE_6__* entries; } ;
struct TYPE_43__ {int status; TYPE_18__ headers; int /*<<< orphan*/  content_length; TYPE_3__* mime_attr; } ;
struct TYPE_35__ {int /*<<< orphan*/  len; int /*<<< orphan*/  base; } ;
struct TYPE_37__ {TYPE_1__ method; } ;
struct TYPE_45__ {int version; int compress_hint; scalar_t__ preferred_chunk_size; TYPE_7__ res; int /*<<< orphan*/  pool; int /*<<< orphan*/  headers; TYPE_2__ input; } ;
typedef  TYPE_9__ h2o_req_t ;
typedef  int /*<<< orphan*/  h2o_pathconf_t ;
typedef  TYPE_10__ h2o_ostream_t ;
typedef  int /*<<< orphan*/  h2o_iovec_t ;
typedef  int /*<<< orphan*/  h2o_filter_t ;
struct TYPE_41__ {int /*<<< orphan*/  len; int /*<<< orphan*/  base; } ;
struct TYPE_32__ {TYPE_5__ name; int /*<<< orphan*/  (* transform ) (TYPE_11__*,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ **,size_t*) ;} ;
typedef  TYPE_11__ h2o_compress_context_t ;
typedef  TYPE_12__ h2o_compress_args_t ;
struct TYPE_42__ {int /*<<< orphan*/  value; int /*<<< orphan*/ * name; } ;
struct TYPE_39__ {int /*<<< orphan*/  is_compressible; } ;
struct TYPE_38__ {int /*<<< orphan*/  buf; } ;
struct TYPE_36__ {int /*<<< orphan*/  buf; } ;

/* Variables and functions */
 scalar_t__ BUF_SIZE ; 
 int /*<<< orphan*/  H2O_ALIGNOF (struct st_compress_encoder_t) ; 
 int H2O_COMPRESSIBLE_BROTLI ; 
 int H2O_COMPRESSIBLE_GZIP ; 
#define  H2O_COMPRESS_HINT_AUTO 132 
#define  H2O_COMPRESS_HINT_DISABLE 131 
#define  H2O_COMPRESS_HINT_ENABLE 130 
#define  H2O_COMPRESS_HINT_ENABLE_BR 129 
#define  H2O_COMPRESS_HINT_ENABLE_GZIP 128 
 int /*<<< orphan*/  H2O_STRLIT (char*) ; 
 TYPE_30__* H2O_TOKEN_ACCEPT_RANGES ; 
 TYPE_29__* H2O_TOKEN_CONTENT_ENCODING ; 
 int /*<<< orphan*/  H2O_TOKEN_VARY ; 
 int /*<<< orphan*/  SIZE_MAX ; 
 int /*<<< orphan*/  h2o_add_header (int /*<<< orphan*/ *,TYPE_18__*,...) ; 
 scalar_t__ h2o_add_ostream (TYPE_9__*,int /*<<< orphan*/ ,int,TYPE_10__**) ; 
 TYPE_11__* h2o_compress_gzip_open (int /*<<< orphan*/ *,int) ; 
 scalar_t__ h2o_create_filter (int /*<<< orphan*/ *,int) ; 
 int h2o_get_compressible_types (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  h2o_iovec_init (int /*<<< orphan*/ ) ; 
 scalar_t__ h2o_memis (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  h2o_ostream_send_next (TYPE_10__*,TYPE_9__*,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  h2o_req_fill_mime_attributes (TYPE_9__*) ; 
 scalar_t__ h2o_send_state_is_in_progress (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  h2o_set_header_token (int /*<<< orphan*/ *,TYPE_18__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  h2o_setup_next_ostream (TYPE_9__*,TYPE_10__**) ; 
 int /*<<< orphan*/  stub1 (TYPE_11__*,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ ,int /*<<< orphan*/ **,size_t*) ; 

__attribute__((used)) static void do_send(h2o_ostream_t *_self, h2o_req_t *req, h2o_iovec_t *inbufs, size_t inbufcnt, h2o_send_state_t state)
{
    if (inbufcnt == 0 && h2o_send_state_is_in_progress(state)) {
        h2o_ostream_send_next(_self, req, inbufs, inbufcnt, state);
        return;
    }

    struct st_compress_encoder_t *self = (void *)_self;
    h2o_iovec_t *outbufs;
    size_t outbufcnt;

    self->compressor->transform(self->compressor, inbufs, inbufcnt, state, &outbufs, &outbufcnt);
    h2o_ostream_send_next(&self->super, req, outbufs, outbufcnt, state);
}

__attribute__((used)) static void on_setup_ostream(h2o_filter_t *_self, h2o_req_t *req, h2o_ostream_t **slot)
{
    struct st_compress_filter_t *self = (void *)_self;
    struct st_compress_encoder_t *encoder;
    int compressible_types;
    int compressible_types_mask = H2O_COMPRESSIBLE_BROTLI | H2O_COMPRESSIBLE_GZIP;
    h2o_compress_context_t *compressor;
    ssize_t i;

    if (req->version < 0x101)
        goto Next;
    if (req->res.status != 200)
        goto Next;
    if (h2o_memis(req->input.method.base, req->input.method.len, H2O_STRLIT("HEAD")))
        goto Next;

    switch (req->compress_hint) {
    case H2O_COMPRESS_HINT_DISABLE:
        /* compression was explicitely disabled, skip */
        goto Next;
    case H2O_COMPRESS_HINT_ENABLE:
        /* compression was explicitely enabled */
        break;
    case H2O_COMPRESS_HINT_ENABLE_BR:
        compressible_types_mask = H2O_COMPRESSIBLE_BROTLI;
        break;
    case H2O_COMPRESS_HINT_ENABLE_GZIP:
        compressible_types_mask = H2O_COMPRESSIBLE_GZIP;
        break;
    case H2O_COMPRESS_HINT_AUTO:
    default:
        /* no hint from the producer, decide whether to compress based
           on the configuration */
        if (req->res.mime_attr == NULL)
            h2o_req_fill_mime_attributes(req);
        if (!req->res.mime_attr->is_compressible)
            goto Next;
        if (req->res.content_length < self->args.min_size)
            goto Next;
    }

    /* skip if failed to gather the list of compressible types */
    compressible_types = h2o_get_compressible_types(&req->headers) & compressible_types_mask;
    if (compressible_types == 0)
        goto Next;

    /* skip if content-encoding header is being set (as well as obtain the location of accept-ranges) */
    size_t content_encoding_header_index = -1, accept_ranges_header_index = -1;
    for (i = 0; i != req->res.headers.size; ++i) {
        if (req->res.headers.entries[i].name == &H2O_TOKEN_CONTENT_ENCODING->buf)
            content_encoding_header_index = i;
        else if (req->res.headers.entries[i].name == &H2O_TOKEN_ACCEPT_RANGES->buf)
            accept_ranges_header_index = i;
        else
            continue;
    }
    if (content_encoding_header_index != -1)
        goto Next;

/* open the compressor */
#if H2O_USE_BROTLI
    if (self->args.brotli.quality != -1 && (compressible_types & H2O_COMPRESSIBLE_BROTLI) != 0) {
        compressor =
            h2o_compress_brotli_open(&req->pool, self->args.brotli.quality, req->res.content_length, req->preferred_chunk_size);
    } else
#endif
        if (self->args.gzip.quality != -1 && (compressible_types & H2O_COMPRESSIBLE_GZIP) != 0) {
        compressor = h2o_compress_gzip_open(&req->pool, self->args.gzip.quality);
    } else {
        /* let proxies know that we looked at accept-encoding when deciding not to compress */
        h2o_set_header_token(&req->pool, &req->res.headers, H2O_TOKEN_VARY, H2O_STRLIT("accept-encoding"));
        goto Next;
    }

    /* adjust the response headers */
    req->res.content_length = SIZE_MAX;
    h2o_add_header(&req->pool, &req->res.headers, H2O_TOKEN_CONTENT_ENCODING, NULL, compressor->name.base, compressor->name.len);
    h2o_set_header_token(&req->pool, &req->res.headers, H2O_TOKEN_VARY, H2O_STRLIT("accept-encoding"));
    if (accept_ranges_header_index != -1) {
        req->res.headers.entries[accept_ranges_header_index].value = h2o_iovec_init(H2O_STRLIT("none"));
    } else {
        h2o_add_header(&req->pool, &req->res.headers, H2O_TOKEN_ACCEPT_RANGES, NULL, H2O_STRLIT("none"));
    }

    /* setup filter */
    encoder = (void *)h2o_add_ostream(req, H2O_ALIGNOF(*encoder), sizeof(*encoder), slot);
    encoder->super.do_send = do_send;
    slot = &encoder->super.next;
    encoder->compressor = compressor;

    /* adjust preferred chunk size (compress by 8192 bytes) */
    if (req->preferred_chunk_size > BUF_SIZE)
        req->preferred_chunk_size = BUF_SIZE;

Next:
    h2o_setup_next_ostream(req, slot);
}

void h2o_compress_register(h2o_pathconf_t *pathconf, h2o_compress_args_t *args)
{
    struct st_compress_filter_t *self = (void *)h2o_create_filter(pathconf, sizeof(*self));
    self->super.on_setup_ostream = on_setup_ostream;
    self->args = *args;
}

