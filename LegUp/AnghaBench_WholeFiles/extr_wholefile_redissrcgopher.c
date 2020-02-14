#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_3__ ;
typedef  struct TYPE_28__   TYPE_2__ ;
typedef  struct TYPE_27__   TYPE_24__ ;
typedef  struct TYPE_26__   TYPE_1__ ;
typedef  struct TYPE_25__   TYPE_10__ ;

/* Type definitions */
typedef  unsigned char* sds ;
struct TYPE_26__ {scalar_t__ type; } ;
typedef  TYPE_1__ robj ;
struct TYPE_28__ {size_t max_processing_chunk; scalar_t__ (* write ) (TYPE_2__*,void const*,size_t) ;size_t processed_bytes; scalar_t__ (* read ) (TYPE_2__*,void*,size_t) ;int (* flush ) (TYPE_2__*) ;int /*<<< orphan*/  (* tell ) (TYPE_2__*) ;int /*<<< orphan*/  (* update_cksum ) (TYPE_2__*,void*,size_t) ;} ;
typedef  TYPE_2__ rio ;
typedef  int /*<<< orphan*/  off_t ;
struct TYPE_29__ {scalar_t__ argc; int /*<<< orphan*/  db; TYPE_1__** argv; } ;
typedef  TYPE_3__ client ;
struct TYPE_27__ {size_t len; size_t alloc; } ;
struct TYPE_25__ {size_t alloc; size_t len; } ;

/* Variables and functions */
 scalar_t__ OBJ_STRING ; 
 TYPE_24__* SDS_HDR (int,unsigned char* const) ; 
 int /*<<< orphan*/  SDS_HDR_VAR (int,unsigned char* const) ; 
#define  SDS_TYPE_16 132 
#define  SDS_TYPE_32 131 
#define  SDS_TYPE_5 130 
 size_t SDS_TYPE_5_LEN (unsigned char) ; 
#define  SDS_TYPE_64 129 
#define  SDS_TYPE_8 128 
 size_t SDS_TYPE_BITS ; 
 unsigned char SDS_TYPE_MASK ; 
 int /*<<< orphan*/  addReply (TYPE_3__*,TYPE_1__*) ; 
 int /*<<< orphan*/  addReplyProto (TYPE_3__*,unsigned char*,size_t) ; 
 TYPE_1__* createStringObject (char*,int) ; 
 int /*<<< orphan*/  decrRefCount (TYPE_1__*) ; 
 TYPE_1__* lookupKeyRead (int /*<<< orphan*/ ,TYPE_1__*) ; 
 unsigned char* sdscatfmt (int /*<<< orphan*/ ,char*,char const*,char const*,char const*,char const*,int) ; 
 int /*<<< orphan*/  sdsempty () ; 
 int /*<<< orphan*/  sdsfree (unsigned char*) ; 
 TYPE_10__* sh ; 
 int /*<<< orphan*/  stub1 (TYPE_2__*,void const*,size_t) ; 
 scalar_t__ stub2 (TYPE_2__*,void const*,size_t) ; 
 scalar_t__ stub3 (TYPE_2__*,void*,size_t) ; 
 int /*<<< orphan*/  stub4 (TYPE_2__*,void*,size_t) ; 
 int /*<<< orphan*/  stub5 (TYPE_2__*) ; 
 int stub6 (TYPE_2__*) ; 

__attribute__((used)) static inline size_t sdslen(const sds s) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
        case SDS_TYPE_5:
            return SDS_TYPE_5_LEN(flags);
        case SDS_TYPE_8:
            return SDS_HDR(8,s)->len;
        case SDS_TYPE_16:
            return SDS_HDR(16,s)->len;
        case SDS_TYPE_32:
            return SDS_HDR(32,s)->len;
        case SDS_TYPE_64:
            return SDS_HDR(64,s)->len;
    }
    return 0;
}

__attribute__((used)) static inline size_t sdsavail(const sds s) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
        case SDS_TYPE_5: {
            return 0;
        }
        case SDS_TYPE_8: {
            SDS_HDR_VAR(8,s);
            return sh->alloc - sh->len;
        }
        case SDS_TYPE_16: {
            SDS_HDR_VAR(16,s);
            return sh->alloc - sh->len;
        }
        case SDS_TYPE_32: {
            SDS_HDR_VAR(32,s);
            return sh->alloc - sh->len;
        }
        case SDS_TYPE_64: {
            SDS_HDR_VAR(64,s);
            return sh->alloc - sh->len;
        }
    }
    return 0;
}

__attribute__((used)) static inline void sdssetlen(sds s, size_t newlen) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
        case SDS_TYPE_5:
            {
                unsigned char *fp = ((unsigned char*)s)-1;
                *fp = SDS_TYPE_5 | (newlen << SDS_TYPE_BITS);
            }
            break;
        case SDS_TYPE_8:
            SDS_HDR(8,s)->len = newlen;
            break;
        case SDS_TYPE_16:
            SDS_HDR(16,s)->len = newlen;
            break;
        case SDS_TYPE_32:
            SDS_HDR(32,s)->len = newlen;
            break;
        case SDS_TYPE_64:
            SDS_HDR(64,s)->len = newlen;
            break;
    }
}

__attribute__((used)) static inline void sdsinclen(sds s, size_t inc) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
        case SDS_TYPE_5:
            {
                unsigned char *fp = ((unsigned char*)s)-1;
                unsigned char newlen = SDS_TYPE_5_LEN(flags)+inc;
                *fp = SDS_TYPE_5 | (newlen << SDS_TYPE_BITS);
            }
            break;
        case SDS_TYPE_8:
            SDS_HDR(8,s)->len += inc;
            break;
        case SDS_TYPE_16:
            SDS_HDR(16,s)->len += inc;
            break;
        case SDS_TYPE_32:
            SDS_HDR(32,s)->len += inc;
            break;
        case SDS_TYPE_64:
            SDS_HDR(64,s)->len += inc;
            break;
    }
}

__attribute__((used)) static inline size_t sdsalloc(const sds s) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
        case SDS_TYPE_5:
            return SDS_TYPE_5_LEN(flags);
        case SDS_TYPE_8:
            return SDS_HDR(8,s)->alloc;
        case SDS_TYPE_16:
            return SDS_HDR(16,s)->alloc;
        case SDS_TYPE_32:
            return SDS_HDR(32,s)->alloc;
        case SDS_TYPE_64:
            return SDS_HDR(64,s)->alloc;
    }
    return 0;
}

__attribute__((used)) static inline void sdssetalloc(sds s, size_t newlen) {
    unsigned char flags = s[-1];
    switch(flags&SDS_TYPE_MASK) {
        case SDS_TYPE_5:
            /* Nothing to do, this type has no total allocation info. */
            break;
        case SDS_TYPE_8:
            SDS_HDR(8,s)->alloc = newlen;
            break;
        case SDS_TYPE_16:
            SDS_HDR(16,s)->alloc = newlen;
            break;
        case SDS_TYPE_32:
            SDS_HDR(32,s)->alloc = newlen;
            break;
        case SDS_TYPE_64:
            SDS_HDR(64,s)->alloc = newlen;
            break;
    }
}

__attribute__((used)) static inline size_t rioWrite(rio *r, const void *buf, size_t len) {
    while (len) {
        size_t bytes_to_write = (r->max_processing_chunk && r->max_processing_chunk < len) ? r->max_processing_chunk : len;
        if (r->update_cksum) r->update_cksum(r,buf,bytes_to_write);
        if (r->write(r,buf,bytes_to_write) == 0)
            return 0;
        buf = (char*)buf + bytes_to_write;
        len -= bytes_to_write;
        r->processed_bytes += bytes_to_write;
    }
    return 1;
}

__attribute__((used)) static inline size_t rioRead(rio *r, void *buf, size_t len) {
    while (len) {
        size_t bytes_to_read = (r->max_processing_chunk && r->max_processing_chunk < len) ? r->max_processing_chunk : len;
        if (r->read(r,buf,bytes_to_read) == 0)
            return 0;
        if (r->update_cksum) r->update_cksum(r,buf,bytes_to_read);
        buf = (char*)buf + bytes_to_read;
        len -= bytes_to_read;
        r->processed_bytes += bytes_to_read;
    }
    return 1;
}

__attribute__((used)) static inline off_t rioTell(rio *r) {
    return r->tell(r);
}

__attribute__((used)) static inline int rioFlush(rio *r) {
    return r->flush(r);
}

void addReplyGopherItem(client *c, const char *type, const char *descr,
                        const char *selector, const char *hostname, int port)
{
    sds item = sdscatfmt(sdsempty(),"%s%s\t%s\t%s\t%i\r\n",
                         type, descr,
                         selector ? selector : "(NULL)",
                         hostname ? hostname : "(NULL)",
                         port);
    addReplyProto(c,item,sdslen(item));
    sdsfree(item);
}

void processGopherRequest(client *c) {
    robj *keyname = c->argc == 0 ? createStringObject("/",1) : c->argv[0];
    robj *o = lookupKeyRead(c->db,keyname);

    /* If there is no such key, return with a Gopher error. */
    if (o == NULL || o->type != OBJ_STRING) {
        char *errstr;
        if (o == NULL)
            errstr = "Error: no content at the specified key";
        else
            errstr = "Error: selected key type is invalid "
                     "for Gopher output";
        addReplyGopherItem(c,"i",errstr,NULL,NULL,0);
        addReplyGopherItem(c,"i","Redis Gopher server",NULL,NULL,0);
    } else {
        addReply(c,o);
    }

    /* Cleanup, also make sure to emit the final ".CRLF" line. Note that
     * the connection will be closed immediately after this because the client
     * will be flagged with CLIENT_CLOSE_AFTER_REPLY, in accordance with the
     * Gopher protocol. */
    if (c->argc == 0) decrRefCount(keyname);

    /* Note that in theory we should terminate the Gopher request with
     * ".<CR><LF>" (called Lastline in the RFC) like that:
     *
     * addReplyProto(c,".\r\n",3);
     *
     * However after examining the current clients landscape, it's probably
     * going to do more harm than good for several reasons:
     *
     * 1. Clients should not have any issue with missing .<CR><LF> as for
     *    specification, and in the real world indeed certain servers
     *    implementations never used to send the terminator.
     *
     * 2. Redis does not know if it's serving a text file or a binary file:
     *    at the same time clients will not remove the ".<CR><LF>" bytes at
     *    tne end when downloading a binary file from the server, so adding
     *    the "Lastline" terminator without knowing the content is just
     *    dangerous.
     *
     * 3. The utility gopher2redis.rb that we provide for Redis, and any
     *    other similar tool you may use as Gopher authoring system for
     *    Redis, can just add the "Lastline" when needed.
     */
}

