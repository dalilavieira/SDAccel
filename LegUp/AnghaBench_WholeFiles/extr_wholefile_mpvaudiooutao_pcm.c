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
typedef  int uint8_t ;
typedef  int uint64_t ;
typedef  int uint32_t ;
typedef  int uint16_t ;
struct priv {int data_length; int /*<<< orphan*/ * fp; scalar_t__ waveheader; scalar_t__ outputfilename; scalar_t__ append; } ;
struct mp_chmap_sel {int /*<<< orphan*/  member_0; } ;
struct TYPE_3__ {int num; } ;
struct ao {scalar_t__ format; int samplerate; int bps; int untimed; int sstride; struct priv* priv; TYPE_1__ channels; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
#define  AF_FORMAT_FLOAT 131 
#define  AF_FORMAT_S16 130 
#define  AF_FORMAT_S32 129 
#define  AF_FORMAT_U8 128 
 scalar_t__ BIG_ENDIAN ; 
 scalar_t__ BYTE_ORDER ; 
 int /*<<< orphan*/  MP_ERR (struct ao*,char*,...) ; 
 int /*<<< orphan*/  MP_FATAL (struct ao*,char*) ; 
 int /*<<< orphan*/  MP_INFO (struct ao*,char*,scalar_t__,char*,int,int,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SEEK_SET ; 
 int WAV_ID_DATA ; 
 int WAV_ID_FLOAT_PCM ; 
 int WAV_ID_FMT ; 
 int WAV_ID_FORMAT_EXTENSIBLE ; 
 int WAV_ID_PCM ; 
 int WAV_ID_RIFF ; 
 int WAV_ID_WAVE ; 
 scalar_t__ af_fmt_from_planar (scalar_t__) ; 
 int /*<<< orphan*/  af_fmt_is_spdif (int) ; 
 int af_fmt_to_bytes (scalar_t__) ; 
 int /*<<< orphan*/  af_fmt_to_str (scalar_t__) ; 
 int /*<<< orphan*/  ao_chmap_sel_adjust (struct ao*,struct mp_chmap_sel*,TYPE_1__*) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (scalar_t__,char*) ; 
 scalar_t__ fseek (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fwrite (void*,int,int,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mp_chmap_sel_add_waveext (struct mp_chmap_sel*) ; 
 int mp_chmap_to_waveext (TYPE_1__*) ; 
 scalar_t__ talloc_strdup (struct priv*,char*) ; 

__attribute__((used)) static void fput16le(uint16_t val, FILE *fp)
{
    uint8_t bytes[2] = {val, val >> 8};
    fwrite(bytes, 1, 2, fp);
}

__attribute__((used)) static void fput32le(uint32_t val, FILE *fp)
{
    uint8_t bytes[4] = {val, val >> 8, val >> 16, val >> 24};
    fwrite(bytes, 1, 4, fp);
}

__attribute__((used)) static void write_wave_header(struct ao *ao, FILE *fp, uint64_t data_length)
{
    uint16_t fmt = ao->format == AF_FORMAT_FLOAT ? WAV_ID_FLOAT_PCM : WAV_ID_PCM;
    int bits = af_fmt_to_bytes(ao->format) * 8;

    // Master RIFF chunk
    fput32le(WAV_ID_RIFF, fp);
    // RIFF chunk size: 'WAVE' + 'fmt ' + 4 + 40 +
    // data chunk hdr (8) + data length
    fput32le(12 + 40 + 8 + data_length, fp);
    fput32le(WAV_ID_WAVE, fp);

    // Format chunk
    fput32le(WAV_ID_FMT, fp);
    fput32le(40, fp);
    fput16le(WAV_ID_FORMAT_EXTENSIBLE, fp);
    fput16le(ao->channels.num, fp);
    fput32le(ao->samplerate, fp);
    fput32le(ao->bps, fp);
    fput16le(ao->channels.num * (bits / 8), fp);
    fput16le(bits, fp);

    // Extension chunk
    fput16le(22, fp);
    fput16le(bits, fp);
    fput32le(mp_chmap_to_waveext(&ao->channels), fp);
    // 2 bytes format + 14 bytes guid
    fput32le(fmt, fp);
    fput32le(0x00100000, fp);
    fput32le(0xAA000080, fp);
    fput32le(0x719B3800, fp);

    // Data chunk
    fput32le(WAV_ID_DATA, fp);
    fput32le(data_length, fp);
}

__attribute__((used)) static int init(struct ao *ao)
{
    struct priv *priv = ao->priv;

    if (!priv->outputfilename)
        priv->outputfilename =
            talloc_strdup(priv, priv->waveheader ? "audiodump.wav" : "audiodump.pcm");

    ao->format = af_fmt_from_planar(ao->format);

    if (priv->waveheader) {
        // WAV files must have one of the following formats

        // And they don't work in big endian; fixing it would be simple, but
        // nobody cares.
        if (BYTE_ORDER == BIG_ENDIAN) {
            MP_FATAL(ao, "Not supported on big endian.\n");
            return -1;
        }

        switch (ao->format) {
        case AF_FORMAT_U8:
        case AF_FORMAT_S16:
        case AF_FORMAT_S32:
        case AF_FORMAT_FLOAT:
             break;
        default:
            if (!af_fmt_is_spdif(ao->format))
                ao->format = AF_FORMAT_S16;
            break;
        }
    }

    struct mp_chmap_sel sel = {0};
    mp_chmap_sel_add_waveext(&sel);
    if (!ao_chmap_sel_adjust(ao, &sel, &ao->channels))
        return -1;

    ao->bps = ao->channels.num * ao->samplerate * af_fmt_to_bytes(ao->format);

    MP_INFO(ao, "File: %s (%s)\nPCM: Samplerate: %d Hz Channels: %d Format: %s\n",
            priv->outputfilename,
            priv->waveheader ? "WAVE" : "RAW PCM", ao->samplerate,
            ao->channels.num, af_fmt_to_str(ao->format));

    priv->fp = fopen(priv->outputfilename, priv->append ? "ab" : "wb");
    if (!priv->fp) {
        MP_ERR(ao, "Failed to open %s for writing!\n", priv->outputfilename);
        return -1;
    }
    if (priv->waveheader)  // Reserve space for wave header
        write_wave_header(ao, priv->fp, 0x7ffff000);
    ao->untimed = true;

    return 0;
}

__attribute__((used)) static void uninit(struct ao *ao)
{
    struct priv *priv = ao->priv;

    if (priv->waveheader) {    // Rewrite wave header
        bool broken_seek = false;
#ifdef __MINGW32__
        // Windows, in its usual idiocy "emulates" seeks on pipes so it always
        // looks like they work. So we have to detect them brute-force.
        broken_seek = FILE_TYPE_DISK !=
            GetFileType((HANDLE)_get_osfhandle(_fileno(priv->fp)));
#endif
        if (broken_seek || fseek(priv->fp, 0, SEEK_SET) != 0)
            MP_ERR(ao, "Could not seek to start, WAV size headers not updated!\n");
        else {
            if (priv->data_length > 0xfffff000) {
                MP_ERR(ao, "File larger than allowed for "
                       "WAV files, may play truncated!\n");
                priv->data_length = 0xfffff000;
            }
            write_wave_header(ao, priv->fp, priv->data_length);
        }
    }
    fclose(priv->fp);
}

__attribute__((used)) static int get_space(struct ao *ao)
{
    return 65536;
}

__attribute__((used)) static int play(struct ao *ao, void **data, int samples, int flags)
{
    struct priv *priv = ao->priv;
    int len = samples * ao->sstride;

    fwrite(data[0], len, 1, priv->fp);
    priv->data_length += len;
    return samples;
}

