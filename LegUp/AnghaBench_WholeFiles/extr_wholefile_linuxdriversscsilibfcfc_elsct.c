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
typedef  int /*<<< orphan*/  u32 ;
struct fc_seq {int dummy; } ;
struct TYPE_2__ {struct fc_seq* (* elsct_send ) (struct fc_lport*,int /*<<< orphan*/ ,struct fc_frame*,unsigned int,void (*) (struct fc_seq*,struct fc_frame*,void*),void*,int /*<<< orphan*/ ) ;} ;
struct fc_lport {TYPE_1__ tt; int /*<<< orphan*/  port_id; } ;
struct fc_frame_header {int fh_type; } ;
struct fc_frame {int dummy; } ;
struct fc_ct_hdr {int /*<<< orphan*/  ct_cmd; } ;
typedef  enum fc_rctl { ____Placeholder_fc_rctl } fc_rctl ;
typedef  enum fc_fh_type { ____Placeholder_fc_fh_type } fc_fh_type ;

/* Variables and functions */
 unsigned int ELS_AUTH_ELS ; 
#define  ELS_LS_ACC 136 
#define  ELS_LS_RJT 135 
#define  FC_EX_CLOSED 134 
#define  FC_EX_TIMEOUT 133 
 int /*<<< orphan*/  FC_FCTL_REQ ; 
#define  FC_FS_ACC 132 
#define  FC_FS_RJT 131 
#define  FC_NO_ERR 130 
#define  FC_TYPE_CT 129 
#define  FC_TYPE_ELS 128 
 scalar_t__ IS_ERR (struct fc_frame*) ; 
 int PTR_ERR (struct fc_frame*) ; 
 int fc_ct_fill (struct fc_lport*,int /*<<< orphan*/ ,struct fc_frame*,unsigned int,int*,int*,int /*<<< orphan*/ *) ; 
 int fc_els_fill (struct fc_lport*,int /*<<< orphan*/ ,struct fc_frame*,unsigned int,int*,int*) ; 
 struct fc_seq* fc_exch_seq_send (struct fc_lport*,struct fc_frame*,void (*) (struct fc_seq*,struct fc_frame*,void*),int /*<<< orphan*/ *,void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fc_fill_fc_hdr (struct fc_frame*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fc_frame_free (struct fc_frame*) ; 
 struct fc_frame_header* fc_frame_header_get (struct fc_frame*) ; 
 struct fc_ct_hdr* fc_frame_payload_get (struct fc_frame*,int) ; 
 int /*<<< orphan*/  fc_frame_payload_op (struct fc_frame*) ; 
 int /*<<< orphan*/  ntohs (int /*<<< orphan*/ ) ; 

struct fc_seq *fc_elsct_send(struct fc_lport *lport, u32 did,
			     struct fc_frame *fp, unsigned int op,
			     void (*resp)(struct fc_seq *,
					  struct fc_frame *,
					  void *),
			     void *arg, u32 timer_msec)
{
	enum fc_rctl r_ctl;
	enum fc_fh_type fh_type;
	int rc;

	/* ELS requests */
	if ((op >= ELS_LS_RJT) && (op <= ELS_AUTH_ELS))
		rc = fc_els_fill(lport, did, fp, op, &r_ctl, &fh_type);
	else {
		/* CT requests */
		rc = fc_ct_fill(lport, did, fp, op, &r_ctl, &fh_type, &did);
	}

	if (rc) {
		fc_frame_free(fp);
		return NULL;
	}

	fc_fill_fc_hdr(fp, r_ctl, did, lport->port_id, fh_type,
		       FC_FCTL_REQ, 0);

	return fc_exch_seq_send(lport, fp, resp, NULL, arg, timer_msec);
}

int fc_elsct_init(struct fc_lport *lport)
{
	if (!lport->tt.elsct_send)
		lport->tt.elsct_send = fc_elsct_send;

	return 0;
}

const char *fc_els_resp_type(struct fc_frame *fp)
{
	const char *msg;
	struct fc_frame_header *fh;
	struct fc_ct_hdr *ct;

	if (IS_ERR(fp)) {
		switch (-PTR_ERR(fp)) {
		case FC_NO_ERR:
			msg = "response no error";
			break;
		case FC_EX_TIMEOUT:
			msg = "response timeout";
			break;
		case FC_EX_CLOSED:
			msg = "response closed";
			break;
		default:
			msg = "response unknown error";
			break;
		}
	} else {
		fh = fc_frame_header_get(fp);
		switch (fh->fh_type) {
		case FC_TYPE_ELS:
			switch (fc_frame_payload_op(fp)) {
			case ELS_LS_ACC:
				msg = "accept";
				break;
			case ELS_LS_RJT:
				msg = "reject";
				break;
			default:
				msg = "response unknown ELS";
				break;
			}
			break;
		case FC_TYPE_CT:
			ct = fc_frame_payload_get(fp, sizeof(*ct));
			if (ct) {
				switch (ntohs(ct->ct_cmd)) {
				case FC_FS_ACC:
					msg = "CT accept";
					break;
				case FC_FS_RJT:
					msg = "CT reject";
					break;
				default:
					msg = "response unknown CT";
					break;
				}
			} else {
				msg = "short CT response";
			}
			break;
		default:
			msg = "response not ELS or CT";
			break;
		}
	}
	return msg;
}

