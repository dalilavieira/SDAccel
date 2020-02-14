#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_4__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ vm_compressor_mode_t ;
typedef  scalar_t__ uint8_t ;
typedef  scalar_t__ uint32_t ;
typedef  scalar_t__ uint16_t ;
typedef  int /*<<< orphan*/  new_codec ;
typedef  unsigned int int32_t ;
typedef  enum compressor_preselect_t { ____Placeholder_compressor_preselect_t } compressor_preselect_t ;
struct TYPE_6__ {scalar_t__* wkscratch; int /*<<< orphan*/ * lz4state; } ;
typedef  TYPE_1__ compressor_encode_scratch_t ;
struct TYPE_7__ {scalar_t__* wkdecompscratch; int /*<<< orphan*/ * lz4decodestate; } ;
typedef  TYPE_2__ compressor_decode_scratch_t ;
typedef  int /*<<< orphan*/  boolean_t ;
typedef  scalar_t__ WK_word ;
struct TYPE_10__ {int lz4_compressed_bytes; int lz4_wk_compression_negative_delta; int wk_compressed_bytes_total; int lz4_decompressions; scalar_t__ lz4_decompressed_bytes; int wk_decompressions; scalar_t__ wk_decompressed_bytes; int /*<<< orphan*/  wk_compressed_bytes_exclusive; int /*<<< orphan*/  wk_compressions_exclusive; int /*<<< orphan*/  wk_sv_compressions; int /*<<< orphan*/  wk_compression_failures; int /*<<< orphan*/  wk_compressions; int /*<<< orphan*/  lz4_wk_compression_delta; int /*<<< orphan*/  lz4_compression_failures; int /*<<< orphan*/  lz4_compressions; } ;
struct TYPE_9__ {scalar_t__ lz4_failure_skips; scalar_t__ lz4_failure_run_length; scalar_t__ lz4_preselects; scalar_t__ lz4_run_length; int /*<<< orphan*/  lz4_total_negatives; int /*<<< orphan*/  lz4_total_unprofitables; int /*<<< orphan*/  lz4_total_failures; int /*<<< orphan*/  lz4_total_preselects; int /*<<< orphan*/  lz4_total_failure_skips; } ;
struct TYPE_8__ {scalar_t__ lz4_max_failure_skips; scalar_t__ lz4_max_failure_run_length; scalar_t__ lz4_max_preselects; scalar_t__ lz4_run_preselection_threshold; int wkdm_reeval_threshold; scalar_t__ lz4_run_continue_bytes; scalar_t__ lz4_profitable_bytes; int lz4_threshold; } ;

/* Variables and functions */
 scalar_t__ CCLZ4 ; 
 scalar_t__ CCWK ; 
 scalar_t__ CMODE_HYB ; 
 scalar_t__ CMODE_LZ4 ; 
 scalar_t__ CMODE_WK ; 
 int CPRESELLZ4 ; 
 int CPRESELWK ; 
 int CSKIPLZ4 ; 
 int FALSE ; 
 scalar_t__ MAX (int,scalar_t__) ; 
 int PAGE_SIZE ; 
 int /*<<< orphan*/  PE_parse_boot_argn (char*,scalar_t__*,int) ; 
 int TRUE ; 
 scalar_t__ VM_COMPRESSOR_DEFAULT_CODEC ; 
 int /*<<< orphan*/  VM_COMPRESSOR_STAT (int) ; 
 int /*<<< orphan*/  VM_DECOMPRESSOR_STAT (scalar_t__) ; 
 scalar_t__ WKdm_SCRATCH_BUF_SIZE_INTERNAL ; 
 int WKdm_compress_new (scalar_t__*,scalar_t__*,scalar_t__*,unsigned int) ; 
 int /*<<< orphan*/  WKdm_decompress_new (scalar_t__*,scalar_t__*,scalar_t__*,unsigned int) ; 
 scalar_t__ __probable (int) ; 
 int /*<<< orphan*/  assert (int) ; 
 int /*<<< orphan*/  assertf (int,char*,scalar_t__,...) ; 
 TYPE_5__ compressor_stats ; 
 int /*<<< orphan*/ * d32 ; 
 scalar_t__ lz4raw_decode_buffer (scalar_t__*,int,scalar_t__ const*,scalar_t__,int /*<<< orphan*/ *) ; 
 scalar_t__ lz4raw_encode_buffer (scalar_t__*,unsigned int,scalar_t__ const*,int,int /*<<< orphan*/ *) ; 
 scalar_t__ vm_compressor_current_codec ; 
 TYPE_4__ vmcstate ; 
 TYPE_3__ vmctune ; 
 int wkc ; 

__attribute__((used)) static inline enum compressor_preselect_t compressor_preselect(void) {
	if (vmcstate.lz4_failure_skips >= vmctune.lz4_max_failure_skips) {
		vmcstate.lz4_failure_skips = 0;
		vmcstate.lz4_failure_run_length = 0;
	}

	if (vmcstate.lz4_failure_run_length >= vmctune.lz4_max_failure_run_length) {
		vmcstate.lz4_failure_skips++;
		vmcstate.lz4_total_failure_skips++;
		return CSKIPLZ4;
	}

	if (vmcstate.lz4_preselects >= vmctune.lz4_max_preselects) {
		vmcstate.lz4_preselects = 0;
		return CPRESELWK;
	}

	if (vmcstate.lz4_run_length >= vmctune.lz4_run_preselection_threshold) {
		vmcstate.lz4_preselects++;
		vmcstate.lz4_total_preselects++;
		return CPRESELLZ4;
	}
	return CPRESELWK;
}

__attribute__((used)) static inline void compressor_selector_update(int lz4sz, int didwk, int wksz) {
	VM_COMPRESSOR_STAT(compressor_stats.lz4_compressions++);

	if (lz4sz == 0) {
		VM_COMPRESSOR_STAT(compressor_stats.lz4_compressed_bytes+=PAGE_SIZE);
		VM_COMPRESSOR_STAT(compressor_stats.lz4_compression_failures++);
		vmcstate.lz4_failure_run_length++;
		VM_COMPRESSOR_STAT(vmcstate.lz4_total_failures++);
		vmcstate.lz4_run_length = 0;
	} else {
		vmcstate.lz4_failure_run_length = 0;

		VM_COMPRESSOR_STAT(compressor_stats.lz4_compressed_bytes+=lz4sz);

		if (lz4sz <= vmctune.wkdm_reeval_threshold) {
			vmcstate.lz4_run_length = 0;
		} else {
			if (!didwk) {
				vmcstate.lz4_run_length++;
			}
		}

		if (didwk) {
			if (__probable(wksz > lz4sz)) {
				uint32_t lz4delta = wksz - lz4sz;
				VM_COMPRESSOR_STAT(compressor_stats.lz4_wk_compression_delta+=lz4delta);
				if (lz4delta >= vmctune.lz4_run_continue_bytes) {
					vmcstate.lz4_run_length++;
				} else if (lz4delta <= vmctune.lz4_profitable_bytes) {
					vmcstate.lz4_failure_run_length++;
					VM_COMPRESSOR_STAT(vmcstate.lz4_total_unprofitables++);
					vmcstate.lz4_run_length = 0;
				} else {
					vmcstate.lz4_run_length = 0;
				}
			} else {
				VM_COMPRESSOR_STAT(compressor_stats.lz4_wk_compression_negative_delta+=(lz4sz-wksz));
				vmcstate.lz4_failure_run_length++;
				VM_COMPRESSOR_STAT(vmcstate.lz4_total_negatives++);
				vmcstate.lz4_run_length = 0;
			}
		}
	}
}

__attribute__((used)) static inline void WKdm_hv(uint32_t *wkbuf) {
#if DEVELOPMENT || DEBUG
	uint32_t *inw = (uint32_t *) wkbuf;
	if (*inw != MZV_MAGIC) {
		if ((*inw | *(inw + 1) | *(inw + 2)) & 0xFFFF0000) {
			panic("WKdm(%p): invalid header 0x%x 0x%x 0x%x\n", wkbuf, *inw, *(inw +1), *(inw+2));
		}
	}
#else /* DEVELOPMENT || DEBUG */
	(void) wkbuf;
#endif
}

__attribute__((used)) static inline void WKdmD(WK_word* src_buf, WK_word* dest_buf, WK_word* scratch, unsigned int bytes) {
#if defined(__arm64__)
#endif
	WKdm_hv(src_buf);
#if defined(__arm64__)
	if (PAGE_SIZE == 4096) {
		WKdm_decompress_4k(src_buf, dest_buf, scratch, bytes);
	} else {
		__unused uint64_t wdsstart;

		VM_COMPRESSOR_STAT_DBG(wdsstart = mach_absolute_time());
		WKdm_decompress_16k(src_buf, dest_buf, scratch, bytes);

		VM_COMPRESSOR_STAT_DBG(compressor_stats.wks_dabstime += mach_absolute_time() - wdsstart);
		VM_COMPRESSOR_STAT(compressor_stats.wks_decompressions++);
	}
#else /* !defined arm64 */
	WKdm_decompress_new(src_buf, dest_buf, scratch, bytes);
#endif
}

__attribute__((used)) static inline int WKdmC(WK_word* src_buf, WK_word* dest_buf, WK_word* scratch, boolean_t *incomp_copy, unsigned int limit) {
	(void)incomp_copy;
	int wkcval;
#if defined(__arm64__)
	if (PAGE_SIZE == 4096) {
		wkcval = WKdm_compress_4k(src_buf, dest_buf, scratch, limit);
	} else {
		__unused uint64_t wcswstart;

		VM_COMPRESSOR_STAT_DBG(wcswstart = mach_absolute_time());

		int wkswsz = WKdm_compress_16k(src_buf, dest_buf, scratch, limit);

		VM_COMPRESSOR_STAT_DBG(compressor_stats.wks_cabstime += mach_absolute_time() - wcswstart);
		VM_COMPRESSOR_STAT(compressor_stats.wks_compressions++);
		wkcval = wkswsz;
	}
#else
	wkcval = WKdm_compress_new(src_buf, dest_buf, scratch, limit);
#endif
	return wkcval;
}

int metacompressor(const uint8_t *in, uint8_t *cdst, int32_t outbufsz, uint16_t *codec, void *cscratchin, boolean_t *incomp_copy) {
	int sz = -1;
	int dowk = FALSE, dolz4 = FALSE, skiplz4 = FALSE;
	int insize = PAGE_SIZE;
	compressor_encode_scratch_t *cscratch = cscratchin;

	if (vm_compressor_current_codec == CMODE_WK) {
		dowk = TRUE;
	} else if (vm_compressor_current_codec == CMODE_LZ4) {
		dolz4 = TRUE;
	} else if (vm_compressor_current_codec == CMODE_HYB) {
		enum compressor_preselect_t presel = compressor_preselect();
		if (presel == CPRESELLZ4) {
			dolz4 = TRUE;
			goto lz4compress;
		} else if (presel == CSKIPLZ4) {
			dowk = TRUE;
			skiplz4 = TRUE;
		} else {
			assert(presel == CPRESELWK);
			dowk = TRUE;
		}
	}

	if (dowk) {
		*codec = CCWK;
		VM_COMPRESSOR_STAT(compressor_stats.wk_compressions++);
		sz = WKdmC(in, cdst, &cscratch->wkscratch[0], incomp_copy, outbufsz);

		if (sz == -1) {
			VM_COMPRESSOR_STAT(compressor_stats.wk_compressed_bytes_total+=PAGE_SIZE);
			VM_COMPRESSOR_STAT(compressor_stats.wk_compression_failures++);

			if (vm_compressor_current_codec == CMODE_HYB) {
				goto lz4eval;
			}
			goto cexit;
		} else if (sz == 0) {
			VM_COMPRESSOR_STAT(compressor_stats.wk_sv_compressions++);
			VM_COMPRESSOR_STAT(compressor_stats.wk_compressed_bytes_total+=4);
		} else {
			VM_COMPRESSOR_STAT(compressor_stats.wk_compressed_bytes_total+=sz);
		}
	}
lz4eval:
	if (vm_compressor_current_codec == CMODE_HYB) {
		if (((sz == -1) || (sz >= vmctune.lz4_threshold)) && (skiplz4 == FALSE)) {
			dolz4 = TRUE;
		} else {
#if DEVELOPMENT || DEBUG
			int wkc = (sz == -1) ? PAGE_SIZE : sz;
#endif
			VM_COMPRESSOR_STAT(compressor_stats.wk_compressions_exclusive++);
			VM_COMPRESSOR_STAT(compressor_stats.wk_compressed_bytes_exclusive+=wkc);
			goto cexit;
		}
	}

lz4compress:

	if (dolz4) {
		if (sz == -1) {
			sz = PAGE_SIZE;
		}
		int wksz = sz;
		*codec = CCLZ4;

		sz = (int) lz4raw_encode_buffer(cdst, outbufsz, in, insize, &cscratch->lz4state[0]);

		compressor_selector_update(sz, dowk, wksz);
		if (sz == 0) {
			sz = -1;
			goto cexit;
		}
	}
cexit:
	return sz;
}

void metadecompressor(const uint8_t *source, uint8_t *dest, uint32_t csize, uint16_t ccodec, void *compressor_dscratchin) {
	int dolz4 = (ccodec == CCLZ4);
	int rval;
	compressor_decode_scratch_t *compressor_dscratch = compressor_dscratchin;
	
	if (dolz4) {
		rval = (int)lz4raw_decode_buffer(dest, PAGE_SIZE, source, csize, &compressor_dscratch->lz4decodestate[0]);
		VM_DECOMPRESSOR_STAT(compressor_stats.lz4_decompressions+=1);
		VM_DECOMPRESSOR_STAT(compressor_stats.lz4_decompressed_bytes+=csize);
#if DEVELOPMENT || DEBUG
		uint32_t *d32 = dest;
#endif
		assertf(rval == PAGE_SIZE, "LZ4 decode: size != pgsize %d, header: 0x%x, 0x%x, 0x%x",
		    rval, *d32, *(d32+1), *(d32+2));
	} else {
		assert(ccodec == CCWK);

		WKdmD(source, dest, &compressor_dscratch->wkdecompscratch[0], csize);

		VM_DECOMPRESSOR_STAT(compressor_stats.wk_decompressions+=1);
		VM_DECOMPRESSOR_STAT(compressor_stats.wk_decompressed_bytes+=csize);
	}
}

uint32_t vm_compressor_get_encode_scratch_size(void) {
	if (vm_compressor_current_codec != VM_COMPRESSOR_DEFAULT_CODEC) {
		return MAX(sizeof(compressor_encode_scratch_t), WKdm_SCRATCH_BUF_SIZE_INTERNAL);
	} else {
		return WKdm_SCRATCH_BUF_SIZE_INTERNAL;
	}
}

uint32_t vm_compressor_get_decode_scratch_size(void) {
	if (vm_compressor_current_codec != VM_COMPRESSOR_DEFAULT_CODEC) {
		return MAX(sizeof(compressor_decode_scratch_t), WKdm_SCRATCH_BUF_SIZE_INTERNAL);
	} else {
		return WKdm_SCRATCH_BUF_SIZE_INTERNAL;
	}
}

int vm_compressor_algorithm(void) {
	return vm_compressor_current_codec;
}

void vm_compressor_algorithm_init(void) {
	vm_compressor_mode_t new_codec = VM_COMPRESSOR_DEFAULT_CODEC;

#if defined(__arm64__)
	new_codec = CMODE_HYB;

	if (PAGE_SIZE == 16384) {
		vmctune.lz4_threshold = 12288;
	}
#endif

	PE_parse_boot_argn("vm_compressor_codec", &new_codec, sizeof(new_codec));
	assertf(((new_codec == VM_COMPRESSOR_DEFAULT_CODEC) || (new_codec == CMODE_WK) ||
		(new_codec == CMODE_LZ4) || (new_codec == CMODE_HYB)),
	    "Invalid VM compression codec: %u", new_codec);

#if defined(__arm__)||defined(__arm64__)
	uint32_t tmpc;
	if (PE_parse_boot_argn("-vm_compressor_wk", &tmpc, sizeof(tmpc))) {
		new_codec = VM_COMPRESSOR_DEFAULT_CODEC;
	} else if (PE_parse_boot_argn("-vm_compressor_hybrid", &tmpc, sizeof(tmpc))) {
		new_codec = CMODE_HYB;
	}

	vm_compressor_current_codec = new_codec;
#endif /* arm/arm64 */
}

