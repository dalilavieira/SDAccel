#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_4__ ;
typedef  struct TYPE_9__   TYPE_3__ ;
typedef  struct TYPE_8__   TYPE_2__ ;
typedef  struct TYPE_7__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  ut8 ;
typedef  scalar_t__ ut64 ;
struct grub_fs {int dummy; } ;
struct grub_file {struct grub_file* file; TYPE_2__* device; struct grub_fs* fs; void* data; TYPE_3__* dev; } ;
struct grub_disk_dev {int dummy; } ;
struct grub_disk {TYPE_4__* data; TYPE_1__* dev; } ;
struct grub_device {int dummy; } ;
typedef  int const grub_size_t ;
typedef  int grub_err_t ;
typedef  struct grub_disk* grub_disk_t ;
typedef  TYPE_3__* grub_disk_dev_t ;
typedef  int const grub_disk_addr_t ;
struct TYPE_10__ {int /*<<< orphan*/  io; int /*<<< orphan*/  (* read_at ) (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int const) ;} ;
struct TYPE_9__ {int (* read ) (struct grub_disk*,int const,int const,char*) ;} ;
struct TYPE_8__ {struct grub_file* disk; } ;
struct TYPE_7__ {int (* read ) (struct grub_disk*,int const,int const,char*) ;} ;
typedef  TYPE_4__ RIOBind ;
typedef  struct grub_file GrubFS ;

/* Variables and functions */
 TYPE_4__* bio ; 
 scalar_t__ delta ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 int /*<<< orphan*/  free (struct grub_file*) ; 
 void* malloc (int) ; 
 int /*<<< orphan*/  memset (void*,char,int) ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ,scalar_t__,int /*<<< orphan*/ *,int const) ; 

__attribute__((used)) static void* empty (int sz) {
	void *p = malloc (sz);
	if (p) memset (p, '\0', sz);
	return p;
}

__attribute__((used)) static grub_err_t read_foo (struct grub_disk *disk, grub_disk_addr_t sector, grub_size_t size, char *buf) {
	if (!disk) {
		eprintf ("oops. no disk\n");
		return 1;
	}
	const int blocksize = 512; // TODO unhardcode 512
	RIOBind *iob = disk->data;
	if (bio) {
		iob = bio;
	}
	//printf ("io %p\n", file->root->iob.io);
	return !iob->read_at (iob->io, delta+(blocksize*sector), (ut8*)buf, size*blocksize);
}

GrubFS *grubfs_new (struct grub_fs *myfs, void *data) {
	struct grub_file *file;
	GrubFS *gfs = empty (sizeof (GrubFS));
	// hacky mallocs :D
	gfs->file = file = empty (sizeof (struct grub_file));
	file->device = empty (sizeof (struct grub_device)+1024);
	file->device->disk = empty (sizeof (struct grub_disk));
	file->device->disk->dev = (grub_disk_dev_t)file->device; // hack!
	file->device->disk->dev->read = read_foo; // grub_disk_dev
	file->device->disk->data = data;
	//file->device->disk->read_hook = read_foo; //read_hook;
	file->fs = myfs;
	return gfs;
}

grub_disk_t grubfs_disk (void *data) {
	struct grub_disk *disk = empty (sizeof (struct grub_disk));
	disk->dev = empty (sizeof (struct grub_disk_dev));
	disk->dev->read = read_foo; // grub_disk_dev
	disk->data = data;
	return disk;
}

void grubfs_free (GrubFS *gf) {
	if (gf) {
		if (gf->file && gf->file->device) {
			free (gf->file->device->disk);
		}
		//free (gf->file->device);
		free (gf->file);
		free (gf);
	}
}

void grubfs_bind_io (RIOBind *iob, ut64 _delta) {
	bio = iob;
	delta = _delta;
}

