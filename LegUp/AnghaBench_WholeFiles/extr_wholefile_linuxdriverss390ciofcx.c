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
typedef  void* u8 ;
typedef  int u64 ;
typedef  int u32 ;
struct TYPE_2__ {size_t tcal; int sac; int /*<<< orphan*/  format; } ;
struct tsb {int intrg; int r; int input; int w; int output; int tccb; int tsb; int flags; int count; int input_count; int output_count; int tccbl; int addr; TYPE_1__ tcah; int /*<<< orphan*/ * cd; void* cd_count; void* cmd; int /*<<< orphan*/ * tca; int /*<<< orphan*/  format; } ;
struct tidaw {int intrg; int r; int input; int w; int output; int tccb; int tsb; int flags; int count; int input_count; int output_count; int tccbl; int addr; TYPE_1__ tcah; int /*<<< orphan*/ * cd; void* cd_count; void* cmd; int /*<<< orphan*/ * tca; int /*<<< orphan*/  format; } ;
struct tcw {int intrg; int r; int input; int w; int output; int tccb; int tsb; int flags; int count; int input_count; int output_count; int tccbl; int addr; TYPE_1__ tcah; int /*<<< orphan*/ * cd; void* cd_count; void* cmd; int /*<<< orphan*/ * tca; int /*<<< orphan*/  format; } ;
struct tccb_tcat {int intrg; int r; int input; int w; int output; int tccb; int tsb; int flags; int count; int input_count; int output_count; int tccbl; int addr; TYPE_1__ tcah; int /*<<< orphan*/ * cd; void* cd_count; void* cmd; int /*<<< orphan*/ * tca; int /*<<< orphan*/  format; } ;
struct tccb_tcah {int dummy; } ;
struct tccb {int intrg; int r; int input; int w; int output; int tccb; int tsb; int flags; int count; int input_count; int output_count; int tccbl; int addr; TYPE_1__ tcah; int /*<<< orphan*/ * cd; void* cd_count; void* cmd; int /*<<< orphan*/ * tca; int /*<<< orphan*/  format; } ;
struct dcw {int intrg; int r; int input; int w; int output; int tccb; int tsb; int flags; int count; int input_count; int output_count; int tccbl; int addr; TYPE_1__ tcah; int /*<<< orphan*/ * cd; void* cd_count; void* cmd; int /*<<< orphan*/ * tca; int /*<<< orphan*/  format; } ;
typedef  scalar_t__ addr_t ;

/* Variables and functions */
 void* ALIGN (int,int) ; 
 int DCW_FLAGS_CC ; 
 int /*<<< orphan*/  ENOSPC ; 
 struct tsb* ERR_PTR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TCCB_FORMAT_DEFAULT ; 
 int TCW_FLAGS_INPUT_TIDA ; 
 int TCW_FLAGS_OUTPUT_TIDA ; 
 int TCW_FLAGS_TIDAW_FORMAT (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  TCW_FORMAT_DEFAULT ; 
 int /*<<< orphan*/  TCW_TIDAW_FORMAT_DEFAULT ; 
 int TIDAW_FLAGS_INSERT_CBC ; 
 int TIDAW_FLAGS_LAST ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ *,void*,void*) ; 
 int /*<<< orphan*/  memset (struct tsb*,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static inline int scm_update_information(void) { return 0; }

__attribute__((used)) static inline int scm_process_availability_information(void) { return 0; }

__attribute__((used)) static inline void cio_register_early_subchannels(void) {}

struct tcw *tcw_get_intrg(struct tcw *tcw)
{
	return (struct tcw *) ((addr_t) tcw->intrg);
}

void *tcw_get_data(struct tcw *tcw)
{
	if (tcw->r)
		return (void *) ((addr_t) tcw->input);
	if (tcw->w)
		return (void *) ((addr_t) tcw->output);
	return NULL;
}

struct tccb *tcw_get_tccb(struct tcw *tcw)
{
	return (struct tccb *) ((addr_t) tcw->tccb);
}

struct tsb *tcw_get_tsb(struct tcw *tcw)
{
	return (struct tsb *) ((addr_t) tcw->tsb);
}

void tcw_init(struct tcw *tcw, int r, int w)
{
	memset(tcw, 0, sizeof(struct tcw));
	tcw->format = TCW_FORMAT_DEFAULT;
	tcw->flags = TCW_FLAGS_TIDAW_FORMAT(TCW_TIDAW_FORMAT_DEFAULT);
	if (r)
		tcw->r = 1;
	if (w)
		tcw->w = 1;
}

__attribute__((used)) static inline size_t tca_size(struct tccb *tccb)
{
	return tccb->tcah.tcal - 12;
}

__attribute__((used)) static u32 calc_dcw_count(struct tccb *tccb)
{
	int offset;
	struct dcw *dcw;
	u32 count = 0;
	size_t size;

	size = tca_size(tccb);
	for (offset = 0; offset < size;) {
		dcw = (struct dcw *) &tccb->tca[offset];
		count += dcw->count;
		if (!(dcw->flags & DCW_FLAGS_CC))
			break;
		offset += sizeof(struct dcw) + ALIGN((int) dcw->cd_count, 4);
	}
	return count;
}

__attribute__((used)) static u32 calc_cbc_size(struct tidaw *tidaw, int num)
{
	int i;
	u32 cbc_data;
	u32 cbc_count = 0;
	u64 data_count = 0;

	for (i = 0; i < num; i++) {
		if (tidaw[i].flags & TIDAW_FLAGS_LAST)
			break;
		/* TODO: find out if padding applies to total of data
		 * transferred or data transferred by this tidaw. Assumption:
		 * applies to total. */
		data_count += tidaw[i].count;
		if (tidaw[i].flags & TIDAW_FLAGS_INSERT_CBC) {
			cbc_data = 4 + ALIGN(data_count, 4) - data_count;
			cbc_count += cbc_data;
			data_count += cbc_data;
		}
	}
	return cbc_count;
}

void tcw_finalize(struct tcw *tcw, int num_tidaws)
{
	struct tidaw *tidaw;
	struct tccb *tccb;
	struct tccb_tcat *tcat;
	u32 count;

	/* Terminate tidaw list. */
	tidaw = tcw_get_data(tcw);
	if (num_tidaws > 0)
		tidaw[num_tidaws - 1].flags |= TIDAW_FLAGS_LAST;
	/* Add tcat to tccb. */
	tccb = tcw_get_tccb(tcw);
	tcat = (struct tccb_tcat *) &tccb->tca[tca_size(tccb)];
	memset(tcat, 0, sizeof(*tcat));
	/* Calculate tcw input/output count and tcat transport count. */
	count = calc_dcw_count(tccb);
	if (tcw->w && (tcw->flags & TCW_FLAGS_OUTPUT_TIDA))
		count += calc_cbc_size(tidaw, num_tidaws);
	if (tcw->r)
		tcw->input_count = count;
	else if (tcw->w)
		tcw->output_count = count;
	tcat->count = ALIGN(count, 4) + 4;
	/* Calculate tccbl. */
	tcw->tccbl = (sizeof(struct tccb) + tca_size(tccb) +
		      sizeof(struct tccb_tcat) - 20) >> 2;
}

void tcw_set_intrg(struct tcw *tcw, struct tcw *intrg_tcw)
{
	tcw->intrg = (u32) ((addr_t) intrg_tcw);
}

void tcw_set_data(struct tcw *tcw, void *data, int use_tidal)
{
	if (tcw->r) {
		tcw->input = (u64) ((addr_t) data);
		if (use_tidal)
			tcw->flags |= TCW_FLAGS_INPUT_TIDA;
	} else if (tcw->w) {
		tcw->output = (u64) ((addr_t) data);
		if (use_tidal)
			tcw->flags |= TCW_FLAGS_OUTPUT_TIDA;
	}
}

void tcw_set_tccb(struct tcw *tcw, struct tccb *tccb)
{
	tcw->tccb = (u64) ((addr_t) tccb);
}

void tcw_set_tsb(struct tcw *tcw, struct tsb *tsb)
{
	tcw->tsb = (u64) ((addr_t) tsb);
}

void tccb_init(struct tccb *tccb, size_t size, u32 sac)
{
	memset(tccb, 0, size);
	tccb->tcah.format = TCCB_FORMAT_DEFAULT;
	tccb->tcah.sac = sac;
	tccb->tcah.tcal = 12;
}

void tsb_init(struct tsb *tsb)
{
	memset(tsb, 0, sizeof(*tsb));
}

struct dcw *tccb_add_dcw(struct tccb *tccb, size_t tccb_size, u8 cmd, u8 flags,
			 void *cd, u8 cd_count, u32 count)
{
	struct dcw *dcw;
	int size;
	int tca_offset;

	/* Check for space. */
	tca_offset = tca_size(tccb);
	size = ALIGN(sizeof(struct dcw) + cd_count, 4);
	if (sizeof(struct tccb_tcah) + tca_offset + size +
	    sizeof(struct tccb_tcat) > tccb_size)
		return ERR_PTR(-ENOSPC);
	/* Add dcw to tca. */
	dcw = (struct dcw *) &tccb->tca[tca_offset];
	memset(dcw, 0, size);
	dcw->cmd = cmd;
	dcw->flags = flags;
	dcw->count = count;
	dcw->cd_count = cd_count;
	if (cd)
		memcpy(&dcw->cd[0], cd, cd_count);
	tccb->tcah.tcal += size;
	return dcw;
}

struct tidaw *tcw_add_tidaw(struct tcw *tcw, int num_tidaws, u8 flags,
			    void *addr, u32 count)
{
	struct tidaw *tidaw;

	/* Add tidaw to tidaw-list. */
	tidaw = ((struct tidaw *) tcw_get_data(tcw)) + num_tidaws;
	memset(tidaw, 0, sizeof(struct tidaw));
	tidaw->flags = flags;
	tidaw->count = count;
	tidaw->addr = (u64) ((addr_t) addr);
	return tidaw;
}

