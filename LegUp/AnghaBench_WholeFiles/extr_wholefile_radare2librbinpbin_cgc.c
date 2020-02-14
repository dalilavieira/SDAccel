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
typedef  int ut8 ;
typedef  int /*<<< orphan*/  ut64 ;
typedef  int ut32 ;
typedef  int ut16 ;
typedef  int /*<<< orphan*/  tmp ;
typedef  int /*<<< orphan*/  RBuffer ;
typedef  int /*<<< orphan*/  RBinArchOptions ;
typedef  int /*<<< orphan*/  RBin ;

/* Variables and functions */
 int /*<<< orphan*/  CGCMAG ; 
 int SCGCMAG ; 
 int /*<<< orphan*/  eprintf (char*) ; 
 int /*<<< orphan*/  memcmp (int*,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  r_buf_append_bytes (int /*<<< orphan*/ *,int const*,int) ; 
 int /*<<< orphan*/  r_buf_append_nbytes (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_buf_append_ut16 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_buf_append_ut32 (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  r_buf_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_buf_new () ; 
 int /*<<< orphan*/ * r_buf_new_with_bytes (int const*,int /*<<< orphan*/ ) ; 
 int r_buf_read_at (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int*,int) ; 
 int r_buf_size (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_buf_write_at (int /*<<< orphan*/ *,int,int const*,int) ; 

__attribute__((used)) static bool check_buffer(RBuffer *buf) {
	ut8 tmp[SCGCMAG + 1];
	int r = r_buf_read_at (buf, 0, tmp, sizeof (tmp));
	return r > SCGCMAG && !memcmp (tmp, CGCMAG, SCGCMAG) && tmp[4] != 2;
}

__attribute__((used)) static bool check_bytes(const ut8 *b, ut64 length) {
	RBuffer *buf = r_buf_new_with_bytes (b, length);
	bool res = check_buffer (buf);
	r_buf_free (buf);
	return res;
}

__attribute__((used)) static RBuffer* create(RBin* bin, const ut8 *code, int codelen, const ut8 *data, int datalen, RBinArchOptions *opt) {
	ut32 filesize, code_va, code_pa, phoff;
	ut32 p_start, p_phoff, p_phdr;
	ut32 p_ehdrsz, p_phdrsz;
	ut16 ehdrsz, phdrsz;
	ut32 p_vaddr, p_paddr, p_fs, p_fs2;
	ut32 baddr = 0x8048000;
	RBuffer *buf = r_buf_new ();

#define B(x,y) r_buf_append_bytes(buf,(const ut8*)(x),y)
#define D(x) r_buf_append_ut32(buf,x)
#define H(x) r_buf_append_ut16(buf,x)
#define Z(x) r_buf_append_nbytes(buf,x)
#define W(x,y,z) r_buf_write_at(buf,x,(const ut8*)(y),z)
#define WZ(x,y) p_tmp=r_buf_size (buf);Z(x);W(p_tmp,y,strlen(y))

	B ("\x7F" "CGC" "\x01\x01\x01\x43", 8);
	Z (8);
	H (2); // ET_EXEC
	H (3); // e_machne = EM_I386

	D (1);
	p_start = r_buf_size (buf);
	D (-1); // _start
	p_phoff = r_buf_size (buf);
	D (-1); // phoff -- program headers offset
	D (0);  // shoff -- section headers offset
	D (0);  // flags
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

	if (data && datalen>0) {
		//ut32 data_section = buf->length;
		eprintf ("Warning: DATA section not support for ELF yet\n");
		B (data, datalen);
	}
	return buf;
}

