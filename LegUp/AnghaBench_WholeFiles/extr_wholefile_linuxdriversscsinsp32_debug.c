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
struct scsi_cmnd {unsigned char* cmnd; } ;

/* Variables and functions */
 int /*<<< orphan*/  ACK_WIDTH ; 
 int /*<<< orphan*/  ARBIT_STATUS ; 
 unsigned short AUTOSCSI_BUSY ; 
 int /*<<< orphan*/  BM_CNT ; 
 int /*<<< orphan*/  BM_START_ADR ; 
#define  BUSPHASE_COMMAND 137 
#define  BUSPHASE_DATA_IN 136 
#define  BUSPHASE_DATA_OUT 135 
#define  BUSPHASE_MESSAGE_IN 134 
#define  BUSPHASE_MESSAGE_OUT 133 
#define  BUSPHASE_SELECT 132 
#define  BUSPHASE_STATUS 131 
 unsigned short BUS_FREE_OCCUER ; 
 int /*<<< orphan*/  COMMAND_CONTROL ; 
 unsigned short COMMAND_PHASE ; 
 int COMMAND_SIZE (unsigned char) ; 
 unsigned short DATA_IN_PHASE ; 
 unsigned short DATA_OUT_PHASE ; 
 int /*<<< orphan*/  FIFO_REST_CNT ; 
 unsigned short ILLEGAL_PHASE ; 
 int /*<<< orphan*/  IRQ_STATUS ; 
 int /*<<< orphan*/  MISC_WR ; 
 unsigned short MSGIN_00_VALID ; 
 unsigned short MSGIN_02_VALID ; 
 unsigned short MSGIN_03_VALID ; 
 unsigned short MSGIN_04_VALID ; 
 unsigned short MSGOUT_PHASE ; 
 unsigned short MSG_IN_OCCUER ; 
 unsigned short MSG_OUT_OCCUER ; 
#define  NOTEXT_GROUP 130 
 int NSP32_DEBUG_MASK ; 
 int NSP32_SPECIAL_PRINT_REGISTER ; 
 int /*<<< orphan*/  OLD_SCSI_PHASE ; 
#define  RESERVED_GROUP 129 
 int /*<<< orphan*/  SACK_CNT ; 
 int /*<<< orphan*/  SAVED_SACK_CNT ; 
 int /*<<< orphan*/  SCSI_BUS_CONTROL ; 
 int /*<<< orphan*/  SCSI_BUS_MONITOR ; 
 int /*<<< orphan*/  SCSI_CSB_IN ; 
 int /*<<< orphan*/  SCSI_EXECUTE_PHASE ; 
 int /*<<< orphan*/  SCSI_MSG_OUT ; 
 int /*<<< orphan*/  SCSI_OUT_LATCH_TARGET_ID ; 
 unsigned short SELECTION_TIMEOUT ; 
 int /*<<< orphan*/  SEL_TIME_OUT ; 
 int /*<<< orphan*/  SGT_ADR ; 
 int /*<<< orphan*/  SREQ_CNT ; 
 int /*<<< orphan*/  SREQ_SMPL_RATE ; 
 unsigned short STATUS_PHASE ; 
 int /*<<< orphan*/  SYNC_REG ; 
 int /*<<< orphan*/  TRANSFER_STATUS ; 
#define  VENDOR_GROUP 128 
 char*** commands ; 
 size_t group (unsigned char) ; 
 int /*<<< orphan*/  nsp32_index_read1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nsp32_index_read2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nsp32_read1 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nsp32_read2 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nsp32_read4 (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  printk (char*,...) ; 
 int /*<<< orphan*/  reserved ; 
 char const* unknown ; 
 int /*<<< orphan*/  vendor ; 

__attribute__((used)) static void print_opcodek(unsigned char opcode)
{
	const char **table = commands[ group(opcode) ];

	switch ((unsigned long) table) {
	case RESERVED_GROUP:
		printk("%s[%02x] ", reserved, opcode); 
		break;
	case NOTEXT_GROUP:
		printk("%s(notext)[%02x] ", unknown, opcode); 
		break;
	case VENDOR_GROUP:
		printk("%s[%02x] ", vendor, opcode); 
		break;
	default:
		if (table[opcode & 0x1f] != unknown)
			printk("%s[%02x] ", table[opcode & 0x1f], opcode);
		else
			printk("%s[%02x] ", unknown, opcode);
		break;
	}
}

__attribute__((used)) static void print_commandk (unsigned char *command)
{
	int i,s;
//	printk(KERN_DEBUG);
	print_opcodek(command[0]);
	/*printk(KERN_DEBUG "%s ", __func__);*/
	if ((command[0] >> 5) == 6 ||
	    (command[0] >> 5) == 7 ) {
		s = 12; /* vender specific */
	} else {
		s = COMMAND_SIZE(command[0]);
	}

	for ( i = 1; i < s; ++i) {
		printk("%02x ", command[i]);
	}

	switch (s) {
	case 6:
		printk("LBA=%d len=%d",
		       (((unsigned int)command[1] & 0x0f) << 16) |
		       ( (unsigned int)command[2]         <<  8) |
		       ( (unsigned int)command[3]              ),
		       (unsigned int)command[4]
			);
		break;
	case 10:
		printk("LBA=%d len=%d",
		       ((unsigned int)command[2] << 24) |
		       ((unsigned int)command[3] << 16) |
		       ((unsigned int)command[4] <<  8) |
		       ((unsigned int)command[5]      ),
		       ((unsigned int)command[7] <<  8) |
		       ((unsigned int)command[8]      )
		       );
		break;
	case 12:
		printk("LBA=%d len=%d",
		       ((unsigned int)command[2] << 24) |
		       ((unsigned int)command[3] << 16) |
		       ((unsigned int)command[4] <<  8) |
		       ((unsigned int)command[5]      ),
		       ((unsigned int)command[6] << 24) |
		       ((unsigned int)command[7] << 16) |
		       ((unsigned int)command[8] <<  8) |
		       ((unsigned int)command[9]      )
		       );
		break;
	default:
		break;
	}
	printk("\n");
}

__attribute__((used)) static void show_command(struct scsi_cmnd *SCpnt)
{
	print_commandk(SCpnt->cmnd);
}

__attribute__((used)) static void show_busphase(unsigned char stat)
{
	switch(stat) {
	case BUSPHASE_COMMAND:
		printk( "BUSPHASE_COMMAND\n");
		break;
	case BUSPHASE_MESSAGE_IN:
		printk( "BUSPHASE_MESSAGE_IN\n");
		break;
	case BUSPHASE_MESSAGE_OUT:
		printk( "BUSPHASE_MESSAGE_OUT\n");
		break;
	case BUSPHASE_DATA_IN:
		printk( "BUSPHASE_DATA_IN\n");
		break;
	case BUSPHASE_DATA_OUT:
		printk( "BUSPHASE_DATA_OUT\n");
		break;
	case BUSPHASE_STATUS:
		printk( "BUSPHASE_STATUS\n");
		break;
	case BUSPHASE_SELECT:
		printk( "BUSPHASE_SELECT\n");
		break;
	default:
		printk( "BUSPHASE_other: 0x%x\n", stat);
		break;
	}
}

__attribute__((used)) static void show_autophase(unsigned short i)
{
	printk("auto: 0x%x,", i);

	if(i & COMMAND_PHASE) {
		printk(" cmd");
	}
	if(i & DATA_IN_PHASE) {
		printk(" din");
	}
	if(i & DATA_OUT_PHASE) {
		printk(" dout");
	}
	if(i & MSGOUT_PHASE) {
		printk(" mout");
	}
	if(i & STATUS_PHASE) {
		printk(" stat");
	}
	if(i & ILLEGAL_PHASE) {
		printk(" ill");
	}
	if(i & BUS_FREE_OCCUER) {
		printk(" bfree-o");
	}
	if(i & MSG_IN_OCCUER) {
		printk(" min-o");
	}
	if(i & MSG_OUT_OCCUER) {
		printk(" mout-o");
	}
	if(i & SELECTION_TIMEOUT) {
		printk(" sel");
	}
	if(i & MSGIN_00_VALID) {
		printk(" m0");
	}
	if(i & MSGIN_02_VALID) {
		printk(" m2");
	}
	if(i & MSGIN_03_VALID) {
		printk(" m3");
	}
	if(i & MSGIN_04_VALID) {
		printk(" m4");
	}
	if(i & AUTOSCSI_BUSY) {
		printk(" busy");
	}

	printk("\n");
}

__attribute__((used)) static void nsp32_print_register(int base)
{
	if (!(NSP32_DEBUG_MASK & NSP32_SPECIAL_PRINT_REGISTER))
		return;

	printk("Phase=0x%x, ", nsp32_read1(base, SCSI_BUS_MONITOR));
	printk("OldPhase=0x%x, ", nsp32_index_read1(base, OLD_SCSI_PHASE));
	printk("syncreg=0x%x, ", nsp32_read1(base, SYNC_REG));
	printk("ackwidth=0x%x, ", nsp32_read1(base, ACK_WIDTH));
	printk("sgtpaddr=0x%lx, ", nsp32_read4(base, SGT_ADR));
	printk("scsioutlatch=0x%x, ", nsp32_read1(base, SCSI_OUT_LATCH_TARGET_ID));
	printk("msgout=0x%lx, ", nsp32_read4(base, SCSI_MSG_OUT));
	printk("miscrd=0x%x, ", nsp32_index_read2(base, MISC_WR));
	printk("seltimeout=0x%x, ", nsp32_read2(base, SEL_TIME_OUT));
	printk("sreqrate=0x%x, ", nsp32_read1(base, SREQ_SMPL_RATE));
	printk("transStatus=0x%x, ", nsp32_read2(base, TRANSFER_STATUS));
	printk("reselectid=0x%x, ", nsp32_read2(base, COMMAND_CONTROL));
	printk("arbit=0x%x, ", nsp32_read1(base, ARBIT_STATUS));
	printk("BmStart=0x%lx, ", nsp32_read4(base, BM_START_ADR));
	printk("BmCount=0x%lx, ", nsp32_read4(base, BM_CNT));
	printk("SackCnt=0x%lx, ", nsp32_read4(base, SACK_CNT));
	printk("SReqCnt=0x%lx, ", nsp32_read4(base, SREQ_CNT));
	printk("SavedSackCnt=0x%lx, ", nsp32_read4(base, SAVED_SACK_CNT));
	printk("ScsiBusControl=0x%x, ", nsp32_read1(base, SCSI_BUS_CONTROL));
	printk("FifoRestCnt=0x%x, ", nsp32_read2(base, FIFO_REST_CNT));
	printk("CdbIn=0x%x, ", nsp32_read1(base, SCSI_CSB_IN));
	printk("\n");

	if (0) {
		printk("execph=0x%x, ", nsp32_read2(base, SCSI_EXECUTE_PHASE));
		printk("IrqStatus=0x%x, ", nsp32_read2(base, IRQ_STATUS));
		printk("\n");
	}
}

