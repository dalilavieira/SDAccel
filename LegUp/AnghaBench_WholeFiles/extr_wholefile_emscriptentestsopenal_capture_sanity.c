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
typedef  int ALenum ;
typedef  int ALCuint ;
typedef  int ALCsizei ;
typedef  scalar_t__ ALCenum ;
typedef  int /*<<< orphan*/  ALCdevice ;
typedef  int /*<<< orphan*/  ALCboolean ;

/* Variables and functions */
 scalar_t__ ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER ; 
 scalar_t__ ALC_CAPTURE_DEVICE_SPECIFIER ; 
#define  AL_FORMAT_MONO16 131 
#define  AL_FORMAT_MONO8 130 
#define  AL_FORMAT_STEREO16 129 
#define  AL_FORMAT_STEREO8 128 
 int /*<<< orphan*/  EXIT_FAILURE ; 
 int* FORMATS ; 
 int* SAMPLE_RATES ; 
 int /*<<< orphan*/  alcCaptureCloseDevice (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * alcCaptureOpenDevice (char const*,int,int,int) ; 
 scalar_t__ alcGetError (int /*<<< orphan*/ *) ; 
 char* alcGetString (int /*<<< orphan*/ *,scalar_t__) ; 
 int countof (int*) ; 
 int /*<<< orphan*/  exit (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,char const*,...) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  result ; 
 int /*<<< orphan*/  stderr ; 
 scalar_t__ strcmp (char const*,char const*) ; 
 scalar_t__ strlen (char const*) ; 

__attribute__((used)) static void end_test() {
#ifdef __EMSCRIPTEN__
    REPORT_RESULT(result);
#endif
    exit(result);
}

__attribute__((used)) static const char* alformat_string(ALenum format) {
    switch(format) {
    #define CASE(X) case X: return #X;
    CASE(AL_FORMAT_MONO8)
    CASE(AL_FORMAT_MONO16)
    CASE(AL_FORMAT_STEREO8)
    CASE(AL_FORMAT_STEREO16)
#ifdef ASSUME_AL_FLOAT32
    CASE(AL_FORMAT_MONO_FLOAT32)
    CASE(AL_FORMAT_STEREO_FLOAT32)
#endif
    #undef CASE
    }
    return "<no_string_available>";
}

__attribute__((used)) static void check_device_sanity_with_params(const char *name, ALCuint sample_rate, ALenum format, ALCsizei buffer_size) {

    printf(
        "Testing \"%s\" @%uHz with %u sample-frames (format: %s)...\n", 
        name, (unsigned)sample_rate, (unsigned) buffer_size,
        alformat_string(format)
    );

    ALCdevice* dev = alcCaptureOpenDevice(name, sample_rate, format, buffer_size);

    if(dev) {
        const char *claimed = alcGetString(dev, ALC_CAPTURE_DEVICE_SPECIFIER);
        if(strcmp(name, claimed)) {
            fprintf(stderr, "The device \"%s\" claims to be actually named \"%s\", which is not correct behavior.\n", name, claimed);
            result = EXIT_FAILURE;
        }
        ALCboolean could_close = alcCaptureCloseDevice(dev);
        if(!could_close) {
            fprintf(stderr, "alcCaptureCloseDevice() with \"%s\" failed!\n", name);
            result = EXIT_FAILURE;
        }
        return;
    }

    ALCenum err = alcGetError(dev);
    fprintf(stderr,
        "alcCaptureOpenDevice(\"%s\", sample_rate=%u, format=%s, "
        "buffer_size=%u) failed with ALC error %x (%s)\n", 
        name, (unsigned)sample_rate, alformat_string(format), 
        (unsigned) buffer_size,
        (unsigned) err, alcGetString(NULL, err)
    );
    result = EXIT_FAILURE;
}

__attribute__((used)) static void check_device_sanity(const char *name) {
    for(int si=0 ; si<countof(SAMPLE_RATES) ; ++si) {
        for(int fi=0 ; fi<countof(FORMATS) ; ++fi) {
            // 8 seconds of data
            check_device_sanity_with_params(
                name, SAMPLE_RATES[si], FORMATS[fi], 8*SAMPLE_RATES[si]
            );
        }
    }
}

__attribute__((used)) static bool is_defaultname_in_names(const char *dft, const char *names) {
    for(const char *name = names; *name ; name += 1+strlen(name)) {
        if(!strcmp(dft, name))
            return true;
    }
    return false;
}

int main() {

    const char *dft = alcGetString(NULL, ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER);
    const char *names = alcGetString(NULL, ALC_CAPTURE_DEVICE_SPECIFIER);

    if(!is_defaultname_in_names(dft, names)) {
        printf(
            "The default device specifier (\"%s\") was not found amongst the device specifier list : ...\n"
            , dft
        );
        for(const char *name = names; *name ; name += 1+strlen(name)) {
            printf("- \"%s\";\n", name);
        }
        printf("... this is not an error, though.\n\n");
    }

    for(const char *name = names; *name ; name += 1+strlen(name)) {
        check_device_sanity(name);
    }

    end_test();
}

