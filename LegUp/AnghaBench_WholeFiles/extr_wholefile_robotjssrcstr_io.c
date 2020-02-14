#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  char uint8_t ;
typedef  size_t uint32_t ;
struct TYPE_10__ {size_t width; size_t height; } ;
struct TYPE_9__ {char blue; char green; char red; } ;
typedef  TYPE_1__ MMRGBColor ;
typedef  TYPE_2__* MMBitmapRef ;
typedef  int MMBMPStringError ;

/* Variables and functions */
 int MAX_DIMENSION_LEN ; 
#define  MMMBMPStringEncodeError 133 
 TYPE_1__* MMRGBColorRefAtPoint (TYPE_2__*,size_t,size_t) ; 
 int /*<<< orphan*/  STR_BITS_PER_PIXEL ; 
 size_t STR_BYTES_PER_PIXEL ; 
 int /*<<< orphan*/  assert (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  atoi (char*) ; 
 char* base64decode (char const*,size_t,int /*<<< orphan*/ *) ; 
 char* base64encode (char*,size_t,size_t*) ; 
 char* calloc (size_t,size_t) ; 
 TYPE_2__* createMMBitmap (char*,size_t,size_t,size_t,int /*<<< orphan*/ ,size_t) ; 
static  char* createRawBitmapData (TYPE_2__*) ; 
 int /*<<< orphan*/  free (char*) ; 
static  int getSizeFromString (char const*,size_t,size_t*,size_t*,size_t*) ; 
 int /*<<< orphan*/  isdigit (char const) ; 
#define  kMMBMPStringCompressError 132 
#define  kMMBMPStringDecodeError 131 
#define  kMMBMPStringDecompressError 130 
 int kMMBMPStringGenericError ; 
#define  kMMBMPStringInvalidHeaderError 129 
#define  kMMBMPStringSizeError 128 
 int /*<<< orphan*/ * len ; 
static  size_t parseDimension (char const*,size_t,size_t*) ; 
 int /*<<< orphan*/  snprintf (char*,size_t,char*,unsigned long,unsigned long,char*) ; 
 char* zlib_compress (char*,size_t,int,size_t*) ; 
 char* zlib_decompress (char*,size_t*) ; 

const char *MMBitmapStringErrorString(MMBMPStringError err)
{
	switch (err) {
		case kMMBMPStringInvalidHeaderError:
			return "Invalid header for string";
		case kMMBMPStringDecodeError:
			return "Error decoding string";
		case kMMBMPStringDecompressError:
			return "Error decompressing string";
		case kMMBMPStringSizeError:
			return "String not of expected size";
		case MMMBMPStringEncodeError:
			return "Error encoding string";
		case kMMBMPStringCompressError:
			return "Error compressing string";
		default:
			return NULL;
	}
}

MMBitmapRef createMMBitmapFromString(const uint8_t *buffer, size_t buflen,
                                     MMBMPStringError *err)
{
	uint8_t *decoded, *decompressed;
	size_t width, height;
	size_t len, bytewidth;

	if (*buffer++ != 'b' || !getSizeFromString(buffer, --buflen,
	                                           &width, &height, &len)) {
		if (err != NULL) *err = kMMBMPStringInvalidHeaderError;
		return NULL;
	}
	buffer += len;
	buflen -= len;

	decoded = base64decode(buffer, buflen, NULL);
	if (decoded == NULL) {
		if (err != NULL) *err = kMMBMPStringDecodeError;
		return NULL;
	}

	decompressed = zlib_decompress(decoded, &len);
	free(decoded);

	if (decompressed == NULL) {
		if (err != NULL) *err = kMMBMPStringDecompressError;
		return NULL;
	}

	bytewidth = width * STR_BYTES_PER_PIXEL; /* Note that bytewidth is NOT
	                                          * aligned to a padding. */
	if (height * bytewidth != len) {
		if (err != NULL) *err = kMMBMPStringSizeError;
		return NULL;
	}

	return createMMBitmap(decompressed, width, height,
	                      bytewidth, STR_BITS_PER_PIXEL, STR_BYTES_PER_PIXEL);
}

uint8_t *createStringFromMMBitmap(MMBitmapRef bitmap, MMBMPStringError *err)
{
	uint8_t *raw, *compressed;
	uint8_t *ret, *encoded;
	size_t len, retlen;

	assert(bitmap != NULL);

	raw = createRawBitmapData(bitmap);
	if (raw == NULL) {
		if (err != NULL) *err = kMMBMPStringGenericError;
		return NULL;
	}

	compressed = zlib_compress(raw,
	                           bitmap->width * bitmap->height *
	                           STR_BYTES_PER_PIXEL,
	                           9, &len);
	free(raw);
	if (compressed == NULL) {
		if (err != NULL) *err = kMMBMPStringCompressError;
		return NULL;
	}

	encoded = base64encode(compressed, len - 1, &retlen);
	free(compressed);
	if (encoded == NULL) {
		if (err != NULL) *err = MMMBMPStringEncodeError;
		return NULL;
	}

	retlen += 3 + (MAX_DIMENSION_LEN * 2);
	ret = calloc(sizeof(char), (retlen + 1));
	snprintf((char *)ret, retlen, "b%lu,%lu,%s", (unsigned long)bitmap->width,
	                                             (unsigned long)bitmap->height,
												 encoded);
	ret[retlen] = '\0';
	free(encoded);
	return ret;
}

__attribute__((used)) static bool getSizeFromString(const uint8_t *buf, size_t buflen,
                              size_t *width, size_t *height,
                              size_t *len)
{
	size_t numlen;
	assert(buf != NULL);
	assert(width != NULL);
	assert(height != NULL);

	if ((*width = parseDimension(buf, buflen, &numlen)) == 0) {
		return false;
	}
	*len = numlen + 1;

	if ((*height = parseDimension(buf + *len, buflen, &numlen)) == 0) {
		return false;
	}
	*len += numlen + 1;

	return true;
}

__attribute__((used)) static uint32_t parseDimension(const uint8_t *buf, size_t buflen,
                               size_t *numlen)
{
	char num[MAX_DIMENSION_LEN + 1];
	size_t i;

	assert(buf != NULL);
	assert(len != NULL);
	for (i = 0; i < buflen && buf[i] != ',' && buf[i] != '\0'; ++i) {
		if (!isdigit(buf[i]) || i > MAX_DIMENSION_LEN) return 0;
		num[i] = buf[i];
	}
	num[i] = '\0';
	*numlen = i;

	return (uint32_t)atoi(num);
}

__attribute__((used)) static uint8_t *createRawBitmapData(MMBitmapRef bitmap)
{
	uint8_t *raw = calloc(STR_BYTES_PER_PIXEL, bitmap->width * bitmap->height);
	size_t y;

	for (y = 0; y < bitmap->height; ++y) {
		/* No padding is added to string bitmaps. */
		const size_t rowOffset = y * bitmap->width * STR_BYTES_PER_PIXEL;
		size_t x;
		for (x = 0; x < bitmap->width; ++x) {
			/* Copy in BGR format. */
			const size_t colOffset = x * STR_BYTES_PER_PIXEL;
			uint8_t *dest = raw + rowOffset + colOffset;
			MMRGBColor *srcColor = MMRGBColorRefAtPoint(bitmap, x, y);
			dest[0] = srcColor->blue;
			dest[1] = srcColor->green;
			dest[2] = srcColor->red;
		}
	}

	return raw;
}

