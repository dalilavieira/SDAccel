#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_9__ ;
typedef  struct TYPE_23__   TYPE_8__ ;
typedef  struct TYPE_22__   TYPE_7__ ;
typedef  struct TYPE_21__   TYPE_6__ ;
typedef  struct TYPE_20__   TYPE_5__ ;
typedef  struct TYPE_19__   TYPE_4__ ;
typedef  struct TYPE_18__   TYPE_3__ ;
typedef  struct TYPE_17__   TYPE_2__ ;
typedef  struct TYPE_16__   TYPE_1__ ;
typedef  struct TYPE_15__   TYPE_12__ ;
typedef  struct TYPE_14__   TYPE_11__ ;
typedef  struct TYPE_13__   TYPE_10__ ;

/* Type definitions */
struct TYPE_24__ {void* addr; } ;
struct TYPE_13__ {TYPE_9__ s; } ;
struct TYPE_22__ {scalar_t__ length; } ;
struct TYPE_23__ {TYPE_7__ s; } ;
struct TYPE_20__ {void* addr; } ;
struct TYPE_21__ {TYPE_5__ s; } ;
struct TYPE_18__ {scalar_t__ length; } ;
struct TYPE_19__ {TYPE_3__ s; } ;
struct TYPE_16__ {void* addr; } ;
struct TYPE_17__ {TYPE_1__ s; } ;
struct TYPE_15__ {int ce; int sf; int ef; scalar_t__ historylength; scalar_t__ totaloutputlength; scalar_t__ totalbyteswritten; int /*<<< orphan*/  crc32; int /*<<< orphan*/  adler32; scalar_t__ compcode; TYPE_10__ res_ptr_addr; TYPE_8__ out_ptr_ctl; TYPE_6__ out_ptr_addr; scalar_t__ ds; TYPE_4__ inp_ptr_ctl; TYPE_2__ inp_ptr_addr; scalar_t__ dg; int /*<<< orphan*/  adlercrc32; int /*<<< orphan*/  ss; int /*<<< orphan*/  cc; scalar_t__ hg; } ;
union zip_zres_s {TYPE_12__ s; } ;
union zip_inst_s {TYPE_12__ s; } ;
typedef  int u64 ;
typedef  int /*<<< orphan*/  u32 ;
struct zip_state {union zip_zres_s result; union zip_zres_s zip_cmd; } ;
struct zip_operation {scalar_t__ flush; scalar_t__ history_len; scalar_t__ input_len; scalar_t__ output_len; int format; int /*<<< orphan*/  csum; scalar_t__ compcode; union zip_zres_s* output; union zip_zres_s* input; int /*<<< orphan*/  speed; int /*<<< orphan*/  ccode; } ;
struct TYPE_14__ {int /*<<< orphan*/  comp_out_bytes; int /*<<< orphan*/  comp_req_complete; int /*<<< orphan*/  comp_req_submit; int /*<<< orphan*/  comp_in_bytes; } ;
struct zip_device {TYPE_11__ stats; } ;

/* Variables and functions */
 int ETIMEDOUT ; 
#define  GZIP_FORMAT 134 
#define  LZS_FORMAT 133 
#define  RAW_FORMAT 132 
#define  ZIP_CMD_DTRUNC 131 
#define  ZIP_CMD_NOTDONE 130 
#define  ZIP_CMD_SUCCESS 129 
 int ZIP_ERROR ; 
 scalar_t__ ZIP_FLUSH_FINISH ; 
#define  ZLIB_FORMAT 128 
 void* __pa (union zip_zres_s*) ; 
 int /*<<< orphan*/  atomic64_add (scalar_t__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  atomic64_inc (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  memset (union zip_zres_s*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  pr_err (char*,...) ; 
 int /*<<< orphan*/  rmb () ; 
 int /*<<< orphan*/  udelay (int) ; 
 int /*<<< orphan*/  zip_dbg (char*,...) ; 
 int /*<<< orphan*/  zip_err (char*,scalar_t__,...) ; 
 int /*<<< orphan*/  zip_load_instr (union zip_zres_s*,struct zip_device*) ; 
 int /*<<< orphan*/  zip_update_cmd_bufs (struct zip_device*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline u64 ZIP_COREX_BIST_STATUS(u64 param1)
{
	if (param1 <= 1)
		return 0x0520ull + (param1 & 1) * 0x8ull;
	pr_err("ZIP_COREX_BIST_STATUS: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_DBG_COREX_INST(u64 param1)
{
	if (param1 <= 1)
		return 0x0640ull + (param1 & 1) * 0x8ull;
	pr_err("ZIP_DBG_COREX_INST: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_DBG_COREX_STA(u64 param1)
{
	if (param1 <= 1)
		return 0x0680ull + (param1 & 1) * 0x8ull;
	pr_err("ZIP_DBG_COREX_STA: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_DBG_QUEX_STA(u64 param1)
{
	if (param1 <= 7)
		return 0x1800ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_DBG_QUEX_STA: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_MSIX_PBAX(u64 param1)
{
	if (param1 == 0)
		return 0x0000838000FF0000ull;
	pr_err("ZIP_MSIX_PBAX: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_MSIX_VECX_ADDR(u64 param1)
{
	if (param1 <= 17)
		return 0x0000838000F00000ull + (param1 & 31) * 0x10ull;
	pr_err("ZIP_MSIX_VECX_ADDR: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_MSIX_VECX_CTL(u64 param1)
{
	if (param1 <= 17)
		return 0x0000838000F00008ull + (param1 & 31) * 0x10ull;
	pr_err("ZIP_MSIX_VECX_CTL: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE(u64 param1)
{
	if (param1 <= 7)
		return 0x2000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_ACK(u64 param1)
{
	if (param1 <= 7)
		return 0x2200ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_ACK: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_ENA_W1C(u64 param1)
{
	if (param1 <= 7)
		return 0x2600ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_ENA_W1C: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_ENA_W1S(u64 param1)
{
	if (param1 <= 7)
		return 0x2400ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_ENA_W1S: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DONE_WAIT(u64 param1)
{
	if (param1 <= 7)
		return 0x2800ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DONE_WAIT: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_DOORBELL(u64 param1)
{
	if (param1 <= 7)
		return 0x4000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_DOORBELL: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_ENA_W1C(u64 param1)
{
	if (param1 <= 7)
		return 0x3600ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_ENA_W1C: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_ENA_W1S(u64 param1)
{
	if (param1 <= 7)
		return 0x3400ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_ENA_W1S: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_INT(u64 param1)
{
	if (param1 <= 7)
		return 0x3000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_INT: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_ERR_INT_W1S(u64 param1)
{
	if (param1 <= 7)
		return 0x3200ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_ERR_INT_W1S: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_GCFG(u64 param1)
{
	if (param1 <= 7)
		return 0x1A00ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_GCFG: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_MAP(u64 param1)
{
	if (param1 <= 7)
		return 0x1400ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_MAP: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_SBUF_ADDR(u64 param1)
{
	if (param1 <= 7)
		return 0x1000ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_SBUF_ADDR: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline u64 ZIP_QUEX_SBUF_CTL(u64 param1)
{
	if (param1 <= 7)
		return 0x1200ull + (param1 & 7) * 0x8ull;
	pr_err("ZIP_QUEX_SBUF_CTL: %llu\n", param1);
	return 0;
}

__attribute__((used)) static inline int zip_poll_result(union zip_zres_s *result)
{
	int retries = 1000;

	while (!result->s.compcode) {
		if (!--retries) {
			pr_err("ZIP ERR: request timed out");
			return -ETIMEDOUT;
		}
		udelay(10);
		/*
		 * Force re-reading of compcode which is updated
		 * by the ZIP coprocessor.
		 */
		rmb();
	}
	return 0;
}

__attribute__((used)) static int prepare_zip_command(struct zip_operation *zip_ops,
			       struct zip_state *s, union zip_inst_s *zip_cmd)
{
	union zip_zres_s *result_ptr = &s->result;

	memset(zip_cmd, 0, sizeof(s->zip_cmd));
	memset(result_ptr, 0, sizeof(s->result));

	/* IWORD #0 */
	/* History gather */
	zip_cmd->s.hg = 0;
	/* compression enable = 1 for deflate */
	zip_cmd->s.ce = 1;
	/* sf (sync flush) */
	zip_cmd->s.sf = 1;
	/* ef (end of file) */
	if (zip_ops->flush == ZIP_FLUSH_FINISH) {
		zip_cmd->s.ef = 1;
		zip_cmd->s.sf = 0;
	}

	zip_cmd->s.cc = zip_ops->ccode;
	/* ss (compression speed/storage) */
	zip_cmd->s.ss = zip_ops->speed;

	/* IWORD #1 */
	/* adler checksum */
	zip_cmd->s.adlercrc32 = zip_ops->csum;
	zip_cmd->s.historylength = zip_ops->history_len;
	zip_cmd->s.dg = 0;

	/* IWORD # 6 and 7 - compression input/history pointer */
	zip_cmd->s.inp_ptr_addr.s.addr  = __pa(zip_ops->input);
	zip_cmd->s.inp_ptr_ctl.s.length = (zip_ops->input_len +
					   zip_ops->history_len);
	zip_cmd->s.ds = 0;

	/* IWORD # 8 and 9 - Output pointer */
	zip_cmd->s.out_ptr_addr.s.addr  = __pa(zip_ops->output);
	zip_cmd->s.out_ptr_ctl.s.length = zip_ops->output_len;
	/* maximum number of output-stream bytes that can be written */
	zip_cmd->s.totaloutputlength    = zip_ops->output_len;

	/* IWORD # 10 and 11 - Result pointer */
	zip_cmd->s.res_ptr_addr.s.addr = __pa(result_ptr);
	/* Clearing completion code */
	result_ptr->s.compcode = 0;

	return 0;
}

int zip_deflate(struct zip_operation *zip_ops, struct zip_state *s,
		struct zip_device *zip_dev)
{
	union zip_inst_s *zip_cmd = &s->zip_cmd;
	union zip_zres_s *result_ptr = &s->result;
	u32 queue;

	/* Prepares zip command based on the input parameters */
	prepare_zip_command(zip_ops, s, zip_cmd);

	atomic64_add(zip_ops->input_len, &zip_dev->stats.comp_in_bytes);
	/* Loads zip command into command queues and rings door bell */
	queue = zip_load_instr(zip_cmd, zip_dev);

	/* Stats update for compression requests submitted */
	atomic64_inc(&zip_dev->stats.comp_req_submit);

	/* Wait for completion or error */
	zip_poll_result(result_ptr);

	/* Stats update for compression requests completed */
	atomic64_inc(&zip_dev->stats.comp_req_complete);

	zip_ops->compcode = result_ptr->s.compcode;
	switch (zip_ops->compcode) {
	case ZIP_CMD_NOTDONE:
		zip_dbg("Zip instruction not yet completed");
		return ZIP_ERROR;

	case ZIP_CMD_SUCCESS:
		zip_dbg("Zip instruction completed successfully");
		zip_update_cmd_bufs(zip_dev, queue);
		break;

	case ZIP_CMD_DTRUNC:
		zip_dbg("Output Truncate error");
		/* Returning ZIP_ERROR to avoid copy to user */
		return ZIP_ERROR;

	default:
		zip_err("Zip instruction failed. Code:%d", zip_ops->compcode);
		return ZIP_ERROR;
	}

	/* Update the CRC depending on the format */
	switch (zip_ops->format) {
	case RAW_FORMAT:
		zip_dbg("RAW Format: %d ", zip_ops->format);
		/* Get checksum from engine, need to feed it again */
		zip_ops->csum = result_ptr->s.adler32;
		break;

	case ZLIB_FORMAT:
		zip_dbg("ZLIB Format: %d ", zip_ops->format);
		zip_ops->csum = result_ptr->s.adler32;
		break;

	case GZIP_FORMAT:
		zip_dbg("GZIP Format: %d ", zip_ops->format);
		zip_ops->csum = result_ptr->s.crc32;
		break;

	case LZS_FORMAT:
		zip_dbg("LZS Format: %d ", zip_ops->format);
		break;

	default:
		zip_err("Unknown Format:%d\n", zip_ops->format);
	}

	atomic64_add(result_ptr->s.totalbyteswritten,
		     &zip_dev->stats.comp_out_bytes);

	/* Update output_len */
	if (zip_ops->output_len < result_ptr->s.totalbyteswritten) {
		/* Dynamic stop && strm->output_len < zipconstants[onfsize] */
		zip_err("output_len (%d) < total bytes written(%d)\n",
			zip_ops->output_len, result_ptr->s.totalbyteswritten);
		zip_ops->output_len = 0;

	} else {
		zip_ops->output_len = result_ptr->s.totalbyteswritten;
	}

	return 0;
}

