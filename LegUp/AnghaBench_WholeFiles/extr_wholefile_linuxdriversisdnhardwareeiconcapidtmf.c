#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ word ;
struct TYPE_8__ {int min_gap_duration; int min_digit_duration; scalar_t__ cycle_counter; int current_digit_on_time; scalar_t__ current_digit_off_time; size_t current_digit_value; int digit_write_pos; scalar_t__ digit_read_pos; int indication_state; int indication_state_ack; int state; long** goertzel_buffer; size_t* digit_buffer; } ;
struct TYPE_9__ {size_t ulaw; TYPE_1__ recv; } ;
typedef  TYPE_2__ t_capidtmf_state ;
typedef  int /*<<< orphan*/  spinlock_t ;
typedef  int dword ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_t ;
typedef  int /*<<< orphan*/  diva_os_spin_lock_magic_t ;
typedef  int diva_os_atomic_t ;
typedef  size_t byte ;
typedef  int /*<<< orphan*/  __u32 ;
typedef  int /*<<< orphan*/  __u16 ;
typedef  int /*<<< orphan*/  __le32 ;
typedef  int /*<<< orphan*/  __le16 ;

/* Variables and functions */
 scalar_t__ CAPIDTMF_LOW_GROUP_FREQUENCIES ; 
 scalar_t__ CAPIDTMF_RECV_ACCUMULATE_CYCLES ; 
 scalar_t__ CAPIDTMF_RECV_BASE_FREQUENCY_COUNT ; 
 int CAPIDTMF_RECV_DIGIT_BUFFER_SIZE ; 
 scalar_t__ CAPIDTMF_RECV_FUNDAMENTAL_DECREMENT ; 
 long CAPIDTMF_RECV_FUNDAMENTAL_OFFSET ; 
 int CAPIDTMF_RECV_INDICATION_DIGIT ; 
 size_t CAPIDTMF_RECV_NO_DIGIT ; 
 int CAPIDTMF_RECV_STATE_DTMF_ACTIVE ; 
 scalar_t__ CAPIDTMF_RECV_STATE_IDLE ; 
 int CAPIDTMF_RECV_TIME_GRANULARITY ; 
 int CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT ; 
 int CAPIDTMF_RECV_WINDOWED_SAMPLES ; 
 scalar_t__ DSPDTMF_RX_HIGH_EXCEEDING_LOW_DEFAULT ; 
 scalar_t__ DSPDTMF_RX_LOW_EXCEEDING_HIGH_DEFAULT ; 
 scalar_t__ DSPDTMF_RX_SENSITIVITY_HIGH_DEFAULT ; 
 scalar_t__ DSPDTMF_RX_SENSITIVITY_LOW_DEFAULT ; 
 scalar_t__ FILE_ ; 
 scalar_t__ capidtmf_dword_leading_zeroes (int) ; 
 long* capidtmf_expand_table_alaw ; 
 long* capidtmf_expand_table_ulaw ; 
 long* capidtmf_recv_goertzel_coef_table ; 
 scalar_t__* capidtmf_recv_guard_snr_high_table ; 
 scalar_t__* capidtmf_recv_guard_snr_low_table ; 
 short* capidtmf_recv_window_function ; 
 int /*<<< orphan*/  cpu_to_le16 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  cpu_to_le32 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  dprintf (char*,char*,int) ; 
 int /*<<< orphan*/  le16_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  le32_to_cpu (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  mdelay (int) ; 
 int /*<<< orphan*/  msleep (int) ; 
 int /*<<< orphan*/  spin_lock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_lock_init (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  spin_unlock_bh (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  trace (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vfree (void*) ; 
 scalar_t__ vmalloc (unsigned int) ; 

__attribute__((used)) static __inline__ void *diva_os_malloc(unsigned long flags, unsigned long size)
{
	void *ret = NULL;

	if (size) {
		ret = (void *) vmalloc((unsigned int) size);
	}
	return (ret);
}

__attribute__((used)) static __inline__ void diva_os_free(unsigned long flags, void *ptr)
{
	vfree(ptr);
}

__attribute__((used)) static __inline__ void diva_os_sleep(dword mSec)
{
	msleep(mSec);
}

__attribute__((used)) static __inline__ void diva_os_wait(dword mSec)
{
	mdelay(mSec);
}

__attribute__((used)) static __inline__ int diva_os_initialize_spin_lock(spinlock_t *lock, void *unused) { \
	spin_lock_init(lock); return (0); }

__attribute__((used)) static __inline__ void diva_os_enter_spin_lock(diva_os_spin_lock_t *a, \
					       diva_os_spin_lock_magic_t *old_irql, \
					       void *dbg) { spin_lock_bh(a); }

__attribute__((used)) static __inline__ void diva_os_leave_spin_lock(diva_os_spin_lock_t *a, \
					       diva_os_spin_lock_magic_t *old_irql, \
					       void *dbg) { spin_unlock_bh(a); }

__attribute__((used)) static inline diva_os_atomic_t
diva_os_atomic_increment(diva_os_atomic_t *pv)
{
	*pv += 1;
	return (*pv);
}

__attribute__((used)) static inline diva_os_atomic_t
diva_os_atomic_decrement(diva_os_atomic_t *pv)
{
	*pv -= 1;
	return (*pv);
}

__attribute__((used)) static inline __u16 GET_WORD(void *addr)
{
	return le16_to_cpu(*(__le16 *)addr);
}

__attribute__((used)) static inline __u32 GET_DWORD(void *addr)
{
	return le32_to_cpu(*(__le32 *)addr);
}

__attribute__((used)) static inline void PUT_WORD(void *addr, __u16 v)
{
	*(__le16 *)addr = cpu_to_le16(v);
}

__attribute__((used)) static inline void PUT_DWORD(void *addr, __u32 v)
{
	*(__le32 *)addr = cpu_to_le32(v);
}

__attribute__((used)) static void capidtmf_goertzel_loop(long *buffer, long *coeffs, short *sample, long count)
{
	int i, j;
	long c, d, q0, q1, q2;

	for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT - 1; i++)
	{
		q1 = buffer[i];
		q2 = buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
		d = coeffs[i] >> 1;
		c = d << 1;
		if (c >= 0)
		{
			for (j = 0; j < count; j++)
			{
				q0 = sample[j] - q2 + (c * (q1 >> 16)) + (((dword)(((dword) d) * ((dword)(q1 & 0xffff)))) >> 15);
				q2 = q1;
				q1 = q0;
			}
		}
		else
		{
			c = -c;
			d = -d;
			for (j = 0; j < count; j++)
			{
				q0 = sample[j] - q2 - ((c * (q1 >> 16)) + (((dword)(((dword) d) * ((dword)(q1 & 0xffff)))) >> 15));
				q2 = q1;
				q1 = q0;
			}
		}
		buffer[i] = q1;
		buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT] = q2;
	}
	q1 = buffer[i];
	q2 = buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
	c = (coeffs[i] >> 1) << 1;
	if (c >= 0)
	{
		for (j = 0; j < count; j++)
		{
			q0 = sample[j] - q2 + (c * (q1 >> 16)) + (((dword)(((dword)(c >> 1)) * ((dword)(q1 & 0xffff)))) >> 15);
			q2 = q1;
			q1 = q0;
			c -= CAPIDTMF_RECV_FUNDAMENTAL_DECREMENT;
		}
	}
	else
	{
		c = -c;
		for (j = 0; j < count; j++)
		{
			q0 = sample[j] - q2 - ((c * (q1 >> 16)) + (((dword)(((dword)(c >> 1)) * ((dword)(q1 & 0xffff)))) >> 15));
			q2 = q1;
			q1 = q0;
			c += CAPIDTMF_RECV_FUNDAMENTAL_DECREMENT;
		}
	}
	coeffs[i] = c;
	buffer[i] = q1;
	buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT] = q2;
}

__attribute__((used)) static void capidtmf_goertzel_result(long *buffer, long *coeffs)
{
	int i;
	long d, e, q1, q2, lo, mid, hi;
	dword k;

	for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
	{
		q1 = buffer[i];
		q2 = buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
		d = coeffs[i] >> 1;
		if (d >= 0)
			d = ((d << 1) * (-q1 >> 16)) + (((dword)(((dword) d) * ((dword)(-q1 & 0xffff)))) >> 15);
		else
			d = ((-d << 1) * (-q1 >> 16)) + (((dword)(((dword) -d) * ((dword)(-q1 & 0xffff)))) >> 15);
		e = (q2 >= 0) ? q2 : -q2;
		if (d >= 0)
		{
			k = ((dword)(d & 0xffff)) * ((dword)(e & 0xffff));
			lo = k & 0xffff;
			mid = k >> 16;
			k = ((dword)(d >> 16)) * ((dword)(e & 0xffff));
			mid += k & 0xffff;
			hi = k >> 16;
			k = ((dword)(d & 0xffff)) * ((dword)(e >> 16));
			mid += k & 0xffff;
			hi += k >> 16;
			hi += ((dword)(d >> 16)) * ((dword)(e >> 16));
		}
		else
		{
			d = -d;
			k = ((dword)(d & 0xffff)) * ((dword)(e & 0xffff));
			lo = -((long)(k & 0xffff));
			mid = -((long)(k >> 16));
			k = ((dword)(d >> 16)) * ((dword)(e & 0xffff));
			mid -= k & 0xffff;
			hi = -((long)(k >> 16));
			k = ((dword)(d & 0xffff)) * ((dword)(e >> 16));
			mid -= k & 0xffff;
			hi -= k >> 16;
			hi -= ((dword)(d >> 16)) * ((dword)(e >> 16));
		}
		if (q2 < 0)
		{
			lo = -lo;
			mid = -mid;
			hi = -hi;
		}
		d = (q1 >= 0) ? q1 : -q1;
		k = ((dword)(d & 0xffff)) * ((dword)(d & 0xffff));
		lo += k & 0xffff;
		mid += k >> 16;
		k = ((dword)(d >> 16)) * ((dword)(d & 0xffff));
		mid += (k & 0xffff) << 1;
		hi += (k >> 16) << 1;
		hi += ((dword)(d >> 16)) * ((dword)(d >> 16));
		d = (q2 >= 0) ? q2 : -q2;
		k = ((dword)(d & 0xffff)) * ((dword)(d & 0xffff));
		lo += k & 0xffff;
		mid += k >> 16;
		k = ((dword)(d >> 16)) * ((dword)(d & 0xffff));
		mid += (k & 0xffff) << 1;
		hi += (k >> 16) << 1;
		hi += ((dword)(d >> 16)) * ((dword)(d >> 16));
		mid += lo >> 16;
		hi += mid >> 16;
		buffer[i] = (lo & 0xffff) | (mid << 16);
		buffer[i + CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT] = hi;
	}
}

__attribute__((used)) static void capidtmf_recv_init(t_capidtmf_state *p_state)
{
	p_state->recv.min_gap_duration = 1;
	p_state->recv.min_digit_duration = 1;

	p_state->recv.cycle_counter = 0;
	p_state->recv.current_digit_on_time = 0;
	p_state->recv.current_digit_off_time = 0;
	p_state->recv.current_digit_value = CAPIDTMF_RECV_NO_DIGIT;

	p_state->recv.digit_write_pos = 0;
	p_state->recv.digit_read_pos = 0;
	p_state->recv.indication_state = 0;
	p_state->recv.indication_state_ack = 0;
	p_state->recv.state = CAPIDTMF_RECV_STATE_IDLE;
}

void capidtmf_recv_enable(t_capidtmf_state *p_state, word min_digit_duration, word min_gap_duration)
{
	p_state->recv.indication_state_ack &= CAPIDTMF_RECV_INDICATION_DIGIT;
	p_state->recv.min_digit_duration = (word)(((((dword) min_digit_duration) * 8) +
						   ((dword)(CAPIDTMF_RECV_TIME_GRANULARITY / 2))) / ((dword) CAPIDTMF_RECV_TIME_GRANULARITY));
	if (p_state->recv.min_digit_duration <= 1)
		p_state->recv.min_digit_duration = 1;
	else
		(p_state->recv.min_digit_duration)--;
	p_state->recv.min_gap_duration =
		(word)((((dword) min_gap_duration) * 8) / ((dword) CAPIDTMF_RECV_TIME_GRANULARITY));
	if (p_state->recv.min_gap_duration <= 1)
		p_state->recv.min_gap_duration = 1;
	else
		(p_state->recv.min_gap_duration)--;
	p_state->recv.state |= CAPIDTMF_RECV_STATE_DTMF_ACTIVE;
}

void capidtmf_recv_disable(t_capidtmf_state *p_state)
{
	p_state->recv.state &= ~CAPIDTMF_RECV_STATE_DTMF_ACTIVE;
	if (p_state->recv.state == CAPIDTMF_RECV_STATE_IDLE)
		capidtmf_recv_init(p_state);
	else
	{
		p_state->recv.cycle_counter = 0;
		p_state->recv.current_digit_on_time = 0;
		p_state->recv.current_digit_off_time = 0;
		p_state->recv.current_digit_value = CAPIDTMF_RECV_NO_DIGIT;
	}
}

void capidtmf_recv_block(t_capidtmf_state *p_state, byte *buffer, word length)
{
	byte result_digit;
	word sample_number, cycle_counter, n, i;
	word low_peak, high_peak;
	dword lo, hi;
	byte   *p;
	short *q;
	byte goertzel_result_buffer[CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT];
	short windowed_sample_buffer[CAPIDTMF_RECV_WINDOWED_SAMPLES];


	if (p_state->recv.state & CAPIDTMF_RECV_STATE_DTMF_ACTIVE)
	{
		cycle_counter = p_state->recv.cycle_counter;
		sample_number = 0;
		while (sample_number < length)
		{
			if (cycle_counter < CAPIDTMF_RECV_ACCUMULATE_CYCLES)
			{
				if (cycle_counter == 0)
				{
					for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
					{
						p_state->recv.goertzel_buffer[0][i] = 0;
						p_state->recv.goertzel_buffer[1][i] = 0;
					}
				}
				n = CAPIDTMF_RECV_ACCUMULATE_CYCLES - cycle_counter;
				if (n > length - sample_number)
					n = length - sample_number;
				if (n > CAPIDTMF_RECV_WINDOWED_SAMPLES)
					n = CAPIDTMF_RECV_WINDOWED_SAMPLES;
				p = buffer + sample_number;
				q = capidtmf_recv_window_function + cycle_counter;
				if (p_state->ulaw)
				{
					for (i = 0; i < n; i++)
					{
						windowed_sample_buffer[i] =
							(short)((capidtmf_expand_table_ulaw[p[i]] * ((long)(q[i]))) >> 15);
					}
				}
				else
				{
					for (i = 0; i < n; i++)
					{
						windowed_sample_buffer[i] =
							(short)((capidtmf_expand_table_alaw[p[i]] * ((long)(q[i]))) >> 15);
					}
				}
				capidtmf_recv_goertzel_coef_table[CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT - 1] = CAPIDTMF_RECV_FUNDAMENTAL_OFFSET;
				capidtmf_goertzel_loop(p_state->recv.goertzel_buffer[0],
						       capidtmf_recv_goertzel_coef_table, windowed_sample_buffer, n);
				cycle_counter += n;
				sample_number += n;
			}
			else
			{
				capidtmf_goertzel_result(p_state->recv.goertzel_buffer[0],
							 capidtmf_recv_goertzel_coef_table);
				for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
				{
					lo = (dword)(p_state->recv.goertzel_buffer[0][i]);
					hi = (dword)(p_state->recv.goertzel_buffer[1][i]);
					if (hi != 0)
					{
						n = capidtmf_dword_leading_zeroes(hi);
						hi = (hi << n) | (lo >> (32 - n));
					}
					else
					{
						n = capidtmf_dword_leading_zeroes(lo);
						hi = lo << n;
						n += 32;
					}
					n = 195 - 3 * n;
					if (hi >= 0xcb300000L)
						n += 2;
					else if (hi >= 0xa1450000L)
						n++;
					goertzel_result_buffer[i] = (byte) n;
				}
				low_peak = DSPDTMF_RX_SENSITIVITY_LOW_DEFAULT;
				result_digit = CAPIDTMF_RECV_NO_DIGIT;
				for (i = 0; i < CAPIDTMF_LOW_GROUP_FREQUENCIES; i++)
				{
					if (goertzel_result_buffer[i] > low_peak)
					{
						low_peak = goertzel_result_buffer[i];
						result_digit = (byte) i;
					}
				}
				high_peak = DSPDTMF_RX_SENSITIVITY_HIGH_DEFAULT;
				n = CAPIDTMF_RECV_NO_DIGIT;
				for (i = CAPIDTMF_LOW_GROUP_FREQUENCIES; i < CAPIDTMF_RECV_BASE_FREQUENCY_COUNT; i++)
				{
					if (goertzel_result_buffer[i] > high_peak)
					{
						high_peak = goertzel_result_buffer[i];
						n = (i - CAPIDTMF_LOW_GROUP_FREQUENCIES) << 2;
					}
				}
				result_digit |= (byte) n;
				if (low_peak + DSPDTMF_RX_HIGH_EXCEEDING_LOW_DEFAULT < high_peak)
					result_digit = CAPIDTMF_RECV_NO_DIGIT;
				if (high_peak + DSPDTMF_RX_LOW_EXCEEDING_HIGH_DEFAULT < low_peak)
					result_digit = CAPIDTMF_RECV_NO_DIGIT;
				n = 0;
				for (i = 0; i < CAPIDTMF_RECV_TOTAL_FREQUENCY_COUNT; i++)
				{
					if ((((short)(low_peak - goertzel_result_buffer[i] - capidtmf_recv_guard_snr_low_table[i])) < 0)
					    || (((short)(high_peak - goertzel_result_buffer[i] - capidtmf_recv_guard_snr_high_table[i])) < 0))
					{
						n++;
					}
				}
				if (n != 2)
					result_digit = CAPIDTMF_RECV_NO_DIGIT;

				if (result_digit == CAPIDTMF_RECV_NO_DIGIT)
				{
					if (p_state->recv.current_digit_on_time != 0)
					{
						if (++(p_state->recv.current_digit_off_time) >= p_state->recv.min_gap_duration)
						{
							p_state->recv.current_digit_on_time = 0;
							p_state->recv.current_digit_off_time = 0;
						}
					}
					else
					{
						if (p_state->recv.current_digit_off_time != 0)
							(p_state->recv.current_digit_off_time)--;
					}
				}
				else
				{
					if ((p_state->recv.current_digit_on_time == 0)
					    && (p_state->recv.current_digit_off_time != 0))
					{
						(p_state->recv.current_digit_off_time)--;
					}
					else
					{
						n = p_state->recv.current_digit_off_time;
						if ((p_state->recv.current_digit_on_time != 0)
						    && (result_digit != p_state->recv.current_digit_value))
						{
							p_state->recv.current_digit_on_time = 0;
							n = 0;
						}
						p_state->recv.current_digit_value = result_digit;
						p_state->recv.current_digit_off_time = 0;
						if (p_state->recv.current_digit_on_time != 0xffff)
						{
							p_state->recv.current_digit_on_time += n + 1;
							if (p_state->recv.current_digit_on_time >= p_state->recv.min_digit_duration)
							{
								p_state->recv.current_digit_on_time = 0xffff;
								i = (p_state->recv.digit_write_pos == CAPIDTMF_RECV_DIGIT_BUFFER_SIZE - 1) ?
									0 : p_state->recv.digit_write_pos + 1;
								if (i == p_state->recv.digit_read_pos)
								{
									trace(dprintf("%s,%d: Receive digit overrun",
										      (char *)(FILE_), __LINE__));
								}
								else
								{
									p_state->recv.digit_buffer[p_state->recv.digit_write_pos] = result_digit;
									p_state->recv.digit_write_pos = i;
									p_state->recv.indication_state =
										(p_state->recv.indication_state & ~CAPIDTMF_RECV_INDICATION_DIGIT) |
										(~p_state->recv.indication_state_ack & CAPIDTMF_RECV_INDICATION_DIGIT);
								}
							}
						}
					}
				}
				cycle_counter = 0;
				sample_number++;
			}
		}
		p_state->recv.cycle_counter = cycle_counter;
	}
}

void capidtmf_init(t_capidtmf_state *p_state, byte ulaw)
{
	p_state->ulaw = ulaw;
	capidtmf_recv_init(p_state);
}

