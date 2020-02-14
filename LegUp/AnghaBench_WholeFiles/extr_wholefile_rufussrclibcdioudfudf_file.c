#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_29__   TYPE_8__ ;
typedef  struct TYPE_28__   TYPE_6__ ;
typedef  struct TYPE_27__   TYPE_5__ ;
typedef  struct TYPE_26__   TYPE_4__ ;
typedef  struct TYPE_25__   TYPE_3__ ;
typedef  struct TYPE_24__   TYPE_2__ ;
typedef  struct TYPE_23__   TYPE_21__ ;
typedef  struct TYPE_22__   TYPE_1__ ;

/* Type definitions */
typedef  long uint64_t ;
typedef  size_t uint32_t ;
typedef  int uint16_t ;
struct TYPE_24__ {scalar_t__ i_part_start; scalar_t__ i_position; } ;
typedef  TYPE_2__ udf_t ;
struct TYPE_25__ {scalar_t__ len; scalar_t__ pos; } ;
typedef  TYPE_3__ udf_short_ad_t ;
struct TYPE_22__ {int /*<<< orphan*/  lba; } ;
struct TYPE_26__ {scalar_t__ len; TYPE_1__ loc; } ;
typedef  TYPE_4__ udf_long_ad_t ;
struct TYPE_27__ {int strat_type; int flags; } ;
typedef  TYPE_5__ udf_icbtag_t ;
struct TYPE_28__ {int /*<<< orphan*/  i_extended_attr; int /*<<< orphan*/  i_alloc_descs; TYPE_5__ icb_tag; } ;
typedef  TYPE_6__ udf_fileid_desc_t ;
typedef  TYPE_6__ udf_file_entry_t ;
struct TYPE_23__ {int link_count; int /*<<< orphan*/  info_len; } ;
struct TYPE_29__ {char const* psz_name; int b_dir; TYPE_2__* p_udf; TYPE_21__ fe; TYPE_21__* fid; } ;
typedef  TYPE_8__ udf_dirent_t ;
typedef  scalar_t__ ssize_t ;
typedef  scalar_t__ off_t ;
typedef  scalar_t__ lba_t ;
typedef  scalar_t__ driver_return_code_t ;

/* Variables and functions */
 scalar_t__ CDIO_INVALID_LBA ; 
 size_t CEILING (size_t,scalar_t__) ; 
 scalar_t__ DRIVER_OP_ERROR ; 
 scalar_t__ DRIVER_OP_SUCCESS ; 
 scalar_t__ GETICB (int /*<<< orphan*/ ) ; 
#define  ICBTAG_FLAG_AD_EXTENDED 132 
#define  ICBTAG_FLAG_AD_IN_ICB 131 
#define  ICBTAG_FLAG_AD_LONG 130 
 int ICBTAG_FLAG_AD_MASK ; 
#define  ICBTAG_FLAG_AD_SHORT 129 
#define  ICBTAG_STRATEGY_TYPE_4 128 
 scalar_t__ MIN (size_t,size_t) ; 
 scalar_t__ UDF_BLOCKSIZE ; 
 int /*<<< orphan*/  cdio_warn (char*,...) ; 
 scalar_t__ i_lba ; 
 int /*<<< orphan*/  memcpy (TYPE_6__*,TYPE_21__*,int) ; 
 scalar_t__ udf_read_sectors (TYPE_2__*,void*,scalar_t__,size_t) ; 
 int uint16_from_le (int) ; 
 scalar_t__ uint32_from_le (int /*<<< orphan*/ ) ; 
 long uint64_from_le (int /*<<< orphan*/ ) ; 

const char *
udf_get_filename(const udf_dirent_t *p_udf_dirent)
{
  if (!p_udf_dirent) return NULL;
  if (!p_udf_dirent->psz_name) return "..";
  return p_udf_dirent->psz_name;
}

bool
udf_get_file_entry(const udf_dirent_t *p_udf_dirent, 
		   /*out*/ udf_file_entry_t *p_udf_fe)
{
  if (!p_udf_dirent) return false;
  memcpy(p_udf_fe, &p_udf_dirent->fe, sizeof(udf_file_entry_t));
  return true;
}

bool udf_get_fileid_descriptor(const udf_dirent_t *p_udf_dirent, 
			       /*out*/ udf_fileid_desc_t *p_udf_fid)
{
  
  if (!p_udf_dirent) return false;
  if (!p_udf_dirent->fid) {
    /* FIXME do something about trying to get the descriptor. */
    return false;
  }
  memcpy(p_udf_fid, p_udf_dirent->fid, sizeof(udf_fileid_desc_t));
  return true;
}

uint16_t udf_get_link_count(const udf_dirent_t *p_udf_dirent) 
{
  if (p_udf_dirent) {
    return uint16_from_le(p_udf_dirent->fe.link_count);
  }
  return 0; /* Error. Non-error case handled above. */
}

uint64_t udf_get_file_length(const udf_dirent_t *p_udf_dirent) 
{
  if (p_udf_dirent) {
    return uint64_from_le(p_udf_dirent->fe.info_len);
  }
  return 2147483647L; /* Error. Non-error case handled above. */
}

bool
udf_is_dir(const udf_dirent_t *p_udf_dirent)
{
  return p_udf_dirent->b_dir;
}

__attribute__((used)) static lba_t
offset_to_lba(const udf_dirent_t *p_udf_dirent, off_t i_offset, 
	      /*out*/ lba_t *pi_lba, /*out*/ uint32_t *pi_max_size)
{
  udf_t *p_udf = p_udf_dirent->p_udf;
  const udf_file_entry_t *p_udf_fe = (udf_file_entry_t *) 
    &p_udf_dirent->fe;
  const udf_icbtag_t *p_icb_tag = &p_udf_fe->icb_tag;
  const uint16_t strat_type= uint16_from_le(p_icb_tag->strat_type);

  if (i_offset < 0) {
    cdio_warn("Negative offset value");
    return CDIO_INVALID_LBA;
  }

  switch (strat_type) {
  case 4096:
    cdio_warn("Cannot deal with strategy4096 yet!");
    return CDIO_INVALID_LBA;
    break;
  case ICBTAG_STRATEGY_TYPE_4:
    {
      off_t icblen = 0;
      uint64_t lsector;
      int ad_offset, ad_num = 0;
      uint16_t addr_ilk = uint16_from_le(p_icb_tag->flags&ICBTAG_FLAG_AD_MASK);
      
      switch (addr_ilk) {
      case ICBTAG_FLAG_AD_SHORT: 
	{
	  udf_short_ad_t *p_icb;
	  /*
	   * The allocation descriptor field is filled with short_ad's.
	   * If the offset is beyond the current extent, look for the
	   * next extent.
	   */
	  do {
	    i_offset -= icblen;
	    ad_offset = sizeof(udf_short_ad_t) * ad_num;
	    if (ad_offset > uint32_from_le(p_udf_fe->i_alloc_descs)) {
	      cdio_warn("File offset out of bounds");
	      return CDIO_INVALID_LBA;
	    }
	    p_icb = (udf_short_ad_t *) 
	      GETICB( uint32_from_le(p_udf_fe->i_extended_attr) 
		      + ad_offset );
	    icblen = p_icb->len;
	    ad_num++;
	  } while(i_offset >= icblen);
	  
	  lsector = (i_offset / UDF_BLOCKSIZE) + p_icb->pos;
	  
	  *pi_max_size = p_icb->len;
	}
	break;
      case ICBTAG_FLAG_AD_LONG: 
	{
	  /*
	   * The allocation descriptor field is filled with long_ad's
	   * If the i_offset is beyond the current extent, look for the
	   * next extent.
	   */
	  udf_long_ad_t *p_icb;
	  do {
	    i_offset -= icblen;
	    ad_offset = sizeof(udf_long_ad_t) * ad_num;
	    if (ad_offset > uint32_from_le(p_udf_fe->i_alloc_descs)) {
	      cdio_warn("File offset out of bounds");
	      return CDIO_INVALID_LBA;
	    }
	    p_icb = (udf_long_ad_t *) 
	      GETICB( uint32_from_le(p_udf_fe->i_extended_attr)
		      + ad_offset );
	    icblen = p_icb->len;
	    ad_num++;
	  } while(i_offset >= icblen);
	
	  lsector = (i_offset / UDF_BLOCKSIZE) +
	    uint32_from_le(((udf_long_ad_t *)(p_icb))->loc.lba);
	  
	  *pi_max_size = p_icb->len;
	}
	break;
      case ICBTAG_FLAG_AD_IN_ICB:
	/*
	 * This type means that the file *data* is stored in the
	 * allocation descriptor field of the file entry.
	 */
	*pi_max_size = 0;
	cdio_warn("Don't know how to data in ICB handle yet");
	return CDIO_INVALID_LBA;
      case ICBTAG_FLAG_AD_EXTENDED:
	cdio_warn("Don't know how to handle extended addresses yet");
	return CDIO_INVALID_LBA;
      default:
	cdio_warn("Unsupported allocation descriptor %d", addr_ilk);
	return CDIO_INVALID_LBA;
      }

      *pi_lba = (lba_t)lsector + p_udf->i_part_start;
      if (*pi_lba < 0) {
	cdio_warn("Negative LBA value");
	return CDIO_INVALID_LBA;
      }
      return *pi_lba;
    }
  default:
    cdio_warn("Unknown strategy type %d", strat_type);
    return DRIVER_OP_ERROR;
  }
}

ssize_t
udf_read_block(const udf_dirent_t *p_udf_dirent, void * buf, size_t count)
{
  if (count == 0) return 0;
  else {
    driver_return_code_t ret;
    uint32_t i_max_size=0;
    udf_t *p_udf = p_udf_dirent->p_udf;
    lba_t i_lba = offset_to_lba(p_udf_dirent, p_udf->i_position, &i_lba, 
				&i_max_size);
    if (i_lba != CDIO_INVALID_LBA) {
      uint32_t i_max_blocks = CEILING(i_max_size, UDF_BLOCKSIZE);
      if ( i_max_blocks < count ) {
	  cdio_warn("read count %u is larger than %u extent size.",
		  (unsigned int)count, i_max_blocks);
	  cdio_warn("read count truncated to %u", (unsigned int)count);
	  count = i_max_blocks;
      }
      ret = udf_read_sectors(p_udf, buf, i_lba, count);
      if (DRIVER_OP_SUCCESS == ret) {
	ssize_t i_read_len = MIN(i_max_size, count * UDF_BLOCKSIZE);
	p_udf->i_position += i_read_len;
	return i_read_len;
      }
      return ret;
    } else {
      return DRIVER_OP_ERROR;
    }
  }
}

