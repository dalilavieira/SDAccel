#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_6__ ;
typedef  struct TYPE_28__   TYPE_5__ ;
typedef  struct TYPE_27__   TYPE_4__ ;
typedef  struct TYPE_26__   TYPE_3__ ;
typedef  struct TYPE_25__   TYPE_2__ ;
typedef  struct TYPE_24__   TYPE_1__ ;
typedef  struct TYPE_23__   TYPE_17__ ;

/* Type definitions */
struct read_blocklist_closure {scalar_t__ part_start; int num; scalar_t__ total_size; struct grub_fs_block* blocks; } ;
struct grub_fs_block {int offset; int length; } ;
struct grub_dirhook_info {int dummy; } ;
typedef  int grub_ssize_t ;
typedef  scalar_t__ grub_size_t ;
typedef  scalar_t__ grub_off_t ;
typedef  TYPE_3__* grub_fs_t ;
typedef  TYPE_4__* grub_file_t ;
typedef  scalar_t__ grub_err_t ;
typedef  TYPE_5__* grub_disk_t ;
typedef  scalar_t__ grub_disk_addr_t ;
typedef  TYPE_6__* grub_device_t ;
struct TYPE_29__ {TYPE_1__* net; scalar_t__ disk; } ;
struct TYPE_28__ {int total_sectors; void (* read_hook ) (scalar_t__,unsigned int,unsigned int,void*) ;int /*<<< orphan*/  partition; struct read_blocklist_closure* closure; } ;
struct TYPE_27__ {int size; scalar_t__ offset; int flags; void (* read_hook ) (scalar_t__,unsigned int,unsigned int,void*) ;struct grub_fs_block* data; TYPE_17__* fs; struct read_blocklist_closure* closure; TYPE_2__* device; } ;
struct TYPE_26__ {int /*<<< orphan*/  (* dir ) (TYPE_6__*,char*,int (*) (char const*,struct grub_dirhook_info const*,void*),int /*<<< orphan*/ ) ;int /*<<< orphan*/  name; struct TYPE_26__* next; } ;
struct TYPE_25__ {TYPE_5__* disk; } ;
struct TYPE_24__ {TYPE_3__* fs; } ;
struct TYPE_23__ {int /*<<< orphan*/  (* close ) (TYPE_4__*) ;} ;

/* Variables and functions */
 int BLOCKLIST_INC_STEP ; 
 scalar_t__ GRUB_DISK_SECTOR_BITS ; 
 int /*<<< orphan*/  GRUB_ERR_BAD_FILENAME ; 
 scalar_t__ GRUB_ERR_BAD_FS ; 
 scalar_t__ GRUB_ERR_NONE ; 
 int /*<<< orphan*/  GRUB_ERR_UNKNOWN_FS ; 
 int GRUB_ULONG_MAX ; 
 scalar_t__ grub_disk_read_ex (TYPE_5__*,int /*<<< orphan*/ ,scalar_t__,scalar_t__,char*,int) ; 
 int grub_disk_write (TYPE_5__*,int /*<<< orphan*/ ,scalar_t__,scalar_t__,char*) ; 
 int /*<<< orphan*/  grub_dprintf (char*,char*,int /*<<< orphan*/ ) ; 
 scalar_t__ grub_errno ; 
 int /*<<< orphan*/  grub_error (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  grub_error_pop () ; 
 int /*<<< orphan*/  grub_error_push () ; 
 int /*<<< orphan*/  grub_file_read (TYPE_4__*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  grub_free (struct grub_fs_block*) ; 
 scalar_t__ grub_fs_autoload_hook () ; 
 TYPE_17__ grub_fs_blocklist ; 
 TYPE_3__* grub_fs_list ; 
 int /*<<< orphan*/  grub_isspace (char) ; 
 scalar_t__ grub_partition_get_start (int /*<<< orphan*/ ) ; 
 struct grub_fs_block* grub_realloc (struct grub_fs_block*,int) ; 
 char* grub_strchr (char*,char) ; 
 int grub_strtoul (char*,char**,int /*<<< orphan*/ ) ; 
 int grub_strtoull (char*,char**,int /*<<< orphan*/ ) ; 
 struct grub_fs_block* grub_zalloc (int) ; 
 int /*<<< orphan*/  stub1 (TYPE_6__*,char*,int (*) (char const*,struct grub_dirhook_info const*,void*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (TYPE_6__*,char*,int (*) (char const*,struct grub_dirhook_info const*,void*),int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (TYPE_4__*) ; 

__attribute__((used)) static int
dummy_func (const char *filename ,
	    const struct grub_dirhook_info *info  ,
	    void *closure )
{
  return 1;
}

grub_fs_t
grub_fs_probe (grub_device_t device)
{
  grub_fs_t p;

  if (device->disk)
    {
      /* Make it sure not to have an infinite recursive calls.  */
      static int count = 0;

      for (p = grub_fs_list; p; p = p->next)
	{
	  grub_dprintf ("fs", "Detecting %s...\n", p->name);
	  (p->dir) (device, "/", dummy_func, 0);
	  if (grub_errno == GRUB_ERR_NONE)
	    return p;

	  grub_error_push ();
	  grub_dprintf ("fs", "%s detection failed.\n", p->name);
	  grub_error_pop ();

	  if (grub_errno != GRUB_ERR_BAD_FS)
	    return 0;

	  grub_errno = GRUB_ERR_NONE;
	}

      /* Let's load modules automatically.  */
      if (grub_fs_autoload_hook && count == 0)
	{
	  count++;

	  while (grub_fs_autoload_hook ())
	    {
	      p = grub_fs_list;

	      (p->dir) (device, "/", dummy_func, 0);
	      if (grub_errno == GRUB_ERR_NONE)
		{
		  count--;
		  return p;
		}

	      if (grub_errno != GRUB_ERR_BAD_FS)
		{
		  count--;
		  return 0;
		}

	      grub_errno = GRUB_ERR_NONE;
	    }

	  count--;
	}
    }
  else if (device->net->fs)
    return device->net->fs;

  grub_error (GRUB_ERR_UNKNOWN_FS, "unknown filesystem");
  return 0;
}

__attribute__((used)) static grub_err_t
grub_fs_blocklist_open (grub_file_t file, const char *name)
{
  char *p = (char *) name;
  unsigned num = 0;
  unsigned i;
  grub_disk_t disk = file->device->disk;
  struct grub_fs_block *blocks;

  /* First, count the number of blocks.  */
  do
    {
      num++;
      p = grub_strchr (p, ',');
      if (p)
	p++;
    }
  while (p);

  /* Allocate a block list.  */
  blocks = grub_zalloc (sizeof (struct grub_fs_block) * (num + 1));
  if (! blocks)
    return 0;

  file->size = 0;
  p = (char *) name;
  if (! *p)
    {
      blocks[0].offset = 0;
      blocks[0].length = (disk->total_sectors == GRUB_ULONG_MAX) ?
	GRUB_ULONG_MAX : (disk->total_sectors << 9);
      file->size = blocks[0].length;
    }
  else for (i = 0; i < num; i++)
    {
      if (*p != '+')
	{
	  blocks[i].offset = grub_strtoull (p, &p, 0);
	  if (grub_errno != GRUB_ERR_NONE || *p != '+')
	    {
	      grub_error (GRUB_ERR_BAD_FILENAME,
			  "invalid file name `%s'", name);
	      goto fail;
	    }
	}

      p++;
      blocks[i].length = grub_strtoul (p, &p, 0);
      if (grub_errno != GRUB_ERR_NONE
	  || blocks[i].length == 0
	  || (*p && *p != ',' && ! grub_isspace (*p)))
	{
	  grub_error (GRUB_ERR_BAD_FILENAME,
		      "invalid file name `%s'", name);
	  goto fail;
	}

      if (disk->total_sectors < blocks[i].offset + blocks[i].length)
	{
	  grub_error (GRUB_ERR_BAD_FILENAME, "beyond the total sectors");
	  goto fail;
	}

      blocks[i].offset <<= GRUB_DISK_SECTOR_BITS;
      blocks[i].length <<= GRUB_DISK_SECTOR_BITS;
      file->size += blocks[i].length;
      p++;
    }

  file->data = blocks;

  return GRUB_ERR_NONE;

 fail:
  grub_free (blocks);
  return grub_errno;
}

__attribute__((used)) static grub_err_t
grub_fs_blocklist_close (grub_file_t file)
{
  grub_free (file->data);
  return grub_errno;
}

__attribute__((used)) static grub_ssize_t
grub_fs_blocklist_rw (int write, grub_file_t file, char *buf, grub_size_t len)
{
  struct grub_fs_block *p;
  grub_off_t offset;
  grub_ssize_t ret = 0;

  if (len > file->size - file->offset)
    len = file->size - file->offset;

  offset = file->offset;
  for (p = file->data; p->length && len > 0; p++)
    {
      if (offset < p->length)
	{
	  grub_size_t size;

	  size = len;
	  if (offset + size > p->length)
	    size = p->length - offset;

	  if (buf && (write) ?
	       grub_disk_write (file->device->disk, 0, p->offset + offset,
				size, buf) :
	       grub_disk_read_ex (file->device->disk, 0, p->offset + offset,
				  size, buf, file->flags) != GRUB_ERR_NONE)
	    return -1;

	  ret += size;
	  len -= size;
	  if (buf)
	    buf += size;
	  offset += size;
	}
      offset -= p->length;
    }

  return ret;
}

__attribute__((used)) static grub_ssize_t
grub_fs_blocklist_read (grub_file_t file, char *buf, grub_size_t len)
{
  grub_ssize_t ret;
  file->device->disk->read_hook = file->read_hook;
  file->device->disk->closure = file->closure;
  ret = grub_fs_blocklist_rw (0, file, buf, len);
  file->device->disk->read_hook = 0;
  return ret;
}

grub_ssize_t
grub_blocklist_write (grub_file_t file, const char *buf, grub_size_t len)
{
  return (file->fs != &grub_fs_blocklist) ? -1 :
    grub_fs_blocklist_rw (1, file, (char *) buf, len);
}

__attribute__((used)) static void
read_blocklist (grub_disk_addr_t sector, unsigned offset,
		unsigned length, void *closure)
{
  struct read_blocklist_closure *c = closure;

  sector = ((sector - c->part_start) << GRUB_DISK_SECTOR_BITS) + offset;

  if ((c->num) &&
      (c->blocks[c->num - 1].offset + c->blocks[c->num - 1].length == sector))
    {
      c->blocks[c->num - 1].length += length;
      goto quit;
    }

  if ((c->num & (BLOCKLIST_INC_STEP - 1)) == 0)
    {
      c->blocks = grub_realloc (c->blocks, (c->num + BLOCKLIST_INC_STEP) *
				sizeof (struct grub_fs_block));
      if (! c->blocks)
	return;
    }

  c->blocks[c->num].offset = sector;
  c->blocks[c->num].length = length;
  c->num++;

 quit:
  c->total_size += length;
}

void
grub_blocklist_convert (grub_file_t file)
{
  struct read_blocklist_closure c;

  if ((file->fs == &grub_fs_blocklist) || (! file->device->disk) ||
      (! file->size))
    return;

  file->offset = 0;
  file->flags = 1;

  c.num = 0;
  c.blocks = 0;
  c.total_size = 0;
  c.part_start = grub_partition_get_start (file->device->disk->partition);
  file->read_hook = read_blocklist;
  file->closure = &c;
  grub_file_read (file, 0, file->size);
  file->read_hook = 0;
  if ((grub_errno) || (c.total_size != file->size))
    {
      grub_errno = 0;
      grub_free (c.blocks);
    }
  else
    {
      if (file->fs->close)
	(file->fs->close) (file);
      file->fs = &grub_fs_blocklist;
      file->data = c.blocks;
    }

  file->offset = 0;
}

