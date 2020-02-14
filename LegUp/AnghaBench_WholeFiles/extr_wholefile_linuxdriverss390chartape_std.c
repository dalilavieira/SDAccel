#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct timer_list {int dummy; } ;
struct tape_request {int size; scalar_t__ rescnt; struct ccw1* cpaddr; void* op; void* cpdata; int /*<<< orphan*/  timer; struct tape_device* device; int /*<<< orphan*/ * callback_data; void* callback; } ;
struct TYPE_2__ {int block_size; struct tape_request* idal_buf; } ;
struct tape_device {scalar_t__ tape_state; int* modeset_byte; scalar_t__ required_tapemarks; scalar_t__ medium_state; TYPE_1__ char_data; int /*<<< orphan*/  state_change_wq; int /*<<< orphan*/  first_minor; int /*<<< orphan*/  cdev_id; } ;
struct idal_buffer {int size; scalar_t__ rescnt; struct ccw1* cpaddr; void* op; void* cpdata; int /*<<< orphan*/  timer; struct tape_device* device; int /*<<< orphan*/ * callback_data; void* callback; } ;
struct display_struct {unsigned char cntrl; int /*<<< orphan*/  message2; int /*<<< orphan*/  message1; } ;
struct ccw1 {void* flags; void* cmd_code; void* cda; void* count; } ;
typedef  scalar_t__ addr_t ;
typedef  void* __u8 ;
typedef  int /*<<< orphan*/  __u64 ;
typedef  void* __u32 ;
typedef  void* __u16 ;

/* Variables and functions */
 int /*<<< orphan*/  ASCEBC (unsigned char*,int) ; 
 void* ASSIGN ; 
 void* BACKSPACEBLOCK ; 
 void* BACKSPACEFILE ; 
 int /*<<< orphan*/  BUG_ON (int) ; 
 void* CCW_CMD_TIC ; 
 void* CCW_FLAG_CC ; 
 void* DATA_SEC_ERASE ; 
 int /*<<< orphan*/  DBF_EVENT (int,char*,...) ; 
 int /*<<< orphan*/  DBF_EXCEPTION (int,char*) ; 
 int /*<<< orphan*/  DBF_LH (int,char*,...) ; 
 int EINVAL ; 
 int EIO ; 
 int ENOMEM ; 
 void* ERASE_GAP ; 
 void* FORSPACEBLOCK ; 
 void* FORSPACEFILE ; 
 int HZ ; 
 scalar_t__ IS_ERR (struct tape_request*) ; 
 void* LOAD_DISPLAY ; 
 int MAX_BLOCKSIZE ; 
 void* MODE_SET_DB ; 
 scalar_t__ MS_LOADED ; 
 int /*<<< orphan*/  MTBSR ; 
 int /*<<< orphan*/  MTFSF ; 
 int /*<<< orphan*/  MTFSR ; 
 int /*<<< orphan*/  MTOFFL ; 
 int /*<<< orphan*/  MTREW ; 
 int /*<<< orphan*/  MTWEOF ; 
 void* NOP ; 
 int PTR_ERR (struct tape_request*) ; 
 void* READ_BACKWARD ; 
 void* READ_BLOCK_ID ; 
 void* READ_FORWARD ; 
 void* REWIND ; 
 void* REWIND_UNLOAD ; 
 void* TO_ASSIGN ; 
 void* TO_BSB ; 
 void* TO_BSF ; 
 void* TO_DIS ; 
 void* TO_DSE ; 
 void* TO_FSB ; 
 void* TO_FSF ; 
 void* TO_NOP ; 
 void* TO_RBA ; 
 void* TO_RBI ; 
 void* TO_REW ; 
 void* TO_RFO ; 
 void* TO_RUN ; 
 void* TO_UNASSIGN ; 
 void* TO_WRI ; 
 void* TO_WTM ; 
 scalar_t__ TS_NOT_OPER ; 
 void* UNASSIGN ; 
 void* WRITETAPEMARK ; 
 void* WRITE_CMD ; 
 int /*<<< orphan*/  del_timer_sync (int /*<<< orphan*/ *) ; 
 struct tape_request* from_timer (int /*<<< orphan*/ ,struct timer_list*,int /*<<< orphan*/ ) ; 
 struct tape_request* idal_buffer_alloc (int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  idal_buffer_free (struct tape_request*) ; 
 int /*<<< orphan*/  idal_buffer_set_cda (struct tape_request*,struct ccw1*) ; 
 scalar_t__ jiffies ; 
 int /*<<< orphan*/  memcpy (unsigned char*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  mod_timer (struct timer_list*,scalar_t__) ; 
 struct tape_request* request ; 
 struct tape_request* tape_alloc_request (int,int) ; 
 int tape_cancel_io (struct tape_device*,struct tape_request*) ; 
 int tape_do_io (struct tape_device*,struct tape_request*) ; 
 int /*<<< orphan*/  tape_do_io_async (struct tape_device*,struct tape_request*) ; 
 int tape_do_io_interruptible (struct tape_device*,struct tape_request*) ; 
 int /*<<< orphan*/  tape_free_request (struct tape_request*) ; 
 int tape_mtop (struct tape_device*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  timer ; 
 int /*<<< orphan*/  timer_setup (int /*<<< orphan*/ *,void (*) (struct timer_list*),int /*<<< orphan*/ ) ; 
 int wait_event_interruptible (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int
tape_do_io_free(struct tape_device *device, struct tape_request *request)
{
	int rc;

	rc = tape_do_io(device, request);
	tape_free_request(request);
	return rc;
}

__attribute__((used)) static inline void
tape_do_io_async_free(struct tape_device *device, struct tape_request *request)
{
	request->callback = (void *) tape_free_request;
	request->callback_data = NULL;
	tape_do_io_async(device, request);
}

__attribute__((used)) static inline void tape_proc_init (void) {;}

__attribute__((used)) static inline void tape_proc_cleanup (void) {;}

__attribute__((used)) static inline struct ccw1 *
tape_ccw_cc(struct ccw1 *ccw, __u8 cmd_code, __u16 memsize, void *cda)
{
	ccw->cmd_code = cmd_code;
	ccw->flags = CCW_FLAG_CC;
	ccw->count = memsize;
	ccw->cda = (__u32)(addr_t) cda;
	return ccw + 1;
}

__attribute__((used)) static inline struct ccw1 *
tape_ccw_end(struct ccw1 *ccw, __u8 cmd_code, __u16 memsize, void *cda)
{
	ccw->cmd_code = cmd_code;
	ccw->flags = 0;
	ccw->count = memsize;
	ccw->cda = (__u32)(addr_t) cda;
	return ccw + 1;
}

__attribute__((used)) static inline struct ccw1 *
tape_ccw_cmd(struct ccw1 *ccw, __u8 cmd_code)
{
	ccw->cmd_code = cmd_code;
	ccw->flags = 0;
	ccw->count = 0;
	ccw->cda = (__u32)(addr_t) &ccw->cmd_code;
	return ccw + 1;
}

__attribute__((used)) static inline struct ccw1 *
tape_ccw_repeat(struct ccw1 *ccw, __u8 cmd_code, int count)
{
	while (count-- > 0) {
		ccw->cmd_code = cmd_code;
		ccw->flags = CCW_FLAG_CC;
		ccw->count = 0;
		ccw->cda = (__u32)(addr_t) &ccw->cmd_code;
		ccw++;
	}
	return ccw;
}

__attribute__((used)) static inline struct ccw1 *
tape_ccw_cc_idal(struct ccw1 *ccw, __u8 cmd_code, struct idal_buffer *idal)
{
	ccw->cmd_code = cmd_code;
	ccw->flags    = CCW_FLAG_CC;
	idal_buffer_set_cda(idal, ccw);
	return ccw++;
}

__attribute__((used)) static inline struct ccw1 *
tape_ccw_end_idal(struct ccw1 *ccw, __u8 cmd_code, struct idal_buffer *idal)
{
	ccw->cmd_code = cmd_code;
	ccw->flags    = 0;
	idal_buffer_set_cda(idal, ccw);
	return ccw++;
}

__attribute__((used)) static void
tape_std_assign_timeout(struct timer_list *t)
{
	struct tape_request *	request = from_timer(request, t, timer);
	struct tape_device *	device = request->device;
	int rc;

	BUG_ON(!device);

	DBF_EVENT(3, "%08x: Assignment timeout. Device busy.\n",
			device->cdev_id);
	rc = tape_cancel_io(device, request);
	if(rc)
		DBF_EVENT(3, "(%08x): Assign timeout: Cancel failed with rc = "
			  "%i\n", device->cdev_id, rc);
}

int
tape_std_assign(struct tape_device *device)
{
	int                  rc;
	struct timer_list    timeout;
	struct tape_request *request;

	request = tape_alloc_request(2, 11);
	if (IS_ERR(request))
		return PTR_ERR(request);

	request->op = TO_ASSIGN;
	tape_ccw_cc(request->cpaddr, ASSIGN, 11, request->cpdata);
	tape_ccw_end(request->cpaddr + 1, NOP, 0, NULL);

	/*
	 * The assign command sometimes blocks if the device is assigned
	 * to another host (actually this shouldn't happen but it does).
	 * So we set up a timeout for this call.
	 */
	timer_setup(&request->timer, tape_std_assign_timeout, 0);
	mod_timer(&timeout, jiffies + 2 * HZ);

	rc = tape_do_io_interruptible(device, request);

	del_timer_sync(&request->timer);

	if (rc != 0) {
		DBF_EVENT(3, "%08x: assign failed - device might be busy\n",
			device->cdev_id);
	} else {
		DBF_EVENT(3, "%08x: Tape assigned\n", device->cdev_id);
	}
	tape_free_request(request);
	return rc;
}

int
tape_std_unassign (struct tape_device *device)
{
	int                  rc;
	struct tape_request *request;

	if (device->tape_state == TS_NOT_OPER) {
		DBF_EVENT(3, "(%08x): Can't unassign device\n",
			device->cdev_id);
		return -EIO;
	}

	request = tape_alloc_request(2, 11);
	if (IS_ERR(request))
		return PTR_ERR(request);

	request->op = TO_UNASSIGN;
	tape_ccw_cc(request->cpaddr, UNASSIGN, 11, request->cpdata);
	tape_ccw_end(request->cpaddr + 1, NOP, 0, NULL);

	if ((rc = tape_do_io(device, request)) != 0) {
		DBF_EVENT(3, "%08x: Unassign failed\n", device->cdev_id);
	} else {
		DBF_EVENT(3, "%08x: Tape unassigned\n", device->cdev_id);
	}
	tape_free_request(request);
	return rc;
}

int
tape_std_display(struct tape_device *device, struct display_struct *disp)
{
	struct tape_request *request;
	int rc;

	request = tape_alloc_request(2, 17);
	if (IS_ERR(request)) {
		DBF_EVENT(3, "TAPE: load display failed\n");
		return PTR_ERR(request);
	}
	request->op = TO_DIS;

	*(unsigned char *) request->cpdata = disp->cntrl;
	DBF_EVENT(5, "TAPE: display cntrl=%04x\n", disp->cntrl);
	memcpy(((unsigned char *) request->cpdata) + 1, disp->message1, 8);
	memcpy(((unsigned char *) request->cpdata) + 9, disp->message2, 8);
	ASCEBC(((unsigned char*) request->cpdata) + 1, 16);

	tape_ccw_cc(request->cpaddr, LOAD_DISPLAY, 17, request->cpdata);
	tape_ccw_end(request->cpaddr + 1, NOP, 0, NULL);

	rc = tape_do_io_interruptible(device, request);
	tape_free_request(request);
	return rc;
}

int
tape_std_read_block_id(struct tape_device *device, __u64 *id)
{
	struct tape_request *request;
	int rc;

	request = tape_alloc_request(3, 8);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_RBI;
	/* setup ccws */
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_cc(request->cpaddr + 1, READ_BLOCK_ID, 8, request->cpdata);
	tape_ccw_end(request->cpaddr + 2, NOP, 0, NULL);
	/* execute it */
	rc = tape_do_io(device, request);
	if (rc == 0)
		/* Get result from read buffer. */
		*id = *(__u64 *) request->cpdata;
	tape_free_request(request);
	return rc;
}

int
tape_std_terminate_write(struct tape_device *device)
{
	int rc;

	if(device->required_tapemarks == 0)
		return 0;

	DBF_LH(5, "tape%d: terminate write %dxEOF\n", device->first_minor,
		device->required_tapemarks);

	rc = tape_mtop(device, MTWEOF, device->required_tapemarks);
	if (rc)
		return rc;

	device->required_tapemarks = 0;
	return tape_mtop(device, MTBSR, 1);
}

int
tape_std_mtload(struct tape_device *device, int count)
{
	return wait_event_interruptible(device->state_change_wq,
		(device->medium_state == MS_LOADED));
}

int
tape_std_mtsetblk(struct tape_device *device, int count)
{
	struct idal_buffer *new;

	DBF_LH(6, "tape_std_mtsetblk(%d)\n", count);
	if (count <= 0) {
		/*
		 * Just set block_size to 0. tapechar_read/tapechar_write
		 * will realloc the idal buffer if a bigger one than the
		 * current is needed.
		 */
		device->char_data.block_size = 0;
		return 0;
	}
	if (device->char_data.idal_buf != NULL &&
	    device->char_data.idal_buf->size == count)
		/* We already have a idal buffer of that size. */
		return 0;

	if (count > MAX_BLOCKSIZE) {
		DBF_EVENT(3, "Invalid block size (%d > %d) given.\n",
			count, MAX_BLOCKSIZE);
		return -EINVAL;
	}

	/* Allocate a new idal buffer. */
	new = idal_buffer_alloc(count, 0);
	if (IS_ERR(new))
		return -ENOMEM;
	if (device->char_data.idal_buf != NULL)
		idal_buffer_free(device->char_data.idal_buf);
	device->char_data.idal_buf = new;
	device->char_data.block_size = count;

	DBF_LH(6, "new blocksize is %d\n", device->char_data.block_size);

	return 0;
}

int
tape_std_mtreset(struct tape_device *device, int count)
{
	DBF_EVENT(6, "TCHAR:devreset:\n");
	device->char_data.block_size = 0;
	return 0;
}

int
tape_std_mtfsf(struct tape_device *device, int mt_count)
{
	struct tape_request *request;
	struct ccw1 *ccw;

	request = tape_alloc_request(mt_count + 2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_FSF;
	/* setup ccws */
	ccw = tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
			  device->modeset_byte);
	ccw = tape_ccw_repeat(ccw, FORSPACEFILE, mt_count);
	ccw = tape_ccw_end(ccw, NOP, 0, NULL);

	/* execute it */
	return tape_do_io_free(device, request);
}

int
tape_std_mtfsr(struct tape_device *device, int mt_count)
{
	struct tape_request *request;
	struct ccw1 *ccw;
	int rc;

	request = tape_alloc_request(mt_count + 2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_FSB;
	/* setup ccws */
	ccw = tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
			  device->modeset_byte);
	ccw = tape_ccw_repeat(ccw, FORSPACEBLOCK, mt_count);
	ccw = tape_ccw_end(ccw, NOP, 0, NULL);

	/* execute it */
	rc = tape_do_io(device, request);
	if (rc == 0 && request->rescnt > 0) {
		DBF_LH(3, "FSR over tapemark\n");
		rc = 1;
	}
	tape_free_request(request);

	return rc;
}

int
tape_std_mtbsr(struct tape_device *device, int mt_count)
{
	struct tape_request *request;
	struct ccw1 *ccw;
	int rc;

	request = tape_alloc_request(mt_count + 2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_BSB;
	/* setup ccws */
	ccw = tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
			  device->modeset_byte);
	ccw = tape_ccw_repeat(ccw, BACKSPACEBLOCK, mt_count);
	ccw = tape_ccw_end(ccw, NOP, 0, NULL);

	/* execute it */
	rc = tape_do_io(device, request);
	if (rc == 0 && request->rescnt > 0) {
		DBF_LH(3, "BSR over tapemark\n");
		rc = 1;
	}
	tape_free_request(request);

	return rc;
}

int
tape_std_mtweof(struct tape_device *device, int mt_count)
{
	struct tape_request *request;
	struct ccw1 *ccw;

	request = tape_alloc_request(mt_count + 2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_WTM;
	/* setup ccws */
	ccw = tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
			  device->modeset_byte);
	ccw = tape_ccw_repeat(ccw, WRITETAPEMARK, mt_count);
	ccw = tape_ccw_end(ccw, NOP, 0, NULL);

	/* execute it */
	return tape_do_io_free(device, request);
}

int
tape_std_mtbsfm(struct tape_device *device, int mt_count)
{
	struct tape_request *request;
	struct ccw1 *ccw;

	request = tape_alloc_request(mt_count + 2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_BSF;
	/* setup ccws */
	ccw = tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
			  device->modeset_byte);
	ccw = tape_ccw_repeat(ccw, BACKSPACEFILE, mt_count);
	ccw = tape_ccw_end(ccw, NOP, 0, NULL);

	/* execute it */
	return tape_do_io_free(device, request);
}

int
tape_std_mtbsf(struct tape_device *device, int mt_count)
{
	struct tape_request *request;
	struct ccw1 *ccw;
	int rc;

	request = tape_alloc_request(mt_count + 2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_BSF;
	/* setup ccws */
	ccw = tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
			  device->modeset_byte);
	ccw = tape_ccw_repeat(ccw, BACKSPACEFILE, mt_count);
	ccw = tape_ccw_end(ccw, NOP, 0, NULL);
	/* execute it */
	rc = tape_do_io_free(device, request);
	if (rc == 0) {
		rc = tape_mtop(device, MTFSR, 1);
		if (rc > 0)
			rc = 0;
	}
	return rc;
}

int
tape_std_mtfsfm(struct tape_device *device, int mt_count)
{
	struct tape_request *request;
	struct ccw1 *ccw;
	int rc;

	request = tape_alloc_request(mt_count + 2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_FSF;
	/* setup ccws */
	ccw = tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
			  device->modeset_byte);
	ccw = tape_ccw_repeat(ccw, FORSPACEFILE, mt_count);
	ccw = tape_ccw_end(ccw, NOP, 0, NULL);
	/* execute it */
	rc = tape_do_io_free(device, request);
	if (rc == 0) {
		rc = tape_mtop(device, MTBSR, 1);
		if (rc > 0)
			rc = 0;
	}

	return rc;
}

int
tape_std_mtrew(struct tape_device *device, int mt_count)
{
	struct tape_request *request;

	request = tape_alloc_request(3, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_REW;
	/* setup ccws */
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1,
		    device->modeset_byte);
	tape_ccw_cc(request->cpaddr + 1, REWIND, 0, NULL);
	tape_ccw_end(request->cpaddr + 2, NOP, 0, NULL);

	/* execute it */
	return tape_do_io_free(device, request);
}

int
tape_std_mtoffl(struct tape_device *device, int mt_count)
{
	struct tape_request *request;

	request = tape_alloc_request(3, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_RUN;
	/* setup ccws */
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_cc(request->cpaddr + 1, REWIND_UNLOAD, 0, NULL);
	tape_ccw_end(request->cpaddr + 2, NOP, 0, NULL);

	/* execute it */
	return tape_do_io_free(device, request);
}

int
tape_std_mtnop(struct tape_device *device, int mt_count)
{
	struct tape_request *request;

	request = tape_alloc_request(2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_NOP;
	/* setup ccws */
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_end(request->cpaddr + 1, NOP, 0, NULL);
	/* execute it */
	return tape_do_io_free(device, request);
}

int
tape_std_mteom(struct tape_device *device, int mt_count)
{
	int rc;

	/*
	 * Seek from the beginning of tape (rewind).
	 */
	if ((rc = tape_mtop(device, MTREW, 1)) < 0)
		return rc;

	/*
	 * The logical end of volume is given by two sewuential tapemarks.
	 * Look for this by skipping to the next file (over one tapemark)
	 * and then test for another one (fsr returns 1 if a tapemark was
	 * encountered).
	 */
	do {
		if ((rc = tape_mtop(device, MTFSF, 1)) < 0)
			return rc;
		if ((rc = tape_mtop(device, MTFSR, 1)) < 0)
			return rc;
	} while (rc == 0);

	return tape_mtop(device, MTBSR, 1);
}

int
tape_std_mtreten(struct tape_device *device, int mt_count)
{
	struct tape_request *request;

	request = tape_alloc_request(4, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_FSF;
	/* setup ccws */
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_cc(request->cpaddr + 1,FORSPACEFILE, 0, NULL);
	tape_ccw_cc(request->cpaddr + 2, NOP, 0, NULL);
	tape_ccw_end(request->cpaddr + 3, CCW_CMD_TIC, 0, request->cpaddr);
	/* execute it, MTRETEN rc gets ignored */
	tape_do_io_interruptible(device, request);
	tape_free_request(request);
	return tape_mtop(device, MTREW, 1);
}

int
tape_std_mterase(struct tape_device *device, int mt_count)
{
	struct tape_request *request;

	request = tape_alloc_request(6, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_DSE;
	/* setup ccws */
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_cc(request->cpaddr + 1, REWIND, 0, NULL);
	tape_ccw_cc(request->cpaddr + 2, ERASE_GAP, 0, NULL);
	tape_ccw_cc(request->cpaddr + 3, DATA_SEC_ERASE, 0, NULL);
	tape_ccw_cc(request->cpaddr + 4, REWIND, 0, NULL);
	tape_ccw_end(request->cpaddr + 5, NOP, 0, NULL);

	/* execute it */
	return tape_do_io_free(device, request);
}

int
tape_std_mtunload(struct tape_device *device, int mt_count)
{
	return tape_mtop(device, MTOFFL, mt_count);
}

int
tape_std_mtcompression(struct tape_device *device, int mt_count)
{
	struct tape_request *request;

	if (mt_count < 0 || mt_count > 1) {
		DBF_EXCEPTION(6, "xcom parm\n");
		return -EINVAL;
	}
	request = tape_alloc_request(2, 0);
	if (IS_ERR(request))
		return PTR_ERR(request);
	request->op = TO_NOP;
	/* setup ccws */
	if (mt_count == 0)
		*device->modeset_byte &= ~0x08;
	else
		*device->modeset_byte |= 0x08;
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_end(request->cpaddr + 1, NOP, 0, NULL);
	/* execute it */
	return tape_do_io_free(device, request);
}

struct tape_request *
tape_std_read_block(struct tape_device *device, size_t count)
{
	struct tape_request *request;

	/*
	 * We have to alloc 4 ccws in order to be able to transform request
	 * into a read backward request in error case.
	 */
	request = tape_alloc_request(4, 0);
	if (IS_ERR(request)) {
		DBF_EXCEPTION(6, "xrbl fail");
		return request;
	}
	request->op = TO_RFO;
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_end_idal(request->cpaddr + 1, READ_FORWARD,
			  device->char_data.idal_buf);
	DBF_EVENT(6, "xrbl ccwg\n");
	return request;
}

void
tape_std_read_backward(struct tape_device *device, struct tape_request *request)
{
	/*
	 * We have allocated 4 ccws in tape_std_read, so we can now
	 * transform the request to a read backward, followed by a
	 * forward space block.
	 */
	request->op = TO_RBA;
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_cc_idal(request->cpaddr + 1, READ_BACKWARD,
			 device->char_data.idal_buf);
	tape_ccw_cc(request->cpaddr + 2, FORSPACEBLOCK, 0, NULL);
	tape_ccw_end(request->cpaddr + 3, NOP, 0, NULL);
	DBF_EVENT(6, "xrop ccwg");}

struct tape_request *
tape_std_write_block(struct tape_device *device, size_t count)
{
	struct tape_request *request;

	request = tape_alloc_request(2, 0);
	if (IS_ERR(request)) {
		DBF_EXCEPTION(6, "xwbl fail\n");
		return request;
	}
	request->op = TO_WRI;
	tape_ccw_cc(request->cpaddr, MODE_SET_DB, 1, device->modeset_byte);
	tape_ccw_end_idal(request->cpaddr + 1, WRITE_CMD,
			  device->char_data.idal_buf);
	DBF_EVENT(6, "xwbl ccwg\n");
	return request;
}

void
tape_std_process_eov(struct tape_device *device)
{
	/*
	 * End of volume: We have to backspace the last written record, then
	 * we TRY to write a tapemark and then backspace over the written TM
	 */
	if (tape_mtop(device, MTBSR, 1) == 0 &&
	    tape_mtop(device, MTWEOF, 1) == 0) {
		tape_mtop(device, MTBSR, 1);
	}
}

