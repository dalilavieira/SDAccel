#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
typedef  int u8 ;
typedef  int u16 ;
struct mv88e6xxx_vtu_entry {int fid; int sid; int vid; int valid; int* member; int* state; } ;
struct TYPE_6__ {int /*<<< orphan*/  domain; } ;
struct mv88e6xxx_chip {scalar_t__ vtu_prob_irq; TYPE_3__ g1_irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  reg_lock; TYPE_2__* ports; TYPE_1__* info; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_5__ {int /*<<< orphan*/  vtu_miss_violation; int /*<<< orphan*/  vtu_member_violation; } ;
struct TYPE_4__ {int pvt; unsigned int num_databases; unsigned int num_ports; unsigned int num_gpio; } ;

/* Variables and functions */
 int EINVAL ; 
 int GENMASK (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ MV88E6352_G1_VTU_FID ; 
 int MV88E6352_G1_VTU_FID_MASK ; 
 scalar_t__ MV88E6352_G1_VTU_SID ; 
 int MV88E6352_G1_VTU_SID_MASK ; 
 int MV88E6390_G1_VTU_VID_PAGE ; 
 int /*<<< orphan*/  MV88E6XXX_G1_STS_IRQ_VTU_PROB ; 
 scalar_t__ MV88E6XXX_G1_VTU_DATA1 ; 
 scalar_t__ MV88E6XXX_G1_VTU_OP ; 
 int MV88E6XXX_G1_VTU_OP_BUSY ; 
 int MV88E6XXX_G1_VTU_OP_FLUSH_ALL ; 
 int MV88E6XXX_G1_VTU_OP_GET_CLR_VIOLATION ; 
 int MV88E6XXX_G1_VTU_OP_MEMBER_VIOLATION ; 
 int MV88E6XXX_G1_VTU_OP_MISS_VIOLATION ; 
 int MV88E6XXX_G1_VTU_OP_SPID_MASK ; 
 int MV88E6XXX_G1_VTU_OP_STU_GET_NEXT ; 
 int MV88E6XXX_G1_VTU_OP_STU_LOAD_PURGE ; 
 int MV88E6XXX_G1_VTU_OP_VTU_GET_NEXT ; 
 int MV88E6XXX_G1_VTU_OP_VTU_LOAD_PURGE ; 
 scalar_t__ MV88E6XXX_G1_VTU_VID ; 
 int MV88E6XXX_G1_VTU_VID_VALID ; 
 int /*<<< orphan*/  dev_dbg_ratelimited (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_err_ratelimited (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  free_irq (int,struct mv88e6xxx_chip*) ; 
 int /*<<< orphan*/  irq_dispose_mapping (int) ; 
 scalar_t__ irq_find_mapping (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mutex_lock (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mutex_unlock (int /*<<< orphan*/ *) ; 
 int mv88e6xxx_g1_read (struct mv88e6xxx_chip*,scalar_t__,int*) ; 
 int mv88e6xxx_g1_wait (struct mv88e6xxx_chip*,scalar_t__,int) ; 
 int mv88e6xxx_g1_write (struct mv88e6xxx_chip*,scalar_t__,int) ; 
 int request_threaded_irq (int,int /*<<< orphan*/ *,int /*<<< orphan*/  (*) (int,void*),int /*<<< orphan*/ ,char*,struct mv88e6xxx_chip*) ; 

__attribute__((used)) static inline bool mv88e6xxx_has_pvt(struct mv88e6xxx_chip *chip)
{
	return chip->info->pvt;
}

__attribute__((used)) static inline unsigned int mv88e6xxx_num_databases(struct mv88e6xxx_chip *chip)
{
	return chip->info->num_databases;
}

__attribute__((used)) static inline unsigned int mv88e6xxx_num_ports(struct mv88e6xxx_chip *chip)
{
	return chip->info->num_ports;
}

__attribute__((used)) static inline u16 mv88e6xxx_port_mask(struct mv88e6xxx_chip *chip)
{
	return GENMASK(mv88e6xxx_num_ports(chip) - 1, 0);
}

__attribute__((used)) static inline unsigned int mv88e6xxx_num_gpio(struct mv88e6xxx_chip *chip)
{
	return chip->info->num_gpio;
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_fid_read(struct mv88e6xxx_chip *chip,
				     struct mv88e6xxx_vtu_entry *entry)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6352_G1_VTU_FID, &val);
	if (err)
		return err;

	entry->fid = val & MV88E6352_G1_VTU_FID_MASK;

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_fid_write(struct mv88e6xxx_chip *chip,
				      struct mv88e6xxx_vtu_entry *entry)
{
	u16 val = entry->fid & MV88E6352_G1_VTU_FID_MASK;

	return mv88e6xxx_g1_write(chip, MV88E6352_G1_VTU_FID, val);
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_sid_read(struct mv88e6xxx_chip *chip,
				     struct mv88e6xxx_vtu_entry *entry)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6352_G1_VTU_SID, &val);
	if (err)
		return err;

	entry->sid = val & MV88E6352_G1_VTU_SID_MASK;

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_sid_write(struct mv88e6xxx_chip *chip,
				      struct mv88e6xxx_vtu_entry *entry)
{
	u16 val = entry->sid & MV88E6352_G1_VTU_SID_MASK;

	return mv88e6xxx_g1_write(chip, MV88E6352_G1_VTU_SID, val);
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_op_wait(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_g1_wait(chip, MV88E6XXX_G1_VTU_OP,
				 MV88E6XXX_G1_VTU_OP_BUSY);
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_op(struct mv88e6xxx_chip *chip, u16 op)
{
	int err;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_VTU_OP,
				 MV88E6XXX_G1_VTU_OP_BUSY | op);
	if (err)
		return err;

	return mv88e6xxx_g1_vtu_op_wait(chip);
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_vid_read(struct mv88e6xxx_chip *chip,
				     struct mv88e6xxx_vtu_entry *entry)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_VTU_VID, &val);
	if (err)
		return err;

	entry->vid = val & 0xfff;

	if (val & MV88E6390_G1_VTU_VID_PAGE)
		entry->vid |= 0x1000;

	entry->valid = !!(val & MV88E6XXX_G1_VTU_VID_VALID);

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_vid_write(struct mv88e6xxx_chip *chip,
				      struct mv88e6xxx_vtu_entry *entry)
{
	u16 val = entry->vid & 0xfff;

	if (entry->vid & 0x1000)
		val |= MV88E6390_G1_VTU_VID_PAGE;

	if (entry->valid)
		val |= MV88E6XXX_G1_VTU_VID_VALID;

	return mv88e6xxx_g1_write(chip, MV88E6XXX_G1_VTU_VID, val);
}

__attribute__((used)) static int mv88e6185_g1_vtu_data_read(struct mv88e6xxx_chip *chip,
				      struct mv88e6xxx_vtu_entry *entry)
{
	u16 regs[3];
	int i;

	/* Read all 3 VTU/STU Data registers */
	for (i = 0; i < 3; ++i) {
		u16 *reg = &regs[i];
		int err;

		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_VTU_DATA1 + i, reg);
		if (err)
			return err;
	}

	/* Extract MemberTag and PortState data */
	for (i = 0; i < mv88e6xxx_num_ports(chip); ++i) {
		unsigned int member_offset = (i % 4) * 4;
		unsigned int state_offset = member_offset + 2;

		entry->member[i] = (regs[i / 4] >> member_offset) & 0x3;
		entry->state[i] = (regs[i / 4] >> state_offset) & 0x3;
	}

	return 0;
}

__attribute__((used)) static int mv88e6185_g1_vtu_data_write(struct mv88e6xxx_chip *chip,
				       struct mv88e6xxx_vtu_entry *entry)
{
	u16 regs[3] = { 0 };
	int i;

	/* Insert MemberTag and PortState data */
	for (i = 0; i < mv88e6xxx_num_ports(chip); ++i) {
		unsigned int member_offset = (i % 4) * 4;
		unsigned int state_offset = member_offset + 2;

		regs[i / 4] |= (entry->member[i] & 0x3) << member_offset;
		regs[i / 4] |= (entry->state[i] & 0x3) << state_offset;
	}

	/* Write all 3 VTU/STU Data registers */
	for (i = 0; i < 3; ++i) {
		u16 reg = regs[i];
		int err;

		err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_VTU_DATA1 + i, reg);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((used)) static int mv88e6390_g1_vtu_data_read(struct mv88e6xxx_chip *chip, u8 *data)
{
	u16 regs[2];
	int i;

	/* Read the 2 VTU/STU Data registers */
	for (i = 0; i < 2; ++i) {
		u16 *reg = &regs[i];
		int err;

		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_VTU_DATA1 + i, reg);
		if (err)
			return err;
	}

	/* Extract data */
	for (i = 0; i < mv88e6xxx_num_ports(chip); ++i) {
		unsigned int offset = (i % 8) * 2;

		data[i] = (regs[i / 8] >> offset) & 0x3;
	}

	return 0;
}

__attribute__((used)) static int mv88e6390_g1_vtu_data_write(struct mv88e6xxx_chip *chip, u8 *data)
{
	u16 regs[2] = { 0 };
	int i;

	/* Insert data */
	for (i = 0; i < mv88e6xxx_num_ports(chip); ++i) {
		unsigned int offset = (i % 8) * 2;

		regs[i / 8] |= (data[i] & 0x3) << offset;
	}

	/* Write the 2 VTU/STU Data registers */
	for (i = 0; i < 2; ++i) {
		u16 reg = regs[i];
		int err;

		err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_VTU_DATA1 + i, reg);
		if (err)
			return err;
	}

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_stu_getnext(struct mv88e6xxx_chip *chip,
					struct mv88e6xxx_vtu_entry *entry)
{
	int err;

	err = mv88e6xxx_g1_vtu_sid_write(chip, entry);
	if (err)
		return err;

	err = mv88e6xxx_g1_vtu_op(chip, MV88E6XXX_G1_VTU_OP_STU_GET_NEXT);
	if (err)
		return err;

	err = mv88e6xxx_g1_vtu_sid_read(chip, entry);
	if (err)
		return err;

	return mv88e6xxx_g1_vtu_vid_read(chip, entry);
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_stu_get(struct mv88e6xxx_chip *chip,
				    struct mv88e6xxx_vtu_entry *vtu)
{
	struct mv88e6xxx_vtu_entry stu;
	int err;

	err = mv88e6xxx_g1_vtu_sid_read(chip, vtu);
	if (err)
		return err;

	stu.sid = vtu->sid - 1;

	err = mv88e6xxx_g1_vtu_stu_getnext(chip, &stu);
	if (err)
		return err;

	if (stu.sid != vtu->sid || !stu.valid)
		return -EINVAL;

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_vtu_getnext(struct mv88e6xxx_chip *chip,
				    struct mv88e6xxx_vtu_entry *entry)
{
	int err;

	err = mv88e6xxx_g1_vtu_op_wait(chip);
	if (err)
		return err;

	/* To get the next higher active VID, the VTU GetNext operation can be
	 * started again without setting the VID registers since it already
	 * contains the last VID.
	 *
	 * To save a few hardware accesses and abstract this to the caller,
	 * write the VID only once, when the entry is given as invalid.
	 */
	if (!entry->valid) {
		err = mv88e6xxx_g1_vtu_vid_write(chip, entry);
		if (err)
			return err;
	}

	err = mv88e6xxx_g1_vtu_op(chip, MV88E6XXX_G1_VTU_OP_VTU_GET_NEXT);
	if (err)
		return err;

	return mv88e6xxx_g1_vtu_vid_read(chip, entry);
}

int mv88e6185_g1_vtu_getnext(struct mv88e6xxx_chip *chip,
			     struct mv88e6xxx_vtu_entry *entry)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_vtu_getnext(chip, entry);
	if (err)
		return err;

	if (entry->valid) {
		err = mv88e6185_g1_vtu_data_read(chip, entry);
		if (err)
			return err;

		/* VTU DBNum[3:0] are located in VTU Operation 3:0
		 * VTU DBNum[7:4] are located in VTU Operation 11:8
		 */
		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_VTU_OP, &val);
		if (err)
			return err;

		entry->fid = val & 0x000f;
		entry->fid |= (val & 0x0f00) >> 4;
	}

	return 0;
}

int mv88e6352_g1_vtu_getnext(struct mv88e6xxx_chip *chip,
			     struct mv88e6xxx_vtu_entry *entry)
{
	int err;

	/* Fetch VLAN MemberTag data from the VTU */
	err = mv88e6xxx_g1_vtu_getnext(chip, entry);
	if (err)
		return err;

	if (entry->valid) {
		/* Fetch (and mask) VLAN PortState data from the STU */
		err = mv88e6xxx_g1_vtu_stu_get(chip, entry);
		if (err)
			return err;

		err = mv88e6185_g1_vtu_data_read(chip, entry);
		if (err)
			return err;

		err = mv88e6xxx_g1_vtu_fid_read(chip, entry);
		if (err)
			return err;
	}

	return 0;
}

int mv88e6390_g1_vtu_getnext(struct mv88e6xxx_chip *chip,
			     struct mv88e6xxx_vtu_entry *entry)
{
	int err;

	/* Fetch VLAN MemberTag data from the VTU */
	err = mv88e6xxx_g1_vtu_getnext(chip, entry);
	if (err)
		return err;

	if (entry->valid) {
		err = mv88e6390_g1_vtu_data_read(chip, entry->member);
		if (err)
			return err;

		/* Fetch VLAN PortState data from the STU */
		err = mv88e6xxx_g1_vtu_stu_get(chip, entry);
		if (err)
			return err;

		err = mv88e6390_g1_vtu_data_read(chip, entry->state);
		if (err)
			return err;

		err = mv88e6xxx_g1_vtu_fid_read(chip, entry);
		if (err)
			return err;
	}

	return 0;
}

int mv88e6185_g1_vtu_loadpurge(struct mv88e6xxx_chip *chip,
			       struct mv88e6xxx_vtu_entry *entry)
{
	u16 op = MV88E6XXX_G1_VTU_OP_VTU_LOAD_PURGE;
	int err;

	err = mv88e6xxx_g1_vtu_op_wait(chip);
	if (err)
		return err;

	err = mv88e6xxx_g1_vtu_vid_write(chip, entry);
	if (err)
		return err;

	if (entry->valid) {
		err = mv88e6185_g1_vtu_data_write(chip, entry);
		if (err)
			return err;

		/* VTU DBNum[3:0] are located in VTU Operation 3:0
		 * VTU DBNum[7:4] are located in VTU Operation 11:8
		 */
		op |= entry->fid & 0x000f;
		op |= (entry->fid & 0x00f0) << 8;
	}

	return mv88e6xxx_g1_vtu_op(chip, op);
}

int mv88e6352_g1_vtu_loadpurge(struct mv88e6xxx_chip *chip,
			       struct mv88e6xxx_vtu_entry *entry)
{
	int err;

	err = mv88e6xxx_g1_vtu_op_wait(chip);
	if (err)
		return err;

	err = mv88e6xxx_g1_vtu_vid_write(chip, entry);
	if (err)
		return err;

	if (entry->valid) {
		/* Write MemberTag and PortState data */
		err = mv88e6185_g1_vtu_data_write(chip, entry);
		if (err)
			return err;

		err = mv88e6xxx_g1_vtu_sid_write(chip, entry);
		if (err)
			return err;

		/* Load STU entry */
		err = mv88e6xxx_g1_vtu_op(chip,
					  MV88E6XXX_G1_VTU_OP_STU_LOAD_PURGE);
		if (err)
			return err;

		err = mv88e6xxx_g1_vtu_fid_write(chip, entry);
		if (err)
			return err;
	}

	/* Load/Purge VTU entry */
	return mv88e6xxx_g1_vtu_op(chip, MV88E6XXX_G1_VTU_OP_VTU_LOAD_PURGE);
}

int mv88e6390_g1_vtu_loadpurge(struct mv88e6xxx_chip *chip,
			       struct mv88e6xxx_vtu_entry *entry)
{
	int err;

	err = mv88e6xxx_g1_vtu_op_wait(chip);
	if (err)
		return err;

	err = mv88e6xxx_g1_vtu_vid_write(chip, entry);
	if (err)
		return err;

	if (entry->valid) {
		/* Write PortState data */
		err = mv88e6390_g1_vtu_data_write(chip, entry->state);
		if (err)
			return err;

		err = mv88e6xxx_g1_vtu_sid_write(chip, entry);
		if (err)
			return err;

		/* Load STU entry */
		err = mv88e6xxx_g1_vtu_op(chip,
					  MV88E6XXX_G1_VTU_OP_STU_LOAD_PURGE);
		if (err)
			return err;

		/* Write MemberTag data */
		err = mv88e6390_g1_vtu_data_write(chip, entry->member);
		if (err)
			return err;

		err = mv88e6xxx_g1_vtu_fid_write(chip, entry);
		if (err)
			return err;
	}

	/* Load/Purge VTU entry */
	return mv88e6xxx_g1_vtu_op(chip, MV88E6XXX_G1_VTU_OP_VTU_LOAD_PURGE);
}

int mv88e6xxx_g1_vtu_flush(struct mv88e6xxx_chip *chip)
{
	int err;

	err = mv88e6xxx_g1_vtu_op_wait(chip);
	if (err)
		return err;

	return mv88e6xxx_g1_vtu_op(chip, MV88E6XXX_G1_VTU_OP_FLUSH_ALL);
}

__attribute__((used)) static irqreturn_t mv88e6xxx_g1_vtu_prob_irq_thread_fn(int irq, void *dev_id)
{
	struct mv88e6xxx_chip *chip = dev_id;
	struct mv88e6xxx_vtu_entry entry;
	int spid;
	int err;
	u16 val;

	mutex_lock(&chip->reg_lock);

	err = mv88e6xxx_g1_vtu_op(chip, MV88E6XXX_G1_VTU_OP_GET_CLR_VIOLATION);
	if (err)
		goto out;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_VTU_OP, &val);
	if (err)
		goto out;

	err = mv88e6xxx_g1_vtu_vid_read(chip, &entry);
	if (err)
		goto out;

	spid = val & MV88E6XXX_G1_VTU_OP_SPID_MASK;

	if (val & MV88E6XXX_G1_VTU_OP_MEMBER_VIOLATION) {
		dev_err_ratelimited(chip->dev, "VTU member violation for vid %d, source port %d\n",
				    entry.vid, spid);
		chip->ports[spid].vtu_member_violation++;
	}

	if (val & MV88E6XXX_G1_VTU_OP_MISS_VIOLATION) {
		dev_dbg_ratelimited(chip->dev, "VTU miss violation for vid %d, source port %d\n",
				    entry.vid, spid);
		chip->ports[spid].vtu_miss_violation++;
	}

	mutex_unlock(&chip->reg_lock);

	return IRQ_HANDLED;

out:
	mutex_unlock(&chip->reg_lock);

	dev_err(chip->dev, "VTU problem: error %d while handling interrupt\n",
		err);

	return IRQ_HANDLED;
}

int mv88e6xxx_g1_vtu_prob_irq_setup(struct mv88e6xxx_chip *chip)
{
	int err;

	chip->vtu_prob_irq = irq_find_mapping(chip->g1_irq.domain,
					      MV88E6XXX_G1_STS_IRQ_VTU_PROB);
	if (chip->vtu_prob_irq < 0)
		return chip->vtu_prob_irq;

	err = request_threaded_irq(chip->vtu_prob_irq, NULL,
				   mv88e6xxx_g1_vtu_prob_irq_thread_fn,
				   IRQF_ONESHOT, "mv88e6xxx-g1-vtu-prob",
				   chip);
	if (err)
		irq_dispose_mapping(chip->vtu_prob_irq);

	return err;
}

void mv88e6xxx_g1_vtu_prob_irq_free(struct mv88e6xxx_chip *chip)
{
	free_irq(chip->vtu_prob_irq, chip);
	irq_dispose_mapping(chip->vtu_prob_irq);
}

