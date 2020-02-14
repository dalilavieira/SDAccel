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
struct user_namespace {int dummy; } ;
struct kqid {int type; int /*<<< orphan*/  projid; int /*<<< orphan*/  gid; int /*<<< orphan*/  uid; } ;
typedef  int /*<<< orphan*/  qid_t ;

/* Variables and functions */
 int /*<<< orphan*/  BUG () ; 
#define  GRPQUOTA 130 
#define  PRJQUOTA 129 
#define  USRQUOTA 128 
 int /*<<< orphan*/  from_kgid (struct user_namespace*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  from_kgid_munged (struct user_namespace*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  from_kprojid (struct user_namespace*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  from_kprojid_munged (struct user_namespace*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  from_kuid (struct user_namespace*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  from_kuid_munged (struct user_namespace*,int /*<<< orphan*/ ) ; 
 int gid_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gid_lt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int gid_valid (int /*<<< orphan*/ ) ; 
 int projid_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int projid_lt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int projid_valid (int /*<<< orphan*/ ) ; 
 int uid_eq (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int uid_lt (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int uid_valid (int /*<<< orphan*/ ) ; 

bool qid_eq(struct kqid left, struct kqid right)
{
	if (left.type != right.type)
		return false;
	switch(left.type) {
	case USRQUOTA:
		return uid_eq(left.uid, right.uid);
	case GRPQUOTA:
		return gid_eq(left.gid, right.gid);
	case PRJQUOTA:
		return projid_eq(left.projid, right.projid);
	default:
		BUG();
	}
}

bool qid_lt(struct kqid left, struct kqid right)
{
	if (left.type < right.type)
		return true;
	if (left.type > right.type)
		return false;
	switch (left.type) {
	case USRQUOTA:
		return uid_lt(left.uid, right.uid);
	case GRPQUOTA:
		return gid_lt(left.gid, right.gid);
	case PRJQUOTA:
		return projid_lt(left.projid, right.projid);
	default:
		BUG();
	}
}

qid_t from_kqid(struct user_namespace *targ, struct kqid kqid)
{
	switch (kqid.type) {
	case USRQUOTA:
		return from_kuid(targ, kqid.uid);
	case GRPQUOTA:
		return from_kgid(targ, kqid.gid);
	case PRJQUOTA:
		return from_kprojid(targ, kqid.projid);
	default:
		BUG();
	}
}

qid_t from_kqid_munged(struct user_namespace *targ, struct kqid kqid)
{
	switch (kqid.type) {
	case USRQUOTA:
		return from_kuid_munged(targ, kqid.uid);
	case GRPQUOTA:
		return from_kgid_munged(targ, kqid.gid);
	case PRJQUOTA:
		return from_kprojid_munged(targ, kqid.projid);
	default:
		BUG();
	}
}

bool qid_valid(struct kqid qid)
{
	switch (qid.type) {
	case USRQUOTA:
		return uid_valid(qid.uid);
	case GRPQUOTA:
		return gid_valid(qid.gid);
	case PRJQUOTA:
		return projid_valid(qid.projid);
	default:
		BUG();
	}
}

