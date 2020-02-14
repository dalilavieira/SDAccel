#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_2__ ;
typedef  struct TYPE_13__   TYPE_1__ ;

/* Type definitions */
typedef  long ssize_t ;
typedef  int off_t ;
typedef  int /*<<< orphan*/  cdio_stream_io_functions ;
struct TYPE_14__ {long (* read ) (int /*<<< orphan*/ *,void*,size_t) ;int (* seek ) (int /*<<< orphan*/ *,int,int) ;int (* stat ) (int /*<<< orphan*/ *) ;scalar_t__ (* open ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* free ) (int /*<<< orphan*/ *) ;int /*<<< orphan*/  (* close ) (int /*<<< orphan*/ *) ;} ;
struct TYPE_13__ {int is_open; int position; int /*<<< orphan*/ * user_data; TYPE_2__ op; } ;
typedef  TYPE_1__ CdioDataSource_t ;

/* Variables and functions */
 int DRIVER_OP_ERROR ; 
 int DRIVER_OP_UNINIT ; 
 TYPE_1__* calloc (int,int) ; 
 int /*<<< orphan*/  cdio_assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cdio_debug (char*) ; 
 int /*<<< orphan*/  cdio_warn (char*) ; 
 int /*<<< orphan*/  free (TYPE_1__*) ; 
 scalar_t__ malloc (size_t) ; 
 int /*<<< orphan*/  memcpy (TYPE_2__*,int /*<<< orphan*/  const*,int) ; 
 size_t strlen (char const*) ; 
 scalar_t__ strncpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stub2 (int /*<<< orphan*/ *) ; 
 scalar_t__ stub3 (int /*<<< orphan*/ *) ; 
 long stub4 (int /*<<< orphan*/ *,void*,size_t) ; 
 int stub5 (int /*<<< orphan*/ *,int,int) ; 
 int stub6 (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline char *libcdio_strndup(const char *s, size_t n)
{
    char *result;
    size_t len = strlen (s);
    if (n < len)
        len = n;
    result = (char *) malloc (len + 1);
    if (!result)
        return 0;
    result[len] = '\0';
    return (char *) strncpy (result, s, len);
}

void
cdio_stream_close(CdioDataSource_t *p_obj)
{
  if (!p_obj) return;

  if (p_obj->is_open) {
    cdio_debug ("closed source...");
    p_obj->op.close(p_obj->user_data);
    p_obj->is_open  = 0;
    p_obj->position = 0;
  }
}

void
cdio_stream_destroy(CdioDataSource_t *p_obj)
{
  if (!p_obj) return;

  cdio_stream_close(p_obj);

  p_obj->op.free(p_obj->user_data);
  p_obj->user_data = NULL;
  free(p_obj);
}

off_t
cdio_stream_getpos(CdioDataSource_t* p_obj, /*out*/ off_t *i_offset)
{
  if (!p_obj || !p_obj->is_open) return DRIVER_OP_UNINIT;
  return *i_offset = p_obj->position;
}

CdioDataSource_t *
cdio_stream_new(void *user_data, const cdio_stream_io_functions *funcs)
{
  CdioDataSource_t *new_obj;

  new_obj = calloc (1, sizeof (CdioDataSource_t));
  cdio_assert (new_obj != NULL);

  new_obj->user_data = user_data;
  memcpy(&(new_obj->op), funcs, sizeof(cdio_stream_io_functions));

  return new_obj;
}

__attribute__((used)) static bool
_cdio_stream_open_if_necessary(CdioDataSource_t *p_obj)
{
  if (!p_obj) return false;

  if (!p_obj->is_open) {
    if (p_obj->op.open(p_obj->user_data)) {
      cdio_warn ("could not open input stream...");
      return false;
    } else {
      cdio_debug ("opened source...");
      p_obj->is_open = 1;
      p_obj->position = 0;
    }
  }
  return true;
}

ssize_t
cdio_stream_read(CdioDataSource_t* p_obj, void *ptr, size_t size, size_t nmemb)
{
  long read_bytes;

  if (!p_obj) return 0;
  if (!_cdio_stream_open_if_necessary(p_obj)) return 0;

  read_bytes = (p_obj->op.read)(p_obj->user_data, ptr, size*nmemb);
  p_obj->position += read_bytes;

  return read_bytes;
}

int
cdio_stream_seek(CdioDataSource_t* p_obj, off_t offset, int whence)
{
  if (!p_obj) return DRIVER_OP_UNINIT;

  if (!_cdio_stream_open_if_necessary(p_obj))
    /* errno is set by _cdio_stream_open_if necessary. */
    return DRIVER_OP_ERROR;

  if (offset < 0) return DRIVER_OP_ERROR;
  if (p_obj->position < 0) return DRIVER_OP_ERROR;

  if (p_obj->position != offset) {
#ifdef STREAM_DEBUG
    cdio_warn("had to reposition DataSource from %ld to %ld!", p_obj->position, offset);
#endif
    p_obj->position = offset;
    return p_obj->op.seek(p_obj->user_data, offset, whence);
  }

  return 0;
}

off_t
cdio_stream_stat(CdioDataSource_t *p_obj)
{
  if (!p_obj) return -1;
  if (!_cdio_stream_open_if_necessary(p_obj)) return -1;

  return p_obj->op.stat(p_obj->user_data);
}

