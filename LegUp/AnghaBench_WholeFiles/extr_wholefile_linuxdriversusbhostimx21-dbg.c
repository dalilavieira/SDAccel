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
struct urb {int dummy; } ;
struct td {int dummy; } ;
struct imx21 {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void create_debug_files(struct imx21 *imx21) { }

__attribute__((used)) static inline void remove_debug_files(struct imx21 *imx21) { }

__attribute__((used)) static inline void debug_urb_submitted(struct imx21 *imx21, struct urb *urb) {}

__attribute__((used)) static inline void debug_urb_completed(struct imx21 *imx21, struct urb *urb,
	int status) {}

__attribute__((used)) static inline void debug_urb_unlinked(struct imx21 *imx21, struct urb *urb) {}

__attribute__((used)) static inline void debug_urb_queued_for_etd(struct imx21 *imx21,
	struct urb *urb) {}

__attribute__((used)) static inline void debug_urb_queued_for_dmem(struct imx21 *imx21,
	struct urb *urb) {}

__attribute__((used)) static inline void debug_etd_allocated(struct imx21 *imx21) {}

__attribute__((used)) static inline void debug_etd_freed(struct imx21 *imx21) {}

__attribute__((used)) static inline void debug_dmem_allocated(struct imx21 *imx21, int size) {}

__attribute__((used)) static inline void debug_dmem_freed(struct imx21 *imx21, int size) {}

__attribute__((used)) static inline void debug_isoc_submitted(struct imx21 *imx21,
	int frame, struct td *td) {}

__attribute__((used)) static inline void debug_isoc_completed(struct imx21 *imx21,
	int frame, struct td *td, int cc, int len) {}

