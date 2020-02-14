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
typedef  size_t u8 ;
struct sk_buff {int len; size_t* data; } ;
struct biquad2_state {int gain; int a1; int a2; int b1; int b2; int z1; int z2; } ;
struct ec_disable_detector_state {int channel_level; int notch_level; int tone_cycle_duration; int good_cycles; int hit; void* tone_present; struct biquad2_state notch; } ;
typedef  int s32 ;
typedef  int int32_t ;
typedef  int int16_t ;

/* Variables and functions */
 int AMI_MASK ; 
 short BIAS ; 
 int DSP_OPT_ULAW ; 
 void* FALSE ; 
 void* TRUE ; 
 int abs (int) ; 
 void* bitrev8 (size_t) ; 
 scalar_t__* dsp_audio_alaw_to_s32 ; 
 size_t* dsp_audio_alaw_to_ulaw ; 
 void** dsp_audio_increase1 ; 
 void** dsp_audio_increase2 ; 
 void** dsp_audio_increase3 ; 
 void** dsp_audio_increase4 ; 
 void** dsp_audio_increase5 ; 
 void** dsp_audio_increase6 ; 
 void** dsp_audio_increase7 ; 
 void** dsp_audio_increase8 ; 
 int* dsp_audio_law2seven ; 
 int* dsp_audio_law_to_s32 ; 
 void** dsp_audio_mix_law ; 
 void** dsp_audio_reduce1 ; 
 void** dsp_audio_reduce2 ; 
 void** dsp_audio_reduce3 ; 
 void** dsp_audio_reduce4 ; 
 void** dsp_audio_reduce5 ; 
 void** dsp_audio_reduce6 ; 
 void** dsp_audio_reduce7 ; 
 void** dsp_audio_reduce8 ; 
 void** dsp_audio_s16_to_law ; 
 size_t* dsp_audio_seven2law ; 
 size_t* dsp_audio_ulaw_to_alaw ; 
 short* dsp_audio_ulaw_to_s32 ; 
 size_t** dsp_audio_volume_change ; 
 int dsp_options ; 

__attribute__((used)) static inline void biquad2_init(struct biquad2_state *bq,
				int32_t gain, int32_t a1, int32_t a2, int32_t b1, int32_t b2)
{
	bq->gain = gain;
	bq->a1 = a1;
	bq->a2 = a2;
	bq->b1 = b1;
	bq->b2 = b2;

	bq->z1 = 0;
	bq->z2 = 0;
}

__attribute__((used)) static inline int16_t biquad2(struct biquad2_state *bq, int16_t sample)
{
	int32_t y;
	int32_t z0;

	z0 = sample * bq->gain + bq->z1 * bq->a1 + bq->z2 * bq->a2;
	y = z0 + bq->z1 * bq->b1 + bq->z2 * bq->b2;

	bq->z2 = bq->z1;
	bq->z1 = z0 >> 15;
	y >>= 15;
	return  y;
}

__attribute__((used)) static inline void
echo_can_disable_detector_init(struct ec_disable_detector_state *det)
{
	/* Elliptic notch */
	/* This is actually centred at 2095Hz, but gets the balance we want, due
	   to the asymmetric walls of the notch */
	biquad2_init(&det->notch,
		     (int32_t)(-0.7600000 * 32768.0),
		     (int32_t)(-0.1183852 * 32768.0),
		     (int32_t)(-0.5104039 * 32768.0),
		     (int32_t)(0.1567596 * 32768.0),
		     (int32_t)(1.0000000 * 32768.0));

	det->channel_level = 0;
	det->notch_level = 0;
	det->tone_present = FALSE;
	det->tone_cycle_duration = 0;
	det->good_cycles = 0;
	det->hit = 0;
}

__attribute__((used)) static inline int
echo_can_disable_detector_update(struct ec_disable_detector_state *det,
				 int16_t amp)
{
	int16_t notched;

	notched = biquad2(&det->notch, amp);
	/* Estimate the overall energy in the channel, and the energy in
	   the notch (i.e. overall channel energy - tone energy => noise).
	   Use abs instead of multiply for speed (is it really faster?).
	   Damp the overall energy a little more for a stable result.
	   Damp the notch energy a little less, so we don't damp out the
	   blip every time the phase reverses */
	det->channel_level += ((abs(amp) - det->channel_level) >> 5);
	det->notch_level += ((abs(notched) - det->notch_level) >> 4);
	if (det->channel_level > 280) {
		/* There is adequate energy in the channel.
		   Is it mostly at 2100Hz? */
		if (det->notch_level * 6 < det->channel_level) {
			/* The notch says yes, so we have the tone. */
			if (!det->tone_present) {
				/* Do we get a kick every 450+-25ms? */
				if (det->tone_cycle_duration >= 425 * 8
				    && det->tone_cycle_duration <= 475 * 8) {
					det->good_cycles++;
					if (det->good_cycles > 2)
						det->hit = TRUE;
				}
				det->tone_cycle_duration = 0;
			}
			det->tone_present = TRUE;
		} else
			det->tone_present = FALSE;
		det->tone_cycle_duration++;
	} else {
		det->tone_present = FALSE;
		det->tone_cycle_duration = 0;
		det->good_cycles = 0;
	}
	return det->hit;
}

__attribute__((used)) static inline unsigned char linear2alaw(short int linear)
{
	int mask;
	int seg;
	int pcm_val;
	static int seg_end[8] = {
		0xFF, 0x1FF, 0x3FF, 0x7FF, 0xFFF, 0x1FFF, 0x3FFF, 0x7FFF
	};

	pcm_val = linear;
	if (pcm_val >= 0) {
		/* Sign (7th) bit = 1 */
		mask = AMI_MASK | 0x80;
	} else {
		/* Sign bit = 0 */
		mask = AMI_MASK;
		pcm_val = -pcm_val;
	}

	/* Convert the scaled magnitude to segment number. */
	for (seg = 0; seg < 8; seg++) {
		if (pcm_val <= seg_end[seg])
			break;
	}
	/* Combine the sign, segment, and quantization bits. */
	return  ((seg << 4) |
		 ((pcm_val >> ((seg)  ?  (seg + 3)  :  4)) & 0x0F)) ^ mask;
}

__attribute__((used)) static inline short int alaw2linear(unsigned char alaw)
{
	int i;
	int seg;

	alaw ^= AMI_MASK;
	i = ((alaw & 0x0F) << 4) + 8 /* rounding error */;
	seg = (((int) alaw & 0x70) >> 4);
	if (seg)
		i = (i + 0x100) << (seg - 1);
	return (short int) ((alaw & 0x80)  ?  i  :  -i);
}

__attribute__((used)) static inline short int ulaw2linear(unsigned char ulaw)
{
	short mu, e, f, y;
	static short etab[] = {0, 132, 396, 924, 1980, 4092, 8316, 16764};

	mu = 255 - ulaw;
	e = (mu & 0x70) / 16;
	f = mu & 0x0f;
	y = f * (1 << (e + 3));
	y += etab[e];
	if (mu & 0x80)
		y = -y;
	return y;
}

__attribute__((used)) static unsigned char linear2ulaw(short sample)
{
	static int exp_lut[256] = {
		0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
		7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
	int sign, exponent, mantissa;
	unsigned char ulawbyte;

	/* Get the sample into sign-magnitude. */
	sign = (sample >> 8) & 0x80;	  /* set aside the sign */
	if (sign != 0)
		sample = -sample;	      /* get magnitude */

	/* Convert from 16 bit linear to ulaw. */
	sample = sample + BIAS;
	exponent = exp_lut[(sample >> 7) & 0xFF];
	mantissa = (sample >> (exponent + 3)) & 0x0F;
	ulawbyte = ~(sign | (exponent << 4) | mantissa);

	return ulawbyte;
}

void dsp_audio_generate_law_tables(void)
{
	int i;
	for (i = 0; i < 256; i++)
		dsp_audio_alaw_to_s32[i] = alaw2linear(bitrev8((u8)i));

	for (i = 0; i < 256; i++)
		dsp_audio_ulaw_to_s32[i] = ulaw2linear(bitrev8((u8)i));

	for (i = 0; i < 256; i++) {
		dsp_audio_alaw_to_ulaw[i] =
			linear2ulaw(dsp_audio_alaw_to_s32[i]);
		dsp_audio_ulaw_to_alaw[i] =
			linear2alaw(dsp_audio_ulaw_to_s32[i]);
	}
}

void
dsp_audio_generate_s2law_table(void)
{
	int i;

	if (dsp_options & DSP_OPT_ULAW) {
		/* generating ulaw-table */
		for (i = -32768; i < 32768; i++) {
			dsp_audio_s16_to_law[i & 0xffff] =
				bitrev8(linear2ulaw(i));
		}
	} else {
		/* generating alaw-table */
		for (i = -32768; i < 32768; i++) {
			dsp_audio_s16_to_law[i & 0xffff] =
				bitrev8(linear2alaw(i));
		}
	}
}

void
dsp_audio_generate_seven(void)
{
	int i, j, k;
	u8 spl;
	u8 sorted_alaw[256];

	/* generate alaw table, sorted by the linear value */
	for (i = 0; i < 256; i++) {
		j = 0;
		for (k = 0; k < 256; k++) {
			if (dsp_audio_alaw_to_s32[k]
			    < dsp_audio_alaw_to_s32[i])
				j++;
		}
		sorted_alaw[j] = i;
	}

	/* generate tabels */
	for (i = 0; i < 256; i++) {
		/* spl is the source: the law-sample (converted to alaw) */
		spl = i;
		if (dsp_options & DSP_OPT_ULAW)
			spl = dsp_audio_ulaw_to_alaw[i];
		/* find the 7-bit-sample */
		for (j = 0; j < 256; j++) {
			if (sorted_alaw[j] == spl)
				break;
		}
		/* write 7-bit audio value */
		dsp_audio_law2seven[i] = j >> 1;
	}
	for (i = 0; i < 128; i++) {
		spl = sorted_alaw[i << 1];
		if (dsp_options & DSP_OPT_ULAW)
			spl = dsp_audio_alaw_to_ulaw[spl];
		dsp_audio_seven2law[i] = spl;
	}
}

void
dsp_audio_generate_mix_table(void)
{
	int i, j;
	s32 sample;

	i = 0;
	while (i < 256) {
		j = 0;
		while (j < 256) {
			sample = dsp_audio_law_to_s32[i];
			sample += dsp_audio_law_to_s32[j];
			if (sample > 32767)
				sample = 32767;
			if (sample < -32768)
				sample = -32768;
			dsp_audio_mix_law[(i << 8) | j] =
				dsp_audio_s16_to_law[sample & 0xffff];
			j++;
		}
		i++;
	}
}

void
dsp_audio_generate_volume_changes(void)
{
	register s32 sample;
	int i;
	int num[]   = { 110, 125, 150, 175, 200, 300, 400, 500 };
	int denum[] = { 100, 100, 100, 100, 100, 100, 100, 100 };

	i = 0;
	while (i < 256) {
		dsp_audio_reduce8[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[7] / num[7]) & 0xffff];
		dsp_audio_reduce7[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[6] / num[6]) & 0xffff];
		dsp_audio_reduce6[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[5] / num[5]) & 0xffff];
		dsp_audio_reduce5[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[4] / num[4]) & 0xffff];
		dsp_audio_reduce4[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[3] / num[3]) & 0xffff];
		dsp_audio_reduce3[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[2] / num[2]) & 0xffff];
		dsp_audio_reduce2[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[1] / num[1]) & 0xffff];
		dsp_audio_reduce1[i] = dsp_audio_s16_to_law[
			(dsp_audio_law_to_s32[i] * denum[0] / num[0]) & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[0] / denum[0];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase1[i] = dsp_audio_s16_to_law[sample & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[1] / denum[1];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase2[i] = dsp_audio_s16_to_law[sample & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[2] / denum[2];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase3[i] = dsp_audio_s16_to_law[sample & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[3] / denum[3];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase4[i] = dsp_audio_s16_to_law[sample & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[4] / denum[4];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase5[i] = dsp_audio_s16_to_law[sample & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[5] / denum[5];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase6[i] = dsp_audio_s16_to_law[sample & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[6] / denum[6];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase7[i] = dsp_audio_s16_to_law[sample & 0xffff];
		sample = dsp_audio_law_to_s32[i] * num[7] / denum[7];
		if (sample < -32768)
			sample = -32768;
		else if (sample > 32767)
			sample = 32767;
		dsp_audio_increase8[i] = dsp_audio_s16_to_law[sample & 0xffff];

		i++;
	}
}

void
dsp_change_volume(struct sk_buff *skb, int volume)
{
	u8 *volume_change;
	int i, ii;
	u8 *p;
	int shift;

	if (volume == 0)
		return;

	/* get correct conversion table */
	if (volume < 0) {
		shift = volume + 8;
		if (shift < 0)
			shift = 0;
	} else {
		shift = volume + 7;
		if (shift > 15)
			shift = 15;
	}
	volume_change = dsp_audio_volume_change[shift];
	i = 0;
	ii = skb->len;
	p = skb->data;
	/* change volume */
	while (i < ii) {
		*p = volume_change[*p];
		p++;
		i++;
	}
}

