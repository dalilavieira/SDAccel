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
struct sk_buff {int len; unsigned char* data; unsigned int mac_len; } ;
struct inbuf_t {unsigned char* data; int head; int inputstate; size_t tail; struct cardstate* cs; } ;
struct cardstate {unsigned short hw_hdr_len; unsigned int cbytes; char* respdata; scalar_t__ mstate; int /*<<< orphan*/  lock; int /*<<< orphan*/  write_tasklet; scalar_t__ connected; int /*<<< orphan*/  dev; struct bc_state* bcs; scalar_t__ dle; int /*<<< orphan*/  event_tasklet; scalar_t__ running; } ;
struct bc_state {int rx_bufsize; int inputstate; scalar_t__ rx_fcs; scalar_t__ proto2; int /*<<< orphan*/  squeue; struct cardstate* cs; struct sk_buff* rx_skb; scalar_t__ ignore; int /*<<< orphan*/  at_state; } ;
typedef  scalar_t__ __u16 ;

/* Variables and functions */
 int /*<<< orphan*/  DEBUG_HDLC ; 
 int /*<<< orphan*/  DEBUG_INTR ; 
 int /*<<< orphan*/  DEBUG_LOCKCMD ; 
 int /*<<< orphan*/  DEBUG_TRANSCMD ; 
#define  DLE_FLAG 128 
 int ENOMEM ; 
 int /*<<< orphan*/  EV_BC_CLOSED ; 
 int /*<<< orphan*/  EV_BC_OPEN ; 
 int INS_DLE_char ; 
 int INS_DLE_command ; 
 int INS_byte_stuff ; 
 int INS_command ; 
 int INS_have_data ; 
 scalar_t__ L2_HDLC ; 
 unsigned int MAX_RESP_SIZE ; 
 scalar_t__ MS_LOCKED ; 
 unsigned char PPP_ESCAPE ; 
 unsigned char PPP_FLAG ; 
 scalar_t__ PPP_GOODFCS ; 
 scalar_t__ PPP_INITFCS ; 
 unsigned char PPP_TRANS ; 
 unsigned int RBUFSIZE ; 
 int /*<<< orphan*/  __skb_put_u8 (struct sk_buff*,unsigned char) ; 
 int /*<<< orphan*/  __skb_trim (struct sk_buff*,int) ; 
 unsigned char bitrev8 (unsigned char) ; 
 scalar_t__ crc_ccitt_byte (scalar_t__,unsigned char) ; 
 void* dev_alloc_skb (int) ; 
 int /*<<< orphan*/  dev_err (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_kfree_skb_any (struct sk_buff*) ; 
 int /*<<< orphan*/  dev_notice (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  dev_warn (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  gig_dbg (int /*<<< orphan*/ ,char*,...) ; 
 int /*<<< orphan*/  gigaset_add_event (struct cardstate*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  gigaset_dbg_buffer (int /*<<< orphan*/ ,char*,unsigned int,unsigned char*) ; 
 int /*<<< orphan*/  gigaset_handle_modem_response (struct cardstate*) ; 
 int /*<<< orphan*/  gigaset_if_receive (struct cardstate*,unsigned char*,unsigned int) ; 
 int /*<<< orphan*/  gigaset_isdn_rcv_err (struct bc_state*) ; 
 int /*<<< orphan*/  gigaset_skb_rcvd (struct bc_state*,struct sk_buff*) ; 
 int /*<<< orphan*/  memcpy (int /*<<< orphan*/ ,int /*<<< orphan*/ ,unsigned short) ; 
 int /*<<< orphan*/  skb_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  skb_put_u8 (struct sk_buff*,unsigned char) ; 
 int /*<<< orphan*/  skb_queue_tail (int /*<<< orphan*/ *,struct sk_buff*) ; 
 int /*<<< orphan*/  skb_reserve (struct sk_buff*,unsigned short) ; 
 int /*<<< orphan*/  skb_reset_mac_header (struct sk_buff*) ; 
 int /*<<< orphan*/  spin_lock_irqsave (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  spin_unlock_irqrestore (int /*<<< orphan*/ *,unsigned long) ; 
 int /*<<< orphan*/  tasklet_schedule (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline void gigaset_schedule_event(struct cardstate *cs)
{
	unsigned long flags;
	spin_lock_irqsave(&cs->lock, flags);
	if (cs->running)
		tasklet_schedule(&cs->event_tasklet);
	spin_unlock_irqrestore(&cs->lock, flags);
}

__attribute__((used)) static inline void gigaset_bchannel_down(struct bc_state *bcs)
{
	gigaset_add_event(bcs->cs, &bcs->at_state, EV_BC_CLOSED, NULL, 0, NULL);
	gigaset_schedule_event(bcs->cs);
}

__attribute__((used)) static inline void gigaset_bchannel_up(struct bc_state *bcs)
{
	gigaset_add_event(bcs->cs, &bcs->at_state, EV_BC_OPEN, NULL, 0, NULL);
	gigaset_schedule_event(bcs->cs);
}

__attribute__((used)) static inline struct sk_buff *gigaset_new_rx_skb(struct bc_state *bcs)
{
	struct cardstate *cs = bcs->cs;
	unsigned short hw_hdr_len = cs->hw_hdr_len;

	if (bcs->ignore) {
		bcs->rx_skb = NULL;
	} else {
		bcs->rx_skb = dev_alloc_skb(bcs->rx_bufsize + hw_hdr_len);
		if (bcs->rx_skb == NULL)
			dev_warn(cs->dev, "could not allocate skb\n");
		else
			skb_reserve(bcs->rx_skb, hw_hdr_len);
	}
	return bcs->rx_skb;
}

__attribute__((used)) static inline int muststuff(unsigned char c)
{
	if (c < PPP_TRANS) return 1;
	if (c == PPP_FLAG) return 1;
	if (c == PPP_ESCAPE) return 1;
	/* other possible candidates: */
	/* 0x91: XON with parity set */
	/* 0x93: XOFF with parity set */
	return 0;
}

__attribute__((used)) static unsigned cmd_loop(unsigned numbytes, struct inbuf_t *inbuf)
{
	unsigned char *src = inbuf->data + inbuf->head;
	struct cardstate *cs = inbuf->cs;
	unsigned cbytes = cs->cbytes;
	unsigned procbytes = 0;
	unsigned char c;

	while (procbytes < numbytes) {
		c = *src++;
		procbytes++;

		switch (c) {
		case '\n':
			if (cbytes == 0 && cs->respdata[0] == '\r') {
				/* collapse LF with preceding CR */
				cs->respdata[0] = 0;
				break;
			}
			/* --v-- fall through --v-- */
		case '\r':
			/* end of message line, pass to response handler */
			if (cbytes >= MAX_RESP_SIZE) {
				dev_warn(cs->dev, "response too large (%d)\n",
					 cbytes);
				cbytes = MAX_RESP_SIZE;
			}
			cs->cbytes = cbytes;
			gigaset_dbg_buffer(DEBUG_TRANSCMD, "received response",
					   cbytes, cs->respdata);
			gigaset_handle_modem_response(cs);
			cbytes = 0;

			/* store EOL byte for CRLF collapsing */
			cs->respdata[0] = c;

			/* cs->dle may have changed */
			if (cs->dle && !(inbuf->inputstate & INS_DLE_command))
				inbuf->inputstate &= ~INS_command;

			/* return for reevaluating state */
			goto exit;

		case DLE_FLAG:
			if (inbuf->inputstate & INS_DLE_char) {
				/* quoted DLE: clear quote flag */
				inbuf->inputstate &= ~INS_DLE_char;
			} else if (cs->dle ||
				   (inbuf->inputstate & INS_DLE_command)) {
				/* DLE escape, pass up for handling */
				inbuf->inputstate |= INS_DLE_char;
				goto exit;
			}
			/* quoted or not in DLE mode: treat as regular data */
			/* --v-- fall through --v-- */
		default:
			/* append to line buffer if possible */
			if (cbytes < MAX_RESP_SIZE)
				cs->respdata[cbytes] = c;
			cbytes++;
		}
	}
exit:
	cs->cbytes = cbytes;
	return procbytes;
}

__attribute__((used)) static unsigned lock_loop(unsigned numbytes, struct inbuf_t *inbuf)
{
	unsigned char *src = inbuf->data + inbuf->head;

	gigaset_dbg_buffer(DEBUG_LOCKCMD, "received response", numbytes, src);
	gigaset_if_receive(inbuf->cs, src, numbytes);
	return numbytes;
}

__attribute__((used)) static unsigned hdlc_loop(unsigned numbytes, struct inbuf_t *inbuf)
{
	struct cardstate *cs = inbuf->cs;
	struct bc_state *bcs = cs->bcs;
	int inputstate = bcs->inputstate;
	__u16 fcs = bcs->rx_fcs;
	struct sk_buff *skb = bcs->rx_skb;
	unsigned char *src = inbuf->data + inbuf->head;
	unsigned procbytes = 0;
	unsigned char c;

	if (inputstate & INS_byte_stuff) {
		if (!numbytes)
			return 0;
		inputstate &= ~INS_byte_stuff;
		goto byte_stuff;
	}

	while (procbytes < numbytes) {
		c = *src++;
		procbytes++;
		if (c == DLE_FLAG) {
			if (inputstate & INS_DLE_char) {
				/* quoted DLE: clear quote flag */
				inputstate &= ~INS_DLE_char;
			} else if (cs->dle || (inputstate & INS_DLE_command)) {
				/* DLE escape, pass up for handling */
				inputstate |= INS_DLE_char;
				break;
			}
		}

		if (c == PPP_ESCAPE) {
			/* byte stuffing indicator: pull in next byte */
			if (procbytes >= numbytes) {
				/* end of buffer, save for later processing */
				inputstate |= INS_byte_stuff;
				break;
			}
byte_stuff:
			c = *src++;
			procbytes++;
			if (c == DLE_FLAG) {
				if (inputstate & INS_DLE_char) {
					/* quoted DLE: clear quote flag */
					inputstate &= ~INS_DLE_char;
				} else if (cs->dle ||
					   (inputstate & INS_DLE_command)) {
					/* DLE escape, pass up for handling */
					inputstate |=
						INS_DLE_char | INS_byte_stuff;
					break;
				}
			}
			c ^= PPP_TRANS;
#ifdef CONFIG_GIGASET_DEBUG
			if (!muststuff(c))
				gig_dbg(DEBUG_HDLC, "byte stuffed: 0x%02x", c);
#endif
		} else if (c == PPP_FLAG) {
			/* end of frame: process content if any */
			if (inputstate & INS_have_data) {
				gig_dbg(DEBUG_HDLC,
					"7e----------------------------");

				/* check and pass received frame */
				if (!skb) {
					/* skipped frame */
					gigaset_isdn_rcv_err(bcs);
				} else if (skb->len < 2) {
					/* frame too short for FCS */
					dev_warn(cs->dev,
						 "short frame (%d)\n",
						 skb->len);
					gigaset_isdn_rcv_err(bcs);
					dev_kfree_skb_any(skb);
				} else if (fcs != PPP_GOODFCS) {
					/* frame check error */
					dev_err(cs->dev,
						"Checksum failed, %u bytes corrupted!\n",
						skb->len);
					gigaset_isdn_rcv_err(bcs);
					dev_kfree_skb_any(skb);
				} else {
					/* good frame */
					__skb_trim(skb, skb->len - 2);
					gigaset_skb_rcvd(bcs, skb);
				}

				/* prepare reception of next frame */
				inputstate &= ~INS_have_data;
				skb = gigaset_new_rx_skb(bcs);
			} else {
				/* empty frame (7E 7E) */
#ifdef CONFIG_GIGASET_DEBUG
				++bcs->emptycount;
#endif
				if (!skb) {
					/* skipped (?) */
					gigaset_isdn_rcv_err(bcs);
					skb = gigaset_new_rx_skb(bcs);
				}
			}

			fcs = PPP_INITFCS;
			continue;
#ifdef CONFIG_GIGASET_DEBUG
		} else if (muststuff(c)) {
			/* Should not happen. Possible after ZDLE=1<CR><LF>. */
			gig_dbg(DEBUG_HDLC, "not byte stuffed: 0x%02x", c);
#endif
		}

		/* regular data byte, append to skb */
#ifdef CONFIG_GIGASET_DEBUG
		if (!(inputstate & INS_have_data)) {
			gig_dbg(DEBUG_HDLC, "7e (%d x) ================",
				bcs->emptycount);
			bcs->emptycount = 0;
		}
#endif
		inputstate |= INS_have_data;
		if (skb) {
			if (skb->len >= bcs->rx_bufsize) {
				dev_warn(cs->dev, "received packet too long\n");
				dev_kfree_skb_any(skb);
				/* skip remainder of packet */
				bcs->rx_skb = skb = NULL;
			} else {
				__skb_put_u8(skb, c);
				fcs = crc_ccitt_byte(fcs, c);
			}
		}
	}

	bcs->inputstate = inputstate;
	bcs->rx_fcs = fcs;
	return procbytes;
}

__attribute__((used)) static unsigned iraw_loop(unsigned numbytes, struct inbuf_t *inbuf)
{
	struct cardstate *cs = inbuf->cs;
	struct bc_state *bcs = cs->bcs;
	int inputstate = bcs->inputstate;
	struct sk_buff *skb = bcs->rx_skb;
	unsigned char *src = inbuf->data + inbuf->head;
	unsigned procbytes = 0;
	unsigned char c;

	if (!skb) {
		/* skip this block */
		gigaset_new_rx_skb(bcs);
		return numbytes;
	}

	while (procbytes < numbytes && skb->len < bcs->rx_bufsize) {
		c = *src++;
		procbytes++;

		if (c == DLE_FLAG) {
			if (inputstate & INS_DLE_char) {
				/* quoted DLE: clear quote flag */
				inputstate &= ~INS_DLE_char;
			} else if (cs->dle || (inputstate & INS_DLE_command)) {
				/* DLE escape, pass up for handling */
				inputstate |= INS_DLE_char;
				break;
			}
		}

		/* regular data byte: append to current skb */
		inputstate |= INS_have_data;
		__skb_put_u8(skb, bitrev8(c));
	}

	/* pass data up */
	if (inputstate & INS_have_data) {
		gigaset_skb_rcvd(bcs, skb);
		inputstate &= ~INS_have_data;
		gigaset_new_rx_skb(bcs);
	}

	bcs->inputstate = inputstate;
	return procbytes;
}

__attribute__((used)) static void handle_dle(struct inbuf_t *inbuf)
{
	struct cardstate *cs = inbuf->cs;

	if (cs->mstate == MS_LOCKED)
		return;		/* no DLE processing in lock mode */

	if (!(inbuf->inputstate & INS_DLE_char)) {
		/* no DLE pending */
		if (inbuf->data[inbuf->head] == DLE_FLAG &&
		    (cs->dle || inbuf->inputstate & INS_DLE_command)) {
			/* start of DLE sequence */
			inbuf->head++;
			if (inbuf->head == inbuf->tail ||
			    inbuf->head == RBUFSIZE) {
				/* end of buffer, save for later processing */
				inbuf->inputstate |= INS_DLE_char;
				return;
			}
		} else {
			/* regular data byte */
			return;
		}
	}

	/* consume pending DLE */
	inbuf->inputstate &= ~INS_DLE_char;

	switch (inbuf->data[inbuf->head]) {
	case 'X':	/* begin of event message */
		if (inbuf->inputstate & INS_command)
			dev_notice(cs->dev,
				   "received <DLE>X in command mode\n");
		inbuf->inputstate |= INS_command | INS_DLE_command;
		inbuf->head++;	/* byte consumed */
		break;
	case '.':	/* end of event message */
		if (!(inbuf->inputstate & INS_DLE_command))
			dev_notice(cs->dev,
				   "received <DLE>. without <DLE>X\n");
		inbuf->inputstate &= ~INS_DLE_command;
		/* return to data mode if in DLE mode */
		if (cs->dle)
			inbuf->inputstate &= ~INS_command;
		inbuf->head++;	/* byte consumed */
		break;
	case DLE_FLAG:	/* DLE in data stream */
		/* mark as quoted */
		inbuf->inputstate |= INS_DLE_char;
		if (!(cs->dle || inbuf->inputstate & INS_DLE_command))
			dev_notice(cs->dev,
				   "received <DLE><DLE> not in DLE mode\n");
		break;	/* quoted byte left in buffer */
	default:
		dev_notice(cs->dev, "received <DLE><%02x>\n",
			   inbuf->data[inbuf->head]);
		/* quoted byte left in buffer */
	}
}

void gigaset_m10x_input(struct inbuf_t *inbuf)
{
	struct cardstate *cs = inbuf->cs;
	unsigned numbytes, procbytes;

	gig_dbg(DEBUG_INTR, "buffer state: %u -> %u", inbuf->head, inbuf->tail);

	while (inbuf->head != inbuf->tail) {
		/* check for DLE escape */
		handle_dle(inbuf);

		/* process a contiguous block of bytes */
		numbytes = (inbuf->head > inbuf->tail ?
			    RBUFSIZE : inbuf->tail) - inbuf->head;
		gig_dbg(DEBUG_INTR, "processing %u bytes", numbytes);
		/*
		 * numbytes may be 0 if handle_dle() ate the last byte.
		 * This does no harm, *_loop() will just return 0 immediately.
		 */

		if (cs->mstate == MS_LOCKED)
			procbytes = lock_loop(numbytes, inbuf);
		else if (inbuf->inputstate & INS_command)
			procbytes = cmd_loop(numbytes, inbuf);
		else if (cs->bcs->proto2 == L2_HDLC)
			procbytes = hdlc_loop(numbytes, inbuf);
		else
			procbytes = iraw_loop(numbytes, inbuf);
		inbuf->head += procbytes;

		/* check for buffer wraparound */
		if (inbuf->head >= RBUFSIZE)
			inbuf->head = 0;

		gig_dbg(DEBUG_INTR, "head set to %u", inbuf->head);
	}
}

__attribute__((used)) static struct sk_buff *HDLC_Encode(struct sk_buff *skb)
{
	struct sk_buff *hdlc_skb;
	__u16 fcs;
	unsigned char c;
	unsigned char *cp;
	int len;
	unsigned int stuf_cnt;

	stuf_cnt = 0;
	fcs = PPP_INITFCS;
	cp = skb->data;
	len = skb->len;
	while (len--) {
		if (muststuff(*cp))
			stuf_cnt++;
		fcs = crc_ccitt_byte(fcs, *cp++);
	}
	fcs ^= 0xffff;			/* complement */

	/* size of new buffer: original size + number of stuffing bytes
	 * + 2 bytes FCS + 2 stuffing bytes for FCS (if needed) + 2 flag bytes
	 * + room for link layer header
	 */
	hdlc_skb = dev_alloc_skb(skb->len + stuf_cnt + 6 + skb->mac_len);
	if (!hdlc_skb) {
		dev_kfree_skb_any(skb);
		return NULL;
	}

	/* Copy link layer header into new skb */
	skb_reset_mac_header(hdlc_skb);
	skb_reserve(hdlc_skb, skb->mac_len);
	memcpy(skb_mac_header(hdlc_skb), skb_mac_header(skb), skb->mac_len);
	hdlc_skb->mac_len = skb->mac_len;

	/* Add flag sequence in front of everything.. */
	skb_put_u8(hdlc_skb, PPP_FLAG);

	/* Perform byte stuffing while copying data. */
	while (skb->len--) {
		if (muststuff(*skb->data)) {
			skb_put_u8(hdlc_skb, PPP_ESCAPE);
			skb_put_u8(hdlc_skb, (*skb->data++) ^ PPP_TRANS);
		} else
			skb_put_u8(hdlc_skb, *skb->data++);
	}

	/* Finally add FCS (byte stuffed) and flag sequence */
	c = (fcs & 0x00ff);	/* least significant byte first */
	if (muststuff(c)) {
		skb_put_u8(hdlc_skb, PPP_ESCAPE);
		c ^= PPP_TRANS;
	}
	skb_put_u8(hdlc_skb, c);

	c = ((fcs >> 8) & 0x00ff);
	if (muststuff(c)) {
		skb_put_u8(hdlc_skb, PPP_ESCAPE);
		c ^= PPP_TRANS;
	}
	skb_put_u8(hdlc_skb, c);

	skb_put_u8(hdlc_skb, PPP_FLAG);

	dev_kfree_skb_any(skb);
	return hdlc_skb;
}

__attribute__((used)) static struct sk_buff *iraw_encode(struct sk_buff *skb)
{
	struct sk_buff *iraw_skb;
	unsigned char c;
	unsigned char *cp;
	int len;

	/* size of new buffer (worst case = every byte must be stuffed):
	 * 2 * original size + room for link layer header
	 */
	iraw_skb = dev_alloc_skb(2 * skb->len + skb->mac_len);
	if (!iraw_skb) {
		dev_kfree_skb_any(skb);
		return NULL;
	}

	/* copy link layer header into new skb */
	skb_reset_mac_header(iraw_skb);
	skb_reserve(iraw_skb, skb->mac_len);
	memcpy(skb_mac_header(iraw_skb), skb_mac_header(skb), skb->mac_len);
	iraw_skb->mac_len = skb->mac_len;

	/* copy and stuff data */
	cp = skb->data;
	len = skb->len;
	while (len--) {
		c = bitrev8(*cp++);
		if (c == DLE_FLAG)
			skb_put_u8(iraw_skb, c);
		skb_put_u8(iraw_skb, c);
	}
	dev_kfree_skb_any(skb);
	return iraw_skb;
}

int gigaset_m10x_send_skb(struct bc_state *bcs, struct sk_buff *skb)
{
	struct cardstate *cs = bcs->cs;
	unsigned len = skb->len;
	unsigned long flags;

	if (bcs->proto2 == L2_HDLC)
		skb = HDLC_Encode(skb);
	else
		skb = iraw_encode(skb);
	if (!skb) {
		dev_err(cs->dev,
			"unable to allocate memory for encoding!\n");
		return -ENOMEM;
	}

	skb_queue_tail(&bcs->squeue, skb);
	spin_lock_irqsave(&cs->lock, flags);
	if (cs->connected)
		tasklet_schedule(&cs->write_tasklet);
	spin_unlock_irqrestore(&cs->lock, flags);

	return len;	/* ok so far */
}

