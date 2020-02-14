#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_19__   TYPE_3__ ;
typedef  struct TYPE_18__   TYPE_2__ ;
typedef  struct TYPE_17__   TYPE_1__ ;

/* Type definitions */
struct super_block {int dummy; } ;
struct inode {scalar_t__ i_ino; struct super_block* i_sb; } ;
struct ext3_super_block {scalar_t__ s_journal_inum; scalar_t__ s_journal_dev; int /*<<< orphan*/  s_feature_incompat; } ;
struct block_device {int dummy; } ;
typedef  int /*<<< orphan*/  journal_t ;
typedef  scalar_t__ ULONG ;
struct TYPE_19__ {struct inode Inode; } ;
struct TYPE_18__ {int /*<<< orphan*/  MainResource; int /*<<< orphan*/  Flags; TYPE_1__* SuperBlock; struct super_block sb; struct block_device bd; } ;
struct TYPE_17__ {int /*<<< orphan*/  s_feature_incompat; } ;
typedef  scalar_t__* PULONG ;
typedef  TYPE_2__* PEXT2_VCB ;
typedef  TYPE_3__* PEXT2_MCB ;
typedef  int /*<<< orphan*/  PEXT2_IRP_CONTEXT ;
typedef  int INT ;

/* Variables and functions */
 int /*<<< orphan*/  ClearLongFlag (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  DbgBreak () ; 
 int /*<<< orphan*/  DbgPrint (char*) ; 
 int /*<<< orphan*/  EXT3_FEATURE_INCOMPAT_RECOVER ; 
 int /*<<< orphan*/  ExAcquireResourceExclusiveLite (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  ExReleaseResourceLite (int /*<<< orphan*/ *) ; 
 TYPE_3__* Ext2AllocateMcb (TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Ext2FreeMcb (TYPE_2__*,TYPE_3__*) ; 
 int /*<<< orphan*/  Ext2LoadInode (TYPE_2__*,struct inode*) ; 
 int /*<<< orphan*/  Ext2RefreshGroup (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  Ext2RefreshSuper (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int /*<<< orphan*/  Ext2SaveSuper (int /*<<< orphan*/ ,TYPE_2__*) ; 
 int FALSE ; 
 scalar_t__ IsFlagOn (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ IsVcbReadOnly (TYPE_2__*) ; 
 int /*<<< orphan*/  SetLongFlag (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int TRUE ; 
 int /*<<< orphan*/  VCB_JOURNAL_RECOVER ; 
 int /*<<< orphan*/  iput (struct inode*) ; 
 int /*<<< orphan*/  journal_destroy (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * journal_init_inode (struct inode*) ; 
 int journal_load (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  journal_wipe_recovery (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  sync_blockdev (struct block_device*) ; 

PEXT2_MCB
Ext2LoadInternalJournal(
    PEXT2_VCB         Vcb,
    ULONG             jNo
)
{
    PEXT2_MCB   Jcb = NULL;

    Jcb = Ext2AllocateMcb(Vcb, NULL, NULL, 0);
    if (!Jcb) {
        goto errorout;
    }

    Jcb->Inode.i_ino = jNo;
    Jcb->Inode.i_sb = &Vcb->sb;
    if (!Ext2LoadInode(Vcb, &Jcb->Inode)) {
        DbgBreak();
        Ext2FreeMcb(Vcb, Jcb);
        goto errorout;
    }

errorout:

    return Jcb;
}

INT
Ext2CheckJournal(
    PEXT2_VCB          Vcb,
    PULONG             jNo
)
{
    struct ext3_super_block* esb = NULL;

    /* check ext3 super block */
    esb = (struct ext3_super_block *)Vcb->SuperBlock;
    if (IsFlagOn(esb->s_feature_incompat,
                 EXT3_FEATURE_INCOMPAT_RECOVER)) {
        SetLongFlag(Vcb->Flags, VCB_JOURNAL_RECOVER);
    }

    /* must stop here if volume is read-only */
    if (IsVcbReadOnly(Vcb)) {
        goto errorout;
    }

    /* journal is external ? */
    if (esb->s_journal_inum == 0) {
        goto errorout;
    }

    /* oops: volume is corrupted */
    if (esb->s_journal_dev) {
        goto errorout;
    }

    /* return the journal inode number */
    *jNo = esb->s_journal_inum;

    return TRUE;

errorout:

    return FALSE;
}

INT
Ext2RecoverJournal(
    PEXT2_IRP_CONTEXT  IrpContext,
    PEXT2_VCB          Vcb
)
{
    INT rc = 0;
    ULONG                   jNo = 0;
    PEXT2_MCB               jcb = NULL;
    struct block_device *   bd = &Vcb->bd;
#ifndef __REACTOS__
    struct super_block *    sb = &Vcb->sb;
#endif
    struct inode *          ji = NULL;
    journal_t *             journal = NULL;
    struct ext3_super_block *esb;

    ExAcquireResourceExclusiveLite(&Vcb->MainResource, TRUE);

    /* check journal inode number */
    if (!Ext2CheckJournal(Vcb, &jNo)) {
        rc = -1;
        goto errorout;
    }

    /* allocate journal Mcb */
    jcb =  Ext2LoadInternalJournal(Vcb, jNo);
    if (!jcb) {
        rc = -6;
        goto errorout;
    }

    /* allocate journal inode */
    ji = &jcb->Inode;

    /* initialize journal file from inode */
    journal = journal_init_inode(ji);

    /* initialzation succeeds ? */
    if (!journal) {
        iput(ji);
        rc = -8;
        goto errorout;
    }

    /* start journal recovery */
    rc = journal_load(journal);
    if (0 != rc) {
        rc = -9;
        DbgPrint("Ext2Fsd: recover_journal: failed "
                 "to recover journal data.\n");
    }

    /* reload super_block and group_description */
    Ext2RefreshSuper(IrpContext, Vcb);
    Ext2RefreshGroup(IrpContext, Vcb);

    /* wipe journal data and clear recover flag in sb */
    if (rc == 0) {
        journal_wipe_recovery(journal);
        ClearLongFlag(
            Vcb->SuperBlock->s_feature_incompat,
            EXT3_FEATURE_INCOMPAT_RECOVER );
        Ext2SaveSuper(IrpContext, Vcb);
        sync_blockdev(bd);
        ClearLongFlag(Vcb->Flags, VCB_JOURNAL_RECOVER);
    }

errorout:

    /* destroy journal structure */
    if (journal) {
        journal_destroy(journal);
    }

    /* destory journal Mcb */
    if (jcb) {
        Ext2FreeMcb(Vcb, jcb);
    }

    ExReleaseResourceLite(&Vcb->MainResource);

    return rc;
}

