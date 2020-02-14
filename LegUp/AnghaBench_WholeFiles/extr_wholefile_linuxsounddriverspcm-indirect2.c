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
struct snd_pcm_substream {struct snd_pcm_runtime* runtime; } ;
struct snd_pcm_runtime {int boundary; TYPE_1__* control; } ;
struct snd_pcm_indirect2 {scalar_t__ min_periods; scalar_t__ sw_io; scalar_t__ sw_buffer_size; int check_alignment; int bytes2hw; unsigned int sw_data; unsigned int min_period_count; int hw_buffer_size; void* appl_ptr; int sw_ready; int hw_ready; int min_multiple; } ;
typedef  void* snd_pcm_uframes_t ;
typedef  int snd_pcm_sframes_t ;
typedef  unsigned int (* snd_pcm_indirect2_zero_t ) (struct snd_pcm_substream*,struct snd_pcm_indirect2*) ;
typedef  void* (* snd_pcm_indirect2_copy_t ) (struct snd_pcm_substream*,struct snd_pcm_indirect2*,size_t) ;
struct TYPE_2__ {void* appl_ptr; } ;

/* Variables and functions */
 scalar_t__ SNDRV_PCM_POS_XRUN ; 
 void* bytes_to_frames (struct snd_pcm_runtime*,scalar_t__) ; 
 scalar_t__ frames_to_bytes (struct snd_pcm_runtime*,int) ; 
 int snd_pcm_lib_period_bytes (struct snd_pcm_substream*) ; 
 int /*<<< orphan*/  snd_pcm_period_elapsed (struct snd_pcm_substream*) ; 

__attribute__((used)) static void
snd_pcm_indirect2_increase_min_periods(struct snd_pcm_substream *substream,
				       struct snd_pcm_indirect2 *rec,
				       int isplay, int iscopy,
				       unsigned int bytes)
{
	if (rec->min_periods >= 0) {
		if (iscopy) {
			rec->sw_io += bytes;
			if (rec->sw_io >= rec->sw_buffer_size)
				rec->sw_io -= rec->sw_buffer_size;
		} else if (isplay) {
			/* If application does not write data in multiples of
			 * a period, move sw_data to the next correctly aligned
			 * position, so that sw_io can converge to it (in the
			 * next step).
			 */
			if (!rec->check_alignment) {
				if (rec->bytes2hw %
				    snd_pcm_lib_period_bytes(substream)) {
					unsigned bytes2hw_aligned =
					    (1 +
					     (rec->bytes2hw /
					      snd_pcm_lib_period_bytes
					      (substream))) *
					    snd_pcm_lib_period_bytes
					    (substream);
					rec->sw_data =
					    bytes2hw_aligned %
					    rec->sw_buffer_size;
#ifdef SND_PCM_INDIRECT2_STAT
					snd_printk(KERN_DEBUG
						   "STAT: @re-align: aligned "
						   "bytes2hw to next period "
						   "size boundary: %d "
						   "(instead of %d)\n",
						   bytes2hw_aligned,
						   rec->bytes2hw);
					snd_printk(KERN_DEBUG
						   "STAT: @re-align: sw_data "
						   "moves to: %d\n",
						   rec->sw_data);
#endif
				}
				rec->check_alignment = 1;
			}
			/* We are at the end and are copying zeros into the
			 * fifo.
			 * Now, we have to make sure that sw_io is increased
			 * until the position of sw_data: Filling the fifo with
			 * the first zeros means, the last bytes were played.
			 */
			if (rec->sw_io != rec->sw_data) {
				unsigned int diff;
				if (rec->sw_data > rec->sw_io)
					diff = rec->sw_data - rec->sw_io;
				else
					diff = (rec->sw_buffer_size -
						rec->sw_io) +
						rec->sw_data;
				if (bytes >= diff)
					rec->sw_io = rec->sw_data;
				else {
					rec->sw_io += bytes;
					if (rec->sw_io >= rec->sw_buffer_size)
						rec->sw_io -=
						    rec->sw_buffer_size;
				}
			}
		}
		rec->min_period_count += bytes;
		if (rec->min_period_count >= (rec->hw_buffer_size / 2)) {
			rec->min_periods += (rec->min_period_count /
					     (rec->hw_buffer_size / 2));
#ifdef SND_PCM_INDIRECT2_STAT
			if ((rec->min_period_count /
			     (rec->hw_buffer_size / 2)) > 7)
				snd_printk(KERN_DEBUG
					   "STAT: more than 7 (%d) min_adds "
					   "at once - too big to save!\n",
					   (rec->min_period_count /
					    (rec->hw_buffer_size / 2)));
			else
				rec->min_adds[(rec->min_period_count /
					       (rec->hw_buffer_size / 2))]++;
#endif
			rec->min_period_count = (rec->min_period_count %
						 (rec->hw_buffer_size / 2));
		}
	} else if (isplay && iscopy)
		rec->min_periods = 0;
}

snd_pcm_uframes_t
snd_pcm_indirect2_pointer(struct snd_pcm_substream *substream,
			  struct snd_pcm_indirect2 *rec)
{
#ifdef SND_PCM_INDIRECT2_STAT
	rec->pointer_calls++;
#endif
	return bytes_to_frames(substream->runtime, rec->sw_io);
}

__attribute__((used)) static void
snd_pcm_indirect2_playback_transfer(struct snd_pcm_substream *substream,
				    struct snd_pcm_indirect2 *rec,
				    snd_pcm_indirect2_copy_t copy,
				    snd_pcm_indirect2_zero_t zero)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	snd_pcm_uframes_t appl_ptr = runtime->control->appl_ptr;

	/* runtime->control->appl_ptr: position where ALSA will write next time
	 * rec->appl_ptr: position where ALSA was last time
	 * diff: obviously ALSA wrote that much bytes into the intermediate
	 * buffer since we checked last time
	 */
	snd_pcm_sframes_t diff = appl_ptr - rec->appl_ptr;

	if (diff) {
#ifdef SND_PCM_INDIRECT2_STAT
		rec->lastdifftime = jiffies;
#endif
		if (diff < -(snd_pcm_sframes_t) (runtime->boundary / 2))
			diff += runtime->boundary;
		/* number of bytes "added" by ALSA increases the number of
		 * bytes which are ready to "be transferred to HW"/"played"
		 * Then, set rec->appl_ptr to not count bytes twice next time.
		 */
		rec->sw_ready += (int)frames_to_bytes(runtime, diff);
		rec->appl_ptr = appl_ptr;
	}
	if (rec->hw_ready && (rec->sw_ready <= 0)) {
		unsigned int bytes;

#ifdef SND_PCM_INDIRECT2_STAT
		if (rec->firstzerotime == 0) {
			rec->firstzerotime = jiffies;
			snd_printk(KERN_DEBUG
				   "STAT: @firstzerotime: mul_elapsed: %d, "
				   "min_period_count: %d\n",
				   rec->mul_elapsed, rec->min_period_count);
			snd_printk(KERN_DEBUG
				   "STAT: @firstzerotime: sw_io: %d, "
				   "sw_data: %d, appl_ptr: %u\n",
				   rec->sw_io, rec->sw_data,
				   (unsigned int)appl_ptr);
		}
		if ((jiffies - rec->firstzerotime) < 3750) {
			rec->zero_times[(jiffies - rec->firstzerotime)]++;
			rec->zero_times_saved++;
		} else
			rec->zero_times_notsaved++;
#endif
		bytes = zero(substream, rec);

#ifdef SND_PCM_INDIRECT2_STAT
		rec->zeros2hw += bytes;
		if (bytes < 64)
			rec->zero_sizes[bytes]++;
		else
			snd_printk(KERN_DEBUG
				   "STAT: %d zero Bytes copied to hardware at "
				   "once - too big to save!\n",
				   bytes);
#endif
		snd_pcm_indirect2_increase_min_periods(substream, rec, 1, 0,
						       bytes);
		return;
	}
	while (rec->hw_ready && (rec->sw_ready > 0)) {
		/* sw_to_end: max. number of bytes that can be read/take from
		 * the current position (sw_data) in _one_ step
		 */
		unsigned int sw_to_end = rec->sw_buffer_size - rec->sw_data;

		/* bytes: number of bytes we have available (for reading) */
		unsigned int bytes = rec->sw_ready;

		if (sw_to_end < bytes)
			bytes = sw_to_end;
		if (!bytes)
			break;

#ifdef SND_PCM_INDIRECT2_STAT
		if (rec->firstbytetime == 0)
			rec->firstbytetime = jiffies;
		rec->lastbytetime = jiffies;
#endif
		/* copy bytes from intermediate buffer position sw_data to the
		 * HW and return number of bytes actually written
		 * Furthermore, set hw_ready to 0, if the fifo isn't empty
		 * now => more could be transferred to fifo
		 */
		bytes = copy(substream, rec, bytes);
		rec->bytes2hw += bytes;

#ifdef SND_PCM_INDIRECT2_STAT
		if (bytes < 64)
			rec->byte_sizes[bytes]++;
		else
			snd_printk(KERN_DEBUG
				   "STAT: %d Bytes copied to hardware at once "
				   "- too big to save!\n",
				   bytes);
#endif
		/* increase sw_data by the number of actually written bytes
		 * (= number of taken bytes from intermediate buffer)
		 */
		rec->sw_data += bytes;
		if (rec->sw_data == rec->sw_buffer_size)
			rec->sw_data = 0;
		/* now sw_data is the position where ALSA is going to write
		 * in the intermediate buffer next time = position we are going
		 * to read from next time
		 */

		snd_pcm_indirect2_increase_min_periods(substream, rec, 1, 1,
						       bytes);

		/* we read bytes from intermediate buffer, so we need to say
		 * that the number of bytes ready for transfer are decreased
		 * now
		 */
		rec->sw_ready -= bytes;
	}
	return;
}

void
snd_pcm_indirect2_playback_interrupt(struct snd_pcm_substream *substream,
				     struct snd_pcm_indirect2 *rec,
				     snd_pcm_indirect2_copy_t copy,
				     snd_pcm_indirect2_zero_t zero)
{
#ifdef SND_PCM_INDIRECT2_STAT
	rec->irq_occured++;
#endif
	/* hardware played some bytes, so there is room again (in fifo) */
	rec->hw_ready = 1;

	/* don't call ack() now, instead call transfer() function directly
	 * (normally called by ack() )
	 */
	snd_pcm_indirect2_playback_transfer(substream, rec, copy, zero);

	if (rec->min_periods >= rec->min_multiple) {
#ifdef SND_PCM_INDIRECT2_STAT
		if ((rec->min_periods / rec->min_multiple) > 7)
			snd_printk(KERN_DEBUG
				   "STAT: more than 7 (%d) mul_adds - too big "
				   "to save!\n",
				   (rec->min_periods / rec->min_multiple));
		else
			rec->mul_adds[(rec->min_periods /
				       rec->min_multiple)]++;
		rec->mul_elapsed_real += (rec->min_periods /
					  rec->min_multiple);
		rec->mul_elapsed++;
#endif
		rec->min_periods = (rec->min_periods % rec->min_multiple);
		snd_pcm_period_elapsed(substream);
	}
}

__attribute__((used)) static void
snd_pcm_indirect2_capture_transfer(struct snd_pcm_substream *substream,
				   struct snd_pcm_indirect2 *rec,
				   snd_pcm_indirect2_copy_t copy,
				   snd_pcm_indirect2_zero_t null)
{
	struct snd_pcm_runtime *runtime = substream->runtime;
	snd_pcm_uframes_t appl_ptr = runtime->control->appl_ptr;
	snd_pcm_sframes_t diff = appl_ptr - rec->appl_ptr;

	if (diff) {
#ifdef SND_PCM_INDIRECT2_STAT
		rec->lastdifftime = jiffies;
#endif
		if (diff < -(snd_pcm_sframes_t) (runtime->boundary / 2))
			diff += runtime->boundary;
		rec->sw_ready -= frames_to_bytes(runtime, diff);
		rec->appl_ptr = appl_ptr;
	}
	/* if hardware has something, but the intermediate buffer is full
	 * => skip contents of buffer
	 */
	if (rec->hw_ready && (rec->sw_ready >= (int)rec->sw_buffer_size)) {
		unsigned int bytes;

#ifdef SND_PCM_INDIRECT2_STAT
		if (rec->firstzerotime == 0) {
			rec->firstzerotime = jiffies;
			snd_printk(KERN_DEBUG "STAT: (capture) "
				   "@firstzerotime: mul_elapsed: %d, "
				   "min_period_count: %d\n",
				   rec->mul_elapsed, rec->min_period_count);
			snd_printk(KERN_DEBUG "STAT: (capture) "
				   "@firstzerotime: sw_io: %d, sw_data: %d, "
				   "appl_ptr: %u\n",
				   rec->sw_io, rec->sw_data,
				   (unsigned int)appl_ptr);
		}
		if ((jiffies - rec->firstzerotime) < 3750) {
			rec->zero_times[(jiffies - rec->firstzerotime)]++;
			rec->zero_times_saved++;
		} else
			rec->zero_times_notsaved++;
#endif
		bytes = null(substream, rec);

#ifdef SND_PCM_INDIRECT2_STAT
		rec->zeros2hw += bytes;
		if (bytes < 64)
			rec->zero_sizes[bytes]++;
		else
			snd_printk(KERN_DEBUG
				   "STAT: (capture) %d zero Bytes copied to "
				   "hardware at once - too big to save!\n",
				   bytes);
#endif
		snd_pcm_indirect2_increase_min_periods(substream, rec, 0, 0,
						       bytes);
		/* report an overrun */
		rec->sw_io = SNDRV_PCM_POS_XRUN;
		return;
	}
	while (rec->hw_ready && (rec->sw_ready < (int)rec->sw_buffer_size)) {
		/* sw_to_end: max. number of bytes that we can write to the
		 *  intermediate buffer (until it's end)
		 */
		size_t sw_to_end = rec->sw_buffer_size - rec->sw_data;

		/* bytes: max. number of bytes, which may be copied to the
		 *  intermediate buffer without overflow (in _one_ step)
		 */
		size_t bytes = rec->sw_buffer_size - rec->sw_ready;

		/* limit number of bytes (for transfer) by available room in
		 * the intermediate buffer
		 */
		if (sw_to_end < bytes)
			bytes = sw_to_end;
		if (!bytes)
			break;

#ifdef SND_PCM_INDIRECT2_STAT
		if (rec->firstbytetime == 0)
			rec->firstbytetime = jiffies;
		rec->lastbytetime = jiffies;
#endif
		/* copy bytes from the intermediate buffer (position sw_data)
		 * to the HW at most and return number of bytes actually copied
		 * from HW
		 * Furthermore, set hw_ready to 0, if the fifo is empty now.
		 */
		bytes = copy(substream, rec, bytes);
		rec->bytes2hw += bytes;

#ifdef SND_PCM_INDIRECT2_STAT
		if (bytes < 64)
			rec->byte_sizes[bytes]++;
		else
			snd_printk(KERN_DEBUG
				   "STAT: (capture) %d Bytes copied to "
				   "hardware at once - too big to save!\n",
				   bytes);
#endif
		/* increase sw_data by the number of actually copied bytes from
		 * HW
		 */
		rec->sw_data += bytes;
		if (rec->sw_data == rec->sw_buffer_size)
			rec->sw_data = 0;

		snd_pcm_indirect2_increase_min_periods(substream, rec, 0, 1,
						       bytes);

		/* number of bytes in the intermediate buffer, which haven't
		 * been fetched by ALSA yet.
		 */
		rec->sw_ready += bytes;
	}
	return;
}

void
snd_pcm_indirect2_capture_interrupt(struct snd_pcm_substream *substream,
				    struct snd_pcm_indirect2 *rec,
				    snd_pcm_indirect2_copy_t copy,
				    snd_pcm_indirect2_zero_t null)
{
#ifdef SND_PCM_INDIRECT2_STAT
	rec->irq_occured++;
#endif
	/* hardware recorded some bytes, so there is something to read from the
	 * record fifo:
	 */
	rec->hw_ready = 1;

	/* don't call ack() now, instead call transfer() function directly
	 * (normally called by ack() )
	 */
	snd_pcm_indirect2_capture_transfer(substream, rec, copy, null);

	if (rec->min_periods >= rec->min_multiple) {

#ifdef SND_PCM_INDIRECT2_STAT
		if ((rec->min_periods / rec->min_multiple) > 7)
			snd_printk(KERN_DEBUG
				   "STAT: more than 7 (%d) mul_adds - "
				   "too big to save!\n",
				   (rec->min_periods / rec->min_multiple));
		else
			rec->mul_adds[(rec->min_periods /
				       rec->min_multiple)]++;
		rec->mul_elapsed_real += (rec->min_periods /
					  rec->min_multiple);
		rec->mul_elapsed++;
#endif
		rec->min_periods = (rec->min_periods % rec->min_multiple);
		snd_pcm_period_elapsed(substream);
	}
}

