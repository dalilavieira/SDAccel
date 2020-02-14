#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct TYPE_24__ {char* class_name; } ;
struct TYPE_23__ {TYPE_5__* priv_class; } ;
struct TYPE_22__ {TYPE_5__* priv_class; } ;
struct TYPE_21__ {char* name; int type; int flags; char* help; char* unit; } ;
struct TYPE_20__ {TYPE_5__* priv_class; } ;
typedef  TYPE_1__ AVOutputFormat ;
typedef  TYPE_2__ AVOption ;
typedef  TYPE_3__ AVInputFormat ;
typedef  TYPE_4__ AVCodec ;
typedef  TYPE_5__ AVClass ;

/* Variables and functions */
 int AV_OPT_FLAG_ENCODING_PARAM ; 
#define  FF_OPT_TYPE_BINARY 135 
 scalar_t__ FF_OPT_TYPE_CONST ; 
#define  FF_OPT_TYPE_DOUBLE 134 
#define  FF_OPT_TYPE_FLAGS 133 
#define  FF_OPT_TYPE_FLOAT 132 
#define  FF_OPT_TYPE_INT 131 
#define  FF_OPT_TYPE_INT64 130 
#define  FF_OPT_TYPE_RATIONAL 129 
#define  FF_OPT_TYPE_STRING 128 
 TYPE_4__* av_codec_next (TYPE_4__*) ; 
 TYPE_3__* av_iformat_next (TYPE_3__*) ; 
 TYPE_2__* av_next_option (TYPE_5__ const**,TYPE_2__ const*) ; 
 TYPE_1__* av_oformat_next (TYPE_1__*) ; 
 TYPE_5__* avcodec_get_class () ; 
 TYPE_5__* avformat_get_class () ; 
 int /*<<< orphan*/  exit (int) ; 
 int /*<<< orphan*/  fprintf (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  printf (char*,...) ; 
 int /*<<< orphan*/  stderr ; 
 int /*<<< orphan*/  strcmp (char*,char*) ; 

__attribute__((used)) static void print_usage(void)
{
    fprintf(stderr, "Usage: enum_options type\n"
            "type: format codec\n");
    exit(1);
}

__attribute__((used)) static void print_option(const AVClass *class, const AVOption *o)
{
    printf("@item -%s @var{", o->name);
    switch (o->type) {
    case FF_OPT_TYPE_BINARY:   printf("hexadecimal string"); break;
    case FF_OPT_TYPE_STRING:   printf("string");             break;
    case FF_OPT_TYPE_INT:
    case FF_OPT_TYPE_INT64:    printf("integer");            break;
    case FF_OPT_TYPE_FLOAT:
    case FF_OPT_TYPE_DOUBLE:   printf("float");              break;
    case FF_OPT_TYPE_RATIONAL: printf("rational number");    break;
    case FF_OPT_TYPE_FLAGS:    printf("flags");              break;
    default:                   printf("value");              break;
    }
    printf("} (@emph{");

    if (o->flags & AV_OPT_FLAG_ENCODING_PARAM) {
        printf("input");
        if (o->flags & AV_OPT_FLAG_ENCODING_PARAM)
            printf("/");
    }
    if (o->flags & AV_OPT_FLAG_ENCODING_PARAM)
        printf("output");

    printf("})\n");
    if (o->help)
        printf("%s\n", o->help);

    if (o->unit) {
        const AVOption *u = NULL;
        printf("\nPossible values:\n@table @samp\n");

        while ((u = av_next_option(&class, u)))
            if (u->type == FF_OPT_TYPE_CONST && u->unit && !strcmp(u->unit, o->unit))
                printf("@item %s\n%s\n", u->name, u->help ? u->help : "");
        printf("@end table\n");
    }
}

__attribute__((used)) static void show_opts(const AVClass *class)
{
    const AVOption *o = NULL;

    printf("@table @option\n");
    while ((o = av_next_option(&class, o)))
        if (o->type != FF_OPT_TYPE_CONST)
            print_option(class, o);
    printf("@end table\n");
}

__attribute__((used)) static void show_format_opts(void)
{
    AVInputFormat *iformat = NULL;
    AVOutputFormat *oformat = NULL;

    printf("@section Generic format AVOptions\n");
    show_opts(avformat_get_class());

    printf("@section Format-specific AVOptions\n");
    while ((iformat = av_iformat_next(iformat))) {
        if (!iformat->priv_class)
            continue;
        printf("@subsection %s AVOptions\n", iformat->priv_class->class_name);
        show_opts(iformat->priv_class);
    }
    while ((oformat = av_oformat_next(oformat))) {
        if (!oformat->priv_class)
            continue;
        printf("@subsection %s AVOptions\n", oformat->priv_class->class_name);
        show_opts(oformat->priv_class);
    }
}

__attribute__((used)) static void show_codec_opts(void)
{
    AVCodec *c = NULL;

    printf("@section Generic codec AVOptions\n");
    show_opts(avcodec_get_class());

    printf("@section Codec-specific AVOptions\n");
    while ((c = av_codec_next(c))) {
        if (!c->priv_class)
            continue;
        printf("@subsection %s AVOptions\n", c->priv_class->class_name);
        show_opts(c->priv_class);
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
        print_usage();

    if (!strcmp(argv[1], "format"))
        show_format_opts();
    else if (!strcmp(argv[1], "codec"))
        show_codec_opts();
    else
        print_usage();

    return 0;
}

