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
typedef  int /*<<< orphan*/  u8 ;
typedef  int /*<<< orphan*/  dictionary_t ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 size_t MAX_COMPRESSION_RATIO ; 
 size_t MAX_OUTPUT_SIZE ; 
 int /*<<< orphan*/  SEEK_END ; 
 size_t ZSTD_decompress_with_dict (int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/ * const) ; 
 size_t ZSTD_get_decompressed_size (int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/ * create_dictionary () ; 
 int /*<<< orphan*/ * dict ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fclose (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  feof (int /*<<< orphan*/ *) ; 
 scalar_t__ ferror (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * fopen (char const*,char*) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*,...) ; 
 size_t fread (int /*<<< orphan*/ *,int,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  free_dictionary (int /*<<< orphan*/ * const) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ *,long,int /*<<< orphan*/ ) ; 
 size_t ftell (int /*<<< orphan*/ *) ; 
 scalar_t__ fwrite (int /*<<< orphan*/  const*,int,size_t,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * input ; 
 void* malloc (size_t) ; 
 int /*<<< orphan*/ * output ; 
 int /*<<< orphan*/  parse_dictionary (int /*<<< orphan*/ * const,int /*<<< orphan*/ *,size_t) ; 
 int /*<<< orphan*/  rewind (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  stderr ; 

size_t read_file(const char *path, u8 **ptr) {
    FILE *f = fopen(path, "rb");
    if (!f) {
        fprintf(stderr, "failed to open file %s\n", path);
        exit(1);
    }

    fseek(f, 0L, SEEK_END);
    size_t size = ftell(f);
    rewind(f);

    *ptr = malloc(size);
    if (!ptr) {
        fprintf(stderr, "failed to allocate memory to hold %s\n", path);
        exit(1);
    }

    size_t pos = 0;
    while (!feof(f)) {
        size_t read = fread(&(*ptr)[pos], 1, size, f);
        if (ferror(f)) {
            fprintf(stderr, "error while reading file %s\n", path);
            exit(1);
        }
        pos += read;
    }

    fclose(f);

    return pos;
}

void write_file(const char *path, const u8 *ptr, size_t size) {
    FILE *f = fopen(path, "wb");

    size_t written = 0;
    while (written < size) {
        written += fwrite(&ptr[written], 1, size, f);
        if (ferror(f)) {
            fprintf(stderr, "error while writing file %s\n", path);
            exit(1);
        }
    }

    fclose(f);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "usage: %s <file.zst> <out_path> [dictionary]\n",
                argv[0]);

        return 1;
    }

    size_t input_size = read_file(argv[1], &input);
    size_t dict_size = 0;
    if (argc >= 4) {
        dict_size = read_file(argv[3], &dict);
    }

    size_t decompressed_size = ZSTD_get_decompressed_size(input, input_size);
    if (decompressed_size == (size_t)-1) {
        decompressed_size = MAX_COMPRESSION_RATIO * input_size;
        fprintf(stderr, "WARNING: Compressed data does not contain "
                        "decompressed size, going to assume the compression "
                        "ratio is at most %d (decompressed size of at most "
                        "%zu)\n",
                MAX_COMPRESSION_RATIO, decompressed_size);
    }
    if (decompressed_size > MAX_OUTPUT_SIZE) {
        fprintf(stderr,
                "Required output size too large for this implementation\n");
        return 1;
    }
    output = malloc(decompressed_size);
    if (!output) {
        fprintf(stderr, "failed to allocate memory\n");
        return 1;
    }

    dictionary_t* const parsed_dict = create_dictionary();
    if (dict) {
        parse_dictionary(parsed_dict, dict, dict_size);
    }
    size_t decompressed =
        ZSTD_decompress_with_dict(output, decompressed_size,
                                  input, input_size, parsed_dict);

    free_dictionary(parsed_dict);

    write_file(argv[2], output, decompressed);

    free(input);
    free(output);
    free(dict);
    input = output = dict = NULL;
}

