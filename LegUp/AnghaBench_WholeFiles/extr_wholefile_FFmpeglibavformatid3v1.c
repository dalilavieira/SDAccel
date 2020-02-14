#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_5__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  char uint8_t ;
typedef  int /*<<< orphan*/  str ;
typedef  int int64_t ;
struct TYPE_10__ {int seekable; } ;
struct TYPE_9__ {TYPE_5__* pb; int /*<<< orphan*/  metadata; } ;
typedef  TYPE_1__ AVFormatContext ;

/* Variables and functions */
 int AVIO_SEEKABLE_NORMAL ; 
 int ID3v1_GENRE_MAX ; 
 int ID3v1_TAG_SIZE ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int /*<<< orphan*/  av_dict_set (int /*<<< orphan*/ *,char const*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  av_dict_set_int (int /*<<< orphan*/ *,char*,char const,int /*<<< orphan*/ ) ; 
 int avio_read (TYPE_5__*,char*,int) ; 
 int /*<<< orphan*/  avio_seek (TYPE_5__*,int,int /*<<< orphan*/ ) ; 
 int avio_size (TYPE_5__*) ; 
 int avio_tell (TYPE_5__*) ; 
 char** ff_id3v1_genre_str ; 

__attribute__((used)) static void get_string(AVFormatContext *s, const char *key,
                       const uint8_t *buf, int buf_size)
{
    int i, c;
    char *q, str[512], *first_free_space = NULL;

    q = str;
    for(i = 0; i < buf_size; i++) {
        c = buf[i];
        if (c == '\0')
            break;
        if ((q - str) >= sizeof(str) - 1)
            break;
        if (c == ' ') {
            if (!first_free_space)
                first_free_space = q;
        } else {
            first_free_space = NULL;
        }
        *q++ = c;
    }
    *q = '\0';

    if (first_free_space)
        *first_free_space = '\0';

    if (*str)
        av_dict_set(&s->metadata, key, str, 0);
}

__attribute__((used)) static int parse_tag(AVFormatContext *s, const uint8_t *buf)
{
    int genre;

    if (!(buf[0] == 'T' &&
          buf[1] == 'A' &&
          buf[2] == 'G'))
        return -1;
    get_string(s, "title",   buf +  3, 30);
    get_string(s, "artist",  buf + 33, 30);
    get_string(s, "album",   buf + 63, 30);
    get_string(s, "date",    buf + 93,  4);
    get_string(s, "comment", buf + 97, 30);
    if (buf[125] == 0 && buf[126] != 0) {
        av_dict_set_int(&s->metadata, "track", buf[126], 0);
    }
    genre = buf[127];
    if (genre <= ID3v1_GENRE_MAX)
        av_dict_set(&s->metadata, "genre", ff_id3v1_genre_str[genre], 0);
    return 0;
}

void ff_id3v1_read(AVFormatContext *s)
{
    int ret;
    uint8_t buf[ID3v1_TAG_SIZE];
    int64_t filesize, position = avio_tell(s->pb);

    if (s->pb->seekable & AVIO_SEEKABLE_NORMAL) {
        /* XXX: change that */
        filesize = avio_size(s->pb);
        if (filesize > 128) {
            avio_seek(s->pb, filesize - 128, SEEK_SET);
            ret = avio_read(s->pb, buf, ID3v1_TAG_SIZE);
            if (ret == ID3v1_TAG_SIZE) {
                parse_tag(s, buf);
            }
            avio_seek(s->pb, position, SEEK_SET);
        }
    }
}

