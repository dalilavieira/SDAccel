#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  int ut8 ;
typedef  int ut64 ;
typedef  int ut32 ;
typedef  int ut16 ;
struct TYPE_8__ {scalar_t__ arch; } ;
struct TYPE_7__ {int /*<<< orphan*/  buf; TYPE_1__* rbin; } ;
struct TYPE_6__ {int /*<<< orphan*/  (* cb_printf ) (char*,int /*<<< orphan*/ ) ;} ;
typedef  int /*<<< orphan*/  RBuffer ;
typedef  TYPE_2__ RBinFile ;
typedef  TYPE_3__ RBinArchOptions ;
typedef  int /*<<< orphan*/  RBin ;

/* Variables and functions */
 int /*<<< orphan*/  ELFMAG ; 
 int /*<<< orphan*/  SELFMAG ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 scalar_t__ memcmp (int const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_buf_append_bytes (int /*<<< orphan*/ *,int const*,int) ; 
 int /*<<< orphan*/  r_buf_append_nbytes (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_buf_append_ut16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_buf_append_ut32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * r_buf_new () ; 
 int /*<<< orphan*/  r_buf_read_le16_at (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  r_buf_read_le32_at (int /*<<< orphan*/ ,int) ; 
 int r_buf_size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_buf_write_at (int /*<<< orphan*/ *,int,int const*,int) ; 
 int /*<<< orphan*/  r_return_val_if_fail (int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  strcmp (scalar_t__,char*) ; 
 int /*<<< orphan*/  stub1 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub2 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub4 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub5 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub6 (char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub7 (char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void headers32(RBinFile *bf) {
#define p bf->rbin->cb_printf
	p ("0x00000000  ELF MAGIC   0x%08x\n", r_buf_read_le32_at (bf->buf, 0));
	p ("0x00000010  Type        0x%04x\n", r_buf_read_le16_at (bf->buf, 0x10));
	p ("0x00000012  Machine     0x%04x\n", r_buf_read_le16_at (bf->buf, 0x12));
	p ("0x00000014  Version     0x%08x\n", r_buf_read_le32_at (bf->buf, 0x14));
	p ("0x00000018  Entrypoint  0x%08x\n", r_buf_read_le32_at (bf->buf, 0x18));
	p ("0x0000001c  PhOff       0x%08x\n", r_buf_read_le32_at (bf->buf, 0x1c));
	p ("0x00000020  ShOff       0x%08x\n", r_buf_read_le32_at (bf->buf, 0x20));
}

__attribute__((used)) static bool check_bytes(const ut8 *buf, ut64 length) {
	return buf && length > 4 && memcmp (buf, ELFMAG, SELFMAG) == 0
		&& buf[4] != 2;
}

__attribute__((used)) static RBuffer* create(RBin* bin, const ut8 *code, int codelen, const ut8 *data, int datalen, RBinArchOptions *opt) {
	ut32 filesize, code_va, code_pa, phoff;
	ut32 p_start, p_phoff, p_phdr;
	ut32 p_ehdrsz, p_phdrsz;
	ut16 ehdrsz, phdrsz;
	ut32 p_vaddr, p_paddr, p_fs, p_fs2;
	ut32 baddr;
	int is_arm = 0;
	RBuffer *buf = r_buf_new ();

	r_return_val_if_fail (bin && opt && opt->arch, NULL);
	is_arm = !strcmp (opt->arch, "arm");
	// XXX: hardcoded
	if (is_arm) {
		baddr = 0x40000;
	} else {
		baddr = 0x8048000;
	}

#define B(x,y) r_buf_append_bytes(buf,(const ut8*)(x),y)
#define D(x) r_buf_append_ut32(buf,x)
#define H(x) r_buf_append_ut16(buf,x)
#define Z(x) r_buf_append_nbytes(buf,x)
#define W(x,y,z) r_buf_write_at(buf,x,(const ut8*)(y),z)
#define WZ(x,y) p_tmp=r_buf_size (buf);Z(x);W(p_tmp,y,strlen(y))

	B ("\x7F" "ELF" "\x01\x01\x01\x00", 8);
	Z (8);
	H (2); // ET_EXEC
	if (is_arm) {
		H (40); // e_machne = EM_ARM
	} else {
		H (3); // e_machne = EM_I386
	}

	D (1);
	p_start = r_buf_size (buf);
	D (-1); // _start
	p_phoff = r_buf_size (buf);
	D (-1); // phoff -- program headers offset
	D (0);  // shoff -- section headers offset
	D (0); // flags
	p_ehdrsz = r_buf_size (buf);
	H (-1); // ehdrsz
	p_phdrsz = r_buf_size (buf);
	H (-1); // phdrsz
	H (1);
	H (0);
	H (0);
	H (0);
	// phdr:
	p_phdr = r_buf_size (buf);
	D (1);
	D (0);
	p_vaddr = r_buf_size (buf);
	D (-1); // vaddr = $$
	p_paddr = r_buf_size (buf);
	D (-1); // paddr = $$
	p_fs = r_buf_size (buf);
	D (-1); // filesize
	p_fs2 = r_buf_size (buf);
	D (-1); // filesize
	D (5); // flags
	D (0x1000); // align

	ehdrsz = p_phdr;
	phdrsz = r_buf_size (buf) - p_phdr;
	code_pa = r_buf_size (buf);
	code_va = code_pa + baddr;
	phoff = 0x34;//p_phdr ;
	filesize = code_pa + codelen + datalen;

	W (p_start, &code_va, 4);
	W (p_phoff, &phoff, 4);
	W (p_ehdrsz, &ehdrsz, 2);
	W (p_phdrsz, &phdrsz, 2);

	code_va = baddr; // hack
	W (p_vaddr, &code_va, 4);
	code_pa = baddr; // hack
	W (p_paddr, &code_pa, 4);

	W (p_fs, &filesize, 4);
	W (p_fs2, &filesize, 4);

	B (code, codelen);

	if (data && datalen > 0) {
		//ut32 data_section = buf->length;
		eprintf ("Warning: DATA section not support for ELF yet\n");
		B (data, datalen);
	}
	return buf;
}

