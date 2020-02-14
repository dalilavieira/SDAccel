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
typedef  int /*<<< orphan*/  ext ;
typedef  int MMImageType ;
typedef  int /*<<< orphan*/  MMIOError ;
typedef  int /*<<< orphan*/ * MMBitmapRef ;

/* Variables and functions */
 char const* MMBMPReadErrorString (int /*<<< orphan*/ ) ; 
 char const* MMPNGReadErrorString (int /*<<< orphan*/ ) ; 
#define  kBMPImageType 129 
 int kInvalidImageType ; 
 int /*<<< orphan*/  kMMIOUnsupportedTypeError ; 
#define  kPNGImageType 128 
 int /*<<< orphan*/ * newMMBitmapFromBMP (char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * newMMBitmapFromPNG (char const*,int /*<<< orphan*/ *) ; 
 int saveMMBitmapAsBMP (int /*<<< orphan*/ *,char const*) ; 
 int saveMMBitmapAsPNG (int /*<<< orphan*/ *,char const*) ; 
 scalar_t__ strcmp (char*,char*) ; 
 char tolower (char const) ; 

const char *getExtension(const char *fname, size_t len)
{
	if (fname == NULL || len <= 0) return NULL;

	while (--len > 0 && fname[len] != '.' && fname[len] != '\0')
		;

	return fname + len + 1;
}

MMImageType imageTypeFromExtension(const char *extension)
{
	char ext[4];
	const size_t maxlen = sizeof(ext) / sizeof(ext[0]);
	size_t i;

	for (i = 0; extension[i] != '\0'; ++i) {
		if (i >= maxlen) return kInvalidImageType;
		ext[i] = tolower(extension[i]);
	}
	ext[i] = '\0';

	if (strcmp(ext, "png") == 0) {
		return kPNGImageType;
	} else if (strcmp(ext, "bmp") == 0) {
		return kBMPImageType;
	} else {
		return kInvalidImageType;
	}
}

MMBitmapRef newMMBitmapFromFile(const char *path, 
                                MMImageType type,
                                MMIOError *err)
{
	switch (type) {
		case kBMPImageType:
			return newMMBitmapFromBMP(path, err);
		case kPNGImageType:
			return newMMBitmapFromPNG(path, err);
		default:
			if (err != NULL) *err = kMMIOUnsupportedTypeError;
			return NULL;
	}
}

int saveMMBitmapToFile(MMBitmapRef bitmap,
                       const char *path,
                       MMImageType type)
{
	switch (type) {
		case kBMPImageType:
			return saveMMBitmapAsBMP(bitmap, path);
		case kPNGImageType:
			return saveMMBitmapAsPNG(bitmap, path);
		default:
			return -1;
	}
}

const char *MMIOErrorString(MMImageType type, MMIOError error)
{
	switch (type) {
		case kBMPImageType:
			return MMBMPReadErrorString(error);
		case kPNGImageType:
			return MMPNGReadErrorString(error);
		default:
			return "Unsupported image type";
	}
}

