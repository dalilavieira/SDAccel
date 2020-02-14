#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */
typedef  struct vnode* vnode_t ;
typedef  scalar_t__ uint64_t ;
typedef  scalar_t__ uint32_t ;
struct vnode {int /*<<< orphan*/  v_lflag; } ;
struct uthread {struct doc_tombstone* t_tombstone; } ;
struct doc_tombstone {char* t_lastop_filename; scalar_t__ t_lastop_item_vid; scalar_t__ t_lastop_document_id; struct vnode* t_lastop_item; scalar_t__ t_lastop_fileid; scalar_t__ t_lastop_parent_vid; struct vnode* t_lastop_parent; } ;
struct componentname {char* cn_nameptr; int cn_namelen; } ;
typedef  scalar_t__ ino64_t ;

/* Variables and functions */
 int /*<<< orphan*/  ISSET (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  VL_TERMINATE ; 
 int /*<<< orphan*/  current_thread () ; 
 struct uthread* get_bsdthread_info (int /*<<< orphan*/ ) ; 
 struct doc_tombstone* kalloc (int) ; 
 int /*<<< orphan*/  memset (struct doc_tombstone*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  strlcpy (char*,char*,int) ; 
 int strlen (char const*) ; 
 scalar_t__ strncmp (char const*,char*,int) ; 
 int vnode_get (struct vnode*) ; 
 int /*<<< orphan*/  vnode_put (struct vnode*) ; 
 scalar_t__ vnode_vid (struct vnode*) ; 

struct doc_tombstone *
doc_tombstone_get(void)
{
	struct  uthread *ut;
	ut = get_bsdthread_info(current_thread());

	if (ut->t_tombstone == NULL) {
		ut->t_tombstone = kalloc(sizeof(struct doc_tombstone));
		if (ut->t_tombstone) {
			memset(ut->t_tombstone, 0, sizeof(struct doc_tombstone));
		}
	}

	return ut->t_tombstone;
}

void
doc_tombstone_clear(struct doc_tombstone *ut, vnode_t *old_vpp)
{
	uint32_t old_id = ut->t_lastop_document_id;

	ut->t_lastop_document_id = 0;
	ut->t_lastop_parent = NULL;
	ut->t_lastop_parent_vid = 0;
	ut->t_lastop_filename[0] = '\0';

	//
	// If the lastop item is still the same and needs to be cleared,
	// clear it.  The following isn't ideal because the vnode might
	// have been recycled.
	//
	if (old_vpp) {
		*old_vpp = NULL;
		if (old_id && ut->t_lastop_item
			&& vnode_vid(ut->t_lastop_item) == ut->t_lastop_item_vid) {
			int res = vnode_get(ut->t_lastop_item);
			if (!res) {
				// Need to check vid again
				if (vnode_vid(ut->t_lastop_item) == ut->t_lastop_item_vid
					&& !ISSET(ut->t_lastop_item->v_lflag, VL_TERMINATE))
					*old_vpp = ut->t_lastop_item;
				else
					vnode_put(ut->t_lastop_item);
			}
		}
	}

	// last, clear these now that we're all done
	ut->t_lastop_item     = NULL;
	ut->t_lastop_fileid   = 0;
	ut->t_lastop_item_vid = 0;
}

bool doc_tombstone_should_ignore_name(const char *nameptr, int len)
{
	if (len == 0) {
		len = strlen(nameptr);
	}

	if (   strncmp(nameptr, "atmp", 4) == 0
		|| (len > 4 && strncmp(nameptr+len-4, ".bak", 4) == 0)
		|| (len > 4 && strncmp(nameptr+len-4, ".tmp", 4) == 0)) {
		return true;
	}

	return false;
}

bool doc_tombstone_should_save(struct doc_tombstone *ut, struct vnode *vp,
							   struct componentname *cnp)
{
	if (cnp->cn_nameptr == NULL) {
		return false;
	}

	if (ut->t_lastop_document_id && ut->t_lastop_item == vp
		&& doc_tombstone_should_ignore_name(cnp->cn_nameptr, cnp->cn_namelen)) {
		return false;
	}

	return true;
}

void
doc_tombstone_save(struct vnode *dvp, struct vnode *vp,
				   struct componentname *cnp, uint64_t doc_id,
				   ino64_t file_id)
{
	struct  doc_tombstone *ut;
	ut = doc_tombstone_get();

	ut->t_lastop_parent         = dvp;
	ut->t_lastop_parent_vid     = vnode_vid(dvp);
	ut->t_lastop_fileid         = file_id;
	ut->t_lastop_item           = vp;
	ut->t_lastop_item_vid       = vp ? vnode_vid(vp) : 0;
    ut->t_lastop_document_id    = doc_id;

	strlcpy((char *)&ut->t_lastop_filename[0], cnp->cn_nameptr, sizeof(ut->t_lastop_filename));
}

