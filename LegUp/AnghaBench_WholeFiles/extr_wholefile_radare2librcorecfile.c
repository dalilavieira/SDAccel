#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_52__   TYPE_9__ ;
typedef  struct TYPE_51__   TYPE_8__ ;
typedef  struct TYPE_50__   TYPE_7__ ;
typedef  struct TYPE_49__   TYPE_6__ ;
typedef  struct TYPE_48__   TYPE_5__ ;
typedef  struct TYPE_47__   TYPE_4__ ;
typedef  struct TYPE_46__   TYPE_3__ ;
typedef  struct TYPE_45__   TYPE_2__ ;
typedef  struct TYPE_44__   TYPE_28__ ;
typedef  struct TYPE_43__   TYPE_1__ ;
typedef  struct TYPE_42__   TYPE_16__ ;
typedef  struct TYPE_41__   TYPE_12__ ;
typedef  struct TYPE_40__   TYPE_11__ ;
typedef  struct TYPE_39__   TYPE_10__ ;

/* Type definitions */
typedef  scalar_t__ ut64 ;
struct TYPE_52__ {int xtr_idx; } ;
struct TYPE_51__ {char* name; } ;
struct TYPE_50__ {int internal; int /*<<< orphan*/  data; } ;
struct TYPE_49__ {TYPE_28__* bin; int /*<<< orphan*/  config; int /*<<< orphan*/  io; TYPE_16__* dbg; int /*<<< orphan*/  flags; TYPE_3__* anal; int /*<<< orphan*/  num; TYPE_2__* assembler; } ;
struct TYPE_48__ {int fd; } ;
struct TYPE_47__ {int /*<<< orphan*/  offset; } ;
struct TYPE_46__ {int /*<<< orphan*/  reg; } ;
struct TYPE_45__ {TYPE_1__* cur; } ;
struct TYPE_44__ {int rawstr; void* maxstrbuf; void* minstrlen; } ;
struct TYPE_43__ {int /*<<< orphan*/  arch; } ;
struct TYPE_42__ {int /*<<< orphan*/  bp; } ;
struct TYPE_41__ {int /*<<< orphan*/  file; } ;
struct TYPE_40__ {int /*<<< orphan*/  bits; int /*<<< orphan*/  arch; } ;
struct TYPE_39__ {TYPE_11__* info; } ;
typedef  int /*<<< orphan*/  RIODesc ;
typedef  TYPE_4__ RFlagItem ;
typedef  TYPE_5__ RCoreFile ;
typedef  TYPE_6__ RCore ;
typedef  TYPE_7__ RBreakpointItem ;
typedef  TYPE_8__ RBinPlugin ;
typedef  TYPE_9__ RBinOptions ;
typedef  TYPE_10__ RBinObject ;
typedef  TYPE_11__ RBinInfo ;
typedef  TYPE_12__ RBinFile ;

/* Variables and functions */
 int /*<<< orphan*/  R_BP_PROT_EXEC ; 
 scalar_t__ UT64_MAX ; 
 int /*<<< orphan*/  eprintf (char*,char const*) ; 
 TYPE_12__* r_bin_cur (TYPE_28__*) ; 
 TYPE_10__* r_bin_cur_object (TYPE_28__*) ; 
 TYPE_8__* r_bin_file_cur_plugin (TYPE_12__*) ; 
 int /*<<< orphan*/  r_bin_open (TYPE_28__*,char const*,TYPE_9__*) ; 
 int /*<<< orphan*/  r_bin_open_io (TYPE_28__*,TYPE_9__*) ; 
 int /*<<< orphan*/  r_bin_options_init (TYPE_9__*,int,scalar_t__,scalar_t__,int) ; 
 TYPE_7__* r_bp_add_sw (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ) ; 
 scalar_t__* r_config_get (int /*<<< orphan*/ ,char*) ; 
 void* r_config_get_i (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  r_config_set (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/  r_config_set_i (int /*<<< orphan*/ ,char*,scalar_t__) ; 
 int /*<<< orphan*/  r_core_bin_set_arch_bits (TYPE_6__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  r_core_bin_set_env (TYPE_6__*,TYPE_12__*) ; 
 int /*<<< orphan*/  r_core_cmd0 (TYPE_6__*,char*) ; 
 TYPE_5__* r_core_file_cur (TYPE_6__*) ; 
 int /*<<< orphan*/ * r_core_file_open (TYPE_6__*,char const*,int /*<<< orphan*/ ,scalar_t__) ; 
 int /*<<< orphan*/  r_debug_select (TYPE_16__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 TYPE_4__* r_flag_get (int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/ * r_io_desc_get (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  r_io_fd_get_pid (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  r_io_fd_get_tid (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  r_io_use_fd (int /*<<< orphan*/ ,int) ; 
 scalar_t__ r_num_math (int /*<<< orphan*/ ,char*) ; 
 scalar_t__ r_reg_getv (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  r_str_newf (char*,char const*,char const*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 int /*<<< orphan*/  strncmp (char*,char const*,int) ; 
 scalar_t__ strstr (int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void loadGP(RCore *core) {
	if (strstr (core->assembler->cur->arch, "mips")) {
		ut64 gp = r_num_math (core->num, "loc._gp");
		if (!gp || gp == UT64_MAX) {
			r_config_set (core->config, "anal.roregs", "zero");
			r_core_cmd0 (core, "10aes@entry0");
			r_config_set (core->config, "anal.roregs", "zero,gp");
			gp = r_reg_getv (core->anal->reg, "gp");
		}
		// eprintf ("[mips] gp: 0x%08"PFMT64x"\n", gp);
		r_config_set_i (core->config, "anal.gp", gp);
	}
}

__attribute__((used)) static bool setbpint(RCore *r, const char *mode, const char *sym) {
	RBreakpointItem *bp;
	RFlagItem *fi = r_flag_get (r->flags, sym);
	if (!fi) {
		return false;
	}
	bp = r_bp_add_sw (r->dbg->bp, fi->offset, 1, R_BP_PROT_EXEC);
	if (bp) {
		bp->internal = true;
#if __linux__
		bp->data = r_str_newf ("?e %s: %s", mode, sym);
#else
		bp->data = r_str_newf ("?e %s: %s;ps@rdi", mode, sym);
#endif
		return true;
	}
	eprintf ("Cannot set breakpoint at %s\n", sym);
	return false;
}

__attribute__((used)) static int r_core_file_do_load_for_debug(RCore *r, ut64 baseaddr, const char *filenameuri) {
	RCoreFile *cf = r_core_file_cur (r);
	RIODesc *desc = cf ? r_io_desc_get (r->io, cf->fd) : NULL;
	RBinFile *binfile = NULL;
	RBinPlugin *plugin;
	int xtr_idx = 0; // if 0, load all if xtr is used

	// TODO : Honor file.path eval var too?
	if (!strncmp ("dbg://", filenameuri, 6)) {
		filenameuri += 6;
	}
	if (!desc) {
		return false;
	}
	if (cf) {
		r_debug_select (r->dbg, r_io_fd_get_pid (r->io, cf->fd),
				r_io_fd_get_tid (r->io, cf->fd));
	}
#if !__linux__
#if !__WINDOWS__
	baseaddr = get_base_from_maps (r, filenameuri);
#endif
	if (baseaddr != UT64_MAX) {
		r_config_set_i (r->config, "bin.baddr", baseaddr);
	}
#endif
	int fd = cf? cf->fd: -1;
	RBinOptions opt;
	r_bin_options_init (&opt, fd, baseaddr, UT64_MAX, false);
	opt.xtr_idx = xtr_idx;
	if (!r_bin_open (r->bin, filenameuri, &opt)) {
		eprintf ("RBinLoad: Cannot open %s\n", filenameuri);
		if (r_config_get_i (r->config, "bin.rawstr")) {
			r_bin_options_init (&opt, fd, baseaddr, UT64_MAX, true);
			opt.xtr_idx = xtr_idx;
			if (!r_bin_open (r->bin, filenameuri, &opt)) {
				return false;
			}
		}
	}

	if (*r_config_get (r->config, "dbg.libs")) {
		r_core_cmd0 (r, ".dmm*");
#if __linux__
		setbpint (r, "dbg.libs", "sym.imp.dlopen");
		setbpint (r, "dbg.libs", "sym.imp.dlmopen");
		setbpint (r, "dbg.unlibs", "sym.imp.dlclose");
#elif __APPLE__
		setbpint (r, "dbg.libs", "sym._dlopen");
		setbpint (r, "dbg.libs", "sym._dlclose");
#endif
	}
	binfile = r_bin_cur (r->bin);
	r_core_bin_set_env (r, binfile);
	plugin = r_bin_file_cur_plugin (binfile);
	if (plugin && !strncmp (plugin->name, "any", 5)) {
		// set use of raw strings
		// r_config_set_i (r->config, "io.va", false);
		//\\ r_config_set (r->config, "bin.rawstr", "true");
		// get bin.minstr
		r->bin->minstrlen = r_config_get_i (r->config, "bin.minstr");
		r->bin->maxstrbuf = r_config_get_i (r->config, "bin.maxstrbuf");
	} else if (binfile) {
		RBinObject *obj = r_bin_cur_object (r->bin);
		RBinInfo *info = obj? obj->info: NULL;
		if (plugin && strcmp (plugin->name, "any") && info) {
			r_core_bin_set_arch_bits (r, binfile->file, info->arch, info->bits);
		}
	}

	if (plugin && !strcmp (plugin->name, "dex")) {
		r_core_cmd0 (r, "\"(fix-dex,wx `ph sha1 $s-32 @32` @12 ; wx `ph adler32 $s-12 @12` @8)\"\n");
	}

	return true;
}

__attribute__((used)) static int r_core_file_do_load_for_io_plugin(RCore *r, ut64 baseaddr, ut64 loadaddr) {
	RCoreFile *cf = r_core_file_cur (r);
	int fd = cf ? cf->fd : -1;
	RBinFile *binfile = NULL;
	int xtr_idx = 0; // if 0, load all if xtr is used
	RBinPlugin *plugin;

	if (fd < 0) {
		return false;
	}
	r_io_use_fd (r->io, fd);
	RBinOptions opt;
	r_bin_options_init (&opt, fd, baseaddr, loadaddr, r->bin->rawstr);
	opt.xtr_idx = xtr_idx;
	if (!r_bin_open_io (r->bin, &opt)) {
		//eprintf ("Failed to load the bin with an IO Plugin.\n");
		return false;
	}
	binfile = r_bin_cur (r->bin);
	r_core_bin_set_env (r, binfile);
	plugin = r_bin_file_cur_plugin (binfile);
	if (plugin && !strcmp (plugin->name, "any")) {
		RBinObject *obj = r_bin_cur_object (r->bin);
		RBinInfo *info = obj? obj->info: NULL;
		if (!info) {
			return false;
		}
		// set use of raw strings
		r_core_bin_set_arch_bits (r, binfile->file, info->arch, info->bits);
		// r_config_set_i (r->config, "io.va", false);
		// r_config_set (r->config, "bin.rawstr", "true");
		// get bin.minstr
		r->bin->minstrlen = r_config_get_i (r->config, "bin.minstr");
		r->bin->maxstrbuf = r_config_get_i (r->config, "bin.maxstrbuf");
	} else if (binfile) {
		RBinObject *obj = r_bin_cur_object (r->bin);
		RBinInfo *info = obj? obj->info: NULL;
		if (!info) {
			return false;
		}
		if (plugin && strcmp (plugin->name, "any") && info) {
			r_core_bin_set_arch_bits (r, binfile->file,
				info->arch, info->bits);
		}
	}

	if (plugin && !strcmp (plugin->name, "dex")) {
		r_core_cmd0 (r, "\"(fix-dex,wx `ph sha1 $s-32 @32` @12 ; wx `ph adler32 $s-12 @12` @8)\"\n");
	}
	return true;
}

__attribute__((used)) static bool try_loadlib(RCore *core, const char *lib, ut64 addr) {
	return r_core_file_open (core, lib, 0, addr) != NULL;
}

