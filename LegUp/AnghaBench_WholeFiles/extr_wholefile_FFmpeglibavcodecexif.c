#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  scalar_t__ uint16_t ;
typedef  enum TiffTypes { ____Placeholder_TiffTypes } TiffTypes ;
struct TYPE_3__ {scalar_t__ id; char const* name; } ;
typedef  int /*<<< orphan*/  GetByteContext ;
typedef  int /*<<< orphan*/  AVDictionary ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_INVALIDDATA ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  ENOMEM ; 
 int FF_ARRAY_ELEMS (TYPE_1__*) ; 
 int /*<<< orphan*/  SEEK_SET ; 
#define  TIFF_BYTE 138 
#define  TIFF_DOUBLE 137 
#define  TIFF_LONG 136 
#define  TIFF_RATIONAL 135 
#define  TIFF_SBYTE 134 
#define  TIFF_SHORT 133 
#define  TIFF_SLONG 132 
#define  TIFF_SRATIONAL 131 
#define  TIFF_SSHORT 130 
#define  TIFF_STRING 129 
#define  TIFF_UNDEFINED 128 
 int /*<<< orphan*/  av_freep (char**) ; 
 int /*<<< orphan*/  av_log (void*,int /*<<< orphan*/ ,char*,char const*,int) ; 
 char* av_malloc (int) ; 
 int /*<<< orphan*/  avpriv_request_sample (void*,char*,int) ; 
 int bytestream2_get_bytes_left (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  bytestream2_init (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int) ; 
 int /*<<< orphan*/  bytestream2_seek (int /*<<< orphan*/ *,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  bytestream2_tell (int /*<<< orphan*/ *) ; 
 int ff_exif_decode_ifd (void*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ **) ; 
 int ff_tadd_bytes_metadata (int,char const*,char const*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ **) ; 
 int ff_tadd_doubles_metadata (int,char const*,char const*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 
 int ff_tadd_long_metadata (int,char const*,char const*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 
 int ff_tadd_rational_metadata (int,char const*,char const*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 
 int ff_tadd_shorts_metadata (int,char const*,char const*,int /*<<< orphan*/ *,int,int,int /*<<< orphan*/ **) ; 
 int ff_tadd_string_metadata (int,char const*,int /*<<< orphan*/ *,int,int /*<<< orphan*/ **) ; 
 int ff_tget_long (int /*<<< orphan*/ *,int) ; 
 int ff_tget_short (int /*<<< orphan*/ *,int) ; 
 int ff_tis_ifd (unsigned int) ; 
 int /*<<< orphan*/  ff_tread_tag (int /*<<< orphan*/ *,int,unsigned int*,int*,unsigned int*,int*) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,unsigned int) ; 
 TYPE_1__* tag_list ; 

__attribute__((used)) static const char *exif_get_tag_name(uint16_t id)
{
    int i;

    for (i = 0; i < FF_ARRAY_ELEMS(tag_list); i++) {
        if (tag_list[i].id == id)
            return tag_list[i].name;
    }

    return NULL;
}

__attribute__((used)) static int exif_add_metadata(void *logctx, int count, int type,
                             const char *name, const char *sep,
                             GetByteContext *gb, int le,
                             AVDictionary **metadata)
{
    switch(type) {
    case 0:
        av_log(logctx, AV_LOG_WARNING,
               "Invalid TIFF tag type 0 found for %s with size %d\n",
               name, count);
        return 0;
    case TIFF_DOUBLE   : return ff_tadd_doubles_metadata(count, name, sep, gb, le, metadata);
    case TIFF_SSHORT   : return ff_tadd_shorts_metadata(count, name, sep, gb, le, 1, metadata);
    case TIFF_SHORT    : return ff_tadd_shorts_metadata(count, name, sep, gb, le, 0, metadata);
    case TIFF_SBYTE    : return ff_tadd_bytes_metadata(count, name, sep, gb, le, 1, metadata);
    case TIFF_BYTE     :
    case TIFF_UNDEFINED: return ff_tadd_bytes_metadata(count, name, sep, gb, le, 0, metadata);
    case TIFF_STRING   : return ff_tadd_string_metadata(count, name, gb, le, metadata);
    case TIFF_SRATIONAL:
    case TIFF_RATIONAL : return ff_tadd_rational_metadata(count, name, sep, gb, le, metadata);
    case TIFF_SLONG    :
    case TIFF_LONG     : return ff_tadd_long_metadata(count, name, sep, gb, le, metadata);
    default:
        avpriv_request_sample(logctx, "TIFF tag type (%u)", type);
        return 0;
    };
}

__attribute__((used)) static int exif_decode_tag(void *logctx, GetByteContext *gbytes, int le,
                           int depth, AVDictionary **metadata)
{
    int ret, cur_pos;
    unsigned id, count;
    enum TiffTypes type;

    if (depth > 2) {
        return 0;
    }

    ff_tread_tag(gbytes, le, &id, &type, &count, &cur_pos);

    if (!bytestream2_tell(gbytes)) {
        bytestream2_seek(gbytes, cur_pos, SEEK_SET);
        return 0;
    }

    // read count values and add it metadata
    // store metadata or proceed with next IFD
    ret = ff_tis_ifd(id);
    if (ret) {
        ret = ff_exif_decode_ifd(logctx, gbytes, le, depth + 1, metadata);
    } else {
        const char *name = exif_get_tag_name(id);
        char *use_name   = (char*) name;

        if (!use_name) {
            use_name = av_malloc(7);
            if (!use_name) {
                return AVERROR(ENOMEM);
            }
            snprintf(use_name, 7, "0x%04X", id);
        }

        ret = exif_add_metadata(logctx, count, type, use_name, NULL,
                                gbytes, le, metadata);

        if (!name) {
            av_freep(&use_name);
        }
    }

    bytestream2_seek(gbytes, cur_pos, SEEK_SET);

    return ret;
}

int ff_exif_decode_ifd(void *logctx, GetByteContext *gbytes,
                       int le, int depth, AVDictionary **metadata)
{
    int i, ret;
    int entries;

    entries = ff_tget_short(gbytes, le);

    if (bytestream2_get_bytes_left(gbytes) < entries * 12) {
        return AVERROR_INVALIDDATA;
    }

    for (i = 0; i < entries; i++) {
        if ((ret = exif_decode_tag(logctx, gbytes, le, depth, metadata)) < 0) {
            return ret;
        }
    }

    // return next IDF offset or 0x000000000 or a value < 0 for failure
    return ff_tget_long(gbytes, le);
}

int avpriv_exif_decode_ifd(void *logctx, const uint8_t *buf, int size,
                           int le, int depth, AVDictionary **metadata)
{
    GetByteContext gb;

    bytestream2_init(&gb, buf, size);

    return ff_exif_decode_ifd(logctx, &gb, le, depth, metadata);
}

