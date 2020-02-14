#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_8__ ;
typedef  struct TYPE_11__   TYPE_7__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
struct TYPE_9__ {char* start; unsigned char* pointer; } ;
struct TYPE_10__ {scalar_t__ error; int problem_value; char* problem; int problem_offset; int unread; int eof; TYPE_1__ buffer; } ;
typedef  TYPE_2__ yaml_parser_t ;
struct TYPE_12__ {char* test; char* title; int result; } ;
struct TYPE_11__ {char* test; char* title; int result; } ;

/* Variables and functions */
 int LONG ; 
 scalar_t__ YAML_READER_ERROR ; 
 int /*<<< orphan*/  assert (unsigned char*) ; 
 char* bom_original ; 
 TYPE_8__* boms ; 
 int /*<<< orphan*/  free (unsigned char*) ; 
 unsigned char* malloc (int) ; 
 scalar_t__ memcmp (char*,char*,int) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 TYPE_7__* utf8_sequences ; 
 int /*<<< orphan*/  yaml_parser_delete (TYPE_2__*) ; 
 int /*<<< orphan*/  yaml_parser_initialize (TYPE_2__*) ; 
 int /*<<< orphan*/  yaml_parser_set_input_string (TYPE_2__*,unsigned char*,int) ; 
 int yaml_parser_update_buffer (TYPE_2__*,int) ; 

int check_utf8_sequences(void)
{
    yaml_parser_t parser;
    int failed = 0;
    int k;
    printf("checking utf-8 sequences...\n");
    for (k = 0; utf8_sequences[k].test; k++) {
        char *title = utf8_sequences[k].title;
        int check = utf8_sequences[k].result;
        int result;
        char *start = utf8_sequences[k].test;
        char *end = start;
        printf("\t%s:\n", title);
        while(1) {
            while (*end != '|' && *end != '!') end++;
            yaml_parser_initialize(&parser);
            yaml_parser_set_input_string(&parser, (unsigned char *)start, end-start);
            result = yaml_parser_update_buffer(&parser, end-start);
            if (result != check) {
                printf("\t\t- ");
                failed ++;
            }
            else {
                printf("\t\t+ ");
            }
            if (!parser.error) {
                printf("(no error)\n");
            }
            else if (parser.error == YAML_READER_ERROR) {
                if (parser.problem_value != -1) {
                    printf("(reader error: %s: #%X at %d)\n",
                            parser.problem, parser.problem_value, parser.problem_offset);
                }
                else {
                    printf("(reader error: %s at %d)\n",
                            parser.problem, parser.problem_offset);
                }
            }
            if (*end == '!') break;
            start = ++end;
            yaml_parser_delete(&parser);
        };
        printf("\n");
    }
    printf("checking utf-8 sequences: %d fail(s)\n", failed);
    return failed;
}

int check_boms(void)
{
    yaml_parser_t parser;
    int failed = 0;
    int k;
    printf("checking boms...\n");
    for (k = 0; boms[k].test; k++) {
        char *title = boms[k].title;
        int check = boms[k].result;
        int result;
        char *start = boms[k].test;
        char *end = start;
        while (*end != '!') end++;
        printf("\t%s: ", title);
        yaml_parser_initialize(&parser);
        yaml_parser_set_input_string(&parser, (unsigned char *)start, end-start);
        result = yaml_parser_update_buffer(&parser, end-start);
        if (!result) {
            printf("- (reader error: %s at %d)\n", parser.problem, parser.problem_offset);
            failed++;
        }
        else {
            if (parser.unread != check) {
                printf("- (length=%d while expected length=%d)\n", parser.unread, check);
                failed++;
            }
            else if (memcmp(parser.buffer.start, bom_original, check) != 0) {
                printf("- (value '%s' does not equal to the original value '%s')\n", parser.buffer.start, bom_original);
                failed++;
            }
            else {
                printf("+\n");
            }
        }
        yaml_parser_delete(&parser);
    }
    printf("checking boms: %d fail(s)\n", failed);
    return failed;
}

int check_long_utf8(void)
{
    yaml_parser_t parser;
    int k = 0;
    int j;
    int failed = 0;
    unsigned char ch0, ch1;
    unsigned char *buffer = malloc(3+LONG*2);
    assert(buffer);
    printf("checking a long utf8 sequence...\n");
    buffer[k++] = '\xef';
    buffer[k++] = '\xbb';
    buffer[k++] = '\xbf';
    for (j = 0; j < LONG; j ++) {
        if (j % 2) {
            buffer[k++] = '\xd0';
            buffer[k++] = '\x90';
        }
        else {
            buffer[k++] = '\xd0';
            buffer[k++] = '\xaf';
        }
    }
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_string(&parser, buffer, 3+LONG*2);
    for (k = 0; k < LONG; k++) {
        if (!parser.unread) {
            if (!yaml_parser_update_buffer(&parser, 1)) {
                printf("\treader error: %s at %d\n", parser.problem, parser.problem_offset);
                failed = 1;
                break;
            }
        }
        if (!parser.unread) {
            printf("\tnot enough characters at %d\n", k);
            failed = 1;
            break;
        }
        if (k % 2) {
            ch0 = '\xd0';
            ch1 = '\x90';
        }
        else {
            ch0 = '\xd0';
            ch1 = '\xaf';
        }
        if (parser.buffer.pointer[0] != ch0 || parser.buffer.pointer[1] != ch1) {
            printf("\tincorrect UTF-8 sequence: %X %X instead of %X %X\n",
                    (int)parser.buffer.pointer[0], (int)parser.buffer.pointer[1],
                    (int)ch0, (int)ch1);
            failed = 1;
            break;
        }
        parser.buffer.pointer += 2;
        parser.unread -= 1;
    }
    if (!failed) {
        if (!yaml_parser_update_buffer(&parser, 1)) {
            printf("\treader error: %s at %d\n", parser.problem, parser.problem_offset);
            failed = 1;
        }
        else if (parser.buffer.pointer[0] != '\0') {
            printf("\texpected NUL, found %X (eof=%d, unread=%d)\n", (int)parser.buffer.pointer[0], parser.eof, parser.unread);
            failed = 1;
        }
    }
    yaml_parser_delete(&parser);
    free(buffer);
    printf("checking a long utf8 sequence: %d fail(s)\n", failed);
    return failed;
}

int check_long_utf16(void)
{
    yaml_parser_t parser;
    int k = 0;
    int j;
    int failed = 0;
    unsigned char ch0, ch1;
    unsigned char *buffer = malloc(2+LONG*2);
    assert(buffer);
    printf("checking a long utf16 sequence...\n");
    buffer[k++] = '\xff';
    buffer[k++] = '\xfe';
    for (j = 0; j < LONG; j ++) {
        if (j % 2) {
            buffer[k++] = '\x10';
            buffer[k++] = '\x04';
        }
        else {
            buffer[k++] = '/';
            buffer[k++] = '\x04';
        }
    }
    yaml_parser_initialize(&parser);
    yaml_parser_set_input_string(&parser, buffer, 2+LONG*2);
    for (k = 0; k < LONG; k++) {
        if (!parser.unread) {
            if (!yaml_parser_update_buffer(&parser, 1)) {
                printf("\treader error: %s at %d\n", parser.problem, parser.problem_offset);
                failed = 1;
                break;
            }
        }
        if (!parser.unread) {
            printf("\tnot enough characters at %d\n", k);
            failed = 1;
            break;
        }
        if (k % 2) {
            ch0 = '\xd0';
            ch1 = '\x90';
        }
        else {
            ch0 = '\xd0';
            ch1 = '\xaf';
        }
        if (parser.buffer.pointer[0] != ch0 || parser.buffer.pointer[1] != ch1) {
            printf("\tincorrect UTF-8 sequence: %X %X instead of %X %X\n",
                    (int)parser.buffer.pointer[0], (int)parser.buffer.pointer[1],
                    (int)ch0, (int)ch1);
            failed = 1;
            break;
        }
        parser.buffer.pointer += 2;
        parser.unread -= 1;
    }
    if (!failed) {
        if (!yaml_parser_update_buffer(&parser, 1)) {
            printf("\treader error: %s at %d\n", parser.problem, parser.problem_offset);
            failed = 1;
        }
        else if (parser.buffer.pointer[0] != '\0') {
            printf("\texpected NUL, found %X (eof=%d, unread=%d)\n", (int)parser.buffer.pointer[0], parser.eof, parser.unread);
            failed = 1;
        }
    }
    yaml_parser_delete(&parser);
    free(buffer);
    printf("checking a long utf16 sequence: %d fail(s)\n", failed);
    return failed;
}

int
main(void)
{
    return check_utf8_sequences() + check_boms() + check_long_utf8() + check_long_utf16();
}

