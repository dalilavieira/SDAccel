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
struct TYPE_5__ {int /*<<< orphan*/  domain; } ;
struct mv88e6xxx_chip {scalar_t__ atu_prob_irq; TYPE_2__ g1_irq; int /*<<< orphan*/  dev; int /*<<< orphan*/  reg_lock; TYPE_1__* ports; TYPE_3__* info; } ;
struct mv88e6xxx_atu_entry {int state; int trunk; int portvec; int* mac; int /*<<< orphan*/  member_0; } ;
typedef  int /*<<< orphan*/  irqreturn_t ;
struct TYPE_6__ {int pvt; unsigned int num_databases; unsigned int num_ports; unsigned int num_gpio; unsigned int age_time_coeff; unsigned long atu_move_port_mask; } ;
struct TYPE_4__ {int /*<<< orphan*/  atu_full_violation; int /*<<< orphan*/  atu_miss_violation; int /*<<< orphan*/  atu_member_violation; } ;

/* Variables and functions */
 int EOPNOTSUPP ; 
 int ERANGE ; 
 int GENMASK (unsigned int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  IRQF_ONESHOT ; 
 int /*<<< orphan*/  IRQ_HANDLED ; 
 scalar_t__ MV88E6352_G1_ATU_FID ; 
 scalar_t__ MV88E6XXX_G1_ATU_CTL ; 
 int MV88E6XXX_G1_ATU_CTL_LEARN2ALL ; 
 scalar_t__ MV88E6XXX_G1_ATU_DATA ; 
 int MV88E6XXX_G1_ATU_DATA_STATE_UNUSED ; 
 int MV88E6XXX_G1_ATU_DATA_TRUNK ; 
 scalar_t__ MV88E6XXX_G1_ATU_MAC01 ; 
 scalar_t__ MV88E6XXX_G1_ATU_OP ; 
 int MV88E6XXX_G1_ATU_OP_AGE_OUT_VIOLATION ; 
 int MV88E6XXX_G1_ATU_OP_BUSY ; 
 int MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_ALL ; 
 int MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_ALL_DB ; 
 int MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_NON_STATIC ; 
 int MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_NON_STATIC_DB ; 
 int MV88E6XXX_G1_ATU_OP_FULL_VIOLATION ; 
 int MV88E6XXX_G1_ATU_OP_GET_CLR_VIOLATION ; 
 int MV88E6XXX_G1_ATU_OP_GET_NEXT_DB ; 
 int MV88E6XXX_G1_ATU_OP_LOAD_DB ; 
 int MV88E6XXX_G1_ATU_OP_MEMBER_VIOLATION ; 
 int MV88E6XXX_G1_ATU_OP_MISS_VIOLATION ; 
 int /*<<< orphan*/  MV88E6XXX_G1_STS_IRQ_ATU_PROB ; 
 int bitmap_weight (unsigned long*,int) ; 
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,int) ; 
 int /*<<< orphan*/  dev_err_ratelimited (int /*<<< orphan*/ ,char*,int*,...) ; 
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

__attribute__((used)) static int mv88e6xxx_g1_atu_fid_write(struct mv88e6xxx_chip *chip, u16 fid)
{
	return mv88e6xxx_g1_write(chip, MV88E6352_G1_ATU_FID, fid & 0xfff);
}

int mv88e6xxx_g1_atu_set_learn2all(struct mv88e6xxx_chip *chip, bool learn2all)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_ATU_CTL, &val);
	if (err)
		return err;

	if (learn2all)
		val |= MV88E6XXX_G1_ATU_CTL_LEARN2ALL;
	else
		val &= ~MV88E6XXX_G1_ATU_CTL_LEARN2ALL;

	return mv88e6xxx_g1_write(chip, MV88E6XXX_G1_ATU_CTL, val);
}

int mv88e6xxx_g1_atu_set_age_time(struct mv88e6xxx_chip *chip,
				  unsigned int msecs)
{
	const unsigned int coeff = chip->info->age_time_coeff;
	const unsigned int min = 0x01 * coeff;
	const unsigned int max = 0xff * coeff;
	u8 age_time;
	u16 val;
	int err;

	if (msecs < min || msecs > max)
		return -ERANGE;

	/* Round to nearest multiple of coeff */
	age_time = (msecs + coeff / 2) / coeff;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_ATU_CTL, &val);
	if (err)
		return err;

	/* AgeTime is 11:4 bits */
	val &= ~0xff0;
	val |= age_time << 4;

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_ATU_CTL, val);
	if (err)
		return err;

	dev_dbg(chip->dev, "AgeTime set to 0x%02x (%d ms)\n", age_time,
		age_time * coeff);

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_atu_op_wait(struct mv88e6xxx_chip *chip)
{
	return mv88e6xxx_g1_wait(chip, MV88E6XXX_G1_ATU_OP,
				 MV88E6XXX_G1_ATU_OP_BUSY);
}

__attribute__((used)) static int mv88e6xxx_g1_atu_op(struct mv88e6xxx_chip *chip, u16 fid, u16 op)
{
	u16 val;
	int err;

	/* FID bits are dispatched all around gradually as more are supported */
	if (mv88e6xxx_num_databases(chip) > 256) {
		err = mv88e6xxx_g1_atu_fid_write(chip, fid);
		if (err)
			return err;
	} else {
		if (mv88e6xxx_num_databases(chip) > 16) {
			/* ATU DBNum[7:4] are located in ATU Control 15:12 */
			err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_ATU_CTL,
						&val);
			if (err)
				return err;

			val = (val & 0x0fff) | ((fid << 8) & 0xf000);
			err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_ATU_CTL,
						 val);
			if (err)
				return err;
		}

		/* ATU DBNum[3:0] are located in ATU Operation 3:0 */
		op |= fid & 0xf;
	}

	err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_ATU_OP,
				 MV88E6XXX_G1_ATU_OP_BUSY | op);
	if (err)
		return err;

	return mv88e6xxx_g1_atu_op_wait(chip);
}

__attribute__((used)) static int mv88e6xxx_g1_atu_data_read(struct mv88e6xxx_chip *chip,
				      struct mv88e6xxx_atu_entry *entry)
{
	u16 val;
	int err;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_ATU_DATA, &val);
	if (err)
		return err;

	entry->state = val & 0xf;
	if (entry->state != MV88E6XXX_G1_ATU_DATA_STATE_UNUSED) {
		entry->trunk = !!(val & MV88E6XXX_G1_ATU_DATA_TRUNK);
		entry->portvec = (val >> 4) & mv88e6xxx_port_mask(chip);
	}

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_atu_data_write(struct mv88e6xxx_chip *chip,
				       struct mv88e6xxx_atu_entry *entry)
{
	u16 data = entry->state & 0xf;

	if (entry->state != MV88E6XXX_G1_ATU_DATA_STATE_UNUSED) {
		if (entry->trunk)
			data |= MV88E6XXX_G1_ATU_DATA_TRUNK;

		data |= (entry->portvec & mv88e6xxx_port_mask(chip)) << 4;
	}

	return mv88e6xxx_g1_write(chip, MV88E6XXX_G1_ATU_DATA, data);
}

__attribute__((used)) static int mv88e6xxx_g1_atu_mac_read(struct mv88e6xxx_chip *chip,
				     struct mv88e6xxx_atu_entry *entry)
{
	u16 val;
	int i, err;

	for (i = 0; i < 3; i++) {
		err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_ATU_MAC01 + i, &val);
		if (err)
			return err;

		entry->mac[i * 2] = val >> 8;
		entry->mac[i * 2 + 1] = val & 0xff;
	}

	return 0;
}

__attribute__((used)) static int mv88e6xxx_g1_atu_mac_write(struct mv88e6xxx_chip *chip,
				      struct mv88e6xxx_atu_entry *entry)
{
	u16 val;
	int i, err;

	for (i = 0; i < 3; i++) {
		val = (entry->mac[i * 2] << 8) | entry->mac[i * 2 + 1];
		err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_ATU_MAC01 + i, val);
		if (err)
			return err;
	}

	return 0;
}

int mv88e6xxx_g1_atu_getnext(struct mv88e6xxx_chip *chip, u16 fid,
			     struct mv88e6xxx_atu_entry *entry)
{
	int err;

	err = mv88e6xxx_g1_atu_op_wait(chip);
	if (err)
		return err;

	/* Write the MAC address to iterate from only once */
	if (entry->state == MV88E6XXX_G1_ATU_DATA_STATE_UNUSED) {
		err = mv88e6xxx_g1_atu_mac_write(chip, entry);
		if (err)
			return err;
	}

	err = mv88e6xxx_g1_atu_op(chip, fid, MV88E6XXX_G1_ATU_OP_GET_NEXT_DB);
	if (err)
		return err;

	err = mv88e6xxx_g1_atu_data_read(chip, entry);
	if (err)
		return err;

	return mv88e6xxx_g1_atu_mac_read(chip, entry);
}

int mv88e6xxx_g1_atu_loadpurge(struct mv88e6xxx_chip *chip, u16 fid,
			       struct mv88e6xxx_atu_entry *entry)
{
	int err;

	err = mv88e6xxx_g1_atu_op_wait(chip);
	if (err)
		return err;

	err = mv88e6xxx_g1_atu_mac_write(chip, entry);
	if (err)
		return err;

	err = mv88e6xxx_g1_atu_data_write(chip, entry);
	if (err)
		return err;

	return mv88e6xxx_g1_atu_op(chip, fid, MV88E6XXX_G1_ATU_OP_LOAD_DB);
}

__attribute__((used)) static int mv88e6xxx_g1_atu_flushmove(struct mv88e6xxx_chip *chip, u16 fid,
				      struct mv88e6xxx_atu_entry *entry,
				      bool all)
{
	u16 op;
	int err;

	err = mv88e6xxx_g1_atu_op_wait(chip);
	if (err)
		return err;

	err = mv88e6xxx_g1_atu_data_write(chip, entry);
	if (err)
		return err;

	/* Flush/Move all or non-static entries from all or a given database */
	if (all && fid)
		op = MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_ALL_DB;
	else if (fid)
		op = MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_NON_STATIC_DB;
	else if (all)
		op = MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_ALL;
	else
		op = MV88E6XXX_G1_ATU_OP_FLUSH_MOVE_NON_STATIC;

	return mv88e6xxx_g1_atu_op(chip, fid, op);
}

int mv88e6xxx_g1_atu_flush(struct mv88e6xxx_chip *chip, u16 fid, bool all)
{
	struct mv88e6xxx_atu_entry entry = {
		.state = 0, /* Null EntryState means Flush */
	};

	return mv88e6xxx_g1_atu_flushmove(chip, fid, &entry, all);
}

__attribute__((used)) static int mv88e6xxx_g1_atu_move(struct mv88e6xxx_chip *chip, u16 fid,
				 int from_port, int to_port, bool all)
{
	struct mv88e6xxx_atu_entry entry = { 0 };
	unsigned long mask;
	int shift;

	if (!chip->info->atu_move_port_mask)
		return -EOPNOTSUPP;

	mask = chip->info->atu_move_port_mask;
	shift = bitmap_weight(&mask, 16);

	entry.state = 0xf, /* Full EntryState means Move */
	entry.portvec = from_port & mask;
	entry.portvec |= (to_port & mask) << shift;

	return mv88e6xxx_g1_atu_flushmove(chip, fid, &entry, all);
}

int mv88e6xxx_g1_atu_remove(struct mv88e6xxx_chip *chip, u16 fid, int port,
			    bool all)
{
	int from_port = port;
	int to_port = chip->info->atu_move_port_mask;

	return mv88e6xxx_g1_atu_move(chip, fid, from_port, to_port, all);
}

__attribute__((used)) static irqreturn_t mv88e6xxx_g1_atu_prob_irq_thread_fn(int irq, void *dev_id)
{
	struct mv88e6xxx_chip *chip = dev_id;
	struct mv88e6xxx_atu_entry entry;
	int spid;
	int err;
	u16 val;

	mutex_lock(&chip->reg_lock);

	err = mv88e6xxx_g1_atu_op(chip, 0,
				  MV88E6XXX_G1_ATU_OP_GET_CLR_VIOLATION);
	if (err)
		goto out;

	err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_ATU_OP, &val);
	if (err)
		goto out;

	err = mv88e6xxx_g1_atu_data_read(chip, &entry);
	if (err)
		goto out;

	err = mv88e6xxx_g1_atu_mac_read(chip, &entry);
	if (err)
		goto out;

	spid = entry.state;

	if (val & MV88E6XXX_G1_ATU_OP_AGE_OUT_VIOLATION) {
		dev_err_ratelimited(chip->dev,
				    "ATU age out violation for %pM\n",
				    entry.mac);
	}

	if (val & MV88E6XXX_G1_ATU_OP_MEMBER_VIOLATION) {
		dev_err_ratelimited(chip->dev,
				    "ATU member violation for %pM portvec %x spid %d\n",
				    entry.mac, entry.portvec, spid);
		chip->ports[spid].atu_member_violation++;
	}

	if (val & MV88E6XXX_G1_ATU_OP_MISS_VIOLATION) {
		dev_err_ratelimited(chip->dev,
				    "ATU miss violation for %pM portvec %x spid %d\n",
				    entry.mac, entry.portvec, spid);
		chip->ports[spid].atu_miss_violation++;
	}

	if (val & MV88E6XXX_G1_ATU_OP_FULL_VIOLATION) {
		dev_err_ratelimited(chip->dev,
				    "ATU full violation for %pM portvec %x spid %d\n",
				    entry.mac, entry.portvec, spid);
		chip->ports[spid].atu_full_violation++;
	}
	mutex_unlock(&chip->reg_lock);

	return IRQ_HANDLED;

out:
	mutex_unlock(&chip->reg_lock);

	dev_err(chip->dev, "ATU problem: error %d while handling interrupt\n",
		err);
	return IRQ_HANDLED;
}

int mv88e6xxx_g1_atu_prob_irq_setup(struct mv88e6xxx_chip *chip)
{
	int err;

	chip->atu_prob_irq = irq_find_mapping(chip->g1_irq.domain,
					      MV88E6XXX_G1_STS_IRQ_ATU_PROB);
	if (chip->atu_prob_irq < 0)
		return chip->atu_prob_irq;

	err = request_threaded_irq(chip->atu_prob_irq, NULL,
				   mv88e6xxx_g1_atu_prob_irq_thread_fn,
				   IRQF_ONESHOT, "mv88e6xxx-g1-atu-prob",
				   chip);
	if (err)
		irq_dispose_mapping(chip->atu_prob_irq);

	return err;
}

void mv88e6xxx_g1_atu_prob_irq_free(struct mv88e6xxx_chip *chip)
{
	free_irq(chip->atu_prob_irq, chip);
	irq_dispose_mapping(chip->atu_prob_irq);
}

