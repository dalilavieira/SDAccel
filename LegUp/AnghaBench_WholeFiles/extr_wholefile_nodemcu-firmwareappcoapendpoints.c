#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_37__   TYPE_8__ ;
typedef  struct TYPE_36__   TYPE_7__ ;
typedef  struct TYPE_35__   TYPE_6__ ;
typedef  struct TYPE_34__   TYPE_5__ ;
typedef  struct TYPE_33__   TYPE_4__ ;
typedef  struct TYPE_32__   TYPE_3__ ;
typedef  struct TYPE_31__   TYPE_2__ ;
typedef  struct TYPE_30__   TYPE_28__ ;
typedef  struct TYPE_29__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ uint8_t ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  scalar_t__ uint16_t ;
typedef  int /*<<< orphan*/  lua_State ;
typedef  int /*<<< orphan*/  coap_rw_buffer_t ;
struct TYPE_30__ {scalar_t__ len; int /*<<< orphan*/  p; } ;
struct TYPE_33__ {scalar_t__* p; size_t len; } ;
struct TYPE_34__ {int /*<<< orphan*/  tok; TYPE_28__ payload; TYPE_4__ content; } ;
typedef  TYPE_5__ coap_packet_t ;
struct TYPE_29__ {scalar_t__ len; int /*<<< orphan*/  p; } ;
struct TYPE_35__ {TYPE_1__ buf; } ;
typedef  TYPE_6__ coap_option_t ;
struct TYPE_36__ {char* name; struct TYPE_36__* next; int /*<<< orphan*/  content_type; } ;
typedef  TYPE_7__ coap_luser_entry ;
struct TYPE_37__ {char* core_attr; TYPE_3__* path; TYPE_2__* user_entry; int /*<<< orphan*/ * handler; } ;
typedef  TYPE_8__ coap_endpoint_t ;
struct TYPE_32__ {scalar_t__ count; char** elems; } ;
struct TYPE_31__ {TYPE_7__* next; } ;

/* Variables and functions */
 int /*<<< orphan*/  COAP_CONTENTTYPE_APPLICATION_LINKFORMAT ; 
 int /*<<< orphan*/  COAP_CONTENTTYPE_NONE ; 
 int /*<<< orphan*/  COAP_CONTENTTYPE_TEXT_PLAIN ; 
 int COAP_ERR_BUFFER_TOO_SMALL ; 
 int /*<<< orphan*/  COAP_OPTION_URI_PATH ; 
 int /*<<< orphan*/  COAP_RSPCODE_BAD_REQUEST ; 
 int /*<<< orphan*/  COAP_RSPCODE_CONTENT ; 
 int /*<<< orphan*/  COAP_RSPCODE_NOT_FOUND ; 
 int LUA_MAXINPUT ; 
 int /*<<< orphan*/  LUA_PROCESS_LINE_SIG ; 
 int /*<<< orphan*/  LUA_TASK_PRIO ; 
 scalar_t__ LUA_TFUNCTION ; 
 size_t MAX_PAYLOAD_SIZE ; 
 int /*<<< orphan*/  NODE_DBG (char*) ; 
 void build_well_known_rsp (char*,scalar_t__) ; 
 scalar_t__ c_memcmp (char*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  c_memset (char*,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ c_strlen (char const*) ; 
 int /*<<< orphan*/  c_strncat (char*,char*,scalar_t__) ; 
 scalar_t__ c_zalloc (size_t) ; 
 int /*<<< orphan*/  coap_buffer_to_string (char*,int,TYPE_28__*) ; 
 TYPE_6__* coap_findOptions (TYPE_5__ const*,int /*<<< orphan*/ ,scalar_t__*) ; 
 int coap_make_response (int /*<<< orphan*/ *,TYPE_5__*,...) ; 
 int /*<<< orphan*/  coap_setup () ; 
 TYPE_8__* endpoints ; 
 int /*<<< orphan*/  id ; 
 char* luaL_checklstring (int /*<<< orphan*/ *,int,size_t*) ; 
 int /*<<< orphan*/  luaL_error (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  lua_call (int /*<<< orphan*/ *,int,int) ; 
 int /*<<< orphan*/  lua_getglobal (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/ * lua_getstate () ; 
 int lua_gettop (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  lua_isnil (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_isnumber (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_isstring (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  lua_pushlstring (int /*<<< orphan*/ *,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ lua_put_line (char*,scalar_t__) ; 
 int /*<<< orphan*/  lua_settop (int /*<<< orphan*/ *,int) ; 
 char* lua_tostring (int /*<<< orphan*/ *,int) ; 
 scalar_t__ lua_type (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  system_get_chip_id () ; 
 int /*<<< orphan*/  system_os_post (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void endpoint_setup(void)
{
    coap_setup();
}

__attribute__((used)) static int handle_get_well_known_core(const coap_endpoint_t *ep, coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo)
{
    outpkt->content.p = (uint8_t *)c_zalloc(MAX_PAYLOAD_SIZE);      // this should be free-ed when outpkt is built in coap_server_respond()
    if(outpkt->content.p == NULL){
        NODE_DBG("not enough memory\n");
        return COAP_ERR_BUFFER_TOO_SMALL;
    }
    outpkt->content.len = MAX_PAYLOAD_SIZE;
    build_well_known_rsp(outpkt->content.p, outpkt->content.len);
    return coap_make_response(scratch, outpkt, (const uint8_t *)outpkt->content.p, c_strlen(outpkt->content.p), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_APPLICATION_LINKFORMAT);
}

__attribute__((used)) static int handle_get_variable(const coap_endpoint_t *ep, coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo)
{
    const coap_option_t *opt;
    uint8_t count;
    int n;
    lua_State *L = lua_getstate();
    if (NULL != (opt = coap_findOptions(inpkt, COAP_OPTION_URI_PATH, &count)))
    {
        if ((count != ep->path->count ) && (count != ep->path->count + 1)) // +1 for /f/[function], /v/[variable]
        {
            NODE_DBG("should never happen.\n");
            goto end;
        }
        if (count == ep->path->count + 1)
        {
            coap_luser_entry *h = ep->user_entry->next;     // ->next: skip the first entry(head)
            while(NULL != h){
                if (opt[count-1].buf.len != c_strlen(h->name))
                {
                    h = h->next;
                    continue;
                }
                if (0 == c_memcmp(h->name, opt[count-1].buf.p, opt[count-1].buf.len))
                {
                    NODE_DBG("/v1/v/");
                    NODE_DBG((char *)h->name);
                    NODE_DBG(" match.\n");
                    if(c_strlen(h->name))
                    {
                        n = lua_gettop(L);
                        lua_getglobal(L, h->name);
                        if (!lua_isnumber(L, -1) && !lua_isstring(L, -1)) {
                            NODE_DBG ("should be a number or string.\n");
                            lua_settop(L, n);
                            return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_NOT_FOUND, COAP_CONTENTTYPE_NONE);
                        } else {
                            const char *res = lua_tostring(L,-1);
                            lua_settop(L, n);
                            return coap_make_response(scratch, outpkt, (const uint8_t *)res, c_strlen(res), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, h->content_type);
                        }
                    }
                } else {
                    h = h->next;
                }
            }
        }else{
            NODE_DBG("/v1/v match.\n");
            goto end;
        }
    }
    NODE_DBG("none match.\n");
end:
    return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}

__attribute__((used)) static int handle_post_function(const coap_endpoint_t *ep, coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo)
{
    const coap_option_t *opt;
    uint8_t count;
    int n;
    lua_State *L = lua_getstate();
    if (NULL != (opt = coap_findOptions(inpkt, COAP_OPTION_URI_PATH, &count)))
    {
        if ((count != ep->path->count ) && (count != ep->path->count + 1)) // +1 for /f/[function], /v/[variable]
        {
            NODE_DBG("should never happen.\n");
            goto end;
        }
        if (count == ep->path->count + 1)
        {
            coap_luser_entry *h = ep->user_entry->next;     // ->next: skip the first entry(head)
            while(NULL != h){
                if (opt[count-1].buf.len != c_strlen(h->name))
                {
                    h = h->next;
                    continue;
                }
                if (0 == c_memcmp(h->name, opt[count-1].buf.p, opt[count-1].buf.len))
                {
                    NODE_DBG("/v1/f/");
                    NODE_DBG((char *)h->name);
                    NODE_DBG(" match.\n");

                    if(c_strlen(h->name))
                    {
                        n = lua_gettop(L);
                        lua_getglobal(L, h->name);
                        if (lua_type(L, -1) != LUA_TFUNCTION) {
                            NODE_DBG ("should be a function\n");
                            lua_settop(L, n);
                            return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_NOT_FOUND, COAP_CONTENTTYPE_NONE);
                        } else {
                            lua_pushlstring(L, inpkt->payload.p, inpkt->payload.len);     // make sure payload.p is filled with '\0' after payload.len, or use lua_pushlstring
                            lua_call(L, 1, 1);
                            if (!lua_isnil(L, -1)){  /* get return? */
                                if( lua_isstring(L, -1) )   // deal with the return string
                                {
                                    size_t len = 0;
                                    const char *ret = luaL_checklstring( L, -1, &len );
                                    if(len > MAX_PAYLOAD_SIZE){
                                        lua_settop(L, n);
                                        luaL_error( L, "return string:<MAX_PAYLOAD_SIZE" );
                                        return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_NOT_FOUND, COAP_CONTENTTYPE_NONE);
                                    }
                                    NODE_DBG((char *)ret);
                                    NODE_DBG("\n");
                                    lua_settop(L, n);
                                    return coap_make_response(scratch, outpkt, ret, len, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
                                }
                            } else {
                                lua_settop(L, n);
                                return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
                            }
                        }
                    }
                } else {
                    h = h->next;
                }
            }
        }else{
            NODE_DBG("/v1/f match.\n");
            goto end;
        }
    }
    NODE_DBG("none match.\n");
end:
    return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_NOT_FOUND, COAP_CONTENTTYPE_NONE);
}

__attribute__((used)) static int handle_post_command(const coap_endpoint_t *ep, coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo)
{
    if (inpkt->payload.len == 0)
        return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_BAD_REQUEST, COAP_CONTENTTYPE_TEXT_PLAIN);
    if (inpkt->payload.len > 0)
    {
        char line[LUA_MAXINPUT];
        if (!coap_buffer_to_string(line, LUA_MAXINPUT, &inpkt->payload) &&
            lua_put_line(line, c_strlen(line))) {
            NODE_DBG("\nResult(if any):\n");
            system_os_post (LUA_TASK_PRIO, LUA_PROCESS_LINE_SIG, 0);
        }
        return coap_make_response(scratch, outpkt, NULL, 0, id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
    }
}

__attribute__((used)) static int handle_get_id(const coap_endpoint_t *ep, coap_rw_buffer_t *scratch, const coap_packet_t *inpkt, coap_packet_t *outpkt, uint8_t id_hi, uint8_t id_lo)
{
    id = system_get_chip_id();
    return coap_make_response(scratch, outpkt, (const uint8_t *)(&id), sizeof(uint32_t), id_hi, id_lo, &inpkt->tok, COAP_RSPCODE_CONTENT, COAP_CONTENTTYPE_TEXT_PLAIN);
}

void build_well_known_rsp(char *rsp, uint16_t rsplen)
{
    const coap_endpoint_t *ep = endpoints;
    int i;
    uint16_t len = rsplen;

    c_memset(rsp, 0, len);

    len--; // Null-terminated string

    while(NULL != ep->handler)
    {
        if (NULL == ep->core_attr) {
            ep++;
            continue;
        }
        if (NULL == ep->user_entry){
            if (0 < c_strlen(rsp)) {
                c_strncat(rsp, ",", len);
                len--;
            }

            c_strncat(rsp, "<", len);
            len--;

            for (i = 0; i < ep->path->count; i++) {
                c_strncat(rsp, "/", len);
                len--;

                c_strncat(rsp, ep->path->elems[i], len);
                len -= c_strlen(ep->path->elems[i]);
            }

            c_strncat(rsp, ">;", len);
            len -= 2;

            c_strncat(rsp, ep->core_attr, len);
            len -= c_strlen(ep->core_attr);
        } else {
            coap_luser_entry *h = ep->user_entry->next;     // ->next: skip the first entry(head)
            while(NULL != h){
                if (0 < c_strlen(rsp)) {
                    c_strncat(rsp, ",", len);
                    len--;
                }

                c_strncat(rsp, "<", len);
                len--;

                for (i = 0; i < ep->path->count; i++) {
                    c_strncat(rsp, "/", len);
                    len--;

                    c_strncat(rsp, ep->path->elems[i], len);
                    len -= c_strlen(ep->path->elems[i]);
                }

                c_strncat(rsp, "/", len);
                len--;

                c_strncat(rsp, h->name, len);
                len -= c_strlen(h->name);

                c_strncat(rsp, ">;", len);
                len -= 2;

                c_strncat(rsp, ep->core_attr, len);
                len -= c_strlen(ep->core_attr);

                h = h->next;
            }
        }
        ep++;
    }
}

