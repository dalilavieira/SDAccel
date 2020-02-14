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
struct page_key_data {unsigned char* data; struct page_key_data* next; } ;
struct page {int dummy; } ;
struct notifier_block {int dummy; } ;
struct TYPE_9__ {int /*<<< orphan*/  mask; } ;
struct TYPE_8__ {int /*<<< orphan*/  mask; } ;
struct TYPE_7__ {int /*<<< orphan*/  mask; } ;
struct TYPE_6__ {int /*<<< orphan*/  mask; } ;
struct TYPE_10__ {TYPE_4__ program_new_psw; TYPE_3__ io_new_psw; TYPE_2__ svc_new_psw; TYPE_1__ external_new_psw; } ;

/* Variables and functions */
 unsigned long DIV_ROUND_UP (unsigned long,size_t) ; 
 int ENOMEM ; 
 int /*<<< orphan*/  GFP_KERNEL ; 
 int /*<<< orphan*/  LC_ORDER ; 
 unsigned long LC_PAGES ; 
 int NOTIFY_BAD ; 
 int NOTIFY_DONE ; 
 int NOTIFY_OK ; 
 size_t PAGE_KEY_DATA_SIZE ; 
 int PFN_DOWN (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  PFN_PHYS (unsigned long) ; 
#define  PM_HIBERNATION_PREPARE 131 
#define  PM_POST_HIBERNATION 130 
#define  PM_POST_SUSPEND 129 
#define  PM_SUSPEND_PREPARE 128 
 int /*<<< orphan*/  PSW_MASK_MCHECK ; 
 TYPE_5__ S390_lowcore ; 
 int /*<<< orphan*/  __ctl_clear_bit (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  __ctl_set_bit (int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/ * __end_rodata ; 
 int /*<<< orphan*/  __get_free_pages (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  __nosave_begin ; 
 int /*<<< orphan*/  __nosave_end ; 
 int /*<<< orphan*/  __pa (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * _stext ; 
 int /*<<< orphan*/  arch_set_page_dat (struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  arch_set_page_nodat (struct page*,int /*<<< orphan*/ ) ; 
 scalar_t__ arch_test_page_nodat (struct page*) ; 
 int /*<<< orphan*/  channel_subsystem_reinit () ; 
 int /*<<< orphan*/  free_page (unsigned long) ; 
 int /*<<< orphan*/  free_pages (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ get_zeroed_page (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  lgr_info_log () ; 
 int /*<<< orphan*/  local_mcck_disable () ; 
 int /*<<< orphan*/  local_mcck_enable () ; 
 scalar_t__ page_address (struct page*) ; 
 scalar_t__ page_get_storage_key (unsigned long) ; 
 struct page_key_data* page_key_data ; 
 struct page_key_data* page_key_rp ; 
 size_t page_key_rx ; 
 struct page_key_data* page_key_wp ; 
 size_t page_key_wx ; 
 int /*<<< orphan*/  page_set_storage_key (unsigned long,unsigned char,int /*<<< orphan*/ ) ; 
 struct page* pfn_to_page (unsigned long) ; 
 int /*<<< orphan*/  suspend_zero_pages ; 
 scalar_t__ tprot (int /*<<< orphan*/ ) ; 
 struct page* virt_to_page (void*) ; 
 int /*<<< orphan*/  zpci_rescan () ; 

unsigned long page_key_additional_pages(unsigned long pages)
{
	return DIV_ROUND_UP(pages, PAGE_KEY_DATA_SIZE);
}

void page_key_free(void)
{
	struct page_key_data *pkd;

	while (page_key_data) {
		pkd = page_key_data;
		page_key_data = pkd->next;
		free_page((unsigned long) pkd);
	}
}

int page_key_alloc(unsigned long pages)
{
	struct page_key_data *pk;
	unsigned long size;

	size = DIV_ROUND_UP(pages, PAGE_KEY_DATA_SIZE);
	while (size--) {
		pk = (struct page_key_data *) get_zeroed_page(GFP_KERNEL);
		if (!pk) {
			page_key_free();
			return -ENOMEM;
		}
		pk->next = page_key_data;
		page_key_data = pk;
	}
	page_key_rp = page_key_wp = page_key_data;
	page_key_rx = page_key_wx = 0;
	return 0;
}

void page_key_read(unsigned long *pfn)
{
	struct page *page;
	unsigned long addr;
	unsigned char key;

	page = pfn_to_page(*pfn);
	addr = (unsigned long) page_address(page);
	key = (unsigned char) page_get_storage_key(addr) & 0x7f;
	if (arch_test_page_nodat(page))
		key |= 0x80;
	*(unsigned char *) pfn = key;
}

void page_key_memorize(unsigned long *pfn)
{
	page_key_wp->data[page_key_wx] = *(unsigned char *) pfn;
	*(unsigned char *) pfn = 0;
	if (++page_key_wx < PAGE_KEY_DATA_SIZE)
		return;
	page_key_wp = page_key_wp->next;
	page_key_wx = 0;
}

void page_key_write(void *address)
{
	struct page *page;
	unsigned char key;

	key = page_key_rp->data[page_key_rx];
	page_set_storage_key((unsigned long) address, key & 0x7f, 0);
	page = virt_to_page(address);
	if (key & 0x80)
		arch_set_page_nodat(page, 0);
	else
		arch_set_page_dat(page, 0);
	if (++page_key_rx >= PAGE_KEY_DATA_SIZE)
		return;
	page_key_rp = page_key_rp->next;
	page_key_rx = 0;
}

int pfn_is_nosave(unsigned long pfn)
{
	unsigned long nosave_begin_pfn = PFN_DOWN(__pa(&__nosave_begin));
	unsigned long nosave_end_pfn = PFN_DOWN(__pa(&__nosave_end));
	unsigned long end_rodata_pfn = PFN_DOWN(__pa(__end_rodata)) - 1;
	unsigned long stext_pfn = PFN_DOWN(__pa(_stext));

	/* Always save lowcore pages (LC protection might be enabled). */
	if (pfn <= LC_PAGES)
		return 0;
	if (pfn >= nosave_begin_pfn && pfn < nosave_end_pfn)
		return 1;
	/* Skip memory holes and read-only pages (DCSS, ...). */
	if (pfn >= stext_pfn && pfn <= end_rodata_pfn)
		return 0;
	if (tprot(PFN_PHYS(pfn)))
		return 1;
	return 0;
}

__attribute__((used)) static int suspend_pm_cb(struct notifier_block *nb, unsigned long action,
			 void *ptr)
{
	switch (action) {
	case PM_SUSPEND_PREPARE:
	case PM_HIBERNATION_PREPARE:
		suspend_zero_pages = __get_free_pages(GFP_KERNEL, LC_ORDER);
		if (!suspend_zero_pages)
			return NOTIFY_BAD;
		break;
	case PM_POST_SUSPEND:
	case PM_POST_HIBERNATION:
		free_pages(suspend_zero_pages, LC_ORDER);
		break;
	default:
		return NOTIFY_DONE;
	}
	return NOTIFY_OK;
}

void save_processor_state(void)
{
	/* swsusp_arch_suspend() actually saves all cpu register contents.
	 * Machine checks must be disabled since swsusp_arch_suspend() stores
	 * register contents to their lowcore save areas. That's the same
	 * place where register contents on machine checks would be saved.
	 * To avoid register corruption disable machine checks.
	 * We must also disable machine checks in the new psw mask for
	 * program checks, since swsusp_arch_suspend() may generate program
	 * checks. Disabling machine checks for all other new psw masks is
	 * just paranoia.
	 */
	local_mcck_disable();
	/* Disable lowcore protection */
	__ctl_clear_bit(0,28);
	S390_lowcore.external_new_psw.mask &= ~PSW_MASK_MCHECK;
	S390_lowcore.svc_new_psw.mask &= ~PSW_MASK_MCHECK;
	S390_lowcore.io_new_psw.mask &= ~PSW_MASK_MCHECK;
	S390_lowcore.program_new_psw.mask &= ~PSW_MASK_MCHECK;
}

void restore_processor_state(void)
{
	S390_lowcore.external_new_psw.mask |= PSW_MASK_MCHECK;
	S390_lowcore.svc_new_psw.mask |= PSW_MASK_MCHECK;
	S390_lowcore.io_new_psw.mask |= PSW_MASK_MCHECK;
	S390_lowcore.program_new_psw.mask |= PSW_MASK_MCHECK;
	/* Enable lowcore protection */
	__ctl_set_bit(0,28);
	local_mcck_enable();
}

void s390_early_resume(void)
{
	lgr_info_log();
	channel_subsystem_reinit();
	zpci_rescan();
}

