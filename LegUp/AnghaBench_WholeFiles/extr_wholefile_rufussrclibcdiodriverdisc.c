#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  lsn_t ;
typedef  int discmode_t ;
typedef  int /*<<< orphan*/  cdtext_t ;
struct TYPE_10__ {int /*<<< orphan*/ * (* get_cdtext_raw ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/ * (* get_cdtext ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_13__ {int /*<<< orphan*/  env; TYPE_1__ op; } ;
struct TYPE_11__ {int (* get_discmode ) (int /*<<< orphan*/ ) ;char* (* get_mcn ) (int /*<<< orphan*/ ) ;int /*<<< orphan*/  (* get_disc_last_lsn ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_12__ {int /*<<< orphan*/  env; TYPE_2__ op; } ;
typedef  TYPE_3__ CdIo_t ;
typedef  TYPE_4__ CdIo ;

/* Variables and functions */
#define  CDIO_DISC_MODE_CD_DA 139 
#define  CDIO_DISC_MODE_CD_DATA 138 
#define  CDIO_DISC_MODE_CD_MIXED 137 
#define  CDIO_DISC_MODE_CD_XA 136 
#define  CDIO_DISC_MODE_DVD_OTHER 135 
#define  CDIO_DISC_MODE_DVD_PR 134 
#define  CDIO_DISC_MODE_DVD_PRW 133 
#define  CDIO_DISC_MODE_DVD_R 132 
#define  CDIO_DISC_MODE_DVD_RAM 131 
#define  CDIO_DISC_MODE_DVD_ROM 130 
#define  CDIO_DISC_MODE_DVD_RW 129 
 int CDIO_DISC_MODE_ERROR ; 
#define  CDIO_DISC_MODE_NO_INFO 128 
 int /*<<< orphan*/  CDIO_INVALID_LSN ; 
 scalar_t__ malloc (size_t) ; 
 size_t strlen (char const*) ; 
 scalar_t__ strncpy (char*,char const*,size_t) ; 
 int /*<<< orphan*/ * stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * stub2 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  stub3 (int /*<<< orphan*/ ) ; 
 int stub4 (int /*<<< orphan*/ ) ; 
 char* stub5 (int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline char *libcdio_strndup(const char *s, size_t n)
{
    char *result;
    size_t len = strlen (s);
    if (n < len)
        len = n;
    result = (char *) malloc (len + 1);
    if (!result)
        return 0;
    result[len] = '\0';
    return (char *) strncpy (result, s, len);
}

cdtext_t *
cdio_get_cdtext (CdIo *obj)
{
  if (obj == NULL) return NULL;
  
  if (NULL != obj->op.get_cdtext) {
    return obj->op.get_cdtext (obj->env);
  } else {
    return NULL;
  }
}

uint8_t *
cdio_get_cdtext_raw (CdIo *obj)
{
  if (obj == NULL) return NULL;

  if (NULL != obj->op.get_cdtext_raw) {
    return obj->op.get_cdtext_raw (obj->env);
  } else {
    return NULL;
  }
}

lsn_t 
cdio_get_disc_last_lsn(const CdIo_t *p_cdio)
{
  if (!p_cdio) return CDIO_INVALID_LSN;
  return p_cdio->op.get_disc_last_lsn (p_cdio->env);
}

discmode_t
cdio_get_discmode (CdIo_t *cd_obj)
{
  if (!cd_obj) return CDIO_DISC_MODE_ERROR;
  
  if (cd_obj->op.get_discmode) {
    return cd_obj->op.get_discmode (cd_obj->env);
  } else {
    return CDIO_DISC_MODE_NO_INFO;
  }
}

char *
cdio_get_mcn (const CdIo_t *p_cdio) 
{
  if (p_cdio && p_cdio->op.get_mcn) {
    return p_cdio->op.get_mcn (p_cdio->env);
  } else {
    return NULL;
  }
}

bool
cdio_is_discmode_cdrom(discmode_t discmode) 
{
  switch (discmode) {
  case CDIO_DISC_MODE_CD_DA:
  case CDIO_DISC_MODE_CD_DATA:
  case CDIO_DISC_MODE_CD_XA:
  case CDIO_DISC_MODE_CD_MIXED:
  case CDIO_DISC_MODE_NO_INFO:
    return true;
  default:
    return false;
  }
}

bool
cdio_is_discmode_dvd(discmode_t discmode) 
{
  switch (discmode) {
    case CDIO_DISC_MODE_DVD_ROM:
    case CDIO_DISC_MODE_DVD_RAM:
    case CDIO_DISC_MODE_DVD_R:
    case CDIO_DISC_MODE_DVD_RW:
    case CDIO_DISC_MODE_DVD_PR:
    case CDIO_DISC_MODE_DVD_PRW:
    case CDIO_DISC_MODE_DVD_OTHER:
      return true;
    default:
      return false;
  }
}

