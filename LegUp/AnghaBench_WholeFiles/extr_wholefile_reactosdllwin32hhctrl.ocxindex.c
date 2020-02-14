#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_46__   TYPE_7__ ;
typedef  struct TYPE_45__   TYPE_5__ ;
typedef  struct TYPE_44__   TYPE_4__ ;
typedef  struct TYPE_43__   TYPE_3__ ;
typedef  struct TYPE_42__   TYPE_37__ ;
typedef  struct TYPE_41__   TYPE_34__ ;
typedef  struct TYPE_40__   TYPE_2__ ;
typedef  struct TYPE_39__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  sz_text_sitemap ;
typedef  int /*<<< orphan*/  stream_t ;
struct TYPE_43__ {char* buf; } ;
typedef  TYPE_3__ strbuf_t ;
typedef  int /*<<< orphan*/  lvi ;
typedef  int /*<<< orphan*/  UINT ;
struct TYPE_39__ {int /*<<< orphan*/  pszIndex; } ;
struct TYPE_46__ {TYPE_5__* index; TYPE_2__* tabs; TYPE_37__* pCHMInfo; TYPE_1__ WinType; } ;
struct TYPE_41__ {TYPE_5__* chm_index; TYPE_5__* chm_file; } ;
struct TYPE_45__ {int indentLevel; int nItems; int itemFlags; struct TYPE_45__* items; struct TYPE_45__* local; struct TYPE_45__* name; struct TYPE_45__* keyword; struct TYPE_45__* next; TYPE_34__ merge; scalar_t__ id; } ;
struct TYPE_44__ {int mask; int iIndent; scalar_t__ lParam; TYPE_5__* pszText; scalar_t__ cchTextMax; int /*<<< orphan*/  iItem; } ;
struct TYPE_42__ {int /*<<< orphan*/  szFile; int /*<<< orphan*/  codePage; } ;
struct TYPE_40__ {int /*<<< orphan*/  hwnd; } ;
typedef  TYPE_4__ LVITEMW ;
typedef  TYPE_5__* LPWSTR ;
typedef  scalar_t__ LPARAM ;
typedef  int /*<<< orphan*/  IndexSubItem ;
typedef  TYPE_5__ IndexItem ;
typedef  int /*<<< orphan*/  IStream ;
typedef  int /*<<< orphan*/  HWND ;
typedef  scalar_t__ HTREEITEM ;
typedef  TYPE_7__ HHInfo ;

/* Variables and functions */
 int /*<<< orphan*/  FIXME (char*) ; 
 int /*<<< orphan*/ * GetChmStream (TYPE_37__*,int /*<<< orphan*/ ,TYPE_34__*) ; 
 int /*<<< orphan*/  IStream_Release (int /*<<< orphan*/ *) ; 
 int LVIF_INDENT ; 
 int LVIF_PARAM ; 
 int LVIF_TEXT ; 
 int /*<<< orphan*/  LVM_INSERTITEMW ; 
 scalar_t__ SendMessageW (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  SetChmPath (TYPE_34__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 size_t TAB_INDEX ; 
 int /*<<< orphan*/  TRACE (char*,...) ; 
 int /*<<< orphan*/  WARN (char*,...) ; 
 char* debugstr_an (char const*,int) ; 
 int /*<<< orphan*/  debugstr_w (TYPE_5__*) ; 
 TYPE_5__* decode_html (char const*,int,int /*<<< orphan*/ ) ; 
 char* get_attr (char const*,char*,int*) ; 
 int /*<<< orphan*/  get_node_name (TYPE_3__*,TYPE_3__*) ; 
 void* heap_alloc_zero (int) ; 
 int /*<<< orphan*/  heap_free (TYPE_5__*) ; 
 TYPE_5__* heap_realloc (TYPE_5__*,int) ; 
 int /*<<< orphan*/  memcmp (char const*,char const*,int) ; 
 int /*<<< orphan*/  memcpy (TYPE_5__*,TYPE_5__*,int) ; 
 int /*<<< orphan*/  memset (TYPE_4__*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ next_node (int /*<<< orphan*/ *,TYPE_3__*) ; 
 int /*<<< orphan*/  strbuf_free (TYPE_3__*) ; 
 int /*<<< orphan*/  strbuf_init (TYPE_3__*) ; 
 int /*<<< orphan*/  strbuf_zero (TYPE_3__*) ; 
 int /*<<< orphan*/  strcasecmp (char*,char*) ; 
 scalar_t__ strcmpW (TYPE_5__*,TYPE_5__*) ; 
 int /*<<< orphan*/  stream_init (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 scalar_t__ strlenW (TYPE_5__*) ; 
 int /*<<< orphan*/  strncasecmp (char*,char const*,int) ; 

__attribute__((used)) static void fill_index_tree(HWND hwnd, IndexItem *item)
{
    int index = 0;
    LVITEMW lvi;

    while(item) {
        TRACE("tree debug: %s\n", debugstr_w(item->keyword));

        if(!item->keyword)
        {
            FIXME("HTML Help index item has no keyword.\n");
            item = item->next;
            continue;
        }
        memset(&lvi, 0, sizeof(lvi));
        lvi.iItem = index++;
        lvi.mask = LVIF_TEXT|LVIF_PARAM|LVIF_INDENT;
        lvi.iIndent = item->indentLevel;
        lvi.cchTextMax = strlenW(item->keyword)+1;
        lvi.pszText = item->keyword;
        lvi.lParam = (LPARAM)item;
        item->id = (HTREEITEM)SendMessageW(hwnd, LVM_INSERTITEMW, 0, (LPARAM)&lvi);
        item = item->next;
    }
}

__attribute__((used)) static void item_realloc(IndexItem *item, int num_items)
{
    item->nItems = num_items;
    item->items = heap_realloc(item->items, sizeof(IndexSubItem)*item->nItems);
    item->items[item->nItems-1].name = NULL;
    item->items[item->nItems-1].local = NULL;
    item->itemFlags = 0x00;
}

__attribute__((used)) static void parse_index_obj_node_param(IndexItem *item, const char *text, UINT code_page)
{
    const char *ptr;
    LPWSTR *param;
    int len;

    ptr = get_attr(text, "name", &len);
    if(!ptr) {
        WARN("name attr not found\n");
        return;
    }

    /* Allocate a new sub-item, either on the first run or whenever a
     * sub-topic has filled out both the "name" and "local" params.
     */
    if(item->itemFlags == 0x11 && (!strncasecmp("name", ptr, len) || !strncasecmp("local", ptr, len)))
        item_realloc(item, item->nItems+1);
    if(!strncasecmp("keyword", ptr, len)) {
        param = &item->keyword;
    }else if(!item->keyword && !strncasecmp("name", ptr, len)) {
        /* Some HTML Help index files use an additional "name" parameter
         * rather than the "keyword" parameter.  In this case, the first
         * occurrence of the "name" parameter is the keyword.
         */
        param = &item->keyword;
    }else if(!strncasecmp("name", ptr, len)) {
        item->itemFlags |= 0x01;
        param = &item->items[item->nItems-1].name;
    }else if(!strncasecmp("local", ptr, len)) {
        item->itemFlags |= 0x10;
        param = &item->items[item->nItems-1].local;
    }else {
        WARN("unhandled param %s\n", debugstr_an(ptr, len));
        return;
    }

    ptr = get_attr(text, "value", &len);
    if(!ptr) {
        WARN("value attr not found\n");
        return;
    }

    *param = decode_html(ptr, len, code_page);
}

__attribute__((used)) static IndexItem *parse_index_sitemap_object(HHInfo *info, stream_t *stream)
{
    strbuf_t node, node_name;
    IndexItem *item;

    strbuf_init(&node);
    strbuf_init(&node_name);

    item = heap_alloc_zero(sizeof(IndexItem));
    item->nItems = 0;
    item->items = heap_alloc_zero(0);
    item->itemFlags = 0x11;

    while(next_node(stream, &node)) {
        get_node_name(&node, &node_name);

        TRACE("%s\n", node.buf);

        if(!strcasecmp(node_name.buf, "param")) {
            parse_index_obj_node_param(item, node.buf, info->pCHMInfo->codePage);
        }else if(!strcasecmp(node_name.buf, "/object")) {
            break;
        }else {
            WARN("Unhandled tag! %s\n", node_name.buf);
        }

        strbuf_zero(&node);
    }

    strbuf_free(&node);
    strbuf_free(&node_name);

    return item;
}

__attribute__((used)) static IndexItem *parse_li(HHInfo *info, stream_t *stream)
{
    strbuf_t node, node_name;
    IndexItem *ret = NULL;

    strbuf_init(&node);
    strbuf_init(&node_name);

    while(next_node(stream, &node)) {
        get_node_name(&node, &node_name);

        TRACE("%s\n", node.buf);

        if(!strcasecmp(node_name.buf, "object")) {
            const char *ptr;
            int len;

            static const char sz_text_sitemap[] = "text/sitemap";

            ptr = get_attr(node.buf, "type", &len);

            if(ptr && len == sizeof(sz_text_sitemap)-1
               && !memcmp(ptr, sz_text_sitemap, len)) {
                ret = parse_index_sitemap_object(info, stream);
                break;
            }
        }else {
            WARN("Unhandled tag! %s\n", node_name.buf);
        }

        strbuf_zero(&node);
    }
    if(!ret)
        FIXME("Failed to parse <li> tag!\n");

    strbuf_free(&node);
    strbuf_free(&node_name);

    return ret;
}

__attribute__((used)) static void parse_hhindex(HHInfo *info, IStream *str, IndexItem *item)
{
    stream_t stream;
    strbuf_t node, node_name;
    int indent_level = -1;

    strbuf_init(&node);
    strbuf_init(&node_name);

    stream_init(&stream, str);

    while(next_node(&stream, &node)) {
        get_node_name(&node, &node_name);

        TRACE("%s\n", node.buf);

        if(!strcasecmp(node_name.buf, "li")) {
            IndexItem *new_item;

            new_item = parse_li(info, &stream);
            if(new_item && item->keyword && strcmpW(new_item->keyword, item->keyword) == 0) {
                int num_items = item->nItems;

                item_realloc(item, num_items+1);
                memcpy(&item->items[num_items], &new_item->items[0], sizeof(IndexSubItem));
                heap_free(new_item->keyword);
                heap_free(new_item->items);
                heap_free(new_item);
            } else if(new_item) {
                item->next = new_item;
                item->next->merge = item->merge;
                item = item->next;
                item->indentLevel = indent_level;
            }
        }else if(!strcasecmp(node_name.buf, "ul")) {
            indent_level++;
        }else if(!strcasecmp(node_name.buf, "/ul")) {
            indent_level--;
        }else {
            WARN("Unhandled tag! %s\n", node_name.buf);
        }

        strbuf_zero(&node);
    }

    strbuf_free(&node);
    strbuf_free(&node_name);
}

void InitIndex(HHInfo *info)
{
    IStream *stream;

    info->index = heap_alloc_zero(sizeof(IndexItem));
    info->index->nItems = 0;
    SetChmPath(&info->index->merge, info->pCHMInfo->szFile, info->WinType.pszIndex);

    stream = GetChmStream(info->pCHMInfo, info->pCHMInfo->szFile, &info->index->merge);
    if(!stream) {
        TRACE("Could not get index stream\n");
        return;
    }

    parse_hhindex(info, stream, info->index);
    IStream_Release(stream);

    fill_index_tree(info->tabs[TAB_INDEX].hwnd, info->index->next);
}

void ReleaseIndex(HHInfo *info)
{
    IndexItem *item = info->index, *next;
    int i;

    if(!item) return;
    /* Note: item->merge is identical for all items, only free once */
    heap_free(item->merge.chm_file);
    heap_free(item->merge.chm_index);
    while(item) {
        next = item->next;

        heap_free(item->keyword);
        for(i=0;i<item->nItems;i++) {
            heap_free(item->items[i].name);
            heap_free(item->items[i].local);
        }
        heap_free(item->items);

        item = next;
    }
}

