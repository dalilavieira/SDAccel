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
typedef  int uint ;
typedef  int u8 ;
struct snd_pcm_runtime {int rate; int /*<<< orphan*/  format; } ;
struct snd_pcm_hw_params {int dummy; } ;

/* Variables and functions */
 int EINVAL ; 
 int IEC958_AES0_CON_EMPHASIS_NONE ; 
 int IEC958_AES0_CON_NOT_COPYRIGHT ; 
 int IEC958_AES1_CON_GENERAL ; 
 int IEC958_AES2_CON_CHANNEL_UNSPEC ; 
 int IEC958_AES2_CON_SOURCE_UNSPEC ; 
 unsigned int IEC958_AES3_CON_CLOCK_1000PPM ; 
 unsigned int IEC958_AES3_CON_FS_176400 ; 
 unsigned int IEC958_AES3_CON_FS_192000 ; 
 unsigned int IEC958_AES3_CON_FS_32000 ; 
 unsigned int IEC958_AES3_CON_FS_44100 ; 
 unsigned int IEC958_AES3_CON_FS_48000 ; 
 unsigned int IEC958_AES3_CON_FS_88200 ; 
 unsigned int IEC958_AES3_CON_FS_96000 ; 
 unsigned int IEC958_AES4_CON_MAX_WORDLEN_24 ; 
 unsigned int IEC958_AES4_CON_WORDLEN_20_16 ; 
 unsigned int IEC958_AES4_CON_WORDLEN_22_18 ; 
 unsigned int IEC958_AES4_CON_WORDLEN_24_20 ; 
 int /*<<< orphan*/  memset (int*,int /*<<< orphan*/ ,size_t) ; 
 int params_rate (struct snd_pcm_hw_params*) ; 
 int params_width (struct snd_pcm_hw_params*) ; 
 int snd_pcm_format_width (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int create_iec958_consumer(uint rate, uint sample_width,
				  u8 *cs, size_t len)
{
	unsigned int fs, ws;

	if (len < 4)
		return -EINVAL;

	switch (rate) {
	case 32000:
		fs = IEC958_AES3_CON_FS_32000;
		break;
	case 44100:
		fs = IEC958_AES3_CON_FS_44100;
		break;
	case 48000:
		fs = IEC958_AES3_CON_FS_48000;
		break;
	case 88200:
		fs = IEC958_AES3_CON_FS_88200;
		break;
	case 96000:
		fs = IEC958_AES3_CON_FS_96000;
		break;
	case 176400:
		fs = IEC958_AES3_CON_FS_176400;
		break;
	case 192000:
		fs = IEC958_AES3_CON_FS_192000;
		break;
	default:
		return -EINVAL;
	}

	if (len > 4) {
		switch (sample_width) {
		case 16:
			ws = IEC958_AES4_CON_WORDLEN_20_16;
			break;
		case 18:
			ws = IEC958_AES4_CON_WORDLEN_22_18;
			break;
		case 20:
			ws = IEC958_AES4_CON_WORDLEN_20_16 |
			     IEC958_AES4_CON_MAX_WORDLEN_24;
			break;
		case 24:
		case 32: /* Assume 24-bit width for 32-bit samples. */
			ws = IEC958_AES4_CON_WORDLEN_24_20 |
			     IEC958_AES4_CON_MAX_WORDLEN_24;
			break;

		default:
			return -EINVAL;
		}
	}

	memset(cs, 0, len);

	cs[0] = IEC958_AES0_CON_NOT_COPYRIGHT | IEC958_AES0_CON_EMPHASIS_NONE;
	cs[1] = IEC958_AES1_CON_GENERAL;
	cs[2] = IEC958_AES2_CON_SOURCE_UNSPEC | IEC958_AES2_CON_CHANNEL_UNSPEC;
	cs[3] = IEC958_AES3_CON_CLOCK_1000PPM | fs;

	if (len > 4)
		cs[4] = ws;

	return len;
}

int snd_pcm_create_iec958_consumer(struct snd_pcm_runtime *runtime, u8 *cs,
	size_t len)
{
	return create_iec958_consumer(runtime->rate,
				      snd_pcm_format_width(runtime->format),
				      cs, len);
}

int snd_pcm_create_iec958_consumer_hw_params(struct snd_pcm_hw_params *params,
					     u8 *cs, size_t len)
{
	return create_iec958_consumer(params_rate(params), params_width(params),
				      cs, len);
}

